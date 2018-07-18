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
#define  HM_PLUSE      1320
//��������ֵ
#define  BACKLIGHT     750
//����ģ���ַ 0x01 Ϊǰ��ģ�� 0x02 Ϊ��ģ��  0x03Ϊ����ģ��   0x04Ϊ�Ǳ�
#define  MT_ADDR       4
//����汾��
#define  VERISON       200
//�Խ�����
#define  TIME          20180329L
//�Խ�����
#define  NULL          (void*)0

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

extern unsigned int BAT24V_count; //���ص�ѹ������ʱ

extern unsigned int M_PO11_count; //���10���ʱ

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
#define  F_3              gKEY[4].bit4



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
//extern const unsigned char BMP_LOGO[];
//extern const unsigned char BMP_LOGObmp[];

/*************************************/
/*typedef struct {

    struct {
        unsigned char : 3;
        unsigned char DMC_Level : 2; //������������ϼ���
        unsigned char DMC_Status : 3; //�������������״̬

        unsigned char DMC_Life; //�������
        unsigned int  DMC_Torque; //���ת��
        unsigned int  DMC_Rpm; //���ת��
        unsigned char DMC_Speed; //����
        unsigned char DMC_Gear; //��λ
    } ID_1002FF1E;
    
    struct {
        unsigned int  DMC_Voltage; //���������ĸ�ߵ�ѹ
        unsigned int  DMC_Current; //���������ĸ�ߵ���
        unsigned char DMC_Controller_temp; //����������¶�
        unsigned char DMC_Moto_temp; //����¶�
        unsigned char DMC_Protect_code; //������������ϴ���
        unsigned char DMC_Verison; //����������汾��
    } ID_1003FF1E;
    
} CAN_SIGNAL_TYPE_S;

extern CAN_SIGNAL_TYPE_S CAN_SIGNAL;*/
//���
extern unsigned char DMC_Status;//�������������״̬
extern unsigned char DMC_Level;//������������ϼ���
extern unsigned char DMC_Life;//�������
extern unsigned int  DMC_Torque;//���ת��
extern unsigned int  DMC_Rpm;//���ת��
extern unsigned char DMC_Speed;//����
extern unsigned char DMC_Gear;//��λ

extern unsigned int  DMC_Voltage;//���������ĸ�ߵ�ѹ
extern unsigned int  DMC_Current;//���������ĸ�ߵ���
extern unsigned char DMC_Controller_temp;//����������¶�
extern unsigned char DMC_Moto_temp;//����¶�
extern unsigned char DMC_Protect_code;//�����������������
extern unsigned char DMC_Verison;//����������汾��

extern unsigned char DMC_Accelerator_percent;//����̤�忪��
extern unsigned char DMC_Brake_percent;//�ƶ�̤�忪��
extern unsigned char DMC_Charge;//��ŵ�״̬
extern unsigned char DMC_GB_Gear; //���굵λ

//���ÿ�����
extern unsigned int  DMQ_Rpm;//���ÿ��������ת��
extern unsigned int  DMQ_Voltage;//���ÿ�����ĸ�ߵ�ѹ
extern unsigned char DMQ_Current;//���ÿ��������ĸ�ߵ���
extern unsigned char DMQ_temp; //�����¶�
extern unsigned char DMQ_Controller_temp;//���ÿ������¶�
extern unsigned char DMQ_Life;//���ÿ���������
extern unsigned char DMQ_Status;//���ÿ���������״̬

//DCDC
extern unsigned char DCDC_Status;//DCDC����״̬
extern unsigned char DCDC_Temp;//DCDCģ���¶�
extern unsigned int  DCDC_Voltage;//DCDC�����ѹ
extern unsigned int  DCDC_Current;//DCDC�������
extern unsigned char DCDC_Code;//DCDC���ϴ���
extern unsigned char DCDC_Verison;//DCDC�汾��

//�ͱÿ�����
extern unsigned int  DMY_Rpm;//�ͱÿ��������ת��
extern unsigned int  DMY_Voltage;//�ͱÿ�����ĸ�ߵ�ѹ
extern unsigned char DMY_Current;//�ͱÿ��������ĸ�ߵ���
extern unsigned char DMY_Controller_temp;//�ͱÿ������¶�
extern unsigned char DMY_Life;//�ͱÿ���������
extern unsigned char DMY_Status;//�ͱÿ���������״̬

