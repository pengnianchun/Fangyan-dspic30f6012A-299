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

#define WORD_WRITE(dest,data)	do{(dest)[0] = (data)&0xFF;((dest)[1]=(data)>>8)&0xFF;}while(0)
#define DWORD_WRITE(dest,data)	do{(dest)[0] = (data)&0xFF;((dest)[1]=(data)>>8)&0xFF;((dest)[2]=(data)>>16)&0xFF;((dest)[3]=(data)>>24)&0xFF;}while(0)

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
        unsigned char bit1 : 1;
        unsigned char bit2 : 1;
        unsigned char bit3 : 1;
        unsigned char bit4 : 1;
        unsigned char bit5 : 1;
        unsigned char bit6 : 1;
        unsigned char bit7 : 1;
        unsigned char bit8 : 1;
    };
    unsigned char byte;
} DATA_BIT;

/*****************�ְ�����CAN*****************/

typedef union {

    struct {
        unsigned long SPN1 : 19;
        unsigned long FMI : 5;
        unsigned long CM : 1;
        unsigned long OC : 7;
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

void DM(unsigned char x, DM1 id);
/*******************�ְ�����*****************/
#pragma pack(1)

typedef union {

    struct {
        unsigned MotoVoltage; //��������ѹ
        unsigned MotoCurrent; //����������
        unsigned MotoSpeed; //���ת��
        unsigned char MotorTemperature; //����¶�
        unsigned char MotorTemperature_Controller; //����¶�
    };
    unsigned char byte[8];
} _CAN_0x0C03A1A7;

typedef union {

    struct {
        unsigned long VCUVerison : 24; //��������������汾��
        unsigned long FaultCode1 : 8; //���ϴ���1       
        unsigned char FaultLevel; //���ϵȼ�
        unsigned char VCUMode; //����ģʽ
        unsigned char FaultCode2; //���ϴ���2
        unsigned char VCULife; //����������Life
    };
    unsigned char byte[8];
} _CAN_0x0C04A1A7;

typedef union {

    struct {
        unsigned char Reserve;
        unsigned char : 3;
        unsigned char E_Brake : 1;
        unsigned char READY : 1;
        unsigned char : 3;
        unsigned char DCDCTemp;
        unsigned char DCDCFaultCode0 : 1;
        unsigned char DCDCFaultCode1 : 1;
        unsigned char DCDCFaultCode2 : 1;
        unsigned char DCDCFaultCode3 : 1;
        unsigned char DCDCFaultCode4 : 1;
        unsigned char DCDCFaultCode5 : 1;
        unsigned char DCDCFaultCode6 : 1;
        unsigned char DCDCFaultCode7 : 1;
        unsigned char DCAC1Temp;
        unsigned char DCAC1FaultCode0 : 1;
        unsigned char DCAC1FaultCode1 : 1;
        unsigned char DCAC1FaultCode2 : 1;
        unsigned char DCAC1FaultCode3 : 1;
        unsigned char DCAC1FaultCode4 : 1;
        unsigned char DCAC1FaultCode5 : 1;
        unsigned char DCAC1FaultCode6 : 1;
        unsigned char DCAC1FaultCode7 : 1;
        unsigned char DCAC2Temp;
        unsigned char DCAC2FaultCode0 : 1;
        unsigned char DCAC2FaultCode1 : 1;
        unsigned char DCAC2FaultCode2 : 1;
        unsigned char DCAC2FaultCode3 : 1;
        unsigned char DCAC2FaultCode4 : 1;
        unsigned char DCAC2FaultCode5 : 1;
        unsigned char DCAC2FaultCode6 : 1;
        unsigned char DCAC2FaultCode7 : 1;
    };
    unsigned char byte[8];
} _CAN_0x0C05A1A7;

typedef union {

    struct {
        unsigned char VCUAcc : 1;
        unsigned char VCUOn : 1;
        unsigned char VCUGearD : 1;
        unsigned char VCUGearR : 1;
        unsigned char VCUGearN : 1;
        unsigned char VCUDiagnosis : 1;
        unsigned char VCUAirPumpTempWarn : 1;
        unsigned char VCUOilPumpTempWarn : 1;

        unsigned char VCUGearS : 1;
        unsigned char Reserve1 : 1;
        unsigned char Reserve2 : 1;
        unsigned char VCUHandBrake : 1;
        unsigned char Reserve3 : 1;
        unsigned char Reserve4 : 1;
        unsigned char VCUPressLowWarn : 1;
        unsigned char Reserve5 : 1;

        unsigned char Reserve6;
        unsigned char VCUOverSpeed;
        unsigned char AcceleratePedal1;
        unsigned char AcceleratePedal2;
        unsigned char BrakePedal1;
        unsigned char BrakePedal2;
    };
    unsigned char byte[8];
} _CAN_0x0C06A1A7;

typedef union {

    struct {
        unsigned char MotoStatus;
        unsigned MotoTorque;
        unsigned MotoSpeed; //���ת��
        unsigned char Reserve1;
        unsigned char Reserve2;
        unsigned char Reserve3;
    };
    unsigned char byte[8];
} _CAN_0x0C08A1A7;

typedef union {

    struct {
        unsigned BMS_V; //��ص�ѹ
        unsigned BMS_A; //��ص���
        unsigned char BMS_SOC; //���SOC
        DATA_BIT BMSFlag1; //���״̬1
        DATA_BIT BMSFlag2; //���״̬2
        DATA_BIT BMSFlag3; //���״̬3
    };
    unsigned char byte[8];
} _CAN_0x1818D0F3;

typedef union {

    struct {
        unsigned BMS_A_charge; //��������
        unsigned BMS_A_discharge; //���ŵ����
        unsigned char Warn_level; //���ϵȼ�
        unsigned BMS_V_average; //���ƽ����ѹ
        unsigned char BMS_T_H; //�������¶�
    };
    unsigned char byte[8];
} _CAN_0x1819D0F3;

typedef union {

    struct {
        unsigned Oum_zheng; //��Ե����ֵ
        unsigned Oum_fu; //��Ե����ֵ
        unsigned Battery_single_H; //��ص���ߵ�ѹ
        unsigned Battery_single_L; //��ص���͵�ѹ
    };
    unsigned char byte[8];
} _CAN_0x181AD0F3;

typedef union {

    struct {
        unsigned char BAT_Min_Cell_Voltage_Cell_Case : 4; //��͵����ѹ���
        unsigned char BAT_Max_Cell_Voltage_Cell_Case : 4; //��ߵ����ѹ���
        unsigned char BAT_Min_Cell_Temp_Cell_Number : 5; //��͵����¶�λ��
        unsigned char BAT_Min_Cell_Temp_Cell_Case : 3; //��͵����¶���� 
        unsigned char BAT_Max_Cell_Temp_Cell_Number : 5; //��ߵ����¶�λ��
        unsigned char BAT_Max_Cell_Temp_Cell_Case : 3; //��ߵ����¶���� 
        unsigned char BAT_Min_Cell_Voltage_Cell_Number; //��͵����ѹλ��
        unsigned char BAT_Max_Cell_Voltage_Cell_Number; //��ߵ����ѹλ��
        unsigned BATRestEnerge; //���ʣ������
        unsigned char BAT_Min_Cell_Temperature; //��͵����¶�
    };
    unsigned char byte[8];
} _CAN_0x181BD0F3;

typedef union {

    struct {
        DATA_BIT BMSFlag4;
        unsigned char ChargeSocketTemp1;
        unsigned char ChargeSocketTemp2;
        unsigned char Reserve1;
        unsigned char Reserve2;
        unsigned char Reserve3;
        unsigned char Reserve4;
        unsigned char Reserve5;
    };
    unsigned char byte[8];
} _CAN_0x181CD0F3;

typedef union {

    struct {
        DATA_BIT KT_Status;
        unsigned char Reserve1;
        unsigned char Reserve2;
        unsigned char Reserve3;
        unsigned char Reserve4;
        unsigned char Reserve5;
        unsigned char Reserve6;
        unsigned char Reserve7;
    };
    unsigned char byte[8];
} _CAN_0x1830A7F3;

typedef union {

    struct {
        unsigned char AirWorkMode1_Xiaodu : 2;
        unsigned char AirWorkMode1_Xinfeng : 2;
        unsigned char AirWorkMode1_Zhire : 2;
        unsigned char AirWorkMode1_Zhileng : 2;

        unsigned char AirWorkMode2_Tongfeng : 2;
        unsigned char AirWorkMode2_Chushi : 2;
        unsigned char AirWorkMode2_Zidong : 2;
        unsigned char Reserve1 : 2;

        unsigned char Reserve2;
        unsigned char Reserve3;
        unsigned char Reserve4;
        unsigned char Reserve5;
        unsigned char Reserve6;
    };
    unsigned char byte[8];
} _CAN_0x18FFC119;

typedef union {

    struct {
        unsigned DCDC_Input_Voltage; //DCDC�����ѹ
        unsigned char DCDC_Output_Voltage; //DCDC�����ѹ
        unsigned DCDC_Output_Current; //DCDC�������
        unsigned char DCDC_Temp; //DCDCģ���¶�
        DATA_BIT DCDC_FaultCode; //DCDC���ϴ���
        unsigned char Reserve;
    };
    unsigned char byte[8];
} _CAN_0x1801A79A;

typedef union {

    struct {
        unsigned AIRDCAC_InputVoltage; //DCAC�����ѹ
        unsigned AIRDCAC_Voltage; //DCAC�����ѹ
        unsigned AIRDCAC_Current; //DCAC�������
        unsigned char AIRDCAC_Temp; //DCAC����¶�
        DATA_BIT AIRDCAC_FaultCode; //DCAC���ϴ���
    };
    unsigned char byte[8];
} _CAN_0x1801A79D;

typedef union {

    struct {
        unsigned OILDCAC_InputVoltage; //DCAC�����ѹ
        unsigned OILDCAC_Voltage; //DCAC�����ѹ
        unsigned OILDCAC_Current; //DCAC�������
        unsigned char OILDCAC_Temp; //DCAC����¶�
        DATA_BIT OILDCAC_FaultCode; //DCAC���ϴ���
    };
    unsigned char byte[8];
} _CAN_0x1801A79B;
#pragma pack()
extern _CAN_0x0C03A1A7 CAN_0x0C03A1A7;
extern _CAN_0x0C04A1A7 CAN_0x0C04A1A7;
extern _CAN_0x0C05A1A7 CAN_0x0C05A1A7;
extern _CAN_0x0C06A1A7 CAN_0x0C06A1A7;
extern _CAN_0x0C08A1A7 CAN_0x0C08A1A7;
extern _CAN_0x1818D0F3 CAN_0x1818D0F3;
extern _CAN_0x1819D0F3 CAN_0x1819D0F3;
extern unsigned int BAT_Cell_Voltage[5][40]; //��ص����ѹ
extern unsigned char BAT_Cell_Temp[5][8]; //��ص����¶�
extern _CAN_0x181AD0F3 CAN_0x181AD0F3;
extern _CAN_0x181BD0F3 CAN_0x181BD0F3;
extern _CAN_0x181CD0F3 CAN_0x181CD0F3;
extern _CAN_0x1830A7F3 CAN_0x1830A7F3;
extern _CAN_0x18FFC119 CAN_0x18FFC119;
extern _CAN_0x1801A79A CAN_0x1801A79A;
extern _CAN_0x1801A79D CAN_0x1801A79D;
extern _CAN_0x1801A79B CAN_0x1801A79B;

void CAN_DATA_Init(void);




#if MODE_FV
extern unsigned char Accelerator; //����̤��

extern unsigned char Speed_lim_mode;//����ģʽ

extern unsigned char water_temp;//ˮ��

extern unsigned int  Engine_oil_press;//����ѹ��
extern unsigned char water_level;//ˮλ

extern unsigned char Wait_start;//�ȴ�����
extern unsigned char Maintain_warn;//ά������
extern unsigned char Stop_warn;//ͣ������
extern unsigned char Engine_warn;//����������

extern unsigned int EngineSpeed;//������ת��

extern unsigned char barometric_pressure; //��ѹѹ�� 0.5Kpa
extern unsigned char ambient_air_temperature; //��Χ�����¶�
extern unsigned char air_pressure; //����ѹ�� 0.5Kpa

extern unsigned int  fuel_rate;   //Сʱȼ��������
extern unsigned int  instantaneous_fuel; //˲̬ȼ�;�����

extern unsigned int  speed_st; //����̤��
#endif

#endif	/* APP_CAN2_RECEIVE_H */

