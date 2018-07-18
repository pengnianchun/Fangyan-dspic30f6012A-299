/*
 * File:   APP_Interrupt.c
 * Author: pnc
 *
 * Created on 2017年7月28日, 下午5:24
 */

#include "APP_System.h"

unsigned int Fcan_count = 0; //前部模块CAN
unsigned int Rcan_count = 0; //顶部模块CAN
unsigned int Mcan_count = 0; //中部模块CAN

unsigned int Ecan_count = 0; //发动机ECU模块CAN
unsigned int Vcan_count = 0; //整车控制器VCU模块CAN
unsigned int Bcan_count = 0; //电池管理器BMS模块CAN
unsigned int Dcan_count = 0; //转向助力DC/AC模块CAN
unsigned int Acan_count = 0; //空调AC模块CAN

unsigned int BAT24V_count = 0; //蓄电池低压报警计时

static void Interval_Run(void) {
    //static unsigned int temp = 0;
    //static unsigned char times = 0;
    unsigned char i = 0;
#if 0    
    if (condition) {//条件不满足，立即停止运行
        temp = temp > 60000 ? 60000 : temp + 1; //计数上限，防止溢出
    } else {
        temp = 0;
    }
    
    if (condition) {//条件不满足，单次循环结束停止运行
        temp = temp > 60000 ? 60000 : temp + 1; //计数上限，防止溢出
    } else if(temp > 0 && temp < (out_time + stop_time) * 100){
        temp = temp > 60000 ? 60000 : temp + 1
    } else {
        temp = 0;
    }
    
    if (condition && ((times < cycle_times) || (!cycle_times))) {//条件不满足，单次循环结束后停止运行，条件满足，运行指定的次数或一直循环运行
        temp = temp > 60000 ? 60000 : temp + 1; //计数上限，防止溢出
    } else if (temp > 0 && temp < (out_time + stop_time) * 100) {        
        temp = temp > 60000 ? 60000 : temp + 1;
    } else {
        temp = 0;
        if (!condition) {
            times = 0;
        }
    }
#endif    
    for (i = 0; Flash[i].Out_time != 0; i++) {
        if (Flash[i].Condition && ((Flash[i].Run_frequency < Flash[i].Cycle_times) || (!Flash[i].Cycle_times))) {//条件不满足，指定循环次数结束后停止运行，条件满足，运行指定的次数或一直循环运行
            Flash[i].Run_time = Flash[i].Run_time > 600000 ? 600000 : Flash[i].Run_time + 1; //计数上限，防止溢出
        } else if (Flash[i].Run_time > 0 && Flash[i].Run_time < (Flash[i].Out_time + Flash[i].Stop_time)) {
            Flash[i].Run_time = Flash[i].Run_time > 600000 ? 600000 : Flash[i].Run_time + 1;
        } else if ((Flash[i].Run_frequency > 0) && (Flash[i].Run_frequency < Flash[i].Cycle_times)) {//改变这里的 cycle_times 可以设置停止运行前循环次数
            Flash[i].Run_time = Flash[i].Run_time > 600000 ? 600000 : Flash[i].Run_time + 1;
        } else {
            Flash[i].Run_time = 0;
            if (!Flash[i].Condition) {
                Flash[i].Run_frequency = 0;
            }
        }

        if (Flash[i].Run_time > 0 && Flash[i].Run_time < Flash[i].Out_time) {
            Flash[i].Status = 1;
        } else if (!Flash[i].Cycle_en) {
            Flash[i].Status = 0;
        } else if (Flash[i].Run_time < (Flash[i].Out_time + Flash[i].Stop_time)) {
            Flash[i].Status = 0;
        } else {
            Flash[i].Run_time = 0;
            Flash[i].Run_frequency++;
            Flash[i].Status = 0;
        }
    }
}

