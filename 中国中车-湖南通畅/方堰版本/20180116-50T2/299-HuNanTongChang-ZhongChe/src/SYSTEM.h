/* 
 * File:   SYSTEM.h
 * Author: mpszm
 *
 * Created on 2016��8��1��, ����2:50
 */

#ifndef SYSTEM_H
#define	SYSTEM_H

#include <xc.h>
#include "bsp.h"

//ϵͳEEPROM������
//���������
#define  TOTAL_MILES   0L
//�����������
#define  SINGLE_MILES  0
//����������  �����뾶508mm  �����ٱ�6.14
#define  HM_PLUSE      177
//��������ֵ
#define  BACKLIGHT     750
//����ģ���ַ 0x01 Ϊǰ��ģ�� 0x02 Ϊ��ģ��  0x03Ϊ����ģ��   0x04Ϊ�Ǳ�
#define  MT_ADDR      4

//����汾����
#define  Version      301        //����0.1  ��V1.0
#define  Version_date 20180116  //20170726

//��ָ��
#define  NULL        (void*)0

extern unsigned int Fcan_count; //ǰ��ģ��CAN
extern unsigned int Rcan_count; //��ģ��CAN
extern unsigned int Mcan_count; //�в�ģ��CAN
extern unsigned int Ecan_count; //������ECUģ��CAN
extern unsigned int Vcan_count; //����������VCUģ��CAN
extern unsigned int Bcan_count; //��ع�����BMSģ��CAN
extern unsigned int Dcan_count; //ת������DC/ACģ��CAN
extern unsigned int Acan_count; //�յ�ACģ��CAN
extern unsigned int ECU_TIME;

extern unsigned int BAT24V_count; //���ص�ѹ������ʱ

extern unsigned int M_PO11_count; //���10���ʱ

extern unsigned int delay_5s;
extern unsigned int delay_cnt;

extern unsigned long e_total_miles;
extern unsigned int e_address; //EEPROM�洢��ַ
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

extern unsigned int  QY_TIME; //��ѹ��ʱ����
extern unsigned int  KYJ_TIME;//��ѹ����ʱ����
extern unsigned char QY_OUT_EN;

extern unsigned int fMK_Version; //ǰģ��汾��
extern unsigned int mMK_Version; //��ģ��汾��
extern unsigned int rMK_Version; //��ģ��汾��

/*�������ƽӿ� */
#define KEY_AV       _RD11       //S1
#define KEY_AV_DR    _TRISD11

#define KEY_SET        _RD10      //S2
#define KEY_SET_DR     _TRISD10

#define KEY_UP         _RD7       //S6
#define KEY_UP_DR      _TRISD7

//�Ǳ��������Դ���ƶ˿�
#define PWR_CTRL_DR   _TRISG13  
#define PWR_CTRL      _LATG13
#define PWR_CTRL_RD   _RG13

//�������˿�

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
#define  F500ms_LCD       gKEY[1].bit6 //lcd��ʾ����ʱ��
#define  alarm_update_flag  gKEY[1].bit7//������ʾ����ʱ��
//#define  CLR_single_miles gKEY[1].bit7
#define  save_flag        gKEY[1].bit8

#define  key_long_set     gKEY[2].bit1
#define  M_ON             gKEY[2].bit2  
#define  kFLASH           gKEY[2].bit3
#define  FLASH            gKEY[2].bit4 //ת�����˸��־
#define  FLASH_1s         gKEY[2].bit5 
#define  DM1_CLEAR        gKEY[2].bit6 
#define  R_flag           gKEY[2].bit7
#define  bLCD_RESET       gKEY[2].bit8

#define  F300ms           gKEY[3].bit1 // 2016/10/22��������ʱ��
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

extern DATA_BIT gCTL[8]; //�Ǳ����������Ϣ
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

extern DBCM_KEY fKEY; //ǰģ�鹦�ʿ���״̬
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

extern DBCM_KEY mKEY; //�У�����ģ�鹦�ʿ���״̬
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

extern DBCM_KEY rKEY; //��ģ�鹦�ʿ���״̬
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

#define CAN_TIME 30//CAN�ڵ���ϱ���
#define BAT24_TIME 100//���ص�ѹ���ͱ���10��

