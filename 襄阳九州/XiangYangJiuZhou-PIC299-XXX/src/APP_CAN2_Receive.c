/*
 * File:   APP_CAN_Receive.c
 * Author: pnc
 *
 * Created on 2017��7��28��, ����6:02
 */

#include "APP_System.h"

/*******************�ְ�����*****************/
DM1 CAN_18FECAEF;
unsigned char CAN_18FECAEF_len;
DM1 CAN_18FECA03;
unsigned char CAN_18FECA03_len;
DM1 CAN_18FECAF5;
unsigned char CAN_18FECAF5_len;
DM1 CAN_18FECA00;
unsigned char CAN_18FECA00_len;
DM1 CAN_18FECAF3;
unsigned char CAN_18FECAF3_len;
CAN_CACHE m_can;
CAN_CACHE n_can;
CAN_CACHE c_can;
CAN_CACHE e_can;
CAN_CACHE b_can;
unsigned long SPN; //�ӻ�������ȡ�Ĺ�����
unsigned char FMI;
/******************************************/
//ID(0x0C008980)
unsigned int VCU_Motor_Front_Voltage; //���������ǰ�˵�ѹ
unsigned int VCU_Motor_Rear_Voltage; //�����������˵�ѹ
unsigned int VCU_Motor_DC_Current; //���������ֱ������
unsigned int VCU_Motor_RPM;

//ID(0x0C018980)    
unsigned char VCU_Speed_percent; //����̤�忪��
unsigned char VCU_Brake_percent; //�ƶ�̤�忪��
DATA_BIT VCU_Power_System_Status; //����ϵͳ״̬
unsigned char VCU_Gear; //��λ
unsigned char VCU_KT; //���Ӵ���״̬
unsigned char VCU_KC; //Ԥ��Ӵ���
unsigned char VCU_Motor_Temp = 40; //����¶�
unsigned char VCU_Motor_Control_Temp = 40; //����������¶�
unsigned char VCU_Motor_Code; //���������
unsigned char VCU_Life; //����������Life

//ID(0x0C028980)
DATA_BIT VCU_Output_Status; //�������״̬
unsigned int VCU_Motor_Brake_Current; //����ƶ�����
unsigned int VCU_Motor_Torque; //���ʵ��ת��
unsigned char VCU_Motor_Number; //�������
unsigned char VCU_Motor_Sequence_Number; //������
unsigned char VCU_Motor_Status; //���״̬

//ID(0x0C038980)
DATA_DOUBLE VCU_Run_Mode; //����ģʽ
DATA_BIT VCU_Warn; //��������
unsigned char VCU_Fault_Number_BAT; //��ع�������
unsigned char VCU_Fault_Number_Motor; //��ع�������
unsigned char VCU_Fault_Number_Other; //��ع�������

//ID��0x18FF12F7��
unsigned int DCDC_Output_Voltage; //DCDC�����ѹ
unsigned int DCDC_Output_Current; //DCDC�����ѹ
unsigned char DCDC_Work_Status; //DCDC����״̬
DATA_BIT DCDC_Fault_Code; //DCDC���ϴ���

//ID��0x18019888��
unsigned int OILDCAC_Output_Voltage; //�ͱ�DCAC�����ѹ
unsigned int OILDCAC_Output_Current; //�ͱ�DCAC�����ѹ
unsigned char OILDCAC_Temp = 40;     //�ͱ�DCACɢ�������¶�
DATA_BIT OILDCAC_Code;               //�ͱ�DCAC���ϴ���

//ID��0x1805A89C��
unsigned int AIRDCAC_Input_Voltage;  //����DCAC�����ѹ
unsigned int AIRDCAC_Output_Voltage; //����DCAC�����ѹ
unsigned int AIRDCAC_Output_Current; //����DCAC�����ѹ
unsigned char AIRDCAC_Temp = 40;     //����DCACɢ�������¶�
DATA_BIT AIRDCAC_Code;               //����DCAC���ϴ���

//ID(0x18F0010B)
unsigned char ABS_Active; //ABS״̬

//BMS���͵�һ�飬ID=0x0CFF7D03
unsigned char BMS_Life; //BMS Life
unsigned char BMS_Fault_Level; //BMS���ϵȼ�
unsigned char BMS_Charge; //��ŵ�״̬
unsigned char BMS_SOC; //���SOC
unsigned char BAT_Max_Cell_Voltage_Cell_Number; //��ߵ����ѹλ��
unsigned int BAT_Max_Cell_Voltage; //��ص���ߵ�ѹ
unsigned char BAT_Min_Cell_Voltage_Cell_Number; //��͵����ѹλ��
unsigned int BAT_Min_Cell_Voltage; //��ص���͵�ѹ

//BMS���͵ڶ��飬ID=0x0CFF7E03
unsigned char BMS_Precharge; //Ԥ���״̬
unsigned char BMS_HighVoltage_Status; //��ѹ����״̬
unsigned char BMS_Check; //BMS�Լ�
unsigned char BMS_SOH; //BMS SOH
unsigned int BMS_V; //��ص�ѹ
unsigned int BMS_A = 1000; //��ص���
unsigned int BAT_Max_Cell_Temperature = 40; //��ߵ����¶�
unsigned int BAT_Min_Cell_Temperature = 40; //��͵����¶�

//BMS���͵����飬ID=0x0CFF7F03
DATA_BIT BMS_Status1; //BMS״̬1
unsigned char BMS_Charging; //BMS��ŵ�״̬
DATA_DOUBLE BMS_Status2; //BMS״̬2
unsigned char BMS_Humidity; //BMSʪ��
unsigned char BMS_Current_Charge_Limit_Long = 200; //�����ó�����繦�ʣ�30min��
unsigned char BMS_Current_Charge_Limit_Short = 200; //�����ö�ʱ��繦�ʣ�30s��
unsigned char BMS_Current_Disharge_Limit_Long; //�����ó����ŵ繦�ʣ�30min��
unsigned char BMS_Current_Disharge_Limit_Short; //�����ö�ʱ�ŵ繦�ʣ�30s��
unsigned int Oum; //��Ե��ֵ

//BMS���͵����飬ID=0x0CFF8003
unsigned char BMS_Fault1[20]; //BMS�༶����
//BMS_Fault1[0]    �¶Ȳ������
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
DATA_BIT BMS_Fault2[3]; //BMS��������

//�������ǹ��ֱ�����ǹ�¶���ʾID=0x18FFDE03
unsigned char BMS_DC_ChargeGun_PT = 40; //ֱ�����ǹ�����¶�
unsigned char BMS_DC_ChargeGun_NT = 40; //ֱ�����ǹ�����¶�
unsigned char BMS_AC_ChargeGun_Temp = 40; //�����ǹ�¶�

//BMS���͵����飬ID=0x0CFF8103
unsigned char BAT_Max_Cell_Voltage_Cell_Case; //��ߵ����ѹ���
unsigned char BAT_Min_Cell_Voltage_Cell_Case; //��͵����ѹ���
unsigned char BAT_Max_Cell_Temp_Cell_Case; //��ߵ����¶����
unsigned char BAT_Max_Cell_Temp_Cell_Number; //��ߵ����ѹλ��
unsigned char BAT_Min_Cell_Temp_Cell_Case; //��͵����¶����
unsigned char BAT_Min_Cell_Temp_Cell_Number; //��ߵ����ѹλ��
DATA_BIT BMS_Warn[2];

//BMS���͵����飬ID=0x0CFF8203���ɳ�索��װ�õ�ѹ���ݣ�
unsigned char BMS_System_Number;
unsigned char BMS_System_SequenceNumber;
unsigned int BMS_System_Voltage;
unsigned int BMS_System_Current = 10000;
unsigned char BMS_BAT_Number;

//BMS���͵ڰ��飬ID=0x0CFF8303
unsigned char BMS_System_Temp_Number;
unsigned char BMS_System_Fault_Number;

//BMS���͵����ѹ��ѡ�ã�0x18(00~FF)DC03
unsigned int BAT_Single_Voltage[200];
unsigned char BAT_Single_Temp[200];

void DM(unsigned char x, DM1 id) {//������id�ĵ�x���������spn��fmi
    SPN = id.bData[2 + 4 * (x - 1)]
            +((unsigned int) id.bData[3 + 4 * (x - 1)] << 8)
            +((unsigned long) (id.bData[4 + 4 * (x - 1)]&0xE0) << 11);
    FMI = (id.bData[4 + 4 * (x - 1)] & 0x1F);
}

