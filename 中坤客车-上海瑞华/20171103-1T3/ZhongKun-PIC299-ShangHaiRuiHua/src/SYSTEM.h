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
#define  TIME          20171103L
//是否带视频信号 0不带视频 1带视频
#define  VIDEO         1
//带视频的个数  
#define  VIDEO_NUMBER  2
//空指针
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
extern unsigned int Tcan_count; //胎压CAN

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

/**********随州协议变量************/

extern unsigned int VCU_TM_NM; //TM目标扭矩
extern unsigned int VCU_TM_RPM; //TM目标转速

extern unsigned char VCU_TM_Brake_percent; //制动踏板开度
extern unsigned char VCU_TM_Speed_percent; //加速踏板开度
extern DATA_BIT VCU_Status_Flag1; //状态1
#define  CHARGE      VCU_Status_Flag1.bit1
#define  DCDC_EN     VCU_Status_Flag1.bit2
#define  BMS_OFFLINE VCU_Status_Flag1.bit3
#define  TM_OFFLINE  VCU_Status_Flag1.bit4
#define  DCAC_EN     VCU_Status_Flag1.bit5
#define  SPEED_EN    VCU_Status_Flag1.bit6
#define  BRAJE_EN    VCU_Status_Flag1.bit7
#define  ELE_BRAKE   VCU_Status_Flag1.bit8

extern unsigned char VCU_Gear; //档位

extern DATA_BIT VCU_Mode; //整车模式

extern unsigned char VCU_Life; //整车控制器LIFE

extern DATA_BIT VCU_Status_Flag2;
#define  READY       VCU_Status_Flag2.bit6
#define  CHARGE_OVERTIME VCU_Status_Flag2.bit7  
#define  VCU_FAULT   VCU_Status_Flag2.bit8 

extern unsigned char VCU_Code; //整车故障码

// VCU2TERMINAL_MOTOR01
extern unsigned char TM_Number; //电机个数
extern unsigned char TM_Serial; //电机序号
extern unsigned char TM_WorkStatus; //TM电机工作状态
extern unsigned char TM_Control_Temp; //TM电机控制器温度
extern unsigned int TM_Feedback_RPM; //TM电机反馈转速
extern unsigned int TM_Feedback_NM; //TM电机反馈扭矩
// VCU2TERMINAL_MOTOR02
extern unsigned char TM_Temp; //TM电机温度
extern unsigned int TM_Voltage_DC; //TM电机直流电压
extern unsigned int TM_Current_DC; //TM电机直流电流

/*extern unsigned int  TM_Feedback_RPM;//TM电机反馈转速
extern unsigned int  TM_Feedback_NM;//TM电机反馈扭矩
extern unsigned int  TM_Current_AC;//TM电机交流电流
extern unsigned char TM_StatusFeedback;//TM电机状态反馈
extern unsigned char TM_WorkStatus;//TM电机工作状态
extern unsigned char TM_LIFE;//TM电机LIFE

extern unsigned char TM_Temp;//TM电机温度
extern unsigned char TM_Control_Temp;//TM电机控制器温度
extern unsigned int  TM_Torque_Limit_Up;//电机扭矩上限
extern unsigned int  TM_Torque_Limit_Down;//电机扭矩下限
extern DATA_BIT      TM_Fault;//TM电机故障等级
extern unsigned char TM_Status;//TM电机状态
extern DATA_BIT      TM_Status_Flag1;//电机状态1
#define  TM_COT_OVERT TM_Status_Flag1.bit1
#define  TM_OVERT    TM_Status_Flag1.bit2

extern unsigned int  TM_Code;//TM电机故障码
extern unsigned int  TM_Current_DC;//TM电机直流电流
extern unsigned int  TM_Voltage_DC;//TM电机直流电压
 */
//IRM
extern unsigned long IRM_Ohm_Positive; //总正绝缘阻值 
extern unsigned long IRM_Ohm_Negative; //总负绝缘阻值 
extern unsigned char IRM_Fault_Level; //设备故障等级
extern unsigned char IRM_Insulation_Level; //绝缘等级
extern unsigned char IRM_Life; //绝缘LIFE

