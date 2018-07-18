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

/*extern DM1 CAN_18FECAEF;
extern unsigned char CAN_18FECAEF_len;
extern DM1 CAN_18FECA03;
extern unsigned char CAN_18FECA03_len;
extern DM1 CAN_18FECAF5;
extern unsigned char CAN_18FECAF5_len;
extern DM1 CAN_18FECA00;
extern unsigned char CAN_18FECA00_len;
extern DM1 CAN_18FECAF3;
extern unsigned char CAN_18FECAF3_len;*/

typedef struct {
    unsigned char pack; //CAN�ּ������ݴ���
    unsigned char flag; //CAN�����������
    unsigned char len; //CAN���泤��
    unsigned char buf[50]; //CAN��������
} CAN_CACHE;
/*extern CAN_CACHE m_can; //HCU����
extern CAN_CACHE n_can; //TCU����
extern CAN_CACHE c_can; //CCU����
extern CAN_CACHE b_can; //BMS����*/

extern unsigned long SPN; //�ӻ�������ȡ�Ĺ�����
extern unsigned char FMI;

void DM(unsigned char x, DM1 id);
/*******************�ְ�����*****************/
#pragma pack(1)

#if 0
typedef union {

	 struct {
		unsigned char HeartBeatSignal : 4;//��������
        unsigned char Reserve1 : 4;//����
        unsigned char BMSPowerCommand;//BMS�ϵ�����
        unsigned char Reserve2;//����
        unsigned char Reserve3;//����
        unsigned char Reserve4;//����
        unsigned char Reserve5;//����
	    unsigned char Reserve6;//����
	 };
	 unsigned char byte[8];
}_CAN_0x0CFF1501;

typedef union {

	 struct {
		unsigned char BMS_ChargingModel : 3;//��س�ŵ�ģʽ
        unsigned char Reserve : 3;//����
        unsigned char BMS_BasicStatus : 2;//BMS����״̬λ
        unsigned char BMS_Average_Temp;//�����ƽ���¶�
        unsigned char BMS_SOC;//�����SOC
        unsigned BMS_Current ;//������ŵ����
        unsigned BMS_Voltage ;//������ܵ�ѹ
	    unsigned char Reserve1 : 4;//����
        unsigned char High_Voltage_RelayStatus : 4;//��ѹ�̵���״̬
	 };
	 unsigned char byte[8];
}_CAN_0x10F8159E;

typedef union {

	 struct {
		unsigned char BMS_AllowMAXTemp;//�������������¶�
        unsigned char BMS_AllowMINTemp;//�������������¶�
        unsigned char BMS_AllowMINSOC;//������������ʹ��SOC
        unsigned BMS_AllowMAXDischargeCurrent;//������������ŵ����
        unsigned BMS_AllowMAXRecycleCurrent;//��������������յ���
        unsigned char Reserve;//����
	 };
	 unsigned char byte[8];
}_CAN_0x10F8169E;

typedef union {

	 struct {
		unsigned char BMS_MIN_Temp;//�������¶�
        unsigned char BMS_MIN_Temp_CellNum;//���������¶ȵ�����
        unsigned char BMS_MIN_Temp_CaseNum;//���������¶�����������
        unsigned char BMS_MAX_Temp;//�������¶�
        unsigned char BMS_MAX_Temp_CellNum;//���������¶ȵ�����
        unsigned char BMS_MAX_Temp_CaseNum;//���������¶�����������
        unsigned char Reserve1;//����
	    unsigned char Reserve2;//����
	 };
	 unsigned char byte[8];
}_CAN_0x18F8179E;

