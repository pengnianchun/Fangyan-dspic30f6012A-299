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
extern DM1 CAN_18FECAD0;
extern unsigned char CAN_18FECAD0_len;

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
/*******************分包处理*****************/
/*************************************/
//整车控制器信息1 0x0CFFC9D0
extern unsigned char VCU_Status;
extern unsigned char VCU_Gear;
extern unsigned char VCU_Lock_Warn;
extern unsigned char VCU_Brake_Warn;
extern unsigned char VCU_Car_Status;
extern unsigned char VCU_Run_Status;
extern unsigned int  VCU_Speed;
extern unsigned char VCU_Gearbox;
extern unsigned char VCU_Brake_Status;
extern unsigned char VCU_Power_Status;
extern unsigned char VCU_Charge;
extern unsigned char VCU_Warn_Level;

//整车控制器信息2 0x0CFFC8D0
extern unsigned char VCU_Accelerator_percent; //油门踏板开度
extern unsigned char VCU_Brake_percent; //制动踏板开度
extern unsigned char VCU_Fault_Number; //其他故障总数
extern unsigned long VCU_Fault_List; //故障列表
extern unsigned char VCU_Motor_Number; 

//整车控制器控制信息 3（0x0CFFCAD0）
/*unsigned char VCU_Control_OCU;
unsigned char VCU_Control_ACU;
unsigned char VCU_Control_DCDC;
unsigned char VCU_Control_AIR;*/

//主驱状态 1（0x18F501F0）
extern unsigned char MCU_Number;
extern unsigned char MCU_Status;
extern unsigned char MCU_Temp;
extern unsigned char MCU_Controller_Temp;
extern unsigned int  MCU_Voltage;
extern unsigned int  MCU_Curretn;

//主驱状态 2（0x18F502F0）
extern unsigned int  MCU_Rpm;
extern unsigned int  MCU_Torque;

//主驱状态 3（0x18F503F0）
extern unsigned char MCU_Controller_Warn_Temp;
extern unsigned char MCU_Warn_Temp;
extern unsigned char MCU_Warn_Number;

//系统故障信息（0x18FECAD0）

//电池管理系统信息 1（0x18F201F3）
extern unsigned char BMS_SOC;
extern unsigned int  BMS_Voltage; //电池总电压
extern unsigned int  BMS_Current; //电池总电流
extern unsigned char BMS_Charge_Power_Limt; 
extern unsigned char BMS_Discharge_Power_Limt; 
extern unsigned char BMS_Life; 

//高压接触器信息（0x18F202F3）
extern DATA_DOUBLE   CM_Connecter_Status[2];
extern unsigned char CM_Up_Status;
extern unsigned char CM_Down_Status;

//电池报警信息（0x18F203F3）
extern unsigned char BMS_Fault_Code;
extern unsigned char BMS_Fault_Level;
extern DATA_BIT      BMS_Charge_Status;
extern unsigned char BMS_Self_Status;
extern DATA_BIT      BMS_Warn_Message[4];

//电池仓火灾报警信息（0x18F209F3）
extern DATA_BIT      BCEM_Warn_Message[8];

//电池仓火灾报警温度信息（0x18F20AF3）
extern unsigned char BCTM_Temp[8];

//电池单体电压信息（0x18F204F3）
extern unsigned int  Battery_Single_H; //电池单体高电压
extern unsigned int  Battery_Single_L; //电池单体低电压
extern unsigned char Battery_Single_H_Positon_Case; //电池单体高电压箱号
extern unsigned char Battery_Single_H_Positon_Cell; //电池单体高电压位置
extern unsigned char Battery_Single_L_Positon_Case; //电池单体低电压箱号
extern unsigned char Battery_Single_L_Positon_Cell; //电池单体低电压位置

//电池单体温度信息（0x18F205F3）
extern unsigned char Battery_Temp_H; //电池单体最高温度
extern unsigned char Battery_Temp_L; //电池单体最低温度
extern unsigned char Battery_Temp_H_Positon_Case; //电池单体高温度箱号
extern unsigned char Battery_Temp_H_Positon_Cell; //电池单体高温度位置
extern unsigned char Battery_Temp_L_Positon_Case; //电池单体低温度箱号
extern unsigned char Battery_Temp_L_Positon_Cell; //电池单体低温度位置

//绝缘检测仪信息（0x18FF2B49）
extern unsigned char IDE_Message;
extern unsigned int  IDE_Ohm;
extern unsigned int  IDE_Voltage;
extern unsigned char IDE_Life;

//气泵系统信息
extern unsigned char ACU_Status; //气泵控制器基本状态
extern unsigned char ACU_Fault_Code; //气泵控制器故障码
extern unsigned char ACU_Power; //气泵控制器功率
extern unsigned char ACU_Temp; //气泵电机温度
extern unsigned char ACU_Controller_temp; //气泵控制器温度
extern unsigned int  ACU_Voltage; //气泵控制器母线电压
extern unsigned int  ACU_Rpm; //气泵控制器电机转速

//油泵系统信息
extern unsigned char OCU_Status; //气泵控制器基本状态
extern unsigned char OCU_Fault_Code; //气泵控制器故障码
extern unsigned char OCU_Power; //气泵控制器功率
extern unsigned char OCU_Temp; //气泵电机温度
extern unsigned char OCU_Controller_temp; //气泵控制器温度
extern unsigned int  OCU_Voltage; //气泵控制器母线电压
extern unsigned int  OCU_Rpm; //气泵控制器电机转速

//DCDC系统信息
extern unsigned char DCDC_Status; //DCDC基本状态
extern unsigned char DCDC_CAN_Warn; //DCDC通讯报警
extern unsigned char DCDC_Temp_Warn; //DCDC温度报警
extern unsigned char DCDC_Status_Warn; //DCDC状态报警
extern unsigned char DCDC_Fault_Code; //DCDC故障代码
extern unsigned char DCDC_Temp; //DCDC模块温度
extern unsigned int  DCDC_Current; //DCDC输出电流
extern unsigned char DCDC_Output_Voltage; //DCDC输出电压
extern unsigned int  DCDC_Voltage; //DCDC母线电压

void DM(unsigned char x, DM1 id,unsigned char i);

#endif	/* APP_CAN2_RECEIVE_H */

