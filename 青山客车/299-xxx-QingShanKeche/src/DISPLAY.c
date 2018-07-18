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

void print_SZ_2(unsigned int x, unsigned int y, //��ʾ����λ��//��������
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
            LCD_DrawImage1BPP(x + i * 16, y, BMP_SZ_2[bcd[i]], color, BLACK);
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
            LCD_DrawImage1BPP(x + i * 16, y, BMP_SZ_2[bcd[i]], color, BLACK);
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

/*void print_D(unsigned int x, unsigned int y, //��2������ʾ
        unsigned char dat) { //��ʾ������       
    unsigned char bcd[8], i = 0;
    for (i = 0; i < 8; i++) {
        bcd[i] = dat % 2;
        dat = dat / 2;
        LCD_DrawImage1BPP(x + 16 * (7 - i), y, BMP_SZ_1[bcd[i]], WHITE, BLACK);
    }
}*/
void print_D(unsigned int x, unsigned int y, //��2������ʾ
        unsigned long dat, //��ʾ������ 
        unsigned char sum, //��ʾ���ݵļ�λ
        unsigned char dot, //��ʾС�����λ��
        unsigned char color1) { //��ʾ���ݵ���ɫ
    unsigned char color, f = 1, i = 0;
    unsigned char bcd[8];
    for (i = 0; i < sum; i++) {
        bcd[sum - i - 1] = dat % 2;
        dat = dat / 2;
    }
    for (i = 0; i < dot; i++) {
        bcd[sum - i] = bcd[sum - 1 - i];
    }
    bcd[sum - dot] = 16; //����С����  
    if (dot > 0) {
        for (i = 0; i <= sum; i++) {
            if (f && (bcd[i] == 0)&&(i < sum - 1 - dot)) { //����ʾǰ��0
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
            if (f && (bcd[i] == 0)&&(i < sum - 1)) { //����ʾǰ��0
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

void disp_rectange(unsigned int x, unsigned int y, //������
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
    LCD_DrawRect(0, 64, 800, 1, GRAY);
    LCD_DrawRect(0, 64 + 64, 800, 1, GRAY);
    for (i = 1; i < 12; i++) {
        LCD_DrawRect(4 + 66 * i, 0, 1, 64, GRAY);
    }
    //�����ӵķ���Ƭ���2016/11/1
    LCD_DrawRect(136, 128, 528, 1, GRAY);
    for (i = 1; i < 12; i++) {
        LCD_DrawRect(4 + 66 * i, 64, 1, 64, GRAY);
    }
    //ÿ�ν��������棬����Ƭ��ɫ���ǻ�ɫ����������ֻ���һ���ϵ���ʾ��ɫ����ҳ��Ͳ���ʾ��ɫ
    for (i = 0; i < 24; i++) {
        color_old[i] = 0;
    }
    LCD_DrawRect(0, 430 + 15, 800, 2, GREEN); //�ײ�����  

    //LCD_DrawRect(0,70,800,3,YELLOW); //��������
    //LCD_DrawImage1BPPZOOM_4(336, 150, BMP_LOGO, BLUE, BLACK); //�ͳ�����
    //������ص��� ��ѹ SOC ���
    LCD_DrawImage1BPP(175, 160, BMP_Voltage, WHITE, BLACK); //��ѹ
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

    LCD_DrawImage1BPP(175, 160 + 60, BMP_Current, WHITE, BLACK); //����
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


    LCD_DrawImage1BPP(10, 365 + 15 - 50 + 10, Bmp_Licheng, YELLOW, BLACK); //���
    LCD_DrawImage1BPP(125, 318 + 15 + 38 + 8, BMP_HZ_KM, WHITE, BLACK); //��λ Km
    LCD_DrawImage1BPP(125, 318 + 15 + 38 * 2 + 8, BMP_HZ_KM, WHITE, BLACK); //��λ Km

    LCD_DrawImage1BPP(165, 365 + 15 - 50 + 10, BMP_DJ, YELLOW, BLACK); //���������
    LCD_DrawImage1BPP(165 + 42, 365 + 15 - 50 + 10, BMP_KZQ, YELLOW, BLACK);
    LCD_DrawImage1BPP(265, 318 + 15 + 38 + 8, BMP_v, WHITE, BLACK); //V
    LCD_DrawImage1BPP(265, 318 + 15 + 38 * 2 + 8, BMP_a, WHITE, BLACK); //A

    LCD_DrawImage1BPP(295, 365 + 15 - 50 + 10, BMP_Dan, YELLOW, BLACK); //�����ѹ
    LCD_DrawImage1BPP(295 + 21, 365 + 15 - 50 + 10, BMP_Ti, YELLOW, BLACK);
    LCD_DrawImage1BPP(295 + 42, 365 + 15 - 50 + 10, BMP_DY, YELLOW, BLACK);
    LCD_DrawImage1BPP(395, 318 + 15 + 38 + 8, BMP_v, WHITE, BLACK); //V
    LCD_DrawImage1BPP(395, 318 + 15 + 38 * 2 + 8, BMP_v, WHITE, BLACK); //V

    LCD_DrawImage1BPP(420, 365 + 15 - 50 + 10, BMP_Dan, YELLOW, BLACK); //�����¶�
    LCD_DrawImage1BPP(420 + 21, 365 + 15 - 50 + 10, BMP_Ti, YELLOW, BLACK);
    LCD_DrawImage1BPP(420 + 42, 365 + 15 - 50 + 10, BMP_Wendu, YELLOW, BLACK);
    LCD_DrawImage1BPP(420 + 90, 318 + 15 + 10 + 38, BMP_T, WHITE, BLACK); //��
    LCD_DrawImage1BPP(420 + 90, 318 + 15 + 10 + 38 * 2, BMP_T, WHITE, BLACK); //��

    LCD_DrawImage1BPP(540, 365 + 15 - 50 + 10, BMP_DJ, YELLOW, BLACK); //���/������
    LCD_DrawImage1BPP(540 + 42, 365 + 15 - 50 + 10, BMP_I, YELLOW, BLACK);
    LCD_DrawImage1BPP(540 + 42 + 11, 365 + 15 - 50 + 10, BMP_KZQ, YELLOW, BLACK);
    LCD_DrawImage1BPP(640, 365 + 15 - 50 + 10 + 38, BMP_T, WHITE, BLACK); //��
    LCD_DrawImage1BPP(640, 365 + 15 - 50 + 10 + 38 * 2, BMP_T, WHITE, BLACK); //��

    LCD_DrawImage1BPP(670, 365 + 15 - 50 + 10, BMP_DC, YELLOW, BLACK); //���/����
    LCD_DrawImage1BPP(670 + 42, 365 + 15 - 50 + 10, BMP_I, YELLOW, BLACK);
    LCD_DrawImage1BPP(670 + 42 + 11, 365 + 15 - 50 + 10, BMP_Qibeng, YELLOW, BLACK);
    LCD_DrawImage1BPP(670 + 100, 365 + 15 - 50 + 10 + 38, BMP_T, WHITE, BLACK); //��
    LCD_DrawImage1BPP(670 + 100, 365 + 15 - 50 + 10 + 38 * 2, BMP_T, WHITE, BLACK); //��

    disp_rectange(5, 365 + 15 - 50, 150, 1, 115, 1, GREEN);
    disp_rectange(5 + 140 + 15, 365 + 15 - 50, 125, 1, 115, 1, GREEN);
    disp_rectange(5 + 270 + 15, 365 + 15 - 50, 125 - 5, 1, 115, 1, GREEN);
    disp_rectange(5 + 400 + 10, 365 + 15 - 50, 125 - 5, 1, 115, 1, GREEN);
    disp_rectange(5 + 530 + 5, 365 + 15 - 50, 125, 1, 115, 1, GREEN);
    disp_rectange(5 + 660 + 5, 365 + 15 - 50, 130 - 5, 1, 115, 1, GREEN);

    /*LCD_DrawImage1BPP(60, 365 - 50 + 10, BMP_Dan, WHITE, BLACK); //�����ѹ
    LCD_DrawImage1BPP(60 + 21, 365 - 50 + 10, BMP_Ti, WHITE, BLACK);
    LCD_DrawImage1BPP(60 + 42, 365 - 50 + 10, BMP_DY, WHITE, BLACK);
    LCD_DrawImage1BPP(15 + 130, 318 + 38 + 8, BMP_v, WHITE, BLACK); //V
    LCD_DrawImage1BPP(15 + 130, 318 + 38 * 2 + 8, BMP_v, WHITE, BLACK); //V

    LCD_DrawImage1BPP(70 + 550, 365 - 50 + 10, BMP_Dan, WHITE, BLACK); //�����¶�
    LCD_DrawImage1BPP(70 + 550 + 21, 365 - 50 + 10, BMP_Ti, WHITE, BLACK);
    LCD_DrawImage1BPP(70 + 550 + 42, 365 - 50 + 10, BMP_Wendu, WHITE, BLACK);
    LCD_DrawImage1BPP(800 - 90, 318 + 10 + 38, BMP_T, WHITE, BLACK); //��
    LCD_DrawImage1BPP(800 - 90, 318 + 10 + 38 * 2, BMP_T, WHITE, BLACK); //��

    LCD_DrawImage1BPP(180 - 20 + 2, 365 - 50 + 10, BMP_DJ, WHITE, BLACK); //���
    LCD_DrawImage1BPP(180 - 20 + 2 + 43, 365 - 50 + 10, BMP_KZQ, WHITE, BLACK); //������
    //LCD_DrawImage1BPP(180 - 20 + 2 + 43 + 64, 365 - 50 + 10, BMP_Wendu, WHITE, BLACK); //�¶�
    LCD_DrawImage1BPP(225 + 83 + 83 - 22, 365 - 50 + 10, BMP_T, WHITE, BLACK); //��

    //LCD_DrawImage1BPP(20, 365 - 50 + 10, BMP_Licheng, WHITE, BLACK); //���

    LCD_DrawImage1BPP(225 + 83 + 83 + 2, 365 - 50 + 10, BMP_DJ, WHITE, BLACK); //���
    LCD_DrawImage1BPP(225 + 83 + 83 + 2 + 43, 365 - 50 + 10, BMP_Zhuansu, WHITE, BLACK); //ת��
    LCD_DrawImage1BPP(615 - 34, 365 - 50 + 10, BMP_RPM, WHITE, BLACK); //RPM

    LCD_DrawImage1BPP(225 + 83 + 83 + 2, 365 - 50 + 10 + 38, BMP_DJ, WHITE, BLACK); //���
    LCD_DrawImage1BPP(225 + 83 + 83 + 2 + 42, 365 - 50 + 10 + 38, BMP_Zhuanju, WHITE, BLACK); //ת��
    LCD_DrawImage1BPP(615 - 22, 365 - 50 + 10 + 38, BMP_n, WHITE, BLACK); //NM
    LCD_DrawImage1BPP(615 - 22 + 11, 365 - 50 + 10 + 38, BMP_m, WHITE, BLACK); //


    LCD_DrawImage1BPP(180 - 20 + 2, 365 - 50 + 10 + 38, BMP_DJ, WHITE, BLACK); //���
    LCD_DrawImage1BPP(180 - 20 + 2 + 43, 365 - 50 + 10 + 38, BMP_Wendu, WHITE, BLACK); //�¶�
    LCD_DrawImage1BPP(225 + 83 + 83 - 22, 365 - 50 + 10 + 38, BMP_T, WHITE, BLACK); //��
     */

    /*LCD_DrawImage1BPP(225 + 83 + 83 + 2, 365 - 50 + 10 + 38, BMP_System, WHITE, BLACK); //ϵͳ
    LCD_DrawImage1BPP(225 + 83 + 83 + 2 + 43, 365 - 50 + 10 + 38, BMP_Code, WHITE, BLACK); //����
    
    LCD_DrawImage1BPP(225 + 83 + 83 + 2, 365 - 50 + 10 + 38*2, BMP_s, WHITE, BLACK); //S
    LCD_DrawImage1BPP(225 + 83 + 83 + 2+ 11 , 365 - 50 + 10 + 38*2, BMP_p, WHITE, BLACK); //P
    LCD_DrawImage1BPP(225 + 83 + 83 + 2+ 11 + 11 , 365 - 50 + 10 + 38*2, BMP_n, WHITE, BLACK); //N
     */
    //LCD_DrawImage1BPP(225 + 83 + 83 + 2+ 11 + 11 + 11 + 2, 365 - 50 + 10 + 38*2, BMP_Maohao, WHITE, BLACK); //:

    //���
    /*LCD_DrawRect(55, 365 - 50, 680, 1, GREEN);
    LCD_DrawRect(55, 365 - 50, 1, 65 + 50, GREEN);
    LCD_DrawRect(735, 365 - 50, 1, 65 + 50, GREEN);
    LCD_DrawRect(180 - 20, 365 - 50, 350 + 85 + 20, 1, GREEN);
    LCD_DrawRect(180 - 20, 365 - 50, 1, 65 + 50, GREEN);
    LCD_DrawRect(225 + 83 + 83, 365 - 50, 1, 65 + 50 - 38, GREEN);
    LCD_DrawRect(615, 365 - 50, 1, 65 + 50, GREEN);
    LCD_DrawRect(180 - 20, 365 - 50 + 38, 350 + 85 + 20, 1, GREEN);
    LCD_DrawRect(180 - 20, 365 - 50 + 38 + 38, 350 + 85 + 20, 1, GREEN);*/

    //LCD_DrawImage1BPPZOOM_4(100, 150 + 70 + 60 + 45 + 50, BMP_DW, WHITE, BLACK); //��λ
    /*
    //��ѹ��1���
    //����
    LCD_DrawRect(33, 100, 50, 3, WHITE); //
    LCD_DrawRect(33, 100, 3, 135, WHITE);
    LCD_DrawRect(83, 100, 3, 135, WHITE);

    LCD_DrawRect(33, 235, 3, 135, RED);
    LCD_DrawRect(83, 235, 3, 138, RED);
    LCD_DrawRect(33, 370, 50, 3, RED); //

    //���
    LCD_DrawImage1BPP(13, 95, BMP_SZ[1], RED, BLACK); //1
    LCD_DrawImage1BPP(21, 95, BMP_SZ[0], RED, BLACK); //0
    LCD_DrawImage1BPP(21, 225, BMP_SZ[5], RED, BLACK); //5
    LCD_DrawImage1BPP(21, 360, BMP_SZ[0], RED, BLACK); //0

    LCD_DrawImage1BPP(33 - 7 + 32, 410, Bmp_Mpa, WHITE, BLACK); //Mpa

    //��ѹ��2���
    LCD_DrawRect(712, 100, 50, 3, WHITE);
    LCD_DrawRect(712, 100, 3, 135, WHITE);
    LCD_DrawRect(712 + 50, 100, 3, 135, WHITE);

    LCD_DrawRect(712, 235, 3, 135, RED);
    LCD_DrawRect(712 + 50, 235, 3, 138, RED);
    LCD_DrawRect(712, 370, 50, 3, RED); //

    LCD_DrawImage1BPP(770, 95, BMP_SZ[1], RED, BLACK); //1
    LCD_DrawImage1BPP(770 + 8, 95, BMP_SZ[0], RED, BLACK); //0
    LCD_DrawImage1BPP(770, 225, BMP_SZ[5], RED, BLACK); //5
    LCD_DrawImage1BPP(770, 360, BMP_SZ[0], RED, BLACK); //0 
     */
    //LCD_DrawImage1BPP(712 - 7 + 32, 410, Bmp_Mpa, WHITE, BLACK); //Mpa

    /*--------------------------------------------
    ������ʾ�ĸ�ʽΪ:(ODO 000.0Km       00:00          TRIP0000000Km)
    ---------------------------------------------*/
    /*LCD_DrawImage1BPP(2, 440 + 3, Bmp_ODO, YELLOW, BLACK); //�ۼ���� ODO  
    //print_SZ_4(2+64+4,440,9999999,7,1,WHITE);

    //LCD_DrawImage1BPPZOOM_4(16 * 6, 318 + 38+2, BMP_HZ_KM, WHITE, BLACK); //��λ Km
    LCD_DrawImage1BPP(210 - 16, 440 + 3, BMP_HZ_KM, WHITE, BLACK); //��λ Km

    LCD_DrawImage1BPP(240 + 300 + 30, 440 + 3, Bmp_TRIP, YELLOW, BLACK); //������� TRIF
    //print_SZ_4(240+80+4,440,9999,4,1,WHITE);
    //LCD_DrawImage1BPPZOOM_4(16 * 6, 318 + 38 * 2+2, BMP_HZ_KM, WHITE, BLACK); //��λ Km
    LCD_DrawImage1BPP(404 + 336 + 30, 440 + 3, BMP_HZ_KM, WHITE, BLACK); //��λ Km
     */
}

void disp_miles(void) {//��ʾ���
    print_SZ_1(10, 318 + 15 + 38 + 2, total_miles / 10, 7, 0, WHITE);
    print_SZ_1(10 + 16, 318 + 15 + 38 * 2 + 2, single_miles, 5, 1, WHITE);
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

void disp_baojing(void) {
    unsigned char color = GRAY;
    /*********************************��һ��***************************************/
    if (IN18) color = YELLOW;
    else color = GRAY;
    if (color_old[0] != color) {
        color_old[0] = color;
        //LCD_DrawImage1BPP(6, 10, Bmp_baojing[1], color, BLACK); //ABS
    }

    if (0) color = RED;
    else color = GRAY;
    if (color_old[1] != color) {
        color_old[1] = color;
        LCD_DrawImage1BPP(6 + 66, 10, Bmp_baojing[14], color, BLACK); //ϵͳ����
    }

    if (rKL1) color = RED;
    else color = GRAY;
    if (color_old[2] != color) {
        color_old[2] = color;
        LCD_DrawImage1BPP(6 + 66 * 2, 10, Bmp_baojing[3], color, BLACK); //�����
    }

    if (!rKL10) color = RED;
    else color = GRAY;
    if (color_old[3] != color) {
        color_old[3] = color;
        LCD_DrawImage1BPP(6 + 66 * 3, 10, Bmp_baojing[8], color, BLACK); //��ǰ��Ƭ
    }

    if (!rKL4) color = RED;
    else color = GRAY;
    if (color_old[4] != color) {
        color_old[4] = color;
        LCD_DrawImage1BPP(6 + 66 * 4, 10, Bmp_baojing[9], color, BLACK); //�����Ƭ
    }

    if (rKL2) color = RED;
    else color = GRAY;
    if (color_old[5] != color) {
        color_old[5] = color;
        LCD_DrawImage1BPP(6 + 66 * 5, 10, Bmp_baojing[2], color, BLACK); //ˮλ

    }

    if (!rKL12) color = RED;
    else color = GRAY;
    if (color_old[6] != color) {
        color_old[6] = color;
        LCD_DrawImage1BPP(6 + 66 * 6, 10, Bmp_baojing[10], color, BLACK); //��ǰ��Ƭ
    }

    if (!rKL6) color = RED;
    else color = GRAY;
    if (color_old[7] != color) {
        color_old[7] = color;
        LCD_DrawImage1BPP(6 + 66 * 7, 10, Bmp_baojing[11], color, BLACK); //�Һ�ɲ��Ƭ
    }

    if (BAT_Status4.bit4) color = RED;
    else color = GRAY;
    if (color_old[8] != color) {
        color_old[8] = color;
        LCD_DrawImage1BPP(6 + 66 * 8, 10, Bmp_baojing[5], color, BLACK); //��Ե����
    }

    if (((BAT_OFFINE == 1) || (MCU_OFFINE == 1) || (SPN[0] > 0))) color = RED;
    else color = GRAY;
    if (color_old[9] != color) {
        color_old[9] = color;
        LCD_DrawImage1BPP(6 + 66 * 9, 10, Bmp_baojing[12], color, BLACK); //ϵͳ����
    }

    /*********************************�ڶ���***************************************/
    //if (AC) color = GREEN;
    //else color = GRAY;
    //if (color_old[11] != color) {
    //    color_old[11] = color;
    //LCD_DrawImage1BPP(6 + 66 * 11, 10, Bmp_baojing[20], color, BLACK); //
    //}

    if (!rKL10) color = RED;
    else color = GRAY;
    if (color_old[15] != color) {
        color_old[15] = color;
        //LCD_DrawImage1BPP(138 + 66 * 1, 74, Bmp_baojing[8], color, BLACK); //��ǰ��Ƭ
    }

    if (!rKL4) color = RED;
    else color = GRAY;
    if (color_old[16] != color) {
        color_old[16] = color;
        //LCD_DrawImage1BPP(138 + 66 * 2, 74, Bmp_baojing[9], color, BLACK); //�����Ƭ
    }

    if (VCU_READY) color = GREEN;
    else color = GRAY;
    if (color_old[17] != color) {
        color_old[17] = color;
        LCD_DrawImage1BPP(138 + 66 * 3 - 1, 74 + 12, Bmp_READY, color, BLACK); //ready
    }

    if (!rKL12) color = RED;
    else color = GRAY;
    if (color_old[18] != color) {
        color_old[18] = color;
        //LCD_DrawImage1BPP(138 + 66 * 4, 74, Bmp_baojing[10], color, BLACK); //��ǰ��Ƭ
    }

    if (!rKL6) color = RED;
    else color = GRAY;
    if (color_old[19] != color) {
        color_old[19] = color;
        //LCD_DrawImage1BPP(138 + 66 * 5, 74, Bmp_baojing[11], color, BLACK); //�Һ���Ƭ
    }

    if (!fKL5) color = RED;
    else color = GRAY;
    if (color_old[20] != color) {
        color_old[20] = color;
        //LCD_DrawImage1BPP(138 + 66 * 6, 74, Bmp_baojing[20], color, BLACK); //��ɲ��Ƭĥ��
    }
}

void disp_VCU_baojing(unsigned char len, DM1 id, unsigned char i) {//ѭ���ѹ��������SPN[i]��
    static unsigned char al_index = 0;
    ////////3S ����һ��  
    if (alarm_vcu_flag == 0) { //3S ����һ��          
        switch (al_index) {
            case 0:
                al_index = 1;
                if (len >= 6) {
                    DM(1, id, i);
                    alarm_vcu_flag = 1;
                    break;
                }

            case 1:
                al_index = 2;
                if (len >= 10) {
                    DM(2, id, i);
                    alarm_vcu_flag = 1;
                    break;
                }

            case 2:
                al_index = 3;
                if (len >= 14) {
                    DM(3, id, i);
                    alarm_vcu_flag = 1;
                    break;
                }

            case 3:
                al_index = 4;
                if (len >= 18) {
                    DM(4, id, i);
                    alarm_vcu_flag = 1;
                    break;
                }

            case 4:
                al_index = 5;
                if (len >= 22) {
                    DM(5, id, i);
                    alarm_vcu_flag = 1;
                    break;
                }

            case 5:
                al_index = 6;
                if (len >= 26) {
                    DM(6, id, i);
                    alarm_vcu_flag = 1;
                    break;
                }

            case 6:
                al_index = 7;
                if (len >= 30) {
                    DM(7, id, i);
                    alarm_vcu_flag = 1;
                    break;
                }

            case 7:
                al_index = 8;
                if (len >= 34) {
                    DM(8, id, i);
                    alarm_vcu_flag = 1;
                    break;
                }

            default:
                al_index = 0;
                break;
        }

        /*if (*(SPN + i) < 6000) {
            print_SZ_1(x, y, *(SPN + i), 6, 0, GREEN);
            print_SZ_1(x + 180, y, *(FMI + i), 3, 0, GREEN);
        }*/
    }
}

void disp_MCU_baojing(unsigned char len, DM1 id, unsigned char i) {//ѭ���ѹ��������SPN[i]��
    static unsigned char al_index = 0;
    ////////3S ����һ��  
    if (alarm_mcu_flag == 0) { //3S ����һ��          
        switch (al_index) {
            case 0:
                al_index = 1;
                if (len >= 6) {
                    DM(1, id, i);
                    alarm_mcu_flag = 1;
                    break;
                }

            case 1:
                al_index = 2;
                if (len >= 10) {
                    DM(2, id, i);
                    alarm_mcu_flag = 1;
                    break;
                }

            case 2:
                al_index = 3;
                if (len >= 14) {
                    DM(3, id, i);
                    alarm_mcu_flag = 1;
                    break;
                }

            case 3:
                al_index = 4;
                if (len >= 18) {
                    DM(4, id, i);
                    alarm_mcu_flag = 1;
                    break;
                }

            case 4:
                al_index = 5;
                if (len >= 22) {
                    DM(5, id, i);
                    alarm_mcu_flag = 1;
                    break;
                }

            case 5:
                al_index = 6;
                if (len >= 26) {
                    DM(6, id, i);
                    alarm_mcu_flag = 1;
                    break;
                }

            case 6:
                al_index = 7;
                if (len >= 30) {
                    DM(7, id, i);
                    alarm_mcu_flag = 1;
                    break;
                }

            case 7:
                al_index = 8;
                if (len >= 34) {
                    DM(8, id, i);
                    alarm_mcu_flag = 1;
                    break;
                }

            default:
                al_index = 0;
                break;
        }
    }
}

void disp_BMS_baojing(unsigned char len, DM1 id, unsigned char i) {//ѭ���ѹ��������SPN[i]��
    static unsigned char al_index = 0;
    ////////3S ����һ��  
    if (alarm_bms_flag == 0) { //3S ����һ��  
        switch (al_index) {
            case 0:
                al_index = 1;
                if (len >= 6) {
                    DM(1, id, i);
                    alarm_bms_flag = 1;
                    break;
                }

            case 1:
                al_index = 2;
                if (len >= 10) {
                    DM(2, id, i);
                    alarm_bms_flag = 1;
                    break;
                }

            case 2:
                al_index = 3;
                if (len >= 14) {
                    DM(3, id, i);
                    alarm_bms_flag = 1;
                    break;
                }

            case 3:
                al_index = 4;
                if (len >= 18) {
                    DM(4, id, i);
                    alarm_bms_flag = 1;
                    break;
                }

            case 4:
                al_index = 5;
                if (len >= 22) {
                    DM(5, id, i);
                    alarm_bms_flag = 1;
                    break;
                }

            case 5:
                al_index = 6;
                if (len >= 26) {
                    DM(6, id, i);
                    alarm_bms_flag = 1;
                    break;
                }

            case 6:
                al_index = 7;
                if (len >= 30) {
                    DM(7, id, i);
                    alarm_bms_flag = 1;
                    break;
                }

            case 7:
                al_index = 8;
                if (len >= 34) {
                    DM(8, id, i);
                    alarm_bms_flag = 1;
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
    if (alarm_update_flag == 0) { //3S ����һ�� 
        //LCD_DrawRect(x, y, 350 + 85 + 10, 36, BLACK); //�����ʾ����
        switch (al_index) {
            case 0:
                al_index = 1;
                /*if (0) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_s, YELLOW, BLACK); //SPN:
                    LCD_DrawImage1BPP(x + 11, y + 8, BMP_p, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11, y + 8, BMP_n, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11 + 11 + 140 , y + 8, BMP_f, YELLOW, BLACK); //FMI:
                    LCD_DrawImage1BPP(x + 11 + 11 + 11 + 140 + 11, y + 8, BMP_m, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11 + 11 + 140 + 11 + 11, y + 8, BMP_i, YELLOW, BLACK);                    
                    disp_VCU_baojing(x + 11 +11 + 11 + 100,y + 8, CAN_18FECAEF_len, CAN_18FECAEF, 0);
                    //LCD_DrawRect(x + 11 + 11 + 11 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/

            case 1:
                al_index = 2;
                /*if (0) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DJ, YELLOW, BLACK); //���ϵͳ����
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_System, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Lixian, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
            case 2:
                al_index = 3;
                if ((BAT_OFFINE == 1) || (MCU_OFFINE == 1) || (SPN[0] > 0)) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Zhengche, YELLOW, BLACK); //����ϵͳ����
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_System, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 3:
                al_index = 4;
                disp_VCU_baojing(CAN_18FECAEF_len, CAN_18FECAEF, 0);
                if (SPN[0] > 0) {
                    LCD_DrawRect(x, y, 300, 36, BLACK); //�����ʾ����
                    LCD_DrawImage1BPP(x, y + 8, BMP_s, YELLOW, BLACK); //SPN
                    LCD_DrawImage1BPP(x + 11, y + 8, BMP_p, YELLOW, BLACK); //  
                    LCD_DrawImage1BPP(x + 11 + 11, y + 8, BMP_n, YELLOW, BLACK); //
                    LCD_DrawImage1BPP(x + 160, y + 8, BMP_f, YELLOW, BLACK); //FMI
                    LCD_DrawImage1BPP(x + 160 + 11, y + 8, BMP_m, YELLOW, BLACK); //  
                    LCD_DrawImage1BPP(x + 160 + 11 + 11, y + 8, BMP_i, YELLOW, BLACK); //
                    print_SZ_2(x + 50, y + 8, *(SPN + 0), 6, 0, YELLOW);
                    print_SZ_2(x + 160 + 30, y + 8, *(FMI + 0), 3, 0, YELLOW);
                    alarm_update_flag = 1;
                    break;
                }

            case 4:
                al_index = 5;
                disp_MCU_baojing(CAN_18FECAEF_len, CAN_18FECAEF, 1);
                if (SPN[1] > 0) {
                    LCD_DrawRect(x, y, 300, 36, BLACK); //�����ʾ����
                    LCD_DrawImage1BPP(x, y + 8, BMP_s, YELLOW, BLACK); //SPN
                    LCD_DrawImage1BPP(x + 11, y + 8, BMP_p, YELLOW, BLACK); //  
                    LCD_DrawImage1BPP(x + 11 + 11, y + 8, BMP_n, YELLOW, BLACK); //
                    LCD_DrawImage1BPP(x + 160, y + 8, BMP_f, YELLOW, BLACK); //FMI
                    LCD_DrawImage1BPP(x + 160 + 11, y + 8, BMP_m, YELLOW, BLACK); //  
                    LCD_DrawImage1BPP(x + 160 + 11 + 11, y + 8, BMP_i, YELLOW, BLACK); //
                    print_SZ_2(x + 50, y + 8, *(SPN + 1), 6, 0, YELLOW);
                    print_SZ_2(x + 160 + 30, y + 8, *(FMI + 1), 3, 0, YELLOW);
                    alarm_update_flag = 1;
                    break;
                }

            case 5:
                al_index = 6;
                disp_BMS_baojing(CAN_18FECAF3_len, CAN_18FECAEF, 2);
                if (SPN[2] > 0) {
                    LCD_DrawRect(x, y, 300, 36, BLACK); //�����ʾ����
                    LCD_DrawImage1BPP(x, y + 8, BMP_s, YELLOW, BLACK); //SPN
                    LCD_DrawImage1BPP(x + 11, y + 8, BMP_p, YELLOW, BLACK); //  
                    LCD_DrawImage1BPP(x + 11 + 11, y + 8, BMP_n, YELLOW, BLACK); //
                    LCD_DrawImage1BPP(x + 160, y + 8, BMP_f, YELLOW, BLACK); //FMI
                    LCD_DrawImage1BPP(x + 160 + 11, y + 8, BMP_m, YELLOW, BLACK); //  
                    LCD_DrawImage1BPP(x + 160 + 11 + 11, y + 8, BMP_i, YELLOW, BLACK); //
                    print_SZ_2(x + 50, y + 8, *(SPN + 2), 6, 0, YELLOW);
                    print_SZ_2(x + 160 + 30, y + 8, *(FMI + 2), 3, 0, YELLOW);
                    alarm_update_flag = 1;
                    break;
                }

            case 6:
                al_index = 7;
                if (MCU_Status1.byte > 0) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DJ, YELLOW, BLACK); //���ϵͳ����
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_System, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 150, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
            case 7:
                al_index = 8;
                if (BAT_Warn_Level > 0) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DC, YELLOW, BLACK); //���ϵͳ����
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_System, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 150, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
            case 8:
                al_index = 9;
                if (pSpeed > 69) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Chaosu, YELLOW, BLACK); //���ٱ���
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42, y, 150, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
            case 9:
                al_index = 10;
                /*if (VCU_Code > 0) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Zhengche, YELLOW, BLACK); //����x������
                    if (VCU_Code >= 150 && VCU_Code <= 200)
                        LCD_DrawImage1BPP(x + 42, y + 8, BMP_SZ_2[4], YELLOW, BLACK);
                    else if (VCU_Code >= 100 && VCU_Code < 150) 
                        LCD_DrawImage1BPP(x + 42, y + 8, BMP_SZ_2[3], YELLOW, BLACK);
                    else if (VCU_Code >= 50 && VCU_Code < 100) 
                        LCD_DrawImage1BPP(x + 42, y + 8, BMP_SZ_2[2], YELLOW, BLACK);
                    else if (VCU_Code > 0 && VCU_Code < 50) 
                        LCD_DrawImage1BPP(x + 42, y + 8, BMP_SZ_2[1], YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 10, y + 8, BMP_Ji, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 10 + 21, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 10 + 21 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
            case 10:
                al_index = 11;
                /*if (TM_Fault.byte > 0) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DJ, YELLOW, BLACK); //���x������
                    if (TM_Fault.bit4)
                        LCD_DrawImage1BPP(x + 42, y + 8, BMP_SZ_2[4], YELLOW, BLACK);
                    else if (TM_Fault.bit3) LCD_DrawImage1BPP(x + 42, y + 8, BMP_SZ_2[3], YELLOW, BLACK);
                    else if (TM_Fault.bit2) LCD_DrawImage1BPP(x + 42, y + 8, BMP_SZ_2[2], YELLOW, BLACK);
                    else if (TM_Fault.bit1) LCD_DrawImage1BPP(x + 42, y + 8, BMP_SZ_2[1], YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 10, y + 8, BMP_Ji, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 10 + 21, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 10 + 21 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
            case 11:
                al_index = 12;
                /*if (TM_Status_Flag1.bit2) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DJ, YELLOW, BLACK); //�������
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 21, y + 8, BMP_Wendu, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/

            case 12:
                al_index = 13;
                /*if (TM_Status_Flag1.bit1) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DJ, YELLOW, BLACK); //�������������
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_KZQ, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 63, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 63 + 21, y + 8, BMP_Wendu, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 63 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/

            case 13:
                al_index = 14;
                /*if (0) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Yuchong, YELLOW, BLACK); //Ԥ�䳬ʱ
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Chaoshi, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/

            case 14:
                al_index = 15;
                if (BAT24V_count == BAT24_TIME) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Xu, YELLOW, BLACK); //���ص�ѹ��
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_DC, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 42, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 42 + 42, y + 8, BMP_Di, YELLOW, BLACK);
                    LCD_DrawRect(x + 21 + 42 + 42 + 21, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 15:
                /*al_index = 16;
                if (((Status_Flag1 >> 2)&0x01) == 1) {
                    LCD_DrawImage1BPP(x, y+8, BMP_s, YELLOW, BLACK); //SOC����
                    LCD_DrawImage1BPP(x + 11, y+8, BMP_o, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11, y+8, BMP_c, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + +11 + 11 + 11, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11 + 11 + 21, y + 8, BMP_Gao, YELLOW, BLACK);
                    LCD_DrawRect(x + 11 + 11 + 11 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/

            case 16:
                /*al_index = 17;
                if (((Status_Flag1 >> 1)&0x01) == 1) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Dan, YELLOW, BLACK); //�����ѹ����
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_Ti, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 21, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 21, y + 8, BMP_Di, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/

            case 17:
                /*al_index = 18;
                if ((Status_Flag1 & 0x01) == 1) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Dan, YELLOW, BLACK); //�����ѹ����
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_Ti, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 21, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 21, y + 8, BMP_Gao, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/

            case 18:
                /*al_index = 19;
                if (((Status_Flag2 >> 7)&0x01) == 1) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Wendu, YELLOW, BLACK); //�²����
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_Cha, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 21, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 21 + 21, y + 8, BMP_Da, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/

            case 19:
                /*al_index = 20;
                if (((Status_Flag2 >> 6)&0x01) == 1) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Wendu, YELLOW, BLACK); //�¶ȱ���
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/

            case 20:
                /*al_index = 21;
                if (((Status_Flag2 >> 5)&0x01) == 1) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Wendu, YELLOW, BLACK); //�¶ȹ���
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 21, y + 8, BMP_Gao, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/

            case 21:
                /*al_index = 22;
                if (((Status_Flag2 >> 4)&0x01) == 1) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Chong, YELLOW, BLACK); //����������
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_DL, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 21, y + 8, BMP_DL, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 21 + 42, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 21 + 41 + 21, y + 8, BMP_Da, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/

            case 22:
                /*al_index = 23;
                if (((Status_Flag2 >> 3)&0x01) == 1) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Fang, YELLOW, BLACK); //�ŵ��������
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_DL, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 21, y + 8, BMP_DL, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 21 + 42, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 21 + 41 + 21, y + 8, BMP_Da, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/

            case 23:
                /*al_index = 24;
                if (((Status_Flag2 >> 2)&0x01) == 1) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Jueyuan, YELLOW, BLACK); //��Ե����
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/

            case 24:
                /*al_index = 25;
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
                }*/

            case 25:
                /*al_index = 26;
                if ((Status_Flag2 & 0x01) == 1) {                    
                    LCD_DrawImage1BPP(x, y + 8, BMP_DC, YELLOW, BLACK); //�����ʧ��
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Re, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 21, y + 8, BMP_Shikong, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 21 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/

            case 26:
                /*al_index = 27;
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
                }*/

            case 27:
                /*al_index = 28;
                if (((Status_Flag3 >> 3)&0x01) == 1) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_You, YELLOW, BLACK); //�е�ѹƫС���
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 21 + 21, y + 8, BMP_Pian, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 21 + 21 + 21, y + 8, BMP_Xiao, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 21 + 21 + 21 + 21, y + 8, BMP_DC, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42 + 21, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/

            case 28:
                al_index = 29;
                if (Fcan_count == CAN_TIME) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Qianbu, YELLOW, BLACK); //ǰ��
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Mokuai, YELLOW, BLACK); //ģ��
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Lixian, YELLOW, BLACK); //����
                    LCD_DrawRect(x + 42 + 42 + 42, y, 150, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 29:
                al_index = 30;
                /*if (Mcan_count == CAN_TIME) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Dingbu, YELLOW, BLACK); //����
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Mokuai, YELLOW, BLACK); //ģ��
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Lixian, YELLOW, BLACK); //����
                    LCD_DrawRect(x + 42 + 42 + 42, y, 42, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/

            case 30:
                al_index = 31;
                if (Rcan_count == CAN_TIME) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Houbu, YELLOW, BLACK); //��
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Mokuai, YELLOW, BLACK); //ģ��
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Lixian, YELLOW, BLACK); //����
                    LCD_DrawRect(x + 42 + 42 + 42, y, 150, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
            default:
                al_index = 0;
                LCD_DrawRect(x, y, 300, 36, BLACK); //�����ʾ����
                break;
        }
    }
}

/*void disp_SPN_FMI(unsigned int x, unsigned int y, unsigned char len, DM1 id) {
    static unsigned char al_index = 0;
    ////////3S ����һ��  
    if (alarm_update_flag == 0) { //3S ����һ��  
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

void updata_Dangwei(unsigned int x, unsigned int y) {
    unsigned char gear = 1;
    gear = VCU_Gear;
    if (gear == 0x44 || gear == 0x4C || gear == 0x4D) gear = 1;
    else if (gear == 0x52) gear = 2;
    else gear = 0;
    LCD_DrawImage1BPP(x, y, BMP_DANGWEI[gear], GREEN, BLACK); //��λ����   
}

void updata_SOC(void) {
    unsigned char color = WHITE;
    unsigned char soc = 100;
    soc = BMS_SOC * 0.4;
    if (soc >= 100) soc = 100;
    if (soc > 25) color = GREEN;
    else if (soc > 0 && soc <= 25) color = RED;
    else color = BLACK;
    print_SZ_1(585, 155 + 60 + 60, soc, 3, 0, WHITE); //SOC��ֵ
    LCD_DrawRect(225 + 2, 150 + 5 + 60 + 60 + 2, (soc * 3.31), 28, color); // 331/100  
    if (soc < 100)//��socΪ100ʱ�����//��ʱ�������
        LCD_DrawRect((225 + 2 + soc * 3.31), 150 + 5 + 60 + 60 + 2, (331 - soc * 3.31), 28, BLACK);
}

void updata_DCDY(unsigned int x, unsigned int y) {
    //unsigned char color = GREEN;
    unsigned int DCDY = 50;
    DCDY = BAT_Voltage * 0.1;
    if (DCDY > 800)
        DCDY = 800;
    print_SZ_1(x, y, DCDY, 3, 0, WHITE); //��ص�ѹ��ֵ x=120+72+30   y=150+60-2
    if (frmID == 0)
        LCD_DrawRect(225 + 2, 150 + 5 + 2, DCDY * 3.31 * 0.125, 28, GREEN); // 331/100  
    if (frmID == 0)//��Ϊ100ʱ�����
        LCD_DrawRect(225 + 2 + DCDY * 3.31 * 0.125, 150 + 5 + 2, 331 - DCDY * 3.31 * 0.125, 28, BLACK);
}

void updata_DCDL(unsigned int x, unsigned int y) {
    unsigned int DCDL = 100;
    DCDL = BAT_Current * 0.1;
    if (DCDL < 1000) {
        DCDL = 1000 - DCDL;
        if (DCDL > 500) DCDL = 500;
        print_SZ_1(x, y, DCDL, 3, 0, WHITE);
        LCD_DrawImage1BPPZOOM_4(x - 20, y + 4, BMP_FU, WHITE, BLACK);
        if (DCDL > 0 && frmID == 0)
            LCD_DrawRect((225 + 2 + 164 - DCDL * 1.64 * 0.2), 150 + 5 + 2 + 60, (DCDL * 1.64 * 0.2 + 1), 28, GREEN);
        if (DCDL < 500 && frmID == 0) {
            LCD_DrawRect(225 + 2, 150 + 5 + 2 + 60, (164 - DCDL * 1.64 * 0.2), 28, BLACK); // 165/100         
            LCD_DrawRect(225 + 83 + 83 + 2, 150 + 5 + 2 + 60, 165, 28, BLACK);
        }
    } else {
        DCDL = DCDL - 1000;
        if (DCDL > 500) DCDL = 500;
        LCD_DrawImage1BPPZOOM_4(x - 20, y + 4, BMP_ZHENG, BLACK, BLACK);
        print_SZ_1(x, y, DCDL, 3, 0, WHITE);
        if (DCDL > 3 && frmID == 0)
            LCD_DrawRect(225 + 83 + 83 + 2, 150 + 5 + 2 + 60, (DCDL * 1.65 * 0.2), 28, GREEN); // �������Ϊ0�������
        if (DCDL < 500 && frmID == 0) {
            LCD_DrawRect((225 + 83 + 83 + 2 + DCDL * 1.65 * 0.2), 150 + 5 + 2 + 60, (165 - DCDL * 1.65 * 0.2), 28, BLACK);
            LCD_DrawRect(225 + 2, 150 + 5 + 2 + 60, 164, 28, BLACK);
        }
    }
}

void updata_DAT(unsigned int x, unsigned int y, //��������ֵ
        unsigned long dat, //��ʾ������ 
        float factor, //����
        unsigned int offset,
        unsigned char color1, //��ɫ
        unsigned char sum, //��ʾ���ݵļ�λ
        unsigned char dot //��ʾС�����λ��       
        ) {//ƫ����
    //unsigned char color = WHITE;
    unsigned int DAT = 100;
    DAT = dat * factor;
    if (DAT < offset) {
        print_SZ_1(x, y, offset - DAT, sum, dot, color1);
        LCD_DrawImage1BPPZOOM_4(x - 25, y + 5, BMP_FU, color1, BLACK);
    } else {
        LCD_DrawImage1BPPZOOM_4(x - 25, y + 5, BMP_ZHENG, BLACK, BLACK);
        print_SZ_1(x, y, DAT - offset, sum, dot, color1); //��ص�����ֵ x=135+180+50+100+20+20   y=150+60-2
    }
}

void frmMain(void) {
    static unsigned char temp = 40;
    if (f_index == 0) { //ֻ����һ��
        f_index = 1;
        mainFrame();
    } else if (f_index == 1) {
        f_index = 2;
        print_SZ_1(305, 318 + 15 + 38, BAT_Single_H * 2, 3, 2, WHITE); //����ߵ�ѹ
        print_SZ_1(305, 318 + 15 + 38 * 2, BAT_Single_L * 2, 3, 2, WHITE); //����͵�ѹ       
    } else if (f_index == 2) {
        f_index = 3;
        disp_baojing();
        updata_DAT(720, 318 + 15 + 38, BAT_Temp, 1, 40, WHITE, 3, 0); //����¶�

        if (ADR[5] >= (84.27 - (0.385 * 25)))
            temp = (ADR[5] - 84.27 + (0.385 * 25)) / 0.385;
        else temp = 0;
        updata_DAT(720, 318 + 15 + 38 * 2, temp, 1, 40, WHITE, 3, 0); //�������¶�
    } else if (f_index == 3) {
        f_index = 4;
        disp_miles();
        updata_DCDL(585, 155 + 60);
        print_SZ_1(190, 318 + 15 + 38, MCU_Voltage * 0.1, 4, 0, WHITE); //�����������ѹ
        updata_DAT(190, 318 + 15 + 38 * 2, MCU_Current, 0.1, 1000, WHITE, 4, 0); //�������������
    } else if (f_index == 4) {
        f_index = 5;
        disp_time(360, 440 + 13, timer);
        updata_DAT(540 + 50, 318 + 15 + 38 * 2, MCU_Controller_Temp, 1, 40, WHITE, 3, 0); //����������¶�
        updata_DAT(540 + 50, 318 + 15 + 38, MCU_Temp, 1, 40, WHITE, 3, 0); //����¶�
    } else if (f_index == 5) {
        f_index = 6;
        updata_SOC();
        updata_DAT(410 + 50, 318 + 15 + 38, BAT_Temp_H, 1, 40, WHITE, 3, 0); //�������
        updata_DAT(410 + 50, 318 + 15 + 38 * 2, BAT_Temp_L, 1, 40, WHITE, 3, 0); //�������
    } else if (f_index == 6) {
        f_index = 7;
        updata_DCDY(585, 155);
        disp_CAN_baojing(2, 450);
    } else if (f_index == 7) {
        f_index = 1;
        updata_Dangwei(138 + 15 + 66 * 4, 74);
        /*print_H(480 + 30 -16, 318 + 38*2, tcu_spn, 5, 0, WHITE); //spn
        if(TCU_code==43) {
            TCU_code=0;  
            TCU_level=0;
        }
        if(TCU_level==3||TCU_level==4)
            color=YELLOW;
        else if(TCU_level==1||TCU_level==2)
            color=RED;
        else color=GREEN;
        print_SZ_1(480 + 30 + 16, 318 + 38, TCU_code, 3, 0, color); //ϵͳ����
    } else {
        f_index = 0;*/
    }

    if (AV_CH == 0) { //�������ֽ���
        if (key_up) { //���ڱ����
            key_up = 0;
            if ((LED15 == 1) && (!time_flag)) {//���⿪��
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
                f_index = 0; //����ֻ����һ�εĽ���
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
                        CS_E = 0; //�ر� 
                        mode = 1; //1,MCU
                        break;
                    case 1: //AV1
                        CS_E = 0; //����
                        mode = 2; //2,AV1 
                        break;
                    case 2: //AV2  SP2  CJ2
                        CS_E = 1; //�� 
                        CS_A = 1;
                        CS_B = 1;
                        CS_C = 1;
                        mode = 6; //AV2
                        break;
                    case 3: //AV2  SP3  CJ3
                        CS_E = 1; //�� 
                        CS_A = 0;
                        CS_B = 1;
                        CS_C = 1;
                        mode = 6; //AV2
                        break;
                    case 4: //AV2  SP4  CJ4
                        CS_E = 1; //�� 
                        CS_A = 1;
                        CS_B = 0;
                        CS_C = 1;
                        mode = 6; //AV2
                        break;
                    default:
                        CS_E = 0; //�ر� 
                        mode = 1; //1,MCU
                        AV_CH = 0;
                        break;
                }
                LCD_CHS(mode);
            }
            if (1) {//��������ѡ��ʹ�ܰ���
                if ((VCU_Gear == 0x52) && R_flag == 0) {//����
                    key_AV = 1; //ģ��AV���ذ�һ��
                    AV_CH = 0; //0+1=1  ����
                    R_flag = 1; //��ֹһֱ�����������������key_AV������1
                }
                if ((VCU_Gear != 0x52) && R_flag == 1) {
                    key_AV = 1;
                    AV_CH = 4; // 0 ����MCU����
                    R_flag = 0;
                    M_flag = 0;
                }
            }

            if (VCU_Gear != 0x52) {//����ѡ��ʹ�ܰ���
                if (rKL15 == 1 && M_flag == 0) {//���ſ�
                    key_AV = 1; //ģ��AV���ذ�һ��
                    AV_CH = 1; //1+1=2  AV1
                    M_flag = 1; //��ֹһֱ�����������������key_AV������1
                }
                if (rKL15 == 0 && M_flag == 1) {
                    key_AV = 1;
                    AV_CH = 4; // 0 ����MCU����
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

    /*if (key_AV) {
        key_AV = 0;
        key_long_set = 0;
        key_up = 0;
        key_set = 0;
        if (time_flag)
            t_add = 1;
        else t_add = 0;
    }*/

    /*if (key_AV) {
        key_AV = 0;
        key_long_set = 0;
        key_up = 0;
        key_set = 0;
        if (time_flag)
            t_add = 1;
        else t_add = 0;

        unsigned char mode = 1; //1,MCU

        if (AV_CH < 2 && !time_flag) AV_CH++;
        else AV_CH = 0;

        switch (AV_CH) {
            case 0: // DAV
                CS_E = 0; //�ر� 
                mode = 1; //1,MCU
                break;
            case 1: //AV1
                CS_E = 0; //����
                mode = 2; //2,AV1 
                break;
            case 2: //AV2  SP2  CJ2
                CS_E = 1; //�� 
                CS_A = 1;
                CS_B = 1;
                CS_C = 1;
                mode = 6; //AV2
                break;
            case 3: //AV2  SP3  CJ3
                CS_E = 1; //�� 
                CS_A = 0;
                CS_B = 1;
                CS_C = 1;
                mode = 6; //AV2
                break;
            case 4: //AV2  SP4  CJ4
                CS_E = 1; //�� 
                CS_A = 1;
                CS_B = 0;
                CS_C = 1;
                mode = 6; //AV2
                break;
            default:
                CS_E = 0; //�ر� 
                mode = 1; //1,MCU
                AV_CH = 0;
                break;
        }
        LCD_CHS(mode);
    }*/

    /***********************************************************/
    /*if (1) {//��������ѡ��ʹ�ܰ���
        if ((VCU_Gear == 0x52) && R_flag == 0) {//����
            key_AV = 1; //ģ��AV���ذ�һ��
            AV_CH = 0; //0+1=1  ����
            R_flag = 1; //��ֹһֱ�����������������key_AV������1
        }
        if ((VCU_Gear != 0x52) && R_flag == 1) {
            key_AV = 1;
            AV_CH = 4; // 0 ����MCU����
            R_flag = 0;
            M_flag = 0;
        }
    }  
    
    if (VCU_Gear != 0x52) {//����ѡ��ʹ�ܰ���
        if (rKL15 == 1 && M_flag == 0) {//���ſ�
            key_AV = 1; //ģ��AV���ذ�һ��
            AV_CH = 1; //1+1=2  AV1
            M_flag = 1; //��ֹһֱ�����������������key_AV������1
        }
        if (rKL15 == 0 && M_flag == 1) {
            key_AV = 1;
            AV_CH = 4; // 0 ����MCU����
            M_flag = 0;
            R_flag = 0;
        }
    }*/
}

/******************************************************/
void ICFrame(unsigned char index) { //�Ǳ���
    unsigned char i;
    LCD_Clear();
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //��������
    if (index == 1) {
        LCD_DrawImage1BPP(130 + 200, 130 - 85, BMP_IC, WHITE, BLACK); //�Ǳ�
        LCD_DrawImage1BPP(130 + 200 + 50, 130 - 85, BMP_STSTEM, WHITE, BLACK); //ϵͳ
        LCD_DrawImage1BPP(130 + 200 + 50 + 50, 130 - 85, BMP_Message, WHITE, BLACK); //��Ϣ

        LCD_DrawImage1BPP(130 + 200 + 200, 130 - 85 + 4, BMP_c, WHITE, BLACK);
        LCD_DrawImage1BPP(130 + 200 + 200 + 11, 130 - 85 + 4, BMP_a, WHITE, BLACK);
        LCD_DrawImage1BPP(130 + 200 + 200 + 11 + 11, 130 - 85 + 4, BMP_n, WHITE, BLACK);
        LCD_DrawImage1BPP(130 + 200 + 200 + 11 + 11 + 11, 130 - 85 + 4, BMP_Tongxin, WHITE, BLACK);

        print_SZ_2(750, 50, 1, 1, 0, WHITE); // 1/3
        LCD_DrawImage1BPP(750 + 11, 50, BMP_I, WHITE, BLACK);
        print_SZ_2(750 + 11 + 14, 50, 3, 1, 0, WHITE);

        /***********************�Ǳ������ɼ�**********************************/
        //��ת��
        LCD_DrawImage1BPP(35, 75, BMP_IC_Zuo, WHITE, BLACK);
        LCD_DrawImage1BPP(35 + 21, 75, BMP_IC_Zhuanxiang, WHITE, BLACK);
        //
        //��Դ����
        LCD_DrawImage1BPP(35, 75 + 25 * 2, BMP_Dianyuan, WHITE, BLACK);
        //ST�ź�
        LCD_DrawImage1BPP(35, 75 + 25 * 3, BMP_s, WHITE, BLACK);
        LCD_DrawImage1BPP(35 + 11, 75 + 25 * 3, BMP_t, WHITE, BLACK);
        LCD_DrawImage1BPP(35 + 11 + 11, 75 + 25 * 3, BMP_IC_Xinhao, WHITE, BLACK);
        //��ת��
        LCD_DrawImage1BPP(35, 75 + 25 * 4, BMP_IC_You, WHITE, BLACK);
        LCD_DrawImage1BPP(35 + 21, 75 + 25 * 4, BMP_IC_Zhuanxiang, WHITE, BLACK);
        //С��
        LCD_DrawImage1BPP(35, 75 + 25 * 5, BMP_Xiao, WHITE, BLACK);
        //Զ���
        LCD_DrawImage1BPP(35, 75 + 25 * 6, BMP_IC_Yuan, WHITE, BLACK);
        LCD_DrawImage1BPP(35 + 21, 75 + 25 * 6, BMP_IC_Guang, WHITE, BLACK);
        //�����
        LCD_DrawImage1BPP(35, 75 + 25 * 7, BMP_IC_Jin, WHITE, BLACK);
        LCD_DrawImage1BPP(35 + 21, 75 + 25 * 7, BMP_IC_Guang, WHITE, BLACK);
        //ǰ���
        LCD_DrawImage1BPP(35, 75 + 25 * 8, BMP_IC_Qian, WHITE, BLACK);
        LCD_DrawImage1BPP(35 + 21, 75 + 25 * 8, BMP_IC_Wu, WHITE, BLACK);
        //�����
        LCD_DrawImage1BPP(35, 75 + 25 * 9, BMP_IC_Hou, WHITE, BLACK);
        LCD_DrawImage1BPP(35 + 21, 75 + 25 * 9, BMP_IC_Wu, WHITE, BLACK);
        //
        //
        //
        //��ε͵�       
        for (i = 13; i < 16; i++) {
            LCD_DrawImage1BPP(35, 75 + 25 * i, BMP_IC_Yugua, WHITE, BLACK);
        }
        LCD_DrawImage1BPP(35 + 42, 75 + 25 * 13, BMP_Di, WHITE, BLACK);
        LCD_DrawImage1BPP(35 + 63, 75 + 25 * 13, BMP_Dang, WHITE, BLACK);
        //��μ�Ъ��
        LCD_DrawImage1BPP(35 + 42, 75 + 25 * 14, BMP_Jianxie, WHITE, BLACK);
        LCD_DrawImage1BPP(35 + 84, 75 + 25 * 14, BMP_Dang, WHITE, BLACK);
        //��θߵ�
        LCD_DrawImage1BPP(35 + 42, 75 + 25 * 15, BMP_Gao, WHITE, BLACK);
        LCD_DrawImage1BPP(35 + 63, 75 + 25 * 15, BMP_Dang, WHITE, BLACK);


        //��
        for (i = 0; i < 16; i++) {
            if (i == 0 || i == 4 || i == 6 || i == 7 || i == 8 || i == 9) {
                if (i != 0 && i != 4)
                    LCD_DrawImage1BPP(35 + 42, 75 + 25 * i, BMP_IC_Deng, WHITE, BLACK);
                LCD_DrawImage1BPP(35 + 63, 75 + 25 * i, BMP_IC_Kaiguan, WHITE, BLACK);
            } else if (i == 5 || i == 2) {
                if (i == 5) {
                    LCD_DrawImage1BPP(35 + 21, 75 + 25 * i, BMP_IC_Deng, WHITE, BLACK);
                }
                LCD_DrawImage1BPP(35 + 42, 75 + 25 * i, BMP_IC_Kaiguan, WHITE, BLACK);
            } else if (i == 13 || i == 15)
                LCD_DrawImage1BPP(35 + 84, 75 + 25 * i, BMP_IC_Kaiguan, WHITE, BLACK);
            else if (i == 14)
                LCD_DrawImage1BPP(35 + 105, 75 + 25 * i, BMP_IC_Kaiguan, WHITE, BLACK);
        }

        //
        //
        //ǰ�ſ�
        LCD_DrawImage1BPP(285, 75 + 25 * 3, BMP_IC_Qian, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 21, 75 + 25 * 3, BMP_Men, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 42, 75 + 25 * 3, BMP_Kai, WHITE, BLACK);
        //�����ˮ
        LCD_DrawImage1BPP(285, 75 + 25 * 4, BMP_IC_Yugua, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 42, 75 + 25 * 4, BMP_Penshui, WHITE, BLACK);
        //������
        /*LCD_DrawImage1BPP(285, 75 + 25 * 5, BMP_DC, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 21, 75 + 25 * 5, BMP_Laba, WHITE, BLACK);*/
        //���1
        LCD_DrawImage1BPP(285, 75 + 25 * 6, BMP_Xiangdeng, WHITE, BLACK);
        print_SZ_2(285 + 42 + 6, 75 + 25 * 6, 1, 1, 0, WHITE);
        //
        //˾����
        LCD_DrawImage1BPP(285, 75 + 25 * 8, BMP_IC_Siji, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 42, 75 + 25 * 8, BMP_IC_Deng, WHITE, BLACK);
        //���Ź�
        LCD_DrawImage1BPP(285, 75 + 25 * 9, BMP_Zhong, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 21, 75 + 25 * 9, BMP_Men, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 42, 75 + 25 * 9, BMP_Guan, WHITE, BLACK);
        //���ſ�
        LCD_DrawImage1BPP(285, 75 + 25 * 10, BMP_Zhong, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 21, 75 + 25 * 10, BMP_Men, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 42, 75 + 25 * 10, BMP_Kai, WHITE, BLACK);
        //ǰ�Ź�
        LCD_DrawImage1BPP(285, 75 + 25 * 11, BMP_IC_Qian, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 21, 75 + 25 * 11, BMP_Men, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 42, 75 + 25 * 11, BMP_Guan, WHITE, BLACK);
        //
        //
        //
        //���2
        LCD_DrawImage1BPP(285, 75 + 25 * 15, BMP_Xiangdeng, WHITE, BLACK);
        print_SZ_2(285 + 42 + 6, 75 + 25 * 15, 2, 1, 0, WHITE);


        //����
        for (i = 0; i < 16; i++) {
            if (i == 3 || i == 8 || i == 9 || i == 10 || i == 11) {
                LCD_DrawImage1BPP(285 + 63, 75 + 25 * i, BMP_IC_Kaiguan, WHITE, BLACK);
            } else if (i == 4) {
                LCD_DrawImage1BPP(285 + 84, 75 + 25 * i, BMP_IC_Kaiguan, WHITE, BLACK);
            } else if (i == 6 || i == 15) {
                LCD_DrawImage1BPP(285 + 42 + 16, 75 + 25 * i, BMP_IC_Kaiguan, WHITE, BLACK);
            }
        }

        //Σ�ձ�������
        LCD_DrawImage1BPP(535, 75 + 25 * 5, BMP_Weixian, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 42, 75 + 25 * 5, BMP_Baojing, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 84, 75 + 25 * 5, BMP_IC_Kaiguan, WHITE, BLACK);
        //ACC����
        LCD_DrawImage1BPP(535, 75 + 25 * 6, BMP_a, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 11, 75 + 25 * 6, BMP_c, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 11 + 11, 75 + 25 * 6, BMP_c, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 11 + 11 + 11, 75 + 25 * 6, BMP_IC_Kaiguan, WHITE, BLACK);
        //Կ��ON����
        LCD_DrawImage1BPP(535, 75 + 25 * 7, BMP_o, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 11, 75 + 25 * 7, BMP_n, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 11 + 11, 75 + 25 * 7, BMP_Dang, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 11 + 11 + 21, 75 + 25 * 7, BMP_IC_Kaiguan, WHITE, BLACK);

        LCD_DrawImage1BPP(535, 75 + 25 * 10, BMP_IC_Qian, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 21, 75 + 25 * 10, BMP_Qiya, WHITE, BLACK);

        LCD_DrawImage1BPP(535, 75 + 25 * 11, BMP_IC_Hou, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 21, 75 + 25 * 11, BMP_Qiya, WHITE, BLACK);

        LCD_DrawImage1BPP(535 + 21, 75 + 25 * 12, BMP_Qibeng, WHITE, BLACK);

        for (i = 8; i < 14; i++) {
            if (i != 10 && i != 11 && i != 12)
                LCD_DrawImage1BPP(535 + 21, 75 + 25 * i, BMP_Beiyong, WHITE, BLACK);
            LCD_DrawImage1BPP(535 + 63, 75 + 25 * i, BMP_Xinhao, WHITE, BLACK);
            LCD_DrawImage1BPP(535 + 63 + 42 + 16 * 4 - 4, 75 + 25 * i, BMP_Omu, WHITE, BLACK); //��
            LCD_DrawImage1BPP(535 + 63 + 42 + 16 * 4 + 16 * 5, 75 + 25 * i, BMP_v, WHITE, BLACK); //V
        }

        LCD_DrawImage1BPP(505 + 100, 75 + 8 + 25 * 15, BMP_Banben, WHITE, BLACK);
        LCD_DrawImage1BPP(505 + 100 + 42, 75 + 8 + 25 * 15, BMP_Hao, WHITE, BLACK);
        LCD_DrawImage1BPP(505 + 200, 75 + 25 * 15, BMP_V, WHITE, BLACK);
    } else if (index == 2) {
        print_SZ_2(750, 50, 2, 1, 0, WHITE); // 2/3
        LCD_DrawImage1BPP(750 + 11, 50, BMP_I, WHITE, BLACK);
        print_SZ_2(750 + 11 + 14, 50, 3, 1, 0, WHITE);

        LCD_DrawImage1BPP(130 + 200 + 200, 130 - 85 + 4, BMP_c, WHITE, BLACK);
        LCD_DrawImage1BPP(130 + 200 + 200 + 11, 130 - 85 + 4, BMP_a, WHITE, BLACK);
        LCD_DrawImage1BPP(130 + 200 + 200 + 11 + 11, 130 - 85 + 4, BMP_n, WHITE, BLACK);
        LCD_DrawImage1BPP(130 + 200 + 200 + 11 + 11 + 11, 130 - 85 + 4, BMP_Tongxin, WHITE, BLACK);

        LCD_DrawImage1BPP(130 + 200, 130 - 85, BMP_QIAN, WHITE, BLACK); //ǰ
        LCD_DrawImage1BPP(130 + 200 + 25, 130 - 85, BMP_MOKUAI, WHITE, BLACK); //ģ��
        LCD_DrawImage1BPP(130 + 200 + 25 + 50, 130 - 85, BMP_Message, WHITE, BLACK); //��Ϣ
        for (i = 0; i < 15; i++) {
            LCD_DrawImage1BPP(60 + 280, 75 + 3 + 25 * i, BMP_a, WHITE, BLACK);
            //LCD_DrawRect(0, 74 +25+ 25 * i, 800, 1, GRAY); //����
        }
        /*************************ǰģ�����***********************************/
        for (i = 0; i < 3; i++) {
            LCD_DrawImage1BPP(60, 75 + 25 * i, BMP_IC_Yugua, WHITE, BLACK);
        }
        //�ߵ�
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 0, BMP_Gao, WHITE, BLACK);
        //�͵�
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 1, BMP_Di, WHITE, BLACK);
        //��ˮ
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 2, BMP_Penshui, WHITE, BLACK);
        for (i = 0; i < 3; i++) {
            if (i != 2) LCD_DrawImage1BPP(60 + 63, 75 + 25 * i, BMP_Dang, WHITE, BLACK);
            LCD_DrawImage1BPP(60 + 84, 75 + 25 * i, BMP_DJ, WHITE, BLACK);
        }
        //��ǰ���
        LCD_DrawImage1BPP(60, 75 + 25 * 3, BMP_IC_Zuo, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 3, BMP_IC_Qian, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 3, BMP_IC_Wu, WHITE, BLACK);
        //������
        LCD_DrawImage1BPP(60, 75 + 25 * 4, BMP_Zhaoming, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 4, BMP_IC_Deng, WHITE, BLACK);
        //��ת���
        LCD_DrawImage1BPP(60, 75 + 25 * 5, BMP_IC_You, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 5, BMP_IC_Zhuanxiang, WHITE, BLACK);
        //��ת���
        LCD_DrawImage1BPP(60, 75 + 25 * 6, BMP_IC_Zuo, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 6, BMP_IC_Zhuanxiang, WHITE, BLACK);
        //����
        LCD_DrawImage1BPP(60, 75 + 25 * 7, BMP_Laba, WHITE, BLACK);
        //��Զ���
        LCD_DrawImage1BPP(60, 75 + 25 * 8, BMP_IC_Zuo, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 8, BMP_IC_Yuan, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 8, BMP_IC_Guang, WHITE, BLACK);
        //��ǰ���
        LCD_DrawImage1BPP(60, 75 + 25 * 9, BMP_IC_You, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 9, BMP_IC_Qian, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 9, BMP_IC_Wu, WHITE, BLACK);
        //��Զ���
        LCD_DrawImage1BPP(60, 75 + 25 * 10, BMP_IC_You, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 10, BMP_IC_Yuan, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 10, BMP_IC_Guang, WHITE, BLACK);
        //�յ���Դ
        LCD_DrawImage1BPP(60, 75 + 25 * 11, BMP_Kongtiao, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 11, BMP_Dianyuan, WHITE, BLACK);
        //������
        LCD_DrawImage1BPP(60, 75 + 25 * 12, BMP_IC_Zuo, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 12, BMP_IC_Jin, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 12, BMP_IC_Guang, WHITE, BLACK);
        //λ�õ�
        LCD_DrawImage1BPP(60, 75 + 25 * 13, BMP_Weizhi, WHITE, BLACK);
        //�ҽ����
        LCD_DrawImage1BPP(60, 75 + 25 * 14, BMP_IC_You, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 14, BMP_IC_Jin, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 14, BMP_IC_Guang, WHITE, BLACK);
        //ADD��θ�λ�ź�
        LCD_DrawImage1BPP(60, 75 + 25 * 15, BMP_a, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 11, 75 + 25 * 15, BMP_d, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 11 + 11, 75 + 25 * 15, BMP_d, WHITE, BLACK);

        for (i = 0; i < 16; i++) {
            if (i == 3 || i == 5 || i == 6 || i == 8 || i == 9 || i == 10 || i == 12 || i == 14)
                LCD_DrawImage1BPP(60 + 63, 75 + 25 * i, BMP_IC_Deng, WHITE, BLACK);
            else if (i == 13)
                LCD_DrawImage1BPP(60 + 42, 75 + 25 * i, BMP_IC_Deng, WHITE, BLACK);
        }
        /***********************ǰģ�鿪�زɼ�*********************************/
        //
        //
        //
        //
        //פ������
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 4, BMP_Zhuche, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 4, BMP_IC_Kaiguan, WHITE, BLACK);
        //
        //���ȿ���
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 6, BMP_Laba, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 6, BMP_IC_Kaiguan, WHITE, BLACK);
        //
        //
        //
        //

        //��ַѡ��1
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 12, BMP_Dizhi, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 12, BMP_Xuanze, WHITE, BLACK);
        print_SZ_2(285 + 150 + 84 + 6, 75 + 25 * 12, 1, 1, 0, WHITE);

        //��ַѡ��2
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 13, BMP_Dizhi, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 13, BMP_Xuanze, WHITE, BLACK);
        print_SZ_2(285 + 150 + 84 + 6, 75 + 25 * 13, 2, 1, 0, WHITE);

        //�汾��
        LCD_DrawImage1BPP(505 + 100, 75 + 8 + 25 * 15, BMP_Banben, WHITE, BLACK);
        LCD_DrawImage1BPP(505 + 100 + 42, 75 + 8 + 25 * 15, BMP_Hao, WHITE, BLACK);
        LCD_DrawImage1BPP(505 + 200, 75 + 25 * 15, BMP_V, WHITE, BLACK);
    } else if (index == 3) {
        LCD_DrawImage1BPP(130 + 200 + 200, 130 - 85 + 4, BMP_c, WHITE, BLACK);
        LCD_DrawImage1BPP(130 + 200 + 200 + 11, 130 - 85 + 4, BMP_a, WHITE, BLACK);
        LCD_DrawImage1BPP(130 + 200 + 200 + 11 + 11, 130 - 85 + 4, BMP_n, WHITE, BLACK);
        LCD_DrawImage1BPP(130 + 200 + 200 + 11 + 11 + 11, 130 - 85 + 4, BMP_Tongxin, WHITE, BLACK);

        print_SZ_2(750, 50, 3, 1, 0, WHITE); // 3/4
        LCD_DrawImage1BPP(750 + 11, 50, BMP_I, WHITE, BLACK);
        print_SZ_2(750 + 11 + 14, 50, 4, 1, 0, WHITE);

        LCD_DrawImage1BPP(130 + 200, 130 - 85, BMP_DING, WHITE, BLACK); //��
        LCD_DrawImage1BPP(130 + 200 + 25, 130 - 85, BMP_MOKUAI, WHITE, BLACK); //ģ��
        LCD_DrawImage1BPP(130 + 200 + 25 + 50, 130 - 85, BMP_Message, WHITE, BLACK); //��Ϣ
        for (i = 0; i < 15; i++) {
            LCD_DrawImage1BPP(60 + 280, 75 + 3 + 25 * i, BMP_a, WHITE, BLACK);
            //LCD_DrawRect(0, 74 +25+ 25 * i, 800, 1, GRAY); //����
        }

        /*********************��ģ�����***************************************/
        //������1
        LCD_DrawImage1BPP(60, 75 + 25 * 0, BMP_IC_Changtiao, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 0, BMP_IC_Deng, WHITE, BLACK);
        print_SZ_2(60 + 63 + 6, 75 + 25 * 0, 1, 1, 0, WHITE);
        //��ת���
        LCD_DrawImage1BPP(60, 75 + 25 * 1, BMP_IC_You, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 1, BMP_IC_Zhuanxiang, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 63, 75 + 25 * 1, BMP_IC_Deng, WHITE, BLACK);
        //˾����
        LCD_DrawImage1BPP(60, 75 + 25 * 2, BMP_IC_Siji, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 2, BMP_IC_Deng, WHITE, BLACK);
        //�ƶ���
        LCD_DrawImage1BPP(60, 75 + 25 * 3, BMP_Zhidong, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 3, BMP_IC_Deng, WHITE, BLACK);
        //ǰ�ſ����
        LCD_DrawImage1BPP(60, 75 + 25 * 4, BMP_IC_Qian, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 4, BMP_Men, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 4, BMP_Kai, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 63, 75 + 25 * 4, BMP_Diancifa, WHITE, BLACK);
        //ǰ·��
        LCD_DrawImage1BPP(60, 75 + 25 * 5, BMP_IC_Qian, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 5, BMP_Lupai, WHITE, BLACK);
        //ǰ�Ź����
        LCD_DrawImage1BPP(60, 75 + 25 * 6, BMP_IC_Qian, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 6, BMP_Men, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 6, BMP_Guan, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 63, 75 + 25 * 6, BMP_Diancifa, WHITE, BLACK);
        //�����ӵ�Դ
        LCD_DrawImage1BPP(60, 75 + 25 * 7, BMP_Dianzizhong, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 63, 75 + 25 * 7, BMP_Dianyuan, WHITE, BLACK);
        //���ſ����
        LCD_DrawImage1BPP(60, 75 + 25 * 8, BMP_Zhong, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 8, BMP_Men, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 8, BMP_Kai, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 63, 75 + 25 * 8, BMP_Diancifa, WHITE, BLACK);
        //��·��
        LCD_DrawImage1BPP(60, 75 + 25 * 9, BMP_IC_Hou, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 9, BMP_Lupai, WHITE, BLACK);
        //���Ź����
        LCD_DrawImage1BPP(60, 75 + 25 * 10, BMP_Zhong, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 10, BMP_Men, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 10, BMP_Guan, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 63, 75 + 25 * 10, BMP_Diancifa, WHITE, BLACK);
        //������2
        LCD_DrawImage1BPP(60, 75 + 25 * 11, BMP_IC_Changtiao, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 11, BMP_IC_Deng, WHITE, BLACK);
        print_SZ_2(60 + 63 + 6, 75 + 25 * 11, 2, 1, 0, WHITE);
        //Ӳ�̵�Դ
        LCD_DrawImage1BPP(60, 75 + 25 * 12, BMP_Yinpan, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 12, BMP_Dianyuan, WHITE, BLACK);
        //λ�õ�
        LCD_DrawImage1BPP(60, 75 + 25 * 13, BMP_Weizhi, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 13, BMP_IC_Deng, WHITE, BLACK);
        //��ת���
        LCD_DrawImage1BPP(60, 75 + 25 * 14, BMP_IC_Zuo, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 14, BMP_IC_Zhuanxiang, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 63, 75 + 25 * 14, BMP_IC_Deng, WHITE, BLACK);

        /************************��ģ�鿪��*********************************/
        //���忪��
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 1, BMP_Men, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 21, 75 + 25 * 1, BMP_Ling, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 1, BMP_IC_Kaiguan, WHITE, BLACK);
        //ǰ��Ӧ��������2
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 3, BMP_IC_Qian, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 21, 75 + 25 * 3, BMP_Men, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 3, BMP_Yingjifa, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 105, 75 + 25 * 3, BMP_Baojing, WHITE, BLACK);
        print_SZ_2(285 + 150 + 105 + 42 + 6, 75 + 25 * 3, 2, 1, 0, WHITE);
        //����Ӧ��������2
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 5, BMP_Zhong, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 21, 75 + 25 * 5, BMP_Men, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 5, BMP_Yingjifa, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 105, 75 + 25 * 5, BMP_Baojing, WHITE, BLACK);
        print_SZ_2(285 + 150 + 105 + 42 + 6, 75 + 25 * 5, 2, 1, 0, WHITE);
        //��ַѡ��1
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 12, BMP_Dizhi, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 12, BMP_Xuanze, WHITE, BLACK);
        print_SZ_2(285 + 150 + 84 + 6, 75 + 25 * 12, 1, 1, 0, WHITE);
        //��ַѡ��2
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 13, BMP_Dizhi, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 13, BMP_Xuanze, WHITE, BLACK);
        print_SZ_2(285 + 150 + 84 + 6, 75 + 25 * 13, 2, 1, 0, WHITE);
        //���ſ��ź�
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 14, BMP_Zhong, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 21, 75 + 25 * 14, BMP_Men, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 14, BMP_Kai, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 63, 75 + 25 * 14, BMP_Xinhao, WHITE, BLACK);
        //ǰ�ſ��ź�
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 15, BMP_IC_Qian, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 21, 75 + 25 * 15, BMP_Men, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 15, BMP_Kai, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 63, 75 + 25 * 15, BMP_Xinhao, WHITE, BLACK);

        LCD_DrawImage1BPP(505 + 100, 75 + 8 + 25 * 15, BMP_Banben, WHITE, BLACK);
        LCD_DrawImage1BPP(505 + 100 + 42, 75 + 8 + 25 * 15, BMP_Hao, WHITE, BLACK);
        LCD_DrawImage1BPP(505 + 200, 75 + 25 * 15, BMP_V, WHITE, BLACK);
    } else if (index == 4) {
        LCD_DrawImage1BPP(130 + 200 + 200, 130 - 85 + 4, BMP_c, WHITE, BLACK);
        LCD_DrawImage1BPP(130 + 200 + 200 + 11, 130 - 85 + 4, BMP_a, WHITE, BLACK);
        LCD_DrawImage1BPP(130 + 200 + 200 + 11 + 11, 130 - 85 + 4, BMP_n, WHITE, BLACK);
        LCD_DrawImage1BPP(130 + 200 + 200 + 11 + 11 + 11, 130 - 85 + 4, BMP_Tongxin, WHITE, BLACK);

        print_SZ_2(750, 50, 3, 1, 0, WHITE); // 3/3
        LCD_DrawImage1BPP(750 + 11, 50, BMP_I, WHITE, BLACK);
        print_SZ_2(750 + 11 + 14, 50, 3, 1, 0, WHITE);

        LCD_DrawImage1BPP(130 + 200, 130 - 85, BMP_HOU, WHITE, BLACK); //��
        LCD_DrawImage1BPP(130 + 200 + 25, 130 - 85, BMP_MOKUAI, WHITE, BLACK); //ģ��
        LCD_DrawImage1BPP(130 + 200 + 25 + 50, 130 - 85, BMP_Message, WHITE, BLACK); //��Ϣ
        for (i = 0; i < 15; i++) {
            LCD_DrawImage1BPP(60 + 280, 75 + 3 + 25 * i, BMP_a, WHITE, BLACK);
            //LCD_DrawRect(0, 74 +25+ 25 * i, 800, 1, GRAY); //����
        }
        /*********************��ģ�����***************************************/
        //��ȴˮ��
        LCD_DrawImage1BPP(60, 75 + 25 * 0, BMP_Lengque, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 0, BMP_Shuibeng, WHITE, BLACK);
        //���Źص�ŷ�
        LCD_DrawImage1BPP(60, 75 + 25 * 1, BMP_Zhong, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 1, BMP_Men, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 1, BMP_Guan, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 63, 75 + 25 * 1, BMP_Diancifa, WHITE, BLACK);
        //���1
        LCD_DrawImage1BPP(60, 75 + 25 * 2, BMP_Xiangdeng, WHITE, BLACK);
        print_SZ_2(60 + 42 + 6, 75 + 25 * 2, 1, 1, 0, WHITE);
        //ǰ�ſ���ŷ�
        LCD_DrawImage1BPP(60, 75 + 25 * 3, BMP_IC_Qian, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 3, BMP_Men, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 3, BMP_Kai, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 63, 75 + 25 * 3, BMP_Diancifa, WHITE, BLACK);
        //˾����
        LCD_DrawImage1BPP(60, 75 + 25 * 4, BMP_IC_Siji, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 4, BMP_IC_Deng, WHITE, BLACK);
        //ǰ�Źص�ŷ�
        LCD_DrawImage1BPP(60, 75 + 25 * 5, BMP_IC_Qian, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 5, BMP_Men, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 5, BMP_Guan, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 63, 75 + 25 * 5, BMP_Diancifa, WHITE, BLACK);
        //�����
        LCD_DrawImage1BPP(60, 75 + 25 * 6, BMP_IC_Hou, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 6, BMP_IC_Wu, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 6, BMP_IC_Deng, WHITE, BLACK);
        //��ת���
        LCD_DrawImage1BPP(60, 75 + 25 * 7, BMP_IC_Zuo, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 7, BMP_IC_Zhuanxiang, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 63, 75 + 25 * 7, BMP_IC_Deng, WHITE, BLACK);
        //�ƶ���
        LCD_DrawImage1BPP(60, 75 + 25 * 8, BMP_Zhidong, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 8, BMP_IC_Deng, WHITE, BLACK);
        //��ת���
        LCD_DrawImage1BPP(60, 75 + 25 * 9, BMP_IC_You, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 9, BMP_IC_Zhuanxiang, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 63, 75 + 25 * 9, BMP_IC_Deng, WHITE, BLACK);
        //������
        LCD_DrawImage1BPP(60, 75 + 25 * 10, BMP_Daoche, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 10, BMP_IC_Deng, WHITE, BLACK);
        //��λ�õ�
        LCD_DrawImage1BPP(60, 75 + 25 * 11, BMP_IC_Hou, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 11, BMP_Weizhi, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 63, 75 + 25 * 11, BMP_IC_Deng, WHITE, BLACK);
        //��λ�õ�
        LCD_DrawImage1BPP(60, 75 + 25 * 12, BMP_Ding, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 12, BMP_Weizhi, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 63, 75 + 25 * 12, BMP_IC_Deng, WHITE, BLACK);
        //���2
        LCD_DrawImage1BPP(60, 75 + 25 * 13, BMP_Xiangdeng, WHITE, BLACK);
        print_SZ_2(60 + 42 + 6, 75 + 25 * 13, 2, 1, 0, WHITE);
        //���ſ���ŷ�
        LCD_DrawImage1BPP(60, 75 + 25 * 14, BMP_Zhong, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 14, BMP_Men, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 14, BMP_Kai, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 63, 75 + 25 * 14, BMP_Diancifa, WHITE, BLACK);

        /*********************��ģ�鿪��***************************************/
        //�����
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 0, BMP_IC_Hou, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 21, 75 + 25 * 0, BMP_Cangmen, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 63, 75 + 25 * 0, BMP_IC_Kaiguan, WHITE, BLACK);
        //ˮλ����
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 1, BMP_Shuiwei, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 1, BMP_Baojing, WHITE, BLACK);
        //
        //���Ħ��Ƭ����
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 3, BMP_IC_Zuo, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 21, 75 + 25 * 3, BMP_IC_Hou, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 3, BMP_Mocapian, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 105, 75 + 25 * 3, BMP_Baojing, WHITE, BLACK);
        //
        //�Һ�Ħ��Ƭ����
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 5, BMP_IC_You, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 21, 75 + 25 * 5, BMP_IC_Hou, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 5, BMP_Mocapian, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 105, 75 + 25 * 5, BMP_Baojing, WHITE, BLACK);
        //
        //�ƶ�����
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 7, BMP_Zhidong, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 7, BMP_IC_Kaiguan, WHITE, BLACK);
        //
        //��ǰĦ��Ƭ����
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 9, BMP_IC_Zuo, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 21, 75 + 25 * 9, BMP_IC_Qian, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 9, BMP_Mocapian, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 105, 75 + 25 * 9, BMP_Baojing, WHITE, BLACK);
        //
        //��ǰĦ��Ƭ����
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 11, BMP_IC_You, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 21, 75 + 25 * 11, BMP_IC_Qian, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 11, BMP_Mocapian, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 105, 75 + 25 * 11, BMP_Baojing, WHITE, BLACK);
        //��ַѡ��1
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 12, BMP_Dizhi, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 12, BMP_Xuanze, WHITE, BLACK);
        print_SZ_2(285 + 150 + 84 + 6, 75 + 25 * 12, 1, 1, 0, WHITE);
        //��ַѡ��2
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 13, BMP_Dizhi, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 13, BMP_Xuanze, WHITE, BLACK);
        print_SZ_2(285 + 150 + 84 + 6, 75 + 25 * 13, 2, 1, 0, WHITE);
        //���ſ��ź�
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 14, BMP_Zhong, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 21, 75 + 25 * 14, BMP_Men, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 14, BMP_Kai, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 63, 75 + 25 * 14, BMP_Xinhao, WHITE, BLACK);
        //ǰ�ſ��ź�
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 15, BMP_IC_Qian, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 21, 75 + 25 * 15, BMP_Men, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 15, BMP_Kai, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 63, 75 + 25 * 15, BMP_Xinhao, WHITE, BLACK);

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
                print_SZ(30 + 250, 75 + 6 + 25 * i, fpcur[i] / 100, 3, 1, YELLOW); //ǰģ�����
            else
                print_SZ(30 + 250, 75 + 6 + 25 * i, 0, 3, 1, YELLOW);
        }
        //ADD��θ�λ�ź�
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
        //����汾��
        print_SZ_1(535 + 200, 75 + 25 * 15, Fversion, 3, 2, YELLOW);
    }

    /*�п�ģ��*/
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
        //����汾��
        print_SZ_1(535 + 200, 75 + 25 * 15, Mversion, 3, 2, YELLOW);
    }

    /*���ģ��*/
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
        //����汾��
        print_SZ_1(535 + 200, 75 + 25 * 15, Rversion, 3, 2, YELLOW);
    }
}

