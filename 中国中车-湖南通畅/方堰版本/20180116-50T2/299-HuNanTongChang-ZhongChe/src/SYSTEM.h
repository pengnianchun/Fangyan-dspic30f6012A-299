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
//百米脉冲数  滚动半径508mm  主减速比6.14
#define  HM_PLUSE      177
//背光亮度值
#define  BACKLIGHT     750
//定义模块地址 0x01 为前部模块 0x02 为后模块  0x03为顶部模块   0x04为仪表
#define  MT_ADDR      4

//软件版本定义
#define  Version      301        //精度0.1  如V1.0
#define  Version_date 20180116  //20170726

//空指针
#define  NULL        (void*)0

extern unsigned int Fcan_count; //前部模块CAN
extern unsigned int Rcan_count; //后部模块CAN
extern unsigned int Mcan_count; //中部模块CAN
extern unsigned int Ecan_count; //发动机ECU模块CAN
extern unsigned int Vcan_count; //整车控制器VCU模块CAN
extern unsigned int Bcan_count; //电池管理器BMS模块CAN
extern unsigned int Dcan_count; //转向助力DC/AC模块CAN
extern unsigned int Acan_count; //空调AC模块CAN
extern unsigned int ECU_TIME;

extern unsigned int BAT24V_count; //蓄电池低压报警计时

extern unsigned int M_PO11_count; //输出10秒计时

extern unsigned int delay_5s;
extern unsigned int delay_cnt;

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

extern unsigned char frmID;

extern unsigned int  QY_TIME; //气压计时变量
extern unsigned int  KYJ_TIME;//空压机计时变量
extern unsigned char QY_OUT_EN;

extern unsigned int fMK_Version; //前模块版本号
extern unsigned int mMK_Version; //顶模块版本号
extern unsigned int rMK_Version; //后模块版本号

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
#define  key_reset   key_AV

#define  bkey_AV          gKEY[1].bit1
#define  key_duble        gKEY[1].bit2
#define  F50ms            gKEY[1].bit3
#define  F100ms           gKEY[1].bit4
#define  F500ms           gKEY[1].bit5  
#define  F500ms_LCD       gKEY[1].bit6 //lcd显示更新时间
#define  alarm_update_flag  gKEY[1].bit7//报警显示更新时间
//#define  CLR_single_miles gKEY[1].bit7
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
#define  F5s              gKEY[3].bit8

#define  F10min           gKEY[4].bit1
#define  F_DISP           gKEY[4].bit2
#define  F_20s            gKEY[4].bit3
#define  F_20s_flag       gKEY[4].bit4
#define  F_3              gKEY[4].bit5

#define  F_Pout           gKEY[4].bit6
#define  R_Pout           gKEY[4].bit7
#define  M_Pout           gKEY[4].bit8

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

#define T_PO1   M_PO1
#define T_PO2   M_PO2
#define T_PO3   M_PO3
#define T_PO4   M_PO4
#define T_PO5   M_PO5
#define T_PO6   M_PO6
#define T_PO7   M_PO7
#define T_PO8   M_PO8
#define T_PO9   M_PO9
#define T_PO10  M_PO10
#define T_PO11  M_PO11
#define T_PO12  M_PO12
#define T_PO13  M_PO13
#define T_PO14  M_PO14
#define T_PO15  M_PO15
#define T_PO16  M_PO16 

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

#define F_KL1   fKL1  
#define F_KL2   fKL2  
#define F_KL3   fKL3 
#define F_KL4   fKL4
#define F_KL5   fKL5  
#define F_KL6   fKL6
#define F_KL7   fKL7  
#define F_KL8   fKL8
#define F_KL9   fKL9 
#define F_KL10  fKL10
#define F_KL11  fKL11
#define F_KL12  fKL12
#define F_KL13  fKL13
#define F_KL14  fKL14
#define F_KL15  fKL15
#define F_ADD   fADD
#define F_KH1   fKH1

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

#define T_KL1   mKL1  
#define T_KL2   mKL2  
#define T_KL3   mKL3 
#define T_KL4   mKL4
#define T_KL5   mKL5  
#define T_KL6   mKL6
#define T_KL7   mKL7  
#define T_KL8   mKL8
#define T_KL9   mKL9 
#define T_KL10  mKL10
#define T_KL11  mKL11
#define T_KL12  mKL12
#define T_KL13  mKL13
#define T_KL14  mKL14
#define T_KL15  mKL15
#define T_ADD   mADD
#define T_KH1   mKH1

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

#define R_KL1   rKL1  
#define R_KL2   rKL2  
#define R_KL3   rKL3 
#define R_KL4   rKL4
#define R_KL5   rKL5  
#define R_KL6   rKL6
#define R_KL7   rKL7  
#define R_KL8   rKL8
#define R_KL9   rKL9 
#define R_KL10  rKL10
#define R_KL11  rKL11
#define R_KL12  rKL12
#define R_KL13  rKL13
#define R_KL14  rKL14
#define R_KL15  rKL15
#define R_ADD   rADD
#define R_KH1   rKH1

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
extern unsigned int fpcur[15];//前模块功率输出电流
extern unsigned int mpcur[15];//中模块功率输出电流
extern unsigned int rpcur[15];//后模块功率输出电流

