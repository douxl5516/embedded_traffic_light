#ifndef __DLG_H__
#define __DLG_H__

#include <QDialog>
#include <QTimer>
#include <ui_traffic_light.h>
#include "frame_handler.h"

/*
  direction：方向，0为东西方向，1为南北方向
  time：计时器的数字
  color：1为绿灯，0为黄灯
*/
struct light_status{
    int time;
    int dir;
    int color;
};


class MyDlg : public QDialog
{
     Q_OBJECT
public:
    MyDlg();
    ~MyDlg();

public slots:
    void open_camera();
    void init_light_status();
    void switch_mode();
    void switch_light();
    void update_led();
    void update_v4l();
    void get_priority();

private:
    Ui::Form ui;
    QTimer *timer;
    QTimer *timer_v4l;
    bool isAutoMode;
    bool isCameraOpen;
    light_status status;
    struct frame_handler handler;
};
#endif
