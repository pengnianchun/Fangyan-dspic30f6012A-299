#include "SYSTEM.h"
//#include "LOGO.h"
unsigned int delay_cnt;
unsigned int delay_5s;
DATA_BIT gKEY[5];
DATA_BIT gCTL[8]; //�Ǳ����������Ϣ

unsigned int single_miles = 0;
unsigned long total_miles = 0;
unsigned int X_pSpeed=0;

unsigned int Fcan_count = 0; //ǰ��ģ��CAN
unsigned int Rcan_count = 0; //����ģ��CAN
unsigned int Mcan_count = 0; //�в�ģ��CAN
unsigned int Ecan_count = 0; //������ECUģ��CAN
unsigned int Vcan_count = 0; //����������VCUģ��CAN
unsigned int Bcan_count = 0; //��ع�����BMSģ��CAN
unsigned int Dcan_count = 0; //ת������DC/ACģ��CAN
unsigned int Acan_count = 0; //�յ�ACģ��CAN

unsigned int Hcan_count = 0; //�����
unsigned int Jcan_count = 0; //��Ե���
unsigned int Ccan_count = 0; //DCDC
unsigned int Qcan_count = 0; //����
unsigned int Ycan_count = 0; //�ͱ�
unsigned int ECU_TIME;
unsigned int QY_count   = 0; //��ѹ��ʱ����

unsigned int BAT24V_count = 0; //���ص�ѹ������ʱ

unsigned int M_PO11_count = 1000; //���10���ʱ

DBCM_KEY fKEY; //ǰģ�鹦�ʿ���״̬
DBCM_KEY mKEY; //�У�����ģ�鹦�ʿ���״̬
DBCM_KEY rKEY; //��ģ�鹦�ʿ���״̬

SW_DATA  fkey[3];
SW_DATA  rkey[3];
SW_DATA  tkey[3];

unsigned int fMK_Version=0; //ǰģ��汾��
unsigned int mMK_Version=0; //��ģ��汾��
unsigned int rMK_Version=0; //��ģ��汾��

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

unsigned int  BUZZ_COUNT;
unsigned int  Vspeed=0; //����
//ϵͳ��ʼ������

