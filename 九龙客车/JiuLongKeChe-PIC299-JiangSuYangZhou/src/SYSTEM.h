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
//����������
#define  HM_PLUSE     1320
//��������ֵ
#define  BACKLIGHT     750
//����ģ���ַ 0x01 Ϊǰ��ģ�� 0x02 Ϊ��ģ��  0x03Ϊ����ģ��   0x04Ϊ�Ǳ�
#define  MT_ADDR      4
//����汾��
#define  VERISON      200

extern unsigned char Fversion;//ǰģ��汾
extern unsigned char Mversion;//��ģ��汾
extern unsigned char Rversion;//��ģ��汾

extern unsigned int Fcan_count; //ǰ��ģ��CAN
extern unsigned int Rcan_count; //��ģ��CAN
extern unsigned int Mcan_count; //�в�ģ��CAN
extern unsigned int Ecan_count; //������ECUģ��CAN
extern unsigned int Vcan_count; //����������VCUģ��CAN
extern unsigned int Bcan_count; //��ع�����BMSģ��CAN
extern unsigned int Dcan_count; //ת������DC/ACģ��CAN
extern unsigned int Acan_count; //�յ�ACģ��CAN

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

#define  key_set     gKEY[0].bit1 
#define  pkey_set    gKEY[0].bit2 
#define  bkey_set    gKEY[0].bit3
#define  key_up      gKEY[0].bit4
#define  pkey_up     gKEY[0].bit5  
#define  bkey_up     gKEY[0].bit6
#define  key_AV      gKEY[0].bit7
#define  pkey_AV     gKEY[0].bit8

#define  bkey_AV     gKEY[1].bit1
#define  key_duble   gKEY[1].bit2
#define  F50ms       gKEY[1].bit3
#define  F100ms      gKEY[1].bit4
#define  F500ms      gKEY[1].bit5  
#define  F500ms_LCD  gKEY[1].bit6 //lcd��ʾ����ʱ��
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
#define  F30s             gKEY[3].bit8

#define  F30s_flag        gKEY[4].bit1

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

#define CAN_TIME 30//CAN�ڵ���ϱ���

typedef union {

    struct {
        unsigned bit1 : 2;
        unsigned bit2 : 2;
        unsigned bit3 : 2;
        unsigned bit4 : 2;
    };
    unsigned char byte;
} DATA_DOUBLE;

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

extern unsigned int ADR[8]; //ģ�����ɼ�   2016/10/15
extern unsigned int ADV[8]; //ģ�����ɼ�   2016/10/15

extern unsigned char LIFE;//�Ǳ�lIFE
//extern unsigned char Count30s;
//extern const unsigned char BMP_LOGO[];
//extern const unsigned char BMP_LOGObmp[];

/**********����Э�����************/
extern unsigned char VCU_LIFE; //����������LIFE
extern unsigned char READY; //����������״̬
extern unsigned char Inverter_Fault; //��������������
extern unsigned char Vacuum_Fault; //��նȹ���
extern unsigned char BAT24V_Fault; //���ع���
extern unsigned char DCDC_Fault; //DCDC����
extern unsigned char Speed_Percent; //����̤�忪��
extern unsigned char Brake_Percent; //�ƶ�̤�忪��
extern unsigned int  Moto_Torque;//ת��
extern unsigned char Motor_Temperature; //����¶�
extern DATA_BIT VCU[4];
#define  WATER_PUMP            VCU[0].bit1
#define  FAN_LOW               VCU[0].bit2  
#define  FAN_HIGH              VCU[0].bit3  
#define  AIR_PUMP              VCU[0].bit4  
#define  AC                    VCU[0].bit5  
#define  HAND_BRAKE            VCU[0].bit6  
#define  FOOT_BRAKE            VCU[0].bit7  
#define  ECO                   VCU[0].bit8  

