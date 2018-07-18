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
typedef union {

    struct {
        unsigned char moto_voltage; //�����ѹ
        unsigned char moto_current; //�������
        unsigned : 8;
        unsigned char moto_speed; //�綯ת��
        unsigned char battle_t; //��ؾ���
        unsigned char Inverter_t; //������¶�
        
        unsigned battle_t_warn : 2; //��ع��±���
        unsigned battle_jueyuan_warn : 2; //��Ե���ͱ���
        unsigned battle_higtv1_warn : 2; //��ѹ���1����
        unsigned battle_higtv2_warn : 2; //��ѹ���2����
        
        unsigned moto_t_warn : 2; //�������
        unsigned moto_ready : 2; //ready�ź�
        unsigned xudc : 2; //�����쳣
        unsigned moto_warn : 2; //�������
    };
    unsigned char byte[8];
}_CAN_0x18EF4AEF;

extern _CAN_0x18EF4AEF CAN_0x18EF4AEF;

typedef union {

    struct {
        unsigned BMS_offline_warn : 2; //��ز�����
        unsigned MCU_offline_warn : 2; //���������
        unsigned TCU_offline_warn : 2; //�����䲻����
        unsigned : 2;
        
        unsigned Engine_offline_warn : 2; //������������       
        unsigned : 6;
        
        unsigned Engine_wait : 2; //����������
        unsigned CAP_offline_Warning : 2; //��������
        unsigned EV : 2; //ģʽ
        unsigned Signal_charge : 2; //����ź�
        
        unsigned char BMS_V;   //��ص�ѹ
        unsigned char BMS_SOC; //���SOC
        unsigned char CAP_voltage; //���ݵ�ѹ
        unsigned char CAP_SOE;       
        unsigned char BMS_A;   //��ص���
    };
    unsigned char byte[8];
} _CAN_0x18EF4BEF;

extern _CAN_0x18EF4BEF CAN_0x18EF4BEF;
#pragma pack(1)
typedef union {

    struct {
        unsigned : 8;        
        unsigned : 8;  
        unsigned : 8;
        unsigned : 8;
        unsigned : 8;
        unsigned : 8;
        unsigned : 8;
        unsigned : 2; 
        unsigned : 2; 
        unsigned Eng_static_test : 2; //��������̬ת�ٲ���
        unsigned tcu_start_allow : 2; //��������������
    };
    unsigned char byte[8];
} _CAN_0x0CF00203;
#pragma pack()
extern unsigned int Speed_rmp; //�����ת��
extern _CAN_0x0CF00203 CAN_0x0CF00203;

extern unsigned char Current_Gear; //��λ
#pragma pack(1)
typedef union {

    struct {
        unsigned int Max_Cell_Voltage: 12;   
        unsigned int : 4;
        
        unsigned char Max_Cell_Voltage_Cell_Number; //��ߵ���λ��
        
        unsigned int Min_Cell_Voltage: 12;   
        unsigned int : 4;
        
        unsigned char Min_Cell_Voltage_Cell_Number; //��͵���λ��
        unsigned char Brake_percent; //̤�忪��      
        unsigned : 8; //��������������
    };
    unsigned char byte[8];
} _CAN_0x18EF4CEF;
#pragma pack()
extern _CAN_0x18EF4CEF CAN_0x18EF4CEF;

typedef union {

    struct {
        unsigned int Max_Cell_Temperature: 12;   
        unsigned int : 4;
        
        unsigned char Max_Cell_Temp_Cell_Number; //��ߵ���λ��      
        unsigned char Motor_Temperature;   
        unsigned char moto2_current; //�������
        unsigned char moto2_speed; //�綯ת��
        unsigned char Inverter2_t; //������¶�
        unsigned char Motor2_Temperature; 
    };
    unsigned char byte[8];
} _CAN_0x18EF4DEF;

extern _CAN_0x18EF4DEF CAN_0x18EF4DEF;
#pragma pack(1)
typedef union {

    struct {
        unsigned int ENG_start_req; //�Ǳ��������
        unsigned long mot_work_time; //��������ۻ�ʱ��
        unsigned char mot_work_percent; //�������ʱ���

        unsigned DCDC_ctrl : 2; //DCDC״̬
        unsigned hcu_starter_forbid : 2; //�𶯻�����
        unsigned aircompress_enable : 2; //ѹ����
        unsigned Brake_Pedal : 2; //ɲ���ź�
    };
    unsigned char byte[8];
} _CAN_0x18EF0AEF;
#pragma pack()
extern _CAN_0x18EF0AEF CAN_0x18EF0AEF;

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

typedef union {

    struct {
        unsigned :16; //���������
        unsigned int XDC_A; //���ص���
        unsigned int XDC_V; //���ص�ѹ
        unsigned char PDH_Temp; //�����¶�
        unsigned PDH_Status : 1; //�𶯻�״̬
        unsigned PDH_OverCurrent : 1; //����
        unsigned PDH_OverVoltage : 1; //��ѹ
        unsigned PDH_Protect : 1; //����
        unsigned : 4; //
    };
    unsigned char byte[8];
} _CAN_0x18FE521E;

extern _CAN_0x18FE521E CAN_0x18FE521E;

typedef union {

    struct {
        unsigned int PDH_A1; //���е���1
        unsigned int PDH_A2; //���е���2
        unsigned int PDH_A3; //���е���3
        unsigned int PDH_A4; //���е���4
    };
    unsigned int  two[4];
    unsigned char byte[8];
} _CAN_0x1CFF5281;

extern _CAN_0x1CFF5281 CAN_0x1CFF5281;

typedef union {

    struct {
        unsigned char : 8; //
        unsigned char PDH_Temp1; //���е���1
        unsigned char PDH_Temp2; //���е���2
        unsigned char PDH_Temp3; //���е���3
        unsigned char PDH_Temp4; //���е���4
        unsigned char PDH_Temp5; //���е���5
        unsigned char PDH_Temp6; //���е���6
        unsigned char : 8; //
    };
    unsigned char byte[8];
} _CAN_0x1CFF5381;

extern _CAN_0x1CFF5381 CAN_0x1CFF5381;

#endif	/* APP_CAN2_RECEIVE_H */

