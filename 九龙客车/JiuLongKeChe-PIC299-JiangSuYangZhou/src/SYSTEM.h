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
#define  MT_ADDR      4
//程序版本号
#define  VERISON      200

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
#define  F30s             gKEY[3].bit8

#define  F30s_flag        gKEY[4].bit1

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

typedef union {

    struct {
        unsigned bit1 : 2;
        unsigned bit2 : 2;
        unsigned bit3 : 2;
        unsigned bit4 : 2;
    };
    unsigned char byte;
} DATA_DOUBLE;

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

extern unsigned int ADR[8]; //模拟量采集   2016/10/15
extern unsigned int ADV[8]; //模拟量采集   2016/10/15

extern unsigned char LIFE;//仪表lIFE
//extern unsigned char Count30s;
//extern const unsigned char BMP_LOGO[];
//extern const unsigned char BMP_LOGObmp[];

/**********随州协议变量************/
extern unsigned char VCU_LIFE; //整车控制器LIFE
extern unsigned char READY; //整车控制器状态
extern unsigned char Inverter_Fault; //整车控制器故障
extern unsigned char Vacuum_Fault; //真空度故障
extern unsigned char BAT24V_Fault; //蓄电池故障
extern unsigned char DCDC_Fault; //DCDC故障
extern unsigned char Speed_Percent; //加速踏板开度
extern unsigned char Brake_Percent; //制动踏板开度
extern unsigned int  Moto_Torque;//转矩
extern unsigned char Motor_Temperature; //电机温度
extern DATA_BIT VCU[4];
#define  WATER_PUMP            VCU[0].bit1
#define  FAN_LOW               VCU[0].bit2  
#define  FAN_HIGH              VCU[0].bit3  
#define  AIR_PUMP              VCU[0].bit4  
#define  AC                    VCU[0].bit5  
#define  HAND_BRAKE            VCU[0].bit6  
#define  FOOT_BRAKE            VCU[0].bit7  
#define  ECO                   VCU[0].bit8  

extern unsigned char VCU_Gear; //档位
extern unsigned char PTC_Front; //前模块PTC档位
extern unsigned char PTC_Rear;  //后模块PTC档位
extern unsigned char Charge_Status; //充电状态
extern unsigned char BUS_Status; //整车状态
extern unsigned char Moto_Fault; //电机系统故障
extern unsigned char BAT_Fault; //电池系统故障
extern unsigned char VCU_Fault; //整车控制器故障
extern unsigned char WaterPump_Fault; //水泵故障
extern unsigned char Fan_Fault; //风扇故障
extern unsigned char AirPump_Fault; //气泵故障
extern unsigned char BAT24V_Status; //蓄电池状态
extern unsigned char Gear_Fault; //挂挡失败
extern unsigned char Inverter_t; //控制器温度
extern unsigned char Vacuum; //真空度
//unsigned char BMS_SOC; //电池SOC

extern unsigned char VCU_Speed; //车速
extern unsigned int  Rest_Mile; //续航里程
extern unsigned int  Moto_Rpm; //电机转速

extern unsigned int  Moto_Voltage; //电机直流电压
extern unsigned int  Moto_Current; //电机相电流
extern unsigned int  Moto_PhaseVoltage; //电机相电压
extern unsigned char Press1; //气压1
extern unsigned char Press2; //气压2

extern unsigned long Program; //程序版本

//BMS
extern unsigned int  BMS_V; //电池电压
extern unsigned int  BMS_A; //电池电流
extern unsigned char BMS_SOC; //电池SOC
extern unsigned char BMS_Life; //BMSlife
extern unsigned char BMS_Fault; //BMS故障等级
extern unsigned char Oum_Warn; //整车绝缘报警

extern unsigned char BAT_Voltage_Number[4];//单体电压序号
extern unsigned char BAT_Temperature_Number;//单体温度序号
extern unsigned char BAT_Cell_Voltage[210]; //电池单体电压
extern unsigned char BAT_Cell_Temperature[60][3]; //电池单体温度

extern DATA_BIT BMS[8];
extern unsigned char BAT_Number;//电池组总串数
extern unsigned int  BAT_Ahr;//电池组容量

