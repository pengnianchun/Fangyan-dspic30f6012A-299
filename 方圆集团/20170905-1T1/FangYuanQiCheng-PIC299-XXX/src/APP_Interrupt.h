/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef APP_INTERRUPT_H
#define	APP_INTERRUPT_H

extern unsigned int Fcan_count; //前部模块CAN
extern unsigned int Rcan_count; //后部模块CAN
extern unsigned int Mcan_count; //中部模块CAN

extern unsigned int Ecan_count; //发动机ECU模块CAN
extern unsigned int Vcan_count; //整车控制器VCU模块CAN
extern unsigned int Bcan_count; //电池管理器BMS模块CAN
extern unsigned int Dcan_count; //转向助力DC/AC模块CAN
extern unsigned int Acan_count; //空调AC模块CAN

extern unsigned int BAT24V_count; //蓄电池低压报警计时

#define C3_K     512
#define FOUT_DR  TRISFbits.TRISF6
#define FOUT     LATFbits.LATF6
//unsigned char vspeed;    //单位km/h

void TIM5_Init(void);

#endif	/* APP_INTERRUPT_H */

