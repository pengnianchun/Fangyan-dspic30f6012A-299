/*
 * File:   APP_LED.c
 * Author: pnc
 *
 * Created on 2017年7月28日, 下午4:49
 */

#include "APP_System.h"

void LED_Logic(void) {
    LED1 = mKL8;   //前门开指示

    LED2 = mKL10;   //中门开指示
    //LED3 = (VCU_Gear==0); //空挡指示

    //左转向
    if ((IN1) || WAKE_Danger)
        LED4 = FLASH;
    else LED4 = 0;

    //LED5 = (VCU_Gear==1); //前进挡指示

    //充电指示
    LED6 = (CAN_0x18EF4BEF.ChargeStatus == 1);
    
    //充电插头连接
    LED7 = (CAN_0x18EF4BEF.No27 == 1 || WAKE_Charge);
    
    //右转向灯
    if ((IN5) || WAKE_Danger)
        LED8 = FLASH;
    else LED8 = 0;

    if (ADV[3] < 2500)//气压1低信号 0.6MP报警
        LED9 = 1;
    else
        LED9 = 0;

    LED10 = 1; //总电源指示   

    if (ADV[4] < 2500) //气压2 0.6MP报警
        LED11 = 1;
    else
        LED11 = 0;

    //SOC报警
    LED12 = (CAN_0x18EF5AEF.No23 || CAN_0x18EF5AEF.No26 || CAN_0x18EF5AEF.No27);

    //电机故障
    LED13 = (CAN_0x18EF5AEF.No2 || CAN_0x18EF5AEF.No3);

    //动力电池系统故障
    LED14 = (CAN_0x18EF5AEF.No1 > 0);

    LED15 = (IN6); //小灯

    LED16 = (BAT24V_count >= BAT24_TIME); //蓄电池电压低

    LED17 = (IN4 && LED15 && IN7 && !IN8); //远光灯

    LED18 = (IN26); //手刹

    LED19 = (IN4 && LED15 && IN9); //前雾灯

    LED20 = (IN4 && LED15 && IN10); //后雾灯

    LED21 = (CAN_0x18EF4AEF.EV_Gear == 13); //倒车灯

    LED22 = (IN4 && LED15 && !IN7 && IN8); //近光灯

    //LED23 = (IN14 && IN31 && M_ON);//缓速器

    LED24 =  (IN29); //刹车指示


    //蜂鸣器 为0时响，为1时不响   
    /*if (mKL2)
        BUZZ = 0;
    else if ((mKH1 && SPEED > 5)       //后舱门未关
            || (LED1  && SPEED > 5)       //前门未关
            || (LED2  && SPEED > 5)       //后门未关
            )
        BUZZ = !FLASH_1s;
    else if (LED4                       //左转向
            || LED8                     //右转向
            || LED9                     //气压1报警
            || LED11                    //气压2报警
            || !fKL4                    //左前摩擦片
            //|| !fKL9                    //左后摩擦片
            || !fKL5                   //右前摩擦片
            //|| !fKL11                   //右后摩擦片
            //|| (mKL10 && SPEED > 5)     //安全带
            //|| (BMS_ChargeGun_Link == 3)//正在充电，禁止行车
            || (SPEED > 69)             //超速报警
            )
        BUZZ = !FLASH;
    else BUZZ = 1;*/

    //背光 小灯开关闭合 
    if (LED15) {
        OC1RS = e_backlight;
    } else {
        OC1RS = 0;
    }

    //PO1 = !(SPEED > 5);
    //PO2 = !(M_ON && VCU_Gear == 1);
}

void LED_Danger(void){     //危险报警状态
    F_PO6 = FLASH;
    F_PO7 = FLASH;
    M_PO6 = FLASH;
    M_PO7 = FLASH;
    R_PO6 = FLASH;
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