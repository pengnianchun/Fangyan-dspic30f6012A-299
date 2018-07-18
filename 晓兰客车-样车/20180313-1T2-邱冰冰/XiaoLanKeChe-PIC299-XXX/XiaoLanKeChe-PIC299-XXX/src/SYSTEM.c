#include "SYSTEM.h"
//#include "LOGO.h"
unsigned int delay_cnt;
DATA_BIT gKEY[5];
DATA_BIT gCTL[8]; //仪表输出控制信息

unsigned int single_miles = 0;
unsigned long total_miles = 0;

unsigned char Fversion;
unsigned char Mversion;
unsigned char Rversion;

unsigned int Fcan_count = 0; //前部模块CAN
unsigned int Rcan_count = 0; //顶部模块CAN
unsigned int Mcan_count = 0; //中部模块CAN
unsigned int Ecan_count = 0; //发动机ECU模块CAN
unsigned int Vcan_count = 0; //整车控制器VCU模块CAN
unsigned int Bcan_count = 0; //电池管理器BMS模块CAN
unsigned int Dcan_count = 0; //转向助力DC/AC模块CAN
unsigned int Acan_count = 0; //空调AC模块CAN

unsigned int BAT24V_count = 0; //蓄电池低压报警计时

unsigned int M_PO11_count = 1000; //输出10秒计时

DBCM_KEY fKEY; //前模块功率开关状态
DBCM_KEY mKEY; //中（顶）模块功率开关状态
DBCM_KEY rKEY; //后模块功率开关状态

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


//系统初始化函数

void System_Init(void) {
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
            //M_PO2 = FLASH;
            //M_PO15 = FLASH;
            //R_PO5 = FLASH;
            //R_PO7 = FLASH;
            LED4 = FLASH; //左转向灯
            LED8 = FLASH; //右转向灯 
            BUZZ = !FLASH;
            M_PO14 = 1; //门泵电源
        } 

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
            //M_PO2 = 0;
            //M_PO15 = 0;
            //R_PO5 = 0;
            //R_PO7 = 0;
            LED4 = 0; //左转向灯
            LED8 = 0; //右转向灯
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
    CAN_0x10F813A4.MotoSpeed = 20000;
}

void Count_ADR(void) {
    float ad = 4096;
    //电压型传感器采集  ADV[]是实际的电压*1000
    //ADV[1] = (unsigned int) (read_ADR(1) / ad * 5000);
    //ADV[2] = (unsigned int) (read_ADR(2) / ad * 5000);
    //ADV[3] = (unsigned int) (read_ADR(3) / ad * 5000);
    //ADV[4] = (unsigned int) (read_ADR(4) / ad * 5000);
    //ADV[5] = (unsigned int) (read_ADR(5) / ad * 5000);
    //ADV[6] = (unsigned int) (read_ADR(6) / ad * 5000);
    //蓄电池电压    
    ADR[0] = (unsigned int) (550.0 * read_VOL() / ad); //实际电压放大10倍   //(read_VOL() - 1300)*10 / 76 + 180;
    if (ADR[0] >= 220) BAT24V_count = 0;
    //电阻型传感器采集  ADR[]是实际的阻值
    ADR[1] = (unsigned int) (100.0 * read_ADR(1) / (ad - read_ADR(1))); //((read_ADR(1) / ad * 100) / (1 - read_ADR(1) / ad));
    ADR[2] = (unsigned int) (100.0 * read_ADR(2) / (ad - read_ADR(2)));
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
    LED1 = IN4; //前门开指示

    LED2 = IN3; //中门开指示
    //LED3 = (DMC_Gear==0 || DMC_Gear==3); //空挡指示

    //左转向
    if (IN1 || wake_up1)
        LED4 = FLASH;
    else LED4 = 0;

    //LED5 = (DMC_Gear==1); //前进挡指示
    
    LED6 = (CAN_0x18F81F27.ChargeStatus == 2); //充电状态

    LED7 = ((BMS_Charge_Status >> 2)&0x01); //充电枪插入
    //右转向灯
    if (IN5 || wake_up1)
        LED8 = FLASH;
    else LED8 = 0;

    LED9 = fKL9; //气压1低信号

    LED10 = 1; //总电源指示   

    LED11 = fKL11; //气压2低信号

    LED12 = (CAN_0x10F8219E.BMSWarningFlag == 4 
            || CAN_0x10F8219E.BMSWarningFlag == 7
            || CAN_0x10F8219E.BMSWarningFlag == 8
            ); //SOC低报警

    LED13 = (DMC_Status == 5); //电机故障

    LED14 = (CAN_0x10F8159E.BMSStatus == 5); //动力电池系统故障

    LED15 = IN33; //小灯

    LED16 = (BAT24V_count == BAT24_TIME); //蓄电池电压低

    LED17 = (IN34 && !IN35); //远光灯

    LED18 = (fKL2); //手刹

    LED19 = (IN9 && IN33); //前雾灯

    LED20 = (IN9 && IN10 && IN33); //后雾灯

    //LED21 = (DMC_Gear==2 /*&& M_ON*/);//倒车灯

    LED22 = (IN35 && IN33 && !IN34); //近光灯

    //LED23 = (IN14 && IN31 && M_ON);//缓速器

    LED24 = (fKL6); //刹车指示


    //蜂鸣器 为0时响，为1时不响   
    if (pSpeed > 69) 
        BUZZ = 0;
    else if (mKL4 || mKL6 || fKL9 ||fKL11 //IN30
            || LED13        
            || mKL2 || fKL15 //门铃
            || CAN_0x18F81F27.VCUFaultCode
            )
        BUZZ = !FLASH_1s;
    else if (IN1 || IN5 || wake_up1)
        BUZZ = !FLASH;
    else BUZZ = 1;
    
    //背光 小灯开关闭合 
    if (LED15) {
        OC1RS = e_backlight;
    } else {
        OC1RS = 0;
    }
    //

    /*if (M_ON) {
        PO1 = 0;
        PO2 = 0;
    } else {
        PO1 = 1;
        PO2 = 1;
    }
    PO1 = (M_ON || wake_up1 || wake_up2);

    PO2 = (DMC_Gear == 2);*/

    //启动 
    /*
    if (((tcu_start_allow == 1)&&(hcu_starter_forbid != 1)) || (ENG_start_req == 21415))
        PO1 = 0;
    else if (hcu_starter_forbid == 1) PO1 = 1;
    else PO1 = 1;
     */
    //if (Brake_Pedal == 0) PO2 = 1;
    //else if (Brake_Pedal == 1) PO2 = 0;
    /**************分包结构*******************/
    /*
    mil_lamp_request = (CAN_18FECAEF.bData[0] >> 2)&0x03;
    fail_mode = (CAN_18FECAEF.bData[0] >> 4)&0x03;
    mil_buzz_request = (CAN_18FECAEF.bData[0] >> 6)&0x03;
    Lamp_status_YELLOW = (CAN_18FECA03.bData[0] >> 2)&0x03;
    Lamp_status_RED = (CAN_18FECA03.bData[0] >> 4)&0x03;
     */
    //DM_ECU(1);   
    /* Maintain_warn = (CAN_18FECA00.bData[0] >> 2)&0x03; //维护报警warn
     Stop_warn = (CAN_18FECA00.bData[0] >> 4)&0x03; //停机报警stop
     Engine_warn = (CAN_18FECA00.bData[0] >> 6)&0x03; //发动机故障    
     */
}

