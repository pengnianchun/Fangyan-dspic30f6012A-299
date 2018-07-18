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
void print_D(unsigned int x, unsigned int y, //��16������ʾ
        unsigned char dat, //��ʾ������ 
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
    LCD_DrawRect(0, 64+64, 800, 1, GRAY);
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
    LCD_DrawRect(0, 430, 800, 2, GREEN); //�ײ�����

    /*LCD_DrawImage1BPP(5, 400 - 65 + 40, BMP_Vv, WHITE, BLACK); //V
    LCD_DrawImage1BPP(5 + 20, 400 - 50 + 5+30 , Bmp_Xiadianchi, WHITE, BLACK); //С���
    

    LCD_DrawImage1BPP(800-180, 400 - 65 + 40, BMP_Tt, WHITE, BLACK); //T
    LCD_DrawImage1BPP(800-160, 400 - 50 + 5+30, Bmp_Xiadianchi, WHITE, BLACK); //С���
    
    */
    //LCD_DrawRect(0,70,800,3,YELLOW); //��������
    // LCD_DrawImage1BPPZOOM_4(336, 150, BMP_LOGO, BLUE, BLACK); //�ͳ�����
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
    
    LCD_DrawImage1BPP(60, 365 - 50 + 10, BMP_Dan, WHITE, BLACK); //�����ѹ
    LCD_DrawImage1BPP(60 + 21, 365 - 50 + 10, BMP_Ti, WHITE, BLACK);
    LCD_DrawImage1BPP(60 + 42, 365 - 50 + 10, BMP_DY, WHITE, BLACK);
    LCD_DrawImage1BPP(15 + 130, 318+38+8, BMP_v, WHITE, BLACK); //V
    LCD_DrawImage1BPP(15 + 130, 318+38*2+8, BMP_v, WHITE, BLACK); //V

    LCD_DrawImage1BPP(70 + 550, 365 - 50 + 10, BMP_Dan, WHITE, BLACK); //�����¶�
    LCD_DrawImage1BPP(70 + 550 + 21, 365 - 50 + 10, BMP_Ti, WHITE, BLACK);
    LCD_DrawImage1BPP(70 + 550 + 42, 365 - 50 + 10, BMP_Wendu, WHITE, BLACK);
    LCD_DrawImage1BPP(800 - 90, 318 + 10 + 38, BMP_T, WHITE, BLACK); //��
    LCD_DrawImage1BPP(800 - 90, 318 + 10 + 38 * 2, BMP_T, WHITE, BLACK); //��

    LCD_DrawImage1BPP(180 - 20 + 2, 365 - 50 + 10, BMP_DJ, WHITE, BLACK); //���
    LCD_DrawImage1BPP(180 - 20 + 2 + 43, 365 - 50 + 10, BMP_KZQ, WHITE, BLACK); //������
    LCD_DrawImage1BPP(225 + 83 + 83 - 22, 365 - 50 + 10, BMP_T, WHITE, BLACK); //��
    
    //LCD_DrawImage1BPP(20, 365 - 50 + 10, BMP_Licheng, WHITE, BLACK); //���

    LCD_DrawImage1BPP(225 + 83 + 83 + 2, 365 - 50 + 10, BMP_DJ, WHITE, BLACK); //���
    LCD_DrawImage1BPP(225 + 83 + 83 + 2 + 43, 365 - 50 + 10, BMP_Zhuansu, WHITE, BLACK); //ת��
    LCD_DrawImage1BPP(615 - 34, 365 - 50 + 10, BMP_RPM, WHITE, BLACK); //RPM

    LCD_DrawImage1BPP(225 + 83 + 83 + 2, 365 - 50 + 10 + 38, BMP_Zhengche, WHITE, BLACK); //����
    LCD_DrawImage1BPP(225 + 83 + 83 + 2 + 42, 365 - 50 + 10 + 38, BMP_Mode, WHITE, BLACK); //ģʽ
    //LCD_DrawImage1BPP(615 - 34, 365 - 50 + 10 + 38, BMP_n, WHITE, BLACK); //NM
    //LCD_DrawImage1BPP(615 - 34 + 16, 365 - 50 + 10 + 38, BMP_m, WHITE, BLACK); //


    LCD_DrawImage1BPP(180 - 20 + 2, 365 - 50 + 10 + 38, BMP_DJ, WHITE, BLACK); //���
    LCD_DrawImage1BPP(180 - 20 + 2 + 43, 365 - 50 + 10 + 38, BMP_Wendu, WHITE, BLACK); //�¶�
    LCD_DrawImage1BPP(225 + 83 + 83 - 22, 365 - 50 + 10 + 38, BMP_T, WHITE, BLACK); //��


    /*LCD_DrawImage1BPP(225 + 83 + 83 + 2, 365 - 50 + 10 + 38, BMP_System, WHITE, BLACK); //ϵͳ
    LCD_DrawImage1BPP(225 + 83 + 83 + 2 + 43, 365 - 50 + 10 + 38, BMP_Code, WHITE, BLACK); //����
    
    LCD_DrawImage1BPP(225 + 83 + 83 + 2, 365 - 50 + 10 + 38*2, BMP_s, WHITE, BLACK); //S
    LCD_DrawImage1BPP(225 + 83 + 83 + 2+ 11 , 365 - 50 + 10 + 38*2, BMP_p, WHITE, BLACK); //P
    LCD_DrawImage1BPP(225 + 83 + 83 + 2+ 11 + 11 , 365 - 50 + 10 + 38*2, BMP_n, WHITE, BLACK); //N
     */
    //LCD_DrawImage1BPP(225 + 83 + 83 + 2+ 11 + 11 + 11 + 2, 365 - 50 + 10 + 38*2, BMP_Maohao, WHITE, BLACK); //:

    //���
    LCD_DrawRect(55, 365 - 50, 680, 1, GREEN);
    LCD_DrawRect(55, 365 - 50, 1, 65 + 50, GREEN);
    LCD_DrawRect(735, 365 - 50, 1, 65 + 50, GREEN);
    LCD_DrawRect(180 - 20, 365 - 50, 350 + 85 + 20, 1, GREEN);
    LCD_DrawRect(180 - 20, 365 - 50, 1, 65 + 50, GREEN);
    LCD_DrawRect(225 + 83 + 83, 365 - 50, 1, 65 + 50 - 38, GREEN);
    LCD_DrawRect(615, 365 - 50, 1, 65 + 50, GREEN);
    LCD_DrawRect(180 - 20, 365 - 50 + 38, 350 + 85 + 20, 1, GREEN);
    LCD_DrawRect(180 - 20, 365 - 50 + 38 + 38, 350 + 85 + 20, 1, GREEN);

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
    LCD_DrawImage1BPP(2, 440 + 3, Bmp_ODO, YELLOW, BLACK); //�ۼ���� ODO  
    //print_SZ_4(2+64+4,440,9999999,7,1,WHITE);

    //LCD_DrawImage1BPPZOOM_4(16 * 6, 318 + 38+2, BMP_HZ_KM, WHITE, BLACK); //��λ Km
    LCD_DrawImage1BPPZOOM_4(210 - 16, 440, BMP_HZ_KM, WHITE, BLACK); //��λ Km

    LCD_DrawImage1BPP(240 + 300 + 30, 440 + 3, Bmp_TRIP, YELLOW, BLACK); //������� TRIF
    //print_SZ_4(240+80+4,440,9999,4,1,WHITE);
    //LCD_DrawImage1BPPZOOM_4(16 * 6, 318 + 38 * 2+2, BMP_HZ_KM, WHITE, BLACK); //��λ Km
    LCD_DrawImage1BPPZOOM_4(404 + 336 + 30, 440, BMP_HZ_KM, WHITE, BLACK); //��λ Km

}

void disp_miles(void) {//��ʾ���  
    print_SZ_1(2 + 64 + 4 + 10, 440 - 2, total_miles / 10, 7, 0, WHITE);
    print_SZ_1(240 + 80 + 4 + 330 + 30 - 16, 440 - 2, single_miles, 5, 1, WHITE); 
}

