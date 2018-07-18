#include "SYSTEM.h"
//#include "LOGO.h"
unsigned int delay_cnt;
DATA_BIT gKEY[5];
DATA_BIT gCTL[8]; //�Ǳ����������Ϣ

unsigned int single_miles = 0;
unsigned long total_miles = 0;

unsigned char Fversion;
unsigned char Mversion;
unsigned char Rversion;

unsigned int Fcan_count = 0; //ǰ��ģ��CAN
unsigned int Rcan_count = 0; //����ģ��CAN
unsigned int Mcan_count = 0; //�в�ģ��CAN
unsigned int Ecan_count = 0; //������ECUģ��CAN
unsigned int Vcan_count = 0; //����������VCUģ��CAN
unsigned int Bcan_count = 0; //��ع�����BMSģ��CAN
unsigned int Dcan_count = 0; //ת������DC/ACģ��CAN
unsigned int Acan_count = 0; //�յ�ACģ��CAN
unsigned int NodeCount[NODE_NUMBER] = {}; //�ڵ㳬ʱ����

unsigned int BAT24V_count = 0; //���ص�ѹ������ʱ

unsigned int M_PO11_count = 1000; //���10���ʱ

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

unsigned int ADR[8]; //ģ�����ɼ�   10/15
unsigned int ADV[8]; //ģ�����ɼ� 

DBCM_POUT fPOUT; //ǰģ�鹦�����״̬
DBCM_POUT mPOUT; //�У�����ģ�鹦�����״̬
DBCM_POUT rPOUT; //��ģ�鹦�����״̬

unsigned char fPF[16]; //ǰģ�鹦���������
unsigned char mPF[16]; //�У�����ģ�鹦�ʹ���
unsigned char rPF[16]; //��ģ�鹦���������

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
            M_PO7 = FLASH;
            M_PO9 = FLASH;
            R_PO6 = FLASH;
            R_PO7 = FLASH;
            LED4 = FLASH; //��ת���
            LED8 = FLASH; //��ת��� 
            BUZZ = !FLASH;
            //M_PO14 = 1; //�űõ�Դ
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
            M_PO7 = 0;
            M_PO9 = 0;
            R_PO6 = 0;
            R_PO7 = 0;
            LED4 = 0; //��ת���
            LED8 = 0; //��ת���
            BUZZ = 1;
            __delay_us(100);
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
    TIM5_Init();
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
    Count_ADR();
}

void Count_ADR(void) {
    float ad = 4096;
    //��ѹ�ʹ������ɼ�  ADV[]��ʵ�ʵĵ�ѹ*1000
    //ADV[1] = (unsigned int) (read_ADR(1) / ad * 5000);
    //ADV[2] = (unsigned int) (read_ADR(2) / ad * 5000);
    ADV[3] = (unsigned int) (read_ADR(3) / ad * 5000);
    ADV[4] = (unsigned int) (read_ADR(4) / ad * 5000);
    //ADV[5] = (unsigned int) (read_ADR(5) / ad * 5000);
    //ADV[6] = (unsigned int) (read_ADR(6) / ad * 5000);
    //���ص�ѹ    
    ADR[0] = (unsigned int) (550.0 * read_VOL() / ad); //ʵ�ʵ�ѹ�Ŵ�10��   //(read_VOL() - 1300)*10 / 76 + 180;
    if (ADR[0] >= 220) BAT24V_count = 0;
    //�����ʹ������ɼ�  ADR[]��ʵ�ʵ���ֵ
    //ADR[1] = (unsigned int) (100.0 * read_ADR(1) / (ad - read_ADR(1))); //((read_ADR(1) / ad * 100) / (1 - read_ADR(1) / ad));
    //ADR[2] = (unsigned int) (100.0 * read_ADR(2) / (ad - read_ADR(2)));
    //ADR[3] = (unsigned int) (100.0*read_ADR(3)/(ad-read_ADR(3)));
    //ADR[4] = (unsigned int) (100.0*read_ADR(4)/(ad-read_ADR(4)));
    //ADR[5] = (unsigned int) (100.0 * read_ADR(5) / (ad - read_ADR(5)));
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
    static unsigned char buzz_flag = 1, buzz_run, timer, old_LED2;
    LED1 = mKH1; //ǰ�ſ�ָʾ

    LED2 = mKL15; //���ſ�ָʾ
    //LED3 = (DMC_Gear==0 || DMC_Gear==3); //�յ�ָʾ

    //��ת��
    if (IN1 || wake_up1)
        LED4 = FLASH;
    else LED4 = 0;

    //LED5 = (DMC_Gear==1); //ǰ����ָʾ
    
    LED6 = (((BMS_Status_Flag5 & 0x01) == 1) && LED7); //���״̬

    LED7 = (((BMS_Status_Flag3 & 0x01) == 1)); //���ǹ����
    //��ת���
    if (IN5 || wake_up1)
        LED8 = FLASH;
    else LED8 = 0;

    LED9 = (ADV[3] < 2166); //��ѹ1���ź�

    LED10 = 1; //�ܵ�Դָʾ   

    LED11 = (ADV[4] < 2166); //��ѹ2���ź�

    LED12 = (((BMS_Status_Flag2 & 0x03) == 1) || ((BMS_Status_Flag2 & 0x03) == 2)); //SOC�ͱ���

    LED13 = ((DMC_Status == 3 && DMC_Level == 0) || (DMC_Status == 3 && DMC_Level > 0 && FLASH_1s)); //�������

    LED14 = ((((BMS_Status_Flag1 & 0x03) == 1) || ((BMS_Status_Flag1 & 0x03) == 2))
            || (((BMS_Status_Flag1 >> 2) & 0x03) == 1) || (((BMS_Status_Flag1 >> 2) & 0x03) == 2)
            || (((BMS_Status_Flag1 >> 4) & 0x03) == 1) || (((BMS_Status_Flag1 >> 4) & 0x03) == 2)
            || (((BMS_Status_Flag1 >> 6) & 0x03) == 1) || (((BMS_Status_Flag1 >> 6) & 0x03) == 2)
            || ((BMS_Status_Flag2 & 0x03) == 1) || ((BMS_Status_Flag2 & 0x03) == 2)
            || (((BMS_Status_Flag2 >> 2) & 0x03) == 1) || (((BMS_Status_Flag2 >> 2) & 0x03) == 2)
            || (((BMS_Status_Flag2 >> 4) & 0x03) == 1) || (((BMS_Status_Flag2 >> 4) & 0x03) == 2)
            || (((BMS_Status_Flag2 >> 6) & 0x03) == 1) || (((BMS_Status_Flag2 >> 6) & 0x03) == 2)); //�������ϵͳ����

    LED15 = IN33; //С��

    LED16 = (BAT24V_count == BAT24_TIME); //���ص�ѹ��

    LED17 = (IN34 && !IN35); //Զ���

    LED18 = (rKL2); //��ɲ

    LED19 = (IN9 && IN33); //ǰ���

    LED20 = (IN9 && IN10 && IN33); //�����

    //LED21 = (DMC_Gear==2 /*&& M_ON*/);//������

    LED22 = (IN35 && IN33 && IN34); //�����

    //LED23 = (IN14 && IN31 && M_ON);//������

    LED24 = (rKL6); //ɲ��ָʾ
    
    /////////////////////////
    if (mKL2 && buzz_flag) {
        buzz_flag = 0;
        timer = 64;
    } else if (!LED2 && old_LED2) {
        buzz_flag = 1;
    }
    old_LED2 = LED2;
    
    if (timer > 0)
        timer--;

    if (/*(timer > 108 && timer <= 148) || (timer > 84 && timer <= 104) ||*/(timer > 24 && timer <= 64) || (timer > 0 && timer <= 20))
        buzz_run = 1;
    else
        buzz_run = 0;
    /////////////////////////

    //delay_out[Delay_3s].condition = (mKL2 && !old_mKL2 && !LED2);
    //old_mKL2 = mKL2;
    //������ Ϊ0ʱ�죬Ϊ1ʱ����   
    if ((pSpeed > 69) || (DMC_Status == 3 && DMC_Level == 0) || buzz_run)
        BUZZ = 0;
    //else if(delay_out[Delay_3s].delay_out)
        //BUZZ = F_100ms;
    else if (!fKL4      //��ǰĦ��Ƭ
            || !fKL1    //���Ħ��Ƭ
            || !fKL5    //��ǰĦ��Ƭ
            || !fKL3    //�Һ�Ħ��Ƭ
            || LED9     //ǰ����ѹ����
            || LED11    //������ѹ����
            || mKL4     //Ӧ��������
            //IN30
            || (DMC_Status == 3 && DMC_Level == 1)
            || (((BMS_Status_Flag3 >> 5) & 0x01) == 1)
            || (((BMS_Status_Flag3 >> 6) & 0x01) == 1))
        BUZZ = !FLASH_1s;
    else if (LED4 || LED8 || wake_up1)
        BUZZ = !FLASH;
    else BUZZ = 1;
    
    //���� С�ƿ��رպ� 
    if (LED15) {
        OC1RS = e_backlight;
    } else {
        OC1RS = 0;
    }

}

