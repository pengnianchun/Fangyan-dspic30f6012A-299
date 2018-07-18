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
#define  TOTAL_MILES   0L
//单次里程配置
#define  SINGLE_MILES  0
//百米脉冲数
#define  HM_PLUSE     1320
//背光亮度值
#define  BACKLIGHT     750
//定义模块地址 0x01 为前部模块 0x02 为后模块  0x03为顶部模块   0x04为仪表
#define  MT_ADDR       4
//程序版本号
#define  VERISON      200
//是否带视频信号 0不带视频 1带视频
#define  VIDEO         1
//带视频的个数  
#define  VIDEO_NUMBER  2

extern unsigned char Fversion;//前模块版本
extern unsigned char Mversion;//中模块版本
extern unsigned char Rversion;//后模块版本

extern unsigned int Fcan_count; //前部模块CAN
extern unsigned int Rcan_count; //后部模块CAN
extern unsigned int Mcan_count; //中部模块CAN
extern unsigned int Ecan_count; //发动机ECU模块CAN
extern unsigned int Vcan_count; //整车控制器VCU模块CAN
extern unsigned int Bcan_count; //电池管理器BMS模块CAN
extern unsigned int Dcan_count; //转向助力DC/AC模块CAN
extern unsigned int Acan_count; //空调AC模块CAN
extern unsigned int BAT24V_count; //蓄电池低压报警计时

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
        unsigned bit1 : 2;
        unsigned bit2 : 2;
        unsigned bit3 : 2;
        unsigned bit4 : 2;
    };
    unsigned char byte;
} DATA_DOUBLE;

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
#define  time_flag  gKEY[3].bit5
#define  M_ON_flag  gKEY[3].bit6
#define  rLED_flag  gKEY[3].bit7

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

#define  alarm_vcu_flag   gKEY[4].bit1
#define  alarm_mcu_flag   gKEY[4].bit2
#define  alarm_bms_flag   gKEY[4].bit3
#define  M_flag           gKEY[4].bit4


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
#define fKL1    fKEY.BITS.kl1
#define fKL2    fKEY.BITS.kl2
#define fKL3    fKEY.BITS.kl3
#define fKL4    fKEY.BITS.kl4
#define fKL5    fKEY.BITS.kl5
#define fKL6    fKEY.BITS.kl6
#define fKL7    fKEY.BITS.kl7
#define fKL8    fKEY.BITS.kl8
#define fKL9    fKEY.BITS.kl9
#define fKL10   fKEY.BITS.kl10
#define fKL11   fKEY.BITS.kl11
#define fKL12   fKEY.BITS.kl12
#define fKL13   fKEY.BITS.kl13
#define fKL14   fKEY.BITS.kl14
#define fKL15   fKEY.BITS.kl15
#define fKH1    fKEY.BITS.kh1
#define fADD    fKEY.BITS.add

extern DBCM_KEY mKEY; //中（顶）模块功率开关状态
#define mKL1    mKEY.BITS.kl1
#define mKL2    mKEY.BITS.kl2
#define mKL3    mKEY.BITS.kl3
#define mKL4    mKEY.BITS.kl4
#define mKL5    mKEY.BITS.kl5
#define mKL6    mKEY.BITS.kl6
#define mKL7    mKEY.BITS.kl7
#define mKL8    mKEY.BITS.kl8
#define mKL9    mKEY.BITS.kl9
#define mKL10   mKEY.BITS.kl10
#define mKL11   mKEY.BITS.kl11
#define mKL12   mKEY.BITS.kl12
#define mKL13   mKEY.BITS.kl13
#define mKL14   mKEY.BITS.kl14
#define mKL15   mKEY.BITS.kl15
#define mKH1    mKEY.BITS.kh1
#define mADD    mKEY.BITS.add

extern DBCM_KEY rKEY; //后模块功率开关状态
#define rKL1    rKEY.BITS.kl1
#define rKL2    rKEY.BITS.kl2
#define rKL3    rKEY.BITS.kl3
#define rKL4    rKEY.BITS.kl4
#define rKL5    rKEY.BITS.kl5
#define rKL6    rKEY.BITS.kl6
#define rKL7    rKEY.BITS.kl7
#define rKL8    rKEY.BITS.kl8
#define rKL9    rKEY.BITS.kl9
#define rKL10   rKEY.BITS.kl10
#define rKL11   rKEY.BITS.kl11
#define rKL12   rKEY.BITS.kl12
#define rKL13   rKEY.BITS.kl13
#define rKL14   rKEY.BITS.kl14
#define rKL15   rKEY.BITS.kl15
#define rKH1    rKEY.BITS.kh1
#define rADD    rKEY.BITS.add

