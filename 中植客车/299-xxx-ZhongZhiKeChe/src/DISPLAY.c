#include "SYSTEM.h"
#include "FONT.h"
#include "LOGO.h"

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

/*void LCD_DrawImageSBPP(unsigned int x,unsigned int y, //û�����֣�������0����ģΪBMP_BLANK
        unsigned char color, //������ɫ
        unsigned char witdh, //������
        __prog__ const unsigned char *img1, //����1
        unsigned char cont1, //����1����
        __prog__ const unsigned char *img2, //����2
        unsigned char cont2, //����1����
        __prog__ const unsigned char *img3, //����3
        unsigned char cont3, //����1����
        __prog__ const unsigned char *img4, //����4
        unsigned char cont4, //����1����
        __prog__ const unsigned char *img5 //����5
        ) {
    LCD_DrawImage1BPP(x, y, img1, color, BLACK);
    LCD_DrawImage1BPP(x + witdh * cont1, y, img2, color, BLACK);
    LCD_DrawImage1BPP(x + witdh * (cont1 + cont2), y, img3, color, BLACK);
    LCD_DrawImage1BPP(x + witdh * (cont1 + cont2 + cont3), y, img4, color, BLACK);
    LCD_DrawImage1BPP(x + witdh * (cont1 + cont2 + cont3 + cont4), y, img5, color, BLACK);
}
 */
//������
/*********************************************************
//������: void mainFrame(void)
//����: ��ʾ�����治��Ҫ���µ�����,�����ʽ
//����: ��
 *********************************************************/

void BMP_Men_Guan(unsigned int x, unsigned int y, unsigned char color) {
    //�����
    disp_rectange(x, y, 72, 2, 88, 2, color);
    /*LCD_DrawRect(x, y, 72, 2, color);
    LCD_DrawRect(x, y + 86, 72, 2, color);
    LCD_DrawRect(x, y, 2, 88, color);
    LCD_DrawRect(x + 70, y, 2, 88, color);*/
    //������
    LCD_DrawRect(x + 36, y + 2, 1, 81, color);
    //����̤��
    LCD_DrawRect(x + 7, y + 83, 57, 2, color);
    LCD_DrawRect(x + 7, y + 83, 1, 3, color);
    LCD_DrawRect(x + 7 + 56, y + 83, 1, 3, color);

    //�����ڿ�
    /*LCD_DrawRect(x + 4, y + 3, 29, 2, color);
    LCD_DrawRect(x + 4, y + 3 + 77, 29, 2, color);
    LCD_DrawRect(x + 3, y + 4, 2, 76, color);
    LCD_DrawRect(x + 3 + 30, y + 4, 2, 76, color);*/
    disp_rectange(x + 4, y + 3, 30, 2, 78, 2, color);

    //�����ڿ�
    /*LCD_DrawRect(x + 4 + 35, y + 3, 29 - 1, 2, color);
    LCD_DrawRect(x + 4 + 35, y + 3 + 77, 29 - 1, 2, color);
    LCD_DrawRect(x + 3 + 35, y + 4, 2, 76, color);
    LCD_DrawRect(x + 3 + 30 + 35 - 1, y + 4, 2, 76, color);*/
    disp_rectange(x + 4 + 35, y + 3, 29, 2, 78, 2, color);
}

void BMP_Men_Kai(unsigned int x, unsigned int y, unsigned char color) {
    //�����
    disp_rectange(x, y, 72, 2, 88, 2, color);
    //����̤��
    LCD_DrawRect(x + 7, y + 83, 57, 2, color);
    LCD_DrawRect(x + 7, y + 83, 1, 3, color);
    LCD_DrawRect(x + 7 + 56, y + 83, 1, 3, color);

    //������
    LCD_DrawRect(x + 36, y + 2, 1, 81, BLACK);

    //�����ڿ�
    disp_rectange(x + 4, y + 3, 30, 2, 78, 2, BLACK);

    //�����ڿ�
    //LCD_DrawRect(x + 4 + 35, y + 3, 29 - 1, 2, BLACK);
    //LCD_DrawRect(x + 4 + 35, y + 3 + 77, 29 - 1, 2, BLACK);
    //LCD_DrawRect(x + 3 + 35, y + 4, 2, 76, BLACK);
    //LCD_DrawRect(x + 3 + 30 + 35 - 1, y + 4, 2, 76, color);

    //LCD_DrawRect(x + 3 + 30 + 35 - 1, y + 4, 2, 76, BLACK); 
    //�����ڿ�
    //LCD_DrawRect(x + 4 + 35 + 8, y + 3, 20, 2, color);
    //LCD_DrawRect(x + 4 + 35 + 8, y + 3 + 77, 20, 2, color);
    //LCD_DrawRect(x + 3 + 35 + 8, y + 4, 2, 76, color);

    disp_rectange(x + 4 + 35, y + 3, 29, 2, 78, 2, BLACK);
}

/*void BMP_MOTO_CODE1(unsigned int x, unsigned int y, unsigned char color) {
    print_SZ_1(x - 60, y , 1, 3, 0, WHITE);
    LCD_DrawImage1BPP(x, y + 8, BMP_Loudian, color, BLACK); //©�籣��
    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Baohu, color, BLACK);

    print_SZ_1(x - 60, y  + 38, 2, 3, 0, WHITE);
    LCD_DrawImage1BPP(x, y + 8 + 38, BMP_Duzhuan, color, BLACK); //��ת����
    LCD_DrawImage1BPP(x + 42, y + 8 + 38, BMP_Baohu, color, BLACK);

    print_SZ_1(x - 60, y + 38 * 2, 3, 3, 0, WHITE);
    LCD_DrawImage1BPP(x, y + 8 + 38 * 2, BMP_Zijian, color, BLACK); //�Լ챣��
    LCD_DrawImage1BPP(x + 42, y + 8 + 38 * 2, BMP_Baohu, color, BLACK);

    print_SZ_1(x - 60, y + 38 * 3, 4, 3, 0, WHITE);
    LCD_DrawImage1BPP(x, y + 8 + 38 * 3, BMP_DJ, color, BLACK); //�����������
    LCD_DrawImage1BPP(x + 42, y + 8 + 38 * 3, BMP_Xianshu, color, BLACK);
    LCD_DrawImage1BPP(x + 42 + 42, y + 8 + 38 * 3, BMP_Guzhang, color, BLACK);

    print_SZ_1(x - 60, y + 38 * 4, 5, 3, 0, WHITE);
    LCD_DrawImage1BPP(x, y + 8 + 38 * 4, BMP_i, color, BLACK); //IPM����
    LCD_DrawImage1BPP(x + 11, y + 8 + 38 * 4, BMP_p, color, BLACK);
    LCD_DrawImage1BPP(x + 11 + 11, y + 8 + 38 * 4, BMP_m, color, BLACK);
    LCD_DrawImage1BPP(x + 11 + 11 + 11, y + 8 + 38 * 4, BMP_Guzhang, color, BLACK);

    print_SZ_1(x - 60, y + 38 * 5, 6, 3, 0, WHITE);
    LCD_DrawImage1BPP(x, y + 8 + 38 * 5, BMP_Zhu, color, BLACK); //���̵�������
    LCD_DrawImage1BPP(x + 21, y + 8 + 38 * 5, BMP_Jidianqi, color, BLACK);
    LCD_DrawImage1BPP(x + 21 + 63, y + 8 + 38 * 5, BMP_Guzhang, color, BLACK);

    print_SZ_1(x - 60, y + 38 * 6, 7, 3, 0, WHITE);
    LCD_DrawImage1BPP(x, y + 8 + 38 * 6, BMP_Yuchong, color, BLACK); //Ԥ��̵�������
    LCD_DrawImage1BPP(x + 42, y + 8 + 38 * 6, BMP_Jidianqi, color, BLACK);
    LCD_DrawImage1BPP(x + 42 + 63, y + 8 + 38 * 6, BMP_Guzhang, color, BLACK);

    print_SZ_1(x - 60, y + 38 * 7, 8, 3, 0, WHITE);
    LCD_DrawImage1BPP(x, y + 8 + 38 * 7, BMP_Ruanjian, color, BLACK); //�������
    LCD_DrawImage1BPP(x + 42, y + 8 + 38 * 7, BMP_Guzhang, color, BLACK);

    print_SZ_1(x - 60, y + 38 * 8, 51, 3, 0, WHITE);
    LCD_DrawImage1BPP(x, y + 8 + 38 * 8, BMP_DJ, color, BLACK); //������¹���
    LCD_DrawImage1BPP(x + 42, y + 8 + 38 * 8, BMP_Guo, color, BLACK);
    LCD_DrawImage1BPP(x + 42 + 21, y + 8 + 38 * 8, BMP_Wendu, color, BLACK);
    LCD_DrawImage1BPP(x + 42 + 42, y + 8 + 38 * 8, BMP_Guzhang, color, BLACK);

    print_SZ_1(x - 60, y + 38 * 9, 52, 3, 0, WHITE);
    LCD_DrawImage1BPP(x, y + 8 + 38 * 9, BMP_Mokuai, color, BLACK); //ģ����¹���
    LCD_DrawImage1BPP(x + 42, y + 8 + 38 * 9, BMP_Guo, color, BLACK);
    LCD_DrawImage1BPP(x + 42 + 21, y + 8 + 38 * 9, BMP_Wendu, color, BLACK);
    LCD_DrawImage1BPP(x + 42 + 42, y + 8 + 38 * 9, BMP_Guzhang, color, BLACK);

    print_SZ_1(x - 60 + 320, y, 53, 3, 0, WHITE);
    LCD_DrawImage1BPP(x + 320, y + 8, BMP_DJ, color, BLACK); //������ٹ���
    LCD_DrawImage1BPP(x + 320 + 42, y + 8, BMP_Chaosu, color, BLACK);
    LCD_DrawImage1BPP(x + 320 + 42 + 42, y + 8, BMP_Guzhang, color, BLACK);

    print_SZ_1(x - 60 + 320, y  + 38, 54, 3, 0, WHITE);
    print_SZ(x + 320, y + 12 + 38, 24, 2, 0, color);
    LCD_DrawImage1BPP(x + 320 + 16, y + 8 + 38, BMP_v, color, BLACK); //24VǷѹ����
    LCD_DrawImage1BPP(x + 320 + 16 + 11, y + 8 + 38, BMP_Qian, color, BLACK);
    LCD_DrawImage1BPP(x + 320 + 16 + 11, y + 8 + 38, BMP_DY, color, BLACK);
    LCD_DrawImage1BPP(x + 320 + 16 + 11 + 42, y + 8 + 38, BMP_Guzhang, color, BLACK);

    print_SZ_1(x - 60 + 320, y + 38 * 2, 55, 3, 0, WHITE);
    print_SZ(x + 320, y + 12 + 38 * 2, 24, 2, 0, color);
    LCD_DrawImage1BPP(x + 320 + 16, y + 8 + 38 * 2, BMP_v, color, BLACK); //24V��ѹ����                    
    LCD_DrawImage1BPP(x + 320 + 16 + 11, y + 8 + 38 * 2, BMP_DY, color, BLACK);
    LCD_DrawImage1BPP(x + 320 + 16 + 11, y + 8 + 38 * 2, BMP_Guo, color, BLACK);
    LCD_DrawImage1BPP(x + 320 + 16 + 11 + 42, y + 8 + 38 * 2, BMP_Guzhang, color, BLACK);

    print_SZ_1(x - 60 + 320, y + 38 * 3, 56, 3, 0, WHITE);
    LCD_DrawImage1BPP(x + 320, y + 8 + 38 * 3, BMP_c, color, BLACK); //CANͨѶ����
    LCD_DrawImage1BPP(x + 320 + 11, y + 8 + 38 * 3, BMP_a, color, BLACK);
    LCD_DrawImage1BPP(x + 320 + 11 + 11, y + 8 + 38 * 3, BMP_n, color, BLACK);
    LCD_DrawImage1BPP(x + 320 + 11 + 11 + 11, y + 8 + 38 * 3, BMP_Tongxun, color, BLACK);
    LCD_DrawImage1BPP(x + 320 + 11 + 11 + 11 + 42, y + 8 + 38 * 3, BMP_Guzhang, color, BLACK);

    print_SZ_1(x - 60 + 320, y + 38 * 4, 57, 3, 0, WHITE);
    LCD_DrawImage1BPP(x + 320, y + 8 + 38 * 4, BMP_DL, color, BLACK); //��������
    LCD_DrawImage1BPP(x + 320, y + 8 + 38 * 4, BMP_Guo, color, BLACK);
    LCD_DrawImage1BPP(x + 320 + 42, y + 8 + 38 * 4, BMP_Guzhang, color, BLACK);

    print_SZ_1(x - 60 + 320, y + 38 * 5, 58, 3, 0, WHITE);
    LCD_DrawImage1BPP(x + 320, y + 8 + 38 * 5, BMP_Guo, color, BLACK); //���ع���  
    LCD_DrawImage1BPP(x + 320 + 21, y + 8 + 38 * 5, BMP_Zai, color, BLACK);
    LCD_DrawImage1BPP(x + 320 + 42, y + 8 + 38 * 5, BMP_Guzhang, color, BLACK);

    print_SZ_1(x - 60 + 320, y+ 38 * 6, 59, 3, 0, WHITE);
    LCD_DrawImage1BPP(x + 320, y + 8 + 38 * 6, BMP_DY, color, BLACK); //Ƿѹ����
    LCD_DrawImage1BPP(x + 320, y + 8 + 38 * 6, BMP_Qian, color, BLACK);
    LCD_DrawImage1BPP(x + 320 + 42, y + 8 + 38 * 6, BMP_Guzhang, color, BLACK);

    print_SZ_1(x - 60 + 320, y  + 38 * 7, 60, 3, 0, WHITE);
    LCD_DrawImage1BPP(x + 320, y + 8 + 38 * 7, BMP_DY, color, BLACK); //��ѹ����
    LCD_DrawImage1BPP(x + 320, y + 8 + 38 * 7, BMP_Guo, color, BLACK);
    LCD_DrawImage1BPP(x + 42 + 320, y + 8 + 38 * 7, BMP_Guzhang, color, BLACK);

    print_SZ_1(x - 60 + 320, y + 38 * 8, 61, 3, 0, WHITE);
    LCD_DrawImage1BPP(x + 320, y + 8 + 38 * 8, BMP_Xiangweijiao, color, BLACK); //��λ�ǹ���
    LCD_DrawImage1BPP(x + 320 + 63, y + 8 + 38 * 8, BMP_Guzhang, color, BLACK);

    print_SZ_1(x - 60 + 320, y + 38 * 9, 62, 3, 0, WHITE);
    LCD_DrawImage1BPP(x + 320, y + 8 + 38 * 9, BMP_Yingjian, color, BLACK); //Ӳ��ĸ�߹�������
    LCD_DrawImage1BPP(x + 320 + 42, y + 8 + 38 * 9, BMP_Muxian, color, BLACK);
    LCD_DrawImage1BPP(x + 320 + 42 + 42, y + 8 + 38 * 9, BMP_DL, color, BLACK);
    LCD_DrawImage1BPP(x + 320 + 42 + 42, y + 8 + 38 * 9, BMP_Guo, color, BLACK);
    LCD_DrawImage1BPP(x + 320 + 42 + 42 + 42, y + 8 + 38 * 9, BMP_Guzhang, color, BLACK);

}

void BMP_MOTO_CODE2(unsigned int x, unsigned int y, unsigned char color) {
    print_SZ_1(x - 60, y, 65, 3, 0, WHITE);
    LCD_DrawImage1BPP(x, y + 8, BMP_Yingjian, color, BLACK); //Ӳ��ĸ�߹�ѹ����
    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Muxian, color, BLACK);
    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_DY, color, BLACK);
    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Guo, color, BLACK);
    LCD_DrawImage1BPP(x + 42 + 42 + 42, y + 8, BMP_Guzhang, color, BLACK);

    print_SZ_1(x - 60, y  + 38, 66, 3, 0, WHITE);
    LCD_DrawImage1BPP(x, y + 8 + 38, BMP_Yingjian, color, BLACK); //Ӳ��ĸ�߹�������
    LCD_DrawImage1BPP(x + 42, y + 8 + 38, BMP_Muxian, color, BLACK);
    LCD_DrawImage1BPP(x + 42 + 42, y + 8 + 38, BMP_DL, color, BLACK);
    LCD_DrawImage1BPP(x + 42 + 42, y + 8 + 38, BMP_Guo, color, BLACK);
    LCD_DrawImage1BPP(x + 42 + 42 + 42, y + 8 + 38, BMP_Guzhang, color, BLACK);

    print_SZ_1(x - 60, y  + 38 * 2, 101, 3, 0, WHITE);
    LCD_DrawImage1BPP(x, y + 8 + 38 * 2, BMP_Muxian, color, BLACK); //ĸ�߹�ѹ����
    LCD_DrawImage1BPP(x + 42, y + 8 + 38 * 2, BMP_DY, color, BLACK);
    LCD_DrawImage1BPP(x + 42, y + 8 + 38 * 2, BMP_Guo, color, BLACK);
    LCD_DrawImage1BPP(x + 42 + 42, y + 8 + 38 * 2, BMP_Baojing, color, BLACK);

    print_SZ_1(x - 60, y + 38 * 3, 102, 3, 0, WHITE);
    LCD_DrawImage1BPP(x, y + 8 + 38 * 3, BMP_Muxian, color, BLACK); //ĸ�߹�ѹ����
    LCD_DrawImage1BPP(x + 42, y + 8 + 38 * 3, BMP_DY, color, BLACK);
    LCD_DrawImage1BPP(x + 42, y + 8 + 38 * 3, BMP_Qian, color, BLACK);
    LCD_DrawImage1BPP(x + 42 + 42, y + 8 + 38 * 3, BMP_Baojing, color, BLACK);

    print_SZ_1(x - 60, y + 38 * 4, 151, 3, 0, WHITE);
    LCD_DrawImage1BPP(x, y + 8 + 38 * 4, BMP_DJ, color, BLACK); //������±���                   
    LCD_DrawImage1BPP(x + 42 + 21, y + 8 + 38 * 4, BMP_Wendu, color, BLACK);
    LCD_DrawImage1BPP(x + 42, y + 8 + 38 * 4, BMP_Guo, color, BLACK);
    LCD_DrawImage1BPP(x + 42 + 42, y + 8 + 38 * 4, BMP_Baojing, color, BLACK);

    print_SZ_1(x - 60, y + 38 * 5, 152, 3, 0, WHITE);
    LCD_DrawImage1BPP(x, y + 8 + 38 * 5, BMP_Mokuai, color, BLACK); //ģ����±���                   
    LCD_DrawImage1BPP(x + 42 + 21, y + 8 + 38 * 5, BMP_Wendu, color, BLACK);
    LCD_DrawImage1BPP(x + 42, y + 8 + 38 * 5, BMP_Guo, color, BLACK);
    LCD_DrawImage1BPP(x + 42 + 42, y + 8 + 38 * 5, BMP_Baojing, color, BLACK);
}
*/

