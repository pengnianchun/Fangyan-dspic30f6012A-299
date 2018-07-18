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
        unsigned VCUFaultCode; //VCU���ϴ���
        unsigned char AcceleratePedal;//����̤��
        unsigned char BrakePedal;//�ƶ�̤��
        unsigned char VCUSpeed;//VCU���ͳ���
        DATA_BIT VCUStatus1;
        DATA_BIT VCUStatus2;
        unsigned char VCUGear : 4;//VCU��λ
        unsigned char VCULife : 4;//VCULife
    };
    unsigned char byte[8];
} _CAN_0x0CFF045A;

typedef union {

    struct {
        unsigned Mile; //��ʻ���
        unsigned char MotorTemperature_Controller; //����������¶�
        unsigned char MotorTemperature; //����¶�
        unsigned MotoSpeed; //���ת��      
        unsigned char LockStatus; //��������״̬
        unsigned char Reserve : 4;//
        unsigned char VCULife : 4;//VCULife
    };
    unsigned char byte[8];
} _CAN_0x0CFF055A;

typedef union {
    
    struct {
        unsigned char VCU_Enabled : 1;//ʹ��
        unsigned char VCU_Fault_Reset : 1;//��������
        unsigned char VCU_Control_Model : 2;//����ģʽ
        unsigned char VCU_Life : 4;//VCUlife
        unsigned char VCU_Gear;//��λ
        unsigned VCU_Target_Torque;//Ŀ��ת��
        unsigned VCU_Target_Rotate_Speed;//Ŀ��ת��
        unsigned char Reserve1;//����
        unsigned char Reserve2;//����
    };
    unsigned char byte[8];
} _CAN_0x0CFF015A;

typedef union {
    
    struct {
        unsigned VCU_Drive_Torque_Limit;//����Ť����ֵ
        unsigned VCU_Brake_Torque_Limit;//�ƶ�Ť����ֵ
        unsigned VCU_Rotate_Speed_Forwardlimit;//ת��������ֵ
        unsigned VCU_Rotate_Speed_Invertlimit;//ת�ٷ�����ֵ
    };
    unsigned char byte[8];
} _CAN_0x0CFF025A;

typedef union {
    
    struct {
        unsigned MCU_Feedback_Rotate_Speed;//����ת��
        unsigned MCU_Feedback_Torque;//����ת��
        unsigned MCU_AlterCurrent_Effect;//����������Чֵ
        unsigned char Reserve1 : 4;//����
        unsigned char MCU_Allow_Precharge : 1;//����Ԥ��
        unsigned char MCU_DischargeStatus_Feedback : 1;//�����ŵ�״̬����
        unsigned char MCU_IGBTEnabledStatus_Feedback : 1;//IGBTʹ��״̬����
        unsigned char Reserve2 : 1;//����
        unsigned char MCU_WorkStatus_Feedback : 4;//����״̬����
        unsigned char MCU_Life : 4;//MCU_Life
    };
    unsigned char byte[8];
} _CAN_0x18FF115B;

typedef union {
    
    struct {
        unsigned char MCU_MotorTemp;//����¶�
        unsigned char MCU_ContorlTemp;//�������¶�
        unsigned MCU_Torque_Toplimit;//ת������
        unsigned MCU_Torque_Lowlimit;//ת������
        unsigned char MCU_FaultLevel : 4;//���ϵȼ�
        unsigned char MCU_DirveMotorStatus : 4;//�������״̬
        unsigned char MCU_Motor_ControlOverHeat : 1;//�������������
        unsigned char MCU_MotorOverHeat : 1;//�������
        unsigned char Reserve : 2;//����
        unsigned char MCU_Life : 4;//MCU_Life
    };
    unsigned char byte[8];
} _CAN_0x18FF125B;

