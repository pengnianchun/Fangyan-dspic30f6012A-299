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
//ID(0x0C008980)
extern unsigned int  VCU_Motor_Front_Voltage;    //电机控制器前端电压
extern unsigned int  VCU_Motor_Rear_Voltage;     //电机控制器后端电压
extern unsigned int  VCU_Motor_DC_Current;       //电机控制器直流电流
extern unsigned int  VCU_Motor_RPM;  

//ID(0x0C018980)    
extern unsigned char VCU_Speed_percent;          //加速踏板开度
extern unsigned char VCU_Brake_percent;          //制动踏板开度
extern DATA_BIT      VCU_Power_System_Status;    //驱动系统状态
extern unsigned char VCU_Gear;                   //档位
extern unsigned char VCU_KT;                     //主接触器状态
extern unsigned char VCU_KC;                     //预充接触器
extern unsigned char VCU_Motor_Temp;             //电机温度
extern unsigned char VCU_Motor_Control_Temp;     //电机控制器温度
extern unsigned char VCU_Motor_Code;             //电机故障码
extern unsigned char VCU_Life;                   //整车控制器Life

//ID(0x0C028980)
extern DATA_BIT      VCU_Output_Status;          //整车输出状态
extern unsigned int  VCU_Motor_Brake_Current;    //电机制动电流
extern unsigned int  VCU_Motor_Torque;           //电机实际转矩
extern unsigned char VCU_Motor_Number;           //电机个数
extern unsigned char VCU_Motor_Sequence_Number;  //电机序号
extern unsigned char VCU_Motor_Status;           //电机状态

//ID(0x0C038980)
extern DATA_DOUBLE   VCU_Run_Mode;               //运行模式
extern DATA_BIT      VCU_Warn;                   //整车报警
extern unsigned char VCU_Fault_Number_BAT;       //电池故障总数
extern unsigned char VCU_Fault_Number_Motor;     //电池故障总数
extern unsigned char VCU_Fault_Number_Other;     //电池故障总数

//ID（0x18FF12F7）
extern unsigned int  DCDC_Output_Voltage;        //DCDC输出电压
extern unsigned int  DCDC_Output_Current;        //DCDC输出电压
extern unsigned char DCDC_Work_Status;           //DCDC工作状态
extern DATA_BIT      DCDC_Fault_Code;            //DCDC故障代码

//ID（0x18019888）
extern unsigned int  OILDCAC_Output_Voltage;     //油泵DCAC输出电压
extern unsigned int  OILDCAC_Output_Current;     //油泵DCAC输出电压
extern unsigned char OILDCAC_Temp;               //油泵DCAC散热器机温度
extern DATA_BIT      OILDCAC_Code;               //油泵DCAC故障代码

//ID（0x1805A89C）
extern unsigned int  AIRDCAC_Input_Voltage;      //气泵DCAC输入电压
extern unsigned int  AIRDCAC_Output_Voltage;     //气泵DCAC输出电压
extern unsigned int  AIRDCAC_Output_Current;     //气泵DCAC输出电压
extern unsigned char AIRDCAC_Temp;               //气泵DCAC散热器机温度
extern DATA_BIT      AIRDCAC_Code;               //气泵DCAC故障代码

//ID(0x18F0010B)
extern unsigned char ABS_Active;                 //ABS状态

//BMS发送第一组，ID=0x0CFF7D03
extern unsigned char BMS_Life;                   //BMS Life
extern unsigned char BMS_Fault_Level;            //BMS故障等级
extern unsigned char BMS_Charge;                 //充放电状态
extern unsigned char BMS_SOC;                    //电池SOC
extern unsigned char BAT_Max_Cell_Voltage_Cell_Number; //最高单体电压位置
extern unsigned int  BAT_Max_Cell_Voltage;       //电池单体高电压
extern unsigned char BAT_Min_Cell_Voltage_Cell_Number; //最低单体电压位置
extern unsigned int  BAT_Min_Cell_Voltage;       //电池单体低电压

//BMS发送第二组，ID=0x0CFF7E03
extern unsigned char BMS_Precharge;              //预充电状态
extern unsigned char BMS_HighVoltage_Status;     //高压链接状态
extern unsigned char BMS_Check;                  //BMS自检
extern unsigned char BMS_SOH;                    //BMS SOH
extern unsigned int  BMS_V;                      //电池电压
extern unsigned int  BMS_A;                      //电池电流
extern unsigned int  BAT_Max_Cell_Temperature;   //最高单体温度
extern unsigned int  BAT_Min_Cell_Temperature;   //最低单体温度

//BMS发送第三组，ID=0x0CFF7F03
extern DATA_BIT      BMS_Status1;                //BMS状态1
extern unsigned char BMS_Charging;               //BMS充放电状态
extern DATA_DOUBLE   BMS_Status2;                //BMS状态2
extern unsigned char BMS_Humidity;               //BMS湿度
extern unsigned char BMS_Current_Charge_Limit_Long; //最大可用持续充电功率（30min）
extern unsigned char BMS_Current_Charge_Limit_Short;//最大可用短时充电功率（30s）
extern unsigned char BMS_Current_Disharge_Limit_Long;     //最大可用持续放电功率（30min）
extern unsigned char BMS_Current_Disharge_Limit_Short;    //最大可用短时放电功率（30s）
extern unsigned int  Oum;                                 //绝缘阻值