void SYSTME_Logic(void) {
    // F_PO1 = (IN16 && M_ON); //��ο쵵
    // F_PO2 = (IN14 && M_ON); //�������
    // F_PO3 = (IN21 && M_ON); //��ˮ���
    //F_PO4 = (LED15 && IN9);                     //��ǰ���
    F_PO5 = (IN28 && IN4);                      //������۷�
    F_PO6 = (FLASH && (IN5 || wake_up1));       //��ת���
    F_PO7 = (FLASH && (IN1 || wake_up1));       //��ת���
    F_PO8 = (((DMC_Rpm * 0.5) > 16300) && F5s); //������ 
    F_PO9 = LED17;                              //��Զ�ص�
    //F_PO10 = (LED15 && IN9);                    //��ǰ���
    F_PO11 = LED17;                             //��Զ���
    F_PO12 = (fKL8);                            //���е� 
    F_PO13 = (LED22);                           //�����
    F_PO14 = (LED15);                           //λ�õ�
    F_PO15 = (LED22);                           //�ҽ���
    F_PO16 = 0;                                 //���ŵ���

    M_PO1 = (LED15);                            //λ�õ�
    M_PO2 = (IN4 && IN24);                      //���2
    M_PO3 = ((pSpeed < 3) && IN6 && IN4);       //ǰ�ſ���ŷ�
    M_PO4 = (IN7 && IN4);                       //ǰ�Źص�ŷ�
    M_PO5 = ((pSpeed < 3) && IN11 && IN4);      //���ſ���ŷ�
    M_PO6 = (IN12 && IN4);                      //���Źص�ŷ�
    M_PO7 = (LED4);                             //��ת���
    M_PO8 = (IN9 && IN10 && LED15);             //�����
    M_PO9 = (LED8);                             //��ת���
    //M_PO10 = (wake_up2 && IN18);                //˾������
    M_PO11 = (LED24);                           //�ƶ���
    M_PO12 = (IN4 && IN25);                     //˾����
    M_PO13 = (DMC_Gear == 2);                   //�����Ƶ�Դ
    M_PO14 = (IN4 || wake_up2);                 //A+�ź����
    M_PO15 = (IN4 && IN23);                     //���1
    M_PO16 = 0;                                 //���ŵ���

    R_PO1 = (M_ON);                             //�����Դ
    R_PO2 = (IN4);                              //Ͷ�һ���Դ     
    R_PO3 = (DMC_Gear == 2);                    //�����ź�      
    R_PO4 = (LED19);                            //��ǰ���
    R_PO5 = (M_ON);                             //������
    R_PO6 = (LED8);                             //��ת���
    R_PO7 = (LED4);                             //��ת���
    R_PO8 = (LED19);                            //��ǰ���
    R_PO9 = (LED24);                            //�ƶ��ź�
    R_PO10 = (LED15 && LED1);                    //ǰ��̤����
    //R_PO11 = (mKH1 && IN6); //ǰ��̤����
    R_PO12 = (LED15 && LED2);                   //����̤����
    //R_PO13 = (mKL15 && IN6); //����̤����
    R_PO14 = (LED15);                           //λ�õ�
    R_PO15 = (IN4 || M_ON || rKH1);             //���̵�����Դ
    R_PO16 = 0;
     
}
//ģ��
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

/*void PCAN_CCVS(void) {
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
 */
//����ϵͳ
void PCAN_DMQTD8(void) {
    CAN_MESSAGE message_DMQTD8;
    unsigned char temp = 0;
    message_DMQTD8.id = 0x18AB9B28;
    message_DMQTD8.data[0] = 0;

    if (ADV[3] < 500)
        temp = 0;
    else if (ADV[3] > 4500)
        temp = 120;
    else 
        temp = (ADV[3] - 500) * 3 / 100;
    message_DMQTD8.data[1] = temp; //��ѹ1

    if (ADV[4] < 500)
        temp = 0;
    else if (ADV[4] > 4500)
        temp = 120;
    else 
        temp = (ADV[4] - 500) * 3 / 100;
    message_DMQTD8.data[2] = temp; //��ѹ2
    
    message_DMQTD8.data[3] = 0;
    message_DMQTD8.data[4] = 0;
    message_DMQTD8.data[5] = 0;
    message_DMQTD8.data[6] = 0;
    message_DMQTD8.data[7] = 0;
    message_DMQTD8.len = 8;
    message_DMQTD8.type = 0;
    CAN2_SendMessage(&message_DMQTD8);
}
//���ϵͳ
void PCAN_DMC(void) {
    CAN_MESSAGE message_DMQTD8;
    DATA_BIT CAN_DATA;
    message_DMQTD8.id = 0x1882BBAB;
    CAN_DATA.bit1 = !LED1; //ǰ��״̬
    CAN_DATA.bit2 = LED1;
    CAN_DATA.bit3 = (!LED2 && !fKH1); //����״̬�ͺ����״̬
    CAN_DATA.bit4 = (LED2 || fKH1);
    CAN_DATA.bit5 = IN27; //ǿ���г�����
    CAN_DATA.bit6 = LED18;//��ɲ
    CAN_DATA.bit7 = 1;
    CAN_DATA.bit8 = 1;
    message_DMQTD8.data[0] = CAN_DATA.byte;
    message_DMQTD8.data[1] = (unsigned char) Battery_Temp_H;
    message_DMQTD8.data[2] = (unsigned char) (Battery_Single_L / 20);
    message_DMQTD8.data[3] = (unsigned char) (Battery_Single_H / 20);
    message_DMQTD8.data[4] = 0xff;
    message_DMQTD8.data[5] = 0xff;
    message_DMQTD8.data[6] = 0xff;
    message_DMQTD8.data[7] = 0xff;
    message_DMQTD8.len = 8;
    message_DMQTD8.type = 0;
    CAN2_SendMessage(&message_DMQTD8);
}
/*void PCAN_send_mile(void) {
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
 */

