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

/*AD驱动程序*/
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

//读取电压值
unsigned int read_VOL(void);
//读取传感器通道值，0=无、1为通道1，以此类推
unsigned int read_ADR(unsigned char chan);

extern unsigned int freq[2];
void INT1_Init(void);
void INT2_Init(void);
void TIMER3_Init(void);

/*
 CAN驱动相关
 */
typedef struct {
    unsigned long id;
    unsigned char data[8];
    unsigned char len;
    unsigned char type;
} CAN_MESSAGE;

void CAN1_Init(void); //波特率 250k 
void CAN1_SendMessage(CAN_MESSAGE *message);
void CAN1_ReceiveMessage(CAN_MESSAGE *message); //中断里面调用

void CAN2_Init(void);
void CAN2_SendMessage(CAN_MESSAGE *message);
void CAN2_ReceiveMessage(CAN_MESSAGE *message);

/*
 EEROM驱动相关
 */
unsigned int EEROM_ReadLowMiles(unsigned long address);
void EEROM_WriteLowMiles(unsigned long address, unsigned int value);
unsigned int EEROM_ReadWord(unsigned long dst);
void EEROM_WriteWord(unsigned long dst, unsigned int val);

/*
 实时时钟驱动相关
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
extern DATE timer; //全局时间变量
void DS3231_ReadTime(DATE *pTime);
void DS3231_SetTime(DATE *pTime);


/*
 步进电机驱动相关
 */
extern unsigned int sm_steps[6];
extern unsigned int sm_new_value[6];
extern unsigned int sm_old_value[6];
extern unsigned char sm_speed[6];

void SM_Init(void);
void SM_Update_0(void); //更新车速表
void SM_Update_1(void); //电压表
void SM_Update_2(void); //机油压力表
void SM_Update_3(void); //油量表
void SM_Update_4(void); //水温表
void SM_Update_5(void); //转速表
void SM_Reset(void); //上点复位归零
void SM_Zero(void); //没有堵转归零

/*
 报警灯相关
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

extern LED_DATA alarm_led[4]; //报警灯全局变量
void LED_Out(void);

#define BUZZ  alarm_led[0].bit0 //蜂鸣器 
#define CS_A  alarm_led[0].bit4 //4051
#define CS_B  alarm_led[0].bit3 
#define CS_C  alarm_led[0].bit2 
#define CS_E  alarm_led[0].bit5 

#define PO1   alarm_led[0].bit6 //功率输出    
#define PO2   alarm_led[0].bit7 //功率输出  

#define LED1  alarm_led[1].bit0 //前门开指示        
#define LED2  alarm_led[1].bit1 //中门开指示                         
#define LED3  alarm_led[1].bit2 //空挡指示  
#define LED4  alarm_led[1].bit3 //左转向报警      
#define LED5  alarm_led[1].bit4 //前进挡指示    
#define LED6  alarm_led[1].bit5 //电量不足报警 
#define LED7  alarm_led[1].bit6 //充电指示  
#define LED8  alarm_led[1].bit7 //右转向报警  
#define LED9  alarm_led[2].bit0 //气压低报警
#define LED10 alarm_led[2].bit1 //总电源指示              
#define LED11 alarm_led[2].bit2 //气压低报警
#define LED12 alarm_led[2].bit3 //SOC报警   
#define LED13 alarm_led[2].bit4 //电机故障报警            
#define LED14 alarm_led[2].bit5 //动力电池故障报警                 
#define LED15 alarm_led[2].bit6 //小灯
#define LED16 alarm_led[2].bit7 //蓄电池充电指示                
#define LED17 alarm_led[3].bit0 //远光灯报警  
#define LED18 alarm_led[3].bit1 //驻车制动报警
#define LED19 alarm_led[3].bit2 //前雾灯报警
#define LED20 alarm_led[3].bit3 //后雾灯报警
#define LED21 alarm_led[3].bit4 //倒车灯
#define LED22 alarm_led[3].bit5 //近光灯报警 
#define LED23 alarm_led[3].bit6 //缓速器报警               
#define LED24 alarm_led[3].bit7 //刹车指示

/*
 开关采集驱动相关
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

extern SW_DATA sw_input[5]; //开关采集全局变量
void SW_Input(void);

#define IN1   sw_input[0].bit0     //开关
#define IN2   !sw_input[0].bit1     //开关
#define IN3   !sw_input[0].bit2     //开关
#define IN4   !sw_input[0].bit3     //开关
#define IN5   sw_input[0].bit4     //开关
#define IN6   sw_input[0].bit5     //开关
#define IN7   sw_input[0].bit6     //开关
#define IN8   sw_input[0].bit7     //信号
#define IN9   sw_input[1].bit0     //信号
#define IN10  sw_input[1].bit1     //开关
#define IN11  sw_input[1].bit2     //开关
#define IN12  sw_input[1].bit3     //
#define IN13  sw_input[1].bit4     //
#define IN14  sw_input[1].bit5     //左刹车蹄片磨损报警开关   控火，断开报警
#define IN15  sw_input[1].bit6     //右刹车蹄片磨损报警开关 
#define IN16  sw_input[1].bit7     //
#define IN17  sw_input[2].bit0     //
#define IN18  sw_input[2].bit1     //气压1报警开关
#define IN19  sw_input[2].bit2     //气压2报警开关
#define IN20  sw_input[2].bit3     //水位报警灯开关
#define IN21  sw_input[2].bit4     //倒档灯信号
#define IN22  sw_input[2].bit5     //空滤堵塞报警开关
#define IN23  sw_input[2].bit6     //后仓门开启开关
#define IN24  sw_input[2].bit7     //干燥器工作信号
#define IN25  sw_input[3].bit0     //ASR指示
#define IN26  sw_input[3].bit1     //排气制动指示
#define IN27  sw_input[3].bit2     //ABS指示
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
#define wake_up1  !sw_input[4].bit5      // 唤醒（危险报警）
#define wake_up2  !sw_input[4].bit6      //	唤醒
#define wake_up3  !sw_input[4].bit7      // ON档

/*
 LCD 驱动相关
 */
