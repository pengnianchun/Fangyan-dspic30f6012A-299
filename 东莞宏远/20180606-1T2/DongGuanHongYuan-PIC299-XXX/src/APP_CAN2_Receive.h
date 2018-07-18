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

/*extern DM1 CAN_18FECAEF;
extern unsigned char CAN_18FECAEF_len;
extern DM1 CAN_18FECA03;
extern unsigned char CAN_18FECA03_len;
extern DM1 CAN_18FECAF5;
extern unsigned char CAN_18FECAF5_len;
extern DM1 CAN_18FECA00;
extern unsigned char CAN_18FECA00_len;
extern DM1 CAN_18FECAF3;
extern unsigned char CAN_18FECAF3_len;*/

typedef struct {
    unsigned char pack; //CAN分几包数据传输
    unsigned char flag; //CAN缓存接收完标记
    unsigned char len; //CAN缓存长度
    unsigned char buf[50]; //CAN缓存数组
} CAN_CACHE;
/*extern CAN_CACHE m_can; //HCU缓存
extern CAN_CACHE n_can; //TCU缓存
extern CAN_CACHE c_can; //CCU缓存
extern CAN_CACHE b_can; //BMS缓存*/

extern unsigned long SPN; //从缓存里提取的故障码
extern unsigned char FMI;

void DM(unsigned char x, DM1 id);
/*******************分包处理*****************/
#pragma pack(1)

#if 0
typedef union {

	 struct {
		unsigned char HeartBeatSignal : 4;//心跳命令
        unsigned char Reserve1 : 4;//保留
        unsigned char BMSPowerCommand;//BMS上电命令
        unsigned char Reserve2;//保留
        unsigned char Reserve3;//保留
        unsigned char Reserve4;//保留
        unsigned char Reserve5;//保留
	    unsigned char Reserve6;//保留
	 };
	 unsigned char byte[8];
}_CAN_0x0CFF1501;

typedef union {

	 struct {
		unsigned char BMS_ChargingModel : 3;//电池充放电模式
        unsigned char Reserve : 3;//保留
        unsigned char BMS_BasicStatus : 2;//BMS基本状态位
        unsigned char BMS_Average_Temp;//电池组平均温度
        unsigned char BMS_SOC;//电池组SOC
        unsigned BMS_Current ;//电池组充放电电流
        unsigned BMS_Voltage ;//电池组总电压
	    unsigned char Reserve1 : 4;//保留
        unsigned char High_Voltage_RelayStatus : 4;//高压继电器状态
	 };
	 unsigned char byte[8];
}_CAN_0x10F8159E;

typedef union {

	 struct {
		unsigned char BMS_AllowMAXTemp;//电池组允许最高温度
        unsigned char BMS_AllowMINTemp;//电池组允许最低温度
        unsigned char BMS_AllowMINSOC;//电池组允许最低使用SOC
        unsigned BMS_AllowMAXDischargeCurrent;//电池组最大允许放电电流
        unsigned BMS_AllowMAXRecycleCurrent;//电池组最大允许回收电流
        unsigned char Reserve;//保留
	 };
	 unsigned char byte[8];
}_CAN_0x10F8169E;

typedef union {

	 struct {
		unsigned char BMS_MIN_Temp;//电池最低温度
        unsigned char BMS_MIN_Temp_CellNum;//电池组最低温度单体编号
        unsigned char BMS_MIN_Temp_CaseNum;//电池组最低温度所在箱体编号
        unsigned char BMS_MAX_Temp;//电池最高温度
        unsigned char BMS_MAX_Temp_CellNum;//电池组最高温度单体编号
        unsigned char BMS_MAX_Temp_CaseNum;//电池组最高温度所在箱体编号
        unsigned char Reserve1;//保留
	    unsigned char Reserve2;//保留
	 };
	 unsigned char byte[8];
}_CAN_0x18F8179E;

