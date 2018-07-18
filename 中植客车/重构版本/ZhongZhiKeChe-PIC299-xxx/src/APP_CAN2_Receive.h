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
extern DM1 CAN_18FECAD0;
extern unsigned char CAN_18FECAD0_len;

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

extern unsigned long SPN[5]; //�ӻ�������ȡ�Ĺ�����
extern unsigned char FMI[5];
/*******************�ְ�����*****************/
/*************************************/
//������������Ϣ1 0x0CFFC9D0
extern unsigned char VCU_Status;
extern unsigned char VCU_Gear;
extern unsigned char VCU_Lock_Warn;
extern unsigned char VCU_Brake_Warn;
extern unsigned char VCU_Car_Status;
extern unsigned char VCU_Run_Status;
extern unsigned int  VCU_Speed;
extern unsigned char VCU_Gearbox;
extern unsigned char VCU_Brake_Status;
extern unsigned char VCU_Power_Status;
extern unsigned char VCU_Charge;
extern unsigned char VCU_Warn_Level;

//������������Ϣ2 0x0CFFC8D0
extern unsigned char VCU_Accelerator_percent; //����̤�忪��
extern unsigned char VCU_Brake_percent; //�ƶ�̤�忪��
extern unsigned char VCU_Fault_Number; //������������
extern unsigned long VCU_Fault_List; //�����б�
extern unsigned char VCU_Motor_Number; 

//����������������Ϣ 3��0x0CFFCAD0��
/*unsigned char VCU_Control_OCU;
unsigned char VCU_Control_ACU;
unsigned char VCU_Control_DCDC;
unsigned char VCU_Control_AIR;*/

//����״̬ 1��0x18F501F0��
extern unsigned char MCU_Number;
extern unsigned char MCU_Status;
extern unsigned char MCU_Temp;
extern unsigned char MCU_Controller_Temp;
extern unsigned int  MCU_Voltage;
extern unsigned int  MCU_Curretn;

//����״̬ 2��0x18F502F0��
extern unsigned int  MCU_Rpm;
extern unsigned int  MCU_Torque;

//����״̬ 3��0x18F503F0��
extern unsigned char MCU_Controller_Warn_Temp;
extern unsigned char MCU_Warn_Temp;
extern unsigned char MCU_Warn_Number;

//ϵͳ������Ϣ��0x18FECAD0��

//��ع���ϵͳ��Ϣ 1��0x18F201F3��
extern unsigned char BMS_SOC;
extern unsigned int  BMS_Voltage; //����ܵ�ѹ
extern unsigned int  BMS_Current; //����ܵ���
extern unsigned char BMS_Charge_Power_Limt; 
extern unsigned char BMS_Discharge_Power_Limt; 
extern unsigned char BMS_Life; 

//��ѹ�Ӵ�����Ϣ��0x18F202F3��
extern DATA_DOUBLE   CM_Connecter_Status[2];
extern unsigned char CM_Up_Status;
extern unsigned char CM_Down_Status;

//��ر�����Ϣ��0x18F203F3��
extern unsigned char BMS_Fault_Code;
extern unsigned char BMS_Fault_Level;
extern DATA_BIT      BMS_Charge_Status;
extern unsigned char BMS_Self_Status;
extern DATA_BIT      BMS_Warn_Message[4];

//��زֻ��ֱ�����Ϣ��0x18F209F3��
extern DATA_BIT      BCEM_Warn_Message[8];

//��زֻ��ֱ����¶���Ϣ��0x18F20AF3��
extern unsigned char BCTM_Temp[8];

//��ص����ѹ��Ϣ��0x18F204F3��
extern unsigned int  Battery_Single_H; //��ص���ߵ�ѹ
extern unsigned int  Battery_Single_L; //��ص���͵�ѹ
extern unsigned char Battery_Single_H_Positon_Case; //��ص���ߵ�ѹ���
extern unsigned char Battery_Single_H_Positon_Cell; //��ص���ߵ�ѹλ��
extern unsigned char Battery_Single_L_Positon_Case; //��ص���͵�ѹ���
extern unsigned char Battery_Single_L_Positon_Cell; //��ص���͵�ѹλ��

//��ص����¶���Ϣ��0x18F205F3��
extern unsigned char Battery_Temp_H; //��ص�������¶�
extern unsigned char Battery_Temp_L; //��ص�������¶�
extern unsigned char Battery_Temp_H_Positon_Case; //��ص�����¶����
extern unsigned char Battery_Temp_H_Positon_Cell; //��ص�����¶�λ��
extern unsigned char Battery_Temp_L_Positon_Case; //��ص�����¶����
extern unsigned char Battery_Temp_L_Positon_Cell; //��ص�����¶�λ��

//��Ե�������Ϣ��0x18FF2B49��
extern unsigned char IDE_Message;
extern unsigned int  IDE_Ohm;
extern unsigned int  IDE_Voltage;
extern unsigned char IDE_Life;

//����ϵͳ��Ϣ
extern unsigned char ACU_Status; //���ÿ���������״̬
extern unsigned char ACU_Fault_Code; //���ÿ�����������
extern unsigned char ACU_Power; //���ÿ���������
extern unsigned char ACU_Temp; //���õ���¶�
extern unsigned char ACU_Controller_temp; //���ÿ������¶�
extern unsigned int  ACU_Voltage; //���ÿ�����ĸ�ߵ�ѹ
extern unsigned int  ACU_Rpm; //���ÿ��������ת��

//�ͱ�ϵͳ��Ϣ
extern unsigned char OCU_Status; //���ÿ���������״̬
extern unsigned char OCU_Fault_Code; //���ÿ�����������
extern unsigned char OCU_Power; //���ÿ���������
extern unsigned char OCU_Temp; //���õ���¶�
extern unsigned char OCU_Controller_temp; //���ÿ������¶�
extern unsigned int  OCU_Voltage; //���ÿ�����ĸ�ߵ�ѹ
extern unsigned int  OCU_Rpm; //���ÿ��������ת��

//DCDCϵͳ��Ϣ
extern unsigned char DCDC_Status; //DCDC����״̬
extern unsigned char DCDC_CAN_Warn; //DCDCͨѶ����
extern unsigned char DCDC_Temp_Warn; //DCDC�¶ȱ���
extern unsigned char DCDC_Status_Warn; //DCDC״̬����
extern unsigned char DCDC_Fault_Code; //DCDC���ϴ���
extern unsigned char DCDC_Temp; //DCDCģ���¶�
extern unsigned int  DCDC_Current; //DCDC�������
extern unsigned char DCDC_Output_Voltage; //DCDC�����ѹ
extern unsigned int  DCDC_Voltage; //DCDCĸ�ߵ�ѹ

void DM(unsigned char x, DM1 id,unsigned char i);

#endif	/* APP_CAN2_RECEIVE_H */

