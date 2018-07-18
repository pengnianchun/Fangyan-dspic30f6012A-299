#include "SYSTEM.h"
#include "FONT.h"
//#include "LOGO.h"
#include "YBFONT.h"

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
 */
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

/*********************************************************
//函数名: void mainFrame(void)
//功能: 显示主界面不需要更新的内容,界面格式
//参数: 无
 *********************************************************/
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

x=161;y=265;
    for(i=0;i<5;i++){
    LCD_DrawRect(x,y+i*30,478, 1,GRAY);//-
   }
x=161;
    LCD_DrawRect(x,y,1, 120,GRAY);//|左
x=391;
    LCD_DrawRect(x,y,1, 120,GRAY);//|中
x=639;
    LCD_DrawRect(x,y,1, 120,GRAY);//|右
    
    //每次进入主界面，符号片颜色都是灰色，若不处理，只会第一次上电显示灰色，翻页后就不显示灰色
    for (i = 0; i < 24; i++) {
        color_old[i] = 0;
    }
    
  //LCD_DrawImage1BPPZOOM_4(336, 150, BMP_LOGO, BLUE, BLACK); //客车车标
//动力电池电流 电压 SOC 外观
//显示电压
    
    //LCD_DrawImage1BPP(175-5, 110 + 13, BMP_Voltage, WHITE, BLACK); //电压
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
    //LCD_DrawImage1BPP(660, 105 + 13, BMP_V, WHITE, BLACK); // V
    LCD_DrawImage1BPP(660-20, 105 + 13+8, Bmp_V, WHITE, BLACK); // V    
//显示电流
    //LCD_DrawImage1BPP(175-5, 110 + 60 + 13-5, BMP_Current, WHITE, BLACK); //电流
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
    //LCD_DrawImage1BPP(660, 105 + 60 + 13-5, BMP_A, WHITE, BLACK); //A
    LCD_DrawImage1BPP(660-20, 105 + 60 + 13-5+8, Bmp_A, WHITE, BLACK); //A
//显示SOC
    //LCD_DrawImage1BPP(170, 100 + 5 + 60 + 60 + 13-10, BMP_SOC, WHITE, BLACK); //SOC
    LCD_DrawImage1BPP(170+3, 100 + 5 + 60 + 60 + 13-10+5, Bmp_SOC, WHITE, BLACK); //SOC
    LCD_DrawRect(225, 100 + 5 + 60 + 60 + 13-10, 335, 2, WHITE);
    LCD_DrawRect(225, 100 + 35 + 60 + 60 + 13-10, 335, 2, WHITE);
    LCD_DrawRect(225, 105 + 60 + 60 + 13-10, 2, 32, WHITE);
    LCD_DrawRect(225 + 83, 95 + 60 + 60 + 13-10, 2, 10, WHITE);
    LCD_DrawRect(225 + 83 + 83, 95 + 60 + 60 + 13-10, 2, 10, WHITE);
    LCD_DrawRect(225 + 83 + 83 + 83, 95 + 60 + 60 + 13-10, 2, 10, WHITE);
    LCD_DrawRect(225 + 83 + 83 + 83 + 84, 105 + 60 + 60 + 13-10, 2, 32, WHITE);
    LCD_DrawImage1BPP(225 - 4, 105 - 14 + 60 + 60 + 13-10, BMP_SZ[0], WHITE, BLACK); //0
    LCD_DrawImage1BPP(225 + 83 + 83 + 83 + 84 - 12, 105 - 14 + 60 + 60 + 13-10, BMP_SZ[1], WHITE, BLACK); //1
    LCD_DrawImage1BPP(225 + 83 + 83 + 83 + 84 - 4, 105 - 14 + 60 + 60 + 13-10, BMP_SZ[0], WHITE, BLACK); //0
    LCD_DrawImage1BPP(225 + 83 + 83 + 83 + 84 + 4, 105 - 14 + 60 + 60 + 13-10, BMP_SZ[0], WHITE, BLACK); //0
    //LCD_DrawImage1BPP(660, 105 + 60 + 60 + 13-10, BMP_BAIFENHAO, WHITE, BLACK); // %
    LCD_DrawImage1BPP(660-20, 105 + 60 + 60 + 13-10+8, Bmp_bfh, WHITE, BLACK); // %

//显示里程
x=210-40;y=407-9;
    LCD_DrawImage1BPP(x,   y,Bmp_TRIP,  WHITE,BLACK);//单次
    LCD_DrawImage1BPP(x+40,y,Bmp_LCheng,WHITE,BLACK);//里程     
x=440-40; 
    LCD_DrawImage1BPP(x,   y,Bmp_ODO,   WHITE,BLACK);//总计 
    LCD_DrawImage1BPP(x+40,y,Bmp_LCheng,WHITE,BLACK);//里程
x=369-12;   
    LCD_DrawImage1BPP(x,   y,Bmp_Km,    WHITE,BLACK);//单位 Km  
x=617-12;      
    LCD_DrawImage1BPP(x,   y,Bmp_Km,    WHITE,BLACK);//单位 Km
     
//第二列
x=433-40;y=280-9;
   LCD_DrawImage1BPP(x,    y+0*30, Bmp_dj,  WHITE, BLACK);//控制器温度
   LCD_DrawImage1BPP(x+40, y+0*30, Bmp_kzq, WHITE, BLACK);//
   LCD_DrawImage1BPP(x+96, y+0*30, Bmp_wd,  WHITE, BLACK);// 
   LCD_DrawImage1BPP(x+226,y+0*30, Bmp_deg, WHITE, BLACK);// 

   LCD_DrawImage1BPP(x,    y+1*30, Bmp_dj,  WHITE,BLACK);//电机温度
   LCD_DrawImage1BPP(x+40, y+1*30, Bmp_wd,  WHITE,BLACK); 
   LCD_DrawImage1BPP(x+226,y+1*30, Bmp_deg, WHITE, BLACK);//
   
   LCD_DrawImage1BPP(x+2,  y+2*30, Bmp_dc,  WHITE, BLACK);//
   LCD_DrawImage1BPP(x+40, y+2*30, Bmp_zg,  WHITE, BLACK);//
   //LCD_DrawImage1BPP(x+40, y+2*30, Bmp_Zui, WHITE, BLACK);//
   //LCD_DrawImage1BPP(x+60, y+2*30, Bmp_Gao, WHITE, BLACK);//
   LCD_DrawImage1BPP(x+80, y+2*30, Bmp_wd,  WHITE, BLACK);// 
   LCD_DrawImage1BPP(x+226,y+2*30, Bmp_deg, WHITE, BLACK);//
   
//第一列
x=221-58;y=280-9;
   //LCD_DrawImage1BPP(x,    y+0*30, Bmp_xdc, WHITE, BLACK);// 蓄电池电压
   //LCD_DrawImage1BPP(x+56, y+0*30, Bmp_DY,  WHITE, BLACK); //
   //LCD_DrawImage1BPP(x+208,y+0*30, Bmp_V,   WHITE, BLACK);//  

   //LCD_DrawImage1BPP(x,    y+1*30, Bmp_dc,   WHITE, BLACK);// 电池故障等级
   //LCD_DrawImage1BPP(x+40, y+1*30, Bmp_ST[0],WHITE, BLACK); 
   //LCD_DrawImage1BPP(x+80, y+1*30, Bmp_DJi,  WHITE, BLACK); 

   //LCD_DrawImage1BPP(x,    y+2*30, Bmp_xt,    WHITE,BLACK); //系统代码
   //LCD_DrawImage1BPP(x+40, y+2*30, Bmp_DMa,   WHITE,BLACK); // 

    LCD_DrawImage1BPP(x,     y+0*30,Bmp_VCU,     WHITE,BLACK);  //MCU
    LCD_DrawImage1BPP(x,     y+1*30,Bmp_MCU,     WHITE,BLACK);  //MCU
    LCD_DrawImage1BPP(x,     y+2*30,Bmp_BMS,     WHITE,BLACK);  //BMS
    
    for(i=0;i<3;i++){
    LCD_DrawImage1BPP(x+40,  y+i*30,Bmp_ST[0],   WHITE,BLACK);  //故障
    LCD_DrawImage1BPP(x+80,  y+i*30,Bmp_DMa,     WHITE,BLACK);  //代码
    } 
    
    
}

void update_dc2(void){
  unsigned char color=0;
 
/////////////第二列/////////////
x=581-32;y=280-9; 
//控制器温度 
    update_deg(x,    y+0*30,DJcontroler_temperature1,WHITE);
//电机温度 
    update_deg(x,    y+1*30,DJ_temperature1,WHITE);
//电池最高温度 
    update_deg(x,    y+2*30,Tmax,WHITE);

   
/////////////第一列/////////////
x=333-32;y=280-9;
//蓄电池电压
    //print_SZ_2(x,    y+0*30,ADR[0],3,1,WHITE); // 0
//锂电池故障等级
    //print_SZ_2(x,    y+1*30,DC_fault,4,0,WHITE); // 0
//系统代码 80,180 
    //print_SZ_2(x-16,  y+2*30,system_fault,5,0,color);//  

//VCU故障代码
if(system_fault>0)color=RED;else color=WHITE;
    print_SZ_2(x,    y+0*30,system_fault,4,0,color); // 0
//MCU故障代码
if(DJ_fault>0)color=RED;else color=WHITE;
    print_SZ_2(x,    y+1*30,DJ_fault,4,0,color); // 0
//BMS故障代码
if(DC_Status[0]>0)color=RED;else color=WHITE;
    print_SZ_2(x,    y+2*30,DC_Status[0],4,0,color); // 0
      
}
void disp_baojing2(void){
  unsigned char s,i,j,color=GRAY;
  unsigned char temp8=0;
  
  if(DC_Status[2]&0x10){color=GREEN;i=0;}
  else                 {color=GRAY; i=1;}
  LCD_DrawImage1BPP(151-20, 64-8,Bmp_JRe,color,BLACK);//加热
  if(i==0){ LCD_DrawImage1BPP(151-18,    86-8,Bmp_Open, color,BLACK);//开
            LCD_DrawImage1BPP(151,       86-8,Bmp_QI,   color,BLACK);//启
          }
  if(i==1){ LCD_DrawImage1BPP(151-18,    86-8,Bmp_Close,color,BLACK);//关
            LCD_DrawImage1BPP(151,       86-8,Bmp_Bi,   color,BLACK);//闭
          } 
  
  if(VCU_Status[2]&0x02)color=GREEN;
  else                  color=GRAY;
  LCD_DrawImage1BPP(212-8, 75-10,Bmp_M,color,BLACK);//M
  
  if(VCU_Status[2]&0x01)color=GREEN;
  else                  color=GRAY;
  LCD_DrawImage1BPP(274-8, 75-16,Bmp_C,color,BLACK);//C
  
  if(VCU_Status[2]&0x04)color=GREEN;
  else                  color=GRAY;
  LCD_DrawImage1BPP(336-6, 75-10,Bmp_S,color,BLACK);//S
  
    temp8=(Gear);
     if( ((temp8>125)&&(temp8<=137))||(temp8==123) ){color=GREEN; i=0;}//D
else if(temp8==124){color=RED;   i=1;}//R
else if(temp8==125){color=GREEN; i=2;}//N
//else if(temp8==8){color=WHITE; i=3;}//P
else               {color=GRAY;  i=2;}//N
       LCD_DrawImage1BPP(396-7,75-10,Bmp_gear_DRN1[i],color,BLACK);//DRNP 小号档位
     //LCD_DrawImage1BPP(396-20,75-18,Bmp_gear_DRN[i],color,BLACK);//DRNP  大号档位
     if((temp8)==126) {color=GREEN;j=1;}//1
else if((temp8)==127) {color=GREEN;j=2;}//2
else if((temp8)==128) {color=GREEN;j=3;}//3
else if((temp8)==129) {color=GREEN;j=4;}//4
else if((temp8)==130) {color=GREEN;j=5;}//5
else if((temp8)==131) {color=GREEN;j=6;}//6
else if((temp8)==132) {color=GREEN;j=7;}//7
else if((temp8)==133) {color=GREEN;j=8;}//8
else if((temp8)==134) {color=GREEN;j=9;}//9
else if((temp8)==135) {color=GREEN;j=10;}//10 
else if((temp8)==136) {color=GREEN;j=11;}//11     
else if((temp8)==137) {color=GREEN;j=12;}//12   
else                  {color=BLACK;j=1;}
       if(j>9)s=2;else s=1;
       //print_SZ_2(396-7+16,75-10+1,j,s,0,color);
       print_SZ(396-7+16,75-10+1,j,s,0,color);
       if(s==1)print_SZ(396-7+16+8,75-10+1,j,s,0,BLACK);
       
  temp8=(VCU_Status[0]&0xc0)>>6;
  if(temp8==1)color=GREEN; 
  else        color=GRAY;
  LCD_DrawImage1BPP(458-28, 75-12, Bmp_READY,color,BLACK);//READY
  
  if(VCU_Status[2]&0x08)color=GREEN;
  else                  color=GRAY;
  LCD_DrawImage1BPP(519-27, 75-15,Bmp_TChe,color,BLACK);//拖车
  
  
  if(VCU_Status[1]&0x02)color=YELLOW;
  else                  color=GRAY;
  LCD_DrawImage1BPP(580-19, 75-19,Bmp_AMT2,color,BLACK);//变速器故障
  
}


void disp_baojing(void){
  unsigned char color=GRAY;

  //if(mKL4 ) color=RED;
  //else             color=GRAY; 
  //LCD_DrawImage1BPP(30-20,5,Bmp_yjf,color,BLACK);//应急阀开启报警开关 
  
  if(!fKL4)color=RED;// 
  else     color=GRAY; 
  if (color_old[0] != color) {
      color_old[0]  = color;
  //LCD_DrawImage1BPP(73, 7,Bmp_mcpL,color,BLACK);//蹄片磨损
  //LCD_DrawImage1BPP (93,16,BMP_SZ[1],color,BLACK);
  }
  
  //if(!fKL5)color=RED;  
  //else     color=GRAY;
  //if (color_old[1] != color) {
  //    color_old[1]  = color;
  //LCD_DrawImage1BPP(133, 7,Bmp_mcpL,color,BLACK);//蹄片磨损
  //LCD_DrawImage1BPP (153,16,BMP_SZ[1],color,BLACK); 
  //}
  
  if(DJ_Status[1]&0x10)color=RED;
  else                 color=GRAY;
  LCD_DrawImage1BPP(122+10, 10,Bmp_DJGRe,color,BLACK);//电机过热
  
  
  if(  rKL11 ) color=RED;
  else         color=GRAY; 
  LCD_DrawImage1BPP(216-28,25-24,Bmp_HCM,color,BLACK);//后舱门
 
  if(  rKL1 ) color=RED;
  else        color=GRAY; 
  LCD_DrawImage1BPP(275-18,25-18,Bmp_SW,color,BLACK);//水位报警

 
  if(VCU_Status[2]&0x10) color=RED;
  else                   color=GRAY; 
  LCD_DrawImage1BPP(336-16,25-15,Bmp_PXing,color,BLACK);//坡行
   
  if(VCU_Status[2]&0x20) color=GREEN;
  else                   color=GRAY; 
  LCD_DrawImage1BPP(397-20,25-20,Bmp_NLiang,color,BLACK);//能量回收
    
  if((eror_R==1)||(eror_R==2))color=RED; //  
  else                        color=GRAY;   
  LCD_DrawImage1BPP(457-14, 25-20,Bmp_jygz,color,BLACK);//绝缘故障报警
  
  if((VCU_Status[1]&0x01)||(DJ_Status[1]&0x80))color=RED; 
  else                                         color=GRAY; 
  LCD_DrawImage1BPP(518-20, 25-15,Bmp_XTgz,color,BLACK);//系统故障
  
//if((VCU_Status[0]&0x03)==0X01)color=YELLOW; 
  if((DC_Status[3]&&0x05)==0x00)color=YELLOW;//判断总正总负继电器状态 1闭合 0断开 
  else                          color=GRAY; 
  LCD_DrawImage1BPP(580-20, 25-14,Bmp_DCQDuan,color,BLACK);//电池切断 

  if(  IN22  )color=YELLOW;
  else        color=GRAY; 
  LCD_DrawImage1BPP(641-28,25-24,Bmp_TB_ABS,color,BLACK);//ABS报警
  
  //if(!fKL8) color=RED; //左  
  //else      color=GRAY; 
  //if (color_old[2] != color) {
  //    color_old[2]  = color;
  //LCD_DrawImage1BPP(622, 7,Bmp_mcpR,color,BLACK);//蹄片磨损
  //LCD_DrawImage1BPP (642,16, BMP_SZ[2],color,BLACK);
  //}
  
  if(!fKL5) color=RED; //右  
  else      color=GRAY; 
  if (color_old[3] != color) {
      color_old[3]  = color;
  //LCD_DrawImage1BPP(682, 7,Bmp_mcpR,color,BLACK);//蹄片磨损
  //LCD_DrawImage1BPP (702,16, BMP_SZ[1],color,BLACK);
  }
  

}

void disp_miles(void) {//显示里程
x=312-40-16;y=407-9;
    print_SZ_2(x, y,single_miles , 5, 1, WHITE);
x=552-49-16;    
    print_SZ_2(x, y, total_miles / 10, 7, 0, WHITE);
}

void updata_QY(void) {
    unsigned char color = RED;
    unsigned int press1 = 50; /*气压传感器量程是0-1.2Mpa ,对应为0-120 进度条0-100*/
    unsigned int press2 = 90; /*气压传感器量程是0-1.2Mpa ,对应为0-120 进度条0-100*/
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
    /*
    if (DCDY >= 1800) DCDY = 1800;
    if (DCDY < 1000) DCDY = 1000;
    print_SZ_1(x, y, (DCDY - 1000), 3, 0, WHITE); //电池电压数值 x=120+72+30   y=150+60-2
    if (DCDY > 1000 && frmID == 0)
        LCD_DrawRect(225 + 2, 100+13 + 5 + 2, ((DCDY - 1000) * 3.31 * 0.125), 28, GREEN); // 331/100  
    if (DCDY < 1800 && frmID == 0)//当为100时会出错
        LCD_DrawRect((225 + 2 + (DCDY - 1000) * 3.31 * 0.125), 100 +13+ 5 + 2, (331 - (DCDY - 1000) * 3.31 * 0.125), 28, BLACK);
    */
    if (DCDY >= 800) DCDY = 800;
    print_SZ_1(x, y, (DCDY), 3, 0, WHITE); //电池电压数值 x=120+72+30   y=150+60-2
    if (frmID == 0)
        LCD_DrawRect(225 + 2, 100+13 + 5 + 2, ((DCDY) * 3.31 * 0.125), 28, GREEN); // 331/100  

}

