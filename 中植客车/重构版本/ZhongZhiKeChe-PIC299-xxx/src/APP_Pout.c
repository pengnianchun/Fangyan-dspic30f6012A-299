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
    F_PO4 = (IN6 && IN9); //左前雾灯
    F_PO5 = ((BMS_SOC > 30) && IN23); //空调面板电源
    F_PO6 = (FLASH && (IN5 || wake_up1)); //右转向灯
    F_PO7 = (FLASH && (IN1 || wake_up1)); //左转向灯
    F_PO8 = mKL15; //中门开信号输出
    F_PO9 = LED17; //左远关灯
    F_PO10 = (IN6 && IN9); //右前雾灯
    F_PO11 = LED17; //右远光灯
    //F_PO12 = M_ON; //行车记录仪电源
    F_PO13 = (IN8); //左近光
    F_PO14 = (IN6); //位置灯
    F_PO15 = (IN8); //右近光

    M_PO1 = (IN12); //长条灯1
    M_PO2 = (FLASH && (IN5 || wake_up1)); //右转向灯
    M_PO3 = (IN11); //司机灯
    M_PO4 = (rKL6); //制动灯
    M_PO5 = (IN20); //前门开电磁阀
    M_PO6 = (IN19); //前路牌
    M_PO7 = (IN28); //前门关电磁阀
    M_PO8 = (M_ON); //电子钟
    M_PO9 = (IN27); //中门开电磁阀
    M_PO10 = (IN19); //后路牌
    M_PO11 = (IN26); //中门关电磁阀
    M_PO12 = (IN13); //长条灯2
    M_PO13 = (M_ON); //硬盘电源
    M_PO14 = (IN6); //位置灯
    M_PO15 = (FLASH && (IN1 || wake_up1)); //左转向灯

    R_PO1 = (rKL6); //制动灯
    R_PO2 = (IN19); //侧路牌
    R_PO3 = (LED20); //后雾灯       
    R_PO4 = (M_ON); //整车控制器电源
    R_PO5 = (FLASH && (IN1 || wake_up1)); //左转向灯
    R_PO6 = (M_ON); //气压传感器电源
    R_PO7 = (FLASH && (IN5 || wake_up1)); //右转向
    R_PO8 = IN22; //电喇叭
    R_PO9 = (VCU_Gear == 13); //倒车灯1
    R_PO10 = IN22; //电喇叭
    R_PO11 = (mKH1 && IN6); //前门踏步灯
    R_PO12 = (IN6); //位置灯示高灯
    R_PO13 = (mKL15 && IN6); //中门踏步灯
    R_PO14 = (VCU_Gear == 13); //倒车蜂鸣器
    R_PO15 = (VCU_Gear == 13); //倒车灯2

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