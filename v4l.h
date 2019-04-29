#ifndef V4L_H
#define V4L_H
#ifdef __cplusplus

struct frame_reader{
    void* caphandle;
};

extern "C" {
#endif
int v4l_main ();
int init_video();
int nxt_frame();
int close_video();
#ifdef __cplusplus
}
#endif
#endif // V4L_H
