#include "SYSTEM.h"
#include "CHAR.h"
//#include "LOGO.h"

unsigned char Index = 0;
unsigned char t = 0;
unsigned char t_add = 0;
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

void print_SZ_2(unsigned int x, unsigned int y, //显示坐标位置//高清数字
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
            LCD_DrawImage1BPP(x + i * 16, y, BMP_SZ_2[bcd[i]], color, BLACK);
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
            LCD_DrawImage1BPP(x + i * 16, y, BMP_SZ_2[bcd[i]], color, BLACK);
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

/*void print_D(unsigned int x, unsigned int y, //以2进制显示
        unsigned char dat) { //显示的数据       
    unsigned char bcd[8], i = 0;
    for (i = 0; i < 8; i++) {
        bcd[i] = dat % 2;
        dat = dat / 2;
        LCD_DrawImage1BPP(x + 16 * (7 - i), y, BMP_SZ_1[bcd[i]], WHITE, BLACK);
    }
}*/
void print_D(unsigned int x, unsigned int y, //以2进制显示
        unsigned long dat, //显示的数据 
        unsigned char sum, //显示数据的几位
        unsigned char dot, //显示小数点的位数
        unsigned char color1) { //显示数据的颜色
    unsigned char color, f = 1, i = 0;
    unsigned char bcd[8];
    for (i = 0; i < sum; i++) {
        bcd[sum - i - 1] = dat % 2;
        dat = dat / 2;
    }
    for (i = 0; i < dot; i++) {
        bcd[sum - i] = bcd[sum - 1 - i];
    }
    bcd[sum - dot] = 16; //加入小数点  
    if (dot > 0) {
        for (i = 0; i <= sum; i++) {
            if (f && (bcd[i] == 0)&&(i < sum - 1 - dot)) { //不显示前面0
                f = 1;
                color = color1;
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
                color = color1;
            } else {
                f = 0;
                color = color1;
            }
            LCD_DrawImage1BPP(x + i * 16, y, BMP_SZ_1[bcd[i]], color, BLACK);
        }
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
    /*if (dot > 0) {
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
    }*/
    if (dot > 0) {
        for (i = 0; i <= sum; i++) {
            color = color1;
            LCD_DrawImage1BPP(x + i * 16, y, BMP_SZ_1[bcd[i]], color, BLACK);
        }
    } else {
        for (i = 0; i < sum; i++) {
            f = 0;
            color = color1;
            LCD_DrawImage1BPP(x + i * 16, y, BMP_SZ_1[bcd[i]], color, BLACK);
        }
    }
}

void LCD_DrawImageSBPP(unsigned int x, unsigned int y, //没有文字，字数填0，字模为BMP_BLANK       
        unsigned char witdh, //字体宽度
        __prog__ const unsigned char *img[], //字符串首地址
        unsigned char fcolor, //字体前景色
        unsigned char bcolor //字体背景色
        ) {
    unsigned char i;
    for (i = 0; img[i] != NULL; i++) {
        LCD_DrawImage1BPP(x + witdh * i, y, img[i], fcolor, bcolor);
    }
}

void disp_miles(void) {//显示里程
    /*
    print_SZ_1(0, 318 + 38 * 2, total_miles / 10, 6, 0, WHITE);
    print_SZ_1(16, 318 + 38, single_miles, 4, 1, WHITE);*/

    print_SZ_1(2 + 64 + 4 + 10, 440 - 2, total_miles / 10, 7, 0, WHITE);
    print_SZ_1(240 + 80 + 4 + 330 + 30 - 16, 440 - 2, single_miles, 5, 1, WHITE);

}

void disp_time(unsigned int x, unsigned int y, DATE dtimer) {
    unsigned char color = 0;
    static unsigned char color_back = 0;
    if (color_back && (t == 0)) {
        if (t_add) {//小时设置，十位
            timer.hour = timer.hour + 0x10;
            if ((timer.hour >> 4) > 2) {
                timer.hour = timer.hour & 0x0f;
            }
            DS3231_SetTime(&timer);
            t_add = 0;
        }
        LCD_DrawImage1BPP(x, y, BMP_SMSZ[(dtimer.hour >> 4)&0x0f], WHITE, GRAY);
    } else LCD_DrawImage1BPP(x, y, BMP_SMSZ[(dtimer.hour >> 4)&0x0f], WHITE, BLACK);

    if (color_back && (t == 1)) {
        if (t_add) {//小时设置，个位
            timer.hour = timer.hour + 0x01;
            if ((timer.hour & 0x0f) > 9) {
                timer.hour = timer.hour & 0xf0;
            }
            DS3231_SetTime(&timer);
            t_add = 0;
        }
        LCD_DrawImage1BPP(x + 28, y, BMP_SMSZ[dtimer.hour & 0x0f], WHITE, GRAY);
    } else LCD_DrawImage1BPP(x + 28, y, BMP_SMSZ[dtimer.hour & 0x0f], WHITE, BLACK);

    if (color_back && (t == 2)) {
        if (t_add) {//分钟设置，十位
            timer.minute = timer.minute + 0x10;
            if ((timer.minute >> 4) > 5) {
                timer.minute = timer.minute & 0x0f;
            }
            DS3231_SetTime(&timer);
            t_add = 0;
        }
        LCD_DrawImage1BPP(x + 28 * 3, y, BMP_SMSZ[(dtimer.minute >> 4)&0x0f], WHITE, GRAY);
    } else LCD_DrawImage1BPP(x + 28 * 3, y, BMP_SMSZ[(dtimer.minute >> 4)&0x0f], WHITE, BLACK);

    if (color_back && (t == 3)) {
        if (t_add) {//分钟设置，个位
            timer.minute = timer.minute + 0x01;
            if ((timer.minute & 0x0f) > 9) {
                timer.minute = timer.minute & 0xf0;
            }
            DS3231_SetTime(&timer);
            t_add = 0;
        }
        LCD_DrawImage1BPP(x + 28 * 4, y, BMP_SMSZ[dtimer.minute & 0x0f], WHITE, GRAY);
    } else LCD_DrawImage1BPP(x + 28 * 4, y, BMP_SMSZ[dtimer.minute & 0x0f], WHITE, BLACK);

    if (F500ms_LCD) color = WHITE;
    else color = BLACK;
    LCD_DrawImage1BPP(x + 28 * 2, y + 3, BMP_SMSZ[10], color, BLACK); //冒号 

    if (time_flag) {
        color_back = FLASH;
    } else {
        color_back = 0;
        t = 0;
    }

    /*****************年月日在子界面显示**********************/
    if (frmID == 1) {
        LCD_DrawImage1BPP(x + 260, y, BMP_SZ_1[2], WHITE, BLACK); //2
        LCD_DrawImage1BPP(x + 260 + 16, y, BMP_SZ_1[0], WHITE, BLACK); //0

        if (color_back && (t == 4)) {
            if (t_add) {//年设置，十位
                timer.year = timer.year + 0x10;
                if ((timer.year >> 4) > 9) {
                    timer.year = timer.year & 0x0f;
                }
                DS3231_SetTime(&timer);
                t_add = 0;
            }
            LCD_DrawImage1BPP(x + 260 + 16 * 2, y, BMP_SZ_1[(dtimer.year >> 4)&0x0f], WHITE, GRAY);
        } else LCD_DrawImage1BPP(x + 260 + 16 * 2, y, BMP_SZ_1[(dtimer.year >> 4)&0x0f], WHITE, BLACK);

        if (color_back && (t == 5)) {
            if (t_add) {//年设置，个位
                timer.year = timer.year + 0x01;
                if ((timer.year & 0x0f) > 9) {
                    timer.year = timer.year & 0xf0;
                }
                DS3231_SetTime(&timer);
                t_add = 0;
            }
            LCD_DrawImage1BPP(x + 260 + 16 * 3, y, BMP_SZ_1[dtimer.year & 0x0f], WHITE, GRAY);
        } else LCD_DrawImage1BPP(x + 260 + 16 * 3, y, BMP_SZ_1[dtimer.year & 0x0f], WHITE, BLACK);

        LCD_DrawImage1BPP(x + 260 + 16 * 4, y, BMP_SZ_1[17], WHITE, BLACK); //-

        if (color_back && (t == 6)) {
            if (t_add) {//月设置，十位
                timer.month = timer.month + 0x10;
                if ((timer.month >> 4) > 1) {
                    timer.month = timer.month & 0x0f;
                }
                DS3231_SetTime(&timer);
                t_add = 0;
            }
            LCD_DrawImage1BPP(x + 260 + 16 * 5, y, BMP_SZ_1[(dtimer.month >> 4)&0x0f], WHITE, GRAY);
        } else LCD_DrawImage1BPP(x + 260 + 16 * 5, y, BMP_SZ_1[(dtimer.month >> 4)&0x0f], WHITE, BLACK);

        if (color_back && (t == 7)) {
            if (t_add) {//月设置，个位
                timer.month = timer.month + 0x01;
                if ((timer.month & 0x0f) > 9) {
                    timer.month = timer.month & 0xf0;
                }
                DS3231_SetTime(&timer);
                t_add = 0;
            }
            LCD_DrawImage1BPP(x + 260 + 16 * 6, y, BMP_SZ_1[dtimer.month & 0x0f], WHITE, GRAY);
        } else LCD_DrawImage1BPP(x + 260 + 16 * 6, y, BMP_SZ_1[dtimer.month & 0x0f], WHITE, BLACK);

        LCD_DrawImage1BPP(x + 260 + 16 * 7, 440, BMP_SZ_1[17], WHITE, BLACK); //-

        if (color_back && (t == 8)) {
            if (t_add) {//日设置，十位
                timer.day = timer.day + 0x10;
                if ((timer.day >> 4) > 3) {
                    timer.day = timer.day & 0x0f;
                }
                DS3231_SetTime(&timer);
                t_add = 0;
            }
            LCD_DrawImage1BPP(x + 260 + 16 * 8, y, BMP_SZ_1[(dtimer.day >> 4)&0x0f], WHITE, GRAY);
        } else LCD_DrawImage1BPP(x + 260 + 16 * 8, y, BMP_SZ_1[(dtimer.day >> 4)&0x0f], WHITE, BLACK);

        if (color_back && (t == 9)) {
            if (t_add) {//日设置，个位
                timer.day = timer.day + 0x01;
                if ((timer.day & 0x0f) > 9) {
                    timer.day = timer.day & 0xf0;
                }
                DS3231_SetTime(&timer);
                t_add = 0;
            }
            LCD_DrawImage1BPP(x + 260 + 16 * 9, y, BMP_SZ_1[dtimer.day & 0x0f], WHITE, GRAY);
        } else LCD_DrawImage1BPP(x + 260 + 16 * 9, y, BMP_SZ_1[dtimer.day & 0x0f], WHITE, BLACK);

    }
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
    //unsigned char color_mode[3];

    if (IN18) color = YELLOW;
    else color = GRAY;
    if (color_old[0] != color) {
        color_old[0] = color;
        //LCD_DrawImage1BPP(6, 10, Bmp_baojing[1], color, BLACK); //ABS
    }

    if (VCU_FAULT) color = RED;
    else color = GRAY;
    if (color_old[1] != color) {
        color_old[1] = color;
        //LCD_DrawImage1BPP(6 + 66, 10, Bmp_baojing[14], color, BLACK); //系统故障
    }

    if (rKL11) color = RED;
    else color = GRAY;
    if (color_old[2] != color) {
        color_old[2] = color;
        //LCD_DrawImage1BPP(6 + 66 * 2, 10, Bmp_baojing[3], color, BLACK); //后舱门
    }

    if ((BMS_SOC > 30) && IN23) color = GREEN;
    else color = GRAY;
    if (color_old[3] != color) {
        color_old[3] = color;
        LCD_DrawImage1BPP(6 + 66 * 3, 10, Bmp_baojing[4], color, BLACK); //AC空调
    }

    if (0) color = GREEN;
    else color = GRAY;
    if (color_old[4] != color) {
        color_old[4] = color;
        LCD_DrawImage1BPP(6 + 66 * 4, 10, Bmp_baojing[5], color, BLACK); //Kt主接触器
    }

    if (rKL1) color = RED;
    else color = GRAY;
    if (color_old[5] != color) {
        color_old[5] = color;
        LCD_DrawImage1BPP(6 + 66 * 5, 10, Bmp_baojing[2], color, BLACK); //水位

    }

    if (IN18) color = YELLOW;
    else color = GRAY;
    if (color_old[6] != color) {
        color_old[6] = color;
        LCD_DrawImage1BPP(6 + 66 * 6, 10, Bmp_baojing[1], color, BLACK); //ABS
    }

    if (VCU_FAULT) color = RED;
    else color = GRAY;
    if (color_old[7] != color) {
        color_old[7] = color;
        LCD_DrawImage1BPP(6 + 66 * 7, 10, Bmp_baojing[14], color, BLACK); //系统故障
    }

    if (rKL11) color = RED;
    else color = GRAY;
    if (color_old[8] != color) {
        color_old[8] = color;
        LCD_DrawImage1BPP(6 + 66 * 8, 10, Bmp_baojing[3], color, BLACK); //后舱门
    }

    if (mKL2) color = RED;
    else color = GRAY;
    if (color_old[9] != color) {
        color_old[9] = color;
        //LCD_DrawImage1BPP(6 + 66 * 9, 10, Bmp_baojing[9], color, BLACK); //门铃
    }

    if ((IN24 || (Vcan_count == 30) ||
            (Bcan_count == 30) ||
            (Dcan_count == 30)))
        color = YELLOW;
    else color = GRAY;
    if (color_old[10] != color) {
        color_old[10] = color;
    }

    if (!fKL2) color = RED;
    else color = GRAY;
    if (color_old[15] != color) {
        color_old[15] = color;
        //LCD_DrawImage1BPP(138 + 66 * 1, 74, Bmp_baojing[10], color, BLACK); //前门1应急阀
        LCD_DrawImage1BPP(140 + 66 * 1, 74, Bmp_baojing[15], color, BLACK); //左前刹车片
        LCD_DrawImage1BPP(140 + 66 * 1 + 17, 74 + 15, BMP_l, color, BLACK);
        print_SZ(140 + 66 * 1 + 17 + 11, 74 + 18, 1, 1, 0, color); 
    }

    if (!rKL2) color = RED;
    else color = GRAY;
    if (color_old[16] != color) {
        color_old[16] = color;
        //LCD_DrawImage1BPP(138 + 66 * 2, 74, Bmp_baojing[11], color, BLACK); //前门2应急阀
        LCD_DrawImage1BPP(140 + 66 * 2, 74, Bmp_baojing[15], color, BLACK); //左后刹车片
        LCD_DrawImage1BPP(140 + 66 * 2 + 17, 74 + 15, BMP_l, color, BLACK);
        print_SZ(140 + 66 * 2 + 17 + 11, 74 + 18, 2, 1, 0, color); 
    }

    if (READY) color = GREEN;
    else color = GRAY;
    if (color_old[17] != color) {
        color_old[17] = color;
        LCD_DrawImage1BPP(138 + 66 * 3 - 1, 74 + 12, Bmp_READY, color, BLACK); //ready
    }

    if (!fKL4) color = RED;
    else color = GRAY;
    if (color_old[18] != color) {
        color_old[18] = color;
        //LCD_DrawImage1BPP(138 + 66 * 4, 74, Bmp_baojing[12], color, BLACK); //中门1应急阀
        LCD_DrawImage1BPP(140 + 66 * 4, 74, Bmp_baojing[15], color, BLACK); //右前刹车片
        LCD_DrawImage1BPP(140 + 66 * 4 + 17, 74 + 15, BMP_r, color, BLACK);
        print_SZ(140 + 66 * 4 + 17 + 11, 74 + 18, 1, 1, 0, color); 
    }

    if (!rKL4) color = RED;
    else color = GRAY;
    if (color_old[19] != color) {
        color_old[19] = color;
        //LCD_DrawImage1BPP(138 + 66 * 5, 74, Bmp_baojing[13], color, BLACK); //中门2应急阀
        LCD_DrawImage1BPP(140 + 66 * 5, 74, Bmp_baojing[15], color, BLACK); //右后刹车片
        LCD_DrawImage1BPP(140 + 66 * 5 + 17, 74 + 15, BMP_r, color, BLACK);
        print_SZ(140 + 66 * 5 + 17 + 11, 74 + 18, 2, 1, 0, color);
    }

    if (0) color = RED;
    else color = GRAY;
    if (color_old[20] != color) {
        color_old[20] = color;
        //LCD_DrawImage1BPP(138 + 66 * 6, 74, Bmp_baojing[20], color, BLACK); 
    }
}

void disp_CAN_baojing(unsigned int x, unsigned int y) {
    static unsigned char al_index = 0;
    if (alarm_update_flag == 0) { //3S 更新一次 
        //LCD_DrawRect(x, y, 350 + 85 + 10, 36, BLACK); //清除显示区域
        switch (al_index) {
            case 0:
                al_index = 1;
                if (BMS_OFFLINE) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_b, YELLOW, BLACK); //BMS离线
                    LCD_DrawImage1BPP(x + 11, y + 8, BMP_m, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11, y + 8, BMP_s, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11 + 11, y + 8, BMP_Lixian, YELLOW, BLACK);
                    LCD_DrawRect(x + 11 + 11 + 11 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 1:
                al_index = 2;
                if (TM_OFFLINE) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DJ, YELLOW, BLACK); //电机系统离线
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_System, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Lixian, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
            case 2:
                al_index = 3;
                if (VCU_FAULT) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Zhengche, YELLOW, BLACK); //整车系统故障
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_System, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 3:
                al_index = 4;
                if (BMS_Comm_Fault > 0) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_b, YELLOW, BLACK); //BMS通信故障
                    LCD_DrawImage1BPP(x + 11, y + 8, BMP_m, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11, y + 8, BMP_s, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11 + 11, y + 8, BMP_Tongxin, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11 + 11 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 11 + 11 + 11 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 4:
                al_index = 5;
                if (BMS_Status == 1) {
                    LCD_DrawImageSBPP(x, y + 8,11, BMS, YELLOW, BLACK); //BMS系统故障
                    LCD_DrawImage1BPP(x + 11 + 11 + 11, y + 8, BMP_System, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11 + 11 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 11 + 11 + 11 + 42 + 42, y, 50, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 5:
                al_index = 6;
                if (DCDC_Fault_Warn) {
                    LCD_DrawImage1BPP(x, y + 6, BMP_DCDC, YELLOW, BLACK); //DCDC故障
                    LCD_DrawImage1BPP(x + 65, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 65 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
            case 6:
                al_index = 7;
                if (OILDCAC_Fault_Warn) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Youbeng, YELLOW, BLACK); //油泵系统故障
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_System, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 50, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
            case 7:
                al_index = 8;
                if (AIRDCAC_Fault_Warn) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Qibeng, YELLOW, BLACK); //气泵系统故障
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_System, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 50, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
            case 8:
                al_index = 9;
                if (pSpeed > 69) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Chaosu, YELLOW, BLACK); //超速报警
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
            case 9:
                al_index = 10;
                if (VCU_Code > 0) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Zhengche, YELLOW, BLACK); //整车x级故障
                    if (VCU_Code >= 150 && VCU_Code <= 200)
                        LCD_DrawImage1BPP(x + 42, y + 8, BMP_SZ_2[4], YELLOW, BLACK);
                    else if (VCU_Code >= 100 && VCU_Code < 150)
                        LCD_DrawImage1BPP(x + 42, y + 8, BMP_SZ_2[3], YELLOW, BLACK);
                    else if (VCU_Code >= 50 && VCU_Code < 100)
                        LCD_DrawImage1BPP(x + 42, y + 8, BMP_SZ_2[2], YELLOW, BLACK);
                    else if (VCU_Code > 0 && VCU_Code < 50)
                        LCD_DrawImage1BPP(x + 42, y + 8, BMP_SZ_2[1], YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 10, y + 8, BMP_Ji, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 10 + 21, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 10 + 21 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
            case 10:
                al_index = 11;
                if (TireFault[0][0].bit2 == 1 
                        || TireFault[0][0].bit3 == 1
                        || TireFault[0][0].bit4 == 1
                        || TireFault[0][1].bit2 == 1 
                        || TireFault[0][1].bit3 == 1
                        || TireFault[0][1].bit4 == 1 
                        || TireFault[1][0].bit2 == 1 
                        || TireFault[1][0].bit3 == 1
                        || TireFault[1][0].bit4 == 1
                        || TireFault[1][1].bit2 == 1 
                        || TireFault[1][1].bit3 == 1
                        || TireFault[1][1].bit4 == 1
                        || TireFault[1][2].bit2 == 1 
                        || TireFault[1][2].bit3 == 1
                        || TireFault[1][2].bit4 == 1
                        || TireFault[1][3].bit2 == 1 
                        || TireFault[1][3].bit3 == 1
                        || TireFault[1][3].bit4 == 1
                        || TirePressureThresholdDetection[0][0] == 3
                        || TirePressureThresholdDetection[0][0] == 4
                        || TirePressureThresholdDetection[0][1] == 3
                        || TirePressureThresholdDetection[0][1] == 4
                        || TirePressureThresholdDetection[1][0] == 3
                        || TirePressureThresholdDetection[1][0] == 4
                        || TirePressureThresholdDetection[1][1] == 3
                        || TirePressureThresholdDetection[1][1] == 4
                        || TirePressureThresholdDetection[1][2] == 3
                        || TirePressureThresholdDetection[1][2] == 4
                        || TirePressureThresholdDetection[1][3] == 3
                        || TirePressureThresholdDetection[1][3] == 4
                        ) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Luntai, YELLOW, BLACK); //轮胎故障
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
            case 11:
                al_index = 12;
                /*if (TM_Status_Flag1.bit2) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DJ, YELLOW, BLACK); //电机过温
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 21, y + 8, BMP_Wendu, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/

            case 12:
                al_index = 13;
                /*if (TM_Status_Flag1.bit1) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DJ, YELLOW, BLACK); //电机控制器过温
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_KZQ, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 63, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 63 + 21, y + 8, BMP_Wendu, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 63 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/

            case 13:
                al_index = 14;
                if (CHARGE_OVERTIME) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Yuchong, YELLOW, BLACK); //预充超时
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Chaoshi, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 14:
                al_index = 15;
                if (BAT24V_count == BAT24_TIME) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Xu, YELLOW, BLACK); //蓄电池电压低
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_DC, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 42, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 42 + 42, y + 8, BMP_Di, YELLOW, BLACK);
                    LCD_DrawRect(x + 21 + 42 + 42 + 21, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 15:
                al_index = 16;
                if (BAT_SOC_Fault > 0) {
                    LCD_DrawImage1BPP(x, y+8, BMP_s, YELLOW, BLACK); //SOC故障
                    LCD_DrawImage1BPP(x + 11, y+8, BMP_o, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11, y+8, BMP_c, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + +11 + 11 + 11, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 11 + 11 + 11 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 16:
                al_index = 17;
                if (BAT_Single_Fault > 0) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Dan, YELLOW, BLACK); //单体电压故障
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_Ti, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 21, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 17:
                al_index = 18;
                if (BAT_Voltage_Fault > 0) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Zong, YELLOW, BLACK); //总电压故障
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 21 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 18:
                al_index = 19;
                if (BAT_Temp_Fault > 0) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Wendu, YELLOW, BLACK); //温度故障
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 19:
                al_index = 20;
                if (BAT_SOC_Fault == 3) {
                    LCD_DrawImage1BPP(x, y+8, BMP_s, YELLOW, BLACK); //SOC过低
                    LCD_DrawImage1BPP(x + 11, y+8, BMP_o, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11, y+8, BMP_c, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + +11 + 11 + 11, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + +11 + 11 + 11 + 21, y + 8, BMP_Di, YELLOW, BLACK);
                    LCD_DrawRect(x + 11 + 11 + 11 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 20:
                al_index = 21;
                if (BAT_Insulation_Fault > 0) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Jueyuan, YELLOW, BLACK); //绝缘故障
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 21:
                al_index = 22;
                if (BAT_Current_Fault > 0) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DL, YELLOW, BLACK);//电流故障
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 22:
                al_index = 23;
                if (BAT_Consistency_Fault > 0) {                    
                    LCD_DrawImage1BPP(x, y + 8, BMP_DC, YELLOW, BLACK); //电池均衡故障
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Junheng, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 23:
                al_index = 24;
                if (BAT_Lock_Fault > 0) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Husuo, YELLOW, BLACK); //互锁报警
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 24:
                al_index = 25;
                /*if (((Status_Flag2 >> 1)&0x01) == 1) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_d, YELLOW, BLACK); //DCDC故障报警
                    LCD_DrawImage1BPP(x + 11, y + 8, BMP_c, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11, y + 8, BMP_d, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11 + 11, y + 8, BMP_c, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11 + 11 + 11, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11 + 11 + 11 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 44 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/

            case 25:
                al_index = 26;
                /*if ((Status_Flag2 & 0x01) == 1) {                    
                    LCD_DrawImage1BPP(x, y + 8, BMP_DC, YELLOW, BLACK); //电池热失控
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Re, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 21, y + 8, BMP_Shikong, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 21 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/

            case 26:
                al_index = 27;
                /*if (((Status_Flag3 >> 2)&0x01) == 1) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_You, YELLOW, BLACK); //有内阻偏大电池
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_Nei, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 21, y + 8, BMP_Zu, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 21 + 21, y + 8, BMP_Pian, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 21 + 21 + 21, y + 8, BMP_Da, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 21 + 21 + 21 + 21, y + 8, BMP_DC, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42 + 21, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/

            case 27:
                al_index = 28;
                /*if (((Status_Flag3 >> 3)&0x01) == 1) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_You, YELLOW, BLACK); //有电压偏小电池
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 21 + 21, y + 8, BMP_Pian, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 21 + 21 + 21, y + 8, BMP_Xiao, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 21 + 21 + 21 + 21, y + 8, BMP_DC, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42 + 21, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/

            case 28:
                al_index = 29;
                if (Fcan_count == CAN_TIME) {
                    LCD_DrawImageSBPP(x, y + 8, 42, QBMKLX, YELLOW, BLACK); //前部模块离线
                    LCD_DrawRect(x + 42 + 42 + 42, y, 42, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 29:
                al_index = 30;
                if (Mcan_count == CAN_TIME) {
                    LCD_DrawImageSBPP(x, y + 8, 42, DBMKLX, YELLOW, BLACK); //顶部模块离线
                    LCD_DrawRect(x + 42 + 42 + 42, y, 42, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 30:
                al_index = 31;
                if (Rcan_count == CAN_TIME) {
                    LCD_DrawImageSBPP(x, y + 8, 42, HBMKLX, YELLOW, BLACK); //后部模块离线
                    LCD_DrawRect(x + 42 + 42 + 42, y, 42, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
            default:
                al_index = 0;
                LCD_DrawRect(x, y, 200, 36, BLACK); //清除显示区域
                break;
        }
    }
}

/*void disp_SPN_FMI(unsigned int x, unsigned int y, unsigned char len, DM1 id) {
    static unsigned char al_index = 0;
    ////////3S 更新一次  
    if (alarm_update_flag == 0) { //3S 更新一次  
        switch (al_index) {
            case 0:
                al_index = 1;
                if (len >= 6) {
                    DM(1, id);
                    print_SZ_1(x, y, SPN, 6, 0, GREEN);
                    print_SZ_1(x + 132, y, FMI, 3, 0, GREEN);
                    alarm_update_flag = 1;
                    break;
                }

            case 1:
                al_index = 2;
                if (len >= 10) {
                    DM(2, id);
                    print_SZ_1(x, y, SPN, 6, 0, GREEN);
                    print_SZ_1(x + 132, y, FMI, 3, 0, GREEN);
                    alarm_update_flag = 1;
                    break;
                }

            case 2:
                al_index = 3;
                if (len >= 14) {
                    DM(3, id);
                    print_SZ_1(x, y, SPN, 6, 0, GREEN);
                    print_SZ_1(x + 132, y, FMI, 3, 0, GREEN);
                    alarm_update_flag = 1;
                    break;
                }

            case 3:
                al_index = 4;
                if (len >= 18) {
                    DM(4, id);
                    print_SZ_1(x, y, SPN, 6, 0, GREEN);
                    print_SZ_1(x + 132, y, FMI, 3, 0, GREEN);
                    alarm_update_flag = 1;
                    break;
                }

            case 4:
                al_index = 5;
                if (len >= 22) {
                    DM(5, id);
                    print_SZ_1(x, y, SPN, 6, 0, GREEN);
                    print_SZ_1(x + 132, y, FMI, 3, 0, GREEN);
                    alarm_update_flag = 1;
                    break;
                }

            case 5:
                al_index = 6;
                if (len >= 26) {
                    DM(6, id);
                    print_SZ_1(x, y, SPN, 6, 0, GREEN);
                    print_SZ_1(x + 132, y, FMI, 3, 0, GREEN);
                    alarm_update_flag = 1;
                    break;
                }

            case 6:
                al_index = 7;
                if (len >= 30) {
                    DM(7, id);
                    print_SZ_1(x, y, SPN, 6, 0, GREEN);
                    print_SZ_1(x + 132, y, FMI, 3, 0, GREEN);
                    alarm_update_flag = 1;
                    break;
                }

            case 7:
                al_index = 8;
                if (len >= 34) {
                    DM(8, id);
                    print_SZ_1(x, y, SPN, 6, 0, GREEN);
                    print_SZ_1(x + 132, y, FMI, 3, 0, GREEN);
                    alarm_update_flag = 1;
                    break;
                }

            default:
                al_index = 0;
                break;
        }
    }
}
 */

void updata_Dangwei(unsigned int x, unsigned int y) {
    unsigned char gear = 1;
    gear = VCU_Gear;
    if (gear == 13) gear = 2;
    else if (gear == 14) gear = 1;
    else if (gear == 15) gear = 3;
    else gear = 0;
    LCD_DrawImage1BPP(x, y, BMP_DANGWEI[gear], GREEN, BLACK); //档位更新   
}

void updata_SOC(void) {
    unsigned char color = WHITE;
    unsigned char soc = 100;
    soc = BMS_SOC;
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
    DCDY = BMS_Voltage * 0.1;
    if (DCDY > 800)
        DCDY = 800;
    print_SZ_1(x, y, DCDY, 3, 0, WHITE); //电池电压数值 x=120+72+30   y=150+60-2
    if (frmID == 0)
        LCD_DrawRect(225 + 2, 150 + 5 + 2, DCDY * 3.31 * 0.125, 28, GREEN); // 331/100  
    if (frmID == 0)//当为100时会出错
        LCD_DrawRect(225 + 2 + DCDY * 3.31 * 0.125, 150 + 5 + 2, 331 - DCDY * 3.31 * 0.125, 28, BLACK);
}

void updata_DCDL(unsigned int x, unsigned int y) {
    unsigned int DCDL = 100;
    DCDL = BMS_Current * 0.05;
    if (DCDL < 1600) {
        DCDL = 1600 - DCDL;
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
        DCDL = DCDL - 1600;
        if (DCDL > 500) DCDL = 500;
        LCD_DrawImage1BPPZOOM_4(x - 20, y + 4, BMP_ZHENG, BLACK, BLACK);
        print_SZ_1(x, y, DCDL, 3, 0, WHITE);
        if (DCDL > 3 && frmID == 0)
            LCD_DrawRect(225 + 83 + 83 + 2, 150 + 5 + 2 + 60, (DCDL * 1.65 * 0.2), 28, GREEN); // 如果长度为0，会出错
        if (DCDL < 500 && frmID == 0) {
            LCD_DrawRect((225 + 83 + 83 + 2 + DCDL * 1.65 * 0.2), 150 + 5 + 2 + 60, (165 - DCDL * 1.65 * 0.2), 28, BLACK);
            LCD_DrawRect(225 + 2, 150 + 5 + 2 + 60, 164, 28, BLACK);
        }
    }
}

void updata_DAT(unsigned int x, unsigned int y, //带符号数值
        unsigned long dat, //显示的数据 
        float factor, //比例
        unsigned int offset,
        unsigned char color1, //颜色
        unsigned char sum, //显示数据的几位
        unsigned char dot //显示小数点的位数       
        ) {//偏移量
    //unsigned char color = WHITE;
    unsigned int DAT = 100;
    DAT = dat * factor;
    if (DAT < offset) {
        print_SZ_1(x, y, offset - DAT, sum, dot, color1);
        LCD_DrawImage1BPPZOOM_4(x - 25, y + 5, BMP_FU, color1, BLACK);
    } else {
        LCD_DrawImage1BPPZOOM_4(x - 25, y + 5, BMP_ZHENG, BLACK, BLACK);
        print_SZ_1(x, y, DAT - offset, sum, dot, color1); //电池电流数值 x=135+180+50+100+20+20   y=150+60-2
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
    LCD_DrawRect(0, 64 + 64, 800, 1, GRAY);
    for (i = 1; i < 12; i++) {
        LCD_DrawRect(4 + 66 * i, 0, 1, 64, GRAY);
    }
    //新增加的符号片框架2016/11/1
    LCD_DrawRect(136, 128, 528, 1, GRAY);
    for (i = 1; i < 12; i++) {
        LCD_DrawRect(4 + 66 * i, 64, 1, 64, GRAY);
    }
    //每次进入主界面，符号片颜色都是灰色，若不处理，只会第一次上电显示灰色，翻页后就不显示灰色
    for (i = 0; i < 24; i++) {
        color_old[i] = 0;
    }
    LCD_DrawRect(0, 430, 800, 1, GREEN); //底部横线

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

    LCD_DrawImageSBPP(60, 365 - 50 + 10, 21, DTDY, WHITE, BLACK); //单体电压
    LCD_DrawImage1BPP(15 + 130, 318 + 38 + 8, BMP_v, WHITE, BLACK); //V
    LCD_DrawImage1BPP(15 + 130, 318 + 38 * 2 + 8, BMP_v, WHITE, BLACK); //V

    LCD_DrawImageSBPP(70 + 550, 365 - 50 + 10, 21, DTWD, WHITE, BLACK); //单体温度
    LCD_DrawImage1BPP(800 - 90, 318 + 10 + 38, BMP_T, WHITE, BLACK); //℃
    LCD_DrawImage1BPP(800 - 90, 318 + 10 + 38 * 2, BMP_T, WHITE, BLACK); //℃

    LCD_DrawImageSBPP(180 - 20 + 2, 365 - 50 + 10, 42, DJKZQ, WHITE, BLACK); //电机控制器
    LCD_DrawImage1BPP(225 + 83 + 83 - 22, 365 - 50 + 10, BMP_T, WHITE, BLACK); //℃

    LCD_DrawImageSBPP(225 + 83 + 83 + 2, 365 - 50 + 10, 42, DJZS, WHITE, BLACK); //电机转速
    LCD_DrawImage1BPP(615 - 34, 365 - 50 + 10, BMP_RPM, WHITE, BLACK); //RPM

    LCD_DrawImageSBPP(225 + 83 + 83 + 2, 365 - 50 + 10 + 38, 42, DJZJ, WHITE, BLACK); //电机转矩
    LCD_DrawImage1BPP(615 - 22, 365 - 50 + 10 + 38, BMP_n, WHITE, BLACK); //NM
    LCD_DrawImage1BPP(615 - 22 + 11, 365 - 50 + 10 + 38, BMP_m, WHITE, BLACK); //


    LCD_DrawImageSBPP(180 - 20 + 2, 365 - 50 + 10 + 38, 42, DJWD, WHITE, BLACK); //电机温度
    LCD_DrawImage1BPP(225 + 83 + 83 - 22, 365 - 50 + 10 + 38, BMP_T, WHITE, BLACK); //℃


    /*LCD_DrawImage1BPP(225 + 83 + 83 + 2, 365 - 50 + 10 + 38, BMP_System, WHITE, BLACK); //系统
    LCD_DrawImage1BPP(225 + 83 + 83 + 2 + 43, 365 - 50 + 10 + 38, BMP_Code, WHITE, BLACK); //代码
    
    LCD_DrawImage1BPP(225 + 83 + 83 + 2, 365 - 50 + 10 + 38*2, BMP_s, WHITE, BLACK); //S
    LCD_DrawImage1BPP(225 + 83 + 83 + 2+ 11 , 365 - 50 + 10 + 38*2, BMP_p, WHITE, BLACK); //P
    LCD_DrawImage1BPP(225 + 83 + 83 + 2+ 11 + 11 , 365 - 50 + 10 + 38*2, BMP_n, WHITE, BLACK); //N
     */
    //LCD_DrawImage1BPP(225 + 83 + 83 + 2+ 11 + 11 + 11 + 2, 365 - 50 + 10 + 38*2, BMP_Maohao, WHITE, BLACK); //:

    //框框
    LCD_DrawRect(55, 365 - 50, 680, 1, GREEN);
    LCD_DrawRect(55, 365 - 50, 1, 65 + 50, GREEN);
    LCD_DrawRect(735, 365 - 50, 1, 65 + 50, GREEN);
    LCD_DrawRect(180 - 20, 365 - 50, 350 + 85 + 20, 1, GREEN);
    LCD_DrawRect(180 - 20, 365 - 50, 1, 65 + 50, GREEN);
    LCD_DrawRect(225 + 83 + 83, 365 - 50, 1, 65 + 50 - 38, GREEN);
    LCD_DrawRect(615, 365 - 50, 1, 65 + 50, GREEN);
    LCD_DrawRect(180 - 20, 365 - 50 + 38, 350 + 85 + 20, 1, GREEN);
    LCD_DrawRect(180 - 20, 365 - 50 + 38 + 38, 350 + 85 + 20, 1, GREEN);

    //LCD_DrawImage1BPPZOOM_4(100, 150 + 70 + 60 + 45 + 50, BMP_DW, WHITE, BLACK); //档位
    /*
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
     */
    //LCD_DrawImage1BPP(712 - 7 + 32, 410, Bmp_Mpa, WHITE, BLACK); //Mpa

    /*--------------------------------------------
    以下显示的格式为:(ODO 000.0Km       00:00          TRIP0000000Km)
    ---------------------------------------------*/
    LCD_DrawImage1BPP(2, 440 + 3, Bmp_ODO, YELLOW, BLACK); //累计里程 ODO  
    //print_SZ_4(2+64+4,440,9999999,7,1,WHITE);

    //LCD_DrawImage1BPPZOOM_4(16 * 6, 318 + 38+2, BMP_HZ_KM, WHITE, BLACK); //单位 Km
    LCD_DrawImage1BPP(210 - 16, 440 + 3, BMP_HZ_KM, WHITE, BLACK); //单位 Km

    LCD_DrawImage1BPP(240 + 300 + 30, 440 + 3, Bmp_TRIP, YELLOW, BLACK); //单次里程 TRIF
    //print_SZ_4(240+80+4,440,9999,4,1,WHITE);
    //LCD_DrawImage1BPPZOOM_4(16 * 6, 318 + 38 * 2+2, BMP_HZ_KM, WHITE, BLACK); //单位 Km
    LCD_DrawImage1BPP(404 + 336 + 30, 440 + 3, BMP_HZ_KM, WHITE, BLACK); //单位 Km

}

void frmMain(void) {
    if (f_index == 0) { //只更新一次
        f_index = 1;
        mainFrame();
    } else if (f_index == 1) {
        f_index = 2;
        print_SZ_1(60, 318 + 38, BAT_Single_H, 4, 3, WHITE); //单体高
        print_SZ_1(60, 318 + 38 * 2, BAT_Single_L, 4, 3, WHITE); //单体低
        updata_DAT(313, 318 + 38, TM_Temp, 1, 40, WHITE, 3, 0); //电机温度
    } else if (f_index == 2) {
        f_index = 3;
        disp_baojing();
        updata_DAT(480 + 30, 318, TM_Feedback_RPM, 1, 20000, WHITE, 4, 0); //电机转速
        updata_DAT(480 + 30, 318 + 38, TM_Feedback_NM, 0.1, 2000, WHITE, 4, 0);
    } else if (f_index == 3) {
        f_index = 4;
        disp_miles();
        updata_DCDL(585, 155 + 60);
    } else if (f_index == 4) {
        f_index = 5;
        disp_time(330, 440, timer);
        updata_DAT(313, 318, TM_Control_Temp, 1, 40, WHITE, 3, 0); //电机控制器温度
    } else if (f_index == 5) {
        f_index = 6;
        updata_SOC();
        updata_DAT(800 - 150, 318 + 38, BAT_Temp_H, 1, 40, WHITE, 3, 0); //单体高温
        updata_DAT(800 - 150, 318 + 38 * 2, BAT_Temp_L, 1, 40, WHITE, 3, 0); //单体低温
    } else if (f_index == 6) {
        f_index = 7;
        updata_DCDY(585, 155);
        disp_CAN_baojing(162, 394);
    } else if (f_index == 7) {
        f_index = 1;
        updata_Dangwei(138 + 15 + 66 * 6, 74);
        /*print_H(480 + 30 -16, 318 + 38*2, tcu_spn, 5, 0, WHITE); //spn
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
        f_index = 0;*/
    }

    if (AV_CH == 0) { //当在数字界面
        if (key_up) { //调节背光灯
            key_up = 0;
            if ((IN6 == 1) && (!time_flag)) {//背光开启
                if (e_backlight >= 1000) e_backlight = 100;
                else e_backlight += 100;
                EEROM_WriteBackLight();
            }
            if (time_flag) {
                t++; //时钟设置
                if (t == 4) t = 0;
            }
        }

        if (key_set) {
            key_set = 0;
            key_long_set = 0;
            key_up = 0;
            key_AV = 0;
            key_duble = 0;
            if (time_flag == 0) {
                f_index = 0; //更新只更新一次的界面
                frmID = 1;
            }
            time_flag = 0;
        }

        if (key_long_set) {
            key_long_set = 0;
            key_set = 0;
            key_up = 0;
            key_AV = 0;
            time_flag = 1;
        }

        if (key_AV) {
            key_AV = 0;
            key_long_set = 0;
            key_up = 0;
            key_set = 0;
            if (time_flag)
                t_add = 1;
            else t_add = 0;
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
            if (time_flag)
                t_add = 1;
            else t_add = 0;
            unsigned char mode = 2; //2,MCU

            if (AV_CH < 4 && !time_flag) AV_CH++;
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
}

/******************************************************/
void MenuFrame(void) {
    LCD_Clear();
    unsigned char color = WHITE;
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //顶部横线   

    LCD_DrawRect(0, 430, 800, 2, YELLOW); //底部横线
    LCD_DrawImageSBPP(130, 130, 50, MOTO_SYSTEM, color, BLACK); //电机系统信息

    LCD_DrawImageSBPP(130, 130 + 35, 50, AIR_SYSTEM, color, BLACK); //气泵系统信息

    LCD_DrawImage1BPP(130, 130 + 35 + 35, BMP_DCDC, color, BLACK); //DCDC
    LCD_DrawImage1BPP(130 + 65, 130 + 35 + 35, BMP_STSTEM, color, BLACK); //系统
    LCD_DrawImage1BPP(130 + 65 + 50, 130 + 35 + 35, BMP_Message, color, BLACK); //信息

    LCD_DrawImageSBPP(130, 130 + 35 + 35 + 35, 50, OIL_SYSTEM, color, BLACK); //油泵系统信息

    LCD_DrawImageSBPP(130, 130 + 35 + 35 + 35 + 35, 50, Luntai_SYSTEM, color, BLACK); //胎压系统信息

    LCD_DrawImageSBPP(130 + 350, 130, 50, BMS_SYSTEM, color, BLACK); //电池管理系统信息

    LCD_DrawImageSBPP(130 + 350, 130 + 35, 50, Battery_SYSTEM, color, BLACK); //电池信息   

    LCD_DrawImageSBPP(130 + 350, 130 + 35 + 35, 50, HV_SYSTEM, color, BLACK); //高压系统信息  

    LCD_DrawImageSBPP(130 + 350, 130 + 35 + 35 + 35, 50, IC_SYSTEM, color, BLACK); //仪表系统信息

}

void MenuUpdate(void) {
    static unsigned char i = 0;
    unsigned char color = BLACK;
    if (key_up) {//箭头向下走
        key_up = 0;
        if (time_flag) {
            t++; //时钟设置
            if (t == 10) t = 0;
        }
        if (!time_flag) {
            i++;
        }
    }

    if (key_AV) {//箭头向上走
        key_AV = 0;
        if (time_flag)
            t_add = 1;
        if (!time_flag)
            i--;
    }

    if (i == 18) i = 9;
    if (i == 0) i = 9;
    //子菜单间切换
    if (i == 9) {
        color = GREEN;
        if (key_set) {
            key_set = 0;
            if (time_flag == 0) {
                f_index = 0;
                frmID = 2;
            }
            time_flag = 0;
        }
    } else
        color = BLACK;
    LCD_DrawImage1BPP(105, 131, BMP_Choose, color, BLACK);
    if (i == 10 || i == 1) {
        color = GREEN;
        if (key_set) {
            key_set = 0;
            if (time_flag == 0) {
                f_index = 0;
                frmID = 3;
            }
            time_flag = 0;
        }
    } else
        color = BLACK;
    LCD_DrawImage1BPP(105, 131 + 35, BMP_Choose, color, BLACK);
    if (i == 11 || i == 2) {
        color = GREEN;
        if (key_set) {
            key_set = 0;
            if (time_flag == 0) {
                f_index = 0;
                frmID = 4;
            }
            time_flag = 0;
        }
    } else
        color = BLACK;
    LCD_DrawImage1BPP(105, 131 + 2 * 35, BMP_Choose, color, BLACK);
    if (i == 12 || i == 3) {
        color = GREEN;
        if (key_set) {
            key_set = 0;
            if (time_flag == 0) {
                f_index = 0;
                frmID = 5;
            }
            time_flag = 0;
        }
    } else
        color = BLACK;
    LCD_DrawImage1BPP(105, 131 + 3 * 35, BMP_Choose, color, BLACK);
    if (i == 13 || i == 4) {
        color = GREEN;
        if (key_set) {
            key_set = 0;
            if (time_flag == 0) {
                f_index = 0;
                frmID = 11;
            }
            time_flag = 0;
        }
    } else
        color = BLACK;
    LCD_DrawImage1BPP(105, 131 + 4 * 35, BMP_Choose, color, BLACK);
    if (i == 14 || i == 5) {
        color = GREEN;
        if (key_set) {
            key_set = 0;
            if (time_flag == 0) {
                f_index = 0;
                frmID = 6;
            }
            time_flag = 0;
        }
    } else
        color = BLACK;
    LCD_DrawImage1BPP(105 + 350, 131, BMP_Choose, color, BLACK);
    if (i == 15 || i == 6) {
        color = GREEN;
        if (key_set) {
            key_set = 0;
            if (time_flag == 0) {
                f_index = 0;
                frmID = 7;
            }
            time_flag = 0;
        }
    } else
        color = BLACK;
    LCD_DrawImage1BPP(105 + 350, 131 + 1 * 35, BMP_Choose, color, BLACK);
    if (i == 16 || i == 7) {
        color = GREEN;
        if (key_set) {
            key_set = 0;
            if (time_flag == 0) {
                f_index = 0;
                frmID = 8;
            }
            time_flag = 0;
        }
    } else
        color = BLACK;
    LCD_DrawImage1BPP(105 + 350, 131 + 2 * 35, BMP_Choose, color, BLACK);
    if (i == 17 || i == 8) {
        color = GREEN;
        if (key_set) {
            key_set = 0;
            if (time_flag == 0) {
                f_index = 0;
                frmID = 9;
            }
            time_flag = 0;
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
        disp_CAN_baojing(2, 440);
        disp_time(330, 440, timer);
    } else {
        f_index = 0;
    }
    if (key_long_set) {
        key_long_set = 0;
        key_set = 0;
        key_up = 0;
        key_AV = 0;
        time_flag = 1;
    }

    if (key_duble) {
        key_duble = 0;
        if (time_flag == 0) {
            f_index = 0;
            frmID = 10;
        }
    }
}

/******************************************************/
void ICFrame(unsigned char index) { //仪表框架
    unsigned char i;
    LCD_Clear();
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //顶部横线
    if (index == 1) {
        LCD_DrawImageSBPP(130 + 200, 130 - 85, 50, IC_SYSTEM, WHITE, BLACK); //仪表

        LCD_DrawImageSBPP(130 + 200 + 200, 130 - 85 + 4, 11, CHAR_CAN, WHITE, BLACK);
        LCD_DrawImage1BPP(130 + 200 + 200 + 11 + 11 + 11, 130 - 85 + 4, BMP_Tongxin, WHITE, BLACK);

        print_SZ_2(750, 50, 1, 1, 0, WHITE); // 1/4
        LCD_DrawImage1BPP(750 + 11, 50, BMP_I, WHITE, BLACK);
        print_SZ_2(750 + 11 + 14, 50, 4, 1, 0, WHITE);

        /***********************仪表开关量采集**********************************/
        //左转向
        LCD_DrawImage1BPP(35, 75, BMP_IC_Zuo, WHITE, BLACK);
        LCD_DrawImage1BPP(35 + 21, 75, BMP_IC_Zhuanxiang, WHITE, BLACK);
        //充电信号
        /*LCD_DrawImage1BPP(35, 75 + 25 * 3, BMP_Chong, WHITE, BLACK);
        LCD_DrawImage1BPP(35 + 21, 75 + 25 * 3, BMP_DC, WHITE, BLACK);
        LCD_DrawImage1BPP(35 + 42, 75 + 25 * 3, BMP_IC_Xinhao, WHITE, BLACK);*/
        //右转向
        LCD_DrawImage1BPP(35, 75 + 25 * 4, BMP_IC_You, WHITE, BLACK);
        LCD_DrawImage1BPP(35 + 21, 75 + 25 * 4, BMP_IC_Zhuanxiang, WHITE, BLACK);
        //小灯
        LCD_DrawImage1BPP(35, 75 + 25 * 5, BMP_Xiao, WHITE, BLACK);
        //远光灯
        LCD_DrawImage1BPP(35, 75 + 25 * 6, BMP_IC_Yuan, WHITE, BLACK);
        LCD_DrawImage1BPP(35 + 21, 75 + 25 * 6, BMP_IC_Guang, WHITE, BLACK);
        //近光灯
        LCD_DrawImage1BPP(35, 75 + 25 * 7, BMP_IC_Jin, WHITE, BLACK);
        LCD_DrawImage1BPP(35 + 21, 75 + 25 * 7, BMP_IC_Guang, WHITE, BLACK);
        //前雾灯
        LCD_DrawImage1BPP(35, 75 + 25 * 8, BMP_IC_Qian, WHITE, BLACK);
        LCD_DrawImage1BPP(35 + 21, 75 + 25 * 8, BMP_IC_Wu, WHITE, BLACK);
        //后雾灯
        LCD_DrawImage1BPP(35, 75 + 25 * 9, BMP_IC_Hou, WHITE, BLACK);
        LCD_DrawImage1BPP(35 + 21, 75 + 25 * 9, BMP_IC_Wu, WHITE, BLACK);
        //司机灯
        LCD_DrawImage1BPP(35, 75 + 25 * 10, BMP_IC_Siji, WHITE, BLACK);
        //长条灯1
        LCD_DrawImage1BPP(35, 75 + 25 * 11, BMP_IC_Changtiao, WHITE, BLACK);
        print_SZ_2(35 + 105 + 6, 75 + 25 * 11, 1, 1, 0, WHITE);
        //长条灯2
        LCD_DrawImage1BPP(35, 75 + 25 * 12, BMP_IC_Changtiao, WHITE, BLACK);
        print_SZ_2(35 + 105 + 6, 75 + 25 * 12, 2, 1, 0, WHITE);
        //雨刮低档       
        for (i = 13; i < 16; i++) {
            LCD_DrawImage1BPP(35, 75 + 25 * i, BMP_IC_Yugua, WHITE, BLACK);
        }
        LCD_DrawImage1BPP(35 + 42, 75 + 25 * 13, BMP_Di, WHITE, BLACK);
        LCD_DrawImage1BPP(35 + 63, 75 + 25 * 13, BMP_Dang, WHITE, BLACK);
        //雨刮间歇档
        LCD_DrawImage1BPP(35 + 42, 75 + 25 * 14, BMP_Jianxie, WHITE, BLACK);
        LCD_DrawImage1BPP(35 + 84, 75 + 25 * 14, BMP_Dang, WHITE, BLACK);
        //雨刮高档
        LCD_DrawImage1BPP(35 + 42, 75 + 25 * 15, BMP_Gao, WHITE, BLACK);
        LCD_DrawImage1BPP(35 + 63, 75 + 25 * 15, BMP_Dang, WHITE, BLACK);


        //灯
        for (i = 0; i < 16; i++) {
            if (i == 0 || i == 4 || i == 6 || i == 7 || i == 8 || i == 9 || i == 10 || i == 11 || i == 12) {
                if (i != 0 && i != 4)
                    LCD_DrawImage1BPP(35 + 42, 75 + 25 * i, BMP_IC_Deng, WHITE, BLACK);
                LCD_DrawImage1BPP(35 + 63, 75 + 25 * i, BMP_IC_Kaiguan, WHITE, BLACK);
            } else if (i == 5) {
                LCD_DrawImage1BPP(35 + 21, 75 + 25 * i, BMP_IC_Deng, WHITE, BLACK);
                LCD_DrawImage1BPP(35 + 42, 75 + 25 * i, BMP_IC_Kaiguan, WHITE, BLACK);
            } else if (i == 13 || i == 15)
                LCD_DrawImage1BPP(35 + 84, 75 + 25 * i, BMP_IC_Kaiguan, WHITE, BLACK);
            else if (i == 14)
                LCD_DrawImage1BPP(35 + 105, 75 + 25 * i, BMP_IC_Kaiguan, WHITE, BLACK);
        }

        //ABS状态
        LCD_DrawImageSBPP(285, 75 + 25 * 1, 11, ABS, WHITE, BLACK);
        //路牌
        LCD_DrawImage1BPP(285, 75 + 25 * 2, BMP_Lupai, WHITE, BLACK);
        //前门开
        LCD_DrawImageSBPP(285, 75 + 25 * 3, 21, QMKKG, WHITE, BLACK);
        //雨刮喷水
        LCD_DrawImage1BPP(285, 75 + 25 * 4, BMP_IC_Yugua, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 42, 75 + 25 * 4, BMP_Penshui, WHITE, BLACK);
        //电喇叭
        LCD_DrawImage1BPP(285, 75 + 25 * 5, BMP_DC, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 21, 75 + 25 * 5, BMP_Laba, WHITE, BLACK);
        //空调
        LCD_DrawImage1BPP(285, 75 + 25 * 6, BMP_Kongtiao, WHITE, BLACK);
        //中门关
        LCD_DrawImageSBPP(285, 75 + 25 * 9, 21, ZMGKG, WHITE, BLACK);
        //中门开
        LCD_DrawImageSBPP(285, 75 + 25 * 10, 21, ZMKKG, WHITE, BLACK);
        //前门关
        LCD_DrawImageSBPP(285, 75 + 25 * 11, 21, QMGKG, WHITE, BLACK);

        //开关
        for (i = 0; i < 16; i++) {
            if (i == 3 || i == 5 || i == 9 || i == 10 || i == 11) {
                LCD_DrawImage1BPP(285 + 63, 75 + 25 * i, BMP_IC_Kaiguan, WHITE, BLACK);
            } else if (i == 2 || i == 6) {
                LCD_DrawImage1BPP(285 + 42, 75 + 25 * i, BMP_IC_Kaiguan, WHITE, BLACK);
            } else if (i == 4)
                LCD_DrawImage1BPP(285 + 84, 75 + 25 * i, BMP_IC_Kaiguan, WHITE, BLACK);
        }

        //危险报警开关
        LCD_DrawImageSBPP(535, 75 + 25 * 5, 42, WXBJKG, WHITE, BLACK);
        //电源唤醒
        LCD_DrawImage1BPP(535, 75 + 25 * 6, BMP_Dianyuan, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 42, 75 + 25 * 6, BMP_Huanxing, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 84, 75 + 25 * 6, BMP_IC_Kaiguan, WHITE, BLACK);
        //钥匙ON开关
        LCD_DrawImage1BPP(535, 75 + 25 * 7, BMP_o, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 11, 75 + 25 * 7, BMP_n, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 11 + 11, 75 + 25 * 7, BMP_Dang, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 11 + 11 + 21, 75 + 25 * 7, BMP_IC_Kaiguan, WHITE, BLACK);

        LCD_DrawImage1BPP(535, 75 + 25 * 10, BMP_IC_Qian, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 21, 75 + 25 * 10, BMP_Qiya, WHITE, BLACK);

        LCD_DrawImage1BPP(535, 75 + 25 * 11, BMP_IC_Hou, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 21, 75 + 25 * 11, BMP_Qiya, WHITE, BLACK);

        for (i = 8; i < 14; i++) {
            if (i != 10 && i != 11)
                LCD_DrawImage1BPP(535 + 21, 75 + 25 * i, BMP_Beiyong, WHITE, BLACK);
            LCD_DrawImage1BPP(535 + 63, 75 + 25 * i, BMP_Xinhao, WHITE, BLACK);
            LCD_DrawImage1BPP(535 + 63 + 42 + 16 * 4 - 4, 75 + 25 * i, BMP_Omu, WHITE, BLACK); //Ω
            LCD_DrawImage1BPP(535 + 63 + 42 + 16 * 4 + 16 * 5, 75 + 25 * i, BMP_v, WHITE, BLACK); //V
        }

        LCD_DrawImage1BPP(505 + 100, 75 + 8 + 25 * 15, BMP_Banben, WHITE, BLACK);
        LCD_DrawImage1BPP(505 + 100 + 42, 75 + 8 + 25 * 15, BMP_Hao, WHITE, BLACK);
        LCD_DrawImage1BPP(505 + 200, 75 + 25 * 15, BMP_V, WHITE, BLACK);
    } else if (index == 2) {
        print_SZ_2(750, 50, 2, 1, 0, WHITE); // 2/4
        LCD_DrawImage1BPP(750 + 11, 50, BMP_I, WHITE, BLACK);
        print_SZ_2(750 + 11 + 14, 50, 4, 1, 0, WHITE);

        LCD_DrawImageSBPP(130 + 200 + 200, 130 - 85 + 4, 11, CHAR_CAN, WHITE, BLACK);
        LCD_DrawImage1BPP(130 + 200 + 200 + 11 + 11 + 11, 130 - 85 + 4, BMP_Tongxin, WHITE, BLACK);

        LCD_DrawImage1BPP(130 + 200, 130 - 85, BMP_QIAN, WHITE, BLACK); //前
        LCD_DrawImage1BPP(130 + 200 + 25, 130 - 85, BMP_MOKUAI, WHITE, BLACK); //模块
        LCD_DrawImage1BPP(130 + 200 + 25 + 50, 130 - 85, BMP_Message, WHITE, BLACK); //信息
        for (i = 0; i < 15; i++) {
            LCD_DrawImage1BPP(60 + 280, 75 + 3 + 25 * i, BMP_a, WHITE, BLACK);
            //LCD_DrawRect(0, 74 +25+ 25 * i, 800, 1, GRAY); //横线
        }
        /*************************前模块输出***********************************/
        for (i = 0; i < 3; i++) {
            LCD_DrawImage1BPP(60, 75 + 25 * i, BMP_IC_Yugua, WHITE, BLACK);
        }
        //高档
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 0, BMP_Gao, WHITE, BLACK);
        //低档
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 1, BMP_Di, WHITE, BLACK);
        //喷水
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 2, BMP_Penshui, WHITE, BLACK);
        for (i = 0; i < 3; i++) {
            if (i != 2) LCD_DrawImage1BPP(60 + 63, 75 + 25 * i, BMP_Dang, WHITE, BLACK);
            LCD_DrawImage1BPP(60 + 84, 75 + 25 * i, BMP_DJ, WHITE, BLACK);
        }
        //左前雾灯
        LCD_DrawImageSBPP(60, 75 + 25 * 3, 21, ZQWDSC, WHITE, BLACK);
        //空调电源
        LCD_DrawImage1BPP(60, 75 + 25 * 4, BMP_Kongtiao, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 4, BMP_Dianyuan, WHITE, BLACK);
        //右转向灯
        LCD_DrawImage1BPP(60, 75 + 25 * 5, BMP_IC_You, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 5, BMP_IC_Zhuanxiang, WHITE, BLACK);
        //左转向灯
        LCD_DrawImage1BPP(60, 75 + 25 * 6, BMP_IC_Zuo, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 6, BMP_IC_Zhuanxiang, WHITE, BLACK);
        //中门开输出
        //LCD_DrawImageSBPP(60, 75 + 25 * 7, 21, ZMKSC, WHITE, BLACK);
        //左远光灯
        LCD_DrawImageSBPP(60, 75 + 25 * 8, 21, ZYGDSC, WHITE, BLACK);
        //右前雾灯
        LCD_DrawImageSBPP(60, 75 + 25 * 9, 21, YQWDSC, WHITE, BLACK);
        //右远光灯
        LCD_DrawImageSBPP(60, 75 + 25 * 10, 21, YYGDSC, WHITE, BLACK);
        //POUT12
        //左近光灯
        LCD_DrawImageSBPP(60, 75 + 25 * 12, 21, ZJGDSC, WHITE, BLACK);
        //位置灯
        LCD_DrawImage1BPP(60, 75 + 25 * 13, BMP_Weizhi, WHITE, BLACK);
        //右近光灯
        LCD_DrawImageSBPP(60, 75 + 25 * 14, 21, YJGDSC, WHITE, BLACK);
        //ADD雨刮复位信号
        LCD_DrawImage1BPP(60, 75 + 25 * 15, BMP_a, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 11, 75 + 25 * 15, BMP_d, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 11 + 11, 75 + 25 * 15, BMP_d, WHITE, BLACK);

        for (i = 0; i < 16; i++) {
            if (i == 3 || i == 5 || i == 6 || i == 8 || i == 9 || i == 10 || i == 12 || i == 14)
                LCD_DrawImage1BPP(60 + 63, 75 + 25 * i, BMP_IC_Deng, WHITE, BLACK);
            else if (i == 13)
                LCD_DrawImage1BPP(60 + 42, 75 + 25 * i, BMP_IC_Deng, WHITE, BLACK);
        }
        /***********************前模块开关采集*********************************/
        LCD_DrawImageSBPP(285 + 150, 75 + 25 * 12, 42, DZXZ, WHITE, BLACK);
        print_SZ_2(285 + 150 + 84 + 6, 75 + 25 * 12, 1, 1, 0, WHITE);

        LCD_DrawImageSBPP(285 + 150, 75 + 25 * 13, 42, DZXZ, WHITE, BLACK);
        print_SZ_2(285 + 150 + 84 + 6, 75 + 25 * 13, 2, 1, 0, WHITE);

        LCD_DrawImageSBPP(505 + 100, 75 + 8 + 25 * 15, 21, BBH, WHITE, BLACK);
        LCD_DrawImage1BPP(505 + 200, 75 + 25 * 15, BMP_V, WHITE, BLACK);
    } else if (index == 3) {
        LCD_DrawImageSBPP(130 + 200 + 200, 130 - 85 + 4, 11, CHAR_CAN, WHITE, BLACK);
        LCD_DrawImage1BPP(130 + 200 + 200 + 11 + 11 + 11, 130 - 85 + 4, BMP_Tongxin, WHITE, BLACK);

        print_SZ_2(750, 50, 3, 1, 0, WHITE); // 3/4
        LCD_DrawImage1BPP(750 + 11, 50, BMP_I, WHITE, BLACK);
        print_SZ_2(750 + 11 + 14, 50, 4, 1, 0, WHITE);

        LCD_DrawImage1BPP(130 + 200, 130 - 85, BMP_DING, WHITE, BLACK); //顶
        LCD_DrawImage1BPP(130 + 200 + 25, 130 - 85, BMP_MOKUAI, WHITE, BLACK); //模块
        LCD_DrawImage1BPP(130 + 200 + 25 + 50, 130 - 85, BMP_Message, WHITE, BLACK); //信息
        for (i = 0; i < 15; i++) {
            LCD_DrawImage1BPP(60 + 280, 75 + 3 + 25 * i, BMP_a, WHITE, BLACK);
            //LCD_DrawRect(0, 74 +25+ 25 * i, 800, 1, GRAY); //横线
        }

        /*********************顶模块输出***************************************/
        //长条灯1
        LCD_DrawImage1BPP(60, 75 + 25 * 0, BMP_IC_Changtiao, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 0, BMP_IC_Deng, WHITE, BLACK);
        print_SZ_2(60 + 63 + 6, 75 + 25 * 0, 1, 1, 0, WHITE);
        //右转向灯
        LCD_DrawImage1BPP(60, 75 + 25 * 1, BMP_IC_You, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 1, BMP_IC_Zhuanxiang, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 63, 75 + 25 * 1, BMP_IC_Deng, WHITE, BLACK);
        //司机灯
        LCD_DrawImage1BPP(60, 75 + 25 * 2, BMP_IC_Siji, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 2, BMP_IC_Deng, WHITE, BLACK);
        //制动灯
        LCD_DrawImage1BPP(60, 75 + 25 * 3, BMP_Zhidong, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 3, BMP_IC_Deng, WHITE, BLACK);
        //前门开电磁阀
        LCD_DrawImageSBPP(60, 75 + 25 * 4, 21, QMKDCF, WHITE, BLACK);
        //前路牌
        LCD_DrawImage1BPP(60, 75 + 25 * 5, BMP_IC_Qian, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 5, BMP_Lupai, WHITE, BLACK);
        //前门关输出
        LCD_DrawImageSBPP(60, 75 + 25 * 6, 21, QMGDCF, WHITE, BLACK);
        //电子钟电源
        LCD_DrawImage1BPP(60, 75 + 25 * 7, BMP_Dianzizhong, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 63, 75 + 25 * 7, BMP_Dianyuan, WHITE, BLACK);
        //中门开电磁阀
        LCD_DrawImageSBPP(60, 75 + 25 * 8, 21, ZMKDCF, WHITE, BLACK);
        //后路牌
        LCD_DrawImage1BPP(60, 75 + 25 * 9, BMP_IC_Hou, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 9, BMP_Lupai, WHITE, BLACK);
        //中门关输出
        LCD_DrawImageSBPP(60, 75 + 25 * 10, 21, ZMGDCF, WHITE, BLACK);
        //长条灯2
        LCD_DrawImage1BPP(60, 75 + 25 * 11, BMP_IC_Changtiao, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 11, BMP_IC_Deng, WHITE, BLACK);
        print_SZ_2(60 + 63 + 6, 75 + 25 * 11, 2, 1, 0, WHITE);
        //硬盘电源
        LCD_DrawImage1BPP(60, 75 + 25 * 12, BMP_Yinpan, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 12, BMP_Dianyuan, WHITE, BLACK);
        //位置灯
        LCD_DrawImage1BPP(60, 75 + 25 * 13, BMP_Weizhi, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 13, BMP_IC_Deng, WHITE, BLACK);
        //左转向灯
        LCD_DrawImage1BPP(60, 75 + 25 * 14, BMP_IC_Zuo, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 14, BMP_IC_Zhuanxiang, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 63, 75 + 25 * 14, BMP_IC_Deng, WHITE, BLACK);

        /************************顶模块开关*********************************/
        //门铃开关
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 1, BMP_Men, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 21, 75 + 25 * 1, BMP_Ling, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 1, BMP_IC_Kaiguan, WHITE, BLACK);
        //前门应急阀报警2
        LCD_DrawImageSBPP(285 + 150, 75 + 25 * 3, 21, QMYJF, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 105, 75 + 25 * 3, BMP_Baojing, WHITE, BLACK);
        print_SZ_2(285 + 150 + 105 + 42 + 6, 75 + 25 * 3, 2, 1, 0, WHITE);
        //中门应急阀报警2
        LCD_DrawImageSBPP(285 + 150, 75 + 25 * 5, 21, ZMYJF, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 105, 75 + 25 * 5, BMP_Baojing, WHITE, BLACK);
        print_SZ_2(285 + 150 + 105 + 42 + 6, 75 + 25 * 5, 2, 1, 0, WHITE);
        //地址选择1
        LCD_DrawImageSBPP(285 + 150, 75 + 25 * 12, 42, DZXZ, WHITE, BLACK);
        print_SZ_2(285 + 150 + 84 + 6, 75 + 25 * 12, 1, 1, 0, WHITE);
        //地址选择2
        LCD_DrawImageSBPP(285 + 150, 75 + 25 * 13, 42, DZXZ, WHITE, BLACK);
        print_SZ_2(285 + 150 + 84 + 6, 75 + 25 * 13, 2, 1, 0, WHITE);
        

        //模块程序版本号
        LCD_DrawImageSBPP(505 + 100, 75 + 8 + 25 * 15, 21, BBH, WHITE, BLACK);
        LCD_DrawImage1BPP(505 + 200, 75 + 25 * 15, BMP_V, WHITE, BLACK);
    } else if (index == 4) {
        LCD_DrawImageSBPP(130 + 200 + 200, 130 - 85 + 4, 11, CHAR_CAN, WHITE, BLACK);
        LCD_DrawImage1BPP(130 + 200 + 200 + 11 + 11 + 11, 130 - 85 + 4, BMP_Tongxin, WHITE, BLACK);

        print_SZ_2(750, 50, 4, 1, 0, WHITE); // 4/4
        LCD_DrawImage1BPP(750 + 11, 50, BMP_I, WHITE, BLACK);
        print_SZ_2(750 + 11 + 14, 50, 4, 1, 0, WHITE);

        LCD_DrawImage1BPP(130 + 200, 130 - 85, BMP_HOU, WHITE, BLACK); //后
        LCD_DrawImage1BPP(130 + 200 + 25, 130 - 85, BMP_MOKUAI, WHITE, BLACK); //模块
        LCD_DrawImage1BPP(130 + 200 + 25 + 50, 130 - 85, BMP_Message, WHITE, BLACK); //信息
        for (i = 0; i < 15; i++) {
            LCD_DrawImage1BPP(60 + 280, 75 + 3 + 25 * i, BMP_a, WHITE, BLACK);
        }
        /*********************后模块输出***************************************/
        //制动灯
        LCD_DrawImage1BPP(60, 75 + 25 * 0, BMP_Zhidong, WHITE, BLACK);
        //侧路牌
        LCD_DrawImage1BPP(60, 75 + 25 * 1, BMP_Ce, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 1, BMP_Lupai, WHITE, BLACK);
        //后雾灯
        LCD_DrawImage1BPP(60, 75 + 25 * 2, BMP_IC_Hou, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 2, BMP_IC_Wu, WHITE, BLACK);
        //整车控制器电源
        LCD_DrawImage1BPP(60, 75 + 25 * 3, BMP_Zhengche, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 3, BMP_KZQ, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 105, 75 + 25 * 3, BMP_Dianyuan, WHITE, BLACK);
        //左转向灯
        LCD_DrawImage1BPP(60, 75 + 25 * 4, BMP_IC_Zuo, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 4, BMP_IC_Zhuanxiang, WHITE, BLACK);
        //气压电源
        LCD_DrawImage1BPP(60, 75 + 25 * 5, BMP_Qiya, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 5, BMP_Dianyuan, WHITE, BLACK);
        //右转向灯
        LCD_DrawImage1BPP(60, 75 + 25 * 6, BMP_IC_You, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 6, BMP_IC_Zhuanxiang, WHITE, BLACK);
        //电喇叭1
        LCD_DrawImage1BPP(60, 75 + 25 * 7, BMP_DC, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 7, BMP_Laba, WHITE, BLACK);
        print_SZ_2(60 + 63 + 6, 75 + 25 * 7, 1, 1, 0, WHITE);
        //倒车灯1
        LCD_DrawImage1BPP(60, 75 + 25 * 8, BMP_Daoche, WHITE, BLACK);
        print_SZ_2(60 + 63 + 6, 75 + 25 * 8, 1, 1, 0, WHITE);
        //电喇叭2
        LCD_DrawImage1BPP(60, 75 + 25 * 9, BMP_DC, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 9, BMP_Laba, WHITE, BLACK);
        print_SZ_2(60 + 63 + 6, 75 + 25 * 9, 2, 1, 0, WHITE);
        //前门踏步灯
        LCD_DrawImage1BPP(60, 75 + 25 * 10, BMP_IC_Qian, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 10, BMP_Men, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 10, BMP_Tabu, WHITE, BLACK);
        //位置灯
        LCD_DrawImage1BPP(60, 75 + 25 * 11, BMP_Weizhi, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 11, BMP_IC_Deng, WHITE, BLACK);
        //中门踏板灯
        LCD_DrawImage1BPP(60, 75 + 25 * 12, BMP_Zhong, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 12, BMP_Men, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 12, BMP_Tabu, WHITE, BLACK);
        //倒车喇叭
        LCD_DrawImage1BPP(60, 75 + 25 * 13, BMP_Daoche, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 13, BMP_Laba, WHITE, BLACK);
        //倒车灯2
        LCD_DrawImage1BPP(60, 75 + 25 * 14, BMP_Daoche, WHITE, BLACK);
        print_SZ_2(60 + 63 + 6, 75 + 25 * 14, 2, 1, 0, WHITE);

        //灯
        for (i = 0; i < 16; i++) {
            if (i == 0 || i == 2 || i == 8 || i == 11 || i == 14)
                LCD_DrawImage1BPP(60 + 42, 75 + 25 * i, BMP_IC_Deng, WHITE, BLACK);
            if (i == 4 || i == 6)
                LCD_DrawImage1BPP(60 + 63, 75 + 25 * i, BMP_IC_Deng, WHITE, BLACK);
            if (i == 10 || i == 12)
                LCD_DrawImage1BPP(60 + 84, 75 + 25 * i, BMP_IC_Deng, WHITE, BLACK);
        }
        /*********************后模块开关***************************************/
        //水位报警
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 0, BMP_Shuiwei, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 0, BMP_Baojing, WHITE, BLACK);
        //左前摩擦片报警
        LCD_DrawImageSBPP(285 + 150, 75 + 25 * 1, 21, ZQMCQ, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 105, 75 + 25 * 1, BMP_Baojing, WHITE, BLACK);
        //前门应急阀报警1
        LCD_DrawImageSBPP(285 + 150, 75 + 25 * 2, 21, QMYJF, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 105, 75 + 25 * 2, BMP_Baojing, WHITE, BLACK);
        print_SZ_2(285 + 150 + 105 + 42 + 6, 75 + 25 * 2, 1, 1, 0, WHITE);
        //右前摩擦片报警
        LCD_DrawImageSBPP(285 + 150, 75 + 25 * 3, 21, YQMCQ, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 105, 75 + 25 * 3, BMP_Baojing, WHITE, BLACK);
        //中门应急阀报警1
        LCD_DrawImageSBPP(285 + 150, 75 + 25 * 4, 21, ZMYJF, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 105, 75 + 25 * 4, BMP_Baojing, WHITE, BLACK);
        print_SZ_2(285 + 150 + 105 + 42 + 6, 75 + 25 * 4, 1, 1, 0, WHITE);
        //制动开关
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 5, BMP_Zhidong, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 5, BMP_IC_Kaiguan, WHITE, BLACK);
        //驻车制动开关
        LCD_DrawImageSBPP(285 + 150, 75 + 25 * 7, 42, ZCZDKG, WHITE, BLACK);
        //后舱门
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 10, BMP_IC_Hou, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 21, 75 + 25 * 10, BMP_Cangmen, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 63, 75 + 25 * 10, BMP_IC_Kaiguan, WHITE, BLACK);
        //地址选择1
        LCD_DrawImageSBPP(285 + 150, 75 + 25 * 12, 42, DZXZ, WHITE, BLACK);
        print_SZ_2(285 + 150 + 84 + 6, 75 + 25 * 12, 1, 1, 0, WHITE);
        //地址选择2
        LCD_DrawImageSBPP(285 + 150, 75 + 25 * 13, 42, DZXZ, WHITE, BLACK);
        print_SZ_2(285 + 150 + 84 + 6, 75 + 25 * 13, 2, 1, 0, WHITE);
        //中门开信号
        LCD_DrawImageSBPP(285 + 150, 75 + 25 * 14, 21, ZMKXH, WHITE, BLACK);
        //前门开信号
        LCD_DrawImageSBPP(285 + 150, 75 + 25 * 15, 21, QMKXH, WHITE, BLACK);

        LCD_DrawImageSBPP(505 + 100, 75 + 8 + 25 * 15, 21, BBH, WHITE, BLACK);
        LCD_DrawImage1BPP(505 + 200, 75 + 25 * 15, BMP_V, WHITE, BLACK);
    }
}

