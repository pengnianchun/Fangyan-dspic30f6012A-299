/*
 * File:   APP_CAN_Receive.c
 * Author: pnc
 *
 * Created on 2017年7月28日, 下午6:02
 */

#include "APP_System.h"

/*******************分包处理*****************/

DM1 CAN_18FECAEF;
unsigned char CAN_18FECAEF_len;
DM1 CAN_18FECA03;
unsigned char CAN_18FECA03_len;
DM1 CAN_18FECAF5;
unsigned char CAN_18FECAF5_len;
DM1 CAN_18FECA00;
unsigned char CAN_18FECA00_len;
DM1 CAN_18FECAD0;
unsigned char CAN_18FECAD0_len;
CAN_CACHE m_can;
CAN_CACHE n_can;
CAN_CACHE c_can;
CAN_CACHE e_can;
unsigned long SPN[5]; //从缓存里提取的故障码
unsigned char FMI[5];
/*******************分包处理*****************/
//整车控制器信息1 0x0CFFC9D0
unsigned char VCU_Status;
unsigned char VCU_Gear;
unsigned char VCU_Lock_Warn;
unsigned char VCU_Brake_Warn;
unsigned char VCU_Car_Status;
unsigned char VCU_Run_Status;
unsigned int  VCU_Speed;
unsigned char VCU_Gearbox;
unsigned char VCU_Brake_Status;
unsigned char VCU_Power_Status;
unsigned char VCU_Charge;
unsigned char VCU_Warn_Level;

//整车控制器信息2 0x0CFFC8D0
unsigned char VCU_Accelerator_percent; //油门踏板开度
unsigned char VCU_Brake_percent; //制动踏板开度
unsigned char VCU_Fault_Number; //其他故障总数
unsigned long VCU_Fault_List; //故障列表
unsigned char VCU_Motor_Number; 

//整车控制器控制信息 3（0x0CFFCAD0）
/*unsigned char VCU_Control_OCU;
unsigned char VCU_Control_ACU;
unsigned char VCU_Control_DCDC;
unsigned char VCU_Control_AIR;*/

//主驱状态 1（0x18F501F0）
unsigned char MCU_Number;
unsigned char MCU_Status;
unsigned char MCU_Temp = 40;
unsigned char MCU_Controller_Temp = 40;
unsigned int  MCU_Voltage;
unsigned int  MCU_Curretn = 10000;

//主驱状态 2（0x18F502F0）
unsigned int  MCU_Rpm = 20000;
unsigned int  MCU_Torque = 20000;

//主驱状态 3（0x18F503F0）
unsigned char MCU_Controller_Warn_Temp;
unsigned char MCU_Warn_Temp;
unsigned char MCU_Warn_Number;

//系统故障信息（0x18FECAD0）

//电池管理系统信息 1（0x18F201F3）
unsigned char BMS_SOC;
unsigned int  BMS_Voltage; //电池总电压
unsigned int  BMS_Current = 10000; //电池总电流
unsigned char BMS_Charge_Power_Limt; 
unsigned char BMS_Discharge_Power_Limt; 
unsigned char BMS_Life; 

//高压接触器信息（0x18F202F3）
DATA_DOUBLE   CM_Connecter_Status[2];
unsigned char CM_Up_Status;
unsigned char CM_Down_Status;

//电池报警信息（0x18F203F3）
unsigned char BMS_Fault_Code;
unsigned char BMS_Fault_Level;
DATA_BIT      BMS_Charge_Status;
unsigned char BMS_Self_Status;
DATA_BIT      BMS_Warn_Message[4];

//电池仓火灾报警信息（0x18F209F3）
DATA_BIT      BCEM_Warn_Message[8];

//电池仓火灾报警温度信息（0x18F20AF3）
unsigned char BCTM_Temp[8];

//电池单体电压信息（0x18F204F3）
unsigned int  Battery_Single_H; //电池单体高电压
unsigned int  Battery_Single_L; //电池单体低电压
unsigned char Battery_Single_H_Positon_Case; //电池单体高电压箱号
unsigned char Battery_Single_H_Positon_Cell; //电池单体高电压位置
unsigned char Battery_Single_L_Positon_Case; //电池单体低电压箱号
unsigned char Battery_Single_L_Positon_Cell; //电池单体低电压位置

