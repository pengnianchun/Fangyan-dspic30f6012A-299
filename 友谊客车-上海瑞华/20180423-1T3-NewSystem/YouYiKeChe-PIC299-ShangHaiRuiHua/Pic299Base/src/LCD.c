#include "BSP.h"
//2016-10-31�޸�LCD���л���ʾ������ǰ�� 1-AV2   2-MCU   4-AV1�޸�Ϊ
//1-DAV 2-AV1 6-AV2


#define LCD_WR_DR   _TRISF5
#define LCD_RD_DR   _TRISF4
#define LCD_CS_DR   _TRISG3 
#define LCD_RS_DR   _TRISG2

#define LCD_DATA_DR  TRISB

#define LCD_WR   _LATF5
#define LCD_RD   _LATF4
#define LCD_CS   _LATG3 
#define LCD_RS   _LATG2

#define LCD_DATA     LATB
#define LCD_DATA_RD  PORTB

static void write_cmd(unsigned char cmd) {
    *((unsigned char *) &LCD_DATA_DR + 1) = 0x00;
    LCD_CS = 0;
    Nop();
    LCD_RS = 0;
    Nop();
    *((unsigned char *) &LCD_DATA + 1) = cmd;
    Nop();
    LCD_WR = 0;
    Nop();
    LCD_WR = 1;
    Nop();
    LCD_CS = 1;
    Nop();
    LCD_RS = 1;
}

static void write_data(unsigned char dat) {
    *((unsigned char *) &LCD_DATA_DR + 1) = 0x00;
    LCD_CS = 0;
    Nop();
    LCD_RS = 1;
    Nop();
    *((unsigned char *) &LCD_DATA + 1) = dat;
    Nop();
    LCD_WR = 0;
    Nop();
    LCD_WR = 1;
    Nop();
    LCD_CS = 1;
    Nop();
    LCD_RS = 0;
}

static unsigned char read_data(void) {
    unsigned char dump;
    *((unsigned char *) &LCD_DATA_DR + 1) = 0xFF;
    LCD_CS = 0;
    Nop();
    LCD_RS = 0;
    Nop();
    LCD_RD = 0;
    Nop();
    dump = *((unsigned char *) &LCD_DATA_RD + 1);
    LCD_RD = 1;
    Nop();
    LCD_CS = 1;
    Nop();
    LCD_RS = 0;
    Nop();
    return dump;
}


//�ı�ģ�⡢����ͨ��
//1-DAV 2-AV1 6-AV2
void LCD_CHS(unsigned char mode) {
    __delay_us(100);
    write_cmd(0x04);
    write_data(mode);
    __delay_us(100);
}

void LCD_BackLight(unsigned char back) {
    write_cmd(0x05);
    write_data(0x07 & back);
}

void LCD_Clear(void) {
    write_cmd(0x00);
    write_data(0x00);

    write_cmd(0x01);
    write_data(0x00);

    write_cmd(0x07);
    write_data(0x00); //����ɫ

    write_cmd(0x06);
    write_data(0x00); //ǰ��ɫ

    write_cmd(0x32);
    write_data(0x00);
    while (read_data() != 0x00);
}

void LCD_Init(void) {

    ADPCFG |= 0xFF00; //��ʼ��Һ�����˿�ΪIO��
    LCD_WR_DR = 0;
    LCD_RD_DR = 0;
    LCD_CS_DR = 0;
    LCD_RS_DR = 0;

    LCD_WR = 1;
    LCD_RD = 1;
    LCD_CS = 1;
    LCD_RS = 1;

    __delay_us(1000);
      
    write_cmd(0x00);
    write_data(0x00);

    write_cmd(0x01);
    write_data(0x00);

    __delay_us(50);
    LCD_CHS(0x01); //�л���MCUģʽ 
    __delay_us(50);

    LCD_BackLight(0x00); //������С

    LCD_Clear();

}