void ICUpdate(unsigned char index) {
    unsigned int dump, i;
    unsigned char color;
    if (index == 1) {
        if (Bcan_count == CAN_TIME && Vcan_count == CAN_TIME)
            LCD_DrawImage1BPP(130 + 200 + 200 + 11 + 11 + 11 + 50 + 20, 130 - 85 + 4, BMP_Guzhang, RED, BLACK);
        else LCD_DrawImage1BPP(130 + 200 + 200 + 11 + 11 + 11 + 50 + 20, 130 - 85 + 4, BMP_Zhengchang, GREEN, BLACK);

        for (i = 0; i < 6; i++) {
            print_SZ_2(535 + 63 + 42 + 4, 75 + 25 * (i + 8), ADR[i + 1], 3, 0, YELLOW);
        }
        for (i = 0; i < 6; i++) {
            print_SZ_2(535 + 63 + 42 + 16 * 5, 75 + 25 * (i + 8), ADV[i + 1] / 10, 3, 2, YELLOW);
        }

        dump = sw_input[0].byte + ((unsigned int) (sw_input[1].byte) << 8);
        for (i = 0; i < 16; i++) {
            if (i == 3 || i == 1 || i == 2) {//为控火开关
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
            /*if (i == 9) {//IN26 为控火开关
                if ((dump & 0x01) == 0x01) {
                    LCD_DrawImage1BPP(255, 75 + 25 * i, Bmpflag[0], WHITE, BLACK);
                } else {
                    LCD_DrawImage1BPP(255, 75 + 25 * i, Bmpflag[1], GREEN, BLACK);
                }
            } else */
            if ((dump & 0x01) == 0x01) {
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
        //对接日期
        print_SZ_1(535 + 25, 75 + 25 * 15, TIME, 8, 0, YELLOW);
        //程序版本号
        print_SZ_1(535 + 200, 75 + 25 * 15, VERISON, 3, 2, YELLOW);
    } else if (index == 2) {
        if (Fcan_count == CAN_TIME)
            LCD_DrawImage1BPP(130 + 200 + 200 + 11 + 11 + 11 + 50 + 20, 130 - 85 + 4, BMP_Guzhang, RED, BLACK);
        else LCD_DrawImage1BPP(130 + 200 + 200 + 11 + 11 + 11 + 50 + 20, 130 - 85 + 4, BMP_Zhengchang, GREEN, BLACK);

        dump = fPOUT.WORDS; //POUT0 -POUT15   
        for (i = 0; i < 15; i++) {
            if ((dump & 0x01) == 0x01) {
                if (fPF[i] == 0) color = GREEN;
                else if (fPF[i] == 1) color = YELLOW;
                else color = RED;
                LCD_DrawImage1BPP(30, 75 + 25 * i, Bmpflag[1], color, BLACK);
            } else {
                LCD_DrawImage1BPP(30, 75 + 25 * i, Bmpflag[0], WHITE, BLACK);
            }
            dump = dump >> 1;
            if (fpcur[i] / 100 > 10)
                print_SZ(30 + 250, 75 + 6 + 25 * i, fpcur[i] / 100, 3, 1, YELLOW); //前模块电流
            else
                print_SZ(30 + 250, 75 + 6 + 25 * i, 0, 3, 1, YELLOW);
        }
        //ADD雨刮复位信号
        if (fADD)
            LCD_DrawImage1BPP(30, 75 + 25 * 15, Bmpflag[1], GREEN, BLACK);
        else
            LCD_DrawImage1BPP(30, 75 + 25 * 15, Bmpflag[0], WHITE, BLACK);

        dump = fKEY.BYTES[0]+((unsigned int) (fKEY.BYTES[1]) << 8); //KL1-KL15
        for (i = 0; i < 15; i++) {
            if ((dump & 0x01) == 0x01) {
                LCD_DrawImage1BPP(255 + 150, 75 + 25 * i, Bmpflag[1], GREEN, BLACK);
            } else {
                LCD_DrawImage1BPP(255 + 150, 75 + 25 * i, Bmpflag[0], WHITE, BLACK);
            }
            dump = dump >> 1;
        }

        dump = fKEY.BYTES[2]; //KH1
        if ((dump & 0x01) == 0x01) {
            LCD_DrawImage1BPP(255 + 150, 75 + 25 * 15, Bmpflag[1], GREEN, BLACK);
        } else {
            LCD_DrawImage1BPP(255 + 150, 75 + 25 * 15, Bmpflag[0], WHITE, BLACK);
        }
        //程序版本号
        print_SZ_1(535 + 200, 75 + 25 * 15, Fversion, 3, 2, YELLOW);
    }

    /*中控模块*/
    if (index == 3) {
        if (Mcan_count == CAN_TIME)
            LCD_DrawImage1BPP(130 + 200 + 200 + 11 + 11 + 11 + 50 + 20, 130 - 85 + 4, BMP_Guzhang, RED, BLACK);
        else LCD_DrawImage1BPP(130 + 200 + 200 + 11 + 11 + 11 + 50 + 20, 130 - 85 + 4, BMP_Zhengchang, GREEN, BLACK);

        dump = mPOUT.WORDS; //POUT1 -POUT15   
        for (i = 0; i < 15; i++) {
            if ((dump & 0x01) == 0x01) {
                if (mPF[i] == 0) color = GREEN;
                else if (mPF[i] == 1) color = YELLOW;
                else color = RED;
                LCD_DrawImage1BPP(30, 75 + 25 * i, Bmpflag[1], color, BLACK);
            } else {
                LCD_DrawImage1BPP(30, 75 + 25 * i, Bmpflag[0], WHITE, BLACK);
            }
            dump = dump >> 1;
            if (mpcur[i] / 100 > 10)
                print_SZ(30 + 250, 75 + 6 + 25 * i, mpcur[i] / 100, 3, 1, YELLOW); //顶模块电流
            else
                print_SZ(30 + 250, 75 + 6 + 25 * i, 0, 3, 1, YELLOW);
        }

        dump = mKEY.BYTES[0]+((unsigned int) (mKEY.BYTES[1]) << 8); //KL1-KL15
        for (i = 0; i < 15; i++) {
            if ((dump & 0x01) == 0x01) {
                LCD_DrawImage1BPP(255 + 150, 75 + 25 * i, Bmpflag[1], GREEN, BLACK);
            } else {
                LCD_DrawImage1BPP(255 + 150, 75 + 25 * i, Bmpflag[0], WHITE, BLACK);
            }
            dump = dump >> 1;
        }

        dump = mKEY.BYTES[2]; //KH1
        if ((dump & 0x01) == 0x01) {
            LCD_DrawImage1BPP(255 + 150, 75 + 25 * 15, Bmpflag[1], GREEN, BLACK);
        } else {
            LCD_DrawImage1BPP(255 + 150, 75 + 25 * 15, Bmpflag[0], WHITE, BLACK);
        }
        //程序版本号
        print_SZ_1(535 + 200, 75 + 25 * 15, Mversion, 3, 2, YELLOW);
    }

    /*后控模块*/
    if (index == 4) {
        if (Rcan_count == CAN_TIME)
            LCD_DrawImage1BPP(130 + 200 + 200 + 11 + 11 + 11 + 50 + 20, 130 - 85 + 4, BMP_Guzhang, RED, BLACK);
        else LCD_DrawImage1BPP(130 + 200 + 200 + 11 + 11 + 11 + 50 + 20, 130 - 85 + 4, BMP_Zhengchang, GREEN, BLACK);

        dump = rPOUT.WORDS; //POUT1 -POUT15   
        for (i = 0; i < 15; i++) {
            if ((dump & 0x01) == 0x01) {
                if (rPF[i] == 0) color = GREEN;
                else if (rPF[i] == 1) color = YELLOW;
                else color = RED;
                LCD_DrawImage1BPP(30, 75 + 25 * i, Bmpflag[1], color, BLACK);
            } else {
                LCD_DrawImage1BPP(30, 75 + 25 * i, Bmpflag[0], WHITE, BLACK);
            }
            dump = dump >> 1;
            if (rpcur[i] / 100 > 10)
                print_SZ(30 + 250, 75 + 6 + 25 * i, rpcur[i] / 100, 3, 1, YELLOW); //后模块电流
            else
                print_SZ(30 + 250, 75 + 6 + 25 * i, 0, 3, 1, YELLOW);
        }

        dump = rKEY.BYTES[0]+((unsigned int) (rKEY.BYTES[1]) << 8); //KL1-KL15
        for (i = 0; i < 15; i++) {
            if ((dump & 0x01) == 0x01) {
                LCD_DrawImage1BPP(255 + 150, 75 + 25 * i, Bmpflag[1], GREEN, BLACK);
            } else {
                LCD_DrawImage1BPP(255 + 150, 75 + 25 * i, Bmpflag[0], WHITE, BLACK);
            }
            dump = dump >> 1;
        }

        dump = rKEY.BYTES[2]; //KH1
        if ((dump & 0x01) == 0x01) {
            LCD_DrawImage1BPP(255 + 150, 75 + 25 * 15, Bmpflag[1], GREEN, BLACK);
        } else {
            LCD_DrawImage1BPP(255 + 150, 75 + 25 * 15, Bmpflag[0], WHITE, BLACK);
        }
        //程序版本号
        print_SZ_1(535 + 200, 75 + 25 * 15, Rversion, 3, 2, YELLOW);
    }
}

void frmIC(void) {
    static unsigned char index_IC = 1;
    if (f_index == 0) { //只更新一次
        f_index = 1;
        ICFrame(index_IC);
    } else if (f_index == 1) {
        f_index = 1;
        ICUpdate(index_IC);
    } else {
        f_index = 0;
    }

    if (key_up) { //子菜单切换
        key_up = 0;
        index_IC++;
        f_index = 0;
        if (index_IC == 5) {
            index_IC = 1;
            frmID = 1;
        }
    }

    if (key_AV) {
        key_AV = 0;
        index_IC--;
        f_index = 0;
        if (index_IC == 0) {
            index_IC = 1;
            frmID = 1;
        }
    }

    if (key_set) {//主菜单/子菜单切换
        key_set = 0;
        frmID = 0;
        f_index = 0;
        index_IC = 1;
    }

    if (key_long_set) {
        key_long_set = 0;
    }

}

/******************************************************/

void MOTOFrame(void) {
    unsigned char i = 0;
    LCD_Clear();
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //顶部横线
    LCD_DrawImageSBPP(130 + 200, 130 - 85, 50, MOTO_SYSTEM, WHITE, BLACK); //电机

    LCD_DrawRect(80, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320 + 320, 90, 1, 380, GREEN);
    for (i = 0; i < 11; i++)
        LCD_DrawRect(80, 90 + i * 38, 640, 1, GREEN);

    LCD_DrawImage1BPP(82, 100, BMP_DJ, WHITE, BLACK); //电机
    LCD_DrawImage1BPP(82 + 42, 100, BMP_Shuliang, WHITE, BLACK); //数量

    LCD_DrawImage1BPP(82, 100 + 38, BMP_DJ, WHITE, BLACK); //电机序号
    LCD_DrawImage1BPP(82 + 42, 100 + 38, BMP_Xuhao, WHITE, BLACK);
    LCD_DrawImage1BPP(82 + 63, 100 + 38, BMP_Hao, WHITE, BLACK);

    LCD_DrawImageSBPP(82, 100 + 38 * 2, 42, DJZLDY, WHITE, BLACK); //电机直流电压
    LCD_DrawImage1BPP(400 - 24, 100 + 38 * 2, BMP_v, WHITE, BLACK); //V

    LCD_DrawImageSBPP(82, 100 + 38 * 3, 42, DJZLDL, WHITE, BLACK); //电机直流电流
    LCD_DrawImage1BPP(400 - 24, 100 + 38 * 3, BMP_a, WHITE, BLACK); //A

    LCD_DrawImageSBPP(82, 100 + 38 * 4, 42, DJGZZT, WHITE, BLACK); //电机工作状态

    /*LCD_DrawImage1BPP(400 - 24 - 11 - 11 - 11, 100 + 38 * 2, BMP_k, WHITE, BLACK); //km/h
    LCD_DrawImage1BPP(400 - 24 - 11 - 11, 100 + 38 * 2, BMP_m, WHITE, BLACK); //
    LCD_DrawImage1BPP(400 - 24 - 11, 100 + 38 * 2, BMP_I, WHITE, BLACK); //
    LCD_DrawImage1BPP(400 - 24, 100 + 38 * 2, BMP_h, WHITE, BLACK); //
     */
    LCD_DrawImage1BPP(82, 100 + 38 * 5, BMP_Zhengche, WHITE, BLACK); //整车
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 5, BMP_KZQ, WHITE, BLACK); //控制器
    LCD_DrawImage1BPP(82 + 42 + 63, 100 + 38 * 5, BMP_Life, WHITE, BLACK); //Life

    LCD_DrawImage1BPP(82, 100 + 38 * 6, BMP_Zhengche, WHITE, BLACK); //整车
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 6, BMP_Zhuangtai, WHITE, BLACK); //状态1
    //LCD_DrawImage1BPP(82 + 42 + 42, 100 - 8 + 4 * 38, BMP_SZ_1[1], WHITE, BLACK); //1

    LCD_DrawImageSBPP(82, 100 + 38 * 7,42, ZCGZDM, WHITE, BLACK); //整车故障代码

    

    LCD_DrawImageSBPP(82 + 320, 100,42, DJZS, WHITE, BLACK); //电机转速
    LCD_DrawImage1BPP(720 - 24 - 24, 100, BMP_RPM, WHITE, BLACK); //RPM

    LCD_DrawImageSBPP(82 + 320, 100 + 38, 42,DJZJ, WHITE, BLACK); //电机转矩
    LCD_DrawImage1BPP(720 - 24 - 11, 100 + 38, BMP_n, WHITE, BLACK); //NM
    LCD_DrawImage1BPP(720 - 24, 100 + 38, BMP_m, WHITE, BLACK); //

    LCD_DrawImageSBPP(82 + 320, 100 + 38 * 2,42, DJWD, WHITE, BLACK); //电机温度
    LCD_DrawImage1BPP(720 - 28, 100 + 38 * 2, BMP_T, WHITE, BLACK); //℃

    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 3, BMP_KZQ, WHITE, BLACK); //控制器
    LCD_DrawImage1BPP(82 + 320 + 63, 100 + 38 * 3, BMP_Wendu, WHITE, BLACK); //温度
    LCD_DrawImage1BPP(720 - 28, 100 + 38 * 3, BMP_T, WHITE, BLACK); //℃

    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 4, BMP_Youmen, WHITE, BLACK); //油门
    LCD_DrawImage1BPP(82 + 42 + 320, 100 + 38 * 4, BMP_Taban, WHITE, BLACK); //踏板
    LCD_DrawImage1BPP(720 - 24, 100 + 38 * 4, BMP_Baifenhao, WHITE, BLACK); //%

    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 5, BMP_Zhidong, WHITE, BLACK); //制动
    LCD_DrawImage1BPP(82 + 42 + 320, 100 + 38 * 5, BMP_Taban, WHITE, BLACK); //踏板
    LCD_DrawImage1BPP(720 - 24, 100 + 38 * 5, BMP_Baifenhao, WHITE, BLACK); //%
}

