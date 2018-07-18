#include "APP_System.h"
//include "APP_FONT.h"
#include "APP_LOGO.h"
#include "APP_CHAR.h"

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

void disp_rectange(unsigned int x, unsigned int y, //画方框
        unsigned int w,
        unsigned char wdat,
        unsigned int h,
        unsigned char hdat,
        unsigned char color1) {
    LCD_DrawRect(x, y, w, wdat, color1);
    LCD_DrawRect(x, y + h - wdat, w, wdat, color1);
    LCD_DrawRect(x, y, hdat, h, color1);
    LCD_DrawRect(x + w - hdat, y, hdat, h, color1);
}

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

void BMP_Men_Guan(unsigned int x, unsigned int y, unsigned char color) {
    //门外框
    disp_rectange(x, y, 72, 2, 88, 2, color);
    //门中线
    LCD_DrawRect(x + 36, y + 2, 1, 81, color);
    //门下踏板
    LCD_DrawRect(x + 7, y + 83, 57, 2, color);
    LCD_DrawRect(x + 7, y + 83, 1, 3, color);
    LCD_DrawRect(x + 7 + 56, y + 83, 1, 3, color);
    //门左内框
    disp_rectange(x + 4, y + 3, 30, 2, 78, 2, color);
    //门右内框
    disp_rectange(x + 4 + 35, y + 3, 29, 2, 78, 2, color);
}

void BMP_Men_Kai(unsigned int x, unsigned int y, unsigned char color) {
    //门外框
    disp_rectange(x, y, 72, 2, 88, 2, color);
    //门下踏板
    LCD_DrawRect(x + 7, y + 83, 57, 2, color);
    LCD_DrawRect(x + 7, y + 83, 1, 3, color);
    LCD_DrawRect(x + 7 + 56, y + 83, 1, 3, color);
    //门中线
    LCD_DrawRect(x + 36, y + 2, 1, 81, BLACK);
    //门左内框
    disp_rectange(x + 4, y + 3, 30, 2, 78, 2, BLACK);
    disp_rectange(x + 4 + 35, y + 3, 29, 2, 78, 2, BLACK);
}

void BMP_BUS(unsigned int x, unsigned int y) {
    unsigned char i;
    disp_rectange(x + 209, y, 178, 2, 10, 2, WHITE);

    LCD_DrawRect(x, y + 8, 471, 2, WHITE); //上外框长
    LCD_DrawRect(x, y + 8, 2, 92, WHITE); //外框高
    LCD_DrawImage1BPP(x, y + 8 + 92, Bmp_Xiahuaxian, WHITE, BLACK); //后下划线
    LCD_DrawRect(x + 54, y + 8 + 105, 471 - 54 + 12, 2, WHITE); //下外框长
    LCD_DrawRect(x + 8, y + 8 + 12, 471 - 8, 2, WHITE); //内框长
    LCD_DrawRect(x + 8, y + 8 + 12, 2, 92 - 12, WHITE); //内框高
    LCD_DrawRect(x + 471 + 10, y + 8 + 105 - 34, 2, 34, WHITE); //车头下长

    LCD_DrawImage1BPP(x + 91, y + 76, Bmp_Luntai, WHITE, BLACK); //轮胎1
    LCD_DrawImage1BPP(x + 91 + 227, y + 76, Bmp_Luntai, WHITE, BLACK); //轮胎2

    BMP_Men_Guan(x + 195, y + 27, WHITE);

    BMP_Men_Guan(x + 184 + 215, y + 27, WHITE);

    LCD_DrawImage1BPP(x + 471, y + 6, Bmp_Chetou1, WHITE, BLACK); //车头1
    LCD_DrawImage1BPP(x + 471 + 24, y + 6 + 13, Bmp_Chetou2, WHITE, BLACK); //车头2
    LCD_DrawRect(x + 471 + 12, y + 6 + 13, 12, 2, WHITE);
    LCD_DrawRect(x + 471 + 12, y + 6 + 13 + 5, 12, 2, WHITE);

    //小窗户1
    disp_rectange(x + 8 + 3, y + 8 + 12 + 3, 31, 1, 20, 1, WHITE);

    //小窗户2
    disp_rectange(x + 8 + 3 + 34, y + 8 + 12 + 3, 31, 1, 20, 1, WHITE);

    LCD_DrawRect(x + 8 + 3 + 15, y + 8 + 12 + 3 + 50, 32, 1, WHITE); //散热孔
    LCD_DrawRect(x + 8 + 3 + 15, y + 8 + 12 + 3 + 28 + 50, 32, 1, WHITE); //
    for (i = 0; i < 9; i++) {
        LCD_DrawRect(x + 8 + 3 + 15 + 4 * i, y + 8 + 12 + 3 + 50, 1, 28, WHITE); //
    }

    //中窗户1
    disp_rectange(x + 8 + 3 + 34 + 34, y + 8 + 12 + 3, 53, 1, 46, 1, WHITE);

    //中窗户2
    disp_rectange(x + 8 + 3 + 34 + 34 + 56, y + 8 + 12 + 3, 53, 1, 46, 1, WHITE);

    //前窗户1
    disp_rectange(x + 8 + 3 + 34 + 34 + 56 * 2 + 72 + 10, y + 8 + 12 + 3, 53, 1, 46, 1, WHITE);

    //前窗户
    disp_rectange(x + 8 + 3 + 34 + 34 + 56 * 3 + 72 + 20, y + 8 + 12 + 3, 53, 1, 46, 1, WHITE);
}

void disp_BMP_baojing(void) {
    unsigned char color = GRAY;
    //unsigned char color_mode[3];

    if (IN23) color = YELLOW;
    else color = GRAY;
    if (color_old[0] != color) {
        color_old[0] = color;
        //LCD_DrawImage1BPP(8, 10, Bmp_baojing[1], color, BLACK); //ABS
    }

    if (0) color = RED;
    else color = GRAY;
    if (color_old[1] != color) {
        color_old[1] = color;
        //LCD_DrawImage1BPP(8 + 66, 10, Bmp_baojing[9], color, BLACK); //系统故障
    }

    if (IN2) color = RED;
    else color = GRAY;
    if (color_old[2] != color) {
        color_old[2] = color;
        //LCD_DrawImage1BPP(8 + 66 * 2, 10, Bmp_baojing[3], color, BLACK); //后舱门
    }

    if (BMS_Ready) color = YELLOW;
    else color = RED;
    if (color_old[3] != color) {
        color_old[3] = color;
        LCD_DrawImage1BPP(8 + 66 * 3, 10, Bmp_baojing[13], color, BLACK); //电池就绪
        //LCD_DrawImage1BPP(8 + 66 * 3 + 17, 10 + 15, BMP_l, color, BLACK);
        //print_SZ(8 + 66 * 3 + 17 + 11, 10 + 18, 1, 1, 0, color);
    }

    if (VCU_FAULT) color = RED;
    else color = GRAY;
    if (color_old[4] != color) {
        color_old[4] = color;
        LCD_DrawImage1BPP(8 + 66 * 4, 10, Bmp_baojing[9], color, BLACK); //系统故障
    }

    if (CAR_Ready) color = GREEN;
    else color = GRAY;
    if (color_old[5] != color) {
        color_old[5] = color;
        LCD_DrawImage1BPP(8 + 66 * 5 - 2, 10 + 12, Bmp_READY, color, BLACK); //ready

    }

    if (IN22) color = GREEN;
    else color = GRAY;
    if (color_old[6] != color) {
        color_old[6] = color;
        //LCD_DrawImage1BPP(8 + 66 * 6, 10, Bmp_baojing[8], color, BLACK); //AC空调
        //档位
    }

    if (IN22) color = GREEN;
    else color = GRAY;
    if (color_old[7] != color) {
        color_old[7] = color;
        LCD_DrawImage1BPP(8 + 66 * 7, 10, Bmp_baojing[4], color, BLACK);//AC空调              
        //print_SZ(8 + 66 * 7, 10, 1, 1, 0, YELLOW);
        //LCD_DrawImage1BPP(8 + 66 * 7, 10, Bmp_baojing[7], color, BLACK); //刹车片
        //LCD_DrawImage1BPP(8 + 66 * 7 + 17, 10 + 15, BMP_r, color, BLACK);
        //print_SZ(8 + 66 * 7 + 17 + 11, 10 + 18, 1, 1, 0, color);
    }

    if (MCU_Control_Ready) color = GREEN;
    else color = RED;
    if (color_old[8] != color) {
        color_old[8] = color;
        LCD_DrawImage1BPP(8 + 66 * 8, 10, Bmp_baojing[14], color, BLACK); //电机就绪 
    }

    if (Three_Ready) color = GREEN;
    else color = RED;
    if (color_old[9] != color) {
        color_old[9] = color;
        LCD_DrawImage1BPP(8 + 66 * 9, 10, Bmp_baojing[15], color, BLACK); //三个一就绪
    }

    if (MCU_Control_High_Temp) color = RED;
    else color = GRAY;
    if (color_old[10] != color) {
        color_old[10] = color;
        //LCD_DrawImage1BPP(8 + 66 * 10, 10, Bmp_baojing[10], color, BLACK); //电机过温
    }

    if (IN24) color = YELLOW;
    else color = GRAY;
    if (color_old[11] != color) {
        color_old[11] = color;
        //LCD_DrawImage1BPP(8 + 66 * 11, 10, Bmp_baojing[0], color, BLACK); //ASR
    }
    /****************************第二行图片****************************************/
    if (ADR[1] < 20) color = YELLOW;
    else color = GRAY;
    if (color_old[12] != color) {
        color_old[12] = color;
        //LCD_DrawImage1BPP(140 + 66 * 0, 74 - 5, Bmp_baojing[12], color, BLACK); //油量报警
    }

    /*if (Tradition && !Hybrid && !Electric) color = GREEN;
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
            LCD_DrawImage1BPP(138 + 9, 74, BMP_Chadian, color, BLACK); //插电
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
    }*/

    if (!IN21) color = RED;
    else color = GRAY;
    if (color_old[13] != color) {
        color_old[13] = color;
        //LCD_DrawImage1BPP(140 + 66 * 1, 74 - 5, Bmp_baojing[7], color, BLACK); //左后刹车片
        //LCD_DrawImage1BPP(140 + 66 * 1 + 19, 74 - 5 + 15, BMP_l, color, BLACK);
        //print_SZ(140 + 66 * 1 + 19 + 11, 74 - 5 + 18, 2, 1, 0, color);
    }

    if (IN26) color = RED;
    else color = GRAY;
    if (color_old[14] != color) {
        color_old[14] = color;
        //LCD_DrawImage1BPP(140 + 66 * 2, 74 - 5, Bmp_baojing[11], color, BLACK); //应急阀
    }

    if (CAR_Ready) color = GREEN;
    else color = GRAY;
    if (color_old[15] != color) {
        color_old[15] = color;
        //LCD_DrawImage1BPP(138 + 66 * 3 - 1, 74 + 12, Bmp_READY, color, BLACK); //ready
    }

    if (0) color = RED;
    else color = GRAY;
    if (color_old[16] != color) {
        color_old[16] = color;
        //档位
    }

    if (!IN22) color = RED;
    else color = GRAY;
    if (color_old[17] != color) {
        color_old[17] = color;
        //LCD_DrawImage1BPP(140 + 66 * 5, 74 - 5, Bmp_baojing[7], color, BLACK); //右后刹车片
        //LCD_DrawImage1BPP(140 + 66 * 5 + 19, 74 - 5 + 15, BMP_r, color, BLACK);
        //print_SZ(140 + 66 * 5 + 19 + 11, 74 - 5 + 18, 2, 1, 0, color);
    }

    if (IN20) color = YELLOW;
    else color = GRAY;
    if (color_old[18] != color) {
        color_old[18] = color;
        //SERVICE
        //LCD_DrawImage1BPP(138 + 9 + 66 * 6, 74 - 5, BMP_Bangzhu, color, BLACK); //服务
        //LCD_DrawImage1BPP(138 + 9 + 66 * 6, 74 - 5 + 22, BMP_Qingqiu, color, BLACK); //请求

    }

}

void disp_FONT_baojing(unsigned int x, unsigned int y) {
    static unsigned char al_index = 0, Comm_i[6], FLAG;
    if (alarm_update_flag == 0) { //3S 更新一次 
        switch (al_index) {
            case 0:
                al_index = 1;
                if (Fcan_count == CAN_TIME) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Qianbu, YELLOW, BLACK); //前部
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Mokuai, YELLOW, BLACK); //模块
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Lixian, YELLOW, BLACK); //离线
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 1:
                al_index = 2;
                /*if (Mcan_count == CAN_TIME) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Dingbu, YELLOW, BLACK); //顶部
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Mokuai, YELLOW, BLACK); //模块
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Lixian, YELLOW, BLACK); //离线
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/

            case 2:
                al_index = 3;
                /*if (Rcan_count == CAN_TIME) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Houbu, YELLOW, BLACK); //后部
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Mokuai, YELLOW, BLACK); //模块
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Lixian, YELLOW, BLACK); //离线
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
            case 3:
                al_index = 4;
                if (BMS_Fault) {
                    LCD_DrawImageSBPP(x, y + 8, 11, BMS, YELLOW, BLACK); //BMS故障
                    LCD_DrawImage1BPP(x + 11 + 11 + 11, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 11 + 11 + 11 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 4:
                al_index = 5;
                if (BAT_High_Temp) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DC, YELLOW, BLACK); //电池高温报警
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Gao, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 21, y + 8, BMP_Wendu, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
            case 5:
                al_index = 6;
                if (MCU_Control_High_Temp) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DJ, YELLOW, BLACK); //电机控制器高温故障
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_KZQ, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 63, y + 8, BMP_Gao, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 63 + 21, y + 8, BMP_Wendu, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 63 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 63 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 6:
                al_index = 7;
                if (BAT24V_count == BAT24_TIME) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Xu, YELLOW, BLACK); //蓄电池电压低
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_DC, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 42, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 42 + 42, y + 8, BMP_Di, YELLOW, BLACK);
                    LCD_DrawRect(x + 21 + 42 + 42 + 21, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 7:
                al_index = 8;
                if (BAT_Low_Temp) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DC, YELLOW, BLACK); //电池低温故障
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Di, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 21, y + 8, BMP_Wendu, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 8:
                al_index = 9;
                /*if (Pack_Bat_UnderVoltage) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DC, YELLOW, BLACK); //电池组欠压报警
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Zu, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 21, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 21, y + 8, BMP_Qian, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 21 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 21 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
            case 9:
                al_index = 10;
                /*if (Single_Bat_UnderVoltage) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Dan, YELLOW, BLACK); //单体欠压报警
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_Ti, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Qian, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
            case 10:
                al_index = 11;
                if (Charging_High_Temp) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Chong, YELLOW, BLACK); //充电机高温报警
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_DJ, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 63, y + 8, BMP_Gao, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 63 + 21, y + 8, BMP_Wendu, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 63 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 63 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
            case 11:
                al_index = 12;
                if (SPEED > 69) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Chaosu, YELLOW, BLACK); //超速报警
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
            case 12:
                al_index = 13;
                if (BAT_OverCurrent) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DC, YELLOW, BLACK); //电池电流过高故障
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_DL, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 21, y + 8, BMP_Gao, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
            case 13:
                al_index = 14;
                if (Three_Fault) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Sanheyi, YELLOW, BLACK); //三合一控制器故障
                    LCD_DrawImage1BPP(x + 63, y + 8, BMP_KZQ, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 63 + 63, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 63 + 63 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
            case 14:
                al_index = 15;
                if (BAT_Voltage_Diff) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DC, YELLOW, BLACK); //电池电压差异故障
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Chayi, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
            case 15:
                al_index = 16;
                /*if (Diff_Temp) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Wendu, YELLOW, BLACK); //温度差异报警
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Chayi, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/

            case 16:
                al_index = 17;
                if (AirPress_Low) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Qiya, YELLOW, BLACK); //气压低故障
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Di, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 21, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 21 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 17:
                al_index = 18;
                if (AirMoto_Fault) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Qibeng, YELLOW, BLACK); //气泵电机故障
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_DJ, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 18:
                al_index = 19;
                if (SwitchMoto_Fault) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_IC_Zhuanxiang, YELLOW, BLACK); //转向电机故障
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_DJ, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 19:
                al_index = 20;
                /*if (Bat_LowTemp) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DC, YELLOW, BLACK); //电池低温报警
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Di, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 21, y + 8, BMP_Wendu, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/

            case 20:
                al_index = 21;
                if (FPower_Fault) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Fuzhu, YELLOW, BLACK); //辅助电源故障
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Dianyuan, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 21:
                al_index = 22;
                /*if (BAT_COOL_FAULT) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DC, YELLOW, BLACK); //电池冷却系统故障
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Lengque, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_System, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/

            case 22:
                al_index = 23;
                /*if (WARN_FAULT) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Jiare, YELLOW, BLACK); //加热故障
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42, y, 150, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/

            case 23:
                al_index = 24;
                /*if (BALANCE_FAULT) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Junheng, YELLOW, BLACK); //均衡报警
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/

            case 24:
                al_index = 25;
                /*if (PRECHARGE_FAULT) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Chong, YELLOW, BLACK); //充电报警
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/

            case 25:
                al_index = 26;
                if (Charging_Link_Fault) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Chong, YELLOW, BLACK); //充电机连接故障
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_DJ, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 63, y + 8, BMP_Lianjie, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 63 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 63 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 26:
                al_index = 27;
                if (Charging_Fault) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Chong, YELLOW, BLACK); //充电机故障
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_DJ, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 63, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 63 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 27:
                al_index = 28;
                /*if (BAT_FAULT || Bat_Fault) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Dongli, YELLOW, BLACK); //动力电池故障
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_DC, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/

            case 28:
                al_index = 29;
                /*if (VOLTAGE_DIFF_FAULT) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Zhilu, YELLOW, BLACK); //支路电压差异报警
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Chayi, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/

            case 29:
                al_index = 30;
                /*if (FIRE_FAULT) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Huozai, YELLOW, BLACK); //火灾极限报警
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Jixian, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/

            case 30:
                al_index = 31;
                /*if (SYSTEM_MISMATCH) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Chunnengxitong, YELLOW, BLACK); //储能系统不匹配
                    LCD_DrawRect(x + 147, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/

            case 31:
                al_index = 32;
                /*if (SOC_JUMP) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_s, YELLOW, BLACK); //SOC跳变
                    LCD_DrawImage1BPP(x + 11, y + 8, BMP_o, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11, y + 8, BMP_c, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11 + 11, y + 8, BMP_Tiaobian, YELLOW, BLACK);
                    LCD_DrawRect(x + 11 + 11 + 11 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/

            case 32:
                al_index = 33;
                /*if (BAT_CELL_COLT_OFFLINE) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Dan, YELLOW, BLACK); //单体过压采集离线
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_Ti, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Caiji, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 42, y + 8, BMP_Lixian, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/

            case 33:
                al_index = 34;
                /*if (TEMP_COLT_OFFLINE) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Wendu, YELLOW, BLACK); //温度采集离线                   
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Caiji, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Lixian, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/

            case 34:
                al_index = 35;
                if (MCU_Control_Fault) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DJ, YELLOW, BLACK); //电机控制器故障
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_KZQ, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 63, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 63 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 35:
                al_index = 36;
                for (; Comm_i[0] < 20 && !FLAG; Comm_i[0]++) {
                    if (BAT_Fault[Comm_i[0]].bit1 & 0x01) {
                        FLAG = 1;
                    }
                }               
                if (FLAG) {
                    FLAG = 0;
                    LCD_DrawRect(x, y, 200, 36, BLACK); //清除显示区域
                    LCD_DrawImage1BPP(x, y + 8, BMP_DC, YELLOW, BLACK); //电池模块x电压过高报警                   
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Mokuai, YELLOW, BLACK);
                    print_SZ(x + 42 + 42, y + 12, Comm_i[0], 2, 0, YELLOW);
                    LCD_DrawImage1BPP(x + 42 + 42 + 16, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 16 + 42, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 16 + 42 + 21, y + 8, BMP_Gao, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 16 + 42 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 16 + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
                if(Comm_i[0] >= 20){
                    Comm_i[0] = 0;
                }

            case 36:
                al_index = 37;
                for (; Comm_i[1] < 20 && !FLAG; Comm_i[1]++) {
                    if (BAT_Fault[Comm_i[1]].bit2 & 0x01) {
                        FLAG = 1;
                    }
                }                
                if (FLAG) {
                    FLAG = 0;
                    LCD_DrawRect(x, y, 200, 36, BLACK); //清除显示区域
                    LCD_DrawImage1BPP(x, y + 8, BMP_DC, YELLOW, BLACK); //电池模块x电压过低报警                   
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Mokuai, YELLOW, BLACK);
                    print_SZ(x + 42 + 42, y + 12, Comm_i[1], 2, 0, YELLOW);
                    LCD_DrawImage1BPP(x + 42 + 42 + 16, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 16 + 42, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 16 + 42 + 21, y + 8, BMP_Di, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 16 + 42 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 16 + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
                if(Comm_i[1] >= 20){
                    Comm_i[1] = 0;
                }

            case 37:
                al_index = 38;
                for (; Comm_i[2] < 20 && !FLAG; Comm_i[2]++) {
                    if (BAT_Fault[Comm_i[2]].bit3 & 0x01) {
                        FLAG = 1;
                    }
                }                
                if (FLAG) {
                    FLAG = 0;
                    LCD_DrawRect(x, y, 200, 36, BLACK); //清除显示区域
                    LCD_DrawImage1BPP(x, y + 8, BMP_DC, YELLOW, BLACK); //电池模块x温度过高报警                   
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Mokuai, YELLOW, BLACK);
                    print_SZ(x + 42 + 42, y + 12,  Comm_i[2], 2, 0, YELLOW);
                    LCD_DrawImage1BPP(x + 42 + 42 + 16, y + 8, BMP_Wendu, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 16 + 42, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 16 + 42 + 21, y + 8, BMP_Gao, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 16 + 42 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 16 + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
                if(Comm_i[2] >= 20){
                    Comm_i[2] = 0;
                }

            case 38:
                al_index = 39;
                for (; Comm_i[3] < 20 && !FLAG; Comm_i[3]++) {
                    if (BAT_Fault[Comm_i[3]].bit4 & 0x01) {
                        FLAG = 1;
                    }
                }               
                if (FLAG) {
                    FLAG = 0;
                    LCD_DrawRect(x, y, 200, 36, BLACK); //清除显示区域
                    LCD_DrawImage1BPP(x, y + 8, BMP_DC, YELLOW, BLACK); //电池模块x温度过低报警                   
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Mokuai, YELLOW, BLACK);
                    print_SZ(x + 42 + 42, y + 12,  Comm_i[3], 2, 0, YELLOW);
                    LCD_DrawImage1BPP(x + 42 + 42 + 16, y + 8, BMP_Wendu, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 16 + 42, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 16 + 42 + 21, y + 8, BMP_Di, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 16 + 42 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 16 + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
                if(Comm_i[3] >= 20){
                    Comm_i[3] = 0;
                }

            case 39:
                al_index = 40;
                /*if (BAT24V_count == BAT24_TIME) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Xu, YELLOW, BLACK); //蓄电池电压低
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_DC, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 42, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 42 + 42, y + 8, BMP_Di, YELLOW, BLACK);
                    LCD_DrawRect(x + 21 + 42 + 42 + 21, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/

            case 40:
                al_index = 41;
                for (; Comm_i[4] < 20 && !FLAG; Comm_i[4]++) {
                    if (BAT_Fault[Comm_i[4]].bit5 & 0x01) {
                        FLAG = 1;
                    }
                }                
                if (FLAG) {
                    FLAG = 0;
                    LCD_DrawRect(x, y, 200, 36, BLACK); //清除显示区域
                    LCD_DrawImage1BPP(x, y + 8, BMP_DC, YELLOW, BLACK); //电池模块x电压过高报警                   
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Mokuai, YELLOW, BLACK);
                    print_SZ(x + 42 + 42, y + 12,  Comm_i[4], 2, 0, YELLOW);
                    LCD_DrawImage1BPP(x + 42 + 42 + 16, y + 8, BMP_DL, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 16 + 42, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 16 + 42 + 21, y + 8, BMP_Gao, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 16 + 42 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 16 + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
                if(Comm_i[4] >= 20){
                    Comm_i[4] = 0;
                }

            case 41:
                al_index = 42;
                for (; Comm_i[5] < 20 && !FLAG; Comm_i[5]++) {
                    if (BAT_Fault[Comm_i[5]].bit6 & 0x01) {
                        FLAG = 1;
                    }
                }               
                if (FLAG) {
                    FLAG = 0;
                    LCD_DrawRect(x, y, 200, 36, BLACK); //清除显示区域
                    LCD_DrawImage1BPP(x, y + 8, BMP_DC, YELLOW, BLACK); //电池模块x差异过高报警                   
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Mokuai, YELLOW, BLACK);
                    print_SZ(x + 42 + 42, y + 12,  Comm_i[5], 2, 0, YELLOW);
                    LCD_DrawImage1BPP(x + 42 + 42 + 16, y + 8, BMP_Chayi, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 16 + 42, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 16 + 42 + 21, y + 8, BMP_Gao, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 16 + 42 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 16 + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
                if(Comm_i[5] >= 20){
                    Comm_i[5] = 0;
                }

            case 42:
                al_index = 43;
                if (VCU_FAULT) {//整车故障
                    LCD_DrawImage1BPP(x, y + 8, BMP_Zhengche, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 43:
                al_index = 44;
                /*if (MCU_Code > 0) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_m, YELLOW, BLACK); //MCU系?故障
                    LCD_DrawImage1BPP(x + 11, y + 8, BMP_c, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11, y + 8, BMP_u, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11 + 11, y + 8, BMP_System, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11 + 11 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    print_SZ_2(x + 11 + 11 + 11 + 42 + 42, y + 8, MCU_Code, 3, 0, YELLOW);
                    LCD_DrawRect(x + 11 + 11 + 11 + 42 + 42 + 48, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/

            case 44:
                al_index = 45;
                /*if (OILDCAC_Status.bit2) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Youbeng, YELLOW, BLACK); //油泵系?故障
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_System, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/

            case 45:
                al_index = 46;
                /*if (AIRDCAC_Status.bit2) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Qibeng, YELLOW, BLACK); //气泵系?故障
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_System, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/

            case 46:
                al_index = 47;
                /*if (AC_Fault_Code > 0) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Kongtiao, YELLOW, BLACK); //空调系?故障
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_System, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/

            case 47:
                al_index = 48;
                /*if (DCDC_Status == 2) {
                    LCD_DrawImage1BPP(x, y + 8 - 2, BMP_DCDC, YELLOW, BLACK); //DCDC系?故障
                    LCD_DrawImage1BPP(x + 65, y + 8, BMP_System, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 65 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 65 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
            default:
                al_index = 0;
                LCD_DrawRect(x, y, 300, 36, BLACK); //清除显示区域
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
#if 0

void BMP_Men_Guan(unsigned int x, unsigned int y, unsigned char color) {
    //门外框
    disp_rectange(x, y, 72, 2, 88, 2, color);
    /*LCD_DrawRect(x, y, 72, 2, color);
    LCD_DrawRect(x, y + 86, 72, 2, color);
    LCD_DrawRect(x, y, 2, 88, color);
    LCD_DrawRect(x + 70, y, 2, 88, color);*/
    //门中线
    LCD_DrawRect(x + 36, y + 2, 1, 81, color);
    //门下踏板
    LCD_DrawRect(x + 7, y + 83, 57, 2, color);
    LCD_DrawRect(x + 7, y + 83, 1, 3, color);
    LCD_DrawRect(x + 7 + 56, y + 83, 1, 3, color);

    //门左内框
    /*LCD_DrawRect(x + 4, y + 3, 29, 2, color);
    LCD_DrawRect(x + 4, y + 3 + 77, 29, 2, color);
    LCD_DrawRect(x + 3, y + 4, 2, 76, color);
    LCD_DrawRect(x + 3 + 30, y + 4, 2, 76, color);*/
    disp_rectange(x + 4, y + 3, 30, 2, 78, 2, color);

    //门右内框
    /*LCD_DrawRect(x + 4 + 35, y + 3, 29 - 1, 2, color);
    LCD_DrawRect(x + 4 + 35, y + 3 + 77, 29 - 1, 2, color);
    LCD_DrawRect(x + 3 + 35, y + 4, 2, 76, color);
    LCD_DrawRect(x + 3 + 30 + 35 - 1, y + 4, 2, 76, color);*/
    disp_rectange(x + 4 + 35, y + 3, 29, 2, 78, 2, color);
}