void updata_DCDL(unsigned int x, unsigned int y) {
    unsigned int DCDL = 100;
    DCDL = DC_current * 0.1;
    /*
    if (DCDL < 1000) {
        DCDL = 1000 - DCDL;
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
        DCDL = DCDL - 1000;
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
    */
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
    soc = DC_SOC ;//* 0.4;
    if (soc >= 100) soc = 100;
    
    //if (soc > 25) color = GREEN;
    //else if (soc > 0 && soc <= 25) color = RED;
    //else color = BLACK;
    
    if(soc>0){
        if( (DC_Status[0]==13 ) || //电池SOC过低 1 级
            (DC_Status[0]==63 ) || //电池SOC过低 2 级   
            (DC_Status[0]==113)    //电池SOC过低 3 级
          )  color = RED;
       else                 color = GREEN;   
    }else                   color = BLACK;
    print_SZ_1(585, 100 + 13 + 5 + 60 + 60 - 10, soc, 3, 0, WHITE); //SOC数值
    LCD_DrawRect(225 + 2, 100 + 13 + 5 + 60 + 60 + 2 - 10, (soc * 3.31), 28, color); // 331/100  
    if (soc < 100)//当soc为100时会出错//此时函数溢出
        LCD_DrawRect((225 + 2 + soc * 3.31), 100 + 13 + 5 + 60 + 60 + 2 - 10, (331 - soc * 3.31), 28, BLACK);
}

void updata_DJDY(unsigned int x, unsigned int y) {
    unsigned int DJDY = 500;
    //DJDY = moto_voltage * 0.1;
    if (DJDY < 1000) {
        //LCD_DrawImage1BPPZOOM_4(x - 40, y + 4, BMP_FU, WHITE, BLACK);
        print_SZ_1(x, y, 0, 3, 0, WHITE); //电机电压数值 x=120+72+35   y=250+60-2
    } else {
        //LCD_DrawImage1BPPZOOM_4(x - 40, y + 4, BMP_ZHENG, WHITE, BLACK);
        print_SZ_1(x, y, DJDY, 3, 0, WHITE); //电机电压数值 x=120+72+35   y=250+60-2
    }
}

void updata_DJDL(unsigned int x, unsigned int y) {
    unsigned char color = WHITE;
    unsigned int DJDL = 100;
    //DJDL = moto_current * 0.1;
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
    //rpm = moto_speed * 0.5;
    //if (rmp < 2000) {
    // LCD_DrawImage1BPPZOOM_4(x - 25, y + 5, BMP_FU, color, BLACK);
    // print_SZ_1(x, y, 2000 - rmp, 4, 0, color); //电流数值
    // } else {
    //     LCD_DrawImage1BPPZOOM_4(x - 25, y + 5, BMP_ZHENG, color, BLACK);
    print_SZ_1(x, y, rpm, 4, 0, color); //电流数值 x=135+180+50+100+20+20   y=250+55
    // }

}


