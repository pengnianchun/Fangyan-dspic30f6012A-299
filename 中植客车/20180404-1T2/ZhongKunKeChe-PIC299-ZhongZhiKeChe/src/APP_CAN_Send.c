/*
 * File:   APP_CAN.c
 * Author: pnc
 *
 * Created on 2017年7月28日, 下午5:02
 */

#include "APP_System.h"

DATA_BIT gCTL[8]; //仪表输出控制信息

void BCAN_SendCtl(void) {
    CAN_MESSAGE message_POUT;
    DATA_BIT temp;
    temp.byte = 0;
    message_POUT.id = 0x6a4;
    message_POUT.data[0] = gCTL[0].byte;
    message_POUT.data[1] = gCTL[1].byte;
    message_POUT.data[2] = gCTL[2].byte;
    message_POUT.data[3] = gCTL[3].byte;
    message_POUT.data[4] = gCTL[4].byte;
    message_POUT.data[5] = gCTL[5].byte;

    temp.bit1 = ((M_ON && wake_up3) || WAKE_ACC);
    temp.bit2 = IN14; //慢档      
    temp.bit3 = IN15; //间歇
    temp.bit4 = IN16; //快档
    temp.bit5 = IN21; //喷水        
    if (IN14 && IN16)temp.bit2 = 0;
    if (IN21) {
        temp.bit2 = 0; //慢档
        temp.bit3 = 0; //间歇
        temp.bit4 = 0; //快档
    }
    message_POUT.data[6] = temp.byte;

    message_POUT.data[7] = 0;
    message_POUT.len = 8;
    message_POUT.type = 1;
    CAN1_SendMessage(&message_POUT);
}

void BCAN_send_mile(void) {
    CAN_MESSAGE msg;
    msg.data[0] = (unsigned char) (e_total_miles); //低八位
    msg.data[1] = (unsigned char) (e_total_miles >> 8); //二级八位
    msg.data[2] = (unsigned char) (e_total_miles >> 16); //三级八位
    msg.data[3] = (unsigned char) (e_total_miles >> 24); //高八位
    msg.data[4] = 0;
    msg.data[5] = 0;
    msg.data[6] = 0;
    msg.data[7] = 0;
    msg.id = 0x454;
    msg.len = 0x08;
    msg.type = 0x01;
    CAN1_SendMessage(&msg);

}

void PCAN_Send1(void) {
    CAN_MESSAGE message_ICU2VCU01;
    unsigned int temp;
    message_ICU2VCU01.id = 0x18FFD017;

    if(ADV[3] < 500)
        temp = 0;
    else if(ADV[3] > 3000)
        temp = 150;
    else temp = (ADV[3] - 500) * 0.05;   
    message_ICU2VCU01.data[0] = temp;//前气压
    
    if(ADV[4] < 500)
        temp = 0;
    else if(ADV[4] > 3000)
        temp = 150;
    else temp = (ADV[4] - 500) * 0.05;    
    message_ICU2VCU01.data[1] = temp;//后气压    
       
    message_ICU2VCU01.data[2] = 0;        
    message_ICU2VCU01.data[3] = 0; 
    message_ICU2VCU01.data[4] = 0; 
    message_ICU2VCU01.data[5] = 0;    
    message_ICU2VCU01.data[6] = 0;
    message_ICU2VCU01.data[7] = 0;
    message_ICU2VCU01.len = 8;
    message_ICU2VCU01.type = 0;
    CAN2_SendMessage(&message_ICU2VCU01);
}

void PCAN_Send2(void) {
    CAN_MESSAGE message_ICU2VCU02;
    unsigned long temp;
    DATA_BIT CAN_DATA;
    message_ICU2VCU02.id = 0x0CDFD017;

    CAN_DATA.bit1 = WAKE_Danger; 
    CAN_DATA.bit2 = (LED9 || LED11); 
    CAN_DATA.bit3 = LED1;  
    CAN_DATA.bit4 = LED2;  
    CAN_DATA.bit5 = fKL12;  
    CAN_DATA.bit6 = 0;
    CAN_DATA.bit7 = 0; 
    CAN_DATA.bit8 = 0;
    temp = CAN_DATA.byte;
    message_ICU2VCU02.data[0] = temp;
    message_ICU2VCU02.data[1] = (unsigned char) (e_total_miles); //低八位
    message_ICU2VCU02.data[2] = (unsigned char) (e_total_miles >> 8); //二级八位
    message_ICU2VCU02.data[3] = (unsigned char) (e_total_miles >> 16); //三级八位
    message_ICU2VCU02.data[4] = (unsigned char) (e_total_miles >> 24); //高八位
    message_ICU2VCU02.data[5] = (unsigned char) (e_single_miles);
    message_ICU2VCU02.data[6] = (unsigned char) (e_single_miles >> 8);
    message_ICU2VCU02.data[7] = 0;
    message_ICU2VCU02.len = 8;
    message_ICU2VCU02.type = 0;
    CAN2_SendMessage(&message_ICU2VCU02);
}

