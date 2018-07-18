#include "SYSTEM.h"
#include "FONT.h"
//#include "LOGO.h"

unsigned char Index = 0;
unsigned char t = 0;
unsigned char frmID = 0;
unsigned char f_index = 0;
unsigned char menuid = 0;
unsigned char AV_CH = 0;
unsigned char color_old[24] = {};

void print_SZ(unsigned int x, unsigned int y, //显示坐标位置 
        unsigned long dat, //显示的数据 
        unsigned char sum, //显示数据的几位
        unsigned char dot, //显示小数点的位数
        unsigned char color1) { //显示数据的颜色
    unsigned char color, f = 1, i = 0;
    unsigned char bcd[8];
    for (i = 0; i < sum; i++) {
        bcd[sum - i - 1] = dat % 10;
        dat = dat / 10;
    }
    for (i = 0; i < dot; i++) {
        bcd[sum - i] = bcd[sum - 1 - i];
    }
    bcd[sum - dot] = 16; //加入小数点  
    if (dot > 0) {
        for (i = 0; i <= sum; i++) {
            if (f && (bcd[i] == 0)&&(i < sum - 1 - dot)) { //不显示前面0
                f = 1;
                color = BLACK;
            } else {
                f = 0;
                color = color1;
            }
            LCD_DrawImage1BPP(x + i * 8, y, BMP_SZ[bcd[i]], color, BLACK);
        }
    } else {
        for (i = 0; i < sum; i++) {
            if (f && (bcd[i] == 0)&&(i < sum - 1)) { //不显示前面0
                f = 1;
                color = BLACK;
            } else {
                f = 0;
                color = color1;
            }
            LCD_DrawImage1BPP(x + i * 8, y, BMP_SZ[bcd[i]], color, BLACK);
        }
    }
}

void print_SZ_1(unsigned int x, unsigned int y, //显示坐标位置//高清数字
        unsigned long dat, //显示的数据 
        unsigned char sum, //显示数据的几位
        unsigned char dot, //显示小数点的位数
        unsigned char color1) { //显示数据的颜色
    unsigned char color, f = 1, i = 0;
    unsigned char bcd[8];
    for (i = 0; i < sum; i++) {
        bcd[sum - i - 1] = dat % 10;
        dat = dat / 10;
    }
    for (i = 0; i < dot; i++) {
        bcd[sum - i] = bcd[sum - 1 - i];
    }
    bcd[sum - dot] = 16; //加入小数点  
    if (dot > 0) {
        for (i = 0; i <= sum; i++) {
            if (f && (bcd[i] == 0)&&(i < sum - 1 - dot)) { //不显示前面0
                f = 1;
                color = BLACK;
            } else {
                f = 0;
                color = color1;
            }
            LCD_DrawImage1BPP(x + i * 16, y, BMP_SZ_1[bcd[i]], color, BLACK);
        }
    } else {
        for (i = 0; i < sum; i++) {
            if (f && (bcd[i] == 0)&&(i < sum - 1)) { //不显示前面0
                f = 1;
                color = BLACK;
            } else {
                f = 0;
                color = color1;
            }
            LCD_DrawImage1BPP(x + i * 16, y, BMP_SZ_1[bcd[i]], color, BLACK);
        }
    }
}

/*
void print_SZ_4(unsigned int x, unsigned int y, //显示坐标位置 //放大4倍数字
        unsigned long dat, //显示的数据 
        unsigned char sum, //显示数据的几位
        unsigned char dot, //显示小数点的位数
        unsigned char color1) { //显示数据的颜色
    unsigned char color, f = 1, i = 0;
    unsigned char bcd[8];
    for (i = 0; i < sum; i++) {
        bcd[sum - i - 1] = dat % 10;
        dat = dat / 10;
    }
    for (i = 0; i < dot; i++) {
        bcd[sum - i] = bcd[sum - 1 - i];
    }
    bcd[sum - dot] = 16; //加入小数点  
    if (dot > 0) {
        for (i = 0; i <= sum; i++) {
            if (f && (bcd[i] == 0)&&(i < sum - 1 - dot)) { //不显示前面0
                f = 1;
                color = BLACK;
            } else {
                f = 0;
                color = color1;
            }
            LCD_DrawImage1BPPZOOM_4(x + i * 16, y, BMP_SZ[bcd[i]], color, BLACK);
        }
    } else {
        for (i = 0; i < sum; i++) {
            if (f && (bcd[i] == 0)&&(i < sum - 1)) { //不显示前面0
                f = 1;
                color = BLACK;
            } else {
                f = 0;
                color = color1;
            }
            LCD_DrawImage1BPPZOOM_4(x + i * 16, y, BMP_SZ[bcd[i]], color, BLACK);
        }
    }
}
 */
void print_D(unsigned int x, unsigned int y, //以2进制显示
        unsigned char dat) { //显示的数据       
    unsigned char bcd[8], i = 0;
    for (i = 0; i < 8; i++) {
        bcd[i] = dat % 2;
        dat = dat / 2;
        LCD_DrawImage1BPP(x + 16 * (7 - i), y, BMP_SZ_1[bcd[i]], WHITE, BLACK);
    }
}

void print_H(unsigned int x, unsigned int y, //以16进制显示
        unsigned long dat, //显示的数据 
        unsigned char sum, //显示数据的几位
        unsigned char dot, //显示小数点的位数
        unsigned char color1) { //显示数据的颜色
    unsigned char color, f = 1, i = 0;
    unsigned char bcd[8];
    for (i = 0; i < sum; i++) {
        bcd[sum - i - 1] = dat % 16;
        dat = dat / 16;
    }
    for (i = 0; i < dot; i++) {
        bcd[sum - i] = bcd[sum - 1 - i];
    }
    bcd[sum - dot] = 16; //加入小数点  
    if (dot > 0) {
        for (i = 0; i <= sum; i++) {
            if (f && (bcd[i] == 0)&&(i < sum - 1 - dot)) { //不显示前面0
                f = 1;
                color = BLACK;
            } else {
                f = 0;
                color = color1;
            }
            LCD_DrawImage1BPP(x + i * 16, y, BMP_SZ_1[bcd[i]], color, BLACK);
        }
    } else {
        for (i = 0; i < sum; i++) {
            if (f && (bcd[i] == 0)&&(i < sum - 1)) { //不显示前面0
                f = 1;
                color = BLACK;
            } else {
                f = 0;
                color = color1;
            }
            LCD_DrawImage1BPP(x + i * 16, y, BMP_SZ_1[bcd[i]], color, BLACK);
        }
    }
}

//主界面

/*********************************************************
//函数名: void mainFrame(void)
//功能: 显示主界面不需要更新的内容,界面格式
//参数: 无
 *********************************************************/
void mainFrame(void) {
    unsigned int i;
    LCD_Clear();
    LCD_DrawRect(0, 0, 800, 1, GRAY);
    LCD_DrawRect(0, 64, 800, 1, GRAY);
    for (i = 1; i < 12; i++) {
        LCD_DrawRect(4 + 66 * i, 0, 1, 64, GRAY);
    }
    //新增加的符号片框架2016/11/1
    LCD_DrawRect(136, 128, 528, 1, GRAY);
    for (i = 1; i < 10; i++) {
        LCD_DrawRect(70 + 66 * i, 64, 1, 64, GRAY);
    }
    //每次进入主界面，符号片颜色都是灰色，若不处理，只会第一次上电显示灰色，翻页后就不显示灰色
    for (i = 0; i < 24; i++) {
        color_old[i] = 0;
    }
    LCD_DrawRect(0, 430, 800, 1, WHITE); //底部横线
    //LCD_DrawRect(0,70,800,3,YELLOW); //顶部横线
    // LCD_DrawImage1BPPZOOM_4(336, 150, BMP_LOGO, BLUE, BLACK); //客车车标
    //动力电池电流 电压 SOC 外观
    LCD_DrawImage1BPP(175, 160, BMP_Voltage, WHITE, BLACK); //电压
    LCD_DrawRect(225, 150 + 5, 335, 2, WHITE);
    LCD_DrawRect(225, 150 + 35, 335, 2, WHITE);
    LCD_DrawRect(225, 155, 2, 32, WHITE);
    LCD_DrawRect(225 + 83, 145, 2, 10, WHITE);
    LCD_DrawRect(225 + 83 + 83, 145, 2, 10, WHITE);
    LCD_DrawRect(225 + 83 + 83 + 83, 145, 2, 10, WHITE);
    LCD_DrawRect(225 + 83 + 83 + 83 + 84, 155, 2, 32, WHITE);
    LCD_DrawImage1BPP(225 - 4, 155 - 14, BMP_SZ[0], WHITE, BLACK); //0
    LCD_DrawImage1BPP(225 + 83 + 83 + 83 + 84 - 12, 155 - 14, BMP_SZ[8], WHITE, BLACK); //8
    LCD_DrawImage1BPP(225 + 83 + 83 + 83 + 84 - 4, 155 - 14, BMP_SZ[0], WHITE, BLACK); //0
    LCD_DrawImage1BPP(225 + 83 + 83 + 83 + 84 + 4, 155 - 14, BMP_SZ[0], WHITE, BLACK); //0   
    LCD_DrawImage1BPP(660, 155, BMP_V, WHITE, BLACK);

    LCD_DrawImage1BPP(175, 160 + 60, BMP_Current, WHITE, BLACK); //电流
    LCD_DrawRect(225, 150 + 5 + 60, 335, 2, WHITE);
    LCD_DrawRect(225, 150 + 35 + 60, 335, 2, WHITE);
    LCD_DrawRect(225, 155 + 60, 2, 32, WHITE);
    LCD_DrawRect(225 + 83, 145 + 60, 2, 10, WHITE);
    LCD_DrawRect(225 + 83 + 83 + 83, 145 + 60, 2, 10, WHITE);
    LCD_DrawRect(225 + 83 + 83 + 83 + 83 + 1, 155 + 60, 2, 32, WHITE);
    LCD_DrawRect(225 - 12, 155 - 14 + 60 + 7, 8, 2, WHITE); //-
    LCD_DrawImage1BPP(225 - 4, 155 - 14 + 60, BMP_SZ[5], WHITE, BLACK); //5
    LCD_DrawImage1BPP(225 + 4, 155 - 14 + 60, BMP_SZ[0], WHITE, BLACK); //0
    LCD_DrawImage1BPP(225 + 12, 155 - 14 + 60, BMP_SZ[0], WHITE, BLACK); //0

    LCD_DrawImage1BPP(225 + 83 + 83 - 4, 145 + 60 - 4, BMP_SZ[0], WHITE, BLACK); //0
    LCD_DrawRect(225 + 83 + 83, 155 + 60, 2, 32, WHITE);

    LCD_DrawImage1BPP(225 + 83 + 83 + 83 + 84 - 12, 155 - 14 + 60, BMP_SZ[5], WHITE, BLACK); //5
    LCD_DrawImage1BPP(225 + 83 + 83 + 83 + 84 - 4, 155 - 14 + 60, BMP_SZ[0], WHITE, BLACK); //0
    LCD_DrawImage1BPP(225 + 83 + 83 + 83 + 84 + 4, 155 - 14 + 60, BMP_SZ[0], WHITE, BLACK); //0
    LCD_DrawImage1BPP(660, 155 + 60, BMP_A, WHITE, BLACK);

    LCD_DrawImage1BPP(170, 150 + 5 + 60 + 60, BMP_SOC, WHITE, BLACK); //SOC
    LCD_DrawRect(225, 150 + 5 + 60 + 60, 335, 2, WHITE);
    LCD_DrawRect(225, 150 + 35 + 60 + 60, 335, 2, WHITE);
    LCD_DrawRect(225, 155 + 60 + 60, 2, 32, WHITE);
    LCD_DrawRect(225 + 83, 145 + 60 + 60, 2, 10, WHITE);
    LCD_DrawRect(225 + 83 + 83, 145 + 60 + 60, 2, 10, WHITE);
    LCD_DrawRect(225 + 83 + 83 + 83, 145 + 60 + 60, 2, 10, WHITE);
    LCD_DrawRect(225 + 83 + 83 + 83 + 84, 155 + 60 + 60, 2, 32, WHITE);
    LCD_DrawImage1BPP(225 - 4, 155 - 14 + 60 + 60, BMP_SZ[0], WHITE, BLACK); //0
    LCD_DrawImage1BPP(225 + 83 + 83 + 83 + 84 - 12, 155 - 14 + 60 + 60, BMP_SZ[1], WHITE, BLACK); //1
    LCD_DrawImage1BPP(225 + 83 + 83 + 83 + 84 - 4, 155 - 14 + 60 + 60, BMP_SZ[0], WHITE, BLACK); //0
    LCD_DrawImage1BPP(225 + 83 + 83 + 83 + 84 + 4, 155 - 14 + 60 + 60, BMP_SZ[0], WHITE, BLACK); //0
    LCD_DrawImage1BPP(660, 155 + 60 + 60, BMP_BAIFENHAO, WHITE, BLACK);

    LCD_DrawImage1BPP(180 - 20 + 2, 365 - 50 + 10, BMP_DJ, WHITE, BLACK); //电机
    LCD_DrawImage1BPP(180 - 20 + 2 + 43, 365 - 50 + 10, BMP_KZQ, WHITE, BLACK); //控制器
    //LCD_DrawImage1BPP(180 - 20 + 2 + 43 + 64, 365 - 50 + 10, BMP_Wendu, WHITE, BLACK); //温度
    LCD_DrawImage1BPP(225 + 83 + 83 - 22, 365 - 50 + 10, BMP_T, WHITE, BLACK); //℃

    LCD_DrawImage1BPP(225 + 83 + 83 + 2, 365 - 50 + 10, BMP_DJ, WHITE, BLACK); //电机
    LCD_DrawImage1BPP(225 + 83 + 83 + 2 + 43, 365 - 50 + 10, BMP_Zhuansu, WHITE, BLACK); //转速
    LCD_DrawImage1BPP(615 - 34, 365 - 50 + 10, BMP_RPM, WHITE, BLACK); //RPM

    LCD_DrawImage1BPP(180 - 20 + 2, 365 - 50 + 10 + 38, BMP_Niaosu, WHITE, BLACK); //尿素
    LCD_DrawImage1BPP(180 - 20 + 2 + 43, 365 - 50 + 10 + 38, BMP_Yewei, WHITE, BLACK); //液位
    LCD_DrawImage1BPP(225 + 83 + 83 - 12, 365 - 50 + 10 + 38, BMP_Baifenhao, WHITE, BLACK); //%

    LCD_DrawImage1BPP(225 + 83 + 83 + 2, 365 - 50 + 10 + 38, BMP_System, WHITE, BLACK); //系统
    LCD_DrawImage1BPP(225 + 83 + 83 + 2 + 43, 365 - 50 + 10 + 38, BMP_Code, WHITE, BLACK); //代码

    //框框
    LCD_DrawRect(180 - 20, 365 - 50, 350 + 85 + 20, 1, WHITE);
    LCD_DrawRect(180 - 20, 365 - 50, 1, 65 + 50, WHITE);
    LCD_DrawRect(225 + 83 + 83, 365 - 50, 1, 65 + 50 - 38, WHITE);
    LCD_DrawRect(615, 365 - 50, 1, 65 + 50, WHITE);
    LCD_DrawRect(180 - 20, 365 - 50 + 38, 350 + 85 + 20, 1, WHITE);
    LCD_DrawRect(180 - 20, 365 - 50 + 38 + 38, 350 + 85 + 20, 1, WHITE);

    //LCD_DrawImage1BPPZOOM_4(100, 150 + 70 + 60 + 45 + 50, BMP_DW, WHITE, BLACK); //档位

    //气压柱1外观
    //方框
    LCD_DrawRect(33, 100, 50, 3, WHITE); //
    LCD_DrawRect(33, 100, 3, 135, WHITE);
    LCD_DrawRect(83, 100, 3, 135, WHITE);

    LCD_DrawRect(33, 235, 3, 135, RED);
    LCD_DrawRect(83, 235, 3, 138, RED);
    LCD_DrawRect(33, 370, 50, 3, RED); //

    //标尺
    LCD_DrawImage1BPP(13, 95, BMP_SZ[1], RED, BLACK); //1
    LCD_DrawImage1BPP(21, 95, BMP_SZ[0], RED, BLACK); //0
    LCD_DrawImage1BPP(21, 225, BMP_SZ[5], RED, BLACK); //5
    LCD_DrawImage1BPP(21, 360, BMP_SZ[0], RED, BLACK); //0

    LCD_DrawImage1BPP(33 - 7 + 32, 410, Bmp_Mpa, WHITE, BLACK); //Mpa

    //气压柱2外观
    LCD_DrawRect(712, 100, 50, 3, WHITE);
    LCD_DrawRect(712, 100, 3, 135, WHITE);
    LCD_DrawRect(712 + 50, 100, 3, 135, WHITE);

    LCD_DrawRect(712, 235, 3, 135, RED);
    LCD_DrawRect(712 + 50, 235, 3, 138, RED);
    LCD_DrawRect(712, 370, 50, 3, RED); //

    LCD_DrawImage1BPP(770, 95, BMP_SZ[1], RED, BLACK); //1
    LCD_DrawImage1BPP(770 + 8, 95, BMP_SZ[0], RED, BLACK); //0
    LCD_DrawImage1BPP(770, 225, BMP_SZ[5], RED, BLACK); //5
    LCD_DrawImage1BPP(770, 360, BMP_SZ[0], RED, BLACK); //0 

    LCD_DrawImage1BPP(712 - 7 + 32, 410, Bmp_Mpa, WHITE, BLACK); //Mpa

    /*--------------------------------------------
    以下显示的格式为:(ODO 000.0Km       00:00          TRIP0000000Km)
    ---------------------------------------------*/
    LCD_DrawImage1BPP(2, 440 + 3, Bmp_ODO, YELLOW, BLACK); //累计里程 ODO  
    //print_SZ_4(2+64+4,440,9999999,7,1,WHITE);

    LCD_DrawImage1BPPZOOM_4(210, 440, BMP_HZ_KM, WHITE, BLACK); //单位 Km

    LCD_DrawImage1BPP(240 + 300 + 30, 440 + 3, Bmp_TRIP, YELLOW, BLACK); //单次里程 TRIF
    //print_SZ_4(240+80+4,440,9999,4,1,WHITE);
    LCD_DrawImage1BPPZOOM_4(404 + 336 + 30, 440, BMP_HZ_KM, WHITE, BLACK); //单位 Km

}