void SYSTME_Logic(void) {
    // F_PO1 = (IN16 && M_ON); //雨刮快档
    // F_PO2 = (IN14 && M_ON); //雨刮慢档
    // F_PO3 = (IN21 && M_ON); //喷水电机
    F_PO4 = (LED15 && IN9);                     //左前雾灯
    F_PO5 = (IN28 && wake_up2);                 //电控排污阀
    F_PO6 = (FLASH && (IN5 || wake_up1));       //右转向灯
    F_PO7 = (FLASH && (IN1 || wake_up1));       //左转向灯
    F_PO8 = ((CAN_0x10F813A4.MotoSpeed > 20300) && F5s); //冷凝器 
    F_PO9 = LED17;                              //左远关灯
    F_PO10 = (LED15 && IN9);                    //右前雾灯
    F_PO11 = LED17;                             //右远光灯
    F_PO12 = (Battery_Temp_H >= 75);            //电池舱风扇 
    F_PO13 = LED22;                             //左近光
    F_PO14 = LED15;                             //位置灯
    F_PO15 = LED22;                             //右近光
    F_PO16 = 0;                                 //励磁电流

    M_PO1 = (IN19);                             //前路牌电源
    M_PO2 = (wake_up2 && IN24);                 //厢灯2
    M_PO3 = (LED15 && IN4);                     //前门踏步灯
    M_PO4 = (fKL6);                             //制动灯
    M_PO5 = (LED15 && IN3);                     //中门踏步灯 
    M_PO6 = (IN19);                             //后路牌
    M_PO7 = (wake_up2 && fKL10);                //后视镜加热
    M_PO8 = (IN9 && IN10 && LED15);             //后雾灯
    M_PO9 = (IN19);                             //侧路牌 //(wake_up2 && IN6 && fKL8); //日行灯
    M_PO10 = (wake_up2 && IN18);                //司机风扇
    M_PO11 = (wake_up2);                        //滚动屏电源
    M_PO12 = (wake_up2 && IN25);                //司机灯
    M_PO13 = (DMC_Gear == 2);                   //倒车灯电源
    M_PO14 = (pSpeed < 3);                      //门泵电源
    M_PO15 = (wake_up2 && IN23);                //厢灯1
    M_PO16 = 0;                                 //励磁电流

    /*R_PO1 = (rKL6); //制动灯
    R_PO2 = (IN19); //侧路牌
    R_PO3 = (rLED_flag); //后雾灯       
    R_PO4 = (M_ON); //整车控制器电源
    R_PO5 = (FLASH && (IN1 || wake_up1)); //左转向灯
    R_PO6 = (M_ON); //气压传感器电源
    R_PO7 = (FLASH && (IN5 || wake_up1)); //右转向
    R_PO8 = IN22; //电喇叭
    R_PO9 = (DMC_Gear == 2); //倒车灯1
    R_PO10 = IN22; //电喇叭
    R_PO11 = (mKH1 && IN6); //前门踏步灯
    R_PO12 = (IN6); //位置灯示高灯
    R_PO13 = (mKL15 && IN6); //中门踏步灯
    R_PO14 = (DMC_Gear == 2); //倒车蜂鸣器
    R_PO15 = (DMC_Gear == 2); //倒车灯2
    R_PO16 = 0;
     */
}
//模块
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
    temp.bit2 = IN14; //慢档      
    temp.bit3 = IN15; //间歇
    temp.bit4 = IN16; //快档
    temp.bit5 = IN21; //喷水        
    if (IN14 && IN16)temp.bit2 = 0;
    if (IN21) {
        temp.bit2 = 0; //慢档
        temp.bit3 = 0; //间歇
        temp.bit4 = 0; //快档
    }
    message_POUT.data[6] = temp.byte;

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
    msg.id = 0x454;
    msg.len = 0x08;
    msg.type = 0x01;
    CAN1_SendMessage(&msg);

}