extern unsigned int  BAT_Max_Cell_Voltage; //电池单体高电压
extern unsigned int  BAT_Min_Cell_Voltage; //电池单体低电压
extern unsigned int  BAT_Max_Cell_Temperature; //最高单体温度
extern unsigned int  BAT_Min_Cell_Temperature; //最低单体温度

extern unsigned char BAT_Max_Cell_Voltage_Cell_Case; //最高单体电压箱号
extern unsigned char BAT_Max_Cell_Voltage_Cell_Number; //最高单体电压位置

extern unsigned char BAT_Min_Cell_Voltage_Cell_Case; //最低单体电压箱号
extern unsigned char BAT_Min_Cell_Voltage_Cell_Number; //最低单体电压位置

extern unsigned char BAT_Max_Cell_Temp_Cell_Case; //最高单体温度箱号
extern unsigned char BAT_Max_Cell_Temp_Cell_Number; //最高单体温度位置

extern unsigned char BAT_Min_Cell_Temp_Cell_Case; //最低单体温度箱号
extern unsigned char BAT_Min_Cell_Temp_Cell_Number; //最低单体温度位置

//充电机
extern unsigned char Charger_Life;//充电机LIFE
extern unsigned int  Charger_Voltage;//充电机输出电压
extern unsigned int  Charger_Current;//充电机输出电流
extern DATA_BIT CHARGER[1];

//0x1800B4D0
extern DATA_DOUBLE VCU_FAULT[2];
extern DATA_BIT    VCU_WARN[4];