typedef union {

	 struct {
		unsigned char TotalVoltageFaultStatus : 4;//总压故障状态
        unsigned char CellVoltageFaultStatus : 4;//单体电压故障状态
        unsigned char TempFaultStatus : 6;//温度故障状态
        unsigned char InsulationResisitanceFaultStatus : 2;//绝缘阻值故障状态
        unsigned char BMS_CellUniformityStatus : 2;//电池单体一致性状态
        unsigned char SOCFaultStatus : 6;//SOC故障状态
        unsigned char CurrentFault : 4;//电流故障
	    unsigned char HVILStatus : 2;//高压互锁状态
        unsigned char BMSInsideFault : 2;//BMS内部故障
        unsigned char StoredEnergySYSMismatchWarning : 1;//可充电储能系统不匹配报警
        unsigned char Reserve1 : 7;//保留
        unsigned char Reserve2;//保留
        unsigned char Reserve3;//保留
        unsigned char Reserve4;//保留
	 };
	 unsigned char byte[8];
}_CAN_0x08F8189E;

typedef union {

	 struct {
		unsigned InsulationResistance;//绝缘阻值
        unsigned char StoredEnergyCellVoltageNUM;//可充电储能单体电压总数
        unsigned char StoredEnergyCellTempNUM;//可充电储能单体温度总数
        unsigned char StoredEnergySYSNUM;//可充电储能子系统个数
        unsigned char StoredEnergySYSNum;//可充电储能子系统号
        unsigned char Reserve1;//保留
        unsigned char Reserve2;//保留
	 };
	 unsigned char byte[8];
}_CAN_0x18F8199E;

typedef union {

	 struct {
		unsigned BMS_MIN_Cell_Voltage;//电池最低单体电压
        unsigned char BMS_MIN_Cell_Voltage_Num;//电池最低单体电压编号
        unsigned char BMS_MIN_Cell_Voltage_CaseNum;//电池最低单体电压所在箱体号
        unsigned BMS_MAX_Cell_Voltage;//电池最高单体电压
        unsigned char BMS_MAX_Cell_Voltage_Num;//电池最高单体电压编号
        unsigned char BMS_MAX_Cell_Voltage_CaseNum;//电池最高单体电压所在箱体号
	 };
	 unsigned char byte[8];
}_CAN_0x18F81A9E;

typedef union {

	 struct {
		unsigned char Gear : 2;//档位
        unsigned char Reserve1 : 6;//保留
        DATA_BIT Notice1;//提示信息1
        DATA_BIT Notice2;//提示信息2
        DATA_BIT Notice3;//提示信息3
        unsigned VCU_FaultCode;//故障代码
        unsigned VCU_MotorSpeed;//电机转速
	 };
	 unsigned char byte[8];
}_CAN_0x08019F80;

typedef union {

	 struct {
		unsigned Voltage;//母线电压
        unsigned Current;//母线电流
        unsigned char MotorCtrlTemp;//电机控制器温度
        unsigned char DriveMotorTemp;//驱动电机温度
        unsigned char SOC;//SOC
        unsigned char Speed;//车速
	 };
	 unsigned char byte[8];
}_CAN_0x08029F80;

typedef union {

	 struct {
		unsigned DriveMileage;//续驶里程
        unsigned RunningPower;//运行功率
        unsigned char VehicleLockingStatus;//车辆锁车状态
        unsigned char AcceleratePedalAperture;//加速踏板开度
        unsigned char BrakePedalAperture;//制动踏板开度
        unsigned char Reserve;//保留
	 };
	 unsigned char byte[8];
}_CAN_0x08039F80;

typedef union {

	 struct {
		unsigned char VehicleStatus : 2;//车辆状态
        unsigned char RunningModel : 3;//运行模式
        unsigned char DCDCStatus : 2;//DCDC状态
        unsigned char Reserve1 : 1;//保留
        unsigned char DriveMotorStatus : 3;//驱动电机状态
        unsigned char DriveMotorNum : 1;//驱动电机序号
        unsigned char DriveMotorNUM : 1;//驱动电机个数
	    unsigned char Reserve2 : 3;//保留
        unsigned char VCU_CtrlTemp;//控制器温度
        unsigned char VCU_DriveMotorTemp;//驱动电机温度
        unsigned VCU_DriveMotorRotateSpeed;//驱动电机转速
        unsigned VCU_DriveMotorTorque;//驱动电机转矩
	 };
	 unsigned char byte[8];
}_CAN_0x08049F80;