void MOTOUpdate(void) {
    //print_SZ_1(82 + 200 + 20, 100 - 8, TM_Current_AC * 0.1, 4, 0, WHITE);
    print_SZ_1(82 + 200 + 20 + 16, 100 - 8, TM_Number, 3, 0, WHITE);
    print_SZ_1(82 + 200 + 20 + 16, 100 - 8 + 38, TM_Serial, 3, 0, WHITE);
    print_SZ_1(82 + 200 + 20, 100 - 8 + 38 * 2, TM_Voltage_DC * 0.1, 4, 0, WHITE);
    updata_DAT(82 + 200 + 20, 100 - 8 + 38 * 3, TM_Current_DC * 0.1, 1, 1000, WHITE, 4, 0);
    print_SZ_1(82 + 200 + 20 + 16, 100 - 8 + 38 * 4, TM_WorkStatus, 3, 0, WHITE); //电机工作状态
    //print_SZ_1(82 + 200 + 20 - 16, 100 - 8 + 38 * 2, DMC_Speed * 0.5, 3, 0, WHITE);
    //print_D(82 + 180, 100 - 8 + 38 * 3, (DMC_Status << 5)+(DMC_Level << 3)); //电机控制器基本状态
    print_SZ_1(82 + 200 + 20 + 16, 100 - 8 + 38 * 5, VCU_Life, 3, 0, WHITE); //整车控制器LIFE
    //print_SZ_1(82 + 200 + 20, 100 - 8 + 38 * 5, DMC_Verison, 3, 2, WHITE); //程序版本
    //print_SZ_1(82 + 200 + 20 + 16 * 3, 100 - 8 + 38 * 6, DMC_Charge, 1, 0, WHITE); //充放电状态
    print_D(82 + 180, 100 - 8 + 38 * 6, VCU_Status_Flag1.byte, 8, 0, WHITE); //VCU状态1
    print_SZ_1(82 + 200 + 20 + 16, 100 - 8 + 38 * 7, VCU_Code, 3, 0, WHITE); //整车故障代码

    /*print_D(82 + 180, 100 - 8 + 38 * 6, TM_StatusFeedback, 8, 0, WHITE); //电机反馈状态    
    print_SZ_1(82 + 200 + 20 + 32, 100 - 8 + 38 * 8, TM_LIFE, 2, 0, WHITE); //电机控制器LIFE
    print_SZ_1(82 + 200 + 20 + 32, 100 - 8 + 38 * 9, TM_Status, 2, 0, WHITE); //电机状态
     */


    updata_DAT(82 + 200 + 300, 100 - 8, TM_Feedback_RPM, 1, 20000, WHITE, 5, 0);
    updata_DAT(82 + 200 + 300 + 16, 100 - 8 + 38, TM_Feedback_NM, 0.1, 2000, WHITE, 4, 0);
    updata_DAT(82 + 200 + 300 + 32, 100 - 8 + 38 * 2, TM_Temp, 1, 40, WHITE, 3, 0);
    updata_DAT(82 + 200 + 300 + 32, 100 - 8 + 38 * 3, TM_Control_Temp, 1, 40, WHITE, 3, 0);
    //print_D(82 + 180 + 320, 100 - 8 + 38 * 4, DMC_Protect_code); //保护代码
    print_SZ_1(82 + 200 + 20 + 320 - 16, 100 - 8 + 38 * 4, VCU_TM_Speed_percent * 4, 4, 1, WHITE); //油门开度
    print_SZ_1(82 + 200 + 20 + 320 - 16, 100 - 8 + 38 * 5, VCU_TM_Brake_percent * 4, 4, 1, WHITE); //制动开度
    /*print_SZ_1(82 + 200 + 300, 100 - 8 + 38 * 6, TM_Torque_Limit_Up, 5, 0, WHITE);
    print_SZ_1(82 + 200 + 300, 100 - 8 + 38 * 7, TM_Torque_Limit_Down, 5, 0, WHITE);
    print_SZ_1(82 + 200 + 300 + 32, 100 - 8 + 38 * 8, TM_Fault.byte, 3, 0, WHITE); //整车故障等级
    print_SZ_1(82 + 200 + 300 + 32, 100 - 8 + 38 * 9, TM_Code, 3, 0, WHITE); //整车故障代码
     */

    /*
    
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
     */
}

