#include "SYSTEM.h"
#include "FONT.h"
//#include "LOGO.h"

unsigned char Index = 0;
unsigned char t = 0;
unsigned char t_add = 0;
unsigned char frmID = 0;
unsigned char f_index = 0;
unsigned char menuid = 0;
unsigned char AV_CH = 0;
unsigned char color_old[35] = {};

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
    LCD_DrawRect(136, 128+64, 528, 1, GRAY);
    for (i = 1; i < 10; i++) {
        LCD_DrawRect(70 + 66 * i, 64, 1, 128, GRAY);
    }
    //每次进入主界面，符号片颜色都是灰色，若不处理，只会第一次上电显示灰色，翻页后就不显示灰色
    for (i = 0; i < 35; i++) {
        color_old[i] = 0;
    }
    LCD_DrawRect(0, 430, 800, 1, WHITE); //底部横线
    //LCD_DrawRect(0,70,800,3,YELLOW); //顶部横线
    // LCD_DrawImage1BPPZOOM_4(336, 150, BMP_LOGO, BLUE, BLACK); //客车车标
    //动力电池电流 电压 SOC 外观
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
    LCD_DrawImage1BPP(660, 155 + 60 + 60, BMP_BAIFENHAO, WHITE, BLACK);
*/
    LCD_DrawImage1BPP(180 - 20 + 2, 365 - 50 + 10 - 38 * 3, BMP_DC, WHITE, BLACK); //电池
    LCD_DrawImage1BPP(180 - 20 + 2 + 42, 365 - 50 + 10 - 38 * 3, BMP_DY, WHITE, BLACK); //电压
    LCD_DrawImage1BPP(225 + 83 + 83 - 22, 365 - 50 + 10 - 38 * 3, BMP_v, WHITE, BLACK); //V
    
    LCD_DrawImage1BPP(180 - 20 + 2, 365 - 50 + 10 - 38, BMP_DC, WHITE, BLACK); //电池
    LCD_DrawImage1BPP(180 - 20 + 2 + 42, 365 - 50 + 10 - 38, BMP_DL, WHITE, BLACK); //电流
    LCD_DrawImage1BPP(225 + 83 + 83 - 22, 365 - 50 + 10 - 38, BMP_a, WHITE, BLACK); //A
    
    LCD_DrawImage1BPP(180 - 20 + 2, 365 - 50 + 10, BMP_DC, WHITE, BLACK); //电池
    LCD_DrawImage1BPP(180 - 20 + 2 + 42, 365 - 50 + 10, BMP_Junheng, WHITE, BLACK); //均衡
    LCD_DrawImage1BPP(180 - 20 + 2 + 42 + 21, 365 - 50 + 10, BMP_Wendu, WHITE, BLACK); //温度
    LCD_DrawRect(180 - 20 + 2 + 42 + 42, 365 - 50 + 10, 21, 20, BLACK);
    LCD_DrawImage1BPP(225 + 83 + 83 - 22, 365 - 50 + 10, BMP_T, WHITE, BLACK); //℃

    LCD_DrawImage1BPP(225 + 83 + 83 + 2, 365 - 50 + 10, BMP_DJ, WHITE, BLACK); //电机
    LCD_DrawImage1BPP(225 + 83 + 83 + 2 + 42, 365 - 50 + 10, BMP_Zhuansu, WHITE, BLACK); //转速
    print_SZ_1(225 + 83 + 83 + 2 + 42 + 42, 365 - 50 + 10 - 8, 1, 1, 0, WHITE); //1
    LCD_DrawImage1BPP(615 - 34+20, 365 - 50 + 10, BMP_RPM, WHITE, BLACK); //RPM

    LCD_DrawImage1BPP(180 - 20 + 2, 365 - 50 + 10 + 38, BMP_m, WHITE, BLACK); //M
    LCD_DrawImage1BPP(180 - 20 + 2 + 11, 365 - 50 + 10 + 38, BMP_c, WHITE, BLACK); //C
    LCD_DrawImage1BPP(180 - 20 + 2 + 11 + 11, 365 - 50 + 10 + 38, BMP_u, WHITE, BLACK); //U
    LCD_DrawImage1BPP(180 - 20 + 2 + 11 + 11 + 11, 365 - 50 + 10 + 38, BMP_Wendu, WHITE, BLACK); //温度
    print_SZ_1(180 - 20 + 2 + 11 + 11 + 11 + 42, 365 - 50 + 10 - 8+38, 1, 1, 0, WHITE); //1
    LCD_DrawImage1BPP(225 + 83 + 83 - 22, 365 - 50 + 10 + 38, BMP_T, WHITE, BLACK); //℃

    LCD_DrawImage1BPP(225 + 83 + 83 + 2, 365 - 50 + 10 + 38 * 2, BMP_DJ, WHITE, BLACK); //电机
    LCD_DrawImage1BPP(225 + 83 + 83 + 2 + 42, 365 - 50 + 10 + 38 * 2, BMP_Wendu, WHITE, BLACK); //温度
    print_SZ_1(225 + 83 + 83 + 2 + 42 + 42, 365 - 50 + 10 - 8+38*2, 1, 1, 0, WHITE); //1
    LCD_DrawImage1BPP(615 - 23+20, 365 - 50 + 10 + 38 * 2, BMP_T, WHITE, BLACK); //℃

    LCD_DrawImage1BPP(225 + 83 + 83 + 2, 365 - 50 + 10 + 38, BMP_DJ, WHITE, BLACK); //电机
    LCD_DrawImage1BPP(225 + 83 + 83 + 2 + 42, 365 - 50 + 10 + 38, BMP_DL, WHITE, BLACK); //电流
    print_SZ_1(225 + 83 + 83 + 2 + 42 + 42, 365 - 50 + 10 - 8+38, 1, 1, 0, WHITE); //1
    LCD_DrawImage1BPP(615 - 18+20, 365 - 50 + 10 + 38, BMP_a, WHITE, BLACK); //A
    
    
    
    LCD_DrawImage1BPP(225 + 83 + 83 + 2, 365 - 50 + 10-38*3, BMP_DJ, WHITE, BLACK); //电机
    LCD_DrawImage1BPP(225 + 83 + 83 + 2 + 42, 365 - 50 + 10-38*3, BMP_Zhuansu, WHITE, BLACK); //转速
    print_SZ_1(225 + 83 + 83 + 2 + 42 + 42, 365 - 50 + 10 - 8-38*3, 2, 1, 0, WHITE); //2
    LCD_DrawImage1BPP(615 - 34+20, 365 - 50 + 10-38*3, BMP_RPM, WHITE, BLACK); //RPM

    LCD_DrawImage1BPP(180 - 20 + 2, 365 - 50 + 10 + 38-38*3, BMP_m, WHITE, BLACK); //M
    LCD_DrawImage1BPP(180 - 20 + 2 + 11, 365 - 50 + 10 + 38-38*3, BMP_c, WHITE, BLACK); //C
    LCD_DrawImage1BPP(180 - 20 + 2 + 11 + 11, 365 - 50 + 10 + 38-38*3, BMP_u, WHITE, BLACK); //U
    LCD_DrawImage1BPP(180 - 20 + 2 + 11 + 11 + 11, 365 - 50 + 10 + 38-38*3, BMP_Wendu, WHITE, BLACK); //温度
    print_SZ_1(180 - 20 + 2 + 11 + 11 + 11 + 42, 365 - 50 + 10 - 8+38-38*3, 2, 1, 0, WHITE); //2
    LCD_DrawImage1BPP(225 + 83 + 83 - 22, 365 - 50 + 10 + 38-38*3, BMP_T, WHITE, BLACK); //℃

    LCD_DrawImage1BPP(225 + 83 + 83 + 2, 365 - 50 + 10 + 38 * 2 - 38 * 3, BMP_DJ, WHITE, BLACK); //电机
    LCD_DrawImage1BPP(225 + 83 + 83 + 2 + 42, 365 - 50 + 10 + 38 * 2 - 38 * 3, BMP_Wendu, WHITE, BLACK); //温度
    print_SZ_1(225 + 83 + 83 + 2 + 42 + 42, 365 - 50 + 10 - 8 + 38 * 2 - 38 * 3, 2, 1, 0, WHITE); //2
    LCD_DrawImage1BPP(615 - 23+20, 365 - 50 + 10 + 38 * 2-38*3, BMP_T, WHITE, BLACK); //℃

    LCD_DrawImage1BPP(225 + 83 + 83 + 2, 365 - 50 + 10 + 38-38*3, BMP_DJ, WHITE, BLACK); //电机
    LCD_DrawImage1BPP(225 + 83 + 83 + 2 + 42, 365 - 50 + 10 + 38-38*3, BMP_DL, WHITE, BLACK); //电流
    print_SZ_1(225 + 83 + 83 + 2 + 42 + 42, 365 - 50 + 10 - 8+38-38*3, 2, 1, 0, WHITE); //2
    LCD_DrawImage1BPP(615 - 18+20, 365 - 50 + 10 + 38-38*3, BMP_a, WHITE, BLACK); //A

    LCD_DrawImage1BPP(615 - 34 + 20 + 50 + 42, 365 - 50 + 10 - 38 * 3, BMP_Baifenhao, WHITE, BLACK); //%

    LCD_DrawImage1BPP(615 - 23 + 20 + 36, 365 - 50 + 10 + 38 * 2, BMP_s, WHITE, BLACK); //S
    LCD_DrawImage1BPP(615 - 23 + 20 + 36 + 11, 365 - 50 + 10 + 38 * 2, BMP_o, WHITE, BLACK); //O
    LCD_DrawImage1BPP(615 - 23 + 20 + 36 + 11 + 11, 365 - 50 + 10 + 38 * 2, BMP_c, WHITE, BLACK); //C

    //SOC框体
    LCD_DrawRect(615 + 20 + 10, 365 - 50 - 38 * 2, 2, 230 - 38 * 2, WHITE);
    LCD_DrawRect(615 + 20 + 10, 365 - 50 - 38 * 2, 38, 2, WHITE);
    LCD_DrawRect(615 + 20 + 10 + 38, 365 - 50 - 38 * 2, 2, 230 - 38*2, WHITE);
    LCD_DrawRect(615 + 20 + 10, 365 - 50 - 38 * 2 + 230 - 38 * 2, 40, 2, WHITE);
    
    //LCD_DrawImage1BPP(225 + 83 + 83 + 2+ 11 + 11 + 11 + 2, 365 - 50 + 10 + 38*2, BMP_Maohao, WHITE, BLACK); //:

    //框框
    for (i = 0; i < 6; i++)
        LCD_DrawRect(180 - 20, 365 - 50 - 38 * 3 + 38 * i, 350 + 85 + 20+20, 1, WHITE);
    LCD_DrawRect(180 - 20, 365 - 50 - 38 * 3, 1, 230, WHITE);
    LCD_DrawRect(225 + 83 + 83, 365 - 50 - 38 * 3, 1, 230, WHITE);
    LCD_DrawRect(615 + 20, 365 - 50 - 38 * 3, 1, 230, WHITE);
    //LCD_DrawRect(180 - 20, 365 - 50 + 38, 350 + 85 + 20, 1, WHITE);
    //LCD_DrawRect(180 - 20, 365 - 50 + 38 + 38, 350 + 85 + 20, 1, WHITE);

    //LCD_DrawImage1BPPZOOM_4(100, 150 + 70 + 60 + 45 + 50, BMP_DW, WHITE, BLACK); //档位

    //气压柱1外观
    //方框
    LCD_DrawRect(33, 100, 51, 3, WHITE); //
    LCD_DrawRect(33, 100, 3, 135, WHITE);
    LCD_DrawRect(83+1, 100, 3, 135, WHITE);

    LCD_DrawRect(33, 235, 3, 135, RED);
    LCD_DrawRect(83+1, 235, 3, 138, RED);
    LCD_DrawRect(33, 370, 51, 3, RED); //

    //标尺
    LCD_DrawImage1BPP(13, 95, BMP_SZ[1], RED, BLACK); //1
    LCD_DrawImage1BPP(21, 95, BMP_SZ[0], RED, BLACK); //0
    LCD_DrawImage1BPP(21, 225, BMP_SZ[5], RED, BLACK); //5
    LCD_DrawImage1BPP(21, 360, BMP_SZ[0], RED, BLACK); //0

    LCD_DrawImage1BPP(33 - 7 + 32, 410, Bmp_Mpa, WHITE, BLACK); //Mpa

    //气压柱2外观
    LCD_DrawRect(712, 100, 51, 3, WHITE);
    LCD_DrawRect(712, 100, 3, 135, WHITE);
    LCD_DrawRect(712 + 51, 100, 3, 135, WHITE);

    LCD_DrawRect(712, 235, 3, 135, RED);
    LCD_DrawRect(712 + 51, 235, 3, 138, RED);
    LCD_DrawRect(712, 370, 51, 3, RED); //

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

    LCD_DrawImage1BPPZOOM_4(210-16, 440, BMP_HZ_KM, WHITE, BLACK); //单位 Km

    LCD_DrawImage1BPP(240 + 300 + 30, 440 + 3, Bmp_TRIP, YELLOW, BLACK); //单次里程 TRIF
    //print_SZ_4(240+80+4,440,9999,4,1,WHITE);
    LCD_DrawImage1BPPZOOM_4(404 + 336 + 30, 440, BMP_HZ_KM, WHITE, BLACK); //单位 Km
}

