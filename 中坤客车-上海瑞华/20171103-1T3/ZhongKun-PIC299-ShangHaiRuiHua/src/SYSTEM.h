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
#define  TIME          20171103L
//�Ƿ����Ƶ�ź� 0������Ƶ 1����Ƶ
#define  VIDEO         1
//����Ƶ�ĸ���  
#define  VIDEO_NUMBER  2
//��ָ��
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
extern unsigned int Tcan_count; //̥ѹCAN

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

#define  F300ms     gKEY[3].bit1 // 2016/10/22��������ʱ��
#define  F400ms     gKEY[3].bit2
#define  F1000ms    gKEY[3].bit3
#define  FLASH_3s   gKEY[3].bit4
#define  time_flag  gKEY[3].bit5
#define  M_ON_flag  gKEY[3].bit6
#define  rLED_flag  gKEY[3].bit7

#define  CLR_single_miles gKEY[1].bit7
#define  save_flag        gKEY[1].bit8
#define  key_long_set     gKEY[2].bit1
#define  M_ON             gKEY[2].bit2  
#define  kFLASH           gKEY[2].bit3
#define  FLASH            gKEY[2].bit4 //ת�����˸��־
#define  FLASH_1s         gKEY[2].bit5 

#define  DM1_CLEAR        gKEY[2].bit6 
#define  R_flag           gKEY[2].bit7
#define  bLCD_RESET       gKEY[2].bit8



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
extern unsigned int fpcur[15]; //ǰģ�鹦���������
extern unsigned int mpcur[15]; //��ģ�鹦���������
extern unsigned int rpcur[15]; //��ģ�鹦���������

extern unsigned int ADR[8]; //ģ�����ɼ�   2016/10/15
extern unsigned int ADV[8]; //�Ǳ�ģ���źŲɼ�ֵ 
//extern const unsigned char BMP_LOGO[];
//extern const unsigned char BMP_LOGObmp[];

/**********����Э�����************/

extern unsigned int VCU_TM_NM; //TMĿ��Ť��
extern unsigned int VCU_TM_RPM; //TMĿ��ת��

extern unsigned char VCU_TM_Brake_percent; //�ƶ�̤�忪��
extern unsigned char VCU_TM_Speed_percent; //����̤�忪��
extern DATA_BIT VCU_Status_Flag1; //״̬1
#define  CHARGE      VCU_Status_Flag1.bit1
#define  DCDC_EN     VCU_Status_Flag1.bit2
#define  BMS_OFFLINE VCU_Status_Flag1.bit3
#define  TM_OFFLINE  VCU_Status_Flag1.bit4
#define  DCAC_EN     VCU_Status_Flag1.bit5
#define  SPEED_EN    VCU_Status_Flag1.bit6
#define  BRAJE_EN    VCU_Status_Flag1.bit7
#define  ELE_BRAKE   VCU_Status_Flag1.bit8

extern unsigned char VCU_Gear; //��λ

extern DATA_BIT VCU_Mode; //����ģʽ

extern unsigned char VCU_Life; //����������LIFE

extern DATA_BIT VCU_Status_Flag2;
#define  READY       VCU_Status_Flag2.bit6
#define  CHARGE_OVERTIME VCU_Status_Flag2.bit7  
#define  VCU_FAULT   VCU_Status_Flag2.bit8 

extern unsigned char VCU_Code; //����������

// VCU2TERMINAL_MOTOR01
extern unsigned char TM_Number; //�������
extern unsigned char TM_Serial; //������
extern unsigned char TM_WorkStatus; //TM�������״̬
extern unsigned char TM_Control_Temp; //TM����������¶�
extern unsigned int TM_Feedback_RPM; //TM�������ת��
extern unsigned int TM_Feedback_NM; //TM�������Ť��
// VCU2TERMINAL_MOTOR02
extern unsigned char TM_Temp; //TM����¶�
extern unsigned int TM_Voltage_DC; //TM���ֱ����ѹ
extern unsigned int TM_Current_DC; //TM���ֱ������

/*extern unsigned int  TM_Feedback_RPM;//TM�������ת��
extern unsigned int  TM_Feedback_NM;//TM�������Ť��
extern unsigned int  TM_Current_AC;//TM�����������
extern unsigned char TM_StatusFeedback;//TM���״̬����
extern unsigned char TM_WorkStatus;//TM�������״̬
extern unsigned char TM_LIFE;//TM���LIFE

extern unsigned char TM_Temp;//TM����¶�
extern unsigned char TM_Control_Temp;//TM����������¶�
extern unsigned int  TM_Torque_Limit_Up;//���Ť������
extern unsigned int  TM_Torque_Limit_Down;//���Ť������
extern DATA_BIT      TM_Fault;//TM������ϵȼ�
extern unsigned char TM_Status;//TM���״̬
extern DATA_BIT      TM_Status_Flag1;//���״̬1
#define  TM_COT_OVERT TM_Status_Flag1.bit1
#define  TM_OVERT    TM_Status_Flag1.bit2

extern unsigned int  TM_Code;//TM���������
extern unsigned int  TM_Current_DC;//TM���ֱ������
extern unsigned int  TM_Voltage_DC;//TM���ֱ����ѹ
 */