void frmIC(void) {
    static unsigned char index_IC = 1;
    if (f_index == 0) { //ֻ����һ��
        f_index = 1;
        ICFrame(index_IC);
    } else if (f_index == 1) {
        f_index = 1;
        ICUpdate(index_IC);
    } else {
        f_index = 0;
    }

    if (key_up) { //�Ӳ˵��л�
        key_up = 0;
        index_IC++;
        if (index_IC == 3)
            index_IC = 4;
        f_index = 0;
        if (index_IC == 5) {
            index_IC = 1;
            frmID = 1;
        }
    }

    if (key_AV) {
        key_AV = 0;
        index_IC--;
        if (index_IC == 3)
            index_IC = 2;
        f_index = 0;
        if (index_IC == 0) {
            index_IC = 1;
            frmID = 1;
        }
    }

    if (key_set) {//���˵�/�Ӳ˵��л�
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
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //��������   

    LCD_DrawRect(0, 430, 800, 2, YELLOW); //�ײ�����
    LCD_DrawImage1BPP(130, 130, BMP_MOTO, color, BLACK); //���
    LCD_DrawImage1BPP(130 + 50, 130, BMP_STSTEM, color, BLACK); //ϵͳ
    LCD_DrawImage1BPP(130 + 50 + 50, 130, BMP_Message, color, BLACK); //��Ϣ

    LCD_DrawImage1BPP(130, 130 + 35, BMP_CAR, color, BLACK); //����
    LCD_DrawImage1BPP(130 + 50, 130 + 35, BMP_STSTEM, color, BLACK); //ϵͳ
    LCD_DrawImage1BPP(130 + 50 + 50, 130 + 35, BMP_Message, color, BLACK); //��Ϣ

    LCD_DrawImage1BPP(130, 130 + 35 + 35, BMP_Gaoya, color, BLACK); //DCDC
    LCD_DrawImage1BPP(130 + 50, 130 + 35 + 35, BMP_STSTEM, color, BLACK); //ϵͳ
    LCD_DrawImage1BPP(130 + 50 + 50, 130 + 35 + 35, BMP_Message, color, BLACK); //��Ϣ

    LCD_DrawImage1BPP(130, 130 + 35 + 35 + 35, BMP_GUZHANG, color, BLACK); //����
    LCD_DrawImage1BPP(130 + 50, 130 + 35 + 35 + 35, BMP_STSTEM, color, BLACK); //ϵͳ
    LCD_DrawImage1BPP(130 + 50 + 50, 130 + 35 + 35 + 35, BMP_Message, color, BLACK); //��Ϣ

    LCD_DrawImage1BPP(130 + 350, 130, BMP_Battery, color, BLACK); //���
    LCD_DrawImage1BPP(130 + 350 + 50, 130, BMP_Manage, color, BLACK); //����
    LCD_DrawImage1BPP(130 + 350 + 50 + 50, 130, BMP_STSTEM, color, BLACK); //ϵͳ
    LCD_DrawImage1BPP(130 + 350 + 50 + 50 + 50, 130, BMP_Message, color, BLACK); //��Ϣ

    LCD_DrawImage1BPP(130 + 350, 130 + 35, BMP_Battery, color, BLACK); //���   
    LCD_DrawImage1BPP(130 + 350 + 50, 130 + 35, BMP_Message, color, BLACK); //��Ϣ 

    LCD_DrawImage1BPP(130 + 350, 130 + 35 + 35, BMP_IC, color, BLACK); //�Ǳ�
    LCD_DrawImage1BPP(130 + 50 + 350, 130 + 35 + 35, BMP_STSTEM, color, BLACK); //ϵͳ
    LCD_DrawImage1BPP(130 + 50 + 50 + 350, 130 + 35 + 35, BMP_Message, color, BLACK); //��Ϣ

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

    if (i == 14) i = 7;
    if (i == 0) i = 7;
    //�Ӳ˵����л�
    if (i == 7) {
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
    if (i == 8 || i == 1) {
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
    if (i == 9 || i == 2) {
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
    if (i == 10 || i == 3) {
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
    if (i == 11 || i == 4) {
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
    if (i == 12 || i == 5) {
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
    if (i == 13 || i == 6) {
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
        disp_CAN_baojing(2, 440);
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
            frmID = 10;
        }
    }
}

/******************************************************/

void MOTOFrame(void) {
    unsigned char i = 0;
    LCD_Clear();
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //��������
    LCD_DrawImage1BPP(130 + 200, 130 - 85, BMP_MOTO, WHITE, BLACK); //���
    LCD_DrawImage1BPP(130 + 200 + 50, 130 - 85, BMP_STSTEM, WHITE, BLACK); //ϵͳ
    LCD_DrawImage1BPP(130 + 200 + 50 + 50, 130 - 85, BMP_Message, WHITE, BLACK); //��Ϣ

    LCD_DrawRect(80, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320 + 320, 90, 1, 380, GREEN);
    for (i = 0; i < 11; i++)
        LCD_DrawRect(80, 90 + i * 38, 640, 1, GREEN);

    LCD_DrawImage1BPP(82, 100 + 38 * 0, BMP_DJ, WHITE, BLACK); //���
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 0, BMP_Zhuangtai, WHITE, BLACK); //״̬

    LCD_DrawImage1BPP(82, 100 + 38 * 1, BMP_DJ, WHITE, BLACK); //���
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 1, BMP_KZQ, WHITE, BLACK); //������
    LCD_DrawImage1BPP(82 + 42 + 63, 100 + 38 * 1, BMP_Wendu, WHITE, BLACK); //�¶�
    LCD_DrawImage1BPP(400 - 28, 100 + 38 * 1, BMP_T, WHITE, BLACK); //��

    LCD_DrawImage1BPP(82, 100 + 38 * 2, BMP_DJ, WHITE, BLACK); //���
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 2, BMP_KZQ, WHITE, BLACK); //������
    LCD_DrawImage1BPP(82 + 63 + 42, 100 + 38 * 2, BMP_Input, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 63 + 42 + 42, 100 + 38 * 2, BMP_DY, WHITE, BLACK); //��ѹ
    LCD_DrawImage1BPP(400 - 24, 100 + 38 * 2, BMP_v, WHITE, BLACK); //V

    LCD_DrawImage1BPP(82, 100 + 38 * 3, BMP_DJ, WHITE, BLACK); //���
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 3, BMP_Zhiliu, WHITE, BLACK); //ֱ��
    LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 3, BMP_DL, WHITE, BLACK); //����
    LCD_DrawImage1BPP(400 - 24, 100 + 38 * 3, BMP_a, WHITE, BLACK); //A

    LCD_DrawImage1BPP(82, 100 + 38 * 4, BMP_DJ, WHITE, BLACK); //���
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 4, BMP_Wendu, WHITE, BLACK); //�¶�
    LCD_DrawImage1BPP(400 - 28, 100 + 38 * 4, BMP_T, WHITE, BLACK); //��

    LCD_DrawImage1BPP(82, 100 + 38 * 5, BMP_DJ, WHITE, BLACK); //���
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 5, BMP_Zhuansu, WHITE, BLACK); //ת��
    LCD_DrawImage1BPP(400 - 24 - 24, 100 + 38 * 5, BMP_RPM, WHITE, BLACK); //RPM

    LCD_DrawImage1BPP(82, 100 + 38 * 6, BMP_DJ, WHITE, BLACK); //���
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 6, BMP_Zhuanju, WHITE, BLACK); //ת��
    LCD_DrawImage1BPP(400 - 24 - 11, 100 + 38 * 6, BMP_n, WHITE, BLACK); //NM
    LCD_DrawImage1BPP(400 - 24, 100 + 38 * 6, BMP_m, WHITE, BLACK); //

    LCD_DrawImage1BPP(82, 100 + 38 * 7, BMP_DJ, WHITE, BLACK); //���
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 7, BMP_Gonglv, WHITE, BLACK); //����
    LCD_DrawImage1BPP(400 - 24 - 11, 100 + 38 * 7, BMP_k, WHITE, BLACK); //KW
    LCD_DrawImage1BPP(400 - 24, 100 + 38 * 7, BMP_w, WHITE, BLACK); //



    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 0, BMP_DJ, WHITE, BLACK); //���
    LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 0, BMP_KZQ, WHITE, BLACK); //������
    LCD_DrawImage1BPP(82 + 320 + 42 + 63, 100 + 38 * 0, BMP_Guo, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 320 + 42 + 63 + 21, 100 + 38 * 0, BMP_Yali, WHITE, BLACK); //ѹ
    LCD_DrawImage1BPP(82 + 320 + 42 + 63 + 42, 100 + 38 * 0, BMP_Baojing, WHITE, BLACK); //����

    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 1, BMP_DJ, WHITE, BLACK); //���
    LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 1, BMP_KZQ, WHITE, BLACK); //������
    LCD_DrawImage1BPP(82 + 320 + 42 + 63, 100 + 38 * 1, BMP_Qian, WHITE, BLACK); //Ƿ
    LCD_DrawImage1BPP(82 + 320 + 42 + 63 + 21, 100 + 38 * 1, BMP_Yali, WHITE, BLACK); //ѹ
    LCD_DrawImage1BPP(82 + 320 + 42 + 63 + 42, 100 + 38 * 1, BMP_Baojing, WHITE, BLACK); //����

    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 2, BMP_DJ, WHITE, BLACK); //���
    LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 2, BMP_KZQ, WHITE, BLACK); //������
    LCD_DrawImage1BPP(82 + 320 + 42 + 63, 100 + 38 * 2, BMP_Guo, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 320 + 42 + 63 + 21, 100 + 38 * 2, BMP_Zai, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 320 + 42 + 63 + 42, 100 + 38 * 2, BMP_Baojing, WHITE, BLACK); //����

    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 3, BMP_DJ, WHITE, BLACK); //���
    LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 3, BMP_KZQ, WHITE, BLACK); //������
    LCD_DrawImage1BPP(82 + 320 + 42 + 63, 100 + 38 * 3, BMP_Wendu, WHITE, BLACK); //�¶�
    LCD_DrawImage1BPP(82 + 320 + 42 + 63 + 42, 100 + 38 * 3, BMP_Baojing, WHITE, BLACK); //����

    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 4, BMP_DJ, WHITE, BLACK); //���
    LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 4, BMP_Wendu, WHITE, BLACK); //�¶�
    LCD_DrawImage1BPP(82 + 320 + 42 + 42, 100 + 38 * 4, BMP_Baojing, WHITE, BLACK); //����

    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 5, BMP_c, WHITE, BLACK); //CANͨѶ����
    LCD_DrawImage1BPP(82 + 320 + 11, 100 + 38 * 5, BMP_a, WHITE, BLACK);
    LCD_DrawImage1BPP(82 + 320 + 11 + 11, 100 + 38 * 5, BMP_n, WHITE, BLACK);
    LCD_DrawImage1BPP(82 + 320 + 11 + 11 + 11, 100 + 38 * 5, BMP_Tongxin, WHITE, BLACK);
    LCD_DrawImage1BPP(82 + 320 + 11 + 11 + 11 + 42, 100 + 38 * 5, BMP_Baojing, WHITE, BLACK); //����

    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 6, BMP_m, WHITE, BLACK); //MCU����״̬
    LCD_DrawImage1BPP(82 + 320 + 11, 100 + 38 * 6, BMP_c, WHITE, BLACK);
    LCD_DrawImage1BPP(82 + 320 + 11 + 11, 100 + 38 * 6, BMP_u, WHITE, BLACK);
    LCD_DrawImage1BPP(82 + 320 + 11 + 11 + 11, 100 + 38 * 6, BMP_Guzhang, WHITE, BLACK);
    LCD_DrawImage1BPP(82 + 320 + 11 + 11 + 11 + 42, 100 + 38 * 6, BMP_Zhuangtai, WHITE, BLACK);
}

