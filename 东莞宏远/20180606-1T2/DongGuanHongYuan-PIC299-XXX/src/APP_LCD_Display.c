#include "APP_System.h"
//include "APP_FONT.h"
#include "APP_CHAR.h"
#include "show_zh_21x20.h"
#include "APP_Srring.h"
#include "APP_LOGO.h"

unsigned char Index = 0;
unsigned char t = 0;
unsigned char t_add = 0;
unsigned char frmID = 0;
unsigned char f_index = 0;
unsigned char menuid = 0;
unsigned char AV_CH = 0;
unsigned char color_old[24] = {};
unsigned int witdh = 0;

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
                //color = BLACK;
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
                //color = BLACK;
                color = color1;
            } else {
                f = 0;
                color = color1;
            }
            LCD_DrawImage1BPP(x + i * 16, y, BMP_SZ_1[bcd[i]], color, BLACK);
        }
    }
    LCD_DrawImage1BPP(x - sum * 16, y, BMP_SZ_1[0], color, BLACK);
    LCD_DrawImage1BPP(x + 16 - sum * 16, y + 8, BMP_ASIC_11x20[120 - 32], color, BLACK);
}

#if 1

void LCD_DrawImageSBPP(unsigned int x, unsigned int y, //û�����֣�������0����ģΪBMP_BLANK       
        unsigned char witdh, //������
        __prog__ const unsigned char **img, //�ַ����׵�ַ
        unsigned char fcolor, //����ǰ��ɫ
        unsigned char bcolor //���屳��ɫ
        ) {
    unsigned char i;
    for (i = 0; img[i] != NULL; i++) {
        LCD_DrawImage1BPP(x + witdh * i, y, img[i], fcolor, bcolor);
    }
}

void LCD_DrawImageSBPP1(unsigned int x, unsigned int y,
        __prog__ const unsigned char **img, //�ַ����׵�ַ
        unsigned char fcolor, //����ǰ��ɫ
        unsigned char bcolor //���屳��ɫ
        ) {
    unsigned char i, witd = 0;
    witdh = 0;
    for (i = 0; img[i] != NULL; i++) {
        LCD_DrawImage1BPP(x + witdh, y, img[i], fcolor, bcolor);
        witd = *(img[i] + 1) * 7;
        witdh += witd;
    }
}
#endif

void LCD_DrawImageString_21x20(unsigned int x, unsigned int y, const unsigned char *s, unsigned char fColor, unsigned char bColor) {
    unsigned int v;
    witdh = 0;
    if (s != NULL) {
        while (*s) {
            if (*s < 0x80) {
                LCD_DrawImage1BPP_11x20(x, y, BMP_ASIC_11x20[*s - 0x20], fColor, bColor);
                s++;
                x += 11;
                witdh += 11;
            } else {
                v = *s - 0x80;
                v *= 128;
                s++;
                v += *s - 0x80;
                LCD_DrawImage1BPP_21x20(x, y, BMP_zh21x20[v], fColor, bColor);
                s++;
                x += 21;
                witdh += 21;
            }
        }
    }
}

typedef struct {
    const unsigned char *img; //��������
    unsigned char squence;
    unsigned char condition;
    unsigned int position; //��̬������ʾλ��
    unsigned int dat; //�䶯������
    unsigned char sum; //��ʾ���ݵ�λ��
} CAN_WARN_LIST;

#define CAN_LIST_NUMBER 120
CAN_WARN_LIST list[CAN_LIST_NUMBER] = {
    {qbmklx, 0}, //ǰ��ģ������
    {dbmklx, 1}, //����ģ������
    {hbmklx, 2}, //��ģ������
    {zmwg, 3}, //����δ�ر���
    {qmwg, 4}, //ǰ��δ�ر���
    {xdcdyd, 5}, //���ص�ѹ��  
    {chagre, 6}, //���ڳ�磬��ֹ�г�   
    {hcmwg, 7}, //�����δ�ر���   
    {clcs, 8}, //��������
    {qmyjfbj, 9}, //ǰ����Ӧ��������
    {qmyjfkg, 10}, //������Ӧ��������
    {zmyjfbj, 11}, //ǰ����Ӧ��������
    {zmyjfkg, 12}, //������Ӧ��������
    {zpl, 13}, //��ƫ��
    {ypl, 14}, //��ƫ��
    {pzbjyx, 15}, //��ײԤ����Ч
    {reserve, 16}, //����
    {reserve, 17}, //����
    {lzqqdkgy, 18}, //˾���뿪����
    {bmsgz, 19}, //bms����
    {hsgz, 20}, //��������
    {wdcybj, 21}, //�¶Ȳ��챨��
    {dcgwbj, 22}, //��ظ��±���
    {cnxtgybj, 23}, //���ش���װ�����͹�ѹ����
    {cnxtqybj, 24}, //���ش���װ������Ƿѹ����
    {socgdbj, 25}, //soc���ͱ���
    {dtdygg, 26}, //�����ѹ����
    {dtdygd, 27}, //�����ѹ����
    {socggbj, 28}, //soc���߱���
    {soctbbj, 29}, //soc���䱨��
    {cnxtppbj, 30}, //�ɳ�索��ϵͳ��ƥ�䱨��
    {dtdycybj, 31}, //��ص���һ���Բ��
    {cnxtgc, 32}, //���ش���װ���͹���
    {dczgygz, 33}, //������ѹ����
    {dczqygz, 34}, //�����Ƿѹ����
    {dtgygg, 35}, //�����ѹ����
    {dtqygg, 36}, //����Ƿѹ����
    {dtdycygz, 37}, //�����ѹ�������
    {wdcygz, 38}, //�¶Ȳ������
    {wdggz, 39}, //�¶ȹ��߹���
    {wdgdgz, 40}, //�¶ȹ��͹���
    {cdglgz, 41}, //����������
    {fdglgz, 42}, //�ŵ��������
    {socgggz, 43}, //soc ���߹���
    {socgdgz, 44}, //soc ���͹���
    {cdqwdgz, 45}, //���ǹ�¶ȹ���
    {dydxgz, 46}, //��ѹ���߹���
    {wddxgz, 47}, //�¶ȶ��߹���
    {nbtxgz, 48}, //�ڲ�ͨѶ����
    {xtgz, 49}, //ϵͳ����
    {cantxgz, 50}, //can ͨ�Ź���
    {jygz, 51}, //��Ե����
    {qbdcacgz, 52}, //���� dcac ����
    {ybdcacgz, 53}, //�ͱ� dcac ����
    {dldcxtgz, 54}, //�������ϵͳ����
    {djxtgr, 55}, //���ϵͳ����
    {djcs, 56}, //�������
    {ktgz, 57}, //�յ�����
    {ycgz, 58}, //Ԥ�����
    {mkgz, 59}, //ģ�����
    {xdlgz, 60}, //���������
    {kzqgy, 61}, //��������ѹ
    {zjgz, 62}, //�Լ����
    {dygz, 63}, //��ѹ�������
    {djdzgz, 64}, //�����ת����
    {mxglgz, 65}, //ĸ�߹�������
    {djkzqgw, 66}, //�������������
    {csgz, 67}, //���ٹ���
    {kzqqy, 68}, //������Ƿѹ
    {djgw, 69}, //�������
    {djgzai, 70}, //�������
    {mkwdbj, 71}, //ģ����¸澯
    {djwdbj, 72}, //������¸澯
    {mxqybj, 73}, //ĸ��Ƿѹ�澯
    {mxgybj, 74}, //ĸ�߹�ѹ�澯
    {wddkbj, 75}, //�¶ȶ��߸澯
    {qbsrgl, 76}, //�����������
    {qbsrgy, 77}, //���������ѹ
    {qbsrqy, 78}, //��������Ƿѹ
    {qbgzbh, 79}, //���ù��ر���
    {qbsrscdk, 80}, //������������Ͽ�
    {qbsrscdl, 81}, //�������������·
    {qbscdl, 82}, //�������ȱ��
    {qbkzqgw, 83}, //���ÿ���������
    {qbdjcs, 84}, //���õ������
    {qbdjgw, 85}, //���õ������
    {ybsrgl, 86}, //�ͱ��������
    {ybsrgy, 87}, //�ͱ������ѹ
    {ybsrqy, 88}, //�ͱ�����Ƿѹ
    {ybgzbh, 89}, //�ͱù��ر���
    {ybsrscdk, 90}, //�ͱ���������Ͽ�
    {ybsrscdl, 91}, //�ͱ����������·
    {ybscdl, 92}, //�ͱ����ȱ��
    {ybkzqgw, 93}, //�ͱÿ���������
    {ybdjcs, 94}, //�ͱõ������
    {ybdjgw, 95}, //�ͱõ������
    {dcdcxtgz, 96}, //dcdcϵͳ����
    {ybxtgz, 97}, //�ͱ�ϵͳ����
    {qbxtgz, 98}, //����ϵͳ����   
    {dldcdk, 99}, //������ضϿ� 
    { xtyjgz, 100}, //	ϵͳһ������
    { xtejgz, 101}, //	ϵͳ��������
    { xtsjgz, 102}, //	ϵͳ��������
    { ywcgqwdg1, 103}, //	���������¶ȸ�1
    { ywcgqndg1, 104}, //	��������Ũ�ȸ�1
    { ywcgqwdg2, 105}, //	���������¶ȸ�2
    { ywcgqndg2, 106}, //	��������Ũ�ȸ�2
    { yjcwgbj, 107}, //	Ӧ����δ�ر���
    { bpqgz, 108}, //	��Ƶ������
    { djxtgz, 109}, //	���ϵͳ����
    { hzgz, 110}, //	���ֹ���
    { ywbjqgz, 111}, //	������������
    { ywbj, 112}, //	������
    { ywwdbj, 113}, //	�����¶ȱ���
    {NULL}
};

static void CAN_WARN_DYNAMIC_UPDATE(CAN_WARN_LIST list, unsigned int x, unsigned int y) {//������ʾ��̬�仯������
    if (list.condition)
        print_SZ_2(x + list.position, y, list.dat, list.sum, 0, YELLOW);
}

static void CAN_WARN_UPDATE(void) {
    list[0].condition = (Fcan_count == CAN_TIME);
    list[1].condition = (Mcan_count == CAN_TIME);
    list[2].condition = (0);
    list[3].condition = (SPEED > 5 && LED2);
    list[4].condition = (SPEED > 5 && LED1);
    list[5].condition = (BAT24V_count == BAT24_TIME);
    list[6].condition = (LED7);
    list[7].condition = (mKL5);
    list[8].condition = (SPEED > 69);
    list[9].condition = (mKL2);
    list[10].condition = (mKL4);
    list[11].condition = (mKL6);
    list[12].condition = (mADD);
    list[13].condition = (0);
    list[14].condition = (0);
    list[15].condition = (0);
    list[16].condition = 0;
    list[17].condition = 0;
    list[18].condition = (((CAN_0x0CF101A7.Gear == 1) || (CAN_0x0CF101A7.Gear == 2)) && !fKL8);
    list[19].condition = (0);
    list[20].condition = (0);
    list[21].condition = 0;
    list[22].condition = (0);
    list[23].condition = 0;
    list[24].condition = 0;
    list[25].condition = (CAN_0x0CF1064A.VCU_DTC == 108);
    list[26].condition = ((CAN_0x0CF1064A.VCU_DTC == 3) || (CAN_0x0CF1064A.VCU_DTC == 52) || (CAN_0x0CF1064A.VCU_DTC == 102));
    list[27].condition = ((CAN_0x0CF1064A.VCU_DTC == 4) || (CAN_0x0CF1064A.VCU_DTC == 53) || (CAN_0x0CF1064A.VCU_DTC == 103));
    list[28].condition = 0;
    list[29].condition = (0);
    list[30].condition = (0);
    list[31].condition = (0);
    list[32].condition = 0;
    list[33].condition = (CAN_0x0CF1064A.VCU_DTC == 100);
    list[34].condition = (CAN_0x0CF1064A.VCU_DTC == 101);
    list[35].condition = (0);
    list[36].condition = (0);
    list[37].condition = (CAN_0x0CF1064A.VCU_DTC == 104);
    list[38].condition = ((CAN_0x0CF1064A.VCU_DTC == 8) || (CAN_0x0CF1064A.VCU_DTC == 57) || (CAN_0x0CF1064A.VCU_DTC == 107));
    list[39].condition = ((CAN_0x0CF1064A.VCU_DTC == 6) || (CAN_0x0CF1064A.VCU_DTC == 55) || (CAN_0x0CF1064A.VCU_DTC == 105));
    list[40].condition = (CAN_0x0CF1064A.VCU_DTC == 106);
    list[41].condition = ((CAN_0x0CF1064A.VCU_DTC == 12) || (CAN_0x0CF1064A.VCU_DTC == 61) || (CAN_0x0CF1064A.VCU_DTC == 111));
    list[42].condition = (CAN_0x0CF1064A.VCU_DTC == 110);
    list[43].condition = (0);
    list[44].condition = (0);
    list[45].condition = 0;
    list[46].condition = 0;
    list[47].condition = 0;
    list[48].condition = (CAN_0x0CF1064A.VCU_DTC == 63);
    list[49].condition = (CAN_0x0CF101A7.SystemFault);
    list[50].condition = (0);
    list[51].condition = (CAN_0x18F746E5.InsulationResisitanceFaultLevel > 0);
    list[52].condition = 0;
    list[53].condition = 0;
    list[54].condition = (CAN_0x18F13DF3.BmsFaultLevel > 0);
    list[55].condition = (0);
    list[56].condition = 0;
    list[57].condition = 0;
    list[58].condition = 0;
    list[59].condition = 0;
    list[60].condition = 0;
    list[61].condition = 0;
    list[62].condition = 0;
    list[63].condition = 0;
    list[64].condition = 0;
    list[65].condition = 0;
    list[66].condition = (0);
    list[67].condition = (0);
    list[68].condition = 0;
    list[69].condition = (0);
    list[70].condition = 0;
    list[71].condition = 0;
    list[72].condition = 0;
    list[73].condition = 0;
    list[74].condition = 0;
    list[75].condition = 0;
    list[76].condition = 0;
    list[77].condition = 0;
    list[78].condition = 0;
    list[79].condition = 0;
    list[80].condition = 0;
    list[81].condition = 0;
    list[82].condition = 0;
    list[83].condition = 0;
    list[84].condition = 0;
    list[85].condition = 0;
    list[86].condition = 0;
    list[87].condition = 0;
    list[88].condition = 0;
    list[89].condition = 0;
    list[90].condition = 0;
    list[91].condition = 0;
    list[92].condition = 0;
    list[93].condition = 0;
    list[94].condition = 0;
    list[95].condition = 0;
    list[96].condition = (CAN_0x142CFF98.DCDC_Status == 2);
    list[97].condition = (CAN_0x142FFF95.SwitcherPumpStatus == 2);
    list[98].condition = (CAN_0x1429FF9B.DCAC_PumpStatus == 2);
    list[99].condition = (0);
    list[100].condition = (CAN_0x0CF1064A.FaultLevel == 1);
    list[101].condition = (CAN_0x0CF1064A.FaultLevel == 2);
    list[102].condition = (CAN_0x0CF1064A.FaultLevel == 3);
    list[103].condition = (IN19);
    list[104].condition = (IN20);
    list[105].condition = (IN28);
    list[106].condition = (IN27);
    list[107].condition = (fKL10);
    list[108].condition = (mKH1);
    list[109].condition = (CAN_0x18F121F0.MotorCtrlStatus == 5);
    list[110].condition = (CAN_0x0CF1064A.VCU_DTC == 24);
    list[111].condition = ((FogWarn[0].FogWarnStatus == 3) || (FogWarn[1].FogWarnStatus == 3) || (FogWarn[2].FogWarnStatus == 3));
    list[112].condition = (FogWarn[0].WarnStatus || FogWarn[1].WarnStatus || FogWarn[2].WarnStatus);
    list[113].condition = (FogWarn[0].TempWarn || FogWarn[1].TempWarn || FogWarn[2].TempWarn);
}
#define BLANK  300

static void CAN_WARN(unsigned int x, unsigned int y,
        CAN_WARN_LIST list[]
        ) {
    static unsigned char i = 0;
    CAN_WARN_UPDATE();
    for (; i < CAN_LIST_NUMBER; i++) {
        if (list[i].condition) {
            LCD_DrawImageString_21x20(x, y, list[i].img, YELLOW, BLACK);
            LCD_DrawRect(x + witdh, y - 8, BLANK - witdh, 36, BLACK);
            CAN_WARN_DYNAMIC_UPDATE(list[i], x, y);
            i++;
            break;
        }
    }
    if (i >= CAN_LIST_NUMBER) {
        alarm_update_flag = 0;
        LCD_DrawRect(x, y - 8, BLANK, 36, BLACK);
        i = 0;
    }
}

void disp_FONT_baojingNew(unsigned int x, unsigned int y) {
    if (alarm_update_flag == 0) {
        alarm_update_flag = 1;
        CAN_WARN(x, y + 8, list);
    }
}

