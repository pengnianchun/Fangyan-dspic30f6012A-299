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
        unsigned VCUFaultCode; //VCU故障代码
        unsigned char AcceleratePedal;//加速踏板
        unsigned char BrakePedal;//制动踏板
        unsigned char VCUSpeed;//VCU发送车速
        DATA_BIT VCUStatus1;
        DATA_BIT VCUStatus2;
        unsigned char VCUGear : 4;//VCU档位
        unsigned char VCULife : 4;//VCULife
    };
    unsigned char byte[8];
} _CAN_0x0CFF045A;

typedef union {

    struct {
        unsigned Mile; //续驶里程
        unsigned char MotorTemperature_Controller; //电机控制器温度
        unsigned char MotorTemperature; //电机温度
        unsigned MotoSpeed; //电机转速      
        unsigned char LockStatus; //车辆锁车状态
        unsigned char Reserve : 4;//
        unsigned char VCULife : 4;//VCULife
    };
    unsigned char byte[8];
} _CAN_0x0CFF055A;

typedef union {
    
    struct {
        unsigned char VCU_Enabled : 1;//使能
        unsigned char VCU_Fault_Reset : 1;//故障重置
        unsigned char VCU_Control_Model : 2;//控制模式
        unsigned char VCU_Life : 4;//VCUlife
        unsigned char VCU_Gear;//档位
        unsigned VCU_Target_Torque;//目标转矩
        unsigned VCU_Target_Rotate_Speed;//目标转速
        unsigned char Reserve1;//保留
        unsigned char Reserve2;//保留
    };
    unsigned char byte[8];
} _CAN_0x0CFF015A;

typedef union {
    
    struct {
        unsigned VCU_Drive_Torque_Limit;//驱动扭矩限值
        unsigned VCU_Brake_Torque_Limit;//制动扭矩限值
        unsigned VCU_Rotate_Speed_Forwardlimit;//转速正向限值
        unsigned VCU_Rotate_Speed_Invertlimit;//转速反向限值
    };
    unsigned char byte[8];
} _CAN_0x0CFF025A;

typedef union {
    
    struct {
        unsigned MCU_Feedback_Rotate_Speed;//反馈转速
        unsigned MCU_Feedback_Torque;//反馈转矩
        unsigned MCU_AlterCurrent_Effect;//交流电流有效值
        unsigned char Reserve1 : 4;//保留
        unsigned char MCU_Allow_Precharge : 1;//允许预充
        unsigned char MCU_DischargeStatus_Feedback : 1;//主动放电状态反馈
        unsigned char MCU_IGBTEnabledStatus_Feedback : 1;//IGBT使能状态反馈
        unsigned char Reserve2 : 1;//保留
        unsigned char MCU_WorkStatus_Feedback : 4;//工作状态反馈
        unsigned char MCU_Life : 4;//MCU_Life
    };
    unsigned char byte[8];
} _CAN_0x18FF115B;

typedef union {
    
    struct {
        unsigned char MCU_MotorTemp;//电机温度
        unsigned char MCU_ContorlTemp;//控制器温度
        unsigned MCU_Torque_Toplimit;//转矩上限
        unsigned MCU_Torque_Lowlimit;//转矩下限
        unsigned char MCU_FaultLevel : 4;//故障等级
        unsigned char MCU_DirveMotorStatus : 4;//驱动电机状态
        unsigned char MCU_Motor_ControlOverHeat : 1;//电机控制器超温
        unsigned char MCU_MotorOverHeat : 1;//电机超温
        unsigned char Reserve : 2;//保留
        unsigned char MCU_Life : 4;//MCU_Life
    };
    unsigned char byte[8];
} _CAN_0x18FF125B;

