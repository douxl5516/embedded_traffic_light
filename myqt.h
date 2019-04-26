#ifndef __DLG_H__
#define __DLG_H__

#include <QDialog>
#include <QTimer>
#include <ui_traffic_light.h>



class MyDlg : public QDialog
{
     Q_OBJECT
public:
    MyDlg();
    ~MyDlg();

public slots:
    void open_camera();
    void switch_light();
    void update();

private:
    Ui::Form ui;
    QTimer *timer;

};
#endif