extern unsigned char VCU_Gear; //��λ
extern unsigned char PTC_Front; //ǰģ��PTC��λ
extern unsigned char PTC_Rear;  //��ģ��PTC��λ
extern unsigned char Charge_Status; //���״̬
extern unsigned char BUS_Status; //����״̬
extern unsigned char Moto_Fault; //���ϵͳ����
extern unsigned char BAT_Fault; //���ϵͳ����
extern unsigned char VCU_Fault; //��������������
extern unsigned char WaterPump_Fault; //ˮ�ù���
extern unsigned char Fan_Fault; //���ȹ���
extern unsigned char AirPump_Fault; //���ù���
extern unsigned char BAT24V_Status; //����״̬
extern unsigned char Gear_Fault; //�ҵ�ʧ��
extern unsigned char Inverter_t; //�������¶�
extern unsigned char Vacuum; //��ն�
//unsigned char BMS_SOC; //���SOC

extern unsigned char VCU_Speed; //����
extern unsigned int  Rest_Mile; //�������
extern unsigned int  Moto_Rpm; //���ת��

extern unsigned int  Moto_Voltage; //���ֱ����ѹ
extern unsigned int  Moto_Current; //��������
extern unsigned int  Moto_PhaseVoltage; //������ѹ
extern unsigned char Press1; //��ѹ1
extern unsigned char Press2; //��ѹ2

extern unsigned long Program; //����汾

//BMS
extern unsigned int  BMS_V; //��ص�ѹ
extern unsigned int  BMS_A; //��ص���
extern unsigned char BMS_SOC; //���SOC
extern unsigned char BMS_Life; //BMSlife
extern unsigned char BMS_Fault; //BMS���ϵȼ�
extern unsigned char Oum_Warn; //������Ե����

extern unsigned char BAT_Voltage_Number[4];//�����ѹ���
extern unsigned char BAT_Temperature_Number;//�����¶����
extern unsigned char BAT_Cell_Voltage[210]; //��ص����ѹ
extern unsigned char BAT_Cell_Temperature[60][3]; //��ص����¶�

extern DATA_BIT BMS[8];
extern unsigned char BAT_Number;//������ܴ���
extern unsigned int  BAT_Ahr;//���������

extern unsigned int  BAT_Max_Cell_Voltage; //��ص���ߵ�ѹ
extern unsigned int  BAT_Min_Cell_Voltage; //��ص���͵�ѹ
extern unsigned int  BAT_Max_Cell_Temperature; //��ߵ����¶�
extern unsigned int  BAT_Min_Cell_Temperature; //��͵����¶�

extern unsigned char BAT_Max_Cell_Voltage_Cell_Case; //��ߵ����ѹ���
extern unsigned char BAT_Max_Cell_Voltage_Cell_Number; //��ߵ����ѹλ��

extern unsigned char BAT_Min_Cell_Voltage_Cell_Case; //��͵����ѹ���
extern unsigned char BAT_Min_Cell_Voltage_Cell_Number; //��͵����ѹλ��

extern unsigned char BAT_Max_Cell_Temp_Cell_Case; //��ߵ����¶����
extern unsigned char BAT_Max_Cell_Temp_Cell_Number; //��ߵ����¶�λ��

extern unsigned char BAT_Min_Cell_Temp_Cell_Case; //��͵����¶����
extern unsigned char BAT_Min_Cell_Temp_Cell_Number; //��͵����¶�λ��

//����
extern unsigned char Charger_Life;//����LIFE
extern unsigned int  Charger_Voltage;//���������ѹ
extern unsigned int  Charger_Current;//�����������
extern DATA_BIT CHARGER[1];

//0x1800B4D0
extern DATA_DOUBLE VCU_FAULT[2];
extern DATA_BIT    VCU_WARN[4];