typedef union {
    
    struct {
        unsigned MCU_Current;//ֱ������
        unsigned MCU_Voltage;//ֱ����ѹ
        unsigned char MCU_FaultCode;//������
        
        unsigned char MCU_PhaseCurrentFault : 1;//���������
        unsigned char MCU_InventerFault : 1;//���������
        unsigned char MCU_SensorPowerFault : 1;//�������������
        unsigned char MCU_MotorSensorFault : 1;//���λ�ô���������
        unsigned char MCU_CurrentOverVoltageFault: 1;//ֱ��ĸ�߹�ѹ����
        unsigned char MCU_CurrentUnderVoltageFault : 1;//ֱ��ĸ��Ƿѹ����
        unsigned char MCU_MotorOverHeatFault : 1;//������¹���
        unsigned char MCU_InventerOverHeatFault : 1;//��������¹���
        
        unsigned char MCU_MotorOverSpeedWarning : 1;//������ٹ���
        unsigned char MCU_PhaseCurrentWarning : 1;//�������������
        unsigned char MCU_MotorTempWarning : 1;//����¶ȱ���
        unsigned char MCU_InventerTempWarning : 1;//������¶ȱ���
        unsigned char CAN_Disconnect : 1;//CAN���߶Ͽ�
        unsigned char MCU_LowVoltageDCFault : 1;//��ѹֱ����Դ����
        unsigned char MCU_Fault : 1;//MCU����
        unsigned char MCU_MotorCtrlModelError : 1;//���������ģʽ����
        
        unsigned char Reserve : 4;//����
        unsigned char MCU_Life : 4;//MCU_Life
    };
    unsigned char byte[8];
} _CAN_0x18FF135B;

typedef union {
    
    struct {
        unsigned char BMS_HighVoltageCommand;//��ѹ���µ�ָ��
        unsigned char BMS_Life;//BMS_Life
        unsigned BMS_MotorCtrlVoltage;//���������ĸ�ߵ�ѹ
        unsigned BMS_MotorCtrlCurrent;//���������ĸ�ߵ���
        unsigned char Reserve1;//����
        unsigned char Reserve2;//����
    };
    unsigned char byte[8];
} _CAN_0x0CFF035A;

typedef union {
    
    struct {
        unsigned char BMS_HighVoltage;//��ѹ���µ�
        unsigned char BMS_FaultLevel : 2;//ϵͳ���ϵȼ�
        unsigned char BMS_ChargeModel : 3;//��ŵ�ģʽ
        unsigned char BMS_SelfChecking : 2;//BMS�Լ�״̬
        unsigned char Reserve1 : 1;//����
        unsigned char BMS_Resistance;//���ϵͳ����
        DATA_BIT  BMS_Status;//BMS״̬
        unsigned BMS_Voltage;//������ܵ�ѹ
        unsigned BMS_Current;//������ܵ���
    };
    unsigned char byte[8];
} _CAN_0x18FF015C;

typedef union {
    
    struct {
        unsigned BMS_OutputVoltage;//���������ܵ�ѹ
        unsigned char BMS_SOC;//SOC
        unsigned char BMS_SOH;//SOH
        unsigned char BMS_MAXSustainChargePower;//�����ó�����繦��
        unsigned char BMS_MAXSnatchChargePower;//�����ö�ʱ��繦��
        unsigned char BMS_MAXSustainDischargePower;//�����ó����ŵ繦��
        unsigned char BMS_MAXSnatchDischargePower;//�����ö�ʱ�ŵ繦��
    };
    unsigned char byte[8];
} _CAN_0x18FF025C;

typedef union {
    
    struct {
        unsigned char BMS_DumpEnergy;//���������ܵ�ѹ
        unsigned char BMS_Cell_Average_Temp;//SOC
        unsigned char BMS_Cell_Max_Temp;//SOH
        unsigned char BMS_Cell_Min_Temp;//�����ó�����繦��
        unsigned BMS_Cell_Max_Voltage;//�����ö�ʱ��繦��
        unsigned BMS_Cell_Min_Voltage;//�����ó����ŵ繦��
    };
    unsigned char byte[8];
} _CAN_0x18FF035C;

