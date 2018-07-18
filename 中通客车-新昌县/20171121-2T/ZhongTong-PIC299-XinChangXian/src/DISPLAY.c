#include "SYSTEM.h"
#include "FONT.h"
//#include "LOGO.h"
#include "YBFONT.h"
#include "CAR.h"

unsigned char Index = 0;
unsigned char t = 0;
unsigned char t_add = 0;
unsigned char frmID = 0;
unsigned char f_index = 0;
unsigned char menuid = 0;
unsigned char AV_CH = 0;
unsigned char color_old[24] = {};
unsigned int  x=0,y=0;


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


void print_SZ_2(unsigned int x, unsigned int y, //显示坐标位置 
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
    bcd[sum - dot] = 10; //加入小数点  
    if (dot > 0) {
        for (i = 0; i <= sum; i++) {
            if (f && (bcd[i] == 0)&&(i < sum - 1 - dot)) { //不显示前面0
                f = 1;
                color = BLACK;
            } else {
                f = 0;
                color = color1;
            }
            LCD_DrawImage1BPP(x + i * 16, y, BMP_SZ_3[bcd[i]], color, BLACK);
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
            LCD_DrawImage1BPP(x + i * 16, y, BMP_SZ_3[bcd[i]], color, BLACK);
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


void print_D(unsigned int x, unsigned int y, //以2进制显示
        unsigned char dat) { //显示的数据       
    unsigned char bcd[8], i = 0;
    for (i = 0; i < 8; i++) {
        bcd[i] = dat % 2;
        dat = dat / 2;
      //LCD_DrawImage1BPP(x + 16 * (7 - i), y, BMP_SZ_1[bcd[i]], WHITE, BLACK);
        LCD_DrawImage1BPP(x + 16 * (7 - i), y, BMP_SZ_3[bcd[i]], WHITE, BLACK);
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
 */
void disp_rectange(unsigned int x,unsigned int y, //显示坐标位置
                     unsigned int w,unsigned int h,   //显示矩形的长度和宽度
                     unsigned int dot,                //显示矩形线条的宽度
                     unsigned char color1){
  LCD_DrawRect(x,y,w*8,dot,color1);  //--
  LCD_DrawRect(x,y+h,w*8,dot,color1); //--

  LCD_DrawRect(x,y,dot,h,color1);//|
  LCD_DrawRect(x+w*8-2,y,dot,h,color1);//|
}

void update_dl(unsigned int x,unsigned int y,unsigned int temp,unsigned int NUM,unsigned int s,unsigned char color){
     unsigned char num=0,color1=0; 
     unsigned char bcd[6]={0,0,0,0,0,0};
     unsigned int  i=0;  
     for(i=0;i<NUM;i++){
      bcd[5-i]=temp%10;
      temp=temp/10; 
     }      
    // + 万 千 百 十 个
    // 0 1  2  3  4  5 
     num=0;
     for(i=6-NUM;i<5;i++){       
      if(bcd[i]==0) num++; //有效位前面零的个数
      else          break;
     }
     if(num==NUM) bcd[4]=s; //全是零
     else         bcd[5-(NUM-num)]=s; //
  
     for(i=0;i<NUM+1;i++){
      if(5-NUM+i<5-(NUM-num)) color1=BLACK;
      else                    color1=color;
      LCD_DrawImage1BPP(x+i*16, y,BMP_SZ_3[bcd[5-NUM+i]],color1,BLACK); //正负号 
     } 
}

void update_deg(unsigned int x,unsigned int y,unsigned char temp,unsigned char color){
     unsigned char s=0; 
     if(temp==0xff)color=BLACK;      
     if(temp>=40){temp=temp-40;s=12;}
     else        {temp=40-temp;s=11;}  
     update_dl(x,y,temp,3,s,color);
}

void update_deg1(unsigned int x,unsigned int y,unsigned char temp,unsigned char color){
     unsigned char s=0; 
     if(temp==0xff)color=BLACK;      
     if(temp>=30){temp=temp-30;s=12;}
     else        {temp=30-temp;s=11;}  
     update_dl(x,y,temp,3,s,color);
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
        LCD_DrawImage1BPP(x + 260, y-2, BMP_SZ_1[2], WHITE, BLACK); //2
        LCD_DrawImage1BPP(x + 260 + 16, y-2, BMP_SZ_1[0], WHITE, BLACK); //0

        if (color_back && (t == 4)) {
            if (t_add) {//年设置，十位
                timer.year = timer.year + 0x10;
                if ((timer.year >> 4) > 9) {
                    timer.year = timer.year & 0x0f;
                }
                DS3231_SetTime(&timer);
                t_add = 0;
            }
            LCD_DrawImage1BPP(x + 260 + 16 * 2, y-2, BMP_SZ_1[(dtimer.year >> 4)&0x0f], WHITE, GRAY);
        } else LCD_DrawImage1BPP(x + 260 + 16 * 2, y-2, BMP_SZ_1[(dtimer.year >> 4)&0x0f], WHITE, BLACK);

        if (color_back && (t == 5)) {
            if (t_add) {//年设置，个位
                timer.year = timer.year + 0x01;
                if ((timer.year & 0x0f) > 9) {
                    timer.year = timer.year & 0xf0;
                }
                DS3231_SetTime(&timer);
                t_add = 0;
            }
            LCD_DrawImage1BPP(x + 260 + 16 * 3, y-2, BMP_SZ_1[dtimer.year & 0x0f], WHITE, GRAY);
        } else LCD_DrawImage1BPP(x + 260 + 16 * 3, y-2, BMP_SZ_1[dtimer.year & 0x0f], WHITE, BLACK);

        LCD_DrawImage1BPP(x + 260 + 16 * 4, y-2, BMP_SZ_1[17], WHITE, BLACK); //-

        if (color_back && (t == 6)) {
            if (t_add) {//月设置，十位
                timer.month = timer.month + 0x10;
                if ((timer.month >> 4) > 1) {
                    timer.month = timer.month & 0x0f;
                }
                DS3231_SetTime(&timer);
                t_add = 0;
            }
            LCD_DrawImage1BPP(x + 260 + 16 * 5, y-2, BMP_SZ_1[(dtimer.month >> 4)&0x0f], WHITE, GRAY);
        } else LCD_DrawImage1BPP(x + 260 + 16 * 5, y-2, BMP_SZ_1[(dtimer.month >> 4)&0x0f], WHITE, BLACK);

        if (color_back && (t == 7)) {
            if (t_add) {//月设置，个位
                timer.month = timer.month + 0x01;
                if ((timer.month & 0x0f) > 9) {
                    timer.month = timer.month & 0xf0;
                }
                DS3231_SetTime(&timer);
                t_add = 0;
            }
            LCD_DrawImage1BPP(x + 260 + 16 * 6, y-2, BMP_SZ_1[dtimer.month & 0x0f], WHITE, GRAY);
        } else LCD_DrawImage1BPP(x + 260 + 16 * 6, y-2, BMP_SZ_1[dtimer.month & 0x0f], WHITE, BLACK);

        LCD_DrawImage1BPP(x + 260 + 16 * 7, y-2, BMP_SZ_1[17], WHITE, BLACK); //-

        if (color_back && (t == 8)) {
            if (t_add) {//日设置，十位
                timer.day = timer.day + 0x10;
                if ((timer.day >> 4) > 3) {
                    timer.day = timer.day & 0x0f;
                }
                DS3231_SetTime(&timer);
                t_add = 0;
            }
            LCD_DrawImage1BPP(x + 260 + 16 * 8, y-2, BMP_SZ_1[(dtimer.day >> 4)&0x0f], WHITE, GRAY);
        } else LCD_DrawImage1BPP(x + 260 + 16 * 8, y-2, BMP_SZ_1[(dtimer.day >> 4)&0x0f], WHITE, BLACK);

        if (color_back && (t == 9)) {
            if (t_add) {//日设置，个位
                timer.day = timer.day + 0x01;
                if ((timer.day & 0x0f) > 9) {
                    timer.day = timer.day & 0xf0;
                }
                DS3231_SetTime(&timer);
                t_add = 0;
            }
            LCD_DrawImage1BPP(x + 260 + 16 * 9, y-2, BMP_SZ_1[dtimer.day & 0x0f], WHITE, GRAY);
        } else LCD_DrawImage1BPP(x + 260 + 16 * 9, y-2, BMP_SZ_1[dtimer.day & 0x0f], WHITE, BLACK);

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

void frmTIME_SET( void ){     
    if (f_index == 0) { //只更新一次
        f_index = 1;  
        time_flag = 1;
        LCD_Clear();
        LCD_DrawRect(0, 56,  800, 2, GRAY); //顶部横线 
        LCD_DrawImage1BPP(360, 30, Bmp_SJSZ, GREEN, BLACK);
    } else if (f_index == 1) {
        f_index = 1;
        disp_time(330-120, 440-200, timer);
    } else {
        f_index = 0;
    }
    
    if (key_up) { //子菜单切换
        key_up = 0;
        if (t < 9) t ++;
        else       t = 9;          
    }
    
    if (key_AV) {
        key_AV = 0;
        if (t > 0) t --;
        else       t = 0;                     
    }
    
    if (key_set) {
        key_set = 0;
        if (time_flag) t_add = 1;
        else           t_add = 0;              
    }
    
    if (key_long_set) {//主菜单/子菜单切换
        key_long_set = 0;
        frmID = 0;
        f_index = 0;
        time_flag=0;
        t = 10;       
    }
    
}

/*
void updata_QY(void) {
    unsigned char color = RED;
    unsigned int press1 = 50; //气压传感器量程是0-1.2Mpa ,对应为0-120 进度条0-100
    unsigned int press2 = 90; //气压传感器量程是0-1.2Mpa ,对应为0-120 进度条0-100
    if (ADR[1] < 10) press1 = 0;
    else if (ADR[1] <= 52) press1 = (ADR[1] - 10)*0.48;
    else if (ADR[1] <= 124) press1 = (ADR[1] - 52)*0.56 + 20;
    else if (ADR[1] <= 155) press1 = (ADR[1] - 124)*0.65 + 60;
    else press1 = (ADR[1] - 155)*0.69 + 80;
    //press1 = ADR[4] / 27; //电压型采样   0-5V
    //press2 = ADR[5] / 27;//电压型采样   0-5V

    if (press1 > 60) color = GREEN;
    else color = RED;
    if (press1 > 100) press1 = 100;
    print_SZ(33 - 7, 410 + 13, press1, 3, 2, color);
    LCD_DrawImage1BPP(33 + 9, 380 + 13, Bmp_QY1, color, BLACK); //气压1图标
    LCD_DrawRect(38, 102 + 13, 44, (260 - press1 * 2.6), BLACK); //260/100  
    LCD_DrawRect(38, (368 + 13 - press1 * 2.6), 44, (press1 * 2.6), color);

    if (ADR[2] < 10) press2 = 0;
    else if (ADR[2] <= 52) press2 = (ADR[2] - 10)*0.48;
    else if (ADR[2] <= 124) press2 = (ADR[2] - 52)*0.56 + 20;
    else if (ADR[2] <= 155) press2 = (ADR[2] - 124)*0.65 + 60;
    else press2 = (ADR[2] - 155)*0.69 + 80;

    if (press2 > 60) color = GREEN;
    else color = RED;
    if (press2 > 100) press2 = 100;
    LCD_DrawImage1BPP(712 + 9, 380 + 13, Bmp_QY2, color, BLACK); //气压2图标
    print_SZ(712 - 7, 410 + 13, press2, 3, 2, color);
    LCD_DrawRect(712 + 5, 102 + 13, 44, (260 - press2 * 2.6), BLACK); //260/100  
    LCD_DrawRect(712 + 5, (368 + 13 - press2 * 2.6), 44, (press2 * 2.6), color);
}



void updata_DCDY(unsigned int x, unsigned int y) {
    //unsigned char color = GREEN;
    unsigned int DCDY = 50;
    DCDY = DC_voltage * 0.1;
 
    if (DCDY >= 800) DCDY = 800;
    print_SZ_1(x, y, (DCDY), 3, 0, WHITE); //电池电压数值 x=120+72+30   y=150+60-2
    if (frmID == 0)
        LCD_DrawRect(225 + 2, 100+13 + 5 + 2, ((DCDY) * 3.31 * 0.125), 28, GREEN); // 331/100  

}

void updata_DCDL(unsigned int x, unsigned int y) {
    unsigned int DCDL = 100;
    DCDL = DC_current * 0.1;

        if (DCDL < 500) {
        DCDL = 500 - DCDL;
        if (DCDL > 500) DCDL = 500;
        print_SZ_1(x, y, DCDL, 3, 0, WHITE);
        LCD_DrawImage1BPPZOOM_4(x - 20, y + 4, BMP_FU, WHITE, BLACK);
        if (DCDL > 0 && frmID == 0)
            LCD_DrawRect((225 + 2 + 164 - DCDL * 1.64 * 0.2), 100+13 + 5 + 2 + 60 - 5, (DCDL * 1.64 * 0.2 + 1), 28, GREEN);
        if (DCDL < 500 && frmID == 0) {
            LCD_DrawRect(225 + 2, 100+13 + 5 + 2 + 60 - 5, (164 - DCDL * 1.64 * 0.2), 28, BLACK); // 165/100         
            LCD_DrawRect(225 + 83 + 83 + 2, 100 +13+ 5 + 2 + 60 - 5, 165, 28, BLACK);
        }
    } else {
        DCDL = DCDL - 500;
        if (DCDL > 500) DCDL = 500;
        LCD_DrawImage1BPPZOOM_4(x - 20, y + 4, BMP_ZHENG, WHITE, BLACK);
        print_SZ_1(x, y, DCDL, 3, 0, WHITE);
        if (DCDL > 3 && frmID == 0)
            LCD_DrawRect(225 + 83 + 83 + 2, 100 +13+ 5 + 2 + 60 - 5, (DCDL * 1.65 * 0.2), 28, GREEN); // 如果长度为0，会出错
        if (DCDL < 500 && frmID == 0) {
            LCD_DrawRect((225 + 83 + 83 + 2 + DCDL * 1.65 * 0.2), 100 +13+ 5 + 2 + 60 - 5, (165 - DCDL * 1.65 * 0.2), 28, BLACK);
            LCD_DrawRect(225 + 2, 100 +13+ 5 + 2 + 60 - 5, 164, 28, BLACK);
        }
    }
    
}

void updata_SOC(void) {
    unsigned char color = WHITE;
    unsigned char soc = 100;
    soc = DC_SOC ;// 0.4;
    if (soc >= 100) soc = 100;
    
    //if (soc > 25) color = GREEN;
    //else if (soc > 0 && soc <= 25) color = RED;
    //else color = BLACK;
    
    if(soc>0){
       if(DC_Status[1]&0x80)color = RED;
       else                 color = GREEN;   
    }else                   color = BLACK;
    print_SZ_1(585, 100 + 13 + 5 + 60 + 60 - 10, soc, 3, 0, WHITE); //SOC数值
    LCD_DrawRect(225 + 2, 100 + 13 + 5 + 60 + 60 + 2 - 10, (soc * 3.31), 28, color); // 331/100  
    if (soc < 100)//当soc为100时会出错//此时函数溢出
        LCD_DrawRect((225 + 2 + soc * 3.31), 100 + 13 + 5 + 60 + 60 + 2 - 10, (331 - soc * 3.31), 28, BLACK);
}
*/

void disp_LOGO(void){
x=400;y=240;
  lcd_show_8dot(x-80,   y-81,  Bmp_LOGO,  WHITE,BLACK);//中通LOGO
}

void disp_Door(void){
  unsigned char color;
  if(T_KH1) color=RED;else  color=BLACK;
  lcd_show_8dot5(155-16+61,25-18,Bmp_TB_door,color,BLACK);//门1
  lcd_show_8dot (185-16+61+2,25-18+20, BMP_SZ[1],color,BLACK);

  if(T_KL15) color=RED; else color=BLACK; 
  lcd_show_8dot5(216-16+61,25-18, Bmp_TB_door,color,BLACK);//门2
  lcd_show_8dot (246-16+61+2,25-18+20, BMP_SZ[2],color,BLACK);
}

//车身中心位置
  unsigned int X=400-478/2;
//unsigned int Y=182-140/2;   //有柱状SOC
  unsigned int Y=242-140/2;//无柱状SOC

//显示车子
void disp_CAR(void){
   unsigned int  x,y;
  x=15-15;y=25-15;
  lcd_show_8dot(X+x, Y+y,  Bmp_CAR1, WHITE, BLACK); //
  x=15-15;y=110-15;
  lcd_show_8dot(X+x, Y+y,  Bmp_CAR2, WHITE, BLACK); //
  x=130-22;y=121-18;
  lcd_show_8dot(X+x, Y+y,  Bmp_CAR3, WHITE, BLACK); //
  x=342-22;y=121-18;
  lcd_show_8dot(X+x, Y+y,  Bmp_CAR3, WHITE, BLACK); //
  x=463-15;y=110-15;
  lcd_show_8dot(X+x, Y+y,  Bmp_CAR4, WHITE, BLACK); //
  x=456-22;y=34-24;
  lcd_show_8dot(X+x, Y+y,  Bmp_CAR5, WHITE, BLACK); //
  x=420-11;y=46-15;
  lcd_show_8dot(X+x, Y+y,  Bmp_CAR6, WHITE, BLACK); //
  x=407-24;y=69-6;
  lcd_show_8dot(X+x, Y+y,  Bmp_CAR7, WHITE, BLACK); //
  x=363-20;y=58-5;
  lcd_show_8dot(X+x, Y+y,  Bmp_CAR8, WHITE, BLACK); //
 //车身其他线条
 //左车顶   
  x=30;y=10;    
  lcd_show_1color(X+x, Y+y,26,2,WHITE);//-
  x=56;y=0;    
  lcd_show_1color(X+x, Y+y,2,11,WHITE);//|
  lcd_show_1color(X+x, Y+y,24,2,WHITE);//-
  x=80;y=0;    
  lcd_show_1color(X+x, Y+y,2,10,WHITE);//|
  x=80;y=10;    
  lcd_show_1color(X+x, Y+y,259,2,WHITE);//-
  //右车顶
  x=339;y=0;    
  lcd_show_1color(X+x, Y+y,2,10,WHITE);//|   
  lcd_show_1color(X+x, Y+y,24,2,WHITE);//-
  x=362;y=0;    
  lcd_show_1color(X+x, Y+y,2,10,WHITE);//|
  x=362;y=10;    
  lcd_show_1color(X+x, Y+y,72,2,WHITE);//-
  //第二行
  x=30;y=20-1;    
  lcd_show_1color(X+x, Y+y,404,2,WHITE);//-
  //第三行
  x=0;y=52;    
  lcd_show_1color(X+x, Y+y,199,2,WHITE);//-
  x=247;y=52;    
  lcd_show_1color(X+x, Y+y,95,2,WHITE);//-
  //第四行
  x=30;y=125-2;    
  lcd_show_1color(X+x, Y+y,78,2,WHITE);//-
  x=152;    
  lcd_show_1color(X+x, Y+y,168,2,WHITE);//-
  x=364;    
  lcd_show_1color(X+x, Y+y,84,2,WHITE);//-
  //左竖
  x=0;y=40;    
  lcd_show_1color(X+x, Y+y,2,55,WHITE);//|
  //右竖
  x=478-2;y=57;    
  lcd_show_1color(X+x, Y+y,2,38,WHITE);//|
/*
  //后门
  x=199;y=31;    
  lcd_show_1color(X+x, Y+y,48,2,WHITE);//-
  lcd_show_1color(X+x, Y+y,2,88,WHITE);//|
  x=199+48-2;y=31;    
  lcd_show_1color(X+x, Y+y,2,88,WHITE);//|
  x=199;y=31+88-2;
  lcd_show_1color(X+x, Y+y,48,2,WHITE);//-

  //前门
  x=383;y=31;    
  lcd_show_1color(X+x, Y+y,27,2,WHITE);//-
  lcd_show_1color(X+x, Y+y,2,88,WHITE);//|
  x=383+48-2;y=31+30;    
  lcd_show_1color(X+x, Y+y,2,58,WHITE);//|
  x=383;y=31+88-2;
  lcd_show_1color(X+x, Y+y,48,2,WHITE);//-

*/

x=51-40;y=79-9;
//lcd_show_8dot(X+x,   Y+y,  Bmp_XShi1,  WHITE,BLACK);//续驶
//lcd_show_8dot(X+x+40,Y+y,  Bmp_LCheng,WHITE,BLACK);//里程
  lcd_show_8dot(X+x,   Y+y,  Bmp_NSYWei,  WHITE,BLACK);//续驶
x=176-12;
  //lcd_show_8dot(X+x, Y+y,  Bmp_Km,  WHITE,BLACK);//单位 Km
  lcd_show_8dot(X+x, Y+y,  Bmp_bfh,  WHITE,BLACK);//单位 %
x=276-16;
  //lcd_show_8dot(X+x, Y+y,  Bmp_SOC, WHITE, BLACK);//SOC
x=364-8;
  //lcd_show_8dot(X+x, Y+y,  Bmp_bfh, WHITE, BLACK);//%

}


//*************************************************
//功能：显示气压柱 格式 
//*************************************************
void QY_frame(void){
 unsigned int x=30,y=75;
//气压1
 lcd_show_1color(x,y-1,   2,146,WHITE);//左边框白色   长度50
 lcd_show_1color(x,y+146, 2,124,RED) ;//左边框红色    长度72

 lcd_show_1color(x+62,y-1,   2,146,WHITE);//右边框白色   长度50
 lcd_show_1color(x+62,y+146, 2,124,RED) ;//右左边框红色    长度72

 lcd_show_1color(x,y-3,  64,2,WHITE);//上边框白色   长度50
 lcd_show_1color(x,y+268,64,2,RED) ;//下边框红色    长度50 

//标尺
 x=26;
 lcd_show_8dot(x-18,y-5,BMP_SZ[1],WHITE,BLACK);//1
 lcd_show_8dot(x-9,y-5, BMP_SZ[2],WHITE,BLACK);//0
 lcd_show_8dot(x-9,y+146-5,BMP_SZ[6],RED,BLACK);//6
 lcd_show_8dot(x-9,y+260,  BMP_SZ[0],RED,BLACK);//0
 

//气压2
 x=710;
 lcd_show_1color(x,y-1,   2,146,WHITE);//左边框白色   长度50
 lcd_show_1color(x,y+146, 2,124,RED) ;//左边框红色    长度72

 lcd_show_1color(x+62,y-1,   2,146,WHITE);//左边框白色   长度50
 lcd_show_1color(x+62,y+146, 2,124,RED) ;//左边框红色    长度72

 lcd_show_1color(x,y-3,  64,2,WHITE);//上边框白色   长度50
 lcd_show_1color(x,y+268,64,2,RED) ;//下边框红色    长度50 

//标尺
 x=779;
 lcd_show_8dot(x,y-5,BMP_SZ[1],WHITE,BLACK);//1
 lcd_show_8dot(x+9,y-5,BMP_SZ[2],WHITE,BLACK);//0

 lcd_show_8dot(x,y+146-5,BMP_SZ[6],RED,BLACK);//6
 lcd_show_8dot(x,y+260,BMP_SZ[0],RED,BLACK);//0

 lcd_show_8dot(38,350,Bmp_QY,RED,BLACK);//气压1图标
 lcd_show_8dot(38+16,345+15,BMP_SZ_3[1],RED,BLACK);
 lcd_show_8dot(66,398,Bmp_MPa,WHITE,BLACK);

 lcd_show_8dot(718,350,Bmp_QY,RED,BLACK);//气压2图标
 lcd_show_8dot(718+16,345+15,BMP_SZ_3[2],RED,BLACK);

 lcd_show_8dot(696+62,398,Bmp_MPa,WHITE,BLACK);
}


void updata_QY(unsigned char id){
 unsigned int old_value1=0;
 static unsigned int old_value2=0;
 static unsigned int old_value3=0;
 unsigned char color=RED;
 unsigned int value;
 unsigned int i,temp=0,x;  

  if(id==1){
    //temp=ADV[6]/10;  
      //temp=fADR[0]/10;
      temp = ADR[2];
    x=30;old_value1=old_value2;    
  }else if(id==2){
    //temp=ADV[5]/10;
      //temp=fADR[1]/10;
      temp = ADR[1];
    x=710;old_value1=old_value3;
  }else {
    temp=0; x=30;
  }
  //电压式0.5-3.5V
//     if(temp>350){temp=350;value=12;}
//else if(temp<=50){temp=50; value=0; }
//else                       value=(unsigned char)((0.4*(temp-50)+4)/10); //大于0.6 时进为1 

  //电阻式
       if(temp>184) {temp=184; value=10;}
  else if(temp<=10) {temp=10;  value=0; }
  else                         value=(unsigned char)(0.05747*(temp-10)); 
  //气压柱加软件阻尼，更新满量程大概需要12秒
  if(value>old_value1){
     old_value1++;
  }else if(value<old_value1){    
     old_value1--;
  }else{
    old_value1=value;
  }  
  if(id==1){old_value2=old_value1;}//
  if(id==2){old_value3=old_value1;}

  for(i=0;i<12;i++){
    if(i>=old_value1)color=0;
    else{
      if(old_value1>=6) color=GREEN;
      else              color=RED;
    }
    lcd_clear_8dot(x+4,(322-(22*i)),56,15,color); //704
  }
  if(id==2)x=719;
//电压式0.5-3.5v
//print_SZ_2(x-25,395,(unsigned int)(0.4*(temp-50)),3,2,WHITE); 
//电阻式
  print_SZ_2(x-25,395,(unsigned int)(0.575*(temp-10)),3,2,WHITE); //685
}


void mainFrame(void) {
    unsigned int i;
    LCD_Clear();
    LCD_DrawRect(0, 430, 800, 2, GRAY);//底部横线
    LCD_DrawRect(0, 0,   800, 1, GRAY);//上横线
    LCD_DrawRect(0, 50,  800, 1, GRAY);//下横线
    
    /*
    LCD_DrawRect(70+66,100,528,1,GRAY);//第二横线   
    for (i = 1; i < 12; i++) {
        LCD_DrawRect(4 +  66 * i, 0, 1, 50, GRAY);//竖线
    }
    for(i=1;i<10;i++)
        LCD_DrawRect(70+66*i,50,1,50,GRAY);//竖线
    */
    
    LCD_DrawRect(122,100,550,1,GRAY);//第二横线
    for(i=1;i<13;i++)
    LCD_DrawRect(61*i,0,1,50,GRAY);//竖线

    for(i=2;i<12;i++)
    LCD_DrawRect(61*i,50,1,50,GRAY);//竖线

   
    //每次进入主界面，符号片颜色都是灰色，若不处理，只会第一次上电显示灰色，翻页后就不显示灰色
    for (i = 0; i < 24; i++) {
        color_old[i] = 1;
    }
    
//LCD_DrawImage1BPPZOOM_4(336, 150, BMP_LOGO, BLUE, BLACK); //客车车标

/*    
x=161;y=265;
   for(i=1;i<5;i++){
   lcd_show_1color(x,y+i*30,478, 1,GRAY);//-
   }
x=161;y=y+30;
   lcd_show_1color(x,y,1, 90,GRAY);//|左
x=391+9;
   lcd_show_1color(x,y,1, 90,GRAY);//|中
x=639;
   lcd_show_1color(x,y,1, 90,GRAY);//|右
*/

//显示里程
x=221-58;y=407-9;
    LCD_DrawImage1BPP(x,   y,Bmp_TRIP,  WHITE,BLACK);//单次
    LCD_DrawImage1BPP(x+40,y,Bmp_LCheng,WHITE,BLACK);//里程     
x=440-40; 
    LCD_DrawImage1BPP(x,   y,Bmp_ODO,   WHITE,BLACK);//总计 
    LCD_DrawImage1BPP(x+40,y,Bmp_LCheng,WHITE,BLACK);//里程
x=369-12;   
    LCD_DrawImage1BPP(x,   y,Bmp_Km,    WHITE,BLACK);//单位 Km  
x=617-12;      
    LCD_DrawImage1BPP(x,   y,Bmp_Km,    WHITE,BLACK);//单位 Km
     
    
}

void update_dc2(void){
   unsigned char color=0,s=0;
   unsigned int  temp;
   unsigned int  x,y;
 //unsigned char i,j;
/////////////第一列/////////////

//车身内部SOC
  x=326-24;y=79-9;
  //print_SZ_2(X+x, Y+y,(0.4*DC_SOC),3,0,color); // 

  //后门
  if(T_KL15)color=RED;else color=WHITE;
  x=199;y=31;    
  lcd_show_1color(X+x, Y+y,48,2,color);//-
  lcd_show_1color(X+x, Y+y,2,88,color);//|
  x=199+48-2;y=31;    
  lcd_show_1color(X+x, Y+y,2,88,color);//|
  x=199;y=31+88-2;
  lcd_show_1color(X+x, Y+y,48,2,color);//-
  if(T_KL15)color=BLACK;else color=WHITE;
  x=199+2;y=61;
  lcd_show_1color(X+x, Y+y,44,2,color);//-
  x=199+24-1;y=31+2;
  lcd_show_1color(X+x, Y+y,2,84,color);//|

  //前门
  if(T_KH1)color=BLACK;else color=WHITE;  
  x=407-24;y=69-6;
  if (color_old[4] != color) {
      color_old[4]  = color;
  lcd_show_8dot5(X+x, Y+y,  Bmp_CAR7, color, BLACK); //
  }  
  
  if(T_KH1)color=RED;else color=WHITE;
  x=383;y=31;    
  lcd_show_1color(X+x, Y+y,27,2,color);//-
  lcd_show_1color(X+x, Y+y,2,88,color);//|
  x=383+48-2;y=31+30;    
  lcd_show_1color(X+x, Y+y,2,58,color);//|
  x=383;y=31+88-2;
  lcd_show_1color(X+x, Y+y,48,2,color);//-
  x=420-11;y=46-15;
  lcd_show_8dot(X+x, Y+y,  Bmp_CAR6, color, BLACK); //

  //后仓门
  if(0)color=RED;else color=BLACK;
  x=24;y=66-14;
  lcd_show_8dot5(X-x, Y+y,  Bmp_CAR9, color, BLACK); //

//续驶里程
  x=131-24;y=79-9;
  //temp=XHLC*5; 
  //if(temp>=1000)temp=999;
  //print_SZ_2(X+x, Y+y,temp,3,0,WHITE);
//尿素液位
  x=131-24;y=79-9;
  print_SZ_2(X+x, Y+y,ADBLUE,3,0,WHITE); 
}

void disp_baojing(void){
  unsigned char color=GRAY;
  //unsigned int  temp;
  
  if(  IN26 || IN25 )    color=RED;
  else             color=GRAY; 
  LCD_DrawImage1BPP(30-20,5,Bmp_yjf,color,BLACK);//前门应急阀开启报警开关 
  
  if(!IN28)color=RED;//左前 
  else      color=GRAY; 
  if (color_old[0] != color) {
      color_old[0]  = color;
  LCD_DrawImage1BPP(91-24,25-18,Bmp_mcp, color,BLACK);//蹄片磨损
  LCD_DrawImage1BPP(91-10, 25-6, Bmp_mcpL,color,BLACK);//L
  LCD_DrawImage1BPP(91+2,25-7,BMP_SZ[1],color,BLACK);
  }
 
  if(!IN21)color=RED;//左后
  else      color=GRAY; 
  if (color_old[1] != color) {
      color_old[1]  = color;
  LCD_DrawImage1BPP(152-24,25-18,Bmp_mcp, color,BLACK);//蹄片磨损
  LCD_DrawImage1BPP(152-10, 25-6, Bmp_mcpL,color,BLACK);//L
  LCD_DrawImage1BPP(152+2,25-7,BMP_SZ[2],color,BLACK);
  }
  
  if(IN4) color=RED;else  color=GRAY;
  lcd_show_8dot5(155-16+61,25-18,Bmp_TB_door,color,BLACK);//门1
  lcd_show_8dot (185-16+61,25-18+20, BMP_SZ[1],color,BLACK);

  if(IN3) color=RED; else color=GRAY; 
  lcd_show_8dot5(216-16+61,25-18, Bmp_TB_door,color,BLACK);//门2
  lcd_show_8dot (246-16+61,25-18+20, BMP_SZ[2],color,BLACK);
 
  if(  IN2 ) color=RED;
  else          color=GRAY; 
  LCD_DrawImage1BPP(330-20,20-19,Bmp_HCM,color,BLACK);//后舱门    
  
  if(M_ON &&(ADBLUE<20)){
     if((ADBLUE<10) && F500ms_LCD)color=GRAY;else color=BLUE; //FLASH
  }else color=GRAY;
  LCD_DrawImage1BPP(396-20,25-20 ,Bmp_ADBLUE, color, BLACK); //

  if(SCR_DM1_double){
      if((SCR_DM2&0x30)==0x10)delay_2s=200;
      if(delay_2s>0)if(F500ms_LCD)color=RED;else color=GRAY; //SCR后处理 红色闪烁
      else          if((SCR_DM2&0x0c)==0x04)color=RED;else color=GRAY; //SCR后处理 黄色长亮
  }else{
      if((SCR_DM1&0x30)==0x10)delay_2s=200;
      if(delay_2s>0)if(F500ms_LCD)color=RED;else color=GRAY; //SCR后处理 红色闪烁
      else          if((SCR_DM1&0x0c)==0x04)color=RED;else color=GRAY; //SCR后处理 黄色长亮
  }
  LCD_DrawImage1BPP(457-15, 25-18,Bmp_SCR,color,BLACK);//

  if(IN6) color=GREEN;
  else    color=GRAY; 
  lcd_show_8dot(518-20,25-20,Bmp_xd,color,BLACK);//小灯
  
  if(IN20) color=YELLOW;   
  else     color=GRAY; 
  lcd_show_8dot5(580-20, 25-20,Bmp_klzs,color,BLACK);//空滤堵塞
  
  if(!IN27)color=RED; //右前
  else      color=GRAY; 
  if (color_old[2] != color) {
      color_old[2]  = color;
  LCD_DrawImage1BPP(640-24,25-18,Bmp_mcp, color,BLACK);//蹄片磨损
  LCD_DrawImage1BPP(640-10, 25-6, Bmp_mcpR,color,BLACK);//R
  LCD_DrawImage1BPP(640+2,25-7,BMP_SZ[1],color,BLACK);
  }
  
  if(!IN22)color=RED; //右后 
  else      color=GRAY; 
  if (color_old[3] != color) {
      color_old[3]  = color;
  LCD_DrawImage1BPP(702-24,25-18,Bmp_mcp, color,BLACK);//蹄片磨损
  LCD_DrawImage1BPP(702-10, 25-6, Bmp_mcpR,color,BLACK);//R
  LCD_DrawImage1BPP(702+2,25-7,BMP_SZ[2],color,BLACK);
  }
  
  if(  T_KL2 ) color=RED;
  else         color=GRAY; 
  //LCD_DrawImage1BPP(762-20,5,Bmp_yjf,color,BLACK);//后门应急阀开启报警开关
  
  
}

void disp_baojing2(void){
  unsigned char i,color=GRAY;
  unsigned char temp8=0;
  
  if(R_KL3)color=RED;//驻车储气筒气压低
  else    color=GRAY;  
  //LCD_DrawImage1BPP(152-24, 75-18,Bmp_TB_QY,color,BLACK);//  
  
  if(R_PO3&&((rpcur[2]/100)>10))color=YELLOW;  // 干燥器指示  电流判断
  else                          color=GRAY; 
  //lcd_show_8dot(193,60,Bmp_TB_gzq,color,BLACK);//
  
  if(  IN17 ) color=RED;
  else         color=GRAY; 
  LCD_DrawImage1BPP(275-18,75-18,Bmp_SW,color,BLACK);//水位报警
  
  if(LED21)color=RED;else color=GRAY;
  lcd_show_8dot(384,62,Bmp_NRD[1],color,BLACK);//R  
  
  if(IN24) color = YELLOW; //ASR
  else     color = GRAY;  
  if (color_old[5] != color) {
      color_old[5]  = color;
  LCD_DrawImage1BPP(518-24, 75-18,Bmp_TB_SChe,color,BLACK);//
  LCD_DrawImage1BPP(518-12, 75-5,Bmp_TB_ASR,color,BLACK);//
  }
  
  if(IN23) color = YELLOW; //ABS
  else     color = GRAY;   
  if (color_old[6] != color) {
      color_old[6]  = color;
  LCD_DrawImage1BPP(579-24, 75-18,Bmp_TB_SChe,color,BLACK);//
  LCD_DrawImage1BPP(579-12, 75-5,Bmp_TB_ABS,color,BLACK);//
  }
  
  if(R_KL4)color=RED;//辅助气压低
  else     color=GRAY;  
  //LCD_DrawImage1BPP(640-24, 75-18,Bmp_TB_QY,color,BLACK);//  
  
}

void disp_miles(void) {//显示里程
x=333-32-16-16;y=407-9;
    print_SZ_2(x, y,single_miles , 4, 1, WHITE);
x=552-49-16;    
    print_SZ_2(x, y, total_miles / 10, 7, 0, WHITE);
}

void frmMain(void) {
  //unsigned char color;
    if (f_index == 0) { //只更新一次
        f_index = 1;
        mainFrame(); 
        disp_CAR();
        QY_frame();
    } else if (f_index == 1) {
        f_index = 2;
        //updata_QY();   
        update_dc2();
    } else if (f_index == 2) {
        f_index = 3;
        disp_baojing();
    } else if (f_index == 3) {
        f_index = 4;
        disp_miles();
        disp_baojing2();
    } else if (f_index == 4) {
        f_index = 5;
        //updata_DCDL(585, 105 + 13 + 60-5);
        updata_QY(1);
    } else if (f_index == 5) {
        f_index = 6;
        updata_QY(2);
        //updata_SOC();
    } else if (f_index == 6) {
        f_index = 7;
        //updata_DCDY(585, 105 + 13);//
    } else if (f_index == 7) {
        f_index = 1;      
    } else {
        f_index = 0;
    }

    if (AV_CH == 0) { //当在数字界面
        if (key_up) { //调节背光灯
            key_up = 0;
            if ((IN7 == 1) && (!time_flag) ) {//背光开启
                if (e_backlight >= 1000) e_backlight = 100;
                else e_backlight += 100;
                EEROM_WriteBackLight();
            }
        }

        if (key_set) {
            key_set = 0;
            key_long_set = 0;
            key_up = 0;
            key_AV = 0;
            key_duble = 0;
            f_index = 0;
            frmID = 1;

        }

        if (key_long_set) {
            key_long_set = 0;
            key_set = 0;
            key_up = 0;
            key_AV = 0;
        }

        if (key_AV) {
            key_AV = 0;
            key_long_set = 0;
            key_up = 0;
            key_set = 0;
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

//显示 接口编号
///////////////////////////////////////////////////////////
void disp_ID(unsigned char index,unsigned int *ptr){
  unsigned int j=0,i=0;
  for(j=0;j<2;j++){
    LCD_DrawImage1BPP(20+j*420, 65, Bmp_interface,WHITE,BLACK);//接口
   if(index){  //
    LCD_DrawImage1BPP(300+j*420,65,Bmp_ZT,WHITE,BLACK);//状态
   }
   for(i=0;i<10;i++){
     if(*ptr==0)break;  //默认接口号为0时，编号结束，后边的不显示。
      print_SZ_2(22+j*420,93+34*i,*ptr++,2,0,WHITE); 
   }
  }
}
///////////////////////////////////////////////////////////
//显示汉字 "开关" 用于仪表信号输入 
//指针变量  显示的位置(x), x=0 不显示开关
///////////////////////////////////////////////////////////
void disp_kg(unsigned int *ptr){
  unsigned int j=0,i=0;
  for(j=0;j<2;j++){
    for(i=0;i<10;i++){
      if(*ptr==0)
        *ptr++;
      else 
      LCD_DrawImage1BPP(*ptr++,95+34*i,Bmp_kg,WHITE,BLACK);           
    }
  }
}

//显示雨刮 1
void disp_yg(unsigned int x,unsigned int y,unsigned int id){
  LCD_DrawImage1BPP(x,   y,Bmp_yuggua, WHITE,BLACK);
  LCD_DrawImage1BPP(x+40,y,Bmp_yg1[id],WHITE,BLACK);
}

//-----------------------------------------------
//更新显示仪表开关量 状态 
//参数： id 显示界面号
//-----------------------------------------------
void disp_KL1(void){
  unsigned int Iid[20]={4,3,2,1,5,6,7,8,9,10,
                        11,12,13,14,15,16,21,22,23,24};
  disp_ID(0,Iid); //显示编号
  x=80;y=95;
  LCD_DrawImage1BPP(x,y+0*34,Bmp_left,WHITE,BLACK);
  LCD_DrawImage1BPP(x+18,y+0*34,Bmp_KIN1,WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+1*34,Bmp_KIN2,WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+2*34,Bmp_KIN3,WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+3*34,Bmp_KIN4,WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+4*34,Bmp_right,WHITE,BLACK);
  LCD_DrawImage1BPP(x+18,y+4*34,Bmp_KIN5,WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+5*34,Bmp_KIN6,WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+5*34,Bmp_Jing,WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+6*34,Bmp_KIN7,WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+7*34,Bmp_front,WHITE,BLACK);
  LCD_DrawImage1BPP(x+18,y+7*34,Bmp_KIN8,WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+8*34,Bmp_rear,WHITE,BLACK);
  LCD_DrawImage1BPP(x+18,y+8*34,Bmp_KIN9,WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+9*34,Bmp_KIN10,WHITE,BLACK);
  LCD_DrawImage1BPP(x+40,y+9*34,Bmp_top,WHITE,BLACK);
  LCD_DrawImage1BPP(x+58,y+9*34,Bmp_Deng,WHITE,BLACK);
  
//第二列 
  x=500;y=95;
  LCD_DrawImage1BPP(x,y+0*34,Bmp_KIN11,WHITE,BLACK); print_SZ_2(x+40,y+0*34,1,1,0,WHITE); 
  LCD_DrawImage1BPP(x,y+1*34,Bmp_KIN12,WHITE,BLACK); print_SZ_2(x+40,y+1*34,2,1,0,WHITE); 
  LCD_DrawImage1BPP(x,y+2*34,Bmp_KIN13,WHITE,BLACK);
  
  disp_yg(x,y+3*34,Bmp_KIN14);
  disp_yg(x,y+4*34,Bmp_KIN15);
  disp_yg(x,y+5*34,Bmp_KIN16);  
  
  LCD_DrawImage1BPP(x,y+6*34,Bmp_KIN17,WHITE,BLACK);// 
  LCD_DrawImage1BPP(x+58,y+6*34,Bmp_Deng,WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+7*34,Bmp_KIN18,WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+8*34,Bmp_KIN19,WHITE,BLACK);// 
  LCD_DrawImage1BPP(x,y+9*34,Bmp_KIN20,WHITE,BLACK);//
  
  unsigned int Iid1[20]={136,0,0,136,136,136,120,136,136,160,
                         558,558,540,580,580,580,580,540,0,0};
  disp_kg(Iid1);  //显示开关
}
//显示仪表开关2
void disp_KL2(void){
  unsigned int Iid[20]={17,18,19,20,28,27,26,25,32,31,
                         30,29,1,2,3,4,5,10,20,13};
  disp_ID(0,Iid); //显示编号
  x=80;y=95;
  disp_yg(x,y+0*34,Bmp_KIN21);
 
  LCD_DrawImage1BPP(x,y+1*34,Bmp_KIN22,WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+2*34,Bmp_KIN23,WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+3*34,Bmp_KIN24,WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+4*34,Bmp_KIN25,WHITE,BLACK); 
  LCD_DrawImage1BPP(x,y+5*34,Bmp_KIN26,WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+6*34,Bmp_KIN27,WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+7*34,Bmp_KIN28,WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+8*34,Bmp_KIN29,WHITE,BLACK);
  LCD_DrawImage1BPP(x+40,y+8*34,Bmp_Deng,WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+9*34,Bmp_KIN30,WHITE,BLACK);

//第二列 
  x=500;y=95;
  LCD_DrawImage1BPP(x,y+0*34,Bmp_KIN31,WHITE,BLACK); 
  LCD_DrawImage1BPP(x,y+1*34,Bmp_KIN32,WHITE,BLACK); 
  LCD_DrawImage1BPP(x,y+2*34,Bmp_KIN33,WHITE,BLACK); 
  LCD_DrawImage1BPP(x,y+3*34,Bmp_KIN34,WHITE,BLACK); 
  LCD_DrawImage1BPP(x,y+3*34,Bmp_ASR1,WHITE,BLACK);   
  
  LCD_DrawImage1BPP(x,y+4*34,Bmp_KIN35,WHITE,BLACK);
  LCD_DrawImage1BPP(x+70,y+4*34,Bmp_DBR,WHITE,BLACK);
  LCD_DrawImage1BPP(x+100,y+4*34,Bmp_adr,WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+5*34,Bmp_KIN36,WHITE,BLACK); 
  LCD_DrawImage1BPP(x,y+6*34,Bmp_KIN37,WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+7*34,Bmp_KIN38,WHITE,BLACK);  
  LCD_DrawImage1BPP(x+40,y+7*34,Bmp_bj,WHITE,BLACK);  
  
  LCD_DrawImage1BPP(x,y+8*34,Bmp_KIN39,WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+9*34,Bmp_KIN40,WHITE,BLACK);
  
  unsigned int Iid1[20]={160,120,136,136,0,0,0,0,136,178,
                         0,0,574,610,638,0,0,580,574,558,};
  disp_kg(Iid1);  //显示开关
}

//显示仪表传感器信号
void disp_ADR(void){ 
 unsigned int  j=0,i=0;
 unsigned char Iid[2][8]={ {8,7,6,5,4,3,2,1},      
                           {15,10,9,14,13,0,0,0  } };//插件顺序是右-左 主要适用于使用新定义的公司
 
  for(j=0;j<2;j++){
      LCD_DrawImage1BPP(20+j*420, 65, Bmp_interface,WHITE,BLACK);//接口      
   for(i=0;i<8;i++){
     if(Iid[j][i]==0)break;  //默认接口号为0时，编号结束，后边的不显示。 
      print_SZ_2(20+j*420,95+34*i,Iid[j][i],2,0,WHITE);       
   }
  }  
    
     LCD_DrawImage1BPP(20+420,95+5*34,Bmp_cxbb,WHITE,BLACK);  //程序版本
     print_SZ_2(20+420,95+6*34,                Version_date,8,0,YELLOW);//时间
     LCD_DrawImage1BPP(20+420+128,95+6*34,Bmp_V,WHITE,BLACK);//A
     print_SZ_2(20+420+128+16,95+6*34,          Version,3,2,YELLOW);//2.00 
 
//100 120   
     x=80+20,y=95;

     LCD_DrawImage1BPP(x+20,y+0*34,Bmp_SER1, WHITE,BLACK);
     LCD_DrawImage1BPP(x+20,y+1*34,Bmp_SER2, WHITE,BLACK);
     LCD_DrawImage1BPP(x+20,y+2*34,Bmp_SER3, WHITE,BLACK);
     LCD_DrawImage1BPP(x+20,y+3*34,Bmp_SER4, WHITE,BLACK);
     
   //LCD_DrawImage1BPP(x,   y+4*34,Bmp_rear,WHITE,BLACK);  
     LCD_DrawImage1BPP(x+20,y+4*34,Bmp_SER5, WHITE,BLACK);
     
   //LCD_DrawImage1BPP(x,   y+5*34,Bmp_front, WHITE,BLACK); 
     LCD_DrawImage1BPP(x+20,y+5*34,Bmp_SER6, WHITE,BLACK); 
     
     LCD_DrawImage1BPP(x+20,y+6*34,Bmp_FREQ1,WHITE,BLACK);
     LCD_DrawImage1BPP(x+20,y+7*34,Bmp_FREQ2,WHITE,BLACK);

   for(i=0;i<8;i++){
     LCD_DrawImage1BPP(x+60,y+i*34,Bmp_adr,WHITE,BLACK);

    if(i<2)
     LCD_DrawImage1BPP(x+170,y+i*34,Bmp_R, WHITE,BLACK); 
    else  if(i<4)
     LCD_DrawImage1BPP(x+170,y+i*34,Bmp_V,WHITE,BLACK);       
    else  if(i<5)
     LCD_DrawImage1BPP(x+170,y+i*34,Bmp_R, WHITE,BLACK); 
    else  if(i<6)
     LCD_DrawImage1BPP(x+170,y+i*34,Bmp_V, WHITE,BLACK); 
    else 
     LCD_DrawImage1BPP(x+170,y+i*34,Bmp_Hz,WHITE,BLACK);       
    
    }

     LCD_DrawImage1BPP(500,y,Bmp_DY,WHITE,BLACK); 
     LCD_DrawImage1BPP(620,y,Bmp_V, WHITE,BLACK); 

  //CAN 接口
  for(i=0;i<2;i++){
     LCD_DrawImage1BPP(500,y+(i+1)*34,Bmp_MK, WHITE,BLACK); 
     LCD_DrawImage1BPP(500,y+(i+3)*34,Bmp_ECU,WHITE,BLACK); 

     LCD_DrawImage1BPP(540,y+34+(i)*68,Bmp_CAN,WHITE,BLACK); 
     LCD_DrawImage1BPP(540+30,y+34+(i)*68,Bmp_Gao,WHITE,BLACK);  
     LCD_DrawImage1BPP(540,y+(i+1)*68,Bmp_CAN,WHITE,BLACK);
     LCD_DrawImage1BPP(540+30,y+(i+1)*68,Bmp_di,WHITE,BLACK); 
  }
}

//模块端口状态 显示
//固定位置显示 励磁电流 和CAN状态
void disp_can(void){
     LCD_DrawImage1BPP(500,265,Bmp_LCDL,WHITE,BLACK); 
     LCD_DrawImage1BPP(540,265,Bmp_dl,  WHITE,BLACK); 

     LCD_DrawImage1BPP(500,299,Bmp_CAN,WHITE,BLACK);
     LCD_DrawImage1BPP(530,299,Bmp_Gao,WHITE,BLACK);
     
     LCD_DrawImage1BPP(500,333,Bmp_CAN,WHITE,BLACK); 
     LCD_DrawImage1BPP(530,333,Bmp_di,WHITE,BLACK); 
     
     LCD_DrawImage1BPP(20+420,    95+8*34,Bmp_cxbb,WHITE,BLACK);//程序版本 
   //LCD_DrawImage1BPP(20+420+128,95+8*34,Bmp_V,   WHITE,BLACK);//A 
     
}

void disp_ADD(unsigned char id){
  unsigned int i=0,s[2]={0,0};
  if(id==1){ 
   s[0]=0;s[1]=0;
  }else if(id==2){
   s[0]=1;s[1]=0;
  }else if(id==3){
   s[0]=0;s[1]=1;
  }else if(id==4){
    s[0]=1;s[1]=1;
  }else{
    s[0]=0;s[1]=0;
  }
  for(i=0;i<2;i++){
    LCD_DrawImage1BPP(500,163+i*34,Bmp_ADD,WHITE,BLACK);          //KL13，KL14做地址
    LCD_DrawImage1BPP(558,163+i*34,Bmp_ADDst[s[i]],WHITE,BLACK);
  }
 //显示信号量 备用信号
  for(i=0;i<3;i++){
    LCD_DrawImage1BPP(524,333+i*34,Bmp_KL, WHITE,BLACK);
    LCD_DrawImage1BPP(566,333+i*34,Bmp_adr,WHITE,BLACK);
   if(i==2)
    LCD_DrawImage1BPP(690,333+i*34,Bmp_Hz, WHITE,BLACK);
   else
    LCD_DrawImage1BPP(690,333+i*34,Bmp_R,  WHITE,BLACK);    
  }
}

//前部模块 电源
void disp_front_load(void){
   unsigned int Iid[20]={1,9,2,10,3,11,4,12,5,13,
                         6,14,7,42,8,17,16,31,0,0};
  disp_ID(1,Iid); //显示编号
  disp_can();
//第一列
  x=80;y=95;
  disp_yg(x,y+0*34,0);//10,18,Bmp_front_load1,WHITE,0x0000);
  LCD_DrawImage1BPP(x+80,y+0*34,Bmp_dj,WHITE,BLACK);  

  disp_yg(x,y+1*34,1);//10,18,Bmp_front_load2,WHITE,0x0000); 
  LCD_DrawImage1BPP(x+80,y+1*34,Bmp_dj,WHITE,BLACK);  
 
  disp_yg(x,y+2*34,2);//10,18,Bmp_front_load3,WHITE,0x0000);
  LCD_DrawImage1BPP(x+80,y+2*34,Bmp_dj,WHITE,BLACK); 
  
  LCD_DrawImage1BPP(x,y+3*34,Bmp_front_load4, WHITE,BLACK);//
  LCD_DrawImage1BPP(x,y+3*34,Bmp_Jing, WHITE,BLACK);//
  
  LCD_DrawImage1BPP(x,y+4*34,Bmp_front_load5, WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+5*34,Bmp_front, WHITE,BLACK);//
  LCD_DrawImage1BPP(x+18,y+5*34,Bmp_front_load6, WHITE,BLACK);//
  
  LCD_DrawImage1BPP(x,y+6*34,Bmp_front_load7, WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+7*34,Bmp_front_load8, WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+7*34,Bmp_Jing, WHITE,BLACK);//
  
  LCD_DrawImage1BPP(x,y+8*34,Bmp_left, WHITE,BLACK); 
  LCD_DrawImage1BPP(x+18,y+8*34,Bmp_front_load9, WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+9*34,Bmp_front_load10,WHITE,BLACK);//
  
//第二列
  x=500;y=95;
  LCD_DrawImage1BPP(x,y+0*34,Bmp_front_load11,WHITE,BLACK);
  LCD_DrawImage1BPP(x+58,y+0*34,Bmp_dy,WHITE,BLACK);
    
  LCD_DrawImage1BPP(x,y+1*34,Bmp_front,WHITE,BLACK);//
  LCD_DrawImage1BPP(x+18,y+1*34,Bmp_front_load12,WHITE,BLACK);
  LCD_DrawImage1BPP(x+58,y+1*34,Bmp_Door,WHITE,BLACK);//
  LCD_DrawImage1BPP(x+76,y+1*34,Bmp_dy,WHITE,BLACK);//
  
  LCD_DrawImage1BPP(x,y+2*34,Bmp_rear,WHITE,BLACK);//
  LCD_DrawImage1BPP(x+18,y+2*34,Bmp_front_load13,WHITE,BLACK);//
  LCD_DrawImage1BPP(x+58,y+2*34,Bmp_Door,WHITE,BLACK);//
  LCD_DrawImage1BPP(x+76,y+2*34,Bmp_dy,WHITE,BLACK);//
  
  LCD_DrawImage1BPP(x,y+3*34,Bmp_left,WHITE,BLACK);//
  LCD_DrawImage1BPP(x+18,y+3*34,Bmp_front,WHITE,BLACK);//
  LCD_DrawImage1BPP(x+36,y+3*34,Bmp_front_load14,WHITE,BLACK);//
  
  LCD_DrawImage1BPP(x,y+4*34,Bmp_right,WHITE,BLACK);//
  LCD_DrawImage1BPP(x+18,y+4*34,Bmp_front,WHITE,BLACK);//
  LCD_DrawImage1BPP(x+36,y+4*34,Bmp_front_load15,WHITE,BLACK);//
  
  
}

//前部模块开关信息
void disp_front_KL(void){
  unsigned int Iid[20]={32,18,33,19,34,20,35,21,36,22,
                        37,23,38,24,39,41,17,25,40,26};
  disp_ID(0,Iid);
//第一列
  x=80;y=95;
  LCD_DrawImage1BPP(x,y+0*34,Bmp_left, WHITE,BLACK);
  LCD_DrawImage1BPP(x+18,y+0*34,Bmp_front, WHITE,BLACK);
  LCD_DrawImage1BPP(x+36,y+0*34,Bmp_FKL1, WHITE,BLACK);
  LCD_DrawImage1BPP(x+92,y+0*34,Bmp_bj, WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+1*34,Bmp_right, WHITE,BLACK);  
  LCD_DrawImage1BPP(x+18,y+1*34,Bmp_front, WHITE,BLACK); 
  LCD_DrawImage1BPP(x+36,y+1*34,Bmp_FKL2, WHITE,BLACK);
  LCD_DrawImage1BPP(x+92,y+1*34,Bmp_bj, WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+2*34,Bmp_FKL3, WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+3*34,Bmp_FKL4, WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+4*34,Bmp_left, WHITE,BLACK);
  LCD_DrawImage1BPP(x+18,y+4*34,Bmp_rear, WHITE,BLACK);
  LCD_DrawImage1BPP(x+36,y+4*34,Bmp_FKL5, WHITE,BLACK);
  LCD_DrawImage1BPP(x+92,y+4*34,Bmp_bj, WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+5*34,Bmp_FKL6, WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+6*34,Bmp_right, WHITE,BLACK);
  LCD_DrawImage1BPP(x+18,y+6*34,Bmp_rear, WHITE,BLACK);
  LCD_DrawImage1BPP(x+36,y+6*34,Bmp_FKL7, WHITE,BLACK);
  LCD_DrawImage1BPP(x+92,y+6*34,Bmp_bj, WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+7*34,Bmp_FKL8, WHITE,BLACK);print_SZ_2(x+40,y+7*34,1,1,0,WHITE);
  LCD_DrawImage1BPP(x+58,y+7*34,Bmp_bj, WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+8*34,Bmp_FKL9, WHITE,BLACK);print_SZ_2(x+40,y+8*34,2,1,0,WHITE);
  LCD_DrawImage1BPP(x+58,y+8*34,Bmp_bj, WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+9*34,Bmp_FKL10,WHITE,BLACK);
  
//第二列 
  x=500;y=95;
  LCD_DrawImage1BPP(x,y+0*34,Bmp_FKL11,WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+1*34,Bmp_FKL12,WHITE,BLACK);
  disp_ADD(1);// KL13 KL14 作为地址线
  LCD_DrawImage1BPP(x,y+4*34,Bmp_FKL15,WHITE,BLACK);
  disp_yg(x,y+5*34,4);
  LCD_DrawImage1BPP(x,y+6*34,Bmp_FKH1,WHITE,BLACK); 
  LCD_DrawImage1BPP(x+58,y+6*34,Bmp_cdian,WHITE,BLACK); 
  LCD_DrawImage1BPP(x+98,y+6*34,Bmp_ZShi,WHITE,BLACK); 
  
  LCD_DrawImage1BPP(524-18,333+0*34,Bmp_front, WHITE,BLACK); 
  LCD_DrawImage1BPP(524,333+0*34,Bmp_qy, WHITE,BLACK);
  
  LCD_DrawImage1BPP(524-18,333+1*34,Bmp_rear, WHITE,BLACK); 
  LCD_DrawImage1BPP(524,333+1*34,Bmp_qy, WHITE,BLACK);
  
  unsigned int Iid1[20]={212,212,0,0,212,0,212,178,178,0,
                         0,0,0,0,0,580,0,0,0,0};
  disp_kg(Iid1);  //显示开关
}


//后部模块 电源
void disp_rear_load(void){
   unsigned int Iid[20]={1,9,2,10,3,11,4,12,5,13,
                         6,14,7,42,8,17,16,31,0,0};
  disp_ID(1,Iid); //显示编号
  disp_can();
//第一列
  x=80;y=95;

  LCD_DrawImage1BPP(x,y+0*34,Bmp_rear_load1,WHITE,BLACK);  
  LCD_DrawImage1BPP(x+58,y+0*34,Bmp_Deng,WHITE,BLACK); 

  LCD_DrawImage1BPP(x,y+1*34,Bmp_rear_load2, WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+2*34,Bmp_rear_load3, WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+3*34,Bmp_rear_load4, WHITE,BLACK); 
  LCD_DrawImage1BPP(x,y+4*34,Bmp_rear_load5, WHITE,BLACK);
 
  //LCD_DrawImage1BPP(x,y+5*34,Bmp_rear, WHITE,BLACK);
  //LCD_DrawImage1BPP(x+18,y+5*34,Bmp_rear_load6, WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+5*34,Bmp_rear_load6, WHITE,BLACK);
  
  //LCD_DrawImage1BPP(x,y+6*34,Bmp_left, WHITE,BLACK);
  //LCD_DrawImage1BPP(x+18,y+6*34,Bmp_rear, WHITE,BLACK);
  //LCD_DrawImage1BPP(x+36,y+6*34,Bmp_rear_load7, WHITE,BLACK);//
  LCD_DrawImage1BPP(x,y+6*34,Bmp_rear_load7, WHITE,BLACK);//  
  
  //LCD_DrawImage1BPP(x,y+7*34,Bmp_right, WHITE,BLACK);
  //LCD_DrawImage1BPP(x+18,y+7*34,Bmp_rear, WHITE,BLACK);
  //LCD_DrawImage1BPP(x+36,y+7*34,Bmp_rear_load8, WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+7*34,Bmp_rear_load8, WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+8*34,Bmp_rear_load9, WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+8*34,Bmp_zche, WHITE,BLACK);
  LCD_DrawImage1BPP(x+58,y+8*34,Bmp_adr, WHITE,BLACK);
  LCD_DrawImage1BPP(x+58+38,y+8*34,Bmp_adr, BLACK,BLACK);
  
  LCD_DrawImage1BPP(x,y+9*34,Bmp_right, WHITE,BLACK);
  LCD_DrawImage1BPP(x+18,y+9*34,Bmp_rear_load10,WHITE,BLACK);//
  
//第二列
  x=500;y=95;
  LCD_DrawImage1BPP(x,y+0*34,Bmp_rear_load11,WHITE,BLACK);
  LCD_DrawImage1BPP(x+58,y+0*34,Bmp_dy,WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+1*34,Bmp_rear_load12,WHITE,BLACK);
  LCD_DrawImage1BPP(x+40,y+1*34,Bmp_dy,WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+2*34,Bmp_rear_load13,WHITE,BLACK);//
  LCD_DrawImage1BPP(x+40,y+2*34,Bmp_Zhu,WHITE,BLACK);//
  LCD_DrawImage1BPP(x+58,y+2*34,Bmp_dy,WHITE,BLACK);//
  LCD_DrawImage1BPP(x+98,y+2*34,Bmp_JDQi,WHITE,BLACK);//
  
  LCD_DrawImage1BPP(x,y+3*34,Bmp_rear_load14,WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+4*34,Bmp_rear_load15,WHITE,BLACK);//
  
}

//后部模块开关信息
void disp_rear_KL(void){
  unsigned int Iid[20]={32,18,33,19,34,20,35,21,36,22,
                        37,23,38,24,39,41,17,25,40,26};
  disp_ID(0,Iid);
//第一列
  x=80;y=95;
  LCD_DrawImage1BPP(x,y+0*34,Bmp_RKL1, WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+1*34,Bmp_RKL2, WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+2*34,Bmp_RKL3, WHITE,BLACK); 
  LCD_DrawImage1BPP(x+58,y+2*34,Bmp_CW, WHITE,BLACK);  
  LCD_DrawImage1BPP(x+98,y+2*34,Bmp_YJFa, WHITE,BLACK); 
  LCD_DrawImage1BPP(x+154,y+2*34,Bmp_bj, WHITE,BLACK); 
  
  LCD_DrawImage1BPP(x,y+3*34,Bmp_RKL4, WHITE,BLACK); 
  LCD_DrawImage1BPP(x+58,y+3*34,Bmp_CW, WHITE,BLACK);  
  LCD_DrawImage1BPP(x+98,y+3*34,Bmp_YJFa, WHITE,BLACK); 
  LCD_DrawImage1BPP(x+156,y+3*34,Bmp_GZi, WHITE,BLACK); 
  LCD_DrawImage1BPP(x+194,y+3*34,Bmp_KQi, WHITE,BLACK); 
  
  LCD_DrawImage1BPP(x,y+4*34,Bmp_RKL5, WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+5*34,Bmp_RKL6, WHITE,BLACK);
  LCD_DrawImage1BPP(x+40,y+5*34,Bmp_yl, WHITE,BLACK);
  LCD_DrawImage1BPP(x+80,y+5*34,Bmp_bj, WHITE,BLACK); 
  
  LCD_DrawImage1BPP(x,y+6*34,Bmp_RKL7, WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+7*34,Bmp_RKL8, WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+8*34,Bmp_RKL9, WHITE,BLACK);
  //LCD_DrawImage1BPP(x+40,y+8*34,Bmp_bj, WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+9*34,Bmp_RKL10,WHITE,BLACK);
  LCD_DrawImage1BPP(x+40,y+9*34,Bmp_bj,WHITE,BLACK);

//第二列 
  x=500;y=95;
  LCD_DrawImage1BPP(x,y+0*34,Bmp_RKL11,WHITE,BLACK); 
  LCD_DrawImage1BPP(x,y+1*34,Bmp_RKL12,WHITE,BLACK);

  disp_ADD(2);// KL13 KL14 作为地址线
  LCD_DrawImage1BPP(x,y+4*34,Bmp_RKL15,WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+5*34,Bmp_RADD,WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+6*34,Bmp_RKH1,WHITE,BLACK); 
  LCD_DrawImage1BPP(x+58,y+6*34,Bmp_cdian,WHITE,BLACK); 
  LCD_DrawImage1BPP(x+98,y+6*34,Bmp_ZShi,WHITE,BLACK); 
  
  LCD_DrawImage1BPP(524,333+0*34,Bmp_jyou, WHITE,BLACK);
  LCD_DrawImage1BPP(524+40,333+0*34,Bmp_yl, WHITE,BLACK);
  
  LCD_DrawImage1BPP(524,333+1*34,Bmp_RYou, WHITE,BLACK);
  
  unsigned int Iid1[20]={120,136,274,314,0,200,120,120,120,160,
                         0,0,0,0,0,0,0,0,0,0};
  disp_kg(Iid1);  //显示开关
}


//顶部模块 电源
void disp_top_load(void){
   unsigned int Iid[20]={1,9,2,10,3,11,4,12,5,13,
                         6,14,7,42,8,17,16,31,0,0};
  disp_ID(1,Iid); //显示编号 
  disp_can();
//第一列
  x=80;y=95; 
  LCD_DrawImage1BPP(x,y+0*34,Bmp_top_load1, WHITE,BLACK); 
  LCD_DrawImage1BPP(x,y+1*34,Bmp_top_load2, WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+2*34,Bmp_left,WHITE,BLACK);
  LCD_DrawImage1BPP(x+18,y+2*34,Bmp_front,WHITE,BLACK);
  LCD_DrawImage1BPP(x+36,y+2*34,Bmp_top_load3, WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+3*34,Bmp_right,WHITE,BLACK);
  LCD_DrawImage1BPP(x+18,y+3*34,Bmp_front,WHITE,BLACK);
  LCD_DrawImage1BPP(x+36,y+3*34,Bmp_top_load4, WHITE,BLACK);

  LCD_DrawImage1BPP(x,y+4*34,Bmp_top_load5, WHITE,BLACK);
  LCD_DrawImage1BPP(x+80,y+4*34,Bmp_dy,WHITE,BLACK);//  
  
  LCD_DrawImage1BPP(x,y+5*34,Bmp_top_load6, WHITE,BLACK);

  LCD_DrawImage1BPP(x,y+6*34,Bmp_top_load7, WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+7*34,Bmp_rear, WHITE,BLACK);
  LCD_DrawImage1BPP(x+18,y+7*34,Bmp_top_load8, WHITE,BLACK);


  LCD_DrawImage1BPP(x,y+8*34,Bmp_top_load9, WHITE,BLACK); print_SZ_2(x+40,y+8*34,1,1,0,WHITE);
  LCD_DrawImage1BPP(x,y+9*34,Bmp_top_load10, WHITE,BLACK);print_SZ_2(x+40,y+9*34,2,1,0,WHITE);
  
//第二列 
  x=500;y=95;
  LCD_DrawImage1BPP(x,y+0*34,Bmp_top_load11,WHITE,BLACK);
  LCD_DrawImage1BPP(x+40,y+0*34,Bmp_top,WHITE,BLACK);// 
  LCD_DrawImage1BPP(x+58,y+0*34,Bmp_Deng,WHITE,BLACK);
    
  LCD_DrawImage1BPP(x,y+1*34,Bmp_top_load12, WHITE,BLACK);
  LCD_DrawImage1BPP(x+40,y+1*34,Bmp_Deng,WHITE,BLACK); 
  
  LCD_DrawImage1BPP(x,y+2*34,Bmp_top_load13,WHITE,BLACK);
 
  LCD_DrawImage1BPP(x,y+3*34,Bmp_top_load14,WHITE,BLACK);
  LCD_DrawImage1BPP(x+40,y+3*34,Bmp_dy,WHITE,BLACK);

  LCD_DrawImage1BPP(x,y+4*34,Bmp_top_load15,WHITE,BLACK);
  LCD_DrawImage1BPP(x+58,y+4*34,Bmp_CWen,WHITE,BLACK); 
  LCD_DrawImage1BPP(x+76,y+4*34,Bmp_Deng,WHITE,BLACK);   
  LCD_DrawImage1BPP(x+92,y+4*34,Bmp_dy,WHITE,BLACK); 
  
}

//顶部模块开关信息
void disp_top_KL(void){
  unsigned int Iid[20]={32,18,33,19,34,20,35,21,36,22,
                        37,23,38,24,39,41,17,25,40,26};
  disp_ID(0,Iid);
//第一列  
  x=80;y=95;
  LCD_DrawImage1BPP(x,y+0*34,Bmp_TKL1, WHITE,BLACK);
  LCD_DrawImage1BPP(x+40,y+0*34,Bmp_front, WHITE,BLACK);
  LCD_DrawImage1BPP(x+58,y+0*34,Bmp_Door, WHITE,BLACK);
  LCD_DrawImage1BPP(x+76,y+0*34,Bmp_YJFa, WHITE,BLACK);
  LCD_DrawImage1BPP(x+134,y+0*34,Bmp_bj, WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+1*34,Bmp_TKL2, WHITE,BLACK);
  LCD_DrawImage1BPP(x+40,y+1*34,Bmp_rear, WHITE,BLACK);
  LCD_DrawImage1BPP(x+58,y+1*34,Bmp_Door, WHITE,BLACK);
  LCD_DrawImage1BPP(x+76,y+1*34,Bmp_YJFa, WHITE,BLACK);
  LCD_DrawImage1BPP(x+134,y+1*34,Bmp_bj, WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+2*34,Bmp_TKL3, WHITE,BLACK);
  LCD_DrawImage1BPP(x+40,y+2*34,Bmp_bj, WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+3*34,Bmp_TKL4, WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+4*34,Bmp_TKL5, WHITE,BLACK); 
  LCD_DrawImage1BPP(x,y+5*34,Bmp_TKL6, WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+6*34,Bmp_TKL7, WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+7*34,Bmp_TKL8, WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+8*34,Bmp_TKL9, WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+9*34,Bmp_TKL10,WHITE,BLACK);

//第二列 +
  x=500;y=95;
  LCD_DrawImage1BPP(x,y+0*34,Bmp_TKL11,WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+1*34,Bmp_TKL12,WHITE,BLACK);
  disp_ADD(3);// KL13 KL14 作为地址线
  
  LCD_DrawImage1BPP(x,y+4*34,Bmp_rear,WHITE,BLACK);
  LCD_DrawImage1BPP(x+18,y+4*34,Bmp_TKL15,WHITE,BLACK);
  LCD_DrawImage1BPP(x+36,y+4*34,Bmp_Open,WHITE,BLACK);
  LCD_DrawImage1BPP(x+54,y+4*34,Bmp_adr,WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+5*34,Bmp_TADD, WHITE,BLACK); 
  
  LCD_DrawImage1BPP(x,y+6*34,Bmp_front, WHITE,BLACK);  
  LCD_DrawImage1BPP(x+18,y+6*34,Bmp_TKH1, WHITE,BLACK); 
  LCD_DrawImage1BPP(x+36,y+6*34,Bmp_Open,WHITE,BLACK);
  LCD_DrawImage1BPP(x+54,y+6*34,Bmp_adr,WHITE,BLACK);
  
  
  unsigned int Iid1[20]={254,254,160,0,0,0,0,0,0,0,
                         0,0,0,0,592,0,592,0,0,0};
  disp_kg(Iid1);  //显示开关
}


//-----------------------------------------------
//更新显示仪表开关量 状态 
//参数： id 显示界面号
//-----------------------------------------------
void update_KL(unsigned char id){
   unsigned int  j=0,i=0,s=0; 
   unsigned int  ktemp[2]={0,0}; 
   unsigned char color=0;
  switch(id){
    case 0:
      ktemp[0]=512*IN10+256*IN9+128*IN8+64*IN7+32*IN6+16*IN5+8*IN4+4*IN3+2*IN2+IN1; //
      ktemp[1]=512*IN20+256*IN19+128*IN18+64*IN17+32*IN16+16*IN15+8*IN14+4*IN13+2*IN12+IN11;
    break;
    case 1:
      ktemp[0]=512*IN30+256*IN29+128*IN28+64*IN27+32*IN26+16*IN25+8*IN24+4*IN23+2*IN22+IN21; //
      ktemp[1]=512*wake_up3+256*wake_up2+128*wake_up1+64*IN37+32*IN36+16*IN35+8*IN34+4*IN33+2*IN32+IN31;;
    break;
    default:
      ktemp[0]=0;ktemp[1]=0;
    break;
  } 
  for(j=0;j<2;j++){
   for(i=0;i<10;i++){        
      if(ktemp[j]&0x0001){
         color=GREEN;
         s=1;//开关状态
      }else{
         color=WHITE;
         s=0;
     }
      
      LCD_DrawImage1BPP(56+j*420,95+34*i,Bmpflag1[s],color,BLACK);
      ktemp[j]=ktemp[j]>>1; //开关状态移位
      //if((j==1)&&(i==1)&&(id==1))break;
      
   }
  }
}

//更新功率输出 状态
void update_CY09MT_load(unsigned char index){
 unsigned char color=GREEN,s=0;	
 unsigned int  Tdate=0,TCAN=0; 
 unsigned char *Sdate; //
 unsigned int  *Pcurrent;
 unsigned int  i=0,j=0;
 unsigned int  MK_Version=0;
  switch(index){
   case 0:
    TCAN=Fcan_count;
    Tdate=((unsigned int )(fPOUT.BYTES[1])<<8)+fPOUT.BYTES[0];
    //Sdate=((unsigned long)(fPF[3].byte)<<24)+((unsigned long)(fPF[2].byte)<<16)+
    //      ((unsigned long)(fPF[1].byte)<<8)+fPF[0].byte;
    Sdate=fPF; //电流负载状态
    Pcurrent=fpcur;//反馈电流
    MK_Version=fMK_Version;
   break;
   case 1:
    TCAN=Rcan_count;
    Tdate=((unsigned int )(rPOUT.BYTES[1])<<8)+rPOUT.BYTES[0];
    //Sdate=((unsigned long)(rPF[3].byte)<<24)+((unsigned long)(rPF[2].byte)<<16)+
    //      ((unsigned long)(rPF[1].byte)<<8)+rPF[0].byte;
    Sdate=rPF; //电流负载状态
    Pcurrent=rpcur;//反馈电流
    MK_Version=rMK_Version;
   break;
   case 2:
    TCAN=Mcan_count;
    Tdate=((unsigned int )(mPOUT.BYTES[1])<<8)+mPOUT.BYTES[0];
    //Sdate=((unsigned long)(mPF[3].byte)<<24)+((unsigned long)(mPF[2].byte)<<16)+
    //      ((unsigned long)(mPF[1].byte)<<8)+mPF[0].byte;
    Sdate=mPF; //电流负载状态
    Pcurrent=mpcur;//反馈电流
    MK_Version=mMK_Version;
   break;
   default:
   break;
  }  
  for(j=0;j<2;j++){
   for(i=0;i<10;i++){
    if(Tdate&0x0001){
      color=GREEN; s=1;
    }else{
      color=WHITE; s=0;
    } 	 
    LCD_DrawImage1BPP(56+j*420,95+34*i,Bmpflag1[s],color,BLACK);
    Tdate=Tdate>>1;  
    
    if(j==1 && i>=5) break; //状态显示16个 故障显示15个 

    //if (Sdate[i+j*10] == 0 || Sdate[i+j*10] == 1) color = GREEN;
    //else if (Sdate[i+j*10] == 2) color = YELLOW;
    //else color = RED; 
    if (Sdate[i+j*10] == 0) color = GREEN;
    else if (Sdate[i+j*10] == 1) color = YELLOW;
    else if (Sdate[i+j*10] == 2) color = RED;
    else color = RED; 
    LCD_DrawImage1BPP(308+j*420,95+i*34,Bmpfault,color,BLACK);//状态

    if (Pcurrent[i+j*10] / 100 > 10)print_SZ(308+j*420+30, 95+i*34+3, Pcurrent[i+j*10] / 100, 3, 1, color); //后模块电流
    else                            print_SZ(308+j*420+30, 95+i*34+3, 0, 3, 1, color);//BLACK
    
   }  
  }
  if(TCAN>=CAN_TIME){
     color=RED;  s=0;
  }else{
     color=GREEN; s=1;
  }
  for(i=0;i<2;i++){
    LCD_DrawImage1BPP(56+420,299+34*i,Bmpflag1[s],color,BLACK); 
  }
  
  //LCD_DrawImage1BPP(20+420+128,95+8*34,Bmp_V,   WHITE,BLACK);//A 
  //print_SZ_2(20+420+128+16,95+8*34,   MK_Version,3,2,YELLOW);//2.00 模块程序版本
    
    LCD_DrawImage1BPP(20+420,95+9*34,Bmp_V,   WHITE,BLACK);//A  
    print_SZ_2(20+420+16,95+9*34,   MK_Version,3,2,YELLOW);//2.00 模块程序版本 
}

//更新模块 开关状态
void update_CY09MT_KL(unsigned char index){
 unsigned int i=0,j=0;
 unsigned char color=GREEN,s=0;;	
 unsigned long Tdate=0; 
 unsigned int  Sdate[3]={0,0,0};
 unsigned int   ADRx=0; //信号量显示位置
  switch(index){
   case 0:
    //开关量
    fKEY.BYTES[1] |=fADD<<7; 
    Tdate=((unsigned long)(fKEY.BYTES[2])<<16)+
          ((unsigned long)(fKEY.BYTES[1])<<8)+fKEY.BYTES[0];

    //信号量 
    ADRx=614;
    Sdate[0]=fADR[0]/10;
    Sdate[1]=fADR[1]/10; 
    Sdate[2]=fFreq;
   break;
   case 1:
    //开关量
    rKEY.BYTES[1] |=rADD<<7;//ADD
    Tdate=((unsigned long)(rKEY.BYTES[2])<<16)+
          ((unsigned long)(rKEY.BYTES[1])<<8)+rKEY.BYTES[0];
    //信号量 
    ADRx=614;
    Sdate[0]=rADR[0]/10;
    Sdate[1]=rADR[1]/10; 
    Sdate[2]=rFreq;
   break;
   case 2:
    //开关量
    mKEY.BYTES[1] |=mADD<<7; //ADD
    Tdate=((unsigned long)(mKEY.BYTES[2])<<16)+
          ((unsigned long)(mKEY.BYTES[1])<<8)+mKEY.BYTES[0];
    //信号量
    ADRx=614;  
    Sdate[0]=mADR[0]/10;
    Sdate[1]=mADR[1]/10; 
    Sdate[2]=mFreq;
   break;
   default:
   break;
  }  
  for(j=0;j<2;j++){  
    for(i=0;i<10;i++){    	 
      if(Tdate&0x0001){
        color=GREEN; s=1;
      }else{
        color=WHITE; s=0;
      } 	 
    LCD_DrawImage1BPP(56+j*420,95+34*i,Bmpflag1[s],color,BLACK);
    Tdate=Tdate>>1;   
      if(j==1 && i>=6) break; 
    }
  }
  for(i=0;i<3;i++){ 
    print_SZ_2(ADRx,333+i*34,Sdate[i],4,0,YELLOW);
  }
}

//更新状态 
void update_ADR(void){
  unsigned int i=0; 
  unsigned char color=0,s=0;
 
  for(i=0;i<2;i++){   
    print_SZ_2(200,95+i*34,ADR[i+1],4,0,WHITE);
  }
  for(i=2;i<4;i++){   
    print_SZ_2(200,95+i*34,ADV[i+1]/10,3,2,WHITE);
  }
  print_SZ_2(200,95+4*34,ADR[5],4,0,WHITE);
  print_SZ_2(200,95+5*34,ADV[6]/10,3,2,WHITE);
  for(i=0;i<2;i++){   
    print_SZ_2(200,95+(i+6)*34,freq[i],4,0,WHITE);
  }
    print_SZ_2(550,95,ADR[0],3,1,WHITE);
  if((Fcan_count>=CAN_TIME)&&(Mcan_count>=CAN_TIME)&&(Rcan_count>=CAN_TIME)){
     color=RED;s=0;
  }else{
     color=GREEN;s=1;
  }   
  LCD_DrawImage1BPP(476,95+1*34,Bmpflag1[s],color,BLACK);
  LCD_DrawImage1BPP(476,95+2*34,Bmpflag1[s],color,BLACK);

  if(ECU_TIME>=CAN_TIME){
     color=RED;s=0;
  }else{
     color=GREEN;s=1;
  }   
  LCD_DrawImage1BPP(476,95+3*34,Bmpflag1[s],color,BLACK);
  LCD_DrawImage1BPP(476,95+4*34,Bmpflag1[s],color,BLACK);
}

void ICFrame(unsigned char id){ 
   LCD_DrawRect(0,60,800,365,BLACK);
  switch(id){
   case 0:disp_KL1(); 
   break;
   case 1:disp_KL2(); 
   break;
   case 2:disp_ADR();
   break;
   case 3:disp_front_load(); 
   break;
   case 4:disp_front_KL(); 
   break;
   case 5:disp_rear_load(); 
   break;
   case 6:disp_rear_KL(); 
   break; 
   case 7:disp_top_load();    
   break;
   case 8:disp_top_KL();    
   break;
   default: 
   break;
  }
  //显示标题栏
   LCD_DrawImage1BPP(700-25,30,Bmp_DI,GREEN,BLACK);//第
   LCD_DrawImage1BPP(700+25,30,Bmp_YE,GREEN,BLACK);//页
   print_SZ_2(700,30,id+1,1,0,WHITE);//页面编号
   LCD_DrawImage1BPP(500,30,Bmp_CANST, WHITE,BLACK);//
   //LCD_DrawImage1BPP(532,30,Bmp_TXun,WHITE,BLACK);   

  if(id<=2){
    LCD_DrawImage1BPP(340-18,30,Bmp_front,   BLACK,BLACK); 
    LCD_DrawImage1BPP(340,   30,BMP_IC,      GREEN,BLACK);//仪表
    LCD_DrawImage1BPP(380,   30,BMP_STSTEM,  GREEN,BLACK);//系统
    LCD_DrawImage1BPP(420,   30,BMP_Message, GREEN,BLACK);//信息
    
  }else{
    if(id<=4){
      LCD_DrawImage1BPP(340-18,30,Bmp_front,GREEN,BLACK);    
    }else if(id<=6){  
      //LCD_DrawImage1BPP(340-18,30,Bmp_top,GREEN,BLACK);
      LCD_DrawImage1BPP(340-18,30,Bmp_rear,GREEN,BLACK);
    }else{  
      LCD_DrawImage1BPP(340-18,30,Bmp_top,GREEN,BLACK);
    }
      LCD_DrawImage1BPP(340,30,Bmp_MK,GREEN,BLACK);
  }
}

void ICUpdate(unsigned char id){
 unsigned int   TCAN=0; 
  switch(id){
   case 0:update_KL(0);TCAN=0;
   break; 
   case 1:update_KL(1);TCAN=0;
   break; 
   case 2:update_ADR();TCAN=0;
   break; 
   case 3:update_CY09MT_load(0);TCAN=Fcan_count;
   break; 
   case 4:update_CY09MT_KL(0);  TCAN=Fcan_count;
   break;  
   case 5:update_CY09MT_load(1);TCAN=Rcan_count;
   break; 
   case 6:update_CY09MT_KL(1);  TCAN=Rcan_count;
   break;      
   case 7:update_CY09MT_load(2);TCAN=Mcan_count;
   break; 
   case 8:update_CY09MT_KL(2);  TCAN=Mcan_count;
   break; 
   default:
   break;  
  }
 unsigned char color;
   if(TCAN>=CAN_TIME){ TCAN=0;color=RED;  }
   else              { TCAN=1;color=GREEN;}
   LCD_DrawImage1BPP(579,30,Bmp_ST[TCAN],color,BLACK);  
}

void frmIC(void) {
  static unsigned char Did=0; //显示屏幕 编号
  if(f_index==0){
    f_index=1;  
    key_up=1;  //触发 显示界面
    Did=9;  
  }else if(f_index==1){
    f_index=1; 
    ICUpdate(Did);
  }else{
    f_index=0;     
  }
  if(key_up){
     if(Did>=2) Did=0;
     else       Did++;
  }
  if(key_reset){
     if(Did>0)  Did--;
     else       Did=2;
  }
  if(key_reset||key_up){
     ICFrame(Did);
     key_up=0;
     key_reset=0;
  }
 if(key_set){
    key_set=0;   
    key_duble=0;
    key_up=0;
    frmID = 1;
    f_index=0;
  }     
    
      
}
unsigned char ZZ=40;
void MenuFrame(void) {
    unsigned char i=0;
    LCD_Clear();
    unsigned char color = WHITE;
    LCD_DrawRect(0, 56,  800, 2, GRAY); //顶部横线 
    LCD_DrawRect(0, 430, 800, 2, GRAY); //底部横线
    
    LCD_DrawImage1BPP(340,   30,BMP_STSTEM, GREEN,BLACK);//系统
    LCD_DrawImage1BPP(340+40,30,Bmp_Menu,   GREEN,BLACK);//菜单
    LCD_DrawImage1BPP(340+80,30,BMP_Message,GREEN,BLACK);//信息
    
x=400-60;y=75-9;
    for(i=1;i<3;i++){
    LCD_DrawImage1BPP(x+40, y+i*ZZ, BMP_STSTEM,  color, BLACK); //系统
    LCD_DrawImage1BPP(x+80, y+i*ZZ, BMP_Message, color, BLACK); //信息
    }
    LCD_DrawImage1BPP(x,    y+0*ZZ, BMP_FDJi,    color, BLACK); //发动机,
    LCD_DrawImage1BPP(x+58, y+0*ZZ, BMP_STSTEM,  color, BLACK); //系统
    LCD_DrawImage1BPP(x+98, y+0*ZZ, BMP_Message, color, BLACK); //信息
    
  //LCD_DrawImage1BPP(x,    y+0*ZZ, BMP_Control, color, BLACK); //控制
  //LCD_DrawImage1BPP(x,    y+1*ZZ, Bmp_ZQu,     color, BLACK); //电机  //BMP_Engine 发动机 
  //LCD_DrawImage1BPP(x,    y+2*ZZ, BMP_Debug,   color, BLACK); //调试
  //LCD_DrawImage1BPP(x,    y+3*ZZ, BMP_Battery, color, BLACK); //电池    
  //LCD_DrawImage1BPP(x,    y+4*ZZ, BMP_Air,     color, BLACK); //空调
  //LCD_DrawImage1BPP(x,    y+5*ZZ, Bmp_DQi,     color, BLACK); //电器  
  //LCD_DrawImage1BPP(x,    y+6*ZZ, BMP_Fuzhu,   color, BLACK); //辅助    
    
  //LCD_DrawImage1BPP(x,    y+1*ZZ, Bmp_TYa,     color, BLACK); //胎压
    LCD_DrawImage1BPP(x,    y+1*ZZ, BMP_IC,      color, BLACK); //仪表

    LCD_DrawImage1BPP(x,    y+2*ZZ, Bmp_SJSZ,    color, BLACK); //时间设置 
    
    LCD_DrawImage1BPP(x,    y+3*ZZ, Bmp_csu,     color, BLACK); //车速
    LCD_DrawImage1BPP(x+40, y+3*ZZ, Bmp_subi,    color, BLACK); //速比
    
    LCD_DrawImage1BPP(x,    y+4*ZZ,Bmp_TChu,     color, BLACK); //退出
      
}

void MenuUpdate(void) {
    static unsigned char i = 0;
    unsigned char color = BLACK;
    if (key_up) {//箭头向下走
        key_up = 0;
        if (!time_flag) {
            i++;
        }
    }

    if (key_AV) {//箭头向上走
        key_AV = 0;
        if (!time_flag)
            i--;
    }

    if (i == 10) i = 5;
    if (i == 0)  i = 5;
    
x=320-9;y=75-10;
    //子菜单间切换
    if (i == 5) {
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
    LCD_DrawImage1BPP(x,  y+0*ZZ, BMP_Choose, color, BLACK);
    
    /*     
    if (i == 6 || i == 1) {
        color = GREEN;
        
        if (key_set) {
            key_set = 0;
            if (time_flag == 0) {
                f_index = 0;
                frmID = 20;
            }
            time_flag = 0;
        }
    } else
        color = BLACK;
    LCD_DrawImage1BPP(x,  y+1*ZZ, BMP_Choose, color, BLACK);

    if (i == 13 || i == 2) {
        color = GREEN;
        if (key_set) {
            key_set = 0;
            if (time_flag == 0) {
                f_index = 0;
                frmID = 7;//4
            }
            time_flag = 0;
        }
    } else
        color = BLACK;
    LCD_DrawImage1BPP(x,  y+2*ZZ, BMP_Choose, color, BLACK);
    if (i == 14 || i == 3) {
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
    LCD_DrawImage1BPP(x,  y+3*ZZ, BMP_Choose, color, BLACK);
    if (i == 15 || i == 4) {
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
    LCD_DrawImage1BPP(x,  y+4*ZZ, BMP_Choose, color, BLACK);

    if (i == 16 || i == 5) {
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
    LCD_DrawImage1BPP(x,  y+5*ZZ, BMP_Choose, color, BLACK);

    if (i == 17 || i == 6) {
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
    LCD_DrawImage1BPP(x,  y+6*ZZ, BMP_Choose, color, BLACK);
    */
    if (i == 6 || i == 1) {
        color = GREEN;
        if (key_set) {
            key_set = 0;
            if (time_flag == 0) {
                f_index = 0;
                frmID = 28;
            }
            time_flag = 0;
        }
    } else
        color = BLACK;
    LCD_DrawImage1BPP(x,  y+1*ZZ, BMP_Choose, color, BLACK);
    if (i == 7 || i == 2) {
        color = GREEN;
        if (key_set) {
            key_set = 0;
            if (time_flag == 0) {
                f_index = 0;
                frmID = 29;
            }
            time_flag = 0;
        }
    } else
        color = BLACK;
    LCD_DrawImage1BPP(x,  y+2*ZZ, BMP_Choose, color, BLACK);
    if (i == 8|| i == 3) {
        color = GREEN;
        if (key_set) {
            key_set = 0;
            if (time_flag == 0) {
                f_index = 0;
                frmID = 30;
            }
            time_flag = 0;
        }
    } else
        color = BLACK;
    LCD_DrawImage1BPP(x,  y+3*ZZ, BMP_Choose, color, BLACK);
    if (i == 9|| i == 4) {
        color = GREEN;
        if (key_set) {
            key_set = 0;
            if (time_flag == 0) {
                f_index = 0;
                frmID = 0;
            }
            time_flag = 0;
        }
    } else
        color = BLACK;
    LCD_DrawImage1BPP(x,  y+4*ZZ, BMP_Choose, color, BLACK);
    
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
    if (key_long_set) {
        key_long_set = 0;
        key_set = 0;
        key_up = 0;
        key_AV = 0;
    }

    if (key_duble) {
        key_duble = 0;
        key_long_set = 0;
        key_set = 0;
        key_up = 0;
        key_AV = 0;    
    }

}

void print001(unsigned int x,unsigned int y, unsigned int temp,unsigned int num){
   unsigned int s=0,i=0;
   unsigned char bcd;
   s=x+num*17-17;
   for(i=0;i<num;i++){
      bcd=temp%10;
      temp=temp/10; 
     LCD_DrawImage1BPP(s-17*i,y,BMP_SZ_3[bcd],YELLOW,BLACK);
   } 
}

void ControlFrame(void) {
     unsigned char i = 0;
x=7;y=68;
   for(i=0;i<11;i++){
    LCD_DrawRect(x,y+i*35,786, 1,GRAY);//-
   }
    LCD_DrawRect(x,y,1, 350,GRAY);//|左
x=269;
   //LCD_DrawRect(x,y,1, 350,GRAY);//|中1
x=400;
    LCD_DrawRect(x,y,1, 350,GRAY);//|中
x=531;
   //LCD_DrawRect(x,y,1, 350,GRAY);//|中2
x=793;
    LCD_DrawRect(x,y,1, 350,GRAY);//|右


///////////////////////第一列///////////////////////
x=10;y=84-9; 
    for(i=0;i<8;i++){
    lcd_show_8dot( x, y+35*i, Bmp_FDJi,WHITE,0x0000);
    }
    lcd_show_8dot(x+56, y+35*0, Bmp_zs,WHITE,0x0000);

    lcd_show_8dot(x+56, y+35*1, Bmp_sw,WHITE,0x0000); //

    lcd_show_8dot(x+56 ,y+35*2, Bmp_ym,WHITE,0x0000); //

    lcd_show_8dot(x+56, y+35*3, Bmp_jyou,WHITE,0x0000); // 
    lcd_show_8dot(x+96, y+35*3, Bmp_yl,  WHITE,0x0000); // 

    lcd_show_8dot(x+56, y+35*4, Bmp_jq,WHITE,0x0000); // 
    lcd_show_8dot(x+96, y+35*4, Bmp_wd,WHITE,0x0000); // 

    lcd_show_8dot(x+56, y+35*5, Bmp_jq,WHITE,0x0000); // 
    lcd_show_8dot(x+96, y+35*5, Bmp_yl,WHITE,0x0000); // 

    lcd_show_8dot(x+56, y+35*6, Bmp_zy,WHITE,0x0000); // 
    lcd_show_8dot(x+96, y+35*6, Bmp_yl,WHITE,0x0000); // 

    lcd_show_8dot(x+56, y+35*7, Bmp_SShi,WHITE,0x0000);//
    lcd_show_8dot(x+96, y+35*7, Bmp_yh,WHITE,0x0000);  //

  //lcd_show_8dot(x+56, y+35*8, Bmp_PJun,WHITE,0x0000);//
  //lcd_show_8dot(x+96, y+35*8, Bmp_yh,WHITE,0x0000);  //

  //lcd_show_8dot(x,    y+35*9, Bmp_DCeng,WHITE,0x0000); 
  //lcd_show_8dot(x+40, y+35*9, Bmp_LJi,WHITE,0x0000); //
  //lcd_show_8dot(x+80, y+35*9, Bmp_yh,WHITE,0x0000);  //

x=x+338;//单位符号
y=y+4;
    lcd_show_8dot(370-20,   y+35*0, Bmp_RPM, WHITE,0x0000);
    lcd_show_8dot(370-20,   y+35*1, Bmp_deg, WHITE,0x0000);
    lcd_show_8dot(370-20,   y+35*2, Bmp_bfh, WHITE,0x0000);
    lcd_show_8dot(370-20,   y+35*3, Bmp_MPa, WHITE,0x0000);
    lcd_show_8dot(370-20,   y+35*4, Bmp_deg, WHITE,0x0000);
    lcd_show_8dot(370-20,   y+35*5, Bmp_kpa, WHITE,0x0000);
    lcd_show_8dot(370-20,   y+35*6, Bmp_kpa, WHITE,0x0000);
    lcd_show_8dot(370-20,   y+35*7, Bmp_Lh,  WHITE,0x0000);//Bmp_KGH
  //lcd_show_8dot(370-32-20,y+35*8, Bmp_KGKM,WHITE,0x0000);
  //lcd_show_8dot(370-20,   y+35*9, Bmp_KGH, WHITE,0x0000);LCD_DrawRect(370, y+35*9, 20,16, 0x0000);

///////////////////////第二列///////////////////////
x=463-58;y=84-9; 
  //x=420; y=75;
  //故障代码
  lcd_show_8dot(500+35, y, Bmp_FDJi,WHITE,0x0000);
  lcd_show_8dot(556+35, y, Bmp_ST[0],WHITE,0x0000);
  lcd_show_8dot(596+35, y, Bmp_dm,WHITE,0x0000);

  x=550; y=110; 
  lcd_show_8dot(x,    y,Bmp_SPN,WHITE,BLACK);
  lcd_show_8dot(x+100,y,Bmp_FMI,WHITE,BLACK);

  x=430; y=145;
  for(i=0;i<8;i++){
     lcd_show_8dot(x,y+i*35,BMP_SZ_3[i+1],WHITE,BLACK); 
   }

x=x+338;

}

void ControlUpdate(void) {
  unsigned int  temp=0;
  unsigned long temp32=0;
  
//////////////////////第一列////////////////////
x=305-32;y=84-9;
    temp=EngineSpeed>>3;
    print_SZ_2(300-20,77,temp,4,0,YELLOW);//
//温度
    temp=WaterTem; 
    update_deg(300-20,77+35*1,temp,YELLOW);//
//发动机
    temp=0.4*speed_st;
    print_SZ_2(316-20,77+35*2,temp,3,0,YELLOW);//
//发动机机油压力
    temp=(0.4*engine_oil_press); 
    print_SZ_2(300-20,77+35*3,temp,3,2,YELLOW);//
//进气温度
    temp=ambient_air_temperature; 
    update_deg(300-20,77+35*4,temp,YELLOW);// 
//注意 进气压力和增压压力的比率 为2kpa/bit
    temp=((unsigned int)air_pressure)*2;       //进气压力
    print_SZ_2(316-20,77+35*5,temp,3,0,YELLOW);//
//增压压力
    temp=((unsigned int)barometric_pressure)*2;
    print_SZ_2(316-20,77+35*6,temp,3,0,YELLOW);//
//瞬时质量气耗    
    temp=(unsigned int)(5*fuel_rate);//油耗    
  //temp=QT_SSZL_QH;
    print_SZ_2(268-16-20,77+35*7,temp,6,2,YELLOW);
//百公里质量气耗 平均气耗
    //temp=QT_KMZL_QH;
    //print_SZ_2(268-48-20,77+35*8,temp,6,2,YELLOW);
//单程累计气耗
    //temp32=QT_trip_XHL*5;
    //print_SZ_2(268-48-20,77+35*9,temp32,8,1,YELLOW);

//////////////////////第二列////////////////////
x=698-32;y=84-9;

  unsigned int   x=500, y=145;
  unsigned int   i,s=0;
  unsigned long  spn=0;
  if(ECU_DTC_NUM>=10) s=(ECU_DTC_NUM-2)/4; //故障个数
  for(i=0;i<8;i++){
    if(i<=s)spn= ECU_dtc[i].byte[0] + ((unsigned int) (ECU_dtc[i].byte[1]) << 8)
                    +((unsigned long) (ECU_dtc[i].byte[2] & 0xE0) << 11);
    else   spn=0;
    print_SZ_2(x-20,y+35*i,spn,6,0,GREEN);//SPN;//更新显示故障代码SPN
  }
  for(i=0;i<8;i++){
    if(i<=s)spn= (ECU_dtc[i].byte[2]&0x1f);
    else   spn=0;
    print_SZ_2(650-20,y+35*i,spn,2,0,GREEN);//FMI//更新显示故障代码FMI
  }

}

void frmControl(void) {
    if (f_index == 0) { //只更新一次
        f_index = 1;
        LCD_DrawRect(0,60,800,365,BLACK);
        LCD_DrawImage1BPP(340,30,       BMP_FDJi,    GREEN, BLACK); //发动机
        LCD_DrawImage1BPP(340+40+16,30, BMP_STSTEM,  GREEN, BLACK); //系统
        LCD_DrawImage1BPP(340+80+16,30, BMP_Message, GREEN, BLACK); //信息
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
    }
    if (key_set) {//返回主界面
        key_set = 0;
        frmID = 1;
        f_index = 0;
        Index = 0;
    }
    if (key_long_set) {
        key_long_set = 0;
    }

}


/*********************************************************************
//函数名: void frm_speed(void)
//功能:  设置处理
//参数:  全局变量
**********************************************************************/
void frm_speed(void){
  if(f_index==0){
    f_index=1;
    key_set =0;
    key_duble=0;
    LCD_DrawRect(0,0, 800,50, BLACK);
    LCD_DrawRect(0,60,800,365,BLACK);
    LCD_DrawImage1BPP(360,30,Bmp_csu, GREEN,BLACK);//车速
    LCD_DrawImage1BPP(400,30,Bmp_subi,GREEN,BLACK);//速比
    
    LCD_DrawImage1BPP(340-40, 145,Bmp_subi, YELLOW,BLACK);//
    LCD_DrawImage1BPP(340-40, 200,Bmp_csu,  YELLOW,BLACK); //
    LCD_DrawImage1BPP(430,    200,Bmp_kmh,  GREEN,BLACK); // /h 

  }else if(f_index==1){
    f_index=1;
    print_SZ_2(340,145,e_hm_pulse,5,0,GREEN);//SPEED_RATIO  
    print_SZ_2(340,200,Vspeed,4,1,GREEN);//Vspeed    
  }else{
    f_index=0;
  }
  if(key_set){
    key_set=0;
    key_up=0;
    key_reset=0;
    frmID=1;
    f_index=0; 
  }
  if(key_duble){
    key_duble=0;
    key_set=0;
    key_up=0;
    key_reset=0;
    key_long_set=0;
    frmID=31;
    f_index=0;   
  }
}

//密码输入
void update_code(unsigned int Tid,unsigned int *ptr){
   unsigned char color=0,color1=0;
   if(Tid==0){ color=RED; color1=RED;  }
   else      { color=GRAY;color1=WHITE;}
   disp_rectange(320+40*0+4,220,4,40,2,color);
   LCD_DrawImage1BPP(328+40*0+4,230,BMP_SZ_3[*ptr++],color1,BLACK);

   if(Tid==1){ color=RED; color1=RED;  }
   else      { color=GRAY;color1=WHITE;}
   disp_rectange(320+40*1+4,220,4,40,2,color);
   LCD_DrawImage1BPP(328+40*1+4,230,BMP_SZ_3[*ptr++],color1,BLACK);

   if(Tid==2){ color=RED; color1=RED;  }
   else      { color=GRAY;color1=WHITE;}
   disp_rectange(320+40*2+4,220,4,40,2,color);
   LCD_DrawImage1BPP(328+40*2+4,230,BMP_SZ_3[*ptr++],color1,BLACK);

   if(Tid==3){ color=RED; color1=RED;  }
   else      { color=GRAY;color1=WHITE;}
   disp_rectange(320+40*3+4,220,4,40,2,color);
   LCD_DrawImage1BPP(328+40*3+4,230,BMP_SZ_3[*ptr++],color1,BLACK);   
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
    LCD_DrawImage1BPP(360,30,Bmp_csu, GREEN,BLACK);//车速
    LCD_DrawImage1BPP(400,30,Bmp_subi,GREEN,BLACK);//速比
    
    LCD_DrawImage1BPP(400-40,190,Bmp_srmm,GREEN,BLACK);
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
  if(key_reset){
     key_reset=0;
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

void disp_system(unsigned char id){
    unsigned char color=0;
    if(id==0) color=GREEN;
    else      color=WHITE;
    LCD_DrawImage1BPP(300+24,   140,BMP_SZ_3[1],color,BLACK);
    LCD_DrawImage1BPP(316+24,   140,BMP_SZ_3[10],color,BLACK);
    LCD_DrawImage1BPP(336+24,   140,Bmp_subi,color,BLACK);//速比 
    LCD_DrawImage1BPP(336+40+24,140,Bmp_SZhi,color,BLACK);//设置
    if(id==1) color=GREEN;
    else      color=WHITE;
    LCD_DrawImage1BPP(300+24, 190,BMP_SZ_3[2],color,BLACK);
    LCD_DrawImage1BPP(316+24, 190,BMP_SZ_3[10],color,BLACK);
    LCD_DrawImage1BPP(336+24, 190,Bmp_LCheng,color,BLACK);//里程
    LCD_DrawImage1BPP(376+24, 190,Bmp_SZhi,  color,BLACK);//设置 

    if(id==2) color=GREEN;
    else      color=WHITE;
    LCD_DrawImage1BPP(300+24, 240,BMP_SZ_3[3],color,BLACK);
    LCD_DrawImage1BPP(316+24, 240,BMP_SZ_3[10],color,BLACK);
    LCD_DrawImage1BPP(336+24, 240,Bmp_TChu,color,BLACK);//退出 
}
void frm_system(void){
  static unsigned char ID=0;
  if(f_index==0){
     f_index=1;    
     LCD_DrawRect(0,60,800,365,BLACK);
     LCD_DrawImage1BPP(360,30,Bmp_csu, GREEN,BLACK);//车速
     LCD_DrawImage1BPP(400,30,Bmp_subi,GREEN,BLACK);//速比
     key_up=1; 
     ID=11;
  }else if(f_index==1){
    f_index=1;  
  }else{
    f_index=0;
  }
  if(key_up){
   if(ID>=2)ID=0;
   else     ID++;
  }
  if(key_reset){
   if(ID<=0)ID=2;
   else     ID--;
  }
  if(key_reset||key_up){
    disp_system(ID);
    key_up=0;
    key_reset=0;
  }
  if(key_set){
   key_set=0;
   f_index=0;
   frmID=ID+33; //菜单号从2---7开始 
   if(frmID>=35)frmID=0; //返回主界面 
  }
}

//总里程设置
void update_miles(unsigned int Tid,unsigned int *ptr){
   unsigned char color=0,color1=0;
   if(Tid==0){ color=RED; color1=RED;  }
   else      { color=GRAY;color1=WHITE;}
   disp_rectange(260+40*0,220,4,40,2,color);
   LCD_DrawImage1BPP(268+40*0,230,BMP_SZ_3[*ptr++],color1,BLACK);

   if(Tid==1){ color=RED; color1=RED;  }
   else      { color=GRAY;color1=WHITE;}
   disp_rectange(260+40*1,220,4,40,2,color);
   LCD_DrawImage1BPP(268+40*1,230,BMP_SZ_3[*ptr++],color1,BLACK);

   if(Tid==2){ color=RED; color1=RED;  }
   else      { color=GRAY;color1=WHITE;}
   disp_rectange(260+40*2,220,4,40,2,color);
   LCD_DrawImage1BPP(268+40*2,230,BMP_SZ_3[*ptr++],color1,BLACK);

   if(Tid==3){ color=RED; color1=RED;  }
   else      { color=GRAY;color1=WHITE;}
   disp_rectange(260+40*3,220,4,40,2,color);
   LCD_DrawImage1BPP(268+40*3,230,BMP_SZ_3[*ptr++],color1,BLACK);   

   if(Tid==4){ color=RED; color1=RED;  }
   else      { color=GRAY;color1=WHITE;}
   disp_rectange(260+40*4,220,4,40,2,color);
   LCD_DrawImage1BPP(268+40*4,230,BMP_SZ_3[*ptr++],color1,BLACK);   

   if(Tid==5){ color=RED; color1=RED;  }
   else      { color=GRAY;color1=WHITE;}
   disp_rectange(260+40*5,220,4,40,2,color);
   LCD_DrawImage1BPP(268+40*5,230,BMP_SZ_3[*ptr++],color1,BLACK); 

   if(Tid==6){ color=RED; color1=RED;  }
   else      { color=GRAY;color1=WHITE;}
   disp_rectange(260+40*6,220,4,40,2,color);
   LCD_DrawImage1BPP(268+40*6,230,BMP_SZ_3[*ptr++],color1,BLACK);   
}

void frm_miles(void){  
  static unsigned int  Tid=0;
  static unsigned int  bcd[7]={0,0,0,0,0,0,0};
  unsigned int i=0; 
  unsigned long tmiles=0;
  if(f_index==0){
    f_index=1;
    key_up=0;
    key_reset=0;
    key_set =0;
    key_duble=0;
    LCD_DrawRect(0,60,800,365,BLACK);
    
    LCD_DrawImage1BPP(360,30,Bmp_LCheng,GREEN,BLACK);//里程
    LCD_DrawImage1BPP(400,30,Bmp_SZhi,GREEN,BLACK);//设置
    
    LCD_DrawImage1BPP(200+60,185,Bmp_ODO,WHITE,BLACK);//总计
    LCD_DrawImage1BPP(240+60,185,Bmp_LCheng,WHITE,BLACK);//里程  

    LCD_DrawImage1BPP(440+60,187,Bmp_Km, WHITE,BLACK);//单位 Km 
    delay_5s=12000;  
  }else if(f_index==1){
    f_index=1;
    update_miles(Tid,&bcd[0]);
    print_SZ_2(325+60,185,total_miles/10,7,0,YELLOW);
  }else{
    f_index=0;
  }
  if(key_set){
    key_set=0;
    delay_5s=12000;  
    if(Tid>=6)Tid=0;
    else      Tid++;
    tmiles=0;
    for(i=0;i<7;i++){    
     tmiles+=bcd[i];
     tmiles=tmiles*10;
    }
    total_miles=tmiles;    
    e_total_miles=tmiles;
    EEROM_WriteTotalMiles();
    delay_cnt=1;
    while (delay_cnt > 1); //延时10Ms
    EEROM_ReadTotalMiles();
  }
  if(key_up){
     key_up=0; 
     delay_5s=12000; 
    if(Tid<=6){
      if(bcd[Tid]>0) bcd[Tid]--; 
      else           bcd[Tid]=0;
    }else Tid=0;
  }
  if(key_reset){
     key_reset=0;
     delay_5s=12000; 
    if(Tid<=6){
      if(bcd[Tid]<9) bcd[Tid]++; 
      else           bcd[Tid]=9;
    }else Tid=0;
  }
  if(key_long_set ||(delay_5s<=1)){
    key_duble=0;
    key_long_set=0;
    //key_up_long=0;
    //key_reset_long=0;
    frmID=0;
    f_index=0;
  }
}
//
void disp_setDATE(void){  
    unsigned int i=0;   
    LCD_DrawImage1BPP(360,30,Bmp_subi,GREEN,BLACK);//速比
    LCD_DrawImage1BPP(400,30,Bmp_SZhi,GREEN,BLACK);//设置
  
    LCD_DrawImage1BPP(300+60,170,Bmp_subi,YELLOW,BLACK);//
    LCD_DrawImage1BPP(390+60,170,Bmp_csu, YELLOW,BLACK); //

    LCD_DrawImage1BPP(430+60,170,Bmp_kmh,GREEN,BLACK); // /h  
 
    LCD_DrawImage1BPP(210+60,205,BMP_SZ_3[1],YELLOW,BLACK);// 
    LCD_DrawImage1BPP(210+60,245,BMP_SZ_3[2],YELLOW,BLACK);//

  //x=180,y=120; 
  for(i=0;i<4;i++){
    LCD_DrawRect(180+60,120+35+40*i,320,2,GRAY);//横  
  }
    LCD_DrawRect(180+60,120+35,2,120,GRAY); //竖
    LCD_DrawRect(260+60,120+35,2,120,GRAY); //
    LCD_DrawRect(380+60,120+35,2,120,GRAY); //
    LCD_DrawRect(498+60,120+35,2,120,GRAY); //
}
unsigned int new_pluse=1000;
void update_setDATE(void){
    unsigned int temp=0; 
    unsigned int x=180,y=120;
    unsigned long Ftemp=0; 
  //print_SZ(x+145+60, y,enTime,2,0,GREEN);    
    print_SZ_2(x+100+60,y+85,e_hm_pulse,5,0,GREEN);//   
    print_SZ_2(x+210+60,y+85,Vspeed,4,1,GREEN);//车速

  //目标值
    print_SZ_2(x+100+60,y+125,new_pluse,5,0,RED); // 
    //Ftemp=30.0*DJ_speed; //车速 
    //temp=(unsigned int)(Ftemp/new_pluse);    //车速
    temp = (unsigned int)((unsigned long)3600*freq[0]/new_pluse);//车速单位0.1KM/H
    print_SZ_2(x+210+60,y+125,temp,4,1,RED);
}

void frm_setDATE(void){
  if(f_index==0){
    f_index=1;
    key_up=0;
    key_reset=0;
    key_set =0;
    key_duble=0;
    LCD_DrawRect(0,60,800,365,BLACK);
    disp_setDATE();
  //Read_enTime();  //取得 使能次数
    new_pluse=e_hm_pulse;//
  //new_pluse=HM_PLUSE;  //  
  //enTime_flag=1;  //使能设定次数记录
  }else if(f_index==1){
    f_index=1;
    update_setDATE();
  }else{
    f_index=0;
  } 
  if(key_set){
     key_set=0;   
     key_up=0;
     key_reset=0;    
     e_hm_pulse=new_pluse;
   //HM_PLUSE=new_pluse;    
     EEROM_WriteHMPulse();//写入
     EEROM_ReadHMPulse(); //读出 校验  
  }

  if(key_reset){
     key_reset=0;
     if(new_pluse<29990)new_pluse+=1;
     else               new_pluse=30000;
  }
  if(key_up){
     key_up=0; 
     if(new_pluse>20) new_pluse-=1;
     else             new_pluse=5;
  }
  if(key_long_set){
     key_long_set=0;
     key_up=0;
     key_reset=0;
     frmID=0;
     f_index=0;
  } 
}


void disp_CAN_baojing(unsigned int x,unsigned int y){
    static unsigned char al_index = 0;
    unsigned int w=0;
    unsigned char color=0;
    unsigned char Fcolor=YELLOW;  
    if (alarm_update_flag == 0) { //3S 更新一次 
        //LCD_DrawRect(x, y, 350 + 85 + 10, 36, BLACK); //清除显示区域
        switch (al_index) {
            case 0:
                al_index = 1;
                //if(1){
                if(0){      
                LCD_DrawImage1BPP(x,    y, Bmp_front,Fcolor,color);
                LCD_DrawImage1BPP(x+16, y, Bmp_MK,   Fcolor,color);
                LCD_DrawImage1BPP(x+56, y, Bmp_CANST,Fcolor,color);                
                LCD_DrawImage1BPP(x+128,y, Bmp_ST[2],Fcolor,color);
                w=x+128+40;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break;   
                }         
            case 1: 
                al_index=2;
                //if(1){
                if(0){
                LCD_DrawImage1BPP(x,    y, Bmp_rear, Fcolor,color);
                LCD_DrawImage1BPP(x+16, y, Bmp_MK,   Fcolor,color);
                LCD_DrawImage1BPP(x+56, y, Bmp_CANST,Fcolor,color);             
                LCD_DrawImage1BPP(x+128,y, Bmp_ST[2],Fcolor,color);
                w=x+128+40;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                }
            case 2: 
                al_index=3; 
                //if(1){
                if(0){
                LCD_DrawImage1BPP(x,    y, Bmp_top,  Fcolor,color);
                LCD_DrawImage1BPP(x+16, y, Bmp_MK,   Fcolor,color);
                LCD_DrawImage1BPP(x+56, y, Bmp_CANST,Fcolor,color);              
                LCD_DrawImage1BPP(x+128,y, Bmp_ST[2],Fcolor,color);
                w=x+128+40;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                }
            case 3: 
                al_index=4; 
                //if(1){
                if(ECU_TIME>=CAN_TIME){
                LCD_DrawImage1BPP(x,    y, Bmp_ECU,  Fcolor,color);
                LCD_DrawImage1BPP(x+40, y, Bmp_CANST,Fcolor,color);               
                LCD_DrawImage1BPP(x+112,y, Bmp_ST[2],Fcolor,color);
                w=x+112+40;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                }
            case 4: 
                al_index=5; 
                //if(1){
                //if(LED16){ //蓄电池电压低  
                if(BAT24V_count >= BAT24_TIME){//蓄电池电压低
                LCD_DrawImage1BPP(x,    y, Bmp_xdc,Fcolor,color);
                LCD_DrawImage1BPP(x+56, y, Bmp_DY, Fcolor,color);
                LCD_DrawImage1BPP(x+96, y, Bmp_gd, Fcolor,color);
                w=x+96+40;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                }
            case 5: 
                al_index=6; 
                //if(1){
                if(Vspeed>650){ //您已超速      
                LCD_DrawImage1BPP(x, y, Bmp_nycs,Fcolor,color);
                w=x+80;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                } 
            case 6: 
                al_index=7; 
                //if(1){
                if(LED9){ //前气压报警      
                LCD_DrawImage1BPP(x,    y, Bmp_front,Fcolor,color);
                LCD_DrawImage1BPP(x+16, y, Bmp_qy,Fcolor,color);
                LCD_DrawImage1BPP(x+56, y, Bmp_bj,Fcolor,color);
                w=x+56+40;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                } 
            case 7: 
                al_index=8; 
                //if(1){
                if(LED11){ //后气压报警      
                LCD_DrawImage1BPP(x,    y, Bmp_rear,Fcolor,color);
                LCD_DrawImage1BPP(x+16, y, Bmp_qy,Fcolor,color);
                LCD_DrawImage1BPP(x+56, y, Bmp_bj,Fcolor,color);
                w=x+56+40;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                } 
            case 8: 
                al_index=9; 
                //if(1){
                if(LED7){ //水温报警      
                LCD_DrawImage1BPP(x,    y, Bmp_sw,Fcolor,color);
                LCD_DrawImage1BPP(x+40, y, Bmp_bj,Fcolor,color);
                w=x+40+40;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                } 
            case 9: 
                al_index=10; 
                //if(1){
                if(LED6){ //机油压力报警      
                LCD_DrawImage1BPP(x,    y, Bmp_jyou,Fcolor,color);
                LCD_DrawImage1BPP(x+40, y, Bmp_yl,Fcolor,color);                
                LCD_DrawImage1BPP(x+80, y, Bmp_bj,Fcolor,color);
                w=x+80+40;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                } 
            case 10: 
                al_index=11; 
                //if(1){
                if(IN17){ //水位报警      
                LCD_DrawImage1BPP(x,    y, Bmp_SWei,Fcolor,color);
                LCD_DrawImage1BPP(x+40, y, Bmp_bj,Fcolor,color);
                w=x+40+40;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                }
            case 11: 
                al_index=12; 
                //if(1){
                if(IN4  && (Vspeed > 50)){ //前门未关报警     
                LCD_DrawImage1BPP(x,    y, Bmp_front,Fcolor,color);
                LCD_DrawImage1BPP(x+16, y, Bmp_Door,Fcolor,color);
                LCD_DrawImage1BPP(x+32, y, Bmp_WGuan,Fcolor,color);              
                LCD_DrawImage1BPP(x+72, y, Bmp_bj,Fcolor,color);
                w=x+72+40;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                } 
            case 12: 
                al_index=13; 
                //if(1){
                if(IN3  && (Vspeed > 50)){ //后门未关报警     
                LCD_DrawImage1BPP(x,    y, Bmp_rear,Fcolor,color);
                LCD_DrawImage1BPP(x+16, y, Bmp_Door,Fcolor,color);
                LCD_DrawImage1BPP(x+32, y, Bmp_WGuan,Fcolor,color);              
                LCD_DrawImage1BPP(x+72, y, Bmp_bj,Fcolor,color);
                w=x+72+40;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                }   
            case 13: 
                al_index=14; 
                //if(1){
                if(!IN28){ //左前蹄片报警    
                LCD_DrawImage1BPP(x,    y, Bmp_left,Fcolor,color);
                LCD_DrawImage1BPP(x+16, y, Bmp_front,Fcolor,color);
                LCD_DrawImage1BPP(x+32, y, Bmp_FKL44,Fcolor,color);              
                LCD_DrawImage1BPP(x+88, y, Bmp_bj,Fcolor,color);
                w=x+88+40;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                } 
            case 14: 
                al_index=15; 
                //if(1){
                if(!IN27){ //右前蹄片报警    
                LCD_DrawImage1BPP(x,    y, Bmp_right,Fcolor,color);
                LCD_DrawImage1BPP(x+16, y, Bmp_front,Fcolor,color);
                LCD_DrawImage1BPP(x+32, y, Bmp_FKL44,Fcolor,color);              
                LCD_DrawImage1BPP(x+88, y, Bmp_bj,Fcolor,color);
                w=x+88+40;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                }    
            case 15: 
                al_index=16; 
                //if(1){
                if(!IN21){ //左后蹄片报警    
                LCD_DrawImage1BPP(x,    y, Bmp_left,Fcolor,color);
                LCD_DrawImage1BPP(x+16, y, Bmp_rear,Fcolor,color);
                LCD_DrawImage1BPP(x+32, y, Bmp_FKL44,Fcolor,color);              
                LCD_DrawImage1BPP(x+88, y, Bmp_bj,Fcolor,color);
                w=x+88+40;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                }   
            case 16: 
                al_index=17; 
                //if(1){
                if(!IN22){ //右后蹄片报警    
                LCD_DrawImage1BPP(x,    y, Bmp_right,Fcolor,color);
                LCD_DrawImage1BPP(x+16, y, Bmp_rear,Fcolor,color);
                LCD_DrawImage1BPP(x+32, y, Bmp_FKL44,Fcolor,color);              
                LCD_DrawImage1BPP(x+88, y, Bmp_bj,Fcolor,color);
                w=x+88+40;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                } 
            case 17: 
                al_index=18; 
                //if(1){
                if(0){ //前气压传感器故障    
                LCD_DrawImage1BPP(x,    y, Bmp_front,Fcolor,color);
                LCD_DrawImage1BPP(x+16, y, Bmp_qy,Fcolor,color);         
                LCD_DrawImage1BPP(x+56, y, Bmp_CGQi,Fcolor,color);              
                LCD_DrawImage1BPP(x+112, y, Bmp_ST[0],Fcolor,color);
                w=x+112+40;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                } 
            case 18: 
                al_index=19; 
                //if(1){
                if(0){ //后气压传感器故障    
                LCD_DrawImage1BPP(x,    y, Bmp_rear,Fcolor,color);
                LCD_DrawImage1BPP(x+16, y, Bmp_qy,Fcolor,color);         
                LCD_DrawImage1BPP(x+56, y, Bmp_CGQi,Fcolor,color);              
                LCD_DrawImage1BPP(x+112, y, Bmp_ST[0],Fcolor,color);
                w=x+112+40;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                }        
            case 19: 
                al_index=20; 
                //if(1){
                if(0){ //燃油传感器故障    
                LCD_DrawImage1BPP(x,    y, Bmp_RYou,Fcolor,color);         
                LCD_DrawImage1BPP(x+40, y, Bmp_CGQi,Fcolor,color);              
                LCD_DrawImage1BPP(x+96, y, Bmp_ST[0],Fcolor,color);
                w=x+96+40;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                }  
            case 20: 
                al_index=0; 
                //if(1){
                if(IN2  && (Vspeed > 50)){ //仓门未关报警     
                LCD_DrawImage1BPP(x,    y, Bmp_CWen,Fcolor,color);
                LCD_DrawImage1BPP(x+16, y, Bmp_Door,Fcolor,color);
                LCD_DrawImage1BPP(x+32, y, Bmp_WGuan,Fcolor,color);              
                LCD_DrawImage1BPP(x+72, y, Bmp_bj,Fcolor,color);
                w=x+72+40;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                }    
                  
            default:
                al_index=0; 
                LCD_DrawRect(x, y, 250, 36, color); //清除显示区域
                break;
        }
               
    }
}

void LCD_Exec(void) {
  static unsigned char disp_flag=0;
  if(disp_flag==0){
    disp_flag=1;
    if(frmID != 29)disp_time(330, 430 + 12, timer);
  }else if(disp_flag==1){
    disp_flag=0;
    if(frmID != 29)disp_CAN_baojing(20,455-11);//
  }else{
    disp_flag=0;
  }
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
 
            
        case 28:
            frmIC();
            break; 
        case 29:   
            frmTIME_SET();           
            break;  
        case 30: 
            frm_speed();
            break; 
        case 31:
            frm_code();//
            break;
        case 32:
            frm_system();//设置参数信息
            break;
        case 33:
            frm_setDATE();//设置参数信息
            break;
        case 34:
            frm_miles();//设置参数信息
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