/*void PCAN_CCVS(void) {
    CAN_MESSAGE message_CCVS;
    message_CCVS.id = 0x0C19A7A1;
    message_CCVS.data[0] = (unsigned char) (M_ON << 6)//ON档
            + (unsigned char) (0 << 5)//ST档
            + (unsigned char) (IN27 << 4)//后门开信号
            + (unsigned char) (IN20 << 3)//前面开信号
            + (unsigned char) (0 << 2)//后舱门开信号
            + (unsigned char) (rKL8 << 1)//驻车信号
            + (unsigned char) (rKL10 || rKL12); //气压低报警信号
    message_CCVS.data[1] = (unsigned char) (IN1 << 7)//左转向
            + (unsigned char) (IN7 << 6)//远光灯
            + (unsigned char) (IN9 << 5)//前雾灯
            + (unsigned char) (IN5 << 4)//右转向
            + (unsigned char) (IN33 << 3)//油量报警
            + (unsigned char) (0 << 2)//发动机预热
            + (unsigned char) (IN8 << 1)//近光灯
            + (unsigned char) (rLED_flag); //后雾灯
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
//气泵系统
void PCAN_DMQTD8(void) {
    CAN_MESSAGE message_DMQTD8;
    unsigned char temp = 0;
    message_DMQTD8.id = 0x18AB9B28;
    message_DMQTD8.data[0] = 0;

    if (ADR[1] < 10)
        temp = 0;
    else if (ADR[1] < 52)
        temp = ((ADR[1] - 10) / 2.1);
    else if (ADR[1] < 88)
        temp = (20 + ((ADR[1] - 52) / 1.8));
    else if (ADR[1] < 124)
        temp = (40 + ((ADR[1] - 88) / 1.8));
    else if (ADR[1] < 155)
        temp = (60 + ((ADR[1] - 124) / 1.55));
    else if (ADR[1] < 180)
        temp = (80 + ((ADR[1] - 155) / 1.25));
    else temp = 100;
    message_DMQTD8.data[1] = temp; //气压1

    if (ADR[2] < 10)
        temp = 0;
    else if (ADR[2] < 52)
        temp = ((ADR[2] - 10) / 2.1);
    else if (ADR[2] < 88)
        temp = (20 + ((ADR[2] - 52) / 1.8));
    else if (ADR[2] < 124)
        temp = (40 + ((ADR[2] - 88) / 1.8));
    else if (ADR[2] < 155)
        temp = (60 + ((ADR[2] - 124) / 1.55));
    else if (ADR[2] < 180)
        temp = (80 + ((ADR[2] - 155) / 1.25));
    else temp = 100;
    message_DMQTD8.data[2] = temp; //气压2
    
    message_DMQTD8.data[3] = 0;
    message_DMQTD8.data[4] = 0;
    message_DMQTD8.data[5] = 0;
    message_DMQTD8.data[6] = 0;
    message_DMQTD8.data[7] = 0;
    message_DMQTD8.len = 8;
    message_DMQTD8.type = 0;
    CAN2_SendMessage(&message_DMQTD8);
}
//电机系统
/*void PCAN_DMC(void) {
    CAN_MESSAGE message_DMQTD8;
    DATA_BIT CAN_DATA;
    message_DMQTD8.id = 0x1882BBAB;
    CAN_DATA.bit1 = !IN4; //前门状态
    CAN_DATA.bit2 = IN4;
    CAN_DATA.bit3 = (!IN3 && !mKH1); //中门状态和后舱门状态
    CAN_DATA.bit4 = (IN3 || mKH1);
    CAN_DATA.bit5 = IN27; //强制行车开关
    CAN_DATA.bit6 = fKL2; //手刹
    CAN_DATA.bit7 = 1;
    CAN_DATA.bit8 = 1;
    message_DMQTD8.data[0] = CAN_DATA.byte;*/
    /*message_DMQTD8.data[0] = (unsigned char) (IN3 << 3)//中门关信号
            + (unsigned char) (!IN3 << 2)//中门开信号
            + (unsigned char) (IN4 << 1)//前门关信号
            + (unsigned char) (!IN4); //前门开信号*/
  /*  message_DMQTD8.data[1] = (unsigned char) Battery_Temp_H;
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
*///电机系统
void PCAN_DMC(void) {
    CAN_MESSAGE message_DMQTD8;
    DATA_BIT CAN_DATA;
    message_DMQTD8.id = 0x18F84E37;

    message_DMQTD8.data[0] = ADR[0]/10*2;

    message_DMQTD8.data[1] = 0;
message_DMQTD8.data[2] = pSpeed;
    CAN_DATA.bit1 = IN1; //前门状态
    CAN_DATA.bit2 = 0;
    CAN_DATA.bit3 = IN5; //中门状态和后舱门状态
    CAN_DATA.bit4 = 0;
    CAN_DATA.bit5 = IN10; //制行车开关
    CAN_DATA.bit6 = 0; //手刹
    CAN_DATA.bit7 = IN34;
    CAN_DATA.bit8 = 0;
    message_DMQTD8.data[3] = CAN_DATA.byte;
CAN_DATA.bit1 = fKL6; //前门状态
    CAN_DATA.bit2 = 0;
    CAN_DATA.bit3 = 0; //中门状态和后舱门状态
    CAN_DATA.bit4 = 0;
    CAN_DATA.bit5 = LED9|| LED11; //制行车开关
    CAN_DATA.bit6 = 0; //手刹
    CAN_DATA.bit7 = fKL2;
    CAN_DATA.bit8 = 0;
    message_DMQTD8.data[4] = CAN_DATA.byte;
CAN_DATA.bit1 = 0; //前门状态
    CAN_DATA.bit2 = 0;
    CAN_DATA.bit3 = 0; //中门状态和后舱门状态
    CAN_DATA.bit4 = 0;
    CAN_DATA.bit5 = 0; //制行车开关
    CAN_DATA.bit6 = 0; //手刹
    CAN_DATA.bit7 = 0;
    CAN_DATA.bit8 = 0;
    message_DMQTD8.data[5] = CAN_DATA.byte;
CAN_DATA.bit1 = 0; //前门状态
    CAN_DATA.bit2 = 0;
    CAN_DATA.bit3 = mKH1; //中门状态和后舱门状态
    CAN_DATA.bit4 = 0;
    CAN_DATA.bit5 = LED1; //制行车开关
    CAN_DATA.bit6 = 0; //手刹
    CAN_DATA.bit7 = LED2;
    CAN_DATA.bit8 = 0;
    message_DMQTD8.data[6] = CAN_DATA.byte;
    message_DMQTD8.data[7] = 0xff;
    message_DMQTD8.len = 8;
    message_DMQTD8.type = 0;
    CAN2_SendMessage(&message_DMQTD8);
}
/*void PCAN_send_mile(void) {
    CAN_MESSAGE msg;
    msg.data[0] = (unsigned char) (e_total_miles); //低八位
    msg.data[1] = (unsigned char) (e_total_miles >> 8); //二级八位
    msg.data[2] = (unsigned char) (e_total_miles >> 16); //三级八位
    msg.data[3] = (unsigned char) (e_total_miles >> 24); //高八位
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

    msg.data[0] = 0; //低八位
    msg.data[1] = 0; //中八位
    msg.data[2] = 0; //高八位
   
    msg.data[3] = 0;
    temp = (e_total_miles );
    msg.data[4] = (unsigned char) (temp); //低八位
    msg.data[5] = (unsigned char) (temp >> 8); //中八位;
    msg.data[6] = (unsigned char) (temp >> 16); //中八位;
    msg.data[7] = (unsigned char) (temp >> 24); //中八位;
    msg.id = 0x18F85037;
    msg.len = 0x08;
    msg.type = 0x00;
    CAN2_SendMessage(&msg);
}

void PCAN_SEND1(void) {
    CAN_MESSAGE msg;
    unsigned char temp = 0;
    DATA_BIT CAN_DATA;
    
    if (ADR[1] < 10)
        temp = 0;
    else if (ADR[1] < 52)
        temp = ((ADR[1] - 10) / 2.1);
    else if (ADR[1] < 88)
        temp = (20 + ((ADR[1] - 52) / 1.8));
    else if (ADR[1] < 124)
        temp = (40 + ((ADR[1] - 88) / 1.8));
    else if (ADR[1] < 155)
        temp = (60 + ((ADR[1] - 124) / 1.55));
    else if (ADR[1] < 180)
        temp = (80 + ((ADR[1] - 155) / 1.25));
    else temp = 100;
    msg.data[0] = temp; //气压1
    
    if (ADR[2] < 10)
        temp = 0;
    else if (ADR[2] < 52)
        temp = ((ADR[2] - 10) / 2.1);
    else if (ADR[2] < 88)
        temp = (20 + ((ADR[2] - 52) / 1.8));
    else if (ADR[2] < 124)
        temp = (40 + ((ADR[2] - 88) / 1.8));
    else if (ADR[2] < 155)
        temp = (60 + ((ADR[2] - 124) / 1.55));
    else if (ADR[2] < 180)
        temp = (80 + ((ADR[2] - 155) / 1.25));
    else temp = 100;
    msg.data[1] = temp; //气压2   
    msg.data[2] = 0;
    msg.data[3] = 0;

    CAN_DATA.bit1 = 0;            //钥匙ON
    CAN_DATA.bit2 = 0;           //手刹
    CAN_DATA.bit3 = 0; //倒车
    CAN_DATA.bit4 = 0;               //保留
    CAN_DATA.bit5 = 0;               //保留
    CAN_DATA.bit6 = 0;               //保留
    CAN_DATA.bit7 = 0;            //后舱门
    CAN_DATA.bit8 = 0;               //保留
    msg.data[4] = 0;

    CAN_DATA.bit1 = 0;                            //保留
    CAN_DATA.bit2 = 0; //蓄电池电压低
    CAN_DATA.bit3 = 0;//仪表系统故障
   
    CAN_DATA.bit4 = 0;                         //中门
    CAN_DATA.bit5 = 0;                         //前门
    CAN_DATA.bit6 = 0;                            //保留
    CAN_DATA.bit7 = 0;                            //保留
    CAN_DATA.bit8 = 0;                            //保留
    msg.data[5] = 0;

    msg.data[6] = 0;
    msg.data[7] = 0;
    msg.id = 0x18F84F37;
    msg.len = 0x08;
    msg.type = 0x00;
    CAN2_SendMessage(&msg);
}

void PCAN_SEND3(void) {
    CAN_MESSAGE msg;
    DATA_BIT CAN_DATA;

    CAN_DATA.bit1 = LED20; //后雾灯
    CAN_DATA.bit2 = 0;
    CAN_DATA.bit3 = LED19; //前雾灯
    CAN_DATA.bit4 = 0;
    CAN_DATA.bit5 = LED8;  //右转向
    CAN_DATA.bit6 = 0;
    CAN_DATA.bit7 = LED4;  //左转向
    CAN_DATA.bit8 = 0;
    msg.data[0] = CAN_DATA.byte;

    CAN_DATA.bit1 = 0;    //中桥制动气压报警信号
    CAN_DATA.bit2 = 0;
    CAN_DATA.bit3 = LED9; //前桥制动气压报警信号
    CAN_DATA.bit4 = 0;
    CAN_DATA.bit5 = 0;    //制动报警信号
    CAN_DATA.bit6 = 0;
    CAN_DATA.bit7 = LED24; //制动灯信号
    CAN_DATA.bit8 = 0;
    msg.data[1] = CAN_DATA.byte;

    CAN_DATA.bit1 = LED17; //远光灯信号
    CAN_DATA.bit2 = 0;
    CAN_DATA.bit3 = 0;     //超车灯信号
    CAN_DATA.bit4 = 0; 
    CAN_DATA.bit5 = 0;     //电喇叭信号
    CAN_DATA.bit6 = 0;
    CAN_DATA.bit7 = LED11; //后桥制动气压报警信号
    CAN_DATA.bit8 = 0;
    msg.data[2] = CAN_DATA.byte;

    CAN_DATA.bit1 = (mKL4 || mKL6); //门泵应急阀开关报警
    CAN_DATA.bit2 = 0;
    CAN_DATA.bit3 = wake_up1;       //双闪灯信号
    CAN_DATA.bit4 = 0;
    CAN_DATA.bit5 = LED15;            //位置灯信号
    CAN_DATA.bit6 = 0;
    CAN_DATA.bit7 = LED22;            //近光灯信号
    CAN_DATA.bit8 = 0;
    msg.data[3] = CAN_DATA.byte;

    CAN_DATA.bit1 = IN36;     //ASR 故障灯
    CAN_DATA.bit2 = 0; //
    CAN_DATA.bit3 = IN37;     //ABS 故障灯
    CAN_DATA.bit4 = 0;
    CAN_DATA.bit5 = wake_up2; //钥匙 ACC 档
    CAN_DATA.bit6 = 0;
    CAN_DATA.bit7 = M_ON;     //钥匙 ON 档
    CAN_DATA.bit8 = 0;
    msg.data[4] = CAN_DATA.byte;

    CAN_DATA.bit1 = 0; //保留
    CAN_DATA.bit2 = 0;
    CAN_DATA.bit3 = 0; //低水位报警
    CAN_DATA.bit4 = 0;
    CAN_DATA.bit5 = 0; //空调控制电源
    CAN_DATA.bit6 = 0;
    CAN_DATA.bit7 = 0; //除霜开关
    CAN_DATA.bit8 = 0;
    msg.data[5] = CAN_DATA.byte;

    msg.data[6] = 0;
    msg.data[7] = 0;
    msg.id = 0x18FFA217;
    msg.len = 0x08;
    msg.type = 0x00;
    CAN2_SendMessage(&msg);
}
//BMS控制
void PCAN_LCD_BMS(void) {
    CAN_MESSAGE msg;
    msg.data[0] = BMU_Number;
    msg.data[1] = 0xff;
    msg.data[2] = 0xFF;
    msg.data[3] = 0xFF;
    msg.data[4] = 0xFF;
    msg.data[5] = 0xFF;
    msg.data[6] = 0xFF;
    msg.data[7] = 0xFF;
    msg.id = 0x1800F328;
    msg.len = 0x08;
    msg.type = 0x00;
    CAN2_SendMessage(&msg);

}
//博世杰行车记录仪
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

    CAN_DATA.bit1 = LED22;             //近光灯
    CAN_DATA.bit2 = 0;
    CAN_DATA.bit3 = (LED19 || LED20);  //雾灯
    CAN_DATA.bit4 = 0;
    CAN_DATA.bit5 = M_PO13;            //倒车灯
    CAN_DATA.bit6 = 0;
    CAN_DATA.bit7 = 0;                 //喇叭
    CAN_DATA.bit8 = 0;
    msg.data[0] = CAN_DATA.byte;

    CAN_DATA.bit1 = 0; /*((DMC_Level == 0 && DMC_Status == 3) || //电机严重故障
            (((DMY_Status >> 4) & 0x03) == 2) ||            //油泵故障
            (((DMQ_Status >> 4) & 0x03) == 2) ||            //气泵故障
            (DCDC_Code > 0 && DCDC_Code < 51) ||            //DCDC严重故障
            LED14);                                         //电池系统故障
    */
    CAN_DATA.bit2 = 0;
    CAN_DATA.bit3 = LED8;               //右转向灯
    CAN_DATA.bit4 = 0;
    CAN_DATA.bit5 = LED4;               //左转向
    CAN_DATA.bit6 = 0;
    CAN_DATA.bit7 = (IN3 || IN4);       //车门开
    CAN_DATA.bit8 = 0;
    msg.data[1] = CAN_DATA.byte;

    CAN_DATA.bit1 = 0;                  //门强制选择开关
    CAN_DATA.bit2 = 0;
    CAN_DATA.bit3 = 0;
    CAN_DATA.bit4 = 0;
    CAN_DATA.bit5 = (fKL9 || fKL11);     //低气压报警
    CAN_DATA.bit6 = 0;
    CAN_DATA.bit7 = LED17;              //远光灯
    CAN_DATA.bit8 = 0;
    msg.data[2] = CAN_DATA.byte;

    CAN_DATA.bit1 = 0; //水温高报警
    CAN_DATA.bit2 = 0;
    CAN_DATA.bit3 = 0; //水位低报警
    CAN_DATA.bit4 = 0;
    CAN_DATA.bit5 = 0; //空滤报警
    CAN_DATA.bit6 = 0;
    CAN_DATA.bit7 = 0; //油压报警
    CAN_DATA.bit8 = 0;
    msg.data[3] = CAN_DATA.byte;

    CAN_DATA.bit1 = fKL9;  //前气压报警
    CAN_DATA.bit2 = 0;    
    CAN_DATA.bit3 = fKL11; //后气压报警
    CAN_DATA.bit4 = 0;
    CAN_DATA.bit5 = 0;
    CAN_DATA.bit6 = 0;
    CAN_DATA.bit7 = 0;
    CAN_DATA.bit8 = 0;
    msg.data[4] = CAN_DATA.byte;

    CAN_DATA.bit1 = fKL6; //刹车工作
    CAN_DATA.bit2 = 0;
    CAN_DATA.bit3 = 0;    //缓速器工作
    CAN_DATA.bit4 = 0;
    CAN_DATA.bit5 = IN4;  //门2开
    CAN_DATA.bit6 = 0;
    CAN_DATA.bit7 = IN3;  //门1开
    CAN_DATA.bit8 = 0;
    msg.data[5] = CAN_DATA.byte;

    CAN_DATA.bit1 = 0; //左门3
    CAN_DATA.bit2 = 0;
    CAN_DATA.bit3 = 0; //左门2
    CAN_DATA.bit4 = 0;
    CAN_DATA.bit5 = 0; //左门1
    CAN_DATA.bit6 = 0;
    CAN_DATA.bit7 = 0; //左右门选择 00左门 01右门
    CAN_DATA.bit8 = 0;
    msg.data[6] = CAN_DATA.byte;

    CAN_DATA.bit1 = 0; //右门3
    CAN_DATA.bit2 = 0;
    CAN_DATA.bit3 = 0; //右门2
    CAN_DATA.bit4 = 0;
    CAN_DATA.bit5 = 0; //右门1
    CAN_DATA.bit6 = 0;
    CAN_DATA.bit7 = 0; //车型选择 00普通公交车 01BRT车
    CAN_DATA.bit8 = 0;
    msg.data[7] = CAN_DATA.byte;
    msg.id = 0x18FED925;
    msg.len = 0x08;
    msg.type = 0x00;
    CAN2_SendMessage(&msg);
}

