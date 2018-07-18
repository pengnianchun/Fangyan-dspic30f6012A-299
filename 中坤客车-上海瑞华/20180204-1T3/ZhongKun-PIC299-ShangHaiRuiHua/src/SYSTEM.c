#include "SYSTEM.h"
#include "LOGO.h"
unsigned char delay_cnt;
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
unsigned int BAT24V_count = 0; //���ص�ѹ������ʱ
unsigned int Tcan_count = 0; //̥ѹCAN

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
unsigned int ADV[8]; //�Ǳ�ģ���źŲɼ�ֵ 

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
            M_PO2 = FLASH;
            M_PO15 = FLASH;
            R_PO5 = FLASH;
            R_PO7 = FLASH;
            LED4 = FLASH; //��ת���
            LED8 = FLASH; //��ת��� 
            BUZZ = !FLASH;
        } else {
            F_PO6 = 0;
            F_PO7 = 0;
            M_PO2 = 0;
            M_PO15 = 0;
            R_PO5 = 0;
            R_PO7 = 0;
            LED4 = 0; //��ת���
            LED8 = 0; //��ת��� 
            BUZZ = 1;
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
            BCAN_SendCtl(); //�ж����BCAN����50ms����һ�Σ�����������������״̬�������Ѿ�����
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
    TIM5_Init(); //Ƶ�������ʼ��
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
    F_PO5 = ((BMS_SOC > 30) && IN23); //�յ�����Դ
    F_PO6 = (FLASH && (IN5 || wake_up1)); //��ת���
    F_PO7 = (FLASH && (IN1 || wake_up1)); //��ת���
    F_PO8 = LED2; //���ſ��ź���� 
    F_PO9 = LED17; //��Զ�ص�
    F_PO10 = (IN6 && IN9); //��ǰ���
    F_PO11 = LED17; //��Զ���
  //F_PO12 = M_ON; //�г���¼�ǵ�Դ
    F_PO12 = ((pSpeed>2)&&(pSpeed<10));//pSpeed>0 && ���ٵ���10km ���ⲿ����������죬���˾�ʾ����
    F_PO13 = (IN8); //�����
    F_PO14 = (IN6); //λ�õ�
    F_PO15 = (IN8); //�ҽ���

    M_PO1 = (IN12); //�Ķ���1
    M_PO2 = (FLASH && (IN5 || wake_up1)); //��ת���
    M_PO3 = (IN11); //�ڶ���
    M_PO4 = (rKL6); //�ƶ���
    M_PO5 = (IN20 && (pSpeed <= 5)); //ǰ�ſ���ŷ�
    M_PO6 = (IN13); //���ӿ���
    M_PO7 = (IN28); //ǰ�Źص�ŷ�
    M_PO8 = (M_ON); //������
    M_PO9 = (IN27 && (pSpeed <= 5)); //���ſ���ŷ�
      M_PO10 = (IN19); //��·��
    M_PO11 = (IN26); //���Źص�ŷ�
    M_PO12 = (IN12); //�Ķ���2
    M_PO13 = (IN13); //���ӿ���
    M_PO14 = (IN6); //λ�õ�
    M_PO15 = (FLASH && (IN1 || wake_up1)); //��ת���

    R_PO1 = (rKL6); //�ƶ���
      R_PO2 = (IN19); //��·��
    R_PO3 = (LED20); //�����       
      R_PO4 = (M_ON); //������������Դ
    R_PO5 = (FLASH && (IN1 || wake_up1)); //��ת���
    R_PO6 = (M_ON); //��ѹ��������Դ
    R_PO7 = (FLASH && (IN5 || wake_up1)); //��ת��
    R_PO8 = IN22; //������
    R_PO9 = (VCU_Gear == 13); //������1
    R_PO10 = IN22; //������
    R_PO11 = (LED1 && IN6); //ǰ��̤����
    R_PO12 = (IN6); //λ�õ�ʾ�ߵ�
    R_PO13 = (LED2 && IN6); //����̤����
    R_PO14 = (VCU_Gear == 13); //����������
    R_PO15 = (VCU_Gear == 13); //������2

}

void Count_ADR(void) {
    float ad = 4096.0;
    //��ѹ�ʹ������ɼ�  ADR[]��ʵ�ʵĵ�ѹ*1000
    //ADV[1] = (unsigned int) (10*read_ADR(1) / ad*500);
    //ADV[2] = (unsigned int) (10*read_ADR(2) / ad*500);
    ADV[3] = (unsigned int) (10 * read_ADR(3) / ad * 500);
    ADV[4] = (unsigned int) (10 * read_ADR(4) / ad * 500);
    //ADV[5] = (unsigned int) (10*read_ADR(5) / ad*500);
    //ADV[6] = (unsigned int) (10*read_ADR(6) / ad*500);
    //if (ADV[4] <= 0) ADR[4] = 0;
    //if (ADV[5] <= 0) ADR[5] = 0;
    //���ص�ѹ    
    ADV[0] = (unsigned int) (550.0 * read_VOL() / ad); //ʵ�ʵ�ѹ�Ŵ�10��   //(read_VOL() - 1300)*10 / 76 + 180;
    if (ADV[0] >= 220) BAT24V_count = 0;
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
    LED1 = mKH1; //ǰ�ſ�ָʾ

    LED2 = mKL15; //���ſ�ָʾ
    //LED3 = (VCU_Gear==0); //�յ�ָʾ

    //��ת��
    if ((IN1) || wake_up1)
        LED4 = FLASH;
    else LED4 = 0;

    //LED5 = (VCU_Gear==1); //ǰ����ָʾ

    //���ָʾ
    LED6 = (BMS_Mode == 1);
    //����ͷ����
    LED7 = wake_up2;
    //��ת���
    if ((IN5) || wake_up1)
        LED8 = FLASH;
    else LED8 = 0;

    if ((ADV[3]) < 2000)//��ѹ1���ź�
        LED9 = 1;
    else
        LED9 = 0;

    LED10 = 1; //�ܵ�Դָʾ   

    if ((ADV[4]) < 2000) //��ѹ2
        LED11 = 1;
    else
        LED11 = 0;

    LED12 = (BAT_SOC_Fault > 0);

    //LED13 = (TM_Fault.byte > 0 && TM_Fault.byte < 5); //�������

    //LED14 = (BMS_Status == 1); //�������ϵͳ����
    LED14 = 0;
    
    LED15 = IN6; //С��

    LED16 = (BAT24V_count >= BAT24_TIME); //���ص�ѹ��

    LED17 = (IN7 && !IN8); //Զ���

    LED18 = (rKL8); //��ɲ

    LED19 = (IN9 && IN6); //ǰ���

    LED20 = (IN9 && IN6 && IN10); //�����

    //LED21 = (VCU_Gear==2 );//������

    LED22 = IN8; //�����

    //LED23 = (IN14 && IN31 && M_ON);//������

    LED24 = (rKL6 || ELE_BRAKE); //ɲ��ָʾ


    //������ Ϊ0ʱ�죬Ϊ1ʱ����   
    if (pSpeed > 69)
        BUZZ = 0;
    else if (!rKL2 || !rKL4 || (!IN17 && READY) || (IN17 && IN24))// || LED9 || LED11)  || !fKL2 || !fKL4
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

    if (M_ON) {
        PO1 = 0;
        PO2 = 0;
    } else {
        PO1 = 1;
        PO2 = 1;
    }
}

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

