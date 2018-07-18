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
/*******************�ְ�����*****************/
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
//extern unsigned int  BAT_Cell_VoltageNumber; //����������
extern unsigned int  BAT_Cell_Voltage[10][31]; //��ص����ѹ
//����������¶���Ϣ 0x18E1EFF3
//extern unsigned int  BAT_Cell_TempNumber; //����������
extern unsigned char BAT_Cell_Temp[10][6]; //��ص����¶�
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

void DM(unsigned char x, DM1 id);

#endif	/* APP_CAN2_RECEIVE_H */