//******************************************************
//��ʾһ����ɫͼƬ
//******************************************************

void LCD_DrawFcolor(unsigned char color) {
    write_cmd(0x06);
    write_data(color); //ǰ��ɫ
}

void LCD_DrawBcolor(unsigned char color) {
    write_cmd(0x07);
    write_data(color); //����ɫ
}

void LCD_DrawPoint(unsigned int x, unsigned int y, unsigned char color) {
    write_cmd((unsigned char) ((x >> 4) & 0xF0));
    write_data((unsigned char) x);

    write_cmd((unsigned char) ((y >> 4) & 0xF0) | 0x01);
    write_data((unsigned char) y);

    write_cmd(0x02);
    write_data(color);
}

void LCD_Draw8Point(unsigned int x, unsigned int y, unsigned char dat) {

    //�������д��8�㣬��λΪ0д�뱳��ɫ�� Ϊ1д��ǰ��ɫ
    write_cmd((unsigned char) ((x >> 4) & 0xF0));
    write_data((unsigned char) x);

    write_cmd((unsigned char) ((y >> 4) & 0xF0) | 0x01);
    write_data((unsigned char) y);

    write_cmd(0x12);
    write_data(dat);
}

void LCD_DrawMPoint(unsigned int x, unsigned int y, unsigned int mpoint) {

    //�������д��8�㣬��λΪ0д�뱳��ɫ�� Ϊ1д��ǰ��ɫ
     write_cmd((unsigned char) ((x >> 4) & 0xF0));
     write_data((unsigned char) x);
     
     write_cmd((unsigned char) ((y >> 4) & 0xF0) | 0x01);
     write_data((unsigned char) y);
    
    
     while (mpoint > 0xff){ 
     mpoint=mpoint-0xff;  
     write_cmd(0x22);  
     write_data(0xff);
     __delay_us(20);
     x=x+0xff; 
     write_cmd((unsigned char) ((x >> 4) & 0xF0));
     write_data((unsigned char) x);
    }
     
     if(mpoint==0) return;
     write_cmd(0x22);   
     write_data(mpoint); 
     __delay_us(20);
}


void LCD_DrawImage1BPP(unsigned int x, unsigned int y,
        __prog__ const unsigned char *img,
        unsigned char fcolor, unsigned char bcolor) {

    write_cmd(0x06);
    write_data(fcolor); //ǰ��ɫ

    write_cmd(0x07);
    write_data(bcolor); //����ɫ

    //unsigned int wp;
    unsigned int hp, wb;
    //wp = *img++;
    hp = *img++;
    wb = *img++;

    unsigned int i, j;

    for (i = 0; i < hp; i++) {
        write_cmd((unsigned char) ((x >> 4) & 0xF0));
        write_data((unsigned char) x);

        write_cmd((unsigned char) ((y >> 4) & 0xF0) | 0x01);
        write_data((unsigned char) y);

        write_cmd(0x12); //8��д��ʽ 
        for (j = 0; j < wb; j++) {
            write_data(*img++); //д����  
            __delay_us(20);
        }
        y++;
    }
}

void LCD_DrawImage1BPPZOOM_1(unsigned int x, unsigned int y,
        __prog__ const unsigned char *img,
        unsigned char fcolor, unsigned char bcolor) {

    write_cmd(0x06);
    write_data(fcolor); //ǰ��ɫ

    write_cmd(0x07);
    write_data(bcolor); //����ɫ

    //unsigned int wp;
    unsigned int hp, wb;
    //wp = *img++;
    hp = *img++;
    wb = *img++;

    unsigned int i, j, k;

    for (i = 0; i < hp; i++) {
        write_cmd((unsigned char) ((x >> 4) & 0xF0));
        write_data((unsigned char) x);

        write_cmd((unsigned char) ((y >> 4) & 0xF0) | 0x01);
        write_data((unsigned char) y);

        write_cmd(0x02); //1��д��ʽ 

        unsigned char dump;

        for (j = 0; j < wb; j++) {
            dump = *img++;
            for (k = 0; k < 8; k++) {
                if ((dump & 0x80) == 0x80) {
                    write_data(fcolor);
                } else {
                    write_data(bcolor);
                }
                dump <<= 1;
            }

        }
        y++;
    }
}

