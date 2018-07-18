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

#define  key_set          gKEY[0].bit1 
#define  pkey_set         gKEY[0].bit2 
#define  bkey_set         gKEY[0].bit3
#define  key_up           gKEY[0].bit4
#define  pkey_up          gKEY[0].bit5  
#define  bkey_up          gKEY[0].bit6
#define  key_AV           gKEY[0].bit7
#define  pkey_AV          gKEY[0].bit8

#define  bkey_AV          gKEY[1].bit1
#define  key_duble        gKEY[1].bit2
#define  F50ms            gKEY[1].bit3
#define  F100ms           gKEY[1].bit4
#define  F500ms           gKEY[1].bit5  
#define  F500ms_LCD       gKEY[1].bit6 //lcd显示更新时间
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

#define  F300ms           gKEY[3].bit1 // 2016/10/22新增更新时间
#define  F400ms           gKEY[3].bit2
#define  F1000ms          gKEY[3].bit3
#define  FLASH_3s         gKEY[3].bit4
#define  time_flag        gKEY[3].bit5
#define  M_ON_flag        gKEY[3].bit6
#define  rLED_flag        gKEY[3].bit7

#define  alarm_update_flag   gKEY[4].bit1//报警显示更新时间
#define  alarm_update_flag1  gKEY[4].bit2//报警显示更新时间
#define  alarm_update_flag2  gKEY[4].bit3//报警显示更新时间

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
#define mKL15   mKEY.BITS.kl15   //控火开关
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
#define rKL15   rKEY.BITS.kl15   //控火开关
#define rKH1    rKEY.BITS.kh1
#define rADD    rKEY.BITS.add

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

/*********************************************/
extern unsigned char Index;
extern unsigned char t;
extern unsigned char t_add;
extern unsigned char frmID;
extern unsigned char f_index;
extern unsigned char menuid;
extern unsigned char AV_CH;
extern unsigned char color_old[35];
/*********************************************/

extern unsigned int ADR[8]; //模拟量采集缓存   2016/10/15
//extern const unsigned char BMP_LOGO[];
//extern const unsigned char BMP_LOGObmp[];
#define CAN_TIME  30 //CAN节点故障报警，CAN接受超过3秒未收到，则视为故障
/**********随州协议变量************/


extern unsigned char moto_voltage; //电机电压
extern unsigned char moto_current; //电机电流
extern unsigned char moto_speed; //电动转速
extern unsigned char battle_t; //电池均温
extern unsigned char Inverter_t; //逆变器温度
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
extern unsigned char BMS_V; //电池电压
extern unsigned char BMS_SOC; //电池SOC
extern unsigned char BMS_A; //电池电流

extern unsigned char mil_lamp_request; //混动黄色报警
extern unsigned char fail_mode; //混动红色报警
extern unsigned char mil_buzz_request; //蜂鸣器响
extern unsigned long hcu_spn; //HCU故障码
extern unsigned char hcu_fmi;

extern unsigned int Speed_rmp; //输出轴转速
extern unsigned char Eng_static_test; //发动机稳态转速测试
extern unsigned char tcu_start_allow; //发动机运行启动

extern unsigned char Current_Gear; //档位

extern unsigned char Lamp_status_YELLOW; //变速箱黄灯状态
extern unsigned char Lamp_status_RED; //变速箱红灯状态
extern unsigned long tcu_spn; //TCU故障码
extern unsigned char tcu_fmi;

extern unsigned long ccu_spn; //CCU故障码
extern unsigned char ccu_fmi;

extern unsigned long ecu_spn; //ECU故障码
extern unsigned char ecu_fmi;

extern unsigned int Max_Cell_Voltage;//最高单体电压
extern unsigned char Max_Cell_Voltage_Cell_Number;//最高单体电压位置
extern unsigned int Min_Cell_Voltage;//最低单体电压
extern unsigned char Min_Cell_Voltage_Cell_Number;//最低单体电压位置
extern unsigned char Brake_percent; //制动踏板开度

extern DATA_BIT OTS_DI;
#define Zichong         OTS_DI.bit1
#define Electric        OTS_DI.bit2
#define Hybrid_forbid   OTS_DI.bit3
#define Daisujingzhi    OTS_DI.bit4

extern unsigned int Max_Cell_Temperature;//最高单体温度
extern unsigned char Max_Cell_Temp_Cell_Number;//最高单体温度位置
extern unsigned char Motor_Temperature;//电机1温度
extern unsigned char Motor2_Generatrix_Current;//电机2电流
extern unsigned char Motor2_Speed;//电机2转速
extern unsigned char Motor2_Inverter_Temperature;//电机2逆变器温度
extern unsigned char Motor2_Temperature;//电机2温度