void BMP_Men_Kai(unsigned int x, unsigned int y, unsigned char color) {
    //门外框
    disp_rectange(x, y, 72, 2, 88, 2, color);
    //门下踏板
    LCD_DrawRect(x + 7, y + 83, 57, 2, color);
    LCD_DrawRect(x + 7, y + 83, 1, 3, color);
    LCD_DrawRect(x + 7 + 56, y + 83, 1, 3, color);

    //门中线
    LCD_DrawRect(x + 36, y + 2, 1, 81, BLACK);

    //门左内框
    disp_rectange(x + 4, y + 3, 30, 2, 78, 2, BLACK);

    //门右内框
    //LCD_DrawRect(x + 4 + 35, y + 3, 29 - 1, 2, BLACK);
    //LCD_DrawRect(x + 4 + 35, y + 3 + 77, 29 - 1, 2, BLACK);
    //LCD_DrawRect(x + 3 + 35, y + 4, 2, 76, BLACK);
    //LCD_DrawRect(x + 3 + 30 + 35 - 1, y + 4, 2, 76, color);

    //LCD_DrawRect(x + 3 + 30 + 35 - 1, y + 4, 2, 76, BLACK); 
    //门右内框
    //LCD_DrawRect(x + 4 + 35 + 8, y + 3, 20, 2, color);
    //LCD_DrawRect(x + 4 + 35 + 8, y + 3 + 77, 20, 2, color);
    //LCD_DrawRect(x + 3 + 35 + 8, y + 4, 2, 76, color);

    disp_rectange(x + 4 + 35, y + 3, 29, 2, 78, 2, BLACK);
}

void BMP_BUS(unsigned int x, unsigned int y) {
    unsigned char i;
    /*LCD_DrawRect(x + 209, y, 178, 2, WHITE); //顶部长方形
    LCD_DrawRect(x + 209, y + 8, 176, 2, WHITE);
    LCD_DrawRect(x + 209, y, 2, 8, WHITE);
    LCD_DrawRect(x + 209 + 176, y, 2, 8, WHITE);*/
    disp_rectange(x + 209, y, 178, 2, 10, 2, WHITE);

    LCD_DrawRect(x, y + 8, 471, 2, WHITE); //上外框长
    LCD_DrawRect(x, y + 8, 2, 92, WHITE); //外框高
    LCD_DrawImage1BPP(x, y + 8 + 92, Bmp_Xiahuaxian, WHITE, BLACK); //后下划线
    LCD_DrawRect(x + 54, y + 8 + 105, 471 - 54 + 12, 2, WHITE); //下外框长
    LCD_DrawRect(x + 8, y + 8 + 12, 471 - 8, 2, WHITE); //内框长
    LCD_DrawRect(x + 8, y + 8 + 12, 2, 92 - 12, WHITE); //内框高
    LCD_DrawRect(x + 471 + 10, y + 8 + 105 - 34, 2, 34, WHITE); //车头下长

    LCD_DrawImage1BPP(x + 91, y + 76, Bmp_Luntai, WHITE, BLACK); //轮胎1
    LCD_DrawImage1BPP(x + 91 + 227, y + 76, Bmp_Luntai, WHITE, BLACK); //轮胎2

    //LCD_DrawImage1BPP(x + 195, y + 27, Bmp_Men, WHITE, BLACK); //门1

    BMP_Men_Guan(x + 195, y + 27, WHITE);

    //LCD_DrawImage1BPP(x + 184 + 215, y + 27, Bmp_Men, WHITE, BLACK); //门2

    BMP_Men_Guan(x + 184 + 215, y + 27, WHITE);

    LCD_DrawImage1BPP(x + 471, y + 6, Bmp_Chetou1, WHITE, BLACK); //车头1
    LCD_DrawImage1BPP(x + 471 + 24, y + 6 + 13, Bmp_Chetou2, WHITE, BLACK); //车头2
    LCD_DrawRect(x + 471 + 12, y + 6 + 13, 12, 2, WHITE);
    LCD_DrawRect(x + 471 + 12, y + 6 + 13 + 5, 12, 2, WHITE);


    /*LCD_DrawRect(x + 8 + 3, y + 8 + 12 + 3, 31, 1, WHITE); 
    LCD_DrawRect(x + 8 + 3, y + 8 + 12 + 3 + 20, 31, 1, WHITE); //
    LCD_DrawRect(x + 8 + 3, y + 8 + 12 + 3, 1, 20, WHITE); //
    LCD_DrawRect(x + 8 + 3 + 31, y + 8 + 12 + 3, 1, 20, WHITE); //*/
    //小窗户1
    disp_rectange(x + 8 + 3, y + 8 + 12 + 3, 31, 1, 20, 1, WHITE);

    /*LCD_DrawRect(x + 8 + 3 + 34, y + 8 + 12 + 3, 31, 1, WHITE); //小窗户2
    LCD_DrawRect(x + 8 + 3 + 34, y + 8 + 12 + 3 + 20, 31, 1, WHITE); //
    LCD_DrawRect(x + 8 + 3 + 34, y + 8 + 12 + 3, 1, 20, WHITE); //
    LCD_DrawRect(x + 8 + 3 + 31 + 34, y + 8 + 12 + 3, 1, 20, WHITE); //*/
    //小窗户2
    disp_rectange(x + 8 + 3 + 34, y + 8 + 12 + 3, 31, 1, 20, 1, WHITE);

    LCD_DrawRect(x + 8 + 3 + 15, y + 8 + 12 + 3 + 50, 32, 1, WHITE); //散热孔
    LCD_DrawRect(x + 8 + 3 + 15, y + 8 + 12 + 3 + 28 + 50, 32, 1, WHITE); //
    for (i = 0; i < 9; i++) {
        LCD_DrawRect(x + 8 + 3 + 15 + 4 * i, y + 8 + 12 + 3 + 50, 1, 28, WHITE); //
    }
    //LCD_DrawRect(150 + 8 + 3 + 35+15, 150 + 8 + 12 + 3+50, 1, 28, YELLOW); //

    /*LCD_DrawRect(x + 8 + 3 + 34 + 34, y + 8 + 12 + 3, 53, 1, WHITE); //中窗户1
    LCD_DrawRect(x + 8 + 3 + 34 + 34, y + 8 + 12 + 3 + 46, 53, 1, WHITE); //
    LCD_DrawRect(x + 8 + 3 + 34 + 34, y + 8 + 12 + 3, 1, 46, WHITE); //
    LCD_DrawRect(x + 8 + 3 + 33 + 34 + 53, y + 8 + 12 + 3, 1, 46, WHITE); */
    //中窗户1
    disp_rectange(x + 8 + 3 + 34 + 34, y + 8 + 12 + 3, 53, 1, 46, 1, WHITE);

    /*LCD_DrawRect(x + 8 + 3 + 34 + 34 + 56, y + 8 + 12 + 3, 53, 1, WHITE); //中窗户2
    LCD_DrawRect(x + 8 + 3 + 34 + 34 + 56, y + 8 + 12 + 3 + 46, 53, 1, WHITE); //
    LCD_DrawRect(x + 8 + 3 + 34 + 34 + 56, y + 8 + 12 + 3, 1, 46, WHITE); //
    LCD_DrawRect(x + 8 + 3 + 33 + 34 + 53 + 56, y + 8 + 12 + 3, 1, 46, WHITE); */
    //中窗户2
    disp_rectange(x + 8 + 3 + 34 + 34 + 56, y + 8 + 12 + 3, 53, 1, 46, 1, WHITE);

    /*LCD_DrawRect(x + 8 + 3 + 34 + 34 + 56 * 2 + 72 + 10, y + 8 + 12 + 3, 53, 1, WHITE); //前窗户1
    LCD_DrawRect(x + 8 + 3 + 34 + 34 + 56 * 2 + 72 + 10, y + 8 + 12 + 3 + 46, 53, 1, WHITE); //
    LCD_DrawRect(x + 8 + 3 + 34 + 34 + 56 * 2 + 72 + 10, y + 8 + 12 + 3, 1, 46, WHITE); //
    LCD_DrawRect(x + 8 + 3 + 33 + 34 + 53 + 56 * 2 + 72 + 10, y + 8 + 12 + 3, 1, 46, WHITE); */
    //前窗户1
    disp_rectange(x + 8 + 3 + 34 + 34 + 56 * 2 + 72 + 10, y + 8 + 12 + 3, 53, 1, 46, 1, WHITE);

    /*LCD_DrawRect(x + 8 + 3 + 34 + 34 + 56 * 3 + 72 + 20, y + 8 + 12 + 3, 53, 1, WHITE); //前窗户2
    LCD_DrawRect(x + 8 + 3 + 34 + 34 + 56 * 3 + 72 + 20, y + 8 + 12 + 3 + 46, 53, 1, WHITE); //
    LCD_DrawRect(x + 8 + 3 + 34 + 34 + 56 * 3 + 72 + 20, y + 8 + 12 + 3, 1, 46, WHITE); //
    LCD_DrawRect(x + 8 + 3 + 33 + 34 + 53 + 56 * 3 + 72 + 20, y + 8 + 12 + 3, 1, 46, WHITE); */
    //前窗户
    disp_rectange(x + 8 + 3 + 34 + 34 + 56 * 3 + 72 + 20, y + 8 + 12 + 3, 53, 1, 46, 1, WHITE);
}
#endif

void updata_GEAR(unsigned int x, unsigned int y) {
    //unsigned char gear = 1;
    if (IN34) GEAR = 0;
    else if (IN35) GEAR = 2;
    else if (IN33) GEAR = 1;
    else GEAR = 0;
    LCD_DrawImage1BPP(x, y, BMP_DANGWEI[GEAR], GREEN, BLACK); //档位更新   
}

void updata_SOC(unsigned int x, unsigned int y) {
    unsigned char color = WHITE;
    static unsigned char soc = 100;
    soc = BMS_SOC;
    /*if(F_DISP && (soc < BMS_SOC * 0.4)){//带增加的效果
        F_DISP=0;
        soc++;
    }
    if(F_DISP && (soc > BMS_SOC * 0.4)){
        F_DISP=0;
        soc--;
    }*/
    if (soc >= 100) soc = 100;
    if (soc > 25) color = GREEN;
    else if (soc > 0 && soc <= 25) color = RED;
    else color = BLACK;
    print_SZ_1(x, y, soc, 3, 0, WHITE); //SOC数值
    LCD_DrawRect(x - 360 + 2, y + 2, (soc * 3.31), 28, color); // 331/100  
    if (soc < 100)//当soc为100时会出错//此时函数溢出
        LCD_DrawRect((x - 360 + 2 + soc * 3.31), y + 2, (331 - soc * 3.31), 28, BLACK);
}