typedef union {

	 struct {
		unsigned VCU_MotorCtrlInputVoltage;//电机控制器输入电压
        unsigned VCU_CtrlCurrent;//控制器直流母线电流
        unsigned char DriveMotorFaultNUM;//驱动电机故障总数
        unsigned char DCDCTempWarning : 1;//DCDC温度报警
        unsigned char DCDCStatusWarning : 1;//DCDC状态报警
        unsigned char MotorCtrlTempWarning : 1;//电机控制器温度报警
        unsigned char DriveMotorTempWarning : 1;//驱动电机温度报警
        unsigned char Reserve1 : 4;//保留
	    unsigned char Reserve2;//保留
        unsigned char Reserve3;//保留
	 };
	 unsigned char byte[8];
}_CAN_0x08059F80;

typedef union {

	 struct {
		unsigned DCDC_InputVoltage;//输入电压
        unsigned char DCDC_InputCurrent;//输入电流
        unsigned char DCDC_OutputCurrent;//输出电流
        unsigned char DCDC_CtrlTemp;//控制器温度
        unsigned char DCDC_OutputAssistLowVoltage;//输出辅助低压
        unsigned char DCDC_Life;//DCDC_Life
        unsigned char DCDC_FaultCode : 4;//故障码
	    unsigned char DCDC_Status : 2;//DCDC状态
        unsigned char Reserve : 1;//保留
        unsigned char DCDC_CtrlPrechargeStatus : 1;//控制器预充状态
	 };
	 unsigned char byte[8];
}_CAN_0x142CFF98;

typedef union {

	 struct {
		unsigned DCAC_MotorRotateSpeed;//电机转速
        unsigned DCAC_CtrlVoltage;//控制器母线电压
        unsigned char DCAC_CtrlCurrent;//控制器电流
        unsigned char DCAC_CtrlTemp;//控制器温度
        unsigned char DCAC_Life;//DCAC_Life
        unsigned char DCAC_FaultCode : 4;//故障码
        unsigned char DCAC_PumpStatus : 2;//气泵状态
	    unsigned char Reserve : 1;//保留
        unsigned char DCAC_CtrlPrechargeStatus : 1;//控制器预充状态
	 };
	 unsigned char byte[8];
}_CAN_0x1429FF9B;

typedef union {

	 struct {
		unsigned char VCU_CtrlWorkCommand;//控制工作命令
        unsigned char Reserve1;//保留
        unsigned char Reserve2;//保留
        unsigned char Reserve3;//保留
        unsigned char Reserve4;//保留
        unsigned char Reserve5;//保留
        unsigned char Reserve6;//保留
	    unsigned char Reserve7;//保留
	 };
	 unsigned char byte[8];
}_CAN_0x0C6CA4D7;

typedef union {

    struct {
        unsigned char Reserve1 : 4; //保留
        unsigned char Lane_Depature_Right : 2; //（右车道偏离）
        unsigned char Lane_Depature_Left : 2; //（左车道偏离）
        unsigned char warning : 1; //碰撞预警
        unsigned char Reserve2 : 7; //保留
        unsigned char Reserve3; //保留
        unsigned char Reserve4; //保留
        unsigned char Reserve5; //保留
        unsigned char Reserve6; //保留
        unsigned char Reserve7; //保留
        unsigned char Reserve8; //保留
    };
    unsigned char byte[8];
} _CAN_0x10F007E8;
#endif

