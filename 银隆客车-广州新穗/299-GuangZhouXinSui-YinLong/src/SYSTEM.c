#include "SYSTEM.h"
//#include "LOGO.h"
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

unsigned int M_PO11_count = 2000; //��ģ??����?20��??

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

unsigned char fPF[15]; //ǰģ�鹦���������
unsigned char mPF[15]; //�У�����ģ�鹦�ʹ���
unsigned char rPF[15]; //��ģ�鹦���������

unsigned int fpcur[15]; //ǰģ�鹦���������
unsigned int mpcur[15]; //��ģ�鹦���������
unsigned int rpcur[15]; //��ģ�鹦���������

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
            PWR_CTRL_DR = 0;
            PWR_CTRL = 1;
            F_PO6 = FLASH;
            F_PO7 = FLASH;
            M_PO2 = FLASH;
            M_PO15 = FLASH;
            R_PO5 = FLASH;
            R_PO7 = FLASH;
            LED4 = FLASH; //��ת���
            LED8 = FLASH; //��ת��� 
        } else {
            F_PO6 = 0;
            F_PO7 = 0;
            M_PO2 = 0;
            M_PO15 = 0;
            R_PO5 = 0;
            R_PO7 = 0;
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
            F_PO6 = 0;
            F_PO7 = 0;
            M_PO2 = 0;
            M_PO15 = 0;
            R_PO5 = 0;
            R_PO7 = 0;
            LED4 = 0; //��ת���
            LED8 = 0; //��ת���
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
    F_PO4 = (IN6 && IN9); //��ǰ���
    F_PO5 = (IN28 && wake_up2); //������۷�
    F_PO6 = (FLASH && (IN5 || wake_up1)); //��ת���
    F_PO7 = (FLASH && (IN1 || wake_up1)); //��ת���
    F_PO8 = (IN6 && IN4); //ǰ��̤����
    F_PO9 = (IN7); //��Զ�ص�
    F_PO10 = (IN6 && IN9); //��ǰ���
    F_PO11 = (IN7); //��Զ���
    F_PO12 = (IN6 && IN3); //����̤����
    F_PO13 = (IN8); //�����
    F_PO14 = (IN6); //λ�õ�
    F_PO15 = (IN8); //�ҽ���

    M_PO1 = (IN19); //ǰ·�Ƶ�Դ
    M_PO2 = (wake_up2 && IN24); //���2
    M_PO3 = (((DMC_Rpm * 0.5) > 16300) && F5s); //������
    M_PO4 = (fKL6); //�ƶ���
    M_PO5 = ((ADR[1] < 125) || (ADR[2] < 125)); //����ѹ������
    M_PO6 = (IN19); //��·��
    M_PO7 = (wake_up2 && fKL10); //���Ӿ�����
    M_PO8 = (IN9 && IN10); //�����
    M_PO9 = (wake_up2 && IN6 && fKL8); //���е�
    M_PO10 = (IN18); //���ȿ���
    if ((ADR[1] < 125) || (ADR[2] < 125))//�綯�������
        M_PO11 = 1;
    else if (!M_PO11_count)
        M_PO11 = 0;
    M_PO12 = (IN25 || (IN6 && IN4)); //˾����
    M_PO13 = (DMC_Gear==2); //�����Ƶ�Դ
    M_PO14 = (pSpeed < 3); //�űõ�Դ
    M_PO15 = (wake_up2 && IN23); //���1

    /*R_PO1 = (rKL6); //�ƶ���
    R_PO2 = (IN19); //��·��
    R_PO3 = (rLED_flag); //�����       
    R_PO4 = (M_ON); //������������Դ
    R_PO5 = (FLASH && (IN1 || wake_up1)); //��ת���
    R_PO6 = (M_ON); //��ѹ��������Դ
    R_PO7 = (FLASH && (IN5 || wake_up1)); //��ת��
    R_PO8 = IN22; //������
    R_PO9 = (DMC_Gear == 2); //������1
    R_PO10 = IN22; //������
    R_PO11 = (mKH1 && IN6); //ǰ��̤����
    R_PO12 = (IN6); //λ�õ�ʾ�ߵ�
    R_PO13 = (mKL15 && IN6); //����̤����
    R_PO14 = (DMC_Gear == 2); //����������
    R_PO15 = (DMC_Gear == 2); //������2
*/
}

