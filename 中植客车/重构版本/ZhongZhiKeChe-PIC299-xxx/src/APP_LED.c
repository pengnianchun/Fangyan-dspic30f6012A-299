/*
 * File:   APP_LED.c
 * Author: pnc
 *
 * Created on 2017年7月28日, 下午4:49
 */

#include "APP_System.h"

void LED_Logic(void) {
    LED1 = IN4; //前门开指示

    LED2 = IN3; //中门开指示
    
    //LED3 = (DMC_Gear==0 || DMC_Gear==3); //空挡指示

    //左转向
    if (IN1 || wake_up1)
        LED4 = FLASH;
    else LED4 = 0;

    //LED5 = (DMC_Gear==1); //前进挡指示
    
    LED6 = BMS_Charge_Status.bit2; //充电状态

    LED7 = BMS_Charge_Status.bit1; //充电枪插入
    //右转向灯
    if (IN5 || wake_up1)
        LED8 = FLASH;
    else LED8 = 0;

    LED9 = IN11; //气压1低信号

    LED10 = 1; //总电源指示   

    LED11 = IN12; //气压2低信号

    LED12 = (BMS_Warn_Message[0].bit5 //SOC报警
            || BMS_Warn_Message[0].bit8
            || BMS_Warn_Message[1].bit1); 

    LED13 = (MCU_Warn_Number > 0 && MCU_Warn_Number < 252); //电机故障

    LED14 = (BMS_Fault_Level == 1      //动力电池系统故障
            || BMS_Fault_Level == 2
            || BMS_Fault_Level == 3);
           /*((((BMS_Status_Flag1 & 0x03) == 1) || ((BMS_Status_Flag1 & 0x03) == 2))
            || (((BMS_Status_Flag1 >> 2) & 0x03) == 1) || (((BMS_Status_Flag1 >> 2) & 0x03) == 2)
            || (((BMS_Status_Flag1 >> 4) & 0x03) == 1) || (((BMS_Status_Flag1 >> 4) & 0x03) == 2)
            || (((BMS_Status_Flag1 >> 6) & 0x03) == 1) || (((BMS_Status_Flag1 >> 6) & 0x03) == 2)
            || ((BMS_Status_Flag2 & 0x03) == 1) || ((BMS_Status_Flag2 & 0x03) == 2)
            || (((BMS_Status_Flag2 >> 2) & 0x03) == 1) || (((BMS_Status_Flag2 >> 2) & 0x03) == 2)
            || (((BMS_Status_Flag2 >> 4) & 0x03) == 1) || (((BMS_Status_Flag2 >> 4) & 0x03) == 2)
            || (((BMS_Status_Flag2 >> 6) & 0x03) == 1) || (((BMS_Status_Flag2 >> 6) & 0x03) == 2))
           */
    LED15 = IN6; //小灯

    LED16 = (BAT24V_count == BAT24_TIME); //蓄电池电压低

    LED17 = (IN7 && !IN8); //远光灯

    LED18 = (IN26); //手刹

    LED19 = (IN9 && IN6); //前雾灯

    LED20 = (IN9 && IN10 && IN6); //后雾灯

    //LED21 = (DMC_Gear==2 /*&& M_ON*/);//倒车灯

    LED22 = (IN8 && IN6 && IN7); //近光灯

    //LED23 = (IN14 && IN31 && M_ON);//缓速器

    LED24 = (fKL6); //刹车指示


    //蜂鸣器 为0时响，为1时不响   
    if (SPEED > 69)
        BUZZ = 0;
    else if (LED13 || LED14)
        BUZZ = !FLASH_1s;
    else if (IN1 || IN5 || wake_up1)
        BUZZ = !FLASH;
    else BUZZ = 1;
    
    //背光 小灯开关闭合 
    if (IN6) {
        OC1RS = e_backlight;
    } else {
        OC1RS = 0;
    }
    
    PO1 = 0;
    PO2 = 0;
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