void disp_miles(void) {//显示里程
    print_SZ_1(2 + 64 + 4 + 10, 440 - 2, total_miles/10, 7, 0, WHITE);
    print_SZ_1(240 + 80 + 4 + 330 + 30-16, 440 - 2, single_miles, 5, 1, WHITE);
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

    if ((moto_warn || (MCU_offline_warn==1))) color = RED;
    else color = GRAY;
    if (color_old[0] != color) {
        color_old[0] = color;
        LCD_DrawImage1BPP(6, 10, Bmp_baojing[18], color, BLACK); //电机故障
    }

    if (IN2) color = RED;
    //else if (IN28 && M_ON) color = GRAY;
    else color = GRAY;
    if (color_old[1] != color) {
        color_old[1] = color;
        LCD_DrawImage1BPP(6 + 66, 10, Bmp_baojing[2], color, BLACK); //前门开
    }

    if (IN3) color = RED;
    //else if (IN26 && M_ON) color = GRAY;
    else color = GRAY;
    if (color_old[2] != color) {
        color_old[2] = color;
        LCD_DrawImage1BPP(6 + 66 * 2, 10, Bmp_baojing[3], color, BLACK); //后门开
    }

    if (BMS_SOC<20) color = YELLOW;
    else color = GRAY;
    if (color_old[3] != color) {
        color_old[3] = color;
        LCD_DrawImage1BPP(6 + 66 * 3, 10, Bmp_baojing[9], color, BLACK); //充电确认
    }

    if ((rKL8 || rKL9)) color = RED;
    else color = GRAY;
    if (color_old[4] != color) {
        color_old[4] = color;
        LCD_DrawImage1BPP(6 + 66 * 4, 10, Bmp_baojing[17], color, BLACK); //门外断气
    }
    if (rKL8)
        print_SZ(6 + 66 * 4 + 55, 8, 1, 1, 0, RED);
    else print_SZ(6 + 66 * 4 + 55, 8, 1, 1, 0, GRAY);

    if (rKL9)
        print_SZ(6 + 66 * 4 + 55, 5 + 42, 2, 1, 0, RED);
    else print_SZ(6 + 66 * 4 + 55, 5 + 42, 2, 1, 0, GRAY);
    

    if(fail_mode || Lamp_status_RED)
        color = RED;
    else if ((mil_lamp_request==1) || (Lamp_status_YELLOW==1))
        color = YELLOW;   
    else color = GRAY;
    if (color_old[5] != color) {
        color_old[5] = color;
        LCD_DrawImage1BPP(6 + 66 * 5, 10+8, Bmp_STOP, color, BLACK); //STOP        
    }

    if (IN31) color = YELLOW;
    else color = GRAY;
    if (color_old[6] != color) {
        color_old[6] = color;
        LCD_DrawImage1BPP(6 + 66 * 6, 10, Bmp_baojing[5], color, BLACK); //空滤
    }

    if (IN19) color = GREEN;
    else color = GRAY;
    if (color_old[7] != color) {
        color_old[7] = color;
        LCD_DrawImage1BPP(6 + 66 * 7, 10, Bmp_baojing[16], color, BLACK); //小灯
    }

    if (rKL7) color = RED;
    else color = GRAY;
    if (color_old[8] != color) {
        color_old[8] = color;
        LCD_DrawImage1BPP(6 + 66 * 8, 10, Bmp_baojing[7], color, BLACK); //后舱门
    }

    if ((!rKL5 || !rKL10)) color = RED;
    else color = GRAY;
    if (color_old[9] != color) {
        color_old[9] = color;
        LCD_DrawImage1BPP(6 + 66 * 9, 10, Bmp_baojing[6], color, BLACK); //水位
    }
    if (!rKL5)
        print_SZ(6 + 66 * 9 + 55, 8, 1, 1, 0, RED);
    else print_SZ(6 + 66 * 9 + 55, 8, 1, 1, 0, GRAY);

    if (!rKL10)
        print_SZ(6 + 66 * 9 + 55, 5 + 42, 2, 1, 0, RED);
    else print_SZ(6 + 66 * 9 + 55, 5 + 42, 2, 1, 0, GRAY);
    
    if ((pSpeed > 69)) color = YELLOW;
    else color = GRAY;
    if (color_old[10] != color) {
        color_old[10] = color;
        LCD_DrawImage1BPP(16 + 66 * 10, 10, BMP_Chaosu, color, BLACK); //超速
        LCD_DrawImage1BPP(16 + 66 * 10, 10+22, BMP_Baojing, color, BLACK); //报警
    }

    if (battle_t_warn) color = RED;
    else color = GRAY;
    if (color_old[11] != color) {
        color_old[11] = color;
        LCD_DrawImage1BPP(6 + 66 * 11, 10, Bmp_baojing[11], color, BLACK); //动力电池过温
    }
       
    if ( Hybrid_forbid && !Electric)  
        color = GREEN;
    else 
        color = GRAY;
    if (color_old[12] != color) {
        color_old[12] = color;
        if( color == GREEN ){
        LCD_DrawImage1BPP(138 + 9, 74, BMP_Changgui, color, BLACK); //常规
        LCD_DrawImage1BPP(138 + 9, 74 + 22, BMP_Mode, color, BLACK); //模式
        }
    }
    
    if ( !Hybrid_forbid && !Electric )  
        color = GREEN;
    else 
        color = GRAY;
    if (color_old[13] != color) {
        color_old[13] = color;
        if( color == GREEN ){
        LCD_DrawImage1BPP(138 + 9, 74, BMP_Hundong, color, BLACK); //混动
        LCD_DrawImage1BPP(138 + 9, 74 + 22, BMP_Mode, color, BLACK); //模式
        }
    }
    
    if (Electric) 
        color = GREEN;
    else 
        color = GRAY;
    if (color_old[14] != color) {
        color_old[14] = color;
        if( color == GREEN ){
        LCD_DrawImage1BPP(138 + 9, 74, BMP_Diandong, color, BLACK); //电动
        LCD_DrawImage1BPP(138 + 9, 74 + 22, BMP_Mode, color, BLACK); //模式
        }
    }
             
 
    /*
    if (Tradition && M_ON) color_mode[0] = GREEN;
    else color_mode[0] = GRAY;
    if (color_old[12] != color_mode[0]) {
        color_old[12] = color_mode[0];
        LCD_DrawImage1BPP(138 + 9, 74, BMP_Chuantong, color_mode[0], BLACK); //传统
        LCD_DrawImage1BPP(138 + 9, 74 + 22, BMP_Mode, color_mode[0], BLACK); //模式
    }
    
    if (Hybrid && M_ON) color_mode[1] = GREEN;
    else color_mode[1] = GRAY;
    if (color_old[13] != color_mode[1]) {
        color_old[13] = color_mode[1];
        LCD_DrawImage1BPP(138 + 9, 74, BMP_Chadian, color_mode[1], BLACK); //插电
        LCD_DrawImage1BPP(138 + 9, 74 + 22, BMP_Mode, color_mode[1], BLACK); //模式
    }

    if (Electric && M_ON) color_mode[2] = GREEN;
    else color_mode[2] = GRAY;
    if (color_old[14] != color_mode[2]) {
        color_old[14] = color_mode[2];
        LCD_DrawImage1BPP(138 + 9, 74, BMP_Chundian, color_mode[2], BLACK); //纯电
        LCD_DrawImage1BPP(138 + 9, 74 + 22, BMP_Mode, color_mode[2], BLACK); //模式
    }
    */
    if (battle_higtv1_warn || battle_higtv2_warn || (BMS_offline_warn==1)) color = RED;
    else color = GRAY;
    if (color_old[15] != color) {
        color_old[15] = color;
        LCD_DrawImage1BPP(138 + 66 * 1, 74, Bmp_baojing[10], color, BLACK); //动力电池故障
    }

    if (fail_mode) color = RED;
    else if (mil_lamp_request)
        color=YELLOW;
    else color = GRAY;
    if (color_old[16] != color) {
        color_old[16] = color;
        LCD_DrawImage1BPP(138 + 66 * 2, 74, Bmp_baojing[12], color, BLACK); //系统故障
    }

    if (moto_ready) color = GREEN;
    else color = GRAY;
    if (color_old[17] != color) {
        color_old[17] = color;
        LCD_DrawImage1BPP(138 + 66 * 3 + 2, 74 + 12, BMP_r, color, BLACK); //R
        LCD_DrawImage1BPP(138 + 66 * 3 + 2 + 11, 74 + 12, BMP_e, color, BLACK); //E        
        LCD_DrawImage1BPP(138 + 66 * 3 + 2 + 11 + 11, 74 + 12, BMP_a, color, BLACK); //A
        LCD_DrawImage1BPP(138 + 66 * 3 + 2 + 11 + 11 + 11, 74 + 12, BMP_d, color, BLACK); //D  
        LCD_DrawImage1BPP(138 + 66 * 3 + 2 + 11 + 11 + 11 + 11, 74 + 12, BMP_y, color, BLACK); //Y  
    }

    if (moto_t_warn) color = RED;
    else color = GRAY;
    if (color_old[18] != color) {
        color_old[18] = color;
        LCD_DrawImage1BPP(138 + 66 * 4, 74, Bmp_baojing[13], color, BLACK); //电机过温
    }
  
    if (!fKL2) color = RED;
    else color = GRAY;
    if (color_old[19] != color) {
        color_old[19] = color;
        LCD_DrawImage1BPP(138 + 66 * 5, 74, Bmp_baojing[15], color, BLACK); //左刹车片磨损
    }
    
    if (!fKL3) color = RED;
    else color = GRAY;
    if (color_old[20] != color) {
        color_old[20] = color;
        LCD_DrawImage1BPP(138 + 66 * 6, 74, Bmp_baojing[14], color, BLACK); //右刹车片磨损
    }
    
    if (battle_jueyuan_warn) color = RED;
    else color = GRAY;
    if (color_old[21] != color) {
        color_old[21] = color;
        LCD_DrawImage1BPP(138 + 66 * 7, 74, Bmp_baojing[19], color, BLACK); //绝缘故障
    }
    
    if (Lamp_status_RED || (TCU_offline_warn==1)) color = RED;
    else if(Lamp_status_YELLOW) color = YELLOW;
    else color = GRAY;
    if (color_old[22] != color) {
        color_old[22] = color;
        LCD_DrawImage1BPP(6 + 66 * 2, 10+64*2, Bmp_baojing[20], color, BLACK); //变速箱故障
    }
    
    if ( DC_DC_code.byte) color = RED;
    else color = GRAY;
    if (color_old[23] != color) {
        color_old[23] = color;
        LCD_DrawImage1BPP(138 + 2 + 66, 10 + 64 * 2, BMP_d, color, BLACK); //D
        LCD_DrawImage1BPP(138 + 2 + 66 + 11, 10 + 64 * 2, BMP_c, color, BLACK); //C
        LCD_DrawImage1BPP(138 + 2 + 66 + 11 + 11, 10 + 64 * 2, BMP_I, color, BLACK); // /
        LCD_DrawImage1BPP(138 + 2 + 66 + 11 + 11 + 11, 10 + 64 * 2, BMP_d, color, BLACK); //D
        LCD_DrawImage1BPP(138 + 2 + 66 + 11 + 11 + 11 + 11, 10 + 64 * 2, BMP_c, color, BLACK); //C      
    }
    
    if ( DC_AC_code.byte) color = RED;
    else color = GRAY;
    if (color_old[32] != color) {
        color_old[32] = color;
        LCD_DrawImage1BPP(138 + 2 + 66, 10 + 64 * 2 + 22, BMP_d, color, BLACK); //D
        LCD_DrawImage1BPP(138 + 2 + 66 + 11, 10 + 64 * 2 + 22, BMP_c, color, BLACK); //C
        LCD_DrawImage1BPP(138 + 2 + 66 + 11 + 11, 10 + 64 * 2 + 22, BMP_I, color, BLACK); // /
        LCD_DrawImage1BPP(138 + 2 + 66 + 11 + 11 + 11, 10 + 64 * 2 + 22, BMP_a, color, BLACK); //A
        LCD_DrawImage1BPP(138 + 2 + 66 + 11 + 11 + 11 + 11, 10 + 64 * 2 + 22, BMP_c, color, BLACK); //C
    }

    if (IN5) color = YELLOW;
    else color = GRAY;
    if (color_old[24] != color) {
        color_old[24] = color;
        LCD_DrawImage1BPP(138 + 9 + 66 * 2, 10 + 64 * 2, BMP_Jiting, color, BLACK); //急停
        LCD_DrawImage1BPP(138 + 9 + 66 * 2, 10 + 22 + 64 * 2, BMP_Zhishi, color, BLACK); //指示
    }
    
    if (Daisujingzhi) color = YELLOW;
    else color = BLACK;
    if (color_old[25] != color) {
        color_old[25] = color;
        LCD_DrawImage1BPP(138 + 9 - 40, 10 + 64 * 3, BMP_Tingji, color, BLACK); //停机
        LCD_DrawImage1BPP(138 + 9 - 40, 10 + 22 + 64 * 3, BMP_Jinzhi, color, BLACK); //禁止
    }

    if (Eng_static_test) color = YELLOW;
    else color = BLACK;
    if (color_old[30] != color) {
        color_old[30] = color;
        LCD_DrawImage1BPP(138 + 9 - 40, 10 + 64 * 4, BMP_Sudu, color, BLACK); //速度
        LCD_DrawImage1BPP(138 + 9 - 40, 10 + 22 + 64 * 4, BMP_Ceshi, color, BLACK); //测试
    }

    if (Zichong) color = YELLOW;
    else color = GRAY;
    if (color_old[31] != color) {
        color_old[31] = color;
        LCD_DrawImage1BPP(138 + 9 + 66 * 3, 10 + 64 * 2, BMP_Zhuche, color, BLACK); //驻车
        LCD_DrawImage1BPP(138 + 9 + 66 * 3, 10 + 22 + 64 * 2, BMP_Zichong, color, BLACK); //自充
    }
    
    if ( ABS_lamp) color = YELLOW;
    else color = GRAY;
    if (color_old[26] != color) {
        color_old[26] = color;
        LCD_DrawImage1BPP(6 + 66 * 6, 10+64*2, Bmp_baojing[1], color, BLACK); //ABS
    }
    
    if (rPOUT.BITS.O1 && (rPF[0] == 0)) color = GREEN;
    else color = GRAY;
    if (color_old[27] != color) {
        color_old[27] = color;
        LCD_DrawImage1BPP(6 + 66 * 7, 10+64*2, Bmp_baojing[4], color, BLACK); //干燥
    }
    
    if (rKL11) color = RED;
    else color = GRAY;
    if (color_old[28] != color) {
        color_old[28] = color;
        LCD_DrawImage1BPP(6 + 66 * 8, 10+64*2, Bmp_baojing[21], color, BLACK); //仓温
    }
    
    if (rADR[0] <= 331) color = RED;
    else color = GRAY;
    if (color_old[29] != color) {
        color_old[29] = color;
        LCD_DrawImage1BPP(6 + 66 * 9, 10+64*2, Bmp_baojing[22], color, BLACK); //电池仓温
    }
    
}
/*
void disp_SPN_FMI(unsigned int x, unsigned int y, unsigned char len, DM1 id) {
    static unsigned char al_index = 0;
    ////////3S 更新一次  
    switch (al_index) {
        case 0:
            if (len >= 6) {
                DM(1, id);
                print_SZ_1(x, y, hcu_spn, 6, 0, GREEN);
                print_SZ_1(x + 100, y, hcu_fmi, 3, 0, GREEN);
                if (alarm_update_flag1 == 1) {
                    alarm_update_flag1 = 0;
                    al_index = 1;
                }
                break;
            }
            


        case 1:
            if (len >= 10) {
                DM(2, id);
                print_SZ_1(x, y, hcu_spn, 6, 0, GREEN);
                print_SZ_1(x + 100, y, hcu_fmi, 3, 0, GREEN);
                if (alarm_update_flag1 == 1) {
                    alarm_update_flag1 = 0;
                    al_index = 2;
                }
                break;
            }
            

        case 2:
            if (len >= 14) {
                DM(3, id);
                print_SZ_1(x, y, hcu_spn, 6, 0, GREEN);
                print_SZ_1(x + 100, y, hcu_fmi, 3, 0, GREEN);
                if (alarm_update_flag1 == 1) {
                    alarm_update_flag1 = 0;
                    al_index = 3;
                }
                 
            }
           break;


        case 3:

            if (len >= 18) {
                DM(4, id);
                print_SZ_1(x, y, hcu_spn, 6, 0, GREEN);
                print_SZ_1(x + 100, y, hcu_fmi, 3, 0, GREEN);
                if (alarm_update_flag1 == 1) {
                    alarm_update_flag1 = 0;
                    al_index = 4;
                }
                break;
            }
            

        case 4:

            if (len >= 22) {
                DM(5, id);
                print_SZ_1(x, y, hcu_spn, 6, 0, GREEN);
                print_SZ_1(x + 100, y, hcu_fmi, 3, 0, GREEN);
                if (alarm_update_flag1 == 1) {
                    alarm_update_flag1 = 0;
                    al_index = 5;
                }
                break;
            }
            

        case 5:

            if (len >= 26) {
                DM(6, id);
                print_SZ_1(x, y, hcu_spn, 6, 0, GREEN);
                print_SZ_1(x + 100, y, hcu_fmi, 3, 0, GREEN);
                if (alarm_update_flag1 == 1) {
                    alarm_update_flag1 = 0;
                    al_index = 6;
                }
                break;
            }
            
        case 6:

            if (len >= 30) {
                DM(7, id);
                print_SZ_1(x, y, hcu_spn, 6, 0, GREEN);
                print_SZ_1(x + 100, y, hcu_fmi, 3, 0, GREEN);
                if (alarm_update_flag1 == 1) {
                    alarm_update_flag1 = 0;
                    al_index = 7;
                }
                break;
            }
            

        case 7:

            if (len >= 34) {
                DM(8, id);
                print_SZ_1(x, y, hcu_spn, 6, 0, GREEN);
                print_SZ_1(x + 100, y, hcu_fmi, 3, 0, GREEN);
                if (alarm_update_flag1 == 1) {
                    alarm_update_flag1 = 0;
                    al_index = 8;
                }
                break;
            }
            
        default:
            al_index = 0;
            break;
    }
}
 */
