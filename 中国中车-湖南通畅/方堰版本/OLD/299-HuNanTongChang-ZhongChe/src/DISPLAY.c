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
unsigned char color_old[24] = {};

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
 */
void print_D(unsigned int x, unsigned int y, //��2������ʾ
        unsigned char dat) { //��ʾ������       
    unsigned char bcd[8], i = 0;
    for (i = 0; i < 8; i++) {
        bcd[i] = dat % 2;
        dat = dat / 2;
        LCD_DrawImage1BPP(x + 16 * (7 - i), y, BMP_SZ_1[bcd[i]], WHITE, BLACK);
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

//������

/*********************************************************
//������: void mainFrame(void)
//����: ��ʾ�����治��Ҫ���µ�����,�����ʽ
//����: ��
 *********************************************************/
void mainFrame(void) {
    unsigned int i;
    LCD_Clear();
    LCD_DrawRect(0, 0, 800, 1, GRAY);
    LCD_DrawRect(0, 64 - 5, 800, 1, GRAY);
    for (i = 1; i < 12; i++) {
        LCD_DrawRect(4 + 66 * i, 0, 1, 64 - 5, GRAY);
    }
    //�����ӵķ���Ƭ���2016/11/1
    LCD_DrawRect(136, 128 - 10, 528, 1, GRAY);
    for (i = 1; i < 10; i++) {
        LCD_DrawRect(70 + 66 * i, 64 - 5, 1, 64 - 5, GRAY);
    }
    //ÿ�ν��������棬����Ƭ��ɫ���ǻ�ɫ����������ֻ���һ���ϵ���ʾ��ɫ����ҳ��Ͳ���ʾ��ɫ
    for (i = 0; i < 24; i++) {
        color_old[i] = 0;
    }
    LCD_DrawRect(0, 430+13, 800, 1, WHITE); //�ײ�����
    //LCD_DrawRect(0,70,800,3,YELLOW); //��������
    // LCD_DrawImage1BPPZOOM_4(336, 150, BMP_LOGO, BLUE, BLACK); //�ͳ�����
    //������ص��� ��ѹ SOC ���
    LCD_DrawImage1BPP(175, 160 + 13, BMP_Voltage, WHITE, BLACK); //��ѹ
    LCD_DrawRect(225, 150 + 5 + 13, 335, 2, WHITE);
    LCD_DrawRect(225, 150 + 35 + 13, 335, 2, WHITE);
    LCD_DrawRect(225, 155 + 13, 2, 32, WHITE);
    LCD_DrawRect(225 + 83, 145 + 13, 2, 10, WHITE);
    LCD_DrawRect(225 + 83 + 83, 145 + 13, 2, 10, WHITE);
    LCD_DrawRect(225 + 83 + 83 + 83, 145 + 13, 2, 10, WHITE);
    LCD_DrawRect(225 + 83 + 83 + 83 + 84, 155 + 13, 2, 32, WHITE);
    LCD_DrawImage1BPP(225 - 4, 155 - 14 + 13, BMP_SZ[0], WHITE, BLACK); //0
    LCD_DrawImage1BPP(225 + 83 + 83 + 83 + 84 - 12, 155 - 14 + 13, BMP_SZ[8], WHITE, BLACK); //8
    LCD_DrawImage1BPP(225 + 83 + 83 + 83 + 84 - 4, 155 - 14 + 13, BMP_SZ[0], WHITE, BLACK); //0
    LCD_DrawImage1BPP(225 + 83 + 83 + 83 + 84 + 4, 155 - 14 + 13, BMP_SZ[0], WHITE, BLACK); //0   
    LCD_DrawImage1BPP(660, 155 + 13, BMP_V, WHITE, BLACK);

    LCD_DrawImage1BPP(175, 160 + 60 + 13, BMP_Current, WHITE, BLACK); //����
    LCD_DrawRect(225, 150 + 5 + 60 + 13, 335, 2, WHITE);
    LCD_DrawRect(225, 150 + 35 + 60 + 13, 335, 2, WHITE);
    LCD_DrawRect(225, 155 + 60 + 13, 2, 32, WHITE);
    LCD_DrawRect(225 + 83, 145 + 60 + 13, 2, 10, WHITE);
    LCD_DrawRect(225 + 83 + 83 + 83, 145 + 60 + 13, 2, 10, WHITE);
    LCD_DrawRect(225 + 83 + 83 + 83 + 83 + 1, 155 + 60 + 13, 2, 32, WHITE);
    LCD_DrawRect(225 - 12, 155 - 14 + 60 + 7 + 13, 8, 2, WHITE); //-
    LCD_DrawImage1BPP(225 - 4, 155 - 14 + 60 + 13, BMP_SZ[5], WHITE, BLACK); //5
    LCD_DrawImage1BPP(225 + 4, 155 - 14 + 60 + 13, BMP_SZ[0], WHITE, BLACK); //0
    LCD_DrawImage1BPP(225 + 12, 155 - 14 + 60 + 13, BMP_SZ[0], WHITE, BLACK); //0

    LCD_DrawImage1BPP(225 + 83 + 83 - 4, 145 + 60 - 4 + 13, BMP_SZ[0], WHITE, BLACK); //0
    LCD_DrawRect(225 + 83 + 83, 155 + 60 + 13, 2, 32, WHITE);

    LCD_DrawImage1BPP(225 + 83 + 83 + 83 + 84 - 12, 155 - 14 + 60 + 13, BMP_SZ[5], WHITE, BLACK); //5
    LCD_DrawImage1BPP(225 + 83 + 83 + 83 + 84 - 4, 155 - 14 + 60 + 13, BMP_SZ[0], WHITE, BLACK); //0
    LCD_DrawImage1BPP(225 + 83 + 83 + 83 + 84 + 4, 155 - 14 + 60 + 13, BMP_SZ[0], WHITE, BLACK); //0
    LCD_DrawImage1BPP(660, 155 + 60 + 13, BMP_A, WHITE, BLACK);

    LCD_DrawImage1BPP(170, 150 + 5 + 60 + 60 + 13, BMP_SOC, WHITE, BLACK); //SOC
    LCD_DrawRect(225, 150 + 5 + 60 + 60 + 13, 335, 2, WHITE);
    LCD_DrawRect(225, 150 + 35 + 60 + 60 + 13, 335, 2, WHITE);
    LCD_DrawRect(225, 155 + 60 + 60 + 13, 2, 32, WHITE);
    LCD_DrawRect(225 + 83, 145 + 60 + 60 + 13, 2, 10, WHITE);
    LCD_DrawRect(225 + 83 + 83, 145 + 60 + 60 + 13, 2, 10, WHITE);
    LCD_DrawRect(225 + 83 + 83 + 83, 145 + 60 + 60 + 13, 2, 10, WHITE);
    LCD_DrawRect(225 + 83 + 83 + 83 + 84, 155 + 60 + 60 + 13, 2, 32, WHITE);
    LCD_DrawImage1BPP(225 - 4, 155 - 14 + 60 + 60 + 13, BMP_SZ[0], WHITE, BLACK); //0
    LCD_DrawImage1BPP(225 + 83 + 83 + 83 + 84 - 12, 155 - 14 + 60 + 60 + 13, BMP_SZ[1], WHITE, BLACK); //1
    LCD_DrawImage1BPP(225 + 83 + 83 + 83 + 84 - 4, 155 - 14 + 60 + 60 + 13, BMP_SZ[0], WHITE, BLACK); //0
    LCD_DrawImage1BPP(225 + 83 + 83 + 83 + 84 + 4, 155 - 14 + 60 + 60 + 13, BMP_SZ[0], WHITE, BLACK); //0
    LCD_DrawImage1BPP(660, 155 + 60 + 60 + 13, BMP_BAIFENHAO, WHITE, BLACK);

    LCD_DrawImage1BPP(180 - 20 + 2, 365 - 50 + 10 + 13, BMP_DJ, WHITE, BLACK); //���
    LCD_DrawImage1BPP(180 - 20 + 2 + 43, 365 - 50 + 10 + 13, BMP_KZQ, WHITE, BLACK); //������
    //LCD_DrawImage1BPP(180 - 20 + 2 + 43 + 64, 365 - 50 + 10, BMP_Wendu, WHITE, BLACK); //�¶�
    LCD_DrawImage1BPP(225 + 83 + 83 - 22, 365 - 50 + 10 + 13, BMP_T, WHITE, BLACK); //��

    LCD_DrawImage1BPP(225 + 83 + 83 + 2, 365 - 50 + 10 + 13, BMP_DJ, WHITE, BLACK); //���
    LCD_DrawImage1BPP(225 + 83 + 83 + 2 + 43, 365 - 50 + 10 + 13, BMP_Zhuansu, WHITE, BLACK); //ת��
    LCD_DrawImage1BPP(615 - 34, 365 - 50 + 10 + 13, BMP_RPM, WHITE, BLACK); //RPM

    LCD_DrawImage1BPP(180 - 20 + 2, 365 - 50 + 10 + 38 + 13, BMP_Niaosu, WHITE, BLACK); //����
    LCD_DrawImage1BPP(180 - 20 + 2 + 43, 365 - 50 + 10 + 38 + 13, BMP_Yewei, WHITE, BLACK); //Һλ
    LCD_DrawImage1BPP(225 + 83 + 83 - 12, 365 - 50 + 10 + 38 + 13, BMP_Baifenhao, WHITE, BLACK); //%

    LCD_DrawImage1BPP(225 + 83 + 83 + 2, 365 - 50 + 10 + 38 + 13, BMP_System, WHITE, BLACK); //ϵͳ
    LCD_DrawImage1BPP(225 + 83 + 83 + 2 + 43, 365 - 50 + 10 + 38 + 13, BMP_Code, WHITE, BLACK); //����

    LCD_DrawImage1BPP(225 + 83 + 83 + 2, 365 - 50 + 10 + 38 * 2 + 13, BMP_s, WHITE, BLACK); //S
    LCD_DrawImage1BPP(225 + 83 + 83 + 2 + 11, 365 - 50 + 10 + 38 * 2 + 13, BMP_p, WHITE, BLACK); //P
    LCD_DrawImage1BPP(225 + 83 + 83 + 2 + 11 + 11, 365 - 50 + 10 + 38 * 2 + 13, BMP_n, WHITE, BLACK); //N
    //LCD_DrawImage1BPP(225 + 83 + 83 + 2+ 11 + 11 + 11 + 2, 365 - 50 + 10 + 38*2, BMP_Maohao, WHITE, BLACK); //:

    //���
    LCD_DrawRect(180 - 20, 365 - 50 + 13, 350 + 85 + 20, 1, WHITE);
    LCD_DrawRect(180 - 20, 365 - 50 + 13, 1, 65 + 50, WHITE);
    LCD_DrawRect(225 + 83 + 83, 365 - 50 + 13, 1, 65 + 50, WHITE);
    LCD_DrawRect(615, 365 - 50 + 13, 1, 65 + 50, WHITE);
    LCD_DrawRect(180 - 20, 365 - 50 + 38 + 13, 350 + 85 + 20, 1, WHITE);
    LCD_DrawRect(180 - 20, 365 - 50 + 38 + 38 + 13, 350 + 85 + 20, 1, WHITE);

    //LCD_DrawImage1BPPZOOM_4(100, 150 + 70 + 60 + 45 + 50, BMP_DW, WHITE, BLACK); //��λ

    //��ѹ��1���
    //����
    LCD_DrawRect(33, 100 + 13, 51, 3, WHITE); //
    LCD_DrawRect(33, 100 + 13, 3, 135, WHITE);
    LCD_DrawRect(84, 100 + 13, 3, 135, WHITE);

    LCD_DrawRect(33, 235 + 13, 3, 135, RED);
    LCD_DrawRect(84, 235 + 13, 3, 138, RED);
    LCD_DrawRect(33, 370 + 13, 51, 3, RED); //

    //���
    LCD_DrawImage1BPP(13, 95 + 13, BMP_SZ[1], RED, BLACK); //1
    LCD_DrawImage1BPP(21, 95 + 13, BMP_SZ[0], RED, BLACK); //0
    LCD_DrawImage1BPP(21, 225 + 13, BMP_SZ[5], RED, BLACK); //5
    LCD_DrawImage1BPP(21, 360 + 13, BMP_SZ[0], RED, BLACK); //0

    LCD_DrawImage1BPP(33 - 7 + 32, 410 + 13, Bmp_Mpa, WHITE, BLACK); //Mpa

    //��ѹ��2���
    LCD_DrawRect(712, 100 + 13, 51, 3, WHITE);
    LCD_DrawRect(712, 100 + 13, 3, 135, WHITE);
    LCD_DrawRect(712 + 51, 100 + 13, 3, 135, WHITE);

    LCD_DrawRect(712, 235 + 13, 3, 135, RED);
    LCD_DrawRect(712 + 51, 235 + 13, 3, 138, RED);
    LCD_DrawRect(712, 370 + 13, 51, 3, RED); //

    LCD_DrawImage1BPP(770, 95 + 13, BMP_SZ[1], RED, BLACK); //1
    LCD_DrawImage1BPP(770 + 8, 95 + 13, BMP_SZ[0], RED, BLACK); //0
    LCD_DrawImage1BPP(770, 225 + 13, BMP_SZ[5], RED, BLACK); //5
    LCD_DrawImage1BPP(770, 360 + 13, BMP_SZ[0], RED, BLACK); //0 

    LCD_DrawImage1BPP(712 - 7 + 32, 410 + 13, Bmp_Mpa, WHITE, BLACK); //Mpa

    /*--------------------------------------------
    ������ʾ�ĸ�ʽΪ:(ODO 000.0Km       00:00          TRIP0000000Km)
    ---------------------------------------------*/
    LCD_DrawImage1BPP(2, 440 + 3 + 13, Bmp_ODO, YELLOW, BLACK); //�ۼ���� ODO  
    //print_SZ_4(2+64+4,440,9999999,7,1,WHITE);

    LCD_DrawImage1BPPZOOM_4(210 - 16, 440 + 13, BMP_HZ_KM, WHITE, BLACK); //��λ Km

    LCD_DrawImage1BPP(240 + 300 + 30, 440 + 3 + 13, Bmp_TRIP, YELLOW, BLACK); //������� TRIF
    //print_SZ_4(240+80+4,440,9999,4,1,WHITE);
    LCD_DrawImage1BPPZOOM_4(404 + 336 + 30, 440 + 13, BMP_HZ_KM, WHITE, BLACK); //��λ Km

}

void disp_miles(void) {//��ʾ���
    print_SZ_1(2 + 64 + 4 + 10, 440 - 2 + 13, total_miles / 10, 7, 0, WHITE);
    print_SZ_1(240 + 80 + 4 + 330 + 30 - 16, 440 - 2 + 13, single_miles, 5, 1, WHITE);
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
    if (frmID == 1) {
        LCD_DrawImage1BPP(x + 260, y, BMP_SZ_1[2], WHITE, BLACK); //2
        LCD_DrawImage1BPP(x + 260 + 16, y, BMP_SZ_1[0], WHITE, BLACK); //0

        if (color_back && (t == 4)) {
            if (t_add) {//�����ã�ʮλ
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
            if (t_add) {//�����ã���λ
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
            if (t_add) {//�����ã�ʮλ
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
            if (t_add) {//�����ã���λ
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
            if (t_add) {//�����ã�ʮλ
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
            if (t_add) {//�����ã���λ
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

void disp_baojing(void) {
    unsigned char color = GRAY;
    //unsigned char color_mode[3];

    if (IN2) color = YELLOW;
    else color = GRAY;
    if (color_old[0] != color) {
        color_old[0] = color;
        LCD_DrawImage1BPP(6, 5, Bmp_baojing[1], color, BLACK); //ABS
    }

    if (IN20) color = RED;
        //else if (IN28 && M_ON) color = GRAY;
    else color = GRAY;
    if (color_old[1] != color) {
        color_old[1] = color;
        LCD_DrawImage1BPP(6 + 66, 5, Bmp_baojing[2], color, BLACK); //ǰ�ſ�
    }

    if (IN27) color = RED;
        //else if (IN26 && M_ON) color = GRAY;
    else color = GRAY;
    if (color_old[2] != color) {
        color_old[2] = color;
        LCD_DrawImage1BPP(6 + 66 * 2, 5, Bmp_baojing[3], color, BLACK); //���ſ�
    }

    if (Charge_Check) color = YELLOW;
    else color = GRAY;
    if (color_old[3] != color) {
        color_old[3] = color;
        LCD_DrawImage1BPP(6 + 66 * 3, 5, Bmp_baojing[9], color, BLACK); //���ȷ��
    }

    if (IN2) color = GREEN;
    else color = GRAY;
    if (color_old[4] != color) {
        color_old[4] = color;
        LCD_DrawImage1BPP(6 + 66 * 4, 5, Bmp_baojing[4], color, BLACK); //����
    }

    if (Warn_level ||
            ((IN22 || IN23 || (Engine_oil_press * 4 <= 70)) && Engine_Speed > 0) ||
            (water_temp > 138))
        color = RED;
    else color = GRAY;
    if (color_old[5] != color) {
        color_old[5] = color;
        LCD_DrawImage1BPP(6 + 66 * 5, 5 + 8, Bmp_STOP, color, BLACK); //��ɫSTOP

    }

    if (rKL5) color = YELLOW;
    else color = GRAY;
    if (color_old[6] != color) {
        color_old[6] = color;
        LCD_DrawImage1BPP(6 + 66 * 6, 5, Bmp_baojing[5], color, BLACK); //����
    }

    if (IN6) color = GREEN;
    else color = GRAY;
    if (color_old[7] != color) {
        color_old[7] = color;
        LCD_DrawImage1BPP(6 + 66 * 7, 5, Bmp_baojing[16], color, BLACK); //С��
    }

    if (rKL15) color = RED;
    else color = GRAY;
    if (color_old[8] != color) {
        color_old[8] = color;
        LCD_DrawImage1BPP(6 + 66 * 8, 5, Bmp_baojing[7], color, BLACK); //�����
    }

    if (rKL1) color = RED;
    else color = GRAY;
    if (color_old[9] != color) {
        color_old[9] = color;
        LCD_DrawImage1BPP(6 + 66 * 9, 5, Bmp_baojing[6], color, BLACK); //ˮλ
    }

    if ((IN24 || (Vcan_count == 30) ||
            (Bcan_count == 30) ||
            (Dcan_count == 30)))
        color = YELLOW;
    else color = GRAY;
    if (color_old[10] != color) {
        color_old[10] = color;
        LCD_DrawImage1BPP(6 + 66 * 10, 5 + 8, Bmp_STOP, color, BLACK); //��ɫSTOP
    }

    if (AC) color = GREEN;
    else color = GRAY;
    if (color_old[11] != color) {
        color_old[11] = color;
        LCD_DrawImage1BPP(6 + 66 * 11, 5, Bmp_baojing[11], color, BLACK); //AC�յ�
    }

    if (Tradition && !Hybrid && !Electric) color = GREEN;
    else color = GRAY;
    if (color_old[12] != color) {
        color_old[12] = color;
        if (color == GREEN) {
            LCD_DrawImage1BPP(138 + 9, 74 - 10, BMP_Chuantong, color, BLACK); //��ͳ
            LCD_DrawImage1BPP(138 + 9, 74 - 10 + 22, BMP_Mode, color, BLACK); //ģʽ
        }
    }

    if (!Tradition && Hybrid && !Electric) color = GREEN;
    else color = GRAY;
    if (color_old[13] != color) {
        color_old[13] = color;
        if (color == GREEN) {
            LCD_DrawImage1BPP(138 + 9, 74 - 10, BMP_Chadian, color, BLACK); //���
            LCD_DrawImage1BPP(138 + 9, 74 - 10 + 22, BMP_Mode, color, BLACK); //ģʽ
        }
    }

    if (!Tradition && !Hybrid && Electric) color = GREEN;
    else color = GRAY;
    if (color_old[14] != color) {
        color_old[14] = color;
        if (color == GREEN) {
            LCD_DrawImage1BPP(138 + 9, 74 - 10, BMP_Chundian, color, BLACK); //����
            LCD_DrawImage1BPP(138 + 9, 74 - 10 + 22, BMP_Mode, color, BLACK); //ģʽ
        }
    }

    if (!Tradition && !Hybrid && !Electric) {
        LCD_DrawImage1BPP(138 + 9, 74 - 10, BMP_Chundian, BLACK, BLACK); //����
        LCD_DrawImage1BPP(138 + 9, 74 - 10 + 22, BMP_Mode, BLACK, BLACK); //ģʽ
    }

    /*
    if (Tradition && M_ON) color_mode[0] = GREEN;
    else color_mode[0] = GRAY;
    if (color_old[12] != color_mode[0]) {
        color_old[12] = color_mode[0];
        LCD_DrawImage1BPP(138 + 9, 74, BMP_Chuantong, color_mode[0], BLACK); //��ͳ
        LCD_DrawImage1BPP(138 + 9, 74 + 22, BMP_Mode, color_mode[0], BLACK); //ģʽ
    }
    
    if (Hybrid && M_ON) color_mode[1] = GREEN;
    else color_mode[1] = GRAY;
    if (color_old[13] != color_mode[1]) {
        color_old[13] = color_mode[1];
        LCD_DrawImage1BPP(138 + 9, 74, BMP_Chadian, color_mode[1], BLACK); //���
        LCD_DrawImage1BPP(138 + 9, 74 + 22, BMP_Mode, color_mode[1], BLACK); //ģʽ
    }

    if (Electric && M_ON) color_mode[2] = GREEN;
    else color_mode[2] = GRAY;
    if (color_old[14] != color_mode[2]) {
        color_old[14] = color_mode[2];
        LCD_DrawImage1BPP(138 + 9, 74, BMP_Chundian, color_mode[2], BLACK); //����
        LCD_DrawImage1BPP(138 + 9, 74 + 22, BMP_Mode, color_mode[2], BLACK); //ģʽ
    }
     */
    if (Mode_S) color = YELLOW;
    else color = GRAY;
    if (color_old[15] != color) {
        color_old[15] = color;
        LCD_DrawImage1BPP(138 + 66 * 1, 74 - 10, Bmp_baojing[10], color, BLACK); //S
    }

    if (Kt) color = GREEN;
    else color = GRAY;
    if (color_old[16] != color) {
        color_old[16] = color;
        LCD_DrawImage1BPP(138 + 66 * 2, 74 - 10, Bmp_baojing[12], color, BLACK); //Kt
    }

    if (High_Voltage) color = RED;
    else color = GRAY;
    if (color_old[17] != color) {
        color_old[17] = color;
        LCD_DrawImage1BPP(138 + 66 * 3 + 9, 74 - 10, BMP_DY, color, BLACK); //��ѹ
        LCD_DrawImage1BPP(138 + 66 * 3 + 9, 74 - 10, BMP_Gao, color, BLACK); //��        
        LCD_DrawImage1BPP(138 + 66 * 3 + 9, 74 - 10 + 20, BMP_Jianxiu, color, BLACK); //����
    }

    if (IN2) color = GREEN;
    else if (moto_warn == 0) color = GRAY;
    if (color_old[18] != color) {
        color_old[18] = color;
        LCD_DrawImage1BPP(138 + 66 * 4, 74 - 10, Bmp_baojing[13], color, BLACK); //��˪
    }

    if (!fKL4) color = RED;
    else color = GRAY;
    if (color_old[19] != color) {
        color_old[19] = color;
        LCD_DrawImage1BPP(138 + 66 * 5, 74 - 10, Bmp_baojing[15], color, BLACK); //��ɲ��Ƭĥ��
    }

    if (!fKL5) color = RED;
    else color = GRAY;
    if (color_old[20] != color) {
        color_old[20] = color;
        LCD_DrawImage1BPP(138 + 66 * 6, 74 - 10, Bmp_baojing[14], color, BLACK); //��ɲ��Ƭĥ��
    }

    if (mKL2) color = RED;
    else color = GRAY;
    if (color_old[21] != color) {
        color_old[21] = color;
        LCD_DrawImage1BPP(138 + 66 * 7, 74 - 10, Bmp_baojing[17], color, BLACK); //�³�����
    }
}

void disp_CAN_baojing(unsigned int x, unsigned int y) {
    static unsigned char al_index = 0;
    if (alarm_update_flag == 0) { //3S ����һ�� 
        //LCD_DrawRect(x, y, 350 + 85 + 10, 36, BLACK); //�����ʾ����
        switch (al_index) {
            case 0:
                al_index = 1;
                if (Vcan_count == 30) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Shuiwen, YELLOW, BLACK); //ˮ����Ϣ��ʧ
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Xinxi, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Diushi, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 1:
                al_index = 2;
                if (Vcan_count == 30) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Jiyou, YELLOW, BLACK); //����ѹ����Ϣ��ʧ
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Yali, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Xinxi, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 42, y + 8, BMP_Diushi, YELLOW, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
            case 2:
                al_index = 3;
                if (Vcan_count == 30 || Bcan_count == 30 || Dcan_count == 30) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Zong, YELLOW, BLACK); //����ͨѶ�쳣
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_Xian, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 21, y + 8, BMP_Tongxun, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 21 + 42, y + 8, BMP_Yichang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 3:
                al_index = 4;
                if ((Engine_oil_press * 4 < 100) && (Engine_Speed > 0) && M_ON) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Jiyou, YELLOW, BLACK); //����ѹ����
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Yali, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Di, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 21, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 4:
                al_index = 5;
                if (IN31 && (Engine_Speed > 0) && M_ON) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Jiyou, YELLOW, BLACK); //����ѹ������
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Yali, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 5:
                al_index = 6;
                if ((water_temp > 138)&& (Engine_Speed > 0) && M_ON) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Shuiwen, YELLOW, BLACK); //ˮ�¸�
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Gao, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
            case 6:
                al_index = 7;
                if ((IN22 || IN23) && M_ON) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Qiya, YELLOW, BLACK); //��ѹ�ͱ���
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Di, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 21, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 21 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
            case 7:
                al_index = 8;
                if (Warn_level == 1) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Qing, YELLOW, BLACK); //��ͣ��
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_Tingche, YELLOW, BLACK);
                    LCD_DrawRect(x + 21 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
            case 8:
                al_index = 9;
                if (pSpeed > 69) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Chaosu, YELLOW, BLACK); //���ٱ���
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
            case 9:
                al_index = 10;
                if (TCU_warn == 1) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Qing, YELLOW, BLACK); //���������
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_Jiancha, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 42, y + 8, BMP_Biansuxiang, YELLOW, BLACK);
                    LCD_DrawRect(x + 21 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
            case 10:
                al_index = 11;
                if (((Status_Flag1 >> 7)&0x01) == 1) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DC, YELLOW, BLACK); //��ؾ������
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Junheng, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
            case 11:
                al_index = 12;
                if (((Status_Flag1 >> 6)&0x01) == 1) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Zong, YELLOW, BLACK); //�ܵ�ѹ��ѹ
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 42, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 42, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawRect(x + 21 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 12:
                al_index = 13;
                if (((Status_Flag1 >> 5)&0x01) == 1) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Zong, YELLOW, BLACK); //�ܵ�ѹǷѹ
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 42, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 42, y + 8, BMP_Qian, YELLOW, BLACK);
                    LCD_DrawRect(x + 21 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 13:
                al_index = 14;
                if (((Status_Flag1 >> 4)&0x01) == 1) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DC, YELLOW, BLACK); //���ͨѶ����
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Tongxun, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 14:
                al_index = 15;
                if (((Status_Flag1 >> 3)&0x01) == 1) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_s, YELLOW, BLACK); //SOC����
                    LCD_DrawImage1BPP(x + 11, y + 8, BMP_o, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11, y + 8, BMP_c, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + +11 + 11 + 11, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11 + 11 + 21, y + 8, BMP_Di, YELLOW, BLACK);
                    LCD_DrawRect(x + 11 + 11 + 11 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 15:
                al_index = 16;
                if (((Status_Flag1 >> 2)&0x01) == 1) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_s, YELLOW, BLACK); //SOC����
                    LCD_DrawImage1BPP(x + 11, y + 8, BMP_o, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11, y + 8, BMP_c, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + +11 + 11 + 11, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11 + 11 + 21, y + 8, BMP_Gao, YELLOW, BLACK);
                    LCD_DrawRect(x + 11 + 11 + 11 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 16:
                al_index = 17;
                if (((Status_Flag1 >> 1)&0x01) == 1) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Dan, YELLOW, BLACK); //�����ѹ����
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_Ti, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 21, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 21, y + 8, BMP_Di, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 17:
                al_index = 18;
                if ((Status_Flag1 & 0x01) == 1) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Dan, YELLOW, BLACK); //�����ѹ����
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_Ti, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 21, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 21, y + 8, BMP_Gao, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 18:
                al_index = 19;
                if (((Status_Flag2 >> 7)&0x01) == 1) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Wendu, YELLOW, BLACK); //�²����
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
                    LCD_DrawImage1BPP(x, y + 8, BMP_Wendu, YELLOW, BLACK); //�¶ȱ���
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 20:
                al_index = 21;
                if (((Status_Flag2 >> 5)&0x01) == 1) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Wendu, YELLOW, BLACK); //�¶ȹ���
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 21, y + 8, BMP_Gao, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 21:
                al_index = 22;
                if (((Status_Flag2 >> 4)&0x01) == 1) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Chong, YELLOW, BLACK); //����������
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
                    LCD_DrawImage1BPP(x, y + 8, BMP_Fang, YELLOW, BLACK); //�ŵ��������
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
                    LCD_DrawImage1BPP(x, y + 8, BMP_Jueyuan, YELLOW, BLACK); //��Ե����
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 24:
                al_index = 25;
                if (((Status_Flag2 >> 1)&0x01) == 1) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_d, YELLOW, BLACK); //DCDC���ϱ���
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
                    LCD_DrawImage1BPP(x, y + 8, BMP_DC, YELLOW, BLACK); //�����ʧ��
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Re, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 21, y + 8, BMP_Shikong, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 21 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 26:
                al_index = 27;
                if (((Status_Flag3 >> 2)&0x01) == 1) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_You, YELLOW, BLACK); //������ƫ����
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
                al_index = 28;
                if (((Status_Flag3 >> 3)&0x01) == 1) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_You, YELLOW, BLACK); //�е�ѹƫС���
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 21 + 21, y + 8, BMP_Pian, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 21 + 21 + 21, y + 8, BMP_Xiao, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 21 + 21 + 21 + 21, y + 8, BMP_DC, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42 + 21, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 28:
                al_index = 29;
                if (Fcan_count == CAN_TIME) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Qianbu, YELLOW, BLACK); //ǰ��
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Mokuai, YELLOW, BLACK); //ģ��
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Lixian, YELLOW, BLACK); //����
                    LCD_DrawRect(x + 42 + 42 + 42, y, 42, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 29:
                al_index = 30;
                if (Mcan_count == CAN_TIME) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Dingbu, YELLOW, BLACK); //����
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Mokuai, YELLOW, BLACK); //ģ��
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Lixian, YELLOW, BLACK); //����
                    LCD_DrawRect(x + 42 + 42 + 42, y, 42, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 30:
                al_index = 31;
                if (Rcan_count == CAN_TIME) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Houbu, YELLOW, BLACK); //��
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Mokuai, YELLOW, BLACK); //ģ��
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Lixian, YELLOW, BLACK); //����
                    LCD_DrawRect(x + 42 + 42 + 42, y, 42, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
            default:
                al_index = 0;
                LCD_DrawRect(x, y, 200, 36, BLACK); //�����ʾ����
                break;
        }
    }
}

