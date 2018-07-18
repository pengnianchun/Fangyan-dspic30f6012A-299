/*
 * File:   APP_LED.c
 * Author: pnc
 *
 * Created on 2017年7月28日, 下午4:49
 */

#include "APP_System.h"

void LED_Logic(void) {     
    //前门开指示 //油量报警
    LED1 = mKH1;

    //中门开指示 空挡指示
    LED2 = fKH1;   
    
    //排气制动指示
    LED3 = 0; 

    //Interval_Status(IN1 || IN5 || WAKE_Danger,Flash_400ms);//注册400ms闪烁有效状态
    //左转向
    if (IN1 || WAKE_Danger)
        LED4 = FLASH;
        //LED4 = Flash[Flash_400ms].Status;
    else LED4 = 0;
  
    LED5 = 0; //前进挡指示 预热指示

    //充电指示  机油压力报警
    LED6 = (CAN_0x08019F80.Notice2.bit4);   
    
    //充电插头连接  水温高报警
    LED7 = (CAN_0x08019F80.Notice2.bit3 || WAKE_Charge);
    
    //右转向灯
    if (IN5 || WAKE_Danger)
        LED8 = FLASH;
        //LED8 = Flash[Flash_400ms].Status;
    else LED8 = 0;

    if (ADV[3] < 2500)//气压1低信号 0.55MP报警
        LED9 = 1;
    else
        LED9 = 0;

    LED10 = 1; //总电源指示   

    if (ADV[4] < 2500) //气压2 0.55MP报警
        LED11 = 1;
    else
        LED11 = 0;

    //SOC报警 发动机故障报警
    LED12 = (CAN_0x08F8189E.SOCFaultStatus > 0);

    //电机故障 油中积水报警
    LED13 = (0);

    //动力电池系统故障 OBD指示
    LED14 = (CAN_0x08019F80.Notice2.bit1);

    LED15 = (IN6); //小灯 发动机诊断报警指示

    LED16 = (BAT24V_count >= BAT24_TIME); //蓄电池电压低 充电指示

    LED17 = (IN7); //远光灯 远光灯报警

    LED18 = (rKL8); //手刹 驻车制动报警

    LED19 = (LED15 && IN9); //前雾灯 前雾灯报警

    LED20 = ((LED19 || LED17 || LED22) && IN10); //后雾灯 后雾灯报警

    LED21 = (CAN_0x08019F80.Gear == 1);//倒车灯 倒车灯

    LED22 = (IN8); //近光灯 近光灯报警

    LED23 = 0;//缓速器 缓速器报警

    LED24 =  (fKL6); //刹车指示 刹车指示


    Interval_Status((CAN_0x10F007E8.Lane_Depature_Left == 1) || (CAN_0x10F007E8.Lane_Depature_Right == 1), Flash_100ms);
    Interval_Status(CAN_0x10F007E8.warning, Flash_200ms);
    //蜂鸣器 为0时响，为1时不响   
    if (fKL1) //下车门铃
        BUZZ = 0;
    else if ((rKL11 && SPEED > 5) //后舱门未关
            || (LED1 && SPEED > 5) //前门未关
            || (LED2 && SPEED > 5) //后门未关
            )
        BUZZ = !FLASH_1s;
    else if (IN1     //左转向
            || IN4   //右转向
            || WAKE_Danger //危险报警
            || LED9  //气压1报警
            || LED11 //气压2报警
            || !fKL2 //左前摩擦片
            || !fKL4 //左后摩擦片
            || (IN24 && SPEED > 5) //安全带
            //|| (LED7)                     //正在充电，禁止行车   
            || (IN17 && !LED18) //重力感应报警
            || (SPEED > 69)//超速报警
            )
        BUZZ = !FLASH;
    else if (CAN_0x10F007E8.warning)
        BUZZ = !Flash[Flash_200ms].Status;
    else if ((CAN_0x10F007E8.Lane_Depature_Left == 1) || (CAN_0x10F007E8.Lane_Depature_Right == 1))
        BUZZ = !Flash[Flash_100ms].Status;
    else
        BUZZ = 1;

    //背光 小灯开关闭合 
    if (LED15) {
        OC1RS = e_backlight;
    } else {
        OC1RS = 0;
    }

    //硬件主动控制，赋值0，打开输出。硬件被动控制，赋值1，打开输出
    PO1 = (SPEED < 5);
    PO2 = (SPEED < 5);
}

