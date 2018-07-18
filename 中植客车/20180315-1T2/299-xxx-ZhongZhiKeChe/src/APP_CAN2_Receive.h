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
        unsigned long SPN : 19;
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
/*******************�ְ�����*****************/
#pragma pack(1)

typedef union {
    unsigned char byte[8];

    struct {
        unsigned char CarStatus : 2;
        unsigned char RunMode : 2;
        unsigned char GearMode : 4;
        unsigned char EV_Gear;
        unsigned EV_Speed;
        unsigned char SpeedDepth;
        unsigned char BrakeDepth;
        unsigned Oum;
    };
} _CAN_0x18EF4AEF;

typedef union {
    unsigned char byte[8];

    struct {
        unsigned char No1 : 1;
        unsigned char No2 : 1;
        unsigned char No3 : 1;
        unsigned char No4 : 1;
        unsigned char No5 : 1;
        unsigned char No6 : 1;
        unsigned char No7 : 1;
        unsigned char No8 : 1;

        unsigned char No9 : 1;
        unsigned char No10 : 1;
        unsigned char No11 : 1;
        unsigned char No12 : 1;
        unsigned char No13 : 1;
        unsigned char No14 : 1;
        unsigned char No15 : 1;
        unsigned char No16 : 1;

        unsigned char No17 : 1;
        unsigned char No18 : 1;
        unsigned char No19 : 1;
        unsigned char Reserve1 : 5;

        unsigned char No20 : 1;
        unsigned char No21 : 1;
        unsigned char No22 : 1;
        unsigned char No23 : 1;
        unsigned char No24 : 1;
        unsigned char No25 : 1;
        unsigned char No26 : 1;
        unsigned char No27 : 1;

        unsigned char ChargeStatus : 4;
        unsigned char LoceStatus : 4;

        unsigned char No30 : 1;
        unsigned char No31 : 1;
        unsigned char No32 : 1;
        unsigned char No33 : 1;
        unsigned char No34 : 1;
        unsigned char No35 : 1;
        unsigned char No36 : 1;
        unsigned char No37 : 1;

        unsigned char No38 : 1;
        unsigned char No39 : 1;
        unsigned char Reserve2 : 6;

        unsigned char CtrlIOStatus;
    };
} _CAN_0x18EF4BEF;

typedef union {
    unsigned char byte[8];

    struct {
        unsigned int BMS_V; //��ص�ѹ
        unsigned int BMS_A; //��ص���
        unsigned char BMS_SOC; //���SOC
        unsigned char EV_RestAhr; //���ʣ������
        unsigned char DischargePowerLimilt;
        unsigned char ChargePowerLimilt;
    };
} _CAN_0x18EF4CEF;

typedef union {
    unsigned char byte[8];

    struct {
        unsigned char BAT_Max_Cell_Voltage; //��ص���ߵ�ѹ
        unsigned char BAT_Min_Cell_Voltage; //��ص���͵�ѹ
        unsigned char BAT_Max_Cell_Voltage_Cell_Number; //��ߵ����ѹ���
        unsigned char BAT_Min_Cell_Voltage_Cell_Number; //��͵����ѹ���
        unsigned char BAT_Max_Cell_Temperature; //��ߵ����¶�
        unsigned char BAT_Min_Cell_Temperature; //��͵����¶�
        unsigned char BAT_Max_Cell_Temp_Cell_Number; //��ߵ����¶ȱ��
        unsigned char BAT_Min_Cell_Temp_Cell_Number; //��͵����¶ȱ��
    };
} _CAN_0x18EF4DEF;

typedef union {
    unsigned char byte[8];

    struct {
        unsigned char MotorNumber : 4;
        unsigned char MotorSquence : 4;
        unsigned int MCU_RPM; //���ת��
        unsigned int MotorTorque;
        unsigned int OutSpeed;
        unsigned char Reserve;
    };
} _CAN_0x18EF4EEF;

