#include "BSP.h"

unsigned int freq[2];
unsigned int fin_count[2];

void INT1_Init(void) {
    _INT1IF = 0;
    _INT1IE = 1;
    _INT1EP = 1;
}
void INT2_Init(void) {
    _INT2IF = 0;
    _INT2IE = 1;
    _INT2EP = 1;
}


void TIMER3_Init(void) {
    T3CON = 0x0020; // 16M/64��Ƶ  250kHz
    TMR3 = 0;
    PR3 = 49999;  //200ms�ж�һ�� 
    _T3IF = 0;
    _T3IE = 1;
    T3CONbits.TON=1;
}

//200ms�ж�һ��
void __attribute__((__interrupt__, auto_psv)) _T3Interrupt(void) {
    static unsigned int stemp[5] = {0, 0, 0, 0, 0};
    static unsigned int i = 0;
    
    static unsigned int Tstemp[5] = {0, 0, 0, 0, 0};
    static unsigned int j = 0;
    if (i >= 5) i = 0;
    stemp[i++] = fin_count[0];
    fin_count[0] = 0;
    freq[0] = stemp[0] + stemp[1] + stemp[2] + stemp[3] + stemp[4];
    
    if (j >= 5) j = 0;
    Tstemp[j++] = fin_count[1];
    fin_count[1] = 0;
    freq[1] = Tstemp[0] + Tstemp[1] + Tstemp[2] + Tstemp[3] + Tstemp[4];
   
    _T3IF = 0;
}

void __attribute__((__interrupt__, auto_psv)) _INT1Interrupt(void) {
    fin_count[0]++;
    _INT1IF = 0;
}
void __attribute__((__interrupt__, auto_psv)) _INT2Interrupt(void){
    fin_count[1]++;
    _INT2IF = 0;
}