/*
extern unsigned int Moto_Voltage; //电机电压
extern unsigned int Moto_Current; //电机电流
extern unsigned int Moto_Rpm; //电机转速
extern unsigned char Motor_Temperature; //电机温度
extern unsigned char Inverter_t; //控制器温度

extern unsigned long Program; //程序版本
extern unsigned char Car_Mode; //整车模式
extern unsigned char Car_Fault_Level;//故障等级
extern unsigned int  Fault_Code;//故障代码
extern unsigned char Car_LIFE; //整车控制器

extern DATA_BIT MET_C_3[2];
#define  Kt_1             MET_C_3[0].bit1
#define  Kt_0             MET_C_3[0].bit2  
#define  Kt_Charge        MET_C_3[0].bit3  
#define  Kt_Defrost       MET_C_3[0].bit4  
#define  Kt_AC            MET_C_3[0].bit5  

#define  Brake_Ele        MET_C_3[1].bit4
#define  READY            MET_C_3[1].bit5
extern unsigned char DCDC_Sanreqi_t; //DCDC散热器温度
extern unsigned char DCDC_Warn_code; //DCDC故障代码
extern unsigned char DCAC1_Sanreqi_t; //DCAC1散热器温度
extern unsigned char DCAC1_Warn_code; //DCAC1故障代码
extern unsigned char DCAC2_Sanreqi_t; //DCAC2散热器温度
extern unsigned char DCAC2_Warn_code; //DCAC2故障代码

extern DATA_BIT MET_C_4[3];
#define  Gear_D           MET_C_4[0].bit3
#define  Gear_R           MET_C_4[0].bit4  
#define  Gear_N           MET_C_4[0].bit5  

#define  Park             MET_C_4[1].bit4
#define  Press_Low        MET_C_4[1].bit7  
extern unsigned char Over_Speed; //超速报警
extern unsigned char Speed_Percent1; //加速踏板1开度
extern unsigned char Speed_Percent2; //加速踏板2开度
extern unsigned char Brake_Percent1; //制动踏板1开度
extern unsigned char Brake_Percent2; //制动踏板2开度

extern unsigned int  Oum_zheng; //绝缘正阻值
extern unsigned int  Oum_fu;    //绝缘负阻值
extern unsigned char Oum_Warn;  //整车绝缘报警

//BMS1_S_1
extern unsigned char BMS_SOC; //电池SOC
extern unsigned int  BMS_V; //电池电压
extern unsigned int  BMS_A; //电池电流
extern unsigned int  BAT_Number;//电池组总串数
extern unsigned char BMS_Life; //BMSlife

//BMS1_S_3
extern DATA_BIT BMS1_S_3[3];
#define  BMU_OFFLINE           BMS1_S_3[0].bit1
#define  CHARGER_COMM_FAULT    BMS1_S_3[0].bit2  
#define  PRECHARGE_FAULT       BMS1_S_3[0].bit3 
#define  BALANCE_FAULT         BMS1_S_3[0].bit4
#define  WARN_FAULT            BMS1_S_3[0].bit5 
#define  BAT_COOL_FAULT        BMS1_S_3[0].bit6
#define  BMS_FAULT_OTHER       BMS1_S_3[0].bit7
#define  BMS_COMM_FAULT        BMS1_S_3[0].bit8  

#define  CHARGE_PLUG           BMS1_S_3[1].bit4
#define  CHARGE_STATUS         BMS1_S_3[1].bit5 
#define  BAT_FAULT             BMS1_S_3[1].bit6
extern unsigned char BMS_Self_Check;//BMS自检状态

#define  TEMP_COLT_OFFLINE     BMS1_S_3[2].bit1
#define  BAT_CELL_COLT_OFFLINE BMS1_S_3[2].bit2  
#define  SOC_JUMP              BMS1_S_3[2].bit4
#define  SYSTEM_MISMATCH       BMS1_S_3[2].bit5 
#define  FIRE_FAULT            BMS1_S_3[2].bit6
#define  VOLTAGE_DIFF_FAULT    BMS1_S_3[2].bit7

extern unsigned char Battery_OverTemp;//电池高温报警
extern unsigned char Pole_OverTemp;//极柱高温报警
extern unsigned char Single_Bat_OverVoltage;//单体过压报警
extern unsigned char Pack_Bat_OverVoltage;//电池组过压报警
extern unsigned char Pack_Bat_UnderVoltage;//电池组欠压报警
extern unsigned char Single_Bat_UnderVoltage;//单体欠压报警
extern unsigned char Charge_Gun_OverTemp;//充电枪过温报警
extern unsigned char Bat_Fault;//动力电池故障
extern unsigned char Discharge_OverCurrent;//放电过流报警
extern unsigned char Charge_OverCurrent;//充电过流报警
extern unsigned char Diff_Voltage;//单体电压差异报警
extern unsigned char Diff_Temp;//温度差异报警
extern unsigned char SOC_Low;//SOC低报警
extern unsigned char SOC_High;//SOC高报警
extern unsigned char Diff_SOC;//SOC差异报警
extern unsigned char Bat_LowTemp;//电池温度低报警

//BMS单体电池数据
extern unsigned int  BAT_Max_Cell_Voltage[4]; //电池单体高电压
extern unsigned char BAT_Max_Cell_Voltage_Cell_Case[4]; //最高单体电压箱号
extern unsigned char BAT_Max_Cell_Voltage_Cell_Number[4]; //最低单体电压位置

extern unsigned int  BAT_Min_Cell_Voltage[4]; //电池单体高电压
extern unsigned char BAT_Min_Cell_Voltage_Cell_Case[4]; //最高单体电压箱号
extern unsigned char BAT_Min_Cell_Voltage_Cell_Number[4]; //最低单体电压位置

extern unsigned int  BAT_Max_Cell_Temperature[4]; //最高单体温度
extern unsigned char BAT_Max_Cell_Temp_Cell_Case[4]; //最高单体温度箱号

extern unsigned int  BAT_Min_Cell_Temperature[4]; //最低单体温度
extern unsigned char BAT_Min_Cell_Temp_Cell_Case[4]; //最低单体温度箱号

extern unsigned char BAT_Pole_Temperature_P[16];//正极柱温度
extern unsigned char BAT_Pole_Temperature_N[16];//负极柱温度
*/
/*
extern unsigned int  VCU_TM_NM; //TM目标扭矩
extern unsigned int  VCU_TM_RPM; //TM目标转速

extern unsigned char VCU_TM_Brake_percent; //制动踏板开度
extern unsigned char VCU_TM_Speed_percent; //加速踏板开度
extern unsigned char VCU_Status_Flag1;//状态1
extern unsigned char VCU_Gear;//档位
extern unsigned char VCU_Fault;//车辆系统故障
extern DATA_BIT VCU_Status_Flag2[1];
#define  READY            VCU_Status_Flag2[0].bit3
#define  BMS_OFFLINE      VCU_Status_Flag2[0].bit4  
#define  ISG_OFFLINE      VCU_Status_Flag2[0].bit5  
#define  TM_OFFLINE       VCU_Status_Flag2[0].bit6  
#define  CHARGE_OVERTIME  VCU_Status_Flag2[0].bit7  
#define  CAR_LOCK         VCU_Status_Flag2[0].bit8    
extern unsigned char VCU_Life;//整车控制器LIFE

extern unsigned int  TM_Feedback_RPM;//TM电机反馈转速
extern unsigned int  TM_Feedback_NM;//TM电机反馈扭矩
extern unsigned char TM_WorkStatus;//TM电机工作状态

extern unsigned char TM_Temp;//TM电机温度
extern unsigned char TM_Control_Temp;//TM电机控制器温度
extern unsigned char TM_Fault;//TM电机故障等级

extern unsigned int  TM_Current_DC;//TM电机直流电流
extern unsigned int  TM_Voltage_DC;//TM电机直流电压

extern unsigned char VCU_Kt; //主接触器控制命令
extern unsigned char VCU_ON; //钥匙下电状态
extern unsigned char VCU_Order; //故障处理命令
extern unsigned int  VCU_Voltage; //电机控制器电压

extern unsigned char BMS_Status;//电池状态
extern unsigned char BMS_Fault; //故障状态
extern unsigned char BMS_Balance_Lock;//电池均衡锁定状态
extern unsigned char BMS_Fault_Lock;//故障锁定状态
extern unsigned char BMS_SOC;//SOC
extern unsigned char BMS_SOH;//SOH
extern unsigned char BMS_Ahr;//电池容量
extern unsigned int  BMS_Ohm;//电池系统内阻
extern unsigned char BMS_Life;//生命信号

extern unsigned int  BMS_Voltage;//电池系统内总电压
extern unsigned int  BMS_OutVoltage;//电池系统输出电压
extern unsigned int  BMS_Current;//电池系统电流
extern unsigned int  BMS_Power;//电池系统功率
extern unsigned char BMS_Temp;//环境温度

extern unsigned int  BMS_TotalVoltage; //单体电池电压总和
extern unsigned int  Battery_Single_H; //电池单体高电压
extern unsigned int  Battery_Single_L; //电池单体低电压
extern unsigned char Battery_Single_H_Number; //电池单体高电压位置
extern unsigned char Battery_Single_L_Number; //电池单体低电压箱号

extern unsigned int  Battery_Temp_Average; //电池平均温度
extern unsigned int  Battery_Temp_H; //电池单体最高温度
extern unsigned int  Battery_Temp_L; //电池单体最低温度
extern unsigned char Battery_Temp_H_Number; //电池单体高温度序号
extern unsigned char Battery_Temp_L_Number; //电池单体低温度序号

extern unsigned int  Battery_Voltage_H_Limit;//电池系统最高电压限制
extern unsigned int  Battery_Voltage_L_Limit;//电池系统最低电压限制
extern unsigned int  Battery_Single_Voltage_H_Limit;//电池单体最高电压限制
extern unsigned int  Battery_Single_Voltage_L_Limit;//电池单体最低电压限制
extern unsigned char Battery_Current_Discharge_Limit;//最高允许放电电流
extern unsigned char Battery_Current_Charge_Limit;//最高允许充电电流

extern unsigned char BMS_SOC_H_Limit;//最高允许SOC值
extern unsigned char BMS_SOC_L_Limit;//最低允许SOC值
extern unsigned char BMS_Power_10s_Discharge_Limit;//10s 最高允许放电功率
extern unsigned char BMS_Power_10s_Charge_Limit;//10s 最高允许充电功率
extern unsigned char Battery_Temp_H_Limit; //最高允许电池单体温度
extern unsigned char Battery_Temp_L_Limit; //最低允许电池单体温度

extern unsigned long BMS_spn; //BMS故障码
extern unsigned char BMS_fmi;
extern unsigned char BMS_cm;
extern unsigned char BMS_oc;

extern unsigned int  DCDC_Voltage; //DCDC输出电压
extern unsigned int  DCDC_Current; //DCDC输出电流
extern unsigned char DCDC_Status; //DCDC工作状态
extern unsigned char DCDC_Output_Cut; //DCDC 输出切断
extern unsigned char DCDC_intput_Cut; //DCDC 输入切断
extern unsigned char DCDC_BasicStatus; //DCDC基本状态
extern unsigned char DCDC_Level_Fault; //DCDC故障等级
extern unsigned char DCDC_Temp; //DCDC模块温度

extern unsigned int  OILDCAC_U_Voltage; //DCAC输出U电压
extern unsigned int  OILDCAC_U_Current; //DCAC输出U电流
extern unsigned char OILDCAC_Status; //DCAC工作状态
extern unsigned char OILDCAC_Output_Cut; //DCAC 输出切断
extern unsigned char OILDCAC_intput_Cut; //DCAC 输入切断
extern unsigned char OILDCAC_BasicStatus; //DCAC基本状态
extern unsigned char OILDCAC_Level_Fault; //DCAC故障等级
extern unsigned char OILDCAC_Fault_Code; //DCAC故障代码
extern unsigned char OILDCAC_Temp; //DCAC模块温度

extern unsigned int  OILDCAC_V_Voltage; //DCAC输出V电压
extern unsigned int  OILDCAC_V_Current; //DCAC输出V电流
extern unsigned int  OILDCAC_W_Voltage; //DCAC输出W电压
extern unsigned int  OILDCAC_W_Current; //DCAC输出W电流

extern unsigned int  AIRDCAC_U_Voltage; //DCAC输出U电压
extern unsigned int  AIRDCAC_U_Current; //DCAC输出U电流
extern unsigned char AIRDCAC_Status; //DCAC工作状态
extern unsigned char AIRDCAC_Output_Cut; //DCAC 输出切断
extern unsigned char AIRDCAC_intput_Cut; //DCAC 输入切断
extern unsigned char AIRDCAC_BasicStatus; //DCAC基本状态
extern unsigned char AIRDCAC_Level_Fault; //DCAC故障等级
extern unsigned char AIRDCAC_Fault_Code; //DCAC故障代码
extern unsigned char AIRDCAC_Temp; //DCAC模块温度

extern unsigned int  AIRDCAC_V_Voltage; //DCAC输出V电压
extern unsigned int  AIRDCAC_V_Current; //DCAC输出V电流
extern unsigned int  AIRDCAC_W_Voltage; //DCAC输出W电压
extern unsigned int  AIRDCAC_W_Current; //DCAC输出W电流
*/
/**********************************************/