typedef union {
    unsigned char byte[8];

    struct {
        unsigned char : 4;
        unsigned char MotorSquence : 4;
        unsigned char MotorStatus; //���״̬
        unsigned int MCUVoltage;
        unsigned int MCUCurrent;
        unsigned char MCU_Control_Temp; //����������¶�
        unsigned char MCU_Temp; //����¶�     
    };
} _CAN_0x18EF4FEF;

typedef union {
    unsigned char byte[8];

    struct {
        unsigned char No1 : 2;
        unsigned char No2 : 2;
        unsigned char No3 : 2;
        unsigned char No4 : 2;

        unsigned char No5 : 2;
        unsigned char No6_1 : 2;
        unsigned char No6_2 : 2;
        unsigned char No7 : 2;

        unsigned char No8 : 1;
        unsigned char No9 : 1;
        unsigned char No10 : 1;
        unsigned char No11 : 1;
        unsigned char No12 : 1;
        unsigned char No13 : 1;
        unsigned char No14 : 1;
        unsigned char No15 : 1;

        unsigned char No16 : 1;
        unsigned char No17 : 1;
        unsigned char No18 : 1;
        unsigned char Reserve1 : 5;

        unsigned char No19 : 1;
        unsigned char No20 : 1;
        unsigned char No21 : 1;
        unsigned char No22 : 1;
        unsigned char No23 : 1;
        unsigned char No24 : 1;
        unsigned char No25 : 1;
        unsigned char No26 : 1;

        unsigned char No27 : 1;
        unsigned char No28 : 1;
        unsigned char No29 : 1;
        unsigned char No30 : 1;
        unsigned char No31 : 1;
        unsigned char No32 : 1;
        unsigned char No33 : 1;
        unsigned char Reserve2 : 1;

        unsigned char No34 : 1;
        unsigned char No35 : 1;
        unsigned char No36 : 1;
        unsigned char No37 : 1;
        unsigned char No38 : 1;
        unsigned char No39 : 1;
        unsigned char No40 : 1;
        unsigned char No41 : 1;

        unsigned char No42 : 1;
        unsigned char No43 : 1;
        unsigned char No44 : 1;
        unsigned char No45 : 1;
        unsigned char No46 : 1;
        unsigned char No47 : 1;
        unsigned char No48 : 1;
        unsigned char Reserve3 : 1;
    };
} _CAN_0x18EF5AEF;

typedef union {
    unsigned char byte[8];

    struct {
        unsigned char No1 : 1;
        unsigned char No2 : 1;
        unsigned char No3 : 1;
        unsigned char No4 : 1;
        unsigned char No5 : 1;
        unsigned char No6 : 1;
        unsigned char No7 : 1;
        unsigned char No8 : 1;

        unsigned char No9 : 2;
        unsigned char No10 : 2;
        unsigned char No11 : 2;
        unsigned char No12 : 2;

        unsigned char No13 : 1;
        unsigned char No14 : 1;
        unsigned char No15 : 1;
        unsigned char No16 : 1;
        unsigned char No17 : 1;
        unsigned char No18 : 1;
        unsigned char : 2;

        unsigned char Reserve1;
        unsigned char Reserve2;
        unsigned char Reserve3;
        unsigned char Reserve4;
        unsigned char Reserve5;
    };
} _CAN_0x18EF5BEF;

typedef union {
    unsigned char byte[8];

    struct {
        unsigned char Ev_Fail_Mode : 4;
        unsigned char : 4;
        unsigned char Reserve1;
        DTC VCU_DM1;
    };
} _CAN_0x18FECAEF;

#pragma pack()
extern _CAN_0x18EF4AEF CAN_0x18EF4AEF;
extern _CAN_0x18EF4BEF CAN_0x18EF4BEF;
extern _CAN_0x18EF4CEF CAN_0x18EF4CEF;
extern _CAN_0x18EF4DEF CAN_0x18EF4DEF;
extern _CAN_0x18EF4EEF CAN_0x18EF4EEF;
extern _CAN_0x18EF4FEF CAN_0x18EF4FEF;
extern _CAN_0x18EF5AEF CAN_0x18EF5AEF;
extern _CAN_0x18EF5BEF CAN_0x18EF5BEF;
extern _CAN_0x18FECAEF CAN_0x18FECAEF;