void updata_DCDY(unsigned int x, unsigned int y) {
    //unsigned char color = GREEN;
    unsigned int DCDY = 50;
    DCDY = BMS_V;
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
    DCDL = BMS_A;
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

   // LCD_DrawImageSBPP(225 + 83 + 83 + 2, 365 - 50 + 10 + 38, 42, DJZJ, WHITE, BLACK); //电机转矩
   // LCD_DrawImage1BPP(615 - 22, 365 - 50 + 10 + 38, BMP_n, WHITE, BLACK); //NM
   // LCD_DrawImage1BPP(615 - 22 + 11, 365 - 50 + 10 + 38, BMP_m, WHITE, BLACK); //


    LCD_DrawImageSBPP(180 - 20 + 2, 365 - 50 + 10 + 38, 63, SHYWD, WHITE, BLACK); //三合一温度
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
        print_SZ_1(60 + 32, 318 + 38, BAT_Max_Cell_Voltage, 3, 0, WHITE); //单体高
        print_SZ_1(60 + 32, 318 + 38 * 2, BAT_Min_Cell_Voltage, 3, 0, WHITE); //单体低
        updata_DAT(313, 318 + 38, Three_Temp, 1, 40, WHITE, 3, 0); //三合一温度
    } else if (f_index == 2) {
        f_index = 3;
        disp_BMP_baojing();
        updata_DAT(480 + 30, 318, MCU_RPM, 1, 3000, WHITE, 4, 0); //电机转速
        //updata_DAT(480 + 30, 318 + 38, MCU_RPM, 0.1, 2000, WHITE, 4, 0);
    } else if (f_index == 3) {
        f_index = 4;
        disp_miles();
        updata_DCDL(585, 155 + 60);
    } else if (f_index == 4) {
        f_index = 5;
        disp_time(330, 440, timer);
        updata_DAT(313, 318, MCU_Control_Temp, 1, 40, WHITE, 3, 0); //电机控制器温度
    } else if (f_index == 5) {
        f_index = 6;
        updata_SOC(585, 155 + 60 + 60);
        updata_DAT(800 - 150, 318 + 38, BAT_Max_Cell_Temperature, 1, 40, WHITE, 3, 0); //单体高温
        updata_DAT(800 - 150, 318 + 38 * 2, BAT_Min_Cell_Temperature, 1, 40, WHITE, 3, 0); //单体低温
    } else if (f_index == 6) {
        f_index = 7;
        updata_DCDY(585, 155);
        disp_FONT_baojing(162, 394);
    } else if (f_index == 7) {
        f_index = 1;
        updata_GEAR(138 + 15 + 66 * 4, 10);
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
            if ((LED15 == 1) && (!time_flag)) {//背光开启
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
    }

    switch (VIDEO) {
        case 0:
            if (key_AV) {
                key_AV = 0;
                key_long_set = 0;
                key_up = 0;
                key_set = 0;
                if (time_flag)
                    t_add = 1;
                else t_add = 0;
            }
            break;
        case 1:
            if (key_AV) {
                key_AV = 0;
                key_long_set = 0;
                key_up = 0;
                key_set = 0;
                if (time_flag)
                    t_add = 1;
                else t_add = 0;

                unsigned char mode = 1; //1,MCU

                if (AV_CH < VIDEO_NUMBER && !time_flag) AV_CH++;
                else AV_CH = 0;

                switch (AV_CH) {
                    case 0: // DAV
                        CS_E = 0; //关闭 
                        mode = 1; //1,MCU
                        break;
                    case 1: //AV1
                        CS_E = 0; //倒车
                        mode = 2; //2,AV1 
                        break;
                    case 2: //AV2  SP2  CJ2
                        CS_E = 1; //打开 
                        CS_A = 1;
                        CS_B = 1;
                        CS_C = 1;
                        mode = 6; //AV2
                        break;
                    case 3: //AV2  SP3  CJ3
                        CS_E = 1; //打开 
                        CS_A = 0;
                        CS_B = 1;
                        CS_C = 1;
                        mode = 6; //AV2
                        break;
                    case 4: //AV2  SP4  CJ4
                        CS_E = 1; //打开 
                        CS_A = 1;
                        CS_B = 0;
                        CS_C = 1;
                        mode = 6; //AV2
                        break;
                    default:
                        CS_E = 0; //关闭 
                        mode = 1; //1,MCU
                        AV_CH = 0;
                        break;
                }
                LCD_CHS(mode);
            }

            //倒车视屏选择使能按键
            if ((GEAR == 1) && !R_flag) {//倒挡
                key_AV = 1; //模拟AV开关按一次
                AV_CH = 0; //0+1=1  倒车
                R_flag = 1; //防止一直进入这个函数，导致key_AV总是置1
            }
            if ((GEAR != 1) && R_flag) {
                key_AV = 1;
                AV_CH = 4; // 0 返回MCU界面
                R_flag = 0;
                M_flag = 0;
            }

            //中门选择使能按键 优先级小于倒车
            if (GEAR != 1) {
                if (IN3 && !M_flag) {//中门开
                    key_AV = 1; //模拟AV开关按一次
                    AV_CH = 1; //1+1=2  AV1
                    M_flag = 1; //防止一直进入这个函数，导致key_AV总是置1
                }
                if (!IN3 && M_flag) {
                    key_AV = 1;
                    AV_CH = 4; // 0 返回MCU界面
                    M_flag = 0;
                    R_flag = 0;
                }
            }
            break;
        default:
            if (key_AV) {
                key_AV = 0;
                key_long_set = 0;
                key_up = 0;
                key_set = 0;
                if (time_flag)
                    t_add = 1;
                else t_add = 0;
            }
            break;
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

        print_SZ_2(750, 50, 1, 1, 0, WHITE); // 1/2
        LCD_DrawImage1BPP(750 + 11, 50, BMP_I, WHITE, BLACK);
        print_SZ_2(750 + 11 + 14, 50, 2, 1, 0, WHITE);

        /***********************仪表开关量采集*********************************/
        /*************************第一列开关***********************************/
        //左转向
        LCD_DrawImage1BPP(35, 75 + 25 * 0, BMP_IC_Zuo, WHITE, BLACK);
        LCD_DrawImage1BPP(35 + 21, 75 + 25 * 0, BMP_IC_Zhuanxiang, WHITE, BLACK);
        LCD_DrawImage1BPP(35 + 63, 75 + 25 * 0, BMP_IC_Kaiguan, WHITE, BLACK);
        //后门开信号
        //LCD_DrawImageSBPP(35, 75 + 25 * 1, 21, ZMKXH, WHITE, BLACK);
        //ACC信号
        LCD_DrawImageSBPP(35, 75 + 25 * 2, 11, ACCXH, WHITE, BLACK);
        //START
        LCD_DrawImageSBPP(35, 75 + 25 * 3, 11, START, WHITE, BLACK);
        //右转向
        LCD_DrawImage1BPP(35, 75 + 25 * 4, BMP_IC_You, WHITE, BLACK);
        LCD_DrawImage1BPP(35 + 21, 75 + 25 * 4, BMP_IC_Zhuanxiang, WHITE, BLACK);
        LCD_DrawImage1BPP(35 + 63, 75 + 25 * 4, BMP_IC_Kaiguan, WHITE, BLACK);
        //小灯
        LCD_DrawImageSBPP(35, 75 + 25 * 5, 21, XDKG, WHITE, BLACK);
        //远光灯
        LCD_DrawImageSBPP(35, 75 + 25 * 6, 21, YGDKG, WHITE, BLACK);
        //近光灯
        LCD_DrawImageSBPP(35, 75 + 25 * 7, 21, JGDKG, WHITE, BLACK);
        //前雾灯
        LCD_DrawImageSBPP(35, 75 + 25 * 8, 21, QWDKG, WHITE, BLACK);
        //后雾灯
        LCD_DrawImageSBPP(35, 75 + 25 * 9, 21, HWDKG, WHITE, BLACK);
        //驻车制动开关
        LCD_DrawImageSBPP(35, 75 + 25 * 10, 42, ZCZDKG, WHITE, BLACK);
        //制动开关
        LCD_DrawImage1BPP(35, 75 + 25 * 11, BMP_Zhidong, WHITE, BLACK);
        LCD_DrawImage1BPP(35 + 42, 75 + 25 * 11, BMP_IC_Deng, WHITE, BLACK);
        LCD_DrawImage1BPP(35 + 42 + 21, 75 + 25 * 11, BMP_IC_Kaiguan, WHITE, BLACK);
        //喇叭开关
        LCD_DrawImageSBPP(35, 75 + 25 * 12, 42, LBKG, WHITE, BLACK);
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
        /*************************第二列开关***********************************/
        //
        //
        //
        //
        //雨刮喷水
        LCD_DrawImage1BPP(285, 75 + 25 * 4, BMP_IC_Yugua, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 42, 75 + 25 * 4, BMP_Penshui, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 42 + 42, 75 + 25 * 4, BMP_IC_Kaiguan, WHITE, BLACK);
        //空调开关
        LCD_DrawImageSBPP(285, 75 + 25 * 5,42, KTKG, WHITE, BLACK);
        //站点灯开关
        LCD_DrawImage1BPP(285, 75 + 25 * 6, BMP_Zhandian, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 42, 75 + 25 * 6, BMP_IC_Deng, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 63, 75 + 25 * 6, BMP_IC_Kaiguan, WHITE, BLACK);
        //驾驶室灯开关
        LCD_DrawImage1BPP(285, 75 + 25 * 7, BMP_Jiashishi, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 63, 75 + 25 * 7, BMP_IC_Deng, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 84, 75 + 25 * 7, BMP_IC_Kaiguan, WHITE, BLACK);
        //
        //
        //

        /*************************第三列开关***********************************/
        //D档开关
        LCD_DrawImage1BPP(535, 75 + 25 * 0, BMP_d, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 11, 75 + 25 * 0, BMP_Dang, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 11 + 21, 75 + 25 * 0, BMP_IC_Kaiguan, WHITE, BLACK);
        //N档开关
        LCD_DrawImage1BPP(535, 75 + 25 * 1, BMP_n, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 11, 75 + 25 * 1, BMP_Dang, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 11 + 21, 75 + 25 * 1, BMP_IC_Kaiguan, WHITE, BLACK);
        //R档开关
        LCD_DrawImage1BPP(535, 75 + 25 * 2, BMP_r, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 11, 75 + 25 * 2, BMP_Dang, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 11 + 21, 75 + 25 * 2, BMP_IC_Kaiguan, WHITE, BLACK);    
        //
        //
        //危险报警开关
        LCD_DrawImageSBPP(535, 75 + 25 * 5,42, WXBJXH, WHITE, BLACK);;
        //充电唤醒
        LCD_DrawImageSBPP(535, 75 + 25 * 6,42, CDHXXH, WHITE, BLACK);
        //钥匙ON开关
        LCD_DrawImage1BPP(535, 75 + 25 * 7, BMP_o, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 11, 75 + 25 * 7, BMP_n, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 11 + 11, 75 + 25 * 7, BMP_Dang, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 11 + 11 + 21, 75 + 25 * 7, BMP_IC_Kaiguan, WHITE, BLACK);

        LCD_DrawImage1BPP(535, 75 + 25 * 10, BMP_IC_Qian, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 21, 75 + 25 * 10, BMP_Qiya, WHITE, BLACK);

        LCD_DrawImage1BPP(535, 75 + 25 * 11, BMP_IC_Hou, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 21, 75 + 25 * 11, BMP_Qiya, WHITE, BLACK);

        LCD_DrawImage1BPP(535 + 21, 75 + 25 * 8, BMP_Youliang, WHITE, BLACK);

        for (i = 8; i < 14; i++) {
            if (i != 8 && i != 10 && i != 11)
                LCD_DrawImage1BPP(535 + 21, 75 + 25 * i, BMP_Beiyong, WHITE, BLACK);
            LCD_DrawImage1BPP(535 + 63, 75 + 25 * i, BMP_Xinhao, WHITE, BLACK);
            LCD_DrawImage1BPP(535 + 63 + 42 + 16 * 4 - 4, 75 + 25 * i, BMP_Omu, WHITE, BLACK); //Ω
            LCD_DrawImage1BPP(535 + 63 + 42 + 16 * 4 + 16 * 5, 75 + 25 * i, BMP_v, WHITE, BLACK); //V
        }

        LCD_DrawImage1BPP(505 + 100, 75 + 8 + 25 * 15, BMP_Banben, WHITE, BLACK);
        LCD_DrawImage1BPP(505 + 100 + 42, 75 + 8 + 25 * 15, BMP_Hao, WHITE, BLACK);
        LCD_DrawImage1BPP(505 + 200, 75 + 25 * 15, BMP_V, WHITE, BLACK);
    } else if (index == 2) {
        print_SZ_2(750, 50, 2, 1, 0, WHITE); // 2/2
        LCD_DrawImage1BPP(750 + 11, 50, BMP_I, WHITE, BLACK);
        print_SZ_2(750 + 11 + 14, 50, 2, 1, 0, WHITE);

        LCD_DrawImage1BPP(130 + 200 + 200, 130 - 85 + 4, BMP_c, WHITE, BLACK);
        LCD_DrawImage1BPP(130 + 200 + 200 + 11, 130 - 85 + 4, BMP_a, WHITE, BLACK);
        LCD_DrawImage1BPP(130 + 200 + 200 + 11 + 11, 130 - 85 + 4, BMP_n, WHITE, BLACK);
        LCD_DrawImage1BPP(130 + 200 + 200 + 11 + 11 + 11, 130 - 85 + 4, BMP_Tongxin, WHITE, BLACK);

        LCD_DrawImage1BPP(130 + 200, 130 - 85, BMP_QIAN, WHITE, BLACK); //前
        LCD_DrawImage1BPP(130 + 200 + 25, 130 - 85, BMP_MOKUAI, WHITE, BLACK); //模块
        LCD_DrawImage1BPP(130 + 200 + 25 + 50, 130 - 85, BMP_Message, WHITE, BLACK); //信息
        for (i = 0; i < 15; i++) {
            LCD_DrawImage1BPP(60 + 280, 75 + 3 + 25 * i, BMP_a, WHITE, BLACK);
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
        //前雾灯输出
        LCD_DrawImageSBPP(60, 75 + 25 * 3, 21, QWDSC, WHITE, BLACK);
        //驻车制动输出
        LCD_DrawImageSBPP(60, 75 + 25 * 4, 42, ZCZDSC, WHITE, BLACK);
        //右转向灯
        LCD_DrawImage1BPP(60, 75 + 25 * 5, BMP_IC_You, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 5, BMP_IC_Zhuanxiang, WHITE, BLACK);
        //左转向灯
        LCD_DrawImage1BPP(60, 75 + 25 * 6, BMP_IC_Zuo, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 6, BMP_IC_Zhuanxiang, WHITE, BLACK);
        //空调电源
        LCD_DrawImageSBPP(60, 75 + 25 * 7, 42, KTDY, WHITE, BLACK);
        //远光灯
        LCD_DrawImage1BPP(60, 75 + 25 * 8, BMP_IC_Yuan, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 8, BMP_IC_Guang, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 8, BMP_IC_Deng, WHITE, BLACK);
        //驾驶室灯
        LCD_DrawImage1BPP(60, 75 + 25 * 9, BMP_Jiashishi, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 63, 75 + 25 * 9, BMP_IC_Deng, WHITE, BLACK);
        //喇叭
        LCD_DrawImage1BPP(60, 75 + 25 * 10, BMP_Laba, WHITE, BLACK);
        //制动灯
        LCD_DrawImage1BPP(60, 75 + 25 * 11, BMP_Zhidong, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 11, BMP_IC_Deng, WHITE, BLACK);
        //近光灯
        LCD_DrawImage1BPP(60, 75 + 25 * 12, BMP_IC_Jin, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 12, BMP_IC_Guang, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 12, BMP_IC_Deng, WHITE, BLACK);
        //位置灯
        LCD_DrawImage1BPP(60, 75 + 25 * 13, BMP_Weizhi, WHITE, BLACK);
        //警示灯
        LCD_DrawImage1BPP(60, 75 + 25 * 14, BMP_Jingshi, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 14, BMP_IC_Deng, WHITE, BLACK);
        //ADD雨刮复位信号
        LCD_DrawImage1BPP(60, 75 + 25 * 15, BMP_a, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 11, 75 + 25 * 15, BMP_d, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 11 + 11, 75 + 25 * 15, BMP_d, WHITE, BLACK);
        /***********************前模块开关采集*********************************/
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 12, BMP_Dizhi, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 12, BMP_Xuanze, WHITE, BLACK);
        print_SZ_2(285 + 150 + 84 + 6, 75 + 25 * 12, 1, 1, 0, WHITE);

        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 13, BMP_Dizhi, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 13, BMP_Xuanze, WHITE, BLACK);
        print_SZ_2(285 + 150 + 84 + 6, 75 + 25 * 13, 2, 1, 0, WHITE);
        LCD_DrawImage1BPP(505 + 100, 75 + 8 + 25 * 15, BMP_Banben, WHITE, BLACK);
        LCD_DrawImage1BPP(505 + 100 + 42, 75 + 8 + 25 * 15, BMP_Hao, WHITE, BLACK);
        LCD_DrawImage1BPP(505 + 200, 75 + 25 * 15, BMP_V, WHITE, BLACK);
    } else if (index == 3) {
#if 0
        LCD_DrawImage1BPP(130 + 200 + 200, 130 - 85 + 4, BMP_c, WHITE, BLACK);
        LCD_DrawImage1BPP(130 + 200 + 200 + 11, 130 - 85 + 4, BMP_a, WHITE, BLACK);
        LCD_DrawImage1BPP(130 + 200 + 200 + 11 + 11, 130 - 85 + 4, BMP_n, WHITE, BLACK);
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
        //前门开输出
        LCD_DrawImage1BPP(60, 75 + 25 * 4, BMP_IC_Qian, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 4, BMP_Men, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 4, BMP_Kai, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 63, 75 + 25 * 4, BMP_Diancifa, WHITE, BLACK);
        //前路牌
        LCD_DrawImage1BPP(60, 75 + 25 * 5, BMP_IC_Qian, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 5, BMP_Lupai, WHITE, BLACK);
        //前门关输出
        LCD_DrawImage1BPP(60, 75 + 25 * 6, BMP_IC_Qian, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 6, BMP_Men, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 6, BMP_Guan, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 63, 75 + 25 * 6, BMP_Diancifa, WHITE, BLACK);
        //电子钟电源
        LCD_DrawImage1BPP(60, 75 + 25 * 7, BMP_Dianzizhong, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 63, 75 + 25 * 7, BMP_Dianyuan, WHITE, BLACK);
        //中门开输出
        LCD_DrawImage1BPP(60, 75 + 25 * 8, BMP_Zhong, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 8, BMP_Men, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 8, BMP_Kai, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 63, 75 + 25 * 8, BMP_Diancifa, WHITE, BLACK);
        //后路牌
        LCD_DrawImage1BPP(60, 75 + 25 * 9, BMP_IC_Hou, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 9, BMP_Lupai, WHITE, BLACK);
        //中门关输出
        LCD_DrawImage1BPP(60, 75 + 25 * 10, BMP_Zhong, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 10, BMP_Men, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 10, BMP_Guan, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 63, 75 + 25 * 10, BMP_Diancifa, WHITE, BLACK);
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

        /*LCD_DrawImage1BPPZOOM_4(60, 75, BmpBCU_M_OUT1, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 1, BmpBCU_M_OUT2, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 2, BmpBCU_M_OUT3, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 3, BmpBCU_M_OUT4, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 4, BmpBCU_M_OUT5, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 5, BmpBCU_M_OUT6, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 6, BmpBCU_M_OUT7, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 7, BmpBCU_M_OUT8, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 8, BmpBCU_M_OUT9, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 9, BmpBCU_M_OUT10, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 10, BmpBCU_M_OUT11, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 11, BmpBCU_M_OUT12, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 12, BmpBCU_M_OUT13, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 13, BmpBCU_M_OUT14, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 14, BmpBCU_M_OUT15, WHITE, BLACK);*/


        /************************顶模块开关*********************************/
        //门铃开关
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 1, BMP_Men, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 21, 75 + 25 * 1, BMP_Ling, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 1, BMP_IC_Kaiguan, WHITE, BLACK);
        //前门应急阀报警2
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 3, BMP_IC_Qian, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 21, 75 + 25 * 3, BMP_Men, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 3, BMP_Yingjifa, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 105, 75 + 25 * 3, BMP_Baojing, WHITE, BLACK);
        print_SZ_2(285 + 150 + 105 + 42 + 6, 75 + 25 * 3, 2, 1, 0, WHITE);
        //中门应急阀报警2
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 5, BMP_Zhong, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 21, 75 + 25 * 5, BMP_Men, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 5, BMP_Yingjifa, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 105, 75 + 25 * 5, BMP_Baojing, WHITE, BLACK);
        print_SZ_2(285 + 150 + 105 + 42 + 6, 75 + 25 * 5, 2, 1, 0, WHITE);
        //地址选择1
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 12, BMP_Dizhi, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 12, BMP_Xuanze, WHITE, BLACK);
        print_SZ_2(285 + 150 + 84 + 6, 75 + 25 * 12, 1, 1, 0, WHITE);
        //地址选择2
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 13, BMP_Dizhi, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 13, BMP_Xuanze, WHITE, BLACK);
        print_SZ_2(285 + 150 + 84 + 6, 75 + 25 * 13, 2, 1, 0, WHITE);
        //中门开信号
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 14, BMP_Zhong, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 21, 75 + 25 * 14, BMP_Men, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 14, BMP_Kai, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 63, 75 + 25 * 14, BMP_Xinhao, WHITE, BLACK);
        //前门开信号
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 15, BMP_IC_Qian, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 21, 75 + 25 * 15, BMP_Men, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 15, BMP_Kai, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 63, 75 + 25 * 15, BMP_Xinhao, WHITE, BLACK);

        LCD_DrawImage1BPP(505 + 100, 75 + 8 + 25 * 15, BMP_Banben, WHITE, BLACK);
        LCD_DrawImage1BPP(505 + 100 + 42, 75 + 8 + 25 * 15, BMP_Hao, WHITE, BLACK);
        LCD_DrawImage1BPP(505 + 200, 75 + 25 * 15, BMP_V, WHITE, BLACK);
