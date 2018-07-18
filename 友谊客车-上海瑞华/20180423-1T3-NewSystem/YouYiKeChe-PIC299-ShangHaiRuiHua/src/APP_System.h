/* 
 * File:   SYSTEM.h
 * Author: mpszm
 *
 * Created on 2016年8月1日, 下午2:50
 */

#ifndef SYSTEM_H
#define	SYSTEM_H

#include <xc.h>
#include "bsp.h"
#include "APP_CAN2_Receive.h"
#include "APP_CAN1_Receive.h"
#include "APP_LED.h"
#include "APP_Pout.h"
#include "APP_AD.h"
#include "APP_CAN_Send.h"
#include "APP_SAVE.h"
#include "APP_Interrupt.h"
#include "APP_LCD_Display.h"
#include <string.h>
#include <stdlib.h>

//系统EEPROM配置字
//总里程配置
#define  TOTAL_MILES   0L
//单次里程配置
#define  SINGLE_MILES  0
//百米脉冲数
#define  HM_PLUSE      105
//背光亮度值
#define  BACKLIGHT     750
//定义模块地址 0x01 为前部模块 0x02 为后模块  0x03为顶部模块   0x04为仪表
#define  MT_ADDR       4
//程序版本号
#define  VERISON       100
//对接日期
#define  TIME          20180423L
//是否带视频信号 0不带视频 1带视频
#define  VIDEO         0
//带视频的个数  
#define  VIDEO_NUMBER  2
//空指针
//#define  NULL          (void*)0
//唤醒状态
#define  WAKE_Danger   wake_up1     
#define  WAKE_ON       wake_up3
#define  WAKE_ACC      0
#define  WAKE_Charge   wake_up2
#define  WAKE_Start    0
//车型传统/纯电动
#define  MODE_EV       1
#define  MODE_FV       0
//主界面显示模式，决定显示车还是刻度条
#define  DrawBus       0
//外CAN节点数量
#define  NODE_NUMBER   4

extern unsigned char delay_cnt;

extern unsigned int single_miles;
extern unsigned long total_miles;

extern unsigned char PRESS[2]; //气压值

extern unsigned int SPEED; //外部CAN换算车速
extern unsigned int RPM;   //外部CAN换算转速


/*按键控制接口 */
#define KEY_AV       _RD11       //S1
#define KEY_AV_DR    _TRISD11

#define KEY_SET        _RD10      //S2
#define KEY_SET_DR     _TRISD10

#define KEY_UP         _RD7       //S6
#define KEY_UP_DR      _TRISD7

//仪表主供电电源控制端口
#define PWR_CTRL_DR   _TRISG13  
#define PWR_CTRL      _LATG13
#define PWR_CTRL_RD   _RG13

extern DATA_BIT gKEY[5];

#define  key_set            gKEY[0].bit1 
#define  pkey_set           gKEY[0].bit2 
#define  bkey_set           gKEY[0].bit3

#define  key_up             gKEY[0].bit4
#define  pkey_up            gKEY[0].bit5  
#define  bkey_up            gKEY[0].bit6

#define  key_AV             gKEY[0].bit7
#define  pkey_AV            gKEY[0].bit8
#define  bkey_AV            gKEY[1].bit1
 
#define  key_duble          gKEY[1].bit2
#define  F50ms              gKEY[1].bit3
#define  F100ms             gKEY[1].bit4
#define  F500ms             gKEY[1].bit5  
#define  F500ms_LCD         gKEY[1].bit6 //lcd显示更新时间
#define  alarm_update_flag  gKEY[1].bit7//报警显示更新时间
#define  CLR_single_miles   gKEY[1].bit8

#define  key_long_set       gKEY[2].bit1
#define  M_ON               gKEY[2].bit2  
#define  kFLASH             gKEY[2].bit3
#define  FLASH              gKEY[2].bit4 //转向灯闪烁标志
#define  FLASH_1s           gKEY[2].bit5 
#define  DM1_CLEAR          gKEY[2].bit6 
#define  R_flag             gKEY[2].bit7
#define  bLCD_RESET         gKEY[2].bit8

#define  F300ms             gKEY[3].bit1 // 2016/10/22新增更新时间
#define  F400ms             gKEY[3].bit2
#define  F1000ms            gKEY[3].bit3
#define  FLASH_3s           gKEY[3].bit4
#define  time_flag          gKEY[3].bit5
#define  M_ON_flag          gKEY[3].bit6
#define  M_flag             gKEY[3].bit7
#define  save_flag          gKEY[3].bit8

#define  LCD_Static         gKEY[4].bit1
#define  TestMode           gKEY[4].bit2
#define  F6s                gKEY[4].bit3


#define CAN_TIME 30//CAN节点故障报警
#define BAT24_TIME 100//蓄电池电压过低报警10秒

extern unsigned int NodeCount[NODE_NUMBER]; //节点超时计数


void System_Init(void);

void SM_Logic(void);

void SM_Test(void);

int SM_Zero_State(void);

typedef enum {
    NONCYCLE,
    CYCLE
} CYCLE_EN; 

typedef enum {
    Flash_400ms = 0,
    Flash_500ms,
    Flash_1s,
    Run_3s,
    Run_150ms,
    Flash_100ms,
    Flash_200ms,
    Flash_Null
} Flash_Number; 

typedef struct {
    unsigned char Status;               //标记状态
    unsigned char Condition;            //启动条件
    unsigned int  Out_time;             //条件满足，工作时间 T = out_time * 处理间隔时间
    CYCLE_EN      Cycle_en;             //是否循环执行
    unsigned int  Stop_time;            //循环执行时，间歇时间 T = stop_time * 处理间隔时间
    unsigned char Cycle_times;          //循环次数，0为无限循环
    unsigned int  Run_time;             //已经运行时间
    unsigned char Run_frequency;        //已经运行次数
} _FLASH;

extern _FLASH Flash[];

void Interval_Status(unsigned int condition, Flash_Number x);

int Trigger_up(unsigned int x);

#if 0
int Interval_Run(unsigned char condition,  //启动条件
        unsigned int out_time,              //条件满足，工作时间 T = time * 处理间隔时间
        CYCLE_EN cycle_en,                  //是否循环执行
        unsigned int stop_time,             //循环执行时，间歇时间
        unsigned char cycle_times           //循环次数，0为无限循环
        );
#endif
//void KeyProcess(void);

// 任务结构
typedef struct _TASK_COMPONENTS
{
    void (*TaskHook)(void);            // 要运行的任务函数
    unsigned long ItvTime;             // 任务运行间隔时间
    unsigned char Run;                 // 程序运行标记：0-不运行，1运行
    unsigned long Timer;               // 计时器      
} TASK_COMPONENTS;                     // 任务定义

extern TASK_COMPONENTS TaskComps[];

typedef struct {
    unsigned long delay_time;          //延时时间
    unsigned char condition;           //条件
    unsigned char delay_out;           //输出
    unsigned long Timer;               //计时器  
} _Delay_Out;

typedef enum {
    Delay_5s,
    Delay_10s,
    Delay_20s,
    Delay_50s,
} Delay_Time;

extern _Delay_Out delay_out[];

//void TaskRemarks(void);  //任务标志处理
//void TaskProcess(void);  //任务处理函数
#endif	/* SYSTEM_H */

