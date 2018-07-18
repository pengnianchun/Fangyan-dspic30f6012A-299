#include "SYSTEM.h"
#include "LOGO.h"
unsigned char delay_cnt;
unsigned int  delay_5s;

DATA_BIT gKEY[5];
DATA_BIT gCTL[8]; //仪表输出控制信息

unsigned int single_miles = 0;
unsigned long total_miles = 0;


unsigned int Fcan_count = 0; //前部模块CAN
unsigned int Rcan_count = 0; //顶部模块CAN
unsigned int Mcan_count = 0; //中部模块CAN
unsigned int Ecan_count = 0; //发动机ECU模块CAN
unsigned int Vcan_count = 0; //整车控制器VCU模块CAN
unsigned int Bcan_count = 0; //电池管理器BMS模块CAN
unsigned int Dcan_count = 0; //转向助力DC/AC模块CAN
unsigned int Acan_count = 0; //空调AC模块CAN
unsigned int ECU_TIME=0;     

unsigned int BAT24V_count = 0; //蓄电池低压报警计时
unsigned int M_PO11_count = 1000; //输出10秒计时

DBCM_KEY fKEY; //前模块功率开关状态
DBCM_KEY mKEY; //中（顶）模块功率开关状态
DBCM_KEY rKEY; //后模块功率开关状态

SW_DATA  fkey[3];
SW_DATA  rkey[3];
SW_DATA  tkey[3];

unsigned int fMK_Version=0; //前模块版本号
unsigned int mMK_Version=0; //顶模块版本号
unsigned int rMK_Version=0; //后模块版本号

unsigned int fFreq; //前模块频率
unsigned int mFreq; //中（顶）模块频率
unsigned int rFreq; //后模块频率

unsigned int fSpeed; //前模块折算车速
unsigned int mSpeed; //中（顶）模块折算车速
unsigned int rSpeed; //后模块折算车速
unsigned int pSpeed; //外部CAN这算车速

unsigned int fADR[2]; //前模块电阻值
unsigned int mADR[2]; //中（顶）模块电阻值
unsigned int rADR[2]; //后模块电阻值

unsigned int ADR[8]; //仪表模拟信号采集值    2016/10/10
unsigned int ADV[8]; //模拟量采集 

DBCM_POUT fPOUT; //前模块功率输出状态
DBCM_POUT mPOUT; //中（顶）模块功率输出状态
DBCM_POUT rPOUT; //后模块功率输出状态

unsigned char fPF[16]; //前模块功率输出故障
unsigned char mPF[16]; //中（顶）模块功率故障
unsigned char rPF[16]; //后模块功率输出故障

unsigned int fpcur[15];//前模块功率输出电流
unsigned int mpcur[15];//中模块功率输出电流
unsigned int rpcur[15];//后模块功率输出电流

unsigned int fSingle_miles;
unsigned int mSingle_miles;
unsigned int rSingle_miles;

unsigned char ccvs_eng_req; //启动请求

unsigned char dm_hcu_display[32]; //故障类型
unsigned char dm_tcu_display[32];

unsigned int  BUZZ_COUNT;
unsigned int  Vspeed=0; //车速

//系统初始化函数
void System_Init(void) {  
    ADPCFG = 0xffff; //关闭AD口     
    alarm_led[0].byte = 0xff;//消除开机瞬间LED和蜂鸣器闪烁
    alarm_led[1].byte = 0x00;
    alarm_led[2].byte = 0x00;
    alarm_led[3].byte = 0x00;
    LED_Out();  
    /*按键控制接口 */
    KEY_UP_DR = 1; //   
    KEY_SET_DR = 1; // 
    KEY_AV_DR = 1;
    
    PWR_CTRL_DR = 1; //供电电压端口初始化
    PWR_CTRL = 0;
    
    LCD_Init();
    TIMER1_Init();
    delay_cnt = 10; //延时0.1s
    while (delay_cnt > 1) {
        ClrWdt();
        SW_Input(); //开关读取
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
        if (wake_up1) {//如果危险报警唤醒
            PWR_CTRL_DR = 0;
            PWR_CTRL = 1;
            F_PO6 = FLASH;
            F_PO7 = FLASH;
        } else {
            F_PO6 = 0;
            F_PO7 = 0;
        }
            T_PO15=F_PO7; //左转向灯
            T_PO2 =F_PO6; //右转向灯
            LED16 =F_PO7; //左转向报警
            LED21 =F_PO6; //右转向报警   
            BUZZ  = !(LED16 || LED21);//转向蜂鸣
            
        if (F50ms) {
            F50ms = 0;
            LED_Out();
            SW_Input();
            BCAN_SendCtl();
        }
        
        if (M_ON || wake_up2)  break; // 如果是ON唤醒则正常退出
        
        if (wake_up1 == 0) {
            F_PO6 = 0;
            F_PO7 = 0;
            T_PO15=F_PO7; //左转向灯
            T_PO2 =F_PO6; //右转向灯
            LED16 =F_PO7; //左转向报警
            LED21 =F_PO6; //右转向报警  
            BUZZ  = 1;
            BCAN_SendCtl();//中断里的BCAN发送50ms发送一次，可能来不及发最后的状态，程序已经结束
            __delay_us(100);
            BCAN_SendCtl();
            __delay_us(100);
            BCAN_SendCtl();
            __delay_us(100);
            BCAN_SendCtl();
            __delay_us(100);
            PWR_CTRL_DR = 1; //关闭电源
            PWR_CTRL = 0; //关闭电源 
            PWR_CTRL_DR = 1; //关闭电源
            PWR_CTRL = 0; //关闭电源 
            PWR_CTRL_DR = 1; //关闭电源
            PWR_CTRL = 0; //关闭电源 
        }
    }
    
    delay_cnt = 100; //设置1s定时 
    SM_Init();
    SM_Reset();
    BL_Init(); //仪表小灯背光初始化
    INT1_Init();
    INT2_Init();
    TIMER3_Init();
    EEROM_ReadSingleMiles();
    EEROM_ReadTotalMiles();
    EEROM_ReadHMPulse();
    EEROM_ReadBackLight();
    single_miles = e_single_miles;
    total_miles = e_total_miles;
    OC1RS = e_backlight; //更新背光值
    ADC_Init();
    LCD_Init();
    alarm_led[0].byte = 0xC0; //蜂鸣器开启
    alarm_led[1].byte = 0xff;
    alarm_led[2].byte = 0xff;
    alarm_led[3].byte = 0xff;
    LED_Out();
    while (delay_cnt > 1); //延时1s
    OC1RS = 0;
    PWR_CTRL_DR = 0; //电源控制接口
    PWR_CTRL = 1; //开启MCU电源控制
    alarm_led[0].byte = 0xff;
    alarm_led[1].byte = 0x00;
    alarm_led[2].byte = 0x00;
    alarm_led[3].byte = 0x00;
    LED_Out();
    SW_Input();
    LCD_BackLight(7);
    DS3231_ReadTime(&timer); //读取时间   
}

