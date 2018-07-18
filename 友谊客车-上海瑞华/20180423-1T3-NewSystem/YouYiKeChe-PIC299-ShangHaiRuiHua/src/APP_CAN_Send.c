/*
 * File:   APP_CAN.c
 * Author: pnc
 *
 * Created on 2017��7��28��, ����5:02
 */

#include "APP_System.h"

DATA_BIT gCTL[8]; //�Ǳ����������Ϣ
unsigned char ccvs_eng_req; //��������
unsigned char pct_cut[][15] = {//����������λ��100mA
    {120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120}, 
    {120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120},
    {120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120}};
unsigned char pct_time[] = {5, 5, 5}; //����ʱ�䵥λ��100mA

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
*/
void BCAN_send_pct1(void) {
    CAN_MESSAGE msg;
    msg.data[0] = pct_cut[0][0]; 
    msg.data[1] = pct_cut[0][1];
    msg.data[2] = pct_cut[0][2]; 
    msg.data[3] = pct_cut[0][3]; 
    msg.data[4] = pct_cut[0][4];
    msg.data[5] = pct_cut[0][5];
    msg.data[6] = pct_cut[0][6];
    msg.data[7] = pct_cut[0][7];
    msg.id = 0x500 + 1;
    msg.len = 0x08;
    msg.type = 0x01;
    CAN1_SendMessage(&msg);

}

void BCAN_send_pct2(void) {
    CAN_MESSAGE msg;
    msg.data[0] = pct_cut[0][8]; 
    msg.data[1] = pct_cut[0][9];
    msg.data[2] = pct_cut[0][10]; 
    msg.data[3] = pct_cut[0][11]; 
    msg.data[4] = pct_cut[0][12];
    msg.data[5] = pct_cut[0][13];
    msg.data[6] = pct_cut[0][14];
    msg.data[7] = pct_time[0];
    msg.id = 0x510 + 1;
    msg.len = 0x08;
    msg.type = 0x01;
    CAN1_SendMessage(&msg);

}

void BCAN_send_pct3(void) {
    CAN_MESSAGE msg;
    msg.data[0] = pct_cut[1][0]; 
    msg.data[1] = pct_cut[1][1];
    msg.data[2] = pct_cut[1][2]; 
    msg.data[3] = pct_cut[1][3]; 
    msg.data[4] = pct_cut[1][4];
    msg.data[5] = pct_cut[1][5];
    msg.data[6] = pct_cut[1][6];
    msg.data[7] = pct_cut[1][7];
    msg.id = 0x500 + 2;
    msg.len = 0x08;
    msg.type = 0x01;
    CAN1_SendMessage(&msg);

}

void BCAN_send_pct4(void) {
    CAN_MESSAGE msg;
    msg.data[0] = pct_cut[1][8]; 
    msg.data[1] = pct_cut[1][9];
    msg.data[2] = pct_cut[1][10]; 
    msg.data[3] = pct_cut[1][11]; 
    msg.data[4] = pct_cut[1][12];
    msg.data[5] = pct_cut[1][13];
    msg.data[6] = pct_cut[1][14];
    msg.data[7] = pct_time[1];
    msg.id = 0x510 + 2;
    msg.len = 0x08;
    msg.type = 0x01;
    CAN1_SendMessage(&msg);

}

void BCAN_send_pct5(void) {
    CAN_MESSAGE msg;
    msg.data[0] = pct_cut[2][0]; 
    msg.data[1] = pct_cut[2][1];
    msg.data[2] = pct_cut[2][2]; 
    msg.data[3] = pct_cut[2][3]; 
    msg.data[4] = pct_cut[2][4];
    msg.data[5] = pct_cut[2][5];
    msg.data[6] = pct_cut[2][6];
    msg.data[7] = pct_cut[2][7];
    msg.id = 0x500 + 3;
    msg.len = 0x08;
    msg.type = 0x01;
    CAN1_SendMessage(&msg);

}

void BCAN_send_pct6(void) {
    CAN_MESSAGE msg;
    msg.data[0] = pct_cut[2][8]; 
    msg.data[1] = pct_cut[2][9];
    msg.data[2] = pct_cut[2][10]; 
    msg.data[3] = pct_cut[2][11]; 
    msg.data[4] = pct_cut[2][12];
    msg.data[5] = pct_cut[2][13];
    msg.data[6] = pct_cut[2][14];
    msg.data[7] = pct_time[2];
    msg.id = 0x510 + 3;
    msg.len = 0x08;
    msg.type = 0x01;
    CAN1_SendMessage(&msg);

}

