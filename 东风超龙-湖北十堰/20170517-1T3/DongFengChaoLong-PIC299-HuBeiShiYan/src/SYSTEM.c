#include "SYSTEM.h"
//#include "LOGO.h"
unsigned int delay_cnt;
unsigned int delay_5s;
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
unsigned int  PT1000[56][3]={
    {1155,1159,40},//40��
    {1159,1163,41},
    {1163,1166,42},
    {1166,1170,43},
    {1170,1174,44},
    {1174,1178,45},
    {1178,1182,46},
    {1182,1186,47},
    {1186,1190,48},
    {1190,1193,49},
    
    {1193,1197,50},
    {1197,1201,51},
    {1201,1205,52},
    {1205,1209,53},
    {1209,1213,54},
    {1213,1217,55},
    {1217,1220,56},
    {1220,1224,57},
    {1224,1228,58},
    {1228,1232,59},
    
    {1232,1236,60},
    {1236,1240,61},
    {1240,1243,62},
    {1243,1247,63},
    {1247,1251,64},
    {1251,1255,65},
    {1255,1259,66},
    {1259,1263,67},
    {1263,1266,68},
    {1266,1270,69},
    
    {1270,1274,70},
    {1274,1278,71},
    {1278,1282,72},
    {1282,1286,73},
    {1286,1289,74},
    {1289,1293,75},
    {1293,1297,76},
    {1297,1301,77},
    {1301,1305,78},
    {1305,1308,79},
    
    {1308,1312,80},
    {1312,1316,81},
    {1316,1320,82},
    {1320,1324,83},
    {1324,1328,84},
    {1328,1331,85},
    {1331,1335,86},
    {1335,1339,87},
    {1339,1343,88},
    {1343,1347,89},
    
    {1347,1350,90},
    {1350,1354,91},
    {1354,1358,92},
    {1358,1362,93},
    {1362,1366,94},
    {1366,1369,95},
};
//ϵͳ��ʼ������

void System_Init(void) {
    unsigned char i,j;
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
        } else {
            F_PO6 = 0;
            F_PO7 = 0;
        }
            T_PO15=F_PO7; //��ת���
            T_PO2 =F_PO6; //��ת���
            LED4  =F_PO7; //��ת�򱨾�
            LED8  =F_PO6; //��ת�򱨾�   
            BUZZ = !FLASH;//ת�����
            
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
            T_PO15=F_PO7; //��ת���
            T_PO2 =F_PO6; //��ת���
            LED4  =F_PO7; //��ת�򱨾�
            LED8  =F_PO6; //��ת�򱨾�  
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
    
/*
    //������
    for(j=0;j<7;j++){
        for(i=0;i<50;i++){
            Battery_Voltage[j][i]=1000;
        }
    }
    Battery_Voltage[0][0]=5000;
    Battery_Voltage[0][1]=5400;
    Battery_Voltage[1][0]=4000;
    Battery_Voltage[1][1]=4300;
    Battery_Voltage[6][0]=3000;
    Battery_Voltage[6][1]=3200;
    
    Battery_Voltage_Sum[0]=50; //��ص����ѹÿ������
    Battery_Voltage_Sum[1]=45; 
    Battery_Voltage_Sum[2]=40;
    Battery_Voltage_Sum[3]=35;
    Battery_Voltage_Sum[4]=30;
    Battery_Voltage_Sum[5]=25;
    Battery_Voltage_Sum[6]=20;
    
    Battery_Temp_Sum[0]=10;    //��ص����¶�ÿ������
    Battery_Temp_Sum[1]=9;
    Battery_Temp_Sum[2]=8;
    Battery_Temp_Sum[3]=7;
    Battery_Temp_Sum[4]=6;
    Battery_Temp_Sum[5]=5;
    Battery_Temp_Sum[6]=4;
    
    DC_JH_Status[0][0]=0x80;//��ؾ���״̬ ģ����  1-48 ��
    DC_JH_Status[0][1]=0x40;
    DC_JH_Status[0][2]=0x20;
    DC_JH_Status[0][3]=0x10;
    
    DC_JH_Status[1][0]=0x08;
    DC_JH_Status[1][1]=0x04;
    DC_JH_Status[1][2]=0x02;
    DC_JH_Status[1][3]=0x01;
    
    DC_JH_Status[2][0]=0x18;
    DC_JH_Status[2][1]=0x24;
    DC_JH_Status[2][2]=0x42;
    DC_JH_Status[2][3]=0x81;
    
    DC_JH_Status[3][0]=0x81;
    DC_JH_Status[3][1]=0x42;
    DC_JH_Status[3][2]=0x24;
    DC_JH_Status[3][3]=0x18;
    
    DC_JH_Status[4][0]=0x81;
    DC_JH_Status[4][1]=0x81;
    DC_JH_Status[4][2]=0x81;
    DC_JH_Status[4][3]=0x81;
    
    DC_JH_Status[5][0]=0x18;
    DC_JH_Status[5][1]=0x18;
    DC_JH_Status[5][2]=0x18;
    DC_JH_Status[5][3]=0x18;
    
    DC_JH_Status[6][0]=0xff;
    DC_JH_Status[6][1]=0x55;
    DC_JH_Status[6][2]=0xff;
    DC_JH_Status[6][3]=0x55;
 */
    
    
}

