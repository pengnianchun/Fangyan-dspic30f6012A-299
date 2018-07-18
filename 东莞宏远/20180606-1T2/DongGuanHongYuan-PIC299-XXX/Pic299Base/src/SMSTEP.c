#include "BSP.h"

#define MD1F_DR   _TRISD5
#define MD1C_DR   _TRISD6
#define MD1F      _LATD5
#define MD1C      _LATD6

#define MD2F_DR   _TRISD3
#define MD2C_DR   _TRISD4
#define MD2F      _LATD3
#define MD2C      _LATD4

#define MD3F_DR   _TRISD1
#define MD3C_DR   _TRISD2
#define MD3F      _LATD2
#define MD3C      _LATD1

#define MD4F_DR   _TRISG14
#define MD4C_DR   _TRISG12
#define MD4F      _LATG14
#define MD4C      _LATG12

#define MD5F_DR    _TRISC1
#define MD5C_DR    _TRISG15
#define MD5F       _LATC1
#define MD5C       _LATG15

#define MD6F_DR   _TRISC14 
#define MD6C_DR   _TRISC13
#define MD6F      _LATC13
#define MD6C      _LATC14

unsigned int  sm_steps[6] = {0, 0, 0, 0, 0, 0};
unsigned int  sm_new_value[6] = {0, 0, 0, 0, 0, 0};
unsigned int  sm_old_value[6] = {0, 0, 0, 0, 0, 0};
unsigned char sm_speed[6] = {0, 0, 0, 0, 0, 0};

void SM_Init(void) {
    MD1C_DR = 0;
    MD1F_DR = 0;
    MD2C_DR = 0;
    MD2F_DR = 0;
    MD3C_DR = 0;
    MD3F_DR = 0;
    MD4C_DR = 0;
    MD4F_DR = 0;
    MD5C_DR = 0;
    MD5F_DR = 0;
    MD6C_DR = 0;
    MD6F_DR = 0;

    MD1C = 1;
    MD1F = 0;
    MD2C = 1;
    MD2F = 0;
    MD3C = 1;
    MD3F = 0;
    MD4C = 1;
    MD4F = 0;
    MD5C = 1;
    MD5F = 0;
    MD6C = 1;
    MD6F = 0;

    //定时器4设置
    T4CON = 0; //1：1 分频   32MHz
    TMR4 = 0;
    PR4 = 31999;  //1ms中断一次
    _T4IE = 1;
    T4CONbits.TON=1;
}

void SM_Update_0(void) {//车速表
    if (sm_new_value[0] >= sm_old_value[0]) {
        sm_steps[0] = sm_new_value[0] - sm_old_value[0];
        MD1C = 0; //顺时针移动
    } else {
        sm_steps[0] = sm_old_value[0] - sm_new_value[0];
        MD1C = 1; //逆时针移动
    }
    if (sm_steps[0] > 480) sm_speed[0] = 0; //最快速度
    else if (sm_steps[0] > 360) sm_speed[0] = 1; //
    else if (sm_steps[0] > 240) sm_speed[0] = 2; //     
    else if (sm_steps[0] > 180) sm_speed[0] = 3; //
    else if (sm_steps[0] > 120) sm_speed[0] = 4; //
    else if (sm_steps[0] > 80) sm_speed[0] = 5; //
    else if (sm_steps[0] > 60) sm_speed[0] = 6; //
    else if (sm_steps[0] > 45) sm_speed[0] = 7; //
    else if (sm_steps[0] > 30) sm_speed[0] = 8; //120ms
    else if (sm_steps[0] > 20) sm_speed[0] = 10; //300ms
    else if (sm_steps[0] > 12) sm_speed[0] = 15; //120ms
    else if (sm_steps[0] > 6) sm_speed[0] = 25; //150ms
    else sm_speed[0] = 35; //210ms
}