void BMP_BUS(unsigned int x, unsigned int y) {
    unsigned char i;
    /*LCD_DrawRect(x + 209, y, 178, 2, WHITE); //����������
    LCD_DrawRect(x + 209, y + 8, 176, 2, WHITE);
    LCD_DrawRect(x + 209, y, 2, 8, WHITE);
    LCD_DrawRect(x + 209 + 176, y, 2, 8, WHITE);*/
    disp_rectange(x + 209, y, 178, 2, 10, 2, WHITE);

    LCD_DrawRect(x, y + 8, 471, 2, WHITE); //�����
    LCD_DrawRect(x, y + 8, 2, 92, WHITE); //����
    LCD_DrawImage1BPP(x, y + 8 + 92, Bmp_Xiahuaxian, WHITE, BLACK); //���»���
    LCD_DrawRect(x + 54, y + 8 + 105, 471 - 54 + 12, 2, WHITE); //�����
    LCD_DrawRect(x + 8, y + 8 + 12, 471 - 8, 2, WHITE); //�ڿ�
    LCD_DrawRect(x + 8, y + 8 + 12, 2, 92 - 12, WHITE); //�ڿ��
    LCD_DrawRect(x + 471 + 10, y + 8 + 105 - 34, 2, 34, WHITE); //��ͷ�³�

    LCD_DrawImage1BPP(x + 91, y + 76, Bmp_Luntai, WHITE, BLACK); //��̥1
    LCD_DrawImage1BPP(x + 91 + 227, y + 76, Bmp_Luntai, WHITE, BLACK); //��̥2

    //LCD_DrawImage1BPP(x + 195, y + 27, Bmp_Men, WHITE, BLACK); //��1

    BMP_Men_Guan(x + 195, y + 27, WHITE);

    //LCD_DrawImage1BPP(x + 184 + 215, y + 27, Bmp_Men, WHITE, BLACK); //��2

    BMP_Men_Guan(x + 184 + 215, y + 27, WHITE);

    LCD_DrawImage1BPP(x + 471, y + 6, Bmp_Chetou1, WHITE, BLACK); //��ͷ1
    LCD_DrawImage1BPP(x + 471 + 24, y + 6 + 13, Bmp_Chetou2, WHITE, BLACK); //��ͷ2
    LCD_DrawRect(x + 471 + 12, y + 6 + 13, 12, 2, WHITE);
    LCD_DrawRect(x + 471 + 12, y + 6 + 13 + 5, 12, 2, WHITE);


    /*LCD_DrawRect(x + 8 + 3, y + 8 + 12 + 3, 31, 1, WHITE); 
    LCD_DrawRect(x + 8 + 3, y + 8 + 12 + 3 + 20, 31, 1, WHITE); //
    LCD_DrawRect(x + 8 + 3, y + 8 + 12 + 3, 1, 20, WHITE); //
    LCD_DrawRect(x + 8 + 3 + 31, y + 8 + 12 + 3, 1, 20, WHITE); //*/
    //С����1
    disp_rectange(x + 8 + 3, y + 8 + 12 + 3, 31, 1, 20, 1, WHITE);

    /*LCD_DrawRect(x + 8 + 3 + 34, y + 8 + 12 + 3, 31, 1, WHITE); //С����2
    LCD_DrawRect(x + 8 + 3 + 34, y + 8 + 12 + 3 + 20, 31, 1, WHITE); //
    LCD_DrawRect(x + 8 + 3 + 34, y + 8 + 12 + 3, 1, 20, WHITE); //
    LCD_DrawRect(x + 8 + 3 + 31 + 34, y + 8 + 12 + 3, 1, 20, WHITE); //*/
    //С����2
    disp_rectange(x + 8 + 3 + 34, y + 8 + 12 + 3, 31, 1, 20, 1, WHITE);

    LCD_DrawRect(x + 8 + 3 + 15, y + 8 + 12 + 3 + 50, 32, 1, WHITE); //ɢ�ȿ�
    LCD_DrawRect(x + 8 + 3 + 15, y + 8 + 12 + 3 + 28 + 50, 32, 1, WHITE); //
    for (i = 0; i < 9; i++) {
        LCD_DrawRect(x + 8 + 3 + 15 + 4 * i, y + 8 + 12 + 3 + 50, 1, 28, WHITE); //
    }
    //LCD_DrawRect(150 + 8 + 3 + 35+15, 150 + 8 + 12 + 3+50, 1, 28, YELLOW); //

    /*LCD_DrawRect(x + 8 + 3 + 34 + 34, y + 8 + 12 + 3, 53, 1, WHITE); //�д���1
    LCD_DrawRect(x + 8 + 3 + 34 + 34, y + 8 + 12 + 3 + 46, 53, 1, WHITE); //
    LCD_DrawRect(x + 8 + 3 + 34 + 34, y + 8 + 12 + 3, 1, 46, WHITE); //
    LCD_DrawRect(x + 8 + 3 + 33 + 34 + 53, y + 8 + 12 + 3, 1, 46, WHITE); */
    //�д���1
    disp_rectange(x + 8 + 3 + 34 + 34, y + 8 + 12 + 3, 53, 1, 46, 1, WHITE);

    /*LCD_DrawRect(x + 8 + 3 + 34 + 34 + 56, y + 8 + 12 + 3, 53, 1, WHITE); //�д���2
    LCD_DrawRect(x + 8 + 3 + 34 + 34 + 56, y + 8 + 12 + 3 + 46, 53, 1, WHITE); //
    LCD_DrawRect(x + 8 + 3 + 34 + 34 + 56, y + 8 + 12 + 3, 1, 46, WHITE); //
    LCD_DrawRect(x + 8 + 3 + 33 + 34 + 53 + 56, y + 8 + 12 + 3, 1, 46, WHITE); */
    //�д���2
    disp_rectange(x + 8 + 3 + 34 + 34 + 56, y + 8 + 12 + 3, 53, 1, 46, 1, WHITE);

    /*LCD_DrawRect(x + 8 + 3 + 34 + 34 + 56 * 2 + 72 + 10, y + 8 + 12 + 3, 53, 1, WHITE); //ǰ����1
    LCD_DrawRect(x + 8 + 3 + 34 + 34 + 56 * 2 + 72 + 10, y + 8 + 12 + 3 + 46, 53, 1, WHITE); //
    LCD_DrawRect(x + 8 + 3 + 34 + 34 + 56 * 2 + 72 + 10, y + 8 + 12 + 3, 1, 46, WHITE); //
    LCD_DrawRect(x + 8 + 3 + 33 + 34 + 53 + 56 * 2 + 72 + 10, y + 8 + 12 + 3, 1, 46, WHITE); */
    //ǰ����1
    disp_rectange(x + 8 + 3 + 34 + 34 + 56 * 2 + 72 + 10, y + 8 + 12 + 3, 53, 1, 46, 1, WHITE);

    /*LCD_DrawRect(x + 8 + 3 + 34 + 34 + 56 * 3 + 72 + 20, y + 8 + 12 + 3, 53, 1, WHITE); //ǰ����2
    LCD_DrawRect(x + 8 + 3 + 34 + 34 + 56 * 3 + 72 + 20, y + 8 + 12 + 3 + 46, 53, 1, WHITE); //
    LCD_DrawRect(x + 8 + 3 + 34 + 34 + 56 * 3 + 72 + 20, y + 8 + 12 + 3, 1, 46, WHITE); //
    LCD_DrawRect(x + 8 + 3 + 33 + 34 + 53 + 56 * 3 + 72 + 20, y + 8 + 12 + 3, 1, 46, WHITE); */
    //ǰ����
    disp_rectange(x + 8 + 3 + 34 + 34 + 56 * 3 + 72 + 20, y + 8 + 12 + 3, 53, 1, 46, 1, WHITE);
}

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
    LCD_DrawRect(0, 430 + 15, 800, 2, GREEN); //�ײ�����   

    BMP_BUS(150, 150 + 40); //��BUS

    LCD_DrawImage1BPP(180, 150, BMP_s, WHITE, BLACK); //SOC
    LCD_DrawImage1BPP(180 + 11, 150, BMP_o, WHITE, BLACK);
    LCD_DrawImage1BPP(180 + 11 + 11, 150, BMP_c, WHITE, BLACK);

    disp_rectange(225, 150 + 5 - 10, 335, 2, 32, 2, WHITE);
    for (i = 0; i < 3; i++)
        LCD_DrawRect(225 + 83 + 83 * i, 145 - 10, 2, 10, WHITE);

    LCD_DrawImage1BPP(225 - 4, 155 - 14 - 10, BMP_SZ[0], WHITE, BLACK); //0

    print_SZ(225 + 83 + 83 + 83 + 84 - 12, 155 - 14 - 10, 100, 3, 0, WHITE); //100
    LCD_DrawImage1BPP(650, 155, BMP_Baifenhao, WHITE, BLACK);

    LCD_DrawImage1BPP(10, 365 + 15 - 50 + 10, Bmp_Licheng, YELLOW, BLACK); //���
    LCD_DrawImage1BPP(125, 318 + 15 + 38 + 8, BMP_HZ_KM, WHITE, BLACK); //��λ Km
    LCD_DrawImage1BPP(125, 318 + 15 + 38 * 2 + 8, BMP_HZ_KM, WHITE, BLACK); //��λ Km

    LCD_DrawImage1BPP(165, 365 + 15 - 50 + 10, BMP_DY, YELLOW, BLACK); //��ѹ���
    LCD_DrawImage1BPP(165, 365 + 15 - 50 + 10, BMP_Gao, YELLOW, BLACK);
    LCD_DrawImage1BPP(165 + 42, 365 + 15 - 50 + 10, BMP_DC, YELLOW, BLACK);
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

    LCD_DrawImage1BPP(670, 365 + 15 - 50 + 10, BMP_DJ, YELLOW, BLACK); //���
    LCD_DrawImage1BPP(670 + 42, 365 + 15 - 50 + 10, BMP_Zhuanju, YELLOW, BLACK); //ת��
    LCD_DrawImage1BPP(670 + 100, 365 + 15 - 50 + 10 + 38, BMP_n, WHITE, BLACK); //NM
    LCD_DrawImage1BPP(670 + 100 + 11, 365 + 15 - 50 + 10 + 38, BMP_m, WHITE, BLACK); //

    disp_rectange(5, 365 + 15 - 50, 150, 1, 115, 1, GREEN);
    disp_rectange(5 + 140 + 15, 365 + 15 - 50, 125, 1, 115, 1, GREEN);
    disp_rectange(5 + 270 + 15, 365 + 15 - 50, 125 - 5, 1, 115, 1, GREEN);
    disp_rectange(5 + 400 + 10, 365 + 15 - 50, 125 - 5, 1, 115, 1, GREEN);
    disp_rectange(5 + 530 + 5, 365 + 15 - 50, 125, 1, 115, 1, GREEN);
    disp_rectange(5 + 660 + 5, 365 + 15 - 50, 130 - 5, 1, 115, 1, GREEN);

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
        LCD_DrawImage1BPP(10 + 66 * 2, 5, Bmp_baojing[2], color, BLACK); //��ǰ��Ƭ
    }

    if (!fKL5) color = RED;
    else color = GRAY;
    if (color_old[3] != color) {
        color_old[3] = color;
        LCD_DrawImage1BPP(10 + 66 * 3, 5, Bmp_baojing[3], color, BLACK); //��ǰ��Ƭ
    }

    if (mKH1) color = RED;
    else color = GRAY;
    if (color_old[4] != color) {
        color_old[4] = color;
        LCD_DrawImage1BPP(10 + 66 * 4, 5, Bmp_baojing[4], color, BLACK); //�����
    }

    if (0) color = RED;
    else color = GRAY;
    if (color_old[5] != color) {
        color_old[5] = color;
        LCD_DrawImage1BPP(10 + 66 * 5, 5, Bmp_baojing[5], color, BLACK); //�����Ƭ

    }

    if (0) color = RED;
    else color = GRAY;
    if (color_old[6] != color) {
        color_old[6] = color;
        LCD_DrawImage1BPP(10 + 66 * 6, 5, Bmp_baojing[6], color, BLACK); //�Һ���Ƭ
    }

    if (mKL2 || fKL15) color = RED;
    else color = GRAY;
    if (color_old[7] != color) {
        color_old[7] = color;
        LCD_DrawImage1BPP(10 + 66 * 7, 5, Bmp_baojing[7], color, BLACK); //����
    }

    if (mKL4) color = RED;
    else color = GRAY;
    if (color_old[8] != color) {
        color_old[8] = color;
        LCD_DrawImage1BPP(10 + 66 * 8, 5, Bmp_baojing[8], color, BLACK); //ǰ��Ӧ����
    }

    if (mKL6) color = RED;
    else color = GRAY;
    if (color_old[9] != color) {
        color_old[9] = color;
        LCD_DrawImage1BPP(10 + 66 * 9, 5, Bmp_baojing[9], color, BLACK); //����Ӧ����
    }

    if (IN30)
        color = RED;
    else color = GRAY;
    if (color_old[10] != color) {
        color_old[10] = color;
        LCD_DrawImage1BPP(10 + 66 * 10, 5, Bmp_baojing[10], color, BLACK); //��ȫ��
    }

    if (VCU_Status == 3) color = RED;
    else color = GRAY;
    if (color_old[15] != color) {
        color_old[15] = color;
        LCD_DrawImage1BPP(10 + 66 * 11, 5, Bmp_baojing[11], color, BLACK); //��������
    }

    /*if (mKL4) color = RED;
    else color = GRAY;
    if (color_old[16] != color) {
        color_old[16] = color;
        //LCD_DrawImage1BPP(142 + 66 * 2, 74 - 10, Bmp_baojing[11], color, BLACK); //����Ӧ����
    }*/

    if (VCU_Status == 1) color = GREEN;
    else color = GRAY;
    if (color_old[17] != color) {
        color_old[17] = color;
        LCD_DrawImage1BPP(138 + 66 * 3 - 1, 74 + 12 - 5, Bmp_READY, color, BLACK); //ready
    }

    /*if (rKL5) color = RED;
    else color = GRAY;
    if (color_old[18] != color) {
        color_old[18] = color;
        //LCD_DrawImage1BPP(142 + 66 * 4, 74 - 10, Bmp_baojing[12], color, BLACK); //����1Ӧ����
    }

    if (mKL6) color = RED;
    else color = GRAY;
    if (color_old[19] != color) {
        color_old[19] = color;
        //LCD_DrawImage1BPP(142 + 66 * 5, 74 - 10, Bmp_baojing[13], color, BLACK); //����2Ӧ����
    }

    if (!fKL5) color = RED;
    else color = GRAY;
    if (color_old[20] != color) {
        color_old[20] = color;
        //LCD_DrawImage1BPP(142 + 66 * 6, 74-10, Bmp_baojing[20], color, BLACK); //��ɲ��Ƭĥ��
    }*/
}

void disp_CAN_baojing(unsigned int x, unsigned int y) {
    static unsigned char al_index = 0;
    if (alarm_update_flag == 0) { //3S ����һ�� 
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
                }
                if ((BMU_Comm_Status1 || BMU_Comm_Status2 || BMU_Comm_Status3 || BMU_Comm_Status4) && F_Comm) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_BMU, YELLOW, BLACK); //BMUͨѶ����
                    LCD_DrawImage1BPP(x + 33 + 16, y + 8, BMP_Tongxun, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 33 + 16 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 33 + 42 + 16 + 42, y, 200, 36, BLACK);
                    F_Comm = 0;
                    alarm_update_flag = 1;
                    break;
                }*/

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
                }
                if ((BMU_Bala_Status1 || BMU_Bala_Status2 || BMU_Bala_Status3 || BMU_Bala_Status4) && F_Bala) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_BMU, YELLOW, BLACK); //BMU�������
                    LCD_DrawImage1BPP(x + 33 + 16, y + 8, BMP_Junheng, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 33 + 16 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 33 + 16 + 42 + 42, y, 200, 36, BLACK);
                    F_Bala = 0;
                    alarm_update_flag = 1;
                    break;
                }*/

            case 2:
                al_index = 3;
                /*if (Rcan_count == CAN_TIME) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Houbu, YELLOW, BLACK); //��
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Mokuai, YELLOW, BLACK); //ģ��
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Lixian, YELLOW, BLACK); //����
                    LCD_DrawRect(x + 42 + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/

                /*case 0:
                    al_index = 1;
                    if (DMC_Protect_code == 1) {
                        LCD_DrawImage1BPP(x, y + 8, BMP_Loudian, YELLOW, BLACK); //©�籣��
                        LCD_DrawImage1BPP(x + 42, y + 8, BMP_Baohu, YELLOW, BLACK);
                        LCD_DrawRect(x + 42 + 42, y, 200, 36, BLACK);
                        alarm_update_flag = 1;
                        break;
                    }

                case 1:
                    al_index = 2;
                    if (DMC_Protect_code == 2) {
                        LCD_DrawImage1BPP(x, y + 8, BMP_Duzhuan, YELLOW, BLACK); //��ת����
                        LCD_DrawImage1BPP(x + 42, y + 8, BMP_Baohu, YELLOW, BLACK);
                        LCD_DrawRect(x + 42 + 42, y, 200, 36, BLACK);
                        alarm_update_flag = 1;
                        break;
                    }
                case 2:
                    al_index = 3;
                    if (DMC_Protect_code == 3) {
                        LCD_DrawImage1BPP(x, y + 8, BMP_Zijian, YELLOW, BLACK); //�Լ챣��
                        LCD_DrawImage1BPP(x + 42, y + 8, BMP_Baohu, YELLOW, BLACK);
                        LCD_DrawRect(x + 42 + 42, y, 200, 36, BLACK);
                        alarm_update_flag = 1;
                        break;
                    }

                case 3:
                    al_index = 4;
                    if (DMC_Protect_code == 4) {
                        LCD_DrawImage1BPP(x, y + 8, BMP_DJ, YELLOW, BLACK); //�����������
                        LCD_DrawImage1BPP(x + 42, y + 8, BMP_Xianshu, YELLOW, BLACK);
                        LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                        LCD_DrawRect(x + 42 + 42 + 42, y, 200, 36, BLACK);
                        alarm_update_flag = 1;
                        break;
                    }

                case 4:
                    al_index = 5;
                    if (DMC_Protect_code == 5) {
                        LCD_DrawImage1BPP(x, y + 8, BMP_i, YELLOW, BLACK); //IPM����
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
                        LCD_DrawImage1BPP(x, y + 8, BMP_Zhu, YELLOW, BLACK); //���̵�������
                        LCD_DrawImage1BPP(x + 21, y + 8, BMP_Jidianqi, YELLOW, BLACK);
                        LCD_DrawImage1BPP(x + 21 + 63, y + 8, BMP_Guzhang, YELLOW, BLACK);
                        LCD_DrawRect(x + 21 + 63 + 42, y, 200, 36, BLACK);
                        alarm_update_flag = 1;
                        break;
                    }
                case 6:
                    al_index = 7;
                    if (DMC_Protect_code == 7) {
                        LCD_DrawImage1BPP(x, y + 8, BMP_Yuchong, YELLOW, BLACK); //Ԥ��̵�������
                        LCD_DrawImage1BPP(x + 42, y + 8, BMP_Jidianqi, YELLOW, BLACK);
                        LCD_DrawImage1BPP(x + 42 + 63, y + 8, BMP_Guzhang, YELLOW, BLACK);
                        LCD_DrawRect(x + 42 + 63 + 42, y, 200, 36, BLACK);
                        alarm_update_flag = 1;
                        break;
                    }
                case 7:
                    al_index = 8;
                    if (DMC_Protect_code == 8) {
                        LCD_DrawImage1BPP(x, y + 8, BMP_Ruanjian, YELLOW, BLACK); //�������
                        LCD_DrawImage1BPP(x + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                        LCD_DrawRect(x + 42 + 42, y, 200, 36, BLACK);
                        alarm_update_flag = 1;
                        break;
                    }*/

            case 3:
                al_index = 4;
                if (BAT24V_count == BAT24_TIME) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Xu, YELLOW, BLACK); //���ص�ѹ��
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_DC, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 42, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 42 + 42, y + 8, BMP_Di, YELLOW, BLACK);
                    LCD_DrawRect(x + 21 + 42 + 42 + 21, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 4:
                al_index = 5;
                if (pSpeed > 69) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Chaosu, YELLOW, BLACK); //���ٱ���
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
                /*case 9:
                    al_index = 10;
                    if (DMC_Protect_code == 51) {
                        LCD_DrawImage1BPP(x, y + 8, BMP_DJ, YELLOW, BLACK); //������¹���
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
                        LCD_DrawImage1BPP(x, y + 8, BMP_Mokuai, YELLOW, BLACK); //ģ����¹���
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
                        LCD_DrawImage1BPP(x, y + 8, BMP_DJ, YELLOW, BLACK); //������ٹ���
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
                        LCD_DrawImage1BPP(x + 16, y + 8, BMP_v, YELLOW, BLACK); //24VǷѹ����
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
                        LCD_DrawImage1BPP(x + 16, y + 8, BMP_v, YELLOW, BLACK); //24V��ѹ����                    
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
                        LCD_DrawImage1BPP(x, y + 8, BMP_c, YELLOW, BLACK); //CANͨѶ����
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
                        LCD_DrawImage1BPP(x, y + 8, BMP_DL, YELLOW, BLACK); //��������
                        LCD_DrawImage1BPP(x, y + 8, BMP_Guo, YELLOW, BLACK);
                        LCD_DrawImage1BPP(x + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                        LCD_DrawRect(x + 42 + 42, y, 200, 36, BLACK);
                        alarm_update_flag = 1;
                        break;
                    }

                case 16:
                    al_index = 17;
                    if (DMC_Protect_code == 58) {
                        LCD_DrawImage1BPP(x, y + 8, BMP_Guo, YELLOW, BLACK); //���ع���  
                        LCD_DrawImage1BPP(x + 21, y + 8, BMP_Zai, YELLOW, BLACK);
                        LCD_DrawImage1BPP(x + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                        LCD_DrawRect(x + 42 + 42, y, 200, 36, BLACK);
                        alarm_update_flag = 1;
                        break;
                    }

                case 17:
                    al_index = 18;
                    if (DMC_Protect_code == 59) {
                        LCD_DrawImage1BPP(x, y + 8, BMP_DY, YELLOW, BLACK); //Ƿѹ����
                        LCD_DrawImage1BPP(x, y + 8, BMP_Qian, YELLOW, BLACK);
                        LCD_DrawImage1BPP(x + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                        LCD_DrawRect(x + 42 + 42 + 42, y, 200, 36, BLACK);
                        alarm_update_flag = 1;
                        break;
                    }

                case 18:
                    al_index = 19;
                    if (DMC_Protect_code == 60) {
                        LCD_DrawImage1BPP(x, y + 8, BMP_DY, YELLOW, BLACK); //��ѹ����
                        LCD_DrawImage1BPP(x, y + 8, BMP_Guo, YELLOW, BLACK);
                        LCD_DrawImage1BPP(x + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                        LCD_DrawRect(x + 42 + 42, y, 200, 36, BLACK);
                        alarm_update_flag = 1;
                        break;
                    }

                case 19:
                    al_index = 20;
                    if (DMC_Protect_code == 61) {
                        LCD_DrawImage1BPP(x, y + 8, BMP_Xiangweijiao, YELLOW, BLACK); //��λ�ǹ���
                        LCD_DrawImage1BPP(x + 63, y + 8, BMP_Guzhang, YELLOW, BLACK);
                        LCD_DrawRect(x + 63 + 42, y, 200, 36, BLACK);
                        alarm_update_flag = 1;
                        break;
                    }

                case 20:
                    al_index = 21;
                    if (DMC_Protect_code == 62) {
                        LCD_DrawImage1BPP(x, y + 8, BMP_Yingjian, YELLOW, BLACK); //Ӳ��ĸ�߹�������
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
                        LCD_DrawImage1BPP(x, y + 8, BMP_Yingjian, YELLOW, BLACK); //Ӳ��ĸ�߹�ѹ����
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
                        LCD_DrawImage1BPP(x, y + 8, BMP_Yingjian, YELLOW, BLACK); //Ӳ��ĸ�߹�������
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
                        LCD_DrawImage1BPP(x, y + 8, BMP_Muxian, YELLOW, BLACK); //ĸ�߹�ѹ����
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
                        LCD_DrawImage1BPP(x, y + 8, BMP_Muxian, YELLOW, BLACK); //ĸ�߹�ѹ����
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
                        LCD_DrawImage1BPP(x, y + 8, BMP_DJ, YELLOW, BLACK); //������±���                   
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
                        LCD_DrawImage1BPP(x, y + 8, BMP_Mokuai, YELLOW, BLACK); //ģ����±���                   
                        LCD_DrawImage1BPP(x + 42 + 21, y + 8, BMP_Wendu, YELLOW, BLACK);
                        LCD_DrawImage1BPP(x + 42, y + 8, BMP_Guo, YELLOW, BLACK);
                        LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                        LCD_DrawRect(x + 42 + 42 + 42, y, 200, 36, BLACK);
                        alarm_update_flag = 1;
                        break;
                    }*/

            case 5:
                al_index = 6;
                /*if (((BMS_Status_Flag1 & 0x03) == 1) || ((BMS_Status_Flag1 & 0x03) == 2)) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Dan, YELLOW, BLACK); //�����ѹ����
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_Ti, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 21, y + 8, BMP_DY, YELLOW, BLACK);
                    if((BMS_Status_Flag1 & 0x03) == 1){
                        LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Yiban, YELLOW, BLACK);
                    }else if((BMS_Status_Flag1 & 0x03) == 2){
                        LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Yanzhong, YELLOW, BLACK);
                    } 
                    LCD_DrawImage1BPP(x + 42 + 42 + 42, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 42 + 21, y + 8, BMP_Di, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42 + 42, y, 150, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/

            case 6:
                al_index = 7;
                /*if ((((BMS_Status_Flag1 >> 2) & 0x03) == 1) || (((BMS_Status_Flag1 >> 2) & 0x03) == 2)) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Dan, YELLOW, BLACK); //�����ѹ����
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_Ti, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 21, y + 8, BMP_DY, YELLOW, BLACK);
                    if(((BMS_Status_Flag1 >> 2) & 0x03) == 1){
                        LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Yiban, YELLOW, BLACK);
                    }else if(((BMS_Status_Flag1 >> 2) & 0x03) == 2){
                        LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Yanzhong, YELLOW, BLACK);
                    } 
                    LCD_DrawImage1BPP(x + 42 + 42 + 42, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 42 + 21, y + 8, BMP_Gao, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42 + 42, y, 150, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/

            case 7:
                al_index = 8;
                /*if ((((BMS_Status_Flag1 >> 4) & 0x03) == 1) || (((BMS_Status_Flag1 >> 4) & 0x03) == 2)) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Wendu, YELLOW, BLACK); //�¶ȹ���
                    if(((BMS_Status_Flag1 >> 4) & 0x03) == 1){
                        LCD_DrawImage1BPP(x + 42, y + 8, BMP_Yiban, YELLOW, BLACK);
                    }else if(((BMS_Status_Flag1 >> 4) & 0x03) == 2){
                        LCD_DrawImage1BPP(x + 42, y + 8, BMP_Yanzhong, YELLOW, BLACK);
                    } 
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 21, y + 8, BMP_Di, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/

            case 8:
                al_index = 9;
                /*if ((((BMS_Status_Flag1 >> 6) & 0x03) == 1) || (((BMS_Status_Flag1 >> 6) & 0x03) == 2)) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Wendu, YELLOW, BLACK); //�¶ȹ���
                    if(((BMS_Status_Flag1 >> 6) & 0x03) == 1){
                        LCD_DrawImage1BPP(x + 42, y + 8, BMP_Yiban, YELLOW, BLACK);
                    }else if(((BMS_Status_Flag1 >> 6) & 0x03) == 2){
                        LCD_DrawImage1BPP(x + 42, y + 8, BMP_Yanzhong, YELLOW, BLACK);
                    } 
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 21, y + 8, BMP_Gao, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/

            case 9:
                al_index = 10;
                /*if (((BMS_Status_Flag2 & 0x03) == 1) || ((BMS_Status_Flag2 & 0x03) == 2)) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_s, YELLOW, BLACK); //SOC����
                    LCD_DrawImage1BPP(x + 11, y + 8, BMP_o, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11, y + 8, BMP_c, YELLOW, BLACK);
                    if(((BMS_Status_Flag2) & 0x03) == 1){
                        LCD_DrawImage1BPP(x + 11 + 11 + 11, y + 8, BMP_Yiban, YELLOW, BLACK);
                    }else if(((BMS_Status_Flag2) & 0x03) == 2){
                        LCD_DrawImage1BPP(x + 11 + 11 + 11, y + 8, BMP_Yanzhong, YELLOW, BLACK);
                    } 
                    LCD_DrawImage1BPP(x + 11 + 11 + 11 + 42, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11 + 11 + 42 + 21, y + 8, BMP_Di, YELLOW, BLACK);
                    LCD_DrawRect(x + 11 + 11 + 11 + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/

            case 10:
                al_index = 11;
                /*if ((((BMS_Status_Flag2 >> 2) & 0x03) == 1) || (((BMS_Status_Flag2 >> 2) & 0x03) == 2)) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DL, YELLOW, BLACK); //��������
                    if(((BMS_Status_Flag2 >> 2) & 0x03) == 1){
                        LCD_DrawImage1BPP(x + 42, y + 8, BMP_Yiban, YELLOW, BLACK);
                    }else if(((BMS_Status_Flag2 >> 2) & 0x03) == 2){
                        LCD_DrawImage1BPP(x + 42, y + 8, BMP_Yanzhong, YELLOW, BLACK);
                    }
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 21, y + 8, BMP_Gao, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/

            case 11:
                al_index = 12;
                /*if ((((BMS_Status_Flag2 >> 4) & 0x03) == 1) || (((BMS_Status_Flag2 >> 4) & 0x03) == 2)) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Jueyuan, YELLOW, BLACK); //��Ե����
                    if(((BMS_Status_Flag2 >> 4) & 0x03) == 1){
                        LCD_DrawImage1BPP(x + 42, y + 8, BMP_Yiban, YELLOW, BLACK);
                    }else if(((BMS_Status_Flag2 >> 4) & 0x03) == 2){
                        LCD_DrawImage1BPP(x + 42, y + 8, BMP_Yanzhong, YELLOW, BLACK);
                    }
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/

            case 12:
                al_index = 13;
                /*if ((((BMS_Status_Flag2 >> 6) & 0x03) == 1) || (((BMS_Status_Flag2 >> 6) & 0x03) == 2)) {                  
                    LCD_DrawImage1BPP(x, y + 8, BMP_DC, YELLOW, BLACK);//���ѹ�����
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Yali, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 21, y + 8, BMP_Cha, YELLOW, BLACK); 
                    if(((BMS_Status_Flag2 >> 6) & 0x03) == 1){
                        LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Yiban, YELLOW, BLACK);
                    }else if(((BMS_Status_Flag2 >> 6) & 0x03) == 2){
                        LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Yanzhong, YELLOW, BLACK);
                    }
                    LCD_DrawImage1BPP(x + 42 + 42 + 42, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 42 + 21, y + 8, BMP_Da, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42 + 42, y, 150, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/

            case 13:
                al_index = 14;
                /*if (((BMS_Status_Flag3 >> 1) & 0x01) == 1) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Chongdian, YELLOW, BLACK); //���ͨѶ�쳣
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Tongxun, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Yichang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/

            case 14:
                al_index = 15;
                /*if (((BMS_Status_Flag3 >> 5) & 0x01) == 1) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Chongdian, YELLOW, BLACK); //����ֹͣʧЧ�������ֶ�ֹͣ���
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_DJ, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 63, y + 8, BMP_Tingzhi, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 63 + 42, y + 8, BMP_Shixiao, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 63 + 42 + 42, y + 8, BMP_Liji, YELLOW, BLACK);
                    //LCD_DrawRect(x + 63 + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/

            case 15:
                al_index = 16;
                /*if (((BMS_Status_Flag3 >> 6) & 0x01) == 1) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Chongdian, YELLOW, BLACK); //���Ӵ���ʧЧ�������ֶ�ֹͣ���
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Jiechuqi, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 63, y + 8, BMP_Shixiao, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 63 + 42, y + 8, BMP_Liji, YELLOW, BLACK);
                    //LCD_DrawRect(x + 42 + 63 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/

            case 16:
                al_index = 17;
                if (MCU_Warn_Number > 0 && MCU_Warn_Number < 252) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DJ, YELLOW, BLACK); //���ϵͳ����
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_System, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 17:
                al_index = 18;
                if (BMS_Fault_Level > 0) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DC, YELLOW, BLACK); //���ϵͳ����
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_System, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 18:
                al_index = 19;
                if (OCU_Fault_Code > 0) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Youbeng, YELLOW, BLACK); //�ͱ�ϵͳ����
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_System, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 19:
                al_index = 20;
                if (ACU_Fault_Code > 0) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Qibeng, YELLOW, BLACK); //����ϵͳ����
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_System, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 20:
                al_index = 21;
                if ((DCDC_CAN_Warn == 1)
                        || (DCDC_Temp_Warn == 1)
                        || (DCDC_Status_Warn == 1)
                        || (DCDC_Fault_Code > 0 && DCDC_Fault_Code < 9)) {
                    LCD_DrawImage1BPP(x, y + 6, BMP_DCDC, YELLOW, BLACK); //DCDCϵͳ����
                    LCD_DrawImage1BPP(x + 65, y + 8, BMP_System, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 65 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 65 + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 21:
                al_index = 22;
                if (VCU_Status == 3) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Zhengche, YELLOW, BLACK); //��������
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 22:
                al_index = 23;
                if (Fcan_count == CAN_TIME) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Qianbu, YELLOW, BLACK); //ǰ��
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Mokuai, YELLOW, BLACK); //ģ��
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Lixian, YELLOW, BLACK); //����
                    LCD_DrawRect(x + 42 + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 23:
                al_index = 24;
                if (Mcan_count == CAN_TIME) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Dingbu, YELLOW, BLACK); //����
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Mokuai, YELLOW, BLACK); //ģ��
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Lixian, YELLOW, BLACK); //����
                    LCD_DrawRect(x + 42 + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 24:
                al_index = 25;
                /*if (((BMS_Status_Flag3 >> 2) & 0x01) == 1) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DL, YELLOW, BLACK); //��������������
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Chuanganqi, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 63, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 63 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/

            case 25:
                al_index = 26;
                /*if (((BMS_Status_Flag3 >> 4) & 0x01) == 1) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Qing, YELLOW, BLACK); //������������ʻģʽ
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_Qiu, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Jinru, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Chesu, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Di, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 42, y + 8, BMP_Xingshi, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 42 + 42, y + 8, BMP_Mode, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42 + 42 + 42, y, 130, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/

            case 26:
                al_index = 27;
                /*if (((BMS_Status_Flag3 >> 3) & 0x01) == 1) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Qing, YELLOW, BLACK); //�������ǿ��ͣ��ģʽ
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_Qiu, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Jinru, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Qiangzhi, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 42, y + 8, BMP_Tingche, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 42 + 42, y + 8, BMP_Mode, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42 + 42 + 42, y, 130, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                
            case 27:
                al_index = 28;
                /*if (((BMS_Status_Flag6 >> 2) & 0x03) == 1) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DY, YELLOW, BLACK); //��ѹ��������
                    LCD_DrawImage1BPP(x, y + 8, BMP_Gao, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Husuo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 200, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                
            case 28:
                al_index = 29;
                /*if ((BMS_Status_Flag6 & 0x03) == 1) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Huozai, YELLOW, BLACK); //���ֱ���
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42, y, 250, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
            default:
                al_index = 0;
                LCD_DrawRect(x, y, 340, 36, BLACK); //�����ʾ����
                break;
        }
    }
}

void updata_Dangwei(unsigned int x, unsigned int y) {
    unsigned char gear = 1;
    gear = VCU_Gearbox;
    if (gear == 0) gear = 0;
    else if (gear == 13) gear = 1;
    else if (gear == 14) gear = 2;
    else if (gear == 15) gear = 3;
    else /*if(gear > 0 && gear < 7)*/ gear = 2;
    LCD_DrawImage1BPP(x, y, BMP_DANGWEI[gear], GREEN, BLACK); //��λ����   
}

