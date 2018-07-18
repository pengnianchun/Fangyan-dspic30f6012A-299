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
#define  HM_PLUSE      1320
//背光亮度值
#define  BACKLIGHT     750
//定义模块地址 0x01 为前部模块 0x02 为后模块  0x03为顶部模块   0x04为仪表
#define  MT_ADDR       4
//程序版本号
#define  VERISON       200
//对接日期
#define  TIME          20180329L
//对接日期
#define  NULL          (void*)0

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

extern unsigned int M_PO11_count; //输出10秒计时

extern unsigned int delay_cnt;

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

extern unsigned char frmID;

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

#define  key_set          gKEY[0].bit1 
#define  pkey_set         gKEY[0].bit2 
#define  bkey_set         gKEY[0].bit3
#define  key_up           gKEY[0].bit4
#define  pkey_up          gKEY[0].bit5  
#define  bkey_up          gKEY[0].bit6
#define  key_AV           gKEY[0].bit7
#define  pkey_AV          gKEY[0].bit8

#define  bkey_AV          gKEY[1].bit1
#define  key_duble        gKEY[1].bit2
#define  F50ms            gKEY[1].bit3
#define  F100ms           gKEY[1].bit4
#define  F500ms           gKEY[1].bit5  
#define  F500ms_LCD       gKEY[1].bit6 //lcd显示更新时间
#define  alarm_update_flag  gKEY[1].bit7//报警显示更新时间
//#define  CLR_single_miles gKEY[1].bit7
#define  save_flag        gKEY[1].bit8

#define  key_long_set     gKEY[2].bit1
#define  M_ON             gKEY[2].bit2  
#define  kFLASH           gKEY[2].bit3
#define  FLASH            gKEY[2].bit4 //转向灯闪烁标志
#define  FLASH_1s         gKEY[2].bit5 
#define  DM1_CLEAR        gKEY[2].bit6 
#define  R_flag           gKEY[2].bit7
#define  bLCD_RESET       gKEY[2].bit8

#define  F300ms           gKEY[3].bit1 // 2016/10/22新增更新时间
#define  F400ms           gKEY[3].bit2
#define  F1000ms          gKEY[3].bit3
#define  FLASH_3s         gKEY[3].bit4
#define  time_flag        gKEY[3].bit5
#define  M_ON_flag        gKEY[3].bit6
#define  rLED_flag        gKEY[3].bit7
#define  F5s              gKEY[3].bit8

#define  F10min           gKEY[4].bit1
#define  F_DISP           gKEY[4].bit2
#define  F_20s            gKEY[4].bit3
#define  F_20s_flag       gKEY[4].bit4
#define  F_3              gKEY[4].bit4



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
extern unsigned int fpcur[15];//前模块功率输出电流
extern unsigned int mpcur[15];//中模块功率输出电流
extern unsigned int rpcur[15];//后模块功率输出电流

extern unsigned int ADR[8]; //模拟量采集   10/15
extern unsigned int ADV[8]; //模拟量采集 

extern unsigned int pSpeed; //外部CAN换算车速
//extern const unsigned char BMP_LOGO[];
//extern const unsigned char BMP_LOGObmp[];

/*************************************/
/*typedef struct {

    struct {
        unsigned char : 3;
        unsigned char DMC_Level : 2; //电机控制器故障级别
        unsigned char DMC_Status : 3; //电机控制器基本状态

        unsigned char DMC_Life; //电机生命
        unsigned int  DMC_Torque; //电机转矩
        unsigned int  DMC_Rpm; //电机转速
        unsigned char DMC_Speed; //车速
        unsigned char DMC_Gear; //档位
    } ID_1002FF1E;
    
    struct {
        unsigned int  DMC_Voltage; //电机控制器母线电压
        unsigned int  DMC_Current; //电机控制器母线电流
        unsigned char DMC_Controller_temp; //电机控制器温度
        unsigned char DMC_Moto_temp; //电机温度
        unsigned char DMC_Protect_code; //电机控制器故障代码
        unsigned char DMC_Verison; //电机控制器版本号
    } ID_1003FF1E;
    
} CAN_SIGNAL_TYPE_S;

extern CAN_SIGNAL_TYPE_S CAN_SIGNAL;*/
//电机
extern unsigned char DMC_Status;//电机控制器基本状态
extern unsigned char DMC_Level;//电机控制器故障级别
extern unsigned char DMC_Life;//电机生命
extern unsigned int  DMC_Torque;//电机转矩
extern unsigned int  DMC_Rpm;//电机转速
extern unsigned char DMC_Speed;//车速
extern unsigned char DMC_Gear;//档位