void LED_Danger(void){     //危险报警状态
    F_PO6 = FLASH;
    F_PO7 = FLASH;
    M_PO2 = FLASH;
    M_PO15 = FLASH;
    R_PO5 = FLASH;
    R_PO7 = FLASH;
    LED4 = FLASH; //左转向灯
    LED8 = FLASH; //右转向灯 
    BUZZ = !FLASH;
}

void LED_Clear(void){      //LED全部关闭
    alarm_led[0].byte = 0xff;
    alarm_led[1].byte = 0x00;
    alarm_led[2].byte = 0x00;
    alarm_led[3].byte = 0x00;
}

void LED_Enable(void){
    alarm_led[0].byte = 0xC0; //蜂鸣器开启
    alarm_led[1].byte = 0xff;
    alarm_led[2].byte = 0xff;
    alarm_led[3].byte = 0xff;
}

void LED_Test(void) { //将所有的LED灯点亮。只为测试使用
    static unsigned char led_test_count = 0,tq = 0;
    unsigned char led_test[26][3] = {
        {0x00, 0x00, 0x02}, //驻车制动
        {0x00, 0x00, 0x08}, //后雾灯 
        {0x00, 0x00, 0x20}, //近光灯
        {0x00, 0x00, 0x40}, //缓速器
        {0x01, 0x00, 0x00}, //前门开
        {0x02, 0x00, 0x00}, //后门开  
        {0x04, 0x00, 0x00}, //空档  
        {0x00, 0x00, 0x04}, //前雾灯

        {0x00, 0x00, 0x10}, //倒车灯
        {0x00, 0x00, 0x80}, //刹车灯 
        {0x00, 0x00, 0x01}, //远光灯
        {0x08, 0x00, 0x00}, //左转向灯
        {0x80, 0x00, 0x00}, //右转向灯
        {0x10, 0x00, 0x00}, //D
        {0x20, 0x00, 0x00}, //充电指示
        {0x40, 0x00, 0x00}, //充电插头

        {0x00, 0x01, 0x00}, //气压1
        {0x00, 0x02, 0x00}, //电源指示
        {0x00, 0x08, 0x00}, //SOC
        {0x00, 0x40, 0x00}, //小灯
        {0x00, 0x04, 0x00}, //气压2
        {0x00, 0x10, 0x00}, //电机故障
        {0x00, 0x20, 0x00}, //电池故障
        {0x00, 0x80, 0x00}, //电池

        {0x00, 0x00, 0x00}, //
        {0xff, 0xff, 0xff}};

    if (led_test_count < 26) {
        alarm_led[1].byte = led_test[led_test_count][0];
        alarm_led[2].byte = led_test[led_test_count][1];
        alarm_led[3].byte = led_test[led_test_count][2];
    } else {
        if (FLASH) {
            alarm_led[1].byte = 0xff;
            alarm_led[2].byte = 0xff;
            alarm_led[3].byte = 0xff;
        } else {
            alarm_led[1].byte = 0x00;
            alarm_led[2].byte = 0x00;
            alarm_led[3].byte = 0x00;
        }
    }
    if (tq >= 19) {
        tq = 0;
        if (led_test_count > 44)led_test_count = 0;
        led_test_count++;
    } else {
        tq++;
    }

    OC1RS = e_backlight;
    if (led_test_count > 43 || Fversion == 100)BUZZ = 0; //蜂鸣器 
    else BUZZ = 1; //关闭蜂鸣器 

}