/*
void PCAN_METER21(void) {
    CAN_MESSAGE message_METER21;
    message_METER21.id = 0x18FFA117;
    message_METER21.data[0] = (ADR[3] - 500) * 0.04; //ǰ��ѹ
    message_METER21.data[1] = (ADR[4] - 500) * 0.04; //����ѹ    
    message_METER21.data[2] = 0xff;
    message_METER21.data[3] = 0xff;
    message_METER21.data[4] = (unsigned char) (0 << 7)//������
            + (unsigned char) (rKL11 << 6)//�����
            + (unsigned char) (0 << 5)//����
            + (unsigned char) (0 << 4)//����
            + (unsigned char) (0 << 3)//����
            + (unsigned char) ((VCU_Gear == 2) << 2)//�����ź�
            + (unsigned char) (rKL8 << 1)//פ���ź�
            + (unsigned char) (M_ON); //ON��
    message_METER21.data[5] = (unsigned char) (mKH1 << 4)//ǰ�ſ�
            + (unsigned char) ((mKL15 || mKL6 || rKL5) << 3)//���ſ�
            + (unsigned char) (0 << 2)//�Ǳ�ϵͳ����
            + (unsigned char) ((ADR[0] < 160) << 1)//��ѹ���ص�
            + (unsigned char) (0); //���ſ�
    message_METER21.data[6] = 0xff;
    message_METER21.data[7] = 0xff;
    message_METER21.len = 8;
    message_METER21.type = 0;
    CAN2_SendMessage(&message_METER21);
}

void PCAN_METER22(void) {
    CAN_MESSAGE message_METER22;
    unsigned long temp;
    temp = e_total_miles * 0.8;
    message_METER22.id = 0x18FFA017;
    message_METER22.data[0] = (unsigned char) (temp); //�Ͱ�λ
    message_METER22.data[1] = (unsigned char) (temp >> 8); //������λ 
    message_METER22.data[2] = (unsigned char) (temp >> 16); //������λ
    message_METER22.data[3] = (unsigned char) (pSpeed * 10); //���ٵͰ�λ
    message_METER22.data[4] = (unsigned char) ((pSpeed * 10) >> 8); //���ٸ߰�λ
    message_METER22.data[5] = 0xff;
    message_METER22.data[6] = 0xff;
    message_METER22.data[7] = 0xff;
    message_METER22.len = 8;
    message_METER22.type = 0;
    CAN2_SendMessage(&message_METER22);
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

void PCAN_send_req(void) {
    CAN_MESSAGE msg;
    msg.data[0] = 0xff;
    msg.data[1] = (unsigned char) 0x0f
            + (unsigned char) ((ccvs_eng_req & 0x03) << 4)
            +(unsigned char) (0x03 << 6);
    msg.data[2] = 0xFF;
    msg.data[3] = 0xFF;
    msg.data[4] = 0xFF;
    msg.data[5] = 0xFF;
    msg.data[6] = 0xFF;
    msg.data[7] = 0xFF;
    msg.id = 0x18FED917;
    msg.len = 0x08;
    msg.type = 0x00;
    CAN2_SendMessage(&msg);

}
 */
void PCAN_ICU2VCU01(void) {
    CAN_MESSAGE message_ICU2VCU01;
    unsigned int temp;
    DATA_BIT CAN_DATA;
    message_ICU2VCU01.id = 0x1801EF17;

    if (ADV[3] < 500) temp = 0;
    else if (ADV[3] < 3000) temp = (unsigned char)((ADV[3] - 500) * 0.04);
    else temp = 100;
    message_ICU2VCU01.data[0] = temp; //ǰ��ѹ

    if (ADV[4] < 500) temp = 0;
    else if (ADV[4] < 3000) temp = (unsigned char)((ADV[4] - 500) * 0.04);
    else temp = 100;
    message_ICU2VCU01.data[1] = temp; //����ѹ    

    message_ICU2VCU01.data[2] = 0;
    message_ICU2VCU01.data[3] = 0;

    CAN_DATA.bit1 = M_ON; //key on
    CAN_DATA.bit2 = LED18; //���ƶ�
    CAN_DATA.bit3 = (VCU_Gear == 13); //����
    CAN_DATA.bit4 = 0;
    CAN_DATA.bit5 = 0;
    CAN_DATA.bit6 = 0;
    CAN_DATA.bit7 = rKL11; //�����
    CAN_DATA.bit8 = 0;
    message_ICU2VCU01.data[4] = CAN_DATA.byte;

    CAN_DATA.bit1 = LED2; //����
    CAN_DATA.bit2 = LED16; //���ص�����
    CAN_DATA.bit3 = 0;
    CAN_DATA.bit4 = 0;
    CAN_DATA.bit5 = LED1; //ǰ��
    CAN_DATA.bit6 = 0;
    CAN_DATA.bit7 = 0;
    CAN_DATA.bit8 = 0;
    message_ICU2VCU01.data[5] = CAN_DATA.byte;

    message_ICU2VCU01.data[6] = 0;
    message_ICU2VCU01.data[7] = 0;
    message_ICU2VCU01.len = 8;
    message_ICU2VCU01.type = 0;
    CAN2_SendMessage(&message_ICU2VCU01);
}

void PCAN_ICU2VCU02(void) {
    CAN_MESSAGE message_ICU2VCU02;
    unsigned int temp;
    message_ICU2VCU02.id = 0x1802EF17;
    message_ICU2VCU02.data[0] = (unsigned char) (e_total_miles); //�Ͱ�λ
    message_ICU2VCU02.data[1] = (unsigned char) (e_total_miles >> 8); //������λ
    message_ICU2VCU02.data[2] = (unsigned char) (e_total_miles >> 16); //������λ
    message_ICU2VCU02.data[3] = (unsigned char) (e_total_miles >> 24); //�߰�λ
    temp = pSpeed * 10;
    message_ICU2VCU02.data[4] = (temp);
    message_ICU2VCU02.data[5] = (temp >> 8);
    message_ICU2VCU02.data[6] = 0;
    message_ICU2VCU02.data[7] = 0;
    message_ICU2VCU02.len = 8;
    message_ICU2VCU02.type = 0;
    CAN2_SendMessage(&message_ICU2VCU02);
}