/*
extern unsigned int Moto_Voltage; //�����ѹ
extern unsigned int Moto_Current; //�������
extern unsigned int Moto_Rpm; //���ת��
extern unsigned char Motor_Temperature; //����¶�
extern unsigned char Inverter_t; //�������¶�

extern unsigned long Program; //����汾
extern unsigned char Car_Mode; //����ģʽ
extern unsigned char Car_Fault_Level;//���ϵȼ�
extern unsigned int  Fault_Code;//���ϴ���
extern unsigned char Car_LIFE; //����������

extern DATA_BIT MET_C_3[2];
#define  Kt_1             MET_C_3[0].bit1
#define  Kt_0             MET_C_3[0].bit2  
#define  Kt_Charge        MET_C_3[0].bit3  
#define  Kt_Defrost       MET_C_3[0].bit4  
#define  Kt_AC            MET_C_3[0].bit5  

#define  Brake_Ele        MET_C_3[1].bit4
#define  READY            MET_C_3[1].bit5
extern unsigned char DCDC_Sanreqi_t; //DCDCɢ�����¶�
extern unsigned char DCDC_Warn_code; //DCDC���ϴ���
extern unsigned char DCAC1_Sanreqi_t; //DCAC1ɢ�����¶�
extern unsigned char DCAC1_Warn_code; //DCAC1���ϴ���
extern unsigned char DCAC2_Sanreqi_t; //DCAC2ɢ�����¶�
extern unsigned char DCAC2_Warn_code; //DCAC2���ϴ���

extern DATA_BIT MET_C_4[3];
#define  Gear_D           MET_C_4[0].bit3
#define  Gear_R           MET_C_4[0].bit4  
#define  Gear_N           MET_C_4[0].bit5  

#define  Park             MET_C_4[1].bit4
#define  Press_Low        MET_C_4[1].bit7  
extern unsigned char Over_Speed; //���ٱ���
extern unsigned char Speed_Percent1; //����̤��1����
extern unsigned char Speed_Percent2; //����̤��2����
extern unsigned char Brake_Percent1; //�ƶ�̤��1����
extern unsigned char Brake_Percent2; //�ƶ�̤��2����

extern unsigned int  Oum_zheng; //��Ե����ֵ
extern unsigned int  Oum_fu;    //��Ե����ֵ
extern unsigned char Oum_Warn;  //������Ե����

//BMS1_S_1
extern unsigned char BMS_SOC; //���SOC
extern unsigned int  BMS_V; //��ص�ѹ
extern unsigned int  BMS_A; //��ص���
extern unsigned int  BAT_Number;//������ܴ���
extern unsigned char BMS_Life; //BMSlife

//BMS1_S_3
extern DATA_BIT BMS1_S_3[3];
#define  BMU_OFFLINE           BMS1_S_3[0].bit1
#define  CHARGER_COMM_FAULT    BMS1_S_3[0].bit2  
#define  PRECHARGE_FAULT       BMS1_S_3[0].bit3 
#define  BALANCE_FAULT         BMS1_S_3[0].bit4
#define  WARN_FAULT            BMS1_S_3[0].bit5 
#define  BAT_COOL_FAULT        BMS1_S_3[0].bit6
#define  BMS_FAULT_OTHER       BMS1_S_3[0].bit7
#define  BMS_COMM_FAULT        BMS1_S_3[0].bit8  

#define  CHARGE_PLUG           BMS1_S_3[1].bit4
#define  CHARGE_STATUS         BMS1_S_3[1].bit5 
#define  BAT_FAULT             BMS1_S_3[1].bit6
extern unsigned char BMS_Self_Check;//BMS�Լ�״̬

#define  TEMP_COLT_OFFLINE     BMS1_S_3[2].bit1
#define  BAT_CELL_COLT_OFFLINE BMS1_S_3[2].bit2  
#define  SOC_JUMP              BMS1_S_3[2].bit4
#define  SYSTEM_MISMATCH       BMS1_S_3[2].bit5 
#define  FIRE_FAULT            BMS1_S_3[2].bit6
#define  VOLTAGE_DIFF_FAULT    BMS1_S_3[2].bit7

extern unsigned char Battery_OverTemp;//��ظ��±���
extern unsigned char Pole_OverTemp;//�������±���
extern unsigned char Single_Bat_OverVoltage;//�����ѹ����
extern unsigned char Pack_Bat_OverVoltage;//������ѹ����
extern unsigned char Pack_Bat_UnderVoltage;//�����Ƿѹ����
extern unsigned char Single_Bat_UnderVoltage;//����Ƿѹ����
extern unsigned char Charge_Gun_OverTemp;//���ǹ���±���
extern unsigned char Bat_Fault;//������ع���
extern unsigned char Discharge_OverCurrent;//�ŵ��������
extern unsigned char Charge_OverCurrent;//����������
extern unsigned char Diff_Voltage;//�����ѹ���챨��
extern unsigned char Diff_Temp;//�¶Ȳ��챨��
extern unsigned char SOC_Low;//SOC�ͱ���
extern unsigned char SOC_High;//SOC�߱���
extern unsigned char Diff_SOC;//SOC���챨��
extern unsigned char Bat_LowTemp;//����¶ȵͱ���

//BMS����������
extern unsigned int  BAT_Max_Cell_Voltage[4]; //��ص���ߵ�ѹ
extern unsigned char BAT_Max_Cell_Voltage_Cell_Case[4]; //��ߵ����ѹ���
extern unsigned char BAT_Max_Cell_Voltage_Cell_Number[4]; //��͵����ѹλ��

extern unsigned int  BAT_Min_Cell_Voltage[4]; //��ص���ߵ�ѹ
extern unsigned char BAT_Min_Cell_Voltage_Cell_Case[4]; //��ߵ����ѹ���
extern unsigned char BAT_Min_Cell_Voltage_Cell_Number[4]; //��͵����ѹλ��

extern unsigned int  BAT_Max_Cell_Temperature[4]; //��ߵ����¶�
extern unsigned char BAT_Max_Cell_Temp_Cell_Case[4]; //��ߵ����¶����

extern unsigned int  BAT_Min_Cell_Temperature[4]; //��͵����¶�
extern unsigned char BAT_Min_Cell_Temp_Cell_Case[4]; //��͵����¶����

extern unsigned char BAT_Pole_Temperature_P[16];//�������¶�
extern unsigned char BAT_Pole_Temperature_N[16];//�������¶�
*/
/*
extern unsigned int  VCU_TM_NM; //TMĿ��Ť��
extern unsigned int  VCU_TM_RPM; //TMĿ��ת��

extern unsigned char VCU_TM_Brake_percent; //�ƶ�̤�忪��
extern unsigned char VCU_TM_Speed_percent; //����̤�忪��
extern unsigned char VCU_Status_Flag1;//״̬1
extern unsigned char VCU_Gear;//��λ
extern unsigned char VCU_Fault;//����ϵͳ����
extern DATA_BIT VCU_Status_Flag2[1];
#define  READY            VCU_Status_Flag2[0].bit3
#define  BMS_OFFLINE      VCU_Status_Flag2[0].bit4  
#define  ISG_OFFLINE      VCU_Status_Flag2[0].bit5  
#define  TM_OFFLINE       VCU_Status_Flag2[0].bit6  
#define  CHARGE_OVERTIME  VCU_Status_Flag2[0].bit7  
#define  CAR_LOCK         VCU_Status_Flag2[0].bit8    
extern unsigned char VCU_Life;//����������LIFE

extern unsigned int  TM_Feedback_RPM;//TM�������ת��
extern unsigned int  TM_Feedback_NM;//TM�������Ť��
extern unsigned char TM_WorkStatus;//TM�������״̬

extern unsigned char TM_Temp;//TM����¶�
extern unsigned char TM_Control_Temp;//TM����������¶�
extern unsigned char TM_Fault;//TM������ϵȼ�

extern unsigned int  TM_Current_DC;//TM���ֱ������
extern unsigned int  TM_Voltage_DC;//TM���ֱ����ѹ

extern unsigned char VCU_Kt; //���Ӵ�����������
extern unsigned char VCU_ON; //Կ���µ�״̬
extern unsigned char VCU_Order; //���ϴ�������
extern unsigned int  VCU_Voltage; //�����������ѹ

extern unsigned char BMS_Status;//���״̬
extern unsigned char BMS_Fault; //����״̬
extern unsigned char BMS_Balance_Lock;//��ؾ�������״̬
extern unsigned char BMS_Fault_Lock;//��������״̬
extern unsigned char BMS_SOC;//SOC
extern unsigned char BMS_SOH;//SOH
extern unsigned char BMS_Ahr;//�������
extern unsigned int  BMS_Ohm;//���ϵͳ����
extern unsigned char BMS_Life;//�����ź�

extern unsigned int  BMS_Voltage;//���ϵͳ���ܵ�ѹ
extern unsigned int  BMS_OutVoltage;//���ϵͳ�����ѹ
extern unsigned int  BMS_Current;//���ϵͳ����
extern unsigned int  BMS_Power;//���ϵͳ����
extern unsigned char BMS_Temp;//�����¶�

extern unsigned int  BMS_TotalVoltage; //�����ص�ѹ�ܺ�
extern unsigned int  Battery_Single_H; //��ص���ߵ�ѹ
extern unsigned int  Battery_Single_L; //��ص���͵�ѹ
extern unsigned char Battery_Single_H_Number; //��ص���ߵ�ѹλ��
extern unsigned char Battery_Single_L_Number; //��ص���͵�ѹ���

extern unsigned int  Battery_Temp_Average; //���ƽ���¶�
extern unsigned int  Battery_Temp_H; //��ص�������¶�
extern unsigned int  Battery_Temp_L; //��ص�������¶�
extern unsigned char Battery_Temp_H_Number; //��ص�����¶����
extern unsigned char Battery_Temp_L_Number; //��ص�����¶����

extern unsigned int  Battery_Voltage_H_Limit;//���ϵͳ��ߵ�ѹ����
extern unsigned int  Battery_Voltage_L_Limit;//���ϵͳ��͵�ѹ����
extern unsigned int  Battery_Single_Voltage_H_Limit;//��ص�����ߵ�ѹ����
extern unsigned int  Battery_Single_Voltage_L_Limit;//��ص�����͵�ѹ����
extern unsigned char Battery_Current_Discharge_Limit;//�������ŵ����
extern unsigned char Battery_Current_Charge_Limit;//������������

extern unsigned char BMS_SOC_H_Limit;//�������SOCֵ
extern unsigned char BMS_SOC_L_Limit;//�������SOCֵ
extern unsigned char BMS_Power_10s_Discharge_Limit;//10s �������ŵ繦��
extern unsigned char BMS_Power_10s_Charge_Limit;//10s ��������繦��
extern unsigned char Battery_Temp_H_Limit; //��������ص����¶�
extern unsigned char Battery_Temp_L_Limit; //��������ص����¶�

extern unsigned long BMS_spn; //BMS������
extern unsigned char BMS_fmi;
extern unsigned char BMS_cm;
extern unsigned char BMS_oc;

extern unsigned int  DCDC_Voltage; //DCDC�����ѹ
extern unsigned int  DCDC_Current; //DCDC�������
extern unsigned char DCDC_Status; //DCDC����״̬
extern unsigned char DCDC_Output_Cut; //DCDC ����ж�
extern unsigned char DCDC_intput_Cut; //DCDC �����ж�
extern unsigned char DCDC_BasicStatus; //DCDC����״̬
extern unsigned char DCDC_Level_Fault; //DCDC���ϵȼ�
extern unsigned char DCDC_Temp; //DCDCģ���¶�

extern unsigned int  OILDCAC_U_Voltage; //DCAC���U��ѹ
extern unsigned int  OILDCAC_U_Current; //DCAC���U����
extern unsigned char OILDCAC_Status; //DCAC����״̬
extern unsigned char OILDCAC_Output_Cut; //DCAC ����ж�
extern unsigned char OILDCAC_intput_Cut; //DCAC �����ж�
extern unsigned char OILDCAC_BasicStatus; //DCAC����״̬
extern unsigned char OILDCAC_Level_Fault; //DCAC���ϵȼ�
extern unsigned char OILDCAC_Fault_Code; //DCAC���ϴ���
extern unsigned char OILDCAC_Temp; //DCACģ���¶�

extern unsigned int  OILDCAC_V_Voltage; //DCAC���V��ѹ
extern unsigned int  OILDCAC_V_Current; //DCAC���V����
extern unsigned int  OILDCAC_W_Voltage; //DCAC���W��ѹ
extern unsigned int  OILDCAC_W_Current; //DCAC���W����

extern unsigned int  AIRDCAC_U_Voltage; //DCAC���U��ѹ
extern unsigned int  AIRDCAC_U_Current; //DCAC���U����
extern unsigned char AIRDCAC_Status; //DCAC����״̬
extern unsigned char AIRDCAC_Output_Cut; //DCAC ����ж�
extern unsigned char AIRDCAC_intput_Cut; //DCAC �����ж�
extern unsigned char AIRDCAC_BasicStatus; //DCAC����״̬
extern unsigned char AIRDCAC_Level_Fault; //DCAC���ϵȼ�
extern unsigned char AIRDCAC_Fault_Code; //DCAC���ϴ���
extern unsigned char AIRDCAC_Temp; //DCACģ���¶�

extern unsigned int  AIRDCAC_V_Voltage; //DCAC���V��ѹ
extern unsigned int  AIRDCAC_V_Current; //DCAC���V����
extern unsigned int  AIRDCAC_W_Voltage; //DCAC���W��ѹ
extern unsigned int  AIRDCAC_W_Current; //DCAC���W����
*/
/**********************************************/

