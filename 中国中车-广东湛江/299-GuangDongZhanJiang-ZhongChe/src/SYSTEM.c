#include "SYSTEM.h"
#include "LOGO.h"
unsigned char delay_cnt;
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

unsigned int ADR[8]; //模拟量采集   10/15


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

unsigned int ADR[8]; //仪表模拟信号采集值    2016/10/10

DBCM_POUT fPOUT; //前模块功率输出状态
DBCM_POUT mPOUT; //中（顶）模块功率输出状态
DBCM_POUT rPOUT; //后模块功率输出状态

unsigned char fPF[15]; //前模块功率输出故障
unsigned char mPF[15]; //中（顶）模块功率故障
unsigned char rPF[15]; //后模块功率输出故障

unsigned int fSingle_miles;
unsigned int mSingle_miles;
unsigned int rSingle_miles;

unsigned char ccvs_eng_req; //启动请求

unsigned char dm_hcu_display[32]; //故障类型
unsigned char dm_tcu_display[32];


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
            F_PO9 = FLASH;
            F_PO10 = FLASH;
            M_PO7 = FLASH;
            M_PO8 = FLASH;
            LED4 = FLASH; //左转向灯
            LED8 = FLASH; //右转向灯 
        } else {
            F_PO9 = 0;
            F_PO10 = 0;
            M_PO7 = 0;
            M_PO8 = 0;
            LED4 = 0; //左转向灯
            LED8 = 0; //右转向灯 
        }
              
        if (F50ms) {
            F50ms = 0;
            LED_Out();
            SW_Input();
            BCAN_SendCtl();
        }
        
        if (M_ON || wake_up2)  break; // 如果是ON唤醒则正常退出
        
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

void SYSTME_Logic(void) {
   // F_PO1 = (IN16 && M_ON); //雨刮快档
   // F_PO2 = (IN14 && M_ON); //雨刮慢档
   // F_PO3 = (IN21 && M_ON); //喷水电机
    F_PO4 = (IN6 && IN9 && M_ON); //左前雾灯
    F_PO5 = (fKH1 && M_ON); //倒车灯
    F_PO6 = (FLASH && (IN5 || wake_up1) && M_ON); //右转向灯
    F_PO7 = (FLASH && (IN1 || wake_up1) && M_ON); //左转向灯
    F_PO8 = M_ON; //液位显示电源
    F_PO9 = (IN7 && M_ON); //左远关灯
    F_PO10 = (IN6 && IN9 && M_ON); //右前雾灯
    F_PO11 = (IN7 && M_ON); //右远光灯
    F_PO12 = M_ON; //行车记录仪电源
    F_PO13 = (IN8 && M_ON); //左近光
    F_PO14 = (IN6 && M_ON); //位置灯
    F_PO15 = (IN8 && M_ON); //右近光

    M_PO1 = (IN12 && M_ON); //广告灯
    M_PO2 = (FLASH && (IN5 || wake_up1) && M_ON); //右转向灯
    M_PO3 = ((mKH1 || mKL15) && M_ON); //车内指示灯电源
    M_PO4 = ((fKL6 || rKL6) && M_ON); //制动灯
    M_PO5 = (IN20 && (moto_speed<50) && M_ON); //前门开电磁阀
    M_PO6 = (IN19 && M_ON); //前路牌
    M_PO7 = (IN28 && M_ON); //前门关电磁阀
    M_PO8 = (IN19 && M_ON); //侧路牌
    M_PO9 = (IN27 && (moto_speed<50) && M_ON); //中门开电磁阀
    M_PO10 = (IN19 && M_ON); //后路牌
    M_PO11 = (IN26 && M_ON); //中门关电磁阀
    M_PO12 = (IN19 && M_ON); //滚动电子
    M_PO13 = (IN6 && M_ON); //小灯
    M_PO14 = (IN19 && M_ON); //后广告屏
    M_PO15 = (FLASH && (IN1 || wake_up1) && M_ON); //左转向灯
    
    R_PO1 = ((fKL6 || rKL6) && M_ON); //制动灯
    //R_PO2 = (FLASH && IN5 && M_ON); 
    R_PO3 = (rLED_flag && M_ON); //后雾灯       
    //R_PO4 = (fKL6 && M_ON); 
    R_PO5 = (FLASH && (IN1 || wake_up1) && M_ON); //左转向灯
    //R_PO6 = (IN19 && M_ON); 
    R_PO7 = (FLASH && (IN5 || wake_up1) && M_ON); //右转向
    R_PO8 = M_ON; //干燥器电源
    R_PO9 = (fKH1 && M_ON); //倒车灯
    //R_PO10 = (IN19 && M_ON); 
    R_PO11 = (mKL15 && IN6 && M_ON); //前门踏步灯
    R_PO12 = (IN6 && M_ON); //位置灯示高灯
    R_PO13 = (mKH1 && IN6 && M_ON); //中门踏步灯
    //R_PO14 = (IN19 && M_ON);
    //R_PO15 = (FLASH && IN1 && M_ON); 
    
}

