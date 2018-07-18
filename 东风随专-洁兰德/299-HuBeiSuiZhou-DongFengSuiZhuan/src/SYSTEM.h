/* 
 * File:   SYSTEM.h
 * Author: mpszm
 *
 * Created on 2016年8月1日, 下午2:50
 */

#ifndef SYSTEM_H
#define	SYSTEM_H

#include <xc.h>
#include "bsp.h"


//系统EEPROM配置字
//总里程配置
#define  TOTAL_MILES   2000L
//单次里程配置
#define  SINGLE_MILES  2000
//百米脉冲数
#define  HM_PLUSE     1320
//背光亮度值
#define  BACKLIGHT     750
//定义模块地址 0x01 为前部模块 0x02 为后模块  0x03为顶部模块   0x04为仪表
#define  MT_ADDR      4


extern unsigned long e_total_miles;
extern unsigned int e_address; //EEPROM存储地址
extern unsigned int e_single_miles;
extern unsigned int e_backlight;
extern unsigned int e_hm_pulse;
void EEROM_WriteBackLight(void);
void EEROM_ReadBackLight(void);
void EEROM_WriteHMPulse(void);
void EEROM_ReadHMPulse(void);
void EEROM_WriteSingleMiles(void);
void EEROM_ReadSingleMiles(void);
void EEROM_WriteTotalMiles(void);
void EEROM_ReadTotalMiles(void);
void EEROM_WriteAddress(void);
void EEROM_ReadAddress(void);

extern unsigned int single_miles;
extern unsigned long total_miles;

/*按键控制接口 */
#define KEY_AV       _RD11       //S1
#define KEY_AV_DR    _TRISD11

#define KEY_SET        _RD10      //S2
#define KEY_SET_DR     _TRISD10

#define KEY_UP         _RD7       //S6
#define KEY_UP_DR      _TRISD7

//仪表主供电电源控制端口
#define PWR_CTRL_DR   _TRISG13  
#define PWR_CTRL      _LATG13
#define PWR_CTRL_RD   _RG13

//蜂鸣器端口

typedef union {
    unsigned char BYTES[2];
    unsigned int WORDS;

    struct {
        unsigned char O1 : 1;
        unsigned char O2 : 1;
        unsigned char O3 : 1;
        unsigned char O4 : 1;
        unsigned char O5 : 1;
        unsigned char O6 : 1;
        unsigned char O7 : 1;
        unsigned char O8 : 1;
        unsigned char O9 : 1;
        unsigned char O10 : 1;
        unsigned char O11 : 1;
        unsigned char O12 : 1;
        unsigned char O13 : 1;
        unsigned char O14 : 1;
        unsigned char O15 : 1;
        unsigned OD : 1;
    } BITS;
} DBCM_POUT;

typedef union {

    struct {
        unsigned kl1 : 1;
        unsigned kl2 : 1;
        unsigned kl3 : 1;
        unsigned kl4 : 1;
        unsigned kl5 : 1;
        unsigned kl6 : 1;
        unsigned kl7 : 1;
        unsigned kl8 : 1;

        unsigned kl9 : 1;
        unsigned kl10 : 1;
        unsigned kl11 : 1;
        unsigned kl12 : 1;
        unsigned kl13 : 1;
        unsigned kl14 : 1;
        unsigned kl15 : 1;
        unsigned : 1;

        unsigned kh1 : 1;
        unsigned add : 1;
        unsigned : 6;
    } BITS;
    unsigned char BYTES[3];
} DBCM_KEY;

typedef union {

    struct {
        unsigned bit1 : 1;
        unsigned bit2 : 1;
        unsigned bit3 : 1;
        unsigned bit4 : 1;
        unsigned bit5 : 1;
        unsigned bit6 : 1;
        unsigned bit7 : 1;
        unsigned bit8 : 1;
    };
    unsigned char byte;
} DATA_BIT;

extern DATA_BIT gKEY[5];

#define  key_set     gKEY[0].bit1 
#define  pkey_set    gKEY[0].bit2 
#define  bkey_set    gKEY[0].bit3

#define  key_up      gKEY[0].bit4
#define  pkey_up     gKEY[0].bit5  
#define  bkey_up     gKEY[0].bit6

#define  key_AV      gKEY[0].bit7
#define  pkey_AV     gKEY[0].bit8
#define  bkey_AV     gKEY[1].bit1

#define  key_duble   gKEY[1].bit2

#define  F50ms       gKEY[1].bit3
#define  F100ms      gKEY[1].bit4
#define  F500ms      gKEY[1].bit5  
#define  F500ms_LCD  gKEY[1].bit6 //lcd显示更新时间
#define  alarm_update_flag  gKEY[1].bit7//报警显示更新时间

#define  F300ms     gKEY[3].bit1 // 2016/10/22新增更新时间
#define  F400ms     gKEY[3].bit2
#define  F1000ms    gKEY[3].bit3
#define  FLASH_3s   gKEY[3].bit4

