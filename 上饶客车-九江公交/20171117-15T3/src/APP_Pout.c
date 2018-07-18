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
    //F_PO14 = (VCU_Gear == 1);              //倒车信号
    F_PO15 = LED22;                        //左近光灯

    M_PO1 = LED15;      //小灯
    M_PO2 = (IN20 && (SPEED < 5));               //中门踏步灯
    M_PO3 = (IN28);                        //电喇叭
    M_PO4 = (IN27 && (SPEED < 5)); //制动灯
    M_PO5 = (IN26);                        //空调面板电源
    M_PO6 = LED4;                     //电子风扇控制电源
    M_PO7 = LED8; //滚动屏
    M_PO8 = LED19;                          //右转向灯
    M_PO9 = (WAKE_ON && IN11);              //前门踏步灯
    M_PO10 = (WAKE_ON && IN12);                    //干燥器
    M_PO11 = (WAKE_ON && IN12);                        //前雾灯
    M_PO12 = LED17;                    //气压传感器电源
    M_PO13 = LED17; //小灯电源
    M_PO14 = LED22; //倒车信号
    M_PO15 = LED22;                         //左转向灯

    R_PO1 = (EV_Gear == 2); //制动灯
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
    R_PO15 = WAKE_ON; //倒车灯2

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