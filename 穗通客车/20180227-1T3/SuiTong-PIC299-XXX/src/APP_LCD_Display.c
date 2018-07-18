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
unsigned char witdh = 0;

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
                //color = BLACK;
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
                //color = BLACK;
                color = color1;
            } else {
                f = 0;
                color = color1;
            }
            LCD_DrawImage1BPP(x + i * 16, y, BMP_SZ_1[bcd[i]], color, BLACK);
        }
    }
    LCD_DrawImage1BPP(x - sum * 16, y, BMP_SZ_1[0], color, BLACK);
    LCD_DrawImage1BPP(x + 16 - sum * 16, y + 8, BMP_x, color, BLACK);
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

void LCD_DrawImageSBPP1(unsigned int x, unsigned int y, //没有文字，字数填0，字模为BMP_BLANK       
        //unsigned char witdh, //字体宽度
        __prog__ const unsigned char *img[], //字符串首地址
        unsigned char fcolor, //字体前景色
        unsigned char bcolor //字体背景色
        ) {
    unsigned char i,witd = 0,witdh = 0;
    for (i = 0; img[i] != NULL; i++) {
        LCD_DrawImage1BPP(x + witdh, y, img[i], fcolor, bcolor);
        witd = *(img[i] + 1) * 7;
        witdh += witd;
    }
}

typedef struct {     
    __prog__ const unsigned char **img;
    unsigned char condition;    
    unsigned char Dynamic; 
} CAN_WARN_LIST;

#define CAN_LIST_NUMBER 100
CAN_WARN_LIST list[CAN_LIST_NUMBER] = {
    {0},
    {0},
    {0},
};

static void CAN_WARN_UPDATE(void){
    list[0].condition = 0;
    list[1].condition = 0;
    list[2].condition = 0;
}

static void CAN_WARN(unsigned int x, unsigned int y,
        CAN_WARN_LIST list[]
        ) {
    static unsigned char i = 0;
    CAN_WARN_UPDATE();
    for (; i < CAN_LIST_NUMBER;i++) {
        if (list[i].condition) {
            LCD_DrawImageSBPP1(x, y, list[i].img, YELLOW, BLACK);
            LCD_DrawRect(x + witdh, y, 250 - witdh, 36, BLACK);
            i++;
            break;
        }
    }
    if (i >= CAN_LIST_NUMBER) {
        alarm_update_flag = 0;
        LCD_DrawRect(x, y, 250, 36, BLACK);
        i = 0;
    }
}

void disp_FONT_baojingNew(unsigned int x, unsigned int y) {
    if (alarm_update_flag == 0) {
        alarm_update_flag = 1;
        CAN_WARN(x, y + 8, list);      
    }
}