void updata_SOC(unsigned int x, unsigned int y) {
    unsigned char color = WHITE;
    static unsigned char soc = 100;
    soc = BMS_SOC;
    /*if(F_DISP && (soc < BMS_SOC * 0.4)){//�����ӵ�Ч��
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
    print_SZ_1(x, y, soc, 3, 0, WHITE); //SOC��ֵ
    LCD_DrawRect(x - 360 + 2, y + 2, (soc * 3.31), 28, color); // 331/100  
    if (soc < 100)//��socΪ100ʱ�����//��ʱ�������
        LCD_DrawRect((x - 360 + 2 + soc * 3.31), y + 2, (331 - soc * 3.31), 28, BLACK);
}

void updata_DCDY(unsigned int x, unsigned int y) {
    //unsigned char color = GREEN;
    unsigned int DCDY = 50;
    DCDY = BMS_Voltage * 0.1;
    if (DCDY >= 800) DCDY = 800;
    print_SZ_1(x, y, DCDY, 4, 0, WHITE); //��ص�ѹ��ֵ x=120+72+30   y=150+60-2
    //if (frmID == 0)
    //    LCD_DrawRect(225 + 2, 150 + 5 + 2, DCDY * 3.31 * 0.125, 28, GREEN); // 331/100  
    //if (DCDY < 800 && frmID == 0)//��Ϊ100ʱ�����
    //    LCD_DrawRect((225 + 2 + DCDY * 3.31 * 0.125), 150 + 5 + 2, (331 - DCDY * 3.31 * 0.125), 28, BLACK);
}

void updata_DCDL(unsigned int x, unsigned int y) {
    unsigned int DCDL = 100;
    DCDL = BMS_Current * 0.1;
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
        LCD_DrawImage1BPPZOOM_4(x - 20, y + 4, BMP_ZHENG, BLACK, BLACK);
        print_SZ_1(x, y, DCDL, 3, 0, WHITE);
        //if (DCDL > 3 && frmID == 0)
        //    LCD_DrawRect(225 + 83 + 83 + 2, 150 + 5 + 2 + 60, (DCDL * 1.65 * 0.2), 28, GREEN); // �������Ϊ0�������
        //if (DCDL < 500 && frmID == 0) {
        //    LCD_DrawRect((225 + 83 + 83 + 2 + DCDL * 1.65 * 0.2), 150 + 5 + 2 + 60, (165 - DCDL * 1.65 * 0.2), 28, BLACK);
        //    LCD_DrawRect(225 + 2, 150 + 5 + 2 + 60, 164, 28, BLACK);
        //}
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
    if (f_index == 0) { //ֻ����һ��
        f_index = 1;
        mainFrame();
    } else if (f_index == 1) {
        f_index = 2;
        updata_DAT(700, 318 + 15 + 38, MCU_Torque, 0.1, 2000, WHITE, 4, 0); //���ת��
    } else if (f_index == 2) {
        f_index = 3;
        disp_baojing();
        print_SZ_1(305, 318 + 15 + 38, Battery_Single_H, 4, 3, WHITE); //����ߵ�ѹ
        print_SZ_1(305, 318 + 15 + 38 * 2, Battery_Single_L, 4, 3, WHITE); //����͵�ѹ
    } else if (f_index == 3) {
        f_index = 4;
        disp_miles();
        //�ſ���ͼ�񱨾�
        if (IN3) {
            BMP_Men_Kai(150 + 195, 190 + 27, RED); //��2��
        } else
            BMP_Men_Guan(150 + 195, 190 + 27, WHITE); //��2��
        if (IN4)
            BMP_Men_Kai(150 + 184 + 215, 190 + 27, RED); //��1��
        else
            BMP_Men_Guan(150 + 184 + 215, 190 + 27, WHITE); //��1��        
    } else if (f_index == 4) {
        f_index = 5;
        disp_time(360, 440 + 13, timer);
        updata_DAT(540 + 50, 318 + 15 + 38 * 2, MCU_Controller_Temp, 1, 40, WHITE, 3, 0); //����������¶�
        updata_DAT(540 + 50, 318 + 15 + 38, MCU_Temp, 1, 40, WHITE, 3, 0); //����¶�
    } else if (f_index == 5) {
        f_index = 6;
        updata_SOC(585, 155 - 10);
        updata_DCDY(150 + 45, 318 + 15 + 38); //�ܵ�ѹ
        updata_DCDL(150 + 45 + 16, 318 + 15 + 38 * 2); //�ܵ���
    } else if (f_index == 6) {
        f_index = 7;
        updata_DAT(410 + 50, 318 + 15 + 38, Battery_Temp_H, 1, 40, WHITE, 3, 0); //�������
        updata_DAT(410 + 50, 318 + 15 + 38 * 2, Battery_Temp_L, 1, 40, WHITE, 3, 0); //�������       
        disp_CAN_baojing(2, 450);
    } else if (f_index == 7) {
        f_index = 1;
        updata_Dangwei(138 + 17 + 66 * 4, 74 - 5);
        //print_H(480 + 30 -16, 318+15 + 38*2, tcu_spn, 5, 0, WHITE); //spn
        //print_SZ_1(480 + 30 + 16, 318 + 38, TCU_code, 3, 0, color); //ϵͳ����
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
            if (time_flag)
                t_add = 1;
            else t_add = 0;
        }
    }
    /***********************************************************/
    /*
        if (IN35 == 0) {//��������ѡ��ʹ�ܰ���
            if (IN11 && R_flag == 0) {//����
                key_AV = 1; //ģ��AV���ذ�һ��
                AV_CH = 0; //0+1=1  ����
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
            unsigned char mode = 1; //1,MCU

            if (AV_CH < 4 && !time_flag) AV_CH++;
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
     */
}