void updata_QY(void) {
    unsigned char color = RED;
    unsigned int press1 = 50; /*��ѹ������������0-1.2Mpa ,��ӦΪ0-120 ������0-100*/
    static int update_press1=0;
    unsigned int press2 = 90; /*��ѹ������������0-1.2Mpa ,��ӦΪ0-120 ������0-100*/
    static int update_press2=0;
    if (ADR[1] < 10) press1 = 0;
    else if (ADR[1] <= 52) press1 = (ADR[1] - 10)*0.48;
    else if (ADR[1] <= 124) press1 = (ADR[1] - 52)*0.56 + 20;
    else if (ADR[1] <= 155) press1 = (ADR[1] - 124)*0.65 + 60;
    else press1 = (ADR[1] - 155)*0.69 + 80;
    //press1 = ADR[4] / 27; //��ѹ�Ͳ���   0-5V
    //press2 = ADR[5] / 27;//��ѹ�Ͳ���   0-5V

    //����
    PRESS[0] = press1;
    if (press1 > update_press1) update_press1++;
    else if (press1 < update_press1)update_press1--;
    else update_press1 = press1;
    
    if (update_press1 > 60) color = GREEN;
    else color = RED;
    if (update_press1 > 100) update_press1 = 100;
    print_SZ(33 - 7, 410 + 13, update_press1, 3, 2, color);
    LCD_DrawImage1BPP(33 + 9, 380 + 13, Bmp_QY1, color, BLACK); //��ѹ1ͼ��
    LCD_DrawRect(38, 108 + 13, 44, (260 - update_press1 * 2.6), BLACK); //260/100  
    if (update_press1 % 5 == 0) {
        LCD_DrawRect(38, (368 + 13 - update_press1 * 2.6), 44, (update_press1 * 2.6), color);
    } else {
        LCD_DrawRect(38, (368 + 13 - update_press1 * 2.6), 44, (update_press1 * 2.6 + 1), color);
    }

    if (ADR[2] < 10) press2 = 0;  
    else if (ADR[2] <= 52) press2 = (ADR[2] - 10)*0.48;
    else if (ADR[2] <= 124) press2 = (ADR[2] - 52)*0.56 + 20;
    else if (ADR[2] <= 155) press2 = (ADR[2] - 124)*0.65 + 60;
    else press2 = (ADR[2] - 155)*0.69 + 80;

    PRESS[1] = press2;
    //����
    if (press2 > update_press2) update_press2++;
    else if (press2 < update_press2)update_press2--;
    else update_press2 = press2;
    
    if (update_press2 > 60) color = GREEN;
    else color = RED;
    if (update_press2 > 100) update_press2 = 100;
    LCD_DrawImage1BPP(712 + 9, 380 + 13, Bmp_QY2, color, BLACK); //��ѹ2ͼ��
    print_SZ(712 - 7, 410 + 13, update_press2, 3, 2, color);
    LCD_DrawRect(712 + 5, 108 + 13, 44, (260 - update_press2 * 2.6), BLACK); //260/100  
    if (update_press2 % 5 == 0) {
        LCD_DrawRect(712 + 5, (368 + 13 - update_press2 * 2.6), 44, (update_press2 * 2.6), color);
    } else {
        LCD_DrawRect(712 + 5, (368 + 13 - update_press2 * 2.6), 44, (update_press2 * 2.6 + 1), color);
    }

}