typedef union {

    struct {
        unsigned char DriverMode : 2; //行驶模式
        unsigned char Gear : 4; //档位
        unsigned char Reserve1 : 2;

        unsigned char AcceleratePedalAperture; //加速踏板开度
        unsigned Speed; //车速
        unsigned char BrakePedalAperture; //制动踏板开度
        unsigned char Reserve2;

        unsigned char LimitTorque : 1; //
        unsigned char LimitPower : 1; //
        unsigned char LimitPower3 : 4; //
        unsigned char SystemFault : 1; //
        unsigned char READY : 1; //

        unsigned char VcuLife; //
    };
    unsigned char byte[8];
} _CAN_0x0CF101A7;

typedef union {

    struct {
        unsigned char ProductCode; //系统厂家代码
        unsigned char ContactorOrder; //VCU上高压指令    
        unsigned McuInputVoltage; //电机控制器母线电压
        unsigned char Reserve1; //

        unsigned char Reserve2 : 5; //
        unsigned char ChargeStatus : 2; //BMS 充电控制指令及状态
        unsigned char ChargeEn : 1;

        unsigned char ContactorStatus; //高压继电器状态
        unsigned char VcuLife;
    };
    unsigned char byte[8];
} _CAN_0x0CF103A7;

typedef union {

    struct {
        unsigned char FaultLevel : 3; //整车故障等级 
        unsigned char Reserve1 : 5;

        unsigned VCU_DTC; //整车故障码
        unsigned char Reserve2;

        unsigned char Ganzaopin : 1; //空压机过温
        unsigned char AirOverTemp : 1; //空压机过温
        unsigned char Reserve3 : 6;

        unsigned char Reserve4;
        unsigned char Reserve5;
        unsigned char Reserve6;
    };
    unsigned char byte[8];
} _CAN_0x0CF1064A;

typedef union {

    struct {
        unsigned CtrlVoltage; //控制器输入电压
        unsigned CtrlCurrent; //控制器母线电流

        unsigned char Reserve1 : 2;
        unsigned char IpuMode : 5;
        unsigned char Reserve2 : 1;

        DATA_BIT Diagnosis1;
        unsigned char Reserve4;

        unsigned char Reserve5 : 4;
        unsigned char McuLife : 4;
    };
    unsigned char byte[8];
} _CAN_0x18F11FF0;

typedef union {

    struct {
        unsigned MotorTopTorque;
        unsigned MotorSpeed;
        unsigned MotorTorque;
        unsigned char MotorTemp; //电机温度
        unsigned char MotorCtrlTemp; //电机控制器温度
    };
    unsigned char byte[8];
} _CAN_0x18F120F0;

typedef union {

    struct {
        unsigned char MotorCtrlStatus;
        unsigned char MotorCtrlFaultCode;
        unsigned Reserve1;
        unsigned Reserve2; //
        unsigned Reserve3; //
    };
    unsigned char byte[8];
} _CAN_0x18F121F0;

typedef union {

    struct {
        unsigned Voltage; //母线电压
        unsigned Current; //母线电流
        unsigned SOC; //SOC

        unsigned char BmsFaultLevel : 3; //
        unsigned char BmsRequest : 2; //
        unsigned char BmsCheckout : 3; //

        unsigned char Contactor1 : 2;
        unsigned char Contactor2 : 2;
        unsigned char Contactor3 : 2;
        unsigned char Contactor4 : 2;
    };
    unsigned char byte[8];
} _CAN_0x18F13DF3;

typedef union {

    struct {
        unsigned BMS_MAX_Cell_Voltage; //电池最高单体电压
        unsigned BMS_MIN_Cell_Voltage; //电池最低单体电压
        unsigned char BMS_MAX_Temp; //电池最高温度
        unsigned char BMS_MIN_Temp; //电池最低温度
        unsigned char Reserve1; //
        unsigned char Reserve2; //
    };
    unsigned char byte[8];
} _CAN_0x18F13EF3;