/*extern unsigned int moto_voltage; //�����ѹ
extern unsigned int moto_current; //�������
extern unsigned int moto_speed; //�綯ת��
extern unsigned char Motor_Temperature; //����¶�
extern unsigned char Inverter_t; //������¶�

extern unsigned char Accelerator; //���ſ���
extern unsigned int Engine_Speed;//������ת��

extern unsigned int Fule_rate;//�ͺ�
extern unsigned char water_temp;//ˮ��
extern unsigned char Engine_Fuhe;//����������
extern unsigned char Niaosu;//����;
extern unsigned char Accelerator_Shiji; //����̤��ʵ��
extern unsigned char Engine_oil_press; //����ѹ��
extern unsigned char ambient_air_temperature; //��Χ�����¶�

extern unsigned char Current_Gear; //��λ
extern unsigned char TCU_Position;//���λ��
extern unsigned char TCU_warn;//���������
extern unsigned char STOP;//ͣ������
extern unsigned int Speed_rmp; //�����ת��
extern unsigned char Car_mode;//����ģʽ
extern unsigned char TCU_code;//��������ϴ���
extern unsigned char TCU_level;//��������ϵȼ�

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

//#define  Kt               CAN_KEY[2].bit2  

#define  Brake_Pedal      CAN_KEY[3].bit1 
extern unsigned char Brake_percent; //�ƶ�̤�忪��
extern unsigned char Speed_percent; //����̤�忪��
extern unsigned char Digit_input3;//����������3

extern unsigned long Program;//����汾
extern unsigned long tcu_spn; //TCU������
extern unsigned char tcu_fmi;
extern unsigned long tcu_cm; 
extern unsigned char tcu_oc;
extern unsigned char Car_LIFE;//����������

extern unsigned int BMS_V; //��ص�ѹ
extern unsigned char BMS_SOC; //���SOC
extern unsigned int BMS_A; //��ص���
extern unsigned char Status_Flag1;
extern unsigned char Status_Flag2;
extern unsigned char Status_Flag3;

extern unsigned int BMS_A_charge; //��������
extern unsigned int BMS_A_discharge; //������
extern unsigned char Warn_level;//���ϵȼ�
extern unsigned int BMS_V_average; //���ƽ����ѹ
extern unsigned char BMS_T_H;//�������¶�

extern unsigned int Oum_zheng; //��Ե����ֵ
extern unsigned int Oum_fu; //��Ե����ֵ
extern unsigned int Battery_single_H; //��ص���ߵ�ѹ
extern unsigned int Battery_single_L; //��ص���͵�ѹ

extern unsigned char Battery_number[10];//��ر��
extern unsigned int Battery_voltage[10];//��ص����ѹ

extern unsigned char Battery_number_t[10];//����¶ȱ��
extern unsigned int Battery_temp[10];//��ص����¶�

extern unsigned int DCAC_W;
extern unsigned int DCAC_V;
extern unsigned int DCAC_U;
extern unsigned char Sanreqi_t;//ɢ�����¶�
extern unsigned char DCAC_Warn_code;//���ϴ���

extern unsigned char AC_Warn_code;//AC���ϴ���
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
extern unsigned char Indoor_t;//�����¶�
extern unsigned char Outdoor_t;//�����¶�
extern unsigned char Set_t;//�趨
extern unsigned char AC_req;//��������
extern unsigned char AC_LIFE;//AC����

extern unsigned char battle_t; //��ؾ���
extern unsigned char battle_t_warn; //��ع��±���
extern unsigned char battle_jueyuan_warn; //��Ե���ͱ���
extern unsigned char battle_higtv1_warn; //��ѹ���1����
extern unsigned char battle_higtv2_warn; //��ѹ���2����
extern unsigned char moto_t_warn; //�������
extern unsigned char moto_ready; //ready�ź�
extern unsigned char xudc; //�����쳣
extern unsigned char moto_warn; //�������

extern unsigned char BMS_offline_warn; //��ز�����
extern unsigned char MCU_offline_warn; //���������
extern unsigned char TCU_offline_warn; //�����䲻����
extern unsigned char Engine_offline_warn; //������������
extern unsigned char Engine_wait; //����������
extern unsigned char EV; //ģʽ
extern unsigned char Signal_charge; //����ź�


extern unsigned char mil_lamp_request; //��ɫ��������
extern unsigned char fail_mode; //���ֱ���
extern unsigned char mil_buzz_request; //��������
extern unsigned long hcu_spn; //HCU������
extern unsigned char hcu_fmi;


extern unsigned char Eng_static_test; //��������̬ת�ٲ���
extern unsigned char tcu_start_allow; //��������������


extern unsigned char Lamp_status_YELLOW; //������Ƶ�״̬
extern unsigned char Lamp_status_RED; //��������״̬

extern unsigned long ccu_spn; //CCU������
extern unsigned char ccu_fmi;

extern unsigned long ecu_spn; //ECU������
extern unsigned char ecu_fmi;



extern unsigned char Motor_Temperature; //����¶�

extern unsigned int ENG_start_req; //�Ǳ��������
extern unsigned long mot_work_time; //��������ۻ�ʱ��
extern unsigned char mot_work_percent; //�������ʱ���
extern unsigned char DCDC_ctrl; //DCDC״̬
extern unsigned char hcu_starter_forbid; //�𶯻�����
extern unsigned char aircompress_enable; //ѹ����
extern unsigned char Speed_lim_mode;//����ģʽ

extern unsigned char water_level;//ˮλ

extern unsigned char Wait_start;//�ȴ�����
extern unsigned char Maintain_warn;//ά������
extern unsigned char Stop_warn;//ͣ������
extern unsigned char Engine_warn;//����������
*/

extern unsigned int pSpeed; //�ⲿCAN���㳵��

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
    unsigned char pack; //CAN�ּ������ݴ���
    unsigned char flag; //CAN�����������
    unsigned char len; //CAN���泤��
    unsigned char buf[50]; //CAN��������
} CAN_CACHE;
extern CAN_CACHE m_can;//HCU����
extern CAN_CACHE n_can;//TCU����
extern CAN_CACHE c_can;//CCU����
extern CAN_CACHE b_can;//BMS����


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
void DM_BCU(unsigned char x);
void DM(unsigned char x, DM1 id);
//dispaly
void LCD_Exec(void);
void TIM5_Init(void);
//void TIMER4_Init(void);
/******************************/
/********************************************/

#endif	/* SYSTEM_H */

