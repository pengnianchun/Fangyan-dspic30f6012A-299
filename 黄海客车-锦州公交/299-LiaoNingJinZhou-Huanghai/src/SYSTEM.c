#include "SYSTEM.h"
#include "LOGO.h"
unsigned char delay_cnt;
DATA_BIT gKEY[5];
DATA_BIT gCTL[8]; //�Ǳ����������Ϣ

unsigned int single_miles = 0;
unsigned long total_miles = 0;


unsigned int Fcan_count = 0; //ǰ��ģ��CAN
unsigned int Rcan_count = 0; //����ģ��CAN
unsigned int Mcan_count = 0; //�в�ģ��CAN
unsigned int Ecan_count = 0; //������ECUģ��CAN
unsigned int Vcan_count = 0; //����������VCUģ��CAN
unsigned int Bcan_count = 0; //��ع�����BMSģ��CAN
unsigned int Dcan_count = 0; //ת������DC/ACģ��CAN
unsigned int Acan_count = 0; //�յ�ACģ��CAN

unsigned int ADR[8]; //ģ�����ɼ�   10/15


DBCM_KEY fKEY; //ǰģ�鹦�ʿ���״̬
DBCM_KEY mKEY; //�У�����ģ�鹦�ʿ���״̬
DBCM_KEY rKEY; //��ģ�鹦�ʿ���״̬

unsigned int fFreq; //ǰģ��Ƶ��
unsigned int mFreq; //�У�����ģ��Ƶ��
unsigned int rFreq; //��ģ��Ƶ��

unsigned int fSpeed; //ǰģ�����㳵��
unsigned int mSpeed; //�У�����ģ�����㳵��
unsigned int rSpeed; //��ģ�����㳵��
unsigned int pSpeed; //�ⲿCAN���㳵��

unsigned int fADR[2]; //ǰģ�����ֵ
unsigned int mADR[2]; //�У�����ģ�����ֵ
unsigned int rADR[2]; //��ģ�����ֵ

unsigned int ADR[8]; //�Ǳ�ģ���źŲɼ�ֵ    2016/10/10

DBCM_POUT fPOUT; //ǰģ�鹦�����״̬
DBCM_POUT mPOUT; //�У�����ģ�鹦�����״̬
DBCM_POUT rPOUT; //��ģ�鹦�����״̬

unsigned char fPF[16]; //ǰģ�鹦���������
unsigned char mPF[16]; //�У�����ģ�鹦�ʹ���
unsigned char rPF[16]; //��ģ�鹦���������

unsigned int fpcur[15];//ǰģ�鹦���������
unsigned int mpcur[15];//��ģ�鹦���������
unsigned int rpcur[15];//��ģ�鹦���������

unsigned int fSingle_miles;
unsigned int mSingle_miles;
unsigned int rSingle_miles;

unsigned char ccvs_eng_req; //��������

unsigned char dm_hcu_display[32]; //��������
unsigned char dm_tcu_display[32];


//ϵͳ��ʼ������

void System_Init(void) {
    ADPCFG = 0xffff; //�ر�AD��     
    alarm_led[0].byte = 0xff; //��������˲��LED�ͷ�������˸
    alarm_led[1].byte = 0x00;
    alarm_led[2].byte = 0x00;
    alarm_led[3].byte = 0x00;
    LED_Out();
    /*�������ƽӿ� */
    KEY_UP_DR = 1; //   
    KEY_SET_DR = 1; // 
    KEY_AV_DR = 1;

    PWR_CTRL_DR = 1; //�����ѹ�˿ڳ�ʼ��
    PWR_CTRL = 0;

    LCD_Init();
    TIMER1_Init();
    delay_cnt = 10; //��ʱ0.1s
    while (delay_cnt > 1) {
        ClrWdt();
        SW_Input(); //���ض�ȡ
    }
    alarm_led[0].byte = 0xff;
    alarm_led[1].byte = 0x00;
    alarm_led[2].byte = 0x00;
    alarm_led[3].byte = 0x00;
    LED_Out();
    gCTL[0].byte = 0x00;
    gCTL[1].byte = 0x00;
    gCTL[2].byte = 0x00;
    gCTL[3].byte = 0x00;
    gCTL[4].byte = 0x00;
    gCTL[5].byte = 0x00;
    gCTL[6].byte = 0x00;
    gCTL[7].byte = 0x00;
    CAN1_Init();
    CAN2_Init();
    while (1) {
        ClrWdt();
        LCD_BackLight(0x00);
        if (wake_up1) {//���Σ�ձ�������
            F_PO8 = FLASH;
            F_PO6 = FLASH;
            R_PO11 = FLASH;
            R_PO12 = FLASH;
            LED4 = FLASH; //��ת���
            LED8 = FLASH; //��ת��� 
        } else {
            F_PO6 = 0;
            F_PO8 = 0;
            R_PO11 = 0;
            R_PO12 = 0;
            LED4 = 0; //��ת���
            LED8 = 0; //��ת��� 
        }

        if (F50ms) {
            F50ms = 0;
            LED_Out();
            SW_Input();
            BCAN_SendCtl();
        }

        if (M_ON || wake_up2) break; // �����ON�����������˳�

        if (wake_up1 == 0) {
            F_PO8 = 0;
            F_PO6 = 0;
            R_PO11 = 0;
            R_PO12 = 0;
            BCAN_SendCtl();
            __delay_us(100);
            BCAN_SendCtl();
            __delay_us(100);
            BCAN_SendCtl();
            __delay_us(100);
            BCAN_SendCtl();
            __delay_us(100);
            PWR_CTRL_DR = 1; //�رյ�Դ
            PWR_CTRL = 0; //�رյ�Դ 
            PWR_CTRL_DR = 1; //�رյ�Դ
            PWR_CTRL = 0; //�رյ�Դ 
            PWR_CTRL_DR = 1; //�رյ�Դ
            PWR_CTRL = 0; //�رյ�Դ 
        }
    }

    delay_cnt = 100; //����1s��ʱ 
    SM_Init();
    SM_Reset();
    BL_Init(); //�Ǳ�С�Ʊ����ʼ��
    INT1_Init();
    INT2_Init();
    TIMER3_Init();
    EEROM_ReadSingleMiles();
    EEROM_ReadTotalMiles();
    EEROM_ReadHMPulse();
    EEROM_ReadBackLight();
    single_miles = e_single_miles;
    total_miles = e_total_miles;
    OC1RS = e_backlight; //���±���ֵ
    ADC_Init();
    LCD_Init();
    alarm_led[0].byte = 0xC0; //����������
    alarm_led[1].byte = 0xff;
    alarm_led[2].byte = 0xff;
    alarm_led[3].byte = 0xff;
    LED_Out();
    while (delay_cnt > 1); //��ʱ1s
    OC1RS = 0;
    PWR_CTRL_DR = 0; //��Դ���ƽӿ�
    PWR_CTRL = 1; //����MCU��Դ����
    alarm_led[0].byte = 0xff;
    alarm_led[1].byte = 0x00;
    alarm_led[2].byte = 0x00;
    alarm_led[3].byte = 0x00;
    LED_Out();
    SW_Input();
    LCD_BackLight(7);
    DS3231_ReadTime(&timer); //��ȡʱ��   
}