void frmMOTO(void) {
    if (f_index == 0) { //只更新一次
        f_index = 1;
        MOTOFrame();
    } else if (f_index == 1) {
        f_index = 1;
        MOTOUpdate();
    } else {
        f_index = 0;
    }
    if (key_AV) {
        frmID = 1;
        f_index = 0;
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

void DMQFrame(void) {
    unsigned char i = 0;
    LCD_Clear();
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //顶部横线
    LCD_DrawImageSBPP(130 + 200 - 15, 130 - 85, 50, AIR_SYSTEM, WHITE, BLACK); //气泵

    LCD_DrawRect(80, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320 + 320, 90, 1, 380, GREEN);
    for (i = 0; i < 11; i++)
        LCD_DrawRect(80, 90 + i * 38, 640, 1, GREEN);

    LCD_DrawImage1BPP(82, 100 - 2, BMP_DCAC, WHITE, BLACK); //DCAC
    LCD_DrawImage1BPP(82 + 52 + 11, 100, BMP_w, WHITE, BLACK); //  W
    LCD_DrawImage1BPP(82 + 52 + 11 + 11, 100, BMP_Xiang, WHITE, BLACK); //相
    LCD_DrawImage1BPP(82 + 52 + 11 + 11 + 21, 100, BMP_Output, WHITE, BLACK); //输出
    LCD_DrawImage1BPP(82 + 52 + 11 + 11 + 21 + 42, 100, BMP_DL, WHITE, BLACK); //电流
    LCD_DrawImage1BPP(400 - 24, 100, BMP_a, WHITE, BLACK); //A

    LCD_DrawImage1BPP(82, 100 - 2 + 38, BMP_DCAC, WHITE, BLACK); //DCAC
    LCD_DrawImage1BPP(82 + 52 + 11, 100 + 38, BMP_w, WHITE, BLACK); //  W
    LCD_DrawImage1BPP(82 + 52 + 11 + 11, 100 + 38, BMP_Xiang, WHITE, BLACK); //相
    LCD_DrawImage1BPP(82 + 52 + 11 + 11 + 21, 100 + 38, BMP_Output, WHITE, BLACK); //输出
    LCD_DrawImage1BPP(82 + 52 + 11 + 11 + 21 + 42, 100 + 38, BMP_DY, WHITE, BLACK); //电压
    LCD_DrawImage1BPP(400 - 24, 100 + 38, BMP_v, WHITE, BLACK); //V

    LCD_DrawImage1BPP(82, 100 - 2 + 38 * 2, BMP_DCAC, WHITE, BLACK); //DCAC
    LCD_DrawImage1BPP(82 + 52 + 11, 100 + 38 * 2, BMP_v, WHITE, BLACK); //  V
    LCD_DrawImage1BPP(82 + 52 + 11 + 11, 100 + 38 * 2, BMP_Xiang, WHITE, BLACK); //相
    LCD_DrawImage1BPP(82 + 52 + 11 + 11 + 21, 100 + 38 * 2, BMP_Output, WHITE, BLACK); //输出
    LCD_DrawImage1BPP(82 + 52 + 11 + 11 + 21 + 42, 100 + 38 * 2, BMP_DL, WHITE, BLACK); //电流
    LCD_DrawImage1BPP(400 - 24, 100 + 38 * 2, BMP_a, WHITE, BLACK); //A

    LCD_DrawImage1BPP(82, 100 - 2 + 38 * 3, BMP_DCAC, WHITE, BLACK); //DCAC
    LCD_DrawImage1BPP(82 + 52 + 11, 100 + 38 * 3, BMP_v, WHITE, BLACK); //  V
    LCD_DrawImage1BPP(82 + 52 + 11 + 11, 100 + 38 * 3, BMP_Xiang, WHITE, BLACK); //相
    LCD_DrawImage1BPP(82 + 52 + 11 + 11 + 21, 100 + 38 * 3, BMP_Output, WHITE, BLACK); //输出
    LCD_DrawImage1BPP(82 + 52 + 11 + 11 + 21 + 42, 100 + 38 * 3, BMP_DY, WHITE, BLACK); //电压
    LCD_DrawImage1BPP(400 - 24, 100 + 38 * 3, BMP_v, WHITE, BLACK); //V

    LCD_DrawImage1BPP(82, 100 - 2 + 38 * 4, BMP_DCAC, WHITE, BLACK); //DCAC
    LCD_DrawImage1BPP(82 + 52 + 11, 100 + 38 * 4, BMP_u, WHITE, BLACK); //  U
    LCD_DrawImage1BPP(82 + 52 + 11 + 11, 100 + 38 * 4, BMP_Xiang, WHITE, BLACK); //相
    LCD_DrawImage1BPP(82 + 52 + 11 + 11 + 21, 100 + 38 * 4, BMP_Output, WHITE, BLACK); //输出
    LCD_DrawImage1BPP(82 + 52 + 11 + 11 + 21 + 42, 100 + 38 * 4, BMP_DL, WHITE, BLACK); //电流
    LCD_DrawImage1BPP(400 - 24, 100 + 38 * 4, BMP_a, WHITE, BLACK); //A

    LCD_DrawImage1BPP(82, 100 - 2 + 38 * 5, BMP_DCAC, WHITE, BLACK); //DCAC
    LCD_DrawImage1BPP(82 + 52 + 11, 100 + 38 * 5, BMP_u, WHITE, BLACK); //  U
    LCD_DrawImage1BPP(82 + 52 + 11 + 11, 100 + 38 * 5, BMP_Xiang, WHITE, BLACK); //相
    LCD_DrawImage1BPP(82 + 52 + 11 + 11 + 21, 100 + 38 * 5, BMP_Output, WHITE, BLACK); //输出
    LCD_DrawImage1BPP(82 + 52 + 11 + 11 + 21 + 42, 100 + 38 * 5, BMP_DY, WHITE, BLACK); //电压
    LCD_DrawImage1BPP(400 - 24, 100 + 38 * 5, BMP_v, WHITE, BLACK); //V

    LCD_DrawImage1BPP(82 + 320, 100, BMP_KZQ, WHITE, BLACK); //控制器
    LCD_DrawImage1BPP(82 + 320 + 63, 100, BMP_Wendu, WHITE, BLACK); //温度
    LCD_DrawImage1BPP(720 - 24, 100, BMP_T, WHITE, BLACK); //℃

    LCD_DrawImage1BPP(82 + 320, 100 + 38, BMP_Guzhang, WHITE, BLACK); //故障
    LCD_DrawImage1BPP(82 + 42 + 320, 100 + 38, BMP_Code, WHITE, BLACK); //代码

    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 2, BMP_Guzhang, WHITE, BLACK); //故障
    LCD_DrawImage1BPP(82 + 42 + 320, 100 + 38 * 2, BMP_Dengji, WHITE, BLACK); //等级

    LCD_DrawImage1BPP(82 + 320, 100 - 2 + 38 * 3, BMP_DCAC, WHITE, BLACK); //DCAC
    LCD_DrawImage1BPP(82 + 320 + 52, 100 + 2 + 38 * 3, BMP_Input, WHITE, BLACK); //输入
    LCD_DrawImage1BPP(82 + 320 + 52 + 42, 100 + 2 + 38 * 3, BMP_Qieduan, WHITE, BLACK); //切断

    LCD_DrawImage1BPP(82 + 320, 100 - 2 + 38 * 4, BMP_DCAC, WHITE, BLACK); //DCAC
    LCD_DrawImage1BPP(82 + 320 + 52, 100 + 2 + 38 * 4, BMP_Output, WHITE, BLACK); //输出
    LCD_DrawImage1BPP(82 + 320 + 52 + 42, 100 + 2 + 38 * 4, BMP_Qieduan, WHITE, BLACK); //切断

    LCD_DrawImage1BPP(82 + 320, 100 - 2 + 38 * 5, BMP_DCAC, WHITE, BLACK); //DCAC
    LCD_DrawImage1BPP(82 + 320 + 52, 100 + 2 + 38 * 5, BMP_Gongzuo, WHITE, BLACK); //工作
    LCD_DrawImage1BPP(82 + 320 + 52 + 42, 100 + 2 + 38 * 5, BMP_Zhuangtai, WHITE, BLACK); //状态

    LCD_DrawImage1BPP(82 + 320, 100 - 2 + 38 * 6, BMP_DCAC, WHITE, BLACK); //DCAC温度报警
    LCD_DrawImage1BPP(82 + 320 + 52, 100 - 2 + 38 * 6, BMP_Wendu, WHITE, BLACK);
    LCD_DrawImage1BPP(82 + 320 + 52 + 42, 100 - 2 + 38 * 6, BMP_Baojing, WHITE, BLACK);

    LCD_DrawImage1BPP(82 + 320, 100 - 2 + 38 * 7, BMP_DCAC, WHITE, BLACK); //DCAC温度报警
    LCD_DrawImage1BPP(82 + 320 + 52, 100 - 2 + 38 * 7, BMP_Guzhang, WHITE, BLACK);
    LCD_DrawImage1BPP(82 + 320 + 52 + 42, 100 - 2 + 38 * 7, BMP_Zhuangtai, WHITE, BLACK);

}

void DMQUpdate(void) {
    print_SZ_1(82 + 200 + 20 - 16, 100 - 8, AIRDCAC_W_Current * 0.1, 4, 0, WHITE);
    print_SZ_1(82 + 200 + 20 - 16, 100 - 8 + 38, AIRDCAC_W_Voltage * 0.1, 4, 0, WHITE);
    print_SZ_1(82 + 200 + 20 - 16, 100 - 8 + 38 * 2, AIRDCAC_V_Current * 0.1, 4, 0, WHITE);
    print_SZ_1(82 + 200 + 20 - 16, 100 - 8 + 38 * 3, AIRDCAC_V_Voltage * 0.1, 4, 0, WHITE);
    print_SZ_1(82 + 200 + 20 - 16, 100 - 8 + 38 * 4, AIRDCAC_U_Current * 0.1, 4, 0, WHITE);
    print_SZ_1(82 + 200 + 20 - 16, 100 - 8 + 38 * 5, AIRDCAC_U_Voltage * 0.1, 4, 0, WHITE);

    updata_DAT(82 + 200 + 300, 100 - 8, AIRDCAC_Temp, 1, 40, WHITE, 3, 0);
    print_SZ_1(82 + 200 + 300 + 16, 100 - 8 + 38, AIRDCAC_Fault_Code, 2, 0, WHITE);
    print_SZ_1(82 + 200 + 300 + 16, 100 - 8 + 38 * 2, AIRDCAC_Level_Fault, 2, 0, WHITE);
    print_SZ_1(82 + 200 + 300 + 16, 100 - 8 + 38 * 3, AIRDCAC_intput_Cut, 2, 0, WHITE);
    print_SZ_1(82 + 200 + 300 + 16, 100 - 8 + 38 * 4, AIRDCAC_Output_Cut, 2, 0, WHITE);
    print_SZ_1(82 + 200 + 300 + 16, 100 - 8 + 38 * 5, AIRDCAC_Status, 2, 0, WHITE);
    print_SZ_1(82 + 200 + 300 + 16, 100 - 8 + 38 * 6, AIRDCAC_Temp_Warn, 2, 0, WHITE);
    print_SZ_1(82 + 200 + 300 + 16, 100 - 8 + 38 * 7, AIRDCAC_Fault_Warn, 2, 0, WHITE);
}

void frmDMQ(void) {
    if (f_index == 0) { //只更新一次
        f_index = 1;
        DMQFrame();
    } else if (f_index == 1) {
        f_index = 1;
        DMQUpdate();
    } else {
        f_index = 0;
    }
    if (key_AV) {
        frmID = 1;
        f_index = 0;
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
void DCDCFrame(void) {
    unsigned char i = 0;
    LCD_Clear();
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //顶部横线
    LCD_DrawImage1BPP(130 + 200, 130 - 85, BMP_DCDC, WHITE, BLACK); //DCDC
    LCD_DrawImage1BPP(130 + 200 + 65, 130 - 85, BMP_STSTEM, WHITE, BLACK); //系统
    LCD_DrawImage1BPP(130 + 200 + 65 + 50, 130 - 85, BMP_Message, WHITE, BLACK); //信息

    LCD_DrawRect(80, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320 + 320, 90, 1, 380, GREEN);
    for (i = 0; i < 11; i++)
        LCD_DrawRect(80, 90 + i * 38, 640, 1, GREEN);

    LCD_DrawImage1BPP(82, 100 - 2, BMP_DCDC, WHITE, BLACK); //DCDC
    LCD_DrawImage1BPP(82 + 65, 100 + 2, BMP_Output, WHITE, BLACK); //输出
    LCD_DrawImage1BPP(82 + 65 + 42, 100 + 2, BMP_DY, WHITE, BLACK); //电压
    LCD_DrawImage1BPP(400 - 24, 100 - 2, BMP_v, WHITE, BLACK); //V

    LCD_DrawImage1BPP(82, 100 - 2 + 38, BMP_DCDC, WHITE, BLACK); //DCDC
    LCD_DrawImage1BPP(82 + 65, 100 + 2 + 38, BMP_Output, WHITE, BLACK); //输出
    LCD_DrawImage1BPP(82 + 65 + 42, 100 + 2 + 38, BMP_DL, WHITE, BLACK); //电流
    LCD_DrawImage1BPP(400 - 24, 100 - 2 + 38, BMP_a, WHITE, BLACK); //A

    LCD_DrawImage1BPP(82, 100 - 2 + 38 * 2, BMP_DCDC, WHITE, BLACK); //DCDC
    LCD_DrawImage1BPP(82 + 65, 100 + 2 + 38 * 2, BMP_Mokuai, WHITE, BLACK); //模块
    LCD_DrawImage1BPP(82 + 65 + 42, 100 + 2 + 38 * 2, BMP_Wendu, WHITE, BLACK); //温度
    LCD_DrawImage1BPP(400 - 28, 100 - 2 + 38 * 2, BMP_T, WHITE, BLACK); //℃

    LCD_DrawImage1BPP(82, 100 - 2 + 38 * 3, BMP_DCDC, WHITE, BLACK); //DCDC
    LCD_DrawImage1BPP(82 + 65, 100 + 38 * 3, BMP_Guzhang, WHITE, BLACK); //故障
    LCD_DrawImage1BPP(82 + 65 + 42, 100 + 3 * 38, BMP_Code, WHITE, BLACK); //代码

    LCD_DrawImage1BPP(82 + 320, 100 - 2 + 38 * 3, BMP_DCDC, WHITE, BLACK); //DCDC
    LCD_DrawImage1BPP(82 + 65 + 320, 100 + 2 + 38 * 3, BMP_Output, WHITE, BLACK); //输出
    LCD_DrawImage1BPP(82 + 65 + 42 + 320, 100 + 2 + 38 * 3, BMP_Qieduan, WHITE, BLACK); //切断

    LCD_DrawImage1BPP(82 + 320, 100 - 2, BMP_DCDC, WHITE, BLACK); //DCDC
    LCD_DrawImage1BPP(82 + 320 + 65, 100 + 2, BMP_Gongzuo, WHITE, BLACK); //工作
    LCD_DrawImage1BPP(82 + 320 + 65 + 42, 100 + 2, BMP_Zhuangtai, WHITE, BLACK); //状态

    LCD_DrawImage1BPP(82 + 320, 100 - 2 + 38, BMP_DCDC, WHITE, BLACK); //DCDC
    LCD_DrawImage1BPP(82 + 320 + 65, 100 + 2 + 38, BMP_Guzhang, WHITE, BLACK); //故障
    LCD_DrawImage1BPP(82 + 320 + 65 + 42, 100 + 2 + 38, BMP_Dengji, WHITE, BLACK); //等级

    LCD_DrawImage1BPP(82 + 320, 100 - 2 + 38 * 2, BMP_DCDC, WHITE, BLACK); //DCDC
    LCD_DrawImage1BPP(82 + 320 + 65, 100 + 2 + 38 * 2, BMP_Input, WHITE, BLACK); //输入
    LCD_DrawImage1BPP(82 + 320 + 65 + 42, 100 + 2 + 38 * 2, BMP_Qieduan, WHITE, BLACK); //切断

    LCD_DrawImage1BPP(82 + 320, 100 - 2 + 38 * 4, BMP_DCDC, WHITE, BLACK); //DCDC温度报警
    LCD_DrawImage1BPP(82 + 320 + 65, 100 - 2 + 38 * 4, BMP_Wendu, WHITE, BLACK);
    LCD_DrawImage1BPP(82 + 320 + 65 + 42, 100 - 2 + 38 * 4, BMP_Baojing, WHITE, BLACK);

    LCD_DrawImage1BPP(82 + 320, 100 - 2 + 38 * 5, BMP_DCDC, WHITE, BLACK); //DCDC温度报警
    LCD_DrawImage1BPP(82 + 320 + 65, 100 - 2 + 38 * 5, BMP_Guzhang, WHITE, BLACK);
    LCD_DrawImage1BPP(82 + 320 + 65 + 42, 100 - 2 + 38 * 5, BMP_Zhuangtai, WHITE, BLACK);
}

void DCDCUpdate(void) {
    print_SZ_1(82 + 200 + 20 - 16, 100 - 8, DCDC_Voltage * 0.1, 4, 0, WHITE);
    print_SZ_1(82 + 200 + 20 - 16, 100 - 8 + 38, DCDC_Current * 0.1, 4, 0, WHITE);
    updata_DAT(82 + 200 + 20, 100 - 8 + 38 * 2, DCDC_Temp, 1, 40, WHITE, 3, 0);
    print_SZ_1(82 + 200 + 20 - 16, 100 - 8 + 38 * 3, DCDC_Fault_Code, 4, 0, WHITE);

    print_SZ_1(82 + 200 + 300 + 16, 100 - 8, DCDC_Status, 2, 0, WHITE);
    print_SZ_1(82 + 200 + 300 + 16, 100 - 8 + 38, DCDC_Level_Fault, 2, 0, WHITE);
    print_SZ_1(82 + 200 + 300 + 16, 100 - 8 + 38 * 2, DCDC_intput_Cut, 2, 0, WHITE);
    print_SZ_1(82 + 200 + 300 + 16, 100 - 8 + 38 * 3, DCDC_Output_Cut, 2, 0, WHITE);
    print_SZ_1(82 + 200 + 300 + 16, 100 - 8 + 38 * 4, DCDC_Temp_Warn, 2, 0, WHITE);
    print_SZ_1(82 + 200 + 300 + 16, 100 - 8 + 38 * 5, DCDC_Fault_Warn, 2, 0, WHITE);
}

void frmDCDC(void) {
    if (f_index == 0) { //只更新一次
        f_index = 1;
        DCDCFrame();
    } else if (f_index == 1) {
        f_index = 1;
        DCDCUpdate();
    } else {
        f_index = 0;
    }
    if (key_AV) {
        key_AV = 0;
        frmID = 1;
        f_index = 0;
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
void DMYFrame(void) {
    unsigned char i = 0;
    LCD_Clear();
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //顶部横线
    LCD_DrawImageSBPP(130 + 200, 130 - 85, 50, OIL_SYSTEM, WHITE, BLACK); //油泵

    LCD_DrawRect(80, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320 + 320, 90, 1, 380, GREEN);
    for (i = 0; i < 11; i++)
        LCD_DrawRect(80, 90 + i * 38, 640, 1, GREEN);

    LCD_DrawImage1BPP(82, 100 - 2, BMP_DCAC, WHITE, BLACK); //DCAC
    LCD_DrawImage1BPP(82 + 52 + 11, 100, BMP_w, WHITE, BLACK); //  W
    LCD_DrawImage1BPP(82 + 52 + 11 + 11, 100, BMP_Xiang, WHITE, BLACK); //相
    LCD_DrawImage1BPP(82 + 52 + 11 + 11 + 21, 100, BMP_Output, WHITE, BLACK); //输出
    LCD_DrawImage1BPP(82 + 52 + 11 + 11 + 21 + 42, 100, BMP_DL, WHITE, BLACK); //电流
    LCD_DrawImage1BPP(400 - 24, 100, BMP_a, WHITE, BLACK); //A

    LCD_DrawImage1BPP(82, 100 - 2 + 38, BMP_DCAC, WHITE, BLACK); //DCAC
    LCD_DrawImage1BPP(82 + 52 + 11, 100 + 38, BMP_w, WHITE, BLACK); //  W
    LCD_DrawImage1BPP(82 + 52 + 11 + 11, 100 + 38, BMP_Xiang, WHITE, BLACK); //相
    LCD_DrawImage1BPP(82 + 52 + 11 + 11 + 21, 100 + 38, BMP_Output, WHITE, BLACK); //输出
    LCD_DrawImage1BPP(82 + 52 + 11 + 11 + 21 + 42, 100 + 38, BMP_DY, WHITE, BLACK); //电压
    LCD_DrawImage1BPP(400 - 24, 100 + 38, BMP_v, WHITE, BLACK); //V

    LCD_DrawImage1BPP(82, 100 - 2 + 38 * 2, BMP_DCAC, WHITE, BLACK); //DCAC
    LCD_DrawImage1BPP(82 + 52 + 11, 100 + 38 * 2, BMP_v, WHITE, BLACK); //  V
    LCD_DrawImage1BPP(82 + 52 + 11 + 11, 100 + 38 * 2, BMP_Xiang, WHITE, BLACK); //相
    LCD_DrawImage1BPP(82 + 52 + 11 + 11 + 21, 100 + 38 * 2, BMP_Output, WHITE, BLACK); //输出
    LCD_DrawImage1BPP(82 + 52 + 11 + 11 + 21 + 42, 100 + 38 * 2, BMP_DL, WHITE, BLACK); //电流
    LCD_DrawImage1BPP(400 - 24, 100 + 38 * 2, BMP_a, WHITE, BLACK); //A

    LCD_DrawImage1BPP(82, 100 - 2 + 38 * 3, BMP_DCAC, WHITE, BLACK); //DCAC
    LCD_DrawImage1BPP(82 + 52 + 11, 100 + 38 * 3, BMP_v, WHITE, BLACK); //  V
    LCD_DrawImage1BPP(82 + 52 + 11 + 11, 100 + 38 * 3, BMP_Xiang, WHITE, BLACK); //相
    LCD_DrawImage1BPP(82 + 52 + 11 + 11 + 21, 100 + 38 * 3, BMP_Output, WHITE, BLACK); //输出
    LCD_DrawImage1BPP(82 + 52 + 11 + 11 + 21 + 42, 100 + 38 * 3, BMP_DY, WHITE, BLACK); //电压
    LCD_DrawImage1BPP(400 - 24, 100 + 38 * 3, BMP_v, WHITE, BLACK); //V

    LCD_DrawImage1BPP(82, 100 - 2 + 38 * 4, BMP_DCAC, WHITE, BLACK); //DCAC
    LCD_DrawImage1BPP(82 + 52 + 11, 100 + 38 * 4, BMP_u, WHITE, BLACK); //  U
    LCD_DrawImage1BPP(82 + 52 + 11 + 11, 100 + 38 * 4, BMP_Xiang, WHITE, BLACK); //相
    LCD_DrawImage1BPP(82 + 52 + 11 + 11 + 21, 100 + 38 * 4, BMP_Output, WHITE, BLACK); //输出
    LCD_DrawImage1BPP(82 + 52 + 11 + 11 + 21 + 42, 100 + 38 * 4, BMP_DL, WHITE, BLACK); //电流
    LCD_DrawImage1BPP(400 - 24, 100 + 38 * 4, BMP_a, WHITE, BLACK); //A

    LCD_DrawImage1BPP(82, 100 - 2 + 38 * 5, BMP_DCAC, WHITE, BLACK); //DCAC
    LCD_DrawImage1BPP(82 + 52 + 11, 100 + 38 * 5, BMP_u, WHITE, BLACK); //  U
    LCD_DrawImage1BPP(82 + 52 + 11 + 11, 100 + 38 * 5, BMP_Xiang, WHITE, BLACK); //相
    LCD_DrawImage1BPP(82 + 52 + 11 + 11 + 21, 100 + 38 * 5, BMP_Output, WHITE, BLACK); //输出
    LCD_DrawImage1BPP(82 + 52 + 11 + 11 + 21 + 42, 100 + 38 * 5, BMP_DY, WHITE, BLACK); //电压
    LCD_DrawImage1BPP(400 - 24, 100 + 38 * 5, BMP_v, WHITE, BLACK); //V

    LCD_DrawImage1BPP(82 + 320, 100, BMP_KZQ, WHITE, BLACK); //控制器
    LCD_DrawImage1BPP(82 + 320 + 63, 100, BMP_Wendu, WHITE, BLACK); //温度
    LCD_DrawImage1BPP(720 - 24, 100, BMP_T, WHITE, BLACK); //℃

    LCD_DrawImage1BPP(82 + 320, 100 + 38, BMP_Guzhang, WHITE, BLACK); //故障
    LCD_DrawImage1BPP(82 + 42 + 320, 100 + 38, BMP_Code, WHITE, BLACK); //代码

    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 2, BMP_Guzhang, WHITE, BLACK); //故障
    LCD_DrawImage1BPP(82 + 42 + 320, 100 + 38 * 2, BMP_Dengji, WHITE, BLACK); //等级

    LCD_DrawImage1BPP(82 + 320, 100 - 2 + 38 * 3, BMP_DCAC, WHITE, BLACK); //DCAC
    LCD_DrawImage1BPP(82 + 320 + 52, 100 + 2 + 38 * 3, BMP_Input, WHITE, BLACK); //输入
    LCD_DrawImage1BPP(82 + 320 + 52 + 42, 100 + 2 + 38 * 3, BMP_Qieduan, WHITE, BLACK); //切断

    LCD_DrawImage1BPP(82 + 320, 100 - 2 + 38 * 4, BMP_DCAC, WHITE, BLACK); //DCAC
    LCD_DrawImage1BPP(82 + 320 + 52, 100 + 2 + 38 * 4, BMP_Output, WHITE, BLACK); //输出
    LCD_DrawImage1BPP(82 + 320 + 52 + 42, 100 + 2 + 38 * 4, BMP_Qieduan, WHITE, BLACK); //切断

    LCD_DrawImage1BPP(82 + 320, 100 - 2 + 38 * 5, BMP_DCAC, WHITE, BLACK); //DCAC
    LCD_DrawImage1BPP(82 + 320 + 52, 100 + 2 + 38 * 5, BMP_Gongzuo, WHITE, BLACK); //工作
    LCD_DrawImage1BPP(82 + 320 + 52 + 42, 100 + 2 + 38 * 5, BMP_Zhuangtai, WHITE, BLACK); //状态

    LCD_DrawImage1BPP(82 + 320, 100 - 2 + 38 * 6, BMP_DCAC, WHITE, BLACK); //DCAC温度报警
    LCD_DrawImage1BPP(82 + 320 + 52, 100 - 2 + 38 * 6, BMP_Wendu, WHITE, BLACK);
    LCD_DrawImage1BPP(82 + 320 + 52 + 42, 100 - 2 + 38 * 6, BMP_Baojing, WHITE, BLACK);

    LCD_DrawImage1BPP(82 + 320, 100 - 2 + 38 * 7, BMP_DCAC, WHITE, BLACK); //DCAC温度报警
    LCD_DrawImage1BPP(82 + 320 + 52, 100 - 2 + 38 * 7, BMP_Guzhang, WHITE, BLACK);
    LCD_DrawImage1BPP(82 + 320 + 52 + 42, 100 - 2 + 38 * 7, BMP_Zhuangtai, WHITE, BLACK);

}

void DMYUpdate(void) {
    print_SZ_1(82 + 200 + 20 - 16, 100 - 8, OILDCAC_W_Current * 0.1, 4, 0, WHITE);
    print_SZ_1(82 + 200 + 20 - 16, 100 - 8 + 38, OILDCAC_W_Voltage * 0.1, 4, 0, WHITE);
    print_SZ_1(82 + 200 + 20 - 16, 100 - 8 + 38 * 2, OILDCAC_V_Current * 0.1, 4, 0, WHITE);
    print_SZ_1(82 + 200 + 20 - 16, 100 - 8 + 38 * 3, OILDCAC_V_Voltage * 0.1, 4, 0, WHITE);
    print_SZ_1(82 + 200 + 20 - 16, 100 - 8 + 38 * 4, OILDCAC_U_Current * 0.1, 4, 0, WHITE);
    print_SZ_1(82 + 200 + 20 - 16, 100 - 8 + 38 * 5, OILDCAC_U_Voltage * 0.1, 4, 0, WHITE);

    updata_DAT(82 + 200 + 300, 100 - 8, OILDCAC_Temp, 1, 40, WHITE, 3, 0);
    print_SZ_1(82 + 200 + 300 + 16, 100 - 8 + 38, OILDCAC_Fault_Code, 2, 0, WHITE);
    print_SZ_1(82 + 200 + 300 + 16, 100 - 8 + 38 * 2, OILDCAC_Level_Fault, 2, 0, WHITE);
    print_SZ_1(82 + 200 + 300 + 16, 100 - 8 + 38 * 3, OILDCAC_intput_Cut, 2, 0, WHITE);
    print_SZ_1(82 + 200 + 300 + 16, 100 - 8 + 38 * 4, OILDCAC_Output_Cut, 2, 0, WHITE);
    print_SZ_1(82 + 200 + 300 + 16, 100 - 8 + 38 * 5, OILDCAC_Status, 2, 0, WHITE);
    print_SZ_1(82 + 200 + 300 + 16, 100 - 8 + 38 * 6, OILDCAC_Temp_Warn, 2, 0, WHITE);
    print_SZ_1(82 + 200 + 300 + 16, 100 - 8 + 38 * 7, OILDCAC_Fault_Warn, 2, 0, WHITE);
}

void frmDMY(void) {
    if (f_index == 0) { //只更新一次
        f_index = 1;
        DMYFrame();
    } else if (f_index == 1) {
        f_index = 1;
        DMYUpdate();
    } else {
        f_index = 0;
    }
    if (key_AV) {
        key_AV = 0;
        frmID = 1;
        f_index = 0;
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
void BMSFrame(unsigned char index) {
    unsigned char i = 0;
    LCD_Clear();
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //顶部横线
    LCD_DrawImageSBPP(130 + 200 - 24, 130 - 85, 50, BMS_SYSTEM, WHITE, BLACK); //电池

    if (index == 1) {
        print_SZ_2(750, 50, 1, 1, 0, WHITE); // 1/2
        LCD_DrawImage1BPP(750 + 11, 50, BMP_I, WHITE, BLACK);
        print_SZ_2(750 + 11 + 14, 50, 2, 1, 0, WHITE);
        LCD_DrawRect(80, 90, 1, 380, GREEN);
        LCD_DrawRect(80 + 320, 90, 1, 380, GREEN);
        LCD_DrawRect(80 + 320 + 320 + 70, 90, 1, 380, GREEN);
        for (i = 0; i < 11; i++)
            LCD_DrawRect(80, 90 + i * 38, 710, 1, GREEN);

        LCD_DrawImage1BPP(82, 100, BMP_DC, WHITE, BLACK); //电池
        LCD_DrawImage1BPP(82 + 42, 100, BMP_Zong, WHITE, BLACK); //总
        LCD_DrawImage1BPP(82 + 42 + 21, 100, BMP_DY, WHITE, BLACK); //电压
        LCD_DrawImage1BPP(82 + 42 + 21 + 42 + 2, 100 + 5, BMP_Maohao, WHITE, BLACK); //:
        LCD_DrawImage1BPP(400 - 24, 100, BMP_v, WHITE, BLACK); //V

        LCD_DrawImage1BPP(82, 100 + 38, BMP_DC, WHITE, BLACK); //电池
        LCD_DrawImage1BPP(82 + 42, 100 + 38, BMP_Zong, WHITE, BLACK); //总
        LCD_DrawImage1BPP(82 + 42 + 21, 100 + 38, BMP_DL, WHITE, BLACK); //电流
        LCD_DrawImage1BPP(400 - 24, 100 + 38, BMP_a, WHITE, BLACK); //A

        LCD_DrawImage1BPP(82, 100 + 38 * 2, BMP_s, WHITE, BLACK); //S
        LCD_DrawImage1BPP(82 + 11, 100 + 38 * 2, BMP_o, WHITE, BLACK); //O
        LCD_DrawImage1BPP(82 + 11 + 11, 100 + 38 * 2, BMP_c, WHITE, BLACK); //C
        LCD_DrawImage1BPP(400 - 24, 100 + 38 * 2, BMP_Baifenhao, WHITE, BLACK); //%

        LCD_DrawImage1BPP(82, 100 + 38 * 3, BMP_DC, WHITE, BLACK); //电池充放电模式
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 3, BMP_Chong, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 42 + 21, 100 + 38 * 3, BMP_Fang, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 3, BMP_DC, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 42 + 21 + 42, 100 + 38 * 3, BMP_Mode, WHITE, BLACK);

        LCD_DrawImage1BPP(82, 100 + 38 * 4, BMP_Gao, WHITE, BLACK); //高压继电器状态
        LCD_DrawImage1BPP(82 + 21, 100 + 38 * 4, BMP_Yali, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 4, BMP_Jidianqi, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 42 + 63, 100 + 38 * 4, BMP_Zhuangtai, WHITE, BLACK);

        LCD_DrawImage1BPP(82, 100 + 38 * 5, BMP_Guzhang, WHITE, BLACK); //故障
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 5, BMP_Zhuangtai, WHITE, BLACK); //状态

        LCD_DrawImage1BPP(82, 100 + 38 * 6, BMP_Dan, WHITE, BLACK); //单
        LCD_DrawImage1BPP(82 + 21, 100 + 38 * 6, BMP_Ti, WHITE, BLACK); //体
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 6, BMP_DY, WHITE, BLACK); //电压
        LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 6, BMP_Shuliang, WHITE, BLACK); //数量

        LCD_DrawImage1BPP(82, 100 + 38 * 7, BMP_Dan, WHITE, BLACK); //单
        LCD_DrawImage1BPP(82 + 21, 100 + 38 * 7, BMP_Ti, WHITE, BLACK); //体
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 7, BMP_Wendu, WHITE, BLACK); //温度
        LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 7, BMP_Shuliang, WHITE, BLACK); //数量

        LCD_DrawImage1BPP(82, 100 + 38 * 8, BMP_System, WHITE, BLACK); //系统
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 8, BMP_Shuliang, WHITE, BLACK); //数量

        LCD_DrawImage1BPP(82, 100 + 38 * 9, BMP_System, WHITE, BLACK); //系统
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 9, BMP_Hao, WHITE, BLACK); //号


        for (i = 0; i < 4; i++) {
            LCD_DrawImage1BPP(82 + 320, 100 + 38 * i, BMP_Zui, WHITE, BLACK); //最
            if (i % 2 == 0)
                LCD_DrawImage1BPP(82 + 320 + 21, 100 + 38 * i, BMP_Gao, WHITE, BLACK); // 高
            else LCD_DrawImage1BPP(82 + 320 + 21, 100 + 38 * i, BMP_Di, WHITE, BLACK); // 低 
            LCD_DrawImage1BPP(82 + 320 + 21 + 21, 100 + 38 * i, BMP_Dan, WHITE, BLACK); //单
            LCD_DrawImage1BPP(82 + 320 + 21 + 21 + 21, 100 + 38 * i, BMP_Ti, WHITE, BLACK); //体
            if (i < 2) {
                LCD_DrawImage1BPP(82 + 320 + 21 + 21 + 21 + 21, 100 + 38 * i, BMP_DY, WHITE, BLACK); //电压
                LCD_DrawImage1BPP(720 - 24 - 63 - 5, 100 + 38 * i, BMP_v, WHITE, BLACK); //V
            } else {
                LCD_DrawImage1BPP(82 + 320 + 21 + 21 + 21 + 21, 100 + 38 * i, BMP_Wendu, WHITE, BLACK); //温度
                LCD_DrawImage1BPP(720 - 28 - 63 - 5, 100 + 38 * i, BMP_T, WHITE, BLACK); //℃
            }
            LCD_DrawImage1BPP(82 + 320 + 42 * 7 - 5, 100 + 38 * i, BMP_Xiang_BMS, WHITE, BLACK); //箱

            LCD_DrawImage1BPP(82 + 320 + 42 * 8.5 + 5, 100 + 38 * i, BMP_Hao, WHITE, BLACK); //号
        }

        LCD_DrawImage1BPP(82 + 320, 100 + 38 * 4, BMP_Dan, WHITE, BLACK); //单
        LCD_DrawImage1BPP(82 + 320 + 21, 100 + 38 * 4, BMP_Ti, WHITE, BLACK); //体
        LCD_DrawImage1BPP(82 + 320 + 21 + 21, 100 + 38 * 4, BMP_Pingjun, WHITE, BLACK); //平均
        LCD_DrawImage1BPP(82 + 320 + 21 + 21 + 42, 100 + 38 * 4, BMP_Wendu, WHITE, BLACK); //温度
        LCD_DrawImage1BPP(720 - 28, 100 + 38 * 4, BMP_T, WHITE, BLACK); //℃    

        LCD_DrawImage1BPP(82 + 320, 100 + 38 * 5, BMP_Jueyuan, WHITE, BLACK); //绝缘
        LCD_DrawImage1BPP(82 + 42 + 320, 100 + 38 * 5, BMP_DC, WHITE, BLACK); //电池
        LCD_DrawImage1BPP(82 + 42 + 21 + 320, 100 + 38 * 5, BMP_Zu, WHITE, BLACK); //阻
        LCD_DrawImage1BPP(720 - 28, 100 + 38 * 5, BMP_k, WHITE, BLACK); //K
        LCD_DrawImage1BPP(720 - 16, 100 + 2 + 38 * 5, BMP_Omu, WHITE, BLACK); //Ω

    } else if (index == 2) {
        print_SZ_2(750, 50, 2, 1, 0, WHITE); // 1/2
        LCD_DrawImage1BPP(750 + 11, 50, BMP_I, WHITE, BLACK);
        print_SZ_2(750 + 11 + 14, 50, 2, 1, 0, WHITE);
        LCD_DrawRect(80, 90, 1, 380, GREEN);
        LCD_DrawRect(80 + 320, 90, 1, 380, GREEN);
        LCD_DrawRect(80 + 320 + 320, 90, 1, 380, GREEN);
        for (i = 0; i < 11; i++)
            LCD_DrawRect(80, 90 + i * 38, 640, 1, GREEN);
        LCD_DrawImage1BPP(82, 100, BMP_Zui, WHITE, BLACK); //最
        LCD_DrawImage1BPP(82 + 21, 100, BMP_Gao, WHITE, BLACK); //高
        LCD_DrawImage1BPP(82 + 42, 100, BMP_Yunxu, WHITE, BLACK); //允许
        LCD_DrawImage1BPP(82 + 42 + 42, 100, BMP_Dan, WHITE, BLACK); //单
        LCD_DrawImage1BPP(82 + 42 + 42 + 21, 100, BMP_Ti, WHITE, BLACK); //体
        LCD_DrawImage1BPP(82 + 42 + 42 + 42, 100, BMP_Wendu, WHITE, BLACK); //温度
        LCD_DrawImage1BPP(400 - 24, 100, BMP_T, WHITE, BLACK); //℃

        LCD_DrawImage1BPP(82, 100 + 38, BMP_Zui, WHITE, BLACK); //最
        LCD_DrawImage1BPP(82 + 21, 100 + 38, BMP_Di, WHITE, BLACK); //低
        LCD_DrawImage1BPP(82 + 42, 100 + 38, BMP_Yunxu, WHITE, BLACK); //允许
        LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38, BMP_Dan, WHITE, BLACK); //单
        LCD_DrawImage1BPP(82 + 42 + 42 + 21, 100 + 38, BMP_Ti, WHITE, BLACK); //体
        LCD_DrawImage1BPP(82 + 42 + 42 + 42, 100 + 38, BMP_Wendu, WHITE, BLACK); //温度
        LCD_DrawImage1BPP(400 - 24, 100 + 38, BMP_T, WHITE, BLACK); //℃ 

        LCD_DrawImage1BPP(82, 100 + 38 * 2, BMP_Zui, WHITE, BLACK); //最
        LCD_DrawImage1BPP(82 + 21, 100 + 38 * 2, BMP_Di, WHITE, BLACK); //低
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 2, BMP_Yunxu, WHITE, BLACK); //允许
        LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 2, BMP_s, WHITE, BLACK); //S
        LCD_DrawImage1BPP(82 + 42 + 42 + 11, 100 + 38 * 2, BMP_o, WHITE, BLACK); //O
        LCD_DrawImage1BPP(82 + 42 + 42 + 11 + 11, 100 + 38 * 2, BMP_c, WHITE, BLACK); //C
        LCD_DrawImage1BPP(400 - 24, 100 + 38 * 2, BMP_Baifenhao, WHITE, BLACK); //%

        LCD_DrawImage1BPP(82, 100 + 38 * 3, BMP_Zui, WHITE, BLACK); //最
        LCD_DrawImage1BPP(82 + 21, 100 + 38 * 3, BMP_Gao, WHITE, BLACK); //高
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 3, BMP_Yunxu, WHITE, BLACK); //允许
        LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 3, BMP_Fang, WHITE, BLACK); //放
        LCD_DrawImage1BPP(82 + 42 + 42 + 21, 100 + 38 * 3, BMP_DY, WHITE, BLACK); //电
        LCD_DrawImage1BPP(82 + 42 + 42 + 42, 100 + 38 * 3, BMP_DL, WHITE, BLACK); //电流
        LCD_DrawImage1BPP(400 - 24, 100 + 38 * 3, BMP_a, WHITE, BLACK); //A

        LCD_DrawImage1BPP(82, 100 + 38 * 4, BMP_Zui, WHITE, BLACK); //最
        LCD_DrawImage1BPP(82 + 21, 100 + 38 * 4, BMP_Gao, WHITE, BLACK); //高
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 4, BMP_Yunxu, WHITE, BLACK); //允许
        LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 4, BMP_Fankui, WHITE, BLACK); //反馈
        LCD_DrawImage1BPP(82 + 42 + 42 + 42, 100 + 38 * 4, BMP_DL, WHITE, BLACK); //电流
        LCD_DrawImage1BPP(400 - 24, 100 + 38 * 4, BMP_a, WHITE, BLACK); //A

        /*LCD_DrawImage1BPP(82, 100, BMP_DC, WHITE, BLACK); //电池
        LCD_DrawImage1BPP(82 + 42, 100, BMP_System, WHITE, BLACK); //系统
        LCD_DrawImage1BPP(82 + 42 + 42, 100, BMP_Zui, WHITE, BLACK); //最
        LCD_DrawImage1BPP(82 + 42 + 42 + 21, 100, BMP_Gao, WHITE, BLACK); //高
        LCD_DrawImage1BPP(82 + 42 + 42 + 42, 100, BMP_Yunxu, WHITE, BLACK); //允许
        LCD_DrawImage1BPP(82 + 42 + 42 + 42 + 42, 100, BMP_DY, WHITE, BLACK); //电压
        LCD_DrawImage1BPP(400 - 24, 100, BMP_v, WHITE, BLACK); //V

        LCD_DrawImage1BPP(82, 100 + 38, BMP_DC, WHITE, BLACK); //电池
        LCD_DrawImage1BPP(82 + 42, 100 + 38, BMP_System, WHITE, BLACK); //系统
        LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38, BMP_Zui, WHITE, BLACK); //最
        LCD_DrawImage1BPP(82 + 42 + 42 + 21, 100 + 38, BMP_Di, WHITE, BLACK); //低
        LCD_DrawImage1BPP(82 + 42 + 42 + 42, 100 + 38, BMP_Yunxu, WHITE, BLACK); //允许
        LCD_DrawImage1BPP(82 + 42 + 42 + 42 + 42, 100 + 38, BMP_DY, WHITE, BLACK); //电压
        LCD_DrawImage1BPP(400 - 24, 100 + 38, BMP_v, WHITE, BLACK); //V

        LCD_DrawImage1BPP(82, 100 + 38 * 2, BMP_Dan, WHITE, BLACK); //单
        LCD_DrawImage1BPP(82 + 21, 100 + 38 * 2, BMP_Ti, WHITE, BLACK); //体
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 2, BMP_Zui, WHITE, BLACK); //最
        LCD_DrawImage1BPP(82 + 42 + 21, 100 + 38 * 2, BMP_Gao, WHITE, BLACK); //高
        LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 2, BMP_Yunxu, WHITE, BLACK); //允许
        LCD_DrawImage1BPP(82 + 42 + 42 + 42, 100 + 38 * 2, BMP_DY, WHITE, BLACK); //电压
        LCD_DrawImage1BPP(400 - 24, 100 + 38 * 2, BMP_v, WHITE, BLACK); //V

        LCD_DrawImage1BPP(82, 100 + 38 * 3, BMP_Dan, WHITE, BLACK); //单
        LCD_DrawImage1BPP(82 + 21, 100 + 38 * 3, BMP_Ti, WHITE, BLACK); //体
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 3, BMP_Zui, WHITE, BLACK); //最
        LCD_DrawImage1BPP(82 + 42 + 21, 100 + 38 * 3, BMP_Di, WHITE, BLACK); //低
        LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 3, BMP_Yunxu, WHITE, BLACK); //允许
        LCD_DrawImage1BPP(82 + 42 + 42 + 42, 100 + 38 * 3, BMP_DY, WHITE, BLACK); //电压
        LCD_DrawImage1BPP(400 - 24, 100 + 38 * 3, BMP_v, WHITE, BLACK); //V

        LCD_DrawImage1BPP(82, 100 + 38 * 4, BMP_Zui, WHITE, BLACK); //最
        LCD_DrawImage1BPP(82 + 21, 100 + 38 * 4, BMP_Gao, WHITE, BLACK); //高
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 4, BMP_Yunxu, WHITE, BLACK); //允许
        LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 4, BMP_Chong, WHITE, BLACK); //充
        LCD_DrawImage1BPP(82 + 42 + 42 + 21, 100 + 38 * 4, BMP_DY, WHITE, BLACK); //电
        LCD_DrawImage1BPP(82 + 42 + 42 + 42, 100 + 38 * 4, BMP_DL, WHITE, BLACK); //电流
        LCD_DrawImage1BPP(400 - 24, 100 + 38 * 4, BMP_a, WHITE, BLACK); //A

        LCD_DrawImage1BPP(82, 100 + 38 * 5, BMP_Zui, WHITE, BLACK); //最
        LCD_DrawImage1BPP(82 + 21, 100 + 38 * 5, BMP_Gao, WHITE, BLACK); //高
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 5, BMP_Yunxu, WHITE, BLACK); //允许
        LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 5, BMP_Fang, WHITE, BLACK); //放
        LCD_DrawImage1BPP(82 + 42 + 42 + 21, 100 + 38 * 5, BMP_DY, WHITE, BLACK); //电
        LCD_DrawImage1BPP(82 + 42 + 42 + 42, 100 + 38 * 5, BMP_DL, WHITE, BLACK); //电流
        LCD_DrawImage1BPP(400 - 24, 100 + 38 * 5, BMP_a, WHITE, BLACK); //A

        LCD_DrawImage1BPP(82, 100 + 38 * 6, BMP_Zui, WHITE, BLACK); //最
        LCD_DrawImage1BPP(82 + 21, 100 + 38 * 6, BMP_Gao, WHITE, BLACK); //高
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 6, BMP_Yunxu, WHITE, BLACK); //允许
        LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 6, BMP_s, WHITE, BLACK); //S
        LCD_DrawImage1BPP(82 + 42 + 42 + 11, 100 + 38 * 6, BMP_o, WHITE, BLACK); //O
        LCD_DrawImage1BPP(82 + 42 + 42 + 11 + 11, 100 + 38 * 6, BMP_c, WHITE, BLACK); //C
        LCD_DrawImage1BPP(400 - 24, 100 + 38 * 6, BMP_Baifenhao, WHITE, BLACK); //%

        LCD_DrawImage1BPP(82, 100 + 38 * 7, BMP_Zui, WHITE, BLACK); //最
        LCD_DrawImage1BPP(82 + 21, 100 + 38 * 7, BMP_Di, WHITE, BLACK); //低
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 7, BMP_Yunxu, WHITE, BLACK); //允许
        LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 7, BMP_s, WHITE, BLACK); //S
        LCD_DrawImage1BPP(82 + 42 + 42 + 11, 100 + 38 * 7, BMP_o, WHITE, BLACK); //O
        LCD_DrawImage1BPP(82 + 42 + 42 + 11 + 11, 100 + 38 * 7, BMP_c, WHITE, BLACK); //C
        LCD_DrawImage1BPP(400 - 24, 100 + 38 * 7, BMP_Baifenhao, WHITE, BLACK); //%

        LCD_DrawImage1BPP(82, 100 + 38 * 8, BMP_Zui, WHITE, BLACK); //最
        LCD_DrawImage1BPP(82 + 21, 100 + 38 * 8, BMP_Gao, WHITE, BLACK); //高
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 8, BMP_Yunxu, WHITE, BLACK); //允许
        LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 8, BMP_Fang, WHITE, BLACK); //放
        LCD_DrawImage1BPP(82 + 42 + 42 + 21, 100 + 38 * 8, BMP_DY, WHITE, BLACK); //电
        LCD_DrawImage1BPP(82 + 42 + 42 + 42, 100 + 38 * 8, BMP_Gonglv, WHITE, BLACK); //功率
        LCD_DrawImage1BPP(400 - 24 - 11, 100 + 38 * 8, BMP_k, WHITE, BLACK); //kw
        LCD_DrawImage1BPP(400 - 24, 100 + 38 * 8, BMP_w, WHITE, BLACK);

        LCD_DrawImage1BPP(82, 100 + 38 * 9, BMP_Zui, WHITE, BLACK); //最
        LCD_DrawImage1BPP(82 + 21, 100 + 38 * 9, BMP_Gao, WHITE, BLACK); //高
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 9, BMP_Yunxu, WHITE, BLACK); //允许
        LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 9, BMP_Chong, WHITE, BLACK); //充
        LCD_DrawImage1BPP(82 + 42 + 42 + 21, 100 + 38 * 9, BMP_DY, WHITE, BLACK); //电
        LCD_DrawImage1BPP(82 + 42 + 42 + 42, 100 + 38 * 9, BMP_Gonglv, WHITE, BLACK); //功率
        LCD_DrawImage1BPP(400 - 24 - 11, 100 + 38 * 9, BMP_k, WHITE, BLACK); //kw
        LCD_DrawImage1BPP(400 - 24, 100 + 38 * 9, BMP_w, WHITE, BLACK);

        LCD_DrawImage1BPP(82 + 320, 100, BMP_Zui, WHITE, BLACK); //最
        LCD_DrawImage1BPP(82 + 320 + 21, 100, BMP_Gao, WHITE, BLACK); //高
        LCD_DrawImage1BPP(82 + 320 + 42, 100, BMP_Yunxu, WHITE, BLACK); //允许
        LCD_DrawImage1BPP(82 + 320 + 42 + 42, 100, BMP_Dan, WHITE, BLACK); //单
        LCD_DrawImage1BPP(82 + 320 + 42 + 42 + 21, 100, BMP_Ti, WHITE, BLACK); //体
        LCD_DrawImage1BPP(82 + 320 + 42 + 42 + 42, 100, BMP_Wendu, WHITE, BLACK); //温度
        LCD_DrawImage1BPP(720 - 24, 100, BMP_T, WHITE, BLACK); //℃

        LCD_DrawImage1BPP(82 + 320, 100 + 38, BMP_Zui, WHITE, BLACK); //最
        LCD_DrawImage1BPP(82 + 320 + 21, 100 + 38, BMP_Di, WHITE, BLACK); //低
        LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38, BMP_Yunxu, WHITE, BLACK); //允许
        LCD_DrawImage1BPP(82 + 320 + 42 + 42, 100 + 38, BMP_Dan, WHITE, BLACK); //单
        LCD_DrawImage1BPP(82 + 320 + 42 + 42 + 21, 100 + 38, BMP_Ti, WHITE, BLACK); //体
        LCD_DrawImage1BPP(82 + 320 + 42 + 42 + 42, 100 + 38, BMP_Wendu, WHITE, BLACK); //温度
        LCD_DrawImage1BPP(720 - 24, 100 + 38, BMP_T, WHITE, BLACK); //℃       

        LCD_DrawImage1BPP(82 + 320, 100 + 38 * 2, BMP_DC, WHITE, BLACK); //电池
        LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 2, BMP_Zhuangtai, WHITE, BLACK); //状态

        LCD_DrawImage1BPP(82 + 320, 100 + 38 * 3, BMP_Guzhang, WHITE, BLACK); //故障
        LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 3, BMP_Zhuangtai, WHITE, BLACK); //状态

        LCD_DrawImage1BPP(82 + 320, 100 + 38 * 4, BMP_Junheng, WHITE, BLACK); //均衡
        LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 4, BMP_Suoding, WHITE, BLACK); //锁定
        LCD_DrawImage1BPP(82 + 320 + 42 + 42, 100 + 38 * 4, BMP_Zhuangtai, WHITE, BLACK); //状态

        LCD_DrawImage1BPP(82 + 320, 100 + 38 * 5, BMP_Guzhang, WHITE, BLACK); //故障
        LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 5, BMP_Suoding, WHITE, BLACK); //锁定
        LCD_DrawImage1BPP(82 + 320 + 42 + 42, 100 + 38 * 5, BMP_Zhuangtai, WHITE, BLACK); //状态
         */
        for (i = 0; i < 2; i++) {
            if (i == 0)
                LCD_DrawImage1BPP(82, 100 + 38 * (i + 5), BMP_Zheng, WHITE, BLACK); //正
            else LCD_DrawImage1BPP(82, 100 + 38 * (i + 5), BMP_Fu, WHITE, BLACK); //负
            LCD_DrawImage1BPP(82 + 21, 100 + 38 * (i + 5), BMP_Jueyuan, WHITE, BLACK); //绝缘
            LCD_DrawImage1BPP(82 + 42 + 21, 100 + 38 * (i + 5), BMP_DC, WHITE, BLACK); //电池
            LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * (i + 5), BMP_Zu, WHITE, BLACK); //阻
            LCD_DrawImage1BPP(82 + 42 + 42 + 21 + 2, 100 + 5 + 38 * (i + 5), BMP_Maohao, WHITE, BLACK); //:
            LCD_DrawImage1BPP(400 - 28, 100 + 38 * (i + 5), BMP_k, WHITE, BLACK); //K
            LCD_DrawImage1BPP(400 - 16, 100 + 2 + 38 * (i + 5), BMP_Omu, WHITE, BLACK); //Ω
        }

        LCD_DrawImage1BPP(82, 100 + 38 * 7, BMP_Jueyuan, WHITE, BLACK); //绝缘
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 7, BMP_Guzhang, WHITE, BLACK); //故障
        LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 7, BMP_Dengji, WHITE, BLACK); //等级

        LCD_DrawImage1BPP(82, 100 + 38 * 8, BMP_Jueyuan, WHITE, BLACK); //绝缘
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 8, BMP_Dengji, WHITE, BLACK); //等级

        LCD_DrawImage1BPP(82, 100 + 38 * 9, BMP_Jueyuan, WHITE, BLACK); //绝缘
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 9, BMP_Mokuai, WHITE, BLACK); //模块
        LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 9, BMP_Life, WHITE, BLACK); //LIFE


        LCD_DrawImage1BPP(82 + 320, 100, BMP_Zong, WHITE, BLACK); //总压故障状态
        LCD_DrawImage1BPP(82 + 320 + 21, 100, BMP_Yali, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 320 + 42, 100, BMP_Guzhang, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 320 + 42 + 42, 100, BMP_Zhuangtai, WHITE, BLACK); //

        LCD_DrawImage1BPP(82 + 320, 100 + 38, BMP_Dan, WHITE, BLACK); //单体电压故障状态
        LCD_DrawImage1BPP(82 + 320 + 21, 100 + 38, BMP_Ti, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38, BMP_DY, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 320 + 42 + 42, 100 + 38, BMP_Guzhang, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 320 + 42 + 42 + 42, 100 + 38, BMP_Zhuangtai, WHITE, BLACK); //

        LCD_DrawImage1BPP(82 + 320, 100 + 38 * 2, BMP_Wendu, WHITE, BLACK); //温度故障状态
        LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 2, BMP_Guzhang, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 320 + 42 + 42, 100 + 38 * 2, BMP_Zhuangtai, WHITE, BLACK); //

        LCD_DrawImage1BPP(82 + 320, 100 + 38 * 3, BMP_Jueyuan, WHITE, BLACK); //绝缘故障状态
        LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 3, BMP_Guzhang, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 320 + 42 + 42, 100 + 38 * 3, BMP_Zhuangtai, WHITE, BLACK); //

        LCD_DrawImage1BPP(82 + 320, 100 + 38 * 4, BMP_Junheng, WHITE, BLACK); //均衡故障状态
        LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 4, BMP_Guzhang, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 320 + 42 + 42, 100 + 38 * 4, BMP_Zhuangtai, WHITE, BLACK); //

        LCD_DrawImage1BPP(82 + 320, 100 + 38 * 5, BMP_s, WHITE, BLACK); //SOC故障状态
        LCD_DrawImage1BPP(82 + 320 + 11, 100 + 38 * 5, BMP_o, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 320 + 11 + 11, 100 + 38 * 5, BMP_c, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 320 + 11 + 11 + 11, 100 + 38 * 5, BMP_Guzhang, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 320 + 11 + 11 + 11 + 42, 100 + 38 * 5, BMP_Zhuangtai, WHITE, BLACK); //

        LCD_DrawImage1BPP(82 + 320, 100 + 38 * 6, BMP_DL, WHITE, BLACK); //电流故障状态
        LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 6, BMP_Guzhang, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 320 + 42 + 42, 100 + 38 * 6, BMP_Zhuangtai, WHITE, BLACK); //

        LCD_DrawImage1BPP(82 + 320, 100 + 38 * 7, BMP_Gao, WHITE, BLACK); //高压互锁状态
        LCD_DrawImage1BPP(82 + 320 + 21, 100 + 38 * 7, BMP_Yali, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 7, BMP_Husuo, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 320 + 42 + 42, 100 + 38 * 7, BMP_Zhuangtai, WHITE, BLACK); //

        LCD_DrawImage1BPP(82 + 320, 100 + 38 * 8, BMP_b, WHITE, BLACK); //BMS故障状态
        LCD_DrawImage1BPP(82 + 320 + 11, 100 + 38 * 8, BMP_m, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 320 + 11 + 11, 100 + 38 * 8, BMP_s, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 320 + 11 + 11 + 11, 100 + 38 * 8, BMP_Guzhang, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 320 + 11 + 11 + 11 + 42, 100 + 38 * 8, BMP_Zhuangtai, WHITE, BLACK); //

        LCD_DrawImage1BPP(82 + 320, 100 + 38 * 9, BMP_System, WHITE, BLACK); //系统报警
        LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 9, BMP_Baojing, WHITE, BLACK); //

    }

}

