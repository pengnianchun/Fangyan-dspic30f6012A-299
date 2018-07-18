#include "SYSTEM.h"
unsigned char delay_cnt;
DATA_BIT gKEY[5];
DATA_BIT gCTL[8]; //�Ǳ����������Ϣ

unsigned int single_miles = 0;
unsigned long total_miles = 0;


unsigned int Fcan_count = 0; //ǰ��ģ��
unsigned int Rcan_count = 0; //����ģ��
unsigned int Mcan_count = 0; //�в�ģ��
unsigned int Ncan_count = 0; //������ECUģ��




DBCM_KEY fKEY; //ǰģ�鹦�ʿ���״̬
DBCM_KEY mKEY; //�У�����ģ�鹦�ʿ���״̬
DBCM_KEY rKEY; //��ģ�鹦�ʿ���״̬

unsigned int fFreq; //ǰģ��Ƶ��
unsigned int mFreq; //�У�����ģ��Ƶ��
unsigned int rFreq; //��ģ��Ƶ��

unsigned int fSpeed; //ǰģ�����㳵��
unsigned int mSpeed; //�У�����ģ�����㳵��
unsigned int rSpeed; //��ģ�����㳵��

unsigned int fADR[2]; //ǰģ�����ֵ
unsigned int mADR[2]; //�У�����ģ�����ֵ
unsigned int rADR[2]; //��ģ�����ֵ

DBCM_POUT fPOUT; //ǰģ�鹦�����״̬
DBCM_POUT mPOUT; //�У�����ģ�鹦�����״̬
DBCM_POUT rPOUT; //��ģ�鹦�����״̬

unsigned char fPF[15]; //ǰģ�鹦���������
unsigned char mPF[15]; //�У�����ģ�鹦�ʹ���
unsigned char rPF[15]; //��ģ�鹦���������

unsigned int fSingle_miles;
unsigned int mSingle_miles;
unsigned int rSingle_miles;
//ϵͳ��ʼ������

void System_Init(void) {
    ADPCFG = 0xffff; //�ر�AD��  

    /*�������ƽӿ� */
    KEY_UP_DR = 1; //   
    KEY_SET_DR = 1; // 
    KEY_AV_DR = 1;

    PWR_CTRL_DR = 1; //�����ѹ�˿ڳ�ʼ��
    PWR_CTRL = 0;

    TIMER1_Init();
    delay_cnt = 10; //��ʼֵ
    LCD_Init(); //Һ������ʼ��

    delay_cnt = 10;
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
        if (wake_up1) {//���Σ�ձ�������
            F_PO9 = FLASH;
            F_PO10 = FLASH;
            M_PO7 = FLASH;
            M_PO8 = FLASH;
            BUZZ = !FLASH;
        } else {
            F_PO9 = 0;
            F_PO10 = 0;
            M_PO7 = 0;
            M_PO8 = 0;
        }
        LED4 = M_PO7; //��ת���
        LED8 = M_PO8; //��ת���

        if (F50ms) {
            F50ms = 0;
            LED_Out();
            SW_Input();
            BCAN_SendCtl();
        }

        if (M_ON) break; // �����ON�����������˳�
        if (wake_up1 == 0) {
            F_PO9 = 0;
            F_PO10 = 0;
            M_PO7 = 0;
            M_PO8 = 0;
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
        }
    }

    delay_cnt = 200; //����2s��ʱ 
    SM_Init();
    SM_Reset();
    BL_Init(); //�Ǳ�С�Ʊ����ʼ��

    EEROM_ReadSingleMiles();
    EEROM_ReadTotalMiles();
    EEROM_ReadHMPulse();
    EEROM_ReadBackLight();

    OC1RS = e_backlight; //���±���ֵ
    //ConfigINT1();
    //ConfigINT2();

    ADC_Init();
    LCD_Init();
    alarm_led[0].byte = 0xC0; //����������
    alarm_led[1].byte = 0xff;
    alarm_led[2].byte = 0xff;
    alarm_led[3].byte = 0xff;
    LED_Out();

    while (delay_cnt > 1); //��ʱ0.1s
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

}

void LED_Logic(void) {

    
    
  //���� С�ƿ��رպ� 
 if(IN2)          OC1RS=e_backlight;
 else             OC1RS=0; 
}

void BCAN_SendCtl(void) {

}