//�յ�
extern unsigned char Air_Status_Flag1; //�յ�״̬1
extern unsigned char Air_Status_Flag2; //�յ�״̬2
extern unsigned char Air_Status_Flag3; //�յ�״̬3
extern unsigned char Air_Indoor_t; //�����¶�
extern unsigned char Air_Outdoor_t; //�����¶�
extern unsigned char Air_Set_t; //�趨

//BMS
extern unsigned char BMS_Type;//BMS��������
extern unsigned char Battery_Case_Total_Number;//����������
extern unsigned char BMS_Unit_Number;//��ع���ϵͳ�ӿص�Ԫ����
extern unsigned int  Battery_Cell_Total_Number;//����ܴ���
extern unsigned int  BMS_Nubmer;//��ع���ϵͳ���

extern unsigned char Battery_Case_number;//������n
extern unsigned char Battery_Cell_number;//�����n�ڵ�ش���
extern unsigned char Battery_Cell_Temp_Number;//������ڵ���¶�̽ͷ����

extern unsigned int  BMS_V;//����ܵ�ѹ
extern unsigned int  BMS_A;//����ܵ���
extern unsigned char BMS_SOC;//���SOC
extern unsigned char BMS_Life;//BMS LIFE
extern unsigned char BMS_Status_Flag1;//���״̬1
extern unsigned char BMS_Status_Flag2;//���״̬2

extern unsigned int  Battery_Single_H; //��ص���ߵ�ѹ
extern unsigned int  Battery_Single_L; //��ص���͵�ѹ
extern unsigned char Battery_Temp_H; //��ص�������¶�
extern unsigned char Battery_Temp_L; //��ص�������¶�
extern unsigned char BMS_Status_Flag3;//���״̬3
extern unsigned char BMS_Status_Flag4;//�̵���״̬

extern unsigned char Battery_Single_H_Positon_Case; //��ص���ߵ�ѹ���
extern unsigned char Battery_Single_H_Positon_Cell; //��ص���ߵ�ѹλ��
extern unsigned char Battery_Single_L_Positon_Case; //��ص���͵�ѹ���
extern unsigned char Battery_Single_L_Positon_Cell; //��ص���͵�ѹλ��
extern unsigned char Battery_Temp_H_Positon_Case; //��ص�����¶����
extern unsigned char Battery_Temp_H_Positon_Cell; //��ص�����¶�λ��
extern unsigned char Battery_Temp_L_Positon_Case; //��ص�����¶����
extern unsigned char Battery_Temp_L_Positon_Cell; //��ص�����¶�λ��

extern DATA_BIT      BMU_Comm_Status[4];//1-8   BMUͨѶ״̬
/*extern unsigned char BMU_Comm_Status2;//9-16  BMUͨѶ״̬
extern unsigned char BMU_Comm_Status3;//17-24 BMUͨѶ״̬
extern unsigned char BMU_Comm_Status4; //25-32 BMUͨѶ״̬*/

extern DATA_BIT      BMU_Bala_Status[4]; //1-8   BMU����״̬
/*extern unsigned char BMU_Bala_Status2; //9-16  BMU����״̬
extern unsigned char BMU_Bala_Status3; //17-24 BMU����״̬
extern unsigned char BMU_Bala_Status4; //25-32 BMU����״̬*/

extern unsigned char DC1positive_Temp;//����ͷDC1+�¶�
extern unsigned char DC1negative_Temp;//����ͷDC1-�¶�
extern unsigned char DC2positive_Temp;//����ͷDC2+�¶�
extern unsigned char DC2negative_Temp;//����ͷDC2-�¶�
extern unsigned int  Ohm_Positive;//������Ե��ֵ 
extern unsigned int  Ohm_Negative;//�ܸ���Ե��ֵ 

extern unsigned int  Energe_Rest;//ʣ������
extern unsigned char BMS_Status_Flag5;
extern unsigned char BMS_Status_Flag6;

extern unsigned char Battery_Single_H_Positon_Total;//��ߵ����ѹλ�ã�������
extern unsigned char Battery_Single_L_Positon_Total;//��͵����ѹλ�ã�������
extern unsigned char Battery_Temp_H_Positon_Total;//��ߵ����¶�λ�ã�������
extern unsigned char Battery_Temp_L_Positon_Total;//��͵����¶�λ�ã�������
extern unsigned char Battery_Single_H_Pack;//��ߵ����ѹ����
extern unsigned char Battery_Single_L_Pack;//��͵����ѹ����
extern unsigned char Battery_Temp_H_Pack;//��ߵ����¶Ȱ���
extern unsigned char Battery_Temp_L_Pack;//��͵����¶Ȱ���

extern unsigned char BMU_Number;//BMU��

extern unsigned char Battery_Pack; //��ر��İ���
extern unsigned int  Battery_Voltage[12]; //��ص����ѹ
extern unsigned int  Battery_Temp[12]; //��ص����¶�


/******************************************************************************/
extern unsigned int  BMS_Status;
extern unsigned char Battery_Temp_avg; //��ص���ƽ���¶�
extern unsigned char Battery_Oum_Status; 

extern unsigned char BMS_Charge_Status; 
extern unsigned char BMS_Warn; 
extern unsigned char BMS_Fault_Number; 

extern unsigned char KT; 

/******************************************************************************/
#pragma pack(1)

typedef union {

    struct {
        unsigned MotoVoltage; //��������ѹ
        unsigned MotoCurrent; //����������
        unsigned char MotorControllerTemperature; //����¶�
        unsigned char MotorTemperature; //����¶�   
        unsigned char MotorControllerLife;  
        unsigned char CANVerison;  
    };
    unsigned char byte[8];
} _CAN_0x10F811A4;

typedef union {

    struct {
        unsigned char MotorFaultNumber;
        unsigned char MotorSquence;
        unsigned char MotorStatus;
        unsigned MotoSpeed; //���ת��
        unsigned MotoTorque; //���ת��
        unsigned char Reserve;
    };
    unsigned char byte[8];
} _CAN_0x10F813A4;

typedef union {

    struct {
        unsigned char Reserve1 : 1;
        unsigned char VCUEnInsulation : 3;
        unsigned char KT : 4;
        unsigned char Reserve2;
        unsigned char Reserve3;
        unsigned char Reserve4;
        unsigned char Reserve5;
        unsigned char Reserve6;
        unsigned char Reserve7;
        unsigned char Reserve8;
    };
    unsigned char byte[8];
} _CAN_0x0C109E27;

typedef union {

    struct {
        unsigned char Reserve1 : 3;
        unsigned char BMSFaultLevel : 2;
        unsigned char BMSStatus : 3;
        unsigned char BATAverageTemp;
        unsigned char BMS_SOC; //���SOC
        unsigned BMS_A; //��ص���
        unsigned BMS_V; //��ص�ѹ     
        unsigned char Reserve2;
    };
    unsigned char byte[8];
} _CAN_0x10F8159E;

typedef union {

    struct {
        unsigned char BAT_Min_Cell_Temperature; //��͵����¶�
        unsigned char BAT_Min_Cell_Temp_Cell_Case; //��͵����¶���� 
        unsigned char BAT_Min_Cell_Temp_Cell_Number; //��͵����¶�λ��
        unsigned char Reserve1;
        unsigned char BAT_SMin_Cell_Temperature; //��ε͵����¶�
        unsigned char BAT_SMin_Cell_Temp_Cell_Case; //��ε͵����¶���� 
        unsigned char BAT_SMin_Cell_Temp_Cell_Number; //��ε͵����¶�λ��
        unsigned char Reserve2;
    };
    unsigned char byte[8];
} _CAN_0x10F8179E;

typedef union {

    struct {
        unsigned char BAT_Max_Cell_Temperature; //��ߵ����¶�
        unsigned char BAT_Max_Cell_Temp_Cell_Case; //��ߵ����¶���� 
        unsigned char BAT_Max_Cell_Temp_Cell_Number; //��ߵ����¶�λ��
        unsigned char Reserve1;
        unsigned char BAT_SMax_Cell_Temperature; //��θߵ����¶�
        unsigned char BAT_SMax_Cell_Temp_Cell_Case; //��θߵ����¶���� 
        unsigned char BAT_SMax_Cell_Temp_Cell_Number; //��θߵ����¶�λ��
        unsigned char Reserve2;
    };
    unsigned char byte[8];
} _CAN_0x18F8189E;