#endif
    } else if (index == 4) {
#if 0
        LCD_DrawImage1BPP(130 + 200 + 200, 130 - 85 + 4, BMP_c, WHITE, BLACK);
        LCD_DrawImage1BPP(130 + 200 + 200 + 11, 130 - 85 + 4, BMP_a, WHITE, BLACK);
        LCD_DrawImage1BPP(130 + 200 + 200 + 11 + 11, 130 - 85 + 4, BMP_n, WHITE, BLACK);
        LCD_DrawImage1BPP(130 + 200 + 200 + 11 + 11 + 11, 130 - 85 + 4, BMP_Tongxin, WHITE, BLACK);

        print_SZ_2(750, 50, 4, 1, 0, WHITE); // 4/4
        LCD_DrawImage1BPP(750 + 11, 50, BMP_I, WHITE, BLACK);
        print_SZ_2(750 + 11 + 14, 50, 4, 1, 0, WHITE);

        LCD_DrawImage1BPP(130 + 200, 130 - 85, BMP_HOU, WHITE, BLACK); //后
        LCD_DrawImage1BPP(130 + 200 + 25, 130 - 85, BMP_MOKUAI, WHITE, BLACK); //模块
        LCD_DrawImage1BPP(130 + 200 + 25 + 50, 130 - 85, BMP_Message, WHITE, BLACK); //信息
        for (i = 0; i < 15; i++) {
            LCD_DrawImage1BPP(60 + 280, 75 + 3 + 25 * i, BMP_a, WHITE, BLACK);
            //LCD_DrawRect(0, 74 +25+ 25 * i, 800, 1, GRAY); //横线
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
        /*LCD_DrawImage1BPPZOOM_4(60, 75, BmpBCU_R_OUT1, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 1, BmpBCU_R_OUT2, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 2, BmpBCU_R_OUT3, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 3, BmpBCU_R_OUT4, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 4, BmpBCU_R_OUT5, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 5, BmpBCU_R_OUT6, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 6, BmpBCU_R_OUT7, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 7, BmpBCU_R_OUT8, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 8, BmpBCU_R_OUT9, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 9, BmpBCU_R_OUT10, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 10, BmpBCU_R_OUT11, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 11, BmpBCU_R_OUT12, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 12, BmpBCU_R_OUT13, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 13, BmpBCU_R_OUT14, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 14, BmpBCU_R_OUT15, WHITE, BLACK);*/

        /*********************后模块开关***************************************/
        //水位报警
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 0, BMP_Shuiwei, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 0, BMP_Baojing, WHITE, BLACK);
        //左前摩擦片报警
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 1, BMP_IC_Zuo, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 21, 75 + 25 * 1, BMP_IC_Qian, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 1, BMP_Mocapian, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 105, 75 + 25 * 1, BMP_Baojing, WHITE, BLACK);
        //前门应急阀报警1
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 2, BMP_IC_Qian, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 21, 75 + 25 * 2, BMP_Men, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 2, BMP_Yingjifa, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 105, 75 + 25 * 2, BMP_Baojing, WHITE, BLACK);
        print_SZ_2(285 + 150 + 105 + 42 + 6, 75 + 25 * 2, 1, 1, 0, WHITE);
        //右前摩擦片报警
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 3, BMP_IC_You, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 21, 75 + 25 * 3, BMP_IC_Qian, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 3, BMP_Mocapian, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 105, 75 + 25 * 3, BMP_Baojing, WHITE, BLACK);
        //中门应急阀报警1
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 4, BMP_Zhong, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 21, 75 + 25 * 4, BMP_Men, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 4, BMP_Yingjifa, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 105, 75 + 25 * 4, BMP_Baojing, WHITE, BLACK);
        print_SZ_2(285 + 150 + 105 + 42 + 6, 75 + 25 * 4, 1, 1, 0, WHITE);
        //制动开关
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 5, BMP_Zhidong, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 5, BMP_IC_Kaiguan, WHITE, BLACK);
        //驻车制动开关
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 7, BMP_Zhuche, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 7, BMP_Zhidong, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 84, 75 + 25 * 7, BMP_IC_Kaiguan, WHITE, BLACK);
        //后舱门
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 10, BMP_IC_Hou, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 21, 75 + 25 * 10, BMP_Cangmen, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 63, 75 + 25 * 10, BMP_IC_Kaiguan, WHITE, BLACK);
        //地址选择1
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 12, BMP_Dizhi, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 12, BMP_Xuanze, WHITE, BLACK);
        print_SZ_2(285 + 150 + 84 + 6, 75 + 25 * 12, 1, 1, 0, WHITE);
        //地址选择2
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 13, BMP_Dizhi, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 13, BMP_Xuanze, WHITE, BLACK);
        print_SZ_2(285 + 150 + 84 + 6, 75 + 25 * 13, 2, 1, 0, WHITE);

        LCD_DrawImage1BPP(505 + 100, 75 + 8 + 25 * 15, BMP_Banben, WHITE, BLACK);
        LCD_DrawImage1BPP(505 + 100 + 42, 75 + 8 + 25 * 15, BMP_Hao, WHITE, BLACK);
        LCD_DrawImage1BPP(505 + 200, 75 + 25 * 15, BMP_V, WHITE, BLACK);
        /*LCD_DrawImage1BPPZOOM_4(285 + 150, 75, BmpBCU_R_KL1, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285 + 150, 75 + 25 * 1, BmpBCU_R_KL2, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285 + 150, 75 + 25 * 2, BmpBCU_R_KL3, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285 + 150, 75 + 25 * 3, BmpBCU_R_KL4, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285 + 150, 75 + 25 * 4, BmpBCU_R_KL5, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285 + 150, 75 + 25 * 5, BmpBCU_R_KL6, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285 + 150, 75 + 25 * 6, BmpBCU_R_KL7, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285 + 150, 75 + 25 * 7, BmpBCU_R_KL8, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285 + 150, 75 + 25 * 8, BmpBCU_R_KL9, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285 + 150, 75 + 25 * 9, BmpBCU_R_KL10, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285 + 150, 75 + 25 * 10, BmpBCU_R_KL11, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285 + 150, 75 + 25 * 11, BmpBCU_R_KL12, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285 + 150, 75 + 25 * 12, BmpBCU_R_KL13, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285 + 150, 75 + 25 * 13, BmpBCU_R_KL14, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285 + 150, 75 + 25 * 14, BmpBCU_R_KL15, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285 + 150, 75 + 25 * 15, BmpBCU_R_KH1, WHITE, BLACK);*/
#endif
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
            if (i == 0 || i == 1 || i == 2 || i == 5 || i == 6 || i == 7) {
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
                print_SZ(30 + 250, 75 + 6 + 25 * i, fpcur[i] / 100, 3, 1, GREEN); //前模块电流
            else
                print_SZ(30 + 250, 75 + 6 + 25 * i, 0, 3, 1, GREEN);
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
                print_SZ(30 + 250, 75 + 6 + 25 * i, mpcur[i] / 100, 3, 1, GREEN); //顶模块电流
            else
                print_SZ(30 + 250, 75 + 6 + 25 * i, 0, 3, 1, GREEN);
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
                print_SZ(30 + 250, 75 + 6 + 25 * i, rpcur[i] / 100, 3, 1, GREEN); //后模块电流
            else
                print_SZ(30 + 250, 75 + 6 + 25 * i, 0, 3, 1, GREEN);
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
        if (index_IC == 3) {
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

void MenuFrame(void) {
    LCD_Clear();
    unsigned char color = WHITE;
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //顶部横线   

    LCD_DrawRect(0, 430, 800, 2, YELLOW); //底部横线
    LCD_DrawImageSBPP(130, 130, 50, MOTO_SYSTEM, color, BLACK); //电机

    //    LCD_DrawImageSBPP(130, 130 + 35, 50, AIR_SYSTEM, color, BLACK); //气泵

    //    LCD_DrawImage1BPP(130, 130 + 35 + 35, BMP_DCDC, color, BLACK); //DCDC
    //    LCD_DrawImage1BPP(130 + 65, 130 + 35 + 35, BMP_STSTEM, color, BLACK); //系统
    //    LCD_DrawImage1BPP(130 + 65 + 50, 130 + 35 + 35, BMP_Message, color, BLACK); //信息

    //    LCD_DrawImageSBPP(130, 130 + 35 + 35 + 35, 50, OIL_SYSTEM, color, BLACK); //油泵

    //LCD_DrawImageSBPP(130 + 350, 130 + 35 * 0, 50, BMS_SYSTEM, color, BLACK); //电池

    LCD_DrawImageSBPP(130 + 350, 130 + 35 * 0, 50, Battery_SYSTEM, color, BLACK); //电池   

    //    LCD_DrawImageSBPP(130 + 350, 130 + 35 + 35, 50, HV_SYSTEM, color, BLACK); //高压  

    LCD_DrawImageSBPP(130, 130 + 35 * 1, 50, IC_SYSTEM, color, BLACK); //仪表

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

    if (i == 6) i = 3;
    if (i == 0) i = 3;
    //子菜单间切换
    if (i == 3) {
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
    if (i == 4 || i == 1) {
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
    LCD_DrawImage1BPP(105, 131 + 35 * 1, BMP_Choose, color, BLACK);
    if (i == 5 || i == 2) {
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
    LCD_DrawImage1BPP(105 + 350, 131 + 0 * 35, BMP_Choose, color, BLACK);
    /*    if (i == 7 || i == 3) {
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
        if (i == 12 || i == 4) {
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
        if (i == 13 || i == 5) {
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
        if (i == 14 || i == 6) {
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
        if (i == 15 || i == 7) {
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
     */

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
        disp_FONT_baojing(2, 440);
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
            frmID = 30;
        }
    }
}

/******************************************************/

void MOTOFrame(unsigned char index) {
    unsigned char i = 0;
    LCD_Clear();
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //顶部横线
    LCD_DrawImageSBPP(130 + 200, 130 - 85, 50, MOTO_SYSTEM, WHITE, BLACK); //电机

    LCD_DrawRect(80, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320 + 320, 90, 1, 380, GREEN);
    for (i = 0; i < 11; i++)
        LCD_DrawRect(80, 90 + i * 38, 640, 1, GREEN);

    if (index == 1) {

        LCD_DrawImage1BPP(82, 100 + 38 * 0, BMP_s, WHITE, BLACK); //S
        LCD_DrawImage1BPP(82 + 11, 100 + 38 * 0, BMP_o, WHITE, BLACK); //O
        LCD_DrawImage1BPP(82 + 11 + 11, 100 + 38 * 0, BMP_c, WHITE, BLACK); //C
        LCD_DrawImage1BPP(400 - 24, 100 + 38 * 0, BMP_Baifenhao, WHITE, BLACK); //%

        LCD_DrawImage1BPP(82, 100 + 38 * 1, BMP_DJ, WHITE, BLACK); //电机
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 1, BMP_Zhuansu, WHITE, BLACK); //转速
        LCD_DrawImage1BPP(400 - 24 - 24, 100 + 38 * 1, BMP_RPM, WHITE, BLACK); //RPM

        LCD_DrawImage1BPP(82, 100 + 38 * 2, BMP_DC, WHITE, BLACK); //电池
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 2, BMP_Zong, WHITE, BLACK); //总
        LCD_DrawImage1BPP(82 + 42 + 21, 100 + 38 * 2, BMP_DY, WHITE, BLACK); //电压
        LCD_DrawImage1BPP(400 - 24, 100 + 38 * 2, BMP_v, WHITE, BLACK); //V

        LCD_DrawImage1BPP(82, 100 + 38 * 3, BMP_DC, WHITE, BLACK); //电池
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 3, BMP_Zong, WHITE, BLACK); //总
        LCD_DrawImage1BPP(82 + 42 + 21, 100 + 38 * 3, BMP_DL, WHITE, BLACK); //电流
        LCD_DrawImage1BPP(400 - 24, 100 + 38 * 3, BMP_a, WHITE, BLACK); //A

        LCD_DrawImage1BPP(82, 100 + 38 * 4, BMP_Chongdian, WHITE, BLACK); //充电
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 4, BMP_Xuqiu, WHITE, BLACK); //需求
        LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 4, BMP_DY, WHITE, BLACK); //电压
        LCD_DrawImage1BPP(400 - 24, 100 + 38 * 4, BMP_v, WHITE, BLACK); //V

        LCD_DrawImage1BPP(82, 100 + 38 * 5, BMP_Chongdian, WHITE, BLACK); //电池
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 5, BMP_Xuqiu, WHITE, BLACK); //需求
        LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 5, BMP_DL, WHITE, BLACK); //电流
        LCD_DrawImage1BPP(400 - 24, 100 + 38 * 5, BMP_a, WHITE, BLACK); //A               

        LCD_DrawImage1BPP(82, 100 + 38 * 6, BMP_DJ, WHITE, BLACK); //电机
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 6, BMP_KZQ, WHITE, BLACK); //控制器
        LCD_DrawImage1BPP(82 + 42 + 63, 100 + 38 * 6, BMP_Wendu, WHITE, BLACK); //温度
        LCD_DrawImage1BPP(400 - 28, 100 + 38 * 6, BMP_T, WHITE, BLACK); //℃

        LCD_DrawImage1BPP(82, 100 + 38 * 7, BMP_Sanheyi, WHITE, BLACK); //三合一
        LCD_DrawImage1BPP(82 + 63, 100 + 38 * 7, BMP_Wendu, WHITE, BLACK); //温度
        LCD_DrawImage1BPP(400 - 28, 100 + 38 * 7, BMP_T, WHITE, BLACK); //℃

        LCD_DrawImage1BPP(82, 100 + 38 * 8, BMP_Qibeng, WHITE, BLACK); //气泵
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 8, BMP_Zhuansu, WHITE, BLACK); //转速
        LCD_DrawImage1BPP(400 - 24 - 24, 100 + 38 * 8, BMP_RPM, WHITE, BLACK); //RPM

        LCD_DrawImage1BPP(82, 100 + 38 * 9, BMP_IC_Zhuanxiang, WHITE, BLACK); //转向
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 9, BMP_Zhuansu, WHITE, BLACK); //转速
        LCD_DrawImage1BPP(400 - 24 - 24, 100 + 38 * 9, BMP_RPM, WHITE, BLACK); //RPM


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
                //LCD_DrawImage1BPP(82 + 320 + 42 * 8.5 + 5, 100 + 38 * i, BMP_Hao, WHITE, BLACK); //号
            } else {
                LCD_DrawImage1BPP(82 + 320 + 21 + 21 + 21 + 21, 100 + 38 * i, BMP_Wendu, WHITE, BLACK); //温度
                LCD_DrawImage1BPP(720 - 28 - 63 - 5, 100 + 38 * i, BMP_T, WHITE, BLACK); //℃
            }
            LCD_DrawImage1BPP(82 + 320 + 42 * 7 - 5, 100 + 38 * i, BMP_Xiang_BMS, WHITE, BLACK); //箱            
        }




        /*        LCD_DrawImage1BPP(82, 100, BMP_Zhengche, WHITE, BLACK); //整车状态
                LCD_DrawImage1BPP(82 + 42, 100, BMP_Zhuangtai, WHITE, BLACK); //

                LCD_DrawImage1BPP(82, 100 + 38, BMP_System, WHITE, BLACK); //系统互锁状态
                LCD_DrawImage1BPP(82 + 42, 100 + 38, BMP_Husuo, WHITE, BLACK);
                LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38, BMP_Zhuangtai, WHITE, BLACK);

                LCD_DrawImage1BPP(82, 100 + 38 * 2, BMP_System, WHITE, BLACK); //系统自检状态
                LCD_DrawImage1BPP(82 + 42, 100 + 38 * 2, BMP_Zijian, WHITE, BLACK);
                LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 2, BMP_Zhuangtai, WHITE, BLACK);

                LCD_DrawImage1BPP(82, 100 + 38 * 3, BMP_b, WHITE, BLACK); //BMS接触器状态
                LCD_DrawImage1BPP(82 + 11, 100 + 38 * 3, BMP_m, WHITE, BLACK);
                LCD_DrawImage1BPP(82 + 11 + 11, 100 + 38 * 3, BMP_s, WHITE, BLACK);
                LCD_DrawImage1BPP(82 + 11 + 11 + 11, 100 + 38 * 3, BMP_Jiechuqi, WHITE, BLACK);
                LCD_DrawImage1BPP(82 + 11 + 11 + 11 + 63, 100 + 38 * 3, BMP_Zhuangtai, WHITE, BLACK);

                LCD_DrawImage1BPP(82, 100 + 38 * 4, BMP_Chesu, WHITE, BLACK); //车速
                LCD_DrawImage1BPP(400 - 48, 100 + 38 * 4, Bmp_kmh, WHITE, BLACK);

                LCD_DrawImage1BPP(82, 100 + 38 * 5, BMP_v, WHITE, BLACK); //VCU故障码
                LCD_DrawImage1BPP(82 + 11, 100 + 38 * 5, BMP_c, WHITE, BLACK);
                LCD_DrawImage1BPP(82 + 11 + 11, 100 + 38 * 5, BMP_u, WHITE, BLACK);
                LCD_DrawImage1BPP(82 + 11 + 11 + 11, 100 + 38 * 5, BMP_Guzhang, WHITE, BLACK);
                LCD_DrawImage1BPP(82 + 11 + 11 + 11 + 42, 100 + 38 * 5, BMP_Code, WHITE, BLACK);

                LCD_DrawImage1BPP(82, 100 + 38 * 6, BMP_v, WHITE, BLACK); //VCU Life
                LCD_DrawImage1BPP(82 + 11, 100 + 38 * 6, BMP_c, WHITE, BLACK);
                LCD_DrawImage1BPP(82 + 11 + 11, 100 + 38 * 6, BMP_u, WHITE, BLACK);
                LCD_DrawImage1BPP(82 + 11 + 11 + 11 + 11, 100 + 38 * 6, BMP_Life, WHITE, BLACK);

                LCD_DrawImage1BPP(82, 100 + 38 * 7, BMP_v, WHITE, BLACK); //VCU 版本
                LCD_DrawImage1BPP(82 + 11, 100 + 38 * 7, BMP_c, WHITE, BLACK);
                LCD_DrawImage1BPP(82 + 11 + 11, 100 + 38 * 7, BMP_u, WHITE, BLACK);
                LCD_DrawImage1BPP(82 + 11 + 11 + 11 + 11, 100 + 38 * 7, BMP_Banben, WHITE, BLACK);

                LCD_DrawImage1BPP(82, 100 + 38 * 8, BMP_Xuhang, WHITE, BLACK); //续航里程
                LCD_DrawImage1BPP(82 + 42, 100 + 38 * 8, Bmp_Licheng, WHITE, BLACK);
                LCD_DrawImage1BPP(400 - 36, 100 + 38 * 8, BMP_HZ_KM, WHITE, BLACK);

                LCD_DrawImage1BPP(82, 100 + 38 * 9, BMP_Pingjun, WHITE, BLACK); //平均电耗
                LCD_DrawImage1BPP(82 + 42, 100 + 38 * 9, BMP_Dianhao, WHITE, BLACK);
                LCD_DrawImage1BPP(400 - 24 - 11 - 11, 100 + 38 * 9, BMP_k, WHITE, BLACK);
                LCD_DrawImage1BPP(400 - 24 - 11, 100 + 38 * 9, BMP_w, WHITE, BLACK);
                LCD_DrawImage1BPP(400 - 24, 100 + 38 * 9, BMP_h, WHITE, BLACK);



                LCD_DrawImage1BPP(82 + 320, 100 + 38 * 0, BMP_Youbeng, WHITE, BLACK); //油泵使能
                LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 0, BMP_Shineng, WHITE, BLACK);

                LCD_DrawImage1BPP(82 + 320, 100 + 38 * 1, BMP_Qibeng, WHITE, BLACK); //气泵使能
                LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 1, BMP_Shineng, WHITE, BLACK);

                LCD_DrawImage1BPP(82 + 320, 100 + 38 * 2 - 4, BMP_DCDC, WHITE, BLACK); //DCDC使能
                LCD_DrawImage1BPP(82 + 320 + 65, 100 + 38 * 2, BMP_Shineng, WHITE, BLACK);

                LCD_DrawImage1BPP(82 + 320, 100 + 38 * 3, BMP_Kongtiao, WHITE, BLACK); //空调使能
                LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 3, BMP_Shineng, WHITE, BLACK);

                LCD_DrawImage1BPP(82 + 320, 100 + 38 * 4, BMP_v, WHITE, BLACK); //VCU控制状态
                LCD_DrawImage1BPP(82 + 320 + 11, 100 + 38 * 4, BMP_c, WHITE, BLACK); //
                LCD_DrawImage1BPP(82 + 320 + 11 + 11, 100 + 38 * 4, BMP_u, WHITE, BLACK); //
                LCD_DrawImage1BPP(82 + 320 + 11 + 11 + 11, 100 + 38 * 4, BMP_KZQ, WHITE, BLACK);
                LCD_DrawImage1BPP(82 + 320 + 11 + 11 + 11 + 42, 100 + 38 * 4, BMP_Zhuangtai, WHITE, BLACK);

                LCD_DrawImage1BPP(82 + 320, 100 + 38 * 5, BMP_v, WHITE, BLACK); //VCU接触器状态
                LCD_DrawImage1BPP(82 + 320 + 11, 100 + 38 * 5, BMP_c, WHITE, BLACK); //
                LCD_DrawImage1BPP(82 + 320 + 11 + 11, 100 + 38 * 5, BMP_u, WHITE, BLACK); //
                LCD_DrawImage1BPP(82 + 320 + 11 + 11 + 11, 100 + 38 * 5, BMP_Jiechuqi, WHITE, BLACK);
                LCD_DrawImage1BPP(82 + 320 + 11 + 11 + 11 + 63, 100 + 38 * 5, BMP_Zhuangtai, WHITE, BLACK);

                LCD_DrawImage1BPP(82 + 320, 100 + 38 * 6, BMP_b, WHITE, BLACK); //BMS接触器状态
                LCD_DrawImage1BPP(82 + 320 + 11, 100 + 38 * 6, BMP_m, WHITE, BLACK); //
                LCD_DrawImage1BPP(82 + 320 + 11 + 11, 100 + 38 * 6, BMP_s, WHITE, BLACK); //
                LCD_DrawImage1BPP(82 + 320 + 11 + 11 + 11, 100 + 38 * 6, BMP_Jiechuqi, WHITE, BLACK);
                LCD_DrawImage1BPP(82 + 320 + 11 + 11 + 11 + 63, 100 + 38 * 6, BMP_Zhuangtai, WHITE, BLACK);

                LCD_DrawImage1BPP(82 + 320, 100 + 38 * 7, BMP_Youmen, WHITE, BLACK); //油门
                LCD_DrawImage1BPP(82 + 42 + 320, 100 + 38 * 7, BMP_Taban, WHITE, BLACK); //踏板
                LCD_DrawImage1BPP(720 - 24, 100 + 38 * 7, BMP_Baifenhao, WHITE, BLACK); //%

                LCD_DrawImage1BPP(82 + 320, 100 + 38 * 8, BMP_Zhidong, WHITE, BLACK); //制动
                LCD_DrawImage1BPP(82 + 42 + 320, 100 + 38 * 8, BMP_Taban, WHITE, BLACK); //踏板
                LCD_DrawImage1BPP(720 - 24, 100 + 38 * 8, BMP_Baifenhao, WHITE, BLACK); //%
         */
    } else if (index == 2) {
        /*        print_SZ_2(750, 50, 2, 1, 0, WHITE); // 2/2
                LCD_DrawImage1BPP(750 + 11, 50, BMP_I, WHITE, BLACK);
                print_SZ_2(750 + 11 + 14, 50, 2, 1, 0, WHITE);

                LCD_DrawImage1BPP(82, 100 + 38 * 0, BMP_DJ, WHITE, BLACK); //电机
                LCD_DrawImage1BPP(82 + 42, 100 + 38 * 0, BMP_Output, WHITE, BLACK); //输出
                LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 0, BMP_DY, WHITE, BLACK); //电压
                LCD_DrawImage1BPP(400 - 24, 100 + 38 * 0, BMP_v, WHITE, BLACK); //V

                LCD_DrawImage1BPP(82, 100 + 38 * 1, BMP_DJ, WHITE, BLACK); //电机
                LCD_DrawImage1BPP(82 + 42, 100 + 38 * 1, BMP_Xiang, WHITE, BLACK); //相
                LCD_DrawImage1BPP(82 + 42 + 21, 100 + 38 * 1, BMP_DL, WHITE, BLACK); //电流
                LCD_DrawImage1BPP(400 - 24, 100 + 38 * 1, BMP_a, WHITE, BLACK); //A

                LCD_DrawImage1BPP(82, 100 + 38 * 2, BMP_DJ, WHITE, BLACK); //电机
                LCD_DrawImage1BPP(82 + 42, 100 + 38 * 2, BMP_Muxian, WHITE, BLACK); //母线
                LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 2, BMP_DY, WHITE, BLACK); //电压
                LCD_DrawImage1BPP(400 - 24, 100 + 38 * 2, BMP_v, WHITE, BLACK); //V

                LCD_DrawImage1BPP(82, 100 + 38 * 3, BMP_DJ, WHITE, BLACK); //电机
                LCD_DrawImage1BPP(82 + 42, 100 + 38 * 3, BMP_Muxian, WHITE, BLACK); //母线
                LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 3, BMP_DL, WHITE, BLACK); //电流
                LCD_DrawImage1BPP(400 - 24, 100 + 38 * 3, BMP_a, WHITE, BLACK); //A

                LCD_DrawImage1BPP(82, 100 + 38 * 4, BMP_DJ, WHITE, BLACK); //电机
                LCD_DrawImage1BPP(82 + 42, 100 + 38 * 4, BMP_Zhuansu, WHITE, BLACK); //转速
                LCD_DrawImage1BPP(400 - 24 - 24, 100 + 38 * 4, BMP_RPM, WHITE, BLACK); //RPM

                LCD_DrawImage1BPP(82, 100 + 38 * 5, BMP_DJ, WHITE, BLACK); //电机
                LCD_DrawImage1BPP(82 + 42, 100 + 38 * 5, BMP_Zhuanju, WHITE, BLACK); //转矩
                LCD_DrawImage1BPP(400 - 24 - 11, 100 + 38 * 5, BMP_n, WHITE, BLACK); //NM
                LCD_DrawImage1BPP(400 - 24, 100 + 38 * 5, BMP_m, WHITE, BLACK); //

                LCD_DrawImage1BPP(82, 100 + 38 * 6, BMP_DJ, WHITE, BLACK); //电机
                LCD_DrawImage1BPP(82 + 42, 100 + 38 * 6, BMP_Wendu, WHITE, BLACK); //温度
                LCD_DrawImage1BPP(400 - 28, 100 + 38 * 6, BMP_T, WHITE, BLACK); //℃

                LCD_DrawImage1BPP(82, 100 + 38 * 7, BMP_KZQ, WHITE, BLACK); //控制器
                LCD_DrawImage1BPP(82 + 63, 100 + 38 * 7, BMP_Wendu, WHITE, BLACK); //温度
                LCD_DrawImage1BPP(400 - 28, 100 + 38 * 7, BMP_T, WHITE, BLACK); //℃

                LCD_DrawImage1BPP(82, 100 + 38 * 8, BMP_DJ, WHITE, BLACK); //电机
                LCD_DrawImage1BPP(82 + 42, 100 + 38 * 8, BMP_Gonglv, WHITE, BLACK); //功率
                LCD_DrawImage1BPP(400 - 28 - 11, 100 + 38 * 8, BMP_k, WHITE, BLACK); //KW   
                LCD_DrawImage1BPP(400 - 28, 100 + 38 * 8, BMP_w, WHITE, BLACK); //KW

                LCD_DrawImage1BPP(82, 100 + 38 * 9, BMP_m, WHITE, BLACK); //MCU
                LCD_DrawImage1BPP(82 + 11, 100 + 38 * 9, BMP_c, WHITE, BLACK); //
                LCD_DrawImage1BPP(82 + 11 + 11, 100 + 38 * 9, BMP_u, WHITE, BLACK); //
                LCD_DrawImage1BPP(82 + 11 + 11 + 11, 100 + 38 * 9, BMP_Zijian, WHITE, BLACK); //自检
                LCD_DrawImage1BPP(82 + 11 + 11 + 11 + 42, 100 + 38 * 9, BMP_Zhuangtai, WHITE, BLACK); //状态



                LCD_DrawImage1BPP(82 + 320, 100 + 38 * 0, BMP_m, WHITE, BLACK); //MCU
                LCD_DrawImage1BPP(82 + 320 + 11, 100 + 38 * 0, BMP_c, WHITE, BLACK); //
                LCD_DrawImage1BPP(82 + 320 + 11 + 11, 100 + 38 * 0, BMP_u, WHITE, BLACK); //
                LCD_DrawImage1BPP(82 + 320 + 11 + 11 + 11, 100 + 38 * 0, BMP_Guzhang, WHITE, BLACK); //故障
                LCD_DrawImage1BPP(82 + 320 + 11 + 11 + 11 + 42, 100 + 38 * 0, BMP_Code, WHITE, BLACK); //代码

                LCD_DrawImage1BPP(82 + 320, 100 + 38 * 1, BMP_m, WHITE, BLACK); //MCU
                LCD_DrawImage1BPP(82 + 320 + 11, 100 + 38 * 1, BMP_c, WHITE, BLACK); //
                LCD_DrawImage1BPP(82 + 320 + 11 + 11, 100 + 38 * 1, BMP_u, WHITE, BLACK); //
                LCD_DrawImage1BPP(82 + 320 + 11 + 11 + 11, 100 + 38 * 1, BMP_Tongxin, WHITE, BLACK); //通信
                LCD_DrawImage1BPP(82 + 320 + 11 + 11 + 11 + 42, 100 + 38 * 1, BMP_Guzhang, WHITE, BLACK); //故障

                LCD_DrawImage1BPP(82 + 320, 100 + 38 * 2, BMP_DJ, WHITE, BLACK); //电机温度报警
                LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 2, BMP_Wendu, WHITE, BLACK); //
                LCD_DrawImage1BPP(82 + 320 + 42 + 42, 100 + 38 * 2, BMP_Baojing, WHITE, BLACK); //

                LCD_DrawImage1BPP(82 + 320, 100 + 38 * 3, BMP_DJ, WHITE, BLACK); //电机控制器温度报警
                LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 3, BMP_KZQ, WHITE, BLACK); //
                LCD_DrawImage1BPP(82 + 320 + 42 + 63, 100 + 38 * 3, BMP_Wendu, WHITE, BLACK); //
                LCD_DrawImage1BPP(82 + 320 + 42 + 63 + 42, 100 + 38 * 3, BMP_Baojing, WHITE, BLACK); //

                LCD_DrawImage1BPP(82 + 320, 100 + 38 * 4, BMP_DL, WHITE, BLACK);
                LCD_DrawImage1BPP(82 + 320, 100 + 38 * 4, BMP_Guo, WHITE, BLACK); //过流报警
                LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 4, BMP_Baojing, WHITE, BLACK); //

                LCD_DrawImage1BPP(82 + 320, 100 + 38 * 5, BMP_DJ, WHITE, BLACK); //电机控制器欠压报警
                LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 5, BMP_KZQ, WHITE, BLACK); //
                LCD_DrawImage1BPP(82 + 320 + 42 + 63, 100 + 38 * 5, BMP_Qian, WHITE, BLACK); //
                LCD_DrawImage1BPP(82 + 320 + 42 + 42 + 42, 100 + 38 * 5, BMP_Yali, WHITE, BLACK); //
                LCD_DrawImage1BPP(82 + 320 + 42 + 63 + 42, 100 + 38 * 5, BMP_Baojing, WHITE, BLACK); //

                LCD_DrawImage1BPP(82 + 320, 100 + 38 * 6, BMP_DJ, WHITE, BLACK); //电机控制器过压报警
                LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 6, BMP_KZQ, WHITE, BLACK); //
                LCD_DrawImage1BPP(82 + 320 + 42 + 63, 100 + 38 * 6, BMP_Guo, WHITE, BLACK); //
                LCD_DrawImage1BPP(82 + 320 + 42 + 42 + 42, 100 + 38 * 6, BMP_Yali, WHITE, BLACK); //
                LCD_DrawImage1BPP(82 + 320 + 42 + 63 + 42, 100 + 38 * 6, BMP_Baojing, WHITE, BLACK); //         
            }
         */
    }
}

