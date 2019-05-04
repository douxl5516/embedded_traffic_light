#include <pthread.h>
#include "card_ctrl.h"

//02 20 52
int  Card_Request(){
	uchar txbuff[11];	
	uchar rxbuff[11];	
	int i = 0;
	uchar len = 0;
	txbuff[0]=0x02;
	txbuff[1]=0x20;
	txbuff[2]=0x52;
        tty_fflush();
	tty_write(txbuff,3);
	usleep(100);
	//read
        tty_read(&len,1);
        tty_read(rxbuff,len);
        fflush(stdout);
        if(len > 1){
                return 1;
        }else{  
                return -1;
        }
}
//01 21
int  Card_Anticoll(uchar *card_NO){
	uchar txbuff[11];	
	uchar rxbuff[11];	
	int i = 0;
	uchar len = 0;
	txbuff[0]=0x01;
	txbuff[1]=0x21;
        tty_fflush();
	tty_write(txbuff,2);
	usleep(100);
	//read
        tty_read(&len,1);
        tty_read(rxbuff,len);
        fflush(stdout);
        if(len > 1){
		memcpy(card_NO,&rxbuff[1],4);
                return 1;
        }else{  
                return -1;
        }
}
//01 22
int  Card_Select(){
        uchar txbuff[11];
        uchar rxbuff[11];
        int i = 0;
        uchar len = 0;
        txbuff[0]=0x01;
        txbuff[1]=0x22;
        tty_fflush();
        tty_write(txbuff,2);
	usleep(100);
        //read
        tty_read(&len,1);
        tty_read(rxbuff,len);
        fflush(stdout);
        if(len > 1){
                return 1;
        }else{ 
                return -1;
        }
}

//04 23 60 00 00
int  Card_Auth_EE(uchar addr,uchar block){
        uchar txbuff[11];
        uchar rxbuff[11];
        int i = 0;
        uchar len = 0;
        txbuff[0]=0x04;
        txbuff[1]=0x23;
        txbuff[2]=0x60;
        txbuff[3]=addr;
        txbuff[4]=block;
        tty_fflush();
        tty_write(txbuff,5);
	usleep(100);
        //read
        tty_read(&len,1);
        tty_read(rxbuff,len);
        fflush(stdout);
        if(rxbuff[1] == 0x00){
                return 1;
        }else{ 
                return -1;
        }
}

//09 24 60 00 FF FF FF FF FF FF 
int  Card_Load_Key_EE(uchar addr,uchar *key){
        uchar txbuff[11];
        uchar rxbuff[11];
        int i = 0;
        uchar len = 0;
        txbuff[0]=0x09;
        txbuff[1]=0x24;
        txbuff[2]=0x60;
        txbuff[3]=addr;
	memcpy(&txbuff[4],key,6);
        tty_fflush();
        tty_write(txbuff,10);
	usleep(100);
        //read
        tty_read(&len,1);
        tty_read(rxbuff,len);
        fflush(stdout);
        if(rxbuff[0] == 0x00){
                return 1;
        }else{ 
                return -1;
        }       
}

//02 25 01
int  Card_Read(uchar block,uchar *data){
        uchar txbuff[11];
        uchar rxbuff[24];
        int i = 0;
        uchar len = 0;
        txbuff[0]=0x02;
        txbuff[1]=0x25;
        txbuff[2]=block;
        tty_fflush();
        tty_write(txbuff,3);
	usleep(100);
        //read
        tty_read(&len,1);
        tty_read(rxbuff,len);
	//for(i = 0;i < len;i ++)
	//	printf("rxbuff[%d] = 0x%x\n",i,rxbuff[i]);
        fflush(stdout);
        if(len > 1){
		memcpy(data,&rxbuff[1],16);
                return 1;
        }else{ 
                return -1;
        }
}
//12 26 01  FF EE DD CC BB AA 99 88 77 66 55 44 33 22 11 00
int  Card_Write(uchar block,uchar *data){
        uchar txbuff[24];
        uchar rxbuff[11];
        int i = 0;
        uchar len = 0;
        txbuff[0]=0x12;
        txbuff[1]=0x26;
        txbuff[2]=block;
        memcpy(&txbuff[3],data,16);
	
	//for(i = 0;i < 19;i ++)
	//	printf("txbuff[%d] = 0x%x\n",i,txbuff[i]);
        tty_fflush();
        tty_write(txbuff,19);
	usleep(100);
        //read
        tty_read(&len,1);
	//printf("len = %d\n",len);
        tty_read(rxbuff,len);
        fflush(stdout);
        if(rxbuff[0] == 0x00){
		//printf("write data OK\n");
                return 1;
        }else{ 
		//printf("write data faild\n");
                return -1;
        }
}
//01 10
int Card_Beep(uchar delay){
	uchar txbuff[11];
        uchar rxbuff[11];
        int i = 0;
        uchar len = 0;
        txbuff[0]=0x02;
        txbuff[1]=0x10;
        txbuff[2]=delay;
        tty_fflush();
        tty_write(txbuff,3);
        usleep(100);
}


int card_ctrl_main(void){
	uchar card_NO[4] = {0x00,0x00,0x00,0x00};
	tty_init();
    Card_Beep(1);
	while(1){
        while(1){
            sleep(1);
            if((Card_Request() > 0))
                break;
        }
	 	if(Card_Anticoll(card_NO) < 0)
			continue;
        return 1;
	}	
}
