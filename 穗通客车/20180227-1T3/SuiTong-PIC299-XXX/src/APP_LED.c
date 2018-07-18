/*
 * File:   APP_LED.c
 * Author: pnc
 *
 * Created on 2017年7月28日, 下午4:49
 */

#include "APP_System.h"

void LED_Logic(void) {     
    //前门开指示 //油量报警
    LED1 = fKL15;

    //中门开指示 空挡指示
    LED2 = mKH1;   
    
    //排气制动指示
    //LED3 = (VCU_Gear==0); 

    //Interval_Status(IN1 || IN5 || WAKE_Danger,Flash_400ms);//注册400ms闪烁有效状态
    //左转向
    if ((IN1 && WAKE_ACC) || WAKE_Danger)
        LED4 = FLASH;
        //LED4 = Flash[Flash_400ms].Status;
    else LED4 = 0;
  
    //LED5 = (VCU_Gear==1); //前进挡指示 预热指示

    //充电指示  机油压力报警
    LED6 = (CAN_0x1818D0F3.BMSFlag3.bit7);   
    
    //充电插头连接  水温高报警
    LED7 = (CAN_0x1818D0F3.BMSFlag3.bit6);
    
    //右转向灯
    if ((IN5 && WAKE_ACC) || WAKE_Danger)
        LED8 = FLASH;
        //LED8 = Flash[Flash_400ms].Status;
    else LED8 = 0;

    if (rKL10)//气压1低信号 0.55MP报警
        LED9 = 1;
    else
        LED9 = 0;

    LED10 = 1; //总电源指示   

    if (rKL12) //气压2 0.55MP报警
        LED11 = 1;
    else
        LED11 = 0;

    //SOC报警 发动机故障报警
    LED12 = (CAN_0x181CD0F3.BMSFlag4.bit2 || CAN_0x1818D0F3.BMSFlag1.bit3 || CAN_0x1818D0F3.BMSFlag1.bit4);

    //电机故障 油中积水报警
    LED13 = (CAN_0x0C04A1A7.FaultLevel > 0);

    //动力电池系统故障 OBD指示
    LED14 = (CAN_0x1819D0F3.Warn_level > 0);

    LED15 = (IN6 && WAKE_ACC); //小灯 发动机诊断报警指示

    LED16 = (BAT24V_count >= BAT24_TIME); //蓄电池电压低 充电指示

    LED17 = (WAKE_ACC && IN7); //远光灯 远光灯报警

    LED18 = (rKL5); //手刹 驻车制动报警

    LED19 = (WAKE_ACC && IN9); //前雾灯 前雾灯报警

    LED20 = (LED19 && IN10); //后雾灯 后雾灯报警

    LED21 = (CAN_0x0C06A1A7.VCUGearR && WAKE_ON);//倒车灯 倒车灯

    LED22 = (WAKE_ACC && IN8); //近光灯 近光灯报警

    //LED23 = (IN14 && IN31 && M_ON);//缓速器 缓速器报警

    LED24 =  (WAKE_ACC && (CAN_0x0C05A1A7.E_Brake || rKL3)); //刹车指示 刹车指示


    //蜂鸣器 为0时响，为1时不响   
    if (mKL2)                               //下车门铃
        BUZZ = 0;
    else if ((rKL11 && SPEED > 5)           //后舱门未关
            || (LED1  && SPEED > 5)         //前门未关
            || (LED2   && SPEED > 5)        //后门未关
            )
        BUZZ = !FLASH_1s;
    else if (LED4                           //左转向
            || LED8                         //右转向
            || LED9                         //气压1报警
            || LED11                        //气压2报警
            || !rKL2                        //左前摩擦片
            || !rKL4                        //左后摩擦片
            || !rKL6                        //右前摩擦片
            || !rKL8                        //右后摩擦片
            //|| (mKL10 && SPEED > 5)       //安全带
            //|| (BMS_ChargeGun_Link == 1)//正在充电，禁止行车         
            || (CAN_0x0C06A1A7.VCUOverSpeed)//超速报警
            )
        BUZZ = !FLASH;
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