void PCAN_LCD_CANBUS1(void) {
    CAN_MESSAGE msg;
    unsigned long temp = 0;
    temp = (e_total_miles * 0.8);
    msg.data[0] = (unsigned char) (temp); //�Ͱ�λ
    msg.data[1] = (unsigned char) (temp >> 8); //�а�λ
    msg.data[2] = (unsigned char) (temp >> 16); //�߰�λ
    temp = pSpeed * 10;
    msg.data[3] = (unsigned char) (temp);
    msg.data[4] = (unsigned char) (temp >> 8);
    msg.data[5] = 0;
    msg.data[6] = 0;
    msg.data[7] = 0;
    msg.id = 0x18FFA017;
    msg.len = 0x08;
    msg.type = 0x00;
    CAN2_SendMessage(&msg);
}

void PCAN_SEND1(void) {
    CAN_MESSAGE msg;
    unsigned char temp = 0;
    DATA_BIT CAN_DATA;
    
    if (ADV[3] < 500)
        temp = 0;
    else if (ADV[3] > 4500)
        temp = 120;
    else 
        temp = (ADV[3] - 500) * 3 / 100;
    msg.data[0] = temp; //��ѹ1
    
    if (ADV[4] < 500)
        temp = 0;
    else if (ADV[4] > 4500)
        temp = 120;
    else 
        temp = (ADV[4] - 500) * 3 / 100;
    msg.data[1] = temp; //��ѹ2   
    msg.data[2] = 0;
    msg.data[3] = 0;

    CAN_DATA.bit1 = M_ON;            //Կ��ON
    CAN_DATA.bit2 = LED18;           //��ɲ
    CAN_DATA.bit3 = (DMC_Gear == 2); //����
    CAN_DATA.bit4 = 0;               //����
    CAN_DATA.bit5 = 0;               //����
    CAN_DATA.bit6 = 0;               //����
    CAN_DATA.bit7 = fKH1;            //�����
    CAN_DATA.bit8 = 0;               //����
    msg.data[4] = CAN_DATA.byte;

    CAN_DATA.bit1 = 0;                            //����
    CAN_DATA.bit2 = LED16; //���ص�ѹ��
    CAN_DATA.bit3 = ((Fcan_count == CAN_TIME) ||  //�Ǳ�ϵͳ����
                    (Mcan_count == CAN_TIME)); 
    CAN_DATA.bit4 = LED2;                         //����
    CAN_DATA.bit5 = LED1;                         //ǰ��
    CAN_DATA.bit6 = 0;                            //����
    CAN_DATA.bit7 = 0;                            //����
    CAN_DATA.bit8 = 0;                            //����
    msg.data[5] = CAN_DATA.byte;

    msg.data[6] = 0;
    msg.data[7] = 0;
    msg.id = 0x18FFA117;
    msg.len = 0x08;
    msg.type = 0x00;
    CAN2_SendMessage(&msg);
}