void frmMain(void) {
    unsigned char color;
    if (f_index == 0) { //只更新一次
        f_index = 1;
        mainFrame();     
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
            if ((LED15 == 1) && (!time_flag)) {//背光开启
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
  LCD_DrawImage1BPP(x+18,y+0*34,Bmp_IN3,WHITE,BLACK);  
  
  LCD_DrawImage1BPP(x,y+1*34,Bmp_IN1,WHITE,BLACK); 
  LCD_DrawImage1BPP(x,y+2*34,Bmp_IN2,WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+3*34,Bmp_IN4,WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+4*34,Bmp_right,WHITE,BLACK); 
  LCD_DrawImage1BPP(x+18,y+4*34,Bmp_IN3,WHITE,BLACK); 
  
  LCD_DrawImage1BPP(x,y+5*34,Bmp_IN5,WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+6*34,Bmp_IN6,WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+7*34,Bmp_IN7,WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+7*34,Bmp_Jing,WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+8*34,Bmp_front,WHITE,BLACK);
  LCD_DrawImage1BPP(x+18,y+8*34,Bmp_IN8,WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+9*34,Bmp_rear,WHITE,BLACK);
  LCD_DrawImage1BPP(x+18,y+9*34,Bmp_IN9,WHITE,BLACK);
  
//第二列 
  x=500;y=95;
  LCD_DrawImage1BPP(x,y+0*34,Bmp_IN11,WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+1*34,Bmp_IN12,WHITE,BLACK);//
  LCD_DrawImage1BPP(x,y+2*34,Bmp_IN13,WHITE,BLACK);//

  disp_yg(x,y+3*34,Bmp_IN14);
  disp_yg(x,y+4*34,Bmp_IN15);
  disp_yg(x,y+5*34,Bmp_IN16);  
  
  LCD_DrawImage1BPP(x,y+6*34,Bmp_IN17,WHITE,BLACK);// 
  LCD_DrawImage1BPP(x,y+7*34,Bmp_IN18,WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+8*34,Bmp_IN19,WHITE,BLACK);// 
  
  //LCD_DrawImage1BPP(x,y+9*34,Bmp_front,WHITE,BLACK);//
  LCD_DrawImage1BPP(x,y+9*34,Bmp_IN20,WHITE,BLACK);//
  //LCD_DrawImage1BPP(x+40,y+9*34,Bmp_Open,WHITE,BLACK);//
  
  unsigned int Iid1[20]={154,0,0,136,154,120,136,136,136,136,
                         0,0,0,580,580,580,0,0,0,0};
  disp_kg(Iid1);  //显示开关
}
//显示仪表开关2
void disp_KL2(void){
  unsigned int Iid[20]={17,18,19,20,28,27,26,25,32,31,
                        30,29,1,2,3,4,5,10,20,13};
  disp_ID(0,Iid); //显示编号
  x=80;y=95;
  disp_yg(x,y+0*34,Bmp_IN21);
 
  LCD_DrawImage1BPP(x,y+1*34,Bmp_IN22,WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+2*34,Bmp_IN23,WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+3*34,Bmp_IN23,WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+4*34,Bmp_IN23,WHITE,BLACK);
  
  //LCD_DrawImage1BPP(x,y+5*34,Bmp_rear,WHITE,BLACK);  
  LCD_DrawImage1BPP(x,y+5*34,Bmp_IN26,WHITE,BLACK);
  //LCD_DrawImage1BPP(x+40,y+5*34,Bmp_Close,WHITE,BLACK);//
  
  //LCD_DrawImage1BPP(x,y+6*34,Bmp_rear,WHITE,BLACK);  
  LCD_DrawImage1BPP(x,y+6*34,Bmp_IN27,WHITE,BLACK);
  //LCD_DrawImage1BPP(x+40,y+6*34,Bmp_Open,WHITE,BLACK);//
  
  //LCD_DrawImage1BPP(x,y+7*34,Bmp_front,WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+7*34,Bmp_IN28,WHITE,BLACK);
  //LCD_DrawImage1BPP(x+40,y+7*34,Bmp_Close,WHITE,BLACK);//
  
  LCD_DrawImage1BPP(x,y+8*34,Bmp_IN29,WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+9*34,Bmp_IN30,WHITE,BLACK);  

  
//第二列 
  x=500;y=95;
  LCD_DrawImage1BPP(x,y+0*34,Bmp_IN31,WHITE,BLACK); 
  LCD_DrawImage1BPP(x,y+1*34,Bmp_IN32,WHITE,BLACK); 
  LCD_DrawImage1BPP(x,y+2*34,Bmp_IN33,WHITE,BLACK); 
  LCD_DrawImage1BPP(x,y+3*34,Bmp_IN34,WHITE,BLACK); 
  LCD_DrawImage1BPP(x,y+4*34,Bmp_IN35,WHITE,BLACK); 
  LCD_DrawImage1BPP(x,y+5*34,Bmp_IN36,WHITE,BLACK); 
  LCD_DrawImage1BPP(x,y+6*34,Bmp_IN37,WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+7*34,Bmp_wakeup1,WHITE,BLACK);  
  LCD_DrawImage1BPP(x+40,y+7*34,Bmp_bj,WHITE,BLACK);  
  
  LCD_DrawImage1BPP(x,y+8*34,Bmp_wakeup2,WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+9*34,Bmp_wakeup3,WHITE,BLACK);
  
  unsigned int Iid1[20]={160,118,0,0,0,0,0,0,0,0,
                         0,0,0,0,0,0,0,580,540,556,};
  disp_kg(Iid1);  //显示开关
}

//显示仪表传感器信号
void disp_ADR(void){ 
 unsigned int  j=0,i=0;
 unsigned char Iid[2][8]={ {8,7,6,5,4,3,2,1},
                           {15,10,9,19,18,0,0,0  } };
 
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
     
     LCD_DrawImage1BPP(x,   y+4*34,Bmp_rear,WHITE,BLACK);
     LCD_DrawImage1BPP(x+20,y+4*34,Bmp_SER5, WHITE,BLACK);
     
     LCD_DrawImage1BPP(x,   y+5*34,Bmp_front, WHITE,BLACK);
     LCD_DrawImage1BPP(x+20,y+5*34,Bmp_SER6, WHITE,BLACK); 
     
     LCD_DrawImage1BPP(x+20,y+6*34,Bmp_FREQ1,WHITE,BLACK);
     LCD_DrawImage1BPP(x+20,y+7*34,Bmp_FREQ2,WHITE,BLACK);

   for(i=0;i<8;i++){
     LCD_DrawImage1BPP(x+60,y+i*34,Bmp_adr,WHITE,BLACK);

    if(i<4)
     LCD_DrawImage1BPP(x+170,y+i*34,Bmp_R, WHITE,BLACK); 
    else  if(i<6)
     LCD_DrawImage1BPP(x+170,y+i*34,Bmp_V,WHITE,BLACK);       
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
  
  LCD_DrawImage1BPP(x,y+3*34,Bmp_front, WHITE,BLACK);//
  LCD_DrawImage1BPP(x+18,y+3*34,Bmp_front_load4, WHITE,BLACK);//
  
  LCD_DrawImage1BPP(x,y+4*34,Bmp_front_load5, WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+5*34,Bmp_right, WHITE,BLACK);//
  LCD_DrawImage1BPP(x+18,y+5*34,Bmp_front_load6, WHITE,BLACK);//
  
  LCD_DrawImage1BPP(x,y+6*34,Bmp_left, WHITE,BLACK);// 
  LCD_DrawImage1BPP(x+18,y+6*34,Bmp_front_load7, WHITE,BLACK);//
  
  LCD_DrawImage1BPP(x,y+7*34,Bmp_front_load8, WHITE,BLACK);
  LCD_DrawImage1BPP(x+40,y+7*34,Bmp_XShi, WHITE,BLACK);
  LCD_DrawImage1BPP(x+80,y+7*34,Bmp_dy, WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+8*34,Bmp_left, WHITE,BLACK); 
  LCD_DrawImage1BPP(x+18,y+8*34,Bmp_front_load9, WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+9*34,Bmp_front_load10,WHITE,BLACK);//
  LCD_DrawImage1BPP(x+56,y+9*34,Bmp_dy,WHITE,BLACK); 
  
//第二列
  x=500;y=95;
  LCD_DrawImage1BPP(x,y+0*34,Bmp_right,WHITE,BLACK);
  LCD_DrawImage1BPP(x+18,y+0*34,Bmp_front_load11,WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+1*34,Bmp_front_load12,WHITE,BLACK);
  LCD_DrawImage1BPP(x+56,y+1*34,Bmp_dy,WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+2*34,Bmp_left,WHITE,BLACK);//
  LCD_DrawImage1BPP(x+18,y+2*34,Bmp_front_load13,WHITE,BLACK);//
  LCD_DrawImage1BPP(x+18,y+2*34,Bmp_Jing,WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+3*34,Bmp_qy,WHITE,BLACK);//
  LCD_DrawImage1BPP(x+40,y+3*34,Bmp_front_load14,WHITE,BLACK);//
  LCD_DrawImage1BPP(x+96,y+3*34,Bmp_dy,WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+4*34,Bmp_right,WHITE,BLACK);//
  LCD_DrawImage1BPP(x+18,y+4*34,Bmp_front_load15,WHITE,BLACK);//
  LCD_DrawImage1BPP(x+18,y+4*34,Bmp_Jing,WHITE,BLACK);
  
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
  
  LCD_DrawImage1BPP(x,y+3*34,Bmp_left, WHITE,BLACK);
  LCD_DrawImage1BPP(x+18,y+3*34,Bmp_front, WHITE,BLACK);
  LCD_DrawImage1BPP(x+36,y+3*34,Bmp_FKL4, WHITE,BLACK);
  LCD_DrawImage1BPP(x+92,y+3*34,Bmp_bj, WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+4*34,Bmp_right, WHITE,BLACK);  
  LCD_DrawImage1BPP(x+18,y+4*34,Bmp_front, WHITE,BLACK); 
  LCD_DrawImage1BPP(x+36,y+4*34,Bmp_FKL5, WHITE,BLACK);
  LCD_DrawImage1BPP(x+92,y+4*34,Bmp_bj, WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+5*34,Bmp_FKL6, WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+6*34,Bmp_FKL7, WHITE,BLACK);
  
  //LCD_DrawImage1BPP(x,y+7*34,Bmp_left, WHITE,BLACK);
  //LCD_DrawImage1BPP(x+18,y+7*34,Bmp_rear, WHITE,BLACK);
  //LCD_DrawImage1BPP(x+36,y+7*34,Bmp_FKL8, WHITE,BLACK);
  //LCD_DrawImage1BPP(x+92,y+7*34,Bmp_bj, WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+7*34,Bmp_KL, WHITE,BLACK);
  
  //LCD_DrawImage1BPP(x,y+8*34,Bmp_right, WHITE,BLACK);
  //LCD_DrawImage1BPP(x+18,y+8*34,Bmp_rear, WHITE,BLACK);
  //LCD_DrawImage1BPP(x+36,y+8*34,Bmp_FKL9, WHITE,BLACK);
  //LCD_DrawImage1BPP(x+92,y+8*34,Bmp_bj, WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+8*34,Bmp_KL, WHITE,BLACK);
      
  LCD_DrawImage1BPP(x,y+9*34,Bmp_FKL10,WHITE,BLACK);

//第二列 
  x=500;y=95;
  LCD_DrawImage1BPP(x,y+0*34,Bmp_FKL11,WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+1*34,Bmp_FKL12,WHITE,BLACK);
  disp_ADD(1);// KL13 KL14 作为地址线
  
  LCD_DrawImage1BPP(x,y+4*34,Bmp_front,WHITE,BLACK);
  LCD_DrawImage1BPP(x+18,y+4*34,Bmp_Door,WHITE,BLACK);
  LCD_DrawImage1BPP(x+36,y+4*34,Bmp_Open,WHITE,BLACK);
  LCD_DrawImage1BPP(x+56,y+4*34,Bmp_FKL15,WHITE,BLACK);
  
  disp_yg(x,y+5*34,4);
  
  LCD_DrawImage1BPP(x,y+6*34,Bmp_rear,WHITE,BLACK);
  LCD_DrawImage1BPP(x+18,y+6*34,Bmp_Door,WHITE,BLACK);
  LCD_DrawImage1BPP(x+36,y+6*34,Bmp_Open,WHITE,BLACK);
  LCD_DrawImage1BPP(x+56,y+6*34,Bmp_FKH1,WHITE,BLACK); 

  unsigned int Iid1[20]={0,0,0,0,0,136,0,0,0,0,
                         0,0,0,0,596,580,596,0,0,0};
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
  LCD_DrawImage1BPP(x+56,y+0*34,Bmp_dy,WHITE,BLACK);  
  LCD_DrawImage1BPP(x+96,y+0*34,Bmp_ABS,WHITE,BLACK); 
  
  LCD_DrawImage1BPP(x,y+1*34,Bmp_rear_load2,WHITE,BLACK);  
  LCD_DrawImage1BPP(x+56,y+1*34,Bmp_PQKZhi,WHITE,BLACK);  
 
  LCD_DrawImage1BPP(x,y+2*34,Bmp_rear_load3,WHITE,BLACK); 
  LCD_DrawImage1BPP(x+56,y+2*34,Bmp_dy,WHITE,BLACK);  
    
  LCD_DrawImage1BPP(x,y+3*34,Bmp_rear_load4, WHITE,BLACK);//
  LCD_DrawImage1BPP(x+56,y+3*34,Bmp_EN, WHITE,BLACK);// 
  LCD_DrawImage1BPP(x+96,y+3*34,BMP_Control, WHITE,BLACK);//   
  
  LCD_DrawImage1BPP(x,y+4*34,Bmp_rear_load5, WHITE,BLACK);
  LCD_DrawImage1BPP(x+118,y+4*34,Bmp_dy, WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+5*34,Bmp_rear_load6, WHITE,BLACK);//
  LCD_DrawImage1BPP(x+56,y+5*34,Bmp_dy, WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+6*34,Bmp_rear_load7, WHITE,BLACK);//
  LCD_DrawImage1BPP(x+56,y+6*34,Bmp_dy, WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+7*34,Bmp_rear_load8, WHITE,BLACK);
  LCD_DrawImage1BPP(x+56,y+7*34,Bmp_dy, WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+8*34,Bmp_rear_load9, WHITE,BLACK);
  
  LCD_DrawImage1BPP(x+4,y+9*34,Bmp_wakeup3,WHITE,BLACK);//
  LCD_DrawImage1BPP(x,y+9*34,Bmp_rear_load10,WHITE,BLACK);//
  LCD_DrawImage1BPP(x+60,y+9*34,Bmp_dy,WHITE,BLACK);//

//第二列
  x=500;y=95;
  LCD_DrawImage1BPP(x,y+0*34,Bmp_rear,WHITE,BLACK);
  LCD_DrawImage1BPP(x+18,y+0*34,Bmp_rear_load11,WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+1*34,Bmp_rear_load12,WHITE,BLACK);
  LCD_DrawImage1BPP(x+118,y+1*34,Bmp_dy,WHITE,BLACK);//
  
  LCD_DrawImage1BPP(x,y+2*34,Bmp_rear_load13,WHITE,BLACK);//
  LCD_DrawImage1BPP(x+96,y+2*34,Bmp_dy,WHITE,BLACK);//
  
  LCD_DrawImage1BPP(x,y+3*34,Bmp_rear_load14,WHITE,BLACK);//
  
  LCD_DrawImage1BPP(x,y+4*34,Bmp_rear_load15,WHITE,BLACK);//
  LCD_DrawImage1BPP(x+58,y+4*34,Bmp_fs,WHITE,BLACK);//  
  LCD_DrawImage1BPP(x+96,y+4*34,BMP_Control, WHITE,BLACK);// 
  
}

//后部模块开关信息
void disp_rear_KL(void){
  unsigned int Iid[20]={32,18,33,19,34,20,35,21,36,22,
                        37,23,38,24,39,41,17,25,40,26};
  disp_ID(0,Iid);
//第一列
  x=80;y=95;
  LCD_DrawImage1BPP(x,y+0*34,Bmp_RKL1, WHITE,BLACK);
  LCD_DrawImage1BPP(x+40,y+0*34,Bmp_CGQi, WHITE,BLACK);  
  
  LCD_DrawImage1BPP(x,y+1*34,Bmp_RKL2, WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+2*34,Bmp_RKL3, WHITE,BLACK);
  
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

  unsigned int Iid1[20]={176,0,0,0,0,0,0,120,0,0,
                         556,0,0,0,0,0,0,0,0,0};
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
  LCD_DrawImage1BPP(x+56,y+0*34,Bmp_dy,WHITE,BLACK);//
  
  LCD_DrawImage1BPP(x,y+1*34,Bmp_right, WHITE,BLACK);
  LCD_DrawImage1BPP(x+18,y+1*34,Bmp_top_load2, WHITE,BLACK);
  
  LCD_DrawImage1BPP(x+83,y+2*34,Bmp_wakeup3, WHITE,BLACK); 
  LCD_DrawImage1BPP(x,y+2*34,Bmp_top_load3, WHITE,BLACK);
  LCD_DrawImage1BPP(x+140,y+2*34,Bmp_dy,WHITE,BLACK);//
  
  LCD_DrawImage1BPP(x,y+3*34,Bmp_top_load4, WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+4*34,Bmp_front, WHITE,BLACK);
  LCD_DrawImage1BPP(x+18,y+4*34,Bmp_top_load5, WHITE,BLACK);
  LCD_DrawImage1BPP(x+38,y+4*34,Bmp_Open,WHITE,BLACK);//  
  LCD_DrawImage1BPP(x+58,y+4*34,Bmp_dcf, WHITE,BLACK); 

    
  LCD_DrawImage1BPP(x,y+5*34,Bmp_top_load6, WHITE,BLACK);
  LCD_DrawImage1BPP(x+18,y+5*34,Bmp_Beng, WHITE,BLACK);
  LCD_DrawImage1BPP(x+40,y+5*34,Bmp_dy,WHITE,BLACK);//
  
  LCD_DrawImage1BPP(x,y+6*34,Bmp_front, WHITE,BLACK);
  LCD_DrawImage1BPP(x+18,y+6*34,Bmp_top_load7, WHITE,BLACK);
  LCD_DrawImage1BPP(x+38,y+6*34,Bmp_Close,WHITE,BLACK);//  
  LCD_DrawImage1BPP(x+58,y+6*34,Bmp_dcf, WHITE,BLACK);

  
  LCD_DrawImage1BPP(x,y+7*34,Bmp_top_load8, WHITE,BLACK);
  LCD_DrawImage1BPP(x+97,y+7*34,Bmp_dy,WHITE,BLACK);//
    
  LCD_DrawImage1BPP(x,y+8*34,Bmp_rear, WHITE,BLACK);
  LCD_DrawImage1BPP(x+18,y+8*34,Bmp_top_load9, WHITE,BLACK);
  LCD_DrawImage1BPP(x+38,y+8*34,Bmp_Open,WHITE,BLACK);//  
  LCD_DrawImage1BPP(x+58,y+8*34,Bmp_dcf, WHITE,BLACK); 
   
  LCD_DrawImage1BPP(x,y+9*34,Bmp_top_load10,WHITE,BLACK);
  LCD_DrawImage1BPP(x+40,y+9*34,Bmp_dy,WHITE,BLACK);//
  
//第二列 
  x=500;y=95;
  LCD_DrawImage1BPP(x,y+0*34,Bmp_rear,WHITE,BLACK);  
  LCD_DrawImage1BPP(x+18,y+0*34,Bmp_top_load11,WHITE,BLACK);
  LCD_DrawImage1BPP(x+38,y+0*34,Bmp_Close,WHITE,BLACK);// 
  LCD_DrawImage1BPP(x+58,y+0*34,Bmp_dcf,WHITE,BLACK);
    
  LCD_DrawImage1BPP(x,y+1*34,Bmp_top_load12,WHITE,BLACK);
  LCD_DrawImage1BPP(x+56,y+1*34,Bmp_dy,WHITE,BLACK);//
  
  LCD_DrawImage1BPP(x,y+2*34,Bmp_top_load13,WHITE,BLACK);
  LCD_DrawImage1BPP(x+40,y+2*34,Bmp_dy,WHITE,BLACK);//
  
  LCD_DrawImage1BPP(x,y+3*34,Bmp_top_load14,WHITE,BLACK);
  LCD_DrawImage1BPP(x+40,y+3*34,Bmp_fs,WHITE,BLACK);
  LCD_DrawImage1BPP(x+80,y+3*34,Bmp_dy,WHITE,BLACK);//
  
  LCD_DrawImage1BPP(x,y+4*34,Bmp_left,WHITE,BLACK); 
  LCD_DrawImage1BPP(x+18,y+4*34,Bmp_top_load15,WHITE,BLACK);
  
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
  
  LCD_DrawImage1BPP(x,y+7*34,Bmp_TKL8, WHITE,BLACK);
  LCD_DrawImage1BPP(x+40,y+7*34,Bmp_fs,WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+8*34,Bmp_TKL9, WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+9*34,Bmp_TKL10,WHITE,BLACK);

//第二列 +
  x=500;y=95;
  LCD_DrawImage1BPP(x,y+0*34,Bmp_TKL11,WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+1*34,Bmp_TKL12,WHITE,BLACK);
  disp_ADD(3);// KL13 KL14 作为地址线
  
  LCD_DrawImage1BPP(x,y+4*34,Bmp_front,WHITE,BLACK);
  LCD_DrawImage1BPP(x+18,y+4*34,Bmp_TKL15,WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+5*34,Bmp_TADD, WHITE,BLACK); 
  
  LCD_DrawImage1BPP(x,y+6*34,Bmp_rear, WHITE,BLACK);  
  LCD_DrawImage1BPP(x+18,y+6*34,Bmp_TKH1, WHITE,BLACK); 

  unsigned int Iid1[20]={0,136,0,0,0,120,0,160,0,0,
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
  switch(index){
   case 0:
    TCAN=Fcan_count;
    Tdate=((unsigned int )(fPOUT.BYTES[1])<<8)+fPOUT.BYTES[0];
    //Sdate=((unsigned long)(fPF[3].byte)<<24)+((unsigned long)(fPF[2].byte)<<16)+
    //      ((unsigned long)(fPF[1].byte)<<8)+fPF[0].byte;
    Sdate=fPF; //电流负载状态
    Pcurrent=fpcur;//反馈电流
   break;
   case 1:
    TCAN=Rcan_count;
    Tdate=((unsigned int )(rPOUT.BYTES[1])<<8)+rPOUT.BYTES[0];
    //Sdate=((unsigned long)(rPF[3].byte)<<24)+((unsigned long)(rPF[2].byte)<<16)+
    //      ((unsigned long)(rPF[1].byte)<<8)+rPF[0].byte;
    Sdate=rPF; //电流负载状态
    Pcurrent=rpcur;//反馈电流
   break;
   case 2:
    TCAN=Mcan_count;
    Tdate=((unsigned int )(mPOUT.BYTES[1])<<8)+mPOUT.BYTES[0];
    //Sdate=((unsigned long)(mPF[3].byte)<<24)+((unsigned long)(mPF[2].byte)<<16)+
    //      ((unsigned long)(mPF[1].byte)<<8)+mPF[0].byte;
    Sdate=mPF; //电流负载状态
    Pcurrent=mpcur;//反馈电流
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
 
  for(i=0;i<4;i++){   
    print_SZ_2(200,95+i*34,ADR[i+1],4,0,WHITE);
  }
    x=100+170+20+20;y=95+0*34;
  if(ADR[1]<PT1000[0][0])s=40;
  else   if(ADR[1]>PT1000[54][1])s=95;
  else {
            for(i=0;i<55;i++){
                if((ADR[1]>PT1000[i][0])&&(ADR[1]<=PT1000[i][1])){s=PT1000[i][2];break;}
            }
  }
  print_SZ_2(x,y,s,2,0,WHITE);
  LCD_DrawImage1BPP(x+40,y,Bmp_deg, WHITE,BLACK); 
  
  print_SZ_2(200,95+4*34,ADV[5]/10,3,2,WHITE);
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
     if(Did>=6) Did=0;
     else       Did++;
  }
  if(key_reset){
     if(Did>0)  Did--;
     else       Did=6;
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

/******************************************************/

void MenuFrame(void) {
    LCD_Clear();
    unsigned char color = WHITE;
    LCD_DrawRect(0, 56,  800, 2, GRAY); //顶部横线 
    LCD_DrawRect(0, 430, 800, 2, GRAY); //底部横线
    
    LCD_DrawImage1BPP(340,   30,BMP_STSTEM, GREEN,BLACK);//系统
    LCD_DrawImage1BPP(340+40,30,Bmp_Menu,   GREEN,BLACK);//菜单
    LCD_DrawImage1BPP(340+80,30,BMP_Message,GREEN,BLACK);//信息
    
x=400-60;y=75-9;
    LCD_DrawImage1BPP(x,    y+0*30, BMP_Control, color, BLACK); //控制
    LCD_DrawImage1BPP(x+40, y+0*30, BMP_STSTEM,  color, BLACK); //系统
    LCD_DrawImage1BPP(x+80, y+0*30, BMP_Message, color, BLACK); //信息

  //LCD_DrawImage1BPP(x,    y+1*30, BMP_Engine, color, BLACK);  //发动机
    LCD_DrawImage1BPP(x,    y+1*30, BMP_DJ,      color, BLACK); //电机   
    LCD_DrawImage1BPP(x+40, y+1*30, BMP_STSTEM,  color, BLACK); //系统
    LCD_DrawImage1BPP(x+80, y+1*30, BMP_Message, color, BLACK); //信息
    
    LCD_DrawImage1BPP(x,    y+2*30, BMP_Battery, color, BLACK); //电池    
    LCD_DrawImage1BPP(x+40, y+2*30, BMP_STSTEM,  color, BLACK); //系统
    LCD_DrawImage1BPP(x+80, y+2*30, BMP_Message, color, BLACK); //信息
 
    LCD_DrawImage1BPP(x,    y+3*30, BMP_Fuzhu,   color, BLACK); //辅助    
    LCD_DrawImage1BPP(x+40, y+3*30, BMP_STSTEM,  color, BLACK); //系统
    LCD_DrawImage1BPP(x+80, y+3*30, BMP_Message, color, BLACK); //信息
    
    LCD_DrawImage1BPP(x,    y+4*30, Bmp_MHQ,     color, BLACK); //灭火    
    LCD_DrawImage1BPP(x+40, y+4*30, BMP_STSTEM,  color, BLACK); //系统
    LCD_DrawImage1BPP(x+80, y+4*30, BMP_Message, color, BLACK); //信息

  //LCD_DrawImage1BPP(x,    y+5*30, BMP_Air,     color, BLACK); //空调
  //LCD_DrawImage1BPP(x+40, y+5*30, BMP_STSTEM,  color, BLACK); //系统
  //LCD_DrawImage1BPP(x+80, y+5*30, BMP_Message, color, BLACK); //信息   

    LCD_DrawImage1BPP(x,    y+5*30, BMP_IC,      color, BLACK); //仪表
    LCD_DrawImage1BPP(x+40, y+5*30, BMP_STSTEM,  color, BLACK); //系统
    LCD_DrawImage1BPP(x+80, y+5*30, BMP_Message, color, BLACK); //信息

    LCD_DrawImage1BPP(x,    y+6*30,Bmp_SJSZ,     color, BLACK); //时间设置 
    
    LCD_DrawImage1BPP(x,    y+7*30,Bmp_csu,      color, BLACK); //车速
    LCD_DrawImage1BPP(x+40, y+7*30,Bmp_subi,     color, BLACK); //速比
    
    LCD_DrawImage1BPP(x,    y+8*30,Bmp_TChu,     color, BLACK); //退出
      
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
                frmID = 4;//8
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
                frmID = 5;
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
                frmID = 6;
            }
            time_flag = 0;
        }
    } else
        color = BLACK;
    LCD_DrawImage1BPP(x,  y+4*30, BMP_Choose, color, BLACK);
    /*
    if (i == 15 || i == 5) {
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
    LCD_DrawImage1BPP(x,  y+5*30, BMP_Choose, color, BLACK);
    */
    if (i == 14 || i == 5) {
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
    LCD_DrawRect(x+196,   y+6*35,1, 140,GRAY);//|中    
x=531;
   //LCD_DrawRect(x,y,1, 350,GRAY);//|中2
x=793;
    LCD_DrawRect(x,y,1, 350,GRAY);//|右

///////////////////////第一列///////////////////////  
x=10;y=84-9;
    LCD_DrawImage1BPP(x,     y+0*35,Bmp_xt,      WHITE,BLACK);  //系统
    LCD_DrawImage1BPP(x+40,  y+0*35,Bmp_HSuo,    WHITE,BLACK);  //互锁
    LCD_DrawImage1BPP(x+80,  y+0*35,Bmp_ZT,      WHITE,BLACK);  //状态

    for(i=1;i<4;i++){
    LCD_DrawImage1BPP(x,     y+i*35,Bmp_VCU,     WHITE,BLACK);  //VCU  
    }
    LCD_DrawImage1BPP(x+40,  y+1*35,Bmp_ZJian,   WHITE,BLACK);  //自检    
    LCD_DrawImage1BPP(x+80,  y+1*35,Bmp_ZT,      WHITE,BLACK);  //状态    

    LCD_DrawImage1BPP(x+40,  y+2*35,Bmp_ST[0],   WHITE,BLACK);  //故障
    LCD_DrawImage1BPP(x+80,  y+2*35,Bmp_DMa,     WHITE,BLACK);  //代码
    
    LCD_DrawImage1BPP(x,     y+3*35,Bmp_life,    WHITE,BLACK);   //LIFE 
    LCD_DrawImage1BPP(x,     y+3*35,Bmp_VCU,     WHITE,BLACK);   //VCU  
    
    LCD_DrawImage1BPP(x,     y+4*35,Bmp_MCU,     WHITE,BLACK);  //MCU
    LCD_DrawImage1BPP(x+40,  y+4*35,Bmp_ST[0],   WHITE,BLACK);  //故障
    LCD_DrawImage1BPP(x+80,  y+4*35,Bmp_DMa,     WHITE,BLACK);  //代码  
    
    LCD_DrawImage1BPP(x,     y+5*35,Bmp_MCU,     WHITE,BLACK);  //MCU
    LCD_DrawImage1BPP(x+40,  y+5*35,Bmp_ZJian,   WHITE,BLACK);  //自检    
    LCD_DrawImage1BPP(x+80,  y+5*35,Bmp_ZT,      WHITE,BLACK);  //状态 
///////////////////////第二列///////////////////////
x=463-58;y=84-9; 
    LCD_DrawImage1BPP(x,     y+0*35,Bmp_QDong,   WHITE,BLACK);  //
    LCD_DrawImage1BPP(x+40,  y+0*35,Bmp_BPQi,    WHITE,BLACK);  //
    LCD_DrawImage1BPP(x+96,  y+0*35,Bmp_MXian,   WHITE,BLACK);  //
    LCD_DrawImage1BPP(x+136, y+0*35,Bmp_DY,      WHITE,BLACK);  //  
    
    LCD_DrawImage1BPP(x,     y+1*35,Bmp_dj,      WHITE,BLACK);  //
    LCD_DrawImage1BPP(x+40,  y+1*35,Bmp_wd,      WHITE,BLACK);  //

    LCD_DrawImage1BPP(x,     y+2*35,Bmp_dj,      WHITE,BLACK);  //
    LCD_DrawImage1BPP(x+40,  y+2*35,Bmp_kzq,     WHITE,BLACK);  //
    LCD_DrawImage1BPP(x+96,  y+2*35,Bmp_wd,      WHITE,BLACK);  //
   
    LCD_DrawImage1BPP(x,     y+3*35,Bmp_js,      WHITE,BLACK);  //加速踏板
    LCD_DrawImage1BPP(x+40,  y+3*35,Bmp_tb,      WHITE,BLACK);   
    
    LCD_DrawImage1BPP(x,     y+4*35,Bmp_zd,      WHITE,BLACK);  //制动踏板
    LCD_DrawImage1BPP(x+40,  y+4*35,Bmp_tb,      WHITE,BLACK);  

    LCD_DrawImage1BPP(x,     y+5*35,Bmp_XHang,   WHITE,BLACK);  //续航
    LCD_DrawImage1BPP(x+40,  y+5*35,Bmp_LCheng,  WHITE,BLACK);  
  
    LCD_DrawImage1BPP(x,     y+6*35,Bmp_ZXiang,  WHITE,BLACK);//转向
    LCD_DrawImage1BPP(x+40,  y+6*35,Bmp_ZLi,     WHITE,BLACK);//助力
    LCD_DrawImage1BPP(x+80,  y+6*35,Bmp_Beng,    WHITE,BLACK);//泵
    
    LCD_DrawImage1BPP(x,     y+7*35,Bmp_Qi,      WHITE,BLACK);//气
    LCD_DrawImage1BPP(x+20,  y+7*35,Bmp_Beng,    WHITE,BLACK);//泵
    
    LCD_DrawImage1BPP(x,     y+8*35,Bmp_DCDC,    WHITE,BLACK);//DCDC
    LCD_DrawImage1BPP(x+24,  y+8*35,Bmp_DCDC,    WHITE,BLACK);//DCDC
    
    LCD_DrawImage1BPP(x,     y+9*35,Bmp_kt,      WHITE,BLACK);//DCDC
    
x=x+196+3;
    LCD_DrawImage1BPP(x,     y+6*35,Bmp_fs,      WHITE,BLACK);//风扇

    LCD_DrawImage1BPP(x,     y+7*35,Bmp_Water,   WHITE,BLACK);//水
    LCD_DrawImage1BPP(x+20,  y+7*35,Bmp_Beng,    WHITE,BLACK);//泵
    
    LCD_DrawImage1BPP(x,     y+8*35,Bmp_Jia,     WHITE,BLACK);//加热
    LCD_DrawImage1BPP(x+20,  y+8*35,Bmp_Re,      WHITE,BLACK);//
    
    LCD_DrawImage1BPP(x,     y+9*35,Bmp_CShuang, WHITE,BLACK);//除霜
       
    
x=463-58;
x=x+338; 
    LCD_DrawImage1BPP(x,     y+0*35,  Bmp_V,    WHITE,BLACK);   
    LCD_DrawImage1BPP(x,     y+1*35,  Bmp_deg,  WHITE,BLACK);   
    LCD_DrawImage1BPP(x,     y+2*35,  Bmp_deg,  WHITE,BLACK);   
    LCD_DrawImage1BPP(x,     y+3*35,  Bmp_bfh,  WHITE,BLACK);   
    LCD_DrawImage1BPP(x,     y+4*35,  Bmp_bfh,  WHITE,BLACK);   
    LCD_DrawImage1BPP(x,     y+5*35,  Bmp_Km,   WHITE,BLACK); 
}

void ControlUpdate(void) {
    unsigned int i=0,j=0,temp=1000;
  
//////////////////////第一列////////////////////
x=305-32;y=84-9;
    
//互锁状态
temp=(VCU_Status[0]&0x30)>>4;
           if(temp==0)i=0;//没有
     else  if(temp==1)i=1;//充电
     else  if(temp==2)i=2;//后舱门
     else  if(temp==3)i=3;//乘客门
     else             i=0;
     if(i==0){LCD_DrawImage1BPP(x-56,     y+0*35,  Bmp_MYou,    WHITE,BLACK); LCD_DrawRect(x+40-56, y+0*35,16,18,BLACK);            }
     if(i==1){LCD_DrawImage1BPP(x-56,     y+0*35,  Bmp_cdian,   WHITE,BLACK); LCD_DrawRect(x+40-56, y+0*35,16,18,BLACK);            } 
     if(i==2){LCD_DrawImage1BPP(x-56,     y+0*35,  Bmp_hcm,     WHITE,BLACK);                                                       }
     if(i==3){LCD_DrawImage1BPP(x-56,     y+0*35,  Bmp_hcm,     WHITE,BLACK); LCD_DrawImage1BPP(x-56,y+0*35, Bmp_CKe,WHITE,BLACK);  }   
              LCD_DrawImage1BPP(x,        y+0*35,  Bmp_HSuo,    WHITE,BLACK); 
     
//自检状态
temp=(VCU_Status[0]&0x0c)>>2;
           if(temp==0)i=0;//正在
     else  if(temp==1)i=1;//成功
     else  if(temp==2)i=2;//失败
     else             i=0;     
     if(i==0){LCD_DrawImage1BPP(x-56,     y+1*35,  Bmp_ZZai,    WHITE,BLACK); LCD_DrawImage1BPP(x,y+1*35, Bmp_ZJian,WHITE,BLACK);  }        
     if(i==1){LCD_DrawImage1BPP(x-56,     y+1*35,  Bmp_ZJian,   WHITE,BLACK); LCD_DrawImage1BPP(x,y+1*35, Bmp_CGong,WHITE,BLACK);  }      
     if(i==2){LCD_DrawImage1BPP(x-56,     y+1*35,  Bmp_ZJian,   WHITE,BLACK); LCD_DrawImage1BPP(x,y+1*35, Bmp_SBai, WHITE,BLACK);  }    

//VCU故障代码
     print_SZ_2(x,    y+2*35,system_fault,4,0,YELLOW);
//VCU LIFE
     print_SZ_2(x,    y+3*35,controler_LIFE,4,0,YELLOW);
//MCU LIFE   
     print_SZ_2(x,    y+4*35,DJ_fault,4,0,YELLOW);
//自检状态
temp=(DJ_Status[0]&0x03);
           if(temp==0)i=0;//正在
     else  if(temp==1)i=1;//成功
     else  if(temp==2)i=2;//失败
     else             i=0;     
     if(i==0){LCD_DrawImage1BPP(x-56,     y+5*35,  Bmp_ZZai,    WHITE,BLACK); LCD_DrawImage1BPP(x,y+5*35, Bmp_ZJian,WHITE,BLACK);  }        
     if(i==1){LCD_DrawImage1BPP(x-56,     y+5*35,  Bmp_ZJian,   WHITE,BLACK); LCD_DrawImage1BPP(x,y+5*35, Bmp_CGong,WHITE,BLACK);  }      
     if(i==2){LCD_DrawImage1BPP(x-56,     y+5*35,  Bmp_ZJian,   WHITE,BLACK); LCD_DrawImage1BPP(x,y+5*35, Bmp_SBai, WHITE,BLACK);  }    
 

//////////////////////第二列////////////////////
x=698-32;y=84-9;
//驱动变频器母线电压
     print_SZ_2(x,  y+0*35,DJcontroler_voltage,4,0,YELLOW);
//电机温度
     update_deg(x,  y+1*35,DJ_temperature,YELLOW);
//控制器温度
     update_deg(x,  y+2*35,DJcontroler_temperature,YELLOW);
//加速踏板
     print_SZ_2(x,  y+3*35,traction_st[0]*0.4,4,0,YELLOW);
//制动踏板
     print_SZ_2(x,  y+4*35,brake_st[0]*0.4,4,0,YELLOW);
//续航里程
     print_SZ_2(x,  y+5*35,XHLC>>3,4,0,YELLOW);
//电附件使能 
     x=553;
temp=VCU_Status[4]; 
     if(temp&0x01)LCD_DrawImage1BPP(x,y+6*35, Bmp_Open,  GREEN,  BLACK);//转向泵
     else         LCD_DrawImage1BPP(x,y+6*35, Bmp_Close, YELLOW, BLACK);//
     
     if(temp&0x02)LCD_DrawImage1BPP(x,y+7*35, Bmp_Open,  GREEN,  BLACK);//气泵
     else         LCD_DrawImage1BPP(x,y+7*35, Bmp_Close, YELLOW, BLACK);//

     if(temp&0x04)LCD_DrawImage1BPP(x,y+8*35, Bmp_Open,  GREEN,  BLACK);//DCDC
     else         LCD_DrawImage1BPP(x,y+8*35, Bmp_Close, YELLOW, BLACK);//

     if(temp&0x08)LCD_DrawImage1BPP(x,y+9*35, Bmp_Open,  GREEN,  BLACK);//空调
     else         LCD_DrawImage1BPP(x,y+9*35, Bmp_Close, YELLOW, BLACK);//

     x=553+196;
     if(temp&0x10)LCD_DrawImage1BPP(x,y+6*35, Bmp_Open,  GREEN,  BLACK);//风扇
     else         LCD_DrawImage1BPP(x,y+6*35, Bmp_Close, YELLOW, BLACK);//
     
     if(temp&0x20)LCD_DrawImage1BPP(x,y+7*35, Bmp_Open,  GREEN,  BLACK);//水泵
     else         LCD_DrawImage1BPP(x,y+7*35, Bmp_Close, YELLOW, BLACK);//

     if(temp&0x40)LCD_DrawImage1BPP(x,y+8*35, Bmp_Open,  GREEN,  BLACK);//加热
     else         LCD_DrawImage1BPP(x,y+8*35, Bmp_Close, YELLOW, BLACK);//

     if(temp&0x80)LCD_DrawImage1BPP(x,y+9*35, Bmp_Open,  GREEN,  BLACK);//除霜
     else         LCD_DrawImage1BPP(x,y+9*35, Bmp_Close, YELLOW, BLACK);//
 


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
     LCD_DrawImage1BPP(x,    y+0*35,Bmp_js,   WHITE,BLACK);//加速踏板
     LCD_DrawImage1BPP(x+40, y+0*35,Bmp_tb,   WHITE,BLACK);  

     LCD_DrawImage1BPP(x,    y+1*35, Bmp_dj,  WHITE,BLACK);//电机转矩
     LCD_DrawImage1BPP(x+40, y+1*35, Bmp_zj,  WHITE,BLACK);

     LCD_DrawImage1BPP(x,    y+2*35, Bmp_dj,  WHITE,BLACK);//电机转速
     LCD_DrawImage1BPP(x+40, y+2*35, Bmp_zs,  WHITE,BLACK);

     LCD_DrawImage1BPP(x,    y+3*35, Bmp_dj,  WHITE,BLACK);//电机温度
     LCD_DrawImage1BPP(x+40, y+3*35, Bmp_wd,  WHITE,BLACK); 

     LCD_DrawImage1BPP(x,    y+4*35, Bmp_kzq, WHITE,BLACK);//控制器温度
     LCD_DrawImage1BPP(x+56, y+4*35, Bmp_wd,  WHITE,BLACK);    
     
     LCD_DrawImage1BPP(x,    y+5*35, Bmp_bj,  WHITE,BLACK);//报警状态
     LCD_DrawImage1BPP(x+40, y+5*35, Bmp_ZT,  WHITE,BLACK); 
            print_SZ_2(x+80, y+5*35, 1,1,0,WHITE);//
     
     LCD_DrawImage1BPP(x,    y+6*35, Bmp_bj,  WHITE,BLACK);//报警状态
     LCD_DrawImage1BPP(x+40, y+6*35, Bmp_ZT,  WHITE,BLACK); 
            print_SZ_2(x+80, y+6*35, 2,1,0,WHITE);//    
            
x=x+338;//单位符号
     LCD_DrawImage1BPP(x,    y+0*35, Bmp_V,   WHITE, BLACK);
     LCD_DrawImage1BPP(x,    y+1*35, Bmp_Nm,  WHITE, BLACK);
     LCD_DrawImage1BPP(x,    y+2*35, Bmp_RPM, WHITE, BLACK);
     LCD_DrawImage1BPP(x,    y+3*35, Bmp_deg, WHITE, BLACK);
     LCD_DrawImage1BPP(x,    y+4*35, Bmp_deg, WHITE, BLACK);
            
///////////////////////第二列///////////////////////
x=463-58;y=84-9;         
     LCD_DrawImage1BPP(x,    y+0*35, Bmp_dj,   WHITE,BLACK);//电机母线电压
     LCD_DrawImage1BPP(x+40, y+0*35, Bmp_MXian,WHITE,BLACK);
     LCD_DrawImage1BPP(x+80, y+0*35, Bmp_DY,   WHITE,BLACK);           

     LCD_DrawImage1BPP(x,    y+1*35, Bmp_dj,   WHITE,BLACK);//电机相电流
     LCD_DrawImage1BPP(x+40, y+1*35, Bmp_Xiang,WHITE,BLACK);
     LCD_DrawImage1BPP(x+56, y+1*35, Bmp_dl,   WHITE,BLACK);    

     LCD_DrawImage1BPP(x,    y+2*35, Bmp_dj,   WHITE,BLACK);//电机实时功率
     LCD_DrawImage1BPP(x+40, y+2*35, Bmp_SShi, WHITE,BLACK);
     LCD_DrawImage1BPP(x+80, y+2*35, Bmp_GLv,  WHITE,BLACK);        
    
x=x+338;//单位符号
     LCD_DrawImage1BPP(x,    y+0*35, Bmp_V,  WHITE, BLACK);
     LCD_DrawImage1BPP(x,    y+1*35, Bmp_A,  WHITE, BLACK);
     LCD_DrawImage1BPP(x,    y+2*35, Bmp_W,WHITE, BLACK);

}

void DJUpdate(void) {
    unsigned int  s=0,temp=0; 
    unsigned char i=0;
//////////////////////第一列////////////////////
x=305-32;y=84-9;
//加速踏板
      if(traction_st[1]>=1023)temp=500;
else  if(traction_st[1]==0)   temp=0;
else                          temp=(unsigned int)(traction_st[1]*0.4887);
      if(temp<=80) temp=80;
      if(temp>=450)temp=450;
     print_SZ_2(x+16, y+0*35,temp/10,2,1,YELLOW);// 
   //print_SZ_2(x,    y+0*35,traction_st[1],4,0,YELLOW);//
//电机转矩
     print_SZ_2(x,    y+1*35,(DJtorque>>1),4,0,YELLOW);//
//电机转速
     print_SZ_2(x,    y+2*35,DJ_speed,4,0,YELLOW);//
//电机温度
     update_deg(x,    y+3*35,DJ_temperature1,YELLOW);
//控制器温度
     update_deg(x,    y+4*35,DJcontroler_temperature1,YELLOW);    

//报警状态1
temp=DJ_Status[3];
     for(i=0;i<8;i++){     
       LCD_DrawImage1BPP(x-16*i+48,y+5*35,BMP_SZ_3[temp&0x01],YELLOW,BLACK);
       temp>>=1;
      }
//报警状态2
temp=DJ_Status[4];
     for(i=0;i<8;i++){     
       LCD_DrawImage1BPP(x-16*i+48,y+6*35,BMP_SZ_3[temp&0x01],YELLOW,BLACK);
       temp>>=1;
      }
               
//////////////////////第二列////////////////////
x=698-32;y=84-9;
//母线电压
     print_SZ_2(x,    y+0*35,DMC_Voltage,4,0,YELLOW);//
//相电流
temp=DMC_Current>>1;
     if(temp>=1000){
        temp=(temp-1000);s=12;
     }else{
        temp=(1000-temp);s=11;
          }
     if(temp>=1000)temp=999;
     update_dl(x,    y+1*35,temp,3,s,YELLOW);  
//实时功率
     print_SZ_2(x-16, y+2*35,DJ_Power*10,5,0,YELLOW);//
     
    
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

void disp_battery1(void){
     unsigned int i=0;
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

    
   // 清除下页的电池箱数
    LCD_DrawImage1BPP(700-25-120,30,Bmp_DI, BLACK,BLACK);//第
    LCD_DrawImage1BPP(700+25-120,30,Bmp_Box,BLACK,BLACK);//箱
    print_SZ_2(700-8-120,30,10,2,0,BLACK);//电池箱号
///////////////////////第一列///////////////////////  
x=10;y=84-9;
     for(i=0;i<9;i++){
     LCD_DrawImage1BPP(x,    y+i*35,Bmp_dc,   WHITE,BLACK);//电池总电压
     }
     LCD_DrawImage1BPP(x+40, y+0*35,Bmp_zong, WHITE,BLACK);
     LCD_DrawImage1BPP(x+56, y+0*35,Bmp_DY,   WHITE,BLACK);

   //LCD_DrawImage1BPP(x,    y+1*35,Bmp_dc,   WHITE,BLACK);
     LCD_DrawImage1BPP(x+40, y+1*35,Bmp_zong, WHITE,BLACK);//电池总电流
     LCD_DrawImage1BPP(x+56, y+1*35,Bmp_dl,   WHITE,BLACK);

   //LCD_DrawImage1BPP(x,    y+2*35,Bmp_dc,   WHITE,BLACK);
     LCD_DrawImage1BPP(x+40, y+2*35,Bmp_SOC,  WHITE,BLACK);//电池soc

    for(i=3;i<7;i++){
   //LCD_DrawImage1BPP(x,    y+i*35,Bmp_dc,   WHITE,BLACK);
     LCD_DrawImage1BPP(x+40, y+i*35,Bmp_JHeng,WHITE,BLACK);//电池均衡状态1
     LCD_DrawImage1BPP(x+80, y+i*35,Bmp_ZT,   WHITE,BLACK);
            print_SZ_2(x+120,y+i*35, i-2,1,0, WHITE);//
    }
     
   //LCD_DrawImage1BPP(x,    y+7*35,Bmp_dc,   WHITE,BLACK);//电池
     LCD_DrawImage1BPP(x+40, y+7*35,Bmp_bj,   WHITE,BLACK);//报警状态
     LCD_DrawImage1BPP(x+80, y+7*35,Bmp_ZT,   WHITE,BLACK);
            print_SZ_2(x+120,y+7*35, 1,1,0,   WHITE);//
            
   //LCD_DrawImage1BPP(x,    y+8*35,Bmp_dc,   WHITE,BLACK);//电池
     LCD_DrawImage1BPP(x+40, y+8*35,Bmp_bj,   WHITE,BLACK);//报警状态
     LCD_DrawImage1BPP(x+80, y+8*35,Bmp_ZT,   WHITE,BLACK);
            print_SZ_2(x+120,y+8*35, 2,1,0,   WHITE);//
            
   //LCD_DrawImage1BPP(x,    y+9*35,Bmp_jy,   WHITE,BLACK);
   //LCD_DrawImage1BPP(x+40, y+9*35,Bmp_dz,   WHITE,BLACK);
     LCD_DrawImage1BPP(x,    y+9*35,Bmp_ZCheng,   WHITE,BLACK); //总负继电器
     LCD_DrawImage1BPP(x+20, y+9*35,Bmp_fu,       WHITE,BLACK); // 
     LCD_DrawImage1BPP(x+40, y+9*35,Bmp_JDQi,     WHITE,BLACK); //     
            
   //LCD_DrawImage1BPP(x+196,    y+9*35,Bmp_JRe,  WHITE,BLACK); //加热继电器
     LCD_DrawImage1BPP(x+196,    y+9*35,Bmp_ZCheng, WHITE,BLACK); //总正继电器
     LCD_DrawImage1BPP(x+196+20, y+9*35,Bmp_zheng,  WHITE,BLACK); // 
     LCD_DrawImage1BPP(x+196+40, y+9*35,Bmp_JDQi,   WHITE,BLACK); // 
     
x=x+338;//单位符号
     LCD_DrawImage1BPP(x,    y+0*35, Bmp_V,   WHITE,BLACK);
     LCD_DrawImage1BPP(x,    y+1*35, Bmp_A,   WHITE,BLACK);
     LCD_DrawImage1BPP(x,    y+2*35, Bmp_bfh, WHITE,BLACK);  
     for(i=0;i<4;i++){
     LCD_DrawImage1BPP(x,    y+(i+3)*35, Bmp_DI,  WHITE,BLACK);//第
     LCD_DrawImage1BPP(x+32, y+(i+3)*35, Bmp_Box, WHITE,BLACK);//箱         
     }
   //LCD_DrawImage1BPP(x,    y+9*35, Bmp_K,   WHITE,BLACK);
   //LCD_DrawImage1BPP(x+16, y+9*35, Bmp_R,   WHITE,BLACK);
                
///////////////////////第二列///////////////////////
x=463-58;y=84-9;
     for(i=0;i<4;i++){
     LCD_DrawImage1BPP(x,    y+i*35,Bmp_dc,   WHITE,BLACK);         
     }
   //LCD_DrawImage1BPP(x,    y+0*35,Bmp_dc,   WHITE,BLACK);
     LCD_DrawImage1BPP(x+40, y+0*35,Bmp_YXu,  WHITE,BLACK);//电池允许充电电流     
     LCD_DrawImage1BPP(x+80, y+0*35,Bmp_cdian,WHITE,BLACK);
     LCD_DrawImage1BPP(x+120,y+0*35,Bmp_dl,   WHITE,BLACK);
     
   //LCD_DrawImage1BPP(x,    y+1*35,Bmp_dc,   WHITE,BLACK);
     LCD_DrawImage1BPP(x+40, y+1*35,Bmp_YXu,  WHITE,BLACK);//电池允许放电电流     
     LCD_DrawImage1BPP(x+80, y+1*35,Bmp_fd,   WHITE,BLACK);
     LCD_DrawImage1BPP(x+120,y+1*35,Bmp_dl,   WHITE,BLACK); 

   //LCD_DrawImage1BPP(x,    y+2*35,Bmp_dc,   WHITE,BLACK);
     LCD_DrawImage1BPP(x+40, y+2*35,Bmp_dt,   WHITE,BLACK);//电池单体数量   
     LCD_DrawImage1BPP(x+80, y+2*35,Bmp_Sum,  WHITE,BLACK); 
     
   //LCD_DrawImage1BPP(x,    y+3*35,Bmp_dc,   WHITE,BLACK);
     LCD_DrawImage1BPP(x+40, y+3*35,Bmp_wd,   WHITE,BLACK);//电池温度数量   
     LCD_DrawImage1BPP(x+80, y+3*35,Bmp_Sum,  WHITE,BLACK); 
     
     for(i=4;i<8;i++){
     LCD_DrawImage1BPP(x,    y+i*35,Bmp_dt,   WHITE,BLACK);         
     }
   //LCD_DrawImage1BPP(x,    y+4*35,Bmp_dt,   WHITE,BLACK);
     LCD_DrawImage1BPP(x+40, y+4*35,Bmp_zg,   WHITE,BLACK);//单体最高电压
     //LCD_DrawImage1BPP(x+40, y+4*35, Bmp_Zui, WHITE, BLACK);//
     //LCD_DrawImage1BPP(x+60, y+4*35, Bmp_Gao, WHITE, BLACK);//
     LCD_DrawImage1BPP(x+80, y+4*35,Bmp_DY,   WHITE,BLACK);

   //LCD_DrawImage1BPP(x,    y+5*35,Bmp_dt,   WHITE,BLACK);
     LCD_DrawImage1BPP(x+40, y+5*35,Bmp_zdi,  WHITE,BLACK);//单体最低电压
     LCD_DrawImage1BPP(x+80, y+5*35,Bmp_DY,   WHITE,BLACK);
     
   //LCD_DrawImage1BPP(x,    y+6*35,Bmp_dt,   WHITE,BLACK);
     LCD_DrawImage1BPP(x+40, y+6*35,Bmp_zg,   WHITE,BLACK);//单体最高温度
     //LCD_DrawImage1BPP(x+40, y+6*35, Bmp_Zui, WHITE, BLACK);//
     //LCD_DrawImage1BPP(x+60, y+6*35, Bmp_Gao, WHITE, BLACK);//
     LCD_DrawImage1BPP(x+80, y+6*35,Bmp_wd,   WHITE,BLACK);

   //LCD_DrawImage1BPP(x,    y+7*35,Bmp_dt,   WHITE,BLACK);
     LCD_DrawImage1BPP(x+40, y+7*35,Bmp_zdi,  WHITE,BLACK);//单体最低温度
     LCD_DrawImage1BPP(x+80, y+7*35,Bmp_wd,   WHITE,BLACK);
     
     for(i=8;i<10;i++){
     LCD_DrawImage1BPP(x,    y+i*35,Bmp_dt,   WHITE,BLACK);
     LCD_DrawImage1BPP(x+40,    y+i*35,Bmp_DY,   WHITE,BLACK);//单体电压最高允许
     if(i==8)LCD_DrawImage1BPP(x+80, y+i*35,Bmp_zg,   WHITE,BLACK);//最高
     else    LCD_DrawImage1BPP(x+80, y+i*35,Bmp_zdi,  WHITE,BLACK);//最低
     LCD_DrawImage1BPP(x+120, y+i*35,Bmp_YXu,   WHITE,BLACK);
     }
     
     //LCD_DrawImage1BPP(x,    y+8*35,Bmp_zg,   WHITE,BLACK);//最高电压位置
     //LCD_DrawImage1BPP(x,    y+8*35, Bmp_Zui, WHITE, BLACK);//
     //LCD_DrawImage1BPP(x+20, y+8*35, Bmp_Gao, WHITE, BLACK);//
     //LCD_DrawImage1BPP(x+40, y+8*35,Bmp_DY,   WHITE,BLACK);
     //LCD_DrawImage1BPP(x+80, y+8*35,Bmp_WZhi, WHITE,BLACK);

     //LCD_DrawImage1BPP(x,    y+9*35,Bmp_zdi, WHITE,BLACK);//最低电压位置
     //LCD_DrawImage1BPP(x+40, y+9*35,Bmp_DY,  WHITE,BLACK);
     //LCD_DrawImage1BPP(x+80, y+9*35,Bmp_WZhi,WHITE,BLACK);
     
     x=x+196;
     //LCD_DrawImage1BPP(x,    y+8*35,Bmp_zg,   WHITE,BLACK);//最高温度位置
     //LCD_DrawImage1BPP(x,    y+8*35,Bmp_Zui,  WHITE, BLACK);//
     //LCD_DrawImage1BPP(x+20, y+8*35,Bmp_Gao,  WHITE, BLACK);//
     //LCD_DrawImage1BPP(x+40, y+8*35,Bmp_wd,   WHITE,BLACK);
     //LCD_DrawImage1BPP(x+80, y+8*35,Bmp_WZhi, WHITE,BLACK);

     //LCD_DrawImage1BPP(x,    y+9*35,Bmp_zdi, WHITE,BLACK);//最低温度位置
     //LCD_DrawImage1BPP(x+40, y+9*35,Bmp_wd,  WHITE,BLACK);
     //LCD_DrawImage1BPP(x+80, y+9*35,Bmp_WZhi,WHITE,BLACK);
         
x=463-58;   
x=x+338;//单位符号
     LCD_DrawImage1BPP(x,    y+0*35,Bmp_A,    WHITE,BLACK);
     LCD_DrawImage1BPP(x,    y+1*35,Bmp_A,    WHITE,BLACK);
     LCD_DrawImage1BPP(x-114,y+4*35,Bmp_V,    WHITE,BLACK);
     LCD_DrawImage1BPP(x-114,y+5*35,Bmp_V,    WHITE,BLACK); 
     LCD_DrawImage1BPP(x-114,y+6*35,Bmp_deg,  WHITE,BLACK); 
     LCD_DrawImage1BPP(x-114,y+7*35,Bmp_deg,  WHITE,BLACK); 
     LCD_DrawImage1BPP(x-114,y+8*35,Bmp_V,    WHITE,BLACK);
     LCD_DrawImage1BPP(x-114,y+9*35,Bmp_V,    WHITE,BLACK);
     for(i=4;i<8;i++){
     LCD_DrawImage1BPP(x-43,y+i*35,Bmp_Box,   WHITE,BLACK); 
     LCD_DrawImage1BPP(x+27,y+i*35,Bmp_Num,   WHITE,BLACK); 
     }
   
}

void disp_battery2(void ){
     unsigned int i=0,j=0,k=0;
x=7;y=68;
   for(i=0;i<11;i++){
   LCD_DrawRect(x,y+i*35,786, 1,GRAY);//-
   }
   LCD_DrawRect(x,y,1, 350,GRAY);//|左
x=66;
   LCD_DrawRect(x,y,1, 350,GRAY);//|中1
x=172;
   LCD_DrawRect(x,y,1, 350,GRAY);//|中2
x=278;
   LCD_DrawRect(x,y,1, 350,GRAY);//|中3
x=384;
   LCD_DrawRect(x,y,1, 350,GRAY);//|中
x=490;
   LCD_DrawRect(x,y,1, 350,GRAY);//|中4
x=597;
   LCD_DrawRect(x,y,1, 350,GRAY);//|中5
x=656;
   LCD_DrawRect(x,y,1, 350,GRAY);//|中6
x=793;
   LCD_DrawRect(x,y,1, 350,GRAY);//|右

    LCD_DrawImage1BPP(700-25-120,30,Bmp_DI, GREEN,BLACK);//第
    LCD_DrawImage1BPP(700+25-120,30,Bmp_Box,GREEN,BLACK);//箱
///////////////////////第一列///////////////////////
x=36-18;y=84-9;
    //LCD_DrawImage1BPP(x,    y+0*35,  Bmp_Bian,   WHITE,BLACK);//编
    //LCD_DrawImage1BPP(x+20, y+0*35,  Bmp_Num,    WHITE,BLACK);//号
    
    //LCD_DrawImage1BPP(x+197,y+0*35,  Bmp_Bian,   WHITE,BLACK);//编
    //LCD_DrawImage1BPP(x+217,y+0*35,  Bmp_Num,    WHITE,BLACK);//号
    
x=136-18;
    //LCD_DrawImage1BPP(x,    y+0*35,  Bmp_DY,     WHITE,BLACK);//电压
    //LCD_DrawImage1BPP(x+197,y+0*35,  Bmp_DY,     WHITE,BLACK);//电压

///////////////////////第二列///////////////////////
x=36-18+393;
  //LCD_DrawImage1BPP(x,    y+0*35,  Bmp_Box,   WHITE,BLACK);//箱
    //LCD_DrawImage1BPP(x,    y+0*35,  Bmp_Bian,  WHITE,BLACK);//编
    //LCD_DrawImage1BPP(x+20, y+0*35,  Bmp_Num,   WHITE,BLACK);//号
    
    //LCD_DrawImage1BPP(x+197,y+0*35,  Bmp_Box,   WHITE,BLACK);//箱
    //LCD_DrawImage1BPP(x+217,y+0*35,  Bmp_Num,   WHITE,BLACK);//号
    
x=136-18+393;
    //LCD_DrawImage1BPP(x,    y+0*35,  Bmp_DY,     WHITE,BLACK);//电压
    //LCD_DrawImage1BPP(x+197,y+0*35,  Bmp_wd,     WHITE,BLACK);//温度

///////////////////////第一列///////////////////////
x=180-8;
//for(j=0;j<3;j++){
//  for(i=0;i<9;i++){
//      LCD_DrawImage1BPP(x+j*197, y+(i+1)*35,Bmp_V, WHITE,BLACK);//V
//     }
//  }
///////////////////////第二列///////////////////////
x=564-8;
  //for(i=0;i<9;i++){
  //    LCD_DrawImage1BPP(x+1*197, y+(i+1)*35,Bmp_deg,WHITE,BLACK);//
  //   }

///////////////////////第一列///////////////////////
x=36-16;
//for(j=0;j<3;j++){
  for(i=0;i<10;i++){
      print_SZ_2(x+0*197, y+(i)*35,(k+1),2,0,YELLOW);
      k=k+5;
     }   
//  }
///////////////////////第二列///////////////////////
x=36-16+393;
k=0;
//for(j=0;j<2;j++){
  for(i=0;i<10;i++){
      print_SZ_2(x+1*197, y+(i)*35,(k+1),2,0,YELLOW);
      k++;
     }   
//  }


}
void update_battery1(void){
     unsigned int temp=0,j,i;
     static unsigned char s=5;
//////////////////////第一列////////////////////
x=305-32;y=84-9;
//电池总电压
     print_SZ_2(x,    y+0*35,DC_voltage/10,4,0,YELLOW);
//电池总电流
temp=DC_current/10;
     if(temp>=500){
        temp=(temp-500);j=12;
     }else{
        temp=(500-temp);j=11;
     }
     if(temp>=500)temp=500;
     update_dl(x,    y+1*35,temp,3,j,YELLOW);
//SOC
     print_SZ_2(x,   y+2*35,DC_SOC,4,0,YELLOW);

//电池均衡状态
     
if(F7s){F7s=0; 

    if(s>=(BMU_NUM-1))s=0;else s++;

    for(j=0;j<4;j++){  
        print_SZ_2(356-6+14,   y+(j+3)*35,s+1,1,0,YELLOW);
        temp=DC_JH_Status[s][j];
     for(i=0;i<8;i++){     
       LCD_DrawImage1BPP(x-16*i+48,y+(j+3)*35,BMP_SZ_3[temp&0x01],YELLOW,BLACK);
       temp>>=1;
      }
    }

}

//电池报警状态1
temp=DC_Status[0];
     for(i=0;i<8;i++){     
       LCD_DrawImage1BPP(x-16*i+48,y+7*35,BMP_SZ_3[temp&0x01],YELLOW,BLACK);
       temp>>=1;
      }
//电池报警状态2
temp=DC_Status[1];
     for(i=0;i<8;i++){     
       LCD_DrawImage1BPP(x-16*i+48,y+8*35,BMP_SZ_3[temp&0x01],YELLOW,BLACK);
       temp>>=1;
      }
//绝缘电阻     
   //print_SZ_2(x-16,    y+9*35,DC_JY[0],5,0,YELLOW);
//总负继电器
    if(DC_Status[3]&0x01)LCD_DrawImage1BPP(158-18,    y+9*35,  Bmp_BHe,     GREEN,BLACK);//闭合
    else                 LCD_DrawImage1BPP(158-18,    y+9*35,  Bmp_DKai,    YELLOW,BLACK);//断开
//总正继电器
    if(DC_Status[3]&0x04)LCD_DrawImage1BPP(158-18+196,    y+9*35,  Bmp_BHe,     GREEN,BLACK);//闭合
    else                 LCD_DrawImage1BPP(158-18+196,    y+9*35,  Bmp_DKai,    YELLOW,BLACK);//断开

//加热继电器
  //if(DC_Status[3]&0x02)LCD_DrawImage1BPP(158-18+196,    y+9*35,  Bmp_BHe,     GREEN,BLACK);//闭合
  //else                 LCD_DrawImage1BPP(158-18+196,    y+9*35,  Bmp_DKai,    YELLOW,BLACK);//断开


//////////////////////第二列////////////////////
x=698-32;y=84-9; 
//充电电流
temp=CD_current<<1;
     if(temp>=1000){
        temp=(temp-1000);j=12;
     }else{
        temp=(1000-temp);j=11;
     }
     if(temp>=1000)temp=999;
     update_dl(x,    y+0*35,temp,3,j,YELLOW);
//放电电流
     print_SZ_2(x,   y+1*35,FD_current<<1,4,0,YELLOW);
//单体数量
     print_SZ_2(x,   y+2*35,DC_DT_sum,4,0,YELLOW);
//温度数量
     print_SZ_2(x,   y+3*35,DC_TEMP_sum,4,0,YELLOW);
     

     x=583-40;
//最高电压     
     print_SZ_2(x,   y+4*35,Vmax,4,3,YELLOW);
//最低电压     
     print_SZ_2(x,   y+5*35,Vmin,4,3,YELLOW);
//最高温度
     update_deg(x+16,y+6*35,Tmax,YELLOW);
//最低温度
     update_deg(x+16,y+7*35,Tmin,YELLOW);
     
     x=672-24;
//最高电压箱号
     print_SZ_2(x,   y+4*35,Vmax_box,3,0,YELLOW);
//最低电压箱号
     print_SZ_2(x,   y+5*35,Vmin_box,3,0,YELLOW);
//最高温度箱号
     print_SZ_2(x,   y+6*35,Tmax_box,3,0,YELLOW);
//最低温度箱号
     print_SZ_2(x,   y+7*35,Tmin_box,3,0,YELLOW);
     
     x=743-24;
//最高电压位置
     print_SZ_2(x,   y+4*35,Vmax_num[1],3,0,YELLOW);
//最低电压位置
     print_SZ_2(x,   y+5*35,Vmin_num[1],3,0,YELLOW);
//最高温度位置       
     print_SZ_2(x,   y+6*35,Tmax_num[1],3,0,YELLOW);
//最低温度位置   
     print_SZ_2(x,   y+7*35,Tmin_num[1],3,0,YELLOW);
     
     x=583-40;
//单体电压最高允许   
     print_SZ_2(x+32,   y+8*35,37,2,1,YELLOW);
//单体电压最低允许   
     print_SZ_2(x+32,   y+9*35,25,2,1,YELLOW);
    
//最高电压位置   
     //print_SZ_2(x,   y+8*35,Vmax_num[0],3,0,YELLOW);
//最低电压位置   
     //print_SZ_2(x,   y+9*35,Vmin_num[0],3,0,YELLOW);
     
     x=760-24;
//最高温度位置   
     //print_SZ_2(x,   y+8*35,Tmax_num[0],3,0,YELLOW);
//最低温度位置   
     //print_SZ_2(x,   y+9*35,Tmin_num[0],3,0,YELLOW);

     
}
void update_battery2(unsigned char ID ){
     unsigned int  j=0,i=0,s=0; 
     unsigned char color=0,color1=0;
     unsigned int  temp=0;
     
   //print_SZ_2(700-8-120,30,ID,2,0,WHITE);//电池箱号
     print_SZ_2(700-120,30,ID,1,0,WHITE);//电池箱号   
//////////////////////第一列////////////////////
    for(j=0;j<10;j++){
        for(i=0;i<5;i++){   
            temp=Battery_Voltage[ID-1][j*5+i];
            
            if(temp==0xffff)color=BLACK;
            else            color=WHITE;

            s=j*5+i;
            if( (s>=50)||(s>=Battery_Voltage_Sum[ID-1]) )break;
            
            x=110-40;          
            print_SZ_2(x+i*106,y+(j)*35,temp,4,3,color);  // 显示电池电压
            x=161-8;
            LCD_DrawImage1BPP(x+i*106, y+(j)*35,Bmp_V, color,BLACK);//V
        }
    }  
     
        for(i=0;i<10;i++){ 
            temp=DC_Temp[ID-1][i]; //
            if(temp==0xff) color=BLACK;
            else           color=WHITE;
            if( i>=Battery_Temp_Sum[ID-1] )break;
            x=518-32;
            update_deg(x+1*197,y+(i)*35,temp,color);  // 显示电池温度
            x=564-8;
            LCD_DrawImage1BPP(x+1*197, y+(i)*35,Bmp_deg,color,BLACK);//
        }
       
}

void BMSFrame(unsigned char ID){
  LCD_DrawRect(0,60,800,365,BLACK);
     //显示标题栏
  LCD_DrawImage1BPP(700-25,30,Bmp_DI,GREEN,BLACK);//第
  LCD_DrawImage1BPP(700+25,30,Bmp_YE,GREEN,BLACK);//页
  
//print_SZ_2(700-8,30,ID+1,2,0,WHITE);//页面编号
  print_SZ_2(700,30,ID+1,1,0,WHITE);//页面编号
  
  if(ID==0)     disp_battery1();
  else          disp_battery2();  
}

void BMSUpdate(unsigned char ID){   
  if(ID==0)     update_battery1();
  else          update_battery2(ID);
}

void frmBMS(void) {
    static unsigned char ID=1;
    if (f_index == 0) { //只更新一次
        f_index = 1;
        key_up=1;
        ID=12;
      //LCD_DrawRect(0,60,800,365,BLACK);
        LCD_DrawImage1BPP(340,30,    BMP_DC,      GREEN, BLACK); //电池
        LCD_DrawImage1BPP(340+40,30, BMP_STSTEM,  GREEN, BLACK); //系统
        LCD_DrawImage1BPP(340+80,30, BMP_Message, GREEN, BLACK); //信息
    } else if (f_index == 1) {
        f_index = 1;
        BMSUpdate(ID);
    } else {
        f_index = 0;
    }
  
    if(key_up){
       if(ID>=(BMU_NUM)) ID=0;
       else              ID++;
    }
    
    if(key_AV){
       if(ID>0)  ID--;
       else      ID=(BMU_NUM);
    }

    if(key_AV||key_up){
       key_up=0;
       key_AV=0;    
       BMSFrame(ID);
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

/******************************************************/
void disp_Fuzhu1(void) {
     unsigned char i = 0;
x=7;y=68;
   for(i=0;i<11;i++){
    LCD_DrawRect(x,y+i*35,786, 1,GRAY);//-
   }
    LCD_DrawRect(x,y,1, 350,GRAY);//|左
x=269;
   //LCD_DrawRect(x,y,1, 350,GRAY);//|中1
x=400;
    //LCD_DrawRect(x,y,1, 350,GRAY);//|中
    LCD_DrawRect(x,y+35,  1,105,GRAY);//|中
    LCD_DrawRect(x,y+35*6,1,105,GRAY);//|中
x=531;
   //LCD_DrawRect(x,y,1, 350,GRAY);//|中2
x=793;
    LCD_DrawRect(x,y,1, 350,GRAY);//|右

///////////////////////第一列///////////////////////  
x=400-48;y=84-9;
    LCD_DrawImage1BPP(x,     y+0*35,Bmp_ZXiang,       WHITE,BLACK);//转向
    LCD_DrawImage1BPP(x+40,  y+0*35,Bmp_ZLi,          WHITE,BLACK);//助力
    LCD_DrawImage1BPP(x+80,  y+0*35,Bmp_Beng,         WHITE,BLACK);//泵
    
x=10;
    LCD_DrawImage1BPP(x,     y+1*35,Bmp_dj,          WHITE,BLACK);//电机转速
    LCD_DrawImage1BPP(x+40,  y+1*35,Bmp_zs,          WHITE,BLACK);//

    LCD_DrawImage1BPP(x,     y+2*35,Bmp_sc,          WHITE,BLACK);//输出相电流
    LCD_DrawImage1BPP(x+40,  y+2*35,Bmp_Xiang,       WHITE,BLACK);//
    LCD_DrawImage1BPP(x+56,  y+2*35,Bmp_dl,          WHITE,BLACK);//

    LCD_DrawImage1BPP(x,     y+3*35,Bmp_work,        WHITE,BLACK);//工作状态
    LCD_DrawImage1BPP(x+40,  y+3*35,Bmp_ZT,          WHITE,BLACK);//
    
    LCD_DrawImage1BPP(x,     y+4*35,Bmp_ST[0],       WHITE,BLACK);//故障代码
    LCD_DrawImage1BPP(x+40,  y+4*35,Bmp_DMa,         WHITE,BLACK);//
    
    
x=400-48;y=84-9;
    LCD_DrawImage1BPP(x,     y+5*35,Bmp_KYJi,        WHITE,BLACK);//空压机
    LCD_DrawImage1BPP(x+58,  y+5*35,Bmp_Qi,          WHITE,BLACK);//气
    LCD_DrawImage1BPP(x+80,  y+5*35,Bmp_Beng,        WHITE,BLACK);//泵
    
x=10;
    LCD_DrawImage1BPP(x,     y+6*35,Bmp_dj,          WHITE,BLACK);//电机转速
    LCD_DrawImage1BPP(x+40,  y+6*35,Bmp_zs,          WHITE,BLACK);//

    LCD_DrawImage1BPP(x,     y+7*35,Bmp_sc,          WHITE,BLACK);//输出相电流
    LCD_DrawImage1BPP(x+40,  y+7*35,Bmp_Xiang,       WHITE,BLACK);//
    LCD_DrawImage1BPP(x+56,  y+7*35,Bmp_dl,          WHITE,BLACK);//

    LCD_DrawImage1BPP(x,     y+8*35,Bmp_work,        WHITE,BLACK);//工作状态
    LCD_DrawImage1BPP(x+40,  y+8*35,Bmp_ZT,          WHITE,BLACK);//
    
    LCD_DrawImage1BPP(x,     y+9*35,Bmp_ST[0],       WHITE,BLACK);//故障代码
    LCD_DrawImage1BPP(x+40,  y+9*35,Bmp_DMa,         WHITE,BLACK);//
     

x=x+338;//单位符号
    LCD_DrawImage1BPP(x,     y+1*35, Bmp_RPM,WHITE,BLACK);
    LCD_DrawImage1BPP(x,     y+2*35, Bmp_A,  WHITE,BLACK);
    
    LCD_DrawImage1BPP(x,     y+6*35, Bmp_RPM,WHITE,BLACK);
    LCD_DrawImage1BPP(x,     y+7*35, Bmp_A,  WHITE,BLACK);
///////////////////////第二列///////////////////////
x=463-58;y=84-9; 
    LCD_DrawImage1BPP(x,     y+1*35,Bmp_kzq,       WHITE,BLACK);//控制器温度
    LCD_DrawImage1BPP(x+56,  y+1*35,Bmp_wd,        WHITE,BLACK);//

    LCD_DrawImage1BPP(x+18,  y+2*35,Bmp_life,      WHITE,BLACK);//
    LCD_DrawImage1BPP(x,     y+2*35,Bmp_kzq,       WHITE,BLACK);//控制器LIFE

    LCD_DrawImage1BPP(x,     y+6*35,Bmp_kzq,       WHITE,BLACK);//控制器温度
    LCD_DrawImage1BPP(x+56,  y+6*35,Bmp_wd,        WHITE,BLACK);//

    LCD_DrawImage1BPP(x+18,  y+7*35,Bmp_life,      WHITE,BLACK);//
    LCD_DrawImage1BPP(x,     y+7*35,Bmp_kzq,       WHITE,BLACK);//控制器LIFE

    
x=x+338;//单位符号   
    LCD_DrawImage1BPP(x,     y+1*35, Bmp_deg,  WHITE,BLACK);   
    LCD_DrawImage1BPP(x,     y+6*35, Bmp_deg,  WHITE,BLACK);  
    
}

void update_Fuzhu1(void) {
  unsigned int i=0,j=0,temp=1000;
  unsigned char color=0,color1=0;
//////////////////////第一列////////////////////
x=305-32;y=84-9;
//////////////////////转向助力泵////////////////
//电机转速
     print_SZ_2(x,     y+1*35,DCAC_speed[0],4,0,YELLOW);
//输出相电流
     print_SZ_2(x,     y+2*35,DCAC_current[0]*0.2,4,0,YELLOW);
//工作状态
     x=137-19;
temp=DCAC_Status[0]&0x03;
          if(temp==0){i=0;color=WHITE;}
     else if(temp==1){i=1;color=GREEN;}
     else if(temp==2){i=2;color=RED;  }
     else            {i=0;color=WHITE;}
     for(j=0;j<3;j++){
     if(j==i)color1=color;else color1=GRAY;
     if(j==0)LCD_DrawImage1BPP(x,     y+3*35,Bmp_TZhi,    color1,BLACK);//
     if(j==1)LCD_DrawImage1BPP(x+60,  y+3*35,Bmp_YXing,   color1,BLACK);//
     if(j==2)LCD_DrawImage1BPP(x+120, y+3*35,Bmp_ST[0],   color1,BLACK);//
     }
//故障代码
x=305-32;
temp=DCAC_fault[0];
     for(i=0;i<8;i++){     
       LCD_DrawImage1BPP(x-16*i+48,y+4*35,BMP_SZ_3[temp&0x01],YELLOW,BLACK);
       temp>>=1;
      }
/*
     x=137-19;//输入欠压
     if(temp&0x01)color=RED;else color=GRAY;       
     LCD_DrawImage1BPP(x,     y+4*35,Bmp_sr,    color,BLACK);//
     LCD_DrawImage1BPP(x+40,  y+4*35,Bmp_Qian,  color,BLACK);//
     LCD_DrawImage1BPP(x+56,  y+4*35,Bmp_Ya,    color,BLACK);//
     x=257-38;//母线过压
     if(temp&0x02)color=RED;else color=GRAY; 
     LCD_DrawImage1BPP(x,     y+4*35,Bmp_MXian, color,BLACK);//
     LCD_DrawImage1BPP(x+40,  y+4*35,Bmp_Guo,   color,BLACK);//
     LCD_DrawImage1BPP(x+56,  y+4*35,Bmp_Ya,    color,BLACK);//
     x=388-70;//读写错误
     if(temp&0x04)color=RED;else color=GRAY; 
     LCD_DrawImage1BPP(x,     y+4*35,Bmp_DXCWu, color,BLACK);//     
     x=502-19;//过流 
     if(temp&0x08)color=RED;else color=GRAY; 
     LCD_DrawImage1BPP(x,     y+4*35,Bmp_dl,    color,BLACK);//
     LCD_DrawImage1BPP(x,     y+4*35,Bmp_Guo,   color,BLACK);//
     x=562-19;//过热
     if(temp&0x10)color=RED;else color=GRAY; 
     LCD_DrawImage1BPP(x,     y+4*35,Bmp_Guo,   color,BLACK);//
     LCD_DrawImage1BPP(x+18,  y+4*35,Bmp_Re,    color,BLACK);//
     x=622-19;//过载  
     if(temp&0x20)color=RED;else color=GRAY; 
     LCD_DrawImage1BPP(x,     y+4*35,Bmp_Guo,   color,BLACK);//
     LCD_DrawImage1BPP(x+18,  y+4*35,Bmp_Zai,   color,BLACK);//
     x=682-19;//缺相
     if(temp&0x40)color=RED;else color=GRAY; 
     LCD_DrawImage1BPP(x,     y+4*35,Bmp_Que,   color,BLACK);//
     LCD_DrawImage1BPP(x+18,  y+4*35,Bmp_Xiang, color,BLACK);//
*/ 
//////////////////////空压机气泵////////////////  
x=305-32;
//电机转速
     print_SZ_2(x,     y+6*35,DCAC_speed[1],4,0,YELLOW);
//输出相电流
     print_SZ_2(x,     y+7*35,DCAC_current[1]*0.2,4,0,YELLOW);
//工作状态
     x=137-19;
temp=DCAC_Status[1]&0X03;
          if(temp==0){i=0;color=WHITE;}
     else if(temp==1){i=1;color=GREEN;}
     else if(temp==2){i=2;color=RED;  }
     else            {i=0;color=WHITE;}
     for(j=0;j<3;j++){
     if(j==i)color1=color;else color1=GRAY;
     if(j==0)LCD_DrawImage1BPP(x,     y+8*35,Bmp_TZhi,    color1,BLACK);//
     if(j==1)LCD_DrawImage1BPP(x+60,  y+8*35,Bmp_YXing,   color1,BLACK);//
     if(j==2)LCD_DrawImage1BPP(x+120, y+8*35,Bmp_ST[0],   color1,BLACK);//
     }
//故障代码
x=305-32;
temp=DCAC_fault[1];
     for(i=0;i<8;i++){     
       LCD_DrawImage1BPP(x-16*i+48,y+9*35,BMP_SZ_3[temp&0x01],YELLOW,BLACK);
       temp>>=1;
      }
/*
     x=137-19;//输入欠压
     if(temp&0x01)color=RED;else color=GRAY;       
     LCD_DrawImage1BPP(x,     y+9*35,Bmp_sr,    color,BLACK);//
     LCD_DrawImage1BPP(x+40,  y+9*35,Bmp_Qian,  color,BLACK);//
     LCD_DrawImage1BPP(x+56,  y+9*35,Bmp_Ya,    color,BLACK);//
     x=257-38;//母线过压
     if(temp&0x02)color=RED;else color=GRAY; 
     LCD_DrawImage1BPP(x,     y+9*35,Bmp_MXian, color,BLACK);//
     LCD_DrawImage1BPP(x+40,  y+9*35,Bmp_Guo,   color,BLACK);//
     LCD_DrawImage1BPP(x+56,  y+9*35,Bmp_Ya,    color,BLACK);//
     x=388-70;//读写错误
     if(temp&0x04)color=RED;else color=GRAY; 
     LCD_DrawImage1BPP(x,     y+9*35,Bmp_DXCWu, color,BLACK);//     
     x=502-19;//过流 
     if(temp&0x08)color=RED;else color=GRAY; 
     LCD_DrawImage1BPP(x,     y+9*35,Bmp_dl,    color,BLACK);//
     LCD_DrawImage1BPP(x,     y+9*35,Bmp_Guo,   color,BLACK);//
     x=562-19;//过热
     if(temp&0x10)color=RED;else color=GRAY; 
     LCD_DrawImage1BPP(x,     y+9*35,Bmp_Guo,   color,BLACK);//
     LCD_DrawImage1BPP(x+18,  y+9*35,Bmp_Re,    color,BLACK);//
     x=622-19;//过载  
     if(temp&0x20)color=RED;else color=GRAY; 
     LCD_DrawImage1BPP(x,     y+9*35,Bmp_Guo,   color,BLACK);//
     LCD_DrawImage1BPP(x+18,  y+9*35,Bmp_Zai,   color,BLACK);//
     x=682-19;//缺相
     if(temp&0x40)color=RED;else color=GRAY; 
     LCD_DrawImage1BPP(x,     y+9*35,Bmp_Que,   color,BLACK);//
     LCD_DrawImage1BPP(x+18,  y+9*35,Bmp_Xiang, color,BLACK);//
*/
//////////////////////第二列////////////////////
x=698-32;y=84-9;
//////////////////////转向助力泵////////////////
//控制器温度
     print_SZ_2(x,     y+1*35,DCAC_temp[0],4,0,YELLOW);
//控制器LIFE      
     print_SZ_2(x,     y+2*35,DCAC_life[0],4,0,YELLOW);
//////////////////////空压机气泵////////////////    
//控制器温度
     print_SZ_2(x,     y+6*35,DCAC_temp[1],4,0,YELLOW);
//控制器LIFE     
     print_SZ_2(x,     y+7*35,DCAC_life[1],4,0,YELLOW);
        
}

void disp_Fuzhu2(void){
     unsigned char i = 0;
x=7;y=68;
   for(i=0;i<11;i++){
    LCD_DrawRect(x,y+i*35,786, 1,GRAY);//-
   }
    LCD_DrawRect(x,y,1, 350,GRAY);//|左
x=269;
   //LCD_DrawRect(x,y,1, 350,GRAY);//|中1
x=400;
    //LCD_DrawRect(x,y,1, 350,GRAY);//|中
    LCD_DrawRect(x,y+35,  1,105,GRAY);//|中
    LCD_DrawRect(x,y+35*6,1,105,GRAY);//|中
x=531;
   //LCD_DrawRect(x,y,1, 350,GRAY);//|中2
x=793;
    LCD_DrawRect(x,y,1, 350,GRAY);//|右

///////////////////////第一列///////////////////////  
x=400-20;y=84-9;
    LCD_DrawImage1BPP(x,     y+0*35,Bmp_You,         WHITE,BLACK);//油
    LCD_DrawImage1BPP(x+20,  y+0*35,Bmp_Beng,        WHITE,BLACK);//泵
    
x=10;
    LCD_DrawImage1BPP(x,     y+1*35,Bmp_sc,          WHITE,BLACK);//输出电压
    LCD_DrawImage1BPP(x+40,  y+1*35,Bmp_DY,          WHITE,BLACK);//

    LCD_DrawImage1BPP(x,     y+2*35,Bmp_sc,          WHITE,BLACK);//输出电流
    LCD_DrawImage1BPP(x+40,  y+2*35,Bmp_dl,          WHITE,BLACK);//

    LCD_DrawImage1BPP(x,     y+3*35,Bmp_srq,         WHITE,BLACK);//散热器温度
    LCD_DrawImage1BPP(x+56,  y+3*35,Bmp_wd,          WHITE,BLACK);//
    
    LCD_DrawImage1BPP(x,     y+4*35,Bmp_ST[0],       WHITE,BLACK);//故障代码
    LCD_DrawImage1BPP(x+40,  y+4*35,Bmp_DMa,         WHITE,BLACK);//
    
    
x=400-20;y=84-9;
    LCD_DrawImage1BPP(x,     y+5*35,Bmp_Qi,          WHITE,BLACK);//气
    LCD_DrawImage1BPP(x+20,  y+5*35,Bmp_Beng,        WHITE,BLACK);//泵
    
x=10;
    LCD_DrawImage1BPP(x,     y+6*35,Bmp_sr,          WHITE,BLACK);//输入电压
    LCD_DrawImage1BPP(x+40,  y+6*35,Bmp_DY,          WHITE,BLACK);//

    LCD_DrawImage1BPP(x,     y+7*35,Bmp_sc,          WHITE,BLACK);//输出电流
    LCD_DrawImage1BPP(x+40,  y+7*35,Bmp_dl,          WHITE,BLACK);//

    LCD_DrawImage1BPP(x,     y+8*35,Bmp_srq,         WHITE,BLACK);//散热器温度
    LCD_DrawImage1BPP(x+56,  y+8*35,Bmp_wd,          WHITE,BLACK);//
    
    LCD_DrawImage1BPP(x,     y+9*35,Bmp_ST[0],       WHITE,BLACK);//故障代码
    LCD_DrawImage1BPP(x+40,  y+9*35,Bmp_DMa,         WHITE,BLACK);//
    

x=x+338;//单位符号
    LCD_DrawImage1BPP(x,     y+1*35, Bmp_V,    WHITE,BLACK);
    LCD_DrawImage1BPP(x,     y+2*35, Bmp_A,    WHITE,BLACK);
    LCD_DrawImage1BPP(x,     y+3*35, Bmp_deg,  WHITE,BLACK);
    
    LCD_DrawImage1BPP(x,     y+6*35, Bmp_V,    WHITE,BLACK);
    LCD_DrawImage1BPP(x,     y+7*35, Bmp_A,    WHITE,BLACK);
    LCD_DrawImage1BPP(x,     y+8*35, Bmp_deg,  WHITE,BLACK);
///////////////////////第二列///////////////////////
x=463-58;y=84-9; 
    LCD_DrawImage1BPP(x,     y+6*35,Bmp_sc,          WHITE,BLACK);//输出电压
    LCD_DrawImage1BPP(x+40,  y+6*35,Bmp_DY,          WHITE,BLACK);//

x=x+338;//单位符号   
    LCD_DrawImage1BPP(x,     y+6*35, Bmp_V,WHITE,BLACK);  
    

}
void update_Fuzhu2(void){
  unsigned int i=0,j=0,temp=1000;
  unsigned char color=0,color1=0;
//////////////////////第一列////////////////////
x=305-32;y=84-9;
//////////////////////油泵//////////////////// 
//输出电压
     print_SZ_2(x,     y+1*35,YB_voltage,4,0,YELLOW);
//输出电流
     print_SZ_2(x,     y+2*35,YB_current,4,0,YELLOW);
//散热器温度
     print_SZ_2(x,     y+3*35,YB_temp,4,0,YELLOW);
//故障代码
x=305-32;
temp=YB_fault;  
     for(i=0;i<8;i++){     
       LCD_DrawImage1BPP(x-16*i+48,y+4*35,BMP_SZ_3[temp&0x01],YELLOW,BLACK);
       temp>>=1;
      }
/*
     x=137-19;//输入欠压
     if(temp&0x01)color=RED;else color=GRAY;       
     LCD_DrawImage1BPP(x,     y+4*35,Bmp_sr,    color,BLACK);//
     LCD_DrawImage1BPP(x+40,  y+4*35,Bmp_Qian,  color,BLACK);//
     LCD_DrawImage1BPP(x+56,  y+4*35,Bmp_Ya,    color,BLACK);//
     x=257-38;//输入过压
     if(temp&0x02)color=RED;else color=GRAY; 
     LCD_DrawImage1BPP(x,     y+4*35,Bmp_sr,    color,BLACK);//
     LCD_DrawImage1BPP(x+40,  y+4*35,Bmp_Guo,   color,BLACK);//
     LCD_DrawImage1BPP(x+56,  y+4*35,Bmp_Ya,    color,BLACK);//
     x=388-70;//驱动电源
     if(temp&0x04)color=RED;else color=GRAY; 
     LCD_DrawImage1BPP(x,     y+4*35,Bmp_QDong, color,BLACK);//
     LCD_DrawImage1BPP(x+40,  y+4*35,Bmp_dy,    color,BLACK);//
     x=457-38;//CAN中断 
     if(temp&0x08)color=RED;else color=GRAY; 
     LCD_DrawImage1BPP(x,     y+4*35,Bmp_CAN,   color,BLACK);//
     LCD_DrawImage1BPP(x+32,  y+4*35,Bmp_ZDuan, color,BLACK);//
     x=536-19;//过热
     if(temp&0x10)color=RED;else color=GRAY; 
     LCD_DrawImage1BPP(x,     y+4*35,Bmp_Guo,   color,BLACK);//
     LCD_DrawImage1BPP(x+18,  y+4*35,Bmp_Re,    color,BLACK);//
     x=596-19;//短路  
     if(temp&0x20)color=RED;else color=GRAY; 
     LCD_DrawImage1BPP(x,     y+4*35,Bmp_DLu,   color,BLACK);//
     x=656-19;//过载  
     if(temp&0x40)color=RED;else color=GRAY; 
     LCD_DrawImage1BPP(x,     y+4*35,Bmp_Guo,   color,BLACK);//
     LCD_DrawImage1BPP(x+18,  y+4*35,Bmp_Zai,   color,BLACK);//
     x=716-19;//缺相
     if(temp&0x80)color=RED;else color=GRAY; 
     LCD_DrawImage1BPP(x,     y+4*35,Bmp_Que,   color,BLACK);//
     LCD_DrawImage1BPP(x+18,  y+4*35,Bmp_Xiang, color,BLACK);//
*/

//////////////////////气泵////////////////////
x=305-32;y=84-9;
//输入电压
     print_SZ_2(x,     y+6*35,QB_voltage_IN,4,0,YELLOW);
//输出电流
     print_SZ_2(x,     y+7*35,QB_current,4,0,YELLOW);
//散热器温度
     print_SZ_2(x,     y+8*35,QB_temp,4,0,YELLOW);
//故障代码
x=305-32;
temp=QB_fault;
     for(i=0;i<8;i++){     
       LCD_DrawImage1BPP(x-16*i+48,y+9*35,BMP_SZ_3[temp&0x01],YELLOW,BLACK);
       temp>>=1;
      }
/*
     x=137-19;//输入欠压
     if(temp&0x01)color=RED;else color=GRAY;       
     LCD_DrawImage1BPP(x,     y+9*35,Bmp_sr,    color,BLACK);//
     LCD_DrawImage1BPP(x+40,  y+9*35,Bmp_Qian,  color,BLACK);//
     LCD_DrawImage1BPP(x+56,  y+9*35,Bmp_Ya,    color,BLACK);//
     x=257-38;//输入过压
     if(temp&0x02)color=RED;else color=GRAY; 
     LCD_DrawImage1BPP(x,     y+9*35,Bmp_sr,    color,BLACK);//
     LCD_DrawImage1BPP(x+40,  y+9*35,Bmp_Guo,   color,BLACK);//
     LCD_DrawImage1BPP(x+56,  y+9*35,Bmp_Ya,    color,BLACK);//
     x=388-70;//驱动电源
     if(temp&0x04)color=RED;else color=GRAY; 
     LCD_DrawImage1BPP(x,     y+9*35,Bmp_QDong, color,BLACK);//
     LCD_DrawImage1BPP(x+40,  y+9*35,Bmp_dy,    color,BLACK);//
     x=457-38;//CAN中断 
     if(temp&0x08)color=RED;else color=GRAY; 
     LCD_DrawImage1BPP(x,     y+9*35,Bmp_CAN,   color,BLACK);//
     LCD_DrawImage1BPP(x+32,  y+9*35,Bmp_ZDuan, color,BLACK);//
     x=536-19;//过热
     if(temp&0x10)color=RED;else color=GRAY; 
     LCD_DrawImage1BPP(x,     y+9*35,Bmp_Guo,   color,BLACK);//
     LCD_DrawImage1BPP(x+18,  y+9*35,Bmp_Re,    color,BLACK);//
     x=596-19;//短路  
     if(temp&0x20)color=RED;else color=GRAY; 
     LCD_DrawImage1BPP(x,     y+9*35,Bmp_DLu,   color,BLACK);//
     x=656-19;//过载  
     if(temp&0x40)color=RED;else color=GRAY; 
     LCD_DrawImage1BPP(x,     y+9*35,Bmp_Guo,   color,BLACK);//
     LCD_DrawImage1BPP(x+18,  y+9*35,Bmp_Zai,   color,BLACK);//
     x=716-19;//缺相
     if(temp&0x80)color=RED;else color=GRAY; 
     LCD_DrawImage1BPP(x,     y+9*35,Bmp_Que,   color,BLACK);//
     LCD_DrawImage1BPP(x+18,  y+9*35,Bmp_Xiang, color,BLACK);//
*/  
     
//////////////////////第二列////////////////////
x=698-32;y=84-9;  
//输出电压
     print_SZ_2(x,     y+6*35,QB_voltage_OUT,4,0,YELLOW);

}

void disp_Fuzhu3(void){
     unsigned char i = 0;
x=7;y=68;
   for(i=0;i<11;i++){
    LCD_DrawRect(x,y+i*35,786, 1,GRAY);//-
   }
    LCD_DrawRect(x,y,1, 350,GRAY);//|左
x=269;
   //LCD_DrawRect(x,y,1, 350,GRAY);//|中1
x=400;
    //LCD_DrawRect(x,y,1, 350,GRAY);//|中
    LCD_DrawRect(x,y+35,  1,105,GRAY);//|中
    LCD_DrawRect(x,y+35*6,1,105,GRAY);//|中
x=531;
   //LCD_DrawRect(x,y,1, 350,GRAY);//|中2
x=793;
    LCD_DrawRect(x,y,1, 350,GRAY);//|右

///////////////////////第一列///////////////////////  
x=400-24;y=84-9;
    LCD_DrawImage1BPP(x,     y+0*35,Bmp_DCDC,        WHITE,BLACK);//DCDC
    LCD_DrawImage1BPP(x+24,  y+0*35,Bmp_DCDC,        WHITE,BLACK);//DCDC
x=10;
    LCD_DrawImage1BPP(x,     y+1*35,Bmp_sc,          WHITE,BLACK);//输出电压
    LCD_DrawImage1BPP(x+40,  y+1*35,Bmp_DY,          WHITE,BLACK);//

    LCD_DrawImage1BPP(x,     y+2*35,Bmp_sc,          WHITE,BLACK);//输出电流
    LCD_DrawImage1BPP(x+40,  y+2*35,Bmp_dl,          WHITE,BLACK);//

    LCD_DrawImage1BPP(x,     y+3*35,Bmp_work,        WHITE,BLACK);//工作状态
    LCD_DrawImage1BPP(x+40,  y+3*35,Bmp_ZT,          WHITE,BLACK);//
    
    LCD_DrawImage1BPP(x,     y+4*35,Bmp_ST[0],       WHITE,BLACK);//故障代码
    LCD_DrawImage1BPP(x+40,  y+4*35,Bmp_DMa,         WHITE,BLACK);//
    
    
x=400-48;y=84-9;
    LCD_DrawImage1BPP(x,     y+5*35,Bmp_jy,          WHITE,BLACK);//绝缘检测仪
    LCD_DrawImage1BPP(x+40,  y+5*35,Bmp_JCYi,        WHITE,BLACK);//

    
x=10;
    LCD_DrawImage1BPP(x,     y+6*35,Bmp_DY,          WHITE,BLACK);//高压正对地绝缘电阻
    LCD_DrawImage1BPP(x,     y+6*35,Bmp_Gao,         WHITE,BLACK);//
    LCD_DrawImage1BPP(x+40,  y+6*35,Bmp_zheng,       WHITE,BLACK);//  
    LCD_DrawImage1BPP(x+56,  y+6*35,Bmp_DDi,         WHITE,BLACK);//  
    LCD_DrawImage1BPP(x+96,  y+6*35,Bmp_jy,          WHITE,BLACK);//   
    LCD_DrawImage1BPP(x+136, y+6*35,Bmp_dz,          WHITE,BLACK);//
    
    LCD_DrawImage1BPP(x,     y+7*35,Bmp_DY,          WHITE,BLACK);//高压负对地绝缘电阻
    LCD_DrawImage1BPP(x,     y+7*35,Bmp_Gao,         WHITE,BLACK);//
    LCD_DrawImage1BPP(x+40,  y+7*35,Bmp_fu,          WHITE,BLACK);//  
    LCD_DrawImage1BPP(x+56,  y+7*35,Bmp_DDi,         WHITE,BLACK);//  
    LCD_DrawImage1BPP(x+96,  y+7*35,Bmp_jy,          WHITE,BLACK);//   
    LCD_DrawImage1BPP(x+136, y+7*35,Bmp_dz,          WHITE,BLACK);//  
    
    LCD_DrawImage1BPP(x,     y+8*35,Bmp_ST[0],       WHITE,BLACK);//故障等级
    LCD_DrawImage1BPP(x+40,  y+8*35,Bmp_DJi,         WHITE,BLACK);//
   
    
x=x+338;//单位符号
    LCD_DrawImage1BPP(x,     y+1*35, Bmp_V,    WHITE,BLACK);
    LCD_DrawImage1BPP(x,     y+2*35, Bmp_A,    WHITE,BLACK);
    
    LCD_DrawImage1BPP(x,     y+6*35, Bmp_K,    WHITE,BLACK);LCD_DrawImage1BPP(x+16,     y+6*35, Bmp_R,    WHITE,BLACK);
    LCD_DrawImage1BPP(x,     y+7*35, Bmp_K,    WHITE,BLACK);LCD_DrawImage1BPP(x+16,     y+7*35, Bmp_R,    WHITE,BLACK);
    LCD_DrawImage1BPP(x,     y+8*35,Bmp_JBie,  WHITE,BLACK);//         
         LCD_DrawRect(x+18,  y+8*35,20, 18,BLACK);// 
    
///////////////////////第二列///////////////////////
x=463-58;y=84-9; 
    LCD_DrawImage1BPP(x,     y+6*35,Bmp_life,     WHITE,BLACK);//
    LCD_DrawImage1BPP(x,     y+6*35,Bmp_jy,       WHITE,BLACK);//绝缘LIFE
    
    LCD_DrawImage1BPP(x,     y+7*35,Bmp_LDian,    WHITE,BLACK);//
    LCD_DrawImage1BPP(x+40,  y+7*35,Bmp_bj,       WHITE,BLACK);//漏电报警
    
x=x+338;//单位符号   

  
}
void update_Fuzhu3(void){
  unsigned int i=0,j=0,temp=1000;
  unsigned char color=0;
//////////////////////第一列////////////////////
x=305-32;y=84-9;
//////////////////////油泵//////////////////// 
//输出电压
     print_SZ_2(x,     y+1*35,DCDC_voltage/10,4,0,YELLOW);
//输出电流
     print_SZ_2(x,     y+2*35,DCDC_current/10,4,0,YELLOW);
//工作状态
temp=DCDC_Status&0X03;
     x=137-19;
     if(temp==0)color=WHITE;else color=GRAY;
     LCD_DrawImage1BPP(x,     y+3*35,Bmp_TZhi,    color,BLACK);//

     if(temp==1)color=WHITE;else color=GRAY;
     LCD_DrawImage1BPP(x+60,  y+3*35,Bmp_cdian,   color,BLACK);//

     if(temp==2)color=WHITE;else color=GRAY;
     LCD_DrawImage1BPP(x+120, y+3*35,Bmp_OK,      color,BLACK);//

x=305-32;
//故障代码
temp=DCDC_fault;
     for(i=0;i<8;i++){     
       LCD_DrawImage1BPP(x-16*i+48,y+4*35,BMP_SZ_3[temp&0x01],YELLOW,BLACK);
       temp>>=1;
      }
//正对地绝缘电阻
     print_SZ_2(x-16,     y+6*35,anode_R,5,0,YELLOW);
//负对地绝缘电阻
     print_SZ_2(x-16,     y+7*35,negative_R,5,0,YELLOW);
//故障等级
     if(eror_R>0)color=RED;else color=BLACK;
     print_SZ_2(x+48,     y+8*35,eror_R+1,1,0,color);
    
//////////////////////第二列////////////////////
x=698-32;y=84-9; 
//LIFE
     print_SZ_2(x-16,     y+6*35,JY_life,5,0,YELLOW);
//漏电报警
     if(JY_Status==0x55)color=RED;else color=WHITE;
     LCD_DrawImage1BPP(x,     y+7*35,Bmp_LDian,    color,BLACK);//
     if(JY_Status==0x55)color=BLACK;else color=WHITE;
     LCD_DrawImage1BPP(x-18,  y+7*35,Bmp_Bu,    color,BLACK);//

}


void FuzhuFrame(unsigned char ID){
   LCD_DrawRect(0,60,800,365,BLACK);
   //显示标题栏
   LCD_DrawImage1BPP(700-25,30,Bmp_DI,GREEN,BLACK);//第
   LCD_DrawImage1BPP(700+25,30,Bmp_YE,GREEN,BLACK);//页
   print_SZ_2(700,30,ID+1,1,0,WHITE);//页面编号
   
     switch(ID){
      case 0: disp_Fuzhu1();
      break;
      case 1: disp_Fuzhu2();
      break;
      case 2: disp_Fuzhu3();
      break;
      default:
      break;
  }
 // if(ID==0)     disp_Fuzhu1();
 // else          disp_Fuzhu2();  
}

void FuzhuUpdate(unsigned char ID){ 
     switch(ID){
      case 0: update_Fuzhu1();
      break;
      case 1: update_Fuzhu2();
      break;
      case 2: update_Fuzhu3();
      break;
      default:
      break;
  }
    
  //if(ID==0)     update_Fuzhu1();
  //else          update_Fuzhu2();
}


void frmFuzhu(void) {
    static unsigned char ID=1;
    if (f_index == 0) { //只更新一次
        f_index = 1;
        LCD_DrawRect(0,60,800,365,BLACK);
        LCD_DrawImage1BPP(340,30,    BMP_Fuzhu,   GREEN, BLACK); //辅助
        LCD_DrawImage1BPP(340+40,30, BMP_STSTEM,  GREEN, BLACK); //系统
        LCD_DrawImage1BPP(340+80,30, BMP_Message, GREEN, BLACK); //信息
        //FuzhuFrame();
        key_up=1;
        ID=2;
    } else if (f_index == 1) {
        f_index = 1;
        FuzhuUpdate(ID);
    } else {
        f_index = 0;
    }
    if(key_up){
       if(ID>=2) ID=0;
       else      ID++;
    }
    if(key_AV){
       if(ID>0)  ID--;
       else      ID=2;
    }

    if(key_AV||key_up){
       key_up=0;
       key_AV=0;    
       FuzhuFrame(ID);
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


/******************************************************/
void MHQFrame(void) {
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

    LCD_DrawImage1BPP(x,     y+0*35,Bmp_dc,        WHITE,BLACK);//电池箱号
    LCD_DrawImage1BPP(x+40,  y+0*35,Bmp_Box,       WHITE,BLACK);
    LCD_DrawImage1BPP(x+56,  y+0*35,Bmp_Num,       WHITE,BLACK);   
 
    LCD_DrawImage1BPP(x,     y+1*35,Bmp_YJing,     WHITE,BLACK);//预警
    LCD_DrawImage1BPP(x+40,  y+1*35,Bmp_JBie,      WHITE,BLACK);//级别

    LCD_DrawImage1BPP(x,     y+2*35,Bmp_ST[0],     WHITE,BLACK);//故障
    LCD_DrawImage1BPP(x+40,  y+2*35,Bmp_DJi,       WHITE,BLACK);//等级

    LCD_DrawImage1BPP(x,     y+3*35,Bmp_ST[0],     WHITE,BLACK);//故障
    LCD_DrawImage1BPP(x+40,  y+3*35,Bmp_DMa,       WHITE,BLACK);//代码

    LCD_DrawImage1BPP(x,     y+4*35,Bmp_life,      WHITE,BLACK);//
    LCD_DrawImage1BPP(x,     y+4*35,Bmp_MHQ,       WHITE,BLACK);//LIFE
    
x=x+338;//单位符号
    LCD_DrawImage1BPP(x,     y+1*35,Bmp_JBie,  WHITE,BLACK);//         
         LCD_DrawRect(x+18,  y+1*35,20, 18,BLACK);// 
    LCD_DrawImage1BPP(x,     y+2*35,Bmp_JBie,  WHITE,BLACK);//         
         LCD_DrawRect(x+18,  y+2*35,20, 18,BLACK);// 
///////////////////////第二列///////////////////////
x=463-58;y=84-9; 



x=x+338;//单位符号   



}

void MHQUpdate(void) {
  //unsigned int i=0,j=0,temp=1000;
  
//////////////////////第一列////////////////////
x=305-32;y=84-9;
//电池箱号
    print_SZ_2(x,     y+0*35,MHQ_Number ,4,0,YELLOW);
//预警级别
    print_SZ_2(x,     y+1*35,MHQ_Alarm  ,4,0,YELLOW);
//故障等级
    print_SZ_2(x,     y+2*35,(MHQ_fault&0xc0)>>6,4,0,YELLOW);
//故障代码
    print_SZ_2(x,     y+3*35,(MHQ_fault&0x3f),4,0,YELLOW);
//LIFE
    print_SZ_2(x,     y+4*35,(MHQ_life),4,0,YELLOW);
//////////////////////第二列////////////////////
x=698-32;y=84-9;  

}

void frmMHQ(void) {
    if (f_index == 0) { //只更新一次
        f_index = 1;
        LCD_DrawRect(0,60,800,365,BLACK);
        LCD_DrawImage1BPP(340,30,    Bmp_MHQ,     GREEN, BLACK); //灭火
        LCD_DrawImage1BPP(340+40,30, BMP_STSTEM,  GREEN, BLACK); //系统
        LCD_DrawImage1BPP(340+80,30, BMP_Message, GREEN, BLACK); //信息
        MHQFrame();
    } else if (f_index == 1) {
        f_index = 1;
        MHQUpdate();
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
    Ftemp=30.0*DJ_speed; //车速 
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
     if(new_pluse<29990)new_pluse+=10;
     else               new_pluse=30000;
  }
  if(key_up){
     key_up=0; 
     if(new_pluse>20) new_pluse-=10;
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
                if(Fcan_count>=CAN_TIME){      
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
                if(Rcan_count>=CAN_TIME){
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
                if(Mcan_count>=CAN_TIME){
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
                if(LED16){ //蓄电池电压低                
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
                if(Vspeed>=690){ //您已超速      
                LCD_DrawImage1BPP(x, y, Bmp_nycs,Fcolor,color);
                w=x+80;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                } 
            case 6: 
                al_index=7; 
                //if(1){
                if(VCU_Status[1]&0x04){//VCU通讯故障
                LCD_DrawImage1BPP(x,    y, Bmp_VCU,  Fcolor,color);
                LCD_DrawImage1BPP(x+40, y, Bmp_CANST,Fcolor,color);            
                LCD_DrawImage1BPP(x+112,y, Bmp_ST[2],Fcolor,color);
                w=x+112+40;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                }
            case 7: 
                al_index=8; 
                //if(1){
                if(DJ_Status[1]&0x20){//MCU通讯故障
                LCD_DrawImage1BPP(x,    y, Bmp_MCU,  Fcolor,color);
                LCD_DrawImage1BPP(x+40, y, Bmp_CANST,Fcolor,color);               
                LCD_DrawImage1BPP(x+112,y, Bmp_ST[2],Fcolor,color);
                w=x+112+40;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                } 
            case 8: 
                al_index=9; 
                //if(1){
                if(DJ_Status[1]&0x10){//电机温度报警
                LCD_DrawImage1BPP(x,    y, Bmp_dj,  Fcolor,color);
                LCD_DrawImage1BPP(x+40, y, Bmp_wd,  Fcolor,color);              
                LCD_DrawImage1BPP(x+80, y, Bmp_bj,  Fcolor,color);
                w=x+80+40;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                } 
            case 9: 
                al_index=10; 
                //if(1){
                if(DJ_Status[1]&0x08){//电机控制器温度报警
                LCD_DrawImage1BPP(x,    y, Bmp_dj,  Fcolor,color);
                LCD_DrawImage1BPP(x+40, y, Bmp_kzq, Fcolor,color);
                LCD_DrawImage1BPP(x+96, y, Bmp_wd,  Fcolor,color);              
                LCD_DrawImage1BPP(x+136,y, Bmp_bj,  Fcolor,color);
                w=x+136+40;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                }       
            case 10: 
                al_index=11; 
                //if(1){
                if(DJ_Status[1]&0x04){//电机短路过流报警
                LCD_DrawImage1BPP(x,    y, Bmp_dj,  Fcolor,color);
                LCD_DrawImage1BPP(x+40, y, Bmp_DLu, Fcolor,color);
                LCD_DrawImage1BPP(x+80, y, Bmp_dl,  Fcolor,color);     
                LCD_DrawImage1BPP(x+80, y, Bmp_Guo, Fcolor,color);              
                LCD_DrawImage1BPP(x+120,y, Bmp_bj,  Fcolor,color);
                w=x+120+40;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                }       
            case 11: 
                al_index=12; 
                //if(1){
                if(DJ_Status[1]&0x03){//电机控制器欠压报警
                LCD_DrawImage1BPP(x,    y, Bmp_dj,  Fcolor,color);
                LCD_DrawImage1BPP(x+40, y, Bmp_kzq, Fcolor,color);
                if((DJ_Status[1]&0x03)==0x02)LCD_DrawImage1BPP(x+96, y, Bmp_Qian,Fcolor,color);//欠
                else                         LCD_DrawImage1BPP(x+96, y, Bmp_Guo, Fcolor,color);//过
                LCD_DrawImage1BPP(x+112,y, Bmp_Ya,  Fcolor,color);           
                LCD_DrawImage1BPP(x+128,y, Bmp_bj,  Fcolor,color);
                w=x+128+40;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                }   
            case 12: 
                al_index=13; 
                //if(1){
                if( (DC_Status[0]==1  ) || //电池单体过压 1 级
                    (DC_Status[0]==51 ) || //电池单体过压 2 级   
                    (DC_Status[0]==101) || //电池单体过压 3 级
                        
                    (DC_Status[0]==2  ) || //电池单体欠压 1 级
                    (DC_Status[0]==52 ) || //电池单体欠压 2 级   
                    (DC_Status[0]==102)    //电池单体欠压 3 级       
                  ){ //          
                LCD_DrawImage1BPP(x,    y, Bmp_dc, Fcolor,color);
                LCD_DrawImage1BPP(x+40, y, Bmp_dt, Fcolor,color);
                if( (DC_Status[0]==1  ) || //电池单体过压 1 级
                    (DC_Status[0]==51 ) || //电池单体过压 2 级   
                    (DC_Status[0]==101)    //电池单体过压 3 级
                  )LCD_DrawImage1BPP(x+80, y, Bmp_Guo,Fcolor,color);
           else if( (DC_Status[0]==2  ) || //电池单体欠压 1 级
                    (DC_Status[0]==52 ) || //电池单体欠压 2 级   
                    (DC_Status[0]==102)    //电池单体欠压 3 级  
                  )LCD_DrawImage1BPP(x+80, y, Bmp_Qian,Fcolor,color);
                LCD_DrawImage1BPP(x+96, y, Bmp_Ya, Fcolor,color);   
                LCD_DrawImage1BPP(x+112,y, Bmp_DJi,Fcolor,color);                
                     if((DC_Status[0]==1  )||(DC_Status[0]==2  ))print_SZ_2(x+112+1,y,1,1,0,Fcolor);// 1 
                else if((DC_Status[0]==51 )||(DC_Status[0]==52 ))print_SZ_2(x+112+1,y,2,1,0,Fcolor);// 2
                else if((DC_Status[0]==101)||(DC_Status[0]==102))print_SZ_2(x+112+1,y,3,1,0,Fcolor);// 3   
                w=x+112+40;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                }
            case 13: 
                al_index=14; 
                //if(1){
                if( 
                    (DC_Status[0]==64 ) || //2 级   
                    (DC_Status[0]==114)    //3 级
                  ){ //充电座温度过高 2,3级 
                LCD_DrawImage1BPP(x,    y, Bmp_dc,   Fcolor,color);
                LCD_DrawImage1BPP(x+40, y, Bmp_cdian,Fcolor,color);
                LCD_DrawImage1BPP(x+80, y, Bmp_Zuo,  Fcolor,color);                
                LCD_DrawImage1BPP(x+96, y, Bmp_wd,   Fcolor,color);
                LCD_DrawImage1BPP(x+136,y, Bmp_gg,   Fcolor,color);   
                LCD_DrawImage1BPP(x+176,y, Bmp_DJi,  Fcolor,color);                
                     if(DC_Status[0]==64 )print_SZ_2(x+176+1,y,2,1,0,Fcolor);// 2 
                else if(DC_Status[0]==114)print_SZ_2(x+176+1,y,3,1,0,Fcolor);// 3   
                w=x+176+40;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                }
            case 14: 
                al_index=15; 
                //if(1){
                if( (DC_Status[0]==13 ) || //电池SOC过低 1 级
                    (DC_Status[0]==63 ) || //电池SOC过低 2 级   
                    (DC_Status[0]==113) || //电池SOC过低 3 级
                        
                    (DC_Status[0]==12 ) || //电池SOC过高 1 级
                    (DC_Status[0]==62 ) || //电池SOC过高 2 级   
                    (DC_Status[0]==112)    //电池SOC过高 3 级  
                  ){ //电池SOC
                LCD_DrawImage1BPP(x,    y, Bmp_dc, Fcolor,color);
                LCD_DrawImage1BPP(x+40, y, Bmp_SOC,Fcolor,color);
                if( (DC_Status[0]==13 ) || //电池SOC过低 1 级
                    (DC_Status[0]==63 ) || //电池SOC过低 2 级   
                    (DC_Status[0]==113)    //电池SOC过低 3 级
                  )LCD_DrawImage1BPP(x+72, y, Bmp_gd, Fcolor,color);//过低
           else if( (DC_Status[0]==12 ) || //电池SOC过高 1 级
                    (DC_Status[0]==62 ) || //电池SOC过高 2 级   
                    (DC_Status[0]==112)    //电池SOC过高 3 级  
                  )LCD_DrawImage1BPP(x+72, y, Bmp_gg, Fcolor,color);//过高
                LCD_DrawImage1BPP(x+112,y, Bmp_DJi,Fcolor,color);
                     if((DC_Status[0]==13 )||(DC_Status[0]==12 ))print_SZ_2(x+112+1,y,1,1,0,Fcolor);// 1 
                else if((DC_Status[0]==63 )||(DC_Status[0]==62 ))print_SZ_2(x+112+1,y,2,1,0,Fcolor);// 2
                else if((DC_Status[0]==113)||(DC_Status[0]==112))print_SZ_2(x+112+1,y,3,1,0,Fcolor);// 3 
                w=x+112+40;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                }	
            case 15: 
                al_index=16; 
                //if(1){
                if( (DC_Status[0]==4  ) || //电池温度过高 1 级
                    (DC_Status[0]==54 ) || //电池温度过高 2 级   
                    (DC_Status[0]==104) || //电池温度过高 3 级
                        
                    (DC_Status[0]==5  ) || //电池温度过低 1 级
                    (DC_Status[0]==55 ) || //电池温度过低 2 级   
                    (DC_Status[0]==105)    //电池温度过低 3 级  
                  ){ //电池温度过高，低1,2,3级
                LCD_DrawImage1BPP(x,    y, Bmp_dc, Fcolor,color);
                LCD_DrawImage1BPP(x+40, y, Bmp_wd, Fcolor,color);
                LCD_DrawImage1BPP(x+80, y, Bmp_Guo,Fcolor,color);
                if( (DC_Status[0]==4  ) || //电池温度过高 1 级
                    (DC_Status[0]==54 ) || //电池温度过高 2 级   
                    (DC_Status[0]==104)    //电池温度过高 3 级
                  )LCD_DrawImage1BPP(x+96, y, Bmp_Gao,Fcolor,color);//高
           else if( (DC_Status[0]==5  ) || //电池温度过低 1 级
                    (DC_Status[0]==55 ) || //电池温度过低 2 级   
                    (DC_Status[0]==105)    //电池温度过低 3 级  
                  )LCD_DrawImage1BPP(x+96, y, Bmp_di, Fcolor,color);//低                  
                LCD_DrawImage1BPP(x+112,y, Bmp_DJi,Fcolor,color);  
                     if((DC_Status[0]==4  )||(DC_Status[0]==5  ))print_SZ_2(x+112+1,y,1,1,0,Fcolor);// 1 
                else if((DC_Status[0]==54 )||(DC_Status[0]==55 ))print_SZ_2(x+112+1,y,2,1,0,Fcolor);// 2
                else if((DC_Status[0]==104)||(DC_Status[0]==105))print_SZ_2(x+112+1,y,3,1,0,Fcolor);// 3 
                w=x+112+40;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                }
            case 16: 
                al_index=17; 
                //if(1){
                if( (DC_Status[0]==6  ) || //电池单体温差过大 1 级
                    (DC_Status[0]==56 ) || //电池单体温差过大 2 级   
                    (DC_Status[0]==106) || //电池单体温差过大 3 级
                        
                    (DC_Status[0]==3  ) || //电池单体压差过大 1 级
                    (DC_Status[0]==53 ) || //电池单体压差过大 2 级   
                    (DC_Status[0]==103)    //电池单体压差过大 3 级
                  ) {//
                LCD_DrawImage1BPP(x,    y, Bmp_dc, Fcolor,color);
                LCD_DrawImage1BPP(x+40, y, Bmp_dt, Fcolor,color);
                if( (DC_Status[0]==6  ) || //电池单体温差过大 1 级
                    (DC_Status[0]==56 ) || //电池单体温差过大 2 级   
                    (DC_Status[0]==106)    //电池单体温差过大 3 级
                  )LCD_DrawImage1BPP(x+80-2, y, Bmp_wd, Fcolor,color);
           else if( (DC_Status[0]==3  ) || //电池单体压差过大 1 级
                    (DC_Status[0]==53 ) || //电池单体压差过大 2 级   
                    (DC_Status[0]==103)    //电池单体压差过大 3 级
                  )LCD_DrawImage1BPP(x+80, y, Bmp_Ya, Fcolor,color);
                LCD_DrawImage1BPP(x+96, y, Bmp_cgd,Fcolor,color);
                LCD_DrawImage1BPP(x+152,y, Bmp_DJi,Fcolor,color);  
                     if((DC_Status[0]==6  )||(DC_Status[0]==3  ))print_SZ_2(x+152+1,y,1,1,0,Fcolor);// 1 
                else if((DC_Status[0]==56 )||(DC_Status[0]==53 ))print_SZ_2(x+152+1,y,2,1,0,Fcolor);// 2
                else if((DC_Status[0]==106)||(DC_Status[0]==103))print_SZ_2(x+152+1,y,3,1,0,Fcolor);// 3
                w=x+152+40;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                }   
            case 17: 
                al_index=18; 
                //if(1){
                if( (DC_Status[0]==7  ) || //电池组过压 1 级
                    (DC_Status[0]==57 ) || //电池组过压 2 级   
                    (DC_Status[0]==107) || //电池组过压 3 级
                        
                    (DC_Status[0]==8  ) || //电池组欠压 1 级
                    (DC_Status[0]==58 ) || //电池组欠压 2 级   
                    (DC_Status[0]==108)    //电池组欠压 3 级
                  ) {//
                LCD_DrawImage1BPP(x,    y, Bmp_dc,  Fcolor,color);
                LCD_DrawImage1BPP(x+40, y, Bmp_Zu,  Fcolor,color);
                LCD_DrawImage1BPP(x+56, y, Bmp_DY,  Fcolor,color);
                if( (DC_Status[0]==7  ) || //电池组过压 1 级
                    (DC_Status[0]==57 ) || //电池组过压 2 级   
                    (DC_Status[0]==107)    //电池组过压 3 级
                  )LCD_DrawImage1BPP(x+56, y, Bmp_Guo, Fcolor,color);
           else if( (DC_Status[0]==8  ) || //电池组欠压 1 级
                    (DC_Status[0]==58 ) || //电池组欠压 2 级   
                    (DC_Status[0]==108)    //电池组欠压 3 级
                  )LCD_DrawImage1BPP(x+56, y, Bmp_Qian, Fcolor,color);
                LCD_DrawImage1BPP(x+96,y, Bmp_DJi,Fcolor,color);  
                     if((DC_Status[0]==7  )||(DC_Status[0]==8  ))print_SZ_2(x+96+1,y,1,1,0,Fcolor);// 1 
                else if((DC_Status[0]==57 )||(DC_Status[0]==58 ))print_SZ_2(x+96+1,y,2,1,0,Fcolor);// 2
                else if((DC_Status[0]==107)||(DC_Status[0]==108))print_SZ_2(x+96+1,y,3,1,0,Fcolor);// 3
                w=x+96+40;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                }
            case 18: 
                al_index=19; 
                //if(1){
                //if(DC_Status[1]&0X60){ //稳态充放电电流123级
                if( (DC_Status[0]==9  ) || //稳态充电电流 1 级
                    (DC_Status[0]==59 ) || //稳态充电电流 2 级   
                    (DC_Status[0]==109) || //稳态充电电流 3 级
                        
                    (DC_Status[0]==10 ) || //稳态放电电流 1 级
                    (DC_Status[0]==60 ) || //稳态放电电流 2 级   
                    (DC_Status[0]==110)    //稳态放电电流 3 级
                  ) {//
                LCD_DrawImage1BPP(x,    y, Bmp_WTai,  Fcolor,color);
                if( (DC_Status[0]==9  ) || //稳态充电电流 1 级
                    (DC_Status[0]==59 ) || //稳态充电电流 2 级   
                    (DC_Status[0]==109)    //稳态充电电流 3 级
                  )LCD_DrawImage1BPP(x+40, y, Bmp_cdian,Fcolor,color);//充电
           else if( (DC_Status[0]==10 ) || //稳态放电电流 1 级
                    (DC_Status[0]==60 ) || //稳态放电电流 2 级   
                    (DC_Status[0]==110)    //稳态放电电流 3 级
                  )LCD_DrawImage1BPP(x+40, y, Bmp_fd,   Fcolor,color);//放电
                LCD_DrawImage1BPP(x+80, y, Bmp_dl, Fcolor,color);
                LCD_DrawImage1BPP(x+80, y, Bmp_Guo,Fcolor,color);       
                LCD_DrawImage1BPP(x+120,y, Bmp_DJi,Fcolor,color);  
                     if((DC_Status[0]==9  )||(DC_Status[0]==10 ))print_SZ_2(x+120+1,y,1,1,0,Fcolor);// 1 
                else if((DC_Status[0]==59 )||(DC_Status[0]==60 ))print_SZ_2(x+120+1,y,2,1,0,Fcolor);// 2
                else if((DC_Status[0]==109)||(DC_Status[0]==110))print_SZ_2(x+120+1,y,3,1,0,Fcolor);// 3
                w=x+120+40;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                }
            case 19: 
                al_index=20; 
                //if(1){
                if((DC_Status[0]==115 )){ //BMS故障
                LCD_DrawImage1BPP(x,    y, Bmp_BMS,  Fcolor,color);
                LCD_DrawImage1BPP(x+40,y, Bmp_DJi,Fcolor,color);  
                print_SZ_2(x+40+1,y,3,1,0,Fcolor);// 1 
                LCD_DrawImage1BPP(x+80, y, Bmp_ST[0],Fcolor,color);
                w=x+80+40;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                }
            case 20: 
                al_index=21; 
                //if(1){
                if((eror_R==1)||(eror_R==2)){ //绝缘报警1,2级故障
                LCD_DrawImage1BPP(x,    y, Bmp_jy, Fcolor,color);
                LCD_DrawImage1BPP(x+40, y, Bmp_bj, Fcolor,color);
                LCD_DrawImage1BPP(x+80, y, Bmp_DJi,Fcolor,color);  
                print_SZ_2(x+80+1,y,eror_R+1,1,0,Fcolor);//  
                LCD_DrawImage1BPP(x+120, y, Bmp_ST[0],Fcolor,color);
                w=x+120+40;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                }
            case 21: 
                al_index=22; 
                //if(1){
                if((VCU_Status[0]&0x30)==0x10){ //充电互锁      
                LCD_DrawImage1BPP(x,    y, Bmp_cdian,Fcolor,color);
                LCD_DrawImage1BPP(x+40, y, Bmp_HSuo, Fcolor,color);                
                w=x+40+40;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                }              
            case 22: 
                al_index=23; 
                //if(1){
                if((VCU_Status[1]&0x08)){ //总成需要保养     
                LCD_DrawImage1BPP(x,    y, Bmp_ZCheng, Fcolor,color);
                LCD_DrawImage1BPP(x+40, y, Bmp_XBYang, Fcolor,color);                
                w=x+40+56;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                }              
            case 23: 
                al_index=24; 
                //if(1){
                if((DC_Status[4]&0x01)){ //加热启动失败     
                LCD_DrawImage1BPP(x,    y, Bmp_JRe,   Fcolor,color);
                LCD_DrawImage1BPP(x+40, y, Bmp_Qdong, Fcolor,color); 
                LCD_DrawImage1BPP(x+80, y, Bmp_SBai,  Fcolor,color);     
                w=x+80+40;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                }  
            case 24: 
                al_index=25; 
                //if(1){
                if((DC_Status[4]&0x02)){ //加热模块温度过高     
                LCD_DrawImage1BPP(x,    y, Bmp_JRe, Fcolor,color);
                LCD_DrawImage1BPP(x+40, y, Bmp_MK,  Fcolor,color); 
                LCD_DrawImage1BPP(x+80, y, Bmp_wd,  Fcolor,color);  
                LCD_DrawImage1BPP(x+120,y, Bmp_gg,  Fcolor,color);       
                w=x+120+40;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                }  
            case 25: 
                al_index=26; 
                //if(1){
                if((DC_Status[4]&0x04)){ //加热超时     
                LCD_DrawImage1BPP(x,    y, Bmp_JRe, Fcolor,color);
                LCD_DrawImage1BPP(x+40, y, Bmp_CShi,Fcolor,color);     
                w=x+40+40;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                }  
            case 26: 
                al_index=0; 
                //if(1){
                if((DC_Status[4]&0x08)){ //加热异常     
                LCD_DrawImage1BPP(x,    y, Bmp_JRe,   Fcolor,color);
                LCD_DrawImage1BPP(x+40, y, Bmp_YChang,Fcolor,color);     
                w=x+40+40;LCD_DrawRect(w, y, 250-w, 36, color);
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
        case 3:
            frmDJ();
            break;
        case 4:
            frmBMS();
            break;
        case 5:
            frmFuzhu();
            break;
        case 6:
            frmMHQ();
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