void disp_SPN_FMI_1(unsigned int x, unsigned int y, unsigned char len, DM1 id) {
    static unsigned char al_index = 0;
    ////////3S 更新一次  
    if (alarm_update_flag1 == 0) { //3S 更新一次  
        switch (al_index) {
            case 0:
                al_index = 1;
                if (len >= 6) {
                    DM(1, id);
                    print_SZ_1(x, y, SPN, 6, 0, GREEN);
                    print_SZ_1(x + 100, y, FMI, 3, 0, GREEN);
                    alarm_update_flag1 = 1;
                    break;
                }
                
            case 1:
                al_index = 2;
                if (len >= 10) {
                    DM(2, id);
                    print_SZ_1(x, y, SPN, 6, 0, GREEN);
                    print_SZ_1(x + 100, y, FMI, 3, 0, GREEN);
                    alarm_update_flag1 = 1;
                    break;
                }

            case 2:
                al_index = 3;
                if (len >= 14) {
                    DM(3, id);
                    print_SZ_1(x, y, SPN, 6, 0, GREEN);
                    print_SZ_1(x + 100, y, FMI, 3, 0, GREEN);
                    alarm_update_flag1 = 1;
                    break;
                }

            case 3:
                al_index = 4;
                if (len >= 18) {
                    DM(4, id);
                    print_SZ_1(x, y, SPN, 6, 0, GREEN);
                    print_SZ_1(x + 100, y, FMI, 3, 0, GREEN);
                    alarm_update_flag1 = 1;
                    break;
                }

            case 4:
                al_index = 5;
                if (len >= 22) {
                    DM(5, id);
                    print_SZ_1(x, y, SPN, 6, 0, GREEN);
                    print_SZ_1(x + 100, y, FMI, 3, 0, GREEN);
                    alarm_update_flag1 = 1;
                    break;
                }

            case 5:
                al_index = 6;
                if (len >= 26) {
                    DM(6, id);
                    print_SZ_1(x, y, SPN, 6, 0, GREEN);
                    print_SZ_1(x + 100, y, FMI, 3, 0, GREEN);
                    alarm_update_flag1 = 1;
                    break;
                }

            case 6:
                al_index = 7;
                if (len >= 30) {
                    DM(7, id);
                    print_SZ_1(x, y, SPN, 6, 0, GREEN);
                    print_SZ_1(x + 100, y, FMI, 3, 0, GREEN);
                    alarm_update_flag1 = 1;
                    break;
                }

            case 7:
                al_index = 8;
                if (len >= 34) {
                    DM(8, id);
                    print_SZ_1(x, y, SPN, 6, 0, GREEN);
                    print_SZ_1(x + 100, y, FMI, 3, 0, GREEN);
                    alarm_update_flag1 = 1;
                    break;
                }

            default:
                al_index = 0;
                break;
        }
    }
}

void disp_SPN_FMI_2(unsigned int x, unsigned int y, unsigned char len, DM1 id) {
    static unsigned char al_index = 0;
    ////////3S 更新一次  
    if (alarm_update_flag2 == 0) { //3S 更新一次  
        switch (al_index) {
            case 0:
                al_index = 1;
                if (len >= 6) {
                    DM(1, id);
                    print_SZ_1(x, y, SPN, 6, 0, GREEN);
                    print_SZ_1(x + 100, y, FMI, 3, 0, GREEN);
                    alarm_update_flag2 = 1;
                    break;
                }
                
            case 1:
                al_index = 2;
                if (len >= 10) {
                    DM(2, id);
                    print_SZ_1(x, y, SPN, 6, 0, GREEN);
                    print_SZ_1(x + 100, y, FMI, 3, 0, GREEN);
                    alarm_update_flag2 = 1;
                    break;
                }

            case 2:
                al_index = 3;
                if (len >= 14) {
                    DM(3, id);
                    print_SZ_1(x, y, SPN, 6, 0, GREEN);
                    print_SZ_1(x + 100, y, FMI, 3, 0, GREEN);
                    alarm_update_flag2 = 1;
                    break;
                }

            case 3:
                al_index = 4;
                if (len >= 18) {
                    DM(4, id);
                    print_SZ_1(x, y, SPN, 6, 0, GREEN);
                    print_SZ_1(x + 100, y, FMI, 3, 0, GREEN);
                    alarm_update_flag2 = 1;
                    break;
                }

            case 4:
                al_index = 5;
                if (len >= 22) {
                    DM(5, id);
                    print_SZ_1(x, y, SPN, 6, 0, GREEN);
                    print_SZ_1(x + 100, y, FMI, 3, 0, GREEN);
                    alarm_update_flag2 = 1;
                    break;
                }

            case 5:
                al_index = 6;
                if (len >= 26) {
                    DM(6, id);
                    print_SZ_1(x, y, SPN, 6, 0, GREEN);
                    print_SZ_1(x + 100, y, FMI, 3, 0, GREEN);
                    alarm_update_flag2 = 1;
                    break;
                }

            case 6:
                al_index = 7;
                if (len >= 30) {
                    DM(7, id);
                    print_SZ_1(x, y, SPN, 6, 0, GREEN);
                    print_SZ_1(x + 100, y, FMI, 3, 0, GREEN);
                    alarm_update_flag2 = 1;
                    break;
                }

            case 7:
                al_index = 8;
                if (len >= 34) {
                    DM(8, id);
                    print_SZ_1(x, y, SPN, 6, 0, GREEN);
                    print_SZ_1(x + 100, y, FMI, 3, 0, GREEN);
                    alarm_update_flag2 = 1;
                    break;
                }

            default:
                al_index = 0;
                break;
        }
    }
}

void disp_CAN_baojing(unsigned int x, unsigned int y) {
    static unsigned char al_index = 0;
    if (alarm_update_flag == 0) { //3S 更新一次  
        switch (al_index) {
            case 0:
                al_index = 1;
                if (battle_t_warn) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Dongli, YELLOW, BLACK); //动力电池过温
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_DC, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 21, y + 8, BMP_Wendu, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 42, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 1:
                al_index = 2;
                if (battle_jueyuan_warn) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Jueyuan, YELLOW, BLACK); //绝缘故障
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42, y, 84, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
            case 2:
                al_index = 3;
                if (battle_higtv1_warn) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Dongli, YELLOW, BLACK); //动力电池1故障
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_DC, YELLOW, BLACK);
                    print_SZ_1(x + 42 + 42, y, 1, 1, 0, YELLOW);
                    LCD_DrawImage1BPP(x + 42 + 42 + 16, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 3:
                al_index = 4;
                if (battle_higtv2_warn) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Dongli, YELLOW, BLACK); //动力电池2故障
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_DC, YELLOW, BLACK);
                    print_SZ_1(x + 42 + 42, y, 2, 1, 0, YELLOW);
                    LCD_DrawImage1BPP(x + 42 + 42 + 16, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 4:
                al_index = 5;
                if ((moto_t_warn==1) && M_ON) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Dongli, YELLOW, BLACK); //动力电机过温
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_DJ, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Guowen, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 42, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 5:
                al_index = 6;
                if ((moto_warn==1) && M_ON) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DJ, YELLOW, BLACK); //电机系统故障
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_System, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 42, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
            case 6:
                al_index = 7;
                if ((MCU_offline_warn==1) && M_ON) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Dongli, YELLOW, BLACK); //动力系统离线
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_System, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Lixian, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 42, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
            case 7:
                al_index = 8;
                if ((TCU_offline_warn==1) && M_ON) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_a, YELLOW, BLACK); //AMT离线
                    LCD_DrawImage1BPP(x + 11, y + 8, BMP_m, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11, y + 8, BMP_t, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11 + 11, y + 8, BMP_Lixian, YELLOW, BLACK);
                    LCD_DrawRect(x + 11 + 11 + 11 + 42, y, 84, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
            case 8:
                al_index = 9;
                if ((BMS_offline_warn==1) && M_ON) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Dongli, YELLOW, BLACK); //动力电池离线
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_DC, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Lixian, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 42, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
            case 9:
                al_index = 10;
                if (mil_lamp_request) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Hundong, YELLOW, BLACK); //混动系统异常
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_System, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Yichang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 42, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
            case 10:
                al_index = 11;
                if (fail_mode) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Hundong, YELLOW, BLACK); //混动系统故障
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_System, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 42, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
            case 11:
                al_index = 12;
                if (Lamp_status_YELLOW) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_a, YELLOW, BLACK); //AMT异常
                    LCD_DrawImage1BPP(x + 11, y + 8, BMP_m, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11, y + 8, BMP_t, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11 + 11, y + 8, BMP_Yichang, YELLOW, BLACK);
                    LCD_DrawRect(x + 11 + 11 + 11 + 42, y, 84, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 12:
                al_index = 13;
                if (Lamp_status_RED) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_a, YELLOW, BLACK); //AMT故障
                    LCD_DrawImage1BPP(x + 11, y + 8, BMP_m, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11, y + 8, BMP_t, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11 + 11, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 11 + 11 + 11 + 42, y, 84, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 13:
                al_index = 14;
                if (DC_DC_code.byte) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_d, YELLOW, BLACK); //DCDC
                    LCD_DrawImage1BPP(x + 11, y + 8, BMP_c, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11, y + 8, BMP_d, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11 + 11, y + 8, BMP_c, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + +11 + 11 + 11 + 11, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 11 + 11 + 11 + 11 + 42, y, 84, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 14:
                al_index = 15;
                if (DC_AC_code.byte) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_d, YELLOW, BLACK); //DCAC
                    LCD_DrawImage1BPP(x + 11, y + 8, BMP_c, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11, y + 8, BMP_a, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11 + 11, y + 8, BMP_c, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + +11 + 11 + 11 + 11, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 11 + 11 + 11 + 11 + 42, y, 84, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 15:
                al_index = 16;
                if (Fcan_count == CAN_TIME) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Qianbu, YELLOW, BLACK); //前部
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Mokuai, YELLOW, BLACK); //模块
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Lixian, YELLOW, BLACK); //离线
                    LCD_DrawRect(x + 42 + 42 + 42, y, 42, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 16:
                al_index = 17;
                if (rKL6) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Chongdiangai, YELLOW, BLACK); //充电盖未关
                    LCD_DrawRect(x + 42 + 42 + 21, y, 42, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 17:
                al_index = 18;
                if (Rcan_count == CAN_TIME) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Houbu, YELLOW, BLACK); //后部
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Mokuai, YELLOW, BLACK); //模块
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Lixian, YELLOW, BLACK); //离线
                    LCD_DrawRect(x + 42 + 42 + 42, y, 42, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 18:/*
                al_index = 19;
                if (((Status_Flag2 >> 7)&0x01) == 1) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Wendu, YELLOW, BLACK); //温差过大
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_Cha, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 21, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 21 + 21, y + 8, BMP_Da, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 19:
                al_index = 20;
                if (((Status_Flag2 >> 6)&0x01) == 1) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Wendu, YELLOW, BLACK); //温度报警
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 20:
                al_index = 21;
                if (((Status_Flag2 >> 5)&0x01) == 1) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Wendu, YELLOW, BLACK); //温度过高
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 21, y + 8, BMP_Gao, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
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
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
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
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 23:
                al_index = 24;
                if (((Status_Flag2 >> 2)&0x01) == 1) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Jueyuan, YELLOW, BLACK); //绝缘报警
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
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
                    LCD_DrawRect(x + 44 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 25:
                al_index = 26;
                if ((Status_Flag2 & 0x01) == 1) {                    
                    LCD_DrawImage1BPP(x, y + 8, BMP_DC, YELLOW, BLACK); //电池热失控
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Re, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 21, y + 8, BMP_Shikong, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 21 + 42, y, 100, 36, BLACK);
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
                    LCD_DrawRect(x + 42 + 42 + 42 + 21, y, 100, 36, BLACK);
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
                    LCD_DrawRect(x + 42 + 42 + 42 + 21, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
            default:
                al_index = 0;
                LCD_DrawRect(x, y, 200, 36, BLACK); //清除显示区域
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
    press1 = ADR[6] / 40;
    /*press1 = ADR[4] / 27; //电压型采样   0-5V
    press2 = ADR[5] / 27;//电压型采样   0-5V*/
    //阻尼
    if (press1 > update_press1) update_press1++;
    else if (press1 < update_press1)update_press1--;
    else update_press1 = press1;
    
    if (update_press1 > 60) color = GREEN;
    else color = RED;
    if (update_press1 > 100) update_press1 = 100;
    print_SZ(33 - 7, 410, update_press1, 3, 2, color);
    LCD_DrawImage1BPP(33 + 9, 380, Bmp_QY1, color, BLACK); //气压1图标
    LCD_DrawRect(38, 108, 44, (260 - update_press1 * 2.6), BLACK); //260/100  
    if (update_press1 % 5 == 0) {
        LCD_DrawRect(38, (368 - update_press1 * 2.6), 44, (update_press1 * 2.6), color);
    } else {
        LCD_DrawRect(38, (368 - update_press1 * 2.6), 44, (update_press1 * 2.6 + 1), color);
    }

    press2 = ADR[5] / 40;
    //阻尼
    if (press2 > update_press2) update_press2++;
    else if (press2 < update_press2)update_press2--;
    else update_press2 = press2;
    
    if (update_press2 > 60) color = GREEN;
    else color = RED;
    if (update_press2 > 100) update_press2 = 100;
    LCD_DrawImage1BPP(712 + 9, 380, Bmp_QY2, color, BLACK); //气压2图标
    print_SZ(712 - 7, 410, update_press2, 3, 2, color);
    LCD_DrawRect(712 + 5, 108, 44, (260 - update_press2 * 2.6), BLACK); //260/100 
    if (update_press2 % 5 == 0) {         
        LCD_DrawRect(712 + 5, (368 - update_press2 * 2.6), 44, (update_press2 * 2.6), color);
    }else {
        LCD_DrawRect(712 + 5, (368 - update_press2 * 2.6), 44, (update_press2 * 2.6 + 1), color);
    }

}