void MOTOUpdate(unsigned char index) {
    print_SZ_1(82 + 200 + 30 - 16, 100 - 8 + 38 * 0, BMS_SOC, 3, 0, WHITE);
    updata_DAT(82 + 200, 100 - 8 + 38 * 1, MCU_RPM, 1, 3000, WHITE, 4, 0);
    print_SZ_1(82 + 200 + 30 - 32, 100 - 8 + 38 * 2, BMS_V, 4, 0, WHITE);
    updata_DAT(82 + 200 + 30 - 32, 100 - 8 + 38 * 3, BMS_A, 1, 1000, WHITE, 4, 0);
    print_SZ_1(82 + 200 + 30 - 32, 100 - 8 + 38 * 4, BMS_Charge_V, 4, 0, WHITE);
    updata_DAT(82 + 200 + 30 - 32, 100 - 8 + 38 * 5, BMS_Charge_A, 1, 1000, WHITE, 4, 0);
    updata_DAT(82 + 200 + 16, 100 - 8 + 38 * 6, MCU_Control_Temp, 1, 40, WHITE, 3, 0);
    updata_DAT(82 + 200 + 16, 100 - 8 + 38 * 7, Three_Temp, 1, 40, WHITE, 3, 0);
    updata_DAT(82 + 200 - 16, 100 - 8 + 38 * 8, Air_RPM, 1, 0, WHITE, 5, 0);
    updata_DAT(82 + 200 - 16, 100 - 8 + 38 * 9, Switch_RPM, 1, 0, WHITE, 5, 0);


    print_SZ_1(82 + 200 + 300 + 32 - 32 - 5, 100 - 8, BAT_Max_Cell_Voltage, 3, 0, WHITE);
    print_SZ_1(82 + 200 + 300 - 32 + 16 * 6 - 5, 100 - 8, BAT_Max_Cell_Voltage_Cell_Case, 3, 0, WHITE);

    print_SZ_1(82 + 200 + 300 + 32 - 32 - 5, 100 - 8 + 38, BAT_Min_Cell_Voltage, 3, 0, WHITE);
    print_SZ_1(82 + 200 + 300 - 32 + 16 * 6 - 5, 100 - 8 + 38, BAT_Min_Cell_Voltage_Cell_Case, 3, 0, WHITE);

    updata_DAT(82 + 200 + 300 - 5, 100 - 8 + 38 * 2, BAT_Max_Cell_Temperature, 1, 40, WHITE, 3, 0);
    print_SZ_1(82 + 200 + 300 - 32 + 16 * 6 - 5, 100 - 8 + 38 * 2, BAT_Max_Cell_Temp_Cell_Case, 3, 0, WHITE);

    updata_DAT(82 + 200 + 300 - 5, 100 - 8 + 38 * 3, BAT_Min_Cell_Temperature, 1, 40, WHITE, 3, 0);
    print_SZ_1(82 + 200 + 300 - 32 + 16 * 6 - 5, 100 - 8 + 38 * 3, BAT_Min_Cell_Temp_Cell_Case, 3, 0, WHITE);

    /*    if (index == 1) {
            print_D(82 + 260, 100 - 8 + 38 * 0, VCU_Status.bit4, 2, 0, WHITE);
            //print_D(82 + 260, 100 - 8 + 38 * 1, VCU_Status.bit3, 2, 0, WHITE);
            //print_D(82 + 260, 100 - 8 + 38 * 2, VCU_Status.bit2, 2, 0, WHITE);
            //print_D(82 + 260, 100 - 8 + 38 * 3, VCU_Status.bit1, 2, 0, WHITE);
            if (VCU_Status.bit3) {
                LCD_DrawImage1BPP(82 + 42 * 6 - 5, 100 + 38 * 1, BMP_Husuo, RED, BLACK);
            } else {
                LCD_DrawImage1BPP(82 + 42 * 6 - 5, 100 + 38 * 1, BMP_Zhengchang, GREEN, BLACK);
            }
            if (VCU_Status.bit2 == 0) {
                LCD_DrawImage1BPP(82 + 42 * 6 - 5, 100 + 38 * 2, BMP_Zijian, YELLOW, BLACK);
            } else if (VCU_Status.bit2 == 1) {
                LCD_DrawImage1BPP(82 + 42 * 6 - 5, 100 + 38 * 2, BMP_Zhengchang, GREEN, BLACK);
            } else if (VCU_Status.bit2 == 2) {
                LCD_DrawImage1BPP(82 + 42 * 6 - 5, 100 + 38 * 2, BMP_Guzhang, RED, BLACK);
            }
            if (VCU_Status.bit1 == 1) {
                LCD_DrawImage1BPP(82 + 42 * 6 - 5, 100 + 38 * 3, BMP_Bihe, YELLOW, BLACK);
            } else if (VCU_Status.bit1 == 0) {
                LCD_DrawImage1BPP(82 + 42 * 6 - 5, 100 + 38 * 3, BMP_Qieduan, YELLOW, BLACK);
            }
            print_SZ_1(82 + 200 + 20, 100 - 8 + 38 * 4, SPEED, 3, 0, WHITE);
            print_SZ_1(82 + 200 + 20, 100 - 8 + 38 * 5, VCU_Code, 3, 0, WHITE);
            print_SZ_1(82 + 200 + 20, 100 - 8 + 38 * 6, VCU_Life, 3, 0, WHITE);
            print_SZ_1(82 + 200 + 20, 100 - 8 + 38 * 7, VCU_Verison, 3, 1, WHITE);
            print_SZ_1(82 + 200 + 20, 100 - 8 + 38 * 8, VCU_KM * 0.125, 3, 0, WHITE);
            print_SZ_1(82 + 200 + 20, 100 - 8 + 38 * 9, VCU_Kwh_100Km, 3, 0, WHITE);

            if (VCU_Enable[0].bit1) {
                LCD_DrawImage1BPP(82 + 42 * 6 - 5 + 320, 100 + 38 * 0, BMP_Kai, GREEN, BLACK);
            } else {
                LCD_DrawImage1BPP(82 + 42 * 6 - 5 + 320, 100 + 38 * 0, BMP_Guan, RED, BLACK);
            }
            if (VCU_Enable[1].bit1) {
                LCD_DrawImage1BPP(82 + 42 * 6 - 5 + 320, 100 + 38 * 1, BMP_Kai, GREEN, BLACK);
            } else {
                LCD_DrawImage1BPP(82 + 42 * 6 - 5 + 320, 100 + 38 * 1, BMP_Guan, RED, BLACK);
            }

            if (VCU_Enable[2].bit1) {
                LCD_DrawImage1BPP(82 + 42 * 6 - 5 + 320, 100 + 38 * 2, BMP_Kai, GREEN, BLACK);
            } else {
                LCD_DrawImage1BPP(82 + 42 * 6 - 5 + 320, 100 + 38 * 2, BMP_Guan, RED, BLACK);
            }

            if (VCU_Enable[3].bit1) {
                LCD_DrawImage1BPP(82 + 42 * 6 - 5 + 320, 100 + 38 * 3, BMP_Kai, GREEN, BLACK);
            } else {
                LCD_DrawImage1BPP(82 + 42 * 6 - 5 + 320, 100 + 38 * 3, BMP_Guan, RED, BLACK);
            }

            print_D(82 + 200 + 32 + 260, 100 - 8 + 38 * 4, VCU_KT_Control.byte, 8, 0, WHITE);
            print_D(82 + 200 + 32 + 260, 100 - 8 + 38 * 5, VCU_KT_Status.byte, 8, 0, WHITE);
            print_D(82 + 200 + 32 + 260, 100 - 8 + 38 * 6, BMS_KT_Status.byte, 8, 0, WHITE);
            print_SZ_1(82 + 200 + 20 + 320 - 16, 100 - 8 + 38 * 7, VCU_TM_Speed_percent * 4, 4, 1, WHITE); //油门开度
            print_SZ_1(82 + 200 + 20 + 320 - 16, 100 - 8 + 38 * 8, VCU_TM_Brake_percent * 4, 4, 1, WHITE); //制动开度
        } else if (index == 2) {
            print_SZ_1(82 + 200, 100 - 8 + 38 * 0, MCU_Output_Voltage, 4, 0, WHITE);
            print_SZ_1(82 + 200, 100 - 8 + 38 * 1, MCU_Phase_Current * 0.1, 4, 0, WHITE);
            print_SZ_1(82 + 200, 100 - 8 + 38 * 2, MCU_Voltage, 4, 0, WHITE);
            updata_DAT(82 + 200, 100 - 8 + 38 * 3, MCU_Current, 0.1, 3200, WHITE, 4, 0);
            updata_DAT(82 + 200 - 16, 100 - 8 + 38 * 4, MCU_RPM, 1, 0, WHITE, 5, 0);
            updata_DAT(82 + 200, 100 - 8 + 38 * 5, MCU_NM, 1, 2000, WHITE, 4, 0);
            updata_DAT(82 + 200 + 16, 100 - 8 + 38 * 6, MCU_Temp, 1, 40, WHITE, 3, 0);
            updata_DAT(82 + 200 + 16, 100 - 8 + 38 * 7, MCU_Control_Temp, 1, 40, WHITE, 3, 0);
            updata_DAT(82 + 200 + 16, 100 - 8 + 38 * 8, MCU_POWER, 1, 200, WHITE, 3, 0);
            print_D(82 + 200 + 32, 100 - 8 + 38 * 9, MCU_Status, 2, 0, WHITE); //电机工作状态


            print_SZ_1(82 + 200 + 20 + 16 + 320, 100 - 8 + 38 * 0, MCU_Code, 3, 0, WHITE); //MCU故障代码

            if (MCU_Fault.bit6) {
                LCD_DrawImage1BPP(82 + 42 * 6 - 5 + 320, 100 + 38 * 1, BMP_Baojing, RED, BLACK);
            } else {
                LCD_DrawImage1BPP(82 + 42 * 6 - 5 + 320, 100 + 38 * 1, BMP_Zhengchang, GREEN, BLACK);
            }
            if (MCU_Fault.bit5) {
                LCD_DrawImage1BPP(82 + 42 * 6 - 5 + 320, 100 + 38 * 2, BMP_Baojing, RED, BLACK);
            } else {
                LCD_DrawImage1BPP(82 + 42 * 6 - 5 + 320, 100 + 38 * 2, BMP_Zhengchang, GREEN, BLACK);
            }
            if (MCU_Fault.bit4) {
                LCD_DrawImage1BPP(82 + 42 * 6 - 5 + 320, 100 + 38 * 3, BMP_Baojing, RED, BLACK);
            } else {
                LCD_DrawImage1BPP(82 + 42 * 6 - 5 + 320, 100 + 38 * 3, BMP_Zhengchang, GREEN, BLACK);
            }
            if (MCU_Fault.bit3) {
                LCD_DrawImage1BPP(82 + 42 * 6 - 5 + 320, 100 + 38 * 4, BMP_Baojing, RED, BLACK);
            } else {
                LCD_DrawImage1BPP(82 + 42 * 6 - 5 + 320, 100 + 38 * 4, BMP_Zhengchang, GREEN, BLACK);
            }
            if (MCU_Fault.bit2) {
                LCD_DrawImage1BPP(82 + 42 * 6 - 5 + 320, 100 + 38 * 5, BMP_Baojing, RED, BLACK);
            } else {
                LCD_DrawImage1BPP(82 + 42 * 6 - 5 + 320, 100 + 38 * 5, BMP_Zhengchang, GREEN, BLACK);
            }
            if (MCU_Fault.bit1) {
                LCD_DrawImage1BPP(82 + 42 * 6 - 5 + 320, 100 + 38 * 6, BMP_Baojing, RED, BLACK);
            } else {
                LCD_DrawImage1BPP(82 + 42 * 6 - 5 + 320, 100 + 38 * 6, BMP_Zhengchang, GREEN, BLACK);
            }
        }
     */
}