extern unsigned int ADR[8]; //模拟量采集   10/15
extern unsigned int ADV[8]; //模拟量采集 

extern unsigned int pSpeed; //外部CAN换算车速
/*************************************/


/******************************************************************/
 #define  BAT_NUM      96  //单体电池个数
 #define  CAN_BAT_NUM  24   //单体电池电压CAN发送数据帧数，
 #define  BAT_BOX_NUM  10               //一帧包含四个单体电压，不足四个按四个计算      

//整车控制器变量 
extern  unsigned int   DJcontroler_voltage;//电机控制器输入电压
extern  unsigned int   DJcontroler_current; //电机控制器入电流高
extern  unsigned int   DJ_torque;           //发电机控制器输入电流
extern  unsigned int   DJ_speed;

extern  unsigned char  DJ_temperature;             //驱动电机温度
extern  unsigned char  DJcontroler_temperature;    //驱动电机控制器温度
extern  unsigned char  FDJ_temperature;            //发电机温度
extern  unsigned char  FDJcontroler_temperature;   //发电机控制器温度
extern  unsigned char  DR_state;                   //司机操作状态
extern  unsigned char  KEY_state;                  //开关量状态
extern  unsigned char  system_state;               //系统工作状态
extern  unsigned int   system_fault;               //系统故障码

extern  unsigned  int  EngineSpeed;
extern  unsigned char  WaterTem;
extern  unsigned char  EngineLoad;    //发动机负荷率
extern  unsigned char  urea_high;     //尿素液位
extern  unsigned char  speed_st1;     //发动机目标油门踏板状态
extern  unsigned char  speed_st2;     //发动机实际油门踏板
extern  unsigned char  controler_LIFE; //整车控制器Life

extern  unsigned char  traction_st;   //牵引踏板百分比
extern  unsigned char  brake_st;      //制动踏板百分比
extern  unsigned char  engine_oil_press;       //发动机机油压力
extern  unsigned char  ambient_air_temperature;//发动机进气温度
extern  unsigned long  total_fuel;     //发动机累计油（气）耗量

extern  unsigned char  debug_num[8]; //调试参数1

extern  unsigned char  KZQversion[7];
extern  unsigned char  FDJversion[7];  //程序版本号高 3字节
extern  unsigned char  DJversion[7];   //程序版本号高 3字节

extern  unsigned int   DJ_torqueST; //驱动电机目标转矩
extern  unsigned int   EngineSpeST; //发动机目标转速
extern  unsigned char  instantaneous_fuel; //瞬态燃油经济性
extern  unsigned int   single_BGLfuel;    //小计百公里油耗
extern  unsigned int   total_BGLfuel;     //总计百公里油耗

extern  unsigned int   DCDC_SC_voltage;
extern  unsigned int   DCDC_SC_current;
extern  unsigned int   DCDC_SR_voltage;
extern  unsigned char  DCDC_temperature;
extern  unsigned char  DCDC_fault;        //DCDC故障码

extern  unsigned int   DCAC_W_current;
extern  unsigned int   DCAC_V_current;
extern  unsigned int   DCAC_U_current;
extern  unsigned char  DCAC_temperature;
extern  unsigned char  DCAC_fault;   

extern  unsigned int   CD_current; //当前最大允许充电电流
extern  unsigned int   FD_current; //当前最大允许放电电流
extern  unsigned char  DC_fault;  //系统故障等级
extern  unsigned char  Tmin;     //最低单体电池温度
extern  unsigned char  Twater; //进水口温度
extern  unsigned char  DC_JCQst[2]; //电池接触器请求断开标识

extern  unsigned char  KT_Status[3];
extern  unsigned char  KT_temp[3];
extern  unsigned int   KT_current;
extern  unsigned char  KT_life;

extern  unsigned char  KT_ctrl;
extern  unsigned char  KT_MODE;//空调选择模式  0电动 1传统
extern  unsigned char  KT_temp1[3];
//电池电池管理相关报文 
extern  unsigned int   DC_voltage; //电池电压 
extern  unsigned int   DC_current; //电池电流 
extern  unsigned char  DC_SOC;
extern  unsigned char  DC_Status[6];

extern  unsigned int   Vmax;     //最大单体电压
extern  unsigned char  Vmax_num; //最大单体电压组号
extern  unsigned char  Tmax;     //最大单体电池温度
extern  unsigned char  Tmax_num; //最大单体电池温度组号
extern  unsigned int   Vmin;     //最小单体电压
extern  unsigned char  Vmin_num; //最小单体电压组号

extern  unsigned int   anode_R;     //正端对地绝缘电阻
extern  unsigned int   negative_R;  //负端对地绝缘电阻
extern  unsigned char  eror_R;      //绝缘故障等级
extern  unsigned char  R_life;      //
extern  unsigned char  R_ID;      //整车漏电报警