void SM_Update_1(void) {//电压表
    if (sm_new_value[1] >= sm_old_value[1]) {
        sm_steps[1] = sm_new_value[1] - sm_old_value[1];
        MD2C = 0; //逆时针移动
    } else {
        sm_steps[1] = sm_old_value[1] - sm_new_value[1];
        MD2C = 1; //顺时针移动
    }
    if (sm_steps[1] > 480) sm_speed[1] = 0; //最快速度
    else if (sm_steps[1] > 360) sm_speed[1] = 1; //
    else if (sm_steps[1] > 240) sm_speed[1] = 2; //     
    else if (sm_steps[1] > 180) sm_speed[1] = 3; //
    else if (sm_steps[1] > 120) sm_speed[1] = 4; //
    else if (sm_steps[1] > 80) sm_speed[1] = 5; //
    else if (sm_steps[1] > 60) sm_speed[1] = 6; //
    else if (sm_steps[1] > 45) sm_speed[1] = 7; //
    else if (sm_steps[1] > 30) sm_speed[1] = 8; //120ms
    else if (sm_steps[1] > 20) sm_speed[1] = 10; //300ms
    else if (sm_steps[1] > 12) sm_speed[1] = 15; //120ms
    else if (sm_steps[1] > 6) sm_speed[1] = 25; //150ms
    else sm_speed[1] = 35; //210ms
}

void SM_Update_2(void) {//机油压力表//气压2
    if (sm_new_value[2] >= sm_old_value[2]) {
        sm_steps[2] = sm_new_value[2] - sm_old_value[2];
        MD3C = 0; //顺时针移动
    } else {
        sm_steps[2] = sm_old_value[2] - sm_new_value[2];
        MD3C = 1; //逆时针移动
    }
    //气压2
    if (sm_steps[2] > 480) sm_speed[2] = 0; //最快速度
    else if (sm_steps[2] > 360) sm_speed[2] = 1; //
    else if (sm_steps[2] > 240) sm_speed[2] = 2; //     
    else if (sm_steps[2] > 180) sm_speed[2] = 3; //
    else if (sm_steps[2] > 120) sm_speed[2] = 4; //
    else if (sm_steps[2] > 80) sm_speed[2] = 5; //
    else if (sm_steps[2] > 60) sm_speed[2] = 6; //
    else if (sm_steps[2] > 45) sm_speed[2] = 7; //
    else if (sm_steps[2] > 30) sm_speed[2] = 8; //120ms
    else if (sm_steps[2] > 20) sm_speed[2] = 10; //300ms
    else if (sm_steps[2] > 12) sm_speed[2] = 15; //120ms
    else if (sm_steps[2] > 6) sm_speed[2] = 25; //150ms
    else sm_speed[2] = 35; //210ms
    //机油压力表
    /*if (sm_steps[2] > 480) sm_speed[2] = 5; //最快速度
    else if (sm_steps[2] > 360) sm_speed[2] = 10; //
    else if (sm_steps[2] > 240) sm_speed[2] = 20; //     
    else if (sm_steps[2] > 180) sm_speed[2] = 30; //
    else if (sm_steps[2] > 120) sm_speed[2] = 40; //
    else if (sm_steps[2] > 80) sm_speed[2] = 50; //
    else if (sm_steps[2] > 60) sm_speed[2] = 60; //
    else if (sm_steps[2] > 45) sm_speed[2] = 70; //
    else if (sm_steps[2] > 30) sm_speed[2] = 80; //120ms
    else if (sm_steps[2] > 20) sm_speed[2] = 90; //300ms
    else if (sm_steps[2] > 12) sm_speed[2] = 100; //120ms
    else if (sm_steps[2] > 6) sm_speed[2] = 110; //150ms
    else sm_speed[2] = 120; //210ms
    */
}