void PCAN_0x18FEF117(void) {
    CAN_MESSAGE message_ICU2VCU01;
    unsigned int temp;
    DATA_BIT CAN_DATA;
    message_ICU2VCU01.id = 0x18FEF117;
    
    CAN_DATA.bit1 = LED18; 
    CAN_DATA.bit2 = 0; 
    CAN_DATA.bit3 = LED24;  
    CAN_DATA.bit4 = 0;  
    CAN_DATA.bit5 = checkout;  
    CAN_DATA.bit6 = 0;
    CAN_DATA.bit7 = WAKE_Danger; 
    CAN_DATA.bit8 = 0;
    temp = CAN_DATA.byte;
    message_ICU2VCU01.data[0] = temp;
    
    temp = SPEED * 10;
    message_ICU2VCU01.data[1] = (unsigned char) (temp);
    message_ICU2VCU01.data[2] = (unsigned char) (temp >> 8);
    
    CAN_DATA.bit1 = LED1; 
    CAN_DATA.bit2 = 0; 
    CAN_DATA.bit3 = LED2;  
    CAN_DATA.bit4 = 0;  
    CAN_DATA.bit5 = mKH1;  
    CAN_DATA.bit6 = 0;
    CAN_DATA.bit7 = 0; 
    CAN_DATA.bit8 = 0;
    temp = CAN_DATA.byte;
    message_ICU2VCU01.data[3] = temp;

    /*if (ADR[1] < 10)
        temp = 0;
    else if (ADR[1] < 52)
        temp = (ADR[1] - 10)*0.47;
    else if (ADR[1] < 88)
        temp = 20 + (ADR[1] - 52)*0.55;
    else if (ADR[1] < 124)
        temp = 40 + (ADR[1] - 88)*0.55;
    else if (ADR[1] < 155)
        temp = 60 + (ADR[1] - 124)*0.64;
    else if (ADR[1] < 180)
        temp = 80 + (ADR[1] - 155)*0.8;
    else
        temp = 100;*/
    if(ADV[3] < 500)
        temp = 0;
    else if(ADV[3] > 4500)
        temp = 120;
    else 
        temp = (ADV[3] - 500) * 0.03; 
    message_ICU2VCU01.data[4] = temp; //前气压

    /*if (ADR[2] < 10)
        temp = 0;
    else if (ADR[2] < 52)
        temp = (ADR[2] - 10)*0.47;
    else if (ADR[2] < 88)
        temp = 20 + (ADR[2] - 52)*0.55;
    else if (ADR[2] < 124)
        temp = 40 + (ADR[2] - 88)*0.55;
    else if (ADR[2] < 155)
        temp = 60 + (ADR[2] - 124)*0.64;
    else if (ADR[2] < 180)
        temp = 80 + (ADR[2] - 155)*0.8;
    else
        temp = 100;*/
    if(ADV[4] < 500)
        temp = 0;
    else if(ADV[4] > 4500)
        temp = 120;
    else 
        temp = (ADV[4] - 500) * 0.03; 
    message_ICU2VCU01.data[5] = temp; //后气压   

    message_ICU2VCU01.data[6] = 0;
    message_ICU2VCU01.data[7] = 0;

    message_ICU2VCU01.len = 8;
    message_ICU2VCU01.type = 0;
    CAN2_SendMessage(&message_ICU2VCU01);
}

void PCAN_0x18FEF217(void) {
    CAN_MESSAGE message_ICU2VCU02;
    unsigned long temp;
    message_ICU2VCU02.id = 0x18FEF217;
    temp = e_total_miles ;
    message_ICU2VCU02.data[0] = (unsigned char) (temp); //低八位
    message_ICU2VCU02.data[1] = (unsigned char) (temp >> 8); //二级八位
    message_ICU2VCU02.data[2] = (unsigned char) (temp >> 16); //三级八位
    message_ICU2VCU02.data[3] = (unsigned char) (temp >> 24);
    temp = e_single_miles ;
    message_ICU2VCU02.data[4] = temp;
    message_ICU2VCU02.data[5] = temp >> 8;
    message_ICU2VCU02.data[6] = 0;
    message_ICU2VCU02.data[7] = 0;
    message_ICU2VCU02.len = 8;
    message_ICU2VCU02.type = 0;
    CAN2_SendMessage(&message_ICU2VCU02);
}

//CAN任务调度函数添加
TASK_COMPONENTS TaskComps[] = {
    //{0, 10, 10, BCAN_send_mile},
    //{0, 10, 10, BCAN_SendCtl},
    //{0, 5, 5, PCAN_Send1},
    //{0, 5, 5, PCAN_Send2},   
    {0, 10, 10, PCAN_0x18FEF117},
    {0, 100, 100, PCAN_0x18FEF217},
    {0, 0, 0, NULL}
};