void updata_Dangwei(unsigned int x, unsigned int y,unsigned int z) {
    unsigned char gear = 1,color;
    gear = Current_Gear-124;
    if (gear > 7) gear = 1;
    if(gear==0) color=RED;
    else if(gear==1) color=WHITE;
    else color=GREEN;
    if(z)
        LCD_DrawImage1BPPZOOM_4(x, y, BMP_DANGWEI[gear], color, BLACK); //档位更新
    else
        LCD_DrawImage1BPP(x, y, BMP_DANGWEI[gear], color, BLACK); //档位更新
}

void updata_SOC(unsigned int x, unsigned int y) {
    unsigned char color = WHITE;
    unsigned char soc = 100;
    soc = BMS_SOC * 0.5;
    if (soc >= 100) soc = 100;
    if (soc > 30) color = GREEN;
    else if (soc >= 20 && soc <= 30) color = YELLOW;
    else if (soc < 20) color = RED;
    else color = BLACK;
    print_SZ_1(x, y, soc, 3, 0, color); //SOC数值
    if (frmID == 0) {
        LCD_DrawRect(615 + 20 + 10 + 2, 365 - 50 - 38 * 2 + 2 + 152 - soc * 1.52, 36, (soc * 1.52), color); // 152/100  
        if (soc < 100)//当soc为100时会出错//此时函数溢出
            LCD_DrawRect(615 + 20 + 10 + 2, 365 - 50 - 38 * 2 + 2, 36, (152 - soc * 1.52), BLACK);
    }
    //if(frmID==0){
    //LCD_DrawRect(225 + 2, 150 + 5 + 60 + 60 + 2, (soc * 3.31), 28, color); // 331/100  
    //if (soc < 100)//当soc为100时会出错//此时函数溢出
    //    LCD_DrawRect((225 + 2 + soc * 3.31), 150 + 5 + 60 + 60 + 2, (331 - soc * 3.31), 28, BLACK);
    //}
}

void updata_DCDY(unsigned int x, unsigned int y) {
    //unsigned char color = GREEN;
    unsigned int DCDY = 50;
    DCDY = BMS_V * 2;
    print_SZ_1(x, y, DCDY, 3, 0, GREEN); //电池电压数值 x=120+72+30   y=150+60-2
    //if (DCDY > 1000 && frmID == 0)
       // LCD_DrawRect(225 + 2, 150 + 5 + 2, ((DCDY - 1000) * 3.31 * 0.125), 28, GREEN); // 331/100  
    //if (DCDY < 1800 && frmID == 0)//当为100时会出错
        //LCD_DrawRect((225 + 2 + (DCDY - 1000) * 3.31 * 0.125), 150 + 5 + 2, (331 - (DCDY - 1000) * 3.31 * 0.125), 28, BLACK);
}

void updata_DJDY(unsigned int x, unsigned int y) {
    unsigned int DJDY = 500;
    DJDY = moto_voltage * 2;
    print_SZ_1(x, y, DJDY, 3, 0, GREEN); //电机电压数值 x=120+72+35   y=250+60-2   
}

void updata_DCDL(unsigned int x, unsigned int y) {
    unsigned int DCDL = 100;
    DCDL = BMS_A * 8;
    if (DCDL < 1000) {
        DCDL = 1000 - DCDL;
        if (DCDL > 500) DCDL = 500;
        print_SZ_1(x, y, DCDL, 3, 0, GREEN);
        LCD_DrawImage1BPPZOOM_4(x - 20, y + 4, BMP_FU, GREEN, BLACK);
        //if (DCDL > 0 && frmID == 0)
            //LCD_DrawRect((225 + 2 + 164 - DCDL * 1.64 * 0.2), 150 + 5 + 2 + 60, (DCDL * 1.64 * 0.2 + 1), 28, GREEN);
        //if (DCDL < 500 && frmID == 0) {
            //LCD_DrawRect(225 + 2, 150 + 5 + 2 + 60, (164 - DCDL * 1.64 * 0.2), 28, BLACK); // 165/100         
            //LCD_DrawRect(225 + 83 + 83 + 2, 150 + 5 + 2 + 60, 165, 28, BLACK);       
    } else {
        DCDL = DCDL - 1000;
        if (DCDL > 500) DCDL = 500;
        LCD_DrawImage1BPPZOOM_4(x - 20, y + 4, BMP_ZHENG, GREEN, BLACK);
        print_SZ_1(x, y, DCDL, 3, 0, GREEN);
        //if (DCDL > 3 && frmID == 0)
            //LCD_DrawRect(225 + 83 + 83 + 2, 150 + 5 + 2 + 60, (DCDL * 1.65 * 0.2), 28, GREEN); // 如果长度为0，会出错
        //if (DCDL < 500 && frmID == 0) {
            //LCD_DrawRect((225 + 83 + 83 + 2 + DCDL * 1.65 * 0.2), 150 + 5 + 2 + 60, (165 - DCDL * 1.65 * 0.2), 28, BLACK);
            //LCD_DrawRect(225 + 2, 150 + 5 + 2 + 60, 164, 28, BLACK);
        }
    }

