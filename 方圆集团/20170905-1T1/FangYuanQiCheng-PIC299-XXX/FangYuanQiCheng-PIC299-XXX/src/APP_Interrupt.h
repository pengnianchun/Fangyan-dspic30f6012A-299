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

extern unsigned int Fcan_count; //ǰ��ģ��CAN
extern unsigned int Rcan_count; //��ģ��CAN
extern unsigned int Mcan_count; //�в�ģ��CAN

extern unsigned int Ecan_count; //������ECUģ��CAN
extern unsigned int Vcan_count; //����������VCUģ��CAN
extern unsigned int Bcan_count; //��ع�����BMSģ��CAN
extern unsigned int Dcan_count; //ת������DC/ACģ��CAN
extern unsigned int Acan_count; //�յ�ACģ��CAN

extern unsigned int BAT24V_count; //���ص�ѹ������ʱ

#define C3_K     512
#define FOUT_DR  TRISFbits.TRISF6
#define FOUT     LATFbits.LATF6
//unsigned char vspeed;    //��λkm/h

void TIM5_Init(void);

#endif	/* APP_INTERRUPT_H */

