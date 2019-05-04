#include <QMessageBox>
#include <QThread>
#include "myqt.h"
#include "led.h"
#include "tty.h"
#include "card_ctrl.h"
#include "v4l.h"

MyDlg::MyDlg()
{
	ui.setupUi(this);
    isAutoMode=true;
    isCameraOpen=false;
    timer = new QTimer(this);
    timer_v4l=new QTimer(this);

    QObject::connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(open_camera()));
    QObject::connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(switch_mode()));
    QObject::connect(ui.pushButton_3, SIGNAL(clicked()), this, SLOT(switch_light()));
    QObject::connect(ui.pushButton_unlock,SIGNAL(clicked()),this,SLOT(get_priority()));
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(update_led()));
    QObject::connect(timer_v4l, SIGNAL(timeout()), this, SLOT(update_v4l()));

    init_light_status();
    timer->start(1000);
}

MyDlg::~MyDlg(){
    delete timer;
    delete timer_v4l;
}

void MyDlg::get_priority(){
    if(card_ctrl_main()){
        ui.pushButton->setEnabled(true);
        ui.pushButton_2->setEnabled(true);
        ui.label->setText(QString("Welcome"));
    }
}

void MyDlg::init_light_status(){
    status.time=10;
    status.dir=0;
    status.color=0;
    ui.label_dir->setText(QString(status.dir==0?"WE":"NS"));
    ui.label_time->setNum(status.time);
    ui.label_color->setText(QString(status.color==0?"yellow":"green"));
    ui.label_auto->setText(QString(isAutoMode?"yes":"no"));
}

void MyDlg::open_camera(){
    if(isCameraOpen){
        close_video(handler);
        timer_v4l->stop();
    }else{
        handler=init_video();
        timer_v4l->start(50);
    }
}

void MyDlg::switch_mode(){
    if(isAutoMode){
        ui.pushButton_2->setText("to auto mode");
        ui.pushButton_3->setEnabled(true);
        timer->stop();
        led_light(status.dir,0,1);
    }else{
        ui.pushButton_2->setText("to manual mode");
        ui.pushButton_3->setEnabled(false);
        init_light_status();
        timer->start(1000);
    }
    isAutoMode=!isAutoMode;
    ui.label_auto->setText(QString(isAutoMode?"yes":"no"));
}

void MyDlg::switch_light(){
    status.dir=1-status.dir;
    ui.label_dir->setText(QString(status.dir==0?"WE":"NS"));
    led_light(status.dir,0,1);
}

void MyDlg::update_led(){
    ui.label_dir->setText(QString(status.dir==0?"WE":"NS"));
    ui.label_time->setNum(status.time);
    ui.label_color->setText(QString(status.color==0?"yellow":"green"));
    ui.label_auto->setText(QString(isAutoMode?"yes":"no"));
    led_light(status.dir,status.time,status.color);
    if(status.time!=0){
        status.time--;
        return;
    }else if(status.time==0){
        if(status.color==1){
            status.color--;
            status.time=3;
            return;
        }else if(status.color==0){
            status.dir=1-status.dir;
            status.time=10;
            status.color=1;
            return;
        }
    }
}

void MyDlg::update_v4l(){
    nxt_frame(handler);
}

