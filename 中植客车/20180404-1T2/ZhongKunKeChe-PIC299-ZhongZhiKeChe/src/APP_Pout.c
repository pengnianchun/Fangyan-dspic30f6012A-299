/*
 * File:   APP_Pout.c
 * Author: pnc
 *
 * Created on 2017年7月28日, 下午4:53
 */


#include "APP_System.h"

void SYSTME_Logic(void) {
    // F_PO1 = (IN16 && M_ON); //雨刮快档
    // F_PO2 = (IN14 && M_ON); //雨刮慢档
    // F_PO3 = (IN21 && M_ON); //喷水电机
    F_PO4 = (LED15 && IN9);                     //左前雾灯
    F_PO5 = (IN28 && wake_up2);                 //电控排污阀
    F_PO6 = (FLASH && (IN5 || wake_up1));       //右转向灯
    F_PO7 = (FLASH && (IN1 || wake_up1));       //左转向灯
    Interval_Status(CAN_0x18EF4EEF.MCU_RPM > 20300,Flash_3s_10min);
    F_PO8 = Flash[Flash_3s_10min].Status; //冷凝器 
    F_PO9 = LED17;                              //左远关灯
    F_PO10 = (LED15 && IN9);                    //右前雾灯
    F_PO11 = LED17;                             //右远光灯
    F_PO12 = fKL8;                              //日行灯 
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
    M_PO13 = (CAN_0x18EF4AEF.EV_Gear == 13);    //倒车灯电源
    M_PO14 = (SPEED < 3);                       //门泵电源
    M_PO15 = (wake_up2 && IN23);                //厢灯1
    M_PO16 = 0;                                 //励磁电流

    /*R_PO1 = (0); //制动灯
    R_PO2 = LED15; //侧路牌
    R_PO3 = WAKE_ON; //后雾灯       
    R_PO4 = (LED15 && mKH1); //整车控制器电源
    R_PO5 = (LED15 && mKL12); //左转向灯
    R_PO6 = LED4; //气压传感器电源
    R_PO7 = LED8; //右转向
    R_PO8 = LED20; //电喇叭
    R_PO9 = 0; //倒车灯1
    R_PO10 = WAKE_ON; //电喇叭
    R_PO11 = LED24; //前门踏步灯
    R_PO12 = (WAKE_ACC && IN22); //位置灯示高灯
    R_PO13 = (WAKE_ACC && IN23); //中门踏步灯
    R_PO14 = (WAKE_ACC && IN24); //倒车蜂鸣器
    R_PO15 = WAKE_ON; //倒车灯2*/

}

void POUT_Clear(void){
    gCTL[0].byte = 0x00;
    gCTL[1].byte = 0x00;
    gCTL[2].byte = 0x00;
    gCTL[3].byte = 0x00;
    gCTL[4].byte = 0x00;
    gCTL[5].byte = 0x00;
    gCTL[6].byte = 0x00;
    gCTL[7].byte = 0x00;
}