void disp_miles() {//��ʾ���
#if DrawBus
    print_SZ_1(10, 318 + 15 + 38 + 2, total_miles / 10, 7, 0, WHITE);
    print_SZ_1(10 + 16, 318 + 15 + 38 * 2 + 2, single_miles, 5, 1, WHITE);
#else
    print_SZ_1(2 + 64 + 4 + 10, 440 - 2 + 13 - 5, total_miles / 10, 7, 0, WHITE);
    print_SZ_1(240 + 80 + 4 + 330 + 30 - 16, 440 - 2 + 13 - 5, single_miles, 5, 1, WHITE);
#endif    
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
    if (frmID == 1 || DrawBus) {
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

#if DrawBus

void BMP_Men_Guan(unsigned int x, unsigned int y, unsigned char color) {
    //�����
    disp_rectange(x, y, 72, 2, 88, 2, color);
    //������
    LCD_DrawRect(x + 36, y + 2, 1, 81, color);
    //����̤��
    LCD_DrawRect(x + 7, y + 83, 57, 2, color);
    LCD_DrawRect(x + 7, y + 83, 1, 3, color);
    LCD_DrawRect(x + 7 + 56, y + 83, 1, 3, color);
    //�����ڿ�
    disp_rectange(x + 4, y + 3, 30, 2, 78, 2, color);
    //�����ڿ�
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
    disp_rectange(x + 4 + 35, y + 3, 29, 2, 78, 2, BLACK);
}

void BMP_BUS(unsigned int x, unsigned int y) {
    unsigned char i;
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

    BMP_Men_Guan(x + 195, y + 27, WHITE);

    BMP_Men_Guan(x + 184 + 215, y + 27, WHITE);

    LCD_DrawImage1BPP(x + 471, y + 6, Bmp_Chetou1, WHITE, BLACK); //��ͷ1
    LCD_DrawImage1BPP(x + 471 + 24, y + 6 + 13, Bmp_Chetou2, WHITE, BLACK); //��ͷ2
    LCD_DrawRect(x + 471 + 12, y + 6 + 13, 12, 2, WHITE);
    LCD_DrawRect(x + 471 + 12, y + 6 + 13 + 5, 12, 2, WHITE);

    //С����1
    disp_rectange(x + 8 + 3, y + 8 + 12 + 3, 31, 1, 20, 1, WHITE);

    //С����2
    disp_rectange(x + 8 + 3 + 34, y + 8 + 12 + 3, 31, 1, 20, 1, WHITE);

    LCD_DrawRect(x + 8 + 3 + 15, y + 8 + 12 + 3 + 50, 32, 1, WHITE); //ɢ�ȿ�
    LCD_DrawRect(x + 8 + 3 + 15, y + 8 + 12 + 3 + 28 + 50, 32, 1, WHITE); //
    for (i = 0; i < 9; i++) {
        LCD_DrawRect(x + 8 + 3 + 15 + 4 * i, y + 8 + 12 + 3 + 50, 1, 28, WHITE); //
    }

    //�д���1
    disp_rectange(x + 8 + 3 + 34 + 34, y + 8 + 12 + 3, 53, 1, 46, 1, WHITE);

    //�д���2
    disp_rectange(x + 8 + 3 + 34 + 34 + 56, y + 8 + 12 + 3, 53, 1, 46, 1, WHITE);

    //ǰ����1
    disp_rectange(x + 8 + 3 + 34 + 34 + 56 * 2 + 72 + 10, y + 8 + 12 + 3, 53, 1, 46, 1, WHITE);

    //ǰ����
    disp_rectange(x + 8 + 3 + 34 + 34 + 56 * 3 + 72 + 20, y + 8 + 12 + 3, 53, 1, 46, 1, WHITE);
}
#endif

#if MODE_FV

void updata_QY(void) {
    unsigned char color = RED;
    unsigned int press1 = 50; /*��ѹ������������0-1.2Mpa ,��ӦΪ0-120 ������0-100*/
    static int update_press1 = 0;
    unsigned int press2 = 90; /*��ѹ������������0-1.2Mpa ,��ӦΪ0-120 ������0-100*/
    static int update_press2 = 0;
    /*if (ADR[1] < 10) press1 = 0;
    else if (ADR[1] <= 52) press1 = (ADR[1] - 10)*0.48;
    else if (ADR[1] <= 124) press1 = (ADR[1] - 52)*0.56 + 20;
    else if (ADR[1] <= 155) press1 = (ADR[1] - 124)*0.65 + 60;
    else press1 = (ADR[1] - 155)*0.69 + 80;*/
    if (ADV[2] < 500)
        press1 = 0;
    else if (ADV[2] > 3000)
        press1 = 100;
    else
        press1 = (ADV[2] - 500) / 25;

    if (ADV[3] < 500)
        press2 = 0;
    else if (ADV[3] > 3000)
        press2 = 100;
    else
        press2 = (ADV[3] - 500) / 25;

    //����
    PRESS[0] = press1;
    if (press1 > update_press1) update_press1 += 2;
    else if (press1 < update_press1)update_press1--;
    else update_press1 = press1;

    if (update_press1 > 60) color = GREEN;
    else color = RED;
    if (update_press1 > 100) update_press1 = 100;
    print_SZ_1(33 - 7 - 16, 410 + 13 - 5 - 10, update_press1, 3, 2, color);
    LCD_DrawImage1BPP(33 + 9, 380 + 13 - 5 - 10, Bmp_QY1, color, BLACK); //��ѹ1ͼ��
    LCD_DrawRect(38, 108 + 12 - 5 - 10, 44, (260 - update_press1 * 2.6), BLACK); //260/100  
    if (update_press1 % 5 == 0) {
        LCD_DrawRect(38, (368 + 12 - 5 - 10 - update_press1 * 2.6), 44, (update_press1 * 2.6), color);
    } else {
        LCD_DrawRect(38, (368 + 12 - 5 - 10 - update_press1 * 2.6), 44, (update_press1 * 2.6 + 1), color);
    }

    /*if (ADR[2] < 10) press2 = 0;
    else if (ADR[2] <= 52) press2 = (ADR[2] - 10)*0.48;
    else if (ADR[2] <= 124) press2 = (ADR[2] - 52)*0.56 + 20;
    else if (ADR[2] <= 155) press2 = (ADR[2] - 124)*0.65 + 60;
    else press2 = (ADR[2] - 155)*0.69 + 80;*/

    PRESS[1] = press2;
    //����
    if (press2 > update_press2) update_press2 += 2;
    else if (press2 < update_press2)update_press2--;
    else update_press2 = press2;

    if (update_press2 > 60) color = GREEN;
    else color = RED;
    if (update_press2 > 100) update_press2 = 100;
    LCD_DrawImage1BPP(712 + 9, 380 + 13 - 5 - 10, Bmp_QY2, color, BLACK); //��ѹ2ͼ��
    print_SZ_1(712 - 7 - 16, 410 + 13 - 5 - 10, update_press2, 3, 2, color);
    LCD_DrawRect(712 + 5, 108 + 12 - 5 - 10, 44, (260 - update_press2 * 2.6), BLACK); //260/100  
    if (update_press2 % 5 == 0) {
        LCD_DrawRect(712 + 5, (368 + 12 - 5 - 10 - update_press2 * 2.6), 44, (update_press2 * 2.6), color);
    } else {
        LCD_DrawRect(712 + 5, (368 + 12 - 5 - 10 - update_press2 * 2.6), 44, (update_press2 * 2.6 + 1), color);
    }

}
#endif

void disp_BMP_baojing(void) {
    unsigned char color = GRAY;
    //unsigned char color_mode[3];

    if (fKL7)
        color = YELLOW;
    else
        color = GRAY;
    if (color_old[0] != color) {
        color_old[0] = color;
        LCD_DrawImage1BPP(8, 10, Bmp_baojing[0], color, BLACK); //ASR
    }

    if (fKL6 && (SPEED > 5))
        color = RED;
    else
        color = GRAY;
    if (color_old[1] != color) {
        color_old[1] = color;
        LCD_DrawImage1BPP(8 + 66, 10, Bmp_baojing[4], color, BLACK); //��ȫ��
    }

    if (mKL5)
        color = RED;
    else
        color = GRAY;
    if (color_old[2] != color) {
        color_old[2] = color;
        LCD_DrawImage1BPP(8 + 66 * 2, 10, Bmp_baojing[3], color, BLACK); //�����
    }

    if (!fKL4)
        color = RED;
    else
        color = GRAY;
    if (color_old[3] != color) {
        color_old[3] = color;
        LCD_DrawImage1BPP(8 + 66 * 3, 10, Bmp_baojing[7], color, BLACK); //��ǰɲ��Ƭ
        LCD_DrawImage1BPP_11x20(8 + 66 * 3 + 17, 10 + 15, BMP_ASIC_11x20[76 - 32], color, BLACK);
        print_SZ(8 + 66 * 3 + 17 + 11, 10 + 18, 1, 1, 0, color);
    }

    if (CAN_0x18F746E5.InsulationResisitanceFaultLevel > 0)
        color = RED;
    else
        color = GRAY;
    if (color_old[4] != color) {
        color_old[4] = color;
        LCD_DrawImage1BPP(8 + 66 * 4, 10, Bmp_baojing[5], color, BLACK); //��Ե����
    }

    if (mKL7)
        color = RED;
    else
        color = GRAY;
    if (color_old[5] != color) {
        color_old[5] = color;
        LCD_DrawImage1BPP(8 + 66 * 5, 10, Bmp_baojing[2], color, BLACK); //ˮλ

    }

    if (Flash[Flash_500ms].Status)
        color = YELLOW;
    else
        color = GRAY;
    if (color_old[6] != color) {
        color_old[6] = color;
        LCD_DrawImage1BPP(8 + 66 * 6, 10, Bmp_baojing[12], color, BLACK); //����
    }

    if (CAN_0x18F121F0.MotorCtrlStatus == 5)
        color = RED;
    else
        color = GRAY;
    if (color_old[7] != color) {
        color_old[7] = color;
        LCD_DrawImage1BPP(8 + 66 * 7, 10, Bmp_baojing[9], color, BLACK); //�������

    }

    if (!fKL5)
        color = RED;
    else
        color = GRAY;
    if (color_old[8] != color) {
        color_old[8] = color;
        LCD_DrawImage1BPP(8 + 66 * 8, 10, Bmp_baojing[7], color, BLACK); //��ǰɲ��Ƭ
        LCD_DrawImage1BPP_11x20(8 + 66 * 8 + 17, 10 + 15, BMP_ASIC_11x20[82 - 32], color, BLACK);
        print_SZ(8 + 66 * 8 + 17 + 11, 10 + 18, 1, 1, 0, color);
    }

    if (CAN_0x18F13DF3.BmsFaultLevel > 0)
        color = RED;
    else
        color = GRAY;
    if (color_old[9] != color) {
        color_old[9] = color;
        LCD_DrawImage1BPP(8 + 66 * 9, 10, Bmp_baojing[14], color, BLACK); //������ع���
    }

    if (((CAN_0x0CF101A7.Gear == 1) || (CAN_0x0CF101A7.Gear == 2)) && !fKL8)
        color = RED;
    else
        color = GRAY;
    if (color_old[10] != color) {
        color_old[10] = color;
        LCD_DrawImage1BPP(8 + 66 * 10, 10, Bmp_baojing[13], color, BLACK); //������Ӧ����
    }

    if (IN34)
        color = YELLOW;
    else
        color = GRAY;
    if (color_old[11] != color) {
        color_old[11] = color;
        LCD_DrawImage1BPP(8 + 66 * 11, 10, Bmp_baojing[1], color, BLACK); //ABS
    }
    /****************************�ڶ���ͼƬ****************************************/
    if (!CAN_0x0CF103A7.ContactorOrder)
        color = YELLOW;
    else
        color = GRAY;
    if (color_old[12] != color) {
        color_old[12] = color;
        LCD_DrawImage1BPP(140 + 66 * 0, 74 - 5, Bmp_baojing[11], color, BLACK); //��ѹ����
    }

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

    if (!mKL8)
        color = RED;
    else
        color = GRAY;
    if (color_old[13] != color) {
        color_old[13] = color;
        LCD_DrawImage1BPP(140 + 66 * 1, 74 - 5, Bmp_baojing[7], color, BLACK); //���ɲ��Ƭ
        LCD_DrawImage1BPP_11x20(140 + 66 * 1 + 19, 74 - 5 + 15, BMP_ASIC_11x20[76 - 32], color, BLACK);
        print_SZ(140 + 66 * 1 + 19 + 11, 74 - 5 + 18, 2, 1, 0, color);
        //LCD_DrawImage1BPP(140 + 66 * 1, 74 - 5, Bmp_baojing[16], color, BLACK); //������Ӧ
    }

    if (mKL2 || mKL4 || mKL6 || mADD)
        color = RED;
    else
        color = GRAY;
    if (color_old[14] != color) {
        color_old[14] = color;
        LCD_DrawImage1BPP(140 + 66 * 2, 74 - 5, Bmp_baojing[6], color, BLACK); //Ӧ����        
    }
    /*if (fKL8 || fKL10 || mKL6)
        color = RED;
    else 
        color = GRAY;
    print_SZ(140 + 66 * 2 + 54 - 1, 74 - 5 + 18 - 22, 1, 1, 0, color);
    
    if (mKL8 || rKL9 || rKL7)
        color = RED;
    else 
        color = GRAY;
    print_SZ(140 + 66 * 2 + 54 - 1, 74 - 5 + 18 + 16, 2, 1, 0, color);*/
    ////////////////////////////////////////////////////////////////

    if (CAN_0x0CF101A7.READY)
        color = GREEN;
    else
        color = GRAY;
    if (color_old[15] != color) {
        color_old[15] = color;
        LCD_DrawImage1BPP(138 + 66 * 3 - 1, 74 + 12 - 5, Bmp_READY, color, BLACK); //ready
    }

    if (CAN_0x0CF101A7.LimitPower || CAN_0x0CF101A7.LimitTorque)
        color = YELLOW;
    else
        color = GRAY;
    if (color_old[16] != color) {
        color_old[16] = color;
        //��λ
    }

    if (CAN_0x0CF101A7.LimitPower || CAN_0x0CF101A7.LimitTorque)
        color = YELLOW;
    else
        color = GRAY;
    if (color_old[17] != color) {
        color_old[17] = color;
        LCD_DrawImage1BPP(140 + 66 * 5, 74 - 5, Bmp_baojing[10], color, BLACK); //�޹���
    }

    if (!mKL9)
        color = RED;
    else
        color = GRAY;
    if (color_old[18] != color) {
        color_old[18] = color;
        LCD_DrawImage1BPP(140 + 66 * 6, 74 - 5, Bmp_baojing[7], color, BLACK); //�Һ�Ħ��Ƭ
        LCD_DrawImage1BPP_11x20(140 + 66 * 6 + 19, 74 - 5 + 15, BMP_ASIC_11x20[82 - 32], color, BLACK);
        print_SZ(140 + 66 * 6 + 19 + 11, 74 - 5 + 18, 2, 1, 0, color);
    }

    if (CAN_0x0CF101A7.SystemFault)
        color = RED;
    else
        color = GRAY;
    if (color_old[19] != color) {
        color_old[19] = color;
        LCD_DrawImage1BPP(140 + 66 * 7, 74 - 5, Bmp_baojing[8], color, BLACK); //����״̬
    }
    
    if (CAN_0x0CF101A7.LimitPower || CAN_0x0CF101A7.LimitTorque)
        color = RED;
    else
        color = GRAY;
    if (color_old[20] != color) {
        color_old[20] = color;
        //LCD_DrawImage1BPP(140 + 66 * 8, 74 - 5, Bmp_baojing[10], color, BLACK); //
    }

}
#if 0

void disp_FONT_baojing(unsigned int x, unsigned int y) {
    static unsigned char al_index = 0; //, Comm_i = 0, Comm_j = 0, FLAG;
    if (alarm_update_flag == 0) { //3S ����һ�� 
        switch (al_index) {
            case 0:
                al_index = 1;
                if (Fcan_count == CAN_TIME) {
                    LCD_DrawImageSBPP(x, y + 8, 42, QBMKLX, YELLOW, BLACK); //ǰ��
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 1:
                al_index = 2;
                if (Mcan_count == CAN_TIME) {
                    LCD_DrawImageSBPP(x, y + 8, 42, DBMKLX, YELLOW, BLACK); //����
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 2:
                al_index = 3;
                if (Rcan_count == CAN_TIME) {
                    LCD_DrawImageSBPP(x, y + 8, 42, HBMKLX, YELLOW, BLACK); //��
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 3:
                al_index = 4;
                if (CAN_0x0C04A1A7.FaultLevel) {
                    LCD_DrawImageSBPP(x, y + 8, 42, DJXTGZ, YELLOW, BLACK); //���ϵͳ����
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 4:
                al_index = 5;
                if (CAN_0x0C06A1A7.VCUOilPumpTempWarn) {
                    LCD_DrawImageSBPP(x, y + 8, 42, YBWDBJ, YELLOW, BLACK); //�ͱ��¶ȱ���
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 5:
                al_index = 6;
                /*if (0) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DC, YELLOW, BLACK); //��ظ��±���
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Gao, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 21, y + 8, BMP_Wendu, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x0C06A1A7.VCUAirPumpTempWarn) {
                    LCD_DrawImageSBPP(x, y + 8, 42, QBWDBJ, YELLOW, BLACK); //�����¶ȱ���
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 6:
                al_index = 7;
                /*if (0) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Dan, YELLOW, BLACK); //�����ѹ����
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_Ti, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                /*if (0) {
                    LCD_DrawImageSBPP(x, y + 8, 21, GYDC, YELLOW, BLACK); //��ѹ���1����
                    print_SZ_2(x + 84, y + 8, 1, 1, 0, YELLOW);
                    LCD_DrawImage1BPP(x + 84 + 11, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 84 + 11 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x0C06A1A7.VCUOverSpeed) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Chaosu, YELLOW, BLACK); //���ٱ���
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 7:
                al_index = 8;
                /*if (0) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DC, YELLOW, BLACK); //������ѹ����
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Zu, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 21, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 21, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 21 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 21 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                /*if (0) {
                    LCD_DrawImageSBPP(x, y + 8, 21, GYDC, YELLOW, BLACK); //��ѹ���2����
                    print_SZ_2(x + 84, y + 8, 2, 1, 0, YELLOW);
                    LCD_DrawImage1BPP(x + 84 + 11, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 84 + 11 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1818D0F3.BMSFlag1.bit1) {
                    LCD_DrawImageSBPP(x, y + 8, 21, DTDYGG, YELLOW, BLACK); //�����ѹ����
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 8:
                al_index = 9;
                /*if (0) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DC, YELLOW, BLACK); //�����Ƿѹ����
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Zu, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 21, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 21, y + 8, BMP_Qian, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 21 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 21 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1818D0F3.BMSFlag1.bit2) {
                    LCD_DrawImageSBPP(x, y + 8, 21, DTDYGD, YELLOW, BLACK); //�����ѹ����
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 9:
                al_index = 10;
                /*if (0) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Dan, YELLOW, BLACK); //����Ƿѹ����
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_Ti, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Qian, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1818D0F3.BMSFlag1.bit3) {
                    LCD_DrawRect(x, y, 100, 36, BLACK);
                    LCD_DrawImageSBPP(x, y + 8, 21, SOCGG, YELLOW, BLACK); //SOC����
                    LCD_DrawRect(x + 63 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 10:
                al_index = 11;
                /*if (0) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Chong, YELLOW, BLACK); //���ǹ���±���
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Qiang, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 63, y + 8, BMP_Gao, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 63 + 21, y + 8, BMP_Wendu, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 63 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 63 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1818D0F3.BMSFlag1.bit4) {
                    LCD_DrawRect(x, y, 100, 36, BLACK);
                    LCD_DrawImageSBPP(x, y + 8, 21, SOCGD, YELLOW, BLACK); //SOC����
                    LCD_DrawRect(x + 63 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 11:
                al_index = 12;
                if (CAN_0x1818D0F3.BMSFlag1.bit5) {
                    LCD_DrawImageSBPP(x, y + 8, 42, DCTXGZ, YELLOW, BLACK); //���ͨѶ����
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
            case 12:
                al_index = 13;
                /*if (VCU_FaultCode == 145 || VCU_FaultCode == 215) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Fang, YELLOW, BLACK); //�ŵ��������
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_DL, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_DL, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                /*if (CAN_0x18EF4BEF.CAP_offline_Warning == 1) {
                    LCD_DrawImageSBPP(x, y + 8, 21, DRLX, YELLOW, BLACK); //��������
                    LCD_DrawRect(x + 84, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1818D0F3.BMSFlag1.bit6) {
                    LCD_DrawImageSBPP(x, y + 8, 21, ZDYQY, YELLOW, BLACK); //�ܵ�ѹǷѹ
                    LCD_DrawRect(x + 42 + 42 + 21, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 13:
                al_index = 14;
                /*if (VCU_FaultCode == 146 || VCU_FaultCode == 216) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Chong, YELLOW, BLACK); //����������
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_DL, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_DL, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1818D0F3.BMSFlag1.bit7) {
                    LCD_DrawImageSBPP(x, y + 8, 21, ZDYGY, YELLOW, BLACK); //�ܵ�ѹ��ѹ
                    LCD_DrawRect(x + 42 + 42 + 21, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 14:
                al_index = 15;
                /*if (VCU_FaultCode == 144 || VCU_FaultCode == 214) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Dan, YELLOW, BLACK); //�����ѹ���챨��
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_Ti, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Chayi, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1818D0F3.BMSFlag1.bit8) {
                    LCD_DrawImageSBPP(x, y + 8, 42, JHGZ, YELLOW, BLACK); //�������
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 15:
                al_index = 16;
                /*if (VCU_FaultCode == 151 || VCU_FaultCode == 221) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Wendu, YELLOW, BLACK); //�¶Ȳ��챨��
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Chayi, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1818D0F3.BMSFlag2.bit1) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DC, YELLOW, BLACK); //������¹���
                    LCD_DrawImageSBPP(x + 42, y + 8, 21, SWGG, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 16:
                al_index = 17;
                /*if (0) {
                    LCD_DrawImageSBPP(x, y + 8, 11, SOC, YELLOW, BLACK); //SOC�ͱ���
                    LCD_DrawImage1BPP(x + 11 + 11 + 11, y + 8, BMP_Di, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11 + 11 + 21, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 11 + 11 + 11 + 21 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1818D0F3.BMSFlag2.bit2) {
                    LCD_DrawImageSBPP(x, y + 8, 42, YWBJ, YELLOW, BLACK); //������
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 17:
                al_index = 18;
                /*if (VCU_FaultCode == 316) {
                    LCD_DrawImageSBPP(x, y + 8, 11, SOC, YELLOW, BLACK); //SOC�߱���
                    LCD_DrawImage1BPP(x + 11 + 11 + 11, y + 8, BMP_Gao, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11 + 11 + 21, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 11 + 11 + 11 + 21 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1818D0F3.BMSFlag2.bit3) {
                    LCD_DrawImageSBPP(x, y + 8, 42, JYBJ, YELLOW, BLACK); //��Ե����
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 18:
                al_index = 19;
                /*if (VCU_FaultCode == 313) {
                    LCD_DrawImageSBPP(x, y + 8, 11, SOC, YELLOW, BLACK); //SOC���챨��
                    LCD_DrawImage1BPP(x + 11 + 11 + 11, y + 8, BMP_Chayi, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11 + 11 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 11 + 11 + 11 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1818D0F3.BMSFlag2.bit4) {
                    LCD_DrawImageSBPP(x, y + 8, 21, CDDL, YELLOW, BLACK); //����������
                    LCD_DrawImageSBPP(x + 42 + 42, y + 8, 21, GD, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 19:
                al_index = 20;
                /*if (VCU_FaultCode == 220 || VCU_FaultCode == 150) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DC, YELLOW, BLACK); //��ص��±���
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Di, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 21, y + 8, BMP_Wendu, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1818D0F3.BMSFlag2.bit5) {
                    LCD_DrawImageSBPP(x, y + 8, 21, FDDL, YELLOW, BLACK); //�ŵ��������
                    LCD_DrawImageSBPP(x + 42 + 42, y + 8, 21, GD, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 20:
                al_index = 21;
                if (CAN_0x1818D0F3.BMSFlag3.bit6) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Charging, YELLOW, BLACK); //���ڳ�磬��ֹ�г�    
                    alarm_update_flag = 1;
                    break;
                }

            case 21:
                al_index = 22;
                /*if (BAT_COOL_FAULT) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DC, YELLOW, BLACK); //�����ȴϵͳ����
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Lengque, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_System, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1818D0F3.BMSFlag2.bit6) {
                    LCD_DrawImageSBPP(x, y + 8, 42, DCWD, YELLOW, BLACK); //����¶ȹ���
                    LCD_DrawImageSBPP(x + 42 + 42, y + 8, 21, GG, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 22:
                al_index = 23;
                /*if (VCU_FaultCode == 310 || VCU_FaultCode == 311 || VCU_FaultCode == 312) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Jiare, YELLOW, BLACK); //���ȹ���
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42, y, 150, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1818D0F3.BMSFlag2.bit8) {
                    LCD_DrawImageSBPP(x, y + 8, 21, WCGD, YELLOW, BLACK); //�²����
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 23:
                al_index = 24;
                /*if (Concentrated_Lubrication.bit5) {
                    LCD_DrawImageSBPP(x, y + 8, 42, JZRH, YELLOW, BLACK); //�����󻬱���
                    LCD_DrawImage1BPP(x + 84, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 84 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x181CD0F3.BMSFlag4.bit1) {
                    LCD_DrawImageSBPP(x, y + 8, 21, GYHS, YELLOW, BLACK); //��ѹ����
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 24:
                al_index = 25;
                /*if (VCU_FaultCode == 163 || VCU_FaultCode == 233) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Chong, YELLOW, BLACK); //��籨��
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42, y, 150, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x181CD0F3.BMSFlag4.bit2) {
                    LCD_DrawRect(x, y, 100, 36, BLACK);
                    LCD_DrawImageSBPP(x, y + 8, 21, SOCTB, YELLOW, BLACK); //SOC����
                    LCD_DrawRect(x + 63 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 25:
                al_index = 26;
                /*if (BMS_ChargeGun_Comm == 1) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Chong, YELLOW, BLACK); //���ͨѶ����
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Tongxin, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x181CD0F3.BMSFlag4.bit3 || CAN_0x181CD0F3.BMSFlag4.bit5) {
                    LCD_DrawImageSBPP(x, y + 8, 42, CNXTBJ, YELLOW, BLACK); //����ϵͳ����
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 26:
                al_index = 27;
                /*if (fKL8) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Yanwu, YELLOW, BLACK); //������
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42, y, 150, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x181CD0F3.BMSFlag4.bit4) {
                    LCD_DrawImageSBPP(x, y + 8, 21, DTYCBJ, YELLOW, BLACK); //����ѹ���
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 27:
                al_index = 28;
                /*if (BMS_Warn_Type == 1 || BMS_Warn_Type == 2 || BMS_Warn_Type == 3) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Dongli, YELLOW, BLACK); //������ع���
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_DC, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1801A79A.DCDC_FaultCode.bit6) {
                    LCD_DrawImageSBPP(x, y + 8, 21, DCDCDL, YELLOW, BLACK); //DCDC��·
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 28:
                al_index = 29;
                /*if (VCU_FaultCode == 168) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Zhilu, YELLOW, BLACK); //֧·��ѹ���챨��
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Chayi, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1801A79A.DCDC_FaultCode.bit5) {
                    LCD_DrawImageSBPP(x, y + 8, 21, DCDCGR, YELLOW, BLACK); //DCDC����
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 29:
                al_index = 30;
                /*if (BMS_FireWarnLevel == 1 || BMS_FireWarnLevel == 2) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DC, YELLOW, BLACK); //��ػ���Ԥ��
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Huozai, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Yujing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1801A79A.DCDC_FaultCode.bit1) {
                    LCD_DrawImageSBPP(x, y + 8, 21, DCDCSR, YELLOW, BLACK); //DCDC����Ƿѹ
                    LCD_DrawImageSBPP(x + 44 + 42, y + 8, 21, QY, YELLOW, BLACK); //
                    LCD_DrawRect(x + 44 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 30:
                al_index = 31;
                /*if (VCU_FaultCode == 314) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Chunnengxitong, YELLOW, BLACK); //����ϵͳ��ƥ��
                    LCD_DrawRect(x + 147, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1801A79A.DCDC_FaultCode.bit2) {
                    LCD_DrawImageSBPP(x, y + 8, 21, DCDCSR, YELLOW, BLACK); //DCDC�����ѹ
                    LCD_DrawImageSBPP(x + 44 + 42, y + 8, 21, GY, YELLOW, BLACK); //
                    LCD_DrawRect(x + 44 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 31:
                al_index = 32;
                /*if (VCU_FaultCode == 313) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_s, YELLOW, BLACK); //SOC����
                    LCD_DrawImage1BPP(x + 11, y + 8, BMP_o, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11, y + 8, BMP_c, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11 + 11, y + 8, BMP_Tiaobian, YELLOW, BLACK);
                    LCD_DrawRect(x + 11 + 11 + 11 + 42, y, 150, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1801A79A.DCDC_FaultCode.bit3) {
                    LCD_DrawImageSBPP(x, y + 8, 21, DCDCSC, YELLOW, BLACK); //DCDC���״̬
                    LCD_DrawImage1BPP(x + 44 + 42, y + 8, BMP_Zhuangtai, YELLOW, BLACK); //
                    LCD_DrawRect(x + 44 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 32:
                al_index = 33;
                /*if (BMS_FireWarnLevel == 1 || BMS_FireWarnLevel == 2) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DC, YELLOW, BLACK); //��ػ���Ԥ��
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Huozai, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Yujing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1801A79D.AIRDCAC_FaultCode.bit1) {
                    LCD_DrawImageSBPP(x, y + 8, 42, QBSR, YELLOW, BLACK); //��������Ƿѹ
                    LCD_DrawImageSBPP(x + 42 + 42, y + 8, 21, QY, YELLOW, BLACK); //
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 33:
                al_index = 34;
                if (rKL11 && SPEED > 5) {
                    LCD_DrawImageSBPP(x, y + 8, 21, HCMWG, YELLOW, BLACK); //�����δ��                   
                    LCD_DrawRect(x + 21 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 34:
                al_index = 35;
                /*if (!mKL12 && KT_SIGNAL) {
                    LCD_DrawImageSBPP(x, y + 8, 42, ZLBJ, YELLOW, BLACK); //��������
                    LCD_DrawRect(x + 42 + 42, y, 150, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1801A79D.AIRDCAC_FaultCode.bit2) {
                    LCD_DrawImageSBPP(x, y + 8, 42, QBSR, YELLOW, BLACK); //���������ѹ
                    LCD_DrawImageSBPP(x + 42 + 42, y + 8, 21, GY, YELLOW, BLACK); //
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 35:
                al_index = 36;
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
                    LCD_DrawRect(x, y, 200, 36, BLACK); //�����ʾ����
                    LCD_DrawImage1BPP(x, y + 8, BMP_Dijige, YELLOW, BLACK); //��x��������
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
                if (CAN_0x1801A79D.AIRDCAC_FaultCode.bit3) {
                    LCD_DrawImageSBPP(x, y + 8, 42, QBSSGL, YELLOW, BLACK); //���õ�ѹ��Դ
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Di, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 21, y + 8, BMP_Yali, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Dianyuan, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 36:
                al_index = 37;
                if (CAN_0x1801A79D.AIRDCAC_FaultCode.bit4) {
                    LCD_DrawImageSBPP(x, y + 8, 42, QBSSGL, YELLOW, BLACK); //����˲ʱ����
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 37:
                al_index = 38;
                /*if (BMS_FireFaultCode > 0) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DC, YELLOW, BLACK); //��ػ���Ԥ������
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Huozai, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Yujing, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1801A79D.AIRDCAC_FaultCode.bit5) {
                    LCD_DrawImageSBPP(x, y + 8, 42, QBGR, YELLOW, BLACK); //���ù���
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 38:
                al_index = 39;
                if (CAN_0x1801A79D.AIRDCAC_FaultCode.bit6) {
                    LCD_DrawImageSBPP(x, y + 8, 42, QBDL, YELLOW, BLACK); //���ö�·
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 39:
                al_index = 40;
                if (BAT24V_count == BAT24_TIME) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Xu, YELLOW, BLACK); //���ص�ѹ��
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_DC, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 42, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 42 + 42, y + 8, BMP_Di, YELLOW, BLACK);
                    LCD_DrawRect(x + 21 + 42 + 42 + 21, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 40:
                al_index = 41;
                if (CAN_0x1801A79D.AIRDCAC_FaultCode.bit7) {
                    LCD_DrawImageSBPP(x, y + 8, 42, QBGY, YELLOW, BLACK); //���ù���
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 41:
                al_index = 42;
                /*if (VCU_FaultCode >= 170 && VCU_FaultCode <= 179) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_v, YELLOW, BLACK); //VCUͨѶ����
                    LCD_DrawImage1BPP(x + 11, y + 8, BMP_c, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11, y + 8, BMP_u, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11 + 11, y + 8, BMP_Tongxin, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11 + 11 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 11 + 11 + 11 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1801A79D.AIRDCAC_FaultCode.bit8) {
                    LCD_DrawImageSBPP(x, y + 8, 42, QBQX, YELLOW, BLACK); //����ȱ��
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 42:
                al_index = 43;
                if (LED2 && SPEED > 5) {
                    LCD_DrawImageSBPP(x, y + 8, 21, ZMWG, YELLOW, BLACK); //����δ��                   
                    LCD_DrawRect(x + 42 + 42, y, 150, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 43:
                al_index = 44;
                if (LED1 && SPEED > 5) {
                    LCD_DrawImageSBPP(x, y + 8, 21, QMWG, YELLOW, BLACK); //ǰ��δ��                   
                    LCD_DrawRect(x + 42 + 42, y, 150, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 44:
                al_index = 45;
                /*if (OILDCAC_FaultCode) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Youbeng, YELLOW, BLACK); //�ͱ�ϵͳ����
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_System, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1801A79B.OILDCAC_FaultCode.bit1) {
                    LCD_DrawImageSBPP(x, y + 8, 42, YBSR, YELLOW, BLACK); //���������ѹ
                    LCD_DrawImageSBPP(x + 42 + 42, y + 8, 21, GY, YELLOW, BLACK); //
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 45:
                al_index = 46;
                /*if (AIRDCAC_FaultCode) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Qibeng, YELLOW, BLACK); //����ϵͳ����
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_System, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1801A79B.OILDCAC_FaultCode.bit2) {
                    LCD_DrawImageSBPP(x, y + 8, 42, YBSR, YELLOW, BLACK); //���������ѹ
                    LCD_DrawImageSBPP(x + 42 + 42, y + 8, 21, GY, YELLOW, BLACK); //
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 46:
                al_index = 47;
                /*if (VCU_Status3.bit8) {
                    LCD_DrawImageSBPP(x, y + 8, 21, CLYS, YELLOW, BLACK); //��������
                    LCD_DrawRect(x + 42 + 42, y, 150, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1801A79B.OILDCAC_FaultCode.bit3) {
                    LCD_DrawImageSBPP(x, y + 8, 42, YBSSGL, YELLOW, BLACK); //���õ�ѹ��Դ
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Di, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 21, y + 8, BMP_Yali, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Dianyuan, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 47:
                al_index = 48;
                /*if (DCDC_FaultCode) {
                    LCD_DrawImage1BPP(x, y + 8 - 2, BMP_DCDC, YELLOW, BLACK); //DCDCϵͳ����
                    LCD_DrawImage1BPP(x + 65, y + 8, BMP_System, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 65 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 65 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1801A79B.OILDCAC_FaultCode.bit4) {
                    LCD_DrawImageSBPP(x, y + 8, 42, YBSSGL, YELLOW, BLACK); //����˲ʱ����
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 48:
                al_index = 49;
                if (CAN_0x1801A79B.OILDCAC_FaultCode.bit5) {
                    LCD_DrawImageSBPP(x, y + 8, 42, YBGR, YELLOW, BLACK); //���ù���
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 49:
                al_index = 50;
                if (BAT24V_count == BAT24_TIME) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Xu, YELLOW, BLACK); //���ص�ѹ��
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_DC, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 42, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 42 + 42, y + 8, BMP_Di, YELLOW, BLACK);
                    LCD_DrawRect(x + 21 + 42 + 42 + 21, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 50:
                al_index = 51;
                if (CAN_0x1801A79B.OILDCAC_FaultCode.bit6) {
                    LCD_DrawImageSBPP(x, y + 8, 42, YBDL, YELLOW, BLACK); //���ö�·
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 51:
                al_index = 52;
                if (CAN_0x1801A79B.OILDCAC_FaultCode.bit7) {
                    LCD_DrawImageSBPP(x, y + 8, 42, YBGY, YELLOW, BLACK); //���ù���
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 52:
                al_index = 53;
                if (CAN_0x1801A79B.OILDCAC_FaultCode.bit8) {
                    LCD_DrawImageSBPP(x, y + 8, 42, YBQX, YELLOW, BLACK); //����ȱ��
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 53:
                al_index = 54;
                if (fKL8) {
                    LCD_DrawImageSBPP(x, y + 8, 21, QMWGFKBJ, YELLOW, BLACK); //ǰ���ⷧ�ǿ�����
                    LCD_DrawRect(x + 21 * 8, y, 50, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 54:
                al_index = 55;
                if (fKL10) {
                    LCD_DrawImageSBPP(x, y + 8, 21, QMYJFBJ, YELLOW, BLACK); //ǰ��Ӧ��������
                    LCD_DrawRect(x + 21 * 7, y, 50, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 55:
                al_index = 56;
                if (mKL4) {
                    LCD_DrawImageSBPP(x, y + 8, 21, NYJFGKBJ, YELLOW, BLACK); //��Ӧ�����ǿ�����
                    LCD_DrawRect(x + 21 * 8, y, 50, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 56:
                al_index = 57;
                if (mKL6) {
                    LCD_DrawImageSBPP(x, y + 8, 21, QMCNYJFBJ, YELLOW, BLACK); //ǰ�ų���Ӧ��������
                    LCD_DrawRect(x + 21 * 9, y, 50, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 57:
                al_index = 58;
                if (mKL8) {
                    LCD_DrawImageSBPP(x, y + 8, 21, HMCNYJFBJ, YELLOW, BLACK); //���ų���Ӧ��������
                    LCD_DrawRect(x + 21 * 9, y, 50, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 58:
                al_index = 59;
                if (rKL7) {
                    LCD_DrawImageSBPP(x, y + 8, 21, HMWYJFGKBJ, YELLOW, BLACK); //������Ӧ�����ǿ�����
                    //LCD_DrawRect(x + 21 * 10, y, 50, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 59:
                al_index = 60;
                if (rKL9) {
                    LCD_DrawImageSBPP(x, y + 8, 21, HMWYJFBJ, YELLOW, BLACK); //������Ӧ��������
                    LCD_DrawRect(x + 21 * 8, y, 50, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            default:
                al_index = 0;
                LCD_DrawRect(x, y, 250, 36, BLACK); //�����ʾ����
                break;
        }
    }

}
#endif

void updata_Dangwei(unsigned int x, unsigned int y) {//0 : N;  1��D;  2 :R;  3��P
    unsigned char gear = 0;
    if (CAN_0x0CF101A7.Gear == 4) gear = 0;
    else if (CAN_0x0CF101A7.Gear == 1) gear = 1;
    else if (CAN_0x0CF101A7.Gear == 2) gear = 2;
    else if (CAN_0x0CF101A7.Gear == 8) gear = 3;
    else gear = 0;
    LCD_DrawImage1BPP(x, y, BMP_DANGWEI[gear], GREEN, BLACK); //��λ���� 
}

void updata_SOC(unsigned int x, unsigned int y) {
    unsigned char color = WHITE;
    static unsigned char soc = 100;
    soc = CAN_0x18F13DF3.SOC * 0.4;
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

void updata_DCDY(unsigned int x, unsigned int y, float factor) {
    //unsigned char color = GREEN;
    unsigned int DCDY = 50;
    DCDY = 0 * factor;
    if (DCDY >= 800)
        DCDY = 800;
    print_SZ_1(x, y, DCDY, 3, 0, WHITE); //��ص�ѹ��ֵ x=120+72+30   y=150+60-2
    if (frmID == 0)
        LCD_DrawRect(x - 358, y + 2, DCDY * 3.31 * 0.125, 28, GREEN); // 331/100  
    if (DCDY < 800 && frmID == 0)//��Ϊ100ʱ�����
        LCD_DrawRect((x - 358 + DCDY * 3.31 * 0.125), y + 2, (331 - DCDY * 3.31 * 0.125), 28, BLACK);
}

void updata_DCDL(unsigned int x, unsigned int y, float factor, unsigned int offset) {
    unsigned int DCDL = 100;
    DCDL = 0 * factor;
    if (DCDL < offset) {
        DCDL = offset - DCDL;
        if (DCDL > 500) DCDL = 500;
        print_SZ_1(x, y, DCDL, 3, 0, WHITE);
        LCD_DrawImage1BPPZOOM_4(x - 20, y + 4, BMP_ASIC_11x20[45 - 32], WHITE, BLACK);
        if (DCDL > 0 && frmID == 0)
            LCD_DrawRect((225 + 2 + 164 - DCDL * 1.64 * 0.2), 150 + 5 + 2 + 60, (DCDL * 1.64 * 0.2 + 1), 28, GREEN);
        if (DCDL < 500 && frmID == 0) {
            LCD_DrawRect(225 + 2, 150 + 5 + 2 + 60, (164 - DCDL * 1.64 * 0.2), 28, BLACK); // 165/100         
            LCD_DrawRect(225 + 83 + 83 + 2, 150 + 5 + 2 + 60, 165, 28, BLACK);
        }
    } else {
        DCDL = DCDL - offset;
        if (DCDL > 500) DCDL = 500;
        LCD_DrawImage1BPPZOOM_4(x - 20, y + 4, BMP_ASIC_11x20[43 - 32], WHITE, BLACK);
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
        LCD_DrawImage1BPP_11x20(x - 16, y + 5, BMP_ASIC_11x20[45 - 32], color1, BLACK);
    } else {
        LCD_DrawImage1BPP_11x20(x - 16, y + 5, BMP_ASIC_11x20[43 - 32], BLACK, BLACK);
        print_SZ_1(x, y, DAT - offset, sum, dot, color1); //��ص�����ֵ x=135+180+50+100+20+20   y=150+60-2
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

#if DrawBus
    LCD_DrawRect(0, 430 + 15, 800, 2, GREEN); //�ײ����� 

    BMP_BUS(150, 150 + 40); //��BUS

    LCD_DrawImage1BPP(170, 145, BMP_SOC, WHITE, BLACK); //SOC

    disp_rectange(225, 150 + 5 - 10, 335, 2, 32, 2, WHITE);
    for (i = 0; i < 3; i++)
        LCD_DrawRect(225 + 83 + 83 * i, 145 - 10, 2, 10, WHITE);

    LCD_DrawImage1BPP(225 - 4, 155 - 14 - 10, BMP_SZ[0], WHITE, BLACK); //0

    print_SZ(225 + 83 + 83 + 83 + 84 - 12, 155 - 14 - 10, 100, 3, 0, WHITE); //100
    LCD_DrawImage1BPP(650, 145, BMP_BAIFENHAO, WHITE, BLACK);

    LCD_DrawImageString_21x20(10, 365 + 15 - 50 + 10, lc, YELLOW, BLACK); //���
    LCD_DrawImageString_21x20(125, 318 + 15 + 38 + 8, string_km, WHITE, BLACK); //��λ Km
    LCD_DrawImageString_21x20(125, 318 + 15 + 38 * 2 + 8, string_km, WHITE, BLACK); //��λ Km

    LCD_DrawImageString_21x20(165, 365 + 15 - 50 + 10, gydc, YELLOW, BLACK); //��ѹ���
    LCD_DrawImage1BPP_11x20(265, 318 + 15 + 38 + 8, BMP_ASIC_11x20[86 - 32], WHITE, BLACK); //V
    LCD_DrawImage1BPP_11x20(265, 318 + 15 + 38 * 2 + 8, BMP_ASIC_11x20[65 - 32], WHITE, BLACK); //A

    LCD_DrawImageString_21x20(295, 365 + 15 - 50 + 10, dtdy, YELLOW, BLACK); //�����ѹ
    LCD_DrawImage1BPP_11x20(395, 318 + 15 + 38 + 8, BMP_ASIC_11x20[86 - 32], WHITE, BLACK); //V
    LCD_DrawImage1BPP_11x20(395, 318 + 15 + 38 * 2 + 8, BMP_ASIC_11x20[86 - 32], WHITE, BLACK); //V

    LCD_DrawImageString_21x20(420, 365 + 15 - 50 + 10, dtwd, YELLOW, BLACK); //�����¶�
    LCD_DrawImage1BPP(420 + 90, 318 + 15 + 10 + 38, BMP_T, WHITE, BLACK); //��
    LCD_DrawImage1BPP(420 + 90, 318 + 15 + 10 + 38 * 2, BMP_T, WHITE, BLACK); //��

    LCD_DrawImageString_21x20(540, 365 + 15 - 50 + 10, dj_kzq, YELLOW, BLACK); //���/������
    LCD_DrawImage1BPP(640, 365 + 15 - 50 + 10 + 38, BMP_T, WHITE, BLACK); //��
    LCD_DrawImage1BPP(640, 365 + 15 - 50 + 10 + 38 * 2, BMP_T, WHITE, BLACK); //��

    LCD_DrawImageString_21x20(670, 365 + 15 - 50 + 10, zs_dtc, YELLOW, BLACK); //ת��/DTC
    LCD_DrawImageString_21x20(670 + 100 - 16, 365 + 15 - 50 + 10 + 38, string_rpm, WHITE, BLACK); //Rpm

    //LCD_DrawImageString_21x20(670, 365 + 15 - 50 + 10 + 38 * 2, string_rpm, WHITE, BLACK); //Rpm

    disp_rectange(5, 365 + 15 - 50, 150, 1, 115, 1, GREEN);
    disp_rectange(5 + 140 + 15, 365 + 15 - 50, 125, 1, 115, 1, GREEN);
    disp_rectange(5 + 270 + 15, 365 + 15 - 50, 125 - 5, 1, 115, 1, GREEN);
    disp_rectange(5 + 400 + 10, 365 + 15 - 50, 125 - 5, 1, 115, 1, GREEN);
    disp_rectange(5 + 530 + 5, 365 + 15 - 50, 125, 1, 115, 1, GREEN);
    disp_rectange(5 + 660 + 5, 365 + 15 - 50, 130 - 5, 1, 115, 1, GREEN);

#elif MODE_FV
    //������ص��� ��ѹ SOC ���
    LCD_DrawRect(0, 430 + 10 + 2, 800, 2, GREEN); //�ײ����� 

    LCD_DrawImage1BPP(175, 160 + 13 - 5 - 10, BMP_Voltage, WHITE, BLACK); //��ѹ
    disp_rectange(225, 150 + 5 + 13 - 5 - 10, 335, 2, 32, 2, WHITE);
    LCD_DrawRect(225 + 83, 145 + 13 - 5 - 10, 2, 10, WHITE);
    LCD_DrawRect(225 + 83 + 83, 145 + 13 - 5 - 10, 2, 10, WHITE);
    LCD_DrawRect(225 + 83 + 83 + 83, 145 + 13 - 5 - 10, 2, 10, WHITE);

    LCD_DrawImage1BPP(225 - 4, 155 - 14 + 13 - 5 - 10, BMP_SZ[0], WHITE, BLACK); //0
    print_SZ(225 + 83 + 83 + 83 + 84 - 12, 155 - 14 + 13 - 5 - 10, 800, 3, 0 WHITE); //8
    //LCD_DrawImage1BPP(225 + 83 + 83 + 83 + 84 - 4, 155 - 14 + 13 - 5 - 10, BMP_SZ[0], WHITE, BLACK); //0
    //LCD_DrawImage1BPP(225 + 83 + 83 + 83 + 84 + 4, 155 - 14 + 13 - 5 - 10, BMP_SZ[0], WHITE, BLACK); //0   
    LCD_DrawImage1BPP(660, 155 + 13 - 5 - 10, BMP_V, WHITE, BLACK);

    LCD_DrawImage1BPP(170, 150 + 5 + 60 + 13 - 5 - 10, BMP_SOC, WHITE, BLACK); //SOC
    disp_rectange(225, 150 + 5 + 60 + 13 - 5 - 10, 335, 2, 32, 2, WHITE);
    LCD_DrawRect(225 + 83, 145 + 60 + 13 - 5 - 10, 2, 10, WHITE);
    LCD_DrawRect(225 + 83 + 83, 145 + 60 + 13 - 5 - 10, 2, 10, WHITE);
    LCD_DrawRect(225 + 83 + 83 + 83, 145 + 60 + 13 - 5 - 10, 2, 10, WHITE);
    LCD_DrawImage1BPP(225 - 4, 155 - 14 + 60 + 13 - 5 - 10, BMP_SZ[0], WHITE, BLACK); //0
    print_SZ(225 + 83 + 83 + 83 + 84 - 12, 155 - 14 + 60 + 13 - 5 - 10, 100, 3, 0, WHITE); //1
    //LCD_DrawImage1BPP(225 + 83 + 83 + 83 + 84 - 4, 155 - 14 + 60 + 13 - 5 - 10, BMP_SZ[0], WHITE, BLACK); //0
    //LCD_DrawImage1BPP(225 + 83 + 83 + 83 + 84 + 4, 155 - 14 + 60 + 13 - 5 - 10, BMP_SZ[0], WHITE, BLACK); //0
    LCD_DrawImage1BPP(660, 155 + 60 + 13 - 5 - 10, BMP_BAIFENHAO, WHITE, BLACK);

    LCD_DrawImageString_21x20(180 - 20 + 2, 260 + 8, ZGDY, WHITE, BLACK); //��ߵ�ѹ
    LCD_DrawImage1BPP(225 + 83 + 83 - 22, 260 + 8, BMP_v, WHITE, BLACK); //V

    LCD_DrawImageString_21x20(180 - 20 + 2, 260 + 8 + 36, zddy, WHITE, BLACK); //��͵�ѹ
    LCD_DrawImage1BPP(225 + 83 + 83 - 22, 260 + 8 + 36, BMP_v, WHITE, BLACK); //��

    LCD_DrawImageString_21x20(225 + 83 + 83 + 2, 260 + 8, dcdl, WHITE, BLACK); //��ص���
    LCD_DrawImage1BPP(615 - 22, 260 + 8, BMP_a, WHITE, BLACK); //A

    LCD_DrawImageString_21x20(225 + 83 + 83 + 2, 260 + 8 + 36, zgwd, WHITE, BLACK); //����¶�
    LCD_DrawImage1BPP(615 - 22, 260 + 8 + 36, BMP_T, WHITE, BLACK); //V

    LCD_DrawImageString_21x20(180 - 20 + 2, 260 + 8 + 36 * 2, djkzq, WHITE, BLACK); //���
    LCD_DrawImage1BPP(225 + 83 + 83 - 22, 260 + 8 + 36 * 2, BMP_T, WHITE, BLACK); //��

    LCD_DrawImageString_21x20(225 + 83 + 83 + 2, 260 + 8 + 36 * 2, djzs, WHITE, BLACK); //���ת��
    //LCD_DrawImage1BPP(615 - 22, 260 + 8 + 36 * 2, BMP_v, WHITE, BLACK); //V
    LCD_DrawImage1BPP(615 - 34, 260 + 8 + 36 * 2, BMP_RPM, WHITE, BLACK); //RPM

    LCD_DrawImageString_21x20(180 - 20 + 2, 260 + 8 + 36 * 3, djwd, WHITE, BLACK); //����¶�
    LCD_DrawImage1BPP(225 + 83 + 83 - 22, 260 + 8 + 36 * 3, BMP_T, WHITE, BLACK); //��

    //LCD_DrawImageSBPP(225 + 83 + 83 + 2, 260 + 8 + 36 * 3, 63, FDJQH, WHITE, BLACK);
    LCD_DrawImageSBPP(615 - 34, 260 + 8 + 36 * 3, 11, CHAR_LH, WHITE, BLACK); //LH


    LCD_DrawRect(180 - 20, 260, 1, 180 + 2, WHITE);
    LCD_DrawRect(225 + 83 + 83, 260, 1, 180 - 36 + 2, WHITE);
    LCD_DrawRect(615, 260, 1, 180 + 2, WHITE);
    for (i = 0; i < 5; i++) {
        LCD_DrawRect(180 - 20, 260 + 36 * i, 350 + 85 + 20, 1, WHITE);
    }

    //��ѹ��1���
    LCD_DrawRect(33, 100 + 13 - 5 - 10, 51, 3, WHITE); //
    LCD_DrawRect(33, 100 + 13 - 5 - 10, 3, 135, WHITE);
    LCD_DrawRect(84, 100 + 13 - 5 - 10, 3, 135, WHITE);

    LCD_DrawRect(33, 235 + 13 - 5 - 10, 3, 135, RED);
    LCD_DrawRect(84, 235 + 13 - 5 - 10, 3, 138, RED);
    LCD_DrawRect(33, 370 + 13 - 5 - 10, 51, 3, RED); //

    //���
    LCD_DrawImage1BPP(13 - 5, 95 + 13 - 5 - 10, BMP_SZ_2[1], RED, BLACK); //1
    LCD_DrawImage1BPP(21 - 5, 95 + 13 - 5 - 10, BMP_SZ_2[0], RED, BLACK); //0
    LCD_DrawImage1BPP(21 - 5, 225 + 13 - 5 - 10, BMP_SZ_2[5], RED, BLACK); //5
    LCD_DrawImage1BPP(21 - 5, 360 + 13 - 5 - 10, BMP_SZ_2[0], RED, BLACK); //0

    LCD_DrawImageSBPP(33 - 7 + 32 + 16, 410 + 13 - 5, 11, CHAR_MPA, WHITE, BLACK); //Mpa

    //��ѹ��2���
    LCD_DrawRect(712, 100 + 13 - 5 - 10, 51, 3, WHITE);
    LCD_DrawRect(712, 100 + 13 - 5 - 10, 3, 135, WHITE);
    LCD_DrawRect(712 + 51, 100 + 13 - 5 - 10, 3, 135, WHITE);

    LCD_DrawRect(712, 235 + 13 - 5 - 10, 3, 135, RED);
    LCD_DrawRect(712 + 51, 235 + 13 - 5 - 10, 3, 138, RED);
    LCD_DrawRect(712, 370 + 13 - 5 - 10, 51, 3, RED); //

    LCD_DrawImage1BPP(770, 95 + 13 - 5 - 10, BMP_SZ_2[1], RED, BLACK); //1
    LCD_DrawImage1BPP(770 + 8, 95 + 13 - 5 - 10, BMP_SZ_2[0], RED, BLACK); //0
    LCD_DrawImage1BPP(770, 225 + 13 - 5 - 10, BMP_SZ_2[5], RED, BLACK); //5
    LCD_DrawImage1BPP(770, 360 + 13 - 5 - 10, BMP_SZ_2[0], RED, BLACK); //0 

    LCD_DrawImageSBPP(712 - 7 + 32 + 16, 410 + 13 - 5, 11, CHAR_MPA, WHITE, BLACK); //Mpa

    /*--------------------------------------------
    ������ʾ�ĸ�ʽΪ:(ODO 000.0Km       00:00          TRIP0000000Km)
    ---------------------------------------------*/
    LCD_DrawImage1BPP(2, 440 + 3 + 13 - 5, Bmp_ODO, YELLOW, BLACK); //�ۼ���� ODO  

    LCD_DrawImage1BPP(210 - 16, 440 + 10, BMP_HZ_KM, WHITE, BLACK); //��λ Km

    LCD_DrawImage1BPP(240 + 300 + 30, 440 + 3 + 13 - 5, Bmp_TRIP, YELLOW, BLACK); //������� TRIF

    LCD_DrawImage1BPP(404 + 336 + 30, 440 + 10, BMP_HZ_KM, WHITE, BLACK); //��λ Km

#elif MODE_EV
    LCD_DrawRect(0, 430 + 8, 800, 1, GREEN); //�ײ�����
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
    print_SZ(225 + 83 + 83 + 83 + 84 - 12, 155 - 14, 800, 3, 0, WHITE); //800
    //LCD_DrawImage1BPP(225 + 83 + 83 + 83 + 84 - 4, 155 - 14, BMP_SZ[0], WHITE, BLACK); //0
    //LCD_DrawImage1BPP(225 + 83 + 83 + 83 + 84 + 4, 155 - 14, BMP_SZ[0], WHITE, BLACK); //0   
    LCD_DrawImage1BPP(660, 155, BMP_V, WHITE, BLACK);

    LCD_DrawImage1BPP(175, 160 + 60, BMP_Current, WHITE, BLACK); //����
    LCD_DrawRect(225, 150 + 5 + 60, 335, 2, WHITE);
    LCD_DrawRect(225, 150 + 35 + 60, 335, 2, WHITE);
    LCD_DrawRect(225, 155 + 60, 2, 32, WHITE);
    LCD_DrawRect(225 + 83, 145 + 60, 2, 10, WHITE);
    LCD_DrawRect(225 + 83 + 83 + 83, 145 + 60, 2, 10, WHITE);
    LCD_DrawRect(225 + 83 + 83 + 83 + 83 + 1, 155 + 60, 2, 32, WHITE);
    LCD_DrawRect(225 - 12, 155 - 14 + 60 + 7, 8, 2, WHITE); //-
    print_SZ(225 - 4, 155 - 14 + 60, 500, 3, 0, WHITE); //5
    //LCD_DrawImage1BPP(225 + 4, 155 - 14 + 60, BMP_SZ[0], WHITE, BLACK); //0
    //LCD_DrawImage1BPP(225 + 12, 155 - 14 + 60, BMP_SZ[0], WHITE, BLACK); //0

    LCD_DrawImage1BPP(225 + 83 + 83 - 4, 145 + 60 - 4, BMP_SZ[0], WHITE, BLACK); //0
    LCD_DrawRect(225 + 83 + 83, 155 + 60, 2, 32, WHITE);

    print_SZ(225 + 83 + 83 + 83 + 84 - 12, 155 - 14 + 60, 500, 3, 0, WHITE); //5
    //LCD_DrawImage1BPP(225 + 83 + 83 + 83 + 84 - 4, 155 - 14 + 60, BMP_SZ[0], WHITE, BLACK); //0
    //LCD_DrawImage1BPP(225 + 83 + 83 + 83 + 84 + 4, 155 - 14 + 60, BMP_SZ[0], WHITE, BLACK); //0
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
    print_SZ(225 + 83 + 83 + 83 + 84 - 12, 155 - 14 + 60 + 60, 100, 3, 0, WHITE); //1
    //LCD_DrawImage1BPP(225 + 83 + 83 + 83 + 84 - 4, 155 - 14 + 60 + 60, BMP_SZ[0], WHITE, BLACK); //0
    //LCD_DrawImage1BPP(225 + 83 + 83 + 83 + 84 + 4, 155 - 14 + 60 + 60, BMP_SZ[0], WHITE, BLACK); //0
    LCD_DrawImage1BPP(660, 155 + 60 + 60, BMP_BAIFENHAO, WHITE, BLACK);

    LCD_DrawImageString_21x20(60, 365 - 50 + 10 + 8, dtdy, WHITE, BLACK); //�����ѹ
    LCD_DrawImage1BPP_11x20(15 + 130, 318 + 38 + 8 + 8, BMP_ASIC_11x20[86 - 32], WHITE, BLACK); //V
    LCD_DrawImage1BPP_11x20(15 + 130, 318 + 38 * 2 + 8 + 8, BMP_ASIC_11x20[86 - 32], WHITE, BLACK); //V

    LCD_DrawImageString_21x20(70 + 550, 365 - 50 + 10 + 8, dtwd, WHITE, BLACK); //�����¶�
    LCD_DrawImage1BPP(800 - 90, 318 + 10 + 8 + 38, BMP_T, WHITE, BLACK); //��
    LCD_DrawImage1BPP(800 - 90, 318 + 10 + 8 + 38 * 2, BMP_T, WHITE, BLACK); //��

    LCD_DrawImageString_21x20(180 - 20 + 2, 365 - 50 + 10 + 8, djkzq, WHITE, BLACK); //���������
    LCD_DrawImage1BPP(225 + 83 + 83 - 22, 365 - 50 + 10 + 8, BMP_T, WHITE, BLACK); //��

    LCD_DrawImageString_21x20(225 + 83 + 83 + 2, 365 - 50 + 10 + 8, djzs, WHITE, BLACK); //���ת��
    LCD_DrawImageString_21x20(615 - 34, 365 - 50 + 10 + 8, char_rpm, WHITE, BLACK); //RPM

    LCD_DrawImageString_21x20(225 + 83 + 83 + 2, 365 - 50 + 10 + 8 + 38, xdcdy, WHITE, BLACK); //���ת��
    LCD_DrawImage1BPP_11x20(615 - 22, 365 - 50 + 10 + 8 + 38, BMP_ASIC_11x20[86 - 32], WHITE, BLACK); //V


    LCD_DrawImageString_21x20(180 - 20 + 2, 365 - 50 + 10 + 8 + 38, djwd, WHITE, BLACK); //����¶�
    LCD_DrawImage1BPP(225 + 83 + 83 - 22, 365 - 50 + 10 + 8 + 38, BMP_T, WHITE, BLACK); //��

    //���
    LCD_DrawRect(55, 365 - 50 + 8, 680, 1, GREEN);
    LCD_DrawRect(55, 365 - 50 + 8, 1, 65 + 50, GREEN);
    LCD_DrawRect(735, 365 - 50 + 8, 1, 65 + 50, GREEN);
    LCD_DrawRect(180 - 20, 365 - 50 + 8, 350 + 85 + 20, 1, GREEN);
    LCD_DrawRect(180 - 20, 365 - 50 + 8, 1, 65 + 50, GREEN);
    LCD_DrawRect(225 + 83 + 83, 365 - 50 + 8, 1, 65 + 50 - 38, GREEN);
    LCD_DrawRect(615, 365 - 50 + 8, 1, 65 + 50, GREEN);
    LCD_DrawRect(180 - 20, 365 - 50 + 8 + 38, 350 + 85 + 20, 1, GREEN);
    LCD_DrawRect(180 - 20, 365 - 50 + 8 + 38 + 38, 350 + 85 + 20, 1, GREEN);

    /*--------------------------------------------
    ������ʾ�ĸ�ʽΪ:(ODO 000.0Km       00:00          TRIP0000000Km)
    ---------------------------------------------*/
    LCD_DrawImage1BPP(2, 440 + 3 + 13 - 5, Bmp_ODO, YELLOW, BLACK); //�ۼ���� ODO  

    LCD_DrawImage1BPP(210 - 16, 440 + 10, BMP_HZ_KM, WHITE, BLACK); //��λ Km

    LCD_DrawImage1BPP(240 + 300 + 30, 440 + 3 + 13 - 5, Bmp_TRIP, YELLOW, BLACK); //������� TRIF

    LCD_DrawImage1BPP(404 + 336 + 30, 440 + 10, BMP_HZ_KM, WHITE, BLACK); //��λ Km
#endif

}

void frmMain(void) {
#if DrawBus
    if (f_index == 0) { //ֻ����һ��
        f_index = 1;
        mainFrame();
    } else if (f_index == 1) {
        f_index = 2;
        updata_DAT(700 - 12, 318 + 15 + 38, CAN_0x18F120F0.MotorSpeed, 1, 12000, WHITE, 4, 0); //���ת��
        if (CAN_0x0CF1064A.VCU_DTC == 0)
            print_SZ_1(700 - 8, 318 + 15 + 38 * 2, CAN_0x0CF1064A.VCU_DTC, 6, 0, WHITE); //���ϴ���
        else
            print_SZ_1(700 - 8, 318 + 15 + 38 * 2, CAN_0x0CF1064A.VCU_DTC, 6, 0, RED); //���ϴ���
    } else if (f_index == 2) {
        f_index = 3;
        disp_BMP_baojing();
        print_SZ_1(305 + 8, 318 + 15 + 38, CAN_0x18F13EF3.BMS_MAX_Cell_Voltage, 3, 2, WHITE); //����ߵ�ѹ
        print_SZ_1(305 + 8, 318 + 15 + 38 * 2, CAN_0x18F13EF3.BMS_MIN_Cell_Voltage, 3, 2, WHITE); //����͵�ѹ
    } else if (f_index == 3) {
        f_index = 4;
        disp_miles();
        //�ſ���ͼ�񱨾�
        if (LED2) {
            BMP_Men_Kai(150 + 195, 190 + 27, RED); //��2��
        } else
            BMP_Men_Guan(150 + 195, 190 + 27, WHITE); //��2��
        if (LED1)
            BMP_Men_Kai(150 + 184 + 215, 190 + 27, RED); //��1��
        else
            BMP_Men_Guan(150 + 184 + 215, 190 + 27, WHITE); //��1��        
    } else if (f_index == 4) {
        f_index = 5;
        disp_time(360 - 15, 440 + 8, timer);
        updata_DAT(540 + 50, 318 + 15 + 38 * 2, CAN_0x18F120F0.MotorCtrlTemp, 1, 40, WHITE, 3, 0); //����������¶�
        updata_DAT(540 + 50, 318 + 15 + 38, CAN_0x18F120F0.MotorTemp, 1, 40, WHITE, 3, 0); //����¶�
    } else if (f_index == 5) {
        f_index = 6;
        updata_SOC(585, 155 - 10);
        updata_DAT(150 + 45, 318 + 15 + 38, CAN_0x18F13DF3.Voltage, 0.1, 0, WHITE, 4, 0); //�ܵ�ѹ
        updata_DAT(150 + 45, 318 + 15 + 38 * 2, CAN_0x18F13DF3.Current, 0.1, 1000, WHITE, 4, 0); //�ܵ���
        //updata_DCDL(150 + 45 + 16, 318 + 15 + 38 * 2); //�ܵ���
    } else if (f_index == 6) {
        f_index = 7;
        updata_DAT(410 + 50, 318 + 15 + 38, CAN_0x18F13EF3.BMS_MAX_Temp, 1, 40, WHITE, 3, 0); //�������
        updata_DAT(410 + 50, 318 + 15 + 38 * 2, CAN_0x18F13EF3.BMS_MIN_Temp, 1, 40, WHITE, 3, 0); //�������       
        disp_FONT_baojingNew(2, 447);
    } else if (f_index == 7) {
        f_index = 1;
        updata_Dangwei(138 + 17 + 66 * 4, 74 - 5);
    } else {
        f_index = 0;
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
#if VIDEO
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

                //��������ѡ��ʹ�ܰ���
                /*if ((VCU_Gear == 1) && !R_flag) {//����
                    key_AV = 1; //ģ��AV���ذ�һ��
                    AV_CH = 0; //0+1=1  ����
                    R_flag = 1; //��ֹһֱ�����������������key_AV������1
                }
                if ((VCU_Gear != 1) && R_flag) {
                    key_AV = 1;
                    AV_CH = 4; // 0 ����MCU����
                    R_flag = 0;
                    M_flag = 0;
                }*/

                //����ѡ��ʹ�ܰ��� ���ȼ�С�ڵ���
                /*if (VCU_Gear != 1) {
                    if (IN3 && !M_flag) {//���ſ�
                        key_AV = 1; //ģ��AV���ذ�һ��
                        AV_CH = 1; //1+1=2  AV1
                        M_flag = 1; //��ֹһֱ�����������������key_AV������1
                    }
                    if (!IN3 && M_flag) {
                        key_AV = 1;
                        AV_CH = 4; // 0 ����MCU����
                        M_flag = 0;
                        R_flag = 0;
                    }
                }*/
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
#endif
    }

#elif MODE_FV
    if (f_index == 0) { //ֻ����һ��
        f_index = 1;
        mainFrame();
    } else if (f_index == 1) {
        f_index = 2;
        //updata_DAT(480 + 30, 318 + 13 - 5, MCU_NM, 0.25, 8192, WHITE, 4, 0); //���ת��
        //updata_DCDL(585, 155 + 13 - 5 + 60);
        updata_DAT(480 + 40 - 10, 260 + 2 + 36 * 0, 0, 8, 1000, WHITE, 4, 0); //��ص���
        //print_SZ_1(480 + 40, 260 + 3 + 36 * 2, 0, 3, 0, WHITE); //���ݵ�ѹ   
        updata_DAT(480 + 40 - 10, 260 + 3 + 36 * 2, 0, 20, 2000, WHITE, 4, 0); //���ת�� 
    } else if (f_index == 2) {
        f_index = 3;
        disp_BMP_baojing();
        print_SZ_1(313 - 16 * 2, 260 + 2, 0 * 1.5, 4, 3, WHITE); //����ߵ�ѹ
        print_SZ_1(313 - 16 * 2, 260 + 2 + 36 * 1, 0 * 1.5, 4, 3, WHITE); //����͵�ѹ
    } else if (f_index == 3) {
        f_index = 4;
        disp_miles();
        updata_DCDY(585, 155 + 13 - 5 - 10);
    } else if (f_index == 4) {
        f_index = 5;
        disp_time(330, 440 + 13, timer);
        updata_DAT(313, 260 + 2 + 36 * 2, 0, 1, 40, WHITE, 3, 0); //����������¶�
        updata_DAT(313, 260 + 2 + 36 * 3, 0, 1, 40, WHITE, 3, 0); //����¶�
    } else if (f_index == 5) {
        f_index = 6;
        updata_SOC(585, 155 + 13 + 60 - 5 - 10);
        updata_QY();
    } else if (f_index == 6) {
        f_index = 7;
        updata_DAT(480 + 40 + 6, 260 + 2 + 36 * 1, 0, 0.2, 50, WHITE, 3, 0); //�������       
        disp_FONT_baojingNew(162, 260 + 1 + 36 * 4);
    } else if (f_index == 7) {
        f_index = 1;
        updata_Dangwei(138 + 17 + 66 * 4, 74 - 5);
        print_SZ_1(480 + 40 - 10, 260 + 3 + 36 * 3, 0 * 0.05, 4, 0, WHITE);
        //print_H(480 + 30 -16, 318+15 + 38*2, tcu_spn, 5, 0, WHITE); //spn
        //print_SZ_1(480 + 30 + 16, 318 + 38, TCU_code, 3, 0, color); //ϵͳ����
    } else {
        f_index = 0;
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
#if VIDEO
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

                //��������ѡ��ʹ�ܰ���
                /*if ((VCU_Gear == 1) && !R_flag) {//����
                    key_AV = 1; //ģ��AV���ذ�һ��
                    AV_CH = 0; //0+1=1  ����
                    R_flag = 1; //��ֹһֱ�����������������key_AV������1
                }
                if ((VCU_Gear != 1) && R_flag) {
                    key_AV = 1;
                    AV_CH = 4; // 0 ����MCU����
                    R_flag = 0;
                    M_flag = 0;
                }*/

                //����ѡ��ʹ�ܰ��� ���ȼ�С�ڵ���
                /*if (VCU_Gear != 1) {
                    if (IN3 && !M_flag) {//���ſ�
                        key_AV = 1; //ģ��AV���ذ�һ��
                        AV_CH = 1; //1+1=2  AV1
                        M_flag = 1; //��ֹһֱ�����������������key_AV������1
                    }
                    if (!IN3 && M_flag) {
                        key_AV = 1;
                        AV_CH = 4; // 0 ����MCU����
                        M_flag = 0;
                        R_flag = 0;
                    }
                }*/
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
#endif
    }

#elif (MODE_EV && !DrawBus)
    if (f_index == 0) { //ֻ����һ��
        f_index = 1;
        mainFrame();
    } else if (f_index == 1) {
        f_index = 2;
        print_SZ_1(60, 318 + 8 + 38, CAN_0x18F81A9E.BMS_MAX_Cell_Voltage, 4, 3, WHITE); //�����
        print_SZ_1(60, 318 + 8 + 38 * 2, CAN_0x18F81A9E.BMS_MIN_Cell_Voltage, 4, 3, WHITE); //�����
        updata_DAT(313, 318 + 8 + 38, CAN_0x08029F80.DriveMotorTemp, 1, 40, WHITE, 3, 0); //����¶�
    } else if (f_index == 2) {
        f_index = 3;
        disp_BMP_baojing();
        updata_DAT(480 + 30, 318 + 8, CAN_0x08019F80.VCU_MotorSpeed, 1, 8000, WHITE, 4, 0); //���ת��
        print_SZ_1(480 + 30, 318 + 8 + 38, ADV[0], 3, 1, WHITE); //���ص�ѹ
    } else if (f_index == 3) {
        f_index = 4;
        disp_miles();
        updata_DCDL(585, 155 + 60, 0.05, 1600);
    } else if (f_index == 4) {
        f_index = 5;
        disp_time(330, 440 + 5, timer);
        updata_DAT(313, 318 + 8, CAN_0x08029F80.MotorCtrlTemp/*witdh*/, 1, 40, WHITE, 3, 0); //����������¶�
    } else if (f_index == 5) {
        f_index = 6;
        updata_SOC(585, 155 + 60 + 60);
        updata_DAT(800 - 150, 318 + 8 + 38, CAN_0x18F8179E.BMS_MAX_Temp/*DS3231_ReadTemp()*/, 1, 40, WHITE, 3, 0); //�������
        updata_DAT(800 - 150, 318 + 8 + 38 * 2, CAN_0x18F8179E.BMS_MIN_Temp, 1, 40, WHITE, 3, 0); //�������
    } else if (f_index == 6) {
        f_index = 7;
        updata_DCDY(585, 155, 0.1);
        disp_FONT_baojingNew(162, 325 + 38 * 2);
        //LCD_DrawImageString_21x20(162, 325 + 38 * 2,main_page_3,WHITE,BLACK);
    } else if (f_index == 7) {
        f_index = 1;
        updata_Dangwei(138 + 15 + 66 * 4, 70);
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
#if VIDEO
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

                //��������ѡ��ʹ�ܰ���
                /*if ((VCU_Gear == 1) && !R_flag) {//����
                    key_AV = 1; //ģ��AV���ذ�һ��
                    AV_CH = 0; //0+1=1  ����
                    R_flag = 1; //��ֹһֱ�����������������key_AV������1
                }
                if ((VCU_Gear != 1) && R_flag) {
                    key_AV = 1;
                    AV_CH = 4; // 0 ����MCU����
                    R_flag = 0;
                    M_flag = 0;
                }*/

                //����ѡ��ʹ�ܰ��� ���ȼ�С�ڵ���
                /*if (VCU_Gear != 1) {
                    if (IN3 && !M_flag) {//���ſ�
                        key_AV = 1; //ģ��AV���ذ�һ��
                        AV_CH = 1; //1+1=2  AV1
                        M_flag = 1; //��ֹһֱ�����������������key_AV������1
                    }
                    if (!IN3 && M_flag) {
                        key_AV = 1;
                        AV_CH = 4; // 0 ����MCU����
                        M_flag = 0;
                        R_flag = 0;
                    }
                }*/
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
#endif
    }
#endif   
}

/******************************************************/
void ICFrame(unsigned char index) { //�Ǳ���
    unsigned char i;
    const unsigned char *ip1[16] = {in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16};
    const unsigned char *ip2[16] = {in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32};
    const unsigned char *ip3[16] = {in33, in34, in35, in36, in37, in38, in39, in40, ad1, ad2, ad3, ad4, ad5, ad6};
    LCD_Clear();
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //��������

    print_SZ_2(750, 50, index, 1, 0, WHITE); // x/1
    LCD_DrawImage1BPP_11x20(750 + 11, 50, BMP_ASIC_11x20[47 - 32], WHITE, BLACK);
    print_SZ_2(750 + 11 + 14, 50, 3, 1, 0, WHITE);

    LCD_DrawImageString_21x20(130 + 200 + 200, 130 - 85 + 4, cantx, WHITE, BLACK); //CANͨѶ

    if (index == 1) {
        LCD_DrawImageSBPP(130 + 200, 130 - 85, 50, IC_SYSTEM, WHITE, BLACK); //�Ǳ�            
        /***********************�Ǳ������ɼ�*********************************/
        /*************************��һ�п���***********************************/
        for (i = 0; i < 16; i++) {
            LCD_DrawImageString_21x20(35, 75 + 25 * i, ip1[i], WHITE, BLACK);
        }
        /*************************�ڶ��п���***********************************/
        for (i = 0; i < 16; i++) {
            LCD_DrawImageString_21x20(285, 75 + 25 * i, ip2[i], WHITE, BLACK);
        }
        /*************************�����п���***********************************/
        for (i = 0; i < 16; i++) {
            LCD_DrawImageString_21x20(535, 75 + 25 * i, ip3[i], WHITE, BLACK);
        }
        for (i = 8; i < 14; i++) {
            LCD_DrawImage1BPP(535 + 63 + 42 + 16 * 4 - 4, 75 + 25 * i, BMP_Omu, WHITE, BLACK); //��
            LCD_DrawImage1BPP_11x20(535 + 63 + 42 + 16 * 4 + 16 * 5, 75 + 25 * i, BMP_ASIC_11x20[86 - 32], WHITE, BLACK); //V
        }
        LCD_DrawImageString_21x20(505 + 100, 75 + 8 + 25 * 15, bbh, WHITE, BLACK);
        LCD_DrawImage1BPP(505 + 200, 75 + 25 * 15, BMP_V, WHITE, BLACK);
    } else {
        if (index == 2) {
            const unsigned char *fp1[16] = {fout1, fout2, fout3, fout4, fout5, fout6, fout7, fout8, fout9, fout10, fout11, fout12, fout13, fout14, fout15, fadd};
            const unsigned char *fp2[16] = {fkl1, fkl2, fkl3, fkl4, fkl5, fkl6, fkl7, fkl8, fkl9, fkl10, fkl11, fkl12, fkl13, fkl14, fkl15, fkh1};
            LCD_DrawImage1BPP(130 + 200, 130 - 85, BMP_QIAN, WHITE, BLACK); //ǰ
            LCD_DrawImage1BPP(130 + 200 + 25, 130 - 85, BMP_MOKUAI, WHITE, BLACK); //ģ��
            LCD_DrawImage1BPP(130 + 200 + 25 + 50, 130 - 85, BMP_Message, WHITE, BLACK); //��Ϣ
            for (i = 0; i < 15; i++) {
                LCD_DrawImage1BPP_11x20(60 + 280, 75 + 3 + 25 * i, BMP_ASIC_11x20[65 - 32], WHITE, BLACK);
            }
            /*************************ǰģ�����***********************************/
            for (i = 0; i < 16; i++) {
                LCD_DrawImageString_21x20(60, 75 + 25 * i, fp1[i], WHITE, BLACK);
            }
            /***********************ǰģ�鿪�زɼ�*********************************/
            for (i = 0; i < 16; i++) {
                LCD_DrawImageString_21x20(285 + 150, 75 + 25 * i, fp2[i], WHITE, BLACK);
            }
            LCD_DrawImageString_21x20(535 + 63 - 11, 75 + 25 * 0, fad1, WHITE, BLACK);
            LCD_DrawImageString_21x20(535 + 63 - 11, 75 + 25 * 1, fad2, WHITE, BLACK);
        } else if (index == 3) {
            const unsigned char *mp1[16] = {mout1, mout2, mout3, mout4, mout5, mout6, mout7, mout8, mout9, mout10, mout11, mout12, mout13, mout14, mout15, madd};
            const unsigned char *mp2[16] = {mkl1, mkl2, mkl3, mkl4, mkl5, mkl6, mkl7, mkl8, mkl9, mkl10, mkl11, mkl12, mkl13, mkl14, mkl15, mkh1};
            LCD_DrawImage1BPP(130 + 200, 130 - 85, BMP_DING, WHITE, BLACK); //��
            LCD_DrawImage1BPP(130 + 200 + 25, 130 - 85, BMP_MOKUAI, WHITE, BLACK); //ģ��
            LCD_DrawImage1BPP(130 + 200 + 25 + 50, 130 - 85, BMP_Message, WHITE, BLACK); //��Ϣ
            for (i = 0; i < 15; i++) {
                LCD_DrawImage1BPP_11x20(60 + 280, 75 + 3 + 25 * i, BMP_ASIC_11x20[65 - 32], WHITE, BLACK);
            }
            /*********************��ģ�����***************************************/
            for (i = 0; i < 16; i++) {
                LCD_DrawImageString_21x20(60, 75 + 25 * i, mp1[i], WHITE, BLACK);
            }
            /************************��ģ�鿪��*********************************/
            for (i = 0; i < 16; i++) {
                LCD_DrawImageString_21x20(285 + 150, 75 + 25 * i, mp2[i], WHITE, BLACK);
            }
            LCD_DrawImageString_21x20(535 + 63 - 11, 75 + 25 * 0, mad1, WHITE, BLACK);
            LCD_DrawImageString_21x20(535 + 63 - 11, 75 + 25 * 1, mad2, WHITE, BLACK);
        } else if (index == 4) {
            const unsigned char *rp1[16] = {rout1, rout2, rout3, rout4, rout5, rout6, rout7, rout8, rout9, rout10, rout11, rout12, rout13, rout14, rout15, radd};
            const unsigned char *rp2[16] = {rkl1, rkl2, rkl3, rkl4, rkl5, rkl6, rkl7, rkl8, rkl9, rkl10, rkl11, rkl12, rkl13, rkl14, rkl15, rkh1};
            LCD_DrawImage1BPP(130 + 200, 130 - 85, BMP_HOU, WHITE, BLACK); //��
            LCD_DrawImage1BPP(130 + 200 + 25, 130 - 85, BMP_MOKUAI, WHITE, BLACK); //ģ��
            LCD_DrawImage1BPP(130 + 200 + 25 + 50, 130 - 85, BMP_Message, WHITE, BLACK); //��Ϣ
            for (i = 0; i < 15; i++) {
                LCD_DrawImage1BPP_11x20(60 + 280, 75 + 3 + 25 * i, BMP_ASIC_11x20[65 - 32], WHITE, BLACK);
            }
            /*********************��ģ�����***************************************/
            for (i = 0; i < 16; i++) {
                LCD_DrawImageString_21x20(60, 75 + 25 * i, rp1[i], WHITE, BLACK);
            }
            /*********************��ģ�鿪��***************************************/
            for (i = 0; i < 16; i++) {
                LCD_DrawImageString_21x20(285 + 150, 75 + 25 * i, rp2[i], WHITE, BLACK);
            }
            LCD_DrawImageString_21x20(535 + 63 - 11, 75 + 25 * 0, rad1, WHITE, BLACK);
            LCD_DrawImageString_21x20(535 + 63 - 11, 75 + 25 * 1, rad2, WHITE, BLACK);
        }
        LCD_DrawImage1BPP(535 + 63 + 42 + 16 * 4 - 4, 75 + 25 * 0, BMP_Omu, WHITE, BLACK); //��
        LCD_DrawImage1BPP(535 + 63 + 42 + 16 * 4 + 16 * 5, 75 + 25 * 0, BMP_ASIC_11x20[86 - 32], WHITE, BLACK); //V

        LCD_DrawImage1BPP(535 + 63 + 42 + 16 * 4 - 4, 75 + 25 * 1, BMP_Omu, WHITE, BLACK); //��
        LCD_DrawImage1BPP(535 + 63 + 42 + 16 * 4 + 16 * 5, 75 + 25 * 1, BMP_ASIC_11x20[86 - 32], WHITE, BLACK); //V

        //�汾��
        LCD_DrawImageString_21x20(505 + 100, 75 + 8 + 25 * 15, bbh, WHITE, BLACK);
        LCD_DrawImage1BPP(505 + 200, 75 + 25 * 15, BMP_V, WHITE, BLACK);
    }
}

void ICUpdate(unsigned char index) {
    unsigned int dump, i;
    unsigned char color, CanStatus = 1;
    if (index == 1) {
        for (i = 0; i < NODE_NUMBER; i++) {
            CanStatus = CanStatus && (NodeCount[i] < CAN_TIME);
        }
        if (CanStatus)
            LCD_DrawImageString_21x20(130 + 200 + 200 + 11 + 11 + 11 + 50 + 20, 130 - 85 + 4, zhengchang, GREEN, BLACK);
        else
            LCD_DrawImageString_21x20(130 + 200 + 200 + 11 + 11 + 11 + 50 + 20, 130 - 85 + 4, guzhang, RED, BLACK);

        for (i = 0; i < 6; i++) {
            print_SZ_2(535 + 63 + 42 + 4, 75 + 25 * (i + 8), ADR[i + 1], 3, 0, YELLOW);
        }
        for (i = 0; i < 6; i++) {
            print_SZ_2(535 + 63 + 42 + 16 * 5, 75 + 25 * (i + 8), ADV[i + 1] / 10, 3, 2, YELLOW);
        }
print_SZ_2(535 + 63 + 42 + 16 * 5, 75 + 25 * 14, ADV[0], 3, 1, YELLOW);
        dump = sw_input[0].byte + ((unsigned int) (sw_input[1].byte) << 8);
        for (i = 0; i < 16; i++) {
            if (i < 8) {
                if ((dump & 0x01) == 0x01) {//Ϊ�ػ𿪹�
                    LCD_DrawImage1BPP(5, 75 + 25 * i, Bmpflag[0], WHITE, BLACK);
                } else {
                    LCD_DrawImage1BPP(5, 75 + 25 * i, Bmpflag[1], GREEN, BLACK);
                }
            }
            else if ((dump & 0x01) == 0x01) {
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
        //�Խ�����
        print_SZ_1(535 + 25, 75 + 25 * 15, TIME, 8, 0, YELLOW);
        //����汾��
        print_SZ_1(535 + 200, 75 + 25 * 15, VERISON, 3, 2, YELLOW);
    } else if (index == 2) {
        if (Fcan_count == CAN_TIME)
            LCD_DrawImageString_21x20(130 + 200 + 200 + 11 + 11 + 11 + 50 + 20, 130 - 85 + 4, guzhang, RED, BLACK);
        else
            LCD_DrawImageString_21x20(130 + 200 + 200 + 11 + 11 + 11 + 50 + 20, 130 - 85 + 4, zhengchang, GREEN, BLACK);

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
                print_SZ(30 + 250, 75 + 6 + 25 * i, fpcur[i] / 100, 3, 1, GREEN); //ǰģ�����
            else
                print_SZ(30 + 250, 75 + 6 + 25 * i, 0, 3, 1, GREEN);
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
        //ģ��ģ���ź�
        for (i = 0; i < 2; i++) {
            print_SZ_2(535 + 63 + 42 + 4, 75 + 25 * i, fADR[i], 3, 0, YELLOW);
        }
        for (i = 0; i < 2; i++) {
            print_SZ_2(535 + 63 + 42 + 16 * 5, 75 + 25 * i, fADV[i] / 10, 3, 2, YELLOW);
        }
        //����汾��
        print_SZ_1(535 + 200, 75 + 25 * 15, Fversion, 3, 2, YELLOW);
    }

    /*�п�ģ��*/
    if (index == 3) {
        if (Mcan_count == CAN_TIME)
            LCD_DrawImageString_21x20(130 + 200 + 200 + 11 + 11 + 11 + 50 + 20, 130 - 85 + 4, guzhang, RED, BLACK);
        else
            LCD_DrawImageString_21x20(130 + 200 + 200 + 11 + 11 + 11 + 50 + 20, 130 - 85 + 4, zhengchang, GREEN, BLACK);

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
                print_SZ(30 + 250, 75 + 6 + 25 * i, mpcur[i] / 100, 3, 1, GREEN); //��ģ�����
            else
                print_SZ(30 + 250, 75 + 6 + 25 * i, 0, 3, 1, GREEN);
        }
        //ADD��θ�λ�ź�
        if (mADD)
            LCD_DrawImage1BPP(30, 75 + 25 * 15, Bmpflag[1], GREEN, BLACK);
        else
            LCD_DrawImage1BPP(30, 75 + 25 * 15, Bmpflag[0], WHITE, BLACK);

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
        for (i = 0; i < 2; i++) {
            print_SZ_2(535 + 63 + 42 + 4, 75 + 25 * i, mADR[i], 3, 0, YELLOW);
        }
        for (i = 0; i < 2; i++) {
            print_SZ_2(535 + 63 + 42 + 16 * 5, 75 + 25 * i, mADV[i] / 10, 3, 2, YELLOW);
        }
        //����汾��
        print_SZ_1(535 + 200, 75 + 25 * 15, Mversion, 3, 2, YELLOW);
    }

    /*���ģ��*/
    if (index == 4) {
        if (Rcan_count == CAN_TIME)
            LCD_DrawImageString_21x20(130 + 200 + 200 + 11 + 11 + 11 + 50 + 20, 130 - 85 + 4, guzhang, RED, BLACK);
        else
            LCD_DrawImageString_21x20(130 + 200 + 200 + 11 + 11 + 11 + 50 + 20, 130 - 85 + 4, zhengchang, GREEN, BLACK);

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
                print_SZ(30 + 250, 75 + 6 + 25 * i, rpcur[i] / 100, 3, 1, GREEN); //��ģ�����
            else
                print_SZ(30 + 250, 75 + 6 + 25 * i, 0, 3, 1, GREEN);
        }
        //ADD��θ�λ�ź�
        if (rADD)
            LCD_DrawImage1BPP(30, 75 + 25 * 15, Bmpflag[1], GREEN, BLACK);
        else
            LCD_DrawImage1BPP(30, 75 + 25 * 15, Bmpflag[0], WHITE, BLACK);

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
        for (i = 0; i < 2; i++) {
            print_SZ_2(535 + 63 + 42 + 4, 75 + 25 * i, rADR[i], 3, 0, YELLOW);
        }
        for (i = 0; i < 2; i++) {
            print_SZ_2(535 + 63 + 42 + 16 * 5, 75 + 25 * i, rADV[i] / 10, 3, 2, YELLOW);
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

void MenuFrame(void) {
    unsigned char color = WHITE;
    LCD_Clear();
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //��������   

    LCD_DrawRect(0, 430, 800, 2, YELLOW); //�ײ�����
    LCD_DrawImageSBPP(130, 130 + 35 * 0, 50, MOTO_SYSTEM, color, BLACK); //���

    LCD_DrawImageSBPP(130, 130 + 35 * 1, 50, DCDC_SYSTEM, color, BLACK); //DCDC

    LCD_DrawImageSBPP(130, 130 + 35 * 2, 50, AIR_SYSTEM, color, BLACK); //����

    LCD_DrawImageSBPP(130, 130 + 35 * 3, 50, OIL_SYSTEM, color, BLACK); //ת��


    LCD_DrawImageSBPP(130 + 350, 130 + 35 * 0, 50, BMS_SYSTEM, color, BLACK); //BMS

    LCD_DrawImageSBPP(130 + 350, 130 + 35 * 1, 50, Battery_SYSTEM, color, BLACK); //���   

    LCD_DrawImageSBPP(130 + 350, 130 + 35 * 2, 50, AC_SYSTEM, color, BLACK); //�յ�

    LCD_DrawImageSBPP(130 + 350, 130 + 35 * 3, 50, IC_SYSTEM, color, BLACK); //�Ǳ�

}

#define Menu_Number  8

void MenuUpdate(void) {
    static unsigned char menu = 1;
    unsigned char color = BLACK, j = 0, i = 0;
    if (key_up) {//��ͷ������
        key_up = 0;
        if (time_flag) {
            t++; //ʱ������
            if (t == 10) t = 0;
        }
        if (!time_flag) {
            menu++;
            if (menu > Menu_Number) {
                menu = 1;
            }
        }
    }

    if (key_AV) {//��ͷ������
        key_AV = 0;
        if (time_flag)
            t_add = 1;
        if (!time_flag) {
            menu--;
            if (menu < 1) {
                menu = Menu_Number;
            }
        }
    }
#if 0
    switch (menu) {
        case 1:
            if (key_set) {
                key_set = 0;
                if (time_flag == 0) {
                    f_index = 0;
                    frmID = 2;
                }
                time_flag = 0;
            }

            for (i = 0; i < Menu_Number; i++) {
                if ((i + 1) == menu)
                    LCD_DrawImage1BPP(105, 131 + 35 * i, BMP_Choose, GREEN, BLACK);
                else
                    LCD_DrawImage1BPP(105, 131 + 35 * i, BMP_Choose, BLACK, BLACK);
            }
            break;
        case 2:
            if (key_set) {
                key_set = 0;
                if (time_flag == 0) {
                    f_index = 0;
                    frmID = 3;
                }
                time_flag = 0;
            }

            for (i = 0; i < Menu_Number; i++) {
                if ((i + 1) == menu)
                    LCD_DrawImage1BPP(105, 131 + 35 * i, BMP_Choose, GREEN, BLACK);
                else
                    LCD_DrawImage1BPP(105, 131 + 35 * i, BMP_Choose, BLACK, BLACK);
            }
            break;
        case 3:
            if (key_set) {
                key_set = 0;
                if (time_flag == 0) {
                    f_index = 0;
                    frmID = 7;
                }
                time_flag = 0;
            }

            for (i = 0; i < Menu_Number; i++) {
                if ((i + 1) == menu)
                    LCD_DrawImage1BPP(105, 131 + 35 * i, BMP_Choose, GREEN, BLACK);
                else
                    LCD_DrawImage1BPP(105, 131 + 35 * i, BMP_Choose, BLACK, BLACK);
            }
            break;
        case 4:
            if (key_set) {
                key_set = 0;
                if (time_flag == 0) {
                    f_index = 0;
                    frmID = 9;
                }
                time_flag = 0;
            }

            for (i = 0; i < Menu_Number; i++) {
                if ((i + 1) == menu)
                    LCD_DrawImage1BPP(105, 131 + 35 * i, BMP_Choose, GREEN, BLACK);
                else
                    LCD_DrawImage1BPP(105, 131 + 35 * i, BMP_Choose, BLACK, BLACK);
            }
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        default:
            break;
    }
#endif

#if 0
    //�Ӳ˵����л�
    if (menu == 1) {
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
    LCD_DrawImage1BPP(105 + 350 * 0, 131, BMP_Choose, color, BLACK);
    if (menu == 2) {
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
    LCD_DrawImage1BPP(105 + 350 * 0, 131 + 35, BMP_Choose, color, BLACK);
    if (menu == 3) {
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
    LCD_DrawImage1BPP(105 + 350 * 0, 131 + 2 * 35, BMP_Choose, color, BLACK);
    if (menu == 4) {
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
    LCD_DrawImage1BPP(105 + 350 * 1, 131 + 0 * 35, BMP_Choose, color, BLACK);
    if (menu == 5) {
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
    LCD_DrawImage1BPP(105 + 350 * 1, 131 + 35 * 1, BMP_Choose, color, BLACK);
    if (menu == 6) {
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
    LCD_DrawImage1BPP(105 + 350, 131 + 2 * 35, BMP_Choose, color, BLACK);
    if (menu == 7) {
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
    if (menu == 8) {
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

#endif

#if 1
    switch (menu) {
        case 1:
            color = GREEN;
            if (key_set) {
                key_set = 0;
                if (time_flag == 0) {
                    f_index = 0;
                    frmID = 2; //���
                }
                time_flag = 0;
            }
            //LCD_DrawImage1BPP(105 + 350 * 0, 131, BMP_Choose, color, BLACK);
            break;
        case 2:
            color = GREEN;
            if (key_set) {
                key_set = 0;
                if (time_flag == 0) {
                    f_index = 0;
                    frmID = 3; //DCDC
                }
                time_flag = 0;
            }
            //LCD_DrawImage1BPP(105 + 350 * 0, 131 + 35, BMP_Choose, color, BLACK);
            break;
        case 3:
            color = GREEN;
            if (key_set) {
                key_set = 0;
                if (time_flag == 0) {
                    f_index = 0;
                    frmID = 4; //����
                }
                time_flag = 0;
            }
            //LCD_DrawImage1BPP(105 + 350 * 0, 131 + 2 * 35, BMP_Choose, color, BLACK);
            break;
        case 4:
            color = GREEN;
            if (key_set) {
                key_set = 0;
                if (time_flag == 0) {
                    f_index = 0;
                    frmID = 5; //�ͱ�
                }
                time_flag = 0;
            }
            //LCD_DrawImage1BPP(105 + 350 * 0, 131 + 3 * 35, BMP_Choose, color, BLACK);
            break;
        case 5:
            color = GREEN;
            if (key_set) {
                key_set = 0;
                if (time_flag == 0) {
                    f_index = 0;
                    frmID = 6; //BMS
                }
                time_flag = 0;
            }
            //LCD_DrawImage1BPP(105 + 350 * 1, 131 + 0 * 35, BMP_Choose, color, BLACK);
            break;
        case 6:
            color = GREEN;
            if (key_set) {
                key_set = 0;
                if (time_flag == 0) {
                    f_index = 0;
                    frmID = 7; //������
                }
                time_flag = 0;
            }
            //LCD_DrawImage1BPP(105 + 350 * 1, 131 + 1 * 35, BMP_Choose, color, BLACK);
            break;
        case 7:
            color = GREEN;
            if (key_set) {
                key_set = 0;
                if (time_flag == 0) {
                    f_index = 0;
                    frmID = 8; //�յ�
                }
                time_flag = 0;
            }
            //LCD_DrawImage1BPP(105 + 350 * 1, 131 + 2 * 35, BMP_Choose, color, BLACK);
            break;
        case 8:
            color = GREEN;
            if (key_set) {
                key_set = 0;
                if (time_flag == 0) {
                    f_index = 0;
                    frmID = 9; //�Ǳ�
                }
                time_flag = 0;
            }
            //LCD_DrawImage1BPP(105 + 350 * 1, 131 + 3 * 35, BMP_Choose, color, BLACK);
            break;
        default:
            break;
    }
    for (j = 0; j < 2; j++) {
        for (i = 0; i < 4; i++) {
            if ((j * 4 + i + 1) == menu)
                color = GREEN;
            else
                color = BLACK;
            LCD_DrawImage1BPP(105 + 350 * j, 131 + i * 35, BMP_Choose, color, BLACK);
        }
    }
#endif
}

void frmMenu(void) {
    if (f_index == 0) { //ֻ����һ��
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
    const unsigned char *p1_1[10] = {djxtxx1, djxtxx2, djxtxx3, djxtxx4, djxtxx5, djxtxx6};
    const unsigned char *p1_2[10] = {djxtxx7, djxtxx8, djxtxx9, djxtxx10, djxtxx11, djxtxx12};
    const unsigned char *p2_1[10] = {zcxtxx1, zcxtxx2, zcxtxx3, zcxtxx4, zcxtxx5, zcxtxx6, zcxtxx7};
    const unsigned char *p2_2[10] = {zcxtxx8, zcxtxx9, zcxtxx10, zcxtxx11, zcxtxx12, zcxtxx13, zcxtxx14};
    LCD_Clear();
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //��������
    LCD_DrawImageSBPP(130 + 200, 130 - 85, 50, MOTO_SYSTEM, WHITE, BLACK); //���

    LCD_DrawRect(80, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320 + 320, 90, 1, 380, GREEN);
    for (i = 0; i < 11; i++)
        LCD_DrawRect(80, 90 + i * 38, 640, 1, GREEN);

    print_SZ_2(750, 50, index, 1, 0, WHITE); // x/3
    LCD_DrawImage1BPP_11x20(750 + 11, 50, BMP_ASIC_11x20[47 - 32], WHITE, BLACK);
    print_SZ_2(750 + 11 + 14, 50, 2, 1, 0, WHITE);

    if (index == 1) {
        for (i = 0; i < 10; i++) {
            LCD_DrawImageString_21x20(82, 100 + 38 * i, p1_1[i], WHITE, BLACK); //
        }
        for (i = 0; i < 10; i++) {
            LCD_DrawImageString_21x20(82 + 320, 100 + 38 * i, p1_2[i], WHITE, BLACK); //
        }

        LCD_DrawImage1BPP_11x20(400 - 24, 100 + 38 * 0, BMP_ASIC_11x20[86 - 32], WHITE, BLACK); //V
        LCD_DrawImage1BPP_11x20(400 - 24, 100 + 38 * 1, BMP_ASIC_11x20[65 - 32], WHITE, BLACK); //A
        //LCD_DrawImage1BPP(400 - 24, 100 + 38 * 2, BMP_T, WHITE, BLACK); //V
        //LCD_DrawImage1BPP(400 - 28, 100 + 38 * 3, BMP_T, WHITE, BLACK); //��     
        //LCD_DrawImage1BPP_11x20(400 + 320 - 24, 100 + 38 * 0, BMP_ASIC_11x20[37 - 32], WHITE, BLACK); //%
        LCD_DrawImageString_21x20(400 - 32, 100 + 38 * 5, string_nm, WHITE, BLACK); //Nm
        
        
        LCD_DrawImageString_21x20(400 + 320 - 32, 100 + 38 * 0, string_rpm, WHITE, BLACK); //Rpm
        LCD_DrawImageString_21x20(400 + 320 - 32, 100 + 38 * 1, string_nm, WHITE, BLACK); //Nm
        LCD_DrawImage1BPP(400 + 320 - 28, 100 + 38 * 2, BMP_T, WHITE, BLACK); //�� 
        LCD_DrawImage1BPP(400 + 320 - 28, 100 + 38 * 3, BMP_T, WHITE, BLACK); //�� 

    } else if (index == 2) {
        for (i = 0; i < 10; i++) {
            LCD_DrawImageString_21x20(82, 100 + 38 * i, p2_1[i], WHITE, BLACK); //
        }
        for (i = 0; i < 10; i++) {
            LCD_DrawImageString_21x20(82 + 320, 100 + 38 * i, p2_2[i], WHITE, BLACK); //
        }
        
        LCD_DrawImage1BPP_11x20(400  - 24, 100 + 38 * 1, BMP_ASIC_11x20[37 - 32], WHITE, BLACK); //%
        LCD_DrawImage1BPP_11x20(400  - 24, 100 + 38 * 2, BMP_ASIC_11x20[37 - 32], WHITE, BLACK); //%
        LCD_DrawImageString_21x20(400 - 24 - 24, 100 + 38 * 3, string_km1h, WHITE, BLACK); //Km/h
        
        LCD_DrawImage1BPP_11x20(400 + 320 - 24, 100 + 38 * 1, BMP_ASIC_11x20[86 - 32], WHITE, BLACK); //V
    } else if (index == 3) {

    }
}

void MOTOUpdate(unsigned char index) {
    if (index == 1) {
        print_SZ_1(82 + 200 + 16, 100 - 8 + 38 * 0, CAN_0x18F11FF0.CtrlVoltage * 0.1, 3, 0, WHITE);
        updata_DAT(82 + 200 + 16, 100 - 8 + 38 * 1, CAN_0x18F11FF0.CtrlCurrent, 0.1, 1000, WHITE, 3, 0);
        print_D(82 + 200 + 16 * 2, 100 - 8 + 38 * 2, CAN_0x18F11FF0.IpuMode, 5, 0, WHITE);
        print_D(82 + 200 - 16 * 1, 100 - 8 + 38 * 3, CAN_0x18F11FF0.Diagnosis1.byte, 8, 0, WHITE);
        print_SZ_1(82 + 200 + 16, 100 - 8 + 38 * 4, CAN_0x18F11FF0.McuLife, 3, 0, WHITE);
        updata_DAT(82 + 200 + 16, 100 - 8 + 38 * 5, CAN_0x18F120F0.MotorTopTorque, 0.1, 3000, WHITE, 4, 0);


        updata_DAT(82 + 200 + 320 + 16, 100 - 8 + 38 * 0, CAN_0x18F120F0.MotorSpeed, 1, 12000, WHITE, 4, 0);
        updata_DAT(82 + 200 + 320 + 16, 100 - 8 + 38 * 1, CAN_0x18F120F0.MotorTorque, 0.1, 3000, WHITE, 4, 0);
        updata_DAT(82 + 200 + 320 + 16 * 2, 100 - 8 + 38 * 2, CAN_0x18F120F0.MotorTemp, 1, 40, WHITE, 3, 0);
        updata_DAT(82 + 200 + 320 + 16 * 2, 100 - 8 + 38 * 3, CAN_0x18F120F0.MotorCtrlTemp, 1, 40, WHITE, 3, 0);
        
        if (CAN_0x18F121F0.MotorCtrlStatus == 0) {
            LCD_DrawImageString_21x20(82 + 320 + 42 * 6 - 5, 100 + 38 * 4, tingzhi, YELLOW, BLACK);
        } else if (CAN_0x18F121F0.MotorCtrlStatus == 2) {
            LCD_DrawImageString_21x20(82 + 320 + 42 * 6 - 5, 100 + 38 * 4, gongzuo, GREEN, BLACK);
        }else if(CAN_0x18F121F0.MotorCtrlStatus == 5){
            LCD_DrawImageString_21x20(82 + 320 + 42 * 6 - 5, 100 + 38 * 4, guzhang, RED, BLACK);
        }
        print_SZ_1(82 + 200 + 320 + 16, 100 - 8 + 38 * 5, CAN_0x18F121F0.MotorCtrlFaultCode, 3, 0, WHITE);
        
    } else if (index == 2) {
        print_D(82 + 200 - 16 * 1, 100 - 8 + 38 * 0, CAN_0x0CF101A7.byte[0], 8, 0, WHITE);
        print_SZ_1(82 + 200 + 16, 100 - 8 + 38 * 1, CAN_0x0CF101A7.AcceleratePedalAperture * 0.4, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 16, 100 - 8 + 38 * 2, CAN_0x0CF101A7.BrakePedalAperture * 0.4, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 16, 100 - 8 + 38 * 3, CAN_0x0CF101A7.Speed / 256, 3, 0, WHITE);
        print_D(82 + 200 - 16 * 1, 100 - 8 + 38 * 4, CAN_0x0CF101A7.byte[6], 8, 0, WHITE);
        print_SZ_1(82 + 200 + 16, 100 - 8 + 38 * 5, CAN_0x0CF101A7.VcuLife, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 16, 100 - 8 + 38 * 6, CAN_0x0CF103A7.ProductCode, 3, 0, WHITE);
        
        if (CAN_0x0CF103A7.ContactorOrder == 0) {
            LCD_DrawImageString_21x20(82 + 320 + 42 * 6 - 5, 100 + 38 * 0, duankai, YELLOW, BLACK);
        } else if (CAN_0x0CF103A7.ContactorOrder == 1) {
            LCD_DrawImageString_21x20(82 + 320 + 42 * 6 - 5, 100 + 38 * 0, bihe, GREEN, BLACK);
        }
        print_SZ_1(82 + 200 + 320 + 16, 100 - 8 + 38 * 1, CAN_0x0CF103A7.McuInputVoltage * 0.1, 3, 0, WHITE);
        
        if (CAN_0x0CF103A7.ChargeEn == 0) {
            LCD_DrawImageString_21x20(82 + 320 + 42 * 6 - 5, 100 + 38 * 2, tingzhi, YELLOW, BLACK);
        } else if (CAN_0x0CF103A7.ChargeEn == 1) {
            LCD_DrawImageString_21x20(82 + 320 + 42 * 6 - 5, 100 + 38 * 2, gongzuo, GREEN, BLACK);
        }
        
        print_D(82 + 200 + 320 - 16 * 1, 100 - 8 + 38 * 3, CAN_0x0CF103A7.ContactorStatus, 8, 0, WHITE);
        print_SZ_1(82 + 200 + 320 + 16, 100 - 8 + 38 * 4, CAN_0x0CF1064A.FaultLevel, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 320 - 32, 100 - 8 + 38 * 5, CAN_0x0CF1064A.VCU_DTC, 6, 0, WHITE);
        print_D(82 + 200 + 320 - 16 * 1, 100 - 8 + 38 * 6, CAN_0x0CF1064A.byte[7], 8, 0, WHITE);       
    } else if (index == 3) {      
    }
}

void frmMOTO(void) {
    static unsigned char index_MOTO = 1;
    if (f_index == 0) { //ֻ����һ��
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
        index_MOTO--;
        f_index = 0;
        if (index_MOTO == 0) {
            index_MOTO = 1;
            frmID = 1;
        }
    }
    if (key_up) {
        key_up = 0;
        index_MOTO++;
        f_index = 0;
        if (index_MOTO >= 3) {
            index_MOTO = 1;
            frmID = 1;
        }
    }
    if (key_set) {//����������
        key_set = 0;
        frmID = 0;
        f_index = 0;
        Index = 0;
        index_MOTO = 1;
    }
    if (key_long_set) {
        key_long_set = 0;
    }

}

/******************************************************/

void DCDCFrame(void) {
    unsigned char i = 0;
    const unsigned char *p1_1[10] = {dcdcxx1, dcdcxx2, dcdcxx3, dcdcxx4};
    const unsigned char *p1_2[10] = {dcdcxx5, dcdcxx6, dcdcxx7, dcdcxx8, dcdcxx9};
    LCD_Clear();
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //��������
    LCD_DrawImageSBPP(130 + 200, 130 - 85, 50, DCDC_SYSTEM, WHITE, BLACK); //DCDCϵͳ��Ϣ

    LCD_DrawRect(80, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320 + 320, 90, 1, 380, GREEN);
    for (i = 0; i < 11; i++)
        LCD_DrawRect(80, 90 + i * 38, 640, 1, GREEN);

    for (i = 0; i < 10; i++) {
        LCD_DrawImageString_21x20(82, 100 + 38 * i, p1_1[i], WHITE, BLACK); //
    }
    for (i = 0; i < 10; i++) {
        LCD_DrawImageString_21x20(82 + 320, 100 + 38 * i, p1_2[i], WHITE, BLACK); //
    }

    LCD_DrawImage1BPP_11x20(400 - 24, 100, BMP_ASIC_11x20[86 - 32], WHITE, BLACK); //V
    LCD_DrawImage1BPP_11x20(400 - 24, 100 + 38, BMP_ASIC_11x20[65 - 32], WHITE, BLACK); //A
    LCD_DrawImage1BPP_11x20(400 - 24, 100 + 38 * 2, BMP_ASIC_11x20[65 - 32], WHITE, BLACK); //A
    LCD_DrawImage1BPP(400 - 24, 100 + 38 * 3, BMP_T, WHITE, BLACK); //��
    
    LCD_DrawImage1BPP_11x20(720 - 24, 100, BMP_ASIC_11x20[86 - 32], WHITE, BLACK); //V
}

void DCDCUpdate(void) {
    print_SZ_1(82 + 200 + 20, 100 - 8, CAN_0x142CFF98.DCDC_InputVoltage * 0.1, 3, 0, WHITE);
    print_SZ_1(82 + 200 + 20, 100 - 8 + 38, CAN_0x142CFF98.DCDC_InputCurrent, 3, 0, WHITE);  
    print_SZ_1(82 + 200 + 20, 100 - 8 + 38 * 2, CAN_0x142CFF98.DCDC_OutputCurrent, 3, 0, WHITE);
    updata_DAT(82 + 200 + 20, 100 - 8 + 38 * 3, CAN_0x142CFF98.DCDC_CtrlTemp, 1, 40, WHITE, 3, 0);


    print_SZ_1(82 + 200 + 300 + 16 * 2, 100 - 8 + 38 * 0, CAN_0x142CFF98.DCDC_OutputAssistLowVoltage, 3, 0, WHITE);
    print_SZ_1(82 + 200 + 300 + 16 * 2, 100 - 8 + 38 * 1, CAN_0x142CFF98.DCDC_Life, 3, 0, WHITE);
    if (CAN_0x142CFF98.DCDC_Status == 0) {
        LCD_DrawImageString_21x20(82 + 320 + 42 * 6 - 5, 100 + 38 * 2, tingzhi, YELLOW, BLACK);
    } else if (CAN_0x142CFF98.DCDC_Status == 1) {
        LCD_DrawImageString_21x20(82 + 320 + 42 * 6 - 5, 100 + 38 * 2, gongzuo, GREEN, BLACK);
    } else if (CAN_0x142CFF98.DCDC_Status == 2) {
        LCD_DrawImageString_21x20(82 + 320 + 42 * 6 - 5, 100 + 38 * 2, guzhang, RED, BLACK);
    }
    print_SZ_1(82 + 200 + 300 + 16 * 1, 100 - 8 + 38 * 3, CAN_0x142CFF98.DCDC_FaultCode, 4, 0, WHITE); 
    if (CAN_0x142CFF98.DCDC_CtrlPrechargeStatus == 0) {
        LCD_DrawImageString_21x20(82 + 320 + 42 * 6 - 5, 100 + 38 * 4, weiwancheng, YELLOW, BLACK);
    } else if (CAN_0x142CFF98.DCDC_CtrlPrechargeStatus == 1) {
        LCD_DrawImageString_21x20(82 + 320 + 42 * 6 - 5, 100 + 38 * 4, yiwancheng, GREEN, BLACK);
    }    
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
void DMQFrame(void) {
    unsigned char i = 0;
    const unsigned char *p1_1[10] = {qbxtxx1, qbxtxx2, qbxtxx3, qbxtxx4};
    const unsigned char *p1_2[10] = {qbxtxx5, qbxtxx6, qbxtxx7, qbxtxx8};
    LCD_Clear();
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //��������
    LCD_DrawImageSBPP(130 + 200 - 15, 130 - 85, 50, AIR_SYSTEM, WHITE, BLACK);

    LCD_DrawRect(80, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320 + 320, 90, 1, 380, GREEN);
    for (i = 0; i < 11; i++)
        LCD_DrawRect(80, 90 + i * 38, 640, 1, GREEN);

    for (i = 0; i < 10; i++) {
        LCD_DrawImageString_21x20(82, 100 + 38 * i, p1_1[i], WHITE, BLACK); //
    }
    for (i = 0; i < 10; i++) {
        LCD_DrawImageString_21x20(82 + 320, 100 + 38 * i, p1_2[i], WHITE, BLACK); //
    }

    LCD_DrawImageString_21x20(400 - 24 - 11 - 11, 100, string_rpm, WHITE, BLACK);
    LCD_DrawImage1BPP_11x20(400 - 24, 100 + 38 * 1, BMP_ASIC_11x20[86 - 32], WHITE, BLACK);
    LCD_DrawImage1BPP_11x20(400 - 24, 100 + 38 * 2, BMP_ASIC_11x20[65 - 32], WHITE, BLACK);
    LCD_DrawImage1BPP(400 - 24, 100 + 38 * 3, BMP_T, WHITE, BLACK); //��

}

void DMQUpdate(void) {
    print_SZ_1(82 + 200 + 20 - 16, 100 - 8, CAN_0x1429FF9B.DCAC_MotorRotateSpeed * 0.125, 4, 0, WHITE);
    print_SZ_1(82 + 200 + 20, 100 - 8 + 38, CAN_0x1429FF9B.DCAC_CtrlVoltage * 0.1, 3, 0, WHITE);
    print_SZ_1(82 + 200 + 20, 100 - 8 + 38 * 2, CAN_0x1429FF9B.DCAC_CtrlCurrent, 3, 0, WHITE);
    updata_DAT(82 + 200 + 20, 100 - 8 + 38 * 3, CAN_0x1429FF9B.DCAC_CtrlTemp, 1, 40, WHITE, 3, 0);
    
    print_SZ_1(82 + 200 + 320, 100 - 8 + 38 * 0, CAN_0x1429FF9B.DCAC_Life, 3, 0, WHITE);   
    if (CAN_0x1429FF9B.DCAC_PumpStatus == 0) {
        LCD_DrawImageString_21x20(82 + 320 + 42 * 6 - 5, 100 + 38 * 1, tingzhi, YELLOW, BLACK);
    } else if (CAN_0x1429FF9B.DCAC_PumpStatus == 1) {
        LCD_DrawImageString_21x20(82 + 320 + 42 * 6 - 5, 100 + 38 * 1, gongzuo, GREEN, BLACK);
    } else if (CAN_0x1429FF9B.DCAC_PumpStatus == 2) {
        LCD_DrawImageString_21x20(82 + 320 + 42 * 6 - 5, 100 + 38 * 1, guzhang, RED, BLACK);
    }
    print_D(82 + 200 + 300, 100 - 8 + 38 * 2, CAN_0x1429FF9B.DCAC_FaultCode, 4, 0, WHITE);
    if (CAN_0x1429FF9B.DCAC_CtrlPrechargeStatus == 0) {
        LCD_DrawImageString_21x20(82 + 320 + 42 * 6 - 5, 100 + 38 * 3, weiwancheng, YELLOW, BLACK);
    } else if (CAN_0x1429FF9B.DCAC_CtrlPrechargeStatus == 1) {
        LCD_DrawImageString_21x20(82 + 320 + 42 * 6 - 5, 100 + 38 * 3, yiwancheng, GREEN, BLACK);
    }   
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
void DMYFrame(void) {
    unsigned char i = 0;
    const unsigned char *p1_1[10] = {zxzlxx1, zxzlxx2, zxzlxx3, zxzlxx4};
    const unsigned char *p1_2[10] = {zxzlxx5, zxzlxx6, zxzlxx7, zxzlxx8};
    LCD_Clear();
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //��������
    LCD_DrawImageSBPP(130 + 200 - 15, 130 - 85, 50, OIL_SYSTEM, WHITE, BLACK);

    LCD_DrawRect(80, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320 + 320, 90, 1, 380, GREEN);
    for (i = 0; i < 11; i++)
        LCD_DrawRect(80, 90 + i * 38, 640, 1, GREEN);

    for (i = 0; i < 10; i++) {
        LCD_DrawImageString_21x20(82, 100 + 38 * i, p1_1[i], WHITE, BLACK); //
    }
    for (i = 0; i < 10; i++) {
        LCD_DrawImageString_21x20(82 + 320, 100 + 38 * i, p1_2[i], WHITE, BLACK); //
    }

    LCD_DrawImageString_21x20(400 - 24 - 11 - 11, 100, string_rpm, WHITE, BLACK);
    LCD_DrawImage1BPP_11x20(400 - 24, 100 + 38 * 1, BMP_ASIC_11x20[86 - 32], WHITE, BLACK); //V
    LCD_DrawImage1BPP_11x20(400 - 24, 100 + 38 * 2, BMP_ASIC_11x20[65 - 32], WHITE, BLACK); //A
    LCD_DrawImage1BPP(400 - 24, 100 + 38 * 3, BMP_T, WHITE, BLACK); //��
}

void DMYUpdate(void) {
    print_SZ_1(82 + 200 + 20 - 16, 100 - 8, CAN_0x142FFF95.SwitcherMotorSpeed * 0.125, 4, 0, WHITE);
    print_SZ_1(82 + 200 + 20, 100 - 8 + 38, CAN_0x142FFF95.SwitcherCtrlVoltage * 0.1, 3, 0, WHITE);
    print_SZ_1(82 + 200 + 20, 100 - 8 + 38 * 2, CAN_0x142FFF95.SwitcherCtrlCurrent, 3, 0, WHITE);
    updata_DAT(82 + 200 + 20, 100 - 8 + 38 * 3, CAN_0x142FFF95.SwitcherCtrlTemp, 1, 40, WHITE, 3, 0);
    
    print_SZ_1(82 + 200 + 320, 100 - 8 + 38 * 0, CAN_0x142FFF95.SwitcherLife, 3, 0, WHITE);   
    if (CAN_0x142FFF95.SwitcherPumpStatus == 0) {
        LCD_DrawImageString_21x20(82 + 320 + 42 * 6 - 5, 100 + 38 * 1, tingzhi, GREEN, BLACK);
    } else if (CAN_0x142FFF95.SwitcherPumpStatus  == 1) {
        LCD_DrawImageString_21x20(82 + 320 + 42 * 6 - 5, 100 + 38 * 1, gongzuo, GREEN, BLACK);
    } else if (CAN_0x142FFF95.SwitcherPumpStatus  == 2) {
        LCD_DrawImageString_21x20(82 + 320 + 42 * 6 - 5, 100 + 38 * 1, guzhang, GREEN, BLACK);
    }
    print_D(82 + 200 + 300, 100 - 8 + 38 * 2, CAN_0x142FFF95.SwitcherFaultCode, 4, 0, WHITE);
    if (CAN_0x142FFF95.SwitcherCtrlPrechargeStatus == 0) {
        LCD_DrawImageString_21x20(82 + 320 + 42 * 6 - 5, 100 + 38 * 3, weiwancheng, YELLOW, BLACK);
    } else if (CAN_0x142FFF95.SwitcherCtrlPrechargeStatus == 1) {
        LCD_DrawImageString_21x20(82 + 320 + 42 * 6 - 5, 100 + 38 * 3, yiwancheng, GREEN, BLACK);
    }  
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
    const unsigned char *p1_1[10] = {bmsxtxx1, bmsxtxx2, bmsxtxx3, bmsxtxx4, bmsxtxx5, bmsxtxx6, bmsxtxx7, bmsxtxx8, bmsxtxx9, bmsxtxx10};
    const unsigned char *p1_2[10] = {bmsxtxx11, bmsxtxx12, bmsxtxx13, bmsxtxx14, bmsxtxx15, bmsxtxx16, bmsxtxx17, bmsxtxx18, bmsxtxx19, bmsxtxx20};
    const unsigned char *p2_1[10] = {bmsxtxx21, bmsxtxx22, bmsxtxx23, bmsxtxx24};
    const unsigned char *p2_2[10] = {bmsxtxx25, bmsxtxx26, bmsxtxx27};
    const unsigned char *p3_1[10] = {bmsxtxx28, bmsxtxx28, bmsxtxx28, bmsxtxx29, bmsxtxx29, bmsxtxx29};
    const unsigned char *p3_2[10] = {bmsxtxx30, bmsxtxx30, bmsxtxx30, bmsxtxx31, bmsxtxx31, bmsxtxx31};
    LCD_Clear();
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //��������
    LCD_DrawImageSBPP(130 + 200 - 24, 130 - 85, 50, BMS_SYSTEM, WHITE, BLACK); //���

    LCD_DrawRect(80, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320 + 320, 90, 1, 380, GREEN);
    for (i = 0; i < 11; i++)
        LCD_DrawRect(80, 90 + i * 38, 640, 1, GREEN);

    print_SZ_2(750, 50, index, 1, 0, WHITE); // x/3
    LCD_DrawImage1BPP_11x20(750 + 11, 50, BMP_ASIC_11x20[47 - 32], WHITE, BLACK);
    print_SZ_2(750 + 11 + 14, 50, 3, 1, 0, WHITE);

    if (index == 1) {
        for (i = 0; i < 10; i++) {
            LCD_DrawImageString_21x20(82, 100 + 38 * i, p1_1[i], WHITE, BLACK); //
        }
        for (i = 0; i < 10; i++) {
            LCD_DrawImageString_21x20(82 + 320, 100 + 38 * i, p1_2[i], WHITE, BLACK); //
        }

        LCD_DrawImage1BPP_11x20(400 - 24, 100 + 38 * 0, BMP_ASIC_11x20[86 - 32], WHITE, BLACK); //V    
        LCD_DrawImage1BPP_11x20(400 - 24, 100 + 38 * 1, BMP_ASIC_11x20[65 - 32], WHITE, BLACK); //A 
        
        LCD_DrawImage1BPP_11x20(400 - 24, 100 + 38 * 6, BMP_ASIC_11x20[65 - 32], WHITE, BLACK); //A
        LCD_DrawImage1BPP_11x20(400 - 24, 100 + 38 * 7, BMP_ASIC_11x20[65 - 32], WHITE, BLACK); //A
        LCD_DrawImage1BPP(400 - 24, 100 + 38 * 8, BMP_T, WHITE, BLACK); //��
        LCD_DrawImage1BPP(400 - 24, 100 + 38 * 9, BMP_T, WHITE, BLACK); //��
        
        
        LCD_DrawImage1BPP_11x20(400 + 320 - 24, 100 + 38 * 0, BMP_ASIC_11x20[37 - 32], WHITE, BLACK); //%    
        //LCD_DrawImageString_21x20(400 + 320 - 24, 100 + 38 * 2, tian, WHITE, BLACK);
        LCD_DrawImageString_21x20(400 + 320 - 24, 100 + 38 * 8, string_an, WHITE, BLACK);
        LCD_DrawImage1BPP_11x20(400 + 320 - 24, 100 + 38 * 9, BMP_ASIC_11x20[86 - 32], WHITE, BLACK); //V 

    } else if (index == 2) {
        for (i = 0; i < 10; i++) {
            LCD_DrawImageString_21x20(82, 100 + 38 * i, p2_1[i], WHITE, BLACK); //
        }
        for (i = 0; i < 10; i++) {
            LCD_DrawImageString_21x20(82 + 320, 100 + 38 * i, p2_2[i], WHITE, BLACK); //
        }
        LCD_DrawImage1BPP_11x20(400 - 24, 100 + 38 * 0, BMP_ASIC_11x20[86 - 32], WHITE, BLACK); //V
        LCD_DrawImage1BPP(400 - 24, 100 + 38 * 2, BMP_Omu, WHITE, BLACK); //��
        LCD_DrawImage1BPP(400 - 24, 100 + 38 * 3, BMP_Omu, WHITE, BLACK); //��
        
    } else if (index == 3) {
        for (i = 0; i < 10; i++) {
            if (i < 3) {
                print_SZ_1(82 + 21 * 7, 100 - 8 + 38 * i, i + 1, 1, 0, WHITE);
            } else if (i < 6) {
                print_SZ_1(82 + 21 * 6, 100 - 8 + 38 * i, i - 2, 1, 0, WHITE);
            }
            LCD_DrawImageString_21x20(82, 100 + 38 * i, p3_1[i], WHITE, BLACK); //
        }
        for (i = 0; i < 10; i++) {
            if (i < 3) {
                print_SZ_1(82 + 320 + 21 * 8, 100 - 8 + 38 * i, i + 1, 1, 0, WHITE);
            } else if (i < 6) {
                LCD_DrawImage1BPP(400 + 320 - 24, 100 + 38 * i, BMP_T, WHITE, BLACK); //��
                print_SZ_1(82 + 320 + 21 * 4, 100 - 8 + 38 * i, i - 2, 1, 0, WHITE);
            }
            LCD_DrawImageString_21x20(82 + 320, 100 + 38 * i, p3_2[i], WHITE, BLACK); //
        }
    }
}

void BMSUpdate(unsigned char index) {
    unsigned char i;
    if (index == 1) {
#if 1
        print_SZ_1(82 + 200 + 30, 100 - 8, CAN_0x18F13DF3.Voltage * 0.1, 3, 0, WHITE);
        updata_DAT(82 + 200 + 30 - 16, 100 - 8 + 38 * 1, CAN_0x18F13DF3.Current, 0.1, 1000, WHITE, 4, 0);
        if (CAN_0x18F13DF3.BmsCheckout == 0) {
            LCD_DrawImageString_21x20(82 + 42 * 6 - 5, 100 + 38 * 2, wuxiao, GREEN, BLACK);
        } else if (CAN_0x18F13DF3.BmsCheckout == 1) {
            LCD_DrawImageString_21x20(82 + 42 * 6 - 5, 100 + 38 * 2, yuchong, YELLOW, BLACK);
        } else if (CAN_0x18F13DF3.BmsCheckout == 2) {
            LCD_DrawImageString_21x20(82 + 42 * 6 - 5, 100 + 38 * 2, wancheng, YELLOW, BLACK);
        } else if (CAN_0x18F13DF3.BmsCheckout == 3) {
            LCD_DrawImageString_21x20(82 + 42 * 6 - 5, 100 + 38 * 2, jiance, YELLOW, BLACK);
        } else if (CAN_0x18F13DF3.BmsCheckout == 4) {
            LCD_DrawImageString_21x20(82 + 42 * 6 - 5, 100 + 38 * 2, guzhang, YELLOW, BLACK);
        }
        if (CAN_0x18F13DF3.BmsRequest == 2) {
            LCD_DrawImageString_21x20(82 + 42 * 6 - 5, 100 + 38 * 3, wuqingqiu, GREEN, BLACK);
        } else if (CAN_0x18F13DF3.BmsRequest == 3) {
            LCD_DrawImageString_21x20(82 + 42 * 6 - 5, 100 + 38 * 3, youqingqiu, YELLOW, BLACK);
        } 
        print_SZ_1(82 + 200 + 30 - 48, 100 - 8 + 38 * 4, CAN_0x18F13DF3.BmsFaultLevel, 6, 0, WHITE);
        print_D(82 + 200 - 16 * 1, 100 - 8 + 38 * 5, CAN_0x18F13DF3.byte[7], 8, 0, WHITE);              
        updata_DAT(82 + 200 + 30 - 16, 100 - 8 + 38 * 6, CAN_0x18F140F3.LimitChargeCurrent, 0.1, 1000, WHITE, 4, 0);
        updata_DAT(82 + 200 + 30 - 16, 100 - 8 + 38 * 7, CAN_0x18F140F3.LimitDischargeCurrent, 0.1, 1000, WHITE, 4, 0);
        updata_DAT(82 + 200 + 30, 100 - 8 + 38 * 8, CAN_0x18F140F3.LimitHighTemp, 1, 40, WHITE, 3, 0);
        updata_DAT(82 + 200 + 30, 100 - 8 + 38 * 9, CAN_0x18F140F3.LimitLowTemp, 1, 40, WHITE, 3, 0);
        
        
        print_SZ_1(82 + 200 + 320 + 30, 100 - 8 + 38 * 0, CAN_0x18F140F3.LimitSOC * 0.4, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 320 + 30, 100 - 8 + 38 * 1, CAN_0x18F141F3.BmsFaultCode, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 320 + 30, 100 - 8 + 38 * 2, CAN_0x18F141F3.ChargeTime, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 320 + 30, 100 - 8 + 38 * 3, CAN_0x18F141F3.ChargeStatus, 3, 0, WHITE);
        if (CAN_0x18F141F3.BmsBalance == 1) {
            LCD_DrawImageString_21x20(82 + 320 + 42 * 6 - 5, 100 + 38 * 4, youxiao, GREEN, BLACK);
        } else if (CAN_0x18F141F3.BmsBalance == 0) {
            LCD_DrawImageString_21x20(82 + 320 + 42 * 6 - 5, 100 + 38 * 4, wuxiao,RED , BLACK);
        }
       if (CAN_0x18F141F3.ChargeGun == 0x55) {
            LCD_DrawImageString_21x20(82 + 320 + 42 * 6 - 5, 100 + 38 * 5, youxiao, GREEN, BLACK);
        } else if (CAN_0x18F141F3.ChargeGun == 0xAA) {
            LCD_DrawImageString_21x20(82 + 320 + 42 * 6 - 5, 100 + 38 * 5, wuxiao,RED , BLACK);
        }
        print_SZ_1(82 + 200 + 320 + 30, 100 - 8 + 38 * 6, CAN_0x18F141F3.byte[5], 3, 0, WHITE);
        print_SZ_1(82 + 200 + 320 + 30, 100 - 8 + 38 * 7, CAN_0x18F141F3.BmsLife, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 320 + 30, 100 - 8 + 38 * 8, CAN_0x18F148F3.BatAH, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 320 + 30, 100 - 8 + 38 * 9, CAN_0x18F148F3.BatVoltage, 3, 0, WHITE);

#endif
    } else if (index == 2) {
        print_SZ_1(82 + 200 + 30 - 48, 100 - 8 + 38 * 0, CAN_0x18F148F3.BatYear + 1985, 4, 0, WHITE);
        print_SZ_1(82 + 200 + 30 - 48 + 16 * 4, 100 - 8 + 38 * 0, CAN_0x18F148F3.BatMonth, 2, 0, WHITE);
        print_SZ_1(82 + 200 + 30 - 48 + 16 * 6, 100 - 8 + 38 * 0, CAN_0x18F148F3.BatDate, 2, 0, WHITE);
        print_SZ_1(82 + 200 + 30 + 16 * 0, 100 - 8 + 38 * 1, CAN_0x18F746E5.InsulationResisitanceFaultLevel, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 30 - 48, 100 - 8 + 38 * 2, CAN_0x18F746E5.InsulationResistanceP, 6, 0, WHITE);
        print_SZ_1(82 + 200 + 30 - 48, 100 - 8 + 38 * 3, CAN_0x18F746E5.InsulationResistanceN, 6, 0, WHITE);
        
        print_SZ_1(82 + 200 + 30 + 300, 100 - 8 + 38 * 0, CAN_0x18F746E5.InsulationResistanceFaultCode, 4, 0, WHITE);
        print_D(82 + 200 + 30 - 48 + 300, 100 - 8 + 38 * 1, CAN_0x18F746E5.FaultMesg.byte, 8, 0, WHITE);
        print_SZ_1(82 + 200 + 30 + 300, 100 - 8 + 38 * 2, CAN_0x18F746E5.InsulationLife, 4, 0, WHITE);
        
#if 0
        print_SZ_1(82 + 200 + 30, 100 - 8, BMS_Warn_Type, 3, 0, WHITE);
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
        print_SZ_1(82 + 200 + 320 + 30, 100 - 8 + 38 * 5, IM_Life, 3, 0, WHITE);
#endif
    } else if (index == 3) {
        for (i = 0;i < 3; i++) {
            if (FogWarn[i].FogWarnStatus == 1) {
                LCD_DrawImageString_21x20(82 + 42 * 6 - 5, 100 + 38 * i, jiance, YELLOW, BLACK);
            } else if (FogWarn[i].FogWarnStatus == 2) {
                LCD_DrawImageString_21x20(82 + 42 * 6 - 5, 100 + 38 * i, zhengchang, GREEN, BLACK);
            } else if (FogWarn[i].FogWarnStatus == 3) {
                LCD_DrawImageString_21x20(82 + 42 * 6 - 5, 100 + 38 * i, guzhang, RED, BLACK);
            }
        }
        for (i = 0; i < 3; i++) {
            if (FogWarn[i].WarnStatus == 0) {
                LCD_DrawImageString_21x20(82 + 42 * 6 - 5, 100 + 38 * (i + 3), zhengchang, GREEN, BLACK);
            } else if (FogWarn[i].WarnStatus == 1) {
                LCD_DrawImageString_21x20(82 + 42 * 6 - 5, 100 + 38 * (i + 3), guzhang, RED, BLACK);
            }
        }
        for (i = 0; i < 3; i++) {
            if (FogWarn[i].TempWarn == 0) {
                LCD_DrawImageString_21x20(82 + 320 + 42 * 6 - 5, 100 + 38 * i, zhengchang, GREEN, BLACK);
            } else if (FogWarn[i].TempWarn == 1) {
                LCD_DrawImageString_21x20(82 + 320 + 42 * 6 - 5, 100 + 38 * i, guzhang, RED, BLACK);
            }
        }
        for(i=0;i<3;i++){
            updata_DAT(82 + 200 + 300 + 30, 100 - 8 + 38 * (i+3),FogWarn[i].Temp, 1, 40, WHITE, 3, 0);
        }
#if 0
        for (j = 0; j < 2; j++) {
            for (i = 0; i < 10; i++) {
                print_SZ_1(12 + 180 + 390 * j - 5, 100 - 8 + 38 * i, BAT_Pack_Voltage[10 * j + i + 1], 4, 1, WHITE);
                print_SZ_1(12 + 180 + 390 * j - 32 + 16 * 10 + 5, 100 - 8 + 38 * i, BAT_Pack_Number[10 * j + i + 1], 3, 0, WHITE);
            }
        }
#endif
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
        if (index_BMS == 4) {
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
void BATFrame(unsigned char index) {
    unsigned char i, j;
    LCD_Clear();
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //��������
    LCD_DrawImageSBPP(130 + 200 + 24, 130 - 85, 50, Battery_SYSTEM, WHITE, BLACK); //���

    LCD_DrawRect(10, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320 + 320 + 70, 90, 1, 380, GREEN);
    for (i = 0; i < 11; i++)
        LCD_DrawRect(10, 90 + i * 38, 780, 1, GREEN);

    for (j = 0; j < 2; j++) {
        for (i = 0; i < 8; i++) {
            if (i < 4) {
                if (j == 0) {
                    LCD_DrawImageString_21x20(12 + 390 * j + 10, 100 + 38 * i, zgdy, GREEN, BLACK);
                } else {
                    LCD_DrawImageString_21x20(12 + 390 * j + 10, 100 + 38 * i, zddy, GREEN, BLACK);
                }
                LCD_DrawImage1BPP_11x20(330 + 390 * j - 24 - 63 - 17, 100 + 38 * i, BMP_ASIC_11x20[86 - 32], WHITE, BLACK); //V
                LCD_DrawImageString_21x20(12 + 390 * j + 42 * 8.5 + 5, 100 + 38 * i, hao, WHITE, BLACK); //��
                print_SZ_1(12 + 390 * j + 42 * 2 + 10, 100 - 8 + 38 * i, i + 1, 1, 0, GREEN);
            } else {
                if (j == 0) {
                    LCD_DrawImageString_21x20(12 + 390 * j + 10, 100 + 38 * i, zgwd, GREEN, BLACK);
                } else {
                    LCD_DrawImageString_21x20(12 + 390 * j + 10, 100 + 38 * i, zdwd, GREEN, BLACK);
                }
                LCD_DrawImage1BPP(330 + 390 * j - 28 - 63 - 17, 100 + 38 * i, BMP_T, WHITE, BLACK); //��
                print_SZ_1(12 + 390 * j + 42 * 2 + 10, 100 - 8 + 38 * i, i - 3, 1, 0, GREEN);
            }
            LCD_DrawImageString_21x20(12 + 390 * j + 42 * 6.5 + 10, 100 + 38 * i, xiang, WHITE, BLACK); //��
            }
    }   

#if 0
    //�ָ�
    for (i = 0; i < 6; i++) {
        LCD_DrawRect(i * 160, 45 + 70, 1, 360, GRAY);
        LCD_DrawRect(58 + i * 160, 45 + 70, 1, 360, GRAY);
    }
    for (i = 0; i < 13; i++)
        LCD_DrawRect(0, 45 + 70 + i * 36, 800, 1, GRAY);

    //    LCD_DrawImage1BPP(50, 90, BMP_DC, WHITE, BLACK); //���
    //    LCD_DrawImage1BPP(50 + 42, 90, BMP_DY, WHITE, BLACK); //��ѹ
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
                //                LCD_DrawImage1BPP(3 + 16 + 16 + 100 + j * 160, 46 + 70 + i * 36 + 8, BMP_T, YELLOW, BLACK);
            }
        }
    }
#endif
    /*if (index == 6) {
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
}

void BATUpdate(unsigned char index) {
    unsigned char i;
    for (i = 0; i < 4; i++) {
        print_SZ_1(82 + 70 - 16 * 2 + 25, 100 - 8 + 38 * i, BMS_MAX_Cell_Voltage[i], 3, 2, WHITE); //�����ߵ�ѹ
        print_SZ_1(82 + 70 + 16 * 5 + 10, 100 - 8 + 38 * i, BMS_MAX_Cell_Voltage_CaseNum[i], 3, 0, WHITE);
        print_SZ_1(82 + 70 + 16 * 10 + 10, 100 - 8 + 38 * i, BMS_MAX_Cell_Voltage_Num[i], 3, 0, WHITE);
    }
    for (i = 0; i < 4; i++) {
        updata_DAT(82 + 70 - 16 * 1 + 25, 100 - 8 + 38 * (i + 4),BMS_MAX_Temp[i], 1, 40, WHITE, 3, 0); //����¶� 
        print_SZ_1(82 + 70 + 16 * 5 + 10, 100 - 8 + 38 * (i + 4), BMS_MAX_Temp_CaseNum[i], 3, 0, WHITE);
    }

    for (i = 0; i < 4; i++) {
        print_SZ_1(82 + 200 + 260 - 16 * 0, 100 - 8 + 38 * i, BMS_MIN_Cell_Voltage[i], 3, 2, WHITE); //�����ߵ�ѹ
        print_SZ_1(82 + 200 + 260 + 16 * 6, 100 - 8 + 38 * i, BMS_MIN_Cell_Voltage_CaseNum[i], 3, 0, WHITE);
        print_SZ_1(82 + 200 + 260 + 16 * 11, 100 - 8 + 38 * i, BMS_MIN_Cell_Voltage_Num[i], 3, 0, WHITE);
    }
    for (i = 0; i < 4; i++) {
        updata_DAT(82 + 200 + 260 + 16 * 1, 100 - 8 + 38 * (i + 4), BMS_MIN_Temp[i], 1, 40, WHITE, 3, 0); //�����ߵ�ѹ
        print_SZ_1(82 + 200 + 260 + 16 * 6, 100 - 8 + 38 * (i + 4), BMS_MIN_Temp_CaseNum[i], 3, 0, WHITE);
    }
}

void frmBAT(void) {
    static unsigned char index_BAT = 1;
    if (f_index == 0) { //ֻ����һ��
        f_index = 1;
        BATFrame(index_BAT);
    } else if (f_index == 1) {
        f_index = 1;
        BATUpdate(index_BAT);
    } else {
        f_index = 0;
    }
    if (key_up) {
        key_up = 0;
        index_BAT++;
        f_index = 0;
        if (index_BAT >= 2) {
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
void ACFrame(void) {
    unsigned char i = 0;
    const unsigned char *p1_1[10] = {ktxtxx1, ktxtxx2, ktxtxx3};
    const unsigned char *p1_2[10] = {ktxtxx4, ktxtxx5, ktxtxx6};
    LCD_Clear();
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //��������
    LCD_DrawImageSBPP(130 + 200 - 2, 130 - 85, 50, AC_SYSTEM, WHITE, BLACK);

    LCD_DrawRect(80, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320, 90, 1, 380, GREEN);
    LCD_DrawRect(80 + 320 + 320, 90, 1, 380, GREEN);
    for (i = 0; i < 11; i++)
        LCD_DrawRect(80, 90 + i * 38, 640, 1, GREEN);

    for (i = 0; i < 10; i++) {
        LCD_DrawImageString_21x20(82, 100 + 38 * i, p1_1[i], WHITE, BLACK); //
    }
    for (i = 0; i < 10; i++) {
        LCD_DrawImageString_21x20(82 + 320, 100 + 38 * i, p1_2[i], WHITE, BLACK); //
    }
    
    LCD_DrawImage1BPP(400 + 320 - 24, 100 + 38 * 0, BMP_T, WHITE, BLACK);
    LCD_DrawImage1BPP(400 + 320 - 24, 100 + 38 * 1, BMP_T, WHITE, BLACK);
    
}

void ACUpdate(void) {
    print_D(82 + 200 - 16 * 1, 100 - 8 + 38 * 0, CAN_0x18FFC09E.AcSystemFault.byte, 8, 0, WHITE);
    if (CAN_0x18FFC09E.AcFanStatus == 0) {
        LCD_DrawImageString_21x20(82 + 42 * 6 - 5, 100 + 38 * 1, tingzhi, GREEN, BLACK);
    } else if (CAN_0x18F13DF3.BmsCheckout == 1) {
        LCD_DrawImageString_21x20(82 + 42 * 6 - 5, 100 + 38 * 1, disu, YELLOW, BLACK);
    } else if (CAN_0x18F13DF3.BmsCheckout == 2) {
        LCD_DrawImageString_21x20(82 + 42 * 6 - 5, 100 + 38 * 1, zhongsu, YELLOW, BLACK);
    } else if (CAN_0x18F13DF3.BmsCheckout == 4) {
        LCD_DrawImageString_21x20(82 + 42 * 6 - 5, 100 + 38 * 1, gaosu, YELLOW, BLACK);
    }
    print_D(82 + 200 - 16 * 1, 100 - 8 + 38 * 2, CAN_0x18FFC09E.AcSystemStatus, 8, 0, WHITE);

    updata_DAT(82 + 200 + 320 + 30, 100 - 8 + 38 * 0, CAN_0x18FFC09E.AcIndoorTemp, 1, 40, WHITE, 3, 0);
    updata_DAT(82 + 200 + 320 + 30, 100 - 8 + 38 * 1, CAN_0x18FFC09E.AcOutdoorTemp, 1, 40, WHITE, 3, 0);
    print_SZ_1(82 + 200 + 320 + 30, 100 - 8 + 38 * 2, CAN_0x18FFC09E.AcLife, 3, 0, WHITE);

}

void frmAC(void) {
    if (f_index == 0) { //ֻ����һ��
        f_index = 1;
        ACFrame();
    } else if (f_index == 1) {
        f_index = 1;
        ACUpdate();
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
#if 0

void SETFrame(void) {
    LCD_Clear();
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
//������: void frm_speed(void)
//����:  ���ô���
//����:  ȫ�ֱ���
 ******************************************************************************/
void frm_speed(void) {
    if (f_index == 0) {
        f_index = 1;
        key_set = 0;
        key_duble = 0;
        LCD_Clear();
        LCD_DrawRect(0, 0, 800, 50, BLACK);
        LCD_DrawRect(0, 60, 800, 365, BLACK);
        LCD_DrawImageString_21x20(360, 30, cssb, GREEN, BLACK); //�����ٱ�

        LCD_DrawImageString_21x20(340 - 40, 145, subi, YELLOW, BLACK); //
        LCD_DrawImageString_21x20(340 - 40, 200, chesu, YELLOW, BLACK); //
        LCD_DrawImageString_21x20(430, 200, string_km1h, GREEN, BLACK); // /h 

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
//��������
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
    LCD_DrawImage1BPP(360,30,BMP_Chesu, GREEN,BLACK);//����
    LCD_DrawImage1BPP(400,30,BMP_Subi,GREEN,BLACK);//�ٱ�
    
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
    LCD_DrawImageString_21x20(336 + 24, 140, sbsz, color, BLACK); //�ٱ�����
    if (id == 1) color = GREEN;
    else color = WHITE;
    LCD_DrawImage1BPP(300 + 24, 190, BMP_SZ_2[2], color, BLACK);
    LCD_DrawImage1BPP(316 + 24, 190, BMP_SZ_2[10], color, BLACK);
    LCD_DrawImageString_21x20(336 + 24, 190, lcsz, color, BLACK); //�������

    if (id == 2) color = GREEN;
    else color = WHITE;
    LCD_DrawImage1BPP(300 + 24, 240, BMP_SZ_2[3], color, BLACK);
    LCD_DrawImage1BPP(316 + 24, 240, BMP_SZ_2[10], color, BLACK);
    LCD_DrawImageString_21x20(336 + 24, 240, tuichu, color, BLACK); //�˳� 
}

void frm_system(void) {
    static unsigned char ID = 0;
    if (f_index == 0) {
        f_index = 1;
        LCD_DrawRect(0, 60, 800, 365, BLACK);
        LCD_DrawImageString_21x20(360, 30, cssb, GREEN, BLACK); //�����ٱ�
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
        frmID = ID + 32; //�˵��Ŵ�2---7��ʼ 
        if (frmID >= 34)frmID = 0; //���������� 
    }
}

//���������

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

        LCD_DrawImageString_21x20(360, 30, lcsz, GREEN, BLACK); //�������

        LCD_DrawImageString_21x20(200 + 60, 185, zjlc, WHITE, BLACK); //�ܼ���� 

        LCD_DrawImageString_21x20(440 + 60, 187, string_km, WHITE, BLACK); //��λ Km 
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
    LCD_DrawImageString_21x20(360, 30, sbsz, GREEN, BLACK); //�ٱ�����

    LCD_DrawImageString_21x20(300 + 60, 170, sbsz, YELLOW, BLACK); //

    LCD_DrawImage1BPP(210 + 60, 205, BMP_SZ_2[1], YELLOW, BLACK); // 
    LCD_DrawImage1BPP(210 + 60, 245, BMP_SZ_2[2], YELLOW, BLACK); //

    for (i = 0; i < 4; i++) {
        LCD_DrawRect(180 + 60, 120 + 35 + 40 * i, 320, 2, GRAY); //��  
    }
    LCD_DrawRect(180 + 60, 120 + 35, 2, 120, GRAY); //��
    LCD_DrawRect(260 + 60, 120 + 35, 2, 120, GRAY); //
    LCD_DrawRect(380 + 60, 120 + 35, 2, 120, GRAY); //
    LCD_DrawRect(498 + 60, 120 + 35, 2, 120, GRAY); //
}

unsigned int new_pluse = 103;

void update_setDATE(void) {
    unsigned int temp = 0;
    unsigned int x = 180, y = 120;
    print_SZ_2(x + 100 + 60 + 20, y + 85, e_hm_pulse, 3, 0, GREEN); //   
    print_SZ_2(x + 210 + 60 + 30, y + 85, SPEED, 3, 0, GREEN); //����

    //Ŀ��ֵ
    print_SZ_2(x + 100 + 60 + 20, y + 125, new_pluse, 3, 0, RED); // 
    temp = (unsigned int) (SPEED * new_pluse / e_hm_pulse);
    //����
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
        EEROM_WriteHMPulse(); //д��
        EEROM_ReadHMPulse(); //���� У��  
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
            frmDCDC();
            //frmENG();
            break;
        case 4:
            frmDMQ();
            break;
        case 5:
            frmDMY();
            break;
        case 6:
            frmBMS();
            break;
        case 7:
            frmBAT();
            //frmPDH();
            break;
        case 8:
            frmAC();
            break;
        case 9:
            frmIC();
            break;
        case 30:
            frm_speed();
            break;
        case 31:
            frm_system(); //���ò�����Ϣ
            break;
        case 32:
            frm_setDATE(); //���ò�����Ϣ
            break;
        case 33:
            frm_miles(); //���ò�����Ϣ
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