typedef union {
    
    struct {
        unsigned MCU_Current;//直流电流
        unsigned MCU_Voltage;//直流电压
        unsigned char MCU_FaultCode;//故障码
        
        unsigned char MCU_PhaseCurrentFault : 1;//相电流故障
        unsigned char MCU_InventerFault : 1;//逆变器故障
        unsigned char MCU_SensorPowerFault : 1;//传感器供电故障
        unsigned char MCU_MotorSensorFault : 1;//电机位置传感器故障
        unsigned char MCU_CurrentOverVoltageFault: 1;//直流母线过压故障
        unsigned char MCU_CurrentUnderVoltageFault : 1;//直流母线欠压故障
        unsigned char MCU_MotorOverHeatFault : 1;//电机过温故障
        unsigned char MCU_InventerOverHeatFault : 1;//逆变器过温故障
        
        unsigned char MCU_MotorOverSpeedWarning : 1;//电机超速故障
        unsigned char MCU_PhaseCurrentWarning : 1;//相电流过流报警
        unsigned char MCU_MotorTempWarning : 1;//电机温度报警
        unsigned char MCU_InventerTempWarning : 1;//逆变器温度报警
        unsigned char CAN_Disconnect : 1;//CAN总线断开
        unsigned char MCU_LowVoltageDCFault : 1;//低压直流电源故障
        unsigned char MCU_Fault : 1;//MCU故障
        unsigned char MCU_MotorCtrlModelError : 1;//电机控制器模式错误
        
        unsigned char Reserve : 4;//保留
        unsigned char MCU_Life : 4;//MCU_Life
    };
    unsigned char byte[8];
} _CAN_0x18FF135B;

typedef union {
    
    struct {
        unsigned char BMS_HighVoltageCommand;//高压上下电指令
        unsigned char BMS_Life;//BMS_Life
        unsigned BMS_MotorCtrlVoltage;//电机控制器母线电压
        unsigned BMS_MotorCtrlCurrent;//电机控制器母线电流
        unsigned char Reserve1;//保留
        unsigned char Reserve2;//保留
    };
    unsigned char byte[8];
} _CAN_0x0CFF035A;

typedef union {
    
    struct {
        unsigned char BMS_HighVoltage;//高压上下电
        unsigned char BMS_FaultLevel : 2;//系统故障等级
        unsigned char BMS_ChargeModel : 3;//充放电模式
        unsigned char BMS_SelfChecking : 2;//BMS自检状态
        unsigned char Reserve1 : 1;//保留
        unsigned char BMS_Resistance;//电池系统内阻
        DATA_BIT  BMS_Status;//BMS状态
        unsigned BMS_Voltage;//电池组总电压
        unsigned BMS_Current;//电池组总电流
    };
    unsigned char byte[8];
} _CAN_0x18FF015C;

typedef union {
    
    struct {
        unsigned BMS_OutputVoltage;//电池组输出总电压
        unsigned char BMS_SOC;//SOC
        unsigned char BMS_SOH;//SOH
        unsigned char BMS_MAXSustainChargePower;//最大可用持续充电功率
        unsigned char BMS_MAXSnatchChargePower;//最大可用短时充电功率
        unsigned char BMS_MAXSustainDischargePower;//最大可用持续放电功率
        unsigned char BMS_MAXSnatchDischargePower;//最大可用短时放电功率
    };
    unsigned char byte[8];
} _CAN_0x18FF025C;

typedef union {
    
    struct {
        unsigned char BMS_DumpEnergy;//电池组输出总电压
        unsigned char BMS_Cell_Average_Temp;//SOC
        unsigned char BMS_Cell_Max_Temp;//SOH
        unsigned char BMS_Cell_Min_Temp;//最大可用持续充电功率
        unsigned BMS_Cell_Max_Voltage;//最大可用短时充电功率
        unsigned BMS_Cell_Min_Voltage;//最大可用持续放电功率
    };
    unsigned char byte[8];
} _CAN_0x18FF035C;

