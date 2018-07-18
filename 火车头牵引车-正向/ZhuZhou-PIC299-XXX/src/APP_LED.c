/*
 * File:   APP_LED.c
 * Author: pnc
 *
 * Created on 2017年7月28日, 下午4:49
 */

#include "APP_System.h"

void LED_Logic(void) {
    //前门开指示
    LED1 = IN8;   

    //中门开指示
    LED2 = IN9;   
    
    //空挡指示
    //LED3 = (VCU_Gear==0); 

    //左转向
    if ((IN4) || WAKE_Danger)
        LED4 = FLASH;
    else LED4 = 0;

    //前进挡指示
    //LED5 = (VCU_Gear==1); 

    //充电指示
    LED6 = (CAN_0x219.BMS_ChrgStsForTbox == 1);
    
    //充电插头连接
    LED7 = (CAN_0x219.BMS_ChrgConnIndLmp == 1);
    
    //右转向灯
    if ((IN3) || WAKE_Danger)
        LED8 = FLASH;
    else LED8 = 0;

    //气压1低信号 0.55MP报警
    if (IN22)
        LED9 = 1;
    else
        LED9 = 0;

    //总电源指示
    LED10 = 0;    

    //气压2 0.55MP报警
    if (IN23) 
        LED11 = 1;
    else
        LED11 = 0;

    //SOC报警
    LED12 = (CAN_0x213.BMS_SOCLwReqInd);

    //电机故障
    LED13 = (CAN_0x239.MCU_MtrSysFltSts > 0);

    //动力电池系统故障
    LED14 = (CAN_0x207.BMS_SysFltLvl > 0);

    //小灯
    LED15 = 0; 

    //蓄电池电压低
    LED16 = (BAT24V_count >= BAT24_TIME); 

    //远光灯
    LED17 = IN7; 

    //手刹
    LED18 = IN17; 

    //前雾灯
    LED19 = IN18; 

    //后雾灯
    LED20 = IN19; 

    //倒车灯
    //LED21 = (VCU_Gear==2 );

    //近光灯
    LED22 = IN2; 

    //缓速器
    LED23 = IN16;

    //刹车指示
    LED24 = IN24; 


    //蜂鸣器 为0时响，为1时不响   
    if (0)
        BUZZ = 0;
    else if (//VCU_OverSpeed              //超速报警
            //
            //|| mKL3                     //中门应急阀报警
            //|| mKL4                     //车内应急阀报警
            //|| IN13                     //下客门铃
            //|| (IM_FaultStatus == 0x55) //绝缘报警
            //|| (VCU_FaultCode > 0)      //整车故障报警
            //|| (!mKL12 && KT_SIGNAL)    //重力感应报警
            //|| fKL8                     //烟雾报警
             (IN10 && SPEED > 5)     //后舱门未关
            ||  IN11                    //前门应急阀报警
            || (LED1  && SPEED > 5)     //前门未关
            || (LED2  && SPEED > 5)     //后门未关
            || (CAN_0x7E0.VCU_BusVoltage_Alarm == 2) //电池电量不足
            )
        BUZZ = !FLASH_1s;
    else if (LED4                       //左转向
            || LED8                     //右转向
            || LED9                     //气压1报警
            || LED11                    //气压2报警
            //|| !mKL2                    //左前摩擦片
            //|| !mKL4                    //左后摩擦片
            //|| !mKL6                    //右前摩擦片
            //|| !mKL8                    //右后摩擦片
            //|| (mKL10 && SPEED > 5)     //安全带
            //|| (BMS_ChargeGun_Link == 1)//正在充电，禁止行车
            || (SPEED > 69)             //超速报警
            )
        BUZZ = !FLASH;
    else BUZZ = 1;

    //背光 小灯开关闭合 
    if (1) {
        OC1RS = e_backlight;
    } else {
        OC1RS = 0;
    }

    PO1 = !(SPEED > 5);
    PO2 = !(M_ON);
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