void MOTOUpdate(void) {
    print_SZ_1(82 + 200 + 20 + 16, 100 - 8, MCU_Status, 2, 0, WHITE);
    updata_DAT(82 + 200 + 20 + 0, 100 - 8 + 38 * 1, MCU_Controller_Temp, 1, 40, WHITE, 3, 0);
    print_SZ_1(82 + 200 + 20 - 16, 100 - 8 + 38 * 2, MCU_Voltage * 0.1, 4, 0, WHITE);
    updata_DAT(82 + 200 + 20 - 16, 100 - 8 + 38 * 3, MCU_Current * 0.1, 1, 1000, WHITE, 4, 0);
    updata_DAT(82 + 200 + 20 + 0, 100 - 8 + 38 * 4, MCU_Temp, 1, 40, WHITE, 3, 0);
    updata_DAT(82 + 200 + 20 - 32, 100 - 8 + 38 * 5, MCU_RPM, 1, 20000, WHITE, 5, 0);
    updata_DAT(82 + 200 + 20 - 16, 100 - 8 + 38 * 6, MCU_NM, 0.1, 2000, WHITE, 4, 0);
    updata_DAT(82 + 200 + 20 + 0, 100 - 8 + 38 * 7, MCU_Power, 1, 200, WHITE, 3, 0);

    //print_SZ_1(82 + 200 + 300 + 50, 100 - 8, MCU_OverVoltage, 1, 0, WHITE);
    if (MCU_OverVoltage)
        LCD_DrawImage1BPP(82 + 200 + 350, 100 + 38 * 0, BMP_Baojing, RED, BLACK); //����
    else LCD_DrawImage1BPP(82 + 200 + 350, 100 + 38 * 0, BMP_Zhengchang, GREEN, BLACK); //����

    if (MCU_UnderVoltage)
        LCD_DrawImage1BPP(82 + 200 + 350, 100 + 38 * 1, BMP_Baojing, RED, BLACK); //����
    else LCD_DrawImage1BPP(82 + 200 + 350, 100 + 38 * 1, BMP_Zhengchang, GREEN, BLACK); //����

    if (MCU_OverCurrent)
        LCD_DrawImage1BPP(82 + 200 + 350, 100 + 38 * 2, BMP_Baojing, RED, BLACK); //����
    else LCD_DrawImage1BPP(82 + 200 + 350, 100 + 38 * 2, BMP_Zhengchang, GREEN, BLACK); //����

    if (MCU_Con_OverTemp)
        LCD_DrawImage1BPP(82 + 200 + 350, 100 + 38 * 3, BMP_Baojing, RED, BLACK); //����
    else LCD_DrawImage1BPP(82 + 200 + 350, 100 + 38 * 3, BMP_Zhengchang, GREEN, BLACK); //����

    if (MCU_OverTemp)
        LCD_DrawImage1BPP(82 + 200 + 350, 100 + 38 * 4, BMP_Baojing, RED, BLACK); //����
    else LCD_DrawImage1BPP(82 + 200 + 350, 100 + 38 * 4, BMP_Zhengchang, GREEN, BLACK); //����

    if (MCU_CAN_Warn)
        LCD_DrawImage1BPP(82 + 200 + 350, 100 + 38 * 5, BMP_Baojing, RED, BLACK); //����
    else LCD_DrawImage1BPP(82 + 200 + 350, 100 + 38 * 5, BMP_Zhengchang, GREEN, BLACK); //����

    if (MCU_Fault)
        LCD_DrawImage1BPP(82 + 200 + 350, 100 + 38 * 6, BMP_Baojing, RED, BLACK); //����
    else LCD_DrawImage1BPP(82 + 200 + 350, 100 + 38 * 6, BMP_Zhengchang, GREEN, BLACK); //����
}