typedef union {
    
    struct {
        unsigned char BMS_Cell_Max_Temp_Num;//电池最高单体温度编号
        unsigned char BMS_Cell_Min_Temp_Num;//电池最低单体温度编号
        unsigned char BMS_Cell_Max_Voltage_Num;//电池最高单体电压编号
        unsigned char BMS_Cell_Min_Voltage_Num;//电池最低单体电压编号
        unsigned char BMS_ChargingGun_Anode_Temp;//直流充电枪正极温度
        unsigned char BMS_ChargingGun_Cathode_Temp;//直流充电枪负极温度
        unsigned char BMS_AlterCurrent_ChargingGun_Temp;//交流充电枪温度
        unsigned char Reserve;//保留
    };
    unsigned char byte[8];
} _CAN_0x18FF045C;

typedef union {
    
    struct {
        unsigned BMS_Insulation_Resistance;//绝缘电阻值
        DATA_BIT BMS_VoltageFault;//电池电压相关故障
        DATA_BIT BMS_TempFault;//电池温度相关故障
        DATA_BIT BMS_SOCFault;//充电及soc相关故障
        DATA_BIT BMS_FaultList;//故障列表
        unsigned char BMS_Intercom : 1;//内部通讯故障
        unsigned char Reserve1 : 7;//保留
        unsigned char Reserve2;//保留
    };
    unsigned char byte[8];
} _CAN_0x18FF055C;

typedef union {

	 struct {
		unsigned char BMS_Max_Voltage_Num;//最高电压电池子系统号
        unsigned char BMS_Min_Voltage_Num;//最低电压电池子系统号
        unsigned char BMS_Max_Temp_Num;//最高温度子系统号
        unsigned char BMS_Max_Temp_ProbeNum;//最高温度探针序号
        unsigned char BMS_Min_Temp_Num;//最低温度子系统号
        unsigned char BMS_Min_Temp_ProbeNum;//最低温度探针序号
        DATA_BIT BMS_Warning;//电池相关报警
	    DATA_BIT BMS_Warning1;//电池相关报警
	 };
     unsigned char byte[8];
}_CAN_0x18FF065C;

typedef union {

	 struct {
		unsigned char BMS_StoredEnergySYS_NUM;//可充电储能子系统个数
        unsigned char BMS_StoredEnergySYS_Num;//可充电储能子系统号
        unsigned char BMS_Cell_NUM;//单体电池总数
        unsigned char BMS_StoredEnergyTempProbe_NUM;//可充电储能温度探针个数
        unsigned char BMS_BMS_StoredEnergyFault_NUM;//可充电储能装置故障总数
        unsigned char Reserve1;//保留
        unsigned char Reserve2;//保留
	    unsigned char Reserve3;//保留
	 };
	 unsigned char byte[8];
}_CAN_0x18FF075C;

typedef union {

	 struct {
		unsigned BMS_Cell1_Voltage;//单体电池电压
        unsigned BMS_Cell2_Voltage;
        unsigned BMS_Cell3_Voltage;
        unsigned BMS_Cell4_Voltage;
	 };
	 unsigned char byte[8];
}_CAN_Cell_Voltage;

typedef union {

	 struct {
		unsigned char BMS_Cell1_Temp;//单体电池温度
        unsigned char BMS_Cell2_Temp;
        unsigned char BMS_Cell3_Temp;
        unsigned char BMS_Cell4_Temp;
        unsigned char BMS_Cell5_Temp;
        unsigned char BMS_Cell6_Temp;
        unsigned char BMS_Cell7_Temp;
	    unsigned char BMS_Cell8_Temp;
	 };
	 unsigned char byte[8];
}_CAN_Cell_Temp;

typedef union {

	 struct {
		unsigned DCDC_Input_Voltage;//输入电压
        unsigned char DCDC_Input_Current;//输入电流
        unsigned char DCDC_Output_Voltage;//输出电压
        unsigned char DCDC_Output_Current;//输出电流
        unsigned char DCDC_CtrlTemp;//控制器温度
        unsigned char DCDC_CtrlPrechargeStatus : 1;//控制器预充状态
        unsigned char Reserve : 1;//保留
	    unsigned char DCDC_Status : 2;//DCDC状态
        unsigned char DCDC_FaultCode : 4;//故障码
        unsigned char DCDC_Life;//DCDC_Life
	 };
	 unsigned char byte[8];
}_CAN_0x0CFF016B;