void disp_time(unsigned int x, unsigned int y, DATE dtimer) {
    unsigned char color = 0;
    static unsigned char color_back=0;
    if(color_back && (t==0)) {
        if (t_add) {//Сʱ���ã�ʮλ
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
        if (t_add) {//Сʱ���ã���λ
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
        if (t_add) {//�������ã�ʮλ
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
        if (t_add) {//�������ã���λ
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
    LCD_DrawImage1BPP(x + 28 * 2, y + 3, BMP_SMSZ[10], color, BLACK); //ð�� 
    
    if(time_flag){
        color_back=FLASH;
    }
    else {
        color_back=0;
        t=0;
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
            LCD_DrawImage1BPP(x+260 + 16 * 2, y, BMP_SZ_1[(dtimer.year >> 4)&0x0f], WHITE, GRAY);
        } else LCD_DrawImage1BPP(x+260 + 16 * 2, y, BMP_SZ_1[(dtimer.year >> 4)&0x0f], WHITE, BLACK);

        if (color_back && (t == 5)) {
            if (t_add) {//�����ã���λ
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
            if (t_add) {//�����ã�ʮλ
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
            if (t_add) {//�����ã���λ
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
            if (t_add) {//�����ã�ʮλ
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
            if (t_add) {//�����ã���λ
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

    if (1) color = RED;
    else color = GRAY;
    if (color_old[0] != color) {
        color_old[0] = color;
    //    LCD_DrawImage1BPP(6, 10, Bmp_baojing[15], color, BLACK); 
    }

    if (Oum_Warn==0x55) color = RED;
    else color = GRAY;
    if (color_old[1] != color) {
        color_old[1] = color;
        LCD_DrawImage1BPP(6 + 66, 10, Bmp_baojing[15], color, BLACK); //��Ե����
    }

    if (rKL11) color = RED;
    else color = GRAY;
    if (color_old[2] != color) {
        color_old[2] = color;
        LCD_DrawImage1BPP(6 + 66 * 2, 10, Bmp_baojing[3], color, BLACK); //�����
    }

    if (((BMS_SOC * 0.4) > 30) && IN23) color = GREEN;
    else color = GRAY;
    if (color_old[3] != color) {
        color_old[3] = color;
        LCD_DrawImage1BPP(6 + 66 * 3, 10, Bmp_baojing[4], color, BLACK); //AC�յ�
    }

    if (Kt_1) color = GREEN;
    else color = GRAY;
    if (color_old[4] != color) {
        color_old[4] = color;
        LCD_DrawImage1BPP(6 + 66 * 4, 10, Bmp_baojing[5], color, BLACK); //Kt���Ӵ���
    }

    if (rKL1) color = RED;
    else color = GRAY;
    if (color_old[5] != color) {
        color_old[5] = color;
        LCD_DrawImage1BPP(6 + 66*5, 10, Bmp_baojing[2], color, BLACK); //ˮλ

    }

    if (IN18) color = YELLOW;
    else color = GRAY;
    if (color_old[6] != color) {
        color_old[6] = color;
        LCD_DrawImage1BPP(6 + 66 * 6, 10, Bmp_baojing[1], color, BLACK); //ABS
    }

    if (!rKL4) color = RED;
    else color = GRAY;
    if (color_old[7] != color) {
        color_old[7] = color;
        LCD_DrawImage1BPP(6 + 66 * 7, 10, Bmp_baojing[7], color, BLACK); //��ɲ��Ƭ
    }

    if (!rKL2) color = RED;
    else color = GRAY;
    if (color_old[8] != color) {
        color_old[8] = color;
        LCD_DrawImage1BPP(6 + 66 * 8, 10, Bmp_baojing[8], color, BLACK); //��ɲ��Ƭ
    }

    if (mKL2) color = RED;
    else color = GRAY;
    if (color_old[9] != color) {
        color_old[9] = color;
        LCD_DrawImage1BPP(6 + 66 * 9, 10, Bmp_baojing[9], color, BLACK); //����
    }

    if (Car_Fault_Level)
        color = RED;
    else color = GRAY;
    if (color_old[10] != color) {
        color_old[10] = color;
        LCD_DrawImage1BPP(6 + 66 * 10, 10, Bmp_baojing[14], color, BLACK);//��������
    }

    //if (AC) color = GREEN;
    //else color = GRAY;
    //if (color_old[11] != color) {
    //    color_old[11] = color;
        //LCD_DrawImage1BPP(6 + 66 * 11, 10, Bmp_baojing[20], color, BLACK); //
    //}

    /*if (Tradition && !Hybrid && !Electric) color = GREEN;
    else color = GRAY;
    if (color_old[12] != color) {
        color_old[12] = color;
        if (color == GREEN) {
            LCD_DrawImage1BPP(138 + 9, 74, BMP_Chuantong, color, BLACK); //��ͳ
            LCD_DrawImage1BPP(138 + 9, 74 + 22, BMP_Mode, color, BLACK); //ģʽ
        }
    }

    if (!Tradition && Hybrid && !Electric) color = GREEN;
    else color = GRAY;
    if (color_old[13] != color) {
        color_old[13] = color;
        if (color == GREEN) {
            LCD_DrawImage1BPP(138 + 9, 74, BMP_Chadian, color, BLACK); //���
            LCD_DrawImage1BPP(138 + 9, 74 + 22, BMP_Mode, color, BLACK); //ģʽ
        }
    }

    if (!Tradition && !Hybrid && Electric) color = GREEN;
    else color = GRAY;
    if (color_old[14] != color) {
        color_old[14] = color;
        if (color == GREEN) {
            LCD_DrawImage1BPP(138 + 9, 74, BMP_Chundian, color, BLACK); //����
            LCD_DrawImage1BPP(138 + 9, 74 + 22, BMP_Mode, color, BLACK); //ģʽ
        }
    }

    if (!Tradition && !Hybrid && !Electric) {
        LCD_DrawImage1BPP(138 + 9, 74, BMP_Chundian, BLACK, BLACK); //����
        LCD_DrawImage1BPP(138 + 9, 74 + 22, BMP_Mode, BLACK, BLACK); //ģʽ
    }*/

    if (rKL3) color = RED;
    else color = GRAY;
    if (color_old[15] != color) {
        color_old[15] = color;
        LCD_DrawImage1BPP(138 + 66 * 1, 74, Bmp_baojing[10], color, BLACK); //ǰ��1Ӧ����
    }

    if (mKL4) color = RED;
    else color = GRAY;
    if (color_old[16] != color) {
        color_old[16] = color;
        LCD_DrawImage1BPP(138 + 66 * 2, 74, Bmp_baojing[11], color, BLACK); //ǰ��2Ӧ����
    }

    if (READY) color = GREEN;
    else color = GRAY;
    if (color_old[17] != color) {
        color_old[17] = color;
        LCD_DrawImage1BPP(138 + 66 * 3-1, 74+12, Bmp_READY, color, BLACK);//ready
    }

    if (rKL5) color = RED;
    else color = GRAY;
    if (color_old[18] != color) {
        color_old[18] = color;
        LCD_DrawImage1BPP(138 + 66 * 4, 74, Bmp_baojing[12], color, BLACK); //����1Ӧ����
    }

    if (mKL6) color = RED;
    else color = GRAY;
    if (color_old[19] != color) {
        color_old[19] = color;
        LCD_DrawImage1BPP(138 + 66 * 5, 74, Bmp_baojing[13], color, BLACK); //����2Ӧ����
    }

    if (!fKL5) color = RED;
    else color = GRAY;
    if (color_old[20] != color) {
        color_old[20] = color;
        //LCD_DrawImage1BPP(138 + 66 * 6, 74, Bmp_baojing[20], color, BLACK); //��ɲ��Ƭĥ��
    }
}

void disp_CAN_baojing(unsigned int x, unsigned int y) {
    static unsigned char al_index = 0;
    if (alarm_update_flag == 0) { //3S ����һ�� 
        //LCD_DrawRect(x, y, 350 + 85 + 10, 36, BLACK); //�����ʾ����
        switch (al_index) {
            case 0:
                al_index = 1;
                if (Fcan_count == CAN_TIME) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Qianbu, YELLOW, BLACK); //ǰ��
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Mokuai, YELLOW, BLACK); //ģ��
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Lixian, YELLOW, BLACK); //����
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 1:
                al_index = 2;
                if (Mcan_count == CAN_TIME) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Dingbu, YELLOW, BLACK); //����
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Mokuai, YELLOW, BLACK); //ģ��
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Lixian, YELLOW, BLACK); //����
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 2:
                al_index = 3;
                if (Rcan_count == CAN_TIME) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Houbu, YELLOW, BLACK); //��
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Mokuai, YELLOW, BLACK); //ģ��
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Lixian, YELLOW, BLACK); //����
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
            case 3:
                al_index = 4;
                if (BMS_COMM_FAULT) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_b, YELLOW, BLACK); //BMSͨѶ����
                    LCD_DrawImage1BPP(x + 11, y + 8, BMP_m, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11, y + 8, BMP_s, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11 + 11, y + 8, BMP_Tongxun, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11 + 11 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 11 + 11 + 11 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 4:
                al_index = 5;
                if (Battery_OverTemp) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DC, YELLOW, BLACK); //��ظ��±���
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Gao, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 21, y + 8, BMP_Wendu, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
            case 5:
                al_index = 6;
                if (Pole_OverTemp) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Jizhu, YELLOW, BLACK); //�������±���
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Gao, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 21, y + 8, BMP_Wendu, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 6:
                al_index = 7;
                if (Single_Bat_OverVoltage) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Dan, YELLOW, BLACK); //�����ѹ����
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_Ti, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 7:
                al_index = 8;
                if (Pack_Bat_OverVoltage) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DC, YELLOW, BLACK); //������ѹ����
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Zu, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 21, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 21, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 21 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 21 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 8:
                al_index = 9;
                if (Pack_Bat_UnderVoltage) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DC, YELLOW, BLACK); //�����Ƿѹ����
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Zu, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 21, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 21, y + 8, BMP_Qian, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 21 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 21 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
            case 9:
                al_index = 10;
                if (Single_Bat_UnderVoltage) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Dan, YELLOW, BLACK); //����Ƿѹ����
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_Ti, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Qian, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
            case 10:
                al_index = 11;
                if (Charge_Gun_OverTemp) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Chongdianqiang, YELLOW, BLACK); //���ǹ���±���
                    LCD_DrawImage1BPP(x + 63, y + 8, BMP_Gao, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 63 + 21, y + 8, BMP_Wendu, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 63 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 63 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
            case 11:
                al_index = 12;
                if (pSpeed > 69) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Chaosu, YELLOW, BLACK); //���ٱ���
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
            case 12:
                al_index = 13;
                if (Discharge_OverCurrent) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Fang, YELLOW, BLACK); //�ŵ��������
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_DL, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_DL, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
            case 13:
                al_index = 14;
                if (Charge_OverCurrent) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Chong, YELLOW, BLACK); //����������
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_DL, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_DL, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
            case 14:
                al_index = 15;
                if (Diff_Voltage) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Dan, YELLOW, BLACK); //�����ѹ���챨��
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_Ti, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Chayi, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
            case 15:
                al_index = 16;
                if (Diff_Temp) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Wendu, YELLOW, BLACK); //�¶Ȳ��챨��
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Chayi, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 16:
                al_index = 17;
                if (SOC_Low) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_s, YELLOW, BLACK); //SOC�ͱ���
                    LCD_DrawImage1BPP(x + 11, y + 8, BMP_o, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11, y + 8, BMP_c, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11 + 11, y + 8, BMP_Di, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11 + 11 + 21, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 11 + 11 + 11 + 21 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 17:
                al_index = 18;
                if (SOC_High) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_s, YELLOW, BLACK); //SOC�߱���
                    LCD_DrawImage1BPP(x + 11, y + 8, BMP_o, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11, y + 8, BMP_c, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11 + 11, y + 8, BMP_Gao, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11 + 11 + 21, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 11 + 11 + 11 + 21 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 18:
                al_index = 19;
                if (Diff_SOC) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_s, YELLOW, BLACK); //SOC���챨��
                    LCD_DrawImage1BPP(x + 11, y + 8, BMP_o, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11, y + 8, BMP_c, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11 + 11, y + 8, BMP_Chayi, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11 + 11 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 11 + 11 + 11 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 19:
                al_index = 20;
                if (Bat_LowTemp) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DC, YELLOW, BLACK); //��ص��±���
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Di, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 21, y + 8, BMP_Wendu, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 20:
                al_index = 21;
                if (BMS_FAULT_OTHER) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DC, YELLOW, BLACK); //���ϵͳ��������
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_System, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Qita, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 21:
                al_index = 22;
                if (BAT_COOL_FAULT) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DC, YELLOW, BLACK); //�����ȴϵͳ����
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Lengque, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_System, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 22:
                al_index = 23;
                if (WARN_FAULT) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Jiare, YELLOW, BLACK); //���ȹ���
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42, y, 150, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 23:
                al_index = 24;
                if (BALANCE_FAULT) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Junheng, YELLOW, BLACK); //���ⱨ��
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 24:
                al_index = 25;
                if (PRECHARGE_FAULT) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Chongdianqiang, YELLOW, BLACK); //��籨��
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 25:
                al_index = 26;
                if (CHARGER_COMM_FAULT) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Chongdianqiang, YELLOW, BLACK); //���ͨѶ����
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Tongxun, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 26:
                al_index = 27;
                if (BMU_OFFLINE) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_b, YELLOW, BLACK); //BMS�ӿ�����
                    LCD_DrawImage1BPP(x + 11, y + 8, BMP_m, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11, y + 8, BMP_s, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11 + 11, y + 8, BMP_Congkong, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11 + 11 + 42, y + 8, BMP_Lixian, YELLOW, BLACK);
                    LCD_DrawRect(x + 11 + 11 + 11 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 27:
                al_index = 28;
                if (BAT_FAULT) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Dongli, YELLOW, BLACK); //������ع���
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_DC, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 28:
                al_index = 29;
                if (VOLTAGE_DIFF_FAULT) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Zhilu, YELLOW, BLACK); //֧·��ѹ���챨��
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Chayi, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 29:
                al_index = 30;
                if (FIRE_FAULT) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Huozaijixian, YELLOW, BLACK); //���ּ��ޱ���
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 30:
                al_index = 31;
                if (SYSTEM_MISMATCH) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Chunnengxitong, YELLOW, BLACK); //����ϵͳ��ƥ��
                    LCD_DrawRect(x + 147, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 31:
                al_index = 32;
                if (SOC_JUMP) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_s, YELLOW, BLACK); //SOC����
                    LCD_DrawImage1BPP(x + 11, y + 8, BMP_o, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11, y + 8, BMP_c, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11 + 11, y + 8, BMP_Tiaobian, YELLOW, BLACK);
                    LCD_DrawRect(x + 11 + 11 + 11 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 32:
                al_index = 33;
                if (BAT_CELL_COLT_OFFLINE) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Dan, YELLOW, BLACK); //�����ѹ�ɼ�����
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_Ti, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Caiji, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 42, y + 8, BMP_Lixian, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 33:
                al_index = 34;
                if (TEMP_COLT_OFFLINE) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Wendu, YELLOW, BLACK); //�¶Ȳɼ�����                   
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Caiji, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Lixian, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
                
            case 34:
                al_index = 35;
                if (CHARGE_STATUS || CHARGE_PLUG) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Charging, YELLOW, BLACK); //���ڳ�磬��ֹ�г�                   
                    //LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
                case 35:
                al_index = 36;
                if (BAT24V_count == BAT24_TIME) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Xu, YELLOW, BLACK); //���ص�ѹ��
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_DC, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 42, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 42 + 42, y + 8, BMP_Di, YELLOW, BLACK);
                    LCD_DrawRect(x + 21 + 42 + 42 + 21, y, 100, 36, BLACK);
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
    unsigned int press2 = 90; /*��ѹ������������0-1.2Mpa ,��ӦΪ0-120 ������0-100*/
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
    print_SZ(33 - 7, 410, press1, 3, 2, color);
    LCD_DrawImage1BPP(33 + 9, 380, Bmp_QY1, color, BLACK); //��ѹ1ͼ��
    LCD_DrawRect(38, 102, 44, (260 - press1 * 2.6), BLACK); //260/100  
    LCD_DrawRect(38, (368 - press1 * 2.6), 44, (press1 * 2.6), color);

    if (ADR[2] < 10) press2 = 0;
    else if (ADR[2] <= 52) press2 = (ADR[2] - 10)*0.48;
    else if (ADR[2] <= 124) press2 = (ADR[2] - 52)*0.56 + 20;
    else if (ADR[2] <= 155) press2 = (ADR[2] - 124)*0.65 + 60;
    else press2 = (ADR[2] - 155)*0.69 + 80;

    if (press2 > 60) color = GREEN;
    else color = RED;
    if (press2 > 100) press2 = 100;
    LCD_DrawImage1BPP(712 + 9, 380, Bmp_QY2, color, BLACK); //��ѹ2ͼ��
    print_SZ(712 - 7, 410, press2, 3, 2, color);
    LCD_DrawRect(712 + 5, 102, 44, (260 - press2 * 2.6), BLACK); //260/100  
    LCD_DrawRect(712 + 5, (368 - press2 * 2.6), 44, (press2 * 2.6), color);

}

