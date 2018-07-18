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
#define  VERISON      100

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

#define  key_duble   gKEY[1].bit2 //长按AV和UP按钮，隐藏组合按钮

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
#define  MILE_flag  gKEY[3].bit8

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

extern unsigned int ADV[9]; //模拟量采集   2016/10/15
extern unsigned int ADR[9];

extern unsigned char PRESS[2]; //气压值
//extern const unsigned char BMP_LOGO[];
//extern const unsigned char BMP_LOGObmp[];

/**********随州协议变量************/


extern unsigned int moto_voltage; //电机电压
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

#define  Kt               CAN_KEY[2].bit2  

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
/*******************************************/

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
    unsigned char bData[22];
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


/******************************************************************/

#define BCM_F_KL1  fKEY.BITS.kl1
#define BCM_F_KL2  fKEY.BITS.kl2

#define BCM_M_KL2  mKEY.BITS.kl2

#define CAN_TIME 30//CAN节点故障报警


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
//dispaly
void LCD_Exec(void);

//void TIMER4_Init(void);
/******************************/
/********************************************/

#endif	/* SYSTEM_H */

