#include "SYSTEM.h"
#include "CAHR.h"
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

void LCD_DrawImageSBPP(unsigned int x, unsigned int y, //没有文字，字数填0，字模为BMP_BLANK       
        unsigned char witdh, //字体宽度
        __prog__ const unsigned char *img[], //字符串首地址
        unsigned char fcolor, //字体颜色
        unsigned char bcolor //字体颜色
        ) {
    unsigned char i;
    for (i = 0; img[i] != NULL; i++) {
        LCD_DrawImage1BPP(x + witdh * i, y, img[i], fcolor, bcolor);
    }
}

//主界面

/*********************************************************
//函数名: void mainFrame(void)
//功能: 显示主界面不需要更新的内容,界面格式
//参数: 无
 *********************************************************/

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

/*void BMP_MOTO_CODE1(unsigned int x, unsigned int y, unsigned char color) {
    print_SZ_1(x - 60, y , 1, 3, 0, WHITE);
    LCD_DrawImage1BPP(x, y + 8, BMP_Loudian, color, BLACK); //漏电保护
    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Baohu, color, BLACK);

    print_SZ_1(x - 60, y  + 38, 2, 3, 0, WHITE);
    LCD_DrawImage1BPP(x, y + 8 + 38, BMP_Duzhuan, color, BLACK); //堵转保护
    LCD_DrawImage1BPP(x + 42, y + 8 + 38, BMP_Baohu, color, BLACK);

    print_SZ_1(x - 60, y + 38 * 2, 3, 3, 0, WHITE);
    LCD_DrawImage1BPP(x, y + 8 + 38 * 2, BMP_Zijian, color, BLACK); //自检保护
    LCD_DrawImage1BPP(x + 42, y + 8 + 38 * 2, BMP_Baohu, color, BLACK);

    print_SZ_1(x - 60, y + 38 * 3, 4, 3, 0, WHITE);
    LCD_DrawImage1BPP(x, y + 8 + 38 * 3, BMP_DJ, color, BLACK); //电机线束故障
    LCD_DrawImage1BPP(x + 42, y + 8 + 38 * 3, BMP_Xianshu, color, BLACK);
    LCD_DrawImage1BPP(x + 42 + 42, y + 8 + 38 * 3, BMP_Guzhang, color, BLACK);

    print_SZ_1(x - 60, y + 38 * 4, 5, 3, 0, WHITE);
    LCD_DrawImage1BPP(x, y + 8 + 38 * 4, BMP_i, color, BLACK); //IPM故障
    LCD_DrawImage1BPP(x + 11, y + 8 + 38 * 4, BMP_p, color, BLACK);
    LCD_DrawImage1BPP(x + 11 + 11, y + 8 + 38 * 4, BMP_m, color, BLACK);
    LCD_DrawImage1BPP(x + 11 + 11 + 11, y + 8 + 38 * 4, BMP_Guzhang, color, BLACK);

    print_SZ_1(x - 60, y + 38 * 5, 6, 3, 0, WHITE);
    LCD_DrawImage1BPP(x, y + 8 + 38 * 5, BMP_Zhu, color, BLACK); //主继电器故障
    LCD_DrawImage1BPP(x + 21, y + 8 + 38 * 5, BMP_Jidianqi, color, BLACK);
    LCD_DrawImage1BPP(x + 21 + 63, y + 8 + 38 * 5, BMP_Guzhang, color, BLACK);

    print_SZ_1(x - 60, y + 38 * 6, 7, 3, 0, WHITE);
    LCD_DrawImage1BPP(x, y + 8 + 38 * 6, BMP_Yuchong, color, BLACK); //预充继电器故障
    LCD_DrawImage1BPP(x + 42, y + 8 + 38 * 6, BMP_Jidianqi, color, BLACK);
    LCD_DrawImage1BPP(x + 42 + 63, y + 8 + 38 * 6, BMP_Guzhang, color, BLACK);

    print_SZ_1(x - 60, y + 38 * 7, 8, 3, 0, WHITE);
    LCD_DrawImage1BPP(x, y + 8 + 38 * 7, BMP_Ruanjian, color, BLACK); //软件故障
    LCD_DrawImage1BPP(x + 42, y + 8 + 38 * 7, BMP_Guzhang, color, BLACK);

    print_SZ_1(x - 60, y + 38 * 8, 51, 3, 0, WHITE);
    LCD_DrawImage1BPP(x, y + 8 + 38 * 8, BMP_DJ, color, BLACK); //电机过温故障
    LCD_DrawImage1BPP(x + 42, y + 8 + 38 * 8, BMP_Guo, color, BLACK);
    LCD_DrawImage1BPP(x + 42 + 21, y + 8 + 38 * 8, BMP_Wendu, color, BLACK);
    LCD_DrawImage1BPP(x + 42 + 42, y + 8 + 38 * 8, BMP_Guzhang, color, BLACK);

    print_SZ_1(x - 60, y + 38 * 9, 52, 3, 0, WHITE);
    LCD_DrawImage1BPP(x, y + 8 + 38 * 9, BMP_Mokuai, color, BLACK); //模块过温故障
    LCD_DrawImage1BPP(x + 42, y + 8 + 38 * 9, BMP_Guo, color, BLACK);
    LCD_DrawImage1BPP(x + 42 + 21, y + 8 + 38 * 9, BMP_Wendu, color, BLACK);
    LCD_DrawImage1BPP(x + 42 + 42, y + 8 + 38 * 9, BMP_Guzhang, color, BLACK);

    print_SZ_1(x - 60 + 320, y, 53, 3, 0, WHITE);
    LCD_DrawImage1BPP(x + 320, y + 8, BMP_DJ, color, BLACK); //电机超速故障
    LCD_DrawImage1BPP(x + 320 + 42, y + 8, BMP_Chaosu, color, BLACK);
    LCD_DrawImage1BPP(x + 320 + 42 + 42, y + 8, BMP_Guzhang, color, BLACK);

    print_SZ_1(x - 60 + 320, y  + 38, 54, 3, 0, WHITE);
    print_SZ(x + 320, y + 12 + 38, 24, 2, 0, color);
    LCD_DrawImage1BPP(x + 320 + 16, y + 8 + 38, BMP_v, color, BLACK); //24V欠压故障
    LCD_DrawImage1BPP(x + 320 + 16 + 11, y + 8 + 38, BMP_Qian, color, BLACK);
    LCD_DrawImage1BPP(x + 320 + 16 + 11, y + 8 + 38, BMP_DY, color, BLACK);
    LCD_DrawImage1BPP(x + 320 + 16 + 11 + 42, y + 8 + 38, BMP_Guzhang, color, BLACK);

    print_SZ_1(x - 60 + 320, y + 38 * 2, 55, 3, 0, WHITE);
    print_SZ(x + 320, y + 12 + 38 * 2, 24, 2, 0, color);
    LCD_DrawImage1BPP(x + 320 + 16, y + 8 + 38 * 2, BMP_v, color, BLACK); //24V过压故障                    
    LCD_DrawImage1BPP(x + 320 + 16 + 11, y + 8 + 38 * 2, BMP_DY, color, BLACK);
    LCD_DrawImage1BPP(x + 320 + 16 + 11, y + 8 + 38 * 2, BMP_Guo, color, BLACK);
    LCD_DrawImage1BPP(x + 320 + 16 + 11 + 42, y + 8 + 38 * 2, BMP_Guzhang, color, BLACK);

    print_SZ_1(x - 60 + 320, y + 38 * 3, 56, 3, 0, WHITE);
    LCD_DrawImage1BPP(x + 320, y + 8 + 38 * 3, BMP_c, color, BLACK); //CAN通讯故障
    LCD_DrawImage1BPP(x + 320 + 11, y + 8 + 38 * 3, BMP_a, color, BLACK);
    LCD_DrawImage1BPP(x + 320 + 11 + 11, y + 8 + 38 * 3, BMP_n, color, BLACK);
    LCD_DrawImage1BPP(x + 320 + 11 + 11 + 11, y + 8 + 38 * 3, BMP_Tongxun, color, BLACK);
    LCD_DrawImage1BPP(x + 320 + 11 + 11 + 11 + 42, y + 8 + 38 * 3, BMP_Guzhang, color, BLACK);

    print_SZ_1(x - 60 + 320, y + 38 * 4, 57, 3, 0, WHITE);
    LCD_DrawImage1BPP(x + 320, y + 8 + 38 * 4, BMP_DL, color, BLACK); //过流故障
    LCD_DrawImage1BPP(x + 320, y + 8 + 38 * 4, BMP_Guo, color, BLACK);
    LCD_DrawImage1BPP(x + 320 + 42, y + 8 + 38 * 4, BMP_Guzhang, color, BLACK);

    print_SZ_1(x - 60 + 320, y + 38 * 5, 58, 3, 0, WHITE);
    LCD_DrawImage1BPP(x + 320, y + 8 + 38 * 5, BMP_Guo, color, BLACK); //过载故障  
    LCD_DrawImage1BPP(x + 320 + 21, y + 8 + 38 * 5, BMP_Zai, color, BLACK);
    LCD_DrawImage1BPP(x + 320 + 42, y + 8 + 38 * 5, BMP_Guzhang, color, BLACK);

    print_SZ_1(x - 60 + 320, y+ 38 * 6, 59, 3, 0, WHITE);
    LCD_DrawImage1BPP(x + 320, y + 8 + 38 * 6, BMP_DY, color, BLACK); //欠压故障
    LCD_DrawImage1BPP(x + 320, y + 8 + 38 * 6, BMP_Qian, color, BLACK);
    LCD_DrawImage1BPP(x + 320 + 42, y + 8 + 38 * 6, BMP_Guzhang, color, BLACK);

    print_SZ_1(x - 60 + 320, y  + 38 * 7, 60, 3, 0, WHITE);
    LCD_DrawImage1BPP(x + 320, y + 8 + 38 * 7, BMP_DY, color, BLACK); //过压故障
    LCD_DrawImage1BPP(x + 320, y + 8 + 38 * 7, BMP_Guo, color, BLACK);
    LCD_DrawImage1BPP(x + 42 + 320, y + 8 + 38 * 7, BMP_Guzhang, color, BLACK);

    print_SZ_1(x - 60 + 320, y + 38 * 8, 61, 3, 0, WHITE);
    LCD_DrawImage1BPP(x + 320, y + 8 + 38 * 8, BMP_Xiangweijiao, color, BLACK); //相位角故障
    LCD_DrawImage1BPP(x + 320 + 63, y + 8 + 38 * 8, BMP_Guzhang, color, BLACK);

    print_SZ_1(x - 60 + 320, y + 38 * 9, 62, 3, 0, WHITE);
    LCD_DrawImage1BPP(x + 320, y + 8 + 38 * 9, BMP_Yingjian, color, BLACK); //硬件母线过流故障
    LCD_DrawImage1BPP(x + 320 + 42, y + 8 + 38 * 9, BMP_Muxian, color, BLACK);
    LCD_DrawImage1BPP(x + 320 + 42 + 42, y + 8 + 38 * 9, BMP_DL, color, BLACK);
    LCD_DrawImage1BPP(x + 320 + 42 + 42, y + 8 + 38 * 9, BMP_Guo, color, BLACK);
    LCD_DrawImage1BPP(x + 320 + 42 + 42 + 42, y + 8 + 38 * 9, BMP_Guzhang, color, BLACK);

}

void BMP_MOTO_CODE2(unsigned int x, unsigned int y, unsigned char color) {
    print_SZ_1(x - 60, y, 65, 3, 0, WHITE);
    LCD_DrawImage1BPP(x, y + 8, BMP_Yingjian, color, BLACK); //硬件母线过压故障
    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Muxian, color, BLACK);
    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_DY, color, BLACK);
    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Guo, color, BLACK);
    LCD_DrawImage1BPP(x + 42 + 42 + 42, y + 8, BMP_Guzhang, color, BLACK);

    print_SZ_1(x - 60, y  + 38, 66, 3, 0, WHITE);
    LCD_DrawImage1BPP(x, y + 8 + 38, BMP_Yingjian, color, BLACK); //硬件母线过流故障
    LCD_DrawImage1BPP(x + 42, y + 8 + 38, BMP_Muxian, color, BLACK);
    LCD_DrawImage1BPP(x + 42 + 42, y + 8 + 38, BMP_DL, color, BLACK);
    LCD_DrawImage1BPP(x + 42 + 42, y + 8 + 38, BMP_Guo, color, BLACK);
    LCD_DrawImage1BPP(x + 42 + 42 + 42, y + 8 + 38, BMP_Guzhang, color, BLACK);

    print_SZ_1(x - 60, y  + 38 * 2, 101, 3, 0, WHITE);
    LCD_DrawImage1BPP(x, y + 8 + 38 * 2, BMP_Muxian, color, BLACK); //母线过压报警
    LCD_DrawImage1BPP(x + 42, y + 8 + 38 * 2, BMP_DY, color, BLACK);
    LCD_DrawImage1BPP(x + 42, y + 8 + 38 * 2, BMP_Guo, color, BLACK);
    LCD_DrawImage1BPP(x + 42 + 42, y + 8 + 38 * 2, BMP_Baojing, color, BLACK);

    print_SZ_1(x - 60, y + 38 * 3, 102, 3, 0, WHITE);
    LCD_DrawImage1BPP(x, y + 8 + 38 * 3, BMP_Muxian, color, BLACK); //母线过压报警
    LCD_DrawImage1BPP(x + 42, y + 8 + 38 * 3, BMP_DY, color, BLACK);
    LCD_DrawImage1BPP(x + 42, y + 8 + 38 * 3, BMP_Qian, color, BLACK);
    LCD_DrawImage1BPP(x + 42 + 42, y + 8 + 38 * 3, BMP_Baojing, color, BLACK);

    print_SZ_1(x - 60, y + 38 * 4, 151, 3, 0, WHITE);
    LCD_DrawImage1BPP(x, y + 8 + 38 * 4, BMP_DJ, color, BLACK); //电机过温报警                   
    LCD_DrawImage1BPP(x + 42 + 21, y + 8 + 38 * 4, BMP_Wendu, color, BLACK);
    LCD_DrawImage1BPP(x + 42, y + 8 + 38 * 4, BMP_Guo, color, BLACK);
    LCD_DrawImage1BPP(x + 42 + 42, y + 8 + 38 * 4, BMP_Baojing, color, BLACK);

    print_SZ_1(x - 60, y + 38 * 5, 152, 3, 0, WHITE);
    LCD_DrawImage1BPP(x, y + 8 + 38 * 5, BMP_Mokuai, color, BLACK); //模块过温报警                   
    LCD_DrawImage1BPP(x + 42 + 21, y + 8 + 38 * 5, BMP_Wendu, color, BLACK);
    LCD_DrawImage1BPP(x + 42, y + 8 + 38 * 5, BMP_Guo, color, BLACK);
    LCD_DrawImage1BPP(x + 42 + 42, y + 8 + 38 * 5, BMP_Baojing, color, BLACK);
}
 */

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