void BMSUpdate(unsigned char index) {
    if (index == 1) {
        print_SZ_1(82 + 200 + 30, 100 - 8, BMS_Voltage * 0.1, 3, 0, WHITE);
        //print_SZ_1(82 + 200 + 30, 100 - 8 + 38, BMS_Voltage * 0.2, 3, 0, WHITE);
        //print_SZ_1(82 + 200 + 30, 100 - 8 + 38 * 2, BMS_TotalVoltage * 0.1, 3, 0, WHITE);
        updata_DAT(82 + 200 + 30 - 16, 100 - 8 + 38, BMS_Current, 0.05, 1600, WHITE, 4, 0);
        //print_SZ_1(82 + 200 + 30, 100 - 8 + 38 * 4, BMS_Ahr * 2, 3, 0, WHITE);
        //updata_DAT(82 + 200 + 30 - 16, 100 - 8 + 38 * 5, BMS_Power, 0.1, 1000, WHITE, 4, 0);
        print_SZ_1(82 + 200 + 30, 100 - 8 + 38 * 2, BMS_SOC, 3, 0, WHITE);
        //print_SZ_1(82 + 200 + 30 - 32, 100 - 8 + 38 * 7, BMS_SOH * 5, 4, 1, WHITE);
        //print_SZ_1(82 + 200 + 30 - 48, 100 - 8 + 38 * 8, BMS_Ohm, 5, 3, WHITE);
        //print_SZ_1(82 + 200 + 30 + 16, 100 - 8 + 38 * 9, BMS_Life, 2, 0, WHITE);
        print_D(82 + 200 + 48, 100 - 8 + 38 * 3, BMS_Mode, 3, 0, WHITE);
        print_D(82 + 200 + 32, 100 - 8 + 38 * 4, BMS_Kt, 4, 0, WHITE);
        print_D(82 + 200 + 64, 100 - 8 + 38 * 5, BMS_Status, 2, 0, WHITE);
        print_SZ_1(82 + 200 + 30, 100 - 8 + 38 * 6, BMS_Number, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 30, 100 - 8 + 38 * 7, BMS_Temp_Number, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 30, 100 - 8 + 38 * 8, BMS_System_Unit, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 30, 100 - 8 + 38 * 9, BMS_System_Number, 3, 0, WHITE);


        print_SZ_1(82 + 200 + 300 - 32 - 5, 100 - 8, BAT_Single_H, 4, 3, WHITE);
        print_SZ_1(82 + 200 + 300 - 32 + 16 * 6 - 5, 100 - 8, BAT_Single_H_Case, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 300 - 32 + 16 * 10 + 5, 100 - 8, BAT_Single_H_Number, 3, 0, WHITE);

        print_SZ_1(82 + 200 + 300 - 32 - 5, 100 - 8 + 38, BAT_Single_L, 4, 3, WHITE);
        print_SZ_1(82 + 200 + 300 - 32 + 16 * 6 - 5, 100 - 8 + 38, BAT_Single_L_Case, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 300 - 32 + 16 * 10 + 5, 100 - 8 + 38, BAT_Single_L_Number, 3, 0, WHITE);

        updata_DAT(82 + 200 + 300 - 5, 100 - 8 + 38 * 2, BAT_Temp_H, 1, 40, WHITE, 3, 0);
        print_SZ_1(82 + 200 + 300 - 32 + 16 * 6 - 5, 100 - 8 + 38 * 2, BAT_Temp_H_Case, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 300 - 32 + 16 * 10 + 5, 100 - 8 + 38 * 2, BAT_Temp_H_Number, 3, 0, WHITE);

        updata_DAT(82 + 200 + 300 - 5, 100 - 8 + 38 * 3, BAT_Temp_L, 1, 40, WHITE, 3, 0);
        print_SZ_1(82 + 200 + 300 - 32 + 16 * 6 - 5, 100 - 8 + 38 * 3, BAT_Temp_L_Case, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 300 - 32 + 16 * 10 + 5, 100 - 8 + 38 * 3, BAT_Temp_L_Number, 3, 0, WHITE);

        updata_DAT(82 + 200 + 300 + 32 - 5, 100 - 8 + 38 * 4, BAT_Temp_Average, 1, 40, WHITE, 3, 0);

        print_SZ_1(82 + 200 + 300 - 5, 100 - 8 + 38 * 5, BMS_Ohm, 5, 0, WHITE);
        //updata_DAT(82 + 200 + 300, 100 - 8 + 38 * 5, BMS_Temp, 1, 40, WHITE, 3, 0);
        //disp_SPN_FMI(82 + 320 + 90 - 32, 100 + 38 * 7 - 8, CAN_18FECAF3_len, CAN_18FECAF3);
    } else if (index == 2) {
        //print_SZ_1(82 + 200 + 30, 100 - 8, BAT_Voltage_H_Limit * 0.2, 3, 0, WHITE);
        //print_SZ_1(82 + 200 + 30, 100 - 8 + 38, BAT_Voltage_L_Limit * 0.2, 3, 0, WHITE);
        //print_SZ_1(82 + 200 + 30 - 32, 100 - 8 + 38 * 2, BAT_Single_Voltage_H_Limit, 4, 2, WHITE);
        //print_SZ_1(82 + 200 + 30 - 32, 100 - 8 + 38 * 3, BAT_Single_Voltage_L_Limit, 4, 2, WHITE);
        updata_DAT(82 + 200 + 32, 100 - 8, BAT_Temp_H_Limit, 1, 40, WHITE, 3, 0);
        updata_DAT(82 + 200 + 32, 100 - 8 + 38, BAT_Temp_L_Limit, 1, 40, WHITE, 3, 0);
        print_SZ_1(82 + 200 + 32, 100 - 8 + 38 * 2, BMS_SOC_L_Limit, 3, 0, WHITE);
        updata_DAT(82 + 200 + 32 - 16, 100 - 8 + 38 * 3, BAT_Current_Discharge_Limit, 0.05, 1600, WHITE, 4, 0);
        updata_DAT(82 + 200 + 32 - 16, 100 - 8 + 38 * 4, BAT_Current_Charge_Limit, 0.05, 1600, WHITE, 4, 0);
        //print_SZ_1(82 + 200 + 30 - 32, 100 - 8 + 38 * 6, BMS_SOC_H_Limit * 5, 4, 1, WHITE);

        //print_SZ_1(82 + 200 + 30 - 32, 100 - 8 + 38 * 8, BMS_Power_10s_Discharge_Limit * 4, 4, 0, WHITE);
        //print_SZ_1(82 + 200 + 30 - 32, 100 - 8 + 38 * 9, BMS_Power_10s_Charge_Limit * 4, 4, 0, WHITE);


        //print_D(82 + 200 + 300 + 32, 100 - 8 + 38 * 3, BMS_Fault, 4, 0, WHITE);
        //print_D(82 + 200 + 300 + 64, 100 - 8 + 38 * 4, BMS_Balance_Lock, 2, 0, WHITE);
        //print_D(82 + 200 + 300 + 64, 100 - 8 + 38 * 5, BMS_Fault_Lock, 2, 0, WHITE);
        print_SZ_1(82 + 200 - 16, 100 - 8 + 38 * 5, IRM_Ohm_Positive, 6, 0, WHITE);
        print_SZ_1(82 + 200 - 16, 100 - 8 + 38 * 6, IRM_Ohm_Negative, 6, 0, WHITE);
        print_SZ_1(82 + 200 + 64, 100 - 8 + 38 * 7, IRM_Fault_Level, 1, 0, WHITE);
        print_SZ_1(82 + 200 + 64, 100 - 8 + 38 * 8, IRM_Insulation_Level, 1, 0, WHITE);
        print_SZ_1(82 + 200 + 32, 100 - 8 + 38 * 9, IRM_Life, 3, 0, WHITE);

        print_D(82 + 200 + 300 + 48, 100 - 8, BAT_Voltage_Fault, 4, 0, WHITE);
        print_D(82 + 200 + 300 + 48, 100 - 8 + 38, BAT_Single_Fault, 4, 0, WHITE);
        print_D(82 + 200 + 300 + 48 - 32, 100 - 8 + 38 * 2, BAT_Temp_Fault, 6, 0, WHITE);
        print_D(82 + 200 + 300 + 48 + 32, 100 - 8 + 38 * 3, BAT_Insulation_Fault, 2, 0, WHITE);
        print_D(82 + 200 + 300 + 48 + 32, 100 - 8 + 38 * 4, BAT_Consistency_Fault, 2, 0, WHITE);
        print_D(82 + 200 + 300 + 48 - 32, 100 - 8 + 38 * 5, BAT_SOC_Fault, 6, 0, WHITE);
        print_D(82 + 200 + 300 + 48, 100 - 8 + 38 * 6, BAT_Current_Fault, 4, 0, WHITE);
        print_D(82 + 200 + 300 + 48 + 32, 100 - 8 + 38 * 7, BAT_Lock_Fault, 2, 0, WHITE);
        print_D(82 + 200 + 300 + 48 + 32, 100 - 8 + 38 * 8, BMS_Comm_Fault, 2, 0, WHITE);
        print_D(82 + 200 + 300 + 48 + 48, 100 - 8 + 38 * 9, BMS_System_Fault, 1, 0, WHITE);


    }
}

