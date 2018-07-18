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


void print_SZ(unsigned int x, unsigned int y, //��ʾ����λ�� 
        unsigned long dat, //��ʾ������ 
        unsigned char sum, //��ʾ���ݵļ�λ
        unsigned char dot, //��ʾС�����λ��
        unsigned char color1) { //��ʾ���ݵ���ɫ
    unsigned char color, f = 1, i = 0;
    unsigned char bcd[8];
    for (i = 0; i < sum; i++) {
        bcd[sum - i - 1] = dat % 10;
        dat = dat / 10;
    }
    for (i = 0; i < dot; i++) {
        bcd[sum - i] = bcd[sum - 1 - i];
    }
    bcd[sum - dot] = 16; //����С����  
    if (dot > 0) {
        for (i = 0; i <= sum; i++) {
            if (f && (bcd[i] == 0)&&(i < sum - 1 - dot)) { //����ʾǰ��0
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
            if (f && (bcd[i] == 0)&&(i < sum - 1)) { //����ʾǰ��0
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

/*
void print_SZ_1(unsigned int x, unsigned int y, //��ʾ����λ��//��������
        unsigned long dat, //��ʾ������ 
        unsigned char sum, //��ʾ���ݵļ�λ
        unsigned char dot, //��ʾС�����λ��
        unsigned char color1) { //��ʾ���ݵ���ɫ
    unsigned char color, f = 1, i = 0;
    unsigned char bcd[8];
    for (i = 0; i < sum; i++) {
        bcd[sum - i - 1] = dat % 10;
        dat = dat / 10;
    }
    for (i = 0; i < dot; i++) {
        bcd[sum - i] = bcd[sum - 1 - i];
    }
    bcd[sum - dot] = 16; //����С����  
    if (dot > 0) {
        for (i = 0; i <= sum; i++) {
            if (f && (bcd[i] == 0)&&(i < sum - 1 - dot)) { //����ʾǰ��0
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
            if (f && (bcd[i] == 0)&&(i < sum - 1)) { //����ʾǰ��0
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

void print_SZ_2(unsigned int x, unsigned int y, //��ʾ����λ�� 
        unsigned long dat, //��ʾ������ 
        unsigned char sum, //��ʾ���ݵļ�λ
        unsigned char dot, //��ʾС�����λ��
        unsigned char color1) { //��ʾ���ݵ���ɫ
    unsigned char color, f = 1, i = 0;
    unsigned char bcd[8];
    for (i = 0; i < sum; i++) {
        bcd[sum - i - 1] = dat % 10;
        dat = dat / 10;
    }
    for (i = 0; i < dot; i++) {
        bcd[sum - i] = bcd[sum - 1 - i];
    }
    bcd[sum - dot] = 10; //����С����  
    if (dot > 0) {
        for (i = 0; i <= sum; i++) {
            if (f && (bcd[i] == 0)&&(i < sum - 1 - dot)) { //����ʾǰ��0
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
            if (f && (bcd[i] == 0)&&(i < sum - 1)) { //����ʾǰ��0
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
void print_SZ_4(unsigned int x, unsigned int y, //��ʾ����λ�� //�Ŵ�4������
        unsigned long dat, //��ʾ������ 
        unsigned char sum, //��ʾ���ݵļ�λ
        unsigned char dot, //��ʾС�����λ��
        unsigned char color1) { //��ʾ���ݵ���ɫ
    unsigned char color, f = 1, i = 0;
    unsigned char bcd[8];
    for (i = 0; i < sum; i++) {
        bcd[sum - i - 1] = dat % 10;
        dat = dat / 10;
    }
    for (i = 0; i < dot; i++) {
        bcd[sum - i] = bcd[sum - 1 - i];
    }
    bcd[sum - dot] = 16; //����С����  
    if (dot > 0) {
        for (i = 0; i <= sum; i++) {
            if (f && (bcd[i] == 0)&&(i < sum - 1 - dot)) { //����ʾǰ��0
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
            if (f && (bcd[i] == 0)&&(i < sum - 1)) { //����ʾǰ��0
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


void print_D(unsigned int x, unsigned int y, //��2������ʾ
        unsigned char dat) { //��ʾ������       
    unsigned char bcd[8], i = 0;
    for (i = 0; i < 8; i++) {
        bcd[i] = dat % 2;
        dat = dat / 2;
      //LCD_DrawImage1BPP(x + 16 * (7 - i), y, BMP_SZ_1[bcd[i]], WHITE, BLACK);
        LCD_DrawImage1BPP(x + 16 * (7 - i), y, BMP_SZ_3[bcd[i]], WHITE, BLACK);
    }
}


void print_H(unsigned int x, unsigned int y, //��16������ʾ
        unsigned long dat, //��ʾ������ 
        unsigned char sum, //��ʾ���ݵļ�λ
        unsigned char dot, //��ʾС�����λ��
        unsigned char color1) { //��ʾ���ݵ���ɫ
    unsigned char color, f = 1, i = 0;
    unsigned char bcd[8];
    for (i = 0; i < sum; i++) {
        bcd[sum - i - 1] = dat % 16;
        dat = dat / 16;
    }
    for (i = 0; i < dot; i++) {
        bcd[sum - i] = bcd[sum - 1 - i];
    }
    bcd[sum - dot] = 16; //����С����  
    if (dot > 0) {
        for (i = 0; i <= sum; i++) {
            if (f && (bcd[i] == 0)&&(i < sum - 1 - dot)) { //����ʾǰ��0
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
            if (f && (bcd[i] == 0)&&(i < sum - 1)) { //����ʾǰ��0
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
void disp_rectange(unsigned int x,unsigned int y, //��ʾ����λ��
                     unsigned int w,unsigned int h,   //��ʾ���εĳ��ȺͿ��
                     unsigned int dot,                //��ʾ���������Ŀ��
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
    // + �� ǧ �� ʮ ��
    // 0 1  2  3  4  5 
     num=0;
     for(i=6-NUM;i<5;i++){       
      if(bcd[i]==0) num++; //��Чλǰ����ĸ���
      else          break;
     }
     if(num==NUM) bcd[4]=s; //ȫ����
     else         bcd[5-(NUM-num)]=s; //
  
     for(i=0;i<NUM+1;i++){
      if(5-NUM+i<5-(NUM-num)) color1=BLACK;
      else                    color1=color;
      LCD_DrawImage1BPP(x+i*16, y,BMP_SZ_3[bcd[5-NUM+i]],color1,BLACK); //������ 
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

void LCD_DrawImageSBPP(unsigned int x, unsigned int y, //û�����֣�������0����ģΪBMP_BLANK       
                       //unsigned char witdh, //������
                         __prog__ const unsigned char *img[], //�ַ����׵�ַ
                         unsigned char fcolor, //����ǰ��ɫ
                         unsigned char bcolor  //���屳��ɫ
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
        if (t_add) {//Сʱ���ã�ʮλ
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
        if (t_add) {//Сʱ���ã���λ
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
        if (t_add) {//�������ã�ʮλ
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
        if (t_add) {//�������ã���λ
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
    LCD_DrawImage1BPP(x + 28 * 2, y + 3, BMP_SMSZ[10], color, BLACK); //ð�� 

    if (time_flag) {
        color_back = FLASH;
    } else {
        color_back = 0;
        t = 0;
    }

    /*****************���������ӽ�����ʾ**********************/
    //if (frmID == 1) {
        LCD_DrawImage1BPP(x + 260, y-2, BMP_SZ_1[2], WHITE, BLACK); //2
        LCD_DrawImage1BPP(x + 260 + 16, y-2, BMP_SZ_1[0], WHITE, BLACK); //0

        if (color_back && (t == 4)) {
            if (t_add) {//�����ã�ʮλ
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
            if (t_add) {//�����ã���λ
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
            if (t_add) {//�����ã�ʮλ
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
            if (t_add) {//�����ã���λ
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
            if (t_add) {//�����ã�ʮλ
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
            if (t_add) {//�����ã���λ
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
    LCD_DrawImage1BPPZOOM_4(610 + 18 * 2, 440, BMP_SZ[(dtimer.year >> 4)&0x0f], WHITE, BLACK); //��
    LCD_DrawImage1BPPZOOM_4(610 + 18 * 3, 440, BMP_SZ[dtimer.year & 0x0f], WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(610 + 18 * 4, 440, BMP_SZ[17], WHITE, BLACK); //-
    LCD_DrawImage1BPPZOOM_4(610 + 18 * 5, 440, BMP_SZ[(dtimer.month >> 4)&0x0f], WHITE, BLACK); //��
    LCD_DrawImage1BPPZOOM_4(610 + 18 * 6, 440, BMP_SZ[dtimer.month & 0x0f], WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(610 + 18 * 7, 440, BMP_SZ[17], WHITE, BLACK); //-
    LCD_DrawImage1BPPZOOM_4(610 + 18 * 8, 440, BMP_SZ[(dtimer.day >> 4)&0x0f], WHITE, BLACK); //��
    LCD_DrawImage1BPPZOOM_4(610 + 18 * 9, 440, BMP_SZ[dtimer.day & 0x0f], WHITE, BLACK);
     */
}

void frmTIME_SET( void ){     
    if (f_index == 0) { //ֻ����һ��
        f_index = 1;  
        time_flag = 1;
        LCD_Clear();
        LCD_DrawRect(0, 56,  800, 2, GRAY); //�������� 
        LCD_DrawImage1BPP(360, 30, Bmp_SJSZ, GREEN, BLACK);
    } else if (f_index == 1) {
        f_index = 1;
        disp_time(330-120, 440-200, timer);
    } else {
        f_index = 0;
    }
    
    if (key_up) { //�Ӳ˵��л�
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
    
    if (key_long_set) {//���˵�/�Ӳ˵��л�
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
    unsigned int press1 = 50; //��ѹ������������0-1.2Mpa ,��ӦΪ0-120 ������0-100
    unsigned int press2 = 90; //��ѹ������������0-1.2Mpa ,��ӦΪ0-120 ������0-100
    if (ADR[1] < 10) press1 = 0;
    else if (ADR[1] <= 52) press1 = (ADR[1] - 10)*0.48;
    else if (ADR[1] <= 124) press1 = (ADR[1] - 52)*0.56 + 20;
    else if (ADR[1] <= 155) press1 = (ADR[1] - 124)*0.65 + 60;
    else press1 = (ADR[1] - 155)*0.69 + 80;
    //press1 = ADR[4] / 27; //��ѹ�Ͳ���   0-5V
    //press2 = ADR[5] / 27;//��ѹ�Ͳ���   0-5V

    if (press1 > 60) color = GREEN;
    else color = RED;
    if (press1 > 100) press1 = 100;
    print_SZ(33 - 7, 410 + 13, press1, 3, 2, color);
    LCD_DrawImage1BPP(33 + 9, 380 + 13, Bmp_QY1, color, BLACK); //��ѹ1ͼ��
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
    LCD_DrawImage1BPP(712 + 9, 380 + 13, Bmp_QY2, color, BLACK); //��ѹ2ͼ��
    print_SZ(712 - 7, 410 + 13, press2, 3, 2, color);
    LCD_DrawRect(712 + 5, 102 + 13, 44, (260 - press2 * 2.6), BLACK); //260/100  
    LCD_DrawRect(712 + 5, (368 + 13 - press2 * 2.6), 44, (press2 * 2.6), color);
}



void updata_DCDY(unsigned int x, unsigned int y) {
    //unsigned char color = GREEN;
    unsigned int DCDY = 50;
    DCDY = DC_voltage * 0.1;
 
    if (DCDY >= 800) DCDY = 800;
    print_SZ_1(x, y, (DCDY), 3, 0, WHITE); //��ص�ѹ��ֵ x=120+72+30   y=150+60-2
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
            LCD_DrawRect(225 + 83 + 83 + 2, 100 +13+ 5 + 2 + 60 - 5, (DCDL * 1.65 * 0.2), 28, GREEN); // �������Ϊ0�������
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
    print_SZ_1(585, 100 + 13 + 5 + 60 + 60 - 10, soc, 3, 0, WHITE); //SOC��ֵ
    LCD_DrawRect(225 + 2, 100 + 13 + 5 + 60 + 60 + 2 - 10, (soc * 3.31), 28, color); // 331/100  
    if (soc < 100)//��socΪ100ʱ�����//��ʱ�������
        LCD_DrawRect((225 + 2 + soc * 3.31), 100 + 13 + 5 + 60 + 60 + 2 - 10, (331 - soc * 3.31), 28, BLACK);
}
*/


//��������λ��
  unsigned int X=400-478/2;
//unsigned int Y=182-140/2;   //����״SOC
  unsigned int Y=182-140/2+15;//����״SOC

//��ʾ����
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
 //������������
 //�󳵶�   
  x=30;y=10;    
  lcd_show_1color(X+x, Y+y,26,2,WHITE);//-
  x=56;y=0;    
  lcd_show_1color(X+x, Y+y,2,11,WHITE);//|
  lcd_show_1color(X+x, Y+y,24,2,WHITE);//-
  x=80;y=0;    
  lcd_show_1color(X+x, Y+y,2,10,WHITE);//|
  x=80;y=10;    
  lcd_show_1color(X+x, Y+y,259,2,WHITE);//-
  //�ҳ���
  x=339;y=0;    
  lcd_show_1color(X+x, Y+y,2,10,WHITE);//|   
  lcd_show_1color(X+x, Y+y,24,2,WHITE);//-
  x=362;y=0;    
  lcd_show_1color(X+x, Y+y,2,10,WHITE);//|
  x=362;y=10;    
  lcd_show_1color(X+x, Y+y,72,2,WHITE);//-
  //�ڶ���
  x=30;y=20-1;    
  lcd_show_1color(X+x, Y+y,404,2,WHITE);//-
  //������
  x=0;y=52;    
  lcd_show_1color(X+x, Y+y,199,2,WHITE);//-
  x=247;y=52;    
  lcd_show_1color(X+x, Y+y,95,2,WHITE);//-
  //������
  x=30;y=125-2;    
  lcd_show_1color(X+x, Y+y,78,2,WHITE);//-
  x=152;    
  lcd_show_1color(X+x, Y+y,168,2,WHITE);//-
  x=364;    
  lcd_show_1color(X+x, Y+y,84,2,WHITE);//-
  //����
  x=0;y=40;    
  lcd_show_1color(X+x, Y+y,2,55,WHITE);//|
  //����
  x=478-2;y=57;    
  lcd_show_1color(X+x, Y+y,2,38,WHITE);//|
/*
  //����
  x=199;y=31;    
  lcd_show_1color(X+x, Y+y,48,2,WHITE);//-
  lcd_show_1color(X+x, Y+y,2,88,WHITE);//|
  x=199+48-2;y=31;    
  lcd_show_1color(X+x, Y+y,2,88,WHITE);//|
  x=199;y=31+88-2;
  lcd_show_1color(X+x, Y+y,48,2,WHITE);//-

  //ǰ��
  x=383;y=31;    
  lcd_show_1color(X+x, Y+y,27,2,WHITE);//-
  lcd_show_1color(X+x, Y+y,2,88,WHITE);//|
  x=383+48-2;y=31+30;    
  lcd_show_1color(X+x, Y+y,2,58,WHITE);//|
  x=383;y=31+88-2;
  lcd_show_1color(X+x, Y+y,48,2,WHITE);//-

*/

x=51-40;y=79-9;
  //lcd_show_9dot(X+x,   Y+y,  Bmp_main_interface_1_L_1,  WHITE,BLACK);//��ʻ���
x=176-12;
  //lcd_show_8dot(X+x, Y+y,  Bmp_Km,  WHITE,BLACK);//��λ Km
x=276-16;
  lcd_show_8dot(X+x, Y+y,  Bmp_SOC, WHITE, BLACK);//SOC
x=364-8;
  lcd_show_8dot(X+x, Y+y,  Bmp_bfh, WHITE, BLACK);//%

}

void mainFrame(void) {
    unsigned int i;
    LCD_Clear();
    LCD_DrawRect(0, 430, 800, 2, GRAY);//�ײ�����
    LCD_DrawRect(0, 0,   800, 1, GRAY);//�Ϻ���
    LCD_DrawRect(0, 50,  800, 1, GRAY);//�º���
    
    /*
    LCD_DrawRect(70+66,100,528,1,GRAY);//�ڶ�����   
    for (i = 1; i < 12; i++) {
        LCD_DrawRect(4 +  66 * i, 0, 1, 50, GRAY);//����
    }
    for(i=1;i<10;i++)
        LCD_DrawRect(70+66*i,50,1,50,GRAY);//����
    */
    
    LCD_DrawRect(122,100,550,1,GRAY);//�ڶ�����
    for(i=1;i<13;i++)
    LCD_DrawRect(61*i,0,1,50,GRAY);//����

    for(i=2;i<12;i++)
    LCD_DrawRect(61*i,50,1,50,GRAY);//����

   
    //ÿ�ν��������棬����Ƭ��ɫ���ǻ�ɫ����������ֻ���һ���ϵ���ʾ��ɫ����ҳ��Ͳ���ʾ��ɫ
    for (i = 0; i < 24; i++) {
        color_old[i] = 1;
    }
    
//LCD_DrawImage1BPPZOOM_4(336, 150, BMP_LOGO, BLUE, BLACK); //�ͳ�����

x=161;y=265;
   for(i=1;i<5;i++){
   lcd_show_1color(x,y+i*30,478, 1,GRAY);//-
   }
x=161;y=y+30;
   lcd_show_1color(x,y,1, 90,GRAY);//|��
x=391+9;
   lcd_show_1color(x,y,1, 90,GRAY);//|��
x=639;
   lcd_show_1color(x,y,1, 90,GRAY);//|��

//��һ��
x=221-58;y=280-9;
y=280-9+1*30; 
   lcd_show_9dot(x,       y, Bmp_main_interface_2_L_1, WHITE,0x0000);//������ص�ѹ
   lcd_show_8dot(x+208-16,y, Bmp_V,   WHITE, BLACK);//
y=280-9+2*30;
   lcd_show_9dot(x,       y, Bmp_main_interface_2_L_2, WHITE,0x0000);//������ص���
   lcd_show_8dot(x+208-16,y, Bmp_A,   WHITE, BLACK);//
y=280-9+3*30;
   lcd_show_9dot(x,       y, Bmp_main_interface_2_L_3, WHITE,0x0000);//���ת��
   lcd_show_8dot(x+208-16,y, Bmp_RPM, WHITE,0x0000);

//�ڶ���
x=433-40+9;y=280-9;
y=280-9+1*30;
   //lcd_show_9dot(x,       y, Bmp_main_interface_2_R_1, WHITE,0x0000);//����Һλ  ���綯��ȥ��
   //lcd_show_8dot(x+217,   y, Bmp_bfh,  WHITE, BLACK);//
y=280-9+2*30;
   lcd_show_9dot(x,       y, Bmp_main_interface_2_R_2, WHITE,0x0000);//﮵�ع��ϵȼ�
y=280-9+3*30;
   lcd_show_9dot(x,       y, Bmp_main_interface_2_R_3, WHITE,0x0000);//ϵͳ����   
    
//��ʾ���
x=221-58;y=407-9;
   lcd_show_9dot(x,       y, Bmp_main_interface_3_L_1, WHITE,0x0000);//�������   
x=440-40; 
   lcd_show_9dot(x,       y, Bmp_main_interface_3_R_1, WHITE,0x0000);//�ܼ����
x=369-12;   
   LCD_DrawImage1BPP(x,   y,Bmp_Km,    WHITE,BLACK);//��λ Km  
x=617-12;      
   LCD_DrawImage1BPP(x,   y,Bmp_Km,    WHITE,BLACK);//��λ Km
     
    
}

void update_dc2(void){
   unsigned char color=0,s=0;
   unsigned int  temp;
   unsigned int  x,y;
 //unsigned char i,j;
/////////////��һ��/////////////
x=333-32-16;y=280-9;
//����ܵ�ѹ
  temp=DC_voltage/10;
  if(temp>=1000){
     temp=(temp-1000);s=12;
    }else{
     temp=(1000-temp);s=11;
    }
  update_dl(x,    y+1*30,temp,3,s,WHITE);
//��ŵ����
  temp=DC_current/10;
  if(temp>=1000){
     temp=(temp-1000);s=12;
    }else{
     temp=(1000-temp);s=11;
    }
  update_dl(x,    y+2*30,temp,3,s,WHITE);
//���ת��
  temp=DJ_speed>>1;
  print_SZ_2(x,    y+3*30,temp,4,0,WHITE);

/////////////�ڶ���/////////////
x=581-32;y=280-9;  
//����Һλ 
  //if(urea_high<=250)temp=(0.4*urea_high);//����Һλ
  //print_SZ_2(x,y+1*30,temp,4,0,WHITE);
//﮵�ع��ϵȼ�
  temp=DC_fault; 
  if(temp==0)color=WHITE;else color=RED; 
  print_SZ_2(x,y+2*30,temp,4,0,color);

//ϵͳ���� 80,180
//ϵͳ���룺����ID��0x0C04A1A7��ϵͳ���롱, ������ɫ����ID��0x0C04A1A7��ϵͳ����״̬��������ɫ���壬��
//������1�����ϣ������У�2�����ϣ����޹���3����4�����ϣ���������5�����޹��ϣ�����״̬��
//���������� ��ʾΪ��ɫ���޹� ��ʾΪ��ɫ������ ��ʾΪ��ɫ������ɸ��ݡ����ϴ��������ȼ��������֣�
  switch(system_state&0x30){
    case 0x00: color=GREEN; 
    break;
    case 0x10:color=YELLOW;
    break;
    case 0x20:color=RED; 
    break;
    case 0x30:color=RED; 
    break;
   }
   print_SZ_2(x-16,y+3*30,system_fault,5,0,color);

  x=130-28;y=37-12;
  if((system_state&0x30)==0x00)color=GREEN;
//if(system_fault!=0)          color=GREEN;
  else                         color=GRAY;
  lcd_show_8dot(X+x, Y+y,Bmp_READY,color,BLACK);//READY

//SOC
  if(DC_Status[0]&0X08)color=RED;//���SOC����
  else                 color=GREEN;  
  //temp=1.2*DC_SOC;
  //if(temp>300)temp=300; 
  //lcd_show_1color(180+43,250+4-20+30,temp,24,color); // |
  //lcd_show_1color(180+43+temp,250+4-20+30,300-temp,24,BLACK); // |

  if(color==GREEN)color=WHITE;
  //print_SZ_2(180+50+16+300,236+30,(0.4*DC_SOC),3,0,color); // 0

//�����ڲ�SOC
  x=326-24;y=79-9;
  print_SZ_2(X+x, Y+y,(0.4*DC_SOC),3,0,color); // 

  //����
  if(mKH1)color=RED;else color=WHITE;
  x=199;y=31;    
  lcd_show_1color(X+x, Y+y,48,2,color);//-
  lcd_show_1color(X+x, Y+y,2,88,color);//|
  x=199+48-2;y=31;    
  lcd_show_1color(X+x, Y+y,2,88,color);//|
  x=199;y=31+88-2;
  lcd_show_1color(X+x, Y+y,48,2,color);//-
  if(mKH1)color=BLACK;else color=WHITE;
  x=199+2;y=61;
  lcd_show_1color(X+x, Y+y,44,2,color);//-
  x=199+24-1;y=31+2;
  lcd_show_1color(X+x, Y+y,2,84,color);//|

  //ǰ��
  if(mKL15)color=BLACK;else color=WHITE;  
  x=407-24;y=69-6;
  if (color_old[4] != color) {
      color_old[4]  = color;
  lcd_show_8dot5(X+x, Y+y,  Bmp_CAR7, color, BLACK); //
  }  
  
  if(mKL15)color=RED;else color=WHITE;
  x=383;y=31;    
  lcd_show_1color(X+x, Y+y,27,2,color);//-
  lcd_show_1color(X+x, Y+y,2,88,color);//|
  x=383+48-2;y=31+30;    
  lcd_show_1color(X+x, Y+y,2,58,color);//|
  x=383;y=31+88-2;
  lcd_show_1color(X+x, Y+y,48,2,color);//-
  x=420-11;y=46-15;
  lcd_show_8dot(X+x, Y+y,  Bmp_CAR6, color, BLACK); //

  //�����
  if(mKL12)color=RED;else color=BLACK;
  x=24;y=66-14;
  lcd_show_8dot5(X-x, Y+y,  Bmp_CAR9, color, BLACK); //

//��ʻ���
  x=131-24;y=79-9;
  //temp=XHLC*5; 
  //if(temp>=1000)temp=999;
  //print_SZ_2(X+x, Y+y,temp,3,0,WHITE);

      
}
void disp_baojing2(void){
  unsigned char i,color=GRAY;
  unsigned char temp8=0;
        
  if( (TYBJ_state[1]&0x80)||  //��������������¶ȱ���
      (TYBJ_state[2]&0x02)||  //��������¶ȱ���
      (TYBJ_state[4]&0X40)||  //����������
      (TYBJ_state[5]&0X01)    //�������
     )color=RED;else color=GRAY;
  LCD_DrawImage1BPP(122+10, 10+50,Bmp_DJGRe,color,BLACK);//������� 
  
  if(mKL2) color=YELLOW;
  else     color=GRAY; 
  //LCD_DrawImage1BPP(274-20,75-20,Bmp_ml,color,BLACK);//���忪�� 
  if( YW_Status[1]>0 ) color=RED;
  else                 color=GRAY; 
  LCD_DrawImage1BPP(274-16,75-18,Bmp_YW,color,BLACK);//������   
  
//if((DR_state&0X80)==0x00)color=RED;//���߼�
//if((DR_state&0X80))      color=RED;//���߼� 
  if((DC_Status[3]&0X08)==0x00)color=RED;//���߼�  MSD
  else                         color=GRAY; 
  lcd_show_8dot(336-28,75-12,Bmp_MSD,color,BLACK);//��ѹ���� 

  switch(DR_state&0X0F){
   case 0x00:color=GREEN;i=0;
   break;
   case 0x0D:color=RED;i=1;
   break;
   case 0x0E:color=GREEN;i=2;
   break;  
   default: color=GRAY;i=0;
   break; 
  }
  lcd_show_8dot(384,62,Bmp_NRD[i],color,BLACK);//D  

  if(KEY_state&0X10)color=GREEN;
  else              color=GRAY; 
  lcd_show_8dot(458-24,75-11,Bmp_AC,color,BLACK);//AC

  if(DR_state&0X10)color=ORANGE;
  else             color=GRAY; 
  lcd_show_8dot(519-8,75-12,Bmp_S,color,BLACK);//����
    
  lcd_show_8dot(559,57,Bmp_ms[(DR_state&0X60)>>5],GREEN,BLACK);//���� ��� ���
  lcd_show_8dot(559,77,Bmp_ms[3],GREEN,BLACK);//ģʽ

  if(YZT_LIFE==0xFF)color=GREEN;
  else              color=RED; 
  lcd_show_8dot(640-12,65-6,Bmp_GPRS,color,BLACK);//
  lcd_show_1color(640-12+11, 65-6+12,2,20,color);//|
  
}

void disp_baojing(void){
  unsigned char color=GRAY;
  unsigned int  temp;
  
  if(mKL4 ) color=RED;
  else             color=GRAY; 
  LCD_DrawImage1BPP(30-20,5,Bmp_yjf,color,BLACK);//Ӧ���������������� 
  
  if(!rKL4)color=RED;//��ǰ 
  else     color=GRAY; 
  if (color_old[0] != color) {
      color_old[0]  = color;
  LCD_DrawImage1BPP(73, 7,Bmp_mcpL,color,BLACK);//��Ƭĥ��
  LCD_DrawImage1BPP (93,16,BMP_SZ[1],color,BLACK);
  }
  
  if(!rKL7)color=RED;//���  
  else     color=GRAY;
  if (color_old[1] != color) {
      color_old[1]  = color;
  //LCD_DrawImage1BPP(133, 7,Bmp_mcpL,color,BLACK);//��Ƭĥ��
  //LCD_DrawImage1BPP (153,16,BMP_SZ[2],color,BLACK); 
  }
  
  
  if(  mKL12 ) color=RED;
  else         color=GRAY; 
  LCD_DrawImage1BPP(216-28,25-24,Bmp_HCM,color,BLACK);//�����
 
  if(  rKL1 ) color=RED;
  else        color=GRAY; 
//LCD_DrawImage1BPP(275-18,25-18,Bmp_SW,color,BLACK);//ˮλ����

  if(DC_Status[1]&0X20)color=RED;
  else                 color=GRAY; 
  lcd_show_8dot(336-24,25-18,Bmp_DCGR,color,BLACK);//��ع���

  if(DC_Status[3]&0X01)color=RED;
  else                 color=GRAY; 
  lcd_show_8dot(397-24,25-18,Bmp_DCHZ,color,BLACK);//��ػ���

   //һ�����Ϻ�ɫ   �������������ϰ�ɫ   ͣ���������
  if(eror_R==1)     color=RED;
  else if(eror_R==2)color=WHITE;
  else              color=GRAY;   
  LCD_DrawImage1BPP(457-14, 25-20,Bmp_jygz,color,BLACK);//��Ե���ϱ���
  
  temp=(system_state&0x30)>>4;//���кͽ���ʱ
  if((temp==2)||(temp==3))color=RED; 
  else                    color=GRAY; 
  LCD_DrawImage1BPP(518-20, 25-15,Bmp_XTgz,color,BLACK);//ϵͳ����
  
  if((DC_Status[2]&0X02)==0x00)color=YELLOW; 
  else                          color=GRAY; 
  LCD_DrawImage1BPP(580-20, 25-14,Bmp_DCQDuan,color,BLACK);//����ж� 

  if(!rKL5) color=RED; //��ǰ  
  else      color=GRAY; 
  if (color_old[2] != color) {
      color_old[2]  = color;
  LCD_DrawImage1BPP(622, 7,Bmp_mcpR,color,BLACK);//��Ƭĥ��
  LCD_DrawImage1BPP (642,16, BMP_SZ[1],color,BLACK);
  }
  
  if(!rKL9) color=RED; //�Һ� 
  else      color=GRAY; 
  if (color_old[3] != color) {
      color_old[3]  = color;
  //LCD_DrawImage1BPP(682, 7,Bmp_mcpR,color,BLACK);//��Ƭĥ��
  //LCD_DrawImage1BPP (702,16, BMP_SZ[2],color,BLACK);
  }
  

}

void disp_miles(void) {//��ʾ���
x=333-32-16-16;y=407-9;
    print_SZ_2(x, y,single_miles , 4, 1, WHITE);
x=552-49-16;    
    print_SZ_2(x, y, total_miles / 10, 7, 0, WHITE);
}

void frmMain(void) {
  //unsigned char color;
    if (f_index == 0) { //ֻ����һ��
        f_index = 1;
        mainFrame(); 
        disp_CAR();
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
    } else if (f_index == 5) {
        f_index = 6;
        //updata_SOC();
    } else if (f_index == 6) {
        f_index = 7;
        //updata_DCDY(585, 105 + 13);//
    } else if (f_index == 7) {
        f_index = 1;      
    } else {
        f_index = 0;
    }

    if (AV_CH == 0) { //�������ֽ���
        if (key_up) { //���ڱ����
            key_up = 0;
            if ((LED15 == 1) && (!time_flag) ) {//���⿪��
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
        if (IN35 == 0) {//��������ѡ��ʹ�ܰ���
            if (IN11 && R_flag == 0) {//����
                key_AV = 1; //ģ��AV���ذ�һ��
                AV_CH = 3; //3+1=4  ����
                R_flag = 1; //��ֹһֱ�����������������key_AV������1
            }
            if (IN11 == 0 && R_flag == 1) {
                key_AV = 1;
                AV_CH = 4; //����MCU����
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
                    CS_E = 0; //�ر� 
                    mode = 1; //2,MCU
                    break;
                case 1: //AV2  SP2  CJ2
                    CS_E = 1; //�� 
                    CS_A = 1;
                    CS_B = 1;
                    CS_C = 1;
                    mode = 6; //AV2
                    break;
                case 2: //AV2  SP3  CJ3
                    CS_E = 1; //�� 
                    CS_A = 0;
                    CS_B = 1;
                    CS_C = 1;
                    mode = 6; //AV2
                    break;
                case 3: //AV2  SP4  CJ4
                    CS_E = 1; //�� 
                    CS_A = 1;
                    CS_B = 0;
                    CS_C = 1;
                    mode = 6; //AV2
                    break;
                case 4: //AV1
                    CS_E = 0; //����
                    mode = 2; //4,AV1 
                    break;
                default:
                    CS_E = 0; //�ر� 
                    mode = 1; //2,MCU
                    AV_CH = 0;
                    break;
            }
            LCD_CHS(mode);
        }*/
    }
}

//��ʾ �ӿڱ��
///////////////////////////////////////////////////////////
void disp_ID(unsigned char index,unsigned int *ptr){
  unsigned int j=0,i=0;
  for(j=0;j<2;j++){
    LCD_DrawImage1BPP(20+j*420, 65, Bmp_interface,WHITE,BLACK);//�ӿ�
   if(index){  //
    LCD_DrawImage1BPP(300+j*420,65,Bmp_ZT,WHITE,BLACK);//״̬
   }
   for(i=0;i<10;i++){
     if(*ptr==0)break;  //Ĭ�Ͻӿں�Ϊ0ʱ����Ž�������ߵĲ���ʾ��
      print_SZ_2(22+j*420,93+34*i,*ptr++,2,0,WHITE); 
   }
  }
}
///////////////////////////////////////////////////////////
//��ʾ���� "����" �����Ǳ��ź����� 
//ָ�����  ��ʾ��λ��(x), x=0 ����ʾ����
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

//��ʾ��� 1
void disp_yg(unsigned int x,unsigned int y,unsigned int id){
  LCD_DrawImage1BPP(x,   y,Bmp_yuggua, WHITE,BLACK);
  LCD_DrawImage1BPP(x+40,y,Bmp_yg1[id],WHITE,BLACK);
}

//-----------------------------------------------
//������ʾ�Ǳ����� ״̬ 
//������ id ��ʾ�����
//-----------------------------------------------
void disp_KL1(void){
  unsigned int Iid[20]={4,3,2,1,5,6,7,8,9,10,
                        11,12,13,14,15,16,21,22,23,24};
  disp_ID(0,Iid); //��ʾ���
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
  
//�ڶ��� 
  x=500;y=95;
  LCD_DrawImageSBPP(x,y+0*34,Bmp_IN11,WHITE,BLACK);// 
  LCD_DrawImageSBPP(x,y+1*34,Bmp_IN12,WHITE,BLACK);// 
  LCD_DrawImage1BPP(x,y+2*34,Bmp_IN13,WHITE,BLACK);// 
  
  disp_yg(x,y+3*34,Bmp_IN14);
  disp_yg(x,y+4*34,Bmp_IN15);
  disp_yg(x,y+5*34,Bmp_IN16);  
  
  LCD_DrawImage1BPP(x,y+6*34,Bmp_IN17,WHITE,BLACK);// 
  LCD_DrawImage1BPP(x,y+7*34,Bmp_IN18,WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+8*34,Bmp_IN19,WHITE,BLACK);// 
  LCD_DrawImageSBPP(x,y+9*34,Bmp_IN20,WHITE,BLACK);//
  
  unsigned int Iid1[20]={154,0,0,136,154,120,136,136,136,136,
                         596,596,540,580,580,580,0,0,0,556};
  disp_kg(Iid1);  //��ʾ����
}
//��ʾ�Ǳ���2
void disp_KL2(void){
  unsigned int Iid[20]={17,18,19,20,28,27,26,25,32,31,
                        30,29,10,9,8,7,6,1,11,12};
  disp_ID(0,Iid); //��ʾ���
  x=80;y=95;
  disp_yg(x,y+0*34,Bmp_IN21);
  LCD_DrawImage1BPP(x,y+1*34,Bmp_IN22,WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+2*34,Bmp_IN23,WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+3*34,Bmp_IN24,WHITE,BLACK);
  LCD_DrawImageSBPP(x,y+4*34,Bmp_IN25,WHITE,BLACK);
  LCD_DrawImageSBPP(x,y+5*34,Bmp_IN26,WHITE,BLACK);
  LCD_DrawImageSBPP(x,y+6*34,Bmp_IN27,WHITE,BLACK);
  LCD_DrawImageSBPP(x,y+7*34,Bmp_IN28,WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+8*34,Bmp_IN29,WHITE,BLACK);
  LCD_DrawImageSBPP(x,y+9*34,Bmp_IN30,WHITE,BLACK);
  
//�ڶ��� 
  x=500;y=95;
  LCD_DrawImageSBPP(x,y+0*34,Bmp_IN31,WHITE,BLACK);
  LCD_DrawImageSBPP(x,y+1*34,Bmp_IN32,WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+2*34,Bmp_IN33,WHITE,BLACK); 
  LCD_DrawImage1BPP(x,y+3*34,Bmp_IN34,WHITE,BLACK); 
  LCD_DrawImage1BPP(x,y+4*34,Bmp_IN35,WHITE,BLACK); 
  LCD_DrawImage1BPP(x,y+5*34,Bmp_IN36,WHITE,BLACK); 
  LCD_DrawImage1BPP(x,y+6*34,Bmp_IN37,WHITE,BLACK);
  LCD_DrawImageSBPP(x,y+7*34,Bmp_IN38,WHITE,BLACK);   
  LCD_DrawImage1BPP(x,y+8*34,Bmp_IN39,WHITE,BLACK);
  LCD_DrawImageSBPP(x,y+9*34,Bmp_IN40,WHITE,BLACK);
  
  unsigned int Iid1[20]={160,0,0,0,208,136,136,136,0,208,
                         628,628,0,0,0,0,0,580,540,560,};
  disp_kg(Iid1);  //��ʾ����
}

//��ʾ�Ǳ������ź�
void disp_ADR(void){ 
 unsigned int  j=0,i=0;
 unsigned char Iid[2][8]={ {1,2,3,4,5,6,7,8},
                           {9,15,16,17,18,0,0,0  } };
 
  for(j=0;j<2;j++){
      LCD_DrawImage1BPP(20+j*420, 65, Bmp_interface,WHITE,BLACK);//�ӿ�      
   for(i=0;i<8;i++){
     if(Iid[j][i]==0)break;  //Ĭ�Ͻӿں�Ϊ0ʱ����Ž�������ߵĲ���ʾ�� 
      print_SZ_2(20+j*420,95+34*i,Iid[j][i],2,0,WHITE);       
   }
  }  
    
     LCD_DrawImage1BPP(20+420,95+5*34,Bmp_cxbb,WHITE,BLACK);  //����汾
     print_SZ_2(20+420,95+6*34,                Version_date,8,0,YELLOW);//ʱ��
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

  //CAN �ӿ�
  for(i=0;i<2;i++){
     LCD_DrawImage1BPP(500,y+(i+1)*34,Bmp_MK, WHITE,BLACK); 
     LCD_DrawImage1BPP(500,y+(i+3)*34,Bmp_ECU,WHITE,BLACK); 

     LCD_DrawImage1BPP(540,y+34+(i)*68,Bmp_CAN,WHITE,BLACK); 
     LCD_DrawImage1BPP(540+30,y+34+(i)*68,Bmp_Gao,WHITE,BLACK);  
     LCD_DrawImage1BPP(540,y+(i+1)*68,Bmp_CAN,WHITE,BLACK);
     LCD_DrawImage1BPP(540+30,y+(i+1)*68,Bmp_di,WHITE,BLACK); 
  }
}

//ģ��˿�״̬ ��ʾ
//�̶�λ����ʾ ���ŵ��� ��CAN״̬
void disp_can(void){
     LCD_DrawImageSBPP(500,265,Bmp_LCDL,WHITE,BLACK); 
     LCD_DrawImage1BPP(540,265,Bmp_dl,  WHITE,BLACK); 

     LCD_DrawImage1BPP(500,299,Bmp_CAN,WHITE,BLACK);
     LCD_DrawImage1BPP(530,299,Bmp_Gao,WHITE,BLACK);
     
     LCD_DrawImage1BPP(500,333,Bmp_CAN,WHITE,BLACK); 
     LCD_DrawImage1BPP(530,333,Bmp_di,WHITE,BLACK); 
     
     LCD_DrawImage1BPP(20+420,    95+8*34,Bmp_cxbb,WHITE,BLACK);//����汾 
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
    LCD_DrawImage1BPP(500,163+i*34,Bmp_ADD,WHITE,BLACK);          //KL13��KL14����ַ
    LCD_DrawImage1BPP(558,163+i*34,Bmp_ADDst[s[i]],WHITE,BLACK);
  }
 //��ʾ�ź��� �����ź�
  for(i=0;i<3;i++){
    LCD_DrawImage1BPP(524,333+i*34,Bmp_KL, WHITE,BLACK);
    LCD_DrawImage1BPP(566,333+i*34,Bmp_adr,WHITE,BLACK);
   if(i==2)
    LCD_DrawImage1BPP(690,333+i*34,Bmp_Hz, WHITE,BLACK);
   else
    LCD_DrawImage1BPP(690,333+i*34,Bmp_R,  WHITE,BLACK);    
  }
}

//ǰ��ģ�� ��Դ
void disp_front_load(void){
   unsigned int Iid[20]={1,9,2,10,3,11,4,12,5,13,
                         6,14,7,42,8,17,16,31,0,0};
  disp_ID(1,Iid); //��ʾ���
  disp_can();
//��һ��
  x=80;y=95;
  disp_yg(x,y+0*34,0);//10,18,Bmp_front_load1,WHITE,0x0000);
  LCD_DrawImage1BPP(x+80,y+0*34,Bmp_dj,WHITE,BLACK);  

  disp_yg(x,y+1*34,1);//10,18,Bmp_front_load2,WHITE,0x0000); 
  LCD_DrawImage1BPP(x+80,y+1*34,Bmp_dj,WHITE,BLACK);  
 
  disp_yg(x,y+2*34,2);//10,18,Bmp_front_load3,WHITE,0x0000);
  LCD_DrawImage1BPP(x+80,y+2*34,Bmp_dj,WHITE,BLACK); 
  
  LCD_DrawImageSBPP(x,y+3*34,Bmp_front_load4, WHITE,BLACK);//
  LCD_DrawImageSBPP(x,y+4*34,Bmp_front_load5, WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+5*34,Bmp_front_load6, WHITE,BLACK);//
  LCD_DrawImage1BPP(x,y+6*34,Bmp_front_load7, WHITE,BLACK);//
  LCD_DrawImageSBPP(x,y+7*34,Bmp_front_load8, WHITE,BLACK);  
  LCD_DrawImageSBPP(x,y+8*34,Bmp_front_load9, WHITE,BLACK);
  LCD_DrawImageSBPP(x,y+9*34,Bmp_front_load10,WHITE,BLACK);//

//�ڶ���
  x=500;y=95;
  LCD_DrawImageSBPP(x,y+0*34,Bmp_front_load11,WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+1*34,Bmp_front_load12,WHITE,BLACK);  LCD_DrawImage1BPP(x+80,y+1*34,Bmp_Ping,WHITE,BLACK);
  LCD_DrawImageSBPP(x,y+2*34,Bmp_front_load13,WHITE,BLACK);//
  LCD_DrawImage1BPP(x,y+3*34,Bmp_front_load14,WHITE,BLACK);//
  LCD_DrawImageSBPP(x,y+4*34,Bmp_front_load15,WHITE,BLACK);//
}

//ǰ��ģ�鿪����Ϣ
void disp_front_KL(void){
  unsigned int Iid[20]={32,18,33,19,34,20,35,21,36,22,
                        37,23,38,24,39,41,17,25,40,26};
  disp_ID(0,Iid);
//��һ��
  x=80;y=95;
  LCD_DrawImage1BPP(x,y+0*34,Bmp_FKL1, WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+1*34,Bmp_FKL2, WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+2*34,Bmp_FKL3, WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+3*34,Bmp_FKL4, WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+4*34,Bmp_FKL5, WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+5*34,Bmp_FKL6, WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+6*34,Bmp_FKL7, WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+7*34,Bmp_FKL8, WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+8*34,Bmp_FKL9, WHITE,BLACK);  
  LCD_DrawImageSBPP(x,y+9*34,Bmp_FKL10, WHITE,BLACK); 
//�ڶ��� 
  x=500;y=95;
  LCD_DrawImage1BPP(x,y+0*34,Bmp_FKL11,WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+1*34,Bmp_FKL12,WHITE,BLACK);
  disp_ADD(1);// KL13 KL14 ��Ϊ��ַ��
  LCD_DrawImage1BPP(x,y+4*34,Bmp_FKL15,WHITE,BLACK);
  disp_yg(x,y+5*34,4);
  LCD_DrawImage1BPP(x,y+6*34,Bmp_FKH1,WHITE,BLACK); 

  unsigned int Iid1[20]={0,0,0,0,0,0,0,0,0,160,
                         0,0,0,0,0,580,0,0,0,0};
  disp_kg(Iid1);  //��ʾ����
}


//��ģ�� ��Դ
void disp_rear_load(void){
   unsigned int Iid[20]={1,9,2,10,3,11,4,12,5,13,
                         6,14,7,42,8,17,16,31,0,0};
  disp_ID(1,Iid); //��ʾ���
  disp_can();
  unsigned char i;
//��һ��
  x=80;y=95;
  for(i=0;i<10;i++){
  LCD_DrawImage1BPP(x,y+i*34,Bmp_KL,WHITE,BLACK); 
  }
/*
  LCD_DrawImage1BPP(x,y+0*34,Bmp_rear_load1,WHITE,BLACK);  
  LCD_DrawImage1BPP(x,y+1*34,Bmp_rear_load2,WHITE,BLACK); 
  
  LCD_DrawImage1BPP(x,y+2*34,Bmp_rear,WHITE,BLACK);   
  LCD_DrawImage1BPP(x+18,y+2*34,Bmp_rear_load3,WHITE,BLACK); 

  LCD_DrawImage1BPP(x,y+3*34,Bmp_rear_load4, WHITE,BLACK);//
  
  LCD_DrawImage1BPP(x,y+4*34,Bmp_left, WHITE,BLACK);
  LCD_DrawImage1BPP(x+18,y+4*34,Bmp_rear_load5, WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+5*34,Bmp_rear_load6, WHITE,BLACK);//
  
  LCD_DrawImage1BPP(x,y+6*34,Bmp_right, WHITE,BLACK);// 
  LCD_DrawImage1BPP(x+18,y+6*34,Bmp_rear_load7, WHITE,BLACK);//
  
  LCD_DrawImage1BPP(x,y+7*34,Bmp_rear_load8, WHITE,BLACK);
  LCD_DrawImage1BPP(x+56,y+7*34,Bmp_dy, WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+8*34,Bmp_rear_load9, WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+9*34,Bmp_rear_load10,WHITE,BLACK);//
*/
//�ڶ���
  x=500;y=95;
  for(i=0;i<5;i++){
  LCD_DrawImage1BPP(x,y+i*34,Bmp_KL,WHITE,BLACK); 
  }
  /*
  LCD_DrawImage1BPP(x,y+0*34,Bmp_front,WHITE,BLACK);
  LCD_DrawImage1BPP(x+18,y+0*34,Bmp_rear_load11,WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+1*34,Bmp_rear_load12,WHITE,BLACK);
  
  LCD_DrawImage1BPP(x,y+2*34,Bmp_rear,WHITE,BLACK);//
  LCD_DrawImage1BPP(x+18,y+2*34,Bmp_rear_load13,WHITE,BLACK);//
  
  LCD_DrawImage1BPP(x,y+3*34,Bmp_rear_load14,WHITE,BLACK);//
  LCD_DrawImage1BPP(x,y+4*34,Bmp_rear_load15,WHITE,BLACK);//
  */
  
}

//��ģ�鿪����Ϣ
void disp_rear_KL(void){
  unsigned int Iid[20]={32,18,33,19,34,20,35,21,36,22,
                        37,23,38,24,39,41,17,25,40,26};
  disp_ID(0,Iid);
//��һ��
  x=80;y=95;  
  LCD_DrawImage1BPP(x,y+0*34,Bmp_RKL1, WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+1*34,Bmp_RKL2, WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+2*34,Bmp_RKL3, WHITE,BLACK);
  LCD_DrawImageSBPP(x,y+3*34,Bmp_RKL4, WHITE,BLACK);
  LCD_DrawImageSBPP(x,y+4*34,Bmp_RKL5, WHITE,BLACK);
  LCD_DrawImageSBPP(x,y+5*34,Bmp_RKL6, WHITE,BLACK);
      LCD_DrawImage1BPP(x,y+6*34,Bmp_RKL7, WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+7*34,Bmp_RKL8, WHITE,BLACK);
      LCD_DrawImage1BPP(x,y+8*34,Bmp_RKL9, WHITE,BLACK);
  LCD_DrawImageSBPP(x,y+9*34,Bmp_RKL10,WHITE,BLACK); 
//�ڶ��� 
  x=500;y=95;
  LCD_DrawImage1BPP(x,y+0*34,Bmp_RKL11,WHITE,BLACK);
  LCD_DrawImageSBPP(x,y+1*34,Bmp_RKL12,WHITE,BLACK);
  disp_ADD(2);// KL13 KL14 ��Ϊ��ַ��
  LCD_DrawImage1BPP(x,y+4*34,Bmp_RKL15,WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+5*34,Bmp_RADD,WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+6*34,Bmp_RKH1,WHITE,BLACK); 

  unsigned int Iid1[20]={0,0,0,0,0,136,0,120,0,176,
                         0,596,0,0,0,0,0,0,0,0};
  disp_kg(Iid1);  //��ʾ����
}


//����ģ�� ��Դ
void disp_top_load(void){
   unsigned int Iid[20]={1,9,2,10,3,11,4,12,5,13,
                         6,14,7,42,8,17,16,31,0,0};
  disp_ID(1,Iid); //��ʾ��� 
  disp_can();
//��һ��
  x=80;y=95;
  LCD_DrawImageSBPP(x,y+0*34,Bmp_top_load1, WHITE,BLACK); 
  LCD_DrawImageSBPP(x,y+1*34,Bmp_top_load2, WHITE,BLACK);
  LCD_DrawImageSBPP(x,y+2*34,Bmp_top_load3, WHITE,BLACK);
  LCD_DrawImageSBPP(x,y+3*34,Bmp_top_load4, WHITE,BLACK);
  LCD_DrawImageSBPP(x,y+4*34,Bmp_top_load5, WHITE,BLACK);
  LCD_DrawImageSBPP(x,y+5*34,Bmp_top_load6, WHITE,BLACK);
  LCD_DrawImageSBPP(x,y+6*34,Bmp_top_load7, WHITE,BLACK);
  LCD_DrawImageSBPP(x,y+7*34,Bmp_top_load8, WHITE,BLACK);
  LCD_DrawImageSBPP(x,y+8*34,Bmp_top_load9, WHITE,BLACK);
  LCD_DrawImageSBPP(x,y+9*34,Bmp_top_load10, WHITE,BLACK);

//�ڶ��� 
  x=500;y=95;
  LCD_DrawImageSBPP(x,y+0*34,Bmp_top_load11,WHITE,BLACK);
  LCD_DrawImageSBPP(x,y+1*34,Bmp_top_load12,WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+2*34,Bmp_top_load13,WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+3*34,Bmp_top_load14,WHITE,BLACK);
  LCD_DrawImageSBPP(x,y+4*34,Bmp_top_load15,WHITE,BLACK);
  
}

//����ģ�鿪����Ϣ
void disp_top_KL(void){
  unsigned int Iid[20]={32,18,33,19,34,20,35,21,36,22,
                        37,23,38,24,39,41,17,25,40,26};
  disp_ID(0,Iid);
//��һ��  
  x=80;y=95;
  LCD_DrawImage1BPP(x,y+0*34,Bmp_TKL1, WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+1*34,Bmp_TKL2, WHITE,BLACK); 
  LCD_DrawImage1BPP(x,y+2*34,Bmp_TKL3, WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+3*34,Bmp_TKL4, WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+4*34,Bmp_TKL5, WHITE,BLACK); 
  LCD_DrawImage1BPP(x,y+5*34,Bmp_TKL6, WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+6*34,Bmp_TKL7, WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+7*34,Bmp_TKL8, WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+8*34,Bmp_TKL9, WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+9*34,Bmp_TKL10,WHITE,BLACK);

//�ڶ��� +
  x=500;y=95;
  LCD_DrawImage1BPP(x,y+0*34,Bmp_TKL11,WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+1*34,Bmp_TKL12,WHITE,BLACK);
  disp_ADD(3);// KL13 KL14 ��Ϊ��ַ��
  LCD_DrawImageSBPP(x,y+4*34,Bmp_TKL15,WHITE,BLACK);
  LCD_DrawImage1BPP(x,y+5*34,Bmp_TADD, WHITE,BLACK); 
  LCD_DrawImageSBPP(x,y+6*34,Bmp_TKH1, WHITE,BLACK); 

  unsigned int Iid1[20]={0,0,0,176,0,0,0,0,0,0,
                         0,556,0,0,598,0,598,0,0,0};
  disp_kg(Iid1);  //��ʾ����
}

//-----------------------------------------------
//������ʾ�Ǳ����� ״̬ 
//������ id ��ʾ�����
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
         s=1;//����״̬
      }else{
         color=WHITE;
         s=0;
     }
      
      LCD_DrawImage1BPP(56+j*420,95+34*i,Bmpflag1[s],color,BLACK);
      ktemp[j]=ktemp[j]>>1; //����״̬��λ
      //if((j==1)&&(i==1)&&(id==1))break;
      
   }
  }
}

//���¹������ ״̬
void update_CY09MT_load(unsigned char index){
 unsigned char color=GREEN,s=0;	
 unsigned int  Tdate=0,TCAN=0; 
 unsigned char *Sdate; //
 unsigned int  *Pcurrent;
 unsigned int  i=0,j=0;
 unsigned int  MK_Version=0;
 unsigned char *LOAD_ST;
  switch(index){
   case 0:
    TCAN=Fcan_count;
    Tdate=((unsigned int )(fPOUT.BYTES[1])<<8)+fPOUT.BYTES[0];
    //Sdate=((unsigned long)(fPF[3].byte)<<24)+((unsigned long)(fPF[2].byte)<<16)+
    //      ((unsigned long)(fPF[1].byte)<<8)+fPF[0].byte;
    Sdate=fPF; //��������״̬
    Pcurrent=fpcur;//��������
    MK_Version=fMK_Version;
    LOAD_ST=F_LOAD_ST;
   break;
   case 1:
    TCAN=Rcan_count;
    Tdate=((unsigned int )(rPOUT.BYTES[1])<<8)+rPOUT.BYTES[0];
    //Sdate=((unsigned long)(rPF[3].byte)<<24)+((unsigned long)(rPF[2].byte)<<16)+
    //      ((unsigned long)(rPF[1].byte)<<8)+rPF[0].byte;
    Sdate=rPF; //��������״̬
    Pcurrent=rpcur;//��������
    MK_Version=rMK_Version;
    LOAD_ST=R_LOAD_ST;
   break;
   case 2:
    TCAN=Mcan_count;
    Tdate=((unsigned int )(mPOUT.BYTES[1])<<8)+mPOUT.BYTES[0];
    //Sdate=((unsigned long)(mPF[3].byte)<<24)+((unsigned long)(mPF[2].byte)<<16)+
    //      ((unsigned long)(mPF[1].byte)<<8)+mPF[0].byte;
    Sdate=mPF; //��������״̬
    Pcurrent=mpcur;//��������
    MK_Version=mMK_Version;
    LOAD_ST=M_LOAD_ST;
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
    
    if(j==1 && i>=5) break; //״̬��ʾ16�� ������ʾ15�� 

    if(LOAD_ST[i+j*10]==1)color = RED;  //20171208���ӹ��ر�������
    else{
    if (Sdate[i+j*10] == 0) color = GREEN;
    else if (Sdate[i+j*10] == 1) color = YELLOW;
    else if (Sdate[i+j*10] == 2) color = RED;  //20171208���ӹ��ر�������
    else color = RED; 
    }
    LCD_DrawImage1BPP(308+j*420,95+i*34,Bmpfault,color,BLACK);//״̬

    if (Pcurrent[i+j*10] / 100 > 10)print_SZ(308+j*420+30, 95+i*34+3, Pcurrent[i+j*10] / 100, 3, 1, color); //��ģ�����
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
  //print_SZ_2(20+420+128+16,95+8*34,   MK_Version,3,2,YELLOW);//2.00 ģ�����汾
    
    LCD_DrawImage1BPP(20+420,95+9*34,Bmp_V,   WHITE,BLACK);//A  
    print_SZ_2(20+420+16,95+9*34,   MK_Version,3,2,YELLOW);//2.00 ģ�����汾 
}

//����ģ�� ����״̬
void update_CY09MT_KL(unsigned char index){
 unsigned int i=0,j=0;
 unsigned char color=GREEN,s=0;;	
 unsigned long Tdate=0; 
 unsigned int  Sdate[3]={0,0,0};
 unsigned int   ADRx=0; //�ź�����ʾλ��
  switch(index){
   case 0:
    //������
    fKEY.BYTES[1] |=fADD<<7; 
    Tdate=((unsigned long)(fKEY.BYTES[2])<<16)+
          ((unsigned long)(fKEY.BYTES[1])<<8)+fKEY.BYTES[0];

    //�ź��� 
    ADRx=614;
    Sdate[0]=fADR[0]/10;
    Sdate[1]=fADR[1]/10; 
    Sdate[2]=fFreq;
   break;
   case 1:
    //������
    rKEY.BYTES[1] |=rADD<<7;//ADD
    Tdate=((unsigned long)(rKEY.BYTES[2])<<16)+
          ((unsigned long)(rKEY.BYTES[1])<<8)+rKEY.BYTES[0];
    //�ź��� 
    ADRx=614;
    Sdate[0]=rADR[0]/10;
    Sdate[1]=rADR[1]/10; 
    Sdate[2]=rFreq;
   break;
   case 2:
    //������
    mKEY.BYTES[1] |=mADD<<7; //ADD
    Tdate=((unsigned long)(mKEY.BYTES[2])<<16)+
          ((unsigned long)(mKEY.BYTES[1])<<8)+mKEY.BYTES[0];
    //�ź���
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

//����״̬ 
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
  //��ʾ������
   LCD_DrawImage1BPP(700-25,30,Bmp_DI,GREEN,BLACK);//��
   LCD_DrawImage1BPP(700+25,30,Bmp_YE,GREEN,BLACK);//ҳ
   print_SZ_2(700,30,id+1,1,0,WHITE);//ҳ����
   LCD_DrawImage1BPP(500,30,Bmp_CANST, WHITE,BLACK);//
   //LCD_DrawImage1BPP(532,30,Bmp_TXun,WHITE,BLACK);   

  if(id<=2){
    LCD_DrawImage1BPP(340-18,30,Bmp_front,   BLACK,BLACK); 
    LCD_DrawImageSBPP(340,   30,Bmp_menu_1[8],  GREEN, BLACK); //�Ǳ�ϵͳ��Ϣ9
    
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
  static unsigned char Did=0; //��ʾ��Ļ ���
  if(f_index==0){
    f_index=1;  
    key_up=1;  //���� ��ʾ����
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
    LCD_DrawRect(0, 56,  800, 2, GRAY); //�������� 
    LCD_DrawRect(0, 430, 800, 2, GRAY); //�ײ�����
    
  //LCD_DrawImage1BPP(340,   30,BMP_STSTEM, GREEN,BLACK);//ϵͳ
  //LCD_DrawImage1BPP(340+40,30,Bmp_Menu,   GREEN,BLACK);//�˵�
  //LCD_DrawImage1BPP(340+80,30,BMP_Message,GREEN,BLACK);//��Ϣ
    LCD_DrawImageSBPP(340,   30,Bmp_menu_1[0],  GREEN, BLACK); //�˵���Ϣ
    
x=400-60;y=75-9;
    for(i=0;i<11;i++){
    LCD_DrawImageSBPP(x, y+i*30, Bmp_menu_1[i+1],  WHITE, BLACK); //�Ӳ˵���Ϣ
    }

}

void MenuUpdate(void) {
    static unsigned char i = 0;
    unsigned char color = BLACK;
    if (key_up) {//��ͷ������
        key_up = 0;
        if (!time_flag) {
            i++;
        }
    }

    if (key_AV) {//��ͷ������
        key_AV = 0;
        if (!time_flag)
            i--;
    }

    if (i == 22) i = 11;
    if (i == 0)  i = 11;
    
x=320-9;y=75-10;
    //�Ӳ˵����л�
    if (i == 11) {
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
    if (i == 12 || i == 1) {
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
    LCD_DrawImage1BPP(x,  y+2*30, BMP_Choose, color, BLACK);
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
    LCD_DrawImage1BPP(x,  y+3*30, BMP_Choose, color, BLACK);
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
    LCD_DrawImage1BPP(x,  y+4*30, BMP_Choose, color, BLACK);

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
    LCD_DrawImage1BPP(x,  y+5*30, BMP_Choose, color, BLACK);

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
    LCD_DrawImage1BPP(x,  y+6*30, BMP_Choose, color, BLACK);
    
    if (i == 18 || i == 7) {
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
    LCD_DrawImage1BPP(x,  y+7*30, BMP_Choose, color, BLACK);
    if (i == 19 || i == 8) {
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
    LCD_DrawImage1BPP(x,  y+8*30, BMP_Choose, color, BLACK);
    if (i == 20|| i == 9) {
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
    LCD_DrawImage1BPP(x,  y+9*30, BMP_Choose, color, BLACK);
    if (i == 21|| i == 10) {
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
    LCD_DrawImage1BPP(x,  y+10*30, BMP_Choose, color, BLACK);
    
}

void frmMenu(void) {
    if (f_index == 0) { //ֻ����һ��
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
    LCD_DrawRect(x,y,1, 350,GRAY);//|��
x=269;
   //LCD_DrawRect(x,y,1, 350,GRAY);//|��1
x=400;
    LCD_DrawRect(x,y,1, 350,GRAY);//|��
x=531;
   //LCD_DrawRect(x,y,1, 350,GRAY);//|��2
x=793;
    LCD_DrawRect(x,y,1, 350,GRAY);//|��



///////////////////////��һ��///////////////////////
x=10;y=84-9; 
   for(i=0;i<8;i++){
   lcd_show_9dot(x,    y+i*35, Bmp_KZQ_1_L_1[i],    WHITE, BLACK);//������Ϣ
   }

x=x+338;//��λ����
   for(i=0;i<2;i++){
   lcd_show_9dot(x,    y+i*35, Bmp_KZQ_1_L_2[i],    WHITE, BLACK);//
   }


///////////////////////�ڶ���///////////////////////
x=463-58;y=84-9; 
   for(i=0;i<3;i++){
   lcd_show_9dot(x,    y+i*35, Bmp_KZQ_1_R_1[i],    WHITE, BLACK);//������Ϣ
   }

x=x+338;
   for(i=2;i<5;i++){
   lcd_show_9dot(x,    y+(i-2)*35, Bmp_KZQ_1_L_2[i],    WHITE, BLACK);//
   }

}

void ControlUpdate(void) {
    unsigned int i=0,s,temp=1000;
  
//////////////////////��һ��////////////////////
x=305-32;y=84-9;

//��������������ѹ 
  temp=DJcontroler_voltage/10;
  if(temp>=1000){
     temp=(temp-1000);s=12;
    }else{
     temp=(1000-temp);s=11;
    }
  update_dl(x,    y+0*35,temp,3,s,YELLOW);

//���������������� 
  temp=DJcontroler_current/10;
  if(temp>=1000){
     temp=(temp-1000);s=12;
    }else{
     temp=(1000-temp);s=11;
    }
  update_dl(x,    y+1*35,temp,3,s,YELLOW);

//˾������״̬
   temp=DR_state;
   for(i=0;i<8;i++){     
     lcd_show_8dot(x+48-16*i,y+2*35,BMP_SZ_3[temp&0x01],YELLOW,BLACK);
     temp>>=1;
   } 

//������״̬
   temp=KEY_state;
   for(i=0;i<8;i++){     
     lcd_show_8dot(x+48-16*i,y+3*35,BMP_SZ_3[temp&0x01],YELLOW,BLACK);
     temp>>=1;
   } 

//ϵͳ����״̬
   temp=system_state;
   for(i=0;i<8;i++){     
     lcd_show_8dot(x+48-16*i,y+4*35,BMP_SZ_3[temp&0x01],YELLOW,BLACK);
     temp>>=1;
   } 
//����ģʽ
   print_SZ_2(x,y+5*35,CAR_MODE,4,0,YELLOW);
//life
   print_SZ_2(x,y+6*35,controler_LIFE,4,0,YELLOW);

 //�汾��
  x=102-48;
  y=y+8*35; 
  if(KZQversion[0]>99)temp=99;else temp=KZQversion[0];  
  print001(x-2,y, temp,2);
  lcd_clear_8dot(x+34,y+8,8,3,YELLOW);

  if(KZQversion[1]>99)temp=99;else temp=KZQversion[1];  
  print001(x+34+10,y, temp,2);
  lcd_clear_8dot(x+34+34+10,y+8,8,2,YELLOW);

  if(KZQversion[2]>99)temp=99;else temp=KZQversion[2]; 
  print001(x+34+34+20,y, temp,2);
  lcd_clear_8dot(x+34+34+34+20,y+8,8,2,YELLOW);

  temp=(((unsigned int)KZQversion[4])<<8)+KZQversion[3];
  if(temp>9999)temp=9999;  
  print001(x+34+34+34+30,y, temp,4);
  lcd_clear_8dot(x+34+34+34+34+34+30,y+8,8,2,YELLOW);

  if(KZQversion[5]>99)temp=99;else temp=KZQversion[5];  
  print001(x+34+34+34+34+34+40,y, temp,2);
  lcd_show_1color(x+34+34+34+34+34+34+40,y+10,3,3,YELLOW);

  if(KZQversion[6]>99)temp=99;else temp=KZQversion[6];  
  print001(x+34+34+34+34+34+34+45,y, temp,2);

//////////////////////�ڶ���////////////////////
x=698-32;y=84-9;
//ǣ��̤��ٷֱ�
  print_SZ_2(x,    y+0*35,0.4*traction_st,4,0,YELLOW);
//�ƶ�̤��ٷֱ�
  print_SZ_2(x,    y+1*35,0.4*brake_st,4,0,YELLOW);
//��ʻ���
  temp=XHLC*5; 
  if(temp>=1000)temp=999;
  print_SZ_2(x+16, y+2*35,temp,3,0,YELLOW);
}

void frmControl(void) {
    if (f_index == 0) { //ֻ����һ��
        f_index = 1;
        LCD_DrawRect(0,60,800,365,BLACK);
        LCD_DrawImageSBPP(340,   30,Bmp_menu_1[1],  GREEN, BLACK); //����ϵͳ��Ϣ1
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
    if (key_set) {//����������
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
   LCD_DrawRect(x,y,1, 350,GRAY);//|��
x=269;
   //LCD_DrawRect(x,y,1, 350,GRAY);//|��1
x=400;
   LCD_DrawRect(x,y,1, 350,GRAY);//|��
x=531;
   //LCD_DrawRect(x,y,1, 350,GRAY);//|��2
x=793;
   LCD_DrawRect(x,y,1, 350,GRAY);//|��

///////////////////////��һ��///////////////////////
x=10;y=84-9; 
   for(i=0;i<4;i++){
   lcd_show_9dot(x,    y+i*35, Bmp_DJ_1_L_1[i],    WHITE, BLACK);//�����Ϣ
   }

x=x+338;//��λ����
   for(i=0;i<3;i++){
   lcd_show_9dot(x,    y+i*35, Bmp_DJ_1_L_2[i],    WHITE, BLACK);//
   }

///////////////////////�ڶ���///////////////////////
x=463-58;y=84-9; 
   for(i=0;i<3;i++){
   lcd_show_9dot(x,    y+i*35, Bmp_DJ_1_R_1[i],    WHITE, BLACK);//�������Ϣ
   }

x=x+338;
   for(i=0;i<2;i++){
   lcd_show_9dot(x,    y+i*35, Bmp_DJ_1_L_2[i],    WHITE, BLACK);//
   }

}

void DJUpdate(void) {
    unsigned int  s=0,temp=0; 

//////////////////////��һ��////////////////////
x=305-32;y=84-9;

//����¶�
  update_deg(x,y+0*35,DJ_temperature,YELLOW);
//����������¶�
  update_deg(x,y+1*35,DJcontroler_temperature,YELLOW);

//�������ת�� 
  temp=DJ_torque;
  if(temp>=32000){
     temp=(temp-32000);s=12;
 }else{
     temp=(32000-temp);s=11;
      }
  update_dl(x-16,y+2*35,temp,4,s,YELLOW);

//�汾�� ���
  x=102-48;
  y=y+4*35; 
  if(DJversion[0]>99)temp=99;else temp=DJversion[0];  
  print001(x-2,y, temp,2);
  lcd_clear_8dot(x+34,y+8,8,3,YELLOW);

  if(DJversion[1]>99)temp=99;else temp=DJversion[1];  
  print001(x+34+10,y, temp,2);
  lcd_clear_8dot(x+34+34+10,y+8,8,2,YELLOW);

  temp=(((unsigned int)DJversion[3])<<8)+DJversion[2];
  if(temp>9999)temp=9999;  
  print001(x+34+34+20,y, temp,4);
  lcd_clear_8dot(x+34+34+34+34+20,y+8,8,2,YELLOW);

  if(DJversion[4]>99)temp=99;else temp=DJversion[4];  
  print001(x+34+34+34+34+30,y, temp,2);
  lcd_clear_8dot(x+34+34+34+34+34+30,y+8,8,2,YELLOW);

  if(DJversion[5]>99)temp=99;else temp=DJversion[5];  
  print001(x+34+34+34+34+34+40,y, temp,2);
  lcd_show_1color(x+34+34+34+34+34+34+40,y+10,3,3,YELLOW);

  if(DJversion[6]>99)temp=99;else temp=DJversion[6];  
  print001(x+34+34+34+34+34+34+45,y, temp,2);
 

//////////////////////�ڶ���////////////////////
x=698-32;y=84-9;

//������¶�
  update_deg(x,y+0*35,FDJ_temperature,YELLOW);
//������������¶�
  update_deg(x,y+1*35,FDJcontroler_temperature,YELLOW);

 //�汾�� ����� 
  x=102+393-48;
  y=y+3*35;
  if(FDJversion[0]>99)temp=99;else temp=FDJversion[0];  
  print001(x-2,y, temp,2);
  lcd_clear_8dot(x+34,y+8,8,3,YELLOW);

  if(FDJversion[1]>99)temp=99;else temp=FDJversion[1];  
  print001(x+34+10,y, temp,2);
  lcd_clear_8dot(x+34+34+10,y+8,8,2,YELLOW);

  temp=(((unsigned int)FDJversion[3])<<8)+FDJversion[2];
  if(temp>9999)temp=9999;  
  print001(x+34+34+20,y, temp,4);
  lcd_clear_8dot(x+34+34+34+34+20,y+8,8,2,YELLOW);

  if(FDJversion[4]>99)temp=99;else temp=FDJversion[4];  
  print001(x+34+34+34+34+30,y, temp,2);
  lcd_clear_8dot(x+34+34+34+34+34+30,y+8,8,2,YELLOW);

  if(FDJversion[5]>99)temp=99;else temp=FDJversion[5];  
  print001(x+34+34+34+34+34+40,y, temp,2);
  lcd_show_1color(x+34+34+34+34+34+34+40,y+10,3,3,YELLOW);

  if(FDJversion[6]>99)temp=99;else temp=FDJversion[6];  
  print001(x+34+34+34+34+34+34+45,y, temp,2);

  
}

void frmDJ(void) {
    if (f_index == 0) { //ֻ����һ��
        f_index = 1;
        LCD_DrawRect(0,60,800,365,BLACK);
        LCD_DrawImageSBPP(340,   30,Bmp_menu_1[2],  GREEN, BLACK); //����ϵͳ��Ϣ3
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
    if (key_set) {//����������
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
    LCD_DrawRect(x,y,1, 350,GRAY);//|��
x=269;
   //LCD_DrawRect(x,y,1, 350,GRAY);//|��1
x=400;
    LCD_DrawRect(x,y,1, 350,GRAY);//|��
x=531;
   //LCD_DrawRect(x,y,1, 350,GRAY);//|��2
x=793;
    LCD_DrawRect(x,y,1, 350,GRAY);//|��


///////////////////////��һ��///////////////////////
x=10;y=84-9; 
    lcd_show_8dot(x,    y+0*35,  Bmp_dt,     WHITE,BLACK);//����
    lcd_show_8dot(x+40, y+0*35,  Bmp_zg,     WHITE,BLACK);//���
    lcd_show_8dot(x+80, y+0*35,  Bmp_wd,     WHITE,BLACK);//�¶�

    lcd_show_8dot(x,    y+1*35,  Bmp_dt,     WHITE,BLACK);//����
    lcd_show_8dot(x+40, y+1*35,  Bmp_zg,     WHITE,BLACK);//���
    lcd_show_8dot(x+60, y+1*35,  Bmp_di,     WHITE,BLACK);//��
    lcd_show_8dot(x+80, y+1*35,  Bmp_wd,     WHITE,BLACK);//�¶�

    lcd_show_8dot(x,    y+2*35,  Bmp_dc,     WHITE,BLACK);//���
    lcd_show_8dot(x+40, y+2*35,  Bmp_LXing,  WHITE,BLACK);//����

    lcd_show_8dot(x,    y+3*35,  Bmp_dc,     WHITE,BLACK);//���
    lcd_show_8dot(x+40, y+3*35,  Bmp_LQFSshi,WHITE,BLACK);//��ȴ��ʽ

    for(i=0;i<2;i++){
    lcd_show_8dot(x+223,y+i*35,    Bmp_deg,   WHITE,0x0000);//
    lcd_show_8dot(x+296,y+i*35,    Bmp_Box,   WHITE,0x0000);//��
    lcd_show_8dot(x+366,y+i*35,    Bmp_Num,   WHITE,0x0000);//��
    }

///////////////////////�ڶ���///////////////////////
x=463-58;y=84-9; 
    lcd_show_8dot(x,    y+0*35,  Bmp_dt,     WHITE,BLACK);//����
    lcd_show_8dot(x+40, y+0*35,  Bmp_zg,     WHITE,BLACK);//���
    lcd_show_8dot(x+80, y+0*35,  Bmp_DY,     WHITE,BLACK);//��ѹ

    lcd_show_8dot(x,    y+1*35,  Bmp_dt,     WHITE,BLACK);//����
    lcd_show_8dot(x+40, y+1*35,  Bmp_zg,     WHITE,BLACK);//���
    lcd_show_8dot(x+60, y+1*35,  Bmp_di,     WHITE,BLACK);//��
    lcd_show_8dot(x+80, y+1*35,  Bmp_DY,     WHITE,BLACK);//��ѹ

    for(i=0;i<2;i++){
    lcd_show_8dot(x+223,y+i*35,    Bmp_V,    WHITE,0x0000);//V
    lcd_show_8dot(x+296,y+i*35,    Bmp_Box,  WHITE,0x0000);//��
    lcd_show_8dot(x+366,y+i*35,    Bmp_Num,  WHITE,0x0000);//��
    }

}
void disp_battery2(void ){
     unsigned int i=0,j=0,k=0;
x=7;y=68;
   for(i=0;i<11;i++){
   LCD_DrawRect(x,y+i*35,786, 1,GRAY);//-
   }
   LCD_DrawRect(x,y,1, 350,GRAY);//|��
x=66;
   LCD_DrawRect(x,y,1, 350,GRAY);//|��1
x=204;
   LCD_DrawRect(x,y,1, 350,GRAY);//|��2
x=263;
   LCD_DrawRect(x,y,1, 350,GRAY);//|��3
x=400;
   LCD_DrawRect(x,y,1, 350,GRAY);//|��
x=459;
   LCD_DrawRect(x,y,1, 350,GRAY);//|��4
x=597;
   LCD_DrawRect(x,y,1, 350,GRAY);//|��5
x=656;
   LCD_DrawRect(x,y,1, 350,GRAY);//|��6
x=793;
   LCD_DrawRect(x,y,1, 350,GRAY);//|��

///////////////////////��һ��///////////////////////
x=36-18;y=84-9;
    LCD_DrawImage1BPP(x,    y+0*35,  Bmp_Bian,   WHITE,BLACK);//��
    LCD_DrawImage1BPP(x+20, y+0*35,  Bmp_Num,    WHITE,BLACK);//��
    
    LCD_DrawImage1BPP(x+197,y+0*35,  Bmp_Bian,   WHITE,BLACK);//��
    LCD_DrawImage1BPP(x+217,y+0*35,  Bmp_Num,    WHITE,BLACK);//��
    
x=136-18;
    LCD_DrawImage1BPP(x,    y+0*35,  Bmp_DY,     WHITE,BLACK);//��ѹ
    LCD_DrawImage1BPP(x+197,y+0*35,  Bmp_DY,     WHITE,BLACK);//��ѹ

///////////////////////�ڶ���///////////////////////
x=36-18+393;
  //LCD_DrawImage1BPP(x,    y+0*35,  Bmp_Box,   WHITE,BLACK);//��
    LCD_DrawImage1BPP(x,    y+0*35,  Bmp_Bian,  WHITE,BLACK);//��
    LCD_DrawImage1BPP(x+20, y+0*35,  Bmp_Num,   WHITE,BLACK);//��
    
  //LCD_DrawImage1BPP(x+197,y+0*35,  Bmp_Box,   WHITE,BLACK);//��
    LCD_DrawImage1BPP(x+197,y+0*35,  Bmp_Bian,  WHITE,BLACK);//��
    LCD_DrawImage1BPP(x+217,y+0*35,  Bmp_Num,   WHITE,BLACK);//��
    
x=136-18+393;
    LCD_DrawImage1BPP(x,    y+0*35,  Bmp_wd,     WHITE,BLACK);//�¶�
    LCD_DrawImage1BPP(x+197,y+0*35,  Bmp_wd,     WHITE,BLACK);//�¶�

///////////////////////��һ��///////////////////////
x=180-8;
for(j=0;j<2;j++){
  for(i=0;i<5;i++){
      LCD_DrawImage1BPP(x+j*197, y+(i+1)*35,Bmp_V, WHITE,BLACK);//V
     }
  }
///////////////////////�ڶ���///////////////////////
x=564-8;
for(j=0;j<2;j++){
  for(i=0;i<5;i++){
      //LCD_DrawImage1BPP(x+j*197, y+(i+1)*35,Bmp_deg,WHITE,BLACK);//
     }
  }
///////////////////////��һ��///////////////////////
x=36-16;
for(j=0;j<2;j++){
  for(i=0;i<5;i++){
      //print_SZ_2(x+j*197, y+(i+1)*35,(k+1),2,0,YELLOW);
      k++;
     }   
  }
///////////////////////�ڶ���///////////////////////
x=36-16+393;
k=0;
for(j=0;j<2;j++){
  for(i=0;i<5;i++){
      //print_SZ_2(x+j*197, y+(i+1)*35,(k+1),2,0,YELLOW);
      k++;
     }   
  }


}
void update_battery1(void){
     unsigned int temp=0;
//////////////////////��һ��////////////////////

x=305-32;y=84-9;

x=196-32;
//��������¶�
  update_deg(x-10, y+0*35,   Tmax,YELLOW);
  print_SZ_2(  x+91, y+0*35, Tmax_box,3,0,YELLOW);
  print_SZ_2(  x+162,y+0*35, Tmax_num,3,0,YELLOW);
//��С�������¶�
  update_deg(x-10, y+1*35, Tmin,YELLOW);
  print_SZ_2(  x+91, y+1*35, Tmin_box,3,0,YELLOW);
  print_SZ_2(  x+162,y+1*35, Tmin_num,3,0,YELLOW);

//�������
  temp=DC_style;
  lcd_show_8dot(x,  y+2*35+1, Bmp_X,      WHITE, BLACK);//
  print_SZ_2(x-10+32, y+2*35,((temp&0XF0)>>4),1,0,YELLOW);
  print_SZ_2(x-10+48, y+2*35,((temp&0X0F)),   1,0,YELLOW);

//�����ȴ��ʽ
  temp=DC_LengQ;
  lcd_show_8dot(x,  y+3*35+1, Bmp_X,      WHITE, BLACK);//
  print_SZ_2(x-10+32, y+3*35,((temp&0XF0)>>4),1,0,YELLOW);
  print_SZ_2(x-10+48, y+3*35,((temp&0X0F)),   1,0,YELLOW);

//////////////////////�ڶ���////////////////////
x=698-32;y=84-9;

x=196-32+393;
//��������¶�
  print_SZ_2(x-10, y+0*35,(Vmax-10000),     3,2,YELLOW);
  print_SZ_2(x+91, y+0*35, Vmax_box,        3,0,YELLOW);
  print_SZ_2(x+162,y+0*35, Vmax_num,        3,0,YELLOW);
//��С�������¶�
  print_SZ_2(x-10, y+1*35,(Vmin-10000),     3,2,YELLOW);
  print_SZ_2(x+91, y+1*35, Vmin_box,        3,0,YELLOW);
  print_SZ_2(x+162,y+1*35, Vmin_num,        3,0,YELLOW);
     
}
void update_battery2(void){
     unsigned int  j=0,i=0,k=0; 
     unsigned char color=0;
     unsigned int  temp=0;  
//////////////////////��һ��////////////////////
y=84-9;
//�����ѹ
for(j=0;j<2;j++){
  for(i=0;i<5;i++){
      temp=BAT_vol[k]-10000;
      if((temp>=415)||(temp<=250))color=RED;else color=YELLOW;
      x=124-40;
      print_SZ_2(x+j*197,  y+(i+1)*35,temp,4,2,color);
      x=36-24;//���
      print_SZ_2(x+j*197, y+(i+1)*35,(BAT_num[k]),3,0,YELLOW);
      k++;
     }
}
//////////////////////�ڶ���////////////////////
k=0;
//�����¶�
for(j=0;j<2;j++){
  for(i=0;i<5;i++){
      temp=BAT_temp[k];
      if(temp==0xff)color=BLACK;else color=YELLOW;
      x=518-32;//�¶�
      update_deg(x+j*197,  y+(i+1)*35,temp,color);
      x=429-24;//���
      print_SZ_2(x+j*197, y+(i+1)*35,(BAT_num1[k]),3,0,color);      
      x=564-8;//��λ
      if(temp==0xff)color=BLACK;else color=WHITE;
      LCD_DrawImage1BPP(x+j*197, y+(i+1)*35,Bmp_deg,color,BLACK);//
      k++;
     }
}
      
}

void disp_battery3(void){ 
   unsigned int  i=0;
x=7;y=68;
   for(i=0;i<11;i++){
    LCD_DrawRect(x,y+i*35,786, 1,GRAY);//-
   }
    LCD_DrawRect(x,y,1, 350,GRAY);//|��
x=269;
   //LCD_DrawRect(x,y,1, 350,GRAY);//|��1
x=400;
    LCD_DrawRect(x,y,1, 350,GRAY);//|��
x=531;
   //LCD_DrawRect(x,y,1, 350,GRAY);//|��2
x=793;
    LCD_DrawRect(x,y,1, 350,GRAY);//|��

///////////////////////��һ��///////////////////////
x=10;y=84-9; 
    lcd_show_8dot(x,    y+0*35,  Bmp_VINJS,     WHITE,BLACK);//VIN����
    lcd_show_8dot(x+72, y+0*35,  Bmp_ZT,        WHITE,BLACK);//״̬

    for(i=1;i<5;i++){
    lcd_show_8dot(x,    y+i*35,  Bmp_CDZuo,     WHITE,BLACK);//�����
    lcd_show_8dot(x+56, y+i*35,  Bmp_wd,        WHITE,BLACK);//�¶�
    lcd_show_8dot(x+96, y+(i)*35,BMP_SZ_3[i],   WHITE,BLACK);//1
    }
    lcd_show_8dot(x,    y+5*35,  Bmp_XXing,     WHITE,BLACK);//����
    lcd_show_8dot(x+40, y+5*35,  Bmp_ST[0],     WHITE,BLACK);//����
    lcd_show_8dot(x+80, y+5*35,  Bmp_SLiang,    WHITE,BLACK);//����

x=x+338;//��λ����
    for(i=1;i<5;i++){
    lcd_show_8dot(x,    y+i*35,  Bmp_deg,       WHITE, BLACK);//
    }
///////////////////////�ڶ���///////////////////////
x=463-58;y=84-9; 
    lcd_show_8dot(x,    y+0*35,  Bmp_dc,        WHITE,BLACK);//���
    lcd_show_8dot(x+40, y+0*35,  Bmp_xt,        WHITE,BLACK);//ϵͳ
    lcd_show_8dot(x+80, y+0*35,  Bmp_EDing,     WHITE,BLACK);//�
    lcd_show_8dot(x+120,y+0*35,  Bmp_RLiang,    WHITE,BLACK);//����

    lcd_show_8dot(x,    y+1*35,  Bmp_dc,        WHITE,BLACK);//���
    lcd_show_8dot(x+40, y+1*35,  Bmp_xt,        WHITE,BLACK);//ϵͳ
    lcd_show_8dot(x+80, y+1*35,  Bmp_EDing,     WHITE,BLACK);//�
    lcd_show_8dot(x+120,y+1*35,  Bmp_DY,        WHITE,BLACK);//��ѹ

    lcd_show_8dot(x,    y+2*35,  Bmp_dt,        WHITE,BLACK);//����
    lcd_show_8dot(x+40, y+2*35,  Bmp_Chuan,     WHITE,BLACK);//��
    lcd_show_8dot(x+56, y+2*35,  Bmp_LShu,      WHITE,BLACK);//����

    lcd_show_8dot(x,    y+3*35,  Bmp_dt,        WHITE,BLACK);//����
    lcd_show_8dot(x+40, y+3*35,  Bmp_Bing,      WHITE,BLACK);//��
    lcd_show_8dot(x+56, y+3*35,  Bmp_LShu,      WHITE,BLACK);//����

    lcd_show_8dot(x,    y+4*35,  Bmp_dc,        WHITE,BLACK);//���
    lcd_show_8dot(x+40, y+4*35,  Bmp_xt,        WHITE,BLACK);//ϵͳ
    lcd_show_8dot(x+80, y+4*35,  Bmp_wd,        WHITE,BLACK);//�¶�
    lcd_show_8dot(x+120,y+4*35,  Bmp_TZhen,     WHITE,BLACK);//̽��

x=x+338;//��λ����
    lcd_show_8dot(x,    y+0*35, Bmp_AH,        WHITE, BLACK);//
    lcd_show_8dot(x,    y+1*35, Bmp_V,         WHITE, BLACK);//

}
void update_battery3(void){
  unsigned int  i=0,temp=1000;
  unsigned char temp8[10];
//////////////////////��һ��////////////////////
x=305-32;y=84-9;
//VIN����״̬
     temp8[0]=VIN_Status;
  for(i=0;i<8;i++){   
     lcd_show_8dot(x+48-i*16,y+35*(0),BMP_SZ_3[temp8[0]&0x01],YELLOW,BLACK);
     temp8[0]>>=1;
   }
//������¶�
  for(i=0;i<4;i++){
    temp=CDZ_temp[i];
    update_deg(x,y+(i+1)*35,temp,YELLOW);
  }
//���й�������
  print_SZ_2(x,  y+5*35,DC_Status[5],4,0,YELLOW);

//////////////////////�ڶ���////////////////////
x=698-32;y=84-9;
//��ض����
  print_SZ_2(x,  y+0*35,DC_EDRL,4,0,YELLOW);
//��ض��ѹ
  print_SZ_2(x,  y+1*35,DC_EDDY/10,4,0,YELLOW);
//��ص��崮������
  print_SZ_2(x-16,  y+2*35,DC_CL_SUM,5,0,YELLOW);
//��ص��岢������
  print_SZ_2(x,  y+3*35,DC_BL_SUM,4,0,YELLOW);
//���ϵͳ�¶�̽��
  print_SZ_2(x,  y+4*35,DC_WD_SUM,4,0,YELLOW);


}
void disp_battery4(){
   unsigned int  i=0;
   
x=7;y=68;
   for(i=0;i<11;i++){
    LCD_DrawRect(x,y+i*35,786, 1,GRAY);//-
   }
    LCD_DrawRect(x,y,1, 350,GRAY);//|��
x=269;
   //LCD_DrawRect(x,y,1, 350,GRAY);//|��1
x=400;
    LCD_DrawRect(x,y,1, 350,GRAY);//|��
x=531;
   //LCD_DrawRect(x,y,1, 350,GRAY);//|��2
x=793;
    LCD_DrawRect(x,y,1, 350,GRAY);//|��

///////////////////////��һ��///////////////////////
x=10;y=84-9; 
    lcd_show_8dot(x,    y+0*35,  Bmp_dc,     WHITE,BLACK);//��� 
    lcd_show_8dot(x+40, y+0*35,  Bmp_zong,   WHITE,BLACK);//��
    lcd_show_8dot(x+56, y+0*35,  Bmp_DY,     WHITE,BLACK);//��ѹ

    lcd_show_8dot(x,    y+1*35,  Bmp_ZDYXu,  WHITE,BLACK);//�������
    lcd_show_8dot(x+80, y+1*35,  Bmp_cdian,  WHITE,BLACK);//���
    lcd_show_8dot(x+120,y+1*35,  Bmp_dl,     WHITE,BLACK);//����

    lcd_show_8dot(x,    y+2*35,  Bmp_ZDYXu,  WHITE,BLACK);//�������
    lcd_show_8dot(x+80, y+2*35,  Bmp_fd,     WHITE,BLACK);//�ŵ�
    lcd_show_8dot(x+120,y+2*35,  Bmp_dl,     WHITE,BLACK);//����

    lcd_show_8dot(x,    y+3*35,  Bmp_jy,     WHITE,BLACK);//��Ե
    lcd_show_8dot(x+40, y+3*35,  Bmp_zheng,  WHITE,BLACK);//��
    lcd_show_8dot(x+56, y+3*35,  Bmp_DZhi,   WHITE,BLACK);//��ֵ

    lcd_show_8dot(x,    y+4*35,  Bmp_jy,     WHITE,BLACK);//��Ե
    lcd_show_8dot(x+40, y+4*35,  Bmp_fu,     WHITE,BLACK);//��
    lcd_show_8dot(x+56, y+4*35,  Bmp_DZhi,   WHITE,BLACK);//��ֵ

  for(i=0;i<5;i++){
    lcd_show_8dot(x,    y+(i+5)*35,  Bmp_dc,       WHITE,BLACK);//��� 
    lcd_show_8dot(x+40, y+(i+5)*35,  Bmp_ZT,       WHITE,BLACK);//״̬ 
    lcd_show_8dot(x+80, y+(i+5)*35,  BMP_SZ_3[i+1],WHITE,BLACK);//1
  }

x=x+338;//��λ����
    lcd_show_8dot(x,    y+0*35, Bmp_V,      WHITE, BLACK);//
    lcd_show_8dot(x,    y+1*35, Bmp_A,      WHITE, BLACK);//
    lcd_show_8dot(x,    y+2*35, Bmp_A,      WHITE, BLACK);//
    lcd_show_8dot(x,    y+3*35, Bmp_K,      WHITE, BLACK);//K
    lcd_show_8dot(x+16, y+3*35, Bmp_R,      WHITE, BLACK);//��
    lcd_show_8dot(x,    y+4*35, Bmp_K,      WHITE, BLACK);//K
    lcd_show_8dot(x+16, y+4*35, Bmp_R,      WHITE, BLACK);//��

///////////////////////�ڶ���///////////////////////
x=463-58;y=84-9; 
    lcd_show_8dot(x,    y+0*35,  Bmp_cdian,  WHITE,BLACK);//��
    lcd_show_8dot(x+19, y+0*35,  Bmp_fd,     WHITE,BLACK);//�ŵ�
    lcd_show_8dot(x+56, y+0*35,  Bmp_dl,     WHITE,BLACK);//����

  for(i=1;i<5;i++){
    lcd_show_8dot(x,    y+i*35,  Bmp_dt,     WHITE,BLACK);//����
  }
  //lcd_show_8dot(x,    y+1*35,  Bmp_dt,     WHITE,BLACK);//����
    lcd_show_8dot(x+40, y+1*35,  Bmp_PJun,   WHITE,BLACK);//ƽ��
    lcd_show_8dot(x+80, y+1*35,  Bmp_DY,     WHITE,BLACK);//��ѹ

  //lcd_show_8dot(x,    y+2*35,  Bmp_dt,     WHITE,BLACK);//����
    lcd_show_8dot(x+40, y+2*35,  Bmp_zg,     WHITE,BLACK);//���
    lcd_show_8dot(x+80, y+2*35,  Bmp_wd,     WHITE,BLACK);//�¶�

  //lcd_show_8dot(x,    y+3*35,  Bmp_dt,     WHITE,BLACK);//����
    lcd_show_8dot(x+40, y+3*35,  Bmp_zg,     WHITE,BLACK);//���
    lcd_show_8dot(x+80, y+3*35,  Bmp_DY,     WHITE,BLACK);//��ѹ

  //lcd_show_8dot(x,    y+4*35,  Bmp_dt,     WHITE,BLACK);//����
    lcd_show_8dot(x+40, y+4*35,  Bmp_zdi,     WHITE,BLACK);//���
    lcd_show_8dot(x+80, y+4*35,  Bmp_DY,     WHITE,BLACK);//��ѹ


x=x+338;//��λ����
    lcd_show_8dot(x,    y+0*35, Bmp_A,      WHITE, BLACK);//
    lcd_show_8dot(x,    y+1*35, Bmp_V,      WHITE, BLACK);//
    lcd_show_8dot(x,    y+2*35, Bmp_deg,    WHITE, BLACK);//
    lcd_show_8dot(x,    y+3*35, Bmp_V,      WHITE, BLACK);//
    lcd_show_8dot(x,    y+4*35, Bmp_V,      WHITE, BLACK);//


}
void update_battery4(){
  unsigned int  s,i=0,j=0,temp=1000;
  unsigned int  x,y;
  unsigned char temp8[10];
//////////////////////��һ��////////////////////
x=305-32;y=84-9;
//����ܵ�ѹ
  temp=DC_voltage/10;
  if(temp>=1000){
     temp=(temp-1000);s=12;
    }else{
     temp=(1000-temp);s=11;
    }
  update_dl(x,    y+0*35,temp,3,s,YELLOW);
//������������
  temp=CD_current/10;
  if(temp>=1000){
     temp=(temp-1000);s=12;
    }else{
     temp=(1000-temp);s=11;
    }
  update_dl(x,    y+1*35,temp,3,s,YELLOW);
//�������ŵ����
  temp=FD_current/10;
  if(temp>=1000){
     temp=(temp-1000);s=12;
    }else{
     temp=(1000-temp);s=11;
    }
  update_dl(x,    y+2*35,temp,3,s,YELLOW);
//��Ե����ֵ
  print_SZ_2(x-16,  y+3*35,anode_R1,5,0,YELLOW);
//��Ե����ֵ
  print_SZ_2(x-16,  y+4*35,negative_R1,5,0,YELLOW);
//���״̬1-5
  for(j=0;j<5;j++){ 
     temp8[0]=DC_Status[j];
   for(i=0;i<8;i++){     
     lcd_show_8dot(x+48-i*16,y+35*(j+5),BMP_SZ_3[temp8[0]&0x01],YELLOW,BLACK);
     temp8[0]>>=1;
   } 
  } 

//////////////////////�ڶ���////////////////////
x=698-32;y=84-9;

//��ŵ����
  temp=DC_current/10;
  if(temp>=1000){
     temp=(temp-1000);s=12;
    }else{
     temp=(1000-temp);s=11;
    }
  update_dl(x,    y+0*35,temp,3,s,YELLOW);
//����ƽ����ѹ
  temp=Vpj-10000;
  print_SZ_2(x-16,  y+1*35,temp,4,2,YELLOW);
//��������¶�
  update_deg(x,y+2*35,Tmax1,YELLOW);
//������ߵ�ѹ
  temp=Vmax-10000;
  print_SZ_2(x-16,  y+3*35,temp,4,2,YELLOW);
//������͵�ѹ
  temp=Vmin-10000;
  print_SZ_2(x-16,  y+4*35,temp,4,2,YELLOW);


}

void BMSFrame(unsigned char ID){
  LCD_DrawRect(0,60,800,365,BLACK);
  //��ʾ������
  LCD_DrawImage1BPP(578-8,   30,Bmp_Gong,GREEN,BLACK);//��
  LCD_DrawImage1BPP(578-8+50,30,Bmp_YE,  GREEN,BLACK);//ҳ
  print_SZ_2(578-8+33-8,    39-9,4,1,0,YELLOW);//4
  
  LCD_DrawImage1BPP(700-25,30,Bmp_DI,GREEN,BLACK);//��
  LCD_DrawImage1BPP(700+25,30,Bmp_YE,GREEN,BLACK);//ҳ
  
  print_SZ_2(700,30,ID+1,1,0,YELLOW);//ҳ����
  
       if(ID==0)     disp_battery4();
  else if(ID==1)     disp_battery3();
  else if(ID==2)     disp_battery1();
  else if(ID==3)     disp_battery2();
  
}

void BMSUpdate(unsigned char ID){   
       if(ID==0)     update_battery4();
  else if(ID==1)     update_battery3();
  else if(ID==2)     update_battery1();
  else if(ID==3)     update_battery2();
}

void frmBMS(void) {
    static unsigned char ID=1;
    if (f_index == 0) { //ֻ����һ��
        f_index = 1;
        key_up=1;
        ID=3;
        key_set=0;
      //LCD_DrawRect(0,60,800,365,BLACK);
        LCD_DrawImage1BPP(340,30,    BMP_DC,      GREEN, BLACK); //���
        LCD_DrawImage1BPP(340+40,30, BMP_STSTEM,  GREEN, BLACK); //ϵͳ
        LCD_DrawImage1BPP(340+80,30, BMP_Message, GREEN, BLACK); //��Ϣ
    } else if (f_index == 1) {
        f_index = 1;
        BMSUpdate(ID);
    } else {
        f_index = 0;
    }
  
    if(key_up){
       if(ID>=3) ID=0;
       else      ID++;
    }
    
    if(key_AV){
       if(ID>0)  ID--;
       else      ID=3;
    }

    if(key_AV||key_up){
       key_up=0;
       key_AV=0;    
       BMSFrame(ID);
    }
    
    if (key_set) {//����������
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
void FuzhuFrame(void) {
     unsigned char i = 0;
     
x=7;y=68;
   for(i=0;i<11;i++){
    LCD_DrawRect(x,y+i*35,786, 1,GRAY);//-
   }
    LCD_DrawRect(x,y,1, 350,GRAY);//|��
x=269;
   //LCD_DrawRect(x,y,1, 350,GRAY);//|��1
x=400;
    LCD_DrawRect(x,y,1, 350,GRAY);//|��
x=531;
   //LCD_DrawRect(x,y,1, 350,GRAY);//|��2
x=793;
    LCD_DrawRect(x,y,1, 350,GRAY);//|��

///////////////////////��һ��///////////////////////  
x=10;y=84-9; 
    for(i=0;i<8;i++){
    lcd_show_9dot(x,    y+i*35,Bmp_Fuzhu_1_L_1[i],WHITE,BLACK);//DCDC��Ϣ 
    }

x=x+338;//��λ����
    for(i=0;i<7;i++){
    lcd_show_9dot(x,    y+i*35,Bmp_Fuzhu_1_L_2[i],WHITE,BLACK);//DCDC��Ϣ 
    }

///////////////////////�ڶ���///////////////////////
x=463-58;y=84-9; 
    for(i=0;i<7;i++){
    lcd_show_9dot(x,    y+i*35,Bmp_Fuzhu_1_R_1[i],WHITE,BLACK);//DCDC��Ϣ 
    }

x=x+338;//��λ����
    for(i=0;i<4;i++){
    lcd_show_9dot(x,    y+i*35,Bmp_Fuzhu_1_R_2[i],WHITE,BLACK);//DCDC��Ϣ 
    }

}

void FuzhuUpdate(void) {
  unsigned int i=0,s,temp=1000;
  unsigned char color=0;
//////////////////////��һ��////////////////////
x=305-32;y=84-9;
//DCDC�����ѹ
  temp=DCDC_SC_voltage/10;
  if(temp>=1000){
     temp=(temp-1000);s=12;
    }else{
     temp=(1000-temp);s=11;
    }
  update_dl(x,    y+0*35,temp,3,s,YELLOW);
//DCDC�������
  temp=DCDC_SC_current/10;
  if(temp>=1000){
     temp=(temp-1000);s=12;
    }else{
     temp=(1000-temp);s=11;
    }
  update_dl(x,    y+1*35,temp,3,s,YELLOW);
//DCDC�����ѹ
  temp=DCDC_SR_voltage/10;
  if(temp>=1000){
     temp=(temp-1000);s=12;
    }else{
     temp=(1000-temp);s=11;
    }
  update_dl(x,    y+2*35,temp,3,s,YELLOW);
//DCDCɢ�����¶�
  update_deg(x,y+3*35,DCDC_temperature,YELLOW);
//DCDC���ϴ���
  print_SZ_2(x,    y+4*35,DCDC_fault,4,0,YELLOW);
//���˶Եؾ�Ե����
  print_SZ_2(x-16,    y+5*35,anode_R,5,0,YELLOW);
//���˶Եؾ�Ե����
  print_SZ_2(x-16,    y+6*35,negative_R,5,0,YELLOW);
//��ԵLIFE
  print_SZ_2(x,    y+7*35,R_life,4,0,YELLOW);
//////////////////////�ڶ���////////////////////
x=698-32;y=84-9;
//DCAC W���������
  temp=DCAC_W_current/10;
  if(temp>=1000){
     temp=(temp-1000);s=12;
    }else{
     temp=(1000-temp);s=11;
    }
  update_dl(x,    y+0*35,temp,3,s,YELLOW);
//DCAC V���������
  temp=DCAC_V_current/10;
  if(temp>=1000){
     temp=(temp-1000);s=12;
    }else{
     temp=(1000-temp);s=11;
    }
  update_dl(x,    y+1*35,temp,3,s,YELLOW);
//DCAC U���������
  temp=DCAC_U_current/10;
  if(temp>=1000){
     temp=(temp-1000);s=12;
    }else{
     temp=(1000-temp);s=11;
    }
  update_dl(x,    y+2*35,temp,3,s,YELLOW);
//DCAC ɢ�����¶�
  update_deg(x,y+3*35,DCAC_temperature,YELLOW);
//DCAC ���ϴ���
  print_SZ_2(x,    y+4*35,DCAC_fault,4,0,YELLOW);
//��Ե�ȼ�
  print_SZ_2(x,    y+5*35,eror_R,4,0,YELLOW);
//����©�籨��
  lcd_show_8dot(x+10,  y+6*35+1, Bmp_X,      WHITE, BLACK);//
  if(R_ID==0xAA){
  lcd_show_8dot(x+32, y+6*35, Bmp_A,YELLOW, BLACK);//
  lcd_show_8dot(x+48, y+6*35, Bmp_A,YELLOW, BLACK);//
  }else {
  print_SZ_2(x+32, y+6*35,(5),1,0,YELLOW);
  print_SZ_2(x+48, y+6*35,(5),1,0,YELLOW);
  }
  x=463-58;x=x+338;//��λ����
  if(R_ID ==0xAA){i=1;color=GREEN;}
  else           {i=0;color=RED;  }
  lcd_show_8dot(x,    y+6*35, Bmp_ST[i],   color, BLACK);//����������


}

void frmFuzhu(void) {
    if (f_index == 0) { //ֻ����һ��
        f_index = 1;
        LCD_DrawRect(0,60,800,365,BLACK);
        LCD_DrawImageSBPP(340,   30,Bmp_menu_1[7],  GREEN, BLACK); //����ϵͳ��Ϣ8
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
    }

    if (key_set) {//����������
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
    LCD_DrawRect(x,y,1, 350,GRAY);//|��
x=269;
   //LCD_DrawRect(x,y,1, 350,GRAY);//|��1
x=400;
    LCD_DrawRect(x,y,1, 350,GRAY);//|��
x=531;
   //LCD_DrawRect(x,y,1, 350,GRAY);//|��2
x=793;
    LCD_DrawRect(x,y,1, 350,GRAY);//|��

///////////////////////��һ��/////////////////////// 
y=84-9; 
x=203-48;
    lcd_show_9dot(x,    y+0*35,  Bmp_MHQi_1_L_1[0], WHITE,BLACK);//�����װ��
    //lcd_show_9dot(x,    y+5*35,  Bmp_PDHe_2_L_1[0], WHITE,BLACK);//������Ϣ
x=10;
    for(i=1;i<5;i++){
    lcd_show_9dot(x,    y+(i+0)*35,  Bmp_MHQi_1_L_1[i],    WHITE,BLACK);//�����װ��
    } 
    
    //������Ϣ
    for(i=1;i<4;i++){
    //lcd_show_9dot(x,    y+(i+5)*35,  Bmp_PDHe_2_L_1[i],    WHITE,BLACK);//������Ϣ
    }

x=x+338;//��λ����
    //lcd_show_8dot(x,    y+6*35, Bmp_V,      WHITE, BLACK);//
    //lcd_show_8dot(x,    y+7*35, Bmp_A,      WHITE, BLACK);//
    //lcd_show_8dot(x,    y+8*35, Bmp_deg,    WHITE, BLACK);//
    

///////////////////////�ڶ���///////////////////////
y=84-9; 
x=203-60+393;
    lcd_show_9dot(x,    y+0*35,  Bmp_YWu_1_R_1[0],    WHITE,BLACK);//������װ��
x=463-58;

    for(i=1;i<7;i++){
    lcd_show_9dot(x,    y+i*35,  Bmp_YWu_1_R_1[i],    WHITE,BLACK);//������װ��
    }

}

void MHQUpdate(void) {
  unsigned int  i=0,j=0,temp=1000;
  unsigned char color,s;
  unsigned char temp8[10];
//////////////////////��һ��////////////////////
x=305-32;y=84-9;
//�������
  print_SZ_2(x,  y+1*35,MHQ_DCBOX,4,0,YELLOW);
//�����ϵͳԤ������
  print_SZ_2(x,  y+2*35,MHQ_YJJB,4,0,YELLOW);
//�����������
  temp=MHQ_fault;
  lcd_show_8dot(x+32-22,  y+3*35+1, Bmp_X,      WHITE, BLACK);//
  print_SZ_2(x+32, y+3*35,((temp&0XF0)>>4),1,0,YELLOW);
  print_SZ_2(x+48, y+3*35,((temp&0X0F)),   1,0,YELLOW);
//����Уʱ
  temp=MHQ_TIME;
  if(temp==0xAA)color=YELLOW;else color=BLACK;//BLACK;
  lcd_show_8dot(x+32+8,    y+4*35, Bmp_ON, color, BLACK);//
  
/*
//���ص�ѹ
  print_SZ_2(x, y+6*35,(XDC_voltage>>1),3,1,YELLOW);
//���ص���
  temp=XDC_current*0.05;
  if(temp>=1600){
     temp=(temp-1600);s=12;
    }else{
     temp=(1600-temp);s=11;
    }
  update_dl(x,    y+7*35,temp,3,s,YELLOW);
//�����¶�
  update_deg(x,y+8*35,PDH_temp,YELLOW);
*/  
//////////////////////�ڶ���////////////////////
x=698-32;y=84-9;
//��վ����״̬
//��վ��״̬
//��վ����״̬
//��վӲ��״̬
  for(j=0;j<4;j++){ 
     temp8[0]=YW_Status[j];
   for(i=0;i<8;i++){     
     lcd_show_8dot(x+48-i*16,y+35*(j+1),BMP_SZ_3[temp8[0]&0x01],YELLOW,BLACK);
     temp8[0]>>=1;
   } 
  } 

//ϵͳ��״̬
  print_SZ_2(x,  y+5*35,YW_Status[4],4,0,YELLOW);
//LIFE
  print_SZ_2(x,  y+6*35,YW_Status[5],4,0,YELLOW);

}

void frmMHQ(void) {
    if (f_index == 0) { //ֻ����һ��
        f_index = 1;
        LCD_DrawRect(0,60,800,365,BLACK);
        LCD_DrawImageSBPP(340,   30,Bmp_menu_1[6],  GREEN, BLACK); //����ϵͳ��Ϣ7
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

    if (key_set) {//����������
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
void DebugFrame(void) {
     unsigned char i=0,j=0;
x=7;y=68;
   for(i=0;i<11;i++){
    LCD_DrawRect(x,y+i*35,786, 1,GRAY);//-
   }
    LCD_DrawRect(x,y,1, 350,GRAY);//|��
x=269;
   //LCD_DrawRect(x,y,1, 350,GRAY);//|��1
x=400;
    LCD_DrawRect(x,y,1, 350,GRAY);//|��
x=531;
   //LCD_DrawRect(x,y,1, 350,GRAY);//|��2
x=793;
    LCD_DrawRect(x,y,1, 350,GRAY);//|��

///////////////////////��һ��/////////////////////// 
x=10;y=84-9; 
  for(j=0;j<2;j++){
   for(i=0;i<4;i++){
    lcd_show_9dot(x+j*393,   y+i*35, Bmp_Debug_1_L_1,WHITE,0x0000);// 
    
    lcd_show_8dot(x+81+j*393,y+i*35, BMP_SZ_3[j*4+i+1],WHITE,BLACK);//1 
   }
  } 
    lcd_show_9dot(x+0*393,   y+4*35, Bmp_Debug_2_L_1,WHITE,0x0000);//
    
}

void DebugUpdate(void) {
  unsigned int temp[10],i,j=0;

//////////////////////��һ��////////////////////
x=305-32;y=84-9;
    //������״̬
  for(j=0;j<4;j++){ 
     temp[0]=debug_num[j];
   for(i=0;i<8;i++){     
     lcd_show_8dot(x+48-i*16,y+35*j,BMP_SZ_3[temp[0]&0x01],YELLOW,BLACK);
     temp[0]>>=1;
   } 
  } 

     temp[0]=YZT_LIFE;
   for(i=0;i<8;i++){     
     lcd_show_8dot(x+48-i*16,y+35*4,BMP_SZ_3[temp[0]&0x01],YELLOW,BLACK);
     temp[0]>>=1;
   } 
//////////////////////�ڶ���////////////////////
x=698-32;y=84-9;
  for(j=0;j<4;j++){ 
     temp[0]=debug_num[j+4];
   for(i=0;i<8;i++){     
     lcd_show_8dot(x+48-i*16,y+35*j,BMP_SZ_3[temp[0]&0x01],YELLOW,BLACK);
     temp[0]>>=1;
   } 
  }

}

void frmDebug(void) {
    if (f_index == 0) { //ֻ����һ��
        f_index = 1;
        LCD_DrawRect(0,60,800,365,BLACK);
        LCD_DrawImageSBPP(340,   30, Bmp_menu_1[3],  GREEN, BLACK); //����ϵͳ��Ϣ4
        DebugFrame();
    } else if (f_index == 1) {
        f_index = 1;
        DebugUpdate();
    } else {
        f_index = 0;
    }
    if (key_AV) {
        key_AV = 0;
    }

    if (key_up) {
        key_up = 0;
    }

    if (key_set) {//����������
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
void AirFrame(void) {
     unsigned char i = 0;
x=7;y=68;
   for(i=0;i<11;i++){
    LCD_DrawRect(x,y+i*35,786, 1,GRAY);//-
   }
    LCD_DrawRect(x,y,1, 350,GRAY);//|��
x=269;
   //LCD_DrawRect(x,y,1, 350,GRAY);//|��1
x=400;
    LCD_DrawRect(x,y,1, 350,GRAY);//|��
x=531;
   //LCD_DrawRect(x,y,1, 350,GRAY);//|��2
x=793;
    LCD_DrawRect(x,y,1, 350,GRAY);//|��

    if(KT_MODE==0){//Ĭ���ǵ綯�յ�
///////////////////////��һ��/////////////////////// 
x=10;y=84-9; 
//�յ�ϵͳ   
   for(i=0;i<4;i++){
   lcd_show_9dot(x,    y+i*35, Bmp_kt_1_L_1[i],    WHITE,0x0000);//�յ���Ϣ
   }
 
x=x+338;//��λ����
   for(i=0;i<4;i++){
   lcd_show_9dot(x,    y+i*35, Bmp_kt_1_L_2[i],    WHITE,0x0000);//�յ���Ϣ
   }

///////////////////////�ڶ���///////////////////////
x=463-58;y=84-9;
   for(i=0;i<3;i++){
   lcd_show_9dot(x,    y+i*35, Bmp_kt_1_R_1[i],    WHITE,0x0000);//�յ���Ϣ
   }

x=x+338;//��λ����
    lcd_show_8dot(x,    y+0*35, Bmp_A,    WHITE, BLACK);
    
}else{
    ///////////////////////��һ��/////////////////////// 
x=10;y=84-9; 
//�յ�ϵͳ   
   for(i=0;i<4;i++){
   lcd_show_9dot(x,    y+i*35, Bmp_kt_2_L_1[i],    WHITE,0x0000);//�յ�
   }

x=x+338;//��λ����

///////////////////////�ڶ���///////////////////////
x=463-58;y=84-9; 
   for(i=0;i<4;i++){
   lcd_show_9dot(x,    y+i*35, Bmp_kt_2_R_1[i],    WHITE,0x0000);//�յ�
   }

x=x+338;//��λ����
   for(i=0;i<3;i++){
   lcd_show_8dot(x,    y+i*35, Bmp_deg,   WHITE,0x0000); 
   }
    
}

}

void AirUpdate(void) {
  unsigned int s,i=0,j=0,temp=1000;
    if(KT_MODE==0){//Ĭ���ǵ綯�յ�
//////////////////////��һ��////////////////////
x=305-32;y=84-9;
//�յ�����
  print_SZ_2(x,y+0*35,KT_fuhe*0.4,4,0,YELLOW);
//�յ��¶�
   for(i=0;i<3;i++){
     temp=KT_temp[i];
     update_deg(x,y+(i+1)*35,temp,YELLOW);
   }

//////////////////////�ڶ���////////////////////
x=698-32;y=84-9;
//ֱ�������
  temp=KT_current/10;
  if(temp>=1000){
     temp=(temp-1000);s=12;
    }else{
     temp=(1000-temp);s=11;
    }
  update_dl(x,    y+0*35,temp,3,s,YELLOW);
//����״̬
  temp=KT_Status[0];
  for(i=0;i<8;i++){     
     lcd_show_8dot(x+48-i*16, y+1*35,BMP_SZ_3[temp&0x01],YELLOW,BLACK);
     temp>>=1;
  }  
//LIFE 
  print_SZ_2(x,    y+2*35,KT_life,4,0,YELLOW);

}else{
    
//////////////////////��һ��////////////////////
x=305-32;y=84-9;
//�յ����ϴ���
//���״̬
//����״̬
 for(j=0;j<3;j++){
     temp=KT_Status[j];     
   for(i=0;i<8;i++){
     lcd_show_8dot(x+48-i*16, y+j*35,BMP_SZ_3[temp&0x01],YELLOW,BLACK);
     temp>>=1;
   }
 }
//LIFE 
  print_SZ_2(x,    y+3*35,KT_life,4,0,YELLOW);

//////////////////////�ڶ���////////////////////
x=698-32;y=84-9;
//�յ��¶�
//����
//����
//�趨
   for(i=0;i<3;i++){
     temp=KT_temp1[i]>>1;
     update_deg1(x,y+(i)*35,temp,YELLOW);
   }
//��������
  temp=KT_ctrl;
  for(i=0;i<8;i++){     
     lcd_show_8dot(x+48-i*16, y+3*35,BMP_SZ_3[temp&0x01],YELLOW,BLACK);
     temp>>=1;
  }  
     
}
  
}

void frmAir(void) {
    if (f_index == 0) { //ֻ����һ��
        f_index = 1;
        LCD_DrawRect(0,60,800,365,BLACK);
        LCD_DrawImageSBPP(340,   30,Bmp_menu_1[5],  GREEN, BLACK); //�յ�ϵͳ��Ϣ6
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
    }

    if (key_set) {//����������
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
//������: void frm_speed(void)
//����:  ���ô���
//����:  ȫ�ֱ���
**********************************************************************/
void frm_speed(void){
  if(f_index==0){
    f_index=1;
    key_set =0;
    key_duble=0;
    LCD_DrawRect(0,0, 800,50, BLACK);
    LCD_DrawRect(0,60,800,365,BLACK);
    LCD_DrawImage1BPP(360,30,Bmp_csu, GREEN,BLACK);//����
    LCD_DrawImage1BPP(400,30,Bmp_subi,GREEN,BLACK);//�ٱ�
    
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

//��������
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
    LCD_DrawImage1BPP(360,30,Bmp_csu, GREEN,BLACK);//����
    LCD_DrawImage1BPP(400,30,Bmp_subi,GREEN,BLACK);//�ٱ�
    
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
    //��֤����     bcd[2]*1000+ bcd[0]*100+bcd[3]*10+bcd[1];//�任�����A
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
    LCD_DrawImage1BPP(336+24,   140,Bmp_subi,color,BLACK);//�ٱ� 
    LCD_DrawImage1BPP(336+40+24,140,Bmp_SZhi,color,BLACK);//����
    if(id==1) color=GREEN;
    else      color=WHITE;
    LCD_DrawImage1BPP(300+24, 190,BMP_SZ_3[2],color,BLACK);
    LCD_DrawImage1BPP(316+24, 190,BMP_SZ_3[10],color,BLACK);
    LCD_DrawImage1BPP(336+24, 190,Bmp_LCheng,color,BLACK);//���
    LCD_DrawImage1BPP(376+24, 190,Bmp_SZhi,  color,BLACK);//���� 

    if(id==2) color=GREEN;
    else      color=WHITE;
    LCD_DrawImage1BPP(300+24, 240,BMP_SZ_3[3],color,BLACK);
    LCD_DrawImage1BPP(316+24, 240,BMP_SZ_3[10],color,BLACK);
    LCD_DrawImage1BPP(336+24, 240,Bmp_TChu,color,BLACK);//�˳� 
}
void frm_system(void){
  static unsigned char ID=0;
  if(f_index==0){
     f_index=1;    
     LCD_DrawRect(0,60,800,365,BLACK);
     LCD_DrawImage1BPP(360,30,Bmp_csu, GREEN,BLACK);//����
     LCD_DrawImage1BPP(400,30,Bmp_subi,GREEN,BLACK);//�ٱ�
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
   frmID=ID+33; //�˵��Ŵ�2---7��ʼ 
   if(frmID>=35)frmID=0; //���������� 
  }
}

//���������
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
    
    LCD_DrawImage1BPP(360,30,Bmp_LCheng,GREEN,BLACK);//���
    LCD_DrawImage1BPP(400,30,Bmp_SZhi,GREEN,BLACK);//����
    
    LCD_DrawImage1BPP(200+60,185,Bmp_ODO,WHITE,BLACK);//�ܼ�
    LCD_DrawImage1BPP(240+60,185,Bmp_LCheng,WHITE,BLACK);//���  

    LCD_DrawImage1BPP(440+60,187,Bmp_Km, WHITE,BLACK);//��λ Km 
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
    while (delay_cnt > 1); //��ʱ10Ms
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
    LCD_DrawImage1BPP(360,30,Bmp_subi,GREEN,BLACK);//�ٱ�
    LCD_DrawImage1BPP(400,30,Bmp_SZhi,GREEN,BLACK);//����
  
    LCD_DrawImage1BPP(300+60,170,Bmp_subi,YELLOW,BLACK);//
    LCD_DrawImage1BPP(390+60,170,Bmp_csu, YELLOW,BLACK); //

    LCD_DrawImage1BPP(430+60,170,Bmp_kmh,GREEN,BLACK); // /h  
 
    LCD_DrawImage1BPP(210+60,205,BMP_SZ_3[1],YELLOW,BLACK);// 
    LCD_DrawImage1BPP(210+60,245,BMP_SZ_3[2],YELLOW,BLACK);//

  //x=180,y=120; 
  for(i=0;i<4;i++){
    LCD_DrawRect(180+60,120+35+40*i,320,2,GRAY);//��  
  }
    LCD_DrawRect(180+60,120+35,2,120,GRAY); //��
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
    print_SZ_2(x+210+60,y+85,Vspeed,4,1,GREEN);//����

  //Ŀ��ֵ
    print_SZ_2(x+100+60,y+125,new_pluse,5,0,RED); // 
    Ftemp=30.0*DJ_speed; //���� 
    temp=(unsigned int)(Ftemp/new_pluse);    //����
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
  //Read_enTime();  //ȡ�� ʹ�ܴ���
    new_pluse=e_hm_pulse;//
  //new_pluse=HM_PLUSE;  //  
  //enTime_flag=1;  //ʹ���趨������¼
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
     EEROM_WriteHMPulse();//д��
     EEROM_ReadHMPulse(); //���� У��  
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
    if (alarm_update_flag == 0) { //3S ����һ�� 
        //LCD_DrawRect(x, y, 350 + 85 + 10, 36, BLACK); //�����ʾ����
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
                //if(LED16){ //���ص�ѹ��  
                if(BAT24V_count >= BAT24_TIME){//���ص�ѹ��
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
                if(Vspeed>690){ //���ѳ���      
                LCD_DrawImage1BPP(x, y, Bmp_nycs,Fcolor,color);
                w=x+80;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                } 
            case 6: 
                al_index=7; 
                //if(1){
                if(DC_Status[0]&0X03){ //��ص����ѹ,����
                LCD_DrawImage1BPP(x,    y, Bmp_dc, Fcolor,color);
                LCD_DrawImage1BPP(x+40, y, Bmp_dt, Fcolor,color);
                if(DC_Status[0]&0X01)LCD_DrawImage1BPP(x+80, y, Bmp_Guo,Fcolor,color);
                else                 LCD_DrawImage1BPP(x+80, y, Bmp_Qian,Fcolor,color);
                LCD_DrawImage1BPP(x+96, y, Bmp_Ya, Fcolor,color);   
                w=x+96+16;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                }
            case 7: 
                al_index=8; 
                //if(1){
                if(DC_Status[0]&0X0c){ //���SOC���ߡ���
                LCD_DrawImage1BPP(x,    y, Bmp_dc, Fcolor,color);
                LCD_DrawImage1BPP(x+40, y, Bmp_SOC,Fcolor,color);
                if(DC_Status[0]&0X04)LCD_DrawImage1BPP(x+72, y, Bmp_gg, Fcolor,color);
                else                 LCD_DrawImage1BPP(x+72, y, Bmp_gd, Fcolor,color);
                w=x+72+40;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                }	
            case 8: 
                al_index=9; 
                //if(1){
                if(DC_Status[0]&0X10){ //�ڲ�ͨѶʧ��
                LCD_DrawImage1BPP(x,     y, Bmp_nb, Fcolor,color);
                LCD_DrawImage1BPP(x+40,  y, Bmp_CANST, Fcolor,color);
                LCD_DrawImage1BPP(x+112, y, Bmp_ST[0],Fcolor,color);
                w=x+112+40;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                }
            case 9: 
                al_index=10; 
                //if(1){
                if(DC_Status[0]&0X60){ //����ܵ�ѹ����,��
                LCD_DrawImage1BPP(x,    y, Bmp_dc,  Fcolor,color);
                LCD_DrawImage1BPP(x+40, y, Bmp_zong,Fcolor,color);
                LCD_DrawImage1BPP(x+56, y, Bmp_DY,  Fcolor,color);
                if(DC_Status[0]&0X20)LCD_DrawImage1BPP(x+96, y, Bmp_gd,  Fcolor,color);//����
                else                 LCD_DrawImage1BPP(x+96, y, Bmp_gg,  Fcolor,color);//����
                w=x+96+40;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                }
            case 10: 
                al_index=11; 
                //if(1){
                if(DC_Status[0]&0X80){ //��ز�����
                LCD_DrawImage1BPP(x,    y, Bmp_dc,  Fcolor,color);
                LCD_DrawImage1BPP(x+40, y, Bmp_Bu,  Fcolor,color);
                LCD_DrawImage1BPP(x+56, y, Bmp_JHeng,  Fcolor,color);
                w=x+56+40;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                }   
            case 11: 
                al_index=12; 
                //if(1){
                if(DC_Status[1]&0X01){ //�����������
                LCD_DrawImage1BPP(x,    y, Bmp_dc,  Fcolor,color);
                LCD_DrawImage1BPP(x+40, y, Bmp_wsgk,  Fcolor,color);
                w=x+40+80;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                } 
            case 12: 
                al_index=13; 
                //if(1){
                if(DC_Status[1]&0X02){ //���������
                LCD_DrawImage1BPP(x,    y, Bmp_dc,  Fcolor,color);
                LCD_DrawImage1BPP(x+40, y, Bmp_YWu,  Fcolor,color);
                LCD_DrawImage1BPP(x+80, y, Bmp_bj,  Fcolor,color);
                w=x+80+40;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                } 
            case 13: 
                al_index=14; 
                //if(1){
                if( (DC_Status[1]&0X04) ||
                  //(TYBJ_state[1]&0x08)||
                             (eror_R==1)||
                             (eror_R==2)
                  ){ //��Ե����
                LCD_DrawImage1BPP(x,    y, Bmp_dc, Fcolor,color);
                LCD_DrawImage1BPP(x+40, y, Bmp_jy, Fcolor,color);
                LCD_DrawImage1BPP(x+80, y, Bmp_bj,Fcolor,color);  
                w=x+80+40;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                }
            case 14: 
                al_index=15; 
                //if(1){
                if(DC_Status[1]&0X18){ //�ŵ��������
                LCD_DrawImage1BPP(x,    y, Bmp_dc,  Fcolor,color);
                if(DC_Status[1]&0X08)LCD_DrawImage1BPP(x+40, y, Bmp_fd,   Fcolor,color);//�ŵ�
                else                 LCD_DrawImage1BPP(x+40, y, Bmp_cdian,Fcolor,color);//���
                LCD_DrawImage1BPP(x+80, y, Bmp_dl, Fcolor,color);
                LCD_DrawImage1BPP(x+120,y, Bmp_gg, Fcolor,color);
                w=x+120+40;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                }
            case 15: 
                al_index=16; 
                //if(1){
                if(DC_Status[1]&0X20){ //�¶ȹ���
                LCD_DrawImage1BPP(x,    y, Bmp_dc,  Fcolor,color);
                LCD_DrawImage1BPP(x+40, y, Bmp_wd,  Fcolor,color);
                LCD_DrawImage1BPP(x+80, y, Bmp_gg,  Fcolor,color);
                w=x+80+40;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                } 
            case 16: 
                al_index=17; 
                //if(1){
                if(DC_Status[1]&0X40){ //�����������
                LCD_DrawImage1BPP(x,    y, Bmp_ws,  Fcolor,color);
                LCD_DrawImage1BPP(x+40, y, Bmp_jic,  Fcolor,color);
                LCD_DrawImage1BPP(x+80, y, Bmp_gg,  Fcolor,color);
                w=x+80+40;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                } 
            case 17: 
                al_index=18; 
                //if(1){
                if(DC_Status[1]&0X80){ //�¶ȼ������
                LCD_DrawImage1BPP(x,    y, Bmp_wd,  Fcolor,color);
                LCD_DrawImage1BPP(x+40, y, Bmp_jic,  Fcolor,color);
                LCD_DrawImage1BPP(x+80, y, Bmp_gg,  Fcolor,color);
                w=x+80+40;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                } 
            case 18: 
                al_index=19; 
                //if(1){
                if(DC_Status[2]&0X40){ //���ڳ�� 
                LCD_DrawImage1BPP(x,    y, Bmp_ZZai,  Fcolor,color);
                LCD_DrawImage1BPP(x+40, y, Bmp_cdian,  Fcolor,color);
                w=x+40+40;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                }                 
            case 19: 
                al_index=20; 
                //if(1){
                if(DC_Status[3]&0X02){ //������¶ȹ��� 
                LCD_DrawImage1BPP(x,    y, Bmp_CDZuo,  Fcolor,color);
                LCD_DrawImage1BPP(x+56, y, Bmp_wd,  Fcolor,color);
                LCD_DrawImage1BPP(x+96, y, Bmp_gg,  Fcolor,color);                
                w=x+96+40;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                }         
            case 20: 
                al_index=21; 
                //if(1){
                if(DC_Status[3]&0X01){ //��ػ���Ԥ��
                LCD_DrawImageSBPP(x,    y, Bmp_Display_bj_20,    Fcolor,color);
                w=x+80+40;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                }        
            case 21: 
                al_index=22; 
                //if(1){
                if(DC_Status[4]&0X02){ //��ع����
                LCD_DrawImageSBPP(x,    y, Bmp_Display_bj_21,    Fcolor,color);
                w=x+56+40;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                }                     
            case 22: 
                al_index=23; 
                //if(1){
                if(DC_Status[4]&0X01){ //���SOC����   
                LCD_DrawImageSBPP(x,    y, Bmp_Display_bj_22,    Fcolor,color);
                w=x+72+40;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                }                  
            case 23: 
                al_index=24; 
                //if(1){
                if((TYBJ_state[1]&0x08)){ //������Ե����
                LCD_DrawImageSBPP(x,    y, Bmp_Display_bj_23,    Fcolor,color);
                w=x+80+40;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                }                      
            case 24: 
                al_index=25; 
                //if(1){
                if((TYBJ_state[1]&0x80)||  //��������������¶ȱ���
                   (TYBJ_state[4]&0X40)    //����������
                  ){ 
                LCD_DrawImageSBPP(x,    y, Bmp_Display_bj_24,    Fcolor,color);
                w=x+136+40;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                }                     
            case 25: 
                al_index=26; 
                //if(1){
                if((TYBJ_state[2]&0x02)||  //��������¶ȱ���
                   (TYBJ_state[5]&0X01)    //�������
                  ){   
                LCD_DrawImageSBPP(x,    y, Bmp_Display_bj_25,    Fcolor,color);
                w=x+80+40;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                }                  
            case 26: 
                al_index=27; 
                //if(1){
               if((TYBJ_state[5]&0X04)){    //�������
                LCD_DrawImageSBPP(x,    y, Bmp_Display_bj_26,    Fcolor,color);
                w=x+80+40;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                }                      
            case 27: 
                al_index=0; 
                //if(1){
                if(YW_Status[1]>0){ //����������
                LCD_DrawImageSBPP(x,    y, Bmp_Display_bj_27,    Fcolor,color);
                w=x+80+40;LCD_DrawRect(w, y, 250-w, 36, color);
                alarm_update_flag = 1;
                break; 
                } 
                
            default:
                al_index=0; 
                LCD_DrawRect(x, y, 250, 36, color); //�����ʾ����
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
        case 7:
            frmDebug();
            break;      
        case 8:
            frmAir();
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
            frm_system();//���ò�����Ϣ
            break;
        case 33:
            frm_setDATE();//���ò�����Ϣ
            break;
        case 34:
            frm_miles();//���ò�����Ϣ
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