void disp_miles() {//显示里程
#if DrawBus
    print_SZ_1(10, 318 + 15 + 38 + 2, total_miles / 10, 7, 0, WHITE);
    print_SZ_1(10 + 16, 318 + 15 + 38 * 2 + 2, single_miles, 5, 1, WHITE);
#else
    print_SZ_1(2 + 64 + 4 + 10, 440 - 2 + 13 - 5, total_miles / 10, 7, 0, WHITE);
    print_SZ_1(240 + 80 + 4 + 330 + 30 - 16, 440 - 2 + 13 - 5, single_miles, 5, 1, WHITE);
#endif    
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
    if (frmID == 1 || DrawBus) {
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

        LCD_DrawImage1BPP(x + 260 + 16 * 7, y, BMP_SZ_1[17], WHITE, BLACK); //-

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

#if DrawBus
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
#endif

#if MODE_FV
void updata_QY(void) {
    unsigned char color = RED;
    unsigned int press1 = 50; /*气压传感器量程是0-1.2Mpa ,对应为0-120 进度条0-100*/
    static int update_press1 = 0;
    unsigned int press2 = 90; /*气压传感器量程是0-1.2Mpa ,对应为0-120 进度条0-100*/
    static int update_press2 = 0;
    /*if (ADR[1] < 10) press1 = 0;
    else if (ADR[1] <= 52) press1 = (ADR[1] - 10)*0.48;
    else if (ADR[1] <= 124) press1 = (ADR[1] - 52)*0.56 + 20;
    else if (ADR[1] <= 155) press1 = (ADR[1] - 124)*0.65 + 60;
    else press1 = (ADR[1] - 155)*0.69 + 80;*/
    if (ADV[2] < 500)
        press1 = 0;
    else if (ADV[2] > 3000)
        press1 = 100;
    else
        press1 = (ADV[2] - 500) / 25;

    if (ADV[3] < 500)
        press2 = 0;
    else if (ADV[3] > 3000)
        press2 = 100;
    else
        press2 = (ADV[3] - 500) / 25;

    //阻尼
    PRESS[0] = press1;
    if (press1 > update_press1) update_press1 += 2;
    else if (press1 < update_press1)update_press1--;
    else update_press1 = press1;

    if (update_press1 > 60) color = GREEN;
    else color = RED;
    if (update_press1 > 100) update_press1 = 100;
    print_SZ_1(33 - 7 - 16, 410 + 13 - 5 - 10, update_press1, 3, 2, color);
    LCD_DrawImage1BPP(33 + 9, 380 + 13 - 5 - 10, Bmp_QY1, color, BLACK); //气压1图标
    LCD_DrawRect(38, 108 + 12 - 5 - 10, 44, (260 - update_press1 * 2.6), BLACK); //260/100  
    if (update_press1 % 5 == 0) {
        LCD_DrawRect(38, (368 + 12 - 5 - 10 - update_press1 * 2.6), 44, (update_press1 * 2.6), color);
    } else {
        LCD_DrawRect(38, (368 + 12 - 5 - 10 - update_press1 * 2.6), 44, (update_press1 * 2.6 + 1), color);
    }

    /*if (ADR[2] < 10) press2 = 0;
    else if (ADR[2] <= 52) press2 = (ADR[2] - 10)*0.48;
    else if (ADR[2] <= 124) press2 = (ADR[2] - 52)*0.56 + 20;
    else if (ADR[2] <= 155) press2 = (ADR[2] - 124)*0.65 + 60;
    else press2 = (ADR[2] - 155)*0.69 + 80;*/

    PRESS[1] = press2;
    //阻尼
    if (press2 > update_press2) update_press2 += 2;
    else if (press2 < update_press2)update_press2--;
    else update_press2 = press2;

    if (update_press2 > 60) color = GREEN;
    else color = RED;
    if (update_press2 > 100) update_press2 = 100;
    LCD_DrawImage1BPP(712 + 9, 380 + 13 - 5 - 10, Bmp_QY2, color, BLACK); //气压2图标
    print_SZ_1(712 - 7 - 16, 410 + 13 - 5 - 10, update_press2, 3, 2, color);
    LCD_DrawRect(712 + 5, 108 + 12 - 5 - 10, 44, (260 - update_press2 * 2.6), BLACK); //260/100  
    if (update_press2 % 5 == 0) {
        LCD_DrawRect(712 + 5, (368 + 12 - 5 - 10 - update_press2 * 2.6), 44, (update_press2 * 2.6), color);
    } else {
        LCD_DrawRect(712 + 5, (368 + 12 - 5 - 10 - update_press2 * 2.6), 44, (update_press2 * 2.6 + 1), color);
    }

}
#endif

void disp_BMP_baojing(void) {
    unsigned char color = GRAY;
    //unsigned char color_mode[3];

    if (IN17) 
        color = YELLOW;
    else 
        color = GRAY;
    if (color_old[0] != color) {
        color_old[0] = color;
        LCD_DrawImage1BPP(8, 10, Bmp_baojing[1], color, BLACK); //ABS
    }

    if (LED1) 
        color = RED;
    else 
        color = GRAY;
    if (color_old[1] != color) {
        color_old[1] = color;
        LCD_DrawImage1BPP(8 + 66, 10, Bmp_baojing[4], color, BLACK); //前门开
    }

    if (rKL11) 
        color = RED;
    else 
        color = GRAY;
    if (color_old[2] != color) {
        color_old[2] = color;
        LCD_DrawImage1BPP(8 + 66 * 2, 10, Bmp_baojing[3], color, BLACK); //后舱门
    }

    if (!rKL2) 
        color = RED;
    else 
        color = GRAY;
    if (color_old[3] != color) {
        color_old[3] = color;
        LCD_DrawImage1BPP(8 + 66 * 3, 10, Bmp_baojing[7], color, BLACK); //左前刹车片
        LCD_DrawImage1BPP(8 + 66 * 3 + 17, 10 + 15, BMP_l, color, BLACK);
        print_SZ(8 + 66 * 3 + 17 + 11, 10 + 18, 1, 1, 0, color);
    }

    if (CAN_0x1818D0F3.BMSFlag2.bit3) 
        color = RED;
    else 
        color = GRAY;
    if (color_old[4] != color) {
        color_old[4] = color;
        LCD_DrawImage1BPP(8 + 66 * 4, 10, Bmp_baojing[5], color, BLACK); //绝缘报警
    }

    if (rKL1) 
        color = RED;
    else 
        color = GRAY;
    if (color_old[5] != color) {
        color_old[5] = color;
        LCD_DrawImage1BPP(8 + 66 * 5, 10, Bmp_baojing[2], color, BLACK); //水位

    }

    if (mKL2) 
        color = YELLOW;
    else 
        color = GRAY;
    if (color_old[6] != color) {
        color_old[6] = color;
        LCD_DrawImage1BPP(8 + 66 * 6, 10, Bmp_baojing[12], color, BLACK); //门铃
    }

    if (IN24) 
        color = GREEN;
    else 
        color = GRAY;
    if (color_old[7] != color) {
        color_old[7] = color;
        LCD_DrawImage1BPP(8 + 66 * 7, 10, Bmp_baojing[10], color, BLACK); //干燥器
        
    }

    if (!rKL4) 
        color = RED;
    else 
        color = GRAY;
    if (color_old[8] != color) {
        color_old[8] = color;
        LCD_DrawImage1BPP(8 + 66 * 8, 10, Bmp_baojing[7], color, BLACK); //右前刹车片
        LCD_DrawImage1BPP(8 + 66 * 8 + 17, 10 + 15, BMP_r, color, BLACK);
        print_SZ(8 + 66 * 8 + 17 + 11, 10 + 18, 1, 1, 0, color);
    }

    if (CAN_0x1818D0F3.BMSFlag2.bit6 ) 
        color = RED;
    else 
        color = GRAY;
    if (color_old[9] != color) {
        color_old[9] = color;
        LCD_DrawImage1BPP(8 + 66 * 9, 10, Bmp_baojing[14], color, BLACK); //电池过温
    }

    if (LED2) 
        color = RED;
    else 
        color = GRAY;
    if (color_old[10] != color) {
        color_old[10] = color;
        LCD_DrawImage1BPP(8 + 66 * 10, 10, Bmp_baojing[13], color, BLACK); //中门开状态
    }

    if (!CAN_0x1830A7F3.KT_Status.bit2) 
        color = YELLOW;
    else 
        color = GRAY;
    if (color_old[11] != color) {
        color_old[11] = color;
        LCD_DrawImage1BPP(8 + 66 * 11, 10, Bmp_baojing[11], color, BLACK); //动力电池切断
    }
    /****************************第二行图片****************************************/
    if (0)
        color = YELLOW;
    else 
        color = GRAY;
    if (color_old[12] != color) {
        color_old[12] = color;
        //LCD_DrawImage1BPP(140 + 66 * 0, 74 - 5, Bmp_baojing[14], color, BLACK); //充电插头
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

    if (!rKL6) 
        color = RED;
    else 
        color = GRAY;
    if (color_old[13] != color) {
        color_old[13] = color;
        LCD_DrawImage1BPP(140 + 66 * 1, 74 - 5, Bmp_baojing[7], color, BLACK); //左后刹车片
        LCD_DrawImage1BPP(140 + 66 * 1 + 19, 74 - 5 + 15, BMP_l, color, BLACK);
        print_SZ(140 + 66 * 1 + 19 + 11, 74 - 5 + 18, 2, 1, 0, color);
        //LCD_DrawImage1BPP(140 + 66 * 1, 74 - 5, Bmp_baojing[13], color, BLACK); //重力感应
    }

    if (fKL8 || fKL10 || mKL4 || mKL6 || mKL8 || rKL7 || rKL9) 
        color = RED;
    else 
        color = GRAY;
    if (color_old[14] != color) {
        color_old[14] = color;
        LCD_DrawImage1BPP(140 + 66 * 2, 74 - 5, Bmp_baojing[6], color, BLACK); //应急阀        
    }
    if (fKL8 || fKL10 || mKL6)
        color = RED;
    else 
        color = GRAY;
    print_SZ(140 + 66 * 2 + 54 - 1, 74 - 5 + 18 - 22, 1, 1, 0, color);
    
    if (mKL8 || rKL9 || rKL7)
        color = RED;
    else 
        color = GRAY;
    print_SZ(140 + 66 * 2 + 54 - 1, 74 - 5 + 18 + 16, 2, 1, 0, color);
    ////////////////////////////////////////////////////////////////

    if (CAN_0x0C05A1A7.READY) 
        color = GREEN;
    else 
        color = GRAY;
    if (color_old[15] != color) {
        color_old[15] = color;
        LCD_DrawImage1BPP(138 + 66 * 3 - 1, 74 + 12 - 5, Bmp_READY, color, BLACK); //ready
    }

    if (0) 
        color = RED;
    else 
        color = GRAY;
    if (color_old[16] != color) {
        color_old[16] = color;
        //档位
    }

    if (fADR[0] < 315)
        color = RED;
    else
        color = GRAY;
    if (color_old[17] != color) {
        color_old[17] = color;
        LCD_DrawImage1BPP(140 + 66 * 5, 74 - 5, Bmp_baojing[15], color, BLACK); //仓温报警
    }

    if (!rKL8) 
        color = RED;
    else 
        color = GRAY;
    if (color_old[18] != color) {
        color_old[18] = color;
        LCD_DrawImage1BPP(140 + 66 * 6, 74 - 5, Bmp_baojing[7], color, BLACK); //右后摩擦片
        LCD_DrawImage1BPP(140 + 66 * 6 + 19, 74 - 5 + 15, BMP_r, color, BLACK);
        print_SZ(140 + 66 * 6 + 19 + 11, 74 - 5 + 18, 2, 1, 0, color);
    }

    if (0) 
        color = YELLOW;
    else 
        color = GRAY;
    if (color_old[19] != color) {
        color_old[19] = color;
        //LCD_DrawImage1BPP(140 + 66 * 7, 74 - 5, Bmp_baojing[19], color, BLACK); //报警状态
    }

}

void disp_FONT_baojing(unsigned int x, unsigned int y) {
    static unsigned char al_index = 0; //, Comm_i = 0, Comm_j = 0, FLAG;
    unsigned char color;
    if (alarm_update_flag == 0) { //3S 更新一次 
        switch (al_index) {
            case 0:
                al_index = 1;
                if (Fcan_count == CAN_TIME) {
                    LCD_DrawImageSBPP(x, y + 8,42, QBMKLX, YELLOW, BLACK); //前部
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 1:
                al_index = 2;
                if (Mcan_count == CAN_TIME) {
                    LCD_DrawImageSBPP(x, y + 8, 42,DBMKLX, YELLOW, BLACK); //顶部
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 2:
                al_index = 3;
                if (Rcan_count == CAN_TIME) {
                    LCD_DrawImageSBPP(x, y + 8,42, HBMKLX, YELLOW, BLACK); //后部
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 3:
                al_index = 4;
                

            case 4:
                al_index = 5;
                if (CAN_0x0C06A1A7.VCUOilPumpTempWarn) {
                    LCD_DrawImageSBPP(x, y + 8, 42, YBWDBJ, YELLOW, BLACK);//油泵温度报警
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                } 
                
            case 5:
                al_index = 6;
                /*if (0) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DC, YELLOW, BLACK); //电池高温报警
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Gao, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 21, y + 8, BMP_Wendu, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x0C06A1A7.VCUAirPumpTempWarn) {
                    LCD_DrawImageSBPP(x, y + 8, 42, QBWDBJ, YELLOW, BLACK);//气泵温度报警
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                } 

            case 6:
                al_index = 7;
                /*if (0) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Dan, YELLOW, BLACK); //单体过压报警
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_Ti, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                /*if (0) {
                    LCD_DrawImageSBPP(x, y + 8, 21, GYDC, YELLOW, BLACK); //高压电池1故障
                    print_SZ_2(x + 84, y + 8, 1, 1, 0, YELLOW);
                    LCD_DrawImage1BPP(x + 84 + 11, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 84 + 11 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x0C06A1A7.VCUOverSpeed) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Chaosu, YELLOW, BLACK); //超速报警
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 7:
                al_index = 8;
                /*if (0) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DC, YELLOW, BLACK); //电池组过压报警
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Zu, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 21, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 21, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 21 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 21 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                /*if (0) {
                    LCD_DrawImageSBPP(x, y + 8, 21, GYDC, YELLOW, BLACK); //高压电池2故障
                    print_SZ_2(x + 84, y + 8, 2, 1, 0, YELLOW);
                    LCD_DrawImage1BPP(x + 84 + 11, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 84 + 11 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1818D0F3.BMSFlag1.bit1) {
                    LCD_DrawImageSBPP(x, y + 8, 21, DTDYGG, YELLOW, BLACK); //单体电压过高
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 8:
                al_index = 9;
                /*if (0) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DC, YELLOW, BLACK); //电池组欠压报警
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Zu, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 21, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 21, y + 8, BMP_Qian, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 21 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 21 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1818D0F3.BMSFlag1.bit2) {
                    LCD_DrawImageSBPP(x, y + 8, 21, DTDYGD, YELLOW, BLACK); //单体电压过低
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
                
            case 9:
                al_index = 10;
                /*if (0) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Dan, YELLOW, BLACK); //单体欠压报警
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_Ti, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Qian, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1818D0F3.BMSFlag1.bit3) {
                    LCD_DrawRect(x, y, 100, 36, BLACK);
                    LCD_DrawImageSBPP(x, y + 8, 21, SOCGG, YELLOW, BLACK); //SOC过高
                    LCD_DrawRect(x + 63 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
                
            case 10:
                al_index = 11;
                /*if (0) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Chong, YELLOW, BLACK); //充电枪高温报警
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Qiang, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 63, y + 8, BMP_Gao, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 63 + 21, y + 8, BMP_Wendu, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 63 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 63 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1818D0F3.BMSFlag1.bit4) {
                    LCD_DrawRect(x, y, 100, 36, BLACK);
                    LCD_DrawImageSBPP(x, y + 8, 21, SOCGD, YELLOW, BLACK); //SOC过低
                    LCD_DrawRect(x + 63 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
                
            case 11:
                al_index = 12;
                if (CAN_0x1818D0F3.BMSFlag1.bit5) {
                    LCD_DrawImageSBPP(x, y + 8, 42, DCTXGZ, YELLOW, BLACK); //电池通讯故障
                    LCD_DrawRect(x + 42+42+42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
            case 12:
                al_index = 13;
                /*if (VCU_FaultCode == 145 || VCU_FaultCode == 215) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Fang, YELLOW, BLACK); //放电电流报警
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_DL, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_DL, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                /*if (CAN_0x18EF4BEF.CAP_offline_Warning == 1) {
                    LCD_DrawImageSBPP(x, y + 8, 21, DRLX, YELLOW, BLACK); //电容离线
                    LCD_DrawRect(x + 84, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1818D0F3.BMSFlag1.bit6) {
                    LCD_DrawImageSBPP(x, y + 8, 21, ZDYQY, YELLOW, BLACK); //总电压欠压
                    LCD_DrawRect(x + 42+42+21, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
                
            case 13:
                al_index = 14;
                /*if (VCU_FaultCode == 146 || VCU_FaultCode == 216) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Chong, YELLOW, BLACK); //充电电流报警
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_DL, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_DL, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1818D0F3.BMSFlag1.bit7) {
                    LCD_DrawImageSBPP(x, y + 8, 21, ZDYGY, YELLOW, BLACK); //总电压过压
                    LCD_DrawRect(x + 42 + 42 + 21, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 14:
                al_index = 15;
                /*if (VCU_FaultCode == 144 || VCU_FaultCode == 214) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Dan, YELLOW, BLACK); //单体电压差异报警
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_Ti, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Chayi, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1818D0F3.BMSFlag1.bit8) {
                    LCD_DrawImageSBPP(x, y + 8, 42, JHGZ, YELLOW, BLACK); //均衡故障
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
                
            case 15:
                al_index = 16;
                /*if (VCU_FaultCode == 151 || VCU_FaultCode == 221) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Wendu, YELLOW, BLACK); //温度差异报警
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Chayi, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1818D0F3.BMSFlag2.bit1) {
                    LCD_DrawImage1BPP(x, y + 8,BMP_DC, YELLOW, BLACK); //电池升温过高
                    LCD_DrawImageSBPP(x + 42, y + 8, 21, SWGG, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }              

            case 16:
                al_index = 17;
                /*if (0) {
                    LCD_DrawImageSBPP(x, y + 8, 11, SOC, YELLOW, BLACK); //SOC低报警
                    LCD_DrawImage1BPP(x + 11 + 11 + 11, y + 8, BMP_Di, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11 + 11 + 21, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 11 + 11 + 11 + 21 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1818D0F3.BMSFlag2.bit2) {
                    LCD_DrawImageSBPP(x, y + 8, 42, YWBJ, YELLOW, BLACK);//烟雾报警
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }  

            case 17:
                al_index = 18;
                /*if (VCU_FaultCode == 316) {
                    LCD_DrawImageSBPP(x, y + 8, 11, SOC, YELLOW, BLACK); //SOC高报警
                    LCD_DrawImage1BPP(x + 11 + 11 + 11, y + 8, BMP_Gao, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11 + 11 + 21, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 11 + 11 + 11 + 21 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1818D0F3.BMSFlag2.bit3) {
                    LCD_DrawImageSBPP(x, y + 8, 42, JYBJ, YELLOW, BLACK);//绝缘报警
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                } 

            case 18:
                al_index = 19;
                /*if (VCU_FaultCode == 313) {
                    LCD_DrawImageSBPP(x, y + 8, 11, SOC, YELLOW, BLACK); //SOC差异报警
                    LCD_DrawImage1BPP(x + 11 + 11 + 11, y + 8, BMP_Chayi, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11 + 11 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 11 + 11 + 11 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1818D0F3.BMSFlag2.bit4) {
                    LCD_DrawImageSBPP(x, y + 8, 21, CDDL, YELLOW, BLACK);//充电电流过大
                    LCD_DrawImageSBPP(x + 42 + 42, y + 8, 21, GD, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                } 

            case 19:
                al_index = 20;
                /*if (VCU_FaultCode == 220 || VCU_FaultCode == 150) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DC, YELLOW, BLACK); //电池低温报警
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Di, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 21, y + 8, BMP_Wendu, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1818D0F3.BMSFlag2.bit5) {
                    LCD_DrawImageSBPP(x, y + 8, 21, FDDL, YELLOW, BLACK);//放电电流过大
                    LCD_DrawImageSBPP(x + 42 + 42, y + 8, 21, GD, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                } 

            case 20:
                al_index = 21;
                if (CAN_0x1818D0F3.BMSFlag3.bit6) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Charging, YELLOW, BLACK); //正在充电，禁止行车    
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
                if (CAN_0x1818D0F3.BMSFlag2.bit6) {
                    LCD_DrawImageSBPP(x, y + 8, 42, DCWD, YELLOW, BLACK);//电池温度过高
                    LCD_DrawImageSBPP(x + 42 + 42, y + 8, 21, GG, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                } 

            case 22:
                al_index = 23;
                /*if (VCU_FaultCode == 310 || VCU_FaultCode == 311 || VCU_FaultCode == 312) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Jiare, YELLOW, BLACK); //加热故障
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42, y, 150, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1818D0F3.BMSFlag2.bit8) {
                    LCD_DrawImageSBPP(x, y + 8, 21, WCGD, YELLOW, BLACK);//温差过大
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                } 

            case 23:
                al_index = 24;
                /*if (Concentrated_Lubrication.bit5) {
                    LCD_DrawImageSBPP(x, y + 8, 42, JZRH, YELLOW, BLACK); //集中润滑报警
                    LCD_DrawImage1BPP(x + 84, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 84 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x181CD0F3.BMSFlag4.bit1) {
                    LCD_DrawImageSBPP(x, y + 8, 21, GYHS, YELLOW, BLACK);//高压互锁
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                } 

            case 24:
                al_index = 25;
                /*if (VCU_FaultCode == 163 || VCU_FaultCode == 233) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Chong, YELLOW, BLACK); //充电报警
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42, y, 150, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x181CD0F3.BMSFlag4.bit2) {
                    LCD_DrawRect(x, y, 100, 36, BLACK);
                    LCD_DrawImageSBPP(x, y + 8, 21, SOCTB, YELLOW, BLACK);//SOC跳变
                    LCD_DrawRect(x + 63 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                } 

            case 25:
                al_index = 26;
                /*if (BMS_ChargeGun_Comm == 1) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Chong, YELLOW, BLACK); //充电通讯报警
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Tongxin, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x181CD0F3.BMSFlag4.bit3 || CAN_0x181CD0F3.BMSFlag4.bit5) {
                    LCD_DrawImageSBPP(x, y + 8, 42, CNXTBJ, YELLOW, BLACK);//储能系统报警
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                } 

            case 26:
                al_index = 27;
                /*if (fKL8) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Yanwu, YELLOW, BLACK); //烟雾报警
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42, y, 150, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x181CD0F3.BMSFlag4.bit4) {
                    LCD_DrawImageSBPP(x, y + 8, 21, DTYCBJ, YELLOW, BLACK);//单体压差报警
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                } 

            case 27:
                al_index = 28;
                /*if (BMS_Warn_Type == 1 || BMS_Warn_Type == 2 || BMS_Warn_Type == 3) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Dongli, YELLOW, BLACK); //动力电池故障
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_DC, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1801A79A.DCDC_FaultCode.bit6) {
                    LCD_DrawImageSBPP(x, y + 8, 21, DCDCDL, YELLOW, BLACK);//DCDC短路
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                } 

            case 28:
                al_index = 29;
                /*if (VCU_FaultCode == 168) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Zhilu, YELLOW, BLACK); //支路电压差异报警
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Chayi, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1801A79A.DCDC_FaultCode.bit5) {
                    LCD_DrawImageSBPP(x, y + 8, 21, DCDCGR, YELLOW, BLACK);//DCDC过热
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                } 

            case 29:
                al_index = 30;
                /*if (BMS_FireWarnLevel == 1 || BMS_FireWarnLevel == 2) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DC, YELLOW, BLACK); //电池火灾预警
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Huozai, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Yujing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1801A79A.DCDC_FaultCode.bit1) {
                    LCD_DrawImageSBPP(x, y + 8, 21, DCDCSR, YELLOW, BLACK);//DCDC输入欠压
                    LCD_DrawImageSBPP(x + 44 + 42, y + 8, 21, QY, YELLOW, BLACK);//
                    LCD_DrawRect(x + 44 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                } 

            case 30:
                al_index = 31;
                /*if (VCU_FaultCode == 314) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Chunnengxitong, YELLOW, BLACK); //储能系统不匹配
                    LCD_DrawRect(x + 147, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1801A79A.DCDC_FaultCode.bit2) {
                    LCD_DrawImageSBPP(x, y + 8, 21, DCDCSR, YELLOW, BLACK);//DCDC输入过压
                    LCD_DrawImageSBPP(x + 44 + 42, y + 8, 21, GY, YELLOW, BLACK);//
                    LCD_DrawRect(x + 44 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                } 

            case 31:
                al_index = 32;
                /*if (VCU_FaultCode == 313) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_s, YELLOW, BLACK); //SOC跳变
                    LCD_DrawImage1BPP(x + 11, y + 8, BMP_o, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11, y + 8, BMP_c, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11 + 11, y + 8, BMP_Tiaobian, YELLOW, BLACK);
                    LCD_DrawRect(x + 11 + 11 + 11 + 42, y, 150, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1801A79A.DCDC_FaultCode.bit3) {
                    LCD_DrawImageSBPP(x, y + 8, 21, DCDCSC, YELLOW, BLACK);//DCDC输出状态
                    LCD_DrawImage1BPP(x + 44 + 42, y + 8, BMP_Zhuangtai, YELLOW, BLACK);//
                    LCD_DrawRect(x + 44 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                } 

            case 32:
                al_index = 33;
                /*if (BMS_FireWarnLevel == 1 || BMS_FireWarnLevel == 2) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DC, YELLOW, BLACK); //电池火灾预警
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Huozai, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Yujing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1801A79D.AIRDCAC_FaultCode.bit1) {
                    LCD_DrawImageSBPP(x, y + 8, 42, QBSR, YELLOW, BLACK);//气泵输入欠压
                    LCD_DrawImageSBPP(x + 42 + 42, y + 8, 21, QY, YELLOW, BLACK);//
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                } 

            case 33:
                al_index = 34;
                if (rKL11 && SPEED > 5) {
                    LCD_DrawImageSBPP(x, y + 8, 21, HCMWG, YELLOW, BLACK); //后舱门未关                   
                    LCD_DrawRect(x + 21 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 34:
                al_index = 35;
                /*if (!mKL12 && KT_SIGNAL) {
                    LCD_DrawImageSBPP(x, y + 8, 42, ZLBJ, YELLOW, BLACK); //重力报警
                    LCD_DrawRect(x + 42 + 42, y, 150, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1801A79D.AIRDCAC_FaultCode.bit2) {
                    LCD_DrawImageSBPP(x, y + 8, 42, QBSR, YELLOW, BLACK);//气泵输入过压
                    LCD_DrawImageSBPP(x + 42 + 42, y + 8, 21, GY, YELLOW, BLACK);//
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                } 

            case 35:
                al_index = 36;
                /*for (; Comm_j < 4;) {
                    for (; Comm_i < 8 && !FLAG; Comm_i++) {
                        if (((BMU_Comm_Status[Comm_j].byte >> Comm_i) & 0x01) == 0)
                            FLAG = 1;
                    }
                    if (Comm_i >= 8) {
                        Comm_i = 0;
                        Comm_j++;
                    }
                    if (FLAG) break;
                }
                if (FLAG) {
                    FLAG = 0;
                    LCD_DrawRect(x, y, 200, 36, BLACK); //清除显示区域
                    LCD_DrawImage1BPP(x, y + 8, BMP_Dijige, YELLOW, BLACK); //第x箱电池离线
                    print_SZ(x + 21, y + 12, Comm_j * 8 + Comm_i, 2, 0, YELLOW);
                    LCD_DrawImage1BPP(x + 21 + 16, y + 8, BMP_Xiang_BMS, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 16 + 21, y + 8, BMP_DC, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 16 + 21 + 42, y + 8, BMP_Lixian, YELLOW, BLACK);
                    LCD_DrawRect(x + 21 + 42 + 16 + 21 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
                if (Comm_j >= 4) {
                    Comm_j = 0;
                }*/
                if (CAN_0x1801A79D.AIRDCAC_FaultCode.bit3) {
                    LCD_DrawImageSBPP(x, y + 8, 42, QBSSGL, YELLOW, BLACK);//气泵低压电源
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Di, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 21, y + 8, BMP_Yali, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8,  BMP_Dianyuan, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                } 

            case 36:
                al_index = 37;
                if (CAN_0x1801A79D.AIRDCAC_FaultCode.bit4) {
                    LCD_DrawImageSBPP(x, y + 8, 42, QBSSGL, YELLOW, BLACK);//气泵瞬时过流
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                } 

            case 37:
                al_index = 38;
                /*if (BMS_FireFaultCode > 0) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DC, YELLOW, BLACK); //电池火灾预警故障
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Huozai, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Yujing, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1801A79D.AIRDCAC_FaultCode.bit5) {
                    LCD_DrawImageSBPP(x, y + 8, 42, QBGR, YELLOW, BLACK);//气泵过热
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                } 

            case 38:
                al_index = 39;
                if (CAN_0x1801A79D.AIRDCAC_FaultCode.bit6) {
                    LCD_DrawImageSBPP(x, y + 8, 42, QBDL, YELLOW, BLACK);//气泵短路
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                } 

            case 39:
                al_index = 40;
                if (BAT24V_count == BAT24_TIME) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Xu, YELLOW, BLACK); //蓄电池电压低
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_DC, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 42, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 42 + 42, y + 8, BMP_Di, YELLOW, BLACK);
                    LCD_DrawRect(x + 21 + 42 + 42 + 21, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 40:
                al_index = 41;
                if (CAN_0x1801A79D.AIRDCAC_FaultCode.bit7) {
                    LCD_DrawImageSBPP(x, y + 8, 42, QBGY, YELLOW, BLACK);//气泵过载
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                } 

            case 41:
                al_index = 42;
                /*if (VCU_FaultCode >= 170 && VCU_FaultCode <= 179) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_v, YELLOW, BLACK); //VCU通讯故障
                    LCD_DrawImage1BPP(x + 11, y + 8, BMP_c, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11, y + 8, BMP_u, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11 + 11, y + 8, BMP_Tongxin, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11 + 11 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 11 + 11 + 11 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1801A79D.AIRDCAC_FaultCode.bit8) {
                    LCD_DrawImageSBPP(x, y + 8, 42, QBQX, YELLOW, BLACK);//气泵缺相
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                } 

            case 42:
                al_index = 43;
                if (LED2 && SPEED > 5) {
                    LCD_DrawImageSBPP(x, y + 8, 21, ZMWG, YELLOW, BLACK); //中门未关                   
                    LCD_DrawRect(x + 42 + 42, y, 150, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 43:
                al_index = 44;
                if (LED1 && SPEED > 5) {
                    LCD_DrawImageSBPP(x, y + 8, 21, QMWG, YELLOW, BLACK); //前门未关                   
                    LCD_DrawRect(x + 42 + 42, y, 150, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 44:
                al_index = 45;
                /*if (OILDCAC_FaultCode) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Youbeng, YELLOW, BLACK); //油泵系统故障
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_System, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1801A79B.OILDCAC_FaultCode.bit1) {
                    LCD_DrawImageSBPP(x, y + 8, 42, YBSR, YELLOW, BLACK);//气泵输入过压
                    LCD_DrawImageSBPP(x + 42 + 42, y + 8, 21, GY, YELLOW, BLACK);//
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                } 

            case 45:
                al_index = 46;
                /*if (AIRDCAC_FaultCode) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Qibeng, YELLOW, BLACK); //气泵系统故障
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_System, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/    
                if (CAN_0x1801A79B.OILDCAC_FaultCode.bit2) {
                    LCD_DrawImageSBPP(x, y + 8, 42, YBSR, YELLOW, BLACK);//气泵输入过压
                    LCD_DrawImageSBPP(x + 42 + 42, y + 8, 21, GY, YELLOW, BLACK);//
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                } 

            case 46:
                al_index = 47;
                /*if (VCU_Status3.bit8) {
                    LCD_DrawImageSBPP(x, y + 8, 21, CLYS, YELLOW, BLACK); //车辆已锁
                    LCD_DrawRect(x + 42 + 42, y, 150, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/    
                if (CAN_0x1801A79B.OILDCAC_FaultCode.bit3) {
                    LCD_DrawImageSBPP(x, y + 8, 42, YBSSGL, YELLOW, BLACK);//气泵低压电源
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Di, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 21, y + 8, BMP_Yali, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8,  BMP_Dianyuan, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                } 

            case 47:
                al_index = 48;
                /*if (DCDC_FaultCode) {
                    LCD_DrawImage1BPP(x, y + 8 - 2, BMP_DCDC, YELLOW, BLACK); //DCDC系统故障
                    LCD_DrawImage1BPP(x + 65, y + 8, BMP_System, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 65 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 65 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1801A79B.OILDCAC_FaultCode.bit4) {
                    LCD_DrawImageSBPP(x, y + 8, 42, YBSSGL, YELLOW, BLACK);//气泵瞬时过流
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                } 

            case 48:
                al_index = 49;
                if (CAN_0x1801A79B.OILDCAC_FaultCode.bit5) {
                    LCD_DrawImageSBPP(x, y + 8, 42, YBGR, YELLOW, BLACK);//气泵过热
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                } 
                
            case 49:
                al_index = 50;
                if (BAT24V_count == BAT24_TIME) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Xu, YELLOW, BLACK); //蓄电池电压低
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_DC, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 42, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 42 + 42, y + 8, BMP_Di, YELLOW, BLACK);
                    LCD_DrawRect(x + 21 + 42 + 42 + 21, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
                
            case 50:
                al_index = 51;
                if (CAN_0x1801A79B.OILDCAC_FaultCode.bit6) {
                    LCD_DrawImageSBPP(x, y + 8, 42, YBDL, YELLOW, BLACK);//气泵短路
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                } 
                
            case 51:
                al_index = 52;
                if (CAN_0x1801A79B.OILDCAC_FaultCode.bit7) {
                    LCD_DrawImageSBPP(x, y + 8, 42, YBGY, YELLOW, BLACK);//气泵过载
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                } 
                
            case 52:
                al_index = 53;
                if (CAN_0x1801A79B.OILDCAC_FaultCode.bit8) {
                    LCD_DrawImageSBPP(x, y + 8, 42, YBQX, YELLOW, BLACK);//气泵缺相
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                } 
                
            case 53:
                al_index = 54; 
                if (fKL8) {
                    LCD_DrawImageSBPP(x, y + 8, 21, QMWGFKBJ, YELLOW, BLACK);//前门外阀盖开报警
                    LCD_DrawRect(x + 21 * 8, y, 50, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                } 
                
            case 54:
                al_index = 55; 
                if (fKL10) {
                    LCD_DrawImageSBPP(x, y + 8, 21, QMYJFBJ, YELLOW, BLACK);//前门应急阀报警
                    LCD_DrawRect(x + 21 * 7, y, 50, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                } 
                
            case 55:
                al_index = 56;  
                if (mKL4) {
                    LCD_DrawImageSBPP(x, y + 8, 21, NYJFGKBJ, YELLOW, BLACK);//内应急阀盖开报警
                    LCD_DrawRect(x + 21 * 8, y, 50, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                } 
                
            case 56:
                al_index = 57; 
                if (mKL6) {
                    LCD_DrawImageSBPP(x, y + 8, 21, QMCNYJFBJ, YELLOW, BLACK);//前门车内应急阀报警
                    LCD_DrawRect(x + 21 * 9, y, 50, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                } 
                
            case 57:
                al_index = 58;  
                if (mKL8) {
                    LCD_DrawImageSBPP(x, y + 8, 21, HMCNYJFBJ, YELLOW, BLACK);//中门车内应急阀报警
                    LCD_DrawRect(x + 21 * 9, y, 50, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                } 
                
            case 58:
                al_index = 59; 
                if (rKL7) {
                    LCD_DrawImageSBPP(x, y + 8, 21, HMWYJFGKBJ, YELLOW, BLACK);//中门外应急阀盖开报警
                    //LCD_DrawRect(x + 21 * 10, y, 50, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                } 

            case 59:
                al_index = 60; 
                if (rKL9) {
                    LCD_DrawImageSBPP(x, y + 8, 21, HMWYJFBJ, YELLOW, BLACK);//中门外应急阀报警
                    LCD_DrawRect(x + 21 * 8, y, 50, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                } 
              
            case 60:
                al_index = 61;
                if (CAN_0x1819D0F3.Warn_level) {
                    LCD_DrawImageSBPP1(x, y + 8, DCXTGZ, YELLOW, BLACK); //电池系统等级故障
                    LCD_DrawRect(x + 21 * 4, y, 21, 36, BLACK);
                    print_SZ_2(x + 21 * 4 + 5, y + 8, CAN_0x1819D0F3.Warn_level, 1, 0, YELLOW);
                    LCD_DrawRect(x + 21 * 8, y, 150, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }    
                
            case 61:
                al_index = 62; 
                if (CAN_0x0C04A1A7.FaultLevel) {
                    if(CAN_0x0C04A1A7.FaultLevel == 1)
                        color = RED;
                    else 
                        color = YELLOW;
                    LCD_DrawImageSBPP1(x, y + 8, ZCXTGZ, color, BLACK); //整车系统等级故障 故障代码xxxxxx
                    LCD_DrawRect(x + 21 * 4, y, 21, 36, BLACK);
                    print_SZ_2(x + 5 + 21 * 4, y + 8, CAN_0x0C04A1A7.FaultLevel, 1, 0, color);
                    LCD_DrawImageSBPP1(x + 21 * 9, y + 8, GZDM, color, BLACK);
                    print_SZ_2(x + 21 * 13, y + 8, CAN_0x0C04A1A7.FaultCode1 + ((unsigned int) CAN_0x0C04A1A7.FaultCode2 << 8), 6, 0, color);
                    //LCD_DrawRect(x + 21 * 8 + 11, y, 50, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }                           
                
            default:
                al_index = 0;
                LCD_DrawRect(x, y, 400, 36, BLACK); //清除显示区域
                break;
        }
    }

}

void updata_Dangwei(unsigned int x, unsigned int y) {//0 : N;  1：D;  2 :R;  3：P
    unsigned char gear = 1;
    gear = 0;
    if (CAN_0x0C06A1A7.VCUGearS) gear = 4;
    else if (CAN_0x0C06A1A7.VCUGearR) gear = 2;
    else if (CAN_0x0C06A1A7.VCUGearN) gear = 0;
    else if (CAN_0x0C06A1A7.VCUGearD) gear = 1;
    else gear = 0;
    LCD_DrawImage1BPP(x, y, BMP_DANGWEI[gear], GREEN, BLACK); //档位更新 
}

void updata_SOC(unsigned int x, unsigned int y) {
    unsigned char color = WHITE;
    static unsigned char soc = 100;
    soc = CAN_0x1818D0F3.BMS_SOC * 0.4;
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
    DCDY = CAN_0x1818D0F3.BMS_V / 10;
    if(DCDY<1000)
        DCDY = 0;
    else
        DCDY = DCDY - 1000;
    
    if (DCDY >= 1800) 
        DCDY = 800;
    print_SZ_1(x, y, DCDY, 3, 0, WHITE); //电池电压数值 x=120+72+30   y=150+60-2
    if (frmID == 0)
        LCD_DrawRect(x - 358, y + 2, DCDY * 3.31 * 0.125, 28, GREEN); // 331/100  
    if (DCDY < 800 && frmID == 0)//当为100时会出错
        LCD_DrawRect((x - 358 + DCDY * 3.31 * 0.125), y + 2, (331 - DCDY * 3.31 * 0.125), 28, BLACK);
}

void updata_DCDL(unsigned int x, unsigned int y) {
    unsigned int DCDL = 100;
    DCDL = CAN_0x1818D0F3.BMS_A / 10;
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
    LCD_DrawRect(0, 64 - 5, 800, 1, GRAY);
    for (i = 1; i < 12; i++) {
        LCD_DrawRect(4 + 66 * i, 0, 1, 64 - 5, GRAY);
    }
    //新增加的符号片框架2016/11/1
    LCD_DrawRect(136, 128 - 10, 528, 1, GRAY);
    for (i = 1; i < 10; i++) {
        LCD_DrawRect(70 + 66 * i, 64 - 5, 1, 64 - 5, GRAY);
    }
    //每次进入主界面，符号片颜色都是灰色，若不处理，只会第一次上电显示灰色，翻页后就不显示灰色
    for (i = 0; i < 24; i++) {
        color_old[i] = 0;
    }

#if DrawBus
    LCD_DrawRect(0, 430 + 15, 800, 2, GREEN); //底部横线 

    BMP_BUS(150, 150 + 40); //画BUS

    LCD_DrawImageSBPP(180, 150, 11, SOC, WHITE, BLACK); //SOC

    disp_rectange(225, 150 + 5 - 10, 335, 2, 32, 2, WHITE);
    for (i = 0; i < 3; i++)
        LCD_DrawRect(225 + 83 + 83 * i, 145 - 10, 2, 10, WHITE);

    LCD_DrawImage1BPP(225 - 4, 155 - 14 - 10, BMP_SZ[0], WHITE, BLACK); //0

    print_SZ(225 + 83 + 83 + 83 + 84 - 12, 155 - 14 - 10, 100, 3, 0, WHITE); //100
    LCD_DrawImage1BPP(650, 155, BMP_Baifenhao, WHITE, BLACK);

    LCD_DrawImage1BPP(10, 365 + 15 - 50 + 10, Bmp_Licheng, YELLOW, BLACK); //里程
    LCD_DrawImage1BPP(125, 318 + 15 + 38 + 8, BMP_HZ_KM, WHITE, BLACK); //单位 Km
    LCD_DrawImage1BPP(125, 318 + 15 + 38 * 2 + 8, BMP_HZ_KM, WHITE, BLACK); //单位 Km

    LCD_DrawImage1BPP(165, 365 + 15 - 50 + 10, BMP_DY, YELLOW, BLACK); //高压电池
    LCD_DrawImage1BPP(165, 365 + 15 - 50 + 10, BMP_Gao, YELLOW, BLACK);
    LCD_DrawImage1BPP(165 + 42, 365 + 15 - 50 + 10, BMP_DC, YELLOW, BLACK);
    LCD_DrawImage1BPP(265, 318 + 15 + 38 + 8, BMP_v, WHITE, BLACK); //V
    LCD_DrawImage1BPP(265, 318 + 15 + 38 * 2 + 8, BMP_a, WHITE, BLACK); //A

    LCD_DrawImageSBPP(295, 365 + 15 - 50 + 10, 21, DTDY, YELLOW, BLACK); //单体电压
    LCD_DrawImage1BPP(395, 318 + 15 + 38 + 8, BMP_v, WHITE, BLACK); //V
    LCD_DrawImage1BPP(395, 318 + 15 + 38 * 2 + 8, BMP_v, WHITE, BLACK); //V

    LCD_DrawImageSBPP(420, 365 + 15 - 50 + 10, 21, DTWD, YELLOW, BLACK); //单体温度
    LCD_DrawImage1BPP(420 + 90, 318 + 15 + 10 + 38, BMP_T, WHITE, BLACK); //℃
    LCD_DrawImage1BPP(420 + 90, 318 + 15 + 10 + 38 * 2, BMP_T, WHITE, BLACK); //℃

    LCD_DrawImage1BPP(540, 365 + 15 - 50 + 10, BMP_DJ, YELLOW, BLACK); //电机/控制器
    LCD_DrawImage1BPP(540 + 42, 365 + 15 - 50 + 10, BMP_I, YELLOW, BLACK);
    LCD_DrawImage1BPP(540 + 42 + 11, 365 + 15 - 50 + 10, BMP_KZQ, YELLOW, BLACK);
    LCD_DrawImage1BPP(640, 365 + 15 - 50 + 10 + 38, BMP_T, WHITE, BLACK); //℃
    LCD_DrawImage1BPP(640, 365 + 15 - 50 + 10 + 38 * 2, BMP_T, WHITE, BLACK); //℃

    LCD_DrawImageSBPP(670, 365 + 15 - 50 + 10, 42, DJZJ, YELLOW, BLACK); //电机转矩
    LCD_DrawImage1BPP(670 + 100, 365 + 15 - 50 + 10 + 38, BMP_n, WHITE, BLACK); //NM
    LCD_DrawImage1BPP(670 + 100 + 11, 365 + 15 - 50 + 10 + 38, BMP_m, WHITE, BLACK); //

    disp_rectange(5, 365 + 15 - 50, 150, 1, 115, 1, GREEN);
    disp_rectange(5 + 140 + 15, 365 + 15 - 50, 125, 1, 115, 1, GREEN);
    disp_rectange(5 + 270 + 15, 365 + 15 - 50, 125 - 5, 1, 115, 1, GREEN);
    disp_rectange(5 + 400 + 10, 365 + 15 - 50, 125 - 5, 1, 115, 1, GREEN);
    disp_rectange(5 + 530 + 5, 365 + 15 - 50, 125, 1, 115, 1, GREEN);
    disp_rectange(5 + 660 + 5, 365 + 15 - 50, 130 - 5, 1, 115, 1, GREEN); 

#elif MODE_FV
    //动力电池电流 电压 SOC 外观
    LCD_DrawRect(0, 430 + 10 + 2, 800, 2, GREEN); //底部横线 

    LCD_DrawImage1BPP(175, 160 + 13 - 5 - 10, BMP_Voltage, WHITE, BLACK); //电压
    disp_rectange(225, 150 + 5 + 13 - 5 - 10, 335, 2, 32, 2, WHITE);
    LCD_DrawRect(225 + 83, 145 + 13 - 5 - 10, 2, 10, WHITE);
    LCD_DrawRect(225 + 83 + 83, 145 + 13 - 5 - 10, 2, 10, WHITE);
    LCD_DrawRect(225 + 83 + 83 + 83, 145 + 13 - 5 - 10, 2, 10, WHITE);

    LCD_DrawImage1BPP(225 - 4, 155 - 14 + 13 - 5 - 10, BMP_SZ[0], WHITE, BLACK); //0
    LCD_DrawImage1BPP(225 + 83 + 83 + 83 + 84 - 12, 155 - 14 + 13 - 5 - 10, BMP_SZ[8], WHITE, BLACK); //8
    LCD_DrawImage1BPP(225 + 83 + 83 + 83 + 84 - 4, 155 - 14 + 13 - 5 - 10, BMP_SZ[0], WHITE, BLACK); //0
    LCD_DrawImage1BPP(225 + 83 + 83 + 83 + 84 + 4, 155 - 14 + 13 - 5 - 10, BMP_SZ[0], WHITE, BLACK); //0   
    LCD_DrawImage1BPP(660, 155 + 13 - 5 - 10, BMP_V, WHITE, BLACK);

    LCD_DrawImage1BPP(170, 150 + 5 + 60 + 13 - 5 - 10, BMP_SOC, WHITE, BLACK); //SOC
    disp_rectange(225, 150 + 5 + 60 + 13 - 5 - 10, 335, 2, 32, 2, WHITE);
    LCD_DrawRect(225 + 83, 145 + 60 + 13 - 5 - 10, 2, 10, WHITE);
    LCD_DrawRect(225 + 83 + 83, 145 + 60 + 13 - 5 - 10, 2, 10, WHITE);
    LCD_DrawRect(225 + 83 + 83 + 83, 145 + 60 + 13 - 5 - 10, 2, 10, WHITE);
    LCD_DrawImage1BPP(225 - 4, 155 - 14 + 60 + 13 - 5 - 10, BMP_SZ[0], WHITE, BLACK); //0
    LCD_DrawImage1BPP(225 + 83 + 83 + 83 + 84 - 12, 155 - 14 + 60 + 13 - 5 - 10, BMP_SZ[1], WHITE, BLACK); //1
    LCD_DrawImage1BPP(225 + 83 + 83 + 83 + 84 - 4, 155 - 14 + 60 + 13 - 5 - 10, BMP_SZ[0], WHITE, BLACK); //0
    LCD_DrawImage1BPP(225 + 83 + 83 + 83 + 84 + 4, 155 - 14 + 60 + 13 - 5 - 10, BMP_SZ[0], WHITE, BLACK); //0
    LCD_DrawImage1BPP(660, 155 + 60 + 13 - 5 - 10, BMP_BAIFENHAO, WHITE, BLACK);

    LCD_DrawImageSBPP(180 - 20 + 2, 260 + 8, 21, ZGDY, WHITE, BLACK); //最高电压
    LCD_DrawImage1BPP(225 + 83 + 83 - 22, 260 + 8, BMP_v, WHITE, BLACK); //V

    LCD_DrawImageSBPP(180 - 20 + 2, 260 + 8 + 36, 21, ZDDY, WHITE, BLACK); //最低电压
    LCD_DrawImage1BPP(225 + 83 + 83 - 22, 260 + 8 + 36, BMP_v, WHITE, BLACK); //℃

    LCD_DrawImageSBPP(225 + 83 + 83 + 2, 260 + 8, 42, DCDL, WHITE, BLACK); //电池电流
    //LCD_DrawImageSBPP(225 + 83 + 83 + 2 + 42, 260 + 8, 11, SOE, WHITE, BLACK); //SOE
    LCD_DrawImage1BPP(615 - 22, 260 + 8, BMP_a, WHITE, BLACK); //A

    LCD_DrawImageSBPP(225 + 83 + 83 + 2, 260 + 8 + 36, 21, ZGWD, WHITE, BLACK); //最高温度
    LCD_DrawImage1BPP(615 - 22, 260 + 8 + 36, BMP_T, WHITE, BLACK); //V

    LCD_DrawImage1BPP(180 - 20 + 2, 260 + 8 + 36 * 2, BMP_DJ, WHITE, BLACK); //电机
    LCD_DrawImage1BPP(180 - 20 + 2 + 43, 260 + 8 + 36 * 2, BMP_KZQ, WHITE, BLACK); //控制器
    //LCD_DrawImage1BPP(180 - 20 + 2 + 43 + 64, 365 - 50 + 10, BMP_Wendu, WHITE, BLACK); //温度
    LCD_DrawImage1BPP(225 + 83 + 83 - 22, 260 + 8 + 36 * 2, BMP_T, WHITE, BLACK); //℃

    LCD_DrawImageSBPP(225 + 83 + 83 + 2, 260 + 8 + 36 * 2, 42, DJZS, WHITE, BLACK); //电机转速
    //LCD_DrawImage1BPP(615 - 22, 260 + 8 + 36 * 2, BMP_v, WHITE, BLACK); //V
    LCD_DrawImage1BPP(615 - 34, 260 + 8 + 36 * 2, BMP_RPM, WHITE, BLACK); //RPM

    LCD_DrawImage1BPP(180 - 20 + 2, 260 + 8 + 36 * 3, BMP_DJ, WHITE, BLACK); //电机
    LCD_DrawImage1BPP(180 - 20 + 2 + 43, 260 + 8 + 36 * 3, BMP_Wendu, WHITE, BLACK); //温度
    LCD_DrawImage1BPP(225 + 83 + 83 - 22, 260 + 8 + 36 * 3, BMP_T, WHITE, BLACK); //℃

    //LCD_DrawImageSBPP(225 + 83 + 83 + 2, 260 + 8 + 36 * 3, 63, FDJQH, WHITE, BLACK);
    LCD_DrawImageSBPP(615 - 34, 260 + 8 + 36 * 3, 11, CHAR_LH, WHITE, BLACK); //LH


    LCD_DrawRect(180 - 20, 260, 1, 180 + 2, WHITE);
    LCD_DrawRect(225 + 83 + 83, 260, 1, 180 - 36 + 2, WHITE);
    LCD_DrawRect(615, 260, 1, 180 + 2, WHITE);
    for (i = 0; i < 5; i++) {
        LCD_DrawRect(180 - 20, 260 + 36 * i, 350 + 85 + 20, 1, WHITE);
    }

    //气压柱1外观
    LCD_DrawRect(33, 100 + 13 - 5 - 10, 51, 3, WHITE); //
    LCD_DrawRect(33, 100 + 13 - 5 - 10, 3, 135, WHITE);
    LCD_DrawRect(84, 100 + 13 - 5 - 10, 3, 135, WHITE);

    LCD_DrawRect(33, 235 + 13 - 5 - 10, 3, 135, RED);
    LCD_DrawRect(84, 235 + 13 - 5 - 10, 3, 138, RED);
    LCD_DrawRect(33, 370 + 13 - 5 - 10, 51, 3, RED); //

    //标尺
    LCD_DrawImage1BPP(13 - 5, 95 + 13 - 5 - 10, BMP_SZ_2[1], RED, BLACK); //1
    LCD_DrawImage1BPP(21 - 5, 95 + 13 - 5 - 10, BMP_SZ_2[0], RED, BLACK); //0
    LCD_DrawImage1BPP(21 - 5, 225 + 13 - 5 - 10, BMP_SZ_2[5], RED, BLACK); //5
    LCD_DrawImage1BPP(21 - 5, 360 + 13 - 5 - 10, BMP_SZ_2[0], RED, BLACK); //0

    LCD_DrawImageSBPP(33 - 7 + 32 + 16, 410 + 13 - 5, 11, CHAR_MPA, WHITE, BLACK); //Mpa

    //气压柱2外观
    LCD_DrawRect(712, 100 + 13 - 5 - 10, 51, 3, WHITE);
    LCD_DrawRect(712, 100 + 13 - 5 - 10, 3, 135, WHITE);
    LCD_DrawRect(712 + 51, 100 + 13 - 5 - 10, 3, 135, WHITE);

    LCD_DrawRect(712, 235 + 13 - 5 - 10, 3, 135, RED);
    LCD_DrawRect(712 + 51, 235 + 13 - 5 - 10, 3, 138, RED);
    LCD_DrawRect(712, 370 + 13 - 5 - 10, 51, 3, RED); //

    LCD_DrawImage1BPP(770, 95 + 13 - 5 - 10, BMP_SZ_2[1], RED, BLACK); //1
    LCD_DrawImage1BPP(770 + 8, 95 + 13 - 5 - 10, BMP_SZ_2[0], RED, BLACK); //0
    LCD_DrawImage1BPP(770, 225 + 13 - 5 - 10, BMP_SZ_2[5], RED, BLACK); //5
    LCD_DrawImage1BPP(770, 360 + 13 - 5 - 10, BMP_SZ_2[0], RED, BLACK); //0 

    LCD_DrawImageSBPP(712 - 7 + 32 + 16, 410 + 13 - 5, 11, CHAR_MPA, WHITE, BLACK); //Mpa
    
    /*--------------------------------------------
    以下显示的格式为:(ODO 000.0Km       00:00          TRIP0000000Km)
    ---------------------------------------------*/
    LCD_DrawImage1BPP(2, 440 + 3 + 13 - 5, Bmp_ODO, YELLOW, BLACK); //累计里程 ODO  

    LCD_DrawImage1BPP(210 - 16, 440 + 10, BMP_HZ_KM, WHITE, BLACK); //单位 Km

    LCD_DrawImage1BPP(240 + 300 + 30, 440 + 3 + 13 - 5, Bmp_TRIP, YELLOW, BLACK); //单次里程 TRIF

    LCD_DrawImage1BPP(404 + 336 + 30, 440 + 10, BMP_HZ_KM, WHITE, BLACK); //单位 Km
    
#elif MODE_EV
    LCD_DrawRect(0, 430 + 8, 800, 1, GREEN); //底部横线
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

    LCD_DrawImageSBPP(60, 365 - 50 + 10 + 8, 21, DTDY, WHITE, BLACK); //单体电压
    LCD_DrawImage1BPP(15 + 130, 318 + 38 + 8 + 8, BMP_v, WHITE, BLACK); //V
    LCD_DrawImage1BPP(15 + 130, 318 + 38 * 2 + 8 + 8, BMP_v, WHITE, BLACK); //V

    LCD_DrawImageSBPP(70 + 550, 365 - 50 + 10 + 8, 21, DTWD, WHITE, BLACK); //单体温度
    LCD_DrawImage1BPP(800 - 90, 318 + 10 + 8 + 38, BMP_T, WHITE, BLACK); //℃
    LCD_DrawImage1BPP(800 - 90, 318 + 10 + 8 + 38 * 2, BMP_T, WHITE, BLACK); //℃

    LCD_DrawImageSBPP(180 - 20 + 2, 365 - 50 + 10 + 8, 42, DJKZQ, WHITE, BLACK); //电机控制器
    LCD_DrawImage1BPP(225 + 83 + 83 - 22, 365 - 50 + 10 + 8, BMP_T, WHITE, BLACK); //℃

    LCD_DrawImageSBPP(225 + 83 + 83 + 2, 365 - 50 + 10 + 8, 42, DJZS, WHITE, BLACK); //电机转速
    LCD_DrawImage1BPP(615 - 34, 365 - 50 + 10 + 8, BMP_RPM, WHITE, BLACK); //RPM

    LCD_DrawImageSBPP(225 + 83 + 83 + 2, 365 - 50 + 10 + 8 + 38, 42, DJZJ, WHITE, BLACK); //电机转矩
    LCD_DrawImage1BPP(615 - 22, 365 - 50 + 10 + 8 + 38, BMP_n, WHITE, BLACK); //NM
    LCD_DrawImage1BPP(615 - 22 + 11, 365 - 50 + 10 + 8 + 38, BMP_m, WHITE, BLACK); //


    LCD_DrawImageSBPP(180 - 20 + 2, 365 - 50 + 10 + 8 + 38, 42, DJWD, WHITE, BLACK); //电机温度
    LCD_DrawImage1BPP(225 + 83 + 83 - 22, 365 - 50 + 10 + 8 + 38, BMP_T, WHITE, BLACK); //℃

    //框框
    LCD_DrawRect(55, 365 - 50 + 8, 680, 1, GREEN);
    LCD_DrawRect(55, 365 - 50 + 8, 1, 65 + 50, GREEN);
    LCD_DrawRect(735, 365 - 50 + 8, 1, 65 + 50, GREEN);
    LCD_DrawRect(180 - 20, 365 - 50 + 8, 350 + 85 + 20, 1, GREEN);
    LCD_DrawRect(180 - 20, 365 - 50 + 8, 1, 65 + 50, GREEN);
    LCD_DrawRect(225 + 83 + 83, 365 - 50 + 8, 1, 65 + 50 - 38, GREEN);
    LCD_DrawRect(615, 365 - 50 + 8, 1, 65 + 50, GREEN);
    LCD_DrawRect(180 - 20, 365 - 50 + 8 + 38, 350 + 85 + 20, 1, GREEN);
    LCD_DrawRect(180 - 20, 365 - 50 + 8 + 38 + 38, 350 + 85 + 20, 1, GREEN);
    
    /*--------------------------------------------
    以下显示的格式为:(ODO 000.0Km       00:00          TRIP0000000Km)
    ---------------------------------------------*/
    LCD_DrawImage1BPP(2, 440 + 3 + 13 - 5, Bmp_ODO, YELLOW, BLACK); //累计里程 ODO  

    LCD_DrawImage1BPP(210 - 16, 440 + 10, BMP_HZ_KM, WHITE, BLACK); //单位 Km

    LCD_DrawImage1BPP(240 + 300 + 30, 440 + 3 + 13 - 5, Bmp_TRIP, YELLOW, BLACK); //单次里程 TRIF

    LCD_DrawImage1BPP(404 + 336 + 30, 440 + 10, BMP_HZ_KM, WHITE, BLACK); //单位 Km
#endif

}

void frmMain(void) {
#if DrawBus
    if (f_index == 0) { //只更新一次
        f_index = 1;
        mainFrame();
    } else if (f_index == 1) {
        f_index = 2;
        updata_DAT(700, 318 + 15 + 38, 0, 1, 3200, WHITE, 4, 0); //电机转矩
    } else if (f_index == 2) {
        f_index = 3;
        disp_BMP_baojing();
        print_SZ_1(305, 318 + 15 + 38, 0, 4, 3, WHITE); //单体高电压
        print_SZ_1(305, 318 + 15 + 38 * 2, 0, 4, 3, WHITE); //单体低电压
    } else if (f_index == 3) {
        f_index = 4;
        disp_miles();
        //门开关图像报警
        if (LED2) {
            BMP_Men_Kai(150 + 195, 190 + 27, RED); //门2开
        } else
            BMP_Men_Guan(150 + 195, 190 + 27, WHITE); //门2关
        if (LED1)
            BMP_Men_Kai(150 + 184 + 215, 190 + 27, RED); //门1开
        else
            BMP_Men_Guan(150 + 184 + 215, 190 + 27, WHITE); //门1关        
    } else if (f_index == 4) {
        f_index = 5;
        disp_time(360, 440 + 8, timer);
        updata_DAT(540 + 50, 318 + 15 + 38 * 2, 0, 1, 40, WHITE, 3, 0); //电机控制器温度
        updata_DAT(540 + 50, 318 + 15 + 38, 0, 1, 40, WHITE, 3, 0); //电机温度
    } else if (f_index == 5) {
        f_index = 6;
        updata_SOC(585, 155 - 10);
        updata_DAT(150 + 45, 318 + 15 + 38, 0 * 0.1, 1, 0, WHITE, 4, 0); //总电压
        updata_DAT(150 + 45, 318 + 15 + 38 * 2, 0 * 0.1, 1, 3200, WHITE, 4, 0); //总电流
        //updata_DCDL(150 + 45 + 16, 318 + 15 + 38 * 2); //总电流
    } else if (f_index == 6) {
        f_index = 7;
        updata_DAT(410 + 50, 318 + 15 + 38, 0, 1, 40, WHITE, 3, 0); //单体高温
        updata_DAT(410 + 50, 318 + 15 + 38 * 2, 0, 1, 40, WHITE, 3, 0); //单体低温       
        disp_FONT_baojing(2, 447);
    } else if (f_index == 7) {
        f_index = 1;
        updata_Dangwei(138 + 17 + 66 * 4, 74 - 5);
    } else {
        f_index = 0;
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
                if (t == 10) t = 0;
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
            if (time_flag)
                t_add = 1;
            else t_add = 0;
        }
#if VIDEO
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
                /*if ((VCU_Gear == 1) && !R_flag) {//倒挡
                    key_AV = 1; //模拟AV开关按一次
                    AV_CH = 0; //0+1=1  倒车
                    R_flag = 1; //防止一直进入这个函数，导致key_AV总是置1
                }
                if ((VCU_Gear != 1) && R_flag) {
                    key_AV = 1;
                    AV_CH = 4; // 0 返回MCU界面
                    R_flag = 0;
                    M_flag = 0;
                }*/

                //中门选择使能按键 优先级小于倒车
                /*if (VCU_Gear != 1) {
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
                }*/
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
#endif
    }
    
#elif MODE_FV
    if (f_index == 0) { //只更新一次
        f_index = 1;
        mainFrame();
    } else if (f_index == 1) {
        f_index = 2;
        //updata_DAT(480 + 30, 318 + 13 - 5, MCU_NM, 0.25, 8192, WHITE, 4, 0); //电机转矩
        //updata_DCDL(585, 155 + 13 - 5 + 60);
        updata_DAT(480 + 40 - 10, 260 + 2 + 36 * 0, 0, 8, 1000, WHITE, 4, 0); //电池电流
        //print_SZ_1(480 + 40, 260 + 3 + 36 * 2, 0, 3, 0, WHITE); //电容电压   
        updata_DAT(480 + 40 - 10, 260 + 3 + 36 * 2, 0, 20, 2000, WHITE, 4, 0); //电机转速 
    } else if (f_index == 2) {
        f_index = 3;
        disp_BMP_baojing();
        print_SZ_1(313 - 16 * 2, 260 + 2, 0 * 1.5, 4, 3, WHITE); //单体高电压
        print_SZ_1(313 - 16 * 2, 260 + 2 + 36 * 1, 0 * 1.5, 4, 3, WHITE); //单体低电压
    } else if (f_index == 3) {
        f_index = 4;
        disp_miles();
        updata_DCDY(585, 155 + 13 - 5 - 10);
    } else if (f_index == 4) {
        f_index = 5;
        disp_time(330, 440 + 13, timer);
        updata_DAT(313, 260 + 2 + 36 * 2, 0, 1, 40, WHITE, 3, 0); //电机控制器温度
        updata_DAT(313, 260 + 2 + 36 * 3, 0, 1, 40, WHITE, 3, 0); //电机温度
    } else if (f_index == 5) {
        f_index = 6;
        updata_SOC(585, 155 + 13 + 60 - 5 - 10);
        updata_QY();
    } else if (f_index == 6) {
        f_index = 7;
        updata_DAT(480 + 40 + 6, 260 + 2 + 36 * 1, 0, 0.2, 50, WHITE, 3, 0); //单体高温       
        disp_FONT_baojing(162, 260 + 1 + 36 * 4);
    } else if (f_index == 7) {
        f_index = 1;
        updata_Dangwei(138 + 17 + 66 * 4, 74 - 5);
        print_SZ_1(480 + 40 - 10, 260 + 3 + 36 * 3, 0 * 0.05, 4, 0, WHITE);
        //print_H(480 + 30 -16, 318+15 + 38*2, tcu_spn, 5, 0, WHITE); //spn
        //print_SZ_1(480 + 30 + 16, 318 + 38, TCU_code, 3, 0, color); //系统代码
    } else {
        f_index = 0;
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
#if VIDEO
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
                /*if ((VCU_Gear == 1) && !R_flag) {//倒挡
                    key_AV = 1; //模拟AV开关按一次
                    AV_CH = 0; //0+1=1  倒车
                    R_flag = 1; //防止一直进入这个函数，导致key_AV总是置1
                }
                if ((VCU_Gear != 1) && R_flag) {
                    key_AV = 1;
                    AV_CH = 4; // 0 返回MCU界面
                    R_flag = 0;
                    M_flag = 0;
                }*/

                //中门选择使能按键 优先级小于倒车
                /*if (VCU_Gear != 1) {
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
                }*/
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
#endif
    }
    
#elif (MODE_EV && !DrawBus)
    if (f_index == 0) { //只更新一次
        f_index = 1;
        mainFrame();
    } else if (f_index == 1) {
        f_index = 2;
        print_SZ_1(60, 318 + 8 + 38, CAN_0x181AD0F3.Battery_single_H, 4, 3, WHITE); //单体高
        print_SZ_1(60, 318 + 8 + 38 * 2, CAN_0x181AD0F3.Battery_single_L, 4, 3, WHITE); //单体低
        updata_DAT(313, 318 + 8 + 38, CAN_0x0C03A1A7.MotorTemperature, 1, 40, WHITE, 3, 0); //电机温度
    } else if (f_index == 2) {
        f_index = 3;
        disp_BMP_baojing();
        updata_DAT(480 + 30, 318 + 8, CAN_0x0C03A1A7.MotoSpeed, 1, 20000, WHITE, 4, 0); //电机转速
        updata_DAT(480 + 30, 318 + 8 + 38, CAN_0x0C08A1A7.MotoTorque, 0.1, 2000, WHITE, 4, 0);
    } else if (f_index == 3) {
        f_index = 4;
        disp_miles();
        updata_DCDL(585, 155 + 60);
    } else if (f_index == 4) {
        f_index = 5;
        disp_time(330, 440 + 5, timer);
        updata_DAT(313, 318 + 8, CAN_0x0C03A1A7.MotorTemperature_Controller, 1, 40, WHITE, 3, 0); //电机控制器温度
    } else if (f_index == 5) {
        f_index = 6;
        updata_SOC(585, 155 + 60 + 60);
        updata_DAT(800 - 150, 318 + 8 + 38, CAN_0x1819D0F3.BMS_T_H, 1, 40, WHITE, 3, 0); //单体高温
        updata_DAT(800 - 150, 318 + 8 + 38 * 2, CAN_0x181BD0F3.BAT_Min_Cell_Temperature, 1, 40, WHITE, 3, 0); //单体低温
    } else if (f_index == 6) {
        f_index = 7;
        updata_DCDY(585, 155);
        disp_FONT_baojing(162, 318 + 8 + 38 * 2);
    } else if (f_index == 7) {
        f_index = 1;
        updata_Dangwei(138 + 15 + 66 * 4, 70);
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
#if VIDEO
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
                /*if ((VCU_Gear == 1) && !R_flag) {//倒挡
                    key_AV = 1; //模拟AV开关按一次
                    AV_CH = 0; //0+1=1  倒车
                    R_flag = 1; //防止一直进入这个函数，导致key_AV总是置1
                }
                if ((VCU_Gear != 1) && R_flag) {
                    key_AV = 1;
                    AV_CH = 4; // 0 返回MCU界面
                    R_flag = 0;
                    M_flag = 0;
                }*/

                //中门选择使能按键 优先级小于倒车
                /*if (VCU_Gear != 1) {
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
                }*/
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
#endif
    }
#endif   
}

/******************************************************/
void ICFrame(unsigned char index) { //仪表框架
    unsigned char i;
    LCD_Clear();
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //顶部横线

    print_SZ_2(750, 50, index, 1, 0, WHITE); // x/1
    LCD_DrawImage1BPP(750 + 11, 50, BMP_I, WHITE, BLACK);
    print_SZ_2(750 + 11 + 14, 50, 4, 1, 0, WHITE);

    LCD_DrawImageSBPP(130 + 200 + 200, 130 - 85 + 4, 11, CHAR_CAN, WHITE, BLACK); //CAN通讯
    LCD_DrawImage1BPP(130 + 200 + 200 + 11 + 11 + 11, 130 - 85 + 4, BMP_Tongxin, WHITE, BLACK);

    if (index == 1) {
        LCD_DrawImageSBPP(130 + 200, 130 - 85, 50, IC_SYSTEM, WHITE, BLACK); //仪表            
        /***********************仪表开关量采集*********************************/
        /*************************第一列开关***********************************/
        //IN1  左转向开关
        LCD_DrawImage1BPP(35, 75 + 25 * 0, BMP_IC_Zuo, WHITE, BLACK);
        LCD_DrawImage1BPP(35 + 21, 75 + 25 * 0, BMP_IC_Zhuanxiang, WHITE, BLACK);
        LCD_DrawImage1BPP(35 + 42 + 21, 75 + 25 * 0, BMP_IC_Kaiguan, WHITE, BLACK);
        //IN2  ON档
        LCD_DrawImageSBPP(35, 75 + 25 * 1, 11, ON, WHITE, BLACK);
        //IN3  ACC档
        LCD_DrawImageSBPP(35, 75 + 25 * 2, 11, ACCD, WHITE, BLACK);       
        //IN4  ST档
        LCD_DrawImageSBPP(35, 75 + 25 * 3, 11, START, WHITE, BLACK);
        //IN5  右转向开关
        LCD_DrawImage1BPP(35, 75 + 25 * 4, BMP_IC_You, WHITE, BLACK);
        LCD_DrawImage1BPP(35 + 21, 75 + 25 * 4, BMP_IC_Zhuanxiang, WHITE, BLACK);
        LCD_DrawImage1BPP(35 + 42 + 21, 75 + 25 * 4, BMP_IC_Kaiguan, WHITE, BLACK);
        //IN6  小灯开关
        LCD_DrawImageSBPP(35, 75 + 25 * 5, 21, XDKG, WHITE, BLACK);      
        //IN7  远光灯
        LCD_DrawImageSBPP(35, 75 + 25 * 6, 21, YGDKG, WHITE, BLACK);
        //IN8  近光灯
        LCD_DrawImageSBPP(35, 75 + 25 * 7, 21, JGDKG, WHITE, BLACK);
        //IN9  前雾灯
        LCD_DrawImageSBPP(35, 75 + 25 * 8, 21, QWDKG, WHITE, BLACK);
        //IN10 后雾灯
        LCD_DrawImageSBPP(35, 75 + 25 * 9, 21, HWDKG, WHITE, BLACK);
        //IN11 喇叭开关
        LCD_DrawImageSBPP(35, 75 + 25 * 10, 42, LBKG, WHITE, BLACK);
        //IN12
        //IN13
        //IN14 
        //IN15 
        //IN16 
        /*************************第二列开关***********************************/
        //IN17 ABS故障
        LCD_DrawImageSBPP(285, 75 + 25 * 0, 11, ABS, WHITE, BLACK);
        //LCD_DrawImageSBPP(285, 75 + 25 * 0, 42, FSKG, WHITE, BLACK);
        //LCD_DrawImageSBPP(285, 75 + 25 * 1, 42, LPKG, WHITE, BLACK);
        //IN18 顶灯开关
        //LCD_DrawImageSBPP(285, 75 + 25 * 1, 21, DDKG, WHITE, BLACK);
        //IN19 前门开开关
        //LCD_DrawImageSBPP(285, 75 + 25 * 2, 21, QMKKG, WHITE, BLACK);
        //IN20 
        //IN21 雨刮喷水
        //LCD_DrawImage1BPP(285, 75 + 25 * 4, BMP_IC_Yugua, WHITE, BLACK);
        //LCD_DrawImage1BPP(285 + 42, 75 + 25 * 4, BMP_Penshui, WHITE, BLACK);
        //IN22 
        //IN23 
        //IN24 暖风
        LCD_DrawImage1BPP(285, 75 + 25 * 7, BMP_Ganzaoqi, WHITE, BLACK);
        //IN25 
        //IN26 中门应急阀报警
        //IN27 前门应急阀报警       
        //IN28 前门关开关
        //LCD_DrawImageSBPP(285, 75 + 25 * 11, 21, QMGKG, WHITE, BLACK);
        //IN29 
        //IN30 辅助气压报警
        //LCD_DrawImageSBPP(285, 75 + 25 * 13, 42, FZQYBJ, WHITE, BLACK);
        //IN31 除霜高档
        /*LCD_DrawImage1BPP(285, 75 + 25 * 14, BMP_Chushuang, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 42, 75 + 25 * 14, BMP_Gao, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 63, 75 + 25 * 14, BMP_Dang, WHITE, BLACK);*/
        //IN32 除霜低档
        /*LCD_DrawImage1BPP(285, 75 + 25 * 15, BMP_Chushuang, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 42, 75 + 25 * 15, BMP_Di, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 63, 75 + 25 * 15, BMP_Dang, WHITE, BLACK);*/

        /*************************第三列开关***********************************/
        //IN33
        //IN34
        //IN35
        //IN36
        //IN37 
        //IN38 危险报警开关
        LCD_DrawImageSBPP(535, 75 + 25 * 5, 42, WXBJKG, WHITE, BLACK);      
        //IN39 充电唤醒
        LCD_DrawImage1BPP(535, 75 + 25 * 6, BMP_Chong, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 21, 75 + 25 * 6, BMP_DC, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 42, 75 + 25 * 6, BMP_Huanxing, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 84, 75 + 25 * 6, BMP_IC_Kaiguan, WHITE, BLACK);
        //IN40 电源开关
        LCD_DrawImageSBPP(535, 75 + 25 * 7,42, DYKG, WHITE, BLACK);
        
        LCD_DrawImage1BPP(535, 75 + 25 * 10, BMP_IC_Qian, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 21, 75 + 25 * 10, BMP_Qiya, WHITE, BLACK);

        LCD_DrawImage1BPP(535, 75 + 25 * 11, BMP_IC_Hou, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 21, 75 + 25 * 11, BMP_Qiya, WHITE, BLACK);

        //LCD_DrawImage1BPP(535 + 21, 75 + 25 * 8, BMP_Youliang, WHITE, BLACK);

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
        LCD_DrawImage1BPP(130 + 200, 130 - 85, BMP_QIAN, WHITE, BLACK); //前
        LCD_DrawImage1BPP(130 + 200 + 25, 130 - 85, BMP_MOKUAI, WHITE, BLACK); //模块
        LCD_DrawImage1BPP(130 + 200 + 25 + 50, 130 - 85, BMP_Message, WHITE, BLACK); //信息
        for (i = 0; i < 15; i++) {
            LCD_DrawImage1BPP(60 + 280, 75 + 3 + 25 * i, BMP_a, WHITE, BLACK);
        }
        /*************************前模块输出***********************************/
        /*for (i = 0; i < 3; i++) {
            LCD_DrawImage1BPP(60, 75 + 25 * i, BMP_IC_Yugua, WHITE, BLACK);
        }*/
        //OUT1  喇叭输出
        //LCD_DrawImageSBPP(60 + 42, 75 + 25 * 0,42, LBSC, WHITE, BLACK);
        //OUT2  风扇电源
        LCD_DrawImageSBPP(60, 75 + 25 * 1, 42, FSDY, WHITE, BLACK);
        //OUT3  喇叭输出
        LCD_DrawImageSBPP(60, 75 + 25 * 2, 42, LBSC, WHITE, BLACK);
        /*for (i = 0; i < 3; i++) {
            if (i != 2) LCD_DrawImage1BPP(60 + 63, 75 + 25 * i, BMP_Dang, WHITE, BLACK);
            LCD_DrawImage1BPP(60 + 84, 75 + 25 * i, BMP_DJ, WHITE, BLACK);
        }*/
        //OUT4  除霜
        LCD_DrawImage1BPP(60, 75 + 25 * 3, BMP_Chushuang, WHITE, BLACK);      
        //OUT5  
        //OUT6  右转向灯
        LCD_DrawImage1BPP(60, 75 + 25 * 5, BMP_IC_You, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 5, BMP_IC_Zhuanxiang, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 63, 75 + 25 * 5, BMP_IC_Deng, WHITE, BLACK);
        //OUT7  左转向灯
        LCD_DrawImage1BPP(60, 75 + 25 * 6, BMP_IC_Zuo, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 6, BMP_IC_Zhuanxiang, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 63, 75 + 25 * 6, BMP_IC_Deng, WHITE, BLACK);
        //OUT8  播放机
        LCD_DrawImage1BPP(60, 75 + 25 * 7, BMP_Bofangji, WHITE, BLACK);
        //OUT9  左远光灯
        LCD_DrawImageSBPP(60, 75 + 25 * 8, 21, ZYGDSC, WHITE, BLACK);
        //OUT10 电源输出
        //LCD_DrawImageSBPP(60, 75 + 25 * 9, 42, DYSC, WHITE, BLACK);
        //OUT11 右远光灯输出
        LCD_DrawImageSBPP(60, 75 + 25 * 10, 21, YYGDSC, WHITE, BLACK);
        //OUT12 前门灯输出
        //LCD_DrawImageSBPP(60, 75 + 25 * 11, 21, QMDSC, WHITE, BLACK);
        //OUT13 左近光灯输出
        LCD_DrawImageSBPP(60, 75 + 25 * 12, 21, ZJGDSC, WHITE, BLACK);
        //OUT14 小灯
        LCD_DrawImageSBPP(60, 75 + 25 * 13, 21, XD, WHITE, BLACK);
        //OUT15 右近光灯
        LCD_DrawImageSBPP(60, 75 + 25 * 14, 21, ZJGDSC, WHITE, BLACK);
        //ADD
        LCD_DrawImageSBPP(60, 75 + 25 * 15, 11, ADD, WHITE, BLACK);
        /***********************前模块开关采集*********************************/
        //KL1 路牌开关
        LCD_DrawImageSBPP(285 + 150, 75 + 25 * 0, 42, LPKG, WHITE, BLACK);
        //KL2  
        //LCD_DrawImageSBPP(285 + 150, 75 + 25 * 1, 42, GGKG, WHITE, BLACK);
        //KL3  
        //KL4
        //KL5  
        //KL6
        //KL7  
        //KL8 前门外阀盖开报警
          LCD_DrawImageSBPP(285 + 150, 75 + 25 * 7, 21, QMWGFKBJ, WHITE, BLACK);
        //KL9  
        //LCD_DrawImageSBPP(285 + 150, 75 + 25 * 8, 42, YWBJKG, WHITE, BLACK);
        //KL10 
          //前门应急阀报警
          LCD_DrawImageSBPP(285 + 150, 75 + 25 * 9, 21, QMYJFBJ, WHITE, BLACK);
        //KL11 
        //KL12 
        //KL12 
        //KL13 地址选择1
        LCD_DrawImageSBPP(285 + 150, 75 + 25 * 12,42, DZXZ1, WHITE, BLACK);
        //KL14 地址选择2
        LCD_DrawImageSBPP(285 + 150, 75 + 25 * 13, 42, DZXZ2, WHITE, BLACK);
        //KL15 前门开信号
        LCD_DrawImageSBPP(285 + 150, 75 + 25 * 14, 21, QMKXH, WHITE, BLACK);
        //KH1  

        LCD_DrawImage1BPP(535 + 63 - 11, 75 + 25 * 0, BMP_Xinhao, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 63 - 11 + 42, 75 + 25 * 0, BMP_SZ_2[1], WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 63 + 42 + 16 * 4 - 4, 75 + 25 * 0, BMP_Omu, WHITE, BLACK); //Ω
        LCD_DrawImage1BPP(535 + 63 + 42 + 16 * 4 + 16 * 5, 75 + 25 * 0, BMP_v, WHITE, BLACK); //V
        
        LCD_DrawImage1BPP(535 + 63 - 11, 75 + 25 * 1, BMP_Xinhao, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 63 - 11 + 42, 75 + 25 * 1, BMP_SZ_2[2], WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 63 + 42 + 16 * 4 - 4, 75 + 25 * 1, BMP_Omu, WHITE, BLACK); //Ω
        LCD_DrawImage1BPP(535 + 63 + 42 + 16 * 4 + 16 * 5, 75 + 25 * 1, BMP_v, WHITE, BLACK); //V

        //版本号
        LCD_DrawImage1BPP(505 + 100, 75 + 8 + 25 * 15, BMP_Banben, WHITE, BLACK);
        LCD_DrawImage1BPP(505 + 100 + 42, 75 + 8 + 25 * 15, BMP_Hao, WHITE, BLACK);
        LCD_DrawImage1BPP(505 + 200, 75 + 25 * 15, BMP_V, WHITE, BLACK);

    } else if (index == 3) {
        LCD_DrawImage1BPP(130 + 200, 130 - 85, BMP_DING, WHITE, BLACK); //顶
        LCD_DrawImage1BPP(130 + 200 + 25, 130 - 85, BMP_MOKUAI, WHITE, BLACK); //模块
        LCD_DrawImage1BPP(130 + 200 + 25 + 50, 130 - 85, BMP_Message, WHITE, BLACK); //信息
        for (i = 0; i < 15; i++) {
            LCD_DrawImage1BPP(60 + 280, 75 + 3 + 25 * i, BMP_a, WHITE, BLACK);
            //LCD_DrawRect(0, 74 +25+ 25 * i, 800, 1, GRAY); //横线
        }

        /*********************顶模块输出***************************************/
        //OUT1  照明1
        LCD_DrawImageSBPP(60, 75 + 25 * 0, 42, ZM1, WHITE, BLACK);
        //OUT2  右转向灯
        LCD_DrawImage1BPP(60, 75 + 25 * 1, BMP_IC_You, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 1, BMP_IC_Zhuanxiang, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 63, 75 + 25 * 1, BMP_IC_Deng, WHITE, BLACK);
        //OUT3  照明2
        LCD_DrawImageSBPP(60, 75 + 25 * 2, 42, ZM2, WHITE, BLACK);
        //OUT4  制动灯
        LCD_DrawImageSBPP(60, 75 + 25 * 3, 42, ZDDSC, WHITE, BLACK);
        //OUT5  前门开输出
        LCD_DrawImageSBPP(60, 75 + 25 * 4, 21, QMKSC, WHITE, BLACK);
        //OUT6  前路牌
        LCD_DrawImageSBPP(60, 75 + 25 * 5, 21, QLP, WHITE, BLACK);
        //OUT7  前门关输出
        LCD_DrawImageSBPP(60, 75 + 25 * 6, 21, QMGSC, WHITE, BLACK);      
        //OUT8  后路牌
        LCD_DrawImageSBPP(60, 75 + 25 * 7, 21, HLP, WHITE, BLACK);
        //OUT9  中门开输出
        LCD_DrawImageSBPP(60, 75 + 25 * 8, 21, ZMKSC, WHITE, BLACK);
        //OUT10 前雾灯输出
        LCD_DrawImageSBPP(60, 75 + 25 * 9, 21, QWDSC, WHITE, BLACK);
        //OUT11 中门关输出
        LCD_DrawImageSBPP(60, 75 + 25 * 10, 21, ZMGSC, WHITE, BLACK);
        //OUT12 司机灯
        LCD_DrawImageSBPP(60, 75 + 25 * 11, 42, SJD, WHITE, BLACK);
        //OUT13 位置灯
        LCD_DrawImageSBPP(60, 75 + 25 * 12, 42, WZD, WHITE, BLACK);
        //OUT14 TV1电源
        LCD_DrawImageSBPP(60, 75 + 25 * 13, 11, TV1DY, WHITE, BLACK);
        //OUT15 左转向灯
        LCD_DrawImage1BPP(60, 75 + 25 * 14, BMP_IC_Zuo, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 14, BMP_IC_Zhuanxiang, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 63, 75 + 25 * 14, BMP_IC_Deng, WHITE, BLACK);              
        /************************顶模块开关*********************************/
        //KL1  前门开
        LCD_DrawImageSBPP(285 + 150, 75 + 25 * 0, 21, QMKKG, WHITE, BLACK);
        //KL2  门铃
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 1, BMP_Menling, WHITE, BLACK);
        //KL3  前门关
        LCD_DrawImageSBPP(285 + 150, 75 + 25 * 2, 21, QMGKG, WHITE, BLACK);
        //KL4  内应急阀盖开报警
        LCD_DrawImageSBPP(285 + 150, 75 + 25 * 3, 21, NYJFGKBJ, WHITE, BLACK);
        //KL5  中门开
        LCD_DrawImageSBPP(285 + 150, 75 + 25 * 4, 21, ZMKKG, WHITE, BLACK);
        //KL6  前门车内应急阀报警
        LCD_DrawImageSBPP(285 + 150, 75 + 25 * 5, 21, QMCNYJFBJ, WHITE, BLACK);
        //KL7  中门开
        LCD_DrawImageSBPP(285 + 150, 75 + 25 * 6, 21, ZMGKG, WHITE, BLACK);
        //KL8  中门车内应急阀报警
        LCD_DrawImageSBPP(285 + 150, 75 + 25 * 7, 21, HMCNYJFBJ, WHITE, BLACK);
        //KL9  司机灯
        LCD_DrawImageSBPP(285 + 150, 75 + 25 * 8, 42, SJDKG, WHITE, BLACK);
        //KL10 照明开关1
        LCD_DrawImageSBPP(285 + 150, 75 + 25 * 9, 42, ZMKG1, WHITE, BLACK);
        //KL11 TV开关1
        LCD_DrawImageSBPP(285 + 150, 75 + 25 * 10, 11, TV1KG, WHITE, BLACK);
        //KL12 照明开关2
        LCD_DrawImageSBPP(285 + 150, 75 + 25 * 11, 42, ZMKG2, WHITE, BLACK);
        //KL13 地址选择1
        LCD_DrawImageSBPP(285 + 150, 75 + 25 * 12,42, DZXZ1, WHITE, BLACK);
        //KL14 地址选择2
        LCD_DrawImageSBPP(285 + 150, 75 + 25 * 13, 42, DZXZ2, WHITE, BLACK);
        //KL15
        //KH1 中门开信号
        LCD_DrawImageSBPP(285 + 150, 75 + 25 * 15, 21, ZMKXH, WHITE, BLACK);
        
        LCD_DrawImage1BPP(535 + 63 - 11, 75 + 25 * 0, BMP_Xinhao, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 63 - 11 + 42, 75 + 25 * 0, BMP_SZ_2[1], WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 63 + 42 + 16 * 4 - 4, 75 + 25 * 0, BMP_Omu, WHITE, BLACK); //Ω
        LCD_DrawImage1BPP(535 + 63 + 42 + 16 * 4 + 16 * 5, 75 + 25 * 0, BMP_v, WHITE, BLACK); //V
        
        LCD_DrawImage1BPP(535 + 63 - 11, 75 + 25 * 1, BMP_Xinhao, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 63 - 11 + 42, 75 + 25 * 1, BMP_SZ_2[2], WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 63 + 42 + 16 * 4 - 4, 75 + 25 * 1, BMP_Omu, WHITE, BLACK); //Ω
        LCD_DrawImage1BPP(535 + 63 + 42 + 16 * 4 + 16 * 5, 75 + 25 * 1, BMP_v, WHITE, BLACK); //V
        
        LCD_DrawImage1BPP(505 + 100, 75 + 8 + 25 * 15, BMP_Banben, WHITE, BLACK);
        LCD_DrawImage1BPP(505 + 100 + 42, 75 + 8 + 25 * 15, BMP_Hao, WHITE, BLACK);

    } else if (index == 4) {     
        LCD_DrawImage1BPP(130 + 200, 130 - 85, BMP_HOU, WHITE, BLACK); //后
        LCD_DrawImage1BPP(130 + 200 + 25, 130 - 85, BMP_MOKUAI, WHITE, BLACK); //模块
        LCD_DrawImage1BPP(130 + 200 + 25 + 50, 130 - 85, BMP_Message, WHITE, BLACK); //信息
        for (i = 0; i < 15; i++) {
            LCD_DrawImage1BPP(60 + 280, 75 + 3 + 25 * i, BMP_a, WHITE, BLACK);
            //LCD_DrawRect(0, 74 +25+ 25 * i, 800, 1, GRAY); //横线
        }
        /*********************后模块输出***************************************/
        //OUT1  制动灯
        LCD_DrawImageSBPP(60, 75 + 25 * 0, 42, ZDDSC, WHITE, BLACK);
        //OUT2  
        //OUT3  后雾灯
        LCD_DrawImageSBPP(60, 75 + 25 * 2, 21, HWDSC, WHITE, BLACK);
        //OUT4  
        //OUT5  左转向灯
        LCD_DrawImage1BPP(60, 75 + 25 * 4, BMP_IC_Zuo, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 4, BMP_IC_Zhuanxiang, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 63, 75 + 25 * 4, BMP_IC_Deng, WHITE, BLACK);
        //OUT6  电源开关
        LCD_DrawImageSBPP(60, 75 + 25 * 5, 42, DYKG, WHITE, BLACK);
        //OUT7  右转向灯
        LCD_DrawImage1BPP(60, 75 + 25 * 6, BMP_IC_You, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 6, BMP_IC_Zhuanxiang, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 63, 75 + 25 * 6, BMP_IC_Deng, WHITE, BLACK);
        //OUT8  
        LCD_DrawImage1BPP(60, 75 + 25 * 7, BMP_Ganzaoqi, WHITE, BLACK);
        //OUT9  倒车信号
        LCD_DrawImageSBPP(60, 75 + 25 * 8, 42, DCXH, WHITE, BLACK);
        //OUT10 ST档
        LCD_DrawImageSBPP(60, 75 + 25 * 9, 11, START, WHITE, BLACK);
        //OUT11 ABS
        LCD_DrawImageSBPP(60, 75 + 25 * 10, 11, ABS, WHITE, BLACK);
        //OUT12 小灯
        LCD_DrawImageSBPP(60, 75 + 25 * 11, 21, XD, WHITE, BLACK);
        //OUT13 接近开关
        LCD_DrawImageSBPP(60, 75 + 25 * 12, 21, JJKG, WHITE, BLACK);
        //OUT14 后舱门灯
        LCD_DrawImageSBPP(60, 75 + 25 * 13, 21, HCMD, WHITE, BLACK);
        //OUT15 BMS
        LCD_DrawImageSBPP(60, 75 + 25 * 14, 11, BMS, WHITE, BLACK);                      
        /*********************后模块开关***************************************/
        //KL1  水位报警
        LCD_DrawImageSBPP(285 + 150, 75 + 25 * 0, 42, SWBJ, WHITE, BLACK);
        //KL2  左前摩擦片
        LCD_DrawImageSBPP(285 + 150, 75 + 25 * 1, 21, ZQMCP, WHITE, BLACK);
        //KL3  制动开关
        LCD_DrawImageSBPP(285 + 150, 75 + 25 * 2, 42, ZDKG, WHITE, BLACK);
        //KL4  右前摩擦片
        LCD_DrawImageSBPP(285 + 150, 75 + 25 * 3, 21, YQMCP, WHITE, BLACK);
        //KL5  驻车制动开关
        LCD_DrawImageSBPP(285 + 150, 75 + 25 * 4, 42, ZCZDKG, WHITE, BLACK);        
        //KL6  左后摩擦片报警
        LCD_DrawImageSBPP(285 + 150, 75 + 25 * 5, 21, ZHMCP, WHITE, BLACK);
        //KL7  中门外应急阀盖开报警
        LCD_DrawImageSBPP(285 + 150, 75 + 25 * 6, 21, HMWYJFGKBJ, WHITE, BLACK);
        //KL8  右后摩擦片报警
        LCD_DrawImageSBPP(285 + 150, 75 + 25 * 7, 21, YHMCP, WHITE, BLACK);
        //KL9  中门外应急阀报警
        LCD_DrawImageSBPP(285 + 150, 75 + 25 * 8, 21, HMWYJFBJ, WHITE, BLACK);
        //KL10 气压报警1
        LCD_DrawImageSBPP(285 + 150, 75 + 25 * 9, 42, QYBJ1, WHITE, BLACK);
        //KL11 后舱门开关
        LCD_DrawImageSBPP(285 + 150, 75 + 25 * 10, 21, HCMKG, WHITE, BLACK);   
        //KL12 气压报警2
        LCD_DrawImageSBPP(285 + 150, 75 + 25 * 11, 42, QYBJ2, WHITE, BLACK);
        //KL13 地址选择1
        LCD_DrawImageSBPP(285 + 150, 75 + 25 * 12,42, DZXZ1, WHITE, BLACK);
        //KL14 地址选择2
        LCD_DrawImageSBPP(285 + 150, 75 + 25 * 13, 42, DZXZ2, WHITE, BLACK);
        //KL15 
        //KH1  发动机输出
        //LCD_DrawImageSBPP(285 + 150, 75 + 25 * 15, 63, FDJSC, WHITE, BLACK);
        
        LCD_DrawImage1BPP(535 + 63 - 11, 75 + 25 * 0, BMP_Xinhao, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 63 - 11 + 42, 75 + 25 * 0, BMP_SZ_2[1], WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 63 + 42 + 16 * 4 - 4, 75 + 25 * 0, BMP_Omu, WHITE, BLACK); //Ω
        LCD_DrawImage1BPP(535 + 63 + 42 + 16 * 4 + 16 * 5, 75 + 25 * 0, BMP_v, WHITE, BLACK); //V
        
        LCD_DrawImage1BPP(535 + 63 - 11, 75 + 25 * 1, BMP_Xinhao, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 63 - 11 + 42, 75 + 25 * 1, BMP_SZ_2[2], WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 63 + 42 + 16 * 4 - 4, 75 + 25 * 1, BMP_Omu, WHITE, BLACK); //Ω
        LCD_DrawImage1BPP(535 + 63 + 42 + 16 * 4 + 16 * 5, 75 + 25 * 1, BMP_v, WHITE, BLACK); //V

        LCD_DrawImage1BPP(505 + 100, 75 + 8 + 25 * 15, BMP_Banben, WHITE, BLACK);
        LCD_DrawImage1BPP(505 + 100 + 42, 75 + 8 + 25 * 15, BMP_Hao, WHITE, BLACK);
        LCD_DrawImage1BPP(505 + 200, 75 + 25 * 15, BMP_V, WHITE, BLACK);
    }
}

void ICUpdate(unsigned char index) {
    unsigned int dump, i;
    unsigned char color,CanStatus = 1;
    if (index == 1) {
        for (i = 0; i < NODE_NUMBER; i++) {
            CanStatus = CanStatus && (NodeCount[i] < CAN_TIME);
        }
        if (CanStatus)
            LCD_DrawImage1BPP(130 + 200 + 200 + 11 + 11 + 11 + 50 + 20, 130 - 85 + 4, BMP_Zhengchang, GREEN, BLACK);
        else
            LCD_DrawImage1BPP(130 + 200 + 200 + 11 + 11 + 11 + 50 + 20, 130 - 85 + 4, BMP_Guzhang, RED, BLACK);

        for (i = 0; i < 6; i++) {
            print_SZ_2(535 + 63 + 42 + 4, 75 + 25 * (i + 8), ADR[i + 1], 3, 0, YELLOW);
        }
        for (i = 0; i < 6; i++) {
            print_SZ_2(535 + 63 + 42 + 16 * 5, 75 + 25 * (i + 8), ADV[i + 1] / 10, 3, 2, YELLOW);
        }

        dump = sw_input[0].byte + ((unsigned int) (sw_input[1].byte) << 8);
        for (i = 0; i < 16; i++) {
            if (i == 1 || i == 2 || i == 3)
            {
            if ((dump & 0x01) == 0x01) {//为控火开关
                LCD_DrawImage1BPP(5, 75 + 25 * i, Bmpflag[0], WHITE, BLACK);
            } else {
                LCD_DrawImage1BPP(5, 75 + 25 * i, Bmpflag[1], GREEN, BLACK);
            }
            } 
            else if ((dump & 0x01) == 0x01) {
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
        //模块模拟信号
        for (i = 0; i < 2; i++) {
            print_SZ_2(535 + 63 + 42 + 4, 75 + 25 * i, fADR[i], 3, 0, YELLOW);
        }
        for (i = 0; i < 2; i++) {
            print_SZ_2(535 + 63 + 42 + 16 * 5, 75 + 25 * i, fADV[i] / 10, 3, 2, YELLOW);
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
        for (i = 0; i < 2; i++) {
            print_SZ_2(535 + 63 + 42 + 4, 75 + 25 * i, mADR[i], 3, 0, YELLOW);
        }
        for (i = 0; i < 2; i++) {
            print_SZ_2(535 + 63 + 42 + 16 * 5, 75 + 25 * i, mADV[i] / 10, 3, 2, YELLOW);
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
        for (i = 0; i < 2; i++) {
            print_SZ_2(535 + 63 + 42 + 4, 75 + 25 * i, rADR[i], 3, 0, YELLOW);
        }
        for (i = 0; i < 2; i++) {
            print_SZ_2(535 + 63 + 42 + 16 * 5, 75 + 25 * i, rADV[i] / 10, 3, 2, YELLOW);
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

void MenuFrame(void) {
    unsigned char color = WHITE;
    LCD_Clear();
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //顶部横线   

    LCD_DrawRect(0, 430, 800, 2, YELLOW); //底部横线
    LCD_DrawImageSBPP(130, 130, 50, MOTO_SYSTEM, color, BLACK); //电机
    
    LCD_DrawImageSBPP(130, 130 + 35, 50, DCDC_SYSTEM, color, BLACK); //DCDC

    LCD_DrawImageSBPP(130, 130 + 35 + 35, 50, AIR_SYSTEM, color, BLACK); //气泵

    LCD_DrawImageSBPP(130, 130 + 35 + 35 + 35, 50, OIL_SYSTEM, color, BLACK); //油泵
    

    LCD_DrawImageSBPP(130 + 350, 130, 50, BMS_SYSTEM, color, BLACK); //电池

    LCD_DrawImageSBPP(130 + 350, 130 + 35, 50, Battery_SYSTEM, color, BLACK); //电池   

    LCD_DrawImageSBPP(130 + 350, 130 + 35 + 35, 50, AC_SYSTEM, color, BLACK); //空调

    LCD_DrawImageSBPP(130 + 350, 130 + 35 + 35 + 35, 50, IC_SYSTEM, color, BLACK); //仪表

}

#define Menu_Number  8

void MenuUpdate(void) {
    static unsigned char menu = 1;
    unsigned char color = BLACK;
    if (key_up) {//箭头向下走
        key_up = 0;
        if (time_flag) {
            t++; //时钟设置
            if (t == 10) t = 0;
        }
        if (!time_flag) {
            menu++;
            if (menu > Menu_Number) {
                menu = 1;
            }
        }
    }

    if (key_AV) {//箭头向上走
        key_AV = 0;
        if (time_flag)
            t_add = 1;
        if (!time_flag) {
            menu--;
            if (menu < 1) {
                menu = Menu_Number;
            }
        }
    }
#if 0
    switch (menu) {
        case 1:
            if (key_set) {
                key_set = 0;
                if (time_flag == 0) {
                    f_index = 0;
                    frmID = 2;
                }
                time_flag = 0;
            }

            for (i = 0; i < Menu_Number; i++) {
                if ((i + 1) == menu)
                    LCD_DrawImage1BPP(105, 131 + 35 * i, BMP_Choose, GREEN, BLACK);
                else
                    LCD_DrawImage1BPP(105, 131 + 35 * i, BMP_Choose, BLACK, BLACK);
            }
            break;
        case 2:
            if (key_set) {
                key_set = 0;
                if (time_flag == 0) {
                    f_index = 0;
                    frmID = 3;
                }
                time_flag = 0;
            }

            for (i = 0; i < Menu_Number; i++) {
                if ((i + 1) == menu)
                    LCD_DrawImage1BPP(105, 131 + 35 * i, BMP_Choose, GREEN, BLACK);
                else
                    LCD_DrawImage1BPP(105, 131 + 35 * i, BMP_Choose, BLACK, BLACK);
            }
            break;
        case 3:
            if (key_set) {
                key_set = 0;
                if (time_flag == 0) {
                    f_index = 0;
                    frmID = 7;
                }
                time_flag = 0;
            }

            for (i = 0; i < Menu_Number; i++) {
                if ((i + 1) == menu)
                    LCD_DrawImage1BPP(105, 131 + 35 * i, BMP_Choose, GREEN, BLACK);
                else
                    LCD_DrawImage1BPP(105, 131 + 35 * i, BMP_Choose, BLACK, BLACK);
            }
            break;
        case 4:
            if (key_set) {
                key_set = 0;
                if (time_flag == 0) {
                    f_index = 0;
                    frmID = 9;
                }
                time_flag = 0;
            }

            for (i = 0; i < Menu_Number; i++) {
                if ((i + 1) == menu)
                    LCD_DrawImage1BPP(105, 131 + 35 * i, BMP_Choose, GREEN, BLACK);
                else
                    LCD_DrawImage1BPP(105, 131 + 35 * i, BMP_Choose, BLACK, BLACK);
            }
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        default:
            break;
    }
#endif
    
#if 1
    //子菜单间切换
    if (menu == 1) {
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
    if (menu == 2) {
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
    if (menu == 3) {
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
    if (menu == 4) {
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
    if (menu == 5) {
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
    if (menu == 6) {
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
    if (menu == 7) {
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
    if (menu == 8) {
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

#endif
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

    print_SZ_2(750, 50, index, 1, 0, WHITE); // x/3
    LCD_DrawImage1BPP(750 + 11, 50, BMP_I, WHITE, BLACK);
    print_SZ_2(750 + 11 + 14, 50, 2, 1, 0, WHITE);

    if (index == 1) {
        LCD_DrawImageSBPP(82, 100, 42, DJSRDY, WHITE, BLACK); //电机母线电压
        LCD_DrawImage1BPP(400 - 24, 100 + 38 * 0, BMP_v, WHITE, BLACK); //V
        
        LCD_DrawImageSBPP(82, 100 + 38, 42, DJSRDL, WHITE, BLACK); //电机母线电流
        LCD_DrawImage1BPP(400 - 24, 100 + 38 * 1, BMP_a, WHITE, BLACK); //V

        LCD_DrawImageSBPP(82, 100 + 38 * 2, 42, DJWD, WHITE, BLACK); //平均温度
        LCD_DrawImage1BPP(400 - 24, 100 + 38 * 2, BMP_T, WHITE, BLACK); //V

        LCD_DrawImageSBPP(82, 100 + 38 * 3, 42, DJKZQ, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 42 + 63, 100 + 38 * 3, BMP_Wendu, WHITE, BLACK); //
        LCD_DrawImage1BPP(400 - 28, 100 + 38 * 3, BMP_T, WHITE, BLACK); //℃

        LCD_DrawImageSBPP(82, 100 + 38 * 4, 42, ZCZT, WHITE, BLACK); //整车状态

        LCD_DrawImageSBPP(82, 100 + 38 * 5, 42, CXBB, WHITE, BLACK); //程序版本

        LCD_DrawImage1BPP(82, 100 + 38 * 6, BMP_Zhengche, WHITE, BLACK); //整车
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 6, BMP_KZQ, WHITE, BLACK); //控制器
        LCD_DrawImage1BPP(82 + 42 + 63, 100 + 38 * 6, BMP_Life, WHITE, BLACK); //Life
        
        LCD_DrawImageSBPP(82, 100 + 38 * 7, 42, GZDM, WHITE, BLACK); //故障代码
        
        LCD_DrawImageSBPP(82, 100 + 38 * 8, 42, GZDJ, WHITE, BLACK); //故障等级
        
        LCD_DrawImageSBPP(82, 100 + 38 * 9, 42, DJZT, WHITE, BLACK); //电机状态
        

        
        
        
        
        
        LCD_DrawImageSBPP(82 + 320, 100, 42, YMTB, WHITE, BLACK); //油门踏板
        LCD_DrawImage1BPP(82 + 42 + 42 + 320, 100 - 8 + 0 * 38, BMP_SZ_1[1], WHITE, BLACK); //1
        LCD_DrawImage1BPP(720 - 24, 100, BMP_Baifenhao, WHITE, BLACK); //%

        LCD_DrawImageSBPP(82 + 320, 100 + 38 * 1, 42, YMTB, WHITE, BLACK); //油门踏板
        LCD_DrawImage1BPP(82 + 42 + 42 + 320, 100 - 8 + 1 * 38, BMP_SZ_1[2], WHITE, BLACK); //2
        LCD_DrawImage1BPP(720 - 24, 100 + 38 * 1, BMP_Baifenhao, WHITE, BLACK); //%
 
        LCD_DrawImageSBPP(82 + 320, 100 + 38 * 2, 42, ZDTB, WHITE, BLACK); //油门踏板
        LCD_DrawImage1BPP(82 + 42 + 42 + 320, 100 - 8 + 2 * 38, BMP_SZ_1[1], WHITE, BLACK); //1
        LCD_DrawImage1BPP(720 - 24, 100 + 38 * 2, BMP_Baifenhao, WHITE, BLACK); //%

        LCD_DrawImageSBPP(82 + 320, 100 + 38 * 3, 42, ZDTB, WHITE, BLACK); //油门踏板
        LCD_DrawImage1BPP(82 + 42 + 42 + 320, 100 - 8 + 3 * 38, BMP_SZ_1[2], WHITE, BLACK); //2
        LCD_DrawImage1BPP(720 - 24, 100 + 38 * 3, BMP_Baifenhao, WHITE, BLACK); //%
        
        LCD_DrawImageSBPP(82 + 320, 100 + 38 * 4, 42, ZCSRZT, WHITE, BLACK); //整车输入状态1
        LCD_DrawImage1BPP(82 + 42 + 42 + 42 + 320, 100 - 8 + 4 * 38, BMP_SZ_1[1], WHITE, BLACK); //

        LCD_DrawImageSBPP(82 + 320, 100 + 38 * 5, 42, ZCSRZT, WHITE, BLACK); //整车输入状态2
        LCD_DrawImage1BPP(82 + 42 + 42 + 42 + 320, 100 - 8 + 5 * 38, BMP_SZ_1[2], WHITE, BLACK); //           

    } else if (index == 2) {
        LCD_DrawImageSBPP(82, 100, 11, DCDC, WHITE, BLACK); //DCDC散热器温度
        LCD_DrawImageSBPP(82 + 44, 100, 63, SRQWD, WHITE, BLACK);
        LCD_DrawImage1BPP(400 - 24, 100 + 38 * 0, BMP_T, WHITE, BLACK); //℃
        
        LCD_DrawImageSBPP(82, 100 + 38 * 1, 11, DCDC, WHITE, BLACK); //DCDC故障代码
        LCD_DrawImageSBPP(82 + 44, 100 + 38 * 1, 42, GZDM, WHITE, BLACK);
        
        
        
        LCD_DrawImageSBPP(82 + 320, 100, 11, DCAC, WHITE, BLACK); //DCAC1散热器温度
        LCD_DrawImage1BPP(82 + 320 + 44, 100 - 8 + 0 * 38, BMP_SZ_1[1], WHITE, BLACK); //1
        LCD_DrawImageSBPP(82 + 320 + 44 + 16, 100, 63, SRQWD, WHITE, BLACK);
        LCD_DrawImage1BPP(400 + 320 - 24, 100 + 38 * 0, BMP_T, WHITE, BLACK); //℃
        
        LCD_DrawImageSBPP(82 + 320, 100 + 38 * 1, 11, DCAC, WHITE, BLACK); //DCAC1故障代码
        LCD_DrawImage1BPP(82 + 320 + 44, 100 - 8 + 1 * 38, BMP_SZ_1[1], WHITE, BLACK); //1
        LCD_DrawImageSBPP(82 + 320 + 44 + 16, 100 + 38 * 1, 42, GZDM, WHITE, BLACK);
        
        LCD_DrawImageSBPP(82 + 320, 100 + 38 * 2, 11, DCAC, WHITE, BLACK); //DCAC1散热器温度
        LCD_DrawImage1BPP(82 + 320 + 44, 100 - 8 + 2 * 38, BMP_SZ_1[2], WHITE, BLACK); //2
        LCD_DrawImageSBPP(82 + 320 + 44 + 16, 100 + 38 * 2, 63, SRQWD, WHITE, BLACK);
        LCD_DrawImage1BPP(400 + 320 - 24, 100 + 38 * 2, BMP_T, WHITE, BLACK); //℃
        
        LCD_DrawImageSBPP(82 + 320, 100 + 38 * 3, 11, DCAC, WHITE, BLACK); //DCAC1故障代码
        LCD_DrawImage1BPP(82 + 320 + 44, 100 - 8 + 3 * 38, BMP_SZ_1[2], WHITE, BLACK); //2
        LCD_DrawImageSBPP(82 + 320 + 44 + 16, 100 + 38 * 3, 42, GZDM, WHITE, BLACK);

        /*LCD_DrawImage1BPP(82, 100 + 38 * 0, BMP_DJ, WHITE, BLACK); //电机
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 0, BMP_Muxian, WHITE, BLACK); //母线
        LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 0, BMP_DY, WHITE, BLACK); //电压
        LCD_DrawImage1BPP(400 - 24, 100 + 38 * 0, BMP_v, WHITE, BLACK); //V

        LCD_DrawImage1BPP(82, 100 + 38 * 1, BMP_DJ, WHITE, BLACK); //电机
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 1, BMP_Muxian, WHITE, BLACK); //母线
        LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 1, BMP_DL, WHITE, BLACK); //电流
        LCD_DrawImage1BPP(400 - 24, 100 + 38 * 1, BMP_a, WHITE, BLACK); //A

        LCD_DrawImage1BPP(82, 100 + 38 * 2, BMP_DJ, WHITE, BLACK); //电机
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 2, BMP_Zhuansu, WHITE, BLACK); //转速
        LCD_DrawImage1BPP(400 - 24 - 24, 100 + 38 * 2, BMP_RPM, WHITE, BLACK); //RPM

        LCD_DrawImage1BPP(82, 100 + 38 * 3, BMP_DJ, WHITE, BLACK); //电机
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 3, BMP_Zhuanju, WHITE, BLACK); //转矩
        LCD_DrawImage1BPP(400 - 24 - 11, 100 + 38 * 3, BMP_n, WHITE, BLACK); //NM
        LCD_DrawImage1BPP(400 - 24, 100 + 38 * 3, BMP_m, WHITE, BLACK); //

        LCD_DrawImage1BPP(82, 100 + 38 * 4, BMP_DJ, WHITE, BLACK); //电机
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 4, BMP_Wendu, WHITE, BLACK); //温度
        LCD_DrawImage1BPP(400 - 28, 100 + 38 * 4, BMP_T, WHITE, BLACK); //℃

        LCD_DrawImage1BPP(82, 100 + 38 * 5, BMP_KZQ, WHITE, BLACK); //控制器
        LCD_DrawImage1BPP(82 + 63, 100 + 38 * 5, BMP_Wendu, WHITE, BLACK); //温度
        LCD_DrawImage1BPP(400 - 28, 100 + 38 * 5, BMP_T, WHITE, BLACK); //℃


        LCD_DrawImageSBPP(82 + 320, 100 + 38 * 0, 42, DJMXDYXHZT, WHITE, BLACK); //电机母线电压状态
        LCD_DrawImageSBPP(82 + 320, 100 + 38 * 1, 42, DJMXDLXHZT, WHITE, BLACK); //电机母线电流状态
        LCD_DrawImageSBPP(82 + 320, 100 + 38 * 2, 42, DCJCQ, WHITE, BLACK); //电池接触器
        LCD_DrawImageSBPP(82 + 320, 100 + 38 * 3, 42, ZDTBZT, WHITE, BLACK); //制动踏板状态
        LCD_DrawImageSBPP(82 + 320, 100 + 38 * 4, 42, JSTBZT, WHITE, BLACK); //加速踏板状态
        LCD_DrawImageSBPP(82 + 320, 100 + 38 * 5, 42, DJWDXHZT, WHITE, BLACK); //制动踏板状态
        LCD_DrawImageSBPP(82 + 320, 100 + 38 * 6, 42, DJKZQWDXHZT, WHITE, BLACK); //加速踏板状态   */ 
    } else if (index == 3) {
        /*LCD_DrawImage1BPP(82, 100 - 2 + 38 * 0, BMP_DCDC, WHITE, BLACK); //DCDC保险状态
        LCD_DrawImageSBPP(82 + 65, 100 + 38 * 0, 42, BXZT, WHITE, BLACK);

        LCD_DrawImage1BPP(82, 100 + 38 * 1, BMP_Kongtiao, WHITE, BLACK); //空调保险状态
        LCD_DrawImageSBPP(82 + 42, 100 + 38 * 1, 42, BXZT, WHITE, BLACK);

        LCD_DrawImage1BPP(82, 100 + 38 * 2, BMP_Chushuang, WHITE, BLACK); //除霜保险状态
        LCD_DrawImageSBPP(82 + 42, 100 + 38 * 2, 42, BXZT, WHITE, BLACK);

        LCD_DrawImage1BPP(82, 100 - 2 + 38 * 3, BMP_DCAC, WHITE, BLACK); //DCAC保险状态
        LCD_DrawImageSBPP(82 + 52, 100 + 38 * 3, 42, BXZT, WHITE, BLACK);

        LCD_DrawImage1BPP(82, 100 + 38 * 4, BMP_DJ, WHITE, BLACK); //电机控制器保险状态
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 4, BMP_KZQ, WHITE, BLACK);
        LCD_DrawImageSBPP(82 + 42 + 63, 100 + 38 * 4, 42, BXZT, WHITE, BLACK);



        LCD_DrawImageSBPP(82 + 320, 100 + 38 * 0, 21, ZZJCQ, WHITE, BLACK); //主正接触器状态
        LCD_DrawImage1BPP(82 + 320 + 42 + 63, 100 + 38 * 0, BMP_Zhuangtai, WHITE, BLACK);

        LCD_DrawImageSBPP(82 + 320, 100 + 38 * 1, 42, YCJCQ, WHITE, BLACK); //预充接触器状态
        LCD_DrawImage1BPP(82 + 320 + 42 + 63, 100 + 38 * 1, BMP_Zhuangtai, WHITE, BLACK);

        LCD_DrawImageSBPP(82 + 320, 100 + 38 * 2, 42, CSJCQ, WHITE, BLACK); //除霜接触器状态
        LCD_DrawImage1BPP(82 + 320 + 42 + 63, 100 + 38 * 2, BMP_Zhuangtai, WHITE, BLACK);*/
    }
}

void MOTOUpdate(unsigned char index) {
    if (index == 1) {
        updata_DAT(82 + 200 + 16, 100 - 8 + 38 * 0, CAN_0x0C03A1A7.MotoVoltage, 0.1, 1000, WHITE, 3, 0);
        updata_DAT(82 + 200 + 16, 100 - 8 + 38 * 1, CAN_0x0C03A1A7.MotoCurrent, 0.1, 1000, WHITE, 3, 0);
        updata_DAT(82 + 200 + 16, 100 - 8 + 38 * 2, CAN_0x0C03A1A7.MotorTemperature, 1, 40, WHITE, 3, 0);
        updata_DAT(82 + 200 + 16, 100 - 8 + 38 * 3, CAN_0x0C03A1A7.MotorTemperature_Controller, 1, 40, WHITE, 3, 0);
        print_SZ_1(82 + 200 + 16, 100 - 8 + 38 * 4, CAN_0x0C04A1A7.VCUMode, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 16 - 16 * 6, 100 - 8 + 38 * 5, CAN_0x0C04A1A7.VCUVerison, 8, 1, WHITE);
        print_SZ_1(82 + 200 + 16, 100 - 8 + 38 * 6, CAN_0x0C04A1A7.VCULife, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 16 - 16 * 3, 100 - 8 + 38 * 7, CAN_0x0C04A1A7.FaultCode1 + ((unsigned int) CAN_0x0C04A1A7.FaultCode2 << 8), 6, 0, WHITE);
        print_SZ_1(82 + 200 + 16, 100 - 8 + 38 * 8, CAN_0x0C04A1A7.FaultLevel, 3, 0, WHITE);
        print_H(82 + 200 + 16 * 2, 100 - 8 + 38 * 9, CAN_0x0C08A1A7.MotoStatus, 2, 0, WHITE);


        print_SZ_1(82 + 200 + 320 + 16, 100 - 8 + 38 * 0, CAN_0x0C06A1A7.AcceleratePedal1, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 320 + 16, 100 - 8 + 38 * 1, CAN_0x0C06A1A7.AcceleratePedal2, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 320 + 16, 100 - 8 + 38 * 2, CAN_0x0C06A1A7.BrakePedal1, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 320 + 16, 100 - 8 + 38 * 3, CAN_0x0C06A1A7.BrakePedal2, 3, 0, WHITE);
        print_D(82 + 200 + 320 + 16 * 3 - 16 * 4, 100 - 8 + 38 * 4, CAN_0x0C06A1A7.byte[0], 8, 0, WHITE);
        print_D(82 + 200 + 320 + 16 * 3 - 16 * 4, 100 - 8 + 38 * 5, CAN_0x0C06A1A7.byte[1], 8, 0, WHITE);
    } else if (index == 2) {
        updata_DAT(82 + 200 + 16, 100 - 8 + 38 * 0, CAN_0x0C05A1A7.DCDCTemp, 1, 40, WHITE, 3, 0);
        print_D(82 + 200 + 16 * 3 - 16 * 4, 100 - 8 + 38 * 1, CAN_0x0C05A1A7.byte[3], 8, 0, WHITE);


        updata_DAT(82 + 200 + 320 + 16, 100 - 8 + 38 * 0, CAN_0x0C05A1A7.DCAC1Temp, 1, 40, WHITE, 3, 0);
        print_D(82 + 200 + 320 + 16 * 3 - 16 * 4, 100 - 8 + 38 * 1, CAN_0x0C05A1A7.byte[5], 8, 0, WHITE);
        updata_DAT(82 + 200 + 320 + 16, 100 - 8 + 38 * 2, CAN_0x0C05A1A7.DCAC2Temp, 1, 40, WHITE, 3, 0);
        print_D(82 + 200 + 320 + 16 * 3 - 16 * 4, 100 - 8 + 38 * 3, CAN_0x0C05A1A7.byte[7], 8, 0, WHITE);
    } else if (index == 3) {
        /*if (Protect[0].bit1) {
            LCD_DrawImage1BPP(82 + 42 * 6 - 5, 100 + 38 * 0, BMP_Zhengchang, GREEN, BLACK);
        } else {
            LCD_DrawImage1BPP(82 + 42 * 6 - 5, 100 + 38 * 0, BMP_Rongduan, RED, BLACK);
        }
        if (Protect[0].bit2) {
            LCD_DrawImage1BPP(82 + 42 * 6 - 5, 100 + 38 * 1, BMP_Zhengchang, GREEN, BLACK);
        } else {
            LCD_DrawImage1BPP(82 + 42 * 6 - 5, 100 + 38 * 1, BMP_Rongduan, RED, BLACK);
        }
        if (Protect[0].bit3) {
            LCD_DrawImage1BPP(82 + 42 * 6 - 5, 100 + 38 * 2, BMP_Zhengchang, GREEN, BLACK);
        } else {
            LCD_DrawImage1BPP(82 + 42 * 6 - 5, 100 + 38 * 2, BMP_Rongduan, RED, BLACK);
        }
        if (Protect[0].bit4) {
            LCD_DrawImage1BPP(82 + 42 * 6 - 5, 100 + 38 * 3, BMP_Zhengchang, GREEN, BLACK);
        } else {
            LCD_DrawImage1BPP(82 + 42 * 6 - 5, 100 + 38 * 3, BMP_Rongduan, RED, BLACK);
        }
        if (Protect[0].bit5) {
            LCD_DrawImage1BPP(82 + 42 * 6 - 5, 100 + 38 * 4, BMP_Zhengchang, GREEN, BLACK);
        } else {
            LCD_DrawImage1BPP(82 + 42 * 6 - 5, 100 + 38 * 4, BMP_Rongduan, RED, BLACK);
        }
        
        if (Protect[1].bit1) {
            LCD_DrawImage1BPP(82 + 42 * 6 - 5 + 320, 100 + 38 * 0, BMP_Bihe, GREEN, BLACK);
        } else {
            LCD_DrawImage1BPP(82 + 42 * 6 - 5 + 320, 100 + 38 * 0, BMP_Duankai, RED, BLACK);
        }
        if (Protect[1].bit2) {
            LCD_DrawImage1BPP(82 + 42 * 6 - 5 + 320, 100 + 38 * 1, BMP_Bihe, GREEN, BLACK);
        } else {
            LCD_DrawImage1BPP(82 + 42 * 6 - 5 + 320, 100 + 38 * 1, BMP_Duankai, RED, BLACK);
        }
        if (Protect[1].bit3) {
            LCD_DrawImage1BPP(82 + 42 * 6 - 5 + 320, 100 + 38 * 2, BMP_Bihe, GREEN, BLACK);
        } else {
            LCD_DrawImage1BPP(82 + 42 * 6 - 5 + 320, 100 + 38 * 2, BMP_Duankai, RED, BLACK);
        }*/
    }
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
        if (index_MOTO >= 3) {
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

void DCDCFrame(void) {
    unsigned char i = 0;
    LCD_Clear();
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //顶部横线
    LCD_DrawImageSBPP(130 + 200, 130 - 85, 50,DCDC_SYSTEM, WHITE, BLACK); //DCDC系统信息

    LCD_DrawRect(80, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320 + 320, 90, 1, 380, GREEN);
    for (i = 0; i < 11; i++)
        LCD_DrawRect(80, 90 + i * 38, 640, 1, GREEN);

    LCD_DrawImageSBPP(82, 100,11, DCDC, WHITE, BLACK); //DCDC
    LCD_DrawImageSBPP(82 + 44, 100, 42, SCDL, WHITE, BLACK); //输出
    LCD_DrawImage1BPP(400 - 24, 100, BMP_a, WHITE, BLACK); //A

    LCD_DrawImageSBPP(82, 100 + 38, 11, DCDC, WHITE, BLACK); //DCDC
    LCD_DrawImageSBPP(82 + 44, 100 + 38, 42, SCDY, WHITE, BLACK); //输出
    LCD_DrawImage1BPP(400 - 24, 100 + 38, BMP_v, WHITE, BLACK); //V  

    LCD_DrawImageSBPP(82, 100 + 38 * 2, 11, DCDC, WHITE, BLACK); //DCAC
    LCD_DrawImageSBPP(82 + 44, 100 + 38 * 2, 42, SRDY, WHITE, BLACK); //输出
    LCD_DrawImage1BPP(400 - 24, 100 + 38 * 2, BMP_v, WHITE, BLACK); //V
    

    LCD_DrawImageSBPP(82 + 320, 100,63, SRQWD, WHITE, BLACK); //控制器温度
    LCD_DrawImage1BPP(720 - 24, 100, BMP_T, WHITE, BLACK); //℃

    LCD_DrawImageSBPP(82 + 320, 100 + 38, 42,GZDM, WHITE, BLACK); //故障代码

    //LCD_DrawImageSBPP(82 + 320, 100 + 38 * 2,42, GZZT, WHITE, BLACK); //工作状态

}

void DCDCUpdate(void) {
    print_SZ_1(82 + 200 + 20, 100 - 8, CAN_0x1801A79A.DCDC_Output_Current * 0.1, 3, 0, WHITE);
    print_SZ_1(82 + 200 + 20 + 16, 100 - 8 + 38, CAN_0x1801A79A.DCDC_Output_Voltage, 2, 0, WHITE);
    print_SZ_1(82 + 200 + 20 - 16, 100 - 8 + 38 * 2, CAN_0x1801A79A.DCDC_Input_Voltage, 4, 0, WHITE);

    updata_DAT(82 + 200 + 300, 100 - 8, CAN_0x1801A79A.DCDC_Temp, 1, 40, WHITE, 3, 0);
    print_D(82 + 180 + 320, 100 - 8 + 38 * 1, CAN_0x1801A79A.DCDC_FaultCode.byte, 8, 0, WHITE);
    /*if (DCDC_WorkStatus == 1) {
        LCD_DrawImage1BPP(82 + 42 * 6 - 5 + 320, 100 + 38 * 2, BMP_Gongzuo, GREEN, BLACK);
    } else {
        LCD_DrawImage1BPP(82 + 42 * 6 - 5 + 320, 100 + 38 * 2, BMP_Tingzhi, RED, BLACK);
    }*/
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
void DMQFrame(void) {
    unsigned char i = 0;
    LCD_Clear();
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //顶部横线
    LCD_DrawImageSBPP(130 + 200 - 15, 130 - 85, 50, AIR_SYSTEM, WHITE, BLACK); 

    LCD_DrawRect(80, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320 + 320, 90, 1, 380, GREEN);
    for (i = 0; i < 11; i++)
        LCD_DrawRect(80, 90 + i * 38, 640, 1, GREEN);
    
    LCD_DrawImageSBPP(82, 100, 11, DCAC, WHITE, BLACK); //DCAC
    LCD_DrawImageSBPP(82 + 44, 100, 42, SCDL, WHITE, BLACK); //输出
    LCD_DrawImage1BPP(400 - 24, 100, BMP_a, WHITE, BLACK); //A

    LCD_DrawImageSBPP(82, 100 + 38, 11, DCAC, WHITE, BLACK); //DCAC
    LCD_DrawImageSBPP(82 + 44, 100 + 38, 42, SCDY, WHITE, BLACK); //输出
    LCD_DrawImage1BPP(400 - 24, 100 + 38, BMP_v, WHITE, BLACK); //V  

    LCD_DrawImageSBPP(82, 100 + 38 * 2, 11, DCAC, WHITE, BLACK); //DCAC
    LCD_DrawImageSBPP(82 + 44, 100 + 38 * 2, 42, SRDY, WHITE, BLACK); //输入
    LCD_DrawImage1BPP(400 - 24, 100 + 38 * 2, BMP_v, WHITE, BLACK); //V
    

    LCD_DrawImageSBPP(82 + 320, 100, 63,SRQWD, WHITE, BLACK); //控制器温度
    LCD_DrawImage1BPP(720 - 24, 100, BMP_T, WHITE, BLACK); //℃

    LCD_DrawImageSBPP(82 + 320, 100 + 38,42, GZDM, WHITE, BLACK); //故障代码

    //LCD_DrawImageSBPP(82 + 320, 100 + 38 * 2,42, GZZT, WHITE, BLACK); //工作状态
    
}

void DMQUpdate(void) {
    print_SZ_1(82 + 200 + 20, 100 - 8, CAN_0x1801A79D.AIRDCAC_Current * 0.1, 3, 0, WHITE);
    print_SZ_1(82 + 200 + 20 + 16, 100 - 8 + 38, CAN_0x1801A79D.AIRDCAC_Voltage, 2, 0, WHITE);
    print_SZ_1(82 + 200 + 20 - 16, 100 - 8 + 38 * 2, CAN_0x1801A79D.AIRDCAC_InputVoltage, 4, 0, WHITE);

    updata_DAT(82 + 200 + 300, 100 - 8, CAN_0x1801A79D.AIRDCAC_Temp, 1, 0, WHITE, 3, 0);
    print_D(82 + 180 + 320, 100 - 8 + 38 * 1, CAN_0x1801A79D.AIRDCAC_FaultCode.byte, 8, 0, WHITE);
    /*if (DCDC_WorkStatus == 1) {
        LCD_DrawImage1BPP(82 + 42 * 6 - 5 + 320, 100 + 38 * 2, BMP_Gongzuo, GREEN, BLACK);
    } else {
        LCD_DrawImage1BPP(82 + 42 * 6 - 5 + 320, 100 + 38 * 2, BMP_Tingzhi, RED, BLACK);
    }*/
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
void DMYFrame(void) {
    unsigned char i = 0;
    LCD_Clear();
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //顶部横线
    LCD_DrawImageSBPP(130 + 200 - 15, 130 - 85, 50, AIR_SYSTEM, WHITE, BLACK);

    LCD_DrawRect(80, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320 + 320, 90, 1, 380, GREEN);
    for (i = 0; i < 11; i++)
        LCD_DrawRect(80, 90 + i * 38, 640, 1, GREEN);
    
    LCD_DrawImageSBPP(82, 100,11, DCAC, WHITE, BLACK); //DCAC
    LCD_DrawImageSBPP(82 + 44, 100, 42, SCDL, WHITE, BLACK); //输出
    LCD_DrawImage1BPP(400 - 24, 100, BMP_a, WHITE, BLACK); //A

    LCD_DrawImageSBPP(82, 100 + 38, 11, DCAC, WHITE, BLACK); //DCAC
    LCD_DrawImageSBPP(82 + 44, 100 + 38, 42, SCDY, WHITE, BLACK); //输出
    LCD_DrawImage1BPP(400 - 24, 100 + 38, BMP_v, WHITE, BLACK); //V  

    LCD_DrawImageSBPP(82, 100 + 38 * 2, 11, DCAC, WHITE, BLACK); //DCAC
    LCD_DrawImageSBPP(82 + 44, 100 + 38 * 2, 42, SRDY, WHITE, BLACK); //输入
    LCD_DrawImage1BPP(400 - 24, 100 + 38 * 2, BMP_v, WHITE, BLACK); //V
    

    LCD_DrawImageSBPP(82 + 320, 100,63, SRQWD, WHITE, BLACK); //控制器温度
    LCD_DrawImage1BPP(720 - 24, 100, BMP_T, WHITE, BLACK); //℃

    LCD_DrawImageSBPP(82 + 320, 100 + 38,42, GZDM, WHITE, BLACK); //故障代码

    //LCD_DrawImageSBPP(82 + 320, 100 + 38 * 2,42, GZZT, WHITE, BLACK); //工作状态  
}

void DMYUpdate(void) {
    print_SZ_1(82 + 200 + 20, 100 - 8, CAN_0x1801A79B.OILDCAC_Current * 0.1, 3, 0, WHITE);
    print_SZ_1(82 + 200 + 20 + 16, 100 - 8 + 38, CAN_0x1801A79B.OILDCAC_Voltage, 2, 0, WHITE);
    print_SZ_1(82 + 200 + 20 - 16, 100 - 8 + 38 * 2, CAN_0x1801A79B.OILDCAC_InputVoltage, 4, 0, WHITE);

    updata_DAT(82 + 200 + 300, 100 - 8, CAN_0x1801A79B.OILDCAC_Temp, 1, 40, WHITE, 3, 0);
    print_D(82 + 180 + 320, 100 - 8 + 38 * 1, CAN_0x1801A79B.OILDCAC_FaultCode.byte, 8, 0, WHITE);
    /*if (DCDC_WorkStatus == 1) {
        LCD_DrawImage1BPP(82 + 42 * 6 - 5 + 320, 100 + 38 * 2, BMP_Gongzuo, GREEN, BLACK);
    } else {
        LCD_DrawImage1BPP(82 + 42 * 6 - 5 + 320, 100 + 38 * 2, BMP_Tingzhi, RED, BLACK);
    }*/
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
    LCD_DrawImageSBPP(130 + 200 - 24, 130 - 85,50, BMS_SYSTEM, WHITE, BLACK); //电池

    LCD_DrawRect(80, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320 + 320 + 70, 90, 1, 380, GREEN);
    for (i = 0; i < 11; i++)
        LCD_DrawRect(80, 90 + i * 38, 710, 1, GREEN);
       
    /*unsigned char i = 0, j = 0;
    LCD_Clear();
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //顶部横线
    LCD_DrawImageSBPP(130 + 200 - 24, 130 - 85, 50, BMS_SYSTEM, WHITE, BLACK); //电池

    print_SZ_2(750, 50, index, 1, 0, WHITE); // index/N
    LCD_DrawImage1BPP(750 + 11, 50, BMP_I, WHITE, BLACK);
    print_SZ_2(750 + 11 + 14, 50, 3, 1, 0, WHITE);*/
    if (index == 1) {
    LCD_DrawImage1BPP(82, 100, BMP_DC, WHITE, BLACK); //电池
    LCD_DrawImageSBPP(82 + 42, 100,21, ZDY, WHITE, BLACK); //总
    LCD_DrawImage1BPP(400 - 24, 100, BMP_v, WHITE, BLACK); //V

    LCD_DrawImage1BPP(82, 100 + 38, BMP_Zui, WHITE, BLACK); //最
    LCD_DrawImage1BPP(82 + 21, 100 + 38, BMP_Da, WHITE, BLACK); //大
    LCD_DrawImage1BPP(82 + 21 + 21, 100 + 38, BMP_Yunxu, WHITE, BLACK); //允许
    LCD_DrawImage1BPP(82 + 21 + 21 + 42, 100 + 38, BMP_Chong, WHITE, BLACK); //充
    LCD_DrawImage1BPP(82 + 21 + 21 + 42 + 21, 100 + 38, BMP_DY, WHITE, BLACK); //电
    LCD_DrawImage1BPP(82 + 21 + 21 + 42 + 21 + 21, 100 + 38, BMP_DL, WHITE, BLACK); //电流
    LCD_DrawImage1BPP(400 - 24, 100 + 38, BMP_a, WHITE, BLACK); //A

    LCD_DrawImage1BPP(82, 100 + 38 * 2, BMP_Zui, WHITE, BLACK); //最
    LCD_DrawImage1BPP(82 + 21, 100 + 38 * 2, BMP_Da, WHITE, BLACK); //大
    LCD_DrawImage1BPP(82 + 21 + 21, 100 + 38 * 2, BMP_Yunxu, WHITE, BLACK); //允许
    LCD_DrawImage1BPP(82 + 21 + 21 + 42, 100 + 38 * 2, BMP_Fang, WHITE, BLACK); //放
    LCD_DrawImage1BPP(82 + 21 + 21 + 42 + 21, 100 + 38 * 2, BMP_DY, WHITE, BLACK); //电
    LCD_DrawImage1BPP(82 + 21 + 21 + 42 + 21 + 21, 100 + 38 * 2, BMP_DL, WHITE, BLACK); //电流
    LCD_DrawImage1BPP(400 - 24, 100 + 38 * 2, BMP_a, WHITE, BLACK); //A

    LCD_DrawImage1BPP(82, 100 + 38 * 3, BMP_Dan, WHITE, BLACK); //单
    LCD_DrawImage1BPP(82 + 21, 100 + 38 * 3, BMP_Ti, WHITE, BLACK); //体
    LCD_DrawImage1BPP(82 + 21 + 21, 100 + 38 * 3, BMP_Pingjun, WHITE, BLACK); //平均
    LCD_DrawImage1BPP(82 + 21 + 21 + 42, 100 + 38 * 3, BMP_DY, WHITE, BLACK); //电压
    LCD_DrawImage1BPP(400 - 24, 100 + 38 * 3, BMP_v, WHITE, BLACK); //V

    LCD_DrawImageSBPP(82, 100 + 38 * 4, 42,DCZT, WHITE, BLACK); //电池
    LCD_DrawImage1BPP(82 + 42 + 42, 100 - 8 + 38 * 4, BMP_SZ_1[1], WHITE, BLACK); //1

    LCD_DrawImageSBPP(82, 100 + 38 * 5,42, DCZT, WHITE, BLACK); //电池
    LCD_DrawImage1BPP(82 + 42 + 42, 100 - 8 + 38 * 5, BMP_SZ_1[2], WHITE, BLACK); //2

    LCD_DrawImageSBPP(82, 100 + 38 * 6, 42, DCZT, WHITE, BLACK); //电池
    LCD_DrawImage1BPP(82 + 42 + 42, 100 - 8 + 38 * 6, BMP_SZ_1[3], WHITE, BLACK); //3
    
    LCD_DrawImageSBPP(82, 100 + 38 * 7, 42, DCZT, WHITE, BLACK); //电池
    LCD_DrawImage1BPP(82 + 42 + 42, 100 - 8 + 38 * 7, BMP_SZ_1[4], WHITE, BLACK); //4
    
    LCD_DrawImage1BPP(82, 100 + 38 * 8, BMP_Rongliang, WHITE, BLACK); //容量
    LCD_DrawImageSBPP(400 - 24 - 22, 100 + 38 * 8,11, CHAR_KWH, WHITE, BLACK); //KWH
    
    
    

    LCD_DrawImage1BPP(82 + 320, 100, BMP_Zong, WHITE, BLACK); //总
    LCD_DrawImage1BPP(82 + 320 + 21, 100, BMP_Zheng, WHITE, BLACK); //正
    LCD_DrawImage1BPP(82 + 320 + 21 + 21, 100, BMP_Jueyuan, WHITE, BLACK); //绝缘
    LCD_DrawImage1BPP(82 + 320 + 42 + 42, 100, BMP_DC, WHITE, BLACK); //电池
    LCD_DrawImage1BPP(82 + 320 + 42 + 42 + 21, 100, BMP_Zu, WHITE, BLACK); //阻
    LCD_DrawImage1BPP(720 - 28, 100, BMP_k, WHITE, BLACK); //K
    LCD_DrawImage1BPP(720 - 16, 100 + 2, BMP_Omu, WHITE, BLACK); //Ω

    LCD_DrawImage1BPP(82 + 320, 100 + 38, BMP_Zong, WHITE, BLACK); //总
    LCD_DrawImage1BPP(82 + 320 + 21, 100 + 38, BMP_Fu, WHITE, BLACK); //负
    LCD_DrawImage1BPP(82 + 320 + 21 + 21, 100 + 38, BMP_Jueyuan, WHITE, BLACK); //绝缘
    LCD_DrawImage1BPP(82 + 320 + 42 + 42, 100 + 38, BMP_DC, WHITE, BLACK); //电池
    LCD_DrawImage1BPP(82 + 320 + 42 + 42 + 21, 100 + 38, BMP_Zu, WHITE, BLACK); //阻
    LCD_DrawImage1BPP(720 - 28, 100 + 38, BMP_k, WHITE, BLACK); //K
    LCD_DrawImage1BPP(720 - 16, 100 + 38 + 2, BMP_Omu, WHITE, BLACK); //Ω

    /*LCD_DrawImage1BPP(82 + 320, 100 + 38 * 2, BMP_Dan, WHITE, BLACK); //单
    LCD_DrawImage1BPP(82 + 320 + 21, 100 + 38 * 2, BMP_Ti, WHITE, BLACK); //体
    LCD_DrawImageSBPP(82 + 320 + 21 + 21, 100 + 38 * 2,21, ZGDY, WHITE, BLACK); 
    LCD_DrawImage1BPP(720 - 24, 100 + 38 * 2, BMP_v, WHITE, BLACK); //V

    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 3, BMP_Dan, WHITE, BLACK); //单
    LCD_DrawImage1BPP(82 + 320 + 21, 100 + 38 * 3, BMP_Ti, WHITE, BLACK); //体
    LCD_DrawImageSBPP(82 + 320 + 21 + 21, 100 + 38 * 3, 21, ZDDY, WHITE, BLACK); //最
    LCD_DrawImage1BPP(720 - 24, 100 + 38 * 3, BMP_v, WHITE, BLACK); //V

    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 4, BMP_Dan, WHITE, BLACK); //单
    LCD_DrawImage1BPP(82 + 320 + 21, 100 + 38 * 4, BMP_Ti, WHITE, BLACK); //体
    LCD_DrawImageSBPP(82 + 320 + 21 + 21, 100 + 38 * 4, 21, ZGWD, WHITE, BLACK); //最
    LCD_DrawImage1BPP(720 - 28, 100 + 38 * 4, BMP_T, WHITE, BLACK); //℃*/
    for (i = 2; i < 6; i++) {
            LCD_DrawImage1BPP(82 + 320, 100 + 38 * i, BMP_Zui, WHITE, BLACK); //最
            if (i % 2 == 0)
                LCD_DrawImage1BPP(82 + 320 + 21, 100 + 38 * i, BMP_Gao, WHITE, BLACK); // 高
            else LCD_DrawImage1BPP(82 + 320 + 21, 100 + 38 * i, BMP_Di, WHITE, BLACK); // 低 
            if (i < 4) {
                LCD_DrawImage1BPP(82 + 320 + 21 + 21, 100 + 38 * i, BMP_DY, WHITE, BLACK); //电压
                LCD_DrawImage1BPP(720 - 24 - 63, 100 + 38 * i, BMP_v, WHITE, BLACK); //V
            } else {
                LCD_DrawImage1BPP(82 + 320 + 21 + 21, 100 + 38 * i, BMP_Wendu, WHITE, BLACK); //温度
                LCD_DrawImage1BPP(720 - 28 - 63, 100 + 38 * i, BMP_T, WHITE, BLACK); //℃
            }
            LCD_DrawImage1BPP(82 + 320 + 42 * 7, 100 + 38 * i, BMP_Xiang_BMS, WHITE, BLACK); //箱

            LCD_DrawImage1BPP(82 + 320 + 42 * 8.5, 100 + 38 * i, BMP_Hao, WHITE, BLACK); //号
        }

    LCD_DrawImageSBPP(82 + 320, 100 + 38 * 6,21, CFDDL, WHITE, BLACK); //充
    LCD_DrawImage1BPP(720 - 24, 100 + 38 * 6, BMP_a, WHITE, BLACK); //V
    
    LCD_DrawImageSBPP(82 + 320, 100 + 38 * 7, 42, GZDJ, WHITE, BLACK); //故障等级
    
    LCD_DrawImageSBPP(82 + 320, 100 + 38 * 8, 21, CDZWD, WHITE, BLACK); //
    LCD_DrawImage1BPP(82 + 320 + 21 * 5, 100 - 8 + 38 * 8, BMP_SZ_1[1], WHITE, BLACK); //1
    LCD_DrawImage1BPP(720 - 24, 100 + 38 * 8, BMP_T, WHITE, BLACK); //V
    
    LCD_DrawImageSBPP(82 + 320, 100 + 38 * 9, 21, CDZWD, WHITE, BLACK); //
    LCD_DrawImage1BPP(82 + 320 + 21 * 5, 100 - 8 + 38 * 9, BMP_SZ_1[2], WHITE, BLACK); //2
    LCD_DrawImage1BPP(720 - 24, 100 + 38 * 9, BMP_T, WHITE, BLACK); //V
        /*LCD_DrawRect(80, 90, 1, 380, GREEN);
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

        LCD_DrawImage1BPP(82, 100 + 38 * 3, BMP_Chong, WHITE, BLACK); //充电次数
        LCD_DrawImage1BPP(82 + 21, 100 + 38 * 3, BMP_DY, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 3, BMP_Cishu, WHITE, BLACK); //

        LCD_DrawImage1BPP(82, 100 + 38 * 4, BMP_b, WHITE, BLACK); //BMS
        LCD_DrawImage1BPP(82 + 11, 100 + 38 * 4, BMP_m, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 11 + 11, 100 + 38 * 4, BMP_s, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 11 + 11 + 11 + 11, 100 + 38 * 4, BMP_Life, WHITE, BLACK); //LIFE

        for (i = 5; i < 9; i++) {
            LCD_DrawImage1BPP(82, 100 + 38 * i, BMP_Zui, WHITE, BLACK); //最大允许充电电流
            LCD_DrawImage1BPP(82 + 21 + 21, 100 + 38 * i, BMP_Yunxu, WHITE, BLACK); //
            if (i == 5)
                LCD_DrawImage1BPP(82 + 21, 100 + 38 * i, BMP_Di, WHITE, BLACK); //
            else if (i == 6)
                LCD_DrawImage1BPP(82 + 21, 100 + 38 * i, BMP_Gao, WHITE, BLACK); //
            else
                LCD_DrawImage1BPP(82 + 21, 100 + 38 * i, BMP_Da, WHITE, BLACK);
            if (i == 6 || i == 8)
                LCD_DrawImage1BPP(82 + 21 + 21 + 42, 100 + 38 * i, BMP_Chong, WHITE, BLACK); //
            else
                LCD_DrawImage1BPP(82 + 21 + 21 + 42, 100 + 38 * i, BMP_Fang, WHITE, BLACK); //
            LCD_DrawImage1BPP(82 + 21 + 21 + 42 + 21, 100 + 38 * i, BMP_DL, WHITE, BLACK); //
            if (i == 5 || i == 6) {
                LCD_DrawImage1BPP(82 + 21 + 21 + 42 + 21 + 21, 100 + 38 * i, BMP_DY, WHITE, BLACK); //
                LCD_DrawImage1BPP(400 - 24, 100 + 38 * i, BMP_v, WHITE, BLACK); //V
            } else {
                LCD_DrawImage1BPP(82 + 21 + 21 + 42 + 21 + 21, 100 + 38 * i, BMP_DL, WHITE, BLACK); //
                LCD_DrawImage1BPP(400 - 24, 100 + 38 * i, BMP_a, WHITE, BLACK); //A
            }
        }
        LCD_DrawImageSBPP(82, 100 + 38 * 9, 42, DCSYRL, WHITE, BLACK); //电池剩余容量
        LCD_DrawImage1BPP(400 - 24 - 11, 100 + 38 * 9, BMP_a, WHITE, BLACK); //AH
        LCD_DrawImage1BPP(400 - 24, 100 + 38 * 9, BMP_h, WHITE, BLACK);


        for (i = 0; i < 5; i++) {
            LCD_DrawImage1BPP(82 + 320, 100 + 38 * i, BMP_Zui, WHITE, BLACK); //最
            if (i % 2 == 0)
                LCD_DrawImage1BPP(82 + 320 + 21, 100 + 38 * i, BMP_Gao, WHITE, BLACK); // 高
            else LCD_DrawImage1BPP(82 + 320 + 21, 100 + 38 * i, BMP_Di, WHITE, BLACK); // 低 
            if (i == 4) {
                LCD_DrawImage1BPP(82 + 320 + 21 + 21, 100 + 38 * i, BMP_Jizhu, WHITE, BLACK); //极柱
            } else {
                LCD_DrawImage1BPP(82 + 320 + 21 + 21, 100 + 38 * i, BMP_Dan, WHITE, BLACK); //单
                LCD_DrawImage1BPP(82 + 320 + 21 + 21 + 21, 100 + 38 * i, BMP_Ti, WHITE, BLACK); //体
            }
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
        LCD_DrawImage1BPP(82 + 320, 100 + 38 * 5, BMP_DC, WHITE, BLACK); //电池
        LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 5, BMP_Xiang_BMS, WHITE, BLACK); //箱
        LCD_DrawImage1BPP(82 + 320 + 42 + 21, 100 + 38 * 5, BMP_Shuliang, WHITE, BLACK); //数量

        LCD_DrawImage1BPP(82 + 320, 100 + 38 * 6, BMP_Dan, WHITE, BLACK); //单体电池数量
        LCD_DrawImage1BPP(82 + 320 + 21, 100 + 38 * 6, BMP_Ti, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 6, BMP_DC, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 320 + 42 + 42, 100 + 38 * 6, BMP_Shuliang, WHITE, BLACK); //

        LCD_DrawImageSBPP(82 + 320, 100 + 38 * 7, 42, DCCLSL, WHITE, BLACK); //电池串联数量

        LCD_DrawImageSBPP(82 + 320, 100 + 38 * 8, 42, DCBLSL, WHITE, BLACK); //电池并联数量   

        LCD_DrawImageSBPP(82 + 320, 100 + 38 * 9, 42, DCEDRL, WHITE, BLACK); //电池额定容量
        LCD_DrawImage1BPP(720 - 24 - 11, 100 + 38 * 9, BMP_a, WHITE, BLACK); //AH
        LCD_DrawImage1BPP(720 - 24, 100 + 38 * 9, BMP_h, WHITE, BLACK);*/
    } else if (index == 2) {
        /*LCD_DrawRect(80, 90, 1, 380, GREEN);
        LCD_DrawRect(80 + 320, 90, 1, 380, GREEN);
        LCD_DrawRect(80 + 320 + 320, 90, 1, 380, GREEN);
        for (i = 0; i < 11; i++)
            LCD_DrawRect(80, 90 + i * 38, 640, 1, GREEN);

        LCD_DrawImageSBPP(82, 100 + 38 * 0, 42, DCBJDJ, WHITE, BLACK); //电池报警等级      
        LCD_DrawImageSBPP(82, 100 + 38 * 1, 42, YJGZDM, WHITE, BLACK); //一级故障代码
        LCD_DrawImageSBPP(82, 100 + 38 * 2, 42, EJGZDM, WHITE, BLACK); //二级故障代码
        LCD_DrawImageSBPP(82, 100 + 38 * 3, 42, SJGZDM, WHITE, BLACK); //三级故障代码

        LCD_DrawImage1BPP(82, 100 + 38 * 4, BMP_DC, WHITE, BLACK); //电池主接触器状态
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 4, BMP_Zhu, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 42 + 21, 100 + 38 * 4, BMP_Jiechuqi, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 42 + 84, 100 + 38 * 4, BMP_Zhuangtai, WHITE, BLACK); //

        LCD_DrawImageSBPP(82, 100 + 38 * 6, 42, HZBJDJ, WHITE, BLACK); //火灾报警等级      
        LCD_DrawImageSBPP(82, 100 + 38 * 7, 42, HZBJGZDM, WHITE, BLACK); //火灾报警故障代码

        LCD_DrawImageSBPP(82, 100 + 38 * 8, 42, HZBJGZDM, WHITE, BLACK); //火灾报警故障箱号
        LCD_DrawImage1BPP(82 + 42 * 3, 100 + 38 * 8, BMP_Xiang_BMS, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 42 * 3 + 21, 100 + 38 * 8, BMP_Hao, WHITE, BLACK); //

        LCD_DrawImageSBPP(82, 100 + 38 * 9, 42, HZBJDJ, WHITE, BLACK); //火灾报警电池箱号
        LCD_DrawImage1BPP(82 + 42 * 2, 100 + 38 * 9, BMP_DC, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 42 * 3, 100 + 38 * 9, BMP_Xiang_BMS, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 42 * 3 + 21, 100 + 38 * 9, BMP_Hao, WHITE, BLACK); //


        LCD_DrawImageSBPP(82 + 320, 100 + 38 * 0, 42, JYMXDY, WHITE, BLACK); //绝缘母线电压
        LCD_DrawImage1BPP(400 + 320 - 28, 100 + 38 * 0, BMP_v, WHITE, BLACK); //V

        LCD_DrawImageSBPP(82 + 320, 100 + 38 * 1, 42, JYGZZT1, WHITE, BLACK); //绝缘故障状态
        LCD_DrawImageSBPP(82 + 320, 100 + 38 * 2, 42, JYGZDJ, WHITE, BLACK); //绝缘故障等级
        LCD_DrawImageSBPP(82 + 320, 100 + 38 * 3, 42, JYGZZT2, WHITE, BLACK); //绝缘工作状态

        LCD_DrawImage1BPP(82 + 320, 100 + 38 * 4, BMP_Jueyuan, WHITE, BLACK); //绝缘
        LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 4, BMP_DC, WHITE, BLACK); //电池
        LCD_DrawImage1BPP(82 + 320 + 42 + 21, 100 + 38 * 4, BMP_Zu, WHITE, BLACK); //阻
        LCD_DrawImage1BPP(400 + 320 - 28, 100 + 38 * 4, BMP_k, WHITE, BLACK); //K
        LCD_DrawImage1BPP(400 + 320 - 16, 100 + 2 + 38 * 4, BMP_Omu, WHITE, BLACK); //Ω       

        LCD_DrawImage1BPP(82 + 320, 100 + 38 * 5, BMP_Jueyuan, WHITE, BLACK); //绝缘
        LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 5, BMP_Life, WHITE, BLACK); //LIFE */     
    } else if (index == 3) {
        /*LCD_DrawRect(10, 90, 1, 380, GREEN);
        LCD_DrawRect(10 + 390, 90, 1, 380, GREEN);
        LCD_DrawRect(10 + 390 + 390, 90, 1, 380, GREEN);
        for (i = 0; i < 11; i++)
            LCD_DrawRect(10, 90 + i * 38, 780, 1, GREEN);

        for (j = 0; j < 2; j++) {
            for (i = 0; i < 10; i++) {
                LCD_DrawImageSBPP(12 + 390 * j, 100 + 38 * i, 42, DLDC, WHITE, BLACK); //动力电池箱号N
                LCD_DrawImage1BPP(12 + 390 * j + 84, 100 + 38 * i, BMP_Xiang_BMS, WHITE, BLACK);
                LCD_DrawImage1BPP(12 + 390 * j + 84 + 21, 100 + 38 * i, BMP_Hao, WHITE, BLACK);
                print_SZ_1(12 + 390 * j + 84 + 42, 100 - 8 + 38 * i, 10 * j + i + 1, 2, 0, WHITE);
                LCD_DrawImage1BPP(310 + 390 * j - 24 - 63 - 5 + 16 * 4, 100 + 38 * i, BMP_v, YELLOW, BLACK); //V
                LCD_DrawImage1BPP(12 + 390 * j + 42 * 8.5 + 5, 100 + 38 * i, BMP_Chuan, WHITE, BLACK); //串
            }
        }*/
    }
}

void BMSUpdate(unsigned char index) {
    if (index == 1) {
#if 1
        updata_DAT(82 + 200 + 30, 100 - 8, CAN_0x1818D0F3.BMS_V, 0.1, 1000, WHITE, 3, 0);
        updata_DAT(82 + 200 + 30, 100 - 8 + 38 * 1, CAN_0x1819D0F3.BMS_A_charge, 0.1, 1000, WHITE, 3, 0);
        updata_DAT(82 + 200 + 30, 100 - 8 + 38 * 2, CAN_0x1819D0F3.BMS_A_discharge, 0.1, 1000, WHITE, 3, 0);
        updata_DAT(82 + 200 + 30 - 32, 100 - 8 + 38 * 3, CAN_0x1819D0F3.BMS_V_average, 1, 10000, WHITE, 4, 2);
        print_D(82 + 180, 100 - 8 + 38 * 4, CAN_0x1818D0F3.BMSFlag1.byte, 8, 0, WHITE);
        print_D(82 + 180, 100 - 8 + 38 * 5, CAN_0x1818D0F3.BMSFlag2.byte, 8, 0, WHITE);
        print_D(82 + 180, 100 - 8 + 38 * 6, CAN_0x1818D0F3.BMSFlag3.byte, 8, 0, WHITE);
        print_D(82 + 180, 100 - 8 + 38 * 7, CAN_0x181CD0F3.BMSFlag4.byte, 8, 0, WHITE);
        print_SZ_1(82 + 200 + 30 - 16, 100 - 8 + 38 * 8, CAN_0x181BD0F3.BATRestEnerge / 10, 3, 0, WHITE);


        print_SZ_1(82 + 200 + 30 + 270, 100 - 8, CAN_0x181AD0F3.Oum_zheng, 5, 0, WHITE); //绝缘正
        print_SZ_1(82 + 200 + 30 + 270, 100 - 8 + 38, CAN_0x181AD0F3.Oum_fu, 5, 0, WHITE); //绝缘负  
        
        updata_DAT(82 + 200 + 260, 100 - 8 + 38 * 2, CAN_0x181AD0F3.Battery_single_H, 1, 0, WHITE, 4, 3); //电池最高电压
        print_SZ_1(82 + 200 + 260 + 16 * 7, 100 - 8 + 38 * 2, CAN_0x181BD0F3.BAT_Max_Cell_Voltage_Cell_Case + 1, 2, 0, WHITE);
        print_SZ_1(82 + 200 + 260 + 16 * 11, 100 - 8 + 38 * 2, CAN_0x181BD0F3.BAT_Max_Cell_Voltage_Cell_Number + 1, 2, 0, WHITE);

        updata_DAT(82 + 200 + 260, 100 - 8 + 38 * 3, CAN_0x181AD0F3.Battery_single_L, 1, 0, WHITE, 4, 3); //电池最低电压
        print_SZ_1(82 + 200 + 260 + 16 * 7, 100 - 8 + 38 * 3, CAN_0x181BD0F3.BAT_Min_Cell_Voltage_Cell_Case + 1, 2, 0, WHITE);
        print_SZ_1(82 + 200 + 260 + 16 * 11, 100 - 8 + 38 * 3, CAN_0x181BD0F3.BAT_Min_Cell_Voltage_Cell_Number + 1, 2, 0, WHITE);

        updata_DAT(82 + 200 + 260 + 16 * 2, 100 - 8 + 38 * 4, CAN_0x1819D0F3.BMS_T_H, 1, 40, WHITE, 3, 0); //最高温度 
        print_SZ_1(82 + 200 + 260 + 16 * 7, 100 - 8 + 38 * 4, CAN_0x181BD0F3.BAT_Max_Cell_Temp_Cell_Case + 1, 2, 0, WHITE);
        print_SZ_1(82 + 200 + 260 + 16 * 11, 100 - 8 + 38 * 4, CAN_0x181BD0F3.BAT_Max_Cell_Temp_Cell_Number + 1, 2, 0, WHITE);

        updata_DAT(82 + 200 + 260 + 16 * 2, 100 - 8 + 38 * 5, CAN_0x181BD0F3.BAT_Min_Cell_Temperature, 1, 40, WHITE, 3, 0); //最低温度 
        print_SZ_1(82 + 200 + 260 + 16 * 7, 100 - 8 + 38 * 5,CAN_0x181BD0F3.BAT_Min_Cell_Temp_Cell_Case + 1, 2, 0, WHITE);
        print_SZ_1(82 + 200 + 260 + 16 * 11, 100 - 8 + 38 * 5, CAN_0x181BD0F3.BAT_Min_Cell_Temp_Cell_Number + 1, 2, 0, WHITE);
        
        updata_DAT(82 + 200 + 30 + 270 + 32, 100 - 8 + 38 * 6, CAN_0x1818D0F3.BMS_A, 0.1, 1000, WHITE, 3, 0); 
        print_SZ_1(82 + 200 + 30 + 270 + 32, 100 - 8 + 38 * 7, CAN_0x1819D0F3.Warn_level, 3, 0, WHITE);
        
        updata_DAT(82 + 200 + 30 + 270 + 16 * 2, 100 - 8 + 38 * 8, CAN_0x181CD0F3.ChargeSocketTemp1, 1, 40, WHITE, 3, 0);
        updata_DAT(82 + 200 + 30 + 270 + 16 * 2, 100 - 8 + 38 * 9, CAN_0x181CD0F3.ChargeSocketTemp2, 1, 40, WHITE, 3, 0);
#endif
    } else if (index == 2) {
#if 0
        print_SZ_1(82 + 200 + 30, 100 - 8, BMS_Warn_Type, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 30, 100 - 8 + 38 * 1, BMS_1LevelFault, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 30, 100 - 8 + 38 * 2, BMS_2LevelFault, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 30, 100 - 8 + 38 * 3, BMS_3LevelFault, 3, 0, WHITE);
        if (BMS_KB == 1) {
            LCD_DrawImage1BPP(82 + 42 * 6 - 5, 100 + 38 * 4, BMP_Bihe, GREEN, BLACK);
        } else if (BMS_KB == 0) {
            LCD_DrawImage1BPP(82 + 42 * 6 - 5, 100 + 38 * 4, BMP_Duankai, RED, BLACK);
        }

        print_SZ_1(82 + 200 + 30, 100 - 8 + 38 * 6, BMS_FireWarnLevel, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 30, 100 - 8 + 38 * 7, BMS_FireFaultCode, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 30, 100 - 8 + 38 * 8, BMS_FireFaultNumber, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 30, 100 - 8 + 38 * 9, BMS_FireWarnNumber, 3, 0, WHITE);



        print_SZ_1(82 + 200 + 320 + 30 - 48, 100 - 8 + 38 * 0, IM_Votage * 0.1, 5, 0, WHITE);
        if (IM_FaultStatus == 0xAA) {
            LCD_DrawImage1BPP(82 + 320 + 42 * 6 - 5, 100 + 38 * 1, BMP_Zhengchang, GREEN, BLACK);
        } else if (IM_FaultStatus == 0x55) {
            LCD_DrawImage1BPP(82 + 320 + 42 * 6 - 5, 100 + 38 * 1, BMP_Guzhang, RED, BLACK);
        }
        print_SZ_1(82 + 200 + 320 + 30 - 32, 100 - 8 + 38 * 2, IM_FaultLevel, 4, 0, WHITE);
        if (IM_WorkStatus == 0xAA) {
            LCD_DrawImage1BPP(82 + 320 + 42 * 6 - 5, 100 + 38 * 3, BMP_Gongzuo, GREEN, BLACK);
        } else if (IM_WorkStatus == 0x55) {
            LCD_DrawImage1BPP(82 + 320 + 42 * 6 - 5, 100 + 38 * 3, BMP_Tingzhi, RED, BLACK);
        }
        print_SZ_1(82 + 200 + 320 + 30 - 48, 100 - 8 + 38 * 4, IM_Oum, 6, 0, WHITE);
        print_SZ_1(82 + 200 + 320 + 30, 100 - 8 + 38 * 5, IM_Life, 3, 0, WHITE);
#endif
    } else if (index == 3) {
#if 0
        for (j = 0; j < 2; j++) {
            for (i = 0; i < 10; i++) {
                print_SZ_1(12 + 180 + 390 * j - 5, 100 - 8 + 38 * i, BAT_Pack_Voltage[10 * j + i + 1], 4, 1, WHITE);
                print_SZ_1(12 + 180 + 390 * j - 32 + 16 * 10 + 5, 100 - 8 + 38 * i, BAT_Pack_Number[10 * j + i + 1], 3, 0, WHITE);
            }
        }
#endif
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
        if (index_BMS == 2) {
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
void BATFrame(unsigned char index) {
    unsigned char i, j;
    LCD_Clear();
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //顶部横线
    LCD_DrawImageSBPP(130 + 200 + 24, 130 - 85, 50, Battery_SYSTEM, WHITE, BLACK);

    //分格
    for (i = 0; i < 6; i++) {
        LCD_DrawRect(i * 160, 45 + 70, 1, 360, GREEN);
        LCD_DrawRect(58 + i * 160, 45 + 70, 1, 360, GREEN);
    }
    for (i = 0; i < 13; i++)
        LCD_DrawRect(0, 45 + 70 + i * 36, 800, 1, GREEN);

    LCD_DrawImage1BPP(50, 90, BMP_DC, WHITE, BLACK); //电池
    LCD_DrawImage1BPP(50 + 42, 90, BMP_Xiang_BMS, WHITE, BLACK); //箱
    LCD_DrawImage1BPP(50 + 42 + 21, 90, BMP_Hao, WHITE, BLACK); //号
    LCD_DrawImage1BPP(50 + 42 + 42 + 21 + 15, 90 - 9, BMP_SZ_1[index], GREEN, BLACK);

    for (j = 0; j < 4; j++) {
        for (i = 0; i < 10; i++) {
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

    for (j = 0; j < 1; j++) {
        for (i = 0; i < 6; i++) {
            if (i < 9) {//写编号个位
                LCD_DrawImage1BPP(5 + 16 + 16 + (j + 4) * 160, 46 + 70 + i * 36, BMP_SZ_1[i + 1], WHITE, BLACK);
                if (j > 0) {//写编号十位
                    LCD_DrawImage1BPP(5 + 16 + (j + 4) * 160, 46 + 70 + i * 36, BMP_SZ_1[j], WHITE, BLACK);
                }
            } else {//写最底下一行编号
                LCD_DrawImage1BPP(5 + 16 + 16 + (j + 4) * 160, 46 + 70 + i * 36, BMP_SZ_1[0], WHITE, BLACK);
                LCD_DrawImage1BPP(5 + 16 + (j + 4) * 160, 46 + 70 + i * 36, BMP_SZ_1[j + 1], WHITE, BLACK);
            }
            LCD_DrawImage1BPP(5 + 3 + 16 + 16 + 100 + (j + 4) * 160, 46 + 70 + 8 + i * 36, BMP_T, YELLOW, BLACK);
        }
    }

    /*for (i = 0; i < 4; i++) {
        LCD_DrawImageSBPP(82 + 320, 100 + 38 * i, 63, PDHDL, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 320 + 105, 100 + 38 * i, BMP_SZ_2[i + 1], WHITE, BLACK);
        LCD_DrawImage1BPP(400 + 320 - 24 - 22, 100 + 38 * i, BMP_a, WHITE, BLACK); //A
    }

    for (i = 0; i < 6; i++) {
        LCD_DrawImageSBPP(82 + 320, 100 + 38 * (i + 4), 63, PDHWD, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 320 + 105, 100 + 38 * (i + 4), BMP_SZ_2[i + 1], WHITE, BLACK);
        LCD_DrawImage1BPP(400 + 320 - 24 - 22, 100 + 38 * (i + 4), BMP_T, WHITE, BLACK); //℃
    }*/
}

void BATUpdate(unsigned char index) { 
    unsigned char i, j;
    if (index > 0 && index < 6) {
        for (j = 0; j < 4; j++) {
            for (i = 0; i < 10; i++) {
                if ((BAT_Cell_Voltage[index - 1][j * 10 + i] == 0) || (BAT_Cell_Voltage[index - 1][j * 10 + i] > 10000)) {//(BAT_Cell_Voltage[index - 1][j * 10 + i] < 10000) {
                    print_SZ_1(60 + j * 160, 46 + 70 + 36 * i, BAT_Cell_Voltage[index - 1][j * 10 + i], 4, 3, BLACK);
                } else
                    print_SZ_1(60 + j * 160, 46 + 70 + 36 * i, BAT_Cell_Voltage[index - 1][j * 10 + i], 4, 3, GREEN); //单体电压
            }
        }
        for (i = 0; i < 6; i++) {
            if ((BAT_Cell_Temp[index - 1][i] == 0xFF) || (BAT_Cell_Temp[index - 1][i] == 0))
                updata_DAT(60 + 4 * 160 + 25, 46 + 70 + 36 * i, BAT_Cell_Temp[index - 1][i], 1, 40, BLACK, 3, 0);
            else
                updata_DAT(60 + 4 * 160 + 25, 46 + 70 + 36 * i, BAT_Cell_Temp[index - 1][i], 1, 40, GREEN, 3, 0); //单体温度
        }
    }
    /*print_SZ_1(82 + 200 + 20 - 32 - 48, 100 - 8 + 38 * 0, CAN_0x18FE521E.XDC_V * 5, 6, 2, WHITE);
    updata_DAT(82 + 200 + 20 - 32, 100 - 8 + 38 * 1, CAN_0x18FE521E.XDC_A, 0.05, 1600, WHITE, 4, 0);
    updata_DAT(82 + 200 + 20 - 16, 100 - 8 + 38 * 2, CAN_0x18FE521E.PDH_Temp, 1, 40, WHITE, 3, 0);
    if (CAN_0x18FE521E.PDH_Status) {
            LCD_DrawImage1BPP(82 + 42 * 5 - 5, 100 + 38 * 3, BMP_Bihe, GREEN, BLACK);
        } else {
            LCD_DrawImage1BPP(82 + 42 * 5 - 5, 100 + 38 * 3, BMP_Duankai, RED, BLACK);
        }
    
    if (CAN_0x18FE521E.PDH_OverCurrent) {
            LCD_DrawImage1BPP(82 + 42 * 1 - 5, 100 + 38 * 4, BMP_Guoliu, RED, BLACK);
        }else {
            LCD_DrawImage1BPP(82 + 42 * 1 - 5, 100 + 38 * 4, BMP_Guoliu, GRAY, BLACK);
        }
    
    if (CAN_0x18FE521E.PDH_OverVoltage) {
            LCD_DrawImage1BPP(82 + 42 * 3 - 5, 100 + 38 * 4, BMP_Guoya, RED, BLACK);
        }else {
            LCD_DrawImage1BPP(82 + 42 * 3 - 5, 100 + 38 * 4, BMP_Guoya, GRAY, BLACK);
        }
    
    if (CAN_0x18FE521E.PDH_Protect) {
            LCD_DrawImage1BPP(82 + 42 * 5 - 5, 100 + 38 * 4, BMP_Baohu, RED, BLACK);
        }else {
            LCD_DrawImage1BPP(82 + 42 * 5 - 5, 100 + 38 * 4, BMP_Baohu, GRAY, BLACK);
        }
    */
    /*for (i = 0; i < 4; i++) {
        updata_DAT(82 + 200 + 320 - 32, 100 - 8 + 38 * i, CAN_0x1CFF5281.two[i], 0.05, 1600, WHITE, 4, 0);
    }
    
    for (i = 0; i < 6; i++) {
        updata_DAT(82 + 200 + 320 - 16, 100 - 8 + 38 * (i + 4), CAN_0x1CFF5381.byte[i + 1], 1, 40, WHITE, 3, 0);
    }*/
}

void frmBAT(void) {
    static unsigned char index_BAT = 1;
    if (f_index == 0) { //只更新一次
        f_index = 1;
        BATFrame(index_BAT);
    } else if (f_index == 1) {
        f_index = 1;
        BATUpdate(index_BAT);
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
void ACFrame(void) {
    unsigned char i = 0;
    LCD_Clear();
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //顶部横线
    LCD_DrawImageSBPP(130 + 200 - 2, 130 - 85, 50, AC_SYSTEM, WHITE, BLACK); 

    LCD_DrawRect(80, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320 + 320, 90, 1, 380, GREEN);
    for (i = 0; i < 11; i++)
        LCD_DrawRect(80, 90 + i * 38, 640, 1, GREEN);

    LCD_DrawImageSBPP(82 + 82, 100 + 38 * 0, 42, KTGZMS, WHITE, BLACK); //空调工作模式
    
    
    
    LCD_DrawImageSBPP(82 + 82 + 320, 100 + 38 * 0, 42, KTGZMS, WHITE, BLACK); //空调工作模式    
}

void ACUpdate(void) {
    if (CAN_0x18FFC119.AirWorkMode1_Zhileng == 1) {
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 1, BMP_Zhileng, GREEN, BLACK);
    } else if(CAN_0x18FFC119.AirWorkMode1_Zhileng == 0){
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 1, BMP_Zhileng, GRAY, BLACK);
    }
    
    if (CAN_0x18FFC119.AirWorkMode1_Zhire == 1) {
        LCD_DrawImage1BPP(82 + 42 + 63, 100 + 38 * 1, BMP_Zhire, GREEN, BLACK);
    } else if(CAN_0x18FFC119.AirWorkMode1_Zhire == 0){
        LCD_DrawImage1BPP(82 + 42 + 63, 100 + 38 * 1, BMP_Zhire, GRAY, BLACK);
    }
    
    
    if (CAN_0x18FFC119.AirWorkMode1_Xinfeng == 1) {
        LCD_DrawImage1BPP(82 + 42 + 63 * 2, 100 + 38 * 1, BMP_Xinfeng, GREEN, BLACK);
    } else if(CAN_0x18FFC119.AirWorkMode1_Xinfeng == 0){
        LCD_DrawImage1BPP(82 + 42 + 63 * 2, 100 + 38 * 1, BMP_Xinfeng, GRAY, BLACK);
    }
    
    
    if (CAN_0x18FFC119.AirWorkMode1_Xiaodu == 1) {
        LCD_DrawImage1BPP(82 + 42 + 63 * 3, 100 + 38 * 1, BMP_Xiaodu, GREEN, BLACK);
    } else if(CAN_0x18FFC119.AirWorkMode1_Xiaodu == 0){
        LCD_DrawImage1BPP(82 + 42 + 63 * 3, 100 + 38 * 1, BMP_Xiaodu, GRAY, BLACK);
    }
    
    
    
    if (CAN_0x18FFC119.AirWorkMode2_Zidong == 1) {
        LCD_DrawImage1BPP(82 + 63 + 320, 100 + 38 * 1, BMP_Zidong, GREEN, BLACK);
    } else if(CAN_0x18FFC119.AirWorkMode2_Zidong == 0){
        LCD_DrawImage1BPP(82 + 63 + 320, 100 + 38 * 1, BMP_Shoudong, GREEN, BLACK);
    }
    
    if (CAN_0x18FFC119.AirWorkMode2_Chushi == 1) {
        LCD_DrawImage1BPP(82 + 63 + 320 + 63, 100 + 38 * 1, BMP_Chushi, GREEN, BLACK);
    } else if(CAN_0x18FFC119.AirWorkMode2_Chushi == 0){
        LCD_DrawImage1BPP(82 + 63 + 320 + 63, 100 + 38 * 1, BMP_Chushi, GRAY, BLACK);
    }
       
    if (CAN_0x18FFC119.AirWorkMode2_Tongfeng == 1) {
        LCD_DrawImage1BPP(82 + 63 + 320 + 63 * 2, 100 + 38 * 1, BMP_Tongfeng, GREEN, BLACK);
    } else if(CAN_0x18FFC119.AirWorkMode2_Tongfeng == 0){
        LCD_DrawImage1BPP(82 + 63 + 320 + 63 * 2, 100 + 38 * 1, BMP_Tongfeng, GRAY, BLACK);
    }
        

}

void frmAC(void) {
    if (f_index == 0) { //只更新一次
        f_index = 1;
        ACFrame();
    } else if (f_index == 1) {
        f_index = 1;
        ACUpdate();
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

unsigned int new_pluse = 103;

void update_setDATE(void) {
    unsigned int temp = 0;
    unsigned int x = 180, y = 120;
    print_SZ_2(x + 100 + 60 + 20, y + 85, e_hm_pulse, 3, 0, GREEN); //   
    print_SZ_2(x + 210 + 60 + 30, y + 85, SPEED, 3, 0, GREEN); //车速

    //目标值
    print_SZ_2(x + 100 + 60 + 20, y + 125, new_pluse, 3, 0, RED); // 
    temp = (unsigned int) (SPEED * new_pluse / e_hm_pulse);
    //车速
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
            frmDCDC();          
            //frmENG();
            break;
        case 4:
            frmDMQ();
            break;
        case 5:
            frmDMY();
            break;
        case 6:
            frmBMS();
            break;
        case 7:
            frmBAT();
            //frmPDH();
            break;
        case 8:
            frmAC();
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



