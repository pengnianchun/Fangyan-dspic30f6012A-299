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
/*******************分包处理*****************/
//VCU信息1 0x0CFA00D0
extern unsigned char VCU_BUSStatus;      //车辆当前状态
extern unsigned char VCU_MotorStatus; //电驱动系统状态
extern unsigned char VCU_HandBrake;   //手刹信号
extern unsigned char VCU_Gear; //档位
extern unsigned char VCU_Key;  //钥匙位置
extern DATA_BIT      VCU_Status1;//信号状态1
#define  KT_SIGNAL     VCU_Status1.bit2
#define  ABS_SIGNAL    VCU_Status1.bit4
#define  RPM_SIGNAL    VCU_Status1.bit5
#define  NM_SIGNAL     VCU_Status1.bit6
extern unsigned int  MCU_RPM;                 //电机转速
extern unsigned int  MCU_NM;                  //电机扭矩
extern unsigned char VCU_Life;
//VCU信息2 0x0CFB00D0
extern DATA_BIT      VCU_Status2;//信号状态2
#define  MCU_VOLTAGE_SIGNAL     VCU_Status2.bit1
#define  MCU_CURRENT_SIGNAL     VCU_Status2.bit2
#define  KC_SIGNAL              VCU_Status2.bit3
#define  BRAKE_SIGNAL           VCU_Status2.bit4
#define  SPEED_SIGNAL           VCU_Status2.bit5
#define  VBAT_SIGNAL            VCU_Status2.bit6
extern unsigned int  MCU_Voltage; //电机母线电压
extern unsigned int  MCU_Current;     //电机电流
extern unsigned char VCU_TM_Brake_percent; //制动踏板开度
extern unsigned char VCU_TM_Speed_percent; //加速踏板开度
extern unsigned char VCU_XDC; //蓄电池电压
//VCU信息3 0x0CFC00D0
extern unsigned char MCU_TempSignal; //电机温度信号状态
extern unsigned char MCU_ControlTempSignal; //电机控制器温度信号状态
extern unsigned char MCU_Temp; //电机温度
extern unsigned char MCU_Control_Temp ; //电机控制器温度
extern unsigned int  VCU_KM;
extern unsigned char VCU_SPEED;
//远程锁车应答 0x0CFE00D0
//VCU故障信息 0x0CFF00D0
extern unsigned int  VCU_FaultCode; 
extern DATA_BIT      VCU_Status3;//信号状态3
#define  VCU_TorqueLimitSignal     VCU_Status3.bit1
#define  VCU_TorqueLimit           VCU_Status3.bit2
#define  VCU_OverSpeed             VCU_Status3.bit3
#define  VCU_RemoteLock            VCU_Status3.bit8
extern unsigned char VCU_Lock;                    //互锁状态
extern unsigned char VCU_Kwh_1s;  //瞬时电耗
//辅机控制器使能信号 0x0CEA00D0
extern unsigned char VCU_OilEn;  //油泵使能
extern unsigned char VCU_AirEn;  //气泵使能
extern unsigned char VCU_DCDCEn; //DCDC使能
//动力电池总信息 0x18A1EFF3
extern unsigned char BMS_SOC;     //电池SOC
extern unsigned int  BMS_V;       //电池电压
extern unsigned int  BMS_A; //电池电流
extern unsigned int  BMS_ChargeTimes; //充电次数
extern unsigned char BMS_Life;     //BMSlife
//动力电池包信息 0x18A2EFF3
extern unsigned char BMS_PackNumber;  //电池箱总串数
extern unsigned int  BMS_SingleNumber;  //电池总串数
extern unsigned char BMS_SeriesNumber;  //串联串数
extern unsigned char BMS_ParallelNumber;  //并联串数
extern unsigned int  BAT_Ahr;           //电池额定容量
//动力电池包电压信息 0x18A3EFF3
extern unsigned char BAT_Pack_SequenceNumber_V; //电池箱号
extern unsigned int  BAT_Pack_Voltage[25]; //电池箱电压
//电池单体和温度总信息 0x18A4EFF3
extern unsigned int  BAT_Min_Cell_Voltage; //电池单体低电压
extern unsigned int  BAT_Max_Cell_Voltage; //电池单体高电压
extern unsigned char BAT_Min_Cell_Temperature; //最低单体温度
extern unsigned char BAT_Max_Cell_Temperature; //最高单体温度
extern unsigned int  BAT_RestAhr;           //电池剩余容量
//电池充放电信息 0x18A5EFF3
extern unsigned int  BMS_LowDischargeVoltage;//最低放电电压
extern unsigned int  BMS_HighChargeVoltage; //最高充电电压
extern unsigned int  BMS_HighDischargeCurrent;//最高放电电流
extern unsigned int  BMS_HighChargeCurrent;//最高充电电流
//电池温度和单体位置信息 0x18A6EFF3
extern unsigned char BAT_Max_Cell_Voltage_Cell_Case; //最高单体电压箱号
extern unsigned char BAT_Max_Cell_Voltage_Cell_Number; //最高单体电压位置
extern unsigned char BAT_Min_Cell_Voltage_Cell_Case; //最低单体电压箱号
extern unsigned char BAT_Min_Cell_Voltage_Cell_Number; //最低单体电压位置
extern unsigned char BAT_Max_Pole_Temp; //最高极柱温度
extern unsigned char BAT_Max_Pole_Temp_Cell_Case; //最高极柱温度箱号
extern unsigned char BAT_Max_Cell_Temp_Cell_Case; //最高单体温度箱号
extern unsigned char BAT_Min_Cell_Temp_Cell_Case; //最低单体温度箱号
//动力电池包单体数量信息（一串作为一个单体） 0x18A7EFF3
extern unsigned char BAT_Pack_SequenceNumber_N; //电池箱号
extern unsigned char BAT_Pack_Number[25]; //电池箱串联数量
//电池报警信息 0x18B1EFF3
extern unsigned char BMS_Warn_Type;      //报警类别
extern unsigned char BMS_1LevelFault;      //一级故障代码
extern unsigned char BMS_2LevelFault;      //二级故障代码
extern unsigned char BMS_3LevelFault;      //三级故障代码
extern unsigned char BMS_InsulationControl;      //绝缘控制
extern unsigned char BMS_ChargeGun_Comm;      //充电枪通讯
extern unsigned char BMS_ChargeGun_Link;      //充电枪连接状态
extern unsigned char BMS_Chargeing;      //充电枪状态
extern unsigned char BMS_KB;               //电池主继电器状态
//电池火灾预警信息 0x18B2EFF3
extern unsigned char BMS_FireWarnLevel;               //电池火灾级别
extern unsigned char BMS_FireFaultCode;               //电池火灾故障码
extern unsigned char BMS_FireFaultNumber;               //电池火灾故障箱号
extern unsigned char BMS_FireWarnNumber;               //电池火灾预警箱号
//电池组所有单体电压信息 0x18C1EFF3
//extern unsigned int  BAT_Cell_VoltageNumber; //动力电池箱号
extern unsigned int  BAT_Cell_Voltage[10][31]; //电池单体电压
//电池组所有温度信息 0x18E1EFF3
//extern unsigned int  BAT_Cell_TempNumber; //动力电池箱号
extern unsigned char BAT_Cell_Temp[10][6]; //电池单体温度
//整车绝缘监控报文 0x1819A1A4
extern unsigned int  IM_Oum;               //绝缘阻值
extern unsigned int  IM_Votage;            //绝缘电压
extern unsigned char IM_FaultLevel;        //绝缘故障等级
extern unsigned char IM_WorkStatus;        //绝缘工作状态
extern unsigned char IM_FaultStatus;       //绝缘故障状态
extern unsigned char IM_Life;              //绝缘Life
//远程锁车命令 0x18FF70EE
//电子档位开关报文 0X18FC0011
//DC/DC报文信息 0x1801A79A
extern unsigned int  DCDC_Input_Voltage;  //DCDC输入电压
extern unsigned char DCDC_Output_Voltage; //DCDC输出电压
extern unsigned int  DCDC_Output_Current; //DCDC输出电流
extern unsigned char DCDC_Temp;      //DCDC模块温度
extern unsigned char DCDC_FaultCode; //DCDC故障代码
extern unsigned char DCDC_WorkStatus; //DCDC工作状态
//油泵控制器报文信息 0x1801A79B
extern unsigned int  OILDCAC_InputVoltage;   //DCAC输入电压
extern unsigned int  OILDCAC_Voltage;   //DCAC输出电压
extern unsigned int  OILDCAC_Current;   //DCAC输出电流
extern unsigned char OILDCAC_Temp; //DCAC电机温度
extern unsigned char OILDCAC_FaultCode;    //DCAC故障代码
//气泵控制器报文信息 0x1801A79D
extern unsigned int  AIRDCAC_InputVoltage;   //DCAC输入电压
extern unsigned int  AIRDCAC_Voltage;   //DCAC输出电压
extern unsigned int  AIRDCAC_Current;   //DCAC输出电流
extern unsigned char AIRDCAC_Temp; //DCAC电机温度
extern unsigned char AIRDCAC_FaultCode;    //DCAC故障代码
//低压油泵（DC/AC）控制器报文信息 0x0CF603A1
//空调控制报文 0x1801A79E
extern unsigned char AC_Status;   //空调运行命令
extern unsigned char AC_Set_Temp; //设定温度
extern unsigned char AC_Gear; //档位
extern unsigned char AC_WindMode; //新风模式
extern unsigned char AC_Work_Status; //工作模式
extern unsigned char AC_Life; 
//高压配电柜信息
extern DATA_BIT Protect[2];
//集中润滑
extern DATA_BIT Concentrated_Lubrication;

void DM(unsigned char x, DM1 id);

#endif	/* APP_CAN2_RECEIVE_H */

