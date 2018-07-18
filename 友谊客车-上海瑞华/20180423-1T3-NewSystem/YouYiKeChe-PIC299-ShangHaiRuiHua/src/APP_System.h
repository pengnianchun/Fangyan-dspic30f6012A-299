/* 
 * File:   SYSTEM.h
 * Author: mpszm
 *
 * Created on 2016��8��1��, ����2:50
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

//ϵͳEEPROM������
//���������
#define  TOTAL_MILES   0L
//�����������
#define  SINGLE_MILES  0
//����������
#define  HM_PLUSE      105
//��������ֵ
#define  BACKLIGHT     750
//����ģ���ַ 0x01 Ϊǰ��ģ�� 0x02 Ϊ��ģ��  0x03Ϊ����ģ��   0x04Ϊ�Ǳ�
#define  MT_ADDR       4
//����汾��
#define  VERISON       100
//�Խ�����
#define  TIME          20180423L
//�Ƿ����Ƶ�ź� 0������Ƶ 1����Ƶ
#define  VIDEO         0
//����Ƶ�ĸ���  
#define  VIDEO_NUMBER  2
//��ָ��
//#define  NULL          (void*)0
//����״̬
#define  WAKE_Danger   wake_up1     
#define  WAKE_ON       wake_up3
#define  WAKE_ACC      0
#define  WAKE_Charge   wake_up2
#define  WAKE_Start    0
//���ʹ�ͳ/���綯
#define  MODE_EV       1
#define  MODE_FV       0
//��������ʾģʽ��������ʾ�����ǿ̶���
#define  DrawBus       0
//��CAN�ڵ�����
#define  NODE_NUMBER   4

extern unsigned char delay_cnt;

extern unsigned int single_miles;
extern unsigned long total_miles;

extern unsigned char PRESS[2]; //��ѹֵ

extern unsigned int SPEED; //�ⲿCAN���㳵��
extern unsigned int RPM;   //�ⲿCAN����ת��


/*�������ƽӿ� */
#define KEY_AV       _RD11       //S1
#define KEY_AV_DR    _TRISD11

#define KEY_SET        _RD10      //S2
#define KEY_SET_DR     _TRISD10

#define KEY_UP         _RD7       //S6
#define KEY_UP_DR      _TRISD7

//�Ǳ��������Դ���ƶ˿�
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
#define  F500ms_LCD         gKEY[1].bit6 //lcd��ʾ����ʱ��
#define  alarm_update_flag  gKEY[1].bit7//������ʾ����ʱ��
#define  CLR_single_miles   gKEY[1].bit8

#define  key_long_set       gKEY[2].bit1
#define  M_ON               gKEY[2].bit2  
#define  kFLASH             gKEY[2].bit3
#define  FLASH              gKEY[2].bit4 //ת�����˸��־
#define  FLASH_1s           gKEY[2].bit5 
#define  DM1_CLEAR          gKEY[2].bit6 
#define  R_flag             gKEY[2].bit7
#define  bLCD_RESET         gKEY[2].bit8

#define  F300ms             gKEY[3].bit1 // 2016/10/22��������ʱ��
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


#define CAN_TIME 30//CAN�ڵ���ϱ���
#define BAT24_TIME 100//���ص�ѹ���ͱ���10��

extern unsigned int NodeCount[NODE_NUMBER]; //�ڵ㳬ʱ����


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
    unsigned char Status;               //���״̬
    unsigned char Condition;            //��������
    unsigned int  Out_time;             //�������㣬����ʱ�� T = out_time * ������ʱ��
    CYCLE_EN      Cycle_en;             //�Ƿ�ѭ��ִ��
    unsigned int  Stop_time;            //ѭ��ִ��ʱ����Ъʱ�� T = stop_time * ������ʱ��
    unsigned char Cycle_times;          //ѭ��������0Ϊ����ѭ��
    unsigned int  Run_time;             //�Ѿ�����ʱ��
    unsigned char Run_frequency;        //�Ѿ����д���
} _FLASH;

extern _FLASH Flash[];

void Interval_Status(unsigned int condition, Flash_Number x);

int Trigger_up(unsigned int x);

#if 0
int Interval_Run(unsigned char condition,  //��������
        unsigned int out_time,              //�������㣬����ʱ�� T = time * ������ʱ��
        CYCLE_EN cycle_en,                  //�Ƿ�ѭ��ִ��
        unsigned int stop_time,             //ѭ��ִ��ʱ����Ъʱ��
        unsigned char cycle_times           //ѭ��������0Ϊ����ѭ��
        );
#endif
//void KeyProcess(void);

// ����ṹ
typedef struct _TASK_COMPONENTS
{
    void (*TaskHook)(void);            // Ҫ���е�������
    unsigned long ItvTime;             // �������м��ʱ��
    unsigned char Run;                 // �������б�ǣ�0-�����У�1����
    unsigned long Timer;               // ��ʱ��      
} TASK_COMPONENTS;                     // ������

extern TASK_COMPONENTS TaskComps[];

typedef struct {
    unsigned long delay_time;          //��ʱʱ��
    unsigned char condition;           //����
    unsigned char delay_out;           //���
    unsigned long Timer;               //��ʱ��  
} _Delay_Out;

typedef enum {
    Delay_5s,
    Delay_10s,
    Delay_20s,
    Delay_50s,
} Delay_Time;

extern _Delay_Out delay_out[];

//void TaskRemarks(void);  //�����־����
//void TaskProcess(void);  //��������
#endif	/* SYSTEM_H */

