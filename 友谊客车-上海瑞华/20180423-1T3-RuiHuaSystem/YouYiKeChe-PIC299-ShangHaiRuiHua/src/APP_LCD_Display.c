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

void LCD_DrawImageSBPP1(unsigned int x, unsigned int y,    
        __prog__ const unsigned char *img[], //字符串首地址
        unsigned char fcolor, //字体前景色
        unsigned char bcolor //字体背景色
        ) {
    unsigned char i,witd = 0;
    witdh = 0;
    for (i = 0; img[i] != NULL; i++) {
        LCD_DrawImage1BPP(x + witdh, y, img[i], fcolor, bcolor);
        witd = *(img[i] + 1) * 7;
        witdh += witd;
    }
}

typedef struct {         
    __prog__ const unsigned char **img;
    unsigned char squence;
    unsigned char condition;    
} CAN_WARN_LIST;

#define CAN_LIST_NUMBER 100
CAN_WARN_LIST list[CAN_LIST_NUMBER] = {
    {QBMKLX, 0},//前部模块离线
    {DBMKLX, 1},//顶部模块离线
    {HBMKLX, 2},//后部模块离线
    {DLDCGZ, 3},//动力电池故障
    {DJGZ, 4},//电机故障
    {JYGZ, 5},//绝缘故障
    {BSXGZ, 6},//变速箱故障
    {DCDCGZ, 7},//DCDC故障
    {ZXDCACGZ, 8},//转向DCAC故障
    {ZDDCACGZ, 9},//制动DCAC故障
    {YMTBGZ, 10},//油门踏板故障
    {CSBJ, 11},//超速故障
    {ZDTBGZ, 12},//制动踏板故障
    {KTGZ, 13},//空调故障
    {ABSGZ, 14},//ABS故障
    {HDGZ, 15},//换挡故障
    {YCGZ, 16},//预充故障
    {VCUJDQGZ, 17},//VCU继电器故障
    {DCDCWDGZ, 18},//DC-DC 温度报警
    {SWGZ, 19},//冷却水温故障
    {CHAGRE, 20},//正在充电，禁止行车
    {WDCYBJ, 21},//温度差异报警
    {DCWDGBJ, 22},//电池过温报警
    {DCGYBJ, 23},//电池过压报警
    {DCQYBJ, 24},//电池欠压报警
    {SOCDBJ, 25},//SOC高报警
    {DTDCGYBJ, 26},//单体电压过压报警
    {DTDCQYBJ, 27},//单体电压欠压报警
    {SOCGGBJ, 28},//SOC过高报警
    {HZBJGZ, 29},//火灾报警故障
    {SOCTBBJ, 30},//SOC跳变故障
    {CDXTCNBJ, 31},//充电储能系统故障
    {DCDTCYBJ, 32},//电池单体差异报警
    {DCGC, 33},//电池过充
    {GYHSZTBJ, 34},//高压互锁状态报警
    {YWBJGZ, 35},//烟雾报警故障
    {DJKZQTXGZ, 36},//电机控制器系统故障
    {DCTXGZ, 37},//电池通讯故障
    {DCDCTXGZ, 38},//DCDC通讯故障
    {XDCDYD, 39},//蓄电池电压低
    {VCUXTGZ, 40},//VCU故障
    {ZMWG, 41},//中门未关报警
    {QMWG, 42},//前门未关报警
    {ZDDCACTXGZ, 43},
    {GYDCACTXGZ, 44},
    {DYDCACTXGZ, 45},
    {GYGTXGZ, 46},
    {HDTXGZ, 47},
    {JYTXGZ, 48},
    {ABSTXGZ, 49},
    {KTTXGZ, 50},
    {TYTXGZ, 51},
    {YCTXGZ, 52},
    {CSXHWX, 53},
    {CSWXXH, 54},
    {HDXTGZ, 55},
    {DJWDBJ, 56},
    {DJKZQWDBJ, 57},
    {DJMXGY, 58},
    {DJMXQY, 59},
    {DJGDL, 60},
    {DJCS, 61},
    {DJDZ, 62},
    {XBXDX, 63},
    {XBXGZ, 64},
    {IGBTGZ, 65},
    {QBXTGZ, 66},
    {YBXTGZ, 67},
    {HCMWG, 68},//后仓门未关报警
    {}
};

