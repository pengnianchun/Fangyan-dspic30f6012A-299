#include "BSP.h"
static unsigned int ad_value[2],ad_switch[9];
void ADC_Init(void) {
    ADPCFG = 0xfffc; //使能AN0和AN1
    ADCON1 = 0x00e0; //SSRC=111 采样完成，自动转换
    ADCON2 = 0x003c; //SMPI=1111 存放16个BUFF产生标记
    ADCON3 = 0x1f1f; //设置AD采样周期为31Tad,转换周期固定为14Tad,一个总周期为31+14=45Tad  1Tad=16*Tcy，Tad=16/16000000=1um
    ADCSSL = 0x0000; //

    AD_E_DR = 0;
    AD_A_DR = 0;
    AD_B_DR = 0;
    AD_C_DR = 0;
    ADCHS = 0;
    _ADIF=0;
    _ADIE=1;    
    ADCON1bits.ASAM = 1;
    ADCON1bits.ADON = 1;
}

unsigned int ADC_Read(unsigned char chs) {
    static unsigned int value = 0;
    unsigned char i;
    if (chs > 16) return 0;

    //ADCON1bits.ADON = 1; //锟斤拷锟?ADC
    //ADCHS = chs;
    //IFS0bits.ADIF = 0;
    
    if (IFS0bits.ADIF) {
        IFS0bits.ADIF = 0;
        value = 0;
        //ADCON1bits.ASAM = 0;
        for (i = 0; i < 16; i++) {
            value = value + *(&ADCBUF0 + i);
        }
        value = value >> 4;
        //ADCON1bits.ADON = 0; //锟截憋拷ADC           
    }  
    return (value);
}

unsigned int adc_avg(volatile unsigned int *ad, unsigned char buff) {
    unsigned int adc_max = 0;
    unsigned int adc_min = 0xffff;
    unsigned int adc_sum = 0;
    unsigned int adc_value;
    unsigned int i;

    for (i = 0; i < buff; i++) {
        adc_value = *(ad + i);
        if (adc_value > adc_max) adc_max = adc_value;
        if (adc_value < adc_min) adc_min = adc_value;
        adc_sum += adc_value;
    }
    adc_sum = adc_sum - adc_max - adc_min;
    if (buff <= 2) return 0;
    return (unsigned int) (adc_sum / (buff - 2));
}

unsigned int read_VOL(void){
    //return(adc_avg(0x00));
    return(ad_value[0]);
    //return(ADC_Read(0));
}

unsigned int read_ADR(unsigned char index) {
    unsigned int dump = 0;
    /*switch (index) {
        case 0:
            AD_E = 1; //锟截憋拷 
            return 0;
            break;
        case 1:
            AD_E = 0;
            AD_A = 0;
            AD_B = 0;
            AD_C = 0;
            break;
        case 2:
            AD_E = 0;
            AD_A = 1;
            AD_B = 0;
            AD_C = 0;
            break;
        case 3:
            AD_E = 0;
            AD_A = 0;
            AD_B = 1;
            AD_C = 0;
            break;
        case 4:
            AD_E = 0;
            AD_A = 1;
            AD_B = 1;
            AD_C = 0;
            break;
        case 5:
            AD_E = 0;
            AD_A = 0;
            AD_B = 0;
            AD_C = 1;
            break;
        case 6:
            AD_E = 0;
            AD_A = 1;
            AD_B = 0;
            AD_C = 1;
            break;
        case 7:
            AD_E = 0;
            AD_A = 0;
            AD_B = 1;
            AD_C = 1;
            break;
        case 8:
            AD_E = 0;
            AD_A = 1;
            AD_B = 1;
            AD_C = 1;
            break;
    }*/
    //__delay32(10);
    //dump = adc_avg(0x01);    
    dump = ad_switch[index];
    return dump;
}

void AD_SWITCH(unsigned char index){
    switch (index) {
                case 0:
                    AD_E = 1; //关闭多路通道 
                    break;
                case 1:
                    AD_E = 0;
                    AD_A = 0;
                    AD_B = 0;
                    AD_C = 0;
                    break;
                case 2:
                    AD_E = 0;
                    AD_A = 1;
                    AD_B = 0;
                    AD_C = 0;
                    break;
                case 3:
                    AD_E = 0;
                    AD_A = 0;
                    AD_B = 1;
                    AD_C = 0;
                    break;
                case 4:
                    AD_E = 0;
                    AD_A = 1;
                    AD_B = 1;
                    AD_C = 0;
                    break;
                case 5:
                    AD_E = 0;
                    AD_A = 0;
                    AD_B = 0;
                    AD_C = 1;
                    break;
                case 6:
                    AD_E = 0;
                    AD_A = 1;
                    AD_B = 0;
                    AD_C = 1;
                    break;
                case 7:
                    AD_E = 0;
                    AD_A = 0;
                    AD_B = 1;
                    AD_C = 1;
                    break;
                case 8:
                    AD_E = 0;
                    AD_A = 1;
                    AD_B = 1;
                    AD_C = 1;
                    break;
            }
}

void __attribute__((__interrupt__, auto_psv)) _ADCInterrupt(void) {
    static unsigned char chs = 1;
    ad_value[ADCHS] = adc_avg(&ADCBUF0, 16);   
    if (ADCHS) {    
        ad_switch[chs] = ad_value[1]; 
        if (++chs >= 9) {
            chs = 1;
        }
        AD_SWITCH(chs); 
    }
    ADCHS = !ADCHS;
    _ADIF = 0;
}