void frmMOTO(void) {
    if (f_index == 0) { //ֻ����һ��
        f_index = 1;
        MOTOFrame();
    } else if (f_index == 1) {
        f_index = 1;
        MOTOUpdate();
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

void CARFrame(void) {
    unsigned char i = 0;
    LCD_Clear();
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //��������
    LCD_DrawImage1BPP(130 + 200 - 15, 130 - 85, BMP_CAR, WHITE, BLACK); //����
    LCD_DrawImage1BPP(130 + 200 + 50 - 15, 130 - 85, BMP_STSTEM, WHITE, BLACK); //ϵͳ
    LCD_DrawImage1BPP(130 + 200 + 50 + 50 - 15, 130 - 85, BMP_Message, WHITE, BLACK); //��Ϣ

    LCD_DrawRect(80, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320 + 320, 90, 1, 380, GREEN);
    for (i = 0; i < 11; i++)
        LCD_DrawRect(80, 90 + i * 38, 640, 1, GREEN);

    LCD_DrawImage1BPP(82, 100 + 38 * 0, BMP_b, WHITE, BLACK); //BMS�Ӵ���״̬
    LCD_DrawImage1BPP(82 + 11, 100 + 38 * 0, BMP_m, WHITE, BLACK);
    LCD_DrawImage1BPP(82 + 11 + 11, 100 + 38 * 0, BMP_s, WHITE, BLACK);
    LCD_DrawImage1BPP(82 + 11 + 11 + 11, 100 + 38 * 0, BMP_Jiechuqi, WHITE, BLACK);
    LCD_DrawImage1BPP(82 + 11 + 11 + 11 + 42, 100 + 38 * 0, BMP_Zhuangtai, WHITE, BLACK);

    LCD_DrawImage1BPP(82, 100 + 38 * 1, BMP_Chushuang, WHITE, BLACK); //��˪ʹ��
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 1, BMP_Shineng, WHITE, BLACK);

    LCD_DrawImage1BPP(82, 100 + 38 * 2, BMP_Kongtiao, WHITE, BLACK); //�յ�ʹ��
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 2, BMP_Shineng, WHITE, BLACK);

    LCD_DrawImage1BPP(82, 100 + 38 * 3, BMP_Sanheyi, WHITE, BLACK); //����һʹ��
    LCD_DrawImage1BPP(82 + 63, 100 + 38 * 3, BMP_Shineng, WHITE, BLACK);

    LCD_DrawImage1BPP(82, 100 + 38 * 4, BMP_Life, WHITE, BLACK); //Life�ź�
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 4, BMP_Xinhao, WHITE, BLACK);

    LCD_DrawImage1BPP(82, 100 + 38 * 5, BMP_Chong, WHITE, BLACK); //���״̬
    LCD_DrawImage1BPP(82 + 21, 100 + 38 * 5, BMP_DC, WHITE, BLACK);
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 5, BMP_Zhuangtai, WHITE, BLACK);


    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 0, BMP_Youmen, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 42 + 320, 100 + 38 * 0, BMP_Taban, WHITE, BLACK); //̤��
    LCD_DrawImage1BPP(720 - 24, 100 + 38 * 0, BMP_Baifenhao, WHITE, BLACK); //%

    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 1, BMP_Zhidong, WHITE, BLACK); //�ƶ�
    LCD_DrawImage1BPP(82 + 42 + 320, 100 + 38 * 1, BMP_Taban, WHITE, BLACK); //̤��
    LCD_DrawImage1BPP(720 - 24, 100 + 38 * 1, BMP_Baifenhao, WHITE, BLACK); //%

    //פ���ƶ��ź�
    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 2, BMP_Zhuche, WHITE, BLACK);
    LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 2, BMP_Zhidong, WHITE, BLACK);
    LCD_DrawImage1BPP(82 + 320 + 84, 100 + 38 * 2, BMP_Xinhao, WHITE, BLACK);

    //�ƶ��ź�
    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 3, BMP_Zhidong, WHITE, BLACK);
    LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 3, BMP_Xinhao, WHITE, BLACK);

    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 4, BMP_DC, WHITE, BLACK); //���״̬
    LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 4, BMP_Zhuangtai, WHITE, BLACK);

    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 5, BMP_DJ, WHITE, BLACK); //���״̬
    LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 5, BMP_Zhuangtai, WHITE, BLACK);



    /*LCD_DrawImage1BPP(82, 100 - 2, BMP_DCAC, WHITE, BLACK); //DCAC
    LCD_DrawImage1BPP(82 + 52 + 11, 100, BMP_w, WHITE, BLACK); //  W
    LCD_DrawImage1BPP(82 + 52 + 11 + 11, 100, BMP_Xiang, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 52 + 11 + 11 + 21, 100, BMP_Output, WHITE, BLACK); //���
    LCD_DrawImage1BPP(82 + 52 + 11 + 11 + 21 + 42, 100, BMP_DL, WHITE, BLACK); //����
    LCD_DrawImage1BPP(400 - 24, 100, BMP_a, WHITE, BLACK); //A

    LCD_DrawImage1BPP(82, 100 - 2 + 38, BMP_DCAC, WHITE, BLACK); //DCAC
    LCD_DrawImage1BPP(82 + 52 + 11, 100 + 38, BMP_w, WHITE, BLACK); //  W
    LCD_DrawImage1BPP(82 + 52 + 11 + 11, 100 + 38, BMP_Xiang, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 52 + 11 + 11 + 21, 100 + 38, BMP_Output, WHITE, BLACK); //���
    LCD_DrawImage1BPP(82 + 52 + 11 + 11 + 21 + 42, 100 + 38, BMP_DY, WHITE, BLACK); //��ѹ
    LCD_DrawImage1BPP(400 - 24, 100 + 38, BMP_v, WHITE, BLACK); //V

    LCD_DrawImage1BPP(82, 100 - 2 + 38 * 2, BMP_DCAC, WHITE, BLACK); //DCAC
    LCD_DrawImage1BPP(82 + 52 + 11, 100 + 38 * 2, BMP_v, WHITE, BLACK); //  V
    LCD_DrawImage1BPP(82 + 52 + 11 + 11, 100 + 38 * 2, BMP_Xiang, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 52 + 11 + 11 + 21, 100 + 38 * 2, BMP_Output, WHITE, BLACK); //���
    LCD_DrawImage1BPP(82 + 52 + 11 + 11 + 21 + 42, 100 + 38 * 2, BMP_DL, WHITE, BLACK); //����
    LCD_DrawImage1BPP(400 - 24, 100 + 38 * 2, BMP_a, WHITE, BLACK); //A

    LCD_DrawImage1BPP(82, 100 - 2 + 38 * 3, BMP_DCAC, WHITE, BLACK); //DCAC
    LCD_DrawImage1BPP(82 + 52 + 11, 100 + 38 * 3, BMP_v, WHITE, BLACK); //  V
    LCD_DrawImage1BPP(82 + 52 + 11 + 11, 100 + 38 * 3, BMP_Xiang, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 52 + 11 + 11 + 21, 100 + 38 * 3, BMP_Output, WHITE, BLACK); //���
    LCD_DrawImage1BPP(82 + 52 + 11 + 11 + 21 + 42, 100 + 38 * 3, BMP_DY, WHITE, BLACK); //��ѹ
    LCD_DrawImage1BPP(400 - 24, 100 + 38 * 3, BMP_v, WHITE, BLACK); //V

    LCD_DrawImage1BPP(82, 100 - 2 + 38 * 4, BMP_DCAC, WHITE, BLACK); //DCAC
    LCD_DrawImage1BPP(82 + 52 + 11, 100 + 38 * 4, BMP_u, WHITE, BLACK); //  U
    LCD_DrawImage1BPP(82 + 52 + 11 + 11, 100 + 38 * 4, BMP_Xiang, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 52 + 11 + 11 + 21, 100 + 38 * 4, BMP_Output, WHITE, BLACK); //���
    LCD_DrawImage1BPP(82 + 52 + 11 + 11 + 21 + 42, 100 + 38 * 4, BMP_DL, WHITE, BLACK); //����
    LCD_DrawImage1BPP(400 - 24, 100 + 38 * 4, BMP_a, WHITE, BLACK); //A

    LCD_DrawImage1BPP(82, 100 - 2 + 38 * 5, BMP_DCAC, WHITE, BLACK); //DCAC
    LCD_DrawImage1BPP(82 + 52 + 11, 100 + 38 * 5, BMP_u, WHITE, BLACK); //  U
    LCD_DrawImage1BPP(82 + 52 + 11 + 11, 100 + 38 * 5, BMP_Xiang, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 52 + 11 + 11 + 21, 100 + 38 * 5, BMP_Output, WHITE, BLACK); //���
    LCD_DrawImage1BPP(82 + 52 + 11 + 11 + 21 + 42, 100 + 38 * 5, BMP_DY, WHITE, BLACK); //��ѹ
    LCD_DrawImage1BPP(400 - 24, 100 + 38 * 5, BMP_v, WHITE, BLACK); //V

    LCD_DrawImage1BPP(82 + 320, 100, BMP_KZQ, WHITE, BLACK); //������
    LCD_DrawImage1BPP(82 + 320 + 63, 100, BMP_Wendu, WHITE, BLACK); //�¶�
    LCD_DrawImage1BPP(720 - 24, 100, BMP_T, WHITE, BLACK); //��

    LCD_DrawImage1BPP(82 + 320, 100 + 38, BMP_Guzhang, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 42 + 320, 100 + 38, BMP_Code, WHITE, BLACK); //����

    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 2, BMP_Guzhang, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 42 + 320, 100 + 38 * 2, BMP_Dengji, WHITE, BLACK); //�ȼ�

    LCD_DrawImage1BPP(82 + 320, 100 - 2 + 38 * 3, BMP_DCAC, WHITE, BLACK); //DCAC
    LCD_DrawImage1BPP(82 + 320 + 52, 100 + 2 + 38 * 3, BMP_Input, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 320 + 52 + 42, 100 + 2 + 38 * 3, BMP_Qieduan, WHITE, BLACK); //�ж�

    LCD_DrawImage1BPP(82 + 320, 100 - 2 + 38 * 4, BMP_DCAC, WHITE, BLACK); //DCAC
    LCD_DrawImage1BPP(82 + 320 + 52, 100 + 2 + 38 * 4, BMP_Output, WHITE, BLACK); //���
    LCD_DrawImage1BPP(82 + 320 + 52 + 42, 100 + 2 + 38 * 4, BMP_Qieduan, WHITE, BLACK); //�ж�

    LCD_DrawImage1BPP(82 + 320, 100 - 2 + 38 * 5, BMP_DCAC, WHITE, BLACK); //DCAC
    LCD_DrawImage1BPP(82 + 320 + 52, 100 + 2 + 38 * 5, BMP_Gongzuo, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 320 + 52 + 42, 100 + 2 + 38 * 5, BMP_Zhuangtai, WHITE, BLACK); //״̬

    LCD_DrawImage1BPP(82 + 320, 100 - 2 + 38 * 6, BMP_DCAC, WHITE, BLACK); //DCAC�¶ȱ���
    LCD_DrawImage1BPP(82 + 320 + 52, 100 - 2 + 38 * 6, BMP_Wendu, WHITE, BLACK);
    LCD_DrawImage1BPP(82 + 320 + 52 + 42, 100 - 2 + 38 * 6, BMP_Baojing, WHITE, BLACK);

    LCD_DrawImage1BPP(82 + 320, 100 - 2 + 38 * 7, BMP_DCAC, WHITE, BLACK); //DCAC�¶ȱ���
    LCD_DrawImage1BPP(82 + 320 + 52, 100 - 2 + 38 * 7, BMP_Guzhang, WHITE, BLACK);
    LCD_DrawImage1BPP(82 + 320 + 52 + 42, 100 - 2 + 38 * 7, BMP_Zhuangtai, WHITE, BLACK);
     */
}