/*extern unsigned char VCU_Kt; //主接触器控制命令
extern unsigned char VCU_ON; //钥匙下电状态
extern unsigned char VCU_Order; //故障处理命令
extern unsigned int  VCU_Voltage; //电机控制器电压
 */


extern unsigned char BMS_Mode; //电池充放电模式
extern unsigned char BMS_Status; //电池状态
extern unsigned char BAT_Temp_Average; //电池平均温度
extern unsigned char BMS_SOC; //SOC
extern unsigned int BMS_Current; //电池系统电流
extern unsigned int BMS_Voltage; //电池系统内总电压
extern unsigned char BMS_Kt; //高压继电器状态

extern unsigned char BAT_Temp_H_Limit; //最高允许电池单体温度
extern unsigned char BAT_Temp_L_Limit; //最低允许电池单体温度
extern unsigned char BMS_SOC_L_Limit; //最低允许SOC值
extern unsigned int BAT_Current_Discharge_Limit; //最高允许放电电流
extern unsigned int BAT_Current_Charge_Limit; //最高允许充电电流

extern unsigned char BAT_Temp_L; //电池单体最低温度
extern unsigned char BAT_Temp_L_Number; //电池单体低温度序号
extern unsigned char BAT_Temp_L_Case; //电池单体低温度箱号
extern unsigned char BAT_Temp_H; //电池单体最高温度
extern unsigned char BAT_Temp_H_Number; //电池单体高温度序号
extern unsigned char BAT_Temp_H_Case; //电池单体高温度箱号

extern unsigned char BAT_Voltage_Fault; //总压故障
extern unsigned char BAT_Single_Fault; //单压故障
extern unsigned char BAT_Temp_Fault; //温度故障
extern unsigned char BAT_Insulation_Fault; //绝缘故障
extern unsigned char BAT_Consistency_Fault; //电池一致性故障
extern unsigned char BAT_SOC_Fault; //SOC故障
extern unsigned char BAT_Current_Fault; //电流故障
extern unsigned char BAT_Lock_Fault; //高压互锁故障
extern unsigned char BMS_Comm_Fault; //BMS通讯故障
extern unsigned char BMS_System_Fault; //BMS系统故障

extern unsigned int BMS_Ohm; //绝缘阻值 
extern unsigned char BMS_Number; //单体电压数量
extern unsigned char BMS_Temp_Number; //单体温度数量
extern unsigned char BMS_System_Unit; //系统数量
extern unsigned char BMS_System_Number; //系统号

extern unsigned int BAT_Single_L; //电池单体低电压
extern unsigned char BAT_Single_L_Number; //电池单体低电压位置
extern unsigned char BAT_Single_L_Case; //电池单体低电压箱号

extern unsigned int BAT_Single_H; //电池单体高电压
extern unsigned char BAT_Single_H_Number; //电池单体高电压位置
extern unsigned char BAT_Single_H_Case; //电池单体高电压箱号
/*
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
 */
extern unsigned int BAT_Cell_Voltage[400];
extern unsigned char BAT_Cell_Temperature[128];

extern unsigned int DCDC_Voltage; //DCDC输出电压
extern unsigned int DCDC_Current; //DCDC输出电流
extern unsigned char DCDC_Status; //DCDC工作状态
extern unsigned char DCDC_Output_Cut; //DCDC 输出切断
extern unsigned char DCDC_intput_Cut; //DCDC 输入切断
extern unsigned char DCDC_Fault_Code; //DCDC故障码
extern unsigned char DCDC_Level_Fault; //DCDC故障等级
extern unsigned char DCDC_Temp_Warn; //DCDC温度报警
extern unsigned char DCDC_Fault_Warn; //DCDC故障报警
extern unsigned char DCDC_Temp; //DCDC模块温度

