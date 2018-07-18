/*
 * File:   APP_AD.c
 * Author: pnc
 *
 * Created on 2017年7月28日, 下午4:59
 */


#include "APP_System.h"

unsigned int ADR[8]; //仪表模拟信号采集值    2016/10/10
unsigned int ADV[8]; //仪表模拟信号采集值 

void Count_ADR(void) {
    float ad = 4096.0;
    //电压型传感器采集  ADR[]是实际的电压*1000
    //ADV[1] = (unsigned int) (10*read_ADR(1) / ad*500);
    //ADV[2] = (unsigned int) (10*read_ADR(2) / ad*500);
    ADV[3] = (unsigned int) (10 * read_ADR(3) / ad * 500);
    ADV[4] = (unsigned int) (10 * read_ADR(4) / ad * 500);
    //ADV[5] = (unsigned int) (10*read_ADR(5) / ad*500);
    ADV[6] = (unsigned int) (10 * read_ADR(6) / ad * 500);
    //if (ADV[4] <= 0) ADR[4] = 0;
    //if (ADV[5] <= 0) ADR[5] = 0;
    //蓄电池电压    
    ADV[0] = (unsigned int) (550.0 * read_VOL() / ad); //实际电压放大10倍   //(read_VOL() - 1300)*10 / 76 + 180;
    if (ADV[0] >= 220) BAT24V_count = 0;
    //电阻型传感器采集  ADR[]是实际的阻值
    //ADR[1] = (unsigned int) (100.0*read_ADR(1)/(ad-read_ADR(1)));//((read_ADR(1) / ad * 100) / (1 - read_ADR(1) / ad));
    //ADR[2] = (unsigned int) (100.0*read_ADR(2)/(ad-read_ADR(2)));
    //ADR[3] = (unsigned int) (100.0*read_ADR(3)/(ad-read_ADR(3)));
    //ADR[4] = (unsigned int) (100.0*read_ADR(4)/(ad-read_ADR(4)));
    //ADR[5] = (unsigned int) (100.0*read_ADR(5)/(ad-read_ADR(5)));
    //ADR[6] = (unsigned int) (100.0*read_ADR(6)/(ad-read_ADR(6)));
    //if (ADR[1] > 1000)
    //    ADR[1] = 0;
    //if (ADR[2] > 1000)
    //    ADR[2] = 0;
    //if (ADR[3] > 1000)
    //    ADR[3] = 0;
    //if (ADR[4] > 1000)
    //    ADR[4] = 0;
    //if (ADR[5] > 1000)
    //    ADR[5] = 0;
    //if (ADR[6] > 1000)
    //    ADR[6] = 0;

}
