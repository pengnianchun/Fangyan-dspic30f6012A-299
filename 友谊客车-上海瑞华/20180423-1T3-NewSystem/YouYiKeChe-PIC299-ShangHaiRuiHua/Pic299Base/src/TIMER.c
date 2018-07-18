#include "BSP.h"


void TIMER1_Init(void){	
 TMR1=0;	
 T1CON = 0x0010;  //1：8分频 Fcy/8 16MHZ/8=2MHz
 PR1=19999;    // 10ms (FCY/8) 20000*0.5ns=10ms FCY*10
 _T1IF=0; 
 _T1IE=1;   
 T1CONbits.TON=1; //运行定时器
} 

/*初始化背光调节*/
void BL_Init(void){
  OC1CON=0x0006;//OCx处于PWM 模式  Timer2是比较时钟源
  T2CON=0x0020; //64分频   (Fcy/64)   16MHz/64  
  PR2=1000;     //PWM周期   250Hz
  OC1R=1000;//初始占空比 （读取EEROM设定值）
  T2CONbits.TON=1;//启动定时器
  OC1RS=0;
}