void Count_ADR(void) {
    unsigned int ad = 4096;
    //��ѹ�ʹ������ɼ�  ADR[]��ʵ�ʵĵ�ѹ*1000
    //ADR[1] = (unsigned int) (read_ADR(1) / ad * 5000);
    //ADR[2] = (unsigned int) (read_ADR(2) / ad * 5000);
    //ADR[3] = (unsigned int) (read_ADR(3) / ad * 5000);
    //ADR[4] = (unsigned int) (read_ADR(4) / ad * 5000);
    //ADR[5] = (unsigned int) (read_ADR(5) / ad * 5000);
    //ADR[6] = (unsigned int) (read_ADR(6) / ad * 5000);
    //if (ADR[4] <= 0) ADR[4] = 0;
    //if (ADR[5] <= 0) ADR[5] = 0;
    //���ص�ѹ    
    ADR[0] = (unsigned int) (550.0 * read_VOL() / ad); //ʵ�ʵ�ѹ�Ŵ�10��   //(read_VOL() - 1300)*10 / 76 + 180;
    //�����ʹ������ɼ�  ADR[]��ʵ�ʵ���ֵ
    ADR[1] = (unsigned int) (100.0 * read_ADR(1) / (ad - read_ADR(1))); //((read_ADR(1) / ad * 100) / (1 - read_ADR(1) / ad));
    ADR[2] = (unsigned int) (100.0 * read_ADR(2) / (ad - read_ADR(2)));
    //ADR[3] = (unsigned int) (100.0*read_ADR(3)/(ad-read_ADR(3)));
    //ADR[4] = (unsigned int) (100.0*read_ADR(4)/(ad-read_ADR(4)));
    ADR[5] = (unsigned int) (100.0 * read_ADR(5) / (ad - read_ADR(5)));
    //ADR[6] = (unsigned int) (100.0*read_ADR(6)/(ad-read_ADR(6)));
    //if (ADR[1] > 1000)
    //    ADR[1] = 0;
    //if (ADR[2] > 1000)
    //    ADR[2] = 0;
    if (ADR[3] > 1000)
        ADR[3] = 0;
    if (ADR[4] > 1000)
        ADR[4] = 0;
    if (ADR[5] > 1000)
        ADR[5] = 0;
    if (ADR[6] > 1000)
        ADR[6] = 0;

}

