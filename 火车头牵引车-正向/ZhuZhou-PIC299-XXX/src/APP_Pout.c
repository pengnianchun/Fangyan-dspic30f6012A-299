/*
 * File:   APP_Pout.c
 * Author: pnc
 *
 * Created on 2017年7月28日, 下午4:53
 */


#include "APP_System.h"

void SYSTME_Logic(void) {
    F_PO1 = (SPEED >= 5);                  //门控电源
    F_PO2 = (WAKE_ACC || WAKE_ON);         //制动踏板电源
    F_PO3 = (WAKE_ON);                     //下客门铃电源
    //F_PO4 = LED4;                        //左前雾灯
    F_PO5 = (WAKE_ON);                     //仓温报警电源
    F_PO6 = LED20;                         //后雾灯
    F_PO7 = LED4;                          //左转向灯
    F_PO8 = (WAKE_ACC || WAKE_ON);         //电视电源
    F_PO9 = LED17;                         //左远关灯
    //F_PO10 = LED4; //右前雾灯
    F_PO11 = LED17;                        //左远关灯
    F_PO12 =(WAKE_ON);                     //集中润滑
    F_PO13 = LED22;                        //左近光灯
    F_PO14 = 0;              //倒车信号
    F_PO15 = LED22;                        //左近光灯

    M_PO1 = ((LED1 || LED2) && IN11);      //广告灯
    M_PO2 = (LED2 && LED15);               //中门踏步灯
    M_PO3 = (IN19);                        //电喇叭
    M_PO4 = ((WAKE_ACC || WAKE_ON) && LED24); //制动灯
    M_PO5 = (fKH1);                        //空调面板电源
    M_PO6 = (WAKE_ON);                     //电子风扇控制电源
    //M_PO7 = ((M_ON || wake_up2) && IN12); //滚动屏
    M_PO8 = LED8;                          //右转向灯
    M_PO9 = (LED1 && LED15);              //前门踏步灯
    M_PO10 = (WAKE_ON);                    //干燥器
    M_PO11 = LED19;                        //前雾灯
    M_PO12 = (WAKE_ON);                    //气压传感器电源
    M_PO13 = ((WAKE_ACC || WAKE_ON) && LED15); //小灯电源
    //M_PO14 = (VCU_Gear == 1); //倒车信号
    M_PO15 = LED4;                         //左转向灯

    R_PO1 = (rKL6); //制动灯
    R_PO2 = (IN19); //侧路牌
    R_PO3 = (LED20); //后雾灯       
    R_PO4 = (M_ON); //整车控制器电源
    R_PO5 = (FLASH && (IN1 || wake_up1)); //左转向灯
    R_PO6 = (M_ON); //气压传感器电源
    R_PO7 = (FLASH && (IN5 || wake_up1)); //右转向
    R_PO8 = IN22; //电喇叭
    R_PO9 = 0; //倒车灯1
    R_PO10 = IN22; //电喇叭
    R_PO11 = (mKH1 && IN6); //前门踏步灯
    R_PO12 = (IN6); //位置灯示高灯
    R_PO13 = (mKL15 && IN6); //中门踏步灯
    R_PO14 = 0; //倒车蜂鸣器
    R_PO15 = 0; //倒车灯2

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