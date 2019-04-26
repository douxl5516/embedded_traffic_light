#include <QMessageBox>
#include <QThread>
#include "myqt.h"
#include "led.h"
#include "tty.h"
#include "card_ctrl.h"


MyDlg::MyDlg()
{
	ui.setupUi(this);
    timer = new QTimer(this);
    QObject::connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(open_camera()));
    QObject::connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(switch_light()));
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(1000);
    if(card_ctrl_main()){
        ui.pushButton->setEnabled(true);
        ui.pushButton_2->setEnabled(true);
        ui.label->setText(QString("Welcome"));
    }
    led_main();
}
MyDlg::~MyDlg(){
    delete timer;
}


void MyDlg::open_camera(){
    open_camera();
}

void MyDlg::switch_light(){
    
}

void MyDlg::update(){

}


