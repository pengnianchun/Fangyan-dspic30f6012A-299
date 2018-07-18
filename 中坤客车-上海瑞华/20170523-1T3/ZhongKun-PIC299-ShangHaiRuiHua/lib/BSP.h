/* 
 * File:   bsp.h
 * Author: mpszm
 *
 * Created 
 */

#ifndef BSP_H
#define	BSP_H

#include <xc.h>
#define FCY 16000000
#include <libpic30.h>

/*AD��������*/
#define AD_E_DR  TRISBbits.TRISB5
#define AD_A_DR  TRISBbits.TRISB2
#define AD_B_DR  TRISBbits.TRISB3
#define AD_C_DR  TRISBbits.TRISB4

#define AD_E LATBbits.LATB5
#define AD_A LATBbits.LATB2
#define AD_B LATBbits.LATB3
#define AD_C LATBbits.LATB4

void ADC_Init(void);
unsigned int ADC_Read(unsigned char chs);

//��ȡ��ѹֵ
unsigned int read_VOL(void);
//��ȡ������ͨ��ֵ��0=�ޡ�1Ϊͨ��1���Դ�����
unsigned int read_ADR(unsigned char chan);

extern unsigned int freq[2];
void INT1_Init(void);
void INT2_Init(void);
void TIMER3_Init(void);

/*
 CAN�������
 */
typedef struct {
    unsigned long id;
    unsigned char data[8];
    unsigned char len;
    unsigned char type;
} CAN_MESSAGE;

void CAN1_Init(void); //������ 250k 
void CAN1_SendMessage(CAN_MESSAGE *message);
void CAN1_ReceiveMessage(CAN_MESSAGE *message); //�ж��������

void CAN2_Init(void);
void CAN2_SendMessage(CAN_MESSAGE *message);
void CAN2_ReceiveMessage(CAN_MESSAGE *message);

/*
 EEROM�������
 */
unsigned int EEROM_ReadLowMiles(unsigned long address);
void EEROM_WriteLowMiles(unsigned long address, unsigned int value);
unsigned int EEROM_ReadWord(unsigned long dst);
void EEROM_WriteWord(unsigned long dst, unsigned int val);

/*
 ʵʱʱ���������
 */
typedef union {

    struct {
        unsigned char second; //[00]
        unsigned char minute; //[01]
        unsigned char hour; //[02]
        unsigned char week; //[03]
        unsigned char day; //[04]
        unsigned char month; //[05]
        unsigned char year; //[06]
    };
    unsigned char byte[7];
} DATE;
extern DATE timer; //ȫ��ʱ�����
void DS3231_ReadTime(DATE *pTime);
void DS3231_SetTime(DATE *pTime);


/*
 ��������������
 */
extern unsigned int sm_steps[6];
extern unsigned int sm_new_value[6];
extern unsigned int sm_old_value[6];
extern unsigned char sm_speed[6];

void SM_Init(void);
void SM_Update_0(void); //���³��ٱ�
void SM_Update_1(void); //��ѹ��
void SM_Update_2(void); //����ѹ����
void SM_Update_3(void); //������
void SM_Update_4(void); //ˮ�±�
void SM_Update_5(void); //ת�ٱ�
void SM_Reset(void); //�ϵ㸴λ����
void SM_Zero(void); //û�ж�ת����

/*
 ���������
 */
typedef union {

    struct {
        unsigned bit0 : 1;
        unsigned bit1 : 1;
        unsigned bit2 : 1;
        unsigned bit3 : 1;
        unsigned bit4 : 1;
        unsigned bit5 : 1;
        unsigned bit6 : 1;
        unsigned bit7 : 1;
    };
    unsigned char byte;
} LED_DATA;

extern LED_DATA alarm_led[4]; //������ȫ�ֱ���
void LED_Out(void);

#define BUZZ  alarm_led[0].bit0 //������ 
#define CS_A  alarm_led[0].bit4 //4051
#define CS_B  alarm_led[0].bit3 
#define CS_C  alarm_led[0].bit2 
#define CS_E  alarm_led[0].bit5 

#define PO1   alarm_led[0].bit6 //�������    
#define PO2   alarm_led[0].bit7 //�������  

#define LED1  alarm_led[1].bit0 //ǰ�ſ�ָʾ        
#define LED2  alarm_led[1].bit1 //���ſ�ָʾ                         
#define LED3  alarm_led[1].bit2 //�յ�ָʾ  
#define LED4  alarm_led[1].bit3 //��ת�򱨾�      
#define LED5  alarm_led[1].bit4 //ǰ����ָʾ    
#define LED6  alarm_led[1].bit5 //�������㱨�� 
#define LED7  alarm_led[1].bit6 //���ָʾ  
#define LED8  alarm_led[1].bit7 //��ת�򱨾�  
#define LED9  alarm_led[2].bit0 //��ѹ�ͱ���
#define LED10 alarm_led[2].bit1 //�ܵ�Դָʾ              
#define LED11 alarm_led[2].bit2 //��ѹ�ͱ���
#define LED12 alarm_led[2].bit3 //SOC����   
#define LED13 alarm_led[2].bit4 //������ϱ���            
#define LED14 alarm_led[2].bit5 //������ع��ϱ���                 
#define LED15 alarm_led[2].bit6 //С��
#define LED16 alarm_led[2].bit7 //���س��ָʾ                
#define LED17 alarm_led[3].bit0 //Զ��Ʊ���  
#define LED18 alarm_led[3].bit1 //פ���ƶ�����
#define LED19 alarm_led[3].bit2 //ǰ��Ʊ���
#define LED20 alarm_led[3].bit3 //����Ʊ���
#define LED21 alarm_led[3].bit4 //������
#define LED22 alarm_led[3].bit5 //����Ʊ��� 
#define LED23 alarm_led[3].bit6 //����������               
#define LED24 alarm_led[3].bit7 //ɲ��ָʾ