/*// EV Information Message 0x18EF4AEF
extern unsigned int  BMS_V;       //��ص�ѹ
extern unsigned char BMS_SOC;     //���SOC
extern unsigned char BMS_A;       //��ص���
extern unsigned char MCU_RPM;     //���ת��
extern unsigned char MCU_Voltage; //���ĸ�ߵ�ѹ
extern unsigned char MCU_Temp;    //����¶�
extern unsigned char MCU_Control_Temp ; //����������¶�

//EV Information Message1 0x18EF4BEF
extern unsigned char EV_Speed;
extern unsigned char EV_Kwh_avg;  //ƽ�����
extern unsigned char EV_Kwh_1s;   //˲ʱ���
extern unsigned int  EV_RestAhr;  //���ʣ������
extern unsigned char EV_Voltage;  //���ص�ѹ
extern unsigned char EV_Gear;     //��λ

//EV Information Message2 0x18EF4CEF
extern unsigned int  BAT_Max_Cell_Voltage; //��ص���ߵ�ѹ
extern unsigned int  BAT_Max_Cell_Voltage_Cell_Number; //��ߵ����ѹ���
extern unsigned int  BAT_Min_Cell_Voltage; //��ص���͵�ѹ
extern unsigned int  BAT_Min_Cell_Voltage_Cell_Number; //��͵����ѹ���

//EV Information Message3 0x18EF4DEF
extern unsigned char BAT_Max_Cell_Temperature; //��ߵ����¶�
extern unsigned int  BAT_Max_Cell_Temp_Cell_Number;   //��ߵ����¶ȱ��
extern unsigned char BAT_Min_Cell_Temperature; //��͵����¶�
extern unsigned int  BAT_Min_Cell_Temp_Cell_Number;   //��͵����¶ȱ��

//EV DTC Message 0x18EF4EEF
typedef union {

    struct {
        unsigned ev_ready_flag : 1;
        unsigned KT_SIGNAL : 1;
        unsigned : 1;
        unsigned : 1;
        unsigned SOC_Warn : 2;
        unsigned Insulation_Fault : 2;
        
        unsigned BMS_Fault : 2;
        unsigned MT_Temp_Warn : 2;
        unsigned MT_Fault : 2;
        unsigned MCU_COMM_Fault : 2;
        
        unsigned BAT_Fault : 2;        
        unsigned BMS_COMM_Fault : 2;
        unsigned BOX_Fault : 2;
        unsigned DCDC_Fault : 2;
        
        unsigned DCAC_A_Fault : 2;       
        unsigned DCAC_B_Fault : 2;
        unsigned A_Fault : 2;       
        unsigned B_Fault : 2;
        
        unsigned V24_Charge : 1;     
        unsigned Fire_Fault : 2;
        unsigned : 5;
    };
    unsigned char byte[5];
} ID_18EF4EEF;
extern ID_18EF4EEF EV_DTC;

//VCU_DM1 0x18FECAEF
extern unsigned char Ev_Fail_Mode;
extern DM1 VCU_DM1;
extern unsigned char VCU_Occurrence_Count;

//Transmission Faults (DM1 with SA03)TCU_DTC 0x18FECA03
extern unsigned char Red_Stop_Lamp_Status;
extern unsigned char Amber_Warning_Lamp_Status;
extern DM1 TCU_DM1;
extern unsigned char TCU_Occurrence_Count;

//�����Ϣ 0x18FFAFF3
extern DATA_DOUBLE Charge;
#define BMS_ChargeGun_Link Charge.bit1
#define BMS_Chargeing      Charge.bit2*/

