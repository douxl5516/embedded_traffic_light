/*
 *
 *   (c) 2005-2010 threewater <threewater@up-tech.com>
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/mman.h>

#include "fb.h"
#include <linux/videodev.h>

#include "grab-ng.h"

#define _GNU_SOURCE
#include <getopt.h>


struct capture_info{
	int width, height;
	char device[256];
};

struct fb_dev
{
	//for frame buffer
	int fb;
	void *fb_mem;	//frame buffer mmap
	int fb_width, fb_height, fb_line_len, fb_size;
	int fb_bpp;
	//src must be RGB24 format
	void (*fb_draw)(struct fb_dev *fbdev, void* src, int x, int y, int width, int height);
};

//static char *default_framebuffer="/dev/fb/0";
static char *default_framebuffer="/dev/fb0";

//static struct capture_info capinfo={320, 240, "/dev/v4l/video1"};
//static struct capture_info capinfo={320, 240, "/dev/v4l/video0"};
static struct capture_info capinfo={320, 240, "/dev/video0"};
static struct fb_dev fbdev;
static char* fb_dev_name=NULL;

#define NUM_CAPBUFFER	32

void fb_draw16bpp(struct fb_dev *fbdev, void* src, int x, int y, int width, int height)
{
	int i, j;
	int fb_line_len = fbdev->fb_line_len;
	__u8 *psrc= (__u8*)src;
	__u16* pdsc = (__u16*)fbdev->fb_mem;
	__u16 tmp, tmp1;

	pdsc+=y*fb_line_len/2 + x;

	for(i=0; i<height; i++){
		memcpy(pdsc, psrc, width*2);
		psrc+=width*2;
/*		for(j=0; j<width; j++){
			tmp = (*psrc)>>3;		tmp<<=11;	*psrc++;
			tmp1 = (*psrc)>>2;	tmp|=(tmp1<<5);	*psrc++;
			tmp |= (*psrc)>>3;	*psrc++;
			pdsc[j] = tmp;
		}*/
		pdsc+=fb_line_len/2;
	}
}

void fb_draw12bpp(struct fb_dev *fbdev, void* src, int x, int y, int width, int height)
{
	int i, j;
	int fb_line_len = fbdev->fb_line_len;
	__u8 *psrc= (__u8*)src;
	__u8* pdsc = (__u8*)fbdev->fb_mem;
	__u8 tmp;

	//fixed me! x must be even
	pdsc+=y*fb_line_len + x*3/2;

	for(i=0; i<height; i++){
		for(j=0; j<width*3/2;){
			tmp = psrc[2]&0xf0;
			tmp |=(psrc[1]>>4);
			pdsc[j++] = tmp;

			tmp = psrc[0]&0xf0;
			tmp |=(psrc[5]>>4);
			pdsc[j++] = tmp;

			tmp = psrc[4]&0xf0;
			tmp |=(psrc[3]>>4);
			pdsc[j++] = tmp;

			psrc+=6;
		}
		pdsc+=fb_line_len;
	}
}

int framebuffer_open(void)
{
	int fb;
	struct fb_var_screeninfo fb_vinfo;
	struct fb_fix_screeninfo fb_finfo;
	
	if (!fb_dev_name && !(fb_dev_name = getenv("FRAMEBUFFER")))
		fb_dev_name=default_framebuffer;

	fb = open (fb_dev_name, O_RDWR);
	if(fb<0){
		printf("device %s open failed\n", fb_dev_name);
		return -1;
	}
	
	if (ioctl(fb, FBIOGET_VSCREENINFO, &fb_vinfo)) {
		printf("Can't get VSCREENINFO: %s\n", strerror(errno));
		close(fb);
		return -1;
	}

	if (ioctl(fb, FBIOGET_FSCREENINFO, &fb_finfo)) {
		printf("Can't get FSCREENINFO: %s\n", strerror(errno));
		return 1;
	}

	fbdev.fb_bpp = fb_vinfo.red.length + fb_vinfo.green.length +
		fb_vinfo.blue.length + fb_vinfo.transp.length;

	fbdev.fb_width = fb_vinfo.xres;
	fbdev.fb_height = fb_vinfo.yres;
	fbdev.fb_line_len = fb_finfo.line_length;
	fbdev.fb_size = fb_finfo.smem_len;

	printf("frame buffer: %dx%d,  %dbpp, 0x%xbyte\n", 
		fbdev.fb_width, fbdev.fb_height, fbdev.fb_bpp, fbdev.fb_size);

	switch(fbdev.fb_bpp){
	case 16:
		fbdev.fb_draw = fb_draw16bpp;
		break;
	case 12:
		fbdev.fb_draw = fb_draw12bpp;
		break;
	default:
		printf("Can't support %d bpp draw\n", fbdev.fb_bpp);
		return -1;
	}


	fbdev.fb_mem = mmap (NULL, fbdev.fb_size, PROT_READ|PROT_WRITE,MAP_SHARED,fb,0);
	if(fbdev.fb_mem==NULL || (int)fbdev.fb_mem==-1){
		fbdev.fb_mem=NULL;
		printf("mmap failed\n");
		close(fb);
		return -1;
	}
	

	fbdev.fb=fb;
	memset (fbdev.fb_mem, 0x0, fbdev.fb_size);

	return 0;
}