void CARUpdate(void) {
    if (BMS_Connecter == 0) {
        LCD_DrawImage1BPP(82 + 200, 100 + 38 * 0, BMP_Kai, GREEN, BLACK); //��
        LCD_DrawRect(82 + 200 + 21, 100 + 38 * 0, 21, 20, BLACK);
    } else if (BMS_Connecter == 1) {
        LCD_DrawImage1BPP(82 + 200, 100 + 38 * 0, BMP_Guan, WHITE, BLACK); //��
        LCD_DrawRect(82 + 200 + 21, 100 + 38 * 0, 21, 20, BLACK);
    } else if (BMS_Connecter == 2)
        LCD_DrawImage1BPP(82 + 200, 100 + 38 * 0, BMP_Guzhang, RED, BLACK); //����

    if (Defrost_EN == 1) {
        LCD_DrawImage1BPP(82 + 200, 100 + 38 * 1, BMP_Kai, GREEN, BLACK); //��
        LCD_DrawRect(82 + 200 + 21, 100 + 38 * 1, 21, 20, BLACK);
    } else if (Defrost_EN == 0) {
        LCD_DrawImage1BPP(82 + 200, 100 + 38 * 1, BMP_Guan, WHITE, BLACK); //��
        LCD_DrawRect(82 + 200 + 21, 100 + 38 * 1, 21, 20, BLACK);
    }

    if (Air_EN == 1) {
        LCD_DrawImage1BPP(82 + 200, 100 + 38 * 2, BMP_Kai, GREEN, BLACK); //��
        LCD_DrawRect(82 + 200 + 21, 100 + 38 * 2, 21, 20, BLACK);
    } else if (Air_EN == 0) {
        LCD_DrawImage1BPP(82 + 200, 100 + 38 * 2, BMP_Guan, WHITE, BLACK); //��
        LCD_DrawRect(82 + 200 + 21, 100 + 38 * 2, 21, 20, BLACK);
    }

    if (Theree_EN == 1) {
        LCD_DrawImage1BPP(82 + 200, 100 + 38 * 3, BMP_Kai, GREEN, BLACK); //��
        LCD_DrawRect(82 + 200 + 21, 100 + 38 * 3, 21, 20, BLACK);
    } else if (Theree_EN == 0) {
        LCD_DrawImage1BPP(82 + 200, 100 + 38 * 3, BMP_Guan, WHITE, BLACK); //��
        LCD_DrawRect(82 + 200 + 21, 100 + 38 * 3, 21, 20, BLACK);
    }

    print_SZ_1(82 + 200 + 20 - 16, 100 - 8 + 38 * 4, VCU_LIFE, 3, 0, WHITE);

    if (VCU_Charge == 0) {
        LCD_DrawImage1BPP(82 + 200, 100 + 38 * 5, BMP_Wei, WHITE, BLACK); //δ���
        LCD_DrawImage1BPP(82 + 200 + 21, 100 + 38 * 5, BMP_Chong, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 200 + 42, 100 + 38 * 5, BMP_Dian, WHITE, BLACK);
    } else if (VCU_Charge == 1 || VCU_Charge == 2) {
        LCD_DrawImage1BPP(82 + 200, 100 + 38 * 5, BMP_Chong, GREEN, BLACK); //���
        LCD_DrawImage1BPP(82 + 200 + 21, 100 + 38 * 5, BMP_Dian, GREEN, BLACK);
        LCD_DrawRect(82 + 200 + 42, 100 + 38 * 5, 42, 20, BLACK);
    }/*else if(VCU_Charge == 2){
        LCD_DrawImage1BPP(82 + 200, 100 + 38 * 5, BMP_Tingzhi, GREEN, BLACK);//ͣ�����
        LCD_DrawImage1BPP(82 + 200 + 21, 100 + 38 * 5, BMP_Chesu, GREEN, BLACK);
        LCD_DrawImage1BPP(82 + 200 + 42, 100 + 38 * 5, BMP_Chong, GREEN, BLACK);
        LCD_DrawImage1BPP(82 + 200 + 42 + 21, 100 + 38 * 5, BMP_Dian, GREEN, BLACK);
    }*/

    print_SZ_1(82 + 200 + 300 + 16, 100 - 8 + 38 * 0, VCU_Speed_percent * 0.4, 3, 0, WHITE);
    print_SZ_1(82 + 200 + 300 + 16, 100 - 8 + 38 * 1, VCU_Brake_percent * 0.4, 3, 0, WHITE);
    print_SZ_1(82 + 200 + 300 + 32, 100 - 8 + 38 * 2, Hand_Brake, 2, 0, WHITE);
    print_SZ_1(82 + 200 + 300 + 32, 100 - 8 + 38 * 3, Foot_Brake, 2, 0, WHITE);

    if (BAT_OFFINE == 1) {
        LCD_DrawImage1BPP(82 + 200 + 300 + 11 * 0, 100 + 38 * 4, BMP_o, RED, BLACK); //
        LCD_DrawImage1BPP(82 + 200 + 300 + 11 * 1, 100 + 38 * 4, BMP_f, RED, BLACK);
        LCD_DrawImage1BPP(82 + 200 + 300 + 11 * 2, 100 + 38 * 4, BMP_f, RED, BLACK);
        LCD_DrawImage1BPP(82 + 200 + 300 + 11 * 3, 100 + 38 * 4, BMP_l, RED, BLACK); //
        LCD_DrawImage1BPP(82 + 200 + 300 + 11 * 4, 100 + 38 * 4, BMP_i, RED, BLACK);
        LCD_DrawImage1BPP(82 + 200 + 300 + 11 * 5, 100 + 38 * 4, BMP_n, RED, BLACK);
        LCD_DrawImage1BPP(82 + 200 + 300 + 11 * 6, 100 + 38 * 4, BMP_e, RED, BLACK);
    } else if (BAT_OFFINE == 3) {
        LCD_DrawImage1BPP(82 + 200 + 300 + 11 * 0, 100 + 38 * 4, BMP_o, BLACK, BLACK); //
        LCD_DrawImage1BPP(82 + 200 + 300 + 11 * 1, 100 + 38 * 4, BMP_o, GREEN, BLACK);
        LCD_DrawImage1BPP(82 + 200 + 300 + 11 * 2, 100 + 38 * 4, BMP_n, GREEN, BLACK);
        LCD_DrawImage1BPP(82 + 200 + 300 + 11 * 3, 100 + 38 * 4, BMP_l, GREEN, BLACK); //
        LCD_DrawImage1BPP(82 + 200 + 300 + 11 * 4, 100 + 38 * 4, BMP_i, GREEN, BLACK);
        LCD_DrawImage1BPP(82 + 200 + 300 + 11 * 5, 100 + 38 * 4, BMP_n, GREEN, BLACK);
        LCD_DrawImage1BPP(82 + 200 + 300 + 11 * 6, 100 + 38 * 4, BMP_e, GREEN, BLACK);
    }

    if (MCU_OFFINE == 1) {
        LCD_DrawImage1BPP(82 + 200 + 300 + 11 * 0, 100 + 38 * 5, BMP_o, RED, BLACK); //
        LCD_DrawImage1BPP(82 + 200 + 300 + 11 * 1, 100 + 38 * 5, BMP_f, RED, BLACK);
        LCD_DrawImage1BPP(82 + 200 + 300 + 11 * 2, 100 + 38 * 5, BMP_f, RED, BLACK);
        LCD_DrawImage1BPP(82 + 200 + 300 + 11 * 3, 100 + 38 * 5, BMP_l, RED, BLACK); //
        LCD_DrawImage1BPP(82 + 200 + 300 + 11 * 4, 100 + 38 * 5, BMP_i, RED, BLACK);
        LCD_DrawImage1BPP(82 + 200 + 300 + 11 * 5, 100 + 38 * 5, BMP_n, RED, BLACK);
        LCD_DrawImage1BPP(82 + 200 + 300 + 11 * 6, 100 + 38 * 5, BMP_e, RED, BLACK);
    } else if (MCU_OFFINE == 3) {
        LCD_DrawImage1BPP(82 + 200 + 300 + 11 * 0, 100 + 38 * 5, BMP_o, BLACK, BLACK); //
        LCD_DrawImage1BPP(82 + 200 + 300 + 11 * 1, 100 + 38 * 5, BMP_o, GREEN, BLACK);
        LCD_DrawImage1BPP(82 + 200 + 300 + 11 * 2, 100 + 38 * 5, BMP_n, GREEN, BLACK);
        LCD_DrawImage1BPP(82 + 200 + 300 + 11 * 3, 100 + 38 * 5, BMP_l, GREEN, BLACK); //
        LCD_DrawImage1BPP(82 + 200 + 300 + 11 * 4, 100 + 38 * 5, BMP_i, GREEN, BLACK);
        LCD_DrawImage1BPP(82 + 200 + 300 + 11 * 5, 100 + 38 * 5, BMP_n, GREEN, BLACK);
        LCD_DrawImage1BPP(82 + 200 + 300 + 11 * 6, 100 + 38 * 5, BMP_e, GREEN, BLACK);
    }
}