extern unsigned int ENG_start_req; //仪表控制启动
extern unsigned long mot_work_time; //电机工作累积时间
extern unsigned char mot_work_percent; //电机工作时间比
extern unsigned char DCDC_ctrl; //DCDC状态
extern unsigned char hcu_starter_forbid; //起动机工作
extern unsigned char aircompress_enable; //压缩机
extern unsigned char Brake_Pedal; //刹车信号
extern unsigned char Speed_lim_mode;//限速模式
extern unsigned char Accelerator; //油门开度

extern unsigned char water_temp;//水温

extern unsigned int  Engine_oil_press;//机油压力
extern unsigned char water_level;//水位

extern unsigned char Wait_start;//等待启动
extern unsigned char Maintain_warn;//维护报警
extern unsigned char Stop_warn;//停机报警
extern unsigned char Engine_warn;//发动机故障

extern unsigned int EngineSpeed;//发动机转速

extern unsigned char barometric_pressure ; //增压压力 0.5Kpa               
extern unsigned char ambient_air_temperature; //周围空气温度
extern unsigned char air_pressure ; //进气压力 0.5Kpa

extern unsigned long Trip_fuel;//单次累计燃气消耗

extern unsigned int Shunshi_fule;//发动机瞬时气耗
extern unsigned int Average_fule;//发动机平均气耗

extern unsigned char ABS_lamp;//ABS状态

extern unsigned long abs_spn; //ABS故障码

extern unsigned int DC_DC_voltage_in;//DCDC输入电压
extern unsigned char DC_DC_voltage_out;//DCDC输出电压
extern unsigned int DC_DC_current_out;//DCDC输出电流
extern unsigned char DC_DC_t;//DCDC散热器温度
extern DATA_BIT DC_DC_code;//DCDC故障代码
#define DCDC_under_v_in       DC_DC_code.bit1
#define DCDC_over_v_in        DC_DC_code.bit2
#define DCDC_out              DC_DC_code.bit3
#define DCDC_over_t           DC_DC_code.bit4
#define DCDC_short            DC_DC_code.bit5

extern unsigned int DC_AC_voltage_in;//DCDC输入电压
extern unsigned int DC_AC_voltage_out;//DCDC输出电压
extern unsigned int DC_AC_current_out;//DCDC输入电流
extern unsigned char DC_AC_t;//DCDC散热器温度
extern DATA_BIT DC_AC_code;//DCDC故障代码
#define DCAC_under_v_in       DC_AC_code.bit1
#define DCAC_over_v_in        DC_AC_code.bit2
#define DCAC_low_vbat         DC_AC_code.bit3
#define DCAC_over_a           DC_AC_code.bit4
#define DCAC_over_t           DC_AC_code.bit5
#define DCAC_short            DC_AC_code.bit6
#define DCAC_over_use         DC_AC_code.bit7
#define DCAC_lost_xiang       DC_AC_code.bit8

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
        DTC DTC6;
        DTC DTC7;
        DTC DTC8;
    };
    unsigned char bData[34];
} DM1;

extern DM1 CAN_18FECAEF;
extern unsigned char CAN_18FECAEF_len;
extern DM1 CAN_18FECA03;
extern unsigned char CAN_18FECA03_len;
extern DM1 CAN_18FECAF5;
extern unsigned char CAN_18FECAF5_len;
extern DM1 CAN_18FECA00;
extern unsigned char CAN_18FECA00_len;

typedef struct {
    unsigned char pack; //CAN分几包数据传输
    unsigned char flag; //CAN缓存接收完标记
    unsigned char len; //CAN缓存长度
    unsigned char buf[50]; //CAN缓存数组
} CAN_CACHE;
extern CAN_CACHE m_can;//HCU缓存
extern CAN_CACHE n_can;//TCU缓存
extern CAN_CACHE c_can;//CCU缓存

extern unsigned long SPN; //从缓存里提取的故障码
extern unsigned char FMI;
//extern unsigned char CM;
//extern unsigned char OC;
/******************************************************************/


void System_Init(void);
void SYSTME_Logic(void);
void LED_Logic(void);

void BCAN_SendCtl(void);
void PCAN_CCVS(void);
void Count_ADR(void);
void PCAN_send_mile(void);
/*
void DM_HCU(unsigned char x);
void DM_TCU(unsigned char x);
void DM_CCU(unsigned char x);
void DM_ECU(unsigned char x);
*/
void DM(unsigned char x,DM1 id);
void LCD_Exec(void);

//void TIMER4_Init(void);
/******************************/
/********************************************/

#endif	/* SYSTEM_H */

