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
/*
//��ػ�����Ϣ ID:0x18F201F3
extern unsigned char BMS_SOC;     //���SOC
extern unsigned int  BMS_V;       //��ص�ѹ
extern unsigned int  BMS_A;       //��ص���
extern unsigned int  BMS_Number;  //������ܴ���
extern unsigned char BMS_Life;    //BMSlife

//��ػ�����Ϣ 2 ID:0x18F202F3
extern unsigned char BMS_Current_Charge_Limit_Long;
extern unsigned char BMS_Current_Charge_Limit_Short;
extern unsigned char BMS_Current_Disharge_Limit_Long;
extern unsigned char BMS_Current_Disharge_Limit_Short;
extern unsigned char BMS_Cut;

//��ع��ϱ�����Ϣ ID:0x18F205F3
extern DATA_DOUBLE   BMS_Warn[4];
#define    Pack_Bat_OverVoltage    BMS_Warn[0].bit1
#define    Single_Bat_OverVoltage  BMS_Warn[0].bit2
#define    Pole_OverTemp           BMS_Warn[0].bit3
#define    Battery_OverTemp        BMS_Warn[0].bit4

#define    Bat_Fault               BMS_Warn[1].bit1
#define    Charge_Gun_OverTemp     BMS_Warn[1].bit2
#define    Single_Bat_UnderVoltage BMS_Warn[1].bit3
#define    Pack_Bat_UnderVoltage   BMS_Warn[1].bit4

#define    Diff_Temp               BMS_Warn[2].bit1
#define    Diff_Voltage            BMS_Warn[2].bit2
#define    Charge_OverCurrent      BMS_Warn[2].bit3
#define    Discharge_OverCurrent   BMS_Warn[2].bit4

#define    Bat_LowTemp             BMS_Warn[3].bit1
#define    Diff_SOC                BMS_Warn[3].bit2
#define    SOC_High                BMS_Warn[3].bit3
#define    SOC_Low                 BMS_Warn[3].bit4

extern DATA_BIT      BMS_Fault[3];
#define  BMU_OFFLINE           BMS_Fault[0].bit1
#define  CHARGER_COMM_FAULT    BMS_Fault[0].bit2  
#define  PRECHARGE_FAULT       BMS_Fault[0].bit3 
#define  BALANCE_FAULT         BMS_Fault[0].bit4
#define  WARN_FAULT            BMS_Fault[0].bit5 
#define  BAT_COOL_FAULT        BMS_Fault[0].bit6
#define  BMS_FAULT_OTHER       BMS_Fault[0].bit7
#define  BMS_COMM_FAULT        BMS_Fault[0].bit8  

#define  BALA_STATUS           BMS_Fault[1].bit1
#define  WARN_STATUS           BMS_Fault[1].bit2  
#define  BAT_COLOD_STATUS      BMS_Fault[1].bit3
#define  CHARGE_PLUG           BMS_Fault[1].bit4
#define  CHARGE_STATUS         BMS_Fault[1].bit5 
#define  BAT_FAULT             BMS_Fault[1].bit6
extern unsigned char BMS_Self_Check;//BMS�Լ�״̬

#define  TEMP_COLT_OFFLINE     BMS_Fault[2].bit1
#define  BAT_CELL_COLT_OFFLINE BMS_Fault[2].bit2  
#define  BAT_DISCHARGE_PROTECT BMS_Fault[2].bit3
#define  SOC_JUMP              BMS_Fault[2].bit4
#define  SYSTEM_MISMATCH       BMS_Fault[2].bit5 
#define  FIRE_FAULT            BMS_Fault[2].bit6
#define  VOLTAGE_DIFF_FAULT    BMS_Fault[2].bit7
#define  KT_FAULT              BMS_Fault[2].bit8

//��ص�����ߵ�ѹ��Ϣ 0x18F206F3 // 0x18F207F3
extern unsigned int  BAT_Max_Cell_Voltage[4]; //��ص���ߵ�ѹ
extern unsigned char BAT_Max_Cell_Voltage_Cell_Case[4]; //��ߵ����ѹ���
extern unsigned char BAT_Max_Cell_Voltage_Cell_Number[4]; //��͵����ѹλ��

//��ص�����͵�ѹ��Ϣ 0x18F208F3 // 0x18F209F3
extern unsigned int  BAT_Min_Cell_Voltage[4]; //��ص���͵�ѹ
extern unsigned char BAT_Min_Cell_Voltage_Cell_Case[4]; //��͵����ѹ���
extern unsigned char BAT_Min_Cell_Voltage_Cell_Number[4]; //��͵����ѹλ��

//�������¶���Ϣ ID:0x18F20AF3
extern unsigned int  BAT_Max_Cell_Temperature[4]; //��ߵ����¶�
extern unsigned char BAT_Max_Cell_Temp_Cell_Case[4]; //��ߵ����¶����

//�������¶���Ϣ ID:0x18F20BF3
extern unsigned int  BAT_Min_Cell_Temperature[4]; //��͵����¶�
extern unsigned char BAT_Min_Cell_Temp_Cell_Case[4]; //��͵����¶����

//��ؼ����¶���Ϣ
extern unsigned char BAT_Pole_Temperature_P[16];//�������¶�
extern unsigned char BAT_Pole_Temperature_N[16];//�������¶�

//�����������״̬ ID:0x185017F3
extern DATA_BIT      BMU_Comm_Status[4]; //���������״̬
extern unsigned char BMS_Unit_Number;    //��������

//����������Ϣ 1������������ ID: 0x18F20CF3
extern unsigned char BAT_Productor;     //�����������
extern unsigned char BAT_Ahr;           //��ض����
extern unsigned char BAT_Voltage;       //��ض��ѹ
extern unsigned int  BAT_Charge_Times;  //��س�����
extern unsigned char BAT_Material;      //��ز���
extern unsigned char BAT_Time_Month;    //��������·�
extern unsigned char BAT_Time_Year;     //����������
extern unsigned char BAT_Verison;       //BMS����汾��

//��Ե����� ID:0x18FF2B49
extern unsigned char Oum_Status;  //��Ե�����״̬
extern unsigned char Oum_Warn;    //��Ե����Ǳ���
extern unsigned int  Oum;         //��Ե��ֵ
extern unsigned int  Oum_Voltage; //��Ե��ֵ
extern unsigned char Oum_Life;    //��Ե�����LIFE

//����������״̬��Ϣ 1 ID:0x18F101D0
extern DATA_DOUBLE   VCU_Status;  
extern unsigned int  VCU_SPEED;
extern unsigned char VCU_Gear;
extern unsigned char VCU_Clutch;
extern DATA_BIT      VCU_Fault;
extern unsigned char VCU_Code;
extern unsigned char VCU_CarMode;
extern unsigned char VCU_Life;

//����������״̬��Ϣ 2 ID:0x18F103D0
extern unsigned char VCU_Verison;
extern unsigned int  VCU_KM;
extern unsigned char VCU_TM_Speed_percent; //����̤�忪��
extern unsigned char VCU_TM_Brake_percent; //�ƶ�̤�忪��
extern unsigned char VCU_Kwh_100Km;

//VCU ʹ�ܿ��� ID:0x18F105D0
extern DATA_BIT      VCU_Enable[4];

//��ѹ��״̬��Ϣ ID:0x18F106D0
extern DATA_BIT      VCU_KT_Control;
extern DATA_BIT      VCU_KT_Status;
extern DATA_BIT      BMS_KT_Status;

//���������״̬��Ϣ 1 ID:0x18F501F0
extern unsigned char MCU_Temp; //����¶�
extern unsigned char MCU_Control_Temp; //����������¶�
extern unsigned int  MCU_Voltage; //���ĸ�ߵ�ѹ
extern unsigned char MCU_SelfStatus; //����Լ�״̬
extern unsigned char MCU_Status; //���״̬
extern DATA_BIT      MCU_Fault;
extern unsigned char MCU_Code;   //���������

//���������״̬��Ϣ 2 ID:0x18F502F0
extern unsigned int  MCU_RPM;         //���ת��
extern unsigned int  MCU_NM;          //���Ť��
extern unsigned int  MCU_POWER;       //�������
extern unsigned int  MCU_Current;     //�������

//���������״̬��Ϣ 3 ID:0x18F503F0
extern unsigned int  MCU_Output_Voltage; //��������ѹ
extern unsigned int  MCU_Phase_Current;  //��������

//�����ͱ÷��ͱ���״̬ ID 0x0CF601A0
extern unsigned int  OILDCAC_Voltage;   //DCAC�����ѹ
extern unsigned char OILDCAC_Current;   //DCAC�������
extern unsigned char OILDCAC_Temp;      //DCAC����¶�
extern DATA_BIT      OILDCAC_Status;    //DCAC����״̬
extern unsigned char OILDCAC_Life;      //DCAC Life
   
//DC/DC ���ͱ���״̬ ID 0x0CF602A1
extern unsigned char DCDC_Status;         //DCDC����״̬
extern unsigned char DCDC_Output_Current; //DCDC�������
extern unsigned char DCDC_Output_Voltage; //DCDC�����ѹ
extern unsigned char DCDC_Temp;           //DCDCģ���¶�
extern DATA_BIT      DCDC_Fault_Warn;     //DCDC���ϱ���
extern unsigned int  DCDC_Input_Voltage;  //DCDC�����ѹ
extern unsigned char DCDC_Life;           //DCDC Life

//���÷��ͱ���״̬ ID 0x0CF603A2
extern unsigned int  AIRDCAC_Voltage;   //DCAC�����ѹ
extern unsigned char AIRDCAC_Current;   //DCAC�������
extern DATA_BIT      AIRDCAC_Status;    //DCAC����״̬
extern unsigned char AIRDCAC_Temp;      //DCAC����¶�
extern unsigned char AIRDCAC_Life;      //DCAC Life

//�յ����Ʊ���״̬ ID 0x0CF605A3
extern unsigned char AC_Status;   //
extern unsigned char AC_Indoor_Temp; 
extern unsigned char AC_Gear; 
extern unsigned char AC_WindMode; 
extern unsigned char AC_Work_Status; 
extern unsigned char AC_Outdoor_Temp; 
extern unsigned char AC_Fault_Code; 
extern unsigned char AC_Life; 

extern unsigned char AC_Set_Temp; 
*/
//ID(0x0C008980)
extern unsigned int  VCU_Motor_Front_Voltage;    //���������ǰ�˵�ѹ
extern unsigned int  VCU_Motor_Rear_Voltage;     //�����������˵�ѹ
extern unsigned int  VCU_Motor_DC_Current;       //���������ֱ������
extern unsigned int  VCU_Motor_RPM;  