void LCD_DrawImage1BPPZOOM_4(unsigned int x, unsigned int y,
        __prog__ const unsigned char *img,
        unsigned char fcolor, unsigned char bcolor) {
    unsigned int dx;

    dx = x;
    write_cmd(0x06);
    write_data(fcolor); //ǰ��ɫ
    write_cmd(0x07);
    write_data(bcolor); //����ɫ

    //unsigned int wp;
    unsigned int hp, wb;
    //wp = *img++;
    hp = *img++;
    wb = *img++;

    unsigned int i, j, k;

    for (i = 0; i < hp; i++) {
        unsigned char dump;
        for (j = 0; j < wb; j++) {
            dump = *img++;
            for (k = 0; k < 8; k++) {
                if ((dump & 0x80) == 0x80) {
                    LCD_DrawPoint(x + k * 2, y, fcolor);
                    LCD_DrawPoint(x + k * 2 + 1, y, fcolor);
                    LCD_DrawPoint(x + k * 2, y + 1, fcolor);
                    LCD_DrawPoint(x + k * 2 + 1, y + 1, fcolor);
                } else {
                    LCD_DrawPoint(x + k * 2, y, bcolor);
                    LCD_DrawPoint(x + k * 2 + 1, y, bcolor);
                    LCD_DrawPoint(x + k * 2, y + 1, bcolor);
                    LCD_DrawPoint(x + k * 2 + 1, y + 1, bcolor);
                }
                dump <<= 1;
            }
            x = x + 16;
        }
        x = dx;
        y += 2;
    }
}

void LCD_DrawRect(unsigned int x, unsigned int y,
        unsigned int w, unsigned int h, unsigned char color) {

    write_cmd(0x06);
    write_data(color); //ǰ��

    unsigned int i;
    
    for (i = 0; i < h; i++) {
      LCD_DrawMPoint(x,y,w); 
      y++;
    }

}

//void LCD_ShowPic(unsigned int x, unsigned char y, unsigned int w, unsigned char h, 
//        __prog__ const unsigned char *ptr) {
//    unsigned int j = 0, i = 0;
//    for (i = 0; i < h; i++) {
//
//        write_cmd(0x01);
//        write_data(y++);
//
//        if (x > 0xff)
//            write_cmd(0x10); //
//        else
//            write_cmd(0x00);
//        write_data((unsigned char) x);
//
//        write_cmd(0x02);
//        for (j = 0; j < w; j++) {
//            write_data(*ptr++);
//        }
//    }
//}


