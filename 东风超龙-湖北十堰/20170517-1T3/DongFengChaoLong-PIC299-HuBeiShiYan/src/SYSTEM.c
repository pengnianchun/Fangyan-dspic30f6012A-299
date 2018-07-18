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

unsigned int Hcan_count = 0; //灭火器
unsigned int Jcan_count = 0; //绝缘检测
unsigned int Ccan_count = 0; //DCDC
unsigned int Qcan_count = 0; //气泵
unsigned int Ycan_count = 0; //油泵
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
unsigned int  PT1000[56][3]={
    {1155,1159,40},//40度
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
//系统初始化函数

void System_Init(void) {
    unsigned char i,j;
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
            LED4  =F_PO7; //左转向报警
            LED8  =F_PO6; //右转向报警   
            BUZZ = !FLASH;//转向蜂鸣
            
        if (F50ms) {
            F50ms = 0;
            LED_Out();
            SW_Input();
            BCAN_SendCtl();
        }

        if (M_ON || wake_up2) break; // 如果是ON唤醒则正常退出

        if (wake_up1 == 0) {
            F_PO6 = 0;
            F_PO7 = 0;
            T_PO15=F_PO7; //左转向灯
            T_PO2 =F_PO6; //右转向灯
            LED4  =F_PO7; //左转向报警
            LED8  =F_PO6; //右转向报警  
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
    
/*
    //调试用
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
    
    Battery_Voltage_Sum[0]=50; //电池单体电压每箱数量
    Battery_Voltage_Sum[1]=45; 
    Battery_Voltage_Sum[2]=40;
    Battery_Voltage_Sum[3]=35;
    Battery_Voltage_Sum[4]=30;
    Battery_Voltage_Sum[5]=25;
    Battery_Voltage_Sum[6]=20;
    
    Battery_Temp_Sum[0]=10;    //电池单体温度每箱数量
    Battery_Temp_Sum[1]=9;
    Battery_Temp_Sum[2]=8;
    Battery_Temp_Sum[3]=7;
    Battery_Temp_Sum[4]=6;
    Battery_Temp_Sum[5]=5;
    Battery_Temp_Sum[6]=4;
    
    DC_JH_Status[0][0]=0x80;//电池均衡状态 模块内  1-48 节
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
    //电压型传感器采集  ADV[]是实际的电压*1000
    //ADV[1] = (unsigned int) (read_ADR(1) / ad * 5000);
    //ADV[2] = (unsigned int) (read_ADR(2) / ad * 5000);
    //ADV[3] = (unsigned int) (read_ADR(3) / ad * 5000);
    //ADV[4] = (unsigned int) (read_ADR(4) / ad * 5000);
    ADV[5] = (unsigned int) (read_ADR(5) / ad * 5000);
    ADV[6] = (unsigned int) (read_ADR(6) / ad * 5000);
    //蓄电池电压    
    ADR[0] = (unsigned int) (550.0 * read_VOL() / ad); //实际电压放大10倍   //(read_VOL() - 1300)*10 / 76 + 180;
    if (ADR[0] >= 225) BAT24V_count = 0;
    //电阻型传感器采集  ADR[]是实际的阻值
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

    unsigned int  QY_TIME=0;  //气压计时变量
    unsigned int  KYJ_TIME=0; //空压机计时变量
    unsigned char QY_OUT_EN=0;//气压外部使能开关
    static unsigned char KYJ_EN=0;
    static unsigned char QY_EN=0;    
void SYSTME_Logic(void) {
    //static unsigned char KYJ_EN=0;
    //static unsigned char QY_EN=0;
 // F_PO1  = (IN16 && M_ON);                    //雨刮快档
 // F_PO2  = (IN14 && M_ON);                    //雨刮慢档
 // F_PO3  = (IN21 && M_ON);                    //喷水电机
    F_PO4  = (IN6 && IN9);                      //左前雾灯
    F_PO5  = (M_ON);                            //投币机电源
    F_PO6  = (FLASH && (IN5 || wake_up1));      //右转向灯
    F_PO7  = (FLASH && (IN1 || wake_up1));      //左转向灯
    F_PO8  = (M_ON);                            //倒车显示电源 
    F_PO9  = (IN7 && !IN8);                     //远关灯      && !IN8
    F_PO10 = (IN6 && IN9 && IN10);              //后雾灯
    F_PO11 =  F_PO9;                            //远光灯
    F_PO12 = (M_ON);                            //行车记录仪电源 
    F_PO13 = (IN8 && IN6 && IN7);              //近光灯 
    F_PO14 = (IN6);                             //位置灯
    F_PO15 =  F_PO13;                           //近光灯
    F_PO16 =  0;                                //励磁电流

//////////////////////////////////////////////////////
//压力   0    0.1    0.2   0.4    0.6    0.8    1   //
//电压  0.5   0.725   1    1.5     2     2.5    3   //
/////////////////////////////////////////////////////
//干燥器排气控制
//ON-ACC档ON&(气压1&&气压2）＞8.1个压时，输出3.5秒    
//or(气压1or气压2）＞8.5个压时，长输出 
//ON-当关掉点火锁，ACC档ON档无效时输出10秒   
        
    if(M_ON){
        if(  QY_count  >= CAN_TIME){//延时处理，上电会闪一下
        //if( (((ADV[6]/10)>253) || ((ADV[5]/10)>253)) && (QY_EN==1) ){ QY_TIME=70;QY_EN=0; }//ON-ACC档ON&(气压1or气压2）＞8.1个压时，输出3.5秒 
        //if(  ((ADV[6]/10)<237) && ((ADV[5]/10)<237)  )              {            QY_EN=1; }//当气压下降到0.75时认为有效   
          if( (((ADV[6]/10)>253) && ((ADV[5]/10)>253)) && (QY_EN==1) ){ QY_TIME=70;QY_EN=0; }//ON-ACC档ON&(气压1 && 气压2）＞8.1个压时，输出3.5秒
          if(  ((ADV[6]/10)<237) && ((ADV[5]/10)<237)  )              {            QY_EN=1; }//当气压下降到0.75时认为有效           
        }else {QY_TIME=0;QY_EN=0;}
    }else QY_TIME=0;
      
         if(QY_TIME>0){ R_PO2=1;QY_TIME--; }
         else if(M_ON && (((ADV[6]/10)>263) || ((ADV[5]/10)>263)) && (QY_count >= CAN_TIME))R_PO2=1;//(气压1or气压2）＞8.5个压时，长输出
         else         { R_PO2=0;QY_TIME=0; }  
         if(M_ON){ QY_OUT_EN=1; }
    
//空压机使能控制 
//ON-ACC档ON&(气压1or气压2）＜6.5个压
//OFF?{（气压1&气压2）＞8.1个压}or(PT1000采集温度＞90℃）

    if(M_ON){
        if(  QY_count  >= CAN_TIME){//延时处理，上电会闪一下
            if( ((ADV[6]/10)<212) || ((ADV[5]/10)<212) )R_PO4=1;//(气压1or气压2）＜6.5个压
            if( (((ADV[6]/10)>253) && ((ADV[5]/10)>253)) ||     //(气压1 &气压2）＞8.1个压
                //(ADR[1]>1308)                                 //(PT1000采集温度＞80℃)
                  (ADR[1]>1347)                                 //(PT1000采集温度＞90℃)             
               )R_PO4=0; 
        }
    }else R_PO4=0;

    R_PO1  = (M_ON);                            //ON档输出电源
    R_PO3  = (M_ON);                            //集中润滑电源                             
    R_PO5  = (M_ON && IN11 && rKL2);            //电喇叭电源
    R_PO6  = (IN4);                             //ST档电源
    R_PO7  = (M_ON && IN11 && rKL4);            //气喇叭电源
    R_PO8  = (M_ON);                            //干燥器电源
    if(Gear==124)R_PO9=1;else R_PO9=0;          //倒车灯 
    R_PO10 = (M_ON);                            //空调ON档电源
    R_PO11 = (mKL15);                           //前门踏步灯    
    R_PO12 = (M_ON);                            //车载远程监控电源
    R_PO13 = (mKH1);                            //中门踏步灯    
    R_PO14 = (M_ON);                            //气压传感器电源
    R_PO16 =  0;                                //励磁电流  
    
//空压机风扇控制   
//ON-ACC档ON&(气压1or气压2）＜6.5个压；
//OFF?{（气压1&气压2）＞8.1个压}or(PT1000采集温度＞90℃）延时30S断电 

    if(M_ON){
       if(  QY_count  >= CAN_TIME){//延时处理，上电会闪一下
         if(( ((ADV[6]/10)<212) || ((ADV[5]/10)<212) ) && R_PO4 ){ R_PO15=1; KYJ_EN=1;}
         if( ( (((ADV[6]/10)>253) && ((ADV[5]/10)>253)) || 
             //(ADR[1]>1308) )  && //PT1000采集温度＞80℃
               (ADR[1]>1347) )  && //PT1000采集温度＞90℃           
                KYJ_EN  
           ){ KYJ_TIME=600;KYJ_EN=0; }  
       }else {KYJ_TIME=0;  KYJ_EN=0;}
    }else   KYJ_TIME=0;
    
    if(KYJ_EN==0){ 
       if(KYJ_TIME>0){          KYJ_TIME--; }
       else          { R_PO15=0;KYJ_TIME=0; }  
    }

    M_PO1  = (mKL2);                            //司机灯电源
    M_PO2  = (F_PO6);                           //右后转向灯
    M_PO3  = (M_ON);                            //车载监控ON档电源
    M_PO4  = (rKL6);                            //制动灯
    M_PO5  = (IN20 && (Vspeed<10));             //前门开门电磁阀
    M_PO6  = (M_ON);                            //门泵电源
    M_PO7  = (IN28);                            //前门关门电磁阀
    M_PO8  = (M_ON);                            //下车呼叫器电源
    M_PO9  = (IN27 && (Vspeed<10));             //中门开门电磁阀
    M_PO10 = (mKL6);                            //电视机电源
    M_PO11 = (IN26);                            //中门关门电磁阀
    M_PO12 = (M_ON);                            //换气扇电源
    M_PO13 = (F_PO14);                          //小灯电源
    M_PO14 = (mKL8);                            //司机电扇电源
    M_PO15 = (F_PO7);                           //左后转向灯
    M_PO16 =  0;                                //励磁电流


}

void LED_Logic(void) {
    LED3  = 0; //空挡指示    
    LED5  = 0; //前进挡指示    
    LED23 = 0; //缓速器
    
    LED10 = 1; //总电源指示     
    
    LED15 = F_PO14; //小灯   
    
    LED4  = F_PO7;  //左转向灯
    LED8  = F_PO6;  //右转向灯   
    
    LED22 = F_PO13; //近光灯    
    LED17 = F_PO9;  //远光灯     
    
    LED19 = F_PO4;  //前雾灯
    LED20 = F_PO10; //后雾灯    
    
    LED1  = mKL15;  //前门开指示
    LED2  = mKH1;   //中门开指示   

    LED18 = rKL8;   //手刹
    LED24 = rKL6;   //刹车指示      
    
    LED21 = R_PO9;  //倒车灯
    if(BAT24V_count >= BAT24_TIME)LED16=1;else LED16=0;//蓄电池电压低     
    
//////////////////////////////////////////////////////
//压力   0    0.1    0.2   0.4    0.6    0.8    1   //
//电压  0.5   0.725   1    1.5     2     2.5    3   //
/////////////////////////////////////////////////////
    if( //IN11              ||
          M_ON              &&
          ((ADV[6]/10)<200)         
      )LED9=1; else LED9=0; //气压1低于0.6MPa 报警
    
    if( //IN12              ||
          M_ON              &&   
        ((ADV[5]/10)<200)    
      )LED11=1;else LED11=0;//气压2低于0.6MPa 报警   
    
    if((DJ_Status[3]>0)||(DJ_Status[4]>0))LED13 = 1;else LED13 = 0; //电机故障   
    
    if(DC_Status[2]&0x01)LED6=1;else LED6=0; //充电状态
    if(DC_Status[2]&0x02)LED7=1;else LED7=0; //充电枪插入    
    
    //if(DC_Status[1]&0x80)LED12=1;else LED12=0; //SOC低报警 对应2.9版本
    if( (DC_Status[0]==13 )  || // 1 级
        (DC_Status[0]==63 )  || // 2 级
        (DC_Status[0]==113)     // 3 级       
      )LED12=1;else LED12=0; //SOC低报警  对应3.0版本
    
    //if((DC_Status[0]>0)||(DC_Status[1]>0))LED14=1;else LED14=0; //动力电池系统故障 对应2.9版本
    if((DC_Status[0]>0))LED14=1;else LED14=0; //动力电池系统故障  对应3.0版本
    //LED14 = 0; //动力电池系统故障    
    
//蜂鸣器 为0时响，为1时不响   
        if (M_ON && (  
               !fKL4 ||   //左前摩擦片报警
               !fKL5 ||   //右前摩擦片报警
                LED9 ||   //气压1
                LED11||   //气压2
                LED4 ||   //左转向灯报警 
                LED8 ||   //右转向灯报警
               (Vspeed > 690)  //超速报警
            ))BUZZ = !FLASH;//1;//!FLASH_1s;
    else      BUZZ = 1;
    
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

    for(i=0;i<7;i++){    
        sbcd=(unsigned char)(timer.byte[i]>>4);
        sbcd=sbcd*10;
        sbcd+=(unsigned char)(timer.byte[i]&0x0f);      
        bcd[i]=sbcd;     
    }
    msg.data[0] = bcd[0]<<2;//秒-精度是0.25
    msg.data[1] = bcd[1];   //分
    msg.data[2] = bcd[2];   //时
    msg.data[3] = bcd[5];   //月
    msg.data[4] = bcd[4]<<2;//日-精度是0.25
    msg.data[5] = bcd[6];   //年
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

    msg.data[0] = 0;//温度
    msg.data[1] = 0;//油量
    msg.data[2] = 0;//油压
    
    temp1=ADV[6]/10;//气压1   
         if(temp1<=50 )temp2=0;
    else if(temp1>=300)temp2=250;
    else               temp2=(temp1-50);
    msg.data[3] = temp2;

    temp1=ADV[5]/10;//气压2   
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

/*******************分包处理*****************/



unsigned char DMC_Status; //电机控制器基本状态
unsigned char DMC_Level; //电机控制器故障级别
unsigned char DMC_Life; //电机生命
unsigned int DMC_Torque = 32000; //电机转矩
unsigned int DMC_Rpm = 32000; //电机转速
unsigned char DMC_Speed; //车速
unsigned char DMC_Gear; //档位

unsigned int DMC_Voltage; //电机控制器母线电压
unsigned int DMC_Current = 2000; //电机控制器母线电流
unsigned char DMC_Controller_temp = 40; //电机控制器温度
unsigned char DMC_Moto_temp = 40; //电机温度
unsigned char DMC_Protect_code; //电机控制器故障代码
unsigned char DMC_Verison; //电机控制器版本号

/*


unsigned char DMC_Accelerator_percent; //油门踏板开度
unsigned char DMC_Brake_percent; //制动踏板开度
unsigned char DMC_Charge; //充放电状态
unsigned char DMC_GB_Gear; //国标档位

unsigned int DMQ_Rpm; //气泵控制器电机转速
unsigned int DMQ_Voltage; //气泵控制器母线电压
unsigned char DMQ_Current; //气泵控制器电机母线电流
unsigned char DMQ_temp = 40; //气泵温度
unsigned char DMQ_Controller_temp = 40; //气泵控制器温度
unsigned char DMQ_Life; //气泵控制器生命
unsigned char DMQ_Status; //气泵控制器基本状态

unsigned char DCDC_Status; //DCDC基本状态
unsigned char DCDC_Temp = 40; //DCDC模块温度
unsigned int DCDC_Voltage; //DCDC输出电压
unsigned int DCDC_Current = 32000; //DCDC输出电流
unsigned char DCDC_Code; //DCDC故障代码
unsigned char DCDC_Verison; //DCDC版本号

unsigned int DMY_Rpm; //油泵控制器电机转速
unsigned int DMY_Voltage; //油泵控制器母线电压
unsigned char DMY_Current; //油泵控制器电机母线电流
unsigned char DMY_Controller_temp = 40; //油泵控制器温度
unsigned char DMY_Life; //油泵控制器生命
unsigned char DMY_Status; //油泵控制器基本状态

unsigned char Air_Status_Flag1; //空调状态1
unsigned char Air_Status_Flag2; //空调状态2
unsigned char Air_Status_Flag3; //空调状态3
unsigned char Air_Indoor_t = 60; //室内温度
unsigned char Air_Outdoor_t = 60; //室外温度
unsigned char Air_Set_t = 60; //设定

unsigned char BMS_Type; //BMS参数类型
unsigned char Battery_Case_Total_Number; //电池箱体个数
unsigned char BMS_Unit_Number = 1; //电池管理系统从控单元个数
unsigned int Battery_Cell_Total_Number; //电池总串数
unsigned int BMS_Nubmer; //电池管理系统编号

unsigned char Battery_Case_number; //电池箱号n
unsigned char Battery_Cell_number; //电池箱n内电池串数
unsigned char Battery_Cell_Temp_Number; //电池箱内电池温度探头个数

*/
 
unsigned int BMS_V; //电池总电压
unsigned int BMS_A = 32000; //电池总电流
unsigned char BMS_SOC; //电池SOC
unsigned char BMS_Life; //BMS LIFE
unsigned char BMS_Status_Flag1; //电池状态1
unsigned char BMS_Status_Flag2; //电池状态2

unsigned int Battery_Single_H; //电池单体高电压
unsigned int Battery_Single_L; //电池单体低电压
unsigned char Battery_Temp_H = 40; //电池单体最高温度
unsigned char Battery_Temp_L = 40; //电池单体最低温度
unsigned char BMS_Status_Flag3 = 0x80; //电池状态3
unsigned char BMS_Status_Flag4; //继电器状态

/*


unsigned char Battery_Single_H_Positon_Case; //电池单体高电压箱号
unsigned char Battery_Single_H_Positon_Cell; //电池单体高电压位置
unsigned char Battery_Single_L_Positon_Case; //电池单体低电压箱号
unsigned char Battery_Single_L_Positon_Cell; //电池单体低电压位置
unsigned char Battery_Temp_H_Positon_Case; //电池单体高温度箱号
unsigned char Battery_Temp_H_Positon_Cell; //电池单体高温度位置
unsigned char Battery_Temp_L_Positon_Case; //电池单体低温度箱号
unsigned char Battery_Temp_L_Positon_Cell; //电池单体低温度位置

unsigned char BMU_Comm_Status1; //1-8   BMU通讯状态
unsigned char BMU_Comm_Status2; //9-16  BMU通讯状态
unsigned char BMU_Comm_Status3; //17-24 BMU通讯状态
unsigned char BMU_Comm_Status4; //25-32 BMU通讯状态

unsigned char BMU_Bala_Status1; //1-8   BMU均衡状态
unsigned char BMU_Bala_Status2; //9-16  BMU均衡状态
unsigned char BMU_Bala_Status3; //17-24 BMU均衡状态
unsigned char BMU_Bala_Status4; //25-32 BMU均衡状态

unsigned char DC1positive_Temp = 40; //充电插头DC1+温度
unsigned char DC1negative_Temp = 40; //充电插头DC1-温度
unsigned char DC2positive_Temp = 40; //充电插头DC2+温度
unsigned char DC2negative_Temp = 40; //充电插头DC2-温度
unsigned int Ohm_Positive; //总正绝缘阻值 
unsigned int Ohm_Negative; //总正绝缘阻值 

unsigned int Energe_Rest; //剩余能量
unsigned char BMS_Status_Flag5;
unsigned char BMS_Status_Flag6;

unsigned char Battery_Single_H_Positon_Total; //最高单体电压位置（总数）
unsigned char Battery_Single_L_Positon_Total; //最低单体电压位置（总数）
unsigned char Battery_Temp_H_Positon_Total; //最高单体温度位置（总数）
unsigned char Battery_Temp_L_Positon_Total; //最低单体温度位置（总数）
unsigned char Battery_Single_H_Pack; //最高单体电压包号
unsigned char Battery_Single_L_Pack; //最低单体电压包号
unsigned char Battery_Temp_H_Pack; //最高单体温度包号
unsigned char Battery_Temp_L_Pack; //最低单体温度包号


*/

unsigned char BMU_Number = 24; //BMU号
unsigned char Battery_Pack; //电池报文包数
//unsigned int Battery_Voltage[12]; //电池单体电压
unsigned int Battery_Temp[12]; //电池单体温度
unsigned char DCDC_Status; //DCDC基本状态

/**************************************************/

unsigned int CAN_BAT_COUNT=0;
unsigned int CAN_DRIVE_COUNT=0;

//整车控制器变量 
unsigned int  DJcontroler_voltage=10000;  //电机控制器输入电压
unsigned int  DJcontroler_current=10000;  //电机控制器入电流高
unsigned int  DJ_speed=0;
unsigned char DJ_temperature=40;          //驱动电机温度
unsigned char DJcontroler_temperature=40; //驱动电机控制器温度

unsigned char DJ_temperature1=40;         //电机温度
unsigned char DJcontroler_temperature1=40;//电机控制器温度
unsigned char VCU_Status[10];     //VCU状态
unsigned char Gear=125;           //档位
unsigned int  XHLC=0;             //续航里程
unsigned char DJ_version;         //MCU 软件版本信息
unsigned char DJ_Status[10];      //电机控制系统状态
unsigned char DJ_fault;           //MCU 系统故障代码
unsigned int  DJ_Power;           //电机实时输出功

unsigned long version=0;          //程序版本号高 3字节
unsigned int  DJtorque=0;     //电机输出目标转矩
unsigned char system_state=0;     //系统工作状态
unsigned int  system_fault=0;     //系统故障码
unsigned char fault_grade=0;      //故障等级
unsigned char controler_LIFE=0;   //整车控制器Life
  
unsigned char PDX_state[2];        
unsigned char DCDC1_temp=40;
unsigned char DCDC1_fault=0;
unsigned char DCDC2_temp=40;
unsigned char DCDC2_fault=0;
unsigned char DCDC3_temp=40;
unsigned char DCDC3_fault=0;

unsigned char KEY_state[4];  //开关量状态  //档位
unsigned int  traction_st[2];   //加速踏板百分比
unsigned char brake_st[2];      //制动踏板百分比

unsigned char JY_life;
unsigned char JY_Status;
unsigned int  anode_R;     //正端对地绝缘电阻
unsigned int  negative_R;  //负端对地绝缘电阻
unsigned char eror_R;      //绝缘故障等级
unsigned char R_state[3];  //

unsigned char KZQversion[7];
unsigned char DJversion[7];  //程序版本号高 3字节

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

//电池电池管理相关报文 
unsigned int  DC_voltage=0;    //电池电压 
unsigned int  DC_current=5000; //电池电流 
unsigned char DC_SOC=0;
unsigned char DC_Status[5];

unsigned int  CD_current=500; //当前最大允许充电电流
unsigned int  FD_current=0;    //当前最大允许放电电流
unsigned char DC_fault=0;   //系统故障等级
unsigned int  Vaverage=0;   //
unsigned char Tmax=40;      //最大单体电池温度
unsigned char Tmin=40;

unsigned int  DCanode_R;    //正端对地绝缘电阻
unsigned int  DCnegative_R; //负端对地绝缘电阻
unsigned int  Vmax;         //最大单体电压
unsigned int  Vmin;         //最小单体电压
 
unsigned char BMU_NUM=7;   //定义模块数量
unsigned int  Battery_Voltage[10][50]; //电池单体电压
unsigned int  Battery_Voltage_Sum[10]={50,50,50,50,50,50,50,50,50,50}; //电池单体电压每箱数量
unsigned int  Battery_Temp_Sum[10]={10,10,10,10,10,10,10,10,10,10};    //电池单体温度每箱数量
unsigned char DC_Temp[10][10];
unsigned char DC_JH_Status[10][4];//电池均衡状态 模块内  1-48 节
unsigned char DC_JY[10];//绝缘电阻
unsigned char DC_DT_sum;//单体电池个数( 串数) 
unsigned char DC_TEMP_sum;//单体温度个数
unsigned char Vmax_num[2];//最高单体电压电池位置   Vmax_num[1]//最高单体电压电池位置：单体电池编号
unsigned char Vmin_num[2];//最低单体电压电池位置   Vmin_num[1]//最低单体电压电池位置：单体电池编号     
unsigned char Tmax_num[2];//最高单体温度位置       Tmax_num[1]//最高单体温度位置：单体温度编号
unsigned char Tmin_num[2];//最低单体温度位置       Tmin_num[1]//最低单体温度位置：单体温度编号

unsigned char Vmax_box;//最高单体电压电池位置：电池箱编号
unsigned char Vmin_box;//最低单体电压电池位置：电池箱编号
unsigned char Tmax_box;//最高单体温度位置：温度箱箱号       
unsigned char Tmin_box;//最低单体温度位置：温度箱箱号  

 DC_DATA  voltage_bat[10];    //单体电池电压
//BMS 只发送电压偏差最大的10个单体，正向5个，负向5个
 
 DC_TEMP  temp_bat[10];//单体电池温度
//BMS 只发送温度偏差最大的10个单体。
 
//油泵控制器
unsigned int  YB_voltage;
unsigned int  YB_current;  
unsigned char YB_temp;   //油泵散热温度
unsigned char YB_fault;  //油泵故障码
//转向助力泵（DC/AC） 空压机 气泵（DC/AC）电源
unsigned int  DCAC_speed[2];//电机估计转速
unsigned int  DCAC_current[2];//输出相电流
unsigned char DCAC_temp[2];//控制器温度
unsigned char DCAC_life[2];//控制器生命信号
unsigned char DCAC_Status[2];
unsigned char DCAC_fault[2];

unsigned int  DCDC_voltage;
unsigned int  DCDC_current;
unsigned char DCDC_fault;
//气泵控制器
unsigned int  QB_voltage_IN; 
unsigned int  QB_voltage_OUT;
unsigned int  QB_current;    
unsigned char QB_temp;        
unsigned char QB_fault;      
//灭火器
unsigned char MHQ_Number;
unsigned char MHQ_Alarm;
unsigned char MHQ_life;
unsigned char MHQ_fault;
         

void __attribute__((__interrupt__, auto_psv)) _C2Interrupt(void) {
    unsigned char i = 0;
    unsigned char j = 0;
    CAN_MESSAGE msg;
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
            case 0x18F101D0:
                Vcan_count = 0;
                VCU_Status[0]=msg.data[0];//
                Vspeed=msg.data[2]*10;//
                pSpeed=msg.data[2];//
                Gear=msg.data[3];//档位状态
                VCU_Status[1]=msg.data[4];//
                system_fault=msg.data[5];//VCU系统故障码
                controler_LIFE=msg.data[7];//
                break;
            case 0x18F103D0:
                Vcan_count = 0;
                version=msg.data[0];//VCU 版本信息
                XHLC=(unsigned char) msg.data[1]+((unsigned int) msg.data[2] << 8);//续航里程
                traction_st[0]=msg.data[3];//油门踏板状态
                brake_st[0]=msg.data[4];//制动踏板状态
                VCU_Status[2]=msg.data[5];//整车模式信息
                VCU_Status[3]=msg.data[6];//整车部分开关量信息
                VCU_Status[4]=msg.data[7];//电附件使能
                break;
            case 0x18F501F0:               
                Vcan_count = 0;
                DJ_temperature=msg.data[0];//
                DJcontroler_temperature=msg.data[1];//
                DJcontroler_voltage=(unsigned char) msg.data[2]+((unsigned int) msg.data[3] << 8);//驱动变频器母线电压
                DJ_version=msg.data[4];//MCU 软件版本信息
                DJ_Status[0]=msg.data[5];//电机控制系统状态
                DJ_Status[1]=msg.data[6];//驱动系统典型故障
                DJ_fault=msg.data[7];//MCU 系统故障代码
                break;         
            case 0x0CF11F05:  
                Vcan_count = 0;
                traction_st[1]=(unsigned char) msg.data[0]+((unsigned int) msg.data[1] << 8);//油门给定
                DJtorque=(unsigned char) msg.data[2]+((unsigned int) msg.data[3] << 8);//电机输出转矩
                DJ_speed=(unsigned char) msg.data[4]+((unsigned int) msg.data[5] << 8);//电机转速
                DJ_Status[2]=msg.data[6];//当前电机的实际运行状态
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
                DMC_Voltage=(unsigned char) msg.data[0]+((unsigned int) msg.data[1] << 8);//母线电压
                DMC_Current=(unsigned char) msg.data[2]+((unsigned int) msg.data[3] << 8);//电机相电流
                DJ_Power=(unsigned char) msg.data[6]+((unsigned int) msg.data[7] << 8);//电机实时输出功
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
                DC_JH_Status[msg.data[0]-1][0] = msg.data[3];//电池均衡状态 模块内  1-12 节
                DC_JH_Status[msg.data[0]-1][1] = msg.data[4];//电池均衡状态 模块内 13-24 节
                DC_JH_Status[msg.data[0]-1][2] = msg.data[5];//电池均衡状态 模块内 25-36 节    
                DC_JH_Status[msg.data[0]-1][3] = msg.data[6];//电池均衡状态 模块内 37-48 节
                Battery_Temp_Sum[msg.data[0]-1]= msg.data[7]; 
                //DC_JY[0]        = msg.data[7];//绝缘电阻
                //DC_JY[msg.data[0]] = msg.data[7];//绝缘电阻      
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
                DC_Status[3] = msg.data[0];//继电器状态 
                DC_current = (unsigned char) msg.data[1]+((unsigned int) msg.data[2] << 8);//总电流
                DC_voltage = (unsigned char) msg.data[3]+((unsigned int) msg.data[4] << 8);//总电压                
                DC_SOC = msg.data[5];
                DC_Status[0] = msg.data[6];//报警字节1
                DC_Status[1] = msg.data[7];//报警字节2          
                break;                
             case 0x1CFF1912: 
                Bcan_count = 0;  
                CD_current = (unsigned char) msg.data[0]+((unsigned int) msg.data[1] << 8);//允许充电电流
                FD_current = (unsigned char) msg.data[2]+((unsigned int) msg.data[3] << 8);//允许放电电流
                Tmax = msg.data[4];
                Tmin = msg.data[5];   
                DC_Status[2] = msg.data[6]; 
                DC_Status[4] = msg.data[7];   
                break;                  
             case 0x1CFF1913: 
                Bcan_count = 0;  
                DC_DT_sum = msg.data[2];//单体电池个数( 串数) 
                DC_TEMP_sum = msg.data[3];//单体温度个数
                Vmax_num[0] = msg.data[4];//最高单体电压电池位置
                Vmin_num[0] = msg.data[5];//最低单体电压电池位置          
                Tmax_num[0] = msg.data[6];//最高单体温度位置
                Tmin_num[0] = msg.data[7];//最低单体温度位置  
                break; 
             case 0x1CFF1914:  
                Bcan_count = 0; 
                Vmax_num[1] = msg.data[0];//最高单体电压电池位置：单体电池编号
                Vmax_box    = msg.data[1];//最高单体电压电池位置：电池箱编号
                Vmin_num[1] = msg.data[2];//最低单体电压电池位置：单体电池编号
                Vmin_box    = msg.data[3];//最低单体电压电池位置：电池箱编号
                Tmax_num[1] = msg.data[4];//最高单体温度位置：    单体温度编号
                Tmax_box    = msg.data[5];//最高单体温度位置：    温度箱箱号       
                Tmin_num[1] = msg.data[6];//最低单体温度位置：    单体温度编号
                Tmin_box    = msg.data[7];//最低单体温度位置：    温度箱箱号              
                break; 
             case 0x1CFF1915: 
                Bcan_count = 0; 
                Vmax = (unsigned char) msg.data[0]+((unsigned int) msg.data[1] << 8);//最高单体电压
                Vmin = (unsigned char) msg.data[2]+((unsigned int) msg.data[3] << 8);//最低单体电压             
                break; 
             case 0x18FEA7A8: //转向助力泵（DC/AC）
                Dcan_count = 0; 
                DCAC_speed[0]   = (unsigned char) msg.data[0]+((unsigned int) msg.data[1] << 8);//电机估计转速
                DCAC_current[0] = msg.data[2];//输出相电流
                DCAC_temp[0]    = msg.data[3];//控制器温度
                DCAC_life[0]    = msg.data[4];//控制器生命信号
                DCAC_Status[0]  = msg.data[5];//工作状态
                DCAC_fault[0]   = msg.data[6];//故障代码
                break;              
             case 0x18019888: //油泵控制器
                Ycan_count = 0; 
                YB_voltage = (unsigned char) msg.data[2]+((unsigned int) msg.data[3] << 8); 
                YB_current = (unsigned char) msg.data[4]+((unsigned int) msg.data[5] << 8);      
                YB_temp    = msg.data[6];//散热器温度
                YB_fault   = msg.data[7];//故障代码
                break;              
             case 0x18FEA5A6: //空压机 气泵（DC/AC）电源
                Qcan_count = 0; 
                DCAC_speed[1]   = (unsigned char) msg.data[0]+((unsigned int) msg.data[1] << 8);//电机估计转速
                DCAC_current[1] = msg.data[2];//输出相电流
                DCAC_temp[1]    = msg.data[3];//控制器温度
                DCAC_life[1]    = msg.data[4];//控制器生命信号
                DCAC_Status[1]  = msg.data[5];//工作状态
                DCAC_fault[1]   = msg.data[6];//故障代码
                break;                  
             case 0x1805A89C: //气泵控制器
                Qcan_count = 0;
                QB_voltage_IN  = (unsigned char) msg.data[0]+((unsigned int) msg.data[1] << 8);//
                QB_voltage_OUT = (unsigned char) msg.data[2]+((unsigned int) msg.data[3] << 8);//
                QB_current     = (unsigned char) msg.data[4]+((unsigned int) msg.data[5] << 8);//
                QB_temp        = msg.data[6];//散热器温度
                QB_fault       = msg.data[7];//故障代码 
                break;  
             case 0x18FF12F7: //低压电源（DC/DC）
                Ccan_count = 0;
                DCDC_voltage  =  (unsigned char) msg.data[0]+((unsigned int) msg.data[1] << 8);//
                DCDC_current  =  (unsigned char) msg.data[2]+((unsigned int) msg.data[3] << 8);//      
                DCDC_Status   =  msg.data[4];//DC/DC 工作状态
                DCDC_fault    =  msg.data[5];//DC/DC 故障代码
                break;     
             case 0x1819A1A4: //绝缘检测仪
                Jcan_count = 0;
                anode_R    = (unsigned char) msg.data[1]+((unsigned int) msg.data[0] << 8);//正对地绝缘电阻
                negative_R = (unsigned char) msg.data[3]+((unsigned int) msg.data[2] << 8);//负对地绝缘电阻
                eror_R     =  msg.data[4];//故障等级
                JY_life    =  msg.data[5];//life
                JY_Status  =  msg.data[6];//整车漏电报警
                break;   
             case 0x18FF301D: //电池箱灭火系统
                Hcan_count = 0;
                MHQ_Number =  msg.data[0];//电池箱号
                MHQ_Alarm  =  msg.data[1];//系统预警级别
                MHQ_life   =  msg.data[6];     
                MHQ_fault  =  msg.data[7];//故障等级 8.8~8.7  故障码 8.6~8.1
                break;      
            default:
                
                if((msg.id>=0x1CFF1711) && (msg.id<=0x1CFF1721)){//单体电池电压
                    Bcan_count = 0;
                    j=((unsigned char)((msg.id & 0x000000FF))-0x11); 
                    if(j<=2){
                    Battery_Voltage_Sum[msg.data[0]-1]=msg.data[7];
                    }
                        for(i=0;i<3;i++){  
                            Battery_Voltage[msg.data[0]-1][j*3+i] = ((unsigned char) msg.data[i*2+1]+((unsigned int) msg.data[i*2+2] << 8)); 
                        }
                } 
                
                if((msg.id>=0x1CFF5011) && (msg.id<=0x1CFF5015)){//单体电池电压  
                    Bcan_count = 0;
                    j=((unsigned char)((msg.id & 0x000000FF))-0x11); 
                       
                        for(i=0;i<2;i++){
                            DC_Temp[msg.data[0]-1][j*2+i] = msg.data[i+1];
                        }
                    
                    if(j<=2){
                        Battery_Temp_Sum[msg.data[0]-1]=msg.data[7]; 
                        
                        for(i=0;i<4;i++){
                            DC_JH_Status[msg.data[0]-1][i] = msg.data[i+3];//电池均衡状态 模块内  1-48 节                         
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
            F7s=1;
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
        if (M_ON_flag && (wake_up3 || wake_up2)) {//若放在main函数里，会导致闪烁频率异常wake_up3置0时，M_ON不会立马置0，因为存在消抖延时
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
                 PCAN_send_time();//时间        
        }else if(can2==1){
                 can2=2;
                 PCAN_send_yb();//气压 
        }else if(can2==2){
                 can2=3;
                 PCAN_send_speed();//车速
        }else if(can2==3){
                 can2=0;
                 PCAN_send_mile();//里程  
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
            //输出5秒，10分钟循环
            if (DMC_Rpm * 0.5 < 16300) count7 = 0;
            else count7++;

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

    if (wake_up3) { //ON开关判断//消抖//M_ON在掉电的一瞬间会使上拉电源无效，而M_ON在断电会保持300ms，从而影响开关量采集
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

