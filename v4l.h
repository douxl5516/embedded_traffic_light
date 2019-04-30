#ifndef V4L_H
#define V4L_H
#ifdef __cplusplus
extern "C" {
#endif

#include "grab-ng.h"
struct frame_handler{
    void* caphandle;
	struct ng_vid_driver * capdriver;
};


	
int v4l_main ();
struct frame_handler init_video();
int nxt_frame(struct frame_handler handler);
int close_video(struct frame_handler handler);
#ifdef __cplusplus
}
#endif
#endif // V4L_H
