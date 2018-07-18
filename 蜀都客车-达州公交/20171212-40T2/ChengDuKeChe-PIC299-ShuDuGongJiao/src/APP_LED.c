/*
 * File:   APP_LED.c
 * Author: pnc
 *
 * Created on 2017年7月28日, 下午4:49
 */

#include "APP_System.h"

void LED_Logic(void) {     
    //前门开指示 //油量报警
    LED1 = 0;

    //中门开指示 空挡指示
    LED2 = 0;   
    
    //排气制动指示
    //LED3 = (VCU_Gear==0); 

    //Interval_Status(IN1 || IN5 || WAKE_Danger,Flash_400ms);//注册400ms闪烁有效状态
    //左转向
    if ((IN1) || WAKE_Danger)
        LED4 = FLASH;
        //LED4 = Flash[Flash_400ms].Status;
    else LED4 = 0;
  
    //LED5 = (VCU_Gear==1); //前进挡指示 预热指示

    //充电指示  机油压力报警
    LED6 = ((Engine_oil_press < 110) && FLASH_1s && (CAN_0x18EF4BEF.Engine_wait == 0));   
    
    //充电插头连接  水温高报警
    LED7 = ((water_temp > 135) && FLASH_1s);
    
    //右转向灯
    if ((IN5) || WAKE_Danger)
        LED8 = FLASH;
        //LED8 = Flash[Flash_400ms].Status;
    else LED8 = 0;

    if (ADV[2] < 1875)//气压1低信号 0.55MP报警
        LED9 = 1;
    else
        LED9 = 0;

    LED10 = 1; //总电源指示   

    if (ADV[3] < 1875) //气压2 0.55MP报警
        LED11 = 1;
    else
        LED11 = 0;

    //SOC报警 发动机故障报警
    LED12 = 0;

    //电机故障 油中积水报警
    LED13 = 0;

    //动力电池系统故障 OBD指示
    LED14 = 0;

    LED15 = 0; //小灯 发动机诊断报警指示

    LED16 = (BAT24V_count >= BAT24_TIME); //蓄电池电压低 充电指示

    LED17 = (WAKE_ON && IN24); //远光灯 远光灯报警

    LED18 = (rKL5); //手刹 驻车制动报警

    LED19 = (WAKE_ON && IN29 && IN8); //前雾灯 前雾灯报警

    LED20 = (LED19 && IN9); //后雾灯 后雾灯报警

    LED21 = (Current_Gear == 124);//倒车灯 倒车灯

    LED22 = (WAKE_ON && IN6); //近光灯 近光灯报警

    //LED23 = (IN14 && IN31 && M_ON);//缓速器 缓速器报警

    LED24 =  (WAKE_ON && rKL2); //刹车指示 刹车指示


    //蜂鸣器 为0时响，为1时不响   
    if (0)
        BUZZ = 0;
    else if ((rKL10 && SPEED > 5)       //后舱门未关
            || (fKL15  && SPEED > 5)     //前门未关
            || (fKH1   && SPEED > 5)     //后门未关
            || IN30                     //辅助气压低
            || ((Engine_oil_press < 110) && (CAN_0x18EF4BEF.Engine_wait == 0))//机油压力报警 < 110
            || (water_temp > 135) //水温高报警>95
            || rKL9 //水位低
            || CAN_18FECAEF.MalfunctionIndicatorLampStatus == 1
            )
        BUZZ = !FLASH_1s;
    else if (LED4                       //左转向
            || LED8                     //右转向
            || LED9                     //气压1报警
            || LED11                    //气压2报警
            || !rKL11                   //左前摩擦片
            || !rKL6                    //左后摩擦片
            || !rKL12                   //右前摩擦片
            || !rKL8                    //右后摩擦片
            //|| (mKL10 && SPEED > 5)     //安全带
            //|| (BMS_ChargeGun_Link == 1)//正在充电，禁止行车
            || (SPEED > 69)             //超速报警
            )
        BUZZ = !FLASH;
    else BUZZ = 1;

    //背光 小灯开关闭合 
    if (IN29) {
        OC1RS = e_backlight;
    } else {
        OC1RS = 0;
    }

    //PO1 = !(SPEED > 5);
    //PO2 = !(M_ON && VCU_Gear == 1);
}

void LED_Danger(void){     //危险报警状态
    F_PO7 = FLASH;
    F_PO8 = FLASH;
    //M_PO8 = FLASH;
    //M_PO15 = FLASH;
    R_PO7 = FLASH;
    R_PO8 = FLASH;
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