/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef APP_CAN2_RECEIVE_H
#define	APP_CAN2_RECEIVE_H

#define WORD_WRITE(dest,data)	do{(dest)[0] = (data)&0xFF;((dest)[1]=(data)>>8)&0xFF;}while(0)
#define DWORD_WRITE(dest,data)	do{(dest)[0] = (data)&0xFF;((dest)[1]=(data)>>8)&0xFF;((dest)[2]=(data)>>16)&0xFF;((dest)[3]=(data)>>24)&0xFF;}while(0)

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
        unsigned char bit1 : 1;
        unsigned char bit2 : 1;
        unsigned char bit3 : 1;
        unsigned char bit4 : 1;
        unsigned char bit5 : 1;
        unsigned char bit6 : 1;
        unsigned char bit7 : 1;
        unsigned char bit8 : 1;
    };
    unsigned char byte;
} DATA_BIT;

/*****************分包处理CAN*****************/

typedef union {

    struct {
        unsigned long SPN1 : 19;
        unsigned long FMI : 5;
        unsigned long CM : 1;
        unsigned long OC : 7;
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

extern unsigned long SPN; //从缓存里提取的故障码
extern unsigned char FMI;

void DM(unsigned char x, DM1 id);
/*******************分包处理*****************/
#pragma pack(1)

typedef union {

    struct {
        unsigned MotoVoltage; //电机输入电压
        unsigned MotoCurrent; //电机输入电流
        unsigned MotoSpeed; //电机转速
        unsigned char MotorTemperature; //电机温度
        unsigned char MotorTemperature_Controller; //电机温度
    };
    unsigned char byte[8];
} _CAN_0x0C03A1A7;

typedef union {

    struct {
        unsigned long VCUVerison : 24; //整车控制器程序版本号
        unsigned long FaultCode1 : 8; //故障代码1       
        unsigned char FaultLevel; //故障等级
        unsigned char VCUMode; //整车模式
        unsigned char FaultCode2; //故障代码2
        unsigned char VCULife; //整车控制器Life
    };
    unsigned char byte[8];
} _CAN_0x0C04A1A7;

typedef union {

    struct {
        unsigned char Reserve;
        unsigned char : 3;
        unsigned char E_Brake : 1;
        unsigned char READY : 1;
        unsigned char : 3;
        unsigned char DCDCTemp;
        unsigned char DCDCFaultCode0 : 1;
        unsigned char DCDCFaultCode1 : 1;
        unsigned char DCDCFaultCode2 : 1;
        unsigned char DCDCFaultCode3 : 1;
        unsigned char DCDCFaultCode4 : 1;
        unsigned char DCDCFaultCode5 : 1;
        unsigned char DCDCFaultCode6 : 1;
        unsigned char DCDCFaultCode7 : 1;
        unsigned char DCAC1Temp;
        unsigned char DCAC1FaultCode0 : 1;
        unsigned char DCAC1FaultCode1 : 1;
        unsigned char DCAC1FaultCode2 : 1;
        unsigned char DCAC1FaultCode3 : 1;
        unsigned char DCAC1FaultCode4 : 1;
        unsigned char DCAC1FaultCode5 : 1;
        unsigned char DCAC1FaultCode6 : 1;
        unsigned char DCAC1FaultCode7 : 1;
        unsigned char DCAC2Temp;
        unsigned char DCAC2FaultCode0 : 1;
        unsigned char DCAC2FaultCode1 : 1;
        unsigned char DCAC2FaultCode2 : 1;
        unsigned char DCAC2FaultCode3 : 1;
        unsigned char DCAC2FaultCode4 : 1;
        unsigned char DCAC2FaultCode5 : 1;
        unsigned char DCAC2FaultCode6 : 1;
        unsigned char DCAC2FaultCode7 : 1;
    };
    unsigned char byte[8];
} _CAN_0x0C05A1A7;

typedef union {

    struct {
        unsigned char VCUAcc : 1;
        unsigned char VCUOn : 1;
        unsigned char VCUGearD : 1;
        unsigned char VCUGearR : 1;
        unsigned char VCUGearN : 1;
        unsigned char VCUDiagnosis : 1;
        unsigned char VCUAirPumpTempWarn : 1;
        unsigned char VCUOilPumpTempWarn : 1;

        unsigned char VCUGearS : 1;
        unsigned char Reserve1 : 1;
        unsigned char Reserve2 : 1;
        unsigned char VCUHandBrake : 1;
        unsigned char Reserve3 : 1;
        unsigned char Reserve4 : 1;
        unsigned char VCUPressLowWarn : 1;
        unsigned char Reserve5 : 1;

        unsigned char Reserve6;
        unsigned char VCUOverSpeed;
        unsigned char AcceleratePedal1;
        unsigned char AcceleratePedal2;
        unsigned char BrakePedal1;
        unsigned char BrakePedal2;
    };
    unsigned char byte[8];
} _CAN_0x0C06A1A7;

typedef union {

    struct {
        unsigned char MotoStatus;
        unsigned MotoTorque;
        unsigned MotoSpeed; //电机转速
        unsigned char Reserve1;
        unsigned char Reserve2;
        unsigned char Reserve3;
    };
    unsigned char byte[8];
} _CAN_0x0C08A1A7;

typedef union {

    struct {
        unsigned BMS_V; //电池电压
        unsigned BMS_A; //电池电流
        unsigned char BMS_SOC; //电池SOC
        DATA_BIT BMSFlag1; //电池状态1
        DATA_BIT BMSFlag2; //电池状态2
        DATA_BIT BMSFlag3; //电池状态3
    };
    unsigned char byte[8];
} _CAN_0x1818D0F3;

typedef union {

    struct {
        unsigned BMS_A_charge; //最大充电电流
        unsigned BMS_A_discharge; //最大放电电流
        unsigned char Warn_level; //故障等级
        unsigned BMS_V_average; //电池平均电压
        unsigned char BMS_T_H; //电池最高温度
    };
    unsigned char byte[8];
} _CAN_0x1819D0F3;

typedef union {

    struct {
        unsigned Oum_zheng; //绝缘正阻值
        unsigned Oum_fu; //绝缘负阻值
        unsigned Battery_single_H; //电池单体高电压
        unsigned Battery_single_L; //电池单体低电压
    };
    unsigned char byte[8];
} _CAN_0x181AD0F3;

typedef union {

    struct {
        unsigned char BAT_Min_Cell_Voltage_Cell_Case : 4; //最低单体电压箱号
        unsigned char BAT_Max_Cell_Voltage_Cell_Case : 4; //最高单体电压箱号
        unsigned char BAT_Min_Cell_Temp_Cell_Number : 5; //最低单体温度位置
        unsigned char BAT_Min_Cell_Temp_Cell_Case : 3; //最低单体温度箱号 
        unsigned char BAT_Max_Cell_Temp_Cell_Number : 5; //最高单体温度位置
        unsigned char BAT_Max_Cell_Temp_Cell_Case : 3; //最高单体温度箱号 
        unsigned char BAT_Min_Cell_Voltage_Cell_Number; //最低单体电压位置
        unsigned char BAT_Max_Cell_Voltage_Cell_Number; //最高单体电压位置
        unsigned BATRestEnerge; //电池剩余能量
        unsigned char BAT_Min_Cell_Temperature; //最低单体温度
    };
    unsigned char byte[8];
} _CAN_0x181BD0F3;

typedef union {

    struct {
        DATA_BIT BMSFlag4;
        unsigned char ChargeSocketTemp1;
        unsigned char ChargeSocketTemp2;
        unsigned char Reserve1;
        unsigned char Reserve2;
        unsigned char Reserve3;
        unsigned char Reserve4;
        unsigned char Reserve5;
    };
    unsigned char byte[8];
} _CAN_0x181CD0F3;

typedef union {

    struct {
        DATA_BIT KT_Status;
        unsigned char Reserve1;
        unsigned char Reserve2;
        unsigned char Reserve3;
        unsigned char Reserve4;
        unsigned char Reserve5;
        unsigned char Reserve6;
        unsigned char Reserve7;
    };
    unsigned char byte[8];
} _CAN_0x1830A7F3;

typedef union {

    struct {
        unsigned char AirWorkMode1_Xiaodu : 2;
        unsigned char AirWorkMode1_Xinfeng : 2;
        unsigned char AirWorkMode1_Zhire : 2;
        unsigned char AirWorkMode1_Zhileng : 2;

        unsigned char AirWorkMode2_Tongfeng : 2;
        unsigned char AirWorkMode2_Chushi : 2;
        unsigned char AirWorkMode2_Zidong : 2;
        unsigned char Reserve1 : 2;

        unsigned char Reserve2;
        unsigned char Reserve3;
        unsigned char Reserve4;
        unsigned char Reserve5;
        unsigned char Reserve6;
    };
    unsigned char byte[8];
} _CAN_0x18FFC119;

typedef union {

    struct {
        unsigned DCDC_Input_Voltage; //DCDC输入电压
        unsigned char DCDC_Output_Voltage; //DCDC输出电压
        unsigned DCDC_Output_Current; //DCDC输出电流
        unsigned char DCDC_Temp; //DCDC模块温度
        DATA_BIT DCDC_FaultCode; //DCDC故障代码
        unsigned char Reserve;
    };
    unsigned char byte[8];
} _CAN_0x1801A79A;

typedef union {

    struct {
        unsigned AIRDCAC_InputVoltage; //DCAC输入电压
        unsigned AIRDCAC_Voltage; //DCAC输出电压
        unsigned AIRDCAC_Current; //DCAC输出电流
        unsigned char AIRDCAC_Temp; //DCAC电机温度
        DATA_BIT AIRDCAC_FaultCode; //DCAC故障代码
    };
    unsigned char byte[8];
} _CAN_0x1801A79D;

typedef union {

    struct {
        unsigned OILDCAC_InputVoltage; //DCAC输入电压
        unsigned OILDCAC_Voltage; //DCAC输出电压
        unsigned OILDCAC_Current; //DCAC输出电流
        unsigned char OILDCAC_Temp; //DCAC电机温度
        DATA_BIT OILDCAC_FaultCode; //DCAC故障代码
    };
    unsigned char byte[8];
} _CAN_0x1801A79B;
#pragma pack()
extern _CAN_0x0C03A1A7 CAN_0x0C03A1A7;
extern _CAN_0x0C04A1A7 CAN_0x0C04A1A7;
extern _CAN_0x0C05A1A7 CAN_0x0C05A1A7;
extern _CAN_0x0C06A1A7 CAN_0x0C06A1A7;
extern _CAN_0x0C08A1A7 CAN_0x0C08A1A7;
extern _CAN_0x1818D0F3 CAN_0x1818D0F3;
extern _CAN_0x1819D0F3 CAN_0x1819D0F3;
extern unsigned int BAT_Cell_Voltage[5][40]; //电池单体电压
extern unsigned char BAT_Cell_Temp[5][8]; //电池单体温度
extern _CAN_0x181AD0F3 CAN_0x181AD0F3;
extern _CAN_0x181BD0F3 CAN_0x181BD0F3;
extern _CAN_0x181CD0F3 CAN_0x181CD0F3;
extern _CAN_0x1830A7F3 CAN_0x1830A7F3;
extern _CAN_0x18FFC119 CAN_0x18FFC119;
extern _CAN_0x1801A79A CAN_0x1801A79A;
extern _CAN_0x1801A79D CAN_0x1801A79D;
extern _CAN_0x1801A79B CAN_0x1801A79B;

void CAN_DATA_Init(void);




#if MODE_FV
extern unsigned char Accelerator; //油门踏板

extern unsigned char Speed_lim_mode;//限速模式

extern unsigned char water_temp;//水温

extern unsigned int  Engine_oil_press;//机油压力
extern unsigned char water_level;//水位

extern unsigned char Wait_start;//等待启动
extern unsigned char Maintain_warn;//维护报警
extern unsigned char Stop_warn;//停机报警
extern unsigned char Engine_warn;//发动机故障

extern unsigned int EngineSpeed;//发动机转速

extern unsigned char barometric_pressure; //增压压力 0.5Kpa
extern unsigned char ambient_air_temperature; //周围空气温度
extern unsigned char air_pressure; //进气压力 0.5Kpa

extern unsigned int  fuel_rate;   //小时燃油消耗率
extern unsigned int  instantaneous_fuel; //瞬态燃油经济性

extern unsigned int  speed_st; //油门踏板
#endif

#endif	/* APP_CAN2_RECEIVE_H */

