/*
 * File:   APP_CAN.c
 * Author: pnc
 *
 * Created on 2017��7��28��, ����5:02
 */

#include "APP_System.h"

DATA_BIT gCTL[8]; //�Ǳ����������Ϣ

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
    temp.bit2 = IN14; //����      
    temp.bit3 = IN15; //��Ъ
    temp.bit4 = IN16; //�쵵
    temp.bit5 = IN21; //��ˮ        
    if (IN14 && IN16)temp.bit2 = 0;
    if (IN21) {
        temp.bit2 = 0; //����
        temp.bit3 = 0; //��Ъ
        temp.bit4 = 0; //�쵵
    }
    message_POUT.data[6] = temp.byte;

    message_POUT.data[7] = 0;
    message_POUT.len = 8;
    message_POUT.type = 1;
    CAN1_SendMessage(&message_POUT);
}

void BCAN_send_mile(void) {
    CAN_MESSAGE msg;
    msg.data[0] = (unsigned char) (e_total_miles); //�Ͱ�λ
    msg.data[1] = (unsigned char) (e_total_miles >> 8); //������λ
    msg.data[2] = (unsigned char) (e_total_miles >> 16); //������λ
    msg.data[3] = (unsigned char) (e_total_miles >> 24); //�߰�λ
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
    DATA_BIT CAN_DATA;
    message_ICU2VCU01.id = 0x18F40117;

    message_ICU2VCU01.data[0] = ADV[0] / 2;
    
    CAN_DATA.bit1 = LED2; 
    CAN_DATA.bit2 = LED1; 
    CAN_DATA.bit3 = IN2;   //�����
    CAN_DATA.bit4 = M_ON;  //ON
    CAN_DATA.bit5 = IN12;  //START
    CAN_DATA.bit6 = LED15;
    CAN_DATA.bit7 = LED4; 
    CAN_DATA.bit8 = LED8;
    message_ICU2VCU01.data[1] = CAN_DATA.byte;
    
    CAN_DATA.bit1 = LED11; 
    CAN_DATA.bit2 = LED9; 
    CAN_DATA.bit3 = LED18;     
    CAN_DATA.bit4 = 0;     
    CAN_DATA.bit5 = 0;     
    CAN_DATA.bit6 = LED15;
    CAN_DATA.bit7 = LED4; 
    CAN_DATA.bit8 = LED8;
    message_ICU2VCU01.data[2] = CAN_DATA.byte;        
    
    if (ADV[3] < 500) temp = 0;
    else if (ADV[3] < 3000) temp = (ADV[3] - 500) * 0.3;
    else temp = 1000;
    message_ICU2VCU01.data[3] = temp / 4; //ǰ��ѹ

    if (ADV[4] < 500) temp = 0;
    else if (ADV[4] < 3000) temp = (ADV[4] - 500) * 0.3;
    else temp = 1000;
    message_ICU2VCU01.data[4] = temp / 4; //����ѹ    

    CAN_DATA.bit1 = LED24; 
    CAN_DATA.bit2 = LED17; 
    CAN_DATA.bit3 = LED22;
    CAN_DATA.bit4 = 0;
    CAN_DATA.bit5 = 0; 
    CAN_DATA.bit6 = 0;
    CAN_DATA.bit7 = 0;
    CAN_DATA.bit8 = 0;
    message_ICU2VCU01.data[5] = CAN_DATA.byte; 
   
    message_ICU2VCU01.data[6] = 0xFF;
    message_ICU2VCU01.data[7] = 0xFF;
    message_ICU2VCU01.len = 8;
    message_ICU2VCU01.type = 0;
    CAN2_SendMessage(&message_ICU2VCU01);
}

void PCAN_Send2(void) {
    CAN_MESSAGE message_ICU2VCU02;
    unsigned long temp;
    message_ICU2VCU02.id = 0x18F40217;
    temp = e_total_miles * 0.8;
    message_ICU2VCU02.data[0] = (unsigned char) (temp); //�Ͱ�λ
    message_ICU2VCU02.data[1] = (unsigned char) (temp >> 8); //������λ
    message_ICU2VCU02.data[2] = (unsigned char) (temp >> 16); //������λ
    message_ICU2VCU02.data[3] = (unsigned char) (temp >> 24); //�߰�λ
    message_ICU2VCU02.data[4] = 0;
    message_ICU2VCU02.data[5] = 0;
    message_ICU2VCU02.data[6] = 0;
    message_ICU2VCU02.data[7] = VERISON;
    message_ICU2VCU02.len = 8;
    message_ICU2VCU02.type = 0;
    CAN2_SendMessage(&message_ICU2VCU02);
}