void __attribute__((__interrupt__, auto_psv)) _C1Interrupt(void) {
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
            case 0x561:
                Fcan_count = 0;
                fPOUT.BYTES[0] = message.data[0];
                fPOUT.BYTES[1] = message.data[1];

                break;
            case 0x562:
                Mcan_count = 0;
                mPOUT.BYTES[0] = message.data[0];
                mPOUT.BYTES[1] = message.data[1];

                break;

            case 0x563:
                Rcan_count = 0;
                rPOUT.BYTES[0] = message.data[0];
                rPOUT.BYTES[1] = message.data[1];

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


unsigned char engine_oil_press = 0;
unsigned char barometric_pressure = 0; //��ѹѹ�� 0.5Kpa
unsigned char ambient_air_temperature = 0; //��Χ�����¶�
unsigned char air_pressure = 0; //����ѹ�� 0.5Kpa
unsigned int EngineSpeed = 0;
unsigned char WaterTem = 0;
unsigned int fuel_rate = 0; //Сʱȼ��������
unsigned int instantaneous_fuel = 0; //˲̬ȼ�;�����
unsigned int battery_voltage = 520;
unsigned char speed_st = 0; //����̤��״̬
unsigned char ECU_DM1 = 0; //ECU DM1 ����

void __attribute__((__interrupt__, auto_psv)) _C2Interrupt(void) {
    CAN_MESSAGE msg;
    if (C1INTFbits.ERRIF) { //���մ���
        C1INTFbits.ERRIF = 0; // ��Ӵ��������
        CAN1_Init();
        C1RX0CONbits.RXFUL = 0;
    }
    if (C1INTFbits.IVRIF) {
        C1INTFbits.IVRIF = 0; //������Ч
        C1RX0CONbits.RXFUL = 0;
    }
    if (C1RX0CONbits.RXFUL) { //������Ч
        Ncan_count = 0;
        CAN2_ReceiveMessage(&msg);
        switch (msg.id) {
            case 0x18FEEF00://������Һ���/ѹ��
                Ncan_count = 0; 
                engine_oil_press = msg.data[3];
                break;

            case 0xcf00400:
                Ncan_count = 0; 
                EngineSpeed = msg.data[3]+((unsigned int) (msg.data[4]) << 8);
                if (EngineSpeed >= 28000) EngineSpeed = 28000; //�����3500RPM
                sm_new_value[4] = (unsigned int) (0.097 * EngineSpeed); //����ת�ٱ�
                break;
            case 0x18FEEE00:
                Ncan_count = 0; 
                WaterTem = msg.data[0];
                break;
            case 0x0CF00300:
                Ncan_count = 0; 
                speed_st = msg.data[1]; //̤�忪��
                break;
            case 0x18FECA00: //DM1
                Ncan_count = 0; 
                ECU_DM1 = msg.data[0];
                break;
            case 0x18FEF200://ȼ������
                Ncan_count = 0; 
                fuel_rate = msg.data[0]+((unsigned int) (msg.data[1]) << 8); //0.05L/h
                instantaneous_fuel = msg.data[2]+((unsigned int) (msg.data[3]) << 8); // 1/512 km/L
                break;
            case 0x18FEF600: //��Χ�������� id==0x18FEF600
                Ncan_count = 0; 
                barometric_pressure = msg.data[1]; //��ѹѹ�� 0.5Kpa
                ambient_air_temperature = msg.data[2]; //��Χ�����¶�
                air_pressure = msg.data[3]; //����ѹ�� 0.5Kpa
                break;
            case 0x18FEF700://��ѹ
                Ncan_count = 0; 
                battery_voltage = msg.data[6]+((unsigned int) (msg.data[7]) << 8);
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
    static unsigned int lpcnt2 = 0, lpcnt1 = 0, lpcount = 0;
    static unsigned int Fcount = 0, Kcount = 0;


    if (delay_cnt > 0) delay_cnt--; //��ʱ������ 

    if (cnt0 >= 5) {//50ms
        cnt0 = 0;
        SYSTME_Logic();
        BCAN_SendCtl();
        F50ms = 1;
        
    } else cnt0++;

    if (cnt1 >= 10) {//100ms
        cnt1 = 0;
        LED_Logic();
        LED_Out();
        F100ms = 1;
        if (Fcan_count >= CAN_TIME)Fcan_count = CAN_TIME;
        else Fcan_count++;
        if (Rcan_count >= CAN_TIME)Rcan_count = CAN_TIME;
        else Rcan_count++;
        if (Mcan_count >= CAN_TIME)Mcan_count = CAN_TIME;
        else Mcan_count++;
        if (Ncan_count >= CAN_TIME)Ncan_count = CAN_TIME;
        else Ncan_count++;

        if (cnt4 > 10) {//1s
            cnt4 = 0;
            FLASH_1s = !FLASH_1s;
        } else cnt4++;
    } else cnt1++;

    if (Fcount >= 40) {//0.4s
        Fcount = 0;
        FLASH = !FLASH;
    } else Fcount++;

    if (Kcount >= 30) {//300ms
        Kcount = 0;
        kFLASH = !kFLASH;
    } else Kcount++;

    if (cnt2 >= 50) {//500ms 
        cnt2 = 0;
        F500ms = 1;
        F500ms_LCD = !F500ms_LCD;
    } else cnt2++;

    if (wake_up3) { //ON�����ж�
        if (cnt3 > 30) M_ON = 1;
        else cnt3++;
    } else {
        if (cnt3 < 1) M_ON = 0;
        else cnt3--;
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
        key_up = 1;         //���ϰ���
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
        if (lpcnt2 >= 300) {
            lpcnt2 = 0;
            bkey_set = 1; //����ʱȡ������������
            key_long_set = 1;
        } else lpcnt2++;
    } else {
        lpcnt2 = 0;
    }
    
    if (KEY_AV && KEY_UP) {
        if (lpcnt1 >= 300) {
            lpcnt1 = 0;
            bkey_AV = 1; //����ʱȡ������������
            bkey_up = 1; //����ʱȡ������������
            key_duble = 1; //�������ܰ���
        } else lpcnt1++;
    } else {
        lpcnt1 = 0;
    }
    
    if (KEY_AV &&  (KEY_UP == 0)) { //���� 2S ���㵥���
        if (lpcount >= 200) {
            single_miles = 0;
            save_flag = 1;
            bkey_AV = 1; //����ʱȡ������������
            lpcount = 100;
        } else lpcount++;
    } else if (lpcount > 0) lpcount--;

    _T1IF = 0;
}