//ID(0x0C018980)    
extern unsigned char VCU_Speed_percent;          //����̤�忪��
extern unsigned char VCU_Brake_percent;          //�ƶ�̤�忪��
extern DATA_BIT      VCU_Power_System_Status;    //����ϵͳ״̬
extern unsigned char VCU_Gear;                   //��λ
extern unsigned char VCU_KT;                     //���Ӵ���״̬
extern unsigned char VCU_KC;                     //Ԥ��Ӵ���
extern unsigned char VCU_Motor_Temp;             //����¶�
extern unsigned char VCU_Motor_Control_Temp;     //����������¶�
extern unsigned char VCU_Motor_Code;             //���������
extern unsigned char VCU_Life;                   //����������Life

//ID(0x0C028980)
extern DATA_BIT      VCU_Output_Status;          //�������״̬
extern unsigned int  VCU_Motor_Brake_Current;    //����ƶ�����
extern unsigned int  VCU_Motor_Torque;           //���ʵ��ת��
extern unsigned char VCU_Motor_Number;           //�������
extern unsigned char VCU_Motor_Sequence_Number;  //������
extern unsigned char VCU_Motor_Status;           //���״̬

//ID(0x0C038980)
extern DATA_DOUBLE   VCU_Run_Mode;               //����ģʽ
extern DATA_BIT      VCU_Warn;                   //��������
extern unsigned char VCU_Fault_Number_BAT;       //��ع�������
extern unsigned char VCU_Fault_Number_Motor;     //��ع�������
extern unsigned char VCU_Fault_Number_Other;     //��ع�������

