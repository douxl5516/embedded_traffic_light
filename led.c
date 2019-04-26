#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
///#include <linux/delay.h>

#define TUBE_IOCTROL  0x11
#define DOT_IOCTROL   0x12

void jmdelay(int n) {
    int i,j,k;
    for (i=0;i<n;i++)
        for (j=0;j<100;j++)
            for (k=0;k<100;k++);
}

void led_main() {
    int fd;
    int i,j,k;
    unsigned int LEDWORD;
    unsigned int MLEDA[8];
    unsigned char LEDCODE[10]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};


    unsigned char dongxi[8] = {0xc0, 0xc0, 0xc0, 0xc0, 0x03, 0x03, 0x03, 0x03};
    unsigned char nanbei[8] = {0xf0, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x0f};


    unsigned char dongxihuang[8] = {0x00, 0xc0, 0xc0, 0x00, 0x00, 0x03, 0x03, 0x00};
    unsigned char nanbeihuang[8] = {0x60, 0x60, 0x00, 0x00, 0x00, 0x00, 0x06, 0x06};

    fd=open("/dev/s3c2440_led0",O_RDWR);
    if (fd < 0) {
        printf("####Led device open fail####\n");
        return;
    }

    LEDWORD=0xff00;

//    asm
//    (
//     "MOV R5,#0X011 \n\t"
//     "STRB R5,[R4] \n\t"
//     );


    printf("will enter TUBE LED  ,please waiting .............. \n");
    LEDWORD=0xff00;
    ioctl(fd,0x12,LEDWORD);
    sleep(1);


    int dir = 1;

    while (1) {
    if (dir == 1) {
      write(fd, dongxi, 10);
    } else {
      write(fd, nanbei, 10);
    }

    int time1;

    for (time1 = 10; time1 >= 0; time1--) {
      int low = time1 % 10;
      int high = time1 / 10;
      LEDWORD = LEDCODE[high] << 8 & 0xff00 | LEDCODE[low];
      ioctl(fd,0x12,LEDWORD);
      sleep(1);
    }

    if (dir == 1) {
      write(fd, dongxihuang, 3);
    } else {
      write(fd, nanbeihuang, 3);
    }
    int time2;

    for(time2=3;time2>=0;time2--){
      int low = time2 % 10;
      int high = time2 / 10;
      LEDWORD = LEDCODE[high] << 8 & 0xff00 | LEDCODE[low];
      ioctl(fd,0x12,LEDWORD);
      sleep(1);
    }

    dir = 1 - dir;
    }

    close(fd);
}

