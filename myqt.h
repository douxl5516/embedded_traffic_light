#ifndef __DLG_H__
#define __DLG_H__

#include <QDialog>
#include <QTimer>
#include <ui_traffic_light.h>

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
    bool isAutoMode=true;
    light_status status;
};
#endif