typedef union {

    struct {
        unsigned BAT_Min_Cell_Voltage; //��͵����ѹ
        unsigned char BAT_Min_Cell_Voltage_Cell_Number; //��͵����ѹλ��
        unsigned char BAT_Min_Cell_Voltage_Cell_Case; //��͵����ѹ���       
        unsigned BAT_SMin_Cell_Voltage; //��ε͵����ѹ
        unsigned char BAT_SMin_Cell_Voltage_Cell_Number; //��ε͵����ѹλ��
        unsigned char BAT_SMin_Cell_Voltage_Cell_Case; //��ε͵����ѹ���         
    };
    unsigned char byte[8];
} _CAN_0x18F8199E;

typedef union {

    struct {
        unsigned BAT_Max_Cell_Voltage; //��ߵ����ѹ
        unsigned char BAT_Max_Cell_Voltage_Cell_Number; //��ߵ����ѹλ��
        unsigned char BAT_Max_Cell_Voltage_Cell_Case; //��ߵ����ѹ���       
        unsigned BAT_SMax_Cell_Voltage; //��θߵ����ѹ
        unsigned char BAT_SMax_Cell_Voltage_Cell_Number; //��θߵ����ѹλ��
        unsigned char BAT_SMax_Cell_Voltage_Cell_Case; //��θߵ����ѹ���         
    };
    unsigned char byte[8];
} _CAN_0x18F81B9E;

typedef union {

    struct {
        unsigned char BMSFaultNumber;     
        unsigned BATRestEnerge; //���ʣ������
        unsigned BATCellTotalNumber;//����ܴ���
        unsigned char Reserve1;
        unsigned char Reserve2;
        unsigned char CANVerison;
    };
    unsigned char byte[8];
} _CAN_0x10F8209E;

typedef union {

    struct {
        unsigned long BMSWarningFlag;   
        unsigned char Reserve1;
        unsigned char ChargeStatus;
        unsigned Ohm_Positive;
    };
    unsigned char byte[8];
} _CAN_0x10F8219E; 

typedef union {

    struct {
        unsigned char BATCaseNumber;  
        unsigned char BATCellNumber;  
        unsigned BATTempNumber;  
        unsigned BATVoltage;  
        unsigned BATCurrent;
    };
    unsigned char byte[8];
} _CAN_0x10F8239E;

typedef union {

    struct {
        unsigned char VCULife;
        unsigned char ChargeStatus : 2;
        unsigned char Door : 1;
        unsigned char Key : 2;       
        unsigned char READY : 1;
        unsigned char Reserve1 : 2;
        unsigned char VCUFaultCode;
        unsigned char VCUSpeed;
        unsigned long VCUTotalMile;
    };
    unsigned char byte[8];
} _CAN_0x18F81F27;

typedef union {

    struct {
        unsigned char AcceleratePedal;
        unsigned char Reserve1;
        unsigned char Reserve2;
        unsigned char Reserve3;
        unsigned char Reserve4;
        unsigned char Reserve5;
        unsigned char Reserve6;
        unsigned char BrakePedal;
    };
    unsigned char byte[8];
} _CAN_0x18F80227;
#pragma pack()

extern _CAN_0x10F811A4 CAN_0x10F811A4;
extern _CAN_0x10F813A4 CAN_0x10F813A4;
extern _CAN_0x0C109E27 CAN_0x0C109E27;
extern _CAN_0x10F8159E CAN_0x10F8159E;
extern _CAN_0x10F8179E CAN_0x10F8179E;
extern _CAN_0x18F8189E CAN_0x18F8189E;
extern _CAN_0x18F8199E CAN_0x18F8199E;
extern _CAN_0x18F81B9E CAN_0x18F81B9E;
extern _CAN_0x10F8209E CAN_0x10F8209E;
extern _CAN_0x10F8219E CAN_0x10F8219E;
extern _CAN_0x10F8239E CAN_0x10F8239E;
extern _CAN_0x18F81F27 CAN_0x18F81F27;
extern _CAN_0x18F80227 CAN_0x18F80227;

extern unsigned char BATCellNumber; 
extern unsigned char BATCellTemp[20][7]; 
extern unsigned char BATCellVoltage[200];
/******************************************************************************/

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
char Count_Time(unsigned char condition, //��������
        unsigned int  out_time,           //�������㣬����ʱ��
        unsigned char cycle_en,           //�Ƿ�ѭ��ִ��
        unsigned int  stop_time           //ѭ��ִ��ʱ����Ъʱ��
        );

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