void updata_Dangwei(void) {
    unsigned char gear = 1;
    gear = Current_Gear;
    if (gear > 7) gear = 0;
    LCD_DrawImage1BPPZOOM_4(100 - 10, 150 + 13 + 65 + 65 + 45 + 35 + 10, BMP_DANGWEI[gear], GREEN, BLACK); //��λ����   
}

void updata_SOC(void) {
    unsigned char color = WHITE;
    unsigned char soc = 100;
    soc = BMS_SOC * 0.4;
    if (soc >= 100) soc = 100;
    if (soc > 25) color = GREEN;
    else if (soc > 0 && soc <= 25) color = RED;
    else color = BLACK;
    print_SZ_1(585, 155 + 13 + 60 + 60, soc, 3, 0, WHITE); //SOC��ֵ
    LCD_DrawRect(225 + 2, 150 + 13 + 5 + 60 + 60 + 2, (soc * 3.31), 28, color); // 331/100  
    if (soc < 100)//��socΪ100ʱ�����//��ʱ�������
        LCD_DrawRect((225 + 2 + soc * 3.31), 150 + 13 + 5 + 60 + 60 + 2, (331 - soc * 3.31), 28, BLACK);
}

void updata_DCDY(unsigned int x, unsigned int y) {
    //unsigned char color = GREEN;
    unsigned int DCDY = 50;
    DCDY = BMS_V * 0.1;
    if (DCDY >= 1800) DCDY = 1800;
    if (DCDY < 1000) DCDY = 1000;
    print_SZ_1(x, y, (DCDY - 1000), 3, 0, WHITE); //��ص�ѹ��ֵ x=120+72+30   y=150+60-2
    if (DCDY > 1000 && frmID == 0)
        LCD_DrawRect(225 + 2, 150+13 + 5 + 2, ((DCDY - 1000) * 3.31 * 0.125), 28, GREEN); // 331/100  
    if (DCDY < 1800 && frmID == 0)//��Ϊ100ʱ�����
        LCD_DrawRect((225 + 2 + (DCDY - 1000) * 3.31 * 0.125), 150 +13+ 5 + 2, (331 - (DCDY - 1000) * 3.31 * 0.125), 28, BLACK);
}

void updata_DJDY(unsigned int x, unsigned int y) {
    unsigned int DJDY = 500;
    DJDY = moto_voltage * 0.1;
    if (DJDY < 1000) {
        //LCD_DrawImage1BPPZOOM_4(x - 40, y + 4, BMP_FU, WHITE, BLACK);
        print_SZ_1(x, y, 0, 3, 0, WHITE); //�����ѹ��ֵ x=120+72+35   y=250+60-2
    } else {
        //LCD_DrawImage1BPPZOOM_4(x - 40, y + 4, BMP_ZHENG, WHITE, BLACK);
        print_SZ_1(x, y, DJDY, 3, 0, WHITE); //�����ѹ��ֵ x=120+72+35   y=250+60-2
    }
}

void updata_DCDL(unsigned int x, unsigned int y) {
    unsigned int DCDL = 100;
    DCDL = BMS_A * 0.1;
    if (DCDL < 1000) {
        DCDL = 1000 - DCDL;
        if (DCDL > 500) DCDL = 500;
        print_SZ_1(x, y, DCDL, 3, 0, WHITE);
        LCD_DrawImage1BPPZOOM_4(x - 20, y + 4, BMP_FU, WHITE, BLACK);
        if (DCDL > 0 && frmID == 0)
            LCD_DrawRect((225 + 2 + 164 - DCDL * 1.64 * 0.2), 150+13 + 5 + 2 + 60, (DCDL * 1.64 * 0.2 + 1), 28, GREEN);
        if (DCDL < 500 && frmID == 0) {
            LCD_DrawRect(225 + 2, 150+13 + 5 + 2 + 60, (164 - DCDL * 1.64 * 0.2), 28, BLACK); // 165/100         
            LCD_DrawRect(225 + 83 + 83 + 2, 150 +13+ 5 + 2 + 60, 165, 28, BLACK);
        }
    } else {
        DCDL = DCDL - 1000;
        if (DCDL > 500) DCDL = 500;
        LCD_DrawImage1BPPZOOM_4(x - 20, y + 4, BMP_ZHENG, WHITE, BLACK);
        print_SZ_1(x, y, DCDL, 3, 0, WHITE);
        if (DCDL > 3 && frmID == 0)
            LCD_DrawRect(225 + 83 + 83 + 2, 150 +13+ 5 + 2 + 60, (DCDL * 1.65 * 0.2), 28, GREEN); // �������Ϊ0�������
        if (DCDL < 500 && frmID == 0) {
            LCD_DrawRect((225 + 83 + 83 + 2 + DCDL * 1.65 * 0.2), 150 +13+ 5 + 2 + 60, (165 - DCDL * 1.65 * 0.2), 28, BLACK);
            LCD_DrawRect(225 + 2, 150 +13+ 5 + 2 + 60, 164, 28, BLACK);
        }
    }
}

