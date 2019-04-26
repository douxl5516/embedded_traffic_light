#include <QMessageBox>
#include "myqt.h"
#include "led.h"
#include "tty.h"
#include "card_ctrl.h"
void open_camera(){

}
MyDlg::MyDlg()
{
	ui.setupUi(this);
    QObject::connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(open_camera()));
    QObject::connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(switch_light()));
    card_ctrl_main();
    //light();
}


void MyDlg::open_camera(){
    open_camera();
}

void MyDlg::switch_light(){
    
}