void disp_miles(void) {//显示里程
    print_SZ_1(2 + 64 + 4 + 10, 440 - 2, total_miles, 7, 1, WHITE);
    print_SZ_1(240 + 80 + 4 + 330 + 30, 440 - 2, single_miles, 4, 1, WHITE);
}

void disp_time(unsigned int x, unsigned int y, DATE dtimer) {
    unsigned char color = 0;
    static unsigned char color_back=0;
    //    if(Did==0) color=RED;
    //    else       color=WHITE;
    if(color_back && (t==0)) {
        if (key_AV) {//小时设置，十位
            timer.hour = timer.hour + 0x10;
            if ((timer.hour >> 4) > 2) {
                timer.hour = timer.hour & 0x0f;
            }
            DS3231_SetTime(&timer);
            key_AV = 0;
            key_long_set = 0;
            key_up = 0;
            key_set = 0;
        }
    LCD_DrawImage1BPP(x, y, BMP_SMSZ[(dtimer.hour >> 4)&0x0f], WHITE, GRAY);
    }
    else LCD_DrawImage1BPP(x, y, BMP_SMSZ[(dtimer.hour >> 4)&0x0f], WHITE, BLACK);
    
    if(color_back && (t==1)){
        if (key_AV) {//小时设置，个位
            timer.hour = timer.hour + 0x01;
            if ((timer.hour & 0x0f) > 9) {
                timer.hour = timer.hour & 0xf0;
            }
            DS3231_SetTime(&timer);
            key_AV = 0;
            key_long_set = 0;
            key_up = 0;
            key_set = 0;
        }
        LCD_DrawImage1BPP(x + 28, y, BMP_SMSZ[dtimer.hour & 0x0f], WHITE, GRAY);    
    }
    else LCD_DrawImage1BPP(x + 28, y, BMP_SMSZ[dtimer.hour & 0x0f], WHITE, BLACK);  
    
    if(color_back && (t==2)){
        if (key_AV) {//分钟设置，十位
            timer.minute = timer.minute + 0x10;
            if ((timer.minute >> 4) > 5) {
                timer.minute = timer.minute & 0x0f;
            }
            DS3231_SetTime(&timer);
            key_AV = 0;
            key_long_set = 0;
            key_up = 0;
            key_set = 0;
        }
    LCD_DrawImage1BPP(x + 28 * 3, y, BMP_SMSZ[(dtimer.minute >> 4)&0x0f], WHITE, GRAY);
    }
    else LCD_DrawImage1BPP(x + 28 * 3, y, BMP_SMSZ[(dtimer.minute >> 4)&0x0f], WHITE, BLACK);
        
    if(color_back && (t==3)){    
        if (key_AV) {//分钟设置，个位
            timer.minute = timer.minute + 0x01;
            if ((timer.minute & 0x0f) > 9) {
                timer.minute = timer.minute & 0xf0;
            }
            DS3231_SetTime(&timer);
            key_AV = 0;
            key_long_set = 0;
            key_up = 0;
            key_set = 0;
        }
    LCD_DrawImage1BPP(x + 28 * 4, y, BMP_SMSZ[dtimer.minute & 0x0f], WHITE, GRAY);
    }
    else LCD_DrawImage1BPP(x + 28 * 4, y, BMP_SMSZ[dtimer.minute & 0x0f], WHITE, BLACK);
   
    if (F500ms_LCD) color = WHITE;
    else color = BLACK;
    LCD_DrawImage1BPP(x + 28 * 2, y + 3, BMP_SMSZ[10], color, BLACK); //冒号 
    
    if(time_flag){
        color_back=FLASH;
    }
    else {
        color_back=0;
        t=0;
    }          
    
    /*****************年月日不显示**********************/
    /*
    LCD_DrawImage1BPPZOOM_4(610, 440, BMP_SZ[2], WHITE, BLACK); //2
    LCD_DrawImage1BPPZOOM_4(610 + 18 * 1, 440, BMP_SZ[0], WHITE, BLACK); //0
    LCD_DrawImage1BPPZOOM_4(610 + 18 * 2, 440, BMP_SZ[(dtimer.year >> 4)&0x0f], WHITE, BLACK); //年
    LCD_DrawImage1BPPZOOM_4(610 + 18 * 3, 440, BMP_SZ[dtimer.year & 0x0f], WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(610 + 18 * 4, 440, BMP_SZ[17], WHITE, BLACK); //-
    LCD_DrawImage1BPPZOOM_4(610 + 18 * 5, 440, BMP_SZ[(dtimer.month >> 4)&0x0f], WHITE, BLACK); //月
    LCD_DrawImage1BPPZOOM_4(610 + 18 * 6, 440, BMP_SZ[dtimer.month & 0x0f], WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(610 + 18 * 7, 440, BMP_SZ[17], WHITE, BLACK); //-
    LCD_DrawImage1BPPZOOM_4(610 + 18 * 8, 440, BMP_SZ[(dtimer.day >> 4)&0x0f], WHITE, BLACK); //日
    LCD_DrawImage1BPPZOOM_4(610 + 18 * 9, 440, BMP_SZ[dtimer.day & 0x0f], WHITE, BLACK);
     */
}

void disp_baojing(void) {
    unsigned char color = GRAY;

    if (IN26 && M_ON) color = YELLOW;
    else color = GRAY;
    if (color_old[0] != color) {
        color_old[0] = color;
        LCD_DrawImage1BPP(6, 10, Bmp_baojing[1], color, BLACK); //ABS
    }

    if (IN8 && M_ON) color = RED;
    else color = GRAY;
    if (color_old[1] != color) {
        color_old[1] = color;
        LCD_DrawImage1BPP(6 + 66, 10, Bmp_baojing[2], color, BLACK); //前门开
    }

    if (IN9 && M_ON) color = RED;
    else color = GRAY;
    if (color_old[2] != color) {
        color_old[2] = color;
        LCD_DrawImage1BPP(6 + 66 * 2, 10, Bmp_baojing[3], color, BLACK); //后门开
    }

    if (Charge_Check) color = YELLOW;
    else color = GRAY;
    if (color_old[3] != color) {
        color_old[3] = color;
        LCD_DrawImage1BPP(6 + 66 * 3, 10, Bmp_baojing[9], color, BLACK); //充电确认
    }

    if (IN14 && M_ON) color = GREEN;
    else color = GRAY;
    if (color_old[4] != color) {
        color_old[4] = color;
        LCD_DrawImage1BPP(6 + 66 * 4, 10, Bmp_baojing[4], color, BLACK); //干燥
    }

    if (Warn_level ||
       ((IN22 || IN23 || (Engine_oil_press * 4 <= 70)) && Engine_Speed > 0) ||
       (water_temp > 138))
        color = RED;
    else color = GRAY;
    if (color_old[5] != color) {
        color_old[5] = color;
        LCD_DrawImage1BPP(6 + 66 * 5, 10+8, Bmp_STOP, color, BLACK); //红色STOP
        
    }

    if (IN18 && M_ON) color = YELLOW;
    else color = GRAY;
    if (color_old[6] != color) {
        color_old[6] = color;
        LCD_DrawImage1BPP(6 + 66 * 6, 10, Bmp_baojing[5], color, BLACK); //空滤
    }

    if (IN2 && M_ON) color = GREEN;
    else color = GRAY;
    if (color_old[7] != color) {
        color_old[7] = color;
        LCD_DrawImage1BPP(6 + 66 * 7, 10, Bmp_baojing[16], color, BLACK); //小灯
    }

    if (IN10 && M_ON) color = RED;
    else color = GRAY;
    if (color_old[8] != color) {
        color_old[8] = color;
        LCD_DrawImage1BPP(6 + 66 * 8, 10, Bmp_baojing[7], color, BLACK); //后舱门
    }

    if (IN24 && M_ON) color = RED;
    else color = GRAY;
    if (color_old[9] != color) {
        color_old[9] = color;
        LCD_DrawImage1BPP(6 + 66 * 9, 10, Bmp_baojing[6], color, BLACK); //水位
    }

    if (IN24 || (Vcan_count == 30) ||
            (Bcan_count == 30) ||
            (Dcan_count == 30))
        color = YELLOW;
    else color = GRAY;
    if (color_old[10] != color) {
        color_old[10] = color;
        LCD_DrawImage1BPP(6 + 66 * 10, 10+8, Bmp_STOP, color, BLACK); //黄色STOP
    }

    if (AC && M_ON) color = GREEN;
    else color = GRAY;
    if (color_old[11] != color) {
        color_old[11] = color;
        LCD_DrawImage1BPP(6 + 66 * 11, 10, Bmp_baojing[11], color, BLACK); //AC空调
    }
    
    if (Tradition && !Hybrid && !Electric) color = GREEN;
    else color = GRAY;
    if (color_old[12] != color) {
        color_old[12] = color;
        if (color == GREEN) {
            LCD_DrawImage1BPP(138 + 9, 74, BMP_Chuantong, color, BLACK); //传统
            LCD_DrawImage1BPP(138 + 9, 74 + 22, BMP_Mode, color, BLACK); //模式
        }
    }

    if (!Tradition && Hybrid && !Electric) color = GREEN;
    else color = GRAY;
    if (color_old[13] != color) {
        color_old[13] = color;
        if (color == GREEN) {
            LCD_DrawImage1BPP(138 + 9, 74 , BMP_Chadian, color, BLACK); //插电
            LCD_DrawImage1BPP(138 + 9, 74 + 22, BMP_Mode, color, BLACK); //模式
        }
    }

    if (!Tradition && !Hybrid && Electric) color = GREEN;
    else color = GRAY;
    if (color_old[14] != color) {
        color_old[14] = color;
        if (color == GREEN) {
            LCD_DrawImage1BPP(138 + 9, 74, BMP_Chundian, color, BLACK); //纯电
            LCD_DrawImage1BPP(138 + 9, 74 + 22, BMP_Mode, color, BLACK); //模式
        }
    }

    if (!Tradition && !Hybrid && !Electric) {
        LCD_DrawImage1BPP(138 + 9, 74, BMP_Chundian, BLACK, BLACK); //纯电
        LCD_DrawImage1BPP(138 + 9, 74 + 22, BMP_Mode, BLACK, BLACK); //模式
    }

    if (Mode_S && M_ON) color = YELLOW;
    else color = GRAY;
    if (color_old[15] != color) {
        color_old[15] = color;
        LCD_DrawImage1BPP(138 + 66 * 1, 74, Bmp_baojing[10], color, BLACK); //S
    }

    if (Kt && M_ON) color = GREEN;
    else color = GRAY;
    if (color_old[16] != color) {
        color_old[16] = color;
        LCD_DrawImage1BPP(138 + 66 * 2, 74, Bmp_baojing[12], color, BLACK); //Kt
    }

    if (High_Voltage && M_ON) color = RED;
    else color = GRAY;
    if (color_old[17] != color) {
        color_old[17] = color;
        LCD_DrawImage1BPP(138 + 66 * 3 + 9, 74, BMP_DY, color, BLACK); //电压
        LCD_DrawImage1BPP(138 + 66 * 3 + 9, 74, BMP_Gao, color, BLACK); //高        
        LCD_DrawImage1BPP(138 + 66 * 3 + 9, 74 + 20, BMP_Jianxiu, color, BLACK); //检修
    }

    if (IN15 && M_ON) color = GREEN;
    else if (moto_warn == 0) color = GRAY;
    if (color_old[18] != color) {
        color_old[18] = color;
        LCD_DrawImage1BPP(138 + 66 * 4, 74, Bmp_baojing[13], color, BLACK); //除霜
    }
  
    if ((!IN29) && M_ON) color = RED;
    else color = GRAY;
    if (color_old[19] != color) {
        color_old[19] = color;
        LCD_DrawImage1BPP(138 + 66 * 5, 74, Bmp_baojing[15], color, BLACK); //左刹车片磨损
    }
    
    if ((!IN21) && M_ON) color = RED;
    else color = GRAY;
    if (color_old[20] != color) {
        color_old[20] = color;
        LCD_DrawImage1BPP(138 + 66 * 6, 74, Bmp_baojing[14], color, BLACK); //右刹车片磨损
    }
}

void disp_CAN_baojing(unsigned int x, unsigned int y) {
    static unsigned char al_index = 0;
    if (alarm_update_flag == 0) { //3S 更新一次 
        //LCD_DrawRect(x, y, 350 + 85 + 10, 36, BLACK); //清除显示区域
        switch (al_index) {
            case 0:
                al_index = 1;
                if (Vcan_count == 30 ) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Shuiwen, YELLOW, BLACK); //水温信息丢失
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Xinxi, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Diushi, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 1:
                al_index = 2;
                if (Vcan_count == 30 ) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Jiyou, YELLOW, BLACK); //机油压力信息丢失
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Yali, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Xinxi, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 42, y + 8, BMP_Diushi, YELLOW, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
            case 2:
                al_index = 3;
                if  (Vcan_count == 30 || Bcan_count == 30 || Dcan_count == 30 ) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Zong, YELLOW, BLACK); //总线通讯异常
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_Xian, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 21, y + 8, BMP_Tongxun, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 21 + 42, y + 8, BMP_Yichang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 3:
                al_index = 4;
                if ((Engine_oil_press * 4 < 100) && M_ON) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Jiyou, YELLOW, BLACK); //机油压力低
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Yali, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Di, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 21, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 4:
                al_index = 5;
                if (IN31 && (Engine_Speed > 0) && M_ON) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Jiyou, YELLOW, BLACK); //机油压力报警
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Yali, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 5:
                al_index = 6;
                if ((water_temp > 138)&& (Engine_Speed > 0) && M_ON) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Shuiwen, YELLOW, BLACK); //水温高
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Gao, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
            case 6:
                al_index = 7;
                if ((IN22 || IN23) && M_ON) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Qiya, YELLOW, BLACK); //气压低报警
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Di, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 21, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 21 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
            case 7:
                al_index = 8;
                if (Warn_level == 1) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Qing, YELLOW, BLACK); //请停车
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_Tingche, YELLOW, BLACK);
                    LCD_DrawRect(x + 21 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
            case 8:
                al_index = 9;
                if (pSpeed > 69) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Chaosu, YELLOW, BLACK); //超速报警
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
            case 9:
                al_index = 10;
                if (TCU_warn == 1) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Qing, YELLOW, BLACK); //请检查变速箱
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_Jiancha, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 42, y + 8, BMP_Biansuxiang, YELLOW, BLACK);
                    LCD_DrawRect(x + 21 + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
            case 10:
                al_index = 11;
                if (((Status_Flag1 >> 7)&0x01) == 1) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DC, YELLOW, BLACK); //电池均衡故障
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Junheng, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
            case 11:
                al_index = 12;
                if (((Status_Flag1 >> 6)&0x01) == 1) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Zong, YELLOW, BLACK); //总电压过压
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 42, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 42, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawRect(x + 21 + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 12:
                al_index = 13;
                if (((Status_Flag1 >> 5)&0x01) == 1) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Zong, YELLOW, BLACK); //总电压欠压
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 42, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 42, y + 8, BMP_Qian, YELLOW, BLACK);
                    LCD_DrawRect(x + 21 + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 13:
                al_index = 14;
                if (((Status_Flag1 >> 4)&0x01) == 1) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DC, YELLOW, BLACK); //电池通讯故障
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Tongxun, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 14:
                al_index = 15;
                if (((Status_Flag1 >> 3)&0x01) == 1) {
                    LCD_DrawImage1BPP(x, y+8, BMP_s, YELLOW, BLACK); //SOC过低
                    LCD_DrawImage1BPP(x + 11, y+8, BMP_o, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11, y+8, BMP_c, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + +11 + 11 + 11, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11 + 11 + 21, y + 8, BMP_Di, YELLOW, BLACK);
                    LCD_DrawRect(x + 11 + 11 + 11 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 15:
                al_index = 16;
                if (((Status_Flag1 >> 2)&0x01) == 1) {
                    LCD_DrawImage1BPP(x, y+8, BMP_s, YELLOW, BLACK); //SOC过高
                    LCD_DrawImage1BPP(x + 11, y+8, BMP_o, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11, y+8, BMP_c, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + +11 + 11 + 11, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11 + 11 + 21, y + 8, BMP_Gao, YELLOW, BLACK);
                    LCD_DrawRect(x + 11 + 11 + 11 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 16:
                al_index = 17;
                if (((Status_Flag1 >> 1)&0x01) == 1) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Dan, YELLOW, BLACK); //单体电压过低
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_Ti, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 21, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 21, y + 8, BMP_Di, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 17:
                al_index = 18;
                if ((Status_Flag1 & 0x01) == 1) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Dan, YELLOW, BLACK); //单体电压过高
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_Ti, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 21, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 21, y + 8, BMP_Gao, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 18:
                al_index = 19;
                if (((Status_Flag2 >> 7)&0x01) == 1) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Wendu, YELLOW, BLACK); //温差过大
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_Cha, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 21, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 21 + 21, y + 8, BMP_Da, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 19:
                al_index = 20;
                if (((Status_Flag2 >> 6)&0x01) == 1) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Wendu, YELLOW, BLACK); //温度报警
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 20:
                al_index = 21;
                if (((Status_Flag2 >> 5)&0x01) == 1) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Wendu, YELLOW, BLACK); //温度过高
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 21, y + 8, BMP_Gao, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 21:
                al_index = 22;
                if (((Status_Flag2 >> 4)&0x01) == 1) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Chong, YELLOW, BLACK); //充电电流过高
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_DL, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 21, y + 8, BMP_DL, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 21 + 42, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 21 + 41 + 21, y + 8, BMP_Da, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 22:
                al_index = 23;
                if (((Status_Flag2 >> 3)&0x01) == 1) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Fang, YELLOW, BLACK); //放电电流过高
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_DL, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 21, y + 8, BMP_DL, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 21 + 42, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 21 + 41 + 21, y + 8, BMP_Da, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 23:
                al_index = 24;
                if (((Status_Flag2 >> 2)&0x01) == 1) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Jueyuan, YELLOW, BLACK); //绝缘报警
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 24:
                al_index = 25;
                if (((Status_Flag2 >> 1)&0x01) == 1) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_d, YELLOW, BLACK); //DCDC故障报警
                    LCD_DrawImage1BPP(x + 11, y + 8, BMP_c, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11, y + 8, BMP_d, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11 + 11, y + 8, BMP_c, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11 + 11 + 11, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11 + 11 + 11 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 44 + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 25:
                al_index = 26;
                if ((Status_Flag2 & 0x01) == 1) {                    
                    LCD_DrawImage1BPP(x, y + 8, BMP_DC, YELLOW, BLACK); //电池热失控
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Re, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 21, y + 8, BMP_Shikong, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 21 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 26:
                al_index = 27;
                if (((Status_Flag3 >> 2)&0x01) == 1) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_You, YELLOW, BLACK); //有内阻偏大电池
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_Nei, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 21, y + 8, BMP_Zu, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 21 + 21, y + 8, BMP_Pian, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 21 + 21 + 21, y + 8, BMP_Da, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 21 + 21 + 21 + 21, y + 8, BMP_DC, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42 + 21, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 27:
                al_index = 0;
                if (((Status_Flag3 >> 3)&0x01) == 1) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_You, YELLOW, BLACK); //有电压偏小电池
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 21 + 21, y + 8, BMP_Pian, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 21 + 21 + 21, y + 8, BMP_Xiao, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 21 + 21 + 21 + 21, y + 8, BMP_DC, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42 + 21, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
            default:
                al_index = 0;
                LCD_DrawRect(x, y, 350 + 85 + 10, 36, BLACK); //清除显示区域
                break;
        }
    }
}