typedef union {

	 struct {
		unsigned DCDC_PumpMotorRotateSpeed;//电机转速
        unsigned DCDC_PumpCtrlVoltage;//控制器母线电压
        unsigned char DCDC_PumpCtrlCurrent;//控制器电流
        unsigned char DCDC_PumpCtrlTemp;//气泵控制器温度
        unsigned char DCDC_PumpCtrlPrechargeStatus : 1;//控制器预充状态
        unsigned char Reserve : 1;//保留
        unsigned char DCDC_PumpStatus : 2;//气泵状态
	    unsigned char DCDC_PumpFaultCode : 4;//气泵故障码
        unsigned char DCDC_PumpLife;//DCDC气泵Life
	 };
	 unsigned char byte[8];
}_CAN_0x0CFF026B;

typedef union {

	 struct {
		unsigned DCDC_OilPumpMotorRotateSpeed;//电机转速
        unsigned DCDC_OilPumpCtrlVoltage;//控制器母线电压
        unsigned char DCDC_OilPumpCtrlCurrent;//控制器电流
        unsigned char DCDC_OilPumpCtrlTemp;//油泵控制器温度
        unsigned char DCDC_OilPumpCtrlPrechargeStatus : 1;//控制器预充状态
        unsigned char DCDC_OilPumpCtrlCtrledStatus : 1;//控制器受控状态
        unsigned char DCDC_OilPumpStatus : 2;//油泵状态
	    unsigned char DCDC_OilPumpFaultCode : 4;//油泵故障码
        unsigned char DCDC_OilPumpLife;//DCDC油泵Life
	 };
	 unsigned char byte[8];
}_CAN_0x0CFF036B;

typedef union {

	 struct {
		unsigned char DCDC_OilPumpOutputVoltageHZ;//油泵控制器输出电压和频率
        unsigned char DCDC_PumpOutputVoltageHZ;//气泵控制器输出电压和频率
        unsigned char DCDC_PowerCommand;//DCDC电源控制命令
        unsigned char DCDC_OilPumpCtrlCommand;//油泵控制器控制命令
        unsigned char DCDC_PumpCtrlCommand;//气泵控制器控制命令
        unsigned char Reserve1;//保留
        unsigned char Reserve2;//保留
	    unsigned char Reserve3;//保留
	 };
	 unsigned char byte[8];
}_CAN_0x0CFF065A;

typedef union {

	 struct {
		unsigned char VCU_VehicleStatus;//车辆状态
        unsigned char VCU_ChargingStatus;//充电状态
        unsigned char VCU_RunModel;//运行模式
        unsigned Speed;//车速
        unsigned char SOC;//SOC
        unsigned char DCDC_Status;//DCDC状态
        unsigned char Gear : 4;//档位
	    unsigned char BrakePower : 1;//制动力
        unsigned char DrivePower : 1;//驱动力
        unsigned char Reserve : 2;//
	 };
	 unsigned char byte[8];
}_CAN_0x18FF015A;

typedef union {

	 struct {
		unsigned long VCU_Odometer;//累计里程
        unsigned  VCU_Voltage;//总电压
        unsigned  VCU_Current;//总电流
	 };
	 unsigned char byte[8];
}_CAN_0x18FF025A;

typedef union {

	 struct {
		unsigned VCU_Insulation_Resistance;//绝缘电阻
        unsigned char VCU_Accelerator_Pedal;//加速踏板行程值
        unsigned char VCU_Brake_PedalStatus;//制动踏板状态
        unsigned VCU_NMotorCtrlInputVoltage;//N号电机控制器输入电压
        unsigned VCU_NMotorCtrlCurrent;///N号电机控制器直流母线电流
	 };
	 unsigned char byte[8];
}_CAN_0x18FF035A;

