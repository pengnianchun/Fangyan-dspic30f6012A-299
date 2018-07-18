#include "BSP.h"

#define H165_SER_DR     _TRISG7
#define H165_CLK_DR     _TRISG6
#define H165_CS_DR      _TRISC2

#define H165_SER       _RG7
#define H165_CLK       _LATG6
#define H165_CS        _LATC2

SW_DATA  sw_input[5];

void SW_Input(void){
  unsigned char dump;
  unsigned char i,j;

  H165_SER_DR=1;
  H165_CLK_DR=0;
  H165_CS_DR=0;
  

  H165_CS=1;
 for(j=0;j<5;j++){ 
   dump=0;	 
  for(i=0;i<8;i++){
   H165_CLK=0;
   dump=(dump<<1);
   dump|=H165_SER;
   H165_CLK=1;
  }
   sw_input[4-j].byte=~dump; 
 }
 H165_CS=0;
}