void SM_Update_3(void) {//油量表
    if (sm_new_value[3] >= sm_old_value[3]) {
        sm_steps[3] = sm_new_value[3] - sm_old_value[3];
        MD4C = 0; //逆时针移动
    } else {
        sm_steps[3] = sm_old_value[3] - sm_new_value[3];
        MD4C = 1; //顺时针移动
    }
    if (sm_steps[3] > 480) sm_speed[3] = 5; //最快速度
    else if (sm_steps[3] > 360) sm_speed[3] = 10; //
    else if (sm_steps[3] > 240) sm_speed[3] = 20; //     
    else if (sm_steps[3] > 180) sm_speed[3] = 30; //
    else if (sm_steps[3] > 120) sm_speed[3] = 40; //
    else if (sm_steps[3] > 80) sm_speed[3] = 50; //
    else if (sm_steps[3] > 60) sm_speed[3] = 60; //
    else if (sm_steps[3] > 45) sm_speed[3] = 70; //
    else if (sm_steps[3] > 30) sm_speed[3] = 80; //120ms
    else if (sm_steps[3] > 20) sm_speed[3] = 90; //300ms
    else if (sm_steps[3] > 12) sm_speed[3] = 100; //120ms
    else if (sm_steps[3] > 6) sm_speed[3] = 110; //150ms
    else sm_speed[3] = 120; //210ms
}

void SM_Update_4(void) {//水温表//气压1
    if (sm_new_value[4] >= sm_old_value[4]) {
        sm_steps[4] = sm_new_value[4] - sm_old_value[4];
        MD5C = 0; //顺时针移动
    } else {
        sm_steps[4] = sm_old_value[4] - sm_new_value[4];
        MD5C = 1; //逆时针移动
    }
    //气压1
    if (sm_steps[4] > 480) sm_speed[4] = 0; //最快速度
    else if (sm_steps[4] > 360) sm_speed[4] = 1; //
    else if (sm_steps[4] > 240) sm_speed[4] = 2; //     
    else if (sm_steps[4] > 180) sm_speed[4] = 3; //
    else if (sm_steps[4] > 120) sm_speed[4] = 4; //
    else if (sm_steps[4] > 80) sm_speed[4] = 5; //
    else if (sm_steps[4] > 60) sm_speed[4] = 6; //
    else if (sm_steps[4] > 45) sm_speed[4] = 7; //
    else if (sm_steps[4] > 30) sm_speed[4] = 8; //120ms
    else if (sm_steps[4] > 20) sm_speed[4] = 10; //300ms
    else if (sm_steps[4] > 12) sm_speed[4] = 15; //120ms
    else if (sm_steps[4] > 6) sm_speed[4] = 25; //150ms
    else sm_speed[4] = 35; //210ms
    //水温表
    /*if (sm_steps[4] > 480) sm_speed[4] = 5; //最快速度
    else if (sm_steps[4] > 360) sm_speed[4] = 10; //
    else if (sm_steps[4] > 240) sm_speed[4] = 20; //     
    else if (sm_steps[4] > 180) sm_speed[4] = 30; //
    else if (sm_steps[4] > 120) sm_speed[4] = 40; //
    else if (sm_steps[4] > 80) sm_speed[4] = 50; //
    else if (sm_steps[4] > 60) sm_speed[4] = 60; //
    else if (sm_steps[4] > 45) sm_speed[4] = 70; //
    else if (sm_steps[4] > 30) sm_speed[4] = 80; //120ms
    else if (sm_steps[4] > 20) sm_speed[4] = 90; //300ms
    else if (sm_steps[4] > 12) sm_speed[4] = 100; //120ms
    else if (sm_steps[4] > 6) sm_speed[4] = 110; //150ms
    else sm_speed[4] = 120; //210ms
    */
}

void SM_Update_5(void) {//转速表
    if (sm_new_value[5] >= sm_old_value[5]) {
        sm_steps[5] = sm_new_value[5] - sm_old_value[5];
        MD6C = 0; //顺时针移动
    } else {
        sm_steps[5] = sm_old_value[5] - sm_new_value[5];
        MD6C = 1; //逆时针移动
    }
    if (sm_steps[5] > 480) sm_speed[5] = 0; //最快速度
    else if (sm_steps[5] > 360) sm_speed[5] = 1; //
    else if (sm_steps[5] > 240) sm_speed[5] = 2; //     
    else if (sm_steps[5] > 180) sm_speed[5] = 3; //
    else if (sm_steps[5] > 120) sm_speed[5] = 4; //
    else if (sm_steps[5] > 80) sm_speed[5] = 5; //
    else if (sm_steps[5] > 60) sm_speed[5] = 6; //
    else if (sm_steps[5] > 45) sm_speed[5] = 7; //
    else if (sm_steps[5] > 30) sm_speed[5] = 8; //120ms
    else if (sm_steps[5] > 20) sm_speed[5] = 10; //300ms
    else if (sm_steps[5] > 12) sm_speed[5] = 15; //120ms
    else if (sm_steps[5] > 6) sm_speed[5] = 25; //150ms
    else sm_speed[5] = 35; //210ms	

}