void frmCAR(void) {
    if (f_index == 0) { //ֻ����һ��
        f_index = 1;
        CARFrame();
    } else if (f_index == 1) {
        f_index = 1;
        CARUpdate();
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
void DCDCFrame(unsigned char index) {
    unsigned char i = 0;
    LCD_Clear();
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //��������
    LCD_DrawImage1BPP(130 + 200, 130 - 85, BMP_Gaoya, WHITE, BLACK); //DCDC
    LCD_DrawImage1BPP(130 + 200 + 50, 130 - 85, BMP_STSTEM, WHITE, BLACK); //ϵͳ
    LCD_DrawImage1BPP(130 + 200 + 50 + 50, 130 - 85, BMP_Message, WHITE, BLACK); //��Ϣ

    LCD_DrawRect(80, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320 + 320, 90, 1, 380, GREEN);
    for (i = 0; i < 11; i++)
        LCD_DrawRect(80, 90 + i * 38, 640, 1, GREEN);

    if (index == 1) {
        print_SZ_2(750, 50, 1, 1, 0, WHITE); // 1/3
        LCD_DrawImage1BPP(750 + 11, 50, BMP_I, WHITE, BLACK);
        print_SZ_2(750 + 11 + 14, 50, 3, 1, 0, WHITE);

        LCD_DrawImage1BPP(130 + 200, 130 - 85, BMP_DCDC, WHITE, BLACK); //DCDC
        LCD_DrawImage1BPP(130 + 200 + 65, 130 - 85, BMP_STSTEM, WHITE, BLACK); //ϵͳ
        LCD_DrawImage1BPP(130 + 200 + 65 + 50, 130 - 85, BMP_Message, WHITE, BLACK); //��Ϣ

        LCD_DrawImage1BPP(82, 100 - 4, BMP_DCDC, WHITE, BLACK); //DCDC
        LCD_DrawImage1BPP(82 + 65, 100 - 2, BMP_Zhuangtai, WHITE, BLACK); //״̬

        LCD_DrawImage1BPP(82, 100 - 4 + 38, BMP_DCDC, WHITE, BLACK); //DCDC
        LCD_DrawImage1BPP(82 + 65, 100 - 2 + 38, BMP_Input, WHITE, BLACK); //����
        LCD_DrawImage1BPP(82 + 65 + 42, 100 - 2 + 38, BMP_DY, WHITE, BLACK); //��ѹ
        LCD_DrawImage1BPP(400 - 24, 100 - 2 + 38, BMP_v, WHITE, BLACK); //V

        LCD_DrawImage1BPP(82, 100 - 4 + 38 * 2, BMP_DCDC, WHITE, BLACK); //DCDC
        LCD_DrawImage1BPP(82 + 65, 100 - 2 + 38 * 2, BMP_Output, WHITE, BLACK); //���
        LCD_DrawImage1BPP(82 + 65 + 42, 100 - 2 + 38 * 2, BMP_DY, WHITE, BLACK); //��ѹ
        LCD_DrawImage1BPP(400 - 24, 100 - 2 + 38 * 2, BMP_v, WHITE, BLACK); //V

        LCD_DrawImage1BPP(82, 100 - 4 + 38 * 3, BMP_DCDC, WHITE, BLACK); //DCDC
        LCD_DrawImage1BPP(82 + 65, 100 - 2 + 38 * 3, BMP_Output, WHITE, BLACK); //���
        LCD_DrawImage1BPP(82 + 65 + 42, 100 - 2 + 38 * 3, BMP_DL, WHITE, BLACK); //����
        LCD_DrawImage1BPP(400 - 24, 100 - 2 + 38 * 3, BMP_a, WHITE, BLACK); //A

        LCD_DrawImage1BPP(82, 100 - 4 + 38 * 4, BMP_DCDC, WHITE, BLACK); //DCDC
        LCD_DrawImage1BPP(82 + 65, 100 - 2 + 38 * 4, BMP_Mokuai, WHITE, BLACK); //ģ��
        LCD_DrawImage1BPP(82 + 65 + 42, 100 - 2 + 38 * 4, BMP_Wendu, WHITE, BLACK); //�¶�
        LCD_DrawImage1BPP(400 - 28, 100 - 2 + 38 * 4, BMP_T, WHITE, BLACK); //��


        LCD_DrawImage1BPP(82 + 320, 100 - 2, BMP_Input, WHITE, BLACK); //����Ƿѹ
        LCD_DrawImage1BPP(82 + 320 + 42, 100 - 2, BMP_DY, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 320 + 42, 100 - 2, BMP_Qian, WHITE, BLACK); //

        LCD_DrawImage1BPP(82 + 320, 100 - 2 + 38, BMP_Input, WHITE, BLACK); //�����ѹ
        LCD_DrawImage1BPP(82 + 320 + 42, 100 - 2 + 38, BMP_DY, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 320 + 42, 100 - 2 + 38, BMP_Guo, WHITE, BLACK); //

        LCD_DrawImage1BPP(82 + 320, 100 - 2 + 38 * 2, BMP_Output, WHITE, BLACK); //���״̬
        LCD_DrawImage1BPP(82 + 320 + 42, 100 - 2 + 38 * 2, BMP_Zhuangtai, WHITE, BLACK); //

        LCD_DrawImage1BPP(82 + 320, 100 - 2 + 38 * 3, BMP_c, WHITE, BLACK); //CAN״̬
        LCD_DrawImage1BPP(82 + 320 + 11, 100 - 2 + 38 * 3, BMP_a, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 320 + 11 + 11, 100 - 2 + 38 * 3, BMP_n, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 320 + 11 * 3, 100 - 2 + 38 * 3, BMP_Zhuangtai, WHITE, BLACK);

        LCD_DrawImage1BPP(82 + 320, 100 - 2 + 38 * 4, BMP_Guo, WHITE, BLACK); //����
        LCD_DrawImage1BPP(82 + 320 + 21, 100 - 2 + 38 * 4, BMP_Re, WHITE, BLACK); //

        LCD_DrawImage1BPP(82 + 320, 100 - 2 + 38 * 5, BMP_Duanlu, WHITE, BLACK); //��·
    } else if (index == 2 || index == 3) {
        if (index == 2) {
            print_SZ_2(750, 50, 2, 1, 0, WHITE); // 2/3
            LCD_DrawImage1BPP(750 + 11, 50, BMP_I, WHITE, BLACK);
            print_SZ_2(750 + 11 + 14, 50, 3, 1, 0, WHITE);

            LCD_DrawImage1BPP(130 + 200, 130 - 85, BMP_DMY, WHITE, BLACK); //�ͱ�
            LCD_DrawImage1BPP(130 + 200 + 50, 130 - 85, BMP_STSTEM, WHITE, BLACK); //ϵͳ
            LCD_DrawImage1BPP(130 + 200 + 50 + 50, 130 - 85, BMP_Message, WHITE, BLACK); //��Ϣ

            LCD_DrawImage1BPP(82, 100 - 2, BMP_DCAC, WHITE, BLACK); //DCAC
            LCD_DrawImage1BPP(82 + 65, 100 + 2, BMP_Youbeng, WHITE, BLACK); //�ͱ�
            LCD_DrawImage1BPP(82 + 65 + 42, 100 + 2, BMP_Zhuangtai, WHITE, BLACK); //״̬
        } else if (index == 3) {
            print_SZ_2(750, 50, 3, 1, 0, WHITE); // 1/3
            LCD_DrawImage1BPP(750 + 11, 50, BMP_I, WHITE, BLACK);
            print_SZ_2(750 + 11 + 14, 50, 3, 1, 0, WHITE);

            LCD_DrawImage1BPP(130 + 200, 130 - 85, BMP_DMQ, WHITE, BLACK); //����
            LCD_DrawImage1BPP(130 + 200 + 50, 130 - 85, BMP_STSTEM, WHITE, BLACK); //ϵͳ
            LCD_DrawImage1BPP(130 + 200 + 50 + 50, 130 - 85, BMP_Message, WHITE, BLACK); //��Ϣ

            LCD_DrawImage1BPP(82, 100 - 2, BMP_DCAC, WHITE, BLACK); //DCAC
            LCD_DrawImage1BPP(82 + 65, 100 + 2, BMP_Qibeng, WHITE, BLACK); //�ͱ�
            LCD_DrawImage1BPP(82 + 65 + 42, 100 + 2, BMP_Zhuangtai, WHITE, BLACK); //״̬
        }

        LCD_DrawImage1BPP(82, 100 - 2 + 38, BMP_DCAC, WHITE, BLACK); //DCDC
        LCD_DrawImage1BPP(82 + 65, 100 - 2 + 38, BMP_Input, WHITE, BLACK); //����
        LCD_DrawImage1BPP(82 + 65 + 42, 100 - 2 + 38, BMP_DY, WHITE, BLACK); //��ѹ
        LCD_DrawImage1BPP(400 - 24, 100 - 2 + 38, BMP_v, WHITE, BLACK); //V

        LCD_DrawImage1BPP(82, 100 - 2 + 38 * 2, BMP_DCAC, WHITE, BLACK); //DCAC
        LCD_DrawImage1BPP(82 + 65, 100 - 2 + 38 * 2, BMP_Output, WHITE, BLACK); //���
        LCD_DrawImage1BPP(82 + 65 + 42, 100 - 2 + 38 * 2, BMP_DY, WHITE, BLACK); //��ѹ
        LCD_DrawImage1BPP(400 - 24, 100 - 2 + 38 * 2, BMP_v, WHITE, BLACK); //V

        LCD_DrawImage1BPP(82, 100 - 2 + 38 * 3, BMP_DCAC, WHITE, BLACK); //DCAC
        LCD_DrawImage1BPP(82 + 65, 100 - 2 + 38 * 3, BMP_Output, WHITE, BLACK); //���
        LCD_DrawImage1BPP(82 + 65 + 42, 100 - 2 + 38 * 3, BMP_DL, WHITE, BLACK); //����
        LCD_DrawImage1BPP(400 - 24, 100 - 2 + 38 * 3, BMP_a, WHITE, BLACK); //A

        LCD_DrawImage1BPP(82, 100 - 2 + 38 * 4, BMP_DCAC, WHITE, BLACK); //DCAC
        LCD_DrawImage1BPP(82 + 65, 100 - 2 + 38 * 4, BMP_Mokuai, WHITE, BLACK); //ģ��
        LCD_DrawImage1BPP(82 + 65 + 42, 100 - 2 + 38 * 4, BMP_Wendu, WHITE, BLACK); //�¶�
        LCD_DrawImage1BPP(400 - 28, 100 - 2 + 38 * 4, BMP_T, WHITE, BLACK); //��


        LCD_DrawImage1BPP(82 + 320, 100 - 2, BMP_Input, WHITE, BLACK); //����Ƿѹ
        LCD_DrawImage1BPP(82 + 320 + 42, 100 - 2, BMP_DY, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 320 + 42, 100 - 2, BMP_Qian, WHITE, BLACK); //

        LCD_DrawImage1BPP(82 + 320, 100 - 2 + 38, BMP_Input, WHITE, BLACK); //�����ѹ
        LCD_DrawImage1BPP(82 + 320 + 42, 100 - 2 + 38, BMP_DY, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 320 + 42, 100 - 2 + 38, BMP_Guo, WHITE, BLACK); //

        LCD_DrawImage1BPP(82 + 320, 100 - 2 + 38 * 2, BMP_Di, WHITE, BLACK); //��ѹ��Դ
        LCD_DrawImage1BPP(82 + 320 + 21, 100 - 2 + 38 * 2, BMP_Yali, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 320 + 42, 100 - 2 + 38 * 2, BMP_Dianyuan, WHITE, BLACK); //

        LCD_DrawImage1BPP(82 + 320, 100 - 2 + 38 * 3, BMP_c, WHITE, BLACK); //CAN״̬
        LCD_DrawImage1BPP(82 + 320 + 11, 100 - 2 + 38 * 3, BMP_a, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 320 + 11 + 11, 100 - 2 + 38 * 3, BMP_n, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 320 + 11 * 3, 100 - 2 + 38 * 3, BMP_Zhuangtai, WHITE, BLACK);

        LCD_DrawImage1BPP(82 + 320, 100 - 2 + 38 * 4, BMP_Guo, WHITE, BLACK); //����
        LCD_DrawImage1BPP(82 + 320 + 21, 100 - 2 + 38 * 4, BMP_Re, WHITE, BLACK); //

        LCD_DrawImage1BPP(82 + 320, 100 - 2 + 38 * 5, BMP_Duanlu, WHITE, BLACK); //��·

        LCD_DrawImage1BPP(82 + 320, 100 - 2 + 38 * 6, BMP_Guo, WHITE, BLACK); //����
        LCD_DrawImage1BPP(82 + 320 + 21, 100 - 2 + 38 * 6, BMP_Zai, WHITE, BLACK); //

        LCD_DrawImage1BPP(82 + 320, 100 - 2 + 38 * 7, BMP_Que, WHITE, BLACK); //ȱ��
        LCD_DrawImage1BPP(82 + 320 + 21, 100 - 2 + 38 * 7, BMP_Xiang, WHITE, BLACK); //
    }
}

void DCDCUpdate(unsigned char index) {
    unsigned char dump, i;
    if (index == 1) {
        if (DCDC_Status == 0) {
            LCD_DrawImage1BPP(82 + 200, 100 + 38 * 0, BMP_Tingzhi, RED, BLACK); //ֹͣ
        } else if (DCDC_Status == 1) {
            LCD_DrawImage1BPP(82 + 200, 100 + 38 * 0, BMP_Gongzuo, GREEN, BLACK); //����
        }

        print_SZ_1(82 + 200 + 20 - 16, 100 - 8 + 38, DCDC_Input_Voltage, 4, 0, WHITE);
        print_SZ_1(82 + 200 + 20, 100 - 8 + 38 * 2, DCDC_Output_Voltage, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 20 - 16, 100 - 8 + 38 * 3, DCDC_Output_Current * 0.1, 4, 0, WHITE);
        updata_DAT(82 + 200 + 20, 100 - 8 + 38 * 4, DCDC_Output_Temp, 1, 40, WHITE, 3, 0);

        dump = DCDC_Warn.byte;
        for (i = 0; i < 6; i++) {
            if ((dump & 0x01) == 1)
                LCD_DrawImage1BPP(82 + 200 + 320, 100 + 38 * i, BMP_Guzhang, RED, BLACK); //����
            else
                LCD_DrawImage1BPP(82 + 200 + 320, 100 + 38 * i, BMP_Zhengchang, GREEN, BLACK); //����
            if (i == 2)
                dump = dump >> 2;
            else
                dump = dump >> 1;
        }

    } else if (index == 2) {
        if (DCAC_OILStatus == 0) {
            LCD_DrawImage1BPP(82 + 200, 100 + 38 * 0, BMP_Tingzhi, RED, BLACK); //ֹͣ
        } else if (DCAC_OILStatus == 1) {
            LCD_DrawImage1BPP(82 + 200, 100 + 38 * 0, BMP_Gongzuo, GREEN, BLACK); //����
        }
        print_SZ_1(82 + 200 + 20 - 16, 100 - 8 + 38, DCAC_Oil_Input_Voltage, 4, 0, WHITE);
        print_SZ_1(82 + 200 + 20, 100 - 8 + 38 * 2, DCAC_Oil_Output_Voltage, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 20 - 16, 100 - 8 + 38 * 3, DCAC_Oil_Output_Current * 0.1, 4, 0, WHITE);
        updata_DAT(82 + 200 + 20, 100 - 8 + 38 * 4, DCAC_Oil_Output_Temp, 1, 40, WHITE, 3, 0);

        dump = DCAC_Oil_Warn.byte;
        for (i = 0; i < 8; i++) {
            if ((dump & 0x01) == 1)
                LCD_DrawImage1BPP(82 + 200 + 320, 100 + 38 * i, BMP_Guzhang, RED, BLACK); //����
            else
                LCD_DrawImage1BPP(82 + 200 + 320, 100 + 38 * i, BMP_Zhengchang, GREEN, BLACK); //����
            dump = dump >> 1;
        }
    } else if (index == 3) {
        if (DCAC_AIRStatus == 0) {
            LCD_DrawImage1BPP(82 + 200, 100 + 38 * 0, BMP_Tingzhi, RED, BLACK); //ֹͣ
        } else if (DCAC_AIRStatus == 1) {
            LCD_DrawImage1BPP(82 + 200, 100 + 38 * 0, BMP_Gongzuo, GREEN, BLACK); //����
        }

        print_SZ_1(82 + 200 + 20 - 16, 100 - 8 + 38, DCAC_Air_Input_Voltage, 4, 0, WHITE);
        print_SZ_1(82 + 200 + 20, 100 - 8 + 38 * 2, DCAC_Air_Output_Voltage, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 20 - 16, 100 - 8 + 38 * 3, DCAC_Air_Output_Current * 0.1, 4, 0, WHITE);
        updata_DAT(82 + 200 + 20, 100 - 8 + 38 * 4, DCAC_Air_Output_Temp, 1, 40, WHITE, 3, 0);

        dump = DCAC_Air_Warn.byte;
        for (i = 0; i < 8; i++) {
            if ((dump & 0x01) == 1)
                LCD_DrawImage1BPP(82 + 200 + 320, 100 + 38 * i, BMP_Guzhang, RED, BLACK); //����
            else
                LCD_DrawImage1BPP(82 + 200 + 320, 100 + 38 * i, BMP_Zhengchang, GREEN, BLACK); //����
            dump = dump >> 1;
        }
    }

}

void frmDCDC(void) {
    static unsigned char index_Gaoya = 1;
    if (f_index == 0) { //ֻ����һ��
        f_index = 1;
        DCDCFrame(index_Gaoya);
    } else if (f_index == 1) {
        f_index = 1;
        DCDCUpdate(index_Gaoya);
    } else {
        f_index = 0;
    }

    if (key_up) { //�Ӳ˵��л�
        key_up = 0;
        index_Gaoya++;
        f_index = 0;
        if (index_Gaoya == 4) {
            index_Gaoya = 1;
            frmID = 1;
        }
    }

    if (key_AV) {
        key_AV = 0;
        index_Gaoya--;
        f_index = 0;
        if (index_Gaoya == 0) {
            index_Gaoya = 1;
            frmID = 1;
        }
    }

    if (key_set) {//���˵�/�Ӳ˵��л�
        key_set = 0;
        frmID = 0;
        f_index = 0;
        index_Gaoya = 1;
    }

    if (key_long_set) {
        key_long_set = 0;
    }
}

/******************************************************/
void FAULTFrame(void) {
    unsigned char i = 0;
    LCD_Clear();
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //��������
    LCD_DrawImage1BPP(130 + 200, 130 - 85, BMP_GUZHANG, WHITE, BLACK); //����
    LCD_DrawImage1BPP(130 + 200 + 50, 130 - 85, BMP_STSTEM, WHITE, BLACK); //ϵͳ
    LCD_DrawImage1BPP(130 + 200 + 50 + 50, 130 - 85, BMP_Message, WHITE, BLACK); //��Ϣ

    LCD_DrawRect(80, 90, 1, 380, GREEN);
    //LCD_DrawRect(80 + 320, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320 + 320, 90, 1, 380, GREEN);
    for (i = 0; i < 11; i++)
        LCD_DrawRect(80, 90 + i * 38, 640, 1, GREEN);

    LCD_DrawImage1BPP(82 + 300, 100 + 38 * 0, BMP_s, WHITE, BLACK); //SPN
    LCD_DrawImage1BPP(82 + 300 + 11, 100 + 38 * 0, BMP_p, WHITE, BLACK); //  
    LCD_DrawImage1BPP(82 + 300 + 11 + 11, 100 + 38 * 0, BMP_n, WHITE, BLACK); //

    LCD_DrawImage1BPP(82 + 300 + 140, 100 + 38 * 0, BMP_f, WHITE, BLACK); //FMI
    LCD_DrawImage1BPP(82 + 300 + 140 + 11, 100 + 38 * 0, BMP_m, WHITE, BLACK); //  
    LCD_DrawImage1BPP(82 + 300 + 140 + 11 + 11, 100 + 38 * 0, BMP_i, WHITE, BLACK); //

    LCD_DrawImage1BPP(82, 100 + 38 * 1, BMP_v, WHITE, BLACK); //VCUϵͳ���������
    LCD_DrawImage1BPP(82 + 11, 100 + 38 * 1, BMP_c, WHITE, BLACK); //  
    LCD_DrawImage1BPP(82 + 11 + 11, 100 + 38 * 1, BMP_u, WHITE, BLACK); //
    LCD_DrawImage1BPP(82 + 11 + 11 + 11, 100 + 38 * 1, BMP_System, WHITE, BLACK); //
    LCD_DrawImage1BPP(82 + 11 + 11 + 11 + 42, 100 + 38 * 1, BMP_Guzhang, WHITE, BLACK); //
    LCD_DrawImage1BPP(82 + 11 + 11 + 11 + 42 + 42, 100 + 38 * 1, BMP_Code, WHITE, BLACK); //

    LCD_DrawImage1BPP(82, 100 + 38 * 2, BMP_m, WHITE, BLACK); //MCUϵͳ���������
    LCD_DrawImage1BPP(82 + 11, 100 + 38 * 2, BMP_c, WHITE, BLACK); //  
    LCD_DrawImage1BPP(82 + 11 + 11, 100 + 38 * 2, BMP_u, WHITE, BLACK); //
    LCD_DrawImage1BPP(82 + 11 + 11 + 11, 100 + 38 * 2, BMP_System, WHITE, BLACK); //
    LCD_DrawImage1BPP(82 + 11 + 11 + 11 + 42, 100 + 38 * 2, BMP_Guzhang, WHITE, BLACK); //
    LCD_DrawImage1BPP(82 + 11 + 11 + 11 + 42 + 42, 100 + 38 * 2, BMP_Code, WHITE, BLACK); //

    LCD_DrawImage1BPP(82, 100 + 38 * 3, BMP_b, WHITE, BLACK); //BMSϵͳ���������
    LCD_DrawImage1BPP(82 + 11, 100 + 38 * 3, BMP_m, WHITE, BLACK); //  
    LCD_DrawImage1BPP(82 + 11 + 11, 100 + 38 * 3, BMP_s, WHITE, BLACK); //
    LCD_DrawImage1BPP(82 + 11 + 11 + 11, 100 + 38 * 3, BMP_System, WHITE, BLACK); //
    LCD_DrawImage1BPP(82 + 11 + 11 + 11 + 42, 100 + 38 * 3, BMP_Guzhang, WHITE, BLACK); //
    LCD_DrawImage1BPP(82 + 11 + 11 + 11 + 42 + 42, 100 + 38 * 3, BMP_Code, WHITE, BLACK); //

}

void FAULTUpdate(void) {
    disp_VCU_baojing(CAN_18FECAEF_len, CAN_18FECAEF, 0);
    if (*(SPN + 0) < 6000) {
        print_SZ_1(82 + 230, 100 - 8 + 38 * 1, *(SPN + 0), 6, 0, GREEN);
        print_SZ_1(82 + 230 + 180, 100 - 8 + 38 * 1, *(FMI + 0), 3, 0, GREEN);
    } else {
        print_SZ_1(82 + 230, 100 - 8 + 38 * 1, 0, 6, 0, GREEN);
        print_SZ_1(82 + 230 + 180, 100 - 8 + 38 * 1, 0, 3, 0, GREEN);
    }

    disp_MCU_baojing(CAN_18FECAEF_len, CAN_18FECAEF, 1);
    if (*(SPN + 1) >= 6000 || *(SPN + 1) == 0) {
        print_SZ_1(82 + 230, 100 - 8 + 38 * 2, *(SPN + 1), 6, 0, GREEN);
        print_SZ_1(82 + 230 + 180, 100 - 8 + 38 * 2, *(FMI + 1), 3, 0, GREEN);
    } else {
        print_SZ_1(82 + 230, 100 - 8 + 38 * 2, 0, 6, 0, GREEN);
        print_SZ_1(82 + 230 + 180, 100 - 8 + 38 * 2, 0, 3, 0, GREEN);
    }

    disp_BMS_baojing(CAN_18FECAF3_len, CAN_18FECAF3, 2);
    print_SZ_1(82 + 230, 100 - 8 + 38 * 3, *(SPN + 2), 6, 0, GREEN);
    print_SZ_1(82 + 230 + 180, 100 - 8 + 38 * 3, *(FMI + 2), 3, 0, GREEN);


}

void frmFAULT(void) {
    if (f_index == 0) { //ֻ����һ��
        f_index = 1;
        FAULTFrame();
    } else if (f_index == 1) {
        f_index = 1;
        FAULTUpdate();
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
void BMSFrame(unsigned char index) {
    unsigned char i = 0;
    LCD_Clear();
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //��������
    LCD_DrawImage1BPP(130 + 200 - 24, 130 - 85, BMP_Battery, WHITE, BLACK); //���
    LCD_DrawImage1BPP(130 + 200 + 50 - 24, 130 - 85, BMP_Manage, WHITE, BLACK); //����
    LCD_DrawImage1BPP(130 + 200 + 50 + 50 - 24, 130 - 85, BMP_STSTEM, WHITE, BLACK); //ϵͳ
    LCD_DrawImage1BPP(130 + 200 + 50 + 50 + 50 - 24, 130 - 85, BMP_Message, WHITE, BLACK); //��Ϣ

    if (index == 1) {
        print_SZ_2(750, 50, 1, 1, 0, WHITE); // 1/2
        LCD_DrawImage1BPP(750 + 11, 50, BMP_I, WHITE, BLACK);
        print_SZ_2(750 + 11 + 14, 50, 2, 1, 0, WHITE);
        LCD_DrawRect(80, 90, 1, 380, GREEN);
        LCD_DrawRect(80 + 320, 90, 1, 380, GREEN);
        LCD_DrawRect(80 + 320 + 320 + 70, 90, 1, 380, GREEN);
        for (i = 0; i < 11; i++)
            LCD_DrawRect(80, 90 + i * 38, 710, 1, GREEN);

        LCD_DrawImage1BPP(82, 100, BMP_Zong, WHITE, BLACK); //��
        LCD_DrawImage1BPP(82 + 21, 100, BMP_Zheng, WHITE, BLACK); //��
        LCD_DrawImage1BPP(82 + 42, 100, BMP_Jiechuqi, WHITE, BLACK); //�Ӵ���
        LCD_DrawImage1BPP(82 + 42 + 63, 100, BMP_Zhuangtai, WHITE, BLACK); //״̬

        LCD_DrawImage1BPP(82, 100 + 38, BMP_Zong, WHITE, BLACK); //��
        LCD_DrawImage1BPP(82 + 21, 100 + 38, BMP_Fu, WHITE, BLACK); //��
        LCD_DrawImage1BPP(82 + 42, 100 + 38, BMP_Jiechuqi, WHITE, BLACK); //�Ӵ���
        LCD_DrawImage1BPP(82 + 42 + 63, 100 + 38, BMP_Zhuangtai, WHITE, BLACK); //״̬

        LCD_DrawImage1BPP(82, 100 + 38 * 2, BMP_Yuchong, WHITE, BLACK); //Ԥ��
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 2, BMP_Jiechuqi, WHITE, BLACK); //�Ӵ���
        LCD_DrawImage1BPP(82 + 42 + 63, 100 + 38 * 2, BMP_Zhuangtai, WHITE, BLACK); //״̬

        LCD_DrawImage1BPP(82, 100 + 38 * 3, BMP_Chushuang, WHITE, BLACK); //��˪
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 3, BMP_Jiechuqi, WHITE, BLACK); //�Ӵ���
        LCD_DrawImage1BPP(82 + 42 + 63, 100 + 38 * 3, BMP_Zhuangtai, WHITE, BLACK); //״̬

        LCD_DrawImage1BPP(82, 100 + 38 * 4, BMP_Kongtiao, WHITE, BLACK); //��˪
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 4, BMP_Jiechuqi, WHITE, BLACK); //�Ӵ���
        LCD_DrawImage1BPP(82 + 42 + 63, 100 + 38 * 4, BMP_Zhuangtai, WHITE, BLACK); //״̬

        LCD_DrawImage1BPP(82, 100 + 38 * 5, BMP_Sanheyi, WHITE, BLACK); //����һ
        LCD_DrawImage1BPP(82 + 63, 100 + 38 * 5, BMP_Jiechuqi, WHITE, BLACK); //�Ӵ���
        LCD_DrawImage1BPP(82 + 63 + 63, 100 + 38 * 5, BMP_Zhuangtai, WHITE, BLACK); //״̬

        LCD_DrawImage1BPP(82, 100 + 38 * 6, BMP_b, WHITE, BLACK); //b
        LCD_DrawImage1BPP(82 + 11, 100 + 38 * 6, BMP_m, WHITE, BLACK); //m
        LCD_DrawImage1BPP(82 + 11 + 11, 100 + 38 * 6, BMP_s, WHITE, BLACK); //s   
        LCD_DrawImage1BPP(82 + 11 + 11 + 11, 100 + 38 * 6, BMP_Gongzuo, WHITE, BLACK); //����
        LCD_DrawImage1BPP(82 + 11 + 11 + 11 + 42, 100 + 38 * 6, BMP_Zhuangtai, WHITE, BLACK); //״̬

        LCD_DrawImage1BPP(82, 100 + 38 * 7, BMP_Jueyuan, WHITE, BLACK); //��Ե
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 7, BMP_DC, WHITE, BLACK); //���
        LCD_DrawImage1BPP(82 + 42 + 21, 100 + 38 * 7, BMP_Zu, WHITE, BLACK); //��
        LCD_DrawImage1BPP(400 - 28, 100 + 38 * 7, BMP_k, WHITE, BLACK); //K
        LCD_DrawImage1BPP(400 - 16, 100 + 2 + 38 * 7, BMP_Omu, WHITE, BLACK); //��

        LCD_DrawImage1BPP(82, 100 + 38 * 8, BMP_Life, WHITE, BLACK); //life�ź�
        LCD_DrawImage1BPP(82 + 44, 100 + 38 * 8, BMP_Xinhao, WHITE, BLACK);

        /*LCD_DrawImage1BPP(82, 100, BMP_DC, WHITE, BLACK); //���
        LCD_DrawImage1BPP(82 + 42, 100, BMP_Zong, WHITE, BLACK); //��
        LCD_DrawImage1BPP(82 + 42 + 21, 100, BMP_DY, WHITE, BLACK); //��ѹ
        LCD_DrawImage1BPP(82 + 42 + 21 + 42 + 2, 100 + 5, BMP_Maohao, WHITE, BLACK); //:
        LCD_DrawImage1BPP(400 - 24, 100, BMP_v, WHITE, BLACK); //V

        LCD_DrawImage1BPP(82, 100 + 38, BMP_DC, WHITE, BLACK); //���
        LCD_DrawImage1BPP(82 + 42, 100 + 38, BMP_Zong, WHITE, BLACK); //��
        LCD_DrawImage1BPP(82 + 42 + 21, 100 + 38, BMP_DL, WHITE, BLACK); //����
        LCD_DrawImage1BPP(400 - 24, 100 + 38, BMP_a, WHITE, BLACK); //A

        LCD_DrawImage1BPP(82, 100 + 38 * 2, BMP_s, WHITE, BLACK); //S
        LCD_DrawImage1BPP(82 + 11, 100 + 38 * 2, BMP_o, WHITE, BLACK); //O
        LCD_DrawImage1BPP(82 + 11 + 11, 100 + 38 * 2, BMP_c, WHITE, BLACK); //C
        LCD_DrawImage1BPP(400 - 24, 100 + 38 * 2, BMP_Baifenhao, WHITE, BLACK); //%

        LCD_DrawImage1BPP(82, 100 + 38 * 3, BMP_DC, WHITE, BLACK); //��س�ŵ�ģʽ
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 3, BMP_Chong, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 42 + 21, 100 + 38 * 3, BMP_Fang, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 3, BMP_DC, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 42 + 21 + 42, 100 + 38 * 3, BMP_Mode, WHITE, BLACK);

        LCD_DrawImage1BPP(82, 100 + 38 * 4, BMP_Gao, WHITE, BLACK); //��ѹ�̵���״̬
        LCD_DrawImage1BPP(82 + 21, 100 + 38 * 4, BMP_Yali, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 4, BMP_Jidianqi, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 42 + 63, 100 + 38 * 4, BMP_Zhuangtai, WHITE, BLACK);

        LCD_DrawImage1BPP(82, 100 + 38 * 5, BMP_Guzhang, WHITE, BLACK); //����
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 5, BMP_Zhuangtai, WHITE, BLACK); //״̬

        LCD_DrawImage1BPP(82, 100 + 38 * 6, BMP_Dan, WHITE, BLACK); //��
        LCD_DrawImage1BPP(82 + 21, 100 + 38 * 6, BMP_Ti, WHITE, BLACK); //��
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 6, BMP_DY, WHITE, BLACK); //��ѹ
        LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 6, BMP_Shuliang, WHITE, BLACK); //����

        LCD_DrawImage1BPP(82, 100 + 38 * 7, BMP_Dan, WHITE, BLACK); //��
        LCD_DrawImage1BPP(82 + 21, 100 + 38 * 7, BMP_Ti, WHITE, BLACK); //��
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 7, BMP_Wendu, WHITE, BLACK); //�¶�
        LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 7, BMP_Shuliang, WHITE, BLACK); //����

        LCD_DrawImage1BPP(82, 100 + 38 * 8, BMP_System, WHITE, BLACK); //ϵͳ
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 8, BMP_Shuliang, WHITE, BLACK); //����

        LCD_DrawImage1BPP(82, 100 + 38 * 9, BMP_System, WHITE, BLACK); //ϵͳ
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 9, BMP_Hao, WHITE, BLACK); //��
         */

        for (i = 0; i < 4; i++) {
            LCD_DrawImage1BPP(82 + 320, 100 + 38 * i, BMP_Zui, WHITE, BLACK); //��
            if (i % 2 == 0)
                LCD_DrawImage1BPP(82 + 320 + 21, 100 + 38 * i, BMP_Gao, WHITE, BLACK); // ��
            else LCD_DrawImage1BPP(82 + 320 + 21, 100 + 38 * i, BMP_Di, WHITE, BLACK); // �� 
            LCD_DrawImage1BPP(82 + 320 + 21 + 21, 100 + 38 * i, BMP_Dan, WHITE, BLACK); //��
            LCD_DrawImage1BPP(82 + 320 + 21 + 21 + 21, 100 + 38 * i, BMP_Ti, WHITE, BLACK); //��
            if (i < 2) {
                LCD_DrawImage1BPP(82 + 320 + 21 + 21 + 21 + 21, 100 + 38 * i, BMP_DY, WHITE, BLACK); //��ѹ
                LCD_DrawImage1BPP(720 - 24 - 63 - 5, 100 + 38 * i, BMP_v, WHITE, BLACK); //V
            } else {
                LCD_DrawImage1BPP(82 + 320 + 21 + 21 + 21 + 21, 100 + 38 * i, BMP_Wendu, WHITE, BLACK); //�¶�
                LCD_DrawImage1BPP(720 - 28 - 63 - 5, 100 + 38 * i, BMP_T, WHITE, BLACK); //��
            }
            LCD_DrawImage1BPP(82 + 320 + 42 * 7 - 5, 100 + 38 * i, BMP_Xiang_BMS, WHITE, BLACK); //��

            LCD_DrawImage1BPP(82 + 320 + 42 * 8.5 + 5, 100 + 38 * i, BMP_Hao, WHITE, BLACK); //��
        }

        /*LCD_DrawImage1BPP(82 + 320, 100 + 38 * 4, BMP_Dan, WHITE, BLACK); //��
        LCD_DrawImage1BPP(82 + 320 + 21, 100 + 38 * 4, BMP_Ti, WHITE, BLACK); //��
        LCD_DrawImage1BPP(82 + 320 + 21 + 21, 100 + 38 * 4, BMP_Pingjun, WHITE, BLACK); //ƽ��
        LCD_DrawImage1BPP(82 + 320 + 21 + 21 + 42, 100 + 38 * 4, BMP_Wendu, WHITE, BLACK); //�¶�
        LCD_DrawImage1BPP(720 - 28, 100 + 38 * 4, BMP_T, WHITE, BLACK); //��    

        LCD_DrawImage1BPP(82 + 320, 100 + 38 * 5, BMP_Jueyuan, WHITE, BLACK); //��Ե
        LCD_DrawImage1BPP(82 + 42 + 320, 100 + 38 * 5, BMP_DC, WHITE, BLACK); //���
        LCD_DrawImage1BPP(82 + 42 + 21 + 320, 100 + 38 * 5, BMP_Zu, WHITE, BLACK); //��
        LCD_DrawImage1BPP(720 - 28, 100 + 38 * 5, BMP_k, WHITE, BLACK); //K
        LCD_DrawImage1BPP(720 - 16, 100 + 2 + 38 * 5, BMP_Omu, WHITE, BLACK); //��

        LCD_DrawImage1BPP(82 + 320, 100 + 38 * 5, BMP_Huanjin, WHITE, BLACK); //����
        LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 5, BMP_Wendu, WHITE, BLACK); //�¶�
        LCD_DrawImage1BPP(720 - 28 - 48, 100 + 38 * 5, BMP_T, WHITE, BLACK); //��
         */



        /*LCD_DrawImage1BPP(82 + 320 + 90 + 40, 100 + 38 * 6, BMP_s, WHITE, BLACK); //SPN
        LCD_DrawImage1BPP(82 + 320 + 90 + 40 + 11, 100 + 38 * 6, BMP_p, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 320 + 90 + 40 + 11 + 11, 100 + 38 * 6, BMP_n, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 320 + 90 + 40 + 80, 100 + 38 * 6, BMP_f, WHITE, BLACK); //FMI
        LCD_DrawImage1BPP(82 + 320 + 90 + 40 + 80 + 11, 100 + 38 * 6, BMP_m, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 320 + 90 + 40 + 80 + 11 + 11, 100 + 38 * 6, BMP_i, WHITE, BLACK);*/
    } else if (index == 2) {
        print_SZ_2(750, 50, 2, 1, 0, WHITE); // 1/2
        LCD_DrawImage1BPP(750 + 11, 50, BMP_I, WHITE, BLACK);
        print_SZ_2(750 + 11 + 14, 50, 2, 1, 0, WHITE);
        LCD_DrawRect(80, 90, 1, 380, GREEN);
        LCD_DrawRect(80 + 320, 90, 1, 380, GREEN);
        LCD_DrawRect(80 + 320 + 320, 90, 1, 380, GREEN);
        for (i = 0; i < 11; i++)
            LCD_DrawRect(80, 90 + i * 38, 640, 1, GREEN);

        LCD_DrawImage1BPP(82, 100 + 38 * 0, BMP_Zhengche, WHITE, BLACK); //�������״̬
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 0, BMP_Chong, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 42 + 21, 100 + 38 * 0, BMP_DC, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 0, BMP_Zhuangtai, WHITE, BLACK);

        LCD_DrawImage1BPP(82, 100 + 38 * 1, BMP_Chong, WHITE, BLACK); //���DC+�¶�
        LCD_DrawImage1BPP(82 + 21, 100 + 38 * 1, BMP_DC, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 42, 100 - 2 + 38 * 1, BMP_DCDC, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(82 + 42 + 26, 100 + 38 * 1, BMP_ZHENG, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 42 + 26 + 12, 100 + 38 * 1, BMP_Wendu, WHITE, BLACK);
        LCD_DrawImage1BPP(400 - 24, 100 + 38 * 1, BMP_T, WHITE, BLACK); //��

        LCD_DrawImage1BPP(82, 100 + 38 * 2, BMP_Chong, WHITE, BLACK); //���DC-�¶�
        LCD_DrawImage1BPP(82 + 21, 100 + 38 * 2, BMP_DC, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 42, 100 - 2 + 38 * 2, BMP_DCDC, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(82 + 42 + 26, 100 + 38 * 2, BMP_FU, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 42 + 26 + 12, 100 + 38 * 2, BMP_Wendu, WHITE, BLACK);
        LCD_DrawImage1BPP(400 - 24, 100 + 38 * 2, BMP_T, WHITE, BLACK); //��

        LCD_DrawImage1BPP(82, 100 + 38 * 3, BMP_Chong, WHITE, BLACK); //���ǹ״̬
        LCD_DrawImage1BPP(82 + 21, 100 + 38 * 3, BMP_DC, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 3, BMP_Qiang, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 63, 100 + 38 * 3, BMP_Zhuangtai, WHITE, BLACK);

        LCD_DrawImage1BPP(82, 100 + 38 * 4, BMP_DC, WHITE, BLACK); //��ؼ���״̬
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 4, BMP_Jiare, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 4, BMP_Zhuangtai, WHITE, BLACK);

        LCD_DrawImage1BPP(82, 100 + 38 * 5, BMP_Zui, WHITE, BLACK); //��߱����ȼ�
        LCD_DrawImage1BPP(82 + 21, 100 + 38 * 5, BMP_Gao, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 5, BMP_Baojing, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 5, BMP_Dengji, WHITE, BLACK);

        LCD_DrawImage1BPP(82, 100 + 38 * 6, BMP_Wendu, WHITE, BLACK); //�¶Ȳ���ȼ�
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 6, BMP_Chayi, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 6, BMP_Baojing, WHITE, BLACK);

        LCD_DrawImage1BPP(82, 100 + 38 * 7, BMP_DC, WHITE, BLACK); //��ظ��±���
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 7, BMP_Gao, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 42 + 21, 100 + 38 * 7, BMP_Wendu, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 7, BMP_Baojing, WHITE, BLACK);

        LCD_DrawImage1BPP(82, 100 + 38 * 8, BMP_Chuneng, WHITE, BLACK); //����װ�ù�ѹ����
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 8, BMP_Zhuangzhi, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 8, BMP_Guo, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 42 + 42 + 21, 100 + 38 * 8, BMP_Yali, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 42 + 42 + 42, 100 + 38 * 8, BMP_Baojing, WHITE, BLACK);

        LCD_DrawImage1BPP(82, 100 + 38 * 9, BMP_Chuneng, WHITE, BLACK); //����װ��Ƿѹ����
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 9, BMP_Zhuangzhi, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 9, BMP_Qian, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 42 + 42 + 21, 100 + 38 * 9, BMP_Yali, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 42 + 42 + 42, 100 + 38 * 9, BMP_Baojing, WHITE, BLACK);


        LCD_DrawImage1BPP(82 + 320, 100 + 38 * 0, BMP_s, WHITE, BLACK); //SOC�ͱ���
        LCD_DrawImage1BPP(82 + 320 + 11, 100 + 38 * 0, BMP_o, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 320 + 11 + 11, 100 + 38 * 0, BMP_c, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 320 + 11 + 11 + 11, 100 + 38 * 0, BMP_Di, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 320 + 11 + 11 + 11 + 21, 100 + 38 * 0, BMP_Baojing, WHITE, BLACK);

        LCD_DrawImage1BPP(82 + 320, 100 + 38 * 1, BMP_Dan, WHITE, BLACK); //�����ع�ѹ����
        LCD_DrawImage1BPP(82 + 320 + 21, 100 + 38 * 1, BMP_Ti, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 1, BMP_DC, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 320 + 42 + 42, 100 + 38 * 1, BMP_Guo, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 320 + 42 + 42 + 21, 100 + 38 * 1, BMP_Yali, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 320 + 42 + 42 + 42, 100 + 38 * 1, BMP_Baojing, WHITE, BLACK);

        LCD_DrawImage1BPP(82 + 320, 100 + 38 * 2, BMP_Dan, WHITE, BLACK); //������Ƿѹ����
        LCD_DrawImage1BPP(82 + 320 + 21, 100 + 38 * 2, BMP_Ti, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 2, BMP_DC, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 320 + 42 + 42, 100 + 38 * 2, BMP_Qian, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 320 + 42 + 42 + 21, 100 + 38 * 2, BMP_Yali, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 320 + 42 + 42 + 42, 100 + 38 * 2, BMP_Baojing, WHITE, BLACK);

        LCD_DrawImage1BPP(82 + 320, 100 + 38 * 3, BMP_s, WHITE, BLACK); //SOC���߱���
        LCD_DrawImage1BPP(82 + 320 + 11, 100 + 38 * 3, BMP_o, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 320 + 11 + 11, 100 + 38 * 3, BMP_c, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 320 + 11 + 11 + 11, 100 + 38 * 3, BMP_Guo, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 320 + 11 + 11 + 11 + 21, 100 + 38 * 3, BMP_Gao, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 320 + 11 + 11 + 11 + 42, 100 + 38 * 3, BMP_Baojing, WHITE, BLACK);

        LCD_DrawImage1BPP(82 + 320, 100 + 38 * 4, BMP_s, WHITE, BLACK); //SOC���䱨��
        LCD_DrawImage1BPP(82 + 320 + 11, 100 + 38 * 4, BMP_o, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 320 + 11 + 11, 100 + 38 * 4, BMP_c, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 320 + 11 + 11 + 11, 100 + 38 * 4, BMP_Tiaobian, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 320 + 11 + 11 + 11 + 42, 100 + 38 * 4, BMP_Baojing, WHITE, BLACK);

        LCD_DrawImage1BPP(82 + 320, 100 + 38 * 5, BMP_Chong, WHITE, BLACK); //��索��ϵͳ��ƥ�䱨��
        LCD_DrawImage1BPP(82 + 320 + 21, 100 + 38 * 5, BMP_DY, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 5, BMP_Chuneng, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 320 + 42 + 42, 100 + 38 * 5, BMP_System, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 320 + 42 + 42 + 42, 100 + 38 * 5, BMP_Bu, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 320 + 42 + 42 + 42 + 21, 100 + 38 * 5, BMP_Pipei, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 320 + 42 + 42 + 42 + 21 + 42, 100 + 38 * 5, BMP_Baojing, WHITE, BLACK);

        LCD_DrawImage1BPP(82 + 320, 100 + 38 * 6, BMP_DC, WHITE, BLACK); //��ص���һ���Բ��
        LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 6, BMP_Dan, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 320 + 42 + 21, 100 + 38 * 6, BMP_Ti, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 320 + 42 + 42, 100 + 38 * 6, BMP_Yizhixing, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 320 + 42 + 42 + 63, 100 + 38 * 6, BMP_Chayi, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 320 + 42 + 42 + 63 + 21, 100 + 38 * 6, BMP_Baojing, WHITE, BLACK);

        LCD_DrawImage1BPP(82 + 320, 100 + 38 * 7, BMP_Jueyuan, WHITE, BLACK); //��Ե����
        LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 7, BMP_Baojing, WHITE, BLACK);

        LCD_DrawImage1BPP(82 + 320, 100 + 38 * 8, BMP_Chuneng, WHITE, BLACK); //����װ�ù���
        LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 8, BMP_Zhuangzhi, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 320 + 42 + 42, 100 + 38 * 8, BMP_Guo, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 320 + 42 + 42 + 21, 100 + 38 * 8, BMP_Chong, WHITE, BLACK);
        /*LCD_DrawImage1BPP(82, 100, BMP_Zui, WHITE, BLACK); //��
        LCD_DrawImage1BPP(82 + 21, 100, BMP_Gao, WHITE, BLACK); //��
        LCD_DrawImage1BPP(82 + 42, 100, BMP_Yunxu, WHITE, BLACK); //����
        LCD_DrawImage1BPP(82 + 42 + 42, 100, BMP_Dan, WHITE, BLACK); //��
        LCD_DrawImage1BPP(82 + 42 + 42 + 21, 100, BMP_Ti, WHITE, BLACK); //��
        LCD_DrawImage1BPP(82 + 42 + 42 + 42, 100, BMP_Wendu, WHITE, BLACK); //�¶�
        LCD_DrawImage1BPP(400 - 24, 100, BMP_T, WHITE, BLACK); //��

        LCD_DrawImage1BPP(82, 100 + 38, BMP_Zui, WHITE, BLACK); //��
        LCD_DrawImage1BPP(82 + 21, 100 + 38, BMP_Di, WHITE, BLACK); //��
        LCD_DrawImage1BPP(82 + 42, 100 + 38, BMP_Yunxu, WHITE, BLACK); //����
        LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38, BMP_Dan, WHITE, BLACK); //��
        LCD_DrawImage1BPP(82 + 42 + 42 + 21, 100 + 38, BMP_Ti, WHITE, BLACK); //��
        LCD_DrawImage1BPP(82 + 42 + 42 + 42, 100 + 38, BMP_Wendu, WHITE, BLACK); //�¶�
        LCD_DrawImage1BPP(400 - 24, 100 + 38, BMP_T, WHITE, BLACK); //�� 

        LCD_DrawImage1BPP(82, 100 + 38 * 2, BMP_Zui, WHITE, BLACK); //��
        LCD_DrawImage1BPP(82 + 21, 100 + 38 * 2, BMP_Di, WHITE, BLACK); //��
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 2, BMP_Yunxu, WHITE, BLACK); //����
        LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 2, BMP_s, WHITE, BLACK); //S
        LCD_DrawImage1BPP(82 + 42 + 42 + 11, 100 + 38 * 2, BMP_o, WHITE, BLACK); //O
        LCD_DrawImage1BPP(82 + 42 + 42 + 11 + 11, 100 + 38 * 2, BMP_c, WHITE, BLACK); //C
        LCD_DrawImage1BPP(400 - 24, 100 + 38 * 2, BMP_Baifenhao, WHITE, BLACK); //%

        LCD_DrawImage1BPP(82, 100 + 38 * 3, BMP_Zui, WHITE, BLACK); //��
        LCD_DrawImage1BPP(82 + 21, 100 + 38 * 3, BMP_Gao, WHITE, BLACK); //��
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 3, BMP_Yunxu, WHITE, BLACK); //����
        LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 3, BMP_Fang, WHITE, BLACK); //��
        LCD_DrawImage1BPP(82 + 42 + 42 + 21, 100 + 38 * 3, BMP_DY, WHITE, BLACK); //��
        LCD_DrawImage1BPP(82 + 42 + 42 + 42, 100 + 38 * 3, BMP_DL, WHITE, BLACK); //����
        LCD_DrawImage1BPP(400 - 24, 100 + 38 * 3, BMP_a, WHITE, BLACK); //A

        LCD_DrawImage1BPP(82, 100 + 38 * 4, BMP_Zui, WHITE, BLACK); //��
        LCD_DrawImage1BPP(82 + 21, 100 + 38 * 4, BMP_Gao, WHITE, BLACK); //��
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 4, BMP_Yunxu, WHITE, BLACK); //����
        LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 4, BMP_Fankui, WHITE, BLACK); //����
        LCD_DrawImage1BPP(82 + 42 + 42 + 42, 100 + 38 * 4, BMP_DL, WHITE, BLACK); //����
        LCD_DrawImage1BPP(400 - 24, 100 + 38 * 4, BMP_a, WHITE, BLACK); //A

        for (i = 0; i < 2; i++) {
            if (i == 0)
                LCD_DrawImage1BPP(82, 100 + 38 * (i + 5), BMP_Zheng, WHITE, BLACK); //��
            else LCD_DrawImage1BPP(82, 100 + 38 * (i + 5), BMP_Fu, WHITE, BLACK); //��
            LCD_DrawImage1BPP(82 + 21, 100 + 38 * (i + 5), BMP_Jueyuan, WHITE, BLACK); //��Ե
            LCD_DrawImage1BPP(82 + 42 + 21, 100 + 38 * (i + 5), BMP_DC, WHITE, BLACK); //���
            LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * (i + 5), BMP_Zu, WHITE, BLACK); //��
            LCD_DrawImage1BPP(82 + 42 + 42 + 21 + 2, 100 + 5 + 38 * (i + 5), BMP_Maohao, WHITE, BLACK); //:
            LCD_DrawImage1BPP(400 - 28, 100 + 38 * (i + 5), BMP_k, WHITE, BLACK); //K
            LCD_DrawImage1BPP(400 - 16, 100 + 2 + 38 * (i + 5), BMP_Omu, WHITE, BLACK); //��
        }

        LCD_DrawImage1BPP(82, 100 + 38 * 7, BMP_Jueyuan, WHITE, BLACK); //��Ե
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 7, BMP_Guzhang, WHITE, BLACK); //����
        LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 7, BMP_Dengji, WHITE, BLACK); //�ȼ�

        LCD_DrawImage1BPP(82, 100 + 38 * 8, BMP_Jueyuan, WHITE, BLACK); //��Ե
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 8, BMP_Dengji, WHITE, BLACK); //�ȼ�

        LCD_DrawImage1BPP(82, 100 + 38 * 9, BMP_Jueyuan, WHITE, BLACK); //��Ե
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 9, BMP_Mokuai, WHITE, BLACK); //ģ��
        LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 9, BMP_Life, WHITE, BLACK); //LIFE


        LCD_DrawImage1BPP(82 + 320, 100, BMP_Zong, WHITE, BLACK); //��ѹ����״̬
        LCD_DrawImage1BPP(82 + 320 + 21, 100, BMP_Yali, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 320 + 42, 100, BMP_Guzhang, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 320 + 42 + 42, 100, BMP_Zhuangtai, WHITE, BLACK); //

        LCD_DrawImage1BPP(82 + 320, 100 + 38, BMP_Dan, WHITE, BLACK); //�����ѹ����״̬
        LCD_DrawImage1BPP(82 + 320 + 21, 100 + 38, BMP_Ti, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38, BMP_DY, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 320 + 42 + 42, 100 + 38, BMP_Guzhang, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 320 + 42 + 42 + 42, 100 + 38, BMP_Zhuangtai, WHITE, BLACK); //

        LCD_DrawImage1BPP(82 + 320, 100 + 38 * 2, BMP_Wendu, WHITE, BLACK); //�¶ȹ���״̬
        LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 2, BMP_Guzhang, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 320 + 42 + 42, 100 + 38 * 2, BMP_Zhuangtai, WHITE, BLACK); //

        LCD_DrawImage1BPP(82 + 320, 100 + 38 * 3, BMP_Jueyuan, WHITE, BLACK); //��Ե����״̬
        LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 3, BMP_Guzhang, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 320 + 42 + 42, 100 + 38 * 3, BMP_Zhuangtai, WHITE, BLACK); //

        LCD_DrawImage1BPP(82 + 320, 100 + 38 * 4, BMP_Junheng, WHITE, BLACK); //�������״̬
        LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 4, BMP_Guzhang, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 320 + 42 + 42, 100 + 38 * 4, BMP_Zhuangtai, WHITE, BLACK); //

        LCD_DrawImage1BPP(82 + 320, 100 + 38 * 5, BMP_s, WHITE, BLACK); //SOC����״̬
        LCD_DrawImage1BPP(82 + 320 + 11, 100 + 38 * 5, BMP_o, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 320 + 11 + 11, 100 + 38 * 5, BMP_c, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 320 + 11 + 11 + 11, 100 + 38 * 5, BMP_Guzhang, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 320 + 11 + 11 + 11 + 42, 100 + 38 * 5, BMP_Zhuangtai, WHITE, BLACK); //

        LCD_DrawImage1BPP(82 + 320, 100 + 38 * 6, BMP_DL, WHITE, BLACK); //��������״̬
        LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 6, BMP_Guzhang, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 320 + 42 + 42, 100 + 38 * 6, BMP_Zhuangtai, WHITE, BLACK); //

        LCD_DrawImage1BPP(82 + 320, 100 + 38 * 7, BMP_Gao, WHITE, BLACK); //��ѹ����״̬
        LCD_DrawImage1BPP(82 + 320 + 21, 100 + 38 * 7, BMP_Yali, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 7, BMP_Husuo, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 320 + 42 + 42, 100 + 38 * 7, BMP_Zhuangtai, WHITE, BLACK); //

        LCD_DrawImage1BPP(82 + 320, 100 + 38 * 8, BMP_b, WHITE, BLACK); //BMS����״̬
        LCD_DrawImage1BPP(82 + 320 + 11, 100 + 38 * 8, BMP_m, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 320 + 11 + 11, 100 + 38 * 8, BMP_s, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 320 + 11 + 11 + 11, 100 + 38 * 8, BMP_Guzhang, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 320 + 11 + 11 + 11 + 42, 100 + 38 * 8, BMP_Zhuangtai, WHITE, BLACK); //

        LCD_DrawImage1BPP(82 + 320, 100 + 38 * 9, BMP_System, WHITE, BLACK); //ϵͳ����
        LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 9, BMP_Baojing, WHITE, BLACK); //
         */
    }

}