void PCAN_Taiya(void){
    CAN_MESSAGE message_ICU2VCU02;
    //unsigned int temp;
    message_ICU2VCU02.id = 0x18FEF403;
    message_ICU2VCU02.data[0] = 0xFF; 
    message_ICU2VCU02.data[1] = 0x88; 
    message_ICU2VCU02.data[2] = 0x88; 
    message_ICU2VCU02.data[3] = 0x00; 
    message_ICU2VCU02.data[4] = 0x00;
    message_ICU2VCU02.data[5] = 0x00;
    message_ICU2VCU02.data[6] = 0x01;
    message_ICU2VCU02.data[7] = 0x01;
    message_ICU2VCU02.len = 8;
    message_ICU2VCU02.type = 0;
    CAN2_SendMessage(&message_ICU2VCU02);
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

void DM_BCU(unsigned char x) {//��������x���������spn��fmi
    BMS_spn = CAN_18FECAF3.bData[2 + 4 * (x - 1)]
            +((unsigned int) CAN_18FECAF3.bData[3 + 4 * (x - 1)] << 8)
            +((unsigned long) (CAN_18FECAF3.bData[4 + 4 * (x - 1)]&0xE0) << 11);
    BMS_fmi = (CAN_18FECAF3.bData[4 + 4 * (x - 1)] & 0x1F);
}

void DM(unsigned char x, DM1 id) {//������id�ĵ�x���������spn��fmi
    hcu_spn = id.bData[2 + 4 * (x - 1)]
            +((unsigned int) id.bData[3 + 4 * (x - 1)] << 8)
            +((unsigned long) (id.bData[4 + 4 * (x - 1)]&0xE0) << 11);
    hcu_fmi = (id.bData[4 + 4 * (x - 1)] & 0x1F);
}*/

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
                if (message.id == 0x888) {
                    if (message.data[0] == 0x88) {
                        if (message.data[1] == 0x88) {
                            timer.hour = message.data[2];
                            timer.minute = message.data[3];
                            timer.year = message.data[4];
                            timer.month = message.data[5];
                            timer.day = message.data[6];
                            DS3231_SetTime(&timer);
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
DM1 CAN_18FECAF3;
unsigned char CAN_18FECAF3_len;
CAN_CACHE m_can;
CAN_CACHE n_can;
CAN_CACHE c_can;
CAN_CACHE e_can;
CAN_CACHE b_can;
unsigned long SPN; //�ӻ�������ȡ�Ĺ�����
unsigned char FMI;
/*******************�ְ�����*****************/
//VCU
unsigned int  VCU_TM_NM = 5000; //TMĿ��Ť��
unsigned int  VCU_TM_RPM = 15000; //TMĿ��ת��

unsigned char VCU_TM_Brake_percent; //�ƶ�̤�忪��
unsigned char VCU_TM_Speed_percent; //����̤�忪��
DATA_BIT VCU_Status_Flag1; //״̬1
unsigned char VCU_Gear; //��λ
DATA_BIT VCU_Mode; //����ģʽ
unsigned char VCU_Life; //����������LIFE
DATA_BIT VCU_Status_Flag2;
unsigned char VCU_Code; //����������
// VCU2TERMINAL_MOTOR01
unsigned char TM_Number; //�������
unsigned char TM_Serial; //������
unsigned char TM_WorkStatus; //TM�������״̬
unsigned char TM_Control_Temp = 40; //TM����������¶�
unsigned int  TM_Feedback_RPM = 20000; //TM�������ת��
unsigned int  TM_Feedback_NM = 20000; //TM�������Ť��
// VCU2TERMINAL_MOTOR02
unsigned char TM_Temp = 40; //TM����¶�
unsigned int  TM_Voltage_DC; //TM���ֱ����ѹ
unsigned int  TM_Current_DC = 10000; //TM���ֱ������
/*
//MCU01
unsigned int  TM_Feedback_RPM=20000;//TM�������ת��
unsigned int  TM_Feedback_NM=10000;//TM�������Ť��
unsigned int  TM_Current_AC;//TM�����������
unsigned char TM_StatusFeedback;//TM���״̬����
unsigned char TM_WorkStatus;//TM�������״̬
unsigned char TM_LIFE;//TM���LIFE
//MCU02
unsigned char TM_Temp=40;//TM����¶�
unsigned char TM_Control_Temp=40;//TM����������¶�
unsigned int  TM_Torque_Limit_Up;//���Ť������
unsigned int  TM_Torque_Limit_Down;//���Ť������
DATA_BIT      TM_Fault;//TM������ϵȼ�
unsigned char TM_Status;//TM���״̬
DATA_BIT      TM_Status_Flag1;//���״̬1
//MCU03
unsigned int  TM_Code;//TM���������
unsigned int  TM_Current_DC=20000;//TM���ֱ������
unsigned int  TM_Voltage_DC;//TM���ֱ����ѹ
 */
//IRM01
unsigned long IRM_Ohm_Positive; //������Ե��ֵ 
unsigned long IRM_Ohm_Negative; //�ܸ���Ե��ֵ 
unsigned char IRM_Fault_Level; //�豸���ϵȼ�
unsigned char IRM_Insulation_Level; //��Ե�ȼ�
unsigned char IRM_Life; //��ԵLIFE

/*unsigned char VCU_Kt; //���Ӵ�����������
unsigned char VCU_ON; //Կ���µ�״̬
unsigned char VCU_Order; //���ϴ�������
unsigned int  VCU_Voltage; //�����������ѹ
 */

unsigned char BMS_Mode; //��س�ŵ�ģʽ
unsigned char BMS_Status; //���״̬
unsigned char BAT_Temp_Average = 40; //���ƽ���¶�
unsigned char BMS_SOC; //SOC
unsigned int  BMS_Current = 32000; //���ϵͳ����
unsigned int  BMS_Voltage; //���ϵͳ���ܵ�ѹ
unsigned char BMS_Kt; //��ѹ�̵���״̬

unsigned char BAT_Temp_H_Limit = 40; //��������ص����¶�
unsigned char BAT_Temp_L_Limit = 40; //��������ص����¶�
unsigned char BMS_SOC_L_Limit; //�������SOCֵ
unsigned int  BAT_Current_Discharge_Limit = 32000; //�������ŵ����
unsigned int  BAT_Current_Charge_Limit = 32000; //������������

unsigned char BAT_Temp_L = 40; //��ص�������¶�
unsigned char BAT_Temp_L_Number; //��ص�����¶����
unsigned char BAT_Temp_L_Case; //��ص�����¶����
unsigned char BAT_Temp_H = 40; //��ص�������¶�
unsigned char BAT_Temp_H_Number; //��ص�����¶����
unsigned char BAT_Temp_H_Case; //��ص�����¶����

unsigned char BAT_Voltage_Fault; //��ѹ����
unsigned char BAT_Single_Fault; //��ѹ����
unsigned char BAT_Temp_Fault; //�¶ȹ���
unsigned char BAT_Insulation_Fault; //��Ե����
unsigned char BAT_Consistency_Fault; //���һ���Թ���
unsigned char BAT_SOC_Fault; //SOC����
unsigned char BAT_Current_Fault; //��������
unsigned char BAT_Lock_Fault; //��ѹ��������
unsigned char BMS_Comm_Fault; //BMSͨѶ����
unsigned char BMS_System_Fault; //BMSϵͳ����

unsigned int  BMS_Ohm; //��Ե��ֵ 
unsigned char BMS_Number; //�����ѹ����
unsigned char BMS_Temp_Number; //�����¶�����
unsigned char BMS_System_Unit; //ϵͳ����
unsigned char BMS_System_Number; //ϵͳ��

unsigned int  BAT_Single_L; //��ص���͵�ѹ
unsigned char BAT_Single_L_Number; //��ص���͵�ѹλ��
unsigned char BAT_Single_L_Case; //��ص���͵�ѹ���

unsigned int  BAT_Single_H; //��ص���͵�ѹ
unsigned char BAT_Single_H_Number; //��ص���͵�ѹλ��
unsigned char BAT_Single_H_Case; //��ص���͵�ѹ���




/*
unsigned char BMS_Mode;//��س�ŵ�ģʽ
unsigned char BMS_Status;//���״̬
unsigned char BMS_Balance_Lock;//��ؾ�������״̬
unsigned char BMS_Fault_Lock;//��������״̬
unsigned char BMS_SOC;//SOC
unsigned char BMS_SOH;//SOH
unsigned char BMS_Ahr;//�������
unsigned int  BMS_Ohm;//���ϵͳ����
unsigned char BMS_Life;//�����ź�

unsigned int  BMS_Voltage;//���ϵͳ���ܵ�ѹ
unsigned int  BMS_OutVoltage;//���ϵͳ�����ѹ
unsigned int  BMS_Current=10000;//���ϵͳ����
unsigned int  BMS_Power=10000;//���ϵͳ����
unsigned char BMS_Temp=40;//�����¶�

unsigned int  BMS_TotalVoltage; //�����ص�ѹ�ܺ�
unsigned int  Battery_Single_H; //��ص���ߵ�ѹ
unsigned int  Battery_Single_L; //��ص���͵�ѹ
unsigned char Battery_Single_H_Number; //��ص���ߵ�ѹλ��
unsigned char Battery_Single_L_Number; //��ص���͵�ѹ���

unsigned int  Battery_Temp_Average=40; //���ƽ���¶�
unsigned int  Battery_Temp_H=40; //��ص�������¶�
unsigned int  Battery_Temp_L=40; //��ص�������¶�
unsigned char Battery_Temp_H_Number; //��ص�����¶����
unsigned char Battery_Temp_L_Number; //��ص�����¶����

unsigned int  Battery_Voltage_H_Limit;//���ϵͳ��ߵ�ѹ����
unsigned int  Battery_Voltage_L_Limit;//���ϵͳ��͵�ѹ����
unsigned int  Battery_Single_Voltage_H_Limit;//��ص�����ߵ�ѹ����
unsigned int  Battery_Single_Voltage_L_Limit;//��ص�����͵�ѹ����
unsigned char Battery_Current_Discharge_Limit;//�������ŵ����
unsigned char Battery_Current_Charge_Limit;//������������

unsigned char BMS_SOC_H_Limit;//�������SOCֵ
unsigned char BMS_SOC_L_Limit;//�������SOCֵ
unsigned char BMS_Power_10s_Discharge_Limit;//10s �������ŵ繦��
unsigned char BMS_Power_10s_Charge_Limit;//10s ��������繦��

unsigned char Battery_Temp_H_Limit=40; //��������ص����¶�
unsigned char Battery_Temp_L_Limit=40; //��������ص����¶�

unsigned long BMS_spn; //BMS������
unsigned char BMS_fmi;
unsigned char BMS_cm;
unsigned char BMS_oc;
 */
unsigned int  BAT_Cell_Voltage[400];
unsigned char BAT_Cell_Temperature[128];

unsigned int  DCDC_Voltage; //DCDC�����ѹ
unsigned int  DCDC_Current; //DCDC�������
unsigned char DCDC_Status; //DCDC����״̬
unsigned char DCDC_Output_Cut; //DCDC ����ж�
unsigned char DCDC_intput_Cut; //DCDC �����ж�
unsigned char DCDC_Fault_Code; //DCDC������
unsigned char DCDC_Level_Fault; //DCDC���ϵȼ�
unsigned char DCDC_Temp_Warn; //DCDC�¶ȱ���
unsigned char DCDC_Fault_Warn; //DCDC���ϱ���
unsigned char DCDC_Temp = 40; //DCDCģ���¶�

unsigned int  OILDCAC_U_Voltage; //DCAC���U��ѹ
unsigned int  OILDCAC_U_Current; //DCAC���U����
unsigned char OILDCAC_Status; //DCAC����״̬
unsigned char OILDCAC_Output_Cut; //DCAC ����ж�
unsigned char OILDCAC_intput_Cut; //DCAC �����ж�
unsigned char OILDCAC_Fault_Code; //DCAC���ϴ���
unsigned char OILDCAC_Level_Fault; //DCAC���ϵȼ�
unsigned char OILDCAC_Temp_Warn; //DCDC�¶ȱ���
unsigned char OILDCAC_Fault_Warn; //DCDC���ϱ���
unsigned char OILDCAC_Temp = 40; //DCACģ���¶�

unsigned int  OILDCAC_V_Voltage; //DCAC���V��ѹ
unsigned int  OILDCAC_V_Current; //DCAC���V����
unsigned int  OILDCAC_W_Voltage; //DCAC���W��ѹ
unsigned int  OILDCAC_W_Current; //DCAC���W����

unsigned int  AIRDCAC_U_Voltage; //DCAC���U��ѹ
unsigned int  AIRDCAC_U_Current; //DCAC���U����
unsigned char AIRDCAC_Status; //DCAC����״̬
unsigned char AIRDCAC_Output_Cut; //DCAC ����ж�
unsigned char AIRDCAC_intput_Cut; //DCAC �����ж�
unsigned char AIRDCAC_Fault_Code; //DCAC���ϴ���
unsigned char AIRDCAC_Level_Fault; //DCAC���ϵȼ�
unsigned char AIRDCAC_Temp_Warn; //DCDC�¶ȱ���
unsigned char AIRDCAC_Fault_Warn; //DCDC���ϱ���
unsigned char AIRDCAC_Temp = 40; //DCACģ���¶�

unsigned int  AIRDCAC_V_Voltage; //DCAC���V��ѹ
unsigned int  AIRDCAC_V_Current; //DCAC���V����
unsigned int  AIRDCAC_W_Voltage; //DCAC���W��ѹ
unsigned int  AIRDCAC_W_Current; //DCAC���W����

DATA_DOUBLE ICS01_Status1; //��ѹ�ɼ�״̬1
DATA_DOUBLE ICS01_Status2; //��ѹ�ɼ�״̬2
DATA_DOUBLE ICS01_Status3; //��ѹ�ɼ�״̬3
DATA_DOUBLE ICS01_Status4; //��ѹ�ɼ�״̬4

unsigned int  ICS01_Voltage_Front; //ǰ�˵�ѹ
unsigned int  ICS01_Voltage_Rear; //��˵�ѹ
unsigned char ICS01_LIFE; //LIFE

//unsigned char TireLocation_LR;                 //��̥λ�ã����ң�
//unsigned char TireLocation_FB;                 //��̥λ�ã�ǰ��
unsigned char TireLocation[4][6];                    //��̥λ��
unsigned char TirePressure[4][6];                    //̥ѹ
unsigned int  TireTemperature[4][6];          //̥��
DATA_DOUBLE   TireFault[4][6];                       //��̥����
unsigned int  TireAirLeakageRate[4][6];              //��ѹ��������
unsigned char TirePressureThresholdDetection[4][6];  //��ѹ��ʾ����
/******************************************/
void __attribute__((__interrupt__, auto_psv)) _C2Interrupt(void) {
    unsigned char i = 0,j = 0;
    unsigned int  temp = 0;
    CAN_MESSAGE msg;
    DATA_DOUBLE CAN_DOUBLE;
    //DATA_BIT CAN_BIT;
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
            case 0x0CFF09EF://VCU12 
                Vcan_count = 0;
                VCU_TM_NM = (unsigned char) msg.data[4]+((unsigned int) msg.data[5] << 8);
                VCU_TM_RPM = (unsigned char) msg.data[6]+((unsigned int) msg.data[7] << 8);
                break;

            case 0x100017EF://VCU2ICU01
                Vcan_count = 0;
                VCU_TM_Speed_percent = (unsigned char) msg.data[0];
                VCU_TM_Brake_percent = (unsigned char) msg.data[1];
                VCU_Status_Flag1.byte = (unsigned char) msg.data[2];
                VCU_Gear = msg.data[3]&0x0F;
                VCU_Mode.byte = msg.data[3] & 0xF0;
                VCU_Life = msg.data[4]&0x0F;
                VCU_Status_Flag2.byte = msg.data[4];
                VCU_Code = msg.data[7];
                break;

            case 0x1801FBEF:
                Vcan_count = 0;
                TM_Number = msg.data[0];
                TM_Serial = msg.data[1];
                TM_WorkStatus = msg.data[2];
                TM_Control_Temp = msg.data[3];
                TM_Feedback_RPM = (unsigned char) msg.data[4]+((unsigned int) msg.data[5] << 8);
                TM_Feedback_NM = (unsigned char) msg.data[6]+((unsigned int) msg.data[7] << 8);
                break;

            case 0x1811FBEF:
                Vcan_count = 0;
                TM_Temp = msg.data[0];
                TM_Voltage_DC = (unsigned char) msg.data[1]+((unsigned int) msg.data[2] << 8);
                TM_Current_DC = (unsigned char) msg.data[3]+((unsigned int) msg.data[4] << 8);
                break;


                /*case 0x0C01EF09://MCU01
                    Vcan_count = 0;
                    TM_Feedback_RPM = (unsigned char) msg.data[0]+((unsigned int) msg.data[1] << 8);
                    TM_Feedback_NM = (unsigned char) msg.data[2]+((unsigned int) msg.data[3] << 8);
                    TM_Current_AC = (unsigned char) msg.data[4]+((unsigned int) msg.data[5] << 8);
                    TM_StatusFeedback = msg.data[6];
                    TM_WorkStatus = msg.data[7]&0x0F;
                    TM_LIFE = (msg.data[7] >> 4)&0x0F;
                    break;   
                
                case 0x0C02EF09://MCU02
                    Vcan_count = 0;
                    TM_Temp = msg.data[0];
                    TM_Control_Temp = msg.data[1];
                    TM_Torque_Limit_Up= (unsigned char) msg.data[2]+((unsigned int) msg.data[3] << 8);
                    TM_Torque_Limit_Down= (unsigned char) msg.data[4]+((unsigned int) msg.data[5] << 8);
                    TM_Fault.byte = msg.data[6]&0x0F;
                    TM_Status = (msg.data[6] >> 4)&0x0F;
                    TM_Status_Flag1.byte = msg.data[7];
                    break;     
            
                case 0x0C03EF09://MCU03
                    Vcan_count = 0;
                    TM_Code = (unsigned char) msg.data[0]+((unsigned int) msg.data[1] << 8);
                    TM_Current_DC = (unsigned char) msg.data[2]+((unsigned int) msg.data[3] << 8);
                    TM_Voltage_DC = (unsigned char) msg.data[4]+((unsigned int) msg.data[5] << 8);
                    break; */

            case 0x18FF08F2://IRM01
                Vcan_count = 0;
                IRM_Ohm_Positive = (unsigned char) msg.data[0]+((unsigned int) msg.data[1] << 8)+((unsigned long) msg.data[2] << 16);
                IRM_Ohm_Negative = (unsigned char) msg.data[3]+((unsigned int) msg.data[4] << 8)+((unsigned long) msg.data[5] << 16);

                CAN_DOUBLE.byte = msg.data[6];
                IRM_Fault_Level = CAN_DOUBLE.bit1;
                IRM_Insulation_Level = CAN_DOUBLE.bit2;

                IRM_Life = msg.data[7];
                break;

                /*case 0x18FFA0F3://VCU21 
                    Vcan_count = 0;
                    VCU_Kt = msg.data[0]&0x03;
                    VCU_ON = (msg.data[0] >> 2)&0x03;
                    VCU_Order = (msg.data[0] >> 4)&0x03;
                    VCU_Voltage = (unsigned char) msg.data[1]+((unsigned int) msg.data[2] << 8);
                    break;*/

            case 0x10F8159E://BMS STATUS 1 
                Bcan_count = 0;
                BMS_Mode = msg.data[0]&0x07;
                BMS_Status = (msg.data[0] >> 6)&0x03;
                BAT_Temp_Average = msg.data[1];
                BMS_SOC = msg.data[2];
                BMS_Current = (unsigned char) msg.data[3]+((unsigned int) msg.data[4] << 8);
                BMS_Voltage = (unsigned char) msg.data[5]+((unsigned int) msg.data[6] << 8);
                BMS_Kt = (msg.data[7] >> 4)&0x0F;
                break;

            case 0x10F8169E://BMS STATUS 2 
                Bcan_count = 0;
                BAT_Temp_H_Limit = msg.data[0];
                BAT_Temp_L_Limit = msg.data[1];
                BMS_SOC_L_Limit = msg.data[2];
                BAT_Current_Discharge_Limit = (unsigned char) msg.data[3]+((unsigned int) msg.data[4] << 8);
                BAT_Current_Charge_Limit = (unsigned char) msg.data[5]+((unsigned int) msg.data[6] << 8);
                break;

            case 0x18F8179E://BMS STATUS 3
                Bcan_count = 0;
                BAT_Temp_L = msg.data[0];
                BAT_Temp_L_Number = msg.data[1];
                BAT_Temp_L_Case = msg.data[2];
                BAT_Temp_H = msg.data[3];
                BAT_Temp_H_Number = msg.data[4];
                BAT_Temp_H_Case = msg.data[5];
                break;

            case 0x18F8189E://BMS STATUS 4
                Bcan_count = 0;
                BAT_Voltage_Fault = msg.data[0]&0x0F;
                BAT_Single_Fault = (msg.data[0] >> 4)&0x0F;
                BAT_Temp_Fault = msg.data[1]&0x3F;
                BAT_Insulation_Fault = (msg.data[1] >> 6)&0x3F;
                BAT_Consistency_Fault = msg.data[2]&0x03;
                BAT_SOC_Fault = (msg.data[2] >> 2)&0x3F;
                BAT_Current_Fault = msg.data[3]&0x0F;
                BAT_Lock_Fault = (msg.data[3] >> 4)&0x03;
                BMS_Comm_Fault = (msg.data[3] >> 6)&0x03;
                BMS_System_Fault = msg.data[4]&0x01;
                break;

            case 0x18F8199E://BMS STATUS 5
                Bcan_count = 0;
                BMS_Ohm = (unsigned char) msg.data[0]+((unsigned int) msg.data[1] << 8);
                BMS_Number = msg.data[2];
                BMS_Temp_Number = msg.data[3];
                BMS_System_Unit = msg.data[4];
                BMS_System_Number = msg.data[5];
                break;

            case 0x18F81A9E://BMS STATUS 6
                Bcan_count = 0;
                BAT_Single_L = (unsigned char) msg.data[0]+((unsigned int) msg.data[1] << 8);
                BAT_Single_L_Number = msg.data[2];
                BAT_Single_L_Case = msg.data[3];
                BAT_Single_H = (unsigned char) msg.data[4]+((unsigned int) msg.data[5] << 8);
                BAT_Single_H_Number = msg.data[6];
                BAT_Single_H_Case = msg.data[7];
                break;


            case 0x18FF12F7://DCDC21 
                Bcan_count = 0;
                DCDC_Voltage = (unsigned char) msg.data[0]+((unsigned int) msg.data[1] << 8);
                DCDC_Current = (unsigned char) msg.data[2]+((unsigned int) msg.data[3] << 8);
                DCDC_Status = msg.data[4]&0x03;
                DCDC_Output_Cut = (msg.data[4] >> 2)&0x01;
                DCDC_intput_Cut = (msg.data[4] >> 3)&0x01;
                DCDC_Fault_Code = msg.data[5];
                DCDC_Level_Fault = msg.data[6]&0x03;
                DCDC_Temp_Warn = (msg.data[6] >> 2)&0x01;
                DCDC_Fault_Warn = (msg.data[6] >> 3)&0x01;
                DCDC_Temp = msg.data[7];
                break;

            case 0x18FF0AF8://OILDCAC21 
                Bcan_count = 0;
                OILDCAC_U_Voltage = (unsigned char) msg.data[0]+((unsigned int) msg.data[1] << 8);
                OILDCAC_U_Current = (unsigned char) msg.data[2]+((unsigned int) msg.data[3] << 8);
                OILDCAC_Status = msg.data[4]&0x03;
                OILDCAC_Output_Cut = (msg.data[4] >> 2)&0x01;
                OILDCAC_intput_Cut = (msg.data[4] >> 3)&0x01;
                OILDCAC_Fault_Code = msg.data[5];
                OILDCAC_Level_Fault = msg.data[6]&0x03;
                OILDCAC_Temp_Warn = (msg.data[6] >> 2)&0x01;
                OILDCAC_Fault_Warn = (msg.data[6] >> 3)&0x01;
                OILDCAC_Temp = msg.data[7];
                break;

            case 0x18FF0BF8://OILDCAC22 
                Bcan_count = 0;
                OILDCAC_V_Voltage = (unsigned char) msg.data[0]+((unsigned int) msg.data[1] << 8);
                OILDCAC_V_Current = (unsigned char) msg.data[2]+((unsigned int) msg.data[3] << 8);
                OILDCAC_W_Voltage = (unsigned char) msg.data[4]+((unsigned int) msg.data[5] << 8);
                OILDCAC_W_Current = (unsigned char) msg.data[6]+((unsigned int) msg.data[7] << 8);
                break;

            case 0x18FF0CF9://AIRDCAC21 
                Bcan_count = 0;
                AIRDCAC_U_Voltage = (unsigned char) msg.data[0]+((unsigned int) msg.data[1] << 8);
                AIRDCAC_U_Current = (unsigned char) msg.data[2]+((unsigned int) msg.data[3] << 8);
                AIRDCAC_Status = msg.data[4]&0x03;
                AIRDCAC_Output_Cut = (msg.data[4] >> 2)&0x01;
                AIRDCAC_intput_Cut = (msg.data[4] >> 3)&0x01;
                AIRDCAC_Fault_Code = msg.data[5];
                AIRDCAC_Level_Fault = msg.data[6]&0x03;
                AIRDCAC_Temp_Warn = (msg.data[6] >> 2)&0x01;
                AIRDCAC_Fault_Warn = (msg.data[6] >> 3)&0x01;
                AIRDCAC_Temp = msg.data[7];
                break;

            case 0x18FF0DF9://AIRDCAC22 
                Bcan_count = 0;
                AIRDCAC_V_Voltage = (unsigned char) msg.data[0]+((unsigned int) msg.data[1] << 8);
                AIRDCAC_V_Current = (unsigned char) msg.data[2]+((unsigned int) msg.data[3] << 8);
                AIRDCAC_W_Voltage = (unsigned char) msg.data[4]+((unsigned int) msg.data[5] << 8);
                AIRDCAC_W_Current = (unsigned char) msg.data[6]+((unsigned int) msg.data[7] << 8);
                break;

            case 0x1801EFA9://ICS01
                Vcan_count = 0;
                ICS01_Status1.byte = msg.data[0];
                ICS01_Status2.byte = msg.data[1];
                ICS01_Status3.byte = msg.data[2];
                ICS01_Status4.byte = msg.data[3];
                ICS01_Voltage_Front = (unsigned char) msg.data[4]+((unsigned int) (msg.data[5]&0x0F) << 8);
                ICS01_Voltage_Rear = (unsigned char) (msg.data[5] >> 4)+((unsigned int) msg.data[6] << 4);
                ICS01_LIFE = msg.data[7];
                break;
                
            case 0x18FEF433://̥ѹ����
                //TireLocation_LR = msg.data[0]&0x0F;
                //TireLocation_FB = (msg.data[0] >> 4)&0x0F;
                temp = msg.data[0];
                i = temp & 0x0F;
                j = (temp >> 4) & 0x0F;
                TireLocation[j][i] = temp;
                TirePressure[j][i] = msg.data[1];
                TireTemperature[j][i] = (unsigned char) msg.data[2]
                        +((unsigned int) msg.data[3] << 8);
                TireFault[j][i].byte = msg.data[4];
                TireAirLeakageRate[j][i] = (unsigned char) msg.data[5]
                        +((unsigned int) msg.data[6] << 8);
                TirePressureThresholdDetection[j][i] = (msg.data[7] >> 5)&0x07;
                break;

                /*
                case 0x0C03A1A7://VCU21 
                    Vcan_count=0;
                    moto_voltage = (unsigned char) msg.data[0]+((unsigned int) msg.data[1] << 8);
                    moto_current = (unsigned char) msg.data[2]+((unsigned int) msg.data[3] << 8);
                    moto_speed = (unsigned char) msg.data[4]+((unsigned int) msg.data[5] << 8);
                    Motor_Temperature = msg.data[6];
                    Inverter_t = msg.data[7];
                    break;

                case 0x0C04A1A7://�Ǳ���MET_C_2
                    Vcan_count=0;
                    Accelerator = (unsigned char) msg.data[4];
                    Engine_Speed = ((unsigned char) msg.data[5]+((unsigned int) msg.data[6] << 8))*0.125;
                    break;

                case 0x0C05A1A7://�Ǳ���MET_C_3
                    Vcan_count=0;
                    Fule_rate = (unsigned char) msg.data[0]+((unsigned int) msg.data[1] << 8);
                    water_temp = msg.data[2];
                    Engine_Fuhe = msg.data[3];
                    Niaosu = msg.data[4];
                    Accelerator_Shiji = msg.data[5]; //����̤��ʵ��
                    Engine_oil_press = msg.data[6]; //����ѹ��
                    ambient_air_temperature = msg.data[7]; //��Χ�����¶�
                    break;

                case 0x0C06A1A7://�Ǳ���MET_C_4  
                    Vcan_count=0;
                    Current_Gear = msg.data[1]&0x0f;
                    TCU_Position = (msg.data[1] >> 4)&0x0f;
                    TCU_warn = msg.data[2]&0x03;
                    STOP = (msg.data[2] >> 2)&0x03;
                    Speed_rmp = ((unsigned char) msg.data[3]+((unsigned int) msg.data[4] << 8))*0.125;
                    Car_mode = msg.data[5];
                    TCU_code = msg.data[6];
                    TCU_level = msg.data[7];
                    break;

                case 0x0C07A1A7://�Ǳ���MET_C_5  
                    Vcan_count=0;
                    CAN_ON = msg.data[0]&0x01;
                    CAN_ACC = (msg.data[0] >> 1)&0x01;
                    Diagnosis = (msg.data[0] >> 2)&0x01;
                    Mode_S = (msg.data[0] >> 3)&0x01;
                    AC = (msg.data[0] >> 4)&0x01;
                    Hybrid = (msg.data[0] >> 5)&0x01;
                    Electric = (msg.data[0] >> 6)&0x01;
                    Tradition = (msg.data[0] >> 7)&0x01;
                    High_Voltage = (msg.data[1] >> 4)&0x01;
                    Charge_Check = (msg.data[1] >> 5)&0x01;
                    Digit_input3 = msg.data[2];
                    //Kt = (msg.data[3] >> 1)&0x01;
                    Brake_Pedal = msg.data[4]&0x01;
                    Speed_percent = msg.data[5];
                    Brake_percent = msg.data[6];
                    break;

                case 0x0C08A1A7://�Ǳ���MET_C_6  
                    Vcan_count=0;
                    Program = ((unsigned char) msg.data[0]
                            +((unsigned int) msg.data[1] << 8)
                            +((unsigned long) msg.data[2] << 16));
                    tcu_spn = ((unsigned char) msg.data[3]
                            +((unsigned int) msg.data[4] << 8)
                            +((unsigned long) (msg.data[5]&0xE0) << 11));
                    tcu_fmi = msg.data[5]&0x1F;
                    tcu_cm = msg.data[6] >> 7;
                    ;
                    tcu_oc = msg.data[6]&0x7F;
                    Car_LIFE = msg.data[7];
                    break;

                case 0x1818D0F3://BMS1_S_1
                    Bcan_count=0;
                    BMS_V = ((unsigned char) msg.data[0]
                            +((unsigned int) msg.data[1] << 8));
                    BMS_A = ((unsigned char) msg.data[2]
                            +((unsigned int) msg.data[3] << 8));
                    BMS_SOC = msg.data[4];
                    Status_Flag1 = msg.data[5];
                    Status_Flag2 = msg.data[6];
                    Status_Flag3 = msg.data[7]&0x0C;
                    break;

                case 0x1819D0F3://BMS1_S_2
                    Bcan_count=0;
                    BMS_A_charge = ((unsigned char) msg.data[0]
                            +((unsigned int) msg.data[1] << 8));
                    BMS_A_discharge = ((unsigned char) msg.data[2]
                            +((unsigned int) msg.data[3] << 8));
                    Warn_level = msg.data[4];
                    BMS_V_average = ((unsigned char) msg.data[5]
                            +((unsigned int) msg.data[6] << 8));
                    BMS_T_H = msg.data[7];
                    break;

                case 0x181AD0F3://BMS1_S_3
                    Bcan_count=0;
                    Oum_zheng = ((unsigned char) msg.data[0]
                            +((unsigned int) msg.data[1] << 8));
                    Oum_fu = ((unsigned char) msg.data[2]
                            +((unsigned int) msg.data[3] << 8));
                    Battery_single_H = ((unsigned char) msg.data[4]
                            +((unsigned int) msg.data[5] << 8));
                    Battery_single_L = ((unsigned char) msg.data[6]
                            +((unsigned int) msg.data[7] << 8));
                    break;

                case 0x180028F3://BMS1_S_4_1
                    Bcan_count=0;
                    Battery_number[0] = msg.data[0];
                    Battery_voltage[0] = ((unsigned char) msg.data[1]
                            +((unsigned int) msg.data[2] << 8));
                    Battery_number[1] = msg.data[3];
                    Battery_voltage[1] = ((unsigned char) msg.data[4]
                            +((unsigned int) msg.data[5] << 8));
                    break;

                case 0x180128F3://BMS1_S_4_2
                    Bcan_count=0;
                    Battery_number[2] = msg.data[0];
                    Battery_voltage[2] = ((unsigned char) msg.data[1]
                            +((unsigned int) msg.data[2] << 8));
                    Battery_number[3] = msg.data[3];
                    Battery_voltage[3] = ((unsigned char) msg.data[4]
                            +((unsigned int) msg.data[5] << 8));
                    break;

                case 0x180228F3://BMS1_S_4_3
                    Bcan_count=0;
                    Battery_number[4] = msg.data[0];
                    Battery_voltage[4] = ((unsigned char) msg.data[1]
                            +((unsigned int) msg.data[2] << 8));
                    Battery_number[5] = msg.data[3];
                    Battery_voltage[5] = ((unsigned char) msg.data[4]
                            +((unsigned int) msg.data[5] << 8));
                    break;

                case 0x180328F3://BMS1_S_4_4
                    Bcan_count=0;
                    Battery_number[6] = msg.data[0];
                    Battery_voltage[6] = ((unsigned char) msg.data[1]
                            +((unsigned int) msg.data[2] << 8));
                    Battery_number[7] = msg.data[3];
                    Battery_voltage[7] = ((unsigned char) msg.data[4]
                            +((unsigned int) msg.data[5] << 8));
                    break;

                case 0x180428F3://BMS1_S_4_5
                    Bcan_count=0;
                    Battery_number[8] = msg.data[0];
                    Battery_voltage[8] = ((unsigned char) msg.data[1]
                            +((unsigned int) msg.data[2] << 8));
                    Battery_number[9] = msg.data[3];
                    Battery_voltage[9] = ((unsigned char) msg.data[4]
                            +((unsigned int) msg.data[5] << 8));
                    break;

                case 0x180028F4://BMS1_S_5_1
                    Bcan_count=0;
                    Battery_number_t[0] = msg.data[0];
                    Battery_temp[0] = msg.data[1];
                    Battery_number_t[1] = msg.data[2];
                    Battery_temp[1] = msg.data[3];
                    Battery_number_t[2] = msg.data[4];
                    Battery_temp[2] = msg.data[5];
                    Battery_number_t[3] = msg.data[6];
                    Battery_temp[3] = msg.data[7];
                    break;

                case 0x180128F4://BMS1_S_5_2
                    Bcan_count=0;
                    Battery_number_t[4] = msg.data[0];
                    Battery_temp[4] = msg.data[1];
                    Battery_number_t[5] = msg.data[2];
                    Battery_temp[5] = msg.data[3];
                    Battery_number_t[6] = msg.data[4];
                    Battery_temp[6] = msg.data[5];
                    Battery_number_t[7] = msg.data[6];
                    Battery_temp[7] = msg.data[7];
                    break;

                case 0x180228F4://BMS1_S_5_3
                    Bcan_count=0;
                    Battery_number_t[8] = msg.data[0];
                    Battery_temp[8] = msg.data[1];
                    Battery_number_t[9] = msg.data[2];
                    Battery_temp[9] = msg.data[3];
                    break;


                case 0x0C09A79B://DAC_S_1
                    Dcan_count=0;
                    DCAC_W = ((unsigned char) msg.data[0]
                            +((unsigned int) msg.data[1] << 8));
                    DCAC_V = ((unsigned char) msg.data[2]
                            +((unsigned int) msg.data[3] << 8));
                    DCAC_U = ((unsigned char) msg.data[4]
                            +((unsigned int) msg.data[5] << 8));
                    Sanreqi_t = msg.data[6];
                    DCAC_Warn_code = msg.data[7];
                    break;


                case 0x18FFC09E://AIR_S_1
                    Acan_count=0;
                    AC_Warn_code = msg.data[0];
                    AC_opean = (msg.data[1] >> 5)&0x01;
                    AC_mind_speed = (msg.data[1] >> 6)&0x01;
                    AC_High_speed = (msg.data[1] >> 7)&0x01;
                    AC_warn1 = msg.data[2]&0x01;
                    AC_cold1_shuang = (msg.data[2] >> 1)&0x01;
                    AC_wind = (msg.data[2] >> 2)&0x01;
                    AC_save = (msg.data[2] >> 3)&0x01;
                    AC_cold2_shuang = (msg.data[2] >> 4)&0x01;
                    AC_cold2 = (msg.data[2] >> 5)&0x01;
                    AC_cold1 = (msg.data[2] >> 7)&0x01;
                    Indoor_t = msg.data[3];
                    Outdoor_t = msg.data[4];
                    Set_t = msg.data[5];
                    AC_req = msg.data[6]&0x01;
                    AC_LIFE = msg.data[7];
                    break;
                
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
        for (i = 0; i < 100; i++) {
            if (msg.id == (0x104C19A4 + i)) {
                Bcan_count = 0;
                BAT_Cell_Voltage[i * 4] = (unsigned char) msg.data[0]+((unsigned int) msg.data[1] << 8);
                BAT_Cell_Voltage[(i * 4) + 1] = (unsigned char) msg.data[2]+((unsigned int) msg.data[3] << 8);
                BAT_Cell_Voltage[(i * 4) + 2] = (unsigned char) msg.data[4]+((unsigned int) msg.data[5] << 8);
                BAT_Cell_Voltage[(i * 4) + 3] = (unsigned char) msg.data[6]+((unsigned int) msg.data[7] << 8);
            }
        }
        for (i = 0; i < 16; i++) {
            if (msg.id == (0x104C1A18 + i)) {
                Bcan_count = 0;
                BAT_Cell_Temperature[i * 8] = (unsigned char) msg.data[0];
                BAT_Cell_Temperature[(i * 8) + 1] = (unsigned char) msg.data[1];
                BAT_Cell_Temperature[(i * 8) + 2] = (unsigned char) msg.data[2];
                BAT_Cell_Temperature[(i * 8) + 3] = (unsigned char) msg.data[3];
                BAT_Cell_Temperature[(i * 8) + 4] = (unsigned char) msg.data[4];
                BAT_Cell_Temperature[(i * 8) + 5] = (unsigned char) msg.data[5];
                BAT_Cell_Temperature[(i * 8) + 6] = (unsigned char) msg.data[6];
                BAT_Cell_Temperature[(i * 8) + 7] = (unsigned char) msg.data[7];
            }
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
    static float mile = 0;
    //static unsigned char task1 = 0;
    //������ʱ3s���
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
        PCAN_ICU2VCU01();
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
        BAT24V_count = BAT24V_count >= BAT24_TIME ? BAT24_TIME : BAT24V_count + 1;
        if (Tcan_count >= 600)Tcan_count = 600;
        else Tcan_count++;

        if (cnt4 >= 9) {//1s
            cnt4 = 0;
            F1000ms = 1;
            FLASH_1s = !FLASH_1s;
            if (Tcan_count < 600) {
                PCAN_Taiya();
            }
            //PCAN_send_mile();
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
        PCAN_ICU2VCU02();
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
    _T5IF = 0;
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
