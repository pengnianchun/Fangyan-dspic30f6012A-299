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
#define  HM_PLUSE      180
//��������ֵ
#define  BACKLIGHT     750
//����ģ���ַ 0x01 Ϊǰ��ģ�� 0x02 Ϊ��ģ��  0x03Ϊ����ģ��   0x04Ϊ�Ǳ�
#define  MT_ADDR      4

//����汾����
#define  Version      200        //����0.1  ��V1.0
#define  Version_date 20170629

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
extern unsigned int  PT1000[56][3];

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
#define  F7s              gKEY[4].bit6



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

extern unsigned char BMU_Comm_Status1;//1-8   BMUͨѶ״̬
extern unsigned char BMU_Comm_Status2;//9-16  BMUͨѶ״̬
extern unsigned char BMU_Comm_Status3;//17-24 BMUͨѶ״̬
extern unsigned char BMU_Comm_Status4; //25-32 BMUͨѶ״̬

extern unsigned char BMU_Bala_Status1; //1-8   BMU����״̬
extern unsigned char BMU_Bala_Status2; //9-16  BMU����״̬
extern unsigned char BMU_Bala_Status3; //17-24 BMU����״̬
extern unsigned char BMU_Bala_Status4; //25-32 BMU����״̬

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
//extern unsigned int  Battery_Voltage[12]; //��ص����ѹ
extern unsigned int  Battery_Temp[12]; //��ص����¶�

/**********����Э�����************/
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

#define  Kt               CAN_KEY[2].bit2  

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


typedef union {
 struct {
 unsigned int  boxid;//�����
 unsigned int  vol;   //��ص�ѹ
 };
 unsigned char byte[4];
}DC_DATA; 

typedef union {
 struct {
  unsigned char  ID;//�����
  unsigned char  TEMP;   //��ص�ѹ
 };
 unsigned char byte[2];
}DC_TEMP;


/******************************************************************/
 #define  BAT_NUM      96  //�����ظ���
 #define  CAN_BAT_NUM  24   //�����ص�ѹCAN��������֡����
 #define  BAT_BOX_NUM  10               //һ֡�����ĸ������ѹ�������ĸ����ĸ�����      

//�������������� 
extern unsigned int  DJcontroler_voltage;//��������������ѹ
extern unsigned int  DJcontroler_current; //����������������
extern unsigned int  DJ_speed;
extern unsigned char DJ_temperature;             //��������¶�
extern unsigned char DJcontroler_temperature;    //��������������¶�

extern unsigned char DJ_temperature1;         //����¶�
extern unsigned char DJcontroler_temperature1;//����������¶�
extern unsigned char VCU_Status[10];     //VCU״̬
extern unsigned char Gear;               //��λ
extern unsigned int  XHLC;               //�������
extern unsigned char DJ_version;         //MCU ����汾��Ϣ
extern unsigned char DJ_Status[10];      //�������ϵͳ״̬
extern unsigned char DJ_fault;           //MCU ϵͳ���ϴ���
extern unsigned int  DJ_Power;           //���ʵʱ�����

extern unsigned int  DJtorque;            //������Ŀ��ת��
extern unsigned char system_state;        //ϵͳ����״̬
extern unsigned int  system_fault;        //ϵͳ������
extern unsigned char fault_grade;        //���ϵȼ�
extern unsigned long version;            //����汾�Ÿ� 3�ֽ�
extern unsigned char controler_LIFE; //����������Life
  
extern unsigned char KZQversion[7];
extern unsigned char DJversion[7]; 

extern unsigned char PDX_state[2]; 
extern unsigned char DCDC1_temp;
extern unsigned char DCDC1_fault;
extern unsigned char DCDC2_temp;
extern unsigned char DCDC2_fault;
extern unsigned char DCDC3_temp;
extern unsigned char DCDC3_fault;

extern unsigned char KEY_state[4];  //������״̬  //��λ
extern unsigned int  traction_st[2];   //����̤��ٷֱ�
extern unsigned char brake_st[2];      //�ƶ�̤��ٷֱ�

extern unsigned int  anode_R;     //���˶Եؾ�Ե����
extern unsigned int  negative_R;  //���˶Եؾ�Ե����
extern unsigned char eror_R;      //��Ե���ϵȼ�
extern unsigned char R_state[3];  //

extern unsigned char SX_state;
extern unsigned char SX_fault;

extern unsigned int  SX_DCvoltage;
extern unsigned int  SX_DRvoltage;
extern unsigned int  SX_DCcurrent;
extern unsigned int  SX_DRcurrent;

extern unsigned char KT_Status[2];
extern unsigned char KT_temp[3];
extern unsigned long KT_current;
extern unsigned char KT_life;

extern unsigned int  CDJ_SRvoltage;
extern unsigned int  CDJ_SRcurrent;
extern unsigned int  CDJ_SCvoltage;
extern unsigned int  CDJ_SCcurrent;

