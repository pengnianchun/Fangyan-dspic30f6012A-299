/*
 * File:   APP_LED.c
 * Author: pnc
 *
 * Created on 2017年7月28日, 下午4:49
 */

#include "APP_System.h"

void LED_Logic(void) {
    //LED1 = IN4;   //前门开指示

    //LED2 = IN3;   //中门开指示
    //LED3 = (VCU_Gear==0); //空挡指示

    //左转向
    if ((IN23) || WAKE_Danger)
        LED4 = FLASH;
    else LED4 = 0;

    //LED5 = (VCU_Gear==1); //前进挡指示

    //充电指示
    LED6 = (Charging == 2);
    //充电插头连接
    LED7 = ChargeGun;
    //右转向灯
    if ((IN24) || WAKE_Danger)
        LED8 = FLASH;
    else LED8 = 0;

    //气压1低信号
    LED9 = IN20;

    LED10 = 1; //总电源指示   

    //if (ADV[4] < 2500) //气压2
    //    LED11 = 1;
    //else
    //    LED11 = 0;

    LED12 = (BMS_SOC < 10);

    LED13 = (MCU_Control_High_Temp || MCU_Control_Fault); //电机故障

    LED14 = (BAT_High_Temp 
            || BAT_Low_Temp
            || BAT_Voltage_Diff 
            || BAT_OverCurrent
            || BMS_Fault
            ); //动力电池系统故障

    LED15 = IN28; //小灯

    LED16 = (BAT24V_count >= BAT24_TIME); //蓄电池电压低

    LED17 = (IN19); //远光灯

    LED18 = (IN22); //手刹

    LED19 = (0); //前雾灯

    LED20 = (0); //后雾灯

    LED21 = (IN13); //倒车灯

    LED22 = IN18; //近光灯

    //LED23 = (IN14 && IN31 && M_ON);//缓速器

    LED24 = (IN21); //刹车指示


    //蜂鸣器 为0时响，为1时不响   
    if ((SPEED > 69))
        BUZZ = 0;
    else if (0)
        BUZZ = !FLASH_1s;
    else if (0)
        BUZZ = !FLASH;
    else BUZZ = 1;

    //背光 小灯开关闭合 
    if (LED15) {
        OC1RS = e_backlight;
    } else {
        OC1RS = 0;
    }

    //PO1 = (SPEED > 5);
    //PO2 = !(M_ON && VCU_Gear == 1);
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