void SYSTME_Logic(void) {
    // F_PO1 = (IN16 && M_ON); //��ο쵵
    // F_PO2 = (IN14 && M_ON); //�������
    // F_PO3 = (IN21 && M_ON); //��ˮ���
    F_PO4 = (IN19 && IN9 && (IN4 || M_ON)); //��ǰ���
    F_PO5 = (IN20 && (pSpeed < 2) && (IN4 || M_ON)); //ǰ�濪��ŷ�
    F_PO6 = (FLASH && (wake_up1 || (IN18 && (IN4 || M_ON)))); //��ת���
    F_PO7 = ((IN28 || (pSpeed > 2)) && (IN4 || M_ON)); //ǰ�Źص�ŷ�
    F_PO8 = (FLASH && (wake_up1 || (IN17 && (IN4 || M_ON)))); //��ת���
    F_PO9 = (IN19 && (IN4 || M_ON)); //λ�õ�
    F_PO10 = ((Current_Gear == 124)&& (IN4 || M_ON)); //������������Դ
    F_PO11 = (IN23 && (IN4 || M_ON)); //�ҽ����
    F_PO12 = (IN23 && (IN4 || M_ON)); //������
    F_PO13 = (IN24 && (IN4 || M_ON)); //��Զ��
    F_PO14 = (IN24 && (IN4 || M_ON)); //��Զ��
    F_PO15 = (IN19 && IN2 && (IN4 || M_ON)); //ǰ̤����
    /*
        M_PO1 = (IN12 && (IN4 || M_ON)); //����
        M_PO2 = (FLASH && (IN5 || wake_up1) && (IN4 || M_ON)); //��ת���
        M_PO3 = ((mKH1 || mKL15) && (IN4 || M_ON)); //����ָʾ�Ƶ�Դ
        M_PO4 = ((fKL6 || rKL6) && (IN4 || M_ON)); //�ƶ���
        M_PO5 = (IN20 && (moto_speed<50) && (IN4 || M_ON)); //ǰ�ſ���ŷ�
        M_PO6 = (IN19 && (IN4 || M_ON)); //ǰ·��
        M_PO7 = (IN28 && (IN4 || M_ON)); //ǰ�Źص�ŷ�
        M_PO8 = (IN19 && (IN4 || M_ON)); //��·��
        M_PO9 = (IN27 && (moto_speed<50) && (IN4 || M_ON)); //���ſ���ŷ�
        M_PO10 = (IN19 && (IN4 || M_ON)); //��·��
        M_PO11 = (IN26 && (IN4 || M_ON)); //���Źص�ŷ�
        M_PO12 = (IN19 && (IN4 || M_ON)); //��������
        M_PO13 = (IN6 && (IN4 || M_ON)); //С��
        M_PO14 = (IN19 && (IN4 || M_ON)); //������
        M_PO15 = (FLASH && (IN1 || wake_up1) && (IN4 || M_ON)); //��ת���
     */
    R_PO1 = IN4; //��������Դ
    R_PO2 = (IN27 && (pSpeed < 2) && (IN4 || M_ON)); //���ſ���ŷ�
    R_PO3 = ((IN26 || (pSpeed > 2)) && (IN4 || M_ON)); //���Źص�ŷ�     
    R_PO4 = (IN19 && IN3 && (IN4 || M_ON)); //��̤����
    R_PO5 = (IN11 && (IN4 || M_ON)); //���ڵ�1
    R_PO6 = (IN19 && IN9 && IN10); //�����
    R_PO7 = ((Current_Gear == 124) && (IN4 || M_ON)); //������
    R_PO8 = ((pSpeed < 5) && (IN4 || M_ON)); //�űõ�Դ
    R_PO9 = ((Brake_Pedal || rKL1) && (IN4 || M_ON)); //�ƶ���
    if ((rADR[0] < 1908) || IN13) { //����
        R_PO10 = 1;
    } else if ((rADR[0] > 2202) || !IN13)
        R_PO10 = 0;
    R_PO11 = (FLASH && (wake_up1 || (IN17 && (IN4 || M_ON)))); //��ת���
    R_PO12 = (FLASH && (wake_up1 || (IN18 && (IN4 || M_ON)))); //��ת���
    R_PO13 = (IN19 && (IN4 || M_ON)); //λ�õ�
    R_PO14 = (IN12 && (IN4 || M_ON)); //���ڵ�2
    R_PO15 = (((IN1 && (tcu_start_allow == 1) && (hcu_starter_forbid != 1)) || (ENG_start_req == 21415) || (rKL15 && (Current_Gear == 125))) && (IN4 || M_ON)); //ǰ����
    R_PO16 = 1;//������������

}

void Count_ADR(void) {
    float ad = 4096.0;
    //��ѹ�ʹ������ɼ�  ADR[]��ʵ�ʵĵ�ѹ*1000
    //ADR[1] = (unsigned int) (read_ADR(1) / ad * 5000);
    //ADR[2] = (unsigned int) (read_ADR(2) / ad * 5000);
    //ADR[3] = (unsigned int) (read_ADR(3) / ad * 5000);
    //ADR[4] = (unsigned int) (read_ADR(4) / ad * 5000);
    ADR[5] = (read_ADR(5) / ad * 5000);
    if (ADR[5] < 500)//0.5Vƫ��
        ADR[5] = 0;
    else ADR[5] = ADR[5] - 500;
    
    ADR[6] = (read_ADR(6) / ad * 5000);
    if (ADR[6] < 500)//0.5Vƫ��
        ADR[6] = 0;
    else ADR[6] = ADR[6] - 500;
    //���ص�ѹ    
    ADR[0] = (unsigned int) (550.0 * read_VOL() / ad); //ʵ�ʵ�ѹ�Ŵ�10��   //(read_VOL() - 1300)*10 / 76 + 180;
    //�����ʹ������ɼ�  ADR[]��ʵ�ʵ���ֵ
    //ADR[1] = (unsigned int) (100.0*read_ADR(1)/(ad-read_ADR(1)));//((read_ADR(1) / ad * 100) / (1 - read_ADR(1) / ad));
    //ADR[2] = (unsigned int) (100.0*read_ADR(2)/(ad-read_ADR(2)));
    //ADR[3] = (unsigned int) (100.0*read_ADR(3)/(ad-read_ADR(3)));
    //ADR[4] = (unsigned int) (100.0*read_ADR(4)/(ad-read_ADR(4)));
    //ADR[5] = (unsigned int) (100.0*read_ADR(5)/(ad-read_ADR(5)));
    //ADR[6] = (unsigned int) (100.0*read_ADR(6)/(ad-read_ADR(6)));
    //if (ADR[1] > 1000)
    //    ADR[1] = 0;
    //if (ADR[2] > 1000)
    //    ADR[2] = 0;
    //if (ADR[3] > 1000)
    //    ADR[3] = 0;
    //if (ADR[4] > 1000)
    //    ADR[4] = 0;
    //if (ADR[5] > 1000)
    //    ADR[5] = 0;
    //if (ADR[6] > 1000)
    //    ADR[6] = 0;
    
}