extern unsigned int  CDJ_power;
extern unsigned char CDJ_temp;
extern unsigned char CDJ_Status;
extern unsigned char CDJ_fault;
extern unsigned char CDJ_grade;
extern unsigned char CDJ_lift;

//��ص�ع�����ر��� 
extern unsigned int  DC_voltage; //��ص�ѹ 
extern unsigned int  DC_current; //��ص��� 
extern unsigned char DC_SOC;
extern unsigned char DC_Status[5];

extern unsigned int  CD_current; //��ǰ������������
extern unsigned int  FD_current; //��ǰ�������ŵ����
extern unsigned char DC_fault;  //ϵͳ���ϵȼ�
extern unsigned int  Vaverage; //
extern unsigned char Tmax;     //��������¶�
extern unsigned char Tmin;     //��С�������¶�


extern unsigned char JY_life;
extern unsigned char JY_Status;
extern unsigned int  DCanode_R;     //���˶Եؾ�Ե����
extern unsigned int  DCnegative_R;  //���˶Եؾ�Ե����
extern unsigned int  Vmax;     //������ѹ
extern unsigned int  Vmin;     //��С�����ѹ
 
extern unsigned char BMU_NUM;   //����ģ������
extern unsigned int  Battery_Voltage[10][50]; //��ص����ѹ
extern unsigned int  Battery_Voltage_Sum[10]; //��ص����ѹÿ������
extern unsigned int  Battery_Temp_Sum[10];    //��ص����¶�ÿ������
extern unsigned char DC_Temp[10][10];
extern unsigned char DC_JH_Status[10][4];//��ؾ���״̬ ģ����  1-12 ��
extern unsigned char DC_JY[10];//��Ե����
extern unsigned char DC_DT_sum;//�����ظ���( ����) 
extern unsigned char DC_TEMP_sum;//�����¶ȸ���
extern unsigned char Vmax_num[2];//��ߵ����ѹ���λ��   Vmax_num[1]//��ߵ����ѹ���λ�ã������ر��
extern unsigned char Vmin_num[2];//��͵����ѹ���λ��   Vmin_num[1]//��͵����ѹ���λ�ã������ر��     
extern unsigned char Tmax_num[2];//��ߵ����¶�λ��       Tmax_num[1]//��ߵ����¶�λ�ã������¶ȱ��
extern unsigned char Tmin_num[2];//��͵����¶�λ��       Tmin_num[1]//��͵����¶�λ�ã������¶ȱ��

extern unsigned char Vmax_box;//��ߵ����ѹ���λ�ã��������
extern unsigned char Vmin_box;//��͵����ѹ���λ�ã��������
extern unsigned char Tmax_box;//��ߵ����¶�λ�ã��¶������       
extern unsigned char Tmin_box;//��͵����¶�λ�ã��¶������ 


//����ת��DC/A
extern unsigned int  YB_Wcurrent;
extern unsigned int  YB_Vcurrent;
extern unsigned int  YB_Ucurrent; 
extern unsigned char YB_temp;   //�ͱ�ɢ���¶�
extern unsigned char YB_fault;  //�ͱù�����

//��ͳ�յ�
extern unsigned char KT_fault;
extern unsigned char KT_Status[2];
extern unsigned char KT_temp1;
extern unsigned char KT_temp2;
extern unsigned char KT_temp3;
extern unsigned char KT_comd;
extern unsigned char KT_life;
extern unsigned int BUZZ_COUNT;

extern DC_DATA  voltage_bat[10];    //�����ص�ѹ
//BMS1ֻ���͵�ѹƫ������10�����壬����5��������5��

extern DC_TEMP  temp_bat[10];//�������¶�
//?BMS1ֻ�����¶�ƫ������10�����塣
extern unsigned int Vspeed;

//�ͱÿ�����
extern unsigned int  YB_voltage;
extern unsigned int  YB_current;  
extern unsigned char YB_temp;   //�ͱ�ɢ���¶�
extern unsigned char YB_fault;  //�ͱù�����
//ת�������ã�DC/AC�� ��ѹ�� ���ã�DC/AC����Դ
extern unsigned int  DCAC_speed[2];//�������ת��
extern unsigned int  DCAC_current[2];//��������
extern unsigned char DCAC_temp[2];//�������¶�
extern unsigned char DCAC_life[2];//�����������ź�
extern unsigned char DCAC_Status[2];
extern unsigned char DCAC_fault[2];

extern unsigned int  DCDC_voltage;
extern unsigned int  DCDC_current;
extern unsigned char DCDC_fault;
//���ÿ�����
extern unsigned int  QB_voltage_IN; 
extern unsigned int  QB_voltage_OUT;
extern unsigned int  QB_current;    
extern unsigned char QB_temp;        
extern unsigned char QB_fault;      
//�����
extern unsigned char MHQ_Number;
extern unsigned char MHQ_Alarm;
extern unsigned char MHQ_life;
extern unsigned char MHQ_fault;


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

#endif	/* SYSTEM_H */