void disp_miles(void) {//显示里程
    print_SZ_1(10, 318 + 15 + 38 + 2, total_miles / 10, 7, 0, WHITE);
    print_SZ_1(10 + 16, 318 + 15 + 38 * 2 + 2, single_miles, 5, 1, WHITE);
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
    //if (frmID == 1) {
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

    //}
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
    static unsigned char COLOR = GRAY;
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

    if (fKH1) color = RED;
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

    if (mKL2) color_old[7] = RED;
    else if(LED2) color_old[7] = GRAY;
    //if (color_old[7] != color) {
    //    color_old[7] = color;
        LCD_DrawImage1BPP(10 + 66 * 7, 5, Bmp_baojing[7], color_old[7], BLACK); //门铃

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
        LCD_DrawImage1BPP(10 + 66 * 9, 5, Bmp_baojing[13], color, BLACK); //水位报警
    }

    if (fKL7)
        color = RED;
    else color = GRAY;
    if (color_old[10] != color) {
        color_old[10] = color;
        LCD_DrawImage1BPP(10 + 66 * 10, 5, Bmp_baojing[10], color, BLACK); //安全带
    }

    if ((DMC_Status == 3) && (DMC_Level == 0)) color = RED;
    else color = GRAY;
    if (color_old[15] != color) {
        color_old[15] = color;
        LCD_DrawImage1BPP(10 + 66 * 11, 5, Bmp_baojing[11], color, BLACK); //整车故障
    }

    if (!rKL7 && DMC_Status == 0) color = RED;
    else color = GRAY;
    if (color_old[16] != color) {
        color_old[16] = color;
        LCD_DrawImage1BPP(142 + 66 * 0, 74 - 10, Bmp_baojing[12], color, BLACK); //重力感应报警
    }
    
    if (CAN_0xCFE5A2F.four1_1 == 6 
            || CAN_0xCFE5A2F.four1_1 == 7
            || CAN_0xCFE5A2F.four1_2 == 6
            || CAN_0xCFE5A2F.four1_2 == 7
            || CAN_0xCFE5A2F.four4_1 == 1
            || CAN_0xCFE5A2F.four4_1 == 2
            || CAN_0xCFE5A2F.four4_1 == 3
            ) COLOR = YELLOW;
    else if ((CAN_0xCFE5A2F.four1_1 == 1 && CAN_0xCFE5A2F.four1_2 == 1))
        COLOR = GRAY;
    if (color_old[17] != COLOR) {
        color_old[17] = COLOR;
        LCD_DrawImageSBPP(142 + 66 * 1 + 5, 74 - 6 , 11, ECAS, COLOR, BLACK); //ECAS空气悬挂报警
        LCD_DrawImage1BPP(142 + 66 * 1 + 5, 74 + 15 , BMP_Anquan, COLOR, BLACK);
    }
    
    if (CAN_0xCFE5A2F.four4_1 == 2) 
        color = GREEN;
    else if ((CAN_0xCFE5A2F.four1_1 == 1 && CAN_0xCFE5A2F.four1_2 == 1) ||
              CAN_0xCFE5A2F.four4_1 == 0
            )color = GRAY;
    else color = color_old[18];
    if (color_old[18] != color) {
        color_old[18] = color;
        LCD_DrawImage1BPP(142 + 66 * 2 + 5, 74 + 5 ,BMP_Cegui, color, BLACK); //侧跪
    }

    if (DMC_Status == 0) color = GREEN;
    else color = GRAY;
    if (color_old[19] != color) {
        color_old[19] = color;
        LCD_DrawImage1BPP(138 + 66 * 3 - 1, 74 + 12 - 5, Bmp_READY, color, BLACK); //ready
    }
    
    if (CAN_18FECA2F.DTC1.Fault > 0)
        color = RED;
    else if (CAN_18FECA2F.DTC1.Fault == 0)
        color = GRAY;
    else color = color_old[20];
    if (color_old[20] != color) {
        color_old[20] = color;
        LCD_DrawImageSBPP(142 + 66 * 5 + 5, 74 - 6 , 11, ECAS, color, BLACK); //ECAS空气悬挂故障
        LCD_DrawImage1BPP(142 + 66 * 5 + 5, 74 + 15 , BMP_Guzhang, color, BLACK);
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
    static unsigned char al_index = 0, Comm_i = 0, Comm_j = 0, Bala_i = 0, Bala_j = 0, FLAG;
    if (alarm_update_flag == 0) { //3S 更新一次 
        switch (al_index) {
            case 0:
                al_index = 1;
                /*switch (index1) {
                    case 0:
                        index1 = 1;
                        if ((BMU_Comm_Status1 & 0x01) == 1) {
                            print_SZ(x + 33, y + 12, 1, 2, 0, YELLOW);
                            F_Comm = 1;
                            break;
                        }
                    case 1:
                        index1 = 2;
                        if (((BMU_Comm_Status1 >> 1) & 0x01) == 1) {
                            print_SZ(x + 33, y + 12, 2, 2, 0, YELLOW);
                            F_Comm = 1;
                            break;
                        }
                    case 2:
                        index1 = 3;
                        if (((BMU_Comm_Status1 >> 2) & 0x01) == 1) {
                            print_SZ(x + 33, y + 12, 3, 2, 0, YELLOW);
                            F_Comm = 1;
                            break;
                        }
                    case 3:
                        index1 = 4;
                        if (((BMU_Comm_Status1 >> 3) & 0x01) == 1) {
                            print_SZ(x + 33, y + 12, 4, 2, 0, YELLOW);
                            F_Comm = 1;
                            break;
                        }
                    case 4:
                        index1 = 5;
                        if (((BMU_Comm_Status1 >> 4) & 0x01) == 1) {
                            print_SZ(x + 33, y + 12, 5, 2, 0, YELLOW);
                            F_Comm = 1;
                            break;
                        }
                    case 5:
                        index1 = 6;
                        if (((BMU_Comm_Status1 >> 5) & 0x01) == 1) {
                            print_SZ(x + 33, y + 12, 6, 2, 0, YELLOW);
                            F_Comm = 1;
                            break;
                        }
                    case 6:
                        index1 = 7;
                        if (((BMU_Comm_Status1 >> 6) & 0x01) == 1) {
                            print_SZ(x + 33, y + 12, 7, 2, 0, YELLOW);
                            F_Comm = 1;
                            break;
                        }
                    case 7:
                        index1 = 8;
                        if (((BMU_Comm_Status1 >> 7) & 0x01) == 1) {
                            print_SZ(x + 33, y + 12, 8, 2, 0, YELLOW);
                            F_Comm = 1;
                            break;
                        }
                    case 8:
                        index1 = 9;
                        if ((BMU_Comm_Status2 & 0x01) == 1) {
                            print_SZ(x + 33, y + 12, 9, 2, 0, YELLOW);
                            F_Comm = 1;
                            break;
                        }
                    case 9:
                        index1 = 10;
                        if (((BMU_Comm_Status2 >> 1) & 0x01) == 1) {
                            print_SZ(x + 33, y + 12, 10, 2, 0, YELLOW);
                            F_Comm = 1;
                            break;
                        }
                    case 10:
                        index1 = 11;
                        if (((BMU_Comm_Status2 >> 2) & 0x01) == 1) {
                            print_SZ(x + 33, y + 12, 11, 2, 0, YELLOW);
                            F_Comm = 1;
                            break;
                        }
                    case 11:
                        index1 = 12;
                        if (((BMU_Comm_Status2 >> 3) & 0x01) == 1) {
                            print_SZ(x + 33, y + 12, 12, 2, 0, YELLOW);
                            F_Comm = 1;
                            break;
                        }
                    case 12:
                        index1 = 13;
                        if (((BMU_Comm_Status2 >> 4) & 0x01) == 1) {
                            print_SZ(x + 33, y + 12, 13, 2, 0, YELLOW);
                            F_Comm = 1;
                            break;
                        }
                    case 13:
                        index1 = 14;
                        if (((BMU_Comm_Status2 >> 5) & 0x01) == 1) {
                            print_SZ(x + 33, y + 12, 14, 2, 0, YELLOW);
                            F_Comm = 1;
                            break;
                        }
                    case 14:
                        index1 = 15;
                        if (((BMU_Comm_Status2 >> 6) & 0x01) == 1) {
                            print_SZ(x + 33, y + 12, 15, 2, 0, YELLOW);
                            F_Comm = 1;
                            break;
                        }
                    case 15:
                        index1 = 16;
                        if (((BMU_Comm_Status2 >> 7) & 0x01) == 1) {
                            print_SZ(x + 33, y + 12, 16, 2, 0, YELLOW);
                            F_Comm = 1;
                            break;
                        }
                    case 16:
                        index1 = 17;
                        if ((BMU_Comm_Status3 & 0x01) == 1) {
                            print_SZ(x + 33, y + 12, 17, 2, 0, YELLOW);
                            F_Comm = 1;
                            break;
                        }
                    case 17:
                        index1 = 18;
                        if (((BMU_Comm_Status3 >> 1) & 0x01) == 1) {
                            print_SZ(x + 33, y + 12, 18, 2, 0, YELLOW);
                            F_Comm = 1;
                            break;
                        }
                    case 18:
                        index1 = 19;
                        if (((BMU_Comm_Status3 >> 2) & 0x01) == 1) {
                            print_SZ(x + 33, y + 12, 19, 2, 0, YELLOW);
                            F_Comm = 1;
                            break;
                        }
                    case 19:
                        index1 = 20;
                        if (((BMU_Comm_Status3 >> 3) & 0x01) == 1) {
                            print_SZ(x + 33, y + 12, 20, 2, 0, YELLOW);
                            F_Comm = 1;
                            break;
                        }
                    case 20:
                        index1 = 21;
                        if (((BMU_Comm_Status3 >> 4) & 0x01) == 1) {
                            print_SZ(x + 33, y + 12, 21, 2, 0, YELLOW);
                            F_Comm = 1;
                            break;
                        }
                    case 21:
                        index1 = 22;
                        if (((BMU_Comm_Status3 >> 5) & 0x01) == 1) {
                            print_SZ(x + 33, y + 12, 22, 2, 0, YELLOW);
                            F_Comm = 1;
                            break;
                        }
                    case 22:
                        index1 = 23;
                        if (((BMU_Comm_Status3 >> 6) & 0x01) == 1) {
                            print_SZ(x + 33, y + 12, 23, 2, 0, YELLOW);
                            F_Comm = 1;
                            break;
                        }
                    case 23:
                        index1 = 24;
                        if (((BMU_Comm_Status3 >> 7) & 0x01) == 1) {
                            print_SZ(x + 33, y + 12, 24, 2, 0, YELLOW);
                            F_Comm = 1;
                            break;
                        }
                    case 24:
                        index1 = 25;
                        if ((BMU_Comm_Status4 & 0x01) == 1) {
                            print_SZ(x + 33, y + 12, 25, 2, 0, YELLOW);
                            F_Comm = 1;
                            break;
                        }
                    case 25:
                        index1 = 26;
                        if (((BMU_Comm_Status4 >> 1) & 0x01) == 1) {
                            print_SZ(x + 33, y + 12, 26, 2, 0, YELLOW);
                            F_Comm = 1;
                            break;
                        }
                    case 26:
                        index1 = 27;
                        if (((BMU_Comm_Status4 >> 2) & 0x01) == 1) {
                            print_SZ(x + 33, y + 12, 27, 2, 0, YELLOW);
                            F_Comm = 1;
                            break;
                        }
                    case 27:
                        index1 = 28;
                        if (((BMU_Comm_Status4 >> 3) & 0x01) == 1) {
                            print_SZ(x + 33, y + 12, 28, 2, 0, YELLOW);
                            F_Comm = 1;
                            break;
                        }
                    case 28:
                        index1 = 29;
                        if (((BMU_Comm_Status4 >> 4) & 0x01) == 1) {
                            print_SZ(x + 33, y + 12, 29, 2, 0, YELLOW);
                            F_Comm = 1;
                            break;
                        }
                    case 29:
                        index1 = 30;
                        if (((BMU_Comm_Status4 >> 5) & 0x01) == 1) {
                            print_SZ(x + 33, y + 12, 30, 2, 0, YELLOW);
                            F_Comm = 1;
                            break;
                        }
                    case 30:
                        index1 = 31;
                        if (((BMU_Comm_Status4 >> 6) & 0x01) == 1) {
                            print_SZ(x + 33, y + 12, 31, 2, 0, YELLOW);
                            F_Comm = 1;
                            break;
                        }
                    case 31:
                        index1 = 0;
                        if (((BMU_Comm_Status4 >> 7) & 0x01) == 1) {
                            print_SZ(x + 33, y + 12, 32, 2, 0, YELLOW);
                            F_Comm = 1;
                            break;
                        }
                    default:
                        index1 = 0;
                        break;
                }*/
                for (; Comm_j < 4;) {
                    for (; Comm_i < 8 && !FLAG; Comm_i++) {
                        if ((BMU_Comm_Status[Comm_j].byte >> Comm_i) & 0x01)
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
                    LCD_DrawImage1BPP(x, y + 8, BMP_BMU, YELLOW, BLACK); //BMU通讯故障
                    print_SZ(x + 33, y + 12, Comm_j * 8 + Comm_i, 2, 0, YELLOW);
                    LCD_DrawImage1BPP(x + 33 + 16, y + 8, BMP_Tongxun, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 33 + 16 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 33 + 42 + 16 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
                if (Comm_j >= 4) {
                    Comm_j = 0;
                }

            case 1:
                al_index = 2;
                /*switch (index2) {
                    case 0:
                        index2 = 1;
                        if ((BMU_Bala_Status1 & 0x01) == 1) {
                            print_SZ(x + 33, y + 12, 1, 2, 0, YELLOW);
                            F_Bala = 1;
                            break;
                        }
                    case 1:
                        index2 = 2;
                        if (((BMU_Bala_Status1 >> 1) & 0x01) == 1) {
                            print_SZ(x + 33, y + 12, 2, 2, 0, YELLOW);
                            F_Bala = 1;
                            break;
                        }
                    case 2:
                        index2 = 3;
                        if (((BMU_Bala_Status1 >> 2) & 0x01) == 1) {
                            print_SZ(x + 33, y + 12, 3, 2, 0, YELLOW);
                            F_Bala = 1;
                            break;
                        }
                    case 3:
                        index2 = 4;
                        if (((BMU_Bala_Status1 >> 3) & 0x01) == 1) {
                            print_SZ(x + 33, y + 12, 4, 2, 0, YELLOW);
                            F_Bala = 1;
                            break;
                        }
                    case 4:
                        index2 = 5;
                        if (((BMU_Bala_Status1 >> 4) & 0x01) == 1) {
                            print_SZ(x + 33, y + 12, 5, 2, 0, YELLOW);
                            F_Bala = 1;
                            break;
                        }
                    case 5:
                        index2 = 6;
                        if (((BMU_Bala_Status1 >> 5) & 0x01) == 1) {
                            print_SZ(x + 33, y + 12, 6, 2, 0, YELLOW);
                            F_Bala = 1;
                            break;
                        }
                    case 6:
                        index2 = 7;
                        if (((BMU_Bala_Status1 >> 6) & 0x01) == 1) {
                            print_SZ(x + 33, y + 12, 7, 2, 0, YELLOW);
                            F_Bala = 1;
                            break;
                        }
                    case 7:
                        index2 = 8;
                        if (((BMU_Bala_Status1 >> 7) & 0x01) == 1) {
                            print_SZ(x + 33, y + 12, 8, 2, 0, YELLOW);
                            F_Bala = 1;
                            break;
                        }
                    case 8:
                        index2 = 9;
                        if ((BMU_Bala_Status2 & 0x01) == 1) {
                            print_SZ(x + 33, y + 12, 9, 2, 0, YELLOW);
                            F_Bala = 1;
                            break;
                        }
                    case 9:
                        index2 = 10;
                        if (((BMU_Bala_Status2 >> 1) & 0x01) == 1) {
                            print_SZ(x + 33, y + 12, 10, 2, 0, YELLOW);
                            F_Bala = 1;
                            break;
                        }
                    case 10:
                        index2 = 11;
                        if (((BMU_Bala_Status2 >> 2) & 0x01) == 1) {
                            print_SZ(x + 33, y + 12, 11, 2, 0, YELLOW);
                            F_Bala = 1;
                            break;
                        }
                    case 11:
                        index2 = 12;
                        if (((BMU_Bala_Status2 >> 3) & 0x01) == 1) {
                            print_SZ(x + 33, y + 12, 12, 2, 0, YELLOW);
                            F_Bala = 1;
                            break;
                        }
                    case 12:
                        index2 = 13;
                        if (((BMU_Bala_Status2 >> 4) & 0x01) == 1) {
                            print_SZ(x + 33, y + 12, 13, 2, 0, YELLOW);
                            F_Bala = 1;
                            break;
                        }
                    case 13:
                        index2 = 14;
                        if (((BMU_Bala_Status2 >> 5) & 0x01) == 1) {
                            print_SZ(x + 33, y + 12, 14, 2, 0, YELLOW);
                            F_Bala = 1;
                            break;
                        }
                    case 14:
                        index2 = 15;
                        if (((BMU_Bala_Status2 >> 6) & 0x01) == 1) {
                            print_SZ(x + 33, y + 12, 15, 2, 0, YELLOW);
                            F_Bala = 1;
                            break;
                        }
                    case 15:
                        index2 = 16;
                        if (((BMU_Bala_Status2 >> 7) & 0x01) == 1) {
                            print_SZ(x + 33, y + 12, 16, 2, 0, YELLOW);
                            F_Bala = 1;
                            break;
                        }
                    case 16:
                        index2 = 17;
                        if ((BMU_Bala_Status3 & 0x01) == 1) {
                            print_SZ(x + 33, y + 12, 17, 2, 0, YELLOW);
                            F_Bala = 1;
                            break;
                        }
                    case 17:
                        index2 = 18;
                        if (((BMU_Bala_Status3 >> 1) & 0x01) == 1) {
                            print_SZ(x + 33, y + 12, 18, 2, 0, YELLOW);
                            F_Bala = 1;
                            break;
                        }
                    case 18:
                        index2 = 19;
                        if (((BMU_Bala_Status3 >> 2) & 0x01) == 1) {
                            print_SZ(x + 33, y + 12, 19, 2, 0, YELLOW);
                            F_Bala = 1;
                            break;
                        }
                    case 19:
                        index2 = 20;
                        if (((BMU_Bala_Status3 >> 3) & 0x01) == 1) {
                            print_SZ(x + 33, y + 12, 20, 2, 0, YELLOW);
                            F_Bala = 1;
                            break;
                        }
                    case 20:
                        index2 = 21;
                        if (((BMU_Bala_Status3 >> 4) & 0x01) == 1) {
                            print_SZ(x + 33, y + 12, 21, 2, 0, YELLOW);
                            F_Bala = 1;
                            break;
                        }
                    case 21:
                        index2 = 22;
                        if (((BMU_Bala_Status3 >> 5) & 0x01) == 1) {
                            print_SZ(x + 33, y + 12, 22, 2, 0, YELLOW);
                            F_Bala = 1;
                            break;
                        }
                    case 22:
                        index2 = 23;
                        if (((BMU_Bala_Status3 >> 6) & 0x01) == 1) {
                            print_SZ(x + 33, y + 12, 23, 2, 0, YELLOW);
                            F_Bala = 1;
                            break;
                        }
                    case 23:
                        index2 = 24;
                        if (((BMU_Bala_Status3 >> 7) & 0x01) == 1) {
                            print_SZ(x + 33, y + 12, 24, 2, 0, YELLOW);
                            F_Bala = 1;
                            break;
                        }
                    case 24:
                        index2 = 25;
                        if ((BMU_Bala_Status4 & 0x01) == 1) {
                            print_SZ(x + 33, y + 12, 25, 2, 0, YELLOW);
                            F_Bala = 1;
                            break;
                        }
                    case 25:
                        index2 = 26;
                        if (((BMU_Bala_Status4 >> 1) & 0x01) == 1) {
                            print_SZ(x + 33, y + 12, 26, 2, 0, YELLOW);
                            F_Bala = 1;
                            break;
                        }
                    case 26:
                        index2 = 27;
                        if (((BMU_Bala_Status4 >> 2) & 0x01) == 1) {
                            print_SZ(x + 33, y + 12, 27, 2, 0, YELLOW);
                            F_Bala = 1;
                            break;
                        }
                    case 27:
                        index2 = 28;
                        if (((BMU_Bala_Status4 >> 3) & 0x01) == 1) {
                            print_SZ(x + 33, y + 12, 28, 2, 0, YELLOW);
                            F_Bala = 1;
                            break;
                        }
                    case 28:
                        index2 = 29;
                        if (((BMU_Bala_Status4 >> 4) & 0x01) == 1) {
                            print_SZ(x + 33, y + 12, 29, 2, 0, YELLOW);
                            F_Bala = 1;
                            break;
                        }
                    case 29:
                        index2 = 30;
                        if (((BMU_Bala_Status4 >> 5) & 0x01) == 1) {
                            print_SZ(x + 33, y + 12, 30, 2, 0, YELLOW);
                            F_Bala = 1;
                            break;
                        }
                    case 30:
                        index2 = 31;
                        if (((BMU_Bala_Status4 >> 6) & 0x01) == 1) {
                            print_SZ(x + 33, y + 12, 21, 2, 0, YELLOW);
                            F_Bala = 1;
                            break;
                        }
                    case 31:
                        index2 = 0;
                        if (((BMU_Bala_Status4 >> 7) & 0x01) == 1) {
                            print_SZ(x + 33, y + 12, 32, 2, 0, YELLOW);
                            F_Bala = 1;
                            break;
                        }
                    default:
                        index2 = 0;
                        break;
                }*/
                for (; Bala_j < 4;) {
                    for (; Bala_i < 8 && !FLAG; Bala_i++) {
                        if ((BMU_Bala_Status[Bala_j].byte >> Bala_i) & 0x01)
                            FLAG = 1;
                    }
                    if (Bala_i >= 8) {
                        Bala_i = 0;
                        Bala_j++;
                    }
                    if (FLAG) break;
                }
                if (FLAG) {
                    FLAG = 0;
                    LCD_DrawImage1BPP(x, y + 8, BMP_BMU, YELLOW, BLACK); //BMU均衡故障
                    print_SZ(x + 33, y + 12, Bala_j * 8 + Bala_i, 2, 0, YELLOW);
                    LCD_DrawImage1BPP(x + 33 + 16, y + 8, BMP_Junheng, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 33 + 16 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 33 + 42 + 16 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
                if (Bala_j >= 4) {
                    Bala_j = 0;
                }

            case 2:
                al_index = 3;
                /*if (Rcan_count == CAN_TIME) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Houbu, YELLOW, BLACK); //后部
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Mokuai, YELLOW, BLACK); //模块
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Lixian, YELLOW, BLACK); //离线
                    LCD_DrawRect(x + 42 + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/

                /*case 0:
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
                    }*/

            case 3:
                al_index = 4;
                if (BAT24V_count == BAT24_TIME) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Xu, YELLOW, BLACK); //蓄电池电压低
                    LCD_DrawImageSBPP(x + 21, y + 8, 42, DCDYD, YELLOW, BLACK);
                    LCD_DrawRect(x + 21 + 42 + 42 + 21, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 4:
                al_index = 5;
                if (DMC_Speed * 0.5 > 69) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Chaosu, YELLOW, BLACK); //超速报警
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
                /*case 9:
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
                    }*/

            case 5:
                al_index = 6;
                if (((BMS_Status_Flag1 & 0x03) == 1) || ((BMS_Status_Flag1 & 0x03) == 2)) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Dan, YELLOW, BLACK); //单体电压过低
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_Ti, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 21, y + 8, BMP_DY, YELLOW, BLACK);
                    if ((BMS_Status_Flag1 & 0x03) == 1) {
                        LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Yiban, YELLOW, BLACK);
                    } else if ((BMS_Status_Flag1 & 0x03) == 2) {
                        LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Yanzhong, YELLOW, BLACK);
                    }
                    LCD_DrawImage1BPP(x + 42 + 42 + 42, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 42 + 21, y + 8, BMP_Di, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42 + 42, y, 150, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 6:
                al_index = 7;
                if ((((BMS_Status_Flag1 >> 2) & 0x03) == 1) || (((BMS_Status_Flag1 >> 2) & 0x03) == 2)) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Dan, YELLOW, BLACK); //单体电压过高
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_Ti, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 21, y + 8, BMP_DY, YELLOW, BLACK);
                    if (((BMS_Status_Flag1 >> 2) & 0x03) == 1) {
                        LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Yiban, YELLOW, BLACK);
                    } else if (((BMS_Status_Flag1 >> 2) & 0x03) == 2) {
                        LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Yanzhong, YELLOW, BLACK);
                    }
                    LCD_DrawImage1BPP(x + 42 + 42 + 42, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 42 + 21, y + 8, BMP_Gao, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42 + 42, y, 150, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 7:
                al_index = 8;
                if ((((BMS_Status_Flag1 >> 4) & 0x03) == 1) || (((BMS_Status_Flag1 >> 4) & 0x03) == 2)) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Wendu, YELLOW, BLACK); //温度过低
                    if (((BMS_Status_Flag1 >> 4) & 0x03) == 1) {
                        LCD_DrawImage1BPP(x + 42, y + 8, BMP_Yiban, YELLOW, BLACK);
                    } else if (((BMS_Status_Flag1 >> 4) & 0x03) == 2) {
                        LCD_DrawImage1BPP(x + 42, y + 8, BMP_Yanzhong, YELLOW, BLACK);
                    }
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 21, y + 8, BMP_Di, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 8:
                al_index = 9;
                if ((((BMS_Status_Flag1 >> 6) & 0x03) == 1) || (((BMS_Status_Flag1 >> 6) & 0x03) == 2)) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Wendu, YELLOW, BLACK); //温度过高
                    if (((BMS_Status_Flag1 >> 6) & 0x03) == 1) {
                        LCD_DrawImage1BPP(x + 42, y + 8, BMP_Yiban, YELLOW, BLACK);
                    } else if (((BMS_Status_Flag1 >> 6) & 0x03) == 2) {
                        LCD_DrawImage1BPP(x + 42, y + 8, BMP_Yanzhong, YELLOW, BLACK);
                    }
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 21, y + 8, BMP_Gao, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 9:
                al_index = 10;
                if (((BMS_Status_Flag2 & 0x03) == 1) || ((BMS_Status_Flag2 & 0x03) == 2)) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_s, YELLOW, BLACK); //SOC过低
                    LCD_DrawImage1BPP(x + 11, y + 8, BMP_o, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11, y + 8, BMP_c, YELLOW, BLACK);
                    if (((BMS_Status_Flag2) & 0x03) == 1) {
                        LCD_DrawImage1BPP(x + 11 + 11 + 11, y + 8, BMP_Yiban, YELLOW, BLACK);
                    } else if (((BMS_Status_Flag2) & 0x03) == 2) {
                        LCD_DrawImage1BPP(x + 11 + 11 + 11, y + 8, BMP_Yanzhong, YELLOW, BLACK);
                    }
                    LCD_DrawImage1BPP(x + 11 + 11 + 11 + 42, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11 + 11 + 42 + 21, y + 8, BMP_Di, YELLOW, BLACK);
                    LCD_DrawRect(x + 11 + 11 + 11 + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 10:
                al_index = 11;
                if ((((BMS_Status_Flag2 >> 2) & 0x03) == 1) || (((BMS_Status_Flag2 >> 2) & 0x03) == 2)) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DL, YELLOW, BLACK); //电流过高
                    if (((BMS_Status_Flag2 >> 2) & 0x03) == 1) {
                        LCD_DrawImage1BPP(x + 42, y + 8, BMP_Yiban, YELLOW, BLACK);
                    } else if (((BMS_Status_Flag2 >> 2) & 0x03) == 2) {
                        LCD_DrawImage1BPP(x + 42, y + 8, BMP_Yanzhong, YELLOW, BLACK);
                    }
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 21, y + 8, BMP_Gao, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 11:
                al_index = 12;
                if ((((BMS_Status_Flag2 >> 4) & 0x03) == 1) || (((BMS_Status_Flag2 >> 4) & 0x03) == 2)) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Jueyuan, YELLOW, BLACK); //绝缘报警
                    if (((BMS_Status_Flag2 >> 4) & 0x03) == 1) {
                        LCD_DrawImage1BPP(x + 42, y + 8, BMP_Yiban, YELLOW, BLACK);
                    } else if (((BMS_Status_Flag2 >> 4) & 0x03) == 2) {
                        LCD_DrawImage1BPP(x + 42, y + 8, BMP_Yanzhong, YELLOW, BLACK);
                    }
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 12:
                al_index = 13;
                if ((((BMS_Status_Flag2 >> 6) & 0x03) == 1) || (((BMS_Status_Flag2 >> 6) & 0x03) == 2)) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DC, YELLOW, BLACK); //电池压差过大
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Yali, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 21, y + 8, BMP_Cha, YELLOW, BLACK);
                    if (((BMS_Status_Flag2 >> 6) & 0x03) == 1) {
                        LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Yiban, YELLOW, BLACK);
                    } else if (((BMS_Status_Flag2 >> 6) & 0x03) == 2) {
                        LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Yanzhong, YELLOW, BLACK);
                    }
                    LCD_DrawImage1BPP(x + 42 + 42 + 42, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 42 + 21, y + 8, BMP_Da, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42 + 42, y, 150, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 13:
                al_index = 14;
                if (((BMS_Status_Flag3 >> 1) & 0x01) == 1) {
                    LCD_DrawImageSBPP(x, y + 8, 42, CDTXYC, YELLOW, BLACK); //充电通讯异常
                    LCD_DrawRect(x + 42 + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 14:
                al_index = 15;
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

            case 15:
                al_index = 16;
                if (((BMS_Status_Flag3 >> 6) & 0x01) == 1) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Chongdian, YELLOW, BLACK); //充电接触器失效，立即手动停止充电
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Jiechuqi, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 63, y + 8, BMP_Shixiao, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 63 + 42, y + 8, BMP_Liji, YELLOW, BLACK);
                    //LCD_DrawRect(x + 42 + 63 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 16:
                al_index = 17;
                if (DMC_Level == 0 && DMC_Status == 3) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DJ, YELLOW, BLACK); //电机系统1级保护
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_System, YELLOW, BLACK);
                    print_SZ(x + 42 + 42, y + 12, 1, 1, 0, YELLOW);
                    LCD_DrawImage1BPP(x + 42 + 42 + 8, y + 8, BMP_Ji, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 8 + 21, y + 8, BMP_Baohu, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42 + 8 + 21, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 17:
                al_index = 18;
                if (DMC_Level == 1 && DMC_Status == 3) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DJ, YELLOW, BLACK); //电机系统2级保护
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_System, YELLOW, BLACK);
                    print_SZ(x + 42 + 42, y + 12, 2, 1, 0, YELLOW);
                    LCD_DrawImage1BPP(x + 42 + 42 + 8, y + 8, BMP_Ji, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 8 + 21, y + 8, BMP_Baohu, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42 + 8 + 21, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 18:
                al_index = 19;
                if (((DMY_Status >> 4) & 0x03) == 2) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Youbeng, YELLOW, BLACK); //油泵系统故障
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_System, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 19:
                al_index = 20;
                if (((DMQ_Status >> 4) & 0x03) == 2) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Qibeng, YELLOW, BLACK); //气泵系统故障
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_System, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 20:
                al_index = 21;
                if (DCDC_Code > 0) {
                    LCD_DrawImage1BPP(x, y + 6, BMP_DCDC, YELLOW, BLACK); //DCDC系统故障
                    LCD_DrawImage1BPP(x + 65, y + 8, BMP_System, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 65 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 65 + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 21:
                al_index = 22;
                if (((BMS_Status_Flag3 >> 7)&0x01) == 0) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_b, YELLOW, BLACK); //B级电压电路断开
                    LCD_DrawImage1BPP(x + 11, y + 8, BMP_Ji, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 21, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 21 + 42, y + 8, BMP_Dianluduankai, YELLOW, BLACK);
                    LCD_DrawRect(x + 11 + 21 + 42 + 84, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 22:
                al_index = 23;
                if (Fcan_count == CAN_TIME) {
                    LCD_DrawImageSBPP(x, y + 8, 42, QBMKLX, YELLOW, BLACK); //前部模块离线
                    LCD_DrawRect(x + 42 + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 23:
                al_index = 24;
                if (Mcan_count == CAN_TIME) {
                    LCD_DrawImageSBPP(x, y + 8, 42, DBMKLX, YELLOW, BLACK); //顶部模块离线
                    LCD_DrawRect(x + 42 + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 24:
                al_index = 25;
                if (((BMS_Status_Flag3 >> 2) & 0x01) == 1) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DL, YELLOW, BLACK); //电流传感器故障
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Chuanganqi, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 63, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 63 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 25:
                al_index = 26;
                if (((BMS_Status_Flag3 >> 4) & 0x01) == 1) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Qing, YELLOW, BLACK); //请求进入低速行驶模式
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_Qiu, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Jinru, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Chesu, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Di, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 42, y + 8, BMP_Xingshi, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 42 + 42, y + 8, BMP_Mode, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42 + 42 + 42, y, 130, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 26:
                al_index = 27;
                if (((BMS_Status_Flag3 >> 3) & 0x01) == 1) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Qing, YELLOW, BLACK); //请求进入强制停车模式
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_Qiu, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Jinru, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Qiangzhi, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 42, y + 8, BMP_Tingche, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 42 + 42, y + 8, BMP_Mode, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42 + 42 + 42, y, 130, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 27:
                al_index = 28;
                if (((BMS_Status_Flag6 >> 2) & 0x03) == 1) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DY, YELLOW, BLACK); //高压互锁报警
                    LCD_DrawImage1BPP(x, y + 8, BMP_Gao, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Husuo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 28:
                al_index = 29;
                if ((BMS_Status_Flag6 & 0x03) == 1) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Huozai, YELLOW, BLACK); //火灾报警
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42, y, 250, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
                
            case 29:
                al_index = 30;
                if (!rKL7 && DMC_Status == 0) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Zhongliganying, YELLOW, BLACK); //重力感应报警
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }  
            case 30:
                al_index = 31;
                if (Rcan_count == CAN_TIME) {
                    LCD_DrawImageSBPP(x, y + 8, 42, HBMKLX, YELLOW, BLACK); //后部模块离线
                    LCD_DrawRect(x + 42 + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
                
            case 31:
                al_index = 32;
                if (Air_Status_Flag1) {
                    LCD_DrawImageSBPP(x, y + 8, 42, KTXTGZ, YELLOW, BLACK); //空调系统故障
                    LCD_DrawRect(x + 42 + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 32:
                al_index = 33;
                if (buzz_run[1]) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Canjiren, YELLOW, BLACK); //残疾人上车呼叫
                    LCD_DrawImageSBPP(x + 63, y + 8, 21, SCHJ, YELLOW, BLACK);
                    LCD_DrawRect(x + 63 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 33:
                al_index = 34;
                if (0) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Canjiren, YELLOW, BLACK); //残疾人下车呼叫
                    LCD_DrawImageSBPP(x + 63, y + 8, 21, XCHJ, YELLOW, BLACK);
                    LCD_DrawRect(x + 63 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
                
            case 34:
                al_index = 35;
                if (fKL12) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Canjiren, YELLOW, BLACK); //残疾人踏板开
                    LCD_DrawImageSBPP(x + 63, y + 8, 42, TBK, YELLOW, BLACK);
                    LCD_DrawRect(x + 63 + 42 + 21, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
            default:
                al_index = 0;
                LCD_DrawRect(x, y, 340, 36, BLACK); //清除显示区域
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
        LCD_DrawImage1BPPZOOM_4(x - 25, y + 5, BMP_ZHENG, BLACK, BLACK);
        print_SZ_1(x, y, DAT - offset, sum, dot, color1); //电池电流数值 x=135+180+50+100+20+20   y=150+60-2
    }
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
        if (i == 7)
            color_old[i] = GRAY;
    }
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

}

void frmMain(void) {
    if (f_index == 0) { //只更新一次
        f_index = 1;
        mainFrame();
    } else if (f_index == 1) {
        f_index = 2;
        updata_DAT(700, 318 + 15 + 38, DMC_Torque * 0.1, 1, 3200, WHITE, 4, 0); //电机转矩
    } else if (f_index == 2) {
        f_index = 3;
        disp_baojing();
        print_SZ_1(305, 318 + 15 + 38, Battery_Single_H, 4, 3, WHITE); //单体高电压
        print_SZ_1(305, 318 + 15 + 38 * 2, Battery_Single_L, 4, 3, WHITE); //单体低电压
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
        updata_DAT(540 + 50, 318 + 15 + 38 * 2, DMC_Controller_temp, 1, 40, WHITE, 3, 0); //电机控制器温度
        updata_DAT(540 + 50, 318 + 15 + 38, DMC_Moto_temp, 1, 40, WHITE, 3, 0); //电机温度
    } else if (f_index == 5) {
        f_index = 6;
        updata_SOC(585, 155 - 10);
        updata_DAT(150 + 45, 318 + 15 + 38, BMS_V * 0.1, 1, 0, WHITE, 4, 0); //总电压
        //updata_DAT(150 + 45, 318 + 15 + 38 * 2, BMS_A * 0.1, 1, 3200, WHITE, 4, 0); //总电流
        updata_DCDL(150 + 45 + 16, 318 + 15 + 38 * 2); //总电流
    } else if (f_index == 6) {
        f_index = 7;
        updata_DAT(410 + 50, 318 + 15 + 38, Battery_Temp_H, 1, 40, WHITE, 3, 0); //单体高温
        updata_DAT(410 + 50, 318 + 15 + 38 * 2, Battery_Temp_L, 1, 40, WHITE, 3, 0); //单体低温       
        disp_CAN_baojing(2, 447);
    } else if (f_index == 7) {
        f_index = 1;
        updata_Dangwei(138 + 17 + 66 * 4, 74 - 5);
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
    }
    /***********************************************************/
    /*
        if (IN35 == 0) {//倒车视屏选择使能按键
            if (IN11 && R_flag == 0) {//倒挡
                key_AV = 1; //模拟AV开关按一次
                AV_CH = 0; //0+1=1  倒车
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
            unsigned char mode = 1; //1,MCU

            if (AV_CH < 4 && !time_flag) AV_CH++;
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
     */
}

/******************************************************/
//仪表诊断
/*******************************************************/
//只更新一次的数据
void ICFrame(unsigned char index) { //仪表框架
    unsigned char i;
    LCD_Clear();
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //顶部横线

    //CAN通讯
    LCD_DrawImageSBPP(130 + 200 + 200, 130 - 85 + 4, 11, CHAR_CAN, WHITE, BLACK);
    LCD_DrawImage1BPP(130 + 200 + 200 + 11 + 11 + 11, 130 - 85 + 4, BMP_Tongxun, WHITE, BLACK);

    //版本号
    LCD_DrawImage1BPP(505 + 100, 75 + 8 + 25 * 15, BMP_Banben, WHITE, BLACK);
    LCD_DrawImage1BPP(505 + 100 + 42, 75 + 8 + 25 * 15, BMP_Hao, WHITE, BLACK);
    LCD_DrawImage1BPP(505 + 200, 75 + 25 * 15, BMP_V, WHITE, BLACK);
    
    print_SZ_2(750, 50, index, 1, 0, WHITE); // 2/3
    LCD_DrawImage1BPP(750 + 11, 50, BMP_I, WHITE, BLACK);
    print_SZ_2(750 + 11 + 14, 50, 4, 1, 0, WHITE);

    if (index == 1) {
        LCD_DrawImageSBPP(130 + 200, 130 - 85, 50, IC_STSTEM, WHITE, BLACK); //仪表系统信息

        /***********************仪表开关量采集**********************************/
        //IN1  左转向
        LCD_DrawImage1BPP(35, 75, BMP_IC_Zuo, WHITE, BLACK);
        LCD_DrawImage1BPP(35 + 21, 75, BMP_IC_Zhuanxiang, WHITE, BLACK);
        //IN2
        //IN3  
        //IN4  ACC开关
        LCD_DrawImage1BPP(35, 75 + 25 * 3, BMP_a, WHITE, BLACK);
        LCD_DrawImage1BPP(35 + 11, 75 + 25 * 3, BMP_c, WHITE, BLACK);
        LCD_DrawImage1BPP(35 + 11 + 11, 75 + 25 * 3, BMP_c, WHITE, BLACK);
        LCD_DrawImage1BPP(35 + 11 + 11 + 11, 75 + 25 * 3, BMP_IC_Kaiguan, WHITE, BLACK);
        //IN5  右转向
        LCD_DrawImage1BPP(35, 75 + 25 * 4, BMP_IC_You, WHITE, BLACK);
        LCD_DrawImage1BPP(35 + 21, 75 + 25 * 4, BMP_IC_Zhuanxiang, WHITE, BLACK);
        //IN6  前门开开关
        LCD_DrawImageSBPP(35, 75 + 25 * 5, 21, QMKKG, WHITE, BLACK);
        //IN7  前门关开关
        LCD_DrawImageSBPP(35, 75 + 25 * 6, 21, QMGKG, WHITE, BLACK);
        //IN8  
        //IN9  前雾灯
        LCD_DrawImageSBPP(35, 75 + 25 * 8, 21, QWDKG, WHITE, BLACK);
        //IN10 后雾灯
        LCD_DrawImageSBPP(35, 75 + 25 * 9, 21, HWDKG, WHITE, BLACK);
        //IN11 中门开开关
        LCD_DrawImageSBPP(35, 75 + 25 * 10, 21, ZMKKG, WHITE, BLACK);
        //IN12 中门关开关
        LCD_DrawImageSBPP(35, 75 + 25 * 11, 21, ZMGKG, WHITE, BLACK);
        //IN13 
        //IN14 雨刮低档       
        for (i = 13; i < 16; i++) {
            LCD_DrawImage1BPP(35, 75 + 25 * i, BMP_IC_Yugua, WHITE, BLACK);
        }
        LCD_DrawImage1BPP(35 + 42, 75 + 25 * 13, BMP_Di, WHITE, BLACK);
        LCD_DrawImage1BPP(35 + 63, 75 + 25 * 13, BMP_Dang, WHITE, BLACK);
        //IN15 雨刮间歇档
        LCD_DrawImage1BPP(35 + 42, 75 + 25 * 14, BMP_Jianxie, WHITE, BLACK);
        LCD_DrawImage1BPP(35 + 84, 75 + 25 * 14, BMP_Dang, WHITE, BLACK);
        //IN16 雨刮高档
        LCD_DrawImage1BPP(35 + 42, 75 + 25 * 15, BMP_Gao, WHITE, BLACK);
        LCD_DrawImage1BPP(35 + 63, 75 + 25 * 15, BMP_Dang, WHITE, BLACK);


        //灯开关
        for (i = 0; i < 16; i++) {
            if (i == 0 || i == 4 || i == 8 || i == 9) {
                if (i != 0 && i != 4)
                    LCD_DrawImage1BPP(35 + 42, 75 + 25 * i, BMP_IC_Deng, WHITE, BLACK);
                LCD_DrawImage1BPP(35 + 63, 75 + 25 * i, BMP_IC_Kaiguan, WHITE, BLACK);
            } else if (i == 13 || i == 15)
                LCD_DrawImage1BPP(35 + 84, 75 + 25 * i, BMP_IC_Kaiguan, WHITE, BLACK);
            else if (i == 14)
                LCD_DrawImage1BPP(35 + 105, 75 + 25 * i, BMP_IC_Kaiguan, WHITE, BLACK);
        }

        //IN17
        //IN18 司机风扇开关
        //LCD_DrawImage1BPP(285, 75 + 25 * 1, BMP_IC_Siji, WHITE, BLACK);
        //LCD_DrawImage1BPP(285 + 42, 75 + 25 * 1, BMP_Fengshan, WHITE, BLACK);
        //IN19 路牌开关
        //LCD_DrawImage1BPP(285, 75 + 25 * 2, BMP_Lupai, WHITE, BLACK);
        //IN20      
        //IN21雨刮喷水
        LCD_DrawImage1BPP(285, 75 + 25 * 4, BMP_IC_Yugua, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 42, 75 + 25 * 4, BMP_Penshui, WHITE, BLACK);
        //IN22
        //IN23 灯厢1开关
        LCD_DrawImage1BPP(285, 75 + 25 * 6, BMP_Dengxiang, WHITE, BLACK);
        print_SZ_2(285 + 42 + 6, 75 + 25 * 6, 1, 1, 0, WHITE);
        //IN24 灯厢2开关
        LCD_DrawImage1BPP(285, 75 + 25 * 7, BMP_Dengxiang, WHITE, BLACK);
        print_SZ_2(285 + 42 + 6, 75 + 25 * 7, 2, 1, 0, WHITE);
        //IN25 司机灯开关
        LCD_DrawImage1BPP(285, 75 + 25 * 8, BMP_IC_Siji, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 42, 75 + 25 * 8, BMP_IC_Deng, WHITE, BLACK);
        //IN26  
        //IN27 强制行车开关
        LCD_DrawImage1BPP(285, 75 + 25 * 10, BMP_Qiangzhi, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 42, 75 + 25 * 10, BMP_Xingshi, WHITE, BLACK);
        //IN28 排污阀开关
        LCD_DrawImage1BPP(285, 75 + 25 * 11, BMP_Paiwufa, WHITE, BLACK);
        //IN29
        //IN30  
        //IN31
        //IN32       
        //开关
        for (i = 0; i < 16; i++) {
            if (i == 8 || i == 11) {
                LCD_DrawImage1BPP(285 + 63, 75 + 25 * i, BMP_IC_Kaiguan, WHITE, BLACK);
            } else if (i == 4 || i == 10)
                LCD_DrawImage1BPP(285 + 84, 75 + 25 * i, BMP_IC_Kaiguan, WHITE, BLACK);
            else if (i == 6 || i == 7)
                LCD_DrawImage1BPP(285 + 42 + 11 + 6, 75 + 25 * i, BMP_IC_Kaiguan, WHITE, BLACK);
        }

        //IN33  小灯
        LCD_DrawImageSBPP(535, 75 + 25 * 0, 21, XDKG, WHITE, BLACK);
        //IN34  远光灯
        LCD_DrawImageSBPP(535, 75 + 25 * 1, 21, YGDKG, WHITE, BLACK);
        //IN35  近光灯
        LCD_DrawImageSBPP(535, 75 + 25 * 2, 21, JGDKG, WHITE, BLACK);
        //IN36 ASR故障
        LCD_DrawImageSBPP(535, 75 + 25 * 3, 11, ASR, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 11 + 11 + 11, 75 + 25 * 3, BMP_Guzhang, WHITE, BLACK);
        //IN37 ABS故障
        LCD_DrawImageSBPP(535, 75 + 25 * 4, 11, ABS, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 11 + 11 + 11, 75 + 25 * 4, BMP_Guzhang, WHITE, BLACK);
        //IN38 危险报警开关
        LCD_DrawImageSBPP(535, 75 + 25 * 5, 42, WXBJKG, WHITE, BLACK);
        //IN39 
        //IN40 钥匙ON开关
        LCD_DrawImage1BPP(535, 75 + 25 * 7, BMP_o, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 11, 75 + 25 * 7, BMP_n, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 11 + 11, 75 + 25 * 7, BMP_Dang, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 11 + 11 + 21, 75 + 25 * 7, BMP_Huanxing, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 11 + 11 + 63, 75 + 25 * 7, BMP_IC_Kaiguan, WHITE, BLACK);

        LCD_DrawImage1BPP(535, 75 + 25 * 10, BMP_IC_Qian, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 21, 75 + 25 * 10, BMP_Qiya, WHITE, BLACK);

        LCD_DrawImage1BPP(535, 75 + 25 * 11, BMP_IC_Hou, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 21, 75 + 25 * 11, BMP_Qiya, WHITE, BLACK);

        for (i = 8; i < 14; i++) {
            if (i < 10 || i > 11)
                LCD_DrawImage1BPP(535 + 21, 75 + 25 * i, BMP_Beiyong, WHITE, BLACK);
            LCD_DrawImage1BPP(535 + 63, 75 + 25 * i, BMP_Xinhao, WHITE, BLACK);
            LCD_DrawImage1BPP(535 + 63 + 42 + 16 * 4 - 4, 75 + 25 * i, BMP_Omu, WHITE, BLACK); //Ω
            LCD_DrawImage1BPP(535 + 63 + 42 + 16 * 4 + 16 * 5, 75 + 25 * i, BMP_v, WHITE, BLACK); //V
        }

    } else if (index == 2) {       
        LCD_DrawImage1BPP(130 + 200, 130 - 85, BMP_QIAN, WHITE, BLACK); //前
        LCD_DrawImage1BPP(130 + 200 + 25, 130 - 85, BMP_MOKUAI, WHITE, BLACK); //模块
        LCD_DrawImage1BPP(130 + 200 + 25 + 50, 130 - 85, BMP_Message, WHITE, BLACK); //信息
        for (i = 0; i < 15; i++) {
            LCD_DrawImage1BPP(60 + 280, 75 + 25 * i, BMP_a, WHITE, BLACK);
            //LCD_DrawRect(0, 74 +25+ 25 * i, 800, 1, GRAY); //横线
        }
        /*************************前模块输出***********************************/
        for (i = 0; i < 3; i++) {
            LCD_DrawImage1BPP(60, 75 + 25 * i, BMP_IC_Yugua, WHITE, BLACK);
        }
        //OUT1  高档
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 0, BMP_Gao, WHITE, BLACK);
        //OUT2  低档
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 1, BMP_Di, WHITE, BLACK);
        //OUT3  喷水
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 2, BMP_Penshui, WHITE, BLACK);
        for (i = 0; i < 3; i++) {
            if (i != 2) LCD_DrawImage1BPP(60 + 63, 75 + 25 * i, BMP_Dang, WHITE, BLACK);
            LCD_DrawImage1BPP(60 + 84, 75 + 25 * i, BMP_DJ, WHITE, BLACK);
        }
        //OUT4  左前雾灯
        //LCD_DrawImageSBPP(60, 75 + 25 * 3, 21, ZQWDSC, WHITE, BLACK);
        //OUT5  排污阀
        LCD_DrawImage1BPP(60, 75 + 25 * 4, BMP_Paiwufa, WHITE, BLACK);
        //OUT6  右转向灯
        LCD_DrawImage1BPP(60, 75 + 25 * 5, BMP_IC_You, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 5, BMP_IC_Zhuanxiang, WHITE, BLACK);
        //OUT7  左转向灯
        LCD_DrawImage1BPP(60, 75 + 25 * 6, BMP_IC_Zuo, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 6, BMP_IC_Zhuanxiang, WHITE, BLACK);
        //OUT8  冷凝器
        LCD_DrawImage1BPP(60, 75 + 25 * 7, BMP_Lengningqi, WHITE, BLACK);
        //OUT9  左远光灯
        LCD_DrawImage1BPP(60, 75 + 25 * 8, BMP_IC_Zuo, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 8, BMP_IC_Yuan, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 8, BMP_IC_Guang, WHITE, BLACK);
        //OUT10 残疾人电源
        LCD_DrawImageSBPP(60, 75 + 25 * 9, 63, CJRDY, WHITE, BLACK);
        //OUT11 右远光灯
        LCD_DrawImageSBPP(60, 75 + 25 * 10, 21, YYGDSC, WHITE, BLACK);
        //OUT12 日行灯
        LCD_DrawImageSBPP(60, 75 + 25 * 11, 42, RXD, WHITE, BLACK);
        //OUT13 左近光灯
        LCD_DrawImageSBPP(60, 75 + 25 * 12, 21, ZJGDSC, WHITE, BLACK);
        //OUT14 位置灯
        LCD_DrawImage1BPP(60, 75 + 25 * 13, BMP_Weizhi, WHITE, BLACK);
        //OUT15 右近光灯
        LCD_DrawImageSBPP(60, 75 + 25 * 14, 21, YJGDSC, WHITE, BLACK);
        //ADD雨刮复位信号
        LCD_DrawImage1BPP(60, 75 + 25 * 15, BMP_a, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 11, 75 + 25 * 15, BMP_d, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 11 + 11, 75 + 25 * 15, BMP_d, WHITE, BLACK);

        for (i = 0; i < 16; i++) {
            if (i == 5 || i == 6 || i == 8 || i == 10 || i == 12 || i == 14)
                LCD_DrawImage1BPP(60 + 63, 75 + 25 * i, BMP_IC_Deng, WHITE, BLACK);
            else if (i == 13)
                LCD_DrawImage1BPP(60 + 42, 75 + 25 * i, BMP_IC_Deng, WHITE, BLACK);
        }
        /***********************前模块开关采集*********************************/
        //KL1  左后摩擦片报警
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 0, BMP_IC_Zuo, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 21, 75 + 25 * 0, BMP_IC_Hou, WHITE, BLACK);
        //KL2  
        //KL3  右后摩擦片报警
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 2, BMP_IC_You, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 21, 75 + 25 * 2, BMP_IC_Hou, WHITE, BLACK);
        //KL4  左前摩擦片报警
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 3, BMP_IC_Zuo, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 21, 75 + 25 * 3, BMP_IC_Qian, WHITE, BLACK);
        //KL5  右前摩擦片报警
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 4, BMP_IC_You, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 21, 75 + 25 * 4, BMP_IC_Qian, WHITE, BLACK);
        for (i = 0; i < 5; i++) {
            if (i != 1) {
                LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * i, BMP_Mocapian, WHITE, BLACK);
                LCD_DrawImage1BPP(285 + 150 + 105, 75 + 25 * i, BMP_IC_Kaiguan, WHITE, BLACK);
            }
        }
        //KL6  
        //KL7  安全带开关
        LCD_DrawImageSBPP(285 + 150, 75 + 25 * 6, 42, AQD, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 63, 75 + 25 * 6, BMP_IC_Kaiguan, WHITE, BLACK);
        //KL8  日行灯开关       
        LCD_DrawImageSBPP(285 + 150, 75 + 25 * 7, 42, RXD, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 63, 75 + 25 * 7, BMP_IC_Kaiguan, WHITE, BLACK);
        //KL9 
        //KL10 残疾人上车呼叫
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 9, BMP_Canjiren, WHITE, BLACK);
        LCD_DrawImageSBPP(285 + 150 + 63, 75 + 25 * 9, 21, SCHJ, WHITE, BLACK);
        //KL11 
        //KL12 残疾人踏板信号
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 11, BMP_Canjiren, WHITE, BLACK);
        LCD_DrawImageSBPP(285 + 150 + 63, 75 + 25 * 11, 42, TBXH, WHITE, BLACK);
        //KL13 地址选择1
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 12, BMP_Dizhi, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 12, BMP_Xuanze, WHITE, BLACK);
        print_SZ_2(285 + 150 + 84 + 6, 75 + 25 * 12, 1, 1, 0, WHITE);
        //KL14 地址选择2
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 13, BMP_Dizhi, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 13, BMP_Xuanze, WHITE, BLACK);
        print_SZ_2(285 + 150 + 84 + 6, 75 + 25 * 13, 2, 1, 0, WHITE);
        //KL15 门铃开关
        /*LCD_DrawImage1BPP(285 + 150, 75 + 25 * 14, BMP_Men, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 21, 75 + 25 * 14, BMP_Ling, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 14, BMP_IC_Kaiguan, WHITE, BLACK);*/
        //KH1  后舱门开关
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 15, BMP_IC_Hou, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 21, 75 + 25 * 15, BMP_Cangmen, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 63, 75 + 25 * 15, BMP_IC_Kaiguan, WHITE, BLACK);
    } else if (index == 3) {
        LCD_DrawImage1BPP(130 + 200, 130 - 85, BMP_DING, WHITE, BLACK); //顶
        LCD_DrawImage1BPP(130 + 200 + 25, 130 - 85, BMP_MOKUAI, WHITE, BLACK); //模块
        LCD_DrawImage1BPP(130 + 200 + 25 + 50, 130 - 85, BMP_Message, WHITE, BLACK); //信息
        for (i = 0; i < 15; i++) {
            LCD_DrawImage1BPP(60 + 280, 75 + 25 * i, BMP_a, WHITE, BLACK);
            //LCD_DrawRect(0, 74 +25+ 25 * i, 800, 1, GRAY); //横线
        }

        /*********************顶模块输出***************************************/
        //OUT1  位置灯
        LCD_DrawImageSBPP(60, 75 + 25 * 0, 42, WZD, WHITE, BLACK);
        //OUT2  厢灯2
        LCD_DrawImage1BPP(60, 75 + 25 * 1, BMP_Dengxiang, WHITE, BLACK);
        print_SZ_2(60 + 42 + 6, 75 + 25 * 1, 2, 1, 0, WHITE);
        //OUT3  前门开输出
        LCD_DrawImageSBPP(60, 75 + 25 * 2, 21, QMKSC, WHITE, BLACK);
        //OUT4  前门关输出
        LCD_DrawImageSBPP(60, 75 + 25 * 3, 21, QMGSC, WHITE, BLACK);
        //OUT5  中门开输出
        LCD_DrawImageSBPP(60, 75 + 25 * 4, 21, ZMKSC, WHITE, BLACK);
        //OUT6  中门关输出
        LCD_DrawImageSBPP(60, 75 + 25 * 5, 21, ZMGSC, WHITE, BLACK);
        //OUT7  左转向灯
        LCD_DrawImage1BPP(60, 75 + 25 * 6, BMP_IC_Zuo, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 6, BMP_IC_Zhuanxiang, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 63, 75 + 25 * 6, BMP_IC_Deng, WHITE, BLACK);
        //OUT8  后雾灯
        LCD_DrawImageSBPP(60, 75 + 25 * 7, 21, HWDSC, WHITE, BLACK);
        //OUT9  右转向灯
        LCD_DrawImage1BPP(60, 75 + 25 * 8, BMP_IC_You, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 8, BMP_IC_Zhuanxiang, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 63, 75 + 25 * 8, BMP_IC_Deng, WHITE, BLACK);
        //OUT10 司机风扇
        //LCD_DrawImage1BPP(60, 75 + 25 * 9, BMP_IC_Siji, WHITE, BLACK);
        //LCD_DrawImage1BPP(60 + 42, 75 + 25 * 9, BMP_Fengshan, WHITE, BLACK);
        //OUT11 制动灯
        LCD_DrawImageSBPP(60, 75 + 25 * 10, 42, ZDD, WHITE, BLACK);
        //OUT12 司机灯电源
        LCD_DrawImage1BPP(60, 75 + 25 * 11, BMP_IC_Siji, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 11, BMP_IC_Deng, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 63, 75 + 25 * 11, BMP_Dianyuan, WHITE, BLACK);
        //OUT13 倒车灯
        LCD_DrawImage1BPP(60, 75 + 25 * 12, BMP_Daoche, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 12, BMP_IC_Deng, WHITE, BLACK);
        //OUT14 A信号输出       
        LCD_DrawImage1BPP(60, 75 + 25 * 13, BMP_a, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 11, 75 + 25 * 13, BMP_Xinhao, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 11 + 42, 75 + 25 * 13, BMP_Output, WHITE, BLACK);
        //OUT15 厢灯1
        LCD_DrawImage1BPP(60, 75 + 25 * 14, BMP_Dengxiang, WHITE, BLACK);
        print_SZ_2(60 + 42 + 6, 75 + 25 * 14, 1, 1, 0, WHITE);

        /************************顶模块开关*********************************/
        //KL1  ECAS提升
        LCD_DrawImageSBPP(285 + 150, 75 + 25 * 0, 11, ECASTS, WHITE, BLACK);
        //KL2  门铃开关
        LCD_DrawImageSBPP(285 + 150, 75 + 25 * 1, 21, MLKG, WHITE, BLACK);
        //KL3  ECAS下降
        LCD_DrawImageSBPP(285 + 150, 75 + 25 * 2, 11, ECASXJ, WHITE, BLACK);
        //KL4  应急阀报警
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 3, BMP_Yingjifa, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 63, 75 + 25 * 3, BMP_Baojing, WHITE, BLACK);
        //KL5  ECAS复位
        LCD_DrawImageSBPP(285 + 150, 75 + 25 * 4, 11, ECASFW, WHITE, BLACK);
        //KL6  水位报警
        LCD_DrawImageSBPP(285 + 150, 75 + 25 * 5, 42, SWBJ, WHITE, BLACK);
        //KL7  ECAS侧跪
        LCD_DrawImageSBPP(285 + 150, 75 + 25 * 6, 11, ECASCG, WHITE, BLACK);
        //KL8  残疾人下车呼叫开关
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 7, BMP_Canjiren, WHITE, BLACK);
        LCD_DrawImageSBPP(285 + 150 + 63, 75 + 25 * 7, 21, XCHJ, WHITE, BLACK);
        //KL9
        //KL10
        //KL11
        //KL12
        //KL13 地址选择1
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 12, BMP_Dizhi, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 12, BMP_Xuanze, WHITE, BLACK);
        print_SZ_2(285 + 150 + 84 + 6, 75 + 25 * 12, 1, 1, 0, WHITE);
        //KL14 地址选择2
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 13, BMP_Dizhi, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 13, BMP_Xuanze, WHITE, BLACK);
        print_SZ_2(285 + 150 + 84 + 6, 75 + 25 * 13, 2, 1, 0, WHITE);
        //KL15 中门开状态
        LCD_DrawImageSBPP(285 + 150, 75 + 25 * 14, 21, ZMKZT, WHITE, BLACK);
        //KH1  前门开状态
        LCD_DrawImageSBPP(285 + 150, 75 + 25 * 15, 21, QMKZT, WHITE, BLACK);       

    } else if (index == 4) {
        LCD_DrawImage1BPP(130 + 200, 130 - 85, BMP_HOU, WHITE, BLACK); //后
        LCD_DrawImage1BPP(130 + 200 + 25, 130 - 85, BMP_MOKUAI, WHITE, BLACK); //模块
        LCD_DrawImage1BPP(130 + 200 + 25 + 50, 130 - 85, BMP_Message, WHITE, BLACK); //信息
        for (i = 0; i < 15; i++) {
            LCD_DrawImage1BPP(60 + 280, 75 + 3 + 25 * i, BMP_a, WHITE, BLACK);
            //LCD_DrawRect(0, 74 +25+ 25 * i, 800, 1, GRAY); //横线
        }
        /*********************后模块输出***************************************/
        //OUT1  雨刮电机电源
        LCD_DrawImageSBPP(60, 75 + 25 * 0, 42, YGDJDY, WHITE, BLACK);
        //OUT2  投币机电源
        LCD_DrawImageSBPP(60, 75 + 25 * 1, 63, TBJDY, WHITE, BLACK);
        //OUT3  倒车输出
        LCD_DrawImage1BPP(60, 75 + 25 * 2, BMP_Daoche, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 2, BMP_Output, WHITE, BLACK);
        //OUT4  左前雾灯
        LCD_DrawImageSBPP(60, 75 + 25 * 3, 21, ZQWDSC, WHITE, BLACK);
        //OUT5  集中润滑电源
        LCD_DrawImageSBPP(60, 75 + 25 * 4, 84, JZRHDY, WHITE, BLACK);
        //OUT6  右转向灯
        LCD_DrawImage1BPP(60, 75 + 25 * 5, BMP_IC_You, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 5, BMP_IC_Zhuanxiang, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 63, 75 + 25 * 5, BMP_IC_Deng, WHITE, BLACK);
        //OUT7  左转向灯
        LCD_DrawImage1BPP(60, 75 + 25 * 6, BMP_IC_Zuo, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 6, BMP_IC_Zhuanxiang, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 63, 75 + 25 * 6, BMP_IC_Deng, WHITE, BLACK);
        //OUT8  右前雾灯
        LCD_DrawImageSBPP(60, 75 + 25 * 7, 21, YQWDSC, WHITE, BLACK);
        //OUT9  制动输出
        LCD_DrawImage1BPP(60, 75 + 25 * 8, BMP_Zhidong, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 8, BMP_Output, WHITE, BLACK);
        //OUT10 前门踏步灯
        LCD_DrawImageSBPP(60, 75 + 25 * 9, 21, QMTB, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 84, 75 + 25 * 9, BMP_IC_Deng, WHITE, BLACK);
        //OUT11 滚动屏电源
        //LCD_DrawImage1BPP(60, 75 + 25 * 10, BMP_Gundongping, WHITE, BLACK);
        //LCD_DrawImage1BPP(60 + 63, 75 + 25 * 10, BMP_Dianyuan, WHITE, BLACK);
        //OUT12 中门踏步灯
        LCD_DrawImageSBPP(60, 75 + 25 * 11, 21, ZMTB, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 84, 75 + 25 * 11, BMP_IC_Deng, WHITE, BLACK);
        //OUT13 倒车灯
        //LCD_DrawImage1BPP(60, 75 + 25 * 12, BMP_Daoche, WHITE, BLACK);
        //LCD_DrawImage1BPP(60 + 42, 75 + 25 * 12, BMP_IC_Deng, WHITE, BLACK);
        //OUT14 位置灯       
        LCD_DrawImageSBPP(60, 75 + 25 * 13, 42, WZD, WHITE, BLACK);
        //OUT15 主继电器
        LCD_DrawImageSBPP(60, 75 + 25 * 14, 21, ZJDQ, WHITE, BLACK);

        /************************后模块开关*********************************/
        //KL1  前门开状态
        //LCD_DrawImageSBPP(285 + 150, 75 + 25 * 0, 21, QMKZT, WHITE, BLACK);
        //KL2  驻车制动开关
        LCD_DrawImageSBPP(285 + 150, 75 + 25 * 1, 42, ZCZDKG, WHITE, BLACK);
        //KL3
        //KL4  
        //KL5
        //KL6  制动灯开关
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 5, BMP_Zhidong, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 5, BMP_IC_Deng, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 63, 75 + 25 * 5, BMP_IC_Kaiguan, WHITE, BLACK);
        //KL7  重力感应开关
        LCD_DrawImageSBPP(285 + 150, 75 + 25 * 6, 84, ZLGYKG, WHITE, BLACK);
        //KL8
        //KL9
        //KL10
        //KL11
        //KL12
        //KL13 地址选择1
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 12, BMP_Dizhi, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 12, BMP_Xuanze, WHITE, BLACK);
        print_SZ_2(285 + 150 + 84 + 6, 75 + 25 * 12, 1, 1, 0, WHITE);
        //KL14 地址选择2
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 13, BMP_Dizhi, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 13, BMP_Xuanze, WHITE, BLACK);
        print_SZ_2(285 + 150 + 84 + 6, 75 + 25 * 13, 2, 1, 0, WHITE);
        //KL15 
        //KH1  START档
        LCD_DrawImageSBPP(285 + 150, 75 + 25 * 15, 11, START, WHITE, BLACK);
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

        //print_SZ_2(535 + 63 + 42 + 16 * 5 , 75 + 25 * 8, ADV[1], 4, 0, YELLOW);
        //print_SZ_2(535 + 63 + 42 + 16 * 5 , 75 + 25 * 9, ADV[2], 4, 0, YELLOW);

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
            if (fpcur[i] / 100 > 3)//小于300mA不显示电流
                print_SZ(30 + 250, 75 + 3 + 25 * i, fpcur[i] / 100, 3, 1, YELLOW); //前模块电流
            else
                print_SZ(30 + 250, 75 + 3 + 25 * i, 0, 3, 1, YELLOW);
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
            if (mpcur[i] / 100 > 3)
                print_SZ(30 + 250, 75 + 3 + 25 * i, mpcur[i] / 100, 3, 1, YELLOW); //顶模块电流
            else
                print_SZ(30 + 250, 75 + 3 + 25 * i, 0, 3, 1, YELLOW);
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
            if (rpcur[i] / 100 > 3)
                print_SZ(30 + 250, 75 + 3 + 25 * i, rpcur[i] / 100, 3, 1, YELLOW); //后模块电流
            else
                print_SZ(30 + 250, 75 + 3 + 25 * i, 0, 3, 1, YELLOW);
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
//菜单选择界面
/*******************************************************/
//只更新一次的数据