void frmBMS(void) {
    static unsigned char index_BMS = 1;
    if (f_index == 0) { //只更新一次
        f_index = 1;
        BMSFrame(index_BMS);
    } else if (f_index == 1) {
        f_index = 1;
        BMSUpdate(index_BMS);
    } else {
        f_index = 0;
    }
    if (key_up) {
        key_up = 0;
        index_BMS++;
        f_index = 0;
        if (index_BMS == 3) {
            index_BMS = 1;
            frmID = 1;
        }
    }

    if (key_AV) {
        key_AV = 0;
        index_BMS--;
        f_index = 0;
        if (index_BMS == 0) {
            index_BMS = 1;
            frmID = 1;
        }
    }

    if (key_set) {//返回主界面
        key_set = 0;
        frmID = 0;
        f_index = 0;
        Index = 0;
        index_BMS = 1;
    }
    if (key_long_set) {
        key_long_set = 0;
    }

}

/******************************************************/
void BatteryFrame(unsigned char index) {
    unsigned char i, j;
    LCD_Clear();
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //顶部横线
    LCD_DrawImageSBPP(130 + 200 + 24, 130 - 85, 50, Battery_SYSTEM, WHITE, BLACK); //电池
    //分格
    for (i = 0; i < 6; i++) {
        LCD_DrawRect(i * 160, 45 + 70, 1, 360, GRAY);
        LCD_DrawRect(58 + i * 160, 45 + 70, 1, 360, GRAY);
    }
    for (i = 0; i < 13; i++)
        LCD_DrawRect(0, 45 + 70 + i * 36, 800, 1, GRAY);

    LCD_DrawImage1BPP(50, 90, BMP_DC, WHITE, BLACK); //电池
    LCD_DrawImage1BPP(50 + 42, 90, BMP_DY, WHITE, BLACK); //电压
    LCD_DrawImage1BPP(50 + 42 + 42 + 15, 90 - 9, BMP_SZ_1[index], GREEN, BLACK);

    //编号
    if (index == 1) {
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

    if (index == 2) {
        for (j = 0; j < 5; j++) {
            for (i = 0; i < 11; i++) {
                if (i < 9) {//写编号个位
                    LCD_DrawImage1BPP(5 + 16 + 16 + j * 160, 46 + 70 + i * 36, BMP_SZ_1[i + 1], WHITE, BLACK);
                    LCD_DrawImage1BPP(5 + 16 + j * 160, 46 + 70 + i * 36, BMP_SZ_1[j + 5], WHITE, BLACK);
                } else {//写最底下一行编号
                    if (j < 4) {
                        LCD_DrawImage1BPP(5 + 16 + 16 + j * 160, 46 + 70 + i * 36, BMP_SZ_1[0], WHITE, BLACK);
                        LCD_DrawImage1BPP(5 + 16 + j * 160, 46 + 70 + i * 36, BMP_SZ_1[j + 6], WHITE, BLACK);
                    } else {
                        LCD_DrawImage1BPP(5 + 16 + 16 + j * 160, 46 + 70 + i * 36, BMP_SZ_1[0], WHITE, BLACK);
                        LCD_DrawImage1BPP(5 + 16 + j * 160, 46 + 70 + i * 36, BMP_SZ_1[0], WHITE, BLACK);
                        LCD_DrawImage1BPP(5 + j * 160, 46 + 70 + i * 36, BMP_SZ_1[1], WHITE, BLACK);
                    }
                }
                LCD_DrawImage1BPP(5 + 4 + 16 + 16 + 100 + j * 160, 46 + 70 + i * 36, BMP_V, YELLOW, BLACK);
            }
        }
    }

    if (index == 3) {
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

    if (index == 4) {
        for (j = 0; j < 5; j++) {
            for (i = 0; i < 11; i++) {
                if (i < 9) {
                    LCD_DrawImage1BPP(5 + 16 + 16 + j * 160, 46 + 70 + i * 36, BMP_SZ_1[i + 1], WHITE, BLACK);
                    LCD_DrawImage1BPP(5 + 16 + j * 160, 46 + 70 + i * 36, BMP_SZ_1[j + 5], WHITE, BLACK);
                    LCD_DrawImage1BPP(5 + j * 160, 46 + 70 + i * 36, BMP_SZ_1[1], WHITE, BLACK);
                } else {//写最底下一行编号
                    if (j < 4) {
                        LCD_DrawImage1BPP(5 + 16 + 16 + j * 160, 46 + 70 + i * 36, BMP_SZ_1[0], WHITE, BLACK);
                        LCD_DrawImage1BPP(5 + 16 + j * 160, 46 + 70 + i * 36, BMP_SZ_1[j + 6], WHITE, BLACK);
                        LCD_DrawImage1BPP(5 + j * 160, 46 + 70 + i * 36, BMP_SZ_1[1], WHITE, BLACK);
                    } else {
                        LCD_DrawImage1BPP(5 + 16 + 16 + j * 160, 46 + 70 + i * 36, BMP_SZ_1[0], WHITE, BLACK);
                        LCD_DrawImage1BPP(5 + 16 + j * 160, 46 + 70 + i * 36, BMP_SZ_1[0], WHITE, BLACK);
                        LCD_DrawImage1BPP(5 + j * 160, 46 + 70 + i * 36, BMP_SZ_1[2], WHITE, BLACK);
                    }
                }
                LCD_DrawImage1BPP(5 + 4 + 16 + 16 + 100 + j * 160, 46 + 70 + i * 36, BMP_V, YELLOW, BLACK);
                //LCD_DrawImage1BPP(5 + j * 160, 46 + 70 + i * 36, BMP_SZ_1[1], WHITE, BLACK);
            }
        }
    }

    if (index == 5) {
        LCD_DrawImage1BPP(50, 90, BMP_DC, WHITE, BLACK); //电池
        LCD_DrawImage1BPP(50 + 42, 90, BMP_Wendu, WHITE, BLACK); //温度
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
                LCD_DrawImage1BPP(3 + 16 + 16 + 100 + j * 160, 46 + 70 + i * 36 + 8, BMP_T, YELLOW, BLACK);
            }
        }
    }

    if (index == 6) {
        LCD_DrawImage1BPP(50, 90, BMP_DC, WHITE, BLACK); //电池
        LCD_DrawImage1BPP(50 + 42, 90, BMP_Wendu, WHITE, BLACK); //温度
        LCD_DrawImage1BPP(50 + 42 + 42 + 15, 90 - 9, BMP_SZ_1[2], GREEN, BLACK);
        for (j = 0; j < 5; j++) {
            for (i = 0; i < 11; i++) {
                if (i < 9) {//写编号个位
                    LCD_DrawImage1BPP(5 + 16 + 16 + j * 160, 46 + 70 + i * 36, BMP_SZ_1[i + 1], WHITE, BLACK);
                    LCD_DrawImage1BPP(5 + 16 + j * 160, 46 + 70 + i * 36, BMP_SZ_1[j + 5], WHITE, BLACK);
                } else {//写最底下一行编号
                    if (j < 4) {
                        LCD_DrawImage1BPP(5 + 16 + 16 + j * 160, 46 + 70 + i * 36, BMP_SZ_1[0], WHITE, BLACK);
                        LCD_DrawImage1BPP(5 + 16 + j * 160, 46 + 70 + i * 36, BMP_SZ_1[j + 6], WHITE, BLACK);
                    } else {
                        LCD_DrawImage1BPP(5 + 16 + 16 + j * 160, 46 + 70 + i * 36, BMP_SZ_1[0], WHITE, BLACK);
                        LCD_DrawImage1BPP(5 + 16 + j * 160, 46 + 70 + i * 36, BMP_SZ_1[0], WHITE, BLACK);
                        LCD_DrawImage1BPP(5 + j * 160, 46 + 70 + i * 36, BMP_SZ_1[1], WHITE, BLACK);
                    }
                }
                LCD_DrawImage1BPP(3 + 16 + 16 + 100 + j * 160, 46 + 70 + i * 36 + 8, BMP_T, YELLOW, BLACK);
            }
        }
    }



    /*for (i = 0; i < 4; i++) {
        LCD_DrawImage1BPP(82 - 50 - 10, 100 + 38 * i, BMP_Dan, WHITE, BLACK); //单
        LCD_DrawImage1BPP(82 - 50 - 10 + 21, 100 + 38 * i, BMP_Ti, WHITE, BLACK); //体
        LCD_DrawImage1BPP(82 - 50 - 10 + 21 + 21, 100 + 38 * i, BMP_Zui, WHITE, BLACK); //最
        LCD_DrawImage1BPP(82 - 50 - 10 + 21 + 21 + 21, 100 + 38 * i, BMP_Gao, WHITE, BLACK); //高
        LCD_DrawImage1BPP(82 - 50 - 10 + 21 + 21 + 21 + 21, 100 + 38 * i, BMP_DY, WHITE, BLACK); //电压
        LCD_DrawImage1BPP(82 - 50 - 10 + 21 + 21 + 21 + 21 + 42, 100 - 8 + 38 * i, BMP_SZ_1[1 + i], WHITE, BLACK); //1
        LCD_DrawImage1BPP(400 - 50 - 10 - 24 - 63, 100 + 38 * i, BMP_v, WHITE, BLACK); //V

        LCD_DrawImage1BPP(82 - 50 - 10 + 42 * 7, 100 + 38 * i, BMP_Xiang_BMS, WHITE, BLACK); //箱

        LCD_DrawImage1BPP(82 - 50 + 42 * 8.5, 100 + 38 * i, BMP_Hao, WHITE, BLACK); //号
    }
    for (i = 0; i < 4; i++) {
        LCD_DrawImage1BPP(82 - 50 - 10, 100 + 38 * 4 + 38 * i, BMP_Dan, WHITE, BLACK); //单
        LCD_DrawImage1BPP(82 - 50 - 10 + 21, 100 + 38 * 4 + 38 * i, BMP_Ti, WHITE, BLACK); //体
        LCD_DrawImage1BPP(82 - 50 - 10 + 21 + 21, 100 + 38 * 4 + 38 * i, BMP_Zui, WHITE, BLACK); //最
        LCD_DrawImage1BPP(82 - 50 - 10 + 21 + 21 + 21, 100 + 38 * 4 + 38 * i, BMP_Di, WHITE, BLACK); //低
        LCD_DrawImage1BPP(82 - 50 - 10 + 21 + 21 + 21 + 21, 100 + 38 * 4 + 38 * i, BMP_DY, WHITE, BLACK); //电压
        LCD_DrawImage1BPP(82 - 50 - 10 + 21 + 21 + 21 + 21 + 42, 100 - 8 + 38 * 4 + 38 * i, BMP_SZ_1[1 + i], WHITE, BLACK); //1
        LCD_DrawImage1BPP(400 - 50 - 10 - 24 - 63, 100 + 38 * 4 + 38 * i, BMP_v, WHITE, BLACK); //V

        LCD_DrawImage1BPP(82 - 50 - 10 + 42 * 7, 100 + 38 * 4 + 38 * i, BMP_Xiang_BMS, WHITE, BLACK); //箱

        LCD_DrawImage1BPP(82 - 50 + 42 * 8.5, 100 + 38 * 4 + 38 * i, BMP_Hao, WHITE, BLACK); //号
    }
    for (i = 0; i < 4; i++) {
        LCD_DrawImage1BPP(82 + 380 - 50, 100 + 38 * i, BMP_Dan, WHITE, BLACK); //单
        LCD_DrawImage1BPP(82 + 380 - 50 + 21, 100 + 38 * i, BMP_Ti, WHITE, BLACK); //体
        LCD_DrawImage1BPP(82 + 380 - 50 + 21 + 21, 100 + 38 * i, BMP_Zui, WHITE, BLACK); //最
        LCD_DrawImage1BPP(82 + 380 - 50 + 21 + 21 + 21, 100 + 38 * i, BMP_Gao, WHITE, BLACK); //高
        LCD_DrawImage1BPP(82 + 380 - 50 + 21 + 21 + 21 + 21, 100 + 38 * i, BMP_Wendu, WHITE, BLACK); //温度
        LCD_DrawImage1BPP(82 + 380 - 50 + 21 + 21 + 21 + 21 + 42, 100 - 8 + 38 * i, BMP_SZ_1[1 + i], WHITE, BLACK); //1
        LCD_DrawImage1BPP(400 + 380 - 50 - 24 - 63, 100 + 38 * i, BMP_T, WHITE, BLACK); //℃

        LCD_DrawImage1BPP(82 + 380 + 10 - 50 + 42 * 7, 100 + 38 * i, BMP_Xiang_BMS, WHITE, BLACK); //箱
    }
    for (i = 0; i < 4; i++) {
        LCD_DrawImage1BPP(82 + 380 - 50, 100 + 38 * 4 + 38 * i, BMP_Dan, WHITE, BLACK); //单
        LCD_DrawImage1BPP(82 + 380 - 50 + 21, 100 + 38 * 4 + 38 * i, BMP_Ti, WHITE, BLACK); //体
        LCD_DrawImage1BPP(82 + 380 - 50 + 21 + 21, 100 + 38 * 4 + 38 * i, BMP_Zui, WHITE, BLACK); //最
        LCD_DrawImage1BPP(82 + 380 - 50 + 21 + 21 + 21, 100 + 38 * 4 + 38 * i, BMP_Di, WHITE, BLACK); //低
        LCD_DrawImage1BPP(82 + 380 - 50 + 21 + 21 + 21 + 21, 100 + 38 * 4 + 38 * i, BMP_Wendu, WHITE, BLACK); //温度
        LCD_DrawImage1BPP(82 + 380 - 50 + 21 + 21 + 21 + 21 + 42, 100 - 8 + 38 * 4 + 38 * i, BMP_SZ_1[1 + i], WHITE, BLACK); //1
        LCD_DrawImage1BPP(400 + 380 - 50 - 24 - 63, 100 + 38 * 4 + 38 * i, BMP_T, WHITE, BLACK); //℃

        LCD_DrawImage1BPP(82 + 380 + 10 - 50 + 42 * 7, 100 + 38 * 4 + 38 * i, BMP_Xiang_BMS, WHITE, BLACK); //箱
    }
    for (i = 0; i < 2; i++)
        LCD_DrawRect(80 - 50 - 10 + 390 * i, 90, 1, 380, GREEN);
    LCD_DrawRect(80 - 50 - 10 + 390 + 380, 90, 1, 380, GREEN);
    for (i = 0; i < 11; i++)
        LCD_DrawRect(80 - 50 - 10, 90 + i * 38, 640 + 120 + 10, 1, GREEN);*/
    /*
    LCD_DrawImage1BPP(82, 100, BMP_DC, WHITE, BLACK); //电池
    LCD_DrawImage1BPP(82 + 42, 100, BMP_System, WHITE, BLACK); //系统
    LCD_DrawImage1BPP(82 + 42 + 42, 100, BMP_Zui, WHITE, BLACK); //最
    LCD_DrawImage1BPP(82 + 42 + 42 + 21, 100, BMP_Gao, WHITE, BLACK); //高
    LCD_DrawImage1BPP(82 + 42 + 42 + 42, 100, BMP_Yunxu, WHITE, BLACK); //允许
    LCD_DrawImage1BPP(82 + 42 + 42 + 42 + 42, 100, BMP_DY, WHITE, BLACK); //电压
    LCD_DrawImage1BPP(400 - 24, 100, BMP_v, WHITE, BLACK); //V
    
    LCD_DrawImage1BPP(82, 100 + 38, BMP_DC, WHITE, BLACK); //电池
    LCD_DrawImage1BPP(82 + 42, 100 + 38, BMP_System, WHITE, BLACK); //系统
    LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38, BMP_Zui, WHITE, BLACK); //最
    LCD_DrawImage1BPP(82 + 42 + 42 + 21, 100 + 38, BMP_Di, WHITE, BLACK); //低
    LCD_DrawImage1BPP(82 + 42 + 42 + 42, 100 + 38, BMP_Yunxu, WHITE, BLACK); //允许
    LCD_DrawImage1BPP(82 + 42 + 42 + 42 + 42 , 100 + 38, BMP_DY, WHITE, BLACK); //电压
    LCD_DrawImage1BPP(400 - 24, 100 + 38, BMP_v, WHITE, BLACK); //V

    LCD_DrawImage1BPP(82, 100 + 38 * 2, BMP_Dan, WHITE, BLACK); //单
    LCD_DrawImage1BPP(82 + 21, 100 + 38 * 2, BMP_Ti, WHITE, BLACK); //体
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 2, BMP_Zui, WHITE, BLACK); //最
    LCD_DrawImage1BPP(82 + 42 + 21, 100 + 38 * 2, BMP_Gao, WHITE, BLACK); //高
    LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 2, BMP_Yunxu, WHITE, BLACK); //允许
    LCD_DrawImage1BPP(82 + 42 + 42 + 42, 100 + 38 * 2, BMP_DY, WHITE, BLACK); //电压
    LCD_DrawImage1BPP(400 - 24, 100 + 38 * 2, BMP_v, WHITE, BLACK); //V

    LCD_DrawImage1BPP(82, 100 + 38 * 3, BMP_Dan, WHITE, BLACK); //单
    LCD_DrawImage1BPP(82 + 21, 100 + 38 * 3, BMP_Ti, WHITE, BLACK); //体
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 3, BMP_Zui, WHITE, BLACK); //最
    LCD_DrawImage1BPP(82 + 42 + 21, 100 + 38 * 3, BMP_Di, WHITE, BLACK); //低
    LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 3, BMP_Yunxu, WHITE, BLACK); //允许
    LCD_DrawImage1BPP(82 + 42 + 42 + 42, 100 + 38 * 3, BMP_DY, WHITE, BLACK); //电压
    LCD_DrawImage1BPP(400 - 24, 100 + 38 * 3, BMP_v, WHITE, BLACK); //V
        
    LCD_DrawImage1BPP(82, 100 + 38 * 4, BMP_Zui, WHITE, BLACK); //最
    LCD_DrawImage1BPP(82 + 21, 100 + 38 * 4, BMP_Gao, WHITE, BLACK); //高
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 4, BMP_Yunxu, WHITE, BLACK); //允许
    LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 4, BMP_Chong, WHITE, BLACK); //充
    LCD_DrawImage1BPP(82 + 42 + 42 + 21, 100 + 38 * 4, BMP_DY, WHITE, BLACK); //电
    LCD_DrawImage1BPP(82 + 42 + 42 + 42, 100 + 38 * 4, BMP_DL, WHITE, BLACK); //电流
    LCD_DrawImage1BPP(400 - 24, 100 + 38 * 4, BMP_a, WHITE, BLACK); //A

    LCD_DrawImage1BPP(82, 100 + 38 * 5, BMP_Zui, WHITE, BLACK); //最
    LCD_DrawImage1BPP(82 + 21, 100 + 38 * 5, BMP_Gao, WHITE, BLACK); //高
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 5, BMP_Yunxu, WHITE, BLACK); //允许
    LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 5, BMP_Fang, WHITE, BLACK); //放
    LCD_DrawImage1BPP(82 + 42 + 42 + 21, 100 + 38 * 5, BMP_DY, WHITE, BLACK); //电
    LCD_DrawImage1BPP(82 + 42 + 42 + 42, 100 + 38 * 5, BMP_DL, WHITE, BLACK); //电流
    LCD_DrawImage1BPP(400 - 24, 100 + 38 * 5, BMP_a, WHITE, BLACK); //A
    
    LCD_DrawImage1BPP(82, 100 + 38 * 6, BMP_Zui, WHITE, BLACK); //最
    LCD_DrawImage1BPP(82 + 21, 100 + 38 * 6, BMP_Gao, WHITE, BLACK); //高
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 6, BMP_Yunxu, WHITE, BLACK); //允许
    LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 6, BMP_s, WHITE, BLACK); //S
    LCD_DrawImage1BPP(82 + 42 + 42 + 11, 100 + 38 * 6, BMP_o, WHITE, BLACK); //O
    LCD_DrawImage1BPP(82 + 42 + 42 + 11 + 11, 100 + 38 * 6, BMP_c, WHITE, BLACK); //C
    LCD_DrawImage1BPP(400 - 24, 100 + 38 * 6, BMP_Baifenhao, WHITE, BLACK); //%
    
    LCD_DrawImage1BPP(82, 100 + 38 * 7, BMP_Zui, WHITE, BLACK); //最
    LCD_DrawImage1BPP(82 + 21, 100 + 38 * 7, BMP_Di, WHITE, BLACK); //低
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 7, BMP_Yunxu, WHITE, BLACK); //允许
    LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 7, BMP_s, WHITE, BLACK); //S
    LCD_DrawImage1BPP(82 + 42 + 42 + 11, 100 + 38 * 7, BMP_o, WHITE, BLACK); //O
    LCD_DrawImage1BPP(82 + 42 + 42 + 11 + 11, 100 + 38 * 7, BMP_c, WHITE, BLACK); //C
    LCD_DrawImage1BPP(400 - 24, 100 + 38 * 7, BMP_Baifenhao, WHITE, BLACK); //%
    
    LCD_DrawImage1BPP(82, 100 + 38 * 8, BMP_Zui, WHITE, BLACK); //最
    LCD_DrawImage1BPP(82 + 21, 100 + 38 * 8, BMP_Gao, WHITE, BLACK); //高
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 8, BMP_Yunxu, WHITE, BLACK); //允许
    LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 8, BMP_Fang, WHITE, BLACK); //放
    LCD_DrawImage1BPP(82 + 42 + 42 + 21, 100 + 38 * 8, BMP_DY, WHITE, BLACK); //电
    LCD_DrawImage1BPP(82 + 42 + 42 + 42, 100 + 38 * 8, BMP_Gonglv, WHITE, BLACK); //功率
    LCD_DrawImage1BPP(400 - 24 - 11, 100 + 38 * 8, BMP_k, WHITE, BLACK); //kw
    LCD_DrawImage1BPP(400 - 24, 100 + 38 * 8, BMP_w, WHITE, BLACK); 
    
    LCD_DrawImage1BPP(82, 100 + 38 * 9, BMP_Zui, WHITE, BLACK); //最
    LCD_DrawImage1BPP(82 + 21, 100 + 38 * 9, BMP_Gao, WHITE, BLACK); //高
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 9, BMP_Yunxu, WHITE, BLACK); //允许
    LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 9, BMP_Chong, WHITE, BLACK); //充
    LCD_DrawImage1BPP(82 + 42 + 42 + 21, 100 + 38 * 9, BMP_DY, WHITE, BLACK); //电
    LCD_DrawImage1BPP(82 + 42 + 42 + 42, 100 + 38 * 9, BMP_Gonglv, WHITE, BLACK); //功率
    LCD_DrawImage1BPP(400 - 24 - 11, 100 + 38 * 9, BMP_k, WHITE, BLACK); //kw
    LCD_DrawImage1BPP(400 - 24, 100 + 38 * 9, BMP_w, WHITE, BLACK); 
    
    LCD_DrawImage1BPP(82 + 320, 100, BMP_Zui, WHITE, BLACK); //最
    LCD_DrawImage1BPP(82 + 320 + 21, 100, BMP_Gao, WHITE, BLACK); //高
    LCD_DrawImage1BPP(82 + 320 + 42, 100, BMP_Yunxu, WHITE, BLACK); //允许
    LCD_DrawImage1BPP(82 + 320 + 42 + 42, 100, BMP_Dan, WHITE, BLACK); //单
    LCD_DrawImage1BPP(82 + 320 + 42 + 42 + 21, 100, BMP_Ti, WHITE, BLACK); //体
    LCD_DrawImage1BPP(82 + 320 + 42 + 42 + 42, 100, BMP_Wendu, WHITE, BLACK); //温度
    LCD_DrawImage1BPP(720 - 24, 100, BMP_T, WHITE, BLACK); //℃
    
    LCD_DrawImage1BPP(82 + 320, 100 + 38, BMP_Zui, WHITE, BLACK); //最
    LCD_DrawImage1BPP(82 + 320 + 21, 100 + 38, BMP_Di, WHITE, BLACK); //低
    LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38, BMP_Yunxu, WHITE, BLACK); //允许
    LCD_DrawImage1BPP(82 + 320 + 42 + 42, 100 + 38, BMP_Dan, WHITE, BLACK); //单
    LCD_DrawImage1BPP(82 + 320 + 42 + 42 + 21, 100 + 38, BMP_Ti, WHITE, BLACK); //体
    LCD_DrawImage1BPP(82 + 320 + 42 + 42 + 42, 100 + 38, BMP_Wendu, WHITE, BLACK); //温度
    LCD_DrawImage1BPP(720 - 24, 100 + 38, BMP_T, WHITE, BLACK); //℃       
    
    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 2, BMP_DC, WHITE, BLACK); //电池
    LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 2, BMP_Zhuangtai, WHITE, BLACK); //状态

    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 3, BMP_Guzhang, WHITE, BLACK); //故障
    LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 3, BMP_Zhuangtai, WHITE, BLACK); //状态

    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 4, BMP_Junheng, WHITE, BLACK); //均衡
    LCD_DrawImage1BPP(82 + 320+42, 100 + 38 * 4, BMP_Suoding, WHITE, BLACK); //锁定
    LCD_DrawImage1BPP(82 + 320 +42+ 42, 100 + 38 * 4, BMP_Zhuangtai, WHITE, BLACK); //状态
    
    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 5, BMP_Guzhang, WHITE, BLACK); //故障
    LCD_DrawImage1BPP(82 + 320+42, 100 + 38 * 5, BMP_Suoding, WHITE, BLACK); //锁定
    LCD_DrawImage1BPP(82 + 320 +42+ 42, 100 + 38 * 5, BMP_Zhuangtai, WHITE, BLACK); //状态
     */
    /*
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
    }*/

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

void BatteryUpdate(unsigned char index) {
    unsigned char i, j;
    if (index == 1) {
        for (j = 0; j < 5; j++) {
            for (i = 0; i < 10; i++) {
                if (BAT_Cell_Voltage[j * 10 + i] == 0)
                    print_SZ_1(60 + j * 160, 46 + 70 + 36 * i, BAT_Cell_Voltage[j * 10 + i], 4, 3, RED);
                else print_SZ_1(60 + j * 160, 46 + 70 + 36 * i, BAT_Cell_Voltage[j * 10 + i], 4, 3, GREEN); //单体电压
            }
        }
    }

    if (index == 2) {
        for (j = 0; j < 5; j++) {
            for (i = 0; i < 10; i++) {
                if (BAT_Cell_Voltage[50 + j * 10 + i] == 0)
                    print_SZ_1(60 + j * 160, 46 + 70 + 36 * i, BAT_Cell_Voltage[50 + j * 10 + i], 4, 3, RED);
                else print_SZ_1(60 + j * 160, 46 + 70 + 36 * i, BAT_Cell_Voltage[50 + j * 10 + i ], 4, 3, GREEN); //单体电压
            }
        }
    }

    if (index == 3) {
        for (j = 0; j < 5; j++) {
            for (i = 0; i < 10; i++) {
                if (BAT_Cell_Voltage[100 + j * 10 + i] == 0)
                    print_SZ_1(60 + j * 160, 46 + 70 + 36 * i, BAT_Cell_Voltage[100 + j * 10 + i], 4, 3, RED);
                else print_SZ_1(60 + j * 160, 46 + 70 + 36 * i, BAT_Cell_Voltage[100 + j * 10 + i], 4, 3, GREEN); //单体电压
            }
        }
    }

    if (index == 4) {
        for (j = 0; j < 5; j++) {
            for (i = 0; i < 10; i++) {
                if (BAT_Cell_Voltage[150 + j * 10 + i] == 0)
                    print_SZ_1(60 + j * 160, 46 + 70 + 36 * i, BAT_Cell_Voltage[150 + j * 10 + i], 4, 3, RED);
                else print_SZ_1(60 + j * 160, 46 + 70 + 36 * i, BAT_Cell_Voltage[150 + j * 10 + i], 4, 3, GREEN); //单体电压
            }
        }
    }

    if (index == 5) {
        for (j = 0; j < 5; j++) {
            for (i = 0; i < 10; i++) {
                if (BAT_Cell_Temperature[j * 10 + i] == 0)
                    updata_DAT(60 + 23 + 42 + j * 160 - 40, 46 + 70 + 36 * i, BAT_Cell_Temperature[j * 10 + i], 1, 40, RED, 3, 0); //单体温度
                else updata_DAT(60 + 23 + 42 + j * 160 - 40, 46 + 70 + 36 * i, BAT_Cell_Temperature[j * 10 + i], 1, 40, GREEN, 3, 0); //单体温度
            }
        }
    }

    if (index == 6) {
        for (j = 0; j < 5; j++) {
            for (i = 0; i < 10; i++) {
                if (BAT_Cell_Temperature[j * 10 + i] == 0)
                    updata_DAT(60 + 23 + 42 + j * 160 - 40, 46 + 70 + 36 * i, BAT_Cell_Temperature[50 + j * 10 + i], 1, 40, RED, 3, 0); //单体温度
                else updata_DAT(60 + 23 + 42 + j * 160 - 40, 46 + 70 + 36 * i, BAT_Cell_Temperature[50 + j * 10 + i], 1, 40, GREEN, 3, 0); //单体温度
            }
        }
    }
    /*for (i = 0; i < 4; i++) {
        print_SZ_1(82 + 200 + 280 - 380-10, 100 - 8 + 38 * i, BAT_Max_Cell_Voltage, 4, 3, YELLOW);
        print_SZ_1(82 + 200 + 280 - 380 -10+ 16 * 7-16, 100 - 8 + 38 * i, BAT_Max_Cell_Voltage_Cell_Case, 3, 0, YELLOW);
        print_SZ_1(82 + 200 + 280 - 380 + 16 * 11-16, 100 - 8 + 38 * i, BAT_Max_Cell_Voltage_Cell_Number, 3, 0, YELLOW);
    }
    for (i = 0; i < 4; i++) {
        print_SZ_1(82 + 200 + 280 - 380-10, 100 - 8 + 38 * (i + 4), BAT_Min_Cell_Voltage[i], 4, 3, YELLOW);
        print_SZ_1(82 + 200 + 280 - 380 -10+ 16 * 7-16, 100 - 8 + 38 * (i + 4), BAT_Min_Cell_Voltage_Cell_Case[i], 3, 0, YELLOW);
        print_SZ_1(82 + 200 + 280 - 380 + 16 * 11-16, 100 - 8 + 38 * (i + 4), BAT_Min_Cell_Voltage_Cell_Number[i], 3, 0, YELLOW);
    }

    for (i = 0; i < 4; i++) {
        updata_DAT(82 + 200 + 310, 100 - 8 + 38 * i, BAT_Max_Cell_Temperature[i], 1, 40, YELLOW, 3, 0);
        print_SZ_1(82 + 200 + 280+10 + 16 * 7-16, 100 - 8 + 38 * i, BAT_Max_Cell_Temp_Cell_Case[i], 3, 0, YELLOW);
    }
    for (i = 0; i < 4; i++) {
        updata_DAT(82 + 200 + 310, 100 - 8 + 38 * (i + 4), BAT_Min_Cell_Temperature[i], 1, 40, YELLOW, 3, 0);
        print_SZ_1(82 + 200 + 280 +10+ 16 * 7-16, 100 - 8 + 38 * (i + 4), BAT_Min_Cell_Temp_Cell_Case[i], 3, 0, YELLOW);
    }*/
}

void frmBattery(void) {
    static unsigned char index_BAT = 1;
    if (f_index == 0) { //只更新一次
        f_index = 1;
        BatteryFrame(index_BAT);
    } else if (f_index == 1) {
        f_index = 1;
        BatteryUpdate(index_BAT);
    } else {
        f_index = 0;
    }
    if (key_up) {
        key_up = 0;
        index_BAT++;
        f_index = 0;
        if (index_BAT == 6) {
            index_BAT = 1;
            frmID = 1;
        }
    }

    if (key_AV) {
        key_AV = 0;
        index_BAT--;
        f_index = 0;
        if (index_BAT == 0) {
            index_BAT = 1;
            frmID = 1;
        }
    }

    if (key_set) {//返回主界面
        key_set = 0;
        frmID = 0;
        f_index = 0;
        Index = 0;
        index_BAT = 1;
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
    LCD_DrawImageSBPP(130 + 200 - 2, 130 - 85, 50, HV_SYSTEM, WHITE, BLACK); //高压

    LCD_DrawRect(80, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320 + 320, 90, 1, 380, GREEN);
    for (i = 0; i < 11; i++)
        LCD_DrawRect(80, 90 + i * 38, 640, 1, GREEN);

    LCD_DrawImage1BPP(82, 100, BMP_Dengji, WHITE, BLACK);
    LCD_DrawImage1BPP(82, 100, BMP_Zheng, WHITE, BLACK); //正极接触器状态

    LCD_DrawImage1BPP(82, 100 + 38, BMP_Dengji, WHITE, BLACK);
    LCD_DrawImage1BPP(82, 100 + 38, BMP_Fu, WHITE, BLACK); //负极接触器状态

    LCD_DrawImage1BPP(82, 100 + 38 * 2, BMP_Dengji, WHITE, BLACK);
    LCD_DrawImage1BPP(82, 100 + 38 * 2, BMP_Zheng, WHITE, BLACK); //正极预充接触器状态
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 2, BMP_Yuchong, WHITE, BLACK);

    LCD_DrawImage1BPP(82, 100 + 38 * 3, BMP_Dengji, WHITE, BLACK);
    LCD_DrawImage1BPP(82, 100 + 38 * 3, BMP_Fu, WHITE, BLACK); //负极预充接触器状态
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 3, BMP_Yuchong, WHITE, BLACK);

    LCD_DrawImage1BPP(82, 100 + 38 * 4, BMP_Chushuang, WHITE, BLACK); //除霜接触器状态

    LCD_DrawImage1BPP(82, 100 + 38 * 5, BMP_Kongtiao, WHITE, BLACK); //空调接触器状态

    LCD_DrawImage1BPP(82, 100 + 38 * 6, BMP_Jiasu, WHITE, BLACK); //加热接触器状态
    LCD_DrawImage1BPP(82 + 21, 100 + 38 * 6, BMP_Ji, WHITE, BLACK);

    LCD_DrawImage1BPP(82, 100 + 38 * 7, BMP_Re, WHITE, BLACK); //热风接触器状态
    LCD_DrawImage1BPP(82 + 21, 100 + 38 * 7, BMP_Feng, WHITE, BLACK);

    LCD_DrawImage1BPP(82, 100 + 38 * 8, BMP_IC_Qian, WHITE, BLACK); //前端电压
    LCD_DrawImage1BPP(82 + 21, 100 + 38 * 8, BMP_Duan, WHITE, BLACK);
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 8, BMP_DY, WHITE, BLACK);
    LCD_DrawImage1BPP(400 - 24, 100 - 2 + 38 * 8, BMP_v, WHITE, BLACK); //V

    LCD_DrawImage1BPP(82, 100 + 38 * 9, BMP_Life, WHITE, BLACK); //LIFE

    for (i = 0; i < 8; i++) {
        if (i == 2 || i == 3) {
            LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * i, BMP_Jiechuqi, WHITE, BLACK);
            LCD_DrawImage1BPP(82 + 42 + 42 + 63, 100 + 38 * i, BMP_Zhuangtai, WHITE, BLACK);
        } else {
            LCD_DrawImage1BPP(82 + 21 + 21, 100 + 38 * i, BMP_Jiechuqi, WHITE, BLACK);
            LCD_DrawImage1BPP(82 + 42 + 63, 100 + 38 * i, BMP_Zhuangtai, WHITE, BLACK);
        }
    }

    for (i = 0; i < 8; i++) {
        LCD_DrawImage1BPP(82 + 320, 100 + 38 * i, BMP_Jiechuqi, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 63 + 320, 100 + 38 * i, BMP_Zhuangtai, WHITE, BLACK);
        print_SZ_2(82 + 63 + 42 + 320, 100 + 38 * i, i + 1, 1, 0, WHITE);
    }

    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 8, BMP_IC_Hou, WHITE, BLACK); //后端电压
    LCD_DrawImage1BPP(82 + 21 + 320, 100 + 38 * 8, BMP_Duan, WHITE, BLACK);
    LCD_DrawImage1BPP(82 + 42 + 320, 100 + 38 * 8, BMP_DY, WHITE, BLACK);
    LCD_DrawImage1BPP(720 - 24, 100 - 2 + 38 * 8, BMP_v, WHITE, BLACK); //V
}