extern  unsigned char  KT_fuhe; //空调实际工作负荷
extern  unsigned char  CAR_MODE;//整车模式-自检-快充-慢充
extern  unsigned char  XHLC;    //续航里程
extern  unsigned char  TYBJ_state[8];//通用报警标志

extern  unsigned int   Vpj;//单体平均电压

extern  unsigned char  Tmax1;//最大单体电池温度

extern  unsigned int   anode_R1;//正端对地绝缘电阻
extern  unsigned int   negative_R1;//负端对地绝缘电阻

extern  unsigned char  VIN_Status;//VIN接收状态
extern  unsigned char  CDZ_temp[4];//充电座温度

extern  unsigned int   DC_EDRL;  //电池额定容量
extern  unsigned int   DC_EDDY;  //电池额定电压
extern  unsigned int   DC_CL_SUM;//电池单体串联数量
extern  unsigned char  DC_BL_SUM;//电池单体并联数量
extern  unsigned char  DC_WD_SUM;//电池系统温度探针

extern  unsigned char  Tmax_box;//最大单体电池温度箱号
extern  unsigned char  Tmin_box;//最小单体电池温度箱号
extern  unsigned char  Vmax_box;//最大单体电池电压箱号
extern  unsigned char  Vmin_box;//最小单体电池电压箱号
extern  unsigned char  Tmin_num;//最小单体电池温度组号

extern  unsigned char  DC_style;//电池类型
extern  unsigned char  DC_LengQ;//电池冷却方式

extern  unsigned int   BAT_vol[10];//单体正反向电压
extern  unsigned int   BAT_num[10];//单体正反向电压编号

extern  unsigned char  BAT_temp[10];//单体正反向温度
extern  unsigned char  BAT_num1[10];//单体正反向温度编号

extern  unsigned char  MHQ_DCBOX;//灭火器电池箱号
extern  unsigned char  MHQ_YJJB; //灭火器系统预警级别
extern  unsigned char  MHQ_fault;//灭火器故障码

extern  unsigned char  MHQ_TIME;//请求校时
extern  unsigned char  YW_Status[6];//烟雾报警
extern  unsigned char  YZT_LIFE;//云智通状态

extern  unsigned int   XDC_current; //蓄电池电流  
extern  unsigned int   XDC_voltage; //蓄电池电压                
extern  unsigned char  PDH_temp;//配电盒温度

extern  unsigned int   Vspeed;

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


extern unsigned char F_LOAD_ST[16];
extern unsigned char R_LOAD_ST[16];
extern unsigned char M_LOAD_ST[16];

extern DATA_BIT gPCTL[8]; //仪表输出控制信息
#define F_POUT1   gPCTL[0].bit1
#define F_POUT2   gPCTL[0].bit2
#define F_POUT3   gPCTL[0].bit3
#define F_POUT4   gPCTL[0].bit4
#define F_POUT5   gPCTL[0].bit5
#define F_POUT6   gPCTL[0].bit6
#define F_POUT7   gPCTL[0].bit7
#define F_POUT8   gPCTL[0].bit8 
#define F_POUT9   gPCTL[1].bit1
#define F_POUT10  gPCTL[1].bit2
#define F_POUT11  gPCTL[1].bit3
#define F_POUT12  gPCTL[1].bit4
#define F_POUT13  gPCTL[1].bit5
#define F_POUT14  gPCTL[1].bit6
#define F_POUT15  gPCTL[1].bit7
#define F_POUT16  gPCTL[1].bit8  /////

#define M_POUT1   gPCTL[2].bit1
#define M_POUT2   gPCTL[2].bit2
#define M_POUT3   gPCTL[2].bit3
#define M_POUT4   gPCTL[2].bit4
#define M_POUT5   gPCTL[2].bit5
#define M_POUT6   gPCTL[2].bit6
#define M_POUT7   gPCTL[2].bit7
#define M_POUT8   gPCTL[2].bit8 
#define M_POUT9   gPCTL[3].bit1
#define M_POUT10  gPCTL[3].bit2
#define M_POUT11  gPCTL[3].bit3
#define M_POUT12  gPCTL[3].bit4
#define M_POUT13  gPCTL[3].bit5
#define M_POUT14  gPCTL[3].bit6
#define M_POUT15  gPCTL[3].bit7
#define M_POUT16  gPCTL[3].bit8  /////

#define R_POUT1   gPCTL[4].bit1
#define R_POUT2   gPCTL[4].bit2
#define R_POUT3   gPCTL[4].bit3
#define R_POUT4   gPCTL[4].bit4
#define R_POUT5   gPCTL[4].bit5
#define R_POUT6   gPCTL[4].bit6
#define R_POUT7   gPCTL[4].bit7
#define R_POUT8   gPCTL[4].bit8 
#define R_POUT9   gPCTL[5].bit1
#define R_POUT10  gPCTL[5].bit2
#define R_POUT11  gPCTL[5].bit3
#define R_POUT12  gPCTL[5].bit4
#define R_POUT13  gPCTL[5].bit5
#define R_POUT14  gPCTL[5].bit6
#define R_POUT15  gPCTL[5].bit7
#define R_POUT16  gPCTL[5].bit8  /////


#endif	/* SYSTEM_H */