extern unsigned int fFreq; //ǰģ��Ƶ��
extern unsigned int mFreq; //�У�����ģ��Ƶ��
extern unsigned int rFreq; //��ģ��Ƶ��
extern unsigned int fSpeed; //ǰģ�����㳵��
extern unsigned int mSpeed; //�У�����ģ�����㳵��
extern unsigned int rSpeed; //��ģ�����㳵��
extern unsigned int fADR[2]; //ǰģ�����ֵ
extern unsigned int mADR[2]; //�У�����ģ�����ֵ
extern unsigned int rADR[2]; //��ģ�����ֵ
extern DBCM_POUT fPOUT; //ǰģ�鹦�����״̬
extern DBCM_POUT mPOUT; //�У�����ģ�鹦�����״̬
extern DBCM_POUT rPOUT; //��ģ�鹦�����״̬
extern unsigned char fPF[16]; //ǰģ�鹦���������
extern unsigned char mPF[16]; //�У�����ģ�鹦�ʹ���
extern unsigned char rPF[16]; //��ģ�鹦���������
extern unsigned int fpcur[15];//ǰģ�鹦���������
extern unsigned int mpcur[15];//��ģ�鹦���������
extern unsigned int rpcur[15];//��ģ�鹦���������

extern unsigned int ADR[8]; //ģ�����ɼ�   10/15
extern unsigned int ADV[8]; //ģ�����ɼ� 

extern unsigned int pSpeed; //�ⲿCAN���㳵��
/*************************************/


/******************************************************************/
 #define  BAT_NUM      96  //�����ظ���
 #define  CAN_BAT_NUM  24   //�����ص�ѹCAN��������֡����
 #define  BAT_BOX_NUM  10               //һ֡�����ĸ������ѹ�������ĸ����ĸ�����      

//�������������� 
extern  unsigned int   DJcontroler_voltage;//��������������ѹ
extern  unsigned int   DJcontroler_current; //����������������
extern  unsigned int   DJ_torque;           //������������������
extern  unsigned int   DJ_speed;

extern  unsigned char  DJ_temperature;             //��������¶�
extern  unsigned char  DJcontroler_temperature;    //��������������¶�
extern  unsigned char  FDJ_temperature;            //������¶�
extern  unsigned char  FDJcontroler_temperature;   //������������¶�
extern  unsigned char  DR_state;                   //˾������״̬
extern  unsigned char  KEY_state;                  //������״̬
extern  unsigned char  system_state;               //ϵͳ����״̬
extern  unsigned int   system_fault;               //ϵͳ������

extern  unsigned  int  EngineSpeed;
extern  unsigned char  WaterTem;
extern  unsigned char  EngineLoad;    //������������
extern  unsigned char  urea_high;     //����Һλ
extern  unsigned char  speed_st1;     //������Ŀ������̤��״̬
extern  unsigned char  speed_st2;     //������ʵ������̤��
extern  unsigned char  controler_LIFE; //����������Life

extern  unsigned char  traction_st;   //ǣ��̤��ٷֱ�
extern  unsigned char  brake_st;      //�ƶ�̤��ٷֱ�
extern  unsigned char  engine_oil_press;       //����������ѹ��
extern  unsigned char  ambient_air_temperature;//�����������¶�
extern  unsigned long  total_fuel;     //�������ۼ��ͣ���������

extern  unsigned char  debug_num[8]; //���Բ���1

extern  unsigned char  KZQversion[7];
extern  unsigned char  FDJversion[7];  //����汾�Ÿ� 3�ֽ�
extern  unsigned char  DJversion[7];   //����汾�Ÿ� 3�ֽ�

extern  unsigned int   DJ_torqueST; //�������Ŀ��ת��
extern  unsigned int   EngineSpeST; //������Ŀ��ת��
extern  unsigned char  instantaneous_fuel; //˲̬ȼ�;�����
extern  unsigned int   single_BGLfuel;    //С�ưٹ����ͺ�
extern  unsigned int   total_BGLfuel;     //�ܼưٹ����ͺ�

extern  unsigned int   DCDC_SC_voltage;
extern  unsigned int   DCDC_SC_current;
extern  unsigned int   DCDC_SR_voltage;
extern  unsigned char  DCDC_temperature;
extern  unsigned char  DCDC_fault;        //DCDC������

extern  unsigned int   DCAC_W_current;
extern  unsigned int   DCAC_V_current;
extern  unsigned int   DCAC_U_current;
extern  unsigned char  DCAC_temperature;
extern  unsigned char  DCAC_fault;   

extern  unsigned int   CD_current; //��ǰ������������
extern  unsigned int   FD_current; //��ǰ�������ŵ����
extern  unsigned char  DC_fault;  //ϵͳ���ϵȼ�
extern  unsigned char  Tmin;     //��͵������¶�
extern  unsigned char  Twater; //��ˮ���¶�
extern  unsigned char  DC_JCQst[2]; //��ؽӴ�������Ͽ���ʶ