extern unsigned int  DMC_Voltage;//电机控制器母线电压
extern unsigned int  DMC_Current;//电机控制器母线电流
extern unsigned char DMC_Controller_temp;//电机控制器温度
extern unsigned char DMC_Moto_temp;//电机温度
extern unsigned char DMC_Protect_code;//电机控制器保护代码
extern unsigned char DMC_Verison;//电机控制器版本号

extern unsigned char DMC_Accelerator_percent;//油门踏板开度
extern unsigned char DMC_Brake_percent;//制动踏板开度
extern unsigned char DMC_Charge;//充放电状态
extern unsigned char DMC_GB_Gear; //国标档位

//气泵控制器
extern unsigned int  DMQ_Rpm;//气泵控制器电机转速
extern unsigned int  DMQ_Voltage;//气泵控制器母线电压
extern unsigned char DMQ_Current;//气泵控制器电机母线电流
extern unsigned char DMQ_temp; //气泵温度
extern unsigned char DMQ_Controller_temp;//气泵控制器温度
extern unsigned char DMQ_Life;//气泵控制器生命
extern unsigned char DMQ_Status;//气泵控制器基本状态

//DCDC
extern unsigned char DCDC_Status;//DCDC基本状态
extern unsigned char DCDC_Temp;//DCDC模块温度
extern unsigned int  DCDC_Voltage;//DCDC输出电压
extern unsigned int  DCDC_Current;//DCDC输出电流
extern unsigned char DCDC_Code;//DCDC故障代码
extern unsigned char DCDC_Verison;//DCDC版本号

//油泵控制器
extern unsigned int  DMY_Rpm;//油泵控制器电机转速
extern unsigned int  DMY_Voltage;//油泵控制器母线电压
extern unsigned char DMY_Current;//油泵控制器电机母线电流
extern unsigned char DMY_Controller_temp;//油泵控制器温度
extern unsigned char DMY_Life;//油泵控制器生命
extern unsigned char DMY_Status;//油泵控制器基本状态

//空调
extern unsigned char Air_Status_Flag1; //空调状态1
extern unsigned char Air_Status_Flag2; //空调状态2
extern unsigned char Air_Status_Flag3; //空调状态3
extern unsigned char Air_Indoor_t; //室内温度
extern unsigned char Air_Outdoor_t; //室外温度
extern unsigned char Air_Set_t; //设定

//BMS
extern unsigned char BMS_Type;//BMS参数类型
extern unsigned char Battery_Case_Total_Number;//电池箱体个数
extern unsigned char BMS_Unit_Number;//电池管理系统从控单元个数
extern unsigned int  Battery_Cell_Total_Number;//电池总串数
extern unsigned int  BMS_Nubmer;//电池管理系统编号

extern unsigned char Battery_Case_number;//电池箱号n
extern unsigned char Battery_Cell_number;//电池箱n内电池串数
extern unsigned char Battery_Cell_Temp_Number;//电池箱内电池温度探头个数

extern unsigned int  BMS_V;//电池总电压
extern unsigned int  BMS_A;//电池总电流
extern unsigned char BMS_SOC;//电池SOC
extern unsigned char BMS_Life;//BMS LIFE
extern unsigned char BMS_Status_Flag1;//电池状态1
extern unsigned char BMS_Status_Flag2;//电池状态2

