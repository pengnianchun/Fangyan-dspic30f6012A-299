/*
 * File:   APP_LED.c
 * Author: pnc
 *
 * Created on 2017年7月28日, 下午4:49
 */

#include "APP_System.h"

void LED_Logic(void) {
    LED1 = IN4;   //前门开指示

    LED2 = IN3;   //中门开指示
    //LED3 = (VCU_Gear==0); //空挡指示

    //左转向
    if ((IN17) || WAKE_Danger)
        LED4 = FLASH;
    else LED4 = 0;

    //LED5 = (VCU_Gear==1); //前进挡指示

    //充电指示
    LED6 = (BMS_Chargeing == 1);
    
    //充电插头连接
    LED7 = (BMS_ChargeGun_Link == 1);
    
    //右转向灯
    if ((IN18) || WAKE_Danger)
        LED8 = FLASH;
    else LED8 = 0;

    if (ADV[3] < 1875)//气压1低信号 0.55MP报警
        LED9 = 1;
    else
        LED9 = 0;

    LED10 = 1; //总电源指示   

    if (ADV[4] < 1875) //气压2 0.55MP报警
        LED11 = 1;
    else
        LED11 = 0;

    //SOC报警
    LED12 = (BMS_1LevelFault == 16
            || BMS_2LevelFault == 16
            || BMS_3LevelFault == 4
            || BMS_3LevelFault == 7
            );

    //电机故障
    LED13 = ((VCU_FaultCode >= 110 &&  VCU_FaultCode <= 139) 
            || (VCU_FaultCode >= 201 &&  VCU_FaultCode <= 209)
            );

    //动力电池系统故障
    LED14 = (BMS_Warn_Type == 1 
            || BMS_Warn_Type ==2
            || BMS_Warn_Type ==3
            );

    LED15 = IN33; //小灯

    LED16 = (BAT24V_count >= BAT24_TIME); //蓄电池电压低

    LED17 = ((M_ON || WAKE_ACC) && IN34 && !IN35); //远光灯

    LED18 = (mKL11); //手刹

    LED19 = ((M_ON || WAKE_ACC) && LED15 && IN36); //前雾灯

    LED20 = ((M_ON || WAKE_ACC) && LED19 && IN23); //后雾灯

    //LED21 = (VCU_Gear==2 );//倒车灯

    LED22 = ((M_ON || WAKE_ACC) && IN34 && IN35); //近光灯

    //LED23 = (IN14 && IN31 && M_ON);//缓速器

    LED24 =  ((M_ON || WAKE_ACC) && IN20); //刹车指示


    //蜂鸣器 为0时响，为1时不响   
    if (0)
        BUZZ = 0;
    else if (VCU_OverSpeed              //超速报警
            || mKL1                     //前门应急阀报警
            || mKL3                     //中门应急阀报警
            //|| mKL4                     //车内应急阀报警
            //|| IN13                     //下客门铃
            || (IM_FaultStatus == 0x55) //绝缘报警
            || (VCU_FaultCode > 0)      //整车故障报警
            || (!mKL12 && KT_SIGNAL)    //重力感应报警
            || fKL8                     //烟雾报警
            || (fKL12 && SPEED > 5)     //后舱门未关
            || (LED1  && SPEED > 5)     //前门未关
            || (LED2  && SPEED > 5)     //后门未关
            )
        BUZZ = !FLASH_1s;
    else if (LED4                       //左转向
            || LED8                     //右转向
            || LED9                     //气压1报警
            || LED11                    //气压2报警
            || !mKL2                    //左前摩擦片
            || !mKL4                    //左后摩擦片
            || !mKL6                    //右前摩擦片
            || !mKL8                    //右后摩擦片
            || (mKL10 && SPEED > 5)     //安全带
            || (BMS_ChargeGun_Link == 1)//正在充电，禁止行车
            || (SPEED > 69)             //超速报警
            )
        BUZZ = !FLASH;
    else BUZZ = 1;

    //背光 小灯开关闭合 
    if (LED15) {
        OC1RS = e_backlight;
    } else {
        OC1RS = 0;
    }

    PO1 = !(SPEED > 5);
    PO2 = !(M_ON && VCU_Gear == 1);
}

void LED_Danger(void){     //危险报警状态
    //F_PO6 = FLASH;
    F_PO7 = FLASH;
    M_PO8 = FLASH;
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