/*extern unsigned int moto_voltage; //电机电压
extern unsigned int moto_current; //电机电流
extern unsigned int moto_speed; //电动转速
extern unsigned char Motor_Temperature; //电机温度
extern unsigned char Inverter_t; //逆变器温度

extern unsigned char Accelerator; //油门开度
extern unsigned int Engine_Speed;//发动机转速

extern unsigned int Fule_rate;//油耗
extern unsigned char water_temp;//水温
extern unsigned char Engine_Fuhe;//发动机负荷
extern unsigned char Niaosu;//尿素;
extern unsigned char Accelerator_Shiji; //油门踏板实际
extern unsigned char Engine_oil_press; //机油压力
extern unsigned char ambient_air_temperature; //周围空气温度

extern unsigned char Current_Gear; //档位
extern unsigned char TCU_Position;//离合位置
extern unsigned char TCU_warn;//变速箱故障
extern unsigned char STOP;//停车故障
extern unsigned int Speed_rmp; //输出轴转速
extern unsigned char Car_mode;//整车模式
extern unsigned char TCU_code;//变速箱故障代码
extern unsigned char TCU_level;//变速箱故障等级

extern DATA_BIT CAN_KEY[4];
#define  CAN_ON           CAN_KEY[0].bit1
#define  CAN_ACC          CAN_KEY[0].bit2  
#define  Diagnosis        CAN_KEY[0].bit3  
#define  Mode_S           CAN_KEY[0].bit4  
#define  AC               CAN_KEY[0].bit5  
#define  Hybrid           CAN_KEY[0].bit6  
#define  Electric         CAN_KEY[0].bit7  
#define  Tradition        CAN_KEY[0].bit8  

#define  High_Voltage     CAN_KEY[1].bit5
#define  Charge_Check     CAN_KEY[1].bit6  

//#define  Kt               CAN_KEY[2].bit2  

#define  Brake_Pedal      CAN_KEY[3].bit1 
extern unsigned char Brake_percent; //制动踏板开度
extern unsigned char Speed_percent; //加速踏板开度
extern unsigned char Digit_input3;//数字量输入3

extern unsigned long Program;//程序版本
extern unsigned long tcu_spn; //TCU故障码
extern unsigned char tcu_fmi;
extern unsigned long tcu_cm; 
extern unsigned char tcu_oc;
extern unsigned char Car_LIFE;//整车控制器

extern unsigned int BMS_V; //电池电压
extern unsigned char BMS_SOC; //电池SOC
extern unsigned int BMS_A; //电池电流
extern unsigned char Status_Flag1;
extern unsigned char Status_Flag2;
extern unsigned char Status_Flag3;

extern unsigned int BMS_A_charge; //最大充电电流
extern unsigned int BMS_A_discharge; //最大电流
extern unsigned char Warn_level;//故障等级
extern unsigned int BMS_V_average; //电池平均电压
extern unsigned char BMS_T_H;//电池最高温度

extern unsigned int Oum_zheng; //绝缘正阻值
extern unsigned int Oum_fu; //绝缘负阻值
extern unsigned int Battery_single_H; //电池单体高电压
extern unsigned int Battery_single_L; //电池单体低电压

extern unsigned char Battery_number[10];//电池编号
extern unsigned int Battery_voltage[10];//电池单体电压

extern unsigned char Battery_number_t[10];//电池温度编号
extern unsigned int Battery_temp[10];//电池单体温度

extern unsigned int DCAC_W;
extern unsigned int DCAC_V;
extern unsigned int DCAC_U;
extern unsigned char Sanreqi_t;//散热器温度
extern unsigned char DCAC_Warn_code;//故障代码

extern unsigned char AC_Warn_code;//AC故障代码
extern DATA_BIT AC_KEY[2];
#define  AC_opean         AC_KEY[0].bit6
#define  AC_mind_speed    AC_KEY[0].bit7
#define  AC_High_speed    AC_KEY[0].bit8

#define  AC_warn1         AC_KEY[1].bit1
#define  AC_cold1_shuang  AC_KEY[1].bit2
#define  AC_wind          AC_KEY[1].bit3
#define  AC_save          AC_KEY[1].bit4
#define  AC_cold2_shuang  AC_KEY[1].bit5
#define  AC_cold2         AC_KEY[1].bit6
#define  AC_cold1         AC_KEY[1].bit8
extern unsigned char Indoor_t;//室内温度
extern unsigned char Outdoor_t;//室外温度
extern unsigned char Set_t;//设定
extern unsigned char AC_req;//制冷请求
extern unsigned char AC_LIFE;//AC生命

extern unsigned char battle_t; //电池均温
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


extern unsigned char mil_lamp_request; //黄色三级报警
extern unsigned char fail_mode; //文字报警
extern unsigned char mil_buzz_request; //蜂鸣器响
extern unsigned long hcu_spn; //HCU故障码
extern unsigned char hcu_fmi;


extern unsigned char Eng_static_test; //发动机稳态转速测试
extern unsigned char tcu_start_allow; //发动机运行启动


extern unsigned char Lamp_status_YELLOW; //变速箱黄灯状态
extern unsigned char Lamp_status_RED; //变速箱红灯状态

extern unsigned long ccu_spn; //CCU故障码
extern unsigned char ccu_fmi;

extern unsigned long ecu_spn; //ECU故障码
extern unsigned char ecu_fmi;



extern unsigned char Motor_Temperature; //电机温度

extern unsigned int ENG_start_req; //仪表控制启动
extern unsigned long mot_work_time; //电机工作累积时间
extern unsigned char mot_work_percent; //电机工作时间比
extern unsigned char DCDC_ctrl; //DCDC状态
extern unsigned char hcu_starter_forbid; //起动机工作
extern unsigned char aircompress_enable; //压缩机
extern unsigned char Speed_lim_mode;//限速模式

extern unsigned char water_level;//水位

extern unsigned char Wait_start;//等待启动
extern unsigned char Maintain_warn;//维护报警
extern unsigned char Stop_warn;//停机报警
extern unsigned char Engine_warn;//发动机故障
*/

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
extern CAN_CACHE m_can;//HCU缓存
extern CAN_CACHE n_can;//TCU缓存
extern CAN_CACHE c_can;//CCU缓存
extern CAN_CACHE b_can;//BMS缓存


/******************************************************************/


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
void DM_BCU(unsigned char x);
void DM(unsigned char x, DM1 id);
//dispaly
void LCD_Exec(void);
void TIM5_Init(void);
//void TIMER4_Init(void);
/******************************/
/********************************************/

#endif	/* SYSTEM_H */