//IRM
extern unsigned long IRM_Ohm_Positive; //������Ե��ֵ 
extern unsigned long IRM_Ohm_Negative; //�ܸ���Ե��ֵ 
extern unsigned char IRM_Fault_Level; //�豸���ϵȼ�
extern unsigned char IRM_Insulation_Level; //��Ե�ȼ�
extern unsigned char IRM_Life; //��ԵLIFE

/*extern unsigned char VCU_Kt; //���Ӵ�����������
extern unsigned char VCU_ON; //Կ���µ�״̬
extern unsigned char VCU_Order; //���ϴ�������
extern unsigned int  VCU_Voltage; //�����������ѹ
 */


extern unsigned char BMS_Mode; //��س�ŵ�ģʽ
extern unsigned char BMS_Status; //���״̬
extern unsigned char BAT_Temp_Average; //���ƽ���¶�
extern unsigned char BMS_SOC; //SOC
extern unsigned int BMS_Current; //���ϵͳ����
extern unsigned int BMS_Voltage; //���ϵͳ���ܵ�ѹ
extern unsigned char BMS_Kt; //��ѹ�̵���״̬

extern unsigned char BAT_Temp_H_Limit; //��������ص����¶�
extern unsigned char BAT_Temp_L_Limit; //��������ص����¶�
extern unsigned char BMS_SOC_L_Limit; //�������SOCֵ
extern unsigned int BAT_Current_Discharge_Limit; //�������ŵ����
extern unsigned int BAT_Current_Charge_Limit; //������������

extern unsigned char BAT_Temp_L; //��ص�������¶�
extern unsigned char BAT_Temp_L_Number; //��ص�����¶����
extern unsigned char BAT_Temp_L_Case; //��ص�����¶����
extern unsigned char BAT_Temp_H; //��ص�������¶�
extern unsigned char BAT_Temp_H_Number; //��ص�����¶����
extern unsigned char BAT_Temp_H_Case; //��ص�����¶����

extern unsigned char BAT_Voltage_Fault; //��ѹ����
extern unsigned char BAT_Single_Fault; //��ѹ����
extern unsigned char BAT_Temp_Fault; //�¶ȹ���
extern unsigned char BAT_Insulation_Fault; //��Ե����
extern unsigned char BAT_Consistency_Fault; //���һ���Թ���
extern unsigned char BAT_SOC_Fault; //SOC����
extern unsigned char BAT_Current_Fault; //��������
extern unsigned char BAT_Lock_Fault; //��ѹ��������
extern unsigned char BMS_Comm_Fault; //BMSͨѶ����
extern unsigned char BMS_System_Fault; //BMSϵͳ����

extern unsigned int BMS_Ohm; //��Ե��ֵ 
extern unsigned char BMS_Number; //�����ѹ����
extern unsigned char BMS_Temp_Number; //�����¶�����
extern unsigned char BMS_System_Unit; //ϵͳ����
extern unsigned char BMS_System_Number; //ϵͳ��

extern unsigned int BAT_Single_L; //��ص���͵�ѹ
extern unsigned char BAT_Single_L_Number; //��ص���͵�ѹλ��
extern unsigned char BAT_Single_L_Case; //��ص���͵�ѹ���

extern unsigned int BAT_Single_H; //��ص���ߵ�ѹ
extern unsigned char BAT_Single_H_Number; //��ص���ߵ�ѹλ��
extern unsigned char BAT_Single_H_Case; //��ص���ߵ�ѹ���
/*
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
 */
extern unsigned int BAT_Cell_Voltage[400];
extern unsigned char BAT_Cell_Temperature[128];

extern unsigned int DCDC_Voltage; //DCDC�����ѹ
extern unsigned int DCDC_Current; //DCDC�������
extern unsigned char DCDC_Status; //DCDC����״̬
extern unsigned char DCDC_Output_Cut; //DCDC ����ж�
extern unsigned char DCDC_intput_Cut; //DCDC �����ж�
extern unsigned char DCDC_Fault_Code; //DCDC������
extern unsigned char DCDC_Level_Fault; //DCDC���ϵȼ�
extern unsigned char DCDC_Temp_Warn; //DCDC�¶ȱ���
extern unsigned char DCDC_Fault_Warn; //DCDC���ϱ���
extern unsigned char DCDC_Temp; //DCDCģ���¶�

extern unsigned int OILDCAC_U_Voltage; //DCAC���U��ѹ
extern unsigned int OILDCAC_U_Current; //DCAC���U����
extern unsigned char OILDCAC_Status; //DCAC����״̬
extern unsigned char OILDCAC_Output_Cut; //DCAC ����ж�
extern unsigned char OILDCAC_intput_Cut; //DCAC �����ж�
extern unsigned char OILDCAC_Fault_Code; //DCAC���ϴ���
extern unsigned char OILDCAC_Level_Fault; //DCAC���ϵȼ�
extern unsigned char OILDCAC_Temp_Warn; //DCDC�¶ȱ���
extern unsigned char OILDCAC_Fault_Warn; //DCDC���ϱ���
extern unsigned char OILDCAC_Temp; //DCACģ���¶�

extern unsigned int OILDCAC_V_Voltage; //DCAC���V��ѹ
extern unsigned int OILDCAC_V_Current; //DCAC���V����
extern unsigned int OILDCAC_W_Voltage; //DCAC���W��ѹ
extern unsigned int OILDCAC_W_Current; //DCAC���W����

extern unsigned int AIRDCAC_U_Voltage; //DCAC���U��ѹ
extern unsigned int AIRDCAC_U_Current; //DCAC���U����
extern unsigned char AIRDCAC_Status; //DCAC����״̬
extern unsigned char AIRDCAC_Output_Cut; //DCAC ����ж�
extern unsigned char AIRDCAC_intput_Cut; //DCAC �����ж�
extern unsigned char AIRDCAC_Fault_Code; //DCAC���ϴ���
extern unsigned char AIRDCAC_Level_Fault; //DCAC���ϵȼ�
extern unsigned char AIRDCAC_Temp_Warn; //DCDC�¶ȱ���
extern unsigned char AIRDCAC_Fault_Warn; //DCDC���ϱ���
extern unsigned char AIRDCAC_Temp; //DCACģ���¶�

extern unsigned int AIRDCAC_V_Voltage; //DCAC���V��ѹ
extern unsigned int AIRDCAC_V_Current; //DCAC���V����
extern unsigned int AIRDCAC_W_Voltage; //DCAC���W��ѹ
extern unsigned int AIRDCAC_W_Current; //DCAC���W����

extern DATA_DOUBLE ICS01_Status1; //��ѹ�ɼ�״̬1
extern DATA_DOUBLE ICS01_Status2; //��ѹ�ɼ�״̬2
extern DATA_DOUBLE ICS01_Status3; //��ѹ�ɼ�״̬3
extern DATA_DOUBLE ICS01_Status4; //��ѹ�ɼ�״̬4

extern unsigned int ICS01_Voltage_Front; //ǰ�˵�ѹ
extern unsigned int ICS01_Voltage_Rear; //��˵�ѹ
extern unsigned char ICS01_LIFE; //LIFE

//extern unsigned char TireLocation_LR;                 //��̥λ�ã����ң�
//extern unsigned char TireLocation_FB;                 //��̥λ�ã�ǰ��
extern unsigned char TireLocation[4][6];                    //��̥λ��
extern unsigned char TirePressure[4][6];                    //̥ѹ
extern unsigned int  TireTemperature[4][6];                 //̥��
extern DATA_DOUBLE   TireFault[4][6];                       //��̥����
extern unsigned int  TireAirLeakageRate[4][6];              //��ѹ��������
extern unsigned char TirePressureThresholdDetection[4][6];  //��ѹ��ʾ����


/**********************************************/

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
extern CAN_CACHE m_can; //HCU����
extern CAN_CACHE n_can; //TCU����
extern CAN_CACHE c_can; //CCU����
extern CAN_CACHE b_can; //BMS����

extern unsigned long SPN; //�ӻ�������ȡ�Ĺ�����
extern unsigned char FMI;
/******************************************************************/


void System_Init(void);
void SYSTME_Logic(void);
void LED_Logic(void);

void BCAN_SendCtl(void);
void PCAN_CCVS(void);
void Count_ADR(void);
void PCAN_send_req(void);
void PCAN_send_mile(void);
void PCAN_Taiya(void);
/*void DM_HCU(unsigned char x);
void DM_TCU(unsigned char x);
void DM_CCU(unsigned char x);
void DM_ECU(unsigned char x);
void DM_BCU(unsigned char x);*/
void DM(unsigned char x, DM1 id);
//dispaly
void LCD_Exec(void);
void TIM5_Init(void);
//void TIMER4_Init(void);
/******************************/
/********************************************/

#endif	/* SYSTEM_H */