typedef union {

	 struct {
		unsigned char TotalVoltageFaultStatus : 4;//��ѹ����״̬
        unsigned char CellVoltageFaultStatus : 4;//�����ѹ����״̬
        unsigned char TempFaultStatus : 6;//�¶ȹ���״̬
        unsigned char InsulationResisitanceFaultStatus : 2;//��Ե��ֵ����״̬
        unsigned char BMS_CellUniformityStatus : 2;//��ص���һ����״̬
        unsigned char SOCFaultStatus : 6;//SOC����״̬
        unsigned char CurrentFault : 4;//��������
	    unsigned char HVILStatus : 2;//��ѹ����״̬
        unsigned char BMSInsideFault : 2;//BMS�ڲ�����
        unsigned char StoredEnergySYSMismatchWarning : 1;//�ɳ�索��ϵͳ��ƥ�䱨��
        unsigned char Reserve1 : 7;//����
        unsigned char Reserve2;//����
        unsigned char Reserve3;//����
        unsigned char Reserve4;//����
	 };
	 unsigned char byte[8];
}_CAN_0x08F8189E;

typedef union {

	 struct {
		unsigned InsulationResistance;//��Ե��ֵ
        unsigned char StoredEnergyCellVoltageNUM;//�ɳ�索�ܵ����ѹ����
        unsigned char StoredEnergyCellTempNUM;//�ɳ�索�ܵ����¶�����
        unsigned char StoredEnergySYSNUM;//�ɳ�索����ϵͳ����
        unsigned char StoredEnergySYSNum;//�ɳ�索����ϵͳ��
        unsigned char Reserve1;//����
        unsigned char Reserve2;//����
	 };
	 unsigned char byte[8];
}_CAN_0x18F8199E;

typedef union {

	 struct {
		unsigned BMS_MIN_Cell_Voltage;//�����͵����ѹ
        unsigned char BMS_MIN_Cell_Voltage_Num;//�����͵����ѹ���
        unsigned char BMS_MIN_Cell_Voltage_CaseNum;//�����͵����ѹ���������
        unsigned BMS_MAX_Cell_Voltage;//�����ߵ����ѹ
        unsigned char BMS_MAX_Cell_Voltage_Num;//�����ߵ����ѹ���
        unsigned char BMS_MAX_Cell_Voltage_CaseNum;//�����ߵ����ѹ���������
	 };
	 unsigned char byte[8];
}_CAN_0x18F81A9E;

typedef union {

	 struct {
		unsigned char Gear : 2;//��λ
        unsigned char Reserve1 : 6;//����
        DATA_BIT Notice1;//��ʾ��Ϣ1
        DATA_BIT Notice2;//��ʾ��Ϣ2
        DATA_BIT Notice3;//��ʾ��Ϣ3
        unsigned VCU_FaultCode;//���ϴ���
        unsigned VCU_MotorSpeed;//���ת��
	 };
	 unsigned char byte[8];
}_CAN_0x08019F80;

typedef union {

	 struct {
		unsigned Voltage;//ĸ�ߵ�ѹ
        unsigned Current;//ĸ�ߵ���
        unsigned char MotorCtrlTemp;//����������¶�
        unsigned char DriveMotorTemp;//��������¶�
        unsigned char SOC;//SOC
        unsigned char Speed;//����
	 };
	 unsigned char byte[8];
}_CAN_0x08029F80;

typedef union {

	 struct {
		unsigned DriveMileage;//��ʻ���
        unsigned RunningPower;//���й���
        unsigned char VehicleLockingStatus;//��������״̬
        unsigned char AcceleratePedalAperture;//����̤�忪��
        unsigned char BrakePedalAperture;//�ƶ�̤�忪��
        unsigned char Reserve;//����
	 };
	 unsigned char byte[8];
}_CAN_0x08039F80;

typedef union {

	 struct {
		unsigned char VehicleStatus : 2;//����״̬
        unsigned char RunningModel : 3;//����ģʽ
        unsigned char DCDCStatus : 2;//DCDC״̬
        unsigned char Reserve1 : 1;//����
        unsigned char DriveMotorStatus : 3;//�������״̬
        unsigned char DriveMotorNum : 1;//����������
        unsigned char DriveMotorNUM : 1;//�����������
	    unsigned char Reserve2 : 3;//����
        unsigned char VCU_CtrlTemp;//�������¶�
        unsigned char VCU_DriveMotorTemp;//��������¶�
        unsigned VCU_DriveMotorRotateSpeed;//�������ת��
        unsigned VCU_DriveMotorTorque;//�������ת��
	 };
	 unsigned char byte[8];
}_CAN_0x08049F80;