void Count_ADR(void) {
    unsigned int  ad = 4096;
    //电压型传感器采集  ADR[]是实际的电压*1000
    //ADR[1] = (unsigned int) (read_ADR(1) / ad * 5000);
    //ADR[2] = (unsigned int) (read_ADR(2) / ad * 5000);
    //ADR[3] = (unsigned int) (read_ADR(3) / ad * 5000);
    //ADR[4] = (unsigned int) (read_ADR(4) / ad * 5000);
    //ADR[5] = (unsigned int) (read_ADR(5) / ad * 5000);
    //ADR[6] = (unsigned int) (read_ADR(6) / ad * 5000);
    //if (ADR[4] <= 0) ADR[4] = 0;
    //if (ADR[5] <= 0) ADR[5] = 0;
    //蓄电池电压    
    ADR[0] = (unsigned int) (550.0 * read_VOL() / ad ); //实际电压放大10倍   //(read_VOL() - 1300)*10 / 76 + 180;
    //电阻型传感器采集  ADR[]是实际的阻值
    ADR[1] = (unsigned int) (100.0*read_ADR(1)/(ad-read_ADR(1)));//((read_ADR(1) / ad * 100) / (1 - read_ADR(1) / ad));
    ADR[2] = (unsigned int) (100.0*read_ADR(2)/(ad-read_ADR(2)));
    //ADR[3] = (unsigned int) (100.0*read_ADR(3)/(ad-read_ADR(3)));
    //ADR[4] = (unsigned int) (100.0*read_ADR(4)/(ad-read_ADR(4)));
    ADR[5] = (unsigned int) (100.0*read_ADR(5)/(ad-read_ADR(5)));
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
    LED1 = ((ADR[5] < 15) && M_ON); //油量过低报警
    
    //LED2 = 0;空档
    //LED3 = (IN16 && IN29 && M_ON); //排气制动

    //左转向
    if ((IN1 && M_ON) || wake_up1)
        LED4 = FLASH;
    else LED4 = 0;

    //LED5 = (IN11 && M_ON); //进气预热

    //机油压力    
    /*if (IN33 && M_ON)//机油报警
        LED6 = 1;
    else*/ if ((Engine_oil_press * 4 <= 70) && M_ON)
        LED6 = FLASH_1s;
    else LED6 = 0;

    if ((water_temp > 138) && M_ON )//水温过高报警
        LED7 = 1;
    else if(Vcan_count==30 && M_ON)
        LED7 = FLASH_1s;
    else LED7 = 0;
    //右转向灯
    if ((IN5 && M_ON) || wake_up1 )
        LED8 = FLASH;
    else LED8 = 0;
    
    if (rKL10 && M_ON)//气压1低信号
        LED9 = 1;
    else
        LED9 = 0;

    LED10 = wake_up2; //总电源指示   

    if (rKL12 && M_ON ) //气压2
        LED11 = 1;
    else
        LED11 = 0;

    //发动机故障指示
    if (Engine_warn == 1 && M_ON)
        LED12 = 1;
    if (Engine_warn == 0)
        LED12 = 0;

    if (Maintain_warn == 1 && M_ON ) {//维护报警
        LED13 = 1;
    } else if (Maintain_warn == 0)LED13 = 0;

    //STOP停机报警
    if (Stop_warn == 1 && M_ON ) {
        LED14 = 1;
    } else if (Stop_warn == 0)LED14 = 0;
    //等待启动//没有确定信号源  
    if (Engine_wait == 1 && M_ON) {
        LED15 = 1;
    } else if (Engine_wait == 0) LED15 = 0;

    LED16 = (IN33 && M_ON); //蓄电池充电

    LED17 = (IN7 && M_ON); //远光灯

    LED18 = (rKL8 && M_ON); //手刹

    LED19 = (IN9 && M_ON); //前雾灯
   
    LED20 = (rLED_flag && M_ON);//后雾灯
    
    LED21 = (fKH1 && M_ON);//倒车灯

    LED22 = (IN8 && M_ON); //近光灯

    //LED23 = (IN14 && IN31 && M_ON);//缓速器

    LED24 = ((Brake_Pedal || fKL6 || rKL6) && M_ON); //刹车指示
    
     
    //蜂鸣器 为0时响，为1时不响   

    if ((Warn_level || (pSpeed > 69)) && M_ON)
        BUZZ = 0;
    else if (((IN33 && (Engine_Speed > 0)) || rKL10 || rKL12 || (TCU_warn == 1) ||
            ((water_temp > 138)&& (Engine_Speed > 0)) ||
            (Status_Flag1 > 0) ||
            (Status_Flag2 > 0) ||
            (Status_Flag3 > 0)) && M_ON)
        BUZZ = !FLASH_1s;
    else BUZZ = 1;
    //背光 小灯开关闭合 
    if (IN6 && M_ON) {
        OC1RS = e_backlight;
    } else {
        OC1RS = 0;
    }
    //
    
    if(M_ON){
        PO1=0;
        PO2=0;
    }else {
        PO1=1;
        PO2=1;
    }
    
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
    Maintain_warn = (CAN_18FECA00.bData[0] >> 2)&0x03; //维护报警warn
    Stop_warn = (CAN_18FECA00.bData[0] >> 4)&0x03; //停机报警stop
    Engine_warn = (CAN_18FECA00.bData[0] >> 6)&0x03; //发动机故障    

}