void __attribute__((__interrupt__, auto_psv)) _T1Interrupt(void) {//10ms中断一次
    static unsigned int cnt0 = 0;
    static unsigned int cnt1 = 3;
    static unsigned int cnt2 = 7;
    static unsigned int cnt3 = 9;
    static unsigned int cnt4 = 0;
    static unsigned int cnt6 = 0;    
    static unsigned int Fcount = 0, Kcount = 0;
    static unsigned int count6 = 0;
    static float mile = 0;
    //static unsigned char task1 = 0;
    //报警延时3s标记
    if (alarm_update_flag == 1) {
        if (count6 >= 300) {//
            count6 = 0;
            alarm_update_flag = 0;
        } else {
            count6++;
        }
    } else {
        count6 = 0;
    }
   //任务标记处理
    TaskRemarks();
    
    //按钮处理
    KeyProcess();
    
    //间歇输出状态
    Interval_Run();

    if (delay_cnt > 0) delay_cnt--; //延时计数器    

    if (cnt0 >= 4) {//50ms
        cnt0 = 0;
        BCAN_send_mile();
        BCAN_SendCtl();
        if (M_ON_flag && (WAKE_ON || WAKE_ACC || WAKE_Charge || WAKE_Start)) {//wake_up3置0时，M_ON不会立马置0，因为存在消抖延时
            LED_Logic();
            LED_Out();
            SYSTME_Logic();
        }
        F50ms = 1;
    } else cnt0++;

    if (cnt1 >= 9) {//100ms
        cnt1 = 0;
        F100ms = 1;      
        //计算累计里程
        if (SPEED > 0) {//车速大于0时才累计
            mile = mile + (float) (SPEED / 3.6 * 0.1);
            if (mile >= 100.0) {
                mile = 0.0;
                save_flag = 1;
                if (single_miles >= 9999) single_miles = 0;
                else single_miles++;
                if (total_miles >= 9999999) total_miles = 0;
                else total_miles++;
            }
        }
        //CAN节点故障计时3s
        if (Fcan_count >= CAN_TIME)Fcan_count = CAN_TIME;
        else Fcan_count++;
        if (Rcan_count >= CAN_TIME)Rcan_count = CAN_TIME;
        else Rcan_count++;
        if (Mcan_count >= CAN_TIME)Mcan_count = CAN_TIME;
        else Mcan_count++;
        if (Ecan_count >= CAN_TIME)Ecan_count = CAN_TIME;
        else Ecan_count++;
        if (Vcan_count >= CAN_TIME)Vcan_count = CAN_TIME;
        else Vcan_count++;
        if (Bcan_count >= CAN_TIME)Bcan_count = CAN_TIME;
        else Bcan_count++;
        if (Dcan_count >= CAN_TIME)Dcan_count = CAN_TIME;
        else Dcan_count++;
        if (Acan_count >= CAN_TIME)Acan_count = CAN_TIME;
        else Acan_count++;
        BAT24V_count = BAT24V_count >= BAT24_TIME ? BAT24_TIME : BAT24V_count + 1;

        if (cnt4 >= 9) {//1s
            cnt4 = 0;
            F1000ms = 1;
            FLASH_1s = !FLASH_1s;            
            if(cnt6 >= 4){//5秒
                cnt6 = 0;
            }else cnt6++;
        } else cnt4++;
    } else cnt1++;

    if (Fcount >= 39) {//0.4s
        Fcount = 0;
        F400ms = 1;
        FLASH = !FLASH;
    } else Fcount++;

    if (Kcount >= 29) {//300ms
        Kcount = 0;
        F300ms = 1;
        kFLASH = !kFLASH;
    } else Kcount++;

    if (cnt2 >= 49) {//500ms 
        cnt2 = 0;
        F500ms = 1;
        F500ms_LCD = !F500ms_LCD;       
    } else cnt2++;

    if (wake_up3) { //ON开关判断//消抖//M_ON在掉电的一瞬间会使上拉电源无效，而M_ON在断电会保持300ms，从而影响开关量采集
        if (cnt3 > 30) M_ON = 1;
        else cnt3++;
    } else {
        if (cnt3 < 1) M_ON = 0;
        else cnt3--;
    }
        
    _T1IF = 0;
}

void TIM5_Init(void) {
    FOUT_DR = 0;
    FOUT = 0;
    T5CON = 0; //1：1 分频   16MHz
    TMR5 = 0;
    PR5 = 15999; //1ms中断一次
    _T5IF = 0;
    _T5IE = 1;
    T5CONbits.TON = 1;
}

void __attribute__((__interrupt__, auto_psv)) _T5Interrupt(void) { //1ms 最大输出频率500HZ
    static unsigned int cnt = 0, out_K = 0,cnt_can = 0;
    out_K = 721; // 比例系数K = 1000 * 3600/公里脉冲数P
    if (SPEED > 0) {
        //if (cnt < 2) FOUT = 1;//C3输出
        if (cnt < (out_K / SPEED) / 2) FOUT = 1; //占空比1:1输出
        else FOUT = 0;
        cnt++;

        //C3输出信号 V = 255 * 2 / T
        /*if (cnt >= (C3_K / SPEED)) {
            cnt = 0;
        }*/
        // 周期T(秒) = 3600/公里脉冲数P(个)/速度（KM/H）
        // 比例系数K = 1000 * 3600/公里脉冲数P
        if (cnt >= (out_K / SPEED)) {
            cnt = 0;
        }

    } else {
        cnt = 0;
        FOUT = 0;
    }
    //CAN任务处理
    TaskProcess();
    
    if (cnt_can >= 4) {
        cnt_can = 0;
        F_CANSend = 1;
    } else {
        cnt_can++;
    }
    
    _T5IF = 0;
}