typedef union {

	 struct {
		unsigned VCU_MotorCtrlInputVoltage;//��������������ѹ
        unsigned VCU_CtrlCurrent;//������ֱ��ĸ�ߵ���
        unsigned char DriveMotorFaultNUM;//���������������
        unsigned char DCDCTempWarning : 1;//DCDC�¶ȱ���
        unsigned char DCDCStatusWarning : 1;//DCDC״̬����
        unsigned char MotorCtrlTempWarning : 1;//����������¶ȱ���
        unsigned char DriveMotorTempWarning : 1;//��������¶ȱ���
        unsigned char Reserve1 : 4;//����
	    unsigned char Reserve2;//����
        unsigned char Reserve3;//����
	 };
	 unsigned char byte[8];
}_CAN_0x08059F80;

typedef union {

	 struct {
		unsigned DCDC_InputVoltage;//�����ѹ
        unsigned char DCDC_InputCurrent;//�������
        unsigned char DCDC_OutputCurrent;//�������
        unsigned char DCDC_CtrlTemp;//�������¶�
        unsigned char DCDC_OutputAssistLowVoltage;//���������ѹ
        unsigned char DCDC_Life;//DCDC_Life
        unsigned char DCDC_FaultCode : 4;//������
	    unsigned char DCDC_Status : 2;//DCDC״̬
        unsigned char Reserve : 1;//����
        unsigned char DCDC_CtrlPrechargeStatus : 1;//������Ԥ��״̬
	 };
	 unsigned char byte[8];
}_CAN_0x142CFF98;

typedef union {

	 struct {
		unsigned DCAC_MotorRotateSpeed;//���ת��
        unsigned DCAC_CtrlVoltage;//������ĸ�ߵ�ѹ
        unsigned char DCAC_CtrlCurrent;//����������
        unsigned char DCAC_CtrlTemp;//�������¶�
        unsigned char DCAC_Life;//DCAC_Life
        unsigned char DCAC_FaultCode : 4;//������
        unsigned char DCAC_PumpStatus : 2;//����״̬
	    unsigned char Reserve : 1;//����
        unsigned char DCAC_CtrlPrechargeStatus : 1;//������Ԥ��״̬
	 };
	 unsigned char byte[8];
}_CAN_0x1429FF9B;

typedef union {

	 struct {
		unsigned char VCU_CtrlWorkCommand;//���ƹ�������
        unsigned char Reserve1;//����
        unsigned char Reserve2;//����
        unsigned char Reserve3;//����
        unsigned char Reserve4;//����
        unsigned char Reserve5;//����
        unsigned char Reserve6;//����
	    unsigned char Reserve7;//����
	 };
	 unsigned char byte[8];
}_CAN_0x0C6CA4D7;

typedef union {

    struct {
        unsigned char Reserve1 : 4; //����
        unsigned char Lane_Depature_Right : 2; //���ҳ���ƫ�룩
        unsigned char Lane_Depature_Left : 2; //���󳵵�ƫ�룩
        unsigned char warning : 1; //��ײԤ��
        unsigned char Reserve2 : 7; //����
        unsigned char Reserve3; //����
        unsigned char Reserve4; //����
        unsigned char Reserve5; //����
        unsigned char Reserve6; //����
        unsigned char Reserve7; //����
        unsigned char Reserve8; //����
    };
    unsigned char byte[8];
} _CAN_0x10F007E8;
#endif