void updata_DJDL(unsigned int x, unsigned int y,unsigned int c,unsigned int f,unsigned int o) {
    unsigned char color = GREEN;
    unsigned int DJDL = 100;
    DJDL = c * f;
    if (DJDL < o) {
        print_SZ_1(x, y, o - DJDL, 3, 0, color);
        LCD_DrawImage1BPPZOOM_4(x - 40, y + 4, BMP_FU, color, BLACK);
    } else {
        LCD_DrawImage1BPPZOOM_4(x - 40, y + 4, BMP_ZHENG, color, BLACK);
        print_SZ_1(x, y, DJDL-o, 3, 0, color); //电池电流数值 x=135+180+50+100+20+20   y=150+60-2
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

void updata_RMP(unsigned int x, unsigned int y,unsigned int r) {
    unsigned char color = GREEN;
    unsigned int rpm = 80;
    rpm = r * 20;
    //if (rmp < 2000) {
    // LCD_DrawImage1BPPZOOM_4(x - 25, y + 5, BMP_FU, color, BLACK);
    // print_SZ_1(x, y, 2000 - rmp, 4, 0, color); //电流数值
    // } else {
    //     LCD_DrawImage1BPPZOOM_4(x - 25, y + 5, BMP_ZHENG, color, BLACK);
    print_SZ_1(x, y, rpm-2000, 4, 0, color); //电流数值 x=135+180+50+100+20+20   y=250+55
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
    //unsigned char color;
    if (f_index == 0) { //只更新一次
        f_index = 1;
        mainFrame();
    } else if (f_index == 1) {
        f_index = 2;
        updata_QY();
        updata_DJDL(480 + 30 + 16 + 20, 318 + 38,moto_current,4,500);//1
        updata_DJDL(480 + 30 + 16 + 20, 318 + 38-38*3,Motor2_Generatrix_Current,8,1000);//2
        updata_Dangwei(100 - 10, 150 + 65 + 65 + 45 + 35 + 10, 1);
    } else if (f_index == 2) {
        f_index = 3;
        disp_baojing();
        updata_RMP(480 + 30 + 20, 318,moto_speed);//1
        updata_RMP(480 + 30 + 20, 318-38*3,Motor2_Speed);//2
    } else if (f_index == 3) {
        f_index = 4;
        disp_miles();
        updata_DCDL(313, 318-38);
    } else if (f_index == 4) {
        f_index = 5;
        disp_time(330, 440, timer);
        updata_T(313, 318, GREEN, battle_t, 1, 40);
        updata_T(313, 318 + 38, GREEN, Inverter_t, 1, 40);//1
        updata_T(313, 318 + 38-38*3, GREEN, Motor2_Inverter_Temperature, 1, 40);//2
        updata_T(480 + 30 + 16 + 20, 318 + 38 * 2, GREEN, Motor_Temperature, 1, 40);//1
        updata_T(480 + 30 + 16 + 20, 318 + 38 * 2-38*3, GREEN, Motor2_Temperature, 1, 40);//2
    } else if (f_index == 5) {
        f_index = 6;
        updata_SOC(480 + 30 + 20 + 80 + 30, 318 - 38 * 3);
    } else if (f_index == 6) {
        f_index = 7;
        updata_DCDY(313, 318-38*3);
        disp_CAN_baojing(162, 394);
    } else if (f_index == 7) {
        f_index = 1;
    } else {
        f_index = 0;
    }

    if (AV_CH == 0) { //当在数字界面
        if (key_up) { //调节背光灯
            key_up = 0;
            if ((IN19 == 1) && (!time_flag)) {//背光开启
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
            if(time_flag==0){
                f_index = 0;  //更新只更新一次的界面
                frmID = 1;
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
        if (i < 8) {//为控火开关
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
        frmID = 7;
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
        frmID = 9;
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
        frmID = 9;
        f_index = 0;
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
    LCD_DrawRect(0, 430, 800, 2, YELLOW); //底部横线

    LCD_DrawImage1BPP(130, 130, BMP_Control, color, BLACK); //驱动
    LCD_DrawImage1BPP(130 + 50, 130, BMP_STSTEM, color, BLACK); //系统
    LCD_DrawImage1BPP(130 + 50 + 50, 130, BMP_Message, color, BLACK); //信息

    LCD_DrawImage1BPP(130, 130 + 35, BMP_Engine, color, BLACK); //发动机
    LCD_DrawImage1BPP(130 + 75, 130 + 35, BMP_STSTEM, color, BLACK); //系统
    LCD_DrawImage1BPP(130 + 75 + 50, 130 + 35, BMP_Message, color, BLACK); //信息

    LCD_DrawImage1BPP(130, 130 + 35 + 35, BMP_Fuzhu, color, BLACK); //辅助
    LCD_DrawImage1BPP(130 + 50, 130 + 35 + 35, BMP_STSTEM, color, BLACK); //系统
    LCD_DrawImage1BPP(130 + 50 + 50, 130 + 35 + 35, BMP_Message, color, BLACK); //信息

    LCD_DrawImage1BPP(130 + 350, 130, BMP_Battery, color, BLACK); //电池
    LCD_DrawImage1BPP(130 + 350 + 50, 130, BMP_STSTEM, color, BLACK); //系统
    LCD_DrawImage1BPP(130 + 350 + 50 + 50, 130, BMP_Message, color, BLACK); //信息
    
    LCD_DrawImage1BPP(130 + 350, 130 + 35, BMP_IC, color, BLACK); //仪表
    LCD_DrawImage1BPP(130 + 50 + 350, 130 + 35, BMP_STSTEM, color, BLACK); //系统
    LCD_DrawImage1BPP(130 + 50 + 50 + 350, 130 + 35, BMP_Message, color, BLACK); //信息

     
}

void MenuUpdate(void) {
    static unsigned char i = 5;
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
    if (i == 10) i = 5;
    if (i == 0) i = 5;
    //子菜单间切换
    if (i == 5 || i==0) {
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
    if (i == 6 || i==1) {
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
    if (i == 7 || i==2) {
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
    if (i == 8 || i==3) {
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
    LCD_DrawImage1BPP(105 + 350, 131, BMP_Choose, color, BLACK);
    if (i == 9 || i==4) {
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
    LCD_DrawImage1BPP(105 + 350, 131 + 35, BMP_Choose, color, BLACK);   
}

void frmMenu(void) {
    if (f_index == 0) { //只更新一次
        f_index = 1;
        MenuFrame();
    } else if (f_index == 1) {
        f_index = 1;
        MenuUpdate();
        disp_time(330, 440, timer);
    } else {
        f_index = 0;
    }
    /*
        if (key_up) {子菜单间切换
            key_up = 0;
            frmID = 2;
            f_index = 0;
        }
     */
    /*if (key_AV) {
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

void ControlFrame(void) {
    unsigned char i = 0;
    LCD_Clear();
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //顶部横线
    LCD_DrawImage1BPP(130 + 200, 130 - 85, BMP_Control, GREEN, BLACK); //控制
    LCD_DrawImage1BPP(130 + 200 + 50, 130 - 85, BMP_STSTEM, GREEN, BLACK); //系统
    LCD_DrawImage1BPP(130 + 200 + 50 + 50, 130 - 85, BMP_Message, GREEN, BLACK); //信息

    LCD_DrawRect(80, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320 + 320, 90, 1, 380, GREEN);
    for (i = 0; i < 11; i++)
        LCD_DrawRect(80, 90 + i * 38, 640, 1, GREEN);
    
    LCD_DrawImage1BPP(82 , 100, BMP_Youmen, WHITE, BLACK); //油门
    LCD_DrawImage1BPP(82 + 42 , 100, BMP_Taban, WHITE, BLACK); //踏板
    LCD_DrawImage1BPP(82 + 42 + 42 , 100, BMP_Kaidu, WHITE, BLACK); //开度
    LCD_DrawImage1BPP(400 - 24, 100, BMP_Baifenhao, WHITE, BLACK); //%
    
    LCD_DrawImage1BPP(82, 100 + 38, BMP_DJ, WHITE, BLACK); //电机
    LCD_DrawImage1BPP(82 + 42, 100 + 38, BMP_DY, WHITE, BLACK); //电压
    //print_SZ_1(82 + 42 + 42, 100 + 38 - 8, 1, 1, 0, WHITE); //1
    LCD_DrawImage1BPP(400 - 24, 100 + 38, BMP_v, WHITE, BLACK); //V
    
    LCD_DrawImage1BPP(82, 100 + 38*2, BMP_DJ, WHITE, BLACK); //电机
    LCD_DrawImage1BPP(82 + 42, 100 + 38*2, BMP_DL, WHITE, BLACK); //电流
    print_SZ_1(82 + 42 + 42, 100 + 38*2 - 8, 1, 1, 0, WHITE); //1
    LCD_DrawImage1BPP(400 - 24, 100 + 38*2, BMP_a, WHITE, BLACK); //A
    
    LCD_DrawImage1BPP(82, 100 + 38 * 3, BMP_DJ, WHITE, BLACK); //电机
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 3, BMP_Wendu, WHITE, BLACK); //温度
    print_SZ_1(82 + 42 + 42, 100 + 38*3 - 8, 1, 1, 0, WHITE); //1
    LCD_DrawImage1BPP(400 - 28, 100 + 38 * 3, BMP_T, WHITE, BLACK); //℃
    
    LCD_DrawImage1BPP(82, 100 + 38 * 4, BMP_a, WHITE, BLACK); //A
    LCD_DrawImage1BPP(82 + 11, 100 + 38 * 4, BMP_m, WHITE, BLACK); //M
    LCD_DrawImage1BPP(82 + 11 + 11, 100 + 38 * 4, BMP_t, WHITE, BLACK); //T
    LCD_DrawImage1BPP(82 + 11 + 11 + 11, 100 + 38 * 4, BMP_Dangwei, WHITE, BLACK); //档位
    
    LCD_DrawImage1BPP(82, 100 + 38 * 5, BMP_a, WHITE, BLACK); //A
    LCD_DrawImage1BPP(82 + 11, 100 + 38 * 5, BMP_m, WHITE, BLACK); //M
    LCD_DrawImage1BPP(82 + 11 + 11, 100 + 38 * 5, BMP_t, WHITE, BLACK); //T
    LCD_DrawImage1BPP(82 + 11 + 11 + 11, 100 + 38 * 5, BMP_Zhuangtai, WHITE, BLACK); //状态
    
    LCD_DrawImage1BPP(82, 100 + 38 * 6, BMP_Hundong, WHITE, BLACK); //混动
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 6, BMP_System, WHITE, BLACK); //系统
    LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 6, BMP_Zhuangtai, WHITE, BLACK); //状态
    
    LCD_DrawImage1BPP(82, 100 + 38 * 7, BMP_a, WHITE, BLACK); //A
    LCD_DrawImage1BPP(82 + 11, 100 + 38 * 7, BMP_b, WHITE, BLACK); //B
    LCD_DrawImage1BPP(82 + 11 + 11, 100 + 38 * 7, BMP_s, WHITE, BLACK); //S
    LCD_DrawImage1BPP(82 + 11 + 11 + 11, 100 + 38 * 7, BMP_Zhuangtai, WHITE, BLACK); //状态

    LCD_DrawImage1BPP(82 + 320, 100, BMP_Zhidong, WHITE, BLACK); //制动
    LCD_DrawImage1BPP(82 + 42 + 320, 100, BMP_Taban, WHITE, BLACK); //踏板
    LCD_DrawImage1BPP(82 + 42 + 43 + 320, 100, BMP_Kaidu, WHITE, BLACK); //开度
    LCD_DrawImage1BPP(720 - 24, 100, BMP_Baifenhao, WHITE, BLACK); //%

    LCD_DrawImage1BPP(82 + 320, 100 + 38*2, BMP_DJ, WHITE, BLACK); //电机
    LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38*2, BMP_Zhuansu, WHITE, BLACK); //转速
    print_SZ_1(82 + 320 + 42+42, 100 + 38*2 - 8, 1, 1, 0, WHITE); //1
    LCD_DrawImage1BPP(720 - 35, 100 + 38*2, BMP_RPM, WHITE, BLACK); //RPM

    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 3, BMP_m, WHITE, BLACK); //M
    LCD_DrawImage1BPP(82 + 320 + 11, 100 + 38 * 3, BMP_c, WHITE, BLACK); //C
    LCD_DrawImage1BPP(82 + 320 + 11 + 11, 100 + 38 * 3, BMP_u, WHITE, BLACK); //U
    LCD_DrawImage1BPP(82 + 320 + 11 + 11 + 11, 100 + 38 * 3, BMP_Wendu, WHITE, BLACK); //温度
    print_SZ_1(82 + 320 + 11 + 11 + 11+42, 100 + 38*3 - 8, 1, 1, 0, WHITE); //1
    LCD_DrawImage1BPP(720 - 28, 100 + 38 * 3, BMP_T, WHITE, BLACK); //℃

    LCD_DrawImage1BPP(82 + 320 + 90 + 20 + 40 + 60, 100 + 38 * 4, BMP_s, WHITE, BLACK); //SPN
    LCD_DrawImage1BPP(82 + 320 + 90 + 20 + 40 + 60 + 11, 100 + 38 * 4, BMP_p, WHITE, BLACK);
    LCD_DrawImage1BPP(82 + 320 + 90 + 20 + 40 + 60 + 11 + 11, 100 + 38 * 4, BMP_n, WHITE, BLACK);
    LCD_DrawImage1BPP(82 + 320 + 90 + 20 + 40 + 60 + 70, 100 + 38 * 4, BMP_f, WHITE, BLACK); //FMI
    LCD_DrawImage1BPP(82 + 320 + 90 + 20 + 40 + 60 + 70 + 11, 100 + 38 * 4, BMP_m, WHITE, BLACK);
    LCD_DrawImage1BPP(82 + 320 + 90 + 20 + 40 + 60 + 70 + 11 + 11, 100 + 38 * 4, BMP_i, WHITE, BLACK); 

    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 5, BMP_a, WHITE, BLACK); //A
    LCD_DrawImage1BPP(82 + 320 + 11, 100 + 38 * 5, BMP_m, WHITE, BLACK); //M
    LCD_DrawImage1BPP(82 + 320 + 11 + 11, 100 + 38 * 5, BMP_t, WHITE, BLACK); //T
    LCD_DrawImage1BPP(82 + 320 + 11 + 11 + 11, 100 + 38 * 5, BMP_Guzhang, WHITE, BLACK); //故障
    LCD_DrawImage1BPP(82 + 320 + 11 + 11 + 11 + 42, 100 + 38 * 5, BMP_Code, WHITE, BLACK); //码
    
    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 6, BMP_Hundong, WHITE, BLACK); //混动
    LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 6, BMP_System, WHITE, BLACK); //系统
    LCD_DrawImage1BPP(82 + 320 + 42 + 43, 100 + 38 * 6, BMP_Guzhang, WHITE, BLACK); //故障
    LCD_DrawImage1BPP(82 + 320 + 42 + 42 + 42, 100 + 38 * 6, BMP_Code, WHITE, BLACK); //码

    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 7, BMP_a, WHITE, BLACK); //A
    LCD_DrawImage1BPP(82 + 320 + 11, 100 + 38 * 7, BMP_b, WHITE, BLACK); //B
    LCD_DrawImage1BPP(82 + 320 + 11 + 11, 100 + 38 * 7, BMP_s, WHITE, BLACK); //S   
    LCD_DrawImage1BPP(82 + 320 + 11 + 11 + 11, 100 + 38 * 7, BMP_Guzhang, WHITE, BLACK); //故障
    LCD_DrawImage1BPP(82 + 320 + 11 + 11 + 11 + 42, 100 + 38 * 7, BMP_Code, WHITE, BLACK); //码

    LCD_DrawImage1BPP(82, 100 + 38 * 8, BMP_DJ, WHITE, BLACK); //电机
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 8, BMP_DL, WHITE, BLACK); //电流
    print_SZ_1(82 + 42 + 42, 100 + 38 * 8 - 8, 2, 1, 0, WHITE); //2
    LCD_DrawImage1BPP(400 - 24, 100 + 38 * 8, BMP_a, WHITE, BLACK); //A

    LCD_DrawImage1BPP(82, 100 + 38 * 9, BMP_DJ, WHITE, BLACK); //电机
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 9, BMP_Wendu, WHITE, BLACK); //温度
    print_SZ_1(82 + 42 + 42, 100 + 38 * 9 - 8, 2, 1, 0, WHITE); //2
    LCD_DrawImage1BPP(400 - 28, 100 + 38 * 9, BMP_T, WHITE, BLACK); //℃

    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 8, BMP_DJ, WHITE, BLACK); //电机
    LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 8, BMP_Zhuansu, WHITE, BLACK); //转速
    print_SZ_1(82 + 320 + 42 + 42, 100 + 38 * 8 - 8, 2, 1, 0, WHITE); //2
    LCD_DrawImage1BPP(720 - 35, 100 + 38 * 8, BMP_RPM, WHITE, BLACK); //RPM

    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 9, BMP_m, WHITE, BLACK); //M
    LCD_DrawImage1BPP(82 + 320 + 11, 100 + 38 * 9, BMP_c, WHITE, BLACK); //C
    LCD_DrawImage1BPP(82 + 320 + 11 + 11, 100 + 38 * 9, BMP_u, WHITE, BLACK); //U
    LCD_DrawImage1BPP(82 + 320 + 11 + 11 + 11, 100 + 38 * 9, BMP_Wendu, WHITE, BLACK); //温度
    print_SZ_1(82 + 320 + 11 + 11 + 11 + 42, 100 + 38 * 9 - 8, 2, 1, 0, WHITE); //2
    LCD_DrawImage1BPP(720 - 28, 100 + 38 * 9, BMP_T, WHITE, BLACK); //℃
}

void ControlUpdate(void) {
    static unsigned char AMT_color[3],HCU_color[3],ABS_color[2];
    print_SZ_1(82 + 200+20 , 100 - 8, Accelerator * 0.4, 3, 0, GREEN); //加速踏板
    updata_DJDY(82 + 200 + 20, 100 + 38 - 8);//电机MCU电压
    updata_DJDL(82 + 200 + 20, 100 + 38 * 2 - 8, moto_current,4,500); //1
    updata_DJDL(82 + 200 + 20, 100 + 38 * 8 - 8, Motor2_Generatrix_Current,8,1000); //2
    updata_T(82 + 200 + 20, 100 + 38 * 3 - 8, GREEN, Motor_Temperature, 1, 40); //1
    updata_T(82 + 200 + 20, 100 + 38 * 9 - 8, GREEN, Motor2_Temperature, 1, 40); //2
    updata_Dangwei(82 + 200 + 20, 100 + 38 * 4 - 4,0);
    /////////////////////////////////////////////
    if (Lamp_status_YELLOW == 0 && Lamp_status_RED == 0)
        AMT_color[0] = GREEN;
    else AMT_color[0] = GRAY;

    if (Lamp_status_YELLOW)
        AMT_color[1] = YELLOW;
    else AMT_color[1] = GRAY;

    if (Lamp_status_RED)
        AMT_color[2] = RED;
    else AMT_color[2] = GRAY;

    LCD_DrawImage1BPP(82 + 42 + 42 + 42 + 15, 100 + 38 * 5, BMP_Zhengchang, AMT_color[0], BLACK); //正常
    LCD_DrawImage1BPP(82 + 42 + 42 + 42 + 15 + 42 + 15, 100 + 38 * 5, BMP_Yichang, AMT_color[1], BLACK); //异常
    LCD_DrawImage1BPP(82 + 42 + 42 + 42 + 15 + 42 + 15 + 42 + 15, 100 + 38 * 5, BMP_Guzhang, AMT_color[2], BLACK); //故障
    
    if (mil_lamp_request == 0 && fail_mode == 0)
        HCU_color[0] = GREEN;
    else HCU_color[0] = GRAY;

    if (mil_lamp_request)
        HCU_color[1] = YELLOW;
    else HCU_color[1] = GRAY;

    if (fail_mode!=0)
        HCU_color[2] = RED;
    else HCU_color[2] = GRAY;

    LCD_DrawImage1BPP(82 + 42 + 42 + 42 + 15, 100 + 38 * 6, BMP_Zhengchang, HCU_color[0], BLACK); //正常
    LCD_DrawImage1BPP(82 + 42 + 42 + 42 + 15 + 42 + 15, 100 + 38 * 6, BMP_Yichang, HCU_color[1], BLACK); //异常
    LCD_DrawImage1BPP(82 + 42 + 42 + 42 + 15 + 42 + 15 + 42 + 15, 100 + 38 * 6, BMP_Guzhang, HCU_color[2], BLACK); //故障
    
    if (ABS_lamp) {
        ABS_color[0] = GRAY;
        ABS_color[1] = RED;
    } else {
        ABS_color[0] = GREEN;
        ABS_color[1] = GRAY;
    }

    LCD_DrawImage1BPP(82 + 42 + 42 + 42 + 15, 100 + 38 * 7, BMP_Zhengchang, ABS_color[0], BLACK); //正常
    LCD_DrawImage1BPP(82 + 42 + 42 + 42 + 15 + 42 + 15, 100 + 38 * 7, BMP_Guzhang, ABS_color[1], BLACK); //故障

    print_SZ_1(82 + 200 + 320, 100 - 8, Brake_percent, 3, 0, GREEN); //制动踏板
    updata_RMP(82 + 200 + 320, 100 + 38 * 2 - 8,moto_speed);//1
    updata_RMP(82 + 200 + 320, 100 + 38 * 8 - 8,Motor2_Speed);//2
    updata_T(82 + 200 + 20 + 320, 100 + 38 * 3 - 8, GREEN, Inverter_t, 1, 40);//1 
    updata_T(82 + 200 + 20 + 320, 100 + 38 * 9 - 8, GREEN, Motor2_Inverter_Temperature, 1, 40);//2
       
    disp_SPN_FMI_1(82 + 150 + 320, 100 - 8 + 38 * 5, CAN_18FECA03_len, CAN_18FECA03); //TCU故障码
    disp_SPN_FMI_2(82 + 150 + 320, 100 - 8 + 38 * 6, CAN_18FECAEF_len, CAN_18FECAEF); //HCU故障码
    print_SZ_1(82 + 150 + 320, 100 + 38 * 7 - 8, abs_spn, 6, 0, GREEN); //ABS故障码
    
/*
    print_SZ_1(82 + 200 + 20, 100 - 8 + 38 * 4, Car_mode, 3, 0, WHITE); //整车模式
    print_SZ_1(82 + 200 - 44, 100 - 8 + 38 * 5, Program, 6, 2, WHITE); //程序版本
    print_SZ_1(82 + 200 + 20, 100 - 8 + 38 * 6, Car_LIFE, 3, 0, WHITE); //整车LIFE
    print_SZ_1(82 + 200 + 320, 100 - 8, Speed_percent * 4, 4, 1, WHITE); //加速踏板
    print_SZ_1(82 + 200 + 320, 100 - 8 + 38, Brake_percent * 4, 4, 1, WHITE); //制动踏板
    print_D(82 + 180 + 320, 100 - 8 + 38 * 2, CAN_KEY[0].byte); //数字量输入1
    print_D(82 + 180 + 320, 100 - 8 + 38 * 3, CAN_KEY[1].byte); //数字量输入2
   //print_D(82 + 180 + 320, 100 - 8 + 38 * 4, Digit_input3); //数字量输入3
    print_D(82 + 180 + 320, 100 - 8 + 38 * 5, CAN_KEY[2].byte); //数字量输入1
    print_D(82 + 180 + 320, 100 - 8 + 38 * 6, CAN_KEY[3].byte); //数字量输入2
    print_D(82 + 180 + 320, 100 - 8 + 38 * 7, 0); //数字量输入3*/

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
    LCD_DrawImage1BPP(130 + 200 - 15, 130 - 85, BMP_Engine, GREEN, BLACK); //发动机
    LCD_DrawImage1BPP(130 + 200 + 75 - 15, 130 - 85, BMP_STSTEM, GREEN, BLACK); //系统
    LCD_DrawImage1BPP(130 + 200 + 75 + 50 - 15, 130 - 85, BMP_Message, GREEN, BLACK); //信息

    LCD_DrawRect(80, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320 + 320, 90, 1, 380, GREEN);
    for (i = 0; i < 11; i++)
        LCD_DrawRect(80, 90 + i * 38, 640, 1, GREEN);
    
    LCD_DrawImage1BPP(82, 100, BMP_Fadongji, WHITE, BLACK); //发动机
    LCD_DrawImage1BPP(82 + 63, 100, BMP_Zhuansu, WHITE, BLACK); //转速
    LCD_DrawImage1BPP(400 - 32, 100, BMP_RPM, WHITE, BLACK); //rpm

    LCD_DrawImage1BPP(82, 100 + 38, BMP_Fadongji, WHITE, BLACK); //发动机
    LCD_DrawImage1BPP(82 + 63, 100 + 38, BMP_Shuiwen, WHITE, BLACK); //水温
    LCD_DrawImage1BPP(400 - 28, 100 + 38, BMP_T, WHITE, BLACK); //℃
    
    LCD_DrawImage1BPP(82, 100 + 38 * 2, BMP_Fadongji, WHITE, BLACK); //发动机
    LCD_DrawImage1BPP(82 + 63, 100 + 38 * 2, BMP_Youmen, WHITE, BLACK); //油门
    LCD_DrawImage1BPP(400 - 24, 100 + 38 * 2, BMP_Baifenhao, WHITE, BLACK); //%
    
    LCD_DrawImage1BPP(82 , 100 + 38 * 3, BMP_Fadongji, WHITE, BLACK); //发动机
    LCD_DrawImage1BPP(82 + 63 , 100 + 38 * 3, BMP_Jiyou, WHITE, BLACK); //机油
    LCD_DrawImage1BPP(82 + 63 + 42 , 100 + 38 * 3, BMP_Yali, WHITE, BLACK); //压力
    LCD_DrawImage1BPP(400 - 32, 100 + 38 * 3, BMP_Kpa, WHITE, BLACK); //Kpa
    
    LCD_DrawImage1BPP(82 , 100 + 38 * 4, BMP_Fadongji, WHITE, BLACK); //发动机
    LCD_DrawImage1BPP(82 + 63 , 100 + 38 * 4, BMP_Jinqi, WHITE, BLACK); //进气
    LCD_DrawImage1BPP(82 + 63 + 42 , 100 + 38 * 4, BMP_Wendu, WHITE, BLACK); //温度
    LCD_DrawImage1BPP(400 - 28, 100 + 38 * 4, BMP_T, WHITE, BLACK); //℃
    
    LCD_DrawImage1BPP(82 , 100 + 38 * 5, BMP_Fadongji, WHITE, BLACK); //发动机
    LCD_DrawImage1BPP(82 + 63 , 100 + 38 * 5, BMP_Jinqi, WHITE, BLACK); //进气
    LCD_DrawImage1BPP(82 + 63 + 42 , 100 + 38 * 5, BMP_Yali, WHITE, BLACK); //压力
    LCD_DrawImage1BPP(400 - 32, 100 + 38 * 5, BMP_Kpa, WHITE, BLACK); //Kpa
    
    LCD_DrawImage1BPP(82 , 100 + 38 * 6, BMP_Fadongji, WHITE, BLACK); //发动机
    LCD_DrawImage1BPP(82 + 63 , 100 + 38 * 6, BMP_Zengya, WHITE, BLACK); //进气
    LCD_DrawImage1BPP(82 + 63 + 42 , 100 + 38 * 6, BMP_Yali, WHITE, BLACK); //压力
    LCD_DrawImage1BPP(400 - 32, 100 + 38 * 6, BMP_Kpa, WHITE, BLACK); //Kpa
    

    LCD_DrawImage1BPP(82, 100 + 38 * 6, BMP_Fadongji, WHITE, BLACK); //发动机
    LCD_DrawImage1BPP(82 + 63, 100 + 38 * 6, BMP_Zengya, WHITE, BLACK); //增压
    LCD_DrawImage1BPP(82 + 63 + 42, 100 + 38 * 6, BMP_Yali, WHITE, BLACK); //压力
    LCD_DrawImage1BPP(400 - 32, 100 + 38 * 6, BMP_Kpa, WHITE, BLACK); //Kpa

    LCD_DrawImage1BPP(82, 100 + 38 * 7, BMP_Fadongji, WHITE, BLACK); //发动机
    LCD_DrawImage1BPP(82 + 63, 100 + 38 * 7, BMP_Shunshihuoliu, WHITE, BLACK); //瞬时
    LCD_DrawImage1BPP(82 + 63+42, 100 + 38 * 7, BMP_Qihao, WHITE, BLACK); //气耗
    LCD_DrawImage1BPP(400 - 50, 100 + 38 * 7, BMP_k, WHITE, BLACK); //K
    LCD_DrawImage1BPP(400 - 50 + 11, 100 + 38 * 7, BMP_g, WHITE, BLACK); //G
    LCD_DrawImage1BPP(400 - 50+ 11 + 11, 100 + 38 * 7, BMP_II, WHITE, BLACK); // /
    LCD_DrawImage1BPP(400 - 50 + 11 + 11 + 11, 100 + 38 * 7, BMP_h, WHITE, BLACK); //H

    LCD_DrawImage1BPP(82, 100 + 38 * 8, BMP_Fadongji, WHITE, BLACK); //发动机
    LCD_DrawImage1BPP(82 + 63, 100 + 38 * 8, BMP_Pingjun, WHITE, BLACK); //平均
    LCD_DrawImage1BPP(82 + 63 + 42, 100 + 38 * 8, BMP_Qihao, WHITE, BLACK); //气耗
    LCD_DrawImage1BPP(400 - 85, 100 + 38 * 8, BMP_k, WHITE, BLACK); //K
    LCD_DrawImage1BPP(400 - 85 + 11, 100 + 38 * 8, BMP_g, WHITE, BLACK); //G
    LCD_DrawImage1BPP(400 - 85 + 11 + 11, 100 + 38 * 8, BMP_II, WHITE, BLACK); // /
    print_SZ(400 - 85 + 11 + 11 + 11, 100 + 4+38 * 8, 100, 3, 0, WHITE);//100
    LCD_DrawImage1BPP(400 - 85+ 11 + 11 + 11 + 24, 100  + 38 * 8, BMP_k, WHITE, BLACK); //K
    LCD_DrawImage1BPP(400 - 85 + 11 + 11 + 11 + 11 + 24, 100  + 38 * 8, BMP_m, WHITE, BLACK); //M

    LCD_DrawImage1BPP(82, 100 + 38 * 9, BMP_Leiji, WHITE, BLACK); //累计
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 9, BMP_Qihao, WHITE, BLACK); //气耗
    LCD_DrawImage1BPP(400 - 50, 100 + 38 * 9, BMP_k, WHITE, BLACK); //K
    LCD_DrawImage1BPP(400 - 50 + 11, 100 + 38 * 9, BMP_g, WHITE, BLACK); //G
    LCD_DrawImage1BPP(400 - 50 + 11 + 11, 100 + 38 * 9, BMP_II, WHITE, BLACK); // /
    LCD_DrawImage1BPP(400 - 50 + 11 + 11 + 11, 100 + 38 * 9, BMP_h, WHITE, BLACK); //H

    LCD_DrawImage1BPP(82 + 320 + 90, 100, BMP_Fadongji, WHITE, BLACK); //发动机
    LCD_DrawImage1BPP(82 + 320 + 90 + 63, 100, BMP_Guzhang, WHITE, BLACK); //故障
    LCD_DrawImage1BPP(82 + 320 + 90 + 63 + 42, 100, BMP_Code, WHITE, BLACK); //代码
    
    LCD_DrawImage1BPP(82 + 320 + 90 + 40, 100 + 38, BMP_s, WHITE, BLACK); //SPN
    LCD_DrawImage1BPP(82 + 320 + 90 + 40 + 11, 100 + 38, BMP_p, WHITE, BLACK); 
    LCD_DrawImage1BPP(82 + 320 + 90 + 40 + 11 + 11, 100 + 38, BMP_n, WHITE, BLACK); 
    LCD_DrawImage1BPP(82 + 320 + 90 + 40 + 80, 100 + 38, BMP_f, WHITE, BLACK); //FMI
    LCD_DrawImage1BPP(82 + 320 + 90 + 40 + 80 + 11, 100 + 38, BMP_m, WHITE, BLACK); 
    LCD_DrawImage1BPP(82 + 320 + 90 + 40 + 80 + 11 + 11, 100 + 38, BMP_i, WHITE, BLACK); 
    
    for(i=1;i<9;i++)
    print_SZ_1(82 + 320, 100 +31+ 38 * i, i, 1, 0, WHITE);
    
    /*

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
*/
}

void EngineUpdate(void) {
    print_SZ_1(82 + 63 + 42 + 80, 100 - 8, EngineSpeed * 0.125, 4, 0, GREEN); //发动机转速
    updata_T(82 + 63 + 42 + 80 + 32, 100 - 8 + 38, GREEN, water_temp, 1, 40); //水温
    //print_SZ_1(82 + 63 + 42 + 80, 100 - 8, EngineSpeed * 0.125, 4, 0, WHITE); //发动机油门
    print_SZ_1(82 + 63 + 42 + 80, 100 + 38 * 3 - 8, Engine_oil_press, 4, 0, GREEN); //发动机机油压力
    updata_T(82 + 63 + 42 + 80 + 32, 100 - 8 + 38 * 4, GREEN, ambient_air_temperature, 1, 40); //进气温度
    print_SZ_1(82 + 63 + 42 + 80, 100 + 38 * 5 - 8, air_pressure, 4, 0, GREEN); //发动机进气压力
    print_SZ_1(82 + 63 + 42 + 80, 100 + 38 * 6 - 8, barometric_pressure, 4, 0, GREEN); //发动机增压压力
    print_SZ_1(82 + 63 + 42 + 80, 100 + 38 * 7 - 8, Shunshi_fule*100, 4, 2, GREEN); //发动机瞬时气耗
    print_SZ_1(82 + 63 + 42 + 80-32, 100 + 38 * 8 - 8, Average_fule*100, 4, 2, GREEN); //发动机平均气耗
    print_SZ_1(82 + 63 + 42 + 80, 100 + 38 * 9 - 8, Trip_fuel, 4, 0, GREEN); //发动机单次累计气耗

    if (CAN_18FECAEF_len >= 6) {
        DM(1,CAN_18FECAEF);
        print_SZ_1(82 + 320 + 90 - 32, 100 + 38 * 2 - 8, hcu_spn, 6, 0, GREEN);
        print_SZ_1(82 + 320 + 90 + 80 + 16, 100 + 38 * 2 - 8, hcu_fmi, 3, 0, GREEN);
    }else{
        print_SZ_1(82 + 320 + 90 - 32, 100 + 38 * 2 - 8, 0, 6, 0, GREEN);
        print_SZ_1(82 + 320 + 90 + 80 + 16, 100 + 38 * 2 - 8, 0, 3, 0, GREEN);
    }
        
    
    if (CAN_18FECAEF_len >= 10) {
        DM(2,CAN_18FECAEF);
        print_SZ_1(82 + 320 + 90 - 32, 100 + 38 * 3 - 8, hcu_spn, 6, 0, GREEN);
        print_SZ_1(82 + 320 + 90 + 80 + 16, 100 + 38 * 3 - 8, hcu_fmi, 3, 0, GREEN);
    }
    else{
        print_SZ_1(82 + 320 + 90 - 32, 100 + 38 * 3 - 8, 0, 6, 0, GREEN);
        print_SZ_1(82 + 320 + 90 + 80 + 16, 100 + 38 * 3 - 8, 0, 3, 0, GREEN);
    }
    
    if (CAN_18FECAEF_len >= 14) {
        DM(3,CAN_18FECAEF);
        print_SZ_1(82 + 320 + 90 - 32, 100 + 38 * 4 - 8, hcu_spn, 6, 0, GREEN);
        print_SZ_1(82 + 320 + 90 + 80 + 16, 100 + 38 * 4 - 8, hcu_fmi, 3, 0, GREEN);
    }else{
        print_SZ_1(82 + 320 + 90 - 32, 100 + 38 * 4 - 8, 0, 6, 0, GREEN);
        print_SZ_1(82 + 320 + 90 + 80 + 16, 100 + 38 * 4 - 8, 0, 3, 0, GREEN);
    }
    
    if (CAN_18FECAEF_len >= 18) {
        DM(4,CAN_18FECAEF);
        print_SZ_1(82 + 320 + 90 - 32, 100 + 38 * 5 - 8, hcu_spn, 6, 0, GREEN);
        print_SZ_1(82 + 320 + 90 + 80 + 16, 100 + 38 * 5 - 8, hcu_fmi, 3, 0, GREEN);
    }else{
        print_SZ_1(82 + 320 + 90 - 32, 100 + 38 * 5 - 8, 0, 6, 0, GREEN);
        print_SZ_1(82 + 320 + 90 + 80 + 16, 100 + 38 * 5 - 8, 0, 3, 0, GREEN);
    }
    
    if (CAN_18FECAEF_len >= 22) {
        DM(5,CAN_18FECAEF);
        print_SZ_1(82 + 320 + 90 - 32, 100 + 38 * 6 - 8, hcu_spn, 6, 0, GREEN);
        print_SZ_1(82 + 320 + 90 + 80 + 16, 100 + 38 * 6 - 8, hcu_fmi, 3, 0, GREEN);
    }else{
        print_SZ_1(82 + 320 + 90 - 32, 100 + 38 * 6 - 8, 0, 6, 0, GREEN);
        print_SZ_1(82 + 320 + 90 + 80 + 16, 100 + 38 * 6 - 8, 0, 3, 0, GREEN);
    }
    
    if (CAN_18FECAEF_len >= 26) {
        DM(6,CAN_18FECAEF);
        print_SZ_1(82 + 320 + 90 - 32, 100 + 38 * 7 - 8, hcu_spn, 6, 0, GREEN);
        print_SZ_1(82 + 320 + 90 + 80 + 16, 100 + 38 * 7 - 8, hcu_fmi, 3, 0, GREEN);
    }else{
        print_SZ_1(82 + 320 + 90 - 32, 100 + 38 * 7 - 8, 0, 6, 0, GREEN);
        print_SZ_1(82 + 320 + 90 + 80 + 16, 100 + 38 * 7 - 8, 0, 3, 0, GREEN);
    }
    
    if (CAN_18FECAEF_len >= 30) {
        DM(7,CAN_18FECAEF);
        print_SZ_1(82 + 320 + 90 - 32, 100 + 38 * 8 - 8, hcu_spn, 6, 0, GREEN);
        print_SZ_1(82 + 320 + 90 + 80 + 16, 100 + 38 * 8 - 8, hcu_fmi, 3, 0, GREEN);
    }else{
        print_SZ_1(82 + 320 + 90 - 32, 100 + 38 * 8 - 8, 0, 6, 0, GREEN);
        print_SZ_1(82 + 320 + 90 + 80 + 16, 100 + 38 * 8 - 8, 0, 3, 0, GREEN);
    }
    
    if (CAN_18FECAEF_len >= 34) {
        DM(8,CAN_18FECAEF);
        print_SZ_1(82 + 320 + 90 - 32, 100 + 38 * 9 - 8, hcu_spn, 6, 0, GREEN);
        print_SZ_1(82 + 320 + 90 + 80 + 16, 100 + 38 * 9 - 8, hcu_fmi, 3, 0, GREEN);
    }else{
        print_SZ_1(82 + 320 + 90 - 32, 100 + 38 * 9 - 8, 0, 6, 0, GREEN);
        print_SZ_1(82 + 320 + 90 + 80 + 16, 100 + 38 * 9 - 8, 0, 3, 0, GREEN);
    }
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
    LCD_DrawImage1BPP(130 + 200, 130 - 85, BMP_Fuzhu, GREEN, BLACK); //辅助
    LCD_DrawImage1BPP(130 + 200 + 50, 130 - 85, BMP_STSTEM, GREEN, BLACK); //系统
    LCD_DrawImage1BPP(130 + 200 + 50 + 50, 130 - 85, BMP_Message, GREEN, BLACK); //信息

    LCD_DrawRect(80, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320, 90+38, 1, 38*2, GREEN);
    LCD_DrawRect(80 + 320, 90+38*5, 1, 38*2, GREEN);
    LCD_DrawRect(80 + 320 + 320, 90, 1, 380, GREEN);
    for (i = 0; i < 11; i++)
        LCD_DrawRect(80, 90 + i * 38, 640, 1, GREEN);

    LCD_DrawImage1BPP(82 + 42 + 240, 100, BMP_d, GREEN, BLACK); //D
    LCD_DrawImage1BPP(82 + 42 + 240 + 11, 100, BMP_c, GREEN, BLACK); //C
    LCD_DrawImage1BPP(82 + 42 + 240 + 11 + 11, 100, BMP_I, GREEN, BLACK); //  /
    LCD_DrawImage1BPP(82 + 42 + 240 + 11 + 11 + 11, 100, BMP_d, GREEN, BLACK); //D
    LCD_DrawImage1BPP(82 + 42 + 240 + 11 + 11 + 11 + 11, 100, BMP_c, GREEN, BLACK); //C
    LCD_DrawImage1BPP(82 + 42 + 240 + 11 + 11 + 11 + 11 + 11, 100, BMP_Bianhuanqi, GREEN, BLACK); //变换器
    
    LCD_DrawImage1BPP(82 , 100+38, BMP_Input, WHITE, BLACK); //输入
    LCD_DrawImage1BPP(82 + 42, 100+38, BMP_DY, WHITE, BLACK); //电压
    LCD_DrawImage1BPP(400 - 24, 100+38, BMP_v, WHITE, BLACK); //v
    
    LCD_DrawImage1BPP(82 , 100+38*2, BMP_Output, WHITE, BLACK); //输出
    LCD_DrawImage1BPP(82 + 42, 100+38*2, BMP_DY, WHITE, BLACK); //电压
    LCD_DrawImage1BPP(400 - 24, 100+38*2, BMP_v, WHITE, BLACK); //v
    
    LCD_DrawImage1BPP(82, 100 + 38 * 3, BMP_Zhuangtai, WHITE, BLACK); //状态
    
    LCD_DrawImage1BPP(82+320, 100+38, BMP_Wendu, WHITE, BLACK); //温度
    LCD_DrawImage1BPP(720 - 28, 100+38 , BMP_T, WHITE, BLACK); //℃
    
    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 2, BMP_Output, WHITE, BLACK); //输出
    LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 2, BMP_DL, WHITE, BLACK); //电流
    LCD_DrawImage1BPP(720 - 24, 100 + 38 * 2, BMP_a, WHITE, BLACK); //A

    LCD_DrawImage1BPP(82 + 240 + 42, 100 + 38 * 4, BMP_d, GREEN, BLACK); //D
    LCD_DrawImage1BPP(82 + 240 + 42 + 11, 100 + 38 * 4, BMP_c, GREEN, BLACK); //C
    LCD_DrawImage1BPP(82 + 240 + 42 + 11 + 11, 100 + 38 * 4, BMP_I, GREEN, BLACK); //  /
    LCD_DrawImage1BPP(82 + 240 + 42 + 11 + 11 + 11, 100 + 38 * 4, BMP_a, GREEN, BLACK); //D
    LCD_DrawImage1BPP(82 + 240 + 42 + 11 + 11 + 11 + 11, 100 + 38 * 4, BMP_c, GREEN, BLACK); //C
    LCD_DrawImage1BPP(82 + 240 + 42 + 11 + 11 + 11 + 11 + 11, 100 + 38 * 4, BMP_Bianhuanqi, GREEN, BLACK); //变换器
    
    LCD_DrawImage1BPP(82 , 100+38*5, BMP_Input, WHITE, BLACK); //输入
    LCD_DrawImage1BPP(82 + 42, 100+38*5, BMP_DY, WHITE, BLACK); //电压
    LCD_DrawImage1BPP(400 - 24, 100+38*5, BMP_v, WHITE, BLACK); //v
    
    LCD_DrawImage1BPP(82 , 100+38*6, BMP_Output, WHITE, BLACK); //输出
    LCD_DrawImage1BPP(82 + 42, 100+38*6, BMP_DY, WHITE, BLACK); //电压
    LCD_DrawImage1BPP(400 - 24, 100+38*6, BMP_v, WHITE, BLACK); //v
    
    LCD_DrawImage1BPP(82, 100 + 38 * 7, BMP_Zhuangtai, WHITE, BLACK); //状态
    
    LCD_DrawImage1BPP(82+320, 100+38*5, BMP_Wendu, WHITE, BLACK); //温度
    LCD_DrawImage1BPP(720 - 28, 100+38*5 , BMP_T, WHITE, BLACK); //℃
    
    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 6, BMP_Output, WHITE, BLACK); //输出
    LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 6, BMP_DL, WHITE, BLACK); //电流
    LCD_DrawImage1BPP(720 - 24, 100 + 38 * 6, BMP_a, WHITE, BLACK); //A
          
}

void FuzhuUpdate(void) {
    static unsigned char DCDC_color[6],DCAC_color[9];
    print_SZ_1(82 + 200, 100 + 38 - 8, DC_DC_voltage_in, 4, 0, GREEN); //DCDC输入电压
    print_SZ_1(82 + 200, 100 + 38 * 2 - 8, DC_DC_voltage_out, 4, 0, GREEN); //DCDC输出电压
    updata_T(82 + 200 + 320, 100 + 38 - 8, GREEN, DC_DC_t, 1, 0); //散热器温度
    print_SZ_1(82 + 200 + 320-16, 100 + 38 * 2 - 8, DC_DC_current_out, 4, 0, GREEN); //DCDC输出电流
    
    if (!DC_DC_code.byte)
        DCDC_color[0] = GREEN;
    else DCDC_color[0] = GRAY;

    if (DCDC_under_v_in)
        DCDC_color[1] = YELLOW;
    else DCDC_color[1] = GRAY;

    if (DCDC_over_v_in)
        DCDC_color[2] = RED;
    else DCDC_color[2] = GRAY;
    
    if (DCDC_out)
        DCDC_color[3] = RED;
    else DCDC_color[3] = GRAY;
    
    if (DCDC_over_t)
        DCDC_color[4] = RED;
    else DCDC_color[4] = GRAY;
    
    if (DCDC_short)
        DCDC_color[5] = RED;
    else DCDC_color[5] = GRAY;

    LCD_DrawImage1BPP(60 + 42 * 2, 100 + 38 * 3, BMP_Zhengchang, DCDC_color[0], BLACK); //正常
    
    LCD_DrawImage1BPP(60 + 42 * 3 + 15, 100 + 38 * 3, BMP_Shuruqianya, DCDC_color[1], BLACK); //输入欠压
    
    LCD_DrawImage1BPP(60 + 42 * 5 + 15 * 2 + 4, 100 + 38 * 3, BMP_Shuchuqianya, DCDC_color[2], BLACK); //输出欠压
    
    LCD_DrawImage1BPP(60 + 42 * 7 + 15 * 3 + 4 * 2, 100 + 38 * 3, BMP_Shuchuzhuangtai, DCDC_color[3], BLACK); //输出状态
    
    LCD_DrawImage1BPP(60 + 42 * 9 + 15 * 4 + 4 * 3, 100 + 38 * 3, BMP_Guo, DCDC_color[4], BLACK); //过
    LCD_DrawImage1BPP(60 + 42 * 9 + 15 * 4 + 4 * 3 + 21, 100 + 38 * 3, BMP_Re, DCDC_color[4], BLACK); //热
    
    LCD_DrawImage1BPP(60 + 42 * 10 + 15 * 4 + 4 * 3 + 21, 100 + 38 * 3, BMP_Duanlu, DCDC_color[5], BLACK); //短路

    print_SZ_1(82 + 200, 100 + 38 * 5 - 8, DC_AC_voltage_in, 4, 0, GREEN); //DCAC输入电压
    print_SZ_1(82 + 200, 100 + 38 * 6 - 8, DC_AC_voltage_out, 4, 0, GREEN); //DCAC输出电压
    updata_T(82 + 200 + 320, 100 + 38 * 5 - 8, GREEN, DC_AC_t, 1, 0); //散热器温度
    print_SZ_1(82 + 200 + 320 - 16, 100 + 38 * 6 - 8, DC_AC_current_out, 4, 0, GREEN); //DCAC输出电流
    
    if (!DC_AC_code.byte)
        DCAC_color[0] = GREEN;
    else DCAC_color[0] = GRAY;

    if (DCAC_under_v_in)
        DCAC_color[1] = YELLOW;
    else DCAC_color[1] = GRAY;

    if (DCAC_over_v_in)
        DCAC_color[2] = RED;
    else DCAC_color[2] = GRAY;
    
    if (DCAC_low_vbat)
        DCAC_color[3] = RED;
    else DCAC_color[3] = GRAY;
    
    if (DCAC_over_a)
        DCAC_color[4] = RED;
    else DCAC_color[4] = GRAY;
    
    if (DCAC_over_t)
        DCAC_color[5] = RED;
    else DCAC_color[5] = GRAY;
    
    if (DCAC_short)
        DCAC_color[6] = RED;
    else DCAC_color[6] = GRAY;
    
    if (DCAC_over_use)
        DCAC_color[7] = RED;
    else DCAC_color[7] = GRAY;
    
    if (DCAC_lost_xiang)
        DCAC_color[8] = RED;
    else DCAC_color[8] = GRAY;

    LCD_DrawImage1BPP(60 + 42 * 2, 100 + 38 * 7, BMP_Zhengchang, DCAC_color[0], BLACK); //正常

    LCD_DrawImage1BPP(60 + 42 * 3 + 15, 100 + 38 * 7, BMP_Shuchuqianya, DCAC_color[1], BLACK); //输入欠压

    LCD_DrawImage1BPP(60 + 42 * 5 + 15 * 2 + 4, 100 + 38 * 7, BMP_Shuruguoya, DCAC_color[2], BLACK); //输入过压

    LCD_DrawImage1BPP(60 + 42 * 7 + 15 * 3 + 4 * 2, 100 + 38 * 7, BMP_Diyadianyuan, DCAC_color[3], BLACK); //欠压

    LCD_DrawImage1BPP(60 + 42 * 9 + 15 * 4 + 4 * 3 , 100 + 38 * 7, BMP_Shunshihuoliu, DCAC_color[4], BLACK); //瞬时过流

    LCD_DrawImage1BPP(60 + 42 * 2 , 100 + 38 * 8, BMP_Guore, DCAC_color[5], BLACK); //过热

    LCD_DrawImage1BPP(60 + 42 * 3 + 15, 100 + 38 * 8, BMP_Duanlu, DCAC_color[6], BLACK); //短路

    LCD_DrawImage1BPP(60 + 42 * 4 + 15 * 2, 100 + 38 * 8, BMP_Guozai, DCAC_color[7], BLACK); //过载

    LCD_DrawImage1BPP(60 + 42 * 5 + 15 * 3, 100 + 38 * 8, BMP_Quexiang, DCAC_color[8], BLACK); //缺相
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
/*******************************************************/
void BMSFrame(void) {
    unsigned char i = 0;
    LCD_Clear();
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //顶部横线
    LCD_DrawImage1BPP(130 + 200 - 24, 130 - 85, BMP_Battery, GREEN, BLACK); //电池
    LCD_DrawImage1BPP(130 + 200 + 50 - 24, 130 - 85, BMP_STSTEM, GREEN, BLACK); //系统
    LCD_DrawImage1BPP(130 + 200 + 50 + 50 - 24, 130 - 85, BMP_Message, GREEN, BLACK); //信息

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

    LCD_DrawImage1BPP(82, 100 + 38, BMP_s, WHITE, BLACK); //S
    LCD_DrawImage1BPP(82 + 11, 100 + 38, BMP_o, WHITE, BLACK); //O
    LCD_DrawImage1BPP(82 + 11 + 11, 100 + 38, BMP_c, WHITE, BLACK); //C
    LCD_DrawImage1BPP(82 + 11 + 11 + 11 + 2, 100 + 5 + 38, BMP_Maohao, WHITE, BLACK); //:
    LCD_DrawImage1BPP(400 - 24, 100 + 38, BMP_Baifenhao, WHITE, BLACK); //%

    LCD_DrawImage1BPP(82, 100 + 38 * 2, BMP_Dan, WHITE, BLACK); //单
    LCD_DrawImage1BPP(82 + 21, 100 + 38 * 2, BMP_Ti, WHITE, BLACK); //体
    LCD_DrawImage1BPP(82 + 21 + 21, 100 + 38 * 2, BMP_Zui, WHITE, BLACK); //最
    LCD_DrawImage1BPP(82 + 21 + 21 + 21, 100 + 38 * 2, BMP_Gao, WHITE, BLACK); //高
    LCD_DrawImage1BPP(82 + 21 + 21 + 21 + 21, 100 + 38 * 2, BMP_DY, WHITE, BLACK); //电压
    LCD_DrawImage1BPP(82 + 21 + 21 + 21 + 21 + 42 + 2, 100 + 5 + 38 * 2, BMP_Maohao, WHITE, BLACK); //:
    LCD_DrawImage1BPP(400 - 24, 100 + 38 * 2, BMP_v, WHITE, BLACK); //V

    LCD_DrawImage1BPP(82, 100 + 38 * 3, BMP_Dan, WHITE, BLACK); //单
    LCD_DrawImage1BPP(82 + 21, 100 + 38 * 3, BMP_Ti, WHITE, BLACK); //体
    LCD_DrawImage1BPP(82 + 21 + 21, 100 + 38 * 3, BMP_Zui, WHITE, BLACK); //最
    LCD_DrawImage1BPP(82 + 21 + 21 + 21, 100 + 38 * 3, BMP_Di, WHITE, BLACK); //低
    LCD_DrawImage1BPP(82 + 21 + 21 + 21 + 21, 100 + 38 * 3, BMP_DY, WHITE, BLACK); //电压
    LCD_DrawImage1BPP(82 + 21 + 21 + 21 + 21 + 42 + 2, 100 + 5 + 38 * 3, BMP_Maohao, WHITE, BLACK); //:
    LCD_DrawImage1BPP(400 - 24, 100 + 38 * 3, BMP_v, WHITE, BLACK); //V

    LCD_DrawImage1BPP(82, 100 + 38 * 4, BMP_Dan, WHITE, BLACK); //单
    LCD_DrawImage1BPP(82 + 21, 100 + 38 * 4, BMP_Ti, WHITE, BLACK); //体
    LCD_DrawImage1BPP(82 + 21 + 21, 100 + 38 * 4, BMP_Zui, WHITE, BLACK); //最
    LCD_DrawImage1BPP(82 + 21 + 21 + 21, 100 + 38 * 4, BMP_Gao, WHITE, BLACK); //高
    LCD_DrawImage1BPP(82 + 21 + 21 + 21 + 21, 100 + 38 * 4, BMP_Wendu, WHITE, BLACK); //温度
    LCD_DrawImage1BPP(82 + 21 + 21 + 21 + 21 + 42 + 2, 100 + 5 + 38 * 4, BMP_Maohao, WHITE, BLACK); //:
    LCD_DrawImage1BPP(400 - 28, 100 + 38 * 4, BMP_T, WHITE, BLACK); //℃

    LCD_DrawImage1BPP(82, 100 + 38 * 5, BMP_DC, WHITE, BLACK); //电池
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 5, BMP_Zhuangtai, WHITE, BLACK); //状态
    LCD_DrawImage1BPP(82 + 42 + 42 + 16 + 2, 100 + 5 + 38 * 5, BMP_Maohao, WHITE, BLACK); //:

    LCD_DrawImage1BPP(82, 100 + 38 * 6, BMP_Jueyuan, WHITE, BLACK); //绝缘
    LCD_DrawImage1BPP(82 + 42 + 2, 100 + 5 + 38 * 6, BMP_Maohao, WHITE, BLACK); //:


    LCD_DrawImage1BPP(82 + 320, 100, BMP_DC, WHITE, BLACK); //电池
    LCD_DrawImage1BPP(82 + 320 + 42, 100, BMP_Zong, WHITE, BLACK); //总
    LCD_DrawImage1BPP(82 + 320 + 42 + 21, 100, BMP_DL, WHITE, BLACK); //电流
    LCD_DrawImage1BPP(82 + 320 + 42 + 21 + 42 + 2, 100 + 5, BMP_Maohao, WHITE, BLACK); //:
    LCD_DrawImage1BPP(720 - 24, 100, BMP_a, WHITE, BLACK); //A

    LCD_DrawImage1BPP(82 + 320, 100 + 38, BMP_DC, WHITE, BLACK); //电池
    LCD_DrawImage1BPP(82 + 320 + 43, 100 + 38, BMP_Pingjun, WHITE, BLACK); //平均
    LCD_DrawImage1BPP(82 + 320 + 43 + 43, 100 + 38, BMP_Wendu, WHITE, BLACK); //温度
    LCD_DrawImage1BPP(82 + 320 + 43 + 43 + 43 + 2, 100 + 38 + 5, BMP_Maohao, WHITE, BLACK); //:
    LCD_DrawImage1BPP(720 - 24, 100 + 38, BMP_T, WHITE, BLACK); //℃

    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 2, BMP_Weizhi, WHITE, BLACK); //位置
    LCD_DrawImage1BPP(82 + 320 + 43 + 2, 100 + 38 * 2 + 5, BMP_Maohao, WHITE, BLACK); //:
    
    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 3, BMP_Weizhi, WHITE, BLACK); //位置
    LCD_DrawImage1BPP(82 + 320 + 43 + 2, 100 + 38 * 3 + 5, BMP_Maohao, WHITE, BLACK); //:
    
    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 4, BMP_Weizhi, WHITE, BLACK); //位置
    LCD_DrawImage1BPP(82 + 320 + 43 + 2, 100 + 38 * 4 + 5, BMP_Maohao, WHITE, BLACK); //:
    
}

void BMSUpdate(void) {
    static unsigned char BAT_color[4],Jueyuan_color[2];
    updata_DCDY(82 + 200 + 30, 100 - 8);
    updata_SOC(82 + 200 + 30, 100 - 8+38);
    print_SZ_1(82 + 200, 100 + 38*2 - 8, Max_Cell_Voltage*0.0015*100, 3, 2, GREEN); //最高单体电压
    print_SZ_1(82 + 200, 100 + 38*3 - 8, Min_Cell_Voltage*0.0015*100, 3, 2, GREEN); //最低单体电压
    updata_T(82 + 200, 100 + 38*4 - 8,GREEN, Max_Cell_Temperature, 0.2, 50) ;//最高单体温度
    
    
    if (battle_t_warn==0 && battle_higtv1_warn==0 && battle_higtv2_warn==0 && BMS_offline_warn==3)
        BAT_color[0] = GREEN;
    else BAT_color[0] = GRAY;
    
    if((BMS_offline_warn==1))
        BAT_color[3] = RED;
    else if((BMS_offline_warn==3))
        BAT_color[3] = GRAY;

    if (battle_t_warn)
        BAT_color[1] = RED;
    else BAT_color[1] = GRAY;

    if (battle_higtv1_warn || battle_higtv2_warn)
        BAT_color[2] = RED;
    else BAT_color[2] = GRAY;
    if (BMS_offline_warn==3)
        LCD_DrawImage1BPP(82 + 42 + 42 + 42, 100 + 38 * 5, BMP_Zhengchang, BAT_color[0], BLACK); //正常
    else LCD_DrawImage1BPP(82 + 42 + 42 + 42, 100 + 38 * 5, BMP_Lixian, BAT_color[3], BLACK); //离线
    LCD_DrawImage1BPP(82 + 42 + 42 + 42 + 15 + 42, 100 + 38 * 5, BMP_Guowen, BAT_color[1], BLACK); //过温
    LCD_DrawImage1BPP(82 + 42 + 42 + 42 + 15 + 42 + 15 + 42, 100 + 38 * 5, BMP_Guzhang, BAT_color[2], BLACK); //故障
    
    if (!battle_jueyuan_warn){
        Jueyuan_color[0] = GREEN;
        Jueyuan_color[1] = GRAY;
    }else{
        Jueyuan_color[0] = GRAY;
        Jueyuan_color[1] = RED;
    }
    LCD_DrawImage1BPP(82 + 42 + 42 + 42, 100 + 38 * 6, BMP_Zhengchang, Jueyuan_color[0], BLACK); //正常
    LCD_DrawImage1BPP(82 + 42 + 42 + 42 + 15 + 42, 100 + 38 * 6, BMP_Guzhang, Jueyuan_color[1], BLACK); //故障

    updata_DCDL(82 + 200 + 30 + 320 - 16, 100 - 8);
    updata_T(82 + 200 + 30 + 270 + 32, 100 - 8 + 38, GREEN, battle_t, 1, 40);
    print_SZ_1(82 + 200 + 30 + 270 + 32, 100 + 38 * 2 - 8, Max_Cell_Voltage_Cell_Number, 1, 0, GREEN); //最高单体电压位置
    print_SZ_1(82 + 200 + 30 + 270 + 32, 100 + 38 * 3 - 8, Min_Cell_Voltage_Cell_Number, 1, 0, GREEN); //最低单体电压位置
    print_SZ_1(82 + 200 + 30 + 270 + 32, 100 + 38 * 4 - 8, Max_Cell_Temp_Cell_Number, 1, 0, GREEN); //最高单体温度位置
    
    /*
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
    updata_T(82 + 200 + 30 + 270 + 32, 100 - 8 + 38 * 4, WHITE, BMS_T_H, 1, 40); //最高温度*/
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
/********************************************************/
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
            frmControl();
            break;
        case 3:
            frmEngine();
            break;
        case 4:
            frmFuzhu();
            break;
        case 5:
            frmBMS();
            break;
        case 6:  
            frmIC();           
            break;
        case 7:   
            frmBCU_f();           
            break;    
        case 8:   
            frmBCU_m();           
            break;
        case 9:   
            frmBCU_r();           
            break;  
        case 10:   
            frmSET();           
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