void LED_Logic(void) {
    LED1 = IN4; //ǰ�ſ�ָʾ

    LED2 = IN3; //���ſ�ָʾ
    //LED3 = (DMC_Gear==0 || DMC_Gear==3); //�յ�ָʾ

    //��ת��
    if ((IN1 /*&& M_ON*/) || wake_up1)
        LED4 = FLASH;
    else LED4 = 0;

    //LED5 = (DMC_Gear==1); //ǰ����ָʾ

    LED6 = (((BMS_Status_Flag3 & 0x01) == 1) && (BMS_A * 0.1 > 3240)); //���ָʾ
    //��ת���
    if ((IN5 /*&& M_ON*/) || wake_up1)
        LED8 = FLASH;
    else LED8 = 0;

    if (ADR[1]<116)//��ѹ1���ź�
        LED9 = 1;
    else
        LED9 = 0;

    LED10 = wake_up2; //�ܵ�Դָʾ   

    if (ADR[2]<116) //��ѹ2
        LED11 = 1;
    else
        LED11 = 0;

    LED12 = (((BMS_Status_Flag2 & 0x03) == 1) || ((BMS_Status_Flag2 & 0x03) == 2));//SOC�ͱ���
    
    LED13 = ((DMC_Status == 3 && DMC_Level == 0) || (DMC_Status == 3 && DMC_Level > 0 && FLASH_1s)); //�������

    LED14 = ((((BMS_Status_Flag1 & 0x03) == 1) || ((BMS_Status_Flag1 & 0x03) == 2)) 
            || (((BMS_Status_Flag1 >> 2) & 0x03) == 1) || (((BMS_Status_Flag1 >> 2) & 0x03) == 2)
            || (((BMS_Status_Flag1 >> 4) & 0x03) == 1) || (((BMS_Status_Flag1 >> 4) & 0x03) == 2)
            || (((BMS_Status_Flag1 >> 6) & 0x03) == 1) || (((BMS_Status_Flag1 >> 6) & 0x03) == 2)
            || ((BMS_Status_Flag2 & 0x03) == 1) || ((BMS_Status_Flag2 & 0x03) == 2)
            || (((BMS_Status_Flag2 >> 2) & 0x03) == 1) || (((BMS_Status_Flag2 >> 2) & 0x03) == 2)
            || (((BMS_Status_Flag2 >> 4) & 0x03) == 1) || (((BMS_Status_Flag2 >> 4) & 0x03) == 2)
            || (((BMS_Status_Flag2 >> 6) & 0x03) == 1) || (((BMS_Status_Flag2 >> 6) & 0x03) == 2)); //�������ϵͳ����

    LED15 = IN6; //С��

    //LED16 = (IN33 && M_ON); //���س��

    LED17 = (IN7); //Զ���

    LED18 = (IN26); //��ɲ

    LED19 = (IN9); //ǰ���

    LED20 = (IN9 && IN10); //�����

    //LED21 = (DMC_Gear==2 /*&& M_ON*/);//������

    LED22 = (IN8); //�����

    //LED23 = (IN14 && IN31 && M_ON);//������

    LED24 = (fKL6 /*&& M_ON*/); //ɲ��ָʾ


    //������ Ϊ0ʱ�죬Ϊ1ʱ����   

    if ((pSpeed > 69) || (DMC_Status == 3 && DMC_Level == 0) || mKL2)
        BUZZ = 0;
    else if (!fKL1 || !fKL3 || !fKL4 || !fKL5 || mKL4 || mKL6 
            || (DMC_Status == 3 && DMC_Level == 1)
            || (((BMS_Status_Flag3 >> 5) & 0x01) == 1)
            || (((BMS_Status_Flag3 >> 6) & 0x01) == 1))
        BUZZ = !FLASH_1s;
    else if (IN1 || IN5 || wake_up1)
        BUZZ = !FLASH;
    else BUZZ = 1;
    //���� С�ƿ��رպ� 
    if (IN6) {
        OC1RS = e_backlight;
    } else {
        OC1RS = 0;
    }
    //

    /*if (M_ON) {
        PO1 = 0;
        PO2 = 0;
    } else {
        PO1 = 1;
        PO2 = 1;
    }*/
    PO1 = (M_ON || wake_up1 || wake_up2);

    PO2 = (DMC_Gear == 2);

    //���� 
    /*
    if (((tcu_start_allow == 1)&&(hcu_starter_forbid != 1)) || (ENG_start_req == 21415))
        PO1 = 0;
    else if (hcu_starter_forbid == 1) PO1 = 1;
    else PO1 = 1;
     */
    //if (Brake_Pedal == 0) PO2 = 1;
    //else if (Brake_Pedal == 1) PO2 = 0;
    /**************�ְ��ṹ*******************/
    /*
    mil_lamp_request = (CAN_18FECAEF.bData[0] >> 2)&0x03;
    fail_mode = (CAN_18FECAEF.bData[0] >> 4)&0x03;
    mil_buzz_request = (CAN_18FECAEF.bData[0] >> 6)&0x03;
    Lamp_status_YELLOW = (CAN_18FECA03.bData[0] >> 2)&0x03;
    Lamp_status_RED = (CAN_18FECA03.bData[0] >> 4)&0x03;
     */
    //DM_ECU(1);   
    /* Maintain_warn = (CAN_18FECA00.bData[0] >> 2)&0x03; //ά������warn
     Stop_warn = (CAN_18FECA00.bData[0] >> 4)&0x03; //ͣ������stop
     Engine_warn = (CAN_18FECA00.bData[0] >> 6)&0x03; //����������    
     */
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
    message_POUT.data[6] = ((M_ON && wake_up3) || wake_up2) + (IN14 << 1)+(IN15 << 2)+(IN16 << 3)+(IN21 << 4); //ģ����ο���
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
    message_CCVS.id = 0x0C19A7A1;
    message_CCVS.data[0] = (unsigned char) (M_ON << 6)//ON��
            + (unsigned char) (0 << 5)//ST��
            + (unsigned char) (IN27 << 4)//���ſ��ź�
            + (unsigned char) (IN20 << 3)//ǰ�濪�ź�
            + (unsigned char) (0 << 2)//����ſ��ź�
            + (unsigned char) (rKL8 << 1)//פ���ź�
            + (unsigned char) (rKL10 || rKL12); //��ѹ�ͱ����ź�
    message_CCVS.data[1] = (unsigned char) (IN1 << 7)//��ת��
            + (unsigned char) (IN7 << 6)//Զ���
            + (unsigned char) (IN9 << 5)//ǰ���
            + (unsigned char) (IN5 << 4)//��ת��
            + (unsigned char) (IN33 << 3)//��������
            + (unsigned char) (0 << 2)//������Ԥ��
            + (unsigned char) (IN8 << 1)//�����
            + (unsigned char) (rLED_flag); //�����
    message_CCVS.data[2] = 0xff;
    message_CCVS.data[3] = (unsigned char) (pSpeed * 2);
    message_CCVS.data[4] = 0xff;
    message_CCVS.data[5] = 0xff;
    message_CCVS.data[6] = 0xff;
    message_CCVS.data[7] = 0xff;
    message_CCVS.len = 8;
    message_CCVS.type = 0;
    CAN2_SendMessage(&message_CCVS);
}