//ID��0x18FF12F7��
extern unsigned int  DCDC_Output_Voltage;        //DCDC�����ѹ
extern unsigned int  DCDC_Output_Current;        //DCDC�����ѹ
extern unsigned char DCDC_Work_Status;           //DCDC����״̬
extern DATA_BIT      DCDC_Fault_Code;            //DCDC���ϴ���

//ID��0x18019888��
extern unsigned int  OILDCAC_Output_Voltage;     //�ͱ�DCAC�����ѹ
extern unsigned int  OILDCAC_Output_Current;     //�ͱ�DCAC�����ѹ
extern unsigned char OILDCAC_Temp;               //�ͱ�DCACɢ�������¶�
extern DATA_BIT      OILDCAC_Code;               //�ͱ�DCAC���ϴ���

//ID��0x1805A89C��
extern unsigned int  AIRDCAC_Input_Voltage;      //����DCAC�����ѹ
extern unsigned int  AIRDCAC_Output_Voltage;     //����DCAC�����ѹ
extern unsigned int  AIRDCAC_Output_Current;     //����DCAC�����ѹ
extern unsigned char AIRDCAC_Temp;               //����DCACɢ�������¶�
extern DATA_BIT      AIRDCAC_Code;               //����DCAC���ϴ���

//ID(0x18F0010B)
extern unsigned char ABS_Active;                 //ABS״̬