void LED_Logic(void) {

    //LED1 = ((ADR[5] < 15) && M_ON); //�������ͱ���

    //LED2 = 0;�յ�
    //LED3 = (IN16 && IN29 && M_ON); //�����ƶ�

    //��ת��
    if ((IN17 && M_ON) || wake_up1)
        LED4 = FLASH;
    else LED4 = 0;

    //LED5 = (IN11 && M_ON); //����Ԥ��

    //����ѹ�� 
    if (!Engine_wait) {
        if (IN33 && M_ON)//���ͱ���
            LED6 = 1;
        else if ((Engine_oil_press * 4 <= 70) && M_ON)
            LED6 = FLASH_1s;
        else LED6 = 0;
    } else LED6 = 0;

    if ((water_temp > 138) && M_ON)//ˮ�¹��߱���
        LED7 = 1;
    else LED7 = 0;
    //��ת���
    if ((IN18 && M_ON) || wake_up1)
        LED8 = FLASH;
    else LED8 = 0;

    if ((rKL3 || (ADR[5]/40 < 60)) && M_ON)//��ѹ1���ź�
        LED9 = 1;
    else
        LED9 = 0;

    LED10 = wake_up2; //�ܵ�Դָʾ   

    if ((rKL4 || (ADR[6]/40 < 60)) && M_ON) //��ѹ2
        LED11 = 1;
    else
        LED11 = 0;

    //����������ָʾ
    /*
    if (Engine_warn == 1 && M_ON)
        LED12 = 1;
    if (Engine_warn == 0)
        LED12 = 0;

    if (Maintain_warn == 1 && M_ON) {//ά������
        LED13 = 1;
    } else if (Maintain_warn == 0)LED13 = 0;

    //STOPͣ������
    if (Stop_warn == 1 && M_ON) {
        LED14 = 1;
    } else if (Stop_warn == 0)LED14 = 0;
    //�ȴ�����//û��ȷ���ź�Դ  
    if (Engine_wait == 1 && M_ON) {
        LED15 = 1;
    } else if (Engine_wait == 0) LED15 = 0;
*/
    LED16 = (!rKH1 && M_ON); //���س��

    LED17 = (IN24 && M_ON); //Զ���

    LED18 = (rKL2 && M_ON); //��ɲ

    LED19 = (IN9 && M_ON); //ǰ���

    LED20 = (IN10 && M_ON); //�����

    LED21 = ((Current_Gear == 124) && M_ON); //������

    LED22 = (IN23 && M_ON); //�����

    //LED23 = (IN14 && IN31 && M_ON);//������

    LED24 = ((Brake_Pedal || rKL1 || rKL12) && M_ON); //ɲ��ָʾ


    //������ Ϊ0ʱ�죬Ϊ1ʱ����   
    if (IN22)
        BUZZ = 1;
    else if ((mil_buzz_request) && !IN22)
        BUZZ = 0;
    else if((IN17 || IN18) && !IN22)
        BUZZ = !FLASH;
    else if((!rKL5 || rKL6 || rKL8 || rKL9 || !rKL10 || rKL11) && !IN22)
        BUZZ = !kFLASH;
    else if((rKL3 || rKL4) && !IN22)
        BUZZ = !FLASH_1s;
    else
        BUZZ = 1;
    //

    if (IN2) {
        PO2 = 0;
    } else {
        PO2 = 1;
    }

    if (IN19) {
        PO1 = 0;
    } else {
        PO1 = 1;
    }

    if (IN19)
        OC1RS = e_backlight;
    else OC1RS = 0;
    
    //���� 
    /*
    if (((tcu_start_allow == 1)&&(hcu_starter_forbid != 1)) || (ENG_start_req == 21415))
        PO1 = 0;
    else if (hcu_starter_forbid == 1) PO1 = 1;
    else PO1 = 1;
     */
    //if (Brake_Pedal == 0) PO2 = 1;
    //else if (Brake_Pedal == 1) PO2 = 0;



    mil_lamp_request = (CAN_18FECAEF.bData[0] >> 2)&0x03;
    fail_mode = (CAN_18FECAEF.bData[0] >> 4)&0x03;
    mil_buzz_request = (CAN_18FECAEF.bData[0] >> 6)&0x03;

    Lamp_status_YELLOW = (CAN_18FECA03.bData[0] >> 2)&0x03;
    Lamp_status_RED = (CAN_18FECA03.bData[0] >> 4)&0x03;

}