void Count_ADR(void) {
    float ad = 4096;
    //��ѹ�ʹ������ɼ�  ADV[]��ʵ�ʵĵ�ѹ*1000
    //ADV[1] = (unsigned int) (read_ADR(1) / ad * 5000);
    //ADV[2] = (unsigned int) (read_ADR(2) / ad * 5000);
    //ADV[3] = (unsigned int) (read_ADR(3) / ad * 5000);
    //ADV[4] = (unsigned int) (read_ADR(4) / ad * 5000);
    ADV[5] = (unsigned int) (read_ADR(5) / ad * 5000);
    ADV[6] = (unsigned int) (read_ADR(6) / ad * 5000);
    //���ص�ѹ    
    ADR[0] = (unsigned int) (550.0 * read_VOL() / ad); //ʵ�ʵ�ѹ�Ŵ�10��   //(read_VOL() - 1300)*10 / 76 + 180;
    if (ADR[0] >= 225) BAT24V_count = 0;
    //�����ʹ������ɼ�  ADR[]��ʵ�ʵ���ֵ
    //ADR[1] = (unsigned int) (100.0 * read_ADR(1) / (ad - read_ADR(1))); //((read_ADR(1) / ad * 100) / (1 - read_ADR(1) / ad));

    ADR[1] = (unsigned int) (1000.0 * read_ADR(1) / (ad - read_ADR(1)));
    ADR[2] = (unsigned int) (100.0 * read_ADR(2) / (ad - read_ADR(2)));
    ADR[3] = (unsigned int) (100.0 * read_ADR(3) / (ad - read_ADR(3)));
    ADR[4] = (unsigned int) (100.0 * read_ADR(4) / (ad - read_ADR(4)));
  //ADR[5] = (unsigned int) (100.0 * read_ADR(5) / (ad - read_ADR(5)));
  //ADR[6] = (unsigned int) (100.0*read_ADR(6)/(ad-read_ADR(6)));
    if (ADR[1] > 2000)ADR[1] = 2000;      
    if (ADR[2] > 1000)ADR[2] = 0;       
    if (ADR[3] > 1000)ADR[3] = 0;      
    if (ADR[4] > 1000)ADR[4] = 0;  
  //if (ADR[5] > 1000)ADR[5] = 0;
  //if (ADR[6] > 1000)ADR[6] = 0;
  

}

    unsigned int  QY_TIME=0;  //��ѹ��ʱ����
    unsigned int  KYJ_TIME=0; //��ѹ����ʱ����
    unsigned char QY_OUT_EN=0;//��ѹ�ⲿʹ�ܿ���
    static unsigned char KYJ_EN=0;
    static unsigned char QY_EN=0;    
void SYSTME_Logic(void) {
    //static unsigned char KYJ_EN=0;
    //static unsigned char QY_EN=0;
 // F_PO1  = (IN16 && M_ON);                    //��ο쵵
 // F_PO2  = (IN14 && M_ON);                    //�������
 // F_PO3  = (IN21 && M_ON);                    //��ˮ���
    F_PO4  = (IN6 && IN9);                      //��ǰ���
    F_PO5  = (M_ON);                            //Ͷ�һ���Դ
    F_PO6  = (FLASH && (IN5 || wake_up1));      //��ת���
    F_PO7  = (FLASH && (IN1 || wake_up1));      //��ת���
    F_PO8  = (M_ON);                            //������ʾ��Դ 
    F_PO9  = (IN7 && !IN8);                     //Զ�ص�      && !IN8
    F_PO10 = (IN6 && IN9 && IN10);              //�����
    F_PO11 =  F_PO9;                            //Զ���
    F_PO12 = (M_ON);                            //�г���¼�ǵ�Դ 
    F_PO13 = (IN8 && IN6 && IN7);              //����� 
    F_PO14 = (IN6);                             //λ�õ�
    F_PO15 =  F_PO13;                           //�����
    F_PO16 =  0;                                //���ŵ���

//////////////////////////////////////////////////////
//ѹ��   0    0.1    0.2   0.4    0.6    0.8    1   //
//��ѹ  0.5   0.725   1    1.5     2     2.5    3   //
/////////////////////////////////////////////////////
//��������������
//ON-ACC��ON&(��ѹ1&&��ѹ2����8.1��ѹʱ�����3.5��    
//or(��ѹ1or��ѹ2����8.5��ѹʱ������� 
//ON-���ص��������ACC��ON����Чʱ���10��   
        
    if(M_ON){
        if(  QY_count  >= CAN_TIME){//��ʱ�����ϵ����һ��
        //if( (((ADV[6]/10)>253) || ((ADV[5]/10)>253)) && (QY_EN==1) ){ QY_TIME=70;QY_EN=0; }//ON-ACC��ON&(��ѹ1or��ѹ2����8.1��ѹʱ�����3.5�� 
        //if(  ((ADV[6]/10)<237) && ((ADV[5]/10)<237)  )              {            QY_EN=1; }//����ѹ�½���0.75ʱ��Ϊ��Ч   
          if( (((ADV[6]/10)>253) && ((ADV[5]/10)>253)) && (QY_EN==1) ){ QY_TIME=70;QY_EN=0; }//ON-ACC��ON&(��ѹ1 && ��ѹ2����8.1��ѹʱ�����3.5��
          if(  ((ADV[6]/10)<237) && ((ADV[5]/10)<237)  )              {            QY_EN=1; }//����ѹ�½���0.75ʱ��Ϊ��Ч           
        }else {QY_TIME=0;QY_EN=0;}
    }else QY_TIME=0;
      
         if(QY_TIME>0){ R_PO2=1;QY_TIME--; }
         else if(M_ON && (((ADV[6]/10)>263) || ((ADV[5]/10)>263)) && (QY_count >= CAN_TIME))R_PO2=1;//(��ѹ1or��ѹ2����8.5��ѹʱ�������
         else         { R_PO2=0;QY_TIME=0; }  
         if(M_ON){ QY_OUT_EN=1; }
    
//��ѹ��ʹ�ܿ��� 
//ON-ACC��ON&(��ѹ1or��ѹ2����6.5��ѹ
//OFF?{����ѹ1&��ѹ2����8.1��ѹ}or(PT1000�ɼ��¶ȣ�90�棩

    if(M_ON){
        if(  QY_count  >= CAN_TIME){//��ʱ�����ϵ����һ��
            if( ((ADV[6]/10)<212) || ((ADV[5]/10)<212) )R_PO4=1;//(��ѹ1or��ѹ2����6.5��ѹ
            if( (((ADV[6]/10)>253) && ((ADV[5]/10)>253)) ||     //(��ѹ1 &��ѹ2����8.1��ѹ
                //(ADR[1]>1308)                                 //(PT1000�ɼ��¶ȣ�80��)
                  (ADR[1]>1347)                                 //(PT1000�ɼ��¶ȣ�90��)             
               )R_PO4=0; 
        }
    }else R_PO4=0;

    R_PO1  = (M_ON);                            //ON�������Դ
    R_PO3  = (M_ON);                            //�����󻬵�Դ                             
    R_PO5  = (M_ON && IN11 && rKL2);            //�����ȵ�Դ
    R_PO6  = (IN4);                             //ST����Դ
    R_PO7  = (M_ON && IN11 && rKL4);            //�����ȵ�Դ
    R_PO8  = (M_ON);                            //��������Դ
    if(Gear==124)R_PO9=1;else R_PO9=0;          //������ 
    R_PO10 = (M_ON);                            //�յ�ON����Դ
    R_PO11 = (mKL15);                           //ǰ��̤����    
    R_PO12 = (M_ON);                            //����Զ�̼�ص�Դ
    R_PO13 = (mKH1);                            //����̤����    
    R_PO14 = (M_ON);                            //��ѹ��������Դ
    R_PO16 =  0;                                //���ŵ���  
    
//��ѹ�����ȿ���   
//ON-ACC��ON&(��ѹ1or��ѹ2����6.5��ѹ��
//OFF?{����ѹ1&��ѹ2����8.1��ѹ}or(PT1000�ɼ��¶ȣ�90�棩��ʱ30S�ϵ� 

    if(M_ON){
       if(  QY_count  >= CAN_TIME){//��ʱ�����ϵ����һ��
         if(( ((ADV[6]/10)<212) || ((ADV[5]/10)<212) ) && R_PO4 ){ R_PO15=1; KYJ_EN=1;}
         if( ( (((ADV[6]/10)>253) && ((ADV[5]/10)>253)) || 
             //(ADR[1]>1308) )  && //PT1000�ɼ��¶ȣ�80��
               (ADR[1]>1347) )  && //PT1000�ɼ��¶ȣ�90��           
                KYJ_EN  
           ){ KYJ_TIME=600;KYJ_EN=0; }  
       }else {KYJ_TIME=0;  KYJ_EN=0;}
    }else   KYJ_TIME=0;
    
    if(KYJ_EN==0){ 
       if(KYJ_TIME>0){          KYJ_TIME--; }
       else          { R_PO15=0;KYJ_TIME=0; }  
    }

    M_PO1  = (mKL2);                            //˾���Ƶ�Դ
    M_PO2  = (F_PO6);                           //�Һ�ת���
    M_PO3  = (M_ON);                            //���ؼ��ON����Դ
    M_PO4  = (rKL6);                            //�ƶ���
    M_PO5  = (IN20 && (Vspeed<10));             //ǰ�ſ��ŵ�ŷ�
    M_PO6  = (M_ON);                            //�űõ�Դ
    M_PO7  = (IN28);                            //ǰ�Ź��ŵ�ŷ�
    M_PO8  = (M_ON);                            //�³���������Դ
    M_PO9  = (IN27 && (Vspeed<10));             //���ſ��ŵ�ŷ�
    M_PO10 = (mKL6);                            //���ӻ���Դ
    M_PO11 = (IN26);                            //���Ź��ŵ�ŷ�
    M_PO12 = (M_ON);                            //�����ȵ�Դ
    M_PO13 = (F_PO14);                          //С�Ƶ�Դ
    M_PO14 = (mKL8);                            //˾�����ȵ�Դ
    M_PO15 = (F_PO7);                           //���ת���
    M_PO16 =  0;                                //���ŵ���


}