//��ѹ��Դ��DC/DC�����ͱ��� 0x18FF12F7
extern unsigned int  DCDC_Output_Voltage; //DCDC�����ѹ
extern unsigned int  DCDC_Output_Current; //DCDC�������
extern unsigned char DCDC_WorkStatus;     //DCDC����״̬
extern unsigned char DCDC_FaultCode;      //DCDC���ϴ���

//�ͱã�DC/AC����Դ���ͱ��� 0x18019888
extern unsigned int  OILDCAC_Voltage;     //DCAC�����ѹ
extern unsigned int  OILDCAC_Current;     //DCAC�������
extern unsigned char OILDCAC_Temp;   //DCACɢ�����¶�
extern unsigned char OILDCAC_FaultCode;   //DCAC���ϴ���

//���ã�DC/AC����Դ���ͱ��� 0x1805A89C
extern unsigned int  AIRDCAC_InputVoltage;//DCAC�����ѹ
extern unsigned int  AIRDCAC_Voltage;     //DCAC�����ѹ
extern unsigned int  AIRDCAC_Current;     //DCAC�������
extern unsigned char AIRDCAC_Temp;   //DCACɢ�����¶�
extern unsigned char AIRDCAC_FaultCode;   //DCAC���ϴ���

extern unsigned char BMS_SOC;
extern unsigned int  BMS_V;
extern unsigned int  BMS_A;
extern unsigned char No27;
extern unsigned char ChargeStatus;

