#include "BSP.h"

void ADC_Init(void) {
    ADPCFG = 0xfffc; //���ýӿ�Ϊģ��ӿ�?1ķ
    ADCON1 = 0x00e0; //SSRC=111 �Զ�ת��
    ADCON2 = 0x003c; //SMPI=1111 ÿ16���ж�һ��
    ADCON3 = 0x1f1f; //����ʱ�� 15Tad, 1Tad= �ڲ� Tcy/2?
    ADCSSL = 0x0000; //

    AD_E_DR = 0;
    AD_A_DR = 0;
    AD_B_DR = 0;
    AD_C_DR = 0;
}

unsigned int ADC_Read(unsigned char chs) {
    unsigned int value = 0;
    unsigned char i;
    if (chs > 16) return 0;

    ADCON1bits.ADON = 1; //���ADC
    ADCHS = chs;
    IFS0bits.ADIF = 0;
    ADCON1bits.ASAM = 1;
    while (!IFS0bits.ADIF);
    ADCON1bits.ASAM = 0;
    for (i = 0; i < 16; i++) {
        value = value + *(&ADCBUF0 + i);
    }
    value = value >> 4;
    ADCON1bits.ADON = 0; //�ر�ADC
    return (value);
}

unsigned int adc_avg(unsigned char channel) {
    unsigned int adc_max = 0;
    unsigned int adc_min = 0xffff;
    unsigned int adc_sum = 0;
    unsigned int adc_value;
    unsigned int i;

    for (i = 0; i < 18; i++) {
        adc_value = ADC_Read(channel);
        if (adc_value > adc_max) adc_max = adc_value;
        if (adc_value < adc_min) adc_min = adc_value;
        adc_sum += adc_value;
    }
    adc_sum = adc_sum - adc_max - adc_min;
    return (unsigned int) (adc_sum >> 4);
}

unsigned int read_VOL(void){
    return(adc_avg(0x00));
}

unsigned int read_ADR(unsigned char index) {
    unsigned int dump;
    switch (index) {
        case 0:
            AD_E = 1; //�ر� 
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
    }
    __delay32(10);
    dump = adc_avg(0x01);
    
    return dump;
}