typedef union {

    struct {
        unsigned char DriverMode : 2; //��ʻģʽ
        unsigned char Gear : 4; //��λ
        unsigned char Reserve1 : 2;

        unsigned char AcceleratePedalAperture; //����̤�忪��
        unsigned Speed; //����
        unsigned char BrakePedalAperture; //�ƶ�̤�忪��
        unsigned char Reserve2;

        unsigned char LimitTorque : 1; //
        unsigned char LimitPower : 1; //
        unsigned char LimitPower3 : 4; //
        unsigned char SystemFault : 1; //
        unsigned char READY : 1; //

        unsigned char VcuLife; //
    };
    unsigned char byte[8];
} _CAN_0x0CF101A7;

typedef union {

    struct {
        unsigned char ProductCode; //ϵͳ���Ҵ���
        unsigned char ContactorOrder; //VCU�ϸ�ѹָ��    
        unsigned McuInputVoltage; //���������ĸ�ߵ�ѹ
        unsigned char Reserve1; //

        unsigned char Reserve2 : 5; //
        unsigned char ChargeStatus : 2; //BMS ������ָ�״̬
        unsigned char ChargeEn : 1;

        unsigned char ContactorStatus; //��ѹ�̵���״̬
        unsigned char VcuLife;
    };
    unsigned char byte[8];
} _CAN_0x0CF103A7;

typedef union {

    struct {
        unsigned char FaultLevel : 3; //�������ϵȼ� 
        unsigned char Reserve1 : 5;

        unsigned VCU_DTC; //����������
        unsigned char Reserve2;

        unsigned char Ganzaopin : 1; //��ѹ������
        unsigned char AirOverTemp : 1; //��ѹ������
        unsigned char Reserve3 : 6;

        unsigned char Reserve4;
        unsigned char Reserve5;
        unsigned char Reserve6;
    };
    unsigned char byte[8];
} _CAN_0x0CF1064A;

typedef union {

    struct {
        unsigned CtrlVoltage; //�����������ѹ
        unsigned CtrlCurrent; //������ĸ�ߵ���

        unsigned char Reserve1 : 2;
        unsigned char IpuMode : 5;
        unsigned char Reserve2 : 1;

        DATA_BIT Diagnosis1;
        unsigned char Reserve4;

        unsigned char Reserve5 : 4;
        unsigned char McuLife : 4;
    };
    unsigned char byte[8];
} _CAN_0x18F11FF0;

typedef union {

    struct {
        unsigned MotorTopTorque;
        unsigned MotorSpeed;
        unsigned MotorTorque;
        unsigned char MotorTemp; //����¶�
        unsigned char MotorCtrlTemp; //����������¶�
    };
    unsigned char byte[8];
} _CAN_0x18F120F0;

typedef union {

    struct {
        unsigned char MotorCtrlStatus;
        unsigned char MotorCtrlFaultCode;
        unsigned Reserve1;
        unsigned Reserve2; //
        unsigned Reserve3; //
    };
    unsigned char byte[8];
} _CAN_0x18F121F0;

typedef union {

    struct {
        unsigned Voltage; //ĸ�ߵ�ѹ
        unsigned Current; //ĸ�ߵ���
        unsigned SOC; //SOC

        unsigned char BmsFaultLevel : 3; //
        unsigned char BmsRequest : 2; //
        unsigned char BmsCheckout : 3; //

        unsigned char Contactor1 : 2;
        unsigned char Contactor2 : 2;
        unsigned char Contactor3 : 2;
        unsigned char Contactor4 : 2;
    };
    unsigned char byte[8];
} _CAN_0x18F13DF3;

typedef union {

    struct {
        unsigned BMS_MAX_Cell_Voltage; //�����ߵ����ѹ
        unsigned BMS_MIN_Cell_Voltage; //�����͵����ѹ
        unsigned char BMS_MAX_Temp; //�������¶�
        unsigned char BMS_MIN_Temp; //�������¶�
        unsigned char Reserve1; //
        unsigned char Reserve2; //
    };
    unsigned char byte[8];
} _CAN_0x18F13EF3;

typedef union {

    struct {
        unsigned LimitChargeCurrent;
        unsigned LimitDischargeCurrent;
        unsigned char LimitHighTemp;
        unsigned char LimitLowTemp;
        unsigned char LimitSOC;
        unsigned char Reserve1; //
    };
    unsigned char byte[8];
} _CAN_0x18F140F3;

