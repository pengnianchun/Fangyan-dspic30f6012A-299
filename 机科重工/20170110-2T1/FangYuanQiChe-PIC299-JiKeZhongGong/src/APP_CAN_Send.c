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

    temp.bit1 = ((M_ON && wake_up3) || wake_up2);
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
    //unsigned int temp;
    DATA_BIT CAN_DATA;
    message_ICU2VCU01.id = 0x18FFA217;
    
    CAN_DATA.bit1 = IN1;   //
    CAN_DATA.bit2 = IN2;  //
    CAN_DATA.bit3 = IN3;   //
    CAN_DATA.bit4 = IN4; //
    CAN_DATA.bit5 = IN5; //
    CAN_DATA.bit6 = IN6;  //
    CAN_DATA.bit7 = IN7;  //
    CAN_DATA.bit8 = IN8;  //
    message_ICU2VCU01.data[0] = CAN_DATA.byte;
    
    CAN_DATA.bit1 = IN9; 
    CAN_DATA.bit2 = IN10; 
    CAN_DATA.bit3 = IN11;     
    CAN_DATA.bit4 = IN12;     
    CAN_DATA.bit5 = IN13;     
    CAN_DATA.bit6 = IN14;
    CAN_DATA.bit7 = IN15; 
    CAN_DATA.bit8 = IN16;
    message_ICU2VCU01.data[1] = CAN_DATA.byte;        

    CAN_DATA.bit1 = IN17; 
    CAN_DATA.bit2 = IN18; 
    CAN_DATA.bit3 = IN19;
    CAN_DATA.bit4 = IN20;
    CAN_DATA.bit5 = IN21; 
    CAN_DATA.bit6 = IN22;
    CAN_DATA.bit7 = IN23;
    CAN_DATA.bit8 = IN24;
    message_ICU2VCU01.data[2] = CAN_DATA.byte; 
   
    CAN_DATA.bit1 = IN25; 
    CAN_DATA.bit2 = IN26; 
    CAN_DATA.bit3 = IN27;
    CAN_DATA.bit4 = IN28;
    CAN_DATA.bit5 = IN29; 
    CAN_DATA.bit6 = IN30;
    CAN_DATA.bit7 = IN31;
    CAN_DATA.bit8 = IN32;
    message_ICU2VCU01.data[3] = CAN_DATA.byte;
    
    CAN_DATA.bit1 = IN33; 
    CAN_DATA.bit2 = IN34; 
    CAN_DATA.bit3 = IN35;
    CAN_DATA.bit4 = IN36;
    CAN_DATA.bit5 = IN37; 
    CAN_DATA.bit6 = M_ON;
    CAN_DATA.bit7 = WAKE_Charge;
    CAN_DATA.bit8 = fKL10;
    message_ICU2VCU01.data[4] = CAN_DATA.byte;
    
    CAN_DATA.bit1 = fPOUT.BITS.O1; 
    CAN_DATA.bit2 = fPOUT.BITS.O2; 
    CAN_DATA.bit3 = fPOUT.BITS.O3;
    CAN_DATA.bit4 = fPOUT.BITS.O4;
    CAN_DATA.bit5 = fPOUT.BITS.O5; 
    CAN_DATA.bit6 = fPOUT.BITS.O6;
    CAN_DATA.bit7 = fPOUT.BITS.O7;
    CAN_DATA.bit8 = fPOUT.BITS.O8;
    message_ICU2VCU01.data[5] = CAN_DATA.byte;
    
    CAN_DATA.bit1 = fPOUT.BITS.O9; 
    CAN_DATA.bit2 = fPOUT.BITS.O10; 
    CAN_DATA.bit3 = fPOUT.BITS.O11;
    CAN_DATA.bit4 = fPOUT.BITS.O12;
    CAN_DATA.bit5 = fPOUT.BITS.O13; 
    CAN_DATA.bit6 = fPOUT.BITS.O14;
    CAN_DATA.bit7 = fPOUT.BITS.O15;
    CAN_DATA.bit8 = fKL1;
    message_ICU2VCU01.data[6] = CAN_DATA.byte;
    
    
    CAN_DATA.bit1 = fKL2; 
    CAN_DATA.bit2 = fKL3; 
    CAN_DATA.bit3 = fKL4;
    CAN_DATA.bit4 = fKL5;
    CAN_DATA.bit5 = fKL6; 
    CAN_DATA.bit6 = fKL7;
    CAN_DATA.bit7 = fKL8;
    CAN_DATA.bit8 = fKL9;
    message_ICU2VCU01.data[7] = CAN_DATA.byte;
    message_ICU2VCU01.len = 8;
    message_ICU2VCU01.type = 0;
    CAN2_SendMessage(&message_ICU2VCU01);
}

void PCAN_Send2(void) {
    CAN_MESSAGE message_ICU2VCU02;
    unsigned long temp;
    message_ICU2VCU02.id = 0x18FFA417;
    
    message_ICU2VCU02.data[0] = ADV[1]; //
    message_ICU2VCU02.data[1] = ADV[2];//
    message_ICU2VCU02.data[2] = ADV[3]; //
    message_ICU2VCU02.data[3] = ADV[4]; //
    message_ICU2VCU02.data[4] = ADV[5];
    message_ICU2VCU02.data[5] = ADV[6];
    message_ICU2VCU02.data[6] = (unsigned char)(freq[0]);//变速箱速度信号
    message_ICU2VCU02.data[7] = (unsigned char)(freq[0]>>8);
    message_ICU2VCU02.len = 8;
    message_ICU2VCU02.type = 0;
    CAN2_SendMessage(&message_ICU2VCU02);
}

void PCAN_Send3(void) {
    CAN_MESSAGE message_ICU2VCU02;
    unsigned long temp;
    DATA_BIT CAN_DATA;
    message_ICU2VCU02.id = 0x18FFA617;

    message_ICU2VCU02.data[0] = (unsigned char)(freq[1]);//车辆速度信号
    message_ICU2VCU02.data[1] = (unsigned char)(freq[1]>>8);
    message_ICU2VCU02.data[2] = (unsigned char)(fADR[0]);
    message_ICU2VCU02.data[3] = (unsigned char)(fADR[1]); 
    message_ICU2VCU02.data[4] = (unsigned char)(fFreq);
    message_ICU2VCU02.data[5] = (unsigned char)(fFreq>>8);
    
    CAN_DATA.bit1 = fKL11; 
    CAN_DATA.bit2 = fKL12; 
    CAN_DATA.bit3 = fKL13;
    CAN_DATA.bit4 = fKL14;
    CAN_DATA.bit5 = fKL15; 
    CAN_DATA.bit6 = 0;
    CAN_DATA.bit7 = 0;
    CAN_DATA.bit8 = 0;
    message_ICU2VCU02.data[6] = CAN_DATA.byte;
    message_ICU2VCU02.data[7] = 0;
    message_ICU2VCU02.len = 8;
    message_ICU2VCU02.type = 0;
    CAN2_SendMessage(&message_ICU2VCU02);
}