/******************************************************/
//�Ǳ����
/*******************************************************/
//ֻ����һ�ε�����
void ICFrame(unsigned char index) { //�Ǳ���
    unsigned char i;
    LCD_Clear();
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //��������
    
    //CANͨѶ
    LCD_DrawImage1BPP(130 + 200 + 200, 130 - 85 + 4, BMP_c, WHITE, BLACK);
    LCD_DrawImage1BPP(130 + 200 + 200 + 11, 130 - 85 + 4, BMP_a, WHITE, BLACK);
    LCD_DrawImage1BPP(130 + 200 + 200 + 11 + 11, 130 - 85 + 4, BMP_n, WHITE, BLACK);
    LCD_DrawImage1BPP(130 + 200 + 200 + 11 + 11 + 11, 130 - 85 + 4, BMP_Tongxun, WHITE, BLACK);

    //�汾��
    LCD_DrawImage1BPP(505 + 100, 75 + 8 + 25 * 15, BMP_Banben, WHITE, BLACK);
    LCD_DrawImage1BPP(505 + 100 + 42, 75 + 8 + 25 * 15, BMP_Hao, WHITE, BLACK);
    LCD_DrawImage1BPP(505 + 200, 75 + 25 * 15, BMP_V, WHITE, BLACK);
    
    if (index == 1) {
        LCD_DrawImage1BPP(130 + 200, 130 - 85, BMP_IC, WHITE, BLACK); //�Ǳ�
        LCD_DrawImage1BPP(130 + 200 + 50, 130 - 85, BMP_STSTEM, WHITE, BLACK); //ϵͳ
        LCD_DrawImage1BPP(130 + 200 + 50 + 50, 130 - 85, BMP_Message, WHITE, BLACK); //��Ϣ
               
        print_SZ_2(750, 50, 1, 1, 0, WHITE); // 1/3
        LCD_DrawImage1BPP(750 + 11, 50, BMP_I, WHITE, BLACK);
        print_SZ_2(750 + 11 + 14, 50, 3, 1, 0, WHITE);
        
       /***********************�Ǳ������ɼ�**********************************/
        //IN1  ��ת��
        LCD_DrawImage1BPP(35, 75, BMP_IC_Zuo, WHITE, BLACK);
        LCD_DrawImage1BPP(35 + 21, 75, BMP_IC_Zhuanxiang, WHITE, BLACK);
        //IN2
        //IN3  ���ſ�״̬
        LCD_DrawImage1BPP(35, 75 + 25 * 2, BMP_Zhong, WHITE, BLACK);
        LCD_DrawImage1BPP(35 + 21, 75 + 25 * 2, BMP_Men, WHITE, BLACK);
        LCD_DrawImage1BPP(35 + 42, 75 + 25 * 2, BMP_Kai, WHITE, BLACK);
        LCD_DrawImage1BPP(35 + 63, 75 + 25 * 2, BMP_Zhuangtai, WHITE, BLACK);
        //IN4  ǰ�ſ�״̬
        LCD_DrawImage1BPP(35, 75 + 25 * 3, BMP_IC_Qian, WHITE, BLACK);
        LCD_DrawImage1BPP(35 + 21, 75 + 25 * 3, BMP_Men, WHITE, BLACK);
        LCD_DrawImage1BPP(35 + 42, 75 + 25 * 3, BMP_Kai, WHITE, BLACK);
        LCD_DrawImage1BPP(35 + 63, 75 + 25 * 3, BMP_Zhuangtai, WHITE, BLACK);
        //IN5  ��ת��
        LCD_DrawImage1BPP(35, 75 + 25 * 4, BMP_IC_You, WHITE, BLACK);
        LCD_DrawImage1BPP(35 + 21, 75 + 25 * 4, BMP_IC_Zhuanxiang, WHITE, BLACK);
        //IN6  С��
        LCD_DrawImage1BPP(35, 75 + 25 * 5, BMP_Xiao, WHITE, BLACK);
        //IN7  Զ���
        LCD_DrawImage1BPP(35, 75 + 25 * 6, BMP_IC_Yuan, WHITE, BLACK);
        LCD_DrawImage1BPP(35 + 21, 75 + 25 * 6, BMP_IC_Guang, WHITE, BLACK);
        //IN8  �����
        LCD_DrawImage1BPP(35, 75 + 25 * 7, BMP_IC_Jin, WHITE, BLACK);
        LCD_DrawImage1BPP(35 + 21, 75 + 25 * 7, BMP_IC_Guang, WHITE, BLACK);
        //IN9  ǰ���
        LCD_DrawImage1BPP(35, 75 + 25 * 8, BMP_IC_Qian, WHITE, BLACK);
        LCD_DrawImage1BPP(35 + 21, 75 + 25 * 8, BMP_IC_Wu, WHITE, BLACK);
        //IN10 �����
        LCD_DrawImage1BPP(35, 75 + 25 * 9, BMP_IC_Hou, WHITE, BLACK);
        LCD_DrawImage1BPP(35 + 21, 75 + 25 * 9, BMP_IC_Wu, WHITE, BLACK);
        //IN11 ǰ��ѹ��������
        LCD_DrawImage1BPP(35, 75 + 25 * 10, BMP_IC_Qian, WHITE, BLACK);
        LCD_DrawImage1BPP(35 + 21, 75 + 25 * 10, BMP_Qiya, WHITE, BLACK);
        LCD_DrawImage1BPP(35 + 63, 75 + 25 * 10, BMP_Baojing, WHITE, BLACK);
        //IN12 ǰ��ѹ��������
        LCD_DrawImage1BPP(35, 75 + 25 * 11, BMP_IC_Hou, WHITE, BLACK);
        LCD_DrawImage1BPP(35 + 21, 75 + 25 * 11, BMP_Qiya, WHITE, BLACK);
        LCD_DrawImage1BPP(35 + 63, 75 + 25 * 11, BMP_Baojing, WHITE, BLACK);
        //IN13 
        //IN14 ��ε͵�       
        for(i=13;i<16;i++){
            LCD_DrawImage1BPP(35, 75 + 25 * i, BMP_IC_Yugua, WHITE, BLACK);
        }
        LCD_DrawImage1BPP(35 + 42, 75 + 25 * 13, BMP_Di, WHITE, BLACK);
        LCD_DrawImage1BPP(35 + 63, 75 + 25 * 13, BMP_Dang, WHITE, BLACK);
        //IN15 ��μ�Ъ��
        LCD_DrawImage1BPP(35 + 42, 75 + 25 * 14, BMP_Jianxie, WHITE, BLACK);
        LCD_DrawImage1BPP(35 + 84, 75 + 25 * 14, BMP_Dang, WHITE, BLACK);
        //IN16 ��θߵ�
        LCD_DrawImage1BPP(35 + 42, 75 + 25 * 15, BMP_Gao, WHITE, BLACK);
        LCD_DrawImage1BPP(35 + 63, 75 + 25 * 15, BMP_Dang, WHITE, BLACK);
        

        //�ƿ���
        for (i = 0; i < 16; i++) {
            if (i == 0 || i == 4 || i == 6 || i == 7 || i == 8 || i == 9) {
                if (i != 0 && i != 4)
                    LCD_DrawImage1BPP(35 + 42, 75 + 25 * i, BMP_IC_Deng, WHITE, BLACK);
                LCD_DrawImage1BPP(35 + 63, 75 + 25 * i, BMP_IC_Kaiguan, WHITE, BLACK);
            } else if (i == 5){
                LCD_DrawImage1BPP(35 + 21, 75 + 25 * i, BMP_IC_Deng, WHITE, BLACK);
                LCD_DrawImage1BPP(35 + 42, 75 + 25 * i, BMP_IC_Kaiguan, WHITE, BLACK);}
            else if (i == 13 || i == 15)
                LCD_DrawImage1BPP(35 + 84, 75 + 25 * i, BMP_IC_Kaiguan, WHITE, BLACK);
            else if (i == 14)
                LCD_DrawImage1BPP(35 + 105, 75 + 25 * i, BMP_IC_Kaiguan, WHITE, BLACK);
        }

        //IN17
        //IN18 ˾�����ȿ���
        LCD_DrawImage1BPP(285, 75 + 25 * 1, BMP_IC_Siji, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 42, 75 + 25 * 1, BMP_Fengshan, WHITE, BLACK);
        //IN19 ·�ƿ���
        LCD_DrawImage1BPP(285, 75 + 25 * 2, BMP_Lupai, WHITE, BLACK);
        //IN20      
        //IN21�����ˮ
        LCD_DrawImage1BPP(285, 75 + 25 * 4, BMP_IC_Yugua, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 42, 75 + 25 * 4, BMP_Penshui, WHITE, BLACK);
        //IN22
        //IN23 ����1����
        LCD_DrawImage1BPP(285, 75 + 25 * 6, BMP_Dengxiang, WHITE, BLACK);
        print_SZ_2(285 + 42 + 6, 75 + 25 * 6, 1, 1, 0, WHITE);
        //IN24 ����2����
        LCD_DrawImage1BPP(285, 75 + 25 * 7, BMP_Dengxiang, WHITE, BLACK);
        print_SZ_2(285 + 42 + 6, 75 + 25 * 7, 2, 1, 0, WHITE);
        //IN25 ˾���ƿ���
        LCD_DrawImage1BPP(285, 75 + 25 * 8, BMP_IC_Siji, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 42, 75 + 25 * 8, BMP_IC_Deng, WHITE, BLACK);
        //IN26 פ���ƶ�����
        LCD_DrawImage1BPP(285 , 75 + 25 * 9, BMP_Zhuche, WHITE, BLACK);  
        LCD_DrawImage1BPP(285 + 42, 75 + 25 * 9, BMP_Zhidong, WHITE, BLACK);  
        //IN27 ǿ���г�����
        LCD_DrawImage1BPP(285 , 75 + 25 * 10, BMP_Qiangzhi, WHITE, BLACK);  
        LCD_DrawImage1BPP(285 + 42, 75 + 25 * 10, BMP_Xingshi, WHITE, BLACK);
        //IN28 ���۷�����
        LCD_DrawImage1BPP(285 , 75 + 25 * 11, BMP_Paiwufa, WHITE, BLACK); 
        //IN29
        //IN30 ��ȫ������
        LCD_DrawImage1BPP(285 , 75 + 25 * 13, BMP_Anquandai, WHITE, BLACK); 
        //IN31
        //IN32       
        //����
        for (i = 0; i < 16; i++) {
            if (i==8 || i==11 || i == 13) {
                LCD_DrawImage1BPP(285 + 63, 75 + 25 * i, BMP_IC_Kaiguan, WHITE, BLACK);
            } else if (i == 2) {
                LCD_DrawImage1BPP(285 + 42, 75 + 25 * i, BMP_IC_Kaiguan, WHITE, BLACK);
            } else if (i == 1 || i == 4 || i == 9 || i == 10)
                LCD_DrawImage1BPP(285 + 84, 75 + 25 * i, BMP_IC_Kaiguan, WHITE, BLACK);
            else if (i == 6 || i == 7)
                LCD_DrawImage1BPP(285 + 42 + 11 + 6, 75 + 25 * i, BMP_IC_Kaiguan, WHITE, BLACK);
        }
        
        //IN33
        //IN34
        //IN35
        //IN36
        //IN37 ASR����
        LCD_DrawImage1BPP(535, 75 + 25 * 3, BMP_a, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 11, 75 + 25 * 3, BMP_s, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 11 + 11, 75 + 25 * 3, BMP_r, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 11 + 11 + 11, 75 + 25 * 3, BMP_Guzhang, WHITE, BLACK);
        //IN38 ABS����
        LCD_DrawImage1BPP(535, 75 + 25 * 4, BMP_a, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 11, 75 + 25 * 4, BMP_b, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 11 + 11, 75 + 25 * 4, BMP_s, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 11 + 11 + 11, 75 + 25 * 4, BMP_Guzhang, WHITE, BLACK);
        //IN38 Σ�ձ�������
        LCD_DrawImage1BPP(535, 75 + 25 * 5, BMP_Weixian, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 42, 75 + 25 * 5, BMP_Baojing, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 84, 75 + 25 * 5, BMP_IC_Kaiguan, WHITE, BLACK);
        //IN39 ACC���ѿ���
        LCD_DrawImage1BPP(535, 75 + 25 * 6, BMP_a, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 11, 75 + 25 * 6, BMP_c, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 11 + 11, 75 + 25 * 6, BMP_c, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 11 + 11 + 11, 75 + 25 * 6, BMP_Huanxing, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 11 + 11 + 11 + 42, 75 + 25 * 6, BMP_IC_Kaiguan, WHITE, BLACK);
        //IN40 Կ��ON����
        LCD_DrawImage1BPP(535, 75 + 25 * 7, BMP_o, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 11, 75 + 25 * 7, BMP_n, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 11 + 11, 75 + 25 * 7, BMP_Dang, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 11 + 11 + 21, 75 + 25 * 7, BMP_Huanxing, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 11 + 11 + 63, 75 + 25 * 7, BMP_IC_Kaiguan, WHITE, BLACK);
        
        LCD_DrawImage1BPP(535, 75 + 25 * 8, BMP_IC_Qian, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 21, 75 + 25 * 8, BMP_Qiya, WHITE, BLACK);
        
        LCD_DrawImage1BPP(535, 75 + 25 * 9, BMP_IC_Hou, WHITE, BLACK);
        LCD_DrawImage1BPP(535 + 21, 75 + 25 * 9, BMP_Qiya, WHITE, BLACK);    
        
        LCD_DrawImage1BPP(535, 75 + 25 * 14, BMP_Xu, YELLOW, BLACK); //���ص�ѹ
        LCD_DrawImage1BPP(535 + 21, 75 + 25 * 14, BMP_DC, YELLOW, BLACK);
        LCD_DrawImage1BPP(535 + 21 + 42, 75 + 25 * 14, BMP_DY, YELLOW, BLACK);
        LCD_DrawImage1BPP(535 + 63 + 42 + 16 * 4 + 16 * 5, 75 + 25 * 14, BMP_v, WHITE, BLACK); //V

        for (i = 8; i < 14; i++) {
            if(i>9)
            LCD_DrawImage1BPP(535 + 21, 75 + 25 * i, BMP_Beiyong, WHITE, BLACK);
            LCD_DrawImage1BPP(535 + 63, 75 + 25 * i, BMP_Xinhao, WHITE, BLACK);
            LCD_DrawImage1BPP(535 + 63 + 42 + 16 * 4 - 4, 75 + 25 * i, BMP_Omu, WHITE, BLACK); //��
            LCD_DrawImage1BPP(535 + 63 + 42 + 16 * 4 + 16 * 5, 75 + 25 * i, BMP_v, WHITE, BLACK); //V
        }
        
    } else if (index == 2) {
        print_SZ_2(750, 50, 2, 1, 0, WHITE); // 2/3
        LCD_DrawImage1BPP(750 + 11, 50, BMP_I, WHITE, BLACK);
        print_SZ_2(750 + 11 + 14, 50, 3, 1, 0, WHITE);
        
        LCD_DrawImage1BPP(130 + 200, 130 - 85, BMP_QIAN, WHITE, BLACK); //ǰ
        LCD_DrawImage1BPP(130 + 200 + 25, 130 - 85, BMP_MOKUAI, WHITE, BLACK); //ģ��
        LCD_DrawImage1BPP(130 + 200 + 25 + 50, 130 - 85, BMP_Message, WHITE, BLACK); //��Ϣ
        for (i = 0; i < 15; i++) {
            LCD_DrawImage1BPP(60 + 280, 75 + 25 * i, BMP_a, WHITE, BLACK);
            //LCD_DrawRect(0, 74 +25+ 25 * i, 800, 1, GRAY); //����
        }
        /*************************ǰģ�����***********************************/
        for (i = 0; i < 3; i++) {
            LCD_DrawImage1BPP(60, 75 + 25 * i, BMP_IC_Yugua, WHITE, BLACK);
        }
        //OUT1  �ߵ�
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 0, BMP_Gao, WHITE, BLACK);
        //OUT2  �͵�
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 1, BMP_Di, WHITE, BLACK);
        //OUT3  ��ˮ
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 2, BMP_Penshui, WHITE, BLACK);
        for (i = 0; i < 3; i++) {
            if (i != 2) LCD_DrawImage1BPP(60 + 63, 75 + 25 * i, BMP_Dang, WHITE, BLACK);
            LCD_DrawImage1BPP(60 + 84, 75 + 25 * i, BMP_DJ, WHITE, BLACK);
        }
        //OUT4  ��ǰ���
        LCD_DrawImage1BPP(60, 75 + 25 * 3, BMP_IC_Zuo, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 3, BMP_IC_Qian, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 3, BMP_IC_Wu, WHITE, BLACK);
        //OUT5  ���۷�
        LCD_DrawImage1BPP(60, 75 + 25 * 4, BMP_Paiwufa, WHITE, BLACK);
        //OUT6  ��ת���
        LCD_DrawImage1BPP(60, 75 + 25 * 5, BMP_IC_You, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 5, BMP_IC_Zhuanxiang, WHITE, BLACK);
        //OUT7  ��ת���
        LCD_DrawImage1BPP(60, 75 + 25 * 6, BMP_IC_Zuo, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 6, BMP_IC_Zhuanxiang, WHITE, BLACK);
        //OUT8  ������
        LCD_DrawImage1BPP(60, 75 + 25 * 7, BMP_Lengningqi, WHITE, BLACK);
        //OUT9  ��Զ���
        LCD_DrawImage1BPP(60, 75 + 25 * 8, BMP_IC_Zuo, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 8, BMP_IC_Yuan, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 8, BMP_IC_Guang, WHITE, BLACK);
        //OUT10 ��ǰ���
        LCD_DrawImage1BPP(60, 75 + 25 * 9, BMP_IC_You, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 9, BMP_IC_Qian, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 9, BMP_IC_Wu, WHITE, BLACK);
        //OUT11 ��Զ���
        LCD_DrawImage1BPP(60, 75 + 25 * 10, BMP_IC_You, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 10, BMP_IC_Yuan, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 10, BMP_IC_Guang, WHITE, BLACK);
        //OUT12 ���е�
        LCD_DrawImage1BPP(60, 75 + 25 * 11, BMP_Rixing, WHITE, BLACK);
        //OUT13 ������
        LCD_DrawImage1BPP(60, 75 + 25 * 12, BMP_IC_Zuo, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 12, BMP_IC_Jin, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 12, BMP_IC_Guang, WHITE, BLACK);
        //OUT14 λ�õ�
        LCD_DrawImage1BPP(60, 75 + 25 * 13, BMP_Weizhi, WHITE, BLACK);
        //OUT15 �ҽ����
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
            else if(i == 11 || i == 13)
                LCD_DrawImage1BPP(60 + 42, 75 + 25 * i, BMP_IC_Deng, WHITE, BLACK);
        }
        /***********************ǰģ�鿪�زɼ�*********************************/
        //KL1  ���Ħ��Ƭ����
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 0, BMP_IC_Zuo, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 21, 75 + 25 * 0, BMP_IC_Hou, WHITE, BLACK);
        //KL2
        //KL3  �Һ�Ħ��Ƭ����
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 2, BMP_IC_You, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 21, 75 + 25 * 2, BMP_IC_Hou, WHITE, BLACK);
        //KL4  ��ǰĦ��Ƭ����
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 3, BMP_IC_Zuo, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 21, 75 + 25 * 3, BMP_IC_Qian, WHITE, BLACK);
        //KL5  ��ǰĦ��Ƭ����
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 4, BMP_IC_You, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 21, 75 + 25 * 4, BMP_IC_Qian, WHITE, BLACK);
        for (i = 0; i < 5; i++) {
            if (i != 1) {
                LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * i, BMP_Mocapian, WHITE, BLACK);
                LCD_DrawImage1BPP(285 + 150 + 105, 75 + 25 * i, BMP_IC_Kaiguan, WHITE, BLACK);
            }
        }
        //KL6  �ƶ��ƿ���
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 5, BMP_Zhidong, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 5, BMP_IC_Deng, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 63, 75 + 25 * 5, BMP_IC_Kaiguan, WHITE, BLACK);
        //KL7
        //KL8  ���еƿ���
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 7, BMP_Rixing, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 7, BMP_IC_Deng, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 63, 75 + 25 * 7, BMP_IC_Kaiguan, WHITE, BLACK);
        //KL9
        //KL10 ���Ӿ����ȿ���
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 9, BMP_IC_Hou, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 21, 75 + 25 * 9, BMP_Shijing, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 63, 75 + 25 * 9, BMP_Jiare, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 105, 75 + 25 * 9, BMP_IC_Kaiguan, WHITE, BLACK);
        //KL11
        //KL12
        //KL13 ��ַѡ��1
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 12, BMP_Dizhi, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 12, BMP_Xuanze, WHITE, BLACK);
        print_SZ_2(285 + 150 + 84 + 6, 75 + 25 * 12, 1, 1, 0, WHITE);
        //KL14 ��ַѡ��2
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 13, BMP_Dizhi, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 13, BMP_Xuanze, WHITE, BLACK);
        print_SZ_2(285 + 150 + 84 + 6, 75 + 25 * 13, 2, 1, 0, WHITE);
        //KL15 ���忪��
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 14, BMP_Men, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 21, 75 + 25 * 14, BMP_Ling, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 14, BMP_IC_Kaiguan, WHITE, BLACK);
        //KH1
    } else if (index == 3) {
        print_SZ_2(750, 50, 3, 1, 0, WHITE); // 3/3
        LCD_DrawImage1BPP(750 + 11, 50, BMP_I, WHITE, BLACK);
        print_SZ_2(750 + 11 + 14, 50, 3, 1, 0, WHITE);
        
        LCD_DrawImage1BPP(130 + 200, 130 - 85, BMP_DING, WHITE, BLACK); //��
        LCD_DrawImage1BPP(130 + 200 + 25, 130 - 85, BMP_MOKUAI, WHITE, BLACK); //ģ��
        LCD_DrawImage1BPP(130 + 200 + 25 + 50, 130 - 85, BMP_Message, WHITE, BLACK); //��Ϣ
        for (i = 0; i < 15; i++) {
            LCD_DrawImage1BPP(60 + 280, 75 + 25 * i, BMP_a, WHITE, BLACK);
            //LCD_DrawRect(0, 74 +25+ 25 * i, 800, 1, GRAY); //����
        }

        /*********************��ģ�����***************************************/
        //OUT1  ǰ·�Ƶ�Դ
        LCD_DrawImage1BPP(60, 75 + 25 * 0, BMP_IC_Qian, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 0, BMP_Lupai, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 63, 75 + 25 * 0, BMP_Dianyuan, WHITE, BLACK);
        //OUT2  ���2
        LCD_DrawImage1BPP(60, 75 + 25 * 1, BMP_Dengxiang, WHITE, BLACK);
        print_SZ_2(60 + 42 + 6, 75 + 25 * 1, 2, 1, 0, WHITE);
        //OUT3  ǰ��̤����
        LCD_DrawImage1BPP(60, 75 + 25 * 2, BMP_IC_Qian, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 2, BMP_Men, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 2, BMP_Tabu, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 84, 75 + 25 * 2, BMP_IC_Deng, WHITE, BLACK);
        //OUT4  �ƶ���
        LCD_DrawImage1BPP(60, 75 + 25 * 3, BMP_Zhidong, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 3, BMP_IC_Deng, WHITE, BLACK);
        //OUT5  ����̤����
        LCD_DrawImage1BPP(60, 75 + 25 * 4, BMP_Zhong, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 4, BMP_Men, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 4, BMP_Tabu, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 84, 75 + 25 * 4, BMP_IC_Deng, WHITE, BLACK);
        //OUT6  ��·�Ƶ�Դ
        LCD_DrawImage1BPP(60, 75 + 25 * 5, BMP_IC_Hou, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 5, BMP_Lupai, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 63, 75 + 25 * 5, BMP_Dianyuan, WHITE, BLACK);
        //OUT7  ���Ӿ�����
        LCD_DrawImage1BPP(60, 75 + 25 * 6, BMP_IC_Hou, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 6, BMP_Shijing, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 63, 75 + 25 * 6, BMP_Jiare, WHITE, BLACK);
        //OUT8  �����
        LCD_DrawImage1BPP(60, 75 + 25 * 7, BMP_IC_Hou, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 7, BMP_IC_Wu, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 7, BMP_IC_Deng, WHITE, BLACK);
        //OUT9  ��·��
        LCD_DrawImage1BPP(60, 75 + 25 * 8, BMP_Ce, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 8, BMP_Lupai, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 63, 75 + 25 * 8, BMP_Dianyuan, WHITE, BLACK);
        //OUT10 ˾������
        LCD_DrawImage1BPP(60, 75 + 25 * 9, BMP_IC_Siji, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 9, BMP_Fengshan, WHITE, BLACK);
        //OUT11 ��������Դ
        LCD_DrawImage1BPP(60, 75 + 25 * 10, BMP_Gundongping, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 63, 75 + 25 * 10, BMP_Dianyuan, WHITE, BLACK);
        //OUT12 ˾���Ƶ�Դ
        LCD_DrawImage1BPP(60, 75 + 25 * 11, BMP_IC_Siji, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 11, BMP_IC_Deng, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 63, 75 + 25 * 11, BMP_Dianyuan, WHITE, BLACK);
        //OUT13 ������
        LCD_DrawImage1BPP(60, 75 + 25 * 12, BMP_Daoche, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 12, BMP_IC_Deng, WHITE, BLACK);
        //OUT14 �űõ�Դ       
        LCD_DrawImage1BPP(60, 75 + 25 * 13, BMP_Qibeng, WHITE, BLACK);
        LCD_DrawImage1BPP(60, 75 + 25 * 13, BMP_Men, WHITE, BLACK);
        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 13, BMP_Dianyuan, WHITE, BLACK);
        //OUT15 ���1
        LCD_DrawImage1BPP(60, 75 + 25 * 14, BMP_Dengxiang, WHITE, BLACK);
        print_SZ_2(60 + 42 + 6, 75 + 25 * 14, 1, 1, 0, WHITE);

        /************************��ģ�鿪��*********************************/
        //KL1
        //KL2  ���忪��
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 1, BMP_Men, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 21, 75 + 25 * 1, BMP_Ling, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 1, BMP_IC_Kaiguan, WHITE, BLACK);
        //KL3
        //KL4  ǰ��Ӧ��������
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 3, BMP_IC_Qian, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 21, 75 + 25 * 3, BMP_Men, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 3, BMP_Yingjifa, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 105, 75 + 25 * 3, BMP_Baojing, WHITE, BLACK);
        //print_SZ_2(285 + 150 + 105 + 42 + 6, 75 + 25 * 3, 2, 1, 0, WHITE);
        //KL5
        //KL6  ����Ӧ��������
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
        //KL13 ��ַѡ��1
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 12, BMP_Dizhi, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 12, BMP_Xuanze, WHITE, BLACK);
        print_SZ_2(285 + 150 + 84 + 6, 75 + 25 * 12, 1, 1, 0, WHITE);
        //KL14 ��ַѡ��2
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 13, BMP_Dizhi, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 13, BMP_Xuanze, WHITE, BLACK);
        print_SZ_2(285 + 150 + 84 + 6, 75 + 25 * 13, 2, 1, 0, WHITE);
        //KL15
        //KH1  ����ſ���
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 15, BMP_IC_Hou, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 21, 75 + 25 * 15, BMP_Cangmen, WHITE, BLACK);  
        LCD_DrawImage1BPP(285 + 150 + 63, 75 + 25 * 15, BMP_IC_Kaiguan, WHITE, BLACK);
        
    } else if (index == 4) {
        LCD_DrawImage1BPP(130 + 200, 130 - 85, BMP_HOU, WHITE, BLACK); //��
        LCD_DrawImage1BPP(130 + 200 + 25, 130 - 85, BMP_MOKUAI, WHITE, BLACK); //ģ��
        LCD_DrawImage1BPP(130 + 200 + 25 + 50, 130 - 85, BMP_Message, WHITE, BLACK); //��Ϣ
        for (i = 0; i < 15; i++) {
            LCD_DrawImage1BPP(60 + 280, 75 + 3 + 25 * i, BMP_a, WHITE, BLACK);
            //LCD_DrawRect(0, 74 +25+ 25 * i, 800, 1, GRAY); //����
        }
        //�ƶ���
        LCD_DrawImage1BPP(60, 75 + 25 * 0, BMP_Zhidong, WHITE, BLACK);       
        //��·��
        LCD_DrawImage1BPP(60, 75 + 25 * 1, BMP_Ce, WHITE, BLACK);  
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 1, BMP_Lupai, WHITE, BLACK);  
        //�����
        LCD_DrawImage1BPP(60, 75 + 25 * 2, BMP_IC_Hou, WHITE, BLACK);  
        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 2, BMP_IC_Wu, WHITE, BLACK);  
        //������������Դ
        //LCD_DrawImage1BPP(60, 75 + 25 * 3, BMP_Zhengche, WHITE, BLACK);  
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
        //LCD_DrawImage1BPP(60 + 21, 75 + 25 * 7, BMP_Laba, WHITE, BLACK);
        print_SZ_2(60 + 63 + 6, 75 + 25 * 7, 1, 1, 0, WHITE);
        //������1
        LCD_DrawImage1BPP(60, 75 + 25 * 8, BMP_Daoche, WHITE, BLACK);
        print_SZ_2(60 + 63 + 6, 75 + 25 * 8, 1, 1, 0, WHITE);
        //������2
        LCD_DrawImage1BPP(60, 75 + 25 * 9, BMP_DC, WHITE, BLACK);
//        LCD_DrawImage1BPP(60 + 21, 75 + 25 * 9, BMP_Laba, WHITE, BLACK);
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
//        LCD_DrawImage1BPP(60 + 42, 75 + 25 * 13, BMP_Laba, WHITE, BLACK);
        //������2
        LCD_DrawImage1BPP(60, 75 + 25 * 14, BMP_Daoche, WHITE, BLACK);
        print_SZ_2(60 + 63 + 6, 75 + 25 * 14, 2, 1, 0, WHITE);

        //��
        for (i = 0; i < 16; i++) {
            if (i == 0 || i == 2 || i == 8 || i == 11 || i == 14)
                LCD_DrawImage1BPP(60 + 42, 75 + 25 * i, BMP_IC_Deng, WHITE, BLACK);
            if (i == 4 || i == 6)
                LCD_DrawImage1BPP(60 + 63, 75 + 25 * i, BMP_IC_Deng, WHITE, BLACK);
            if(i==10 || i==12)
                LCD_DrawImage1BPP(60 + 84, 75 + 25 * i, BMP_IC_Deng, WHITE, BLACK);
        }   

        //ˮλ����
        //��ǰĦ��Ƭ����
        //ǰ��Ӧ��������1
        //��ǰĦ��Ƭ����
        //����Ӧ��������1
        //�ƶ�����
        //פ���ƶ����� 
        //�����
        //��ַѡ��1
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 12, BMP_Dizhi, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 12, BMP_Xuanze, WHITE, BLACK);
        print_SZ_2(285 + 150 + 84 + 6, 75 + 25 * 12, 1, 1, 0, WHITE);
        //��ַѡ��2
        LCD_DrawImage1BPP(285 + 150, 75 + 25 * 13, BMP_Dizhi, WHITE, BLACK);
        LCD_DrawImage1BPP(285 + 150 + 42, 75 + 25 * 13, BMP_Xuanze, WHITE, BLACK);
        print_SZ_2(285 + 150 + 84 + 6, 75 + 25 * 13, 2, 1, 0, WHITE);     
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
        
        //print_SZ_2(535 + 63 + 42 + 16 * 5 , 75 + 25 * 8, ADV[1], 4, 0, YELLOW);
        //print_SZ_2(535 + 63 + 42 + 16 * 5 , 75 + 25 * 9, ADV[2], 4, 0, YELLOW);
        
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
            if (fpcur[i] / 100 > 3)//С��300mA����ʾ����
                print_SZ(30 + 250, 75 + 3 + 25 * i, fpcur[i] / 100, 3, 1, YELLOW); //ǰģ�����
            else
                print_SZ(30 + 250, 75 + 3 + 25 * i, 0, 3, 1, YELLOW);
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
            if (mpcur[i] / 100 > 3)
                print_SZ(30 + 250, 75 + 3 + 25 * i, mpcur[i] / 100, 3, 1, YELLOW); //��ģ�����
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
            if (rpcur[i] / 100 > 3)
                print_SZ(30 + 250, 75 + 3 + 25 * i, rpcur[i] / 100, 3, 1, YELLOW); //��ģ�����
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
//�˵�ѡ�����
/*******************************************************/
//ֻ����һ�ε�����

void MenuFrame(void) {
    LCD_Clear();
    unsigned char color = WHITE;
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //��������   

    LCD_DrawRect(0, 430 + 15, 800, 2, YELLOW); //�ײ�����
    LCD_DrawImage1BPP(130, 130, BMP_VCU, color, BLACK); //����
    LCD_DrawImage1BPP(130 + 50, 130, BMP_STSTEM, color, BLACK); //ϵͳ
    LCD_DrawImage1BPP(130 + 50 + 50, 130, BMP_Message, color, BLACK); //��Ϣ

    LCD_DrawImage1BPP(130, 130 + 35, BMP_DMQ, color, BLACK); //����
    LCD_DrawImage1BPP(130 + 50, 130 + 35, BMP_STSTEM, color, BLACK); //ϵͳ
    LCD_DrawImage1BPP(130 + 50 + 50, 130 + 35, BMP_Message, color, BLACK); //��Ϣ

    LCD_DrawImage1BPP(130, 130 + 35 + 35, BMP_DCDC, color, BLACK); //DCDC
    LCD_DrawImage1BPP(130 + 65, 130 + 35 + 35, BMP_STSTEM, color, BLACK); //ϵͳ
    LCD_DrawImage1BPP(130 + 65 + 50, 130 + 35 + 35, BMP_Message, color, BLACK); //��Ϣ

    LCD_DrawImage1BPP(130, 130 + 35 + 35 + 35, BMP_DMY, color, BLACK); //�ͱ�
    LCD_DrawImage1BPP(130 + 50, 130 + 35 + 35 + 35, BMP_STSTEM, color, BLACK); //ϵͳ
    LCD_DrawImage1BPP(130 + 50 + 50, 130 + 35 + 35 + 35, BMP_Message, color, BLACK); //��Ϣ

    LCD_DrawImage1BPP(130 + 350, 130, BMP_Battery, color, BLACK); //���
    LCD_DrawImage1BPP(130 + 350 + 50, 130, BMP_Manage, color, BLACK); //����
    LCD_DrawImage1BPP(130 + 350 + 50 + 50, 130, BMP_STSTEM, color, BLACK); //ϵͳ
    LCD_DrawImage1BPP(130 + 350 + 50 + 50 + 50, 130, BMP_Message, color, BLACK); //��Ϣ

/*    LCD_DrawImage1BPP(130 + 350, 130 + 35, BMP_Battery, color, BLACK); //���   
    LCD_DrawImage1BPP(130 + 350 + 50, 130 + 35, BMP_Message, color, BLACK); //��Ϣ
*/
    LCD_DrawImage1BPP(130 + 350, 130 + 35 * 1, BMP_IC, color, BLACK); //�Ǳ�
    LCD_DrawImage1BPP(130 + 50 + 350, 130 + 35 * 1, BMP_STSTEM, color, BLACK); //ϵͳ
    LCD_DrawImage1BPP(130 + 50 + 50 + 350, 130 + 35 * 1, BMP_Message, color, BLACK); //��Ϣ

    /*LCD_DrawImage1BPP(130 + 350, 130 + 35 + 35, BMP_Air, color, BLACK); //�յ�
    LCD_DrawImage1BPP(130 + 350 + 50, 130 + 35 + 35, BMP_STSTEM, color, BLACK); //ϵͳ
    LCD_DrawImage1BPP(130 + 350 + 50 + 50, 130 + 35 + 35, BMP_Message, color, BLACK); //��Ϣ   
     */
}
//һֱ���µ�����
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

    if (key_duble) {
        key_duble = 0;
        if (time_flag == 0) {
            f_index = 0;
            frmID = 8;
        }
    }

    if (key_AV) {//��ͷ������
        key_AV = 0;
        if (time_flag)
            t_add = 1;
        if (!time_flag)
            i--;
    }

    if (i == 12) i = 6;
    if (i == 0) i = 6;
    //�Ӳ˵����л�
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
    /*if (i == 12 || i == 6) {
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
    LCD_DrawImage1BPP(105 + 350, 131 + 2 * 35, BMP_Choose, color, BLACK);*/
    /*    if (i == 14 || i == 7) {
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
        disp_time(360, 440 + 13, timer);
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
//�����Ͻ���
/*******************************************************/
//ֻ����һ�ε�����
void VCUFrame(unsigned char index) {
    unsigned char i = 0;
    LCD_Clear();
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //��������
    LCD_DrawImage1BPP(130 + 200, 130 - 85, BMP_VCU, WHITE, BLACK); //����
    LCD_DrawImage1BPP(130 + 200 + 50, 130 - 85, BMP_STSTEM, WHITE, BLACK); //ϵͳ
    LCD_DrawImage1BPP(130 + 200 + 50 + 50, 130 - 85, BMP_Message, WHITE, BLACK); //��Ϣ

    LCD_DrawRect(80, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320 + 320, 90, 1, 380, GREEN);
    for (i = 0; i < 11; i++)
        LCD_DrawRect(80, 90 + i * 38, 640, 1, GREEN);

    if (index == 1) {
        print_SZ(750, 50, 1, 1, 0, WHITE); // 1/2
        LCD_DrawImage1BPP(750 + 8, 50 - 3, BMP_I, WHITE, BLACK);
        print_SZ(750 + 8 + 14, 50, 2, 1, 0, WHITE);
        LCD_DrawImage1BPP(82, 100 + 38 * 0, BMP_Zhengche, WHITE, BLACK); //����
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 0, BMP_KZQ, WHITE, BLACK); //������
        LCD_DrawImage1BPP(82 + 42 + 63, 100 + 38 * 0, BMP_Zhuangtai, WHITE, BLACK); //״̬
        
        LCD_DrawImage1BPP(82, 100 + 38 * 1, BMP_Gao, WHITE, BLACK); //��ѹ��������
        LCD_DrawImage1BPP(82 + 21, 100 + 38 * 1, BMP_Yali, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 1, BMP_Husuo, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 1, BMP_Baojing, WHITE, BLACK); //
        
        LCD_DrawImage1BPP(82, 100 + 38 * 2, BMP_Zhidong, WHITE, BLACK); //�ƶ�ϵͳ����
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 2, BMP_System, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 2, BMP_Baojing, WHITE, BLACK); //
        
        LCD_DrawImage1BPP(82, 100 + 38 * 3, BMP_Zhengche, WHITE, BLACK); //����״̬
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 3, BMP_Zhuangtai, WHITE, BLACK); //
        
        LCD_DrawImage1BPP(82, 100 + 38 * 4, BMP_Yunxing, WHITE, BLACK); //����״̬
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 4, BMP_Zhuangtai, WHITE, BLACK); //
        
        LCD_DrawImage1BPP(82, 100 + 38 * 5, BMP_Chesu, WHITE, BLACK); //����
        LCD_DrawImage1BPP(400 - 24 - 11 - 11 - 11, 100 + 38 * 5, BMP_k, WHITE, BLACK); //km/h
        LCD_DrawImage1BPP(400 - 24 - 11 - 11, 100 + 38 * 5, BMP_m, WHITE, BLACK); //
        LCD_DrawImage1BPP(400 - 24 - 11, 100 + 38 * 5, BMP_I, WHITE, BLACK); //
        LCD_DrawImage1BPP(400 - 24, 100 + 38 * 5, BMP_h, WHITE, BLACK); //
        
        LCD_DrawImage1BPP(82, 100 + 38 * 6, BMP_Zhidong, WHITE, BLACK); //�ƶ���״̬
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 6, BMP_Li, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 42 + 21, 100 + 38 * 6, BMP_Zhuangtai, WHITE, BLACK); //
        
        LCD_DrawImage1BPP(82, 100 + 38 * 7, BMP_Qudong, WHITE, BLACK); //������״̬
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 7, BMP_Li, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 42 + 21, 100 + 38 * 7, BMP_Zhuangtai, WHITE, BLACK); //
        
        LCD_DrawImage1BPP(82, 100 + 38 * 8, BMP_Chong, WHITE, BLACK); //���״̬
        LCD_DrawImage1BPP(82 + 21, 100 + 38 * 8, BMP_DC, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 8, BMP_Zhuangtai, WHITE, BLACK); //
        
        LCD_DrawImage1BPP(82, 100 + 38 * 9, BMP_Baojing, WHITE, BLACK); //�����ȼ�
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 9, BMP_Dengji, WHITE, BLACK); //
        
        LCD_DrawImage1BPP(82 + 320, 100 + 38 * 0, BMP_Youmen, WHITE, BLACK); //����
        LCD_DrawImage1BPP(82 + 42 + 320, 100 + 38 * 0, BMP_Taban, WHITE, BLACK); //̤��
        LCD_DrawImage1BPP(82 + 42 + 42 + 320, 100 + 38 * 0, BMP_Kaidu, WHITE, BLACK); //����
        LCD_DrawImage1BPP(720 - 24, 100 + 38 * 0, BMP_Baifenhao, WHITE, BLACK); //%

        LCD_DrawImage1BPP(82 + 320, 100 + 38 * 1, BMP_Zhidong, WHITE, BLACK); //�ƶ�
        LCD_DrawImage1BPP(82 + 42 + 320, 100 + 38 * 1, BMP_Taban, WHITE, BLACK); //̤��
        LCD_DrawImage1BPP(82 + 42 + 42 + 320, 100 + 38 * 1, BMP_Kaidu, WHITE, BLACK); //����
        LCD_DrawImage1BPP(720 - 24, 100 + 38 * 1, BMP_Baifenhao, WHITE, BLACK); //%
        
        LCD_DrawImage1BPP(82 + 320, 100 + 38 * 2, BMP_Guzhang, WHITE, BLACK); //����
        LCD_DrawImage1BPP(82 + 42 + 320, 100 + 38 * 2, BMP_Zong, WHITE, BLACK); //��
        LCD_DrawImage1BPP(82 + 42 + 21 + 320, 100 + 38 * 2, BMP_Shu, WHITE, BLACK); //��
        
        LCD_DrawImage1BPP(82 + 320, 100 + 38 * 3, BMP_Qudong, WHITE, BLACK); //�����������
        LCD_DrawImage1BPP(82 + 42 + 320, 100 + 38 * 3, BMP_DJ, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 42 + 42 + 320, 100 + 38 * 3, BMP_Zong, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 42 + 42 + 21 + 320, 100 + 38 * 3, BMP_Shu, WHITE, BLACK); //
        
        