void updata_QY(void) {
    unsigned char color = RED;
    unsigned int press1 = 50; /*气压传感器量程是0-1.2Mpa ,对应为0-120 进度条0-100*/
    static int update_press1=0;
    unsigned int press2 = 90; /*气压传感器量程是0-1.2Mpa ,对应为0-120 进度条0-100*/
    static int update_press2=0;
    
    if (ADR[1] < 10) press1 = 0;
    else if (ADR[1] <= 52) press1 = (ADR[1] - 10)*0.48;
    else if (ADR[1] <= 124) press1 = (ADR[1] - 52)*0.56 + 20;
    else if (ADR[1] <= 155) press1 = (ADR[1] - 124)*0.65 + 60;
    else press1 = (ADR[1] - 155)*0.69 + 80;
    //press1 = ADR[4] / 27; //电压型采样   0-5V
    //press2 = ADR[5] / 27;//电压型采样   0-5V

    PRESS[0] = press1;
    
    //阻尼    
    if (press1 > update_press1) update_press1++;
    else if (press1 < update_press1)update_press1--;
    else update_press1 = press1;
    
    if (update_press1 > 60) color = GREEN;
    else color = RED;
    if (update_press1 > 100) update_press1 = 100;
    print_SZ(33 - 7, 410, update_press1, 3, 2, color);
    LCD_DrawImage1BPP(33 + 9, 380, Bmp_QY1, color, BLACK); //气压1图标
    LCD_DrawRect(38, 102, 44, (260 - update_press1 * 2.6), BLACK); //260/100  
    LCD_DrawRect(38, (368 - update_press1 * 2.6), 44, (update_press1 * 2.6), color);
/******************************************************************************/
    if (ADR[2] < 10) press2 = 0;
    else if (ADR[2] <= 52) press2 = (ADR[2] - 10)*0.48;
    else if (ADR[2] <= 124) press2 = (ADR[2] - 52)*0.56 + 20;
    else if (ADR[2] <= 155) press2 = (ADR[2] - 124)*0.65 + 60;
    else press2 = (ADR[2] - 155)*0.69 + 80;
    
    PRESS[1] = press2;
    
    //阻尼
    if (press2 > update_press2) update_press2++;
    else if (press2 < update_press2)update_press2--;
    else update_press2 = press2;

    if (update_press2 > 60) color = GREEN;
    else color = RED;
    if (update_press2 > 100) update_press2 = 100;
    LCD_DrawImage1BPP(712 + 9, 380, Bmp_QY2, color, BLACK); //气压2图标
    print_SZ(712 - 7, 410, update_press2, 3, 2, color);
    LCD_DrawRect(712 + 5, 102, 44, (260 - update_press2 * 2.6), BLACK); //260/100  
    LCD_DrawRect(712 + 5, (368 - update_press2 * 2.6), 44, (update_press2 * 2.6), color);

}

void updata_Dangwei(void) {
    unsigned char gear = 1;
    gear = Current_Gear;
    if (gear > 7) gear = 0;
    LCD_DrawImage1BPPZOOM_4(100 - 10, 150 + 65 + 65 + 45 + 35 + 10, BMP_DANGWEI[gear], GREEN, BLACK); //档位更新   
}

void updata_SOC(void) {
    unsigned char color = WHITE;
    unsigned char soc = 100;
    soc = BMS_SOC * 0.4;
    if (soc >= 100) soc = 100;
    if (soc > 25) color = GREEN;
    else if (soc > 0 && soc <= 25) color = RED;
    else color = BLACK;
    print_SZ_1(585, 155 + 60 + 60, soc, 3, 0, WHITE); //SOC数值
    LCD_DrawRect(225 + 2, 150 + 5 + 60 + 60 + 2, (soc * 3.31), 28, color); // 331/100  
    if (soc < 100)//当soc为100时会出错//此时函数溢出
        LCD_DrawRect((225 + 2 + soc * 3.31), 150 + 5 + 60 + 60 + 2, (331 - soc * 3.31), 28, BLACK);
}

void updata_DCDY(unsigned int x, unsigned int y) {
    //unsigned char color = GREEN;
    unsigned int DCDY = 50;
    DCDY = BMS_V * 0.1;
    if (DCDY >= 1800) DCDY = 1800;
    if (DCDY < 1000) DCDY = 1000;
    print_SZ_1(x, y, (DCDY - 1000), 3, 0, WHITE); //电池电压数值 x=120+72+30   y=150+60-2
    if (DCDY > 1000 && frmID == 0)
        LCD_DrawRect(225 + 2, 150 + 5 + 2, ((DCDY - 1000) * 3.31 * 0.125), 28, GREEN); // 331/100  
    if (DCDY < 1800 && frmID == 0)//当为100时会出错
        LCD_DrawRect((225 + 2 + (DCDY - 1000) * 3.31 * 0.125), 150 + 5 + 2, (331 - (DCDY - 1000) * 3.31 * 0.125), 28, BLACK);
}

void updata_DJDY(unsigned int x, unsigned int y) {
    unsigned int DJDY = 500;
    DJDY = moto_voltage * 0.1;
    if (DJDY < 1000) {
        //LCD_DrawImage1BPPZOOM_4(x - 40, y + 4, BMP_FU, WHITE, BLACK);
        print_SZ_1(x, y, 0, 3, 0, WHITE); //电机电压数值 x=120+72+35   y=250+60-2
    } else {
        //LCD_DrawImage1BPPZOOM_4(x - 40, y + 4, BMP_ZHENG, WHITE, BLACK);
        print_SZ_1(x, y, DJDY, 3, 0, WHITE); //电机电压数值 x=120+72+35   y=250+60-2
    }
}

void updata_DCDL(unsigned int x, unsigned int y) {
    unsigned int DCDL = 100;
    DCDL = BMS_A * 0.1;
    if (DCDL < 1000) {
        DCDL = 1000 - DCDL;
        if (DCDL > 500) DCDL = 500;
        print_SZ_1(x, y, DCDL, 3, 0, WHITE);
        LCD_DrawImage1BPPZOOM_4(x - 20, y + 4, BMP_FU, WHITE, BLACK);
        if (DCDL > 0 && frmID == 0)
            LCD_DrawRect((225 + 2 + 164 - DCDL * 1.64 * 0.2), 150 + 5 + 2 + 60, (DCDL * 1.64 * 0.2 + 1), 28, GREEN);
        if (DCDL < 500 && frmID == 0) {
            LCD_DrawRect(225 + 2, 150 + 5 + 2 + 60, (164 - DCDL * 1.64 * 0.2), 28, BLACK); // 165/100         
            LCD_DrawRect(225 + 83 + 83 + 2, 150 + 5 + 2 + 60, 165, 28, BLACK);
        }
    } else {
        DCDL = DCDL - 1000;
        if (DCDL > 500) DCDL = 500;
        LCD_DrawImage1BPPZOOM_4(x - 20, y + 4, BMP_ZHENG, WHITE, BLACK);
        print_SZ_1(x, y, DCDL, 3, 0, WHITE);
        if (DCDL > 3 && frmID == 0)
            LCD_DrawRect(225 + 83 + 83 + 2, 150 + 5 + 2 + 60, (DCDL * 1.65 * 0.2), 28, GREEN); // 如果长度为0，会出错
        if (DCDL < 500 && frmID == 0) {
            LCD_DrawRect((225 + 83 + 83 + 2 + DCDL * 1.65 * 0.2), 150 + 5 + 2 + 60, (165 - DCDL * 1.65 * 0.2), 28, BLACK);
            LCD_DrawRect(225 + 2, 150 + 5 + 2 + 60, 164, 28, BLACK);
        }
    }
}

void updata_DJDL(unsigned int x, unsigned int y) {
    unsigned char color = WHITE;
    unsigned int DJDL = 100;
    DJDL = moto_current * 0.1;
    if (DJDL < 1000) {
        print_SZ_1(x, y, 1000 - DJDL, 3, 0, color);
        LCD_DrawImage1BPPZOOM_4(x - 40, y + 4, BMP_FU, color, BLACK);
    } else {
        LCD_DrawImage1BPPZOOM_4(x - 40, y + 4, BMP_ZHENG, color, BLACK);
        print_SZ_1(x, y, DJDL, 3, 0, color); //电池电流数值 x=135+180+50+100+20+20   y=150+60-2
    }
}

void updata_T(unsigned int x, unsigned int y, unsigned char color1,
        unsigned int temp, //温度值
        float factor, //比例
        unsigned int offset) {//偏移量
    unsigned char t, color;
    color = color1;
    t = temp*factor;
    if (t < offset) {
        LCD_DrawImage1BPPZOOM_4(x - 25, y + 5, BMP_FU, color, BLACK);
        print_SZ_1(x, y, offset - t, 3, 0, color);
    } else {
        LCD_DrawImage1BPPZOOM_4(x - 25, y + 5, BMP_ZHENG, color, BLACK);
        print_SZ_1(x, y, t - offset, 3, 0, color); //电机温度  x=135+180+50+100+20+20   y=150+70+35
    }
}

void updata_RMP(unsigned int x, unsigned int y) {
    unsigned char color = WHITE;
    unsigned int rpm = 80;
    rpm = moto_speed * 0.5;
    //if (rmp < 2000) {
    // LCD_DrawImage1BPPZOOM_4(x - 25, y + 5, BMP_FU, color, BLACK);
    // print_SZ_1(x, y, 2000 - rmp, 4, 0, color); //电流数值
    // } else {
    //     LCD_DrawImage1BPPZOOM_4(x - 25, y + 5, BMP_ZHENG, color, BLACK);
    print_SZ_1(x, y, rpm, 4, 0, color); //电流数值 x=135+180+50+100+20+20   y=250+55
    // }

}

/*
void updata_Accelerator(unsigned int x, unsigned int y) {
    unsigned char color = WHITE;
    unsigned int ymtb = 80;
    ymtb = Accelerator * 4;
    if (ymtb > 1000) ymtb = 1000;
    print_SZ_1(x, y, ymtb, 4, 1, color); //电流数值 x=135+180+50+100+20+20   y=250+55


}

void updata_Brake_percent(unsigned int x, unsigned int y) {
    unsigned char color = WHITE;
    unsigned int zdtb = 80;
    zdtb = Brake_percent;
    if (zdtb > 100) zdtb = 100;
    print_SZ_1(x, y, zdtb, 3, 0, color); //电流数值 x=135+180+50+100+20+20   y=250+55


}
 */

void frmMain(void) {
    unsigned char color;
    if (f_index == 0) { //只更新一次
        f_index = 1;
        mainFrame();
    } else if (f_index == 1) {
        f_index = 2;
        updata_QY();
        print_SZ_1(313 - 32, 318 + 38, Niaosu * 4, 4, 1, WHITE); //尿素        
    } else if (f_index == 2) {
        f_index = 3;
        disp_baojing();
        updata_RMP(480 + 30, 318);
    } else if (f_index == 3) {
        f_index = 4;
        disp_miles();
        updata_DCDL(585, 155 + 60);
    } else if (f_index == 4) {
        f_index = 5;
        disp_time(330, 440, timer);
        updata_T(313, 318, WHITE, Inverter_t, 1, 40);
    } else if (f_index == 5) {
        f_index = 6;
        updata_SOC();
        updata_Dangwei();
    } else if (f_index == 6) {
        f_index = 7;
        updata_DCDY(585, 155);
        disp_CAN_baojing(162, 394);
    } else if (f_index == 7) {
        f_index = 1;
        if(TCU_code==43) {
            TCU_code=0;  
            TCU_level=0;
        }
        if(TCU_level==3||TCU_level==4)
            color=YELLOW;
        else if(TCU_level==1||TCU_level==2)
            color=RED;
        else color=GREEN;
        print_SZ_1(480 + 30 + 16, 318 + 38, TCU_code, 3, 0, color); //系统代码
    } else {
        f_index = 0;
    }

    if (AV_CH == 0) { //当在数字界面
        if (key_up) { //调节背光灯
            key_up = 0;
            if (IN2 == 1) {//背光开启
                if (e_backlight >= 1000) e_backlight = 100;
                else e_backlight += 100;
                EEROM_WriteBackLight();
            } else {
                t++;//时钟设置
                if (t == 4) t = 0;
            }
        }
        
        if (key_set) {
            key_set = 0;
            key_long_set = 0;
            key_up = 0;
            key_AV = 0;
            key_duble = 0;                                
            if(time_flag==0){
                f_index = 0;  //更新只更新一次的界面
                frmID = 1;
            }
            if(time_flag==1){
                DS3231_SetTime(&timer);
            }
            time_flag=0;
        }
        
        if (key_long_set) {
            key_long_set = 0;
            key_set = 0;
            key_up = 0;
            key_AV = 0;
            time_flag = 1;
            //f_index = 0;//更新只更新一次的界面
        }
    }
/***********************************************************/
    /*
    if (IN35 == 0) {//倒车视屏选择使能按键
        if (IN11 && R_flag == 0) {//倒挡
            key_AV = 1; //模拟AV开关按一次
            AV_CH = 3; //3+1=4  倒车
            R_flag = 1; //防止一直进入这个函数，导致key_AV总是置1
        }
        if (IN11 == 0 && R_flag == 1) {
            key_AV = 1;
            AV_CH = 4; //返回MCU界面
            R_flag = 0;
        }
    }

    if (key_AV) {
        key_AV = 0;
        key_long_set = 0;
        key_up = 0;
        key_set = 0;
        unsigned char mode = 2; //2,MCU

        if (AV_CH < 4) AV_CH++;
        else AV_CH = 0;

        switch (AV_CH) {
            case 0: // DAV
                CS_E = 0; //关闭 
                mode = 1; //2,MCU
                break;
            case 1: //AV2  SP2  CJ2
                CS_E = 1; //打开 
                CS_A = 1;
                CS_B = 1;
                CS_C = 1;
                mode = 6; //AV2
                break;
            case 2: //AV2  SP3  CJ3
                CS_E = 1; //打开 
                CS_A = 0;
                CS_B = 1;
                CS_C = 1;
                mode = 6; //AV2
                break;
            case 3: //AV2  SP4  CJ4
                CS_E = 1; //打开 
                CS_A = 1;
                CS_B = 0;
                CS_C = 1;
                mode = 6; //AV2
                break;
            case 4: //AV1
                CS_E = 0; //倒车
                mode = 2; //4,AV1 
                break;
            default:
                CS_E = 0; //关闭 
                mode = 1; //2,MCU
                AV_CH = 0;
                break;
        }
        LCD_CHS(mode);
    }*/
}