//电池单体温度信息（0x18F205F3）
unsigned char Battery_Temp_H = 40; //电池单体最高温度
unsigned char Battery_Temp_L = 40; //电池单体最低温度
unsigned char Battery_Temp_H_Positon_Case; //电池单体高温度箱号
unsigned char Battery_Temp_H_Positon_Cell; //电池单体高温度位置
unsigned char Battery_Temp_L_Positon_Case; //电池单体低温度箱号
unsigned char Battery_Temp_L_Positon_Cell; //电池单体低温度位置

//绝缘检测仪信息（0x18FF2B49）
unsigned char IDE_Message;
unsigned int  IDE_Ohm;
unsigned int  IDE_Voltage;
unsigned char IDE_Life;

//气泵系统信息
unsigned char ACU_Status; //气泵控制器基本状态
unsigned char ACU_Fault_Code; //气泵控制器故障码
unsigned char ACU_Power; //气泵控制器功率
unsigned char ACU_Temp; //气泵电机温度
unsigned char ACU_Controller_temp; //气泵控制器温度
unsigned int  ACU_Voltage; //气泵控制器母线电压
unsigned int  ACU_Rpm; //气泵控制器电机转速

//油泵系统信息
unsigned char OCU_Status; //气泵控制器基本状态
unsigned char OCU_Fault_Code; //气泵控制器故障码
unsigned char OCU_Power; //气泵控制器功率
unsigned char OCU_Temp; //气泵电机温度
unsigned char OCU_Controller_temp; //气泵控制器温度
unsigned int  OCU_Voltage; //气泵控制器母线电压
unsigned int  OCU_Rpm; //气泵控制器电机转速

//DCDC系统信息
unsigned char DCDC_Status; //DCDC基本状态
unsigned char DCDC_CAN_Warn; //DCDC通讯报警
unsigned char DCDC_Temp_Warn; //DCDC温度报警
unsigned char DCDC_Status_Warn; //DCDC状态报警
unsigned char DCDC_Fault_Code; //DCDC故障代码
unsigned char DCDC_Temp; //DCDC模块温度
unsigned int  DCDC_Current; //DCDC输出电流
unsigned char DCDC_Output_Voltage; //DCDC输出电压
unsigned int  DCDC_Voltage; //DCDC母线电压