void frmMOTO(void) {
    static unsigned char index_MOTO = 1;
    if (f_index == 0) { //只更新一次
        f_index = 1;
        MOTOFrame(index_MOTO);
    } else if (f_index == 1) {
        f_index = 1;
        MOTOUpdate(index_MOTO);
    } else {
        f_index = 0;
    }
    if (key_AV) {
        key_AV = 0;
        index_MOTO--;
        f_index = 0;
        if (index_MOTO == 0) {
            index_MOTO = 1;
            frmID = 1;
        }
    }
    if (key_up) {
        key_up = 0;
        index_MOTO++;
        f_index = 0;
        if (index_MOTO == 2) {
            index_MOTO = 1;
            frmID = 1;
        }
    }
    if (key_set) {//返回主界面
        key_set = 0;
        frmID = 0;
        f_index = 0;
        Index = 0;
        index_MOTO = 1;
    }
    if (key_long_set) {
        key_long_set = 0;
    }

}

/******************************************************/

void DMQFrame(void) {
    /*unsigned char i = 0;
    LCD_Clear();
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //顶部横线
    LCD_DrawImageSBPP(130 + 200 - 15, 130 - 85, 50, AIR_SYSTEM, WHITE, BLACK); //气泵

    LCD_DrawRect(80, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320 + 320, 90, 1, 380, GREEN);
    for (i = 0; i < 11; i++)
        LCD_DrawRect(80, 90 + i * 38, 640, 1, GREEN);

    LCD_DrawImage1BPP(82, 100 - 2, BMP_DCAC, WHITE, BLACK); //DCAC
    LCD_DrawImage1BPP(82 + 52, 100, BMP_Output, WHITE, BLACK); //输出
    LCD_DrawImage1BPP(82 + 52 + 42, 100, BMP_DL, WHITE, BLACK); //电流
    LCD_DrawImage1BPP(400 - 24, 100, BMP_a, WHITE, BLACK); //A

    LCD_DrawImage1BPP(82, 100 - 2 + 38, BMP_DCAC, WHITE, BLACK); //DCAC
    LCD_DrawImage1BPP(82 + 52, 100 + 38, BMP_Output, WHITE, BLACK); //输出
    LCD_DrawImage1BPP(82 + 52 + 42, 100 + 38, BMP_DY, WHITE, BLACK); //电压
    LCD_DrawImage1BPP(400 - 24, 100 + 38, BMP_v, WHITE, BLACK); //V  

    LCD_DrawImage1BPP(82, 100 - 2 + 38 * 2, BMP_DCAC, WHITE, BLACK); //DCAC Life
    LCD_DrawImage1BPP(82 + 52 + 11, 100 - 2 + 38 * 2, BMP_Life, WHITE, BLACK); //



    LCD_DrawImage1BPP(82 + 320, 100, BMP_DJ, WHITE, BLACK); //电机
    LCD_DrawImage1BPP(82 + 320 + 42, 100, BMP_Wendu, WHITE, BLACK); //温度
    LCD_DrawImage1BPP(720 - 24, 100, BMP_T, WHITE, BLACK); //℃

    LCD_DrawImage1BPP(82 + 320, 100 + 38, BMP_Qibeng, WHITE, BLACK); //气泵状态
    LCD_DrawImage1BPP(82 + 42 + 320, 100 + 38, BMP_Zhuangtai, WHITE, BLACK); //  */
}

void DMQUpdate(void) {
    /*print_SZ_1(82 + 200 + 20 - 16, 100 - 8, AIRDCAC_Current * 0.1, 4, 0, WHITE);
    print_SZ_1(82 + 200 + 20 - 16, 100 - 8 + 38, AIRDCAC_Voltage * 0.1, 4, 0, WHITE);
    print_SZ_1(82 + 200 + 20, 100 - 8 + 38 * 2, AIRDCAC_Life, 3, 0, WHITE);

    updata_DAT(82 + 200 + 300, 100 - 8, AIRDCAC_Temp, 1, 40, WHITE, 3, 0);
    print_D(82 + 180 + 320, 100 - 8 + 38 * 1, AIRDCAC_Status.byte, 8, 0, WHITE);*/
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
    /* unsigned char i = 0;
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
     LCD_DrawImage1BPP(82 + 65, 100 + 2 + 38 * 2, BMP_Muxian, WHITE, BLACK); //母线
     LCD_DrawImage1BPP(82 + 65 + 42, 100 + 2 + 38 * 2, BMP_DY, WHITE, BLACK); //电压
     LCD_DrawImage1BPP(400 - 24, 100 - 2 + 38 * 2, BMP_v, WHITE, BLACK); //V

     LCD_DrawImage1BPP(82, 100 - 2 + 38 * 3, BMP_DCDC, WHITE, BLACK); //DCDC Life
     LCD_DrawImage1BPP(82 + 65 + 11, 100 + 2 + 38 * 3, BMP_Life, WHITE, BLACK);




     LCD_DrawImage1BPP(82 + 320, 100 - 2 + 38 * 0, BMP_DCDC, WHITE, BLACK); //DCDC
     LCD_DrawImage1BPP(82 + 65 + 320, 100 + 2 + 38 * 0, BMP_Mokuai, WHITE, BLACK); //模块
     LCD_DrawImage1BPP(82 + 65 + 42 + 320, 100 + 2 + 38 * 0, BMP_Wendu, WHITE, BLACK); //温度
     LCD_DrawImage1BPP(400 + 320 - 28, 100 - 2 + 38 * 0, BMP_T, WHITE, BLACK); //℃

     LCD_DrawImage1BPP(82 + 320, 100 - 2 + 38 * 1, BMP_DCDC, WHITE, BLACK); //DCDC
     LCD_DrawImage1BPP(82 + 320 + 65, 100 + 2 + 38 * 1, BMP_Gongzuo, WHITE, BLACK); //工作 
     LCD_DrawImage1BPP(82 + 320 + 65 + 42, 100 + 2 + 38 * 1, BMP_Zhuangtai, WHITE, BLACK); //状态   

     LCD_DrawImage1BPP(82 + 320, 100 - 2 + 38 * 2, BMP_DCDC, WHITE, BLACK); //DCDC
     LCD_DrawImage1BPP(82 + 320 + 65, 100 + 2 + 38 * 2, BMP_Guzhang, WHITE, BLACK); //故障
     LCD_DrawImage1BPP(82 + 320 + 65 + 42, 100 + 2 + 38 * 2, BMP_Zhuangtai, WHITE, BLACK); //状态*/
}

void DCDCUpdate(void) {
    /*print_SZ_1(82 + 200 + 20 - 16, 100 - 8, DCDC_Output_Voltage * 0.5, 4, 0, WHITE);
    print_SZ_1(82 + 200 + 20 - 16, 100 - 8 + 38, DCDC_Output_Current * 0.5, 4, 0, WHITE);
    print_SZ_1(82 + 200 + 20 - 16, 100 - 8 + 38 * 2, DCDC_Input_Voltage, 4, 0, WHITE);
    print_SZ_1(82 + 200 + 20, 100 - 8 + 38 * 3, DCDC_Life, 3, 0, WHITE);

    updata_DAT(82 + 200 + 300 + 32, 100 - 8 + 38 * 0, DCDC_Temp, 1, 40, WHITE, 3, 0);
    print_D(82 + 260 + 320 - 16, 100 - 8 + 38 * 1, DCDC_Status, 2, 0, WHITE);
    print_D(82 + 180 + 320, 100 - 8 + 38 * 2, DCDC_Fault_Warn.byte, 8, 0, WHITE);*/
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
    /*unsigned char i = 0;
    LCD_Clear();
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //顶部横线
    LCD_DrawImageSBPP(130 + 200, 130 - 85, 50, OIL_SYSTEM, WHITE, BLACK); //油泵

    LCD_DrawRect(80, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320 + 320, 90, 1, 380, GREEN);
    for (i = 0; i < 11; i++)
        LCD_DrawRect(80, 90 + i * 38, 640, 1, GREEN);

    LCD_DrawImage1BPP(82, 100 - 2, BMP_DCAC, WHITE, BLACK); //DCAC
    LCD_DrawImage1BPP(82 + 52, 100, BMP_Output, WHITE, BLACK); //输出
    LCD_DrawImage1BPP(82 + 52 + 42, 100, BMP_DL, WHITE, BLACK); //电流
    LCD_DrawImage1BPP(400 - 24, 100, BMP_a, WHITE, BLACK); //A

    LCD_DrawImage1BPP(82, 100 - 2 + 38, BMP_DCAC, WHITE, BLACK); //DCAC
    LCD_DrawImage1BPP(82 + 52, 100 + 38, BMP_Output, WHITE, BLACK); //输出
    LCD_DrawImage1BPP(82 + 52 + 42, 100 + 38, BMP_DY, WHITE, BLACK); //电压
    LCD_DrawImage1BPP(400 - 24, 100 + 38, BMP_v, WHITE, BLACK); //V  

    LCD_DrawImage1BPP(82, 100 - 2 + 38 * 2, BMP_DCAC, WHITE, BLACK); //DCAC Life
    LCD_DrawImage1BPP(82 + 52 + 11, 100 - 2 + 38 * 2, BMP_Life, WHITE, BLACK); //



    LCD_DrawImage1BPP(82 + 320, 100, BMP_DJ, WHITE, BLACK); //电机
    LCD_DrawImage1BPP(82 + 320 + 42, 100, BMP_Wendu, WHITE, BLACK); //温度
    LCD_DrawImage1BPP(720 - 24, 100, BMP_T, WHITE, BLACK); //℃

    LCD_DrawImage1BPP(82 + 320, 100 + 38, BMP_Youbeng, WHITE, BLACK); //油泵状态
    LCD_DrawImage1BPP(82 + 42 + 320, 100 + 38, BMP_Zhuangtai, WHITE, BLACK); //    */
}

void DMYUpdate(void) {
    /*print_SZ_1(82 + 200 + 20 - 16, 100 - 8, OILDCAC_Current * 0.1, 4, 0, WHITE);
    print_SZ_1(82 + 200 + 20 - 16, 100 - 8 + 38, OILDCAC_Voltage * 0.1, 4, 0, WHITE);
    print_SZ_1(82 + 200 + 20, 100 - 8 + 38 * 2, OILDCAC_Life, 3, 0, WHITE);

    updata_DAT(82 + 200 + 300, 100 - 8, OILDCAC_Temp, 1, 40, WHITE, 3, 0);
    print_D(82 + 180 + 320, 100 - 8 + 38 * 1, OILDCAC_Status.byte, 8, 0, WHITE);*/
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
    /*   unsigned char i = 0;
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
            LCD_DrawImage1BPP(400 - 24, 100, BMP_v, WHITE, BLACK); //V

            LCD_DrawImage1BPP(82, 100 + 38, BMP_DC, WHITE, BLACK); //电池
            LCD_DrawImage1BPP(82 + 42, 100 + 38, BMP_Zong, WHITE, BLACK); //总
            LCD_DrawImage1BPP(82 + 42 + 21, 100 + 38, BMP_DL, WHITE, BLACK); //电流
            LCD_DrawImage1BPP(400 - 24, 100 + 38, BMP_a, WHITE, BLACK); //A

            LCD_DrawImage1BPP(82, 100 + 38 * 2, BMP_s, WHITE, BLACK); //S
            LCD_DrawImage1BPP(82 + 11, 100 + 38 * 2, BMP_o, WHITE, BLACK); //O
            LCD_DrawImage1BPP(82 + 11 + 11, 100 + 38 * 2, BMP_c, WHITE, BLACK); //C
            LCD_DrawImage1BPP(400 - 24, 100 + 38 * 2, BMP_Baifenhao, WHITE, BLACK); //%

            LCD_DrawImage1BPP(82, 100 + 38 * 3, BMP_DC, WHITE, BLACK); //电池
            LCD_DrawImage1BPP(82 + 42, 100 + 38 * 3, BMP_Zong, WHITE, BLACK); //总
            LCD_DrawImage1BPP(82 + 42 + 21, 100 + 38 * 3, BMP_Shuliang, WHITE, BLACK); //数量

            LCD_DrawImage1BPP(82, 100 + 38 * 4, BMP_b, WHITE, BLACK); //BMS
            LCD_DrawImage1BPP(82 + 11, 100 + 38 * 4, BMP_m, WHITE, BLACK); //
            LCD_DrawImage1BPP(82 + 11 + 11, 100 + 38 * 4, BMP_s, WHITE, BLACK); //
            LCD_DrawImage1BPP(82 + 11 + 11 + 11 + 11, 100 + 38 * 4, BMP_Life, WHITE, BLACK); //LIFE

            for (i = 5; i < 9; i++) {
                LCD_DrawImage1BPP(82, 100 + 38 * i, BMP_Zui, WHITE, BLACK); //最大持续充电电流
                LCD_DrawImage1BPP(82 + 21, 100 + 38 * i, BMP_Da, WHITE, BLACK); //
                if (i == 5 || i == 7)
                    LCD_DrawImage1BPP(82 + 21 + 21, 100 + 38 * i, BMP_Chixu, WHITE, BLACK); //
                else
                    LCD_DrawImage1BPP(82 + 21 + 21, 100 + 38 * i, BMP_Duanshi, WHITE, BLACK); //
                if (i == 5 || i == 6)
                    LCD_DrawImage1BPP(82 + 21 + 21 + 42, 100 + 38 * i, BMP_Chong, WHITE, BLACK); //
                else
                    LCD_DrawImage1BPP(82 + 21 + 21 + 42, 100 + 38 * i, BMP_Fang, WHITE, BLACK); //
                LCD_DrawImage1BPP(82 + 21 + 21 + 42 + 21, 100 + 38 * i, BMP_DL, WHITE, BLACK); //
                LCD_DrawImage1BPP(82 + 21 + 21 + 42 + 21 + 21, 100 + 38 * i, BMP_DL, WHITE, BLACK); //
                LCD_DrawImage1BPP(400 - 24, 100 + 38 * i, BMP_a, WHITE, BLACK); //A
            }

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
                    LCD_DrawImage1BPP(82 + 320 + 42 * 8.5 + 5, 100 + 38 * i, BMP_Hao, WHITE, BLACK); //号
                } else {
                    LCD_DrawImage1BPP(82 + 320 + 21 + 21 + 21 + 21, 100 + 38 * i, BMP_Wendu, WHITE, BLACK); //温度
                    LCD_DrawImage1BPP(720 - 28 - 63 - 5, 100 + 38 * i, BMP_T, WHITE, BLACK); //℃
                }
                LCD_DrawImage1BPP(82 + 320 + 42 * 7 - 5, 100 + 38 * i, BMP_Xiang_BMS, WHITE, BLACK); //箱            
            }

            LCD_DrawImage1BPP(82 + 320, 100 + 38 * 4, BMP_b, WHITE, BLACK); //BMS
            LCD_DrawImage1BPP(82 + 320 + 11, 100 + 38 * 4, BMP_m, WHITE, BLACK); //
            LCD_DrawImage1BPP(82 + 320 + 11 + 11, 100 + 38 * 4, BMP_s, WHITE, BLACK); //
            LCD_DrawImage1BPP(82 + 320 + 11 + 11 + 11, 100 + 38 * 4, BMP_Jiechuqi, WHITE, BLACK);
            LCD_DrawImage1BPP(82 + 320 + 11 + 11 + 11 + 63, 100 + 38 * 4, BMP_Zhuangtai, WHITE, BLACK);

            LCD_DrawImage1BPP(82 + 320, 100 + 38 * 5, BMP_v, WHITE, BLACK); //VCU
            LCD_DrawImage1BPP(82 + 320 + 11, 100 + 38 * 5, BMP_c, WHITE, BLACK); //
            LCD_DrawImage1BPP(82 + 320 + 11 + 11, 100 + 38 * 5, BMP_u, WHITE, BLACK); //
            LCD_DrawImage1BPP(82 + 320 + 11 + 11 + 11, 100 + 38 * 5, BMP_Jiechuqi, WHITE, BLACK);
            LCD_DrawImage1BPP(82 + 320 + 11 + 11 + 11 + 63, 100 + 38 * 5, BMP_Zhuangtai, WHITE, BLACK);

            LCD_DrawImage1BPP(82 + 320, 100 + 38 * 6, BMP_b, WHITE, BLACK); //BMS请求切断高压
            LCD_DrawImage1BPP(82 + 320 + 11, 100 + 38 * 6, BMP_m, WHITE, BLACK); //
            LCD_DrawImage1BPP(82 + 320 + 11 + 11, 100 + 38 * 6, BMP_s, WHITE, BLACK); //
            LCD_DrawImage1BPP(82 + 320 + 11 + 11 + 11, 100 + 38 * 6, BMP_Qingqiu, WHITE, BLACK);
            LCD_DrawImage1BPP(82 + 320 + 11 + 11 + 11 + 42, 100 + 38 * 6, BMP_Qieduan, WHITE, BLACK);
            LCD_DrawImage1BPP(82 + 320 + 11 + 11 + 11 + 42 + 42, 100 + 38 * 6, BMP_Gao, WHITE, BLACK);
            LCD_DrawImage1BPP(82 + 320 + 11 + 11 + 11 + 42 + 42 + 21, 100 + 38 * 6, BMP_Yali, WHITE, BLACK);

            LCD_DrawImage1BPP(82 + 320, 100 + 38 * 7, BMP_DC, WHITE, BLACK); //电池
            LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 7, BMP_Xiang_BMS, WHITE, BLACK); //箱
            LCD_DrawImage1BPP(82 + 320 + 42 + 21, 100 + 38 * 7, BMP_Zong, WHITE, BLACK); //总
            LCD_DrawImage1BPP(82 + 320 + 42 + 42, 100 + 38 * 7, BMP_Shuliang, WHITE, BLACK); //数量
        } else if (index == 2) {
            print_SZ_2(750, 50, 2, 1, 0, WHITE); // 1/2
            LCD_DrawImage1BPP(750 + 11, 50, BMP_I, WHITE, BLACK);
            print_SZ_2(750 + 11 + 14, 50, 2, 1, 0, WHITE);
            LCD_DrawRect(80, 90, 1, 380, GREEN);
            LCD_DrawRect(80 + 320, 90, 1, 380, GREEN);
            LCD_DrawRect(80 + 320 + 320, 90, 1, 380, GREEN);
            for (i = 0; i < 11; i++)
                LCD_DrawRect(80, 90 + i * 38, 640, 1, GREEN);

            LCD_DrawImage1BPP(82, 100, BMP_DC, WHITE, BLACK); //电池
            LCD_DrawImage1BPP(82 + 42, 100, BMP_Lengque, WHITE, BLACK); //冷却
            LCD_DrawImage1BPP(82 + 42 + 42, 100, BMP_Zhuangtai, WHITE, BLACK); //状态

            LCD_DrawImage1BPP(82, 100 + 38, BMP_DC, WHITE, BLACK); //电池
            LCD_DrawImage1BPP(82 + 42, 100 + 38, BMP_Jiare, WHITE, BLACK); //加热
            LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38, BMP_Zhuangtai, WHITE, BLACK); //状态

            LCD_DrawImage1BPP(82, 100 + 38 * 2, BMP_DC, WHITE, BLACK); //电池
            LCD_DrawImage1BPP(82 + 42, 100 + 38 * 2, BMP_Junheng, WHITE, BLACK); //均衡
            LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 2, BMP_Zhuangtai, WHITE, BLACK); //状态

            LCD_DrawImage1BPP(82, 100 + 38 * 3, BMP_b, WHITE, BLACK); //BMS
            LCD_DrawImage1BPP(82 + 11, 100 + 38 * 3, BMP_m, WHITE, BLACK); //
            LCD_DrawImage1BPP(82 + 11 + 11, 100 + 38 * 3, BMP_s, WHITE, BLACK); //
            LCD_DrawImage1BPP(82 + 11 + 11 + 11, 100 + 38 * 3, BMP_Zijian, WHITE, BLACK);
            LCD_DrawImage1BPP(82 + 11 + 11 + 11 + 42, 100 + 38 * 3, BMP_Zhuangtai, WHITE, BLACK);


            LCD_DrawImage1BPP(82 + 320, 100 + 38 * 0, BMP_Dongli, WHITE, BLACK); //
            LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 0, BMP_DC, WHITE, BLACK); //
            LCD_DrawImage1BPP(82 + 320 + 42 + 42, 100 + 38 * 0, BMP_Changjia, WHITE, BLACK); //

            LCD_DrawImage1BPP(82 + 320, 100 + 38 * 1, BMP_Dongli, WHITE, BLACK); //
            LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 1, BMP_DC, WHITE, BLACK); //
            LCD_DrawImage1BPP(82 + 320 + 42 + 42, 100 + 38 * 1, BMP_Eding, WHITE, BLACK); //
            LCD_DrawImage1BPP(82 + 320 + 42 + 42 + 42, 100 + 38 * 1, BMP_Rongliang, WHITE, BLACK); //
            LCD_DrawImage1BPP(720 - 24 - 11, 100 + 38 * 1, BMP_a, WHITE, BLACK); //AH
            LCD_DrawImage1BPP(720 - 24, 100 + 38 * 1, BMP_h, WHITE, BLACK);

            LCD_DrawImage1BPP(82 + 320, 100 + 38 * 2, BMP_Dongli, WHITE, BLACK); //
            LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 2, BMP_DC, WHITE, BLACK); //
            LCD_DrawImage1BPP(82 + 320 + 42 + 42, 100 + 38 * 2, BMP_Eding, WHITE, BLACK); //
            LCD_DrawImage1BPP(82 + 320 + 42 + 42 + 42, 100 + 38 * 2, BMP_DY, WHITE, BLACK); //
            LCD_DrawImage1BPP(720 - 24 - 11, 100 + 38 * 2, BMP_v, WHITE, BLACK); //V

            LCD_DrawImage1BPP(82 + 320, 100 + 38 * 3, BMP_Chong, WHITE, BLACK); //
            LCD_DrawImage1BPP(82 + 320 + 21, 100 + 38 * 3, BMP_DY, WHITE, BLACK); //
            LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 3, BMP_Cishu, WHITE, BLACK); //

            LCD_DrawImage1BPP(82 + 320, 100 + 38 * 4, BMP_DC, WHITE, BLACK); //
            LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 4, BMP_Cailiao, WHITE, BLACK); //  

            LCD_DrawImage1BPP(82 + 320, 100 + 38 * 5, BMP_v, YELLOW, BLACK); //V

            LCD_DrawImage1BPP(82, 100 + 38 * 6, BMP_Jueyuan, WHITE, BLACK); //绝缘
            LCD_DrawImage1BPP(82 + 42, 100 + 38 * 6, BMP_Zhuangtai, WHITE, BLACK); //??

            LCD_DrawImage1BPP(82, 100 + 38 * 7, BMP_Jueyuan, WHITE, BLACK); //绝缘
            LCD_DrawImage1BPP(82 + 42, 100 + 38 * 7, BMP_Baojing, WHITE, BLACK); //??
            LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 7, BMP_Zhuangtai, WHITE, BLACK); //??

            LCD_DrawImage1BPP(82, 100 + 38 * 8, BMP_Jueyuan, WHITE, BLACK); //绝缘
            LCD_DrawImage1BPP(82 + 42, 100 + 38 * 8, BMP_DC, WHITE, BLACK); //电池
            LCD_DrawImage1BPP(82 + 42 + 21, 100 + 38 * 8, BMP_Zu, WHITE, BLACK); //阻
            LCD_DrawImage1BPP(400 - 28, 100 + 38 * 8, BMP_k, WHITE, BLACK); //K
            LCD_DrawImage1BPP(400 - 16, 100 + 2 + 38 * 8, BMP_Omu, WHITE, BLACK); //Ω       

            LCD_DrawImage1BPP(82, 100 + 38 * 9, BMP_Jueyuan, WHITE, BLACK); //绝缘
            LCD_DrawImage1BPP(82 + 42, 100 + 38 * 9, BMP_Life, WHITE, BLACK); //LIFE
        }
     */
}