typedef union {
    
    struct {
        unsigned char BMS_Cell_Max_Temp_Num;//�����ߵ����¶ȱ��
        unsigned char BMS_Cell_Min_Temp_Num;//�����͵����¶ȱ��
        unsigned char BMS_Cell_Max_Voltage_Num;//�����ߵ����ѹ���
        unsigned char BMS_Cell_Min_Voltage_Num;//�����͵����ѹ���
        unsigned char BMS_ChargingGun_Anode_Temp;//ֱ�����ǹ�����¶�
        unsigned char BMS_ChargingGun_Cathode_Temp;//ֱ�����ǹ�����¶�
        unsigned char BMS_AlterCurrent_ChargingGun_Temp;//�������ǹ�¶�
        unsigned char Reserve;//����
    };
    unsigned char byte[8];
} _CAN_0x18FF045C;

typedef union {
    
    struct {
        unsigned BMS_Insulation_Resistance;//��Ե����ֵ
        DATA_BIT BMS_VoltageFault;//��ص�ѹ��ع���
        DATA_BIT BMS_TempFault;//����¶���ع���
        DATA_BIT BMS_SOCFault;//��缰soc��ع���
        DATA_BIT BMS_FaultList;//�����б�
        unsigned char BMS_Intercom : 1;//�ڲ�ͨѶ����
        unsigned char Reserve1 : 7;//����
        unsigned char Reserve2;//����
    };
    unsigned char byte[8];
} _CAN_0x18FF055C;

typedef union {

	 struct {
		unsigned char BMS_Max_Voltage_Num;//��ߵ�ѹ�����ϵͳ��
        unsigned char BMS_Min_Voltage_Num;//��͵�ѹ�����ϵͳ��
        unsigned char BMS_Max_Temp_Num;//����¶���ϵͳ��
        unsigned char BMS_Max_Temp_ProbeNum;//����¶�̽�����
        unsigned char BMS_Min_Temp_Num;//����¶���ϵͳ��
        unsigned char BMS_Min_Temp_ProbeNum;//����¶�̽�����
        DATA_BIT BMS_Warning;//�����ر���
	    DATA_BIT BMS_Warning1;//�����ر���
	 };
     unsigned char byte[8];
}_CAN_0x18FF065C;

typedef union {

	 struct {
		unsigned char BMS_StoredEnergySYS_NUM;//�ɳ�索����ϵͳ����
        unsigned char BMS_StoredEnergySYS_Num;//�ɳ�索����ϵͳ��
        unsigned char BMS_Cell_NUM;//����������
        unsigned char BMS_StoredEnergyTempProbe_NUM;//�ɳ�索���¶�̽�����
        unsigned char BMS_BMS_StoredEnergyFault_NUM;//�ɳ�索��װ�ù�������
        unsigned char Reserve1;//����
        unsigned char Reserve2;//����
	    unsigned char Reserve3;//����
	 };
	 unsigned char byte[8];
}_CAN_0x18FF075C;

typedef union {

	 struct {
		unsigned BMS_Cell1_Voltage;//�����ص�ѹ
        unsigned BMS_Cell2_Voltage;
        unsigned BMS_Cell3_Voltage;
        unsigned BMS_Cell4_Voltage;
	 };
	 unsigned char byte[8];
}_CAN_Cell_Voltage;

typedef union {

	 struct {
		unsigned char BMS_Cell1_Temp;//�������¶�
        unsigned char BMS_Cell2_Temp;
        unsigned char BMS_Cell3_Temp;
        unsigned char BMS_Cell4_Temp;
        unsigned char BMS_Cell5_Temp;
        unsigned char BMS_Cell6_Temp;
        unsigned char BMS_Cell7_Temp;
	    unsigned char BMS_Cell8_Temp;
	 };
	 unsigned char byte[8];
}_CAN_Cell_Temp;

typedef union {

	 struct {
		unsigned DCDC_Input_Voltage;//�����ѹ
        unsigned char DCDC_Input_Current;//�������
        unsigned char DCDC_Output_Voltage;//�����ѹ
        unsigned char DCDC_Output_Current;//�������
        unsigned char DCDC_CtrlTemp;//�������¶�
        unsigned char DCDC_CtrlPrechargeStatus : 1;//������Ԥ��״̬
        unsigned char Reserve : 1;//����
	    unsigned char DCDC_Status : 2;//DCDC״̬
        unsigned char DCDC_FaultCode : 4;//������
        unsigned char DCDC_Life;//DCDC_Life
	 };
	 unsigned char byte[8];
}_CAN_0x0CFF016B;