/*******************************************************************************/        
        /*LCD_DrawImage1BPP(82, 100, BMP_KZQ, WHITE, BLACK); //������
        LCD_DrawImage1BPP(82 + 63, 100, BMP_Muxian, WHITE, BLACK); //ĸ��
        LCD_DrawImage1BPP(82 + 63 + 42, 100, BMP_DY, WHITE, BLACK); //��ѹ
        LCD_DrawImage1BPP(400 - 24, 100, BMP_v, WHITE, BLACK); //v

        LCD_DrawImage1BPP(82, 100 + 38, BMP_KZQ, WHITE, BLACK); //������
        LCD_DrawImage1BPP(82 + 63, 100 + 38, BMP_Muxian, WHITE, BLACK); //ĸ��
        LCD_DrawImage1BPP(82 + 63 + 42, 100 + 38, BMP_DL, WHITE, BLACK); //����
        LCD_DrawImage1BPP(400 - 24, 100 + 38, BMP_a, WHITE, BLACK); //a

        LCD_DrawImage1BPP(82, 100 + 38 * 2, BMP_Chesu, WHITE, BLACK); //����
        LCD_DrawImage1BPP(400 - 24 - 11 - 11 - 11, 100 + 38 * 2, BMP_k, WHITE, BLACK); //km/h
        LCD_DrawImage1BPP(400 - 24 - 11 - 11, 100 + 38 * 2, BMP_m, WHITE, BLACK); //
        LCD_DrawImage1BPP(400 - 24 - 11, 100 + 38 * 2, BMP_I, WHITE, BLACK); //
        LCD_DrawImage1BPP(400 - 24, 100 + 38 * 2, BMP_h, WHITE, BLACK); //

        LCD_DrawImage1BPP(82, 100 + 38 * 3, BMP_KZQ, WHITE, BLACK); //������
        LCD_DrawImage1BPP(82 + 63, 100 + 38 * 3, BMP_Jiben, WHITE, BLACK); //����
        LCD_DrawImage1BPP(82 + 63 + 42, 100 + 38 * 3, BMP_Zhuangtai, WHITE, BLACK); //״̬

        LCD_DrawImage1BPP(82, 100 + 38 * 4, BMP_DJ, WHITE, BLACK); //���
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 4, BMP_KZQ, WHITE, BLACK); //������
        LCD_DrawImage1BPP(82 + 42 + 63, 100 + 38 * 4, BMP_Life, WHITE, BLACK); //Life

        LCD_DrawImage1BPP(82, 100 + 38 * 5, BMP_d, WHITE, BLACK); //DMC
        LCD_DrawImage1BPP(82 + 11, 100 + 38 * 5, BMP_m, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 11 + 11, 100 + 38 * 5, BMP_c, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 11 + 11 + 11, 100 + 38 * 5, BMP_Banben, WHITE, BLACK); //�汾
        LCD_DrawImage1BPP(82 + 11 + 11 + 11 + 42, 100 + 38 * 5, BMP_Hao, WHITE, BLACK); //��
        LCD_DrawImage1BPP(400 - 24 - 96, 100 + 38 * 5 - 9, BMP_V, WHITE, BLACK); //V

        LCD_DrawImage1BPP(82, 100 + 38 * 6, BMP_Chong, WHITE, BLACK); //��ŵ�״̬
        LCD_DrawImage1BPP(82 + 21, 100 + 38 * 6, BMP_Fangdian, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 21 + 21, 100 + 38 * 6, BMP_DC, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 21 + 21 + 21, 100 + 38 * 6, BMP_Zhuangtai, WHITE, BLACK); //

        
        LCD_DrawImage1BPP(82, 100 + 38 * 7, BMP_Guobiao, WHITE, BLACK); //���굵λ
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 7, BMP_Dangwei, WHITE, BLACK); //

        LCD_DrawImage1BPP(82, 100 + 38 * 8, BMP_Guobiao, WHITE, BLACK); //��������
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 8, BMP_Youmen, WHITE, BLACK);
        LCD_DrawImage1BPP(400 - 24, 100 + 38 * 8, BMP_Baifenhao, WHITE, BLACK); //%

        LCD_DrawImage1BPP(82, 100 + 38 * 9, BMP_Guobiao, WHITE, BLACK); //�����ƶ�
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 9, BMP_Zhidong, WHITE, BLACK);
        LCD_DrawImage1BPP(400 - 24, 100 + 38 * 9, BMP_Baifenhao, WHITE, BLACK); //%
        

        LCD_DrawImage1BPP(82 + 320, 100, BMP_DJ, WHITE, BLACK); //���
        LCD_DrawImage1BPP(82 + 320 + 42, 100, BMP_Dangqian, WHITE, BLACK); //��ǰ
        LCD_DrawImage1BPP(82 + 320 + 42 + 42, 100, BMP_Zhuansu, WHITE, BLACK); //ת��
        LCD_DrawImage1BPP(720 - 24 - 24, 100, BMP_RPM, WHITE, BLACK); //RPM

        LCD_DrawImage1BPP(82 + 320, 100 + 38, BMP_DJ, WHITE, BLACK); //���
        LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38, BMP_Dangqian, WHITE, BLACK); //��ǰ
        LCD_DrawImage1BPP(82 + 320 + 42 + 42, 100 + 38, BMP_Zhuanju, WHITE, BLACK); //ת��
        LCD_DrawImage1BPP(720 - 24 - 11, 100 + 38, BMP_n, WHITE, BLACK); //NM
        LCD_DrawImage1BPP(720 - 24, 100 + 38, BMP_m, WHITE, BLACK); //

        LCD_DrawImage1BPP(82 + 320, 100 + 38 * 2, BMP_DJ, WHITE, BLACK); //���
        LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 2, BMP_Wendu, WHITE, BLACK); //�¶�
        LCD_DrawImage1BPP(720 - 28, 100 + 38 * 2, BMP_T, WHITE, BLACK); //��

        LCD_DrawImage1BPP(82 + 320, 100 + 38 * 3, BMP_KZQ, WHITE, BLACK); //������
        LCD_DrawImage1BPP(82 + 320 + 63, 100 + 38 * 3, BMP_Wendu, WHITE, BLACK); //�¶�
        LCD_DrawImage1BPP(720 - 28, 100 + 38 * 3, BMP_T, WHITE, BLACK); //��

        LCD_DrawImage1BPP(82 + 320, 100 + 38 * 4, BMP_Youmen, WHITE, BLACK); //����
        LCD_DrawImage1BPP(82 + 42 + 320, 100 + 38 * 4, BMP_Taban, WHITE, BLACK); //̤��
        LCD_DrawImage1BPP(82 + 42 + 42 + 320, 100 + 38 * 4, BMP_Kaidu, WHITE, BLACK); //����
        LCD_DrawImage1BPP(720 - 24, 100 + 38 * 4, BMP_Baifenhao, WHITE, BLACK); //%

        LCD_DrawImage1BPP(82 + 320, 100 + 38 * 5, BMP_Zhidong, WHITE, BLACK); //�ƶ�
        LCD_DrawImage1BPP(82 + 42 + 320, 100 + 38 * 5, BMP_Taban, WHITE, BLACK); //̤��
        LCD_DrawImage1BPP(82 + 42 + 42 + 320, 100 + 38 * 5, BMP_Kaidu, WHITE, BLACK); //����
        LCD_DrawImage1BPP(720 - 24, 100 + 38 * 5, BMP_Baifenhao, WHITE, BLACK); //%

        LCD_DrawImage1BPP(82 + 320, 100 + 38 * 6, BMP_KZQ, WHITE, BLACK); //������
        LCD_DrawImage1BPP(82 + 320 + 63, 100 + 38 * 6, BMP_Guzhang, WHITE, BLACK); //����
        LCD_DrawImage1BPP(82 + 320 + 63 + 42, 100 + 38 * 6, BMP_Code, WHITE, BLACK); //����

        LCD_DrawImage1BPP(82 + 320, 100 + 38 * 7, BMP_KZQ, WHITE, BLACK); //������
        LCD_DrawImage1BPP(82 + 320 + 63, 100 + 38 * 7, BMP_Guzhang, WHITE, BLACK); //����
        LCD_DrawImage1BPP(82 + 320 + 63 + 42, 100 + 38 * 7, BMP_Dengji, WHITE, BLACK); //�ȼ�
        */
    }else if(index == 2){
        print_SZ(750, 50, 2, 1, 0, WHITE); // 1/2
        LCD_DrawImage1BPP(750 + 8, 50 - 3, BMP_I, WHITE, BLACK);
        print_SZ(750 + 8 + 14, 50, 2, 1, 0, WHITE);
        
        LCD_DrawImage1BPP(82, 100 + 38 * 0, BMP_Qudong, WHITE, BLACK); //����������
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 0, BMP_DJ, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 0, BMP_Hao, WHITE, BLACK); //   
        
        LCD_DrawImage1BPP(82, 100 + 38 * 1, BMP_Qudong, WHITE, BLACK); //�������״̬
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 1, BMP_DJ, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 1, BMP_Zhuangtai, WHITE, BLACK); //
        
        LCD_DrawImage1BPP(82, 100 + 38 * 2, BMP_Qudong, WHITE, BLACK); //��������¶�
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 2, BMP_DJ, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 2, BMP_Wendu, WHITE, BLACK); //
        LCD_DrawImage1BPP(400 - 28, 100 + 38 * 2, BMP_T, WHITE, BLACK); //��
        
        LCD_DrawImage1BPP(82, 100 + 38 * 3, BMP_Qudong, WHITE, BLACK); //��������������¶�
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 3, BMP_DJ, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 3, BMP_KZQ, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 42 + 42 + 63, 100 + 38 * 3, BMP_Wendu, WHITE, BLACK); //
        LCD_DrawImage1BPP(400 - 28, 100 + 38 * 3, BMP_T, WHITE, BLACK); //��
        
        LCD_DrawImage1BPP(82, 100 + 38 * 4, BMP_DJ, WHITE, BLACK); //������
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 4, BMP_KZQ, WHITE, BLACK); //������
        LCD_DrawImage1BPP(82 + 42 + 63, 100 + 38 * 4, BMP_Input, WHITE, BLACK); //����
        LCD_DrawImage1BPP(82 + 42 + 63 + 42, 100 + 38 * 4, BMP_DY, WHITE, BLACK); //��ѹ
        LCD_DrawImage1BPP(400 - 20, 100 + 38 * 4, BMP_v, WHITE, BLACK); //v

        LCD_DrawImage1BPP(82, 100 + 38 * 5, BMP_DJ, WHITE, BLACK); //���
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 5, BMP_KZQ, WHITE, BLACK); //������
        LCD_DrawImage1BPP(82 + 42 + 63, 100 + 38 * 5, BMP_Muxian, WHITE, BLACK); //ĸ��
        LCD_DrawImage1BPP(82 + 42 + 63 + 42, 100 + 38 * 5, BMP_DL, WHITE, BLACK); //����
        LCD_DrawImage1BPP(400 - 20, 100 + 38 * 5, BMP_a, WHITE, BLACK); //a
        
        
        
        
        LCD_DrawImage1BPP(82 + 320, 100, BMP_Qudong, WHITE, BLACK); //����
        LCD_DrawImage1BPP(82 + 320 + 42, 100, BMP_DJ, WHITE, BLACK); //���
        LCD_DrawImage1BPP(82 + 320 + 42 + 42, 100, BMP_Zhuansu, WHITE, BLACK); //ת��
        LCD_DrawImage1BPP(720 - 24 - 24, 100, BMP_RPM, WHITE, BLACK); //RPM

        LCD_DrawImage1BPP(82 + 320, 100 + 38, BMP_Qudong, WHITE, BLACK); //����
        LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38, BMP_DJ, WHITE, BLACK); //���
        LCD_DrawImage1BPP(82 + 320 + 42 + 42, 100 + 38, BMP_Zhuanju, WHITE, BLACK); //ת��
        LCD_DrawImage1BPP(720 - 24 - 11, 100 + 38, BMP_n, WHITE, BLACK); //NM
        LCD_DrawImage1BPP(720 - 24, 100 + 38, BMP_m, WHITE, BLACK); //
        
        LCD_DrawImage1BPP(82 + 320, 100 + 38 * 2, BMP_Qudong, WHITE, BLACK); //����
        LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 2, BMP_DJ, WHITE, BLACK); //���
        LCD_DrawImage1BPP(82 + 320 + 42 + 42, 100 + 38 * 2, BMP_KZQ, WHITE, BLACK); //������
        LCD_DrawImage1BPP(82 + 320 + 42 + 42 + 63, 100 + 38 * 2, BMP_Wendu, WHITE, BLACK); //�¶�
        LCD_DrawImage1BPP(82 + 320 + 42 + 42 + 63 + 42, 100 + 38 * 2, BMP_Baojing, WHITE, BLACK); //����

        LCD_DrawImage1BPP(82 + 320, 100 + 38 * 3, BMP_Qudong, WHITE, BLACK); //����
        LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 3, BMP_DJ, WHITE, BLACK); //���
        LCD_DrawImage1BPP(82 + 320 + 42 + 42, 100 + 38 * 3, BMP_Wendu, WHITE, BLACK); //�¶�
        LCD_DrawImage1BPP(82 + 320 + 42 + 42 + 42, 100 + 38 * 3, BMP_Baojing, WHITE, BLACK); //����

        LCD_DrawImage1BPP(82 + 320, 100 + 38 * 4, BMP_Qudong, WHITE, BLACK); //���������������
        LCD_DrawImage1BPP(82 + 42 + 320, 100 + 38 * 4, BMP_DJ, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 42 + 42 + 320, 100 + 38 * 4, BMP_Guzhang, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 42 + 42 + 42 + 320, 100 + 38 * 4, BMP_Zong, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 42 + 42 + 42 + 21 + 320, 100 + 38 * 4, BMP_Shu, WHITE, BLACK); //

        LCD_DrawImage1BPP(82 + 320 + 180, 100 + 38 * 5, BMP_s, WHITE, BLACK); //SPN
        LCD_DrawImage1BPP(82 + 320 + 180 + 11, 100 + 38 * 5, BMP_p, WHITE, BLACK); //  
        LCD_DrawImage1BPP(82 + 320 + 180 + 11 + 11, 100 + 38 * 5, BMP_n, WHITE, BLACK); //

        LCD_DrawImage1BPP(82 + 320 + 250, 100 + 38 * 5, BMP_f, WHITE, BLACK); //FMI
        LCD_DrawImage1BPP(82 + 320 + 250 + 11, 100 + 38 * 5, BMP_m, WHITE, BLACK); //  
        LCD_DrawImage1BPP(82 + 320 + 250 + 11 + 11, 100 + 38 * 5, BMP_i, WHITE, BLACK); //

        LCD_DrawImage1BPP(82 + 320, 100 + 38 * 6, BMP_System, WHITE, BLACK); //ϵͳ������Ϣ
        LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 6, BMP_Guzhang, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 320 + 42 + 42, 100 + 38 * 6, BMP_Xinxi, WHITE, BLACK); //
    }/*else if(index == 3){
        print_SZ(750, 50, 3, 1, 0, WHITE); // 1/3
        LCD_DrawImage1BPP(750 + 8, 50 - 3, BMP_I, WHITE, BLACK);
        print_SZ(750 + 8 + 14, 50, 3, 1, 0, WHITE);
        BMP_MOTO_CODE2(150, 100 - 8, WHITE);        
    }*/

}
//һֱ���µ�����
void VCUUpdate(unsigned char index) {
    //unsigned int temp = 0;
    static unsigned char Status_Old[5];
    if(index == 1){
        if (VCU_Status == 0)
            LCD_DrawImage1BPP(82 + 180 + 42, 100 + 38 * 0, BMP_Zhunbei, GREEN, BLACK);
        else if (VCU_Status == 1)
            LCD_DrawImage1BPP(82 + 180 + 42, 100 + 38 * 0, BMP_Jiuxu, GREEN, BLACK);
        else if (VCU_Status == 2)
            LCD_DrawImage1BPP(82 + 180 + 42, 100 + 38 * 0, BMP_Yunxing, GREEN, BLACK);
        else if (VCU_Status == 3)
            LCD_DrawImage1BPP(82 + 180 + 42, 100 + 38 * 0, BMP_Guzhang, RED, BLACK);
        
        if (VCU_Lock_Warn == 0)
            LCD_DrawImage1BPP(82 + 180 + 42, 100 + 38 * 1, BMP_Zhengchang, GREEN, BLACK);
        else if (VCU_Lock_Warn == 1)
            LCD_DrawImage1BPP(82 + 180 + 42, 100 + 38 * 1, BMP_Guzhang, RED, BLACK);
        
        if (VCU_Brake_Warn == 0)
            LCD_DrawImage1BPP(82 + 180 + 42, 100 + 38 * 2, BMP_Zhengchang, GREEN, BLACK);
        else if (VCU_Brake_Warn == 1)
            LCD_DrawImage1BPP(82 + 180 + 42, 100 + 38 * 2, BMP_Guzhang, RED, BLACK);
        
        if (VCU_Car_Status == 1)
            LCD_DrawImage1BPP(82 + 180 + 42, 100 + 38 * 3, BMP_Qidong, GREEN, BLACK);
        else if (VCU_Car_Status == 2)
            LCD_DrawImage1BPP(82 + 180 + 42, 100 + 38 * 3, BMP_Guzhang, RED, BLACK);
        
        if (VCU_Run_Status == 1)
            LCD_DrawImage1BPP(82 + 180 + 42, 100 + 38 * 4, BMP_Chundian, GREEN, BLACK);
        else if (VCU_Run_Status == 2)
            LCD_DrawImage1BPP(82 + 180 + 42, 100 + 38 * 4, BMP_Hundong, GREEN, BLACK);
        else if (VCU_Run_Status == 3)
            LCD_DrawImage1BPP(82 + 180 + 42, 100 + 38 * 4, BMP_Ranyou, GREEN, BLACK);
        
        print_SZ_1(82 + 200 + 20 - 16, 100 - 8 + 38 * 5, pSpeed, 3, 0, WHITE);
        
        if (VCU_Brake_Status == 0)
            LCD_DrawImage1BPP(82 + 180 + 42, 100 + 38 * 6, BMP_Wu, GREEN, BLACK);
        else if (VCU_Brake_Status == 1)
            LCD_DrawImage1BPP(82 + 180 + 42, 100 + 38 * 6, BMP_You, GREEN, BLACK);
        
        if (VCU_Power_Status == 0)
            LCD_DrawImage1BPP(82 + 180 + 42, 100 + 38 * 7, BMP_Wu, GREEN, BLACK);
        else if (VCU_Power_Status == 1)
            LCD_DrawImage1BPP(82 + 180 + 42, 100 + 38 * 7, BMP_You, GREEN, BLACK);
        
        if (VCU_Charge == 1 && Status_Old[0] != 1) {
            LCD_DrawImage1BPP(82 + 180 + 42, 100 + 38 * 8, BMP_Tingche, GREEN, BLACK);
            LCD_DrawImage1BPP(82 + 180 + 42 + 42, 100 + 38 * 8, BMP_Chongdian, GREEN, BLACK);           
        } else if (VCU_Charge == 2 && Status_Old[0] != 2) {
            LCD_DrawImage1BPP(82 + 180 + 42, 100 + 38 * 8, BMP_Xingshi, GREEN, BLACK);
            LCD_DrawImage1BPP(82 + 180 + 42 + 42, 100 + 38 * 8, BMP_Chongdian, GREEN, BLACK);
        } else if (VCU_Charge == 3 && Status_Old[0] != 3) {
            LCD_DrawImage1BPP(82 + 180 + 42, 100 + 38 * 8, BMP_Wei, GREEN, BLACK);
            LCD_DrawImage1BPP(82 + 180 + 42 + 21, 100 + 38 * 8, BMP_Chongdian, GREEN, BLACK);
            LCD_DrawRect(82 + 180 + 42 + 21 + 42, 100 + 38 * 8, 21, 20, BLACK);
        } else if (VCU_Charge == 4 && Status_Old[0] != 4) {
            LCD_DrawImage1BPP(82 + 180 + 42, 100 + 38 * 8, BMP_Chongdian, GREEN, BLACK);
            LCD_DrawImage1BPP(82 + 180 + 42 + 42, 100 + 38 * 8, BMP_Wancheng, GREEN, BLACK);
        }
        Status_Old[0] = VCU_Charge;
        
        print_SZ_1(82 + 200 + 20 + 32, 100 - 8 + 38 * 9, VCU_Warn_Level, 1, 0, WHITE);
        
                                     
        print_SZ_1(82 + 200 + 300 + 16 * 2, 100 - 8 + 38 * 0, VCU_Accelerator_percent, 3, 0, WHITE); //����̤�忪��
        print_SZ_1(82 + 200 + 300 + 16 * 2, 100 - 8 + 38 * 1, VCU_Brake_percent, 3, 0, WHITE); //�ƶ�̤�忪��
        print_SZ_1(82 + 200 + 300 + 16 * 2, 100 - 8 + 38 * 2, VCU_Fault_Number, 3, 0, WHITE); //��������
        print_SZ_1(82 + 200 + 300 + 16 * 2, 100 - 8 + 38 * 3, VCU_Motor_Number, 3, 0, WHITE); //�������
    }else if (index == 2) {
        print_SZ_1(82 + 200 + 20, 100 - 8, MCU_Number, 1, 0, WHITE);

        if (MCU_Status == 1)
            LCD_DrawImage1BPP(82 + 180 + 42, 100 + 38 * 1, BMP_Haodian, GREEN, BLACK);
        else if (MCU_Status == 2)
            LCD_DrawImage1BPP(82 + 180 + 42, 100 + 38 * 1, BMP_Fadian, GREEN, BLACK);
        else if (MCU_Status == 3)
            LCD_DrawImage1BPP(82 + 180 + 42, 100 + 38 * 1, BMP_Tingzhi, RED, BLACK);
        else if (MCU_Status == 4)
            LCD_DrawImage1BPP(82 + 180 + 42, 100 + 38 * 1, BMP_Zhunbei, GREEN, BLACK);
        
        updata_DAT(82 + 200 + 16 * 2, 100 - 8 + 38 * 2, MCU_Temp, 1, 40, WHITE, 3, 0);
        updata_DAT(82 + 200 + 16 * 2, 100 - 8 + 38 * 3, MCU_Controller_Temp, 1, 40, WHITE, 3, 0);
        print_SZ_1(82 + 200 + 16 * 2, 100 - 8 + 38 * 4, MCU_Voltage * 0.1, 4, 0, WHITE);
        updata_DAT(82 + 200 + 16 * 2, 100 - 8 + 38 * 5, MCU_Curretn, 0.1, 1000, WHITE, 4, 0);
      
        
        updata_DAT(82 + 200 + 320, 100 - 8 + 38 * 0, MCU_Rpm, 1, 20000, WHITE, 4, 0);
        updata_DAT(82 + 200 + 320, 100 - 8 + 38 * 1, MCU_Torque, 0.1, 2000, WHITE, 4, 0); 
        
        if (MCU_Controller_Warn_Temp == 0)
            LCD_DrawImage1BPP(82 + 180 + 320 + 63, 100 + 38 * 2, BMP_Zhengchang, GREEN, BLACK);
        else if (MCU_Controller_Warn_Temp == 1)
            LCD_DrawImage1BPP(82 + 180 + 320 + 63, 100 + 38 * 2, BMP_Baojing, RED, BLACK);

        if (MCU_Warn_Temp == 0)
            LCD_DrawImage1BPP(82 + 180 + 320 + 63, 100 + 38 * 3, BMP_Zhengchang, GREEN, BLACK);
        else if (MCU_Warn_Temp == 1)
            LCD_DrawImage1BPP(82 + 180 + 320 + 63, 100 + 38 * 3, BMP_Baojing, RED, BLACK);

        print_SZ_1(82 + 200 + 320, 100 - 8 + 38 * 4, MCU_Warn_Number, 3, 0, WHITE);
        
        DM(1, CAN_18FECAD0, 0);
        print_SZ_1(82 + 230 + 220, 100 - 8 + 38 * 6, *(SPN + 0), 6, 0, GREEN);
        print_SZ_1(82 + 230 + 220 + 130, 100 - 8 + 38 * 6, *(FMI + 0), 3, 0, GREEN);

    } 
}