void BCAN_SendCtl(void) {
    CAN_MESSAGE message_POUT;
    message_POUT.id = 0x6a4;
    message_POUT.data[0] = gCTL[0].byte;
    message_POUT.data[1] = gCTL[1].byte;
    message_POUT.data[2] = gCTL[2].byte;
    message_POUT.data[3] = gCTL[3].byte;
    message_POUT.data[4] = gCTL[4].byte;
    message_POUT.data[5] = gCTL[5].byte;
    message_POUT.data[6] = ((M_ON && wake_up3) || IN4) + (IN14 << 1)+(IN15 << 2)+(IN16 << 3)+(IN21 << 4); //ģ����ο���
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

void PCAN_CCVS(void) {
    CAN_MESSAGE message_CCVS;
    DATA_BIT CAN_Send;
    message_CCVS.id = 0x18FEF117;
    CAN_Send.bit1 = 0;
    CAN_Send.bit2 = 0;
    CAN_Send.bit3 = rKL2;//��ɲ
    CAN_Send.bit4 = 0;
    CAN_Send.bit5 = 1;//�յ�
    CAN_Send.bit6 = 1;//�յ�
    CAN_Send.bit7 = 0;
    CAN_Send.bit8 = 0;
    message_CCVS.data[0] = CAN_Send.byte;
    
    message_CCVS.data[1] = (unsigned char) (pSpeed * 256);
    message_CCVS.data[2] = (unsigned char) (pSpeed * 256 >> 8);

    CAN_Send.bit1 = 1; //��������ֹ����
    CAN_Send.bit2 = 1; //��������ֹ����
    CAN_Send.bit3 = rKL7; //����� 
    CAN_Send.bit4 = 0; //�����
    CAN_Send.bit5 = rKL1; //��ɲ
    CAN_Send.bit6 = 0; //��ɲ
    CAN_Send.bit7 = 0;
    CAN_Send.bit8 = 0;
    message_CCVS.data[3] = CAN_Send.byte;

    CAN_Send.bit1 = 0; //����70
    CAN_Send.bit2 = 0; //����70
    CAN_Send.bit3 = rKL6; //���ڸ� 
    CAN_Send.bit4 = 0; //���ڸ� 
    CAN_Send.bit5 = 1; //ǰ��
    CAN_Send.bit6 = 1; //ǰ��
    CAN_Send.bit7 = 1; //����
    CAN_Send.bit8 = 1; //����
    message_CCVS.data[4] = CAN_Send.byte;
    
    
    message_CCVS.data[5] = (unsigned char) (ADR[5]/40); //ǰ��ѹ
    message_CCVS.data[6] = (unsigned char) (ADR[6]/40); //����ѹ
    message_CCVS.data[7] = 0xff;
    message_CCVS.len = 8;
    message_CCVS.type = 0;
    CAN2_SendMessage(&message_CCVS);
}

void PCAN_send_mile(void) {
    CAN_MESSAGE msg;
    msg.data[0] = (unsigned char) (e_total_miles); //�Ͱ�λ
    msg.data[1] = (unsigned char) (e_total_miles >> 8); //������λ
    msg.data[2] = (unsigned char) (e_total_miles >> 16); //������λ
    msg.data[3] = (unsigned char) (e_total_miles >> 24); //�߰�λ
    msg.data[4] = (unsigned char) (e_single_miles); //�Ͱ�λ; 
    msg.data[5] = (unsigned char) (e_single_miles >> 8); //������λ;
    msg.data[6] = 0x00;
    msg.data[7] = 0x00;
    msg.id = 0x18EBFFD7;
    msg.len = 0x08;
    msg.type = 0x00;
    CAN2_SendMessage(&msg);

}

void DM(unsigned char x, DM1 id) {//������id�ĵ�x���������spn��fmi
    SPN = id.bData[2 + 4 * (x - 1)]
            +((unsigned int) id.bData[3 + 4 * (x - 1)] << 8)
            +((unsigned long) (id.bData[4 + 4 * (x - 1)]&0xE0) << 11);
    FMI = (id.bData[4 + 4 * (x - 1)] & 0x1F);
}

/*
void DM_HCU(unsigned char x) {//��������x���������spn��fmi
    hcu_spn = CAN_18FECAEF.bData[2 + 4 * (x - 1)]
            +((unsigned int) CAN_18FECAEF.bData[3 + 4 * (x - 1)] << 8)
            +((unsigned long) (CAN_18FECAEF.bData[4 + 4 * (x - 1)]&0xE0) << 11);
    hcu_fmi = (CAN_18FECAEF.bData[4 + 4 * (x - 1)] & 0x1F);
    //if(hcu_spn==103) hcu_spn=0;//�����Ǳ�103�������޷�����
}

void DM_TCU(unsigned char x) {//��������x���������spn��fmi
    tcu_spn = CAN_18FECA03.bData[2 + 4 * (x - 1)]
            +((unsigned int) CAN_18FECA03.bData[3 + 4 * (x - 1)] << 8)
            +((unsigned long) (CAN_18FECA03.bData[4 + 4 * (x - 1)]&0xE0) << 11);
    tcu_fmi = (CAN_18FECA03.bData[4 + 4 * (x - 1)] & 0x1F);
}

void DM_CCU(unsigned char x) {//��������x���������spn��fmi
    ccu_spn = CAN_18FECAF5.bData[2 + 4 * (x - 1)]
            +((unsigned int) CAN_18FECAF5.bData[3 + 4 * (x - 1)] << 8)
            +((unsigned long) (CAN_18FECAF5.bData[4 + 4 * (x - 1)]&0xE0) << 11);
    ccu_fmi = (CAN_18FECAF5.bData[4 + 4 * (x - 1)] & 0x1F);
}

void DM_ECU(unsigned char x) {//��������x���������spn��fmi
    ecu_spn = CAN_18FECA00.bData[2 + 4 * (x - 1)]
            +((unsigned int) CAN_18FECA00.bData[3 + 4 * (x - 1)] << 8)
            +((unsigned long) (CAN_18FECA00.bData[4 + 4 * (x - 1)]&0xE0) << 11);
    ecu_fmi = (CAN_18FECA00.bData[4 + 4 * (x - 1)] & 0x1F);
}
 */
void __attribute__((__interrupt__, auto_psv)) _C1Interrupt(void) {
    unsigned char i = 0, j = 0;
    CAN_MESSAGE message;
    if (C1INTFbits.ERRIF) { //���մ���
        C1INTFbits.ERRIF = 0; // ��Ӵ��������
        CAN1_Init();
        C1RX0CONbits.RXFUL = 0;
    }
    if (C1INTFbits.IVRIF) {
        C1INTFbits.IVRIF = 0; //������Ч
        C1RX0CONbits.RXFUL = 0;
    }
    if (C1INTFbits.WAKIF) {
        C1INTFbits.WAKIF = 0;
    }


    if (C1RX0CONbits.RXFUL) { //������Ч
        CAN1_ReceiveMessage(&message);

        switch (message.id) {
            case 0x681:
                Fcan_count = 0;
                fKEY.BYTES[0] = message.data[0];
                fKEY.BYTES[1] = message.data[1];
                fKEY.BYTES[2] = message.data[2];
                fFreq = message.data[3]+((unsigned int) message.data[4] << 8);
                fSpeed = message.data[5]+((unsigned int) message.data[6] << 8);
                break;
            case 0x682:
                Mcan_count = 0;
                mKEY.BYTES[0] = message.data[0];
                mKEY.BYTES[1] = message.data[1];
                mKEY.BYTES[2] = message.data[2];
                mFreq = message.data[3]+((unsigned int) message.data[4] << 8);
                mSpeed = message.data[5]+((unsigned int) message.data[6] << 8);
                break;
            case 0x683:
                Rcan_count = 0;
                rKEY.BYTES[0] = message.data[0];
                rKEY.BYTES[1] = message.data[1];
                rKEY.BYTES[2] = message.data[2];
                rFreq = message.data[3]+((unsigned int) message.data[4] << 8);
                rSpeed = message.data[5]+((unsigned int) message.data[6] << 8);
                break;
            case 0x671:
                Fcan_count = 0;
                fADR[0] = message.data[0]+((unsigned int) message.data[1] << 8);
                fADR[1] = message.data[2]+((unsigned int) message.data[3] << 8);
                break;
            case 0x672:
                Mcan_count = 0;
                mADR[0] = message.data[0]+((unsigned int) message.data[1] << 8);
                mADR[1] = message.data[2]+((unsigned int) message.data[3] << 8);
                break;
            case 0x673:
                Rcan_count = 0;
                rADR[0] = message.data[0]+((unsigned int) message.data[1] << 8);
                rADR[1] = message.data[2]+((unsigned int) message.data[3] << 8);
                break;
            case 0x621:
                Fcan_count = 0;
                fpcur[0] = message.data[0]+((unsigned int) message.data[1] << 8);
                fpcur[1] = message.data[2]+((unsigned int) message.data[3] << 8);
                fpcur[2] = message.data[4]+((unsigned int) message.data[5] << 8);
                fpcur[3] = message.data[6]+((unsigned int) message.data[7] << 8);
                break;
            case 0x631:
                Fcan_count = 0;
                fpcur[4] = message.data[0]+((unsigned int) message.data[1] << 8);
                fpcur[5] = message.data[2]+((unsigned int) message.data[3] << 8);
                fpcur[6] = message.data[4]+((unsigned int) message.data[5] << 8);
                fpcur[7] = message.data[6]+((unsigned int) message.data[7] << 8);
                break;
            case 0x641:
                Fcan_count = 0;
                fpcur[8] = message.data[0]+((unsigned int) message.data[1] << 8);
                fpcur[9] = message.data[2]+((unsigned int) message.data[3] << 8);
                fpcur[10] = message.data[4]+((unsigned int) message.data[5] << 8);
                fpcur[11] = message.data[6]+((unsigned int) message.data[7] << 8);
                break;
            case 0x651:
                Fcan_count = 0;
                fpcur[12] = message.data[0]+((unsigned int) message.data[1] << 8);
                fpcur[13] = message.data[2]+((unsigned int) message.data[3] << 8);
                fpcur[14] = message.data[4]+((unsigned int) message.data[5] << 8);
                break;
                case 0x622:
                Mcan_count = 0;
                mpcur[0] = message.data[0]+((unsigned int) message.data[1] << 8);
                mpcur[1] = message.data[2]+((unsigned int) message.data[3] << 8);
                mpcur[2] = message.data[4]+((unsigned int) message.data[5] << 8);
                mpcur[3] = message.data[6]+((unsigned int) message.data[7] << 8);
                break;
            case 0x632:
                Mcan_count = 0;
                mpcur[4] = message.data[0]+((unsigned int) message.data[1] << 8);
                mpcur[5] = message.data[2]+((unsigned int) message.data[3] << 8);
                mpcur[6] = message.data[4]+((unsigned int) message.data[5] << 8);
                mpcur[7] = message.data[6]+((unsigned int) message.data[7] << 8);
                break;
            case 0x642:
                Mcan_count = 0;
                mpcur[8] = message.data[0]+((unsigned int) message.data[1] << 8);
                mpcur[9] = message.data[2]+((unsigned int) message.data[3] << 8);
                mpcur[10] = message.data[4]+((unsigned int) message.data[5] << 8);
                mpcur[11] = message.data[6]+((unsigned int) message.data[7] << 8);
                break;
            case 0x652:
                Mcan_count = 0;
                mpcur[12] = message.data[0]+((unsigned int) message.data[1] << 8);
                mpcur[13] = message.data[2]+((unsigned int) message.data[3] << 8);
                mpcur[14] = message.data[4]+((unsigned int) message.data[5] << 8);
                break;
                case 0x623:
                Rcan_count = 0;
                rpcur[0] = message.data[0]+((unsigned int) message.data[1] << 8);
                rpcur[1] = message.data[2]+((unsigned int) message.data[3] << 8);
                rpcur[2] = message.data[4]+((unsigned int) message.data[5] << 8);
                rpcur[3] = message.data[6]+((unsigned int) message.data[7] << 8);
                break;
            case 0x633:
                Rcan_count = 0;
                rpcur[4] = message.data[0]+((unsigned int) message.data[1] << 8);
                rpcur[5] = message.data[2]+((unsigned int) message.data[3] << 8);
                rpcur[6] = message.data[4]+((unsigned int) message.data[5] << 8);
                rpcur[7] = message.data[6]+((unsigned int) message.data[7] << 8);
                break;
            case 0x643:
                Rcan_count = 0;
                rpcur[8] = message.data[0]+((unsigned int) message.data[1] << 8);
                rpcur[9] = message.data[2]+((unsigned int) message.data[3] << 8);
                rpcur[10] = message.data[4]+((unsigned int) message.data[5] << 8);
                rpcur[11] = message.data[6]+((unsigned int) message.data[7] << 8);
                break;
            case 0x653:
                Rcan_count = 0;
                rpcur[12] = message.data[0]+((unsigned int) message.data[1] << 8);
                rpcur[13] = message.data[2]+((unsigned int) message.data[3] << 8);
                rpcur[14] = message.data[4]+((unsigned int) message.data[5] << 8);
                break;
            case 0x561:
                Fcan_count = 0;
                fPOUT.BYTES[0] = message.data[0];
                fPOUT.BYTES[1] = message.data[1];
                for (j = 0; j < 4; j++) {//���״̬�ɼ�
                    for (i = 0; i < 4; i++) {
                        fPF[i + 4 * j] = (message.data[j + 2] >> (i * 2))&0x03;
                    }
                }
                break;
            case 0x562:
                Mcan_count = 0;
                mPOUT.BYTES[0] = message.data[0];
                mPOUT.BYTES[1] = message.data[1];
                for (j = 0; j < 4; j++) {
                    for (i = 0; i < 4; i++) {
                        mPF[i + 4 * j] = (message.data[j + 2] >> (i * 2))&0x03;
                    }
                }
                break;
            case 0x563:
                Rcan_count = 0;
                rPOUT.BYTES[0] = message.data[0];
                rPOUT.BYTES[1] = message.data[1];
                for (j = 0; j < 4; j++) {
                    for (i = 0; i < 4; i++) {
                        rPF[i + 4 * j] = (message.data[j + 2] >> (i * 2))&0x03;
                    }
                }
                break;
            case 0x451:
                Fcan_count = 0;
                fSingle_miles = message.data[4]+((unsigned int) message.data[5] << 8);
                break;
            case 0x452:
                Mcan_count = 0;
                mSingle_miles = message.data[4]+((unsigned int) message.data[5] << 8);
                break;
            case 0x453:
                Rcan_count = 0;
                rSingle_miles = message.data[4]+((unsigned int) message.data[5] << 8);
                break;

            default:
                if (message.id == e_address) {
                    if (message.data[0] == 0xC1) {
                        __asm__ volatile ("reset");
                    }
                }
                if (message.id == 0x610) {
                    if (message.data[0] == 0x55) {
                    } else if (message.data[0] == 0x56) {
                        if (message.data[1] == e_address) {
                            e_hm_pulse = message.data[2]+((unsigned int) message.data[3] << 8);
                            EEROM_WriteTotalMiles();
                        }
                    } else if (message.data[0] == 0x59) {
                        if (message.data[1] == e_address) {
                            e_total_miles = (unsigned char) message.data[2]
                                    +((unsigned int) message.data[3] << 8)
                                    +((unsigned long) message.data[4] << 16)
                                    +((unsigned long) message.data[5] << 24);
                            EEROM_WriteTotalMiles();
                        }
                    } else if (message.data[0] == 0x5A) {
                        if (message.data[1] == e_address) {
                            e_single_miles = (unsigned char) message.data[2]
                                    +((unsigned int) message.data[3] << 8);
                            EEROM_WriteSingleMiles();
                        }
                    }
                }
                break;
        }
    }
    C1INTF = 0; /* the individual flag register cleared */
    C1RX0CONbits.RXFUL = 0;
    _C1IF = 0;
}

/*******************�ְ�����*****************/

DM1 CAN_18FECAEF;
unsigned char CAN_18FECAEF_len;
DM1 CAN_18FECA03;
unsigned char CAN_18FECA03_len;
DM1 CAN_18FECAF5;
unsigned char CAN_18FECAF5_len;
DM1 CAN_18FECA00;
unsigned char CAN_18FECA00_len;
CAN_CACHE m_can;
CAN_CACHE n_can;
CAN_CACHE c_can;
CAN_CACHE e_can;

unsigned long SPN; //�ӻ�������ȡ�Ĺ�����
unsigned char FMI;
//unsigned char CM;
//unsigned char OC;
/*******************�ְ�����*****************/

unsigned char moto_voltage; //�����ѹ
unsigned char moto_current; //�������
unsigned char moto_speed; //�綯ת��
unsigned char battle_t; //��ؾ���
unsigned char Inverter_t; //������¶�
unsigned char battle_t_warn; //��ع��±���
unsigned char battle_jueyuan_warn; //��Ե���ͱ���
unsigned char battle_higtv1_warn; //��ѹ���1����
unsigned char battle_higtv2_warn; //��ѹ���2����
unsigned char moto_t_warn; //�������
unsigned char moto_ready; //ready�ź�
unsigned char xudc; //�����쳣
unsigned char moto_warn; //�������

unsigned char BMS_offline_warn; //��ز�����
unsigned char MCU_offline_warn; //���������
unsigned char TCU_offline_warn; //�����䲻����
unsigned char Engine_offline_warn; //������������
unsigned char Engine_wait; //����������
unsigned char EV; //ģʽ
unsigned char Signal_charge; //����ź�
unsigned char BMS_V; //��ص�ѹ
unsigned char BMS_SOC; //���SOC
unsigned char BMS_A; //��ص���

unsigned char mil_lamp_request; //��ɫ��������
unsigned char fail_mode; //���ֱ���
unsigned char mil_buzz_request; //��������
unsigned long hcu_spn; //HCU������
unsigned char hcu_fmi;

unsigned int Speed_rmp; //�����ת��
unsigned char Eng_static_test; //��������̬ת�ٲ���
unsigned char tcu_start_allow; //��������������

unsigned char Current_Gear; //��λ

unsigned char Lamp_status_YELLOW; //������Ƶ�״̬
unsigned char Lamp_status_RED; //��������״̬
unsigned long tcu_spn; //TCU������
unsigned char tcu_fmi;

unsigned long ccu_spn; //CCU������
unsigned char ccu_fmi;

unsigned long ecu_spn; //ECU������
unsigned char ecu_fmi;

unsigned int Max_Cell_Voltage; //��ߵ����ѹ
unsigned char Max_Cell_Voltage_Cell_Number; //��ߵ����ѹλ��
unsigned int  Min_Cell_Voltage; //��͵����ѹ
unsigned char Min_Cell_Voltage_Cell_Number; //��͵����ѹλ��
unsigned char Brake_percent; //̤�忪��

unsigned int  Max_Cell_Temperature; //��ߵ����¶�
unsigned char Max_Cell_Temp_Cell_Number; //��ߵ����¶�λ��
unsigned char Motor_Temperature; //���1�¶�
unsigned char Motor2_Generatrix_Current; //���2����
unsigned char Motor2_Speed; //���ת��
unsigned char Motor2_Inverter_Temperature; //���2������¶�
unsigned char Motor2_Temperature; //���2�¶�

unsigned int  ENG_start_req; //�Ǳ��������
unsigned long mot_work_time; //��������ۻ�ʱ��
unsigned char mot_work_percent; //�������ʱ���
unsigned char DCDC_ctrl; //DCDC״̬
unsigned char hcu_starter_forbid; //�𶯻�����
unsigned char aircompress_enable; //ѹ����
unsigned char Brake_Pedal; //ɲ���ź�
unsigned char Speed_lim_mode; //����ģʽ
unsigned char Accelerator; //����̤��

DATA_BIT OTS_DI; //OTI DI

unsigned char water_temp; //ˮ��

unsigned int Engine_oil_press; //����ѹ��
unsigned char water_level; //ˮλ

unsigned char Wait_start; //�ȴ�����
unsigned char Maintain_warn; //ά������
unsigned char Stop_warn; //ͣ������
unsigned char Engine_warn; //����������

unsigned int EngineSpeed; //������ת��

unsigned char barometric_pressure; //��ѹѹ�� 0.5Kpa               
unsigned char ambient_air_temperature; //��Χ�����¶�
unsigned char air_pressure; //����ѹ�� 0.5Kpa

unsigned long Trip_fuel; //�����ۼ�ȼ������

unsigned int Shunshi_fule; //������˲ʱ����
unsigned int Average_fule; //������ƽ������

unsigned char ABS_lamp; //ABS״̬

unsigned long abs_spn; //ABS������

unsigned int DC_DC_voltage_in; //DCDC�����ѹ
unsigned char DC_DC_voltage_out; //DCDC�����ѹ
unsigned int DC_DC_current_out; //DCDC�������
unsigned char DC_DC_t; //DCDCɢ�����¶�
DATA_BIT DC_DC_code; //DCDC���ϴ���

unsigned int DC_AC_voltage_in; //DCAC�����ѹ
unsigned int DC_AC_voltage_out; //DCAC�����ѹ
unsigned int DC_AC_current_out; //DCAC�������
unsigned char DC_AC_t; //DCACɢ�����¶�
DATA_BIT DC_AC_code; //DCAC���ϴ���

void __attribute__((__interrupt__, auto_psv)) _C2Interrupt(void) {
    unsigned char i = 0;
    CAN_MESSAGE msg;
    if (C2INTFbits.ERRIF) { //���մ���
        C2INTFbits.ERRIF = 0; // ��Ӵ��������
        CAN2_Init();
        C2RX0CONbits.RXFUL = 0;
    }
    if (C2INTFbits.IVRIF) {
        C2INTFbits.IVRIF = 0; //������Ч
        C2RX0CONbits.RXFUL = 0;
    }
    if (C2RX0CONbits.RXFUL) { //������Ч
        CAN2_ReceiveMessage(&msg);
        switch (msg.id) {
            case 0x18EF4AEF://Hybrid_Information_Message
                moto_voltage = msg.data[0];
                moto_current = msg.data[1];
                moto_speed = msg.data[3];
                battle_t = msg.data[4];
                Inverter_t = msg.data[5];
                battle_t_warn = msg.data[6]&0x03;
                battle_jueyuan_warn = (msg.data[6] >> 2)&0x03;
                battle_higtv1_warn = (msg.data[6] >> 4)&0x03;
                battle_higtv2_warn = (msg.data[6] >> 6)&0x03;
                moto_t_warn = msg.data[7]&0x03;
                moto_ready = (msg.data[7] >> 2)&0x03;
                xudc = (msg.data[7] >> 4)&0x03;
                moto_warn = (msg.data[7] >> 6)&0x03;
                break;

            case 0x18EF4BEF://Hybrid_DTC_Message
                BMS_offline_warn = msg.data[0]&0x03;
                MCU_offline_warn = (msg.data[0] >> 2)&0x03;
                TCU_offline_warn = (msg.data[0] >> 4)&0x03;
                Engine_offline_warn = msg.data[1]&0x03;
                Engine_wait = msg.data[2]&0x03;
                EV = (msg.data[2] >> 4)&0x03;
                Signal_charge = (msg.data[2] >> 6)&0x03;
                BMS_V = msg.data[3];
                BMS_SOC = msg.data[4];
                BMS_A = msg.data[7];
                break;

            case 0x18FECAEF:// DM1 HCU
                for (i = 0; i < 6; i++) {
                    CAN_18FECAEF.bData[i] = msg.data[i];
                }
                CAN_18FECAEF_len = 0x06; //m_can.len;
                break;

            case 0x1CECFFEF://TPCM HCU
                if (msg.data[0] == 0x20) {
                    if (msg.data[5] == 0xCA && msg.data[6] == 0xFE) {
                        m_can.len = msg.data[1]+((unsigned int) msg.data[2] << 8);
                        m_can.pack = msg.data[3];
                        m_can.flag = 1; //CAN���տ�ʼ���
                    }
                }
                break;

            case 0x1CEBFFEF://TPDT HCU
                if (m_can.flag == 1) {
                    if (msg.data[0] <= m_can.pack) {
                        unsigned int slen;
                        slen = (msg.data[0] - 1)*7;
                        for (i = 0; i < 7; i++) {
                            m_can.buf[slen + i] = msg.data[i + 1];
                        }
                    }
                    if (msg.data[0] == m_can.pack) {
                        for (i = 0; i < m_can.len; i++) {
                            CAN_18FECAEF.bData[i] = m_can.buf[i];
                        }
                        CAN_18FECAEF_len = m_can.len;
                        m_can.flag = 0; //����ɽ���
                    }
                }
                break;
                //////////////////////////////////////////////////////////////////////////////////            
            case 0x0CF00203://ETC1 TCU
                Speed_rmp = ((unsigned char) msg.data[1]
                        +((unsigned int) msg.data[2] << 8))*0.125; //�����ת��
                Eng_static_test = (msg.data[7] >> 4)&0x03; //��������̬ת�ٲ���
                tcu_start_allow = (msg.data[7] >> 6)&0x03; //��������������
                break;


            case 0x18F00503://ETC2 TCU
                Current_Gear = msg.data[3];
                break;

            case 0x18FECA03:// DM1 TCU
                for (i = 0; i < 6; i++) {
                    CAN_18FECA03.bData[i] = msg.data[i];
                }
                CAN_18FECA03_len = 0x06; //n_can.len;
                Lamp_status_YELLOW = (CAN_18FECA03.bData[0] >> 2)&0x03;
                Lamp_status_RED = (CAN_18FECA03.bData[0] >> 4)&0x03;
                break;

            case 0x1CECFF03://TPCM TCU
                if (msg.data[0] == 0x20) {
                    if (msg.data[5] == 0xCA && msg.data[6] == 0xFE) {
                        n_can.len = msg.data[1]+((unsigned int) msg.data[2] << 8);
                        n_can.pack = msg.data[3];
                        n_can.flag = 1; //CAN���տ�ʼ���
                    }
                }
                break;

            case 0x1CEBFF03://TPDT TCU
                if (n_can.flag == 1) {
                    if (msg.data[0] <= n_can.pack) {
                        unsigned int slen;
                        slen = (msg.data[0] - 1)*7;
                        for (i = 0; i < 7; i++) {
                            n_can.buf[slen + i] = msg.data[i + 1];
                        }
                    }
                    if (msg.data[0] == n_can.pack) {
                        for (i = 0; i < n_can.len; i++) {
                            CAN_18FECA03.bData[i] = n_can.buf[i];
                        }
                        CAN_18FECA03_len = n_can.len;
                        n_can.flag = 0; //����ɽ���
                    }
                }
                break;

            case 0x18FECAF5:// DM1 CCU
                for (i = 0; i < 6; i++) {
                    CAN_18FECAF5.bData[i] = msg.data[i];
                }
                CAN_18FECAF5_len = 0x06; //i_can.len;
                break;

            case 0x18FECA00:// DM1 ECU
                for (i = 0; i < 6; i++) {
                    CAN_18FECA00.bData[i] = msg.data[i];
                }
                CAN_18FECA00_len = 0x06; //e_can.len;

                break;


                ////////////////////////////////////////////////////////////////////////////////          
            case 0x18EF4CEF://BMS Cell voltage Information Message
                Max_Cell_Voltage = (msg.data[0]+((unsigned int) msg.data[1] << 8)) & 0xfff;
                Max_Cell_Voltage_Cell_Number = msg.data[2];
                Min_Cell_Voltage = (msg.data[3]+((unsigned int) msg.data[4] << 8)) & 0xfff;
                Min_Cell_Voltage_Cell_Number = msg.data[5];
                Brake_percent = msg.data[6];
                break;

            case 0x18EF4DEF://Hybrid Temperature Information Message
                Max_Cell_Temperature = msg.data[0]+((unsigned int) msg.data[1] << 8);
                Max_Cell_Temp_Cell_Number = msg.data[2];
                Motor_Temperature = msg.data[3];
                Motor2_Generatrix_Current = msg.data[4];
                Motor2_Speed = msg.data[5];
                Motor2_Inverter_Temperature = msg.data[6];
                Motor2_Temperature = msg.data[7];
                break;

            case 0x18EF0AEF:// Hybrid_ENG_Control
                ENG_start_req = (unsigned char) msg.data[0]
                        +((unsigned int) msg.data[1] << 8);
                mot_work_time = (unsigned char) msg.data[2]
                        +((unsigned int) msg.data[3] << 8)
                        +((unsigned long) msg.data[4] << 16)
                        +((unsigned long) msg.data[5] << 24);
                mot_work_percent = msg.data[6];
                DCDC_ctrl = msg.data[7]&0x03;
                hcu_starter_forbid = (msg.data[7] >> 2)&0x03;
                aircompress_enable = (msg.data[7] >> 4)&0x03;
                Brake_Pedal = (msg.data[7] >> 6)&0x03;
                break;

            case 0x0CF00300://Electronic Engine Controller 2 (EEC2)
                Accelerator = msg.data[1];
                break;


            case 0x189111EF:// OTS_DI
                Zichong = (msg.data[0] >> 1)&0x01;
                Electric = (msg.data[0] >> 2)&0x01;
                Hybrid_forbid = (msg.data[0] >> 6)&0x01;
                Daisujingzhi = (msg.data[0] >> 7)&0x01;
                break;

            case 0x18FEEE00://ˮ��
                water_temp = (unsigned char) msg.data[0];
                break;

            case 0x18FEEF00://ˮλ�ͻ���ѹ��
                Engine_oil_press = (unsigned int) (msg.data[3]);
                water_level = (unsigned char) (msg.data[7]*0.4);
                break;

            case 0x18FEE400://�������ȴ�����
                Wait_start = (unsigned char) (msg.data[3]&0x03);
                //water_level=(unsigned char)(msg.data[7]*0.4);  
                break;

            case 0x18FEF600: //��Χ�������� id==0x18FEF600
                barometric_pressure = msg.data[1]*2; //��ѹѹ�� 0.5Kpa
                ambient_air_temperature = msg.data[2]; //��Χ�����¶�
                air_pressure = msg.data[3]*2; //����ѹ�� 0.5Kpa
                break;

            case 0x0CF00400:
                EngineSpeed = msg.data[3]+((unsigned int) (msg.data[4]) << 8);
                if (EngineSpeed >= 32000) EngineSpeed = 32000; //�����4000RPM
                break;

            case 0x1CFEAF00://����ȼ������
                Trip_fuel = (msg.data[0]
                        +((unsigned int) (msg.data[1]) << 8)
                        +((unsigned long) (msg.data[2]) << 16)
                        +((unsigned long) (msg.data[3]) << 24))*0.5; //�����ۼ�����              
                break;

            case 0x1FDE800://����ȼ�����Ѿ�����
                Shunshi_fule = (msg.data[4]
                        +((unsigned int) (msg.data[5]) << 8))*0.01; //˲ʱ����
                break;

            case 0x1FDE900://����ȼ�����Ѿ�����
                Average_fule = (msg.data[4]
                        +((unsigned int) (msg.data[5]) << 8))*0.01; //ƽ������
                break;

            case 0x18F0010B:
                ABS_lamp = (msg.data[5] >> 4)&0x03; //ABS״̬
                break;

            case 0x18FECA0B://ABS������
                abs_spn = msg.data[2]
                        +((unsigned int) (msg.data[3] << 8))
                        +((unsigned long) (msg.data[4] << 11));
                break;

            case 0x1801A79A://DC/DC�任��
                DC_DC_voltage_in = msg.data[0]
                        +((unsigned int) (msg.data[1] << 8));
                DC_DC_voltage_out = msg.data[2];
                DC_DC_current_out = msg.data[3]
                        +((unsigned int) (msg.data[4] << 8));
                DC_DC_t = msg.data[5];
                DC_DC_code.byte = msg.data[6];
                break;

            case 0x1801A79B://DC/AC�任��
                DC_AC_voltage_in = msg.data[0]
                        +((unsigned int) (msg.data[1] << 8));
                DC_AC_voltage_out = msg.data[2]
                        +((unsigned int) (msg.data[3] << 8));
                DC_AC_current_out = msg.data[4]
                        +((unsigned int) (msg.data[5] << 8));
                DC_AC_t = msg.data[6];
                DC_AC_code.byte = msg.data[7];
                break;
        }
    }
    C2INTF = 0; /* the individual flag register cleared */
    C2RX0CONbits.RXFUL = 0;
    IFS2bits.C2IF = 0;
}

void __attribute__((__interrupt__, auto_psv)) _T1Interrupt(void) {//10ms�ж�һ��
    static unsigned int cnt0 = 0;
    static unsigned int cnt1 = 3;
    static unsigned int cnt2 = 7;
    static unsigned int cnt3 = 9;
    static unsigned int cnt4 = 0;
    static unsigned int cnt5 = 0;
    static unsigned int lpcnt2 = 0, lpcnt1 = 0, lpcount = 0;
    static unsigned int Fcount = 0, Kcount = 0;
    static unsigned int count6 = 0, count8 = 0;
    static float mile = 0;
    //������ʱ3s���

    if (alarm_update_flag1 || alarm_update_flag2) {
        if (count6 >= 300) {//
            count6 = 0;
            alarm_update_flag1 = 0;
            alarm_update_flag2 = 0;
        } else {
            count6++;
        }
    } else {
        count6 = 0;
    }

    if (alarm_update_flag) {
        if (count8 >= 300) {//
            count8 = 0;
            alarm_update_flag = 0;
        } else {
            count8++;
        }
    } else {
        count8 = 0;
    }

    if (delay_cnt > 0) delay_cnt--; //��ʱ������ 

    if (cnt0 >= 4) {//50ms
        cnt0 = 0;
        BCAN_send_mile();
        BCAN_SendCtl();
        if (M_ON_flag && (wake_up3 || wake_up2)) {//wake_up3��0ʱ��M_ON����������0����Ϊ����������ʱ
            LED_Logic();
            LED_Out();
            SYSTME_Logic();
        }
        F50ms = 1;
    } else cnt0++;

    if (cnt1 >= 9) {//100ms
        cnt1 = 0;
        F100ms = 1;
        PCAN_CCVS();
        //�����ۼ����
        if (pSpeed > 0) {//���ٴ���0ʱ���ۼ�
            mile = mile + (float) (pSpeed / 3.6 * 0.1);
            if (mile >= 100.0) {
                mile = 0.0;
                save_flag = 1;
                if (single_miles >= 9999) single_miles = 0;
                else single_miles++;
                if (total_miles >= 9999999) total_miles = 0;
                else total_miles++;
            }
        }
        //CAN�ڵ���ϼ�ʱ3s
        if (Fcan_count >= CAN_TIME)Fcan_count = CAN_TIME;
        else Fcan_count++;
        if (Rcan_count >= CAN_TIME)Rcan_count = CAN_TIME;
        else Rcan_count++;
        if (Mcan_count >= CAN_TIME)Mcan_count = CAN_TIME;
        else Mcan_count++;
        if (Ecan_count >= CAN_TIME)Ecan_count = CAN_TIME;
        else Ecan_count++;
        if (Vcan_count >= CAN_TIME)Vcan_count = CAN_TIME;
        else Vcan_count++;
        if (Bcan_count >= CAN_TIME)Bcan_count = CAN_TIME;
        else Bcan_count++;
        if (Dcan_count >= CAN_TIME)Dcan_count = CAN_TIME;
        else Dcan_count++;
        if (Acan_count >= CAN_TIME)Acan_count = CAN_TIME;
        else Acan_count++;

        if (cnt4 >= 9) {//1s
            cnt4 = 0;
            F1000ms = 1;
            FLASH_1s = !FLASH_1s;
            PCAN_send_mile();
        } else cnt4++;
    } else cnt1++;

    if (Fcount >= 39) {//0.4s
        Fcount = 0;
        F400ms = 1;
        FLASH = !FLASH;
    } else Fcount++;

    if (Kcount >= 29) {//300ms
        Kcount = 0;
        F300ms = 1;
        kFLASH = !kFLASH;
    } else Kcount++;

    if (cnt2 >= 49) {//500ms 
        cnt2 = 0;
        F500ms = 1;
        F500ms_LCD = !F500ms_LCD;
    } else cnt2++;

    if (wake_up3) { //ON�����ж�//����//M_ON�ڵ����һ˲���ʹ������Դ��Ч����M_ON�ڶϵ�ᱣ��300ms���Ӷ�Ӱ�쿪�����ɼ�
        if (cnt3 > 30) M_ON = 1;
        else cnt3++;
    } else {
        if (cnt3 < 1) M_ON = 0;
        else cnt3--;
    }

    if (IN10 && IN6 && (IN7 || IN8) && IN9) { //����ƿ����ǳ������أ�����
        if (cnt5 > 10) rLED_flag = 1;
        else cnt5++;
    } else if ((IN6 && (IN7 || IN8) && IN9) == 0) {
        rLED_flag = 0;
        cnt5 = 0;
    }

    //bit  key_set;  
    if (!KEY_SET && pkey_set && !bkey_set) {
        key_set = 1;
        bkey_set = pkey_set;
    } else {
        if (!KEY_SET == pkey_set) bkey_set = pkey_set;
    }
    pkey_set = KEY_SET;

    //bit  key_up;
    if (!KEY_UP && pkey_up && !bkey_up) {
        key_up = 1; //���ϰ���
        bkey_up = pkey_up;
    } else {
        if (!KEY_UP == pkey_up) bkey_up = pkey_up;
    }
    pkey_up = KEY_UP;

    //bit key_AV;
    if (!KEY_AV && pkey_AV && !bkey_AV) {
        key_AV = 1;
        bkey_AV = pkey_AV;
    } else {
        if (!KEY_AV == pkey_AV)bkey_AV = pkey_AV;
    }
    pkey_AV = KEY_AV;


    if (KEY_SET) {
        if (lpcnt2 >= 300) {//����SET��ť
            //lpcnt2 = 0;
            bkey_set = 1; //����ʱȡ������������
            key_long_set = 1;
        } else lpcnt2++;
    } else {
        lpcnt2 = 0;
    }

    if (KEY_AV && KEY_UP) {
        if (lpcnt1 >= 300) {//��ϰ�ť������AV��UP��ť
            //lpcnt1 = 0;
            bkey_AV = 1; //����ʱȡ������������
            bkey_up = 1; //����ʱȡ������������
            key_duble = 1; //�������ܰ���
        } else lpcnt1++;
    } else {
        lpcnt1 = 0;
    }

    if (KEY_AV && (KEY_UP == 0)) { //���� 2S ���㵥��� ����AV
        if (lpcount >= 200) {
            single_miles = 0;
            lpcount = 0;
            save_flag = 1;
            bkey_AV = 1; //����ʱȡ������������
            lpcount = 100;
        } else lpcount++;
    } else if (lpcount > 0) lpcount--;

    _T1IF = 0;
}
/*
void TIMER4_Init(void) {
    TMR4=0;
    T4CON = 0x0010; // 1��8��Ƶ Fcy/8 16MHZ/8=2MHz
    PR4 = 19999;  //10ms�ж�һ�� 
    _T4IF = 0;
    _T4IE = 1;
    T4CONbits.TON=1;
}

void __attribute__((__interrupt__, auto_psv)) _T2Interrupt(void){
    static unsigned int cnt = 0;
    if (cnt >= 5) {//50ms
        cnt = 0;
        fFreq++;
    }else cnt++;
    
    
    
    
    _T4IF = 0;  
}*/