/*
//VCU��Ϣ1 0x0CFA00D0
extern unsigned char VCU_BUSStatus;      //������ǰ״̬
extern unsigned char VCU_MotorStatus; //������ϵͳ״̬
extern unsigned char VCU_HandBrake;   //��ɲ�ź�
extern unsigned char VCU_Gear; //��λ
extern unsigned char VCU_Key;  //Կ��λ��
extern DATA_BIT      VCU_Status1;//�ź�״̬1
#define  KT_SIGNAL     VCU_Status1.bit2
#define  ABS_SIGNAL    VCU_Status1.bit4
#define  RPM_SIGNAL    VCU_Status1.bit5
#define  NM_SIGNAL     VCU_Status1.bit6
extern unsigned int  MCU_RPM;                 //���ת��
extern unsigned int  MCU_NM;                  //���Ť��
extern unsigned char VCU_Life;
//VCU��Ϣ2 0x0CFB00D0
extern DATA_BIT      VCU_Status2;//�ź�״̬2
#define  MCU_VOLTAGE_SIGNAL     VCU_Status2.bit1
#define  MCU_CURRENT_SIGNAL     VCU_Status2.bit2
#define  KC_SIGNAL              VCU_Status2.bit3
#define  BRAKE_SIGNAL           VCU_Status2.bit4
#define  SPEED_SIGNAL           VCU_Status2.bit5
#define  VBAT_SIGNAL            VCU_Status2.bit6
extern unsigned int  MCU_Voltage; //���ĸ�ߵ�ѹ
extern unsigned int  MCU_Current;     //�������
extern unsigned char VCU_TM_Brake_percent; //�ƶ�̤�忪��
extern unsigned char VCU_TM_Speed_percent; //����̤�忪��
extern unsigned char VCU_XDC; //���ص�ѹ
//VCU��Ϣ3 0x0CFC00D0
extern unsigned char MCU_TempSignal; //����¶��ź�״̬
extern unsigned char MCU_ControlTempSignal; //����������¶��ź�״̬
extern unsigned char MCU_Temp; //����¶�
extern unsigned char MCU_Control_Temp ; //����������¶�
extern unsigned int  VCU_KM;
extern unsigned char VCU_SPEED;
//Զ������Ӧ�� 0x0CFE00D0
//VCU������Ϣ 0x0CFF00D0
extern unsigned int  VCU_FaultCode; 
extern DATA_BIT      VCU_Status3;//�ź�״̬3
#define  VCU_TorqueLimitSignal     VCU_Status3.bit1
#define  VCU_TorqueLimit           VCU_Status3.bit2
#define  VCU_OverSpeed             VCU_Status3.bit3
#define  VCU_RemoteLock            VCU_Status3.bit8
extern unsigned char VCU_Lock;                    //����״̬
extern unsigned char VCU_Kwh_1s;  //˲ʱ���
//����������ʹ���ź� 0x0CEA00D0
extern unsigned char VCU_OilEn;  //�ͱ�ʹ��
extern unsigned char VCU_AirEn;  //����ʹ��
extern unsigned char VCU_DCDCEn; //DCDCʹ��
//�����������Ϣ 0x18A1EFF3
extern unsigned char BMS_SOC;     //���SOC
extern unsigned int  BMS_V;       //��ص�ѹ
extern unsigned int  BMS_A; //��ص���
extern unsigned int  BMS_ChargeTimes; //������
extern unsigned char BMS_Life;     //BMSlife
//������ذ���Ϣ 0x18A2EFF3
extern unsigned char BMS_PackNumber;  //������ܴ���
extern unsigned int  BMS_SingleNumber;  //����ܴ���
extern unsigned char BMS_SeriesNumber;  //��������
extern unsigned char BMS_ParallelNumber;  //��������
extern unsigned int  BAT_Ahr;           //��ض����
//������ذ���ѹ��Ϣ 0x18A3EFF3
extern unsigned char BAT_Pack_SequenceNumber_V; //������
extern unsigned int  BAT_Pack_Voltage[25]; //������ѹ
//��ص�����¶�����Ϣ 0x18A4EFF3
extern unsigned int  BAT_Min_Cell_Voltage; //��ص���͵�ѹ
extern unsigned int  BAT_Max_Cell_Voltage; //��ص���ߵ�ѹ
extern unsigned char BAT_Min_Cell_Temperature; //��͵����¶�
extern unsigned char BAT_Max_Cell_Temperature; //��ߵ����¶�
extern unsigned int  BAT_RestAhr;           //���ʣ������
//��س�ŵ���Ϣ 0x18A5EFF3
extern unsigned int  BMS_LowDischargeVoltage;//��ͷŵ��ѹ
extern unsigned int  BMS_HighChargeVoltage; //��߳���ѹ
extern unsigned int  BMS_HighDischargeCurrent;//��߷ŵ����
extern unsigned int  BMS_HighChargeCurrent;//��߳�����
//����¶Ⱥ͵���λ����Ϣ 0x18A6EFF3
extern unsigned char BAT_Max_Cell_Voltage_Cell_Case; //��ߵ����ѹ���
extern unsigned char BAT_Max_Cell_Voltage_Cell_Number; //��ߵ����ѹλ��
extern unsigned char BAT_Min_Cell_Voltage_Cell_Case; //��͵����ѹ���
extern unsigned char BAT_Min_Cell_Voltage_Cell_Number; //��͵����ѹλ��
extern unsigned char BAT_Max_Pole_Temp; //��߼����¶�
extern unsigned char BAT_Max_Pole_Temp_Cell_Case; //��߼����¶����
extern unsigned char BAT_Max_Cell_Temp_Cell_Case; //��ߵ����¶����
extern unsigned char BAT_Min_Cell_Temp_Cell_Case; //��͵����¶����
//������ذ�����������Ϣ��һ����Ϊһ�����壩 0x18A7EFF3
extern unsigned char BAT_Pack_SequenceNumber_N; //������
extern unsigned char BAT_Pack_Number[25]; //����䴮������
//��ر�����Ϣ 0x18B1EFF3
extern unsigned char BMS_Warn_Type;      //�������
extern unsigned char BMS_1LevelFault;      //һ�����ϴ���
extern unsigned char BMS_2LevelFault;      //�������ϴ���
extern unsigned char BMS_3LevelFault;      //�������ϴ���
extern unsigned char BMS_InsulationControl;      //��Ե����
extern unsigned char BMS_ChargeGun_Comm;      //���ǹͨѶ
extern unsigned char BMS_ChargeGun_Link;      //���ǹ����״̬
extern unsigned char BMS_Chargeing;      //���ǹ״̬
extern unsigned char BMS_KB;               //������̵���״̬
//��ػ���Ԥ����Ϣ 0x18B2EFF3
extern unsigned char BMS_FireWarnLevel;               //��ػ��ּ���
extern unsigned char BMS_FireFaultCode;               //��ػ��ֹ�����
extern unsigned char BMS_FireFaultNumber;               //��ػ��ֹ������
extern unsigned char BMS_FireWarnNumber;               //��ػ���Ԥ�����
//��������е����ѹ��Ϣ 0x18C1EFF3
extern unsigned int  BAT_Cell_VoltageNumber; //����������
extern unsigned int  BAT_Cell_Voltage[10][35]; //��ص����ѹ
//����������¶���Ϣ 0x18E1EFF3
extern unsigned int  BAT_Cell_TempNumber; //����������
extern unsigned int  BAT_Cell_Temp[10][30]; //��ص����¶�
//������Ե��ر��� 0x1819A1A4
extern unsigned int  IM_Oum;               //��Ե��ֵ
extern unsigned int  IM_Votage;            //��Ե��ѹ
extern unsigned char IM_FaultLevel;        //��Ե���ϵȼ�
extern unsigned char IM_WorkStatus;        //��Ե����״̬
extern unsigned char IM_FaultStatus;       //��Ե����״̬
extern unsigned char IM_Life;              //��ԵLife
//Զ���������� 0x18FF70EE
//���ӵ�λ���ر��� 0X18FC0011
//DC/DC������Ϣ 0x1801A79A
extern unsigned int  DCDC_Input_Voltage;  //DCDC�����ѹ
extern unsigned char DCDC_Output_Voltage; //DCDC�����ѹ
extern unsigned int  DCDC_Output_Current; //DCDC�������
extern unsigned char DCDC_Temp;      //DCDCģ���¶�
extern unsigned char DCDC_FaultCode; //DCDC���ϴ���
extern unsigned char DCDC_WorkStatus; //DCDC����״̬
//�ͱÿ�����������Ϣ 0x1801A79B
extern unsigned int  OILDCAC_InputVoltage;   //DCAC�����ѹ
extern unsigned int  OILDCAC_Voltage;   //DCAC�����ѹ
extern unsigned int  OILDCAC_Current;   //DCAC�������
extern unsigned char OILDCAC_Temp; //DCAC����¶�
extern unsigned char OILDCAC_FaultCode;    //DCAC���ϴ���
//���ÿ�����������Ϣ 0x1801A79D
extern unsigned int  AIRDCAC_InputVoltage;   //DCAC�����ѹ
extern unsigned int  AIRDCAC_Voltage;   //DCAC�����ѹ
extern unsigned int  AIRDCAC_Current;   //DCAC�������
extern unsigned char AIRDCAC_Temp; //DCAC����¶�
extern unsigned char AIRDCAC_FaultCode;    //DCAC���ϴ���
//��ѹ�ͱã�DC/AC��������������Ϣ 0x0CF603A1
//�յ����Ʊ��� 0x1801A79E
extern unsigned char AC_Status;   //�յ���������
extern unsigned char AC_Set_Temp; //�趨�¶�
extern unsigned char AC_Gear; //��λ
extern unsigned char AC_WindMode; //�·�ģʽ
extern unsigned char AC_Work_Status; //����ģʽ
extern unsigned char AC_Life; 
//��ѹ������Ϣ
extern DATA_BIT Protect[2];
//������
extern DATA_BIT Concentrated_Lubrication;
*/
void DM(unsigned char x, DM1 id);
void CAN_DATA_Init(void);
#endif	/* APP_CAN2_RECEIVE_H */

