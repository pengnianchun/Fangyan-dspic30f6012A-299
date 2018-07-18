#include "SYSTEM.h"
//#include "LOGO.h"
unsigned int delay_cnt;
unsigned int delay_5s;
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
unsigned int Kcan_count = 0; //电机控制器

unsigned int Hcan_count = 0; //灭火器
unsigned int Jcan_count = 0; //记录仪   绝缘检测
unsigned int Ccan_count = 0; //DCDC
unsigned int Qcan_count = 0; //气泵
unsigned int Ycan_count = 0; //油泵
unsigned int JYcan_count =0; //绝缘监测仪
unsigned int Tcan_count = 0; //时间计时
unsigned int ECU_TIME;
unsigned int QY_count   = 0; //气压延时处理

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

unsigned int ADR[8]; //模拟量采集   10/15
unsigned int ADV[8]; //模拟量采集 

DBCM_POUT fPOUT; //前模块功率输出状态
DBCM_POUT mPOUT; //中（顶）模块功率输出状态
DBCM_POUT rPOUT; //后模块功率输出状态

unsigned char fPF[16]; //前模块功率输出故障
unsigned char mPF[16]; //中（顶）模块功率故障
unsigned char rPF[16]; //后模块功率输出故障

unsigned int fpcur[15]; //前模块功率输出电流
unsigned int mpcur[15]; //中模块功率输出电流
unsigned int rpcur[15]; //后模块功率输出电流

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
    unsigned char i,j;
    unsigned char count=10;
    ADPCFG = 0xffff; //关闭AD口     
    alarm_led[0].byte = 0xff; //消除开机瞬间LED和蜂鸣器闪烁
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
        PWR_CTRL_DR = 0;
        PWR_CTRL = 1; 
        /*
        if (wake_up1) {//如果危险报警唤醒
            PWR_CTRL_DR = 0;
            PWR_CTRL = 1;
            F_PO6 = FLASH;//左转向灯
            F_PO7 = FLASH;//右转向灯
        } else {
            F_PO6 = 0;
            F_PO7 = 0;
        }
            R_PO6 = F_PO6; //左转向灯
            R_PO7 = F_PO7; //右转向灯
            LED4  = F_PO6; //左转向报警
            LED8  = F_PO7; //右转向报警   
            BUZZ  = !(LED8 || LED4);//转向蜂鸣
        */    
            
        if (F50ms) {
            F50ms = 0;
            SYSTME_Logic();
            LED4  = F_PO6; //左转向报警
            LED8  = F_PO7; //右转向报警  
            if(wake_up1==0){LED4=0;LED8=0;} 
          //BUZZ  = !(LED8 || LED4); //转向蜂鸣 
            if(wake_up1)BUZZ  = !FLASH;else BUZZ  = 1; 
            
            LED_Out();
            SW_Input();
            BCAN_SendCtl();
        }

        if (M_ON && wake_up3) break; // 如果是ON唤醒则正常退出

        if (M_ACC){
          //disp_LOGO();
          //disp_Door();
          //LCD_BackLight(7);
            LED10 = 1; //总电源指示            
        }else{
            LCD_BackLight(0);
            LED10 = 0; //总电源指示
        }
        
        if ((wake_up1 == 0)&&(wake_up2 == 0)&&(wake_up3 == 0)) {
            F_PO6 = 0;
            F_PO7 = 0;
            R_PO6 = F_PO6; //左转向灯
            R_PO7 = F_PO7; //右转向灯
            LED4  = F_PO6; //左转向报警
            LED8  = F_PO7; //右转向报警    
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
    Count_ADR();
    /*
    //调试用
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
    //电压型传感器采集  ADV[]是实际的电压*1000
    ADV[3] = (unsigned int) (read_ADR(3) / ad * 3500) + 0.3*ADV[3];
    ADV[4] = (unsigned int) (read_ADR(4) / ad * 3500) + 0.3*ADV[4];
    ADV[5] = (unsigned int) (read_ADR(5) / ad * 3500) + 0.3*ADV[5]; 
    ADV[6] = (unsigned int) (read_ADR(6) / ad * 3500) + 0.3*ADV[6];
    //蓄电池电压    
    ADR[0] = (unsigned int) (550.0 * read_VOL() / ad); //实际电压放大10倍   //(read_VOL() - 1300)*10 / 76 + 180;
    if (ADR[0] >= 180) BAT24V_count = 0;
    //电阻型传感器采集  ADR[]是实际的阻值
    //ADR[1] = (unsigned int) (100.0 * read_ADR(1) / (ad - read_ADR(1))); //((read_ADR(1) / ad * 100) / (1 - read_ADR(1) / ad));
    ADR[1] = (unsigned int) (70.0 * read_ADR(1) / (ad - read_ADR(1))) + 0.3*ADR[1];
    ADR[2] = (unsigned int) (70.0 * read_ADR(2) / (ad - read_ADR(2))) + 0.3*ADR[2];
    ADR[3] = (unsigned int) (70.0 * read_ADR(3) / (ad - read_ADR(3))) + 0.3*ADR[3];
    ADR[4] = (unsigned int) (70.0 * read_ADR(4) / (ad - read_ADR(4))) + 0.3*ADR[4];
    ADR[5] = (unsigned int) (70.0 * read_ADR(5) / (ad - read_ADR(5))) + 0.3*ADR[5];
    ADR[6] = (unsigned int) (70.0 * read_ADR(6) / (ad - read_ADR(6))) + 0.3*ADR[6];   
    
    if (ADR[1] > 1000)ADR[1] = 1000;      
    if (ADR[2] > 1000)ADR[2] = 1000;       
    if (ADR[3] > 1000)ADR[3] = 0;      
    if (ADR[4] > 1000)ADR[4] = 0;  
    if (ADR[5] > 1000)ADR[5] = 0;
    if (ADR[6] > 1000)ADR[6] = 0;
  
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
    F_PO4  = (IN17);                            //电喇叭
    F_PO5  = (M_ACC||M_ON);                     //钥匙电源
    F_PO6  = (FLASH && (IN1 || wake_up1));      //左转向灯
    F_PO7  = (FLASH && (IN5 || wake_up1));      //右转向灯
    
    if (mKL15 && QY_EN) {QY_TIME = 40;QY_EN = 0;}        //投币机开门信号
    if ( (QY_TIME > 30) ||
        ((QY_TIME < 20) && (QY_TIME > 10))
       ) F_PO8 = 1;
    else F_PO8 = 0;
    if (QY_TIME > 0)QY_TIME--;                               
    if(mKL15==0)QY_EN=1;
        
    F_PO9  = (IN7 && !IN8 );                    //远光灯      
    F_PO10 = (IN6 && IN9);                      //前雾灯
    F_PO11 = (IN8);                             //近光灯
    if(VCU_Status[1] &0x40)F_PO12 = 1;          //倒车电源 
    else                   F_PO12 = 0;                       
    F_PO13 = (M_ACC||M_ON);                     //钥匙电源 
    F_PO14 = (IN6);                             //位置灯
    F_PO15 = (R_PO2);                           //刹车信号输出
    F_PO16 =  0;                                //励磁电流

    R_PO1 =   F_PO12;                           //倒车灯
    if((VCU_Status[0] &0x80)||(VCU_Status[1] &0x08)||rKL3 )R_PO2 = 1;else R_PO2 = 0;//制动灯                   
    R_PO3  = (IN10 && (F_PO10||F_PO9||F_PO11)); //后雾灯     
    R_PO4  = (M_ON);                            //ON档信号
    R_PO5  = (IN6 && mKL15);                    //前门踏步灯
    R_PO6  =  F_PO6;                            //左转向灯
    R_PO7  =  F_PO7;                            //右转向灯
    R_PO8  = (M_ON);                            //干燥器电源
    R_PO9  = (IN6 && mKH1);                     //中门踏步灯 
    R_PO10 = (M_ACC||M_ON);                     //总电源继电器
    R_PO11 = (M_ACC||M_ON);                     //钥匙电源    
    R_PO12 = (F_PO14);                          //小灯
    R_PO13 = (M_ACC||M_ON);                     //USB电源    
    R_PO14 =  0;                                //
    R_PO15 =  0;                                //
    R_PO16 =  0;                                //励磁电流  
    
    M_PO1  =  R_PO5;                            //前门踏步灯
    M_PO2  = (M_ACC||M_ON);                     //门泵电源
    M_PO3  = (IN25);                            //广告灯箱
    M_PO4 =   R_PO9;                            //中门踏步灯
    M_PO5  = (IN27 && (Vspeed<10));             //中门开门电磁阀
    M_PO6  = (IN26);                            //中门关门电磁阀
    M_PO7  = (IN19);                            //路牌（前） 
    M_PO8  = (IN23);                            //顶灯1
    M_PO9  = (IN24);                            //顶灯2
    M_PO10 = (IN22);                            //驾驶员顶灯
    M_PO11 = (M_PO7);                           //路牌（侧）
    M_PO12 = (M_PO7);                           //路牌（后）
    M_PO13 = (F_PO14);                          //小灯电源
    M_PO14 = (IN20 && (Vspeed<10));             //前门开门电磁阀
    M_PO15 = (IN28);                            //前门关门电磁阀
    M_PO16 =  0;                                //励磁电流

    
}

void LED_Logic(void) {
    LED3  = 0; //空挡指示    
    LED5  = 0; //前进挡指示    
    LED23 = 0; //缓速器
    LED13 = 0; //电机故障 
    
    LED10 = 1; //总电源指示     
    
    LED15 = F_PO14; //小灯   
    
    LED4  = F_PO6;  //左转向灯
    LED8  = F_PO7;  //右转向灯   
    
    LED22 = F_PO11; //近光灯    
    LED17 = F_PO9;  //远光灯     
    
    LED19 = F_PO10; //前雾灯
    LED20 = R_PO3;  //后雾灯    
    
    LED1  = mKL15;  //前门开指示
    LED2  = mKH1;   //中门开指示   

    if((VCU_Status[1] & 0x80)|| rKL8)LED18 = 1;else LED18 = 0;//手刹
    LED24 = R_PO2;  //刹车指示      
    
    LED21 = F_PO12; //倒车灯
    if(BAT24V_count >= BAT24_TIME)LED16=1;else LED16=0;//蓄电池电压低     
    
//////////////////////////////////////////////////////
//压力   0    0.1    0.2   0.4    0.6    0.8    1   //
//电压  0.5   0.725   1    1.5     2     2.5    3   //
/////////////////////////////////////////////////////
    if( //IN11               ||
        //rKL10              ||
        //((ADV[3]/10)<200) ||  
          (ADR[1]<115)
      )LED9=1; else LED9=0; //气压1低于0.55MPa 报警
    
    if( //IN12               ||
        //rKL11              ||    
        //((ADV[4]/10)<200) || 
          (ADR[2]<115)
      )LED11=1;else LED11=0;//气压2低于0.55MPa 报警   
      
    if(DC_Status[0]&0X08)LED7=1;else LED7=0; //充电枪插入  
    
    static unsigned int time100=0;    
    if(DC_current<31900){
       if(time100>100)time100=100;else time100++;
    }else time100=0;
    if(LED7 && (time100>=100))LED6=1;else LED6=0; //充电状态    
    
    if( (DC_Status[1]&0x40) ||  //SOC过低
        (DC_Status[1]&0x08)     //SOC低
       )LED12=0;else LED12=0;   //SOC低报警
    
    if( (((DC_Status[0]&0x06)>>1)==0x01)|| //二级故障：电池内部绝缘一级故障
        (((DC_Status[0]&0x06)>>1)==0x02)|| //二级故障：电池内部绝缘二级故障
          (DC_Status[1]&0x20)           || //一级故障：电池温度过高，停车
          (DC_Status[1]&0x02)           || //一级故障：模块电压过低
          (DC_Status[1]&0x01)              //二级故障：模块电压过高       
       )LED14=1;else LED14=0; //动力电池系统故障    
    
//蜂鸣器 为0时响，为1时不响
         if(    IN1                ||  //左转向灯报警 
                IN5                ||  //右转向灯报警
                wake_up1
           )    BUZZ = !(LED4 || LED8);//
    else if(
                LED9               ||  //气压1  
                LED11                  //气压2   
            )   BUZZ = kFLASH;
    else if(
                LED14              ||  //动力电池系统故障
                (DJ_Status[1]&0x01)    //一级故障：电机控制器过热
            )   BUZZ = FLASH_1s;
    else if( M_ON &&
           (   !fKL4 ||   //左前摩擦片报警
               !fKL5 ||   //右前摩擦片报警
             //!fKL8 ||   //左后摩擦片报警
             //!fKL9 ||   //右后摩擦片报警
              (VCU_Status[0]&0x04)||   //整车控制器气压低报警
              (DC_Status[0]&0x20) ||   //一级故障：烟雾报警
              ((R_ID&0x30)==0x10) ||   //二级故障：二级绝缘故障
              ((R_ID&0x30)==0x20) ||   //一级故障：一级绝缘故障
              
            //((YW_Status[0]&0x0f)==4) ||  //通讯故障 
              ((YW_Status[0]&0x0f)==5) ||  //一级故障：电池仓烟雾气体赌塞故障
              ((YW_Status[0]&0x0f)==6) ||  //一级故障：电池仓烟雾紧急报警          
            //((YW_Status[0]&0x0f)==7) ||  //设备故障
            
            //((YW1_Status[0]&0x07)==4) ||  //通讯故障 
              ((YW1_Status[0]&0x07)==5) ||  //一级故障：电池箱烟雾气体赌塞故障  
              ((YW1_Status[0]&0x07)==6) ||  //一级故障：电池箱烟雾紧急报警
            //((YW1_Status[0]&0x07)==7) ||  //设备故障 
            
              //F_TaiYa            ||  //胎压报警
                fKL3               ||  //门铃开关
                rKL7               ||  //水位
                mKL8               ||  //车内应急阀开启报警开关
                IN34               ||  //车外应急阀开启报警开关 
                LED16              ||  //蓄电池电压低
              //LED9               ||  //气压1  
              //LED11              ||  //气压2   
              //LED4               ||  //左转向灯报警 
              //LED8                   //右转向灯报警    
               (Vspeed > 690)          //超速报警       
            )
       )     BUZZ = 0;//!FLASH;
    else     BUZZ = 1;
    
    
    //背光 小灯开关闭合 
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

//模块
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
    temp.bit1 = IN14; //慢档      
    temp.bit2 = IN15; //间歇
    temp.bit3 = IN16; //快档
    temp.bit4 = IN21; //喷水        
    if (IN14 && IN16)temp.bit1 = 0;
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
    PFF temp;
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
    msg.data[7] = bcd[6];   //年 
    msg.data[6] = bcd[5];   //月
    msg.data[5] = bcd[4];   //日
    msg.data[4] = bcd[2];   //时 
    msg.data[3] = bcd[1];   //分    
    msg.data[2] = bcd[0];   //秒
    
    temp.byte=0;
    temp.Bit1 = rKL15;//后舱门
    temp.Bit2 = LED1; //前门
    temp.Bit3 = LED2; //中门
    temp.Bit4 = 0;    //后门
    msg.data[1] = temp.byte;  
    
    temp.byte=0;
    temp.Bit1 = 0;    //安全门
    temp.bit2 = LED18;//手制动  
    temp.bit3 = IN6;  //夜灯
    temp.bit4 = IN5;  //右转
    temp.bit5 = IN1;  //左转
    temp.bit6 = wake_up1;//双闪
    msg.data[0] = temp.byte; 
    
    msg.id      = 0x18F607bd;   
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
    
    temp=total_miles/10;
    msg.data[0] = (unsigned char) (temp);       
    msg.data[1] = (unsigned char) (temp >> 8 );
    msg.data[2] = (unsigned char) (temp >> 16); 
    msg.data[3] = (unsigned char) (temp >> 24); 
    
    msg.data[4] = Vspeed/10; //      
    msg.data[5] = 0;         //Trip 小计里程清零标志位（ 1： 请求清 0；  0： 无请求）    
    temp=single_miles;
    msg.data[6] = (unsigned char) (temp);         
    msg.data[7] = (unsigned char) (temp >> 8 );        

    msg.id      = 0x18FF304B;    
    msg.len     = 8;
    msg.type    = 0;
    CAN2_SendMessage(&msg);

}


//博世杰行车记录仪1
void PCAN_Send_TCO1(void) {
    CAN_MESSAGE msg;
    msg.data[0] = 0;
    msg.data[1] = 0;
    msg.data[2] = 0;
    msg.data[3] = 0;
    msg.data[4] = 0;
    msg.data[5] = 0;
    msg.data[6] = 0;
    msg.data[7] = (unsigned char)(Vspeed/10);
    msg.id      = 0x0CFE6C21;
    msg.len     = 0x08;
    msg.type    = 0x00;
    CAN2_SendMessage(&msg);
}

//博世杰行车记录仪2
void PCAN_Send_TCO2(void) {
    CAN_MESSAGE msg;
    PF          temp;
    
    temp.bit1 = LED22 ;//近光灯
    temp.bit2 =(LED19 ||LED20 );//雾灯
    temp.bit3 = LED21 ; //倒车灯
    temp.bit4 = F_PO4 ; //喇叭      
    msg.data[0] = temp.byte;                    

    temp.bit1 = 0;    //严重故障
    temp.bit2 = F_PO7;//右转向灯
    temp.bit3 = F_PO6;//左转向灯
    temp.bit4 = (LED1||LED2);//车门开      
    msg.data[1] = temp.byte;   
    
    temp.bit1 = 0;//门强制选择
    temp.bit2 = 0;//
    temp.bit3 = ( (LED9)||(LED11) );//低气压报警
    temp.bit4 = LED17;//远光灯      
    msg.data[2] = temp.byte;   
    
    temp.bit1 = 0;//水温高报警
    temp.bit2 = rKL7;//水位低报警
    temp.bit3 = 0;//空滤报警
    temp.bit4 = 0;//油压报警      
    msg.data[3] = temp.byte;   
    
    temp.bit1 = (LED9);//前气压报警
    temp.bit2 = (LED11);//后气压报警
    temp.bit3 = 0;//
    temp.bit4 = 0;//      
    msg.data[4] = temp.byte;   
    
    temp.bit1 = LED24;//刹车灯
    temp.bit2 = 0;    //缓速器工作
    temp.bit3 = LED1; //门1开
    temp.bit4 = LED2; //门2开      
    msg.data[5] = temp.byte;    
    
    temp.bit1 = 0;//左门3
    temp.bit2 = 0;//左门2
    temp.bit3 = 0;//左门1
    temp.bit4 = 0;//左右门选择 00左门 01右门      
    msg.data[6] = temp.byte;   
    
    temp.bit1 = 0;//右门3
    temp.bit2 = 0;//右门2
    temp.bit3 = 0;//右门1
    temp.bit4 = 0;//车型选择 00普通公交车 01BRT      
    msg.data[7] = temp.byte;   
    
    msg.id      = 0x18FED925;
    msg.len     = 0x08;
    msg.type    = 0x00;
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
    unsigned char i = 0, j = 0;
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

/**************************************************/

unsigned int CAN_BAT_COUNT=0;
unsigned int CAN_DRIVE_COUNT=0;

//整车控制器变量 
unsigned int   DJcontroler_voltage=0;//电机控制器输入电压
unsigned int   DJcontroler_current=32000; //电机控制器入电流高
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
unsigned char  R_life[3]={0,0,0};      //
unsigned char  R_ID=0X00;   //整车漏电报警

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

unsigned int   DC_voltage=0; //电池电压 
unsigned int   DC_current=32000; //电池电流 
unsigned char  DC_SOC=0;
unsigned char  DC_Status[6]={0,0,0,0x00,0,0};

unsigned int   Vmax=10000;//最大单体电压
unsigned char  Vmax_num;  //最大单体电压组号
unsigned char  Tmax=40;   //最大单体电池温度
unsigned char  Tmax_num;  //最大单体电池温度组号
unsigned int   Vmin=10000;//最小单体电压
unsigned char  Vmin_num;  //最小单体电压组号 
 
unsigned int   CD_current=32000; //当前最大允许充电电流
unsigned int   FD_current=32000; //当前最大允许放电电流
unsigned char  DC_fault=0;       //系统故障等级
unsigned char  Tmin=40;          //最低单体电池温度
unsigned char  Twater=40;        //进水口温度
unsigned char  DC_JCQst[2]={0,0}; //电池接触器请求断开标识

unsigned char  KT_fuhe=0; //空调实际工作负荷
unsigned char  CAR_MODE=0;//整车模式-自检-快充-慢充
unsigned int   XHLC=0;    //续航里程
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
unsigned char  YW1_Status[10]={0,0,0,0,0,0,0,0,0,0};//烟雾报警器 检测点在电池箱体内

unsigned char  YZT_LIFE=0;//云智通状态
unsigned char  YZT_Status=0;//云智通故障码

unsigned char  VCU_Status[10]={0,0,0,0,0,0,0,0,0,0};//
unsigned char  DC_BOX_SUM=0;//电池总箱数
unsigned char  Tjc=0;//电池模块的温度极差
unsigned char  DJ_Status[10]={0,0,0,0,0,0,0,0,0,0};//

unsigned char  GZ_Status[10]={0,0,0,0,0,0,0,0,0,0};//
unsigned char  JLY_time[10]={0,0,0,0,0,0,0,0,80,90};//行车记录仪时间

//胎压监测 
 unsigned char Tire_Press[7]={0,0,0,0,0,0,0};
 unsigned int  Tire_Temp[7]={8736,8736,8736,8736,8736,8736,8736}; 
 unsigned char Tire_Status[7]={0x00,0x00,0x00,0x00,0x00,0x00,0x00};
 unsigned char Tire_fault[7]={0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0x00};
 unsigned char Tire_BK_ST=0;//备胎状态


void __attribute__((__interrupt__, auto_psv)) _C2Interrupt(void) {
    unsigned char i = 0;
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
            case  0x18FEF433://
                if (msg.data[0] == 0x00) {//左前
                     Tire_Press[0] = msg.data[1];
                      Tire_Temp[0] = ((unsigned int) (msg.data[3]) << 8) + msg.data[2];
                    Tire_Status[0] = msg.data[4];
                     Tire_fault[0] = msg.data[7];
                } else if (msg.data[0] == 0x03) {//右前01
                     Tire_Press[1] = msg.data[1];
                      Tire_Temp[1] = ((unsigned int) (msg.data[3]) << 8) + msg.data[2];
                    Tire_Status[1] = msg.data[4];
                     Tire_fault[1] = msg.data[7];
                } else if (msg.data[0] == 0x10) {//左后1
                     Tire_Press[2] = msg.data[1];
                      Tire_Temp[2] = ((unsigned int) (msg.data[3]) << 8) + msg.data[2];
                    Tire_Status[2] = msg.data[4];
                     Tire_fault[2] = msg.data[7];
                } else if (msg.data[0] == 0x11) {//左后2
                     Tire_Press[3] = msg.data[1];
                      Tire_Temp[3] = ((unsigned int) (msg.data[3]) << 8) + msg.data[2];
                    Tire_Status[3] = msg.data[4];
                     Tire_fault[3] = msg.data[7];
                } else if (msg.data[0] == 0x12) {//右后1
                     Tire_Press[4] = msg.data[1];
                      Tire_Temp[4] = ((unsigned int) (msg.data[3]) << 8) + msg.data[2];
                    Tire_Status[4] = msg.data[4];
                     Tire_fault[4] = msg.data[7];
                } else if (msg.data[0] == 0x13) {//右后2
                     Tire_Press[5] = msg.data[1];
                      Tire_Temp[5] = ((unsigned int) (msg.data[3]) << 8) + msg.data[2];
                    Tire_Status[5] = msg.data[4];
                     Tire_fault[5] = msg.data[7];
                }
                break; 
            
            case 0x0CFF0A4A://EVCU_ALL： 整车控制器发送的数据 1
                Vcan_count=0;
                VCU_Status[0] = msg.data[7];//
                VCU_Status[1] = msg.data[6];//
                VCU_Status[2] = msg.data[1];//电池故障
                VCU_Status[3] = msg.data[0];//主接触器断开/闭合
                break;   
            case 0x0CFF0B4A://EVCU_ALL：整车控制器发送的数据 2 
                VCU_Status[4] = msg.data[2];//Bit2 ready  Bit1 系统故障  Bit0 二级故障：系统告警        
                break;     
            case 0x0CFF324A://EVCU_INS：整车控制器发送的数据4（CAN1 通道）描述：此帧是整车控制器发送给仪表） 
                XHLC = ((unsigned int)msg.data[7]<<8) + msg.data[6];//续驶里程       
                break;    
            case 0x0CFFEB4A://EVCU_PC： 整车控制器发送的数据 5（CAN1通道）描述：此帧是整车控制器发送给上位机/BMS）
                VCU_Status[5] = msg.data[5];
                VCU_Status[6] = msg.data[1];
                VCU_Status[7] = msg.data[0];
                break;     
            case 0x18FF2848://BMSC1_0：电池管理单元 CAN1 通道发送数据 1 
                Bcan_count=0;
                DC_Status[0] = msg.data[6];
                DC_Status[1] = msg.data[5];
                DC_SOC       = msg.data[4];            
                DC_current = (((unsigned int) msg.data[3] << 8) + msg.data[2]); //电池电流                 
                DC_voltage = (((unsigned int) msg.data[1] << 8) + msg.data[0]); //电池电压      
                break;     
            case 0x18FF2948://BMSC1_1：电池管理单元 CAN1 通道发送数据 2
                DC_BOX_SUM   = msg.data[7]; //电池总箱数
                DC_Status[2] = msg.data[6];//电压不均衡  温度均衡  极柱温度过高  BMS 内部通讯
                Tjc  = msg.data[5]; //电池模块的温度极差
                Tmax = msg.data[4]; //最大单体电池温度
                Tmin = Tmax-(Tjc);
                Vmax = (((unsigned int) msg.data[3] << 8) + msg.data[2]); //最大单体电压
                Vmin = (((unsigned int) msg.data[1] << 8) + msg.data[0]); //最小单体电压
                break;    
            case 0x18FF2A48://MSC1_2： 电池管理单元 CAN1 通道发送数据 3
                Tmax_box = msg.data[3]>>4;   //最大单体电池温度箱号        
                Tmin_box = msg.data[3]&0x0f; //最小单体电池温度组号    
                Vmax_box = msg.data[2]>>4;   //最大单体电池电压箱号
                Vmin_box = msg.data[2]&0x0f; //最小单体电池电压箱号
                Vmax_num = msg.data[1];      //最大单体电池电压节数
                Vmin_num = msg.data[0];      //最小单体电池电压节数  
                break;     
            case 0x18FF2B48://BMS1_3： 电池管理单元 CAN1 通道发送数据 4  
                FD_current = (((unsigned int) msg.data[7] << 8) + msg.data[6]); //当前最大允许放电电流
                CD_current = (((unsigned int) msg.data[5] << 8) + msg.data[4]); //当前最大允许充电电流        
                break;    
            case 0x18FF2B49://绝缘监测仪
                JYcan_count=0;
                R_life[0] = msg.data[7];    //
                anode_R = (((unsigned int)msg.data[1]<<8) + msg.data[2]);  //绝缘电阻
                R_ID    = msg.data[0];    //整车漏电报警
                break;    
            case 0x18FF2C47://MOT_EVCU1：电动/发电机控制器发送数据 1  
                Kcan_count=0;
                DJ_torque=((unsigned int)msg.data[7]<<8) + msg.data[6];//电机转矩
                DJcontroler_voltage=((unsigned int)msg.data[5]<<8) + msg.data[4];//电机控制器直流侧电压
                DJcontroler_current=((unsigned int)msg.data[3]<<8) + msg.data[2]; //电动机直流侧电流
                break;    
            case 0x18FF2D47://MOTC1_1： 电动/发电机控制器发送数据 2    
                DJ_Status[0] = msg.data[7];//电机控制器故障
                DJ_Status[1] = msg.data[6];//电机控制器故障
                DJ_speed =((unsigned int)msg.data[3]<<8) + msg.data[2];//电机转速
                DJ_temperature=msg.data[1];             //驱动电机温度
                DJcontroler_temperature=msg.data[0];    //驱动电机控制器温度
                break;      
            case 0x18FF5A52://烟雾报警器 CAN1 检测点在电池仓内
                YW_Status[0] = msg.data[0]; //烟雾报警
                YW_Status[1] = msg.data[1]; //通讯故障
                YW_Status[2] = msg.data[2]; //赌塞故障
                YW_Status[3] = msg.data[3]; //烟雾报警故障
                YW_Status[5] = msg.data[7]; //LIFE
                break;
            case 0x18FF0258://远程监控终端    
                YZT_Status = msg.data[0]; //故障码
                break;    
            case 0x18FF5B52://BMS发送给整车控制器数据 烟雾报警器 检测点在电池箱体内
                YW1_Status[0] = msg.data[0]; //烟雾报警  00：正常 01：通讯故障 10：堵塞故障 11：烟雾报警 
                YW1_Status[1] = msg.data[1]; //
                YW1_Status[2] = msg.data[2]; //
                YW1_Status[3] = msg.data[3]; //
                YW1_Status[4] = msg.data[4]; //
                YW1_Status[5] = msg.data[5]; //
                YW1_Status[6] = msg.data[6]; //
                YW1_Status[7] = msg.data[7]; //LIFE
                break;    
            case 0x18FF064A://    
                GZ_Status[0] = msg.data[7]; //Bit76 整车故障  Bit54 BMS故障  Bit32 电机控制器故障  Bit10 小充电机故障
                GZ_Status[1] = msg.data[6]; //BMS故障码表
                GZ_Status[2] = msg.data[5]; //电机控制器故障码表
                GZ_Status[3] = msg.data[4]; //小充电机故障码表
                GZ_Status[4] = msg.data[3]; //整车故障码
                break;               
            case 0x0CFF104A:
                DC_Status[3] = msg.data[6];//Bit10充电继电器状态                              
                break;    
            case 0x18FF0257://行车记录仪时间
                Jcan_count=0;
                JLY_time[0] = msg.data[0];//0X02固定值
                JLY_time[1] = msg.data[1];//年20
                JLY_time[2] = msg.data[2];//年15
                JLY_time[3] = msg.data[3];//月
                JLY_time[4] = msg.data[4];//日
                JLY_time[5] = msg.data[5];//时
                JLY_time[6] = msg.data[6];//分
                JLY_time[7] = msg.data[7];//秒
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
    static unsigned int cnt6 = 0;
    static unsigned int lpcnt2 = 0, lpcnt1 = 0, lpcount = 0;
    static unsigned int Fcount = 0, Kcount = 0;
    static unsigned int count6 = 0;
    static unsigned int count7 = 0;
    static unsigned int can1 = 0, can2 = 0;
    //static unsigned int count8 = 0;
    static float mile = 0;
    //报警延时3s标记
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
   
    if (F3s_1 == 1) {
        if (cnt6 >= 16) {//
            cnt6 = 0;
            F3s_1 = 0;
        } else {
            cnt6++;
        }
    } else {
        cnt6 = 0;
    }
    
    if (delay_cnt > 0) delay_cnt--; //延时计数器 
    if (delay_5s > 0)  delay_5s--; //延时计数器  

    if (cnt0 >= 4) {//50ms
        cnt0 = 0;
        BCAN_send_mile();
        BCAN_SendCtl();
        if (M_ON_flag && (wake_up3)) {//若放在main函数里，会导致闪烁频率异常wake_up3置0时，M_ON不会立马置0，因为存在消抖延时
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
                 PCAN_send_time();//时间        
        }else if(can2==1){
                 can2=2;
                 PCAN_send_mile();
               //PCAN_send_yb();//气压 
        }else if(can2==2){
                 can2=0;
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
                if (total_miles >= 99999999) total_miles = 0;
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
        if (Kcan_count >= CAN_TIME)Kcan_count = CAN_TIME;
        else Kcan_count++;   
        if(BAT24V_count>= BAT24_TIME)BAT24V_count= BAT24_TIME;
        else BAT24V_count++;
        if (ECU_TIME   >= CAN_TIME)ECU_TIME   = CAN_TIME;
        else ECU_TIME++;
        if(  QY_count  >= CAN_TIME)QY_count = CAN_TIME;
        else QY_count++;
        //if (Hcan_count >= CAN_TIME)Hcan_count = CAN_TIME;
        //else Hcan_count++;
        //if (Ccan_count >= CAN_TIME)Ccan_count = CAN_TIME;
        //else Ccan_count++;
        //if (Qcan_count >= CAN_TIME)Qcan_count = CAN_TIME;
        //else Qcan_count++;
        //if (Ycan_count >= CAN_TIME)Ycan_count = CAN_TIME;
        //else Ycan_count++;
        
        if (Jcan_count >= 100)Jcan_count = 100; 
        else Jcan_count++;
        if (JYcan_count >= 100)JYcan_count = 100; 
        else JYcan_count++;
        if(Tcan_count >=CAN_TIME)Tcan_count=0;
        else                     Tcan_count++;         
        if(Tcan_count ==5 ){JLY_time[8]=JLY_time[7];R_life[1]=R_life[0];}
        if(Tcan_count ==45){JLY_time[9]=JLY_time[7];R_life[2]=R_life[0];}

        
        if (cnt4 >= 9) {//1s
            cnt4 = 0;
            F1000ms = 1;
            FLASH_1s = !FLASH_1s;
            //PCAN_send_mile();
            //输出5秒，10分钟循环
            //if (DMC_Rpm * 0.5 < 16300) count7 = 0;
            //else count7++;

            if ((count7 > 0) && (count7 < 6)) {
                F5s = 1;
            } else if (count7 < 605) {
                F5s = 0;
            } else count7 = 0;
            //蜂鸣6秒，10分钟循环报警
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

    if (wake_up2) { //ACC开关判断//消抖//M_ON在掉电的一瞬间会使上拉电源无效，而M_ON在断电会保持300ms，从而影响开关量采集
        if (cnt3 > 30) M_ACC = 1;
        else cnt3++;
    } else {
        if (cnt3 < 1) M_ACC = 0;
        else cnt3--;
    }
    
    if (wake_up3) { //ON开关判断//消抖//M_ON在掉电的一瞬间会使上拉电源无效，而M_ON在断电会保持300ms，从而影响开关量采集
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
            //lpcnt2 = 0;
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
            lpcount = 0;
            single_miles = 0;
            save_flag = 1;
            bkey_AV = 1; //长按时取消单按键操作
            lpcount = 100;
        } else lpcount++;
    } else if (lpcount > 0) lpcount--;

    _T1IF = 0;
}

#define C3_K     512
#define FOUT_DR  TRISFbits.TRISF6
#define FOUT     LATFbits.LATF6
//unsigned char vspeed;    //单位km/h

void TIM5_Init(void) {
    FOUT_DR = 0;
    FOUT = 0;
    T5CON = 0; //1：1 分频   16MHz
    TMR5 = 0;
    PR5 = 15999; //1ms中断一次
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