typedef union {

    struct {
        unsigned char BmsFaultCode;
        unsigned char ChargeTime;
        unsigned char ChargeStatus;

        unsigned char BmsBalance : 1;
        unsigned char Reserve1 : 7;

        unsigned char ChargeGun;
        unsigned char Reserve2;
        unsigned char BmsLife;
        unsigned char Reserve3;
    };
    unsigned char byte[8];
} _CAN_0x18F141F3;

typedef union {

    struct {
        unsigned BatAH; //������صĶ����
        unsigned BatVoltage; //������صĶ�ܵ�ѹ
        unsigned char BatYear;
        unsigned char BatMonth;
        unsigned char BatDate;
        unsigned char Reserve;
    };
    unsigned char byte[8];
} _CAN_0x18F148F3;

typedef union {

    struct {
        unsigned SwitcherMotorSpeed; //���ת��
        unsigned SwitcherCtrlVoltage; //������ĸ�ߵ�ѹ
        unsigned char SwitcherCtrlCurrent; //����������
        unsigned char SwitcherCtrlTemp; //�������¶�
        unsigned char SwitcherLife; //ת������Life

        unsigned char SwitcherFaultCode : 4; //������
        unsigned char SwitcherPumpStatus : 2; //����״̬
        unsigned char SwitcherFeedback : 1; //����״̬
        unsigned char SwitcherCtrlPrechargeStatus : 1; //������Ԥ��״̬
    };
    unsigned char byte[8];
} _CAN_0x142FFF95;

typedef union {

    struct {
        unsigned DCDC_InputVoltage; //�����ѹ
        unsigned char DCDC_InputCurrent; //�������
        unsigned char DCDC_OutputCurrent; //�������
        unsigned char DCDC_CtrlTemp; //�������¶�
        unsigned char DCDC_OutputAssistLowVoltage; //���������ѹ
        unsigned char DCDC_Life; //DCDC_Life
        unsigned char DCDC_FaultCode : 4; //������
        unsigned char DCDC_Status : 2; //DCDC״̬
        unsigned char Reserve : 1; //����
        unsigned char DCDC_CtrlPrechargeStatus : 1; //������Ԥ��״̬
    };
    unsigned char byte[8];
} _CAN_0x142CFF98;

typedef union {

    struct {
        unsigned DCAC_MotorRotateSpeed; //���ת��
        unsigned DCAC_CtrlVoltage; //������ĸ�ߵ�ѹ
        unsigned char DCAC_CtrlCurrent; //����������
        unsigned char DCAC_CtrlTemp; //�������¶�
        unsigned char DCAC_Life; //DCAC_Life
        unsigned char DCAC_FaultCode : 4; //������
        unsigned char DCAC_PumpStatus : 2; //����״̬
        unsigned char Reserve : 1; //����
        unsigned char DCAC_CtrlPrechargeStatus : 1; //������Ԥ��״̬
    };
    unsigned char byte[8];
} _CAN_0x1429FF9B;

typedef union {

    struct {
        DATA_BIT AcSystemFault; //�յ�ϵͳ����

        unsigned char Reserve1 : 5;
        unsigned char AcFanStatus : 3; //�յ�ϵͳ�������״̬

        unsigned char AcSystemStatus; //�յ�ϵͳ����״̬
        unsigned char AcIndoorTemp; //�����¶�
        unsigned char AcOutdoorTemp; //�����¶�
        unsigned char Reserve2; //����
        unsigned char Reserve3; //����
        unsigned char AcLife; //��յ�������ͨ��״ֵ̬��ѭ�������仯���Դ˶϶�ͨ����Ч
    };
    unsigned char byte[8];
} _CAN_0x18FFC09E;

