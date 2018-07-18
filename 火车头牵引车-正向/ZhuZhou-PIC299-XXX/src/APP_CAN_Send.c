/*
 * File:   APP_CAN.c
 * Author: pnc
 *
 * Created on 2017��7��28��, ����5:02
 */

#include "APP_System.h"

DATA_BIT gCTL[8]; //�Ǳ����������Ϣ

//CAN������Ⱥ������
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
    message_ICU2VCU01.id = 0x18FFD017;

    if(ADV[3] < 500)
        temp = 0;
    else if(ADV[3] > 3000)
        temp = 125;
    else temp = (ADV[3] - 500) * 0.05;   
    message_ICU2VCU01.data[0] = temp;//ǰ��ѹ
    
    if(ADV[4] < 500)
        temp = 0;
    else if(ADV[4] > 3000)
        temp = 125;
    else temp = (ADV[4] - 500) * 0.05;    
    message_ICU2VCU01.data[1] = temp;//����ѹ    
       
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
    message_ICU2VCU02.data[1] = (unsigned char) (e_total_miles); //�Ͱ�λ
    message_ICU2VCU02.data[2] = (unsigned char) (e_total_miles >> 8); //������λ
    message_ICU2VCU02.data[3] = (unsigned char) (e_total_miles >> 16); //������λ
    message_ICU2VCU02.data[4] = (unsigned char) (e_total_miles >> 24); //�߰�λ
    message_ICU2VCU02.data[5] = (unsigned char) (e_single_miles);
    message_ICU2VCU02.data[6] = (unsigned char) (e_single_miles >> 8);
    message_ICU2VCU02.data[7] = 0;
    message_ICU2VCU02.len = 8;
    message_ICU2VCU02.type = 0;
    CAN2_SendMessage(&message_ICU2VCU02);
}

//�������г���¼��
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

    CAN_DATA.bit1 = LED22;             //�����
    CAN_DATA.bit2 = 0;
    CAN_DATA.bit3 = (LED19 || LED20);  //���
    CAN_DATA.bit4 = 0;
    CAN_DATA.bit5 = 0;   //������
    CAN_DATA.bit6 = 0;
    CAN_DATA.bit7 = 0;                 //����
    CAN_DATA.bit8 = 0;
    msg.data[0] = CAN_DATA.byte;

    CAN_DATA.bit1 = 0; /*((DMC_Level == 0 && DMC_Status == 3) || //������ع���
            (((DMY_Status >> 4) & 0x03) == 2) ||            //�ͱù���
            (((DMQ_Status >> 4) & 0x03) == 2) ||            //���ù���
            (DCDC_Code > 0 && DCDC_Code < 51) ||            //DCDC���ع���
            LED14);                                         //���ϵͳ����
    */
    CAN_DATA.bit2 = 0;
    CAN_DATA.bit3 = LED8;               //��ת���
    CAN_DATA.bit4 = 0;
    CAN_DATA.bit5 = LED4;               //��ת��
    CAN_DATA.bit6 = 0;
    CAN_DATA.bit7 = (LED1 || LED2);       //���ſ�
    CAN_DATA.bit8 = 0;
    msg.data[1] = CAN_DATA.byte;

    CAN_DATA.bit1 = 0;                  //��ǿ��ѡ�񿪹�
    CAN_DATA.bit2 = 0;
    CAN_DATA.bit3 = 0;
    CAN_DATA.bit4 = 0;
    CAN_DATA.bit5 = (LED9 || LED11);     //����ѹ����
    CAN_DATA.bit6 = 0;
    CAN_DATA.bit7 = LED17;              //Զ���
    CAN_DATA.bit8 = 0;
    msg.data[2] = CAN_DATA.byte;

    CAN_DATA.bit1 = 0; //ˮ�¸߱���
    CAN_DATA.bit2 = 0;
    CAN_DATA.bit3 = fKL10; //ˮλ�ͱ���
    CAN_DATA.bit4 = 0;
    CAN_DATA.bit5 = 0; //���˱���
    CAN_DATA.bit6 = 0;
    CAN_DATA.bit7 = 0; //��ѹ����
    CAN_DATA.bit8 = 0;
    msg.data[3] = CAN_DATA.byte;

    CAN_DATA.bit1 = LED9;  //ǰ��ѹ����
    CAN_DATA.bit2 = 0;    
    CAN_DATA.bit3 = LED11; //����ѹ����
    CAN_DATA.bit4 = 0;
    CAN_DATA.bit5 = 0;
    CAN_DATA.bit6 = 0;
    CAN_DATA.bit7 = 0;
    CAN_DATA.bit8 = 0;
    msg.data[4] = CAN_DATA.byte;

    CAN_DATA.bit1 = LED24; //ɲ������
    CAN_DATA.bit2 = 0;
    CAN_DATA.bit3 = 0;    //����������
    CAN_DATA.bit4 = 0;
    CAN_DATA.bit5 = LED2;  //��2��
    CAN_DATA.bit6 = 0;
    CAN_DATA.bit7 = LED1;  //��1��
    CAN_DATA.bit8 = 0;
    msg.data[5] = CAN_DATA.byte;

    CAN_DATA.bit1 = 0; //����3
    CAN_DATA.bit2 = 0;
    CAN_DATA.bit3 = 0; //����2
    CAN_DATA.bit4 = 0;
    CAN_DATA.bit5 = 0; //����1
    CAN_DATA.bit6 = 0;
    CAN_DATA.bit7 = 0; //������ѡ�� 00���� 01����
    CAN_DATA.bit8 = 0;
    msg.data[6] = CAN_DATA.byte;

    CAN_DATA.bit1 = 0; //����3
    CAN_DATA.bit2 = 0;
    CAN_DATA.bit3 = 0; //����2
    CAN_DATA.bit4 = 0;
    CAN_DATA.bit5 = 0; //����1
    CAN_DATA.bit6 = 0;
    CAN_DATA.bit7 = 0; //����ѡ�� 00��ͨ������ 01BRT��
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
    msg.data[2] = (unsigned char) ((temp >> 16) & 0x0F) + CAN_DATA.byte; //������λ
    msg.data[3] = (unsigned char) (temp >> 8); //������λ
    msg.data[4] = (unsigned char) (temp); //�Ͱ�λ
    msg.data[5] = 0;
    msg.data[6] = ((life++)&0x0F);
    msg.data[7] = 0;
    
    msg.id = 0x2A0;
    msg.len = 0x08;
    msg.type = 0x01;
    CAN2_SendMessage(&msg);

}