void MenuFrame(void) {
    LCD_Clear();
    unsigned char color = WHITE;
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //顶部横线   

    LCD_DrawRect(0, 430 + 15, 800, 2, YELLOW); //底部横线

    LCD_DrawImageSBPP(130, 130, 50, MOTO_STSTEM, color, BLACK); //电机系统信息

    LCD_DrawImageSBPP(130, 130 + 35, 50, AIR_STSTEM, color, BLACK); //气泵系统信息

    LCD_DrawImage1BPP(130, 130 + 35 + 35, BMP_DCDC, color, BLACK); //DCDC
    LCD_DrawImage1BPP(130 + 65, 130 + 35 + 35, BMP_STSTEM, color, BLACK); //系统
    LCD_DrawImage1BPP(130 + 65 + 50, 130 + 35 + 35, BMP_Message, color, BLACK); //信息

    LCD_DrawImageSBPP(130, 130 + 35 + 35 + 35, 50, OIL_STSTEM, color, BLACK); //油泵系统信息

    LCD_DrawImageSBPP(130 + 350, 130, 50, BMS_STSTEM, color, BLACK); //电池管理系统信息

    LCD_DrawImageSBPP(130 + 350, 130 + 35, 50, Battery_STSTEM, color, BLACK); //电池系统信息

    LCD_DrawImageSBPP(130 + 350, 130 + 35 + 35, 50, IC_STSTEM, color, BLACK); //仪表系统信息
    
    LCD_DrawImageSBPP(130 + 350, 130 + 35 + 35 + 35, 50, Air_STSTEM, color, BLACK); //空调系统信息


    /*LCD_DrawImage1BPP(130 + 350, 130 + 35 + 35, BMP_Air, color, BLACK); //空调
    LCD_DrawImage1BPP(130 + 350 + 50, 130 + 35 + 35, BMP_STSTEM, color, BLACK); //系统
    LCD_DrawImage1BPP(130 + 350 + 50 + 50, 130 + 35 + 35, BMP_Message, color, BLACK); //信息   
     */
}
//一直更新的数据
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

    if (key_duble) {
        key_duble = 0;
        if (time_flag == 0) {
            f_index = 0;
            frmID = 8;
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
            if (time_flag == 0) {
                f_index = 0;
                frmID = 2;
            }
            time_flag = 0;
        }
    } else
        color = BLACK;
    LCD_DrawImage1BPP(105, 131, BMP_Choose, color, BLACK);
    if (i == 9 || i == 1) {
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
    if (i == 10 || i == 2) {
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
    if (i == 11 || i == 3) {
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
                frmID = 9;
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
                frmID = 10;
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
        disp_time(360, 440 + 8, timer);
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
//电机诊断界面
/*******************************************************/
//只更新一次的数据
void MOTOFrame(unsigned char index) {
    unsigned char i = 0;
    LCD_Clear();
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //顶部横线
    LCD_DrawImageSBPP(130 + 200, 130 - 85, 50, MOTO_STSTEM, WHITE, BLACK); //电机

    LCD_DrawRect(80, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320 + 320, 90, 1, 380, GREEN);
    for (i = 0; i < 11; i++)
        LCD_DrawRect(80, 90 + i * 38, 640, 1, GREEN);

    if (index == 1) {
        LCD_DrawImage1BPP(82, 100, BMP_KZQ, WHITE, BLACK); //控制器
        LCD_DrawImageSBPP(82 + 63, 100, 42, MXDY, WHITE, BLACK); //母线电压
        LCD_DrawImage1BPP(400 - 24, 100, BMP_v, WHITE, BLACK); //v

        LCD_DrawImage1BPP(82, 100 + 38, BMP_KZQ, WHITE, BLACK); //控制器
        LCD_DrawImageSBPP(82 + 63, 100 + 38, 42, MXDL, WHITE, BLACK); //母线电流
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

        LCD_DrawImageSBPP(82, 100 + 38 * 6, 21, CFDZT, WHITE, BLACK); //充放电状态

        /*
        LCD_DrawImage1BPP(82, 100 + 38 * 7, BMP_Guobiao, WHITE, BLACK); //国标档位
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 7, BMP_Dangwei, WHITE, BLACK); //

        LCD_DrawImage1BPP(82, 100 + 38 * 8, BMP_Guobiao, WHITE, BLACK); //国标油门
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 8, BMP_Youmen, WHITE, BLACK);
        LCD_DrawImage1BPP(400 - 24, 100 + 38 * 8, BMP_Baifenhao, WHITE, BLACK); //%

        LCD_DrawImage1BPP(82, 100 + 38 * 9, BMP_Guobiao, WHITE, BLACK); //国标制动
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 9, BMP_Zhidong, WHITE, BLACK);
        LCD_DrawImage1BPP(400 - 24, 100 + 38 * 9, BMP_Baifenhao, WHITE, BLACK); //%
         */

        LCD_DrawImageSBPP(82 + 320, 100, 42, DJDQZS, WHITE, BLACK); //电机当前转速
        LCD_DrawImage1BPP(720 - 24 - 24, 100, BMP_RPM, WHITE, BLACK); //RPM

        LCD_DrawImageSBPP(82 + 320, 100 + 38, 42, DJDQZJ, WHITE, BLACK); //电机当前转速
        LCD_DrawImage1BPP(720 - 24 - 11, 100 + 38, BMP_n, WHITE, BLACK); //NM
        LCD_DrawImage1BPP(720 - 24, 100 + 38, BMP_m, WHITE, BLACK); //

        LCD_DrawImageSBPP(82 + 320, 100 + 38 * 2, 42, DJWD, WHITE, BLACK); //电机温度
        LCD_DrawImage1BPP(720 - 28, 100 + 38 * 2, BMP_T, WHITE, BLACK); //℃

        LCD_DrawImageSBPP(82 + 320, 100 + 38 * 3, 63, KZQWD, WHITE, BLACK); //控制器温度
        LCD_DrawImage1BPP(720 - 28, 100 + 38 * 3, BMP_T, WHITE, BLACK); //℃

        LCD_DrawImageSBPP(82 + 320, 100 + 38 * 4, 42, YMTBKD, WHITE, BLACK); //油门踏板开度
        LCD_DrawImage1BPP(720 - 24, 100 + 38 * 4, BMP_Baifenhao, WHITE, BLACK); //%

        LCD_DrawImageSBPP(82 + 320, 100 + 38 * 5, 42, ZDTBKD, WHITE, BLACK); //制动踏板开度
        LCD_DrawImage1BPP(720 - 24, 100 + 38 * 5, BMP_Baifenhao, WHITE, BLACK); //%

        LCD_DrawImage1BPP(82 + 320, 100 + 38 * 6, BMP_KZQ, WHITE, BLACK); //控制器
        LCD_DrawImageSBPP(82 + 320 + 63, 100 + 38 * 6, 42, GZDM, WHITE, BLACK); //故障代码

        LCD_DrawImage1BPP(82 + 320, 100 + 38 * 7, BMP_KZQ, WHITE, BLACK); //控制器
        LCD_DrawImageSBPP(82 + 320 + 63, 100 + 38 * 7, 42, GZDJ, WHITE, BLACK); //故障等级
    }/*else if(index == 1){
        print_SZ(750, 50, 2, 1, 0, WHITE); // 1/3
        LCD_DrawImage1BPP(750 + 8, 50 - 3, BMP_I, WHITE, BLACK);
        print_SZ(750 + 8 + 14, 50, 3, 1, 0, WHITE);
        BMP_MOTO_CODE1(150, 100 - 8, WHITE);        
    }else if(index == 2){
        print_SZ(750, 50, 3, 1, 0, WHITE); // 1/3
        LCD_DrawImage1BPP(750 + 8, 50 - 3, BMP_I, WHITE, BLACK);
        print_SZ(750 + 8 + 14, 50, 3, 1, 0, WHITE);
        BMP_MOTO_CODE2(150, 100 - 8, WHITE);        
    }*/

}
//一直更新的数据
void MOTOUpdate(unsigned char index) {
    unsigned int temp = 0;
    if (index == 1) {
        print_SZ_1(82 + 200 + 20, 100 - 8, DMC_Voltage * 0.05, 4, 0, WHITE);
        temp = DMC_Current;

        if (temp * 0.05 > 1594 && temp * 0.05 < 1604) temp = 32000;
        updata_DAT(82 + 200 + 20, 100 - 8 + 38, temp, 0.05, 1600, WHITE, 4, 0);
        print_SZ_1(82 + 200 + 20 - 16, 100 - 8 + 38 * 2, DMC_Speed * 0.5 * 1.03, 3, 0, WHITE);

        if (DMC_Status == 0)
            LCD_DrawImage1BPP(82 + 180 + 42, 100 + 38 * 3, BMP_Zhunbeijiuxu, GREEN, BLACK);
        else if (DMC_Status == 1)
            LCD_DrawImage1BPP(82 + 180 + 42, 100 + 38 * 3, BMP_Yunxingzhuangtai, GREEN, BLACK);
        else if (DMC_Status == 2)
            LCD_DrawImage1BPP(82 + 180 + 42, 100 + 38 * 3, BMP_Keshanggaoya, GREEN, BLACK);
        else if (DMC_Status == 3)
            LCD_DrawImage1BPP(82 + 180 + 42, 100 + 38 * 3, BMP_Xitonguzhang, RED, BLACK);
        else if (DMC_Status == 4)
            LCD_DrawImage1BPP(82 + 180 + 42, 100 + 38 * 3, BMP_Xiadianzhuangtai, GREEN, BLACK);

        //print_D(82 + 180, 100 - 8 + 38 * 3, (DMC_Status << 5)+(DMC_Level << 3)); //电机控制器基本状态
        print_H(82 + 200 + 20 + 16, 100 - 8 + 38 * 4, DMC_Life, 3, 0, WHITE); //电机生命
        print_SZ_1(82 + 200 + 20, 100 - 8 + 38 * 5, DMC_Verison, 3, 2, WHITE); //程序版本

        if (DMC_Charge == 1) {
            LCD_DrawImage1BPP(82 + 200 + 22 + 16 * 3, 100 + 38 * 6, BMP_Chongdian, GREEN, BLACK);
        } else if (DMC_Charge == 2)
            LCD_DrawImage1BPP(82 + 200 + 22 + 16 * 3, 100 + 38 * 6, BMP_Fangdian, GREEN, BLACK);
        //print_SZ_1(82 + 200 + 20 + 16 * 3, 100 - 8 + 38 * 6, DMC_Charge, 1, 0, WHITE); //充放电状态

        /*if ((DMC_GB_Gear & 0x0F) == 0) {
            LCD_DrawImage1BPP(82 + 200 + 22 + 16 * 3, 100 + 38 * 7, BMP_n, GREEN, BLACK);
        } else if ((DMC_GB_Gear & 0x0F) == 13) {
            LCD_DrawImage1BPP(82 + 200 + 22 + 16 * 3, 100 + 38 * 7, BMP_r, RED, BLACK);
        } else if ((DMC_GB_Gear & 0x0F) == 14) {
            LCD_DrawImage1BPP(82 + 200 + 22 + 16 * 3, 100 + 38 * 7, BMP_d, GREEN, BLACK);
        } else if ((DMC_GB_Gear & 0x0F) == 15) {
            LCD_DrawImage1BPP(82 + 200 + 22 + 16 * 3, 100 + 38 * 7, BMP_p, GREEN, BLACK);
        } else print_SZ(82 + 200 + 22 + 16 * 3 + 1, 100 + 38 * 7 + 3, DMC_GB_Gear & 0x0F, 1, 0, WHITE);

        if ((DMC_GB_Gear & 0x10) == 0)
            print_SZ_1(82 + 200 + 22 + 16, 100 - 8 + 38 * 8, 0, 3, 0, WHITE);
        else print_SZ_1(82 + 200 + 22 + 16, 100 - 8 + 38 * 8, 100, 3, 0, WHITE);

        if ((DMC_GB_Gear & 0x20) == 0)
            print_SZ_1(82 + 200 + 22 + 16, 100 - 8 + 38 * 9, 0, 3, 0, WHITE);
        else print_SZ_1(82 + 200 + 22 + 16, 100 - 8 + 38 * 9, 100, 3, 0, WHITE);*/

        if (DMC_Rpm * 0.5 > 16000)
            temp = DMC_Rpm * 0.5 - 16000;
        else temp = 16000 - DMC_Rpm * 0.5;
        if (temp <= 5) temp = 0;
        print_SZ_1(82 + 200 + 300, 100 - 8, temp, 5, 0, WHITE);

        updata_DAT(82 + 200 + 300 + 16, 100 - 8 + 38, DMC_Torque, 0.1, 3200, WHITE, 4, 0);
        updata_DAT(82 + 200 + 300 + 16 * 2, 100 - 8 + 38 * 2, DMC_Moto_temp, 1, 40, WHITE, 3, 0);
        updata_DAT(82 + 200 + 300 + 16 * 2, 100 - 8 + 38 * 3, DMC_Controller_temp, 1, 40, WHITE, 3, 0);
        print_SZ_1(82 + 200 + 300 + 16 * 2, 100 - 8 + 38 * 4, DMC_Accelerator_percent, 3, 0, WHITE); //油门开度
        print_SZ_1(82 + 200 + 300 + 16 * 2, 100 - 8 + 38 * 5, DMC_Brake_percent, 3, 0, WHITE); //油门开度

        if (DMC_Protect_code == 0)//故障代码
            print_SZ_1(82 + 200 + 300 + 16 * 2, 100 - 8 + 38 * 6, DMC_Protect_code, 3, 0, GREEN);
        else print_SZ_1(82 + 200 + 300 + 16 * 2, 100 - 8 + 38 * 6, DMC_Protect_code, 3, 0, RED);

        if (DMC_Status == 3)//故障等级
            print_SZ_1(82 + 200 + 300 + 16 * 2, 100 - 8 + 38 * 7, DMC_Level + 1, 3, 0, RED);
        else print_SZ_1(82 + 200 + 300 + 16 * 2, 100 - 8 + 38 * 7, DMC_Level + 1, 3, 0, BLACK);
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
    if (key_up) { //子菜单切换
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
//气泵诊断界面
/*******************************************************/
//只更新一次的数据
void DMQFrame(void) {
    unsigned char i = 0;
    LCD_Clear();
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //顶部横线
    LCD_DrawImageSBPP(130 + 200 - 15, 130 - 85, 50, AIR_STSTEM, WHITE, BLACK); //气泵

    LCD_DrawRect(80, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320 + 320, 90, 1, 380, GREEN);
    for (i = 0; i < 11; i++)
        LCD_DrawRect(80, 90 + i * 38, 640, 1, GREEN);

    LCD_DrawImageSBPP(82, 100, 42, DJZS, WHITE, BLACK); //电机转速
    LCD_DrawImage1BPP(400 - 24 - 24, 100, BMP_RPM, WHITE, BLACK); //RPM

    LCD_DrawImage1BPP(82, 100 + 38, BMP_KZQ, WHITE, BLACK); //控制器
    LCD_DrawImageSBPP(82 + 63, 100 + 38, 42, MXDY, WHITE, BLACK); //母线
    LCD_DrawImage1BPP(400 - 24, 100 + 38, BMP_v, WHITE, BLACK); //v

    LCD_DrawImage1BPP(82, 100 + 38 * 2, BMP_KZQ, WHITE, BLACK); //控制器
    LCD_DrawImageSBPP(82 + 63, 100 + 38 * 2, 42, MXDL, WHITE, BLACK); //母线
    LCD_DrawImage1BPP(400 - 24, 100 + 38 * 2, BMP_a, WHITE, BLACK); //a

    LCD_DrawImage1BPP(82, 100 + 38 * 3, BMP_Qibeng, WHITE, BLACK); //气泵
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 3, BMP_Wendu, WHITE, BLACK); //温度
    LCD_DrawImage1BPP(400 - 28, 100 + 38 * 3, BMP_T, WHITE, BLACK); //℃



    LCD_DrawImageSBPP(82 + 320, 100, 63, KZQWD, WHITE, BLACK); //控制器温度
    LCD_DrawImage1BPP(720 - 28, 100, BMP_T, WHITE, BLACK); //℃

    LCD_DrawImage1BPP(82 + 320, 100 + 38, BMP_Qibeng, WHITE, BLACK); //气泵
    LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38, BMP_Life, WHITE, BLACK); //Life

    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 2, BMP_KZQ, WHITE, BLACK); //控制器
    LCD_DrawImage1BPP(82 + 320 + 63, 100 + 38 * 2, BMP_Yuchong, WHITE, BLACK); //预充
    LCD_DrawImage1BPP(82 + 320 + 63 + 42, 100 + 38 * 2, BMP_Zhuangtai, WHITE, BLACK); //状态

    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 3, BMP_Qibeng, WHITE, BLACK); //气泵
    LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 3, BMP_Zhuangtai, WHITE, BLACK); //状态

    LCD_DrawImageSBPP(82 + 320, 100 + 2 + 38 * 4, 42, GZDM, WHITE, BLACK); //故障代码

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
//一直更新的数据
void DMQUpdate(void) {
    print_SZ_1(82 + 200 + 20 - 16, 100 - 8, DMQ_Rpm * 0.125, 4, 0, WHITE);
    print_SZ_1(82 + 200 + 20 - 16, 100 - 8 + 38, DMQ_Voltage * 0.1, 4, 0, WHITE);
    print_SZ_1(82 + 200 + 20, 100 - 8 + 38 * 2, DMQ_Current, 3, 0, WHITE);
    updata_DAT(82 + 200 + 20, 100 - 8 + 38 * 3, DMQ_temp, 1, 40, WHITE, 3, 0);

    updata_DAT(82 + 200 + 300, 100 - 8, DMQ_Controller_temp, 1, 40, WHITE, 3, 0);
    print_SZ_1(82 + 200 + 300, 100 - 8 + 38, DMQ_Life, 3, 0, WHITE); //心跳
    print_SZ_1(82 + 200 + 300 + 16 * 2, 100 - 8 + 38 * 2, (DMQ_Status >> 7) & 0x01, 1, 0, WHITE); //控制器预充状态

    if (((DMQ_Status >> 4) & 0x03) == 0)
        LCD_DrawImage1BPP(82 + 200 + 300, 100 + 38 * 3, BMP_Zhunbeijiuxu, GREEN, BLACK);
    else if (((DMQ_Status >> 4) & 0x03) == 1)
        LCD_DrawImage1BPP(82 + 200 + 300, 100 + 38 * 3, BMP_Yunxingzhuangtai, GREEN, BLACK);
    else if (((DMQ_Status >> 4) & 0x03) == 2)
        LCD_DrawImage1BPP(82 + 200 + 300, 100 + 38 * 3, BMP_Xitonguzhang, RED, BLACK);

    print_SZ_1(82 + 200 + 300 + 16, 100 - 8 + 38 * 4, DMQ_Status & 0x0F, 2, 0, WHITE);

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
        f_index = 0;
        frmID = 1;
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
//DCDC诊断界面
/*******************************************************/
//只更新一次的数据

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
    LCD_DrawImageSBPP(82 + 320 + 65, 100 + 2 + 38,42, GZDM, WHITE, BLACK); //故障代码

    LCD_DrawImage1BPP(82 + 320, 100 - 2 + 38 * 2, BMP_DCDC, WHITE, BLACK); //DCDC
    LCD_DrawImage1BPP(82 + 320 + 65, 100 + 2 + 38 * 2, BMP_Banben, WHITE, BLACK); //版本
    LCD_DrawImage1BPP(82 + 320 + 65 + 42, 100 + 2 + 38 * 2, BMP_Hao, WHITE, BLACK); //号
    LCD_DrawImage1BPP(720 - 24 - 90, 100 - 9 + 38 * 2, BMP_V, WHITE, BLACK); //v

}
//一直更新的数据
void DCDCUpdate(void) {
    print_SZ_1(82 + 200 + 20 - 16, 100 - 8, DCDC_Voltage * 0.05, 4, 0, WHITE);
    updata_DAT(82 + 200 + 20 - 16, 100 - 8 + 38, DCDC_Current, 0.05, 1600, WHITE, 4, 0);
    updata_DAT(82 + 200 + 20, 100 - 8 + 38 * 2, DCDC_Temp, 1, 40, WHITE, 3, 0);

    print_D(82 + 180 + 320, 100 - 8, DCDC_Status); //系统代码
    print_SZ_1(82 + 180 + 320, 100 - 8 + 38, DCDC_Code, 3, 0, WHITE); //系统代码
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
        f_index = 0;
        frmID = 1;
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
//油泵诊断界面
/*******************************************************/
//只更新一次的数据

void DMYFrame(void) {
    unsigned char i = 0;
    LCD_Clear();
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //顶部横线
    LCD_DrawImageSBPP(130 + 200, 130 - 85, 50, OIL_STSTEM, WHITE, BLACK); //油泵

    LCD_DrawRect(80, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320 + 320, 90, 1, 380, GREEN);
    for (i = 0; i < 11; i++)
        LCD_DrawRect(80, 90 + i * 38, 640, 1, GREEN);

    LCD_DrawImageSBPP(82, 100, 42, DJZS, WHITE, BLACK); //电机
    LCD_DrawImage1BPP(400 - 24 - 24, 100, BMP_RPM, WHITE, BLACK); //RPM

    LCD_DrawImage1BPP(82, 100 + 38, BMP_KZQ, WHITE, BLACK); //控制器
    LCD_DrawImageSBPP(82 + 63, 100 + 38, 42, MXDY, WHITE, BLACK); //母线电压
    LCD_DrawImage1BPP(400 - 24, 100 + 38, BMP_v, WHITE, BLACK); //v

    LCD_DrawImage1BPP(82, 100 + 38 * 2, BMP_KZQ, WHITE, BLACK); //控制器
    LCD_DrawImageSBPP(82 + 63, 100 + 38 * 2, 42, MXDL, WHITE, BLACK); //母线电流
    LCD_DrawImage1BPP(400 - 24, 100 + 38 * 2, BMP_a, WHITE, BLACK); //a

    LCD_DrawImageSBPP(82 + 320, 100, 63, KZQWD, WHITE, BLACK); //控制器温度
    LCD_DrawImage1BPP(720 - 28, 100, BMP_T, WHITE, BLACK); //℃

    LCD_DrawImage1BPP(82 + 320, 100 + 38, BMP_Youbeng, WHITE, BLACK); //油泵
    LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38, BMP_Life, WHITE, BLACK); //Life

    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 2, BMP_KZQ, WHITE, BLACK); //控制器
    LCD_DrawImage1BPP(82 + 320 + 63, 100 + 38 * 2, BMP_Yuchong, WHITE, BLACK); //预充
    LCD_DrawImage1BPP(82 + 320 + 63 + 42, 100 + 38 * 2, BMP_Zhuangtai, WHITE, BLACK); //状态

    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 3, BMP_Youbeng, WHITE, BLACK); //油泵
    LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 3, BMP_Zhuangtai, WHITE, BLACK); //状态

    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 4, BMP_Kongzhifangshi, WHITE, BLACK); //控制方式

    LCD_DrawImageSBPP(82 + 320, 100 + 2 + 38 * 5, 42, GZDM, WHITE, BLACK); //故障代码
}
//一直更新的数据
void DMYUpdate(void) {
    print_SZ_1(82 + 200 + 20 - 16, 100 - 8, DMY_Rpm * 0.125, 4, 0, WHITE);
    print_SZ_1(82 + 200 + 20 - 16, 100 - 8 + 38, DMY_Voltage * 0.1, 4, 0, WHITE);
    print_SZ_1(82 + 200 + 20, 100 - 8 + 38 * 2, DMY_Current, 3, 0, WHITE);

    updata_DAT(82 + 200 + 300, 100 - 8, DMY_Controller_temp, 1, 40, WHITE, 3, 0);
    print_SZ_1(82 + 200 + 300, 100 - 8 + 38, DMY_Life, 3, 0, WHITE); //心跳   
    print_SZ_1(82 + 180 + 320 + 16 * 2, 100 - 8 + 38 * 2, (DMY_Status >> 7) & 0x01, 1, 0, WHITE); //控制器预充状态

    if (((DMY_Status >> 4) & 0x03) == 0)
        LCD_DrawImage1BPP(82 + 200 + 300, 100 + 38 * 3, BMP_Tingzhi, YELLOW, BLACK);
    else if (((DMY_Status >> 4) & 0x03) == 1)
        LCD_DrawImage1BPP(82 + 200 + 300, 100 + 38 * 3, BMP_Yunxing, GREEN, BLACK);
    else if (((DMY_Status >> 4) & 0x03) == 2)
        LCD_DrawImage1BPP(82 + 200 + 300, 100 + 38 * 3, BMP_Guzhang, RED, BLACK);

    print_SZ_1(82 + 180 + 320 + 16 * 2, 100 - 8 + 38 * 4, (DMY_Status >> 6) & 0x01, 1, 0, WHITE);

    print_SZ_1(82 + 180 + 320 + 16, 100 - 8 + 38 * 5, DMY_Status & 0x0F, 2, 0, WHITE);
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
        f_index = 0;
        frmID = 1;
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
//BMS诊断界面
/*******************************************************/
//只更新一次的数据

void BMSFrame(unsigned char index) {
    unsigned char i = 0, j = 0, color = WHITE;
    LCD_Clear();
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //顶部横线
    LCD_DrawImageSBPP(130 + 200 - 24, 130 - 85, 50, BMS_STSTEM, WHITE, BLACK); //电池

    print_SZ(750, 50, index, 1, 0, WHITE); // 1/N
    LCD_DrawImage1BPP(750 + 8, 50 - 3, BMP_I, WHITE, BLACK);
    print_SZ(750 + 8 + 14, 50, 5, 1, 0, WHITE);

    if (index == 1) {
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

        for (i = 0; i < 3; i++) {
            LCD_DrawImage1BPP(82, 100 + 38 * (i + 2), BMP_DC, WHITE, BLACK); //电池
            LCD_DrawImage1BPP(82 + 42, 100 + 38 * (i + 2), BMP_Zhuangtai, WHITE, BLACK); //状态
            LCD_DrawImage1BPP(82 + 42 + 42, 100 - 8 + 38 * (i + 2), BMP_SZ_1[i + 1], WHITE, BLACK); //1
        }

        /*LCD_DrawImage1BPP(82, 100 + 38 * 3, BMP_DC, WHITE, BLACK); //电池
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 3, BMP_Zhuangtai, WHITE, BLACK); //状态
        LCD_DrawImage1BPP(82 + 42 + 42, 100 - 8 + 38 * 3, BMP_SZ_1[2], WHITE, BLACK); //2

        LCD_DrawImage1BPP(82, 100 + 38 * 4, BMP_DC, WHITE, BLACK); //电池
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 4, BMP_Zhuangtai, WHITE, BLACK); //状态
        LCD_DrawImage1BPP(82 + 42 + 42, 100 - 8 + 38 * 4, BMP_SZ_1[3], WHITE, BLACK); */

        LCD_DrawImage1BPP(82, 100 + 38 * 5, BMP_DC, WHITE, BLACK); //电池
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 5, BMP_Xiang, WHITE, BLACK); //箱
        LCD_DrawImage1BPP(82 + 42 + 21, 100 + 38 * 5, BMP_Geshu, WHITE, BLACK); //个数

        LCD_DrawImage1BPP(82, 100 + 38 * 6, BMP_BMU, WHITE, BLACK); //BMU
        LCD_DrawImage1BPP(82 + 35, 100 + 38 * 6, BMP_Danyuan, WHITE, BLACK); //单元
        LCD_DrawImage1BPP(82 + 35 + 42, 100 + 38 * 6, BMP_Geshu, WHITE, BLACK); //个数

        LCD_DrawImage1BPP(82, 100 + 38 * 7, BMP_Jidianqi, WHITE, BLACK); //继电器
        LCD_DrawImage1BPP(82 + 63, 100 + 38 * 7, BMP_Zhuangtai, WHITE, BLACK); //状态
        LCD_DrawImage1BPP(82 + 63 + 42, 100 - 8 + 38 * 7, BMP_SZ_1[4], WHITE, BLACK); //4

        LCD_DrawImage1BPP(82, 100 + 38 * 8, BMP_Chong, WHITE, BLACK); //充放电状态
        LCD_DrawImage1BPP(82 + 21, 100 + 38 * 8, BMP_Fangdian, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 21 + 21, 100 + 38 * 8, BMP_DC, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 21 + 21 + 21, 100 + 38 * 8, BMP_Zhuangtai, WHITE, BLACK); //

        LCD_DrawImage1BPP(82, 100 + 38 * 9, BMP_Shengyunengliang, WHITE, BLACK); //剩余能量
        LCD_DrawImage1BPP(400 - 24 - 11 - 11, 100 + 38 * 9, BMP_k, WHITE, BLACK); //kwh
        LCD_DrawImage1BPP(400 - 24 - 11, 100 + 38 * 9, BMP_w, WHITE, BLACK);
        LCD_DrawImage1BPP(400 - 24, 100 + 38 * 9, BMP_h, WHITE, BLACK);

        for (i = 0; i < 4; i++) {
            LCD_DrawImage1BPP(82 + 320, 100 + 38 * i, BMP_Zui, WHITE, BLACK); //最
            if (i % 2 == 0)
                LCD_DrawImage1BPP(82 + 320 + 21, 100 + 38 * i, BMP_Gao, WHITE, BLACK); // 高
            else LCD_DrawImage1BPP(82 + 320 + 21, 100 + 38 * i, BMP_Di, WHITE, BLACK); // 低 
            LCD_DrawImage1BPP(82 + 320 + 21 + 21, 100 + 38 * i, BMP_Dan, WHITE, BLACK); //单
            LCD_DrawImage1BPP(82 + 320 + 21 + 21 + 21, 100 + 38 * i, BMP_Ti, WHITE, BLACK); //体
            if (i < 2) {
                LCD_DrawImage1BPP(82 + 320 + 21 + 21 + 21 + 21, 100 + 38 * i, BMP_DY, WHITE, BLACK); //电压
                LCD_DrawImage1BPP(720 - 24 - 63, 100 + 38 * i, BMP_v, WHITE, BLACK); //V
            } else {
                LCD_DrawImage1BPP(82 + 320 + 21 + 21 + 21 + 21, 100 + 38 * i, BMP_Wendu, WHITE, BLACK); //温度
                LCD_DrawImage1BPP(720 - 28 - 63, 100 + 38 * i, BMP_T, WHITE, BLACK); //℃
            }
            LCD_DrawImage1BPP(82 + 320 + 42 * 7, 100 + 38 * i, BMP_Xiang, WHITE, BLACK); //箱

            LCD_DrawImage1BPP(82 + 320 + 42 * 8.5, 100 + 38 * i, BMP_Hao, WHITE, BLACK); //号
        }

        /*LCD_DrawImage1BPP(82 + 320 + 42 * 7, 100, BMP_Xiang, WHITE, BLACK); //箱

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

        LCD_DrawImage1BPP(82 + 320 + 42 * 8.5, 100 + 38 * 3, BMP_Hao, WHITE, BLACK);*/ //号

        for (i = 0; i < 3; i++) {
            LCD_DrawImage1BPP(82 + 320, 100 + 38 * (i + 4), BMP_DC, WHITE, BLACK); //电池
            LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * (i + 4), BMP_System, WHITE, BLACK); //系统
        }
        LCD_DrawImage1BPP(82 + 320 + 42 + 42, 100 + 38 * 4, BMP_Zong, WHITE, BLACK); //总
        LCD_DrawImage1BPP(82 + 320 + 42 + 42 + 21, 100 + 38 * 4, BMP_Chuanshu, WHITE, BLACK); //串数

        LCD_DrawImage1BPP(82 + 320 + 42 + 42, 100 + 38 * 5, BMP_Bianhao, WHITE, BLACK); //编号

        LCD_DrawImage1BPP(82 + 320 + 42 + 42, 100 + 38 * 6, BMP_Life, WHITE, BLACK); //Life

        for (i = 0; i < 2; i++) {
            if (i == 0)
                LCD_DrawImage1BPP(82 + 320, 100 + 38 * (i + 7), BMP_Zheng, WHITE, BLACK); //正
            else LCD_DrawImage1BPP(82 + 320, 100 + 38 * (i + 7), BMP_Fu, WHITE, BLACK); //负
            LCD_DrawImage1BPP(82 + 320 + 21, 100 + 38 * (i + 7), BMP_Jueyuan, WHITE, BLACK); //绝缘
            LCD_DrawImage1BPP(82 + 320 + 42 + 21, 100 + 38 * (i + 7), BMP_DC, WHITE, BLACK); //电池
            LCD_DrawImage1BPP(82 + 320 + 42 + 42, 100 + 38 * (i + 7), BMP_Zu, WHITE, BLACK); //阻
            //LCD_DrawImage1BPP(82 + 320 + 42 + 42 + 21 + 2, 100 + 5 + 38 * (i + 7), BMP_Maohao, WHITE, BLACK); //:
            LCD_DrawImage1BPP(720 - 28 + 60, 100 + 38 * (i + 7), BMP_k, WHITE, BLACK); //K
            LCD_DrawImage1BPP(720 - 16 + 60, 100 + 2 + 38 * (i + 7), BMP_Omu, WHITE, BLACK); //Ω
        }
        LCD_DrawImage1BPP(82 + 320, 100 + 38 * 9, BMP_Dingbu, WHITE, BLACK); //顶部充电状态
        LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 9, BMP_Chong, WHITE, BLACK); 
        LCD_DrawImage1BPP(82 + 320 + 42 + 21, 100 + 38 * 9, BMP_DC, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 320 + 42 + 21 + 21, 100 + 38 * 9, BMP_Zhuangtai, WHITE, BLACK); //
    }
    if (index == 2) {
        LCD_DrawRect(80, 90, 1, 380, GREEN);
        LCD_DrawRect(80 + 320, 90, 1, 380, GREEN);
        LCD_DrawRect(80 + 320 + 320, 90, 1, 380, GREEN);
        for (i = 0; i < 11; i++)
            LCD_DrawRect(80, 90 + i * 38, 640, 1, GREEN);

        for (i = 0; i < 8; i++) {
            LCD_DrawImage1BPP(82, 100 + 38 * i, BMP_Chongdian, WHITE, BLACK); //充电插头温度
            LCD_DrawImage1BPP(82 + 42, 100 + 38 * i, BMP_Chatou, WHITE, BLACK);
            print_SZ_1(82 + 42 + 42, 100 - 8 + 38 * i, i / 2 + 1, 1, 0, WHITE);
            LCD_DrawImage1BPP(82 + 42 + 42 + 16, 100 - 2 + 38 * i, BMP_DCDC, WHITE, BLACK);
            if (i == 0 || i == 2 || i == 4 || i == 6)
                LCD_DrawImage1BPPZOOM_4(82 + 42 + 42 + 16 + 26, 100 + 38 * i, BMP_ZHENG, WHITE, BLACK);
            LCD_DrawImage1BPP(82 + 42 + 42 + 16 + 26 + 12, 100 + 38 * i, BMP_Wendu, WHITE, BLACK);
            LCD_DrawImage1BPP(400 - 24, 100 + 38 * i, BMP_T, WHITE, BLACK); //℃
        }

        for (i = 0; i < 4; i++) {
            LCD_DrawImage1BPP(82 + 320, 100 + 38 * i, BMP_Chongdian, WHITE, BLACK); //充电插头X插拔次数
            LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * i, BMP_Chatou, WHITE, BLACK);
            print_SZ_1(82 + 320 + 42 + 42, 100 - 8 + 38 * i, i + 1, 1, 0, WHITE);
            LCD_DrawImage1BPP(82 + 320 + 42 + 42 + 16, 100 + 38 * i, BMP_Chabacishu, WHITE, BLACK);
        }

        for (i = 0; i < 2; i++) {
            LCD_DrawImage1BPP(82, 100 + 38 * (i + 8), BMP_DC, WHITE, BLACK); //电池
            LCD_DrawImage1BPP(82 + 42, 100 + 38 * (i + 8), BMP_Zhuangtai, WHITE, BLACK); //状态
            LCD_DrawImage1BPP(82 + 42 + 42, 100 - 8 + 38 * (i + 8), BMP_SZ_1[i + 5], WHITE, BLACK); //5  6
        }


        LCD_DrawImage1BPP(82 + 320, 100 + 38 * 9, BMP_Jidianqi, WHITE, BLACK); //继电器
        LCD_DrawImage1BPP(82 + 320 + 63, 100 + 38 * 9, BMP_Zhuangtai, WHITE, BLACK); //状态
        LCD_DrawImage1BPP(82 + 320 + 63 + 42, 100 - 8 + 38 * 9, BMP_SZ_1[5], WHITE, BLACK); //5


    }
    if (index == 3) {
        LCD_DrawRect(80, 90, 1, 380, GREEN);
        LCD_DrawRect(80 + 320, 90, 1, 380, GREEN);
        LCD_DrawRect(80 + 320 + 320, 90, 1, 380, GREEN);
        for (i = 0; i < 11; i++)
            LCD_DrawRect(80, 90 + i * 38, 640, 1, GREEN);

        for (i = 0; i < 8; i++) {
            LCD_DrawImage1BPP(82, 100 + 38 * i, BMP_Zui, WHITE, BLACK); //最
            if (i % 2 == 0)
                LCD_DrawImage1BPP(82 + 21, 100 + 38 * i, BMP_Gao, WHITE, BLACK); // 高
            else LCD_DrawImage1BPP(82 + 21, 100 + 38 * i, BMP_Di, WHITE, BLACK); // 低 
            LCD_DrawImage1BPP(82 + 21 + 21, 100 + 38 * i, BMP_Dan, WHITE, BLACK); //单
            LCD_DrawImage1BPP(82 + 21 + 21 + 21, 100 + 38 * i, BMP_Ti, WHITE, BLACK); //体
            if (i == 0 || i == 1 || i == 4 || i == 5) {
                LCD_DrawImage1BPP(82 + 21 + 21 + 21 + 21, 100 + 38 * i, BMP_DY, WHITE, BLACK); //电压
                //LCD_DrawImage1BPP(720 - 24 - 63, 100 + 38 * i, BMP_v, WHITE, BLACK); //V
            } else {
                LCD_DrawImage1BPP(82 + 21 + 21 + 21 + 21, 100 + 38 * i, BMP_Wendu, WHITE, BLACK); //温度
                //LCD_DrawImage1BPP(720 - 28 - 63, 100 + 38 * i, BMP_T, WHITE, BLACK); //℃
            }
            if (i < 4)LCD_DrawImage1BPP(82 + 21 + 21 + 21 + 21 + 42, 100 + 38 * i, BMP_Weizhi, WHITE, BLACK); //位置
            else LCD_DrawImage1BPP(82 + 21 + 21 + 21 + 21 + 42, 100 + 38 * i, BMP_Bianhao, WHITE, BLACK); //编号
        }
    }
    if (index == 4) {
        for (i = 0; i < 5; i++) {
            LCD_DrawRect(10 + 195 * i, 90, 1, 380, GREEN);
        }
        for (i = 0; i < 11; i++)
            LCD_DrawRect(10, 90 + i * 38, 780, 1, GREEN);

        for (j = 0; j < 4; j++) {
            for (i = 0; i < 10; i++) {
                color = (10 * j + i >= BMS_Unit_Number) ? BLACK : WHITE;
                LCD_DrawImage1BPP(12 + j * 195, 100 + 38 * i, BMP_BMU, color, BLACK); //BMUxx通讯状态
                LCD_DrawImage1BPP(12 + 33 + 32 + j * 195, 100 + 38 * i, BMP_Tongxun, color, BLACK);
                LCD_DrawImage1BPP(12 + 33 + 32 + 42 + j * 195, 100 + 38 * i, BMP_Zhuangtai, color, BLACK);
                if (i < 9) {//写编号个位
                    LCD_DrawImage1BPP(12 + 33 + 16 + j * 195, 100 - 8 + i * 38, BMP_SZ_1[i + 1], color, BLACK);
                    if (j > 0) {//写编号十位
                        LCD_DrawImage1BPP(12 + 33 + j * 195, 100 - 8 + i * 38, BMP_SZ_1[j], color, BLACK);
                    }
                } else {//写最底下一行编号
                    LCD_DrawImage1BPP(12 + 33 + 16 + j * 195, 100 - 8 + i * 38, BMP_SZ_1[0], color, BLACK);
                    LCD_DrawImage1BPP(12 + 33 + j * 195, 100 - 8 + i * 38, BMP_SZ_1[j + 1], color, BLACK);
                }
            }
        }


    }
    if (index == 5) {
        for (i = 0; i < 5; i++) {
            LCD_DrawRect(10 + 195 * i, 90, 1, 380, GREEN);
        }
        for (i = 0; i < 11; i++)
            LCD_DrawRect(10, 90 + i * 38, 780, 1, GREEN);

        for (j = 0; j < 4; j++) {
            for (i = 0; i < 10; i++) {
                color = (10 * j + i >= BMS_Unit_Number) ? BLACK : WHITE;
                LCD_DrawImage1BPP(12 + j * 195, 100 + 38 * i, BMP_BMU, color, BLACK); //BMUxx均衡状态
                LCD_DrawImage1BPP(12 + 33 + 32 + j * 195, 100 + 38 * i, BMP_Junheng, color, BLACK);
                LCD_DrawImage1BPP(12 + 33 + 32 + 42 + j * 195, 100 + 38 * i, BMP_Zhuangtai, color, BLACK);
                if (i < 9) {//写编号个位
                    LCD_DrawImage1BPP(12 + 33 + 16 + j * 195, 100 - 8 + i * 38, BMP_SZ_1[i + 1], color, BLACK);
                    if (j > 0) {//写编号十位
                        LCD_DrawImage1BPP(12 + 33 + j * 195, 100 - 8 + i * 38, BMP_SZ_1[j], color, BLACK);
                    }
                } else {//写最底下一行编号
                    LCD_DrawImage1BPP(12 + 33 + 16 + j * 195, 100 - 8 + i * 38, BMP_SZ_1[0], color, BLACK);
                    LCD_DrawImage1BPP(12 + 33 + j * 195, 100 - 8 + i * 38, BMP_SZ_1[j + 1], color, BLACK);
                }
            }
        }

    }

}
//一直更新的数据
void BMSUpdate(unsigned char index) {
    unsigned char i = 0, color = WHITE;
    if (index == 1) {
        updata_DCDY(82 + 200 + 30, 100 - 8);
        updata_DCDL(82 + 200 + 30, 100 - 8 + 38);
        print_D(82 + 180, 100 - 8 + 38 * 2, BMS_Status_Flag1);
        print_D(82 + 180, 100 - 8 + 38 * 3, BMS_Status_Flag2);
        print_D(82 + 180, 100 - 8 + 38 * 4, BMS_Status_Flag3);
        print_SZ_1(82 + 200 + 30 + 16 * 3, 100 - 8 + 38 * 5, Battery_Case_Total_Number, 2, 0, WHITE);
        print_SZ_1(82 + 200 + 30 + 16 * 3, 100 - 8 + 38 * 6, BMS_Unit_Number, 2, 0, WHITE);
        print_D(82 + 180, 100 - 8 + 38 * 7, BMS_Status_Flag4);
        if (BMS_Status_Flag5 & 0x01) {
            LCD_DrawImage1BPP(82 + 200 + 22 + 16 * 3, 100 + 38 * 8, BMP_Chongdian, GREEN, BLACK);
        } else if (!(BMS_Status_Flag5 & 0x01))
            LCD_DrawImage1BPP(82 + 200 + 22 + 16 * 3, 100 + 38 * 8, BMP_Fangdian, GREEN, BLACK);
        print_SZ_1(82 + 200 + 4, 100 - 8 + 38 * 9, Energe_Rest * 0.1, 3, 0, WHITE);

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
        print_SZ_1(82 + 200 + 260 + 16 * 8, 100 - 8 + 38 * 7, Ohm_Positive, 5, 0, WHITE);
        print_SZ_1(82 + 200 + 260 + 16 * 8, 100 - 8 + 38 * 8, Ohm_Negative, 5, 0, WHITE);
        if ((BMS_Status_Flag5 >> 1) & 0x01) {
            LCD_DrawImage1BPP(82 + 200 + 320 + 22 + 16 * 3, 100 + 38 * 9, BMP_Yunxing, GREEN, BLACK);
        } else if (!((BMS_Status_Flag5 >> 1) & 0x01)){
            LCD_DrawImage1BPP(82 + 200 + 320 + 22 + 16 * 3, 100 + 38 * 9, BMP_Tingzhi, RED, BLACK);
        }
    }
    if (index == 2) {
        updata_DAT(82 + 200 + 20, 100 - 8, DC1positive_Temp, 1, 40, WHITE, 3, 0);
        updata_DAT(82 + 200 + 20, 100 - 8 + 38, DC1negative_Temp, 1, 40, WHITE, 3, 0);
        updata_DAT(82 + 200 + 20, 100 - 8 + 38 * 2, DC2positive_Temp, 1, 40, WHITE, 3, 0);
        updata_DAT(82 + 200 + 20, 100 - 8 + 38 * 3, DC2negative_Temp, 1, 40, WHITE, 3, 0);
        updata_DAT(82 + 200 + 20, 100 - 8 + 38 * 4, DC3positive_Temp, 1, 40, WHITE, 3, 0);
        updata_DAT(82 + 200 + 20, 100 - 8 + 38 * 5, DC3negative_Temp, 1, 40, WHITE, 3, 0);
        updata_DAT(82 + 200 + 20, 100 - 8 + 38 * 6, DC4positive_Temp, 1, 40, WHITE, 3, 0);
        updata_DAT(82 + 200 + 20, 100 - 8 + 38 * 7, DC4negative_Temp, 1, 40, WHITE, 3, 0);
        print_D(82 + 180, 100 - 8 + 38 * 8, BMS_Status_Flag5);
        print_D(82 + 180, 100 - 8 + 38 * 9, BMS_Status_Flag6);


        print_SZ_1(82 + 500 + 8, 100 - 8, ChargeSet_Times1, 6, 0, WHITE);
        print_SZ_1(82 + 500 + 8, 100 - 8 + 38, ChargeSet_Times2, 6, 0, WHITE);
        print_SZ_1(82 + 500 + 8, 100 - 8 + 38 * 2, ChargeSet_Times3, 6, 0, WHITE);
        print_SZ_1(82 + 500 + 8, 100 - 8 + 38 * 3, ChargeSet_Times4, 6, 0, WHITE);
        print_D(82 + 180 + 320, 100 - 8 + 38 * 9, BMS_KtStatus_Flag5);

    }
    if (index == 3) {
        print_SZ_1(82 + 180 + 16 * 2, 100 - 8, Battery_Single_H_Positon_Total, 3, 0, WHITE);
        print_SZ_1(82 + 180 + 16 * 2, 100 - 8 + 38, Battery_Single_L_Positon_Total, 3, 0, WHITE);
        print_SZ_1(82 + 180 + 16 * 2, 100 - 8 + 38 * 2, Battery_Temp_H_Positon_Total, 3, 0, WHITE);
        print_SZ_1(82 + 180 + 16 * 2, 100 - 8 + 38 * 3, Battery_Temp_L_Positon_Total, 3, 0, WHITE);
        print_SZ_1(82 + 180 + 16 * 2, 100 - 8 + 38 * 4, Battery_Single_H_Pack, 3, 0, WHITE);
        print_SZ_1(82 + 180 + 16 * 2, 100 - 8 + 38 * 5, Battery_Single_L_Pack, 3, 0, WHITE);
        print_SZ_1(82 + 180 + 16 * 2, 100 - 8 + 38 * 6, Battery_Temp_H_Pack, 3, 0, WHITE);
        print_SZ_1(82 + 180 + 16 * 2, 100 - 8 + 38 * 7, Battery_Temp_L_Pack, 3, 0, WHITE);
    }
    if (index == 4) {
        for (i = 0; i < 10; i++) {
            if (i < BMS_Unit_Number) {
                if (i < 8) {
                    color = ((BMU_Comm_Status[0].byte >> i) & 0x01) > 0 ? RED : GREEN;
                    print_SZ_1(12 + 33 + 32 + 42 + 42 + 16, 100 - 8 + i * 38, (BMU_Comm_Status[0].byte >> i)&0x01, 1, 0, color);
                } else {
                    color = ((BMU_Comm_Status[1].byte >> (i - 8)) & 0x01) > 0 ? RED : GREEN;
                    print_SZ_1(12 + 33 + 32 + 42 + 42 + 16, 100 - 8 + i * 38, (BMU_Comm_Status[1].byte >> (i - 8))&0x01, 1, 0, color);
                }
            }
        }
        for (i = 0; i < 10; i++) {
            if ((10 + i) < BMS_Unit_Number) {
                if (i < 6) {
                    color = ((BMU_Comm_Status[1].byte >> (i + 2)) & 0x01) > 0 ? RED : GREEN;
                    print_SZ_1(12 + 33 + 32 + 42 + 42 + 1 * 195 + 16, 100 - 8 + i * 38, (BMU_Comm_Status[1].byte >> (i + 2))&0x01, 1, 0, color);
                } else {
                    color = ((BMU_Comm_Status[2].byte >> (i - 6)) & 0x01) > 0 ? RED : GREEN;
                    print_SZ_1(12 + 33 + 32 + 42 + 42 + 1 * 195 + 16, 100 - 8 + i * 38, (BMU_Comm_Status[2].byte >> (i - 6))&0x01, 1, 0, color);
                }
            }
        }
        for (i = 0; i < 10; i++) {
            if ((20 + i) < BMS_Unit_Number) {
                if (i < 4) {
                    color = ((BMU_Comm_Status[2].byte >> (i + 4)) & 0x01) > 0 ? RED : GREEN;
                    print_SZ_1(12 + 33 + 32 + 42 + 42 + 2 * 195 + 16, 100 - 8 + i * 38, (BMU_Comm_Status[2].byte >> (i + 4))&0x01, 1, 0, color);
                } else {
                    color = ((BMU_Comm_Status[3].byte >> (i - 4)) & 0x01) > 0 ? RED : GREEN;
                    print_SZ_1(12 + 33 + 32 + 42 + 42 + 2 * 195 + 16, 100 - 8 + i * 38, (BMU_Comm_Status[3].byte >> (i - 4))&0x01, 1, 0, color);
                }
            }
        }
        for (i = 0; i < 2; i++) {
            if ((30 + i) < BMS_Unit_Number) {
                color = ((BMU_Comm_Status[3].byte >> (i + 6)) & 0x01) > 0 ? RED : GREEN;
                print_SZ_1(12 + 33 + 32 + 42 + 42 + 3 * 195 + 16, 100 - 8 + i * 38, (BMU_Comm_Status[3].byte >> (i + 6))&0x01, 1, 0, color);
            }
        }
    }
    if (index == 5) {
        for (i = 0; i < 10; i++) {
            if (i < BMS_Unit_Number) {
                if (i < 8) {
                    color = ((BMU_Bala_Status[0].byte >> i) & 0x01) > 0 ? RED : GREEN;
                    print_SZ_1(12 + 33 + 32 + 42 + 42 + 16, 100 - 8 + i * 38, (BMU_Bala_Status[0].byte >> i)&0x01, 1, 0, color);
                } else {
                    color = ((BMU_Bala_Status[1].byte >> (i - 8)) & 0x01) > 0 ? RED : GREEN;
                    print_SZ_1(12 + 33 + 32 + 42 + 42 + 16, 100 - 8 + i * 38, (BMU_Bala_Status[1].byte >> (i - 8)) & 0x01, 1, 0, color);
                }
            }
        }
        for (i = 0; i < 10; i++) {
            if ((10 + i) < BMS_Unit_Number) {
                if (i < 6) {
                    color = ((BMU_Bala_Status[1].byte >> (i + 2)) & 0x01) > 0 ? RED : GREEN;
                    print_SZ_1(12 + 33 + 32 + 42 + 42 + 1 * 195 + 16, 100 - 8 + i * 38, (BMU_Bala_Status[1].byte >> (i + 2))&0x01, 1, 0, color);
                } else {
                    color = ((BMU_Bala_Status[2].byte >> (i - 6)) & 0x01) > 0 ? RED : GREEN;
                    print_SZ_1(12 + 33 + 32 + 42 + 42 + 1 * 195 + 16, 100 - 8 + i * 38, (BMU_Bala_Status[2].byte >> (i - 6))&0x01, 1, 0, color);
                }
            }
        }
        for (i = 0; i < 10; i++) {
            if ((20 + i) < BMS_Unit_Number) {
                if (i < 4) {
                    color = ((BMU_Bala_Status[2].byte >> (i + 4)) & 0x01) > 0 ? RED : GREEN;
                    print_SZ_1(12 + 33 + 32 + 42 + 42 + 2 * 195 + 16, 100 - 8 + i * 38, (BMU_Bala_Status[2].byte >> (i + 4))&0x01, 1, 0, color);
                } else {
                    color = ((BMU_Bala_Status[3].byte >> (i - 4)) & 0x01) > 0 ? RED : GREEN;
                    print_SZ_1(12 + 33 + 32 + 42 + 42 + 2 * 195 + 16, 100 - 8 + i * 38, (BMU_Bala_Status[3].byte >> (i - 4))&0x01, 1, 0, color);
                }
            }
        }
        for (i = 0; i < 2; i++) {
            if ((30 + i) < BMS_Unit_Number) {
                color = ((BMU_Bala_Status[3].byte >> (i + 6)) & 0x01) > 0 ? RED : GREEN;
                print_SZ_1(12 + 33 + 32 + 42 + 42 + 3 * 195 + 16, 100 - 8 + i * 38, (BMU_Bala_Status[3].byte >> (i + 6))&0x01, 1, 0, color);
            }
        }
    }
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
    if (key_AV) {
        key_AV = 0;
        index_BMS--;
        f_index = 0;
        if (index_BMS == 0) {
            index_BMS = 1;
            frmID = 1;
        }
    }

    if (key_up) { //子菜单切换
        key_up = 0;
        index_BMS++;
        f_index = 0;
        if (index_BMS == 6) {
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
//电池数据界面
/*******************************************************/
//只更新一次的数据

void BatteryFrame(void) {
    unsigned char i, j;
    LCD_Clear();
    //LCD_DrawRect(0, 70, 800, 2, YELLOW); //顶部横线
    LCD_DrawImageSBPP(30, 20, 50, Battery_STSTEM, WHITE, BLACK); //电池

    LCD_DrawImage1BPP(30, 20 + 38 + 7, BMP_BMU, WHITE, BLACK); //箱
    //LCD_DrawImage1BPP(30 + 21, 20 + 38 + 7, BMP_Hao, WHITE, BLACK); //号
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
//一直更新的数据
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
            updata_DAT(82 + 200 + 220, 100 - 38 * 2 - 8 + 38 * i, Battery_Temp[i], 1, 40, BLACK, 3, 0); //无效温度清除
        else
            updata_DAT(82 + 200 + 220, 100 - 38 * 2 - 8 + 38 * i, Battery_Temp[i], 1, 40, WHITE, 3, 0); //单体温度
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
            /*f_index = 0;
            frmID = 1;*/
        }
    }

    if (key_up) {
        key_up = 0;
        //f_index = 0;
        BMU_Number++;
        if (BMU_Number > BMS_Unit_Number) {
            BMU_Number = 1;
            f_index = 0;
            frmID = 1;
        }
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
//仪表诊断
/*******************************************************/
void AirFrame(void) {
    unsigned char i = 0;
    LCD_Clear();
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //顶部横线
    LCD_DrawImageSBPP(130 + 200 - 2, 130 - 85, 50, Air_STSTEM, WHITE, BLACK); //空调系统信息

    LCD_DrawRect(80, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320 + 320, 90, 1, 380, GREEN);
    for (i = 0; i < 11; i++)
        LCD_DrawRect(80, 90 + i * 38, 640, 1, GREEN);

    LCD_DrawImageSBPP(82, 100, 42, KTGZDM, WHITE, BLACK); //空调故障代码

    LCD_DrawImageSBPP(82, 100 + 38, 42, KTDJZT, WHITE, BLACK); //空调电机状态

    LCD_DrawImageSBPP(82, 100 + 38 * 2, 42, KTGZZT, WHITE, BLACK); //空调工作状态

    LCD_DrawImageSBPP(82 + 320, 100, 21, CNSJ, WHITE, BLACK); //车内实际
    LCD_DrawImage1BPP(82 + 320 + 42 + 42, 100, BMP_Wendu, WHITE, BLACK); //温度
    LCD_DrawImage1BPP(720 - 28, 100, BMP_T, WHITE, BLACK); //℃

    LCD_DrawImageSBPP(82 + 320, 100 + 38,21, CWSJ, WHITE, BLACK); //车外实际
    LCD_DrawImage1BPP(82 + 320 + 42 + 42, 100 + 38, BMP_Wendu, WHITE, BLACK); //温度
    LCD_DrawImage1BPP(720 - 28, 100 + 38, BMP_T, WHITE, BLACK); //℃

    LCD_DrawImageSBPP(82 + 320, 100 + 38 * 2, 42, SDWD, WHITE, BLACK); //设定温度
    LCD_DrawImage1BPP(720 - 28, 100 + 38 * 2, BMP_T, WHITE, BLACK); //℃
    
    LCD_DrawImageSBPP(82 + 320, 100 + 38 * 3, 42, SJGL, WHITE, BLACK); //设定温度
    LCD_DrawImage1BPP(720 - 28, 100 + 38 * 3, BMP_k, WHITE, BLACK); //℃
    LCD_DrawImage1BPP(720 - 28 + 11, 100 + 38 * 3, BMP_w, WHITE, BLACK); //℃

}

void AirUpdate(void) {
    print_D(82 + 180, 100 - 8, Air_Status_Flag1); //空调故障码
    print_D(82 + 180, 100 - 8 + 38, Air_Status_Flag2); //空调风速
    print_D(82 + 180, 100 - 8 + 38 * 2, Air_Status_Flag3); //空调状态

    updata_DAT(82 + 63 + 42 + 80 + 32 + 320, 100 - 8, Air_Indoor_t, 0.5, 30, WHITE, 3, 0);
    updata_DAT(82 + 63 + 42 + 80 + 32 + 320, 100 - 8 + 38, Air_Outdoor_t, 0.5, 30, WHITE, 3, 0);
    updata_DAT(82 + 63 + 42 + 80 + 32 + 320, 100 - 8 + 38 * 2, Air_Set_t, 0.5, 30, WHITE, 3, 0);
    print_SZ_1(82 + 63 + 42 + 80 + 32 + 320, 100 - 8 + 38 * 3, Air_Power, 3, 1, WHITE);
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
        f_index = 0;
        frmID = 1;
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
//里程设置界面
/*******************************************************/
//只更新一次的数据

void SETFrame(void) {
    LCD_Clear();
    //unsigned char i;
    //unsigned char color = WHITE;
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //顶部横线   
    LCD_DrawRect(0, 430 + 15, 800, 2, YELLOW); //底部横线   
    LCD_DrawImage1BPP(220, 195, Bmp_Licheng, WHITE, BLACK); //累计里程
    LCD_DrawImage1BPP(405, 190, BMP_HZ_KM, WHITE, BLACK); //单位 Km 
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

//密码输入
/*void update_code(unsigned int Tid,unsigned int *ptr){
   unsigned char color = 0, color1 = 0;
    if (Tid == 0) {
        color = RED;
        color1 = RED;
    } else {
        color = GRAY;
        color1 = WHITE;
    }
    disp_rectange(320 + 40 * 0, 220, 4, 40, 2, color);
    LCD_DrawImage1BPP(328 + 40 * 0, 230, 2, 18, BMP_SZ_1[*ptr++], color1, BLACK);

    if (Tid == 1) {
        color = RED;
        color1 = RED;
    } else {
        color = GRAY;
        color1 = WHITE;
    }
    disp_rectange(320 + 40 * 1, 220, 4, 40, 2, color);
    LCD_DrawImage1BPP(328 + 40 * 1, 230, 2, 18, BMP_SZ_1[*ptr++], color1, BLACK);

    if (Tid == 2) {
        color = RED;
        color1 = RED;
    } else {
        color = GRAY;
        color1 = WHITE;
    }
    disp_rectange(320 + 40 * 2, 220, 4, 40, 2, color);
    LCD_DrawImage1BPP(328 + 40 * 2, 230, 2, 18, BMP_SZ_1[*ptr++], color1, BLACK);

    if (Tid == 3) {
        color = RED;
        color1 = RED;
    } else {
        color = GRAY;
        color1 = WHITE;
    }
    disp_rectange(320 + 40 * 3, 220, 4, 40, 2, color);
    LCD_DrawImage1BPP(328 + 40 * 3, 230, 2, 18, BMP_SZ_1[*ptr++], color1, BLACK);   
}


void frm_code(void){  
 static unsigned int  Tid=0;
 static unsigned int  bcd[4]={0,0,0,0};
      
  if(_index==0){
    _index=1;
    Tid=0;
    key_set =0;
    key_duble=0;
    disp_frm(6);
    LCD_DrawImage1BPP(290,190,10,18,Bmp_srmm,GREEN,BLACK);
    bcd[0]=1;
    bcd[1]=2;   
    bcd[2]=3;
    bcd[3]=4;  
  }else if(_index==1){
    _index=1;
    update_code(Tid,&bcd[0]);
  }else{
    _index=0;
  }
  if(key_set){
    key_set=0;
    if(Tid>=3)Tid=0;
    else      Tid++;
    //验证密码     bcd[2]*1000+ bcd[0]*100+bcd[3]*10+bcd[1];//变换随机数A
    if(single_miles==(unsigned int)(bcd[0]*1000+ bcd[1]*100+bcd[2]*10+bcd[3])){
      menuid=31; 
      _index=0;    
    }
  }
  if(key_set){
     key_set=0;
    if(Tid<=3){
      if(bcd[Tid]>0) bcd[Tid]--; 
      else           bcd[Tid]=0;
    }else Tid=0;
  }
  if(key_up){
     key_up=0;
    if(Tid<=3){
      if(bcd[Tid]<9) bcd[Tid]++; 
      else           bcd[Tid]=9;
    }else Tid=0;
  }
  if(key_duble){
    key_duble=0;
    menuid=0;
    _index=0;
  }
}
 */
//总里程设置

/*void update_miles(unsigned int Tid, unsigned int *ptr) {
    
}

void frm_miles(void) {
    
}
 */

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
            frmSET();
            break;
        case 9:
            frmIC();
            break;
        case 10:
            frmAir();
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



