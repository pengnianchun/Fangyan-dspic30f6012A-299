#include "SYSTEM.h"
#include "FONT.h"
#include "LOGO.h"

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

void BMP_BUS(unsigned int x, unsigned int y) {
    unsigned char i;
    LCD_DrawRect(x + 209, y, 178, 2, WHITE); //顶部长方形
    LCD_DrawRect(x + 209, y + 8, 176, 2, WHITE);
    LCD_DrawRect(x + 209, y, 2, 8, WHITE);
    LCD_DrawRect(x + 209 + 176, y, 2, 8, WHITE);

    LCD_DrawRect(x, y + 8, 471, 2, WHITE); //上外框长
    LCD_DrawRect(x, y + 8, 2, 92, WHITE); //外框高
    LCD_DrawImage1BPP(x, y + 8 + 92, Bmp_Xiahuaxian, WHITE, BLACK); //后下划线
    LCD_DrawRect(x + 54, y + 8 + 105, 471 - 54, 2, WHITE); //下外框长
    LCD_DrawRect(x + 8, y + 8 + 12, 471 - 8, 2, WHITE); //内框长
    LCD_DrawRect(x + 8, y + 8 + 12, 2, 92 - 12, WHITE); //内框高

    LCD_DrawImage1BPP(x + 91, y + 76, Bmp_Luntai, WHITE, BLACK); //轮胎1
    LCD_DrawImage1BPP(x + 91 + 227, y + 76, Bmp_Luntai, WHITE, BLACK); //轮胎2

    LCD_DrawImage1BPP(x + 195, y + 27, Bmp_Men, WHITE, BLACK); //门1
    LCD_DrawImage1BPP(x + 184 + 215, y + 27, Bmp_Men, WHITE, BLACK); //门2

    LCD_DrawImage1BPP(x + 471, y + 6, Bmp_Chetou, WHITE, BLACK); //车头


    LCD_DrawRect(x + 8 + 3, y + 8 + 12 + 3, 31, 1, WHITE); //小窗户1
    LCD_DrawRect(x + 8 + 3, y + 8 + 12 + 3 + 20, 31, 1, WHITE); //
    LCD_DrawRect(x + 8 + 3, y + 8 + 12 + 3, 1, 20, WHITE); //
    LCD_DrawRect(x + 8 + 3 + 31, y + 8 + 12 + 3, 1, 20, WHITE); //

    LCD_DrawRect(x + 8 + 3 + 34, y + 8 + 12 + 3, 31, 1, WHITE); //小窗户2
    LCD_DrawRect(x + 8 + 3 + 34, y + 8 + 12 + 3 + 20, 31, 1, WHITE); //
    LCD_DrawRect(x + 8 + 3 + 34, y + 8 + 12 + 3, 1, 20, WHITE); //
    LCD_DrawRect(x + 8 + 3 + 31 + 34, y + 8 + 12 + 3, 1, 20, WHITE); //

    LCD_DrawRect(x + 8 + 3 + 15, y + 8 + 12 + 3 + 50, 32, 1, WHITE); //散热孔
    LCD_DrawRect(x + 8 + 3 + 15, y + 8 + 12 + 3 + 28 + 50, 32, 1, WHITE); //
    for (i = 0; i < 9; i++) {
        LCD_DrawRect(x + 8 + 3 + 15 + 4 * i, y + 8 + 12 + 3 + 50, 1, 28, WHITE); //
    }
    //LCD_DrawRect(150 + 8 + 3 + 35+15, 150 + 8 + 12 + 3+50, 1, 28, YELLOW); //

    LCD_DrawRect(x + 8 + 3 + 34 + 34, y + 8 + 12 + 3, 53, 1, WHITE); //中窗户1
    LCD_DrawRect(x + 8 + 3 + 34 + 34, y + 8 + 12 + 3 + 46, 53, 1, WHITE); //
    LCD_DrawRect(x + 8 + 3 + 34 + 34, y + 8 + 12 + 3, 1, 46, WHITE); //
    LCD_DrawRect(x + 8 + 3 + 33 + 34 + 53, y + 8 + 12 + 3, 1, 46, WHITE); //

    LCD_DrawRect(x + 8 + 3 + 34 + 34 + 56, y + 8 + 12 + 3, 53, 1, WHITE); //中窗户2
    LCD_DrawRect(x + 8 + 3 + 34 + 34 + 56, y + 8 + 12 + 3 + 46, 53, 1, WHITE); //
    LCD_DrawRect(x + 8 + 3 + 34 + 34 + 56, y + 8 + 12 + 3, 1, 46, WHITE); //
    LCD_DrawRect(x + 8 + 3 + 33 + 34 + 53 + 56, y + 8 + 12 + 3, 1, 46, WHITE); //

    LCD_DrawRect(x + 8 + 3 + 34 + 34 + 56 * 2 + 72 + 10, y + 8 + 12 + 3, 53, 1, WHITE); //中窗户1
    LCD_DrawRect(x + 8 + 3 + 34 + 34 + 56 * 2 + 72 + 10, y + 8 + 12 + 3 + 46, 53, 1, WHITE); //
    LCD_DrawRect(x + 8 + 3 + 34 + 34 + 56 * 2 + 72 + 10, y + 8 + 12 + 3, 1, 46, WHITE); //
    LCD_DrawRect(x + 8 + 3 + 33 + 34 + 53 + 56 * 2 + 72 + 10, y + 8 + 12 + 3, 1, 46, WHITE); //

    LCD_DrawRect(x + 8 + 3 + 34 + 34 + 56 * 3 + 72 + 20, y + 8 + 12 + 3, 53, 1, WHITE); //中窗户2
    LCD_DrawRect(x + 8 + 3 + 34 + 34 + 56 * 3 + 72 + 20, y + 8 + 12 + 3 + 46, 53, 1, WHITE); //
    LCD_DrawRect(x + 8 + 3 + 34 + 34 + 56 * 3 + 72 + 20, y + 8 + 12 + 3, 1, 46, WHITE); //
    LCD_DrawRect(x + 8 + 3 + 33 + 34 + 53 + 56 * 3 + 72 + 20, y + 8 + 12 + 3, 1, 46, WHITE); //
}

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
    LCD_DrawRect(0, 430 + 15, 800, 2, GREEN); //底部横线   

    BMP_BUS(150, 150 + 40); //画BUS

    //LCD_DrawRect(0,70,800,3,YELLOW); //顶部横线
    // LCD_DrawImage1BPPZOOM_4(336, 150, BMP_LOGO, BLUE, BLACK); //客车车标
    //动力电池电流 电压 SOC 外观

    LCD_DrawImage1BPP(170, 150 + 5 - 10, BMP_SOC, WHITE, BLACK); //SOC
    LCD_DrawRect(225, 150 + 5 - 10, 335, 2, WHITE);
    LCD_DrawRect(225, 150 + 35 - 10, 335, 2, WHITE);
    LCD_DrawRect(225, 155 - 10, 2, 32, WHITE);
    LCD_DrawRect(225 + 83, 145 - 10, 2, 10, WHITE);
    LCD_DrawRect(225 + 83 + 83, 145 - 10, 2, 10, WHITE);
    LCD_DrawRect(225 + 83 + 83 + 83, 145 - 10, 2, 10, WHITE);
    LCD_DrawRect(225 + 83 + 83 + 83 + 84, 155 - 10, 2, 32, WHITE);
    LCD_DrawImage1BPP(225 - 4, 155 - 14 - 10, BMP_SZ[0], WHITE, BLACK); //0
    LCD_DrawImage1BPP(225 + 83 + 83 + 83 + 84 - 12, 155 - 14 - 10, BMP_SZ[1], WHITE, BLACK); //1
    LCD_DrawImage1BPP(225 + 83 + 83 + 83 + 84 - 4, 155 - 14 - 10, BMP_SZ[0], WHITE, BLACK); //0
    LCD_DrawImage1BPP(225 + 83 + 83 + 83 + 84 + 4, 155 - 14 - 10, BMP_SZ[0], WHITE, BLACK); //0
    LCD_DrawImage1BPP(660, 155 - 10, BMP_BAIFENHAO, WHITE, BLACK);
    /*
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
    LCD_DrawImage1BPP(660, 155 + 60 + 60, BMP_BAIFENHAO, WHITE, BLACK);*/

    //LCD_DrawImage1BPP(20, 130, BMP_Gao, WHITE, BLACK); //高压电池
    //LCD_DrawImage1BPP(660-550, 155, BMP_V, WHITE, BLACK);   
    //LCD_DrawImage1BPP(660-550, 155 + 60, BMP_A, WHITE, BLACK);

    /*LCD_DrawImage1BPP(5, 400 + 15 - 65 + 40, BMP_Vv, WHITE, BLACK); //V
    LCD_DrawImage1BPP(5 + 20, 400 + 15 - 50 + 5 + 30, Bmp_Xiadianchi, WHITE, BLACK); //小电池
    LCD_DrawImage1BPP(15 + 130, 318 + 15 + 38 + 8, BMP_v, WHITE, BLACK); //V
    LCD_DrawImage1BPP(15 + 130, 318 + 15 + 38 * 2 + 8, BMP_v, WHITE, BLACK); //V

    LCD_DrawImage1BPP(800 - 180, 400 + 15 - 65 + 40, BMP_Tt, WHITE, BLACK); //T
    LCD_DrawImage1BPP(800 - 160, 400 + 15 - 50 + 5 + 30, Bmp_Xiadianchi, WHITE, BLACK); //小电池
    LCD_DrawImage1BPP(800 - 20, 318 + 10 + 15 + 38, BMP_T, WHITE, BLACK); //℃
    LCD_DrawImage1BPP(800 - 20, 318 + 10 + 15 + 38 * 2, BMP_T, WHITE, BLACK); //℃
    */
    LCD_DrawImage1BPP(60, 365 + 15- 50 + 10, BMP_Dan, WHITE, BLACK); //单体电压
    LCD_DrawImage1BPP(60 + 21, 365+ 15 - 50 + 10, BMP_Ti, WHITE, BLACK);
    LCD_DrawImage1BPP(60 + 42, 365+ 15 - 50 + 10, BMP_DY, WHITE, BLACK);
    LCD_DrawImage1BPP(15 + 130, 318+ 15+38+8, BMP_v, WHITE, BLACK); //V
    LCD_DrawImage1BPP(15 + 130, 318+ 15+38*2+8, BMP_v, WHITE, BLACK); //V

    LCD_DrawImage1BPP(70 + 550, 365+ 15 - 50 + 10, BMP_Dan, WHITE, BLACK); //单体温度
    LCD_DrawImage1BPP(70 + 550 + 21, 365 + 15- 50 + 10, BMP_Ti, WHITE, BLACK);
    LCD_DrawImage1BPP(70 + 550 + 42, 365+ 15 - 50 + 10, BMP_Wendu, WHITE, BLACK);
    LCD_DrawImage1BPP(800 - 90, 318 + 15+ 10 + 38, BMP_T, WHITE, BLACK); //℃
    LCD_DrawImage1BPP(800 - 90, 318 + 15+ 10 + 38 * 2, BMP_T, WHITE, BLACK); //℃

    LCD_DrawImage1BPP(180 - 20 + 2, 365 + 15 - 50 + 10, BMP_Zong, WHITE, BLACK); //总
    LCD_DrawImage1BPP(180 - 20 + 2 + 21, 365 + 15 - 50 + 10, BMP_DY, WHITE, BLACK); //电压
    LCD_DrawImage1BPP(225 + 83 + 83 - 22, 365 + 15 - 50 + 5, BMP_V, WHITE, BLACK); //V

    //LCD_DrawImage1BPP(20, 365 - 50 + 10, BMP_Licheng, WHITE, BLACK); //里程

    LCD_DrawImage1BPP(225 + 83 + 83 + 2, 365 + 15 - 50 + 10, BMP_Zong, WHITE, BLACK); //总
    LCD_DrawImage1BPP(225 + 83 + 83 + 2 + 21, 365 + 15 - 50 + 10, BMP_DL, WHITE, BLACK); //电流
    LCD_DrawImage1BPP(615 - 22, 365 + 15 - 50 + 5, BMP_A, WHITE, BLACK); //A

    /*LCD_DrawImage1BPP(225 + 83 + 83 + 2, 365 + 15 - 50 + 10 + 38, BMP_DJ, WHITE, BLACK); //电机
    LCD_DrawImage1BPP(225 + 83 + 83 + 2 + 42, 365 + 15 - 50 + 10 + 38, BMP_Zhuanju, WHITE, BLACK); //转矩
    LCD_DrawImage1BPP(615 - 34, 365 + 15 - 50 + 10 + 38, BMP_n, WHITE, BLACK); //NM
    LCD_DrawImage1BPP(615 - 34 + 16, 365 + 15 - 50 + 10 + 38, BMP_m, WHITE, BLACK); //
     */

    LCD_DrawImage1BPP(180 - 20 + 2, 365 + 15 - 50 + 10 + 38, BMP_DJ, WHITE, BLACK); //电机
    LCD_DrawImage1BPP(180 - 20 + 2 + 43, 365 + 15 - 50 + 10 + 38, BMP_Wendu, WHITE, BLACK); //温度
    LCD_DrawImage1BPP(225 + 83 + 83 - 22, 365 + 15 - 50 + 10 + 38, BMP_T, WHITE, BLACK); //℃

    LCD_DrawImage1BPP(225 + 83 + 83 + 2, 365 + 15 - 50 + 10 + 38, BMP_DJ, WHITE, BLACK); //电机
    LCD_DrawImage1BPP(225 + 83 + 83 + 2 + 43, 365 + 15 - 50 + 10 + 38, BMP_KZQ, WHITE, BLACK); //控制器
    LCD_DrawImage1BPP(615 - 22, 365 + 15 - 50 + 10 + 38, BMP_T, WHITE, BLACK); //℃

    //银龙界面第一次版本
    /*LCD_DrawImage1BPP(650, 365 - 65 + 10 - 38, BMP_Vv, WHITE, BLACK); //V
    LCD_DrawImage1BPP(670, 365 - 50 + 5 - 38, Bmp_Xiadianchi, WHITE, BLACK); //小电池
    LCD_DrawImage1BPP(780, 365 - 50 + 10-38, BMP_v, WHITE, BLACK); //V
    LCD_DrawImage1BPP(780, 365 - 50 + 10, BMP_v, WHITE, BLACK); //V

    LCD_DrawImage1BPP(650, 365 - 65 + 10 + 38, BMP_Tt, WHITE, BLACK); //T
    LCD_DrawImage1BPP(670, 365 - 50 + 5 + 38, Bmp_Xiadianchi, WHITE, BLACK); //小电池
    LCD_DrawImage1BPP(780, 365 - 50 + 10 + 38, BMP_T, WHITE, BLACK); //℃
    LCD_DrawImage1BPP(780, 365 - 50 + 10+38*2, BMP_T, WHITE, BLACK); //℃
    
    LCD_DrawImage1BPP(20, 130, BMP_Gao, WHITE, BLACK); //高压电池
    LCD_DrawImage1BPP(20, 130, BMP_DY, WHITE, BLACK); //
    LCD_DrawImage1BPP(20+42, 130, BMP_DC, WHITE, BLACK); //
    
    LCD_DrawImage1BPP(660-550, 155, BMP_V, WHITE, BLACK);
    
    LCD_DrawImage1BPP(660-550, 155 + 60, BMP_A, WHITE, BLACK);
    
    LCD_DrawImage1BPP(20, 365 - 50 + 10 - 38 * 2, BMP_DJ, WHITE, BLACK); //电机
    LCD_DrawImage1BPP(20 + 42, 365 - 50 + 10 - 38 * 2, BMP_KZQ, WHITE, BLACK); //控制器
    LCD_DrawImage1BPP(660 - 550, 365 - 50 + 10 - 38, BMP_T, WHITE, BLACK); //℃
    LCD_DrawImage1BPP(660 - 550, 365 - 50 + 10, BMP_T, WHITE, BLACK); //℃

    LCD_DrawImage1BPP(20, 365 - 50 + 10 + 38, BMP_DJ, WHITE, BLACK); //电机
    LCD_DrawImage1BPP(20+42, 365 - 50 + 10 + 38, BMP_Zhuansu, WHITE, BLACK); //转速
    LCD_DrawImage1BPP(660 - 550, 365 - 50 + 10 + 38 * 2, BMP_RPM, WHITE, BLACK); //RPM
     */
    /*
    //框框
    LCD_DrawRect(180 - 20, 365 - 50, 350 + 85 + 20, 1, WHITE);
    LCD_DrawRect(180 - 20, 365 - 50, 1, 65 + 50, WHITE);
    LCD_DrawRect(225 + 83 + 83, 365 - 50, 1, 65 + 50, WHITE);
    LCD_DrawRect(615, 365 - 50, 1, 65 + 50, WHITE);
    LCD_DrawRect(180 - 20, 365 - 50 + 38, 350 + 85 + 20, 1, WHITE);
    LCD_DrawRect(180 - 20, 365 - 50 + 38 + 38, 350 + 85 + 20, 1, WHITE);
     */
    /*
                LCD_DrawImage1BPP(180 - 20 + 2, 365 - 50 + 10, BMP_DJ, WHITE, BLACK); //电机
                LCD_DrawImage1BPP(180 - 20 + 2 + 43, 365 - 50 + 10, BMP_KZQ, WHITE, BLACK); //控制器
                //LCD_DrawImage1BPP(180 - 20 + 2 + 43 + 64, 365 - 50 + 10, BMP_Wendu, WHITE, BLACK); //温度
                LCD_DrawImage1BPP(225 + 83 + 83 - 22, 365 - 50 + 10, BMP_T, WHITE, BLACK); //℃

                LCD_DrawImage1BPP(225 + 83 + 83 + 2, 365 - 50 + 10, BMP_DJ, WHITE, BLACK); //电机
                LCD_DrawImage1BPP(225 + 83 + 83 + 2 + 43, 365 - 50 + 10, BMP_Zhuansu, WHITE, BLACK); //转速
                LCD_DrawImage1BPP(615 - 34, 365 - 50 + 10, BMP_RPM, WHITE, BLACK); //RPM

                //LCD_DrawImage1BPP(180 - 20 + 2, 365 - 50 + 10 + 38, BMP_Niaosu, WHITE, BLACK); //尿素
                LCD_DrawImage1BPP(180 - 20 + 2 + 43, 365 - 50 + 10 + 38, BMP_Yewei, WHITE, BLACK); //液位
                LCD_DrawImage1BPP(225 + 83 + 83 - 12, 365 - 50 + 10 + 38, BMP_Baifenhao, WHITE, BLACK); //%

                LCD_DrawImage1BPP(225 + 83 + 83 + 2, 365 - 50 + 10 + 38, BMP_System, WHITE, BLACK); //系统
                LCD_DrawImage1BPP(225 + 83 + 83 + 2 + 43, 365 - 50 + 10 + 38, BMP_Code, WHITE, BLACK); //代码
    
                LCD_DrawImage1BPP(225 + 83 + 83 + 2, 365 - 50 + 10 + 38*2, BMP_s, WHITE, BLACK); //S
                LCD_DrawImage1BPP(225 + 83 + 83 + 2+ 11 , 365 - 50 + 10 + 38*2, BMP_p, WHITE, BLACK); //P
                LCD_DrawImage1BPP(225 + 83 + 83 + 2+ 11 + 11 , 365 - 50 + 10 + 38*2, BMP_n, WHITE, BLACK); //N
                //LCD_DrawImage1BPP(225 + 83 + 83 + 2+ 11 + 11 + 11 + 2, 365 - 50 + 10 + 38*2, BMP_Maohao, WHITE, BLACK); //:

                //框框
                LCD_DrawRect(180 - 20, 365 - 50, 350 + 85 + 20, 1, WHITE);
                LCD_DrawRect(180 - 20, 365 - 50, 1, 65 + 50, WHITE);
                LCD_DrawRect(225 + 83 + 83, 365 - 50, 1, 65 + 50, WHITE);
                LCD_DrawRect(615, 365 - 50, 1, 65 + 50, WHITE);
                LCD_DrawRect(180 - 20, 365 - 50 + 38, 350 + 85 + 20, 1, WHITE);
                LCD_DrawRect(180 - 20, 365 - 50 + 38 + 38, 350 + 85 + 20, 1, WHITE);
     */

    //
    LCD_DrawRect(55, 365 + 15 - 50, 680, 1, GREEN);
    LCD_DrawRect(55, 365 + 15 - 50, 1, 65 + 50, GREEN);
    LCD_DrawRect(735, 365 + 15 - 50, 1, 65 + 50, GREEN);
    LCD_DrawRect(180 - 20, 365 + 15 - 50, 350 + 85 + 20, 1, GREEN);
    LCD_DrawRect(180 - 20, 365 + 15 - 50, 1, 65 + 50, GREEN);
    LCD_DrawRect(225 + 83 + 83, 365 + 15 - 50, 1, 65 + 50 - 38, GREEN);
    LCD_DrawRect(615, 365 + 15 - 50, 1, 65 + 50, GREEN);
    LCD_DrawRect(180 - 20, 365 + 15 - 50 + 38, 350 + 85 + 20, 1, GREEN);
    LCD_DrawRect(180 - 20, 365 + 15 - 50 + 38 + 38, 350 + 85 + 20, 1, GREEN);
    /*LCD_DrawRect(1, 365 - 50 + 15 + 38, 800, 1, GREEN);
    LCD_DrawRect(1, 365 - 50 + 15 + 38, 1, 65 + 50 - 38, GREEN);
    LCD_DrawRect(799, 365 - 50 + 15 + 38, 1, 65 + 50 - 38, GREEN);
    LCD_DrawRect(180 - 20, 365 - 50 + 15, 350 + 85 + 20, 1, GREEN);
    LCD_DrawRect(180 - 20, 365 - 50 + 15, 1, 65 + 50, GREEN);
    LCD_DrawRect(225 + 83 + 83, 365 - 50 + 15, 1, 65 + 50 - 38, GREEN);
    LCD_DrawRect(615, 365 - 50 + 15, 1, 65 + 50, GREEN);
    LCD_DrawRect(180 - 20, 365 - 50 + 38 + 15, 350 + 85 + 20, 1, GREEN);
    LCD_DrawRect(180 - 20, 365 - 50 + 38 + 38 + 15, 350 + 85 + 20, 1, GREEN);
     */

    /*--------------------------------------------
    以下显示的格式为:(ODO 000.0Km       00:00          TRIP0000000Km)
    ---------------------------------------------*/
    LCD_DrawImage1BPP(2, 440 + 3 + 13, Bmp_ODO, YELLOW, BLACK); //累计里程 ODO  
    //print_SZ_4(2+64+4,440,9999999,7,1,WHITE);

    LCD_DrawImage1BPP(210 - 16, 440 + 3 + 13, BMP_HZ_KM, WHITE, BLACK); //单位 Km

    LCD_DrawImage1BPP(240 + 300 + 30, 440 + 3 + 13, Bmp_TRIP, YELLOW, BLACK); //单次里程 TRIF
    //print_SZ_4(240+80+4,440,9999,4,1,WHITE);
    LCD_DrawImage1BPP(404 + 336 + 30, 440 + 3 + 13, BMP_HZ_KM, WHITE, BLACK); //单位 Km

}