typedef union {

	 struct {
		unsigned char VCU_DriverMotor_NUM : 4;//驱动电机个数
        unsigned char VCU_DriverMotor_Num: 4;//驱动电机序号N
        unsigned char VCU_NDriverMotorStatus;//N号驱动电机状态
        unsigned char VCU_NDriverCtrl_Temp;//N号驱动电机控制器温度
        unsigned VCU_NDriverMotorRotateSpeed;//N号驱动电机转速
        unsigned VCU_NDriverMotorTorque;//N号驱动电机转矩
        unsigned char VCU_NDriverMotorTemp;//N号驱动电机温度
	 };
	 unsigned char byte[8];
}_CAN_0x18FF045A;

typedef union {

	 struct {
		unsigned char MAXVoltageSYSNum;//最高电压电池子系统号
        unsigned char MAXVoltageCellNum;//最高电压电池单体代号
        unsigned  CellMAXVoltage;//电池单体电压最高值
        unsigned char MINVoltageSYSNum;//最低电压电池子系统号
        unsigned char MINVoltageCellNum;//最低电压电池单体代号
        unsigned CellMINVoltage;//电池单体电压最低值
	 };
	 unsigned char byte[8];
}_CAN_0x18FF055A;

typedef union {

	 struct {
		unsigned char MAXTempSYSNum;//最高温度子系统号
        unsigned char MAXTempProdeNum;//最高温度探针序号
        unsigned char MAXTemp;//最高温度值
        unsigned char MINTempSYSNum;//最低温度子系统号
        unsigned char MINTempProdeNum;//最低温度探针序号
        unsigned char MINTemp;//最低温度值
        unsigned char Reserve1;//保留
	    unsigned char Reserve2;//保留
	 };
	 unsigned char byte[8];
}_CAN_0x18FF065A;

typedef union {

	 struct {
		unsigned char HighestWarningLevel;//最高报警等级
        DATA_BIT Warning1;//报警信号
        DATA_BIT Warning2;//报警信号
        unsigned char Warning3 : 3;//报警信号
        unsigned char Reserve1 : 5;//保留
        unsigned char Reserve2;//保留
        unsigned char Reserve3;//保留
	    unsigned char Reserve4;//保留
        unsigned char Reserve5;//保留
	 };
	 unsigned char byte[8];
}_CAN_0x18FF075A;

typedef union {

	 struct {
		unsigned char AnodeCocontactorCtrlCommand;//主正接触器控制命令
        unsigned char CathodeCocontactorCtrlCommand;//主负接触器控制命令
        unsigned char PrechargeCocontactorCtrlCommand;//预充接触器控制命令
        unsigned char RapidChargeCocontactorCtrlCommand;//快充接触器控制命令
        unsigned char TrickleChargeCocontactorCtrlCommand;//慢充接触器控制命令
        unsigned char HeatCocontactorCtrlCommand;//加热接触器控制命令
        unsigned char AIRCtrlCommand;//空调控制命令
	    unsigned char DefrostCtrlCommand;//除霜控制命令
	 };
	 unsigned char byte[8];
}_CAN_0x0CFF075A;

typedef union {

	 struct {
		unsigned char AnodeCocontactorFeedback;//主正接触器反馈
        unsigned char CathodeCocontactorFeedback;//主负接触器反馈
        unsigned char PrechargeCocontactorFeedback;//预充接触器反馈
        unsigned char RapidchargeCocontactorFeedback;//快充接触器反馈
        unsigned char TrikclechargeCocontactorFeedback;//慢充接触器反馈
        unsigned char HeatCocontactorFeedback;//加热接触器反馈
        unsigned char AIR;//空调
	    unsigned char Defrost;//除霜
	 };
	 unsigned char byte[8];
}_CAN_0x18FF016D;
#endif

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
#pragma pack()

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

