#ifndef __DLG_H__
#define __DLG_H__

#include <QDialog>
#include <QTimer>
#include <ui_traffic_light.h>
#include "frame_handler.h"

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
