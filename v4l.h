#ifndef V4L_H
#define V4L_H
#include "frame_handler.h"
#ifdef __cplusplus
extern "C" {
#endif

    int v4l_main ();
    frame_handler init_video();
    int nxt_frame(frame_handler handler);
    int close_video(frame_handler handler);
#ifdef __cplusplus
}
#endif
#endif
