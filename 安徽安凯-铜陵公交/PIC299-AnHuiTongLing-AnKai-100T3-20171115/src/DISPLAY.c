#include "SYSTEM.h"
#include "FONT.h"
#include "LOGO.h"
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

void update_degX(unsigned int x,unsigned int y,unsigned int temp,unsigned int Z,unsigned char color){
     unsigned char s=0; 
     if(temp==0xFFFF)color=BLACK;      
     if(temp>=Z){temp=temp-Z; s=12;}
     else       {temp=Z-temp; s=11;}  
     update_dl(x,y,temp,3,s,color);
}

/*
void LCD_DrawImageSBPP(unsigned int x, unsigned int y, //没有文字，字数填0，字模为BMP_BLANK       
        unsigned char witdh, //字体宽度
        __prog__ const unsigned char *img[], //字符串首地址
        unsigned char fcolor, //字体前景色
        unsigned char bcolor  //字体背景色
        ) {
    unsigned char i;
    for (i = 0; img[i] != NULL; i++) {
        LCD_DrawImage1BPP(x + witdh * i, y, img[i], fcolor, bcolor);
    }
}
*/

void LCD_DrawImageSBPP(unsigned int x, unsigned int y, //没有文字，字数填0，字模为BMP_BLANK       
                       //unsigned char witdh, //字体宽度
                         __prog__ const unsigned char *img[], //字符串首地址
                         unsigned char fcolor, //字体前景色
                         unsigned char bcolor  //字体背景色
        ) {
    unsigned char i;
    unsigned char witdh=0;
    unsigned char wide=0;  
    for (i = 0; img[i] != NULL; i++) {
        LCD_DrawImage1BPP(x + witdh, y, img[i], fcolor, bcolor);
        wide=(*(img[i]+1)*8);
        witdh=witdh+wide;
    }
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

void updata_DCDY(unsigned int x, unsigned int y) {
    //unsigned char color = GREEN;
    unsigned int DCDY = 50;
    DCDY = DC_voltage * 0.1;
 
    if (DCDY >= 800) DCDY = 800;
    print_SZ_1(x, y, (DCDY), 3, 0, WHITE); //电池电压数值 x=120+72+30   y=150+60-2
    if (DCDY > 0   && frmID == 0)
        LCD_DrawRect(225 + 2, 100+13 + 5 + 2, ((DCDY) * 3.31 * 0.125), 28, GREEN); // 331/100  
    if (DCDY < 800 && frmID == 0)//当为100时会出错
        LCD_DrawRect((225 + 2 + (DCDY) * 3.31 * 0.125), 100 +13+ 5 + 2, (331 - (DCDY) * 3.31 * 0.125), 28, BLACK);  

}

void updata_DCDL(unsigned int x, unsigned int y) {
    unsigned int DCDL = 100;
    DCDL = DC_current * 0.1;

        if (DCDL < 3200) {
        DCDL = 3200 - DCDL;
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
        DCDL = DCDL - 3200;
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
    soc = DC_SOC*0.4 ;
    if (soc >= 100) soc = 100;
    
    if(soc>0){
       if( (DC_Status[1]&0x40) ||  //SOC过低
           (DC_Status[1]&0x08)     //SOC低
         )color = RED;else  color = GREEN;
    }else                   color = BLACK;
    print_SZ_1(585, 100 + 13 + 5 + 60 + 60 - 10, soc, 3, 0, WHITE); //SOC数值
    LCD_DrawRect(225 + 2, 100 + 13 + 5 + 60 + 60 + 2 - 10, (soc * 3.31), 28, color); // 331/100  
    if (soc < 100)//当soc为100时会出错//此时函数溢出
        LCD_DrawRect((225 + 2 + soc * 3.31), 100 + 13 + 5 + 60 + 60 + 2 - 10, (331 - soc * 3.31), 28, BLACK);
}

void disp_VAS(void){
    LCD_DrawImage1BPP(175-5, 110 + 13, Bmp_DY, WHITE, BLACK); //电压
    LCD_DrawRect(225, 100 + 5 + 13, 335, 2, WHITE);
    LCD_DrawRect(225, 100 + 35 + 13, 335, 2, WHITE);
    LCD_DrawRect(225, 105 + 13, 2, 32, WHITE);
    LCD_DrawRect(225 + 83, 95 + 13, 2, 10, WHITE);
    LCD_DrawRect(225 + 83 + 83, 95 + 13, 2, 10, WHITE);
    LCD_DrawRect(225 + 83 + 83 + 83, 95 + 13, 2, 10, WHITE);
    LCD_DrawRect(225 + 83 + 83 + 83 + 84, 105 + 13, 2, 32, WHITE);
    LCD_DrawImage1BPP(225 - 4, 105 - 14 + 13, BMP_SZ[0], WHITE, BLACK); //0
    LCD_DrawImage1BPP(225 + 83 + 83 + 83 + 84 - 12, 105 - 14 + 13, BMP_SZ[8], WHITE, BLACK); //8
    LCD_DrawImage1BPP(225 + 83 + 83 + 83 + 84 - 4, 105 - 14 + 13, BMP_SZ[0], WHITE, BLACK); //0
    LCD_DrawImage1BPP(225 + 83 + 83 + 83 + 84 + 4, 105 - 14 + 13, BMP_SZ[0], WHITE, BLACK); //0   
    LCD_DrawImage1BPP(660-20, 105 + 13+8, Bmp_V, WHITE, BLACK); // V    
//显示电流
    LCD_DrawImage1BPP(175-5, 110 + 60 + 13-5, Bmp_dl, WHITE, BLACK); //电流   
    LCD_DrawRect(225, 100 + 5 + 60 + 13-5, 335, 2, WHITE);
    LCD_DrawRect(225, 100 + 35 + 60 + 13-5, 335, 2, WHITE);
    LCD_DrawRect(225, 105 + 60 + 13-5, 2, 32, WHITE);
    LCD_DrawRect(225 + 83, 95 + 60 + 13-5, 2, 10, WHITE);
    LCD_DrawRect(225 + 83 + 83 + 83, 95 + 60 + 13-5, 2, 10, WHITE);
    LCD_DrawRect(225 + 83 + 83 + 83 + 83 + 1, 105 + 60 + 13-5, 2, 32, WHITE);
    LCD_DrawRect(225 - 12, 105 - 14 + 60 + 7 + 13-5, 8, 2, WHITE); //-
    LCD_DrawImage1BPP(225 - 4, 105 - 14 + 60 + 13-5, BMP_SZ[5], WHITE, BLACK); //5
    LCD_DrawImage1BPP(225 + 4, 105 - 14 + 60 + 13-5, BMP_SZ[0], WHITE, BLACK); //0
    LCD_DrawImage1BPP(225 + 12, 105 - 14 + 60 + 13-5, BMP_SZ[0], WHITE, BLACK); //0
    LCD_DrawImage1BPP(225 + 83 + 83 - 4, 95 + 60 - 4 + 13-5, BMP_SZ[0], WHITE, BLACK); //0
    LCD_DrawRect(225 + 83 + 83, 105 + 60 + 13-5, 2, 32, WHITE); 
    LCD_DrawImage1BPP(225 + 83 + 83 + 83 + 84 - 12, 105 - 14 + 60 + 13-5, BMP_SZ[5], WHITE, BLACK); //5
    LCD_DrawImage1BPP(225 + 83 + 83 + 83 + 84 - 4, 105 - 14 + 60 + 13-5, BMP_SZ[0], WHITE, BLACK); //0
    LCD_DrawImage1BPP(225 + 83 + 83 + 83 + 84 + 4, 105 - 14 + 60 + 13-5, BMP_SZ[0], WHITE, BLACK); //0
    LCD_DrawImage1BPP(660-20, 105 + 60 + 13-5+8, Bmp_A, WHITE, BLACK); //A
//显示SOC
    LCD_DrawImage1BPP(170+3, 100 + 5 + 60 + 60 + 13-10+5, Bmp_SOC, WHITE, BLACK); //SOC
    LCD_DrawRect(225, 100 + 5 + 60 + 60 + 13-10, 335, 2, WHITE);
    LCD_DrawRect(225, 100 + 35 + 60 + 60 + 13-10, 335, 2, WHITE);
    LCD_DrawRect(225, 105 + 60 + 60 + 13-10, 2, 32, WHITE);
    LCD_DrawRect(225 + 83 + 83 + 83 + 84, 105 + 60 + 60 + 13-10, 2, 32, WHITE);    
    //LCD_DrawRect(225 + 83, 95 + 60 + 60 + 13-10, 2, 10, WHITE);
    //LCD_DrawRect(225 + 83 + 83, 95 + 60 + 60 + 13-10, 2, 10, WHITE);
    //LCD_DrawRect(225 + 83 + 83 + 83, 95 + 60 + 60 + 13-10, 2, 10, WHITE);
    //LCD_DrawImage1BPP(225 - 4, 105 - 14 + 60 + 60 + 13-10, BMP_SZ[0], WHITE, BLACK); //0
    //LCD_DrawImage1BPP(225 + 83 + 83 + 83 + 84 - 12, 105 - 14 + 60 + 60 + 13-10, BMP_SZ[1], WHITE, BLACK); //1
    //LCD_DrawImage1BPP(225 + 83 + 83 + 83 + 84 - 4, 105 - 14 + 60 + 60 + 13-10, BMP_SZ[0], WHITE, BLACK); //0
    //LCD_DrawImage1BPP(225 + 83 + 83 + 83 + 84 + 4, 105 - 14 + 60 + 60 + 13-10, BMP_SZ[0], WHITE, BLACK); //0
    LCD_DrawImage1BPP(225 + 83 + 83 + 83 + 84+2, 105 + 60 + 60 + 13, Bmp_dji, WHITE, BLACK); //    
    LCD_DrawImage1BPP(660-20, 105 + 60 + 60 + 13-10+8, Bmp_bfh, WHITE, BLACK); // %
}

void mainFrame(void) {
    unsigned int i;
    LCD_Clear();
    LCD_DrawRect(0, 430, 800, 2, GRAY);//底部横线
    LCD_DrawRect(0, 0,   800, 1, GRAY);//上横线
    LCD_DrawRect(0, 50,  800, 1, GRAY);//下横线
    
    LCD_DrawRect(122,100,550,1,GRAY);//第二横线
    for(i=1;i<13;i++)
    LCD_DrawRect(61*i,0,1,50,GRAY);//竖线

    for(i=2;i<12;i++)
    LCD_DrawRect(61*i,50,1,50,GRAY);//竖线

   
    //每次进入主界面，符号片颜色都是灰色，若不处理，只会第一次上电显示灰色，翻页后就不显示灰色
    for (i = 0; i < 24; i++) {
        color_old[i] = 1;
    }
    
   disp_VAS();//显示电压，电流，SOC框架

x=161;y=265;
   for(i=0;i<5;i++){
   lcd_show_1color(x,y+i*30,478, 1,GRAY);//-
   }
x=161;//y=y+30;
   lcd_show_1color(x,y,1, 90+30,GRAY);//|左
x=391+9;
   lcd_show_1color(x,y,1, 90+30,GRAY);//|中
x=639;
   lcd_show_1color(x,y,1, 90+30,GRAY);//|右

//第一列
x=221-58;y=280-9;
   for(i=0;i<3;i++){
   lcd_show_9dot(x,       y+i*30, Bmp_main_interface_1_L_1[i], WHITE, BLACK);//
   lcd_show_9dot(x+208,   y+i*30, Bmp_main_interface_1_L_2[i], WHITE, BLACK);//单位符号
   }

//第二列
x=433-40+9;y=280-9;
   for(i=0;i<4;i++){
   lcd_show_9dot(x,       y+i*30, Bmp_main_interface_1_R_1[i], WHITE, BLACK);//
   lcd_show_9dot(x+217,   y+i*30, Bmp_main_interface_1_L_2[3], WHITE, BLACK);//单位符号
   }   
    
//显示里程
x=221-58;y=407-9;
    LCD_DrawImageSBPP(x,   y, Bmp_main_interface_3_L_1[0], WHITE, BLACK);//    
x=440-40; 
    LCD_DrawImageSBPP(x,   y, Bmp_main_interface_3_L_1[1], WHITE, BLACK);// 
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
x=333-32-16;y=280-9;
//最大单体电池电压
  print_SZ_2(x,    y+0*30,(Vmax),           4,3,WHITE);
//最小单体电池电压
  print_SZ_2(x,    y+1*30,(Vmin),           4,3,WHITE);
//续驶里程
  print_SZ_2(x,    y+2*30,(XHLC),           4,1,WHITE);
  
/////////////第二列/////////////
x=581-32;y=280-9;  
//最大单体电池温度
  update_deg(x,y+0*30, Tmax,        WHITE);
//最小单体电池温度
  update_deg(x,y+1*30, Tmin,        WHITE);
//电机控制器温度
  update_deg(x,y+2*30, DJcontroler_temperature,WHITE);  
//电机温度
  update_deg(x,y+3*30, DJ_temperature,WHITE);

}

void disp_baojing2(void){
  unsigned char i,color=GRAY;
  unsigned char temp8=0;
        
  if( DJ_Status[1]&0X01 )color=RED;else color=GRAY;
  LCD_DrawImage1BPP(122+10, 10+50,Bmp_DJGRe,color,BLACK);//电机过热 
  
  if(VCU_Status[0] & 0x02)color=YELLOW;else color=GRAY;//充电盖
  lcd_show_8dot(214-20,75-18,Bmp_TB_CDGai,color,BLACK);//
  
  if(fKL3) color=GREEN;
  else     color=GRAY; 
  LCD_DrawImage1BPP(274-20,75-20,Bmp_ml,color,BLACK);//门铃开关 
  
  if((VCU_Status[4]&0X04))color=GREEN;//READY
  else                    color=GRAY; 
  lcd_show_8dot(336-28, 75-12,Bmp_READY,color,BLACK);
  
  switch(VCU_Status[1]&0X70){
   case 0x10:color=GREEN;i=0;
   break;
   case 0x40:color=RED;i=1;
   break;
   case 0x20:color=GREEN;i=2;
   break;  
   default: color=GRAY;i=0;
   break; 
  }
  lcd_show_8dot(384,62,Bmp_NRD[i],color,BLACK);//D  
    
                if(  ((Tire_Status[0]&0x03)==0x01)|| //高温报警
                     ((Tire_Status[0]&0x0C)==0x04)|| //漏气报警
                     ((Tire_fault[0]&0xE0)==0x00) || //高压报警
                     ((Tire_fault[0]&0xE0)==0x20) || //高压预警
                     ((Tire_fault[0]&0xE0)==0x60) || //低压预警    
                     ((Tire_fault[0]&0xE0)==0x80) || //低压报警 
                        
                     ((Tire_Status[1]&0x03)==0x01)|| //高温报警
                     ((Tire_Status[1]&0x0C)==0x04)|| //漏气报警
                     ((Tire_fault[1]&0xE0)==0x00) || //高压报警
                     ((Tire_fault[1]&0xE0)==0x20) || //高压预警
                     ((Tire_fault[1]&0xE0)==0x60) || //低压预警    
                     ((Tire_fault[1]&0xE0)==0x80) || //低压报警       
                        
                     ((Tire_Status[2]&0x03)==0x01)|| //高温报警
                     ((Tire_Status[2]&0x0C)==0x04)|| //漏气报警
                     ((Tire_fault[2]&0xE0)==0x00) || //高压报警
                     ((Tire_fault[2]&0xE0)==0x20) || //高压预警
                     ((Tire_fault[2]&0xE0)==0x60) || //低压预警    
                     ((Tire_fault[2]&0xE0)==0x80) || //低压报警                   
                       
                     ((Tire_Status[3]&0x03)==0x01)|| //高温报警
                     ((Tire_Status[3]&0x0C)==0x04)|| //漏气报警
                     ((Tire_fault[3]&0xE0)==0x00) || //高压报警
                     ((Tire_fault[3]&0xE0)==0x20) || //高压预警
                     ((Tire_fault[3]&0xE0)==0x60) || //低压预警    
                     ((Tire_fault[3]&0xE0)==0x80) || //低压报警      
                        
                     ((Tire_Status[4]&0x03)==0x01)|| //高温报警
                     ((Tire_Status[4]&0x0C)==0x04)|| //漏气报警
                     ((Tire_fault[4]&0xE0)==0x00) || //高压报警
                     ((Tire_fault[4]&0xE0)==0x20) || //高压预警
                     ((Tire_fault[4]&0xE0)==0x60) || //低压预警    
                     ((Tire_fault[4]&0xE0)==0x80) || //低压报警     
                        
                     ((Tire_Status[5]&0x03)==0x01)|| //高温报警
                     ((Tire_Status[5]&0x0C)==0x04)|| //漏气报警
                     ((Tire_fault[5]&0xE0)==0x00) || //高压报警
                     ((Tire_fault[5]&0xE0)==0x20) || //高压预警
                     ((Tire_fault[5]&0xE0)==0x60) || //低压预警    
                     ((Tire_fault[5]&0xE0)==0x80)    //低压报警                               
                   ) {color=RED; F_TaiYa=1;} else {color=GRAY;F_TaiYa=0;}//胎压报警
  lcd_show_8dot(458-20,75-18,Bmp_TB_TaiYa,color,BLACK);//  
  
  if(VCU_Status[0] & 0x80)color=GREEN;else color=GRAY;//电制动
  lcd_show_8dot(640-24,75-18,Bmp_TB_DZDong,color,BLACK);//
  
}

void disp_baojing(void){
  unsigned char color=GRAY;
  unsigned int  temp;
  
  if(mKL8 ) color=RED;
  else             color=GRAY; 
  LCD_DrawImage1BPP(30-20,5,Bmp_yjf,color,BLACK);//车内应急阀开启报警开关 
  
  if(!fKL4 || !fKL5)color=RED;//左前 //右前
  else              color=GRAY; 
  if (color_old[0] != color) {
      color_old[0]  = color;
  LCD_DrawImage1BPP(91-24,25-18,Bmp_mcp, color,BLACK);//蹄片磨损
  //LCD_DrawImage1BPP(91-10, 25-6, Bmp_mcpL,color,BLACK);//L
  //LCD_DrawImage1BPP(91+2,25-7,BMP_SZ[1],color,BLACK);
  }
  
  if(!fKL8)color=RED;//左后  
  else     color=GRAY;
  if (color_old[1] != color) {
      color_old[1]  = color;
  //LCD_DrawImage1BPP(152-24,25-18,Bmp_mcp, color,BLACK);//蹄片磨损
  //LCD_DrawImage1BPP(152-10, 25-6, Bmp_mcpL,color,BLACK);//L
  //LCD_DrawImage1BPP(152+2,25-7,BMP_SZ[2],color,BLACK);
  }
  
  if(  rKL15 ) color=RED;
  else         color=GRAY; 
  LCD_DrawImage1BPP(216-28,25-24,Bmp_HCM,color,BLACK);//后舱门
  
  if(  rKL7 ) color=RED;
  else        color=GRAY; 
  LCD_DrawImage1BPP(275-18,25-18,Bmp_SW,color,BLACK);//水位报警

   //一级故障红色   报警，二级故障白色   停车立即检查
  temp=(R_ID&0X30)>>4;
  if(temp==1)     color=RED;
  else if(temp==2)color=WHITE;
  else            color=GRAY;   
  //LCD_DrawImage1BPP(457-14, 25-20,Bmp_jygz,color,BLACK);//绝缘故障报警
  
  if((VCU_Status[4]&0x02))color=RED; 
  else                    color=GRAY; 
  LCD_DrawImage1BPP(518-20, 25-15,Bmp_XTgz,color,BLACK);//系统故障
  
  if((VCU_Status[3]&0X80)==0x00){color=YELLOW; LCD_DrawImage1BPP(580-20, 25-14,Bmp_DCQDuan,color,BLACK); }//断开
  else                          {color=GREEN;  LCD_DrawImage1BPP(580-20, 25-14,Bmp_DCQDuan2,color,BLACK);}//闭合

  if(!fKL5) color=RED; //右前  
  else      color=GRAY; 
  if (color_old[2] != color) {
      color_old[2]  = color;
  //LCD_DrawImage1BPP(640-24,25-18,Bmp_mcp, color,BLACK);//蹄片磨损
  //LCD_DrawImage1BPP(640-10, 25-6, Bmp_mcpR,color,BLACK);//R
  //LCD_DrawImage1BPP(640+2,25-7,BMP_SZ[1],color,BLACK);
  }
  
  if(!fKL9) color=RED; //右后 
  else      color=GRAY; 
  if (color_old[3] != color) {
      color_old[3]  = color;
  //LCD_DrawImage1BPP(702-24,25-18,Bmp_mcp, color,BLACK);//蹄片磨损
  //LCD_DrawImage1BPP(702-10, 25-6, Bmp_mcpR,color,BLACK);//R
  //LCD_DrawImage1BPP(702+2,25-7,BMP_SZ[2],color,BLACK);
  }
  
  if(IN34 ) color=RED;
  else      color=GRAY; 
  LCD_DrawImage1BPP(762-20,5,Bmp_yjf,color,BLACK);//车外应急阀开启报警开关 

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
      //disp_CAR();
    } else if (f_index == 1) {
        f_index = 2;   
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
        updata_DCDL(585, 105 + 13 + 60-5);
    } else if (f_index == 5) {
        f_index = 6;
        updata_SOC();
    } else if (f_index == 6) {
        f_index = 7;
        updata_DCDY(585, 105 + 13);//
    } else if (f_index == 7) {
        f_index = 1;      
    } else {
        f_index = 0;
    }

    if (AV_CH == 0) { //当在数字界面
        if (key_up) { //调节背光灯
            key_up = 0;
            if ((LED15 == 1) && (!time_flag) ) {//背光开启
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
  LCD_DrawImageSBPP(x,y+0*34,Bmp_IN1,WHITE,BLACK);  
  LCD_DrawImage1BPP(x,y+1*34,Bmp_IN2,WHITE,BLACK); 
  LCD_DrawImage1BPP(x,y+2*34,Bmp_IN3,WHITE,BLACK);
  LCD_DrawImageSBPP(x,y+3*34,Bmp_IN4,WHITE,BLACK);
  LCD_DrawImageSBPP(x,y+4*34,Bmp_IN5,WHITE,BLACK); 
  
  LCD_DrawImage1BPP(x,y+5*34,Bmp_IN6,WHITE,BLACK);
  LCD_DrawImageSBPP(x,y+6*34,Bmp_IN7,WHITE,BLACK);
  LCD_DrawImageSBPP(x,y+7*34,Bmp_IN8,WHITE,BLACK);
  LCD_DrawImageSBPP(x,y+8*34,Bmp_IN9,WHITE,BLACK);
  LCD_DrawImageSBPP(x,y+9*34,Bmp_IN10,WHITE,BLACK);
//第二列 
  x=500;y=95;
  LCD_DrawImage1BPP(x,y+0*34,Bmp_KL,WHITE,BLACK);// 
  LCD_DrawImage1BPP(x,y+1*34,Bmp_KL,WHITE,BLACK);// 
  LCD_DrawImage1BPP(x,y+2*34,Bmp_KL,WHITE,BLACK);// 
  
  disp_yg(x,y+3*34,Bmp_IN14);
  disp_yg(x,y+4*34,Bmp_IN15);
  disp_yg(x,y+5*34,Bmp_IN16);  
  
  LCD_DrawImage1BPP(x,y+6*34,Bmp_IN17,WHITE,BLACK);// 
  LCD_DrawImage1BPP(x,y+7*34,Bmp_IN18,WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+8*34,Bmp_IN19,WHITE,BLACK);// 
  LCD_DrawImageSBPP(x,y+9*34,Bmp_IN20,WHITE,BLACK);//
  
  unsigned int Iid1[20]={154,0,0,136,154,120,136,136,136,136,
                         0,0,0,580,580,580,540,0,540,550};
  disp_kg(Iid1);  //显示开关
}
//显示仪表开关2
void disp_KL2(void){
  unsigned int Iid[20]={17,18,19,20,28,27,26,25,32,31,
                        30,29,1,2,3,4,5,10,20,13};
  disp_ID(0,Iid); //显示编号
  x=80;y=95;
  disp_yg(x,y+0*34,Bmp_IN21);
  LCD_DrawImageSBPP(x,y+1*34,Bmp_IN22,WHITE,BLACK);
  LCD_DrawImageSBPP(x,y+2*34,Bmp_IN23,WHITE,BLACK);
  LCD_DrawImageSBPP(x,y+3*34,Bmp_IN24,WHITE,BLACK);
  LCD_DrawImageSBPP(x,y+4*34,Bmp_IN25,WHITE,BLACK);
  LCD_DrawImageSBPP(x,y+5*34,Bmp_IN26,WHITE,BLACK);
  LCD_DrawImageSBPP(x,y+6*34,Bmp_IN27,WHITE,BLACK);
  LCD_DrawImageSBPP(x,y+7*34,Bmp_IN28,WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+8*34,Bmp_IN29,WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+9*34,Bmp_IN30,WHITE,BLACK);
//第二列 
  x=500;y=95;
  LCD_DrawImage1BPP(x,y+0*34,Bmp_IN31,WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+1*34,Bmp_IN32,WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+2*34,Bmp_IN33,WHITE,BLACK); 
  LCD_DrawImageSBPP(x,y+3*34,Bmp_IN34,WHITE,BLACK); 
  LCD_DrawImage1BPP(x,y+4*34,Bmp_IN35,WHITE,BLACK); 
  LCD_DrawImage1BPP(x,y+5*34,Bmp_IN36,WHITE,BLACK); 
  LCD_DrawImage1BPP(x,y+6*34,Bmp_IN37,WHITE,BLACK);
  LCD_DrawImageSBPP(x,y+7*34,Bmp_IN38,WHITE,BLACK);   
  LCD_DrawImageSBPP(x,y+8*34,Bmp_IN39,WHITE,BLACK);
  LCD_DrawImageSBPP(x,y+9*34,Bmp_IN40,WHITE,BLACK);
  
  unsigned int Iid1[20]={160,136,176,176,160,130,130,130,0,0,
                         0,0,0,636,0,0,0,580,569,560,};
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
     LCD_DrawImage1BPP(x,   y+0*34,Bmp_front, WHITE,BLACK);
     LCD_DrawImage1BPP(x+20,y+0*34,Bmp_SER1, WHITE,BLACK);
     
     LCD_DrawImage1BPP(x,   y+1*34,Bmp_rear,WHITE,BLACK);
     LCD_DrawImage1BPP(x+20,y+1*34,Bmp_SER2, WHITE,BLACK);

   //LCD_DrawImage1BPP(x,   y+2*34,Bmp_front, WHITE,BLACK);
     LCD_DrawImage1BPP(x+20,y+2*34,Bmp_SER3, WHITE,BLACK);
     
   //LCD_DrawImage1BPP(x,   y+3*34,Bmp_rear,WHITE,BLACK);
     LCD_DrawImage1BPP(x+20,y+3*34,Bmp_SER4, WHITE,BLACK);
     
     LCD_DrawImage1BPP(x+20,y+4*34,Bmp_SER5, WHITE,BLACK);
     
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
  LCD_DrawImageSBPP(x,y+4*34,Bmp_front_load5, WHITE,BLACK);
  LCD_DrawImageSBPP(x,y+5*34,Bmp_front_load6, WHITE,BLACK);//
  LCD_DrawImageSBPP(x,y+6*34,Bmp_front_load7, WHITE,BLACK);//
  LCD_DrawImageSBPP(x,y+7*34,Bmp_front_load8, WHITE,BLACK);  
  LCD_DrawImageSBPP(x,y+8*34,Bmp_front_load9, WHITE,BLACK);
  LCD_DrawImageSBPP(x,y+9*34,Bmp_front_load10,WHITE,BLACK);//

//第二列
  x=500;y=95;
  LCD_DrawImageSBPP(x,y+0*34,Bmp_front_load11,WHITE,BLACK);
  LCD_DrawImageSBPP(x,y+1*34,Bmp_front_load12,WHITE,BLACK);
  LCD_DrawImageSBPP(x,y+2*34,Bmp_front_load13,WHITE,BLACK);//
  LCD_DrawImage1BPP(x,y+3*34,Bmp_front_load14,WHITE,BLACK);//
  LCD_DrawImageSBPP(x,y+4*34,Bmp_front_load15,WHITE,BLACK);//
  
}

//前部模块开关信息
void disp_front_KL(void){
  unsigned int Iid[20]={32,18,33,19,34,20,35,21,36,22,
                        37,23,38,24,39,41,17,25,40,26};
  disp_ID(0,Iid);
//第一列
  x=80;y=95;
  LCD_DrawImage1BPP(x,y+0*34,Bmp_FKL1, WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+1*34,Bmp_FKL2, WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+2*34,Bmp_FKL3, WHITE,BLACK);
  LCD_DrawImageSBPP(x,y+3*34,Bmp_FKL4, WHITE,BLACK);
  LCD_DrawImageSBPP(x,y+4*34,Bmp_FKL5, WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+5*34,Bmp_FKL6, WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+6*34,Bmp_FKL7, WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+7*34,Bmp_FKL8, WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+8*34,Bmp_FKL9, WHITE,BLACK);    
  LCD_DrawImage1BPP(x,y+9*34,Bmp_FKL10,WHITE,BLACK);
//第二列 
  x=500;y=95;
  LCD_DrawImage1BPP(x,y+0*34,Bmp_FKL11,WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+1*34,Bmp_FKL12,WHITE,BLACK);
  disp_ADD(1);// KL13 KL14 作为地址线
  LCD_DrawImage1BPP(x,y+4*34,Bmp_FKL15,WHITE,BLACK);
  disp_yg(x,y+5*34,4);
  LCD_DrawImage1BPP(x,y+6*34,Bmp_FKH1,WHITE,BLACK); 

  unsigned int Iid1[20]={0,0,120,192,192,0,0,0,0,0,
                         0,0,0,0,0,580,0,0,0,0};
  disp_kg(Iid1);  //显示开关
}


//后部模块 电源
void disp_rear_load(void){
   unsigned int Iid[20]={1,9,2,10,3,11,4,12,5,13,
                         6,14,7,42,8,17,16,31,0,0};
  disp_ID(1,Iid); //显示编号
  disp_can();
  unsigned char i;
//第一列
  x=80;y=95;
  LCD_DrawImageSBPP(x,y+0*34,Bmp_rear_load1,WHITE,BLACK);  
  LCD_DrawImageSBPP(x,y+1*34,Bmp_rear_load2,WHITE,BLACK);  
  LCD_DrawImageSBPP(x,y+2*34,Bmp_rear_load3,WHITE,BLACK); 
  LCD_DrawImageSBPP(x,y+3*34,Bmp_rear_load4, WHITE,BLACK);//
  LCD_DrawImageSBPP(x,y+4*34,Bmp_rear_load5, WHITE,BLACK);
  LCD_DrawImageSBPP(x,y+5*34,Bmp_rear_load6, WHITE,BLACK);//
  LCD_DrawImageSBPP(x,y+6*34,Bmp_rear_load7, WHITE,BLACK);//
  LCD_DrawImageSBPP(x,y+7*34,Bmp_rear_load8, WHITE,BLACK);
  LCD_DrawImageSBPP(x,y+8*34,Bmp_rear_load9, WHITE,BLACK);
  LCD_DrawImageSBPP(x,y+9*34,Bmp_rear_load10,WHITE,BLACK);//

//第二列
  x=500;y=95;
  LCD_DrawImageSBPP(x,y+0*34,Bmp_rear_load11,WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+1*34,Bmp_rear_load12,WHITE,BLACK);
  LCD_DrawImageSBPP(x,y+2*34,Bmp_rear_load13,WHITE,BLACK);//
  LCD_DrawImage1BPP(x,y+3*34,Bmp_rear_load14,WHITE,BLACK);//
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
  LCD_DrawImageSBPP(x,y+2*34,Bmp_RKL3, WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+3*34,Bmp_RKL4, WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+4*34,Bmp_RKL5, WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+5*34,Bmp_RKL6, WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+6*34,Bmp_RKL7, WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+7*34,Bmp_RKL8, WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+8*34,Bmp_RKL9, WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+9*34,Bmp_RKL10,WHITE,BLACK); 
  
//第二列 
  x=500;y=95;
  LCD_DrawImage1BPP(x,y+0*34,Bmp_RKL11,WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+1*34,Bmp_RKL12,WHITE,BLACK);
  disp_ADD(2);// KL13 KL14 作为地址线
  LCD_DrawImage1BPP(x,y+4*34,Bmp_RKL15,WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+5*34,Bmp_RADD,WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+6*34,Bmp_RKH1,WHITE,BLACK); 

  unsigned int Iid1[20]={0,0,136,0,0,0,120,120,0,0,
                         0,0,0,0,556,0,0,0,0,0};
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
  LCD_DrawImageSBPP(x,y+0*34,Bmp_top_load1, WHITE,BLACK); 
  LCD_DrawImageSBPP(x,y+1*34,Bmp_top_load2, WHITE,BLACK);
  LCD_DrawImageSBPP(x,y+2*34,Bmp_top_load3, WHITE,BLACK);
  LCD_DrawImageSBPP(x,y+3*34,Bmp_top_load4, WHITE,BLACK);
  LCD_DrawImageSBPP(x,y+4*34,Bmp_top_load5, WHITE,BLACK);
  LCD_DrawImageSBPP(x,y+5*34,Bmp_top_load6, WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+6*34,Bmp_top_load7, WHITE,BLACK);
  LCD_DrawImageSBPP(x,y+7*34,Bmp_top_load8, WHITE,BLACK);
  LCD_DrawImageSBPP(x,y+8*34,Bmp_top_load9, WHITE,BLACK);
  LCD_DrawImageSBPP(x,y+9*34,Bmp_top_load10, WHITE,BLACK);

//第二列 
  x=500;y=95;
  LCD_DrawImageSBPP(x,y+0*34,Bmp_top_load11,WHITE,BLACK);
  LCD_DrawImageSBPP(x,y+1*34,Bmp_top_load12,WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+2*34,Bmp_top_load13,WHITE,BLACK);
  LCD_DrawImageSBPP(x,y+3*34,Bmp_top_load14,WHITE,BLACK);
  LCD_DrawImageSBPP(x,y+4*34,Bmp_top_load15,WHITE,BLACK);
  
}

//顶部模块开关信息
void disp_top_KL(void){
  unsigned int Iid[20]={32,18,33,19,34,20,35,21,36,22,
                        37,23,38,24,39,41,17,25,40,26};
  disp_ID(0,Iid);
//第一列  
  x=80;y=95;
  LCD_DrawImage1BPP(x,y+0*34,Bmp_TKL1, WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+1*34,Bmp_TKL2, WHITE,BLACK); 
  LCD_DrawImage1BPP(x,y+2*34,Bmp_TKL3, WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+3*34,Bmp_TKL4, WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+4*34,Bmp_TKL5, WHITE,BLACK); 
  LCD_DrawImage1BPP(x,y+5*34,Bmp_TKL6, WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+6*34,Bmp_TKL7, WHITE,BLACK);
  LCD_DrawImageSBPP(x,y+7*34,Bmp_TKL8, WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+8*34,Bmp_TKL9, WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+9*34,Bmp_TKL10,WHITE,BLACK);

//第二列 +
  x=500;y=95;
  LCD_DrawImage1BPP(x,y+0*34,Bmp_TKL11,WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+1*34,Bmp_TKL12,WHITE,BLACK);
  disp_ADD(3);// KL13 KL14 作为地址线
  LCD_DrawImageSBPP(x,y+4*34,Bmp_TKL15,WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+5*34,Bmp_TADD, WHITE,BLACK); 
  LCD_DrawImageSBPP(x,y+6*34,Bmp_TKH1, WHITE,BLACK); 

  unsigned int Iid1[20]={0,0,0,0,0,0,0,216,0,0,
                         0,0,0,0,598,0,598,0,0,0};
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
     if(Did>=8) Did=0;
     else       Did++;
  }
  if(key_reset){
     if(Did>0)  Did--;
     else       Did=8;
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
    for(i=0;i<9;i++){
    LCD_DrawImageSBPP(x, y+i*30, Bmp_menu_1[i+1],  color, BLACK); //
    }
   
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

    if (i == 18) i = 9;
    if (i == 0)  i = 9;
    
x=320-9;y=75-10;
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
    LCD_DrawImage1BPP(x,  y+0*30, BMP_Choose, color, BLACK);
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
    LCD_DrawImage1BPP(x,  y+1*30, BMP_Choose, color, BLACK);
    if (i == 11 || i == 2) {
        color = GREEN;
        if (key_set) {
            key_set = 0;
            if (time_flag == 0) {
                f_index = 0;
                frmID = 4;//4
            }
            time_flag = 0;
        }
    } else
        color = BLACK;
    LCD_DrawImage1BPP(x,  y+2*30, BMP_Choose, color, BLACK);
    
    if (i == 12 || i == 3) {
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
    LCD_DrawImage1BPP(x,  y+3*30, BMP_Choose, color, BLACK);
    
    if (i == 13 || i == 4) {
        color = GREEN;
        if (key_set) {
            key_set = 0;
            if (time_flag == 0) {
                f_index = 0;
                frmID = 20;//胎压
            }
            time_flag = 0;
        }
    } else
        color = BLACK;
    LCD_DrawImage1BPP(x,  y+4*30, BMP_Choose, color, BLACK);
    
    if (i == 14 || i == 5) {
        color = GREEN;
        if (key_set) {
            key_set = 0;
            if (time_flag == 0) {
                f_index = 0;
                frmID = 28;//仪表
            }
            time_flag = 0;
        }
    } else
        color = BLACK;
    LCD_DrawImage1BPP(x,  y+5*30, BMP_Choose, color, BLACK);
    if (i == 15 || i == 6) {
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
    LCD_DrawImage1BPP(x,  y+6*30, BMP_Choose, color, BLACK);
    if (i == 16|| i == 7) {
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
    LCD_DrawImage1BPP(x,  y+7*30, BMP_Choose, color, BLACK);
    if (i == 17|| i == 8) {
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
    LCD_DrawImage1BPP(x,  y+8*30, BMP_Choose, color, BLACK);
    
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
   for(i=0;i<7;i++){
    lcd_show_9dot(x,   y+i*35, Bmp_KZQ_1_L_1[i+2],WHITE, BLACK);//
   }

x=x+338;//单位符号

///////////////////////第二列///////////////////////
x=463-58;y=84-9; 

x=x+338;


}

void ControlUpdate(void) {
    unsigned int i=0,s,temp=1000;
  
//////////////////////第一列////////////////////
x=305-32;y=84-9;
//制动状态
   if(VCU_Status[1]&0x08)i = 1;else i = 0;
   lcd_show_9dot(x,   y+0*35, Bmp_KZQ_1_L_1[i],WHITE, BLACK);//
//怠速状态
   if(VCU_Status[1]&0x04)i = 1;else i = 0;
   lcd_show_9dot(x,   y+1*35, Bmp_KZQ_1_L_1[i],WHITE, BLACK);//
//电机制动优先信号
   if(VCU_Status[1]&0x01)i = WHITE;else i = BLACK;
   lcd_show_8dot(x,   y+2*35, Bmp_Fa,i, BLACK);//
   lcd_show_8dot(x+18,y+2*35, Bmp_Dian,i, BLACK);//
   //print_SZ_2(x,    y+2*35,i,4,0,YELLOW);//当电机处于发电状态时,此位置 1
//BMS故障码表
   print_SZ_2(x,    y+3*35,GZ_Status[1],4,0,YELLOW);    
//电机控制器故障码表  
   print_SZ_2(x,    y+4*35,GZ_Status[2],4,0,YELLOW);  
//小充电机故障码表    
   print_SZ_2(x,    y+5*35,GZ_Status[3],4,0,YELLOW);  
//整车故障码    
   print_SZ_2(x,    y+6*35,GZ_Status[4],4,0,YELLOW);  
   
//////////////////////第二列////////////////////
x=698-32;y=84-9;


}

void frmControl(void) {
    if (f_index == 0) { //只更新一次
        f_index = 1;
        LCD_DrawRect(0,60,800,365,BLACK);
        LCD_DrawImage1BPP(340,30,    BMP_Control, GREEN, BLACK); //控制
        LCD_DrawImage1BPP(340+40,30, BMP_STSTEM,  GREEN, BLACK); //系统
        LCD_DrawImage1BPP(340+80,30, BMP_Message, GREEN, BLACK); //信息
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

void DJFrame(void) { 
   unsigned int  i=0;

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
   for(i=0;i<6;i++){
   lcd_show_9dot(x,    y+i*35, Bmp_DJ_1_L_1[i],    WHITE, BLACK);//电机
   }

x=x+338;//单位符号
   for(i=0;i<6;i++){
   lcd_show_9dot(x,    y+i*35, Bmp_DJ_1_L_2[i],    WHITE, BLACK);//电机
   }

///////////////////////第二列///////////////////////
x=463-58;y=84-9; 

x=x+338;

    
}

void DJUpdate(void) {
    unsigned int  s=0,temp=0; 

//////////////////////第一列////////////////////
x=305-32;y=84-9;
//驱动电机转矩 
  temp=DJ_torque/10;
  if(temp>=3200){
     temp=(temp-3200);s=12;
 }else{
     temp=(3200-temp);s=11;
      }
  update_dl(x-16,y+0*35,temp,4,s,YELLOW);
//电机控制器直流侧电压
  print_SZ_2(x,    y+1*35,DJcontroler_voltage,4,0,YELLOW);
//电动机直流侧电流
  temp=DJcontroler_current/10;
  if(temp>=3200){
     temp=(temp-3200);s=12;
 }else{
     temp=(3200-temp);s=11;
      }
  update_dl(x-16,y+2*35,temp,4,s,YELLOW);
//电机转速
  print_SZ_2(x,y+3*35,DJ_speed,4,0,YELLOW);
//电机温度
  update_deg(x,y+4*35,DJ_temperature,YELLOW);
//电机控制器温度
  update_deg(x,y+5*35,DJcontroler_temperature,YELLOW);

//////////////////////第二列////////////////////
x=698-32;y=84-9;

  
}

void frmDJ(void) {
    if (f_index == 0) { //只更新一次
        f_index = 1;
        LCD_DrawRect(0,60,800,365,BLACK);
        LCD_DrawImage1BPP(340,30,    BMP_DJ,      GREEN, BLACK); //电机
        LCD_DrawImage1BPP(340+40,30, BMP_STSTEM,  GREEN, BLACK); //系统
        LCD_DrawImage1BPP(340+80,30, BMP_Message, GREEN, BLACK); //信息
        DJFrame();
    } else if (f_index == 1) {
        f_index = 1;
        DJUpdate();
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

void disp_battery4(){
   unsigned int  i=0;
   
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
    lcd_show_9dot(x,    y+(i)*35,  Bmp_BMS_1_L_1[i],       WHITE,BLACK);//电池 
  }

x=x+338;//单位符号
  for(i=0;i<6;i++){
    lcd_show_9dot(x,    y+(i)*35,  Bmp_BMS_1_L_2[i],       WHITE,BLACK);//单位 
  }

///////////////////////第二列///////////////////////
x=463-58;y=84-9; 
  for(i=0;i<4;i++){
    lcd_show_9dot(x,    y+i*35,  Bmp_BMS_1_R_1[i],     WHITE,BLACK);//单体
  }
  for(i=0;i<4;i++){
    lcd_show_9dot(x+223,y+i*35,  Bmp_BMS_1_R_2[i],     WHITE,BLACK);//单位
  }
  for(i=0;i<4;i++){
    lcd_show_8dot(x+296,y+i*35,    Bmp_Box,  WHITE,0x0000);//箱
  //lcd_show_8dot(x+366,y+i*35,    Bmp_Num,  WHITE,0x0000);//号
  }
    lcd_show_8dot(x+366,y+0*35,    Bmp_Jie,  WHITE,0x0000);//节
    lcd_show_8dot(x+366,y+1*35,    Bmp_Jie,  WHITE,0x0000);//节

x=x+338;//单位符号
    
}

void update_battery4(){
  unsigned int  s,i=0,j=0,temp=1000;
  unsigned int  x,y;
  unsigned char temp8[10];
  unsigned char color;
//////////////////////第一列////////////////////
x=305-32;y=84-9;
//电池总电压
  print_SZ_2(x,  y+0*35,DC_voltage/10,4,0,YELLOW);
//电池总电流
  temp=DC_current/10;
  if(temp>=3200){
     temp=(temp-3200);s=12;
    }else{
     temp=(3200-temp);s=11;
    }
  update_dl(x,    y+1*35,temp,3,s,YELLOW);
//SOC
  print_SZ_2(x,  y+2*35,DC_SOC*0.4,4,0,YELLOW);
//最大允许充电电流
  temp=CD_current/10;
  if(temp>=3200){
     temp=(temp-3200);s=12;
    }else{
     temp=(3200-temp);s=11;
    }
  update_dl(x,    y+3*35,temp,3,s,YELLOW);
//最大允许放电电流
  temp=FD_current/10;
  if(temp>=3200){
     temp=(temp-3200);s=12;
    }else{
     temp=(3200-temp);s=11;
    }
  update_dl(x,    y+4*35,temp,3,s,YELLOW);
//绝缘电阻
  print_SZ_2(x-16,  y+5*35,anode_R1,5,0,YELLOW);
//电池总箱数
  print_SZ_2(x,  y+6*35,DC_BOX_SUM,4,0,YELLOW);
//充电标志位
  if(DC_Status[0]&0x10)color=BLACK; else color=WHITE;
  lcd_show_8dot(x-18,y+7*35,    Bmp_Bu,  color,0x0000);//不
  lcd_show_8dot(x,   y+7*35,    Bmp_JZhi,  WHITE,0x0000);//禁止
//////////////////////第二列////////////////////
x=698-32;y=84-9;

x=196-32+393;
//最大单体电池电压
  print_SZ_2(x-10, y+0*35,(Vmax),           4,3,YELLOW);
  print_SZ_2(x+91, y+0*35, Vmax_box,        3,0,YELLOW);
  print_SZ_2(x+162,y+0*35, Vmax_num,        3,0,YELLOW);
//最小单体电池电压
  print_SZ_2(x-10, y+1*35,(Vmin),           4,3,YELLOW);
  print_SZ_2(x+91, y+1*35, Vmin_box,        3,0,YELLOW);
  print_SZ_2(x+162,y+1*35, Vmin_num,        3,0,YELLOW);
//最大单体电池温度
  update_deg(x-10+16,y+2*35, Tmax,        YELLOW);
  print_SZ_2(x+91,   y+2*35, Tmax_box,3,0,YELLOW);
  //print_SZ_2(x+162,y+2*35, Tmax_num,3,0,YELLOW);
//最小单体电池温度
  update_deg(x-10+16,y+3*35, Tmin,        YELLOW);
  print_SZ_2(x+91,   y+3*35, Tmin_box,3,0,YELLOW);
  //print_SZ_2(x+162,y+3*35, Tmin_num,3,0,YELLOW);

}

void frmBMS(void) {
    static unsigned char ID=1;
    if (f_index == 0) { //只更新一次
        f_index = 1;
        key_up=1;
        ID=3;
        key_set=0;
        LCD_DrawRect(0,60,800,365,BLACK);
        LCD_DrawImage1BPP(340,30,    BMP_Battery, GREEN, BLACK); //电池
        LCD_DrawImage1BPP(340+40,30, BMP_STSTEM,  GREEN, BLACK); //系统
        LCD_DrawImage1BPP(340+80,30, BMP_Message, GREEN, BLACK); //信息
        disp_battery4();
    } else if (f_index == 1) {
        f_index = 1;
        update_battery4();
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

void YWuFrame(void) { 
   unsigned int  i=0,j;
   unsigned int  temp=0;
x=7;y=68;
   for(i=0;i<11;i++){
   LCD_DrawRect(x,y+i*35,786, 1,GRAY);//-
   }
   LCD_DrawRect(x,y,1, 350,GRAY);//|左
x=203;
   LCD_DrawRect(x,y,1, 350,GRAY);//|中1  
x=400;y=103;
   LCD_DrawRect(x,y,1, 350-35,GRAY);//|中
x=596;
   LCD_DrawRect(x,y,1, 350-35,GRAY);//|中2
x=793;y=68;
   LCD_DrawRect(x,y,1, 350,GRAY);//|右

///////////////////////第一列///////////////////////
x=10;y=84-9; 
    lcd_show_9dot(105-28,    y+(0)*35,  Bmp_YW_1_L_1[0],     WHITE,BLACK);//电池仓
    
   for(i=0;i<8;i++){
    lcd_show_8dot(x,    y+(i+1)*35,  BMP_SZ_3[i+1],     WHITE,BLACK);//0
  }

x=x+338;//单位符号

///////////////////////第二列///////////////////////
x=224-16;y=84-9; 
    lcd_show_9dot(498-28,    y+(0)*35,  Bmp_YW_1_L_1[1],     WHITE,BLACK);//电池箱
    
    temp=temp+8;
    for(j=1;j<3;j++){
        for(i=0;i<8;i++){
            print_SZ_2(x+j*196,   y+(i+1)*35, ++temp,2,0,WHITE);//0
        }  
    }
        for(i=0;i<8;i++){
            print_SZ_2(x+0*196,   y+(i+1)*35, i+1,1,0,WHITE);//0
        }  
            
        for(i=0;i<2;i++){
            lcd_show_9dot(x+i*196,    y+(9)*35,  Bmp_YW_1_L_1[2+i],     WHITE,BLACK);////0
        }  
    
x=x+338;

}

void YWuUpdate(void) {
    unsigned int  s=0,temp=0; 
    unsigned char color;
    unsigned int  i=0,j;
    unsigned char Yw_temp[4];
    unsigned char Yw1_temp[7];  
//////////////////////第一列////////////////////
x=147-40;y=120-9;
    
    for(i=0;i<8;i++){
         if(i==0){
                  Yw_temp[1]=YW_Status[1];
                  Yw_temp[2]=YW_Status[2];
                  Yw_temp[3]=YW_Status[3];
                 }
         if(Yw_temp[1]&0x01){ s = 1; color = RED;  } //通讯故障
    else if(Yw_temp[2]&0x01){ s = 2; color = RED;  } //赌塞故障
    else if(Yw_temp[3]&0x01){ s = 3; color = RED;  } //烟雾报警
    else                    { s = 0; color = GREEN;} //正常
    lcd_show_9dot(x, y+(i)*35,  Bmp_Display_bj_YW[s],    color,BLACK);//
    Yw_temp[1]=(Yw_temp[1]>>1);
    Yw_temp[2]=(Yw_temp[2]>>1);
    Yw_temp[3]=(Yw_temp[3]>>1);
    
    }
   
//////////////////////第二列////////////////////
x=343-40;y=120-9;
    for(i=0;i<4;i++){
         if(i==0){
                 Yw1_temp[1]=YW1_Status[1];
                 Yw1_temp[2]=YW1_Status[2];              
                 Yw1_temp[3]=YW1_Status[3];           
                 Yw1_temp[4]=YW1_Status[4];
                 Yw1_temp[5]=YW1_Status[5];              
                 Yw1_temp[6]=YW1_Status[6];                              
                 }
      
         if((Yw1_temp[1]&0x03)==1){ s = 1; color = RED;  } //通讯故障
    else if((Yw1_temp[1]&0x03)==2){ s = 2; color = RED;  } //赌塞故障 
    else if((Yw1_temp[1]&0x03)==3){ s = 3; color = RED;  } //烟雾报警
    else                          { s = 0; color = GREEN;} //正常    
    lcd_show_9dot(x, y+(i)*35,  Bmp_Display_bj_YW[s],    color,BLACK);//    

         if((Yw1_temp[2]&0x03)==1){ s = 1; color = RED;  } //通讯故障
    else if((Yw1_temp[2]&0x03)==2){ s = 2; color = RED;  } //赌塞故障 
    else if((Yw1_temp[2]&0x03)==3){ s = 3; color = RED;  } //烟雾报警
    else                          { s = 0; color = GREEN;} //正常    
    lcd_show_9dot(x, y+(i+4)*35,  Bmp_Display_bj_YW[s],    color,BLACK);//      
    
         if((Yw1_temp[3]&0x03)==1){ s = 1; color = RED;  } //通讯故障
    else if((Yw1_temp[3]&0x03)==2){ s = 2; color = RED;  } //赌塞故障 
    else if((Yw1_temp[3]&0x03)==3){ s = 3; color = RED;  } //烟雾报警
    else                          { s = 0; color = GREEN;} //正常    
    lcd_show_9dot(x+196*1, y+(i)*35,  Bmp_Display_bj_YW[s],    color,BLACK);//    

         if((Yw1_temp[4]&0x03)==1){ s = 1; color = RED;  } //通讯故障
    else if((Yw1_temp[4]&0x03)==2){ s = 2; color = RED;  } //赌塞故障 
    else if((Yw1_temp[4]&0x03)==3){ s = 3; color = RED;  } //烟雾报警
    else                          { s = 0; color = GREEN;} //正常    
    lcd_show_9dot(x+196*1, y+(i+4)*35,  Bmp_Display_bj_YW[s],    color,BLACK);// 
    
         if((Yw1_temp[5]&0x03)==1){ s = 1; color = RED;  } //通讯故障
    else if((Yw1_temp[5]&0x03)==2){ s = 2; color = RED;  } //赌塞故障 
    else if((Yw1_temp[5]&0x03)==3){ s = 3; color = RED;  } //烟雾报警
    else                          { s = 0; color = GREEN;} //正常    
    lcd_show_9dot(x+196*2, y+(i)*35,  Bmp_Display_bj_YW[s],    color,BLACK);//    

         if((Yw1_temp[6]&0x03)==1){ s = 1; color = RED;  } //通讯故障
    else if((Yw1_temp[6]&0x03)==2){ s = 2; color = RED;  } //赌塞故障 
    else if((Yw1_temp[6]&0x03)==3){ s = 3; color = RED;  } //烟雾报警
    else                          { s = 0; color = GREEN;} //正常    
    lcd_show_9dot(x+196*2, y+(i+4)*35,  Bmp_Display_bj_YW[s],    color,BLACK);//  
    
    Yw1_temp[1]=(Yw1_temp[1]>>2);
    Yw1_temp[2]=(Yw1_temp[2]>>2);
    Yw1_temp[3]=(Yw1_temp[3]>>2);
    Yw1_temp[4]=(Yw1_temp[4]>>2);
    Yw1_temp[5]=(Yw1_temp[5]>>2);
    Yw1_temp[6]=(Yw1_temp[6]>>2);
    
    }


//烟雾LIFE
print_SZ_2(x+0*196,   y+(8)*35, YW1_Status[7],4,0,YELLOW);//
//传感器数量
print_SZ_2(x+1*196,   y+(8)*35,(YW1_Status[0]&0xF8)>>3,4,0,YELLOW);//


}

void frmYWu(void) {
    if (f_index == 0) { //只更新一次
        f_index = 1;
        LCD_DrawRect(0,60,800,365,BLACK);
        LCD_DrawImage1BPP(340,30,    BMP_YWu,     GREEN, BLACK); //电机
        LCD_DrawImage1BPP(340+40,30, BMP_STSTEM,  GREEN, BLACK); //系统
        LCD_DrawImage1BPP(340+80,30, BMP_Message, GREEN, BLACK); //信息
        YWuFrame();
    } else if (f_index == 1) {
        f_index = 1;
        YWuUpdate();
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


void TaiYaFrame(void) {
     unsigned char i = 0;

//左前轮
x=80;y=342;
    lcd_show_8dot( x-50, y-18, Bmp_LTai,WHITE,0x0000);
    lcd_show_8dot( x-12, y-8,  Bmp_FL,  WHITE,0x0000);//FL
//右前轮
x=80;y=138; 
    lcd_show_8dot( x-50, y-18, Bmp_LTai,WHITE,0x0000);
    lcd_show_8dot( x-12, y-8,  Bmp_FR,  WHITE,0x0000);//FR
//左后轮1
x=460;y=342; 
    lcd_show_8dot( x-50, y-18, Bmp_LTai,WHITE,0x0000);
    lcd_show_8dot( x-20, y-8,  Bmp_RL,  WHITE,0x0000);//RL  
       print_SZ_2( x+4, y-9,  1,1,0,   WHITE);//
//左后轮2
x=460;y=302; 
    lcd_show_8dot( x-50, y-18, Bmp_LTai,WHITE,0x0000);
    lcd_show_8dot( x-20, y-8,  Bmp_RL,  WHITE,0x0000);//RL  
       print_SZ_2( x+4, y-9,  2,1,0,   WHITE);//   
//右后轮1
x=460;y=178;
    lcd_show_8dot( x-50, y-18, Bmp_LTai,WHITE,0x0000);
    lcd_show_8dot( x-20, y-8,  Bmp_RR,  WHITE,0x0000);//RR  
       print_SZ_2( x+4, y-9,  1,1,0,   WHITE);//  
//右后轮2
x=460;y=138;
    lcd_show_8dot( x-50, y-18, Bmp_LTai,WHITE,0x0000);
    lcd_show_8dot( x-20, y-8,  Bmp_RR,  WHITE,0x0000);//RR  
       print_SZ_2( x+4, y-9,  2,1,0,   WHITE);//

//左|线
x=80;y=240;
    LCD_DrawRect(x-1,y-84,1, 168,GRAY);//|左
    LCD_DrawRect(x,  y-84,1, 168,GRAY);//|左
    LCD_DrawRect(x+1,y-84,1, 168,GRAY);//|左
//右|线
x=460;y=240;
    LCD_DrawRect(x-1,y-44,1, 88,GRAY);//|左
    LCD_DrawRect(x,  y-44,1, 88,GRAY);//|左
    LCD_DrawRect(x+1,y-44,1, 88,GRAY);//|左
//中间横线    
x=270;y=240;
    LCD_DrawRect(x-190,y-1,380, 1,GRAY);//|左
    LCD_DrawRect(x-190,y,  380, 1,GRAY);//|左
    LCD_DrawRect(x-190,y+1,380, 1,GRAY);//|左 
    
//单位
x=222;y=138;
    lcd_show_8dot(x-16,   y-7, Bmp_Bar, WHITE,0x0000);  
x=320;y=138;
    lcd_show_8dot(x-8,    y-8, Bmp_deg, WHITE,0x0000);    
x=222;y=342;
    lcd_show_8dot(x-16,   y-7, Bmp_Bar, WHITE,0x0000);  
x=320;y=342;
    lcd_show_8dot(x-8,    y-8, Bmp_deg, WHITE,0x0000);  
    
x=602;y=138;
    lcd_show_8dot(x-16,   y-7, Bmp_Bar, WHITE,0x0000);  
x=700;y=138;
    lcd_show_8dot(x-8,    y-8, Bmp_deg, WHITE,0x0000);   
x=602;y=178;
    lcd_show_8dot(x-16,   y-7, Bmp_Bar, WHITE,0x0000);  
x=700;y=178;
    lcd_show_8dot(x-8,    y-8, Bmp_deg, WHITE,0x0000);  
x=602;y=302;
    lcd_show_8dot(x-16,   y-7, Bmp_Bar, WHITE,0x0000);  
x=700;y=302;
    lcd_show_8dot(x-8,    y-8, Bmp_deg, WHITE,0x0000); 
x=602;y=342;
    lcd_show_8dot(x-16,   y-7, Bmp_Bar, WHITE,0x0000);  
x=700;y=342;
    lcd_show_8dot(x-8,    y-8, Bmp_deg, WHITE,0x0000);    
    
    
}

void TaiYaUpdate(void) {
  unsigned int  temp=0;
  unsigned long temp32=0;
  unsigned char color=0;
  static unsigned char i=5;
  static unsigned char al_index=1;
  static unsigned char al_index0=1;  
  static unsigned char al_index1=1; 
  static unsigned char al_index2=1; 
  static unsigned char al_index3=1;
  static unsigned char al_index4=1;
  static unsigned char al_index5=1; 

//////////////////////第一列////////////////////
//左前轮
if((Tire_Status[0]&0x30)==0x10)color=0;else color=YELLOW;
x=169-32;y=342-9;
print_SZ_2(x,y,Tire_Press[0]*5.5,3,2,color);//
x=279-32;y=342-9;
update_degX(x,y,Tire_Temp[0]*0.03125,273,color);//
x=362-28;y=342-9;

//右前轮
if((Tire_Status[1]&0x30)==0x10)color=0;else color=YELLOW;
x=169-32;y=138-9;
print_SZ_2(x,y,Tire_Press[1]*5.5,3,2,color);//
x=279-32;y=138-9;
update_degX(x,y,Tire_Temp[1]*0.03125,273,color);//
x=362-28;y=138-9;

//左后左轮1
if((Tire_Status[2]&0x30)==0x10)color=0;else color=YELLOW;
x=549-32;y=342-9;
print_SZ_2(x,y,Tire_Press[2]*5.5,3,2,color);//
x=659-32;y=342-9;
update_degX(x,y,Tire_Temp[2]*0.03125,273,color);//
x=742-28;y=342-9;

//左后右轮2
if((Tire_Status[3]&0x30)==0x10)color=0;else color=YELLOW;
x=549-32;y=342-9-40;
print_SZ_2(x,y,Tire_Press[3]*5.5,3,2,color);//
x=659-32;y=342-9-40;
update_degX(x,y,Tire_Temp[3]*0.03125,273,color);//
x=742-28;y=342-9-40;

//右后左轮1
if((Tire_Status[4]&0x30)==0x10)color=0;else color=YELLOW;
x=549-32;y=178-9;
print_SZ_2(x,y,Tire_Press[4]*5.5,3,2,color);//
x=659-32;y=178-9;
update_degX(x,y,Tire_Temp[4]*0.03125,273,color);//
x=742-28;y=178-9;

//右后右轮2
if((Tire_Status[5]&0x30)==0x10)color=0;else color=YELLOW;
x=549-32;y=178-9-40;
print_SZ_2(x,y,Tire_Press[5]*5.5,3,2,color);//
x=659-32;y=178-9-40;
update_degX(x,y,Tire_Temp[5]*0.03125,273,color);//
x=742-28;y=178-9-40;

  if(F3s_1==0){//时间触发

    if(i>4)i=0;else i++;
    if(i==0){x=362-28;y=342-9;   al_index=al_index0;}//左前轮
    if(i==1){x=362-28;y=138-9;   al_index=al_index1;}//右前轮
    if(i==2){x=742-28;y=342-9;   al_index=al_index2;}//左后左轮1   
    if(i==3){x=742-28;y=342-9-40;al_index=al_index3;}//左后右轮2 
    if(i==4){x=742-28;y=178-9;   al_index=al_index4;}//右后左轮1
    if(i==5){x=742-28;y=178-9-40;al_index=al_index5;}//右后右轮2 
      
    if((Tire_Status[i]&0x30)==0x10){LCD_DrawImageSBPP(x,y, Bmp_Display_bj_TY[0], BLACK,  BLACK);}//信号丢失不显示
    else {  
            switch(al_index){
            case 1: 
                al_index=2; 
               if((Tire_Status[i]&0x03)==0x01){ //高温报警
                LCD_DrawImageSBPP(x, y, Bmp_Display_bj_TY[0],  RED, BLACK);
                F3s_1=1;
                break; 
                }  
            case 2: 
                al_index=3; 
               if((Tire_Status[i]&0x0C)==0x04){ //漏气报警
                LCD_DrawImageSBPP(x, y, Bmp_Display_bj_TY[1],  RED, BLACK);  
                F3s_1=1;
                break; 
                }  
            case 3: 
                al_index=4; 
               if((Tire_fault[i]&0xE0)==0x00){ //高压报警
                LCD_DrawImageSBPP(x, y, Bmp_Display_bj_TY[2],  RED, BLACK);   
                F3s_1=1;
                break; 
                }  
            case 4: 
                al_index=5; 
               if((Tire_fault[i]&0xE0)==0x20){ //高压预警
                LCD_DrawImageSBPP(x, y, Bmp_Display_bj_TY[3],  RED, BLACK);  
                F3s_1=1;
                break; 
                }  
            case 5: 
                al_index=6; 
               if((Tire_fault[i]&0xE0)==0x40){ //正常
                LCD_DrawImageSBPP(x, y, Bmp_Display_bj_TY[4],  GREEN, BLACK);  
                F3s_1=1;
                break; 
                }        
            case 6: 
                al_index=7; 
               if((Tire_fault[i]&0xE0)==0x60){ //低压预警
                LCD_DrawImageSBPP(x, y, Bmp_Display_bj_TY[5],  RED, BLACK);
                F3s_1=1;
                break; 
                }         
            case 7: 
                al_index=8; 
               if((Tire_fault[i]&0xE0)==0x80){ //低压报警
                LCD_DrawImageSBPP(x, y, Bmp_Display_bj_TY[6],  RED, BLACK);   
                F3s_1=1;
                break; 
                }     
            case 8: 
                al_index=1; 
                if(  ((Tire_Status[i]&0x03)!=0x01)&& //高温报警
                     ((Tire_Status[i]&0x0C)!=0x04)&& //漏气报警
                     ((Tire_fault[i]&0xE0)!=0x00) && //高压报警
                     ((Tire_fault[i]&0xE0)!=0x20) && //高压预警
                     ((Tire_fault[i]&0xE0)!=0x40) && //正常
                     ((Tire_fault[i]&0xE0)!=0x60) && //低压预警    
                     ((Tire_fault[i]&0xE0)!=0x80)    //低压报警    
                   ){
                LCD_DrawImageSBPP(x,y, Bmp_Display_bj_TY[0], BLACK,  BLACK);//不显示   
                F3s_1=1;
                break; 
                }    
            default:
                al_index=1;
                break;
                }
            
        if(i==0){al_index0=al_index;}//左前轮
        if(i==1){al_index1=al_index;}//右前轮
        if(i==2){al_index2=al_index;}//左后左轮1   
        if(i==3){al_index3=al_index;}//左后右轮2 
        if(i==4){al_index4=al_index;}//右后左轮1
        if(i==5){al_index5=al_index;}//右后右轮2    
            
        }
    
    }//时间触发

}

void frmTaiYa(void) {
    if (f_index == 0) { //只更新一次
        f_index = 1;
        LCD_DrawRect(0,60,800,365,BLACK);
        LCD_DrawImage1BPP(340-16,30, Bmp_front,   BLACK,BLACK);  
        LCD_DrawImage1BPP(340,   30, Bmp_TYa,     GREEN, BLACK); //胎压
        LCD_DrawImage1BPP(340+40,30, BMP_STSTEM,  GREEN, BLACK); //系统
        LCD_DrawImage1BPP(340+80,30, BMP_Message, GREEN, BLACK); //信息
        TaiYaFrame();
    } else if (f_index == 1) {
        f_index = 1;
        TaiYaUpdate();
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
    Ftemp=60.0*DJ_speed; //车速 
    temp=(unsigned int)(Ftemp/new_pluse);    //车速
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

unsigned int disp_bj_YB(unsigned int x,unsigned int y){
    static unsigned char al_index = 31;
    unsigned char color=0;
    unsigned char Fcolor=YELLOW;  
    unsigned int  leng,temp;
    switch(al_index){
            case 31: 
                al_index=32; 
                //if(1){
                if(  LED9   ){ //前气压低报警
                LCD_DrawImageSBPP(x, y, Bmp_Display_bj_YB_31,   Fcolor,color);//
                leng = 112;
                break; 
                }        
            case 32: 
                al_index=33; 
                //if(1){
                if(   LED11  ){ //后气压低报警
                LCD_DrawImageSBPP(x, y, Bmp_Display_bj_YB_32,   Fcolor,color);//
                leng = 112;
                break; 
                }   
            case 33: 
                al_index=34; 
                //if(1){
                if(  !fKL4   ){ //左摩擦片报警
                LCD_DrawImageSBPP(x, y, Bmp_Display_bj_YB_33,   Fcolor,color);//
                leng = 112;
                break; 
                }       
            case 34: 
                al_index=35; 
                //if(1){
                if(  !fKL5   ){ //右摩擦片报警
                LCD_DrawImageSBPP(x, y, Bmp_Display_bj_YB_34,   Fcolor,color);//
                leng = 112;
                break; 
                }              
            case 35: 
                al_index=36; 
                //if(1){
                if(   mKL8  ){ //车内应急阀打开
                LCD_DrawImageSBPP(x, y, Bmp_Display_bj_YB_35,   Fcolor,color);//
                leng = 136;
                break; 
                }              
            case 36: 
                al_index=37; 
                //if(1){
                if(   IN34  ){ //车外应急阀打开
                LCD_DrawImageSBPP(x, y, Bmp_Display_bj_YB_36,   Fcolor,color);//
                leng = 136;
                break; 
                }               
            case 37: 
                al_index=38; 
                //if(1){
                if(  rKL7   ){ //水位报警
                LCD_DrawImageSBPP(x, y, Bmp_Display_bj_YB_37,   Fcolor,color);//
                leng = 80;
                break; 
                }              
            case 38: 
                al_index=39; 
                //if(1){
                if(VCU_Status[0] & 0x02){ //充电保护盖打开
                LCD_DrawImageSBPP(x, y, Bmp_Display_bj_YB_38,   Fcolor,color);//
                leng = 136;
                break; 
                }              
            case 39: 
                al_index=31; 
                //if(1){
                if(   fKL3  ){ //下客请求
                LCD_DrawImageSBPP(x, y, Bmp_Display_bj_YB_39,   Fcolor,color);//
                leng = 80;
                break; 
                } 
  
            default:
                leng=0;al_index=31;
                break;
        }
            return leng; 
}

unsigned int disp_bj_DC(unsigned int x,unsigned int y){
    static unsigned char al_index = 1;
    unsigned char color=0;
    unsigned char Fcolor=YELLOW;  
    unsigned int  leng,temp;
    switch(al_index){
            case 1: 
                al_index=3; 
                //if(1){
                if(VCU_Status[2]&0XC0){ //电池总电压过高,低
                if(VCU_Status[2]&0X80)LCD_DrawImageSBPP(x, y, Bmp_Display_bj_DC_1,  Fcolor,color);//过高
                else                  LCD_DrawImageSBPP(x, y, Bmp_Display_bj_DC_2,  Fcolor,color);//过低
                leng = 216;
                break; 
                }        
            case 3: 
                al_index=5; 
                //if(1){
                if(VCU_Status[2]&0X20){ //电池单体过压,过低
                LCD_DrawImageSBPP(x,    y, Bmp_Display_bj_DC_3, Fcolor,color);//电池单体过压
                leng = 240;
                break; 
                }
            case 5: 
                al_index=7; 
                //if(1){
                if(VCU_Status[2]&0X0C){ //放电电流过大
                if(VCU_Status[2]&0X08)LCD_DrawImageSBPP(x, y, Bmp_Display_bj_DC_5,   Fcolor,color);//放电
                else                  LCD_DrawImageSBPP(x, y, Bmp_Display_bj_DC_6,   Fcolor,color);//充电
                leng = 232;
                break; 
                }
            case 7: 
                al_index=9; 
                //if(1){
                if(VCU_Status[2]&0X03){ //电池箱温度过高  过低
                if(VCU_Status[2]&0X02)LCD_DrawImageSBPP(x, y, Bmp_Display_bj_DC_7,   Fcolor,color);//过高
                else                  LCD_DrawImageSBPP(x, y, Bmp_Display_bj_DC_8,   Fcolor,color);//过低
                leng = 216;
                break; 
                }     
            case 9: 
                al_index=10; 
                //if(1){
                if(  DC_Status[0]&0x20   ){ //一级故障：烟雾报警
                LCD_DrawImageSBPP(x, y, Bmp_Display_bj_DC_9,   Fcolor,color);//
                leng = 160;
                break; 
                }     
            case 10: 
                al_index=11; 
                //if(1){
                if(  (DC_Status[0]&0x02)   ){ //二级故障：电池内部绝缘一级故障 
                LCD_DrawImageSBPP(x, y, Bmp_Display_bj_DC_10,   Fcolor,color);//
                leng = 272;
                break; 
                } 
            case 11: 
                al_index=12; 
                //if(1){
                if(  (DC_Status[0]&0x04)   ){ //二级故障：电池内部绝缘二级故障 
                LCD_DrawImageSBPP(x, y, Bmp_Display_bj_DC_11,   Fcolor,color);//
                leng = 272;
                break; 
                }    
            case 12: 
                al_index=13; 
                //if(1){
                if(   DC_Status[1]&0x40  ){ //一级故障：SOC 过低
                LCD_DrawImageSBPP(x, y, Bmp_Display_bj_DC_12,   Fcolor,color);//
                leng = 152;
                break; 
                }            
            case 13: 
                al_index=14; 
                //if(1){
                if(  DC_Status[1]&0x20   ){ //一级故障：电池温度过高，停车
                LCD_DrawImageSBPP(x, y, Bmp_Display_bj_DC_13,   Fcolor,color);//
                leng = 248;
                break; 
                }         
            case 14: 
                al_index=15; 
                //if(1){
                if(  DC_Status[1]&0x10   ){ //一级故障：动力电池过流 
                LCD_DrawImageSBPP(x, y, Bmp_Display_bj_DC_14,   Fcolor,color);//
                leng = 192;
                break; 
                }          
            case 15: 
                al_index=16; 
                //if(1){
                if(   DC_Status[1]&0x08  ){ //二级故障：SOC 低
                LCD_DrawImageSBPP(x, y, Bmp_Display_bj_DC_15,   Fcolor,color);//
                leng = 128;
                break; 
                }            
            case 16: 
                al_index=17; 
                //if(1){
                if(   DC_Status[1]&0x04  ){ //二级故障：SOC 过高
                LCD_DrawImageSBPP(x, y, Bmp_Display_bj_DC_16,   Fcolor,color);//
                leng = 152;
                break; 
                }              
            case 17: 
                al_index=18; 
                //if(1){
                if(  DC_Status[1]&0x02   ){ //一级故障：模块电压过低
                LCD_DrawImageSBPP(x, y, Bmp_Display_bj_DC_17,   Fcolor,color);//
                leng = 200;
                break; 
                }     
            case 18: 
                al_index=19; 
                //if(1){
                if(   DC_Status[1]&0x01  ){ //二级故障：模块电压过高
                LCD_DrawImageSBPP(x, y, Bmp_Display_bj_DC_18,   Fcolor,color);//
                leng = 200;
                break; 
                }          
                
            case 19: 
                al_index=20; 
                //if(1){
                if(  ((DC_Status[2]&0xC0)>>6)==1   ){ //二级故障：单箱电压不均衡
                LCD_DrawImageSBPP(x, y, Bmp_Display_bj_DC_19,   Fcolor,color);//
                leng = 208;
                break; 
                }             
            case 20: 
                al_index=21; 
                //if(1){
                if(  ((DC_Status[2]&0xC0)>>6)==2   ){ //二级故障：整箱电压不均
                LCD_DrawImageSBPP(x, y, Bmp_Display_bj_DC_20,   Fcolor,color);//
                leng = 184;
                break; 
                }          
            case 21: 
                al_index=22; 
                //if(1){
                if(   ((DC_Status[2]&0x30)>>4)==1  ){ //二级故障：电池高低温差大于15度
                LCD_DrawImageSBPP(x, y, Bmp_Display_bj_DC_21,   Fcolor,color);//
                leng = 264;
                break; 
                }    
            case 22: 
                al_index=23; 
                //if(1){
                if(   ((DC_Status[2]&0x30)>>4)==2  ){ //二级故障：电池高低温差大于10度
                LCD_DrawImageSBPP(x, y, Bmp_Display_bj_DC_22,   Fcolor,color);//
                leng = 264;
                break; 
                }                   
            case 23: 
                al_index=24; 
                //if(1){
                if(   ((DC_Status[2]&0x0C)>>2)==1  ){ //一级故障：电池极柱温度大于65度，请停车检查
                LCD_DrawImageSBPP(x, y, Bmp_Display_bj_DC_23,   Fcolor,color);//
                leng = 240;
                break; 
                }                    
            case 24: 
                al_index=25; 
                //if(1){
                if(   ((DC_Status[2]&0x0C)>>2)==2  ){ //一级故障：电池极柱温度大于75度，请停车检查
                LCD_DrawImageSBPP(x, y, Bmp_Display_bj_DC_24,   Fcolor,color);//
                leng = 240;
                break; 
                }    
            case 25: 
                al_index=26; 
                //if(1){
                if(  ((DC_Status[2]&0x03))==1   ){ //二级故障：电池从板电压检测故障
                LCD_DrawImageSBPP(x, y, Bmp_Display_bj_DC_25,   Fcolor,color);//
                leng = 280;
                break; 
                }                 
            case 26: 
                al_index=27; 
                //if(1){
                if(  ((DC_Status[2]&0x03))==2   ){ //二级故障：电池从板CAN通讯故障
                LCD_DrawImageSBPP(x, y, Bmp_Display_bj_DC_26,   Fcolor,color);//
                leng = 272;
                break; 
                }                
            case 27: 
                al_index=1; 
                //if(1){
                if(   (((DC_Status[2]&0x0C)>>2)==1 )||//一级故障：电池极柱温度大于65度，
                      (((DC_Status[2]&0x0C)>>2)==2 )  //一级故障：电池极柱温度大于75度，
                   ){ //请停车检查
                LCD_DrawImageSBPP(x, y, Bmp_Display_bj_DC_27,   Fcolor,color);//
                leng = 96;
                break; 
                }   
                
            default:
                leng=0;al_index=1;
                break;
        }
            return leng;
}

unsigned int disp_bj_DJ(unsigned int x,unsigned int y){
    static unsigned char al_index = 1;
    unsigned char color=0;
    unsigned char Fcolor=YELLOW;  
    unsigned int  leng,temp;
    switch(al_index){
            case 1: 
                al_index=2; 
                //if(1){
               if((DJ_Status[0]&0x08)){    //一级故障：直流侧欠压
                LCD_DrawImageSBPP(x,    y, Bmp_Display_bj_DJ_1,    Fcolor,color);             
                leng = 168;
                break; 
                }    
            case 2: 
                al_index=3; 
                //if(1){
               if((DJ_Status[0]&0x04)){    //一级故障：电机控制器过流
                LCD_DrawImageSBPP(x,    y, Bmp_Display_bj_DJ_2,    Fcolor,color);             
                leng = 208;
                break; 
                }   
            case 3: 
                al_index=4; 
                //if(1){
               if((DJ_Status[0]&0x02)){    //一级故障：IGBT 故障
                LCD_DrawImageSBPP(x,    y, Bmp_Display_bj_DJ_3,    Fcolor,color);             
                leng = 160;
                break; 
                }   
            case 4: 
                al_index=5; 
                //if(1){
               if((DJ_Status[0]&0x01)){    //一级故障：直流侧过压
                LCD_DrawImageSBPP(x,    y, Bmp_Display_bj_DJ_4,    Fcolor,color);             
                leng = 168;
                break; 
                }               
            case 5: 
                al_index=6; 
                //if(1){
               if((DJ_Status[1]&0x40)){    //一级故障：主接触器触点故障
                LCD_DrawImageSBPP(x,    y, Bmp_Display_bj_DJ_5,    Fcolor,color);             
                leng = 232;
                break; 
                }              
            case 6: 
                al_index=7; 
                //if(1){
               if((DJ_Status[1]&0x08)){    //二级故障：电机控制器过载
                LCD_DrawImageSBPP(x,    y, Bmp_Display_bj_DJ_6,    Fcolor,color);             
                leng = 208;
                break; 
                }   
            case 7: 
                al_index=8; 
                //if(1){
               if((DJ_Status[1]&0x04)){    //一级故障：电机控制器超速
                LCD_DrawImageSBPP(x,    y, Bmp_Display_bj_DJ_7,    Fcolor,color);             
                leng = 216;
                break; 
                }           
            case 8: 
                al_index=1; 
                //if(1){
               if(DJ_Status[1]&0X01){    //一级故障：电机控制器过热
                LCD_DrawImageSBPP(x,    y, Bmp_Display_bj_DJ_8,    Fcolor,color);             
                leng = 208;
                break; 
                }                                     
                
            default:
                leng=0;al_index=1;
                break;
        }
            return leng;    
}

unsigned int disp_bj_JK(unsigned int x,unsigned int y){
    static unsigned char al_index = 1;
    unsigned char color=0;
    unsigned char Fcolor=YELLOW;  
    unsigned int  leng,temp;
    switch(al_index){
            case 1: 
                al_index=2; 
                //if(1){
               if(( YZT_Status==1 )){    //远程监控终端无法获取整车控制器信息
                LCD_DrawImageSBPP(x,    y, Bmp_Display_bj_JK_1,    Fcolor,color);             
                leng = 288;
                break; 
                }     
            case 2: 
                al_index=3; 
                //if(1){
               if(( YZT_Status==2 )){    //远程监控终端无法获取电机控制器信息
                LCD_DrawImageSBPP(x,    y, Bmp_Display_bj_JK_2,    Fcolor,color);             
                leng = 288;
                break; 
                }       
            case 3: 
                al_index=4; 
                //if(1){
               if(( YZT_Status==3 )){    //远程监控终端无法获取一体化配电柜信息
                LCD_DrawImageSBPP(x,    y, Bmp_Display_bj_JK_3,    Fcolor,color);             
                leng = 248;
                break; 
                }        
            case 4: 
                al_index=5; 
                //if(1){
               if(( YZT_Status==4 )){    //远程监控终端无法获取绝缘监测仪信息
                LCD_DrawImageSBPP(x,    y, Bmp_Display_bj_JK_4,    Fcolor,color);             
                leng = 288;
                break; 
                }     
            case 5: 
                al_index=6; 
                //if(1){
               if(( YZT_Status==5 )){    //远程监控终端无法获取转向控制器信息
                LCD_DrawImageSBPP(x,    y, Bmp_Display_bj_JK_5,    Fcolor,color);             
                leng = 288;
                break; 
                }   
            case 6: 
                al_index=7; 
                //if(1){
               if(( YZT_Status==6 )){    //远程监控终端无法获取打气控制器信息
                LCD_DrawImageSBPP(x,    y, Bmp_Display_bj_JK_6,    Fcolor,color);             
                leng = 288;
                break; 
                }   
            case 7: 
                al_index=8; 
                //if(1){
               if(( YZT_Status==7 )&&( VCU_Status[4]&0X04 )){    //远程监控终端无法获取DC/DC控制器信息
                LCD_DrawImageSBPP(x,    y, Bmp_Display_bj_JK_7,    Fcolor,color);     
                LCD_DrawImage1BPP(x+256,y, Bmp_xx,                 Fcolor,color);     
                leng = 296;
                break; 
                }    
            case 8: 
                al_index=9; 
                //if(1){
               if(( YZT_Status==8 )){    //远程监控终端无法获取仪表信息
                LCD_DrawImageSBPP(x,    y, Bmp_Display_bj_JK_8,    Fcolor,color);             
                leng = 232;
                break; 
                }   
            case 9: 
                al_index=10; 
                //if(1){
               if(( YZT_Status==9 )){    //远程监控终端无法获取BMS信息
                LCD_DrawImageSBPP(x,    y, Bmp_Display_bj_JK_9,    Fcolor,color);             
                leng = 224;
                break; 
                }             
            case 10: 
                al_index=1; 
                //if(1){
               if(( YZT_Status==10 )){    //远程监控终端无法获取烟雾报警器信息
                LCD_DrawImageSBPP(x,    y, Bmp_Display_bj_JK_10,    Fcolor,color);             
                leng = 288;
                break; 
                }               
 
                
            default:
                leng=0;al_index=1;
                break;
        }
            return leng;  
}

unsigned int disp_bj_ZC(unsigned int x,unsigned int y){
    static unsigned char al_index = 1;
    unsigned char color=0;
    unsigned char Fcolor=YELLOW;  
    unsigned int  leng,temp;
    switch(al_index){
            case 1: 
                al_index=2; 
                //if(1){
               if( ((GZ_Status[0]&0xC0)>>6)==1 ){    //整车一级报警
                LCD_DrawImageSBPP(x,    y, Bmp_Display_bj_ZC_1,    Fcolor,color);        
                leng = 112;
                break; 
                }   
            case 2: 
                al_index=3; 
                //if(1){
               if( ((GZ_Status[0]&0xC0)>>6)==2 ){    //整车二级保护
                LCD_DrawImageSBPP(x,    y, Bmp_Display_bj_ZC_2,    Fcolor,color);             
                leng = 112;
                break; 
                }   
            case 3: 
                al_index=4; 
                //if(1){
               if( ((GZ_Status[0]&0xC0)>>6)==3 ){    //整车三级故障
                LCD_DrawImageSBPP(x,    y, Bmp_Display_bj_ZC_3,    Fcolor,color);             
                leng = 112;
                break; 
                }           
            case 4: 
                al_index=5; 
                //if(1){
               if( ((GZ_Status[0]&0x30)>>4)==1 ){    //BMS一级报警
                LCD_DrawImageSBPP(x,    y, Bmp_Display_bj_ZC_4,    Fcolor,color);             
                leng = 104;
                break; 
                }       
            case 5: 
                al_index=6; 
                //if(1){
               if( ((GZ_Status[0]&0x30)>>4)==2 ){    //BMS二级保护
                LCD_DrawImageSBPP(x,    y, Bmp_Display_bj_ZC_5,    Fcolor,color);             
                leng = 104;
                break; 
                }                
            case 6: 
                al_index=7; 
                //if(1){
               if( ((GZ_Status[0]&0x30)>>4)==3 ){    //BMS三级故障
                LCD_DrawImageSBPP(x,    y, Bmp_Display_bj_ZC_6,    Fcolor,color);             
                leng = 104;
                break; 
                }   
            case 7: 
                al_index=8; 
                //if(1){
               if( ((GZ_Status[0]&0x0C)>>2)==1 ){    //电机控制器一级报警
                LCD_DrawImageSBPP(x,    y, Bmp_Display_bj_ZC_7,    Fcolor,color);             
                leng = 168;
                break; 
                }   
            case 8: 
                al_index=9; 
                //if(1){
               if( ((GZ_Status[0]&0x0C)>>2)==2 ){    //电机控制器二级保护
                LCD_DrawImageSBPP(x,    y, Bmp_Display_bj_ZC_8,    Fcolor,color);             
                leng = 168;
                break; 
                }          
            case 9: 
                al_index=10; 
                //if(1){
               if( ((GZ_Status[0]&0x0C)>>2)==3 ){    //电机控制器三级故障
                LCD_DrawImageSBPP(x,    y, Bmp_Display_bj_ZC_9,    Fcolor,color);             
                leng = 168;
                break; 
                }            
            case 10: 
                al_index=11; 
                //if(1){
               if( ((GZ_Status[0]&0x03))==1 ){    //小充电机一级报警
                LCD_DrawImageSBPP(x,    y, Bmp_Display_bj_ZC_10,    Fcolor,color);             
                leng = 144;
                break; 
                }                
            case 11: 
                al_index=12; 
                //if(1){
               if( ((GZ_Status[0]&0x03))==2 ){    //小充电机二级保护
                LCD_DrawImageSBPP(x,    y, Bmp_Display_bj_ZC_11,    Fcolor,color);             
                leng = 144;
                break; 
                }         
            case 12: 
                al_index=13; 
                //if(1){
               if( ((GZ_Status[0]&0x03))==3 ){    //小充电机三级故障
                LCD_DrawImageSBPP(x,    y, Bmp_Display_bj_ZC_12,    Fcolor,color);             
                leng = 144;
                break; 
                }    
            case 13: 
                al_index=19;//14; 
                //if(1){
               if(( GZ_Status[4]==3 )){    //003：小充电机不在线
                LCD_DrawImageSBPP(x,    y, Bmp_Display_bj_ZC_13,    Fcolor,color);             
                leng = 168;
                break; 
                }     
/* 
            case 14: 
                al_index=15; 
                //if(1){
               if(( (Jcan_count >= 100)||(JLY_time[9]!=JLY_time[8]) )){    //时钟信息丢失，防乳化功能失效
                LCD_DrawImageSBPP(x,    y, Bmp_Display_bj_ZC_14,    Fcolor,color);             
                leng = 264;
                break; 
                }          
            case 15: 
                al_index=16; 
                //if(1){
               if((  (JYcan_count >= 100)||(R_life[1]!=R_life[2])  )){    //绝缘监测仪无信息
                LCD_DrawImageSBPP(x,    y, Bmp_Display_bj_ZC_15,    Fcolor,color);             
                leng = 152;
                break; 
                }    
            case 16: 
                al_index=17; 
                //if(1){
               if((  (Kcan_count >= CAN_TIME)  )){    //电机控制器无信息
                LCD_DrawImageSBPP(x,    y, Bmp_Display_bj_ZC_16,    Fcolor,color);             
                leng = 152;
                break; 
                }       
            case 17: 
                al_index=18; 
                //if(1){
               if((  (Vcan_count >= CAN_TIME)  )){    //整车控制器无信息
                LCD_DrawImageSBPP(x,    y, Bmp_Display_bj_ZC_17,    Fcolor,color);             
                leng = 152;
                break; 
                }        
            case 18: 
                al_index=19; 
                //if(1){
               if((  (Bcan_count >= CAN_TIME)  )){    //电池管理系统无信息
                LCD_DrawImageSBPP(x,    y, Bmp_Display_bj_ZC_18,    Fcolor,color);             
                leng = 176;
                break; 
                }    
*/
            case 19: 
                al_index=20; 
                //if(1){
               if((VCU_Status[0] & 0x04)){    //整车控制器气压低
                LCD_DrawImageSBPP(x,    y, Bmp_Display_bj_ZC_19,    Fcolor,color);             
                leng = 152;
                break; 
                }            
            case 20: 
                al_index=21; 
                //if(1){
               if((VCU_Status[0] & 0x01)){    //一级故障：熔断器断开
                LCD_DrawImageSBPP(x,    y, Bmp_Display_bj_ZC_20,    Fcolor,color);             
                leng = 176;
                break; 
                }               
            case 21: 
                al_index=22; 
                //if(1){
                if(VCU_Status[4]&0X01){ //系统告警
                LCD_DrawImageSBPP(x, y, Bmp_Display_bj_ZC_21,   Fcolor,color);//           
                leng = 160;
                break; 
                }     
            case 22: 
                al_index=1; 
                //if(1){
                if((DC_Status[3]&0X03)==1){ //充电继电器故障
                LCD_DrawImageSBPP(x, y, Bmp_Display_bj_ZC_22,   Fcolor,color);//           
                leng = 136;
                break; 
                }         
                
            default:
                leng=0;al_index=1;
                break;
        }
            return leng;
}

void disp_CAN_baojing(unsigned int x,unsigned int y){
    static unsigned char al_index = 0;
    unsigned int  w=0;
    unsigned char color=0;
    unsigned char Fcolor=YELLOW;  
    unsigned int  Length=330;//250
    unsigned int  leng,temp;
    
    if (alarm_update_flag == 0) { //3S 更新一次 
        //LCD_DrawRect(x, y, 350 + 85 + 10, 36, BLACK); //清除显示区域
        switch (al_index) {
            case 0:
                al_index = 1;
                //if(1){
                if(M_ON && (Fcan_count>=CAN_TIME)){      
                LCD_DrawImage1BPP(x,    y, Bmp_front,Fcolor,color);
                LCD_DrawImage1BPP(x+16, y, Bmp_MK,   Fcolor,color);
                LCD_DrawImage1BPP(x+56, y, Bmp_CANST,Fcolor,color);                
                LCD_DrawImage1BPP(x+128,y, Bmp_ST[2],Fcolor,color);
                w=x+128+40;LCD_DrawRect(w, y, Length-w, 36, color);
                alarm_update_flag = 1;
                break;   
                }         
            case 1: 
                al_index=2;
                //if(1){
                if(M_ON && (Rcan_count>=CAN_TIME)){
                LCD_DrawImage1BPP(x,    y, Bmp_rear, Fcolor,color);
                LCD_DrawImage1BPP(x+16, y, Bmp_MK,   Fcolor,color);
                LCD_DrawImage1BPP(x+56, y, Bmp_CANST,Fcolor,color);             
                LCD_DrawImage1BPP(x+128,y, Bmp_ST[2],Fcolor,color);
                w=x+128+40;LCD_DrawRect(w, y, Length-w, 36, color);
                alarm_update_flag = 1;
                break; 
                }
            case 2: 
                al_index=3; 
                //if(1){
                if(M_ON && (Mcan_count>=CAN_TIME)){
                LCD_DrawImage1BPP(x,    y, Bmp_top,  Fcolor,color);
                LCD_DrawImage1BPP(x+16, y, Bmp_MK,   Fcolor,color);
                LCD_DrawImage1BPP(x+56, y, Bmp_CANST,Fcolor,color);              
                LCD_DrawImage1BPP(x+128,y, Bmp_ST[2],Fcolor,color);
                w=x+128+40;LCD_DrawRect(w, y, Length-w, 36, color);
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
                w=x+112+40;LCD_DrawRect(w, y, Length-w, 36, color);
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
                w=x+96+40;LCD_DrawRect(w, y, Length-w, 36, color);
                alarm_update_flag = 1;
                break; 
                }
            case 5: 
                al_index=6; 
                //if(1){
                if(Vspeed>690){ //您已超速      
                LCD_DrawImage1BPP(x, y, Bmp_nycs,Fcolor,color);
                w=x+80;LCD_DrawRect(w, y, Length-w, 36, color);
                alarm_update_flag = 1;
                break; 
                } 
            case 6: 
                al_index=7; 
                temp = (VCU_Status[5]&0x07);
                //if(1){
                if( (temp > 0) && (temp < 5) ){ //电量报警信息
                if(temp == 1){ LCD_DrawImageSBPP(x,y, Bmp_Display_bj_SOC_1, Fcolor,color); leng = 112;  } //电量低，请充电   
                if(temp == 2){ LCD_DrawImageSBPP(x,y, Bmp_Display_bj_SOC_2, Fcolor,color); leng = 216;  } //电量低，请充电 ，系统降功率 
                if(temp == 3){ LCD_DrawImageSBPP(x,y, Bmp_Display_bj_SOC_3, Fcolor,color); leng = 176;  } //电量低，请充电 ，无动力
                if(temp == 4){ LCD_DrawImageSBPP(x,y, Bmp_Display_bj_SOC_4, Fcolor,color); leng = 192;  } //电量低，请充电 ，电量耗尽  
                w=x+leng;LCD_DrawRect(w, y, Length-w, 36, color);
                alarm_update_flag = 1;
                break; 
                }	   
            case 7: 
                al_index=8; 
                temp = (VCU_Status[5]&0XC0)>>6;
                //if(1){
                if(temp > 0){ //电制动当前制动效果
                if(temp == 1){ LCD_DrawImageSBPP(x, y, Bmp_Display_bj_ZD_1,   Fcolor,color); leng = 112; }//电制动已衰减  
                if(temp == 2){ LCD_DrawImageSBPP(x, y, Bmp_Display_bj_ZD_2,   Fcolor,color); leng = 152; }//电制动已严重下降                
                if(temp == 3){ LCD_DrawImageSBPP(x, y, Bmp_Display_bj_ZD_3,   Fcolor,color); leng = 152; }//无电制动注意刹车                      
                w=x+leng;LCD_DrawRect(w, y, Length-w, 36, color);
                alarm_update_flag = 1;
                break; 
                }   
            case 8: 
                al_index=9; 
                temp = (R_ID&0X30)>>4;
                //if(1){
                if( (temp==1)||(temp==2) ){ //绝缘故障 
                if(temp == 2){ LCD_DrawImageSBPP(x, y, Bmp_Display_bj_JY_1,   Fcolor,color); leng = 192; }//一级故障：一级绝缘故障  
                if(temp == 1){ LCD_DrawImageSBPP(x, y, Bmp_Display_bj_JY_2,   Fcolor,color); leng = 192; }//二级故障：二级绝缘故障                                   
                w=x+leng;LCD_DrawRect(w, y, Length-w, 36, color);
                alarm_update_flag = 1;
                break; 
                }  
            case 9: 
                al_index=10; 
                temp = (YW_Status[0]&0X0f);
                //if(1){
                if( (temp==5)||(temp==6) ){ //电池仓烟雾
                if(temp == 5){ LCD_DrawImageSBPP(x, y, Bmp_Display_bj_YW_1,   Fcolor,color); leng = 256; }//一级故障：电池仓烟雾气体赌塞故障  
                if(temp == 6){ LCD_DrawImageSBPP(x, y, Bmp_Display_bj_YW_2,   Fcolor,color); leng = 256; }//一级故障：电池仓烟雾紧急报警                                  
                w=x+leng;LCD_DrawRect(w, y, Length-w, 36, color);
                alarm_update_flag = 1;
                break; 
                }  
            case 10: 
                al_index=11; 
                temp = (YW1_Status[0]&0X07);
                //if(1){
                if( (temp==5)||(temp==6) ){ //电池箱烟雾
                if(temp == 5){ LCD_DrawImageSBPP(x, y, Bmp_Display_bj_YW_3,   Fcolor,color); leng = 256; }//一级故障：电池箱烟雾气体赌塞故障   
                if(temp == 6){ LCD_DrawImageSBPP(x, y, Bmp_Display_bj_YW_4,   Fcolor,color); leng = 256; }//一级故障：电池箱烟雾紧急报警                                    
                w=x+leng;LCD_DrawRect(w, y, Length-w, 36, color);
                alarm_update_flag = 1;
                break; 
                }     

            case 11: 
                al_index=12; 
                //if(1){
               if( ( (Jcan_count >= 100) && (JLY_time[9]==JLY_time[8]) ) ||
                     (Jcan_count >= 100)  
                 ){    //时钟信息丢失，防乳化功能失效
                LCD_DrawImageSBPP(x,    y, Bmp_Display_bj_ZC_14,    Fcolor,color);             
                leng = 264;
                w=x+leng;LCD_DrawRect(w, y, Length-w, 36, color);
                alarm_update_flag = 1;
                break; 
                }          
            case 12: 
                al_index=13; 
                //if(1){
               if((  (JYcan_count >= 100) && (R_life[1]==R_life[2])  ) ||
                     (JYcan_count >= 100)  
                 ){    //绝缘监测仪无信息
                LCD_DrawImageSBPP(x,    y, Bmp_Display_bj_ZC_15,    Fcolor,color);             
                leng = 152;
                w=x+leng;LCD_DrawRect(w, y, Length-w, 36, color);
                alarm_update_flag = 1;
                break; 
                }    
            case 13: 
                al_index=14; 
                //if(1){
               if((  (Kcan_count >= CAN_TIME)  )){    //电机控制器无信息
                LCD_DrawImageSBPP(x,    y, Bmp_Display_bj_ZC_16,    Fcolor,color);             
                leng = 152;
                w=x+leng;LCD_DrawRect(w, y, Length-w, 36, color);
                alarm_update_flag = 1;
                break; 
                }       
            case 14: 
                al_index=15; 
                //if(1){
               if((  (Vcan_count >= CAN_TIME)  )){    //整车控制器无信息
                LCD_DrawImageSBPP(x,    y, Bmp_Display_bj_ZC_17,    Fcolor,color);             
                leng = 152;
                w=x+leng;LCD_DrawRect(w, y, Length-w, 36, color);
                alarm_update_flag = 1;
                break; 
                }        
            case 15: 
                al_index=16; 
                //if(1){
               if((  (Bcan_count >= CAN_TIME)  )){    //电池管理系统无信息
                LCD_DrawImageSBPP(x,    y, Bmp_Display_bj_ZC_18,    Fcolor,color);             
                leng = 176;
                w=x+leng;LCD_DrawRect(w, y, Length-w, 36, color);
                alarm_update_flag = 1;
                break; 
                }   
            case 16: 
                al_index=17; 
                //if(1){
                if( F_TaiYa ){     //胎压信息   
                LCD_DrawImageSBPP(x,    y, Bmp_Display_bj_ZC_23,    Fcolor,color);             
                leng = 80;
                w=x+leng;LCD_DrawRect(w, y, Length-w, 36, color);
                alarm_update_flag = 1;
                break; 
                }  

            case 17: 
                al_index=18; 
                w=x+disp_bj_ZC(x,y);
                if(w>x){
                LCD_DrawRect(w, y, Length-w, 36, color);
                alarm_update_flag = 1;  
                break; 
                }  
            case 18: 
                al_index=19; 
                w=x+disp_bj_JK(x,y);
                if(w>x){
                LCD_DrawRect(w, y, Length-w, 36, color);
                alarm_update_flag = 1;  
                break; 
                }  
            case 19: 
                al_index=20; 
                w=x+disp_bj_DJ(x,y);
                if(w>x){
                LCD_DrawRect(w, y, Length-w, 36, color);
                alarm_update_flag = 1;  
                break; 
                }  
            case 20: 
                al_index=21; 
                w=x+disp_bj_DC(x,y);
                if(w>x){
                LCD_DrawRect(w, y, Length-w, 36, color);
                alarm_update_flag = 1;  
                break; 
                }  
            case 21: 
                al_index=0; 
                w=x+disp_bj_YB(x,y);
                if(w>x){
                LCD_DrawRect(w, y, Length-w, 36, color);
                alarm_update_flag = 1;  
                break; 
                }  
                
            default:
                al_index=0; 
                LCD_DrawRect(x, y, Length-x, 36, color); //清除显示区域
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
    if(frmID != 29)disp_CAN_baojing(10,455-11);//
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
        case 3:
            frmDJ();
            break;
        case 4:
            frmBMS();
            break;
        case 5:
            //frmFuzhu();
            break;
        case 6:
            //frmMHQ();
            break;
        case 7:
            //frmDebug();
            break;      
        case 8:
            //frmAir();
            break;     
        case 9:
            frmYWu();
            break;         
        case 20:
            frmTaiYa();
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