void disp_miles(void) {//显示里程
    print_SZ_1(2 + 64 + 4 + 10, 440 - 2 + 13, total_miles / 10, 7, 0, WHITE);
    print_SZ_1(240 + 80 + 4 + 330 + 30 - 16, 440 - 2 + 13, single_miles, 5, 1, WHITE);
}

void disp_time(unsigned int x, unsigned int y, DATE dtimer) {
    unsigned char color = 0;
    static unsigned char color_back=0;
    if(color_back && (t==0)) {
        if (t_add) {//小时设置，十位
            timer.hour = timer.hour + 0x10;
            if ((timer.hour >> 4) > 2) {
                timer.hour = timer.hour & 0x0f;
            }
            DS3231_SetTime(&timer);
            t_add = 0;
        }
    LCD_DrawImage1BPP(x, y, BMP_SMSZ[(dtimer.hour >> 4)&0x0f], WHITE, GRAY);
    }
    else LCD_DrawImage1BPP(x, y, BMP_SMSZ[(dtimer.hour >> 4)&0x0f], WHITE, BLACK);
    
    if(color_back && (t==1)){
        if (t_add) {//小时设置，个位
            timer.hour = timer.hour + 0x01;
            if ((timer.hour & 0x0f) > 9) {
                timer.hour = timer.hour & 0xf0;
            }
            DS3231_SetTime(&timer);
            t_add = 0;
        }
        LCD_DrawImage1BPP(x + 28, y, BMP_SMSZ[dtimer.hour & 0x0f], WHITE, GRAY);    
    }
    else LCD_DrawImage1BPP(x + 28, y, BMP_SMSZ[dtimer.hour & 0x0f], WHITE, BLACK);  
    
    if(color_back && (t==2)){
        if (t_add) {//分钟设置，十位
            timer.minute = timer.minute + 0x10;
            if ((timer.minute >> 4) > 5) {
                timer.minute = timer.minute & 0x0f;
            }
            DS3231_SetTime(&timer);
            t_add = 0;
        }
    LCD_DrawImage1BPP(x + 28 * 3, y, BMP_SMSZ[(dtimer.minute >> 4)&0x0f], WHITE, GRAY);
    }
    else LCD_DrawImage1BPP(x + 28 * 3, y, BMP_SMSZ[(dtimer.minute >> 4)&0x0f], WHITE, BLACK);
        
    if(color_back && (t==3)){    
        if (t_add) {//分钟设置，个位
            timer.minute = timer.minute + 0x01;
            if ((timer.minute & 0x0f) > 9) {
                timer.minute = timer.minute & 0xf0;
            }
            DS3231_SetTime(&timer);
            t_add = 0;
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
            LCD_DrawImage1BPP(x+260 + 16 * 2, y, BMP_SZ_1[(dtimer.year >> 4)&0x0f], WHITE, GRAY);
        } else LCD_DrawImage1BPP(x+260 + 16 * 2, y, BMP_SZ_1[(dtimer.year >> 4)&0x0f], WHITE, BLACK);

        if (color_back && (t == 5)) {
            if (t_add) {//年设置，个位
                timer.year = timer.year + 0x01;
                if ((timer.year & 0x0f) > 9) {
                    timer.year = timer.year & 0xf0;
                }
                DS3231_SetTime(&timer);
                t_add = 0;
            }
            LCD_DrawImage1BPP(x +260+ 16 * 3, y, BMP_SZ_1[dtimer.year & 0x0f], WHITE, GRAY);
        } else LCD_DrawImage1BPP(x +260+ 16 * 3, y, BMP_SZ_1[dtimer.year & 0x0f], WHITE, BLACK);
      
        LCD_DrawImage1BPP(x +260+ 16 * 4, y, BMP_SZ_1[17], WHITE, BLACK); //-

        if (color_back && (t == 6)) {
            if (t_add) {//月设置，十位
                timer.month = timer.month + 0x10;
                if ((timer.month >> 4) > 1) {
                    timer.month = timer.month & 0x0f;
                }
                DS3231_SetTime(&timer);
                t_add = 0;
            }
            LCD_DrawImage1BPP(x+260 + 16 * 5, y, BMP_SZ_1[(dtimer.month >> 4)&0x0f], WHITE, GRAY);
        } else LCD_DrawImage1BPP(x+260 + 16 * 5, y, BMP_SZ_1[(dtimer.month >> 4)&0x0f], WHITE, BLACK);
        
        if (color_back && (t == 7)) {
            if (t_add) {//月设置，个位
                timer.month = timer.month + 0x01;
                if ((timer.month & 0x0f) > 9) {
                    timer.month = timer.month & 0xf0;
                }
                DS3231_SetTime(&timer);
                t_add = 0;
            }
            LCD_DrawImage1BPP(x +260+ 16 * 6, y, BMP_SZ_1[dtimer.month & 0x0f], WHITE, GRAY);
        } else LCD_DrawImage1BPP(x+260 + 16 * 6, y, BMP_SZ_1[dtimer.month & 0x0f], WHITE, BLACK);
       
        LCD_DrawImage1BPP(x+260 + 16 * 7, y, BMP_SZ_1[17], WHITE, BLACK); //-
        
        if (color_back && (t == 8)) {
            if (t_add) {//日设置，十位
                timer.day = timer.day + 0x10;
                if ((timer.day >> 4) > 3) {
                    timer.day = timer.day & 0x0f;
                }
                DS3231_SetTime(&timer);
                t_add = 0;
            }
            LCD_DrawImage1BPP(x+260 + 16 * 8, y, BMP_SZ_1[(dtimer.day >> 4)&0x0f], WHITE, GRAY);
        } else LCD_DrawImage1BPP(x +260+ 16 * 8, y, BMP_SZ_1[(dtimer.day >> 4)&0x0f], WHITE, BLACK);

        if (color_back && (t == 9)) {
            if (t_add) {//日设置，个位
                timer.day = timer.day + 0x01;
                if ((timer.day & 0x0f) > 9) {
                    timer.day = timer.day & 0xf0;
                }
                DS3231_SetTime(&timer);
                t_add = 0;
            }
            LCD_DrawImage1BPP(x +260+ 16 * 9, y, BMP_SZ_1[dtimer.day & 0x0f], WHITE, GRAY);
        } else LCD_DrawImage1BPP(x+260 + 16 * 9, y, BMP_SZ_1[dtimer.day & 0x0f], WHITE, BLACK);

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

    if (IN36) color = YELLOW;
    else color = GRAY;
    if (color_old[0] != color) {
        color_old[0] = color;
        LCD_DrawImage1BPP(10, 5, Bmp_baojing[0], color, BLACK); //ASR
    }

    if (IN37) color = YELLOW;
    else color = GRAY;
    if (color_old[1] != color) {
        color_old[1] = color;
        LCD_DrawImage1BPP(10 + 66, 5, Bmp_baojing[1], color, BLACK); //ABS
    }

    if (!fKL4) color = RED;
    else color = GRAY;
    if (color_old[2] != color) {
        color_old[2] = color;
        LCD_DrawImage1BPP(10 + 66 * 2, 5, Bmp_baojing[2], color, BLACK); //左前蹄片
    }

    if (!fKL5) color = RED;
    else color = GRAY;
    if (color_old[3] != color) {
        color_old[3] = color;
        LCD_DrawImage1BPP(10 + 66 * 3, 5, Bmp_baojing[3], color, BLACK); //右前蹄片
    }

    if (mKH1) color = RED;
    else color = GRAY;
    if (color_old[4] != color) {
        color_old[4] = color;
        LCD_DrawImage1BPP(10 + 66 * 4, 5, Bmp_baojing[4], color, BLACK); //后舱门
    }

    if (!fKL1) color = RED;
    else color = GRAY;
    if (color_old[5] != color) {
        color_old[5] = color;
        LCD_DrawImage1BPP(10 + 66 * 5, 5, Bmp_baojing[5], color, BLACK); //左后蹄片

    }

    if (!fKL3) color = RED;
    else color = GRAY;
    if (color_old[6] != color) {
        color_old[6] = color;
        LCD_DrawImage1BPP(10 + 66 * 6, 5, Bmp_baojing[6], color, BLACK); //右后蹄片
    }

    if (mKL2) color = RED;
    else color = GRAY;
    if (color_old[7] != color) {
        color_old[7] = color;
        LCD_DrawImage1BPP(10 + 66 * 7, 5, Bmp_baojing[7], color, BLACK); //门铃
    }

    if (mKL4) color = RED;
    else color = GRAY;
    if (color_old[8] != color) {
        color_old[8] = color;
        LCD_DrawImage1BPP(10 + 66 * 8, 5, Bmp_baojing[8], color, BLACK); //前门应急阀
    }

    if (mKL6) color = RED;
    else color = GRAY;
    if (color_old[9] != color) {
        color_old[9] = color;
        LCD_DrawImage1BPP(10 + 66 * 9, 5, Bmp_baojing[9], color, BLACK); //中门应急阀
    }

    if (IN30)
        color = RED;
    else color = GRAY;
    if (color_old[10] != color) {
        color_old[10] = color;
        LCD_DrawImage1BPP(10 + 66 * 10, 5, Bmp_baojing[10], color, BLACK); //安全带
    }

    if ((DMC_Status==3) && (DMC_Level==0)) color = RED;
    else color = GRAY;
    if (color_old[15] != color) {
        color_old[15] = color;
        LCD_DrawImage1BPP(10 + 66 * 11, 5, Bmp_baojing[11], color, BLACK); //整车故障
    }

    /*if (mKL4) color = RED;
    else color = GRAY;
    if (color_old[16] != color) {
        color_old[16] = color;
        //LCD_DrawImage1BPP(142 + 66 * 2, 74 - 10, Bmp_baojing[11], color, BLACK); //中门应急阀
    }*/

    if (DMC_Status == 0) color = GREEN;
    else color = GRAY;
    if (color_old[17] != color) {
        color_old[17] = color;
        LCD_DrawImage1BPP(138 + 66 * 3 - 1, 74 + 12 - 5, Bmp_READY, color, BLACK); //ready
    }

    /*if (rKL5) color = RED;
    else color = GRAY;
    if (color_old[18] != color) {
        color_old[18] = color;
        //LCD_DrawImage1BPP(142 + 66 * 4, 74 - 10, Bmp_baojing[12], color, BLACK); //中门1应急阀
    }

    if (mKL6) color = RED;
    else color = GRAY;
    if (color_old[19] != color) {
        color_old[19] = color;
        //LCD_DrawImage1BPP(142 + 66 * 5, 74 - 10, Bmp_baojing[13], color, BLACK); //中门2应急阀
    }

    if (!fKL5) color = RED;
    else color = GRAY;
    if (color_old[20] != color) {
        color_old[20] = color;
        //LCD_DrawImage1BPP(142 + 66 * 6, 74-10, Bmp_baojing[20], color, BLACK); //右刹车片磨损
    }*/
}

void disp_CAN_baojing(unsigned int x, unsigned int y) {
    static unsigned char al_index = 0;
    if (alarm_update_flag == 0) { //3S 更新一次 
        //LCD_DrawRect(x, y, 350 + 85 + 10, 36, BLACK); //清除显示区域
        switch (al_index) {
            case 0:
                al_index = 1;
                if (DMC_Protect_code == 1) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Loudian, YELLOW, BLACK); //漏电保护
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Baohu, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 1:
                al_index = 2;
                if (DMC_Protect_code == 2) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Duzhuan, YELLOW, BLACK); //堵转保护
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Baohu, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
            case 2:
                al_index = 3;
                if (DMC_Protect_code == 3) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Zijian, YELLOW, BLACK); //自检保护
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Baohu, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 3:
                al_index = 4;
                if (DMC_Protect_code == 4) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DJ, YELLOW, BLACK); //电机线束故障
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Xianshu, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 4:
                al_index = 5;
                if (DMC_Protect_code == 5) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_i, YELLOW, BLACK); //IPM故障
                    LCD_DrawImage1BPP(x + 11, y + 8, BMP_p, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11, y + 8, BMP_m, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11 + 11, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 11 + 11 + 11 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 5:
                al_index = 6;
                if (DMC_Protect_code == 6) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Zhu, YELLOW, BLACK); //主继电器故障
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_Jidianqi, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 63, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 21 + 63 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
            case 6:
                al_index = 7;
                if (DMC_Protect_code == 7) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Yuchong, YELLOW, BLACK); //预充继电器故障
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Jidianqi, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 63, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 63 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
            case 7:
                al_index = 8;
                if (DMC_Protect_code == 8) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Ruanjian, YELLOW, BLACK); //软件故障
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
            case 8:
                al_index = 9;
                if (DMC_Speed * 0.5 > 69) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Chaosu, YELLOW, BLACK); //超速报警
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
            case 9:
                al_index = 10;
                if (DMC_Protect_code == 51) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DJ, YELLOW, BLACK); //电机过温故障
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 21, y + 8, BMP_Wendu, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
            case 10:
                al_index = 11;
                if (DMC_Protect_code == 52) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Mokuai, YELLOW, BLACK); //模块过温故障
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 21, y + 8, BMP_Wendu, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
            case 11:
                al_index = 12;
                if (DMC_Protect_code == 53) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DJ, YELLOW, BLACK); //电机超速故障
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Chaosu, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 12:
                al_index = 13;
                if (DMC_Protect_code == 54) {
                    print_SZ(x, y + 12, 24, 2, 0, YELLOW);
                    LCD_DrawImage1BPP(x + 16, y + 8, BMP_v, YELLOW, BLACK); //24V欠压故障
                    LCD_DrawImage1BPP(x + 16 + 11, y + 8, BMP_Qian, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 16 + 11, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 16 + 11 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 16 + 11 + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 13:
                al_index = 14;
                if (DMC_Protect_code == 55) {
                    print_SZ(x, y + 12, 24, 2, 0, YELLOW);
                    LCD_DrawImage1BPP(x + 16, y + 8, BMP_v, YELLOW, BLACK); //24V过压故障                    
                    LCD_DrawImage1BPP(x + 16 + 11, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 16 + 11, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 16 + 11 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 16 + 11 + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 14:
                al_index = 15;
                if (DMC_Protect_code == 56) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_c, YELLOW, BLACK); //CAN通讯故障
                    LCD_DrawImage1BPP(x + 11, y + 8, BMP_a, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11, y + 8, BMP_n, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11 + 11, y + 8, BMP_Tongxun, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11 + 11 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 11 + 11 + 11 + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 15:
                al_index = 16;
                if (DMC_Protect_code == 57) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DL, YELLOW, BLACK); //过流故障
                    LCD_DrawImage1BPP(x, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 16:
                al_index = 17;
                if (DMC_Protect_code == 58) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Guo, YELLOW, BLACK); //过载故障  
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_Zai, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 17:
                al_index = 18;
                if (DMC_Protect_code == 59) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DY, YELLOW, BLACK); //欠压故障
                    LCD_DrawImage1BPP(x, y + 8, BMP_Qian, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 18:
                al_index = 19;
                if (DMC_Protect_code == 60) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DY, YELLOW, BLACK); //过压故障
                    LCD_DrawImage1BPP(x, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 19:
                al_index = 20;
                if (DMC_Protect_code == 61) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Xiangweijiao, YELLOW, BLACK); //相位角故障
                    LCD_DrawImage1BPP(x + 63, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 63 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 20:
                al_index = 21;
                if (DMC_Protect_code == 62) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Yingjian, YELLOW, BLACK); //硬件母线过流故障
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Muxian, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_DL, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 21:
                al_index = 22;
                if (DMC_Protect_code == 65) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Yingjian, YELLOW, BLACK); //硬件母线过压故障
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Muxian, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 22:
                al_index = 23;
                if (DMC_Protect_code == 66) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Yingjian, YELLOW, BLACK); //硬件母线过流故障
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Muxian, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_DL, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 23:
                al_index = 24;
                if (DMC_Protect_code == 101) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Muxian, YELLOW, BLACK); //母线过压报警
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 24:
                al_index = 25;
                if (DMC_Protect_code == 102) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Muxian, YELLOW, BLACK); //母线过压报警
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Qian, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 25:
                al_index = 26;
                if (DMC_Protect_code == 151) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DJ, YELLOW, BLACK); //电机过温报警                   
                    LCD_DrawImage1BPP(x + 42 + 21, y + 8, BMP_Wendu, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 26:
                al_index = 27;
                if (DMC_Protect_code == 152) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Mokuai, YELLOW, BLACK); //模块过温报警                   
                    LCD_DrawImage1BPP(x + 42 + 21, y + 8, BMP_Wendu, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 27:
                al_index = 28;
                if (((BMS_Status_Flag1 & 0x03) == 1) || ((BMS_Status_Flag1 & 0x03) == 2)) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Dan, YELLOW, BLACK); //单体电压过低
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_Ti, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 21, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 21, y + 8, BMP_Di, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 28:
                al_index = 29;
                if ((((BMS_Status_Flag1 >> 2) & 0x03) == 1) || (((BMS_Status_Flag1 >> 2) & 0x03) == 2)) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Dan, YELLOW, BLACK); //单体电压过高
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_Ti, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 21, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 21, y + 8, BMP_Gao, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 29:
                al_index = 30;
                if ((((BMS_Status_Flag1 >> 4) & 0x03) == 1) || (((BMS_Status_Flag1 >> 4) & 0x03) == 2)) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Wendu, YELLOW, BLACK); //温度过低
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 21, y + 8, BMP_Di, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 30:
                al_index = 31;
                if ((((BMS_Status_Flag1 >> 6) & 0x03) == 1) || (((BMS_Status_Flag1 >> 6) & 0x03) == 2)) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Wendu, YELLOW, BLACK); //温度过高
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 21, y + 8, BMP_Gao, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 31:
                al_index = 32;
                if (((BMS_Status_Flag2 & 0x03) == 1) || ((BMS_Status_Flag2 & 0x03) == 2)) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_s, YELLOW, BLACK); //SOC过低
                    LCD_DrawImage1BPP(x + 11, y + 8, BMP_o, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11, y + 8, BMP_c, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + +11 + 11 + 11, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11 + 11 + 21, y + 8, BMP_Di, YELLOW, BLACK);
                    LCD_DrawRect(x + 11 + 11 + 11 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 32:
                al_index = 33;
                if ((((BMS_Status_Flag2 >> 2) & 0x03) == 1) || (((BMS_Status_Flag2 >> 2) & 0x03) == 2)) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DL, YELLOW, BLACK); //电流过高
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 21, y + 8, BMP_Da, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 33:
                al_index = 34;
                if ((((BMS_Status_Flag2 >> 4) & 0x03) == 1) || (((BMS_Status_Flag2 >> 4) & 0x03) == 2)) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Jueyuan, YELLOW, BLACK); //绝缘报警
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 34:
                al_index = 35;
                if ((((BMS_Status_Flag2 >> 6) & 0x03) == 1) || (((BMS_Status_Flag2 >> 6) & 0x03) == 2)) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DC, YELLOW, BLACK); //电池均衡故障
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Junheng, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 35:
                al_index = 36;
                if (((BMS_Status_Flag3 >> 1) & 0x01) == 1) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Chongdian, YELLOW, BLACK); //充电通讯异常
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Tongxun, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Yichang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 36:
                al_index = 37;
                if (((BMS_Status_Flag3 >> 5) & 0x01) == 1) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Chongdian, YELLOW, BLACK); //充电机停止失效，立即手动停止充电
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_DJ, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 63, y + 8, BMP_Tingzhi, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 63 + 42, y + 8, BMP_Shixiao, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 63 + 42 + 42, y + 8, BMP_Liji, YELLOW, BLACK);
                    //LCD_DrawRect(x + 63 + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 37:
                al_index = 38;
                if (((BMS_Status_Flag3 >> 6) & 0x01) == 1) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Chongdian, YELLOW, BLACK); //充电接触器失效，立即手动停止充电
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Jiechuqi, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 63, y + 8, BMP_Shixiao, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 63 + 42, y + 8, BMP_Liji, YELLOW, BLACK);
                    //LCD_DrawRect(x + 42 + 63 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 38:
                al_index = 39;
                if (BMS_Unit_Number >= 1) {
                    if ((BMU_Comm_Status1 & 0x01) == 1) {
                        LCD_DrawRect(x + 21, y + 8, 16, 20, BLACK);
                        LCD_DrawImage1BPP(x, y + 8, BMP_Dijige, YELLOW, BLACK); //第1号连接故障
                        print_SZ(x + 21, y + 12, 2, 2, 0, YELLOW);
                        LCD_DrawImage1BPP(x + 21 + 16, y + 8, BMP_Hao, YELLOW, BLACK);
                        LCD_DrawImage1BPP(x + 21 + 16 + 21, y + 8, BMP_Lianjie, YELLOW, BLACK);
                        LCD_DrawImage1BPP(x + 21 + 16 + 21 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                        LCD_DrawRect(x + 21 + 16 + 21 + 42 + 42, y, 200, 36, BLACK);
                        alarm_update_flag = 1;
                        break;
                    }
                }

            case 39:
                al_index = 40;
                if (BMS_Unit_Number >= 2) {
                    if (((BMU_Comm_Status1 >> 1) & 0x01) == 1) {
                        LCD_DrawRect(x + 21, y + 8, 16, 20, BLACK);
                        LCD_DrawImage1BPP(x, y + 8, BMP_Dijige, YELLOW, BLACK); //第2号连接故障
                        print_SZ(x + 21, y + 12, 2, 2, 0, YELLOW);
                        LCD_DrawImage1BPP(x + 21 + 16, y + 8, BMP_Hao, YELLOW, BLACK);
                        LCD_DrawImage1BPP(x + 21 + 16 + 21, y + 8, BMP_Lianjie, YELLOW, BLACK);
                        LCD_DrawImage1BPP(x + 21 + 16 + 21 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                        LCD_DrawRect(x + 21 + 16 + 21 + 42 + 42, y, 200, 36, BLACK);
                        alarm_update_flag = 1;
                        break;
                    }
                }

            case 40:
                al_index = 41;
                if (BMS_Unit_Number >= 3) {
                    if (((BMU_Comm_Status1 >> 2) & 0x01) == 1) {
                        LCD_DrawRect(x + 21, y + 8, 16, 20, BLACK);
                        LCD_DrawImage1BPP(x, y + 8, BMP_Dijige, YELLOW, BLACK); //第3号连接故障
                        print_SZ(x + 21, y + 12, 3, 2, 0, YELLOW);
                        LCD_DrawImage1BPP(x + 21 + 16, y + 8, BMP_Hao, YELLOW, BLACK);
                        LCD_DrawImage1BPP(x + 21 + 16 + 21, y + 8, BMP_Lianjie, YELLOW, BLACK);
                        LCD_DrawImage1BPP(x + 21 + 16 + 21 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                        LCD_DrawRect(x + 21 + 16 + 21 + 42 + 42, y, 200, 36, BLACK);
                        alarm_update_flag = 1;
                        break;
                    }
                }

            case 41:
                al_index = 42;
                if (BMS_Unit_Number >= 4) {
                    if (((BMU_Comm_Status1 >> 3) & 0x01) == 1) {
                        LCD_DrawRect(x + 21, y + 8, 16, 20, BLACK);
                        LCD_DrawImage1BPP(x, y + 8, BMP_Dijige, YELLOW, BLACK); //第4号连接故障
                        print_SZ(x + 21, y + 12, 4, 2, 0, YELLOW);
                        LCD_DrawImage1BPP(x + 21 + 16, y + 8, BMP_Hao, YELLOW, BLACK);
                        LCD_DrawImage1BPP(x + 21 + 16 + 21, y + 8, BMP_Lianjie, YELLOW, BLACK);
                        LCD_DrawImage1BPP(x + 21 + 16 + 21 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                        LCD_DrawRect(x + 21 + 16 + 21 + 42 + 42, y, 200, 36, BLACK);
                        alarm_update_flag = 1;
                        break;
                    }
                }

            case 42:
                al_index = 43;
                if (BMS_Unit_Number >= 5) {
                    if (((BMU_Comm_Status1 >> 4) & 0x01) == 1) {
                        LCD_DrawRect(x + 21, y + 8, 16, 20, BLACK);
                        LCD_DrawImage1BPP(x, y + 8, BMP_Dijige, YELLOW, BLACK); //第5号连接故障
                        print_SZ(x + 21, y + 12, 5, 2, 0, YELLOW);
                        LCD_DrawImage1BPP(x + 21 + 16, y + 8, BMP_Hao, YELLOW, BLACK);
                        LCD_DrawImage1BPP(x + 21 + 16 + 21, y + 8, BMP_Lianjie, YELLOW, BLACK);
                        LCD_DrawImage1BPP(x + 21 + 16 + 21 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                        LCD_DrawRect(x + 21 + 16 + 21 + 42 + 42, y, 200, 36, BLACK);
                        alarm_update_flag = 1;
                        break;
                    }
                }

            case 43:
                al_index = 44;
                if (BMS_Unit_Number >= 6) {
                    if (((BMU_Comm_Status1 >> 5) & 0x01) == 1) {
                        LCD_DrawRect(x + 21, y + 8, 16, 20, BLACK);
                        LCD_DrawImage1BPP(x, y + 8, BMP_Dijige, YELLOW, BLACK); //第6号连接故障
                        print_SZ(x + 21, y + 12, 6, 2, 0, YELLOW);
                        LCD_DrawImage1BPP(x + 21 + 16, y + 8, BMP_Hao, YELLOW, BLACK);
                        LCD_DrawImage1BPP(x + 21 + 16 + 21, y + 8, BMP_Lianjie, YELLOW, BLACK);
                        LCD_DrawImage1BPP(x + 21 + 16 + 21 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                        LCD_DrawRect(x + 21 + 16 + 21 + 42 + 42, y, 200, 36, BLACK);
                        alarm_update_flag = 1;
                        break;
                    }
                }

            case 44:
                al_index = 45;
                if (BMS_Unit_Number >= 7) {
                    if (((BMU_Comm_Status1 >> 6) & 0x01) == 1) {
                        LCD_DrawRect(x + 21, y + 8, 16, 20, BLACK);
                        LCD_DrawImage1BPP(x, y + 8, BMP_Dijige, YELLOW, BLACK); //第7号连接故障
                        print_SZ(x + 21, y + 12, 7, 2, 0, YELLOW);
                        LCD_DrawImage1BPP(x + 21 + 16, y + 8, BMP_Hao, YELLOW, BLACK);
                        LCD_DrawImage1BPP(x + 21 + 16 + 21, y + 8, BMP_Lianjie, YELLOW, BLACK);
                        LCD_DrawImage1BPP(x + 21 + 16 + 21 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                        LCD_DrawRect(x + 21 + 16 + 21 + 42 + 42, y, 200, 36, BLACK);
                        alarm_update_flag = 1;
                        break;
                    }
                }

            case 45:
                al_index = 46;
                if (BMS_Unit_Number >= 8) {
                    if (((BMU_Comm_Status1 >> 7) & 0x01) == 1) {
                        LCD_DrawRect(x + 21, y + 8, 16, 20, BLACK);
                        LCD_DrawImage1BPP(x, y + 8, BMP_Dijige, YELLOW, BLACK); //第8号连接故障
                        print_SZ(x + 21, y + 12, 8, 2, 0, YELLOW);
                        LCD_DrawImage1BPP(x + 21 + 16, y + 8, BMP_Hao, YELLOW, BLACK);
                        LCD_DrawImage1BPP(x + 21 + 16 + 21, y + 8, BMP_Lianjie, YELLOW, BLACK);
                        LCD_DrawImage1BPP(x + 21 + 16 + 21 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                        LCD_DrawRect(x + 21 + 16 + 21 + 42 + 42, y, 200, 36, BLACK);
                        alarm_update_flag = 1;
                        break;
                    }
                }

            case 46:
                al_index = 47;
                if (BMS_Unit_Number >= 9) {
                    if ((BMU_Comm_Status2 & 0x01) == 1) {
                        LCD_DrawRect(x + 21, y + 8, 16, 20, BLACK);
                        LCD_DrawImage1BPP(x, y + 8, BMP_Dijige, YELLOW, BLACK); //第9号连接故障
                        LCD_DrawRect(x, y + 8, 16, 20, BLACK);
                        print_SZ(x + 21, y + 12, 9, 2, 0, YELLOW);
                        LCD_DrawImage1BPP(x + 21 + 16, y + 8, BMP_Hao, YELLOW, BLACK);
                        LCD_DrawImage1BPP(x + 21 + 16 + 21, y + 8, BMP_Lianjie, YELLOW, BLACK);
                        LCD_DrawImage1BPP(x + 21 + 16 + 21 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                        LCD_DrawRect(x + 21 + 16 + 21 + 42 + 42, y, 200, 36, BLACK);
                        alarm_update_flag = 1;
                        break;
                    }
                }

            case 47:
                al_index = 48;
                if (BMS_Unit_Number >= 10) {
                    if (((BMU_Comm_Status2 >> 1) & 0x01) == 1) {
                        LCD_DrawRect(x + 21, y + 8, 16, 20, BLACK);
                        LCD_DrawImage1BPP(x, y + 8, BMP_Dijige, YELLOW, BLACK); //第10号连接故障
                        print_SZ(x + 21, y + 12, 10, 2, 0, YELLOW);
                        LCD_DrawImage1BPP(x + 21 + 16, y + 8, BMP_Hao, YELLOW, BLACK);
                        LCD_DrawImage1BPP(x + 21 + 16 + 21, y + 8, BMP_Lianjie, YELLOW, BLACK);
                        LCD_DrawImage1BPP(x + 21 + 16 + 21 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                        LCD_DrawRect(x + 21 + 16 + 21 + 42 + 42, y, 200, 36, BLACK);
                        alarm_update_flag = 1;
                        break;
                    }
                }

            case 48:
                al_index = 49;
                if (BMS_Unit_Number >= 11) {
                    if (((BMU_Comm_Status2 >> 2) & 0x01) == 1) {
                        LCD_DrawRect(x + 21, y + 8, 16, 20, BLACK);
                        LCD_DrawImage1BPP(x, y + 8, BMP_Dijige, YELLOW, BLACK); //第11号连接故障
                        print_SZ(x + 21, y + 12, 11, 2, 0, YELLOW);
                        LCD_DrawImage1BPP(x + 21 + 16, y + 8, BMP_Hao, YELLOW, BLACK);
                        LCD_DrawImage1BPP(x + 21 + 16 + 21, y + 8, BMP_Lianjie, YELLOW, BLACK);
                        LCD_DrawImage1BPP(x + 21 + 16 + 21 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                        LCD_DrawRect(x + 21 + 16 + 21 + 42 + 42, y, 200, 36, BLACK);
                        alarm_update_flag = 1;
                        break;
                    }
                }

            case 49:
                al_index = 50;
                if (BMS_Unit_Number >= 12) {
                    if (((BMU_Comm_Status2 >> 3) & 0x01) == 1) {
                        LCD_DrawRect(x + 21, y + 8, 16, 20, BLACK);
                        LCD_DrawImage1BPP(x, y + 8, BMP_Dijige, YELLOW, BLACK); //第12号连接故障
                        print_SZ(x + 21, y + 12, 12, 2, 0, YELLOW);
                        LCD_DrawImage1BPP(x + 21 + 16, y + 8, BMP_Hao, YELLOW, BLACK);
                        LCD_DrawImage1BPP(x + 21 + 16 + 21, y + 8, BMP_Lianjie, YELLOW, BLACK);
                        LCD_DrawImage1BPP(x + 21 + 16 + 21 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                        LCD_DrawRect(x + 21 + 16 + 21 + 42 + 42, y, 200, 36, BLACK);
                        alarm_update_flag = 1;
                        break;
                    }
                }

            case 50:
                al_index = 51;
                if (BMS_Unit_Number >= 13) {
                    if (((BMU_Comm_Status2 >> 4) & 0x01) == 1) {
                        LCD_DrawRect(x + 21, y + 8, 16, 20, BLACK);
                        LCD_DrawImage1BPP(x, y + 8, BMP_Dijige, YELLOW, BLACK); //第13号连接故障
                        print_SZ(x + 21, y + 12, 13, 2, 0, YELLOW);
                        LCD_DrawImage1BPP(x + 21 + 16, y + 8, BMP_Hao, YELLOW, BLACK);
                        LCD_DrawImage1BPP(x + 21 + 16 + 21, y + 8, BMP_Lianjie, YELLOW, BLACK);
                        LCD_DrawImage1BPP(x + 21 + 16 + 21 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                        LCD_DrawRect(x + 21 + 16 + 21 + 42 + 42, y, 200, 36, BLACK);
                        alarm_update_flag = 1;
                        break;
                    }
                }

            case 51:
                al_index = 52;
                if (BMS_Unit_Number >= 14) {
                    if (((BMU_Comm_Status2 >> 5) & 0x01) == 1) {
                        LCD_DrawRect(x + 21, y + 8, 16, 20, BLACK);
                        LCD_DrawImage1BPP(x, y + 8, BMP_Dijige, YELLOW, BLACK); //第14号连接故障
                        print_SZ(x + 21, y + 12, 14, 2, 0, YELLOW);
                        LCD_DrawImage1BPP(x + 21 + 16, y + 8, BMP_Hao, YELLOW, BLACK);
                        LCD_DrawImage1BPP(x + 21 + 16 + 21, y + 8, BMP_Lianjie, YELLOW, BLACK);
                        LCD_DrawImage1BPP(x + 21 + 16 + 21 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                        LCD_DrawRect(x + 21 + 16 + 21 + 42 + 42, y, 200, 36, BLACK);
                        alarm_update_flag = 1;
                        break;
                    }
                }

            case 52:
                al_index = 53;
                if (BMS_Unit_Number >= 15) {
                    if (((BMU_Comm_Status2 >> 6) & 0x01) == 1) {
                        LCD_DrawRect(x + 21, y + 8, 16, 20, BLACK);
                        LCD_DrawImage1BPP(x, y + 8, BMP_Dijige, YELLOW, BLACK); //第15号连接故障
                        print_SZ(x + 21, y + 12, 15, 2, 0, YELLOW);
                        LCD_DrawImage1BPP(x + 21 + 16, y + 8, BMP_Hao, YELLOW, BLACK);
                        LCD_DrawImage1BPP(x + 21 + 16 + 21, y + 8, BMP_Lianjie, YELLOW, BLACK);
                        LCD_DrawImage1BPP(x + 21 + 16 + 21 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                        LCD_DrawRect(x + 21 + 16 + 21 + 42 + 42, y, 200, 36, BLACK);
                        alarm_update_flag = 1;
                        break;
                    }
                }

            case 53:
                al_index = 54;
                if (BMS_Unit_Number >= 16) {
                    if (((BMU_Comm_Status2 >> 7) & 0x01) == 1) {
                        LCD_DrawRect(x + 21, y + 8, 16, 20, BLACK);
                        LCD_DrawImage1BPP(x, y + 8, BMP_Dijige, YELLOW, BLACK); //第16号连接故障
                        print_SZ(x + 21, y + 12, 16, 2, 0, YELLOW);
                        LCD_DrawImage1BPP(x + 21 + 16, y + 8, BMP_Hao, YELLOW, BLACK);
                        LCD_DrawImage1BPP(x + 21 + 16 + 21, y + 8, BMP_Lianjie, YELLOW, BLACK);
                        LCD_DrawImage1BPP(x + 21 + 16 + 21 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                        LCD_DrawRect(x + 21 + 16 + 21 + 42 + 42, y, 200, 36, BLACK);
                        alarm_update_flag = 1;
                        break;
                    }
                }

            case 54:
                al_index = 55;
                if (BMS_Unit_Number >= 17) {
                    if ((BMU_Comm_Status3 & 0x01) == 1) {
                        LCD_DrawRect(x + 21, y + 8, 16, 20, BLACK);
                        LCD_DrawImage1BPP(x, y + 8, BMP_Dijige, YELLOW, BLACK); //第17号连接故障
                        print_SZ(x + 21, y + 12, 17, 2, 0, YELLOW);
                        LCD_DrawImage1BPP(x + 21 + 16, y + 8, BMP_Hao, YELLOW, BLACK);
                        LCD_DrawImage1BPP(x + 21 + 16 + 21, y + 8, BMP_Lianjie, YELLOW, BLACK);
                        LCD_DrawImage1BPP(x + 21 + 16 + 21 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                        LCD_DrawRect(x + 21 + 16 + 21 + 42 + 42, y, 200, 36, BLACK);
                        alarm_update_flag = 1;
                        break;
                    }
                }

            case 55:
                al_index = 56;
                if (BMS_Unit_Number >= 18) {
                    if (((BMU_Comm_Status3 >> 1) & 0x01) == 1) {
                        LCD_DrawRect(x + 21, y + 8, 16, 20, BLACK);
                        LCD_DrawImage1BPP(x, y + 8, BMP_Dijige, YELLOW, BLACK); //第18号连接故障
                        print_SZ(x + 21, y + 12, 18, 2, 0, YELLOW);
                        LCD_DrawImage1BPP(x + 21 + 16, y + 8, BMP_Hao, YELLOW, BLACK);
                        LCD_DrawImage1BPP(x + 21 + 16 + 21, y + 8, BMP_Lianjie, YELLOW, BLACK);
                        LCD_DrawImage1BPP(x + 21 + 16 + 21 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                        LCD_DrawRect(x + 21 + 16 + 21 + 42 + 42, y, 200, 36, BLACK);
                        alarm_update_flag = 1;
                        break;
                    }
                }

            case 56:
                al_index = 57;
                if (BMS_Unit_Number >= 19) {
                    if (((BMU_Comm_Status3 >> 2) & 0x01) == 1) {
                        LCD_DrawRect(x + 21, y + 8, 16, 20, BLACK);
                        LCD_DrawImage1BPP(x, y + 8, BMP_Dijige, YELLOW, BLACK); //第19号连接故障
                        print_SZ(x + 21, y + 12, 19, 2, 0, YELLOW);
                        LCD_DrawImage1BPP(x + 21 + 16, y + 8, BMP_Hao, YELLOW, BLACK);
                        LCD_DrawImage1BPP(x + 21 + 16 + 21, y + 8, BMP_Lianjie, YELLOW, BLACK);
                        LCD_DrawImage1BPP(x + 21 + 16 + 21 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                        LCD_DrawRect(x + 21 + 16 + 21 + 42 + 42, y, 200, 36, BLACK);
                        alarm_update_flag = 1;
                        break;
                    }
                }

            case 57:
                al_index = 58;
                if (BMS_Unit_Number >= 20) {
                    if (((BMU_Comm_Status3 >> 3) & 0x01) == 1) {
                        LCD_DrawRect(x + 21, y + 8, 16, 20, BLACK);
                        LCD_DrawImage1BPP(x, y + 8, BMP_Dijige, YELLOW, BLACK); //第20号连接故障
                        print_SZ(x + 21, y + 12, 20, 2, 0, YELLOW);
                        LCD_DrawImage1BPP(x + 21 + 16, y + 8, BMP_Hao, YELLOW, BLACK);
                        LCD_DrawImage1BPP(x + 21 + 16 + 21, y + 8, BMP_Lianjie, YELLOW, BLACK);
                        LCD_DrawImage1BPP(x + 21 + 16 + 21 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                        LCD_DrawRect(x + 21 + 16 + 21 + 42 + 42, y, 200, 36, BLACK);
                        alarm_update_flag = 1;
                        break;
                    }
                }

            case 58:
                al_index = 59;
                if (BMS_Unit_Number >= 21) {
                    if (((BMU_Comm_Status3 >> 4) & 0x01) == 1) {
                        LCD_DrawRect(x + 21, y + 8, 16, 20, BLACK);
                        LCD_DrawImage1BPP(x, y + 8, BMP_Dijige, YELLOW, BLACK); //第21号连接故障
                        print_SZ(x + 21, y + 12, 21, 2, 0, YELLOW);
                        LCD_DrawImage1BPP(x + 21 + 16, y + 8, BMP_Hao, YELLOW, BLACK);
                        LCD_DrawImage1BPP(x + 21 + 16 + 21, y + 8, BMP_Lianjie, YELLOW, BLACK);
                        LCD_DrawImage1BPP(x + 21 + 16 + 21 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                        LCD_DrawRect(x + 21 + 16 + 21 + 42 + 42, y, 200, 36, BLACK);
                        alarm_update_flag = 1;
                        break;
                    }
                }

            case 59:
                al_index = 60;
                if (BMS_Unit_Number >= 22) {
                    if (((BMU_Comm_Status3 >> 5) & 0x01) == 1) {
                        LCD_DrawRect(x + 21, y + 8, 16, 20, BLACK);
                        LCD_DrawImage1BPP(x, y + 8, BMP_Dijige, YELLOW, BLACK); //第22号连接故障
                        print_SZ(x + 21, y + 12, 22, 2, 0, YELLOW);
                        LCD_DrawImage1BPP(x + 21 + 16, y + 8, BMP_Hao, YELLOW, BLACK);
                        LCD_DrawImage1BPP(x + 21 + 16 + 21, y + 8, BMP_Lianjie, YELLOW, BLACK);
                        LCD_DrawImage1BPP(x + 21 + 16 + 21 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                        LCD_DrawRect(x + 21 + 16 + 21 + 42 + 42, y, 200, 36, BLACK);
                        alarm_update_flag = 1;
                        break;
                    }
                }

            case 60:
                al_index = 61;
                if (BMS_Unit_Number >= 23) {
                    if (((BMU_Comm_Status3 >> 6) & 0x01) == 1) {
                        LCD_DrawRect(x + 21, y + 8, 16, 20, BLACK);
                        LCD_DrawImage1BPP(x, y + 8, BMP_Dijige, YELLOW, BLACK); //第23号连接故障
                        print_SZ(x + 21, y + 12, 23, 2, 0, YELLOW);
                        LCD_DrawImage1BPP(x + 21 + 16, y + 8, BMP_Hao, YELLOW, BLACK);
                        LCD_DrawImage1BPP(x + 21 + 16 + 21, y + 8, BMP_Lianjie, YELLOW, BLACK);
                        LCD_DrawImage1BPP(x + 21 + 16 + 21 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                        LCD_DrawRect(x + 21 + 16 + 21 + 42 + 42, y, 200, 36, BLACK);
                        alarm_update_flag = 1;
                        break;
                    }
                }

            case 61:
                al_index = 62;
                if (BMS_Unit_Number >= 24) {
                    if (((BMU_Comm_Status3 >> 7) & 0x01) == 1) {
                        LCD_DrawRect(x + 21, y + 8, 16, 20, BLACK);
                        LCD_DrawImage1BPP(x, y + 8, BMP_Dijige, YELLOW, BLACK); //第24号连接故障
                        print_SZ(x + 21, y + 12, 24, 2, 0, YELLOW);
                        LCD_DrawImage1BPP(x + 21 + 16, y + 8, BMP_Hao, YELLOW, BLACK);
                        LCD_DrawImage1BPP(x + 21 + 16 + 21, y + 8, BMP_Lianjie, YELLOW, BLACK);
                        LCD_DrawImage1BPP(x + 21 + 16 + 21 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                        LCD_DrawRect(x + 21 + 16 + 21 + 42 + 42, y, 200, 36, BLACK);
                        alarm_update_flag = 1;
                        break;
                    }
                }

            case 62:
                al_index = 63;
                if (Fcan_count == CAN_TIME) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Qianbu, YELLOW, BLACK); //前部
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Mokuai, YELLOW, BLACK); //模块
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Lixian, YELLOW, BLACK); //离线
                    LCD_DrawRect(x + 42 + 42 + 42, y, 250, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 63:
                al_index = 64;
                if (Mcan_count == CAN_TIME) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Dingbu, YELLOW, BLACK); //顶部
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Mokuai, YELLOW, BLACK); //模块
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Lixian, YELLOW, BLACK); //离线
                    LCD_DrawRect(x + 42 + 42 + 42, y, 250, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 64:
                al_index = 65;
                /*if (Rcan_count == CAN_TIME) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Houbu, YELLOW, BLACK); //后部
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Mokuai, YELLOW, BLACK); //模块
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Lixian, YELLOW, BLACK); //离线
                    LCD_DrawRect(x + 42 + 42 + 42, y, 250, 36, BLACK);
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

void updata_Dangwei(unsigned int x, unsigned int y) {
    unsigned char gear = 1;
    gear = DMC_Gear;
    if (gear > 2) gear = 0;
    LCD_DrawImage1BPP(x, y, BMP_DANGWEI[gear], GREEN, BLACK); //档位更新   
}

void updata_SOC(unsigned int x, unsigned int y) {
    unsigned char color = WHITE;
    static unsigned char soc = 100;
    soc = BMS_SOC * 0.4;
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
    DCDY = BMS_V * 0.1;
    if (DCDY >= 800) DCDY = 800;
    print_SZ_1(x, y, DCDY, 3, 0, WHITE); //电池电压数值 x=120+72+30   y=150+60-2
    //if (frmID == 0)
    //    LCD_DrawRect(225 + 2, 150 + 5 + 2, DCDY * 3.31 * 0.125, 28, GREEN); // 331/100  
    //if (DCDY < 800 && frmID == 0)//当为100时会出错
    //    LCD_DrawRect((225 + 2 + DCDY * 3.31 * 0.125), 150 + 5 + 2, (331 - DCDY * 3.31 * 0.125), 28, BLACK);
}

void updata_DCDL(unsigned int x, unsigned int y) {
    unsigned int DCDL = 100;
    DCDL = BMS_A * 0.1;
    if (DCDL < 3200) {
        DCDL = 3200 - DCDL;
        if (DCDL > 500) DCDL = 500;
        print_SZ_1(x, y, DCDL, 3, 0, WHITE);
        LCD_DrawImage1BPPZOOM_4(x - 20, y + 4, BMP_FU, WHITE, BLACK);
        //if (DCDL > 0 && frmID == 0)
        //    LCD_DrawRect((225 + 2 + 164 - DCDL * 1.64 * 0.2), 150 + 5 + 2 + 60, (DCDL * 1.64 * 0.2 + 1), 28, GREEN);
        //if (DCDL < 500 && frmID == 0) {
        //   LCD_DrawRect(225 + 2, 150 + 5 + 2 + 60, (164 - DCDL * 1.64 * 0.2), 28, BLACK); // 165/100         
        //    LCD_DrawRect(225 + 83 + 83 + 2, 150 + 5 + 2 + 60, 165, 28, BLACK);
        //}
    } else {
        DCDL = DCDL - 3200;
        if (DCDL > 500) DCDL = 500;
        LCD_DrawImage1BPPZOOM_4(x - 20, y + 4, BMP_ZHENG, WHITE, BLACK);
        print_SZ_1(x, y, DCDL, 3, 0, WHITE);
        //if (DCDL > 3 && frmID == 0)
        //    LCD_DrawRect(225 + 83 + 83 + 2, 150 + 5 + 2 + 60, (DCDL * 1.65 * 0.2), 28, GREEN); // 如果长度为0，会出错
        //if (DCDL < 500 && frmID == 0) {
        //    LCD_DrawRect((225 + 83 + 83 + 2 + DCDL * 1.65 * 0.2), 150 + 5 + 2 + 60, (165 - DCDL * 1.65 * 0.2), 28, BLACK);
        //    LCD_DrawRect(225 + 2, 150 + 5 + 2 + 60, 164, 28, BLACK);
        //}
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
        LCD_DrawImage1BPPZOOM_4(x - 25, y + 5, BMP_ZHENG, color1, BLACK);
        print_SZ_1(x, y, DAT - offset, sum, dot, color1); //电池电流数值 x=135+180+50+100+20+20   y=150+60-2
    }
}

void frmMain(void) {
    if (f_index == 0) { //只更新一次
        f_index = 1;
        mainFrame();
    } else if (f_index == 1) {
        f_index = 2;
    } else if (f_index == 2) {
        f_index = 3;
        disp_baojing();
        print_SZ_1(60, 318 + 15 + 38, Battery_Single_H, 4, 3, WHITE); //单体高电压
        print_SZ_1(60, 318 + 15 + 38 * 2, Battery_Single_L, 4, 3, WHITE); //单体低电压
    } else if (f_index == 3) {
        f_index = 4;
        disp_miles();
        if (IN3)//门开关图像报警
            LCD_DrawImage1BPP(150 + 195, 190 + 27, Bmp_Menkai, RED, BLACK); //门2开
        else
            LCD_DrawImage1BPP(150 + 195, 190 + 27, Bmp_Men, WHITE, BLACK); //门2关
        if (IN4)
            LCD_DrawImage1BPP(150 + 184 + 215, 190 + 27, Bmp_Menkai, RED, BLACK); //门1开
        else
            LCD_DrawImage1BPP(150 + 184 + 215, 190 + 27, Bmp_Men, WHITE, BLACK); //门1关
    } else if (f_index == 4) {
        f_index = 5;
        disp_time(330, 440 + 13, timer);
        updata_DAT(313 + 220, 318 + 15 + 38, DMC_Controller_temp, 1, 40, WHITE, 3, 0); //电机控制器温度
        updata_DAT(313, 318 + 15 + 38, DMC_Moto_temp, 1, 40, WHITE, 3, 0); //电机温度
    } else if (f_index == 5) {
        f_index = 6;
        updata_SOC(585, 155 - 10);
        updata_DAT(313 - 16, 318 + 15, BMS_V * 0.1, 1, 0, WHITE, 4, 0); //总电压
        updata_DAT(313 + 220 - 16, 318 + 15, BMS_A * 0.1, 1, 3200, WHITE, 4, 0); //总电流
    } else if (f_index == 6) {
        f_index = 7;
        updata_DAT(800 - 150, 318 + 15 + 38, Battery_Temp_H, 1, 40, WHITE, 3, 0); //单体高温
        updata_DAT(800 - 150, 318 + 15 + 38 * 2, Battery_Temp_L, 1, 40, WHITE, 3, 0); //单体低温       
        disp_CAN_baojing(162, 394 + 15);
    } else if (f_index == 7) {
        f_index = 1;
        updata_Dangwei(138 + 17 + 66 * 4, 74-10);
        //print_H(480 + 30 -16, 318+15 + 38*2, tcu_spn, 5, 0, WHITE); //spn
        //print_SZ_1(480 + 30 + 16, 318 + 38, TCU_code, 3, 0, color); //系统代码
    } else {
        f_index = 0;
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
            if (time_flag)
            t_add = 1;
            else t_add = 0;
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

/******************************************************/
void ICFrame(void) { //仪表框架
    LCD_Clear();

    LCD_DrawImage1BPPZOOM_4(320, 15, BmpZHYB, WHITE, BLACK);
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //顶部横线

    LCD_DrawImage1BPPZOOM_4(35, 75, Bmp_IN1, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(35, 75 + 25 * 1, Bmp_IN2, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(35, 75 + 25 * 2, Bmp_IN3, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(35, 75 + 25 * 3, Bmp_IN4, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(35, 75 + 25 * 4, Bmp_IN5, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(35, 75 + 25 * 5, Bmp_IN6, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(35, 75 + 25 * 6, Bmp_IN7, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(35, 75 + 25 * 7, Bmp_IN8, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(35, 75 + 25 * 8, Bmp_IN9, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(35, 75 + 25 * 9, Bmp_IN10, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(35, 75 + 25 * 10, Bmp_IN11, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(35, 75 + 25 * 11, Bmp_IN12, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(35, 75 + 25 * 12, Bmp_IN13, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(35, 75 + 25 * 13, Bmp_IN14, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(35, 75 + 25 * 14, Bmp_IN15, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(35, 75 + 25 * 15, Bmp_IN16, WHITE, BLACK);


    LCD_DrawImage1BPPZOOM_4(285, 75, Bmp_IN17, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 1, Bmp_IN18, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 2, Bmp_IN19, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 3, Bmp_IN20, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 4, Bmp_IN21, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 5, Bmp_IN22, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 6, Bmp_IN23, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 7, Bmp_IN24, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 8, Bmp_IN25, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 9, Bmp_IN26, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 10, Bmp_IN27, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 11, Bmp_IN28, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 12, Bmp_IN29, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 13, Bmp_IN30, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 14, Bmp_IN31, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 15, Bmp_IN32, WHITE, BLACK);


    LCD_DrawImage1BPPZOOM_4(535, 75, Bmp_IN33, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(535, 75 + 25 * 1, Bmp_IN34, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(535, 75 + 25 * 2, Bmp_IN35, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(535, 75 + 25 * 3, Bmp_IN36, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(535, 75 + 25 * 4, Bmp_IN37, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(535, 75 + 25 * 5, Bmp_IN38, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(535, 75 + 25 * 6, Bmp_IN39, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(535, 75 + 25 * 7, Bmp_IN40, WHITE, BLACK);


}

void ICUpdate(void) {
    unsigned int dump;
    unsigned int i;

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
        frmID = 10;
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
void BCUFrame(unsigned char index) {
    unsigned char i;
    LCD_Clear();

    LCD_DrawRect(0, 70, 800, 2, YELLOW); //顶部横线
    if (index == 0) {
        LCD_DrawImage1BPPZOOM_4(320, 15, BmpQMK, WHITE, BLACK);
        for (i = 0; i < 15; i++) {
            LCD_DrawImage1BPP(60 + 280, 75 + 3 + 25 * i, BMP_a, WHITE, BLACK);
            //LCD_DrawRect(0, 74 +25+ 25 * i, 800, 1, GRAY); //横线
        }

        LCD_DrawImage1BPPZOOM_4(60, 75, BmpBCU_F_OUT1, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 1, BmpBCU_F_OUT2, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 2, BmpBCU_F_OUT3, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 3, BmpBCU_F_OUT4, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 4, BmpBCU_F_OUT5, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 5, BmpBCU_F_OUT6, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 6, BmpBCU_F_OUT7, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 7, BmpBCU_F_OUT8, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 8, BmpBCU_F_OUT9, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 9, BmpBCU_F_OUT10, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 10, BmpBCU_F_OUT11, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 11, BmpBCU_F_OUT12, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 12, BmpBCU_F_OUT13, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 13, BmpBCU_F_OUT14, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 14, BmpBCU_F_OUT15, WHITE, BLACK);

        LCD_DrawImage1BPPZOOM_4(285 + 150, 75, BmpBCU_F_KL1, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285 + 150, 75 + 25 * 1, BmpBCU_F_KL2, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285 + 150, 75 + 25 * 2, BmpBCU_F_KL3, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285 + 150, 75 + 25 * 3, BmpBCU_F_KL4, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285 + 150, 75 + 25 * 4, BmpBCU_F_KL5, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285 + 150, 75 + 25 * 5, BmpBCU_F_KL6, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285 + 150, 75 + 25 * 6, BmpBCU_F_KL7, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285 + 150, 75 + 25 * 7, BmpBCU_F_KL8, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285 + 150, 75 + 25 * 8, BmpBCU_F_KL9, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285 + 150, 75 + 25 * 9, BmpBCU_F_KL10, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285 + 150, 75 + 25 * 10, BmpBCU_F_KL11, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285 + 150, 75 + 25 * 11, BmpBCU_F_KL12, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285 + 150, 75 + 25 * 12, BmpBCU_F_KL13, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285 + 150, 75 + 25 * 13, BmpBCU_F_KL14, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285 + 150, 75 + 25 * 14, BmpBCU_F_KL15, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285 + 150, 75 + 25 * 15, BmpBCU_F_KH1, WHITE, BLACK);
    } else if (index == 1) {
        LCD_DrawImage1BPPZOOM_4(320, 15, BmpZMK, WHITE, BLACK);
        for (i = 0; i < 15; i++) {
            LCD_DrawImage1BPP(60 + 280, 75 + 3 + 25 * i, BMP_a, WHITE, BLACK);
            //LCD_DrawRect(0, 74 +25+ 25 * i, 800, 1, GRAY); //横线
        }

        LCD_DrawImage1BPPZOOM_4(60, 75, BmpBCU_M_OUT1, WHITE, BLACK);
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
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 14, BmpBCU_M_OUT15, WHITE, BLACK);


        LCD_DrawImage1BPPZOOM_4(285 + 150, 75, BmpBCU_M_KL1, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285 + 150, 75 + 25 * 1, BmpBCU_M_KL2, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285 + 150, 75 + 25 * 2, BmpBCU_M_KL3, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285 + 150, 75 + 25 * 3, BmpBCU_M_KL4, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285 + 150, 75 + 25 * 4, BmpBCU_M_KL5, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285 + 150, 75 + 25 * 5, BmpBCU_M_KL6, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285 + 150, 75 + 25 * 6, BmpBCU_M_KL7, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285 + 150, 75 + 25 * 7, BmpBCU_M_KL8, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285 + 150, 75 + 25 * 8, BmpBCU_M_KL9, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285 + 150, 75 + 25 * 9, BmpBCU_M_KL10, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285 + 150, 75 + 25 * 10, BmpBCU_M_KL11, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285 + 150, 75 + 25 * 11, BmpBCU_M_KL12, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285 + 150, 75 + 25 * 12, BmpBCU_M_KL13, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285 + 150, 75 + 25 * 13, BmpBCU_M_KL14, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285 + 150, 75 + 25 * 14, BmpBCU_M_KL15, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285 + 150, 75 + 25 * 15, BmpBCU_M_KH1, WHITE, BLACK);
    } else if (index == 2) {

        LCD_DrawImage1BPPZOOM_4(320, 15, BmpHMK, WHITE, BLACK);
        for (i = 0; i < 15; i++) {
            LCD_DrawImage1BPP(60 + 280, 75 + 3 + 25 * i, BMP_a, WHITE, BLACK);
            //LCD_DrawRect(0, 74 +25+ 25 * i, 800, 1, GRAY); //横线
        }

        LCD_DrawImage1BPPZOOM_4(60, 75, BmpBCU_R_OUT1, WHITE, BLACK);
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
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 14, BmpBCU_R_OUT15, WHITE, BLACK);

        LCD_DrawImage1BPPZOOM_4(285 + 150, 75, BmpBCU_R_KL1, WHITE, BLACK);
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
        LCD_DrawImage1BPPZOOM_4(285 + 150, 75 + 25 * 15, BmpBCU_R_KH1, WHITE, BLACK);

    }
}

void BCUUpdate(unsigned char index) {
    unsigned int dump, i;
    unsigned char color;

    /*前控模块*/
    if (index == 0) {
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
    }

    /*中控模块*/
    if (index == 1) {
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
    }

    /*后控模块*/
    if (index == 2) {
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
    }
}

void frmBCU_f(void) {
    if (f_index == 0) { //只更新一次
        f_index = 1;
        BCUFrame(0);
    } else if (f_index == 1) {
        f_index = 1;
        BCUUpdate(0);
    } else {
        f_index = 0;
    }
    if (key_set) {
        key_set = 0;
        frmID = 0;
        f_index = 0;
    }
    if (key_up) {
        key_up = 0;
        frmID = 11;
        f_index = 0;
    }


}

void frmBCU_m(void) {
    if (f_index == 0) { //只更新一次
        f_index = 1;
        BCUFrame(1);
    } else if (f_index == 1) {
        f_index = 1;
        BCUUpdate(1);
    } else {
        f_index = 0;
    }
    if (key_set) {
        key_set = 0;
        frmID = 0;
        f_index = 0;
    }
    if (key_up) {
        key_up = 0;
        frmID = 1;
        f_index = 0;
    }
    
    if (key_AV) {
        key_AV = 0;
    }

}

void frmBCU_r(void) {
    if (f_index == 0) { //只更新一次
        f_index = 1;
        BCUFrame(2);
    } else if (f_index == 1) {
        f_index = 1;
        BCUUpdate(2);
    } else {
        f_index = 0;
    }
    if (key_set) {
        key_set = 0;
        frmID = 0;
        f_index = 0;
    }
    if (key_up) {
        key_up = 0;
        frmID = 1;
        f_index = 0;
    }

}

/******************************************************/

void MenuFrame(void) {
    LCD_Clear();
    unsigned char color = WHITE;
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //顶部横线   

    LCD_DrawRect(0, 430 + 15, 800, 2, YELLOW); //底部横线
    LCD_DrawImage1BPP(130, 130, BMP_MOTO, color, BLACK); //电机
    LCD_DrawImage1BPP(130 + 50, 130, BMP_STSTEM, color, BLACK); //系统
    LCD_DrawImage1BPP(130 + 50 + 50, 130, BMP_Message, color, BLACK); //信息

    LCD_DrawImage1BPP(130, 130 + 35, BMP_DMQ, color, BLACK); //气泵
    LCD_DrawImage1BPP(130 + 50, 130 + 35, BMP_STSTEM, color, BLACK); //系统
    LCD_DrawImage1BPP(130 + 50 + 50, 130 + 35, BMP_Message, color, BLACK); //信息

    LCD_DrawImage1BPP(130, 130 + 35 + 35, BMP_DCDC, color, BLACK); //DCDC
    LCD_DrawImage1BPP(130 + 65, 130 + 35 + 35, BMP_STSTEM, color, BLACK); //系统
    LCD_DrawImage1BPP(130 + 65 + 50, 130 + 35 + 35, BMP_Message, color, BLACK); //信息

    LCD_DrawImage1BPP(130, 130 + 35 + 35 + 35, BMP_DMY, color, BLACK); //油泵
    LCD_DrawImage1BPP(130 + 50, 130 + 35 + 35 + 35, BMP_STSTEM, color, BLACK); //系统
    LCD_DrawImage1BPP(130 + 50 + 50, 130 + 35 + 35 + 35, BMP_Message, color, BLACK); //信息

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
    LCD_DrawImage1BPP(130 + 50 + 350, 130 + 35 + 35 + 35, BMP_STSTEM, color, BLACK); //系统
    LCD_DrawImage1BPP(130 + 50 + 50 + 350, 130 + 35 + 35 + 35, BMP_Message, color, BLACK); //信息


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
       
    if (i == 16) i = 8;
    if (i == 0) i = 8;
    //子菜单间切换
    if (i == 8) {
        color = GREEN;
        if (key_set) {
            key_set = 0;
            if(time_flag==0){
                f_index = 0;  
                frmID = 2;
            }
            time_flag=0;
        }
    } else
        color = BLACK;
    LCD_DrawImage1BPP(105, 131, BMP_Choose, color, BLACK);
    if (i == 9 || i==1) {
        color = GREEN;
        if (key_set) {
            key_set = 0;
            if(time_flag==0){
                f_index = 0;  
                frmID = 3;
            }           
            time_flag=0;
        }
    } else
        color = BLACK;
    LCD_DrawImage1BPP(105, 131 + 35, BMP_Choose, color, BLACK);
    if (i == 10 || i==2) {
        color = GREEN;
        if (key_set) {
            key_set = 0;
            if(time_flag==0){
                f_index = 0;  
                frmID = 4;
            }          
            time_flag=0;
        }
    } else
        color = BLACK;
    LCD_DrawImage1BPP(105, 131 + 2 * 35, BMP_Choose, color, BLACK);
    if (i == 11 || i==3) {
        color = GREEN;
        if (key_set) {
            key_set = 0;
            if(time_flag==0){
                f_index = 0; 
                frmID = 5;
            }
            time_flag=0;
        }
    } else
        color = BLACK;
    LCD_DrawImage1BPP(105, 131 + 3 * 35, BMP_Choose, color, BLACK);
    if (i == 12 || i==4) {
        color = GREEN;
        if (key_set) {
            key_set = 0;
            if(time_flag==0){
                f_index = 0;  
                frmID = 6;
            }
            time_flag=0;
        }
    } else
        color = BLACK;
    LCD_DrawImage1BPP(105 + 350, 131, BMP_Choose, color, BLACK);
    if (i == 13 || i==5) {
        color = GREEN;
        if (key_set) {
            key_set = 0;
            if(time_flag==0){
                f_index = 0;  
                frmID = 7;
            }
            time_flag=0;
        }
    } else
        color = BLACK;
    LCD_DrawImage1BPP(105 + 350, 131 + 1 * 35, BMP_Choose, color, BLACK);
    if (i == 14 || i==6) {
        color = GREEN;
        if (key_set) {
            key_set = 0;
            if(time_flag==0){
                f_index = 0;  
                frmID = 8;
            }
            time_flag=0;
        }
    } else
        color = BLACK;
    LCD_DrawImage1BPP(105 + 350, 131 + 2 * 35, BMP_Choose, color, BLACK);
    if (i == 15 || i==7) {
        color = GREEN;
        if (key_set) {
            key_set = 0;
            if(time_flag==0){
                f_index = 0;  
                frmID = 9;
            }
            time_flag=0;
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
        disp_time(330, 440+13, timer);
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
}

/******************************************************/

void MOTOFrame(void) {
    unsigned char i = 0;
    LCD_Clear();
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //顶部横线
    LCD_DrawImage1BPP(130 + 200, 130 - 85, BMP_MOTO, WHITE, BLACK); //电机
    LCD_DrawImage1BPP(130 + 200 + 50, 130 - 85, BMP_STSTEM, WHITE, BLACK); //系统
    LCD_DrawImage1BPP(130 + 200 + 50 + 50, 130 - 85, BMP_Message, WHITE, BLACK); //信息

    LCD_DrawRect(80, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320 + 320, 90, 1, 380, GREEN);
    for (i = 0; i < 11; i++)
        LCD_DrawRect(80, 90 + i * 38, 640, 1, GREEN);

    LCD_DrawImage1BPP(82, 100, BMP_KZQ, WHITE, BLACK); //控制器
    LCD_DrawImage1BPP(82 + 63, 100, BMP_Muxian, WHITE, BLACK); //母线
    LCD_DrawImage1BPP(82 + 63 + 42, 100, BMP_DY, WHITE, BLACK); //电压
    LCD_DrawImage1BPP(400 - 24, 100, BMP_v, WHITE, BLACK); //v

    LCD_DrawImage1BPP(82, 100 + 38, BMP_KZQ, WHITE, BLACK); //控制器
    LCD_DrawImage1BPP(82 + 63, 100 + 38, BMP_Muxian, WHITE, BLACK); //母线
    LCD_DrawImage1BPP(82 + 63 + 42, 100 + 38, BMP_DL, WHITE, BLACK); //电流
    LCD_DrawImage1BPP(400 - 24, 100 + 38, BMP_a, WHITE, BLACK); //a

    LCD_DrawImage1BPP(82, 100 + 38 * 2, BMP_Chesu, WHITE, BLACK); //车速
    LCD_DrawImage1BPP(400 - 24 - 11 - 11 - 11, 100 + 38 * 2, BMP_k, WHITE, BLACK); //km/h
    LCD_DrawImage1BPP(400 - 24 - 11 - 11, 100 + 38 * 2, BMP_m, WHITE, BLACK); //
    LCD_DrawImage1BPP(400 - 24 - 11, 100 + 38 * 2, BMP_I, WHITE, BLACK); //
    LCD_DrawImage1BPP(400 - 24, 100 + 38 * 2, BMP_h, WHITE, BLACK); //

    LCD_DrawImage1BPP(82, 100 + 38 * 3, BMP_KZQ, WHITE, BLACK); //控制器
    LCD_DrawImage1BPP(82 + 63, 100 + 38 * 3, BMP_Jiben, WHITE, BLACK); //基本
    LCD_DrawImage1BPP(82 + 63 + 42, 100 + 38 * 3, BMP_Zhuangtai, WHITE, BLACK); //状态

    LCD_DrawImage1BPP(82, 100 + 38 * 4, BMP_DJ, WHITE, BLACK); //电机
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 4, BMP_KZQ, WHITE, BLACK); //控制器
    LCD_DrawImage1BPP(82 + 42 + 63, 100 + 38 * 4, BMP_Life, WHITE, BLACK); //Life

    LCD_DrawImage1BPP(82, 100 + 38 * 5, BMP_d, WHITE, BLACK); //DMC
    LCD_DrawImage1BPP(82 + 11, 100 + 38 * 5, BMP_m, WHITE, BLACK); //
    LCD_DrawImage1BPP(82 + 11 + 11, 100 + 38 * 5, BMP_c, WHITE, BLACK); //
    LCD_DrawImage1BPP(82 + 11 + 11 + 11, 100 + 38 * 5, BMP_Banben, WHITE, BLACK); //版本
    LCD_DrawImage1BPP(82 + 11 + 11 + 11 + 42, 100 + 38 * 5, BMP_Hao, WHITE, BLACK); //号
    LCD_DrawImage1BPP(400 - 24 - 96, 100 + 38 * 5 - 9, BMP_V, WHITE, BLACK); //V

    LCD_DrawImage1BPP(82, 100 + 38 * 6, BMP_Chong, WHITE, BLACK); //充放电状态
    LCD_DrawImage1BPP(82 + 21, 100 + 38 * 6, BMP_Fang, WHITE, BLACK); //
    LCD_DrawImage1BPP(82 + 21 + 21, 100 + 38 * 6, BMP_DC, WHITE, BLACK); //
    LCD_DrawImage1BPP(82 + 21 + 21 + 21, 100 + 38 * 6, BMP_Zhuangtai, WHITE, BLACK); //

    LCD_DrawImage1BPP(82 + 320, 100, BMP_DJ, WHITE, BLACK); //电机
    LCD_DrawImage1BPP(82 + 320 + 42, 100, BMP_Dangqian, WHITE, BLACK); //当前
    LCD_DrawImage1BPP(82 + 320 + 42 + 42, 100, BMP_Zhuansu, WHITE, BLACK); //转速
    LCD_DrawImage1BPP(720 - 24 - 24, 100, BMP_RPM, WHITE, BLACK); //RPM

    LCD_DrawImage1BPP(82 + 320, 100 + 38, BMP_DJ, WHITE, BLACK); //电机
    LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38, BMP_Dangqian, WHITE, BLACK); //当前
    LCD_DrawImage1BPP(82 + 320 + 42 + 42, 100 + 38, BMP_Zhuanju, WHITE, BLACK); //转速
    LCD_DrawImage1BPP(720 - 24 - 11, 100 + 38, BMP_n, WHITE, BLACK); //NM
    LCD_DrawImage1BPP(720 - 24, 100 + 38, BMP_m, WHITE, BLACK); //

    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 2, BMP_DJ, WHITE, BLACK); //电机
    LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 2, BMP_Wendu, WHITE, BLACK); //温度
    LCD_DrawImage1BPP(720 - 28, 100 + 38 * 2, BMP_T, WHITE, BLACK); //℃

    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 3, BMP_KZQ, WHITE, BLACK); //控制器
    LCD_DrawImage1BPP(82 + 320 + 63, 100 + 38 * 3, BMP_Wendu, WHITE, BLACK); //温度
    LCD_DrawImage1BPP(720 - 28, 100 + 38 * 3, BMP_T, WHITE, BLACK); //℃

    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 4, BMP_KZQ, WHITE, BLACK); //控制器
    LCD_DrawImage1BPP(82 + 320 + 63, 100 + 38 * 4, BMP_Guzhang, WHITE, BLACK); //故障
    LCD_DrawImage1BPP(82 + 320 + 63 + 42, 100 + 38 * 4, BMP_Code, WHITE, BLACK); //代码

    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 5, BMP_Youmen, WHITE, BLACK); //油门
    LCD_DrawImage1BPP(82 + 42 + 320, 100 + 38 * 5, BMP_Taban, WHITE, BLACK); //踏板
    LCD_DrawImage1BPP(82 + 42 + 42 + 320, 100 + 38 * 5, BMP_Kaidu, WHITE, BLACK); //开度
    LCD_DrawImage1BPP(720 - 24, 100 + 38 * 5, BMP_Baifenhao, WHITE, BLACK); //%

    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 6, BMP_Zhidong, WHITE, BLACK); //制动
    LCD_DrawImage1BPP(82 + 42 + 320, 100 + 38 * 6, BMP_Taban, WHITE, BLACK); //踏板
    LCD_DrawImage1BPP(82 + 42 + 42 + 320, 100 + 38 * 6, BMP_Kaidu, WHITE, BLACK); //开度
    LCD_DrawImage1BPP(720 - 24, 100 + 38 * 6, BMP_Baifenhao, WHITE, BLACK); //%

    /*
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
     */
}

void MOTOUpdate(void) {

    print_SZ_1(82 + 200 + 20, 100 - 8, DMC_Voltage * 0.05, 4, 0, WHITE);
    updata_DAT(82 + 200 + 20, 100 - 8 + 38, DMC_Current, 0.05, 1600, WHITE, 4, 0);
    print_SZ_1(82 + 200 + 20 - 16, 100 - 8 + 38 * 2, DMC_Speed * 0.5, 3, 0, WHITE);
    print_D(82 + 180, 100 - 8 + 38 * 3, (DMC_Status << 5)+(DMC_Level << 3)); //电机控制器基本状态
    print_H(82 + 200 + 20 + 16, 100 - 8 + 38 * 4, DMC_Life, 3, 0, WHITE); //电机生命
    print_SZ_1(82 + 200 + 20, 100 - 8 + 38 * 5, DMC_Verison, 3, 2, WHITE); //程序版本
    print_SZ_1(82 + 200 + 20 + 16 * 3, 100 - 8 + 38 * 6, DMC_Charge, 1, 0, WHITE); //充放电状态

    updata_DAT(82 + 200 + 300, 100 - 8, DMC_Rpm, 0.5, 16000, WHITE, 5, 0);
    updata_DAT(82 + 200 + 300, 100 - 8 + 38, DMC_Torque, 0.1, 3200, WHITE, 4, 0);
    updata_DAT(82 + 200 + 300, 100 - 8 + 38 * 2, DMC_Moto_temp, 1, 40, WHITE, 3, 0);
    updata_DAT(82 + 200 + 300, 100 - 8 + 38 * 3, DMC_Controller_temp, 1, 40, WHITE, 3, 0);
    print_SZ_1(82 + 200 + 20 + 320, 100 - 8 + 38 * 4, DMC_Protect_code, 3, 0, WHITE); //故障代码
    print_SZ_1(82 + 200 + 20 + 320, 100 - 8 + 38 * 5, DMC_Accelerator_percent, 3, 0, WHITE); //油门开度
    print_SZ_1(82 + 200 + 20 + 320, 100 - 8 + 38 * 6, DMC_Brake_percent, 3, 0, WHITE); //油门开度

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
    LCD_DrawImage1BPP(130 + 200 - 15, 130 - 85, BMP_DMQ, WHITE, BLACK); //气泵
    LCD_DrawImage1BPP(130 + 200 + 50 - 15, 130 - 85, BMP_STSTEM, WHITE, BLACK); //系统
    LCD_DrawImage1BPP(130 + 200 + 50 + 50 - 15, 130 - 85, BMP_Message, WHITE, BLACK); //信息

    LCD_DrawRect(80, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320 + 320, 90, 1, 380, GREEN);
    for (i = 0; i < 11; i++)
        LCD_DrawRect(80, 90 + i * 38, 640, 1, GREEN);

    LCD_DrawImage1BPP(82, 100, BMP_DJ, WHITE, BLACK); //电机
    LCD_DrawImage1BPP(82 + 42, 100, BMP_Zhuansu, WHITE, BLACK); //转速
    LCD_DrawImage1BPP(400 - 24 - 24, 100, BMP_RPM, WHITE, BLACK); //RPM

    LCD_DrawImage1BPP(82, 100 + 38, BMP_KZQ, WHITE, BLACK); //控制器
    LCD_DrawImage1BPP(82 + 63, 100 + 38, BMP_Muxian, WHITE, BLACK); //母线
    LCD_DrawImage1BPP(82 + 63 + 42, 100 + 38, BMP_DY, WHITE, BLACK); //电压
    LCD_DrawImage1BPP(400 - 24, 100 + 38, BMP_v, WHITE, BLACK); //v

    LCD_DrawImage1BPP(82, 100 + 38 * 2, BMP_KZQ, WHITE, BLACK); //控制器
    LCD_DrawImage1BPP(82 + 63, 100 + 38 * 2, BMP_Muxian, WHITE, BLACK); //母线
    LCD_DrawImage1BPP(82 + 63 + 42, 100 + 38 * 2, BMP_DL, WHITE, BLACK); //电流
    LCD_DrawImage1BPP(400 - 24, 100 + 38 * 2, BMP_a, WHITE, BLACK); //a

    LCD_DrawImage1BPP(82 + 320, 100, BMP_KZQ, WHITE, BLACK); //控制器
    LCD_DrawImage1BPP(82 + 320 + 63, 100, BMP_Wendu, WHITE, BLACK); //温度
    LCD_DrawImage1BPP(720 - 28, 100, BMP_T, WHITE, BLACK); //℃

    LCD_DrawImage1BPP(82 + 320, 100 + 38, BMP_Qibeng, WHITE, BLACK); //气泵
    LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38, BMP_Life, WHITE, BLACK); //Life

    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 2, BMP_KZQ, WHITE, BLACK); //控制器
    LCD_DrawImage1BPP(82 + 320 + 63, 100 + 38 * 2, BMP_Zhuangtai, WHITE, BLACK); //状态



    /*
    //LCD_DrawImage1BPP(82, 100 + 38 * 3, BMP_Niaosu, WHITE, BLACK); //尿素
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 3, BMP_Yewei, WHITE, BLACK); //液位
    LCD_DrawImage1BPP(400 - 24, 100 + 38 * 3, BMP_Baifenhao, WHITE, BLACK); //%


    //LCD_DrawImage1BPP(82 + 320, 100, BMP_Fadongji, WHITE, BLACK); //发动机
    LCD_DrawImage1BPP(82 + 63 + 320, 100, BMP_Mubiao, WHITE, BLACK); //目标
    LCD_DrawImage1BPP(82 + 63 + 42 + 320, 100, BMP_Youmen, WHITE, BLACK); //油门
    LCD_DrawImage1BPP(720 - 24, 100, BMP_Baifenhao, WHITE, BLACK); //%

    //LCD_DrawImage1BPP(82 + 320, 100 + 38, BMP_Fadongji, WHITE, BLACK); //发动机
    LCD_DrawImage1BPP(82 + 63 + 320, 100 + 38, BMP_Shiji, WHITE, BLACK); //实际
    LCD_DrawImage1BPP(82 + 63 + 42 + 320, 100 + 38, BMP_Youmen, WHITE, BLACK); //油门
    LCD_DrawImage1BPP(720 - 24, 100 + 38, BMP_Baifenhao, WHITE, BLACK); //%   

    //LCD_DrawImage1BPP(82 + 320, 100 + 38 * 2, BMP_Fadongji, WHITE, BLACK); //发动机
    //LCD_DrawImage1BPP(82 + 63 + 320, 100 + 38 * 2, BMP_Jiyou, WHITE, BLACK); //机油
    LCD_DrawImage1BPP(82 + 63 + 42 + 320, 100 + 38 * 2, BMP_Yali, WHITE, BLACK); //压力
    LCD_DrawImage1BPP(720 - 32, 100 + 38 * 2, BMP_Kpa, WHITE, BLACK); //Kpa

    //LCD_DrawImage1BPP(82 + 320, 100 + 38 * 3, BMP_Fadongji, WHITE, BLACK); //发动机
    //LCD_DrawImage1BPP(82 + 63 + 320, 100 + 38 * 3, BMP_Jinqi, WHITE, BLACK); //进气
    LCD_DrawImage1BPP(82 + 63 + 42 + 320, 100 + 38 * 3, BMP_Wendu, WHITE, BLACK); //温度
    LCD_DrawImage1BPP(720 - 28, 100 + 38 * 3, BMP_T, WHITE, BLACK); //℃
     */
}

void DMQUpdate(void) {
    print_SZ_1(82 + 200 + 20 - 16, 100 - 8, DMQ_Rpm * 0.125, 4, 0, WHITE);
    print_SZ_1(82 + 200 + 20 - 16, 100 - 8 + 38, DMQ_Voltage * 0.1, 4, 0, WHITE);
    print_SZ_1(82 + 200 + 20, 100 - 8 + 38 * 2, DMQ_Current, 3, 0, WHITE);

    updata_DAT(82 + 200 + 300, 100 - 8, DMQ_Controller_temp, 1, 40, WHITE, 3, 0);
    print_SZ_1(82 + 200 + 300, 100 - 8 + 38, DMQ_Life, 3, 0, WHITE); //心跳
    print_D(82 + 180 + 320, 100 - 8 + 38 * 2, DMQ_Status); //控制器基本状态

    /*
    print_SZ_1(82 + 63 + 42 + 80, 100 - 8, Fule_rate * 5, 4, 2, WHITE); //油耗
    updata_T(82 + 63 + 42 + 80 + 32, 100 - 8 + 38, WHITE, water_temp, 1, 40); //水温
    print_SZ_1(82 + 63 + 42 + 80 + 16, 100 - 8 + 38 * 2, Engine_Fuhe, 4, 0, WHITE); //负荷
    print_SZ_1(82 + 63 + 42 + 80, 100 - 8 + 38 * 3, Niaosu * 4, 4, 1, WHITE); //尿素
    print_SZ_1(82 + 63 + 42 + 80 + 320, 100 - 8, Accelerator * 4, 4, 1, WHITE); //目标油门
    print_SZ_1(82 + 63 + 42 + 80 + 320, 100 - 8 + 38, Accelerator_Shiji * 4, 4, 1, WHITE); //实际油门
    print_SZ_1(82 + 63 + 42 + 80 + 16 + 320, 100 - 8 + 38 * 2, Engine_oil_press * 4, 4, 0, WHITE); //机油压力
    updata_T(82 + 63 + 42 + 80 + 32 + 320, 100 - 8 + 38 * 3, WHITE, ambient_air_temperature, 1, 40); //进气温度
     */
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

    LCD_DrawImage1BPP(82 + 320, 100 - 2, BMP_DCDC, WHITE, BLACK); //DCDC
    LCD_DrawImage1BPP(82 + 320 + 65, 100 + 2, BMP_System, WHITE, BLACK); //系统
    LCD_DrawImage1BPP(82 + 320 + 65 + 42, 100 + 2, BMP_Code, WHITE, BLACK); //代码

    LCD_DrawImage1BPP(82 + 320, 100 - 2 + 38, BMP_DCDC, WHITE, BLACK); //DCDC
    LCD_DrawImage1BPP(82 + 320 + 65, 100 + 2 + 38, BMP_Guzhang, WHITE, BLACK); //故障
    LCD_DrawImage1BPP(82 + 320 + 65 + 42, 100 + 2 + 38, BMP_Code, WHITE, BLACK); //代码

    LCD_DrawImage1BPP(82 + 320, 100 - 2 + 38 * 2, BMP_DCDC, WHITE, BLACK); //DCDC
    LCD_DrawImage1BPP(82 + 320 + 65, 100 + 2 + 38 * 2, BMP_Banben, WHITE, BLACK); //版本
    LCD_DrawImage1BPP(82 + 320 + 65 + 42, 100 + 2 + 38 * 2, BMP_Hao, WHITE, BLACK); //号
    LCD_DrawImage1BPP(720 - 24 - 90, 100 - 9 + 38 * 2, BMP_V, WHITE, BLACK); //v

}

void DCDCUpdate(void) {
    print_SZ_1(82 + 200 + 20 - 16, 100 - 8, DCDC_Voltage * 0.05, 4, 0, WHITE);
    updata_DAT(82 + 200 + 20 - 16, 100 - 8 + 38, DCDC_Current, 0.05, 1600, WHITE, 4, 0);
    updata_DAT(82 + 200 + 20, 100 - 8 + 38 * 2, DCDC_Temp, 1, 40, WHITE, 3, 0);

    print_D(82 + 180 + 320, 100 - 8, DCDC_Status); //系统代码
    print_D(82 + 180 + 320, 100 - 8 + 38, DCDC_Code); //系统代码
    print_SZ_1(82 + 200 + 340, 100 - 8 + 38 * 2, DCDC_Verison, 3, 2, WHITE); //程序版本

    /*
    print_SZ_1(82 + 270, 100 - 8, DCAC_W * 0.1 - 1000, 4, 0, WHITE); //W相电流
    print_SZ_1(82 + 270, 100 - 8 + 38, DCAC_V * 0.1 - 1000, 4, 0, WHITE); //W相电流
    print_SZ_1(82 + 270, 100 - 8 + 38 * 2, DCAC_U * 0.1 - 1000, 4, 0, WHITE); //W相电流
    updata_T(82 + 63 + 42 + 80 + 32 + 320, 100 - 8, WHITE, Sanreqi_t, 1, 40); //散热器温度
    print_SZ_1(82 + 270 + 320 - 52, 100 - 8 + 38, DCAC_Warn_code, 3, 0, WHITE); //故障码
     */
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
    LCD_DrawImage1BPP(130 + 200, 130 - 85, BMP_DMY, WHITE, BLACK); //油泵
    LCD_DrawImage1BPP(130 + 200 + 50, 130 - 85, BMP_STSTEM, WHITE, BLACK); //系统
    LCD_DrawImage1BPP(130 + 200 + 50 + 50, 130 - 85, BMP_Message, WHITE, BLACK); //信息

    LCD_DrawRect(80, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320 + 320, 90, 1, 380, GREEN);
    for (i = 0; i < 11; i++)
        LCD_DrawRect(80, 90 + i * 38, 640, 1, GREEN);

    LCD_DrawImage1BPP(82, 100, BMP_DJ, WHITE, BLACK); //电机
    LCD_DrawImage1BPP(82 + 42, 100, BMP_Zhuansu, WHITE, BLACK); //转速
    LCD_DrawImage1BPP(400 - 24 - 24, 100, BMP_RPM, WHITE, BLACK); //RPM

    LCD_DrawImage1BPP(82, 100 + 38, BMP_KZQ, WHITE, BLACK); //控制器
    LCD_DrawImage1BPP(82 + 63, 100 + 38, BMP_Muxian, WHITE, BLACK); //母线
    LCD_DrawImage1BPP(82 + 63 + 42, 100 + 38, BMP_DY, WHITE, BLACK); //电压
    LCD_DrawImage1BPP(400 - 24, 100 + 38, BMP_v, WHITE, BLACK); //v

    LCD_DrawImage1BPP(82, 100 + 38 * 2, BMP_KZQ, WHITE, BLACK); //控制器
    LCD_DrawImage1BPP(82 + 63, 100 + 38 * 2, BMP_Muxian, WHITE, BLACK); //母线
    LCD_DrawImage1BPP(82 + 63 + 42, 100 + 38 * 2, BMP_DL, WHITE, BLACK); //电流
    LCD_DrawImage1BPP(400 - 24, 100 + 38 * 2, BMP_a, WHITE, BLACK); //a

    LCD_DrawImage1BPP(82 + 320, 100, BMP_KZQ, WHITE, BLACK); //控制器
    LCD_DrawImage1BPP(82 + 320 + 63, 100, BMP_Wendu, WHITE, BLACK); //温度
    LCD_DrawImage1BPP(720 - 28, 100, BMP_T, WHITE, BLACK); //℃

    LCD_DrawImage1BPP(82 + 320, 100 + 38, BMP_Youbeng, WHITE, BLACK); //油泵
    LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38, BMP_Life, WHITE, BLACK); //Life

    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 2, BMP_KZQ, WHITE, BLACK); //控制器
    LCD_DrawImage1BPP(82 + 320 + 63, 100 + 38 * 2, BMP_Zhuangtai, WHITE, BLACK); //状态
}

void DMYUpdate(void) {
    print_SZ_1(82 + 200 + 20 - 16, 100 - 8, DMY_Rpm * 0.125, 4, 0, WHITE);
    print_SZ_1(82 + 200 + 20 - 16, 100 - 8 + 38, DMY_Voltage * 0.1, 4, 0, WHITE);
    print_SZ_1(82 + 200 + 20, 100 - 8 + 38 * 2, DMY_Current, 3, 0, WHITE);

    updata_DAT(82 + 200 + 300, 100 - 8, DMY_Controller_temp, 1, 40, WHITE, 3, 0);
    print_SZ_1(82 + 200 + 300, 100 - 8 + 38, DMY_Life, 3, 0, WHITE); //心跳
    print_D(82 + 180 + 320, 100 - 8 + 38 * 2, DMY_Status); //控制器基本状态
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

    LCD_DrawImage1BPP(82, 100 + 38 * 2, BMP_DC, WHITE, BLACK); //电池
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 2, BMP_Zhuangtai, WHITE, BLACK); //状态
    LCD_DrawImage1BPP(82 + 42 + 42, 100 - 8 + 38 * 2, BMP_SZ_1[1], WHITE, BLACK); //1

    LCD_DrawImage1BPP(82, 100 + 38 * 3, BMP_DC, WHITE, BLACK); //电池
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 3, BMP_Zhuangtai, WHITE, BLACK); //状态
    LCD_DrawImage1BPP(82 + 42 + 42, 100 - 8 + 38 * 3, BMP_SZ_1[2], WHITE, BLACK); //2

    LCD_DrawImage1BPP(82, 100 + 38 * 4, BMP_DC, WHITE, BLACK); //电池
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 4, BMP_Zhuangtai, WHITE, BLACK); //状态
    LCD_DrawImage1BPP(82 + 42 + 42, 100 - 8 + 38 * 4, BMP_SZ_1[3], WHITE, BLACK); //3

    LCD_DrawImage1BPP(82, 100 + 38 * 5, BMP_DC, WHITE, BLACK); //电池
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 5, BMP_Xiang, WHITE, BLACK); //箱
    LCD_DrawImage1BPP(82 + 42 + 21, 100 + 38 * 5, BMP_Geshu, WHITE, BLACK); //个数

    LCD_DrawImage1BPP(82, 100 + 38 * 6, BMP_Congkong, WHITE, BLACK); //从控
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 6, BMP_Danyuan, WHITE, BLACK); //单元
    LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 6, BMP_Geshu, WHITE, BLACK); //个数

    LCD_DrawImage1BPP(82 + 320, 100, BMP_Dan, WHITE, BLACK); //单
    LCD_DrawImage1BPP(82 + 320 + 21, 100, BMP_Ti, WHITE, BLACK); //体
    LCD_DrawImage1BPP(82 + 320 + 21 + 21, 100, BMP_Zui, WHITE, BLACK); //最
    LCD_DrawImage1BPP(82 + 320 + 21 + 21 + 21, 100, BMP_Gao, WHITE, BLACK); //高
    LCD_DrawImage1BPP(82 + 320 + 21 + 21 + 21 + 21, 100, BMP_DY, WHITE, BLACK); //电压
    LCD_DrawImage1BPP(720 - 24 - 63, 100, BMP_v, WHITE, BLACK); //V

    LCD_DrawImage1BPP(82 + 320 + 42 * 7, 100, BMP_Xiang, WHITE, BLACK); //箱

    LCD_DrawImage1BPP(82 + 320 + 42 * 8.5, 100, BMP_Hao, WHITE, BLACK); //号

    LCD_DrawImage1BPP(82 + 320, 100 + 38, BMP_Dan, WHITE, BLACK); //单
    LCD_DrawImage1BPP(82 + 320 + 21, 100 + 38, BMP_Ti, WHITE, BLACK); //体
    LCD_DrawImage1BPP(82 + 320 + 21 + 21, 100 + 38, BMP_Zui, WHITE, BLACK); //最
    LCD_DrawImage1BPP(82 + 320 + 21 + 21 + 21, 100 + 38, BMP_Di, WHITE, BLACK); //低
    LCD_DrawImage1BPP(82 + 320 + 21 + 21 + 21 + 21, 100 + 38, BMP_DY, WHITE, BLACK); //电压
    LCD_DrawImage1BPP(720 - 24 - 63, 100 + 38, BMP_v, WHITE, BLACK); //V

    LCD_DrawImage1BPP(82 + 320 + 42 * 7, 100 + 38, BMP_Xiang, WHITE, BLACK); //箱

    LCD_DrawImage1BPP(82 + 320 + 42 * 8.5, 100 + 38, BMP_Hao, WHITE, BLACK); //号

    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 2, BMP_DC, WHITE, BLACK); //电池
    LCD_DrawImage1BPP(82 + 320 + 21 + 21, 100 + 38 * 2, BMP_Zui, WHITE, BLACK); //最
    LCD_DrawImage1BPP(82 + 320 + 21 + 21 + 21, 100 + 38 * 2, BMP_Gao, WHITE, BLACK); //高
    LCD_DrawImage1BPP(82 + 320 + 21 + 21 + 21 + 21, 100 + 38 * 2, BMP_Wendu, WHITE, BLACK); //温度
    LCD_DrawImage1BPP(720 - 28 - 63, 100 + 38 * 2, BMP_T, WHITE, BLACK); //℃

    LCD_DrawImage1BPP(82 + 320 + 42 * 7, 100 + 38 * 2, BMP_Xiang, WHITE, BLACK); //箱

    LCD_DrawImage1BPP(82 + 320 + 42 * 8.5, 100 + 38 * 2, BMP_Hao, WHITE, BLACK); //号

    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 3, BMP_DC, WHITE, BLACK); //电池
    LCD_DrawImage1BPP(82 + 320 + 21 + 21, 100 + 38 * 3, BMP_Zui, WHITE, BLACK); //最
    LCD_DrawImage1BPP(82 + 320 + 21 + 21 + 21, 100 + 38 * 3, BMP_Di, WHITE, BLACK); //低
    LCD_DrawImage1BPP(82 + 320 + 21 + 21 + 21 + 21, 100 + 38 * 3, BMP_Wendu, WHITE, BLACK); //温度
    LCD_DrawImage1BPP(720 - 28 - 63, 100 + 38 * 3, BMP_T, WHITE, BLACK); //℃

    LCD_DrawImage1BPP(82 + 320 + 42 * 7, 100 + 38 * 3, BMP_Xiang, WHITE, BLACK); //箱

    LCD_DrawImage1BPP(82 + 320 + 42 * 8.5, 100 + 38 * 3, BMP_Hao, WHITE, BLACK); //号

    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 4, BMP_DC, WHITE, BLACK); //电池
    LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 4, BMP_System, WHITE, BLACK); //系统
    LCD_DrawImage1BPP(82 + 320 + 42 + 42, 100 + 38 * 4, BMP_Zong, WHITE, BLACK); //总
    LCD_DrawImage1BPP(82 + 320 + 42 + 42 + 21, 100 + 38 * 4, BMP_Chuanshu, WHITE, BLACK); //串数

    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 5, BMP_DC, WHITE, BLACK); //电池
    LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 5, BMP_System, WHITE, BLACK); //系统
    LCD_DrawImage1BPP(82 + 320 + 42 + 42, 100 + 38 * 5, BMP_Bianhao, WHITE, BLACK); //编号


    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 6, BMP_DC, WHITE, BLACK); //电池
    LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 6, BMP_System, WHITE, BLACK); //系统
    LCD_DrawImage1BPP(82 + 320 + 42 + 42, 100 + 38 * 6, BMP_Life, WHITE, BLACK); //Life

    /*
    LCD_DrawImage1BPP(82+ 320, 100 + 38, BMP_Zui, WHITE, BLACK); //最
    LCD_DrawImage1BPP(82 + 320+ 21, 100 + 38, BMP_Da, WHITE, BLACK); //大
    LCD_DrawImage1BPP(82 + 320+ 21 + 21, 100 + 38, BMP_Yunxu, WHITE, BLACK); //允许
    LCD_DrawImage1BPP(82+ 320 + 21 + 21 + 42, 100 + 38, BMP_Chong, WHITE, BLACK); //充
    LCD_DrawImage1BPP(82 + 320+ 21 + 21 + 42 + 21, 100 + 38, BMP_DY, WHITE, BLACK); //电
    LCD_DrawImage1BPP(82 + 320+ 21 + 21 + 42 + 21 + 21, 100 + 38, BMP_DL, WHITE, BLACK); //电流
    LCD_DrawImage1BPP(82+ 320 + 21 + 21 + 42 + 21 + 21 + 42 + 2, 100 + 38 + 5, BMP_Maohao, WHITE, BLACK); //:
    LCD_DrawImage1BPP(720 - 24, 100 + 38, BMP_a, WHITE, BLACK); //A

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
     */

}

void BMSUpdate(void) {
    updata_DCDY(82 + 200 + 30, 100 - 8);
    updata_DCDL(82 + 200 + 30, 100 - 8 + 38);
    print_D(82 + 180, 100 - 8 + 38 * 2, BMS_Status_Flag1);
    print_D(82 + 180, 100 - 8 + 38 * 3, BMS_Status_Flag2);
    print_D(82 + 180, 100 - 8 + 38 * 4, BMS_Status_Flag3);
    print_SZ_1(82 + 200 + 30 + 16 * 3, 100 - 8 + 38 * 5, Battery_Case_Total_Number, 2, 0, WHITE);
    print_SZ_1(82 + 200 + 30 + 16 * 3, 100 - 8 + 38 * 6, BMS_Unit_Number, 2, 0, WHITE);

    print_SZ_1(82 + 200 + 260, 100 - 8, Battery_Single_H, 4, 3, WHITE);
    print_SZ_1(82 + 200 + 260 + 16 * 7, 100 - 8, Battery_Single_H_Positon_Case, 2, 0, WHITE);
    print_SZ_1(82 + 200 + 260 + 16 * 11, 100 - 8, Battery_Single_H_Positon_Cell, 2, 0, WHITE);

    print_SZ_1(82 + 200 + 260, 100 - 8 + 38, Battery_Single_L, 4, 3, WHITE);
    print_SZ_1(82 + 200 + 260 + 16 * 7, 100 - 8 + 38, Battery_Single_L_Positon_Case, 2, 0, WHITE);
    print_SZ_1(82 + 200 + 260 + 16 * 11, 100 - 8 + 38, Battery_Single_L_Positon_Cell, 2, 0, WHITE);

    updata_DAT(82 + 200 + 260 + 16 * 2, 100 - 8 + 38 * 2, Battery_Temp_H, 1, 40, WHITE, 3, 0);
    print_SZ_1(82 + 200 + 260 + 16 * 7, 100 - 8 + 38 * 2, Battery_Temp_H_Positon_Case, 2, 0, WHITE);
    print_SZ_1(82 + 200 + 260 + 16 * 11, 100 - 8 + 38 * 2, Battery_Temp_H_Positon_Cell, 2, 0, WHITE);

    updata_DAT(82 + 200 + 260 + 16 * 2, 100 - 8 + 38 * 3, Battery_Temp_L, 1, 40, WHITE, 3, 0);
    print_SZ_1(82 + 200 + 260 + 16 * 7, 100 - 8 + 38 * 3, Battery_Temp_L_Positon_Case, 2, 0, WHITE);
    print_SZ_1(82 + 200 + 260 + 16 * 11, 100 - 8 + 38 * 3, Battery_Temp_L_Positon_Cell, 2, 0, WHITE);

    print_SZ_1(82 + 200 + 260 + 16 * 10, 100 - 8 + 38 * 4, Battery_Cell_Total_Number, 3, 0, WHITE);
    print_SZ_1(82 + 200 + 260 + 16 * 10, 100 - 8 + 38 * 5, BMS_Nubmer, 3, 0, WHITE);
    print_SZ_1(82 + 200 + 260 + 16 * 10, 100 - 8 + 38 * 6, BMS_Life, 3, 0, WHITE);

    /*
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
     */
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
    //LCD_DrawRect(0, 70, 800, 2, YELLOW); //顶部横线
    LCD_DrawImage1BPP(30, 20, BMP_Battery, WHITE, BLACK); //电池
    LCD_DrawImage1BPP(30 + 50, 20, BMP_Message, WHITE, BLACK); //信息

    LCD_DrawImage1BPP(30, 20 + 38 + 7, BMP_Xiang, WHITE, BLACK); //箱
    LCD_DrawImage1BPP(30 + 21, 20 + 38 + 7, BMP_Hao, WHITE, BLACK); //号
    //分格
    for (i = 0; i < 3; i++)
        LCD_DrawRect(200 + 200 * i, 90 - 38 * 2, 1, 456, GREEN);
    for (i = 0; i < 13; i++)
        LCD_DrawRect(200, 90 - 38 * 2 + i * 38, 400, 1, GREEN);

    for (j = 0; j < 2; j++) {
        for (i = 0; i < 12; i++) {
            if (i < 9) {//写编号个位
                LCD_DrawImage1BPP(40 + 5 + 16 + 36 + 120 + j * 200, 92 - 38 * 2 + i * 38, BMP_SZ_1[i + 1], WHITE, BLACK);
            } else {//写最底下一行编号
                LCD_DrawImage1BPP(40 + 5 + 16 + 36 + 120 + j * 200, 92 - 38 * 2 + i * 38, BMP_SZ_1[i - 9], WHITE, BLACK);
                LCD_DrawImage1BPP(40 + 5 + 36 + 120 + j * 200, 92 - 38 * 2 + i * 38, BMP_SZ_1[1], WHITE, BLACK);
            }
            if (j == 0)
                LCD_DrawImage1BPP(40 + 5 + 72 + 250, 92 - 38 * 2 + i * 38, BMP_V, YELLOW, BLACK);
            else
                LCD_DrawImage1BPP(40 + 5 + 70 + 250 + 200, 100 - 38 * 2 + i * 38, BMP_T, YELLOW, BLACK);
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
    print_SZ_1(30 + 50, 20 + 38, BMU_Number, 2, 0, WHITE);
    for (i = 0; i < 12; i++) {
        if (Battery_Voltage[i] == 0xFFFF)
            print_SZ_1(82 + 200, 100 - 38 * 2 - 8 + 38 * i, Battery_Voltage[i], 4, 3, BLACK); //无效电压清除
        else
            print_SZ_1(82 + 200, 100 - 38 * 2 - 8 + 38 * i, Battery_Voltage[i], 4, 3, WHITE); //单体电压
    }
    for (i = 0; i < 12; i++) {
        if (Battery_Temp[i] == 0xFF)
            updata_DAT(82 + 200 + 220, 100 - 38 * 2 - 8 + 38 * i, Battery_Temp[i], 1, 40, BLACK, 3, 0);//无效温度清除
        else
            updata_DAT(82 + 200 + 220, 100 - 38 * 2 - 8 + 38 * i, Battery_Temp[i], 1, 40, WHITE, 3, 0);//单体温度
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
        //f_index = 0;
        if (BMU_Number > 0)
            BMU_Number--;
        if (BMU_Number == 0) {
            BMU_Number = BMS_Unit_Number;
        }
    }

    if (key_up) {
        key_up = 0;
        //f_index = 0;
        BMU_Number++;
        if (BMU_Number > BMS_Unit_Number)
            BMU_Number = 1;
        //if (BMU_Number > Battery_Case_Total_Number)
        //    BMU_Number = 1;

        //frmID = 1;
        //Index++;//多界面切换
        //if(Index==4) Index=0;
    }

    if (key_set) {//返回主界面
        key_set = 0;
        frmID = 0;
        f_index = 0;
        Index = 0;
        BMU_Number = 1;
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

    /*
    LCD_DrawImage1BPP(82, 100 + 38 * 3, BMP_Kongtiao, WHITE, BLACK); //空调
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 3, BMP_Life, WHITE, BLACK); //Life
    LCD_DrawImage1BPP(82 + 42 + 44 + 2, 100 + 5 + 38 * 3, BMP_Maohao, WHITE, BLACK); //:
     */

    LCD_DrawImage1BPP(82 + 320, 100, BMP_Che, WHITE, BLACK); //车
    LCD_DrawImage1BPP(82 + 320 + 21, 100, BMP_Wai, WHITE, BLACK); //外
    LCD_DrawImage1BPP(82 + 320 + 42, 100, BMP_Shiji, WHITE, BLACK); //实际
    LCD_DrawImage1BPP(82 + 320 + 42 + 42, 100, BMP_Wendu, WHITE, BLACK); //温度
    //LCD_DrawImage1BPP(82 + 320 + 42 + 42 + 42 + 2, 100 + 5, BMP_Maohao, WHITE, BLACK); //:
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

    /*
    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 3, BMP_Kongtiao, WHITE, BLACK); //空调
    LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 3, BMP_Zhilen, WHITE, BLACK); //制冷
    LCD_DrawImage1BPP(82 + 320 + 42 + 42, 100 + 38 * 3, BMP_Qingqiu, WHITE, BLACK); //请求
    LCD_DrawImage1BPP(82 + 320 + 42 + 42 + 42 + 2, 100 + 5 + 38 * 3, BMP_Maohao, WHITE, BLACK); //:  
     */
}

void AirUpdate(void) {
    print_D(82 + 180, 100 - 8, Air_Status_Flag1); //空调故障码
    print_D(82 + 180, 100 - 8 + 38, Air_Status_Flag2); //空调风速
    print_D(82 + 180, 100 - 8 + 38 * 2, Air_Status_Flag3); //空调状态
    //print_SZ_1(82 + 270 - 10, 100 - 8 + 38 * 3, AC_LIFE, 3, 0, WHITE); //空调LIFE
    //updata_T(82 + 63 + 42 + 80 + 32 + 320, 100 - 8, WHITE, Air_Indoor_t, 0.5, 30); //室内温度
    //updata_T(82 + 63 + 42 + 80 + 32 + 320, 100 - 8 + 38, WHITE, Air_Outdoor_t, 0.5, 30); //室外温度
    //updata_T(82 + 63 + 42 + 80 + 32 + 320, 100 - 8 + 38 * 2, WHITE, Air_Set_t, 0.5, 30); //设定温度

    updata_DAT(82 + 63 + 42 + 80 + 32 + 320, 100 - 8, Air_Indoor_t, 0.5, 30, WHITE, 3, 0);
    updata_DAT(82 + 63 + 42 + 80 + 32 + 320, 100 - 8 + 38, Air_Outdoor_t, 0.5, 30, WHITE, 3, 0);
    updata_DAT(82 + 63 + 42 + 80 + 32 + 320, 100 - 8 + 38 * 2, Air_Set_t, 0.5, 30, WHITE, 3, 0);
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

void frmSET(void) {


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
            frmMOTO();
            break;
        case 3:
            //frmBCU_f();
            frmDMQ();
            break;
        case 4:
            //frmBCU_m();
            frmDCDC();
            break;
        case 5:
            //frmBCU_r();
            frmDMY();
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
            frmIC();
            break;
        case 10:
            frmBCU_f();
            break;
        case 11:
            frmBCU_m();
            break;
        case 12:
            //frmBCU_r();
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



