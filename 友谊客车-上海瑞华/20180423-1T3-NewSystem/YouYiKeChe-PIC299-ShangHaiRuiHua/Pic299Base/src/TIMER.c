#include "BSP.h"


void TIMER1_Init(void){	
 TMR1=0;	
 T1CON = 0x0010;  //1��8��Ƶ Fcy/8 16MHZ/8=2MHz
 PR1=19999;    // 10ms (FCY/8) 20000*0.5ns=10ms FCY*10
 _T1IF=0; 
 _T1IE=1;   
 T1CONbits.TON=1; //���ж�ʱ��
} 

/*��ʼ���������*/
void BL_Init(void){
  OC1CON=0x0006;//OCx����PWM ģʽ  Timer2�ǱȽ�ʱ��Դ
  T2CON=0x0020; //64��Ƶ   (Fcy/64)   16MHz/64  
  PR2=1000;     //PWM����   250Hz
  OC1R=1000;//��ʼռ�ձ� ����ȡEEROM�趨ֵ��
  T2CONbits.TON=1;//������ʱ��
  OC1RS=0;
}






