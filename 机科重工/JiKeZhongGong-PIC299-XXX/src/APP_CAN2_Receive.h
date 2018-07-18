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
//整车控制器1 ID：0X1000EF1D
extern DATA_BIT      VCU_Fault[3];  
#define VCU_FAULT            VCU_Fault[0].bit1
#define MCU_Control_Ready    VCU_Fault[0].bit2
#define BMS_Ready            VCU_Fault[0].bit3
#define Three_Ready          VCU_Fault[0].bit4
#define CAR_Ready            VCU_Fault[0].bit5
#define ChargeGun            VCU_Fault[0].bit6
extern unsigned char Charging;

extern unsigned char BMS_SOC;         //电池SOC
extern unsigned int  MCU_RPM; //电机转速
extern unsigned int  BMS_V;           //电池电压
extern unsigned int  BMS_A;   //电池电流

//整车控制器2 ID：0X1100EF1D
#define MCU_Control_High_Temp VCU_Fault[1].bit1
#define MCU_Control_Fault     VCU_Fault[1].bit2
#define BAT_High_Temp         VCU_Fault[1].bit3
#define BAT_Low_Temp          VCU_Fault[1].bit4
#define BAT_Voltage_Diff      VCU_Fault[1].bit5
#define BAT_OverCurrent       VCU_Fault[1].bit6
#define BMS_Fault             VCU_Fault[1].bit7
#define Three_Fault           VCU_Fault[1].bit8

#define AirPress_Low          VCU_Fault[2].bit1
#define AirMoto_Fault         VCU_Fault[2].bit2
#define SwitchMoto_Fault      VCU_Fault[2].bit3
#define FPower_Fault          VCU_Fault[2].bit4
#define Charging_Link_Fault   VCU_Fault[2].bit5
#define Charging_High_Temp    VCU_Fault[2].bit6
#define Charging_Fault        VCU_Fault[2].bit7

extern unsigned int  BMS_Charge_V;         //充电需求电压
extern unsigned int  BMS_Charge_A;         //充电需求电流
extern unsigned char Storage_Battery;      //蓄电池电压
extern unsigned char MCU_Control_Temp;     //电机控制器温度

//整车控制器3 ID：0X0CFA001D
/*extern unsigned char VCU_Speed;             //整车发送车速
extern unsigned char Three_Temp;            //三合一温度
extern unsigned int  Air_RPM;               //气泵转速
extern unsigned int  Switch_RPM;            //转向泵转速
*/
//整车控制器4 ID：0X0CFB001D
extern unsigned char BAT_Max_Cell_Voltage;           //电池单体高电压
extern unsigned char BAT_Min_Cell_Voltage;           //电池单体低电压
extern unsigned char BAT_Max_Cell_Voltage_Cell_Case; //最高单体电压箱号
extern unsigned char BAT_Min_Cell_Voltage_Cell_Case; //最低单体电压箱号
extern unsigned char BAT_Max_Cell_Temperature;       //最高单体温度
extern unsigned char BAT_Min_Cell_Temperature;       //最低单体温度
extern unsigned char BAT_Max_Cell_Temp_Cell_Case;    //最高单体温度箱号
extern unsigned char BAT_Min_Cell_Temp_Cell_Case;    //最低单体温度箱号

//整车控制器5 ID：0X0CFC011D
extern unsigned char BAT_Cell_Voltage[20];           //电池模块电压
extern unsigned char BAT_Cell_Temperature[20];       //电池模块温度
extern unsigned char BAT_Cell_Current[20];           //电池模块电流
extern DATA_BIT      BAT_Fault[20];                  //电池模块报警 

