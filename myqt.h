#ifndef __DLG_H__
#define __DLG_H__

#include <QDialog>
#include <ui_traffic_light.h>



class MyDlg : public QDialog
{
     Q_OBJECT
public:
    MyDlg();

public slots:
    void open_camera();
    void switch_light();

private:
    Ui::Form ui;

};
#endif