extern  unsigned char  KT_Status[3];
extern  unsigned char  KT_temp[3];
extern  unsigned int   KT_current;
extern  unsigned char  KT_life;

extern  unsigned char  KT_ctrl;
extern  unsigned char  KT_MODE;//�յ�ѡ��ģʽ  0�綯 1��ͳ
extern  unsigned char  KT_temp1[3];
//��ص�ع�����ر��� 
extern  unsigned int   DC_voltage; //��ص�ѹ 
extern  unsigned int   DC_current; //��ص��� 
extern  unsigned char  DC_SOC;
extern  unsigned char  DC_Status[6];

extern  unsigned int   Vmax;     //������ѹ
extern  unsigned char  Vmax_num; //������ѹ���
extern  unsigned char  Tmax;     //��������¶�
extern  unsigned char  Tmax_num; //��������¶����
extern  unsigned int   Vmin;     //��С�����ѹ
extern  unsigned char  Vmin_num; //��С�����ѹ���

extern  unsigned int   anode_R;     //���˶Եؾ�Ե����
extern  unsigned int   negative_R;  //���˶Եؾ�Ե����
extern  unsigned char  eror_R;      //��Ե���ϵȼ�
extern  unsigned char  R_life;      //
extern  unsigned char  R_ID;      //����©�籨��

extern  unsigned char  KT_fuhe; //�յ�ʵ�ʹ�������
extern  unsigned char  CAR_MODE;//����ģʽ-�Լ�-���-����
extern  unsigned char  XHLC;    //�������
extern  unsigned char  TYBJ_state[8];//ͨ�ñ�����־

extern  unsigned int   Vpj;//����ƽ����ѹ

extern  unsigned char  Tmax1;//��������¶�

extern  unsigned int   anode_R1;//���˶Եؾ�Ե����
extern  unsigned int   negative_R1;//���˶Եؾ�Ե����

extern  unsigned char  VIN_Status;//VIN����״̬
extern  unsigned char  CDZ_temp[4];//������¶�

extern  unsigned int   DC_EDRL;  //��ض����
extern  unsigned int   DC_EDDY;  //��ض��ѹ
extern  unsigned int   DC_CL_SUM;//��ص��崮������
extern  unsigned char  DC_BL_SUM;//��ص��岢������
extern  unsigned char  DC_WD_SUM;//���ϵͳ�¶�̽��

extern  unsigned char  Tmax_box;//��������¶����
extern  unsigned char  Tmin_box;//��С�������¶����
extern  unsigned char  Vmax_box;//������ص�ѹ���
extern  unsigned char  Vmin_box;//��С�����ص�ѹ���
extern  unsigned char  Tmin_num;//��С�������¶����

extern  unsigned char  DC_style;//�������
extern  unsigned char  DC_LengQ;//�����ȴ��ʽ

extern  unsigned int   BAT_vol[10];//�����������ѹ
extern  unsigned int   BAT_num[10];//�����������ѹ���

extern  unsigned char  BAT_temp[10];//�����������¶�
extern  unsigned char  BAT_num1[10];//�����������¶ȱ��

extern  unsigned char  MHQ_DCBOX;//�����������
extern  unsigned char  MHQ_YJJB; //�����ϵͳԤ������
extern  unsigned char  MHQ_fault;//�����������

extern  unsigned char  MHQ_TIME;//����Уʱ
extern  unsigned char  YW_Status[6];//������
extern  unsigned char  YZT_LIFE;//����ͨ״̬

extern  unsigned int   XDC_current; //���ص���  
extern  unsigned int   XDC_voltage; //���ص�ѹ                
extern  unsigned char  PDH_temp;//�����¶�

extern  unsigned int   Vspeed;

/*****************�ְ�����CAN*****************/

typedef union {

    struct {
        unsigned long SPN1 : 19;
        unsigned FMI : 5;
        unsigned CM : 1;
        unsigned OC : 7;
    }; //����ṹ��Ҫ��֤
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
    unsigned char pack; //CAN�ּ������ݴ���
    unsigned char flag; //CAN�����������
    unsigned char len; //CAN���泤��
    unsigned char buf[50]; //CAN��������
} CAN_CACHE;
extern CAN_CACHE m_can;//HCU����
extern CAN_CACHE n_can;//TCU����
extern CAN_CACHE c_can;//CCU����

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

extern DATA_BIT gPCTL[8]; //�Ǳ����������Ϣ
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