void PCAN_DMQTD8(void) {
    CAN_MESSAGE message_DMQTD8;
    message_DMQTD8.id = 0x18AB9B28;
    message_DMQTD8.data[0] = 0xff;
    message_DMQTD8.data[1] = 100;
    message_DMQTD8.data[2] = 100;
    message_DMQTD8.data[3] = 0xff;
    message_DMQTD8.data[4] = 0xff;
    message_DMQTD8.data[5] = 0xff;
    message_DMQTD8.data[6] = 0xff;
    message_DMQTD8.data[7] = 0xff;
    message_DMQTD8.len = 8;
    message_DMQTD8.type = 0;
    CAN2_SendMessage(&message_DMQTD8);
}

void PCAN_DMC(void) {
    CAN_MESSAGE message_DMQTD8;
    message_DMQTD8.id = 0x1882BBAB;
    message_DMQTD8.data[0] = (unsigned char) (IN3 << 3)//���Ź��ź�
            + (unsigned char) (!IN3 << 2)//���ſ��ź�
            + (unsigned char) (IN4 << 1)//ǰ�Ź��ź�
            + (unsigned char) (!IN4); //ǰ�ſ��ź�
    message_DMQTD8.data[1] = (unsigned char) Battery_Temp_H;
    message_DMQTD8.data[2] = (unsigned char) (Battery_Single_L * 0.001 * 50);
    message_DMQTD8.data[3] = (unsigned char) (Battery_Single_H * 0.001 * 50);
    message_DMQTD8.data[4] = 0xff;
    message_DMQTD8.data[5] = 0xff;
    message_DMQTD8.data[6] = 0xff;
    message_DMQTD8.data[7] = 0xff;
    message_DMQTD8.len = 8;
    message_DMQTD8.type = 0;
    CAN2_SendMessage(&message_DMQTD8);
}

void PCAN_send_mile(void) {
    CAN_MESSAGE msg;
    msg.data[0] = (unsigned char) (e_total_miles); //�Ͱ�λ
    msg.data[1] = (unsigned char) (e_total_miles >> 8); //������λ
    msg.data[2] = (unsigned char) (e_total_miles >> 16); //������λ
    msg.data[3] = (unsigned char) (e_total_miles >> 24); //�߰�λ
    msg.data[4] = 0;
    msg.data[5] = 0;
    msg.data[6] = 0;
    msg.data[7] = 0;
    msg.id = 0x0C1AA7A1;
    msg.len = 0x08;
    msg.type = 0x00;
    CAN2_SendMessage(&msg);

}