static void CAN_WARN_UPDATE(void) {
    list[0].condition = (Fcan_count == CAN_TIME);
    list[1].condition = (Mcan_count == CAN_TIME);
    list[2].condition = 0;//(Rcan_count == CAN_TIME);
    list[3].condition = (CAN_0x18EF5AEF.No1 > 0);
    list[4].condition = (CAN_0x18EF5AEF.No2 || CAN_0x18EF5AEF.No3);
    list[5].condition = (CAN_0x18EF5AEF.No4 > 0);
    list[6].condition = (CAN_0x18EF5AEF.No5 > 0);
    list[7].condition = (CAN_0x18EF5AEF.No6_1 > 0);
    list[8].condition = (CAN_0x18EF5AEF.No6_2 > 0);
    list[9].condition = (CAN_0x18EF5AEF.No7 > 0);
    list[10].condition = (CAN_0x18EF5AEF.No8 > 0);
    list[11].condition = (SPEED > 69);
    list[12].condition = (CAN_0x18EF5AEF.No9 > 0);
    list[13].condition = (CAN_0x18EF5AEF.No10 > 0);
    list[14].condition = (CAN_0x18EF5AEF.No11 > 0);
    list[15].condition = (CAN_0x18EF5AEF.No12 > 0);
    list[16].condition = (CAN_0x18EF5AEF.No14 > 0);
    list[17].condition = (CAN_0x18EF5AEF.No15 > 0);
    list[18].condition = (CAN_0x18EF5AEF.No17 > 0);
    list[19].condition = (CAN_0x18EF5AEF.No18 > 0);
    list[20].condition = (CAN_0x18EF4BEF.No27);
    list[21].condition = (CAN_0x18EF5AEF.No19 > 0);
    list[22].condition = (CAN_0x18EF5AEF.No20 > 0);
    list[23].condition = (CAN_0x18EF5AEF.No21 > 0);
    list[24].condition = (CAN_0x18EF5AEF.No22 > 0);
    list[25].condition = (CAN_0x18EF5AEF.No23 > 0);
    list[26].condition = (CAN_0x18EF5AEF.No24 > 0);
    list[27].condition = (CAN_0x18EF5AEF.No25 > 0);
    list[28].condition = (CAN_0x18EF5AEF.No26 > 0);
    list[29].condition = (CAN_0x18EF5AEF.No32 > 0);
    list[30].condition = (CAN_0x18EF5AEF.No27 > 0);
    list[31].condition = (CAN_0x18EF5AEF.No28 > 0);
    list[32].condition = (CAN_0x18EF5AEF.No29 > 0);
    list[33].condition = (CAN_0x18EF5AEF.No30 > 0);
    list[34].condition = (CAN_0x18EF5AEF.No31 > 0);
    list[35].condition = (CAN_0x18EF5AEF.No33 > 0);
    list[36].condition = (CAN_0x18EF5AEF.No34 || CAN_0x18EF5AEF.No35);
    list[37].condition = (CAN_0x18EF5AEF.No36 > 0);
    list[38].condition = (CAN_0x18EF5AEF.No38 > 0);
    list[39].condition = (BAT24V_count == BAT24_TIME);
    list[40].condition = (CAN_0x18FECAEF.Ev_Fail_Mode > 0);
    list[41].condition = (SPEED > 5 && LED2);
    list[42].condition = (SPEED > 5 && LED1);
    list[43].condition = (CAN_0x18EF5AEF.No39 > 0);
    list[44].condition = (CAN_0x18EF5AEF.No40 > 0);
    list[45].condition = (CAN_0x18EF5AEF.No41 > 0);
    list[46].condition = (CAN_0x18EF5AEF.No42 > 0);
    list[47].condition = (CAN_0x18EF5AEF.No43 > 0);
    list[48].condition = (CAN_0x18EF5AEF.No44 > 0);
    list[49].condition = (CAN_0x18EF5AEF.No45 > 0);
    list[50].condition = (CAN_0x18EF5AEF.No46 > 0);
    list[51].condition = (CAN_0x18EF5AEF.No47 > 0);
    list[52].condition = (CAN_0x18EF5AEF.No48 > 0);
    list[53].condition = (CAN_0x18EF5BEF.No1 > 0);
    list[54].condition = (CAN_0x18EF5BEF.No2 > 0);
    list[55].condition = (CAN_0x18EF5BEF.No3
            || CAN_0x18EF5BEF.No4
            || CAN_0x18EF5BEF.No5
            || CAN_0x18EF5BEF.No6
            || CAN_0x18EF5BEF.No7
            || CAN_0x18EF5BEF.No8);
    list[56].condition = (CAN_0x18EF5BEF.No9 > 0);
    list[57].condition = (CAN_0x18EF5BEF.No10 > 0);
    list[58].condition = (CAN_0x18EF5BEF.No11 > 0);
    list[59].condition = (CAN_0x18EF5BEF.No12 > 0);
    list[60].condition = (CAN_0x18EF5BEF.No13 > 0);
    list[61].condition = (CAN_0x18EF5BEF.No14 > 0);
    list[62].condition = (CAN_0x18EF5BEF.No15 > 0);
    list[63].condition = (CAN_0x18EF5BEF.No16 > 0);
    list[64].condition = (CAN_0x18EF5BEF.No17 > 0);
    list[65].condition = (CAN_0x18EF5BEF.No18 > 0);
    list[66].condition = (AIRDCAC_FaultCode > 0);
    list[67].condition = (OILDCAC_FaultCode > 0);
    list[68].condition = (SPEED > 5 && mKH1);
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

/*void CAN_WARN_LIST1(unsigned int x, unsigned int y,
        unsigned char condititon,
        __prog__ const unsigned char *img[]
        ) {
    if (condititon) {
        LCD_DrawImageSBPP1(x, y, img, YELLOW, BLACK);
        LCD_DrawRect(x + witdh, y, 250 - witdh, 36, BLACK);
    }
}*/

void disp_miles(unsigned int x, unsigned int y) {//显示里程
    print_SZ_1(x + 16, y + 15 + 36 * 1 + 2, single_miles, 5, 1, WHITE);
    print_SZ_1(x, y + 15 + 36 * 2 + 2, total_miles / 10, 7, 0, WHITE);
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

    if (IN37) color = YELLOW;
    else color = GRAY;
    if (color_old[0] != color) {
        color_old[0] = color;
        LCD_DrawImage1BPP(8, 10, Bmp_baojing[1], color, BLACK); //ABS
    }

    if (CAN_0x18FECAEF.Ev_Fail_Mode > 0) color = RED;
    else color = GRAY;
    if (color_old[1] != color) {
        color_old[1] = color;
        LCD_DrawImage1BPP(8 + 66, 10, Bmp_baojing[9], color, BLACK); //系统故障
    }

    if (IN12) color = RED;
    else color = GRAY;
    if (color_old[2] != color) {
        color_old[2] = color;
        LCD_DrawImage1BPP(8 + 66 * 2, 10, Bmp_baojing[3], color, BLACK); //后舱门
    }

    if (!IN15) color = RED;
    else color = GRAY;
    if (color_old[3] != color) {
        color_old[3] = color;
        LCD_DrawImage1BPP(8 + 66 * 3, 10, Bmp_baojing[7], color, BLACK); //左前刹车片
        LCD_DrawImage1BPP(8 + 66 * 3 + 17, 10 + 15, BMP_l, color, BLACK);
        print_SZ(8 + 66 * 3 + 17 + 11, 10 + 18, 1, 1, 0, color);
    }

    if (CAN_0x18EF5AEF.No4 > 0) color = RED;
    else color = GRAY;
    if (color_old[4] != color) {
        color_old[4] = color;
        LCD_DrawImage1BPP(8 + 66 * 4, 10, Bmp_baojing[5], color, BLACK); //绝缘报警
    }

    if (CAN_0x18EF5AEF.No18 || IN13) color = RED;
    else color = GRAY;
    if (color_old[5] != color) {
        color_old[5] = color;
        LCD_DrawImage1BPP(8 + 66 * 5, 10, Bmp_baojing[2], color, BLACK); //水位

    }

    if (IN31) color = RED;
    else color = GRAY;
    if (color_old[6] != color) {
        color_old[6] = color;
        LCD_DrawImage1BPP(8 + 66 * 6, 10, Bmp_baojing[14], color, BLACK); //安全带
    }

    if (!IN16) color = RED;
    else color = GRAY;
    if (color_old[7] != color) {
        color_old[7] = color;
        LCD_DrawImage1BPP(8 + 66 * 7, 10, Bmp_baojing[7], color, BLACK); //右前刹车片
        LCD_DrawImage1BPP(8 + 66 * 7 + 17, 10 + 15, BMP_r, color, BLACK);
        print_SZ(8 + 66 * 7 + 17 + 11, 10 + 18, 1, 1, 0, color);
    }

    if (CAN_0x18EF5AEF.No5 == 1) color = RED;
    else color = GRAY;
    if (color_old[8] != color) {
        color_old[8] = color;
        LCD_DrawImage1BPP(8 + 66 * 8, 10, Bmp_baojing[16], color, BLACK); //变速箱 
    }

    if (!CAN_0x18EF4BEF.No21) color = YELLOW;
    else color = GRAY;
    if (color_old[9] != color) {
        color_old[9] = color;
        LCD_DrawImage1BPP(8 + 66 * 9, 10, Bmp_baojing[6], color, BLACK); //动力电池切断
    }

    if (CAN_0x18EF5BEF.No9) color = RED;
    else color = GRAY;
    if (color_old[10] != color) {
        color_old[10] = color;
        LCD_DrawImage1BPP(8 + 66 * 10, 10, Bmp_baojing[10], color, BLACK); //电机过温
    }

    if (IN21 || IN22) color = GREEN;
    else color = GRAY;
    if (color_old[11] != color) {
        color_old[11] = color;
        LCD_DrawImage1BPP(8 + 66 * 11, 10, Bmp_baojing[17], color, BLACK); //除霜
    }
    /****************************第二行图片****************************************/
    if (!IN24 && WAKE_ON && (CAN_0x18EF4AEF.EV_Gear == 13 || CAN_0x18EF4AEF.EV_Gear == 14) && !IN26) color = RED;
    else color = GRAY;
    if (color_old[12] != color) {
        color_old[12] = color;
        LCD_DrawImage1BPP(140 + 66 * 0, 74 - 5, Bmp_baojing[13], color, BLACK); //重力感应
    }

    if (0) color = RED;
    else color = GRAY;
    if (color_old[13] != color) {
        color_old[13] = color;
        LCD_DrawImage1BPP(140 + 66 * 1, 74 - 5, Bmp_baojing[7], color, BLACK); //左后刹车片
        LCD_DrawImage1BPP(140 + 66 * 1 + 19, 74 - 5 + 15, BMP_l, color, BLACK);
        print_SZ(140 + 66 * 1 + 19 + 11, 74 - 5 + 18, 2, 1, 0, color);
        //LCD_DrawImage1BPP(140 + 66 * 1, 74 - 5, Bmp_baojing[13], color, BLACK); //重力感应
    }

    if (mKL4 || mKL6) color = RED;
    else color = GRAY;
    if (color_old[14] != color) {
        color_old[14] = color;
        LCD_DrawImage1BPP(140 + 66 * 2, 74 - 5, Bmp_baojing[11], color, BLACK); //前门应急阀
    }
    if (mKL4)
        color = RED;
    else 
        color = GRAY;
    print_SZ(140 + 66 * 2 + 54 - 1, 74 - 5 + 18 - 22, 1, 1, 0, color);
    
    if (mKL6)
        color = RED;
    else 
        color = GRAY;
    print_SZ(140 + 66 * 2 + 54 - 1, 74 - 5 + 18 + 16, 2, 1, 0, color);
    /////////////////////////////////////////////////////////////////////////////////////////

    if (CAN_0x18EF4BEF.No20) color = GREEN;
    else color = GRAY;
    if (color_old[15] != color) {
        color_old[15] = color;
        LCD_DrawImage1BPP(138 + 66 * 3 - 1, 74 + 12 - 5, Bmp_READY, color, BLACK); //ready
    }

    if (0) color = RED;
    else color = GRAY;
    if (color_old[16] != color) {
        color_old[16] = color;
        //档位
    }

    if (0) color = RED;
    else color = GRAY;
    if (color_old[17] != color) {
        color_old[17] = color;
        LCD_DrawImage1BPP(140 + 66 * 5, 74 - 5, Bmp_baojing[7], color, BLACK); //右后摩擦片
        LCD_DrawImage1BPP(140 + 66 * 5 + 19, 74 - 5 + 15, BMP_r, color, BLACK);
        print_SZ(140 + 66 * 5 + 19 + 11, 74 - 5 + 18, 2, 1, 0, color);
    }

    if (mKL2) color = YELLOW;
    else color = GRAY;
    if (color_old[18] != color) {
        color_old[18] = color;
        LCD_DrawImage1BPP(140 + 66 * 6, 74 - 5, Bmp_baojing[8], color, BLACK); //门铃
    }

    if (0) color = RED;
    else color = GRAY;
    if (color_old[19] != color) {
        color_old[19] = color;
        //LCD_DrawImage1BPP(140 + 66 * 7, 74 - 5, Bmp_baojing[17], color, BLACK); //中门应急阀
    }

}

void disp_FONT_baojingNew(unsigned int x, unsigned int y) {
    if (alarm_update_flag == 0) {
        alarm_update_flag = 1;
        CAN_WARN(x, y + 8, list);      
    }
}
#if 0
void disp_FONT_baojing(unsigned int x, unsigned int y) {
    static unsigned char al_index = 0; //, Comm_i = 0, Comm_j = 0, FLAG;
    if (alarm_update_flag == 0) { //3S 更新一次 
        switch (al_index) {
            case 0:
                al_index = 1;
                /*if (Fcan_count == CAN_TIME) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Qianbu, YELLOW, BLACK); //前部
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Mokuai, YELLOW, BLACK); //模块
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Lixian, YELLOW, BLACK); //离线
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/

            case 1:
                al_index = 2;
                if (Mcan_count == CAN_TIME) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Dingbu, YELLOW, BLACK); //顶部
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Mokuai, YELLOW, BLACK); //模块
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Lixian, YELLOW, BLACK); //离线
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 2:
                al_index = 3;
                if (Rcan_count == CAN_TIME) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Houbu, YELLOW, BLACK); //后部
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Mokuai, YELLOW, BLACK); //模块
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Lixian, YELLOW, BLACK); //离线
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 3:
                al_index = 4;
                if (1) {
                    LCD_DrawImageSBPP(x, y + 8, 42, DLDCGZ, YELLOW, BLACK); //动力电池故障
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 4:
                al_index = 5;
                if (1) {
                    LCD_DrawImageSBPP(x, y + 8, 42, DJGZ, YELLOW, BLACK); //电机故障
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    //CAN_WARN_LIST1(x, y + 8, 1, DJGZ);
                    alarm_update_flag = 1;
                    break;
                }
                
            case 5:
                al_index = 6;
                if (1) {
                    LCD_DrawImageSBPP(x, y + 8, 42, JYGZ, YELLOW, BLACK); //绝缘故障
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    //CAN_WARN_LIST1(x, y + 8, 1, JYGZ);
                    alarm_update_flag = 1;
                    break;
                }

            case 6:
                al_index = 7;
                if (1) {
                    LCD_DrawImageSBPP(x, y + 8, 63, BSXGZ, YELLOW, BLACK); //变速箱故障
                    LCD_DrawRect(x + 63 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 7:
                al_index = 8;
                if (1) {
                    LCD_DrawImageSBPP1(x, y + 8,DCDCGZ, YELLOW, BLACK); //DCDC故障
                    LCD_DrawRect(x + 14 * 4 + 44, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 8:
                al_index = 9;
                if (1) {
                    LCD_DrawImageSBPP1(x, y + 8, ZXDCACGZ, YELLOW, BLACK); //转向DCAC故障       
                    LCD_DrawRect(x + 14 * 4 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
                /*if (VCU_FaultCode == 142 || VCU_FaultCode == 212) {
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
                if (1) {
                    LCD_DrawImageSBPP1(x, y + 8, ZDDCACGZ, YELLOW, BLACK); //制动DCAC故障       
                    LCD_DrawRect(x + 14 * 4 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
                /*if (VCU_FaultCode == 143 || VCU_FaultCode == 213) {
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
                if (EV_DTC.A_Fault == 1) {
                    LCD_DrawImageSBPP1(x, y + 8,YMTBGZ, YELLOW, BLACK); //油门踏板故障       
                    LCD_DrawRect(x + 65 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
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
                
            case 11:
                al_index = 12;
                if (SPEED > 69) {
                    LCD_DrawImageSBPP1(x, y + 8, CSBJ, YELLOW, BLACK); //超速报警
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
            case 12:
                al_index = 13;
                if (1) {
                    LCD_DrawImageSBPP1(x, y + 8, ZDTBGZ, YELLOW, BLACK); //制动踏板故障       
                    LCD_DrawRect(x + 42 * 3, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
                /*if (VCU_FaultCode == 145 || VCU_FaultCode == 215) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Fang, YELLOW, BLACK); //放电电流报警
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_DL, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_DL, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                
            case 13:
                al_index = 14;
                if (1) {
                    LCD_DrawImageSBPP(x, y + 8, 42, KTGZ, YELLOW, BLACK); //空调故障       
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
                /*if (VCU_FaultCode == 146 || VCU_FaultCode == 216) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Chong, YELLOW, BLACK); //充电电流报警
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_DL, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_DL, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
            case 14:
                al_index = 15;
                if (1) {
                    LCD_DrawImageSBPP1(x, y + 8,ABSGZ, YELLOW, BLACK); //ABS故障       
                    LCD_DrawRect(x + 14 * 3 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
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
                
            case 15:
                al_index = 16;
                if (1) {
                    LCD_DrawImageSBPP1(x, y + 8,HDGZ, YELLOW, BLACK); //换挡故障       
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
                /*if (VCU_FaultCode == 151 || VCU_FaultCode == 221) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Wendu, YELLOW, BLACK); //温度差异报警
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Chayi, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/

            case 16:
                al_index = 17;
                if (1) {
                    LCD_DrawImageSBPP(x, y + 8, 42, YCGZ, YELLOW, BLACK); //预充故障       
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 17:
                al_index = 18;
                if (1) {
                    LCD_DrawImageSBPP1(x, y + 8,VCUJDQGZ, YELLOW, BLACK); //VCU继电器故障       
                    LCD_DrawRect(x + 14 * 3 + 42 * 5, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
                /*if (VCU_FaultCode == 316) {
                    LCD_DrawImageSBPP(x, y + 8, 11, SOC, YELLOW, BLACK); //SOC高报警
                    LCD_DrawImage1BPP(x + 11 + 11 + 11, y + 8, BMP_Gao, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11 + 11 + 21, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 11 + 11 + 11 + 21 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/

            case 18:
                al_index = 19;
                if (1) {
                    LCD_DrawImageSBPP1(x, y + 8,DCDCWDGZ, YELLOW, BLACK); //DC-DC 温度报警       
                    LCD_DrawRect(x + 14 * 4 + 42 * 4, y, 50, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
                /*if (VCU_FaultCode == 313) {
                    LCD_DrawImageSBPP(x, y + 8, 11, SOC, YELLOW, BLACK); //SOC差异报警
                    LCD_DrawImage1BPP(x + 11 + 11 + 11, y + 8, BMP_Chayi, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11 + 11 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 11 + 11 + 11 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/

            case 19:
                al_index = 20;
                if (1) {
                    LCD_DrawImageSBPP(x, y + 8,21,SWGZ, YELLOW, BLACK); //水温故障     
                    LCD_DrawRect(x + 42 * 2, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
                /*if (VCU_FaultCode == 220 || VCU_FaultCode == 150) {
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
                if (BMS_ChargeGun_Link == 3) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Charging, YELLOW, BLACK); //正在充电，禁止行车    
                    alarm_update_flag = 1;
                    break;
                }

            case 21:
                al_index = 22;
                if (1) {
                    LCD_DrawImageSBPP1(x, y + 8, WDCYBJ, YELLOW, BLACK); //温度差异报警     
                    LCD_DrawRect(x + 42 * 3, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
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
                if (1) {
                    LCD_DrawImageSBPP1(x, y + 8, DCWDGBJ, YELLOW, BLACK); //电池高温报警     
                    LCD_DrawRect(x + 21 * 7, y, 50, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
                /*if (VCU_FaultCode == 310 || VCU_FaultCode == 311 || VCU_FaultCode == 312) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Jiare, YELLOW, BLACK); //加热故障
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42, y, 150, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/

            case 23:
                al_index = 24;
                if (1) {
                    LCD_DrawImageSBPP1(x, y + 8, DCGYBJ, YELLOW, BLACK); //电池过压报警     
                    LCD_DrawRect(x + 21 * 6, y, 50, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
                /*if (Concentrated_Lubrication.bit5) {
                    LCD_DrawImageSBPP(x, y + 8, 42, JZRH, YELLOW, BLACK); //集中润滑报警
                    LCD_DrawImage1BPP(x + 84, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 84 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/

            case 24:
                al_index = 25;
                if (1) {
                    LCD_DrawImageSBPP1(x, y + 8, DCQYBJ, YELLOW, BLACK); //电池欠压报警     
                    LCD_DrawRect(x + 21 * 6, y, 50, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
                /*if (VCU_FaultCode == 163 || VCU_FaultCode == 233) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Chong, YELLOW, BLACK); //充电报警
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/

            case 25:
                al_index = 26;
                if (1) {
                    LCD_DrawImageSBPP1(x, y + 8, SOCDBJ, YELLOW, BLACK); //SOC 低报警     
                    LCD_DrawRect(x + 14 * 3 + 21 * 3, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
                /*if (BMS_ChargeGun_Comm == 1) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Chong, YELLOW, BLACK); //充电通讯报警
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Tongxin, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/

            case 26:
                al_index = 27;
                if (1) {
                    LCD_DrawImageSBPP1(x, y + 8, DTDCGYBJ, YELLOW, BLACK); //单体电池过压报警   
                    LCD_DrawRect(x + 14 * 0 + 21 * 8, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
                /*if (EV_DTC.Fire_Fault ) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Yanwu, YELLOW, BLACK); //烟雾报警
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/

            case 27:
                al_index = 28;
                if (1) {
                    LCD_DrawImageSBPP1(x, y + 8, DTDCQYBJ, YELLOW, BLACK); //单体电池欠压报警   
                    LCD_DrawRect(x + 14 * 0 + 21 * 8, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 28:
                al_index = 29;
                if (1) {
                    LCD_DrawImageSBPP1(x, y + 8, SOCGGBJ, YELLOW, BLACK); //SOC 过高报警   
                    LCD_DrawRect(x + 14 * 3 + 21 * 4, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
                /*if (VCU_FaultCode == 168) {
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
                if (1) {
                    LCD_DrawImageSBPP1(x, y + 8,HZBJGZ, YELLOW, BLACK); //火灾报警故障
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 30:
                al_index = 31;
                if (1) {
                    LCD_DrawImageSBPP1(x, y + 8, SOCTBBJ, YELLOW, BLACK); //SOC 跳变报警   
                    LCD_DrawRect(x + 14 * 3 + 21 * 4, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
                /*if (VCU_FaultCode == 314) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Chunnengxitong, YELLOW, BLACK); //储能系统不匹配
                    LCD_DrawRect(x + 147, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/

            case 31:
                al_index = 32;
                if (1) {
                    LCD_DrawImageSBPP1(x, y + 8, CDXTCNBJ, YELLOW, BLACK); //充电储能系统报警  
                    LCD_DrawRect(x + 14 * 0 + 21 * 8, y, 50, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
                /*if (VCU_FaultCode == 313) {
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
                if (1) {
                    LCD_DrawImageSBPP1(x, y + 8, DCDTCYBJ, YELLOW, BLACK); //电池单体差异报警  
                    LCD_DrawRect(x + 14 * 0 + 21 * 8, y, 50, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
                /*if (BMS_FireWarnLevel == 1 || BMS_FireWarnLevel == 2) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DC, YELLOW, BLACK); //电池火灾预警
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Huozai, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Yujing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/

            case 33:
                al_index = 34;
                if (1) {
                    LCD_DrawImageSBPP1(x, y + 8, DCGC, YELLOW, BLACK); //电池过充  
                    LCD_DrawRect(x + 14 * 0 + 21 * 4, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
                /*if (fKL12 && SPEED > 5) {
                    LCD_DrawImageSBPP(x, y + 8, 21, HCMWG, YELLOW, BLACK); //后舱门未关                   
                    LCD_DrawRect(x + 21 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/

            case 34:
                al_index = 35;
                if (1) {
                    LCD_DrawImageSBPP1(x, y + 8, GYHSZTBJ, YELLOW, BLACK); //高压互锁状态报警  
                    LCD_DrawRect(x + 14 * 0 + 21 * 8, y, 50, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
                /*if (!mKL12 && KT_SIGNAL) {
                    LCD_DrawImageSBPP(x, y + 8, 42, ZLBJ, YELLOW, BLACK); //重力报警
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/

            case 35:
                al_index = 36;
                if (1) {
                    LCD_DrawImageSBPP1(x, y + 8, YWBJGZ, YELLOW, BLACK); //烟雾报警故障  
                    LCD_DrawRect(x + 14 * 0 + 21 * 6, y, 50, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
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

            case 36:
                al_index = 37;
                if (1) {
                    LCD_DrawImageSBPP1(x, y + 8, DJKZQTXGZ, YELLOW, BLACK); //电机控制器通讯故障  
                    LCD_DrawRect(x + 14 * 0 + 21 * 9, y, 50, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 37:
                al_index = 38;
                if (1) {
                    LCD_DrawImageSBPP1(x, y + 8, DCTXGZ, YELLOW, BLACK); //电池通讯故障  
                    LCD_DrawRect(x + 14 * 0 + 21 * 6, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
                /*DM(1, TCU_DM1);
                if (SPN > 0) {
                    LCD_DrawImageSBPP(x, y + 8, 11, TCU, YELLOW, BLACK); //TCU SPNxxxxxx FMI xx
                    LCD_DrawImageSBPP(x + 11 * 4, y + 8, 11, CHAR_SPN, YELLOW, BLACK);
                    print_SZ_2(x + 11 * 7, y + 8, SPN, 6, 0, RED);
                    LCD_DrawImageSBPP(x + 11 * 16, y + 8, 11, CHAR_FMI, YELLOW, BLACK);
                    print_SZ_2(x + 11 * 20, y + 8, FMI, 2, 0, RED);
                    LCD_DrawRect(x + 11 * 23, y, 50, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/

            case 38:
                al_index = 39;
                if (1) {
                    LCD_DrawImageSBPP1(x, y + 8, DCDCTXGZ, YELLOW, BLACK); //DCDC通讯故障  
                    LCD_DrawRect(x + 14 * 4 + 21 * 4, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
                /*if (VCU_Lock > 0) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_System, YELLOW, BLACK); //系统互锁故障
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Husuo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/

            case 39:
                al_index = 40;
                if (BAT24V_count >= BAT24_TIME) {
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
                DM(1, VCU_DM1);
                if (SPN > 0) {
                    LCD_DrawImageSBPP(x, y + 8, 11, VCU, YELLOW, BLACK); //VCU SPNxxxxxx FMI xx
                    LCD_DrawImageSBPP(x + 11 * 4, y + 8, 11, CHAR_SPN, YELLOW, BLACK);
                    print_SZ_2(x + 11 * 7, y + 8, SPN, 6, 0, RED);
                    LCD_DrawImageSBPP(x + 11 * 16, y + 8, 11, CHAR_FMI, YELLOW, BLACK);
                    print_SZ_2(x + 11 * 20, y + 8, FMI, 2, 0, RED);
                    LCD_DrawRect(x + 11 * 23, y, 50, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 41:
                al_index = 42;
                if (1) {
                    LCD_DrawImageSBPP1(x, y + 8, VCUXTGZ, YELLOW, BLACK); //VCU系统故障
                    LCD_DrawRect(x + 14 * 3 + 21 * 4, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 42:
                al_index = 43;
                if (LED2 && SPEED > 5) {
                    LCD_DrawImageSBPP(x, y + 8, 21, ZMWG, YELLOW, BLACK); //中门未关                   
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 43:
                al_index = 44;
                if (LED1 && SPEED > 5) {
                    LCD_DrawImageSBPP(x, y + 8, 21, QMWG, YELLOW, BLACK); //前门未关                   
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 44:
                al_index = 45;
                if (OILDCAC_FaultCode > 0) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Youbeng, YELLOW, BLACK); //油泵系统故障
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_System, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 45:
                al_index = 46;
                if (AIRDCAC_FaultCode > 0) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Qibeng, YELLOW, BLACK); //气泵系统故障
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_System, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 46:
                al_index = 47;
                if (1) {
                    LCD_DrawImageSBPP1(x, y + 8, ZDDCACTXGZ, YELLOW, BLACK); //制动 DCAC 通讯故障  
                    LCD_DrawRect(x + 14 * 4 + 21 * 6, y, 50, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
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
                if (1) {
                    LCD_DrawImageSBPP1(x, y + 8, GYDCACTXGZ, YELLOW, BLACK); //高压转向 DCAC 通讯故障   
                    LCD_DrawRect(x + 14 * 4 + 21 * 6, y, 50, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 48:
                al_index = 49;
                if (1) {
                    LCD_DrawImageSBPP1(x, y + 8, DYDCACTXGZ, YELLOW, BLACK); //低压转向 DCAC 通讯故障   
                    LCD_DrawRect(x + 14 * 4 + 21 * 6, y, 50, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }        

            case 49:
                al_index = 50;
                if (1) {
                    LCD_DrawImageSBPP1(x, y + 8, GYGTXGZ, YELLOW, BLACK); //高压柜通讯故障
                    LCD_DrawRect(x + 14 * 0 + 21 * 7, y, 50, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 50:
                al_index = 51;
                if (1) {
                    LCD_DrawImageSBPP1(x, y + 8, HDTXGZ, YELLOW, BLACK); //选档面板通讯故障
                    LCD_DrawRect(x + 14 * 0 + 21 * 6, y, 50, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
                
            case 51:
                al_index = 52;
                if (1) {
                    LCD_DrawImageSBPP1(x, y + 8, JYTXGZ, YELLOW, BLACK); //绝缘检测仪通讯故障
                    LCD_DrawRect(x + 14 * 0 + 21 * 6, y, 50, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
                
            case 52:
                al_index = 53;
                if (1) {
                    LCD_DrawImageSBPP1(x, y + 8, ABSTXGZ, YELLOW, BLACK); //ABS/EBS 通讯故障
                    LCD_DrawRect(x + 14 * 3 + 21 * 4, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
                
            case 53:
                al_index = 54;
                if (1) {
                    LCD_DrawImageSBPP1(x, y + 8, KTTXGZ, YELLOW, BLACK); //空调通讯故障
                    LCD_DrawRect(x + 14 * 0 + 21 * 6, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
                
            case 54:
                al_index = 55;
                if (1) {
                    LCD_DrawImageSBPP1(x, y + 8, TYTXGZ, YELLOW, BLACK); //胎压通讯故障
                    LCD_DrawRect(x + 14 * 0 + 21 * 6, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
                
            case 55:
                al_index = 56;
                if (1) {
                    LCD_DrawImageSBPP1(x, y + 8, YCTXGZ, YELLOW, BLACK); //远程控制设备通讯故障
                    LCD_DrawRect(x + 14 * 0 + 21 * 6, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }   
                
            case 56:
                al_index = 57;
                if (1) {
                    LCD_DrawImageSBPP1(x, y + 8, CSXHWX, YELLOW, BLACK); //车速信号无效
                    LCD_DrawRect(x + 14 * 0 + 21 * 6, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }    
                
            case 57:
                al_index = 58;
                if (1) {
                    LCD_DrawImageSBPP1(x, y + 8, CSWXXH, YELLOW, BLACK); //车速没有信号
                    LCD_DrawRect(x + 14 * 0 + 21 * 6, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }  
                
            case 58:
                al_index = 59;
                if (1) {
                    LCD_DrawImageSBPP1(x, y + 8, HDXTGZ, YELLOW, BLACK); //选挡传系统故障
                    LCD_DrawRect(x + 14 * 0 + 21 * 6, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }  
                
            case 59:
                al_index = 60;
                if (1) {
                    LCD_DrawImageSBPP1(x, y + 8, DJWDBJ, YELLOW, BLACK); //驱动电机温度报警
                    LCD_DrawRect(x + 14 * 0 + 21 * 6, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                } 
                
            case 60:
                al_index = 61;
                if (1) {
                    LCD_DrawImageSBPP1(x, y + 8, DJKZQWDBJ, YELLOW, BLACK); //驱动电机控制器温度报警
                    LCD_DrawRect(x + 14 * 0 + 21 * 9, y, 50, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                } 
                
            case 61:
                al_index = 62;
                if (1) {
                    LCD_DrawImageSBPP1(x, y + 8, DJMXGY, YELLOW, BLACK); //电机母线过压
                    LCD_DrawRect(x + 14 * 0 + 21 * 6, y, 50, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }   
                
            case 62:
                al_index = 63;
                if (1) {
                    LCD_DrawImageSBPP1(x, y + 8, DJMXQY, YELLOW, BLACK); //电机母线欠压
                    LCD_DrawRect(x + 14 * 0 + 21 * 6, y, 50, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }  
                
            case 63:
                al_index = 64;
                if (1) {
                    LCD_DrawImageSBPP1(x, y + 8, DJGDL, YELLOW, BLACK); //电机过电流
                    LCD_DrawRect(x + 14 * 0 + 21 * 5, y, 50, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }   
                
            case 64:
                al_index = 65;
                if (1) {
                    LCD_DrawImageSBPP1(x, y + 8, DJCS, YELLOW, BLACK); //电机超速
                    LCD_DrawRect(x + 14 * 0 + 21 * 4, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }   
                
            case 65:
                al_index = 66;
                if (1) {
                    LCD_DrawImageSBPP1(x, y + 8, DJDZ, YELLOW, BLACK); //电机堵转
                    LCD_DrawRect(x + 14 * 0 + 21 * 4, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                } 
                
            case 66:
                al_index = 67;
                if (1) {
                    LCD_DrawImageSBPP1(x, y + 8, XBXDX, YELLOW, BLACK); //旋变线断线
                    LCD_DrawRect(x + 14 * 0 + 21 * 5, y, 50, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                } 
                
            case 67:
                al_index = 68;
                if (1) {
                    LCD_DrawImageSBPP1(x, y + 8, XBXGZ, YELLOW, BLACK); //旋变值错误故障
                    LCD_DrawRect(x + 14 * 0 + 21 * 5, y, 50, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                } 
                
            case 68:
                al_index = 69;
                if (1) {
                    LCD_DrawImageSBPP1(x, y + 8, IGBTGZ, YELLOW, BLACK); //IGBT 故障
                    LCD_DrawRect(x + 14 * 4 + 21 * 2, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }      
                
            default:
                al_index = 0;
                LCD_DrawRect(x, y, 250, 36, BLACK); //清除显示区域
                break;
        }
    }

}
#endif
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

void updata_Dangwei(unsigned int x, unsigned int y) {
    unsigned char gear = 1;
    //gear = CAN_0x18EF4AEF.EV_Gear;
    if (CAN_0x18EF4AEF.EV_Gear == 0) gear = 0;
    else if (CAN_0x18EF4AEF.EV_Gear == 14) gear = 1;
    else if (CAN_0x18EF4AEF.EV_Gear == 13) gear = 2;
    else if (CAN_0x18EF4AEF.EV_Gear == 15) gear = 3;
    else gear = 0;
    LCD_DrawImage1BPP(x, y, BMP_DANGWEI[gear], GREEN, BLACK); //档位更新   0:N   1:D  2:R  3:P
}

void updata_SOC(unsigned int x, unsigned int y) {
    unsigned char color = WHITE;
    static unsigned char soc = 100;
    soc = CAN_0x18EF4CEF.BMS_SOC;
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
    DCDY = CAN_0x18EF4CEF.BMS_V;
    if (DCDY >= 800) DCDY = 800;
    print_SZ_1(x, y, DCDY, 3, 0, WHITE); //电池电压数值 x=120+72+30   y=150+60-2
    //if (frmID == 0)
    //    LCD_DrawRect(225 + 2, 150 + 5 + 2, DCDY * 3.31 * 0.125, 28, GREEN); // 331/100  
    //if (DCDY < 800 && frmID == 0)//当为100时会出错
    //    LCD_DrawRect((225 + 2 + DCDY * 3.31 * 0.125), 150 + 5 + 2, (331 - DCDY * 3.31 * 0.125), 28, BLACK);
}

void updata_DCDL(unsigned int x, unsigned int y) {
    unsigned int DCDL = 100;
    DCDL = CAN_0x18EF4CEF.BMS_A;
    if (DCDL < 1000) {
        DCDL = 1000 - DCDL;
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
        DCDL = DCDL - 1000;
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
    LCD_DrawRect(0, 430 + 5, 800, 2, GREEN); //底部横线   

    BMP_BUS(150, 150 + 40 - 5); //画BUS

    LCD_DrawImageSBPP(180, 150, 11, SOC, WHITE, BLACK); //SOC

    disp_rectange(225, 150 + 5 - 10, 335, 2, 32, 2, WHITE);
    for (i = 0; i < 3; i++)
        LCD_DrawRect(225 + 83 + 83 * i, 145 - 10, 2, 10, WHITE);

    LCD_DrawImage1BPP(225 - 4, 155 - 14 - 10, BMP_SZ[0], WHITE, BLACK); //0

    print_SZ(225 + 83 + 83 + 83 + 84 - 12, 155 - 14 - 10, 100, 3, 0, WHITE); //100
    LCD_DrawImage1BPP(650, 155, BMP_Baifenhao, WHITE, BLACK);

    LCD_DrawImage1BPP(10, 365 + 15 - 50 + 10 - 5, Bmp_Licheng, YELLOW, BLACK); //里程
    LCD_DrawImage1BPP(125, 318 + 15 + 36 + 8 - 5, BMP_HZ_KM, WHITE, BLACK); //单位 Km
    LCD_DrawImage1BPP(125, 318 + 15 + 36 * 2 + 8 - 5, BMP_HZ_KM, WHITE, BLACK); //单位 Km

    LCD_DrawImage1BPP(165, 365 + 15 - 50 + 10 - 5, BMP_DY, YELLOW, BLACK); //高压电池
    LCD_DrawImage1BPP(165, 365 + 15 - 50 + 10 - 5, BMP_Gao, YELLOW, BLACK);
    LCD_DrawImage1BPP(165 + 42, 365 + 15 - 50 + 10 - 5, BMP_DC, YELLOW, BLACK);
    LCD_DrawImage1BPP(265, 318 + 15 + 36 + 8 - 5, BMP_v, WHITE, BLACK); //V
    LCD_DrawImage1BPP(265, 318 + 15 + 36 * 2 + 8 - 5, BMP_a, WHITE, BLACK); //A

    LCD_DrawImageSBPP(295, 365 + 15 - 50 + 10 - 5, 21, DTDY, YELLOW, BLACK); //单体电压
    LCD_DrawImage1BPP(395, 318 + 15 + 36 + 8 - 5, BMP_v, WHITE, BLACK); //V
    LCD_DrawImage1BPP(395, 318 + 15 + 36 * 2 + 8 - 5, BMP_v, WHITE, BLACK); //V

    LCD_DrawImageSBPP(420, 365 + 15 - 50 + 10 - 5, 21, DTWD, YELLOW, BLACK); //单体温度
    LCD_DrawImage1BPP(420 + 90, 318 + 15 + 10 + 36 - 5, BMP_T, WHITE, BLACK); //℃
    LCD_DrawImage1BPP(420 + 90, 318 + 15 + 10 + 36 * 2 - 5, BMP_T, WHITE, BLACK); //℃

    LCD_DrawImage1BPP(540, 365 + 15 - 50 + 10 - 5, BMP_DJ, YELLOW, BLACK); //电机/控制器
    LCD_DrawImage1BPP(540 + 42, 365 + 15 - 50 + 10 - 5, BMP_I, YELLOW, BLACK);
    LCD_DrawImage1BPP(540 + 42 + 11, 365 + 15 - 50 + 10 - 5, BMP_KZQ, YELLOW, BLACK);
    LCD_DrawImage1BPP(640, 365 + 15 - 50 + 10 + 36 - 5, BMP_T, WHITE, BLACK); //℃
    LCD_DrawImage1BPP(640, 365 + 15 - 50 + 10 + 36 * 2 - 5, BMP_T, WHITE, BLACK); //℃

    LCD_DrawImageSBPP(670, 365 + 15 - 50 + 10 - 5, 42, DCSYDL, YELLOW, BLACK); //电池剩余电量
    LCD_DrawImage1BPP(670 + 100 - 11, 365 + 15 - 50 + 10 + 36 - 5, BMP_k, WHITE, BLACK); //kwh
    LCD_DrawImage1BPP(670 + 100, 365 + 15 - 50 + 10 + 36 - 5, BMP_w, WHITE, BLACK);
    LCD_DrawImage1BPP(670 + 100 + 11, 365 + 15 - 50 + 10 + 36 - 5, BMP_h, WHITE, BLACK);
    /*LCD_DrawImage1BPP(670, 365 + 15 - 50 + 10 - 5, BMP_DJ, YELLOW, BLACK); //电机
    LCD_DrawImage1BPP(670 + 42, 365 + 15 - 50 + 10 - 5, BMP_Zhuanju, YELLOW, BLACK); //转矩
    LCD_DrawImage1BPP(670 + 100, 365 + 15 - 50 + 10 + 36 - 5, BMP_n, WHITE, BLACK); //NM
    LCD_DrawImage1BPP(670 + 100 + 11, 365 + 15 - 50 + 10 + 36 - 5, BMP_m, WHITE, BLACK); //*/

    disp_rectange(5, 365 + 15 - 50 - 5, 150, 1, 111, 1, GREEN);
    disp_rectange(5 + 140 + 15, 365 + 15 - 50 - 5, 125, 1, 111, 1, GREEN);
    disp_rectange(5 + 270 + 15, 365 + 15 - 50 - 5, 125 - 5, 1, 111, 1, GREEN);
    disp_rectange(5 + 400 + 10, 365 + 15 - 50 - 5, 125 - 5, 1, 111, 1, GREEN);
    disp_rectange(5 + 530 + 5, 365 + 15 - 50 - 5, 125, 1, 111, 1, GREEN);
    disp_rectange(5 + 660 + 5, 365 + 15 - 50 - 5, 130 - 5, 1, 111, 1, GREEN);

}

void frmMain(void) {
    if (f_index == 0) { //只更新一次
        f_index = 1;
        mainFrame();
    } else if (f_index == 1) {
        f_index = 2;
        print_SZ_1(700, 318 + 15 + 36 - 5, CAN_0x18EF4CEF.EV_RestAhr, 3, 0, WHITE); //电池剩余电量
    } else if (f_index == 2) {
        f_index = 3;
        disp_BMP_baojing();
        print_SZ_1(305, 318 + 15 + 36 - 5, CAN_0x18EF4DEF.BAT_Max_Cell_Voltage * 2, 3, 2, WHITE); //单体高电压
        print_SZ_1(305, 318 + 15 + 36 * 2 - 5, CAN_0x18EF4DEF.BAT_Min_Cell_Voltage * 2, 3, 2, WHITE); //单体低电压
    } else if (f_index == 3) {
        f_index = 4;
        disp_miles(10, 318 - 5);
        //门开关图像报警
        if (LED2) {
            BMP_Men_Kai(150 + 195, 190 + 27 - 5, RED); //门2开
        } else
            BMP_Men_Guan(150 + 195, 190 + 27 - 5, WHITE); //门2关
        if (LED1)
            BMP_Men_Kai(150 + 184 + 215, 190 + 27 - 5, RED); //门1开
        else
            BMP_Men_Guan(150 + 184 + 215, 190 + 27 - 5, WHITE); //门1关        
    } else if (f_index == 4) {
        f_index = 5;
        disp_time(360, 440 + 4, timer);
        updata_DAT(540 + 50, 318 + 15 + 36 * 2 - 5, CAN_0x18EF4FEF.MCU_Control_Temp, 1, 40, WHITE, 3, 0); //电机控制器温度
        updata_DAT(540 + 50, 318 + 15 + 36 - 5, CAN_0x18EF4FEF.MCU_Temp, 1, 40, WHITE, 3, 0); //电机温度
    } else if (f_index == 5) {
        f_index = 6;
        updata_SOC(585, 155 - 10);
        updata_DAT(150 + 45, 318 + 15 + 36 - 5, CAN_0x18EF4CEF.BMS_V, 1, 0, WHITE, 4, 0); //总电压
        //updata_DAT(150 + 45, 318 + 15 + 38 * 2, BMS_A * 0.1, 1, 3200, WHITE, 4, 0); //总电流
        updata_DCDL(150 + 45 + 16, 318 + 15 + 36 * 2 - 5); //总电流
    } else if (f_index == 6) {
        f_index = 7;
        updata_DAT(410 + 50, 318 + 15 + 36 - 5, CAN_0x18EF4DEF.BAT_Max_Cell_Temperature, 1, 40, WHITE, 3, 0); //单体高温
        updata_DAT(410 + 50, 318 + 15 + 36 * 2 - 5, CAN_0x18EF4DEF.BAT_Min_Cell_Temperature, 1, 40, WHITE, 3, 0); //单体低温       
        //disp_FONT_baojing(2, 443);
        disp_FONT_baojingNew(2, 443);
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
            if ((CAN_0x18EF4AEF.EV_Gear == 2) && !R_flag) {//倒挡
                key_AV = 1; //模拟AV开关按一次
                AV_CH = 0; //0+1=1  倒车
                R_flag = 1; //防止一直进入这个函数，导致key_AV总是置1
            }
            if ((CAN_0x18EF4AEF.EV_Gear != 2) && R_flag) {
                key_AV = 1;
                AV_CH = 4; // 0 返回MCU界面
                R_flag = 0;
                M_flag = 0;
            }

            //中门选择使能按键 优先级小于倒车
            if (CAN_0x18EF4AEF.EV_Gear != 1) {
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
   
    print_SZ_2(750, 50, index, 1, 0, WHITE); // x/1
    LCD_DrawImage1BPP(750 + 11, 50, BMP_I, WHITE, BLACK);
    print_SZ_2(750 + 11 + 14, 50, 3, 1, 0, WHITE);

    LCD_DrawImageSBPP(130 + 200 + 200, 130 - 85 + 4, 11, CHAR_CAN, WHITE, BLACK); //CAN通讯
    LCD_DrawImage1BPP(130 + 200 + 200 + 11 + 11 + 11, 130 - 85 + 4, BMP_Tongxin, WHITE, BLACK);
    
    //版本号
    LCD_DrawImage1BPP(505 + 100, 75 + 8 + 25 * 15, BMP_Banben, WHITE, BLACK);
    LCD_DrawImage1BPP(505 + 100 + 42, 75 + 8 + 25 * 15, BMP_Hao, WHITE, BLACK);
    LCD_DrawImage1BPP(505 + 200, 75 + 25 * 15, BMP_V, WHITE, BLACK);

    if (index == 1) {
        LCD_DrawImageSBPP(130 + 200, 130 - 85, 50, IC_SYSTEM, WHITE, BLACK); //仪表            
        /***********************仪表开关量采集*********************************/
        /*************************第一列开关***********************************/
        /***********************仪表开关量采集**********************************/
        //IN1  左转向
        LCD_DrawImage1BPP(35, 75, BMP_IC_Zuo, WHITE, BLACK);
        LCD_DrawImage1BPP(35 + 21, 75, BMP_IC_Zhuanxiang, WHITE, BLACK);
        //IN2
        //IN3  中门开状态
        LCD_DrawImageSBPP(35, 75 + 25 * 2, 21, ZMKXH, WHITE, BLACK);
        //IN4  前门开状态
        LCD_DrawImageSBPP(35, 75 + 25 * 3, 21, QMKXH, WHITE, BLACK);
        //IN5  右转向
        LCD_DrawImage1BPP(35, 75 + 25 * 4, BMP_IC_You, WHITE, BLACK);
        LCD_DrawImage1BPP(35 + 21, 75 + 25 * 4, BMP_IC_Zhuanxiang, WHITE, BLACK);
        //IN6
        //IN7
        //IN8
        //IN9  前雾灯
        LCD_DrawImageSBPP(35, 75 + 25 * 8, 21, QWDKG, WHITE, BLACK);
        //IN10 后雾灯
        LCD_DrawImageSBPP(35, 75 + 25 * 9, 21, HWDKG, WHITE, BLACK);
        //IN11
        //IN12
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
        LCD_DrawImage1BPP(285, 75 + 25 * 1, BMP_IC_Siji, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 42, 75 + 25 * 1, BMP_Fengshan, WHITE, BLACK);
        //IN19 路牌开关
        LCD_DrawImage1BPP(285, 75 + 25 * 2, BMP_Lupai, WHITE, BLACK);
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
            } else if (i == 2) {
                LCD_DrawImage1BPP(285 + 42, 75 + 25 * i, BMP_IC_Kaiguan, WHITE, BLACK);
            } else if (i == 1 || i == 4 || i == 10)
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
        //IN39 ACC唤醒开关
        LCD_DrawImage1BPP(535, 75 + 25 * 6, BMP_a, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 11, 75 + 25 * 6, BMP_c, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 11 + 11, 75 + 25 * 6, BMP_c, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 11 + 11 + 11, 75 + 25 * 6, BMP_Huanxing, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 11 + 11 + 11 + 42, 75 + 25 * 6, BMP_IC_Kaiguan, WHITE, BLACK);
        //IN40 钥匙ON开关
        LCD_DrawImage1BPP(535, 75 + 25 * 7, BMP_o, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 11, 75 + 25 * 7, BMP_n, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 11 + 11, 75 + 25 * 7, BMP_Dang, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 11 + 11 + 21, 75 + 25 * 7, BMP_Huanxing, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 11 + 11 + 63, 75 + 25 * 7, BMP_IC_Kaiguan, WHITE, BLACK);

        LCD_DrawImage1BPP(535, 75 + 25 * 8, BMP_IC_Qian, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 21, 75 + 25 * 8, BMP_Qiya, WHITE, BLACK);

        LCD_DrawImage1BPP(535, 75 + 25 * 9, BMP_IC_Hou, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 21, 75 + 25 * 9, BMP_Qiya, WHITE, BLACK);

        for (i = 8; i < 14; i++) {
            if (i > 9)
                LCD_DrawImage1BPP(535 + 21, 75 + 25 * i, BMP_Beiyong, WHITE, BLACK);
            LCD_DrawImage1BPP(535 + 63, 75 + 25 * i, BMP_Xinhao, WHITE, BLACK);
            LCD_DrawImage1BPP(535 + 63 + 42 + 16 * 4 - 4, 75 + 25 * i, BMP_Omu, WHITE, BLACK); //Ω
            LCD_DrawImage1BPP(535 + 63 + 42 + 16 * 4 + 16 * 5, 75 + 25 * i, BMP_v, WHITE, BLACK); //V
        }

    } else if (index == 2) {
        print_SZ_2(750, 50, 2, 1, 0, WHITE); // 2/3
        LCD_DrawImage1BPP(750 + 11, 50, BMP_I, WHITE, BLACK);
        print_SZ_2(750 + 11 + 14, 50, 3, 1, 0, WHITE);

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
        LCD_DrawImageSBPP(60, 75 + 25 * 3, 21, ZQWDSC, WHITE, BLACK);
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
        //OUT10 右前雾灯
        LCD_DrawImageSBPP(60, 75 + 25 * 9, 21, YQWDSC, WHITE, BLACK);
        //OUT11 右远光灯
        LCD_DrawImageSBPP(60, 75 + 25 * 10, 21, YYGDSC, WHITE, BLACK);
        //OUT12 电池舱风扇
        LCD_DrawImage1BPP(60, 75 + 25 * 11, BMP_DC, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 11, BMP_Cangmen, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42 + 21, 75 + 25 * 11, BMP_Fengshan, WHITE, BLACK);
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
            if (i == 3 || i == 5 || i == 6 || i == 8 || i == 9 || i == 10 || i == 12 || i == 14)
                LCD_DrawImage1BPP(60 + 63, 75 + 25 * i, BMP_IC_Deng, WHITE, BLACK);
            else if (i == 13)
                LCD_DrawImage1BPP(60 + 42, 75 + 25 * i, BMP_IC_Deng, WHITE, BLACK);
        }
        /***********************前模块开关采集*********************************/
        //KL1  左后摩擦片报警
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 0, BMP_IC_Zuo, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 21, 75 + 25 * 0, BMP_IC_Hou, WHITE, BLACK);
        //KL2  驻车制动开关
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 1, BMP_Zhuche, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 1, BMP_Zhidong, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42 + 42, 75 + 25 * 1, BMP_IC_Kaiguan, WHITE, BLACK);
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
        //KL6  制动灯开关
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 5, BMP_Zhidong, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 5, BMP_IC_Deng, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 63, 75 + 25 * 5, BMP_IC_Kaiguan, WHITE, BLACK);
        //KL7  安全带开关
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 6, BMP_Anquandai, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 63, 75 + 25 * 6, BMP_IC_Kaiguan, WHITE, BLACK);
        //KL8  日行灯开关       
        //KL9 前气压报警开关
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 8, BMP_IC_Qian, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 21, 75 + 25 * 8, BMP_Qiya, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 63, 75 + 25 * 8, BMP_Baojing, WHITE, BLACK);
        //KL10 后视镜加热开关
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 9, BMP_IC_Hou, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 21, 75 + 25 * 9, BMP_Shijing, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 63, 75 + 25 * 9, BMP_Jiare, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 105, 75 + 25 * 9, BMP_IC_Kaiguan, WHITE, BLACK);
        //KL11 后气压报警开关
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 10, BMP_IC_Hou, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 21, 75 + 25 * 10, BMP_Qiya, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 63, 75 + 25 * 10, BMP_Baojing, WHITE, BLACK);
        //KL12
        //KL13 地址选择1
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 12, BMP_Dizhi, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 12, BMP_Xuanze, WHITE, BLACK);
        print_SZ_2(285 + 150 + 84 + 6, 75 + 25 * 12, 1, 1, 0, WHITE);
        //KL14 地址选择2
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 13, BMP_Dizhi, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 13, BMP_Xuanze, WHITE, BLACK);
        print_SZ_2(285 + 150 + 84 + 6, 75 + 25 * 13, 2, 1, 0, WHITE);
        //KL15 门铃开关
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 14, BMP_Men, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 21, 75 + 25 * 14, BMP_Ling, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 14, BMP_IC_Kaiguan, WHITE, BLACK);
        //KH1
    } else if (index == 3) {
        print_SZ_2(750, 50, 3, 1, 0, WHITE); // 3/3
        LCD_DrawImage1BPP(750 + 11, 50, BMP_I, WHITE, BLACK);
        print_SZ_2(750 + 11 + 14, 50, 3, 1, 0, WHITE);

        LCD_DrawImage1BPP(130 + 200, 130 - 85, BMP_DING, WHITE, BLACK); //顶
        LCD_DrawImage1BPP(130 + 200 + 25, 130 - 85, BMP_MOKUAI, WHITE, BLACK); //模块
        LCD_DrawImage1BPP(130 + 200 + 25 + 50, 130 - 85, BMP_Message, WHITE, BLACK); //信息
        for (i = 0; i < 15; i++) {
            LCD_DrawImage1BPP(60 + 280, 75 + 25 * i, BMP_a, WHITE, BLACK);
            //LCD_DrawRect(0, 74 +25+ 25 * i, 800, 1, GRAY); //横线
        }

        /*********************顶模块输出***************************************/
        //OUT1  前路牌电源
        LCD_DrawImage1BPP(60, 75 + 25 * 0, BMP_IC_Qian, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 0, BMP_Lupai, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 63, 75 + 25 * 0, BMP_Dianyuan, WHITE, BLACK);
        //OUT2  厢灯2
        LCD_DrawImage1BPP(60, 75 + 25 * 1, BMP_Dengxiang, WHITE, BLACK);
        print_SZ_2(60 + 42 + 6, 75 + 25 * 1, 2, 1, 0, WHITE);
        //OUT3  前门踏步灯
        LCD_DrawImage1BPP(60, 75 + 25 * 2, BMP_IC_Qian, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 2, BMP_Men, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 2, BMP_Taban, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 84, 75 + 25 * 2, BMP_IC_Deng, WHITE, BLACK);
        //OUT4  制动灯
        LCD_DrawImage1BPP(60, 75 + 25 * 3, BMP_Zhidong, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 3, BMP_IC_Deng, WHITE, BLACK);
        //OUT5  中门踏步灯
        LCD_DrawImage1BPP(60, 75 + 25 * 4, BMP_Zhong, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 4, BMP_Men, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 4, BMP_Taban, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 84, 75 + 25 * 4, BMP_IC_Deng, WHITE, BLACK);
        //OUT6  后路牌电源
        LCD_DrawImage1BPP(60, 75 + 25 * 5, BMP_IC_Hou, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 5, BMP_Lupai, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 63, 75 + 25 * 5, BMP_Dianyuan, WHITE, BLACK);
        //OUT7  后视镜加热
        LCD_DrawImage1BPP(60, 75 + 25 * 6, BMP_IC_Hou, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 6, BMP_Shijing, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 63, 75 + 25 * 6, BMP_Jiare, WHITE, BLACK);
        //OUT8  后雾灯
        LCD_DrawImageSBPP(60, 75 + 25 * 7, 21, HWDSC, WHITE, BLACK);
        //OUT9  侧路牌
        LCD_DrawImage1BPP(60, 75 + 25 * 8, BMP_Ce, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 8, BMP_Lupai, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 63, 75 + 25 * 8, BMP_Dianyuan, WHITE, BLACK);
        //OUT10 司机风扇
        LCD_DrawImage1BPP(60, 75 + 25 * 9, BMP_IC_Siji, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 9, BMP_Fengshan, WHITE, BLACK);
        //OUT11 滚动屏电源
        LCD_DrawImage1BPP(60, 75 + 25 * 10, BMP_Gundongping, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 63, 75 + 25 * 10, BMP_Dianyuan, WHITE, BLACK);
        //OUT12 司机灯电源
        LCD_DrawImage1BPP(60, 75 + 25 * 11, BMP_IC_Siji, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 11, BMP_IC_Deng, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 63, 75 + 25 * 11, BMP_Dianyuan, WHITE, BLACK);
        //OUT13 倒车灯
        LCD_DrawImage1BPP(60, 75 + 25 * 12, BMP_Daoche, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 12, BMP_IC_Deng, WHITE, BLACK);
        //OUT14 门泵电源       
        LCD_DrawImage1BPP(60, 75 + 25 * 13, BMP_Qibeng, WHITE, BLACK);
        LCD_DrawImage1BPP(60, 75 + 25 * 13, BMP_Men, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 13, BMP_Dianyuan, WHITE, BLACK);
        //OUT15 厢灯1
        LCD_DrawImage1BPP(60, 75 + 25 * 14, BMP_Dengxiang, WHITE, BLACK);
        print_SZ_2(60 + 42 + 6, 75 + 25 * 14, 1, 1, 0, WHITE);

        /************************顶模块开关*********************************/
        //KL1
        //KL2  门铃开关
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 1, BMP_Men, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 21, 75 + 25 * 1, BMP_Ling, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 1, BMP_IC_Kaiguan, WHITE, BLACK);
        //KL3
        //KL4  前门应急阀报警
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 3, BMP_IC_Qian, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 21, 75 + 25 * 3, BMP_Men, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 3, BMP_Yingjifa, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 105, 75 + 25 * 3, BMP_Baojing, WHITE, BLACK);
        //print_SZ_2(285 + 150 + 105 + 42 + 6, 75 + 25 * 3, 2, 1, 0, WHITE);
        //KL5
        //KL6  中门应急阀报警
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 5, BMP_Zhong, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 21, 75 + 25 * 5, BMP_Men, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 5, BMP_Yingjifa, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 105, 75 + 25 * 5, BMP_Baojing, WHITE, BLACK);
        //print_SZ_2(285 + 150 + 105 + 42 + 6, 75 + 25 * 5, 2, 1, 0, WHITE);
        //KL7
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
        //KH1  后舱门开关
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 15, BMP_IC_Hou, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 21, 75 + 25 * 15, BMP_Cangmen, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 63, 75 + 25 * 15, BMP_IC_Kaiguan, WHITE, BLACK);

    } else if (index == 4) {

        LCD_DrawImage1BPP(130 + 200, 130 - 85, BMP_HOU, WHITE, BLACK); //后
        LCD_DrawImage1BPP(130 + 200 + 25, 130 - 85, BMP_MOKUAI, WHITE, BLACK); //模块
        LCD_DrawImage1BPP(130 + 200 + 25 + 50, 130 - 85, BMP_Message, WHITE, BLACK); //信息
        for (i = 0; i < 15; i++) {
            LCD_DrawImage1BPP(60 + 280, 75 + 3 + 25 * i, BMP_a, WHITE, BLACK);
            //LCD_DrawRect(0, 74 +25+ 25 * i, 800, 1, GRAY); //横线
        }
        /*********************后模块输出***************************************/
        //OUT1  倒车灯
        LCD_DrawImageSBPP(60, 75 + 25 * 0, 42, DCD, WHITE, BLACK);
        //OUT2  位置灯
        LCD_DrawImage1BPP(60, 75 + 25 * 1, BMP_Weizhi, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 1, BMP_IC_Deng, WHITE, BLACK);
        //OUT3  电源开关
        LCD_DrawImageSBPP(60, 75 + 25 * 2, 42, DYKG, WHITE, BLACK);
        //OUT4  前门灯输出
        LCD_DrawImageSBPP(60, 75 + 25 * 3, 21, QMDSC, WHITE, BLACK);
        //OUT5  中门灯输出
        LCD_DrawImageSBPP(60, 75 + 25 * 4, 21, ZMDSC, WHITE, BLACK);
        //OUT6  左转向灯
        LCD_DrawImage1BPP(60, 75 + 25 * 5, BMP_IC_Zuo, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 5, BMP_IC_Zhuanxiang, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 63, 75 + 25 * 5, BMP_IC_Deng, WHITE, BLACK);
        //OUT7  右转向灯
        LCD_DrawImage1BPP(60, 75 + 25 * 6, BMP_IC_You, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 6, BMP_IC_Zhuanxiang, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 63, 75 + 25 * 6, BMP_IC_Deng, WHITE, BLACK);
        //OUT8  后雾灯
        LCD_DrawImageSBPP(60, 75 + 25 * 7, 21, HWDSC, WHITE, BLACK);
        //OUT9  干燥器
        LCD_DrawImageSBPP(60, 75 + 25 * 8, 21, GZQ, WHITE, BLACK);
        //OUT10 空调
        LCD_DrawImage1BPP(60, 75 + 25 * 9, BMP_Kongtiao, WHITE, BLACK);
        //OUT11 制动灯
        LCD_DrawImageSBPP(60, 75 + 25 * 10, 42, ZDDSC, WHITE, BLACK);
        //OUT12 风扇输出
        LCD_DrawImageSBPP(60, 75 + 25 * 11, 42, FSSC, WHITE, BLACK);
        //OUT13 广告输出1
        LCD_DrawImageSBPP(60, 75 + 25 * 12, 42, GGSC1, WHITE, BLACK);
        //OUT14 广告输出2
        LCD_DrawImageSBPP(60, 75 + 25 * 13, 42, GGSC2, WHITE, BLACK);
        //OUT15 报站器
        LCD_DrawImage1BPP(60, 75 + 25 * 14, BMP_Baozhanqi, WHITE, BLACK);

        /*********************后模块开关***************************************/
        //KL1  
        //KL2  
        //KL3  
        //KL4  驻车制动开关
        LCD_DrawImageSBPP(285 + 150, 75 + 25 * 3, 42, ZCZDKG, WHITE, BLACK);
        //KL5  燃油水位报警
        LCD_DrawImageSBPP(285 + 150, 75 + 25 * 4, 42, RYSWBJ, WHITE, BLACK);
        //KL6  电机水位报警
        LCD_DrawImageSBPP(285 + 150, 75 + 25 * 5, 42, DJSWBJ, WHITE, BLACK);
        //KL7
        //KL8  左前摩擦片报警
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 7, BMP_IC_Zuo, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 21, 75 + 25 * 7, BMP_IC_Qian, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 7, BMP_Mocapian, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 105, 75 + 25 * 7, BMP_Baojing, WHITE, BLACK);
        //KL9  右前摩擦片报警
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 8, BMP_IC_You, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 21, 75 + 25 * 8, BMP_IC_Qian, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 8, BMP_Mocapian, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 105, 75 + 25 * 8, BMP_Baojing, WHITE, BLACK);
        //KL10 左后摩擦片报警
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 9, BMP_IC_Zuo, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 21, 75 + 25 * 9, BMP_IC_Hou, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 9, BMP_Mocapian, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 105, 75 + 25 * 9, BMP_Baojing, WHITE, BLACK);
        //KL11 右后摩擦片报警
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 10, BMP_IC_You, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 21, 75 + 25 * 10, BMP_IC_Hou, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 10, BMP_Mocapian, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 105, 75 + 25 * 10, BMP_Baojing, WHITE, BLACK);
        //KL13 地址选择1
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 12, BMP_Dizhi, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 12, BMP_Xuanze, WHITE, BLACK);
        print_SZ_2(285 + 150 + 84 + 6, 75 + 25 * 12, 1, 1, 0, WHITE);
        //KL14 地址选择2
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 13, BMP_Dizhi, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 13, BMP_Xuanze, WHITE, BLACK);
        print_SZ_2(285 + 150 + 84 + 6, 75 + 25 * 13, 2, 1, 0, WHITE);

        LCD_DrawImage1BPP(505 + 100, 75 + 8 + 25 * 15, BMP_Banben, WHITE, BLACK);
        LCD_DrawImage1BPP(505 + 100 + 42, 75 + 8 + 25 * 15, BMP_Hao, WHITE, BLACK);
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
            /*if (i == 3 || i == 1 || i == 2)*/
            //{
            if ((dump & 0x01) == 0x01) {//为控火开关
                LCD_DrawImage1BPP(5, 75 + 25 * i, Bmpflag[0], WHITE, BLACK);
            } else {
                LCD_DrawImage1BPP(5, 75 + 25 * i, Bmpflag[1], GREEN, BLACK);
            }
            //} 
            /*else if ((dump & 0x01) == 0x01) {
            LCD_DrawImage1BPP(5, 75 + 25 * i, Bmpflag[1], GREEN, BLACK);
        } else {
            LCD_DrawImage1BPP(5, 75 + 25 * i, Bmpflag[0], WHITE, BLACK);
        }*/
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
        if (index_IC == 4) {
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

    LCD_DrawImageSBPP(130, 130 + 35, 50, AIR_SYSTEM, color, BLACK); //气泵

    LCD_DrawImage1BPP(130, 130 + 35 + 35, BMP_DCDC, color, BLACK); //DCDC
    LCD_DrawImage1BPP(130 + 65, 130 + 35 + 35, BMP_STSTEM, color, BLACK); //系统
    LCD_DrawImage1BPP(130 + 65 + 50, 130 + 35 + 35, BMP_Message, color, BLACK); //信息

    LCD_DrawImageSBPP(130, 130 + 35 + 35 + 35, 50, OIL_SYSTEM, color, BLACK); //油泵

    LCD_DrawImageSBPP(130 + 350, 130, 50, BMS_SYSTEM, color, BLACK); //电池

    //LCD_DrawImageSBPP(130 + 350, 130 + 35,50, Battery_SYSTEM, color, BLACK); //电池   

    //LCD_DrawImageSBPP(130 + 350, 130 + 35 + 35, 50,HV_SYSTEM, color, BLACK); //高压  

    LCD_DrawImageSBPP(130 + 350, 130 + 35, 50, IC_SYSTEM, color, BLACK); //仪表

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

    if (i == 12) i = 6;
    if (i == 0) i = 6;
    //子菜单间切换
    if (i == 6) {
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
    if (i == 7 || i == 1) {
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
    if (i == 8 || i == 2) {
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
    if (i == 9 || i == 3) {
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
    if (i == 10 || i == 4) {
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
    if (i == 11 || i == 5) {
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
    LCD_DrawImage1BPP(105 + 350, 131 + 1 * 35, BMP_Choose, color, BLACK);
    /*if (i == 13 || i == 6) {
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
    if (i == 14 || i == 7) {
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
        disp_FONT_baojingNew(2, 440);
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
        LCD_DrawImageSBPP1(82, 100 + 38 * 0, DJZS, WHITE, BLACK); //电机转速
        LCD_DrawImage1BPP(400 - 24 - 24, 100 + 38 * 0, BMP_RPM, WHITE, BLACK); //RPM
        
        LCD_DrawImageSBPP(82, 100 + 38 * 1, 42, DJZJ, WHITE, BLACK); //电机转矩
        LCD_DrawImageSBPP(400 - 24 - 24, 100 + 38 * 1, 11, NM, WHITE, BLACK); //NM

        LCD_DrawImageSBPP(82, 100 + 38 * 2, 42, DJSRDY, WHITE, BLACK); //电机输入电压
        LCD_DrawImage1BPP(400 - 24, 100 + 38 * 2, BMP_v, WHITE, BLACK); //V
        
        LCD_DrawImageSBPP(82, 100 + 38 * 3, 42, DJSRDL, WHITE, BLACK); //电机输入电流
        LCD_DrawImage1BPP(400 - 24, 100 + 38 * 3, BMP_a, WHITE, BLACK); //V

        LCD_DrawImageSBPP(82, 100 + 38 * 4, 42, DJWD, WHITE, BLACK); //电机温度
        LCD_DrawImage1BPP(400 - 28, 100 + 38 * 4, BMP_T, WHITE, BLACK); //℃

        LCD_DrawImageSBPP(82, 100 + 38 * 5, 63, KZQWD, WHITE, BLACK); //控制器温度
        LCD_DrawImage1BPP(400 - 28, 100 + 38 * 5, BMP_T, WHITE, BLACK); //℃

        LCD_DrawImageSBPP(82, 100 + 38 * 6, 21, DWMS, WHITE, BLACK); //档位模式
        
        LCD_DrawImageSBPP(82, 100 + 38 * 7, 21, DWXX, WHITE, BLACK); //档位信息

        LCD_DrawImage1BPP(82, 100 + 38 * 8, BMP_Chesu, WHITE, BLACK); //车速
        LCD_DrawImage1BPP(400 - 48, 100 + 38 * 8, Bmp_kmh, WHITE, BLACK);
        
        LCD_DrawImageSBPP(82, 100 + 38 * 9, 42, SCZS, WHITE, BLACK); //输出转速
        LCD_DrawImage1BPP(400 - 24 - 24, 100 + 38 * 9, BMP_RPM, WHITE, BLACK); //RPM

        /*LCD_DrawImage1BPP(82, 100 + 38 * 6, BMP_Xu, WHITE, BLACK); //蓄电池电压
        LCD_DrawImage1BPP(82 + 21, 100 + 38 * 6, BMP_DC, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 21 + 42, 100 + 38 * 6, BMP_DY, WHITE, BLACK); //
        LCD_DrawImage1BPP(400 - 24, 100 + 38 * 6, BMP_v, WHITE, BLACK); //%*/
        //LCD_DrawImageSBPP(82, 100 + 38 * 7, 42, HZBJGZ, WHITE, BLACK); //火灾报警故障
       
        LCD_DrawImageSBPP1(82 + 320, 100 + 38 * 0, SBKZZL, WHITE, BLACK);

        LCD_DrawImageSBPP1(82 + 320, 100 + 38 * 1, FSKZZL, WHITE, BLACK);

        LCD_DrawImageSBPP1(82 + 320, 100 + 38 * 2, BMSKZZL, WHITE, BLACK);

        LCD_DrawImageSBPP1(82 + 320, 100 + 38 * 3, MCUKZZL, WHITE, BLACK);

        LCD_DrawImageSBPP1(82 + 320, 100 + 38 * 4, ZFKZZL, WHITE, BLACK);

        LCD_DrawImageSBPP1(82 + 320, 100 + 38 * 5, ZZKZZL, WHITE, BLACK);
        
        LCD_DrawImageSBPP1(82 + 320, 100 + 38 * 6, FJKZZL, WHITE, BLACK);
        
        LCD_DrawImageSBPP1(82 + 320, 100 + 38 * 7, KTKZZL, WHITE, BLACK);
        
        LCD_DrawImageSBPP1(82 + 320, 100 + 38 * 8, NFKZZL, WHITE, BLACK);
        
        LCD_DrawImageSBPP(82 + 320, 100 + 38 * 9, 42, XDKZKG, WHITE, BLACK);
             
        /*
        LCD_DrawImageSBPP(82, 100,42, ZCZT, WHITE, BLACK); //整车状态

        LCD_DrawImageSBPP(82, 100 + 38,42, XTHSZT, WHITE, BLACK); //系统互锁状态

        LCD_DrawImageSBPP(82, 100 + 38 * 2, 42, DJXTZT, WHITE, BLACK); //电机系统状态

        LCD_DrawImageSBPP(82, 100 + 38 * 3, 21, ZZJCQ, WHITE, BLACK); //主正接触器状态
        LCD_DrawImage1BPP(82 + 42 + 63, 100 + 38 * 3, BMP_Zhuangtai, WHITE, BLACK);

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

        LCD_DrawImageSBPP(82, 100 + 38 * 7, 11, ABSXH, WHITE, BLACK); //ABS信号

        LCD_DrawImage1BPP(82, 100 + 38 * 8, BMP_Xuhang, WHITE, BLACK); //续航里程
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 8, Bmp_Licheng, WHITE, BLACK);
        LCD_DrawImage1BPP(400 - 36, 100 + 38 * 8, BMP_HZ_KM, WHITE, BLACK);

        LCD_DrawImage1BPP(82, 100 + 38 * 9, BMP_Shunshi, WHITE, BLACK); //瞬时电耗
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

        LCD_DrawImageSBPP(82 + 320, 100 + 38 * 3, 42, DJZSXH, WHITE, BLACK); //电机转速信号

        LCD_DrawImageSBPP(82 + 320, 100 + 38 * 4, 42, DJZZXH, WHITE, BLACK); //电机转矩信号

        LCD_DrawImage1BPP(82 + 320, 100 + 38 * 5, BMP_Youmen, WHITE, BLACK); //油门
        LCD_DrawImage1BPP(82 + 42 + 320, 100 + 38 * 5, BMP_Taban, WHITE, BLACK); //踏板
        LCD_DrawImage1BPP(720 - 24, 100 + 38 * 5, BMP_Baifenhao, WHITE, BLACK); //%

        LCD_DrawImage1BPP(82 + 320, 100 + 38 * 6, BMP_Zhidong, WHITE, BLACK); //制动
        LCD_DrawImage1BPP(82 + 42 + 320, 100 + 38 * 6, BMP_Taban, WHITE, BLACK); //踏板
        LCD_DrawImage1BPP(720 - 24, 100 + 38 * 6, BMP_Baifenhao, WHITE, BLACK); //%
        
        LCD_DrawImage1BPP(82 + 320, 100 + 38 * 7, BMP_Xu, WHITE, BLACK); //蓄电池电压
        LCD_DrawImage1BPP(82 + 21 + 320, 100 + 38 * 7, BMP_DC, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 21 + 42 + 320, 100 + 38 * 7, BMP_DY, WHITE, BLACK); //
        LCD_DrawImage1BPP(720 - 24, 100 + 38 * 7, BMP_v, WHITE, BLACK); //%
         */
    } else if (index == 2) {
        LCD_DrawImageSBPP1(82, 100 + 38 * 0,YBKZZL, WHITE, BLACK); //油泵控制指令

        LCD_DrawImageSBPP1(82, 100 + 38 * 1,QBKZZL, WHITE, BLACK); //

        LCD_DrawImageSBPP1(82, 100 + 38 * 2,DCDCKZZL, WHITE, BLACK);
        //LCD_DrawImageSBPP(82 + 44, 100 + 38 * 2, 42, KZZL, WHITE, BLACK);

        LCD_DrawImageSBPP1(82, 100 + 38 * 3, SHYKZZL, WHITE, BLACK);

        LCD_DrawImageSBPP(82, 100 + 38 * 4, 21, GYJCQZT, WHITE, BLACK);
        
        LCD_DrawImageSBPP1(82, 100 + 38 * 5, ZFJCQZT, WHITE, BLACK);

        LCD_DrawImageSBPP1(82, 100 + 38 * 6, CDJCQZT, WHITE, BLACK);
        
        LCD_DrawImageSBPP1(82, 100 + 38 * 7, KTJCQZT, WHITE, BLACK);
        
        LCD_DrawImageSBPP1(82, 100 + 38 * 8, NFJCQZT, WHITE, BLACK);

        LCD_DrawImage1BPP(82, 100 + 38 * 9, BMP_KZQ, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 63, 100 + 38 * 9, BMP_i, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 63 + 11, 100 + 38 * 9, BMP_o, WHITE, BLACK);
        LCD_DrawImageSBPP(82 + 63 + 11 + 11, 100 + 38 * 9, 42, SRZT, WHITE, BLACK);

        
        LCD_DrawImageSBPP1(82 + 320 + 80, 100 + 38 * 0, VCUXTGZDM, YELLOW, BLACK); //VCU系统故障

        LCD_DrawImageSBPP(82 + 82 + 320 + 63 - 30, 100 + 38 * 1, 11, CHAR_SPN, YELLOW, BLACK); //SPN

        LCD_DrawImageSBPP(82 + 82 + 320 + 63 + 105 - 30, 100 + 38 * 1, 11, CHAR_FMI, YELLOW, BLACK); //SPN
        
        LCD_DrawImageSBPP1(82 + 320 + 80, 100 + 38 * 6, XXJCZL, YELLOW, BLACK); //下线检测指令
        
        LCD_DrawImageSBPP(82 + 320, 100 + 38 * 7, 42, ZDTBZT, WHITE, BLACK); //制动踏板状态
        LCD_DrawImage1BPP(400 + 320 - 28, 100 + 38 * 7, BMP_Baifenhao, WHITE, BLACK); //%
        LCD_DrawImageSBPP(82 + 320, 100 + 38 * 8, 42, JSTBZT, WHITE, BLACK); //加速踏板状态
        LCD_DrawImage1BPP(400 + 320 - 28, 100 + 38 * 8, BMP_Baifenhao, WHITE, BLACK); //%

        LCD_DrawImage1BPP(82 + 320, 100 + 38 * 9, BMP_Jueyuan, WHITE, BLACK); //绝缘
        LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 9, BMP_DC, WHITE, BLACK); //电池
        LCD_DrawImage1BPP(82 + 320 + 42 + 21, 100 + 38 * 9, BMP_Zu, WHITE, BLACK); //阻
        LCD_DrawImage1BPP(400 + 320 - 28, 100 + 38 * 9, BMP_k, WHITE, BLACK); //K
        LCD_DrawImage1BPP(400 + 320 - 16, 100 + 2 + 38 * 9, BMP_Omu, WHITE, BLACK); //Ω 
        /* LCD_DrawImage1BPP(82, 100 + 38 * 0, BMP_DJ, WHITE, BLACK); //电机
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
        LCD_DrawImageSBPP(82 + 320, 100 + 38 * 6, 42, DJKZQWDXHZT, WHITE, BLACK); //加速踏板状态  
         */
    } else if (index == 3) {
        /* LCD_DrawImageSBPP(82 + 320, 100 + 38 * 0, 42, DJGZ, WHITE, BLACK); //电机故障

        LCD_DrawImageSBPP(82 + 320, 100 + 38 * 1, 11, MCU, WHITE, BLACK); //MCU通讯故障
        LCD_DrawImage1BPP(82 + 320 + 11 + 11 + 11, 100 + 38 * 1, BMP_Tongxin, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 320 + 11 + 11 + 11 + 42, 100 + 38 * 1, BMP_Guzhang, WHITE, BLACK);

        LCD_DrawImageSBPP(82 + 320, 100 + 38 * 2, 42, DLDCGZ, WHITE, BLACK); //动力电池故障

        LCD_DrawImageSBPP(82 + 320, 100 + 38 * 3, 11, BMS, WHITE, BLACK); //BMS通讯故障
        LCD_DrawImage1BPP(82 + 320 + 11 + 11 + 11, 100 + 38 * 3, BMP_Tongxin, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 320 + 11 + 11 + 11 + 42, 100 + 38 * 3, BMP_Guzhang, WHITE, BLACK);

        LCD_DrawImageSBPP(82 + 320, 100 + 38 * 4, 63, BSXGZ, WHITE, BLACK); //变速箱故障

        LCD_DrawImage1BPP(82 + 320, 100 + 38 * 5, BMP_DCDC, WHITE, BLACK); //DCDC系统故障
        LCD_DrawImage1BPP(82 + 320 + 65, 100 + 38 * 5, BMP_System, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 320 + 65 + 42, 100 + 38 * 5, BMP_Guzhang, WHITE, BLACK);

        LCD_DrawImage1BPP(82 + 320, 100 + 38 * 6, BMP_IC_Zhuanxiang, WHITE, BLACK); //转向DCAC故障       
        LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 6 - 2, BMP_DCAC, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 320 + 52 + 42, 100 + 38 * 6, BMP_Guzhang, WHITE, BLACK);

        LCD_DrawImage1BPP(82 + 320, 100 + 38 * 7, BMP_Zhidong, WHITE, BLACK); //制动DCAC故障       
        LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 7 - 2, BMP_DCAC, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 320 + 52 + 42, 100 + 38 * 7, BMP_Guzhang, WHITE, BLACK);

        LCD_DrawImageSBPP(82 + 320, 100 + 38 * 8, 42, YMTBGZ, WHITE, BLACK); //油门踏板故障

        LCD_DrawImageSBPP1(82 + 320, 100 + 38 * 9, ZDTBGZ, WHITE, BLACK); //制动踏板故障 */
        /*LCD_DrawImage1BPP(82, 100 - 2 + 38 * 0, BMP_DCDC, WHITE, BLACK);//DCDC保险状态
        LCD_DrawImageSBPP(82 + 65, 100 + 38 * 0, 42, BXZT, WHITE, BLACK); 

        LCD_DrawImage1BPP(82, 100 + 38 * 1, BMP_Kongtiao, WHITE, BLACK);//空调保险状态
        LCD_DrawImageSBPP(82 + 42, 100 + 38 * 1, 42, BXZT, WHITE, BLACK);
        
        LCD_DrawImage1BPP(82, 100 + 38 * 2, BMP_Chushuang, WHITE, BLACK);//除霜保险状态
        LCD_DrawImageSBPP(82 + 42, 100 + 38 * 2, 42, BXZT, WHITE, BLACK);
        
        LCD_DrawImage1BPP(82, 100 - 2 + 38 * 3, BMP_DCAC, WHITE, BLACK);//DCAC保险状态
        LCD_DrawImageSBPP(82 + 52, 100 + 38 * 3, 42, BXZT, WHITE, BLACK);
        
        LCD_DrawImage1BPP(82, 100 + 38 * 4, BMP_DJ, WHITE, BLACK);//电机控制器保险状态
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
    unsigned char color;
    if (index == 1) {
        updata_DAT(82 + 200, 100 - 8 + 38 * 0, CAN_0x18EF4EEF.MCU_RPM, 1, 20000, WHITE, 4, 0);
        updata_DAT(82 + 200, 100 - 8 + 38 * 1, CAN_0x18EF4EEF.MotorTorque, 0.1, 2000, WHITE, 4, 0);
        print_SZ_1(82 + 200, 100 - 8 + 38 * 2, CAN_0x18EF4FEF.MCUVoltage, 4, 0, WHITE);
        updata_DAT(82 + 200, 100 - 8 + 38 * 3, CAN_0x18EF4FEF.MCUCurrent, 1, 1000, WHITE, 4, 0);
        updata_DAT(82 + 200 + 16, 100 - 8 + 38 * 4, CAN_0x18EF4FEF.MCU_Temp, 1, 40, WHITE, 3, 0);
        updata_DAT(82 + 200 + 16, 100 - 8 + 38 * 5, CAN_0x18EF4FEF.MCU_Control_Temp, 1, 40, WHITE, 3, 0);
        print_SZ_1(82 + 200 + 16 * 3, 100 - 8 + 38 * 6, CAN_0x18EF4AEF.GearMode, 1, 0, WHITE);
        if (CAN_0x18EF4AEF.EV_Gear == 15) {
            LCD_DrawImage1BPP(82 + 42 * 6 - 5, 100 + 38 * 7, BMP_p, GREEN, BLACK);
        } else if (CAN_0x18EF4AEF.EV_Gear == 13) {
            LCD_DrawImage1BPP(82 + 42 * 6 - 5, 100 + 38 * 7, BMP_r, GREEN, BLACK);
        } else if (CAN_0x18EF4AEF.EV_Gear == 0) {
            LCD_DrawImage1BPP(82 + 42 * 6 - 5, 100 + 38 * 7, BMP_n, GREEN, BLACK);
        } else if (CAN_0x18EF4AEF.EV_Gear == 14) {
            LCD_DrawImage1BPP(82 + 42 * 6 - 5, 100 + 38 * 7, BMP_d, GREEN, BLACK);
        }

        /*if (EV_DTC.Fire_Fault == 1) {
            LCD_DrawImage1BPP(82 + 42 * 6 - 5, 100 + 38 * 7, BMP_Guzhang, RED, BLACK);
        } else if (EV_DTC.Fire_Fault == 0) {
            LCD_DrawImage1BPP(82 + 42 * 6 - 5, 100 + 38 * 7, BMP_Zhengchang, GREEN, BLACK);
        }*/
        print_SZ_1(82 + 200 + 16, 100 - 8 + 38 * 8, SPEED, 3, 0, WHITE);
        updata_DAT(82 + 200, 100 - 8 + 38 * 9, CAN_0x18EF4EEF.OutSpeed, 1, 20000, WHITE, 4, 0);


        if (CAN_0x18EF4BEF.No3 == 1) {
            LCD_DrawImage1BPP(82 + 320 + 42 * 6 - 5, 100 + 38 * 0, BMP_Gongzuo, GREEN, BLACK);
        } else if (CAN_0x18EF4BEF.No3 == 0) {
            LCD_DrawImage1BPP(82 + 320 + 42 * 6 - 5, 100 + 38 * 0, BMP_Tingzhi, YELLOW, BLACK);
        }
        if (CAN_0x18EF4BEF.No4 == 1) {
            LCD_DrawImage1BPP(82 + 320 + 42 * 6 - 5, 100 + 38 * 1, BMP_Gongzuo, GREEN, BLACK);
        } else if (CAN_0x18EF4BEF.No4 == 0) {
            LCD_DrawImage1BPP(82 + 320 + 42 * 6 - 5, 100 + 38 * 1, BMP_Tingzhi, YELLOW, BLACK);
        }

        if (CAN_0x18EF4BEF.No5 == 1) {
            LCD_DrawImage1BPP(82 + 320 + 42 * 6 - 5, 100 + 38 * 2, BMP_Gongzuo, GREEN, BLACK);
        } else if (CAN_0x18EF4BEF.No5 == 0) {
            LCD_DrawImage1BPP(82 + 320 + 42 * 6 - 5, 100 + 38 * 2, BMP_Tingzhi, YELLOW, BLACK);
        }

        if (CAN_0x18EF4BEF.No6 == 1) {
            LCD_DrawImage1BPP(82 + 320 + 42 * 6 - 5, 100 + 38 * 3, BMP_Gongzuo, GREEN, BLACK);
        } else if (CAN_0x18EF4BEF.No6 == 0) {
            LCD_DrawImage1BPP(82 + 320 + 42 * 6 - 5, 100 + 38 * 3, BMP_Tingzhi, YELLOW, BLACK);
        }

        if (CAN_0x18EF4BEF.No7 == 1) {
            LCD_DrawImage1BPP(82 + 320 + 42 * 6 - 5, 100 + 38 * 4, BMP_Gongzuo, GREEN, BLACK);
        } else if (CAN_0x18EF4BEF.No7 == 0) {
            LCD_DrawImage1BPP(82 + 320 + 42 * 6 - 5, 100 + 38 * 4, BMP_Tingzhi, YELLOW, BLACK);
        }

        if (CAN_0x18EF4BEF.No9 == 1) {
            LCD_DrawImage1BPP(82 + 320 + 42 * 6 - 5, 100 + 38 * 5, BMP_Gongzuo, GREEN, BLACK);
        } else if (CAN_0x18EF4BEF.No9 == 0) {
            LCD_DrawImage1BPP(82 + 320 + 42 * 6 - 5, 100 + 38 * 5, BMP_Tingzhi, YELLOW, BLACK);
        }

        if (CAN_0x18EF4BEF.No10 == 1) {
            LCD_DrawImage1BPP(82 + 320 + 42 * 6 - 5, 100 + 38 * 6, BMP_Gongzuo, GREEN, BLACK);
        } else if (CAN_0x18EF4BEF.No10 == 0) {
            LCD_DrawImage1BPP(82 + 320 + 42 * 6 - 5, 100 + 38 * 6, BMP_Tingzhi, YELLOW, BLACK);
        }

        if (CAN_0x18EF4BEF.No13 == 1) {
            LCD_DrawImage1BPP(82 + 320 + 42 * 6 - 5, 100 + 38 * 7, BMP_Gongzuo, GREEN, BLACK);
        } else if (CAN_0x18EF4BEF.No13 == 0) {
            LCD_DrawImage1BPP(82 + 320 + 42 * 6 - 5, 100 + 38 * 7, BMP_Tingzhi, YELLOW, BLACK);
        }

        if (CAN_0x18EF4BEF.No14 == 1) {
            LCD_DrawImage1BPP(82 + 320 + 42 * 6 - 5, 100 + 38 * 8, BMP_Gongzuo, GREEN, BLACK);
        } else if (CAN_0x18EF4BEF.No14 == 0) {
            LCD_DrawImage1BPP(82 + 320 + 42 * 6 - 5, 100 + 38 * 8, BMP_Tingzhi, YELLOW, BLACK);
        }

        if (CAN_0x18EF4BEF.No15 == 1) {
            LCD_DrawImage1BPP(82 + 320 + 42 * 6 - 5, 100 + 38 * 9, BMP_Gongzuo, GREEN, BLACK);
        } else if (CAN_0x18EF4BEF.No15 == 0) {
            LCD_DrawImage1BPP(82 + 320 + 42 * 6 - 5, 100 + 38 * 9, BMP_Tingzhi, YELLOW, BLACK);
        }

        /*print_SZ_1(82 + 200 + 20, 100 - 8 + 38 * 0, VCU_BUSStatus, 2, 0, WHITE);
        print_SZ_1(82 + 200 + 20, 100 - 8 + 38 * 1, VCU_Lock, 2, 0, WHITE);
        print_SZ_1(82 + 200 + 20, 100 - 8 + 38 * 2, VCU_MotorStatus, 2, 0, WHITE);
        if (KT_SIGNAL) {
            LCD_DrawImage1BPP(82 + 42 * 6 - 5, 100 + 38 * 3, BMP_Bihe, GREEN, BLACK);
        } else {
            LCD_DrawImage1BPP(82 + 42 * 6 - 5, 100 + 38 * 3, BMP_Duankai, RED, BLACK);
        }
        print_SZ_1(82 + 200 + 20, 100 - 8 + 38 * 4, VCU_SPEED * 0.5, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 20, 100 - 8 + 38 * 5, VCU_FaultCode, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 20, 100 - 8 + 38 * 6, VCU_Life, 3, 0, WHITE);
        if (ABS_SIGNAL) {
            LCD_DrawImage1BPP(82 + 42 * 6 - 5, 100 + 38 * 7, BMP_Youxiao, GREEN, BLACK);
        } else {
            LCD_DrawImage1BPP(82 + 42 * 6 - 5, 100 + 38 * 7, BMP_Wuxiao, RED, BLACK);
        }
        print_SZ_1(82 + 200 + 20 - 16, 100 - 8 + 38 * 8, VCU_KM * 0.125, 4, 0, WHITE);
        print_SZ_1(82 + 200 + 20 - 32, 100 - 8 + 38 * 9, VCU_Kwh_1s, 4, 3, WHITE);
        
        if (VCU_OilEn == 0xAA) {
            LCD_DrawImage1BPP(82 + 42 * 6 - 5 + 320, 100 + 38 * 0, BMP_Kai, GREEN, BLACK);
        } else if(VCU_OilEn == 0x55) {
            LCD_DrawImage1BPP(82 + 42 * 6 - 5 + 320, 100 + 38 * 0, BMP_Guan, RED, BLACK);
        }
        if (VCU_AirEn == 0xAA) {
            LCD_DrawImage1BPP(82 + 42 * 6 - 5 + 320, 100 + 38 * 1, BMP_Kai, GREEN, BLACK);
        } else if(VCU_AirEn == 0x55){
            LCD_DrawImage1BPP(82 + 42 * 6 - 5 + 320, 100 + 38 * 1, BMP_Guan, RED, BLACK);
        }

        if (VCU_DCDCEn == 0xAA) {
            LCD_DrawImage1BPP(82 + 42 * 6 - 5 + 320, 100 + 38 * 2, BMP_Kai, GREEN, BLACK);
        } else if(VCU_DCDCEn == 0x55){
            LCD_DrawImage1BPP(82 + 42 * 6 - 5 + 320, 100 + 38 * 2, BMP_Guan, RED, BLACK);
        }

        if (!RPM_SIGNAL) {
            LCD_DrawImage1BPP(82 + 42 * 6 - 5 + 320, 100 + 38 * 3, BMP_Youxiao, GREEN, BLACK);
        } else {
            LCD_DrawImage1BPP(82 + 42 * 6 - 5 + 320, 100 + 38 * 3, BMP_Wuxiao, RED, BLACK);
        }
        
        if (!NM_SIGNAL) {
            LCD_DrawImage1BPP(82 + 42 * 6 - 5 + 320, 100 + 38 * 4, BMP_Youxiao, GREEN, BLACK);
        } else {
            LCD_DrawImage1BPP(82 + 42 * 6 - 5 + 320, 100 + 38 * 4, BMP_Wuxiao, RED, BLACK);
        }
        
        print_SZ_1(82 + 200 + 20 + 320 - 16, 100 - 8 + 38 * 5, VCU_TM_Speed_percent * 0.5, 3, 0, WHITE); //油门开度
        print_SZ_1(82 + 200 + 20 + 320 - 16, 100 - 8 + 38 * 6, VCU_TM_Brake_percent * 0.5, 3, 0, WHITE); //制动开度      
        print_SZ_1(82 + 200 + 20 + 320 - 16, 100 - 8 + 38 * 7, VCU_XDC * 2.5, 3, 1, WHITE); //蓄电池电压
         */
    } else if (index == 2) {
        if (CAN_0x18EF4BEF.No16 == 1) {
            LCD_DrawImage1BPP(82 + 42 * 6 - 5, 100 + 38 * 0, BMP_Gongzuo, GREEN, BLACK);
        } else if (CAN_0x18EF4BEF.No16 == 0) {
            LCD_DrawImage1BPP(82 + 42 * 6 - 5, 100 + 38 * 0, BMP_Tingzhi, YELLOW, BLACK);
        }
        
        if (CAN_0x18EF4BEF.No17 == 1) {
            LCD_DrawImage1BPP(82 + 42 * 6 - 5, 100 + 38 * 1, BMP_Gongzuo, GREEN, BLACK);
        } else if (CAN_0x18EF4BEF.No17 == 0) {
            LCD_DrawImage1BPP(82 + 42 * 6 - 5, 100 + 38 * 1, BMP_Tingzhi, YELLOW, BLACK);
        }
        
        if (CAN_0x18EF4BEF.No18 == 1) {
            LCD_DrawImage1BPP(82 + 42 * 6 - 5, 100 + 38 * 2, BMP_Gongzuo, GREEN, BLACK);
        } else if (CAN_0x18EF4BEF.No18 == 0) {
            LCD_DrawImage1BPP(82 + 42 * 6 - 5, 100 + 38 * 2, BMP_Tingzhi, YELLOW, BLACK);
        }
        
        if (CAN_0x18EF4BEF.No19 == 1) {
            LCD_DrawImage1BPP(82 + 42 * 6 - 5, 100 + 38 * 3, BMP_Gongzuo, GREEN, BLACK);
        } else if (CAN_0x18EF4BEF.No19 == 0) {
            LCD_DrawImage1BPP(82 + 42 * 6 - 5, 100 + 38 * 3, BMP_Tingzhi, YELLOW, BLACK);
        }
        
        if (CAN_0x18EF4BEF.No21 == 1) {
            LCD_DrawImage1BPP(82 + 42 * 6 - 5, 100 + 38 * 4, BMP_Bihe, GREEN, BLACK);
        } else if (CAN_0x18EF4BEF.No21 == 0) {
            LCD_DrawImage1BPP(82 + 42 * 6 - 5, 100 + 38 * 4, BMP_Duankai, YELLOW, BLACK);
        }
        
        if (CAN_0x18EF4BEF.No35 == 1) {
            LCD_DrawImage1BPP(82 + 42 * 6 - 5, 100 + 38 * 5, BMP_Bihe, GREEN, BLACK);
        } else if (CAN_0x18EF4BEF.No35 == 0) {
            LCD_DrawImage1BPP(82 + 42 * 6 - 5, 100 + 38 * 5, BMP_Duankai, YELLOW, BLACK);
        }
        
        if (CAN_0x18EF4BEF.No36 == 1) {
            LCD_DrawImage1BPP(82 + 42 * 6 - 5, 100 + 38 * 6, BMP_Bihe, GREEN, BLACK);
        } else if (CAN_0x18EF4BEF.No36 == 0) {
            LCD_DrawImage1BPP(82 + 42 * 6 - 5, 100 + 38 * 6, BMP_Duankai, YELLOW, BLACK);
        }
        
        if (CAN_0x18EF4BEF.No38 == 1) {
            LCD_DrawImage1BPP(82 + 42 * 6 - 5, 100 + 38 * 7, BMP_Bihe, GREEN, BLACK);
        } else if (CAN_0x18EF4BEF.No38 == 0) {
            LCD_DrawImage1BPP(82 + 42 * 6 - 5, 100 + 38 * 7, BMP_Duankai, YELLOW, BLACK);
        }
        
        if (CAN_0x18EF4BEF.No39 == 1) {
            LCD_DrawImage1BPP(82 + 42 * 6 - 5, 100 + 38 * 8, BMP_Bihe, GREEN, BLACK);
        } else if (CAN_0x18EF4BEF.No39 == 0) {
            LCD_DrawImage1BPP(82 + 42 * 6 - 5, 100 + 38 * 8, BMP_Duankai, YELLOW, BLACK);
        }
        print_D(82 + 42 * 6 - 16 * 5, 100 - 8 + 38 * 9, CAN_0x18EF4BEF.CtrlIOStatus, 8, 0, WHITE);
               
        /////////////////////////////////////////////////////////
        if(CheckMode)
            color = YELLOW;
        else 
            color = BLACK;

        if (!checkout) {
            LCD_DrawImage1BPP(82 + 320 + 42 * 6 - 5, 100 + 38 * 6, BMP_Zhengchang, GREEN, color);
        } else {
            LCD_DrawImage1BPP(82 + 320 + 42 * 6 - 5, 100 + 38 * 6, BMP_Jiance, GREEN, color);
        }
        /////////////////////////////////////////////////////////
        
        print_SZ_1(82 + 100 + 320 - 16 - 30, 100 - 8 + 38 * 2, CAN_0x18FECAEF.VCU_DM1.SPN, 6, 0, GREEN);
        print_SZ_1(82 + 100 + 320 + 128 + 16 - 30, 100 - 8 + 38 * 2, CAN_0x18FECAEF.VCU_DM1.FMI, 2, 0, GREEN);
        
        print_SZ_1(82 + 200 + 20 + 320 - 16, 100 - 8 + 38 * 7, CAN_0x18EF4AEF.SpeedDepth, 3, 0, WHITE); //油门开度
        print_SZ_1(82 + 200 + 20 + 320 - 16, 100 - 8 + 38 * 8, CAN_0x18EF4AEF.BrakeDepth , 3, 0, WHITE); //制动开度      
        print_SZ_1(82 + 200 + 20 + 320 - 16 * 4, 100 - 8 + 38 * 9, CAN_0x18EF4AEF.Oum, 6, 0, WHITE); //蓄电池电压
        /*print_SZ_1(82 + 200, 100 - 8 + 38 * 0, MCU_Voltage, 4, 0, WHITE);
        updata_DAT(82 + 200, 100 - 8 + 38 * 1, MCU_Current, 0.25, 2048, WHITE, 4, 0);
        updata_DAT(82 + 200 - 16, 100 - 8 + 38 * 2, MCU_RPM, 1, 0, WHITE, 5, 0);
        updata_DAT(82 + 200, 100 - 8 + 38 * 3, MCU_NM, 0.25, 8192, WHITE, 4, 0);
        updata_DAT(82 + 200 + 16, 100 - 8 + 38 * 4, MCU_Temp, 1, 40, WHITE, 3, 0);
        updata_DAT(82 + 200 + 16, 100 - 8 + 38 * 5, MCU_Control_Temp, 1, 40, WHITE, 3, 0);
        
        if (!VCU_Status2.bit1) {
            LCD_DrawImage1BPP(82 + 42 * 6 - 5 + 320, 100 + 38 * 0, BMP_Youxiao, GREEN, BLACK);
        } else {
            LCD_DrawImage1BPP(82 + 42 * 6 - 5 + 320, 100 + 38 * 0, BMP_Wuxiao, RED, BLACK);
        }
        if (!VCU_Status2.bit2) {
            LCD_DrawImage1BPP(82 + 42 * 6 - 5 + 320, 100 + 38 * 1, BMP_Youxiao, GREEN, BLACK);
        } else {
            LCD_DrawImage1BPP(82 + 42 * 6 - 5 + 320, 100 + 38 * 1, BMP_Wuxiao, RED, BLACK);
        }
        if (!VCU_Status2.bit3) {
            LCD_DrawImage1BPP(82 + 42 * 6 - 5 + 320, 100 + 38 * 2, BMP_Youxiao, GREEN, BLACK);
        } else {
            LCD_DrawImage1BPP(82 + 42 * 6 - 5 + 320, 100 + 38 * 2, BMP_Wuxiao, RED, BLACK);
        }
        if (!VCU_Status2.bit4) {
            LCD_DrawImage1BPP(82 + 42 * 6 - 5 + 320, 100 + 38 * 3, BMP_Youxiao, GREEN, BLACK);
        } else {
            LCD_DrawImage1BPP(82 + 42 * 6 - 5 + 320, 100 + 38 * 3, BMP_Wuxiao, RED, BLACK);
        }
        if (!VCU_Status2.bit5) {
            LCD_DrawImage1BPP(82 + 42 * 6 - 5 + 320, 100 + 38 * 4, BMP_Youxiao, GREEN, BLACK);
        } else {
            LCD_DrawImage1BPP(82 + 42 * 6 - 5 + 320, 100 + 38 * 4, BMP_Wuxiao, RED, BLACK);
        }
        if (!MCU_TempSignal) {
            LCD_DrawImage1BPP(82 + 42 * 6 - 5 + 320, 100 + 38 * 5, BMP_Youxiao, GREEN, BLACK);
        } else {
            LCD_DrawImage1BPP(82 + 42 * 6 - 5 + 320, 100 + 38 * 5, BMP_Wuxiao, RED, BLACK);
        }
        if (!MCU_ControlTempSignal) {
            LCD_DrawImage1BPP(82 + 42 * 6 - 5 + 320, 100 + 38 * 6, BMP_Youxiao, GREEN, BLACK);
        } else {
            LCD_DrawImage1BPP(82 + 42 * 6 - 5 + 320, 100 + 38 * 6, BMP_Wuxiao, RED, BLACK);
        }*/
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
        }
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
        if (CheckMode)
            checkout = !checkout;
        else {
            index_MOTO--;
            f_index = 0;
            if (index_MOTO == 0) {
                index_MOTO = 1;
                frmID = 1;
            }
        }
    }
    if (key_up) {
        key_up = 0;
        if (CheckMode)
            checkout = !checkout;
        else {
            index_MOTO++;
            f_index = 0;
            if (index_MOTO >= 3) {
                index_MOTO = 1;
                frmID = 1;
            }
        }
    }
    if (key_set) {//返回主界面
        key_set = 0;
        if (CheckMode) {
            CheckMode = 0;
        } else {
            frmID = 0;
            f_index = 0;
            Index = 0;
            index_MOTO = 1;
        }
    }
    if (key_long_set) {
        key_long_set = 0;
        CheckMode = 1;
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
    LCD_DrawImage1BPP(82 + 52, 100, BMP_Output, WHITE, BLACK); //输出
    LCD_DrawImage1BPP(82 + 52 + 42, 100, BMP_DL, WHITE, BLACK); //电流
    LCD_DrawImage1BPP(400 - 24, 100, BMP_a, WHITE, BLACK); //A

    LCD_DrawImage1BPP(82, 100 - 2 + 38, BMP_DCAC, WHITE, BLACK); //DCAC
    LCD_DrawImage1BPP(82 + 52, 100 + 38, BMP_Output, WHITE, BLACK); //输出
    LCD_DrawImage1BPP(82 + 52 + 42, 100 + 38, BMP_DY, WHITE, BLACK); //电压
    LCD_DrawImage1BPP(400 - 24, 100 + 38, BMP_v, WHITE, BLACK); //V  

    LCD_DrawImage1BPP(82, 100 - 2 + 38 * 2, BMP_DCAC, WHITE, BLACK); //DCAC
    LCD_DrawImage1BPP(82 + 52, 100 + 38 * 2, BMP_Input, WHITE, BLACK); //输入
    LCD_DrawImage1BPP(82 + 52 + 42, 100 + 38 * 2, BMP_DY, WHITE, BLACK); //电压
    LCD_DrawImage1BPP(400 - 24, 100 + 38 * 2, BMP_v, WHITE, BLACK); //V



    LCD_DrawImage1BPP(82 + 320, 100, BMP_KZQ, WHITE, BLACK); //控制器
    LCD_DrawImage1BPP(82 + 320 + 63, 100, BMP_Wendu, WHITE, BLACK); //温度
    LCD_DrawImage1BPP(720 - 24, 100, BMP_T, WHITE, BLACK); //℃

    LCD_DrawImage1BPP(82 + 320, 100 + 38, BMP_Guzhang, WHITE, BLACK); //故障代码
    LCD_DrawImage1BPP(82 + 42 + 320, 100 + 38, BMP_Code, WHITE, BLACK); //  
}

void DMQUpdate(void) {
    print_SZ_1(82 + 200 + 20, 100 - 8, AIRDCAC_Current, 3, 0, WHITE);
    print_SZ_1(82 + 200 + 20 - 16, 100 - 8 + 38, AIRDCAC_Voltage, 4, 0, WHITE);
    print_SZ_1(82 + 200 + 20 - 16, 100 - 8 + 38 * 2, AIRDCAC_InputVoltage, 4, 0, WHITE);

    updata_DAT(82 + 200 + 300, 100 - 8, AIRDCAC_Temp, 1, 40, WHITE, 3, 0);
    print_D(82 + 180 + 320, 100 - 8 + 38 * 1, AIRDCAC_FaultCode, 8, 0, WHITE);
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
    LCD_DrawImage1BPP(82 + 52, 100, BMP_Output, WHITE, BLACK); //输出
    LCD_DrawImage1BPP(82 + 52 + 42, 100, BMP_DL, WHITE, BLACK); //电流
    LCD_DrawImage1BPP(400 - 24, 100, BMP_a, WHITE, BLACK); //A

    LCD_DrawImage1BPP(82, 100 - 2 + 38, BMP_DCDC, WHITE, BLACK); //DCDC
    LCD_DrawImage1BPP(82 + 52, 100 + 38, BMP_Output, WHITE, BLACK); //输出
    LCD_DrawImage1BPP(82 + 52 + 42, 100 + 38, BMP_DY, WHITE, BLACK); //电压
    LCD_DrawImage1BPP(400 - 24, 100 + 38, BMP_v, WHITE, BLACK); //V  



    /*LCD_DrawImage1BPP(82 + 320, 100, BMP_KZQ, WHITE, BLACK); //控制器
    LCD_DrawImage1BPP(82 + 320 + 63, 100, BMP_Wendu, WHITE, BLACK); //温度
    LCD_DrawImage1BPP(720 - 24, 100, BMP_T, WHITE, BLACK); //℃*/

    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 0, BMP_Guzhang, WHITE, BLACK); //故障代码
    LCD_DrawImage1BPP(82 + 42 + 320, 100 + 38 * 0, BMP_Code, WHITE, BLACK); // 

    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 1, BMP_Gongzuo, WHITE, BLACK); //工作状态
    LCD_DrawImage1BPP(82 + 42 + 320, 100 + 38 * 1, BMP_Zhuangtai, WHITE, BLACK); // 
}

void DCDCUpdate(void) {
    print_SZ_1(82 + 200 + 20 - 16, 100 - 8, DCDC_Output_Current, 4, 1, WHITE);
    print_SZ_1(82 + 200 + 20 - 16, 100 - 8 + 38, DCDC_Output_Voltage, 4, 1, WHITE);
    //print_SZ_1(82 + 200 + 20 - 16, 100 - 8 + 38 * 2, DCDC_Input_Voltage, 4, 0, WHITE);

    //updata_DAT(82 + 200 + 300, 100 - 8, DCDC_Temp, 1, 40, WHITE, 3, 0);
    print_D(82 + 180 + 320, 100 - 8 + 38 * 0, DCDC_FaultCode, 8, 0, WHITE);
    if (DCDC_WorkStatus == 1) {
        LCD_DrawImage1BPP(82 + 42 * 6 - 5 + 320, 100 + 38 * 1, BMP_Gongzuo, GREEN, BLACK);
    } else {
        LCD_DrawImage1BPP(82 + 42 * 6 - 5 + 320, 100 + 38 * 1, BMP_Tingzhi, RED, BLACK);
    }
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
    LCD_DrawImage1BPP(82 + 52, 100, BMP_Output, WHITE, BLACK); //输出
    LCD_DrawImage1BPP(82 + 52 + 42, 100, BMP_DL, WHITE, BLACK); //电流
    LCD_DrawImage1BPP(400 - 24, 100, BMP_a, WHITE, BLACK); //A

    LCD_DrawImage1BPP(82, 100 - 2 + 38, BMP_DCAC, WHITE, BLACK); //DCAC
    LCD_DrawImage1BPP(82 + 52, 100 + 38, BMP_Output, WHITE, BLACK); //输出
    LCD_DrawImage1BPP(82 + 52 + 42, 100 + 38, BMP_DY, WHITE, BLACK); //电压
    LCD_DrawImage1BPP(400 - 24, 100 + 38, BMP_v, WHITE, BLACK); //V  

   /*LCD_DrawImage1BPP(82, 100 - 2 + 38 * 2, BMP_DCAC, WHITE, BLACK); //DCAC Life
    LCD_DrawImage1BPP(82 + 52 + 11, 100 - 2 + 38 * 2, BMP_Life, WHITE, BLACK); //

    LCD_DrawImage1BPP(82, 100 - 2 + 38 * 2, BMP_DCAC, WHITE, BLACK); //DCAC
    LCD_DrawImage1BPP(82 + 52, 100 + 38 * 2, BMP_Input, WHITE, BLACK); //输入
    LCD_DrawImage1BPP(82 + 52 + 42, 100 + 38 * 2, BMP_DY, WHITE, BLACK); //电压
    LCD_DrawImage1BPP(400 - 24, 100 + 38 * 2, BMP_v, WHITE, BLACK); //V*/

    LCD_DrawImage1BPP(82 + 320, 100, BMP_KZQ, WHITE, BLACK); //控制器
    LCD_DrawImage1BPP(82 + 320 + 63, 100, BMP_Wendu, WHITE, BLACK); //温度
    LCD_DrawImage1BPP(720 - 24, 100, BMP_T, WHITE, BLACK); //℃

    LCD_DrawImage1BPP(82 + 320, 100 + 38, BMP_Guzhang, WHITE, BLACK); //故障代码
    LCD_DrawImage1BPP(82 + 42 + 320, 100 + 38, BMP_Code, WHITE, BLACK); //    
}

void DMYUpdate(void) {
    print_SZ_1(82 + 200 + 20, 100 - 8, OILDCAC_Current, 3, 0, WHITE);
    print_SZ_1(82 + 200 + 20 - 16, 100 - 8 + 38, OILDCAC_Voltage, 4, 0, WHITE);
    //print_SZ_1(82 + 200 + 20 - 16, 100 - 8 + 38 * 2, OILDCAC_InputVoltage, 4, 0, WHITE);

    updata_DAT(82 + 200 + 300, 100 - 8, OILDCAC_Temp, 1, 40, WHITE, 3, 0);
    print_D(82 + 180 + 320, 100 - 8 + 38 * 1, OILDCAC_FaultCode, 8, 0, WHITE);
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

    print_SZ_2(750, 50, index, 1, 0, WHITE); // index/N
    LCD_DrawImage1BPP(750 + 11, 50, BMP_I, WHITE, BLACK);
    print_SZ_2(750 + 11 + 14, 50, 1, 1, 0, WHITE);
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

        LCD_DrawImage1BPP(82, 100 + 38 * 2, BMP_s, WHITE, BLACK); //S
        LCD_DrawImage1BPP(82 + 11, 100 + 38 * 2, BMP_o, WHITE, BLACK); //O
        LCD_DrawImage1BPP(82 + 11 + 11, 100 + 38 * 2, BMP_c, WHITE, BLACK); //C
        LCD_DrawImage1BPP(400 - 24, 100 + 38 * 2, BMP_Baifenhao, WHITE, BLACK); //%

        /*LCD_DrawImage1BPP(82, 100 + 38 * 3, BMP_Pingjun, WHITE, BLACK); //平均电耗
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 3, BMP_Dianhao, WHITE, BLACK);
        LCD_DrawImageSBPP(400 - 28 - 11 * 7, 100 + 38 * 3, 11, KWH, WHITE, BLACK);

        LCD_DrawImage1BPP(82, 100 + 38 * 4, BMP_Shunshi, WHITE, BLACK); //瞬时电耗
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 4, BMP_Dianhao, WHITE, BLACK);
        LCD_DrawImageSBPP(400 - 28 - 11 * 7, 100 + 38 * 4, 11, KWH, WHITE, BLACK);*/

        LCD_DrawImageSBPP(82, 100 + 38 * 3, 42, DCSYDL, WHITE, BLACK); //电池剩余电量
        LCD_DrawImageSBPP(400 - 24 - 11 - 11, 100 + 38 * 3, 11, KWH, WHITE, BLACK); //KWH

        LCD_DrawImageSBPP(82, 100 + 38 * 4, 21, ZDFDXZGL, WHITE, BLACK); //最大放电功率限制
        LCD_DrawImageSBPP(400 - 24 - 11 - 11, 100 + 38 * 4, 11, KW, WHITE, BLACK); //KW
        
        LCD_DrawImageSBPP(82, 100 + 38 * 5, 21, ZDCDXZGL, WHITE, BLACK); //最大充电功率限制
        LCD_DrawImageSBPP(400 - 24 - 11 - 11, 100 + 38 * 5, 11, KW, WHITE, BLACK); //KW


        for (i = 0; i < 4; i++) {
            LCD_DrawImage1BPP(82 + 320, 100 + 38 * i, BMP_Zui, WHITE, BLACK); //最
            if (i % 2 == 0) {
                LCD_DrawImage1BPP(82 + 320 + 21, 100 + 38 * i, BMP_Gao, WHITE, BLACK); // 高
            } else {
                LCD_DrawImage1BPP(82 + 320 + 21, 100 + 38 * i, BMP_Di, WHITE, BLACK); // 低 
            }

            LCD_DrawImage1BPP(82 + 320 + 21 + 21, 100 + 38 * i, BMP_Dan, WHITE, BLACK); //单
            LCD_DrawImage1BPP(82 + 320 + 21 + 21 + 21, 100 + 38 * i, BMP_Ti, WHITE, BLACK); //体

            LCD_DrawImage1BPP(82 + 320 + 42 * 8.5 + 5, 100 + 38 * i, BMP_Hao, WHITE, BLACK); //号

            if (i < 2) {
                LCD_DrawImage1BPP(82 + 320 + 21 + 21 + 21 + 21, 100 + 38 * i, BMP_DY, WHITE, BLACK); //电压
                LCD_DrawImage1BPP(720 - 24 - 63 - 5, 100 + 38 * i, BMP_v, WHITE, BLACK); //V
            } else {
                LCD_DrawImage1BPP(82 + 320 + 21 + 21 + 21 + 21, 100 + 38 * i, BMP_Wendu, WHITE, BLACK); //温度
                LCD_DrawImage1BPP(720 - 28 - 63 - 5, 100 + 38 * i, BMP_T, WHITE, BLACK); //℃
            }
        }

        /*LCD_DrawImage1BPP(82, 100, BMP_DC, WHITE, BLACK); //电池
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

        LCD_DrawImage1BPP(82 , 100 + 38 * 3, BMP_Chong, WHITE, BLACK); //充电次数
        LCD_DrawImage1BPP(82  + 21, 100 + 38 * 3, BMP_DY, WHITE, BLACK); //
        LCD_DrawImage1BPP(82  + 42, 100 + 38 * 3, BMP_Cishu, WHITE, BLACK); //

        LCD_DrawImage1BPP(82, 100 + 38 * 4, BMP_b, WHITE, BLACK); //BMS
        LCD_DrawImage1BPP(82 + 11, 100 + 38 * 4, BMP_m, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 11 + 11, 100 + 38 * 4, BMP_s, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 11 + 11 + 11 + 11, 100 + 38 * 4, BMP_Life, WHITE, BLACK); //LIFE

        for (i = 5; i < 9; i++) {
            LCD_DrawImage1BPP(82, 100 + 38 * i, BMP_Zui, WHITE, BLACK); //最大允许充电电流
            LCD_DrawImage1BPP(82 + 21 + 21, 100 + 38 * i, BMP_Yunxu, WHITE, BLACK); //
            if (i == 5)                
                LCD_DrawImage1BPP(82 + 21, 100 + 38 * i, BMP_Di, WHITE, BLACK); //
            else if(i == 6)
                LCD_DrawImage1BPP(82 + 21, 100 + 38 * i, BMP_Gao, WHITE, BLACK); //
            else 
                LCD_DrawImage1BPP(82 + 21, 100 + 38 * i, BMP_Da, WHITE, BLACK);
            if (i == 6 || i == 8)
                LCD_DrawImage1BPP(82 + 21 + 21 + 42, 100 + 38 * i, BMP_Chong, WHITE, BLACK); //
            else
                LCD_DrawImage1BPP(82 + 21 + 21 + 42, 100 + 38 * i, BMP_Fang, WHITE, BLACK); //
            LCD_DrawImage1BPP(82 + 21 + 21 + 42 + 21, 100 + 38 * i, BMP_DL, WHITE, BLACK); //
            LCD_DrawImage1BPP(82 + 21 + 21 + 42 + 21 + 21, 100 + 38 * i, BMP_DL, WHITE, BLACK); //
            LCD_DrawImage1BPP(400 - 24, 100 + 38 * i, BMP_a, WHITE, BLACK); //A
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
        LCD_DrawImage1BPP(720 - 24, 100 + 38 * 9, BMP_h, WHITE, BLACK);  */
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
        LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 5, BMP_Life, WHITE, BLACK); //LIFE    */
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
        print_SZ_1(82 + 200 + 30, 100 - 8, CAN_0x18EF4CEF.BMS_V, 3, 0, WHITE);
        updata_DAT(82 + 200 + 30, 100 - 8 + 38, CAN_0x18EF4CEF.BMS_A, 1, 1000, WHITE, 3, 0);
        print_SZ_1(82 + 200 + 30, 100 - 8 + 38 * 2, CAN_0x18EF4CEF.BMS_SOC, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 30 - 16 * 1, 100 - 8 + 38 * 3, CAN_0x18EF4CEF.EV_RestAhr, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 30 - 16 * 1, 100 - 8 + 38 * 4, CAN_0x18EF4CEF.DischargePowerLimilt, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 30 - 16, 100 - 8 + 38 * 5, CAN_0x18EF4CEF.ChargePowerLimilt, 3, 0, WHITE);

        print_SZ_1(82 + 200 + 300 - 32 - 5, 100 - 8, CAN_0x18EF4DEF.BAT_Max_Cell_Voltage * 2, 3, 2, WHITE);
        //print_SZ_1(82 + 200 + 300 - 32 + 16 * 6 - 5, 100 - 8, BAT_Max_Cell_Voltage_Cell_Case, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 300 - 32 + 16 * 9 + 5, 100 - 8, CAN_0x18EF4DEF.BAT_Max_Cell_Voltage_Cell_Number, 4, 0, WHITE);

        print_SZ_1(82 + 200 + 300 - 32 - 5, 100 - 8 + 38, CAN_0x18EF4DEF.BAT_Min_Cell_Voltage * 2, 3, 2, WHITE);
        //print_SZ_1(82 + 200 + 300 - 32 + 16 * 6 - 5, 100 - 8 + 38, BAT_Min_Cell_Voltage_Cell_Case, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 300 - 32 + 16 * 9 + 5, 100 - 8 + 38, CAN_0x18EF4DEF.BAT_Min_Cell_Voltage_Cell_Number, 4, 0, WHITE);

        updata_DAT(82 + 200 + 300 - 16 - 5, 100 - 8 + 38 * 2, CAN_0x18EF4DEF.BAT_Max_Cell_Temperature, 1, 40, WHITE, 3, 0);
        print_SZ_1(82 + 200 + 300 - 32 + 16 * 9 + 5, 100 - 8 + 38 * 2, CAN_0x18EF4DEF.BAT_Max_Cell_Temp_Cell_Number, 4, 0, WHITE);

        updata_DAT(82 + 200 + 300 - 16 - 5, 100 - 8 + 38 * 3, CAN_0x18EF4DEF.BAT_Min_Cell_Temperature, 1, 40, WHITE, 3, 0);
        print_SZ_1(82 + 200 + 300 - 32 + 16 * 9 + 5, 100 - 8 + 38 * 3, CAN_0x18EF4DEF.BAT_Min_Cell_Temp_Cell_Number, 4, 0, WHITE);
        /*print_SZ_1(82 + 200 + 30, 100 - 8, BMS_V * 0.02, 3, 0, WHITE);
        updata_DAT(82 + 200 + 30 - 16, 100 - 8 + 38, BMS_A, 0.1, 3600, WHITE, 4, 0);
        print_SZ_1(82 + 200 + 30, 100 - 8 + 38 * 2, BMS_SOC * 0.4, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 30 - 16 * 3, 100 - 8 + 38 * 3, BMS_ChargeTimes, 6, 0, WHITE);
        print_SZ_1(82 + 200 + 30 + 16, 100 - 8 + 38 * 4, BMS_Life, 2, 0, WHITE);
        updata_DAT(82 + 200 + 30 - 16, 100 - 8 + 38 * 5, BMS_LowDischargeVoltage, 0.1, 0, WHITE, 4, 0);
        updata_DAT(82 + 200 + 30 - 16, 100 - 8 + 38 * 6, BMS_HighChargeVoltage, 0.1, 0, WHITE, 4, 0);
        updata_DAT(82 + 200 + 30 - 16, 100 - 8 + 38 * 7, BMS_HighDischargeCurrent, 0.1, 0, WHITE, 4, 0);
        updata_DAT(82 + 200 + 30 - 16, 100 - 8 + 38 * 8, BMS_HighChargeCurrent, 0.1, 6553, WHITE, 4, 0);
        print_SZ_1(82 + 200 + 30 - 16 * 3, 100 - 8 + 38 * 9, BAT_RestAhr, 5, 2, WHITE);


        print_SZ_1(82 + 200 + 300 - 32 - 5, 100 - 8, BAT_Max_Cell_Voltage, 4, 3, WHITE);
        print_SZ_1(82 + 200 + 300 - 32 + 16 * 6 - 5, 100 - 8, BAT_Max_Cell_Voltage_Cell_Case, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 300 - 32 + 16 * 10 + 5, 100 - 8, BAT_Max_Cell_Voltage_Cell_Number, 3, 0, WHITE);

        print_SZ_1(82 + 200 + 300 - 32 - 5, 100 - 8 + 38, BAT_Min_Cell_Voltage, 4, 3, WHITE);
        print_SZ_1(82 + 200 + 300 - 32 + 16 * 6 - 5, 100 - 8 + 38, BAT_Min_Cell_Voltage_Cell_Case, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 300 - 32 + 16 * 10 + 5, 100 - 8 + 38, BAT_Min_Cell_Voltage_Cell_Number, 3, 0, WHITE);

        updata_DAT(82 + 200 + 300 - 5, 100 - 8 + 38 * 2, BAT_Max_Cell_Temperature, 1, 40, WHITE, 3, 0);
        print_SZ_1(82 + 200 + 300 - 32 + 16 * 6 - 5, 100 - 8 + 38 * 2, BAT_Max_Cell_Temp_Cell_Case, 3, 0, WHITE);

        updata_DAT(82 + 200 + 300 - 5, 100 - 8 + 38 * 3, BAT_Min_Cell_Temperature, 1, 40, WHITE, 3, 0);
        print_SZ_1(82 + 200 + 300 - 32 + 16 * 6 - 5, 100 - 8 + 38 * 3, BAT_Min_Cell_Temp_Cell_Case, 3, 0, WHITE);
        
        updata_DAT(82 + 200 + 300 - 5, 100 - 8 + 38 * 4, BAT_Max_Pole_Temp, 1, 40, WHITE, 3, 0);
        print_SZ_1(82 + 200 + 300 - 32 + 16 * 6 - 5, 100 - 8 + 38 * 4, BAT_Max_Pole_Temp_Cell_Case, 3, 0, WHITE);
        
        print_SZ_1(82 + 200 + 300 - 5, 100 - 8 + 38 * 5, BMS_PackNumber, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 300 - 5, 100 - 8 + 38 * 6, BMS_SingleNumber, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 300 - 5, 100 - 8 + 38 * 7, BMS_SeriesNumber, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 300 - 5, 100 - 8 + 38 * 8, BMS_ParallelNumber, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 300 - 5, 100 - 8 + 38 * 9, BAT_Ahr, 5, 2, WHITE);    */
    } else if (index == 2) {
        /*print_SZ_1(82 + 200 + 30, 100 - 8, BMS_Warn_Type, 3, 0, WHITE);
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
        print_SZ_1(82 + 200 + 320 + 30, 100 - 8 + 38 * 5, IM_Life, 3, 0, WHITE);*/
    } else if (index == 3) {
        /*for (j = 0; j < 2; j++) {
            for (i = 0; i < 10; i++) {
                print_SZ_1(12 + 180 + 390 * j - 5, 100 - 8 + 38 * i, BAT_Pack_Voltage[10 * j + i + 1], 4, 1, WHITE);
                print_SZ_1(12 + 180 + 390 * j - 32 + 16 * 10 + 5, 100 - 8 + 38 * i, BAT_Pack_Number[10 * j + i + 1], 3, 0, WHITE);
            }
        }*/
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
        if (index_BMS >= 2) {
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
    LCD_DrawImage1BPP(50 + 42, 90, BMP_Xiang_BMS, WHITE, BLACK); //箱
    LCD_DrawImage1BPP(50 + 42 + 21, 90, BMP_Hao, WHITE, BLACK); //号
    LCD_DrawImage1BPP(50 + 42 + 42 + 21 + 15, 90 - 9, BMP_SZ_1[index], GREEN, BLACK);

    for (j = 0; j < 3; j++) {
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

    for (j = 0; j < 2; j++) {
        for (i = 0; i < 10; i++) {
            if (i < 9) {//写编号个位
                LCD_DrawImage1BPP(5 + 16 + 16 + (j + 3) * 160, 46 + 70 + i * 36, BMP_SZ_1[i + 1], WHITE, BLACK);
                if (j > 0) {//写编号十位
                    LCD_DrawImage1BPP(5 + 16 + (j + 3) * 160, 46 + 70 + i * 36, BMP_SZ_1[j], WHITE, BLACK);
                }
            } else {//写最底下一行编号
                LCD_DrawImage1BPP(5 + 16 + 16 + (j + 3) * 160, 46 + 70 + i * 36, BMP_SZ_1[0], WHITE, BLACK);
                LCD_DrawImage1BPP(5 + 16 + (j + 3) * 160, 46 + 70 + i * 36, BMP_SZ_1[j + 1], WHITE, BLACK);
            }
            LCD_DrawImage1BPP(5 + 3 + 16 + 16 + 100 + (j + 3) * 160, 46 + 70 + 8 + i * 36, BMP_T, YELLOW, BLACK);
        }
    }
    //编号
    /*if (index == 1) {
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
    }*/
}

void BatteryUpdate(unsigned char index) {
    //unsigned char i, j;
    /*for (j = 0; j < 3; j++) {
        for (i = 0; i < 10; i++) {
            if (BAT_Cell_Voltage[index][j * 10 + i + 1] == 0)
                print_SZ_1(60 + j * 160, 46 + 70 + 36 * i, BAT_Cell_Voltage[index][j * 10 + i + 1], 4, 3, BLACK);
            else print_SZ_1(60 + j * 160, 46 + 70 + 36 * i, BAT_Cell_Voltage[index][j * 10 + i + 1], 4, 3, GREEN); //单体电压
        }
    }
    for (j = 0; j < 2; j++) {
        for (i = 0; i < 10; i++) {
            if (BAT_Cell_Temp[index][j * 10 + i] == 0)
                updata_DAT(60 + (j + 3) * 160 + 25, 46 + 70 + 36 * i, BAT_Cell_Temp[index][j * 10 + i], 1, 40, BLACK, 3, 0);
            else updata_DAT(60 + (j + 3) * 160 + 25, 46 + 70 + 36 * i, BAT_Cell_Temp[index][j * 10 + i], 1, 40, GREEN, 3, 0); //单体温度
        }
    }
     */


    /*if (index == 1) {
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
     */
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
        if (index_BAT == 8) {
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
    LCD_DrawImageSBPP(130 + 200 - 2, 130 - 85, 50, HV_SYSTEM, WHITE, BLACK); //空调

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



    /*LCD_DrawImage1BPP(82 + 320, 100, BMP_Chesu, WHITE, BLACK); //车
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
    /*if (AC_Status == 1) {
        LCD_DrawImage1BPP(82 + 42 * 6 - 5, 100 + 38 * 0, BMP_Gongzuo, GREEN, BLACK);
    } else {
        LCD_DrawImage1BPP(82 + 42 * 6 - 5, 100 + 38 * 0, BMP_Tingzhi, RED, BLACK);
    }
    updata_DAT(82 + 200 + 32, 100 - 8 + 38 * 1, AC_Set_Temp, 0.5, 40, WHITE, 3, 0);
    print_SZ_1(82 + 200 + 64, 100 - 8 + 38 * 2, AC_Gear + 1, 1, 0, WHITE);
    
    if (AC_WindMode == 1) {
        LCD_DrawImage1BPP(82 + 42 * 6 - 5, 100 + 38 * 3, BMP_Wai, GREEN, BLACK);
    } else {
        LCD_DrawImage1BPP(82 + 42 * 6 - 5, 100 + 38 * 3, BMP_Nei, GREEN, BLACK);
    }
    LCD_DrawImage1BPP(82 + 42 * 6 - 5 + 24, 100 + 38 * 3, BMP_Xunhuan, GREEN, BLACK);
    
    print_SZ_1(82 + 200 + 64, 100 - 8 + 38 * 4, AC_Work_Status, 1, 0, WHITE);
    print_SZ_1(82 + 200 + 32, 100 - 8 + 38 * 5, AC_Life, 3, 0, WHITE);
     */

    /*updata_DAT(82 + 200 + 300 + 32, 100 - 8 + 38 * 0, AC_Indoor_Temp, 0.5, 40, WHITE, 3, 0);
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