extern unsigned int  Battery_Single_H; //电池单体高电压
extern unsigned int  Battery_Single_L; //电池单体低电压
extern unsigned char Battery_Temp_H; //电池单体最高温度
extern unsigned char Battery_Temp_L; //电池单体最低温度
extern unsigned char BMS_Status_Flag3;//电池状态3
extern unsigned char BMS_Status_Flag4;//继电器状态

extern unsigned char Battery_Single_H_Positon_Case; //电池单体高电压箱号
extern unsigned char Battery_Single_H_Positon_Cell; //电池单体高电压位置
extern unsigned char Battery_Single_L_Positon_Case; //电池单体低电压箱号
extern unsigned char Battery_Single_L_Positon_Cell; //电池单体低电压位置
extern unsigned char Battery_Temp_H_Positon_Case; //电池单体高温度箱号
extern unsigned char Battery_Temp_H_Positon_Cell; //电池单体高温度位置
extern unsigned char Battery_Temp_L_Positon_Case; //电池单体低温度箱号
extern unsigned char Battery_Temp_L_Positon_Cell; //电池单体低温度位置

extern DATA_BIT      BMU_Comm_Status[4];//1-8   BMU通讯状态
/*extern unsigned char BMU_Comm_Status2;//9-16  BMU通讯状态
extern unsigned char BMU_Comm_Status3;//17-24 BMU通讯状态
extern unsigned char BMU_Comm_Status4; //25-32 BMU通讯状态*/

extern DATA_BIT      BMU_Bala_Status[4]; //1-8   BMU均衡状态
/*extern unsigned char BMU_Bala_Status2; //9-16  BMU均衡状态
extern unsigned char BMU_Bala_Status3; //17-24 BMU均衡状态
extern unsigned char BMU_Bala_Status4; //25-32 BMU均衡状态*/

extern unsigned char DC1positive_Temp;//充电插头DC1+温度
extern unsigned char DC1negative_Temp;//充电插头DC1-温度
extern unsigned char DC2positive_Temp;//充电插头DC2+温度
extern unsigned char DC2negative_Temp;//充电插头DC2-温度
extern unsigned int  Ohm_Positive;//总正绝缘阻值 
extern unsigned int  Ohm_Negative;//总负绝缘阻值 

extern unsigned int  Energe_Rest;//剩余能量
extern unsigned char BMS_Status_Flag5;
extern unsigned char BMS_Status_Flag6;

extern unsigned char Battery_Single_H_Positon_Total;//最高单体电压位置（总数）
extern unsigned char Battery_Single_L_Positon_Total;//最低单体电压位置（总数）
extern unsigned char Battery_Temp_H_Positon_Total;//最高单体温度位置（总数）
extern unsigned char Battery_Temp_L_Positon_Total;//最低单体温度位置（总数）
extern unsigned char Battery_Single_H_Pack;//最高单体电压包号
extern unsigned char Battery_Single_L_Pack;//最低单体电压包号
extern unsigned char Battery_Temp_H_Pack;//最高单体温度包号
extern unsigned char Battery_Temp_L_Pack;//最低单体温度包号

extern unsigned char BMU_Number;//BMU号

extern unsigned char Battery_Pack; //电池报文包数
extern unsigned int  Battery_Voltage[12]; //电池单体电压
extern unsigned int  Battery_Temp[12]; //电池单体温度


/******************************************************************************/
extern unsigned int  BMS_Status;
extern unsigned char Battery_Temp_avg; //电池单体平均温度
extern unsigned char Battery_Oum_Status; 

extern unsigned char BMS_Charge_Status; 
extern unsigned char BMS_Warn; 
extern unsigned char BMS_Fault_Number; 

extern unsigned char KT; 

/******************************************************************************/
#pragma pack(1)