void BCAN_SendCtl(void) {
    CAN_MESSAGE message_POUT;
    message_POUT.id = 0x6a4;
    message_POUT.data[0] = gCTL[0].byte;
    message_POUT.data[1] = gCTL[1].byte;
    message_POUT.data[2] = gCTL[2].byte;
    message_POUT.data[3] = gCTL[3].byte;
    message_POUT.data[4] = gCTL[4].byte;
    message_POUT.data[5] = gCTL[5].byte;
    message_POUT.data[6] = (M_ON && wake_up3) + (IN14 << 1)+(IN15 << 2)+(IN16 << 3)+(IN21 << 4);//模块雨刮控制
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

void PCAN_CCVS(void) {
    CAN_MESSAGE message_CCVS;
    message_CCVS.id = 0x0C19A7A1;
    message_CCVS.data[0] = (unsigned char) (M_ON << 6)//ON档
            + (unsigned char) (0 << 5)//ST档
            + (unsigned char) (IN27 << 4)//后门开信号
            + (unsigned char) (IN20 << 3)//前面开信号
            + (unsigned char) (0 << 2)//后舱门开信号
            + (unsigned char) (rKL8 << 1)//驻车信号
            + (unsigned char) (rKL10 || rKL12) ;//气压低报警信号
    message_CCVS.data[1] = (unsigned char) (IN1 << 7)//左转向
            + (unsigned char) (IN7 << 6)//远光灯
            + (unsigned char) (IN9 << 5)//前雾灯
            + (unsigned char) (IN5 << 4)//右转向
            + (unsigned char) (IN33 << 3)//油量报警
            + (unsigned char) (0 << 2)//发动机预热
            + (unsigned char) (IN8 << 1)//近光灯
            + (unsigned char) (rLED_flag) ;//后雾灯
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

void PCAN_send_mile(void) {
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
                for (j = 0; j < 4; j++) {//输出状态采集
                    for (i = 0; i < 4; i++) {
                        fPF[i + 4 * j] = (message.data[j + 2] >> (i * 2))&0x03;
                    }
                }
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

unsigned int moto_voltage; //电机电压
unsigned int moto_current; //电机电流
unsigned int moto_speed; //电机转速
unsigned int Generator;//发电机电流

unsigned char Motor_Temperature; //电机温度
unsigned char Inverter_t; //逆变器温度
unsigned char Generator_Temperature; //发电机温度
unsigned char Generator_Inverter_t; //发电机逆变器温度


unsigned char Accelerator; //油门踏板
unsigned int Engine_Speed; //发动机转速

unsigned int Fule_rate; //油耗
unsigned char water_temp; //水温
unsigned char Engine_Fuhe; //发动机负荷
unsigned char Niaosu; //尿素;
unsigned char Accelerator_Shiji; //油门踏板实际
unsigned char Engine_oil_press; //机油压力
unsigned char ambient_air_temperature; //周围空气温度
unsigned long Engine_oil_consume; //发动机累计气耗
unsigned char Engine_oil_consume_instant; //发动机瞬时气耗

unsigned char Current_Gear; //档位
unsigned char TCU_Position; //离合位置
unsigned char TCU_warn; //变速箱故障
unsigned char STOP; //停车故障
unsigned int Speed_rmp; //输出轴转速
unsigned char Car_mode; //整车模式
unsigned char TCU_code; //变速箱故障代码
unsigned char TCU_level; //变速箱故障等级

unsigned char Parameter1;//调制参数1
unsigned char Parameter2;//调制参数2
unsigned char Parameter3;//调制参数3
unsigned char Parameter4;//调制参数4
unsigned char Parameter5;//调制参数5
unsigned char Parameter6;//调制参数6
unsigned char Parameter7;//调制参数7
unsigned char Parameter8;//调制参数8

DATA_BIT CAN_KEY[4];

unsigned char Moto_status;//电机状态
unsigned char Generator_status;//发电机状态
unsigned char Car_status;//整车

unsigned char Brake_percent; //制动踏板开度
unsigned char Speed_percent; //加速踏板开度
unsigned char Digit_input3; //数字量输入3

unsigned long Program; //程序版本
unsigned long tcu_spn; //TCU故障码
unsigned char tcu_fmi;
unsigned long tcu_cm;
unsigned char tcu_oc;
unsigned char Car_LIFE; //整车控制器

unsigned int BMS_V; //电池电压
unsigned char BMS_SOC; //电池SOC
unsigned int BMS_A; //电池电流
unsigned char Status_Flag1;
unsigned char Status_Flag2;
unsigned char Status_Flag3;

unsigned int BMS_A_charge; //最大充电电流
unsigned int BMS_A_discharge; //最大电流
unsigned char Warn_level; //故障等级
unsigned int BMS_V_average; //电池平均电压
unsigned char BMS_T_H; //电池最高温度

unsigned int Oum_zheng; //绝缘正阻值
unsigned int Oum_fu; //绝缘负阻值

unsigned int Battery_single_H; //电池单体高电压
unsigned char Battery_number_H; //高压电池编号
unsigned char Battery_case_H; //高压电池箱号
unsigned int Battery_single_L; //电池单体低电压
unsigned char Battery_number_L; //高压电池编号
unsigned char Battery_case_L; //高压电池箱号
unsigned char Battery_number_t; //最高电池温度编号
unsigned char Battery_case_t; //高温电池箱号

unsigned int Battery_temp[24]; //电池单体温度
unsigned int Battery_voltage[96]; //电池单体电压

unsigned int DCAC_W;
unsigned int DCAC_V;
unsigned int DCAC_U;
unsigned char Sanreqi_t; //散热器温度

unsigned char DCDC_Warn_code;//DCDC故障代码
unsigned char DCDC_Warn_code_double;//双向DCDC故障代码
unsigned char DCDC_Warn_code_oil;//油泵DCDC故障代码
unsigned char DCDC_Warn_code_gas;//气泵DCDC故障代码

unsigned char AC_Warn_code; //AC故障代码
DATA_BIT AC_KEY[2];
unsigned char Indoor_t; //室内温度
unsigned char Outdoor_t; //室外温度
unsigned char Set_t; //设定
unsigned char AC_req; //制冷请求
unsigned char AC_LIFE; //AC生命



/**************************************************/
unsigned char battle_t; //电池均温
unsigned char battle_t_warn; //电池过温报警
unsigned char battle_jueyuan_warn; //绝缘过低报警
unsigned char battle_higtv1_warn; //高压电池1故障
unsigned char battle_higtv2_warn; //高压电池2故障
unsigned char moto_t_warn; //电机过温
unsigned char moto_ready; //ready信号
unsigned char xudc; //蓄电池异常
unsigned char moto_warn; //电机故障

unsigned char BMS_offline_warn; //电池不在线
unsigned char MCU_offline_warn; //电机不在线
unsigned char TCU_offline_warn; //变速箱不在线
unsigned char Engine_offline_warn; //发动机不在线
unsigned char Engine_wait; //发动机怠速
unsigned char EV; //模式
unsigned char Signal_charge; //充电信号

unsigned char mil_lamp_request; //黄色三级报警
unsigned char fail_mode; //文字报警
unsigned char mil_buzz_request; //蜂鸣器响
unsigned long hcu_spn; //HCU故障码
unsigned char hcu_fmi;

unsigned char Eng_static_test; //发动机稳态转速测试
unsigned char tcu_start_allow; //发动机运行启动

unsigned char Lamp_status_YELLOW; //变速箱黄灯状态
unsigned char Lamp_status_RED; //变速箱红灯状态

unsigned long ccu_spn; //CCU故障码
unsigned char ccu_fmi;

unsigned long ecu_spn; //ECU故障码
unsigned char ecu_fmi;

unsigned int ENG_start_req; //仪表控制启动
unsigned long mot_work_time; //电机工作累积时间
unsigned char mot_work_percent; //电机工作时间比
unsigned char DCDC_ctrl; //DCDC状态
unsigned char hcu_starter_forbid; //起动机工作
unsigned char aircompress_enable; //压缩机
unsigned char Speed_lim_mode; //限速模式

unsigned char water_level; //水位

unsigned char Wait_start; //等待启动
unsigned char Maintain_warn; //维护报警
unsigned char Stop_warn; //发动机停机报警
unsigned char Engine_warn; //发动机故障

void __attribute__((__interrupt__, auto_psv)) _C2Interrupt(void) {
    unsigned char i=0; 
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
            //for(j=0;j<20;j++)
            case 0x0C03A1A7://仪表报文MET_C_1
                Vcan_count=0;
                moto_voltage = (unsigned char) msg.data[0]+((unsigned int) msg.data[1] << 8);
                moto_current = (unsigned char) msg.data[2]+((unsigned int) msg.data[3] << 8);               
                Generator = (unsigned char) msg.data[4]+((unsigned int) msg.data[5] << 8);//发电机电流
                moto_speed = (unsigned char) msg.data[6]+((unsigned int) msg.data[7] << 8);
                break;

            case 0x0C04A1A7://仪表报文MET_C_2
                Vcan_count=0;
                Motor_Temperature = msg.data[0];
                Inverter_t = msg.data[1];
                Generator_Temperature = msg.data[2];
                Generator_Inverter_t = msg.data[3];
                CAN_KEY[0].byte = msg.data[4];
                CAN_KEY[1].byte = msg.data[5];
                Moto_status = msg.data[6]&0x03;
                Generator_status = (msg.data[6]>>2)&0x03;
                Moto_status = (msg.data[6]>>4)&0x03;
                Car_mode = msg.data[7];
                break;

            case 0x0C05A1A7://仪表报文MET_C_3
                Vcan_count=0;
                Engine_Speed = (unsigned char) msg.data[0]+((unsigned int) msg.data[1] << 8);
                water_temp = msg.data[2];
                Engine_Fuhe = msg.data[3];
                Niaosu = msg.data[4];
                Accelerator = msg.data[5]; //目标油门踏板
                Accelerator_Shiji = msg.data[6]; //油门踏板实际
                Car_LIFE = msg.data[7]; //机油压力
                break;

            case 0x0C06A1A7://仪表报文MET_C_4  
                Vcan_count=0;
                Speed_percent = msg.data[0];
                Brake_percent = msg.data[1];
                Engine_oil_press = msg.data[2];
                ambient_air_temperature = msg.data[3];
                Engine_oil_consume = ((unsigned char) msg.data[4]
                                     +((unsigned int) msg.data[5] << 8)
                                     +((unsigned long) msg.data[6] << 16)
                                     +((unsigned long) msg.data[7] << 24));
                break;

            case 0x0C07A1A7://仪表报文MET_C_5  
                Vcan_count=0;
                Parameter1 = msg.data[0];
                Parameter2 = msg.data[1];
                Parameter3 = msg.data[2];
                Parameter4 = msg.data[3];
                Parameter5 = msg.data[4];
                Parameter6 = msg.data[5];
                Parameter7 = msg.data[6];
                Parameter8 = msg.data[7];
                /*
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
                Kt = (msg.data[3] >> 1)&0x01;
                Brake_Pedal = msg.data[4]&0x01;
                Speed_percent = msg.data[5];
                Brake_percent = msg.data[6];
                */
                break;

            case 0x0C08A1A7://仪表报文MET_C_6  
                Vcan_count=0;
                Program = ((unsigned char) msg.data[0]
                        +((unsigned int) msg.data[1] << 8)
                        +((unsigned long) msg.data[2] << 16));
                Engine_oil_consume_instant = msg.data[3];
                DCDC_Warn_code_double=msg.data[4];
                DCDC_Warn_code=msg.data[5];
                DCDC_Warn_code_oil=msg.data[6];
                DCDC_Warn_code_gas=msg.data[7];
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
                Battery_single_H = ((unsigned char) msg.data[0]
                        +((unsigned int) msg.data[1] << 8))&0xFFF;
                Battery_case_H = ((unsigned char) msg.data[1]>>4)&0x0F;
                Battery_number_H = msg.data[2];
                BMS_T_H=msg.data[3];
                Battery_number_t=msg.data[4]&0x0F;
                Battery_case_t=(msg.data[4]>>4)&0x0F;
                Battery_single_L = ((unsigned char) msg.data[5]
                        +((unsigned int) msg.data[6] << 8))&0xFFF;
                Battery_case_L = ((unsigned char) msg.data[6]>>4)&0x0F;
                Battery_number_L = msg.data[7];
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
                Battery_voltage[0] = ((unsigned char) msg.data[0]
                        +((unsigned int) msg.data[1] << 8))&0xFFF;
                Battery_voltage[1] = ((unsigned char) msg.data[2]
                        +((unsigned int) msg.data[3] << 8))&0xFFF;
                Battery_voltage[2] = ((unsigned char) msg.data[4]
                        +((unsigned int) msg.data[5] << 8))&0xFFF;
                Battery_voltage[3] = ((unsigned char) msg.data[6]
                        +((unsigned int) msg.data[7] << 8))&0xFFF;
                break;

            case 0x180128F3://BMS1_S_4_2
                Bcan_count=0;
                Battery_voltage[4] = ((unsigned char) msg.data[0]
                        +((unsigned int) msg.data[1] << 8))&0xFFF;
                Battery_voltage[5] = ((unsigned char) msg.data[2]
                        +((unsigned int) msg.data[3] << 8))&0xFFF;
                Battery_voltage[6] = ((unsigned char) msg.data[4]
                        +((unsigned int) msg.data[5] << 8))&0xFFF;
                Battery_voltage[7] = ((unsigned char) msg.data[6]
                        +((unsigned int) msg.data[7] << 8))&0xFFF;
                break;

            case 0x180228F3://BMS1_S_4_3
                Bcan_count=0;
                Battery_voltage[8] = ((unsigned char) msg.data[0]
                        +((unsigned int) msg.data[1] << 8))&0xFFF;
                Battery_voltage[9] = ((unsigned char) msg.data[2]
                        +((unsigned int) msg.data[3] << 8))&0xFFF;
                Battery_voltage[10] = ((unsigned char) msg.data[4]
                        +((unsigned int) msg.data[5] << 8))&0xFFF;
                Battery_voltage[11] = ((unsigned char) msg.data[6]
                        +((unsigned int) msg.data[7] << 8))&0xFFF;
                break;

            case 0x180328F3://BMS1_S_4_4
                Battery_voltage[12] = ((unsigned char) msg.data[0]
                        +((unsigned int) msg.data[1] << 8))&0xFFF;
                Battery_voltage[13] = ((unsigned char) msg.data[2]
                        +((unsigned int) msg.data[3] << 8))&0xFFF;
                Battery_voltage[14] = ((unsigned char) msg.data[4]
                        +((unsigned int) msg.data[5] << 8))&0xFFF;
                Battery_voltage[15] = ((unsigned char) msg.data[6]
                        +((unsigned int) msg.data[7] << 8))&0xFFF;
                break;

            case 0x180428F3://BMS1_S_4_5
                Bcan_count=0;
                Battery_voltage[16] = ((unsigned char) msg.data[0]
                        +((unsigned int) msg.data[1] << 8))&0xFFF;
                Battery_voltage[17] = ((unsigned char) msg.data[2]
                        +((unsigned int) msg.data[3] << 8))&0xFFF;
                Battery_voltage[18] = ((unsigned char) msg.data[4]
                        +((unsigned int) msg.data[5] << 8))&0xFFF;
                Battery_voltage[19] = ((unsigned char) msg.data[6]
                        +((unsigned int) msg.data[7] << 8))&0xFFF;
                break;

            case 0x180028F4://BMS1_S_5_1
                Bcan_count=0;
                Battery_temp[0] = msg.data[1];
                Battery_temp[1] = msg.data[3];
                Battery_temp[2] = msg.data[5];
                Battery_temp[3] = msg.data[7];
                break;

            case 0x180128F4://BMS1_S_5_2
                Bcan_count=0;
                Battery_temp[4] = msg.data[1];
                Battery_temp[5] = msg.data[3];
                Battery_temp[6] = msg.data[5];
                Battery_temp[7] = msg.data[7];
                break;

            case 0x180228F4://BMS1_S_5_3
                Bcan_count=0;
                Battery_temp[8] = msg.data[1];
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
                //DCAC_Warn_code = msg.data[7];
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

                /*   
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
                            m_can.flag = 1; //CAN接收开始标记
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
                            m_can.flag = 0; //已完成接收
                        }
                    }

                    break;
                    //////////////////////////////////////////////////////////////////////////////////            
                case 0x0CF00203://ETC1 TCU
                    Speed_rmp = ((unsigned char) msg.data[1]
                            +((unsigned int) msg.data[2] << 8))*0.125; //输出轴转速
                    Eng_static_test = (msg.data[7] >> 4)&0x03; //发动机稳态转速测试
                    tcu_start_allow = (msg.data[7] >> 6)&0x03; //发动机运行启动
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
                            n_can.flag = 1; //CAN接收开始标记
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
                            n_can.flag = 0; //已完成接收
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

                case 0x18FEEE00://水温
                    water_temp = (unsigned char) msg.data[0];
                    break;

                case 0x18FEEF00://水位和机油压力
                    Engine_oil_press = (unsigned int) (msg.data[3]*4);
                    water_level = (unsigned char) (msg.data[7]*0.4);
                    break;

                case 0x18FEE400://发动机等待启动
                    Wait_start = (unsigned char) (msg.data[3]&0x03);
                    //water_level=(unsigned char)(msg.data[7]*0.4);  
                    break;

                case 0x18FEF600: //周围环境条件 id==0x18FEF600
                    //barometric_pressure = msg.data[1]; //增压压力 0.5Kpa
                    ambient_air_temperature = msg.data[2]; //周围空气温度
                    //air_pressure = msg.data[3]; //进气压力 0.5Kpa
                    break;
                 */
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

    if (cnt0 >= 4) {//50ms
        cnt0 = 0;              
        BCAN_send_mile();
        BCAN_SendCtl();
        if (M_ON_flag && wake_up3) {//wake_up3置0时，M_ON不会立马置0，因为存在消抖延时
            LED_Logic();
            LED_Out();
            SYSTME_Logic();
        }
        F50ms = 1;
    } else cnt0++;

    if (cnt1 >= 9) {//100ms
        cnt1 = 0;
        F100ms= 1;    
        PCAN_CCVS();
        //计算累计里程
        if (pSpeed > 0) {//车速大于0时才累计
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

        if (cnt4 >= 9) {//1s
            cnt4 = 0;
            F1000ms = 1;
            FLASH_1s = !FLASH_1s;
            PCAN_send_mile();
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
    
    if (IN10 && IN6 && (IN7 || IN8) && IN9) { //后雾灯开关是常开开关，消抖
        if (cnt5 > 10) rLED_flag = 1;
        else cnt5++;       
    }else if((IN6 && (IN7 || IN8) && IN9)==0){
        rLED_flag = 0;
        cnt5=0;
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