void PCAN_LCD_BMS(void) {
    CAN_MESSAGE msg;
    msg.data[0] = BMU_Number;
    msg.data[1] = 0xff;
    msg.data[2] = 0xFF;
    msg.data[3] = 0xFF;
    msg.data[4] = 0xFF;
    msg.data[5] = 0xFF;
    msg.data[6] = 0xFF;
    msg.data[7] = 0xFF;
    msg.id = 0x1800F328;
    msg.len = 0x08;
    msg.type = 0x00;
    CAN2_SendMessage(&msg);

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
/*******************�ְ�����*****************/
//���
unsigned char DMC_Status; //�������������״̬
unsigned char DMC_Level; //������������ϼ���
unsigned char DMC_Life; //�������
unsigned int DMC_Torque = 32000; //���ת��
unsigned int DMC_Rpm = 32000; //���ת��
unsigned char DMC_Speed; //����
unsigned char DMC_Gear; //��λ

unsigned int DMC_Voltage; //���������ĸ�ߵ�ѹ
unsigned int DMC_Current = 32000; //���������ĸ�ߵ���
unsigned char DMC_Controller_temp = 40; //����������¶�
unsigned char DMC_Moto_temp = 40; //����¶�
unsigned char DMC_Protect_code; //������������ϴ���
unsigned char DMC_Verison; //����������汾��

unsigned char DMC_Accelerator_percent; //����̤�忪��
unsigned char DMC_Brake_percent; //�ƶ�̤�忪��
unsigned char DMC_Charge; //��ŵ�״̬

//���ÿ�����
unsigned int DMQ_Rpm; //���ÿ��������ת��
unsigned int DMQ_Voltage; //���ÿ�����ĸ�ߵ�ѹ
unsigned char DMQ_Current; //���ÿ��������ĸ�ߵ���
unsigned char DMQ_Controller_temp = 40; //���ÿ������¶�
unsigned char DMQ_Life; //���ÿ���������
unsigned char DMQ_Status; //���ÿ���������״̬

//DCDC
unsigned char DCDC_Status; //DCDC����״̬
unsigned char DCDC_Temp = 40; //DCDCģ���¶�
unsigned int DCDC_Voltage; //DCDC�����ѹ
unsigned int DCDC_Current = 32000; //DCDC�������
unsigned char DCDC_Code; //DCDC���ϴ���
unsigned char DCDC_Verison; //DCDC�汾��

//�ͱÿ�����
unsigned int DMY_Rpm; //�ͱÿ��������ת��
unsigned int DMY_Voltage; //�ͱÿ�����ĸ�ߵ�ѹ
unsigned char DMY_Current; //�ͱÿ��������ĸ�ߵ���
unsigned char DMY_Controller_temp = 40; //�ͱÿ������¶�
unsigned char DMY_Life; //�ͱÿ���������
unsigned char DMY_Status; //�ͱÿ���������״̬

//�յ�
unsigned char Air_Status_Flag1; //�յ�״̬1
unsigned char Air_Status_Flag2; //�յ�״̬2
unsigned char Air_Status_Flag3; //�յ�״̬3
unsigned char Air_Indoor_t = 60; //�����¶�
unsigned char Air_Outdoor_t = 60; //�����¶�
unsigned char Air_Set_t = 60; //�趨


//BMS
unsigned char BMS_Type; //BMS��������
unsigned char Battery_Case_Total_Number; //����������
unsigned char BMS_Unit_Number; //��ع���ϵͳ�ӿص�Ԫ����
unsigned int Battery_Cell_Total_Number; //����ܴ���
unsigned int BMS_Nubmer; //��ع���ϵͳ���

unsigned char Battery_Case_number; //������n
unsigned char Battery_Cell_number; //�����n�ڵ�ش���
unsigned char Battery_Cell_Temp_Number; //������ڵ���¶�̽ͷ����

unsigned int BMS_V; //����ܵ�ѹ
unsigned int BMS_A = 32000; //����ܵ���
unsigned char BMS_SOC; //���SOC
unsigned char BMS_Life; //BMS LIFE
unsigned char BMS_Status_Flag1; //���״̬1
unsigned char BMS_Status_Flag2; //���״̬2

unsigned int Battery_Single_H; //��ص���ߵ�ѹ
unsigned int Battery_Single_L; //��ص���͵�ѹ
unsigned char Battery_Temp_H = 40; //��ص�������¶�
unsigned char Battery_Temp_L = 40; //��ص�������¶�
unsigned char BMS_Status_Flag3; //���״̬3

unsigned char Battery_Single_H_Positon_Case; //��ص���ߵ�ѹ���
unsigned char Battery_Single_H_Positon_Cell; //��ص���ߵ�ѹλ��
unsigned char Battery_Single_L_Positon_Case; //��ص���͵�ѹ���
unsigned char Battery_Single_L_Positon_Cell; //��ص���͵�ѹλ��
unsigned char Battery_Temp_H_Positon_Case; //��ص�����¶����
unsigned char Battery_Temp_H_Positon_Cell; //��ص�����¶�λ��
unsigned char Battery_Temp_L_Positon_Case; //��ص�����¶����
unsigned char Battery_Temp_L_Positon_Cell; //��ص�����¶�λ��

unsigned char BMU_Comm_Status1; //1-8   BMUͨѶ״̬
unsigned char BMU_Comm_Status2; //9-16  BMUͨѶ״̬
unsigned char BMU_Comm_Status3; //17-24 BMUͨѶ״̬

unsigned char BMU_Number = 1; //BMU��

unsigned char Battery_Pack; //��ر��İ���
unsigned int Battery_Voltage[12]; //��ص����ѹ
unsigned int Battery_Temp[12]; //��ص����¶�

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
            case 0x1002FF1e://DMCRD1
                Vcan_count = 0;
                DMC_Status = (msg.data[0] >> 5)&0x07;
                DMC_Level = (msg.data[0] >> 3)&0x03;
                DMC_Life = msg.data[1];
                DMC_Torque = (unsigned char) msg.data[2]+((unsigned int) msg.data[3] << 8);
                DMC_Rpm = (unsigned char) msg.data[4]+((unsigned int) msg.data[5] << 8);
                DMC_Speed = msg.data[6];
                DMC_Gear = msg.data[7]&0x03;
                break;

            case 0x1003FF1e://DMCRD2
                Vcan_count = 0;
                DMC_Voltage = ((unsigned char) msg.data[0]+((unsigned int) msg.data[1] << 8));
                DMC_Current = ((unsigned char) msg.data[2]+((unsigned int) msg.data[3] << 8));
                DMC_Controller_temp = msg.data[4];
                DMC_Moto_temp = msg.data[5];
                DMC_Protect_code = msg.data[6];
                DMC_Verison = msg.data[7];
                break;

            case 0x1004FF1e://DMCRD3
                Vcan_count = 0;
                DMC_Accelerator_percent = msg.data[0];
                DMC_Brake_percent = msg.data[1];
                DMC_Charge = msg.data[2]&0x03;
                break;

            case 0x1429289B://DMQRD1  
                Vcan_count = 0;
                DMQ_Rpm = (unsigned char) msg.data[0]+((unsigned int) msg.data[1] << 8);
                DMQ_Voltage = (unsigned char) msg.data[2]+((unsigned int) msg.data[3] << 8);
                DMQ_Current = msg.data[4];
                DMQ_Controller_temp = msg.data[5];
                DMQ_Life = msg.data[6];
                DMQ_Status = msg.data[7];
                break;

            case 0x1828272B://DCDC  
                Vcan_count = 0;
                DCDC_Status = msg.data[0];
                DCDC_Temp = msg.data[1];
                DCDC_Voltage = (unsigned char) msg.data[2]+((unsigned int) msg.data[3] << 8);
                DCDC_Current = (unsigned char) msg.data[4]+((unsigned int) msg.data[5] << 8);
                DCDC_Code = msg.data[6];
                DCDC_Verison = msg.data[7];
                break;

            case 0x142A2895://DMYTD1  
                Vcan_count = 0;
                DMY_Rpm = (unsigned char) msg.data[0]+((unsigned int) msg.data[1] << 8);
                DMY_Voltage = (unsigned char) msg.data[2]+((unsigned int) msg.data[3] << 8);
                DMY_Current = msg.data[4];
                DMY_Controller_temp = msg.data[5];
                DMY_Life = msg.data[6];
                DMY_Status = msg.data[7];
                break;

            case 0x18AA28F3://BMS_LCD01
                Bcan_count = 0;
                if (msg.data[0] == 1) {
                    Battery_Case_Total_Number = msg.data[1];
                    BMS_Unit_Number = msg.data[2];
                    Battery_Cell_Total_Number = (unsigned char) msg.data[4]+((unsigned int) msg.data[3] << 8);
                    BMS_Nubmer = (unsigned char) msg.data[6]+((unsigned int) msg.data[5] << 8);
                } else if (msg.data[0] == 2) {
                    Battery_Case_number = msg.data[1];
                    Battery_Cell_number = msg.data[2];
                    Battery_Cell_Temp_Number = msg.data[3];
                }
                break;

            case 0x1818D0F3://BMSCAN2_B1
                Bcan_count = 0;
                BMS_V = ((unsigned char) msg.data[1]
                        +((unsigned int) msg.data[0] << 8));
                BMS_A = ((unsigned char) msg.data[3]
                        +((unsigned int) msg.data[2] << 8));
                BMS_SOC = msg.data[4];
                BMS_Life = msg.data[5];
                BMS_Status_Flag1 = msg.data[6];
                BMS_Status_Flag2 = msg.data[7];
                break;

            case 0x1819D0F3://BMSCAN2_B2
                Bcan_count = 0;
                Battery_Single_H = ((unsigned char) msg.data[1]
                        +((unsigned int) msg.data[0] << 8));
                Battery_Single_L = ((unsigned char) msg.data[3]
                        +((unsigned int) msg.data[2] << 8));
                Battery_Temp_H = msg.data[4];
                Battery_Temp_L = msg.data[5];
                BMS_Status_Flag3 = msg.data[6];
                break;

            case 0x181AD0F3://BMSCAN2_B3
                Bcan_count = 0;
                Battery_Single_H_Positon_Case = msg.data[0];
                Battery_Single_H_Positon_Cell = msg.data[1];
                Battery_Single_L_Positon_Case = msg.data[2];
                Battery_Single_L_Positon_Cell = msg.data[3];
                Battery_Temp_H_Positon_Case = msg.data[4];
                Battery_Temp_H_Positon_Cell = msg.data[5];
                Battery_Temp_L_Positon_Case = msg.data[6];
                Battery_Temp_L_Positon_Cell = msg.data[7];
                break;

            case 0x181BD0F3://BMSCAN2_B4
                Bcan_count = 0;
                BMU_Comm_Status1 = msg.data[0];
                BMU_Comm_Status2 = msg.data[1];
                BMU_Comm_Status3 = msg.data[2];
                break;

            case 0x180028F3://BMS_LCD02
                if (msg.data[0] == BMU_Number) {
                    for (i = 0; i < 4; i++) {
                        if (msg.data[1] == i + 1) {
                            Battery_Voltage[i * 3] = ((unsigned char) msg.data[3]
                                    +((unsigned int) msg.data[2] << 8));
                            Battery_Voltage[i * 3 + 1] = ((unsigned char) msg.data[5]
                                    +((unsigned int) msg.data[4] << 8));
                            Battery_Voltage[i * 3 + 2] = ((unsigned char) msg.data[7]
                                    +((unsigned int) msg.data[6] << 8));
                        }
                    }
                } else {
                    for (i = 0; i < 4; i++) {
                        Battery_Voltage[i * 3] = 0xFFFF;
                        Battery_Voltage[i * 3 + 1] = 0xFFFF;
                        Battery_Voltage[i * 3 + 2] = 0xFFFF;
                    }
                }
                break;

            case 0x180028F4://BCTDT1
                if (msg.data[0] == BMU_Number) {
                    for (i = 0; i < 2; i++) {
                        if (msg.data[1] == i + 1) {
                            Battery_Temp[i * 6] = msg.data[2];
                            Battery_Temp[i * 6 + 1] = msg.data[3];
                            Battery_Temp[i * 6 + 2] = msg.data[4];
                            Battery_Temp[i * 6 + 3] = msg.data[5];
                            Battery_Temp[i * 6 + 4] = msg.data[6];
                            Battery_Temp[i * 6 + 5] = msg.data[7];
                        }
                    }
                } else {
                    for (i = 0; i < 2; i++) {
                        Battery_Temp[i * 6] = 0xFF;
                        Battery_Temp[i * 6 + 1] = 0xFF;
                        Battery_Temp[i * 6 + 2] = 0xFF;
                        Battery_Temp[i * 6 + 3] = 0xFF;
                        Battery_Temp[i * 6 + 4] = 0xFF;
                        Battery_Temp[i * 6 + 5] = 0xFF;
                    }
                }
                break;

            case 0x18FFC09E://Air
                Vcan_count = 0;
                Air_Status_Flag1 = msg.data[0];
                Air_Status_Flag2 = msg.data[1];
                Air_Status_Flag3 = msg.data[2];
                Air_Indoor_t = msg.data[3];
                Air_Outdoor_t = msg.data[4];
                Air_Set_t = msg.data[5];
                break;


                /*   
                case 0x18FECA00:// DM1 ECU
                    Ecan_count=0;
                        for (i = 0; i < 6; i++) {
                            CAN_18FECA00.bData[i] = msg.data[i];
                        }
                        CAN_18FECA00_len = 0x06; //e_can.len;               
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
                                    m_can.buf[slen+i] = msg.data[i + 1];
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
                                    n_can.buf[slen+i] = msg.data[i + 1];
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
                        Brake_percent = msg.data[6];
                        break;

                    case 0x18EF4DEF://Hybrid Temperature Information Message
                        Motor_Temperature = msg.data[3];
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

                    case 0x18FEEE00://ˮ��
                        water_temp = (unsigned char) msg.data[0];
                        break;

                    case 0x18FEEF00://ˮλ�ͻ���ѹ��
                        Engine_oil_press = (unsigned int) (msg.data[3]*4);
                        water_level = (unsigned char) (msg.data[7]*0.4);
                        break;

                    case 0x18FEE400://�������ȴ�����
                        Wait_start = (unsigned char) (msg.data[3]&0x03);
                        //water_level=(unsigned char)(msg.data[7]*0.4);  
                        break;

                    case 0x18FEF600: //��Χ�������� id==0x18FEF600
                        //barometric_pressure = msg.data[1]; //��ѹѹ�� 0.5Kpa
                        ambient_air_temperature = msg.data[2]; //��Χ�����¶�
                        //air_pressure = msg.data[3]; //����ѹ�� 0.5Kpa
                        break;
                 */
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
    static unsigned int count6 = 0;
    static unsigned int count7 = 0;
    //static unsigned int count8 = 0;
    static float mile = 0;
    //������ʱ3s���
    F_DISP = 1;
    if (alarm_update_flag == 1) {
        if (count6 >= 300) {//
            count6 = 0;
            alarm_update_flag = 0;
        } else {
            count6++;
        }
    } else {
        count6 = 0;
    }

    if (delay_cnt > 0) delay_cnt--; //��ʱ������ 
    
    //��?20��?����?��Ҫ���SYSTEM_LOGIC,��Ȼ?����?
    if ((((ADR[1] > 153) && (ADR[2] > 153)) && !F_20s_flag)) {
        M_PO11_count = 2000;
    }
    F_20s_flag = ((ADR[1] > 153) && (ADR[2] > 153));
    if ((M_PO11_count > 0)) {
        M_PO11_count--;
    }

    if (cnt0 >= 4) {//50ms
        cnt0 = 0;
        BCAN_send_mile();
        BCAN_SendCtl();
        if (M_ON_flag && (wake_up3 || wake_up2)) {//������main������ᵼ����˸Ƶ���쳣wake_up3��0ʱ��M_ON����������0����Ϊ����������ʱ
            LED_Logic();
            LED_Out();
            SYSTME_Logic();
        }
        F50ms = 1;
    } else cnt0++;

    if (cnt1 >= 9) {//100ms
        cnt1 = 0;
        F100ms = 1;
        //PCAN_CCVS();
        PCAN_LCD_BMS();
        PCAN_DMQTD8();
        PCAN_DMC();
        //�����ۼ����
        if (pSpeed > 0) {//���ٴ���0ʱ���ۼ�
            mile = mile + (float) (pSpeed / 3.6 * 0.1);
            if (mile >= 100.0) {
                mile = 0.0;
                save_flag = 1;
                if (single_miles >= 9999) single_miles = 0;
                else single_miles++;
                if (total_miles >= 99999999) total_miles = 0;
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
            //PCAN_send_mile();
            //���5�룬10����ѭ��
            if (DMC_Rpm * 0.5 < 16300) count7 = 0;
            else count7++;
            
            if ((count7 > 0) && (count7 < 6)) {
                F5s = 1;
            } else if (count7 < 605) {
                F5s = 0;
            }else count7 = 0;   
            //����6�룬10����ѭ������
            /*if (1) count8 = 0;
            else count8++;
            
            if ((count8 > 0) && (count8 < 6)) {
                F_3 = 1;
            } else if (count8 < 605) {
                F_3 = 0;
            }else count8 = 0; 
            */
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
            lpcnt2 = 0;
            bkey_set = 1; //����ʱȡ������������
            key_long_set = 1;
        } else lpcnt2++;
    } else {
        lpcnt2 = 0;
    }

    if (KEY_AV && KEY_UP) {
        if (lpcnt1 >= 300) {//��ϰ�ť������AV��UP��ť
            lpcnt1 = 0;
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
            save_flag = 1;
            bkey_AV = 1; //����ʱȡ������������
            lpcount = 100;
        } else lpcount++;
    } else if (lpcount > 0) lpcount--;

    _T1IF = 0;
}

#define C3_K     512
#define FOUT_DR  TRISFbits.TRISF6
#define FOUT     LATFbits.LATF6
//unsigned char vspeed;    //��λkm/h

void TIM5_Init(void) {
    FOUT_DR = 0;
    FOUT = 0;
    T5CON = 0; //1��1 ��Ƶ   16MHz
    TMR5 = 0;
    PR5 = 15999; //1ms�ж�һ��
    _T5IE = 1;
    T5CONbits.TON = 1;
}

void __attribute__((__interrupt__, auto_psv)) _T5Interrupt(void) { //1ms  
    static unsigned int cnt = 0;
    if (pSpeed > 0) {
        if (cnt < 2) FOUT = 1;
        else FOUT = 0;
        cnt++;

        if (cnt >= (C3_K / pSpeed)) {
            cnt = 0;
        }

    } else {
        cnt = 0;
        FOUT = 0;
    }
    _T5IF = 0;
}