/******************************************************/
void ICFrame(void) { //仪表框架
    LCD_Clear();

    LCD_DrawImage1BPPZOOM_4(320, 15, BmpZHYB, WHITE, BLACK);
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //顶部横线

    LCD_DrawImage1BPPZOOM_4(35, 75, Bmp_IN1, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(35, 75 + 25 * 1, Bmp_IN33/*备用开关*//*Bmp_IN2*/, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(35, 75 + 25 * 2, Bmp_IN7/*Bmp_IN3*/, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(35, 75 + 25 * 3, Bmp_IN6/*Bmp_IN4*/, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(35, 75 + 25 * 4, Bmp_IN5, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(35, 75 + 25 * 5, Bmp_IN33/*备用开关*//*Bmp_IN6*/, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(35, 75 + 25 * 6, Bmp_IN33/*备用开关*//*Bmp_IN7*/, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(35, 75 + 25 * 7, Bmp_IN33/*备用开关*//*Bmp_IN8*/, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(35, 75 + 25 * 8, Bmp_IN33/*备用开关*//*Bmp_IN9*/, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(35, 75 + 25 * 9, Bmp_ran_you_yu_re/*Bmp_IN10*/, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(35, 75 + 25 * 10, Bmp_jin_qi_yu_re/*Bmp_IN11*/, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(35, 75 + 25 * 11, Bmp_IN2/*Bmp_IN12*/, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(35, 75 + 25 * 12, Bmp_IN33/*备用开关*//*Bmp_IN13*/, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(35, 75 + 25 * 13, Bmp_qu_li_kai_guan_gao/*Bmp_IN14*/, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(35, 75 + 25 * 14, Bmp_IN33/*备用开关*//*Bmp_IN15*/, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(35, 75 + 25 * 15, Bmp_pai_qi_zd_gao/*Bmp_IN16*/, WHITE, BLACK);


    LCD_DrawImage1BPPZOOM_4(285, 75, Bmp_IN18/*Bmp_IN17*/, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 1, Bmp_IN33/*备用开关*//*Bmp_IN18*/, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 2, Bmp_IN8/*Bmp_IN19*/, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 3, Bmp_an_quan_dai/*Bmp_IN20*/, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 4, Bmp_IN33/*备用开关*//*Bmp_IN21*/, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 5, Bmp_IN33/*备用开关*//*Bmp_IN22*/, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 6, Bmp_IN33/*备用开关*//*Bmp_IN23*/, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 7, Bmp_IN11/*Bmp_IN24*/, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 8, Bmp_IN33/*备用开关*//*Bmp_IN25*/, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 9, Bmp_IN20/*Bmp_IN26*/, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 10, Bmp_deng_si_jian_ce/*Bmp_IN27*/, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 11, Bmp_IN33/*备用开关*//*Bmp_IN28*/, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 12, Bmp_pai_qi_zd_di/*Bmp_IN29*/, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 13, Bmp_IN33/*备用开关*//*Bmp_IN30*/, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 14, Bmp_qu_li_kai_guan_di/*Bmp_IN31*/, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 15, Bmp_IN33/*备用开关*//*Bmp_IN32*/, WHITE, BLACK);


    LCD_DrawImage1BPPZOOM_4(535, 75, Bmp_IN34/*Bmp_IN33*/, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(535, 75 + 25 * 1, Bmp_IN28/*Bmp_IN34*/, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(535, 75 + 25 * 2, Bmp_IN26/*Bmp_IN35*/, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(535, 75 + 25 * 3, Bmp_IN36, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(535, 75 + 25 * 4, Bmp_IN37, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(535, 75 + 25 * 5, Bmp_IN38, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(535, 75 + 25 * 6, Bmp_IN39, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(535, 75 + 25 * 7, Bmp_IN40, WHITE, BLACK);

    LCD_DrawImage1BPP(505 + 200, 75 + 25 * 15, BMP_V, WHITE, BLACK);

}

void ICUpdate(void) {
    unsigned int dump;
    unsigned int i;

    dump = sw_input[0].byte + ((unsigned int) (sw_input[1].byte) << 8);
    for (i = 0; i < 16; i++) {
        if (i == 3 || i == 1 || i == 2 || i == 0 || i == 4 || i == 6 || i == 7 || i == 9 || i == 10 || i == 11
                || i == 13 || i == 15) {//为控火开关
            if ((dump & 0x01) == 0x01) {
                LCD_DrawImage1BPP(5, 75 + 25 * i, Bmpflag[0], WHITE, BLACK);
            } else {
                LCD_DrawImage1BPP(5, 75 + 25 * i, Bmpflag[1], GREEN, BLACK);
            }
        } else if ((dump & 0x01) == 0x01) {
            LCD_DrawImage1BPP(5, 75 + 25 * i, Bmpflag[1], GREEN, BLACK);
        } else {
            LCD_DrawImage1BPP(5, 75 + 25 * i, Bmpflag[0], WHITE, BLACK);
        }
        dump = dump >> 1;
    }

    dump = sw_input[2].byte + ((unsigned int) (sw_input[3].byte) << 8);
    for (i = 0; i < 16; i++) {
        if (i == 9) {//IN26 为控火开关
            if ((dump & 0x01) == 0x01) {
                LCD_DrawImage1BPP(255, 75 + 25 * i, Bmpflag[0], WHITE, BLACK);
            } else {
                LCD_DrawImage1BPP(255, 75 + 25 * i, Bmpflag[1], GREEN, BLACK);
            }
        } else if ((dump & 0x01) == 0x01) {
            LCD_DrawImage1BPP(255, 75 + 25 * i, Bmpflag[1], GREEN, BLACK);
        } else {
            LCD_DrawImage1BPP(255, 75 + 25 * i, Bmpflag[0], WHITE, BLACK);
        }
        dump = dump >> 1;
    }

    dump = sw_input[4].byte;
    for (i = 0; i < 8; i++) {//WAKE1 WAKE2 WAKE3为控火开关
        if (i == 5 || i == 6 || i == 7) {
            if ((dump & 0x01) == 0x01)
                LCD_DrawImage1BPP(505, 75 + 25 * i, Bmpflag[0], WHITE, BLACK);
            else
                LCD_DrawImage1BPP(505, 75 + 25 * i, Bmpflag[1], GREEN, BLACK);
        } else if ((dump & 0x01) == 0x01) {
            LCD_DrawImage1BPP(505, 75 + 25 * i, Bmpflag[1], GREEN, BLACK);
        } else
            LCD_DrawImage1BPP(505, 75 + 25 * i, Bmpflag[0], WHITE, BLACK);
        dump = dump >> 1;
    }
    //程序版本号
    print_SZ_1(535 + 200, 75 + 25 * 15, VERISON, 3, 2, WHITE);

}

void frmIC(void) {
    if (f_index == 0) { //只更新一次
        f_index = 1;
        ICFrame();
    } else if (f_index == 1) {
        f_index = 1;
        ICUpdate();
    } else {
        f_index = 0;
    }


    if (key_up) { //子菜单切换
        key_up = 0;
        frmID = 1;
        f_index = 0;
    }

    if (key_AV) {
        key_AV = 0;
    }
    if (key_set) {//主菜单/子菜单切换
        key_set = 0;
        frmID = 0;
        f_index = 0;
    }
    if (key_long_set) {
        key_long_set = 0;
    }

}

/******************************************************/

void MenuFrame(void) {
    LCD_Clear();
    unsigned char color = WHITE;
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //顶部横线   

    LCD_DrawImage1BPP(130, 130, BMP_Control, color, BLACK); //控制
    LCD_DrawImage1BPP(130 + 50, 130, BMP_STSTEM, color, BLACK); //系统
    LCD_DrawImage1BPP(130 + 50 + 50, 130, BMP_Message, color, BLACK); //信息

    LCD_DrawImage1BPP(130, 130 + 35, BMP_Engine, color, BLACK); //发动机
    LCD_DrawImage1BPP(130 + 75, 130 + 35, BMP_STSTEM, color, BLACK); //系统
    LCD_DrawImage1BPP(130 + 75 + 50, 130 + 35, BMP_Message, color, BLACK); //信息

    LCD_DrawImage1BPP(130, 130 + 35 + 35, BMP_Fuzhu, color, BLACK); //辅助
    LCD_DrawImage1BPP(130 + 50, 130 + 35 + 35, BMP_STSTEM, color, BLACK); //系统
    LCD_DrawImage1BPP(130 + 50 + 50, 130 + 35 + 35, BMP_Message, color, BLACK); //信息

    LCD_DrawImage1BPP(130, 130 + 35 + 35 + 35, BMP_TCU, color, BLACK); //TCU
    LCD_DrawImage1BPP(130 + 39, 130 + 35 + 35 + 35, BMP_STSTEM, color, BLACK); //系统
    LCD_DrawImage1BPP(130 + 39 + 50, 130 + 35 + 35 + 35, BMP_Message, color, BLACK); //信息

    LCD_DrawImage1BPP(130 + 350, 130, BMP_Battery, color, BLACK); //电池
    LCD_DrawImage1BPP(130 + 350 + 50, 130, BMP_Manage, color, BLACK); //管理
    LCD_DrawImage1BPP(130 + 350 + 50 + 50, 130, BMP_STSTEM, color, BLACK); //系统
    LCD_DrawImage1BPP(130 + 350 + 50 + 50 + 50, 130, BMP_Message, color, BLACK); //信息

    LCD_DrawImage1BPP(130 + 350, 130 + 35, BMP_Battery, color, BLACK); //电池   
    LCD_DrawImage1BPP(130 + 350 + 50, 130 + 35, BMP_Message, color, BLACK); //信息

    LCD_DrawImage1BPP(130 + 350, 130 + 35 + 35, BMP_Air, color, BLACK); //空调
    LCD_DrawImage1BPP(130 + 350 + 50, 130 + 35 + 35, BMP_STSTEM, color, BLACK); //系统
    LCD_DrawImage1BPP(130 + 350 + 50 + 50, 130 + 35 + 35, BMP_Message, color, BLACK); //信息   



    LCD_Clear();
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //顶部横线   

    LCD_DrawImage1BPP(130, 130, BMP_Control, color, BLACK); //控制
    LCD_DrawImage1BPP(130 + 50, 130, BMP_STSTEM, color, BLACK); //系统
    LCD_DrawImage1BPP(130 + 50 + 50, 130, BMP_Message, color, BLACK); //信息

    LCD_DrawImage1BPP(130, 130 + 35, BMP_Engine, color, BLACK); //发动机
    LCD_DrawImage1BPP(130 + 75, 130 + 35, BMP_STSTEM, color, BLACK); //系统
    LCD_DrawImage1BPP(130 + 75 + 50, 130 + 35, BMP_Message, color, BLACK); //信息

    LCD_DrawImage1BPP(130, 130 + 35 + 35, BMP_Fuzhu, color, BLACK); //辅助
    LCD_DrawImage1BPP(130 + 50, 130 + 35 + 35, BMP_STSTEM, color, BLACK); //系统
    LCD_DrawImage1BPP(130 + 50 + 50, 130 + 35 + 35, BMP_Message, color, BLACK); //信息

    LCD_DrawImage1BPP(130, 130 + 35 + 35 + 35, BMP_TCU, color, BLACK); //TCU
    LCD_DrawImage1BPP(130 + 39, 130 + 35 + 35 + 35, BMP_STSTEM, color, BLACK); //系统
    LCD_DrawImage1BPP(130 + 39 + 50, 130 + 35 + 35 + 35, BMP_Message, color, BLACK); //信息

    LCD_DrawImage1BPP(130 + 350, 130, BMP_Battery, color, BLACK); //电池
    LCD_DrawImage1BPP(130 + 350 + 50, 130, BMP_Manage, color, BLACK); //管理
    LCD_DrawImage1BPP(130 + 350 + 50 + 50, 130, BMP_STSTEM, color, BLACK); //系统
    LCD_DrawImage1BPP(130 + 350 + 50 + 50 + 50, 130, BMP_Message, color, BLACK); //信息

    LCD_DrawImage1BPP(130 + 350, 130 + 35, BMP_Battery, color, BLACK); //电池   
    LCD_DrawImage1BPP(130 + 350 + 50, 130 + 35, BMP_Message, color, BLACK); //信息

    LCD_DrawImage1BPP(130 + 350, 130 + 35 + 35, BMP_Air, color, BLACK); //空调
    LCD_DrawImage1BPP(130 + 350 + 50, 130 + 35 + 35, BMP_STSTEM, color, BLACK); //系统
    LCD_DrawImage1BPP(130 + 350 + 50 + 50, 130 + 35 + 35, BMP_Message, color, BLACK); //信息
    
    LCD_DrawImage1BPP(130 + 350, 130 + 35 + 35 + 35, BMP_IC, color, BLACK); //仪表
    LCD_DrawImage1BPP(130 + 350 + 50, 130 + 35 + 35 + 35, BMP_STSTEM, color, BLACK); //系统
    LCD_DrawImage1BPP(130 + 350 + 50 + 50, 130 + 35 + 35 + 35, BMP_Message, color, BLACK); //信息
}

void MenuUpdate(void) {
    static unsigned char i = 0;
    unsigned char color = BLACK;
    if (key_up) {//箭头向下走
        key_up = 0;
        i++;
    }
    if (key_AV) {//箭头向上走
        key_AV = 0;
        i--;
    }
    if (i == 0) i = 8;
    if (i == 16) i = 8;
    //子菜单间切换
    if (i == 8) {
        color = GREEN;
        if (key_set) {
            key_set = 0;
            frmID = 2;
            f_index = 0;
        }
    } else
        color = BLACK;
    LCD_DrawImage1BPP(105, 131, BMP_Choose, color, BLACK);
    if (i == 1 || i == 9) {
        color = GREEN;
        if (key_set) {
            key_set = 0;
            frmID = 3;
            f_index = 0;
        }
    } else
        color = BLACK;
    LCD_DrawImage1BPP(105, 131 + 35, BMP_Choose, color, BLACK);
    if (i == 2 || i == 10) {
        color = GREEN;
        if (key_set) {
            key_set = 0;
            frmID = 4;
            f_index = 0;
        }
    } else
        color = BLACK;
    LCD_DrawImage1BPP(105, 131 + 2 * 35, BMP_Choose, color, BLACK);
    if (i == 3 || i == 11) {
        color = GREEN;
        if (key_set) {
            key_set = 0;
            frmID = 5;
            f_index = 0;
        }
    } else
        color = BLACK;
    LCD_DrawImage1BPP(105, 131 + 3 * 35, BMP_Choose, color, BLACK);
    if (i == 4 || i == 12) {
        color = GREEN;
        if (key_set) {
            key_set = 0;
            frmID = 6;
            f_index = 0;
        }
    } else
        color = BLACK;
    LCD_DrawImage1BPP(105 + 350, 131, BMP_Choose, color, BLACK);
    if (i == 5 || i == 13) {
        color = GREEN;
        if (key_set) {
            key_set = 0;
            frmID = 7;
            f_index = 0;
        }
    } else
        color = BLACK;
    LCD_DrawImage1BPP(105 + 350, 131 + 1 * 35, BMP_Choose, color, BLACK);
    if (i == 6 || i == 14) {
        color = GREEN;
        if (key_set) {
            key_set = 0;
            frmID = 8;
            f_index = 0;
        }
    } else
        color = BLACK;
    LCD_DrawImage1BPP(105 + 350, 131 + 2 * 35, BMP_Choose, color, BLACK);
    if (i == 7  || i == 15) {
        color = GREEN;
        if (key_set) {
            key_set = 0;
            frmID = 10;
            f_index = 0;
        }
    } else
        color = BLACK;
    LCD_DrawImage1BPP(105 + 350, 131 + 3 * 35, BMP_Choose, color, BLACK);


    /*
    static unsigned char al_index = 0;
    if (alarm_update_flag == 0) { //3S 更新一次 循环  x=270  y=375
        // LCD_DrawRect(x, y - 5, 320, 50, BLACK); //清除显示区域
        switch (al_index) {
                //具体显示故障码的SPN和FMI
            case 0:
                al_index = 1;
                if (CAN_18FECAEF_len >= 6) {
                    DM_HCU(1);
                    if (hcu_spn > 0) {
                        LCD_DrawImage1BPPZOOM_4(x, y + 5, BMP_SPN, WHITE, BLACK);
                        LCD_DrawImage1BPPZOOM_4(x + 190, y + 5, BMP_FMI, WHITE, BLACK);
                        print_SZ_1(x + 50, y, hcu_spn, 6, 0, RED);
                        print_SZ_1(x + 230, y, hcu_fmi, 4, 0, RED);
                        alarm_update_flag = 1;
                        break;
                    }
                }

            case 1:
                al_index = 2;
                if (CAN_18FECAEF_len >= 10) {
                    DM_HCU(2);
                    if (hcu_spn > 0) {
                        LCD_DrawImage1BPPZOOM_4(x, y + 5, BMP_SPN, WHITE, BLACK);
                        print_SZ_1(x + 50, y, hcu_spn, 6, 0, RED);
                        print_SZ_1(x + 120 + 110, y, hcu_fmi, 4, 0, RED);
                        LCD_DrawImage1BPPZOOM_4(x + 190, y + 5, BMP_FMI, WHITE, BLACK);
                        alarm_update_flag = 1;
                        break;
                    }
                }
            case 2:
                al_index = 3;
                if (CAN_18FECAEF_len >= 14) {
                    DM_HCU(3);
                    if (hcu_spn > 0) {
                        LCD_DrawImage1BPPZOOM_4(x, y + 5, BMP_SPN, WHITE, BLACK);
                        print_SZ_1(x + 50, y, hcu_spn, 6, 0, RED);
                        print_SZ_1(x + 120 + 110, y, hcu_fmi, 4, 0, RED);
                        LCD_DrawImage1BPPZOOM_4(x + 190, y + 5, BMP_FMI, WHITE, BLACK);
                        alarm_update_flag = 1;
                        break;
                    }
                }
            case 3:
                al_index = 4;
                if (CAN_18FECAEF_len >= 18) {
                    DM_HCU(4);
                    if (hcu_spn > 0) {
                        LCD_DrawImage1BPPZOOM_4(x, y + 5, BMP_SPN, WHITE, BLACK);
                        print_SZ_1(x + 50, y, hcu_spn, 6, 0, RED);
                        print_SZ_1(x + 120 + 110, y, hcu_fmi, 4, 0, RED);
                        LCD_DrawImage1BPPZOOM_4(x + 190, y + 5, BMP_FMI, WHITE, BLACK);
                        alarm_update_flag = 1;
                        break;
                    }
                }
            case 4:
                al_index = 5;
                if (CAN_18FECAEF_len >= 22) {
                    DM_HCU(5);
                    if (hcu_spn > 0) {
                        LCD_DrawImage1BPPZOOM_4(x, y + 5, BMP_SPN, WHITE, BLACK);
                        print_SZ_1(x + 50, y, hcu_spn, 6, 0, RED);
                        print_SZ_1(x + 120 + 110, y, hcu_fmi, 4, 0, RED);
                        LCD_DrawImage1BPPZOOM_4(x + 190, y + 5, BMP_FMI, WHITE, BLACK);
                        alarm_update_flag = 1;
                        break;
                    }
                }

            case 5:
                al_index = 6;
                if (CAN_18FECA03_len >= 6) {
                    DM_TCU(1);
                    if (tcu_spn > 0) {
                        LCD_DrawImage1BPPZOOM_4(x, y + 5, BMP_SPN, WHITE, BLACK);
                        print_SZ_1(x + 50, y, tcu_spn, 6, 0, RED);
                        print_SZ_1(x + 120 + 110, y, tcu_fmi, 4, 0, RED);
                        LCD_DrawImage1BPPZOOM_4(x + 190, y + 5, BMP_FMI, WHITE, BLACK);
                        alarm_update_flag = 1;
                        break;
                    }
                }

            case 6:
                al_index = 7;
                if (CAN_18FECA03_len >= 10) {
                    DM_TCU(2);
                    if (tcu_spn > 0) {
                        LCD_DrawImage1BPPZOOM_4(x, y + 5, BMP_SPN, WHITE, BLACK);
                        print_SZ_1(x + 50, y, tcu_spn, 6, 0, RED);
                        print_SZ_1(x + 120 + 110, y, tcu_fmi, 4, 0, RED);
                        LCD_DrawImage1BPPZOOM_4(x + 190, y + 5, BMP_FMI, WHITE, BLACK);
                        alarm_update_flag = 1;
                        break;
                    }
                }
            case 7:
                al_index = 8;
                if (CAN_18FECA03_len >= 14) {
                    DM_TCU(3);
                    if (tcu_spn > 0) {
                        LCD_DrawImage1BPPZOOM_4(x, y + 5, BMP_SPN, WHITE, BLACK);
                        print_SZ_1(x + 50, y, tcu_spn, 6, 0, RED);
                        print_SZ_1(x + 120 + 110, y, tcu_fmi, 4, 0, RED);
                        LCD_DrawImage1BPPZOOM_4(x + 190, y + 5, BMP_FMI, WHITE, BLACK);
                        alarm_update_flag = 1;
                        break;
                    }
                }
            case 8:
                al_index = 9;
                if (CAN_18FECA03_len >= 18) {
                    DM_TCU(4);
                    if (tcu_spn > 0) {
                        LCD_DrawImage1BPPZOOM_4(x, y + 5, BMP_SPN, WHITE, BLACK);
                        print_SZ_1(x + 50, y, tcu_spn, 6, 0, RED);
                        print_SZ_1(x + 120 + 110, y, tcu_fmi, 4, 0, RED);
                        LCD_DrawImage1BPPZOOM_4(x + 190, y + 5, BMP_FMI, WHITE, BLACK);
                        alarm_update_flag = 1;
                        break;
                    }
                }
            case 9:
                al_index = 10;
                if (CAN_18FECA03_len >= 22) {
                    DM_TCU(5);
                    if (tcu_spn > 0) {
                        LCD_DrawImage1BPPZOOM_4(x, y + 5, BMP_SPN, WHITE, BLACK);
                        print_SZ_1(x + 50, y, tcu_spn, 6, 0, RED);
                        print_SZ_1(x + 120 + 110, y, tcu_fmi, 4, 0, RED);
                        LCD_DrawImage1BPPZOOM_4(x + 190, y + 5, BMP_FMI, WHITE, BLACK);
                        alarm_update_flag = 1;
                        break;
                    }
                }

            case 10:
                al_index = 0;
                if (CAN_18FECAF5_len >= 6) {
                    DM_CCU(1);
                    if (ccu_spn > 50000) {
                        LCD_DrawImage1BPPZOOM_4(x, y + 5, BMP_SPN, WHITE, BLACK);
                        print_SZ_1(x + 50, y, ccu_spn, 6, 0, RED);
                        print_SZ_1(x + 120 + 110, y, ccu_fmi, 4, 0, RED);
                        LCD_DrawImage1BPPZOOM_4(x + 190, y + 5, BMP_FMI, WHITE, BLACK);
                        alarm_update_flag = 1;
                        break;
                    }
                }

            default:
                al_index = 0;
                LCD_DrawRect(x, y, 320, 50, BLACK); //清除显示区域
                break;
        }
    }


    //电机状态
    if (MCU_offline_warn == 0x3) {
        LCD_DrawImage1BPPZOOM_4(50 + 30, 80, BMP_MCU_online, GREEN, BLACK);
        LCD_DrawRect(50 + 96 + 30, 80, 25, 30, BLACK); //残留覆盖
    } else if (MCU_offline_warn == 1)
        LCD_DrawImage1BPPZOOM_4(50 + 30, 80, BMP_DJ_offline_1, RED, BLACK);

    //电池状态
    if (BMS_offline_warn == 0x3) {
        LCD_DrawImage1BPPZOOM_4(200 + 30, 80, BMP_BMS_online, GREEN, BLACK);
        LCD_DrawRect(200 + 96 + 30, 80, 25, 30, BLACK);
    } else if (BMS_offline_warn == 1)
        LCD_DrawImage1BPPZOOM_4(200 + 30, 80, BMP_DC_offline_1, RED, BLACK);

    //变速箱状态
    if (TCU_offline_warn == 0x3) {
        LCD_DrawImage1BPPZOOM_4(350 + 30, 80, BMP_TCU_online, GREEN, BLACK);
        LCD_DrawRect(350 + 120 + 30, 80, 25, 30, BLACK);
    } else if (TCU_offline_warn == 1)
        LCD_DrawImage1BPPZOOM_4(350 + 30, 80, BMP_TCU_offline_1, RED, BLACK);

    //发动机状态
    if (Engine_offline_warn == 0x3) {
        LCD_DrawImage1BPPZOOM_4(500 + 24 + 30, 80, BMP_Engine_online, GREEN, BLACK);
        LCD_DrawRect(500 + 120 + 24 + 30, 80, 25, 30, BLACK);
    } else if (Engine_offline_warn == 1)
        LCD_DrawImage1BPPZOOM_4(500 + 24 + 30, 80, BMP_Engine_offline_1, RED, BLACK);

    updata_DJDY(198, 208); //(120+72+35,250+60-2);
    updata_DJDL(520, 208);
    updata_DCT(211, 253);
    updata_DJT(505, 255);
    updata_RMP(213, 308); //(135+180+50+100+20+20,250+55);
    updata_DJ_kzq_T(553, 308);
    updata_Accelerator(553, 358);
    updata_Brake_percent(235 + 18, 358);
     */


}

void frmMenu(void) {
    if (f_index == 0) { //只更新一次
        f_index = 1;
        MenuFrame();
    } else if (f_index == 1) {
        f_index = 1;
        MenuUpdate();
    } else {
        f_index = 0;
    }
    /*
        if (key_up) {子菜单间切换
            key_up = 0;
            frmID = 2;
            f_index = 0;
        }
    if (key_AV) {
        key_AV = 0;
    }
    if (key_set) {
        key_set = 0;
        frmID = 0;
        f_index = 0;
    }
     */
    if (key_long_set) {
        key_long_set = 0;
    }
    
    if (key_duble) {
        key_duble = 0;
        if (time_flag == 0) {
            f_index = 0;
            frmID = 9;
        }
    }

}

/******************************************************/

void ControlFrame(void) {
    unsigned char i = 0;
    LCD_Clear();
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //顶部横线
    LCD_DrawImage1BPP(130 + 200, 130 - 85, BMP_Control, WHITE, BLACK); //控制
    LCD_DrawImage1BPP(130 + 200 + 50, 130 - 85, BMP_STSTEM, WHITE, BLACK); //系统
    LCD_DrawImage1BPP(130 + 200 + 50 + 50, 130 - 85, BMP_Message, WHITE, BLACK); //信息

    LCD_DrawRect(80, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320 + 320, 90, 1, 380, GREEN);
    for (i = 0; i < 11; i++)
        LCD_DrawRect(80, 90 + i * 38, 640, 1, GREEN);

    LCD_DrawImage1BPP(82, 100, BMP_DJ, WHITE, BLACK); //电机
    LCD_DrawImage1BPP(82 + 42, 100, BMP_Input, WHITE, BLACK); //输入
    LCD_DrawImage1BPP(82 + 42 + 42, 100, BMP_DY, WHITE, BLACK); //电压
    LCD_DrawImage1BPP(400 - 24, 100, BMP_v, WHITE, BLACK); //v

    LCD_DrawImage1BPP(82, 100 + 38, BMP_DJ, WHITE, BLACK); //电机
    LCD_DrawImage1BPP(82 + 42, 100 + 38, BMP_Input, WHITE, BLACK); //输入
    LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38, BMP_DL, WHITE, BLACK); //电流
    LCD_DrawImage1BPP(400 - 24, 100 + 38, BMP_a, WHITE, BLACK); //a

    LCD_DrawImage1BPP(82, 100 + 38 * 2, BMP_DJ, WHITE, BLACK); //电机
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 2, BMP_Wendu, WHITE, BLACK); //温度
    LCD_DrawImage1BPP(400 - 28, 100 + 38 * 2, BMP_T, WHITE, BLACK); //℃

    LCD_DrawImage1BPP(82, 100 + 38 * 3, BMP_DJ, WHITE, BLACK); //电机
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 3, BMP_KZQ, WHITE, BLACK); //控制器
    LCD_DrawImage1BPP(82 + 42 + 63, 100 + 38 * 3, BMP_Wendu, WHITE, BLACK); //温度
    LCD_DrawImage1BPP(400 - 28, 100 + 38 * 3, BMP_T, WHITE, BLACK); //℃

    LCD_DrawImage1BPP(82, 100 + 38 * 4, BMP_Zhengche, WHITE, BLACK); //整车
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 4, BMP_Mode, WHITE, BLACK); //模式

    LCD_DrawImage1BPP(82, 100 + 38 * 5, BMP_Chengxu, WHITE, BLACK); //程序
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 5, BMP_Banben, WHITE, BLACK); //版本
    LCD_DrawImage1BPP(82 + 42 + 42 + 2, 100 + 5 + 38 * 5, BMP_Maohao, WHITE, BLACK); //:

    LCD_DrawImage1BPP(82, 100 + 38 * 6, BMP_Zhengche, WHITE, BLACK); //整车
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 6, BMP_KZQ, WHITE, BLACK); //控制器
    LCD_DrawImage1BPP(82 + 42 + 63, 100 + 38 * 6, BMP_Life, WHITE, BLACK); //Life
    LCD_DrawImage1BPP(82 + 42 + 63 + 44 + 2, 100 + 5 + 38 * 6, BMP_Maohao, WHITE, BLACK); //:

    LCD_DrawImage1BPP(82 + 320, 100, BMP_Jiasu, WHITE, BLACK); //加速
    LCD_DrawImage1BPP(82 + 42 + 320, 100, BMP_Taban, WHITE, BLACK); //踏板
    LCD_DrawImage1BPP(82 + 42 + 42 + 320, 100, BMP_Baifenbi, WHITE, BLACK); //百分比
    LCD_DrawImage1BPP(720 - 24, 100, BMP_Baifenhao, WHITE, BLACK); //%

    LCD_DrawImage1BPP(82 + 320, 100 + 38, BMP_Zhidong, WHITE, BLACK); //制动
    LCD_DrawImage1BPP(82 + 42 + 320, 100 + 38, BMP_Taban, WHITE, BLACK); //踏板
    LCD_DrawImage1BPP(82 + 42 + 42 + 320, 100 + 38, BMP_Baifenbi, WHITE, BLACK); //百分比
    LCD_DrawImage1BPP(720 - 24, 100 + 38, BMP_Baifenhao, WHITE, BLACK); //%

    LCD_DrawImage1BPP(82 + 320, 100 + 2 * 38, BMP_Shuzi, WHITE, BLACK); //数字
    LCD_DrawImage1BPP(82 + 42 + 320, 100 + 2 * 38, BMP_Liang, WHITE, BLACK); //量
    LCD_DrawImage1BPP(82 + 42 + 21 + 320, 100 + 2 * 38, BMP_Input, WHITE, BLACK); //输入
    LCD_DrawImage1BPP(82 + 42 + 21 + 42 + 320, 100 - 8 + 2 * 38, BMP_SZ_1[1], WHITE, BLACK); //1

    LCD_DrawImage1BPP(82 + 320, 100 + 3 * 38, BMP_Shuzi, WHITE, BLACK); //数字
    LCD_DrawImage1BPP(82 + 42 + 320, 100 + 3 * 38, BMP_Liang, WHITE, BLACK); //量
    LCD_DrawImage1BPP(82 + 42 + 21 + 320, 100 + 3 * 38, BMP_Input, WHITE, BLACK); //输入
    LCD_DrawImage1BPP(82 + 42 + 21 + 42 + 320, 100 - 8 + 3 * 38, BMP_SZ_1[2], WHITE, BLACK); //2

    LCD_DrawImage1BPP(82 + 320, 100 + 4 * 38, BMP_Shuzi, WHITE, BLACK); //数字
    LCD_DrawImage1BPP(82 + 42 + 320, 100 + 4 * 38, BMP_Liang, WHITE, BLACK); //量
    LCD_DrawImage1BPP(82 + 42 + 21 + 320, 100 + 4 * 38, BMP_Input, WHITE, BLACK); //输入
    LCD_DrawImage1BPP(82 + 42 + 21 + 42 + 320, 100 - 8 + 4 * 38, BMP_SZ_1[3], WHITE, BLACK); //3

    LCD_DrawImage1BPP(82 + 320, 100 + 5 * 38, BMP_Shuzi, WHITE, BLACK); //数字
    LCD_DrawImage1BPP(82 + 42 + 320, 100 + 5 * 38, BMP_Liang, WHITE, BLACK); //量
    LCD_DrawImage1BPP(82 + 42 + 21 + 320, 100 + 5 * 38, BMP_Output, WHITE, BLACK); //输出
    LCD_DrawImage1BPP(82 + 42 + 21 + 42 + 320, 100 - 8 + 5 * 38, BMP_SZ_1[1], WHITE, BLACK); //1

    LCD_DrawImage1BPP(82 + 320, 100 + 6 * 38, BMP_Shuzi, WHITE, BLACK); //数字
    LCD_DrawImage1BPP(82 + 42 + 320, 100 + 6 * 38, BMP_Liang, WHITE, BLACK); //量
    LCD_DrawImage1BPP(82 + 42 + 21 + 320, 100 + 6 * 38, BMP_Output, WHITE, BLACK); //输出
    LCD_DrawImage1BPP(82 + 42 + 21 + 42 + 320, 100 - 8 + 6 * 38, BMP_SZ_1[2], WHITE, BLACK); //2

    LCD_DrawImage1BPP(82 + 320, 100 + 7 * 38, BMP_Shuzi, WHITE, BLACK); //数字
    LCD_DrawImage1BPP(82 + 42 + 320, 100 + 7 * 38, BMP_Liang, WHITE, BLACK); //量
    LCD_DrawImage1BPP(82 + 42 + 21 + 320, 100 + 7 * 38, BMP_Output, WHITE, BLACK); //输出
    LCD_DrawImage1BPP(82 + 42 + 21 + 42 + 320, 100 - 8 + 7 * 38, BMP_SZ_1[3], WHITE, BLACK); //3

}

void ControlUpdate(void) {
    updata_DJDY(82 + 200 + 20, 100 - 8);
    updata_DJDL(82 + 200 + 20, 100 + 38 - 8);
    updata_T(82 + 200 + 20, 100 + 38 * 2 - 8, WHITE, Motor_Temperature, 1, 40);
    updata_T(82 + 200 + 20, 100 + 38 * 3 - 8, WHITE, Inverter_t, 1, 40);

    print_SZ_1(82 + 200 + 20, 100 - 8 + 38 * 4, Car_mode, 3, 0, WHITE); //整车模式
    print_SZ_1(82 + 200 - 44, 100 - 8 + 38 * 5, Program, 6, 2, WHITE); //程序版本
    print_SZ_1(82 + 200 + 20, 100 - 8 + 38 * 6, Car_LIFE, 3, 0, WHITE); //整车LIFE
    print_SZ_1(82 + 200 + 320, 100 - 8, Speed_percent * 4, 4, 1, WHITE); //加速踏板
    print_SZ_1(82 + 200 + 320, 100 - 8 + 38, Brake_percent * 4, 4, 1, WHITE); //制动踏板
    print_D(82 + 180 + 320, 100 - 8 + 38 * 2, CAN_KEY[0].byte); //数字量输入1
    print_D(82 + 180 + 320, 100 - 8 + 38 * 3, CAN_KEY[1].byte); //数字量输入2
    print_D(82 + 180 + 320, 100 - 8 + 38 * 4, Digit_input3); //数字量输入3
    print_D(82 + 180 + 320, 100 - 8 + 38 * 5, CAN_KEY[2].byte); //数字量输入1
    print_D(82 + 180 + 320, 100 - 8 + 38 * 6, CAN_KEY[3].byte); //数字量输入2
    print_D(82 + 180 + 320, 100 - 8 + 38 * 7, 0); //数字量输入3

}

void frmControl(void) {
    if (f_index == 0) { //只更新一次
        f_index = 1;
        ControlFrame();
    } else if (f_index == 1) {
        f_index = 1;
        ControlUpdate();
    } else {
        f_index = 0;
    }
    if (key_AV) {
        key_AV = 0;
    }
    if (key_up) {
        key_up = 0;
        frmID = 1;
        f_index = 0;
    }
    if (key_set) {//返回主界面
        key_set = 0;
        frmID = 0;
        f_index = 0;
        Index = 0;
    }
    if (key_long_set) {
        key_long_set = 0;
    }

}

/******************************************************/

void EngineFrame(void) {
    unsigned char i = 0;
    LCD_Clear();
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //顶部横线
    LCD_DrawImage1BPP(130 + 200 - 15, 130 - 85, BMP_Engine, WHITE, BLACK); //发动机
    LCD_DrawImage1BPP(130 + 200 + 75 - 15, 130 - 85, BMP_STSTEM, WHITE, BLACK); //系统
    LCD_DrawImage1BPP(130 + 200 + 75 + 50 - 15, 130 - 85, BMP_Message, WHITE, BLACK); //信息

    LCD_DrawRect(80, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320 + 320, 90, 1, 380, GREEN);
    for (i = 0; i < 11; i++)
        LCD_DrawRect(80, 90 + i * 38, 640, 1, GREEN);

    LCD_DrawImage1BPP(82, 100, BMP_Fadongji, WHITE, BLACK); //发动机
    LCD_DrawImage1BPP(82 + 63, 100, BMP_Youhao, WHITE, BLACK); //油耗
    LCD_DrawImage1BPP(400 - 32, 100, BMP_L_H, WHITE, BLACK); //L/H

    LCD_DrawImage1BPP(82, 100 + 38, BMP_Fadongji, WHITE, BLACK); //发动机
    LCD_DrawImage1BPP(82 + 63, 100 + 38, BMP_Shuiwen, WHITE, BLACK); //水温
    LCD_DrawImage1BPP(400 - 28, 100 + 38, BMP_T, WHITE, BLACK); //℃

    LCD_DrawImage1BPP(82, 100 + 38 * 2, BMP_Fadongji, WHITE, BLACK); //发动机
    LCD_DrawImage1BPP(82 + 63, 100 + 38 * 2, BMP_Fuhe, WHITE, BLACK); //负荷
    LCD_DrawImage1BPP(400 - 24, 100 + 38 * 2, BMP_Baifenhao, WHITE, BLACK); //%

    LCD_DrawImage1BPP(82, 100 + 38 * 3, BMP_Niaosu, WHITE, BLACK); //尿素
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 3, BMP_Yewei, WHITE, BLACK); //液位
    LCD_DrawImage1BPP(400 - 24, 100 + 38 * 3, BMP_Baifenhao, WHITE, BLACK); //%


    LCD_DrawImage1BPP(82 + 320, 100, BMP_Fadongji, WHITE, BLACK); //发动机
    LCD_DrawImage1BPP(82 + 63 + 320, 100, BMP_Mubiao, WHITE, BLACK); //目标
    LCD_DrawImage1BPP(82 + 63 + 42 + 320, 100, BMP_Youmen, WHITE, BLACK); //油门
    LCD_DrawImage1BPP(720 - 24, 100, BMP_Baifenhao, WHITE, BLACK); //%

    LCD_DrawImage1BPP(82 + 320, 100 + 38, BMP_Fadongji, WHITE, BLACK); //发动机
    LCD_DrawImage1BPP(82 + 63 + 320, 100 + 38, BMP_Shiji, WHITE, BLACK); //实际
    LCD_DrawImage1BPP(82 + 63 + 42 + 320, 100 + 38, BMP_Youmen, WHITE, BLACK); //油门
    LCD_DrawImage1BPP(720 - 24, 100 + 38, BMP_Baifenhao, WHITE, BLACK); //%   

    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 2, BMP_Fadongji, WHITE, BLACK); //发动机
    LCD_DrawImage1BPP(82 + 63 + 320, 100 + 38 * 2, BMP_Jiyou, WHITE, BLACK); //机油
    LCD_DrawImage1BPP(82 + 63 + 42 + 320, 100 + 38 * 2, BMP_Yali, WHITE, BLACK); //压力
    LCD_DrawImage1BPP(720 - 32, 100 + 38 * 2, BMP_Kpa, WHITE, BLACK); //Kpa

    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 3, BMP_Fadongji, WHITE, BLACK); //发动机
    LCD_DrawImage1BPP(82 + 63 + 320, 100 + 38 * 3, BMP_Jinqi, WHITE, BLACK); //进气
    LCD_DrawImage1BPP(82 + 63 + 42 + 320, 100 + 38 * 3, BMP_Wendu, WHITE, BLACK); //温度
    LCD_DrawImage1BPP(720 - 28, 100 + 38 * 3, BMP_T, WHITE, BLACK); //℃

}

void EngineUpdate(void) {
    print_SZ_1(82 + 63 + 42 + 80, 100 - 8, Fule_rate * 5, 4, 2, WHITE); //油耗
    updata_T(82 + 63 + 42 + 80 + 32, 100 - 8 + 38, WHITE, water_temp, 1, 40); //水温
    print_SZ_1(82 + 63 + 42 + 80 + 16, 100 - 8 + 38 * 2, Engine_Fuhe, 4, 0, WHITE); //负荷
    print_SZ_1(82 + 63 + 42 + 80, 100 - 8 + 38 * 3, Niaosu * 4, 4, 1, WHITE); //尿素
    print_SZ_1(82 + 63 + 42 + 80 + 320, 100 - 8, Accelerator * 4, 4, 1, WHITE); //目标油门
    print_SZ_1(82 + 63 + 42 + 80 + 320, 100 - 8 + 38, Accelerator_Shiji * 4, 4, 1, WHITE); //实际油门
    print_SZ_1(82 + 63 + 42 + 80 + 16 + 320, 100 - 8 + 38 * 2, Engine_oil_press * 4, 4, 0, WHITE); //机油压力
    updata_T(82 + 63 + 42 + 80 + 32 + 320, 100 - 8 + 38 * 3, WHITE, ambient_air_temperature, 1, 40); //进气温度
}

void frmEngine(void) {
    if (f_index == 0) { //只更新一次
        f_index = 1;
        EngineFrame();
    } else if (f_index == 1) {
        f_index = 1;
        EngineUpdate();
    } else {
        f_index = 0;
    }
    if (key_AV) {
        key_AV = 0;
    }

    if (key_up) {
        key_up = 0;
        f_index = 0;
        frmID = 1;
    }

    if (key_set) {//返回主界面
        key_set = 0;
        frmID = 0;
        f_index = 0;
        Index = 0;
    }
    if (key_long_set) {
        key_long_set = 0;
    }

}

/******************************************************/
void FuzhuFrame(void) {
    unsigned char i = 0;
    LCD_Clear();
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //顶部横线
    LCD_DrawImage1BPP(130 + 200, 130 - 85, BMP_Fuzhu, WHITE, BLACK); //辅助
    LCD_DrawImage1BPP(130 + 200 + 50, 130 - 85, BMP_STSTEM, WHITE, BLACK); //系统
    LCD_DrawImage1BPP(130 + 200 + 50 + 50, 130 - 85, BMP_Message, WHITE, BLACK); //信息

    LCD_DrawRect(80, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320 + 60, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320 + 320, 90, 1, 380, GREEN);
    for (i = 0; i < 11; i++)
        LCD_DrawRect(80, 90 + i * 38, 640, 1, GREEN);

    LCD_DrawImage1BPP(82, 100, BMP_Youbeng, WHITE, BLACK); //油泵
    LCD_DrawImage1BPP(82 + 42, 100, BMP_d, WHITE, BLACK); //D
    LCD_DrawImage1BPP(82 + 42 + 11, 100, BMP_c, WHITE, BLACK); //C
    LCD_DrawImage1BPP(82 + 42 + 11 + 11, 100, BMP_I, WHITE, BLACK); //  /
    LCD_DrawImage1BPP(82 + 42 + 11 + 11 + 11, 100, BMP_a, WHITE, BLACK); //A
    LCD_DrawImage1BPP(82 + 42 + 11 + 11 + 11 + 11, 100, BMP_c, WHITE, BLACK); //C
    LCD_DrawImage1BPP(82 + 42 + 11 + 11 + 11 + 11 + 21, 100, BMP_w, WHITE, BLACK); //  W
    LCD_DrawImage1BPP(82 + 42 + 11 + 11 + 11 + 11 + 21 + 11, 100, BMP_Xiang, WHITE, BLACK); //相
    LCD_DrawImage1BPP(82 + 42 + 11 + 11 + 11 + 11 + 21 + 11 + 21, 100, BMP_Output, WHITE, BLACK); //输出
    LCD_DrawImage1BPP(82 + 42 + 11 + 11 + 11 + 11 + 21 + 11 + 21 + 42, 100, BMP_DL, WHITE, BLACK); //电流
    LCD_DrawImage1BPP(400 - 24 + 60, 100, BMP_a, WHITE, BLACK); //A

    LCD_DrawImage1BPP(82, 100 + 38, BMP_Youbeng, WHITE, BLACK); //油泵
    LCD_DrawImage1BPP(82 + 42, 100 + 38, BMP_d, WHITE, BLACK); //D
    LCD_DrawImage1BPP(82 + 42 + 11, 100 + 38, BMP_c, WHITE, BLACK); //C
    LCD_DrawImage1BPP(82 + 42 + 11 + 11, 100 + 38, BMP_I, WHITE, BLACK); //  /
    LCD_DrawImage1BPP(82 + 42 + 11 + 11 + 11, 100 + 38, BMP_a, WHITE, BLACK); //A
    LCD_DrawImage1BPP(82 + 42 + 11 + 11 + 11 + 11, 100 + 38, BMP_c, WHITE, BLACK); //C
    LCD_DrawImage1BPP(82 + 42 + 11 + 11 + 11 + 11 + 21, 100 + 38, BMP_v, WHITE, BLACK); //  V
    LCD_DrawImage1BPP(82 + 42 + 11 + 11 + 11 + 11 + 21 + 11, 100 + 38, BMP_Xiang, WHITE, BLACK); //相
    LCD_DrawImage1BPP(82 + 42 + 11 + 11 + 11 + 11 + 21 + 11 + 21, 100 + 38, BMP_Output, WHITE, BLACK); //输出
    LCD_DrawImage1BPP(82 + 42 + 11 + 11 + 11 + 11 + 21 + 11 + 21 + 42, 100 + 38, BMP_DL, WHITE, BLACK); //电流
    LCD_DrawImage1BPP(400 - 24 + 60, 100 + 38, BMP_a, WHITE, BLACK); //A

    LCD_DrawImage1BPP(82, 100 + 38 * 2, BMP_Youbeng, WHITE, BLACK); //油泵
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 2, BMP_d, WHITE, BLACK); //D
    LCD_DrawImage1BPP(82 + 42 + 11, 100 + 38 * 2, BMP_c, WHITE, BLACK); //C
    LCD_DrawImage1BPP(82 + 42 + 11 + 11, 100 + 38 * 2, BMP_I, WHITE, BLACK); //  /
    LCD_DrawImage1BPP(82 + 42 + 11 + 11 + 11, 100 + 38 * 2, BMP_a, WHITE, BLACK); //A
    LCD_DrawImage1BPP(82 + 42 + 11 + 11 + 11 + 11, 100 + 38 * 2, BMP_c, WHITE, BLACK); //C
    LCD_DrawImage1BPP(82 + 42 + 11 + 11 + 11 + 11 + 21, 100 + 38 * 2, BMP_u, WHITE, BLACK); //  U
    LCD_DrawImage1BPP(82 + 42 + 11 + 11 + 11 + 11 + 21 + 11, 100 + 38 * 2, BMP_Xiang, WHITE, BLACK); //相
    LCD_DrawImage1BPP(82 + 42 + 11 + 11 + 11 + 11 + 21 + 11 + 21, 100 + 38 * 2, BMP_Output, WHITE, BLACK); //输出
    LCD_DrawImage1BPP(82 + 42 + 11 + 11 + 11 + 11 + 21 + 11 + 21 + 42, 100 + 38 * 2, BMP_DL, WHITE, BLACK); //电流
    LCD_DrawImage1BPP(400 - 24 + 60, 100 + 38 * 2, BMP_a, WHITE, BLACK); //A

    LCD_DrawImage1BPP(82 + 320 + 60, 100, BMP_Sanreqi, WHITE, BLACK); //散热器
    LCD_DrawImage1BPP(82 + 63 + 320 + 60, 100, BMP_Wendu, WHITE, BLACK); //温度
    LCD_DrawImage1BPP(82 + 63 + 320 + 60 + 42 + 2, 100 + 5, BMP_Maohao, WHITE, BLACK); //:
    LCD_DrawImage1BPP(720 - 24, 100, BMP_T, WHITE, BLACK); //℃

    LCD_DrawImage1BPP(82 + 320 + 60, 100 + 38, BMP_Guzhang, WHITE, BLACK); //故障
    LCD_DrawImage1BPP(82 + 42 + 320 + 60, 100 + 38, BMP_Code, WHITE, BLACK); //代码
    LCD_DrawImage1BPP(82 + 42 + 320 + 60 + 42 + 2, 100 + 5 + 38, BMP_Maohao, WHITE, BLACK); //:
}

void FuzhuUpdate(void) {
    print_SZ_1(82 + 270, 100 - 8, DCAC_W * 0.1 - 1000, 4, 0, WHITE); //W相电流
    print_SZ_1(82 + 270, 100 - 8 + 38, DCAC_V * 0.1 - 1000, 4, 0, WHITE); //W相电流
    print_SZ_1(82 + 270, 100 - 8 + 38 * 2, DCAC_U * 0.1 - 1000, 4, 0, WHITE); //W相电流
    updata_T(82 + 63 + 42 + 80 + 32 + 320, 100 - 8, WHITE, Sanreqi_t, 1, 40); //散热器温度
    print_SZ_1(82 + 270 + 320 - 52, 100 - 8 + 38, DCAC_Warn_code, 3, 0, WHITE); //故障码
}

void frmFuzhu(void) {
    if (f_index == 0) { //只更新一次
        f_index = 1;
        FuzhuFrame();
    } else if (f_index == 1) {
        f_index = 1;
        FuzhuUpdate();
    } else {
        f_index = 0;
    }
    if (key_AV) {
        key_AV = 0;
    }

    if (key_up) {
        key_up = 0;
        f_index = 0;
        frmID = 1;
    }

    if (key_set) {//返回主界面
        key_set = 0;
        frmID = 0;
        f_index = 0;
        Index = 0;
    }
    if (key_long_set) {
        key_long_set = 0;
    }

}

/******************************************************/
void TCUFrame(void) {
    unsigned char i = 0;
    LCD_Clear();
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //顶部横线
    LCD_DrawImage1BPP(130 + 200, 130 - 85, BMP_TCU, WHITE, BLACK); //TCU
    LCD_DrawImage1BPP(130 + 200 + 50, 130 - 85, BMP_STSTEM, WHITE, BLACK); //系统
    LCD_DrawImage1BPP(130 + 200 + 50 + 50, 130 - 85, BMP_Message, WHITE, BLACK); //信息

    LCD_DrawRect(80, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320 + 50, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320 + 320, 90, 1, 380, GREEN);
    for (i = 0; i < 11; i++)
        LCD_DrawRect(80, 90 + i * 38, 640, 1, GREEN);

    LCD_DrawImage1BPP(82, 100, BMP_Lihe, WHITE, BLACK); //离合
    LCD_DrawImage1BPP(82 + 42, 100, BMP_Shiji, WHITE, BLACK); //实际
    LCD_DrawImage1BPP(82 + 42 + 42, 100, BMP_Weizhi, WHITE, BLACK); //位置

    LCD_DrawImage1BPP(82, 100 + 38, BMP_Dangwei, WHITE, BLACK); //档位  

    LCD_DrawImage1BPP(82, 100 + 38 * 2, BMP_t, WHITE, BLACK); //T
    LCD_DrawImage1BPP(82 + 11, 100 + 38 * 2, BMP_c, WHITE, BLACK); //C
    LCD_DrawImage1BPP(82 + 11 + 11, 100 + 38 * 2, BMP_u, WHITE, BLACK); //U
    LCD_DrawImage1BPP(82 + 11 + 11 + 11, 100 + 38 * 2, BMP_Guzhang, WHITE, BLACK); //故障
    LCD_DrawImage1BPP(82 + 11 + 11 + 11 + 42, 100 + 38 * 2, BMP_Xinxi, WHITE, BLACK); //信息

    LCD_DrawImage1BPP(82, 100 + 38 * 3, BMP_Biansuxiang, WHITE, BLACK); //变速箱
    LCD_DrawImage1BPP(82 + 63, 100 + 38 * 3, BMP_Output, WHITE, BLACK); //输出
    LCD_DrawImage1BPP(82 + 63 + 42, 100 + 38 * 3, BMP_Zhou, WHITE, BLACK); //轴
    LCD_DrawImage1BPP(82 + 63 + 42 + 21, 100 + 38 * 3, BMP_Zhuansu, WHITE, BLACK); //转速
    LCD_DrawImage1BPP(400 - 42 + 50, 100 + 38 * 3, BMP_RPM, WHITE, BLACK); //RPM

    LCD_DrawImage1BPP(82 + 320 + 50, 100, BMP_f, WHITE, BLACK); //F
    LCD_DrawImage1BPP(82 + 11 + 320 + 50, 100, BMP_m, WHITE, BLACK); //M
    LCD_DrawImage1BPP(82 + 11 + 11 + 320 + 50, 100, BMP_i, WHITE, BLACK); //I
    LCD_DrawImage1BPP(82 + 11 + 11 + 11 + 320 + 50 + 2, 100 + 5, BMP_Maohao, WHITE, BLACK); //:

    LCD_DrawImage1BPP(82 + 320 + 50, 100 + 38, BMP_s, WHITE, BLACK); //S
    LCD_DrawImage1BPP(82 + 11 + 320 + 50, 100 + 38, BMP_p, WHITE, BLACK); //P
    LCD_DrawImage1BPP(82 + 11 + 11 + 320 + 50, 100 + 38, BMP_n, WHITE, BLACK); //N
    LCD_DrawImage1BPP(82 + 11 + 11 + 11 + 320 + 50 + 2, 100 + 5 + 38, BMP_Maohao, WHITE, BLACK); //:

    LCD_DrawImage1BPP(82 + 320 + 50, 100 + 38 * 2, BMP_c, WHITE, BLACK); //C
    LCD_DrawImage1BPP(82 + 11 + 320 + 50, 100 + 38 * 2, BMP_m, WHITE, BLACK); //M
    LCD_DrawImage1BPP(82 + 11 + 11 + 320 + 50 + 2, 100 + 5 + 38 * 2, BMP_Maohao, WHITE, BLACK); //:

    LCD_DrawImage1BPP(82 + 320 + 50, 100 + 38 * 3, BMP_o, WHITE, BLACK); //O
    LCD_DrawImage1BPP(82 + 11 + 320 + 50, 100 + 38 * 3, BMP_c, WHITE, BLACK); //C
    LCD_DrawImage1BPP(82 + 11 + 11 + 320 + 50 + 2, 100 + 5 + 38 * 3, BMP_Maohao, WHITE, BLACK); //:
}

void TCUUpdate(void) {
    print_SZ_1(82 + 200, 100 - 8, TCU_Position, 1, 0, WHITE); //TCU位置
    print_SZ_1(82 + 200, 100 - 8 + 38, Current_Gear, 1, 0, WHITE); //档位
    print_D(82 + 200, 100 - 8 + 38 * 2, TCU_code); //故障码
    print_SZ_1(82 + 200, 100 - 8 + 38 * 3, Speed_rmp, 4, 0, WHITE); //输出轴转速
    print_SZ_1(82 + 150 + 320 + 16, 100 - 8, tcu_fmi, 2, 0, WHITE); //fmi
    print_H(82 + 150 + 320 - 48, 100 - 8 + 38, tcu_spn, 6, 0, WHITE); //spn
    print_SZ_1(82 + 150 + 320 + 32, 100 - 8 + 38 * 2, tcu_cm, 1, 0, WHITE); //cm
    print_H(82 + 150 + 320 + 16, 100 - 8 + 38 * 3, tcu_oc, 2, 0, WHITE); //oc
}

void frmTCU(void) {
    if (f_index == 0) { //只更新一次
        f_index = 1;
        TCUFrame();
    } else if (f_index == 1) {
        f_index = 1;
        TCUUpdate();
    } else {
        f_index = 0;
    }
    if (key_AV) {
        key_AV = 0;
    }

    if (key_up) {
        key_up = 0;
        f_index = 0;
        frmID = 1;
    }

    if (key_set) {//返回主界面
        key_set = 0;
        frmID = 0;
        f_index = 0;
        Index = 0;
    }
    if (key_long_set) {
        key_long_set = 0;
    }

}

/******************************************************/
void BMSFrame(void) {
    unsigned char i = 0;
    LCD_Clear();
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //顶部横线
    LCD_DrawImage1BPP(130 + 200 - 24, 130 - 85, BMP_Battery, WHITE, BLACK); //电池
    LCD_DrawImage1BPP(130 + 200 + 50 - 24, 130 - 85, BMP_Manage, WHITE, BLACK); //管理
    LCD_DrawImage1BPP(130 + 200 + 50 + 50 - 24, 130 - 85, BMP_STSTEM, WHITE, BLACK); //系统
    LCD_DrawImage1BPP(130 + 200 + 50 + 50 + 50 - 24, 130 - 85, BMP_Message, WHITE, BLACK); //信息

    LCD_DrawRect(80, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320 + 320, 90, 1, 380, GREEN);
    for (i = 0; i < 11; i++)
        LCD_DrawRect(80, 90 + i * 38, 640, 1, GREEN);

    LCD_DrawImage1BPP(82, 100, BMP_DC, WHITE, BLACK); //电池
    LCD_DrawImage1BPP(82 + 42, 100, BMP_Zong, WHITE, BLACK); //总
    LCD_DrawImage1BPP(82 + 42 + 21, 100, BMP_DY, WHITE, BLACK); //电压
    LCD_DrawImage1BPP(82 + 42 + 21 + 42 + 2, 100 + 5, BMP_Maohao, WHITE, BLACK); //:
    LCD_DrawImage1BPP(400 - 24, 100, BMP_v, WHITE, BLACK); //V

    LCD_DrawImage1BPP(82, 100 + 38, BMP_Zui, WHITE, BLACK); //最
    LCD_DrawImage1BPP(82 + 21, 100 + 38, BMP_Da, WHITE, BLACK); //大
    LCD_DrawImage1BPP(82 + 21 + 21, 100 + 38, BMP_Yunxu, WHITE, BLACK); //允许
    LCD_DrawImage1BPP(82 + 21 + 21 + 42, 100 + 38, BMP_Chong, WHITE, BLACK); //充
    LCD_DrawImage1BPP(82 + 21 + 21 + 42 + 21, 100 + 38, BMP_DY, WHITE, BLACK); //电
    LCD_DrawImage1BPP(82 + 21 + 21 + 42 + 21 + 21, 100 + 38, BMP_DL, WHITE, BLACK); //电流
    LCD_DrawImage1BPP(82 + 21 + 21 + 42 + 21 + 21 + 42 + 2, 100 + 38 + 5, BMP_Maohao, WHITE, BLACK); //:
    LCD_DrawImage1BPP(400 - 24, 100 + 38, BMP_a, WHITE, BLACK); //A

    LCD_DrawImage1BPP(82, 100 + 38 * 2, BMP_Zui, WHITE, BLACK); //最
    LCD_DrawImage1BPP(82 + 21, 100 + 38 * 2, BMP_Da, WHITE, BLACK); //大
    LCD_DrawImage1BPP(82 + 21 + 21, 100 + 38 * 2, BMP_Yunxu, WHITE, BLACK); //允许
    LCD_DrawImage1BPP(82 + 21 + 21 + 42, 100 + 38 * 2, BMP_Fang, WHITE, BLACK); //放
    LCD_DrawImage1BPP(82 + 21 + 21 + 42 + 21, 100 + 38 * 2, BMP_DY, WHITE, BLACK); //电
    LCD_DrawImage1BPP(82 + 21 + 21 + 42 + 21 + 21, 100 + 38 * 2, BMP_DL, WHITE, BLACK); //电流
    LCD_DrawImage1BPP(82 + 21 + 21 + 42 + 21 + 21 + 42 + 2, 100 + 38 * 2 + 5, BMP_Maohao, WHITE, BLACK); //:
    LCD_DrawImage1BPP(400 - 24, 100 + 38 * 2, BMP_a, WHITE, BLACK); //A

    LCD_DrawImage1BPP(82, 100 + 38 * 3, BMP_Dan, WHITE, BLACK); //单
    LCD_DrawImage1BPP(82 + 21, 100 + 38 * 3, BMP_Ti, WHITE, BLACK); //体
    LCD_DrawImage1BPP(82 + 21 + 21, 100 + 38 * 3, BMP_Pingjun, WHITE, BLACK); //平均
    LCD_DrawImage1BPP(82 + 21 + 21 + 42, 100 + 38 * 3, BMP_DY, WHITE, BLACK); //电压
    LCD_DrawImage1BPP(82 + 21 + 21 + 42 + 42 + 2, 100 + 38 * 3 + 5, BMP_Maohao, WHITE, BLACK); //:
    LCD_DrawImage1BPP(400 - 24, 100 + 38 * 3, BMP_v, WHITE, BLACK); //V

    LCD_DrawImage1BPP(82, 100 + 38 * 4, BMP_DC, WHITE, BLACK); //电池
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 4, BMP_Zhuangtai, WHITE, BLACK); //状态
    LCD_DrawImage1BPP(82 + 42 + 42, 100 - 8 + 38 * 4, BMP_SZ_1[1], WHITE, BLACK); //1
    LCD_DrawImage1BPP(82 + 42 + 42 + 16 + 2, 100 + 5 + 38 * 4, BMP_Maohao, WHITE, BLACK); //:

    LCD_DrawImage1BPP(82, 100 + 38 * 5, BMP_DC, WHITE, BLACK); //电池
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 5, BMP_Zhuangtai, WHITE, BLACK); //状态
    LCD_DrawImage1BPP(82 + 42 + 42, 100 - 8 + 38 * 5, BMP_SZ_1[2], WHITE, BLACK); //2
    LCD_DrawImage1BPP(82 + 42 + 42 + 16 + 2, 100 + 5 + 38 * 5, BMP_Maohao, WHITE, BLACK); //:

    LCD_DrawImage1BPP(82, 100 + 38 * 6, BMP_DC, WHITE, BLACK); //电池
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 6, BMP_Zhuangtai, WHITE, BLACK); //状态
    LCD_DrawImage1BPP(82 + 42 + 42, 100 - 8 + 38 * 6, BMP_SZ_1[3], WHITE, BLACK); //3
    LCD_DrawImage1BPP(82 + 42 + 42 + 16 + 2, 100 + 5 + 38 * 6, BMP_Maohao, WHITE, BLACK); //:

    LCD_DrawImage1BPP(82 + 320, 100, BMP_Zong, WHITE, BLACK); //总
    LCD_DrawImage1BPP(82 + 320 + 21, 100, BMP_Zheng, WHITE, BLACK); //正
    LCD_DrawImage1BPP(82 + 320 + 21 + 21, 100, BMP_Jueyuan, WHITE, BLACK); //绝缘
    LCD_DrawImage1BPP(82 + 320 + 42 + 42, 100, BMP_DC, WHITE, BLACK); //电池
    LCD_DrawImage1BPP(82 + 320 + 42 + 42 + 21, 100, BMP_Zu, WHITE, BLACK); //阻
    LCD_DrawImage1BPP(82 + 320 + 42 + 42 + 21 + 21 + 2, 100 + 5, BMP_Maohao, WHITE, BLACK); //:
    LCD_DrawImage1BPP(720 - 28, 100, BMP_k, WHITE, BLACK); //K
    LCD_DrawImage1BPP(720 - 16, 100 + 2, BMP_Omu, WHITE, BLACK); //Ω

    LCD_DrawImage1BPP(82 + 320, 100 + 38, BMP_Zong, WHITE, BLACK); //总
    LCD_DrawImage1BPP(82 + 320 + 21, 100 + 38, BMP_Fuhe, WHITE, BLACK); //负荷
    LCD_DrawImage1BPP(82 + 320 + 21 + 21, 100 + 38, BMP_Jueyuan, WHITE, BLACK); //绝缘
    LCD_DrawImage1BPP(82 + 320 + 42 + 42, 100 + 38, BMP_DC, WHITE, BLACK); //电池
    LCD_DrawImage1BPP(82 + 320 + 42 + 42 + 21, 100 + 38, BMP_Zu, WHITE, BLACK); //阻
    LCD_DrawImage1BPP(82 + 320 + 42 + 42 + 21 + 21 + 2, 100 + 5 + 38, BMP_Maohao, WHITE, BLACK); //:
    LCD_DrawImage1BPP(720 - 28, 100 + 38, BMP_k, WHITE, BLACK); //K
    LCD_DrawImage1BPP(720 - 16, 100 + 38 + 2, BMP_Omu, WHITE, BLACK); //Ω

    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 2, BMP_Dan, WHITE, BLACK); //单
    LCD_DrawImage1BPP(82 + 320 + 21, 100 + 38 * 2, BMP_Ti, WHITE, BLACK); //体
    LCD_DrawImage1BPP(82 + 320 + 21 + 21, 100 + 38 * 2, BMP_Zui, WHITE, BLACK); //最
    LCD_DrawImage1BPP(82 + 320 + 21 + 21 + 21, 100 + 38 * 2, BMP_Gao, WHITE, BLACK); //高
    LCD_DrawImage1BPP(82 + 320 + 21 + 21 + 21 + 21, 100 + 38 * 2, BMP_DY, WHITE, BLACK); //电压
    LCD_DrawImage1BPP(82 + 320 + 21 + 21 + 21 + 21 + 42 + 2, 100 + 5 + 38 * 2, BMP_Maohao, WHITE, BLACK); //:
    LCD_DrawImage1BPP(720 - 24, 100 + 38 * 2, BMP_v, WHITE, BLACK); //V

    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 3, BMP_Dan, WHITE, BLACK); //单
    LCD_DrawImage1BPP(82 + 320 + 21, 100 + 38 * 3, BMP_Ti, WHITE, BLACK); //体
    LCD_DrawImage1BPP(82 + 320 + 21 + 21, 100 + 38 * 3, BMP_Zui, WHITE, BLACK); //最
    LCD_DrawImage1BPP(82 + 320 + 21 + 21 + 21, 100 + 38 * 3, BMP_Di, WHITE, BLACK); //低
    LCD_DrawImage1BPP(82 + 320 + 21 + 21 + 21 + 21, 100 + 38 * 3, BMP_DY, WHITE, BLACK); //电压
    LCD_DrawImage1BPP(82 + 320 + 21 + 21 + 21 + 21 + 42 + 2, 100 + 5 + 38 * 3, BMP_Maohao, WHITE, BLACK); //:
    LCD_DrawImage1BPP(720 - 24, 100 + 38 * 3, BMP_v, WHITE, BLACK); //V

    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 4, BMP_Dan, WHITE, BLACK); //单
    LCD_DrawImage1BPP(82 + 320 + 21, 100 + 38 * 4, BMP_Ti, WHITE, BLACK); //体
    LCD_DrawImage1BPP(82 + 320 + 21 + 21, 100 + 38 * 4, BMP_Zui, WHITE, BLACK); //最
    LCD_DrawImage1BPP(82 + 320 + 21 + 21 + 21, 100 + 38 * 4, BMP_Gao, WHITE, BLACK); //高
    LCD_DrawImage1BPP(82 + 320 + 21 + 21 + 21 + 21, 100 + 38 * 4, BMP_Wendu, WHITE, BLACK); //温度
    LCD_DrawImage1BPP(82 + 320 + 21 + 21 + 21 + 21 + 42 + 2, 100 + 5 + 38 * 4, BMP_Maohao, WHITE, BLACK); //:
    LCD_DrawImage1BPP(720 - 28, 100 + 38 * 4, BMP_T, WHITE, BLACK); //℃

    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 5, BMP_Chong, WHITE, BLACK); //充
    LCD_DrawImage1BPP(82 + 320 + 21, 100 + 38 * 5, BMP_Fang, WHITE, BLACK); //放
    LCD_DrawImage1BPP(82 + 320 + 21 + 21, 100 + 38 * 5, BMP_DC, WHITE, BLACK); //电池
    LCD_DrawImage1BPP(82 + 320 + 21 + 21 + 21, 100 + 38 * 5, BMP_DL, WHITE, BLACK); //电流
    LCD_DrawImage1BPP(82 + 320 + 21 + 21 + 21 + 42 + 2, 100 + 5 + 38 * 5, BMP_Maohao, WHITE, BLACK); //:
    LCD_DrawImage1BPP(720 - 24, 100 + 38 * 5, BMP_a, WHITE, BLACK); //V
    /*******************************/

}

void BMSUpdate(void) {
    updata_DCDY(82 + 200 + 30, 100 - 8);
    updata_DCDL(82 + 200 + 30 + 320 - 16, 100 - 8 + 38 * 5);
    print_D(82 + 180, 100 - 8 + 38 * 4, Status_Flag1);
    print_D(82 + 180, 100 - 8 + 38 * 5, Status_Flag2);
    print_D(82 + 180, 100 - 8 + 38 * 6, Status_Flag3);
    print_SZ_1(82 + 200 + 30, 100 - 8 + 38, BMS_A_charge * 0.1 - 1000, 3, 0, WHITE); //允许充电电流
    print_SZ_1(82 + 200 + 30, 100 - 8 + 38 * 2, BMS_A_discharge * 0.1 - 1000, 3, 0, WHITE); //允许放电电流
    print_SZ_1(82 + 200 + 30 - 16, 100 - 8 + 38 * 3, BMS_V_average - 10000, 3, 2, WHITE); //电池平均电压
    print_SZ_1(82 + 200 + 30 + 270, 100 - 8, Oum_zheng, 5, 0, WHITE); //绝缘正
    print_SZ_1(82 + 200 + 30 + 270, 100 - 8 + 38, Oum_fu, 5, 0, WHITE); //绝缘负
    print_SZ_1(82 + 200 + 30 + 270 + 16, 100 - 8 + 38 * 2, Battery_single_H - 10000, 3, 2, WHITE); //电池最高电压
    print_SZ_1(82 + 200 + 30 + 270 + 16, 100 - 8 + 38 * 3, Battery_single_L - 10000, 3, 2, WHITE); //电池最低电压
    updata_T(82 + 200 + 30 + 270 + 32, 100 - 8 + 38 * 4, WHITE, BMS_T_H, 1, 40); //最高温度
}

void frmBMS(void) {
    if (f_index == 0) { //只更新一次
        f_index = 1;
        BMSFrame();
    } else if (f_index == 1) {
        f_index = 1;
        BMSUpdate();
    } else {
        f_index = 0;
    }
    if (key_AV) {
        key_AV = 0;
    }

    if (key_up) {
        key_up = 0;
        f_index = 0;
        frmID = 1;
    }

    if (key_set) {//返回主界面
        key_set = 0;
        frmID = 0;
        f_index = 0;
        Index = 0;
    }
    if (key_long_set) {
        key_long_set = 0;
    }

}

/******************************************************/
void BatteryFrame(void) {
    unsigned char i, j;
    LCD_Clear();
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //顶部横线
    LCD_DrawImage1BPP(130 + 200 + 24, 130 - 85, BMP_Battery, WHITE, BLACK); //电池
    LCD_DrawImage1BPP(130 + 200 + 50 + 24, 130 - 85, BMP_Message, WHITE, BLACK); //信息
    //分格
    for (i = 0; i < 3; i++)
        LCD_DrawRect(80 + 320 * i, 90, 1, 380, GREEN);
    for (i = 0; i < 11; i++)
        LCD_DrawRect(80, 90 + i * 38, 640, 1, GREEN);
    for (j = 0; j < 2; j++) {
        for (i = 0; i < 10; i++) {
            if (i < 9) {//写编号个位
                LCD_DrawImage1BPP(40 + 5 + 16 + 36 + j * 320, 92 + i * 38, BMP_SZ_1[i + 1], WHITE, BLACK);
            } else {//写最底下一行编号
                LCD_DrawImage1BPP(40 + 5 + 16 + 36 + j * 320, 92 + i * 38, BMP_SZ_1[0], WHITE, BLACK);
                LCD_DrawImage1BPP(40 + 5 + 36 + j * 320, 92 + i * 38, BMP_SZ_1[1], WHITE, BLACK);
            }
            if (j == 0)
                LCD_DrawImage1BPP(40 + 5 + 72 + 250, 92 + i * 38, BMP_V, YELLOW, BLACK);
            else
                LCD_DrawImage1BPP(40 + 5 + 70 + 250 + 320, 100 + i * 38, BMP_T, YELLOW, BLACK);
        }
    }

    /********************一个界面显示50个单位*****************************/
    //分格
    /*
    for (i = 0; i < 6; i++) {
        LCD_DrawRect(i * 160, 45 + 70, 1, 360, GRAY);
        LCD_DrawRect(60 + i * 160, 45 + 70, 1, 360, GRAY);
    }
    for (i = 0; i < 13; i++)
        LCD_DrawRect(0, 45 + 70 + i * 36, 800, 1, GRAY);

    LCD_DrawImage1BPP(50, 90, BMP_DC, WHITE, BLACK); //电池
    LCD_DrawImage1BPP(50 + 42, 90, BMP_DY, WHITE, BLACK); //电压
    LCD_DrawImage1BPP(50 + 42 + 42 + 15, 90 - 9, BMP_SZ_1[index + 1], GREEN, BLACK);

    //编号
    if (index == 0) {
        for (j = 0; j < 5; j++) {
            for (i = 0; i < 11; i++) {
                if (i < 9) {//写编号个位
                    LCD_DrawImage1BPP(5 + 16 + 16 + j * 160, 46 + 70 + i * 36, BMP_SZ_1[i + 1], WHITE, BLACK);
                    if (j > 0) {//写编号十位
                        LCD_DrawImage1BPP(5 + 16 + j * 160, 46 + 70 + i * 36, BMP_SZ_1[j], WHITE, BLACK);
                    }
                } else {//写最底下一行编号
                    LCD_DrawImage1BPP(5 + 16 + 16 + j * 160, 46 + 70 + i * 36, BMP_SZ_1[0], WHITE, BLACK);
                    LCD_DrawImage1BPP(5 + 16 + j * 160, 46 + 70 + i * 36, BMP_SZ_1[j + 1], WHITE, BLACK);
                }
                LCD_DrawImage1BPP(5 + 4 + 16 + 16 + 100 + j * 160, 46 + 70 + i * 36, BMP_V, YELLOW, BLACK);
            }
        }
    }

    if (index == 1) {
        for (j = 0; j < 5; j++) {
            for (i = 0; i < 11; i++) {
                if (i < 9) {//写编号个位
                    LCD_DrawImage1BPP(5 + 16 + 16 + j * 160, 46 + 70 + i * 36, BMP_SZ_1[i + 1], WHITE, BLACK); 
                    LCD_DrawImage1BPP(5 + 16 + j * 160, 46 + 70 + i * 36, BMP_SZ_1[j+5], WHITE, BLACK);                   
                } else {//写最底下一行编号
                    if(j<4){
                    LCD_DrawImage1BPP(5 + 16 + 16 + j * 160, 46 + 70 + i * 36, BMP_SZ_1[0], WHITE, BLACK);
                    LCD_DrawImage1BPP(5 + 16 + j * 160, 46 + 70 + i * 36, BMP_SZ_1[j + 6], WHITE, BLACK);
                    }else{
                        LCD_DrawImage1BPP(5 + 16 + 16 + j * 160, 46 + 70 + i * 36, BMP_SZ_1[0], WHITE, BLACK);
                        LCD_DrawImage1BPP(5 + 16 + j * 160, 46 + 70 + i * 36, BMP_SZ_1[0], WHITE, BLACK);   
                        LCD_DrawImage1BPP(5 + j * 160, 46 + 70 + i * 36, BMP_SZ_1[1], WHITE, BLACK); 
                    }
                }
                LCD_DrawImage1BPP(5 + 4 + 16 + 16 + 100 + j * 160, 46 + 70 + i * 36, BMP_V, YELLOW, BLACK);
            }
        }
    }
    
    if (index == 2) {
        for (j = 0; j < 5; j++) {
            for (i = 0; i < 11; i++) {
                if (i < 9) {
                    LCD_DrawImage1BPP(5 + 16 + 16 + j * 160, 46 + 70 + i * 36, BMP_SZ_1[i + 1], WHITE, BLACK);
                    LCD_DrawImage1BPP(5 + 16 + j * 160, 46 + 70 + i * 36, BMP_SZ_1[j], WHITE, BLACK);
                } else {//写最底下一行编号
                    LCD_DrawImage1BPP(5 + 16 + 16 + j * 160, 46 + 70 + i * 36, BMP_SZ_1[0], WHITE, BLACK);
                    LCD_DrawImage1BPP(5 + 16 + j * 160, 46 + 70 + i * 36, BMP_SZ_1[j + 1], WHITE, BLACK);
                }
                LCD_DrawImage1BPP(5 + 4 + 16 + 16 + 100 + j * 160, 46 + 70 + i * 36, BMP_V, YELLOW, BLACK);
                LCD_DrawImage1BPP(5 + j * 160, 46 + 70 + i * 36, BMP_SZ_1[1], WHITE, BLACK);
            }
        }
    }
    
    if (index == 3) {
        LCD_DrawImage1BPP(50, 90, BMP_DC, WHITE, BLACK); //电池
        LCD_DrawImage1BPP(50 + 42, 90, BMP_Wendu, WHITE, BLACK); //电压
        LCD_DrawImage1BPP(50 + 42 + 42 + 15, 90 - 9, BMP_SZ_1[1], GREEN, BLACK);
        for (j = 0; j < 5; j++) {
            for (i = 0; i < 11; i++) {
                if (i < 9) {//写编号个位
                    LCD_DrawImage1BPP(5 + 16 + 16 + j * 160, 46 + 70 + i * 36, BMP_SZ_1[i + 1], WHITE, BLACK);
                    if (j > 0) {//写编号十位
                        LCD_DrawImage1BPP(5 + 16 + j * 160, 46 + 70 + i * 36, BMP_SZ_1[j], WHITE, BLACK);
                    }
                } else {//写最底下一行编号
                    LCD_DrawImage1BPP(5 + 16 + 16 + j * 160, 46 + 70 + i * 36, BMP_SZ_1[0], WHITE, BLACK);
                    LCD_DrawImage1BPP(5 + 16 + j * 160, 46 + 70 + i * 36, BMP_SZ_1[j + 1], WHITE, BLACK);
                }
                LCD_DrawRect(5 + 4 + 16 + 16 + 100 + j * 160, 46 + 70 + i * 36, 16, 33, BLACK);
                LCD_DrawImage1BPP(4 + 16 + 16 + 100 + j * 160, 54 + 70 + i * 36, BMP_T, YELLOW, BLACK);
            }
        }
    }*/
    /*****************************************************************************/
}

void BatteryUpdate(void) {
    unsigned char i;
    for (i = 0; i < 10; i++) {
        print_SZ_1(82 + 200 - 100, 100 - 8 + 38 * i, Battery_number[i], 3, 0, GREEN); //单体电压编号
        print_SZ_1(82 + 200, 100 - 8 + 38 * i, Battery_voltage[i] - 10000, 3, 2, WHITE); //单体电压
    }
    for (i = 0; i < 10; i++) {
        print_SZ_1(82 + 200 - 100 + 300, 100 - 8 + 38 * i, Battery_number_t[i], 3, 0, GREEN); //单体温度编号
        updata_T(82 + 200 + 320, 100 - 8 + 38 * i, WHITE, Battery_temp[i], 1, 40); //单体温度
    }
}

void frmBattery(void) {
    if (f_index == 0) { //只更新一次
        f_index = 1;
        BatteryFrame();
        /*多界面切换
        if (Index == 0)
            BatteryFrame(0);
        if (Index == 1)
            BatteryFrame(1);
        if (Index == 2)
            BatteryFrame(2);
        if (Index == 3)
            BatteryFrame(3);
         */
    } else if (f_index == 1) {
        f_index = 1;
        BatteryUpdate();
    } else {
        f_index = 0;
    }
    if (key_AV) {
        key_AV = 0;
    }

    if (key_up) {
        key_up = 0;
        f_index = 0;
        frmID = 1;
        //Index++;//多界面切换
        //if(Index==4) Index=0;
    }

    if (key_set) {//返回主界面
        key_set = 0;
        frmID = 0;
        f_index = 0;
        Index = 0;
    }
    if (key_long_set) {
        key_long_set = 0;
    }

}

/******************************************************/
void AirFrame(void) {
    unsigned char i = 0;
    LCD_Clear();
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //顶部横线
    LCD_DrawImage1BPP(130 + 200 - 2, 130 - 85, BMP_Air, WHITE, BLACK); //空调
    LCD_DrawImage1BPP(130 + 200 + 50 - 2, 130 - 85, BMP_STSTEM, WHITE, BLACK); //系统
    LCD_DrawImage1BPP(130 + 200 + 50 + 50 - 2, 130 - 85, BMP_Message, WHITE, BLACK); //信息

    LCD_DrawRect(80, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320 + 320, 90, 1, 380, GREEN);
    for (i = 0; i < 11; i++)
        LCD_DrawRect(80, 90 + i * 38, 640, 1, GREEN);

    LCD_DrawImage1BPP(82, 100, BMP_Kongtiao, WHITE, BLACK); //空调
    LCD_DrawImage1BPP(82 + 42, 100, BMP_Guzhang, WHITE, BLACK); //故障
    LCD_DrawImage1BPP(82 + 42 + 42, 100, BMP_Code, WHITE, BLACK); //代码
    LCD_DrawImage1BPP(82 + 42 + 42 + 42 + 2, 100 + 5, BMP_Maohao, WHITE, BLACK); //:

    LCD_DrawImage1BPP(82, 100 + 38, BMP_Kongtiao, WHITE, BLACK); //空调
    LCD_DrawImage1BPP(82 + 42, 100 + 38, BMP_Feng, WHITE, BLACK); //风
    LCD_DrawImage1BPP(82 + 42 + 21, 100 + 38, BMP_DJ, WHITE, BLACK); //电机
    LCD_DrawImage1BPP(82 + 42 + 21 + 21, 100 + 38, BMP_Zhuangtai, WHITE, BLACK); //状态
    LCD_DrawImage1BPP(82 + 42 + 21 + 21 + 42 + 2, 100 + 5 + 38, BMP_Maohao, WHITE, BLACK); //:

    LCD_DrawImage1BPP(82, 100 + 38 * 2, BMP_Kongtiao, WHITE, BLACK); //空调
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 2, BMP_Gongzuo, WHITE, BLACK); //工作
    LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 2, BMP_Zhuangtai, WHITE, BLACK); //状态
    LCD_DrawImage1BPP(82 + 42 + 42 + 42 + 2, 100 + 5 + 38 * 2, BMP_Maohao, WHITE, BLACK); //:

    LCD_DrawImage1BPP(82, 100 + 38 * 3, BMP_Kongtiao, WHITE, BLACK); //空调
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 3, BMP_Life, WHITE, BLACK); //Life
    LCD_DrawImage1BPP(82 + 42 + 44 + 2, 100 + 5 + 38 * 3, BMP_Maohao, WHITE, BLACK); //:

    LCD_DrawImage1BPP(82 + 320, 100, BMP_Che, WHITE, BLACK); //车
    LCD_DrawImage1BPP(82 + 320 + 21, 100, BMP_Wai, WHITE, BLACK); //外
    LCD_DrawImage1BPP(82 + 320 + 42, 100, BMP_Shiji, WHITE, BLACK); //实际
    LCD_DrawImage1BPP(82 + 320 + 42 + 42, 100, BMP_Wendu, WHITE, BLACK); //温度
    LCD_DrawImage1BPP(82 + 320 + 42 + 42 + 42 + 2, 100 + 5, BMP_Maohao, WHITE, BLACK); //:
    LCD_DrawImage1BPP(720 - 28, 100, BMP_T, WHITE, BLACK); //℃


    LCD_DrawImage1BPP(82 + 320, 100 + 38, BMP_Che, WHITE, BLACK); //车
    LCD_DrawImage1BPP(82 + 320 + 21, 100 + 38, BMP_Nei, WHITE, BLACK); //内
    LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38, BMP_Shiji, WHITE, BLACK); //实际
    LCD_DrawImage1BPP(82 + 320 + 42 + 42, 100 + 38, BMP_Wendu, WHITE, BLACK); //温度
    LCD_DrawImage1BPP(82 + 320 + 42 + 42 + 42 + 2, 100 + 5 + 38, BMP_Maohao, WHITE, BLACK); //:
    LCD_DrawImage1BPP(720 - 28, 100 + 38, BMP_T, WHITE, BLACK); //℃


    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 2, BMP_Sheding, WHITE, BLACK); //设定
    LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 2, BMP_Wendu, WHITE, BLACK); //温度
    LCD_DrawImage1BPP(82 + 320 + 42 + 42 + 2, 100 + 5 + 38 * 2, BMP_Maohao, WHITE, BLACK); //:
    LCD_DrawImage1BPP(720 - 28, 100 + 38 * 2, BMP_T, WHITE, BLACK); //℃

    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 3, BMP_Kongtiao, WHITE, BLACK); //空调
    LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 3, BMP_Zhilen, WHITE, BLACK); //制冷
    LCD_DrawImage1BPP(82 + 320 + 42 + 42, 100 + 38 * 3, BMP_Qingqiu, WHITE, BLACK); //请求
    LCD_DrawImage1BPP(82 + 320 + 42 + 42 + 42 + 2, 100 + 5 + 38 * 3, BMP_Maohao, WHITE, BLACK); //:  
}

