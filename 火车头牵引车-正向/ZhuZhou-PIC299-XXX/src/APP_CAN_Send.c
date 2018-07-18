/*
 * File:   APP_CAN.c
 * Author: pnc
 *
 * Created on 2017年7月28日, 下午5:02
 */

#include "APP_System.h"

DATA_BIT gCTL[8]; //仪表输出控制信息

//CAN任务调度函数添加
TASK_COMPONENTS TaskComps[] = {
    {0, 10, 10, BCAN_send_mile},
    {0, 10, 10, BCAN_SendCtl},
    //{0, 10, 10, PCAN_Send1},
    //{0, 10, 10, PCAN_Send2}, 
    //{0, 100, 100, PCAN_Send_TCO1},
    //{0, 100, 100, PCAN_Send_TCO2}, 
    {0, 5, 5, BCAN_IC_VehSpdAndMilSts}, 
    {0, 0, 0, NULL}
};

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
        temp = 125;
    else temp = (ADV[3] - 500) * 0.05;   
    message_ICU2VCU01.data[0] = temp;//前气压
    
    if(ADV[4] < 500)
        temp = 0;
    else if(ADV[4] > 3000)
        temp = 125;
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

//博世杰行车记录仪
void PCAN_Send_TCO1(void) {
    CAN_MESSAGE msg;
    msg.data[0] = 0;
    msg.data[1] = 0;
    msg.data[2] = 0;
    msg.data[3] = 0;
    msg.data[4] = 0;
    msg.data[5] = 0;
    msg.data[6] = 0;
    msg.data[7] = (unsigned char) SPEED;
    msg.id = 0x0CFE6C21;
    msg.len = 0x08;
    msg.type = 0x00;
    CAN2_SendMessage(&msg);
}

void PCAN_Send_TCO2(void) {
    CAN_MESSAGE msg;
    DATA_BIT CAN_DATA;

    CAN_DATA.bit1 = LED22;             //近光灯
    CAN_DATA.bit2 = 0;
    CAN_DATA.bit3 = (LED19 || LED20);  //雾灯
    CAN_DATA.bit4 = 0;
    CAN_DATA.bit5 = 0;   //倒车灯
    CAN_DATA.bit6 = 0;
    CAN_DATA.bit7 = 0;                 //喇叭
    CAN_DATA.bit8 = 0;
    msg.data[0] = CAN_DATA.byte;

    CAN_DATA.bit1 = 0; /*((DMC_Level == 0 && DMC_Status == 3) || //电机严重故障
            (((DMY_Status >> 4) & 0x03) == 2) ||            //油泵故障
            (((DMQ_Status >> 4) & 0x03) == 2) ||            //气泵故障
            (DCDC_Code > 0 && DCDC_Code < 51) ||            //DCDC严重故障
            LED14);                                         //电池系统故障
    */
    CAN_DATA.bit2 = 0;
    CAN_DATA.bit3 = LED8;               //右转向灯
    CAN_DATA.bit4 = 0;
    CAN_DATA.bit5 = LED4;               //左转向
    CAN_DATA.bit6 = 0;
    CAN_DATA.bit7 = (LED1 || LED2);       //车门开
    CAN_DATA.bit8 = 0;
    msg.data[1] = CAN_DATA.byte;

    CAN_DATA.bit1 = 0;                  //门强制选择开关
    CAN_DATA.bit2 = 0;
    CAN_DATA.bit3 = 0;
    CAN_DATA.bit4 = 0;
    CAN_DATA.bit5 = (LED9 || LED11);     //低气压报警
    CAN_DATA.bit6 = 0;
    CAN_DATA.bit7 = LED17;              //远光灯
    CAN_DATA.bit8 = 0;
    msg.data[2] = CAN_DATA.byte;

    CAN_DATA.bit1 = 0; //水温高报警
    CAN_DATA.bit2 = 0;
    CAN_DATA.bit3 = fKL10; //水位低报警
    CAN_DATA.bit4 = 0;
    CAN_DATA.bit5 = 0; //空滤报警
    CAN_DATA.bit6 = 0;
    CAN_DATA.bit7 = 0; //油压报警
    CAN_DATA.bit8 = 0;
    msg.data[3] = CAN_DATA.byte;

    CAN_DATA.bit1 = LED9;  //前气压报警
    CAN_DATA.bit2 = 0;    
    CAN_DATA.bit3 = LED11; //后气压报警
    CAN_DATA.bit4 = 0;
    CAN_DATA.bit5 = 0;
    CAN_DATA.bit6 = 0;
    CAN_DATA.bit7 = 0;
    CAN_DATA.bit8 = 0;
    msg.data[4] = CAN_DATA.byte;

    CAN_DATA.bit1 = LED24; //刹车工作
    CAN_DATA.bit2 = 0;
    CAN_DATA.bit3 = 0;    //缓速器工作
    CAN_DATA.bit4 = 0;
    CAN_DATA.bit5 = LED2;  //门2开
    CAN_DATA.bit6 = 0;
    CAN_DATA.bit7 = LED1;  //门1开
    CAN_DATA.bit8 = 0;
    msg.data[5] = CAN_DATA.byte;

    CAN_DATA.bit1 = 0; //左门3
    CAN_DATA.bit2 = 0;
    CAN_DATA.bit3 = 0; //左门2
    CAN_DATA.bit4 = 0;
    CAN_DATA.bit5 = 0; //左门1
    CAN_DATA.bit6 = 0;
    CAN_DATA.bit7 = 0; //左右门选择 00左门 01右门
    CAN_DATA.bit8 = 0;
    msg.data[6] = CAN_DATA.byte;

    CAN_DATA.bit1 = 0; //右门3
    CAN_DATA.bit2 = 0;
    CAN_DATA.bit3 = 0; //右门2
    CAN_DATA.bit4 = 0;
    CAN_DATA.bit5 = 0; //右门1
    CAN_DATA.bit6 = 0;
    CAN_DATA.bit7 = 0; //车型选择 00普通公交车 01BRT车
    CAN_DATA.bit8 = 0;
    msg.data[7] = CAN_DATA.byte;
    msg.id = 0x18FED925;
    msg.len = 0x08;
    msg.type = 0x00;
    CAN2_SendMessage(&msg);
}

void BCAN_IC_VehSpdAndMilSts(void) {
    CAN_MESSAGE msg;
    DATA_BIT CAN_DATA;
    unsigned long temp;
    static unsigned char life = 0;
    msg.data[0] = ((unsigned char) CAN_0x141.VCU_VehSpdV << 7) + ((CAN_0x141.VCU_VehSpd >> 8) & 0x7F);
    msg.data[1] = (unsigned char) CAN_0x141.VCU_VehSpd;  
    
    CAN_DATA.bit1 = 0;
    CAN_DATA.bit2 = 0;
    CAN_DATA.bit3 = 0;
    CAN_DATA.bit4 = 0;
    CAN_DATA.bit5 = LED18;
    CAN_DATA.bit6 = IN30;
    CAN_DATA.bit7 = 0;
    CAN_DATA.bit8 = 0;
    temp = e_total_miles / 10;
    msg.data[2] = (unsigned char) ((temp >> 16) & 0x0F) + CAN_DATA.byte; //三级八位
    msg.data[3] = (unsigned char) (temp >> 8); //二级八位
    msg.data[4] = (unsigned char) (temp); //低八位
    msg.data[5] = 0;
    msg.data[6] = ((life++)&0x0F);
    msg.data[7] = 0;
    
    msg.id = 0x2A0;
    msg.len = 0x08;
    msg.type = 0x01;
    CAN2_SendMessage(&msg);

}