void updata_Dangwei(unsigned int x, unsigned int y) {
    unsigned char gear;
    if (Gear_N && !Gear_D && !Gear_R)
        gear = 0;
    else if (!Gear_N && Gear_D && !Gear_R)
        gear = 1;
    else if (!Gear_N && !Gear_D && Gear_R)
        gear = 2;
    else gear = 0;
    //if (gear > 3) gear = 0;
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
    if (BMS_V > 10000) DCDY = (BMS_V - 10000) * 0.1;
    else DCDY = 0;
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
    DCDL = BMS_A * 0.1;
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

void updata_DAT(unsigned int x, unsigned int y,//��������ֵ
        unsigned long dat, //��ʾ������ 
        float factor,//����
        unsigned int offset,
        unsigned char color1,//��ɫ
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
        print_SZ_1(x, y, DAT-offset, sum, dot, color1); //��ص�����ֵ x=135+180+50+100+20+20   y=150+60-2
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
    //unsigned char color;
    if (f_index == 0) { //ֻ����һ��
        f_index = 1;
        mainFrame();
    } else if (f_index == 1) {
        f_index = 2;
        print_SZ_1(60, 318 + 38, BAT_Max_Cell_Voltage[0], 4, 3, WHITE); //����ߵ�ѹ
        print_SZ_1(60, 318 + 38 * 2, BAT_Min_Cell_Voltage[0], 4, 3, WHITE); //����͵�ѹ
        updata_DAT(313, 318 + 38, Motor_Temperature, 1, 40, WHITE, 3, 0); //����¶�
    } else if (f_index == 2) {
        f_index = 3;
        disp_baojing();
        updata_DAT(480 + 30, 318, Moto_Rpm, 0.5, 0, WHITE, 4, 0); //���ת��
        print_SZ_1(480 + 30 + 16, 318 + 38, Car_Mode, 3, 0, WHITE); //����ģʽ
    } else if (f_index == 3) {
        f_index = 4;
        disp_miles();
        updata_DCDL(585, 155 + 60);
    } else if (f_index == 4) {
        f_index = 5;
        disp_time(330, 440, timer);
        updata_DAT(313, 318, Inverter_t, 1, 40, WHITE, 3, 0);//����������¶�
    } else if (f_index == 5) {
        f_index = 6;
        updata_SOC();
        updata_DAT(800 - 150, 318 + 38, BAT_Max_Cell_Temperature[0], 1, 40, WHITE, 3, 0); //�������
        updata_DAT(800 - 150, 318 + 38 * 2, BAT_Min_Cell_Temperature[0], 1, 40, WHITE, 3, 0); //�������
    } else if (f_index == 6) {
        f_index = 7;
        updata_DCDY(585, 155);
        disp_CAN_baojing(162, 394);
    } else if (f_index == 7) {
        f_index = 1;
        updata_Dangwei(138 + 15 + 66 * 6, 74);
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

        if (key_AV) {
            key_AV = 0;
            key_long_set = 0;
            key_up = 0;
            key_set = 0;
            if (time_flag)
            t_add = 1;
            else t_add = 0;
        }
    }
/***********************************************************/
    
    /*if (IN35 == 0) {//��������ѡ��ʹ�ܰ���
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
        LCD_DrawImage1BPP(130 + 200 + 200 + 11 + 11 + 11, 130 - 85 + 4, BMP_Tongxun, WHITE, BLACK);

        print_SZ_2(750, 50, 1, 1, 0, WHITE); // 1/4
        LCD_DrawImage1BPP(750 + 11, 50, BMP_I, WHITE, BLACK);
        print_SZ_2(750 + 11 + 14, 50, 4, 1, 0, WHITE);

        /***********************�Ǳ������ɼ�**********************************/
        //��ת��
        LCD_DrawImage1BPP(35, 75, BMP_IC_Zuo, WHITE, BLACK);
        LCD_DrawImage1BPP(35 + 21, 75, BMP_IC_Zhuanxiang, WHITE, BLACK);
        //����ź�
        LCD_DrawImage1BPP(35, 75 + 25 * 3, BMP_Chong, WHITE, BLACK);
        LCD_DrawImage1BPP(35 + 21, 75 + 25 * 3, BMP_DC, WHITE, BLACK);
        LCD_DrawImage1BPP(35 + 42, 75 + 25 * 3, BMP_IC_Xinhao, WHITE, BLACK);
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
        //˾����
        LCD_DrawImage1BPP(35, 75 + 25 * 10, BMP_IC_Siji, WHITE, BLACK);
        //������1
        LCD_DrawImage1BPP(35, 75 + 25 * 11, BMP_IC_Changtiao, WHITE, BLACK);
        print_SZ_2(35 + 105 + 6, 75 + 25 * 11, 1, 1, 0, WHITE);
        //������2
        LCD_DrawImage1BPP(35, 75 + 25 * 12, BMP_IC_Changtiao, WHITE, BLACK);
        print_SZ_2(35 + 105 + 6, 75 + 25 * 12, 2, 1, 0, WHITE);
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
            if (i == 0 || i == 4 || i == 6 || i == 7 || i == 8 || i == 9 || i == 10 || i == 11 || i == 12) {
                if (i != 0 && i != 4)
                    LCD_DrawImage1BPP(35 + 42, 75 + 25 * i, BMP_IC_Deng, WHITE, BLACK);
                LCD_DrawImage1BPP(35 + 63, 75 + 25 * i, BMP_IC_Kaiguan, WHITE, BLACK);
            } else if (i == 5) {
                LCD_DrawImage1BPP(35 + 21, 75 + 25 * i, BMP_IC_Deng, WHITE, BLACK);
                LCD_DrawImage1BPP(35 + 42, 75 + 25 * i, BMP_IC_Kaiguan, WHITE, BLACK);
            } else if (i == 13 || i == 15)
                LCD_DrawImage1BPP(35 + 84, 75 + 25 * i, BMP_IC_Kaiguan, WHITE, BLACK);
            else if (i == 14)
                LCD_DrawImage1BPP(35 + 105, 75 + 25 * i, BMP_IC_Kaiguan, WHITE, BLACK);
        }
        /*LCD_DrawImage1BPPZOOM_4(35, 75 + 25 * 1, Bmp_IN2, WHITE, BLACK);
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
        LCD_DrawImage1BPPZOOM_4(35, 75 + 25 * 15, Bmp_IN16, WHITE, BLACK);*/

        //ABS״̬
        LCD_DrawImage1BPP(285, 75 + 25 * 1, BMP_a, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 11, 75 + 25 * 1, BMP_b, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 11 + 11, 75 + 25 * 1, BMP_s, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 11 + 11 + 11, 75 + 25 * 1, BMP_Zhuangtai, WHITE, BLACK);
        //·��
        LCD_DrawImage1BPP(285, 75 + 25 * 2, BMP_Lupai, WHITE, BLACK);
        //ǰ�ſ�
        LCD_DrawImage1BPP(285, 75 + 25 * 3, BMP_IC_Qian, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 21, 75 + 25 * 3, BMP_Men, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 42, 75 + 25 * 3, BMP_Kai, WHITE, BLACK);
        //�����ˮ
        LCD_DrawImage1BPP(285, 75 + 25 * 4, BMP_IC_Yugua, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 42, 75 + 25 * 4, BMP_Penshui, WHITE, BLACK);
        //������
        LCD_DrawImage1BPP(285, 75 + 25 * 5, BMP_DC, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 21, 75 + 25 * 5, BMP_Laba, WHITE, BLACK);
        //�յ�
        LCD_DrawImage1BPP(285, 75 + 25 * 6, BMP_Kongtiao, WHITE, BLACK);
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

        /*LCD_DrawImage1BPPZOOM_4(285, 75, Bmp_IN17, WHITE, BLACK);
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
        LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 15, Bmp_IN32, WHITE, BLACK);*/
        //����
        for (i = 0; i < 16; i++) {
            if (i == 3 || i == 5 || i == 9 || i == 10 || i == 11) {
                LCD_DrawImage1BPP(285 + 63, 75 + 25 * i, BMP_IC_Kaiguan, WHITE, BLACK);
            } else if (i == 2 || i == 6) {
                LCD_DrawImage1BPP(285 + 42, 75 + 25 * i, BMP_IC_Kaiguan, WHITE, BLACK);
            } else if (i == 4)
                LCD_DrawImage1BPP(285 + 84, 75 + 25 * i, BMP_IC_Kaiguan, WHITE, BLACK);
        }

        //Σ�ձ�������
        LCD_DrawImage1BPP(535, 75 + 25 * 5, BMP_Weixian, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 42, 75 + 25 * 5, BMP_Baojing, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 84, 75 + 25 * 5, BMP_IC_Kaiguan, WHITE, BLACK);
        //��Դ����
        LCD_DrawImage1BPP(535, 75 + 25 * 6, BMP_Dianyuan, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 42, 75 + 25 * 6, BMP_Huanxing, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 84, 75 + 25 * 6, BMP_IC_Kaiguan, WHITE, BLACK);
        //Կ��ON����
        LCD_DrawImage1BPP(535, 75 + 25 * 7, BMP_o, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 11, 75 + 25 * 7, BMP_n, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 11 + 11, 75 + 25 * 7, BMP_Dang, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 11 + 11 + 21, 75 + 25 * 7, BMP_IC_Kaiguan, WHITE, BLACK);
        /*LCD_DrawImage1BPPZOOM_4(535, 75, Bmp_IN33, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(535, 75 + 25 * 1, Bmp_IN34, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(535, 75 + 25 * 2, Bmp_IN35, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(535, 75 + 25 * 3, Bmp_IN36, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(535, 75 + 25 * 4, Bmp_IN37, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(535, 75 + 25 * 5, Bmp_IN38, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(535, 75 + 25 * 6, Bmp_IN39, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(535, 75 + 25 * 7, Bmp_IN40, WHITE, BLACK);*/

        LCD_DrawImage1BPP(535, 75 + 25 * 10, BMP_IC_Qian, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 21, 75 + 25 * 10, BMP_Qiya, WHITE, BLACK);

        LCD_DrawImage1BPP(535, 75 + 25 * 11, BMP_IC_Hou, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 21, 75 + 25 * 11, BMP_Qiya, WHITE, BLACK);
        
        LCD_DrawImage1BPP(535, 75 + 25 * 14, BMP_Xu, YELLOW, BLACK); //���ص�ѹ
        LCD_DrawImage1BPP(535 + 21, 75 + 25 * 14, BMP_DC, YELLOW, BLACK);
        LCD_DrawImage1BPP(535 + 21 + 42, 75 + 25 * 14, BMP_DY, YELLOW, BLACK);
        LCD_DrawImage1BPP(535 + 63 + 42 + 16 * 4 + 16 * 5, 75 + 25 * 14, BMP_v, WHITE, BLACK); //V

        for (i = 8; i < 14; i++) {
            if (i != 10 && i != 11)
                LCD_DrawImage1BPP(535 + 21, 75 + 25 * i, BMP_Beiyong, WHITE, BLACK);
            LCD_DrawImage1BPP(535 + 63, 75 + 25 * i, BMP_Xinhao, WHITE, BLACK);
            LCD_DrawImage1BPP(535 + 63 + 42 + 16 * 4 - 4, 75 + 25 * i, BMP_Omu, WHITE, BLACK); //��
            LCD_DrawImage1BPP(535 + 63 + 42 + 16 * 4 + 16 * 5, 75 + 25 * i, BMP_v, WHITE, BLACK); //V
        }

        LCD_DrawImage1BPP(505 + 100, 75 + 8 + 25 * 15, BMP_Banben, WHITE, BLACK);
        LCD_DrawImage1BPP(505 + 100 + 42, 75 + 8 + 25 * 15, BMP_Hao, WHITE, BLACK);
        LCD_DrawImage1BPP(505 + 200, 75 + 25 * 15, BMP_V, WHITE, BLACK);
    } else if (index == 2) {
        print_SZ_2(750, 50, 2, 1, 0, WHITE); // 2/4
        LCD_DrawImage1BPP(750 + 11, 50, BMP_I, WHITE, BLACK);
        print_SZ_2(750 + 11 + 14, 50, 4, 1, 0, WHITE);

        LCD_DrawImage1BPP(130 + 200 + 200, 130 - 85 + 4, BMP_c, WHITE, BLACK);
        LCD_DrawImage1BPP(130 + 200 + 200 + 11, 130 - 85 + 4, BMP_a, WHITE, BLACK);
        LCD_DrawImage1BPP(130 + 200 + 200 + 11 + 11, 130 - 85 + 4, BMP_n, WHITE, BLACK);
        LCD_DrawImage1BPP(130 + 200 + 200 + 11 + 11 + 11, 130 - 85 + 4, BMP_Tongxun, WHITE, BLACK);

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
        //�յ���Դ
        LCD_DrawImage1BPP(60, 75 + 25 * 4, BMP_Kongtiao, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 4, BMP_Dianyuan, WHITE, BLACK);
        //��ת���
        LCD_DrawImage1BPP(60, 75 + 25 * 5, BMP_IC_You, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 5, BMP_IC_Zhuanxiang, WHITE, BLACK);
        //��ת���
        LCD_DrawImage1BPP(60, 75 + 25 * 6, BMP_IC_Zuo, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 6, BMP_IC_Zhuanxiang, WHITE, BLACK);
        //���ſ����
        LCD_DrawImage1BPP(60, 75 + 25 * 7, BMP_Zhong, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 7, BMP_Men, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 7, BMP_Kai, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 63, 75 + 25 * 7, BMP_Output, WHITE, BLACK);
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
        /*LCD_DrawImage1BPPZOOM_4(60, 75, BmpBCU_F_OUT1, WHITE, BLACK);
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
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 14, BmpBCU_F_OUT15, WHITE, BLACK);*/
        /***********************ǰģ�鿪�زɼ�*********************************/
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 12, BMP_Dizhi, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 12, BMP_Xuanze, WHITE, BLACK);
        print_SZ_2(285 + 150 + 84 + 6, 75 + 25 * 12, 1, 1, 0, WHITE);

        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 13, BMP_Dizhi, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 13, BMP_Xuanze, WHITE, BLACK);
        print_SZ_2(285 + 150 + 84 + 6, 75 + 25 * 13, 2, 1, 0, WHITE);
        LCD_DrawImage1BPP(505 + 100, 75 + 8 + 25 * 15, BMP_Banben, WHITE, BLACK);
        LCD_DrawImage1BPP(505 + 100 + 42, 75 + 8 + 25 * 15, BMP_Hao, WHITE, BLACK);
        LCD_DrawImage1BPP(505 + 200, 75 + 25 * 15, BMP_V, WHITE, BLACK);
        /*LCD_DrawImage1BPPZOOM_4(285 + 150, 75, BmpBCU_F_KL1, WHITE, BLACK);
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
        LCD_DrawImage1BPPZOOM_4(285 + 150, 75 + 25 * 15, BmpBCU_F_KH1, WHITE, BLACK);*/
    } else if (index == 3) {
        LCD_DrawImage1BPP(130 + 200 + 200, 130 - 85 + 4, BMP_c, WHITE, BLACK);
        LCD_DrawImage1BPP(130 + 200 + 200 + 11, 130 - 85 + 4, BMP_a, WHITE, BLACK);
        LCD_DrawImage1BPP(130 + 200 + 200 + 11 + 11, 130 - 85 + 4, BMP_n, WHITE, BLACK);
        LCD_DrawImage1BPP(130 + 200 + 200 + 11 + 11 + 11, 130 - 85 + 4, BMP_Tongxun, WHITE, BLACK);

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
        
        /*LCD_DrawImage1BPPZOOM_4(60, 75, BmpBCU_M_OUT1, WHITE, BLACK);
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
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 14, BmpBCU_M_OUT15, WHITE, BLACK);*/


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
        /*LCD_DrawImage1BPPZOOM_4(285 + 150, 75, BmpBCU_M_KL1, WHITE, BLACK);
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
        LCD_DrawImage1BPPZOOM_4(285 + 150, 75 + 25 * 15, BmpBCU_M_KH1, WHITE, BLACK);*/
    } else if (index == 4) {
        LCD_DrawImage1BPP(130 + 200 + 200, 130 - 85 + 4, BMP_c, WHITE, BLACK);
        LCD_DrawImage1BPP(130 + 200 + 200 + 11, 130 - 85 + 4, BMP_a, WHITE, BLACK);
        LCD_DrawImage1BPP(130 + 200 + 200 + 11 + 11, 130 - 85 + 4, BMP_n, WHITE, BLACK);
        LCD_DrawImage1BPP(130 + 200 + 200 + 11 + 11 + 11, 130 - 85 + 4, BMP_Tongxun, WHITE, BLACK);

        print_SZ_2(750, 50, 4, 1, 0, WHITE); // 4/4
        LCD_DrawImage1BPP(750 + 11, 50, BMP_I, WHITE, BLACK);
        print_SZ_2(750 + 11 + 14, 50, 4, 1, 0, WHITE);

        LCD_DrawImage1BPP(130 + 200, 130 - 85, BMP_HOU, WHITE, BLACK); //��
        LCD_DrawImage1BPP(130 + 200 + 25, 130 - 85, BMP_MOKUAI, WHITE, BLACK); //ģ��
        LCD_DrawImage1BPP(130 + 200 + 25 + 50, 130 - 85, BMP_Message, WHITE, BLACK); //��Ϣ
        for (i = 0; i < 15; i++) {
            LCD_DrawImage1BPP(60 + 280, 75 + 3 + 25 * i, BMP_a, WHITE, BLACK);
            //LCD_DrawRect(0, 74 +25+ 25 * i, 800, 1, GRAY); //����
        }
        /*********************��ģ�����***************************************/
        //�ƶ���
        LCD_DrawImage1BPP(60, 75 + 25 * 0, BMP_Zhidong, WHITE, BLACK);
        //��·��
        LCD_DrawImage1BPP(60, 75 + 25 * 1, BMP_Ce, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 1, BMP_Lupai, WHITE, BLACK);
        //�����
        LCD_DrawImage1BPP(60, 75 + 25 * 2, BMP_IC_Hou, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 2, BMP_IC_Wu, WHITE, BLACK);
        //������������Դ
        LCD_DrawImage1BPP(60, 75 + 25 * 3, BMP_Zhengche, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 3, BMP_KZQ, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 105, 75 + 25 * 3, BMP_Dianyuan, WHITE, BLACK);
        //��ת���
        LCD_DrawImage1BPP(60, 75 + 25 * 4, BMP_IC_Zuo, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 4, BMP_IC_Zhuanxiang, WHITE, BLACK);
        //��ѹ��Դ
        LCD_DrawImage1BPP(60, 75 + 25 * 5, BMP_Qiya, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 5, BMP_Dianyuan, WHITE, BLACK);
        //��ת���
        LCD_DrawImage1BPP(60, 75 + 25 * 6, BMP_IC_You, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 6, BMP_IC_Zhuanxiang, WHITE, BLACK);
        //������1
        LCD_DrawImage1BPP(60, 75 + 25 * 7, BMP_DC, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 7, BMP_Laba, WHITE, BLACK);
        print_SZ_2(60 + 63 + 6, 75 + 25 * 7, 1, 1, 0, WHITE);
        //������1
        LCD_DrawImage1BPP(60, 75 + 25 * 8, BMP_Daoche, WHITE, BLACK);
        print_SZ_2(60 + 63 + 6, 75 + 25 * 8, 1, 1, 0, WHITE);
        //������2
        LCD_DrawImage1BPP(60, 75 + 25 * 9, BMP_DC, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 9, BMP_Laba, WHITE, BLACK);
        print_SZ_2(60 + 63 + 6, 75 + 25 * 9, 2, 1, 0, WHITE);
        //ǰ��̤����
        LCD_DrawImage1BPP(60, 75 + 25 * 10, BMP_IC_Qian, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 10, BMP_Men, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 10, BMP_Tabu, WHITE, BLACK);
        //λ�õ�
        LCD_DrawImage1BPP(60, 75 + 25 * 11, BMP_Weizhi, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 11, BMP_IC_Deng, WHITE, BLACK);
        //����̤���
        LCD_DrawImage1BPP(60, 75 + 25 * 12, BMP_Zhong, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 12, BMP_Men, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 12, BMP_Tabu, WHITE, BLACK);
        //��������
        LCD_DrawImage1BPP(60, 75 + 25 * 13, BMP_Daoche, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 13, BMP_Laba, WHITE, BLACK);
        //������2
        LCD_DrawImage1BPP(60, 75 + 25 * 14, BMP_Daoche, WHITE, BLACK);
        print_SZ_2(60 + 63 + 6, 75 + 25 * 14, 2, 1, 0, WHITE);

        //��
        for (i = 0; i < 16; i++) {
            if (i == 0 || i == 2 || i == 8 || i == 11 || i == 14)
                LCD_DrawImage1BPP(60 + 42, 75 + 25 * i, BMP_IC_Deng, WHITE, BLACK);
            if (i == 4 || i == 6)
                LCD_DrawImage1BPP(60 + 63, 75 + 25 * i, BMP_IC_Deng, WHITE, BLACK);
            if (i == 10 || i == 12)
                LCD_DrawImage1BPP(60 + 84, 75 + 25 * i, BMP_IC_Deng, WHITE, BLACK);
        }
        /*LCD_DrawImage1BPPZOOM_4(60, 75, BmpBCU_R_OUT1, WHITE, BLACK);
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
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 14, BmpBCU_R_OUT15, WHITE, BLACK);*/

        /*********************��ģ�鿪��***************************************/
        //ˮλ����
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 0, BMP_Shuiwei, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 0, BMP_Baojing, WHITE, BLACK);
        //��ǰĦ��Ƭ����
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 1, BMP_IC_Zuo, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 21, 75 + 25 * 1, BMP_IC_Qian, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 1, BMP_Mocapian, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 105, 75 + 25 * 1, BMP_Baojing, WHITE, BLACK);
        //ǰ��Ӧ��������1
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 2, BMP_IC_Qian, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 21, 75 + 25 * 2, BMP_Men, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 2, BMP_Yingjifa, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 105, 75 + 25 * 2, BMP_Baojing, WHITE, BLACK);
        print_SZ_2(285 + 150 + 105 + 42 + 6, 75 + 25 * 2, 1, 1, 0, WHITE);
        //��ǰĦ��Ƭ����
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 3, BMP_IC_You, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 21, 75 + 25 * 3, BMP_IC_Qian, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 3, BMP_Mocapian, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 105, 75 + 25 * 3, BMP_Baojing, WHITE, BLACK);
        //����Ӧ��������1
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 4, BMP_Zhong, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 21, 75 + 25 * 4, BMP_Men, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 4, BMP_Yingjifa, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 105, 75 + 25 * 4, BMP_Baojing, WHITE, BLACK);
        print_SZ_2(285 + 150 + 105 + 42 + 6, 75 + 25 * 4, 1, 1, 0, WHITE);
        //�ƶ�����
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 5, BMP_Zhidong, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 5, BMP_IC_Kaiguan, WHITE, BLACK);
        //פ���ƶ�����
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 7, BMP_Zhuche, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 7, BMP_Zhidong, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 84, 75 + 25 * 7, BMP_IC_Kaiguan, WHITE, BLACK);
        //�����
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 10, BMP_IC_Hou, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 21, 75 + 25 * 10, BMP_Cangmen, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 63, 75 + 25 * 10, BMP_IC_Kaiguan, WHITE, BLACK);
        //��ַѡ��1
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 12, BMP_Dizhi, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 12, BMP_Xuanze, WHITE, BLACK);
        print_SZ_2(285 + 150 + 84 + 6, 75 + 25 * 12, 1, 1, 0, WHITE);
        //��ַѡ��2
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 13, BMP_Dizhi, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 13, BMP_Xuanze, WHITE, BLACK);
        print_SZ_2(285 + 150 + 84 + 6, 75 + 25 * 13, 2, 1, 0, WHITE);
        
        LCD_DrawImage1BPP(505 + 100, 75 + 8 + 25 * 15, BMP_Banben, WHITE, BLACK);
        LCD_DrawImage1BPP(505 + 100 + 42, 75 + 8 + 25 * 15, BMP_Hao, WHITE, BLACK);
        LCD_DrawImage1BPP(505 + 200, 75 + 25 * 15, BMP_V, WHITE, BLACK);
        /*LCD_DrawImage1BPPZOOM_4(285 + 150, 75, BmpBCU_R_KL1, WHITE, BLACK);
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
        LCD_DrawImage1BPPZOOM_4(285 + 150, 75 + 25 * 15, BmpBCU_R_KH1, WHITE, BLACK);*/
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
        print_SZ_2(535 + 63 + 42 + 16 * 5, 75 + 25 * 14, ADV[0], 3, 1, YELLOW);

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
        if(fADD)
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
        print_SZ_1(535 + 200, 75 + 25 * 15, 100, 3, 2, YELLOW);
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
        print_SZ_1(535 + 200, 75 + 25 * 15, 100, 3, 2, YELLOW);
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
        print_SZ_1(535 + 200, 75 + 25 * 15, 100, 3, 2, YELLOW);
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
    LCD_DrawRect(0, 430+13, 800, 2, YELLOW); //�ײ�����

    LCD_DrawImage1BPP(130, 130, BMP_MOTO, color, BLACK); //���
    LCD_DrawImage1BPP(130 + 50, 130, BMP_STSTEM, color, BLACK); //ϵͳ
    LCD_DrawImage1BPP(130 + 50 + 50, 130, BMP_Message, color, BLACK); //��Ϣ

    LCD_DrawImage1BPP(130 + 350, 130, BMP_Battery, color, BLACK); //���
    LCD_DrawImage1BPP(130 + 350 + 50, 130, BMP_Manage, color, BLACK); //����
    LCD_DrawImage1BPP(130 + 350 + 50 + 50, 130, BMP_STSTEM, color, BLACK); //ϵͳ
    LCD_DrawImage1BPP(130 + 350 + 50 + 50 + 50, 130, BMP_Message, color, BLACK); //��Ϣ
    /*
    LCD_DrawImage1BPP(130, 130 + 35, BMP_DMQ, color, BLACK); //����
    LCD_DrawImage1BPP(130 + 50, 130 + 35, BMP_STSTEM, color, BLACK); //ϵͳ
    LCD_DrawImage1BPP(130 + 50 + 50, 130 + 35, BMP_Message, color, BLACK); //��Ϣ

    LCD_DrawImage1BPP(130, 130 + 35 + 35, BMP_DCDC, color, BLACK); //DCDC
    LCD_DrawImage1BPP(130 + 65, 130 + 35 + 35, BMP_STSTEM, color, BLACK); //ϵͳ
    LCD_DrawImage1BPP(130 + 65 + 50, 130 + 35 + 35, BMP_Message, color, BLACK); //��Ϣ

    LCD_DrawImage1BPP(130, 130 + 35 + 35 + 35, BMP_DMY, color, BLACK); //�ͱ�
    LCD_DrawImage1BPP(130 + 50, 130 + 35 + 35 + 35, BMP_STSTEM, color, BLACK); //ϵͳ
    LCD_DrawImage1BPP(130 + 50 + 50, 130 + 35 + 35 + 35, BMP_Message, color, BLACK); //��Ϣ
    */
    
    LCD_DrawImage1BPP(130 + 350, 130 + 35, BMP_Battery, color, BLACK); //���   
    LCD_DrawImage1BPP(130 + 350 + 50, 130 + 35, BMP_Message, color, BLACK); //��Ϣ

    /*LCD_DrawImage1BPP(130 + 350, 130 + 35 + 35, BMP_Air, color, BLACK); //�յ�
    LCD_DrawImage1BPP(130 + 350 + 50, 130 + 35 + 35, BMP_STSTEM, color, BLACK); //ϵͳ
    LCD_DrawImage1BPP(130 + 350 + 50 + 50, 130 + 35 + 35, BMP_Message, color, BLACK); //��Ϣ   
    */
    LCD_DrawImage1BPP(130, 130 + 35, BMP_IC, color, BLACK); //�Ǳ�
    LCD_DrawImage1BPP(130 + 50, 130 + 35, BMP_STSTEM, color, BLACK); //ϵͳ
    LCD_DrawImage1BPP(130 + 50 + 50, 130 + 35, BMP_Message, color, BLACK); //��Ϣ   
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
       
    if (i == 8) i = 4;
    if (i == 0) i = 4;
    //�Ӳ˵����л�
    if (i == 4) {
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
    if (i == 5 || i==1) {
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
    /*if (i == 10 || i==2) {
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
    if (i == 11 || i==3) {
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
    LCD_DrawImage1BPP(105, 131 + 3 * 35, BMP_Choose, color, BLACK);*/
    if (i == 6 || i==2) {
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
    LCD_DrawImage1BPP(105 + 350, 131, BMP_Choose, color, BLACK);
    if (i == 7 || i==3) {
        color = GREEN;
        if (key_set) {
            key_set = 0;
            if(time_flag==0){
                f_index = 0;  
                frmID = 7;
            }
            time_flag=0;
        }
    } else
        color = BLACK;
    LCD_DrawImage1BPP(105 + 350, 131 + 35, BMP_Choose, color, BLACK);
    /*if (i == 14 || i==6) {
        color = GREEN;
        if (key_set) {
            key_set = 0;
            if(time_flag==0){
                f_index = 0;  
                frmID = 8;
            }
            time_flag=0;
        }
    } else
        color = BLACK;
    LCD_DrawImage1BPP(105 + 350, 131 + 2 * 35, BMP_Choose, color, BLACK);
    if (i == 15 || i==7) {
        color = GREEN;
        if (key_set) {
            key_set = 0;
            if(time_flag==0){
                f_index = 0;  
                frmID = 9;
            }
            time_flag=0;
        }
    } else
        color = BLACK;
    LCD_DrawImage1BPP(105 + 350, 131 + 3 * 35, BMP_Choose, color, BLACK);
*/

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
        disp_time(330, 440+13, timer);
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
            frmID = 4;
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

    LCD_DrawImage1BPP(82, 100 + 38 * 6, BMP_Zhengche, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 6, BMP_KZQ, WHITE, BLACK); //������
    LCD_DrawImage1BPP(82 + 42 + 63, 100 + 38 * 6, BMP_Life, WHITE, BLACK); //Life
    
    LCD_DrawImage1BPP(82, 100 + 38 * 7, BMP_Zui, WHITE, BLACK); //��߹��ϵȼ�
    LCD_DrawImage1BPP(82+21, 100 + 38 * 7, BMP_Gao, WHITE, BLACK); 
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 7, BMP_Guzhang, WHITE, BLACK);
    LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 7, BMP_Dengji, WHITE, BLACK);
    
    LCD_DrawImage1BPP(82, 100 + 38 * 8, BMP_Zhengche, WHITE, BLACK); //�������ϴ���
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 8, BMP_Guzhang, WHITE, BLACK);
    LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 8, BMP_Code, WHITE, BLACK);
    
    LCD_DrawImage1BPP(82, 100 + 38 * 9, BMP_Jiechuqi, WHITE, BLACK); //�Ӵ���״̬
    LCD_DrawImage1BPP(82 + 63, 100 + 38 * 9, BMP_Zhuangtai, WHITE, BLACK);
  
    LCD_DrawImage1BPP(82 + 320, 100, BMP_Jiasu, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 42 + 320, 100, BMP_Taban, WHITE, BLACK); //̤��
    LCD_DrawImage1BPP(82 + 42 + 42 + 320, 100 - 8, BMP_SZ_1[1], WHITE, BLACK); //1
    //LCD_DrawImage1BPP(82 + 42 + 42 + 320, 100, BMP_Baifenbi, WHITE, BLACK); //�ٷֱ�
    LCD_DrawImage1BPP(720 - 24, 100, BMP_Baifenhao, WHITE, BLACK); //%

    LCD_DrawImage1BPP(82 + 320, 100 + 38, BMP_Jiasu, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 42 + 320, 100 + 38, BMP_Taban, WHITE, BLACK); //̤��
    LCD_DrawImage1BPP(82 + 42 + 42 + 320, 100 - 8 + 38, BMP_SZ_1[2], WHITE, BLACK); //2
    //LCD_DrawImage1BPP(82 + 42 + 42 + 320, 100, BMP_Baifenbi, WHITE, BLACK); //�ٷֱ�
    LCD_DrawImage1BPP(720 - 24, 100 + 38, BMP_Baifenhao, WHITE, BLACK); //%

    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 2, BMP_Zhidong, WHITE, BLACK); //�ƶ�
    LCD_DrawImage1BPP(82 + 42 + 320, 100 + 38 * 2, BMP_Taban, WHITE, BLACK); //̤��
    LCD_DrawImage1BPP(82 + 42 + 42 + 320, 100 - 8 + 38 * 2, BMP_SZ_1[1], WHITE, BLACK); //1
    //LCD_DrawImage1BPP(82 + 42 + 42 + 320, 100 + 38, BMP_Baifenbi, WHITE, BLACK); //�ٷֱ�
    LCD_DrawImage1BPP(720 - 24, 100 + 38 * 2, BMP_Baifenhao, WHITE, BLACK); //%

    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 3, BMP_Zhidong, WHITE, BLACK); //�ƶ�
    LCD_DrawImage1BPP(82 + 42 + 320, 100 + 38 * 3, BMP_Taban, WHITE, BLACK); //̤��
    LCD_DrawImage1BPP(82 + 42 + 42 + 320, 100 - 8 + 38 * 3, BMP_SZ_1[2], WHITE, BLACK); //2
    //LCD_DrawImage1BPP(82 + 42 + 42 + 320, 100 + 38, BMP_Baifenbi, WHITE, BLACK); //�ٷֱ�
    LCD_DrawImage1BPP(720 - 24, 100 + 38 * 3, BMP_Baifenhao, WHITE, BLACK); //%

    LCD_DrawImage1BPP(82 + 320, 100 - 2 + 38 * 4, BMP_DCDC, WHITE, BLACK); //DCDCɢ�����¶�
    LCD_DrawImage1BPP(82 + 65 + 320, 100 + 38 * 4, BMP_Sanreqi, WHITE, BLACK);
    LCD_DrawImage1BPP(82 + 65 + 63 + 320, 100 + 38 * 4, BMP_Wendu, WHITE, BLACK);
    LCD_DrawImage1BPP(720 - 24, 100 + 38 * 4, BMP_T, WHITE, BLACK); //��

    LCD_DrawImage1BPP(82 + 320, 100 - 2 + 38 * 5, BMP_DCDC, WHITE, BLACK); //DCDC���ϴ���
    LCD_DrawImage1BPP(82 + 65 + 320, 100 + 38 * 5, BMP_Guzhang, WHITE, BLACK);
    LCD_DrawImage1BPP(82 + 65 + 42 + 320, 100 + 38 * 5, BMP_Code, WHITE, BLACK);

    LCD_DrawImage1BPP(82 + 320, 100 - 2 + 38 * 6, BMP_DCAC, WHITE, BLACK); //DCAC1ɢ�����¶�
    LCD_DrawImage1BPP(82 + 52 + 320, 100 - 8 + 38 * 6, BMP_SZ_1[1], WHITE, BLACK); //1
    LCD_DrawImage1BPP(82 + 52 + 16 + 320, 100 + 38 * 6, BMP_Sanreqi, WHITE, BLACK);
    LCD_DrawImage1BPP(82 + 52 + 16 + 63 + 320, 100 + 38 * 6, BMP_Wendu, WHITE, BLACK);
    LCD_DrawImage1BPP(720 - 24, 100 + 38 * 6, BMP_T, WHITE, BLACK); //��

    LCD_DrawImage1BPP(82 + 320, 100 - 2 + 38 * 7, BMP_DCAC, WHITE, BLACK); //DCAC1���ϴ���
    LCD_DrawImage1BPP(82 + 52 + 320, 100 - 8 + 38 * 7, BMP_SZ_1[1], WHITE, BLACK); //1
    LCD_DrawImage1BPP(82 + 52 + 16 + 320, 100 + 38 * 7, BMP_Guzhang, WHITE, BLACK);
    LCD_DrawImage1BPP(82 + 52 + 16 + 43 + 320, 100 + 38 * 7, BMP_Code, WHITE, BLACK);
    
    LCD_DrawImage1BPP(82 + 320, 100 - 2 + 38 * 8, BMP_DCAC, WHITE, BLACK); //DCAC2ɢ�����¶�
    LCD_DrawImage1BPP(82 + 52 + 320, 100 - 8 + 38 * 8, BMP_SZ_1[2], WHITE, BLACK); //2
    LCD_DrawImage1BPP(82 + 52 + 16 + 320, 100 + 38 * 8, BMP_Sanreqi, WHITE, BLACK);
    LCD_DrawImage1BPP(82 + 52 + 16 + 63 + 320, 100 + 38 * 8, BMP_Wendu, WHITE, BLACK);
    LCD_DrawImage1BPP(720 - 24, 100 + 38 * 8, BMP_T, WHITE, BLACK); //��

    LCD_DrawImage1BPP(82 + 320, 100 - 2 + 38 * 9, BMP_DCAC, WHITE, BLACK); //DCAC2���ϴ���
    LCD_DrawImage1BPP(82 + 52 + 320, 100 - 8 + 38 * 9, BMP_SZ_1[2], WHITE, BLACK); //2
    LCD_DrawImage1BPP(82 + 52 + 16 + 320, 100 + 38 * 9, BMP_Guzhang, WHITE, BLACK);
    LCD_DrawImage1BPP(82 + 52 + 16 + 43 + 320, 100 + 38 * 9, BMP_Code, WHITE, BLACK);

}

