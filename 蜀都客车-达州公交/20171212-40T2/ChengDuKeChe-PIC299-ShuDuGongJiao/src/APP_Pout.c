/*
 * File:   APP_Pout.c
 * Author: pnc
 *
 * Created on 2017年7月28日, 下午4:53
 */


#include "APP_System.h"

void SYSTME_Logic(void) {
    unsigned int temp = 0;
    //F_PO1 = (SPEED >= 5);                  //门控电源
    //F_PO2 = (WAKE_ACC || WAKE_ON);         //制动踏板电源
    //F_PO3 = (WAKE_ON);                     //下客门铃电源
    F_PO4 = LED22;                         //左近光灯
    F_PO5 = LED17;                         //左远光灯（远光辅佐）
    F_PO6 = LED19;                         //前雾灯
    F_PO7 = LED4;                          //左前转向灯（前部侧转）
    F_PO8 = LED8;                          //右前转向灯（前部侧转）
    F_PO9 = IN29;                          //前小灯(左右侧标灯)
    //车门电源
    if ((SPEED >= 5) && (fKL15 || fKH1)) {
        F_PO10 = 1;
    }else if((SPEED >= 5) && !fKL15 && !fKH1){
        F_PO10 = 0;
    }else if(SPEED < 5){
        F_PO10 = 1;
    }        
    F_PO11 = LED22;                        //右近光灯
    F_PO12 = (IN29 && fKL15);              //前门踏步灯（LED）
    //启动请求
    //ON - 前起动ON 且 空挡ON 且 转速小于550 且 后舱门OFF时输出；
    //ON - 后起动ON 且 空挡ON 且 转速小于550且后舱门ON且手刹信号ON时输出；
    F_PO13 = ((IN4 && (Current_Gear == 125)&&(EngineSpeed < 4400)&&(!rKL10))
            || (rKL15 && (Current_Gear == 125)&&(EngineSpeed < 4400) && rKL10 && LED18)
            );                           
    F_PO14 = WAKE_ON;                      //风扇电源
    F_PO15 = LED17;                        //右远光灯（远光辅佐）
    F_PO16 = 0;

    /*M_PO1 = 1;                             //车门电源、电子钟
    M_PO2 = IN29;                          //示高灯（LED）
    M_PO3 = ((mKH1 && IN29) || IN11);      //中门灯（LED）
    M_PO4 = (IN17);                        //前路牌
    M_PO5 = (WAKE_ON && fKL2);             //广告灯（LED）
    M_PO6 = (IN17);                        //侧、后路牌
    M_PO7 = (WAKE_ON && fKL10);            //TV1电源
    M_PO8 = (fKL3 || F_PO12);              //驾驶员顶灯（LED)（ACCorON+驾驶员顶灯开关）或者（ACC/ON+前门开到位信号）或者（充电开关+驾驶员顶灯开关）
    M_PO9 = (IN11);                        //厢灯1输出（LED)
    M_PO10 = (IN12);                       //厢灯2输出（LED)
    M_PO11 = (WAKE_ON && IN26 && (SPEED == 0)); //中门开电磁阀
    M_PO12 = (WAKE_ON && (IN32 || (SPEED > 5)));//中门关电磁阀
    M_PO13 = (WAKE_ON && IN19 && (SPEED == 0)); //前门开电磁阀
    M_PO14 = (WAKE_ON && (IN28 || (SPEED > 5)));//前门关电磁阀
    M_PO15 = (WAKE_ON && fKL10);           //TV2电源
    M_PO16 = 0;*/

    //启动继电器触点满足以下二个条件之一://ON - 前起动ON且空挡ON且转速小于550且后舱门OFF且HCU启动禁止值为0且TCU启动使能值为1；
                                         //ON - 后起动ON且空挡ON且转速小于550且后舱门ON且手刹信号ON；
                                         //ON - 车辆运行过程中HCU（0x18EF0AEF）发出数值为21415后时输出；
    if ((Current_Gear == 125)                            //空挡
            && (EngineSpeed < 4400)                      //转速小于550
            && (CAN_0x18EF0AEF.hcu_starter_forbid == 0)  //HCU启动禁止值为0
            && (CAN_0x0CF00203.tcu_start_allow == 1)     //TCU启动使能值为1
            && IN4                                       //前启动
            && !rKL10                                    //后舱门OFF
            ) {
        R_PO1 = 1;
    } else if((Current_Gear == 125)                      //空挡 
            && (EngineSpeed < 4400)                      //转速小于550
            && rKL15                                     //后启动
            && rKL10                                     //后舱门ON
            && rKL5                                      //手刹ON
            ){
        R_PO1 = 1;
    } else if (CAN_0x18EF0AEF.ENG_start_req == 21415) {
        R_PO1 = 1;
    } else {
        R_PO1 = 0;
    }
    //排风扇
    temp = rADR[1];
    if (M_ON) {
        if (IN17) {
            R_PO2 = 1;
        } else {
            if (temp <= 220)R_PO2 = 1; //35度开启
            if (temp >= 232)R_PO2 = 0; //32度关闭 
        }
    } else {
        R_PO2 = 0;
    }
    R_PO3 = (WAKE_ON); //干燥器  ON档输出       
    R_PO4 = (WAKE_ON && (Current_Gear == 124)); //倒车灯（LED)
    R_PO5 = (LED24); //后刹车灯（LED)
    R_PO6 = (LED20); //后雾灯（LED)
    R_PO7 = (LED4);  //左后转向灯（后部侧转）（LED)
    R_PO8 = (LED8);  //右后转向灯（后部侧转）（LED)
    R_PO9 = (WAKE_ON || WAKE_ACC); //门泵电源
    R_PO10 = (IN29); //后小灯（LED)
    R_PO11 = ((WAKE_ON && IN29 && fKH1) || IN11); //中门踏板灯（LED）
    //驾驶员顶灯（LED)（ACCorON+驾驶员顶灯开关）或者（ACC/ON+小灯+前门开到位信号）或者（充电开关+驾驶员顶灯开关）
    R_PO12 = ((WAKE_ON && (IN18 || (fKL15 && IN29))) || (WAKE_Charge && IN18));
    R_PO13 = (IN11);                       //厢灯1输出（LED)
    R_PO14 = (IN12);                       //厢灯2输出（LED)
    R_PO15 = (WAKE_ON && (fKH1 || fKL15)); //门开信号
    R_PO16 = 1;

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