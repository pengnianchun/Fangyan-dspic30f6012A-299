#include "SYSTEM.h"
#include "FONT.h"
//#include "LOGO.h"
#include "YBFONT.h"
//#include "CAR.h"

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
*/


void updata_DCDY(unsigned int x, unsigned int y) {
    //unsigned char color = GREEN;
    unsigned int DCDY = 50;
    if(DC_voltage>=65534)DC_voltage=0;
    DCDY = DC_voltage * 0.1;
    //DCDY = DCDY-1000;
    
    if (DCDY >= 800) DCDY = 800;
    print_SZ_1(x, y, (DCDY), 3, 0, WHITE); //电池电压数值 x=120+72+30   y=150+60-2
    if (DCDY > 0   && frmID == 0)
        LCD_DrawRect(225 + 2, 100+13 + 5 + 2, ((DCDY) * 3.31 * 0.125), 28, GREEN); // 331/100  
    if (DCDY < 800 && frmID == 0)//当为100时会出错
        LCD_DrawRect((225 + 2 + (DCDY) * 3.31 * 0.125), 100 +13+ 5 + 2, (331 - (DCDY) * 3.31 * 0.125), 28, BLACK);

}

void updata_DCDL(unsigned int x, unsigned int y) {
    unsigned int DCDL = 100;
    if(DC_current>=65534)DCDL=1000;else DCDL=DC_current/10;
    //DCDL = DC_current * 0.1;

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
    
}

void updata_SOC(void) {
    unsigned char color = WHITE;
    unsigned char soc = 100;
    if(DC_SOC>=254)DC_SOC=0;
    soc = DC_SOC ;// 0.4;
    if (soc >= 100) soc = 100;
    
    //if (soc > 25) color = GREEN;
    //else if (soc > 0 && soc <= 25) color = RED;
    //else color = BLACK;
    
    if(soc>0){
       if(DC_Status[1]&0XC0)color = RED;
       else                 color = GREEN;   
    }else                   color = BLACK;
    print_SZ_1(585, 100 + 13 + 5 + 60 + 60 - 10, soc, 3, 0, WHITE); //SOC数值
    LCD_DrawRect(225 + 2, 100 + 13 + 5 + 60 + 60 + 2 - 10, (soc * 3.31), 28, color); // 331/100  
    if (soc < 100)//当soc为100时会出错//此时函数溢出
        LCD_DrawRect((225 + 2 + soc * 3.31), 100 + 13 + 5 + 60 + 60 + 2 - 10, (331 - soc * 3.31), 28, BLACK);
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
        color_old[i] = 1;
    }
    
//LCD_DrawImage1BPPZOOM_4(336, 150, BMP_LOGO, BLUE, BLACK); //客车车标
 
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
   LCD_DrawImage1BPP(x+80, y+2*30, Bmp_wd,  WHITE, BLACK);// 
   LCD_DrawImage1BPP(x+226,y+2*30, Bmp_deg, WHITE, BLACK);//
   
   LCD_DrawImage1BPP(x+2,  y+3*30, Bmp_dc,  WHITE, BLACK);//
   LCD_DrawImage1BPP(x+40, y+3*30, Bmp_zdi, WHITE, BLACK);//
   LCD_DrawImage1BPP(x+80, y+3*30, Bmp_wd,  WHITE, BLACK);// 
   LCD_DrawImage1BPP(x+226,y+3*30, Bmp_deg, WHITE, BLACK);// 
   
//第一列
x=221-58;y=280-9;
   LCD_DrawImage1BPP(x,    y+0*30, Bmp_dc,   WHITE, BLACK);//电池故障等级
   LCD_DrawImage1BPP(x+40, y+0*30, Bmp_ST[0],WHITE, BLACK); 
   LCD_DrawImage1BPP(x+80, y+0*30, Bmp_DJi,  WHITE, BLACK); 

   LCD_DrawImage1BPP(x,    y+1*30, Bmp_ZChe, WHITE,BLACK); //整车故障等级
   LCD_DrawImage1BPP(x+40, y+1*30, Bmp_ST[0],WHITE, BLACK); 
   LCD_DrawImage1BPP(x+80, y+1*30, Bmp_DJi,  WHITE, BLACK); 

 //LCD_DrawImage1BPP(x,     y+2*30, Bmp_XShi1, WHITE,BLACK);//续驶
 //LCD_DrawImage1BPP(x+40,  y+2*30, Bmp_LCheng,WHITE,BLACK);//里程
 //LCD_DrawImage1BPP(378-12,y+2*30, Bmp_Km,    WHITE,BLACK);//单位 Km
   
 //LCD_DrawImage1BPP(x,     y+0*30,Bmp_VCU,     WHITE,BLACK);  //VCU
 //LCD_DrawImage1BPP(x,     y+1*30,Bmp_MCU,     WHITE,BLACK);  //MCU
 //LCD_DrawImage1BPP(x,     y+2*30,Bmp_BMS,     WHITE,BLACK);  //BMS
    
 //for(i=0;i<3;i++){
 //LCD_DrawImage1BPP(x+40,  y+i*30,Bmp_ST[0],   WHITE,BLACK);  //故障
 //LCD_DrawImage1BPP(x+80,  y+i*30,Bmp_DMa,     WHITE,BLACK);  //代码
 //} 
    
}

void update_dc2(void){
  unsigned char color=0;
  unsigned int  temp=0;
/////////////第二列/////////////
x=581-32;y=280-9; 
//控制器温度 
    if(DJcontroler_temperature>=254)DJcontroler_temperature=40;
    update_deg(x,    y+0*30,DJcontroler_temperature,WHITE);
//电机温度 
    if(DJ_temperature>=254)DJ_temperature=40;
    update_deg(x,    y+1*30,DJ_temperature,WHITE);
//电池最高温度 
    if(Tmax>=254)Tmax=40;
    update_deg(x,    y+2*30,Tmax,WHITE);
//电池最低温度 
    if(Tmin>=254)Tmin=40;
    update_deg(x,    y+3*30,Tmin,WHITE);
   
/////////////第一列/////////////
x=333-32;y=280-9;
//锂电池故障等级
  //if(DC_fault_dj>=254)DC_fault_dj=0;
    if(DC_fault_dj>0)color=RED;else color=WHITE;
    print_SZ_2(x,     y+0*30,DC_fault_dj,4,0,color); // 0
//整车故障等级
    if(VCU_Status[5]>=254)VCU_Status[5]=0;
    if(VCU_Status[5]>0)color=RED;else color=WHITE;
    print_SZ_2(x,     y+1*30,VCU_Status[5],4,0,color); // 0
//VCU故障代码
//MCU故障代码
//BMS故障代码

   
}

void disp_baojing2(void){
  unsigned char i,color=GRAY;
  unsigned char temp8=0;
        
  if( (MCU_Status[1]&0x01)||  //驱动电机控制器温度报警
      (MCU_Status[1]&0x02)    //驱动电机温度报警
     )color=RED;else color=GRAY;
  LCD_DrawImage1BPP(122+10, 10+50,Bmp_DJGRe,color,BLACK);//电机过热 
  
  if(mKL9)color=RED;//仓温报警
  else    color=GRAY;    
  LCD_DrawImage1BPP(213-24, 75-16,Bmp_CWBJ,color,BLACK);//
  
  if((DC_Status[3]&0X08)==0x00)color=RED;//负逻辑  MSD
  else                         color=GRAY; 
  //lcd_show_8dot(315,57,Bmp_GYa,color,BLACK);//高压检修
  //lcd_show_8dot(315,77,Bmp_JXiu,color,BLACK);//

  switch((VCU_Status[0]&0X38)>>3){
   case 0x00:color=GREEN;i=0;
   break;
   case 0x01:color=RED;  i=1;
   break;
   case 0x02:color=GREEN;i=2;
   break;
   case 0x03:color=GREEN;i=3;
   break;  
   default:  color=GRAY; i=0;
   break; 
  }
  lcd_show_8dot(384-61,62,Bmp_NRDCP[i],color,BLACK);//D  

  switch(VCU_Status[3]&0X0F){
   case 0x00:color=GREEN;i=0;//N
   break;
   case 0x0D:color=RED;  i=1;//R
   break;
   case 0x0E:color=GREEN;i=2;//D
   break;
   case 0x0F:color=GREEN;i=4;//P
   break;  
   
   case 0x01:color=GREEN;i=5;//1
   break; 
   case 0x02:color=GREEN;i=6;//2
   break; 
   case 0x03:color=GREEN;i=7;//3
   break; 
   case 0x04:color=GREEN;i=8;//4
   break; 
   case 0x05:color=GREEN;i=9;//5
   break; 
   case 0x06:color=GREEN;i=10;//6
   break; 
   
   default:  color=GRAY; i=0;
   break; 
  }
  lcd_show_8dot(384,62,Bmp_NRDCP[i],color,BLACK);//D  
  
  
  if(VCU_Cmd[2]==0X55)color=GREEN;
  else                color=GRAY; 
  lcd_show_8dot(458-16,75-11,Bmp_AC,color,BLACK);//AC

  if(DR_state&0X10)color=YELLOW;
  else             color=GRAY; 
  //lcd_show_8dot(498,57,Bmp_PPo,color,BLACK);//爬坡
  //lcd_show_8dot(498,77,Bmp_ms[3],color,BLACK);//模式
    
  if(     IN4   )color=RED;
  else           color=GRAY; 
  lcd_show_8dot(518-24,75-18,Bmp_TB_PQZZ,color,BLACK);//排气制动 
  
        if(VCU_Status[2]==1)i=0;
  else  if(VCU_Status[2]==2)i=1;
  else  if(VCU_Status[2]==3)i=2;
  else                      i=0;
  lcd_show_8dot(559,57,Bmp_ms[i],GREEN,BLACK);//纯电 混合 燃油
  lcd_show_8dot(559,77,Bmp_ms[3],GREEN,BLACK);//模式

  if(fKL1)color=RED;//安全门
  else    color=GRAY;    
  LCD_DrawImage1BPP(640-22, 75-18,Bmp_YJM_door,color,BLACK);//
  
  
}