void BMSUpdate(unsigned char index) {
    /*    if (index == 1) {
            print_SZ_1(82 + 200 + 30, 100 - 8, BMS_V * 0.02, 3, 0, WHITE);
            updata_DAT(82 + 200 + 30 - 16, 100 - 8 + 38, BMS_A, 0.1, 3200, WHITE, 4, 0);
            print_SZ_1(82 + 200 + 30, 100 - 8 + 38 * 2, BMS_SOC * 0.4, 3, 0, WHITE);
            print_SZ_1(82 + 200 + 30, 100 - 8 + 38 * 3, BMS_Number, 3, 0, WHITE);
            print_SZ_1(82 + 200 + 30 + 16, 100 - 8 + 38 * 4, BMS_Life, 2, 0, WHITE);
            updata_DAT(82 + 200 + 30 - 16, 100 - 8 + 38 * 5, BMS_Current_Charge_Limit_Long, 5, 1000, WHITE, 4, 0);
            updata_DAT(82 + 200 + 30 - 16, 100 - 8 + 38 * 6, BMS_Current_Charge_Limit_Short, 5, 1000, WHITE, 4, 0);
            updata_DAT(82 + 200 + 30 - 16, 100 - 8 + 38 * 7, BMS_Current_Disharge_Limit_Long, 5, 0, WHITE, 4, 0);
            updata_DAT(82 + 200 + 30 - 16, 100 - 8 + 38 * 8, BMS_Current_Disharge_Limit_Short, 5, 0, WHITE, 4, 0);


            print_SZ_1(82 + 200 + 300 - 32 - 5, 100 - 8, BAT_Max_Cell_Voltage[0], 4, 3, WHITE);
            print_SZ_1(82 + 200 + 300 - 32 + 16 * 6 - 5, 100 - 8, BAT_Max_Cell_Voltage_Cell_Case[0], 3, 0, WHITE);
            print_SZ_1(82 + 200 + 300 - 32 + 16 * 10 + 5, 100 - 8, BAT_Max_Cell_Voltage_Cell_Number[0], 3, 0, WHITE);

            print_SZ_1(82 + 200 + 300 - 32 - 5, 100 - 8 + 38, BAT_Min_Cell_Voltage[0], 4, 3, WHITE);
            print_SZ_1(82 + 200 + 300 - 32 + 16 * 6 - 5, 100 - 8 + 38, BAT_Min_Cell_Voltage_Cell_Case[0], 3, 0, WHITE);
            print_SZ_1(82 + 200 + 300 - 32 + 16 * 10 + 5, 100 - 8 + 38, BAT_Min_Cell_Voltage_Cell_Number[0], 3, 0, WHITE);

            updata_DAT(82 + 200 + 300 - 5, 100 - 8 + 38 * 2, BAT_Max_Cell_Temperature[0], 1, 40, WHITE, 3, 0);
            print_SZ_1(82 + 200 + 300 - 32 + 16 * 6 - 5, 100 - 8 + 38 * 2, BAT_Max_Cell_Temp_Cell_Case[0], 3, 0, WHITE);

            updata_DAT(82 + 200 + 300 - 5, 100 - 8 + 38 * 3, BAT_Min_Cell_Temperature[0], 1, 40, WHITE, 3, 0);
            print_SZ_1(82 + 200 + 300 - 32 + 16 * 6 - 5, 100 - 8 + 38 * 3, BAT_Min_Cell_Temp_Cell_Case[0], 3, 0, WHITE);

            print_D(82 + 200 + 32 + 320, 100 - 8 + 38 * 4, BMS_KT_Status.byte, 8, 0, WHITE);
            print_D(82 + 200 + 32 + 320, 100 - 8 + 38 * 5, VCU_KT_Status.byte, 8, 0, WHITE);
            if (BMS_Cut == 0) {
                LCD_DrawImage1BPP(82 + 320 + 42 * 7 - 5, 100 + 38 * 6, BMP_Zhengchang, GREEN, BLACK);
            } else if (BMS_Cut == 1) {
                LCD_DrawImage1BPP(82 + 320 + 42 * 7 - 5, 100 + 38 * 6, BMP_Qieduan, RED, BLACK);
            }
            print_SZ_1(82 + 200 + 300 - 32 + 16 * 6 - 5, 100 - 8 + 38 * 7, BMS_Unit_Number, 3, 0, WHITE);
        } else if (index == 2) {
            if (BAT_COLOD_STATUS) {
                LCD_DrawImage1BPP(82 + 42 * 6 - 5, 100 + 38 * 0, BMP_Kai, GREEN, BLACK);
            } else {
                LCD_DrawImage1BPP(82 + 42 * 6 - 5, 100 + 38 * 0, BMP_Guan, RED, BLACK);
            }

            if (WARN_STATUS) {
                LCD_DrawImage1BPP(82 + 42 * 6 - 5, 100 + 38 * 1, BMP_Kai, GREEN, BLACK);
            } else {
                LCD_DrawImage1BPP(82 + 42 * 6 - 5, 100 + 38 * 1, BMP_Guan, RED, BLACK);
            }

            if (BALA_STATUS) {
                LCD_DrawImage1BPP(82 + 42 * 6 - 5, 100 + 38 * 2, BMP_Kai, GREEN, BLACK);
            } else {
                LCD_DrawImage1BPP(82 + 42 * 6 - 5, 100 + 38 * 2, BMP_Guan, RED, BLACK);
            }

            print_SZ_1(82 + 200 + 30, 100 - 8 + 38 * 3, BMS_Self_Check, 2, 0, WHITE);

            print_D(82 + 200 + 32, 100 - 8 + 38 * 6, Oum_Status, 4, 0, WHITE);
            if (Oum_Warn == 0) {
                LCD_DrawImage1BPP(82 + 42 * 6 - 5, 100 + 38 * 7, BMP_Zhengchang, GREEN, BLACK);
            } else {
                LCD_DrawImage1BPP(82 + 42 * 6 - 5, 100 + 38 * 7, BMP_Baojing, RED, BLACK);
            }
            print_SZ_1(82 + 200 + 30 - 48, 100 - 8 + 38 * 8, Oum, 6, 0, WHITE);
            print_SZ_1(82 + 200 + 30, 100 - 8 + 38 * 9, Oum_Life, 3, 0, WHITE);


            print_SZ_1(82 + 200 + 300 + 32 - 5, 100 - 8, BAT_Productor, 2, 0, WHITE);
            print_SZ_1(82 + 200 + 300 - 5, 100 - 8 + 38 * 1, BAT_Ahr * 5, 4, 0, WHITE);
            print_SZ_1(82 + 200 + 300 - 5, 100 - 8 + 38 * 2, BAT_Voltage * 5, 4, 0, WHITE);
            print_SZ_1(82 + 200 + 300 - 32 - 5, 100 - 8 + 38 * 3, BAT_Charge_Times, 6, 0, WHITE);
            print_SZ_1(82 + 200 + 300 + 32 - 5, 100 - 8 + 38 * 4, BAT_Material, 2, 0, WHITE);
            print_SZ_1(82 + 320 + 20, 100 - 8 + 38 * 5, BAT_Verison, 2, 1, WHITE);
            print_SZ_1(82 + 320 + 20 + 160, 100 - 8 + 38 * 5, BAT_Time_Year + 2000, 4, 0, WHITE);
            LCD_DrawImage1BPP(82 + 320 + 20 + 160 + 64, 100 - 8 + 38 * 5, BMP_SZ_1[17], WHITE, BLACK); //-
            print_SZ_1(82 + 320 + 20 + 160 + 80, 100 - 8 + 38 * 5, BAT_Time_Month, 2, 0, WHITE);
        }
     */
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
    unsigned char i = 0, j = 0;
    LCD_Clear();
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //顶部横线
    LCD_DrawImage1BPP(130 + 200 + 24, 130 - 85, BMP_Battery, WHITE, BLACK); //电池
    LCD_DrawImage1BPP(130 + 200 + 50 + 24, 130 - 85, BMP_Message, WHITE, BLACK); //信息

    LCD_DrawImage1BPP(50, 90, BMP_DC, WHITE, BLACK); //电池
    LCD_DrawImage1BPP(50 + 42, 90, BMP_Xinxi, WHITE, BLACK); //信息
    LCD_DrawImage1BPP(50 + 42 + 42 + 15, 90 - 9, BMP_SZ_1[index], GREEN, BLACK);

    for (i = 0; i < 11; i++) {
        LCD_DrawRect(0, 45 + 70 + 36 * i, 800, 1, GRAY);
    }
    for(i = 1;i<5;i++){
    LCD_DrawRect(50 + i * 180, 45 + 70, 1, 360, GRAY);
    }

    for (j = 1; j < 4; j++) {
        for (i = 0; i < 11; i++) {
            if (i < 9) {
                print_SZ_1(5 + 16 + 42 + 42 + 42 + 10, 46 + 70 + i * 36, (index - 1) * 10 + i + 1, 2, 0, YELLOW);
            } else {
                print_SZ_1(5 + 16 + 42 + 42 + 42 + 10 + 16, 46 + 70 + i * 36, 0, 1, 0, YELLOW);
                print_SZ_1(5 + 16 + 42 + 42 + 42 + 10, 46 + 70 + i * 36, index, 1, 0, YELLOW);
            }

            LCD_DrawImage1BPP(5 + 16, 46 + 70 + i * 36 + 8, BMP_DC, WHITE, BLACK);
            LCD_DrawImage1BPP(5 + 16 + 42, 46 + 70 + i * 36 + 8, BMP_Caiji, WHITE, BLACK);
            LCD_DrawImage1BPP(5 + 16 + 42 + 42, 46 + 70 + i * 36 + 8, BMP_Mokuai, WHITE, BLACK);

            LCD_DrawImage1BPP(5 + 16 + 42 + 1 * 180, 46 + 70 + 8 + i * 36, BMP_DY, WHITE, BLACK);
            LCD_DrawImage1BPP(4 + 16 + 16 + 100 + 42 + 30 + 1 * 180, 54 + 70 + i * 36, BMP_v, YELLOW, BLACK);

            LCD_DrawImage1BPP(5 + 16 + 42 + 2 * 180, 46 + 70 + 8 + i * 36, BMP_DL, WHITE, BLACK);
            LCD_DrawImage1BPP(4 + 16 + 16 + 100 + 42 + 30 + 2 * 180, 54 + 70 + i * 36, BMP_a, YELLOW, BLACK);

            LCD_DrawImage1BPP(5 + 16 + 42 + 3 * 180, 46 + 70 + 8 + i * 36, BMP_Wendu, WHITE, BLACK);
            LCD_DrawImage1BPP(4 + 16 + 16 + 100 + 42 + 20 + 3 * 180, 54 + 70 + i * 36, BMP_T, YELLOW, BLACK);
        }
    }
}