//BMS发送第四组，ID=0x0CFF8003
extern unsigned char BMS_Fault1[20];                //BMS多级故障
#define  Diff_Temp                 BMS_Fault1[0]    //温度差异故障
#define  Diff_Voltage              BMS_Fault1[1]    //单体电压差异故障
#define  Temp_High                 BMS_Fault1[2]    //温度过高故障
#define  Single_Bat_OverVoltage    BMS_Fault1[3]    //单体过压故障
#define  Single_Bat_UnderVoltage   BMS_Fault1[4]    //单体欠压故障
#define  Pack_Bat_OverVoltage      BMS_Fault1[5]    //电池组过压故障
#define  Pack_Bat_UnderVoltage     BMS_Fault1[6]    //电池组欠压故障
#define  OverCharge_Fault          BMS_Fault1[7]    //充电过流故障
#define  OverDisharge_Fault        BMS_Fault1[8]    //放电过流故障
#define  SOC_High                  BMS_Fault1[9]    //SOC过高故障
#define  SOC_Low                   BMS_Fault1[10]    //SOC过低故障
#define  Insulation_Fault          BMS_Fault1[11]    //绝缘故障
#define  Bat_LowTemp               BMS_Fault1[12]    //放电温度过低
#define  DC_Charge_Gun_OverTemp    BMS_Fault1[13]    //直流充电枪温度故障
#define  AC_Charge_Gun_OverTemp    BMS_Fault1[14]    //交流充电枪温度故障

//BMS_Fault1[1]    单体电压差异故障
//BMS_Fault1[2]    温度过高故障
//BMS_Fault1[3]    单体过压故障
//BMS_Fault1[4]    单体欠压故障
//BMS_Fault1[5]    电池组过压故障
//BMS_Fault1[6]    电池组欠压故障
//BMS_Fault1[7]    充电过流故障
//BMS_Fault1[8]    放电过流故障
//BMS_Fault1[9]    SOC过高故障
//BMS_Fault1[10]   绝缘故障
//BMS_Fault1[11]   放电温度过低
//BMS_Fault1[12]   直流充电枪温度故障
//BMS_Fault1[13]   交流充电枪温度故障
extern DATA_BIT      BMS_Fault2[3];               //BMS单级故障
#define  BAT_CELL_COLT_OFFLINE       BMS_Fault2[0].bit3    //采集离线故障
#define  BAT_CELL_MODULE_FAULT       BMS_Fault2[0].bit4    //采集模块故障
#define  BAT_CELL_Voltage_BREAK      BMS_Fault2[0].bit5    //单体电压断线
#define  TEMP_COLT_OFFLINE           BMS_Fault2[0].bit6    //单体温度断线
#define  VCU_COMM_OFFLINE            BMS_Fault2[0].bit7    //VCU离线故障
#define  HUOER_OFFLINE               BMS_Fault2[0].bit8    //霍尔离线故障
#define  INSIDE_COMM_OFFLINE         BMS_Fault2[1].bit1    //内部通讯故障
#define  CHARGER_COMM_FAULT          BMS_Fault2[1].bit2    //与充电机通讯故障
#define  Box_Kt_FAULT                BMS_Fault2[2].bit1    //箱内接触器故障
#define  Charge_Kt_FAULT             BMS_Fault2[2].bit2    //充电接触器故障
#define  WARN_Kt_FAULT               BMS_Fault2[2].bit3    //加热接触器故障

//交流充电枪与直流充电枪温度显示ID=0x18FFDE03
extern unsigned char BMS_DC_ChargeGun_PT;         //直流充电枪正极温度
extern unsigned char BMS_DC_ChargeGun_NT;         //直流充电枪正极温度
extern unsigned char BMS_AC_ChargeGun_Temp;       //交充电枪温度

//BMS发送第六组，ID=0x0CFF8103
extern unsigned char BAT_Max_Cell_Voltage_Cell_Case; //最高单体电压箱号
extern unsigned char BAT_Min_Cell_Voltage_Cell_Case; //最低单体电压箱号
extern unsigned char BAT_Max_Cell_Temp_Cell_Case;    //最高单体温度箱号
extern unsigned char BAT_Max_Cell_Temp_Cell_Number;  //最高单体电压位置
extern unsigned char BAT_Min_Cell_Temp_Cell_Case;    //最低单体温度箱号
extern unsigned char BAT_Min_Cell_Temp_Cell_Number;  //最高单体电压位置
extern DATA_BIT      BMS_Warn[2]; 

//BMS发送第七组，ID=0x0CFF8203（可充电储能装置电压数据）
extern unsigned char BMS_System_Number;
extern unsigned char BMS_System_SequenceNumber;
extern unsigned int  BMS_System_Voltage;
extern unsigned int  BMS_System_Current;
extern unsigned char BMS_BAT_Number;

//BMS发送第八组，ID=0x0CFF8303
extern unsigned char BMS_System_Temp_Number;
extern unsigned char BMS_System_Fault_Number;

//BMS发送单体电压（选用）0x18(00~FF)DC03
extern unsigned int  BAT_Single_Voltage[200];
extern unsigned char BAT_Single_Temp[200];



void DM(unsigned char x, DM1 id);

#endif	/* APP_CAN2_RECEIVE_H */