void AirUpdate(void) {
    print_D(82 + 270, 100 - 8, ICS01_Status1.bit1, 2, 0, WHITE);
    print_D(82 + 270, 100 - 8 + 38, ICS01_Status1.bit2, 2, 0, WHITE);
    print_D(82 + 270, 100 - 8 + 38 * 2, ICS01_Status1.bit3, 2, 0, WHITE);
    print_D(82 + 270, 100 - 8 + 38 * 3, ICS01_Status1.bit4, 2, 0, WHITE);
    print_D(82 + 270, 100 - 8 + 38 * 4, ICS01_Status2.bit1, 2, 0, WHITE);
    print_D(82 + 270, 100 - 8 + 38 * 5, ICS01_Status2.bit2, 2, 0, WHITE);
    print_D(82 + 270, 100 - 8 + 38 * 6, ICS01_Status2.bit3, 2, 0, WHITE);
    print_D(82 + 270, 100 - 8 + 38 * 7, ICS01_Status2.bit4, 2, 0, WHITE);
    print_SZ_1(82 + 270 - 16 * 3, 100 - 8 + 38 * 8, ICS01_Voltage_Front, 4, 0, WHITE); //前端电压
    print_SZ_1(82 + 270 - 16 * 3, 100 - 8 + 38 * 9, ICS01_LIFE, 4, 0, WHITE); //LIFE

    print_D(82 + 270 + 320, 100 - 8, ICS01_Status3.bit1, 2, 0, WHITE);
    print_D(82 + 270 + 320, 100 - 8 + 38, ICS01_Status3.bit2, 2, 0, WHITE);
    print_D(82 + 270 + 320, 100 - 8 + 38 * 2, ICS01_Status3.bit3, 2, 0, WHITE);
    print_D(82 + 270 + 320, 100 - 8 + 38 * 3, ICS01_Status3.bit4, 2, 0, WHITE);
    print_D(82 + 270 + 320, 100 - 8 + 38 * 4, ICS01_Status4.bit1, 2, 0, WHITE);
    print_D(82 + 270 + 320, 100 - 8 + 38 * 5, ICS01_Status4.bit2, 2, 0, WHITE);
    print_D(82 + 270 + 320, 100 - 8 + 38 * 6, ICS01_Status4.bit3, 2, 0, WHITE);
    print_D(82 + 270 + 320, 100 - 8 + 38 * 7, ICS01_Status4.bit4, 2, 0, WHITE);
    print_SZ_1(82 + 270 - 16 * 3 + 320, 100 - 8 + 38 * 8, ICS01_Voltage_Front, 4, 0, WHITE); //前端电压
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
        frmID = 1;
        f_index = 0;
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

/*void AirFrame(void) {
    unsigned char i = 0;
    LCD_Clear();
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //顶部横线
    LCD_DrawImage1BPP(130 + 200 - 2, 130 - 85, BMP_Gaoya, WHITE, BLACK); //高压
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
    //LCD_DrawImage1BPP(82 + 42 + 42 + 42 + 2, 100 + 5, BMP_Maohao, WHITE, BLACK); //:

    LCD_DrawImage1BPP(82, 100 + 38, BMP_Kongtiao, WHITE, BLACK); //空调
    LCD_DrawImage1BPP(82 + 42, 100 + 38, BMP_Feng, WHITE, BLACK); //风
    LCD_DrawImage1BPP(82 + 42 + 21, 100 + 38, BMP_DJ, WHITE, BLACK); //电机
    LCD_DrawImage1BPP(82 + 42 + 21 + 21, 100 + 38, BMP_Zhuangtai, WHITE, BLACK); //状态
    //LCD_DrawImage1BPP(82 + 42 + 21 + 21 + 42 + 2, 100 + 5 + 38, BMP_Maohao, WHITE, BLACK); //:

    LCD_DrawImage1BPP(82, 100 + 38 * 2, BMP_Kongtiao, WHITE, BLACK); //空调
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 2, BMP_Gongzuo, WHITE, BLACK); //工作
    LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 2, BMP_Zhuangtai, WHITE, BLACK); //状态
    //LCD_DrawImage1BPP(82 + 42 + 42 + 42 + 2, 100 + 5 + 38 * 2, BMP_Maohao, WHITE, BLACK); //:


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
    //LCD_DrawImage1BPP(82 + 320 + 42 + 42 + 42 + 2, 100 + 5 + 38, BMP_Maohao, WHITE, BLACK); //:
    LCD_DrawImage1BPP(720 - 28, 100 + 38, BMP_T, WHITE, BLACK); //℃


    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 2, BMP_Sheding, WHITE, BLACK); //设定
    LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 2, BMP_Wendu, WHITE, BLACK); //温度
    //LCD_DrawImage1BPP(82 + 320 + 42 + 42 + 2, 100 + 5 + 38 * 2, BMP_Maohao, WHITE, BLACK); //:
    LCD_DrawImage1BPP(720 - 28, 100 + 38 * 2, BMP_T, WHITE, BLACK); //℃

}

void AirUpdate(void) {
    
    print_D(82 + 180, 100 - 8, Air_Status_Flag1); //空调故障码
    print_D(82 + 180, 100 - 8 + 38, Air_Status_Flag2); //空调风速
    print_D(82 + 180, 100 - 8 + 38 * 2, Air_Status_Flag3); //空调状态
    //print_SZ_1(82 + 270 - 10, 100 - 8 + 38 * 3, AC_LIFE, 3, 0, WHITE); //空调LIFE
    updata_T(82 + 63 + 42 + 80 + 32 + 320, 100 - 8, WHITE, Air_Indoor_t, 0.5, 30); //室内温度
    updata_T(82 + 63 + 42 + 80 + 32 + 320, 100 - 8 + 38, WHITE, Air_Outdoor_t, 0.5, 30); //室外温度
    updata_T(82 + 63 + 42 + 80 + 32 + 320, 100 - 8 + 38 * 2, WHITE, Air_Set_t, 0.5, 30); //设定温度
    //print_D(82 + 180 + 320, 100 - 8 + 38 * 3, AC_req); //空调请求
     
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
        frmID = 1;
        f_index = 0;
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

}*/

/******************************************************/
void TaiyaFrame(unsigned char index) {
    unsigned char i = 0;
    LCD_Clear();
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //顶部横线
    LCD_DrawImageSBPP(130 + 200 - 2, 130 - 85, 50, Luntai_SYSTEM, WHITE, BLACK); //胎压

    LCD_DrawRect(80, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320 + 320, 90, 1, 380, GREEN);
    for (i = 0; i < 11; i++)
        LCD_DrawRect(80, 90 + i * 38, 640, 1, GREEN);

    print_SZ_2(750, 50, index, 1, 0, WHITE); // i/3
    LCD_DrawImage1BPP(750 + 11, 50, BMP_I, WHITE, BLACK);
    print_SZ_2(750 + 11 + 14, 50, 3, 1, 0, WHITE);

    for (i = 0; i < 2; i++) {
        LCD_DrawImage1BPP(82 + 320 * i, 100, BMP_Luntai, WHITE, BLACK); //轮胎位置
        LCD_DrawImage1BPP(82 + 320 * i + 42, 100, BMP_Weizhi, WHITE, BLACK);

        LCD_DrawImage1BPP(82 + 320 * i, 100 + 38, BMP_Luntai, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 320 * i + 42, 100 + 38, BMP_Yali, WHITE, BLACK); //轮胎压力
        LCD_DrawImage1BPP(400 + 320 * i - 24 - 11 - 11, 100 - 2 + 38 * 1, BMP_b, WHITE, BLACK); //BAR
        LCD_DrawImage1BPP(400 + 320 * i - 24 - 11, 100 - 2 + 38 * 1, BMP_a, WHITE, BLACK); //
        LCD_DrawImage1BPP(400 + 320 * i - 24, 100 - 2 + 38 * 1, BMP_r, WHITE, BLACK); //

        LCD_DrawImage1BPP(82 + 320 * i, 100 + 38 * 2, BMP_Luntai, WHITE, BLACK); //轮胎温度
        LCD_DrawImage1BPP(82 + 320 * i + 42, 100 + 38 * 2, BMP_Wendu, WHITE, BLACK); //
        LCD_DrawImage1BPP(400 + 320 * i - 28, 100 + 38 * 2, BMP_T, WHITE, BLACK);

        LCD_DrawImage1BPP(82 + 320 * i, 100 + 38 * 3, BMP_Luntai, WHITE, BLACK); //轮胎信号报警
        LCD_DrawImage1BPP(82 + 320 * i + 42, 100 + 38 * 3, BMP_Xinhao, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 320 * i + 42 + 42, 100 + 38 * 3, BMP_Baojing, WHITE, BLACK); //

        LCD_DrawImage1BPP(82 + 320 * i, 100 + 38 * 4, BMP_Luntai, WHITE, BLACK); //轮胎漏气报警
        LCD_DrawImage1BPP(82 + 320 * i + 42, 100 + 38 * 4, BMP_Louqi, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 320 * i + 42 + 42, 100 + 38 * 4, BMP_Baojing, WHITE, BLACK); //

        LCD_DrawImage1BPP(82 + 320 * i, 100 + 38 * 5, BMP_Luntai, WHITE, BLACK); //轮胎高温报警
        LCD_DrawImage1BPP(82 + 320 * i + 42, 100 + 38 * 5, BMP_Gao, WHITE, BLACK); //       
        LCD_DrawImage1BPP(82 + 320 * i + 42 + 21, 100 + 38 * 5, BMP_Wendu, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 320 * i + 42 + 42, 100 + 38 * 5, BMP_Baojing, WHITE, BLACK); //

        LCD_DrawImage1BPP(82 + 320 * i, 100 + 38 * 6, BMP_Qiya, WHITE, BLACK); //气压降低速率
        LCD_DrawImage1BPP(82 + 320 * i + 42, 100 + 38 * 6, BMP_Jiangdi, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 320 * i + 42 + 42, 100 + 38 * 6, BMP_Sulv, WHITE, BLACK); //
        LCD_DrawImage1BPP(400 + 320 * i - 24 - 11 - 11 - 11 - 11, 100 - 2 + 38 * 6, BMP_b, WHITE, BLACK); //BAR/S
        LCD_DrawImage1BPP(400 + 320 * i - 24 - 11 - 11 - 11, 100 - 2 + 38 * 6, BMP_a, WHITE, BLACK); //
        LCD_DrawImage1BPP(400 + 320 * i - 24 - 11 - 11, 100 - 2 + 38 * 6, BMP_r, WHITE, BLACK); //
        LCD_DrawImage1BPP(400 + 320 * i - 24 - 11, 100 - 2 + 38 * 6, BMP_I, WHITE, BLACK); //
        LCD_DrawImage1BPP(400 + 320 * i - 24, 100 - 2 + 38 * 6, BMP_s, WHITE, BLACK); //

        LCD_DrawImage1BPP(82 + 320 * i, 100 + 38 * 7, BMP_Qiya, WHITE, BLACK); //气压报警等级
        LCD_DrawImage1BPP(82 + 320 * i + 42, 100 + 38 * 7, BMP_Baojing, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 320 * i + 42 + 42, 100 + 38 * 7, BMP_Dengji, WHITE, BLACK); //  
    }
}

void TaiyaUpdate(unsigned char index) {
    unsigned char i = 0, j = 0, index1 = 1;
    for (j = 0; j < 2; j++) {
        if (index == 3) {
            index1 = 2;
            i = j + 2;
        } else {
            i = j;
            index1 = index;
        }
        print_H(82 + 320 * j + 180 - 5 + 16, 100 - 8, TireLocation[index1 - 1][i], 2, 0, WHITE);
        print_SZ_1(82 + 320 * j + 180 - 5 - 16 * 1, 100 - 8 + 38 * 1, TirePressure[index1 - 1][i] * 6.3 / 10, 3, 1, WHITE); //胎压
        updata_DAT(82 + 320 * j + 180 - 5, 100 - 8 + 38 * 2, TireTemperature[index1 - 1][i] / 32, 1, 273, WHITE, 3, 0);

        if (TireFault[index1 - 1][i].bit2 == 0) {
            LCD_DrawImage1BPP(82 + 320 * j + 180 - 5, 100 + 38 * 3, BMP_Zhengchang, GREEN, BLACK);
        } else if (TireFault[index1 - 1][i].bit2 == 1) {
            LCD_DrawImage1BPP(82 + 320 * j + 180 - 5, 100 + 38 * 3, BMP_Guzhang, RED, BLACK);
        }

        if (TireFault[index1 - 1][i].bit3 == 0) {
            LCD_DrawImage1BPP(82 + 320 * j + 180 - 5, 100 + 38 * 4, BMP_Zhengchang, GREEN, BLACK);
        } else if (TireFault[index1 - 1][i].bit3 == 1) {
            LCD_DrawImage1BPP(82 + 320 * j + 180 - 5, 100 + 38 * 4, BMP_Louqi, RED, BLACK);
        }

        if (TireFault[index1 - 1][i].bit4 == 0) {
            LCD_DrawImage1BPP(82 + 320 * j + 180 - 5, 100 + 38 * 5, BMP_Zhengchang, GREEN, BLACK);
        } else if (TireFault[index1 - 1][i].bit4 == 1) {
            LCD_DrawImage1BPP(82 + 320 * j + 180 - 5, 100 + 38 * 5, BMP_Baojing, RED, BLACK);
        }

        print_SZ_1(82 + 320 * j + 180 - 5 - 16 * 0, 100 - 8 + 38 * 6, TireAirLeakageRate[index1 - 1][i] * 0.1 / 100, 3, 2, WHITE); //漏气速度

        if (TirePressureThresholdDetection[index1 - 1][i] == 2) {
            LCD_DrawImage1BPP(82 + 320 * j + 180 - 5, 100 + 38 * 7, BMP_Zhengchang, GREEN, BLACK);
        } else if (TirePressureThresholdDetection[index1 - 1][i] == 3) {
            LCD_DrawImage1BPP(82 + 320 * j + 180 - 5, 100 + 38 * 7, BMP_Diya, YELLOW, BLACK);
        } else if (TirePressureThresholdDetection[index1 - 1][i] == 4) {
            LCD_DrawImageSBPP(82 + 320 * j + 180 - 5, 100 + 38 * 7, 21, GD, RED, BLACK);
        }
    }
}

void frmTaiya(void) {
    static unsigned char index_Taiya = 1;
    if (f_index == 0) { //只更新一次
        f_index = 1;
        TaiyaFrame(index_Taiya);
    } else if (f_index == 1) {
        f_index = 1;
        TaiyaUpdate(index_Taiya);
    } else {
        f_index = 0;
    }
    if (key_up) {
        key_up = 0;
        index_Taiya++;
        f_index = 0;
        if (index_Taiya == 4) {
            index_Taiya = 1;
            frmID = 1;
        }
    }

    if (key_AV) {
        key_AV = 0;
        index_Taiya--;
        f_index = 0;
        if (index_Taiya == 0) {
            index_Taiya = 1;
            frmID = 1;
        }
    }

    if (key_set) {//返回主界面
        key_set = 0;
        frmID = 0;
        f_index = 0;
        Index = 0;
        index_Taiya = 1;
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
    LCD_DrawImage1BPP(405, 190, BMP_HZ_KM, WHITE, BLACK); //单位 Km 
}

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

/******************************************************/

void LCD_Exec(void) {
    switch (frmID) {
        case 0:
            frmMain();
            break;
        case 1:
            frmMenu();
            break;
        case 2:
            frmMOTO();
            break;
        case 3:
            frmDMQ();
            break;
        case 4:
            frmDCDC();
            break;
        case 5:
            frmDMY();
            break;
        case 6:
            frmBMS();
            break;
        case 7:
            frmBattery();
            break;
        case 8:
            frmAir();
            break;
        case 9:
            frmIC();
            break;
        case 10:
            frmSET();
            break;
        case 11:
            frmTaiya();
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