void BCAN_test_0x550(void) {
    CAN_MESSAGE msg;
    msg.data[0] = sw_input[0].byte;
    msg.data[1] = sw_input[1].byte;
    msg.data[2] = sw_input[2].byte;
    msg.data[3] = sw_input[3].byte;
    msg.data[4] = sw_input[4].byte;
    msg.data[5] = freq[0];
    msg.data[6] = freq[1];
    msg.data[7] = ADV[0] / 5;
    msg.id = 0x550;
    msg.len = 0x08;
    msg.type = 0x01;
    if (TestMode) {
        CAN1_SendMessage(&msg);
    }
}

void BCAN_test_0x551(void) {
    CAN_MESSAGE msg;
    msg.data[0] = ADR[1] / 4;
    msg.data[1] = ADR[2] / 4;
    msg.data[2] = ADR[3] / 4;
    msg.data[3] = ADR[4] / 4;
    msg.data[4] = ADR[4] / 4;
    msg.data[5] = ADR[6] / 4;
    msg.data[6] = VERISON;
    msg.data[7] = 0;
    msg.id = 0x551;
    msg.len = 0x08;
    msg.type = 0x01;
    if (TestMode) {
        CAN1_SendMessage(&msg);
    }
}

void BCAN_test_0x552(void) {
    CAN_MESSAGE msg;
    msg.data[0] = ADV[1] / 20;
    msg.data[1] = ADV[2] / 20;
    msg.data[2] = ADV[3] / 20;
    msg.data[3] = ADV[4] / 20;
    msg.data[4] = ADV[4] / 20;
    msg.data[5] = ADV[6] / 20;
    msg.data[6] = 0;
    msg.data[7] = 0;
    msg.id = 0x552;
    msg.len = 0x08;
    msg.type = 0x01;
    if (TestMode) {
        CAN1_SendMessage(&msg);
    }
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
    //CAN_DATA.bit5 = (VCU_Gear == 1);   //������
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
    CAN2_SendMessage(&msg);
}