void updata_DJDL(unsigned int x, unsigned int y) {
    unsigned char color = WHITE;
    unsigned int DJDL = 100;
    DJDL = moto_current * 0.1;
    if (DJDL < 1000) {
        print_SZ_1(x, y, 1000 - DJDL, 3, 0, color);
        LCD_DrawImage1BPPZOOM_4(x - 40, y + 4, BMP_FU, color, BLACK);
    } else {
        LCD_DrawImage1BPPZOOM_4(x - 40, y + 4, BMP_ZHENG, color, BLACK);
        print_SZ_1(x, y, DJDL, 3, 0, color); //��ص�����ֵ x=135+180+50+100+20+20   y=150+60-2
    }
}

void updata_T(unsigned int x, unsigned int y, unsigned char color1,
        unsigned int temp, //�¶�ֵ
        float factor, //����
        unsigned int offset) {//ƫ����
    unsigned char t, color;
    color = color1;
    t = temp*factor;
    if (t < offset) {
        LCD_DrawImage1BPPZOOM_4(x - 25, y + 5, BMP_FU, color, BLACK);
        print_SZ_1(x, y, offset - t, 3, 0, color);
    } else {
        LCD_DrawImage1BPPZOOM_4(x - 25, y + 5, BMP_ZHENG, color, BLACK);
        print_SZ_1(x, y, t - offset, 3, 0, color); //����¶�  x=135+180+50+100+20+20   y=150+70+35
    }
}

void updata_RMP(unsigned int x, unsigned int y) {
    unsigned char color = WHITE;
    unsigned int rpm = 80;
    rpm = moto_speed * 0.5;
    //if (rmp < 2000) {
    // LCD_DrawImage1BPPZOOM_4(x - 25, y + 5, BMP_FU, color, BLACK);
    // print_SZ_1(x, y, 2000 - rmp, 4, 0, color); //������ֵ
    // } else {
    //     LCD_DrawImage1BPPZOOM_4(x - 25, y + 5, BMP_ZHENG, color, BLACK);
    print_SZ_1(x, y, rpm, 4, 0, color); //������ֵ x=135+180+50+100+20+20   y=250+55
    // }

}

/*
void updata_Accelerator(unsigned int x, unsigned int y) {
    unsigned char color = WHITE;
    unsigned int ymtb = 80;
    ymtb = Accelerator * 4;
    if (ymtb > 1000) ymtb = 1000;
    print_SZ_1(x, y, ymtb, 4, 1, color); //������ֵ x=135+180+50+100+20+20   y=250+55


}

void updata_Brake_percent(unsigned int x, unsigned int y) {
    unsigned char color = WHITE;
    unsigned int zdtb = 80;
    zdtb = Brake_percent;
    if (zdtb > 100) zdtb = 100;
    print_SZ_1(x, y, zdtb, 3, 0, color); //������ֵ x=135+180+50+100+20+20   y=250+55


}
 */