#define  CLR_single_miles gKEY[1].bit7
#define  save_flag        gKEY[1].bit8
#define  key_long_set     gKEY[2].bit1
#define  M_ON             gKEY[2].bit2  
#define  kFLASH           gKEY[2].bit3
#define  FLASH            gKEY[2].bit4 //转向灯闪烁标志
#define  FLASH_1s         gKEY[2].bit5 

#define  DM1_CLEAR        gKEY[2].bit6 
#define  R_flag           gKEY[2].bit7
#define  bLCD_RESET       gKEY[2].bit8


extern DATA_BIT gCTL[8]; //仪表输出控制信息
#define F_PO1   gCTL[0].bit1
#define F_PO2   gCTL[0].bit2
#define F_PO3   gCTL[0].bit3
#define F_PO4   gCTL[0].bit4
#define F_PO5   gCTL[0].bit5
#define F_PO6   gCTL[0].bit6
#define F_PO7   gCTL[0].bit7
#define F_PO8   gCTL[0].bit8 
#define F_PO9   gCTL[1].bit1
#define F_PO10  gCTL[1].bit2
#define F_PO11  gCTL[1].bit3
#define F_PO12  gCTL[1].bit4
#define F_PO13  gCTL[1].bit5
#define F_PO14  gCTL[1].bit6
#define F_PO15  gCTL[1].bit7
#define F_PO16  gCTL[1].bit8  /////

#define M_PO1  gCTL[2].bit1
#define M_PO2  gCTL[2].bit2
#define M_PO3  gCTL[2].bit3
#define M_PO4  gCTL[2].bit4
#define M_PO5  gCTL[2].bit5
#define M_PO6  gCTL[2].bit6
#define M_PO7  gCTL[2].bit7
#define M_PO8  gCTL[2].bit8 
#define M_PO9   gCTL[3].bit1
#define M_PO10  gCTL[3].bit2
#define M_PO11  gCTL[3].bit3
#define M_PO12  gCTL[3].bit4
#define M_PO13  gCTL[3].bit5
#define M_PO14  gCTL[3].bit6
#define M_PO15  gCTL[3].bit7
#define M_PO16  gCTL[3].bit8  /////

#define R_PO1  gCTL[4].bit1
#define R_PO2  gCTL[4].bit2
#define R_PO3  gCTL[4].bit3
#define R_PO4  gCTL[4].bit4
#define R_PO5  gCTL[4].bit5
#define R_PO6  gCTL[4].bit6
#define R_PO7  gCTL[4].bit7
#define R_PO8  gCTL[4].bit8 
#define R_PO9   gCTL[5].bit1
#define R_PO10  gCTL[5].bit2
#define R_PO11  gCTL[5].bit3
#define R_PO12  gCTL[5].bit4
#define R_PO13  gCTL[5].bit5
#define R_PO14  gCTL[5].bit6
#define R_PO15  gCTL[5].bit7
#define R_PO16  gCTL[5].bit8  /////

extern DBCM_KEY fKEY; //前模块功率开关状态
extern DBCM_KEY mKEY; //中（顶）模块功率开关状态
extern DBCM_KEY rKEY; //后模块功率开关状态
extern unsigned int fFreq; //前模块频率
extern unsigned int mFreq; //中（顶）模块频率
extern unsigned int rFreq; //后模块频率
extern unsigned int fSpeed; //前模块折算车速
extern unsigned int mSpeed; //中（顶）模块折算车速
extern unsigned int rSpeed; //后模块折算车速
extern unsigned int fADR[2]; //前模块电阻值
extern unsigned int mADR[2]; //中（顶）模块电阻值
extern unsigned int rADR[2]; //后模块电阻值
extern DBCM_POUT fPOUT; //前模块功率输出状态
extern DBCM_POUT mPOUT; //中（顶）模块功率输出状态
extern DBCM_POUT rPOUT; //后模块功率输出状态
extern unsigned char fPF[15]; //前模块功率输出故障
extern unsigned char mPF[15]; //中（顶）模块功率故障
extern unsigned char rPF[15]; //后模块功率输出故障

extern unsigned int ADR[8]; //模拟量采集   2016/10/15
extern const unsigned char BMP_LOGO[];
extern const unsigned char BMP_LOGObmp[];

/**********随州协议变量************/


extern unsigned char moto_voltage; //电机电压
extern unsigned char moto_current; //电机电流
extern unsigned char moto_speed; //电动转速
extern unsigned char battle_t; //电池均温
extern unsigned char Inverter_t; //逆变器温度
extern unsigned char battle_t_warn; //电池过温报警
extern unsigned char battle_jueyuan_warn; //绝缘过低报警
extern unsigned char battle_higtv1_warn; //高压电池1故障
extern unsigned char battle_higtv2_warn; //高压电池2故障
extern unsigned char moto_t_warn; //电机过温
extern unsigned char moto_ready; //ready信号
extern unsigned char xudc; //蓄电池异常
extern unsigned char moto_warn; //电机故障