void BatteryUpdate(unsigned char index) {
    unsigned char i = 0;
    for (i = 0; i < 10; i++) {
        if (BAT_Cell_Voltage[(index - 1) * 10 + i] == 0)
            print_SZ_1(65 + 23 + 42 + 20 + 1 * 180 - 10, 46 + 70 + 36 * i, BAT_Cell_Voltage[(index - 1) * 10 + i], 3, 0, BLACK); //单体电压
        else print_SZ_1(65 + 23 + 42 + 20 + 1 * 180 - 10, 46 + 70 + 36 * i, BAT_Cell_Voltage[(index - 1) * 10 + i], 3, 0, GREEN); //

        if (BAT_Cell_Current[(index - 1) * 10 + i] == 0)
            print_SZ_1(65 + 23 + 42 + 20 + 2 * 180 - 10, 46 + 70 + 36 * i, BAT_Cell_Current[(index - 1) * 10 + i], 3, 0, BLACK); //单体电流
        else print_SZ_1(65 + 23 + 42 + 20 + 2 * 180 - 10, 46 + 70 + 36 * i, BAT_Cell_Current[(index - 1) * 10 + i], 3, 0, GREEN); //

        if (BAT_Cell_Temperature[(index - 1) * 10 + i] == 0)
            updata_DAT(65 + 23 + 42 + 20 + 3 * 180 - 10, 46 + 70 + 36 * i, BAT_Cell_Temperature[(index - 1) * 10 + i], 1, 40, BLACK, 3, 0); //单体温度
        else updata_DAT(65 + 23 + 42 + 20 + 3 * 180 - 10, 46 + 70 + 36 * i, BAT_Cell_Temperature[(index - 1) * 10 + i], 1, 40, GREEN, 3, 0); //单体温度  
    }
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
        if (index_BAT == 3) {
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
    /*    unsigned char i = 0;
        LCD_Clear();
        LCD_DrawRect(0, 70, 800, 2, YELLOW); //顶部横线
        LCD_DrawImageSBPP(130 + 200 - 2, 130 - 85, 50, AIR_SYSTEM, WHITE, BLACK); //高压

        LCD_DrawRect(80, 90, 1, 380, GREEN);
        LCD_DrawRect(80 + 320, 90, 1, 380, GREEN);
        LCD_DrawRect(80 + 320 + 320, 90, 1, 380, GREEN);
        for (i = 0; i < 11; i++)
            LCD_DrawRect(80, 90 + i * 38, 640, 1, GREEN);

        LCD_DrawImage1BPP(82, 100 + 38 * 0, BMP_Kongtiao, WHITE, BLACK); //空调
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 0, BMP_Gongzuo, WHITE, BLACK); //工作
        LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 0, BMP_Zhuangtai, WHITE, BLACK); //状态

        LCD_DrawImage1BPP(82, 100 + 38 * 1, BMP_Sheding, WHITE, BLACK); //设定
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 1, BMP_Wendu, WHITE, BLACK); //温度
        LCD_DrawImage1BPP(400 - 28, 100 + 38 * 1, BMP_T, WHITE, BLACK); //℃

        LCD_DrawImage1BPP(82, 100 + 38 * 2, BMP_Chesu, WHITE, BLACK); //
        LCD_DrawImage1BPP(82, 100 + 38 * 2, BMP_Feng, WHITE, BLACK); //风速    

        LCD_DrawImage1BPP(82, 100 + 38 * 3, BMP_Xin, WHITE, BLACK); //新风模式 
        LCD_DrawImage1BPP(82 + 21, 100 + 38 * 3, BMP_Feng, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 3, BMP_Mode, WHITE, BLACK); //

        LCD_DrawImage1BPP(82, 100 + 38 * 4, BMP_Gongzuo, WHITE, BLACK); //工作
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 4, BMP_Mode, WHITE, BLACK); //模式

        LCD_DrawImage1BPP(82, 100 + 38 * 5, BMP_Kongtiao, WHITE, BLACK); //空调
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 5, BMP_Life, WHITE, BLACK); //Life



        LCD_DrawImage1BPP(82 + 320, 100, BMP_Chesu, WHITE, BLACK); //车
        LCD_DrawImage1BPP(82 + 320 + 21, 100, BMP_Nei, WHITE, BLACK); //内
        LCD_DrawImage1BPP(82 + 320 + 42, 100, BMP_Wendu, WHITE, BLACK); //温度
        LCD_DrawImage1BPP(720 - 28, 100, BMP_T, WHITE, BLACK); //℃

        LCD_DrawImage1BPP(82 + 320, 100 + 38 * 1, BMP_Chesu, WHITE, BLACK); //车
        LCD_DrawImage1BPP(82 + 320 + 21, 100 + 38 * 1, BMP_Wai, WHITE, BLACK); //外
        LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 1, BMP_Wendu, WHITE, BLACK); //温度
        LCD_DrawImage1BPP(720 - 28, 100 + 38 * 1, BMP_T, WHITE, BLACK); //℃

        LCD_DrawImage1BPP(82 + 320, 100 + 38 * 2, BMP_Kongtiao, WHITE, BLACK); //空调
        LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 2, BMP_Guzhang, WHITE, BLACK); //故障
        LCD_DrawImage1BPP(82 + 320 + 42 + 42, 100 + 38 * 2, BMP_Code, WHITE, BLACK); //代码      
     */
}

void AirUpdate(void) {
    /*    if (AC_Status == 1) {
            LCD_DrawImage1BPP(82 + 42 * 6 - 5, 100 + 38 * 0, BMP_Gongzuo, GREEN, BLACK);
        } else {
            LCD_DrawImage1BPP(82 + 42 * 6 - 5, 100 + 38 * 0, BMP_Tingzhi, RED, BLACK);
        }
        updata_DAT(82 + 200 + 32, 100 - 8 + 38 * 1, AC_Set_Temp, 0.5, 40, WHITE, 3, 0);
        print_SZ_1(82 + 200 + 64, 100 - 8 + 38 * 2, AC_Gear, 1, 0, WHITE);

        if (AC_WindMode == 1) {
            LCD_DrawImage1BPP(82 + 42 * 6 - 5, 100 + 38 * 3, BMP_Wai, GREEN, BLACK);
        } else {
            LCD_DrawImage1BPP(82 + 42 * 6 - 5, 100 + 38 * 3, BMP_Nei, GREEN, BLACK);
        }
        LCD_DrawImage1BPP(82 + 42 * 6 - 5 + 24, 100 + 38 * 3, BMP_Xunhuan, GREEN, BLACK);

        print_SZ_1(82 + 200 + 64, 100 - 8 + 38 * 4, AC_Work_Status, 1, 0, WHITE);
        print_SZ_1(82 + 200 + 32, 100 - 8 + 38 * 5, AC_Life, 3, 0, WHITE);


        updata_DAT(82 + 200 + 300 + 32, 100 - 8 + 38 * 0, AC_Indoor_Temp, 0.5, 40, WHITE, 3, 0);
        updata_DAT(82 + 200 + 300 + 32, 100 - 8 + 38 * 1, AC_Outdoor_Temp, 0.5, 40, WHITE, 3, 0);
        print_SZ_1(82 + 200 + 300 + 32, 100 - 8 + 38 * 2, AC_Fault_Code, 3, 0, WHITE);

     */
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
/******************************************************/
#if 0

void SETFrame(void) {
    LCD_Clear();
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
    } else if (f_index == 1) {
        f_index = 1;
        SETUpdate(Tid, &bcd[0]);
        print_SZ_1(290, 185, total_miles / 10, 7, 0, YELLOW);
    } else {
        f_index = 0;
    }
    if (key_up) {
        key_up = 0;
        if (Tid >= 6)Tid = 0;
        else Tid++;
        tmiles = 0;
        for (i = 0; i < 7; i++) {
            tmiles += bcd[i];
            tmiles = tmiles * 10;
        }
        total_miles = tmiles;
        save_flag = 1;
    }
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
#endif
/******************************************************/

/*******************************************************************************
//函数名: void frm_speed(void)
//功能:  设置处理
//参数:  全局变量
 ******************************************************************************/
void frm_speed(void) {
    if (f_index == 0) {
        f_index = 1;
        key_set = 0;
        key_duble = 0;
        LCD_Clear();
        LCD_DrawRect(0, 0, 800, 50, BLACK);
        LCD_DrawRect(0, 60, 800, 365, BLACK);
        LCD_DrawImage1BPP(360, 30, BMP_Chesu, GREEN, BLACK); //车速
        LCD_DrawImage1BPP(400, 30, BMP_Subi, GREEN, BLACK); //速比

        LCD_DrawImage1BPP(340 - 40, 145, BMP_Subi, YELLOW, BLACK); //
        LCD_DrawImage1BPP(340 - 40, 200, BMP_Chesu, YELLOW, BLACK); //
        LCD_DrawImage1BPP(430, 200, Bmp_kmh, GREEN, BLACK); // /h 

    } else if (f_index == 1) {
        f_index = 1;
        print_SZ_2(340 + 32, 145, e_hm_pulse, 3, 0, GREEN); //SPEED_RATIO  
        print_SZ_2(340 + 32, 200, SPEED, 3, 0, GREEN); //Vspeed    
    } else {
        f_index = 0;
    }
    if (key_set) {
        key_set = 0;
        key_up = 0;
        key_AV = 0;
        frmID = 1;
        f_index = 0;
    }
    if (key_duble) {
        key_duble = 0;
        key_set = 0;
        key_up = 0;
        key_AV = 0;
        key_long_set = 0;
        frmID = 31;
        f_index = 0;
    }
}
#if 0
//密码输入
/*void update_code(unsigned int Tid,unsigned int *ptr){
   unsigned char color=0,color1=0;
   if(Tid==0){ color=RED; color1=RED;  }
   else      { color=GRAY;color1=WHITE;}
   disp_rectange(320+40*0+4,220,4,2,40,2,color);
   LCD_DrawImage1BPP(328+40*0+4,230,BMP_SZ_2[*ptr++],color1,BLACK);

   if(Tid==1){ color=RED; color1=RED;  }
   else      { color=GRAY;color1=WHITE;}
   disp_rectange(320+40*1+4,220,4,2,40,2,color);
   LCD_DrawImage1BPP(328+40*1+4,230,BMP_SZ_2[*ptr++],color1,BLACK);

   if(Tid==2){ color=RED; color1=RED;  }
   else      { color=GRAY;color1=WHITE;}
   disp_rectange(320+40*2+4,220,4,2,40,2,color);
   LCD_DrawImage1BPP(328+40*2+4,230,BMP_SZ_2[*ptr++],color1,BLACK);

   if(Tid==3){ color=RED; color1=RED;  }
   else      { color=GRAY;color1=WHITE;}
   disp_rectange(320+40*3+4,220,4,2,40,2,color);
   LCD_DrawImage1BPP(328+40*3+4,230,BMP_SZ_2[*ptr++],color1,BLACK);   
}

void frm_code(void){  
 static unsigned int  Tid=0;
 static unsigned int  bcd[4]={0,0,0,0};      
  if(f_index==0){
    f_index=1;
    Tid=0;
    key_set =0;
    key_duble=0;
    LCD_DrawRect(0,60,800,365,BLACK);
    LCD_DrawImage1BPP(360,30,BMP_Chesu, GREEN,BLACK);//车速
    LCD_DrawImage1BPP(400,30,BMP_Subi,GREEN,BLACK);//速比
    
    //LCD_DrawImage1BPP(400-40,190,Bmp_srmm,GREEN,BLACK);
    bcd[0]=1;
    bcd[1]=2;   
    bcd[2]=3;
    bcd[3]=4;  
  }else if(f_index==1){
    f_index=1;
    update_code(Tid,&bcd[0]);
  }else{
    f_index=0;
  }
  if(key_set){
    key_set=0;
    if(Tid>=3)Tid=0;
    else      Tid++;
    //验证密码     bcd[2]*1000+ bcd[0]*100+bcd[3]*10+bcd[1];//变换随机数A
    if(single_miles==(unsigned int)(bcd[0]*1000+ bcd[1]*100+bcd[2]*10+bcd[3])){
      frmID=32; 
      f_index=0;    
    }
  }
   if(key_up){
     key_up=0;
    if(Tid<=3){
      if(bcd[Tid]>0) bcd[Tid]--; 
      else           bcd[Tid]=0;
    }else Tid=0;
  }
  if(key_AV){
     key_AV=0;
    if(Tid<=3){
      if(bcd[Tid]<9) bcd[Tid]++; 
      else           bcd[Tid]=9;
    }else Tid=0;
  }
  if(key_duble){
    key_duble=0;
    frmID=0;
    f_index=0;
  }
}
 */
#endif

void disp_system(unsigned char id) {
    unsigned char color = 0;
    if (id == 0) color = GREEN;
    else color = WHITE;
    LCD_DrawImage1BPP(300 + 24, 140, BMP_SZ_2[1], color, BLACK);
    LCD_DrawImage1BPP(316 + 24, 140, BMP_SZ_2[10], color, BLACK);
    LCD_DrawImage1BPP(336 + 24, 140, BMP_Subi, color, BLACK); //速比 
    LCD_DrawImage1BPP(336 + 42 + 24, 140, BMP_Sheding, color, BLACK); //设置
    if (id == 1) color = GREEN;
    else color = WHITE;
    LCD_DrawImage1BPP(300 + 24, 190, BMP_SZ_2[2], color, BLACK);
    LCD_DrawImage1BPP(316 + 24, 190, BMP_SZ_2[10], color, BLACK);
    LCD_DrawImage1BPP(336 + 24, 190, Bmp_Licheng, color, BLACK); //里程
    LCD_DrawImage1BPP(336 + 24 + 42, 190, BMP_Sheding, color, BLACK); //设置 

    if (id == 2) color = GREEN;
    else color = WHITE;
    LCD_DrawImage1BPP(300 + 24, 240, BMP_SZ_2[3], color, BLACK);
    LCD_DrawImage1BPP(316 + 24, 240, BMP_SZ_2[10], color, BLACK);
    LCD_DrawImage1BPP(336 + 24, 240, BMP_Tuichu, color, BLACK); //退出 
}

void frm_system(void) {
    static unsigned char ID = 0;
    if (f_index == 0) {
        f_index = 1;
        LCD_DrawRect(0, 60, 800, 365, BLACK);
        LCD_DrawImage1BPP(360, 30, BMP_Chesu, GREEN, BLACK); //车速
        LCD_DrawImage1BPP(360 + 42, 30, BMP_Subi, GREEN, BLACK); //速比
        key_up = 1;
        ID = 11;
    } else if (f_index == 1) {
        f_index = 1;
    } else {
        f_index = 0;
    }
    if (key_up) {
        if (ID >= 2)ID = 0;
        else ID++;
    }
    if (key_AV) {
        if (ID <= 0)ID = 2;
        else ID--;
    }
    if (key_AV || key_up) {
        disp_system(ID);
        key_up = 0;
        key_AV = 0;
    }
    if (key_set) {
        key_set = 0;
        f_index = 0;
        frmID = ID + 32; //菜单号从2---7开始 
        if (frmID >= 34)frmID = 0; //返回主界面 
    }
}

//总里程设置

void update_miles(unsigned int Tid, unsigned int *ptr) {
    unsigned char color = 0, color1 = 0;
    if (Tid == 0) {
        color = RED;
        color1 = RED;
    } else {
        color = GRAY;
        color1 = WHITE;
    }
    LCD_DrawImage1BPP(268 + 40 * 0, 230, BMP_SZ_2[*ptr++], color1, BLACK);

    if (Tid == 1) {
        color = RED;
        color1 = RED;
    } else {
        color = GRAY;
        color1 = WHITE;
    }
    LCD_DrawImage1BPP(268 + 40 * 1, 230, BMP_SZ_2[*ptr++], color1, BLACK);

    if (Tid == 2) {
        color = RED;
        color1 = RED;
    } else {
        color = GRAY;
        color1 = WHITE;
    }
    LCD_DrawImage1BPP(268 + 40 * 2, 230, BMP_SZ_2[*ptr++], color1, BLACK);

    if (Tid == 3) {
        color = RED;
        color1 = RED;
    } else {
        color = GRAY;
        color1 = WHITE;
    }
    LCD_DrawImage1BPP(268 + 40 * 3, 230, BMP_SZ_2[*ptr++], color1, BLACK);

    if (Tid == 4) {
        color = RED;
        color1 = RED;
    } else {
        color = GRAY;
        color1 = WHITE;
    }
    LCD_DrawImage1BPP(268 + 40 * 4, 230, BMP_SZ_2[*ptr++], color1, BLACK);

    if (Tid == 5) {
        color = RED;
        color1 = RED;
    } else {
        color = GRAY;
        color1 = WHITE;
    }
    LCD_DrawImage1BPP(268 + 40 * 5, 230, BMP_SZ_2[*ptr++], color1, BLACK);

    if (Tid == 6) {
        color = RED;
        color1 = RED;
    } else {
        color = GRAY;
        color1 = WHITE;
    }
    LCD_DrawImage1BPP(268 + 40 * 6, 230, BMP_SZ_2[*ptr++], color1, BLACK);
}

void frm_miles(void) {
    static unsigned int Tid = 0;
    static unsigned int bcd[7] = {0, 0, 0, 0, 0, 0, 0};
    unsigned int i = 0;
    unsigned long tmiles = 0;
    if (f_index == 0) {
        f_index = 1;
        key_up = 0;
        key_AV = 0;
        key_set = 0;
        key_duble = 0;
        LCD_Clear();
        LCD_DrawRect(0, 60, 800, 365, BLACK);

        LCD_DrawImage1BPP(360, 30, Bmp_Licheng, GREEN, BLACK); //里程
        LCD_DrawImage1BPP(400, 30, BMP_Sheding, GREEN, BLACK); //设置

        LCD_DrawImage1BPP(200 + 60, 185, BMP_Zong, WHITE, BLACK); //总计
        LCD_DrawImage1BPP(200 + 60 + 21, 185, Bmp_Licheng, WHITE, BLACK); //里程  

        LCD_DrawImage1BPP(440 + 60, 187, BMP_HZ_KM, WHITE, BLACK); //单位 Km 
    } else if (f_index == 1) {
        f_index = 1;
        update_miles(Tid, &bcd[0]);
        print_SZ_2(325 + 60, 185, total_miles / 10, 7, 0, YELLOW);
    } else {
        f_index = 0;
    }
    if (key_up) {
        key_up = 0;
        if (Tid >= 6)Tid = 0;
        else Tid++;
        tmiles = 0;
        for (i = 0; i < 7; i++) {
            tmiles += bcd[i];
            tmiles = tmiles * 10;
        }
        total_miles = tmiles;
        save_flag = 1;
    }
    if (key_AV) {
        key_AV = 0;
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

void disp_setDATE(void) {
    unsigned int i = 0;
    LCD_DrawImage1BPP(360, 30, BMP_Subi, GREEN, BLACK); //速比
    LCD_DrawImage1BPP(360 + 42, 30, BMP_Sheding, GREEN, BLACK); //设置

    LCD_DrawImage1BPP(300 + 60, 170, BMP_Subi, YELLOW, BLACK); //
    LCD_DrawImage1BPP(390 + 60 + 30, 170, BMP_Sheding, YELLOW, BLACK); //

    LCD_DrawImage1BPP(210 + 60, 205, BMP_SZ_2[1], YELLOW, BLACK); // 
    LCD_DrawImage1BPP(210 + 60, 245, BMP_SZ_2[2], YELLOW, BLACK); //

    for (i = 0; i < 4; i++) {
        LCD_DrawRect(180 + 60, 120 + 35 + 40 * i, 320, 2, GRAY); //横  
    }
    LCD_DrawRect(180 + 60, 120 + 35, 2, 120, GRAY); //竖
    LCD_DrawRect(260 + 60, 120 + 35, 2, 120, GRAY); //
    LCD_DrawRect(380 + 60, 120 + 35, 2, 120, GRAY); //
    LCD_DrawRect(498 + 60, 120 + 35, 2, 120, GRAY); //
}

unsigned int new_pluse = 105;

void update_setDATE(void) {
    unsigned int temp = 0;
    unsigned int x = 180, y = 120;
    print_SZ_2(x + 100 + 60 + 20, y + 85, e_hm_pulse, 3, 0, GREEN); //   
    print_SZ_2(x + 210 + 60 + 30, y + 85, SPEED, 3, 0, GREEN); //车速

    //目标值
    print_SZ_2(x + 100 + 60 + 20, y + 125, new_pluse, 3, 0, RED); // 
    temp = (unsigned int) (RPM * 0.446 * 2 * 60 * 3.14159 / 1000 / 5.571 * new_pluse / 100);
    ; //车速
    print_SZ_2(x + 210 + 60 + 30, y + 125, temp, 3, 0, RED);
}

void frm_setDATE(void) {
    if (f_index == 0) {
        f_index = 1;
        key_up = 0;
        key_AV = 0;
        key_set = 0;
        key_duble = 0;
        LCD_DrawRect(0, 60, 800, 365, BLACK);
        disp_setDATE();
        new_pluse = e_hm_pulse; //
    } else if (f_index == 1) {
        f_index = 1;
        update_setDATE();
    } else {
        f_index = 0;
    }
    if (key_set) {
        key_set = 0;
        key_up = 0;
        key_AV = 0;
        e_hm_pulse = new_pluse;
        EEROM_WriteHMPulse(); //写入
        EEROM_ReadHMPulse(); //读出 校验  
    }

    if (key_up) {
        key_up = 0;
        if (new_pluse < 29990)new_pluse += 1;
        else new_pluse = 30000;
    }
    if (key_AV) {
        key_AV = 0;
        if (new_pluse > 20) new_pluse -= 1;
        else new_pluse = 5;
    }
    if (key_long_set) {
        key_long_set = 0;
        key_up = 0;
        key_AV = 0;
        frmID = 0;
        f_index = 0;
    }
}
/******************************************************************************/
#if 0

void test(void) {
    unsigned char i, j;
    static unsigned char date[40];
    for (j = 0; j < 3; j++) {
        for (i = 0; i < 16; i++) {
            print_SZ_2(35 + 250 * j, 75 + 25 * i, 16 * j + i + 1, 2, 0, WHITE);
        }
    }

    if (IN1) print_SZ_2(35 + 64 + 250 * 0, 75 + 25 * 0, date[0]++, 2, 0, WHITE);
    if (IN2) print_SZ_2(35 + 64 + 250 * 0, 75 + 25 * 1, date[1]++, 2, 0, WHITE);
    if (IN3) print_SZ_2(35 + 64 + 250 * 0, 75 + 25 * 2, date[2]++, 2, 0, WHITE);
    if (IN4) print_SZ_2(35 + 64 + 250 * 0, 75 + 25 * 3, date[3]++, 2, 0, WHITE);
    if (IN5) print_SZ_2(35 + 64 + 250 * 0, 75 + 25 * 4, date[4]++, 2, 0, WHITE);
    if (IN6) print_SZ_2(35 + 64 + 250 * 0, 75 + 25 * 5, date[5]++, 2, 0, WHITE);
    if (IN7) print_SZ_2(35 + 64 + 250 * 0, 75 + 25 * 6, date[6]++, 2, 0, WHITE);
    if (IN8) print_SZ_2(35 + 64 + 250 * 0, 75 + 25 * 7, date[7]++, 2, 0, WHITE);
    if (IN9) print_SZ_2(35 + 64 + 250 * 0, 75 + 25 * 8, date[8]++, 2, 0, WHITE);
    if (IN10) print_SZ_2(35 + 64 + 250 * 0, 75 + 25 * 9, date[9]++, 2, 0, WHITE);
    if (IN11) print_SZ_2(35 + 64 + 250 * 0, 75 + 25 * 10, date[10]++, 2, 0, WHITE);
    if (IN12) print_SZ_2(35 + 64 + 250 * 0, 75 + 25 * 11, date[11]++, 2, 0, WHITE);
    if (IN13) print_SZ_2(35 + 64 + 250 * 0, 75 + 25 * 12, date[12]++, 2, 0, WHITE);
    if (IN14) print_SZ_2(35 + 64 + 250 * 0, 75 + 25 * 13, date[13]++, 2, 0, WHITE);
    if (IN15) print_SZ_2(35 + 64 + 250 * 0, 75 + 25 * 14, date[14]++, 2, 0, WHITE);
    if (IN16) print_SZ_2(35 + 64 + 250 * 0, 75 + 25 * 15, date[15]++, 2, 0, WHITE);



    if (IN17) print_SZ_2(35 + 64 + 250 * 1, 75 + 25 * 0, date[16]++, 2, 0, WHITE);
    if (IN18) print_SZ_2(35 + 64 + 250 * 1, 75 + 25 * 1, date[17]++, 2, 0, WHITE);
    if (IN19) print_SZ_2(35 + 64 + 250 * 1, 75 + 25 * 2, date[18]++, 2, 0, WHITE);
    if (IN20) print_SZ_2(35 + 64 + 250 * 1, 75 + 25 * 3, date[19]++, 2, 0, WHITE);
    if (IN21) print_SZ_2(35 + 64 + 250 * 1, 75 + 25 * 4, date[20]++, 2, 0, WHITE);
    if (IN22) print_SZ_2(35 + 64 + 250 * 1, 75 + 25 * 5, date[21]++, 2, 0, WHITE);
    if (IN23) print_SZ_2(35 + 64 + 250 * 1, 75 + 25 * 6, date[22]++, 2, 0, WHITE);
    if (IN24) print_SZ_2(35 + 64 + 250 * 1, 75 + 25 * 7, date[23]++, 2, 0, WHITE);
    if (IN25) print_SZ_2(35 + 64 + 250 * 1, 75 + 25 * 8, date[24]++, 2, 0, WHITE);
    if (IN26) print_SZ_2(35 + 64 + 250 * 1, 75 + 25 * 9, date[25]++, 2, 0, WHITE);
    if (IN27) print_SZ_2(35 + 64 + 250 * 1, 75 + 25 * 10, date[26]++, 2, 0, WHITE);
    if (IN28) print_SZ_2(35 + 64 + 250 * 1, 75 + 25 * 11, date[27]++, 2, 0, WHITE);
    if (IN29) print_SZ_2(35 + 64 + 250 * 1, 75 + 25 * 12, date[28]++, 2, 0, WHITE);
    if (IN30) print_SZ_2(35 + 64 + 250 * 1, 75 + 25 * 13, date[29]++, 2, 0, WHITE);
    if (IN31) print_SZ_2(35 + 64 + 250 * 1, 75 + 25 * 14, date[30]++, 2, 0, WHITE);
    if (IN32) print_SZ_2(35 + 64 + 250 * 1, 75 + 25 * 15, date[31]++, 2, 0, WHITE);

    if (IN33) print_SZ_2(35 + 64 + 250 * 2, 75 + 25 * 0, date[32]++, 2, 0, WHITE);
    if (IN34) print_SZ_2(35 + 64 + 250 * 2, 75 + 25 * 1, date[33]++, 2, 0, WHITE);
    if (IN35) print_SZ_2(35 + 64 + 250 * 2, 75 + 25 * 2, date[34]++, 2, 0, WHITE);
    if (IN36) print_SZ_2(35 + 64 + 250 * 2, 75 + 25 * 3, date[35]++, 2, 0, WHITE);
    if (IN37) print_SZ_2(35 + 64 + 250 * 2, 75 + 25 * 4, date[36]++, 2, 0, WHITE);
    if (wake_up1) print_SZ_2(35 + 64 + 250 * 2, 75 + 25 * 5, date[37]++, 2, 0, WHITE);
    if (wake_up2) print_SZ_2(35 + 64 + 250 * 2, 75 + 25 * 6, date[38]++, 2, 0, WHITE);
    if (wake_up3) print_SZ_2(35 + 64 + 250 * 2, 75 + 25 * 7, date[39]++, 2, 0, WHITE);

}
#endif

/******************************************************************************/

void LCD_Exec(void) {
    switch (frmID) {
        case 0:
            frmMain();
            //test();
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
        case 30:
            frm_speed();
            break;
        case 31:
            frm_system(); //设置参数信息
            break;
        case 32:
            frm_setDATE(); //设置参数信息
            break;
        case 33:
            frm_miles(); //设置参数信息
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