typedef union {

    struct {
        unsigned LimitChargeCurrent;
        unsigned LimitDischargeCurrent;
        unsigned char LimitHighTemp;
        unsigned char LimitLowTemp;
        unsigned char LimitSOC;
        unsigned char Reserve1; //
    };
    unsigned char byte[8];
} _CAN_0x18F140F3;

typedef union {

    struct {
        unsigned char BmsFaultCode;
        unsigned char ChargeTime;
        unsigned char ChargeStatus;

        unsigned char BmsBalance : 1;
        unsigned char Reserve1 : 7;

        unsigned char ChargeGun;
        unsigned char Reserve2;
        unsigned char BmsLife;
        unsigned char Reserve3;
    };
    unsigned char byte[8];
} _CAN_0x18F141F3;

typedef union {

    struct {
        unsigned BatAH; //动力电池的额定容量
        unsigned BatVoltage; //动力电池的额定总电压
        unsigned char BatYear;
        unsigned char BatMonth;
        unsigned char BatDate;
        unsigned char Reserve;
    };
    unsigned char byte[8];
} _CAN_0x18F148F3;

typedef union {

    struct {
        unsigned SwitcherMotorSpeed; //电机转速
        unsigned SwitcherCtrlVoltage; //控制器母线电压
        unsigned char SwitcherCtrlCurrent; //控制器电流
        unsigned char SwitcherCtrlTemp; //控制器温度
        unsigned char SwitcherLife; //转向助力Life

        unsigned char SwitcherFaultCode : 4; //故障码
        unsigned char SwitcherPumpStatus : 2; //气泵状态
        unsigned char SwitcherFeedback : 1; //反馈状态
        unsigned char SwitcherCtrlPrechargeStatus : 1; //控制器预充状态
    };
    unsigned char byte[8];
} _CAN_0x142FFF95;

typedef union {

    struct {
        unsigned DCDC_InputVoltage; //输入电压
        unsigned char DCDC_InputCurrent; //输入电流
        unsigned char DCDC_OutputCurrent; //输出电流
        unsigned char DCDC_CtrlTemp; //控制器温度
        unsigned char DCDC_OutputAssistLowVoltage; //输出辅助低压
        unsigned char DCDC_Life; //DCDC_Life
        unsigned char DCDC_FaultCode : 4; //故障码
        unsigned char DCDC_Status : 2; //DCDC状态
        unsigned char Reserve : 1; //保留
        unsigned char DCDC_CtrlPrechargeStatus : 1; //控制器预充状态
    };
    unsigned char byte[8];
} _CAN_0x142CFF98;

typedef union {

    struct {
        unsigned DCAC_MotorRotateSpeed; //电机转速
        unsigned DCAC_CtrlVoltage; //控制器母线电压
        unsigned char DCAC_CtrlCurrent; //控制器电流
        unsigned char DCAC_CtrlTemp; //控制器温度
        unsigned char DCAC_Life; //DCAC_Life
        unsigned char DCAC_FaultCode : 4; //故障码
        unsigned char DCAC_PumpStatus : 2; //气泵状态
        unsigned char Reserve : 1; //保留
        unsigned char DCAC_CtrlPrechargeStatus : 1; //控制器预充状态
    };
    unsigned char byte[8];
} _CAN_0x1429FF9B;

typedef union {

    struct {
        DATA_BIT AcSystemFault; //空调系统故障

        unsigned char Reserve1 : 5;
        unsigned char AcFanStatus : 3; //空调系统风机运行状态

        unsigned char AcSystemStatus; //空调系统运行状态
        unsigned char AcIndoorTemp; //车内温度
        unsigned char AcOutdoorTemp; //车外温度
        unsigned char Reserve2; //保留
        unsigned char Reserve3; //保留
        unsigned char AcLife; //电空调控制器通信状态值：循环递增变化，以此断定通信有效
    };
    unsigned char byte[8];
} _CAN_0x18FFC09E;