void frmVCU(void) {
    static unsigned char index_VCU = 1;
    if (f_index == 0) { //ֻ����һ��
        f_index = 1;
        VCUFrame(index_VCU);
    } else if (f_index == 1) {
        f_index = 1;
        VCUUpdate(index_VCU);
    } else {
        f_index = 0;
    }
    if (key_AV) {
        key_AV = 0;
        index_VCU--;
        f_index = 0;
        if (index_VCU == 0) {
            index_VCU = 1;
            frmID = 1;
        }
    }
    if (key_up) { //�Ӳ˵��л�
        key_up = 0;
        index_VCU++;
        f_index = 0;
        if (index_VCU == 3) {
            index_VCU = 1;
            frmID = 1;
        }
    }
    if (key_set) {//����������
        key_set = 0;
        frmID = 0;
        f_index = 0;
        Index = 0;
        index_VCU = 1;
    }
    if (key_long_set) {
        key_long_set = 0;
    }

}

/******************************************************/
//������Ͻ���
/*******************************************************/
//ֻ����һ�ε�����
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

    LCD_DrawImage1BPP(82, 100, BMP_DJ, WHITE, BLACK); //���
    LCD_DrawImage1BPP(82 + 42, 100, BMP_Zhuansu, WHITE, BLACK); //ת��
    LCD_DrawImage1BPP(400 - 24 - 24, 100, BMP_RPM, WHITE, BLACK); //RPM

    LCD_DrawImage1BPP(82, 100 + 38, BMP_DJ, WHITE, BLACK); //���
    LCD_DrawImage1BPP(82 + 42, 100 + 38, BMP_Muxian, WHITE, BLACK); //ĸ��
    LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38, BMP_DY, WHITE, BLACK); //��ѹ
    LCD_DrawImage1BPP(400 - 24, 100 + 38, BMP_v, WHITE, BLACK); //v

    LCD_DrawImage1BPP(82, 100 + 38 * 2, BMP_DJ, WHITE, BLACK); //���
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 2, BMP_Gonglv, WHITE, BLACK); //����
    LCD_DrawImage1BPP(400 - 35, 100 + 38 * 2, BMP_k, WHITE, BLACK); //k
    LCD_DrawImage1BPP(400 - 24, 100 + 38 * 2, BMP_w, WHITE, BLACK); //a

    LCD_DrawImage1BPP(82, 100 + 38 * 3, BMP_DJ, WHITE, BLACK); //���
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 3, BMP_Wendu, WHITE, BLACK); //�¶�
    LCD_DrawImage1BPP(400 - 28, 100 + 38 * 3, BMP_T, WHITE, BLACK); //��



    LCD_DrawImage1BPP(82 + 320, 100, BMP_KZQ, WHITE, BLACK); //������
    LCD_DrawImage1BPP(82 + 320 + 63, 100, BMP_Wendu, WHITE, BLACK); //�¶�
    LCD_DrawImage1BPP(720 - 28, 100, BMP_T, WHITE, BLACK); //��

    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 1, BMP_Qibeng, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 1, BMP_Zhuangtai, WHITE, BLACK); //״̬

    LCD_DrawImage1BPP(82 + 320, 100 + 2 + 38 * 2, BMP_Guzhang, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 320 + 42, 100 + 2 + 38 * 2, BMP_Code, WHITE, BLACK); //����



    /*
    //LCD_DrawImage1BPP(82, 100 + 38 * 3, BMP_Niaosu, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 3, BMP_Yewei, WHITE, BLACK); //Һλ
    LCD_DrawImage1BPP(400 - 24, 100 + 38 * 3, BMP_Baifenhao, WHITE, BLACK); //%


    //LCD_DrawImage1BPP(82 + 320, 100, BMP_Fadongji, WHITE, BLACK); //������
    LCD_DrawImage1BPP(82 + 63 + 320, 100, BMP_Mubiao, WHITE, BLACK); //Ŀ��
    LCD_DrawImage1BPP(82 + 63 + 42 + 320, 100, BMP_Youmen, WHITE, BLACK); //����
    LCD_DrawImage1BPP(720 - 24, 100, BMP_Baifenhao, WHITE, BLACK); //%

    //LCD_DrawImage1BPP(82 + 320, 100 + 38, BMP_Fadongji, WHITE, BLACK); //������
    LCD_DrawImage1BPP(82 + 63 + 320, 100 + 38, BMP_Shiji, WHITE, BLACK); //ʵ��
    LCD_DrawImage1BPP(82 + 63 + 42 + 320, 100 + 38, BMP_Youmen, WHITE, BLACK); //����
    LCD_DrawImage1BPP(720 - 24, 100 + 38, BMP_Baifenhao, WHITE, BLACK); //%   

    //LCD_DrawImage1BPP(82 + 320, 100 + 38 * 2, BMP_Fadongji, WHITE, BLACK); //������
    //LCD_DrawImage1BPP(82 + 63 + 320, 100 + 38 * 2, BMP_Jiyou, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 63 + 42 + 320, 100 + 38 * 2, BMP_Yali, WHITE, BLACK); //ѹ��
    LCD_DrawImage1BPP(720 - 32, 100 + 38 * 2, BMP_Kpa, WHITE, BLACK); //Kpa

    //LCD_DrawImage1BPP(82 + 320, 100 + 38 * 3, BMP_Fadongji, WHITE, BLACK); //������
    //LCD_DrawImage1BPP(82 + 63 + 320, 100 + 38 * 3, BMP_Jinqi, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 63 + 42 + 320, 100 + 38 * 3, BMP_Wendu, WHITE, BLACK); //�¶�
    LCD_DrawImage1BPP(720 - 28, 100 + 38 * 3, BMP_T, WHITE, BLACK); //��
     */
}
//һֱ���µ�����
void DMQUpdate(void) {
    print_SZ_1(82 + 200 + 20 - 16, 100 - 8, ACU_Rpm, 4, 0, WHITE);
    print_SZ_1(82 + 200 + 20, 100 - 8 + 38, ACU_Voltage, 3, 0, WHITE);
    print_SZ_1(82 + 200 + 20, 100 - 8 + 38 * 2, ACU_Power, 3, 0, WHITE);
    updata_DAT(82 + 200 + 20, 100 - 8 + 38 * 3, ACU_Temp, 1, 40, WHITE, 3, 0);

    updata_DAT(82 + 200 + 300, 100 - 8, ACU_Controller_temp, 1, 40, WHITE, 3, 0);
    if (ACU_Status == 0)
        LCD_DrawImage1BPP(82 + 200 + 300, 100 + 38 * 1, BMP_Tingzhi, GREEN, BLACK);
    else if (ACU_Status == 1)
        LCD_DrawImage1BPP(82 + 200 + 300, 100 + 38 * 1, BMP_Yunxing, GREEN, BLACK);   
    print_SZ_1(82 + 200 + 300 + 16 * 2, 100 - 8 + 38 * 2, ACU_Fault_Code, 1, 0, WHITE); //������Ԥ��״̬   
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
//DCDC��Ͻ���
/*******************************************************/
//ֻ����һ�ε�����

void DCDCFrame(void) {
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

    LCD_DrawImage1BPP(82, 100 - 2, BMP_DCDC, WHITE, BLACK); //DCDC
    LCD_DrawImage1BPP(82 + 65, 100 + 2, BMP_Muxian, WHITE, BLACK); //ĸ��
    LCD_DrawImage1BPP(82 + 65 + 42, 100 + 2, BMP_DY, WHITE, BLACK); //��ѹ
    LCD_DrawImage1BPP(400 - 24, 100 - 2, BMP_v, WHITE, BLACK); //V
    
    LCD_DrawImage1BPP(82, 100 - 2 + 38, BMP_DCDC, WHITE, BLACK); //DCDC
    LCD_DrawImage1BPP(82 + 65, 100 + 2 + 38, BMP_Output, WHITE, BLACK); //���
    LCD_DrawImage1BPP(82 + 65 + 42, 100 + 2 + 38, BMP_DY, WHITE, BLACK); //��ѹ
    LCD_DrawImage1BPP(400 - 24, 100 - 2 + 38, BMP_v, WHITE, BLACK); //V

    LCD_DrawImage1BPP(82, 100 - 2 + 38 * 2, BMP_DCDC, WHITE, BLACK); //DCDC
    LCD_DrawImage1BPP(82 + 65, 100 + 2 + 38 * 2, BMP_Output, WHITE, BLACK); //���
    LCD_DrawImage1BPP(82 + 65 + 42, 100 + 2 + 38 * 2, BMP_DL, WHITE, BLACK); //����
    LCD_DrawImage1BPP(400 - 24, 100 - 2 + 38 * 2, BMP_a, WHITE, BLACK); //A

    LCD_DrawImage1BPP(82, 100 - 2 + 38 * 3, BMP_DCDC, WHITE, BLACK); //DCDC
    LCD_DrawImage1BPP(82 + 65, 100 + 2 + 38 * 3, BMP_Gongzuo, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 65 + 42, 100 + 2 + 38 * 3, BMP_Wendu, WHITE, BLACK); //�¶�
    LCD_DrawImage1BPP(400 - 28, 100 - 2 + 38 * 3, BMP_T, WHITE, BLACK); //��

    
    
    
    
    LCD_DrawImage1BPP(82 + 320, 100 - 2, BMP_DCDC, WHITE, BLACK); //DCDC
    LCD_DrawImage1BPP(82 + 320 + 65, 100 + 2, BMP_Gongzuo, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 320 + 65 + 42, 100 + 2, BMP_Zhuangtai, WHITE, BLACK); //״̬

    LCD_DrawImage1BPP(82 + 320, 100 - 2 + 38, BMP_DCDC, WHITE, BLACK); //DCDC
    LCD_DrawImage1BPP(82 + 320 + 65, 100 + 2 + 38, BMP_Tongxun, WHITE, BLACK); //ͨѶ
    LCD_DrawImage1BPP(82 + 320 + 65 + 42, 100 + 2 + 38, BMP_Baojing, WHITE, BLACK); //����
    
    LCD_DrawImage1BPP(82 + 320, 100 - 2 + 38 * 2, BMP_DCDC, WHITE, BLACK); //DCDC
    LCD_DrawImage1BPP(82 + 320 + 65, 100 + 2 + 38 * 2, BMP_Wendu, WHITE, BLACK); //�¶�
    LCD_DrawImage1BPP(82 + 320 + 65 + 42, 100 + 2 + 38 * 2, BMP_Baojing, WHITE, BLACK); //����

    LCD_DrawImage1BPP(82 + 320, 100 - 2 + 38 * 3, BMP_DCDC, WHITE, BLACK); //DCDC
    LCD_DrawImage1BPP(82 + 320 + 65, 100 + 2 + 38 * 3, BMP_Zhuangtai, WHITE, BLACK); //״̬
    LCD_DrawImage1BPP(82 + 320 + 65 + 42, 100 + 2 + 38 * 3, BMP_Baojing, WHITE, BLACK); //����

    LCD_DrawImage1BPP(82 + 320, 100 - 2 + 38 * 4, BMP_DCDC, WHITE, BLACK); //DCDC
    LCD_DrawImage1BPP(82 + 320 + 65, 100 + 2 + 38 * 4, BMP_Guzhang, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 320 + 65 + 42, 100 + 2 + 38 * 4, BMP_Code, WHITE, BLACK); //����

}
//һֱ���µ�����
void DCDCUpdate(void) {
    print_SZ_1(82 + 200 + 16, 100 - 8, DCDC_Voltage, 3, 0, WHITE);
    print_SZ_1(82 + 200 + 32, 100 - 8 + 38, DCDC_Output_Voltage, 2, 0, WHITE);
    print_SZ_1(82 + 200, 100 - 8 + 38 * 2, DCDC_Current, 4, 0, WHITE);
    updata_DAT(82 + 200 + 16, 100 - 8 + 38 * 3, DCDC_Temp, 1, 40, WHITE, 3, 0);
    
    if (DCDC_Status == 0)
        LCD_DrawImage1BPP(82 + 200 + 300, 100 + 38 * 0, BMP_Tingzhi, RED, BLACK);
    else if (DCDC_Status == 1)
        LCD_DrawImage1BPP(82 + 200 + 300, 100 + 38 * 0, BMP_Yunxing, GREEN, BLACK); 
    
    if (DCDC_CAN_Warn == 0)
        LCD_DrawImage1BPP(82 + 200 + 300, 100 + 38 * 1, BMP_Zhengchang, GREEN, BLACK);
    else if (DCDC_CAN_Warn == 1)
        LCD_DrawImage1BPP(82 + 200 + 300, 100 + 38 * 1, BMP_Baojing, RED, BLACK); 
    
    if (DCDC_Temp_Warn == 0)
        LCD_DrawImage1BPP(82 + 200 + 300, 100 + 38 * 2, BMP_Zhengchang, GREEN, BLACK);
    else if (DCDC_Temp_Warn == 1)
        LCD_DrawImage1BPP(82 + 200 + 300, 100 + 38 * 2, BMP_Baojing, RED, BLACK); 
    
    if (DCDC_Status_Warn == 0)
        LCD_DrawImage1BPP(82 + 200 + 300, 100 + 38 * 3, BMP_Zhengchang, GREEN, BLACK);
    else if (DCDC_Status_Warn == 1)
        LCD_DrawImage1BPP(82 + 200 + 300, 100 + 38 * 3, BMP_Baojing, RED, BLACK);
    
    print_SZ_1(82 + 270 + 250, 100 - 8 + 38 * 4, DCDC_Fault_Code, 1, 0, WHITE); //������
    
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
//�ͱ���Ͻ���
/*******************************************************/
//ֻ����һ�ε�����

void DMYFrame(void) {
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

    LCD_DrawImage1BPP(82, 100, BMP_DJ, WHITE, BLACK); //���
    LCD_DrawImage1BPP(82 + 42, 100, BMP_Zhuansu, WHITE, BLACK); //ת��
    LCD_DrawImage1BPP(400 - 24 - 24, 100, BMP_RPM, WHITE, BLACK); //RPM

    LCD_DrawImage1BPP(82, 100 + 38, BMP_DJ, WHITE, BLACK); //���
    LCD_DrawImage1BPP(82 + 42, 100 + 38, BMP_Muxian, WHITE, BLACK); //ĸ��
    LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38, BMP_DY, WHITE, BLACK); //��ѹ
    LCD_DrawImage1BPP(400 - 24, 100 + 38, BMP_v, WHITE, BLACK); //v

    LCD_DrawImage1BPP(82, 100 + 38 * 2, BMP_DJ, WHITE, BLACK); //���
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 2, BMP_Gonglv, WHITE, BLACK); //����
    LCD_DrawImage1BPP(400 - 35, 100 + 38 * 2, BMP_k, WHITE, BLACK); //k
    LCD_DrawImage1BPP(400 - 24, 100 + 38 * 2, BMP_w, WHITE, BLACK); //a

    LCD_DrawImage1BPP(82, 100 + 38 * 3, BMP_DJ, WHITE, BLACK); //���
    LCD_DrawImage1BPP(82 + 42, 100 + 38 * 3, BMP_Wendu, WHITE, BLACK); //�¶�
    LCD_DrawImage1BPP(400 - 28, 100 + 38 * 3, BMP_T, WHITE, BLACK); //��



    LCD_DrawImage1BPP(82 + 320, 100, BMP_KZQ, WHITE, BLACK); //������
    LCD_DrawImage1BPP(82 + 320 + 63, 100, BMP_Wendu, WHITE, BLACK); //�¶�
    LCD_DrawImage1BPP(720 - 28, 100, BMP_T, WHITE, BLACK); //��

    LCD_DrawImage1BPP(82 + 320, 100 + 38 * 1, BMP_Youbeng, WHITE, BLACK); //�ͱ�
    LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 1, BMP_Zhuangtai, WHITE, BLACK); //״̬

    LCD_DrawImage1BPP(82 + 320, 100 + 2 + 38 * 2, BMP_Guzhang, WHITE, BLACK); //����
    LCD_DrawImage1BPP(82 + 320 + 42, 100 + 2 + 38 * 2, BMP_Code, WHITE, BLACK); //����
}
//һֱ���µ�����
void DMYUpdate(void) {
    print_SZ_1(82 + 200 + 20 - 16, 100 - 8, OCU_Rpm, 4, 0, WHITE);
    print_SZ_1(82 + 200 + 20, 100 - 8 + 38, OCU_Voltage, 3, 0, WHITE);
    print_SZ_1(82 + 200 + 20, 100 - 8 + 38 * 2, OCU_Power, 3, 0, WHITE);
    updata_DAT(82 + 200 + 20, 100 - 8 + 38 * 3, OCU_Temp, 1, 40, WHITE, 3, 0);

    updata_DAT(82 + 200 + 300, 100 - 8, OCU_Controller_temp, 1, 40, WHITE, 3, 0);
    if (OCU_Status == 0)
        LCD_DrawImage1BPP(82 + 200 + 300, 100 + 38 * 1, BMP_Tingzhi, GREEN, BLACK);
    else if (OCU_Status == 1)
        LCD_DrawImage1BPP(82 + 200 + 300, 100 + 38 * 1, BMP_Yunxing, GREEN, BLACK);   
    print_SZ_1(82 + 200 + 300 + 16 * 2, 100 - 8 + 38 * 2, OCU_Fault_Code, 1, 0, WHITE); //������Ԥ��״̬ 
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
//BMS��Ͻ���
/*******************************************************/
//ֻ����һ�ε�����

void BMSFrame(unsigned char index) {
    unsigned char i = 0;
    LCD_Clear();
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //��������
    LCD_DrawImage1BPP(130 + 200 - 24, 130 - 85, BMP_Battery, WHITE, BLACK); //���
    LCD_DrawImage1BPP(130 + 200 + 50 - 24, 130 - 85, BMP_Manage, WHITE, BLACK); //����
    LCD_DrawImage1BPP(130 + 200 + 50 + 50 - 24, 130 - 85, BMP_STSTEM, WHITE, BLACK); //ϵͳ
    LCD_DrawImage1BPP(130 + 200 + 50 + 50 + 50 - 24, 130 - 85, BMP_Message, WHITE, BLACK); //��Ϣ

    if (index == 1) {
        print_SZ(750, 50, 1, 1, 0, WHITE); // 1/4
        LCD_DrawImage1BPP(750 + 8, 50 - 3, BMP_I, WHITE, BLACK);
        print_SZ(750 + 8 + 14, 50, 4, 1, 0, WHITE);
        LCD_DrawRect(80, 90, 1, 380, GREEN);
        LCD_DrawRect(80 + 320, 90, 1, 380, GREEN);
        LCD_DrawRect(80 + 320 + 320 + 70, 90, 1, 380, GREEN);
        for (i = 0; i < 11; i++)
            LCD_DrawRect(80, 90 + i * 38, 710, 1, GREEN);

        LCD_DrawImage1BPP(82, 100, BMP_DC, WHITE, BLACK); //���
        LCD_DrawImage1BPP(82 + 42, 100, BMP_Zong, WHITE, BLACK); //��
        LCD_DrawImage1BPP(82 + 42 + 21, 100, BMP_DY, WHITE, BLACK); //��ѹ
        LCD_DrawImage1BPP(400 - 24, 100, BMP_v, WHITE, BLACK); //V

        LCD_DrawImage1BPP(82, 100 + 38, BMP_DC, WHITE, BLACK); //���
        LCD_DrawImage1BPP(82 + 42, 100 + 38, BMP_Zong, WHITE, BLACK); //��
        LCD_DrawImage1BPP(82 + 42 + 21, 100 + 38, BMP_DL, WHITE, BLACK); //����
        LCD_DrawImage1BPP(400 - 24, 100 + 38, BMP_a, WHITE, BLACK); //A
        
        LCD_DrawImage1BPP(82, 100 + 38 * 2, BMP_DC, WHITE, BLACK); //��س�繦������
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 2, BMP_Chongdian, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 2, BMP_Gonglv, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 42 + 42 + 42, 100 + 38 * 2, BMP_Xianzhi, WHITE, BLACK); //
        LCD_DrawImage1BPP(400 - 24 - 11, 100 + 38 * 2, BMP_k, WHITE, BLACK); //K
        LCD_DrawImage1BPP(400 - 24, 100 + 38 * 2, BMP_w, WHITE, BLACK); //W
        
        LCD_DrawImage1BPP(82, 100 + 38 * 3, BMP_DC, WHITE, BLACK); //��طŵ繦������
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 3, BMP_Fangdian, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 3, BMP_Gonglv, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 42 + 42 + 42, 100 + 38 * 3, BMP_Xianzhi, WHITE, BLACK); //
        LCD_DrawImage1BPP(400 - 24 - 11, 100 + 38 * 3, BMP_k, WHITE, BLACK); //K
        LCD_DrawImage1BPP(400 - 24, 100 + 38 * 3, BMP_w, WHITE, BLACK); //W
        
        LCD_DrawImage1BPP(82, 100 + 38 * 4, BMP_DC, WHITE, BLACK); //���
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 4, BMP_System, WHITE, BLACK);//ϵͳ
        LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 4, BMP_Life, WHITE, BLACK); //Life
        
        LCD_DrawImage1BPP(82 , 100 + 38 * 5, BMP_DC, WHITE, BLACK); //���
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 5, BMP_Guzhang, WHITE, BLACK);//����
        LCD_DrawImage1BPP(82+ 42 + 42, 100 + 38 * 5, BMP_Code, WHITE, BLACK); //����
        
        LCD_DrawImage1BPP(82, 100 + 38 * 6, BMP_DC, WHITE, BLACK); //���
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 6, BMP_Guzhang, WHITE, BLACK);//����
        LCD_DrawImage1BPP(82  + 42 + 42, 100 + 38 * 6, BMP_Dengji, WHITE, BLACK); //�ȼ�
        
        LCD_DrawImage1BPP(82 , 100 + 38 * 7, BMP_Chong, WHITE, BLACK); //��ŵ�״̬
        LCD_DrawImage1BPP(82  + 21, 100 + 38 * 7, BMP_Fangdian, WHITE, BLACK); //
        LCD_DrawImage1BPP(82  + 21 + 21, 100 + 38 * 7, BMP_DC, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 21 + 21 + 21, 100 + 38 * 7, BMP_Zhuangtai, WHITE, BLACK); //
        
        LCD_DrawImage1BPP(82, 100 + 38 * 8, BMP_Zijian, WHITE, BLACK); //�Լ�״̬
        LCD_DrawImage1BPP(82  + 42, 100 + 38 * 8, BMP_Zhuangtai, WHITE, BLACK); //
                          
        
        /*for (i = 0; i < 3; i++) {
            LCD_DrawImage1BPP(82, 100 + 38 * (i + 2), BMP_DC, WHITE, BLACK); //���
            LCD_DrawImage1BPP(82 + 42, 100 + 38 * (i + 2), BMP_Zhuangtai, WHITE, BLACK); //״̬
            LCD_DrawImage1BPP(82 + 42 + 42, 100 - 8 + 38 * (i + 2), BMP_SZ_1[i + 1], WHITE, BLACK); //1
        }

        LCD_DrawImage1BPP(82, 100 + 38 * 3, BMP_DC, WHITE, BLACK); //���
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 3, BMP_Zhuangtai, WHITE, BLACK); //״̬
        LCD_DrawImage1BPP(82 + 42 + 42, 100 - 8 + 38 * 3, BMP_SZ_1[2], WHITE, BLACK); //2

        LCD_DrawImage1BPP(82, 100 + 38 * 4, BMP_DC, WHITE, BLACK); //���
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 4, BMP_Zhuangtai, WHITE, BLACK); //״̬
        LCD_DrawImage1BPP(82 + 42 + 42, 100 - 8 + 38 * 4, BMP_SZ_1[3], WHITE, BLACK); 

        LCD_DrawImage1BPP(82, 100 + 38 * 5, BMP_DC, WHITE, BLACK); //���
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 5, BMP_Xiang, WHITE, BLACK); //��
        LCD_DrawImage1BPP(82 + 42 + 21, 100 + 38 * 5, BMP_Geshu, WHITE, BLACK); //����

        LCD_DrawImage1BPP(82, 100 + 38 * 6, BMP_BMU, WHITE, BLACK); //BMU
        LCD_DrawImage1BPP(82 + 35, 100 + 38 * 6, BMP_Danyuan, WHITE, BLACK); //��Ԫ
        LCD_DrawImage1BPP(82 + 35 + 42, 100 + 38 * 6, BMP_Geshu, WHITE, BLACK); //����

        LCD_DrawImage1BPP(82, 100 + 38 * 7, BMP_Jidianqi, WHITE, BLACK); //�̵���
        LCD_DrawImage1BPP(82 + 63, 100 + 38 * 7, BMP_Zhuangtai, WHITE, BLACK); //״̬

        LCD_DrawImage1BPP(82, 100 + 38 * 8, BMP_Chong, WHITE, BLACK); //��ŵ�״̬
        LCD_DrawImage1BPP(82 + 21, 100 + 38 * 8, BMP_Fangdian, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 21 + 21, 100 + 38 * 8, BMP_DC, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 21 + 21 + 21, 100 + 38 * 8, BMP_Zhuangtai, WHITE, BLACK); */

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
            LCD_DrawImage1BPP(82 + 320 + 42 * 7 - 5, 100 + 38 * i, BMP_Xiang, WHITE, BLACK); //��

            LCD_DrawImage1BPP(82 + 320 + 42 * 8.5 + 5, 100 + 38 * i, BMP_Hao, WHITE, BLACK); //��
        }              

        LCD_DrawImage1BPP(82 + 320, 100 + 38 * 4, BMP_DC, WHITE, BLACK); //���
        LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 4, BMP_Jueyuan, WHITE, BLACK); //��Ե
        LCD_DrawImage1BPP(82 + 320 + 42 + 42, 100 + 38 * 4, BMP_System, WHITE, BLACK); //ϵͳ
        LCD_DrawImage1BPP(82 + 320 + 42 + 42 + 42, 100 + 38 * 4, BMP_Xinxi, WHITE, BLACK); //��Ϣ
        
        LCD_DrawImage1BPP(82 + 320, 100 + 38 * 5, BMP_Jueyuan, WHITE, BLACK); //��Ե
        LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 5, BMP_Baojing, WHITE, BLACK); //����
        
        LCD_DrawImage1BPP(82 + 320, 100 + 38 * 6, BMP_Jueyuan, WHITE, BLACK); //��Ե
        LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 6, BMP_DC, WHITE, BLACK); //���
        LCD_DrawImage1BPP(82 + 320 + 42 + 21, 100 + 38 * 6, BMP_Zu, WHITE, BLACK); //��
        LCD_DrawImage1BPP(720 - 28 + 60, 100 + 38 * 6, BMP_k, WHITE, BLACK); //K
        LCD_DrawImage1BPP(720 - 16 + 60, 100 + 2 + 38 * 6, BMP_Omu, WHITE, BLACK); //��


        LCD_DrawImage1BPP(82 + 320, 100 + 38 * 7, BMP_Jueyuan, WHITE, BLACK); //��Ե
        LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 7, BMP_System, WHITE, BLACK); //ϵͳ
        LCD_DrawImage1BPP(82 + 320 + 42 + 42, 100 + 38 * 7, BMP_Life, WHITE, BLACK); //Life



        /*for (i = 0; i < 2; i++) {
            if (i == 0)
                LCD_DrawImage1BPP(82 + 320, 100 + 38 * (i + 7), BMP_Zheng, WHITE, BLACK); //��
            else LCD_DrawImage1BPP(82 + 320, 100 + 38 * (i + 7), BMP_Fu, WHITE, BLACK); //��
            LCD_DrawImage1BPP(82 + 320 + 21, 100 + 38 * (i + 7), BMP_Jueyuan, WHITE, BLACK); //��Ե
            LCD_DrawImage1BPP(82 + 320 + 42 + 21, 100 + 38 * (i + 7), BMP_DC, WHITE, BLACK); //���
            LCD_DrawImage1BPP(82 + 320 + 42 + 42, 100 + 38 * (i + 7), BMP_Zu, WHITE, BLACK); //��
            //LCD_DrawImage1BPP(82 + 320 + 42 + 42 + 21 + 2, 100 + 5 + 38 * (i + 7), BMP_Maohao, WHITE, BLACK); //:
            LCD_DrawImage1BPP(720 - 28 + 60, 100 + 38 * (i + 7), BMP_k, WHITE, BLACK); //K
            LCD_DrawImage1BPP(720 - 16 + 60, 100 + 2 + 38 * (i + 7), BMP_Omu, WHITE, BLACK); //��
        }*/
    }
    if (index == 2) {
        print_SZ(750, 50, 2, 1, 0, WHITE); // 2/4
        LCD_DrawImage1BPP(750 + 8, 50 - 3, BMP_I, WHITE, BLACK);
        print_SZ(750 + 8 + 14, 50, 4, 1, 0, WHITE);

        LCD_DrawRect(80, 90, 1, 380, GREEN);
        LCD_DrawRect(80 + 320, 90, 1, 380, GREEN);
        LCD_DrawRect(80 + 320 + 320, 90, 1, 380, GREEN);
        for (i = 0; i < 11; i++)
            LCD_DrawRect(80, 90 + i * 38, 640, 1, GREEN);
        
        LCD_DrawImage1BPP(82, 100 + 38 * 0, BMP_Wendu, WHITE, BLACK); //�¶Ȳ��챨��
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 0, BMP_Chayi, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 42 + 42, 100 + 38 * 0, BMP_Baojing, WHITE, BLACK); // 
        
        LCD_DrawImage1BPP(82, 100 + 38 * 1, BMP_Wendu, WHITE, BLACK); //�¶ȹ��߱���
        LCD_DrawImage1BPP(82+ 42, 100 + 38 * 1, BMP_Guo, WHITE, BLACK); //
        LCD_DrawImage1BPP(82  + 42 + 21, 100 + 38 * 1, BMP_Gao, WHITE, BLACK); //
        LCD_DrawImage1BPP(82  + 42 + 42, 100 + 38 * 1, BMP_Baojing, WHITE, BLACK); // 
        
        LCD_DrawImage1BPP(82 , 100 + 38 * 2, BMP_Chezai ,WHITE, BLACK); //���ش���װ�ù�ѹ
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 2, BMP_Chuneng, WHITE, BLACK); //
        LCD_DrawImage1BPP(82  + 42 + 42, 100 + 38 * 2, BMP_Zhuangzhi, WHITE, BLACK); //
        LCD_DrawImage1BPP(82+ 42 + 42 + 42, 100 + 38 * 2, BMP_DY, WHITE, BLACK);
        LCD_DrawImage1BPP(82+ 42 + 42 + 42, 100 + 38 * 2, BMP_Guo ,WHITE, BLACK); //
        LCD_DrawImage1BPP(82  + 42 + 42 + 42 + 42, 100 + 38 * 2, BMP_Baojing, WHITE, BLACK); // 
        
        LCD_DrawImage1BPP(82 , 100 + 38 * 3, BMP_Chezai ,WHITE, BLACK); //���ش���װ��Ƿѹ
        LCD_DrawImage1BPP(82  + 42, 100 + 38 * 3, BMP_Chuneng, WHITE, BLACK); //
        LCD_DrawImage1BPP(82  + 42 + 42, 100 + 38 * 3, BMP_Zhuangzhi, WHITE, BLACK); //
        LCD_DrawImage1BPP(82  + 42 + 42 + 42, 100 + 38 * 3, BMP_DY, WHITE, BLACK);
        LCD_DrawImage1BPP(82  + 42 + 42 + 42, 100 + 38 * 3, BMP_Qian ,WHITE, BLACK); //
        LCD_DrawImage1BPP(82  + 42 + 42 + 42 + 42, 100 + 38 * 3, BMP_Baojing, WHITE, BLACK); // 
        
        LCD_DrawImage1BPP(82 , 100 + 38 * 4, BMP_s ,WHITE, BLACK); //SOC�ͱ���
        LCD_DrawImage1BPP(82  + 11, 100 + 38 * 4, BMP_o, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 11 + 11, 100 + 38 * 4, BMP_c, WHITE, BLACK); //
        LCD_DrawImage1BPP(82+ 11 + 11 + 11, 100 + 38 * 4, BMP_Di, WHITE, BLACK);
        LCD_DrawImage1BPP(82  + 11 + 11 + 11 + 21, 100 + 38 * 4, BMP_Baojing ,WHITE, BLACK); //
        
        LCD_DrawImage1BPP(82 , 100 + 38 * 5, BMP_Dan ,WHITE, BLACK); //�����ع�ѹ����
        LCD_DrawImage1BPP(82 + 21, 100 + 38 * 5, BMP_Ti, WHITE, BLACK); //
        LCD_DrawImage1BPP(82  + 21 + 21, 100 + 38 * 5, BMP_DC, WHITE, BLACK); //
        LCD_DrawImage1BPP(82  + 21 + 21 + 42, 100 + 38 * 5, BMP_DY, WHITE, BLACK);
        LCD_DrawImage1BPP(82  + 21 + 21 + 42, 100 + 38 * 5, BMP_Guo ,WHITE, BLACK); //
        LCD_DrawImage1BPP(82  + 21 + 21 + 42 + 42, 100 + 38 * 5, BMP_Baojing, WHITE, BLACK); // 
        
        LCD_DrawImage1BPP(82 , 100 + 38 * 6, BMP_Dan ,WHITE, BLACK); //������Ƿѹ����
        LCD_DrawImage1BPP(82  + 21, 100 + 38 * 6, BMP_Ti, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 21 + 21, 100 + 38 * 6, BMP_DC, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 21 + 21 + 42, 100 + 38 * 6, BMP_DY, WHITE, BLACK);
        LCD_DrawImage1BPP(82  + 21 + 21 + 42, 100 + 38 * 6, BMP_Qian ,WHITE, BLACK); //
        LCD_DrawImage1BPP(82  + 21 + 21 + 42 + 42, 100 + 38 * 6, BMP_Baojing, WHITE, BLACK); // 
         // 
        LCD_DrawImage1BPP(82 , 100 + 38 * 7, BMP_s ,WHITE, BLACK); //SOC�߱���
        LCD_DrawImage1BPP(82  + 11, 100 + 38 * 7, BMP_o, WHITE, BLACK); //
        LCD_DrawImage1BPP(82  + 11 + 11, 100 + 38 * 7, BMP_c, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 11 + 11 + 11, 100 + 38 * 7, BMP_Gao, WHITE, BLACK);
        LCD_DrawImage1BPP(82  + 11 + 11 + 11 + 21, 100 + 38 * 7, BMP_Baojing ,WHITE, BLACK); //
        
        LCD_DrawImage1BPP(82 + 320, 100 + 38 * 0, BMP_s ,WHITE, BLACK); //SOC���䱨��
        LCD_DrawImage1BPP(82 + 320 + 11, 100 + 38 * 0, BMP_o, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 320 + 11 + 11, 100 + 38 * 0, BMP_c, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 320 + 11 + 11 + 11, 100 + 38 * 0, BMP_Tiaobian, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 320 + 11 + 11 + 11 + 42, 100 + 38 * 0, BMP_Baojing ,WHITE, BLACK); //
        
        LCD_DrawImage1BPP(82 + 320, 100 + 38 * 1, BMP_Chuneng, WHITE, BLACK); //����ϵͳƥ�䱨��
        LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 1, BMP_System, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 320 + 42 + 42, 100 + 38 * 1, BMP_Pipei, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 320 + 42 + 42 + 42, 100 + 38 * 1, BMP_Baojing, WHITE, BLACK); // 
        
        LCD_DrawImage1BPP(82 + 320, 100 + 38 * 2, BMP_DC, WHITE, BLACK); //��ص�����챨��
        LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 2, BMP_Dan, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 320 + 42 + 21, 100 + 38 * 2, BMP_Ti, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 320 + 42 + 42 , 100 + 38 * 2, BMP_Chayi, WHITE, BLACK); // 
        LCD_DrawImage1BPP(82 + 320 + 42 + 42 + 42, 100 + 38 * 2, BMP_Baojing, WHITE, BLACK); // 
        
        LCD_DrawImage1BPP(82 + 320, 100 + 38 * 3, BMP_Chezai, WHITE, BLACK); //���ش���װ�ù��䱨��
        LCD_DrawImage1BPP(82 + 320 + 42, 100 + 38 * 3, BMP_Chuneng, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 320 + 42 + 42, 100 + 38 * 3, BMP_Zhuangzhi, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 320 + 42 + 42 + 42, 100 + 38 * 3, BMP_Guo, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 320 + 42 + 42 + 42 + 21, 100 + 38 * 3, BMP_Chong, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 320 + 42 + 42 + 42 + 42, 100 + 38 * 3, BMP_Baojing, WHITE, BLACK); // 

        /*for (i = 0; i < 4; i++) {
            LCD_DrawImage1BPP(82, 100 + 38 * i, BMP_Chongdian, WHITE, BLACK); //����ͷ�¶�
            LCD_DrawImage1BPP(82 + 42, 100 + 38 * i, BMP_Chatou, WHITE, BLACK);
            print_SZ_1(82 + 42 + 42, 100 - 8 + 38 * i, i / 2 + 1, 1, 0, WHITE);
            LCD_DrawImage1BPP(82 + 42 + 42 + 16, 100 - 2 + 38 * i, BMP_DCDC, WHITE, BLACK);
            if (i == 0 || i == 2)
                LCD_DrawImage1BPPZOOM_4(82 + 42 + 42 + 16 + 26, 100 + 38 * i, BMP_ZHENG, WHITE, BLACK);
            LCD_DrawImage1BPP(82 + 42 + 42 + 16 + 26 + 12, 100 + 38 * i, BMP_Wendu, WHITE, BLACK);
            LCD_DrawImage1BPP(400 - 24, 100 + 38 * i, BMP_T, WHITE, BLACK); //��
        }

        LCD_DrawImage1BPP(82, 100 + 38 * 4, BMP_Shengyunengliang, WHITE, BLACK); //ʣ������
        LCD_DrawImage1BPP(400 - 24 - 11 - 11, 100 + 38 * 4, BMP_k, WHITE, BLACK); //kwh
        LCD_DrawImage1BPP(400 - 24 - 11, 100 + 38 * 4, BMP_w, WHITE, BLACK);
        LCD_DrawImage1BPP(400 - 24, 100 + 38 * 4, BMP_h, WHITE, BLACK);

        for (i = 0; i < 2; i++) {
            LCD_DrawImage1BPP(82, 100 + 38 * (i + 5), BMP_DC, WHITE, BLACK); //���
            LCD_DrawImage1BPP(82 + 42, 100 + 38 * (i + 5), BMP_Zhuangtai, WHITE, BLACK); //״̬
            LCD_DrawImage1BPP(82 + 42 + 42, 100 - 8 + 38 * (i + 5), BMP_SZ_1[i + 5], WHITE, BLACK); //5  6
        }

        for (i = 0; i < 8; i++) {
            LCD_DrawImage1BPP(82 + 320, 100 + 38 * i, BMP_Zui, WHITE, BLACK); //��
            if (i % 2 == 0)
                LCD_DrawImage1BPP(82 + 320 + 21, 100 + 38 * i, BMP_Gao, WHITE, BLACK); // ��
            else LCD_DrawImage1BPP(82 + 320 + 21, 100 + 38 * i, BMP_Di, WHITE, BLACK); // �� 
            LCD_DrawImage1BPP(82 + 320 + 21 + 21, 100 + 38 * i, BMP_Dan, WHITE, BLACK); //��
            LCD_DrawImage1BPP(82 + 320 + 21 + 21 + 21, 100 + 38 * i, BMP_Ti, WHITE, BLACK); //��
            if (i == 0 || i == 1 || i == 4 || i == 5) {
                LCD_DrawImage1BPP(82 + 320 + 21 + 21 + 21 + 21, 100 + 38 * i, BMP_DY, WHITE, BLACK); //��ѹ
                //LCD_DrawImage1BPP(720 - 24 - 63, 100 + 38 * i, BMP_v, WHITE, BLACK); //V
            } else {
                LCD_DrawImage1BPP(82 + 320 + 21 + 21 + 21 + 21, 100 + 38 * i, BMP_Wendu, WHITE, BLACK); //�¶�
                //LCD_DrawImage1BPP(720 - 28 - 63, 100 + 38 * i, BMP_T, WHITE, BLACK); //��
            }
            if (i < 4)LCD_DrawImage1BPP(82 + 320 + 21 + 21 + 21 + 21 + 42, 100 + 38 * i, BMP_Weizhi, WHITE, BLACK); //λ��
            else LCD_DrawImage1BPP(82 + 320 + 21 + 21 + 21 + 21 + 42, 100 + 38 * i, BMP_Bianhao, WHITE, BLACK); //���
        }*/
    }
    if (index == 3) {
        print_SZ(750, 50, 3, 1, 0, WHITE); // 3/4
        LCD_DrawImage1BPP(750 + 8, 50 - 3, BMP_I, WHITE, BLACK);
        print_SZ(750 + 8 + 14, 50, 4, 1, 0, WHITE);
        
        LCD_DrawRect(80, 90, 1, 380, GREEN);
        //LCD_DrawRect(80 + 320, 90, 1, 380, GREEN);
        LCD_DrawRect(80 + 320 + 320, 90, 1, 380, GREEN);
        for (i = 0; i < 11; i++)
            LCD_DrawRect(80, 90 + i * 38, 640, 1, GREEN);
        
        LCD_DrawImage1BPP(82, 100 + 38 * 0, BMP_DC, WHITE, BLACK); //��ز��豸���ӱ���
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 0, BMP_Cangmen, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 42 + 21, 100 + 38 * 0, BMP_Shebei, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 42 + 21 + 42, 100 + 38 * 0, BMP_Lianjie, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 42 + 21 + 42 + 42, 100 + 38 * 0, BMP_Baojing, WHITE, BLACK); //
        
        LCD_DrawImage1BPP(82, 100 + 38 * 1, BMP_DC, WHITE, BLACK); //��ز�������
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 1, BMP_Cangmen, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 42 + 21, 100 + 38 * 1, BMP_Yanwu, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 42 + 21 + 42, 100 + 38 * 1, BMP_Baojing, WHITE, BLACK); //
        
        LCD_DrawImage1BPP(82, 100 + 38 * 2, BMP_DC, WHITE, BLACK); //��زջ��ֱ���
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 2, BMP_Cangmen, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 42 + 21, 100 + 38 * 2, BMP_Huozai, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 42 + 21 + 42, 100 + 38 * 2, BMP_Baojing, WHITE, BLACK); //
        
        LCD_DrawImage1BPP(82, 100 + 38 * 3, BMP_DC, WHITE, BLACK); //��ز��¶ȱ���
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 3, BMP_Cangmen, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 42 + 21, 100 + 38 * 3, BMP_Wendu, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 42 + 21 + 42, 100 + 38 * 3, BMP_Baojing, WHITE, BLACK); //
        
        LCD_DrawImage1BPP(82, 100 + 38 * 4, BMP_DC, WHITE, BLACK); //��ز����䱨��
        LCD_DrawImage1BPP(82 + 42, 100 + 38 * 4, BMP_Cangmen, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 42 + 21, 100 + 38 * 4, BMP_Tiaobian, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 42 + 21 + 42, 100 + 38 * 4, BMP_Baojing, WHITE, BLACK); //
        
        LCD_DrawImage1BPP(82 , 100 + 38 * 8, BMP_Zhengchang, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 42 + 20, 100 - 4 + 38 * 8, Bmpflag[1], GREEN, BLACK);
        
        LCD_DrawImage1BPP(82, 100 + 38 * 9, BMP_Baojing, WHITE, BLACK); //
        LCD_DrawImage1BPP(82 + 42 + 20, 100 - 4 + 38 * 9, Bmpflag[1], RED, BLACK);
                                            
    }
    if (index == 4) {
        print_SZ(750, 50, 4, 1, 0, WHITE); // 4/4
        LCD_DrawImage1BPP(750 + 8, 50 - 3, BMP_I, WHITE, BLACK);
        print_SZ(750 + 8 + 14, 50, 4, 1, 0, WHITE);
        
        LCD_DrawRect(80, 90, 1, 380, GREEN);
        LCD_DrawRect(80 + 320, 90, 1, 380, GREEN);
        LCD_DrawRect(80 + 320 + 320, 90, 1, 380, GREEN);
        for (i = 0; i < 11; i++)
            LCD_DrawRect(80, 90 + i * 38, 640, 1, GREEN);
        
        for (i = 0; i < 4; i++) {
            print_SZ_1(82, 100 - 8 + 38 * i, i + 1, 1, 0, WHITE); //1�ŵ�ز��¶�
            LCD_DrawImage1BPP(82 + 16, 100 + 38 * i, BMP_Hao, WHITE, BLACK); //
            LCD_DrawImage1BPP(82 + 16 + 21, 100 + 38 * i, BMP_DC, WHITE, BLACK); //
            LCD_DrawImage1BPP(82 + 16 + 21 + 42, 100 + 38 * i, BMP_Cangmen, WHITE, BLACK);
            LCD_DrawImage1BPP(82 + 16 + 21 + 42 + 21, 100 + 38 * i, BMP_Wendu, WHITE, BLACK); //
            LCD_DrawImage1BPP(720 - 28, 100 + 38 * i, BMP_T, WHITE, BLACK); //��
        }
        
        for (i = 0; i < 4; i++) {
            print_SZ_1(82 + 320, 100 - 8 + 38 * i, i + 5, 1, 0, WHITE); //5�ŵ�ز��¶�
            LCD_DrawImage1BPP(82 + 320 + 16, 100 + 38 * i, BMP_Hao, WHITE, BLACK); //
            LCD_DrawImage1BPP(82 + 320 + 16 + 21, 100 + 38 * i, BMP_DC, WHITE, BLACK); //
            LCD_DrawImage1BPP(82 + 320 + 16 + 21 + 42, 100 + 38 * i, BMP_Cangmen, WHITE, BLACK);
            LCD_DrawImage1BPP(82 + 320 + 16 + 21 + 42 + 21, 100 + 38 * i, BMP_Wendu, WHITE, BLACK); //
            LCD_DrawImage1BPP(400 - 28, 100 + 38 * i, BMP_T, WHITE, BLACK); //��
        }
       

    }

}
//һֱ���µ�����
void BMSUpdate(unsigned char index) {
    unsigned char i = 0, j = 0, dump, color = WHITE;
    static unsigned char Static_Old[2]={0xFF,0xFF};
    if(index == 1){
        updata_DCDY(82 + 200 + 30 - 16, 100 - 8);
        updata_DCDL(82 + 200 + 30, 100 - 8 + 38);
        print_SZ_1(82 + 200 + 30, 100 - 8 + 38 * 2, BMS_Charge_Power_Limt, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 30, 100 - 8 + 38 * 3, BMS_Discharge_Power_Limt, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 30, 100 - 8 + 38 * 4, BMS_Life, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 30, 100 - 8 + 38 * 5, BMS_Fault_Code, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 30, 100 - 8 + 38 * 6, BMS_Fault_Level, 3, 0, WHITE);
        if(BMS_Charge_Status.bit2 == 0 && Static_Old[0] != 0){
            LCD_DrawImage1BPP(82 + 200 + 20, 100 + 38 * 7, BMP_Wei, YELLOW, BLACK); //δ���
            LCD_DrawImage1BPP(82 + 200 + 20 + 21, 100 + 38 * 7, BMP_Chongdian, YELLOW, BLACK); 
        }else if(BMS_Charge_Status.bit2 == 1 && Static_Old[0] != 1){
            LCD_DrawImage1BPP(82 + 200 + 20, 100 + 38 * 7, BMP_Chongdian, GREEN, BLACK); //�����
            LCD_DrawImage1BPP(82 + 200 + 20 + 42, 100 + 38 * 7, BMP_Zhong, GREEN, BLACK); 
        }
        Static_Old[0] = BMS_Charge_Status.bit2;
        
        if(BMS_Self_Status == 0 && Static_Old[1] != 0){
            LCD_DrawImage1BPP(82 + 200 + 20, 100 + 38 * 8, BMP_Zijian, YELLOW, BLACK); //�Լ���
            LCD_DrawImage1BPP(82 + 200 + 20 + 42, 100 + 38 * 8, BMP_Zhong, YELLOW, BLACK); 
            LCD_DrawRect(82 + 200 + 20 + 63, 100 + 38 * 8, 21, 20, BLACK);
        }else if(BMS_Self_Status == 1 && Static_Old[1] != 1){
            LCD_DrawImage1BPP(82 + 200 + 20, 100 + 38 * 8, BMP_Zijian, GREEN, BLACK); //�Լ����
            LCD_DrawImage1BPP(82 + 200 + 20 + 42, 100 + 38 * 8, BMP_Wancheng, GREEN, BLACK); 
        }else if(BMS_Self_Status == 2 && Static_Old[1] != 2){
            LCD_DrawImage1BPP(82 + 200 + 20, 100 + 38 * 8, BMP_Zijian, RED, BLACK); //�Լ����
            LCD_DrawImage1BPP(82 + 200 + 20 + 42, 100 + 38 * 8, BMP_Guzhang, RED, BLACK); 
        }
        Static_Old[1] = BMS_Self_Status;
                        
        print_SZ_1(82 + 200 + 300 - 32 - 5, 100 - 8, Battery_Single_H, 4, 3, WHITE);
        print_SZ_1(82 + 200 + 300 - 32 + 16 * 6 - 5, 100 - 8, Battery_Single_H_Positon_Case, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 300 - 32 + 16 * 10 + 5, 100 - 8, Battery_Single_H_Positon_Cell, 3, 0, WHITE);

        print_SZ_1(82 + 200 + 300 - 32 - 5, 100 - 8 + 38, Battery_Single_L, 4, 3, WHITE);
        print_SZ_1(82 + 200 + 300 - 32 + 16 * 6 - 5, 100 - 8 + 38, Battery_Single_L_Positon_Case, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 300 - 32 + 16 * 10 + 5, 100 - 8 + 38, Battery_Single_L_Positon_Cell, 3, 0, WHITE);

        updata_DAT(82 + 200 + 300 - 5, 100 - 8 + 38 * 2, Battery_Temp_H, 1, 40, WHITE, 3, 0);
        print_SZ_1(82 + 200 + 300 - 32 + 16 * 6 - 5, 100 - 8 + 38 * 2, Battery_Temp_H_Positon_Case, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 300 - 32 + 16 * 10 + 5, 100 - 8 + 38 * 2, Battery_Temp_H_Positon_Cell, 3, 0, WHITE);

        updata_DAT(82 + 200 + 300 - 5, 100 - 8 + 38 * 3, Battery_Temp_L, 1, 40, WHITE, 3, 0);
        print_SZ_1(82 + 200 + 300 - 32 + 16 * 6 - 5, 100 - 8 + 38 * 3, Battery_Temp_L_Positon_Case, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 300 - 32 + 16 * 10 + 5, 100 - 8 + 38 * 3, Battery_Temp_L_Positon_Cell, 3, 0, WHITE);
        
        print_SZ_1(82 + 200 + 300 - 32 + 16 * 6 - 5, 100 - 8 + 38 * 4, IDE_Message & 0x0F, 3, 0, WHITE);
        if(((IDE_Message >> 4) & 0x0F) == 0)
            LCD_DrawImage1BPP(82 + 200 + 300 - 32 + 16 * 6 - 5, 100 + 38 * 5, BMP_Zhengchang, GREEN, BLACK); //����
        else 
            LCD_DrawImage1BPP(82 + 200 + 300 - 32 + 16 * 6 - 5, 100 + 38 * 5, BMP_Guzhang, RED, BLACK); //����
        print_SZ_1(82 + 200 + 300 - 32 + 16 * 3 - 5, 100 - 8 + 38 * 6, IDE_Ohm, 6, 0, WHITE);
        print_SZ_1(82 + 200 + 300 - 32 + 16 * 6 - 5, 100 - 8 + 38 * 7, IDE_Life, 3, 0, WHITE);
        
        
    }else if(index == 2){
        dump = BMS_Warn_Message[0].byte;
        for (i = 0; i < 8; i++) {
            if((dump & 0x01) == 0x01){
                LCD_DrawImage1BPP(82 + 180 + 42 + 21, 100 + 38 * i, BMP_Guzhang, RED, BLACK);
            }else {
                LCD_DrawImage1BPP(82 + 180 + 42 + 21, 100 + 38 * i, BMP_Zhengchang, GREEN, BLACK);
            }
            dump >>= 1;
        }
        
        dump = BMS_Warn_Message[1].byte;
        for (i = 0; i < 4; i++) {
            if((dump & 0x01) == 0x01){
                LCD_DrawImage1BPP(82 + 320 + 180 + 42 + 21, 100 + 38 * i, BMP_Guzhang, RED, BLACK);
            }else {
                LCD_DrawImage1BPP(82 + 320 + 180 + 42 + 21, 100 + 38 * i, BMP_Zhengchang, GREEN, BLACK);
            }
            dump >>= 1;
        }
        
    }else if(index == 3){
        for (i = 0; i < 8; i++) {
            dump = BCEM_Warn_Message[i].byte;
            for (j = 0; j < 5; j++) {
                if ((dump & 0x01) == 0x01)
                    color = RED;
                else color = GREEN;
                print_SZ_1(82 + 240 + 50 * i, 100 - 8 + 38 * j, i + 1, 1, 0, WHITE);
                LCD_DrawImage1BPP(82 + 240 + 16 + 50 * i, 100 - 4 + 38 * j, Bmpflag[1], color, BLACK);
                dump = dump >> 1;
            }
        }
    } else if (index == 4) {
        for (i = 0; i < 4; i++) {
            updata_DAT(82 + 220 - 5, 100 - 8 + 38 * i, BCTM_Temp[i], 1, 40, WHITE, 3, 0);
        }
        for (i = 0; i < 4; i++) {
            updata_DAT(82 + 220 + 320 - 5, 100 - 8 + 38 * i, BCTM_Temp[i + 4], 1, 40, WHITE, 3, 0);
        }
    }
    
    /*if (index == 1) {
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

        print_SZ_1(82 + 200 + 300 - 32 - 5, 100 - 8, BAT_Single_H, 4, 3, WHITE);
        print_SZ_1(82 + 200 + 300 - 32 + 16 * 6 - 5, 100 - 8, BAT_Single_H_Case, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 300 - 32 + 16 * 10 + 5, 100 - 8, BAT_Single_H_Number, 3, 0, WHITE);

        print_SZ_1(82 + 200 + 300 - 32 - 5, 100 - 8 + 38, BAT_Single_L, 4, 3, WHITE);
        print_SZ_1(82 + 200 + 300 - 32 + 16 * 6 - 5, 100 - 8 + 38, BAT_Single_L_Case, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 300 - 32 + 16 * 10 + 5, 100 - 8 + 38, BAT_Single_L_Number, 3, 0, WHITE);

        updata_DAT(82 + 200 + 300 - 5, 100 - 8 + 38 * 2, BAT_Temp_H, 1, 40, WHITE, 3, 0);
        print_SZ_1(82 + 200 + 300 - 32 + 16 * 6 - 5, 100 - 8 + 38 * 2, BAT_Temp_H_Case, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 300 - 32 + 16 * 10 + 5, 100 - 8 + 38 * 2, BAT_Temp_H_Number, 3, 0, WHITE);

        updata_DAT(82 + 200 + 300 - 5, 100 - 8 + 38 * 3, BAT_Temp_L, 1, 40, WHITE, 3, 0);
        print_SZ_1(82 + 200 + 300 - 32 + 16 * 6 - 5, 100 - 8 + 38 * 3, BAT_Temp_L_Case, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 300 - 32 + 16 * 10 + 5, 100 - 8 + 38 * 3, BAT_Temp_L_Number, 3, 0, WHITE);

        print_SZ_1(82 + 200 + 260 + 16 * 10, 100 - 8 + 38 * 4, Battery_Cell_Total_Number, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 260 + 16 * 10, 100 - 8 + 38 * 5, BMS_Nubmer, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 260 + 16 * 10, 100 - 8 + 38 * 6, BMS_Life, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 260 + 16 * 8, 100 - 8 + 38 * 7, Ohm_Positive, 5, 0, WHITE);
        print_SZ_1(82 + 200 + 260 + 16 * 8, 100 - 8 + 38 * 8, Ohm_Negative, 5, 0, WHITE);
    }
    if (index == 2) {
        updata_DAT(82 + 200 + 20, 100 - 8, DC1positive_Temp, 1, 40, WHITE, 3, 0);
        updata_DAT(82 + 200 + 20, 100 - 8 + 38, DC1negative_Temp, 1, 40, WHITE, 3, 0);
        updata_DAT(82 + 200 + 20, 100 - 8 + 38 * 2, DC2positive_Temp, 1, 40, WHITE, 3, 0);
        updata_DAT(82 + 200 + 20, 100 - 8 + 38 * 3, DC2negative_Temp, 1, 40, WHITE, 3, 0);
        print_SZ_1(82 + 200 + 4, 100 - 8 + 38 * 4, Energe_Rest * 0.1, 3, 0, WHITE);
        print_D(82 + 180, 100 - 8 + 38 * 5, BMS_Status_Flag5);
        print_D(82 + 180, 100 - 8 + 38 * 6, BMS_Status_Flag6);

        print_SZ_1(82 + 200 + 300 + 16 * 2, 100 - 8, Battery_Single_H_Positon_Total, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 300 + 16 * 2, 100 - 8 + 38, Battery_Single_L_Positon_Total, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 300 + 16 * 2, 100 - 8 + 38 * 2, Battery_Temp_H_Positon_Total, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 300 + 16 * 2, 100 - 8 + 38 * 3, Battery_Temp_L_Positon_Total, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 300 + 16 * 2, 100 - 8 + 38 * 4, Battery_Single_H_Pack, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 300 + 16 * 2, 100 - 8 + 38 * 5, Battery_Single_L_Pack, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 300 + 16 * 2, 100 - 8 + 38 * 6, Battery_Temp_H_Pack, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 300 + 16 * 2, 100 - 8 + 38 * 7, Battery_Temp_L_Pack, 3, 0, WHITE);

    }
    if (index == 3) {
        for (i = 0; i < 10; i++) {
            if (i < BMS_Unit_Number) {
                if (i < 8) {
                    color = ((BMU_Comm_Status1 >> i) & 0x01) > 0 ? RED : GREEN;
                    print_SZ_1(12 + 33 + 32 + 42 + 42 + 16, 100 - 8 + i * 38, (BMU_Comm_Status1 >> i)&0x01, 1, 0, color);
                } else {
                    color = ((BMU_Comm_Status2 >> (i - 8)) & 0x01) > 0 ? RED : GREEN;
                    print_SZ_1(12 + 33 + 32 + 42 + 42 + 16, 100 - 8 + i * 38, (BMU_Comm_Status2 >> (i - 8))&0x01, 1, 0, color);
                }
            }
        }
        for (i = 0; i < 10; i++) {
            if ((10 + i) < BMS_Unit_Number) {
                if (i < 6) {
                    color = ((BMU_Comm_Status2 >> (i + 2)) & 0x01) > 0 ? RED : GREEN;
                    print_SZ_1(12 + 33 + 32 + 42 + 42 + 1 * 195 + 16, 100 - 8 + i * 38, (BMU_Comm_Status2 >> (i + 2))&0x01, 1, 0, color);
                } else {
                    color = ((BMU_Comm_Status3 >> (i - 6)) & 0x01) > 0 ? RED : GREEN;
                    print_SZ_1(12 + 33 + 32 + 42 + 42 + 1 * 195 + 16, 100 - 8 + i * 38, (BMU_Comm_Status3 >> (i - 6))&0x01, 1, 0, color);
                }
            }
        }
        for (i = 0; i < 10; i++) {
            if ((20 + i) < BMS_Unit_Number) {
                if (i < 4) {
                    color = ((BMU_Comm_Status3 >> (i + 4)) & 0x01) > 0 ? RED : GREEN;
                    print_SZ_1(12 + 33 + 32 + 42 + 42 + 2 * 195 + 16, 100 - 8 + i * 38, (BMU_Comm_Status3 >> (i + 4))&0x01, 1, 0, color);
                } else {
                    color = ((BMU_Comm_Status4 >> (i - 4)) & 0x01) > 0 ? RED : GREEN;
                    print_SZ_1(12 + 33 + 32 + 42 + 42 + 2 * 195 + 16, 100 - 8 + i * 38, (BMU_Comm_Status4 >> (i - 4))&0x01, 1, 0, color);
                }
            }
        }
        for (i = 0; i < 2; i++) {
            if ((30 + i) < BMS_Unit_Number) {
                color = ((BMU_Comm_Status4 >> (i + 6)) & 0x01) > 0 ? RED : GREEN;
                print_SZ_1(12 + 33 + 32 + 42 + 42 + 3 * 195 + 16, 100 - 8 + i * 38, (BMU_Comm_Status4 >> (i + 6))&0x01, 1, 0, color);
            }
        }
    }
    if (index == 4) {
        for (i = 0; i < 10; i++) {
            if (i < BMS_Unit_Number) {
                if (i < 8) {
                    color = ((BMU_Bala_Status1 >> i) & 0x01) > 0 ? RED : GREEN;
                    print_SZ_1(12 + 33 + 32 + 42 + 42 + 16, 100 - 8 + i * 38, (BMU_Bala_Status1 >> i)&0x01, 1, 0, color);
                } else {
                    color = ((BMU_Bala_Status2 >> (i - 8)) & 0x01) > 0 ? RED : GREEN;
                    print_SZ_1(12 + 33 + 32 + 42 + 42 + 16, 100 - 8 + i * 38, (BMU_Bala_Status2 >> (i - 8)) & 0x01, 1, 0, color);
                }
            }
        }
        for (i = 0; i < 10; i++) {
            if ((10 + i) < BMS_Unit_Number) {
                if (i < 6) {
                    color = ((BMU_Bala_Status2 >> (i + 2)) & 0x01) > 0 ? RED : GREEN;
                    print_SZ_1(12 + 33 + 32 + 42 + 42 + 1 * 195 + 16, 100 - 8 + i * 38, (BMU_Bala_Status2 >> (i + 2))&0x01, 1, 0, color);
                } else {
                    color = ((BMU_Bala_Status3 >> (i - 6)) & 0x01) > 0 ? RED : GREEN;
                    print_SZ_1(12 + 33 + 32 + 42 + 42 + 1 * 195 + 16, 100 - 8 + i * 38, (BMU_Bala_Status3 >> (i - 6))&0x01, 1, 0, color);
                }
            }
        }
        for (i = 0; i < 10; i++) {
            if ((20 + i) < BMS_Unit_Number) {
                if (i < 4) {
                    color = ((BMU_Bala_Status3 >> (i + 4)) & 0x01) > 0 ? RED : GREEN;
                    print_SZ_1(12 + 33 + 32 + 42 + 42 + 2 * 195 + 16, 100 - 8 + i * 38, (BMU_Bala_Status3 >> (i + 4))&0x01, 1, 0, color);
                } else {
                    color = ((BMU_Bala_Status4 >> (i - 4)) & 0x01) > 0 ? RED : GREEN;
                    print_SZ_1(12 + 33 + 32 + 42 + 42 + 2 * 195 + 16, 100 - 8 + i * 38, (BMU_Bala_Status4 >> (i - 4))&0x01, 1, 0, color);
                }
            }
        }
        for (i = 0; i < 2; i++) {
            if ((30 + i) < BMS_Unit_Number) {
                color = ((BMU_Bala_Status4 >> (i + 6)) & 0x01) > 0 ? RED : GREEN;
                print_SZ_1(12 + 33 + 32 + 42 + 42 + 3 * 195 + 16, 100 - 8 + i * 38, (BMU_Bala_Status4 >> (i + 6))&0x01, 1, 0, color);
            }
        }
    }*/
    /*
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
     */
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
    if (key_AV) {
        key_AV = 0;
        index_BMS--;
        f_index = 0;
        if (index_BMS == 0) {
            index_BMS = 1;
            frmID = 1;
        }
    }

    if (key_up) { //�Ӳ˵��л�
        key_up = 0;
        index_BMS++;
        f_index = 0;
        if (index_BMS == 5) {
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
//������ݽ���
/*******************************************************/
//ֻ����һ�ε�����

void BatteryFrame(void) {
    unsigned char i, j;
    LCD_Clear();
    //LCD_DrawRect(0, 70, 800, 2, YELLOW); //��������
    LCD_DrawImage1BPP(30, 20, BMP_Battery, WHITE, BLACK); //���
    LCD_DrawImage1BPP(30 + 50, 20, BMP_Message, WHITE, BLACK); //��Ϣ

    LCD_DrawImage1BPP(30, 20 + 38 + 7, BMP_BMU, WHITE, BLACK); //��
    //LCD_DrawImage1BPP(30 + 21, 20 + 38 + 7, BMP_Hao, WHITE, BLACK); //��
    //�ָ�
    for (i = 0; i < 3; i++)
        LCD_DrawRect(200 + 200 * i, 90 - 38 * 2, 1, 456, GREEN);
    for (i = 0; i < 13; i++)
        LCD_DrawRect(200, 90 - 38 * 2 + i * 38, 400, 1, GREEN);

    for (j = 0; j < 2; j++) {
        for (i = 0; i < 12; i++) {
            if (i < 9) {//д��Ÿ�λ
                LCD_DrawImage1BPP(40 + 5 + 16 + 36 + 120 + j * 200, 92 - 38 * 2 + i * 38, BMP_SZ_1[i + 1], WHITE, BLACK);
            } else {//д�����һ�б��
                LCD_DrawImage1BPP(40 + 5 + 16 + 36 + 120 + j * 200, 92 - 38 * 2 + i * 38, BMP_SZ_1[i - 9], WHITE, BLACK);
                LCD_DrawImage1BPP(40 + 5 + 36 + 120 + j * 200, 92 - 38 * 2 + i * 38, BMP_SZ_1[1], WHITE, BLACK);
            }
            if (j == 0)
                LCD_DrawImage1BPP(40 + 5 + 72 + 250, 92 - 38 * 2 + i * 38, BMP_V, YELLOW, BLACK);
            else
                LCD_DrawImage1BPP(40 + 5 + 70 + 250 + 200, 100 - 38 * 2 + i * 38, BMP_T, YELLOW, BLACK);
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
//һֱ���µ�����
void BatteryUpdate(void) {
    /*print_SZ_1(30 + 50, 20 + 38, BMU_Number, 2, 0, WHITE);
    for (i = 0; i < 12; i++) {
        if (Battery_Voltage[i] == 0xFFFF)
            print_SZ_1(82 + 200, 100 - 38 * 2 - 8 + 38 * i, Battery_Voltage[i], 4, 3, BLACK); //��Ч��ѹ���
        else
            print_SZ_1(82 + 200, 100 - 38 * 2 - 8 + 38 * i, Battery_Voltage[i], 4, 3, WHITE); //�����ѹ
    }
    for (i = 0; i < 12; i++) {
        if (Battery_Temp[i] == 0xFF)
            updata_DAT(82 + 200 + 220, 100 - 38 * 2 - 8 + 38 * i, Battery_Temp[i], 1, 40, BLACK, 3, 0); //��Ч�¶����
        else
            updata_DAT(82 + 200 + 220, 100 - 38 * 2 - 8 + 38 * i, Battery_Temp[i], 1, 40, WHITE, 3, 0); //�����¶�
    }*/
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
        //f_index = 0;
        /*if (BMU_Number > 0)
            BMU_Number--;
        if (BMU_Number == 0) {
            BMU_Number = BMS_Unit_Number;
        }*/
    }

    if (key_up) {
        key_up = 0;
        //f_index = 0;
        /*BMU_Number++;
        if (BMU_Number > BMS_Unit_Number) {
            BMU_Number = 1;
            f_index = 0;
            frmID = 1;
        }*/
        //if (BMU_Number > Battery_Case_Total_Number)
        //    BMU_Number = 1;

        //frmID = 1;
        //Index++;//������л�
        //if(Index==4) Index=0;
    }

    if (key_set) {//����������
        key_set = 0;
        frmID = 0;
        f_index = 0;
        Index = 0;
//        BMU_Number = 1;
    }
    if (key_long_set) {
        key_long_set = 0;
    }

}

/******************************************************/
//�Ǳ����
/*******************************************************/
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

    LCD_DrawImage1BPP(82 + 320, 100, BMP_Che, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 320 + 21, 100, BMP_Wai, WHITE, BLACK); //��
    LCD_DrawImage1BPP(82 + 320 + 42, 100, BMP_Shiji, WHITE, BLACK); //ʵ��
    LCD_DrawImage1BPP(82 + 320 + 42 + 42, 100, BMP_Wendu, WHITE, BLACK); //�¶�
    //LCD_DrawImage1BPP(82 + 320 + 42 + 42 + 42 + 2, 100 + 5, BMP_Maohao, WHITE, BLACK); //:
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

    updata_DAT(82 + 63 + 42 + 80 + 32 + 320, 100 - 8, Air_Indoor_t, 0.5, 30, WHITE, 3, 0);
    updata_DAT(82 + 63 + 42 + 80 + 32 + 320, 100 - 8 + 38, Air_Outdoor_t, 0.5, 30, WHITE, 3, 0);
    updata_DAT(82 + 63 + 42 + 80 + 32 + 320, 100 - 8 + 38 * 2, Air_Set_t, 0.5, 30, WHITE, 3, 0);
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
//������ý���
/*******************************************************/
//ֻ����һ�ε�����

void SETFrame(void) {
    LCD_Clear();
    //unsigned char i;
    //unsigned char color = WHITE;
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //��������   
    LCD_DrawRect(0, 430 + 15, 800, 2, YELLOW); //�ײ�����   
    LCD_DrawImage1BPP(220, 195, Bmp_Licheng, WHITE, BLACK); //�ۼ����
    LCD_DrawImage1BPP(405, 190, BMP_HZ_KM, WHITE, BLACK); //��λ Km 
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

//��������
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
    //��֤����     bcd[2]*1000+ bcd[0]*100+bcd[3]*10+bcd[1];//�任�����A
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
//���������

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
            frmVCU();
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