//吊具控制器  ID:0x18FF020A
extern DATA_BIT      DJ_Status[8];                   //吊具控制器状态
/*
//电池基本信息 ID:0x18F201F3
extern unsigned char BMS_SOC;     //电池SOC
extern unsigned int  BMS_V;       //电池电压
extern unsigned int  BMS_A;       //电池电流
extern unsigned int  BMS_Number;  //电池组总串数
extern unsigned char BMS_Life;    //BMSlife

//电池基本信息 2 ID:0x18F202F3
extern unsigned char BMS_Current_Charge_Limit_Long;
extern unsigned char BMS_Current_Charge_Limit_Short;
extern unsigned char BMS_Current_Disharge_Limit_Long;
extern unsigned char BMS_Current_Disharge_Limit_Short;
extern unsigned char BMS_Cut;

//电池故障报警信息 ID:0x18F205F3
extern DATA_DOUBLE   BMS_Warn[4];
#define    Pack_Bat_OverVoltage    BMS_Warn[0].bit1
#define    Single_Bat_OverVoltage  BMS_Warn[0].bit2
#define    Pole_OverTemp           BMS_Warn[0].bit3
#define    Battery_OverTemp        BMS_Warn[0].bit4

#define    Bat_Fault               BMS_Warn[1].bit1
#define    Charge_Gun_OverTemp     BMS_Warn[1].bit2
#define    Single_Bat_UnderVoltage BMS_Warn[1].bit3
#define    Pack_Bat_UnderVoltage   BMS_Warn[1].bit4

#define    Diff_Temp               BMS_Warn[2].bit1
#define    Diff_Voltage            BMS_Warn[2].bit2
#define    Charge_OverCurrent      BMS_Warn[2].bit3
#define    Discharge_OverCurrent   BMS_Warn[2].bit4

#define    Bat_LowTemp             BMS_Warn[3].bit1
#define    Diff_SOC                BMS_Warn[3].bit2
#define    SOC_High                BMS_Warn[3].bit3
#define    SOC_Low                 BMS_Warn[3].bit4

extern DATA_BIT      BMS_Fault[3];
#define  BMU_OFFLINE           BMS_Fault[0].bit1
#define  CHARGER_COMM_FAULT    BMS_Fault[0].bit2  
#define  PRECHARGE_FAULT       BMS_Fault[0].bit3 
#define  BALANCE_FAULT         BMS_Fault[0].bit4
#define  WARN_FAULT            BMS_Fault[0].bit5 
#define  BAT_COOL_FAULT        BMS_Fault[0].bit6
#define  BMS_FAULT_OTHER       BMS_Fault[0].bit7
#define  BMS_COMM_FAULT        BMS_Fault[0].bit8  

#define  BALA_STATUS           BMS_Fault[1].bit1
#define  WARN_STATUS           BMS_Fault[1].bit2  
#define  BAT_COLOD_STATUS      BMS_Fault[1].bit3
#define  CHARGE_PLUG           BMS_Fault[1].bit4
#define  CHARGE_STATUS         BMS_Fault[1].bit5 
#define  BAT_FAULT             BMS_Fault[1].bit6
extern unsigned char BMS_Self_Check;//BMS自检状态

#define  TEMP_COLT_OFFLINE     BMS_Fault[2].bit1
#define  BAT_CELL_COLT_OFFLINE BMS_Fault[2].bit2  
#define  BAT_DISCHARGE_PROTECT BMS_Fault[2].bit3
#define  SOC_JUMP              BMS_Fault[2].bit4
#define  SYSTEM_MISMATCH       BMS_Fault[2].bit5 
#define  FIRE_FAULT            BMS_Fault[2].bit6
#define  VOLTAGE_DIFF_FAULT    BMS_Fault[2].bit7
#define  KT_FAULT              BMS_Fault[2].bit8

//电池单体最高电压信息 0x18F206F3 // 0x18F207F3
extern unsigned int  BAT_Max_Cell_Voltage[4]; //电池单体高电压
extern unsigned char BAT_Max_Cell_Voltage_Cell_Case[4]; //最高单体电压箱号
extern unsigned char BAT_Max_Cell_Voltage_Cell_Number[4]; //最低单体电压位置

//电池单体最低电压信息 0x18F208F3 // 0x18F209F3
extern unsigned int  BAT_Min_Cell_Voltage[4]; //电池单体低电压
extern unsigned char BAT_Min_Cell_Voltage_Cell_Case[4]; //最低单体电压箱号
extern unsigned char BAT_Min_Cell_Voltage_Cell_Number[4]; //最低单体电压位置

//电池最高温度信息 ID:0x18F20AF3
extern unsigned int  BAT_Max_Cell_Temperature[4]; //最高单体温度
extern unsigned char BAT_Max_Cell_Temp_Cell_Case[4]; //最高单体温度箱号

//电池最低温度信息 ID:0x18F20BF3
extern unsigned int  BAT_Min_Cell_Temperature[4]; //最低单体温度
extern unsigned char BAT_Min_Cell_Temp_Cell_Case[4]; //最低单体温度箱号

//电池极柱温度信息
extern unsigned char BAT_Pole_Temperature_P[16];//正极柱温度
extern unsigned char BAT_Pole_Temperature_N[16];//负极柱温度

//电池箱体在线状态 ID:0x185017F3
extern DATA_BIT      BMU_Comm_Status[4]; //电池箱在线状态
extern unsigned char BMS_Unit_Number;    //电池箱个数

//电池组基本信息 1（厂家容量） ID: 0x18F20CF3
extern unsigned char BAT_Productor;     //电池生产厂家
extern unsigned char BAT_Ahr;           //电池额定容量
extern unsigned char BAT_Voltage;       //电池额定电压
extern unsigned int  BAT_Charge_Times;  //电池充电次数
extern unsigned char BAT_Material;      //电池材料
extern unsigned char BAT_Time_Month;    //电池生产月份
extern unsigned char BAT_Time_Year;     //电池生产年份
extern unsigned char BAT_Verison;       //BMS程序版本号

//绝缘检测仪 ID:0x18FF2B49
extern unsigned char Oum_Status;  //绝缘检测仪状态
extern unsigned char Oum_Warn;    //绝缘检测仪报警
extern unsigned int  Oum;         //绝缘阻值
extern unsigned int  Oum_Voltage; //绝缘阻值
extern unsigned char Oum_Life;    //绝缘检测仪LIFE

//整车控制器状态信息 1 ID:0x18F101D0
extern DATA_DOUBLE   VCU_Status;  
extern unsigned int  VCU_SPEED;
extern unsigned char VCU_Gear;
extern unsigned char VCU_Clutch;
extern DATA_BIT      VCU_Fault;
extern unsigned char VCU_Code;
extern unsigned char VCU_CarMode;
extern unsigned char VCU_Life;

//整车控制器状态信息 2 ID:0x18F103D0
extern unsigned char VCU_Verison;
extern unsigned int  VCU_KM;
extern unsigned char VCU_TM_Speed_percent; //加速踏板开度
extern unsigned char VCU_TM_Brake_percent; //制动踏板开度
extern unsigned char VCU_Kwh_100Km;

//VCU 使能控制 ID:0x18F105D0
extern DATA_BIT      VCU_Enable[4];

//高压柜状态信息 ID:0x18F106D0
extern DATA_BIT      VCU_KT_Control;
extern DATA_BIT      VCU_KT_Status;
extern DATA_BIT      BMS_KT_Status;

//电机控制器状态信息 1 ID:0x18F501F0
extern unsigned char MCU_Temp; //电机温度
extern unsigned char MCU_Control_Temp; //电机控制器温度
extern unsigned int  MCU_Voltage; //电机母线电压
extern unsigned char MCU_SelfStatus; //电机自检状态
extern unsigned char MCU_Status; //电机状态
extern DATA_BIT      MCU_Fault;
extern unsigned char MCU_Code;   //电机故障码

//电机控制器状态信息 2 ID:0x18F502F0
extern unsigned int  MCU_RPM;         //电机转速
extern unsigned int  MCU_NM;          //电机扭矩
extern unsigned int  MCU_POWER;       //电机功率
extern unsigned int  MCU_Current;     //电机电流

//电机控制器状态信息 3 ID:0x18F503F0
extern unsigned int  MCU_Output_Voltage; //电机输出电压
extern unsigned int  MCU_Phase_Current;  //电机相电流

//助力油泵发送报文状态 ID 0x0CF601A0
extern unsigned int  OILDCAC_Voltage;   //DCAC输出电压
extern unsigned char OILDCAC_Current;   //DCAC输出电流
extern unsigned char OILDCAC_Temp;      //DCAC电机温度
extern DATA_BIT      OILDCAC_Status;    //DCAC工作状态
extern unsigned char OILDCAC_Life;      //DCAC Life
   
//DC/DC 发送报文状态 ID 0x0CF602A1
extern unsigned char DCDC_Status;         //DCDC工作状态
extern unsigned char DCDC_Output_Current; //DCDC输出电流
extern unsigned char DCDC_Output_Voltage; //DCDC输出电压
extern unsigned char DCDC_Temp;           //DCDC模块温度
extern DATA_BIT      DCDC_Fault_Warn;     //DCDC故障报警
extern unsigned int  DCDC_Input_Voltage;  //DCDC输入电压
extern unsigned char DCDC_Life;           //DCDC Life

//气泵发送报文状态 ID 0x0CF603A2
extern unsigned int  AIRDCAC_Voltage;   //DCAC输出电压
extern unsigned char AIRDCAC_Current;   //DCAC输出电流
extern DATA_BIT      AIRDCAC_Status;    //DCAC工作状态
extern unsigned char AIRDCAC_Temp;      //DCAC电机温度
extern unsigned char AIRDCAC_Life;      //DCAC Life

//空调控制报文状态 ID 0x0CF605A3
extern unsigned char AC_Status;   //
extern unsigned char AC_Indoor_Temp; 
extern unsigned char AC_Gear; 
extern unsigned char AC_WindMode; 
extern unsigned char AC_Work_Status; 
extern unsigned char AC_Outdoor_Temp; 
extern unsigned char AC_Fault_Code; 
extern unsigned char AC_Life; 

extern unsigned char AC_Set_Temp; 
*/
void DM(unsigned char x, DM1 id);

#endif	/* APP_CAN2_RECEIVE_H */