typedef union {

    struct {
        unsigned MotoVoltage; //电机输入电压
        unsigned MotoCurrent; //电机输入电流
        unsigned char MotorControllerTemperature; //电机温度
        unsigned char MotorTemperature; //电机温度   
        unsigned char MotorControllerLife;  
        unsigned char CANVerison;  
    };
    unsigned char byte[8];
} _CAN_0x10F811A4;

typedef union {

    struct {
        unsigned char MotorFaultNumber;
        unsigned char MotorSquence;
        unsigned char MotorStatus;
        unsigned MotoSpeed; //电机转速
        unsigned MotoTorque; //电机转矩
        unsigned char Reserve;
    };
    unsigned char byte[8];
} _CAN_0x10F813A4;

typedef union {

    struct {
        unsigned char Reserve1 : 1;
        unsigned char VCUEnInsulation : 3;
        unsigned char KT : 4;
        unsigned char Reserve2;
        unsigned char Reserve3;
        unsigned char Reserve4;
        unsigned char Reserve5;
        unsigned char Reserve6;
        unsigned char Reserve7;
        unsigned char Reserve8;
    };
    unsigned char byte[8];
} _CAN_0x0C109E27;

typedef union {

    struct {
        unsigned char Reserve1 : 3;
        unsigned char BMSFaultLevel : 2;
        unsigned char BMSStatus : 3;
        unsigned char BATAverageTemp;
        unsigned char BMS_SOC; //电池SOC
        unsigned BMS_A; //电池电流
        unsigned BMS_V; //电池电压     
        unsigned char Reserve2;
    };
    unsigned char byte[8];
} _CAN_0x10F8159E;

typedef union {

    struct {
        unsigned char BAT_Min_Cell_Temperature; //最低单体温度
        unsigned char BAT_Min_Cell_Temp_Cell_Case; //最低单体温度箱号 
        unsigned char BAT_Min_Cell_Temp_Cell_Number; //最低单体温度位置
        unsigned char Reserve1;
        unsigned char BAT_SMin_Cell_Temperature; //最次低单体温度
        unsigned char BAT_SMin_Cell_Temp_Cell_Case; //最次低单体温度箱号 
        unsigned char BAT_SMin_Cell_Temp_Cell_Number; //最次低单体温度位置
        unsigned char Reserve2;
    };
    unsigned char byte[8];
} _CAN_0x10F8179E;

typedef union {

    struct {
        unsigned char BAT_Max_Cell_Temperature; //最高单体温度
        unsigned char BAT_Max_Cell_Temp_Cell_Case; //最高单体温度箱号 
        unsigned char BAT_Max_Cell_Temp_Cell_Number; //最高单体温度位置
        unsigned char Reserve1;
        unsigned char BAT_SMax_Cell_Temperature; //最次高单体温度
        unsigned char BAT_SMax_Cell_Temp_Cell_Case; //最次高单体温度箱号 
        unsigned char BAT_SMax_Cell_Temp_Cell_Number; //最次高单体温度位置
        unsigned char Reserve2;
    };
    unsigned char byte[8];
} _CAN_0x18F8189E;

typedef union {

    struct {
        unsigned BAT_Min_Cell_Voltage; //最低单体电压
        unsigned char BAT_Min_Cell_Voltage_Cell_Number; //最低单体电压位置
        unsigned char BAT_Min_Cell_Voltage_Cell_Case; //最低单体电压箱号       
        unsigned BAT_SMin_Cell_Voltage; //最次低单体电压
        unsigned char BAT_SMin_Cell_Voltage_Cell_Number; //最次低单体电压位置
        unsigned char BAT_SMin_Cell_Voltage_Cell_Case; //最次低单体电压箱号         
    };
    unsigned char byte[8];
} _CAN_0x18F8199E;

typedef union {

    struct {
        unsigned BAT_Max_Cell_Voltage; //最高单体电压
        unsigned char BAT_Max_Cell_Voltage_Cell_Number; //最高单体电压位置
        unsigned char BAT_Max_Cell_Voltage_Cell_Case; //最高单体电压箱号       
        unsigned BAT_SMax_Cell_Voltage; //最次高单体电压
        unsigned char BAT_SMax_Cell_Voltage_Cell_Number; //最次高单体电压位置
        unsigned char BAT_SMax_Cell_Voltage_Cell_Case; //最次高单体电压箱号         
    };
    unsigned char byte[8];
} _CAN_0x18F81B9E;