void PCAN_SEND3(void) {
    CAN_MESSAGE msg;
    DATA_BIT CAN_DATA;

    CAN_DATA.bit1 = LED20; //�����
    CAN_DATA.bit2 = 0;
    CAN_DATA.bit3 = LED19; //ǰ���
    CAN_DATA.bit4 = 0;
    CAN_DATA.bit5 = LED8;  //��ת��
    CAN_DATA.bit6 = 0;
    CAN_DATA.bit7 = LED4;  //��ת��
    CAN_DATA.bit8 = 0;
    msg.data[0] = CAN_DATA.byte;

    CAN_DATA.bit1 = 0;    //�����ƶ���ѹ�����ź�
    CAN_DATA.bit2 = 0;
    CAN_DATA.bit3 = LED9; //ǰ���ƶ���ѹ�����ź�
    CAN_DATA.bit4 = 0;
    CAN_DATA.bit5 = 0;    //�ƶ������ź�
    CAN_DATA.bit6 = 0;
    CAN_DATA.bit7 = LED24; //�ƶ����ź�
    CAN_DATA.bit8 = 0;
    msg.data[1] = CAN_DATA.byte;

    CAN_DATA.bit1 = LED17; //Զ����ź�
    CAN_DATA.bit2 = 0;
    CAN_DATA.bit3 = 0;     //�������ź�
    CAN_DATA.bit4 = 0; 
    CAN_DATA.bit5 = 0;     //�������ź�
    CAN_DATA.bit6 = 0;
    CAN_DATA.bit7 = LED11; //�����ƶ���ѹ�����ź�
    CAN_DATA.bit8 = 0;
    msg.data[2] = CAN_DATA.byte;

    CAN_DATA.bit1 = mKL4;             //�ű�Ӧ�������ر���
    CAN_DATA.bit2 = 0;
    CAN_DATA.bit3 = wake_up1;         //˫�����ź�
    CAN_DATA.bit4 = 0;
    CAN_DATA.bit5 = LED15;            //λ�õ��ź�
    CAN_DATA.bit6 = 0;
    CAN_DATA.bit7 = LED22;            //������ź�
    CAN_DATA.bit8 = 0;
    msg.data[3] = CAN_DATA.byte;

    CAN_DATA.bit1 = IN36;     //ASR ���ϵ�
    CAN_DATA.bit2 = 0; //
    CAN_DATA.bit3 = IN37;     //ABS ���ϵ�
    CAN_DATA.bit4 = 0;
    CAN_DATA.bit5 = IN4;      //Կ�� ACC ��
    CAN_DATA.bit6 = 0;
    CAN_DATA.bit7 = M_ON;     //Կ�� ON ��
    CAN_DATA.bit8 = 0;
    msg.data[4] = CAN_DATA.byte;

    CAN_DATA.bit1 = 0; //����
    CAN_DATA.bit2 = 0;
    CAN_DATA.bit3 = 0; //��ˮλ����
    CAN_DATA.bit4 = 0;
    CAN_DATA.bit5 = 0; //�յ����Ƶ�Դ
    CAN_DATA.bit6 = 0;
    CAN_DATA.bit7 = 0; //��˪����
    CAN_DATA.bit8 = 0;
    msg.data[5] = CAN_DATA.byte;

    msg.data[6] = 0;
    msg.data[7] = 0;
    msg.id = 0x18FFA217;
    msg.len = 0x08;
    msg.type = 0x00;
    CAN2_SendMessage(&msg);
}
//BMS����
void PCAN_LCD_BMS(void) {
    CAN_MESSAGE msg;
    msg.data[0] = BMU_Number;
    msg.data[1] = 0x01;
    msg.data[2] = 0xFF;
    msg.data[3] = 0xFF;
    msg.data[4] = 0xFF;
    msg.data[5] = 0xFF;
    msg.data[6] = 0xFF;
    msg.data[7] = 0xFF;
    msg.id = 0x1800F328;
    msg.len = 0x08;
    msg.type = 0x00;
    
    if (frmID == 6 || frmID == 7) {
        CAN2_SendMessage(&msg);
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
    msg.data[7] = (unsigned char) pSpeed;
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
    CAN_DATA.bit5 = M_PO13;            //������
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

    CAN_DATA.bit1 = 0;    //ˮ�¸߱���
    CAN_DATA.bit2 = 0;
    CAN_DATA.bit3 = 0;    //ˮλ�ͱ���
    CAN_DATA.bit4 = 0;
    CAN_DATA.bit5 = 0;    //���˱���
    CAN_DATA.bit6 = 0;
    CAN_DATA.bit7 = 0;    //��ѹ����
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
    CAN_DATA.bit3 = 0;     //����������
    CAN_DATA.bit4 = 0;
    CAN_DATA.bit5 = LED2;  //��2��
    CAN_DATA.bit6 = 0;
    CAN_DATA.bit7 = LED1;  //��1��
    CAN_DATA.bit8 = 0;
    msg.data[5] = CAN_DATA.byte;

    CAN_DATA.bit1 = 0;     //����3
    CAN_DATA.bit2 = 0;
    CAN_DATA.bit3 = 0;     //����2
    CAN_DATA.bit4 = 0;
    CAN_DATA.bit5 = 0;     //����1
    CAN_DATA.bit6 = 0;
    CAN_DATA.bit7 = 0;     //������ѡ�� 00���� 01����
    CAN_DATA.bit8 = 0;
    msg.data[6] = CAN_DATA.byte;

    CAN_DATA.bit1 = 0;     //����3
    CAN_DATA.bit2 = 0;
    CAN_DATA.bit3 = 0;     //����2
    CAN_DATA.bit4 = 0;
    CAN_DATA.bit5 = 0;     //����1
    CAN_DATA.bit6 = 0;
    CAN_DATA.bit7 = 0;     //����ѡ�� 00��ͨ������ 01BRT��
    CAN_DATA.bit8 = 0;
    msg.data[7] = CAN_DATA.byte;
    msg.id = 0x18FED925;
    msg.len = 0x08;
    msg.type = 0x00;
    CAN2_SendMessage(&msg);
}
//������
void PCAN_Send_CarNet1(void) {
    CAN_MESSAGE msg;
    DATA_BIT CAN_DATA;

    CAN_DATA.bit1 = LED1;                               //��1
    CAN_DATA.bit2 = 0;
    CAN_DATA.bit3 = LED2;                               //��2
    CAN_DATA.bit4 = 0;
    CAN_DATA.bit5 = 1;                                  //��3
    CAN_DATA.bit6 = 1;
    CAN_DATA.bit7 = 1;                                  //��4
    CAN_DATA.bit8 = 1;
    msg.data[0] = CAN_DATA.byte;

    CAN_DATA.bit1 = IN1;                                //��ת���
    CAN_DATA.bit2 = 0;
    CAN_DATA.bit3 = IN5;                                //��ת���
    CAN_DATA.bit4 = 0;
    CAN_DATA.bit5 = (DMC_Gear == 1);                    //ǰ����
    CAN_DATA.bit6 = 0;
    CAN_DATA.bit7 = (DMC_Gear == 2);                    //������
    CAN_DATA.bit8 = 0;
    msg.data[1] = CAN_DATA.byte;

    CAN_DATA.bit1 = ((DMC_Gear == 0) || (DMC_Gear == 3));//�յ�
    CAN_DATA.bit2 = 0; 
    CAN_DATA.bit3 = LED24;           //ɲ��
    CAN_DATA.bit4 = 0;
    CAN_DATA.bit5 = LED18;           //��ɲ
    CAN_DATA.bit6 = 0;
    CAN_DATA.bit7 = LED17;           //Զ���
    CAN_DATA.bit8 = 0;
    msg.data[2] = CAN_DATA.byte;

    CAN_DATA.bit1 = LED22;           //�����
    CAN_DATA.bit2 = 0;
    CAN_DATA.bit3 = 1;               //����
    CAN_DATA.bit4 = 1;
    CAN_DATA.bit5 = IN37;            //ABS
    CAN_DATA.bit6 = 0;
    CAN_DATA.bit7 = 1;               //������
    CAN_DATA.bit8 = 1;
    msg.data[3] = CAN_DATA.byte;

    CAN_DATA.bit1 = 1;               //���ع���
    CAN_DATA.bit2 = 1;    
    CAN_DATA.bit3 = LED9;            //��ѹ1��
    CAN_DATA.bit4 = 0;
    CAN_DATA.bit5 = LED11;           //��ѹ2��
    CAN_DATA.bit6 = 0;
    CAN_DATA.bit7 = mKL6;            //ˮλ����
    CAN_DATA.bit8 = 0;
    msg.data[4] = CAN_DATA.byte;

    CAN_DATA.bit1 = (DCDC_Code > 0); //DCDC����
    CAN_DATA.bit2 = 0;
    CAN_DATA.bit3 = 1;               //���˱���
    CAN_DATA.bit4 = 1;
    CAN_DATA.bit5 = 1;               //����ѹ������   
    CAN_DATA.bit6 = 1;
    CAN_DATA.bit7 = 1;               //�������ź�
    CAN_DATA.bit8 = 1;
    msg.data[5] = CAN_DATA.byte;

    CAN_DATA.bit1 = wake_up1;        //Σ���ź�
    CAN_DATA.bit2 = 0;
    CAN_DATA.bit3 = IN4;             //ACC
    CAN_DATA.bit4 = 0;
    CAN_DATA.bit5 = M_ON;            //ON
    CAN_DATA.bit6 = 0;
    CAN_DATA.bit7 = rKH1;            //�����ź�
    CAN_DATA.bit8 = 0;
    msg.data[6] = CAN_DATA.byte;

    CAN_DATA.bit1 = 1;              //���״̬
    CAN_DATA.bit2 = !LED6;
    CAN_DATA.bit3 = 0;     
    CAN_DATA.bit4 = 0;
    CAN_DATA.bit5 = 0;              //����ģʽ
    CAN_DATA.bit6 = 0;
    CAN_DATA.bit7 = 0;     
    CAN_DATA.bit8 = 0;
    msg.data[7] = CAN_DATA.byte;
    msg.id = 0x18FF01E6;
    msg.len = 0x08;
    msg.type = 0x00;
    CAN2_SendMessage(&msg);
}

void PCAN_Send_CarNet2(void) {
    CAN_MESSAGE msg;
    unsigned long temp = 0;
    //DATA_BIT CAN_DATA;
    
    if (ADV[3] < 500)
        temp = 0;
    else if (ADV[3] > 3833)
        temp = 250;
    else 
        temp = (ADV[3] - 500) * 0.075;
    msg.data[0] = temp; //��ѹ1
    
    if (ADV[4] < 500)
        temp = 0;
    else if (ADV[4] > 3833)
        temp = 250;
    else 
        temp = (ADV[4] - 500) * 0.075;
    msg.data[1] = temp; //��ѹ2   
    
    msg.data[2] = 0;
    
    msg.data[3] = pSpeed;//����
    
    temp = e_total_miles * 10;
    msg.data[4] = (unsigned char) (temp); //�Ͱ�λ
    msg.data[5] = (unsigned char) (temp >> 8); //������λ
    msg.data[6] = (unsigned char) (temp >> 16); //������λ
    msg.data[7] = (unsigned char) (temp >> 24); //�߰�λ
    msg.id = 0x18FF02E6;
    msg.len = 0x08;
    msg.type = 0x00;
    CAN2_SendMessage(&msg);
}
//��������
void PCAN_Send_ECAS(void) {
    CAN_MESSAGE msg;
    DATA_BIT CAN_DATA;
   
    CAN_DATA.bit1 = 0;
    CAN_DATA.bit2 = 0;
    CAN_DATA.bit3 = 0;
    CAN_DATA.bit4 = 0;
    CAN_DATA.bit5 = mKL7;
    CAN_DATA.bit6 = 0;
    CAN_DATA.bit7 = 1;
    CAN_DATA.bit8 = 0;
    msg.data[0] = CAN_DATA.byte;
    
    if (mKL1) {
        msg.data[1] = 0x66;
    }else if(mKL3){
        msg.data[1] = 0x77;
    }else if(mKL5){
        msg.data[1] = 0x11;
    }else {
        msg.data[1] = 0x00;
    }
    msg.data[2] = 0;
    msg.data[3] = 0;
    msg.data[4] = 0;
    msg.data[5] = 0;
    
    CAN_DATA.bit1 = mKL7;
    CAN_DATA.bit2 = 0;
    CAN_DATA.bit3 = mKL7;
    CAN_DATA.bit4 = 0;
    CAN_DATA.bit5 = 0;
    CAN_DATA.bit6 = 0;
    CAN_DATA.bit7 = 0;
    CAN_DATA.bit8 = 0;
    msg.data[6] = CAN_DATA.byte;
    
    msg.data[7] = 0;
    msg.id = 0x0CD22F27;
    msg.len = 0x08;
    msg.type = 0x00;
    CAN2_SendMessage(&msg);
}

void PCAN_Send_TCO3(void) {
    CAN_MESSAGE msg;
    DATA_BIT CAN_DATA;
   
    CAN_DATA.bit1 = 0;
    CAN_DATA.bit2 = 0;
    CAN_DATA.bit3 = 0;
    CAN_DATA.bit4 = 0;
    CAN_DATA.bit5 = 0;
    CAN_DATA.bit6 = 0;
    CAN_DATA.bit7 = 0;
    CAN_DATA.bit8 = 0;
    msg.data[0] = CAN_DATA.byte;
    
    msg.data[2] = 0;
    msg.data[3] = 0;
    msg.data[4] = 0;
    msg.data[5] = 0;
    
    CAN_DATA.bit1 = 0;
    CAN_DATA.bit2 = 0;
    CAN_DATA.bit3 = 0;
    CAN_DATA.bit4 = 0;
    CAN_DATA.bit5 = 0;
    CAN_DATA.bit6 = 0;
    CAN_DATA.bit7 = 0;
    CAN_DATA.bit8 = 0;
    msg.data[6] = CAN_DATA.byte;
    
    msg.data[7] = pSpeed;
    msg.id = 0x0CFE6CEE;
    msg.len = 0x08;
    msg.type = 0x00;
    CAN2_SendMessage(&msg);
}

void PCAN_Send_DC(void) {
    CAN_MESSAGE msg;
    //DATA_BIT CAN_DATA;
    unsigned int temp;
   
    if (LED1 || LED2)
        temp = 0;
    else if (LED2)
        temp = 1;
    else
        temp = 2;
    msg.data[0] = temp;
    msg.data[1] = 0;
    msg.data[2] = 0;
    msg.data[3] = 0;
    msg.data[4] = 0;
    msg.data[5] = 0;
    msg.data[6] = 0;  
    msg.data[7] = 0;
    msg.id = 0x18FE4EEC;
    msg.len = 0x08;
    msg.type = 0x00;
    CAN2_SendMessage(&msg);
}

void PCAN_Send_EBC1(void) {
    CAN_MESSAGE msg;
    DATA_BIT CAN_DATA;
   
    CAN_DATA.bit1 = IN36;
    CAN_DATA.bit2 = 0;
    CAN_DATA.bit3 = IN36;
    CAN_DATA.bit4 = 0;
    CAN_DATA.bit5 = 0;
    CAN_DATA.bit6 = 0;
    CAN_DATA.bit7 = 0;
    CAN_DATA.bit8 = 0;
    msg.data[0] = CAN_DATA.byte;
    
    msg.data[1] = 0;
    msg.data[2] = 0;
    msg.data[3] = 0;
    msg.data[4] = 0;
    msg.data[5] = 0;
    msg.data[6] = 0;  
    msg.data[7] = 0;
    msg.id = 0x18F0010B;
    msg.len = 0x08;
    msg.type = 0x00;
    CAN2_SendMessage(&msg);
}

char Count_Time(unsigned char condition, //��������
        unsigned int  out_time,           //�������㣬����ʱ��
        unsigned char cycle_en,           //�Ƿ�ѭ��ִ��
        unsigned int  stop_time           //ѭ��ִ��ʱ����Ъʱ��
        ) { 
    static unsigned int temp = 0;
    if (condition) {
        temp = temp > 60000 ? 60000 : temp + 1; //�������ޣ���ֹ���
    } else {
        temp = 0;
    }

    if (temp > 0 && temp < out_time * 100) {
        return 1;
    } else if (!cycle_en) {
        return 0;
    } else if (temp < (out_time + stop_time) * 100) {
        return 0;
    } else {
        temp = 0;
        return 0;     
    }
}

_Delay_Out delay_out[] = {
    {300},
    {500},
    {1000},
    {2000},
    {5000},
    {}
};
//�ӳ����������.delay_condition��ֵ��������.delay_out��״̬
void Delay_Out(void) {
    unsigned char i;
    for (i = 0; delay_out[i].delay_time != 0; i++) {
        if (delay_out[i].condition) {
            delay_out[i].delay_out = 1;
            delay_out[i].Timer = delay_out[i].delay_time;
        } else if (delay_out[i].Timer > 0) {
            delay_out[i].delay_out = 1;
            delay_out[i].Timer--;
        } else
            delay_out[i].delay_out = 0;
    }
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
                Fversion = message.data[6];
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
                Mversion = message.data[6];
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
                Rversion = message.data[6];
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
DM1 CAN_18FECA2F;
unsigned char CAN_18FECA2F_len;
CAN_CACHE m_can;
CAN_CACHE n_can;
CAN_CACHE c_can;
CAN_CACHE e_can;
/*******************�ְ�����*****************/
/*CAN_SIGNAL_TYPE_S CAN_SIGNAL = {
    .ID_1002FF1E.DMC_Torque = 32000,
    .ID_1002FF1E.DMC_Rpm = 32000,
    .ID_1003FF1E.DMC_Controller_temp = 40,
    .ID_1003FF1E.DMC_Moto_temp = 40,
    .ID_1003FF1E.DMC_Current = 32000
};*/

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
unsigned char DMC_GB_Gear; //���굵λ

//���ÿ�����
unsigned int DMQ_Rpm; //���ÿ��������ת��
unsigned int DMQ_Voltage; //���ÿ�����ĸ�ߵ�ѹ
unsigned char DMQ_Current; //���ÿ��������ĸ�ߵ���
unsigned char DMQ_temp = 40; //�����¶�
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
unsigned char Air_Set_t = 60; //�趨�¶�
unsigned char Air_Power; //����

//BMS
unsigned char BMS_Type; //BMS��������
unsigned char Battery_Case_Total_Number; //����������
unsigned char BMS_Unit_Number = 1; //��ع���ϵͳ�ӿص�Ԫ����
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
unsigned char BMS_Status_Flag3 = 0x80; //���״̬3
unsigned char BMS_Status_Flag4; //�̵���״̬

unsigned char Battery_Single_H_Positon_Case; //��ص���ߵ�ѹ���
unsigned char Battery_Single_H_Positon_Cell; //��ص���ߵ�ѹλ��
unsigned char Battery_Single_L_Positon_Case; //��ص���͵�ѹ���
unsigned char Battery_Single_L_Positon_Cell; //��ص���͵�ѹλ��
unsigned char Battery_Temp_H_Positon_Case; //��ص�����¶����
unsigned char Battery_Temp_H_Positon_Cell; //��ص�����¶�λ��
unsigned char Battery_Temp_L_Positon_Case; //��ص�����¶����
unsigned char Battery_Temp_L_Positon_Cell; //��ص�����¶�λ��

DATA_BIT      BMU_Comm_Status[4]; //1-8   BMUͨѶ״̬
/*unsigned char BMU_Comm_Status2; //9-16  BMUͨѶ״̬
unsigned char BMU_Comm_Status3; //17-24 BMUͨѶ״̬
unsigned char BMU_Comm_Status4; //25-32 BMUͨѶ״̬*/

DATA_BIT      BMU_Bala_Status[4]; //1-8   BMU����״̬
/*unsigned char BMU_Bala_Status2; //9-16  BMU����״̬
unsigned char BMU_Bala_Status3; //17-24 BMU����״̬
unsigned char BMU_Bala_Status4; //25-32 BMU����״̬*/


unsigned char DC1positive_Temp = 40; //����ͷDC1+�¶�
unsigned char DC1negative_Temp = 40; //����ͷDC1-�¶�
unsigned char DC2positive_Temp = 40; //����ͷDC2+�¶�
unsigned char DC2negative_Temp = 40; //����ͷDC2-�¶�
unsigned int Ohm_Positive; //������Ե��ֵ 
unsigned int Ohm_Negative; //������Ե��ֵ 

unsigned int Energe_Rest; //ʣ������
unsigned char BMS_Status_Flag5;
unsigned char BMS_Status_Flag6;

unsigned char Battery_Single_H_Positon_Total; //��ߵ����ѹλ�ã�������
unsigned char Battery_Single_L_Positon_Total; //��͵����ѹλ�ã�������
unsigned char Battery_Temp_H_Positon_Total; //��ߵ����¶�λ�ã�������
unsigned char Battery_Temp_L_Positon_Total; //��͵����¶�λ�ã�������
unsigned char Battery_Single_H_Pack; //��ߵ����ѹ����
unsigned char Battery_Single_L_Pack; //��͵����ѹ����
unsigned char Battery_Temp_H_Pack; //��ߵ����¶Ȱ���
unsigned char Battery_Temp_L_Pack; //��͵����¶Ȱ���

unsigned char DC3positive_Temp = 40; //����ͷDC3+�¶�
unsigned char DC3negative_Temp = 40; //����ͷDC3-�¶�
unsigned char DC4positive_Temp = 40; //����ͷDC4+�¶�
unsigned char DC4negative_Temp = 40; //����ͷDC4-�¶�
unsigned char BMS_KtStatus_Flag5; //�̵���״̬5

unsigned char BMU_Number = 1; //BMU��

unsigned char Battery_Pack; //��ر��İ���
unsigned int Battery_Voltage[12]; //��ص����ѹ
unsigned int Battery_Temp[12]; //��ص����¶�

//��ع���ϵͳ������������δ�������Ϣ BMS -LCD03
unsigned int ChargeSet_Times1;
unsigned int ChargeSet_Times2;
unsigned int ChargeSet_Times3;
unsigned int ChargeSet_Times4;

//ECAS��������Э�� 0x0CFE5A2F
_CAN_0x0CFE5A2F CAN_0xCFE5A2F;

void __attribute__((__interrupt__, auto_psv)) _C2Interrupt(void) {
    unsigned char i = 0, temp = 0;
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
                NodeCount[0] = 0;
                DMC_Status = (msg.data[0] >> 5)&0x07;
                DMC_Level = (msg.data[0] >> 3)&0x03;
                DMC_Life = msg.data[1];
                DMC_Torque = (unsigned char) msg.data[2]+((unsigned int) msg.data[3] << 8);
                DMC_Rpm = (unsigned char) msg.data[4]+((unsigned int) msg.data[5] << 8);
                DMC_Speed = msg.data[6];
                DMC_Gear = msg.data[7]&0x03;
                break;

            case 0x1003FF1e://DMCRD2
                NodeCount[0] = 0;
                DMC_Voltage = ((unsigned char) msg.data[0]+((unsigned int) msg.data[1] << 8));
                DMC_Current = ((unsigned char) msg.data[2]+((unsigned int) msg.data[3] << 8));
                DMC_Controller_temp = msg.data[4];
                DMC_Moto_temp = msg.data[5];
                DMC_Protect_code = msg.data[6];
                DMC_Verison = msg.data[7];
                break;

            case 0x1004FF1e://DMCRD3
                NodeCount[0] = 0;
                DMC_Accelerator_percent = msg.data[0];
                DMC_Brake_percent = msg.data[1];
                DMC_Charge = msg.data[2]&0x03;
                DMC_GB_Gear = msg.data[3];
                break;

            case 0x1429289B://DMQRD1  
                NodeCount[1] = 0;
                DMQ_Rpm = (unsigned char) msg.data[0]+((unsigned int) msg.data[1] << 8);
                DMQ_Voltage = (unsigned char) msg.data[2]+((unsigned int) msg.data[3] << 8);
                DMQ_Current = msg.data[4];
                DMQ_temp = msg.data[5];
                DMQ_Life = msg.data[6];
                DMQ_Status = msg.data[7];
                break;

            case 0x142A289B://DMQRD2  
                NodeCount[1] = 0;
                DMQ_Controller_temp = msg.data[0];
                break;

            case 0x1828272B://DCDC  
                NodeCount[2] = 0;
                DCDC_Status = msg.data[0];
                DCDC_Temp = msg.data[1];
                DCDC_Voltage = (unsigned char) msg.data[2]+((unsigned int) msg.data[3] << 8);
                DCDC_Current = (unsigned char) msg.data[4]+((unsigned int) msg.data[5] << 8);
                DCDC_Code = msg.data[6];
                DCDC_Verison = msg.data[7];
                break;

            case 0x142A2895://DMYTD1  
                NodeCount[3] = 0;
                DMY_Rpm = (unsigned char) msg.data[0]+((unsigned int) msg.data[1] << 8);
                DMY_Voltage = (unsigned char) msg.data[2]+((unsigned int) msg.data[3] << 8);
                DMY_Current = msg.data[4];
                DMY_Controller_temp = msg.data[5];
                DMY_Life = msg.data[6];
                DMY_Status = msg.data[7];
                break;

            case 0x18AA28F3://BMS_LCD01
                NodeCount[4] = 0;
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
                NodeCount[4] = 0;
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
                NodeCount[4] = 0;
                Battery_Single_H = ((unsigned char) msg.data[1]
                        +((unsigned int) msg.data[0] << 8));
                Battery_Single_L = ((unsigned char) msg.data[3]
                        +((unsigned int) msg.data[2] << 8));
                Battery_Temp_H = msg.data[4];
                Battery_Temp_L = msg.data[5];
                BMS_Status_Flag3 = msg.data[6];
                BMS_Status_Flag4 = msg.data[7];
                break;

            case 0x181AD0F3://BMSCAN2_B3
                NodeCount[4] = 0;
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
                NodeCount[4] = 0;
                for (i = 0; i < ((BMS_Unit_Number / 8) + 1); i++) {
                    BMU_Comm_Status[i].byte = msg.data[i];
                }
                for (i = 0; i < (BMS_Unit_Number % 8); i++) {
                    temp = (temp << 1) + 1;
                }
                BMU_Comm_Status[BMS_Unit_Number / 8].byte = BMU_Comm_Status[BMS_Unit_Number / 8].byte & temp;
                break;

            case 0x181CD0F3://BMSCAN2_B5
                NodeCount[4] = 0;
                for (i = 0; i < (BMS_Unit_Number / 8) + 1; i++) {
                    BMU_Bala_Status[i].byte = msg.data[i];
                }
                for (i = 0; i < (BMS_Unit_Number % 8); i++) {
                    temp = (temp << 1) + 1;
                }
                BMU_Bala_Status[BMS_Unit_Number / 8].byte = BMU_Bala_Status[BMS_Unit_Number / 8].byte & temp;
                break;

            case 0x181DD0F3://BMSCAN2_B6
                NodeCount[4] = 0;
                DC1positive_Temp = msg.data[0];
                DC1negative_Temp = msg.data[1];
                DC2positive_Temp = msg.data[2];
                DC2negative_Temp = msg.data[3];
                Ohm_Positive = ((unsigned char) msg.data[5]
                        +((unsigned int) msg.data[4] << 8));
                Ohm_Negative = ((unsigned char) msg.data[7]
                        +((unsigned int) msg.data[6] << 8));
                break;

            case 0x181ED0F3://BMSCAN2_B7
                NodeCount[4] = 0;
                Energe_Rest = ((unsigned char) msg.data[1]
                        +((unsigned int) msg.data[0] << 8));
                BMS_Status_Flag5 = msg.data[2];
                BMS_Status_Flag6 = msg.data[3];
                break;

            case 0x181FD0F3://BMSCAN2_B8
                NodeCount[4] = 0;
                Battery_Single_H_Positon_Total = msg.data[0];
                if (Battery_Single_H_Positon_Total > 200) {
                    Battery_Single_H_Positon_Total -= 200;
                }
                Battery_Single_L_Positon_Total = msg.data[1];
                if (Battery_Single_L_Positon_Total > 200) {
                    Battery_Single_L_Positon_Total -= 200;
                }
                Battery_Temp_H_Positon_Total = msg.data[2];
                if (Battery_Temp_H_Positon_Total > 200) {
                    Battery_Temp_H_Positon_Total -= 200;
                }
                Battery_Temp_L_Positon_Total = msg.data[3];
                if (Battery_Temp_L_Positon_Total > 200) {
                    Battery_Temp_L_Positon_Total -= 200;
                }
                Battery_Single_H_Pack = msg.data[4];
                Battery_Single_L_Pack = msg.data[5];
                Battery_Temp_H_Pack = msg.data[6];
                Battery_Temp_L_Pack = msg.data[7];
                break;

            case 0x1820D0F3://BMSCAN2_B9
                NodeCount[4] = 0;
                DC3positive_Temp = msg.data[0];
                DC3negative_Temp = msg.data[1];
                DC4positive_Temp = msg.data[2];
                DC4negative_Temp = msg.data[3];
                BMS_KtStatus_Flag5 = msg.data[7];
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

            case 0x182128F3:
                ChargeSet_Times1 = ((unsigned char) msg.data[1]
                        +((unsigned int) msg.data[0] << 8));
                ChargeSet_Times2 = ((unsigned char) msg.data[3]
                        +((unsigned int) msg.data[2] << 8));
                ChargeSet_Times3 = ((unsigned char) msg.data[5]
                        +((unsigned int) msg.data[4] << 8));
                ChargeSet_Times4 = ((unsigned char) msg.data[7]
                        +((unsigned int) msg.data[6] << 8));
                break;

            case 0x18FFC09E://Air
                //NodeCount[5] = 0;
                Air_Status_Flag1 = msg.data[0];
                Air_Status_Flag2 = msg.data[1];
                Air_Status_Flag3 = msg.data[2];
                Air_Indoor_t = msg.data[3];
                Air_Outdoor_t = msg.data[4];
                Air_Set_t = msg.data[5];
                Air_Power = msg.data[6];
                break;

            case 0xCFE5A2F:
                for (i = 0; i < 8; i++) {
                    CAN_0xCFE5A2F.BYTE[i] = msg.data[i];
                }
                break;

            case 0x18FECA2F:// DM1 ECAS

                for (i = 0; i < 6; i++) {
                    //CAN_18FECA2F.bData[i] = msg.data[i];
                }
                CAN_18FECA2F_len = 0x06; //m_can.len;

                break;

            /*case 0x1CECFF2F://TPCM ECAS
                if (msg.data[0] == 0x20) {
                    if (msg.data[5] == 0xCA && msg.data[6] == 0xFE) {
                        m_can.len = msg.data[1]+((unsigned int) msg.data[2] << 8);
                        m_can.pack = msg.data[3];
                        m_can.flag = 1; //CAN���տ�ʼ���
                    }
                }

                break;

            case 0x1CEBFF2F://TPDT ECAS
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
                            CAN_18FECA2F.bData[i] = m_can.buf[i];
                        }
                        CAN_18FECA2F_len = m_can.len;
                        m_can.flag = 0; //����ɽ���
                    }
                }

                break;*/

                
                
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

static void CAN_DATA_Init(void) {
    if (NodeCount[0] == CAN_TIME) {
        DMC_Speed = 0;
        /*DMC_Status = 0;
        DMC_Level = 0;
        DMC_Life = 0;
        DMC_Torque = 32000;
        DMC_Rpm = 32000;
        DMC_Speed = 0;
        DMC_Gear = 0;
        DMC_Voltage = 0;
        DMC_Current = 32000;
        DMC_Controller_temp = 40;
        DMC_Moto_temp = 40;
        DMC_Protect_code = 0;
        DMC_Verison = 0;
        DMC_Accelerator_percent = 0;
        DMC_Brake_percent = 0;
        DMC_Charge = 0;
        DMC_GB_Gear = 0;*/
    }
    if (NodeCount[1] == CAN_TIME) {
        /*DMQ_Rpm = 0;
        DMQ_Voltage = 0;
        DMQ_Current = 0;
        DMQ_temp = 40;
        DMQ_Controller_temp = 40;
        DMQ_Life = 0;
        DMQ_Status = 0;*/
    }
    if (NodeCount[2] == CAN_TIME) {
        /*DCDC_Status = 0;
        DCDC_Voltage = 0;
        DCDC_Current = 32000;
        DCDC_Temp = 40;
        DCDC_Code = 0;
        DCDC_Verison = 0;*/
    }
    if (NodeCount[3] == CAN_TIME) {
        /*DMY_Rpm = 0;
        DMY_Voltage = 0;
        DMY_Current = 0;
        DMY_Controller_temp = 40;
        DMY_Life = 0;
        DMY_Status = 0;*/
    }
    if (NodeCount[4] == CAN_TIME) {
        /*BMS_Type = 0;
        Battery_Case_Total_Number = 0;
        BMS_Unit_Number = 0;
        Battery_Cell_Total_Number = 0;
        BMS_Nubmer = 0;
        Battery_Case_number = 0;
        Battery_Cell_number = 0;
        Battery_Cell_Temp_Number = 0;
        BMS_V = 0;
        BMS_A = 32000; //����ܵ���
        BMS_SOC = 0;
        BMS_Life = 0;
        BMS_Status_Flag1 = 0;
        BMS_Status_Flag2 = 0;
        Battery_Single_H = 0;
        Battery_Single_L = 0;
        Battery_Temp_H = 0;
        Battery_Temp_L = 0;
        BMS_Status_Flag3 = 0;
        BMS_Status_Flag4 = 0;
        Battery_Single_H_Positon_Case = 0;
        Battery_Single_H_Positon_Cell = 0;
        Battery_Single_L_Positon_Case = 0;
        Battery_Single_L_Positon_Cell = 0;
        Battery_Temp_H_Positon_Case = 0;
        Battery_Temp_H_Positon_Cell = 0;
        Battery_Temp_L_Positon_Case = 0;
        Battery_Temp_L_Positon_Cell = 0;
        DC1positive_Temp = 40; //����ͷDC1+�¶�
        DC1negative_Temp = 40; //����ͷDC1-�¶�
        DC2positive_Temp = 40; //����ͷDC2+�¶�
        DC2negative_Temp = 40; //����ͷDC2-�¶�
        Ohm_Positive = 0; //������Ե��ֵ 
        Ohm_Negative = 0; //������Ե��ֵ 
        Energe_Rest = 0; //ʣ������
        BMS_Status_Flag5 = 0;
        BMS_Status_Flag6 = 0;
        DC3positive_Temp = 40; //����ͷDC3+�¶�
        DC3negative_Temp = 40; //����ͷDC3-�¶�
        DC4positive_Temp = 40; //����ͷDC4+�¶�
        DC4negative_Temp = 40; //����ͷDC4-�¶�
        BMS_KtStatus_Flag5 = 0; //�̵���״̬5
        ChargeSet_Times1 = 0;
        ChargeSet_Times2 = 0;
        ChargeSet_Times3 = 0;
        ChargeSet_Times4 = 0;*/
    }
    /*if (NodeCount[5] == CAN_TIME) {
        Air_Status_Flag1 = 0;
        Air_Status_Flag2 = 0;
        Air_Status_Flag3 = 0;
        Air_Indoor_t = 60;
        Air_Outdoor_t = 60;
        Air_Set_t = 60;
        Air_Power = 0;
    }*/
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
    //static unsigned int can1 = 0, can2 = 0, can3 = 0;
    //static unsigned int count8 = 0;
    static float mile = 0;
    unsigned char i;
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

    Delay_Out();
    
    if (delay_cnt > 0) delay_cnt--; //��ʱ������ 

    //�ӳ�10�����������Ҫ���SYSTEM_LOGIC,��Ȼ�����ӳ�
    if ((ADR[0] < 220) && !F_20s_flag) {
        M_PO11_count = 1000;
    }
    F_20s_flag = (ADR[0] < 220);
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

    /*if (can1 == 0)//100msѭ�����ͱ���
        PCAN_DMC();
    else if (can1 == 1)
        PCAN_Send_TCO1();
    else if (can1 == 2 && (frmID == 6 || frmID == 7))//�ڵ�ؽ���ʱ�ŷ��͵��
        PCAN_LCD_BMS();
    else if (can1 == 3)
        PCAN_Send_TCO2();
    else if (can1 == 4)
        PCAN_DMQTD8();
    else if (can1 == 6)
        PCAN_SEND1();
    if (can1 >= 9)
        can1 = 0;
    else can1++;

    if (can2 == 5)//500msѭ�����ͱ���
        PCAN_LCD_CANBUS1();
    else if (can2 == 7)
        PCAN_SEND3();
    if (can2 >= 49)
        can2 = 0;
    else can2++;*/
    
    TaskRemarks();

    if (cnt1 >= 9) {//100ms
        cnt1 = 0;
        F100ms = 1;
        F_100ms = !F_100ms;
        //PCAN_CCVS();        
        //PCAN_DMQTD8();       
        //PCAN_SEND1();        
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
        /*if (Ecan_count >= CAN_TIME)Ecan_count = CAN_TIME;
        else Ecan_count++;
        if (Vcan_count >= CAN_TIME)Vcan_count = CAN_TIME;
        else Vcan_count++;
        if (Bcan_count >= CAN_TIME)Bcan_count = CAN_TIME;
        else Bcan_count++;
        if (Dcan_count >= CAN_TIME)Dcan_count = CAN_TIME;
        else Dcan_count++;
        if (Acan_count >= CAN_TIME)Acan_count = CAN_TIME;
        else Acan_count++;*/
        BAT24V_count = BAT24V_count >= BAT24_TIME ? BAT24_TIME : BAT24V_count + 1;
        for (i = 0; i < NODE_NUMBER; i++) {
            NodeCount[i] = NodeCount[i] >= CAN_TIME ? CAN_TIME : NodeCount[i] + 1;
            if (NodeCount[i] == CAN_TIME) {
                CAN_DATA_Init();
            }
        }      

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
            } else count7 = 0;
           
            //F5s = Count_Time(1, DMC_Rpm * 0.5 > 16300, 5, 1, 600);
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

    if (IN10 && LED15 && (LED17 || LED22) && IN9) { //����ƿ����ǳ������أ�����
        if (cnt5 > 10) rLED_flag = 1;
        else cnt5++;
    } else if ((LED15 && (LED17 || LED22) && IN9) == 0) {
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
        if (lpcnt1 >= 200) {//��ϰ�ť������AV��UP��ť
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
            lpcount = 0;
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
    
    TaskProcess();
    
    _T5IF = 0;
}

TASK_COMPONENTS TaskComps[] = {
    {0, 10, 10, PCAN_DMC},
    {0, 10, 10, PCAN_Send_TCO1},
    {0, 10, 10, PCAN_LCD_BMS},
    {0, 10, 10, PCAN_Send_TCO2},
    {0, 10, 10, PCAN_DMQTD8},
    {0, 10, 10, PCAN_SEND1},
    {0, 50, 50, PCAN_LCD_CANBUS1},
    {0, 50, 50, PCAN_SEND3}, 
    {0, 100, 100, PCAN_Send_CarNet1}, 
    {0, 100, 100, PCAN_Send_CarNet2}, 
    {0, 10, 10, PCAN_Send_ECAS}, 
    {0, 10, 10, PCAN_Send_TCO3}, 
    {0, 10, 10, PCAN_Send_DC}, 
    {0, 10, 10, PCAN_Send_EBC1}, 
    {0, 0, 0, NULL}
};
/**************************************************************************************
 * FunctionName   : TaskRemarks()
 * Description    : �����־����
 * EntryParameter : None
 * ReturnValue    : None
 **************************************************************************************/
void TaskRemarks(void) {
    unsigned char i;
    for (i = 0; TaskComps[i].TaskHook != NULL; i++) // �������ʱ�䴦��
    {
        if (TaskComps[i].Timer) // ʱ�䲻Ϊ0
        {
            TaskComps[i].Timer--; // ��ȥһ������
        }
        if (TaskComps[i].Timer == 0) // ʱ�������
        {
            if (TaskComps[i].Run == 0) {
                TaskComps[i].Timer = TaskComps[i].ItvTime; // �ָ���ʱ��ֵ��������һ��
                TaskComps[i].Run = 1; // �����������
            }
        }
    }
}

/**************************************************************************************
 * FunctionName   : TaskProcess()
 * Description    : ������
 * EntryParameter : None
 * ReturnValue    : None
 **************************************************************************************/
void TaskProcess(void) {
    unsigned char i = 0;
    static unsigned char Flag = 0, poll_time = 0;
    //������,����������ȡ����poll_time * ����ʱ����
    for (i = 0; TaskComps[i].TaskHook != NULL; i++) { // �������ʱ�䴦��
        if (TaskComps[i].Run && Flag) // ʱ�䲻Ϊ0
        {
            TaskComps[i].TaskHook(); // ��������
            TaskComps[i].Run = 0; // ��־��0 
            Flag = 0;
        }
    }

    if (poll_time >= 4) {
        poll_time = 0;
        Flag = 1;
    } else if (!Flag) {
        poll_time++;
    }

    //������ÿ��ѭ��ִֻ��һ������
    /*if (TaskComps[i].TaskHook != NULL) // �������ʱ�䴦��
    {
        if (TaskComps[i].Run) // ʱ�䲻Ϊ0
        {
            TaskComps[i].TaskHook(); // ��������
            TaskComps[i].Run = 0; // ��־��0 
        }
        i++;
    }
    if(TaskComps[i].TaskHook == NULL){
        i = 0;
    }*/
}