void frmMain(void) {
    unsigned char color;
    if (f_index == 0) { //ֻ����һ��
        f_index = 1;
        mainFrame();
    } else if (f_index == 1) {
        f_index = 2;
        updata_QY();
        print_SZ_1(313 - 32, 318 + 13 + 38, Niaosu * 4, 4, 1, WHITE); //����        
    } else if (f_index == 2) {
        f_index = 3;
        disp_baojing();
        updata_RMP(480 + 30, 318 + 13);
    } else if (f_index == 3) {
        f_index = 4;
        disp_miles();
        updata_DCDL(585, 155 + 13 + 60);
    } else if (f_index == 4) {
        f_index = 5;
        disp_time(330, 440 + 13, timer);
        updata_T(313, 318 + 13, WHITE, Inverter_t, 1, 40);
    } else if (f_index == 5) {
        f_index = 6;
        updata_SOC();
        updata_Dangwei();
    } else if (f_index == 6) {
        f_index = 7;
        updata_DCDY(585, 155 + 13);
        disp_CAN_baojing(162, 394 + 13);
    } else if (f_index == 7) {
        f_index = 1;
        print_H(480 + 30 - 16, 318 + 13 + 38 * 2, tcu_spn, 5, 0, WHITE); //spn
        if (TCU_level == 3 || TCU_level == 4)
            color = YELLOW;
        else if (TCU_level == 1 || TCU_level == 2)
            color = RED;
        else color = GREEN;
        print_SZ_1(480 + 30 + 16, 318+13 + 38, TCU_code, 3, 0, color); //ϵͳ����
    } else {
        f_index = 0;
    }

    if (AV_CH == 0) { //�������ֽ���
        if (key_up) { //���ڱ����
            key_up = 0;
            if ((IN6 == 1) && (!time_flag)) {//���⿪��
                if (e_backlight >= 1000) e_backlight = 100;
                else e_backlight += 100;
                EEROM_WriteBackLight();
            }
            if (time_flag) {
                t++; //ʱ������
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
                f_index = 0;
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
            key_set = 0;
            if (time_flag)
                t_add = 1;
            else t_add = 0;
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

/******************************************************/
void ICFrame(void) { //�Ǳ���
    LCD_Clear();

    LCD_DrawImage1BPPZOOM_4(320, 15, BmpZHYB, WHITE, BLACK);
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //��������

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

    LCD_DrawImage1BPP(505 + 200, 75 + 25 * 15, BMP_V, WHITE, BLACK);

}

void ICUpdate(void) {
    unsigned int dump;
    unsigned int i;

    dump = sw_input[0].byte + ((unsigned int) (sw_input[1].byte) << 8);
    for (i = 0; i < 16; i++) {
        if (i == 3 || i == 1 || i == 2) {//Ϊ�ػ𿪹�
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
        /*if (i == 9) {//IN26 Ϊ�ػ𿪹�
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
    for (i = 0; i < 8; i++) {//WAKE1 WAKE2 WAKE3Ϊ�ػ𿪹�
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
    
    //����汾��
    print_SZ_1(535 + 200, 75 + 25 * 15, VERISON, 3, 2, WHITE);
}

void frmIC(void) {
    if (f_index == 0) { //ֻ����һ��
        f_index = 1;
        ICFrame();
    } else if (f_index == 1) {
        f_index = 1;
        ICUpdate();
    } else {
        f_index = 0;
    }


    if (key_up) { //�Ӳ˵��л�
        key_up = 0;
        frmID = 10;
        f_index = 0;
    }

    if (key_AV) {
        key_AV = 0;
    }
    if (key_set) {//���˵�/�Ӳ˵��л�
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

    LCD_DrawRect(0, 70, 800, 2, YELLOW); //��������
    if (index == 0) {
        LCD_DrawImage1BPPZOOM_4(320, 15, BmpQMK, WHITE, BLACK);
        for (i = 0; i < 15; i++) {
            LCD_DrawImage1BPP(60 + 280, 75 + 3 + 25 * i, BMP_a, WHITE, BLACK);
            //LCD_DrawRect(0, 74 +25+ 25 * i, 800, 1, GRAY); //����
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
            //LCD_DrawRect(0, 74 +25+ 25 * i, 800, 1, GRAY); //����
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
            //LCD_DrawRect(0, 74 +25+ 25 * i, 800, 1, GRAY); //����
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

    /*ǰ��ģ��*/
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
                print_SZ(30 + 250, 75 + 6 + 25 * i, fpcur[i] / 100, 3, 1, YELLOW); //ǰģ�����
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

    /*�п�ģ��*/
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
                print_SZ(30 + 250, 75 + 6 + 25 * i, mpcur[i] / 100, 3, 1, YELLOW); //��ģ�����
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

    /*���ģ��*/
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
                print_SZ(30 + 250, 75 + 6 + 25 * i, rpcur[i] / 100, 3, 1, YELLOW); //��ģ�����
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
    if (f_index == 0) { //ֻ����һ��
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
    if (key_AV) {
        key_AV = 0;
    }


}

void frmBCU_m(void) {
    if (f_index == 0) { //ֻ����һ��
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
        frmID = 12;
        f_index = 0;
    }
    if (key_AV) {
        key_AV = 0;
    }

}

void frmBCU_r(void) {
    if (f_index == 0) { //ֻ����һ��
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
    if (key_AV) {
        key_AV = 0;
    }

}

/******************************************************/

void MenuFrame(void) {
    LCD_Clear();
    unsigned char color = WHITE;
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //��������   
    LCD_DrawRect(0, 430, 800, 2, YELLOW); //�ײ�����

    LCD_DrawImage1BPP(130, 130, BMP_Control, color, BLACK); //����
    LCD_DrawImage1BPP(130 + 50, 130, BMP_STSTEM, color, BLACK); //ϵͳ
    LCD_DrawImage1BPP(130 + 50 + 50, 130, BMP_Message, color, BLACK); //��Ϣ

    LCD_DrawImage1BPP(130, 130 + 35, BMP_Engine, color, BLACK); //������
    LCD_DrawImage1BPP(130 + 75, 130 + 35, BMP_STSTEM, color, BLACK); //ϵͳ
    LCD_DrawImage1BPP(130 + 75 + 50, 130 + 35, BMP_Message, color, BLACK); //��Ϣ

    LCD_DrawImage1BPP(130, 130 + 35 + 35, BMP_Fuzhu, color, BLACK); //����
    LCD_DrawImage1BPP(130 + 50, 130 + 35 + 35, BMP_STSTEM, color, BLACK); //ϵͳ
    LCD_DrawImage1BPP(130 + 50 + 50, 130 + 35 + 35, BMP_Message, color, BLACK); //��Ϣ

    LCD_DrawImage1BPP(130, 130 + 35 + 35 + 35, BMP_TCU, color, BLACK); //TCU
    LCD_DrawImage1BPP(130 + 39, 130 + 35 + 35 + 35, BMP_STSTEM, color, BLACK); //ϵͳ
    LCD_DrawImage1BPP(130 + 39 + 50, 130 + 35 + 35 + 35, BMP_Message, color, BLACK); //��Ϣ

    LCD_DrawImage1BPP(130 + 350, 130, BMP_Battery, color, BLACK); //���
    LCD_DrawImage1BPP(130 + 350 + 50, 130, BMP_Manage, color, BLACK); //����
    LCD_DrawImage1BPP(130 + 350 + 50 + 50, 130, BMP_STSTEM, color, BLACK); //ϵͳ
    LCD_DrawImage1BPP(130 + 350 + 50 + 50 + 50, 130, BMP_Message, color, BLACK); //��Ϣ

    LCD_DrawImage1BPP(130 + 350, 130 + 35, BMP_Battery, color, BLACK); //���   
    LCD_DrawImage1BPP(130 + 350 + 50, 130 + 35, BMP_Message, color, BLACK); //��Ϣ

    LCD_DrawImage1BPP(130 + 350, 130 + 35 + 35, BMP_Air, color, BLACK); //�յ�
    LCD_DrawImage1BPP(130 + 350 + 50, 130 + 35 + 35, BMP_STSTEM, color, BLACK); //ϵͳ
    LCD_DrawImage1BPP(130 + 350 + 50 + 50, 130 + 35 + 35, BMP_Message, color, BLACK); //��Ϣ   

    LCD_DrawImage1BPP(130 + 350, 130 + 35 + 35 + 35, BMP_IC, color, BLACK); //�Ǳ�
    LCD_DrawImage1BPP(130 + 50 + 350, 130 + 35 + 35 + 35, BMP_STSTEM, color, BLACK); //ϵͳ
    LCD_DrawImage1BPP(130 + 50 + 50 + 350, 130 + 35 + 35 + 35, BMP_Message, color, BLACK); //��Ϣ


}

void MenuUpdate(void) {
    static unsigned char i = 0;
    unsigned char color = BLACK;
    if (key_up) {//��ͷ������
        key_up = 0;
        if (time_flag) {
            t++; //ʱ������
            if (t == 10) t = 0;
        }
        if (!time_flag) {
            i++;
        }
    }

    if (key_AV) {//��ͷ������
        key_AV = 0;
        if (time_flag)
            t_add = 1;
        if (!time_flag)
            i--;
    }

    if (i == 16) i = 8;
    if (i == 0) i = 8;
    //�Ӳ˵����л�
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
                frmID = 8;
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
                frmID = 9;
            }
            time_flag = 0;
        }
    } else
        color = BLACK;
    LCD_DrawImage1BPP(105 + 350, 131 + 3 * 35, BMP_Choose, color, BLACK);


    /*
    static unsigned char al_index = 0;
    if (alarm_update_flag == 0) { //3S ����һ�� ѭ��  x=270  y=375
        // LCD_DrawRect(x, y - 5, 320, 50, BLACK); //�����ʾ����
        switch (al_index) {
                //������ʾ�������SPN��FMI
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
                LCD_DrawRect(x, y, 320, 50, BLACK); //�����ʾ����
                break;
        }
    }


    //���״̬
    if (MCU_offline_warn == 0x3) {
        LCD_DrawImage1BPPZOOM_4(50 + 30, 80, BMP_MCU_online, GREEN, BLACK);
        LCD_DrawRect(50 + 96 + 30, 80, 25, 30, BLACK); //��������
    } else if (MCU_offline_warn == 1)
        LCD_DrawImage1BPPZOOM_4(50 + 30, 80, BMP_DJ_offline_1, RED, BLACK);

    //���״̬
    if (BMS_offline_warn == 0x3) {
        LCD_DrawImage1BPPZOOM_4(200 + 30, 80, BMP_BMS_online, GREEN, BLACK);
        LCD_DrawRect(200 + 96 + 30, 80, 25, 30, BLACK);
    } else if (BMS_offline_warn == 1)
        LCD_DrawImage1BPPZOOM_4(200 + 30, 80, BMP_DC_offline_1, RED, BLACK);

    //������״̬
    if (TCU_offline_warn == 0x3) {
        LCD_DrawImage1BPPZOOM_4(350 + 30, 80, BMP_TCU_online, GREEN, BLACK);
        LCD_DrawRect(350 + 120 + 30, 80, 25, 30, BLACK);
    } else if (TCU_offline_warn == 1)
        LCD_DrawImage1BPPZOOM_4(350 + 30, 80, BMP_TCU_offline_1, RED, BLACK);

    //������״̬
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
    if (f_index == 0) { //ֻ����һ��
        f_index = 1;
        MenuFrame();
    } else if (f_index == 1) {
        f_index = 1;
        MenuUpdate();
        disp_time(330, 440 + 13, timer);
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
            frmID = 13;
        }
    }

    /*if (MILE_flag) {
        LCD_DrawImage1BPP(2, 440 + 3, Bmp_ODO, YELLOW, BLACK); //�ۼ���� ODO
        print_SZ_1(2 + 64 + 4 + 10, 440 - 2, total_miles, 7, 1, WHITE);
        if (key_AV) {
            key_AV = 0;
            total_miles=total_miles+1000;
        }
    }*/
}

/******************************************************/

void ControlFrame(void) {
    unsigned char i = 0;
    LCD_Clear();
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //��������
    LCD_DrawImage1BPP(130 + 200, 130 - 85, BMP_Control, WHITE, BLACK); //����
    LCD_DrawImage1BPP(130 + 200 + 50, 130 - 85, BMP_STSTEM, WHITE, BLACK); //ϵͳ
    LCD_DrawImage1BPP(130 + 200 + 50 + 50, 130 - 85, BMP_Message, WHITE, BLACK); //��Ϣ

    LCD_DrawRect(80, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320 + 320, 90, 1, 380, GREEN);
    for (i = 0; i < 11; i++)
        LCD_DrawRect(80, 90 + i * 38, 640, 1, GREEN);

    LCD_DrawImage1BPP(82, 100, BMP_DJ, WHITE, BLACK); //���
    LCD_DrawImage1BPP(82 + 42, 100, BMP_Input, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 42 + 42, 100, BMP_DY, WHITE, BLACK); //��ѹ
    LCD_DrawImage1BPP(400 - 24, 100, BMP_v, WHITE, BLACK); //v

    LCD_DrawImage1BPP(82, 100 + 38, BMP_DJ, WHITE, BLACK); //���
    LCD_DrawImage1BPP(82 + 42, 100 + 38, BMP_Input, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38, BMP_DL, WHITE, BLACK); //����
    LCD_DrawImage1BPP(400 - 24, 100 + 38, BMP_a, WHITE, BLACK); //a

    LCD_DrawImage1BPP(82, 100 + 38 * 2, BMP_DJ, WHITE, BLACK); //���
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 2, BMP_Wendu, WHITE, BLACK); //�¶�
    LCD_DrawImage1BPP(400 - 28, 100 + 38 * 2, BMP_T, WHITE, BLACK); //��

    LCD_DrawImage1BPP(82, 100 + 38 * 3, BMP_DJ, WHITE, BLACK); //���
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 3, BMP_KZQ, WHITE, BLACK); //������
    LCD_DrawImage1BPP(82 + 42 + 63, 100 + 38 * 3, BMP_Wendu, WHITE, BLACK); //�¶�
    LCD_DrawImage1BPP(400 - 28, 100 + 38 * 3, BMP_T, WHITE, BLACK); //��

    LCD_DrawImage1BPP(82, 100 + 38 * 4, BMP_Zhengche, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 4, BMP_Mode, WHITE, BLACK); //ģʽ

    LCD_DrawImage1BPP(82, 100 + 38 * 5, BMP_Chengxu, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 5, BMP_Banben, WHITE, BLACK); //�汾
    LCD_DrawImage1BPP(82 + 42 + 42 + 2, 100 + 5 + 38 * 5, BMP_Maohao, WHITE, BLACK); //:

    LCD_DrawImage1BPP(82, 100 + 38 * 6, BMP_Zhengche, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 6, BMP_KZQ, WHITE, BLACK); //������
    LCD_DrawImage1BPP(82 + 42 + 63, 100 + 38 * 6, BMP_Life, WHITE, BLACK); //Life
    LCD_DrawImage1BPP(82 + 42 + 63 + 44 + 2, 100 + 5 + 38 * 6, BMP_Maohao, WHITE, BLACK); //:

    LCD_DrawImage1BPP(82 + 320, 100, BMP_Jiasu, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 42 + 320, 100, BMP_Taban, WHITE, BLACK); //̤��
    LCD_DrawImage1BPP(82 + 42 + 42 + 320, 100, BMP_Baifenbi, WHITE, BLACK); //�ٷֱ�
    LCD_DrawImage1BPP(720 - 24, 100, BMP_Baifenhao, WHITE, BLACK); //%

    LCD_DrawImage1BPP(82 + 320, 100 + 38, BMP_Zhidong, WHITE, BLACK); //�ƶ�
    LCD_DrawImage1BPP(82 + 42 + 320, 100 + 38, BMP_Taban, WHITE, BLACK); //̤��
    LCD_DrawImage1BPP(82 + 42 + 42 + 320, 100 + 38, BMP_Baifenbi, WHITE, BLACK); //�ٷֱ�
    LCD_DrawImage1BPP(720 - 24, 100 + 38, BMP_Baifenhao, WHITE, BLACK); //%

    LCD_DrawImage1BPP(82 + 320, 100 + 2 * 38, BMP_Shuzi, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 42 + 320, 100 + 2 * 38, BMP_Liang, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 42 + 21 + 320, 100 + 2 * 38, BMP_Input, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 42 + 21 + 42 + 320, 100 - 8 + 2 * 38, BMP_SZ_1[1], WHITE, BLACK); //1

    LCD_DrawImage1BPP(82 + 320, 100 + 3 * 38, BMP_Shuzi, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 42 + 320, 100 + 3 * 38, BMP_Liang, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 42 + 21 + 320, 100 + 3 * 38, BMP_Input, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 42 + 21 + 42 + 320, 100 - 8 + 3 * 38, BMP_SZ_1[2], WHITE, BLACK); //2

    LCD_DrawImage1BPP(82 + 320, 100 + 4 * 38, BMP_Shuzi, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 42 + 320, 100 + 4 * 38, BMP_Liang, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 42 + 21 + 320, 100 + 4 * 38, BMP_Input, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 42 + 21 + 42 + 320, 100 - 8 + 4 * 38, BMP_SZ_1[3], WHITE, BLACK); //3

    LCD_DrawImage1BPP(82 + 320, 100 + 5 * 38, BMP_Shuzi, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 42 + 320, 100 + 5 * 38, BMP_Liang, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 42 + 21 + 320, 100 + 5 * 38, BMP_Output, WHITE, BLACK); //���
    LCD_DrawImage1BPP(82 + 42 + 21 + 42 + 320, 100 - 8 + 5 * 38, BMP_SZ_1[1], WHITE, BLACK); //1

    LCD_DrawImage1BPP(82 + 320, 100 + 6 * 38, BMP_Shuzi, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 42 + 320, 100 + 6 * 38, BMP_Liang, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 42 + 21 + 320, 100 + 6 * 38, BMP_Output, WHITE, BLACK); //���
    LCD_DrawImage1BPP(82 + 42 + 21 + 42 + 320, 100 - 8 + 6 * 38, BMP_SZ_1[2], WHITE, BLACK); //2

    LCD_DrawImage1BPP(82 + 320, 100 + 7 * 38, BMP_Shuzi, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 42 + 320, 100 + 7 * 38, BMP_Liang, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 42 + 21 + 320, 100 + 7 * 38, BMP_Output, WHITE, BLACK); //���
    LCD_DrawImage1BPP(82 + 42 + 21 + 42 + 320, 100 - 8 + 7 * 38, BMP_SZ_1[3], WHITE, BLACK); //3

}

void ControlUpdate(void) {
    updata_DJDY(82 + 200 + 20, 100 - 8);
    updata_DJDL(82 + 200 + 20, 100 + 38 - 8);
    updata_T(82 + 200 + 20, 100 + 38 * 2 - 8, WHITE, Motor_Temperature, 1, 40);
    updata_T(82 + 200 + 20, 100 + 38 * 3 - 8, WHITE, Inverter_t, 1, 40);

    print_SZ_1(82 + 200 + 20, 100 - 8 + 38 * 4, Car_mode, 3, 0, WHITE); //����ģʽ
    print_SZ_1(82 + 200 - 44, 100 - 8 + 38 * 5, Program, 6, 2, WHITE); //����汾
    print_SZ_1(82 + 200 + 20, 100 - 8 + 38 * 6, Car_LIFE, 3, 0, WHITE); //����LIFE
    print_SZ_1(82 + 200 + 320, 100 - 8, Speed_percent * 4, 4, 1, WHITE); //����̤��
    print_SZ_1(82 + 200 + 320, 100 - 8 + 38, Brake_percent * 4, 4, 1, WHITE); //�ƶ�̤��
    print_D(82 + 180 + 320, 100 - 8 + 38 * 2, CAN_KEY[0].byte); //����������1
    print_D(82 + 180 + 320, 100 - 8 + 38 * 3, CAN_KEY[1].byte); //����������2
    print_D(82 + 180 + 320, 100 - 8 + 38 * 4, Digit_input3); //����������3
    print_D(82 + 180 + 320, 100 - 8 + 38 * 5, CAN_KEY[2].byte); //����������1
    print_D(82 + 180 + 320, 100 - 8 + 38 * 6, CAN_KEY[3].byte); //����������2
    print_D(82 + 180 + 320, 100 - 8 + 38 * 7, 0); //����������3

}

void frmControl(void) {
    if (f_index == 0) { //ֻ����һ��
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
    if (key_set) {//����������
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
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //��������
    LCD_DrawImage1BPP(130 + 200 - 15, 130 - 85, BMP_Engine, WHITE, BLACK); //������
    LCD_DrawImage1BPP(130 + 200 + 75 - 15, 130 - 85, BMP_STSTEM, WHITE, BLACK); //ϵͳ
    LCD_DrawImage1BPP(130 + 200 + 75 + 50 - 15, 130 - 85, BMP_Message, WHITE, BLACK); //��Ϣ

    LCD_DrawRect(80, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320 + 320, 90, 1, 380, GREEN);
    for (i = 0; i < 11; i++)
        LCD_DrawRect(80, 90 + i * 38, 640, 1, GREEN);

    LCD_DrawImage1BPP(82, 100, BMP_Fadongji, WHITE, BLACK); //������
    LCD_DrawImage1BPP(82 + 63, 100, BMP_Youhao, WHITE, BLACK); //�ͺ�
    LCD_DrawImage1BPP(400 - 32, 100, BMP_L_H, WHITE, BLACK); //L/H

    LCD_DrawImage1BPP(82, 100 + 38, BMP_Fadongji, WHITE, BLACK); //������
    LCD_DrawImage1BPP(82 + 63, 100 + 38, BMP_Shuiwen, WHITE, BLACK); //ˮ��
    LCD_DrawImage1BPP(400 - 28, 100 + 38, BMP_T, WHITE, BLACK); //��

    LCD_DrawImage1BPP(82, 100 + 38 * 2, BMP_Fadongji, WHITE, BLACK); //������
    LCD_DrawImage1BPP(82 + 63, 100 + 38 * 2, BMP_Fuhe, WHITE, BLACK); //����
    LCD_DrawImage1BPP(400 - 24, 100 + 38 * 2, BMP_Baifenhao, WHITE, BLACK); //%

    LCD_DrawImage1BPP(82, 100 + 38 * 3, BMP_Niaosu, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 3, BMP_Yewei, WHITE, BLACK); //Һλ
    LCD_DrawImage1BPP(400 - 24, 100 + 38 * 3, BMP_Baifenhao, WHITE, BLACK); //%


    LCD_DrawImage1BPP(82 + 320, 100, BMP_Fadongji, WHITE, BLACK); //������
    LCD_DrawImage1BPP(82 + 63 + 320, 100, BMP_Mubiao, WHITE, BLACK); //Ŀ��
    LCD_DrawImage1BPP(82 + 63 + 42 + 320, 100, BMP_Youmen, WHITE, BLACK); //����
    LCD_DrawImage1BPP(720 - 24, 100, BMP_Baifenhao, WHITE, BLACK); //%

    LCD_DrawImage1BPP(82 + 320, 100 + 38, BMP_Fadongji, WHITE, BLACK); //������
    LCD_DrawImage1BPP(82 + 63 + 320, 100 + 38, BMP_Shiji, WHITE, BLACK); //ʵ��
    LCD_DrawImage1BPP(82 + 63 + 42 + 320, 100 + 38, BMP_Youmen, WHITE, BLACK); //����
    LCD_DrawImage1BPP(720 - 24, 100 + 38, BMP_Baifenhao, WHITE, BLACK); //%   

    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 2, BMP_Fadongji, WHITE, BLACK); //������
    LCD_DrawImage1BPP(82 + 63 + 320, 100 + 38 * 2, BMP_Jiyou, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 63 + 42 + 320, 100 + 38 * 2, BMP_Yali, WHITE, BLACK); //ѹ��
    LCD_DrawImage1BPP(720 - 32, 100 + 38 * 2, BMP_Kpa, WHITE, BLACK); //Kpa

    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 3, BMP_Fadongji, WHITE, BLACK); //������
    LCD_DrawImage1BPP(82 + 63 + 320, 100 + 38 * 3, BMP_Jinqi, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 63 + 42 + 320, 100 + 38 * 3, BMP_Wendu, WHITE, BLACK); //�¶�
    LCD_DrawImage1BPP(720 - 28, 100 + 38 * 3, BMP_T, WHITE, BLACK); //��

}

void EngineUpdate(void) {
    print_SZ_1(82 + 63 + 42 + 80, 100 - 8, Fule_rate * 5, 4, 2, WHITE); //�ͺ�
    updata_T(82 + 63 + 42 + 80 + 32, 100 - 8 + 38, WHITE, water_temp, 1, 40); //ˮ��
    print_SZ_1(82 + 63 + 42 + 80 + 16, 100 - 8 + 38 * 2, Engine_Fuhe, 4, 0, WHITE); //����
    print_SZ_1(82 + 63 + 42 + 80, 100 - 8 + 38 * 3, Niaosu * 4, 4, 1, WHITE); //����
    print_SZ_1(82 + 63 + 42 + 80 + 320, 100 - 8, Accelerator * 4, 4, 1, WHITE); //Ŀ������
    print_SZ_1(82 + 63 + 42 + 80 + 320, 100 - 8 + 38, Accelerator_Shiji * 4, 4, 1, WHITE); //ʵ������
    print_SZ_1(82 + 63 + 42 + 80 + 16 + 320, 100 - 8 + 38 * 2, Engine_oil_press * 4, 4, 0, WHITE); //����ѹ��
    updata_T(82 + 63 + 42 + 80 + 32 + 320, 100 - 8 + 38 * 3, WHITE, ambient_air_temperature, 1, 40); //�����¶�
}

void frmEngine(void) {
    if (f_index == 0) { //ֻ����һ��
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

    if (key_set) {//����������
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
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //��������
    LCD_DrawImage1BPP(130 + 200, 130 - 85, BMP_Fuzhu, WHITE, BLACK); //����
    LCD_DrawImage1BPP(130 + 200 + 50, 130 - 85, BMP_STSTEM, WHITE, BLACK); //ϵͳ
    LCD_DrawImage1BPP(130 + 200 + 50 + 50, 130 - 85, BMP_Message, WHITE, BLACK); //��Ϣ

    LCD_DrawRect(80, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320 + 60, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320 + 320, 90, 1, 380, GREEN);
    for (i = 0; i < 11; i++)
        LCD_DrawRect(80, 90 + i * 38, 640, 1, GREEN);

    LCD_DrawImage1BPP(82, 100, BMP_Youbeng, WHITE, BLACK); //�ͱ�
    LCD_DrawImage1BPP(82 + 42, 100, BMP_d, WHITE, BLACK); //D
    LCD_DrawImage1BPP(82 + 42 + 11, 100, BMP_c, WHITE, BLACK); //C
    LCD_DrawImage1BPP(82 + 42 + 11 + 11, 100, BMP_I, WHITE, BLACK); //  /
    LCD_DrawImage1BPP(82 + 42 + 11 + 11 + 11, 100, BMP_a, WHITE, BLACK); //A
    LCD_DrawImage1BPP(82 + 42 + 11 + 11 + 11 + 11, 100, BMP_c, WHITE, BLACK); //C
    LCD_DrawImage1BPP(82 + 42 + 11 + 11 + 11 + 11 + 21, 100, BMP_w, WHITE, BLACK); //  W
    LCD_DrawImage1BPP(82 + 42 + 11 + 11 + 11 + 11 + 21 + 11, 100, BMP_Xiang, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 42 + 11 + 11 + 11 + 11 + 21 + 11 + 21, 100, BMP_Output, WHITE, BLACK); //���
    LCD_DrawImage1BPP(82 + 42 + 11 + 11 + 11 + 11 + 21 + 11 + 21 + 42, 100, BMP_DL, WHITE, BLACK); //����
    LCD_DrawImage1BPP(400 - 24 + 60, 100, BMP_a, WHITE, BLACK); //A

    LCD_DrawImage1BPP(82, 100 + 38, BMP_Youbeng, WHITE, BLACK); //�ͱ�
    LCD_DrawImage1BPP(82 + 42, 100 + 38, BMP_d, WHITE, BLACK); //D
    LCD_DrawImage1BPP(82 + 42 + 11, 100 + 38, BMP_c, WHITE, BLACK); //C
    LCD_DrawImage1BPP(82 + 42 + 11 + 11, 100 + 38, BMP_I, WHITE, BLACK); //  /
    LCD_DrawImage1BPP(82 + 42 + 11 + 11 + 11, 100 + 38, BMP_a, WHITE, BLACK); //A
    LCD_DrawImage1BPP(82 + 42 + 11 + 11 + 11 + 11, 100 + 38, BMP_c, WHITE, BLACK); //C
    LCD_DrawImage1BPP(82 + 42 + 11 + 11 + 11 + 11 + 21, 100 + 38, BMP_v, WHITE, BLACK); //  V
    LCD_DrawImage1BPP(82 + 42 + 11 + 11 + 11 + 11 + 21 + 11, 100 + 38, BMP_Xiang, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 42 + 11 + 11 + 11 + 11 + 21 + 11 + 21, 100 + 38, BMP_Output, WHITE, BLACK); //���
    LCD_DrawImage1BPP(82 + 42 + 11 + 11 + 11 + 11 + 21 + 11 + 21 + 42, 100 + 38, BMP_DL, WHITE, BLACK); //����
    LCD_DrawImage1BPP(400 - 24 + 60, 100 + 38, BMP_a, WHITE, BLACK); //A

    LCD_DrawImage1BPP(82, 100 + 38 * 2, BMP_Youbeng, WHITE, BLACK); //�ͱ�
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 2, BMP_d, WHITE, BLACK); //D
    LCD_DrawImage1BPP(82 + 42 + 11, 100 + 38 * 2, BMP_c, WHITE, BLACK); //C
    LCD_DrawImage1BPP(82 + 42 + 11 + 11, 100 + 38 * 2, BMP_I, WHITE, BLACK); //  /
    LCD_DrawImage1BPP(82 + 42 + 11 + 11 + 11, 100 + 38 * 2, BMP_a, WHITE, BLACK); //A
    LCD_DrawImage1BPP(82 + 42 + 11 + 11 + 11 + 11, 100 + 38 * 2, BMP_c, WHITE, BLACK); //C
    LCD_DrawImage1BPP(82 + 42 + 11 + 11 + 11 + 11 + 21, 100 + 38 * 2, BMP_u, WHITE, BLACK); //  U
    LCD_DrawImage1BPP(82 + 42 + 11 + 11 + 11 + 11 + 21 + 11, 100 + 38 * 2, BMP_Xiang, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 42 + 11 + 11 + 11 + 11 + 21 + 11 + 21, 100 + 38 * 2, BMP_Output, WHITE, BLACK); //���
    LCD_DrawImage1BPP(82 + 42 + 11 + 11 + 11 + 11 + 21 + 11 + 21 + 42, 100 + 38 * 2, BMP_DL, WHITE, BLACK); //����
    LCD_DrawImage1BPP(400 - 24 + 60, 100 + 38 * 2, BMP_a, WHITE, BLACK); //A

    LCD_DrawImage1BPP(82 + 320 + 60, 100, BMP_Sanreqi, WHITE, BLACK); //ɢ����
    LCD_DrawImage1BPP(82 + 63 + 320 + 60, 100, BMP_Wendu, WHITE, BLACK); //�¶�
    LCD_DrawImage1BPP(82 + 63 + 320 + 60 + 42 + 2, 100 + 5, BMP_Maohao, WHITE, BLACK); //:
    LCD_DrawImage1BPP(720 - 24, 100, BMP_T, WHITE, BLACK); //��

    LCD_DrawImage1BPP(82 + 320 + 60, 100 + 38, BMP_Guzhang, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 42 + 320 + 60, 100 + 38, BMP_Code, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 42 + 320 + 60 + 42 + 2, 100 + 5 + 38, BMP_Maohao, WHITE, BLACK); //:
}

void FuzhuUpdate(void) {
    print_SZ_1(82 + 270, 100 - 8, DCAC_W * 0.1 - 1000, 4, 0, WHITE); //W�����
    print_SZ_1(82 + 270, 100 - 8 + 38, DCAC_V * 0.1 - 1000, 4, 0, WHITE); //W�����
    print_SZ_1(82 + 270, 100 - 8 + 38 * 2, DCAC_U * 0.1 - 1000, 4, 0, WHITE); //W�����
    updata_T(82 + 63 + 42 + 80 + 32 + 320, 100 - 8, WHITE, Sanreqi_t, 1, 40); //ɢ�����¶�
    print_SZ_1(82 + 270 + 320 - 52, 100 - 8 + 38, DCAC_Warn_code, 3, 0, WHITE); //������
}

void frmFuzhu(void) {
    if (f_index == 0) { //ֻ����һ��
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

    if (key_set) {//����������
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
void TCUFrame(void) {
    unsigned char i = 0;
    LCD_Clear();
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //��������
    LCD_DrawImage1BPP(130 + 200, 130 - 85, BMP_TCU, WHITE, BLACK); //TCU
    LCD_DrawImage1BPP(130 + 200 + 50, 130 - 85, BMP_STSTEM, WHITE, BLACK); //ϵͳ
    LCD_DrawImage1BPP(130 + 200 + 50 + 50, 130 - 85, BMP_Message, WHITE, BLACK); //��Ϣ

    LCD_DrawRect(80, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320 + 50, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320 + 320, 90, 1, 380, GREEN);
    for (i = 0; i < 11; i++)
        LCD_DrawRect(80, 90 + i * 38, 640, 1, GREEN);

    LCD_DrawImage1BPP(82, 100, BMP_Lihe, WHITE, BLACK); //���
    LCD_DrawImage1BPP(82 + 42, 100, BMP_Shiji, WHITE, BLACK); //ʵ��
    LCD_DrawImage1BPP(82 + 42 + 42, 100, BMP_Weizhi, WHITE, BLACK); //λ��

    LCD_DrawImage1BPP(82, 100 + 38, BMP_Dangwei, WHITE, BLACK); //��λ  

    LCD_DrawImage1BPP(82, 100 + 38 * 2, BMP_t, WHITE, BLACK); //T
    LCD_DrawImage1BPP(82 + 11, 100 + 38 * 2, BMP_c, WHITE, BLACK); //C
    LCD_DrawImage1BPP(82 + 11 + 11, 100 + 38 * 2, BMP_u, WHITE, BLACK); //U
    LCD_DrawImage1BPP(82 + 11 + 11 + 11, 100 + 38 * 2, BMP_Guzhang, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 11 + 11 + 11 + 42, 100 + 38 * 2, BMP_Xinxi, WHITE, BLACK); //��Ϣ

    LCD_DrawImage1BPP(82, 100 + 38 * 3, BMP_Biansuxiang, WHITE, BLACK); //������
    LCD_DrawImage1BPP(82 + 63, 100 + 38 * 3, BMP_Output, WHITE, BLACK); //���
    LCD_DrawImage1BPP(82 + 63 + 42, 100 + 38 * 3, BMP_Zhou, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 63 + 42 + 21, 100 + 38 * 3, BMP_Zhuansu, WHITE, BLACK); //ת��
    LCD_DrawImage1BPP(400 - 42 + 50, 100 + 38 * 3, BMP_RPM, WHITE, BLACK); //RPM

    LCD_DrawImage1BPP(82 + 320 + 50, 100, BMP_f, WHITE, BLACK); //F
    LCD_DrawImage1BPP(82 + 11 + 320 + 50, 100, BMP_m, WHITE, BLACK); //M
    LCD_DrawImage1BPP(82 + 11 + 11 + 320 + 50, 100, BMP_i, WHITE, BLACK); //I
    LCD_DrawImage1BPP(82 + 11 + 11 + 11 + 320 + 50 + 2, 100 + 5, BMP_Maohao, WHITE, BLACK); //:

    LCD_DrawImage1BPP(82 + 320 + 50, 100 + 38, BMP_s, WHITE, BLACK); //S
    LCD_DrawImage1BPP(82 + 11 + 320 + 50, 100 + 38, BMP_p, WHITE, BLACK); //P
    LCD_DrawImage1BPP(82 + 11 + 11 + 320 + 50, 100 + 38, BMP_n, WHITE, BLACK); //N
    LCD_DrawImage1BPP(82 + 11 + 11 + 11 + 320 + 50 + 2, 100 + 5 + 38, BMP_Maohao, WHITE, BLACK); //:

    LCD_DrawImage1BPP(82 + 320 + 50, 100 + 38 * 2, BMP_c, WHITE, BLACK); //C
    LCD_DrawImage1BPP(82 + 11 + 320 + 50, 100 + 38 * 2, BMP_m, WHITE, BLACK); //M
    LCD_DrawImage1BPP(82 + 11 + 11 + 320 + 50 + 2, 100 + 5 + 38 * 2, BMP_Maohao, WHITE, BLACK); //:

    LCD_DrawImage1BPP(82 + 320 + 50, 100 + 38 * 3, BMP_o, WHITE, BLACK); //O
    LCD_DrawImage1BPP(82 + 11 + 320 + 50, 100 + 38 * 3, BMP_c, WHITE, BLACK); //C
    LCD_DrawImage1BPP(82 + 11 + 11 + 320 + 50 + 2, 100 + 5 + 38 * 3, BMP_Maohao, WHITE, BLACK); //:
}

void TCUUpdate(void) {
    print_SZ_1(82 + 200, 100 - 8, TCU_Position, 1, 0, WHITE); //TCUλ��
    print_SZ_1(82 + 200, 100 - 8 + 38, Current_Gear, 1, 0, WHITE); //��λ
    print_D(82 + 200, 100 - 8 + 38 * 2, TCU_code); //������
    print_SZ_1(82 + 200, 100 - 8 + 38 * 3, Speed_rmp, 4, 0, WHITE); //�����ת��
    print_SZ_1(82 + 150 + 320 + 16, 100 - 8, tcu_fmi, 2, 0, WHITE); //fmi
    print_H(82 + 150 + 320 - 48, 100 - 8 + 38, tcu_spn, 6, 0, WHITE); //spn
    print_SZ_1(82 + 150 + 320 + 32, 100 - 8 + 38 * 2, tcu_cm, 1, 0, WHITE); //cm
    print_H(82 + 150 + 320 + 16, 100 - 8 + 38 * 3, tcu_oc, 2, 0, WHITE); //oc
}

void frmTCU(void) {
    if (f_index == 0) { //ֻ����һ��
        f_index = 1;
        TCUFrame();
    } else if (f_index == 1) {
        f_index = 1;
        TCUUpdate();
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

    if (key_set) {//����������
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
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //��������
    LCD_DrawImage1BPP(130 + 200 - 24, 130 - 85, BMP_Battery, WHITE, BLACK); //���
    LCD_DrawImage1BPP(130 + 200 + 50 - 24, 130 - 85, BMP_Manage, WHITE, BLACK); //����
    LCD_DrawImage1BPP(130 + 200 + 50 + 50 - 24, 130 - 85, BMP_STSTEM, WHITE, BLACK); //ϵͳ
    LCD_DrawImage1BPP(130 + 200 + 50 + 50 + 50 - 24, 130 - 85, BMP_Message, WHITE, BLACK); //��Ϣ

    LCD_DrawRect(80, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320 + 320, 90, 1, 380, GREEN);
    for (i = 0; i < 11; i++)
        LCD_DrawRect(80, 90 + i * 38, 640, 1, GREEN);

    LCD_DrawImage1BPP(82, 100, BMP_DC, WHITE, BLACK); //���
    LCD_DrawImage1BPP(82 + 42, 100, BMP_Zong, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 42 + 21, 100, BMP_DY, WHITE, BLACK); //��ѹ
    LCD_DrawImage1BPP(82 + 42 + 21 + 42 + 2, 100 + 5, BMP_Maohao, WHITE, BLACK); //:
    LCD_DrawImage1BPP(400 - 24, 100, BMP_v, WHITE, BLACK); //V

    LCD_DrawImage1BPP(82, 100 + 38, BMP_Zui, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 21, 100 + 38, BMP_Da, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 21 + 21, 100 + 38, BMP_Yunxu, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 21 + 21 + 42, 100 + 38, BMP_Chong, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 21 + 21 + 42 + 21, 100 + 38, BMP_DY, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 21 + 21 + 42 + 21 + 21, 100 + 38, BMP_DL, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 21 + 21 + 42 + 21 + 21 + 42 + 2, 100 + 38 + 5, BMP_Maohao, WHITE, BLACK); //:
    LCD_DrawImage1BPP(400 - 24, 100 + 38, BMP_a, WHITE, BLACK); //A

    LCD_DrawImage1BPP(82, 100 + 38 * 2, BMP_Zui, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 21, 100 + 38 * 2, BMP_Da, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 21 + 21, 100 + 38 * 2, BMP_Yunxu, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 21 + 21 + 42, 100 + 38 * 2, BMP_Fang, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 21 + 21 + 42 + 21, 100 + 38 * 2, BMP_DY, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 21 + 21 + 42 + 21 + 21, 100 + 38 * 2, BMP_DL, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 21 + 21 + 42 + 21 + 21 + 42 + 2, 100 + 38 * 2 + 5, BMP_Maohao, WHITE, BLACK); //:
    LCD_DrawImage1BPP(400 - 24, 100 + 38 * 2, BMP_a, WHITE, BLACK); //A

    LCD_DrawImage1BPP(82, 100 + 38 * 3, BMP_Dan, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 21, 100 + 38 * 3, BMP_Ti, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 21 + 21, 100 + 38 * 3, BMP_Pingjun, WHITE, BLACK); //ƽ��
    LCD_DrawImage1BPP(82 + 21 + 21 + 42, 100 + 38 * 3, BMP_DY, WHITE, BLACK); //��ѹ
    LCD_DrawImage1BPP(82 + 21 + 21 + 42 + 42 + 2, 100 + 38 * 3 + 5, BMP_Maohao, WHITE, BLACK); //:
    LCD_DrawImage1BPP(400 - 24, 100 + 38 * 3, BMP_v, WHITE, BLACK); //V

    LCD_DrawImage1BPP(82, 100 + 38 * 4, BMP_DC, WHITE, BLACK); //���
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 4, BMP_Zhuangtai, WHITE, BLACK); //״̬
    LCD_DrawImage1BPP(82 + 42 + 42, 100 - 8 + 38 * 4, BMP_SZ_1[1], WHITE, BLACK); //1
    LCD_DrawImage1BPP(82 + 42 + 42 + 16 + 2, 100 + 5 + 38 * 4, BMP_Maohao, WHITE, BLACK); //:

    LCD_DrawImage1BPP(82, 100 + 38 * 5, BMP_DC, WHITE, BLACK); //���
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 5, BMP_Zhuangtai, WHITE, BLACK); //״̬
    LCD_DrawImage1BPP(82 + 42 + 42, 100 - 8 + 38 * 5, BMP_SZ_1[2], WHITE, BLACK); //2
    LCD_DrawImage1BPP(82 + 42 + 42 + 16 + 2, 100 + 5 + 38 * 5, BMP_Maohao, WHITE, BLACK); //:

    LCD_DrawImage1BPP(82, 100 + 38 * 6, BMP_DC, WHITE, BLACK); //���
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 6, BMP_Zhuangtai, WHITE, BLACK); //״̬
    LCD_DrawImage1BPP(82 + 42 + 42, 100 - 8 + 38 * 6, BMP_SZ_1[3], WHITE, BLACK); //3
    LCD_DrawImage1BPP(82 + 42 + 42 + 16 + 2, 100 + 5 + 38 * 6, BMP_Maohao, WHITE, BLACK); //:

    LCD_DrawImage1BPP(82 + 320, 100, BMP_Zong, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 320 + 21, 100, BMP_Zheng, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 320 + 21 + 21, 100, BMP_Jueyuan, WHITE, BLACK); //��Ե
    LCD_DrawImage1BPP(82 + 320 + 42 + 42, 100, BMP_DC, WHITE, BLACK); //���
    LCD_DrawImage1BPP(82 + 320 + 42 + 42 + 21, 100, BMP_Zu, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 320 + 42 + 42 + 21 + 21 + 2, 100 + 5, BMP_Maohao, WHITE, BLACK); //:
    LCD_DrawImage1BPP(720 - 28, 100, BMP_k, WHITE, BLACK); //K
    LCD_DrawImage1BPP(720 - 16, 100 + 2, BMP_Omu, WHITE, BLACK); //��

    LCD_DrawImage1BPP(82 + 320, 100 + 38, BMP_Zong, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 320 + 21, 100 + 38, BMP_Fuhe, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 320 + 21 + 21, 100 + 38, BMP_Jueyuan, WHITE, BLACK); //��Ե
    LCD_DrawImage1BPP(82 + 320 + 42 + 42, 100 + 38, BMP_DC, WHITE, BLACK); //���
    LCD_DrawImage1BPP(82 + 320 + 42 + 42 + 21, 100 + 38, BMP_Zu, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 320 + 42 + 42 + 21 + 21 + 2, 100 + 5 + 38, BMP_Maohao, WHITE, BLACK); //:
    LCD_DrawImage1BPP(720 - 28, 100 + 38, BMP_k, WHITE, BLACK); //K
    LCD_DrawImage1BPP(720 - 16, 100 + 38 + 2, BMP_Omu, WHITE, BLACK); //��

    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 2, BMP_Dan, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 320 + 21, 100 + 38 * 2, BMP_Ti, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 320 + 21 + 21, 100 + 38 * 2, BMP_Zui, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 320 + 21 + 21 + 21, 100 + 38 * 2, BMP_Gao, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 320 + 21 + 21 + 21 + 21, 100 + 38 * 2, BMP_DY, WHITE, BLACK); //��ѹ
    LCD_DrawImage1BPP(82 + 320 + 21 + 21 + 21 + 21 + 42 + 2, 100 + 5 + 38 * 2, BMP_Maohao, WHITE, BLACK); //:
    LCD_DrawImage1BPP(720 - 24, 100 + 38 * 2, BMP_v, WHITE, BLACK); //V

    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 3, BMP_Dan, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 320 + 21, 100 + 38 * 3, BMP_Ti, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 320 + 21 + 21, 100 + 38 * 3, BMP_Zui, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 320 + 21 + 21 + 21, 100 + 38 * 3, BMP_Di, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 320 + 21 + 21 + 21 + 21, 100 + 38 * 3, BMP_DY, WHITE, BLACK); //��ѹ
    LCD_DrawImage1BPP(82 + 320 + 21 + 21 + 21 + 21 + 42 + 2, 100 + 5 + 38 * 3, BMP_Maohao, WHITE, BLACK); //:
    LCD_DrawImage1BPP(720 - 24, 100 + 38 * 3, BMP_v, WHITE, BLACK); //V

    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 4, BMP_Dan, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 320 + 21, 100 + 38 * 4, BMP_Ti, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 320 + 21 + 21, 100 + 38 * 4, BMP_Zui, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 320 + 21 + 21 + 21, 100 + 38 * 4, BMP_Gao, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 320 + 21 + 21 + 21 + 21, 100 + 38 * 4, BMP_Wendu, WHITE, BLACK); //�¶�
    LCD_DrawImage1BPP(82 + 320 + 21 + 21 + 21 + 21 + 42 + 2, 100 + 5 + 38 * 4, BMP_Maohao, WHITE, BLACK); //:
    LCD_DrawImage1BPP(720 - 28, 100 + 38 * 4, BMP_T, WHITE, BLACK); //��

    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 5, BMP_Chong, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 320 + 21, 100 + 38 * 5, BMP_Fang, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 320 + 21 + 21, 100 + 38 * 5, BMP_DC, WHITE, BLACK); //���
    LCD_DrawImage1BPP(82 + 320 + 21 + 21 + 21, 100 + 38 * 5, BMP_DL, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 320 + 21 + 21 + 21 + 42 + 2, 100 + 5 + 38 * 5, BMP_Maohao, WHITE, BLACK); //:
    LCD_DrawImage1BPP(720 - 24, 100 + 38 * 5, BMP_a, WHITE, BLACK); //V
    /*******************************/

}

void BMSUpdate(void) {
    updata_DCDY(82 + 200 + 30, 100 - 8);
    updata_DCDL(82 + 200 + 30 + 320 - 16, 100 - 8 + 38 * 5);
    print_D(82 + 180, 100 - 8 + 38 * 4, Status_Flag1);
    print_D(82 + 180, 100 - 8 + 38 * 5, Status_Flag2);
    print_D(82 + 180, 100 - 8 + 38 * 6, Status_Flag3);
    print_SZ_1(82 + 200 + 30, 100 - 8 + 38, BMS_A_charge * 0.1 - 1000, 3, 0, WHITE); //���������
    print_SZ_1(82 + 200 + 30, 100 - 8 + 38 * 2, BMS_A_discharge * 0.1 - 1000, 3, 0, WHITE); //����ŵ����
    print_SZ_1(82 + 200 + 30 - 16, 100 - 8 + 38 * 3, BMS_V_average - 10000, 3, 2, WHITE); //���ƽ����ѹ
    print_SZ_1(82 + 200 + 30 + 270, 100 - 8, Oum_zheng, 5, 0, WHITE); //��Ե��
    print_SZ_1(82 + 200 + 30 + 270, 100 - 8 + 38, Oum_fu, 5, 0, WHITE); //��Ե��
    print_SZ_1(82 + 200 + 30 + 270 + 16, 100 - 8 + 38 * 2, Battery_single_H - 10000, 3, 2, WHITE); //�����ߵ�ѹ
    print_SZ_1(82 + 200 + 30 + 270 + 16, 100 - 8 + 38 * 3, Battery_single_L - 10000, 3, 2, WHITE); //�����͵�ѹ
    updata_T(82 + 200 + 30 + 270 + 32, 100 - 8 + 38 * 4, WHITE, BMS_T_H, 1, 40); //����¶�
}

void frmBMS(void) {
    if (f_index == 0) { //ֻ����һ��
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

    if (key_set) {//����������
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
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //��������
    LCD_DrawImage1BPP(130 + 200 + 24, 130 - 85, BMP_Battery, WHITE, BLACK); //���
    LCD_DrawImage1BPP(130 + 200 + 50 + 24, 130 - 85, BMP_Message, WHITE, BLACK); //��Ϣ
    //�ָ�
    for (i = 0; i < 3; i++)
        LCD_DrawRect(80 + 320 * i, 90, 1, 380, GREEN);
    for (i = 0; i < 11; i++)
        LCD_DrawRect(80, 90 + i * 38, 640, 1, GREEN);
    for (j = 0; j < 2; j++) {
        for (i = 0; i < 10; i++) {
            if (i < 9) {//д��Ÿ�λ
                LCD_DrawImage1BPP(40 + 5 + 16 + 36 + j * 320, 92 + i * 38, BMP_SZ_1[i + 1], WHITE, BLACK);
            } else {//д�����һ�б��
                LCD_DrawImage1BPP(40 + 5 + 16 + 36 + j * 320, 92 + i * 38, BMP_SZ_1[0], WHITE, BLACK);
                LCD_DrawImage1BPP(40 + 5 + 36 + j * 320, 92 + i * 38, BMP_SZ_1[1], WHITE, BLACK);
            }
            if (j == 0)
                LCD_DrawImage1BPP(40 + 5 + 72 + 250, 92 + i * 38, BMP_V, YELLOW, BLACK);
            else
                LCD_DrawImage1BPP(40 + 5 + 70 + 250 + 320, 100 + i * 38, BMP_T, YELLOW, BLACK);
        }
    }

    /********************һ��������ʾ50����λ*****************************/
    //�ָ�
    /*
    for (i = 0; i < 6; i++) {
        LCD_DrawRect(i * 160, 45 + 70, 1, 360, GRAY);
        LCD_DrawRect(60 + i * 160, 45 + 70, 1, 360, GRAY);
    }
    for (i = 0; i < 13; i++)
        LCD_DrawRect(0, 45 + 70 + i * 36, 800, 1, GRAY);

    LCD_DrawImage1BPP(50, 90, BMP_DC, WHITE, BLACK); //���
    LCD_DrawImage1BPP(50 + 42, 90, BMP_DY, WHITE, BLACK); //��ѹ
    LCD_DrawImage1BPP(50 + 42 + 42 + 15, 90 - 9, BMP_SZ_1[index + 1], GREEN, BLACK);

    //���
    if (index == 0) {
        for (j = 0; j < 5; j++) {
            for (i = 0; i < 11; i++) {
                if (i < 9) {//д��Ÿ�λ
                    LCD_DrawImage1BPP(5 + 16 + 16 + j * 160, 46 + 70 + i * 36, BMP_SZ_1[i + 1], WHITE, BLACK);
                    if (j > 0) {//д���ʮλ
                        LCD_DrawImage1BPP(5 + 16 + j * 160, 46 + 70 + i * 36, BMP_SZ_1[j], WHITE, BLACK);
                    }
                } else {//д�����һ�б��
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
                if (i < 9) {//д��Ÿ�λ
                    LCD_DrawImage1BPP(5 + 16 + 16 + j * 160, 46 + 70 + i * 36, BMP_SZ_1[i + 1], WHITE, BLACK); 
                    LCD_DrawImage1BPP(5 + 16 + j * 160, 46 + 70 + i * 36, BMP_SZ_1[j+5], WHITE, BLACK);                   
                } else {//д�����һ�б��
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
                } else {//д�����һ�б��
                    LCD_DrawImage1BPP(5 + 16 + 16 + j * 160, 46 + 70 + i * 36, BMP_SZ_1[0], WHITE, BLACK);
                    LCD_DrawImage1BPP(5 + 16 + j * 160, 46 + 70 + i * 36, BMP_SZ_1[j + 1], WHITE, BLACK);
                }
                LCD_DrawImage1BPP(5 + 4 + 16 + 16 + 100 + j * 160, 46 + 70 + i * 36, BMP_V, YELLOW, BLACK);
                LCD_DrawImage1BPP(5 + j * 160, 46 + 70 + i * 36, BMP_SZ_1[1], WHITE, BLACK);
            }
        }
    }
    
    if (index == 3) {
        LCD_DrawImage1BPP(50, 90, BMP_DC, WHITE, BLACK); //���
        LCD_DrawImage1BPP(50 + 42, 90, BMP_Wendu, WHITE, BLACK); //��ѹ
        LCD_DrawImage1BPP(50 + 42 + 42 + 15, 90 - 9, BMP_SZ_1[1], GREEN, BLACK);
        for (j = 0; j < 5; j++) {
            for (i = 0; i < 11; i++) {
                if (i < 9) {//д��Ÿ�λ
                    LCD_DrawImage1BPP(5 + 16 + 16 + j * 160, 46 + 70 + i * 36, BMP_SZ_1[i + 1], WHITE, BLACK);
                    if (j > 0) {//д���ʮλ
                        LCD_DrawImage1BPP(5 + 16 + j * 160, 46 + 70 + i * 36, BMP_SZ_1[j], WHITE, BLACK);
                    }
                } else {//д�����һ�б��
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
    for (i = 0; i < 10; i++) {
        print_SZ_1(82 + 200 - 100, 100 - 8 + 38 * i, Battery_number[i], 3, 0, GREEN); //�����ѹ���
        print_SZ_1(82 + 200, 100 - 8 + 38 * i, Battery_voltage[i] - 10000, 3, 2, WHITE); //�����ѹ
    }
    for (i = 0; i < 10; i++) {
        print_SZ_1(82 + 200 - 100 + 300, 100 - 8 + 38 * i, Battery_number_t[i], 3, 0, GREEN); //�����¶ȱ��
        updata_T(82 + 200 + 320, 100 - 8 + 38 * i, WHITE, Battery_temp[i], 1, 40); //�����¶�
    }
}

void frmBattery(void) {
    if (f_index == 0) { //ֻ����һ��
        f_index = 1;
        BatteryFrame();
        /*������л�
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
    }

    if (key_up) {
        key_up = 0;
        f_index = 0;
        frmID = 1;
        //Index++;//������л�
        //if(Index==4) Index=0;
    }

    if (key_set) {//����������
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
void AirFrame(void) {
    unsigned char i = 0;
    LCD_Clear();
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //��������
    LCD_DrawImage1BPP(130 + 200 - 2, 130 - 85, BMP_Air, WHITE, BLACK); //�յ�
    LCD_DrawImage1BPP(130 + 200 + 50 - 2, 130 - 85, BMP_STSTEM, WHITE, BLACK); //ϵͳ
    LCD_DrawImage1BPP(130 + 200 + 50 + 50 - 2, 130 - 85, BMP_Message, WHITE, BLACK); //��Ϣ

    LCD_DrawRect(80, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320 + 320, 90, 1, 380, GREEN);
    for (i = 0; i < 11; i++)
        LCD_DrawRect(80, 90 + i * 38, 640, 1, GREEN);

    LCD_DrawImage1BPP(82, 100, BMP_Kongtiao, WHITE, BLACK); //�յ�
    LCD_DrawImage1BPP(82 + 42, 100, BMP_Guzhang, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 42 + 42, 100, BMP_Code, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 42 + 42 + 42 + 2, 100 + 5, BMP_Maohao, WHITE, BLACK); //:

    LCD_DrawImage1BPP(82, 100 + 38, BMP_Kongtiao, WHITE, BLACK); //�յ�
    LCD_DrawImage1BPP(82 + 42, 100 + 38, BMP_Feng, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 42 + 21, 100 + 38, BMP_DJ, WHITE, BLACK); //���
    LCD_DrawImage1BPP(82 + 42 + 21 + 21, 100 + 38, BMP_Zhuangtai, WHITE, BLACK); //״̬
    LCD_DrawImage1BPP(82 + 42 + 21 + 21 + 42 + 2, 100 + 5 + 38, BMP_Maohao, WHITE, BLACK); //:

    LCD_DrawImage1BPP(82, 100 + 38 * 2, BMP_Kongtiao, WHITE, BLACK); //�յ�
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 2, BMP_Gongzuo, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 2, BMP_Zhuangtai, WHITE, BLACK); //״̬
    LCD_DrawImage1BPP(82 + 42 + 42 + 42 + 2, 100 + 5 + 38 * 2, BMP_Maohao, WHITE, BLACK); //:

    LCD_DrawImage1BPP(82, 100 + 38 * 3, BMP_Kongtiao, WHITE, BLACK); //�յ�
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 3, BMP_Life, WHITE, BLACK); //Life
    LCD_DrawImage1BPP(82 + 42 + 44 + 2, 100 + 5 + 38 * 3, BMP_Maohao, WHITE, BLACK); //:

    LCD_DrawImage1BPP(82 + 320, 100, BMP_Che, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 320 + 21, 100, BMP_Wai, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 320 + 42, 100, BMP_Shiji, WHITE, BLACK); //ʵ��
    LCD_DrawImage1BPP(82 + 320 + 42 + 42, 100, BMP_Wendu, WHITE, BLACK); //�¶�
    LCD_DrawImage1BPP(82 + 320 + 42 + 42 + 42 + 2, 100 + 5, BMP_Maohao, WHITE, BLACK); //:
    LCD_DrawImage1BPP(720 - 28, 100, BMP_T, WHITE, BLACK); //��


    LCD_DrawImage1BPP(82 + 320, 100 + 38, BMP_Che, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 320 + 21, 100 + 38, BMP_Nei, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38, BMP_Shiji, WHITE, BLACK); //ʵ��
    LCD_DrawImage1BPP(82 + 320 + 42 + 42, 100 + 38, BMP_Wendu, WHITE, BLACK); //�¶�
    LCD_DrawImage1BPP(82 + 320 + 42 + 42 + 42 + 2, 100 + 5 + 38, BMP_Maohao, WHITE, BLACK); //:
    LCD_DrawImage1BPP(720 - 28, 100 + 38, BMP_T, WHITE, BLACK); //��


    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 2, BMP_Sheding, WHITE, BLACK); //�趨
    LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 2, BMP_Wendu, WHITE, BLACK); //�¶�
    LCD_DrawImage1BPP(82 + 320 + 42 + 42 + 2, 100 + 5 + 38 * 2, BMP_Maohao, WHITE, BLACK); //:
    LCD_DrawImage1BPP(720 - 28, 100 + 38 * 2, BMP_T, WHITE, BLACK); //��

    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 3, BMP_Kongtiao, WHITE, BLACK); //�յ�
    LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 3, BMP_Zhilen, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 320 + 42 + 42, 100 + 38 * 3, BMP_Qingqiu, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 320 + 42 + 42 + 42 + 2, 100 + 5 + 38 * 3, BMP_Maohao, WHITE, BLACK); //:  
}

void AirUpdate(void) {
    print_D(82 + 180, 100 - 8, AC_Warn_code); //�յ�������
    print_D(82 + 180, 100 - 8 + 38, AC_KEY[0].byte); //�յ�����
    print_D(82 + 180, 100 - 8 + 38 * 2, AC_KEY[1].byte); //�յ�״̬
    print_SZ_1(82 + 270 - 10, 100 - 8 + 38 * 3, AC_LIFE, 3, 0, WHITE); //�յ�LIFE
    updata_T(82 + 63 + 42 + 80 + 32 + 320, 100 - 8, WHITE, Indoor_t, 0.5, 30); //�����¶�
    updata_T(82 + 63 + 42 + 80 + 32 + 320, 100 - 8 + 38, WHITE, Outdoor_t, 0.5, 30); //�����¶�
    updata_T(82 + 63 + 42 + 80 + 32 + 320, 100 - 8 + 38 * 2, WHITE, Set_t, 0.5, 30); //�趨�¶�
    print_D(82 + 180 + 320, 100 - 8 + 38 * 3, AC_req); //�յ�����
}

void frmAir(void) {
    if (f_index == 0) { //ֻ����һ��
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

    if (key_set) {//����������
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

void SETFrame(void) {
    LCD_Clear();
    //unsigned char i;
    //unsigned char color = WHITE;
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //��������   
    LCD_DrawRect(0, 430 + 15, 800, 2, YELLOW); //�ײ�����   
    LCD_DrawImage1BPP(220, 195, Bmp_Licheng, WHITE, BLACK); //�ۼ����
    LCD_DrawImage1BPPZOOM_4(405, 190, BMP_HZ_KM, WHITE, BLACK); //��λ Km 
}
//һֱ���µ�����
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
            //frmIC();
            frmControl();
            break;
        case 3:
            //frmBCU_f();
            frmEngine();
            break;
        case 4:
            //frmBCU_m();
            frmFuzhu();
            break;
        case 5:
            //frmBCU_r();
            frmTCU();
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
            frmBCU_r();
            break;
        case 13:
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