void SM_Reset(void) {
    unsigned int i = 0;

    MD1C = 1;
    MD2C = 1;
    MD3C = 1;
    MD4C = 1;
    MD5C = 1;
    MD6C = 1;
    for (i = 0; i < 6; i++) {
        sm_steps[i] = 0;
        sm_new_value[i] = 0;
        sm_old_value[i] = 0;
    }
    for (i = 0; i < 1000; i++) {
        MD1F = 0;
        MD2F = 0;
        MD3F = 0;
        MD4F = 0;
        MD5F = 0;
        MD6F = 0;
        __delay_us(400);
        MD1F = 1;
        MD2F = 1;
        MD3F = 1;
        MD4F = 1;
        MD5F = 1;
        MD6F = 1;
    }
}

//步进电机归零

void SM_Zero(void) {
    unsigned int i = 0;
    MD1C = 1;
    MD2C = 1;
    MD3C = 1;
    MD4C = 1;
    MD5C = 1;
    MD6C = 1;
    for (i = 0; i < 6; i++) {
        sm_steps[i] = sm_old_value[i];
        sm_new_value[i] = 0;
        sm_speed[i] = 0; //最快速度    
    }
}

//定时器4中断-----1ms中断一次
void __attribute__((__interrupt__, auto_psv)) _T4Interrupt(void) {
    static unsigned char speed[6] = {0, 0, 0, 0, 0, 0};

    if (sm_steps[0] > 0) {
        if (speed[0] >= sm_speed[0]) {
            MD1F = 1;
            speed[0] = 0;
            MD1F = 0;
            if (MD1C) {
                if (sm_old_value[0] > 0) sm_old_value[0]--;
            } else {
                sm_old_value[0]++;
            }
        } else speed[0]++;
    } else speed[0] = 0;


    if (sm_steps[1] > 0) {
        if (speed[1] >= sm_speed[1]) {
            MD2F = 1;
            speed[1] = 0;
            MD2F = 0;
            if (MD2C) {
                if (sm_old_value[1] > 0) sm_old_value[1]--;
            } else {
                sm_old_value[1]++;
            }
        } else speed[1]++;
    } else speed[1] = 0;

    if (sm_steps[2] > 0) {
        if (speed[2] >= sm_speed[2]) {
            MD3F = 1;
            speed[2] = 0;
            MD3F = 0;
            if (MD3C) {
                if (sm_old_value[2] > 0) sm_old_value[2]--;
            } else {
                sm_old_value[2]++;
            }
        } else speed[2]++;
    } else speed[2] = 0;

    if (sm_steps[3] > 0) {
        if (speed[3] >= sm_speed[3]) {
            MD4F = 1;
            speed[3] = 0;
            MD4F = 0;
            if (MD4C) {
                if (sm_old_value[3] > 0) sm_old_value[3]--;
            } else {
                sm_old_value[3]++;
            }
        } else speed[3]++;
    } else speed[3] = 0;

    if (sm_steps[4] > 0) {
        if (speed[4] >= sm_speed[4]) {
            MD5F = 1;
            speed[4] = 0;
            MD5F = 0;
            if (MD5C) {
                if (sm_old_value[4] > 0) sm_old_value[4]--;
            } else {
                sm_old_value[4]++;
            }
        } else speed[4]++;
    } else speed[4] = 0;


    if (sm_steps[5] > 0) {
        if (speed[5] >= sm_speed[5]) {
            MD6F = 1;
            speed[5] = 0;
            MD6F = 0;
            if (MD6C) {
                if (sm_old_value[5] > 0) sm_old_value[5]--;
            } else {
                sm_old_value[5]++;
            }
        } else speed[5]++;
    } else speed[5] = 0;

    _T4IF = 0;
}