void LED_Logic(void) {
    LED3  = 0; //�յ�ָʾ    
    LED5  = 0; //ǰ����ָʾ    
    LED23 = 0; //������
    
    LED10 = 1; //�ܵ�Դָʾ     
    
    LED15 = F_PO14; //С��   
    
    LED4  = F_PO7;  //��ת���
    LED8  = F_PO6;  //��ת���   
    
    LED22 = F_PO13; //�����    
    LED17 = F_PO9;  //Զ���     
    
    LED19 = F_PO4;  //ǰ���
    LED20 = F_PO10; //�����    
    
    LED1  = mKL15;  //ǰ�ſ�ָʾ
    LED2  = mKH1;   //���ſ�ָʾ   

    LED18 = rKL8;   //��ɲ
    LED24 = rKL6;   //ɲ��ָʾ      
    
    LED21 = R_PO9;  //������
    if(BAT24V_count >= BAT24_TIME)LED16=1;else LED16=0;//���ص�ѹ��     
    
//////////////////////////////////////////////////////
//ѹ��   0    0.1    0.2   0.4    0.6    0.8    1   //
//��ѹ  0.5   0.725   1    1.5     2     2.5    3   //
/////////////////////////////////////////////////////
    if( //IN11              ||
          M_ON              &&
          ((ADV[6]/10)<200)         
      )LED9=1; else LED9=0; //��ѹ1����0.6MPa ����
    
    if( //IN12              ||
          M_ON              &&   
        ((ADV[5]/10)<200)    
      )LED11=1;else LED11=0;//��ѹ2����0.6MPa ����   
    
    if((DJ_Status[3]>0)||(DJ_Status[4]>0))LED13 = 1;else LED13 = 0; //�������   
    
    if(DC_Status[2]&0x01)LED6=1;else LED6=0; //���״̬
    if(DC_Status[2]&0x02)LED7=1;else LED7=0; //���ǹ����    
    
    //if(DC_Status[1]&0x80)LED12=1;else LED12=0; //SOC�ͱ��� ��Ӧ2.9�汾
    if( (DC_Status[0]==13 )  || // 1 ��
        (DC_Status[0]==63 )  || // 2 ��
        (DC_Status[0]==113)     // 3 ��       
      )LED12=1;else LED12=0; //SOC�ͱ���  ��Ӧ3.0�汾
    
    //if((DC_Status[0]>0)||(DC_Status[1]>0))LED14=1;else LED14=0; //�������ϵͳ���� ��Ӧ2.9�汾
    if((DC_Status[0]>0))LED14=1;else LED14=0; //�������ϵͳ����  ��Ӧ3.0�汾
    //LED14 = 0; //�������ϵͳ����    
    
//������ Ϊ0ʱ�죬Ϊ1ʱ����   
        if (M_ON && (  
               !fKL4 ||   //��ǰĦ��Ƭ����
               !fKL5 ||   //��ǰĦ��Ƭ����
                LED9 ||   //��ѹ1
                LED11||   //��ѹ2
                LED4 ||   //��ת��Ʊ��� 
                LED8 ||   //��ת��Ʊ���
               (Vspeed > 690)  //���ٱ���
            ))BUZZ = !FLASH;//1;//!FLASH_1s;
    else      BUZZ = 1;
    
    //���� С�ƿ��رպ� 
    if (IN6) {
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
    temp.bit0 = ((M_ON && wake_up3) || wake_up2);
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

void PCAN_send_time(void) {
    CAN_MESSAGE msg;
    static unsigned char bcd[6]={0,0,0,0,0,0,};
    unsigned char i;
    unsigned char sbcd=0;

    for(i=0;i<7;i++){    
        sbcd=(unsigned char)(timer.byte[i]>>4);
        sbcd=sbcd*10;
        sbcd+=(unsigned char)(timer.byte[i]&0x0f);      
        bcd[i]=sbcd;     
    }
    msg.data[0] = bcd[0]<<2;//��-������0.25
    msg.data[1] = bcd[1];   //��
    msg.data[2] = bcd[2];   //ʱ
    msg.data[3] = bcd[5];   //��
    msg.data[4] = bcd[4]<<2;//��-������0.25
    msg.data[5] = bcd[6];   //��
    msg.data[6] = 0xFF;
    msg.data[7] = 0xFA; 
    msg.id      = 0x18FEF617;   
    msg.len     = 8;
    msg.type    = 0;
    CAN2_SendMessage(&msg);
    
}

void PCAN_send_yb(void) {
    CAN_MESSAGE msg;
    unsigned int  temp1,temp2;

    msg.data[0] = 0;//�¶�
    msg.data[1] = 0;//����
    msg.data[2] = 0;//��ѹ
    
    temp1=ADV[6]/10;//��ѹ1   
         if(temp1<=50 )temp2=0;
    else if(temp1>=300)temp2=250;
    else               temp2=(temp1-50);
    msg.data[3] = temp2;

    temp1=ADV[5]/10;//��ѹ2   
         if(temp1<=50 )temp2=0;
    else if(temp1>=300)temp2=250;
    else               temp2=(temp1-50);
    msg.data[4] = temp2;
    
    msg.data[5] = 0xff;
    msg.data[6] = 0xff;
    msg.data[7] = 0xff;
    msg.id      = 0x18FF88D0;   
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
    
    msg.data[0] = (unsigned char)(Vspeed);
    msg.data[1] = (unsigned char)(Vspeed>>8);
    msg.id      = 0X18F20001;
    msg.len     = 2;
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
    msg.data[4] = 0; 
    msg.data[5] = 0;
    msg.data[6] = 0;
    msg.data[7] = 0;
    msg.id      = 0x0CD6C217;    
    msg.len     = 8;
    msg.type    = 0;
    CAN2_SendMessage(&msg);

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
    msg.id      = 0x0CD60217;    
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

/*******************�ְ�����*****************/



unsigned char DMC_Status; //�������������״̬
unsigned char DMC_Level; //������������ϼ���
unsigned char DMC_Life; //�������
unsigned int DMC_Torque = 32000; //���ת��
unsigned int DMC_Rpm = 32000; //���ת��
unsigned char DMC_Speed; //����
unsigned char DMC_Gear; //��λ

unsigned int DMC_Voltage; //���������ĸ�ߵ�ѹ
unsigned int DMC_Current = 2000; //���������ĸ�ߵ���
unsigned char DMC_Controller_temp = 40; //����������¶�
unsigned char DMC_Moto_temp = 40; //����¶�
unsigned char DMC_Protect_code; //������������ϴ���
unsigned char DMC_Verison; //����������汾��

/*


unsigned char DMC_Accelerator_percent; //����̤�忪��
unsigned char DMC_Brake_percent; //�ƶ�̤�忪��
unsigned char DMC_Charge; //��ŵ�״̬
unsigned char DMC_GB_Gear; //���굵λ

unsigned int DMQ_Rpm; //���ÿ��������ת��
unsigned int DMQ_Voltage; //���ÿ�����ĸ�ߵ�ѹ
unsigned char DMQ_Current; //���ÿ��������ĸ�ߵ���
unsigned char DMQ_temp = 40; //�����¶�
unsigned char DMQ_Controller_temp = 40; //���ÿ������¶�
unsigned char DMQ_Life; //���ÿ���������
unsigned char DMQ_Status; //���ÿ���������״̬

unsigned char DCDC_Status; //DCDC����״̬
unsigned char DCDC_Temp = 40; //DCDCģ���¶�
unsigned int DCDC_Voltage; //DCDC�����ѹ
unsigned int DCDC_Current = 32000; //DCDC�������
unsigned char DCDC_Code; //DCDC���ϴ���
unsigned char DCDC_Verison; //DCDC�汾��

unsigned int DMY_Rpm; //�ͱÿ��������ת��
unsigned int DMY_Voltage; //�ͱÿ�����ĸ�ߵ�ѹ
unsigned char DMY_Current; //�ͱÿ��������ĸ�ߵ���
unsigned char DMY_Controller_temp = 40; //�ͱÿ������¶�
unsigned char DMY_Life; //�ͱÿ���������
unsigned char DMY_Status; //�ͱÿ���������״̬

unsigned char Air_Status_Flag1; //�յ�״̬1
unsigned char Air_Status_Flag2; //�յ�״̬2
unsigned char Air_Status_Flag3; //�յ�״̬3
unsigned char Air_Indoor_t = 60; //�����¶�
unsigned char Air_Outdoor_t = 60; //�����¶�
unsigned char Air_Set_t = 60; //�趨

unsigned char BMS_Type; //BMS��������
unsigned char Battery_Case_Total_Number; //����������
unsigned char BMS_Unit_Number = 1; //��ع���ϵͳ�ӿص�Ԫ����
unsigned int Battery_Cell_Total_Number; //����ܴ���
unsigned int BMS_Nubmer; //��ع���ϵͳ���

unsigned char Battery_Case_number; //������n
unsigned char Battery_Cell_number; //�����n�ڵ�ش���
unsigned char Battery_Cell_Temp_Number; //������ڵ���¶�̽ͷ����

*/
 
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

/*


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
unsigned char BMU_Comm_Status4; //25-32 BMUͨѶ״̬

unsigned char BMU_Bala_Status1; //1-8   BMU����״̬
unsigned char BMU_Bala_Status2; //9-16  BMU����״̬
unsigned char BMU_Bala_Status3; //17-24 BMU����״̬
unsigned char BMU_Bala_Status4; //25-32 BMU����״̬

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


*/

unsigned char BMU_Number = 24; //BMU��
unsigned char Battery_Pack; //��ر��İ���
//unsigned int Battery_Voltage[12]; //��ص����ѹ
unsigned int Battery_Temp[12]; //��ص����¶�
unsigned char DCDC_Status; //DCDC����״̬

/**************************************************/

unsigned int CAN_BAT_COUNT=0;
unsigned int CAN_DRIVE_COUNT=0;

//�������������� 
unsigned int  DJcontroler_voltage=10000;  //��������������ѹ
unsigned int  DJcontroler_current=10000;  //����������������
unsigned int  DJ_speed=0;
unsigned char DJ_temperature=40;          //��������¶�
unsigned char DJcontroler_temperature=40; //��������������¶�

unsigned char DJ_temperature1=40;         //����¶�
unsigned char DJcontroler_temperature1=40;//����������¶�
unsigned char VCU_Status[10];     //VCU״̬
unsigned char Gear=125;           //��λ
unsigned int  XHLC=0;             //�������
unsigned char DJ_version;         //MCU ����汾��Ϣ
unsigned char DJ_Status[10];      //�������ϵͳ״̬
unsigned char DJ_fault;           //MCU ϵͳ���ϴ���
unsigned int  DJ_Power;           //���ʵʱ�����

unsigned long version=0;          //����汾�Ÿ� 3�ֽ�
unsigned int  DJtorque=0;     //������Ŀ��ת��
unsigned char system_state=0;     //ϵͳ����״̬
unsigned int  system_fault=0;     //ϵͳ������
unsigned char fault_grade=0;      //���ϵȼ�
unsigned char controler_LIFE=0;   //����������Life
  
unsigned char PDX_state[2];        
unsigned char DCDC1_temp=40;
unsigned char DCDC1_fault=0;
unsigned char DCDC2_temp=40;
unsigned char DCDC2_fault=0;
unsigned char DCDC3_temp=40;
unsigned char DCDC3_fault=0;

unsigned char KEY_state[4];  //������״̬  //��λ
unsigned int  traction_st[2];   //����̤��ٷֱ�
unsigned char brake_st[2];      //�ƶ�̤��ٷֱ�

unsigned char JY_life;
unsigned char JY_Status;
unsigned int  anode_R;     //���˶Եؾ�Ե����
unsigned int  negative_R;  //���˶Եؾ�Ե����
unsigned char eror_R;      //��Ե���ϵȼ�
unsigned char R_state[3];  //

unsigned char KZQversion[7];
unsigned char DJversion[7];  //����汾�Ÿ� 3�ֽ�

unsigned char SX_state=0;
unsigned char SX_fault=0;

unsigned int  SX_DCvoltage=0;
unsigned int  SX_DRvoltage=0;
unsigned int  SX_DCcurrent=0;
unsigned int  SX_DRcurrent=0;

unsigned char KT_Status[2];
unsigned char KT_temp[3]={40,40,40};
unsigned long KT_current=100000;
unsigned char KT_life=0;

unsigned int  CDJ_SRvoltage=0;
unsigned int  CDJ_SRcurrent=0;
unsigned int  CDJ_SCvoltage=0;
unsigned int  CDJ_SCcurrent=0;

unsigned int  CDJ_power=0;
unsigned char CDJ_temp=0;
unsigned char CDJ_Status=0;
unsigned char CDJ_fault=0;
unsigned char CDJ_grade=0;
unsigned char CDJ_lift=0;

//��ص�ع�����ر��� 
unsigned int  DC_voltage=0;    //��ص�ѹ 
unsigned int  DC_current=5000; //��ص��� 
unsigned char DC_SOC=0;
unsigned char DC_Status[5];

unsigned int  CD_current=500; //��ǰ������������
unsigned int  FD_current=0;    //��ǰ�������ŵ����
unsigned char DC_fault=0;   //ϵͳ���ϵȼ�
unsigned int  Vaverage=0;   //
unsigned char Tmax=40;      //��������¶�
unsigned char Tmin=40;

unsigned int  DCanode_R;    //���˶Եؾ�Ե����
unsigned int  DCnegative_R; //���˶Եؾ�Ե����
unsigned int  Vmax;         //������ѹ
unsigned int  Vmin;         //��С�����ѹ
 
unsigned char BMU_NUM=7;   //����ģ������
unsigned int  Battery_Voltage[10][50]; //��ص����ѹ
unsigned int  Battery_Voltage_Sum[10]={50,50,50,50,50,50,50,50,50,50}; //��ص����ѹÿ������
unsigned int  Battery_Temp_Sum[10]={10,10,10,10,10,10,10,10,10,10};    //��ص����¶�ÿ������
unsigned char DC_Temp[10][10];
unsigned char DC_JH_Status[10][4];//��ؾ���״̬ ģ����  1-48 ��
unsigned char DC_JY[10];//��Ե����
unsigned char DC_DT_sum;//�����ظ���( ����) 
unsigned char DC_TEMP_sum;//�����¶ȸ���
unsigned char Vmax_num[2];//��ߵ����ѹ���λ��   Vmax_num[1]//��ߵ����ѹ���λ�ã������ر��
unsigned char Vmin_num[2];//��͵����ѹ���λ��   Vmin_num[1]//��͵����ѹ���λ�ã������ر��     
unsigned char Tmax_num[2];//��ߵ����¶�λ��       Tmax_num[1]//��ߵ����¶�λ�ã������¶ȱ��
unsigned char Tmin_num[2];//��͵����¶�λ��       Tmin_num[1]//��͵����¶�λ�ã������¶ȱ��

unsigned char Vmax_box;//��ߵ����ѹ���λ�ã��������
unsigned char Vmin_box;//��͵����ѹ���λ�ã��������
unsigned char Tmax_box;//��ߵ����¶�λ�ã��¶������       
unsigned char Tmin_box;//��͵����¶�λ�ã��¶������  

 DC_DATA  voltage_bat[10];    //�����ص�ѹ
//BMS ֻ���͵�ѹƫ������10�����壬����5��������5��
 
 DC_TEMP  temp_bat[10];//�������¶�
//BMS ֻ�����¶�ƫ������10�����塣
 
//�ͱÿ�����
unsigned int  YB_voltage;
unsigned int  YB_current;  
unsigned char YB_temp;   //�ͱ�ɢ���¶�
unsigned char YB_fault;  //�ͱù�����
//ת�������ã�DC/AC�� ��ѹ�� ���ã�DC/AC����Դ
unsigned int  DCAC_speed[2];//�������ת��
unsigned int  DCAC_current[2];//��������
unsigned char DCAC_temp[2];//�������¶�
unsigned char DCAC_life[2];//�����������ź�
unsigned char DCAC_Status[2];
unsigned char DCAC_fault[2];

unsigned int  DCDC_voltage;
unsigned int  DCDC_current;
unsigned char DCDC_fault;
//���ÿ�����
unsigned int  QB_voltage_IN; 
unsigned int  QB_voltage_OUT;
unsigned int  QB_current;    
unsigned char QB_temp;        
unsigned char QB_fault;      
//�����
unsigned char MHQ_Number;
unsigned char MHQ_Alarm;
unsigned char MHQ_life;
unsigned char MHQ_fault;
         

void __attribute__((__interrupt__, auto_psv)) _C2Interrupt(void) {
    unsigned char i = 0;
    unsigned char j = 0;
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
        ECU_TIME=0;
        switch (msg.id) {
            case 0x18F101D0:
                Vcan_count = 0;
                VCU_Status[0]=msg.data[0];//
                Vspeed=msg.data[2]*10;//
                pSpeed=msg.data[2];//
                Gear=msg.data[3];//��λ״̬
                VCU_Status[1]=msg.data[4];//
                system_fault=msg.data[5];//VCUϵͳ������
                controler_LIFE=msg.data[7];//
                break;
            case 0x18F103D0:
                Vcan_count = 0;
                version=msg.data[0];//VCU �汾��Ϣ
                XHLC=(unsigned char) msg.data[1]+((unsigned int) msg.data[2] << 8);//�������
                traction_st[0]=msg.data[3];//����̤��״̬
                brake_st[0]=msg.data[4];//�ƶ�̤��״̬
                VCU_Status[2]=msg.data[5];//����ģʽ��Ϣ
                VCU_Status[3]=msg.data[6];//�������ֿ�������Ϣ
                VCU_Status[4]=msg.data[7];//�總��ʹ��
                break;
            case 0x18F501F0:               
                Vcan_count = 0;
                DJ_temperature=msg.data[0];//
                DJcontroler_temperature=msg.data[1];//
                DJcontroler_voltage=(unsigned char) msg.data[2]+((unsigned int) msg.data[3] << 8);//������Ƶ��ĸ�ߵ�ѹ
                DJ_version=msg.data[4];//MCU ����汾��Ϣ
                DJ_Status[0]=msg.data[5];//�������ϵͳ״̬
                DJ_Status[1]=msg.data[6];//����ϵͳ���͹���
                DJ_fault=msg.data[7];//MCU ϵͳ���ϴ���
                break;         
            case 0x0CF11F05:  
                Vcan_count = 0;
                traction_st[1]=(unsigned char) msg.data[0]+((unsigned int) msg.data[1] << 8);//���Ÿ���
                DJtorque=(unsigned char) msg.data[2]+((unsigned int) msg.data[3] << 8);//������ת��
                DJ_speed=(unsigned char) msg.data[4]+((unsigned int) msg.data[5] << 8);//���ת��
                DJ_Status[2]=msg.data[6];//��ǰ�����ʵ������״̬
                break;      
            case 0x0CF18D05: 
                Vcan_count = 0;
                DJ_temperature1=msg.data[1];
                DJcontroler_temperature1=msg.data[2];//
                DJ_Status[3]=msg.data[6];
                DJ_Status[4]=msg.data[7];      
                break;       
            case 0x0CF12005: 
                Vcan_count = 0;
                DMC_Voltage=(unsigned char) msg.data[0]+((unsigned int) msg.data[1] << 8);//ĸ�ߵ�ѹ
                DMC_Current=(unsigned char) msg.data[2]+((unsigned int) msg.data[3] << 8);//��������
                DJ_Power=(unsigned char) msg.data[6]+((unsigned int) msg.data[7] << 8);//���ʵʱ�����
                break;       
                
            /*    
            case 0x1CFF1711: 
                Bcan_count = 0;
                Battery_Voltage[msg.data[0]-1][0] = ((unsigned char) msg.data[1]+((unsigned int) msg.data[2] << 8));        
                Battery_Voltage[msg.data[0]-1][1] = ((unsigned char) msg.data[3]+((unsigned int) msg.data[4] << 8));
                Battery_Voltage[msg.data[0]-1][2] = ((unsigned char) msg.data[5]+((unsigned int) msg.data[6] << 8));
                Battery_Voltage_Sum[msg.data[0]-1]=msg.data[7];
                break;  
            
            case 0x1CFF1712: 
                Bcan_count = 0;
                Battery_Voltage[msg.data[0]][3] = ((unsigned char) msg.data[1]+((unsigned int) msg.data[2] << 8));         
                Battery_Voltage[msg.data[0]][4] = ((unsigned char) msg.data[3]+((unsigned int) msg.data[4] << 8));
                Battery_Voltage[msg.data[0]][5] = ((unsigned char) msg.data[5]+((unsigned int) msg.data[6] << 8));
                break;  
             case 0x1CFF1713: 
                Bcan_count = 0;
                Battery_Voltage[msg.data[0]][6] = ((unsigned char) msg.data[1]+((unsigned int) msg.data[2] << 8));         
                Battery_Voltage[msg.data[0]][7] = ((unsigned char) msg.data[3]+((unsigned int) msg.data[4] << 8));
                Battery_Voltage[msg.data[0]][8] = ((unsigned char) msg.data[5]+((unsigned int) msg.data[6] << 8));
                break; 
            case 0x1CFF1714: 
                Bcan_count = 0;
                Battery_Voltage[msg.data[0]][9] = ((unsigned char) msg.data[1]+((unsigned int) msg.data[2] << 8));         
                Battery_Voltage[msg.data[0]][10] = ((unsigned char) msg.data[3]+((unsigned int) msg.data[4] << 8));
                Battery_Voltage[msg.data[0]][11] = ((unsigned char) msg.data[5]+((unsigned int) msg.data[6] << 8));
                break;
            case 0x1CFF1715: 
                Bcan_count = 0;
                Battery_Voltage[msg.data[0]][12] = ((unsigned char) msg.data[1]+((unsigned int) msg.data[2] << 8));         
                Battery_Voltage[msg.data[0]][13] = ((unsigned char) msg.data[3]+((unsigned int) msg.data[4] << 8));
                Battery_Voltage[msg.data[0]][14] = ((unsigned char) msg.data[5]+((unsigned int) msg.data[6] << 8));
                break;
            case 0x1CFF1716: 
                Bcan_count = 0;
                Battery_Voltage[msg.data[0]][15] = ((unsigned char) msg.data[1]+((unsigned int) msg.data[2] << 8));         
                Battery_Voltage[msg.data[0]][16] = ((unsigned char) msg.data[3]+((unsigned int) msg.data[4] << 8));
                Battery_Voltage[msg.data[0]][17] = ((unsigned char) msg.data[5]+((unsigned int) msg.data[6] << 8));
                break;
            case 0x1CFF1717: 
                Bcan_count = 0;
                Battery_Voltage[msg.data[0]][18] = ((unsigned char) msg.data[1]+((unsigned int) msg.data[2] << 8));         
                Battery_Voltage[msg.data[0]][19] = ((unsigned char) msg.data[3]+((unsigned int) msg.data[4] << 8));
                Battery_Voltage[msg.data[0]][20] = ((unsigned char) msg.data[5]+((unsigned int) msg.data[6] << 8));
                break;
            case 0x1CFF1718: 
                Bcan_count = 0;
                Battery_Voltage[msg.data[0]][21] = ((unsigned char) msg.data[1]+((unsigned int) msg.data[2] << 8));         
                Battery_Voltage[msg.data[0]][22] = ((unsigned char) msg.data[3]+((unsigned int) msg.data[4] << 8));
                Battery_Voltage[msg.data[0]][23] = ((unsigned char) msg.data[5]+((unsigned int) msg.data[6] << 8));
                break;
           */    
                
             /*   
             case 0x1CFF5011: 
                Bcan_count = 0;  
                DC_Temp[msg.data[0]-1][0] = msg.data[1];
                DC_Temp[msg.data[0]-1][1] = msg.data[2];
                DC_JH_Status[msg.data[0]-1][0] = msg.data[3];//��ؾ���״̬ ģ����  1-12 ��
                DC_JH_Status[msg.data[0]-1][1] = msg.data[4];//��ؾ���״̬ ģ���� 13-24 ��
                DC_JH_Status[msg.data[0]-1][2] = msg.data[5];//��ؾ���״̬ ģ���� 25-36 ��    
                DC_JH_Status[msg.data[0]-1][3] = msg.data[6];//��ؾ���״̬ ģ���� 37-48 ��
                Battery_Temp_Sum[msg.data[0]-1]= msg.data[7]; 
                //DC_JY[0]        = msg.data[7];//��Ե����
                //DC_JY[msg.data[0]] = msg.data[7];//��Ե����      
                break;   
                
             case 0x1CFF5012: 
                Bcan_count = 0;  
                DC_Temp[msg.data[0]][2] = msg.data[1];
                DC_Temp[msg.data[0]][3] = msg.data[2];
                break;        
             case 0x1CFF5013: 
                Bcan_count = 0;  
                DC_Temp[msg.data[0]][4] = msg.data[1];
                DC_Temp[msg.data[0]][5] = msg.data[2];
                break;   
             case 0x1CFF5014: 
                Bcan_count = 0;  
                DC_Temp[msg.data[0]][6] = msg.data[1];
                DC_Temp[msg.data[0]][7] = msg.data[2];
                break;   
             case 0x1CFF5015: 
                Bcan_count = 0;  
                DC_Temp[msg.data[0]][8] = msg.data[1];
                DC_Temp[msg.data[0]][9] = msg.data[2];
                break; 
            */
                
             case 0x1CFF1911: 
                Bcan_count = 0;  
                DC_Status[3] = msg.data[0];//�̵���״̬ 
                DC_current = (unsigned char) msg.data[1]+((unsigned int) msg.data[2] << 8);//�ܵ���
                DC_voltage = (unsigned char) msg.data[3]+((unsigned int) msg.data[4] << 8);//�ܵ�ѹ                
                DC_SOC = msg.data[5];
                DC_Status[0] = msg.data[6];//�����ֽ�1
                DC_Status[1] = msg.data[7];//�����ֽ�2          
                break;                
             case 0x1CFF1912: 
                Bcan_count = 0;  
                CD_current = (unsigned char) msg.data[0]+((unsigned int) msg.data[1] << 8);//���������
                FD_current = (unsigned char) msg.data[2]+((unsigned int) msg.data[3] << 8);//����ŵ����
                Tmax = msg.data[4];
                Tmin = msg.data[5];   
                DC_Status[2] = msg.data[6]; 
                DC_Status[4] = msg.data[7];   
                break;                  
             case 0x1CFF1913: 
                Bcan_count = 0;  
                DC_DT_sum = msg.data[2];//�����ظ���( ����) 
                DC_TEMP_sum = msg.data[3];//�����¶ȸ���
                Vmax_num[0] = msg.data[4];//��ߵ����ѹ���λ��
                Vmin_num[0] = msg.data[5];//��͵����ѹ���λ��          
                Tmax_num[0] = msg.data[6];//��ߵ����¶�λ��
                Tmin_num[0] = msg.data[7];//��͵����¶�λ��  
                break; 
             case 0x1CFF1914:  
                Bcan_count = 0; 
                Vmax_num[1] = msg.data[0];//��ߵ����ѹ���λ�ã������ر��
                Vmax_box    = msg.data[1];//��ߵ����ѹ���λ�ã��������
                Vmin_num[1] = msg.data[2];//��͵����ѹ���λ�ã������ر��
                Vmin_box    = msg.data[3];//��͵����ѹ���λ�ã��������
                Tmax_num[1] = msg.data[4];//��ߵ����¶�λ�ã�    �����¶ȱ��
                Tmax_box    = msg.data[5];//��ߵ����¶�λ�ã�    �¶������       
                Tmin_num[1] = msg.data[6];//��͵����¶�λ�ã�    �����¶ȱ��
                Tmin_box    = msg.data[7];//��͵����¶�λ�ã�    �¶������              
                break; 
             case 0x1CFF1915: 
                Bcan_count = 0; 
                Vmax = (unsigned char) msg.data[0]+((unsigned int) msg.data[1] << 8);//��ߵ����ѹ
                Vmin = (unsigned char) msg.data[2]+((unsigned int) msg.data[3] << 8);//��͵����ѹ             
                break; 
             case 0x18FEA7A8: //ת�������ã�DC/AC��
                Dcan_count = 0; 
                DCAC_speed[0]   = (unsigned char) msg.data[0]+((unsigned int) msg.data[1] << 8);//�������ת��
                DCAC_current[0] = msg.data[2];//��������
                DCAC_temp[0]    = msg.data[3];//�������¶�
                DCAC_life[0]    = msg.data[4];//�����������ź�
                DCAC_Status[0]  = msg.data[5];//����״̬
                DCAC_fault[0]   = msg.data[6];//���ϴ���
                break;              
             case 0x18019888: //�ͱÿ�����
                Ycan_count = 0; 
                YB_voltage = (unsigned char) msg.data[2]+((unsigned int) msg.data[3] << 8); 
                YB_current = (unsigned char) msg.data[4]+((unsigned int) msg.data[5] << 8);      
                YB_temp    = msg.data[6];//ɢ�����¶�
                YB_fault   = msg.data[7];//���ϴ���
                break;              
             case 0x18FEA5A6: //��ѹ�� ���ã�DC/AC����Դ
                Qcan_count = 0; 
                DCAC_speed[1]   = (unsigned char) msg.data[0]+((unsigned int) msg.data[1] << 8);//�������ת��
                DCAC_current[1] = msg.data[2];//��������
                DCAC_temp[1]    = msg.data[3];//�������¶�
                DCAC_life[1]    = msg.data[4];//�����������ź�
                DCAC_Status[1]  = msg.data[5];//����״̬
                DCAC_fault[1]   = msg.data[6];//���ϴ���
                break;                  
             case 0x1805A89C: //���ÿ�����
                Qcan_count = 0;
                QB_voltage_IN  = (unsigned char) msg.data[0]+((unsigned int) msg.data[1] << 8);//
                QB_voltage_OUT = (unsigned char) msg.data[2]+((unsigned int) msg.data[3] << 8);//
                QB_current     = (unsigned char) msg.data[4]+((unsigned int) msg.data[5] << 8);//
                QB_temp        = msg.data[6];//ɢ�����¶�
                QB_fault       = msg.data[7];//���ϴ��� 
                break;  
             case 0x18FF12F7: //��ѹ��Դ��DC/DC��
                Ccan_count = 0;
                DCDC_voltage  =  (unsigned char) msg.data[0]+((unsigned int) msg.data[1] << 8);//
                DCDC_current  =  (unsigned char) msg.data[2]+((unsigned int) msg.data[3] << 8);//      
                DCDC_Status   =  msg.data[4];//DC/DC ����״̬
                DCDC_fault    =  msg.data[5];//DC/DC ���ϴ���
                break;     
             case 0x1819A1A4: //��Ե�����
                Jcan_count = 0;
                anode_R    = (unsigned char) msg.data[1]+((unsigned int) msg.data[0] << 8);//���Եؾ�Ե����
                negative_R = (unsigned char) msg.data[3]+((unsigned int) msg.data[2] << 8);//���Եؾ�Ե����
                eror_R     =  msg.data[4];//���ϵȼ�
                JY_life    =  msg.data[5];//life
                JY_Status  =  msg.data[6];//����©�籨��
                break;   
             case 0x18FF301D: //��������ϵͳ
                Hcan_count = 0;
                MHQ_Number =  msg.data[0];//������
                MHQ_Alarm  =  msg.data[1];//ϵͳԤ������
                MHQ_life   =  msg.data[6];     
                MHQ_fault  =  msg.data[7];//���ϵȼ� 8.8~8.7  ������ 8.6~8.1
                break;      
            default:
                
                if((msg.id>=0x1CFF1711) && (msg.id<=0x1CFF1721)){//�����ص�ѹ
                    Bcan_count = 0;
                    j=((unsigned char)((msg.id & 0x000000FF))-0x11); 
                    if(j<=2){
                    Battery_Voltage_Sum[msg.data[0]-1]=msg.data[7];
                    }
                        for(i=0;i<3;i++){  
                            Battery_Voltage[msg.data[0]-1][j*3+i] = ((unsigned char) msg.data[i*2+1]+((unsigned int) msg.data[i*2+2] << 8)); 
                        }
                } 
                
                if((msg.id>=0x1CFF5011) && (msg.id<=0x1CFF5015)){//�����ص�ѹ  
                    Bcan_count = 0;
                    j=((unsigned char)((msg.id & 0x000000FF))-0x11); 
                       
                        for(i=0;i<2;i++){
                            DC_Temp[msg.data[0]-1][j*2+i] = msg.data[i+1];
                        }
                    
                    if(j<=2){
                        Battery_Temp_Sum[msg.data[0]-1]=msg.data[7]; 
                        
                        for(i=0;i<4;i++){
                            DC_JH_Status[msg.data[0]-1][i] = msg.data[i+3];//��ؾ���״̬ ģ����  1-48 ��                         
                        }
                    }
                }

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
            F7s=1;
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
        if(M_ON==0){if(QY_TIME>0)QY_TIME--; 
                    QY_count=0; 
                   }
        F50ms = 1;
    } else cnt0++;

    if (cnt1 >= 9) {//100ms
        cnt1 = 0;
        F100ms = 1;
        
              if(can2==0){
                 can2=1;
                 PCAN_send_time();//ʱ��        
        }else if(can2==1){
                 can2=2;
                 PCAN_send_yb();//��ѹ 
        }else if(can2==2){
                 can2=3;
                 PCAN_send_speed();//����
        }else if(can2==3){
                 can2=0;
                 PCAN_send_mile();//���  
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
            if (DMC_Rpm * 0.5 < 16300) count7 = 0;
            else count7++;

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

