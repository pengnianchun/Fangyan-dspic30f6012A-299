#include "BSP.h"

#define H595_SI_DR     _TRISG8
#define H595_CLK_DR    _TRISG6
#define H595_CS_DR     _TRISG9

#define H595_SI     _LATG8
#define H595_CLK    _LATG6
#define H595_CS     _LATG9



LED_DATA alarm_led[4];

void LED_Out(void){
   unsigned char i,j;
   unsigned char dump;
   
   H595_SI_DR = 0;
   H595_CLK_DR = 0;
   H595_CS_DR  = 0;
   
   H595_CS = 0;
    
   for(j=0;j<4;j++){
     dump=alarm_led[j].byte;
     for(i=0;i<8;i++){
      H595_CLK = 0;
      if((dump & 0x80)==0x80)       H595_SI = 0;
      else                          H595_SI = 1;
      H595_CLK=1;
      dump=(dump<<1);
    } 
   } 
   
  H595_CS = 1; 

}



