#include "SYSTEM.h"
//#include "LOGO.h"
unsigned int delay_cnt;
unsigned int delay_5s;
unsigned int delay_2s;
DATA_BIT gKEY[6];
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
//ϵͳ��ʼ������

void System_Init(void) {
    unsigned char i,j;
    unsigned char count=10;
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
      //LCD_BackLight(7);
        PWR_CTRL_DR = 0;
        PWR_CTRL = 1; 
        
        /*
        if (wake_up1) {//���Σ�ձ�������
            PWR_CTRL_DR = 0;
            PWR_CTRL = 1;
            F_PO14 = kFLASH; //FLASH;
            F_PO15 = kFLASH; //FLASH;
        } else {
            F_PO14 = 0;
            F_PO15 = 0;
        }
            T_PO3  = F_PO14; //��ת���
            T_PO4  = F_PO15; //��ת���
            LED4   = F_PO14; //��ת�򱨾�
            LED8   = F_PO15; //��ת�򱨾�   
            BUZZ   = !(LED8 || LED4);//ת�����
        */    
        
        if (F50ms) {
            F50ms = 0;
            SYSTME_Logic();
            //LED4  = F_PO14; //��ת�򱨾�
            //LED8  = F_PO15; //��ת�򱨾�  
            if(wake_up1==0){LED4=0;LED8=0;} 
          //BUZZ  = !(LED8 || LED4); //ת����� 
            //if(wake_up1)BUZZ  = !FLASH;else BUZZ  = 1; 
            
            LED_Out();
            SW_Input();
            BCAN_SendCtl();
        }

        if (M_ON && wake_up3) break; // �����ON�����������˳�
        
        if (M_ACC){
            disp_LOGO();
            disp_Door();
            LCD_BackLight(7);
            LED10 = 1; //�ܵ�Դָʾ            
        }else{
            LCD_BackLight(0);
            LED10 = 0; //�ܵ�Դָʾ
        }
                
        if ((wake_up1 == 0)&&(wake_up2 == 0)&&(wake_up3 == 0)) {  // 
            F_PO14 = 0;
            F_PO15 = 0;
            T_PO3  = F_PO14; //��ת���
            T_PO4  = F_PO15; //��ת���
            LED4   = F_PO14; //��ת�򱨾�
            LED8   = F_PO15; //��ת�򱨾�  
            BUZZ  = 1;
            
         while( count-- != 0 ) {
            gCTL[0].byte = 0x00;
            gCTL[1].byte = 0x00;
            gCTL[2].byte = 0x00;
            gCTL[3].byte = 0x00;
            gCTL[4].byte = 0x00;
            gCTL[5].byte = 0x00;
            gCTL[6].byte = 0x00;
            gCTL[7].byte = 0x00;
            __delay_us(200);
            BCAN_SendCtl(); 
            }          
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
    TIM5_Init();
    Count_ADR();
    delay_cnt = 100; //����1s��ʱ 
    disp_LOGO();
    while (delay_cnt > 1); //��ʱ1s
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

void Count_ADR(void) {
    float ad = 4096;
    //��ѹ�ʹ������ɼ�  ADV[]��ʵ�ʵĵ�ѹ*1000
    ADV[3] = (unsigned int) (read_ADR(3) / ad * 3500) + 0.3*ADV[3];
    ADV[4] = (unsigned int) (read_ADR(4) / ad * 3500) + 0.3*ADV[4];
    ADV[5] = (unsigned int) (read_ADR(5) / ad * 3500) + 0.3*ADV[5]; 
    ADV[6] = (unsigned int) (read_ADR(6) / ad * 3500) + 0.3*ADV[6];
    //���ص�ѹ    
    ADR[0] = (unsigned int) (550.0 * read_VOL() / ad); //ʵ�ʵ�ѹ�Ŵ�10��   //(read_VOL() - 1300)*10 / 76 + 180;
    if (ADR[0] >= 225) BAT24V_count = 0;
    //�����ʹ������ɼ�  ADR[]��ʵ�ʵ���ֵ
    //ADR[1] = (unsigned int) (100.0 * read_ADR(1) / (ad - read_ADR(1))); //((read_ADR(1) / ad * 100) / (1 - read_ADR(1) / ad));
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

//ǰ��ģ��
if(M_ACC){  //M_ACC||M_ON
   F_PO4 = IN6;   //�����
   F_PO5 = IN24 && !IN6;  //Զ���
   F_PO6 = IN8;   //ǰ���
   F_PO7 = F_PO5; //Զ���
   F_PO8 = F_PO4; //����� 
   F_PO9 = IN7;   //��С�� 
   F_PO10 = IN22; //����
 //F_PO11 = (!IN35 && (Vspeed>50)); //��������Դ      
}else{
   F_PO4 = 0;   //�����
   F_PO5 = 0;   //Զ���
   F_PO6 = 0;   //ǰ���
   F_PO7 = 0;   //Զ���
   F_PO8 = 0;   //����� 
   F_PO9 = 0;   //��С�� 
   F_PO10 = 0;  //����
 //F_PO11 = 0;  //��������Դ
}    
   if(M_ON){//��������Դ
     F_PO11 = (M_ON && !IN35 && (Vspeed>50));
   }else{
     F_PO11 = (M_ACC && !IN35);
   }
 //F_PO11 = ((M_ON && !IN35 && (Vspeed>50)); 
   F_PO12 = M_ACC;//ǰ�˿��ŵ�Դ
   F_PO13 = M_ACC;//��˿��ŵ�Դ
   
  if(wake_up1){ //Σ����������
    F_PO14=FLASH; //kFLASH;     
    F_PO15=FLASH; //kFLASH; 
  }else{
    if((M_ACC||M_ON)&&IN1)F_PO14=FLASH; //��ת�򿪹�
    else                  F_PO14=0; 
    if((M_ACC||M_ON)&&IN5)F_PO15=FLASH; //��ת�򿪹�
    else                  F_PO15=0;    
  }
   
  F_PO16 = 1; //���ŵ���

//��ģ��
if(M_ACC){  //M_ACC||M_ON
   R_PO1 = IN17;   //����յ�
   R_PO6 = 1;      //�綯���Ӿ���Դ
   R_PO10 = F_PO9; //��С�� 
   if(EngineSpeed>=3600)R_PO13 = 1;else R_PO13 = 0;    //������Դ�̵���
}else{
   R_PO1 = 0;  //����յ�
   R_PO6 = 0;  //�綯���Ӿ���Դ
   R_PO10 = 0; //��С�� 
   R_PO13 = 0; //������Դ�̵��� 
}

   if(T_KH1 || T_KL15)R_PO9 = 1;//פ�����ź����
   if(!T_KH1 && !T_KL15)R_PO9 = 0;  
  
   R_PO2 = M_ACC;  //�����ȵ�Դ
   R_PO3 = M_ON;   //������ 
   R_PO4 = M_ACC;  //�г���¼�ǵ�Դ
   R_PO5 = M_ON;   //�����󻬵�Դ
   R_PO7 = M_ACC;  //
   R_PO8 = M_ACC;  // 
   R_PO11 = (M_ON && R_KL2); //��������Դ
   R_PO12 = M_ACC; 
   R_PO14 = M_ACC; 
   R_PO15 = M_ACC;  
   R_PO16 = 1; //���ŵ���
   
//����ģ��
   T_PO1 = (M_ACC && (R_KL2 || IN4));//ɲ����
   T_PO2 = (M_ACC && R_KL8);//������
   T_PO3 = F_PO14; //��ת�򿪹� 
   T_PO4 = F_PO15; //��ת�򿪹�
   T_PO5 =  M_ACC; //���������Դ 
   T_PO13 = M_ACC; //�����ӵ�Դ
   T_PO14 = M_ACC; //˫����Դ 
   T_PO15 = M_ACC; //�������ֵƵ�Դ
   
if(M_ACC){  //M_ACC||M_ON
   T_PO6 = IN13; //·�Ƶ�
   T_PO7 = IN23; //���ӵ�Դ
   T_PO8 = IN9;  //�����
   T_PO9 = IN11; //���1
   T_PO10 = IN12;//���2
   T_PO11 = IN10;//˾������
   T_PO12 = IN29;//�Ķ���
}else{
   T_PO6 = 0; //·�Ƶ�
   T_PO7 = 0; //���ӵ�Դ
   T_PO8 = 0; //�����
   T_PO9 = 0; //���1
   T_PO10 = 0;//���2
   T_PO11 = 0;//˾������
   T_PO12 = 0;//�Ķ���
}
   
//�Ǳ��ڲ����
if(M_ACC||M_ON){
 //if(IN7)PO1=0;else PO1=1; //С�Ƶ�Դ
 //if(IN2)PO2=0;else PO2=1; //Ͷ�һ�LED��Դ
 }else {
   PO1=1;
   PO2=1;
       }
    
}

void LED_Logic(void) {
    LED3  = 0; //�����ƶ�  
    LED5  = 0; //Ԥ��ָʾ    
    LED13 = 0; //���л�ˮ
    LED15 = 0; //���������    
    LED12 = 0; //����������
    LED14 = 0; //OBD����  

    //if (ECU_DM1_double == 1) {
    //    if (((ECU_DM2 >> 6)&0x03) == 0x01)LED14 = 1;
    //    else                               LED14 = 0; //OBD����
    //    if ((ECU_DM2 & 0x03) == 0x01)LED12 = 1;
    //    else                          LED12 = 0; //����������ָʾ
    //} else {
    //    if (((ECU_DM1 >> 6)&0x03) == 0x01)LED14 = 1;
    //    else                              LED14 = 0; //OBDָʾ
    //    if ((ECU_DM1 & 0x03) == 0x01)LED12 = 1;
    //    else                         LED12 = 0; //����������ָʾ
    //}
    
    //if ((ECU_WFI & 0x03) == 0x01) LED13 = 1; //���л�ˮ���� 
    //else                          LED13 = 0;
        
    //������CANͨѶ����
    //if(((ECU_DM1>>2)&0x03)==0x01) LED12=1;//Σ�ձ��� ��
    //if(((ECU_DM1>>2)&0x03)==0)    LED12=0;

    //if(((ECU_DM1>>4)&0x03)==0x01) LED10=1;//STOP  
    //if(((ECU_DM1>>4)&0x03)==0)    LED10=0;

    LED23 = IN13; //������
    
    //���� С�ƿ��رպ� 
    if (IN6)  OC1RS = e_backlight;   
    else      OC1RS = 0;
 
    LED10 = IN5;   //�ܵ�Դָʾ     
     
    LED2  = 0;     //�յ�ָʾ   
    
    LED4  = 0;     //��ת���
    
    LED8  = 0;     //��ת���   
    
    LED22 = IN8;   //�����   
    
    LED17 = IN7;   //Զ���     
    
    LED19 = IN9;   //ǰ���
    
    LED20 = IN10;  //�����    

    LED18 = IN18;  //��ɲ
    
    LED24 = IN11;  //ɲ��ָʾ      
    
    LED21 = IN12;  //������
    
    LED16 = IN33;  //���ص�ѹ��     
    
////////////////////////////////////////////////////////////
//ѹ��   0    0.1    0.2   0.4    0.6    0.8    1    1.2  //
//��ѹ  0.5   0.75    1    1.5     2     2.5    3    3.5  //
////////////////////////////////////////////////////////////
    LED9 = IN30; //��ѹ1����  

    LED11 = IN29; //��ѹ2����   

    LED6 = ((/*EngineSpeed > 3600 &&*/ (((engine_oil_press * 0.4) < 10) || IN31)) && FLASH_1s); //����ѹ������

    LED7 = ((sm_old_value[4] >= 907 || IN32) && FLASH_1s); //ˮ�¸߱���

    LED1 = IN19; //�����ͱ���

    if (0)
        BUZZ = !FLASH;
    else if (
            (IN3 && (Vspeed > 50)) || //ǰ��δ��
            (IN4 && (Vspeed > 50)) || //����δ��  
            (IN2 && (Vspeed > 50))  //����δ��  
            )BUZZ = !kFLASH; //!kFLASH;
    else if (
            (EngineSpeed > 3600 && (((engine_oil_press * 0.4) < 10) || IN31)) || //����ѹ������
            (sm_old_value[4] >= 907 || IN32) || //ˮ�¸߱���>=103              

            (LED9)  || //��ѹ1�ͱ���
            (LED11) || //��ѹ2�ͱ���  
            //( ((fADR[0]/10)>200) || ((fADR[0]/10)<3) )  || //ǰ��ѹ����������
            //( ((fADR[1]/10)>200) || ((fADR[1]/10)<3) )  || //����ѹ����������
            //( ((rADR[1]/10)>200) || ((rADR[1]/10)<3) )  || //ȼ�ʹ���������

            //(!F_KL1)  || //��ǰ��ɲ����Ƭ���������ձ����� 
            //(!F_KL2)  || //��ǰ��ɲ����Ƭ���������ձ�����    
            //(!F_KL5)  || //����ɲ����Ƭ���������ձ�����
            //(!F_KL7)  || //�Һ��ɲ����Ƭ���������ձ�����

            (IN26) || //�˿��ų���Ӧ������     //����
            (IN25) || //�˿��ų���Ӧ�����Ӵ� //����        
            //(T_KL1)   || //����ǰ��Ӧ������       //����
            //(T_KL2)   || //��������Ӧ������       //����

            (IN17) || //ˮλ����
            (IN20) || //���˶���       
            //(LED4)    || //��ת�򿪹�
            //(LED8)    || //��ת�򿪹�
            (Vspeed > 650) //���ٱ��� 
            ) BUZZ = !FLASH_1s; //!FLASH; //1; 
    else
        BUZZ = 1;

    //��������ʱ����0�������������ʱ����1���
    PO1 = 1;
    PO2 = !(EngineSpeed > 4400);
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
    temp.bit0 = ((M_ACC && wake_up2));//(M_ON && wake_up3)|| 
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
    /*
    msg.data[0] = bcd[6];   //�� 
    msg.data[1] = bcd[5];   //��
    msg.data[2] = bcd[4];   //��
    msg.data[3] = bcd[2];   //ʱ 
    msg.data[4] = bcd[1];   //��    
    msg.data[5] = bcd[0];   //��
    msg.data[6] = 0x00;     
    msg.data[7] = 0x00;
    msg.id      = 0x18EFA5A1;   
    */
    msg.data[0] = bcd[0];   //�� 
    msg.data[1] = bcd[1];   //��
    msg.data[2] = bcd[2];   //ʱ
    msg.data[3] = bcd[4];   //�� 
    msg.data[4] = bcd[5];   //��    
    msg.data[5] = bcd[6];   //��
    msg.data[6] = 0xFF;     
    msg.data[7] = 0xAA;
    msg.id      = 0x18FFCA17;       
    
    msg.len     = 8;
    msg.type    = 0;
    CAN2_SendMessage(&msg);
    
}


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

void PCAN_send_speed(void) {
    CAN_MESSAGE msg;
    
    msg.data[0] = 0xff;
    msg.data[1] = 0xff;
    msg.data[2] = 0xff;
    msg.data[3] = 0xff;
    msg.data[4] = 0xff;
    msg.data[5] = 0xff;
    msg.data[6] = 0x00;
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
    msg.id      = 0x18EBFFD7;   //0x0C1AA7A1;    
    msg.len     = 8;
    msg.type    = 0;
    CAN2_SendMessage(&msg);

}

void Pcan_send_yb5(void){
 CAN_MESSAGE   msg; 
 msg.data[0] = 0xAF;
 msg.data[1] = 0xFE;
 msg.data[2] = 0x00;
 msg.data[3] = 0x00;
 msg.data[4] = 0x00;
 msg.data[5] = 0x00;
 msg.data[6] = 0x00;
 msg.data[7] = 0x00;
 msg.id      = 0x18EA0017;      
 msg.len     = 8;
 msg.type    = 0;
 CAN2_SendMessage(&msg);//0x1CFEAF00

}
void Pcan_send_yb6(void){
 CAN_MESSAGE   msg; 
 msg.data[0] = 0xE8;
 msg.data[1] = 0xFD;
 msg.data[2] = 0x00;
 msg.data[3] = 0x00;
 msg.data[4] = 0x00;
 msg.data[5] = 0x00;
 msg.data[6] = 0x00;
 msg.data[7] = 0x00;
 msg.id      = 0x18EA0017; 
 msg.len     = 8;
 msg.type    = 0;
 CAN2_SendMessage(&msg);//0x18FDE800

}

void Pcan_send_yb7(void){
 CAN_MESSAGE   msg;   
 msg.data[0] = 0xE9;
 msg.data[1] = 0xFD;
 msg.data[2] = 0x00;
 msg.data[3] = 0x00;
 msg.data[4] = 0x00;
 msg.data[5] = 0x00;
 msg.data[6] = 0x00;
 msg.data[7] = 0x00;
 msg.id      = 0x18EA0017;       
 msg.len     = 8;
 msg.type    = 0;
 CAN2_SendMessage(&msg);//0x18FDE900 

}

void Pcan_send_yb8(void){
 CAN_MESSAGE   msg;   
 msg.data[0] = 0xEF;
 msg.data[1] = 0xFE;
 msg.data[2] = 0x00;
 msg.data[3] = 0x00;
 msg.data[4] = 0x00;
 msg.data[5] = 0x00;
 msg.data[6] = 0x00;
 msg.data[7] = 0x00;
 msg.id      = 0x18EA0017;     
 msg.len     = 8;
 msg.type    = 0;
 CAN2_SendMessage(&msg);//0x18FEEF00  
 
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

/**************************************************/

unsigned int CAN_BAT_COUNT=0;
unsigned int CAN_DRIVE_COUNT=0;

//�������������� 
unsigned int   DJcontroler_voltage=10000;//��������������ѹ
unsigned int   DJcontroler_current=10000; //����������������
unsigned int   DJ_torque=32000; //ת��Torque 
unsigned int   DJ_speed=0;

unsigned char  DJ_temperature=40;             //��������¶�
unsigned char  DJcontroler_temperature=40;    //��������������¶�
unsigned char  FDJ_temperature=40;            //������¶�
unsigned char  FDJcontroler_temperature=40;   //������������¶�
unsigned char  DR_state=0x80;                 //˾������״̬
unsigned char  KEY_state=0;                   //������״̬
unsigned char  system_state=0;                //ϵͳ����״̬
unsigned int   system_fault=0;                //ϵͳ������

//unsigned  int  EngineSpeed=0;
//unsigned char  WaterTem=40;
unsigned char  EngineLoad=0;     //������������
unsigned char  urea_high=0;      //����Һλ
unsigned char  speed_st1=0;      //������Ŀ������̤��״̬
unsigned char  speed_st2=0;      //������ʵ������̤��
unsigned char  controler_LIFE=0; //����������Life

unsigned char  traction_st=0;   //ǣ��̤��ٷֱ�
unsigned char  brake_st=0;      //�ƶ�̤��ٷֱ�
//unsigned char  engine_oil_press=0;        //����������ѹ��
//unsigned char  ambient_air_temperature=40;//�����������¶�
unsigned long  total_fuel=0;     //�������ۼ��ͣ���������

unsigned char  debug_num[8]; //���Բ���1

unsigned int   DJ_torqueST=0; //�������Ŀ��ת��
unsigned int   EngineSpeST=0; //������Ŀ��ת��
//unsigned char  instantaneous_fuel=0; //˲̬ȼ�;�����
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
unsigned int   DCDC_SC_current=10000;
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

unsigned int   DC_voltage=10000; //��ص�ѹ 
unsigned int   DC_current=10000; //��ص��� 
unsigned char  DC_SOC=0;
unsigned char  DC_Status[6]={0,0,0,0x08,0,0};

unsigned int   Vmax=10000;//������ѹ
unsigned char  Vmax_num;  //������ѹ���
unsigned char  Tmax=40;   //��������¶�
unsigned char  Tmax_num;  //��������¶����
unsigned int   Vmin=10000;//��С�����ѹ
unsigned char  Vmin_num;  //��С�����ѹ��� 
 
unsigned int   CD_current=10000; //��ǰ������������
unsigned int   FD_current=10000; //��ǰ�������ŵ����
unsigned char  DC_fault=0;       //ϵͳ���ϵȼ�
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

unsigned char  YZT_LIFE=0;//����ͨ״̬

//����CAN��Ϣ///////////////////////////////////////////
 unsigned char engine_oil_press=0;
 unsigned char barometric_pressure=0;//��ѹѹ�� 0.5Kpa
 unsigned char ambient_air_temperature=40;//��Χ�����¶�
 unsigned char air_pressure=0;          //����ѹ�� 0.5Kpa
 unsigned  int EngineSpeed=0;
 unsigned char WaterTem=40;
 unsigned int  fuel_rate=0;   //Сʱȼ��������
 unsigned int  instantaneous_fuel=0; //˲̬ȼ�;�����
 unsigned int  battery_voltage=520;
 unsigned int  speed_st=0; //����̤��
 ECU_DTC  ECU_dtc[8];
 unsigned int  ECU_DTC_NUM=0;
 unsigned char ECU_DM1=0;  
 unsigned char ECU_DM2=0;    //OBD�Ʊ��� 
 unsigned char ECU_WFI=0;    //���л�ˮ
 unsigned char SCR_DM1=0;    //SCR����
 unsigned char SCR_DM2=0;    //SCR����
 unsigned char ADBLUE=0;     //����Һλ 
 
 unsigned char ABS_fault=0;//ABS
 unsigned char ABS_DM1=0; 
 unsigned int ABS_DTC_NUM=0;
 ECU_DTC  ABS_dtc[8];

 unsigned long QT_trip_XHL=0;//�����ۼ�����������
 unsigned long QT_total_XHL=0;//�ܵ��ۼ�����������
 unsigned int  QT_SSZL_QH=0;//˲ʱ��������
 unsigned int  QT_SSTJ_QH=0;//˲ʱ�������
 unsigned int  QT_XSZL_QH=0;//Сʱ��������
 unsigned int  QT_XSTJ_QH=0;//Сʱ�������
 unsigned int  QT_KMZL_QH=0;//�ٹ�����������
 unsigned int  QT_KMTJ_QH=0;//�ٹ����������
//̥ѹ��� 
 unsigned char Tire_Press[7]={0,0,0,0,0,0,0};
 unsigned int  Tire_Temp[7]={160*0,160*0,160*0,160*0,160*0,160*0,160*0}; 
 unsigned char Tire_Status[7];
 unsigned char Tire_fault[7]={0x00,0x00,0x00,0x00,0x00,0x00,0x00};
 unsigned char Tire_BK_ST=0;//��̥״̬
 
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
                
            //������ECUϵͳ
            case 0x0cf00400:    
                ECU_TIME=0;    
                EngineSpeed=msg.data[3]+((unsigned int)(msg.data[4])<<8);	  
                break;
            case 0x18feff00: //���л�ˮ���� 
                ECU_WFI=msg.data[0];
                break;
            case 0x18FEEE00: 	  
                ECU_TIME=0;        
                WaterTem=msg.data[0];
                break;
            case 0x18FEEF00://������Һ���/ѹ��   
                engine_oil_press=msg.data[3]; 
                break;
            case 0x18FEF200://ȼ������ 
                fuel_rate=msg.data[0]+((unsigned int)(msg.data[1])<<8);//0.05L/h
                instantaneous_fuel=(((unsigned int)msg.data[3])<<8)+msg.data[2];// 1/512 km/L	 
                break;
            case 0x18FEF600: //��Χ�������� id==0x18FEF600
                barometric_pressure=msg.data[1];//��ѹѹ�� 0.5Kpa
                ambient_air_temperature=msg.data[2];//��Χ�����¶�
                air_pressure=msg.data[3];          //����ѹ�� 0.5Kpa
                break;
            case 0x18FEF700://��ѹ 
                battery_voltage=msg.data[6]+((unsigned int)(msg.data[7])<<8);
                break; 
            case 0x0CF00300:
                speed_st=msg.data[1];
                break;
            case 0x18FECA00: //DM1      //һ������
                ECU_DM1=msg.data[0];//1,2λ�Ƿ��������ϣ�7,8λ��OBD����
                ECU_dtc[0].byte[0]=msg.data[2];
                ECU_dtc[0].byte[1]=msg.data[3];
                ECU_dtc[0].byte[2]=msg.data[4];
                ECU_dtc[0].byte[3]=msg.data[5];
                break;
            case 0x18ECFF00: //DM1 ������ϴ���
                if(msg.data[5]==0xca && msg.data[6]==0xfe && msg.data[7]==0x00){//DM1 PGN
                ECU_DM1_double=1;
                }else{
                ECU_DM1_double=0;
                }
                ECU_DTC_NUM=msg.data[1]+((unsigned int)(msg.data[2])<<8); //����Ϣ��      
                break;        
            case 0x18EBFF00://�������
                if(ECU_DM1_double==1){
                if(msg.data[0]==0x01){   
                ECU_dtc[0].byte[0]=msg.data[3];
                ECU_dtc[0].byte[1]=msg.data[4];
                ECU_dtc[0].byte[2]=msg.data[5];
                ECU_dtc[0].byte[3]=msg.data[6];
                ECU_dtc[1].byte[0]=msg.data[7];//�ڶ���DTC
               }else if(msg.data[0]==0x02){      
                ECU_dtc[1].byte[1]=msg.data[1];
                ECU_dtc[1].byte[2]=msg.data[2];
                ECU_dtc[1].byte[3]=msg.data[3];

                ECU_dtc[2].byte[0]=msg.data[4];//������DTC
                ECU_dtc[2].byte[1]=msg.data[5];
                ECU_dtc[2].byte[2]=msg.data[6];
                ECU_dtc[2].byte[3]=msg.data[7];
               }else if(msg.data[0]==0x03){
                ECU_dtc[3].byte[0]=msg.data[1];//��si��DTC
                ECU_dtc[3].byte[1]=msg.data[2];
                ECU_dtc[3].byte[2]=msg.data[3];
                ECU_dtc[3].byte[3]=msg.data[4];

                ECU_dtc[4].byte[0]=msg.data[5];//�����DTC
                ECU_dtc[4].byte[1]=msg.data[6];
                ECU_dtc[4].byte[2]=msg.data[7];
               }else if(msg.data[0]==0x04){
                ECU_dtc[4].byte[3]=msg.data[1];

                ECU_dtc[5].byte[0]=msg.data[2];//������DTC
                ECU_dtc[5].byte[1]=msg.data[3];
                ECU_dtc[5].byte[2]=msg.data[4];
                ECU_dtc[5].byte[3]=msg.data[5];

                ECU_dtc[6].byte[0]=msg.data[6];//��7��DTC
                ECU_dtc[6].byte[1]=msg.data[7];
               }else if(msg.data[0]==0x05){
                ECU_dtc[6].byte[2]=msg.data[1];
                ECU_dtc[6].byte[3]=msg.data[2];

                ECU_dtc[7].byte[0]=msg.data[3];//��8��DTC
                ECU_dtc[7].byte[1]=msg.data[4];
                ECU_dtc[7].byte[2]=msg.data[5];
                ECU_dtc[7].byte[3]=msg.data[6];
               }
            }
                break;   
            case 0x18FE563D://����Һλ
                ADBLUE=msg.data[0]*0.4;
                break;                
            case 0x18FECA3D://SCR����
                SCR_DM1=msg.data[0];
                break;   
            case 0x1CECFF3D: //DM1 ������ϴ���
                if(msg.data[5]==0xca && msg.data[6]==0xfe && msg.data[7]==0x00){//DM1 PGN
                SCR_DM1_double=1;
                }else{
                SCR_DM1_double=0;
                }   
                break; 
            case 0x1CEBFF3D://�������
                if(SCR_DM1_double==1){
                if(msg.data[0]==0x01){
                SCR_DM2=msg.data[1];//�����01�жϣ�������ǲ��ж�//1,2λ�Ƿ��������ϣ�7,8λ��OBD���� 
                }
            }
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
    if (delay_2s > 0)  delay_2s--; //��ʱ������
    
    if (cnt0 >= 4) {//50ms
        cnt0 = 0;
        BCAN_send_mile();
        BCAN_SendCtl();
        if (M_ON_flag && (wake_up3 )) {//������main������ᵼ����˸Ƶ���쳣wake_up3��0ʱ��M_ON����������0����Ϊ����������ʱ
            LED_Logic();
            LED_Out();
            SYSTME_Logic();
        }

        F50ms = 1;F50ms1=1;
    } else cnt0++;

    if (cnt1 >= 9) {//100ms
        cnt1 = 0;
        F100ms = 1;
        
              if(can2==0){
                 can2=1;     
                 //Pcan_send_yb8();//������
        }else if(can2==1){
                 can2=1;
                 PCAN_send_speed();//����
        }else if(can2==2){
                 can2=3;
               //PCAN_send_yb();//��ѹ                  
        }else if(can2==3){
                 can2=0;
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

    if (Kcount >= 25) {//250ms
        Kcount = 0;
        F300ms = 1;
        kFLASH = !kFLASH;
    } else Kcount++;

    if (cnt2 >= 49) {//500ms 
        cnt2 = 0;
        F500ms = 1;
        F500ms_LCD = !F500ms_LCD;
    } else cnt2++;

    if (wake_up2) { //ACC�����ж�//����//M_ON�ڵ����һ˲���ʹ������Դ��Ч����M_ON�ڶϵ�ᱣ��300ms���Ӷ�Ӱ�쿪�����ɼ�
        if (cnt3 > 30) M_ACC = 1;
        else cnt3++;
    } else {
        if (cnt3 < 1) M_ACC = 0;
        else cnt3--;
    }

    if (wake_up3) { //ON�����ж�//����//M_ON�ڵ����һ˲���ʹ������Դ��Ч����M_ON�ڶϵ�ᱣ��300ms���Ӷ�Ӱ�쿪�����ɼ�
        if (cnt5 > 30) M_ON = 1;
        else cnt5++;
    } else {
        if (cnt5 < 1) M_ON = 0;
        else cnt5--;
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

unsigned int  Tfin=0;

void TIM5_Init(void) {
    FOUT_DR = 0;
    FOUT = 0;
    T5CON = 0; //1��1 ��Ƶ   16MHz
    TMR5 = 0;
  //PR5 = 15999; //1ms�ж�һ��    ����2:1���
  //PR5 = 256;   //16US�ж�һ��   ����Ƶ������ߵĳ���
    PR5 = 1599;  //100us�ж�һ��   ����Ƶ������ߵĳ���
    _T5IE = 1;
    T5CONbits.TON = 1;
}

void __attribute__((__interrupt__, auto_psv)) _T5Interrupt(void) { //1ms  100us
    static unsigned int cnt = 0, out_K = 0;
    unsigned int temp;
    out_K = 721; // ����ϵ��K = 1000 * 3600/����������P
    if(freq[0] > 0)
        temp = 10000 / freq[0];
    else 
        temp = 0;
    if ((Vspeed / 10) > 0) {
        //if (cnt < 2) FOUT = 1;//C3���
        if (cnt < (temp / 2)) FOUT = 1; //ռ�ձ�1:1���
        else FOUT = 0;
        cnt++;

        //C3����ź� V = 255 * 2 / T
        /*if (cnt >= (C3_K / SPEED)) {
            cnt = 0;
        }*/
        // ����T(��) = 3600/����������P(��)/�ٶȣ�KM/H��
        // ����ϵ��K = 1000 * 3600/����������P
        //if (cnt >= (out_K / (Vspeed / 10))) {
        //    cnt = 0;
        //}

        if (cnt >= temp) {
            cnt = 0;
        }

    } else {
        cnt = 0;
        FOUT = 0;
    }

    _T5IF = 0;
}