void MOTOUpdate(void) {
    updata_DAT(82 + 200 + 20, 100 - 8, Moto_Voltage, 0.1, 1000, WHITE, 3, 0);
    updata_DAT(82 + 200 + 20, 100 + 38 - 8, Moto_Current, 0.1, 1000, WHITE, 3, 0);
    updata_DAT(82 + 200 + 20, 100 + 38 * 2 - 8, Motor_Temperature, 1, 40, WHITE, 3, 0);
    updata_DAT(82 + 200 + 20, 100 + 38 * 3 - 8, Inverter_t, 1, 40, WHITE, 3, 0);
    print_SZ_1(82 + 200 + 20, 100 - 8 + 38 * 4, Car_Mode, 3, 0, WHITE); //����ģʽ
    print_SZ_1(82 + 200 - 44, 100 - 8 + 38 * 5, Program, 6, 1, WHITE); //����汾
    print_SZ_1(82 + 200 + 20, 100 - 8 + 38 * 6, Car_LIFE, 3, 0, WHITE); //����LIFE
    print_SZ_1(82 + 200 + 20 + 32, 100 - 8 + 38 * 7, Car_Fault_Level, 1, 0, WHITE); //�������ϴ���
    print_SZ_1(82 + 200 + 20 - 16, 100 - 8 + 38 * 8, Fault_Code, 4, 0, WHITE); //�������ϴ���
    print_D(82 + 180, 100 - 8 + 38 * 9, MET_C_3[0].byte, 8, 0, WHITE); //�Ӵ���״̬

    print_SZ_1(82 + 200 + 320, 100 - 8, Speed_Percent1 * 4, 4, 1, WHITE); //����̤��1
    print_SZ_1(82 + 200 + 320, 100 - 8 + 38, Speed_Percent2 * 4, 4, 1, WHITE); //����̤��2
    print_SZ_1(82 + 200 + 320, 100 - 8 + 38 * 2, Brake_Percent1 * 4, 4, 1, WHITE); //�ƶ�̤��1
    print_SZ_1(82 + 200 + 320, 100 - 8 + 38 * 3, Brake_Percent2 * 4, 4, 1, WHITE); //�ƶ�̤��2
    updata_DAT(82 + 200 + 320 + 32, 100 - 8 + 38 * 4, DCDC_Sanreqi_t, 1, 40, WHITE, 3, 0);
    print_SZ_1(82 + 200 + 320 + 32, 100 - 8 + 38 * 5, DCDC_Warn_code, 3, 0, WHITE);
    updata_DAT(82 + 200 + 320 + 32, 100 - 8 + 38 * 6, DCAC1_Sanreqi_t, 1, 40, WHITE, 3, 0);
    print_SZ_1(82 + 200 + 320 + 32, 100 - 8 + 38 * 7, DCAC1_Warn_code, 3, 0, WHITE);
    updata_DAT(82 + 200 + 320 + 32, 100 - 8 + 38 * 8, DCAC2_Sanreqi_t, 1, 40, WHITE, 3, 0);
    print_SZ_1(82 + 200 + 320 + 32, 100 - 8 + 38 * 9, DCAC2_Warn_code, 3, 0, WHITE);
    
    /*print_D(82 + 180 + 320, 100 - 8 + 38 * 2, CAN_KEY[0].byte); //����������1
    print_D(82 + 180 + 320, 100 - 8 + 38 * 3, CAN_KEY[1].byte); //����������2
    print_D(82 + 180 + 320, 100 - 8 + 38 * 4, Digit_input3); //����������3
    print_D(82 + 180 + 320, 100 - 8 + 38 * 5, CAN_KEY[2].byte); //����������1
    print_D(82 + 180 + 320, 100 - 8 + 38 * 6, CAN_KEY[3].byte); //����������2
    print_D(82 + 180 + 320, 100 - 8 + 38 * 7, 0); //����������3    
    */
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
        key_AV = 0;
        f_index = 0;
        frmID = 1;
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
/*
void DMQFrame(void) {
    unsigned char i = 0;
    LCD_Clear();
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //��������
    LCD_DrawImage1BPP(130 + 200 - 15, 130 - 85, BMP_DMQ, WHITE, BLACK); //����
    LCD_DrawImage1BPP(130 + 200 + 50 - 15, 130 - 85, BMP_STSTEM, WHITE, BLACK); //ϵͳ
    LCD_DrawImage1BPP(130 + 200 + 50 + 50 - 15, 130 - 85, BMP_Message, WHITE, BLACK); //��Ϣ

    LCD_DrawRect(80, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320 + 320, 90, 1, 380, GREEN);
    for (i = 0; i < 11; i++)
        LCD_DrawRect(80, 90 + i * 38, 640, 1, GREEN);

    LCD_DrawImage1BPP(82, 100 - 2, BMP_DCAC, WHITE, BLACK); //DCAC
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

    LCD_DrawImage1BPP(82 + 320, 100, BMP_Wendu, WHITE, BLACK); //�¶�
    LCD_DrawImage1BPP(720 - 24, 100, BMP_T, WHITE, BLACK); //��

    LCD_DrawImage1BPP(82 + 320, 100 + 38, BMP_Guzhang, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 42 + 320, 100 + 38, BMP_Code, WHITE, BLACK); //����
    
    LCD_DrawImage1BPP(82 + 320, 100 + 38*2, BMP_Guzhang, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 42 + 320, 100 + 38*2, BMP_Dengji, WHITE, BLACK); //�ȼ�

    LCD_DrawImage1BPP(82 + 320, 100 - 2 + 38 * 3, BMP_DCAC, WHITE, BLACK); //DCAC
    LCD_DrawImage1BPP(82 + 320 + 52, 100 + 2 + 38 * 3, BMP_Input, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 320 + 52 + 42, 100 + 2 + 38 * 3, BMP_Qieduan, WHITE, BLACK); //�ж�

    LCD_DrawImage1BPP(82 + 320, 100 - 2 + 38 * 4, BMP_DCAC, WHITE, BLACK); //DCAC
    LCD_DrawImage1BPP(82 + 320 + 52, 100 + 2 + 38 * 4, BMP_Output, WHITE, BLACK); //���
    LCD_DrawImage1BPP(82 + 320 + 52 + 42, 100 + 2 + 38 * 4, BMP_Qieduan, WHITE, BLACK); //�ж�
    
    LCD_DrawImage1BPP(82 + 320, 100 - 2 + 38 * 5, BMP_DCAC, WHITE, BLACK); //DCAC
    LCD_DrawImage1BPP(82 + 320 + 52, 100 + 2 + 38 * 5, BMP_Gongzuo, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 320 + 52 + 42, 100 + 2 + 38 * 5, BMP_Zhuangtai, WHITE, BLACK); //״̬

}

void DMQUpdate(void) {
    print_SZ_1(82 + 200 + 20 - 16, 100 - 8, AIRDCAC_W_Current * 0.1, 4, 0, WHITE);
    print_SZ_1(82 + 200 + 20 - 16, 100 - 8 + 38, AIRDCAC_W_Voltage * 0.1, 4, 0, WHITE);
    print_SZ_1(82 + 200 + 20 - 16, 100 - 8 + 38 * 2, AIRDCAC_V_Current * 0.1, 4, 0, WHITE);
    print_SZ_1(82 + 200 + 20 - 16, 100 - 8 + 38 * 3, AIRDCAC_V_Voltage * 0.1, 4, 0, WHITE);
    print_SZ_1(82 + 200 + 20 - 16, 100 - 8 + 38 * 4, AIRDCAC_U_Current * 0.1, 4, 0, WHITE);
    print_SZ_1(82 + 200 + 20 - 16, 100 - 8 + 38 * 5, AIRDCAC_U_Voltage * 0.1, 4, 0, WHITE);
    
    updata_DAT(82 + 200 + 300, 100 - 8, AIRDCAC_Temp, 1, 40, WHITE, 3, 0);
    print_SZ_1(82 + 200 + 300 + 16, 100 - 8 + 38, AIRDCAC_Fault_Code, 2, 0, WHITE);
    print_SZ_1(82 + 200 + 300 + 16, 100 - 8 + 38 * 2, AIRDCAC_Level_Fault, 2, 0, WHITE);
    print_SZ_1(82 + 200 + 300 + 16, 100 - 8 + 38 * 3, AIRDCAC_intput_Cut, 2, 0, WHITE);
    print_SZ_1(82 + 200 + 300 + 16, 100 - 8 + 38 * 4, AIRDCAC_Output_Cut, 2, 0, WHITE);
    print_SZ_1(82 + 200 + 300 + 16, 100 - 8 + 38 * 5, AIRDCAC_Status, 2, 0, WHITE);
}

void frmDMQ(void) {
    if (f_index == 0) { //ֻ����һ��
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
*/
/******************************************************/
/*void DCDCFrame(void) {
    unsigned char i = 0;
    LCD_Clear();
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //��������
    LCD_DrawImage1BPP(130 + 200, 130 - 85, BMP_DCDC, WHITE, BLACK); //DCDC
    LCD_DrawImage1BPP(130 + 200 + 65, 130 - 85, BMP_STSTEM, WHITE, BLACK); //ϵͳ
    LCD_DrawImage1BPP(130 + 200 + 65 + 50, 130 - 85, BMP_Message, WHITE, BLACK); //��Ϣ

    LCD_DrawRect(80, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320 + 320, 90, 1, 380, GREEN);
    for (i = 0; i < 11; i++)
        LCD_DrawRect(80, 90 + i * 38, 640, 1, GREEN);

    LCD_DrawImage1BPP(82, 100-2, BMP_DCDC, WHITE, BLACK); //DCDC
    LCD_DrawImage1BPP(82 + 65, 100+2, BMP_Output, WHITE, BLACK); //���
    LCD_DrawImage1BPP(82 + 65 + 42, 100+2, BMP_DY, WHITE, BLACK); //��ѹ
    LCD_DrawImage1BPP(400 - 24, 100-2, BMP_v, WHITE, BLACK); //V

    LCD_DrawImage1BPP(82, 100-2 + 38, BMP_DCDC, WHITE, BLACK); //DCDC
    LCD_DrawImage1BPP(82 + 65, 100+2 + 38, BMP_Output, WHITE, BLACK); //���
    LCD_DrawImage1BPP(82 + 65 + 42, 100+2 + 38, BMP_DL, WHITE, BLACK); //����
    LCD_DrawImage1BPP(400 - 24, 100 -2+ 38, BMP_a, WHITE, BLACK); //A

    LCD_DrawImage1BPP(82, 100 - 2 + 38 * 2, BMP_DCDC, WHITE, BLACK); //DCDC
    LCD_DrawImage1BPP(82 + 65, 100 + 2 + 38 * 2, BMP_Mokuai, WHITE, BLACK); //ģ��
    LCD_DrawImage1BPP(82 + 65 + 42, 100 + 2 + 38 * 2, BMP_Wendu, WHITE, BLACK); //�¶�
    LCD_DrawImage1BPP(400 - 28, 100 - 2 + 38 * 2, BMP_T, WHITE, BLACK); //��

    LCD_DrawImage1BPP(82+320, 100 - 2 + 38 * 3, BMP_DCDC, WHITE, BLACK); //DCDC
    LCD_DrawImage1BPP(82 + 65+320, 100 + 2 + 38 * 3, BMP_Output, WHITE, BLACK); //���
    LCD_DrawImage1BPP(82 + 65 + 42+320, 100 + 2 + 38 * 3, BMP_Qieduan, WHITE, BLACK); //�ж�

    LCD_DrawImage1BPP(82 + 320, 100 - 2, BMP_DCDC, WHITE, BLACK); //DCDC
    LCD_DrawImage1BPP(82 + 320 + 65, 100 + 2, BMP_Gongzuo, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 320 + 65 + 42, 100 + 2, BMP_Zhuangtai, WHITE, BLACK); //״̬
    
    LCD_DrawImage1BPP(82 + 320, 100 - 2 + 38, BMP_DCDC, WHITE, BLACK); //DCDC
    LCD_DrawImage1BPP(82 + 320 + 65, 100 + 2 + 38, BMP_Guzhang, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 320 + 65 + 42, 100 + 2 + 38, BMP_Dengji, WHITE, BLACK); //�ȼ�

    LCD_DrawImage1BPP(82 + 320, 100 - 2 + 38 * 2, BMP_DCDC, WHITE, BLACK); //DCDC
    LCD_DrawImage1BPP(82 + 320 + 65, 100 + 2 + 38 * 2, BMP_Input, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 320 + 65 + 42, 100 + 2 + 38 * 2, BMP_Qieduan, WHITE, BLACK); //�ж�

}

void DCDCUpdate(void) {
    print_SZ_1(82 + 200 + 20 - 16, 100 - 8, DCDC_Voltage * 0.1, 4, 0, WHITE);
    print_SZ_1(82 + 200 + 20 - 16, 100 - 8 + 38, DCDC_Current * 0.1, 4, 0, WHITE);
    updata_DAT(82 + 200 + 20, 100 - 8 + 38 * 2, DCDC_Temp, 1, 40, WHITE, 3, 0);

    print_SZ_1(82 + 200 + 300 + 16, 100 - 8, DCDC_Status, 2, 0, WHITE);
    print_SZ_1(82 + 200 + 300 + 16, 100 - 8 + 38, DCDC_Level_Fault, 2, 0, WHITE);
    print_SZ_1(82 + 200 + 300 + 16, 100 - 8 + 38 * 2, DCDC_intput_Cut, 2, 0, WHITE);
    print_SZ_1(82 + 200 + 300 + 16, 100 - 8 + 38 * 3, DCDC_Output_Cut, 2, 0, WHITE);  
}

void frmDCDC(void) {
    if (f_index == 0) { //ֻ����һ��
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
*/
/******************************************************/
/*void DMYFrame(void) {
    unsigned char i = 0;
    LCD_Clear();
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //��������
    LCD_DrawImage1BPP(130 + 200, 130 - 85, BMP_DMY, WHITE, BLACK); //�ͱ�
    LCD_DrawImage1BPP(130 + 200 + 50, 130 - 85, BMP_STSTEM, WHITE, BLACK); //ϵͳ
    LCD_DrawImage1BPP(130 + 200 + 50 + 50, 130 - 85, BMP_Message, WHITE, BLACK); //��Ϣ

    LCD_DrawRect(80, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320 + 320, 90, 1, 380, GREEN);
    for (i = 0; i < 11; i++)
        LCD_DrawRect(80, 90 + i * 38, 640, 1, GREEN);
    
    LCD_DrawImage1BPP(82, 100 - 2, BMP_DCAC, WHITE, BLACK); //DCAC
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

    LCD_DrawImage1BPP(82 + 320, 100, BMP_Wendu, WHITE, BLACK); //�¶�
    LCD_DrawImage1BPP(720 - 24, 100, BMP_T, WHITE, BLACK); //��

    LCD_DrawImage1BPP(82 + 320, 100 + 38, BMP_Guzhang, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 42 + 320, 100 + 38, BMP_Code, WHITE, BLACK); //����
    
    LCD_DrawImage1BPP(82 + 320, 100 + 38*2, BMP_Guzhang, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 42 + 320, 100 + 38*2, BMP_Dengji, WHITE, BLACK); //�ȼ�

    LCD_DrawImage1BPP(82 + 320, 100 - 2 + 38 * 3, BMP_DCAC, WHITE, BLACK); //DCAC
    LCD_DrawImage1BPP(82 + 320 + 52, 100 + 2 + 38 * 3, BMP_Input, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 320 + 52 + 42, 100 + 2 + 38 * 3, BMP_Qieduan, WHITE, BLACK); //�ж�

    LCD_DrawImage1BPP(82 + 320, 100 - 2 + 38 * 4, BMP_DCAC, WHITE, BLACK); //DCAC
    LCD_DrawImage1BPP(82 + 320 + 52, 100 + 2 + 38 * 4, BMP_Output, WHITE, BLACK); //���
    LCD_DrawImage1BPP(82 + 320 + 52 + 42, 100 + 2 + 38 * 4, BMP_Qieduan, WHITE, BLACK); //�ж�
    
    LCD_DrawImage1BPP(82 + 320, 100 - 2 + 38 * 5, BMP_DCAC, WHITE, BLACK); //DCAC
    LCD_DrawImage1BPP(82 + 320 + 52, 100 + 2 + 38 * 5, BMP_Gongzuo, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 320 + 52 + 42, 100 + 2 + 38 * 5, BMP_Zhuangtai, WHITE, BLACK); //״̬
    
}

void DMYUpdate(void) {   
    print_SZ_1(82 + 200 + 20 - 16, 100 - 8, OILDCAC_W_Current * 0.1, 4, 0, WHITE);
    print_SZ_1(82 + 200 + 20 - 16, 100 - 8 + 38, OILDCAC_W_Voltage * 0.1, 4, 0, WHITE);
    print_SZ_1(82 + 200 + 20 - 16, 100 - 8 + 38 * 2, OILDCAC_V_Current * 0.1, 4, 0, WHITE);
    print_SZ_1(82 + 200 + 20 - 16, 100 - 8 + 38 * 3, OILDCAC_V_Voltage * 0.1, 4, 0, WHITE);
    print_SZ_1(82 + 200 + 20 - 16, 100 - 8 + 38 * 4, OILDCAC_U_Current * 0.1, 4, 0, WHITE);
    print_SZ_1(82 + 200 + 20 - 16, 100 - 8 + 38 * 5, OILDCAC_U_Voltage * 0.1, 4, 0, WHITE);
    
    updata_DAT(82 + 200 + 300, 100 - 8, OILDCAC_Temp, 1, 40, WHITE, 3, 0);
    print_SZ_1(82 + 200 + 300 + 16, 100 - 8 + 38, OILDCAC_Fault_Code, 2, 0, WHITE);
    print_SZ_1(82 + 200 + 300 + 16, 100 - 8 + 38 * 2, OILDCAC_Level_Fault, 2, 0, WHITE);
    print_SZ_1(82 + 200 + 300 + 16, 100 - 8 + 38 * 3, OILDCAC_intput_Cut, 2, 0, WHITE);
    print_SZ_1(82 + 200 + 300 + 16, 100 - 8 + 38 * 4, OILDCAC_Output_Cut, 2, 0, WHITE);
    print_SZ_1(82 + 200 + 300 + 16, 100 - 8 + 38 * 5, OILDCAC_Status, 2, 0, WHITE);
}

void frmDMY(void) {
    if (f_index == 0) { //ֻ����һ��
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
*/
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
    LCD_DrawRect(80 + 320 + 320+30, 90, 1, 380, GREEN);
    for (i = 0; i < 11; i++)
        LCD_DrawRect(80, 90 + i * 38, 640+30, 1, GREEN);

    LCD_DrawImage1BPP(82, 100, BMP_DC, WHITE, BLACK); //���
    LCD_DrawImage1BPP(82 + 42, 100, BMP_Zong, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 42 + 21, 100, BMP_DY, WHITE, BLACK); //��ѹ
    LCD_DrawImage1BPP(400 - 24, 100, BMP_v, WHITE, BLACK); //V

    LCD_DrawImage1BPP(82, 100 + 38, BMP_DC, WHITE, BLACK); //���
    LCD_DrawImage1BPP(82 + 42, 100 + 38, BMP_Zong, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 42 + 21, 100 + 38, BMP_DL, WHITE, BLACK); //����
    LCD_DrawImage1BPP(400 - 24, 100 + 38, BMP_a, WHITE, BLACK); //A

    LCD_DrawImage1BPP(82, 100 + 38 * 2, BMP_DC, WHITE, BLACK); //���
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 2, BMP_Zong, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 42 + 21, 100 + 38 * 2, BMP_Chuanshu, WHITE, BLACK); //����

    LCD_DrawImage1BPP(82, 100 + 38 * 3, BMP_s, WHITE, BLACK); //S
    LCD_DrawImage1BPP(82 + 11, 100 + 38 * 3, BMP_o, WHITE, BLACK); //O
    LCD_DrawImage1BPP(82 + 11 + 11, 100 + 38 * 3, BMP_c, WHITE, BLACK); //C
    LCD_DrawImage1BPP(400 - 24, 100 + 38 * 3, BMP_Baifenhao, WHITE, BLACK); //%   

    LCD_DrawImage1BPP(82, 100 + 38 * 4, BMP_Zong, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 21, 100 + 38 * 4, BMP_Zheng, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 21 + 21, 100 + 38 * 4, BMP_Jueyuan, WHITE, BLACK); //��Ե
    LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 4, BMP_DC, WHITE, BLACK); //���
    LCD_DrawImage1BPP(82 + 42 + 42 + 21, 100 + 38 * 4, BMP_Zu, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 42 + 42 + 21 + 21 + 2, 100 + 5 + 38 * 4, BMP_Maohao, WHITE, BLACK); //:
    LCD_DrawImage1BPP(400 - 28, 100 + 38 * 4, BMP_k, WHITE, BLACK); //K
    LCD_DrawImage1BPP(400 - 16, 100 + 2 + 38 * 4, BMP_Omu, WHITE, BLACK); //��

    LCD_DrawImage1BPP(82, 100 + 38 * 5, BMP_Zong, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 21, 100 + 38 * 5, BMP_Fuhe, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 21 + 21, 100 + 38 * 5, BMP_Jueyuan, WHITE, BLACK); //��Ե
    LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 5, BMP_DC, WHITE, BLACK); //���
    LCD_DrawImage1BPP(82 + 42 + 42 + 21, 100 + 38 * 5, BMP_Zu, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 42 + 42 + 21 + 21 + 2, 100 + 5 + 38 * 5, BMP_Maohao, WHITE, BLACK); //:
    LCD_DrawImage1BPP(400 - 28, 100 + 38 * 5, BMP_k, WHITE, BLACK); //K
    LCD_DrawImage1BPP(400 - 16, 100 + 38 * 5 + 2, BMP_Omu, WHITE, BLACK); //��

    LCD_DrawImage1BPP(82, 100 + 38 * 6, BMP_b, WHITE, BLACK); //BMS life
    LCD_DrawImage1BPP(82 + 11, 100 + 38 * 6, BMP_m, WHITE, BLACK);
    LCD_DrawImage1BPP(82 + 11 + 11, 100 + 38 * 6, BMP_s, WHITE, BLACK);
    LCD_DrawImage1BPP(82 + 11 + 11 + 11, 100 + 38 * 6, BMP_Life, WHITE, BLACK); 
    
    LCD_DrawImage1BPP(82, 100 + 38 * 7, BMP_Zhengche, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 42 , 100 + 38 * 7, BMP_Jueyuan, WHITE, BLACK); //��Ե
    LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 7, BMP_Baojing, WHITE, BLACK); //����
    
    /*
    LCD_DrawImage1BPP(82 + 320, 100, BMP_Dan, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 320 + 21, 100, BMP_Ti, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 320 + 21 + 21, 100, BMP_Zui, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 320 + 21 + 21 + 21, 100, BMP_Gao, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 320 + 21 + 21 + 21 + 21, 100, BMP_DY, WHITE, BLACK); //��ѹ
    LCD_DrawImage1BPP(720 - 24-48, 100, BMP_v, WHITE, BLACK); //V

    LCD_DrawImage1BPP(82 + 320 + 42 * 7.5, 100, BMP_Hao, WHITE, BLACK); //��
    
    LCD_DrawImage1BPP(82 + 320, 100 + 38, BMP_Dan, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 320 + 21, 100 + 38, BMP_Ti, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 320 + 21 + 21, 100 + 38, BMP_Zui, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 320 + 21 + 21 + 21, 100 + 38, BMP_Di, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 320 + 21 + 21 + 21 + 21, 100 + 38, BMP_DY, WHITE, BLACK); //��ѹ
    LCD_DrawImage1BPP(720 - 24-48 , 100 + 38, BMP_v, WHITE, BLACK); //V

    LCD_DrawImage1BPP(82 + 320 + 42 * 7.5, 100 + 38, BMP_Hao, WHITE, BLACK); //��
    
    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 2, BMP_Dan, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 320 + 21, 100 + 38 * 2, BMP_Ti, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 320 + 21 + 21, 100 + 38 * 2, BMP_Pingjun, WHITE, BLACK); //ƽ��
    LCD_DrawImage1BPP(82 + 320 + 21 + 21 + 42, 100 + 38 * 2, BMP_Wendu, WHITE, BLACK); //�¶�
    //LCD_DrawImage1BPP(82 + 320 + 21 + 21 + 42 + 42 + 2, 100 + 38 * 2 + 5, BMP_Maohao, WHITE, BLACK); //:
    LCD_DrawImage1BPP(720 - 28-48, 100 + 38 * 2, BMP_T, WHITE, BLACK); //��
    
    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 3, BMP_DC, WHITE, BLACK); //���
    LCD_DrawImage1BPP(82 + 320 + 21 + 21, 100 + 38 * 3, BMP_Zui, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 320 + 21 + 21 + 21, 100 + 38 * 3, BMP_Gao, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 320 + 21 + 21 + 21 + 21, 100 + 38 * 3, BMP_Wendu, WHITE, BLACK); //�¶�
    LCD_DrawImage1BPP(720 - 28-48, 100 + 38 * 3, BMP_T, WHITE, BLACK); //��

    LCD_DrawImage1BPP(82 + 320 + 42 * 7.5, 100 + 38 * 3, BMP_Hao, WHITE, BLACK); //��
    
    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 4, BMP_DC, WHITE, BLACK); //���
    LCD_DrawImage1BPP(82 + 320 + 21 + 21, 100 + 38 * 4, BMP_Zui, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 320 + 21 + 21 + 21, 100 + 38 * 4, BMP_Di, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 320 + 21 + 21 + 21 + 21, 100 + 38 * 4, BMP_Wendu, WHITE, BLACK); //�¶�
    LCD_DrawImage1BPP(720 - 28-48, 100 + 38 * 4, BMP_T, WHITE, BLACK); //��

    LCD_DrawImage1BPP(82 + 320 + 42 * 7.5, 100 + 38 * 4, BMP_Hao, WHITE, BLACK); //��
    
    LCD_DrawImage1BPP(82+320, 100 + 38 * 5, BMP_Huanjin, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 320+42, 100 + 38 * 5, BMP_Wendu, WHITE, BLACK); //�¶�
    LCD_DrawImage1BPP(720 - 28-48, 100 + 38 * 5, BMP_T, WHITE, BLACK); //��
    */
