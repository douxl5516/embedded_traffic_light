#include "tty.h"
#include "stdio.h"
#undef uchar
#define uchar unsigned char

#ifdef __cplusplus
extern "C" {
#endif
    //02 20 52
    int  Card_Request();
    //01 21
    int  Card_Anticoll(uchar *card_NO);
    //01 22
    int  Card_Select();
    //04 23 60 00 00
    int  Card_Auth_EE(uchar addr,uchar block);

    //09 24 60 00 FF FF FF FF FF FF
    int  Card_Load_Key_EE(uchar addr,uchar *key);

    //02 25 01
    int  Card_Read(uchar block,uchar *data);
    //12 26 01  FF EE DD CC BB AA 99 88 77 66 55 44 33 22 11 00
    int  Card_Write(uchar block,uchar *data);
    //01 10
    int Card_Beep(uchar num);
    int card_ctrl_main(void);
#ifdef __cplusplus
}
#endif