char Count_Time(unsigned char condition, //启动条件
        unsigned int  out_time,           //条件满足，工作时间
        unsigned char cycle_en,           //是否循环执行
        unsigned int  stop_time           //循环执行时，间歇时间
        ) { 
    static unsigned int temp = 0;
    if (condition) {
        temp = temp > 60000 ? 60000 : temp + 1; //计数上限，防止溢出
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
                for (j = 0; j < 4; j++) {//输出状态采集
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
/*CAN_SIGNAL_TYPE_S CAN_SIGNAL = {
    .ID_1002FF1E.DMC_Torque = 32000,
    .ID_1002FF1E.DMC_Rpm = 32000,
    .ID_1003FF1E.DMC_Controller_temp = 40,
    .ID_1003FF1E.DMC_Moto_temp = 40,
    .ID_1003FF1E.DMC_Current = 32000
};*/

//电机
unsigned char DMC_Status; //电机控制器基本状态
unsigned char DMC_Level; //电机控制器故障级别
unsigned char DMC_Life; //电机生命
unsigned int DMC_Torque = 20000; //电机转矩
unsigned int DMC_Rpm = 20000; //电机转速
unsigned char DMC_Speed; //车速
unsigned char DMC_Gear; //档位

unsigned int DMC_Voltage; //电机控制器母线电压
unsigned int DMC_Current = 32000; //电机控制器母线电流
unsigned char DMC_Controller_temp = 40; //电机控制器温度
unsigned char DMC_Moto_temp = 40; //电机温度
unsigned char DMC_Protect_code; //电机控制器故障代码
unsigned char DMC_Verison; //电机控制器版本号

unsigned char DMC_Accelerator_percent; //油门踏板开度
unsigned char DMC_Brake_percent; //制动踏板开度
unsigned char DMC_Charge; //充放电状态
unsigned char DMC_GB_Gear; //国标档位

//气泵控制器
unsigned int DMQ_Rpm; //气泵控制器电机转速
unsigned int DMQ_Voltage; //气泵控制器母线电压
unsigned char DMQ_Current; //气泵控制器电机母线电流
unsigned char DMQ_temp = 40; //气泵温度
unsigned char DMQ_Controller_temp = 40; //气泵控制器温度
unsigned char DMQ_Life; //气泵控制器生命
unsigned char DMQ_Status; //气泵控制器基本状态

//DCDC
unsigned char DCDC_Status; //DCDC基本状态
unsigned char DCDC_Temp = 40; //DCDC模块温度
unsigned int DCDC_Voltage; //DCDC输出电压
unsigned int DCDC_Current = 32000; //DCDC输出电流
unsigned char DCDC_Code; //DCDC故障代码
unsigned char DCDC_Verison; //DCDC版本号

//油泵控制器
unsigned int DMY_Rpm; //油泵控制器电机转速
unsigned int DMY_Voltage; //油泵控制器母线电压
unsigned char DMY_Current; //油泵控制器电机母线电流
unsigned char DMY_Controller_temp = 40; //油泵控制器温度
unsigned char DMY_Life; //油泵控制器生命
unsigned char DMY_Status; //油泵控制器基本状态

//空调
unsigned char Air_Status_Flag1; //空调状态1
unsigned char Air_Status_Flag2; //空调状态2
unsigned char Air_Status_Flag3; //空调状态3
unsigned char Air_Indoor_t = 60; //室内温度
unsigned char Air_Outdoor_t = 60; //室外温度
unsigned char Air_Set_t = 60; //设定


//BMS
unsigned char BMS_Type; //BMS参数类型
unsigned char Battery_Case_Total_Number; //电池箱体个数
unsigned char BMS_Unit_Number = 1; //电池管理系统从控单元个数
unsigned int Battery_Cell_Total_Number; //电池总串数
unsigned int BMS_Nubmer; //电池管理系统编号

unsigned char Battery_Case_number; //电池箱号n
unsigned char Battery_Cell_number; //电池箱n内电池串数
unsigned char Battery_Cell_Temp_Number; //电池箱内电池温度探头个数

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

unsigned char Battery_Single_H_Positon_Case; //电池单体高电压箱号
unsigned char Battery_Single_H_Positon_Cell; //电池单体高电压位置
unsigned char Battery_Single_L_Positon_Case; //电池单体低电压箱号
unsigned char Battery_Single_L_Positon_Cell; //电池单体低电压位置
unsigned char Battery_Temp_H_Positon_Case; //电池单体高温度箱号
unsigned char Battery_Temp_H_Positon_Cell; //电池单体高温度位置
unsigned char Battery_Temp_L_Positon_Case; //电池单体低温度箱号
unsigned char Battery_Temp_L_Positon_Cell; //电池单体低温度位置

DATA_BIT      BMU_Comm_Status[4]; //1-8   BMU通讯状态
/*unsigned char BMU_Comm_Status2; //9-16  BMU通讯状态
unsigned char BMU_Comm_Status3; //17-24 BMU通讯状态
unsigned char BMU_Comm_Status4; //25-32 BMU通讯状态*/

DATA_BIT      BMU_Bala_Status[4]; //1-8   BMU均衡状态
/*unsigned char BMU_Bala_Status2; //9-16  BMU均衡状态
unsigned char BMU_Bala_Status3; //17-24 BMU均衡状态
unsigned char BMU_Bala_Status4; //25-32 BMU均衡状态*/


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

unsigned char BMU_Number = 1; //BMU号

unsigned char Battery_Pack; //电池报文包数
unsigned int Battery_Voltage[12]; //电池单体电压
unsigned int Battery_Temp[12]; //电池单体温度

/******************************************************************************/
unsigned int  BMS_Status;
unsigned char Battery_Temp_avg = 40; //电池单体平均温度
unsigned char Battery_Oum_Status; 

unsigned char BMS_Charge_Status; 
unsigned char BMS_Warn; 
unsigned char BMS_Fault_Number; 

unsigned char KT; 
/******************************************************************************/
_CAN_0x10F811A4 CAN_0x10F811A4;
_CAN_0x10F813A4 CAN_0x10F813A4;
_CAN_0x0C109E27 CAN_0x0C109E27;
_CAN_0x10F8159E CAN_0x10F8159E;
_CAN_0x10F8179E CAN_0x10F8179E;
_CAN_0x18F8189E CAN_0x18F8189E;
_CAN_0x18F8199E CAN_0x18F8199E;
_CAN_0x18F81B9E CAN_0x18F81B9E;
_CAN_0x10F8209E CAN_0x10F8209E;
_CAN_0x10F8219E CAN_0x10F8219E;
_CAN_0x10F8239E CAN_0x10F8239E;
_CAN_0x18F81F27 CAN_0x18F81F27;
_CAN_0x18F80227 CAN_0x18F80227;
unsigned char BATCellNumber; 
unsigned char BATCellTemp[20][7]; 
unsigned char BATCellVoltage[200];
/******************************************************************************/

void __attribute__((__interrupt__, auto_psv)) _C2Interrupt(void) {
    unsigned char i = 0,temp = 0;
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
        switch (msg.id) {
            case 0x0C11A427: 
                DMC_Gear = msg.data[6];                
                break;
                
            case 0x10F810A4: 
                DMC_Status = (msg.data[0] >> 5)&0x07;
                DMC_Level = (msg.data[0] >> 3)&0x03;
                DMC_Torque = (unsigned char) msg.data[2]+((unsigned int) msg.data[3] << 8);
                DMC_Rpm = (unsigned char) msg.data[4]+((unsigned int) msg.data[5] << 8);
                DMC_Protect_code = msg.data[6];               
                break;
                
            case 0x10F811A4://
                DMC_Voltage = ((unsigned char) msg.data[0]+((unsigned int) msg.data[1] << 8));
                DMC_Current = ((unsigned char) msg.data[2]+((unsigned int) msg.data[3] << 8));
                DMC_Controller_temp = msg.data[4];
                DMC_Moto_temp = msg.data[5];
                DMC_Life = msg.data[6];
                DMC_Verison = msg.data[7];
                for (i = 0; i < 8; i++) {
                    CAN_0x10F811A4.byte[i] = msg.data[i];
                }
                break;
                
            case 0x10F813A4://
                for (i = 0; i < 8; i++) {
                    CAN_0x10F813A4.byte[i] = msg.data[i];
                }
                break;
                
            case 0x0C109E27://
                KT = msg.data[0];
                for (i = 0; i < 8; i++) {
                    CAN_0x0C109E27.byte[i] = msg.data[i];
                }
                break; 
                
            case 0x18F81E27: 
                DMC_Speed = msg.data[1];                
                break;
                
            case 0x10F8159E://
                BMS_Status = msg.data[0];
                Battery_Temp_avg = msg.data[1];
                BMS_SOC = msg.data[2];
                BMS_A = ((unsigned char) msg.data[3]
                        +((unsigned int) msg.data[4] << 8));
                BMS_V = ((unsigned char) msg.data[5]
                        +((unsigned int) msg.data[6] << 8));               
                
                for (i = 0; i < 8; i++) {
                    CAN_0x10F8159E.byte[i] = msg.data[i];
                }
                break;
                
            case 0x10F8179E://
                Battery_Temp_L = msg.data[0];
                Battery_Temp_L_Positon_Case = msg.data[1];
                Battery_Temp_L_Positon_Cell = msg.data[2];
                for (i = 0; i < 8; i++) {
                    CAN_0x10F8179E.byte[i] = msg.data[i];
                }
                break;  
                
            case 0x18F8189E://
                Battery_Temp_H = msg.data[0];
                Battery_Temp_H_Positon_Case = msg.data[1];
                Battery_Temp_H_Positon_Cell = msg.data[2];
                for (i = 0; i < 8; i++) {
                    CAN_0x18F8189E.byte[i] = msg.data[i];
                }
                break;   
                
            case 0x18F8199E://
                Battery_Single_L = ((unsigned char) msg.data[0]+((unsigned int) msg.data[1] << 8));
                Battery_Single_L_Positon_Case = msg.data[2];
                Battery_Single_L_Positon_Cell = msg.data[3];
                for (i = 0; i < 8; i++) {
                    CAN_0x18F8199E.byte[i] = msg.data[i];
                }
                break; 
                
            case 0x18F81B9E://
                Battery_Single_H = ((unsigned char) msg.data[0]+((unsigned int) msg.data[1] << 8));
                Battery_Single_H_Positon_Case = msg.data[2];
                Battery_Single_H_Positon_Cell = msg.data[3];
                for (i = 0; i < 8; i++) {
                    CAN_0x18F81B9E.byte[i] = msg.data[i];
                }
                break;   
                
            case 0x10F81D9E://
                BMS_Warn = msg.data[0]; 
                BMS_Charge_Status = msg.data[1];
                DC1positive_Temp = msg.data[2];
                DC1negative_Temp = msg.data[3];
                DC2positive_Temp = msg.data[4];
                DC2negative_Temp = msg.data[5];
                BMS_Life = msg.data[6];
                Energe_Rest = msg.data[7];
                break;  
                
            case 0x10F8209E://
                BMS_Fault_Number = msg.data[0]; 
                Energe_Rest = ((unsigned char) msg.data[1]+((unsigned int) msg.data[2] << 8));
                Battery_Cell_Total_Number = ((unsigned char) msg.data[3]+((unsigned int) msg.data[4] << 8));
                for (i = 0; i < 8; i++) {
                    CAN_0x10F8209E.byte[i] = msg.data[i];
                }
                break;  
                
            case 0x10F8219E:
                Ohm_Positive=((unsigned char) msg.data[6]+((unsigned int) msg.data[7] << 8));
               // for (i = 0; i < 8; i++) {
                 //   CAN_0x10F8219E.byte[i] = msg.data[i];
                //}
                break;
                
            case 0x10F8239E:
                for (i = 0; i < 8; i++) {
                    CAN_0x10F8239E.byte[i] = msg.data[i];
                }
                break;    
                
            case 0x18F81F27:
                for (i = 0; i < 8; i++) {
                    CAN_0x18F81F27.byte[i] = msg.data[i];
                }
                break;  
                
            case 0x18F80227:
                 DMC_Accelerator_percent=msg.data[0];//油门踏板开度
                 DMC_Brake_percent=msg.data[8];
                //for (i = 0; i < 8; i++) {
                  //  CAN_0x18F80227.byte[i] = msg.data[i];
                //}
                break;     
        }
        for (i = 0; i < 20; i++) {
            if (msg.id == (0x18F88F9E + ((unsigned long) i << 8))){
                BATCellNumber = msg.data[0];
                if (BATCellNumber < 20) {
                    BATCellTemp[BATCellNumber][0] = msg.data[1];
                    BATCellTemp[BATCellNumber][1] = msg.data[2];
                    BATCellTemp[BATCellNumber][2] = msg.data[3];
                    BATCellTemp[BATCellNumber][3] = msg.data[4];
                    BATCellTemp[BATCellNumber][4] = msg.data[5];
                    BATCellTemp[BATCellNumber][5] = msg.data[6];
                    BATCellTemp[BATCellNumber][6] = msg.data[7];
                }
            }
        }
        for (i = 0; i < 50; i++) {
            if (msg.id == (0x18F8AF9E + ((unsigned long) i << 8))) {
                BATCellVoltage[i * 4] = ((unsigned char) msg.data[0]+((unsigned int) msg.data[1] << 8));
                BATCellVoltage[i * 4 + 1] = ((unsigned char) msg.data[2]+((unsigned int) msg.data[3] << 8));
                BATCellVoltage[i * 4 + 2] = ((unsigned char) msg.data[4]+((unsigned int) msg.data[5] << 8));
                BATCellVoltage[i * 4 + 3] = ((unsigned char) msg.data[6]+((unsigned int) msg.data[7] << 8));
            }
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
        } else {
            count6++;
        }
    } else {
        count6 = 0;
    }

    if (delay_cnt > 0) delay_cnt--; //延时计数器 

    //延迟10秒输出，速率要高於SYSTEM_LOGIC,不然会有延迟
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
        if (M_ON_flag && (wake_up3 || wake_up2)) {//若放在main函数里，会导致闪烁频率异常wake_up3置0时，M_ON不会立马置0，因为存在消抖延时
            LED_Logic();
            LED_Out();
            SYSTME_Logic();
        }
        F50ms = 1;
    } else cnt0++;

    if (can1 == 0)//100ms循环发送报文
        PCAN_DMC();
    else if (can1 == 1)
        PCAN_Send_TCO1();
    else if (can1 == 2 && frmID==7)//在电池界面时才发送电池
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

    if (can2 == 5)//500ms循环发送报文
        PCAN_LCD_CANBUS1();
    else if (can2 == 7)
        PCAN_SEND3();
    if (can2 >= 49)
        can2 = 0;
    else can2++;

    if (cnt1 >= 9) {//100ms
        cnt1 = 0;
        F100ms = 1;
        //PCAN_CCVS();        
        //PCAN_DMQTD8();       
        //PCAN_SEND1();        
        //计算累计里程
        if (pSpeed > 0) {//车速大于0时才累计
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
        BAT24V_count = BAT24V_count >= BAT24_TIME ? BAT24_TIME : BAT24V_count + 1;

        if (cnt4 >= 9) {//1s
            cnt4 = 0;
            F1000ms = 1;
            FLASH_1s = !FLASH_1s;
            //PCAN_send_mile();
            //输出5秒，10分钟循环
            if (CAN_0x10F813A4.MotoSpeed < 20300) count7 = 0;
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
        //PCAN_LCD_CANBUS1();
        //PCAN_SEND3();
        F500ms_LCD = !F500ms_LCD;
    } else cnt2++;

    if (wake_up3) { //ON开关判断//消抖//M_ON在掉电的一瞬间会使上拉电源无效，而M_ON在断电会保持300ms，从而影响开关量采集
        if (cnt3 > 30) M_ON = 1;
        else cnt3++;
    } else {
        if (cnt3 < 1) M_ON = 0;
        else cnt3--;
    }

    if (IN10 && LED15 && (LED17 || LED22) && IN9) { //后雾灯开关是常开开关，消抖
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
        if (lpcnt1 >= 200) {//组合按钮，长按AV和UP按钮
            //lpcnt1 = 0;
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