void __attribute__((__interrupt__, auto_psv)) _C2Interrupt(void) {
    unsigned char i = 0, temp = 0;
    CAN_MESSAGE msg;
    //DATA_DOUBLE CAN_DOUBLE;
    //DATA_BIT CAN_BIT;
    if (C2INTFbits.ERRIF) { //���մ���
        C2INTFbits.ERRIF = 0; // ��Ӵ��������
        CAN2_Init();
        C2RX0CONbits.RXFUL = 0;
    }
    if (C2INTFbits.IVRIF) {
        C2INTFbits.IVRIF = 0; //������Ч
        C2RX0CONbits.RXFUL = 0;
    }
    if (C2RX0CONbits.RXFUL) { //������Ч
        CAN2_ReceiveMessage(&msg);
        switch (msg.id) {
            case 0x0C008980:
                VCU_Motor_Front_Voltage = (unsigned char) msg.data[0]
                        +((unsigned int) msg.data[1] << 8);
                VCU_Motor_Rear_Voltage = (unsigned char) msg.data[2]
                        +((unsigned int) msg.data[3] << 8);
                VCU_Motor_DC_Current = (unsigned char) msg.data[4]
                        +((unsigned int) msg.data[5] << 8);
                VCU_Motor_RPM = (unsigned char) msg.data[6]
                        +((unsigned int) msg.data[7] << 8);
                break;

            case 0x0C018980:
                VCU_Speed_percent = (unsigned char) msg.data[0];
                VCU_Brake_percent = (unsigned char) msg.data[1];
                VCU_Power_System_Status.byte = (unsigned char) msg.data[2];
                VCU_Gear = (unsigned char) msg.data[3] & 0x07;
                VCU_KT = (unsigned char) (msg.data[3] >> 4) & 0x03;
                VCU_KC = (unsigned char) (msg.data[3] >> 6) & 0x03;
                VCU_Motor_Temp = (unsigned char) msg.data[4];
                VCU_Motor_Control_Temp = (unsigned char) msg.data[5];
                VCU_Motor_Code = (unsigned char) msg.data[6];
                VCU_Life = (unsigned char) msg.data[7];
                break;

            case 0x0C028980:
                VCU_Output_Status.byte = (unsigned char) msg.data[0];
                VCU_Motor_Brake_Current = (unsigned char) msg.data[1]
                        +((unsigned int) msg.data[2] << 8);
                VCU_Motor_Torque = (unsigned char) msg.data[3]
                        +((unsigned int) msg.data[4] << 8);
                VCU_Motor_Number = (unsigned char) msg.data[5];
                VCU_Motor_Sequence_Number = (unsigned char) msg.data[6];
                VCU_Motor_Status = (unsigned char) msg.data[7];
                break;

            case 0x0C038980:
                VCU_Run_Mode.byte = (unsigned char) msg.data[0];
                VCU_Warn.byte = (unsigned char) msg.data[1];
                VCU_Fault_Number_BAT = (unsigned char) msg.data[5];
                VCU_Fault_Number_Motor = (unsigned char) msg.data[6];
                VCU_Fault_Number_Other = (unsigned char) msg.data[7];
                break;

            case 0x18FF12F7:
                DCDC_Output_Voltage = (unsigned char) msg.data[0]
                        +((unsigned int) msg.data[1] << 8);
                DCDC_Output_Current = (unsigned char) msg.data[2]
                        +((unsigned int) msg.data[3] << 8);
                DCDC_Work_Status = (unsigned char) msg.data[4];
                DCDC_Fault_Code.byte = (unsigned char) msg.data[5];
                break;

            case 0x18019888:
                OILDCAC_Output_Voltage = (unsigned char) msg.data[2]
                        +((unsigned int) msg.data[3] << 8);
                OILDCAC_Output_Current = (unsigned char) msg.data[4]
                        +((unsigned int) msg.data[5] << 8);
                OILDCAC_Temp = (unsigned char) msg.data[6];
                OILDCAC_Code.byte = (unsigned char) msg.data[7];
                break;

            case 0x1805A89C:
                AIRDCAC_Input_Voltage = (unsigned char) msg.data[0]
                        +((unsigned int) msg.data[1] << 8);
                AIRDCAC_Output_Voltage = (unsigned char) msg.data[2]
                        +((unsigned int) msg.data[3] << 8);
                AIRDCAC_Output_Current = (unsigned char) msg.data[4]
                        +((unsigned int) msg.data[5] << 8);
                AIRDCAC_Temp = (unsigned char) msg.data[6];
                AIRDCAC_Code.byte = (unsigned char) msg.data[7];
                break;

            case 0x18F0010B:
                ABS_Active = (unsigned char) msg.data[0];
                break;

            case 0x0CFF7D03:
                BMS_Life = (unsigned char) msg.data[0] & 0x0F;
                BMS_Charge = (unsigned char) (msg.data[0] >> 4) & 0x01;
                BMS_Fault_Level = (unsigned char) (msg.data[0] >> 5) & 0x07;
                BMS_SOC = (unsigned char) msg.data[1];
                BAT_Max_Cell_Voltage_Cell_Number = (unsigned char) msg.data[2];
                BAT_Max_Cell_Voltage = (unsigned char) msg.data[3]
                        +((unsigned int) msg.data[4] << 8);
                BAT_Min_Cell_Voltage_Cell_Number = (unsigned char) msg.data[5];
                BAT_Min_Cell_Voltage = (unsigned char) msg.data[6]
                        +((unsigned int) msg.data[7] << 8);
                break;

            case 0x0CFF7E03:
                BMS_Life = (unsigned char) msg.data[0] & 0x0F;
                BMS_Precharge = (unsigned char) (msg.data[0] >> 4) & 0x01;
                BMS_HighVoltage_Status = (unsigned char) (msg.data[0] >> 5) & 0x01;
                BMS_Check = (unsigned char) (msg.data[0] >> 6) & 0x03;
                BMS_SOH = (unsigned char) msg.data[1];
                BMS_V = (unsigned char) msg.data[2]
                        +((unsigned int) msg.data[3] << 8);
                BMS_A = (unsigned char) msg.data[4]
                        +((unsigned int) msg.data[5] << 8);
                BAT_Max_Cell_Temperature = (unsigned char) msg.data[6];
                BAT_Min_Cell_Temperature = (unsigned char) msg.data[7];
                break;

            case 0x0CFF7F03:
                BMS_Status1.byte = (unsigned char) msg.data[0];
                BMS_Charging = (unsigned char) (msg.data[0] >> 1) & 0x03;
                BMS_Status2.byte = (unsigned char) msg.data[1];
                BMS_Humidity = (unsigned char) (msg.data[1] >> 4) & 0x0F;
                BMS_Current_Charge_Limit_Long = (unsigned char) msg.data[2];
                BMS_Current_Charge_Limit_Short = (unsigned char) msg.data[3];
                BMS_Current_Disharge_Limit_Long = (unsigned char) msg.data[4];
                BMS_Current_Disharge_Limit_Short = (unsigned char) msg.data[5];
                Oum = (unsigned char) msg.data[6]
                        +((unsigned int) msg.data[7] << 8);
                break;

            case 0x0CFF8003:
                BMS_Fault1[0] = (unsigned char) msg.data[0] & 0x07;
                BMS_Fault1[1] = (unsigned char) (msg.data[0] >> 3) & 0x07;
                BMS_Fault1[2] = (unsigned char) (((msg.data[0] >> 6) & 0x03) + ((msg.data[1] & 0x01) << 2));
                BMS_Fault1[3] = (unsigned char) (msg.data[1] >> 1) & 0x07;
                BMS_Fault1[4] = (unsigned char) (msg.data[1] >> 4) & 0x07;
                BMS_Fault1[5] = (unsigned char) (((msg.data[1] >> 7) & 0x01) + ((msg.data[2] & 0x03) << 1));
                BMS_Fault1[6] = (unsigned char) (msg.data[2] >> 2) & 0x07;
                BMS_Fault1[7] = (unsigned char) (msg.data[2] >> 5) & 0x07;
                BMS_Fault1[8] = (unsigned char) msg.data[3] & 0x07;
                BMS_Fault1[9] = (unsigned char) (msg.data[3] >> 3) & 0x07;
                BMS_Fault1[10] = (unsigned char) (((msg.data[3] >> 6) & 0x03) + ((msg.data[4] & 0x01) << 2));
                BMS_Fault1[11] = (unsigned char) (msg.data[4] >> 1) & 0x07;
                BMS_Fault1[12] = (unsigned char) (msg.data[4] >> 4) & 0x07;
                BMS_Fault2[0].byte = msg.data[5];
                BMS_Fault2[1].byte = msg.data[6];
                BMS_Fault1[12] = (unsigned char) (msg.data[6] >> 2) & 0x07;
                BMS_Fault1[13] = (unsigned char) (msg.data[6] >> 5) & 0x07;
                BMS_Fault2[2].byte = msg.data[7];
                break;

            case 0x18FFDE03:
                BMS_DC_ChargeGun_PT = (unsigned char) msg.data[0];
                BMS_DC_ChargeGun_NT = (unsigned char) msg.data[1];
                BMS_AC_ChargeGun_Temp = (unsigned char) msg.data[2];
                break;

            case 0x0CFF8103:
                BAT_Max_Cell_Voltage_Cell_Case = (unsigned char) msg.data[0];
                BAT_Min_Cell_Voltage_Cell_Case = (unsigned char) msg.data[1];
                BAT_Max_Cell_Temp_Cell_Case = (unsigned char) msg.data[2];
                BAT_Max_Cell_Temp_Cell_Number = (unsigned char) msg.data[3];
                BAT_Min_Cell_Temp_Cell_Case = (unsigned char) msg.data[4];
                BAT_Min_Cell_Temp_Cell_Number = (unsigned char) msg.data[5];
                BMS_Warn[0].byte = (unsigned char) msg.data[6];
                BMS_Warn[1].byte = (unsigned char) msg.data[7];
                break;

            case 0x0CFF8203:
                BMS_System_Number = (unsigned char) msg.data[0];
                BMS_System_SequenceNumber = (unsigned char) msg.data[1];
                BMS_System_Voltage = (unsigned char) msg.data[2]
                        +((unsigned int) msg.data[3] << 8);
                BMS_System_Current = (unsigned char) msg.data[4]
                        +((unsigned int) msg.data[5] << 8);
                BMS_BAT_Number = (unsigned char) msg.data[6];
                break;

            case 0x0CFF8303:
                BMS_System_Temp_Number = (unsigned char) msg.data[4];
                BMS_System_Fault_Number = (unsigned char) msg.data[5];
                break;
#if 0
            case 0x0CFF09EF://VCU12 
                Vcan_count = 0;
                VCU_TM_NM = (unsigned char) msg.data[4]+((unsigned int) msg.data[5] << 8);
                VCU_TM_RPM = (unsigned char) msg.data[6]+((unsigned int) msg.data[7] << 8);
                break;

            case 0x100017EF://VCU2ICU01
                Vcan_count = 0;
                VCU_TM_Speed_percent = (unsigned char) msg.data[0];
                VCU_TM_Brake_percent = (unsigned char) msg.data[1];
                VCU_Status_Flag1.byte = (unsigned char) msg.data[2];
                VCU_Gear = msg.data[3]&0x0F;
                VCU_Mode.byte = msg.data[3] & 0xF0;
                VCU_Life = msg.data[4]&0x0F;
                VCU_Status_Flag2.byte = msg.data[4];
                VCU_Code = msg.data[7];
                break;

            case 0x1801FBEF:
                Vcan_count = 0;
                TM_Number = msg.data[0];
                TM_Serial = msg.data[1];
                TM_WorkStatus = msg.data[2];
                TM_Control_Temp = msg.data[3];
                TM_Feedback_RPM = (unsigned char) msg.data[4]+((unsigned int) msg.data[5] << 8);
                TM_Feedback_NM = (unsigned char) msg.data[6]+((unsigned int) msg.data[7] << 8);
                break;

            case 0x1811FBEF:
                Vcan_count = 0;
                TM_Temp = msg.data[0];
                TM_Voltage_DC = (unsigned char) msg.data[1]+((unsigned int) msg.data[2] << 8);
                TM_Current_DC = (unsigned char) msg.data[3]+((unsigned int) msg.data[4] << 8);
                break;


                /*case 0x0C01EF09://MCU01
                    Vcan_count = 0;
                    TM_Feedback_RPM = (unsigned char) msg.data[0]+((unsigned int) msg.data[1] << 8);
                    TM_Feedback_NM = (unsigned char) msg.data[2]+((unsigned int) msg.data[3] << 8);
                    TM_Current_AC = (unsigned char) msg.data[4]+((unsigned int) msg.data[5] << 8);
                    TM_StatusFeedback = msg.data[6];
                    TM_WorkStatus = msg.data[7]&0x0F;
                    TM_LIFE = (msg.data[7] >> 4)&0x0F;
                    break;   
                
                case 0x0C02EF09://MCU02
                    Vcan_count = 0;
                    TM_Temp = msg.data[0];
                    TM_Control_Temp = msg.data[1];
                    TM_Torque_Limit_Up= (unsigned char) msg.data[2]+((unsigned int) msg.data[3] << 8);
                    TM_Torque_Limit_Down= (unsigned char) msg.data[4]+((unsigned int) msg.data[5] << 8);
                    TM_Fault.byte = msg.data[6]&0x0F;
                    TM_Status = (msg.data[6] >> 4)&0x0F;
                    TM_Status_Flag1.byte = msg.data[7];
                    break;     
            
                case 0x0C03EF09://MCU03
                    Vcan_count = 0;
                    TM_Code = (unsigned char) msg.data[0]+((unsigned int) msg.data[1] << 8);
                    TM_Current_DC = (unsigned char) msg.data[2]+((unsigned int) msg.data[3] << 8);
                    TM_Voltage_DC = (unsigned char) msg.data[4]+((unsigned int) msg.data[5] << 8);
                    break; */

            case 0x18FF08F2://IRM01
                Vcan_count = 0;
                IRM_Ohm_Positive = (unsigned char) msg.data[0]+((unsigned int) msg.data[1] << 8)+((unsigned long) msg.data[2] << 16);
                IRM_Ohm_Negative = (unsigned char) msg.data[3]+((unsigned int) msg.data[4] << 8)+((unsigned long) msg.data[5] << 16);

                CAN_DOUBLE.byte = msg.data[6];
                IRM_Fault_Level = CAN_DOUBLE.bit1;
                IRM_Insulation_Level = CAN_DOUBLE.bit2;

                IRM_Life = msg.data[7];
                break;

                /*case 0x18FFA0F3://VCU21 
                    Vcan_count = 0;
                    VCU_Kt = msg.data[0]&0x03;
                    VCU_ON = (msg.data[0] >> 2)&0x03;
                    VCU_Order = (msg.data[0] >> 4)&0x03;
                    VCU_Voltage = (unsigned char) msg.data[1]+((unsigned int) msg.data[2] << 8);
                    break;*/

            case 0x10F8159E://BMS STATUS 1 
                Bcan_count = 0;
                BMS_Mode = msg.data[0]&0x07;
                BMS_Status = (msg.data[0] >> 6)&0x03;
                BAT_Temp_Average = msg.data[1];
                BMS_SOC = msg.data[2];
                BMS_Current = (unsigned char) msg.data[3]+((unsigned int) msg.data[4] << 8);
                BMS_Voltage = (unsigned char) msg.data[5]+((unsigned int) msg.data[6] << 8);
                BMS_Kt = (msg.data[7] >> 4)&0x0F;
                break;

            case 0x10F8169E://BMS STATUS 2 
                Bcan_count = 0;
                BAT_Temp_H_Limit = msg.data[0];
                BAT_Temp_L_Limit = msg.data[1];
                BMS_SOC_L_Limit = msg.data[2];
                BAT_Current_Discharge_Limit = (unsigned char) msg.data[3]+((unsigned int) msg.data[4] << 8);
                BAT_Current_Charge_Limit = (unsigned char) msg.data[5]+((unsigned int) msg.data[6] << 8);
                break;

            case 0x18F8179E://BMS STATUS 3
                Bcan_count = 0;
                BAT_Temp_L = msg.data[0];
                BAT_Temp_L_Number = msg.data[1];
                BAT_Temp_L_Case = msg.data[2];
                BAT_Temp_H = msg.data[3];
                BAT_Temp_H_Number = msg.data[4];
                BAT_Temp_H_Case = msg.data[5];
                break;

            case 0x18F8189E://BMS STATUS 4
                Bcan_count = 0;
                BAT_Voltage_Fault = msg.data[0]&0x0F;
                BAT_Single_Fault = (msg.data[0] >> 4)&0x0F;
                BAT_Temp_Fault = msg.data[1]&0x3F;
                BAT_Insulation_Fault = (msg.data[1] >> 6)&0x3F;
                BAT_Consistency_Fault = msg.data[2]&0x03;
                BAT_SOC_Fault = (msg.data[2] >> 2)&0x3F;
                BAT_Current_Fault = msg.data[3]&0x0F;
                BAT_Lock_Fault = (msg.data[3] >> 4)&0x03;
                BMS_Comm_Fault = (msg.data[3] >> 6)&0x03;
                BMS_System_Fault = msg.data[4]&0x01;
                break;

            case 0x18F8199E://BMS STATUS 5
                Bcan_count = 0;
                BMS_Ohm = (unsigned char) msg.data[0]+((unsigned int) msg.data[1] << 8);
                BMS_Number = msg.data[2];
                BMS_Temp_Number = msg.data[3];
                BMS_System_Unit = msg.data[4];
                BMS_System_Number = msg.data[5];
                break;

            case 0x18F81A9E://BMS STATUS 6
                Bcan_count = 0;
                BAT_Single_L = (unsigned char) msg.data[0]+((unsigned int) msg.data[1] << 8);
                BAT_Single_L_Number = msg.data[2];
                BAT_Single_L_Case = msg.data[3];
                BAT_Single_H = (unsigned char) msg.data[4]+((unsigned int) msg.data[5] << 8);
                BAT_Single_H_Number = msg.data[6];
                BAT_Single_H_Case = msg.data[7];
                break;


            case 0x18FF12F7://DCDC21 
                Bcan_count = 0;
                DCDC_Voltage = (unsigned char) msg.data[0]+((unsigned int) msg.data[1] << 8);
                DCDC_Current = (unsigned char) msg.data[2]+((unsigned int) msg.data[3] << 8);
                DCDC_Status = msg.data[4]&0x03;
                DCDC_Output_Cut = (msg.data[4] >> 2)&0x01;
                DCDC_intput_Cut = (msg.data[4] >> 3)&0x01;
                DCDC_Fault_Code = msg.data[5];
                DCDC_Level_Fault = msg.data[6]&0x03;
                DCDC_Temp_Warn = (msg.data[6] >> 2)&0x01;
                DCDC_Fault_Warn = (msg.data[6] >> 3)&0x01;
                DCDC_Temp = msg.data[7];
                break;

            case 0x18FF0AF8://OILDCAC21 
                Bcan_count = 0;
                OILDCAC_U_Voltage = (unsigned char) msg.data[0]+((unsigned int) msg.data[1] << 8);
                OILDCAC_U_Current = (unsigned char) msg.data[2]+((unsigned int) msg.data[3] << 8);
                OILDCAC_Status = msg.data[4]&0x03;
                OILDCAC_Output_Cut = (msg.data[4] >> 2)&0x01;
                OILDCAC_intput_Cut = (msg.data[4] >> 3)&0x01;
                OILDCAC_Fault_Code = msg.data[5];
                OILDCAC_Level_Fault = msg.data[6]&0x03;
                OILDCAC_Temp_Warn = (msg.data[6] >> 2)&0x01;
                OILDCAC_Fault_Warn = (msg.data[6] >> 3)&0x01;
                OILDCAC_Temp = msg.data[7];
                break;

            case 0x18FF0BF8://OILDCAC22 
                Bcan_count = 0;
                OILDCAC_V_Voltage = (unsigned char) msg.data[0]+((unsigned int) msg.data[1] << 8);
                OILDCAC_V_Current = (unsigned char) msg.data[2]+((unsigned int) msg.data[3] << 8);
                OILDCAC_W_Voltage = (unsigned char) msg.data[4]+((unsigned int) msg.data[5] << 8);
                OILDCAC_W_Current = (unsigned char) msg.data[6]+((unsigned int) msg.data[7] << 8);
                break;

            case 0x18FF0CF9://AIRDCAC21 
                Bcan_count = 0;
                AIRDCAC_U_Voltage = (unsigned char) msg.data[0]+((unsigned int) msg.data[1] << 8);
                AIRDCAC_U_Current = (unsigned char) msg.data[2]+((unsigned int) msg.data[3] << 8);
                AIRDCAC_Status = msg.data[4]&0x03;
                AIRDCAC_Output_Cut = (msg.data[4] >> 2)&0x01;
                AIRDCAC_intput_Cut = (msg.data[4] >> 3)&0x01;
                AIRDCAC_Fault_Code = msg.data[5];
                AIRDCAC_Level_Fault = msg.data[6]&0x03;
                AIRDCAC_Temp_Warn = (msg.data[6] >> 2)&0x01;
                AIRDCAC_Fault_Warn = (msg.data[6] >> 3)&0x01;
                AIRDCAC_Temp = msg.data[7];
                break;

            case 0x18FF0DF9://AIRDCAC22 
                Bcan_count = 0;
                AIRDCAC_V_Voltage = (unsigned char) msg.data[0]+((unsigned int) msg.data[1] << 8);
                AIRDCAC_V_Current = (unsigned char) msg.data[2]+((unsigned int) msg.data[3] << 8);
                AIRDCAC_W_Voltage = (unsigned char) msg.data[4]+((unsigned int) msg.data[5] << 8);
                AIRDCAC_W_Current = (unsigned char) msg.data[6]+((unsigned int) msg.data[7] << 8);
                break;

            case 0x1801EFA9://ICS01
                Vcan_count = 0;
                ICS01_Status1.byte = msg.data[0];
                ICS01_Status2.byte = msg.data[1];
                ICS01_Status3.byte = msg.data[2];
                ICS01_Status4.byte = msg.data[3];
                ICS01_Voltage_Front = (unsigned char) msg.data[4]+((unsigned int) (msg.data[5]&0x0F) << 8);
                ICS01_Voltage_Rear = (unsigned char) (msg.data[5] >> 4)+((unsigned int) msg.data[6] << 4);
                ICS01_LIFE = msg.data[7];
                break;

                /*
                case 0x0C03A1A7://VCU21 
                    Vcan_count=0;
                    moto_voltage = (unsigned char) msg.data[0]+((unsigned int) msg.data[1] << 8);
                    moto_current = (unsigned char) msg.data[2]+((unsigned int) msg.data[3] << 8);
                    moto_speed = (unsigned char) msg.data[4]+((unsigned int) msg.data[5] << 8);
                    Motor_Temperature = msg.data[6];
                    Inverter_t = msg.data[7];
                    break;

                case 0x0C04A1A7://�Ǳ���MET_C_2
                    Vcan_count=0;
                    Accelerator = (unsigned char) msg.data[4];
                    Engine_Speed = ((unsigned char) msg.data[5]+((unsigned int) msg.data[6] << 8))*0.125;
                    break;

                case 0x0C05A1A7://�Ǳ���MET_C_3
                    Vcan_count=0;
                    Fule_rate = (unsigned char) msg.data[0]+((unsigned int) msg.data[1] << 8);
                    water_temp = msg.data[2];
                    Engine_Fuhe = msg.data[3];
                    Niaosu = msg.data[4];
                    Accelerator_Shiji = msg.data[5]; //����̤��ʵ��
                    Engine_oil_press = msg.data[6]; //����ѹ��
                    ambient_air_temperature = msg.data[7]; //��Χ�����¶�
                    break;

                case 0x0C06A1A7://�Ǳ���MET_C_4  
                    Vcan_count=0;
                    Current_Gear = msg.data[1]&0x0f;
                    TCU_Position = (msg.data[1] >> 4)&0x0f;
                    TCU_warn = msg.data[2]&0x03;
                    STOP = (msg.data[2] >> 2)&0x03;
                    Speed_rmp = ((unsigned char) msg.data[3]+((unsigned int) msg.data[4] << 8))*0.125;
                    Car_mode = msg.data[5];
                    TCU_code = msg.data[6];
                    TCU_level = msg.data[7];
                    break;

                case 0x0C07A1A7://�Ǳ���MET_C_5  
                    Vcan_count=0;
                    CAN_ON = msg.data[0]&0x01;
                    CAN_ACC = (msg.data[0] >> 1)&0x01;
                    Diagnosis = (msg.data[0] >> 2)&0x01;
                    Mode_S = (msg.data[0] >> 3)&0x01;
                    AC = (msg.data[0] >> 4)&0x01;
                    Hybrid = (msg.data[0] >> 5)&0x01;
                    Electric = (msg.data[0] >> 6)&0x01;
                    Tradition = (msg.data[0] >> 7)&0x01;
                    High_Voltage = (msg.data[1] >> 4)&0x01;
                    Charge_Check = (msg.data[1] >> 5)&0x01;
                    Digit_input3 = msg.data[2];
                    //Kt = (msg.data[3] >> 1)&0x01;
                    Brake_Pedal = msg.data[4]&0x01;
                    Speed_percent = msg.data[5];
                    Brake_percent = msg.data[6];
                    break;

                case 0x0C08A1A7://�Ǳ���MET_C_6  
                    Vcan_count=0;
                    Program = ((unsigned char) msg.data[0]
                            +((unsigned int) msg.data[1] << 8)
                            +((unsigned long) msg.data[2] << 16));
                    tcu_spn = ((unsigned char) msg.data[3]
                            +((unsigned int) msg.data[4] << 8)
                            +((unsigned long) (msg.data[5]&0xE0) << 11));
                    tcu_fmi = msg.data[5]&0x1F;
                    tcu_cm = msg.data[6] >> 7;
                    ;
                    tcu_oc = msg.data[6]&0x7F;
                    Car_LIFE = msg.data[7];
                    break;

                case 0x1818D0F3://BMS1_S_1
                    Bcan_count=0;
                    BMS_V = ((unsigned char) msg.data[0]
                            +((unsigned int) msg.data[1] << 8));
                    BMS_A = ((unsigned char) msg.data[2]
                            +((unsigned int) msg.data[3] << 8));
                    BMS_SOC = msg.data[4];
                    Status_Flag1 = msg.data[5];
                    Status_Flag2 = msg.data[6];
                    Status_Flag3 = msg.data[7]&0x0C;
                    break;

                case 0x1819D0F3://BMS1_S_2
                    Bcan_count=0;
                    BMS_A_charge = ((unsigned char) msg.data[0]
                            +((unsigned int) msg.data[1] << 8));
                    BMS_A_discharge = ((unsigned char) msg.data[2]
                            +((unsigned int) msg.data[3] << 8));
                    Warn_level = msg.data[4];
                    BMS_V_average = ((unsigned char) msg.data[5]
                            +((unsigned int) msg.data[6] << 8));
                    BMS_T_H = msg.data[7];
                    break;

                case 0x181AD0F3://BMS1_S_3
                    Bcan_count=0;
                    Oum_zheng = ((unsigned char) msg.data[0]
                            +((unsigned int) msg.data[1] << 8));
                    Oum_fu = ((unsigned char) msg.data[2]
                            +((unsigned int) msg.data[3] << 8));
                    Battery_single_H = ((unsigned char) msg.data[4]
                            +((unsigned int) msg.data[5] << 8));
                    Battery_single_L = ((unsigned char) msg.data[6]
                            +((unsigned int) msg.data[7] << 8));
                    break;

                case 0x180028F3://BMS1_S_4_1
                    Bcan_count=0;
                    Battery_number[0] = msg.data[0];
                    Battery_voltage[0] = ((unsigned char) msg.data[1]
                            +((unsigned int) msg.data[2] << 8));
                    Battery_number[1] = msg.data[3];
                    Battery_voltage[1] = ((unsigned char) msg.data[4]
                            +((unsigned int) msg.data[5] << 8));
                    break;

                case 0x180128F3://BMS1_S_4_2
                    Bcan_count=0;
                    Battery_number[2] = msg.data[0];
                    Battery_voltage[2] = ((unsigned char) msg.data[1]
                            +((unsigned int) msg.data[2] << 8));
                    Battery_number[3] = msg.data[3];
                    Battery_voltage[3] = ((unsigned char) msg.data[4]
                            +((unsigned int) msg.data[5] << 8));
                    break;

                case 0x180228F3://BMS1_S_4_3
                    Bcan_count=0;
                    Battery_number[4] = msg.data[0];
                    Battery_voltage[4] = ((unsigned char) msg.data[1]
                            +((unsigned int) msg.data[2] << 8));
                    Battery_number[5] = msg.data[3];
                    Battery_voltage[5] = ((unsigned char) msg.data[4]
                            +((unsigned int) msg.data[5] << 8));
                    break;

                case 0x180328F3://BMS1_S_4_4
                    Bcan_count=0;
                    Battery_number[6] = msg.data[0];
                    Battery_voltage[6] = ((unsigned char) msg.data[1]
                            +((unsigned int) msg.data[2] << 8));
                    Battery_number[7] = msg.data[3];
                    Battery_voltage[7] = ((unsigned char) msg.data[4]
                            +((unsigned int) msg.data[5] << 8));
                    break;

                case 0x180428F3://BMS1_S_4_5
                    Bcan_count=0;
                    Battery_number[8] = msg.data[0];
                    Battery_voltage[8] = ((unsigned char) msg.data[1]
                            +((unsigned int) msg.data[2] << 8));
                    Battery_number[9] = msg.data[3];
                    Battery_voltage[9] = ((unsigned char) msg.data[4]
                            +((unsigned int) msg.data[5] << 8));
                    break;

                case 0x180028F4://BMS1_S_5_1
                    Bcan_count=0;
                    Battery_number_t[0] = msg.data[0];
                    Battery_temp[0] = msg.data[1];
                    Battery_number_t[1] = msg.data[2];
                    Battery_temp[1] = msg.data[3];
                    Battery_number_t[2] = msg.data[4];
                    Battery_temp[2] = msg.data[5];
                    Battery_number_t[3] = msg.data[6];
                    Battery_temp[3] = msg.data[7];
                    break;

                case 0x180128F4://BMS1_S_5_2
                    Bcan_count=0;
                    Battery_number_t[4] = msg.data[0];
                    Battery_temp[4] = msg.data[1];
                    Battery_number_t[5] = msg.data[2];
                    Battery_temp[5] = msg.data[3];
                    Battery_number_t[6] = msg.data[4];
                    Battery_temp[6] = msg.data[5];
                    Battery_number_t[7] = msg.data[6];
                    Battery_temp[7] = msg.data[7];
                    break;

                case 0x180228F4://BMS1_S_5_3
                    Bcan_count=0;
                    Battery_number_t[8] = msg.data[0];
                    Battery_temp[8] = msg.data[1];
                    Battery_number_t[9] = msg.data[2];
                    Battery_temp[9] = msg.data[3];
                    break;


                case 0x0C09A79B://DAC_S_1
                    Dcan_count=0;
                    DCAC_W = ((unsigned char) msg.data[0]
                            +((unsigned int) msg.data[1] << 8));
                    DCAC_V = ((unsigned char) msg.data[2]
                            +((unsigned int) msg.data[3] << 8));
                    DCAC_U = ((unsigned char) msg.data[4]
                            +((unsigned int) msg.data[5] << 8));
                    Sanreqi_t = msg.data[6];
                    DCAC_Warn_code = msg.data[7];
                    break;


                case 0x18FFC09E://AIR_S_1
                    Acan_count=0;
                    AC_Warn_code = msg.data[0];
                    AC_opean = (msg.data[1] >> 5)&0x01;
                    AC_mind_speed = (msg.data[1] >> 6)&0x01;
                    AC_High_speed = (msg.data[1] >> 7)&0x01;
                    AC_warn1 = msg.data[2]&0x01;
                    AC_cold1_shuang = (msg.data[2] >> 1)&0x01;
                    AC_wind = (msg.data[2] >> 2)&0x01;
                    AC_save = (msg.data[2] >> 3)&0x01;
                    AC_cold2_shuang = (msg.data[2] >> 4)&0x01;
                    AC_cold2 = (msg.data[2] >> 5)&0x01;
                    AC_cold1 = (msg.data[2] >> 7)&0x01;
                    Indoor_t = msg.data[3];
                    Outdoor_t = msg.data[4];
                    Set_t = msg.data[5];
                    AC_req = msg.data[6]&0x01;
                    AC_LIFE = msg.data[7];
                    break;
                
                case 0x18FECA00:// DM1 ECU
                    Ecan_count=0;
                        for (i = 0; i < 6; i++) {
                            CAN_18FECA00.bData[i] = msg.data[i];
                        }
                        CAN_18FECA00_len = 0x06; //e_can.len;               
                        break;

                   
                    case 0x18EF4BEF://Hybrid_DTC_Message
                        BMS_offline_warn = msg.data[0]&0x03;
                        MCU_offline_warn = (msg.data[0] >> 2)&0x03;
                        TCU_offline_warn = (msg.data[0] >> 4)&0x03;
                        Engine_offline_warn = msg.data[1]&0x03;
                        Engine_wait = msg.data[2]&0x03;
                        EV = (msg.data[2] >> 4)&0x03;
                        Signal_charge = (msg.data[2] >> 6)&0x03;
                        BMS_V = msg.data[3];
                        BMS_SOC = msg.data[4];
                        BMS_A = msg.data[7];

                        break;

                    case 0x18FECAEF:// DM1 HCU

                        for (i = 0; i < 6; i++) {
                            CAN_18FECAEF.bData[i] = msg.data[i];
                        }
                        CAN_18FECAEF_len = 0x06; //m_can.len;

                        break;

                    case 0x1CECFFEF://TPCM HCU
                        if (msg.data[0] == 0x20) {
                            if (msg.data[5] == 0xCA && msg.data[6] == 0xFE) {
                                m_can.len = msg.data[1]+((unsigned int) msg.data[2] << 8);
                                m_can.pack = msg.data[3];
                                m_can.flag = 1; //CAN���տ�ʼ���
                            }
                        }

                        break;

                    case 0x1CEBFFEF://TPDT HCU
                        if (m_can.flag == 1) {
                            if (msg.data[0] <= m_can.pack) {
                                unsigned int slen;
                                slen = (msg.data[0] - 1)*7;
                                for (i = 0; i < 7; i++) {
                                    m_can.buf[slen+i] = msg.data[i + 1];
                                }
                            }
                            if (msg.data[0] == m_can.pack) {
                                for (i = 0; i < m_can.len; i++) {
                                    CAN_18FECAEF.bData[i] = m_can.buf[i];
                                }
                                CAN_18FECAEF_len = m_can.len;
                                m_can.flag = 0; //����ɽ���
                            }
                        }

                        break;
                        //////////////////////////////////////////////////////////////////////////////////            
                    case 0x0CF00203://ETC1 TCU
                        Speed_rmp = ((unsigned char) msg.data[1]
                                +((unsigned int) msg.data[2] << 8))*0.125; //�����ת��
                        Eng_static_test = (msg.data[7] >> 4)&0x03; //��������̬ת�ٲ���
                        tcu_start_allow = (msg.data[7] >> 6)&0x03; //��������������
                        break;


                    case 0x18F00503://ETC2 TCU
                        Current_Gear = msg.data[3];
                        break;

                    case 0x18FECA03:// DM1 TCU
                        for (i = 0; i < 6; i++) {
                            CAN_18FECA03.bData[i] = msg.data[i];
                        }
                        CAN_18FECA03_len = 0x06; //n_can.len;
                        break;

                    case 0x1CECFF03://TPCM TCU
                        if (msg.data[0] == 0x20) {
                            if (msg.data[5] == 0xCA && msg.data[6] == 0xFE) {
                                n_can.len = msg.data[1]+((unsigned int) msg.data[2] << 8);
                                n_can.pack = msg.data[3];
                                n_can.flag = 1; //CAN���տ�ʼ���
                            }
                        }
                        break;

                    case 0x1CEBFF03://TPDT TCU
                        if (n_can.flag == 1) {
                            if (msg.data[0] <= n_can.pack) {
                                unsigned int slen;
                                slen = (msg.data[0] - 1)*7;
                                for (i = 0; i < 7; i++) {
                                    n_can.buf[slen+i] = msg.data[i + 1];
                                }
                            }
                            if (msg.data[0] == n_can.pack) {
                                for (i = 0; i < n_can.len; i++) {
                                    CAN_18FECA03.bData[i] = n_can.buf[i];
                                }
                                CAN_18FECA03_len = n_can.len;
                                n_can.flag = 0; //����ɽ���
                            }
                        }
                        break;
                
                    case 0x18FECAF5:// DM1 CCU
                        for (i = 0; i < 6; i++) {
                            CAN_18FECAF5.bData[i] = msg.data[i];
                        }
                        CAN_18FECAF5_len = 0x06; //i_can.len;
                        break;
                
                    case 0x18FECA00:// DM1 ECU
                        for (i = 0; i < 6; i++) {
                            CAN_18FECA00.bData[i] = msg.data[i];
                        }
                        CAN_18FECA00_len = 0x06; //e_can.len;
                
                        break;
                
                
                
                        ////////////////////////////////////////////////////////////////////////////////          
                    case 0x18EF4CEF://BMS Cell voltage Information Message
                        Brake_percent = msg.data[6];
                        break;

                    case 0x18EF4DEF://Hybrid Temperature Information Message
                        Motor_Temperature = msg.data[3];
                        break;

                    case 0x18EF0AEF:// Hybrid_ENG_Control
                        ENG_start_req = (unsigned char) msg.data[0]
                                +((unsigned int) msg.data[1] << 8);
                        mot_work_time = (unsigned char) msg.data[2]
                                +((unsigned int) msg.data[3] << 8)
                                +((unsigned long) msg.data[4] << 16)
                                +((unsigned long) msg.data[5] << 24);
                        mot_work_percent = msg.data[6];
                        DCDC_ctrl = msg.data[7]&0x03;
                        hcu_starter_forbid = (msg.data[7] >> 2)&0x03;
                        aircompress_enable = (msg.data[7] >> 4)&0x03;
                        Brake_Pedal = (msg.data[7] >> 6)&0x03;
                        break;

                    case 0x0CF00300://Electronic Engine Controller 2 (EEC2)
                        Accelerator = msg.data[1];
                        break;

                    case 0x18FEEE00://ˮ��
                        water_temp = (unsigned char) msg.data[0];
                        break;

                    case 0x18FEEF00://ˮλ�ͻ���ѹ��
                        Engine_oil_press = (unsigned int) (msg.data[3]*4);
                        water_level = (unsigned char) (msg.data[7]*0.4);
                        break;

                    case 0x18FEE400://�������ȴ�����
                        Wait_start = (unsigned char) (msg.data[3]&0x03);
                        //water_level=(unsigned char)(msg.data[7]*0.4);  
                        break;

                    case 0x18FEF600: //��Χ�������� id==0x18FEF600
                        //barometric_pressure = msg.data[1]; //��ѹѹ�� 0.5Kpa
                        ambient_air_temperature = msg.data[2]; //��Χ�����¶�
                        //air_pressure = msg.data[3]; //����ѹ�� 0.5Kpa
                        break;
                 */
#endif
        }
        for (i = 0; i < 50; i++) {
            if (msg.id == (0x1800DC03 + ((long) i << 16))) {
                BAT_Single_Voltage[i * 4] = (unsigned char) msg.data[0]+((unsigned int) msg.data[1] << 8);
                BAT_Single_Voltage[(i * 4) + 1] = (unsigned char) msg.data[2]+((unsigned int) msg.data[3] << 8);
                BAT_Single_Voltage[(i * 4) + 2] = (unsigned char) msg.data[4]+((unsigned int) msg.data[5] << 8);
                BAT_Single_Voltage[(i * 4) + 3] = (unsigned char) msg.data[6]+((unsigned int) msg.data[7] << 8);
            }
        }
        for (i = 0; i < 50; i++) {
            if (msg.id == (0x1800DD03 + ((long) i << 16))) {
                BAT_Single_Temp[i * 8] = (unsigned char) msg.data[0];
                BAT_Single_Temp[(i * 8) + 1] = (unsigned char) msg.data[1];
                BAT_Single_Temp[(i * 8) + 2] = (unsigned char) msg.data[2];
                BAT_Single_Temp[(i * 8) + 3] = (unsigned char) msg.data[3];
                BAT_Single_Temp[(i * 8) + 4] = (unsigned char) msg.data[4];
                BAT_Single_Temp[(i * 8) + 5] = (unsigned char) msg.data[5];
                BAT_Single_Temp[(i * 8) + 6] = (unsigned char) msg.data[6];
                BAT_Single_Temp[(i * 8) + 7] = (unsigned char) msg.data[7];
            }
        }
    }
    C2INTF = 0; /* the individual flag register cleared */
    C2RX0CONbits.RXFUL = 0;
    IFS2bits.C2IF = 0;
}