//BMS���͵�һ�飬ID=0x0CFF7D03
extern unsigned char BMS_Life;                   //BMS Life
extern unsigned char BMS_Fault_Level;            //BMS���ϵȼ�
extern unsigned char BMS_Charge;                 //��ŵ�״̬
extern unsigned char BMS_SOC;                    //���SOC
extern unsigned char BAT_Max_Cell_Voltage_Cell_Number; //��ߵ����ѹλ��
extern unsigned int  BAT_Max_Cell_Voltage;       //��ص���ߵ�ѹ
extern unsigned char BAT_Min_Cell_Voltage_Cell_Number; //��͵����ѹλ��
extern unsigned int  BAT_Min_Cell_Voltage;       //��ص���͵�ѹ

//BMS���͵ڶ��飬ID=0x0CFF7E03
extern unsigned char BMS_Precharge;              //Ԥ���״̬
extern unsigned char BMS_HighVoltage_Status;     //��ѹ����״̬
extern unsigned char BMS_Check;                  //BMS�Լ�
extern unsigned char BMS_SOH;                    //BMS SOH
extern unsigned int  BMS_V;                      //��ص�ѹ
extern unsigned int  BMS_A;                      //��ص���
extern unsigned int  BAT_Max_Cell_Temperature;   //��ߵ����¶�
extern unsigned int  BAT_Min_Cell_Temperature;   //��͵����¶�

//BMS���͵����飬ID=0x0CFF7F03
extern DATA_BIT      BMS_Status1;                //BMS״̬1
extern unsigned char BMS_Charging;               //BMS��ŵ�״̬
extern DATA_DOUBLE   BMS_Status2;                //BMS״̬2
extern unsigned char BMS_Humidity;               //BMSʪ��
extern unsigned char BMS_Current_Charge_Limit_Long; //�����ó�����繦�ʣ�30min��
extern unsigned char BMS_Current_Charge_Limit_Short;//�����ö�ʱ��繦�ʣ�30s��
extern unsigned char BMS_Current_Disharge_Limit_Long;     //�����ó����ŵ繦�ʣ�30min��
extern unsigned char BMS_Current_Disharge_Limit_Short;    //�����ö�ʱ�ŵ繦�ʣ�30s��
extern unsigned int  Oum;                                 //��Ե��ֵ

//BMS���͵����飬ID=0x0CFF8003
extern unsigned char BMS_Fault1[20];                //BMS�༶����
#define  Diff_Temp                 BMS_Fault1[0]    //�¶Ȳ������
#define  Diff_Voltage              BMS_Fault1[1]    //�����ѹ�������
#define  Temp_High                 BMS_Fault1[2]    //�¶ȹ��߹���
#define  Single_Bat_OverVoltage    BMS_Fault1[3]    //�����ѹ����
#define  Single_Bat_UnderVoltage   BMS_Fault1[4]    //����Ƿѹ����
#define  Pack_Bat_OverVoltage      BMS_Fault1[5]    //������ѹ����
#define  Pack_Bat_UnderVoltage     BMS_Fault1[6]    //�����Ƿѹ����
#define  OverCharge_Fault          BMS_Fault1[7]    //����������
#define  OverDisharge_Fault        BMS_Fault1[8]    //�ŵ��������
#define  SOC_High                  BMS_Fault1[9]    //SOC���߹���
#define  SOC_Low                   BMS_Fault1[10]    //SOC���͹���
#define  Insulation_Fault          BMS_Fault1[11]    //��Ե����
#define  Bat_LowTemp               BMS_Fault1[12]    //�ŵ��¶ȹ���
#define  DC_Charge_Gun_OverTemp    BMS_Fault1[13]    //ֱ�����ǹ�¶ȹ���
#define  AC_Charge_Gun_OverTemp    BMS_Fault1[14]    //�������ǹ�¶ȹ���

//BMS_Fault1[1]    �����ѹ�������
//BMS_Fault1[2]    �¶ȹ��߹���
//BMS_Fault1[3]    �����ѹ����
//BMS_Fault1[4]    ����Ƿѹ����
//BMS_Fault1[5]    ������ѹ����
//BMS_Fault1[6]    �����Ƿѹ����
//BMS_Fault1[7]    ����������
//BMS_Fault1[8]    �ŵ��������
//BMS_Fault1[9]    SOC���߹���
//BMS_Fault1[10]   ��Ե����
//BMS_Fault1[11]   �ŵ��¶ȹ���
//BMS_Fault1[12]   ֱ�����ǹ�¶ȹ���
//BMS_Fault1[13]   �������ǹ�¶ȹ���
extern DATA_BIT      BMS_Fault2[3];               //BMS��������
#define  BAT_CELL_COLT_OFFLINE       BMS_Fault2[0].bit3    //�ɼ����߹���
#define  BAT_CELL_MODULE_FAULT       BMS_Fault2[0].bit4    //�ɼ�ģ�����
#define  BAT_CELL_Voltage_BREAK      BMS_Fault2[0].bit5    //�����ѹ����
#define  TEMP_COLT_OFFLINE           BMS_Fault2[0].bit6    //�����¶ȶ���
#define  VCU_COMM_OFFLINE            BMS_Fault2[0].bit7    //VCU���߹���
#define  HUOER_OFFLINE               BMS_Fault2[0].bit8    //�������߹���
#define  INSIDE_COMM_OFFLINE         BMS_Fault2[1].bit1    //�ڲ�ͨѶ����
#define  CHARGER_COMM_FAULT          BMS_Fault2[1].bit2    //�����ͨѶ����
#define  Box_Kt_FAULT                BMS_Fault2[2].bit1    //���ڽӴ�������
#define  Charge_Kt_FAULT             BMS_Fault2[2].bit2    //���Ӵ�������
#define  WARN_Kt_FAULT               BMS_Fault2[2].bit3    //���ȽӴ�������

//�������ǹ��ֱ�����ǹ�¶���ʾID=0x18FFDE03
extern unsigned char BMS_DC_ChargeGun_PT;         //ֱ�����ǹ�����¶�
extern unsigned char BMS_DC_ChargeGun_NT;         //ֱ�����ǹ�����¶�
extern unsigned char BMS_AC_ChargeGun_Temp;       //�����ǹ�¶�

//BMS���͵����飬ID=0x0CFF8103
extern unsigned char BAT_Max_Cell_Voltage_Cell_Case; //��ߵ����ѹ���
extern unsigned char BAT_Min_Cell_Voltage_Cell_Case; //��͵����ѹ���
extern unsigned char BAT_Max_Cell_Temp_Cell_Case;    //��ߵ����¶����
extern unsigned char BAT_Max_Cell_Temp_Cell_Number;  //��ߵ����ѹλ��
extern unsigned char BAT_Min_Cell_Temp_Cell_Case;    //��͵����¶����
extern unsigned char BAT_Min_Cell_Temp_Cell_Number;  //��ߵ����ѹλ��
extern DATA_BIT      BMS_Warn[2]; 

//BMS���͵����飬ID=0x0CFF8203���ɳ�索��װ�õ�ѹ���ݣ�
extern unsigned char BMS_System_Number;
extern unsigned char BMS_System_SequenceNumber;
extern unsigned int  BMS_System_Voltage;
extern unsigned int  BMS_System_Current;
extern unsigned char BMS_BAT_Number;

//BMS���͵ڰ��飬ID=0x0CFF8303
extern unsigned char BMS_System_Temp_Number;
extern unsigned char BMS_System_Fault_Number;

//BMS���͵����ѹ��ѡ�ã�0x18(00~FF)DC03
extern unsigned int  BAT_Single_Voltage[200];
extern unsigned char BAT_Single_Temp[200];



void DM(unsigned char x, DM1 id);

#endif	/* APP_CAN2_RECEIVE_H */