extern unsigned char BMS_offline_warn; //电池不在线
extern unsigned char MCU_offline_warn; //电机不在线
extern unsigned char TCU_offline_warn; //变速箱不在线
extern unsigned char Engine_offline_warn; //发动机不在线
extern unsigned char Engine_wait; //发动机怠速
extern unsigned char EV; //模式
extern unsigned char Signal_charge; //充电信号
extern unsigned char BMS_V; //电池电压
extern unsigned char BMS_SOC; //电池SOC
extern unsigned char BMS_A; //电池电流

extern unsigned char mil_lamp_request; //黄色三级报警
extern unsigned char fail_mode; //文字报警
extern unsigned char mil_buzz_request; //蜂鸣器响
extern unsigned long hcu_spn; //HCU故障码
extern unsigned char hcu_fmi;

extern unsigned int Speed_rmp; //输出轴转速
extern unsigned char Eng_static_test; //发动机稳态转速测试
extern unsigned char tcu_start_allow; //发动机运行启动

extern unsigned char Current_Gear; //档位

extern unsigned char Lamp_status_YELLOW; //变速箱黄灯状态
extern unsigned char Lamp_status_RED; //变速箱红灯状态
extern unsigned long tcu_spn; //TCU故障码
extern unsigned char tcu_fmi;

extern unsigned long ccu_spn; //CCU故障码
extern unsigned char ccu_fmi;

extern unsigned long ecu_spn; //ECU故障码
extern unsigned char ecu_fmi;

extern unsigned char Brake_percent; //踏板开度

extern unsigned char Motor_Temperature; //电机温度

extern unsigned int ENG_start_req; //仪表控制启动
extern unsigned long mot_work_time; //电机工作累积时间
extern unsigned char mot_work_percent; //电机工作时间比
extern unsigned char DCDC_ctrl; //DCDC状态
extern unsigned char hcu_starter_forbid; //起动机工作
extern unsigned char aircompress_enable; //压缩机
extern unsigned char Brake_Pedal; //刹车信号
extern unsigned char Speed_lim_mode;//限速模式
extern unsigned char Accelerator; //油门开度

extern unsigned char water_temp;//水温

extern unsigned int  Engine_oil_press;//机油压力
extern unsigned char water_level;//水位

extern unsigned char Wait_start;//等待启动
extern unsigned char Maintain_warn;//维护报警
extern unsigned char Stop_warn;//停机报警
extern unsigned char Engine_warn;//发动机故障

extern unsigned int EngineSpeed;//发动机转速

extern unsigned char ambient_air_temperature;//周围空气温度

extern unsigned int pSpeed; //外部CAN换算车速

/*****************分包处理CAN*****************/

typedef union {

    struct {
        unsigned long SPN1 : 19;
        unsigned FMI : 5;
        unsigned CM : 1;
        unsigned OC : 7;
    }; //这个结构需要验证
    unsigned char bData[4];
} DTC;

typedef union {

    struct {
        unsigned ProtectLampStatus : 2;
        unsigned AmberWarningLampStatus : 2;
        unsigned RedStopLampState : 2;
        unsigned MalfunctionIndicatorLampStatus : 2;
        unsigned FlashProtectLamp : 2;
        unsigned FlashAmberWarningLamp : 2;
        unsigned FlashRedStopLamp : 2;
        unsigned FlashMalfunctionIndicatorLamp : 2;
        DTC DTC1;
        DTC DTC2;
        DTC DTC3;
        DTC DTC4;
        DTC DTC5;
    };
    unsigned char bData[22];
} DM1;

extern DM1 CAN_18FECAEF;
extern unsigned char CAN_18FECAEF_len;
extern DM1 CAN_18FECA03;
extern unsigned char CAN_18FECA03_len;
extern DM1 CAN_18FECAF5;
extern unsigned char CAN_18FECAF5_len;
extern DM1 CAN_18FECA00;
extern unsigned char CAN_18FECA00_len;

typedef struct {
    unsigned char pack; //CAN分几包数据传输
    unsigned char flag; //CAN缓存接收完标记
    unsigned char len; //CAN缓存长度
    unsigned char buf[50]; //CAN缓存数组
} CAN_CACHE;
extern CAN_CACHE m_can;//HCU缓存
extern CAN_CACHE n_can;//TCU缓存
extern CAN_CACHE c_can;//CCU缓存


/******************************************************************/

#define BCM_F_KL1  fKEY.BITS.kl1
#define BCM_F_KL2  fKEY.BITS.kl2

#define BCM_M_KL2  mKEY.BITS.kl2

#define CAN_TIME 30


void System_Init(void);
void SYSTME_Logic(void);
void LED_Logic(void);

void BCAN_SendCtl(void);
void PCAN_CCVS(void);
void Count_ADR(void);
void PCAN_send_req(void);
void PCAN_send_mile(void);

void DM_HCU(unsigned char x);
void DM_TCU(unsigned char x);
void DM_CCU(unsigned char x);
void DM_ECU(unsigned char x);
//dispaly
void LCD_Exec(void);

//void TIMER4_Init(void);

#endif	/* SYSTEM_H */