typedef union {

	 struct {
		unsigned DCDC_PumpMotorRotateSpeed;//���ת��
        unsigned DCDC_PumpCtrlVoltage;//������ĸ�ߵ�ѹ
        unsigned char DCDC_PumpCtrlCurrent;//����������
        unsigned char DCDC_PumpCtrlTemp;//���ÿ������¶�
        unsigned char DCDC_PumpCtrlPrechargeStatus : 1;//������Ԥ��״̬
        unsigned char Reserve : 1;//����
        unsigned char DCDC_PumpStatus : 2;//����״̬
	    unsigned char DCDC_PumpFaultCode : 4;//���ù�����
        unsigned char DCDC_PumpLife;//DCDC����Life
	 };
	 unsigned char byte[8];
}_CAN_0x0CFF026B;

typedef union {

	 struct {
		unsigned DCDC_OilPumpMotorRotateSpeed;//���ת��
        unsigned DCDC_OilPumpCtrlVoltage;//������ĸ�ߵ�ѹ
        unsigned char DCDC_OilPumpCtrlCurrent;//����������
        unsigned char DCDC_OilPumpCtrlTemp;//�ͱÿ������¶�
        unsigned char DCDC_OilPumpCtrlPrechargeStatus : 1;//������Ԥ��״̬
        unsigned char DCDC_OilPumpCtrlCtrledStatus : 1;//�������ܿ�״̬
        unsigned char DCDC_OilPumpStatus : 2;//�ͱ�״̬
	    unsigned char DCDC_OilPumpFaultCode : 4;//�ͱù�����
        unsigned char DCDC_OilPumpLife;//DCDC�ͱ�Life
	 };
	 unsigned char byte[8];
}_CAN_0x0CFF036B;

typedef union {

	 struct {
		unsigned char DCDC_OilPumpOutputVoltageHZ;//�ͱÿ����������ѹ��Ƶ��
        unsigned char DCDC_PumpOutputVoltageHZ;//���ÿ����������ѹ��Ƶ��
        unsigned char DCDC_PowerCommand;//DCDC��Դ��������
        unsigned char DCDC_OilPumpCtrlCommand;//�ͱÿ�������������
        unsigned char DCDC_PumpCtrlCommand;//���ÿ�������������
        unsigned char Reserve1;//����
        unsigned char Reserve2;//����
	    unsigned char Reserve3;//����
	 };
	 unsigned char byte[8];
}_CAN_0x0CFF065A;

typedef union {

	 struct {
		unsigned char VCU_VehicleStatus;//����״̬
        unsigned char VCU_ChargingStatus;//���״̬
        unsigned char VCU_RunModel;//����ģʽ
        unsigned Speed;//����
        unsigned char SOC;//SOC
        unsigned char DCDC_Status;//DCDC״̬
        unsigned char Gear : 4;//��λ
	    unsigned char BrakePower : 1;//�ƶ���
        unsigned char DrivePower : 1;//������
        unsigned char Reserve : 2;//
	 };
	 unsigned char byte[8];
}_CAN_0x18FF015A;

typedef union {

	 struct {
		unsigned long VCU_Odometer;//�ۼ����
        unsigned  VCU_Voltage;//�ܵ�ѹ
        unsigned  VCU_Current;//�ܵ���
	 };
	 unsigned char byte[8];
}_CAN_0x18FF025A;

typedef union {

	 struct {
		unsigned VCU_Insulation_Resistance;//��Ե����
        unsigned char VCU_Accelerator_Pedal;//����̤���г�ֵ
        unsigned char VCU_Brake_PedalStatus;//�ƶ�̤��״̬
        unsigned VCU_NMotorCtrlInputVoltage;//N�ŵ�������������ѹ
        unsigned VCU_NMotorCtrlCurrent;///N�ŵ��������ֱ��ĸ�ߵ���
	 };
	 unsigned char byte[8];
}_CAN_0x18FF035A;