typedef union {

    struct {
        unsigned char InsulationResisitanceFaultLevel : 3; //绝缘阻值故障状态
        unsigned char Reserve1 : 5;

        unsigned InsulationResistanceP; //正极绝缘阻值
        unsigned InsulationResistanceN; //负极绝缘阻值
        unsigned char InsulationResistanceFaultCode;
        DATA_BIT FaultMesg;
        unsigned InsulationLife;
    };
    unsigned char byte[8];
} _CAN_0x18F746E5;

typedef union {

    struct {
        unsigned char FogWarnStatus : 4; //烟雾报警器状态
        unsigned char Reserve1 : 4; //
        
        unsigned char WarnStatus : 1;
        unsigned char Reserve2 : 7; 
        
        unsigned char TempWarn : 1;
        unsigned char Reserve3 : 7;
        
        unsigned char Temp;
        unsigned char Reserve4;
        unsigned char Reserve5;
        unsigned char Reserve6;
        unsigned char Life;
    };
    unsigned char byte[8];
} _FogWarn;
#pragma pack()

extern	unsigned char BMS_MIN_Temp[4];
extern	unsigned char BMS_MIN_Temp_CaseNum[4];

extern	unsigned char BMS_MAX_Temp[4];
extern	unsigned char BMS_MAX_Temp_CaseNum[4];

extern	unsigned BMS_MAX_Cell_Voltage[4];
extern	unsigned char BMS_MAX_Cell_Voltage_Num[4];
extern	unsigned char BMS_MAX_Cell_Voltage_CaseNum[4];

extern	unsigned BMS_MIN_Cell_Voltage[4];
extern	unsigned char BMS_MIN_Cell_Voltage_Num[4];
extern	unsigned char BMS_MIN_Cell_Voltage_CaseNum[4];

#if 0
extern _CAN_0x0CFF1501 CAN_0x0CFF1501;
extern _CAN_0x10F8159E CAN_0x10F8159E;
extern _CAN_0x10F8169E CAN_0x10F8169E;
extern _CAN_0x18F8179E CAN_0x18F8179E;
extern _CAN_0x08F8189E CAN_0x08F8189E;
extern _CAN_0x18F8199E CAN_0x18F8199E;
extern _CAN_0x18F81A9E CAN_0x18F81A9E;
extern _CAN_0x08019F80 CAN_0x08019F80;
extern _CAN_0x08029F80 CAN_0x08029F80;
extern _CAN_0x08039F80 CAN_0x08039F80;
extern _CAN_0x08049F80 CAN_0x08049F80;
extern _CAN_0x08059F80 CAN_0x08059F80;
extern _CAN_0x142CFF98 CAN_0x142CFF98;
extern _CAN_0x1429FF9B CAN_0x1429FF9B;
extern _CAN_0x0C6CA4D7 CAN_0x0C6CA4D7;
extern _CAN_0x10F007E8 CAN_0x10F007E8;
#endif

extern	_CAN_0x0CF101A7 CAN_0x0CF101A7;
extern	_CAN_0x0CF103A7 CAN_0x0CF103A7;
extern	_CAN_0x0CF1064A CAN_0x0CF1064A;
extern	_CAN_0x18F11FF0 CAN_0x18F11FF0;
extern	_CAN_0x18F120F0 CAN_0x18F120F0;
extern	_CAN_0x18F121F0 CAN_0x18F121F0;
extern	_CAN_0x18F13DF3 CAN_0x18F13DF3;
extern	_CAN_0x18F13EF3 CAN_0x18F13EF3;
extern	_CAN_0x18F140F3 CAN_0x18F140F3;
extern	_CAN_0x18F141F3 CAN_0x18F141F3;
extern	_CAN_0x18F148F3 CAN_0x18F148F3;
extern	_CAN_0x142FFF95 CAN_0x142FFF95;
extern	_CAN_0x142CFF98 CAN_0x142CFF98;
extern	_CAN_0x1429FF9B CAN_0x1429FF9B;
extern	_CAN_0x18FFC09E CAN_0x18FFC09E;
extern	_CAN_0x18F746E5 CAN_0x18F746E5;
extern	_FogWarn FogWarn[3];
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