typedef union {

    struct {
        unsigned char BMSFaultNumber;     
        unsigned BATRestEnerge; //电池剩余能量
        unsigned BATCellTotalNumber;//电池总串数
        unsigned char Reserve1;
        unsigned char Reserve2;
        unsigned char CANVerison;
    };
    unsigned char byte[8];
} _CAN_0x10F8209E;

typedef union {

    struct {
        unsigned long BMSWarningFlag;   
        unsigned char Reserve1;
        unsigned char ChargeStatus;
        unsigned Ohm_Positive;
    };
    unsigned char byte[8];
} _CAN_0x10F8219E; 

typedef union {

    struct {
        unsigned char BATCaseNumber;  
        unsigned char BATCellNumber;  
        unsigned BATTempNumber;  
        unsigned BATVoltage;  
        unsigned BATCurrent;
    };
    unsigned char byte[8];
} _CAN_0x10F8239E;

typedef union {

    struct {
        unsigned char VCULife;
        unsigned char ChargeStatus : 2;
        unsigned char Door : 1;
        unsigned char Key : 2;       
        unsigned char READY : 1;
        unsigned char Reserve1 : 2;
        unsigned char VCUFaultCode;
        unsigned char VCUSpeed;
        unsigned long VCUTotalMile;
    };
    unsigned char byte[8];
} _CAN_0x18F81F27;

typedef union {

    struct {
        unsigned char AcceleratePedal;
        unsigned char Reserve1;
        unsigned char Reserve2;
        unsigned char Reserve3;
        unsigned char Reserve4;
        unsigned char Reserve5;
        unsigned char Reserve6;
        unsigned char BrakePedal;
    };
    unsigned char byte[8];
} _CAN_0x18F80227;
#pragma pack()

extern _CAN_0x10F811A4 CAN_0x10F811A4;
extern _CAN_0x10F813A4 CAN_0x10F813A4;
extern _CAN_0x0C109E27 CAN_0x0C109E27;
extern _CAN_0x10F8159E CAN_0x10F8159E;
extern _CAN_0x10F8179E CAN_0x10F8179E;
extern _CAN_0x18F8189E CAN_0x18F8189E;
extern _CAN_0x18F8199E CAN_0x18F8199E;
extern _CAN_0x18F81B9E CAN_0x18F81B9E;
extern _CAN_0x10F8209E CAN_0x10F8209E;
extern _CAN_0x10F8219E CAN_0x10F8219E;
extern _CAN_0x10F8239E CAN_0x10F8239E;
extern _CAN_0x18F81F27 CAN_0x18F81F27;
extern _CAN_0x18F80227 CAN_0x18F80227;

extern unsigned char BATCellNumber; 
extern unsigned char BATCellTemp[20][7]; 
extern unsigned char BATCellVoltage[200];
/******************************************************************************/

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




void System_Init(void);
void SYSTME_Logic(void);
void LED_Logic(void);

void BCAN_SendCtl(void);
void PCAN_CCVS(void);
void Count_ADR(void);
void PCAN_send_req(void);
void PCAN_send_mile(void);
char Count_Time(unsigned char condition, //启动条件
        unsigned int  out_time,           //条件满足，工作时间
        unsigned char cycle_en,           //是否循环执行
        unsigned int  stop_time           //循环执行时，间歇时间
        );

void DM_HCU(unsigned char x);
void DM_TCU(unsigned char x);
void DM_CCU(unsigned char x);
void DM_ECU(unsigned char x);
//dispaly
void LCD_Exec(void);
//void TIMER4_Init(void);
/******************************/
/********************************************/

#endif	/* SYSTEM_H */

