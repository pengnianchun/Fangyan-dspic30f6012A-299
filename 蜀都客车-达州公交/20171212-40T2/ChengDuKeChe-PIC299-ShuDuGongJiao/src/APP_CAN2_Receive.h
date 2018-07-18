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
typedef union {

    struct {
        unsigned char moto_voltage; //电机电压
        unsigned char moto_current; //电机电流
        unsigned : 8;
        unsigned char moto_speed; //电动转速
        unsigned char battle_t; //电池均温
        unsigned char Inverter_t; //逆变器温度
        
        unsigned battle_t_warn : 2; //电池过温报警
        unsigned battle_jueyuan_warn : 2; //绝缘过低报警
        unsigned battle_higtv1_warn : 2; //高压电池1故障
        unsigned battle_higtv2_warn : 2; //高压电池2故障
        
        unsigned moto_t_warn : 2; //电机过温
        unsigned moto_ready : 2; //ready信号
        unsigned xudc : 2; //蓄电池异常
        unsigned moto_warn : 2; //电机故障
    };
    unsigned char byte[8];
}_CAN_0x18EF4AEF;

extern _CAN_0x18EF4AEF CAN_0x18EF4AEF;

typedef union {

    struct {
        unsigned BMS_offline_warn : 2; //电池不在线
        unsigned MCU_offline_warn : 2; //电机不在线
        unsigned TCU_offline_warn : 2; //变速箱不在线
        unsigned : 2;
        
        unsigned Engine_offline_warn : 2; //发动机不在线       
        unsigned : 6;
        
        unsigned Engine_wait : 2; //发动机怠速
        unsigned CAP_offline_Warning : 2; //电容离线
        unsigned EV : 2; //模式
        unsigned Signal_charge : 2; //充电信号
        
        unsigned char BMS_V;   //电池电压
        unsigned char BMS_SOC; //电池SOC
        unsigned char CAP_voltage; //电容电压
        unsigned char CAP_SOE;       
        unsigned char BMS_A;   //电池电流
    };
    unsigned char byte[8];
} _CAN_0x18EF4BEF;

extern _CAN_0x18EF4BEF CAN_0x18EF4BEF;
#pragma pack(1)
typedef union {

    struct {
        unsigned : 8;        
        unsigned : 8;  
        unsigned : 8;
        unsigned : 8;
        unsigned : 8;
        unsigned : 8;
        unsigned : 8;
        unsigned : 2; 
        unsigned : 2; 
        unsigned Eng_static_test : 2; //发动机稳态转速测试
        unsigned tcu_start_allow : 2; //发动机运行启动
    };
    unsigned char byte[8];
} _CAN_0x0CF00203;
#pragma pack()
extern unsigned int Speed_rmp; //输出轴转速
extern _CAN_0x0CF00203 CAN_0x0CF00203;

extern unsigned char Current_Gear; //档位
#pragma pack(1)
typedef union {

    struct {
        unsigned int Max_Cell_Voltage: 12;   
        unsigned int : 4;
        
        unsigned char Max_Cell_Voltage_Cell_Number; //最高单体位置
        
        unsigned int Min_Cell_Voltage: 12;   
        unsigned int : 4;
        
        unsigned char Min_Cell_Voltage_Cell_Number; //最低单体位置
        unsigned char Brake_percent; //踏板开度      
        unsigned : 8; //发动机运行启动
    };
    unsigned char byte[8];
} _CAN_0x18EF4CEF;
#pragma pack()
extern _CAN_0x18EF4CEF CAN_0x18EF4CEF;

typedef union {

    struct {
        unsigned int Max_Cell_Temperature: 12;   
        unsigned int : 4;
        
        unsigned char Max_Cell_Temp_Cell_Number; //最高单体位置      
        unsigned char Motor_Temperature;   
        unsigned char moto2_current; //电机电流
        unsigned char moto2_speed; //电动转速
        unsigned char Inverter2_t; //逆变器温度
        unsigned char Motor2_Temperature; 
    };
    unsigned char byte[8];
} _CAN_0x18EF4DEF;

extern _CAN_0x18EF4DEF CAN_0x18EF4DEF;
#pragma pack(1)
typedef union {

    struct {
        unsigned int ENG_start_req; //仪表控制启动
        unsigned long mot_work_time; //电机工作累积时间
        unsigned char mot_work_percent; //电机工作时间比

        unsigned DCDC_ctrl : 2; //DCDC状态
        unsigned hcu_starter_forbid : 2; //起动机工作
        unsigned aircompress_enable : 2; //压缩机
        unsigned Brake_Pedal : 2; //刹车信号
    };
    unsigned char byte[8];
} _CAN_0x18EF0AEF;
#pragma pack()
extern _CAN_0x18EF0AEF CAN_0x18EF0AEF;

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

typedef union {

    struct {
        unsigned :16; //发电机电流
        unsigned int XDC_A; //蓄电池电流
        unsigned int XDC_V; //蓄电池电压
        unsigned char PDH_Temp; //配电盒温度
        unsigned PDH_Status : 1; //起动机状态
        unsigned PDH_OverCurrent : 1; //过流
        unsigned PDH_OverVoltage : 1; //过压
        unsigned PDH_Protect : 1; //保护
        unsigned : 4; //
    };
    unsigned char byte[8];
} _CAN_0x18FE521E;

extern _CAN_0x18FE521E CAN_0x18FE521E;

typedef union {

    struct {
        unsigned int PDH_A1; //配电盒电流1
        unsigned int PDH_A2; //配电盒电流2
        unsigned int PDH_A3; //配电盒电流3
        unsigned int PDH_A4; //配电盒电流4
    };
    unsigned int  two[4];
    unsigned char byte[8];
} _CAN_0x1CFF5281;

extern _CAN_0x1CFF5281 CAN_0x1CFF5281;

typedef union {

    struct {
        unsigned char : 8; //
        unsigned char PDH_Temp1; //配电盒电流1
        unsigned char PDH_Temp2; //配电盒电流2
        unsigned char PDH_Temp3; //配电盒电流3
        unsigned char PDH_Temp4; //配电盒电流4
        unsigned char PDH_Temp5; //配电盒电流5
        unsigned char PDH_Temp6; //配电盒电流6
        unsigned char : 8; //
    };
    unsigned char byte[8];
} _CAN_0x1CFF5381;

extern _CAN_0x1CFF5381 CAN_0x1CFF5381;

#endif	/* APP_CAN2_RECEIVE_H */