#define CAN_TIME 30//CAN节点故障报警
#define BAT24_TIME 100//蓄电池电压过低报警10秒

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
extern unsigned char fPF[16]; //前模块功率输出故障
extern unsigned char mPF[16]; //中（顶）模块功率故障
extern unsigned char rPF[16]; //后模块功率输出故障
extern unsigned int fpcur[15]; //前模块功率输出电流
extern unsigned int mpcur[15]; //中模块功率输出电流
extern unsigned int rpcur[15]; //后模块功率输出电流

extern unsigned int ADR[8]; //模拟量采集   2016/10/15
extern unsigned int ADV[8]; //仪表模拟信号采集值 
//extern const unsigned char BMP_LOGO[];
//extern const unsigned char BMP_LOGObmp[];
extern unsigned int pSpeed; //外部CAN换算车速

/**********随州协议变量************/

//整车控制器VCU
//0x0C01F3EF 
extern DATA_DOUBLE   VCU_Status1;
#define  BMS_Connecter       VCU_Status1.bit1
#define  Defrost_EN          VCU_Status1.bit2
#define  Air_EN              VCU_Status1.bit3
#define  Theree_EN           VCU_Status1.bit4
extern unsigned char VCU_LIFE;
//0x18FF01EF
//三合一
extern DATA_DOUBLE   VCU_THREE;
#define  VCU_Charge          VCU_THREE.bit1
#define  DCDC_Status         VCU_THREE.bit2
#define  DCAC_OILStatus      VCU_THREE.bit3
#define  DCAC_AIRStatus      VCU_THREE.bit4
extern unsigned char VCU_READY;
extern unsigned char VCU_Gear;
extern unsigned int  VCU_Speed;
extern unsigned char VCU_Speed_percent; //加速踏板开度
extern unsigned char VCU_Brake_percent; //制动踏板开度
//0x18FF02EF
extern DATA_DOUBLE   VCU_Status2;
#define  Hand_Brake          VCU_Status2.bit1
#define  Foot_Brake          VCU_Status2.bit2
#define  BAT_OFFINE          VCU_Status2.bit3
#define  MCU_OFFINE          VCU_Status2.bit4

//电机控制器MCU
//0x1801F0EF
extern unsigned char MCU_Status;//电机状态
extern unsigned char MCU_Controller_Temp; //TM电机控制器温度
extern unsigned int  MCU_Voltage; //电机输出电压
extern unsigned int  MCU_Current; //电机直流电流
//0x1802F0EF
extern unsigned char MCU_Temp; //电机温度
extern unsigned int  MCU_RPM; //电机转速
extern unsigned int  MCU_NM; //电机扭矩
extern unsigned int  MCU_Power; //电机功率
extern DATA_BIT MCU_Status1;//电机报警
#define  MCU_OverVoltage     MCU_Status1.bit1
#define  MCU_UnderVoltage    MCU_Status1.bit2
#define  MCU_OverCurrent     MCU_Status1.bit3
#define  MCU_Con_OverTemp    MCU_Status1.bit4
#define  MCU_OverTemp        MCU_Status1.bit5
#define  MCU_CAN_Warn        MCU_Status1.bit6
#define  MCU_Fault           MCU_Status1.bit7