extern unsigned int OILDCAC_U_Voltage; //DCAC输出U电压
extern unsigned int OILDCAC_U_Current; //DCAC输出U电流
extern unsigned char OILDCAC_Status; //DCAC工作状态
extern unsigned char OILDCAC_Output_Cut; //DCAC 输出切断
extern unsigned char OILDCAC_intput_Cut; //DCAC 输入切断
extern unsigned char OILDCAC_Fault_Code; //DCAC故障代码
extern unsigned char OILDCAC_Level_Fault; //DCAC故障等级
extern unsigned char OILDCAC_Temp_Warn; //DCDC温度报警
extern unsigned char OILDCAC_Fault_Warn; //DCDC故障报警
extern unsigned char OILDCAC_Temp; //DCAC模块温度

extern unsigned int OILDCAC_V_Voltage; //DCAC输出V电压
extern unsigned int OILDCAC_V_Current; //DCAC输出V电流
extern unsigned int OILDCAC_W_Voltage; //DCAC输出W电压
extern unsigned int OILDCAC_W_Current; //DCAC输出W电流

extern unsigned int AIRDCAC_U_Voltage; //DCAC输出U电压
extern unsigned int AIRDCAC_U_Current; //DCAC输出U电流
extern unsigned char AIRDCAC_Status; //DCAC工作状态
extern unsigned char AIRDCAC_Output_Cut; //DCAC 输出切断
extern unsigned char AIRDCAC_intput_Cut; //DCAC 输入切断
extern unsigned char AIRDCAC_Fault_Code; //DCAC故障代码
extern unsigned char AIRDCAC_Level_Fault; //DCAC故障等级
extern unsigned char AIRDCAC_Temp_Warn; //DCDC温度报警
extern unsigned char AIRDCAC_Fault_Warn; //DCDC故障报警
extern unsigned char AIRDCAC_Temp; //DCAC模块温度

extern unsigned int AIRDCAC_V_Voltage; //DCAC输出V电压
extern unsigned int AIRDCAC_V_Current; //DCAC输出V电流
extern unsigned int AIRDCAC_W_Voltage; //DCAC输出W电压
extern unsigned int AIRDCAC_W_Current; //DCAC输出W电流

extern DATA_DOUBLE ICS01_Status1; //高压采集状态1
extern DATA_DOUBLE ICS01_Status2; //高压采集状态2
extern DATA_DOUBLE ICS01_Status3; //高压采集状态3
extern DATA_DOUBLE ICS01_Status4; //高压采集状态4

extern unsigned int ICS01_Voltage_Front; //前端电压
extern unsigned int ICS01_Voltage_Rear; //后端电压
extern unsigned char ICS01_LIFE; //LIFE

//extern unsigned char TireLocation_LR;                 //轮胎位置（左右）
//extern unsigned char TireLocation_FB;                 //轮胎位置（前后）
extern unsigned char TireLocation[4][6];                    //轮胎位置
extern unsigned char TirePressure[4][6];                    //胎压
extern unsigned int  TireTemperature[4][6];                 //胎温
extern DATA_DOUBLE   TireFault[4][6];                       //轮胎报警
extern unsigned int  TireAirLeakageRate[4][6];              //气压降低速率
extern unsigned char TirePressureThresholdDetection[4][6];  //气压警示级别


/**********************************************/

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
extern CAN_CACHE m_can; //HCU缓存
extern CAN_CACHE n_can; //TCU缓存
extern CAN_CACHE c_can; //CCU缓存
extern CAN_CACHE b_can; //BMS缓存

extern unsigned long SPN; //从缓存里提取的故障码
extern unsigned char FMI;
/******************************************************************/


void System_Init(void);
void SYSTME_Logic(void);
void LED_Logic(void);

void BCAN_SendCtl(void);
void PCAN_CCVS(void);
void Count_ADR(void);
void PCAN_send_req(void);
void PCAN_send_mile(void);
void PCAN_Taiya(void);
/*void DM_HCU(unsigned char x);
void DM_TCU(unsigned char x);
void DM_CCU(unsigned char x);
void DM_ECU(unsigned char x);
void DM_BCU(unsigned char x);*/
void DM(unsigned char x, DM1 id);
//dispaly
void LCD_Exec(void);
void TIM5_Init(void);
//void TIMER4_Init(void);
/******************************/
/********************************************/

#endif	/* SYSTEM_H */