void AirUpdate(void) {
    print_D(82 + 180, 100 - 8, AC_Warn_code); //空调故障码
    print_D(82 + 180, 100 - 8 + 38, AC_KEY[0].byte); //空调风速
    print_D(82 + 180, 100 - 8 + 38 * 2, AC_KEY[1].byte); //空调状态
    print_SZ_1(82 + 270 - 10, 100 - 8 + 38 * 3, AC_LIFE, 3, 0, WHITE); //空调LIFE
    updata_T(82 + 63 + 42 + 80 + 32 + 320, 100 - 8, WHITE, Indoor_t, 0.5, 30); //室内温度
    updata_T(82 + 63 + 42 + 80 + 32 + 320, 100 - 8 + 38, WHITE, Outdoor_t, 0.5, 30); //室外温度
    updata_T(82 + 63 + 42 + 80 + 32 + 320, 100 - 8 + 38 * 2, WHITE, Set_t, 0.5, 30); //设定温度
    print_D(82 + 180 + 320, 100 - 8 + 38 * 3, AC_req); //空调请求
}

void frmAir(void) {
    if (f_index == 0) { //只更新一次
        f_index = 1;
        AirFrame();
    } else if (f_index == 1) {
        f_index = 1;
        AirUpdate();
    } else {
        f_index = 0;
    }
    if (key_AV) {
        key_AV = 0;
    }

    if (key_up) {
        key_up = 0;
        f_index = 0;
        frmID = 1;
    }

    if (key_set) {//返回主界面
        key_set = 0;
        frmID = 0;
        f_index = 0;
        Index = 0;
    }
    if (key_long_set) {
        key_long_set = 0;
    }

}