void disp_baojing(void){
  unsigned char color=GRAY;
  unsigned int  temp;
  
  if(mKL4 ) color=RED;
  else             color=GRAY; 
  LCD_DrawImage1BPP(30-20,5,Bmp_yjf,color,BLACK);//应急阀开启报警开关 
  
  if(!fKL4)color=RED;//左前 
  else     color=GRAY; 
  if (color_old[0] != color) {
      color_old[0]  = color;
  LCD_DrawImage1BPP(91-24,25-18,Bmp_mcp, color,BLACK);//蹄片磨损
  LCD_DrawImage1BPP(91-5, 25-6, Bmp_mcpL,color,BLACK);//L
  //LCD_DrawImage1BPP(91,25-7,BMP_SZ[1],color,BLACK);
  }
  
  if(fKL3)color=YELLOW;//ABS
  else    color=GRAY;   
  if (color_old[1] != color) {
      color_old[1]  = color;
  LCD_DrawImage1BPP(152-24, 25-18,Bmp_TB_SChe,color,BLACK);//
  LCD_DrawImage1BPP(152-12, 25-5,Bmp_TB_ABS,color,BLACK);//
  }
  
  if(  mKL5  ) color=RED;
  else         color=GRAY; 
  LCD_DrawImage1BPP(216-28,25-24,Bmp_HCM,color,BLACK);//后舱门
 
  if(  mKL7 ) color=RED;
  else        color=GRAY; 
  LCD_DrawImage1BPP(275-18,25-18,Bmp_SW,color,BLACK);//水位报警

  if( ((VCU_Status[0]&0X03)==1) ||  //就绪
      ((VCU_Status[0]&0X03)==2)     //运行
    )    color=GREEN;
  else   color=GRAY;
  lcd_show_8dot(336-28, 25-12,Bmp_READY,color,BLACK);//READY

  if( ((JY_Status[0]&0x03)>0) ||  //正极绝缘报警
      ((JY_Status[0]&0x0C)>0)     //负极绝缘报警 
    )color=RED;else color=GRAY; 
    
  LCD_DrawImage1BPP(457-14, 25-20,Bmp_jygz,color,BLACK);//绝缘故障报警
  
  if((VCU_Status[5]==2)||(VCU_Status[5]==3))color=RED; 
  else                                      color=GRAY; 
  LCD_DrawImage1BPP(518-20, 25-15,Bmp_XTgz,color,BLACK);//系统故障
  
  if((DC_Status[2]&0X02)==0x00)color=YELLOW; 
  else                          color=GRAY; 
  //LCD_DrawImage1BPP(580-20, 25-14,Bmp_DCQDuan,color,BLACK);//电池切断 

  if(fKL7)color=YELLOW;//ASR
  else    color=GRAY;    
  if (color_old[2] != color) {
      color_old[2]  = color;
  LCD_DrawImage1BPP(640-24, 25-18,Bmp_TB_SChe,color,BLACK);//
  LCD_DrawImage1BPP(640-12, 25-5,Bmp_TB_ASR,color,BLACK);//
  }
  
  if(!fKL5) color=RED; //右前 
  else      color=GRAY; 
  if (color_old[3] != color) {
      color_old[3]  = color;
  LCD_DrawImage1BPP(702-24,25-18,Bmp_mcp, color,BLACK);//蹄片磨损
  LCD_DrawImage1BPP(702-5, 25-6, Bmp_mcpR,color,BLACK);//R
  //LCD_DrawImage1BPP(702,25-7,BMP_SZ[1],color,BLACK);
  }
  
  if(mKL6 ) color=RED;
  else      color=GRAY; 
  LCD_DrawImage1BPP(762-20,5,Bmp_yjf,color,BLACK);//应急阀开启报警开关 
  
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
    }

        //if (key_AV) {
        //    key_AV = 0;
        //    key_long_set = 0;
        //    key_up = 0;
        //    key_set = 0;
        //}
        /***********************************************************/

    //彭年春 2017/7/27 16:50:33
    switch (VIDEO) {
        case 0:
            if (key_AV) {
                key_AV = 0;
                key_long_set = 0;
                key_up = 0;
                key_set = 0;
                //if (time_flag)
                //    t_add = 1;
                //else t_add = 0;
            }
            break;
        case 1:
            if (key_AV) {
                key_AV = 0;
                key_long_set = 0;
                key_up = 0;
                key_set = 0;
                //if (time_flag)
                //    t_add = 1;
                //else t_add = 0;

                unsigned char mode = 1; //1,MCU

                if (AV_CH < 1 /*&& !time_flag*/) AV_CH++;
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
            if (1) {//倒车视屏选择使能按键
                if (((VCU_Status[0]&0x38) == 0x08) && R_flag == 0) {//倒挡
                    key_AV = 1; //模拟AV开关按一次
                    AV_CH = 0; //0+1=1  倒车
                    R_flag = 1; //防止一直进入这个函数，导致key_AV总是置1
                }
                if (((VCU_Status[0]&0x38) != 0x08) && R_flag == 1) {
                    key_AV = 1;
                    AV_CH = 4; // 0 返回MCU界面
                    R_flag = 0;
                    M_flag = 0;
                }
            }

            if ((VCU_Status[0]&0x38) != 0x08) {//中门选择使能按键
                if (LED2 == 1 && M_flag == 0) {//中门开
                    key_AV = 1; //模拟AV开关按一次
                    AV_CH = 1; //1+1=2  AV1
                    M_flag = 1; //防止一直进入这个函数，导致key_AV总是置1
                }
                if (LED2 == 0 && M_flag == 1) {
                    key_AV = 1;
                    AV_CH = 4; // 0 返回MCU界面
                    M_flag = 0;
                    R_flag = 0;
                }
            }
            break;
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
  LCD_DrawImage1BPP(x,y+0*34,Bmp_IN1,WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+1*34,Bmp_rear,WHITE,BLACK);
  LCD_DrawImage1BPP(x+18,y+1*34,Bmp_IN2,WHITE,BLACK);
  LCD_DrawImage1BPP(x+38,y+1*34,Bmp_Open,WHITE,BLACK);//
  LCD_DrawImage1BPP(x+56,y+1*34,Bmp_ZT,WHITE,BLACK);//
  
  LCD_DrawImage1BPP(x,y+2*34,Bmp_front,WHITE,BLACK);
  LCD_DrawImage1BPP(x+18,y+2*34,Bmp_IN3,WHITE,BLACK);
  LCD_DrawImage1BPP(x+38,y+2*34,Bmp_Open,WHITE,BLACK);//
  LCD_DrawImage1BPP(x+56,y+2*34,Bmp_ZT,WHITE,BLACK);//
  
  LCD_DrawImage1BPP(x,y+3*34,Bmp_IN4,WHITE,BLACK);  
  LCD_DrawImage1BPP(x+58,y+3*34,Bmp_ZXDeng,WHITE,BLACK); 
  LCD_DrawImage1BPP(x+56,y+3*34,Bmp_bj,WHITE,BLACK);   

  LCD_DrawImage1BPP(x,y+4*34,Bmp_IN5,WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+5*34,Bmp_IN6,WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+6*34,Bmp_IN7,WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+7*34,Bmp_IN8,WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+8*34,Bmp_left,WHITE,BLACK);
  LCD_DrawImage1BPP(x+18,y+8*34,Bmp_IN9,WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+9*34,Bmp_right,WHITE,BLACK);
  LCD_DrawImage1BPP(x+18,y+9*34,Bmp_IN10,WHITE,BLACK);
  
  
//第二列 
  x=500;y=95;
  LCD_DrawImage1BPP(x,y+0*34,Bmp_IN11,WHITE,BLACK); 
  LCD_DrawImage1BPP(x,y+1*34,Bmp_IN12,WHITE,BLACK); 
  
  LCD_DrawImage1BPP(x,y+2*34,Bmp_IN13,WHITE,BLACK);  
  LCD_DrawImage1BPP(x,y+2*34,Bmp_Jing,WHITE,BLACK);//
  
  disp_yg(x,y+3*34,Bmp_IN14);
  disp_yg(x,y+4*34,Bmp_IN15);
  disp_yg(x,y+5*34,Bmp_IN16);  
  
  LCD_DrawImage1BPP(x,y+6*34,Bmp_IN17,WHITE,BLACK);// 
  LCD_DrawImage1BPP(x,y+7*34,Bmp_IN18,WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+8*34,Bmp_IN19,WHITE,BLACK);// 
  LCD_DrawImage1BPP(x,y+9*34,Bmp_IN20,WHITE,BLACK);//

  
  unsigned int Iid1[20]={136,176,176,194,0,0,0,0,158,158,
                         540,556,556,580,580,580,0,0,0,0};
  disp_kg(Iid1);  //显示开关
}
//显示仪表开关2
void disp_KL2(void){
  unsigned int Iid[20]={17,18,19,20,28,27,26,25,32,31,
                        30,29,1,2,3,4,5,10,20,13};
  disp_ID(0,Iid); //显示编号
  x=80;y=95;
  disp_yg(x,y+0*34,Bmp_IN21);
 
  LCD_DrawImage1BPP(x,y+1*34,Bmp_front,WHITE,BLACK);  
  LCD_DrawImage1BPP(x+18,y+1*34,Bmp_IN22,WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+2*34,Bmp_rear,WHITE,BLACK); 
  LCD_DrawImage1BPP(x+18,y+2*34,Bmp_IN23,WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+3*34,Bmp_IN24,WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+4*34,Bmp_IN25,WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+5*34,Bmp_IN26,WHITE,BLACK); 
  LCD_DrawImage1BPP(x,y+6*34,Bmp_IN27,WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+7*34,Bmp_IN28,WHITE,BLACK);
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
  LCD_DrawImage1BPP(x+40,y+8*34,Bmp_adr,WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+9*34,Bmp_zong,WHITE,BLACK);
  LCD_DrawImage1BPP(x+18,y+9*34,Bmp_dy,WHITE,BLACK);
  
  unsigned int Iid1[20]={160,136,136,120,0,0,0,0,0,0,
                         0,0,0,0,0,0,0,580,578,556,};
  disp_kg(Iid1);  //显示开关
}

//显示仪表传感器信号
void disp_ADR(void){ 
 unsigned int  j=0,i=0;
 unsigned char Iid[2][8]={ {8,7,6,5,4,3,2,1},
                           {15,10,9,14,13,0,0,0  } };
 
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

     LCD_DrawImage1BPP(x,   y+2*34,Bmp_front, WHITE,BLACK);
     LCD_DrawImage1BPP(x+20,y+2*34,Bmp_SER3, WHITE,BLACK);
     
     LCD_DrawImage1BPP(x,   y+3*34,Bmp_rear,WHITE,BLACK);
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
  
  LCD_DrawImage1BPP(x,y+3*34,Bmp_front, WHITE,BLACK);//
  LCD_DrawImage1BPP(x+18,y+3*34,Bmp_front_load4, WHITE,BLACK);//
  
  LCD_DrawImage1BPP(x,y+4*34,Bmp_front_load5, WHITE,BLACK);
  LCD_DrawImage1BPP(x+40,y+4*34,Bmp_BGuang, WHITE,BLACK);  
  LCD_DrawImage1BPP(x+80,y+4*34,Bmp_XDeng, WHITE,BLACK);  
  
  LCD_DrawImage1BPP(x,y+5*34,Bmp_right, WHITE,BLACK);// 
  LCD_DrawImage1BPP(x+18,y+5*34,Bmp_front, WHITE,BLACK);// 
  LCD_DrawImage1BPP(x+38,y+5*34,Bmp_front_load6, WHITE,BLACK);//
  
  LCD_DrawImage1BPP(x,y+6*34,Bmp_left, WHITE,BLACK);// 
  LCD_DrawImage1BPP(x+18,y+6*34,Bmp_front, WHITE,BLACK);// 
  LCD_DrawImage1BPP(x+38,y+6*34,Bmp_front_load7, WHITE,BLACK);//
  
  LCD_DrawImage1BPP(x,y+7*34,Bmp_front_load8, WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+8*34,Bmp_left, WHITE,BLACK); 
  LCD_DrawImage1BPP(x+18,y+8*34,Bmp_front_load9, WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+9*34,Bmp_front,WHITE,BLACK);//
  LCD_DrawImage1BPP(x+18,y+9*34,Bmp_front_load10,WHITE,BLACK);// 

//第二列
  x=500;y=95;
  LCD_DrawImage1BPP(x,y+0*34,Bmp_left,WHITE,BLACK);
  LCD_DrawImage1BPP(x+18,y+0*34,Bmp_front_load11,WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+1*34,Bmp_rear,WHITE,BLACK); 
  LCD_DrawImage1BPP(x+18,y+1*34,Bmp_front_load12,WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+2*34,Bmp_front_load13,WHITE,BLACK);//
  LCD_DrawImage1BPP(x,y+2*34,Bmp_Jing,WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+3*34,Bmp_front_load14,WHITE,BLACK);//
  LCD_DrawImage1BPP(x,y+4*34,Bmp_front_load15,WHITE,BLACK);//

  
}

//前部模块开关信息
void disp_front_KL(void){
  unsigned int Iid[20]={32,18,33,19,34,20,35,21,36,22,
                        37,23,38,24,39,41,17,25,40,26};
  disp_ID(0,Iid);
//第一列
  x=80;y=95;
  LCD_DrawImage1BPP(x,y+0*34,Bmp_FKL1, WHITE,BLACK);
  LCD_DrawImage1BPP(x+40,y+0*34,Bmp_Door, WHITE,BLACK);
  LCD_DrawImage1BPP(x+58,y+0*34,Bmp_Open, WHITE,BLACK);    
  
  LCD_DrawImage1BPP(x,y+1*34,Bmp_FKL2, WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+2*34,Bmp_FKL3, WHITE,BLACK);
  LCD_DrawImage1BPP(x+34,y+2*34,Bmp_bj, WHITE,BLACK);
  
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
  LCD_DrawImage1BPP(x+34,y+6*34,Bmp_bj, WHITE,BLACK);
  
  //LCD_DrawImage1BPP(x,y+7*34,Bmp_left, WHITE,BLACK);
  //LCD_DrawImage1BPP(x+18,y+7*34,Bmp_rear, WHITE,BLACK);
  //LCD_DrawImage1BPP(x+36,y+7*34,Bmp_FKL8, WHITE,BLACK);
  //LCD_DrawImage1BPP(x+92,y+7*34,Bmp_bj, WHITE,BLACK);
  //LCD_DrawImage1BPP(x,y+7*34,Bmp_KL, WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+7*34,Bmp_FKL8, WHITE,BLACK); 
  
  //LCD_DrawImage1BPP(x,y+8*34,Bmp_right, WHITE,BLACK);
  //LCD_DrawImage1BPP(x+18,y+8*34,Bmp_rear, WHITE,BLACK);
  //LCD_DrawImage1BPP(x+36,y+8*34,Bmp_FKL9, WHITE,BLACK);
  //LCD_DrawImage1BPP(x+92,y+8*34,Bmp_bj, WHITE,BLACK);
  //LCD_DrawImage1BPP(x,y+8*34,Bmp_KL, WHITE,BLACK);
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

  unsigned int Iid1[20]={160,0,156,214,214,0,156,0,0,0,
                         0,0,0,0,0,580,0,0,0,0};
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
  
  LCD_DrawImage1BPP(x,y+1*34,Bmp_right, WHITE,BLACK);
  LCD_DrawImage1BPP(x+18,y+1*34,Bmp_rear, WHITE,BLACK);
  LCD_DrawImage1BPP(x+38,y+1*34,Bmp_top_load2, WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+2*34,Bmp_rear,WHITE,BLACK);
  LCD_DrawImage1BPP(x+18,y+2*34,Bmp_top_load3, WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+3*34,Bmp_rear,WHITE,BLACK);
  LCD_DrawImage1BPP(x+18,y+3*34,Bmp_top_load4, WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+4*34,Bmp_top_load5, WHITE,BLACK);

  LCD_DrawImage1BPP(x,y+5*34,Bmp_top_load6, WHITE,BLACK);
  LCD_DrawImage1BPP(x+59,y+5*34,Bmp_Deng,WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+6*34,Bmp_top_load7, WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+7*34,Bmp_top_load8, WHITE,BLACK);
  LCD_DrawImage1BPP(x+40,y+7*34,Bmp_adr, WHITE,BLACK);
  LCD_DrawImage1BPP(x+78,y+7*34,Bmp_sc,WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+8*34,Bmp_top_load9, WHITE,BLACK);

  LCD_DrawImage1BPP(x,y+9*34,Bmp_top_load10, WHITE,BLACK);
  LCD_DrawImage1BPP(x+40,y+9*34,Bmp_Cang, WHITE,BLACK);
  LCD_DrawImage1BPP(x+58,y+9*34,Bmp_fs,WHITE,BLACK);  
  LCD_DrawImage1BPP(x+98,y+9*34,Bmp_dy,WHITE,BLACK); 
                                                        
  
//第二列 
  x=500;y=95;  
  LCD_DrawImage1BPP(x,y+0*34,Bmp_top_load11,WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+1*34,Bmp_top_load12, WHITE,BLACK);

  LCD_DrawImage1BPP(x,y+2*34,Bmp_rear,WHITE,BLACK);
  LCD_DrawImage1BPP(x+18,y+2*34,Bmp_top_load13,WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+3*34,Bmp_rear,WHITE,BLACK);
  LCD_DrawImage1BPP(x+18,y+3*34,Bmp_top_load14,WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+4*34,Bmp_left,WHITE,BLACK); 
  LCD_DrawImage1BPP(x+18,y+4*34,Bmp_rear,WHITE,BLACK);
  LCD_DrawImage1BPP(x+38,y+4*34,Bmp_top_load15,WHITE,BLACK);
  
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
  
  LCD_DrawImage1BPP(x,y+3*34,Bmp_front, WHITE,BLACK);  
  LCD_DrawImage1BPP(x+18,y+3*34,Bmp_Door, WHITE,BLACK);  
  LCD_DrawImage1BPP(x+36,y+3*34,Bmp_TKL4, WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+4*34,Bmp_TKL5, WHITE,BLACK); 
  
  LCD_DrawImage1BPP(x,y+5*34,Bmp_rear, WHITE,BLACK);  
  LCD_DrawImage1BPP(x+18,y+5*34,Bmp_Door, WHITE,BLACK); 
  LCD_DrawImage1BPP(x+36,y+5*34,Bmp_TKL6, WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+6*34,Bmp_TKL7, WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+7*34,Bmp_TKL8, WHITE,BLACK);
  
  LCD_DrawImage1BPP(x+39,y+8*34,Bmp_hcm, WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+8*34,Bmp_TKL9, WHITE,BLACK);
  LCD_DrawImage1BPP(x+80,y+8*34,Bmp_wd, WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+9*34,Bmp_TKL10,WHITE,BLACK);

//第二列 +
  x=500;y=95;
  LCD_DrawImage1BPP(x,y+0*34,Bmp_TKL11,WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+1*34,Bmp_TKL12,WHITE,BLACK);
  disp_ADD(3);// KL13 KL14 作为地址线
  
  LCD_DrawImage1BPP(x,y+4*34,Bmp_TKL15,WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+5*34,Bmp_TADD, WHITE,BLACK); 
  
  LCD_DrawImage1BPP(x,y+6*34,Bmp_TKH1, WHITE,BLACK); 
  LCD_DrawImage1BPP(x+57,y+6*34,Bmp_ST[0], WHITE,BLACK); 
  LCD_DrawImage1BPP(x+96,y+6*34,Bmp_Deng, WHITE,BLACK); 
  LCD_DrawImage1BPP(x+114,y+6*34,Bmp_sr, WHITE,BLACK); 
  
  unsigned int Iid1[20]={120,0,136,216,136,216,120,0,180,0,
                         0,0,0,0,0,0,612,0,0,0};
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
   //case 5:disp_rear_load(); 
   //break;
   //case 6:disp_rear_KL(); 
   //break; 
   case 5:disp_top_load();    
   break;
   case 6:disp_top_KL();    
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
   //case 5:update_CY09MT_load(1);TCAN=Rcan_count;
   //break; 
   //case 6:update_CY09MT_KL(1);  TCAN=Rcan_count;
   //break;      
   case 5:update_CY09MT_load(2);TCAN=Mcan_count;
   break; 
   case 6:update_CY09MT_KL(2);  TCAN=Mcan_count;
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
    for(i=0;i<5;i++){
    LCD_DrawImage1BPP(x+40, y+i*30, BMP_STSTEM,  color, BLACK); //系统
    LCD_DrawImage1BPP(x+80, y+i*30, BMP_Message, color, BLACK); //信息
    }
    LCD_DrawImage1BPP(x,    y+0*30, BMP_Control, color, BLACK); //控制
    LCD_DrawImage1BPP(x,    y+1*30, Bmp_ZQu,     color, BLACK); //电机  //BMP_Engine 发动机 
  //LCD_DrawImage1BPP(x,    y+2*30, BMP_Debug,   color, BLACK); //调试
    LCD_DrawImage1BPP(x,    y+2*30, BMP_Battery, color, BLACK); //电池    
  //LCD_DrawImage1BPP(x,    y+4*30, BMP_Air,     color, BLACK); //空调
  //LCD_DrawImage1BPP(x,    y+5*30, Bmp_DQi,     color, BLACK); //电器  
    LCD_DrawImage1BPP(x,    y+3*30, BMP_Fuzhu,   color, BLACK); //辅助    
    LCD_DrawImage1BPP(x,    y+4*30, BMP_IC,      color, BLACK); //仪表

    LCD_DrawImage1BPP(x,    y+5*30, Bmp_SJSZ,    color, BLACK); //时间设置 
    
    LCD_DrawImage1BPP(x,    y+6*30, Bmp_csu,     color, BLACK); //车速
    LCD_DrawImage1BPP(x+40, y+6*30, Bmp_subi,    color, BLACK); //速比
    
    LCD_DrawImage1BPP(x,    y+7*30,Bmp_TChu,    color, BLACK); //退出
      
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

    if (i == 16) i = 8;
    if (i == 0)  i = 8;
    
x=320-9;y=75-10;
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
    LCD_DrawImage1BPP(x,  y+0*30, BMP_Choose, color, BLACK);
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
    LCD_DrawImage1BPP(x,  y+1*30, BMP_Choose, color, BLACK);
    if (i == 10 || i == 2) {
        color = GREEN;
        if (key_set) {
            key_set = 0;
            if (time_flag == 0) {
                f_index = 0;
                frmID = 4;//7
            }
            time_flag = 0;
        }
    } else
        color = BLACK;
    LCD_DrawImage1BPP(x,  y+2*30, BMP_Choose, color, BLACK);
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
    LCD_DrawImage1BPP(x,  y+3*30, BMP_Choose, color, BLACK);
    if (i == 12 || i == 4) {
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
    LCD_DrawImage1BPP(x,  y+4*30, BMP_Choose, color, BLACK);
    if (i == 13 || i == 5) {
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
    LCD_DrawImage1BPP(x,  y+5*30, BMP_Choose, color, BLACK);
    if (i == 14|| i == 6) {
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
    LCD_DrawImage1BPP(x,  y+6*30, BMP_Choose, color, BLACK);
    if (i == 15|| i == 7) {
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
    LCD_DrawImage1BPP(x,  y+7*30, BMP_Choose, color, BLACK);
    
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
   lcd_show_8dot(x,    y+0*35, Bmp_CLiang, WHITE, BLACK);//车辆
   lcd_show_8dot(x+40, y+0*35, Bmp_ZT,     WHITE, BLACK);//状态
   
   lcd_show_8dot(x,    y+1*35, Bmp_ZChe,   WHITE, BLACK);//整车
   lcd_show_8dot(x+40, y+1*35, Bmp_kzq,    WHITE, BLACK);//控制器
   lcd_show_8dot(x+96, y+1*35, Bmp_ZT,     WHITE, BLACK);//状态

   lcd_show_8dot(x,    y+2*35, Bmp_cdian,  WHITE, BLACK);//充电
   lcd_show_8dot(x+40, y+2*35, Bmp_ZT,     WHITE, BLACK);//状态

   lcd_show_8dot(x,    y+3*35, Bmp_GYa,    WHITE, BLACK);//高压
   lcd_show_8dot(x+40, y+3*35, Bmp_HSuo,   WHITE, BLACK);//互锁
   lcd_show_8dot(x+80, y+3*35, Bmp_ZT,     WHITE, BLACK);//状态

   lcd_show_8dot(x,    y+4*35, Bmp_zd,     WHITE, BLACK);//制动
   lcd_show_8dot(x+40, y+4*35, Bmp_xt,     WHITE, BLACK);//系统
   lcd_show_8dot(x+80, y+4*35, Bmp_ZT,     WHITE, BLACK);//状态  
   
   //lcd_show_8dot(x,    y+5*35, Bmp_DCDC,   WHITE, BLACK);//DCDC
   //lcd_show_8dot(x+24, y+5*35, Bmp_DCDC,   WHITE, BLACK);//
   //lcd_show_8dot(x+48, y+5*35, Bmp_ZT,     WHITE, BLACK);//状态

   //lcd_show_8dot(x,    y+6*35, Bmp_DCDC,   WHITE, BLACK);//DCDC
   //lcd_show_8dot(x+24, y+6*35, Bmp_DCDC,   WHITE, BLACK);//
   //lcd_show_8dot(x+48, y+6*35, Bmp_wd,     WHITE, BLACK);//
   //lcd_show_8dot(x+88, y+6*35, Bmp_bj,     WHITE, BLACK);// 
   
   //lcd_show_8dot(x,    y+7*35, Bmp_DCDC,   WHITE, BLACK);//DCDC
   //lcd_show_8dot(x+24, y+7*35, Bmp_DCDC,   WHITE, BLACK);//
   //lcd_show_8dot(x+48, y+7*35, Bmp_ZT,     WHITE, BLACK);//
   //lcd_show_8dot(x+88, y+7*35, Bmp_bj,     WHITE, BLACK);// 

x=x+338;//单位符号

///////////////////////第二列///////////////////////
x=463-58;y=84-9; 
   lcd_show_8dot(x,    y+0*35, Bmp_qyin,   WHITE, BLACK);//牵引
   lcd_show_8dot(x+40, y+0*35, Bmp_tbbfb,  WHITE, BLACK);//踏板百分比

   lcd_show_8dot(x,    y+1*35, Bmp_zd,     WHITE, BLACK);//制动
   lcd_show_8dot(x+40, y+1*35, Bmp_tbbfb,  WHITE, BLACK);//踏板百分比

   lcd_show_8dot(x,    y+2*35, Bmp_zg,     WHITE, BLACK);//最高故障等级
   lcd_show_8dot(x+40, y+2*35, Bmp_ST[0],  WHITE, BLACK);//
   lcd_show_8dot(x+80, y+2*35, Bmp_DJi,    WHITE, BLACK);//
   
   lcd_show_8dot(x,    y+3*35, Bmp_QTa,    WHITE, BLACK);//其他故障总数
   lcd_show_8dot(x+40, y+3*35, Bmp_ST[0],  WHITE, BLACK);//
   lcd_show_8dot(x+80, y+3*35, Bmp_SLiang, WHITE, BLACK);//
   
   lcd_show_8dot(x,    y+4*35, Bmp_QTa,    WHITE, BLACK);//其他故障代码
   lcd_show_8dot(x+40, y+4*35, Bmp_ST[0],  WHITE, BLACK);//
   lcd_show_8dot(x+80, y+4*35, Bmp_DMa,    WHITE, BLACK);//
   
   lcd_show_8dot(x,    y+5*35, Bmp_QDong,  WHITE, BLACK);//驱动电机数量
   lcd_show_8dot(x+40, y+5*35, Bmp_dj,     WHITE, BLACK);//
   lcd_show_8dot(x+80, y+5*35, Bmp_SLiang, WHITE, BLACK);//
   
   lcd_show_8dot(x,    y+6*35, Bmp_You,    WHITE, BLACK);//油泵
   lcd_show_8dot(x+18, y+6*35, Bmp_Beng,   WHITE, BLACK);//   
   
   lcd_show_8dot(x,    y+7*35, Bmp_Qi,     WHITE, BLACK);//油泵
   lcd_show_8dot(x+18, y+7*35, Bmp_Beng,   WHITE, BLACK);//    
   
   lcd_show_8dot(x,    y+8*35, Bmp_kt,     WHITE, BLACK);//空调  
   
   lcd_show_8dot(x,    y+9*35, Bmp_DCDC,   WHITE, BLACK);//DCDC
   lcd_show_8dot(x+24, y+9*35, Bmp_DCDC,   WHITE, BLACK);//

   for(i=6;i<10;i++){
   lcd_show_8dot(x+50, y+i*35, Bmp_ZLing,  WHITE, BLACK);//指令   
   }
   
   
x=x+338;
   lcd_show_8dot(x,    y+0*35, Bmp_bfh,    WHITE, BLACK);//%
   lcd_show_8dot(x,    y+1*35, Bmp_bfh,    WHITE, BLACK);//%

}

void ControlUpdate(void) {
    unsigned int i=0,s,temp=1000;
    unsigned char color;
//////////////////////第一列////////////////////
x=305-32;y=84-9;
//车辆状态
  temp=VCU_Status[1];
        if(temp==0x01) lcd_show_8dot(x,    y+0*35, Bmp_QDong1,    WHITE, BLACK);//启动
  else  if(temp==0x02) lcd_show_8dot(x,    y+0*35, Bmp_XHuo,      WHITE, BLACK);//熄火     
  else  if(temp==0x03) lcd_show_8dot(x,    y+0*35, Bmp_QTa,       WHITE, BLACK);//其他    
  else  if(temp==0xFE) lcd_show_8dot(x,    y+0*35, Bmp_YChang,    YELLOW,BLACK);//异常    
  else                 lcd_show_8dot(x,    y+0*35, Bmp_YChang,    BLACK, BLACK);//无效不显示

//整车控制器状态
  temp=(VCU_Status[0]&0x07);
        if(temp==0x00) lcd_show_8dot(x,    y+1*35, Bmp_ZBei,      WHITE, BLACK);//准备
  else  if(temp==0x01) lcd_show_8dot(x,    y+1*35, Bmp_JXu,       WHITE, BLACK);//就绪     
  else  if(temp==0x02) lcd_show_8dot(x,    y+1*35, Bmp_YXing,     WHITE, BLACK);//运行    
  else  if(temp==0x03) lcd_show_8dot(x,    y+1*35, Bmp_ST[0],     RED,   BLACK);//故障    
//else                 lcd_show_8dot(x,    y+1*35, Bmp_ZBei,      WHITE, BLACK);//准备

//充电状态
        if(VCU_Status[4]==0x01) { 
           lcd_show_8dot(x,    y+2*35, Bmp_TChe,        WHITE, BLACK);//停车充电
           lcd_show_8dot(x+40, y+2*35, Bmp_cdian,       WHITE, BLACK);  
  }else  if(VCU_Status[4]==0x02) {
           lcd_show_8dot(x,    y+2*35, Bmp_XShi,        WHITE, BLACK);//行驶充电
           lcd_show_8dot(x+40, y+2*35, Bmp_cdian,       WHITE, BLACK);
  }else  if(VCU_Status[4]==0x03) {
           lcd_show_8dot(x,    y+2*35, Bmp_MYou,        WHITE, BLACK);//未充电 
           lcd_show_8dot(x+40, y+2*35, Bmp_cdian,       WHITE, BLACK); 
  }else  if(VCU_Status[4]==0x04) {
           lcd_show_8dot(x,    y+2*35, Bmp_cdian,       WHITE, BLACK);//充电完成
           lcd_show_8dot(x+40, y+2*35, Bmp_OK,          WHITE, BLACK);
  }else  if(VCU_Status[4]==0xFE) {
           lcd_show_8dot(x,    y+2*35, Bmp_cdian,       WHITE, BLACK);//充电
           lcd_show_8dot(x+40, y+2*35, Bmp_YChang,      WHITE, BLACK);//异常
  }else    LCD_DrawRect(x,    y+2*35,80, 18,BLACK);

  
//高压互锁状态
  if(VCU_Status[0]&0x40)lcd_show_8dot(x,    y+3*35, Bmp_bj,        RED,   BLACK);//报警
  else                  lcd_show_8dot(x,    y+3*35, Bmp_ST[1],     WHITE, BLACK);//正常
//制动系统状态
  if(VCU_Status[0]&0x80)lcd_show_8dot(x,    y+4*35, Bmp_bj,        RED,   BLACK);//报警
  else                  lcd_show_8dot(x,    y+4*35, Bmp_ST[1],     WHITE, BLACK);//正常
//DCDC状态

//DCDC温度报警

//DCDC状态报警


//////////////////////第二列////////////////////
x=698-32;y=84-9;
//牵引踏板百分比
  if(traction_st>=254)traction_st=0;//color=BLACK;else color=YELLOW;
  print_SZ_2(x,    y+0*35,traction_st,4,0,YELLOW);
//制动踏板百分比
  if(brake_st>=254)brake_st=0;//color=BLACK;else color=YELLOW;
  print_SZ_2(x,    y+1*35,brake_st,4,0,YELLOW);
//最高报警等级 
  if(VCU_Status[5]>=254)VCU_Status[5]=0;//color=BLACK;else color=RED;
  print_SZ_2(x,    y+2*35,VCU_Status[5],4,0,RED);
//其他故障总数 N 
  if(VCU_Status[6]>=254)VCU_Status[6]=0;//color=BLACK;else color=RED;
  print_SZ_2(x,    y+3*35,VCU_Status[6],4,0,RED);
//其他故障代码列表
  print_SZ_2(x-64*2,    y+4*35,(unsigned char)(VCU_fault>>24),3,0,YELLOW);
  print_SZ_2(x-64*1,    y+4*35,(unsigned char)(VCU_fault>>16),3,0,YELLOW);
  print_SZ_2(x-64*0,    y+4*35,(unsigned char)(VCU_fault>>8), 3,0,YELLOW);
  print_SZ_2(x+64*1,    y+4*35,(unsigned char)(VCU_fault),    3,0,YELLOW);
//驱动电机个数
  print_SZ_2(x,    y+5*35,VCU_Status[7],4,0,YELLOW);
  
x=553;
//油泵控制器控制指令
        if(VCU_Cmd[0]==0x55)LCD_DrawImage1BPP(x,y+6*35, Bmp_Close, YELLOW, BLACK);//
  else  if(VCU_Cmd[0]==0xAA)LCD_DrawImage1BPP(x,y+6*35, Bmp_Open,  GREEN,  BLACK);//   
//气泵控制器控制指令
        if(VCU_Cmd[1]==0x55)LCD_DrawImage1BPP(x,y+7*35, Bmp_Close, YELLOW, BLACK);//
  else  if(VCU_Cmd[1]==0xAA)LCD_DrawImage1BPP(x,y+7*35, Bmp_Open,  GREEN,  BLACK);// 
//空调变频器控制指令      
        if(VCU_Cmd[2]==0x55)LCD_DrawImage1BPP(x,y+8*35, Bmp_YXu,  GREEN,  BLACK);//
  else  if(VCU_Cmd[2]==0xAA)LCD_DrawImage1BPP(x,y+8*35, Bmp_JZhi, YELLOW, BLACK);// 
//DC/DC 控制指令
        if(VCU_Cmd[3]==0x55)LCD_DrawImage1BPP(x,y+9*35, Bmp_Close, YELLOW, BLACK);//
  else  if(VCU_Cmd[3]==0xAA)LCD_DrawImage1BPP(x,y+9*35, Bmp_Open,  GREEN,  BLACK);//      
        
        
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
   for(i=0;i<10;i++){
   lcd_show_8dot(x,    y+i*35, Bmp_dj,    WHITE, BLACK);//电机
   }
   lcd_show_8dot(x+40, y+3*35, Bmp_zj,    WHITE, BLACK);//转矩
   lcd_show_8dot(x+40, y+4*35, Bmp_zs,    WHITE, BLACK);//转速
   
   for(i=0;i<3;i++){
   lcd_show_8dot(x+40, y+(i*1)*35, Bmp_XHao, WHITE, BLACK);//序号
      print_SZ_2(x+80, y+(i*1)*35,(i+1),1,0,WHITE);
   }
   
   for(i=0;i<2;i++){
   lcd_show_8dot(x+40, y+(5+(i*2))*35, Bmp_wd,    WHITE, BLACK);//温度
      //print_SZ_2(x+80, y+(5+(i*2))*35,(i+1),1,0,WHITE);
   lcd_show_8dot(x+40, y+(6+(i*2))*35, Bmp_kzq,   WHITE, BLACK);//控制器
   lcd_show_8dot(x+96, y+(6+(i*2))*35, Bmp_wd,    WHITE, BLACK);//温度
      //print_SZ_2(x+136,y+(6+(i*2))*35,(i+1),1,0,WHITE);
   }
   lcd_show_8dot(x+40, y+9*35, Bmp_ZT,    WHITE, BLACK);//状态

   
x=x+338;//单位符号
   lcd_show_8dot(x,    y+3*35, Bmp_Nm,    WHITE, BLACK);//NM
   lcd_show_8dot(x,    y+4*35, Bmp_RPM,   WHITE, BLACK);//
   lcd_show_8dot(x,    y+5*35, Bmp_deg,   WHITE, BLACK);//
   lcd_show_8dot(x,    y+6*35, Bmp_deg,   WHITE, BLACK);//
 //lcd_show_8dot(x,    y+7*35, Bmp_deg,   WHITE, BLACK);//
 //lcd_show_8dot(x,    y+8*35, Bmp_deg,   WHITE, BLACK);//
   
///////////////////////第二列///////////////////////
x=463-58;y=84-9; 
   for(i=0;i<4;i++){
   lcd_show_8dot(x,    y+i*35, Bmp_dj,     WHITE, BLACK);//电机
   }
   lcd_show_8dot(x+40, y+0*35, Bmp_sr,     WHITE,BLACK);//输入电压
   lcd_show_8dot(x+80, y+0*35, Bmp_DY,     WHITE,BLACK);
   
   lcd_show_8dot(x+40, y+1*35, Bmp_MXian,  WHITE,BLACK);//母线电流
   lcd_show_8dot(x+80, y+1*35, Bmp_dl,     WHITE,BLACK);

   lcd_show_8dot(x+40, y+2*35, Bmp_ST[0],  WHITE, BLACK);//故障总数
   lcd_show_8dot(x+80, y+2*35, Bmp_SLiang, WHITE, BLACK);//
   
   lcd_show_8dot(x+40, y+3*35, Bmp_ST[0],  WHITE, BLACK);//故障代码
   lcd_show_8dot(x+80, y+3*35, Bmp_DMa,    WHITE, BLACK);// 
   
x=x+338;
   lcd_show_8dot(x,    y+0*35, Bmp_V,  WHITE, BLACK);
   lcd_show_8dot(x,    y+1*35, Bmp_A,  WHITE, BLACK);
    
}

void DJUpdate(void) {
    unsigned int  s=0,temp=0; 
    unsigned char i=0;
    unsigned char color;
//////////////////////第一列////////////////////
x=305-32;y=84-9;
//驱动电机序号
  for(i=0;i<3;i++){
  print_SZ_2(x,    y+i*35,MCU_Num[i],4,0,YELLOW);
  }

//驱动电机转矩 
  if(DJ_torque>=65534)temp=2000;else temp=DJ_torque/10;
  if(temp>=2000)temp=(temp-2000);
  else          temp=(2000-temp);     
  print_SZ_2(x,    y+3*35,temp,4,0,YELLOW);
//电机转速
  if(DJ_speed>=65534)DJ_speed=20000;
  if(DJ_speed>=20000)temp=DJ_speed-20000;
  else               temp=20000-DJ_speed;  
  print_SZ_2(x,    y+4*35,temp,4,0,YELLOW);
  
//电机温度
  if(DJ_temperature>=254)DJ_temperature=40;
  update_deg(x,y+5*35,DJ_temperature,YELLOW);
//电机控制器温度
  if(DJcontroler_temperature>=254)DJcontroler_temperature=40;
  update_deg(x,y+6*35,DJcontroler_temperature,YELLOW);  
  
//电机温度报警
  if(MCU_Status[1]&0x02)lcd_show_8dot(x,    y+7*35, Bmp_bj,        RED,   BLACK);//报警
  else                  lcd_show_8dot(x,    y+7*35, Bmp_ST[1],     WHITE, BLACK);//正常
//电机控制器温度报警
  if(MCU_Status[1]&0x01)lcd_show_8dot(x,    y+8*35, Bmp_bj,        RED,   BLACK);//报警
  else                  lcd_show_8dot(x,    y+8*35, Bmp_ST[1],     WHITE, BLACK);//正常
//驱动电机状态       
        if(MCU_Status[0]==0x01) lcd_show_8dot(x,    y+9*35, Bmp_HDian,     WHITE, BLACK);//耗电
  else  if(MCU_Status[0]==0x02) lcd_show_8dot(x,    y+9*35, Bmp_FDian,     WHITE, BLACK);//发电     
  else  if(MCU_Status[0]==0x03) lcd_show_8dot(x,    y+9*35, Bmp_GBi,       WHITE, BLACK);//关闭 
  else  if(MCU_Status[0]==0x04) lcd_show_8dot(x,    y+9*35, Bmp_ZBei,      WHITE, BLACK);//准备 
  else                          lcd_show_8dot(x,    y+9*35, Bmp_GBi,       BLACK, BLACK);//关闭 

//////////////////////第二列////////////////////
x=698-32;y=84-9;

//输入电压
  if(DJcontroler_voltage>=65534)DJcontroler_voltage=0;
  print_SZ_2(x,    y+0*35,DJcontroler_voltage/10,4,0,YELLOW);
//母线电流
  if(DJcontroler_current>=65534)temp=1000;else temp=DJcontroler_current/10; 
  if(temp>=1000){
     temp=(temp-1000);s=12;
 }else{
     temp=(1000-temp);s=11;
      }
  update_dl(x-16,y+1*35,temp,4,s,YELLOW);

//驱动电机故障总数
  if(MCU_Num[3]>=254)MCU_Num[3]=0;
  print_SZ_2(x,    y+2*35,MCU_Num[3],4,0,RED);
//驱动电机故障代码列表
  print_SZ_2(x-64*2,    y+3*35,(unsigned char)(MCU_fault>>24),3,0,YELLOW);
  print_SZ_2(x-64*1,    y+3*35,(unsigned char)(MCU_fault>>16),3,0,YELLOW);
  print_SZ_2(x-64*0,    y+3*35,(unsigned char)(MCU_fault>>8), 3,0,YELLOW);
  print_SZ_2(x+64*1,    y+3*35,(unsigned char)(MCU_fault),    3,0,YELLOW);
  
}

void frmDJ(void) {
    if (f_index == 0) { //只更新一次
        f_index = 1;
        LCD_DrawRect(0,60,800,365,BLACK);
        LCD_DrawImage1BPP(340,30,    Bmp_ZQu,     GREEN, BLACK); //电机
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

void disp_battery3(void){ 
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
    lcd_show_8dot(x,    y+0*35,  Bmp_dc,        WHITE,BLACK);//电池组最大充电电压
    lcd_show_8dot(x+40, y+0*35,  Bmp_Zu,        WHITE,BLACK);//
    lcd_show_8dot(x+56, y+0*35,  Bmp_ZDYXu,     WHITE,BLACK);//
    lcd_show_8dot(x+96, y+0*35,  Bmp_cdian,     WHITE,BLACK);//    
    lcd_show_8dot(x+136,y+0*35,  Bmp_DY,        WHITE,BLACK);//     
    
    lcd_show_8dot(x,    y+1*35,  Bmp_zg,        WHITE,BLACK);//最高充电电压
    lcd_show_8dot(x+40, y+1*35,  Bmp_cdian,     WHITE,BLACK);//    
    lcd_show_8dot(x+80, y+1*35,  Bmp_DY,        WHITE,BLACK);//   
    
    lcd_show_8dot(x,    y+2*35,  Bmp_SJYQiu,    WHITE,BLACK);//实际要求充电电流
    lcd_show_8dot(x+80, y+2*35,  Bmp_cdian,     WHITE,BLACK);//    
    lcd_show_8dot(x+120,y+2*35,  Bmp_dl,        WHITE,BLACK);//  
    
    lcd_show_8dot(x,    y+3*35,  Bmp_dt,        WHITE,BLACK);//单体数    
    lcd_show_8dot(x+40, y+3*35,  Bmp_SLiang,    WHITE, BLACK);// 
    
    lcd_show_8dot(x,    y+4*35,  Bmp_cdian,     WHITE,BLACK);//充电 
    lcd_show_8dot(x+40, y+4*35,  Bmp_kzq,       WHITE,BLACK);//控制 
    lcd_show_8dot(x+78, y+4*35,  Bmp_kzq,       BLACK,BLACK);//控制 
    
    lcd_show_8dot(x,    y+5*35,  Bmp_Dian,      WHITE,BLACK);//电加热接触器
    lcd_show_8dot(x+18, y+5*35,  Bmp_JRe,       WHITE,BLACK);//    
    lcd_show_8dot(x+56, y+5*35,  Bmp_JCQi,      WHITE,BLACK);//  
    
    lcd_show_8dot(x,    y+6*35,  Bmp_cdian,     WHITE,BLACK);//充电接触器  
    lcd_show_8dot(x+40, y+6*35,  Bmp_JCQi,      WHITE,BLACK);//
    
x=x+338;//单位符号
    lcd_show_8dot(x,    y+0*35,  Bmp_V,       WHITE, BLACK);//
    lcd_show_8dot(x,    y+1*35,  Bmp_V,       WHITE, BLACK);//
    lcd_show_8dot(x,    y+2*35,  Bmp_A,       WHITE, BLACK);//
    
///////////////////////第二列///////////////////////
x=463-58;y=84-9; 

    for(i=0;i<4;i++){
    lcd_show_8dot(x,    y+i*35,  Bmp_dt,        WHITE,BLACK);//单体电压报警上限
    lcd_show_8dot(x+40, y+i*35,  Bmp_DY,        WHITE,BLACK);//
    }
    for(i=0;i<2;i++){
    lcd_show_8dot(x+80, y+(i*2)*35,    Bmp_bj,        WHITE,BLACK);//   
    lcd_show_8dot(x+80, y+(i*2+1)*35,  Bmp_QDuan,     WHITE,BLACK);//    
    }

    lcd_show_8dot(x+120,y+0*35,  Bmp_SXian,     WHITE,BLACK);//
    lcd_show_8dot(x+120,y+1*35,  Bmp_SXian,     WHITE,BLACK);//    
    
    lcd_show_8dot(x+120,y+2*35,  Bmp_XXian,     WHITE,BLACK);//
    lcd_show_8dot(x+120,y+3*35,  Bmp_XXian,     WHITE,BLACK);//   
    
    for(i=0;i<2;i++){
    lcd_show_8dot(x,    y+(i+4)*35,  Bmp_EDing,    WHITE,BLACK);//额定最大充电电流
    lcd_show_8dot(x+40, y+(i+4)*35,  Bmp_ZDYXu,    WHITE,BLACK);//
    if(i==0)lcd_show_8dot(x+80, y+(i+4)*35,  Bmp_cdian, WHITE,BLACK);// 
    else    lcd_show_8dot(x+80, y+(i+4)*35,  Bmp_fd,    WHITE,BLACK);// 
    lcd_show_8dot(x+120,y+(i+4)*35,  Bmp_dl,       WHITE,BLACK);//
    }    
    
    lcd_show_8dot(x,    y+6*35,  Bmp_EDing,    WHITE,BLACK);//额定容量
    lcd_show_8dot(x+40, y+6*35,  Bmp_RLiang,   WHITE,BLACK);//
    

x=x+338;//单位符号
    for(i=0;i<6;i++){
    if(i<4)lcd_show_8dot(x,    y+i*35, Bmp_V,    WHITE, BLACK);//    
    else   lcd_show_8dot(x,    y+i*35, Bmp_A,    WHITE, BLACK);// 
    }
    lcd_show_8dot(x,    y+6*35, Bmp_AH,        WHITE, BLACK);//


}
void update_battery3(void){
  unsigned int  i=0,temp=1000;
  unsigned char temp8[10];
//////////////////////第一列////////////////////
x=305-32;y=84-9;
//电池组最大充电电压
if(CD_voltage>=10000)CD_voltage=0;
  print_SZ_2(x,  y+0*35,CD_voltage/10,4,0,YELLOW);
//最高充电电压
  print_SZ_2(x,  y+1*35,MAX_cd_voltage/10,4,0,YELLOW);  
//实际要求充电电流
  print_SZ_2(x,  y+2*35,CD_current/10,4,0,YELLOW);
//单体数
  print_SZ_2(x,  y+3*35,BAT_sum,4,0,YELLOW);
//控制
        if(DC_control==0x01) lcd_show_8dot(x,    y+4*35, Bmp_cdian,     WHITE, BLACK);//充电
  else  if(DC_control==0x02) lcd_show_8dot(x,    y+4*35, Bmp_TZhi,      WHITE, BLACK);//停止     
  else  if(DC_control==0x08) lcd_show_8dot(x,    y+4*35, Bmp_WShou,     WHITE, BLACK);//握手      
  else                       lcd_show_8dot(x,    y+4*35, Bmp_TZhi,      WHITE, BLACK);//停止
//电加热接触器状态
  if(DC_Status[5]&0x02)LCD_DrawImage1BPP(x,y+5*35, Bmp_BHe,  GREEN,  BLACK);//
  else                 LCD_DrawImage1BPP(x,y+5*35, Bmp_DKai, YELLOW, BLACK);// 
//充电接触器
  if(DC_Status[5]&0x04)LCD_DrawImage1BPP(x,y+6*35, Bmp_BHe,  GREEN,  BLACK);//
  else                 LCD_DrawImage1BPP(x,y+6*35, Bmp_DKai, YELLOW, BLACK);// 
  
  

//////////////////////第二列////////////////////
x=698-32;y=84-9;
//单体电压报警上限
  print_SZ_2(x-16,  y+0*35,BAT_Vmax_bj,4,3,YELLOW);
//单体电压切断上限
  print_SZ_2(x-16,  y+1*35,BAT_Vmax_qd,4,3,YELLOW);
//单体电压报警下限
  print_SZ_2(x-16,  y+2*35,BAT_Vmin_bj,4,3,YELLOW);
//单体电压切断下限  
  print_SZ_2(x-16,  y+3*35,BAT_Vmin_qd,4,3,YELLOW);
//额定最大充电电流
  print_SZ_2(x,  y+4*35,DC_Max_ed_cd_current/10,4,0,YELLOW);
//额定最大放电电流
  print_SZ_2(x,  y+5*35,DC_Max_ed_fd_current/10,4,0,YELLOW);
//电池额定容量
  print_SZ_2(x,  y+6*35,DC_EDRL,4,0,YELLOW);


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
    for(i=0;i<7;i++){
    lcd_show_8dot(x,    y+i*35,  Bmp_dc,     WHITE,BLACK);//电池         
    }
    lcd_show_8dot(x+40, y+0*35,  Bmp_zong,   WHITE,BLACK);//总电压
    lcd_show_8dot(x+56, y+0*35,  Bmp_DY,     WHITE,BLACK);//

    lcd_show_8dot(x+40, y+1*35,  Bmp_zong,   WHITE,BLACK);//总电流
    lcd_show_8dot(x+56, y+1*35,  Bmp_dl,     WHITE,BLACK);

    lcd_show_8dot(x+40, y+2*35,  Bmp_SOC,    WHITE,BLACK);//soc

  for(i=0;i<4;i++){
    lcd_show_8dot(x+40, y+(i+3)*35, Bmp_bj,       WHITE,BLACK);//报警   
    lcd_show_8dot(x+80, y+(i+3)*35, Bmp_ZT,       WHITE,BLACK);//状态 
    lcd_show_8dot(x+120,y+(i+3)*35, BMP_SZ_3[i+1],WHITE,BLACK);//1
  }
     
x=x+338;//单位符号
     LCD_DrawImage1BPP(x,    y+0*35, Bmp_V,   WHITE,BLACK);
     LCD_DrawImage1BPP(x,    y+1*35, Bmp_A,   WHITE,BLACK);
     LCD_DrawImage1BPP(x,    y+2*35, Bmp_bfh, WHITE,BLACK); 

///////////////////////第二列///////////////////////
x=463-58;y=84-9; 

    for(i=0;i<5;i++){
    lcd_show_8dot(x,    y+i*35,Bmp_dt,   WHITE,BLACK);         
    }
    lcd_show_8dot(x+40, y+0*35,Bmp_zg,   WHITE,BLACK);//单体最高电压
    lcd_show_8dot(x+80, y+0*35,Bmp_DY,   WHITE,BLACK);
    
    lcd_show_8dot(x+40, y+1*35,Bmp_zdi,  WHITE,BLACK);//单体最低电压
    lcd_show_8dot(x+80, y+1*35,Bmp_DY,   WHITE,BLACK);
     
    lcd_show_8dot(x+40, y+2*35,Bmp_zg,   WHITE,BLACK);//单体最高温度
    lcd_show_8dot(x+80, y+2*35,Bmp_wd,   WHITE,BLACK);

    lcd_show_8dot(x+40, y+3*35,Bmp_zdi,  WHITE,BLACK);//单体最低温度
    lcd_show_8dot(x+80, y+3*35,Bmp_wd,   WHITE,BLACK);
   
    lcd_show_8dot(x+40, y+4*35,Bmp_PJun, WHITE,BLACK);//平均
    lcd_show_8dot(x+80, y+4*35,Bmp_DY,   WHITE,BLACK);//电压 
     
    lcd_show_8dot(x,    y+5*35,Bmp_xt,   WHITE,BLACK);//系统 
    lcd_show_8dot(x+40, y+5*35,Bmp_PJun, WHITE,BLACK);//平均
    lcd_show_8dot(x+80, y+5*35,Bmp_wd,   WHITE,BLACK);//电压 
     
    lcd_show_8dot(x,    y+6*35,  Bmp_dc,    WHITE,BLACK);//电池  
    lcd_show_8dot(x+40, y+6*35, Bmp_ST[0],  WHITE, BLACK);//故障总数
    lcd_show_8dot(x+80, y+6*35, Bmp_SLiang, WHITE, BLACK);//
    
    lcd_show_8dot(x,    y+7*35,  Bmp_dc,    WHITE,BLACK);//电池  
    lcd_show_8dot(x+40, y+7*35, Bmp_ST[0],  WHITE, BLACK);//故障代码
    lcd_show_8dot(x+80, y+7*35, Bmp_DMa,    WHITE, BLACK);// 
    
x=x+338;//单位符号
     LCD_DrawImage1BPP(x-114,y+0*35,Bmp_V,    WHITE,BLACK);
     LCD_DrawImage1BPP(x-114,y+1*35,Bmp_V,    WHITE,BLACK); 
     LCD_DrawImage1BPP(x-114,y+2*35,Bmp_deg,  WHITE,BLACK); 
     LCD_DrawImage1BPP(x-114,y+3*35,Bmp_deg,  WHITE,BLACK); 
     LCD_DrawImage1BPP(x-114,y+4*35,Bmp_V,    WHITE,BLACK);
     LCD_DrawImage1BPP(x-114,y+5*35,Bmp_deg,    WHITE,BLACK);
     for(i=0;i<4;i++){
     LCD_DrawImage1BPP(x-43,y+i*35,Bmp_Num,   WHITE,BLACK); //Bmp_Box
     LCD_DrawImage1BPP(x+27,y+i*35,Bmp_Num,   WHITE,BLACK); 
     }

}
void update_battery4(){
  unsigned int  s,i=0,j=0,temp=1000;
  unsigned int  x,y;
  unsigned char temp8;
//////////////////////第一列////////////////////
x=305-32;y=84-9;
//电池总电压
     if(DC_voltage>=65534)DC_voltage=0;
     print_SZ_2(x,    y+0*35,DC_voltage/10,4,0,YELLOW);
//电池总电流
     if(DC_current>=65534)temp=1000;else temp=DC_current/10;
     if(temp>=1000){
        temp=(temp-1000);j=12;
     }else{
        temp=(1000-temp);j=11;
     }
     if(temp>=1000)temp=1000;
     update_dl(x,    y+1*35,temp,3,j,YELLOW);
//SOC
     if(DC_SOC>=254)DC_SOC=0;
     print_SZ_2(x,   y+2*35,DC_SOC,4,0,YELLOW);
//电池状态1-5
  for(j=0;j<4;j++){ 
     temp8=DC_Status[j+1];
   for(i=0;i<8;i++){     
     lcd_show_8dot(x+48-i*16,y+35*(j+3),BMP_SZ_3[temp8&0x01],YELLOW,BLACK);
     temp8>>=1;
   } 
  } 

//////////////////////第二列////////////////////
x=698-32;y=84-9;

     x=583-40;
//最高电压     
     if(Vmax>=0xFEFE)Vmax=0;
     print_SZ_2(x,   y+0*35,Vmax,4,3,YELLOW);
//最低电压   
     if(Vmin>=0xFEFE)Vmin=0;
     print_SZ_2(x,   y+1*35,Vmin,4,3,YELLOW);
//最高温度
     if(Tmax>=254)Tmax=40;
     update_deg(x+16,y+2*35,Tmax,YELLOW);
//最低温度
     if(Tmin>=254)Tmin=40;
     update_deg(x+16,y+3*35,Tmin,YELLOW);
     
     x=672-24;
//最高电压子系统号
     if(Vmax_xt_num>=254)Vmax_xt_num=0;
     print_SZ_2(x,   y+0*35,Vmax_xt_num,3,0,YELLOW);
//最低电压子系统号
     if(Vmin_xt_num>=254)Vmin_xt_num=0;
     print_SZ_2(x,   y+1*35,Vmin_xt_num,3,0,YELLOW);
//最高温度子系统号
     if(Tmax_xt_num>=254)Tmax_xt_num=0;     
     print_SZ_2(x,   y+2*35,Tmax_xt_num,3,0,YELLOW);
//最低温度子系统号
     if(Tmin_xt_num>=254)Tmin_xt_num=0;       
     print_SZ_2(x,   y+3*35,Tmin_xt_num,3,0,YELLOW);
     
     x=743-24;
//最高电压电池单体代号
     if(Vmax_num>=254)Vmax_num=0;     
     print_SZ_2(x,   y+0*35,Vmax_num,3,0,YELLOW);
//最低电压电池单体代号
     if(Vmin_num>=254)Vmin_num=0;     
     print_SZ_2(x,   y+1*35,Vmin_num,3,0,YELLOW);
//最高温度探针序号       
     if(Tmax_tz_num>=254)Tmax_tz_num=0;     
     print_SZ_2(x,   y+2*35,Tmax_tz_num,3,0,YELLOW);
//最低温度探针序号  
     if(Tmin_tz_num>=254)Tmin_tz_num=0;      
     print_SZ_2(x,   y+3*35,Tmin_tz_num,3,0,YELLOW);
     

     x=583-40;
//单体平均电压
     if(Vpj>=0xFEFE)Vpj=0;      
     print_SZ_2(x,  y+4*35,Vpj,4,3,YELLOW);
//子系统平均温度
     if(Tpj>=254)Tpj=40;        
     update_deg(x+16,y+5*35,Tpj,YELLOW);
     
//可充电储能装置故障总数 N1
     if(DC_cd_sum>=254)DC_cd_sum=0;
     print_SZ_2(x+16,  y+6*35,DC_cd_sum,4,0,YELLOW);
x=698-32;     
//可充电储能装置故障代码列表
     print_SZ_2(x-64*2,    y+7*35,(unsigned char)(DC_fault>>24),3,0,YELLOW);
     print_SZ_2(x-64*1,    y+7*35,(unsigned char)(DC_fault>>16),3,0,YELLOW);
     print_SZ_2(x-64*0,    y+7*35,(unsigned char)(DC_fault>>8), 3,0,YELLOW);
     print_SZ_2(x+64*1,    y+7*35,(unsigned char)(DC_fault),    3,0,YELLOW);
     
}

void BMSFrame(unsigned char ID){
  LCD_DrawRect(0,60,800,365,BLACK);
  //显示标题栏
  LCD_DrawImage1BPP(578-8,   30,Bmp_Gong,GREEN,BLACK);//共
  LCD_DrawImage1BPP(578-8+50,30,Bmp_YE,  GREEN,BLACK);//页
  print_SZ_2(578-8+33-8,    39-9,2,1,0,YELLOW);//4
  
  LCD_DrawImage1BPP(700-25,30,Bmp_DI,GREEN,BLACK);//第
  LCD_DrawImage1BPP(700+25,30,Bmp_YE,GREEN,BLACK);//页
  
  print_SZ_2(700,30,ID+1,1,0,YELLOW);//页面编号
  
       if(ID==0)     disp_battery4();
  else if(ID==1)     disp_battery3();
  //else if(ID==2)     disp_battery1();
  //else if(ID==3)     disp_battery2();
  
}

void BMSUpdate(unsigned char ID){   
       if(ID==0)     update_battery4();
  else if(ID==1)     update_battery3();
  //else if(ID==2)     update_battery1();
  //else if(ID==3)     update_battery2();
}

void frmBMS(void) {
    static unsigned char ID=1;
    if (f_index == 0) { //只更新一次
        f_index = 1;
        key_up=1;
        ID=1;
        key_set=0;
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
       if(ID>=1) ID=0;
       else      ID++;
    }
    
    if(key_AV){
       if(ID>0)  ID--;
       else      ID=1;
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
x=400-18;y=84-9;
   lcd_show_8dot(x,    y+0*35, Bmp_Qi,     WHITE, BLACK);//气泵
   lcd_show_8dot(x+18, y+0*35, Bmp_Beng,   WHITE, BLACK);//
   
x=400-18;y=84-9;
   lcd_show_8dot(x,    y+5*35, Bmp_You,    WHITE, BLACK);//油泵
   lcd_show_8dot(x+18, y+5*35, Bmp_Beng,   WHITE, BLACK);//     
   
for(i=0;i<2;i++){
    
x=10;    
    LCD_DrawImage1BPP(x,     y+(i*5+1)*35,Bmp_dj,          WHITE,BLACK);//电机转速
    LCD_DrawImage1BPP(x+40,  y+(i*5+1)*35,Bmp_zs,          WHITE,BLACK);//

    LCD_DrawImage1BPP(x,     y+(i*5+2)*35,Bmp_MXian,       WHITE,BLACK);//母线电压
    LCD_DrawImage1BPP(x+40,  y+(i*5+2)*35,Bmp_DY,          WHITE,BLACK);//
    
    LCD_DrawImage1BPP(x,     y+(i*5+3)*35,Bmp_work,        WHITE,BLACK);//工作状态
    LCD_DrawImage1BPP(x+40,  y+(i*5+3)*35,Bmp_ZT,          WHITE,BLACK);//  
    
    LCD_DrawImage1BPP(x,     y+(i*5+4)*35,Bmp_ST[0],       WHITE,BLACK);//故障代码
    LCD_DrawImage1BPP(x+40,  y+(i*5+4)*35,Bmp_DMa,         WHITE,BLACK);//

x=x+338;//单位符号
    LCD_DrawImage1BPP(x,     y+(i*5+1)*35, Bmp_RPM,WHITE,BLACK);
    LCD_DrawImage1BPP(x,     y+(i*5+2)*35, Bmp_V,  WHITE,BLACK);

}

///////////////////////第二列///////////////////////
for(i=0;i<2;i++){
    
x=463-58;y=84-9;    
    LCD_DrawImage1BPP(x,     y+(i*5+1)*35,Bmp_kzq,         WHITE,BLACK);//控制器温度
    LCD_DrawImage1BPP(x+56,  y+(i*5+1)*35,Bmp_wd,          WHITE,BLACK);//

    LCD_DrawImage1BPP(x,     y+(i*5+2)*35,Bmp_dj,          WHITE,BLACK);//电机温度
    LCD_DrawImage1BPP(x+40,  y+(i*5+2)*35,Bmp_wd,          WHITE,BLACK);//
    
    LCD_DrawImage1BPP(x,     y+(i*5+3)*35,Bmp_dj,          WHITE,BLACK);//电机功率
    LCD_DrawImage1BPP(x+40,  y+(i*5+3)*35,Bmp_Power,       WHITE,BLACK);//  
    
    
x=x+338;//单位符号
    lcd_show_8dot(x,    y+(i*5+1)*35, Bmp_deg,      WHITE, BLACK);//
    lcd_show_8dot(x,    y+(i*5+2)*35, Bmp_deg,      WHITE, BLACK);//
    lcd_show_8dot(x,    y+(i*5+3)*35, Bmp_K,        WHITE, BLACK);//
    lcd_show_8dot(x+16, y+(i*5+3)*35, Bmp_W,        WHITE, BLACK);//   
    
}
  
}

void update_Fuzhu1(void) {
  unsigned int i=0,s,temp=1000;
  unsigned char color=0;
//////////////////////第一列////////////////////
x=305-32;y=84-9;
//气泵
//电机转速
  print_SZ_2(x,    y+1*35,QB_speed>>3,4,0,YELLOW);
//母线电压
  print_SZ_2(x,    y+2*35,QB_controler_voltage,4,0,YELLOW);
//工作状态
        if((QB_Status[0]&0XC0)==0x00) lcd_show_8dot(x,    y+3*35, Bmp_TZhi,     WHITE, BLACK);//停止
  else  if((QB_Status[0]&0XC0)==0x40) lcd_show_8dot(x,    y+3*35, Bmp_YXing,    WHITE, BLACK);//运行 
  else                                lcd_show_8dot(x,    y+3*35, Bmp_TZhi,     BLACK, BLACK);//停止      
//故障代码
    temp=QB_Status[0];
   for(i=0;i<8;i++){     
     lcd_show_8dot(x+48-i*16,y+35*(4),BMP_SZ_3[temp&0x01],YELLOW,BLACK);
     temp>>=1;
   } 

//油泵
//电机转速
  print_SZ_2(x,    y+6*35,YB_speed>>3,4,0,YELLOW);
//母线电压
  print_SZ_2(x,    y+7*35,YB_controler_voltage,4,0,YELLOW);
//工作状态
        if((YB_Status[0]&0XC0)==0x00) lcd_show_8dot(x,    y+8*35, Bmp_TZhi,     WHITE, BLACK);//停止
  else  if((YB_Status[0]&0XC0)==0x40) lcd_show_8dot(x,    y+8*35, Bmp_YXing,    WHITE, BLACK);//运行 
  else                                lcd_show_8dot(x,    y+8*35, Bmp_TZhi,     BLACK, BLACK);//停止      
//故障代码
    temp=YB_Status[0];
   for(i=0;i<8;i++){     
     lcd_show_8dot(x+48-i*16,y+35*(9),BMP_SZ_3[temp&0x01],YELLOW,BLACK);
     temp>>=1;
   } 

//////////////////////第二列////////////////////
x=698-32;y=84-9;
//气泵
//电机控制器温度
  update_deg(x,y+1*35,QB_controler_temperature,YELLOW);
//电机温度
  update_deg(x,y+2*35,QB_temperature,YELLOW);
//电机功率
  if(QB_Power>=200)temp=QB_Power-200;
  else             temp=200-QB_Power;
  print_SZ_2(x,    y+3*35,temp,4,0,YELLOW);

//油泵
//电机控制器温度
  update_deg(x,y+6*35,YB_controler_temperature,YELLOW);
//电机温度
  update_deg(x,y+7*35,YB_temperature,YELLOW);
//电机功率
  if(YB_Power>=200)temp=YB_Power-200;
  else             temp=200-YB_Power;
  print_SZ_2(x,    y+8*35,temp,4,0,YELLOW);


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
x=400-24;y=84-9;
    LCD_DrawImage1BPP(x,     y+0*35,Bmp_DCDC,        WHITE,BLACK);//DCDC
    LCD_DrawImage1BPP(x+24,  y+0*35,Bmp_DCDC,        WHITE,BLACK);//DCDC
x=10;
    LCD_DrawImage1BPP(x,     y+1*35,Bmp_sc,          WHITE,BLACK);//输出电压
    LCD_DrawImage1BPP(x+40,  y+1*35,Bmp_DY,          WHITE,BLACK);//
    
    LCD_DrawImage1BPP(x,     y+2*35,Bmp_MXian,       WHITE,BLACK);//母线电压
    LCD_DrawImage1BPP(x+40,  y+2*35,Bmp_DY,          WHITE,BLACK);//

    LCD_DrawImage1BPP(x,     y+3*35,Bmp_work,        WHITE,BLACK);//工作状态
    LCD_DrawImage1BPP(x+40,  y+3*35,Bmp_ZT,          WHITE,BLACK);//
    
    LCD_DrawImage1BPP(x,     y+4*35,Bmp_ST[0],       WHITE,BLACK);//故障代码
    LCD_DrawImage1BPP(x+40,  y+4*35,Bmp_DMa,         WHITE,BLACK);//
    
    
x=400-48;y=84-9;
    LCD_DrawImage1BPP(x,     y+5*35,Bmp_jy,          WHITE,BLACK);//绝缘检测仪
    LCD_DrawImage1BPP(x+40,  y+5*35,Bmp_JCYi,        WHITE,BLACK);//

x=10;
    LCD_DrawImage1BPP(x,     y+6*35,Bmp_zheng,       WHITE,BLACK);//正极绝缘电阻  
    LCD_DrawImage1BPP(x+18,  y+6*35,Bmp_jic,         WHITE,BLACK);//  
    LCD_DrawImage1BPP(x+40,  y+6*35,Bmp_jy,          WHITE,BLACK);//   
    LCD_DrawImage1BPP(x+80,  y+6*35,Bmp_dz,          WHITE,BLACK);//
    
    LCD_DrawImage1BPP(x,     y+7*35,Bmp_fu,          WHITE,BLACK);//负极绝缘电阻  
    LCD_DrawImage1BPP(x+18,  y+7*35,Bmp_jic,         WHITE,BLACK);//  
    LCD_DrawImage1BPP(x+40,  y+7*35,Bmp_jy,          WHITE,BLACK);//   
    LCD_DrawImage1BPP(x+80,  y+7*35,Bmp_dz,          WHITE,BLACK);//
    
    LCD_DrawImage1BPP(x,     y+8*35,Bmp_jy,          WHITE,BLACK);//绝缘电阻   
    LCD_DrawImage1BPP(x+40,  y+8*35,Bmp_dz,          WHITE,BLACK);//    
    
    LCD_DrawImage1BPP(x,     y+9*35,Bmp_work,        WHITE,BLACK);//工作状态
    LCD_DrawImage1BPP(x+40,  y+9*35,Bmp_ZT,          WHITE,BLACK);//
   
    
x=x+338;//单位符号
    LCD_DrawImage1BPP(x,     y+1*35, Bmp_V,    WHITE,BLACK);
    LCD_DrawImage1BPP(x,     y+2*35, Bmp_V,    WHITE,BLACK);
    
    for(i=0;i<3;i++){
    LCD_DrawImage1BPP(x,     y+(i+6)*35, Bmp_K,    WHITE,BLACK);
    LCD_DrawImage1BPP(x+16,  y+(i+6)*35, Bmp_R,    WHITE,BLACK);    
    }

///////////////////////第二列///////////////////////
x=463-58;y=84-9; 

    LCD_DrawImage1BPP(x,     y+1*35,Bmp_sc,       WHITE,BLACK);//输出电流
    LCD_DrawImage1BPP(x+40,  y+1*35,Bmp_dl,       WHITE,BLACK);//
    
    LCD_DrawImage1BPP(x,     y+2*35,Bmp_work,     WHITE,BLACK);//工作温度
    LCD_DrawImage1BPP(x+40,  y+2*35,Bmp_wd,       WHITE,BLACK);//

    LCD_DrawImage1BPP(x,     y+6*35,Bmp_zheng,       WHITE,BLACK);//正极绝缘报警
    LCD_DrawImage1BPP(x+18,  y+6*35,Bmp_jic,         WHITE,BLACK);//  
    LCD_DrawImage1BPP(x+40,  y+6*35,Bmp_jy,          WHITE,BLACK);//   
    LCD_DrawImage1BPP(x+80,  y+6*35,Bmp_bj,          WHITE,BLACK);//
    
    LCD_DrawImage1BPP(x,     y+7*35,Bmp_fu,          WHITE,BLACK);//负极绝缘报警  
    LCD_DrawImage1BPP(x+18,  y+7*35,Bmp_jic,         WHITE,BLACK);//  
    LCD_DrawImage1BPP(x+40,  y+7*35,Bmp_jy,          WHITE,BLACK);//   
    LCD_DrawImage1BPP(x+80,  y+7*35,Bmp_bj,          WHITE,BLACK);//
    
x=x+338;//单位符号   
    LCD_DrawImage1BPP(x,     y+1*35, Bmp_A,      WHITE,BLACK);
    LCD_DrawImage1BPP(x,     y+2*35, Bmp_deg,    WHITE,BLACK);
    
}
void update_Fuzhu2(void){
  unsigned int i=0,j=0,temp=1000;
  unsigned char color=0;
//////////////////////第一列////////////////////
x=305-32;y=84-9;
//DCDC
//输出电压
     print_SZ_2(x,     y+1*35,DCDC_SC_voltage,4,0,YELLOW);
//母线电压
     print_SZ_2(x,     y+2*35,DCDC_MX_voltage,4,0,YELLOW);
//工作状态
        if((DCDC_Status[0]&0X03)==0x00) lcd_show_8dot(x,    y+3*35, Bmp_TZhi,     WHITE, BLACK);//停止
  else  if((DCDC_Status[0]&0X03)==0x01) lcd_show_8dot(x,    y+3*35, Bmp_work,     WHITE, BLACK);//工作 
  else                                  lcd_show_8dot(x,    y+3*35, Bmp_TZhi,     BLACK, BLACK);//停止  

//故障代码
for(j=0;j<2;j++){
     temp=DCDC_Status[1-j];
     for(i=0;i<8;i++){     
       LCD_DrawImage1BPP(x-16*i+48+j*192,y+4*35,BMP_SZ_3[temp&0x01],YELLOW,BLACK);
       temp>>=1;
      }
}

//正对地绝缘电阻
     print_SZ_2(x-16,     y+6*35,anode_R,5,0,YELLOW);
//负对地绝缘电阻
     print_SZ_2(x-16,     y+7*35,negative_R,5,0,YELLOW);
//绝缘电阻
     print_SZ_2(x-16,     y+8*35,JY_R,5,0,YELLOW);       
//工作状态
     
        if((JY_Status[1]&0X03)==0x00) {
            lcd_show_8dot(x,    y+9*35, Bmp_Wei,     WHITE, BLACK);//未
            lcd_show_8dot(x+20, y+9*35, Bmp_ST[1],   WHITE, BLACK);//正常
  }else  if((JY_Status[1]&0X03)==0x01) {
            lcd_show_8dot(x,    y+9*35, Bmp_Wei,     BLACK, BLACK);//  
            lcd_show_8dot(x+20, y+9*35, Bmp_ST[1],   WHITE, BLACK);//正常
  }else     LCD_DrawRect(x,     y+9*35,80,18,BLACK); 
                       
//////////////////////第二列////////////////////
x=698-32;y=84-9; 
//DCDC
//输出电流
  temp=DCDC_SC_current/10;
     if(temp>=3200){
        temp=(temp-3200);j=12;
     }else{
        temp=(3200-temp);j=11;
     }
     if(temp>=1000)temp=1000;
     update_dl(x,    y+1*35,temp,3,j,YELLOW);
//工作温度
  update_deg(x,y+2*35,DCDC_temperature,YELLOW);

//绝缘检测仪
//正极绝缘报警
          if((JY_Status[0]&0x03)==0x00){
              lcd_show_8dot(x,    y+6*35, Bmp_ST[1],   WHITE, BLACK);// 
              lcd_show_8dot(x+40, y+6*35, Bmp_ST[1],   BLACK, BLACK);//正常
    }else if((JY_Status[0]&0x03)==0x01){
              lcd_show_8dot(x,    y+6*35, Bmp_jy,      RED,   BLACK);//绝缘 
              lcd_show_8dot(x+40, y+6*35, Bmp_bj,      RED,   BLACK);//报警
    }else if((JY_Status[0]&0x03)==0x02){
              lcd_show_8dot(x,    y+6*35, Bmp_EJi,     RED,   BLACK);//二级           
              lcd_show_8dot(x+40, y+6*35, Bmp_bj,      RED,   BLACK);//报警     
    }else{
              lcd_show_8dot(x,    y+6*35, Bmp_YJi,     RED,   BLACK);//一级           
              lcd_show_8dot(x+40, y+6*35, Bmp_bj,      RED,   BLACK);//报警  
    }
//负极绝缘报警
          if((JY_Status[0]&0x0C)==0x00){
              lcd_show_8dot(x,    y+7*35, Bmp_ST[1],   WHITE, BLACK);// 
              lcd_show_8dot(x+40, y+7*35, Bmp_ST[1],   BLACK, BLACK);//正常
    }else if((JY_Status[0]&0x0C)==0x04){
              lcd_show_8dot(x,    y+7*35, Bmp_jy,      RED,   BLACK);//绝缘 
              lcd_show_8dot(x+40, y+7*35, Bmp_bj,      RED,   BLACK);//报警
    }else if((JY_Status[0]&0x0C)==0x08){
              lcd_show_8dot(x,    y+7*35, Bmp_EJi,     RED,   BLACK);//二级           
              lcd_show_8dot(x+40, y+7*35, Bmp_bj,      RED,   BLACK);//报警     
    }else{
              lcd_show_8dot(x,    y+7*35, Bmp_YJi,     RED,   BLACK);//一级           
              lcd_show_8dot(x+40, y+7*35, Bmp_bj,      RED,   BLACK);//报警  
    }


}

void FuzhuFrame(unsigned char ID){
   LCD_DrawRect(0,60,800,365,BLACK);
   //显示标题栏
  LCD_DrawImage1BPP(578-8,   30,Bmp_Gong,GREEN,BLACK);//共
  LCD_DrawImage1BPP(578-8+50,30,Bmp_YE,  GREEN,BLACK);//页
  print_SZ_2(578-8+33-8,    39-9,2,1,0,YELLOW);//4
  
  LCD_DrawImage1BPP(700-25,30,Bmp_DI,GREEN,BLACK);//第
  LCD_DrawImage1BPP(700+25,30,Bmp_YE,GREEN,BLACK);//页
  
  print_SZ_2(700,30,ID+1,1,0,YELLOW);//页面编号
   
     switch(ID){
      case 0: disp_Fuzhu1();
      break;
      case 1: disp_Fuzhu2();
      break;
      default:
      break;
  }
}

void FuzhuUpdate(unsigned char ID){ 
     switch(ID){
      case 0: update_Fuzhu1();
      break;
      case 1: update_Fuzhu2();
      break;
      default:
      break;
  }

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
        ID=1;
    } else if (f_index == 1) {
        f_index = 1;
        FuzhuUpdate(ID);
    } else {
        f_index = 0;
    }
    
    if(key_up){
       if(ID>=1) ID=0;
       else      ID++;
    }
    if(key_AV){
       if(ID>0)  ID--;
       else      ID=1;
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
    
    LCD_DrawImage1BPP(340-40, 255,Bmp_XSu,  YELLOW,BLACK); //
    LCD_DrawImage1BPP(430,    255,Bmp_kmh,  GREEN,BLACK); // /h 
    
    X_pSpeed=e_limit_pSpeed;//
    
  }else if(f_index==1){
    f_index=1;
    print_SZ_2(340,145,e_hm_pulse,5,0,GREEN);//SPEED_RATIO  
    print_SZ_2(340,200,Vspeed,4,1,GREEN);//Vspeed   
    print_SZ_2(340+16,255,X_pSpeed,3,0,GREEN);//
  }else{
    f_index=0;
  }
  
  if(key_set){
     key_set=0;
     key_up=0;
     key_reset=0;
     e_limit_pSpeed=X_pSpeed;
     EEROM_WriteXSpeed();
     EEROM_ReadXSpeed();
     frmID=1;
     f_index=0; 
  }
  
  if(key_reset){
     key_reset=0;
     if(X_pSpeed<139)X_pSpeed+=10;
     else            X_pSpeed=139;
  }
  if(key_up){
     key_up=0; 
     if(X_pSpeed>9) X_pSpeed-=10;
     else           X_pSpeed=9;
  }
  //if(key_long_set){
  //   key_long_set=0;
  //   key_up=0;
  //   key_reset=0;
  //   frmID=1;
  //   f_index=0;
  //} 
  
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
                if(M_ON && (Fcan_count>=CAN_TIME)){      
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
                if(M_ON && (Rcan_count>=CAN_TIME)){
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
                if(M_ON && (Mcan_count>=CAN_TIME)){
              //LCD_DrawImage1BPP(x,    y, Bmp_top,  Fcolor,color);
                LCD_DrawImage1BPP(x,    y, Bmp_rear, Fcolor,color);
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
                //if(Vspeed>690){ //您已超速    
                if(Vspeed>e_limit_pSpeed*10){ //您已超速                
                LCD_DrawImage1BPP(x, y, Bmp_nycs,Fcolor,color);
                w=x+80;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                } 
            case 6: 
                al_index=7; 
                //if(1){
                if( (DC_Status[2]&0X03) ||  //单体电池过压报警
                    (DC_Status[2]&0X0C)     //单体电池欠压报警
                  ){ //电池单体过压,过低
                LCD_DrawImage1BPP(x,    y, Bmp_dc, Fcolor,color);
                LCD_DrawImage1BPP(x+40, y, Bmp_dt, Fcolor,color);
                if(DC_Status[2]&0X03)LCD_DrawImage1BPP(x+80, y, Bmp_Guo,Fcolor,color);
                else                 LCD_DrawImage1BPP(x+80, y, Bmp_Qian,Fcolor,color);
                LCD_DrawImage1BPP(x+96, y, Bmp_Ya, Fcolor,color);   
                w=x+96+16;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                }
            case 7: 
                al_index=8; 
                //if(1){
                if( (DC_Status[1]&0XC0) ||  //电池SOC 过低报警
                    (DC_Status[2]&0X10)     //电池SOC 过高报警
                  ){ 
                LCD_DrawImage1BPP(x,    y, Bmp_dc, Fcolor,color);
                LCD_DrawImage1BPP(x+40, y, Bmp_SOC,Fcolor,color);
                if(DC_Status[2]&0X10)LCD_DrawImage1BPP(x+72, y, Bmp_gg, Fcolor,color);
                else                 LCD_DrawImage1BPP(x+72, y, Bmp_gd, Fcolor,color);
                w=x+72+40;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                }	
            case 8: 
                al_index=9; 
                //if(1){
                if( (DC_Status[3]&0X0C) ||  //电池组过压报警
                    (DC_Status[3]&0X30)     //电池组欠压报警
                  ){ 
                LCD_DrawImage1BPP(x,    y, Bmp_dc,  Fcolor,color);
                LCD_DrawImage1BPP(x+40, y, Bmp_Zu,  Fcolor,color);
                LCD_DrawImage1BPP(x+56, y, Bmp_DY,  Fcolor,color);
                if(DC_Status[3]&0X30)LCD_DrawImage1BPP(x+96, y, Bmp_gd,  Fcolor,color);//过低
                else                 LCD_DrawImage1BPP(x+96, y, Bmp_gg,  Fcolor,color);//过高
                w=x+96+40;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                }
            case 9: 
                al_index=10; 
                //if(1){
                if(DC_Status[2]&0X80){ //电池不均衡  电池单体一致性差报警
                LCD_DrawImage1BPP(x,    y, Bmp_dc,  Fcolor,color);
                LCD_DrawImage1BPP(x+40, y, Bmp_dt,  Fcolor,color);
                LCD_DrawImage1BPP(x+80, y, Bmp_YZXC,  Fcolor,color);
                w=x+80+80;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                }   
            case 10: 
                al_index=11; 
                //if(1){
                if( (DC_Status[3]&0XC0) ||  //电池组充电电流报警
                    (DC_Status[4]&0X03)     //电池组放电电流报警
                  ){ 
                LCD_DrawImage1BPP(x,    y, Bmp_dc,  Fcolor,color);
                LCD_DrawImage1BPP(x+40, y, Bmp_Zu,  Fcolor,color);          
                if(DC_Status[4]&0X03)LCD_DrawImage1BPP(x+56, y, Bmp_fd,   Fcolor,color);//放电
                else                 LCD_DrawImage1BPP(x+56, y, Bmp_cdian,Fcolor,color);//充电
                LCD_DrawImage1BPP(x+96, y, Bmp_dl, Fcolor,color);
                LCD_DrawImage1BPP(x+136,y, Bmp_gg, Fcolor,color);
                w=x+136+40;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                }
            case 11: 
                al_index=12; 
                //if(1){
                if(DC_Status[1]&0X0C){ //电池温度过高
                LCD_DrawImage1BPP(x,    y, Bmp_dc,  Fcolor,color);
                LCD_DrawImage1BPP(x+40, y, Bmp_wd,  Fcolor,color);
                LCD_DrawImage1BPP(x+80, y, Bmp_gg,  Fcolor,color);
                w=x+80+40;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                } 
            case 12: 
                al_index=13; 
                //if(1){
                if(DC_Status[1]&0X03){ //电池温度差异报警
                LCD_DrawImage1BPP(x,    y, Bmp_dc,  Fcolor,color);                 
                LCD_DrawImage1BPP(x+40, y, Bmp_wd,  Fcolor,color);
                LCD_DrawImage1BPP(x+80, y, Bmp_CYi,  Fcolor,color);
                LCD_DrawImage1BPP(x+120,y, Bmp_bj,  Fcolor,color);
                w=x+120+40;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                } 
            case 13: 
                al_index=14; 
                //if(1){
                if( (DC_Status[1]&0X10) ||  //车载储能装置类型过压报警
                    (DC_Status[1]&0X20)     //车载储能装置类型欠压报警
                  ){ 
                LCD_DrawImage1BPP(x,     y, Bmp_CZCNZZ,  Fcolor,color);
                LCD_DrawImage1BPP(x+119, y, Bmp_LXing,   Fcolor,color);
                if(DC_Status[1]&0X10)LCD_DrawImage1BPP(x+158, y, Bmp_Guo,     Fcolor,color);
                else                 LCD_DrawImage1BPP(x+158, y, Bmp_Qian,    Fcolor,color);
                LCD_DrawImage1BPP(x+174, y, Bmp_Ya,      Fcolor,color);         
                w=x+174+16;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                }
            case 14: 
                al_index=15; 
                //if(1){
                if(DC_Status[4]&0X04){ //车载储能装置类型过充
                LCD_DrawImage1BPP(x,     y, Bmp_CZCNZZ,  Fcolor,color);
                LCD_DrawImage1BPP(x+119, y, Bmp_LXing,   Fcolor,color);
                LCD_DrawImage1BPP(x+158, y, Bmp_Guo,     Fcolor,color);
                LCD_DrawImage1BPP(x+174, y, Bmp_cdian,   Fcolor,color);         
                w=x+174+17;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                } 
            case 15: 
                al_index=16; 
                //if(1){
                if((VCU_Status[4]==0X01)){ //正在充电 
                LCD_DrawImage1BPP(x,    y, Bmp_ZZai,  Fcolor,color);
                LCD_DrawImage1BPP(x+40, y, Bmp_cdian,  Fcolor,color);
                w=x+40+40;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                }   
            case 16: 
                al_index=17; 
                //if(1){
                if(DC_Status[3]&0X03){ //电池组低温报警 
                LCD_DrawImage1BPP(x,    y, Bmp_dc,  Fcolor,color);
                LCD_DrawImage1BPP(x+40, y, Bmp_Zu,  Fcolor,color);       
                LCD_DrawImage1BPP(x+56, y, Bmp_wd,  Fcolor,color);
                LCD_DrawImage1BPP(x+96, y, Bmp_gd,  Fcolor,color);                
                w=x+96+40;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                }                              
            case 17: 
                al_index=18; 
                //if(1){
                if(DC_Status[2]&0X20){ //电池SOC跳变
                LCD_DrawImage1BPP(x,    y, Bmp_dc,    Fcolor,color);
                LCD_DrawImage1BPP(x+40, y, Bmp_SOC,   Fcolor,color);
                LCD_DrawImage1BPP(x+72, y, Bmp_TBian, Fcolor,color);                
                w=x+72+40;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                }                  
            case 18: 
                al_index=19; 
                //if(1){
                if(DC_Status[2]&0X40){ //可充电储能系统不匹配
                LCD_DrawImage1BPP(x,    y, Bmp_Ke,    Fcolor,color);
                LCD_DrawImage1BPP(x+16, y, Bmp_cdian, Fcolor,color);
                LCD_DrawImage1BPP(x+56, y, Bmp_CNeng, Fcolor,color);  
                LCD_DrawImage1BPP(x+96, y, Bmp_xt,    Fcolor,color);             
                LCD_DrawImage1BPP(x+136,y, Bmp_BPPei, Fcolor,color);         
                w=x+136+56;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                }   
            case 19: 
                al_index=20; 
                //if(1){
                if(DC_Status[6]==0x01){ //单体电压互差报警
                LCD_DrawImage1BPP(x,    y, Bmp_dt,    Fcolor,color);
                LCD_DrawImage1BPP(x+40, y, Bmp_DY, Fcolor,color);
                LCD_DrawImage1BPP(x+80, y, Bmp_HCha, Fcolor,color);  
                LCD_DrawImage1BPP(x+120,y, Bmp_bj,    Fcolor,color);                    
                w=x+120+40;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                }        
            case 20: 
                al_index=21; 
                //if(1){                          //整车绝缘报警               
                if( ((JY_Status[0]&0x03)>0) ||  //正极绝缘报警
                    ((JY_Status[0]&0x0C)>0)     //负极绝缘报警 
                    ){ 
                LCD_DrawImage1BPP(x,    y, Bmp_ZChe,    Fcolor,color);
                LCD_DrawImage1BPP(x+40, y, Bmp_jy,   Fcolor,color);
                LCD_DrawImage1BPP(x+80, y, Bmp_bj, Fcolor,color);                
                w=x+80+40;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                }                      
            case 21: 
                al_index=22; 
                //if(1){
                if((MCU_Status[1]&0x01)  //驱动电机控制器温度报警
                  ){ 
                LCD_DrawImage1BPP(x,    y, Bmp_dj,    Fcolor,color);
                LCD_DrawImage1BPP(x+40, y, Bmp_kzq,   Fcolor,color);
                LCD_DrawImage1BPP(x+96, y, Bmp_wd,    Fcolor,color); 
                LCD_DrawImage1BPP(x+136,y, Bmp_gg,    Fcolor,color);                 
                w=x+136+40;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                }                     
            case 22: 
                al_index=23; 
                //if(1){
                if((MCU_Status[1]&0x02)    //驱动电机温度报警
                  ){ 
                LCD_DrawImage1BPP(x,    y, Bmp_dj,    Fcolor,color);
                LCD_DrawImage1BPP(x+40, y, Bmp_wd,    Fcolor,color); 
                LCD_DrawImage1BPP(x+80, y, Bmp_gg,    Fcolor,color);                 
                w=x+80+40;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                }                                   
            case 23: 
                al_index=24; 
                //if(1){
                if(M_ON  && mKH1){    //变频器故障  && IN1
                LCD_DrawImage1BPP(x,    y, Bmp_BPQi,  Fcolor,color);
                LCD_DrawImage1BPP(x+56, y, Bmp_ST[0], Fcolor,color);              
                w=x+56+40;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                }  
            case 24: 
                al_index=0; 
                //if(1){
                if(DC_Status[0]&0X0C){    //内部总线状态  
                LCD_DrawImage1BPP(x,    y, Bmp_dc,  Fcolor,color);
                LCD_DrawImage1BPP(x+40, y, Bmp_nb,  Fcolor,color);    
                LCD_DrawImage1BPP(x+80, y, Bmp_ZXian, Fcolor,color);                    
                LCD_DrawImage1BPP(x+120,y, Bmp_ST[0], Fcolor,color);              
                w=x+120+40;LCD_DrawRect(w, y, 250-w, 36, color);
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
        //    frmMHQ();
            break;
        case 7:
        //    frmDebug();
            break;      
        case 8:
        //    frmAir();
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