//
//void lcd_show_2color(unsigned int x, unsigned char y, unsigned int w, unsigned char h, const unsigned char *ptr, unsigned char fcolor, unsigned char bcolor) {
//    unsigned int j = 0, i = 0;
//    unsigned char s = 0, data = 0;
//    unsigned char ts = 0;
//
//    for (i = 0; i < h; i++) {
//        write_cmd(0x01);
//        write_data(y++);
//        if (x > 0xff) write_cmd(0x10); //
//        else write_cmd(0x00);
//        ts = (unsigned char) x;
//        write_data(ts);
//
//        write_cmd(0x02); //����д��ʽ
//        for (j = 0; j < w; j++) {
//            data = *ptr++;
//            for (s = 0; s < 8; s++) {
//                if ((data << s) & 0x80) write_data(fcolor); //д����     
//                else write_data(bcolor); //д����
//            }
//        }
//    } //end write
//} //end	
//
////******************************************************
////��ʾһ����ɫ�����Ϳ�,
////******************************************************
//
//void lcd_show_1color(unsigned int x, unsigned char y, unsigned int w, unsigned char h, unsigned char color) {
//    unsigned int j = 0, i = 0;
//    for (i = 0; i < h; i++) {
//        if (x > 0xff)
//            write_cmd(0x10); //
//        else
//            write_cmd(0x00);
//        write_data((unsigned char) (x));
//        write_cmd(0x01);
//        write_data(y + i);
//        write_cmd(0x02);
//        for (j = 0; j < w; j++) {
//            write_data(color);
//        }
//    }
//}
//
////��һ������8dot�ı����ĳ���������д��color��ɫ
//
//void lcd_clear_8dot(unsigned int x, unsigned char y, unsigned int w, unsigned char h, unsigned char color) {
//    unsigned int j = 0, i = 0;
//
//    write_cmd(0x06);
//    write_data(color); //ǰ��ɫ
//    write_cmd(0x07);
//    write_data(color); //����ɫ
//
//    for (i = 0; i < h; i++) {
//        if (x > 0xff)
//            write_cmd(0x10); //
//        else
//            write_cmd(0x00);
//        write_data((unsigned char) (x));
//        write_cmd(0x01);
//        write_data(y + i);
//
//        write_cmd(0x12); //8��д��ʽ
//        for (j = 0; j < w; j++) {
//            write_data(0xff);
//        }
//    }
//}
//
//void lcd_show_8dot(unsigned int x, unsigned char y,
//        unsigned int w, unsigned char h,
//        const unsigned char *ptr,
//        unsigned char fcolor, unsigned char bcolor) {
//    unsigned int j = 0, i = 0;
//    unsigned char ts = 0;
//
//    write_cmd(0x06);
//    write_data(fcolor); //ǰ��ɫ
//
//    write_cmd(0x07);
//    write_data(bcolor); //����ɫ
//
//
//    for (i = 0; i < h; i++) {
//        write_cmd(0x01);
//        write_data(y++);
//        if (x > 0xff) write_cmd(0x10); //
//        else write_cmd(0x00);
//        ts = (unsigned char) x;
//        write_data(ts);
//
//        write_cmd(0x12); //8��д��ʽ
//        for (j = 0; j < w; j++) {
//            write_data(*ptr++); //д����     
//        }
//    } //end write
//}
//

void LCD_DrawImage1BPP_21x20(unsigned int x, unsigned int y,
        __prog__ const unsigned char *img,
        unsigned char fcolor, unsigned char bcolor) {

    write_cmd(0x06);
    write_data(fcolor); //ǰ��ɫ

    write_cmd(0x07);
    write_data(bcolor); //����ɫ   

    unsigned int i, j;

    for (i = 0; i < 20; i++) {
        write_cmd((unsigned char) ((x >> 4) & 0xF0));
        write_data((unsigned char) x);

        write_cmd((unsigned char) ((y >> 4) & 0xF0) | 0x01);
        write_data((unsigned char) y);

        write_cmd(0x12); //8��д��ʽ 
        for (j = 0; j < 3; j++) {
            write_data(*img++); //д����  
            __delay_us(20);
        }
        y++;
    }
}

void LCD_DrawImage1BPP_11x20(unsigned int x, unsigned int y,
        __prog__ const unsigned char *img,
        unsigned char fcolor, unsigned char bcolor) {

    write_cmd(0x06);
    write_data(fcolor); //ǰ��ɫ

    write_cmd(0x07);
    write_data(bcolor); //����ɫ   

    unsigned int i, j;

    for (i = 0; i < 20; i++) {
        write_cmd((unsigned char) ((x >> 4) & 0xF0));
        write_data((unsigned char) x);

        write_cmd((unsigned char) ((y >> 4) & 0xF0) | 0x01);
        write_data((unsigned char) y);

        write_cmd(0x12); //8��д��ʽ 
        for (j = 0; j < 2; j++) {
            write_data(*img++); //д����  
            __delay_us(20);
        }
        y++;
    }
}