//电池信息
//0x0C01EFF3
extern DATA_DOUBLE   BAT_Status1;
extern DATA_DOUBLE   BAT_Status2;
extern unsigned char BMS_Status;
extern unsigned int  BMS_Ohm;
extern unsigned char BMS_Life;
extern unsigned char BMS_SOC;
//0x18FFB0F3
extern unsigned int  BAT_Single_H_Case; //电池单体高电压箱号
extern unsigned int  BAT_Single_H_Number; //电池单体高电压位置
extern unsigned int  BAT_Single_L_Case; //电池单体低电压箱号
extern unsigned char BAT_Single_L_Number; //电池单体低电压位置
//0x18FFB1F3
extern unsigned int  BAT_Temp_H_Case; //电池单体高温度箱号
extern unsigned int  BAT_Temp_H_Number; //电池单体高温度序号
extern unsigned int  BAT_Temp_L_Case; //电池单体低温度箱号
extern unsigned int  BAT_Temp_L_Number; //电池单体低温度序号
//0x18FFB2F3
extern unsigned char BAT_Single_H; //电池单体高电压
extern unsigned char BAT_Single_L; //电池单体低电压
extern unsigned char BAT_Temp_H; //电池单体最高温度
extern unsigned char BAT_Temp_L; //电池单体最低温度
//0x18FF11F3
extern unsigned char BAT_Case; //当前箱号
extern unsigned char BAT_Case_Voltage_Number; //当前箱号电压采集数量
extern unsigned char BAT_Case_Temp_Number; //当前箱号温度采集数量
extern unsigned char BAT_Case_Voltage_H; //当前箱号电池单体最高电压
extern unsigned char BAT_Case_Voltage_L; //当前箱号电池单体最低电压
extern unsigned char BAT_Case_Temp_H; //当前箱号电池单体最高温度
extern unsigned char BAT_Case_Temp_L; //当前箱号电池单体最低温度
//0x18FF13F3
extern unsigned int  BAT_Voltage; //电池总电压
extern unsigned int  BAT_Current ; //电池总电流
extern unsigned char BAT_Temp; //电池平均温度
//0x18FF90F3
extern unsigned char BAT_Charge;
extern unsigned char BAT_DC_Positive;
extern unsigned char BAT_DC_Negative;
extern unsigned char BAT_ChargeGun;
extern unsigned char BAT_Warming;
//0x18FF91F3
extern unsigned char BAT_Warn_Level;
extern DATA_BIT      BAT_Status3;
extern DATA_BIT      BAT_Status4;

//0x1801A79A
extern unsigned long DCDC_Input_Voltage; 
extern unsigned char DCDC_Output_Voltage; 
extern unsigned long DCDC_Output_Current; 
extern unsigned char DCDC_Output_Temp;
extern DATA_BIT      DCDC_Warn; 

//0x1801A79B
extern unsigned long DCAC_Oil_Input_Voltage; 
extern unsigned long DCAC_Oil_Output_Voltage; 
extern unsigned long DCAC_Oil_Output_Current; 
extern unsigned char DCAC_Oil_Output_Temp;
extern DATA_BIT      DCAC_Oil_Warn; 

//0x1801A79D
extern unsigned long DCAC_Air_Input_Voltage; 
extern unsigned long DCAC_Air_Output_Voltage; 
extern unsigned long DCAC_Air_Output_Current; 
extern unsigned char DCAC_Air_Output_Temp;
extern DATA_BIT      DCAC_Air_Warn; 

//故障界面
//0x18FECAEF

//0x18FECAF3



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
    unsigned char bData[42];
} DM1;

extern DM1 CAN_18FECAEF;
extern unsigned char CAN_18FECAEF_len;
extern DM1 CAN_18FECA03;
extern unsigned char CAN_18FECA03_len;
extern DM1 CAN_18FECAF5;
extern unsigned char CAN_18FECAF5_len;
extern DM1 CAN_18FECA00;
extern unsigned char CAN_18FECA00_len;
extern DM1 CAN_18FECAF3;
extern unsigned char CAN_18FECAF3_len;

typedef struct {
    unsigned char pack; //CAN分几包数据传输
    unsigned char flag; //CAN缓存接收完标记
    unsigned char len; //CAN缓存长度
    unsigned char buf[50]; //CAN缓存数组
} CAN_CACHE;
extern CAN_CACHE m_can; //HCU缓存
extern CAN_CACHE n_can; //TCU缓存
extern CAN_CACHE c_can; //CCU缓存
extern CAN_CACHE b_can; //BMS缓存

extern unsigned long SPN[5]; //从缓存里提取的故障码
extern unsigned char FMI[5];
/******************************************************************/


void System_Init(void);
void SYSTME_Logic(void);
void LED_Logic(void);

void BCAN_SendCtl(void);
void PCAN_CCVS(void);
void Count_ADR(void);
void PCAN_send_req(void);
void PCAN_send_mile(void);

/*void DM_HCU(unsigned char x);
void DM_TCU(unsigned char x);
void DM_CCU(unsigned char x);
void DM_ECU(unsigned char x);
void DM_BCU(unsigned char x);*/
void DM(unsigned char x, DM1 id, unsigned char i);
//dispaly
void LCD_Exec(void);
void TIM5_Init(void);
//void TIMER4_Init(void);
/******************************/
/********************************************/

#endif	/* SYSTEM_H */