void PCAN_0x0C19A7A1(void) {
    CAN_MESSAGE msg;
    unsigned int temp;
    DATA_BIT CAN_DATA;
    msg.id = 0x0C19A7A1;

    CAN_DATA.bit1 = 0; 
    CAN_DATA.bit2 = 0; 
    CAN_DATA.bit3 = 0; 
    CAN_DATA.bit4 = 1;  //ǰ�ſ��ź�
    CAN_DATA.bit5 = 1;  //���ſ��ź�
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
    CAN2_SendMessage(&msg);
}
//�̿ط��ͱ���
/*
void PCAN_CCVS(void) {
    CAN_MESSAGE message_CCVS;
    DATA_BIT CAN_DATA;
    unsigned int temp;
    message_CCVS.id = 0x18FEF117;
    
    CAN_DATA.bit1 = 1; 
    CAN_DATA.bit2 = 1; 
    CAN_DATA.bit3 = LED18;  //��ɲ
    CAN_DATA.bit4 = 0;  
    CAN_DATA.bit5 = 1;      //�յ�ѹ��������״̬ 00 = ����  01 = ������  11 = ��Ч
    CAN_DATA.bit6 = 1;
    CAN_DATA.bit7 = 1; 
    CAN_DATA.bit8 = 1;
    message_CCVS.data[0] = CAN_DATA.byte;
    message_CCVS.data[1] = 0;
    message_CCVS.data[2] = (unsigned char) SPEED;//(unsigned char) (SPEED * 100 / e_hm_pulse); //���ٷ�ʵ�ʳ���
    
    CAN_DATA.bit1 = 1;      //��������ֹ���� 00=����ֹ������ 01=��ֹ��������11=��Ч����ʾû�и��ź������
    CAN_DATA.bit2 = 1; 
    CAN_DATA.bit3 = rKL10;  //���������ſ���
    CAN_DATA.bit4 = 0;  
    CAN_DATA.bit5 = LED24;  //��ɲ
    CAN_DATA.bit6 = 0;
    CAN_DATA.bit7 = 1;      
    CAN_DATA.bit8 = 1;
    message_CCVS.data[3] = CAN_DATA.byte;
    
    CAN_DATA.bit1 = 0;      //00=Ҫ������ΪĬ��ֵ��70��01=Ҫ������Ϊ100km/h 11=��Ч
    CAN_DATA.bit2 = 0; 
    CAN_DATA.bit3 = 1;      //���ڶ˸��ź� 00= off ���أ�01= on ������11=��Ч����ʾû�и��ź������
    CAN_DATA.bit4 = 1;  
    CAN_DATA.bit5 = fKL15;  //ǰ�ſ���
    CAN_DATA.bit6 = 0;
    CAN_DATA.bit7 = fKH1;   //���ſ���
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
    msg.data[0] = (unsigned char) (e_total_miles); //�Ͱ�λ
    msg.data[1] = (unsigned char) (e_total_miles >> 8); //������λ
    msg.data[2] = (unsigned char) (e_total_miles >> 16); //������λ
    msg.data[3] = (unsigned char) (e_total_miles >> 24); //�߰�λ
    msg.data[4] = (unsigned char) (e_single_miles); //�����ź�
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
    
    CAN_DATA.bit1 = LED22;  //�����
    CAN_DATA.bit2 = 0; 
    CAN_DATA.bit3 = LED19;  //ǰ���
    CAN_DATA.bit4 = 0;  
    CAN_DATA.bit5 = LED21;  //������
    CAN_DATA.bit6 = 0;
    CAN_DATA.bit7 = 1;      //����
    CAN_DATA.bit8 = 1;
    msg.data[0] = CAN_DATA.byte;
    
    CAN_DATA.bit1 = 1;      //���ع���  
    CAN_DATA.bit2 = 1; 
    CAN_DATA.bit3 = LED8;   //��ת���
    CAN_DATA.bit4 = 0;  
    CAN_DATA.bit5 = LED4;   //��ת���
    CAN_DATA.bit6 = 0;
    CAN_DATA.bit7 = (fKL15 || fKH1);      //�ſ�
    CAN_DATA.bit8 = 0;
    msg.data[1] = CAN_DATA.byte;
    
    CAN_DATA.bit1 = 1;    
    CAN_DATA.bit2 = 1; 
    CAN_DATA.bit3 = 1; 
    CAN_DATA.bit4 = 1;  
    CAN_DATA.bit5 = (fPOUT.BITS.O1 || fPOUT.BITS.O2);  //���
    CAN_DATA.bit6 = 0;
    CAN_DATA.bit7 = LED17;    //Զ���
    CAN_DATA.bit8 = 0;
    msg.data[2] = CAN_DATA.byte;
    
    msg.data[3] = 0xFF;
    
    CAN_DATA.bit1 = LED9;    //��ѹ1
    CAN_DATA.bit2 = 0; 
    CAN_DATA.bit3 = LED11;   //��ѹ2
    CAN_DATA.bit4 = 0;  
    CAN_DATA.bit5 = 1;  
    CAN_DATA.bit6 = 1;
    CAN_DATA.bit7 = 1;   
    CAN_DATA.bit8 = 1;
    msg.data[4] = CAN_DATA.byte;
    
    CAN_DATA.bit1 = LED24;   //ɲ����
    CAN_DATA.bit2 = 0; 
    CAN_DATA.bit3 = 1;       //������
    CAN_DATA.bit4 = 1;  
    CAN_DATA.bit5 = fKL15;   //ǰ��״̬
    CAN_DATA.bit6 = 0;
    CAN_DATA.bit7 = fKH1;    //����״̬
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
    message_ICU2VCU01.data[0] = temp;//ǰ��ѹ
    
    if(ADV[3] < 500)
        temp = 0;
    else if(ADV[3] > 3000)
        temp = 250;
    else temp = (ADV[3] - 500) / 10;    
    message_ICU2VCU01.data[1] = temp;//����ѹ    
       
    message_ICU2VCU01.data[2] = 0;        
    message_ICU2VCU01.data[3] = SPEED; 
    temp = e_total_miles * 20;
    message_ICU2VCU01.data[4] = (unsigned char) (temp); //�Ͱ�λ
    message_ICU2VCU01.data[5] = (unsigned char) (temp >> 8); //������λ
    message_ICU2VCU01.data[6] = (unsigned char) (temp >> 16); //������λ
    message_ICU2VCU01.data[7] = (unsigned char) (temp >> 24); //�߰�λ
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
    CAN_DATA.bit4 = (!rKL6 || !rKL8 || !rKL11 || !rKL12);  //ɲ��Ƭ����
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
    CAN_DATA.bit6 = (SPEED > 69);  //����
    CAN_DATA.bit7 = LED18;         //��ɲ
    CAN_DATA.bit8 = 0;         
    message_ICU2VCU01.data[1] = CAN_DATA.byte; 
    
    CAN_DATA.bit1 = 1;    
    CAN_DATA.bit2 = 1;    
    CAN_DATA.bit3 = LED20;        //�����
    CAN_DATA.bit4 = 0;  
    CAN_DATA.bit5 = IN29;         //С��
    CAN_DATA.bit6 = 0;  
//    CAN_DATA.bit7 = (Current_Gear == 125);//��λ      
   // CAN_DATA.bit8 = (Current_Gear == 124);         
    message_ICU2VCU01.data[2] = CAN_DATA.byte;
    
    message_ICU2VCU01.data[3] = 0xFF; 
    
    CAN_DATA.bit1 = 1;    
    CAN_DATA.bit2 = 1;    
    CAN_DATA.bit3 = 1;       
    CAN_DATA.bit4 = 1;  
    CAN_DATA.bit5 = 1;         
    CAN_DATA.bit6 = 1;  
    CAN_DATA.bit7 = LED24;//��ɲ      
    CAN_DATA.bit8 = 0;         
    message_ICU2VCU01.data[4] = CAN_DATA.byte;

    message_ICU2VCU01.data[5] = 0xFF; //
    message_ICU2VCU01.data[6] = 0xFF; //
    message_ICU2VCU01.data[7] = ADV[0] * 2; //���ص�ѹ
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
    message_ICU2VCU01.data[4] = (unsigned char) (temp); //�Ͱ�λ
    message_ICU2VCU01.data[5] = (unsigned char) (temp >> 8); //������λ
    message_ICU2VCU01.data[6] = (unsigned char) (temp >> 16); //������λ
    message_ICU2VCU01.data[7] = (unsigned char) (temp >> 24); //�߰�λ
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
    message_ICU2VCU01.data[7] = (unsigned char) SPEED; //����
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
    
//    CAN_DATA.bit1 = (Current_Gear == 125);    //�յ�
    CAN_DATA.bit2 = 0;    
    CAN_DATA.bit3 = 0;       
    CAN_DATA.bit4 = 0;  
    CAN_DATA.bit5 = fKL15;                    //ǰ��      
    CAN_DATA.bit6 = 0;  
    CAN_DATA.bit7 = fKH1;                     //����
    CAN_DATA.bit8 = 0;
    message.data[2] = CAN_DATA.byte;   
    
    CAN_DATA.bit1 = 0;    
    CAN_DATA.bit2 = 0;    
    CAN_DATA.bit3 = 0;       
    CAN_DATA.bit4 = 0;  
    CAN_DATA.bit5 = LED22;                    //�����      
    CAN_DATA.bit6 = 0;  
    CAN_DATA.bit7 = LED17;                    //Զ���
    CAN_DATA.bit8 = 0;
    message.data[3] = CAN_DATA.byte; 
    
    CAN_DATA.bit1 = LED4;                     //��ת���
    CAN_DATA.bit2 = 0;    
    CAN_DATA.bit3 = LED8;                     //��ת���
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
//������8.3��ֱ��ͨѶЭ��
void PCAN_0x0811809F(void) {
    CAN_MESSAGE msg;
    unsigned int temp;
    static unsigned char Life;
    DATA_BIT CAN_DATA;
    msg.id = 0x0811809F;

    CAN_DATA.bit1 = (LED1 || LED2); 
    CAN_DATA.bit2 = LED18; 
    CAN_DATA.bit3 = LED24; 
    CAN_DATA.bit4 = IN18;
    CAN_DATA.bit5 = 0;
    CAN_DATA.bit6 = 0;
    CAN_DATA.bit7 = 0; 
    CAN_DATA.bit8 = 0;
    msg.data[0] = CAN_DATA.byte;
    
    if (ADV[3] < 500)
        temp = 0;
    else if (ADV[3] < 4500)
        temp = (ADV[3] - 500)*0.03;
    else
        temp = 120;
    msg.data[1] = temp;
    
    if (ADV[4] < 500)
        temp = 0;
    else if (ADV[4] < 4500)
        temp = (ADV[4] - 500)*0.03;
    else
        temp = 120;
    msg.data[2] = temp; 
    
    msg.data[3] = ADV[0] / 2; 
    
    if (ADV[6] < 500)
        temp = 0;
    else if (ADV[6] < 4500)
        temp = (ADV[6] - 500)*0.03;
    else
        temp = 120;
    msg.data[4] = temp;
    msg.data[5] = 0;  
    msg.data[6] = 0;
    msg.data[7] = Life++;
    msg.len = 8;
    msg.type = 0;
    CAN2_SendMessage(&msg);
}

void PCAN_0x0812809F(void) {
    CAN_MESSAGE msg;
    unsigned long temp;
    msg.id = 0x0812809F;

    msg.data[0] = (unsigned char) (e_single_miles);
    msg.data[1] = (unsigned char) (e_single_miles >> 8);
    
    temp = e_total_miles / 10;
    msg.data[2] = (unsigned char) (temp); //�Ͱ�λ
    msg.data[3] = (unsigned char) (temp >> 8); //������λ
    msg.data[4] = (unsigned char) (temp >> 16); //������λ
    msg.data[5] = (unsigned char) (temp >> 24); //�߰�λ
    msg.data[6] = 0;
    msg.data[7] = 0;
    msg.len = 8;
    msg.type = 0;
    CAN2_SendMessage(&msg);
}
//����ƫ��ϵͳ
void PCAN_0x18A70017(void) {
    CAN_MESSAGE msg;
    DATA_BIT CAN_DATA;
    msg.id = 0x18A70017;

    msg.data[0] = 0;
    msg.data[1] = 0;
    msg.data[2] = 0; //
    msg.data[3] = 0; //
    msg.data[4] = 0; //
    
    CAN_DATA.bit1 = 0; 
    CAN_DATA.bit2 = IN1; 
    CAN_DATA.bit3 = 0; 
    CAN_DATA.bit4 = IN5;
    CAN_DATA.bit5 = 0;
    CAN_DATA.bit6 = LED24;
    CAN_DATA.bit7 = 0; 
    CAN_DATA.bit8 = 0;
    msg.data[5] = CAN_DATA.byte; //
    msg.data[6] = 0;
    msg.data[7] = 0;
    msg.len = 8;
    msg.type = 0;
    CAN2_SendMessage(&msg);
}

void PCAN_0x00A90017(void) {
    CAN_MESSAGE msg;
    DATA_BIT CAN_DATA;
    msg.id = 0x00A90017;

    msg.data[0] = 0;
    msg.data[1] = 0;
    msg.data[2] = 0; //
    msg.data[3] = 0; //
    msg.data[4] = 0; //
    
    CAN_DATA.bit1 = 0; 
    CAN_DATA.bit2 = 0; 
    CAN_DATA.bit3 = 0; 
    CAN_DATA.bit4 = 0;
    CAN_DATA.bit5 = 0;
    CAN_DATA.bit6 = LED24;
    CAN_DATA.bit7 = 0; 
    CAN_DATA.bit8 = 0;
    msg.data[5] = 0; //
    msg.data[6] = 0;
    msg.data[7] = 0;
    msg.len = 8;
    msg.type = 0;
    CAN2_SendMessage(&msg);
}

//��ʻ��¼��
void PCAN_0x18F0AA17(void) {
    CAN_MESSAGE msg;
    DATA_BIT CAN_DATA;
    msg.id = 0x18F0AA17;

    msg.data[0] = SPEED;
    CAN_DATA.bit1 = 0; 
    CAN_DATA.bit2 = 0; 
    CAN_DATA.bit3 = 0; 
    CAN_DATA.bit4 = 0;
    CAN_DATA.bit5 = 0;
    CAN_DATA.bit6 = 0;
    CAN_DATA.bit7 = 0; 
    CAN_DATA.bit8 = 0;
    msg.data[1] = CAN_DATA.byte;
    msg.data[2] = 0; //
    msg.data[3] = 0; //
    msg.data[4] = 0; //      
    msg.data[5] = 0; //
    msg.data[6] = 0;
    msg.data[7] = 0;
    msg.len = 8;
    msg.type = 0;
    CAN2_SendMessage(&msg);
}
//CAN������Ⱥ������
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
    {BCAN_SendCtl, 5},
    {BCAN_send_mile, 5},
    {BCAN_send_pct1, 100},
    {BCAN_send_pct2, 100},
    {BCAN_send_pct3, 100},
    {BCAN_send_pct4, 100},
    {BCAN_send_pct5, 100},
    {BCAN_send_pct6, 100},
    {BCAN_test_0x550, 10},
    {BCAN_test_0x551, 10},
    {BCAN_test_0x552, 10},
    {PCAN_0x0811809F, 20},
    {PCAN_0x0812809F, 20},
    {PCAN_0x18A70017, 20},
    {PCAN_0x18F0AA17, 2},    
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