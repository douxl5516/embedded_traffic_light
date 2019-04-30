#ifndef FRAME_HANDLER_H
#define FRAME_HANDLER_H

#include "grab-ng.h"
typedef struct frame_handler{
    void* caphandle;
    struct ng_vid_driver * cap_driver;
    struct ng_video_fmt fmt;
} frame_handler;

#endif // FRAME_HANDLER_H