/*
 ���زɼ��������
 */
typedef union {

    struct {
        unsigned bit0 : 1;
        unsigned bit1 : 1;
        unsigned bit2 : 1;
        unsigned bit3 : 1;
        unsigned bit4 : 1;
        unsigned bit5 : 1;
        unsigned bit6 : 1;
        unsigned bit7 : 1;
    };
    unsigned char byte;
} SW_DATA;

extern SW_DATA sw_input[5]; //���زɼ�ȫ�ֱ���
void SW_Input(void);

#define IN1   sw_input[0].bit0     //����
#define IN2   !sw_input[0].bit1     //����
#define IN3   !sw_input[0].bit2     //����
#define IN4   !sw_input[0].bit3     //����
#define IN5   sw_input[0].bit4     //����
#define IN6   sw_input[0].bit5     //����
#define IN7   sw_input[0].bit6     //����
#define IN8   sw_input[0].bit7     //�ź�
#define IN9   sw_input[1].bit0     //�ź�
#define IN10  sw_input[1].bit1     //����
#define IN11  sw_input[1].bit2     //����
#define IN12  sw_input[1].bit3     //
#define IN13  sw_input[1].bit4     //
#define IN14  sw_input[1].bit5     //��ɲ����Ƭĥ�𱨾�����   �ػ𣬶Ͽ�����
#define IN15  sw_input[1].bit6     //��ɲ����Ƭĥ�𱨾����� 
#define IN16  sw_input[1].bit7     //
#define IN17  sw_input[2].bit0     //
#define IN18  sw_input[2].bit1     //��ѹ1��������
#define IN19  sw_input[2].bit2     //��ѹ2��������
#define IN20  sw_input[2].bit3     //ˮλ�����ƿ���
#define IN21  sw_input[2].bit4     //�������ź�
#define IN22  sw_input[2].bit5     //���˶�����������
#define IN23  sw_input[2].bit6     //����ſ�������
#define IN24  sw_input[2].bit7     //�����������ź�
#define IN25  sw_input[3].bit0     //ASRָʾ
#define IN26  sw_input[3].bit1     //�����ƶ�ָʾ
#define IN27  sw_input[3].bit2     //ABSָʾ
#define IN28  sw_input[3].bit3     //
#define IN29  sw_input[3].bit4     //
#define IN30  sw_input[3].bit5     //
#define IN31  sw_input[3].bit6     //
#define IN32  sw_input[3].bit7     //
#define IN33  sw_input[4].bit0      //
#define IN34  sw_input[4].bit1      //
#define IN35  sw_input[4].bit2      //
#define IN36  sw_input[4].bit3      //
#define IN37  sw_input[4].bit4      //
#define wake_up1  !sw_input[4].bit5      // ���ѣ�Σ�ձ�����
#define wake_up2  !sw_input[4].bit6      //	����
#define wake_up3  !sw_input[4].bit7      // ON��

/*
 LCD �������
 */
#define  BLACK      0X00   //��ɫ
#define  BLUE       0X03   //���� 0X03
#define  GREEN      0X1C   //���� 0X1C
#define  CYAN       0x1F   //����
#define  RED        0xE0   //����
#define  MAGENTA    0xE3   //����
#define  YELLOW     0xFC  //����
#define  WHITE      0XFF  //��ɫ 0XFF
#define  GRAY       0x49   //�Ҷ�
#define  ORANGE     0xF0  //��ɫ
//2016-10-31 �޸�1-DAV 2-AV1 6-AV2 
void LCD_CHS(unsigned char mode); //�ı�ģ�⡢����ͨ�� 1-AV2 2-MCU 4-AV1  �޸�Ϊ1-DAV 2-AV1 6-AV2 
void LCD_BackLight(unsigned char back); //LCD�������ȿ��� 0-7 0�ر� 7����
void LCD_Clear(void); //���� �����ɫ
void LCD_Init(void); //��ʼ�� 
void LCD_DrawImage1BPP(unsigned int x, unsigned int y,
        __prog__ const unsigned char *img,
        unsigned char fcolor, unsigned char bcolor); //дͼƬ��8��д��Ч�ʸ�
void LCD_DrawImage1BPPZOOM_1(unsigned int x, unsigned int y,
        __prog__ const unsigned char *img,
        unsigned char fcolor, unsigned char bcolor); //дͼƬ��1��д��Ч�ʵ�
void LCD_DrawImage1BPPZOOM_4(unsigned int x, unsigned int y,
        __prog__ const unsigned char *img,
        unsigned char fcolor, unsigned char bcolor); //дͼƬ���Ŵ�4��������д 
void LCD_DrawRect(unsigned int x, unsigned int y, //W��ֵΪ0ʱ�������
        unsigned int w, unsigned int h, unsigned char color); //������

#define lcd_show_8dot    LCD_DrawImage1BPP 
#define lcd_show_8dot5   LCD_DrawImage1BPP 
#define lcd_show_1color  LCD_DrawRect
#define lcd_clear_8dot   LCD_DrawRect

/*
 ��ʱ�����
 */
void TIMER1_Init(void); //�δ�ʱ�� //10ms �ж�
void BL_Init(void); //�Ǳ�С�Ʊ����ʼ��


#endif	/* BSP_H */