/******************************************************/

void SETFrame(void) {
    LCD_Clear();
    //unsigned char i;
    //unsigned char color = WHITE;
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //顶部横线   
    LCD_DrawRect(0, 430 + 15, 800, 2, YELLOW); //底部横线   
    LCD_DrawImage1BPP(220, 195, Bmp_Licheng, WHITE, BLACK); //累计里程
    LCD_DrawImage1BPPZOOM_4(405, 190, BMP_HZ_KM, WHITE, BLACK); //单位 Km 
}
//一直更新的数据
void SETUpdate(unsigned int Tid, unsigned int *ptr) {
    unsigned char color = 0, color1 = 0;
    if (Tid == 0) {
        color = RED;
        color1 = RED;
    } else {
        color = GRAY;
        color1 = WHITE;
    }
    //disp_rectange(260+40*0,220,4,40,2,color);
    LCD_DrawImage1BPP(268 + 40 * 0, 230, BMP_SZ_1[*ptr++], color1, BLACK);

    if (Tid == 1) {
        color = RED;
        color1 = RED;
    } else {
        color = GRAY;
        color1 = WHITE;
    }
    //disp_rectange(260+40*1,220,4,40,2,color);
    LCD_DrawImage1BPP(268 + 40 * 1, 230, BMP_SZ_1[*ptr++], color1, BLACK);

    if (Tid == 2) {
        color = RED;
        color1 = RED;
    } else {
        color = GRAY;
        color1 = WHITE;
    }
    // disp_rectange(260+40*2,220,4,40,2,color);
    LCD_DrawImage1BPP(268 + 40 * 2, 230, BMP_SZ_1[*ptr++], color1, BLACK);

    if (Tid == 3) {
        color = RED;
        color1 = RED;
    } else {
        color = GRAY;
        color1 = WHITE;
    }
    //disp_rectange(260+40*3,220,4,40,2,color);
    LCD_DrawImage1BPP(268 + 40 * 3, 230, BMP_SZ_1[*ptr++], color1, BLACK);

    if (Tid == 4) {
        color = RED;
        color1 = RED;
    } else {
        color = GRAY;
        color1 = WHITE;
    }
    //disp_rectange(260+40*4,220,4,40,2,color);
    LCD_DrawImage1BPP(268 + 40 * 4, 230, BMP_SZ_1[*ptr++], color1, BLACK);

    if (Tid == 5) {
        color = RED;
        color1 = RED;
    } else {
        color = GRAY;
        color1 = WHITE;
    }
    //disp_rectange(260+40*5,220,4,40,2,color);
    LCD_DrawImage1BPP(268 + 40 * 5, 230, BMP_SZ_1[*ptr++], color1, BLACK);

    if (Tid == 6) {
        color = RED;
        color1 = RED;
    } else {
        color = GRAY;
        color1 = WHITE;
    }
    // disp_rectange(260+40*6,220,4,40,2,color);
    LCD_DrawImage1BPP(268 + 40 * 6, 230, BMP_SZ_1[*ptr++], color1, BLACK);
}