#define  BLACK      0X00   //黑色
#define  BLUE       0X03   //亮蓝 0X03
#define  GREEN      0X1C   //亮绿 0X1C
#define  CYAN       0x1F   //亮青
#define  RED        0xE0   //亮红
#define  MAGENTA    0xE3   //亮紫
#define  YELLOW     0xFC  //亮黄
#define  WHITE      0XFF  //白色 0XFF
#define  GRAY       0x49   //灰度
#define  ORANGE     0xF0  //橙色
//2016-10-31 修改1-DAV 2-AV1 6-AV2 
void LCD_CHS(unsigned char mode); //改变模拟、数字通道 1-AV2 2-MCU 4-AV1  修改为1-DAV 2-AV1 6-AV2 
void LCD_BackLight(unsigned char back); //LCD背关亮度控制 0-7 0关闭 7最亮
void LCD_Clear(void); //清屏 屏变黑色
void LCD_Init(void); //初始化 
void LCD_DrawImage1BPP(unsigned int x, unsigned int y,
        __prog__ const unsigned char *img,
        unsigned char fcolor, unsigned char bcolor); //写图片，8点写，效率高
void LCD_DrawImage1BPPZOOM_1(unsigned int x, unsigned int y,
        __prog__ const unsigned char *img,
        unsigned char fcolor, unsigned char bcolor); //写图片，1点写，效率低
void LCD_DrawImage1BPPZOOM_4(unsigned int x, unsigned int y,
        __prog__ const unsigned char *img,
        unsigned char fcolor, unsigned char bcolor); //写图片，放大4倍，单点写 
void LCD_DrawRect(unsigned int x, unsigned int y, //W的值为0时，会溢出
        unsigned int w, unsigned int h, unsigned char color); //画矩形

#define lcd_show_8dot    LCD_DrawImage1BPP 
#define lcd_show_8dot5   LCD_DrawImage1BPP 
#define lcd_show_1color  LCD_DrawRect
#define lcd_clear_8dot   LCD_DrawRect

/*
 定时器相关
 */
void TIMER1_Init(void); //滴答时钟 //10ms 中断
void BL_Init(void); //仪表小灯背光初始化


#endif	/* BSP_H */