void framebuffer_close()
{
	if(fbdev.fb_mem){
		munmap(fbdev.fb_mem, fbdev.fb_size);
		fbdev.fb_mem=NULL;
	}

	if(fbdev.fb){
		close(fbdev.fb);
		fbdev.fb=0;
	}
}

int capture(void)
{
	void* caphandle;
	struct ng_vid_driver *cap_driver = &v4l_driver;

	struct ng_video_fmt fmt;

	if(fbdev.fb_bpp==24)
		fmt.fmtid = VIDEO_BGR24;
	else
		fmt.fmtid = VIDEO_RGB16_LE;

	fmt.width = capinfo.width;
	fmt.height = capinfo.height;

	if(framebuffer_open()<0){
		return -1;
	}

	caphandle=cap_driver->open(capinfo.device);

	if(!caphandle){
		printf("failed to open video for linux interface!\n");
		return -1;
	}

	if(cap_driver->setformat(caphandle, &fmt)){
		printf("failed to set video format!\n");
		return -1;
	}

	cap_driver->startvideo(caphandle, 25,  NUM_CAPBUFFER);

	{
		struct ng_video_buf* pvideo_buf;
		int x, y, width, height;
		int diff_width, diff_height;

		diff_width = fbdev.fb_width - fmt.width;
		diff_height = fbdev.fb_height - fmt.height;

		if(diff_width>0){
			x =  diff_width/2;
			width = fmt.width;
		}
		else{
			x = 0;
			width = fbdev.fb_width;
		}

		if(diff_height>0){
			y =  diff_height/2;
			height = fmt.height;
		}
		else{
			y = 0;
			height = fbdev.fb_height;
		}

		//begin capture
		for(;;){
			pvideo_buf=cap_driver->nextframe(caphandle);
			fbdev.fb_draw(&fbdev, pvideo_buf->data, x, y, width, height);
			ng_release_video_buf(pvideo_buf);
		}
	}

	framebuffer_close();
	cap_driver->stopvideo(caphandle);
	cap_driver->close(caphandle);
	return 0;
}

const char*program_name; 
void print_usage (FILE*stream,int exit_code)
{ 
	fprintf (stream, "Usage:%s options [ inputfile ....]\n",program_name); 
	fprintf (stream, "-h --help Display this usage information.\n"
		"-d --device <video device>.\n "
		"-f --framebuffer <frame buffer device>.\n "
		"-v --verbose <n>.\n "
		"-s --size <320:240>\n");
	exit (exit_code); 
} 

static int verbose =0;

int main (int argc,char*argv []) 
{ 
	int next_option; 
	const char*const short_options ="hd:v:f:s:";
	const struct option long_options [] ={
		{"help",0,NULL,'h' }, 
		{"device",1,NULL,'d' }, 
		{"framebuffer",1,NULL,'f' }, 
		{"verbose",1,NULL,'v' }, 
		{"size",0,NULL,'s' }, 
		{NULL,0,NULL,0 }}; 

	const char*output_filename =NULL; 

	program_name =argv [0]; 
	do { 
		next_option =getopt_long (argc,argv,short_options, long_options,NULL); 
		switch (next_option) 
		{ 
		case 'h':/*-h or --help */ 
			print_usage (stdout,0); 
		case 's':/*-s or --size */ 
			//ip =optarg; 
			sscanf(optarg, "%d:%d", &(capinfo.width), &(capinfo.height));
			break; 
		case 'f':/*-f or --framebuffer */ 
			fb_dev_name = optarg;
			break; 
		case 'd':/*-b or --device */ 
			strcpy(capinfo.device, optarg);
			break; 
		case 'v':/*-v or --verbose */ 
			sscanf(optarg, "%d", &verbose);
			ng_debug = verbose;
			break; 
		case '?':/*The user specified an invalid option.*/ 
			print_usage (stderr,1); 
		case -1:/*Done with options.*/ 
			break; 
		default:/*Something else:unexpected.*/ 
			print_usage (stderr,1); 
		}
	}while (next_option !=-1); 
	/*The main program goes here.*/ 

	printf("video %s caputure: %dx%d\n", capinfo.device, capinfo.width, capinfo.height);

	return capture(); 
} 