void BMSUpdate(unsigned char index) {
    static unsigned char dump;
    unsigned char i;
    if (index == 1) {
        if (BAT_Status1.bit1 == 0) {
            LCD_DrawImage1BPP(82 + 200, 100 + 38 * 0, BMP_Kai, GREEN, BLACK); //��
            LCD_DrawRect(82 + 200 + 21, 100 + 38 * 0, 21, 20, BLACK);
        } else if (BAT_Status1.bit1 == 1) {
            LCD_DrawImage1BPP(82 + 200, 100 + 38 * 0, BMP_Guan, WHITE, BLACK); //��
            LCD_DrawRect(82 + 200 + 21, 100 + 38 * 0, 21, 20, BLACK);
        } else if (BAT_Status1.bit1 == 2)
            LCD_DrawImage1BPP(82 + 200, 100 + 38 * 0, BMP_Guzhang, RED, BLACK); //����

        if (BAT_Status1.bit2 == 0) {
            LCD_DrawImage1BPP(82 + 200, 100 + 38 * 1, BMP_Kai, GREEN, BLACK); //��
            LCD_DrawRect(82 + 200 + 21, 100 + 38 * 1, 21, 20, BLACK);
        } else if (BAT_Status1.bit2 == 1) {
            LCD_DrawImage1BPP(82 + 200, 100 + 38 * 1, BMP_Guan, WHITE, BLACK); //��
            LCD_DrawRect(82 + 200 + 21, 100 + 38 * 1, 21, 20, BLACK);
        } else if (BAT_Status1.bit2 == 2)
            LCD_DrawImage1BPP(82 + 200, 100 + 38 * 1, BMP_Guzhang, RED, BLACK); //����

        if (BAT_Status1.bit3 == 0) {
            LCD_DrawImage1BPP(82 + 200, 100 + 38 * 2, BMP_Kai, GREEN, BLACK); //��
            LCD_DrawRect(82 + 200 + 21, 100 + 38 * 2, 21, 20, BLACK);
        } else if (BAT_Status1.bit3 == 1) {
            LCD_DrawImage1BPP(82 + 200, 100 + 38 * 2, BMP_Guan, WHITE, BLACK); //��
            LCD_DrawRect(82 + 200 + 21, 100 + 38 * 2, 21, 20, BLACK);
        } else if (BAT_Status1.bit3 == 2)
            LCD_DrawImage1BPP(82 + 200, 100 + 38 * 2, BMP_Guzhang, RED, BLACK); //����

        if (BAT_Status1.bit4 == 0) {
            LCD_DrawImage1BPP(82 + 200, 100 + 38 * 3, BMP_Kai, GREEN, BLACK); //��
            LCD_DrawRect(82 + 200 + 21, 100 + 38 * 3, 21, 20, BLACK);
        } else if (BAT_Status1.bit4 == 1) {
            LCD_DrawImage1BPP(82 + 200, 100 + 38 * 3, BMP_Guan, WHITE, BLACK); //��
            LCD_DrawRect(82 + 200 + 21, 100 + 38 * 3, 21, 20, BLACK);
        } else if (BAT_Status1.bit4 == 2)
            LCD_DrawImage1BPP(82 + 200, 100 + 38 * 3, BMP_Guzhang, RED, BLACK); //����

        if (BAT_Status2.bit1 == 0) {
            LCD_DrawImage1BPP(82 + 200, 100 + 38 * 4, BMP_Kai, GREEN, BLACK); //��
            LCD_DrawRect(82 + 200 + 21, 100 + 38 * 4, 21, 20, BLACK);
        } else if (BAT_Status2.bit1 == 1) {
            LCD_DrawImage1BPP(82 + 200, 100 + 38 * 4, BMP_Guan, WHITE, BLACK); //��
            LCD_DrawRect(82 + 200 + 21, 100 + 38 * 4, 21, 20, BLACK);
        } else if (BAT_Status2.bit1 == 2)
            LCD_DrawImage1BPP(82 + 200, 100 + 38 * 4, BMP_Guzhang, RED, BLACK); //����

        if (BAT_Status2.bit2 == 0) {
            LCD_DrawImage1BPP(82 + 200, 100 + 38 * 5, BMP_Kai, GREEN, BLACK); //��
            LCD_DrawRect(82 + 200 + 21, 100 + 38 * 5, 21, 20, BLACK);
        } else if (BAT_Status2.bit2 == 1) {
            LCD_DrawImage1BPP(82 + 200, 100 + 38 * 5, BMP_Guan, WHITE, BLACK); //��
            LCD_DrawRect(82 + 200 + 21, 100 + 38 * 5, 21, 20, BLACK);
        } else if (BAT_Status2.bit2 == 2)
            LCD_DrawImage1BPP(82 + 200, 100 + 38 * 5, BMP_Guzhang, RED, BLACK); //����

        print_SZ_1(82 + 200, 100 - 8 + 38 * 6, BMS_Status, 1, 0, WHITE);

        print_SZ_1(82 + 200, 100 - 8 + 38 * 7, BMS_Ohm, 5, 0, WHITE);
        print_SZ_1(82 + 200 + 32, 100 - 8 + 38 * 8, BMS_Life, 3, 0, WHITE);



        print_SZ_1(82 + 200 + 300 - 32 - 5, 100 - 8, BAT_Single_H * 2, 3, 2, WHITE);
        print_SZ_1(82 + 200 + 300 - 32 + 16 * 6 - 5, 100 - 8, BAT_Single_H_Case, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 300 - 32 + 16 * 10 + 5, 100 - 8, BAT_Single_H_Number, 3, 0, WHITE);

        print_SZ_1(82 + 200 + 300 - 32 - 5, 100 - 8 + 38, BAT_Single_L * 2, 3, 2, WHITE);
        print_SZ_1(82 + 200 + 300 - 32 + 16 * 6 - 5, 100 - 8 + 38, BAT_Single_L_Case, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 300 - 32 + 16 * 10 + 5, 100 - 8 + 38, BAT_Single_L_Number, 3, 0, WHITE);

        updata_DAT(82 + 200 + 300 - 5, 100 - 8 + 38 * 2, BAT_Temp_H, 1, 40, WHITE, 3, 0);
        print_SZ_1(82 + 200 + 300 - 32 + 16 * 6 - 5, 100 - 8 + 38 * 2, BAT_Temp_H_Case, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 300 - 32 + 16 * 10 + 5, 100 - 8 + 38 * 2, BAT_Temp_H_Number, 3, 0, WHITE);

        updata_DAT(82 + 200 + 300 - 5, 100 - 8 + 38 * 3, BAT_Temp_L, 1, 40, WHITE, 3, 0);
        print_SZ_1(82 + 200 + 300 - 32 + 16 * 6 - 5, 100 - 8 + 38 * 3, BAT_Temp_L_Case, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 300 - 32 + 16 * 10 + 5, 100 - 8 + 38 * 3, BAT_Temp_L_Number, 3, 0, WHITE);
    } else if (index == 2) {
        print_SZ_1(82 + 200 + 32, 100 - 8 + 38 * 0, BAT_Charge, 3, 0, WHITE);
        updata_DAT(82 + 200 + 32, 100 - 8 + 38 * 1, BAT_DC_Positive, 1, 50, WHITE, 3, 0);
        updata_DAT(82 + 200 + 32, 100 - 8 + 38 * 2, BAT_DC_Negative, 1, 50, WHITE, 3, 0);
        print_H(82 + 200 + 48, 100 - 8 + 38 * 3, BAT_ChargeGun, 2, 0, WHITE);
        print_D(82 + 200 + 48, 100 - 8 + 38 * 4, BAT_Warming, 2, 0, WHITE);
        print_SZ_1(82 + 200 + 32, 100 - 8 + 38 * 5, BAT_Warn_Level, 1, 0, WHITE);

        dump = BAT_Status3.byte;
        for (i = 0; i < 8; i++) {
            if (i < 4) {
                if ((dump & 0x01) == 1) {
                    LCD_DrawImage1BPP(82 + 200 + 32, 100 + 38 * (i + 6), BMP_Guzhang, RED, BLACK); //����
                } else {
                    LCD_DrawImage1BPP(82 + 200 + 32, 100 + 38 * (i + 6), BMP_Zhengchang, GREEN, BLACK); //����
                }
            } else {
                if ((dump & 0x01) == 1) {
                    LCD_DrawImage1BPP(82 + 200 + 320 + 32, 100 + 38 * (i - 4), BMP_Guzhang, RED, BLACK); //����
                } else {
                    LCD_DrawImage1BPP(82 + 200 + 320 + 32, 100 + 38 * (i - 4), BMP_Zhengchang, GREEN, BLACK); //����
                }
            }
            dump = dump >> 1;
        }

        dump = BAT_Status4.byte;
        for (i = 0; i < 5; i++) {
            if ((dump & 0x01) == 1) {
                LCD_DrawImage1BPP(82 + 200 + 320 + 32, 100 + 38 * (i + 4), BMP_Guzhang, RED, BLACK); //����
            } else {
                LCD_DrawImage1BPP(82 + 200 + 320 + 32, 100 + 38 * (i + 4), BMP_Zhengchang, GREEN, BLACK); //����
            }
            dump = dump >> 1;
        }
    }
}