/*
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

    

    

    

    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 5, BMP_Chong, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 320 + 21, 100 + 38 * 5, BMP_Fang, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 320 + 21 + 21, 100 + 38 * 5, BMP_DC, WHITE, BLACK); //���
    LCD_DrawImage1BPP(82 + 320 + 21 + 21 + 21, 100 + 38 * 5, BMP_DL, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 320 + 21 + 21 + 21 + 42 + 2, 100 + 5 + 38 * 5, BMP_Maohao, WHITE, BLACK); //:
    LCD_DrawImage1BPP(720 - 24, 100 + 38 * 5, BMP_a, WHITE, BLACK); //V
    */

}

void BMSUpdate(void) {    
    updata_DAT(82 + 200 + 30, 100 - 8, BMS_V, 0.1, 1000, WHITE, 3, 0);
    updata_DAT(82 + 200 + 30, 100 - 8 + 38, BMS_A, 0.1, 1000, WHITE, 3, 0);
    print_SZ_1(82 + 200 + 30, 100 - 8 + 38 * 2, BAT_Number, 3, 0, WHITE);
    print_SZ_1(82 + 200 + 30 - 16, 100 - 8 + 38 * 3, BMS_SOC * 4, 3, 1, WHITE);
    print_SZ_1(82 + 200 + 30-48, 100 - 8 + 38 * 4, Oum_zheng, 6, 0, WHITE);
    print_SZ_1(82 + 200 + 30-48, 100 - 8 + 38 * 5, Oum_fu, 6, 0, WHITE);
    print_SZ_1(82 + 200 + 30, 100 - 8 + 38 * 6, BMS_Life, 3, 0, WHITE);
    print_H(82 + 200 + 30 + 16, 100 - 8 + 38 * 7, Oum_Warn, 2, 0, WHITE);   
    /*print_SZ_1(82 + 200 + 30, 100 - 8 + 38, BMS_OutVoltage * 0.2, 3, 0, WHITE);
    print_SZ_1(82 + 200 + 30, 100 - 8 + 38 * 2, BMS_TotalVoltage * 0.1, 3, 0, WHITE);
    
    print_SZ_1(82 + 200 + 30, 100 - 8 + 38 * 4, BMS_Ahr * 2, 3, 0, WHITE);
    updata_DAT(82 + 200 + 30 - 16, 100 - 8 + 38 * 5, BMS_Power, 0.1, 1000, WHITE, 4, 0);   
    
    print_SZ_1(82 + 200 + 30 - 32, 100 - 8 + 38 * 7, BMS_SOH * 5, 4, 1, WHITE);
    print_SZ_1(82 + 200 + 30 - 48, 100 - 8 + 38 * 8, BMS_Ohm, 5, 3, WHITE);
    print_SZ_1(82 + 200 + 30 + 16, 100 - 8 + 38 * 9, BMS_Life, 2, 0, WHITE);

    print_SZ_1(82 + 200 + 300 - 48, 100 - 8, Battery_Single_H, 4, 2, WHITE);
    print_SZ_1(82 + 200 + 300 + 85, 100 - 8, Battery_Single_H_Number, 3, 0, WHITE);
    print_SZ_1(82 + 200 + 300 - 48, 100 - 8 + 38, Battery_Single_L, 4, 2, WHITE);
    print_SZ_1(82 + 200 + 300 + 85, 100 - 8 + 38, Battery_Single_L_Number, 3, 0, WHITE);
    updata_DAT(82 + 200 + 300, 100 - 8 + 38 * 2, Battery_Temp_Average, 0.1, 40, WHITE, 3, 0);
    updata_DAT(82 + 200 + 300, 100 - 8 + 38 * 3, Battery_Temp_H, 0.1, 40, WHITE, 3, 0);
    print_SZ_1(82 + 200 + 300 + 85, 100 - 8 + 38 * 3, Battery_Temp_H_Number, 3, 0, WHITE);
    updata_DAT(82 + 200 + 300, 100 - 8 + 38 * 4, Battery_Temp_L, 0.1, 40, WHITE, 3, 0);
    print_SZ_1(82 + 200 + 300 + 85, 100 - 8 + 38 * 4, Battery_Temp_L_Number, 3, 0, WHITE);
    updata_DAT(82 + 200 + 300, 100 - 8 + 38 * 5, BMS_Temp, 1, 40, WHITE, 3, 0);
     * */
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
        f_index = 0;
        frmID = 1;
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
    unsigned char i;
    LCD_Clear();
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //��������
    LCD_DrawImage1BPP(130 + 200 + 24, 130 - 85, BMP_Battery, WHITE, BLACK); //���
    LCD_DrawImage1BPP(130 + 200 + 50 + 24, 130 - 85, BMP_Message, WHITE, BLACK); //��Ϣ
    //�ָ�
    for (i = 0; i < 2; i++)
        LCD_DrawRect(80 - 50 - 10 + 390 * i, 90, 1, 380, GREEN);
    LCD_DrawRect(80 - 50 - 10 + 390 + 380, 90, 1, 380, GREEN);
    for (i = 0; i < 11; i++)
        LCD_DrawRect(80 - 50 - 10, 90 + i * 38, 640 + 120 + 10, 1, GREEN);

    for (i = 0; i < 4; i++) {
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
        LCD_DrawImage1BPP(82 - 50 - 10, 100 + 38 * 5 + 38 * i, BMP_Dan, WHITE, BLACK); //��
        LCD_DrawImage1BPP(82 - 50 - 10 + 21, 100 + 38 * 5 + 38 * i, BMP_Ti, WHITE, BLACK); //��
        LCD_DrawImage1BPP(82 - 50 - 10 + 21 + 21, 100 + 38 * 5 + 38 * i, BMP_Zui, WHITE, BLACK); //��
        LCD_DrawImage1BPP(82 - 50 - 10 + 21 + 21 + 21, 100 + 38 * 5 + 38 * i, BMP_Di, WHITE, BLACK); //��
        LCD_DrawImage1BPP(82 - 50 - 10 + 21 + 21 + 21 + 21, 100 + 38 * 5 + 38 * i, BMP_DY, WHITE, BLACK); //��ѹ
        LCD_DrawImage1BPP(82 - 50 - 10 + 21 + 21 + 21 + 21 + 42, 100 - 8 + 38 * 5 + 38 * i, BMP_SZ_1[1 + i], WHITE, BLACK); //1
        LCD_DrawImage1BPP(400 - 50 - 10 - 24 - 63, 100 + 38 * 5 + 38 * i, BMP_v, WHITE, BLACK); //V

        LCD_DrawImage1BPP(82 - 50 - 10 + 42 * 7, 100 + 38 * 5 + 38 * i, BMP_Xiang_BMS, WHITE, BLACK); //��

        LCD_DrawImage1BPP(82 - 50 + 42 * 8.5, 100 + 38 * 5 + 38 * i, BMP_Hao, WHITE, BLACK); //��
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
        LCD_DrawImage1BPP(82 + 380 - 50, 100 + 38 * 5 + 38 * i, BMP_Dan, WHITE, BLACK); //��
        LCD_DrawImage1BPP(82 + 380 - 50 + 21, 100 + 38 * 5 + 38 * i, BMP_Ti, WHITE, BLACK); //��
        LCD_DrawImage1BPP(82 + 380 - 50 + 21 + 21, 100 + 38 * 5 + 38 * i, BMP_Zui, WHITE, BLACK); //��
        LCD_DrawImage1BPP(82 + 380 - 50 + 21 + 21 + 21, 100 + 38 * 5 + 38 * i, BMP_Di, WHITE, BLACK); //��
        LCD_DrawImage1BPP(82 + 380 - 50 + 21 + 21 + 21 + 21, 100 + 38 * 5 + 38 * i, BMP_Wendu, WHITE, BLACK); //�¶�
        LCD_DrawImage1BPP(82 + 380 - 50 + 21 + 21 + 21 + 21 + 42, 100 - 8 + 38 * 5 + 38 * i, BMP_SZ_1[1 + i], WHITE, BLACK); //1
        LCD_DrawImage1BPP(400 + 380 - 50 - 24 - 63, 100 + 38 * 5 + 38 * i, BMP_T, WHITE, BLACK); //��

        LCD_DrawImage1BPP(82 + 380 + 10 - 50 + 42 * 7, 100 + 38 * 5 + 38 * i, BMP_Xiang_BMS, WHITE, BLACK); //��
    }
    /*LCD_DrawImage1BPP(82 - 50 - 10, 100, BMP_Dan, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 - 50 - 10 + 21, 100, BMP_Ti, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 - 50 - 10 + 21 + 21, 100, BMP_Zui, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 - 50 - 10 + 21 + 21 + 21, 100, BMP_Gao, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 - 50 - 10 + 21 + 21 + 21 + 21, 100, BMP_DY, WHITE, BLACK); //��ѹ
    LCD_DrawImage1BPP(82 - 50 - 10 + 21 + 21 + 21 + 21 + 42, 100 - 8, BMP_SZ_1[1], WHITE, BLACK); //1
    LCD_DrawImage1BPP(400 - 50 - 10 - 24 - 63, 100, BMP_v, WHITE, BLACK); //V

    LCD_DrawImage1BPP(82 - 50 - 10 + 42 * 7, 100, BMP_Xiang_BMS, WHITE, BLACK); //��

    LCD_DrawImage1BPP(82 - 50 + 42 * 8.5, 100, BMP_Hao, WHITE, BLACK); //��

    LCD_DrawImage1BPP(82 - 50 - 10, 100 + 38, BMP_Dan, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 - 50 - 10 + 21, 100 + 38, BMP_Ti, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 - 50 - 10 + 21 + 21, 100 + 38, BMP_Zui, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 - 50 - 10 + 21 + 21 + 21, 100 + 38, BMP_Gao, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 - 50 - 10 + 21 + 21 + 21 + 21, 100 + 38, BMP_DY, WHITE, BLACK); //��ѹ
    LCD_DrawImage1BPP(82 - 50 - 10 + 21 + 21 + 21 + 21 + 42, 100 - 8 + 38, BMP_SZ_1[2], WHITE, BLACK); //2
    LCD_DrawImage1BPP(400 - 50 - 10 - 24 - 63, 100 + 38, BMP_v, WHITE, BLACK); //V

    LCD_DrawImage1BPP(82 - 50 - 10 + 42 * 7, 100 + 38, BMP_Xiang_BMS, WHITE, BLACK); //��

    LCD_DrawImage1BPP(82 - 50 + 42 * 8.5, 100 + 38, BMP_Hao, WHITE, BLACK); //��

    LCD_DrawImage1BPP(82 - 50 - 10, 100 + 38 * 2, BMP_Dan, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 - 50 - 10 + 21, 100 + 38 * 2, BMP_Ti, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 - 50 - 10 + 21 + 21, 100 + 38 * 2, BMP_Zui, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 - 50 - 10 + 21 + 21 + 21, 100 + 38 * 2, BMP_Gao, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 - 50 - 10 + 21 + 21 + 21 + 21, 100 + 38 * 2, BMP_DY, WHITE, BLACK); //��ѹ
    LCD_DrawImage1BPP(82 - 50 - 10 + 21 + 21 + 21 + 21 + 42, 100 - 8 + 38 * 2, BMP_SZ_1[3], WHITE, BLACK); //3
    LCD_DrawImage1BPP(400 - 50 - 10 - 24 - 63, 100 + 38 * 2, BMP_v, WHITE, BLACK); //V

    LCD_DrawImage1BPP(82 - 50 - 10 + 42 * 7, 100 + 38 * 2, BMP_Xiang_BMS, WHITE, BLACK); //��

    LCD_DrawImage1BPP(82 - 50 + 42 * 8.5, 100 + 38 * 2, BMP_Hao, WHITE, BLACK); //��

    LCD_DrawImage1BPP(82 - 50 - 10, 100 + 38 * 3, BMP_Dan, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 - 50 - 10 + 21, 100 + 38 * 3, BMP_Ti, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 - 50 - 10 + 21 + 21, 100 + 38 * 3, BMP_Zui, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 - 50 - 10 + 21 + 21 + 21, 100 + 38 * 3, BMP_Gao, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 - 50 - 10 + 21 + 21 + 21 + 21, 100 + 38 * 3, BMP_DY, WHITE, BLACK); //��ѹ
    LCD_DrawImage1BPP(82 - 50 - 10 + 21 + 21 + 21 + 21 + 42, 100 - 8 + 38 * 3, BMP_SZ_1[4], WHITE, BLACK); //4
    LCD_DrawImage1BPP(400 - 50 - 10 - 24 - 63, 100 + 38 * 3, BMP_v, WHITE, BLACK); //V

    LCD_DrawImage1BPP(82 - 50 - 10 + 42 * 7, 100 + 38 * 3, BMP_Xiang_BMS, WHITE, BLACK); //��

    LCD_DrawImage1BPP(82 - 50 + 42 * 8.5, 100 + 38 * 3, BMP_Hao, WHITE, BLACK); //��

    LCD_DrawImage1BPP(82 - 50 - 10, 100 + 38 * 4, BMP_Dan, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 - 50 - 10 + 21, 100 + 38 * 4, BMP_Ti, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 - 50 - 10 + 21 + 21, 100 + 38 * 4, BMP_Zui, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 - 50 - 10 + 21 + 21 + 21, 100 + 38 * 4, BMP_Di, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 - 50 - 10 + 21 + 21 + 21 + 21, 100 + 38 * 4, BMP_DY, WHITE, BLACK); //��ѹ
    LCD_DrawImage1BPP(82 - 50 - 10 + 21 + 21 + 21 + 21 + 42, 100 - 8 + 38 * 4, BMP_SZ_1[1], WHITE, BLACK); //1
    LCD_DrawImage1BPP(400 - 50 - 10 - 24 - 63, 100 + 38 * 4, BMP_v, WHITE, BLACK); //V

    LCD_DrawImage1BPP(82 - 50 - 10 + 42 * 7, 100 + 38 * 4, BMP_Xiang_BMS, WHITE, BLACK); //��

    LCD_DrawImage1BPP(82 - 50 + 42 * 8.5, 100 + 38 * 4, BMP_Hao, WHITE, BLACK); //��

    LCD_DrawImage1BPP(82 - 50 - 10, 100 + 38 * 5, BMP_Dan, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 - 50 - 10 + 21, 100 + 38 * 5, BMP_Ti, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 - 50 - 10 + 21 + 21, 100 + 38 * 5, BMP_Zui, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 - 50 - 10 + 21 + 21 + 21, 100 + 38 * 5, BMP_Di, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 - 50 - 10 + 21 + 21 + 21 + 21, 100 + 38 * 5, BMP_DY, WHITE, BLACK); //��ѹ
    LCD_DrawImage1BPP(82 - 50 - 10 + 21 + 21 + 21 + 21 + 42, 100 - 8 + 38 * 5, BMP_SZ_1[2], WHITE, BLACK); //2
    LCD_DrawImage1BPP(400 - 50 - 10 - 24 - 63, 100 + 38 * 5, BMP_v, WHITE, BLACK); //V

    LCD_DrawImage1BPP(82 - 50 - 10 + 42 * 7, 100 + 38 * 5, BMP_Xiang_BMS, WHITE, BLACK); //��

    LCD_DrawImage1BPP(82 - 50 + 42 * 8.5, 100 + 38 * 5, BMP_Hao, WHITE, BLACK); //��

    LCD_DrawImage1BPP(82 - 50 - 10, 100 + 38 * 6, BMP_Dan, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 - 50 - 10 + 21, 100 + 38 * 6, BMP_Ti, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 - 50 - 10 + 21 + 21, 100 + 38 * 6, BMP_Zui, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 - 50 - 10 + 21 + 21 + 21, 100 + 38 * 6, BMP_Di, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 - 50 - 10 + 21 + 21 + 21 + 21, 100 + 38 * 6, BMP_DY, WHITE, BLACK); //��ѹ
    LCD_DrawImage1BPP(82 - 50 - 10 + 21 + 21 + 21 + 21 + 42, 100 - 8 + 38 * 6, BMP_SZ_1[3], WHITE, BLACK); //3
    LCD_DrawImage1BPP(400 - 50 - 10 - 24 - 63, 100 + 38 * 6, BMP_v, WHITE, BLACK); //V

    LCD_DrawImage1BPP(82 - 50 - 10 + 42 * 7, 100 + 38 * 6, BMP_Xiang_BMS, WHITE, BLACK); //��

    LCD_DrawImage1BPP(82 - 50 + 42 * 8.5, 100 + 38 * 6, BMP_Hao, WHITE, BLACK); //��

    LCD_DrawImage1BPP(82 - 50 - 10, 100 + 38 * 7, BMP_Dan, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 - 50 - 10 + 21, 100 + 38 * 7, BMP_Ti, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 - 50 - 10 + 21 + 21, 100 + 38 * 7, BMP_Zui, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 - 50 - 10 + 21 + 21 + 21, 100 + 38 * 7, BMP_Di, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 - 50 - 10 + 21 + 21 + 21 + 21, 100 + 38 * 7, BMP_DY, WHITE, BLACK); //��ѹ
    LCD_DrawImage1BPP(82 - 50 - 10 + 21 + 21 + 21 + 21 + 42, 100 - 8 + 38 * 7, BMP_SZ_1[4], WHITE, BLACK); //4
    LCD_DrawImage1BPP(400 - 50 - 10 - 24 - 63, 100 + 38 * 7, BMP_v, WHITE, BLACK); //V

    LCD_DrawImage1BPP(82 - 50 - 10 + 42 * 7, 100 + 38 * 7, BMP_Xiang_BMS, WHITE, BLACK); //��

    LCD_DrawImage1BPP(82 - 50 + 42 * 8.5, 100 + 38 * 7, BMP_Hao, WHITE, BLACK); //��

    LCD_DrawImage1BPP(82 + 380 - 50, 100, BMP_Dan, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 380 - 50 + 21, 100, BMP_Ti, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 380 - 50 + 21 + 21, 100, BMP_Zui, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 380 - 50 + 21 + 21 + 21, 100, BMP_Gao, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 380 - 50 + 21 + 21 + 21 + 21, 100, BMP_Wendu, WHITE, BLACK); //�¶�
    LCD_DrawImage1BPP(82 + 380 - 50 + 21 + 21 + 21 + 21 + 42, 100 - 8, BMP_SZ_1[1], WHITE, BLACK); //1
    LCD_DrawImage1BPP(400 + 380 - 50 - 24 - 63, 100, BMP_T, WHITE, BLACK); //��

    LCD_DrawImage1BPP(82 + 380 + 10 - 50 + 42 * 7, 100, BMP_Xiang_BMS, WHITE, BLACK); //��

    //LCD_DrawImage1BPP(82 - 50 + 42 * 8.5, 100, BMP_Hao, WHITE, BLACK); //��

    LCD_DrawImage1BPP(82 + 380 - 50, 100 + 38, BMP_Dan, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 380 - 50 + 21, 100 + 38, BMP_Ti, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 380 - 50 + 21 + 21, 100 + 38, BMP_Zui, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 380 - 50 + 21 + 21 + 21, 100 + 38, BMP_Gao, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 380 - 50 + 21 + 21 + 21 + 21, 100 + 38, BMP_Wendu, WHITE, BLACK); //�¶�
    LCD_DrawImage1BPP(82 + 380 - 50 + 21 + 21 + 21 + 21 + 42, 100 - 8 + 38, BMP_SZ_1[2], WHITE, BLACK); //2
    LCD_DrawImage1BPP(400 + 380 - 50 - 24 - 63, 100 + 38, BMP_T, WHITE, BLACK); //��

    LCD_DrawImage1BPP(82 + 380 + 10 - 50 + 42 * 7, 100 + 38, BMP_Xiang_BMS, WHITE, BLACK); //��

    //LCD_DrawImage1BPP(82 - 50 + 42 * 8.5, 100 + 38, BMP_Hao, WHITE, BLACK); //��

    LCD_DrawImage1BPP(82 + 380 - 50, 100 + 38 * 2, BMP_Dan, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 380 - 50 + 21, 100 + 38 * 2, BMP_Ti, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 380 - 50 + 21 + 21, 100 + 38 * 2, BMP_Zui, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 380 - 50 + 21 + 21 + 21, 100 + 38 * 2, BMP_Gao, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 380 - 50 + 21 + 21 + 21 + 21, 100 + 38 * 2, BMP_Wendu, WHITE, BLACK); //�¶�
    LCD_DrawImage1BPP(82 + 380 - 50 + 21 + 21 + 21 + 21 + 42, 100 - 8 + 38 * 2, BMP_SZ_1[3], WHITE, BLACK); //3
    LCD_DrawImage1BPP(400 + 380 - 50 - 24 - 63, 100 + 38 * 2, BMP_T, WHITE, BLACK); //��

    LCD_DrawImage1BPP(82 + 380 + 10 - 50 + 42 * 7, 100 + 38 * 2, BMP_Xiang_BMS, WHITE, BLACK); //��

    //LCD_DrawImage1BPP(82 - 50 + 42 * 8.5, 100 + 38 * 2, BMP_Hao, WHITE, BLACK); //��

    LCD_DrawImage1BPP(82 + 380 - 50, 100 + 38 * 3, BMP_Dan, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 380 - 50 + 21, 100 + 38 * 3, BMP_Ti, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 380 - 50 + 21 + 21, 100 + 38 * 3, BMP_Zui, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 380 - 50 + 21 + 21 + 21, 100 + 38 * 3, BMP_Gao, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 380 - 50 + 21 + 21 + 21 + 21, 100 + 38 * 3, BMP_Wendu, WHITE, BLACK); //�¶�
    LCD_DrawImage1BPP(82 + 380 - 50 + 21 + 21 + 21 + 21 + 42, 100 - 8 + 38 * 3, BMP_SZ_1[4], WHITE, BLACK); //4
    LCD_DrawImage1BPP(400 + 380 - 50 - 24 - 63, 100 + 38 * 3, BMP_T, WHITE, BLACK); //��

    LCD_DrawImage1BPP(82 + 380 + 10 - 50 + 42 * 7, 100 + 38 * 3, BMP_Xiang_BMS, WHITE, BLACK); //��

    //LCD_DrawImage1BPP(82+380 - 50 + 42 * 8.5, 100 + 38 * 3, BMP_Hao, WHITE, BLACK); //��

    LCD_DrawImage1BPP(82 + 380 - 50, 100 + 38 * 4, BMP_Dan, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 380 - 50 + 21, 100 + 38 * 4, BMP_Ti, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 380 - 50 + 21 + 21, 100 + 38 * 4, BMP_Zui, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 380 - 50 + 21 + 21 + 21, 100 + 38 * 4, BMP_Di, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 380 - 50 + 21 + 21 + 21 + 21, 100 + 38 * 4, BMP_Wendu, WHITE, BLACK); //�¶�
    LCD_DrawImage1BPP(82 + 380 - 50 + 21 + 21 + 21 + 21 + 42, 100 - 8 + 38 * 4, BMP_SZ_1[1], WHITE, BLACK); //1
    LCD_DrawImage1BPP(400 + 380 - 50 - 24 - 63, 100 + 38 * 4, BMP_T, WHITE, BLACK); //��

    LCD_DrawImage1BPP(82 + 380 + 10 - 50 + 42 * 7, 100 + 38 * 4, BMP_Xiang_BMS, WHITE, BLACK); //��

    //LCD_DrawImage1BPP(82 - 50 + 42 * 8.5, 100+ 38 * 4, BMP_Hao, WHITE, BLACK); //��

    LCD_DrawImage1BPP(82 + 380 - 50, 100 + 38 * 5, BMP_Dan, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 380 - 50 + 21, 100 + 38 * 5, BMP_Ti, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 380 - 50 + 21 + 21, 100 + 38 * 5, BMP_Zui, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 380 - 50 + 21 + 21 + 21, 100 + 38 * 5, BMP_Di, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 380 - 50 + 21 + 21 + 21 + 21, 100 + 38 * 5, BMP_Wendu, WHITE, BLACK); //�¶�
    LCD_DrawImage1BPP(82 + 380 - 50 + 21 + 21 + 21 + 21 + 42, 100 - 8 + 38 * 5, BMP_SZ_1[2], WHITE, BLACK); //2
    LCD_DrawImage1BPP(400 + 380 - 50 - 24 - 63, 100 + 38 * 5, BMP_T, WHITE, BLACK); //V

    LCD_DrawImage1BPP(82 + 380 + 10 - 50 + 42 * 7, 100 + 38 * 5, BMP_Xiang_BMS, WHITE, BLACK); //��

    //LCD_DrawImage1BPP(82 - 50 + 42 * 8.5, 100 + 38*5, BMP_Hao, WHITE, BLACK); //��

    LCD_DrawImage1BPP(82 + 380 - 50, 100 + 38 * 6, BMP_Dan, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 380 - 50 + 21, 100 + 38 * 6, BMP_Ti, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 380 - 50 + 21 + 21, 100 + 38 * 6, BMP_Zui, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 380 - 50 + 21 + 21 + 21, 100 + 38 * 6, BMP_Di, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 380 - 50 + 21 + 21 + 21 + 21, 100 + 38 * 6, BMP_Wendu, WHITE, BLACK); //�¶�
    LCD_DrawImage1BPP(82 + 380 - 50 + 21 + 21 + 21 + 21 + 42, 100 - 8 + 38 * 6, BMP_SZ_1[3], WHITE, BLACK); //3
    LCD_DrawImage1BPP(400 + 380 - 50 - 24 - 63, 100 + 38 * 6, BMP_T, WHITE, BLACK); //V

    LCD_DrawImage1BPP(82 + 380 + 10 - 50 + 42 * 7, 100 + 38 * 6, BMP_Xiang_BMS, WHITE, BLACK); //��

    //LCD_DrawImage1BPP(82 +350- 50 + 42 * 8.5, 100 + 38 * 6, BMP_Hao, WHITE, BLACK); //��

    LCD_DrawImage1BPP(82 + 380 - 50, 100 + 38 * 7, BMP_Dan, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 380 - 50 + 21, 100 + 38 * 7, BMP_Ti, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 380 - 50 + 21 + 21, 100 + 38 * 7, BMP_Zui, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 380 - 50 + 21 + 21 + 21, 100 + 38 * 7, BMP_Di, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 380 - 50 + 21 + 21 + 21 + 21, 100 + 38 * 7, BMP_Wendu, WHITE, BLACK); //�¶�
    LCD_DrawImage1BPP(82 + 380 - 50 + 21 + 21 + 21 + 21 + 42, 100 - 8 + 38 * 7, BMP_SZ_1[4], WHITE, BLACK); //4
    LCD_DrawImage1BPP(400 + 380 - 50 - 24 - 63, 100 + 38 * 7, BMP_T, WHITE, BLACK); //V

    LCD_DrawImage1BPP(82 + 380 + 10 - 50 + 42 * 7, 100 + 38 * 7, BMP_Xiang_BMS, WHITE, BLACK); //��
*/
    //LCD_DrawImage1BPP(82 - 50 + 42 * 8.5, 100 + 38 * 7, BMP_Hao, WHITE, BLACK); //��
    for (i = 0; i < 2; i++)
        LCD_DrawRect(80 - 50 - 10 + 390 * i, 90, 1, 380, GREEN);
    LCD_DrawRect(80 - 50 - 10 + 390 + 380, 90, 1, 380, GREEN);
    for (i = 0; i < 11; i++)
        LCD_DrawRect(80 - 50 - 10, 90 + i * 38, 640 + 120 + 10, 1, GREEN);



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

void BatteryUpdate(void) {
    unsigned char i = 0;
    for (i = 0; i < 4; i++) {
        print_SZ_1(82 + 200 + 280 - 380-10, 100 - 8 + 38 * i, BAT_Max_Cell_Voltage[i], 4, 3, YELLOW);
        print_SZ_1(82 + 200 + 280 - 380 -10+ 16 * 7-16, 100 - 8 + 38 * i, BAT_Max_Cell_Voltage_Cell_Case[i], 3, 0, YELLOW);
        print_SZ_1(82 + 200 + 280 - 380 + 16 * 11-16, 100 - 8 + 38 * i, BAT_Max_Cell_Voltage_Cell_Number[i], 3, 0, YELLOW);
    }
    for (i = 0; i < 4; i++) {
        print_SZ_1(82 + 200 + 280 - 380-10, 100 - 8 + 38 * (i + 5), BAT_Min_Cell_Voltage[i], 4, 3, YELLOW);
        print_SZ_1(82 + 200 + 280 - 380 -10+ 16 * 7-16, 100 - 8 + 38 * (i + 5), BAT_Min_Cell_Voltage_Cell_Case[i], 3, 0, YELLOW);
        print_SZ_1(82 + 200 + 280 - 380 + 16 * 11-16, 100 - 8 + 38 * (i + 5), BAT_Min_Cell_Voltage_Cell_Number[i], 3, 0, YELLOW);
    }

    for (i = 0; i < 4; i++) {
        updata_DAT(82 + 200 + 310, 100 - 8 + 38 * i, BAT_Max_Cell_Temperature[i], 1, 40, YELLOW, 3, 0);
        print_SZ_1(82 + 200 + 280+10 + 16 * 7-16, 100 - 8 + 38 * i, BAT_Max_Cell_Temp_Cell_Case[i], 3, 0, YELLOW);
    }
    for (i = 0; i < 4; i++) {
        updata_DAT(82 + 200 + 310, 100 - 8 + 38 * (i + 5), BAT_Min_Cell_Temperature[i], 1, 40, YELLOW, 3, 0);
        print_SZ_1(82 + 200 + 280 +10+ 16 * 7-16, 100 - 8 + 38 * (i + 5), BAT_Min_Cell_Temp_Cell_Case[i], 3, 0, YELLOW);
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
        f_index = 0;
        frmID = 1;
    }

    if (key_up) {
        key_up = 0;
        f_index = 0;
        frmID = 9;
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
void BatteryFrame1(unsigned char index) {
    unsigned char i = 0;
    LCD_Clear();
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //��������
    LCD_DrawImage1BPP(130 + 200 + 24, 130 - 85, BMP_Battery, WHITE, BLACK); //���
    LCD_DrawImage1BPP(130 + 200 + 50 + 24, 130 - 85, BMP_Message, WHITE, BLACK); //��Ϣ

    LCD_DrawRect(80, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320 + 320, 90, 1, 380, GREEN);
    for (i = 0; i < 11; i++)
        LCD_DrawRect(80, 90 + i * 38, 640, 1, GREEN);
    
    for (i = 0; i < 8; i++) {
        LCD_DrawImage1BPP(82, 100 + 38 * i, BMP_Xiang_BMS, WHITE, BLACK); //��
        print_SZ_1(82 + 21, 100 - 8 + 38 * i, index * 8 + i + 1, 2, 0, WHITE);
        LCD_DrawImage1BPP(82 + 21 + 32, 100 + 38 * i, BMP_Zheng, WHITE, BLACK); //��
        LCD_DrawImage1BPP(82 + 21 + 32 + 21, 100 + 38 * i, BMP_Jizhu, WHITE, BLACK); //����
        LCD_DrawImage1BPP(82 + 21 + 32 + 42, 100 + 38 * i, BMP_Jizhu, WHITE, BLACK); //����
        LCD_DrawImage1BPP(82 + 21 + 32 + 42 + 42, 100 + 38 * i, BMP_Wendu, WHITE, BLACK); //�¶�
        LCD_DrawImage1BPP(400 - 28, 100 + 38 * i, BMP_T, WHITE, BLACK); //��
    }

    for (i = 0; i < 8; i++) {
        LCD_DrawImage1BPP(82 + 320, 100 + 38 * i, BMP_Xiang_BMS, WHITE, BLACK); //��
        print_SZ_1(82 + 320 + 21, 100 - 8 + 38 * i, index * 8 + i + 1, 2, 0, WHITE);
        LCD_DrawImage1BPP(82 + 320 + 21 + 32, 100 + 38 * i, BMP_Fuhe, WHITE, BLACK); //��
        LCD_DrawImage1BPP(82 + 320 + 21 + 32 + 21, 100 + 38 * i, BMP_Jizhu, WHITE, BLACK); //����
        LCD_DrawImage1BPP(82 + 320 + 21 + 32 + 42, 100 + 38 * i, BMP_Jizhu, WHITE, BLACK); //����
        LCD_DrawImage1BPP(82 + 320 + 21 + 32 + 42 + 42, 100 + 38 * i, BMP_Wendu, WHITE, BLACK); //�¶�
        LCD_DrawImage1BPP(720 - 28, 100 + 38 * i, BMP_T, WHITE, BLACK); //��
    } 
    
    /*
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
    
    
    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 3, BMP_Kongtiao, WHITE, BLACK); //�յ�
    LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 3, BMP_Zhilen, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 320 + 42 + 42, 100 + 38 * 3, BMP_Qingqiu, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 320 + 42 + 42 + 42 + 2, 100 + 5 + 38 * 3, BMP_Maohao, WHITE, BLACK); //:  
    */
}

void BatteryUpdate1(unsigned char index) {
    unsigned char i = 0;
    for (i = 0; i < 8; i++) {
        updata_DAT(82 + 220, 100 - 8 + 38 * i, BAT_Pole_Temperature_P[index * 8 + i], 1, 40, YELLOW, 3, 0);
    }

    for (i = 0; i < 8; i++) {
        updata_DAT(82 + 220 + 320, 100 - 8 + 38 * i, BAT_Pole_Temperature_N[index * 8 + i], 1, 40, YELLOW, 3, 0);
    }
}

void frmBatteryFrame1_1(void) {
    if (f_index == 0) { //ֻ����һ��
        f_index = 1;
        BatteryFrame1(0);
    } else if (f_index == 1) {
        f_index = 1;
        BatteryUpdate1(0);
    } else {
        f_index = 0;
    }
    if (key_AV) {
        key_AV = 0;
        f_index = 0;
        frmID = 7;
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

void frmBatteryFrame1_2(void) {
    if (f_index == 0) { //ֻ����һ��
        f_index = 1;
        BatteryFrame1(1);
    } else if (f_index == 1) {
        f_index = 1;
        BatteryUpdate1(1);
    } else {
        f_index = 0;
    }
    if (key_AV) {
        key_AV = 0;
        f_index = 0;
        frmID = 9;
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
/*void AirFrame(void) {
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
    
    
    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 3, BMP_Kongtiao, WHITE, BLACK); //�յ�
    LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 3, BMP_Zhilen, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 320 + 42 + 42, 100 + 38 * 3, BMP_Qingqiu, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 320 + 42 + 42 + 42 + 2, 100 + 5 + 38 * 3, BMP_Maohao, WHITE, BLACK); //:  
    
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
*/
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
            frmIC();        
            //frmDMQ();
            break;
        case 4:
            frmSET();
            break;
        case 5:
            //frmDMY();
            break;
        case 6:            
            frmBMS();
            break;
        case 7:
            frmBattery();
            break;
        case 8:
            frmBatteryFrame1_2();
            break;
        case 9:   
            frmBatteryFrame1_1();
            //frmIC();           
            break;
        case 10:   
            //frmBCU_f();           
            break;    
        case 11:   
            //frmBCU_m();           
            break;
        case 12:   
            //frmBCU_r();           
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