void __attribute__((__interrupt__, auto_psv)) _C2Interrupt(void) {
    unsigned char i = 0;
    CAN_MESSAGE msg;
    if (C2INTFbits.ERRIF) { //接收错误
        C2INTFbits.ERRIF = 0; // 添加错误处理代码
        CAN2_Init();
        C2RX0CONbits.RXFUL = 0;
    }
    if (C2INTFbits.IVRIF) {
        C2INTFbits.IVRIF = 0; //数据无效
        C2RX0CONbits.RXFUL = 0;
    }
    if (C2RX0CONbits.RXFUL) { //数据有效
        CAN2_ReceiveMessage(&msg);
        switch (msg.id) {
            case 0x0CFFC9D0://整车控制器信息1
                Vcan_count = 0;
                VCU_Status = msg.data[0]&0x07;
                VCU_Gear = (msg.data[0] >> 3) & 0x07;
                VCU_Lock_Warn = (msg.data[0] >> 6) & 0x01;
                VCU_Brake_Warn = (msg.data[0] >> 7) & 0x01;
                VCU_Car_Status = msg.data[1];
                VCU_Run_Status = msg.data[2];
                VCU_Speed = ((unsigned char) msg.data[3]+((unsigned int) msg.data[4] << 8));
                VCU_Gearbox = msg.data[5] & 0x0F;
                VCU_Brake_Status = (msg.data[5] >> 4) & 0x01;
                VCU_Power_Status = (msg.data[5] >> 5) & 0x01;
                VCU_Charge = msg.data[6];
                VCU_Warn_Level = msg.data[7];
                break;

            case 0x0CFFC8D0://整车控制器信息 2
                Vcan_count = 0;
                VCU_Accelerator_percent = msg.data[0];
                VCU_Brake_percent = msg.data[1];
                VCU_Fault_Number = msg.data[2];
                VCU_Fault_List = ((unsigned char) msg.data[3]
                                +((unsigned int)  msg.data[4] << 8)
                                +((unsigned long) msg.data[5] << 16)
                                +((unsigned long) msg.data[6] << 24));
                VCU_Motor_Number = msg.data[7];
                break;
                
            case 0x18F501F0://主驱状态 1
                Vcan_count = 0;
                MCU_Number = msg.data[0];
                MCU_Status = msg.data[1];
                MCU_Temp = msg.data[2];
                MCU_Controller_Temp = msg.data[3];
                MCU_Voltage = (unsigned char) msg.data[4]+((unsigned int) msg.data[5] << 8);
                MCU_Curretn = (unsigned long) msg.data[6]+((unsigned long) msg.data[7] << 8);
                break;    
                
            case 0x18F502F0://主驱状态 2
                Vcan_count = 0;
                MCU_Number = msg.data[0];
                MCU_Rpm = (unsigned char) msg.data[1]+((unsigned int) msg.data[2] << 8);
                MCU_Torque = (unsigned char) msg.data[3]+((unsigned int) msg.data[4] << 8);
                break;  
                
            case 0x18F503F0://主驱状态 3
                Vcan_count = 0;
                MCU_Number = msg.data[0];
                MCU_Controller_Warn_Temp = msg.data[1] & 0x01;
                MCU_Warn_Temp = (msg.data[1] >> 1) & 0x01;
                MCU_Warn_Number = msg.data[2];
                break; 
                
            case 0x18FECAD0://系统故障信息
                for (i = 0; i < 6; i++) {
                            CAN_18FECAD0.bData[i] = msg.data[i];
                        }
                        CAN_18FECAD0_len = 0x06;
                break; 
                
            case 0x18F201F3://电池管理系统信息 1
                Vcan_count = 0;
                BMS_SOC = msg.data[0];
                BMS_Voltage = ((unsigned char) msg.data[1]+((unsigned int) msg.data[2] << 8)); //电池总电压
                BMS_Current = ((unsigned char) msg.data[3]+((unsigned int) msg.data[4] << 8)); //电池总电流
                BMS_Charge_Power_Limt = msg.data[5]; 
                BMS_Discharge_Power_Limt = msg.data[6];
                BMS_Life = msg.data[7]; 
                break;    
                
            case 0x18F202F3://高压接触器信息
                CM_Connecter_Status[0].byte =  msg.data[0];
                CM_Connecter_Status[1].byte =  msg.data[1];
                CM_Up_Status =  msg.data[2];
                CM_Down_Status =  msg.data[3];
                break;
                
            case 0x18F203F3://电池报警信息
                BMS_Fault_Code = msg.data[0];
                BMS_Fault_Level =  msg.data[1];
                BMS_Charge_Status.byte =  msg.data[2]; 
                BMS_Self_Status =  msg.data[3];
                BMS_Warn_Message[0].byte = msg.data[4];
                BMS_Warn_Message[1].byte = msg.data[5];
                BMS_Warn_Message[2].byte = msg.data[6];
                BMS_Warn_Message[3].byte = msg.data[7];
                break;

            case 0x18F209F3://电池仓火灾报警信息
                for (i = 0; i < 8; i++)
                    BCEM_Warn_Message[i].byte = msg.data[i];
                break;
                
            case 0x18F20AF3://电池仓火灾报警温度信息
                for (i = 0; i < 8; i++)
                    BCTM_Temp[i] = msg.data[i];
                break;    
                
            case 0x18F204F3://电池单体电压信息
                Battery_Single_H = ((unsigned char) msg.data[0]+((unsigned int) msg.data[1] << 8));
                Battery_Single_L = ((unsigned char) msg.data[2]+((unsigned int) msg.data[3] << 8));
                Battery_Single_H_Positon_Case = msg.data[4];
                Battery_Single_H_Positon_Cell = msg.data[5];
                Battery_Single_L_Positon_Case = msg.data[6];
                Battery_Single_L_Positon_Cell = msg.data[7];
                break;      
            
            case 0x18F205F3://电池单体温度信息
                Battery_Temp_L = msg.data[0];
                Battery_Temp_H = msg.data[1];
                Battery_Temp_L_Positon_Case = msg.data[2];
                Battery_Temp_L_Positon_Cell = msg.data[3];
                Battery_Temp_H_Positon_Case = msg.data[4];
                Battery_Temp_H_Positon_Cell = msg.data[5];
                break;     
                
            case 0x18FF2B49://绝缘检测仪信息
                IDE_Message = msg.data[0];
                IDE_Ohm = ((unsigned char) msg.data[1]+((unsigned int) msg.data[2] << 8));
                IDE_Voltage = ((unsigned char) msg.data[3]+((unsigned int) msg.data[4] << 8));
                IDE_Life = msg.data[7];
                break;    
            
            case 0x1801A79D://气泵系统信息  
                Vcan_count = 0;
                ACU_Status = msg.data[0] & 0x03;
                ACU_Fault_Code = (msg.data[0] >> 2) & 0x3F;
                ACU_Power = msg.data[1];
                ACU_Temp = msg.data[2];
                ACU_Controller_temp = msg.data[3];
                ACU_Voltage = (unsigned char) msg.data[4]+((unsigned int) msg.data[5] << 8);
                ACU_Rpm = (unsigned char) msg.data[6]+((unsigned int) msg.data[7] << 8);
                break;    
                
            case 0x1801A79B://油泵系统信息  
                Vcan_count = 0;
                OCU_Status = msg.data[0] & 0x03;
                OCU_Fault_Code = (msg.data[0] >> 2) & 0x3F;
                OCU_Power = msg.data[1];
                OCU_Temp = msg.data[2];
                OCU_Controller_temp = msg.data[3];
                OCU_Voltage = (unsigned char) msg.data[4]+((unsigned int) msg.data[5] << 8);
                OCU_Rpm = (unsigned char) msg.data[6]+((unsigned int) msg.data[7] << 8);
                break; 

            case 0x1806A6A8://DCDC信息  
                Vcan_count = 0;
                DCDC_Status = msg.data[0] & 0x03;
                DCDC_CAN_Warn = (msg.data[0] >> 2) & 0x03; 
                DCDC_Temp_Warn = (msg.data[0] >> 4) & 0x01;
                DCDC_Status_Warn = (msg.data[0] >> 5) & 0x01;;
                DCDC_Fault_Code = msg.data[1];
                DCDC_Temp = msg.data[2];
                DCDC_Current = (unsigned char) msg.data[3]+((unsigned int) msg.data[4] << 8);
                DCDC_Output_Voltage = msg.data[5];
                DCDC_Voltage = (unsigned char) msg.data[6]+((unsigned int) msg.data[7] << 8);
                break;    
                
                
            /*case 0x1004FF1e://DMCRD3
                Vcan_count = 0;
                DMC_Accelerator_percent = msg.data[0];
                DMC_Brake_percent = msg.data[1];
                DMC_Charge = msg.data[2]&0x03;
                DMC_GB_Gear = msg.data[3];
                break;

            case 0x1429289B://DMQRD1  
                Vcan_count = 0;
                  DMQ_Rpm = (unsigned char) msg.data[0]+((unsigned int) msg.data[1] << 8);
                DMQ_Voltage = (unsigned char) msg.data[2]+((unsigned int) msg.data[3] << 8);
                DMQ_Current = msg.data[4];
                DMQ_temp = msg.data[5];
                DMQ_Life = msg.data[6];
                DMQ_Status = msg.data[7];
                break;

            case 0x142A289B://DMQRD2  
                Vcan_count = 0;
                DMQ_Controller_temp = msg.data[0];
                break;

            case 0x1828272B://DCDC  
                Vcan_count = 0;
                DCDC_Status = msg.data[0];
                DCDC_Temp = msg.data[1];
                DCDC_Voltage = (unsigned char) msg.data[2]+((unsigned int) msg.data[3] << 8);
                DCDC_Current = (unsigned char) msg.data[4]+((unsigned int) msg.data[5] << 8);
                DCDC_Code = msg.data[6];
                DCDC_Verison = msg.data[7];
                break;

            case 0x142A2895://DMYTD1  
                Vcan_count = 0;
                DMY_Rpm = (unsigned char) msg.data[0]+((unsigned int) msg.data[1] << 8);
                DMY_Voltage = (unsigned char) msg.data[2]+((unsigned int) msg.data[3] << 8);
                DMY_Current = msg.data[4];
                DMY_Controller_temp = msg.data[5];
                DMY_Life = msg.data[6];
                DMY_Status = msg.data[7];
                break;

            case 0x18AA28F3://BMS_LCD01
                Bcan_count = 0;
                if (msg.data[0] == 1) {
                    Battery_Case_Total_Number = msg.data[1];
                    BMS_Unit_Number = msg.data[2];
                    Battery_Cell_Total_Number = (unsigned char) msg.data[4]+((unsigned int) msg.data[3] << 8);
                    BMS_Nubmer = (unsigned char) msg.data[6]+((unsigned int) msg.data[5] << 8);
                } else if (msg.data[0] == 2) {
                    Battery_Case_number = msg.data[1];
                    Battery_Cell_number = msg.data[2];
                    Battery_Cell_Temp_Number = msg.data[3];
                }
                break;

            case 0x1818D0F3://BMSCAN2_B1
                Bcan_count = 0;
                BMS_V = ((unsigned char) msg.data[1]
                        +((unsigned int) msg.data[0] << 8));
                BMS_A = ((unsigned char) msg.data[3]
                        +((unsigned int) msg.data[2] << 8));
                BMS_SOC = msg.data[4];
                BMS_Life = msg.data[5];
                BMS_Status_Flag1 = msg.data[6];
                BMS_Status_Flag2 = msg.data[7];
                break;

            case 0x1819D0F3://BMSCAN2_B2
                Bcan_count = 0;
                Battery_Single_H = ((unsigned char) msg.data[1]
                        +((unsigned int) msg.data[0] << 8));
                Battery_Single_L = ((unsigned char) msg.data[3]
                        +((unsigned int) msg.data[2] << 8));
                Battery_Temp_H = msg.data[4];
                Battery_Temp_L = msg.data[5];
                BMS_Status_Flag3 = msg.data[6];
                BMS_Status_Flag4 = msg.data[7];
                break;

            case 0x181AD0F3://BMSCAN2_B3
                Bcan_count = 0;
                Battery_Single_H_Positon_Case = msg.data[0];
                Battery_Single_H_Positon_Cell = msg.data[1];
                Battery_Single_L_Positon_Case = msg.data[2];
                Battery_Single_L_Positon_Cell = msg.data[3];
                Battery_Temp_H_Positon_Case = msg.data[4];
                Battery_Temp_H_Positon_Cell = msg.data[5];
                Battery_Temp_L_Positon_Case = msg.data[6];
                Battery_Temp_L_Positon_Cell = msg.data[7];
                break;

            case 0x181BD0F3://BMSCAN2_B4
                Bcan_count = 0;
                BMU_Comm_Status1 = msg.data[0];
                BMU_Comm_Status2 = msg.data[1];
                BMU_Comm_Status3 = msg.data[2];
                BMU_Comm_Status4 = msg.data[3];
                break;

            case 0x181CD0F3://BMSCAN2_B5
                Bcan_count = 0;
                BMU_Bala_Status1 = msg.data[0];
                BMU_Bala_Status2 = msg.data[1];
                BMU_Bala_Status3 = msg.data[2];
                BMU_Bala_Status4 = msg.data[3];
                break;

            case 0x181DD0F3://BMSCAN2_B6
                Bcan_count = 0;
                DC1positive_Temp = msg.data[0];
                DC1negative_Temp = msg.data[1];
                DC2positive_Temp = msg.data[2];
                DC2negative_Temp = msg.data[3];
                Ohm_Positive = ((unsigned char) msg.data[5]
                        +((unsigned int) msg.data[4] << 8));
                Ohm_Negative = ((unsigned char) msg.data[7]
                        +((unsigned int) msg.data[6] << 8));
                break;

            case 0x181ED0F3://BMSCAN2_B7
                Bcan_count = 0;
                Energe_Rest = ((unsigned char) msg.data[1]
                        +((unsigned int) msg.data[0] << 8));
                BMS_Status_Flag5 = msg.data[2];
                BMS_Status_Flag6 = msg.data[3];
                break;

            case 0x181FD0F3://BMSCAN2_B8
                Bcan_count = 0;
                Battery_Single_H_Positon_Total = msg.data[0];
                if (Battery_Single_H_Positon_Total > 200) {
                    Battery_Single_H_Positon_Total -= 200;
                }
                Battery_Single_L_Positon_Total = msg.data[1];
                if (Battery_Single_L_Positon_Total > 200) {
                    Battery_Single_L_Positon_Total -= 200;
                }
                Battery_Temp_H_Positon_Total = msg.data[2];
                if (Battery_Temp_H_Positon_Total > 200) {
                    Battery_Temp_H_Positon_Total -= 200;
                }
                Battery_Temp_L_Positon_Total = msg.data[3];
                if (Battery_Temp_L_Positon_Total > 200) {
                    Battery_Temp_L_Positon_Total -= 200;
                }
                Battery_Single_H_Pack = msg.data[4];
                Battery_Single_L_Pack = msg.data[5];
                Battery_Temp_H_Pack = msg.data[6];
                Battery_Temp_L_Pack = msg.data[7];
                break;

            case 0x180028F3://BMS_LCD02
                if (msg.data[0] == BMU_Number) {
                    for (i = 0; i < 4; i++) {
                        if (msg.data[1] == i + 1) {
                            Battery_Voltage[i * 3] = ((unsigned char) msg.data[3]
                                    +((unsigned int) msg.data[2] << 8));
                            Battery_Voltage[i * 3 + 1] = ((unsigned char) msg.data[5]
                                    +((unsigned int) msg.data[4] << 8));
                            Battery_Voltage[i * 3 + 2] = ((unsigned char) msg.data[7]
                                    +((unsigned int) msg.data[6] << 8));
                        }
                    }
                } else {
                    for (i = 0; i < 4; i++) {
                        Battery_Voltage[i * 3] = 0xFFFF;
                        Battery_Voltage[i * 3 + 1] = 0xFFFF;
                        Battery_Voltage[i * 3 + 2] = 0xFFFF;
                    }
                }
                break;

            case 0x180028F4://BCTDT1
                if (msg.data[0] == BMU_Number) {
                    for (i = 0; i < 2; i++) {
                        if (msg.data[1] == i + 1) {
                            Battery_Temp[i * 6] = msg.data[2];
                            Battery_Temp[i * 6 + 1] = msg.data[3];
                            Battery_Temp[i * 6 + 2] = msg.data[4];
                            Battery_Temp[i * 6 + 3] = msg.data[5];
                            Battery_Temp[i * 6 + 4] = msg.data[6];
                            Battery_Temp[i * 6 + 5] = msg.data[7];
                        }
                    }
                } else {
                    for (i = 0; i < 2; i++) {
                        Battery_Temp[i * 6] = 0xFF;
                        Battery_Temp[i * 6 + 1] = 0xFF;
                        Battery_Temp[i * 6 + 2] = 0xFF;
                        Battery_Temp[i * 6 + 3] = 0xFF;
                        Battery_Temp[i * 6 + 4] = 0xFF;
                        Battery_Temp[i * 6 + 5] = 0xFF;
                    }
                }
                break;

            case 0x18FFC09E://Air
                Vcan_count = 0;
                Air_Status_Flag1 = msg.data[0];
                Air_Status_Flag2 = msg.data[1];
                Air_Status_Flag3 = msg.data[2];
                Air_Indoor_t = msg.data[3];
                Air_Outdoor_t = msg.data[4];
                Air_Set_t = msg.data[5];
                break;*/


                /*   
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
                                m_can.flag = 1; //CAN接收开始标记
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
                                m_can.flag = 0; //已完成接收
                            }
                        }

                        break;
                        //////////////////////////////////////////////////////////////////////////////////            
                    case 0x0CF00203://ETC1 TCU
                        Speed_rmp = ((unsigned char) msg.data[1]
                                +((unsigned int) msg.data[2] << 8))*0.125; //输出轴转速
                        Eng_static_test = (msg.data[7] >> 4)&0x03; //发动机稳态转速测试
                        tcu_start_allow = (msg.data[7] >> 6)&0x03; //发动机运行启动
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
                                n_can.flag = 1; //CAN接收开始标记
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
                                n_can.flag = 0; //已完成接收
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

                    case 0x18FEEE00://水温
                        water_temp = (unsigned char) msg.data[0];
                        break;

                    case 0x18FEEF00://水位和机油压力
                        Engine_oil_press = (unsigned int) (msg.data[3]*4);
                        water_level = (unsigned char) (msg.data[7]*0.4);
                        break;

                    case 0x18FEE400://发动机等待启动
                        Wait_start = (unsigned char) (msg.data[3]&0x03);
                        //water_level=(unsigned char)(msg.data[7]*0.4);  
                        break;

                    case 0x18FEF600: //周围环境条件 id==0x18FEF600
                        //barometric_pressure = msg.data[1]; //增压压力 0.5Kpa
                        ambient_air_temperature = msg.data[2]; //周围空气温度
                        //air_pressure = msg.data[3]; //进气压力 0.5Kpa
                        break;
                 */
        }
    }
    C2INTF = 0; /* the individual flag register cleared */
    C2RX0CONbits.RXFUL = 0;
    IFS2bits.C2IF = 0;
}

void DM(unsigned char x, DM1 id,unsigned char i){//解析出id的第x个故障码的spn和fmi,放在第i个SPN[i]里
    *(SPN+i) = id.bData[2 + 4 * (x - 1)]
            +((unsigned int) id.bData[3 + 4 * (x - 1)] << 8)
            +((unsigned long) (id.bData[4 + 4 * (x - 1)]&0xE0) << 11);
    *(FMI+i)= (id.bData[4 + 4 * (x - 1)] & 0x1F);
}