typedef union {

    struct {
        unsigned char InsulationResisitanceFaultLevel : 3; //��Ե��ֵ����״̬
        unsigned char Reserve1 : 5;

        unsigned InsulationResistanceP; //������Ե��ֵ
        unsigned InsulationResistanceN; //������Ե��ֵ
        unsigned char InsulationResistanceFaultCode;
        DATA_BIT FaultMesg;
        unsigned InsulationLife;
    };
    unsigned char byte[8];
} _CAN_0x18F746E5;

typedef union {

    struct {
        unsigned char FogWarnStatus : 4; //��������״̬
        unsigned char Reserve1 : 4; //
        
        unsigned char WarnStatus : 1;
        unsigned char Reserve2 : 7; 
        
        unsigned char TempWarn : 1;
        unsigned char Reserve3 : 7;
        
        unsigned char Temp;
        unsigned char Reserve4;
        unsigned char Reserve5;
        unsigned char Reserve6;
        unsigned char Life;
    };
    unsigned char byte[8];
} _FogWarn;
#pragma pack()

extern	unsigned char BMS_MIN_Temp[4];
extern	unsigned char BMS_MIN_Temp_CaseNum[4];

extern	unsigned char BMS_MAX_Temp[4];
extern	unsigned char BMS_MAX_Temp_CaseNum[4];

extern	unsigned BMS_MAX_Cell_Voltage[4];
extern	unsigned char BMS_MAX_Cell_Voltage_Num[4];
extern	unsigned char BMS_MAX_Cell_Voltage_CaseNum[4];

extern	unsigned BMS_MIN_Cell_Voltage[4];
extern	unsigned char BMS_MIN_Cell_Voltage_Num[4];
extern	unsigned char BMS_MIN_Cell_Voltage_CaseNum[4];

#if 0
extern _CAN_0x0CFF1501 CAN_0x0CFF1501;
extern _CAN_0x10F8159E CAN_0x10F8159E;
extern _CAN_0x10F8169E CAN_0x10F8169E;
extern _CAN_0x18F8179E CAN_0x18F8179E;
extern _CAN_0x08F8189E CAN_0x08F8189E;
extern _CAN_0x18F8199E CAN_0x18F8199E;
extern _CAN_0x18F81A9E CAN_0x18F81A9E;
extern _CAN_0x08019F80 CAN_0x08019F80;
extern _CAN_0x08029F80 CAN_0x08029F80;
extern _CAN_0x08039F80 CAN_0x08039F80;
extern _CAN_0x08049F80 CAN_0x08049F80;
extern _CAN_0x08059F80 CAN_0x08059F80;
extern _CAN_0x142CFF98 CAN_0x142CFF98;
extern _CAN_0x1429FF9B CAN_0x1429FF9B;
extern _CAN_0x0C6CA4D7 CAN_0x0C6CA4D7;
extern _CAN_0x10F007E8 CAN_0x10F007E8;
#endif

extern	_CAN_0x0CF101A7 CAN_0x0CF101A7;
extern	_CAN_0x0CF103A7 CAN_0x0CF103A7;
extern	_CAN_0x0CF1064A CAN_0x0CF1064A;
extern	_CAN_0x18F11FF0 CAN_0x18F11FF0;
extern	_CAN_0x18F120F0 CAN_0x18F120F0;
extern	_CAN_0x18F121F0 CAN_0x18F121F0;
extern	_CAN_0x18F13DF3 CAN_0x18F13DF3;
extern	_CAN_0x18F13EF3 CAN_0x18F13EF3;
extern	_CAN_0x18F140F3 CAN_0x18F140F3;
extern	_CAN_0x18F141F3 CAN_0x18F141F3;
extern	_CAN_0x18F148F3 CAN_0x18F148F3;
extern	_CAN_0x142FFF95 CAN_0x142FFF95;
extern	_CAN_0x142CFF98 CAN_0x142CFF98;
extern	_CAN_0x1429FF9B CAN_0x1429FF9B;
extern	_CAN_0x18FFC09E CAN_0x18FFC09E;
extern	_CAN_0x18F746E5 CAN_0x18F746E5;
extern	_FogWarn FogWarn[3];
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