void System_Init(void) {
    unsigned char i, j;
    ADPCFG = 0xffff; //�ر�AD��     
    LED_Clear(); //��������˲��LED�ͷ�������˸
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
    LED_Clear();
    LED_Out();
    POUT_Clear();
    CAN1_Init();
    CAN2_Init();
    while (1) {
        ClrWdt();
        LCD_BackLight(0x00);
        if (wake_up3) {
            PWR_CTRL_DR = 0;
            PWR_CTRL = 1;
            SYSTME_Logic();
            if (wake_up1) {
                LED4 = FLASH; //��ת�򱨾�
                LED8 = FLASH; //��ת�򱨾�   
                BUZZ = !(LED8 || LED4); //ת�����
            }else {
                LED4 = 0; //��ת�򱨾�
                LED8 = 0; //��ת�򱨾�   
                BUZZ = !(LED8 || LED4); //ת�����
            }
        } else if (wake_up1) {//���Σ�ձ�������
            PWR_CTRL_DR = 0;
            PWR_CTRL = 1;
            F_PO6 = FLASH;
            F_PO7 = FLASH;
            T_PO15 = F_PO7; //��ת���
            T_PO2 = F_PO6; //��ת���
            //R_PO5 = F_PO7; //��ת���
            //R_PO7 = F_PO6; //��ת���
            LED4 = F_PO7; //��ת�򱨾�
            LED8 = F_PO6; //��ת�򱨾�   
            BUZZ = !(LED8 || LED4); //ת�����
        } else {
            POUT_Clear();
            LED_Clear();
        }

        if (F50ms) {
            F50ms = 0;
            LED_Out();
            SW_Input();
            BCAN_SendCtl();
        }

        if (IN1 || wake_up2) break; // �����ON�����������˳�

        if (!wake_up3 && !wake_up1) {
            POUT_Clear();
            LED_Clear();
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
    TIMER3_Init();
    TIM5_Init();
    EEROM_ReadSingleMiles();
    EEROM_ReadTotalMiles();
    EEROM_ReadHMPulse();
    EEROM_ReadBackLight();
    single_miles = e_single_miles;
    total_miles = e_total_miles;
    OC1RS = e_backlight; //���±���ֵ
    EEROM_ReadXSpeed();
    X_pSpeed = e_limit_pSpeed;
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
    LED_Clear();
    LED_Out();
    SW_Input();
    LCD_BackLight(7);
    DS3231_ReadTime(&timer); //��ȡʱ��   

    /*
    //������
    for(j=0;j<10;j++){
        for(i=0;i<24;i++){
            Battery_Voltage[j][i]=1000;
        }
    }
    Battery_Voltage[0][0]=5000;
    Battery_Voltage[1][0]=4000;
    Battery_Voltage[9][0]=3000;
     */
}

void SM_Logic(void) {
    static unsigned char SM_task = 0;
    static unsigned int temp = 0;
    static unsigned int temp16 = 0;
    //Vspeed = (30.0 * DJ_speed) / e_hm_pulse; //���ٵ�λ0.1KM/H
    pSpeed = Vspeed / 10;
    if (Vspeed < 1400)sm_new_value[0] = (unsigned int) (Vspeed * 1.885);
    else sm_new_value[0] = 2640;
    SM_Update_0(); //���ٱ�   �Ƕ�220�� 2640

    if (DJ_speed >= 65534)DJ_speed = 20000;
    if (DJ_speed >= 20000)temp16 = DJ_speed - 20000;
    else temp16 = 20000 - DJ_speed;
    if (temp16 < 8000)sm_new_value[5] = (unsigned int) (temp16 * 0.33);
    else sm_new_value[5] = 2640;
    SM_Update_5(); //ת�ٱ�   �Ƕ�220�� 2640

    if (SM_task == 0) {
        SM_task = 1;
        LCD_Exec();
    } else if (SM_task == 1) {
        SM_task = 2;
        /*              
        temp = ADR[1]; //����ˮ�±���� ���ֵ1152  �����Ƕ�96��
        if (temp < 10)
            sm_new_value[4] = 0;
        else if (temp < 52)
            sm_new_value[4] = ((temp - 10) * 5.48);
        else if (temp < 88)
            sm_new_value[4] = ((1152 * 0.2)+((temp - 52) * 6.4));
        else if (temp < 124)
            sm_new_value[4] = ((1152 * 0.4)+((temp - 88) * 6.4));
        else if (temp < 155)
            sm_new_value[4] = ((1152 * 0.6)+((temp - 124) * 7.43));
        else if (temp < 180)
            sm_new_value[4] = ((1152 * 0.8)+((temp - 155) * 9.216));
        else sm_new_value[4] = 1152;
         */
        temp = ADV[3] / 10;
        if (temp < 50)sm_new_value[4] = 0;
        else if (temp < 300)sm_new_value[4] = (unsigned int) (4.608 * (temp - 50));
        else sm_new_value[4] = 1152;
        SM_Update_4(); //��ѹ1
    } else if (SM_task == 2) {
        SM_task = 3;
        temp = DC_SOC;
        if (temp <= 0) {//���ֵΪ1152Ϊ��
            sm_new_value[3] = 0;
        } else if (temp > 100) {
            sm_new_value[3] = 1152;
        } else {
            sm_new_value[3] = (unsigned int) (11.52 * temp);
        }
        SM_Update_3(); //SOC
    } else if (SM_task == 3) {
        SM_task = 4;
        /*
        temp = ADR[2];//����ˮ�±���� ���ֵ1152  �����Ƕ�96��
        if (temp < 10)
            sm_new_value[2] = 0;
        else if (temp < 52)
            sm_new_value[2] = ((temp - 10) * 5.48);
        else if (temp < 88)
            sm_new_value[2] = ((1152 * 0.2)+((temp - 52) * 6.4));
        else if (temp < 124)
            sm_new_value[2] = ((1152 * 0.4)+((temp - 88) * 6.4));
        else if (temp < 155)
            sm_new_value[2] = ((1152 * 0.6)+((temp - 124) * 7.43));
        else if (temp < 180)
            sm_new_value[2] = ((1152 * 0.8)+((temp - 155) * 9.216));
        else sm_new_value[2] = 1152;
         */
        temp = ADV[4] / 10;
        if (temp < 50)sm_new_value[2] = 0;
        else if (temp < 300)sm_new_value[2] = (unsigned int) (4.608 * (temp - 50));
        else sm_new_value[2] = 1152;
        SM_Update_2(); //��ѹ2
    } else if (SM_task == 4) {
        SM_task = 5;
        temp = ADR[0];
        if (temp < 160) { //���µ�ѹ�����ADR[5]
            sm_new_value[1] = 0;
        } else if ((temp >= 160)&&(temp < 320)) {
            sm_new_value[1] = (unsigned int) (7.2 * (temp - 160));
        } else {
            sm_new_value[1] = 1152;
        }
        //ȼ�ͳ�����
        /*if (temp < 180) { //���µ�ѹ�����ADR[5]
            sm_new_value[1] = 0;
        } else if ((temp >= 180)&&(temp < 240)) {
            sm_new_value[1] = (unsigned int) (6.667 * (temp - 180));
        } else if ((temp >= 240)&&(temp <= 320)) {
            sm_new_value[1] = (unsigned int) (10 * (temp - 240)) + 400;
        } else {
            sm_new_value[1] = 1200;
        }*/
        SM_Update_1(); //��ѹ�� 
    } else if (SM_task == 5) {
        SM_task = 0;
        if (F500ms) { //
            F500ms = 0;
            Count_ADR(); //����ģ������ֵ  ������Ӱ������������ʱ��
            DS3231_ReadTime(&timer); //��ȡʱ��  

            //PCAN_send_mile();//���
            PCAN_send_yb1();
            PCAN_send_yb2();

            LCD_BackLight(7); //

            if (save_flag) {
                save_flag = 0;
                e_single_miles = single_miles;
                e_total_miles = total_miles;
                EEROM_WriteSingleMiles();
                EEROM_WriteTotalMiles();
            }
        }
    } else {
        SM_task = 0;
    }
}

void Count_ADR(void) {
    float ad = 4096;
    //��ѹ�ʹ������ɼ�  ADV[]��ʵ�ʵĵ�ѹ*1000
    //ADV[1] = (unsigned int) (read_ADR(1) / ad * 5000);
    
    ADV[3] = (unsigned int) (read_ADR(3) / ad * 3500) + 0.3*ADV[3];
    ADV[4] = (unsigned int) (read_ADR(4) / ad * 3500) + 0.3*ADV[4];
    ADV[5] = (unsigned int) (read_ADR(5) / ad * 3500) + 0.3*ADV[5]; 
    ADV[6] = (unsigned int) (read_ADR(6) / ad * 3500) + 0.3*ADV[6];
    //���ص�ѹ    
    ADR[0] = (unsigned int) (550.0 * read_VOL() / ad); //ʵ�ʵ�ѹ�Ŵ�10��   //(read_VOL() - 1300)*10 / 76 + 180;
    if (ADR[0] >= 225) BAT24V_count = 0;
    //�����ʹ������ɼ�  ADR[]��ʵ�ʵ���ֵ
    //ADR[1] = (unsigned int) (100.0 * read_ADR(1) / (ad - read_ADR(1))); 
    
    ADR[1] = (unsigned int) (70.0 * read_ADR(1) / (ad - read_ADR(1))) + 0.3*ADR[1];
    ADR[2] = (unsigned int) (70.0 * read_ADR(2) / (ad - read_ADR(2))) + 0.3*ADR[2];
    ADR[3] = (unsigned int) (70.0 * read_ADR(3) / (ad - read_ADR(3))) + 0.3*ADR[3];
    ADR[4] = (unsigned int) (70.0 * read_ADR(4) / (ad - read_ADR(4))) + 0.3*ADR[4];
    ADR[5] = (unsigned int) (70.0 * read_ADR(5) / (ad - read_ADR(5))) + 0.3*ADR[5];
    ADR[6] = (unsigned int) (70.0 * read_ADR(6) / (ad - read_ADR(6))) + 0.3*ADR[6];   
    
    if (ADR[1] > 1000)ADR[1] = 0;      
    if (ADR[2] > 1000)ADR[2] = 0;       
    if (ADR[3] > 1000)ADR[3] = 0;      
    if (ADR[4] > 1000)ADR[4] = 0;  
    if (ADR[5] > 1000)ADR[5] = 0;
    if (ADR[6] > 1000)ADR[6] = 0;
  

}

    unsigned int  QY_TIME=0;  //��ѹ��ʱ����
    unsigned int  KYJ_TIME=0; //��ѹ����ʱ����
    unsigned char QY_OUT_EN=1;//��ѹ�ⲿʹ�ܿ���
void SYSTME_Logic(void) {
    static unsigned char KYJ_EN=1;
    static unsigned char QY_EN=1;
 // F_PO1  = (IN16 && M_ON);                    //��ο쵵
 // F_PO2  = (IN14 && M_ON);                    //�������
 // F_PO3  = (IN21 && M_ON);                    //��ˮ���
    F_PO4  = (M_ON && IN11 && IN22);                  //��ǰ���
    F_PO5  = (M_ON && IN11);                          //���ر���С��  
    F_PO6  = (FLASH && ((M_ON && IN10) || wake_up1)); //��ת���
    F_PO7  = (FLASH && ((M_ON && IN9)  || wake_up1)); //��ת���
    F_PO8  = (M_ON && IN24);                          //����
    F_PO9  = (M_ON && IN12 && !IN13);                 //Զ���      
    F_PO10 = (M_ON && IN11 && IN3);                   //ǰ��̤����
    F_PO11 =  F_PO9;                                  //Զ���
    F_PO12 = (M_ON && IN11 && IN2);                   //����̤���� 
    F_PO13 = (M_ON && IN12 && IN13);                  //����� 
    F_PO14 = (M_ON && IN11);                          //λ�õ�
    F_PO15 =  0;                                      //
    F_PO16 =  0;                                      //���ŵ���
    
    M_PO1  =  0;                                //
    M_PO2  = (F_PO6);                           //�Һ�ת���
    M_PO3  = (M_ON && IN23 && F_PO4);           //�����
    M_PO4  = (M_ON && mKL3);                    //ɲ����
    M_PO5  =  0;                                //
    M_PO6  = (M_ON && mKL5);                    //��յ� 
    M_PO7  =  0;                                //
    M_PO8  = (wake_up2);                        //����ź����
    M_PO9  =  0;                                //
    if(M_ON && (Tmax>80))M_PO10=1; //40�ȿ�     //��زַ��ȵ�Դ 
    if(M_ON && (Tmax<75))M_PO10=0; //35�ȹ�                             
    M_PO11 =  0;                                //
    M_PO12 =  0;                                //
    M_PO13 = (F_PO14);                          //С�Ƶ�Դ
    if(M_ON &&((VCU_Status[0]&0X38)==0X08))M_PO14=1;     //������
    else                                   M_PO14=0; 
    M_PO15 = (F_PO7);                           //���ת���
    M_PO16 =  0;                                //���ŵ���


}

void LED_Logic(void) {
    LED3  = 0; //�յ�ָʾ    
    LED5  = 0; //ǰ����ָʾ    
    LED23 = 0; //������
    LED13 = 0; //������� 
    
    LED10 = 1; //�ܵ�Դָʾ     
    
    LED15 = F_PO14; //С��   
    
    LED4  = F_PO7;  //��ת���
    LED8  = F_PO6;  //��ת���   
    
    LED22 = F_PO13; //�����    
    LED17 = F_PO9;  //Զ���     
    
    LED19 = F_PO4;  //ǰ���
    LED20 = M_PO3;  //�����    
    
    LED1  = IN3;    //ǰ�ſ�ָʾ
    LED2  = IN2;    //���ſ�ָʾ   

    LED18 = mKL1;   //��ɲ
    LED24 = M_PO4;  //ɲ��ָʾ      
    
    LED21 = M_PO14; //������
    if(BAT24V_count >= BAT24_TIME)LED16=1;else LED16=0;//���ص�ѹ��     
    
//////////////////////////////////////////////////////
//ѹ��   0    0.1    0.2   0.4    0.6    0.8    1   //
//��ѹ  0.5   0.725   1    1.5     2     2.5    3   //
/////////////////////////////////////////////////////
    if( //IN11              
       ((ADV[3]/10)<200)     
        //rKL10
      )LED9=1; else LED9=0; //��ѹ1����0.6MPa ����
    
    if( //IN12              
        ((ADV[4]/10)<200)  
        //rKL12  
      )LED11=1;else LED11=0;//��ѹ2����0.6MPa ����   
      
    
    if(VCU_Status[4]==0x01)LED6=1;else LED6=0; //���״̬
    if(wake_up2)LED7=1;else LED7=0; //���ǹ����    
    
    if(DC_Status[1]&0XC0)LED12=1;else LED12=0; //SOC�ͱ���
    if( (DC_fault_dj==1) ||
        (DC_fault_dj==2) ||   
        (DC_fault_dj==3)        
      )LED14=1;else LED14=0; //�������ϵͳ����    
    
//������ Ϊ0ʱ�죬Ϊ1ʱ����
         if(    IN9              ||  //��ת��Ʊ��� 
                IN10             ||  //��ת��Ʊ���
                wake_up1
           )    BUZZ = !(LED4 || LED8);//
    else if( M_ON &&
           (   !fKL4 ||   //��ǰĦ��Ƭ����
               !fKL5 ||   //��ǰĦ��Ƭ����
            
             //!fKL8 ||   //���Ħ��Ƭ����
             //!fKL9 ||   //�Һ�Ħ��Ƭ����
                fKL1 ||   //��ȫ�ſ��ź�
                mKL4 ||   //ǰ��Ӧ����������������
                mKL6 ||   //����Ӧ���������������� 
                mKL9 ||   //����������         
                LED9 ||   //��ѹ1  
                LED11||   //��ѹ2   
            
               (MCU_Status[1]&0x02)    ||  //��������¶ȱ���
               (MCU_Status[1]&0x01)    ||  //��������������¶ȱ���
              ((JY_Status[0]&0x03)>0)  ||  //������Ե����
              ((JY_Status[0]&0x0C)>0)  ||  //������Ե���� 
               (VCU_Status[5]==2)      ||  //��������2�ȼ�
               (VCU_Status[5]==3)      ||  //��������3�ȼ�
             //(DC_fault_dj>0)         ||  //��ع��ϵȼ�
            
              ((Vspeed >= 50) && IN3)  ||  //ǰ�ſ�����
              ((Vspeed >= 50) && IN2)  ||  //���ſ�����        
             //(Vspeed > 690)              //���ٱ���  
               (Vspeed > e_limit_pSpeed*10)//���ٱ���              
            )
       )     BUZZ = 0;//!FLASH;
    else     BUZZ = 1;
 
    
    //���� С�ƿ��رպ� 
    if (LED15) { //IN11
        OC1RS = e_backlight;
    } else {
        OC1RS = 0;
    }

    /*if (M_ON) {
        PO1 = 0;
        PO2 = 0;
    } else {
        PO1 = 1;
        PO2 = 1;
    }
    PO1 = (M_ON || wake_up1 || wake_up2);
    PO2 = (DMC_Gear == 2);*/


}

//ģ��
void BCAN_SendCtl(void) {
    CAN_MESSAGE message_POUT;
    SW_DATA     temp;
    
    message_POUT.id = 0x6a4;
    message_POUT.data[0] = gCTL[0].byte;
    message_POUT.data[1] = gCTL[1].byte;
    message_POUT.data[2] = gCTL[2].byte;
    message_POUT.data[3] = gCTL[3].byte;
    message_POUT.data[4] = gCTL[4].byte;
    message_POUT.data[5] = gCTL[5].byte;
    
    temp.byte = 0;
    temp.bit0 = ((M_ON && wake_up3) );//|| wake_up2
    temp.bit1 = IN14; //����      
    temp.bit2 = IN15; //��Ъ
    temp.bit3 = IN16; //�쵵
    temp.bit4 = IN21; //��ˮ        
    if (IN14 && IN16)temp.bit1 = 0;
    if (IN21) {
        temp.bit1 = 0;//����
        temp.bit2 = 0;//��Ъ
        temp.bit3 = 0;//�쵵
    }
    message_POUT.data[6]=temp.byte;
    
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
    msg.id      = 0x454;
    msg.len     = 0x08;
    msg.type    = 0x01;
    CAN1_SendMessage(&msg);

}


void PCAN_send_yb1(void) {
    CAN_MESSAGE msg;
    unsigned int  temp1;
    
    msg.data[0] = Vspeed/10;//����
    
    if(DJ_speed>=65534)DJ_speed=20000;
    if(DJ_speed>=20000)temp1=DJ_speed-20000;
    else               temp1=20000-DJ_speed;
    if(temp1>=2500)temp1=2500;
    msg.data[1] = temp1/10;//ת��  
    
    msg.data[2] = 0;//ˮ��
    msg.data[3] = 0;//����ѹ��  
    
    temp1=ADV[3]/10;//ǰ��ѹ-��ѹʽ
    if(temp1>=50 && temp1<=300)temp1=(unsigned int)(0.4*(temp1-50));  
    else                       temp1=0;
    msg.data[4]=(unsigned char)(temp1);

    temp1=ADV[4]/10;//����ѹ-��ѹʽ
    if(temp1>=50 && temp1<=300)temp1=(unsigned int)(0.4*(temp1-50));  
    else                       temp1=0;
    msg.data[5]=(unsigned char)(temp1);
  
    msg.data[6] = 0;//����
    msg.data[7] = ADR[0]/5;//������ѹ 
    
    msg.id      = 0x18FB7017;   
    msg.len     = 8;
    msg.type    = 0;
    CAN2_SendMessage(&msg);
    
}

void PCAN_send_yb2(void) {
    CAN_MESSAGE msg;
    SW_DATA     temp;
    unsigned long  temp1;
    
    temp.bit0 = LED22; //�����
    temp.bit1 = LED17; //Զ���
    temp.bit2 = LED19; //ǰ���
    temp.bit3 = LED20; //�����   
    temp.bit4 = LED21; //������  
    temp.bit5 = LED24; //ɲ����
    temp.bit6 = LED4;  //��ת��
    temp.bit7 = LED8;  //��ת��
    msg.data[0] =temp.byte;
    
    temp.bit0 = 0;     //��� 1
    temp.bit1 = 0;     //��� 2
    temp.bit2 = LED18; //��ɲ
    temp.bit3 = 0;     //����   
  //temp.bit4 =((VCU_Status[0]&0x38)==0x00); //�յ�  
    if((VCU_Status[0]&0x38)==0x00)temp.bit4=1;else temp.bit4=0;//�յ� 
    temp.bit5 = 0;     //����
    temp.bit6 = LED1;  //ǰ�ſ��ź�
    temp.bit7 = LED2;  //���ſ��ź�
    msg.data[1] =temp.byte;
    
    temp.bit0 = mKL4;  //ǰӦ���ſ���
    temp.bit1 = mKL6;  //��Ӧ���ſ���
    temp.bit2 = mKL5;  //����ſ���
    temp.bit3 = 0;     //���˶�������   
    temp.bit4 = mKL7;  //ˮλ�����ź�  
    temp.bit5 = LED15; //С�ƿ���
    temp.bit6 = IN24;  //���ȿ���
    temp.bit7 = 0;     //·�Ƶƿ���
    msg.data[2] =temp.byte;
        
    temp.bit0 = 0;     //˾���ȿ���
  //temp.bit1 =(IN14||IN15||IN16); //��ο���
  //temp.bit2 =(IN21);             //ϴ�������� 
    if(fPOUT.BYTES[0]&0x03)temp.bit1=1;else temp.bit1=0;//��ο���
    if(fPOUT.BYTES[0]&0x04)temp.bit2=1;else temp.bit2=0;//ϴ��������
    temp.bit3 = fKL3;  //ABS ����   
    temp.bit4 = 0;     //����������  
    temp.bit5 = !fKL4; //����Ƭĥ�𱨾�
    temp.bit6 = !fKL5; //����Ƭĥ�𱨾�
    temp.bit7 = mKL9;  //���������±���
    msg.data[3] =temp.byte;
    
    temp1=total_miles;
    msg.data[4] = (unsigned char) (temp1);       
    msg.data[5] = (unsigned char) (temp1 >> 8 );
    msg.data[6] = (unsigned char) (temp1 >> 16); 
    msg.data[7] = (unsigned char) (temp1 >> 24);   
    
    msg.id      = 0x18FB7117;   
    msg.len     = 8;
    msg.type    = 0;
    CAN2_SendMessage(&msg);
    
}

void POUT_Clear(void) {
    gCTL[0].byte = 0x00;
    gCTL[1].byte = 0x00;
    gCTL[2].byte = 0x00;
    gCTL[3].byte = 0x00;
    gCTL[4].byte = 0x00;
    gCTL[5].byte = 0x00;
    gCTL[6].byte = 0x00;
    gCTL[7].byte = 0x00;
}

void LED_Clear(void){
    alarm_led[0].byte = 0xff;
    alarm_led[1].byte = 0x00;
    alarm_led[2].byte = 0x00;
    alarm_led[3].byte = 0x00;
}

/*
void PCAN_send_yb(void) {
    CAN_MESSAGE msg;
    SW_DATA     temp;
    unsigned int  temp1;
    unsigned char xz=1;//0����  1��ѹ

    temp.bit0 =(IN11||IN12); //��ѹ�ͱ��� (LED9 || LED11)
    temp.bit1 = IN13; //פ���ź� LED18
    temp.bit2 = mKL12;//�����
    temp.bit3 = mKL15;//ǰ�ſ�   LED1
    temp.bit4 = mKH1; //���ſ�   LED2
    temp.bit5 = M_ON; //����
    temp.bit6 = M_ON; //һ��
    temp.bit7 = 0;
    msg.data[0] =temp.byte;
    
    temp.bit0 = M_PO3; //�����   LED20
    temp.bit1 = F_PO13;//�����   LED22
    temp.bit2 = 0;     //������Ԥ��
    temp.bit3 = 0;     //��������
    temp.bit4 = F_PO6; //��ת��� LED8
    temp.bit5 = F_PO4; //ǰ���   LED19
    temp.bit6 = F_PO9; //Զ���   LED17
    temp.bit7 = F_PO7; //��ת��� LED4
    msg.data[1] =temp.byte; 
    
    msg.data[2] = 0;
    msg.data[3] = (unsigned char)(Vspeed/5); //����
       
if(xz==0){
    temp1=ADR[1];//����ʽ
    if(temp1>10 && temp1<185)temp1=(unsigned int)(57.143*(temp1-10));  
    else                     temp1=0;
    msg.data[4]=(unsigned char)(temp1);
    msg.data[5]=(unsigned char)(temp1>>8);

    temp1=ADR[2];//����ʽ
    if(temp1>10 && temp1<185)temp1=(unsigned int)(57.143*(temp1-10));  
    else                     temp1=0;
    msg.data[6]=(unsigned char)(temp1);
    msg.data[7]=(unsigned char)(temp1>>8);
    
}else {
    
    temp1=ADV[3]/10;//��ѹʽ
    if(temp1>=50 && temp1<=300)temp1=(unsigned int)(40*(temp1-50));  
    else                       temp1=0;
    msg.data[4]=(unsigned char)(temp1);
    msg.data[5]=(unsigned char)(temp1>>8);

    temp1=ADV[4]/10;//��ѹʽ
    if(temp1>=50 && temp1<=300)temp1=(unsigned int)(40*(temp1-50));  
    else                       temp1=0;
    msg.data[6]=(unsigned char)(temp1);
    msg.data[7]=(unsigned char)(temp1>>8);
}
    msg.id      = 0x0C19A7A1;      
    msg.len     = 8;
    msg.type    = 0;
    CAN2_SendMessage(&msg);
    
}
 
void PCAN_send_time(void) {
    CAN_MESSAGE msg;
    static unsigned char bcd[6]={0,0,0,0,0,0,};
    unsigned char i;
    unsigned char sbcd=0;

//msg.data[0]=timer.second;
//msg.data[1]=timer.minute;
//msg.data[2]=timer.hour;
//msg.data[3]=timer.day;
//msg.data[4]=timer.month;
//msg.data[5]=timer.year;  
    
    for(i=0;i<7;i++){    
        sbcd=(unsigned char)(timer.byte[i]>>4);
        sbcd=sbcd*10;
        sbcd+=(unsigned char)(timer.byte[i]&0x0f);      
        bcd[i]=sbcd;     
    }
    msg.data[0] = bcd[6];   //�� 
    msg.data[1] = bcd[5];   //��
    msg.data[2] = bcd[4];   //��
    msg.data[3] = bcd[2];   //ʱ 
    msg.data[4] = bcd[1];   //��    
    msg.data[5] = bcd[0];   //��
    msg.data[6] = 0x00;     
    msg.data[7] = 0x00;
    msg.id      = 0x18EFA5A1;   
    msg.len     = 8;
    msg.type    = 0;
    CAN2_SendMessage(&msg);
    
}

void PCAN_send_speed(void) {
    CAN_MESSAGE msg;
    
    msg.data[0] = 0xff;
    msg.data[1] = 0xff;
    msg.data[2] = 0xff;
    msg.data[3] = 0xff;
    msg.data[4] = 0xff;
    msg.data[5] = 0xff;
    msg.data[6] = 0xff;
    msg.data[7] = Vspeed/10;//pSpeed;
    msg.id      = 0X0CFE6CEE;
    msg.len     = 8;
    msg.type    = 0;
    CAN2_SendMessage(&msg);
      
}

void PCAN_send_mile(void) {
    CAN_MESSAGE   msg;    
    unsigned long temp;
 
    temp=total_miles;
    msg.data[0] = (unsigned char) (temp);       
    msg.data[1] = (unsigned char) (temp >> 8 );
    msg.data[2] = (unsigned char) (temp >> 16); 
    msg.data[3] = (unsigned char) (temp >> 24); 
    temp=single_miles;
    msg.data[4] = (unsigned char) (temp);       
    msg.data[5] = (unsigned char) (temp >> 8 );
    msg.data[6] = (unsigned char) (temp >> 16); 
    msg.data[7] = (unsigned char) (temp >> 24);     
    msg.id      = 0x0C1AA7A1;    
    msg.len     = 8;
    msg.type    = 0;
    CAN2_SendMessage(&msg);

}

void PCAN_send_test(void) {
    CAN_MESSAGE msg;
    
    msg.data[0] = (unsigned char)(QY_TIME);
    msg.data[1] = (unsigned char)(QY_TIME>>8);
    msg.data[2] = (unsigned char)(KYJ_TIME);
    msg.data[3] = (unsigned char)(KYJ_TIME>>8);
    msg.data[4] = (unsigned char)(ADV[6]/10);
    msg.data[5] = (unsigned char)(ADV[6]/10>>8);
    msg.data[6] = (unsigned char)(ADV[5]/10);
    msg.data[7] = (unsigned char)(ADV[5]/10>>8);
    msg.id      = 0X1800FF00;
    msg.len     = 8;
    msg.type    = 0;
    CAN2_SendMessage(&msg);
   
}
*/


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
                fkey[0].byte  = fKEY.BYTES[0];                
                fkey[1].byte  = fKEY.BYTES[1];                  
                fkey[2].byte  = fKEY.BYTES[2];
                fkey[1].bit7  = fADD;
                fFreq = message.data[3]+((unsigned int) message.data[4] << 8);
                fSpeed = message.data[5]+((unsigned int) message.data[6] << 8);
                break;
            case 0x682:
                Mcan_count = 0;
                mKEY.BYTES[0] = message.data[0];
                mKEY.BYTES[1] = message.data[1];
                mKEY.BYTES[2] = message.data[2];
                tkey[0].byte  = mKEY.BYTES[0];                
                tkey[1].byte  = mKEY.BYTES[1];                  
                tkey[2].byte  = mKEY.BYTES[2];
                tkey[1].bit7  = mADD;
                mFreq = message.data[3]+((unsigned int) message.data[4] << 8);
                mSpeed = message.data[5]+((unsigned int) message.data[6] << 8);
                break;
            case 0x683:
                Rcan_count = 0;
                rKEY.BYTES[0] = message.data[0];
                rKEY.BYTES[1] = message.data[1];
                rKEY.BYTES[2] = message.data[2];
                rkey[0].byte  = rKEY.BYTES[0];                
                rkey[1].byte  = rKEY.BYTES[1];                  
                rkey[2].byte  = rKEY.BYTES[2];
                rkey[1].bit7  = rADD;
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
                fMK_Version=message.data[6];//ģ��汾��
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
                mMK_Version=message.data[6];//ģ��汾��
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
                rMK_Version=message.data[6];//ģ��汾��
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

/**************************************************/

unsigned int CAN_BAT_COUNT=0;
unsigned int CAN_DRIVE_COUNT=0;

//�������������� 
unsigned int   DJcontroler_voltage=0;//��������������ѹ
unsigned int   DJcontroler_current=10000; //����������������
unsigned int   DJ_torque=20000; //ת��Torque 
unsigned int   DJ_speed=20000;

unsigned char  DJ_temperature=40;             //��������¶�
unsigned char  DJcontroler_temperature=40;    //��������������¶�
unsigned char  FDJ_temperature=40;            //������¶�
unsigned char  FDJcontroler_temperature=40;   //������������¶�
unsigned char  DR_state=0x80;                 //˾������״̬
unsigned char  KEY_state=0;                   //������״̬
unsigned char  system_state=0;                //ϵͳ����״̬
unsigned int   system_fault=0;                //ϵͳ������

unsigned  int  EngineSpeed=0;
unsigned char  WaterTem=40;
unsigned char  EngineLoad=0;     //������������
unsigned char  urea_high=0;      //����Һλ
unsigned char  speed_st1=0;      //������Ŀ������̤��״̬
unsigned char  speed_st2=0;      //������ʵ������̤��
unsigned char  controler_LIFE=0; //����������Life

unsigned char  traction_st=0;   //ǣ��̤��ٷֱ�
unsigned char  brake_st=0;      //�ƶ�̤��ٷֱ�
unsigned char  engine_oil_press=0;        //����������ѹ��
unsigned char  ambient_air_temperature=40;//�����������¶�
unsigned long  total_fuel=0;     //�������ۼ��ͣ���������

unsigned char  debug_num[8]; //���Բ���1

unsigned int   DJ_torqueST=0; //�������Ŀ��ת��
unsigned int   EngineSpeST=0; //������Ŀ��ת��
unsigned char  instantaneous_fuel=0; //˲̬ȼ�;�����
unsigned int   single_BGLfuel=0;     //С�ưٹ����ͺ�
unsigned int   total_BGLfuel=0;      //�ܼưٹ����ͺ�

unsigned char  KZQversion[7];
unsigned char  FDJversion[7];  //����汾�Ÿ� 3�ֽ�
unsigned char  DJversion[7];   //����汾�Ÿ� 3�ֽ�

unsigned int   anode_R;     //���˶Եؾ�Ե����
unsigned int   negative_R;  //���˶Եؾ�Ե����
unsigned char  eror_R;      //��Ե���ϵȼ�
unsigned char  R_life;      //
unsigned char  R_ID=0XAA;   //����©�籨��

unsigned int   DCDC_SC_voltage=10000;
unsigned int   DCDC_SC_current=32000;
unsigned int   DCDC_SR_voltage=10000;
unsigned char  DCDC_temperature=40;
unsigned char  DCDC_fault=0;         //DCDC������

unsigned int   DCAC_W_current=10000;
unsigned int   DCAC_V_current=10000;
unsigned int   DCAC_U_current=10000;
unsigned char  DCAC_temperature=40;
unsigned char  DCAC_fault=0;   

unsigned char  KT_Status[3];
unsigned char  KT_temp[3]={40,40,40};
unsigned char  KT_ctrl=0;
unsigned char  KT_life=0;
unsigned int   KT_current=10000;
unsigned char  KT_MODE=0;//�յ�ѡ��ģʽ  0�綯 1��ͳ
unsigned char  KT_temp1[3]={60,60,60};//����0.5 ƫ����-30

unsigned int   DC_voltage=0; //��ص�ѹ 
unsigned int   DC_current=10000; //��ص��� 
unsigned char  DC_SOC=0;
unsigned char  DC_Status[6]={0,0,0,0x00,0,0};

unsigned int   Vmax=10000;//������ѹ
unsigned char  Vmax_num;  //������ѹ���
unsigned char  Tmax=40;   //��������¶�
unsigned char  Tmax_num;  //��������¶����
unsigned int   Vmin=10000;//��С�����ѹ
unsigned char  Vmin_num;  //��С�����ѹ��� 
 
unsigned int   CD_current=0; //��ǰ������������
unsigned int   FD_current=10000; //��ǰ�������ŵ����
unsigned char  Tmin=40;          //��͵������¶�
unsigned char  Twater=40;        //��ˮ���¶�
unsigned char  DC_JCQst[2]={0,0}; //��ؽӴ�������Ͽ���ʶ

unsigned char  KT_fuhe=0; //�յ�ʵ�ʹ�������
unsigned char  CAR_MODE=0;//����ģʽ-�Լ�-���-����
unsigned char  XHLC=0;    //�������
unsigned char  TYBJ_state[8]={0,0,0,0,0,0,0,0};//ͨ�ñ�����־

unsigned int   Vpj=10000;//����ƽ����ѹ

unsigned char  Tmax1=40;//��������¶�

unsigned int   anode_R1=0;//���˶Եؾ�Ե����
unsigned int   negative_R1=0;//���˶Եؾ�Ե����

unsigned char  VIN_Status=0;//VIN����״̬
unsigned char  CDZ_temp[4]={40,40,40,40};//������¶�

unsigned int   DC_EDRL=0;  //��ض����
unsigned int   DC_EDDY=0;  //��ض��ѹ
unsigned int   DC_CL_SUM=0;//��ص��崮������
unsigned char  DC_BL_SUM=0;//��ص��岢������ 
unsigned char  DC_WD_SUM=0;//���ϵͳ�¶�̽��

unsigned char  Tmax_box=0;//��������¶����
unsigned char  Tmin_box=0;//��С�������¶����
unsigned char  Vmax_box=0;//������ص�ѹ���
unsigned char  Vmin_box=0;//��С�����ص�ѹ���
unsigned char  Tmin_num=0;//��С�������¶����

unsigned char  DC_style=0;//�������
unsigned char  DC_LengQ=0;//�����ȴ��ʽ

unsigned int   BAT_vol[10]={10000,10000,10000,10000,10000,10000,10000,10000,10000,10000};//�����������ѹ
unsigned int   BAT_num[10]={0,0,0,0,0,0,0,0,0,0};//�����������ѹ���

unsigned char  BAT_temp[10]={40,40,40,40,40,40,40,40,40,40};//�����������¶�
unsigned char  BAT_num1[10]={0,0,0,0,0,0,0,0,0,0};//�����������¶ȱ��

unsigned char  MHQ_DCBOX=0;//�����������
unsigned char  MHQ_YJJB=0; //�����ϵͳԤ������
unsigned char  MHQ_fault=0;//�����������

unsigned char  MHQ_TIME=0;//����Уʱ
unsigned char  YW_Status[6]={0,0,0,0,0,0};//������

unsigned char  VCU_Status[10]={0x00,0x02,0x00,0x00,0x03,0x00,0x00,0x00,0x00,0x00,};
unsigned long  VCU_fault;//ϵͳ������
unsigned char  VCU_Cmd[5]={0x55,0x55,0xAA,0x55,0x55};//����ָ��
unsigned char  MCU_Num[5];//����������
unsigned char  MCU_Status[10];//�������״̬
unsigned long  MCU_fault;//ϵͳ������

unsigned char  QB_Status[5];
unsigned int   QB_Power=200;//�������
unsigned char  QB_temperature=40;//����¶�
unsigned char  QB_controler_temperature=40;//����������¶�
unsigned int   QB_controler_voltage;//ĸ�ߵ�ѹ
unsigned int   QB_speed;//ת��

unsigned char  YB_Status[5];
unsigned int   YB_Power=200;//�������
unsigned char  YB_temperature=40;//����¶�
unsigned char  YB_controler_temperature=40;//����������¶�
unsigned int   YB_controler_voltage;//ĸ�ߵ�ѹ
unsigned int   YB_speed;//ת��

unsigned char  DCDC_Status[5];//����״̬
unsigned int   DCDC_MX_voltage;//ĸ�ߵ�ѹ

unsigned int   JY_R;//��Ե����
unsigned char  JY_Status[5]; //������Ե����  ������Ե����
unsigned int   CD_voltage;   //�����������ѹ
unsigned char  Vmax_xt_num;  //��ߵ�ѹ�����ϵͳ��
unsigned char  Vmin_xt_num;  //��͵�ѹ�����ϵͳ��   
unsigned char  DC_fault_dj;  //BMS ���ϵȼ�

unsigned char  Tpj=40; //��ϵͳƽ���¶�
unsigned char  Tmax_xt_num;//����¶���ϵͳ��
unsigned char  Tmin_xt_num;//����¶���ϵͳ��               
unsigned char  Tmax_tz_num;//����¶�̽�����          
unsigned char  Tmin_tz_num;//����¶�̽�����  
unsigned char  DC_cd_sum;//�ɳ�索��װ�ù������� N1
unsigned long  DC_fault;//ϵͳ������
unsigned int   MAX_cd_voltage; //��߳���ѹ
unsigned char  DC_control;//����
unsigned char  BAT_sum;//������ 
unsigned int   BAT_Vmax_bj; //�����ѹ��������
unsigned int   BAT_Vmax_qd; //�����ѹ�ж�����
unsigned int   BAT_Vmin_bj; //�����ѹ��������
unsigned int   BAT_Vmin_qd; //�����ѹ�ж�����
unsigned int   DC_Max_ed_cd_current; //���������
unsigned int   DC_Max_ed_fd_current; //����ŵ����           





void __attribute__((__interrupt__, auto_psv)) _C2Interrupt(void) {
    unsigned char i = 0;
    CAN_MESSAGE msg;
    
    IEC2bits.C2IE = 0; 
    
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
        ECU_TIME=0;
        switch (msg.id) {
            case 0x0CFFC9D0://����������1
                VCU_Status[0]=msg.data[0];//����������״̬ �������״̬ ��ѹ����״̬���� �ƶ�ϵͳ����
                VCU_Status[1]=msg.data[1];//����״̬
                VCU_Status[2]=msg.data[2];//����ģʽ       
                Vspeed=((unsigned int)msg.data[4]<<8) + msg.data[3];//����
                VCU_Status[3]=msg.data[5];//��λ �ƶ��� ������״̬
                VCU_Status[4]=msg.data[6];//���״̬             
                VCU_Status[5]=msg.data[7];//��߱����ȼ�             
                break;
            case 0x0CFFC8D0://����������2 
                traction_st=msg.data[0];   //ǣ��̤��ٷֱ�
                brake_st=msg.data[1];      //�ƶ�̤��ٷֱ�
                VCU_Status[6]=msg.data[2]; //������������ N 
                VCU_fault=(((unsigned long)msg.data[6]<<24)+
                           ((unsigned long)msg.data[5]<<16)+
                           ((unsigned long)msg.data[4]<<8) + 
                                           msg.data[3]);   //ϵͳ������-�������ϴ����б�
                VCU_Status[7]=msg.data[7]; //�����������
                break;    
            case 0x0CFFCAD0://����������3      
                VCU_Cmd[0]=msg.data[0];   //�ͱÿ���������ָ��
                VCU_Cmd[1]=msg.data[1];   //���ÿ���������ָ��            
                VCU_Cmd[2]=msg.data[2];   //�յ���Ƶ������ָ��            
                VCU_Cmd[3]=msg.data[3];   //DC/DC ����ָ��   
                VCU_Status[8]=msg.data[4];//DC/DC ״̬           
                VCU_Status[9]=msg.data[5];//DCDC �¶ȱ���   ״̬����   
                break;
            case 0x18F501F0://���������                
                MCU_Num[0]=msg.data[0];    //����������
                MCU_Status[0]=msg.data[1]; //�������״̬
                DJ_temperature=msg.data[2];             //��������¶�
                DJcontroler_temperature=msg.data[3];    //��������������¶�
                DJcontroler_voltage=((unsigned int)msg.data[5]<<8) + msg.data[4];//��������������ѹ
                DJcontroler_current=((unsigned int)msg.data[7]<<8) + msg.data[6]; //����������������
                break;                
            case 0x18F502F0://����״̬ 2      
                MCU_Num[1]=msg.data[0];    //����������
                DJ_speed =((unsigned int)msg.data[2]<<8) + msg.data[1];//���ת��
                DJ_torque=((unsigned int)msg.data[4]<<8) + msg.data[3];//���ת��
                break;  
            case 0x18F503F0://����״̬ 2      
                MCU_Num[2]=msg.data[0];    //����������
                MCU_Status[1]=msg.data[1]; //��������������¶ȱ���  ����¶ȱ���
                MCU_Num[3]=msg.data[2];    //��������������� N2    
                MCU_fault=(((unsigned long)msg.data[6]<<24)+
                           ((unsigned long)msg.data[5]<<16)+
                           ((unsigned long)msg.data[4]<<8) + 
                                           msg.data[3]);   //ϵͳ������-�������ϴ����б�
                break;        
            case 0x1801A79A://���ÿ�������Ϣ
                QB_Status[0]=msg.data[0]; //��·���������� ����¶ȱ��� ����������¶ȱ��� ͨѶ���� ת�Ӵ��������� �������״̬
                QB_Power=msg.data[1];     //�������
                QB_temperature=msg.data[2];           //����¶�
                QB_controler_temperature=msg.data[3]; //����������¶�
                QB_controler_voltage=(((unsigned int)msg.data[5]<<8) + msg.data[4]);     //ĸ�ߵ�ѹ
                QB_speed=(((unsigned int)msg.data[7]<<8) + msg.data[6]);                 //ת��
                break;        
            case 0x1801A79B://�ͱÿ�������Ϣ 
                YB_Status[0]=msg.data[0]; //��·���������� ����¶ȱ��� ����������¶ȱ��� ͨѶ���� ת�Ӵ��������� �������״̬
                YB_Power=msg.data[1];     //�������
                YB_temperature=msg.data[2];           //����¶�
                YB_controler_temperature=msg.data[3]; //����������¶�
                YB_controler_voltage=(((unsigned int)msg.data[5]<<8) + msg.data[4]);     //ĸ�ߵ�ѹ
                YB_speed=(((unsigned int)msg.data[7]<<8) + msg.data[6]);                 //ת��
                break;      
            case 0x1801A79C://DCDC ��������Ϣ
                DCDC_Status[0]=msg.data[0];   //����״̬  ͨѶ���ϱ���
                DCDC_Status[1]=msg.data[1];   //�¶ȹ���  ������� �����ѹ ���Ƿѹ �����ѹ ����Ƿѹ �����· Ӳ������       
                DCDC_temperature=msg.data[2]; //�����¶�
                DCDC_SC_current=(((unsigned int)msg.data[4]<<8) + msg.data[3]);//�������
                DCDC_SC_voltage=msg.data[5]; //�����ѹ
                DCDC_MX_voltage=(((unsigned int)msg.data[7]<<8) + msg.data[6]);//ĸ�ߵ�ѹ
                break;         
            case 0x1801A79D://��Ե�������Ϣ   
                JY_R=(((unsigned int)msg.data[1]<<8) + msg.data[0]);//��Ե����
                JY_Status[0]=msg.data[2]; //������Ե����  ������Ե����
                anode_R=   (((unsigned int)msg.data[4]<<8) + msg.data[3]);  //���˶Եؾ�Ե����
                negative_R=(((unsigned int)msg.data[6]<<8) + msg.data[5]);  //���˶Եؾ�Ե����
                JY_Status[1]=msg.data[7]; //��Ԫ����״̬ 0��δ������1����������2������3���޲���
                break;   
            case 0x18FF217B://���������������Ϣ     
                DC_Status[0] = msg.data[0];//BMS ϵͳ����״̬ �ڲ�����״̬ ���״̬���� ����״̬
                DC_voltage = (((unsigned int) msg.data[2] << 8) + msg.data[1]); //��ص�ѹ 
                DC_current = (((unsigned int) msg.data[4] << 8) + msg.data[3]); //��ص��� 
                DC_SOC = msg.data[5];
                CD_voltage = (((unsigned int) msg.data[7] << 8) + msg.data[6]); //�����������ѹ 
                break;  
            case 0x18FF227B:     
                DC_Status[1] = msg.data[0];//
                DC_Status[2] = msg.data[1];// 
                DC_Status[3] = msg.data[2];//        
                DC_Status[4] = msg.data[3];//  
                DC_style = msg.data[4];//���ش���װ������
                Vmax_xt_num = msg.data[5];//��ߵ�ѹ�����ϵͳ��
                Vmin_xt_num = msg.data[6];//��͵�ѹ�����ϵͳ��   
                DC_fault_dj = msg.data[7];//BMS ���ϵȼ�
                break;         
            case 0x18FF247B://������ѹ 1     
                Vmax = (((unsigned int) msg.data[1] << 8) + msg.data[0]); //������ѹ
                Vmin = (((unsigned int) msg.data[3] << 8) + msg.data[2]); //��С�����ѹ
                Vpj =  (((unsigned int) msg.data[5] << 8) + msg.data[4]); //����ƽ����ѹ
                Vmax_num = msg.data[6]; //��ߵ�ѹ��ص������
                Vmin_num = msg.data[7]; //��͵�ѹ��ص������
                break;        
            case 0x18FF257B://������¶� 1         
                Tmax     = msg.data[0]; //����¶�ֵ
                Tmin     = msg.data[1]; //����¶�ֵ
                Tpj      = msg.data[2]; //��ϵͳƽ���¶�
                Tmax_xt_num = msg.data[3];//����¶���ϵͳ��
                Tmin_xt_num = msg.data[4];//����¶���ϵͳ��               
                Tmax_tz_num = msg.data[5];//����¶�̽�����          
                Tmin_tz_num = msg.data[6];//����¶�̽�����           
                break;      
            case 0x18FFA97B://��������Ϣ        
                DC_Status[5] = msg.data[0];//����ȽӴ������� ���Ӵ�������
                DC_cd_sum = msg.data[1];//�ɳ�索��װ�ù������� N1
                DC_fault=(((unsigned long)msg.data[5]<<24)+
                          ((unsigned long)msg.data[4]<<16)+
                          ((unsigned long)msg.data[3]<<8) + 
                                          msg.data[2]);   //�ɳ�索��װ�ù��ϴ����б�
                break;                
            case 0x13CC16B2://�������㲥֡             
                MAX_cd_voltage = (((unsigned int) msg.data[1] << 8) + msg.data[0]); //��߳���ѹ
                CD_current = (((unsigned int) msg.data[3] << 8) + msg.data[2]); //ʵ��Ҫ������� 
                DC_control = msg.data[4];//����
                BAT_sum = msg.data[5];//������ 
                break;        
            case 0x104C1991://BMS ϵͳ���� 1     
                BAT_Vmax_bj = (((unsigned int) msg.data[1] << 8) + msg.data[0]); //�����ѹ��������
                BAT_Vmax_qd = (((unsigned int) msg.data[3] << 8) + msg.data[2]); //�����ѹ�ж�����
                BAT_Vmin_bj = (((unsigned int) msg.data[5] << 8) + msg.data[4]); //�����ѹ��������
                BAT_Vmin_qd = (((unsigned int) msg.data[7] << 8) + msg.data[6]); //�����ѹ�ж�����
                break;        
            case 0x104C1992://BMS ϵͳ���� 2           
                DC_Status[6] = (((unsigned int) msg.data[1] << 8) + msg.data[0]);//�����ѹ�����
                DC_Max_ed_cd_current = (((unsigned int) msg.data[3] << 8) + msg.data[2]); //���������
                DC_Max_ed_fd_current = (((unsigned int) msg.data[5] << 8) + msg.data[4]); //����ŵ����           
                DC_EDRL = (((unsigned int) msg.data[7] << 8) + msg.data[6]); //�����
                break;           
  
            default:
                break;
        }
    }
    C2INTF = 0; /* the individual flag register cleared */
    C2RX0CONbits.RXFUL = 0;
    IFS2bits.C2IF = 0;
    IEC2bits.C2IE = 1; 
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
    static unsigned int can1 = 0, can2 = 0;
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
    if (delay_5s > 0)  delay_5s--; //��ʱ������  

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
        
              if(can2==0){
                 can2=1;
                 //if(MHQ_TIME==0xAA){MHQ_TIME=0;PCAN_send_time();}//ʱ��        
        }else if(can2==1){
                 can2=2;
                 //PCAN_send_yb();//��ѹ 
        }else if(can2==2){
                 can2=3;
                 //PCAN_send_speed();//����
        }else if(can2==3){
                 can2=0;
               //PCAN_send_mile();//���  
               //PCAN_send_test();//�Ǳ������
        }
                
        //�����ۼ����
        //if (pSpeed > 0) {//���ٴ���0ʱ���ۼ�
        //    mile = mile + (float) (pSpeed / 3.6 * 0.1);
        if (Vspeed/10 > 0) {//���ٴ���0ʱ���ۼ�
            mile = mile + (float) (Vspeed/10 / 3.6 * 0.1); 
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
      //if (Rcan_count >= CAN_TIME)Rcan_count = CAN_TIME;
      //else Rcan_count++;
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
        if(BAT24V_count>= BAT24_TIME)BAT24V_count= BAT24_TIME;
        else BAT24V_count++;
        if (ECU_TIME   >= CAN_TIME)ECU_TIME   = CAN_TIME;
        else ECU_TIME++;
        if(  QY_count  >= CAN_TIME)QY_count = CAN_TIME;
        else QY_count++;
        //if (Hcan_count >= CAN_TIME)Hcan_count = CAN_TIME;
        //else Hcan_count++;
        //if (Jcan_count >= CAN_TIME)Jcan_count = CAN_TIME;
        //else Jcan_count++;
        //if (Ccan_count >= CAN_TIME)Ccan_count = CAN_TIME;
        //else Ccan_count++;
        //if (Qcan_count >= CAN_TIME)Qcan_count = CAN_TIME;
        //else Qcan_count++;
        //if (Ycan_count >= CAN_TIME)Ycan_count = CAN_TIME;
        //else Ycan_count++;
      
        
        if (cnt4 >= 9) {//1s
            cnt4 = 0;
            F1000ms = 1;
            FLASH_1s = !FLASH_1s;
            //PCAN_send_mile();
            //���5�룬10����ѭ��
            //if (DMC_Rpm * 0.5 < 16300) count7 = 0;
            //else count7++;

            if ((count7 > 0) && (count7 < 6)) {
                F5s = 1;
            } else if (count7 < 605) {
                F5s = 0;
            } else count7 = 0;
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
    _T5IF = 0;
}