void Count_ADR(void) {
    float ad = 4096.0;
    //电压型传感器采集  ADV[]是实际的电压*1000
    ADV[1] = (unsigned int) (read_ADR(1) / ad * 3500) + 0.3*ADV[1];
    ADV[2] = (unsigned int) (read_ADR(2) / ad * 3500) + 0.3*ADV[2];
    ADV[3] = (unsigned int) (read_ADR(3) / ad * 3500) + 0.3*ADV[3];
    ADV[4] = (unsigned int) (read_ADR(4) / ad * 3500) + 0.3*ADV[4];
    ADV[5] = (unsigned int) (read_ADR(5) / ad * 3500) + 0.3*ADV[5]; 
    //蓄电池电压    
    ADR[0] = (unsigned int) ((550.0 * read_VOL() / ad )-2); //实际电压放大10倍   //(read_VOL() - 1300)*10 / 76 + 180;
    if (ADR[0] >= 225) BAT24V_count = 0;
    //电阻型传感器采集  ADR[]是实际的阻值
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

    unsigned int  QY_TIME=0;  //气压计时变量
    unsigned int  KYJ_TIME=0; //空压机计时变量
    unsigned char QY_OUT_EN=1;//气压外部使能开关
void SYSTME_Logic(void) {
    static unsigned char KYJ_EN=1;
    static unsigned char QY_EN=1;
 
 // F_PO1  = (IN16 && M_ON);                    //雨刮快档
 // F_PO2  = (IN14 && M_ON);                    //雨刮慢档
 // F_PO3  = (IN21 && M_ON);                    //喷水电机
    F_PO4  = (IN5 && IN8);                      //左前雾灯
  //if((DR_state&0x0F)==0X0D)F_PO5=1;           //倒车灯
  //else                     F_PO5=0;     
    F_PO5  =  0;                                //
    F_PO6  = (FLASH && (IN4 || wake_up1));      //右转向灯
    F_PO7  = (FLASH && (IN3 || wake_up1));      //左转向灯
    F_PO8  = (M_ON);                            //
    F_PO9  = (IN6 );                            //远光灯      
    F_PO10 =  F_PO4;                            //前雾灯
    F_PO11 =  F_PO9;                            //远光灯
    F_PO12 = (M_ON);                            //
    F_PO13 = (IN5 && IN7 );                     //近光灯 
    F_PO14 = (IN5);                             //位置灯
    F_PO15 =  F_PO13;                           //近光灯
    F_PO16 =  0;                                //励磁电流

  //if((KEY_state&0x80)||fKL6||rKL6)R_PO1 = 1;  //刹车灯
  //else                            R_PO1 = 0;
  //R_PO2  =  0;                                //
  //R_PO3  = (IN10 && (F_PO9||F_PO13||F_PO4));  //后雾灯     
  //R_PO4  =  0;                                //
  //R_PO5  =  F_PO7;                            //左转向灯
  //R_PO6  =  0;                                //
  //R_PO7  =  F_PO6;                            //右转向灯
  //R_PO8  = (M_ON);                            //干燥器电源
  //R_PO9  =  F_PO5;                            //倒车灯 
  //R_PO10 =  0;                                //
  //R_PO11 = (IN6 && mKL15);                    //前门踏步灯    
  //R_PO12 = (F_PO14);                          //小灯
  //R_PO13 = (IN6 && mKH1);                     //中门踏步灯    
  //R_PO14 =  0;                                //
  //R_PO15 =  0;                                //
  //R_PO16 =  0;                                //励磁电流  
    
    M_PO1  = (IN10);                            //广告灯箱
    M_PO2  = (F_PO6);                           //右后转向灯
    M_PO3  = (IN9 && (F_PO9||F_PO13||F_PO4));   //后雾灯
    if((KEY_state&0x80)||rKL6)M_PO4 = 1;        //刹车灯
    else                      M_PO4 = 0;
    M_PO5  = (IN24 && (Vspeed<10));             //前门开门电磁阀
    M_PO6  = (M_ON && fKL7);                    //条形顶灯左2
    M_PO7  = (IN25 || ((Vspeed>50) && mKL15));  //前门关门电磁阀  2017年6月新协议增加车速大于5KM/H自动关门
    M_PO8  = (M_ON && fKL11);                   //条形顶灯右2
    M_PO9  = (IN27 && (Vspeed<10));             //中门开门电磁阀
    M_PO10 = (M_ON && fKL1 );                   //条形顶灯左1
    M_PO11 = (IN28 || ((Vspeed>50) && mKH1));   //中门关门电磁阀  2017年6月新协议增加车速大于5KM/H自动关门
    M_PO12 = (M_ON && fKL9);                    //条形顶灯右1
    M_PO13 = (F_PO14);                          //小灯电源
    if(((DR_state&0x0F)==0X0D)||fKH1)M_PO14=1;  //倒车灯
    else                             M_PO14=0; 
    M_PO15 = (F_PO7);                           //左后转向灯
    M_PO16 =  0;                                //励磁电流
  
}

void LED_Logic(void) {
    unsigned char temp;
    
    LED1  = 0;      //电机故障  
    LED2  = 0;      //ABS报警 
    LED17 = 0;      //水位低报警
    LED20 = 0;      //空滤堵塞报警
   
    LED10 = mKL12;  //后仓门开报警
    
    LED7  = F_PO14; //小灯 
   
    LED16 = F_PO7;  //左转向灯
    LED21 = F_PO6;  //右转向灯   
    
    LED5  = F_PO13; //近光灯    
    LED6  = F_PO9;  //远光灯     
    
    LED4  = F_PO4;  //前雾灯
    LED3  = M_PO3;  //后雾灯    
    
    LED19 = mKL15;  //前门开指示
    LED18 = mKH1;   //中门开指示   

    LED9  = rKL8;   //手刹
    LED11 = M_PO4;  //刹车指示      
    
    if(BAT24V_count >= BAT24_TIME)LED22=1;else LED22=0;//蓄电池电压低 
   
//////////////////////////////////////////////////////
//压力   0    0.1    0.2   0.4    0.6    0.8    1   //
//电压  0.5   0.725   1    1.5     2     2.5    3   //
/////////////////////////////////////////////////////
    LED8  = rKL10||rKL12; //气压低报警
   
    if(DC_Status[2]&0X40)LED13=1;else LED13=0; //充电状态
    if(DC_Status[2]&0X20)LED12=1;else LED12=0; //充电枪插入    
    
    if(DC_fault==1)LED14=1;else LED14=0; //动力电池系统故障  
   
    temp=(system_state&0x30)>>4;//坡行和紧急时
    if((temp==2)||(temp==3))LED15=1;else LED15=0; //系统报警指示
   
//蜂鸣器 为0时响，为1时不响
         if(    IN3               ||  //左转向灯报警 
                IN4               ||  //右转向灯报警
                wake_up1
           )    BUZZ = !(LED16 || LED21);//
    else if( M_ON &&
           ( //!fKL4 ||   //左前摩擦片报警
             //!fKL5 ||   //右前摩擦片报警
             //!fKL8 ||   //左后摩擦片报警
             //!fKL9 ||   //右后摩擦片报警
               !rKL4 ||   //左前摩擦片报警
               !rKL5 ||   //右前摩擦片报警
               !rKL7 ||   //左后摩擦片报警
               !rKL9 ||   //右后摩擦片报警
              ((system_state&0x30)==0x20)||   //坡行
               (eror_R==2)               ||   //绝缘二级故障
               (TYBJ_state[1]&0x80)||  //驱动电机控制器温度报警
               (TYBJ_state[2]&0x02)||  //驱动电机温度报警
               (TYBJ_state[4]&0X40)||  //控制器过温
               (TYBJ_state[5]&0X01)||  //电机过温
               (DC_fault==1)       ||  //电池故障
               (DC_Status[1]&0X20) ||  //电池过热
               (DC_Status[3]&0X01) ||  //电池火灾
               (DC_Status[1]&0X02) ||  //烟雾报警
               (YW_Status[1]>0)    ||  //整车烟雾报警        20171030增加
              //mKL2               ||  //门铃开关
                mKL4               ||  //应急阀开启报警开关
                LED8               ||  //气压1  2   
              //LED16              ||  //左转向灯报警 
              //LED21                  //右转向灯报警    
               (Vspeed > 690)          //超速报警       
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
         
    if(IN5) OC1RS=e_backlight;  //小灯开关 
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
    temp.bit1 = IN18; //慢档      
    temp.bit2 = IN19; //间歇
    temp.bit3 = IN20; //快档
    temp.bit4 = IN21; //喷水        
    if (IN18 && IN20)temp.bit1 = 0;
    if (IN21) {
        temp.bit1 = 0;//慢档
        temp.bit2 = 0;//间歇
        temp.bit3 = 0;//快档
    }
    message_POUT.data[6]=temp.byte;

    message_POUT.data[7] = 0;
    message_POUT.len = 8;
    message_POUT.type = 1;
    CAN1_SendMessage(&message_POUT);
}

void BCAN_send_mile(void) {
    CAN_MESSAGE msg;
    msg.data[0] = (unsigned char) (e_total_miles); //低八位
    msg.data[1] = (unsigned char) (e_total_miles >> 8); //二级八位
    msg.data[2] = (unsigned char) (e_total_miles >> 16); //三级八位
    msg.data[3] = (unsigned char) (e_total_miles >> 24); //高八位
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
    msg.data[0] = bcd[6];   //年 
    msg.data[1] = bcd[5];   //月
    msg.data[2] = bcd[4];   //日
    msg.data[3] = bcd[2];   //时 
    msg.data[4] = bcd[1];   //分    
    msg.data[5] = bcd[0];   //秒
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
    unsigned char xz=1;//0电阻  1电压
    
    temp.bit0 = rKL10||rKL12; //气压低报警
    temp.bit1 = rKL8; //驻车信号
    temp.bit2 = mKL12;//后仓门
    temp.bit3 = mKL15;//前门开
    temp.bit4 = mKH1; //后门开
    temp.bit5 = M_ON; //二挡
    temp.bit6 = M_ON; //一档
    temp.bit7 = 0;
    msg.data[0] =temp.byte;
    
    temp.bit0 = M_PO3; //后雾灯
    temp.bit1 = F_PO13;//近光灯
    temp.bit2 = 0;     //发动机预热
    temp.bit3 = 0;     //油量报警
    temp.bit4 = F_PO6; //右转向灯
    temp.bit5 = F_PO4; //前雾灯
    temp.bit6 = F_PO9; //远光灯
    temp.bit7 = F_PO7; //左转向灯
    msg.data[1] =temp.byte;
    
    msg.data[2] = 0;
    msg.data[3] = (unsigned char)(Vspeed/5); //车速  
    
if(xz==0){
    temp1=ADR[1];//电阻式
    if(temp1>10 && temp1<185)temp1=(unsigned int)(57.143*(temp1-10));  
    else                     temp1=0;
    msg.data[4]=(unsigned char)(temp1);
    msg.data[5]=(unsigned char)(temp1>>8);

    temp1=ADR[2];//电阻式
    if(temp1>10 && temp1<185)temp1=(unsigned int)(57.143*(temp1-10));  
    else                     temp1=0;
    msg.data[6]=(unsigned char)(temp1);
    msg.data[7]=(unsigned char)(temp1>>8);
    
}else {
    
    temp1=ADV[4]/10;//电压式
    if(temp1>=50 && temp1<=300)temp1=(unsigned int)(40*(temp1-50));  
    else                       temp1=0;
    msg.data[4]=(unsigned char)(temp1);
    msg.data[5]=(unsigned char)(temp1>>8);

    temp1=ADV[5]/10;//电压式
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
void DM_HCU(unsigned char x) {//解析出第x个故障码的spn和fmi
    hcu_spn = CAN_18FECAEF.bData[2 + 4 * (x - 1)]
            +((unsigned int) CAN_18FECAEF.bData[3 + 4 * (x - 1)] << 8)
            +((unsigned long) (CAN_18FECAEF.bData[4 + 4 * (x - 1)]&0xE0) << 11);
    hcu_fmi = (CAN_18FECAEF.bData[4 + 4 * (x - 1)] & 0x1F);
    //if(hcu_spn==103) hcu_spn=0;//随州那边103故障码无法消除
}

void DM_TCU(unsigned char x) {//解析出第x个故障码的spn和fmi
    tcu_spn = CAN_18FECA03.bData[2 + 4 * (x - 1)]
            +((unsigned int) CAN_18FECA03.bData[3 + 4 * (x - 1)] << 8)
            +((unsigned long) (CAN_18FECA03.bData[4 + 4 * (x - 1)]&0xE0) << 11);
    tcu_fmi = (CAN_18FECA03.bData[4 + 4 * (x - 1)] & 0x1F);
}

void DM_CCU(unsigned char x) {//解析出第x个故障码的spn和fmi
    ccu_spn = CAN_18FECAF5.bData[2 + 4 * (x - 1)]
            +((unsigned int) CAN_18FECAF5.bData[3 + 4 * (x - 1)] << 8)
            +((unsigned long) (CAN_18FECAF5.bData[4 + 4 * (x - 1)]&0xE0) << 11);
    ccu_fmi = (CAN_18FECAF5.bData[4 + 4 * (x - 1)] & 0x1F);
}

void DM_ECU(unsigned char x) {//解析出第x个故障码的spn和fmi
    ecu_spn = CAN_18FECA00.bData[2 + 4 * (x - 1)]
            +((unsigned int) CAN_18FECA00.bData[3 + 4 * (x - 1)] << 8)
            +((unsigned long) (CAN_18FECA00.bData[4 + 4 * (x - 1)]&0xE0) << 11);
    ecu_fmi = (CAN_18FECA00.bData[4 + 4 * (x - 1)] & 0x1F);
}
*/

void __attribute__((__interrupt__, auto_psv)) _C1Interrupt(void) {
    unsigned char i=0,j=0;
    CAN_MESSAGE message;
    if (C1INTFbits.ERRIF) { //接收错误
        C1INTFbits.ERRIF = 0; // 添加错误处理代码
        CAN1_Init();
        C1RX0CONbits.RXFUL = 0;
    }
    if (C1INTFbits.IVRIF) {
        C1INTFbits.IVRIF = 0; //数据无效
        C1RX0CONbits.RXFUL = 0;
    }
    if (C1INTFbits.WAKIF) {
        C1INTFbits.WAKIF = 0;
    }


    if (C1RX0CONbits.RXFUL) { //数据有效
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
                for (j = 0; j < 4; j++) {//输出状态采集
                    for (i = 0; i < 4; i++) {
                        fPF[i + 4 * j] = (message.data[j + 2] >> (i * 2))&0x03;
                    }
                }
                fMK_Version=message.data[6];//模块版本号
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
                mMK_Version=message.data[6];//模块版本号
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
                rMK_Version=message.data[6];//模块版本号
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

/*******************分包处理*****************/

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
/*******************分包处理*****************/

unsigned int CAN_BAT_COUNT=0;
unsigned int CAN_DRIVE_COUNT=0;

//整车控制器变量 
unsigned int   DJcontroler_voltage=10000;//电机控制器输入电压
unsigned int   DJcontroler_current=10000; //电机控制器入电流高
unsigned int   DJ_torque=32000; //转矩Torque 
unsigned int   DJ_speed=0;

unsigned char  DJ_temperature=40;             //驱动电机温度
unsigned char  DJcontroler_temperature=40;    //驱动电机控制器温度
unsigned char  FDJ_temperature=40;            //发电机温度
unsigned char  FDJcontroler_temperature=40;   //发电机控制器温度
unsigned char  DR_state=0x80;                 //司机操作状态
unsigned char  KEY_state=0;                   //开关量状态
unsigned char  system_state=0;                //系统工作状态
unsigned int   system_fault=0;                //系统故障码

unsigned  int  EngineSpeed=0;
unsigned char  WaterTem=40;
unsigned char  EngineLoad=0;     //发动机负荷率
unsigned char  urea_high=0;      //尿素液位
unsigned char  speed_st1=0;      //发动机目标油门踏板状态
unsigned char  speed_st2=0;      //发动机实际油门踏板
unsigned char  controler_LIFE=0; //整车控制器Life

unsigned char  traction_st=0;   //牵引踏板百分比
unsigned char  brake_st=0;      //制动踏板百分比
unsigned char  engine_oil_press=0;        //发动机机油压力
unsigned char  ambient_air_temperature=40;//发动机进气温度
unsigned long  total_fuel=0;     //发动机累计油（气）耗量

unsigned char  debug_num[8]; //调试参数1

unsigned int   DJ_torqueST=0; //驱动电机目标转矩
unsigned int   EngineSpeST=0; //发动机目标转速
unsigned char  instantaneous_fuel=0; //瞬态燃油经济性
unsigned int   single_BGLfuel=0;     //小计百公里油耗
unsigned int   total_BGLfuel=0;      //总计百公里油耗

unsigned char  KZQversion[7];
unsigned char  FDJversion[7];  //程序版本号高 3字节
unsigned char  DJversion[7];   //程序版本号高 3字节

unsigned int   anode_R;     //正端对地绝缘电阻
unsigned int   negative_R;  //负端对地绝缘电阻
unsigned char  eror_R;      //绝缘故障等级
unsigned char  R_life;      //
unsigned char  R_ID=0XAA;   //整车漏电报警

unsigned int   DCDC_SC_voltage=10000;
unsigned int   DCDC_SC_current=10000;
unsigned int   DCDC_SR_voltage=10000;
unsigned char  DCDC_temperature=40;
unsigned char  DCDC_fault=0;         //DCDC故障码

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
unsigned char  KT_MODE=0;//空调选择模式  0电动 1传统
unsigned char  KT_temp1[3]={60,60,60};//精度0.5 偏移量-30

unsigned int   DC_voltage=10000; //电池电压 
unsigned int   DC_current=10000; //电池电流 
unsigned char  DC_SOC=0;
unsigned char  DC_Status[6]={0,0,0,0x08,0,0};

unsigned int   Vmax=10000;//最大单体电压
unsigned char  Vmax_num;  //最大单体电压组号
unsigned char  Tmax=40;   //最大单体电池温度
unsigned char  Tmax_num;  //最大单体电池温度组号
unsigned int   Vmin=10000;//最小单体电压
unsigned char  Vmin_num;  //最小单体电压组号 
 
unsigned int   CD_current=10000; //当前最大允许充电电流
unsigned int   FD_current=10000; //当前最大允许放电电流
unsigned char  DC_fault=0;       //系统故障等级
unsigned char  Tmin=40;          //最低单体电池温度
unsigned char  Twater=40;        //进水口温度
unsigned char  DC_JCQst[2]={0,0}; //电池接触器请求断开标识

unsigned char  KT_fuhe=0; //空调实际工作负荷
unsigned char  CAR_MODE=0;//整车模式-自检-快充-慢充
unsigned char  XHLC=0;    //续航里程
unsigned char  TYBJ_state[8]={0,0,0,0,0,0,0,0};//通用报警标志

unsigned int   Vpj=10000;//单体平均电压

unsigned char  Tmax1=40;//最大单体电池温度

unsigned int   anode_R1=0;//正端对地绝缘电阻
unsigned int   negative_R1=0;//负端对地绝缘电阻

unsigned char  VIN_Status=0;//VIN接收状态
unsigned char  CDZ_temp[4]={40,40,40,40};//充电座温度

unsigned int   DC_EDRL=0;  //电池额定容量
unsigned int   DC_EDDY=0;  //电池额定电压
unsigned int   DC_CL_SUM=0;//电池单体串联数量
unsigned char  DC_BL_SUM=0;//电池单体并联数量 
unsigned char  DC_WD_SUM=0;//电池系统温度探针

unsigned char  Tmax_box=0;//最大单体电池温度箱号
unsigned char  Tmin_box=0;//最小单体电池温度箱号
unsigned char  Vmax_box=0;//最大单体电池电压箱号
unsigned char  Vmin_box=0;//最小单体电池电压箱号
unsigned char  Tmin_num=0;//最小单体电池温度组号

unsigned char  DC_style=0;//电池类型
unsigned char  DC_LengQ=0;//电池冷却方式

unsigned int   BAT_vol[10]={10000,10000,10000,10000,10000,10000,10000,10000,10000,10000};//单体正反向电压
unsigned int   BAT_num[10]={0,0,0,0,0,0,0,0,0,0};//单体正反向电压编号

unsigned char  BAT_temp[10]={40,40,40,40,40,40,40,40,40,40};//单体正反向温度
unsigned char  BAT_num1[10]={0,0,0,0,0,0,0,0,0,0};//单体正反向温度编号

unsigned char  MHQ_DCBOX=0;//灭火器电池箱号
unsigned char  MHQ_YJJB=0; //灭火器系统预警级别
unsigned char  MHQ_fault=0;//灭火器故障码

unsigned char  MHQ_TIME=0;//请求校时
unsigned char  YW_Status[6]={0,0,0,0,0,0};//烟雾报警

unsigned char  YZT_LIFE=0;//云智通状态

unsigned int   XDC_current=32000; //蓄电池电流  
unsigned int   XDC_voltage=0; //蓄电池电压                
unsigned char  PDH_temp=40;//配电盒温度

void __attribute__((__interrupt__, auto_psv)) _C2Interrupt(void) {
    unsigned char i=0; 
    CAN_MESSAGE msg;
    IEC2bits.C2IE = 0; 
    
    if (C2INTFbits.ERRIF) { //接收错误
        C2INTFbits.ERRIF = 0; // 添加错误处理代码
        CAN2_Init();
        C2RX0CONbits.RXFUL = 0;
    }
    if (C2INTFbits.IVRIF) {
        C2INTFbits.IVRIF = 0; //数据无效
        C2RX0CONbits.RXFUL = 0;
    }
    if (C2RX0CONbits.RXFUL) { //数据有效
        CAN2_ReceiveMessage(&msg);
        ECU_TIME=0;
        switch (msg.id) {
            //整车控制器;
            case 0x0C03A1A7:
                DJcontroler_voltage=((unsigned int)msg.data[1]<<8) + msg.data[0];//电机控制器输入电压
                DJcontroler_current=((unsigned int)msg.data[3]<<8) + msg.data[2]; //电机控制器入电流高
                DJ_torque=((unsigned int)msg.data[5]<<8) + msg.data[4];//电机转矩
                DJ_speed =((unsigned int)msg.data[7]<<8) + msg.data[6];//电机转速
                break;
            case 0x0C04A1A7:
                DJ_temperature=msg.data[0];             //驱动电机温度
                DJcontroler_temperature=msg.data[1];    //驱动电机控制器温度
                FDJ_temperature=msg.data[2];            //发电机温度
                FDJcontroler_temperature=msg.data[3];   //发电机控制器温度
                DR_state=msg.data[4];                   //司机操作状态
                KEY_state=msg.data[5];                  //开关量状态
              //system_state=msg.data[6];               //系统工作状态
                system_fault=(((unsigned int)msg.data[7]<<8) + msg.data[6]); //系统故障码
                break;
            case 0x0C05A1A7:
                EngineSpeed=(((unsigned int)msg.data[1]<<8) + msg.data[0]);
                WaterTem=msg.data[2];
                EngineLoad=msg.data[3];    //发动机负荷率
                urea_high=msg.data[4];     //尿素液位
                speed_st1=msg.data[5];     //发动机目标油门踏板状态
                speed_st2=msg.data[6];     //发动机实际油门踏板
                controler_LIFE=msg.data[7]; //整车控制器Life
                break;
            case 0x0C06A1A7:
                traction_st=msg.data[0];   //牵引踏板百分比
                brake_st=msg.data[1];      //制动踏板百分比
                engine_oil_press=msg.data[2];       //发动机机油压力
                ambient_air_temperature=msg.data[3];//发动机进气温度
                total_fuel=(((unsigned long)msg.data[7]<<24)+
                            ((unsigned long)msg.data[6]<<16)+
                            ((unsigned long)msg.data[5]<<8) + 
                                            msg.data[4]);   //发动机累计油（气）耗量
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
              //DJ_torqueST=(((unsigned int)msg.data[1]<<8) + msg.data[0]); //驱动电机目标转矩
              //EngineSpeST=msg.data[2]; //发动机目标转速
                instantaneous_fuel=msg.data[3];  //瞬时油(气)耗   //小时燃油消耗率
                single_BGLfuel=(((unsigned int)msg.data[5]<<8) + msg.data[4]);  //小计百公里油耗
                total_BGLfuel=(((unsigned int)msg.data[7]<<8) + msg.data[6]);   //总计百公里油耗
                break;
            case 0x0C09A1A7: //整车控制器软件版本号
                KZQversion[0]=msg.data[1];
                KZQversion[1]=msg.data[2];
                KZQversion[2]=msg.data[3];
                KZQversion[3]=msg.data[4];
                KZQversion[4]=msg.data[5];
                KZQversion[5]=msg.data[6];
                KZQversion[6]=msg.data[7];
                break;
            case 0x0C0AA1A7:
                CAR_MODE=msg.data[0];    //整车模式-自检-快充-慢充
                system_state=msg.data[1];//系统工作状态-整车，发电机，电机
                break;
            case 0x0C0CA7F2: //发电机控制器软件版本号
                FDJversion[0]=msg.data[1];
                FDJversion[1]=msg.data[2];
                FDJversion[2]=msg.data[3];
                FDJversion[3]=msg.data[4];
                FDJversion[4]=msg.data[5];
                FDJversion[5]=msg.data[6];
                FDJversion[6]=msg.data[7];
                break;
            case 0x0C0AA7F0: //电机控制器软件版本号
                DJversion[0]=msg.data[1];
                DJversion[1]=msg.data[2];
                DJversion[2]=msg.data[3];
                DJversion[3]=msg.data[4];
                DJversion[4]=msg.data[5];
                DJversion[5]=msg.data[6];
                DJversion[6]=msg.data[7]; 
                break;
            case 0x1819A1A4: // 绝缘检测仪参数
                anode_R=   (((unsigned int)msg.data[0]<<8) + msg.data[1]);  //正端对地绝缘电阻
                negative_R=(((unsigned int)msg.data[2]<<8) + msg.data[3]);  //负端对地绝缘电阻
                eror_R=msg.data[4];    //绝缘故障等级
                R_life=msg.data[5];    //
                R_ID  =msg.data[6];    //整车漏电报警
                break;
            case 0x0C08A79A:  //转发DCDC报文
                DCDC_SC_voltage=(((unsigned int)msg.data[1]<<8) + msg.data[0]); 
                DCDC_SC_current=(((unsigned int)msg.data[3]<<8) + msg.data[2]); 
                DCDC_SR_voltage=(((unsigned int)msg.data[5]<<8) + msg.data[4]); 
                DCDC_temperature=msg.data[6];
                DCDC_fault=msg.data[7]; 
                break;
            case 0x0C09A79B://助力转向DCAC报文ID
                DCAC_W_current=(((unsigned int)msg.data[1]<<8) + msg.data[0]); 
                DCAC_V_current=(((unsigned int)msg.data[3]<<8) + msg.data[2]); 
                DCAC_U_current=(((unsigned int)msg.data[5]<<8) + msg.data[4]); 
                DCAC_temperature=msg.data[6];
                DCAC_fault=msg.data[7]; 
                break;
            case 0x0C01A70A://数据平台1
                XHLC=msg.data[5]; //续航里程  5Km/Bit  最大1000
                break;
            case 0x0C02A70A://数据平台2
                TYBJ_state[0]=msg.data[0];//通用报警标志1
                TYBJ_state[1]=msg.data[1];//通用报警标志2-驱动电机控制器温度报警-绝缘报警
                TYBJ_state[2]=msg.data[2];//通用报警标志3-驱动电机温度报警
                TYBJ_state[3]=msg.data[3];//通用报警标志4
                break;
            case 0x0C03A70A://数据平台3
                TYBJ_state[4]=msg.data[0];//通用报警标志5-控制器过温
                TYBJ_state[5]=msg.data[1];//通用报警标志6-电机超速-电机过温
                TYBJ_state[6]=msg.data[2];//通用报警标志7
                TYBJ_state[7]=msg.data[3];//通用报警标志8   
                break;
            case 0x18FFC09E: //传统空调
                KT_MODE=1;//空调选择模式
                KT_Status[0]=msg.data[0];//空调系统故障代码   
                KT_Status[1]=msg.data[1];//空调系统风机运行状态  
                KT_Status[2]=msg.data[2];//空调系统运行状态   
                KT_temp1[1] =msg.data[3];//车内实际温度
                KT_temp1[0] =msg.data[4];//车外实际温度
                KT_temp1[2] =msg.data[5];//设定温度
                KT_ctrl     =msg.data[6];//空调制冷请求
                KT_life     =msg.data[7];
                break;
            case 0x0C08A7F4:  //电动空调
              //KT_Status[0]=msg.data[0];
                KT_fuhe     =msg.data[0];//空调实际工作负荷
                KT_temp[0]  =msg.data[1];//设定温度
                KT_temp[1]  =msg.data[2];//车外实际温度
                KT_temp[2]  =msg.data[3];//车内实际温度
                KT_current  =(((unsigned int)msg.data[5]<<8) + msg.data[4]); //
                KT_Status[0]=msg.data[6];//空调工作状态
                KT_life     =msg.data[7];
                break;
                //电池电池管理相关报文
            case 0x1818D0F3:
                DC_voltage = (((unsigned int) msg.data[1] << 8) + msg.data[0]); //电池电压 
                DC_current = (((unsigned int) msg.data[3] << 8) + msg.data[2]); //电池电流 
                DC_SOC = msg.data[4];
                DC_Status[0] = msg.data[5];
                DC_Status[1] = msg.data[6];
                DC_Status[2] = msg.data[7];
                break;
            case 0x1819D0F3:
                CD_current = (((unsigned int) msg.data[1] << 8) + msg.data[0]); //当前最大允许充电电流
                FD_current = (((unsigned int) msg.data[3] << 8) + msg.data[2]); //当前最大允许放电电流
                DC_fault = msg.data[4]; //系统故障等级
                Vpj = (((unsigned int) msg.data[6] << 8) + msg.data[5]); //单体平均电压
                Tmax1 = msg.data[7]; //最大单体电池温度
                //Twater=msg.data[6]; //进水口温度
                //DC_JCQst[1]=msg.data[7]; //电池接触器请求断开标识
                break;
            case 0x181AD0F3:
                anode_R1 = (((unsigned int) msg.data[1] << 8) + msg.data[0]); //正端对地绝缘电阻
                negative_R1 = (((unsigned int) msg.data[3] << 8) + msg.data[2]); //负端对地绝缘电阻
                Vmax = (((unsigned int) msg.data[5] << 8) + msg.data[4]); //最大单体电压
                Vmin = (((unsigned int) msg.data[7] << 8) + msg.data[6]); //最小单体电压
                break;
            case 0x181BD0F3:
                VIN_Status   = msg.data[0]; //VIN接收状态
                DC_Status[3] = msg.data[1];
                CDZ_temp[0]  = msg.data[2]; //充电座温度1
                CDZ_temp[1]  = msg.data[3]; //充电座温度2
                CDZ_temp[2]  = msg.data[4]; //充电座温度3
                CDZ_temp[3]  = msg.data[5]; //充电座温度4
                DC_Status[5] = msg.data[6]; //现行故障数量
                DC_Status[4] = msg.data[7]; //
                break;
            case 0x181CD0F3:
                DC_EDRL = (((unsigned int) msg.data[1] << 8) + msg.data[0]); //电池额定容量
                DC_EDDY = (((unsigned int) msg.data[3] << 8) + msg.data[2]); //电池额定电压
                DC_CL_SUM = (((unsigned int) msg.data[5] << 8) + msg.data[4]); //电池单体串联数量
                DC_BL_SUM = msg.data[6]; //电池单体并联数量
                DC_WD_SUM = msg.data[7]; //电池系统温度探针
                break;
            case 0x181DD0F3:
                Tmax     = msg.data[0]; //最大单体电池温度
                Tmax_box = msg.data[1]; //最大单体电池温度箱号
                Tmax_num = msg.data[2]; //最大单体电池温度组号
                Tmin     = msg.data[3]; //最小单体电池温度
                Tmin_box = msg.data[4]; //最小单体电池温度箱号
                Tmin_num = msg.data[5]; //最小单体电池温度组号
                DC_style = msg.data[6]; //电池类型
                DC_LengQ = msg.data[7]; //电池冷却方式
                break;
            case 0x181ED0F3:
                Vmax_box = msg.data[0]; //最大单体电池电压箱号
                Vmax_num = msg.data[1]; //最大单体电池电压组号
                Vmin_box = msg.data[2]; //最小单体电池电压箱号
                Vmin_num = msg.data[3]; //最小单体电池电压组号
                break;
            case 0x180028F3:
                BAT_vol[0] = (((unsigned int) msg.data[2] << 8) + msg.data[1]); //单体1正向电压
                BAT_num[0] = (((unsigned int) msg.data[6] << 8) + msg.data[0]); //单体1正向电压编号
                BAT_vol[1] = (((unsigned int) msg.data[5] << 8) + msg.data[4]); //单体2正向电压
                BAT_num[1] = (((unsigned int) msg.data[7] << 8) + msg.data[3]); //单体2正向电压编号
                break;
            case 0x180128F3:
                BAT_vol[2] = (((unsigned int) msg.data[2] << 8) + msg.data[1]); //单体3正向电压
                BAT_num[2] = (((unsigned int) msg.data[6] << 8) + msg.data[0]); //单体3正向电压编号
                BAT_vol[3] = (((unsigned int) msg.data[5] << 8) + msg.data[4]); //单体4正向电压
                BAT_num[3] = (((unsigned int) msg.data[7] << 8) + msg.data[3]); //单体4正向电压编号
                break;
            case 0x180228F3:
                BAT_vol[4] = (((unsigned int) msg.data[2] << 8) + msg.data[1]); //单体5正向电压
                BAT_num[4] = (((unsigned int) msg.data[6] << 8) + msg.data[0]); //单体5正向电压编号
                BAT_vol[5] = (((unsigned int) msg.data[5] << 8) + msg.data[4]); //单体1反向电压
                BAT_num[5] = (((unsigned int) msg.data[7] << 8) + msg.data[3]); //单体1反向电压编号
                break;
            case 0x180328F3:
                BAT_vol[6] = (((unsigned int) msg.data[2] << 8) + msg.data[1]); //单体2反向电压
                BAT_num[6] = (((unsigned int) msg.data[6] << 8) + msg.data[0]); //单体2反向电压编号
                BAT_vol[7] = (((unsigned int) msg.data[5] << 8) + msg.data[4]); //单体3反向电压
                BAT_num[7] = (((unsigned int) msg.data[7] << 8) + msg.data[3]); //单体3反向电压编号
                break;
            case 0x180428F3:
                BAT_vol[8] = (((unsigned int) msg.data[2] << 8) + msg.data[1]); //单体4反向电压
                BAT_num[8] = (((unsigned int) msg.data[6] << 8) + msg.data[0]); //单体4反向电压编号
                BAT_vol[9] = (((unsigned int) msg.data[5] << 8) + msg.data[4]); //单体5反向电压
                BAT_num[9] = (((unsigned int) msg.data[7] << 8) + msg.data[3]); //单体5反向电压编号
                break;
            case 0x180028F4:
                BAT_num1[0] = msg.data[0]; //单体1正向温度编号
                BAT_temp[0] = msg.data[1]; //单体1正向温度
                BAT_num1[1] = msg.data[2]; //单体2正向温度编号
                BAT_temp[1] = msg.data[3]; //单体2正向温度
                BAT_num1[2] = msg.data[4]; //单体3正向温度编号
                BAT_temp[2] = msg.data[5]; //单体3正向温度
                BAT_num1[3] = msg.data[6]; //单体4正向温度编号
                BAT_temp[3] = msg.data[7]; //单体4正向温度
                break;
            case 0x180128F4:
                BAT_num1[4] = msg.data[0]; //单体5正向温度编号
                BAT_temp[4] = msg.data[1]; //单体5正向温度
                BAT_num1[5] = msg.data[2]; //单体1反向温度编号
                BAT_temp[5] = msg.data[3]; //单体1反向温度
                BAT_num1[6] = msg.data[4]; //单体2反向温度编号
                BAT_temp[6] = msg.data[5]; //单体2反向温度
                BAT_num1[7] = msg.data[6]; //单体3反向温度编号
                BAT_temp[7] = msg.data[7]; //单体3反向温度
                break;
            case 0x180228F4:
                BAT_num1[8] = msg.data[0]; //单体4正向温度编号
                BAT_temp[8] = msg.data[1]; //单体4正向温度
                BAT_num1[9] = msg.data[2]; //单体5反向温度编号
                BAT_temp[9] = msg.data[3]; //单体5反向温度
                break;
            case 0x18EBA1A5:
                MHQ_DCBOX = msg.data[0]; //灭火器电池箱号
                MHQ_YJJB  = msg.data[1]; //灭火器系统预警级别
                MHQ_fault = msg.data[2]; //灭火器故障码
                break;
            case 0x18EFA1A5:
                MHQ_TIME = 0XAA; //请求校时
                break;
            case 0x1819A100:
                YW_Status[0] = msg.data[0]; //从站生命状态
                YW_Status[1] = msg.data[1]; //从站火警状态
                YW_Status[2] = msg.data[2]; //从站接线状态
                YW_Status[3] = msg.data[3]; //从站硬件状态
                YW_Status[4] = msg.data[6]; //系统火警状态
                YW_Status[5] = msg.data[7]; //LIFE
                break;
            case 0x180AA7A3:
                YZT_LIFE = msg.data[6];//终端状态 0XFF：显示网络正常符号片，非FF时显示异常符号片，见符号片定义  20170816添加  
                break;     
            case 0x18FE521E:
                XDC_current = (((unsigned int) msg.data[3] << 8) + msg.data[2]); //蓄电池电流  
                XDC_voltage = (((unsigned int) msg.data[5] << 8) + msg.data[4]); //蓄电池电压                
                PDH_temp    =  msg.data[6];//配电盒温度
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

void __attribute__((__interrupt__, auto_psv)) _T1Interrupt(void) {//10ms中断一次
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
    //报警延时3s标记
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

    if (delay_cnt > 0) delay_cnt--; //延时计数器 
    if (delay_5s > 0)  delay_5s--; //延时计数器     

    if (cnt0 >= 4) {//50ms
        cnt0 = 0;              
        BCAN_send_mile();
        BCAN_SendCtl();
        if (M_ON_flag && (wake_up3 || wake_up2)) {//wake_up3置0时，M_ON不会立马置0，因为存在消抖延时
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
                 if(MHQ_TIME==0xAA){MHQ_TIME=0;PCAN_send_time();}//时间        
        }else if(can2==1){
                 can2=2;
                 PCAN_send_yb();//气压 
        }else if(can2==2){
                 can2=3;
                 PCAN_send_speed();//车速
        }else if(can2==3){
                 can2=0;
               //PCAN_send_mile();//里程  
               //PCAN_send_test();//仪表调试用
        }
        
        //计算累计里程
        //if (pSpeed > 0) {//车速大于0时才累计
        //    mile = mile + (float) (pSpeed / 3.6 * 0.1);
        if (Vspeed/10 > 0) {//车速大于0时才累计
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
        //CAN节点故障计时3s
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

    if (wake_up3) { //ON开关判断//消抖//M_ON在掉电的一瞬间会使上拉电源无效，而M_ON在断电会保持300ms，从而影响开关量采集
        if (cnt3 > 30) M_ON = 1;
        else cnt3++;
    } else {
        if (cnt3 < 1) M_ON = 0;
        else cnt3--;
    }
    
    // 涉及到按键逻辑
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
        key_up = 1; //向上按键
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
        if (lpcnt2 >= 300) {//长按SET按钮
            lpcnt2 = 0;
            bkey_set = 1; //长按时取消单按键操作
            key_long_set = 1;           
        } else lpcnt2++;
    } else {
        lpcnt2 = 0;
    }

    if (KEY_AV && KEY_UP) {
        if (lpcnt1 >= 300) {//组合按钮，长按AV和UP按钮
            lpcnt1 = 0;
            bkey_AV = 1; //长按时取消单按键操作
            bkey_up = 1; //长按时取消单按键操作
            key_duble = 1; //隐含功能按键
        } else lpcnt1++;
    } else {
        lpcnt1 = 0;
    }

    if (KEY_AV && (KEY_UP == 0)) { //长按 2S 清零单里程 长按AV
        if (lpcount >= 200) {
            single_miles = 0;
            save_flag = 1;
            bkey_AV = 1; //长按时取消单按键操作
            lpcount = 100;
        } else lpcount++;
    } else if (lpcount > 0) lpcount--;

    _T1IF = 0;
}
/*
void TIMER4_Init(void) {
    TMR4=0;
    T4CON = 0x0010; // 1：8分频 Fcy/8 16MHZ/8=2MHz
    PR4 = 19999;  //10ms中断一次 
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


