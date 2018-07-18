/*
 * File:   APP_CAN.c
 * Author: pnc
 *
 * Created on 2017年7月28日, 下午5:02
 */

#include "APP_System.h"

DATA_BIT gCTL[8]; //仪表输出控制信息
unsigned char ccvs_eng_req; //启动请求
unsigned char pct_cut[15] = {120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120}; //保护电流单位：100mA
unsigned char pct_time = 10;//保护时间单位：100mA

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

    message_POUT.data[7] = pct_time;
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
/*
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
*/
void BCAN_send_pct1(void) {
    CAN_MESSAGE msg;
    msg.data[0] = pct_cut[0]; 
    msg.data[1] = pct_cut[1];
    msg.data[2] = pct_cut[2]; 
    msg.data[3] = pct_cut[3]; 
    msg.data[4] = pct_cut[4];
    msg.data[5] = pct_cut[5];
    msg.data[6] = pct_cut[6];
    msg.data[7] = pct_cut[7];
    msg.id = 0x6a5;
    msg.len = 0x08;
    msg.type = 0x01;
    CAN1_SendMessage(&msg);

}

void BCAN_send_pct2(void) {
    CAN_MESSAGE msg;
    msg.data[0] = pct_cut[8]; 
    msg.data[1] = pct_cut[9];
    msg.data[2] = pct_cut[10]; 
    msg.data[3] = pct_cut[11]; 
    msg.data[4] = pct_cut[12];
    msg.data[5] = pct_cut[13];
    msg.data[6] = pct_cut[14];
    msg.data[7] = pct_time;
    msg.id = 0x6a6;
    msg.len = 0x08;
    msg.type = 0x01;
    CAN1_SendMessage(&msg);

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
    //CAN_DATA.bit5 = (VCU_Gear == 1);   //倒车灯
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
///////////////////////////////////////
void PCAN_0x0C18A7A1(void) {
    CAN_MESSAGE msg;
    unsigned long temp;
    unsigned char mile1,mile2;
    msg.id = 0x0C18A7A1;   
           
    temp = e_total_miles / 10;
    mile1 = temp/100000;
    temp = temp%100000;
    mile2 = temp/10000;
    msg.data[0] = (mile1 & 0x0F)+((mile2 & 0x0F) << 4);
    
    temp = temp%10000;
    mile1 = temp/1000;
    temp = temp%1000;
    mile2 = temp/100;
    msg.data[1] = (mile1 & 0x0F)+((mile2 & 0x0F) << 4);
    
    temp = temp%100;
    mile1 = temp/10;
    mile2 = temp%10;
    msg.data[2] = (mile1 & 0x0F)+((mile2 & 0x0F) << 4);   
    msg.data[3] = 0; 
    msg.data[4] = 0; 
    msg.data[5] = 0;    
    msg.data[6] = 0;
    msg.data[7] = 0;
    msg.len = 8;
    msg.type = 0;
    if (IN2 || IN3 || WAKE_Danger || WAKE_Charge){
        CAN2_SendMessage(&msg);
    }
}

void PCAN_0x0C19A7A1(void) {
    CAN_MESSAGE msg;
    unsigned int temp;
    DATA_BIT CAN_DATA;
    msg.id = 0x0C19A7A1;

    CAN_DATA.bit1 = 0; 
    CAN_DATA.bit2 = 0; 
    CAN_DATA.bit3 = 0; 
    CAN_DATA.bit4 = LED1;  //前门开信号
    CAN_DATA.bit5 = LED2;  //后门开信号
    CAN_DATA.bit6 = 0;
    CAN_DATA.bit7 = 0; 
    CAN_DATA.bit8 = 0;
    msg.data[0] = CAN_DATA.byte;
    
    CAN_DATA.bit1 = LED20; 
    CAN_DATA.bit2 = LED22; 
    CAN_DATA.bit3 = 0; 
    CAN_DATA.bit4 = 0;  //
    CAN_DATA.bit5 = IN5;  //
    CAN_DATA.bit6 = LED19;
    CAN_DATA.bit7 = LED17; 
    CAN_DATA.bit8 = IN1;
    msg.data[1] = CAN_DATA.byte;
    
    msg.data[2] = 0;   
    msg.data[3] = SPEED * 2; 
    
    if (rADR[0] < 10)
        temp = 0;
    else if (rADR[0] < 79)
        temp = (rADR[0] - 10)*43.5;
    else if (rADR[0] < 116)
        temp = 3000 + (rADR[0] - 79)*81;
    else if (rADR[0] < 149)
        temp = 6000 + (rADR[0] - 116)*60.6;
    else if (rADR[0] < 184)
        temp = 8000 + (rADR[0] - 149)*57.1;
    else
        temp = 10000;
    msg.data[4] = temp;
    msg.data[5] = temp >> 8; 
    
    if (rADR[1] < 10)
        temp = 0;
    else if (rADR[1] < 79)
        temp = (rADR[1] - 10)*43.5;
    else if (rADR[1] < 116)
        temp = 3000 + (rADR[1] - 79)*81;
    else if (rADR[1] < 149)
        temp = 6000 + (rADR[1] - 116)*60.6;
    else if (rADR[1] < 184)
        temp = 8000 + (rADR[1] - 149)*57.1;
    else
        temp = 10000;
    msg.data[6] = temp;
    msg.data[7] = temp >> 8;
    msg.len = 8;
    msg.type = 0;
    if (IN2 || IN3 || WAKE_Danger || WAKE_Charge){
        CAN2_SendMessage(&msg);
    }
}
//绿控发送报文
/*
void PCAN_CCVS(void) {
    CAN_MESSAGE message_CCVS;
    DATA_BIT CAN_DATA;
    unsigned int temp;
    message_CCVS.id = 0x18FEF117;
    
    CAN_DATA.bit1 = 1; 
    CAN_DATA.bit2 = 1; 
    CAN_DATA.bit3 = LED18;  //手刹
    CAN_DATA.bit4 = 0;  
    CAN_DATA.bit5 = 1;      //空调压缩机工作状态 00 = 工作  01 = 不工作  11 = 无效
    CAN_DATA.bit6 = 1;
    CAN_DATA.bit7 = 1; 
    CAN_DATA.bit8 = 1;
    message_CCVS.data[0] = CAN_DATA.byte;
    message_CCVS.data[1] = 0;
    message_CCVS.data[2] = (unsigned char) SPEED;//(unsigned char) (SPEED * 100 / e_hm_pulse); //车速发实际车速
    
    CAN_DATA.bit1 = 1;      //发动机禁止启动 00=不禁止（允许） 01=禁止（不允许）11=无效（表示没有该信号输出）
    CAN_DATA.bit2 = 1; 
    CAN_DATA.bit3 = rKL10;  //发动机仓门开关
    CAN_DATA.bit4 = 0;  
    CAN_DATA.bit5 = LED24;  //脚刹
    CAN_DATA.bit6 = 0;
    CAN_DATA.bit7 = 1;      
    CAN_DATA.bit8 = 1;
    message_CCVS.data[3] = CAN_DATA.byte;
    
    CAN_DATA.bit1 = 0;      //00=要求限速为默认值（70）01=要求限速为100km/h 11=无效
    CAN_DATA.bit2 = 0; 
    CAN_DATA.bit3 = 1;      //充电口端盖信号 00= off （关）01= on （开）11=无效（表示没有该信号输出）
    CAN_DATA.bit4 = 1;  
    CAN_DATA.bit5 = fKL15;  //前门开关
    CAN_DATA.bit6 = 0;
    CAN_DATA.bit7 = fKH1;   //后门开关
    CAN_DATA.bit8 = 0;
    message_CCVS.data[4] = CAN_DATA.byte;
    
    if(ADV[2] < 500)
        temp = 0;
    else if(ADV[2] > 3000)
        temp = 100;
    else 
        temp = (ADV[2] - 500) * 0.04;
    message_CCVS.data[5] = (unsigned char) temp;
    
    if(ADV[3] < 500)
        temp = 0;
    else if(ADV[3] > 3000)
        temp = 100;
    else 
        temp = (ADV[3] - 500) * 0.04;
    message_CCVS.data[6] = (unsigned char) temp;
    message_CCVS.data[7] = 0xff;
    message_CCVS.len = 8;
    message_CCVS.type = 0;
    CAN2_SendMessage(&message_CCVS);
}

void PCAN_18EBFFD7(void) {
    CAN_MESSAGE msg;
    msg.data[0] = (unsigned char) (e_total_miles); //低八位
    msg.data[1] = (unsigned char) (e_total_miles >> 8); //二级八位
    msg.data[2] = (unsigned char) (e_total_miles >> 16); //三级八位
    msg.data[3] = (unsigned char) (e_total_miles >> 24); //高八位
    msg.data[4] = (unsigned char) (e_single_miles); //车速信号
    msg.data[5] = (unsigned char) (e_single_miles >> 8);
    msg.data[6] = 0;
    msg.data[7] = 0;
    msg.id = 0x18EBFFD7;
    msg.len = 0x08;
    msg.type = 0x00;
    CAN2_SendMessage(&msg);

}

void PCAN_18FED925(void) {
    CAN_MESSAGE msg;
    DATA_BIT CAN_DATA;
    
    CAN_DATA.bit1 = LED22;  //近光灯
    CAN_DATA.bit2 = 0; 
    CAN_DATA.bit3 = LED19;  //前雾灯
    CAN_DATA.bit4 = 0;  
    CAN_DATA.bit5 = LED21;  //倒车灯
    CAN_DATA.bit6 = 0;
    CAN_DATA.bit7 = 1;      //喇叭
    CAN_DATA.bit8 = 1;
    msg.data[0] = CAN_DATA.byte;
    
    CAN_DATA.bit1 = 1;      //严重故障  
    CAN_DATA.bit2 = 1; 
    CAN_DATA.bit3 = LED8;   //右转向灯
    CAN_DATA.bit4 = 0;  
    CAN_DATA.bit5 = LED4;   //左转向灯
    CAN_DATA.bit6 = 0;
    CAN_DATA.bit7 = (fKL15 || fKH1);      //门开
    CAN_DATA.bit8 = 0;
    msg.data[1] = CAN_DATA.byte;
    
    CAN_DATA.bit1 = 1;    
    CAN_DATA.bit2 = 1; 
    CAN_DATA.bit3 = 1; 
    CAN_DATA.bit4 = 1;  
    CAN_DATA.bit5 = (fPOUT.BITS.O1 || fPOUT.BITS.O2);  //雨刮
    CAN_DATA.bit6 = 0;
    CAN_DATA.bit7 = LED17;    //远光灯
    CAN_DATA.bit8 = 0;
    msg.data[2] = CAN_DATA.byte;
    
    msg.data[3] = 0xFF;
    
    CAN_DATA.bit1 = LED9;    //气压1
    CAN_DATA.bit2 = 0; 
    CAN_DATA.bit3 = LED11;   //气压2
    CAN_DATA.bit4 = 0;  
    CAN_DATA.bit5 = 1;  
    CAN_DATA.bit6 = 1;
    CAN_DATA.bit7 = 1;   
    CAN_DATA.bit8 = 1;
    msg.data[4] = CAN_DATA.byte;
    
    CAN_DATA.bit1 = LED24;   //刹车灯
    CAN_DATA.bit2 = 0; 
    CAN_DATA.bit3 = 1;       //缓速器
    CAN_DATA.bit4 = 1;  
    CAN_DATA.bit5 = fKL15;   //前门状态
    CAN_DATA.bit6 = 0;
    CAN_DATA.bit7 = fKH1;    //后门状态
    CAN_DATA.bit8 = 0;
    msg.data[5] = CAN_DATA.byte;
    msg.data[6]=0xFF;
    msg.data[7]=0xFF;
    msg.id = 0x18FED925;
    msg.len = 0x08;
    msg.type = 0x00;
    CAN2_SendMessage(&msg);

}

void PCAN_18FFD017(void) {
    CAN_MESSAGE message_ICU2VCU01;
    unsigned long temp;
    message_ICU2VCU01.id = 0x18FFD017;
    
    if(ADV[2] < 500)
        temp = 0;
    else if(ADV[2] > 3000)
        temp = 250;
    else temp = (ADV[2] - 500) / 10;   
    message_ICU2VCU01.data[0] = temp;//前气压
    
    if(ADV[3] < 500)
        temp = 0;
    else if(ADV[3] > 3000)
        temp = 250;
    else temp = (ADV[3] - 500) / 10;    
    message_ICU2VCU01.data[1] = temp;//后气压    
       
    message_ICU2VCU01.data[2] = 0;        
    message_ICU2VCU01.data[3] = SPEED; 
    temp = e_total_miles * 20;
    message_ICU2VCU01.data[4] = (unsigned char) (temp); //低八位
    message_ICU2VCU01.data[5] = (unsigned char) (temp >> 8); //二级八位
    message_ICU2VCU01.data[6] = (unsigned char) (temp >> 16); //三级八位
    message_ICU2VCU01.data[7] = (unsigned char) (temp >> 24); //高八位
    message_ICU2VCU01.len = 8;
    message_ICU2VCU01.type = 0;
    CAN2_SendMessage(&message_ICU2VCU01);
}

void PCAN_18FFD117(void) {
    CAN_MESSAGE message_ICU2VCU01;
    DATA_BIT CAN_DATA;
    message_ICU2VCU01.id = 0x18FFD117;
    
    CAN_DATA.bit1 = 0;    
    CAN_DATA.bit2 = IN37;    //ABS
    CAN_DATA.bit3 = 0;   
    CAN_DATA.bit4 = (!rKL6 || !rKL8 || !rKL11 || !rKL12);  //刹车片报警
    CAN_DATA.bit5 = 1;  
    CAN_DATA.bit6 = 1;
    CAN_DATA.bit7 = 1;   
    CAN_DATA.bit8 = 1;   
    message_ICU2VCU01.data[0] = CAN_DATA.byte;       
    
    CAN_DATA.bit1 = 1;    
    CAN_DATA.bit2 = 1;    
    CAN_DATA.bit3 = 1;   
    CAN_DATA.bit4 = 1;  
    CAN_DATA.bit5 = 0;  
    CAN_DATA.bit6 = (SPEED > 69);  //超速
    CAN_DATA.bit7 = LED18;         //手刹
    CAN_DATA.bit8 = 0;         
    message_ICU2VCU01.data[1] = CAN_DATA.byte; 
    
    CAN_DATA.bit1 = 1;    
    CAN_DATA.bit2 = 1;    
    CAN_DATA.bit3 = LED20;        //后雾灯
    CAN_DATA.bit4 = 0;  
    CAN_DATA.bit5 = IN29;         //小灯
    CAN_DATA.bit6 = 0;  
//    CAN_DATA.bit7 = (Current_Gear == 125);//档位      
   // CAN_DATA.bit8 = (Current_Gear == 124);         
    message_ICU2VCU01.data[2] = CAN_DATA.byte;
    
    message_ICU2VCU01.data[3] = 0xFF; 
    
    CAN_DATA.bit1 = 1;    
    CAN_DATA.bit2 = 1;    
    CAN_DATA.bit3 = 1;       
    CAN_DATA.bit4 = 1;  
    CAN_DATA.bit5 = 1;         
    CAN_DATA.bit6 = 1;  
    CAN_DATA.bit7 = LED24;//脚刹      
    CAN_DATA.bit8 = 0;         
    message_ICU2VCU01.data[4] = CAN_DATA.byte;

    message_ICU2VCU01.data[5] = 0xFF; //
    message_ICU2VCU01.data[6] = 0xFF; //
    message_ICU2VCU01.data[7] = ADV[0] * 2; //蓄电池电压
    message_ICU2VCU01.len = 8;
    message_ICU2VCU01.type = 0;
    CAN2_SendMessage(&message_ICU2VCU01);
}

void PCAN_18FFD217(void) {
    CAN_MESSAGE message_ICU2VCU01;
    unsigned long temp;
    message_ICU2VCU01.id = 0x18FFD217;
  
    message_ICU2VCU01.data[0] = 0;//    
    message_ICU2VCU01.data[1] = 0;//          
    message_ICU2VCU01.data[2] = 0;        
    message_ICU2VCU01.data[3] = 0; 
    temp = e_single_miles * 20;
    message_ICU2VCU01.data[4] = (unsigned char) (temp); //低八位
    message_ICU2VCU01.data[5] = (unsigned char) (temp >> 8); //二级八位
    message_ICU2VCU01.data[6] = (unsigned char) (temp >> 16); //三级八位
    message_ICU2VCU01.data[7] = (unsigned char) (temp >> 24); //高八位
    message_ICU2VCU01.len = 8;
    message_ICU2VCU01.type = 0;
    CAN2_SendMessage(&message_ICU2VCU01);
}

void PCAN_send_req(void) {
    CAN_MESSAGE msg;
    msg.data[0] = 0xff;
    msg.data[1] = (unsigned char) 0x0f
            + (unsigned char) ((ccvs_eng_req & 0x03) << 4)
            +(unsigned char) (0x03 << 6);
    msg.data[2]=0xFF;
    msg.data[3]=0xFF;
    msg.data[4]=0xFF;
    msg.data[5]=0xFF;
    msg.data[6]=0xFF;
    msg.data[7]=0xFF;
    msg.id = 0x18FED917;
    msg.len = 0x08;
    msg.type = 0x00;
    CAN2_SendMessage(&msg);

}

void PCAN_0CFE6CEE(void) {
    CAN_MESSAGE message_ICU2VCU01;
    message_ICU2VCU01.id = 0x0CFE6CEE;
  
    message_ICU2VCU01.data[0] = 0;//    
    message_ICU2VCU01.data[1] = 0;//          
    message_ICU2VCU01.data[2] = 0;        
    message_ICU2VCU01.data[3] = 0; 
    message_ICU2VCU01.data[4] = 0; //
    message_ICU2VCU01.data[5] = 0; //
    message_ICU2VCU01.data[6] = 0; //
    message_ICU2VCU01.data[7] = (unsigned char) SPEED; //车速
    message_ICU2VCU01.len = 8;
    message_ICU2VCU01.type = 0;
    CAN2_SendMessage(&message_ICU2VCU01);
}

void PCAN_18A70017(void) {
    CAN_MESSAGE message;
    DATA_BIT CAN_DATA;
    message.id = 0x18A70017;
      
    message.data[0] = 0;//    
    message.data[1] = 0;//   
    
//    CAN_DATA.bit1 = (Current_Gear == 125);    //空挡
    CAN_DATA.bit2 = 0;    
    CAN_DATA.bit3 = 0;       
    CAN_DATA.bit4 = 0;  
    CAN_DATA.bit5 = fKL15;                    //前门      
    CAN_DATA.bit6 = 0;  
    CAN_DATA.bit7 = fKH1;                     //中门
    CAN_DATA.bit8 = 0;
    message.data[2] = CAN_DATA.byte;   
    
    CAN_DATA.bit1 = 0;    
    CAN_DATA.bit2 = 0;    
    CAN_DATA.bit3 = 0;       
    CAN_DATA.bit4 = 0;  
    CAN_DATA.bit5 = LED22;                    //近光灯      
    CAN_DATA.bit6 = 0;  
    CAN_DATA.bit7 = LED17;                    //远光灯
    CAN_DATA.bit8 = 0;
    message.data[3] = CAN_DATA.byte; 
    
    CAN_DATA.bit1 = LED4;                     //左转向灯
    CAN_DATA.bit2 = 0;    
    CAN_DATA.bit3 = LED8;                     //右转向灯
    CAN_DATA.bit4 = 0;  
    CAN_DATA.bit5 = 0;                   
    CAN_DATA.bit6 = 0;  
    CAN_DATA.bit7 = 0;                   
    CAN_DATA.bit8 = 0;
    message.data[4] = CAN_DATA.byte; //
    
    message.data[5] = 0; //
    message.data[6] = 0; //
    message.data[7] = 0; //
    message.len = 8;
    message.type = 0;
    CAN2_SendMessage(&message);
}
*/
//CAN任务调度函数添加
TASK_COMPONENTS TaskComps[] = {
    /*{0, 100, 100, BCAN_send_pct1},
    {0, 100, 100, BCAN_send_pct2},
    //{0, 10, 10, PCAN_Send1},
    //{0, 10, 10, PCAN_Send2},
    //{0, 100, 100, PCAN_Send_TCO1},
    //{0, 100, 100, PCAN_Send_TCO2},
    {0, 5, 5, PCAN_0CFE6CEE},
    {0, 10, 10, PCAN_CCVS},    
    {0, 20, 20, PCAN_18FFD017},
    {0, 20, 20, PCAN_18FED925},
    {0, 20, 20, PCAN_18FFD117},
    {0, 20, 20, PCAN_18FFD217},   
    {0, 20, 20, PCAN_18A70017},
    {0, 100, 100, PCAN_18EBFFD7},*/
    {PCAN_0x0C18A7A1,10},
    {PCAN_0x0C19A7A1,10},
    {BCAN_send_pct1, 100},
    {BCAN_send_pct2, 100},
    //{0, 10, 10, PCAN_Send1},
    //{0, 10, 10, PCAN_Send2},
    //{0, 100, 100, PCAN_Send_TCO1},
    //{0, 100, 100, PCAN_Send_TCO2},
    //{PCAN_0CFE6CEE, 5},
    //{PCAN_CCVS, 10},
    //{PCAN_18FFD017, 20},
    //{PCAN_18FED925, 20},
    //{PCAN_18FFD117, 20},
    //{PCAN_18FFD217, 20},
    //{PCAN_18A70017, 20},
    //{PCAN_18EBFFD7, 100},
    {NULL}
};