typedef union {

	 struct {
		unsigned char VCU_DriverMotor_NUM : 4;//�����������
        unsigned char VCU_DriverMotor_Num: 4;//����������N
        unsigned char VCU_NDriverMotorStatus;//N���������״̬
        unsigned char VCU_NDriverCtrl_Temp;//N����������������¶�
        unsigned VCU_NDriverMotorRotateSpeed;//N���������ת��
        unsigned VCU_NDriverMotorTorque;//N���������ת��
        unsigned char VCU_NDriverMotorTemp;//N����������¶�
	 };
	 unsigned char byte[8];
}_CAN_0x18FF045A;

typedef union {

	 struct {
		unsigned char MAXVoltageSYSNum;//��ߵ�ѹ�����ϵͳ��
        unsigned char MAXVoltageCellNum;//��ߵ�ѹ��ص������
        unsigned  CellMAXVoltage;//��ص����ѹ���ֵ
        unsigned char MINVoltageSYSNum;//��͵�ѹ�����ϵͳ��
        unsigned char MINVoltageCellNum;//��͵�ѹ��ص������
        unsigned CellMINVoltage;//��ص����ѹ���ֵ
	 };
	 unsigned char byte[8];
}_CAN_0x18FF055A;

typedef union {

	 struct {
		unsigned char MAXTempSYSNum;//����¶���ϵͳ��
        unsigned char MAXTempProdeNum;//����¶�̽�����
        unsigned char MAXTemp;//����¶�ֵ
        unsigned char MINTempSYSNum;//����¶���ϵͳ��
        unsigned char MINTempProdeNum;//����¶�̽�����
        unsigned char MINTemp;//����¶�ֵ
        unsigned char Reserve1;//����
	    unsigned char Reserve2;//����
	 };
	 unsigned char byte[8];
}_CAN_0x18FF065A;

typedef union {

	 struct {
		unsigned char HighestWarningLevel;//��߱����ȼ�
        DATA_BIT Warning1;//�����ź�
        DATA_BIT Warning2;//�����ź�
        unsigned char Warning3 : 3;//�����ź�
        unsigned char Reserve1 : 5;//����
        unsigned char Reserve2;//����
        unsigned char Reserve3;//����
	    unsigned char Reserve4;//����
        unsigned char Reserve5;//����
	 };
	 unsigned char byte[8];
}_CAN_0x18FF075A;

typedef union {

	 struct {
		unsigned char AnodeCocontactorCtrlCommand;//�����Ӵ�����������
        unsigned char CathodeCocontactorCtrlCommand;//�����Ӵ�����������
        unsigned char PrechargeCocontactorCtrlCommand;//Ԥ��Ӵ�����������
        unsigned char RapidChargeCocontactorCtrlCommand;//���Ӵ�����������
        unsigned char TrickleChargeCocontactorCtrlCommand;//����Ӵ�����������
        unsigned char HeatCocontactorCtrlCommand;//���ȽӴ�����������
        unsigned char AIRCtrlCommand;//�յ���������
	    unsigned char DefrostCtrlCommand;//��˪��������
	 };
	 unsigned char byte[8];
}_CAN_0x0CFF075A;

typedef union {

	 struct {
		unsigned char AnodeCocontactorFeedback;//�����Ӵ�������
        unsigned char CathodeCocontactorFeedback;//�����Ӵ�������
        unsigned char PrechargeCocontactorFeedback;//Ԥ��Ӵ�������
        unsigned char RapidchargeCocontactorFeedback;//���Ӵ�������
        unsigned char TrikclechargeCocontactorFeedback;//����Ӵ�������
        unsigned char HeatCocontactorFeedback;//���ȽӴ�������
        unsigned char AIR;//�յ�
	    unsigned char Defrost;//��˪
	 };
	 unsigned char byte[8];
}_CAN_0x18FF016D;
#endif

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
#pragma pack()

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