void frmSET(void) {
    static unsigned int Tid = 0;
    static unsigned int bcd[7] = {0, 0, 0, 0, 0, 0, 0};
    unsigned int i = 0;
    unsigned long tmiles = 0;
    if (f_index == 0) {
        f_index = 1;
        SETFrame();
        //delay_3s=12000;  
    } else if (f_index == 1) {
        f_index = 1;
        SETUpdate(Tid, &bcd[0]);
        print_SZ_1(290, 185, total_miles / 10, 7, 0, YELLOW);
    } else {
        f_index = 0;
    }
    if (key_up) {
        key_up = 0;
        //delay_3s=12000;  
        if (Tid >= 6)Tid = 0;
        else Tid++;
        tmiles = 0;
        for (i = 0; i < 7; i++) {
            tmiles += bcd[i];
            tmiles = tmiles * 10;
        }
        total_miles = tmiles;
        save_flag = 1;
        //delay_cnt = 500;
        //EEROM_ReadTotalMiles();
    }
    /*if (key_set) {
        key_set = 0;
        //delay_3s=12000; 
        if (Tid <= 6) {
            if (bcd[Tid] > 0) bcd[Tid]--;
            else bcd[Tid] = 0;
        } else Tid = 0;
    }*/
    if (key_AV) {
        key_AV = 0;
        //delay_3s=12000; 
        if (Tid <= 6) {
            if (bcd[Tid] < 9) bcd[Tid]++;
            else bcd[Tid] = 0;
        } else Tid = 0;
    }
    if (key_set) {
        key_set = 0;
        frmID = 0;
        f_index = 0;
    }

}

void LCD_Exec(void) {
    switch (frmID) {
        case 0:
            frmMain();
            break;
        case 1:
            frmMenu();
            break;
        case 2:
            //frmIC();
            frmControl();
            break;
        case 3:
            //frmBCU_f();
            frmEngine();
            break;
        case 4:
            //frmBCU_m();
            frmFuzhu();
            break;
        case 5:
            //frmBCU_r();
            frmTCU();
            break;
        case 6:
            //frmSET();
            frmBMS();
            break;
        case 7:
            //frmSET();
            frmBattery();
            break;
        case 8:
            //frmSET();
            frmAir();
            break;
        case 9:
            frmSET();
            break;
        case 10:
            frmIC();
            break;
        default:
            key_up = 0;
            key_set = 0;
            key_AV = 0;
            LCD_Clear();
            break;
    }
    if (key_duble) {
        key_duble = 0;
    }
}