void frmBMS(void) {
    static unsigned char index_BMS = 1;
    if (f_index == 0) { //ֻ����һ��
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
        if (index_BMS == 3) {
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

    if (key_set) {//����������
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
    unsigned char i;
    LCD_Clear();
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //��������
    LCD_DrawImage1BPP(130 + 200 + 24, 130 - 85, BMP_Battery, WHITE, BLACK); //���
    LCD_DrawImage1BPP(130 + 200 + 50 + 24, 130 - 85, BMP_Message, WHITE, BLACK); //��Ϣ
    //�ָ�
    LCD_DrawRect(80, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320 + 320, 90, 1, 380, GREEN);
    for (i = 0; i < 11; i++)
        LCD_DrawRect(80, 90 + i * 38, 640, 1, GREEN);

    LCD_DrawImage1BPP(82, 100 + 38 * 0, BMP_DC, WHITE, BLACK); //���
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 0, BMP_Xiang_BMS, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 42 + 21, 100 + 38 * 0, BMP_Hao, WHITE, BLACK); //��

    LCD_DrawImage1BPP(82, 100 + 38 * 1, BMP_Dan, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 21, 100 + 38 * 1, BMP_Ti, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 21 + 21, 100 + 38 * 1, BMP_DY, WHITE, BLACK); //��ѹ
    LCD_DrawImage1BPP(82 + 21 + 21 + 42, 100 + 38 * 1, BMP_Caiji, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 21 + 21 + 42 + 42, 100 + 38 * 1, BMP_Shuliang, WHITE, BLACK); //����

    LCD_DrawImage1BPP(82, 100 + 38 * 2, BMP_Zui, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 21, 100 + 38 * 2, BMP_Gao, WHITE, BLACK); // ��
    LCD_DrawImage1BPP(82 + 21 + 21, 100 + 38 * 2, BMP_Dan, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 21 + 21 + 21, 100 + 38 * 2, BMP_Ti, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 21 + 21 + 21 + 21, 100 + 38 * 2, BMP_DY, WHITE, BLACK); //��ѹ
    LCD_DrawImage1BPP(400 - 24, 100 + 38 * 2, BMP_v, WHITE, BLACK); //V

    LCD_DrawImage1BPP(82, 100 + 38 * 3, BMP_Zui, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 21, 100 + 38 * 3, BMP_Di, WHITE, BLACK); // ��
    LCD_DrawImage1BPP(82 + 21 + 21, 100 + 38 * 3, BMP_Dan, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 21 + 21 + 21, 100 + 38 * 3, BMP_Ti, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 21 + 21 + 21 + 21, 100 + 38 * 3, BMP_DY, WHITE, BLACK); //��ѹ
    LCD_DrawImage1BPP(400 - 24, 100 + 38 * 3, BMP_v, WHITE, BLACK); //V



    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 1, BMP_Dan, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 320 + 21, 100 + 38 * 1, BMP_Ti, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 320 + 21 + 21, 100 + 38 * 1, BMP_Wendu, WHITE, BLACK); //�¶�
    LCD_DrawImage1BPP(82 + 320 + 21 + 21 + 42, 100 + 38 * 1, BMP_Caiji, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 320 + 21 + 21 + 42 + 42, 100 + 38 * 1, BMP_Shuliang, WHITE, BLACK); //����

    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 2, BMP_Zui, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 320 + 21, 100 + 38 * 2, BMP_Gao, WHITE, BLACK); // ��
    LCD_DrawImage1BPP(82 + 320 + 21 + 21, 100 + 38 * 2, BMP_Dan, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 320 + 21 + 21 + 21, 100 + 38 * 2, BMP_Ti, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 320 + 21 + 21 + 21 + 21, 100 + 38 * 2, BMP_Wendu, WHITE, BLACK); //�¶�
    LCD_DrawImage1BPP(720 - 24, 100 + 38 * 2, BMP_T, WHITE, BLACK); //��

    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 3, BMP_Zui, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 320 + 21, 100 + 38 * 3, BMP_Di, WHITE, BLACK); // �� 
    LCD_DrawImage1BPP(82 + 320 + 21 + 21, 100 + 38 * 3, BMP_Dan, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 320 + 21 + 21 + 21, 100 + 38 * 3, BMP_Ti, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 320 + 21 + 21 + 21 + 21, 100 + 38 * 3, BMP_Wendu, WHITE, BLACK); //�¶�
    LCD_DrawImage1BPP(720 - 24, 100 + 38 * 3, BMP_T, WHITE, BLACK); //��

    /*LCD_DrawImage1BPP(50, 90, BMP_DC, WHITE, BLACK); //���
    LCD_DrawImage1BPP(50 + 42, 90, BMP_DY, WHITE, BLACK); //��ѹ
    LCD_DrawImage1BPP(50 + 42 + 42 + 15, 90 - 9, BMP_SZ_1[index], GREEN, BLACK);

    //���
    if (index == 1) {
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

    if (index == 2) {
        for (j = 0; j < 5; j++) {
            for (i = 0; i < 11; i++) {
                if (i < 9) {//д��Ÿ�λ
                    LCD_DrawImage1BPP(5 + 16 + 16 + j * 160, 46 + 70 + i * 36, BMP_SZ_1[i + 1], WHITE, BLACK);
                    LCD_DrawImage1BPP(5 + 16 + j * 160, 46 + 70 + i * 36, BMP_SZ_1[j + 5], WHITE, BLACK);
                } else {//д�����һ�б��
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
                } else {//д�����һ�б��
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
                } else {//д�����һ�б��
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
        LCD_DrawImage1BPP(50, 90, BMP_DC, WHITE, BLACK); //���
        LCD_DrawImage1BPP(50 + 42, 90, BMP_Wendu, WHITE, BLACK); //�¶�
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
                LCD_DrawImage1BPP(3 + 16 + 16 + 100 + j * 160, 46 + 70 + i * 36 + 8, BMP_T, YELLOW, BLACK);
            }
        }
    }

    if (index == 6) {
        LCD_DrawImage1BPP(50, 90, BMP_DC, WHITE, BLACK); //���
        LCD_DrawImage1BPP(50 + 42, 90, BMP_Wendu, WHITE, BLACK); //�¶�
        LCD_DrawImage1BPP(50 + 42 + 42 + 15, 90 - 9, BMP_SZ_1[2], GREEN, BLACK);
        for (j = 0; j < 5; j++) {
            for (i = 0; i < 11; i++) {
                if (i < 9) {//д��Ÿ�λ
                    LCD_DrawImage1BPP(5 + 16 + 16 + j * 160, 46 + 70 + i * 36, BMP_SZ_1[i + 1], WHITE, BLACK);
                    LCD_DrawImage1BPP(5 + 16 + j * 160, 46 + 70 + i * 36, BMP_SZ_1[j + 5], WHITE, BLACK);
                } else {//д�����һ�б��
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
    /*for (i = 0; i < 4; i++) {
        LCD_DrawImage1BPP(82 - 50 - 10, 100 + 38 * i, BMP_Dan, WHITE, BLACK); //��
        LCD_DrawImage1BPP(82 - 50 - 10 + 21, 100 + 38 * i, BMP_Ti, WHITE, BLACK); //��
        LCD_DrawImage1BPP(82 - 50 - 10 + 21 + 21, 100 + 38 * i, BMP_Zui, WHITE, BLACK); //��
        LCD_DrawImage1BPP(82 - 50 - 10 + 21 + 21 + 21, 100 + 38 * i, BMP_Gao, WHITE, BLACK); //��
        LCD_DrawImage1BPP(82 - 50 - 10 + 21 + 21 + 21 + 21, 100 + 38 * i, BMP_DY, WHITE, BLACK); //��ѹ
        LCD_DrawImage1BPP(82 - 50 - 10 + 21 + 21 + 21 + 21 + 42, 100 - 8 + 38 * i, BMP_SZ_1[1 + i], WHITE, BLACK); //1
        LCD_DrawImage1BPP(400 - 50 - 10 - 24 - 63, 100 + 38 * i, BMP_v, WHITE, BLACK); //V

        LCD_DrawImage1BPP(82 - 50 - 10 + 42 * 7, 100 + 38 * i, BMP_Xiang_BMS, WHITE, BLACK); //��

        LCD_DrawImage1BPP(82 - 50 + 42 * 8.5, 100 + 38 * i, BMP_Hao, WHITE, BLACK); //��
    }
    for (i = 0; i < 4; i++) {
        LCD_DrawImage1BPP(82 - 50 - 10, 100 + 38 * 4 + 38 * i, BMP_Dan, WHITE, BLACK); //��
        LCD_DrawImage1BPP(82 - 50 - 10 + 21, 100 + 38 * 4 + 38 * i, BMP_Ti, WHITE, BLACK); //��
        LCD_DrawImage1BPP(82 - 50 - 10 + 21 + 21, 100 + 38 * 4 + 38 * i, BMP_Zui, WHITE, BLACK); //��
        LCD_DrawImage1BPP(82 - 50 - 10 + 21 + 21 + 21, 100 + 38 * 4 + 38 * i, BMP_Di, WHITE, BLACK); //��
        LCD_DrawImage1BPP(82 - 50 - 10 + 21 + 21 + 21 + 21, 100 + 38 * 4 + 38 * i, BMP_DY, WHITE, BLACK); //��ѹ
        LCD_DrawImage1BPP(82 - 50 - 10 + 21 + 21 + 21 + 21 + 42, 100 - 8 + 38 * 4 + 38 * i, BMP_SZ_1[1 + i], WHITE, BLACK); //1
        LCD_DrawImage1BPP(400 - 50 - 10 - 24 - 63, 100 + 38 * 4 + 38 * i, BMP_v, WHITE, BLACK); //V

        LCD_DrawImage1BPP(82 - 50 - 10 + 42 * 7, 100 + 38 * 4 + 38 * i, BMP_Xiang_BMS, WHITE, BLACK); //��

        LCD_DrawImage1BPP(82 - 50 + 42 * 8.5, 100 + 38 * 4 + 38 * i, BMP_Hao, WHITE, BLACK); //��
    }
    for (i = 0; i < 4; i++) {
        LCD_DrawImage1BPP(82 + 380 - 50, 100 + 38 * i, BMP_Dan, WHITE, BLACK); //��
        LCD_DrawImage1BPP(82 + 380 - 50 + 21, 100 + 38 * i, BMP_Ti, WHITE, BLACK); //��
        LCD_DrawImage1BPP(82 + 380 - 50 + 21 + 21, 100 + 38 * i, BMP_Zui, WHITE, BLACK); //��
        LCD_DrawImage1BPP(82 + 380 - 50 + 21 + 21 + 21, 100 + 38 * i, BMP_Gao, WHITE, BLACK); //��
        LCD_DrawImage1BPP(82 + 380 - 50 + 21 + 21 + 21 + 21, 100 + 38 * i, BMP_Wendu, WHITE, BLACK); //�¶�
        LCD_DrawImage1BPP(82 + 380 - 50 + 21 + 21 + 21 + 21 + 42, 100 - 8 + 38 * i, BMP_SZ_1[1 + i], WHITE, BLACK); //1
        LCD_DrawImage1BPP(400 + 380 - 50 - 24 - 63, 100 + 38 * i, BMP_T, WHITE, BLACK); //��

        LCD_DrawImage1BPP(82 + 380 + 10 - 50 + 42 * 7, 100 + 38 * i, BMP_Xiang_BMS, WHITE, BLACK); //��
    }
    for (i = 0; i < 4; i++) {
        LCD_DrawImage1BPP(82 + 380 - 50, 100 + 38 * 4 + 38 * i, BMP_Dan, WHITE, BLACK); //��
        LCD_DrawImage1BPP(82 + 380 - 50 + 21, 100 + 38 * 4 + 38 * i, BMP_Ti, WHITE, BLACK); //��
        LCD_DrawImage1BPP(82 + 380 - 50 + 21 + 21, 100 + 38 * 4 + 38 * i, BMP_Zui, WHITE, BLACK); //��
        LCD_DrawImage1BPP(82 + 380 - 50 + 21 + 21 + 21, 100 + 38 * 4 + 38 * i, BMP_Di, WHITE, BLACK); //��
        LCD_DrawImage1BPP(82 + 380 - 50 + 21 + 21 + 21 + 21, 100 + 38 * 4 + 38 * i, BMP_Wendu, WHITE, BLACK); //�¶�
        LCD_DrawImage1BPP(82 + 380 - 50 + 21 + 21 + 21 + 21 + 42, 100 - 8 + 38 * 4 + 38 * i, BMP_SZ_1[1 + i], WHITE, BLACK); //1
        LCD_DrawImage1BPP(400 + 380 - 50 - 24 - 63, 100 + 38 * 4 + 38 * i, BMP_T, WHITE, BLACK); //��

        LCD_DrawImage1BPP(82 + 380 + 10 - 50 + 42 * 7, 100 + 38 * 4 + 38 * i, BMP_Xiang_BMS, WHITE, BLACK); //��
    }
    for (i = 0; i < 2; i++)
        LCD_DrawRect(80 - 50 - 10 + 390 * i, 90, 1, 380, GREEN);
    LCD_DrawRect(80 - 50 - 10 + 390 + 380, 90, 1, 380, GREEN);
    for (i = 0; i < 11; i++)
        LCD_DrawRect(80 - 50 - 10, 90 + i * 38, 640 + 120 + 10, 1, GREEN);*/
    /*
    LCD_DrawImage1BPP(82, 100, BMP_DC, WHITE, BLACK); //���
    LCD_DrawImage1BPP(82 + 42, 100, BMP_System, WHITE, BLACK); //ϵͳ
    LCD_DrawImage1BPP(82 + 42 + 42, 100, BMP_Zui, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 42 + 42 + 21, 100, BMP_Gao, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 42 + 42 + 42, 100, BMP_Yunxu, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 42 + 42 + 42 + 42, 100, BMP_DY, WHITE, BLACK); //��ѹ
    LCD_DrawImage1BPP(400 - 24, 100, BMP_v, WHITE, BLACK); //V
    
    LCD_DrawImage1BPP(82, 100 + 38, BMP_DC, WHITE, BLACK); //���
    LCD_DrawImage1BPP(82 + 42, 100 + 38, BMP_System, WHITE, BLACK); //ϵͳ
    LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38, BMP_Zui, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 42 + 42 + 21, 100 + 38, BMP_Di, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 42 + 42 + 42, 100 + 38, BMP_Yunxu, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 42 + 42 + 42 + 42 , 100 + 38, BMP_DY, WHITE, BLACK); //��ѹ
    LCD_DrawImage1BPP(400 - 24, 100 + 38, BMP_v, WHITE, BLACK); //V

    LCD_DrawImage1BPP(82, 100 + 38 * 2, BMP_Dan, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 21, 100 + 38 * 2, BMP_Ti, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 2, BMP_Zui, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 42 + 21, 100 + 38 * 2, BMP_Gao, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 2, BMP_Yunxu, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 42 + 42 + 42, 100 + 38 * 2, BMP_DY, WHITE, BLACK); //��ѹ
    LCD_DrawImage1BPP(400 - 24, 100 + 38 * 2, BMP_v, WHITE, BLACK); //V

    LCD_DrawImage1BPP(82, 100 + 38 * 3, BMP_Dan, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 21, 100 + 38 * 3, BMP_Ti, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 3, BMP_Zui, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 42 + 21, 100 + 38 * 3, BMP_Di, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 3, BMP_Yunxu, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 42 + 42 + 42, 100 + 38 * 3, BMP_DY, WHITE, BLACK); //��ѹ
    LCD_DrawImage1BPP(400 - 24, 100 + 38 * 3, BMP_v, WHITE, BLACK); //V
        
    LCD_DrawImage1BPP(82, 100 + 38 * 4, BMP_Zui, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 21, 100 + 38 * 4, BMP_Gao, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 4, BMP_Yunxu, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 4, BMP_Chong, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 42 + 42 + 21, 100 + 38 * 4, BMP_DY, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 42 + 42 + 42, 100 + 38 * 4, BMP_DL, WHITE, BLACK); //����
    LCD_DrawImage1BPP(400 - 24, 100 + 38 * 4, BMP_a, WHITE, BLACK); //A

    LCD_DrawImage1BPP(82, 100 + 38 * 5, BMP_Zui, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 21, 100 + 38 * 5, BMP_Gao, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 5, BMP_Yunxu, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 5, BMP_Fang, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 42 + 42 + 21, 100 + 38 * 5, BMP_DY, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 42 + 42 + 42, 100 + 38 * 5, BMP_DL, WHITE, BLACK); //����
    LCD_DrawImage1BPP(400 - 24, 100 + 38 * 5, BMP_a, WHITE, BLACK); //A
    
    LCD_DrawImage1BPP(82, 100 + 38 * 6, BMP_Zui, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 21, 100 + 38 * 6, BMP_Gao, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 6, BMP_Yunxu, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 6, BMP_s, WHITE, BLACK); //S
    LCD_DrawImage1BPP(82 + 42 + 42 + 11, 100 + 38 * 6, BMP_o, WHITE, BLACK); //O
    LCD_DrawImage1BPP(82 + 42 + 42 + 11 + 11, 100 + 38 * 6, BMP_c, WHITE, BLACK); //C
    LCD_DrawImage1BPP(400 - 24, 100 + 38 * 6, BMP_Baifenhao, WHITE, BLACK); //%
    
    LCD_DrawImage1BPP(82, 100 + 38 * 7, BMP_Zui, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 21, 100 + 38 * 7, BMP_Di, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 7, BMP_Yunxu, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 7, BMP_s, WHITE, BLACK); //S
    LCD_DrawImage1BPP(82 + 42 + 42 + 11, 100 + 38 * 7, BMP_o, WHITE, BLACK); //O
    LCD_DrawImage1BPP(82 + 42 + 42 + 11 + 11, 100 + 38 * 7, BMP_c, WHITE, BLACK); //C
    LCD_DrawImage1BPP(400 - 24, 100 + 38 * 7, BMP_Baifenhao, WHITE, BLACK); //%
    
    LCD_DrawImage1BPP(82, 100 + 38 * 8, BMP_Zui, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 21, 100 + 38 * 8, BMP_Gao, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 8, BMP_Yunxu, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 8, BMP_Fang, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 42 + 42 + 21, 100 + 38 * 8, BMP_DY, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 42 + 42 + 42, 100 + 38 * 8, BMP_Gonglv, WHITE, BLACK); //����
    LCD_DrawImage1BPP(400 - 24 - 11, 100 + 38 * 8, BMP_k, WHITE, BLACK); //kw
    LCD_DrawImage1BPP(400 - 24, 100 + 38 * 8, BMP_w, WHITE, BLACK); 
    
    LCD_DrawImage1BPP(82, 100 + 38 * 9, BMP_Zui, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 21, 100 + 38 * 9, BMP_Gao, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 9, BMP_Yunxu, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 9, BMP_Chong, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 42 + 42 + 21, 100 + 38 * 9, BMP_DY, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 42 + 42 + 42, 100 + 38 * 9, BMP_Gonglv, WHITE, BLACK); //����
    LCD_DrawImage1BPP(400 - 24 - 11, 100 + 38 * 9, BMP_k, WHITE, BLACK); //kw
    LCD_DrawImage1BPP(400 - 24, 100 + 38 * 9, BMP_w, WHITE, BLACK); 
    
    LCD_DrawImage1BPP(82 + 320, 100, BMP_Zui, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 320 + 21, 100, BMP_Gao, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 320 + 42, 100, BMP_Yunxu, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 320 + 42 + 42, 100, BMP_Dan, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 320 + 42 + 42 + 21, 100, BMP_Ti, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 320 + 42 + 42 + 42, 100, BMP_Wendu, WHITE, BLACK); //�¶�
    LCD_DrawImage1BPP(720 - 24, 100, BMP_T, WHITE, BLACK); //��
    
    LCD_DrawImage1BPP(82 + 320, 100 + 38, BMP_Zui, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 320 + 21, 100 + 38, BMP_Di, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38, BMP_Yunxu, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 320 + 42 + 42, 100 + 38, BMP_Dan, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 320 + 42 + 42 + 21, 100 + 38, BMP_Ti, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 320 + 42 + 42 + 42, 100 + 38, BMP_Wendu, WHITE, BLACK); //�¶�
    LCD_DrawImage1BPP(720 - 24, 100 + 38, BMP_T, WHITE, BLACK); //��       
    
    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 2, BMP_DC, WHITE, BLACK); //���
    LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 2, BMP_Zhuangtai, WHITE, BLACK); //״̬

    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 3, BMP_Guzhang, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 3, BMP_Zhuangtai, WHITE, BLACK); //״̬

    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 4, BMP_Junheng, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 320+42, 100 + 38 * 4, BMP_Suoding, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 320 +42+ 42, 100 + 38 * 4, BMP_Zhuangtai, WHITE, BLACK); //״̬
    
    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 5, BMP_Guzhang, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 320+42, 100 + 38 * 5, BMP_Suoding, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 320 +42+ 42, 100 + 38 * 5, BMP_Zhuangtai, WHITE, BLACK); //״̬
     */
    /*
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
    }*/

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

void BatteryUpdate(unsigned char index) {

    print_SZ_1(82 + 200 + 20, 100 - 8 + 38 * 0, BAT_Case, 3, 0, GREEN);
    print_SZ_1(82 + 200 + 20, 100 - 8 + 38 * 1, BAT_Case_Voltage_Number, 3, 0, WHITE);
    print_SZ_1(82 + 200 + 20 - 16, 100 - 8 + 38 * 2, BAT_Case_Voltage_H * 2, 3, 2, WHITE);
    print_SZ_1(82 + 200 + 20 - 16, 100 - 8 + 38 * 3, BAT_Case_Voltage_L * 2, 3, 2, WHITE);

    print_SZ_1(82 + 200 + 320 + 20 - 16, 100 - 8 + 38 * 1, BAT_Case_Temp_Number, 3, 0, WHITE);
    updata_DAT(82 + 200 + 300 + 20, 100 - 8 + 38 * 2, BAT_Case_Temp_H, 1, 40, WHITE, 3, 0);
    updata_DAT(82 + 200 + 300 + 20, 100 - 8 + 38 * 3, BAT_Case_Temp_L, 1, 40, WHITE, 3, 0);

    /*if (index == 1) {
        for (j = 0; j < 5; j++) {
            for (i = 0; i < 10; i++) {
                if (BAT_Cell_Voltage[j * 10 + i] == 0)
                    print_SZ_1(60 + j * 160, 46 + 70 + 36 * i, BAT_Cell_Voltage[j * 10 + i], 4, 3, RED);
                else print_SZ_1(60 + j * 160, 46 + 70 + 36 * i, BAT_Cell_Voltage[j * 10 + i], 4, 3, GREEN); //�����ѹ
            }
        }
    }

    if (index == 2) {
        for (j = 0; j < 5; j++) {
            for (i = 0; i < 10; i++) {
                if (BAT_Cell_Voltage[50 + j * 10 + i] == 0)
                    print_SZ_1(60 + j * 160, 46 + 70 + 36 * i, BAT_Cell_Voltage[50 + j * 10 + i], 4, 3, RED);
                else print_SZ_1(60 + j * 160, 46 + 70 + 36 * i, BAT_Cell_Voltage[50 + j * 10 + i ], 4, 3, GREEN); //�����ѹ
            }
        }
    }

    if (index == 3) {
        for (j = 0; j < 5; j++) {
            for (i = 0; i < 10; i++) {
                if (BAT_Cell_Voltage[100 + j * 10 + i + 1] == 0)
                    print_SZ_1(60 + j * 160, 46 + 70 + 36 * i, BAT_Cell_Voltage[100 + j * 10 + i], 4, 3, RED);
                else print_SZ_1(60 + j * 160, 46 + 70 + 36 * i, BAT_Cell_Voltage[100 + j * 10 + i], 4, 3, GREEN); //�����ѹ
            }
        }
    }

    if (index == 4) {
        for (j = 0; j < 5; j++) {
            for (i = 0; i < 10; i++) {
                if (BAT_Cell_Voltage[150 + j * 10 + i] == 0)
                    print_SZ_1(60 + j * 160, 46 + 70 + 36 * i, BAT_Cell_Voltage[150 + j * 10 + i], 4, 3, RED);
                else print_SZ_1(60 + j * 160, 46 + 70 + 36 * i, BAT_Cell_Voltage[150 + j * 10 + i], 4, 3, GREEN); //�����ѹ
            }
        }
    }

    if (index == 5) {
        for (j = 0; j < 5; j++) {
            for (i = 0; i < 10; i++) {
                if (BAT_Cell_Temperature[j * 10 + i] == 0)
                    updata_DAT(60 + 23 + 42 + j * 160 - 40, 46 + 70 + 36 * i, BAT_Cell_Temperature[j * 10 + i], 1, 40, RED, 3, 0); //�����¶�
                else updata_DAT(60 + 23 + 42 + j * 160 - 40, 46 + 70 + 36 * i, BAT_Cell_Temperature[j * 10 + i], 1, 40, GREEN, 3, 0); //�����¶�
            }
        }
    }

    if (index == 6) {
        for (j = 0; j < 5; j++) {
            for (i = 0; i < 10; i++) {
                if (BAT_Cell_Temperature[j * 10 + i] == 0)
                    updata_DAT(60 + 23 + 42 + j * 160 - 40, 46 + 70 + 36 * i, BAT_Cell_Temperature[50 + j * 10 + i], 1, 40, RED, 3, 0); //�����¶�
                else updata_DAT(60 + 23 + 42 + j * 160 - 40, 46 + 70 + 36 * i, BAT_Cell_Temperature[50 + j * 10 + i], 1, 40, GREEN, 3, 0); //�����¶�
            }
        }
    }*/
    /*for (i = 0; i < 4; i++) {
        print_SZ_1(82 + 200 + 280 - 380-10, 100 - 8 + 38 * i, BAT_Max_Cell_Voltage, 4, 3, YELLOW);
        print_SZ_1(82 + 200 + 280 - 380 -10+ 16 * 7-16, 100 - 8 + 38 * i, BAT_Max_Cell_Voltage_Cell_Case, 3, 0, YELLOW);
        print_SZ_1(82 + 200 + 280 - 380 + 16 * 11-16, 100 - 8 + 38 * i, BAT_Max_Cell_Voltage_Cell_Number, 3, 0, YELLOW);
    }
    for (i = 0; i < 4; i++) {
        print_SZ_1(82 + 200 + 280 - 380-10, 100 - 8 + 38 * (i + 4), BAT_Min_Cell_Voltage[i], 4, 3, YELLOW);
        print_SZ_1(82 + 200 + 280 - 380 -10+ 16 * 7-16, 100 - 8 + 38 * (i + 4), BAT_Min_Cell_Voltage_Cell_Case[i], 3, 0, YELLOW);
        print_SZ_1(82 + 200 + 280 - 380 + 16 * 11-16, 100 - 8 + 38 * (i + 4), BAT_Min_Cell_Voltage_Cell_Number[i], 3, 0, YELLOW);
    }

    for (i = 0; i < 4; i++) {
        updata_DAT(82 + 200 + 310, 100 - 8 + 38 * i, BAT_Max_Cell_Temperature[i], 1, 40, YELLOW, 3, 0);
        print_SZ_1(82 + 200 + 280+10 + 16 * 7-16, 100 - 8 + 38 * i, BAT_Max_Cell_Temp_Cell_Case[i], 3, 0, YELLOW);
    }
    for (i = 0; i < 4; i++) {
        updata_DAT(82 + 200 + 310, 100 - 8 + 38 * (i + 4), BAT_Min_Cell_Temperature[i], 1, 40, YELLOW, 3, 0);
        print_SZ_1(82 + 200 + 280 +10+ 16 * 7-16, 100 - 8 + 38 * (i + 4), BAT_Min_Cell_Temp_Cell_Case[i], 3, 0, YELLOW);
    }*/
}

void frmBattery(void) {
    static unsigned char index_BAT = 1;
    if (f_index == 0) { //ֻ����һ��
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
        if (index_BAT == 2) {
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

    if (key_set) {//����������
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
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //��������
    LCD_DrawImage1BPP(130 + 200 - 2, 130 - 85, BMP_Gaoya, WHITE, BLACK); //��ѹ
    LCD_DrawImage1BPP(130 + 200 + 50 - 2, 130 - 85, BMP_STSTEM, WHITE, BLACK); //ϵͳ
    LCD_DrawImage1BPP(130 + 200 + 50 + 50 - 2, 130 - 85, BMP_Message, WHITE, BLACK); //��Ϣ

    LCD_DrawRect(80, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320 + 320, 90, 1, 380, GREEN);
    for (i = 0; i < 11; i++)
        LCD_DrawRect(80, 90 + i * 38, 640, 1, GREEN);

    LCD_DrawImage1BPP(82, 100, BMP_Dengji, WHITE, BLACK);
    LCD_DrawImage1BPP(82, 100, BMP_Zheng, WHITE, BLACK); //�����Ӵ���״̬

    LCD_DrawImage1BPP(82, 100 + 38, BMP_Dengji, WHITE, BLACK);
    LCD_DrawImage1BPP(82, 100 + 38, BMP_Fu, WHITE, BLACK); //�����Ӵ���״̬

    LCD_DrawImage1BPP(82, 100 + 38 * 2, BMP_Dengji, WHITE, BLACK);
    LCD_DrawImage1BPP(82, 100 + 38 * 2, BMP_Zheng, WHITE, BLACK); //����Ԥ��Ӵ���״̬
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 2, BMP_Yuchong, WHITE, BLACK);

    LCD_DrawImage1BPP(82, 100 + 38 * 3, BMP_Dengji, WHITE, BLACK);
    LCD_DrawImage1BPP(82, 100 + 38 * 3, BMP_Fu, WHITE, BLACK); //����Ԥ��Ӵ���״̬
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 3, BMP_Yuchong, WHITE, BLACK);

    LCD_DrawImage1BPP(82, 100 + 38 * 4, BMP_Chushuang, WHITE, BLACK); //��˪�Ӵ���״̬

    LCD_DrawImage1BPP(82, 100 + 38 * 5, BMP_Kongtiao, WHITE, BLACK); //�յ��Ӵ���״̬

    LCD_DrawImage1BPP(82, 100 + 38 * 6, BMP_Jiasu, WHITE, BLACK); //���ȽӴ���״̬
    LCD_DrawImage1BPP(82 + 21, 100 + 38 * 6, BMP_Ji, WHITE, BLACK);

    LCD_DrawImage1BPP(82, 100 + 38 * 7, BMP_Re, WHITE, BLACK); //�ȷ�Ӵ���״̬
    LCD_DrawImage1BPP(82 + 21, 100 + 38 * 7, BMP_Feng, WHITE, BLACK);

    LCD_DrawImage1BPP(82, 100 + 38 * 8, BMP_IC_Qian, WHITE, BLACK); //ǰ�˵�ѹ
    LCD_DrawImage1BPP(82 + 21, 100 + 38 * 8, BMP_Duan, WHITE, BLACK);
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 8, BMP_DY, WHITE, BLACK);
    LCD_DrawImage1BPP(400 - 24, 100 - 2 + 38 * 8, BMP_v, WHITE, BLACK); //V

    LCD_DrawImage1BPP(82, 100 + 38 * 9, BMP_Life, WHITE, BLACK); //LIFE

    for (i = 0; i < 8; i++) {
        if (i == 2 || i == 3) {
            LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * i, BMP_Jiechuqi, WHITE, BLACK);
            LCD_DrawImage1BPP(82 + 42 + 42 + 63, 100 + 38 * i, BMP_Zhuangtai, WHITE, BLACK);
        } else {
            LCD_DrawImage1BPP(82 + 21 + 21, 100 + 38 * i, BMP_Jiechuqi, WHITE, BLACK);
            LCD_DrawImage1BPP(82 + 42 + 63, 100 + 38 * i, BMP_Zhuangtai, WHITE, BLACK);
        }
    }

    for (i = 0; i < 8; i++) {
        LCD_DrawImage1BPP(82 + 320, 100 + 38 * i, BMP_Jiechuqi, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 63 + 320, 100 + 38 * i, BMP_Zhuangtai, WHITE, BLACK);
        print_SZ_2(82 + 63 + 42 + 320, 100 + 38 * i, i + 1, 1, 0, WHITE);
    }

    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 8, BMP_IC_Hou, WHITE, BLACK); //��˵�ѹ
    LCD_DrawImage1BPP(82 + 21 + 320, 100 + 38 * 8, BMP_Duan, WHITE, BLACK);
    LCD_DrawImage1BPP(82 + 42 + 320, 100 + 38 * 8, BMP_DY, WHITE, BLACK);
    LCD_DrawImage1BPP(720 - 24, 100 - 2 + 38 * 8, BMP_v, WHITE, BLACK); //V
}

void AirUpdate(void) {

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
        frmID = 1;
        f_index = 0;
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

/*void AirFrame(void) {
    unsigned char i = 0;
    LCD_Clear();
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //��������
    LCD_DrawImage1BPP(130 + 200 - 2, 130 - 85, BMP_Gaoya, WHITE, BLACK); //��ѹ
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
    //LCD_DrawImage1BPP(82 + 42 + 42 + 42 + 2, 100 + 5, BMP_Maohao, WHITE, BLACK); //:

    LCD_DrawImage1BPP(82, 100 + 38, BMP_Kongtiao, WHITE, BLACK); //�յ�
    LCD_DrawImage1BPP(82 + 42, 100 + 38, BMP_Feng, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 42 + 21, 100 + 38, BMP_DJ, WHITE, BLACK); //���
    LCD_DrawImage1BPP(82 + 42 + 21 + 21, 100 + 38, BMP_Zhuangtai, WHITE, BLACK); //״̬
    //LCD_DrawImage1BPP(82 + 42 + 21 + 21 + 42 + 2, 100 + 5 + 38, BMP_Maohao, WHITE, BLACK); //:

    LCD_DrawImage1BPP(82, 100 + 38 * 2, BMP_Kongtiao, WHITE, BLACK); //�յ�
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 2, BMP_Gongzuo, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 2, BMP_Zhuangtai, WHITE, BLACK); //״̬
    //LCD_DrawImage1BPP(82 + 42 + 42 + 42 + 2, 100 + 5 + 38 * 2, BMP_Maohao, WHITE, BLACK); //:


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
    //LCD_DrawImage1BPP(82 + 320 + 42 + 42 + 42 + 2, 100 + 5 + 38, BMP_Maohao, WHITE, BLACK); //:
    LCD_DrawImage1BPP(720 - 28, 100 + 38, BMP_T, WHITE, BLACK); //��


    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 2, BMP_Sheding, WHITE, BLACK); //�趨
    LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 2, BMP_Wendu, WHITE, BLACK); //�¶�
    //LCD_DrawImage1BPP(82 + 320 + 42 + 42 + 2, 100 + 5 + 38 * 2, BMP_Maohao, WHITE, BLACK); //:
    LCD_DrawImage1BPP(720 - 28, 100 + 38 * 2, BMP_T, WHITE, BLACK); //��

}

void AirUpdate(void) {
    
    print_D(82 + 180, 100 - 8, Air_Status_Flag1); //�յ�������
    print_D(82 + 180, 100 - 8 + 38, Air_Status_Flag2); //�յ�����
    print_D(82 + 180, 100 - 8 + 38 * 2, Air_Status_Flag3); //�յ�״̬
    //print_SZ_1(82 + 270 - 10, 100 - 8 + 38 * 3, AC_LIFE, 3, 0, WHITE); //�յ�LIFE
    updata_T(82 + 63 + 42 + 80 + 32 + 320, 100 - 8, WHITE, Air_Indoor_t, 0.5, 30); //�����¶�
    updata_T(82 + 63 + 42 + 80 + 32 + 320, 100 - 8 + 38, WHITE, Air_Outdoor_t, 0.5, 30); //�����¶�
    updata_T(82 + 63 + 42 + 80 + 32 + 320, 100 - 8 + 38 * 2, WHITE, Air_Set_t, 0.5, 30); //�趨�¶�
    //print_D(82 + 180 + 320, 100 - 8 + 38 * 3, AC_req); //�յ�����
     
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
        frmID = 1;
        f_index = 0;
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

}*/

/******************************************************/
void SETFrame(void) {
    LCD_Clear();
    //unsigned char i;
    //unsigned char color = WHITE;
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //��������   
    LCD_DrawRect(0, 430 + 15, 800, 2, YELLOW); //�ײ�����   
    LCD_DrawImage1BPP(220, 195, Bmp_Licheng, WHITE, BLACK); //�ۼ����
    LCD_DrawImage1BPP(405, 190, BMP_HZ_KM, WHITE, BLACK); //��λ Km 
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
            frmCAR();
            break;
        case 4:
            frmDCDC();
            break;
        case 5:
            frmFAULT();
            break;
        case 6:
            frmBMS();
            break;
        case 7:
            frmBattery();
            break;
        case 8:
            frmIC();
            //frmAir();
            break;
        case 9:
            frmIC();
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



