#include "SYSTEM.h"
#include "LOGO.h"
unsigned char delay_cnt;
unsigned int  delay_5s;

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
unsigned int ECU_TIME=0;     

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

unsigned int ADR[8]; //�Ǳ�ģ���źŲɼ�ֵ    2016/10/10
unsigned int ADV[8]; //ģ�����ɼ� 

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

unsigned int  BUZZ_COUNT;
unsigned int  Vspeed=0; //����

//ϵͳ��ʼ������
void System_Init(void) {  
    ADPCFG = 0xffff; //�ر�AD��     
    alarm_led[0].byte = 0xff;//��������˲��LED�ͷ�������˸
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
            LED16 =F_PO7; //��ת�򱨾�
            LED21 =F_PO6; //��ת�򱨾�   
            BUZZ  = !(LED16 || LED21);//ת�����
            
        if (F50ms) {
            F50ms = 0;
            LED_Out();
            SW_Input();
            BCAN_SendCtl();
        }
        
        if (M_ON || wake_up2)  break; // �����ON�����������˳�
        
        if (wake_up1 == 0) {
            F_PO6 = 0;
            F_PO7 = 0;
            T_PO15=F_PO7; //��ת���
            T_PO2 =F_PO6; //��ת���
            LED16 =F_PO7; //��ת�򱨾�
            LED21 =F_PO6; //��ת�򱨾�  
            BUZZ  = 1;
            BCAN_SendCtl();//�ж����BCAN����50ms����һ�Σ�����������������״̬�������Ѿ�����
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

void Count_ADR(void) {
    float ad = 4096.0;
    //��ѹ�ʹ������ɼ�  ADV[]��ʵ�ʵĵ�ѹ*1000
    ADV[1] = (unsigned int) (read_ADR(1) / ad * 3500) + 0.3*ADV[1];
    ADV[2] = (unsigned int) (read_ADR(2) / ad * 3500) + 0.3*ADV[2];
    ADV[3] = (unsigned int) (read_ADR(3) / ad * 3500) + 0.3*ADV[3];
    ADV[4] = (unsigned int) (read_ADR(4) / ad * 3500) + 0.3*ADV[4];
    ADV[5] = (unsigned int) (read_ADR(5) / ad * 3500) + 0.3*ADV[5]; 
    //���ص�ѹ    
    ADR[0] = (unsigned int) ((550.0 * read_VOL() / ad )-2); //ʵ�ʵ�ѹ�Ŵ�10��   //(read_VOL() - 1300)*10 / 76 + 180;
    if (ADR[0] >= 225) BAT24V_count = 0;
    //�����ʹ������ɼ�  ADR[]��ʵ�ʵ���ֵ
    //ADR[1] = (unsigned int) (100.0*read_ADR(1)/(ad-read_ADR(1)));//((read_ADR(1) / ad * 100) / (1 - read_ADR(1) / ad));
    ADR[1] = (unsigned int) (70.0 * read_ADR(1) / (ad - read_ADR(1))) + 0.3*ADR[1];
    ADR[2] = (unsigned int) (70.0 * read_ADR(2) / (ad - read_ADR(2))) + 0.3*ADR[2];
    ADR[3] = (unsigned int) (70.0 * read_ADR(3) / (ad - read_ADR(3))) + 0.3*ADR[3];
    ADR[4] = (unsigned int) (70.0 * read_ADR(4) / (ad - read_ADR(4))) + 0.3*ADR[4];
    ADR[5] = (unsigned int) (70.0 * read_ADR(5) / (ad - read_ADR(5))) + 0.3*ADR[5];
    if (ADR[1] > 1000)ADR[1] = 0;      
    if (ADR[2] > 1000)ADR[2] = 0;       
    if (ADR[3] > 1000)ADR[3] = 0;      
    if (ADR[4] > 1000)ADR[4] = 0;  
    if (ADR[5] > 1000)ADR[5] = 0;

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
    F_PO4  = (IN5 && IN8);                      //��ǰ���
  //if((DR_state&0x0F)==0X0D)F_PO5=1;           //������
  //else                     F_PO5=0;     
    F_PO5  =  0;                                //
    F_PO6  = (FLASH && (IN4 || wake_up1));      //��ת���
    F_PO7  = (FLASH && (IN3 || wake_up1));      //��ת���
    F_PO8  = (M_ON);                            //
    F_PO9  = (IN6 );                            //Զ���      
    F_PO10 =  F_PO4;                            //ǰ���
    F_PO11 =  F_PO9;                            //Զ���
    F_PO12 = (M_ON);                            //
    F_PO13 = (IN5 && IN7 );                     //����� 
    F_PO14 = (IN5);                             //λ�õ�
    F_PO15 =  F_PO13;                           //�����
    F_PO16 =  0;                                //���ŵ���

  //if((KEY_state&0x80)||fKL6||rKL6)R_PO1 = 1;  //ɲ����
  //else                            R_PO1 = 0;
  //R_PO2  =  0;                                //
  //R_PO3  = (IN10 && (F_PO9||F_PO13||F_PO4));  //�����     
  //R_PO4  =  0;                                //
  //R_PO5  =  F_PO7;                            //��ת���
  //R_PO6  =  0;                                //
  //R_PO7  =  F_PO6;                            //��ת���
  //R_PO8  = (M_ON);                            //��������Դ
  //R_PO9  =  F_PO5;                            //������ 
  //R_PO10 =  0;                                //
  //R_PO11 = (IN6 && mKL15);                    //ǰ��̤����    
  //R_PO12 = (F_PO14);                          //С��
  //R_PO13 = (IN6 && mKH1);                     //����̤����    
  //R_PO14 =  0;                                //
  //R_PO15 =  0;                                //
  //R_PO16 =  0;                                //���ŵ���  
    
    M_PO1  = (IN10);                            //������
    M_PO2  = (F_PO6);                           //�Һ�ת���
    M_PO3  = (IN9 && (F_PO9||F_PO13||F_PO4));   //�����
    if((KEY_state&0x80)||rKL6)M_PO4 = 1;        //ɲ����
    else                      M_PO4 = 0;
    M_PO5  = (IN24 && (Vspeed<10));             //ǰ�ſ��ŵ�ŷ�
    M_PO6  = (M_ON && fKL7);                    //���ζ�����2
    M_PO7  = (IN25 || ((Vspeed>50) && mKL15));  //ǰ�Ź��ŵ�ŷ�  2017��6����Э�����ӳ��ٴ���5KM/H�Զ�����
    M_PO8  = (M_ON && fKL11);                   //���ζ�����2
    M_PO9  = (IN27 && (Vspeed<10));             //���ſ��ŵ�ŷ�
    M_PO10 = (M_ON && fKL1 );                   //���ζ�����1
    M_PO11 = (IN28 || ((Vspeed>50) && mKH1));   //���Ź��ŵ�ŷ�  2017��6����Э�����ӳ��ٴ���5KM/H�Զ�����
    M_PO12 = (M_ON && fKL9);                    //���ζ�����1
    M_PO13 = (F_PO14);                          //С�Ƶ�Դ
    if(((DR_state&0x0F)==0X0D)||fKH1)M_PO14=1;  //������
    else                             M_PO14=0; 
    M_PO15 = (F_PO7);                           //���ת���
    M_PO16 =  0;                                //���ŵ���
  
}

void LED_Logic(void) {
    unsigned char temp;
    
    LED1  = 0;      //�������  
    LED2  = 0;      //ABS���� 
    LED17 = 0;      //ˮλ�ͱ���
    LED20 = 0;      //���˶�������
   
    LED10 = mKL12;  //����ſ�����
    
    LED7  = F_PO14; //С�� 
   
    LED16 = F_PO7;  //��ת���
    LED21 = F_PO6;  //��ת���   
    
    LED5  = F_PO13; //�����    
    LED6  = F_PO9;  //Զ���     
    
    LED4  = F_PO4;  //ǰ���
    LED3  = M_PO3;  //�����    
    
    LED19 = mKL15;  //ǰ�ſ�ָʾ
    LED18 = mKH1;   //���ſ�ָʾ   

    LED9  = rKL8;   //��ɲ
    LED11 = M_PO4;  //ɲ��ָʾ      
    
    if(BAT24V_count >= BAT24_TIME)LED22=1;else LED22=0;//���ص�ѹ�� 
   
//////////////////////////////////////////////////////
//ѹ��   0    0.1    0.2   0.4    0.6    0.8    1   //
//��ѹ  0.5   0.725   1    1.5     2     2.5    3   //
/////////////////////////////////////////////////////
    LED8  = rKL10||rKL12; //��ѹ�ͱ���
   
    if(DC_Status[2]&0X40)LED13=1;else LED13=0; //���״̬
    if(DC_Status[2]&0X20)LED12=1;else LED12=0; //���ǹ����    
    
    if(DC_fault==1)LED14=1;else LED14=0; //�������ϵͳ����  
   
    temp=(system_state&0x30)>>4;//���кͽ���ʱ
    if((temp==2)||(temp==3))LED15=1;else LED15=0; //ϵͳ����ָʾ
   
//������ Ϊ0ʱ�죬Ϊ1ʱ����
         if(    IN3               ||  //��ת��Ʊ��� 
                IN4               ||  //��ת��Ʊ���
                wake_up1
           )    BUZZ = !(LED16 || LED21);//
    else if( M_ON &&
           ( //!fKL4 ||   //��ǰĦ��Ƭ����
             //!fKL5 ||   //��ǰĦ��Ƭ����
             //!fKL8 ||   //���Ħ��Ƭ����
             //!fKL9 ||   //�Һ�Ħ��Ƭ����
               !rKL4 ||   //��ǰĦ��Ƭ����
               !rKL5 ||   //��ǰĦ��Ƭ����
               !rKL7 ||   //���Ħ��Ƭ����
               !rKL9 ||   //�Һ�Ħ��Ƭ����
              ((system_state&0x30)==0x20)||   //����
               (eror_R==2)               ||   //��Ե��������
               (TYBJ_state[1]&0x80)||  //��������������¶ȱ���
               (TYBJ_state[2]&0x02)||  //��������¶ȱ���
               (TYBJ_state[4]&0X40)||  //����������
               (TYBJ_state[5]&0X01)||  //�������
               (DC_fault==1)       ||  //��ع���
               (DC_Status[1]&0X20) ||  //��ع���
               (DC_Status[3]&0X01) ||  //��ػ���
               (DC_Status[1]&0X02) ||  //������
               (YW_Status[1]>0)    ||  //����������        20171030����
              //mKL2               ||  //���忪��
                mKL4               ||  //Ӧ����������������
                LED8               ||  //��ѹ1  2   
              //LED16              ||  //��ת��Ʊ��� 
              //LED21                  //��ת��Ʊ���    
               (Vspeed > 690)          //���ٱ���       
            )
       )     BUZZ = 0;//!FLASH;
    else     BUZZ = 1;
    
    if((system_state&0x30)==0x30){
        BUZZ=0; //
        if(FLASH){
        alarm_led[1].byte=0xff;
        alarm_led[2].byte=0xff;
        alarm_led[3].byte=0xff;
    }else{
        alarm_led[1].byte=0;
        alarm_led[2].byte=0;
        alarm_led[3].byte=0;
         } 
    }          
         
    if(IN5) OC1RS=e_backlight;  //С�ƿ��� 
    else    OC1RS=0;
   
    if(M_ON){ PO1=0; PO2=0; }     
    else    { PO1=1; PO2=1; }
        
}

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
    temp.bit1 = IN18; //����      
    temp.bit2 = IN19; //��Ъ
    temp.bit3 = IN20; //�쵵
    temp.bit4 = IN21; //��ˮ        
    if (IN18 && IN20)temp.bit1 = 0;
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

void PCAN_send_yb(void) {
    CAN_MESSAGE   msg;
    SW_DATA       temp;
    unsigned int  temp1;
    unsigned char xz=1;//0����  1��ѹ
    
    temp.bit0 = rKL10||rKL12; //��ѹ�ͱ���
    temp.bit1 = rKL8; //פ���ź�
    temp.bit2 = mKL12;//�����
    temp.bit3 = mKL15;//ǰ�ſ�
    temp.bit4 = mKH1; //���ſ�
    temp.bit5 = M_ON; //����
    temp.bit6 = M_ON; //һ��
    temp.bit7 = 0;
    msg.data[0] =temp.byte;
    
    temp.bit0 = M_PO3; //�����
    temp.bit1 = F_PO13;//�����
    temp.bit2 = 0;     //������Ԥ��
    temp.bit3 = 0;     //��������
    temp.bit4 = F_PO6; //��ת���
    temp.bit5 = F_PO4; //ǰ���
    temp.bit6 = F_PO9; //Զ���
    temp.bit7 = F_PO7; //��ת���
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
    
    temp1=ADV[4]/10;//��ѹʽ
    if(temp1>=50 && temp1<=300)temp1=(unsigned int)(40*(temp1-50));  
    else                       temp1=0;
    msg.data[4]=(unsigned char)(temp1);
    msg.data[5]=(unsigned char)(temp1>>8);

    temp1=ADV[5]/10;//��ѹʽ
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
    unsigned char i=0,j=0;
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
                //if(fADR[0]>8000)fADR[0]=0;
                //if(fADR[1]>8000)fADR[1]=0;
                break;
            case 0x672:
                Mcan_count = 0;
                mADR[0] = message.data[0]+((unsigned int) message.data[1] << 8);
                mADR[1] = message.data[2]+((unsigned int) message.data[3] << 8);
                //if(mADR[0]>8000)mADR[0]=0;
                //if(mADR[1]>8000)mADR[1]=0;
                break;
            case 0x673:
                Rcan_count = 0;
                rADR[0] = message.data[0]+((unsigned int) message.data[1] << 8);
                rADR[1] = message.data[2]+((unsigned int) message.data[3] << 8);
                //if(rADR[0]>8000)rADR[0]=0;
                //if(rADR[1]>8000)rADR[1]=0;
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

unsigned int   XDC_current=32000; //���ص���  
unsigned int   XDC_voltage=0; //���ص�ѹ                
unsigned char  PDH_temp=40;//�����¶�

void __attribute__((__interrupt__, auto_psv)) _C2Interrupt(void) {
    unsigned char i=0; 
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
            //����������;
            case 0x0C03A1A7:
                DJcontroler_voltage=((unsigned int)msg.data[1]<<8) + msg.data[0];//��������������ѹ
                DJcontroler_current=((unsigned int)msg.data[3]<<8) + msg.data[2]; //����������������
                DJ_torque=((unsigned int)msg.data[5]<<8) + msg.data[4];//���ת��
                DJ_speed =((unsigned int)msg.data[7]<<8) + msg.data[6];//���ת��
                break;
            case 0x0C04A1A7:
                DJ_temperature=msg.data[0];             //��������¶�
                DJcontroler_temperature=msg.data[1];    //��������������¶�
                FDJ_temperature=msg.data[2];            //������¶�
                FDJcontroler_temperature=msg.data[3];   //������������¶�
                DR_state=msg.data[4];                   //˾������״̬
                KEY_state=msg.data[5];                  //������״̬
              //system_state=msg.data[6];               //ϵͳ����״̬
                system_fault=(((unsigned int)msg.data[7]<<8) + msg.data[6]); //ϵͳ������
                break;
            case 0x0C05A1A7:
                EngineSpeed=(((unsigned int)msg.data[1]<<8) + msg.data[0]);
                WaterTem=msg.data[2];
                EngineLoad=msg.data[3];    //������������
                urea_high=msg.data[4];     //����Һλ
                speed_st1=msg.data[5];     //������Ŀ������̤��״̬
                speed_st2=msg.data[6];     //������ʵ������̤��
                controler_LIFE=msg.data[7]; //����������Life
                break;
            case 0x0C06A1A7:
                traction_st=msg.data[0];   //ǣ��̤��ٷֱ�
                brake_st=msg.data[1];      //�ƶ�̤��ٷֱ�
                engine_oil_press=msg.data[2];       //����������ѹ��
                ambient_air_temperature=msg.data[3];//�����������¶�
                total_fuel=(((unsigned long)msg.data[7]<<24)+
                            ((unsigned long)msg.data[6]<<16)+
                            ((unsigned long)msg.data[5]<<8) + 
                                            msg.data[4]);   //�������ۼ��ͣ���������
                break;
            case 0x0C07A1A7:
                debug_num[0]=msg.data[0];
                debug_num[1]=msg.data[1];
                debug_num[2]=msg.data[2];
                debug_num[3]=msg.data[3];
                debug_num[4]=msg.data[4];
                debug_num[5]=msg.data[5];
                debug_num[6]=msg.data[6];
                debug_num[7]=msg.data[7];
                break;
            case 0x0C08A1A7:
              //DJ_torqueST=(((unsigned int)msg.data[1]<<8) + msg.data[0]); //�������Ŀ��ת��
              //EngineSpeST=msg.data[2]; //������Ŀ��ת��
                instantaneous_fuel=msg.data[3];  //˲ʱ��(��)��   //Сʱȼ��������
                single_BGLfuel=(((unsigned int)msg.data[5]<<8) + msg.data[4]);  //С�ưٹ����ͺ�
                total_BGLfuel=(((unsigned int)msg.data[7]<<8) + msg.data[6]);   //�ܼưٹ����ͺ�
                break;
            case 0x0C09A1A7: //��������������汾��
                KZQversion[0]=msg.data[1];
                KZQversion[1]=msg.data[2];
                KZQversion[2]=msg.data[3];
                KZQversion[3]=msg.data[4];
                KZQversion[4]=msg.data[5];
                KZQversion[5]=msg.data[6];
                KZQversion[6]=msg.data[7];
                break;
            case 0x0C0AA1A7:
                CAR_MODE=msg.data[0];    //����ģʽ-�Լ�-���-����
                system_state=msg.data[1];//ϵͳ����״̬-����������������
                break;
            case 0x0C0CA7F2: //���������������汾��
                FDJversion[0]=msg.data[1];
                FDJversion[1]=msg.data[2];
                FDJversion[2]=msg.data[3];
                FDJversion[3]=msg.data[4];
                FDJversion[4]=msg.data[5];
                FDJversion[5]=msg.data[6];
                FDJversion[6]=msg.data[7];
                break;
            case 0x0C0AA7F0: //�������������汾��
                DJversion[0]=msg.data[1];
                DJversion[1]=msg.data[2];
                DJversion[2]=msg.data[3];
                DJversion[3]=msg.data[4];
                DJversion[4]=msg.data[5];
                DJversion[5]=msg.data[6];
                DJversion[6]=msg.data[7]; 
                break;
            case 0x1819A1A4: // ��Ե����ǲ���
                anode_R=   (((unsigned int)msg.data[0]<<8) + msg.data[1]);  //���˶Եؾ�Ե����
                negative_R=(((unsigned int)msg.data[2]<<8) + msg.data[3]);  //���˶Եؾ�Ե����
                eror_R=msg.data[4];    //��Ե���ϵȼ�
                R_life=msg.data[5];    //
                R_ID  =msg.data[6];    //����©�籨��
                break;
            case 0x0C08A79A:  //ת��DCDC����
                DCDC_SC_voltage=(((unsigned int)msg.data[1]<<8) + msg.data[0]); 
                DCDC_SC_current=(((unsigned int)msg.data[3]<<8) + msg.data[2]); 
                DCDC_SR_voltage=(((unsigned int)msg.data[5]<<8) + msg.data[4]); 
                DCDC_temperature=msg.data[6];
                DCDC_fault=msg.data[7]; 
                break;
            case 0x0C09A79B://����ת��DCAC����ID
                DCAC_W_current=(((unsigned int)msg.data[1]<<8) + msg.data[0]); 
                DCAC_V_current=(((unsigned int)msg.data[3]<<8) + msg.data[2]); 
                DCAC_U_current=(((unsigned int)msg.data[5]<<8) + msg.data[4]); 
                DCAC_temperature=msg.data[6];
                DCAC_fault=msg.data[7]; 
                break;
            case 0x0C01A70A://����ƽ̨1
                XHLC=msg.data[5]; //�������  5Km/Bit  ���1000
                break;
            case 0x0C02A70A://����ƽ̨2
                TYBJ_state[0]=msg.data[0];//ͨ�ñ�����־1
                TYBJ_state[1]=msg.data[1];//ͨ�ñ�����־2-��������������¶ȱ���-��Ե����
                TYBJ_state[2]=msg.data[2];//ͨ�ñ�����־3-��������¶ȱ���
                TYBJ_state[3]=msg.data[3];//ͨ�ñ�����־4
                break;
            case 0x0C03A70A://����ƽ̨3
                TYBJ_state[4]=msg.data[0];//ͨ�ñ�����־5-����������
                TYBJ_state[5]=msg.data[1];//ͨ�ñ�����־6-�������-�������
                TYBJ_state[6]=msg.data[2];//ͨ�ñ�����־7
                TYBJ_state[7]=msg.data[3];//ͨ�ñ�����־8   
                break;
            case 0x18FFC09E: //��ͳ�յ�
                KT_MODE=1;//�յ�ѡ��ģʽ
                KT_Status[0]=msg.data[0];//�յ�ϵͳ���ϴ���   
                KT_Status[1]=msg.data[1];//�յ�ϵͳ�������״̬  
                KT_Status[2]=msg.data[2];//�յ�ϵͳ����״̬   
                KT_temp1[1] =msg.data[3];//����ʵ���¶�
                KT_temp1[0] =msg.data[4];//����ʵ���¶�
                KT_temp1[2] =msg.data[5];//�趨�¶�
                KT_ctrl     =msg.data[6];//�յ���������
                KT_life     =msg.data[7];
                break;
            case 0x0C08A7F4:  //�綯�յ�
              //KT_Status[0]=msg.data[0];
                KT_fuhe     =msg.data[0];//�յ�ʵ�ʹ�������
                KT_temp[0]  =msg.data[1];//�趨�¶�
                KT_temp[1]  =msg.data[2];//����ʵ���¶�
                KT_temp[2]  =msg.data[3];//����ʵ���¶�
                KT_current  =(((unsigned int)msg.data[5]<<8) + msg.data[4]); //
                KT_Status[0]=msg.data[6];//�յ�����״̬
                KT_life     =msg.data[7];
                break;
                //��ص�ع�����ر���
            case 0x1818D0F3:
                DC_voltage = (((unsigned int) msg.data[1] << 8) + msg.data[0]); //��ص�ѹ 
                DC_current = (((unsigned int) msg.data[3] << 8) + msg.data[2]); //��ص��� 
                DC_SOC = msg.data[4];
                DC_Status[0] = msg.data[5];
                DC_Status[1] = msg.data[6];
                DC_Status[2] = msg.data[7];
                break;
            case 0x1819D0F3:
                CD_current = (((unsigned int) msg.data[1] << 8) + msg.data[0]); //��ǰ������������
                FD_current = (((unsigned int) msg.data[3] << 8) + msg.data[2]); //��ǰ�������ŵ����
                DC_fault = msg.data[4]; //ϵͳ���ϵȼ�
                Vpj = (((unsigned int) msg.data[6] << 8) + msg.data[5]); //����ƽ����ѹ
                Tmax1 = msg.data[7]; //��������¶�
                //Twater=msg.data[6]; //��ˮ���¶�
                //DC_JCQst[1]=msg.data[7]; //��ؽӴ�������Ͽ���ʶ
                break;
            case 0x181AD0F3:
                anode_R1 = (((unsigned int) msg.data[1] << 8) + msg.data[0]); //���˶Եؾ�Ե����
                negative_R1 = (((unsigned int) msg.data[3] << 8) + msg.data[2]); //���˶Եؾ�Ե����
                Vmax = (((unsigned int) msg.data[5] << 8) + msg.data[4]); //������ѹ
                Vmin = (((unsigned int) msg.data[7] << 8) + msg.data[6]); //��С�����ѹ
                break;
            case 0x181BD0F3:
                VIN_Status   = msg.data[0]; //VIN����״̬
                DC_Status[3] = msg.data[1];
                CDZ_temp[0]  = msg.data[2]; //������¶�1
                CDZ_temp[1]  = msg.data[3]; //������¶�2
                CDZ_temp[2]  = msg.data[4]; //������¶�3
                CDZ_temp[3]  = msg.data[5]; //������¶�4
                DC_Status[5] = msg.data[6]; //���й�������
                DC_Status[4] = msg.data[7]; //
                break;
            case 0x181CD0F3:
                DC_EDRL = (((unsigned int) msg.data[1] << 8) + msg.data[0]); //��ض����
                DC_EDDY = (((unsigned int) msg.data[3] << 8) + msg.data[2]); //��ض��ѹ
                DC_CL_SUM = (((unsigned int) msg.data[5] << 8) + msg.data[4]); //��ص��崮������
                DC_BL_SUM = msg.data[6]; //��ص��岢������
                DC_WD_SUM = msg.data[7]; //���ϵͳ�¶�̽��
                break;
            case 0x181DD0F3:
                Tmax     = msg.data[0]; //��������¶�
                Tmax_box = msg.data[1]; //��������¶����
                Tmax_num = msg.data[2]; //��������¶����
                Tmin     = msg.data[3]; //��С�������¶�
                Tmin_box = msg.data[4]; //��С�������¶����
                Tmin_num = msg.data[5]; //��С�������¶����
                DC_style = msg.data[6]; //�������
                DC_LengQ = msg.data[7]; //�����ȴ��ʽ
                break;
            case 0x181ED0F3:
                Vmax_box = msg.data[0]; //������ص�ѹ���
                Vmax_num = msg.data[1]; //������ص�ѹ���
                Vmin_box = msg.data[2]; //��С�����ص�ѹ���
                Vmin_num = msg.data[3]; //��С�����ص�ѹ���
                break;
            case 0x180028F3:
                BAT_vol[0] = (((unsigned int) msg.data[2] << 8) + msg.data[1]); //����1�����ѹ
                BAT_num[0] = (((unsigned int) msg.data[6] << 8) + msg.data[0]); //����1�����ѹ���
                BAT_vol[1] = (((unsigned int) msg.data[5] << 8) + msg.data[4]); //����2�����ѹ
                BAT_num[1] = (((unsigned int) msg.data[7] << 8) + msg.data[3]); //����2�����ѹ���
                break;
            case 0x180128F3:
                BAT_vol[2] = (((unsigned int) msg.data[2] << 8) + msg.data[1]); //����3�����ѹ
                BAT_num[2] = (((unsigned int) msg.data[6] << 8) + msg.data[0]); //����3�����ѹ���
                BAT_vol[3] = (((unsigned int) msg.data[5] << 8) + msg.data[4]); //����4�����ѹ
                BAT_num[3] = (((unsigned int) msg.data[7] << 8) + msg.data[3]); //����4�����ѹ���
                break;
            case 0x180228F3:
                BAT_vol[4] = (((unsigned int) msg.data[2] << 8) + msg.data[1]); //����5�����ѹ
                BAT_num[4] = (((unsigned int) msg.data[6] << 8) + msg.data[0]); //����5�����ѹ���
                BAT_vol[5] = (((unsigned int) msg.data[5] << 8) + msg.data[4]); //����1�����ѹ
                BAT_num[5] = (((unsigned int) msg.data[7] << 8) + msg.data[3]); //����1�����ѹ���
                break;
            case 0x180328F3:
                BAT_vol[6] = (((unsigned int) msg.data[2] << 8) + msg.data[1]); //����2�����ѹ
                BAT_num[6] = (((unsigned int) msg.data[6] << 8) + msg.data[0]); //����2�����ѹ���
                BAT_vol[7] = (((unsigned int) msg.data[5] << 8) + msg.data[4]); //����3�����ѹ
                BAT_num[7] = (((unsigned int) msg.data[7] << 8) + msg.data[3]); //����3�����ѹ���
                break;
            case 0x180428F3:
                BAT_vol[8] = (((unsigned int) msg.data[2] << 8) + msg.data[1]); //����4�����ѹ
                BAT_num[8] = (((unsigned int) msg.data[6] << 8) + msg.data[0]); //����4�����ѹ���
                BAT_vol[9] = (((unsigned int) msg.data[5] << 8) + msg.data[4]); //����5�����ѹ
                BAT_num[9] = (((unsigned int) msg.data[7] << 8) + msg.data[3]); //����5�����ѹ���
                break;
            case 0x180028F4:
                BAT_num1[0] = msg.data[0]; //����1�����¶ȱ��
                BAT_temp[0] = msg.data[1]; //����1�����¶�
                BAT_num1[1] = msg.data[2]; //����2�����¶ȱ��
                BAT_temp[1] = msg.data[3]; //����2�����¶�
                BAT_num1[2] = msg.data[4]; //����3�����¶ȱ��
                BAT_temp[2] = msg.data[5]; //����3�����¶�
                BAT_num1[3] = msg.data[6]; //����4�����¶ȱ��
                BAT_temp[3] = msg.data[7]; //����4�����¶�
                break;
            case 0x180128F4:
                BAT_num1[4] = msg.data[0]; //����5�����¶ȱ��
                BAT_temp[4] = msg.data[1]; //����5�����¶�
                BAT_num1[5] = msg.data[2]; //����1�����¶ȱ��
                BAT_temp[5] = msg.data[3]; //����1�����¶�
                BAT_num1[6] = msg.data[4]; //����2�����¶ȱ��
                BAT_temp[6] = msg.data[5]; //����2�����¶�
                BAT_num1[7] = msg.data[6]; //����3�����¶ȱ��
                BAT_temp[7] = msg.data[7]; //����3�����¶�
                break;
            case 0x180228F4:
                BAT_num1[8] = msg.data[0]; //����4�����¶ȱ��
                BAT_temp[8] = msg.data[1]; //����4�����¶�
                BAT_num1[9] = msg.data[2]; //����5�����¶ȱ��
                BAT_temp[9] = msg.data[3]; //����5�����¶�
                break;
            case 0x18EBA1A5:
                MHQ_DCBOX = msg.data[0]; //�����������
                MHQ_YJJB  = msg.data[1]; //�����ϵͳԤ������
                MHQ_fault = msg.data[2]; //�����������
                break;
            case 0x18EFA1A5:
                MHQ_TIME = 0XAA; //����Уʱ
                break;
            case 0x1819A100:
                YW_Status[0] = msg.data[0]; //��վ����״̬
                YW_Status[1] = msg.data[1]; //��վ��״̬
                YW_Status[2] = msg.data[2]; //��վ����״̬
                YW_Status[3] = msg.data[3]; //��վӲ��״̬
                YW_Status[4] = msg.data[6]; //ϵͳ��״̬
                YW_Status[5] = msg.data[7]; //LIFE
                break;
            case 0x180AA7A3:
                YZT_LIFE = msg.data[6];//�ն�״̬ 0XFF����ʾ������������Ƭ����FFʱ��ʾ�쳣����Ƭ��������Ƭ����  20170816���  
                break;     
            case 0x18FE521E:
                XDC_current = (((unsigned int) msg.data[3] << 8) + msg.data[2]); //���ص���  
                XDC_voltage = (((unsigned int) msg.data[5] << 8) + msg.data[4]); //���ص�ѹ                
                PDH_temp    =  msg.data[6];//�����¶�
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
    static unsigned int can1 = 0, can2 = 0;
    static float mile = 0;
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
    if (delay_5s > 0)  delay_5s--; //��ʱ������     

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
        F100ms= 1;    
              if(can2==0){
                 can2=1;
                 if(MHQ_TIME==0xAA){MHQ_TIME=0;PCAN_send_time();}//ʱ��        
        }else if(can2==1){
                 can2=2;
                 PCAN_send_yb();//��ѹ 
        }else if(can2==2){
                 can2=3;
                 PCAN_send_speed();//����
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
        if(BAT24V_count>= BAT24_TIME)BAT24V_count= BAT24_TIME;
        else BAT24V_count++;
        if (ECU_TIME   >= CAN_TIME)ECU_TIME   = CAN_TIME;
        else ECU_TIME++;
        
        if (cnt4 >= 9) {//1s
            cnt4 = 0;
            F1000ms = 1;
            FLASH_1s = !FLASH_1s;
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
    } else cnt2++;

    if (wake_up3) { //ON�����ж�//����//M_ON�ڵ����һ˲���ʹ������Դ��Ч����M_ON�ڶϵ�ᱣ��300ms���Ӷ�Ӱ�쿪�����ɼ�
        if (cnt3 > 30) M_ON = 1;
        else cnt3++;
    } else {
        if (cnt3 < 1) M_ON = 0;
        else cnt3--;
    }
    
    // �漰�������߼�
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


