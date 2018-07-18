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
DM1 CAN_18FECAF3;
unsigned char CAN_18FECAF3_len;
CAN_CACHE m_can;
CAN_CACHE n_can;
CAN_CACHE c_can;
CAN_CACHE e_can;
CAN_CACHE b_can;
unsigned long SPN; //从缓存里提取的故障码
unsigned char FMI;
/******************************************/
//电池基本信息 ID:0x18F201F3
unsigned char BMS_SOC;     //电池SOC
unsigned int  BMS_V;       //电池电压
unsigned int  BMS_A=32000; //电池电流
unsigned int  BMS_Number;  //电池组总串数
unsigned char BMS_Life;     //BMSlife

//电池基本信息 2 ID:0x18F202F3
unsigned char BMS_Current_Charge_Limit_Long = 200;
unsigned char BMS_Current_Charge_Limit_Short = 200;
unsigned char BMS_Current_Disharge_Limit_Long;
unsigned char BMS_Current_Disharge_Limit_Short;
DATA_BIT      BMS_KT_Status;
unsigned char BMS_Cut;

//电池故障报警信息 ID:0x18F205F3
DATA_DOUBLE   BMS_Warn[4];
DATA_BIT      BMS_Fault[3];
unsigned char BMS_Self_Check;//BMS自检状态

//电池单体最高电压信息 0x18F206F3 // 0x18F207F3
unsigned int  BAT_Max_Cell_Voltage[4]; //电池单体高电压
unsigned char BAT_Max_Cell_Voltage_Cell_Case[4]; //最高单体电压箱号
unsigned char BAT_Max_Cell_Voltage_Cell_Number[4]; //最低单体电压位置

//电池单体最低电压信息 0x18F208F3 // 0x18F209F3
unsigned int  BAT_Min_Cell_Voltage[4]; //电池单体低电压
unsigned char BAT_Min_Cell_Voltage_Cell_Case[4]; //最低单体电压箱号
unsigned char BAT_Min_Cell_Voltage_Cell_Number[4]; //最低单体电压位置

//电池最高温度信息 ID:0x18F20AF3
unsigned int  BAT_Max_Cell_Temperature[4]; //最高单体温度
unsigned char BAT_Max_Cell_Temp_Cell_Case[4]; //最高单体温度箱号

//电池最低温度信息 ID:0x18F20BF3
unsigned int  BAT_Min_Cell_Temperature[4]; //最低单体温度
unsigned char BAT_Min_Cell_Temp_Cell_Case[4]; //最低单体温度箱号

//电池极柱温度信息
unsigned char BAT_Pole_Temperature_P[16];//正极柱温度
unsigned char BAT_Pole_Temperature_N[16];//负极柱温度

//电池箱体在线状态 ID:0x185017F3
DATA_BIT      BMU_Comm_Status[4]; //电池箱在线状态
unsigned char BMS_Unit_Number;    //电池箱个数

//电池组基本信息 1（厂家容量） ID: 0x18F20CF3
unsigned char BAT_Productor;     //电池生产厂家
unsigned char BAT_Ahr;           //电池额定容量
unsigned char BAT_Voltage;       //电池额定电压
unsigned int  BAT_Charge_Times;  //电池充电次数
unsigned char BAT_Material;      //电池材料
unsigned char BAT_Time_Month;    //电池生产月份
unsigned char BAT_Time_Year;     //电池生产年份
unsigned char BAT_Verison;       //BMS程序版本号

//绝缘检测仪 ID:0x18FF2B49
unsigned char Oum_Status;  //绝缘检测仪状态
unsigned char Oum_Warn;    //绝缘检测仪报警
unsigned int  Oum;         //绝缘阻值
unsigned int  Oum_Voltage; //绝缘阻值
unsigned char Oum_Life;    //绝缘检测仪LIFE

//整车控制器状态信息 1 ID:0x18F101D0
DATA_DOUBLE   VCU_Status;  
unsigned int  VCU_SPEED;
unsigned char VCU_Gear;
unsigned char VCU_Clutch;
DATA_BIT      VCU_Fault;
unsigned char VCU_Code;
unsigned char VCU_CarMode;
unsigned char VCU_Life;

//整车控制器状态信息 2 ID:0x18F103D0
unsigned char VCU_Verison;
unsigned int  VCU_KM;
unsigned char VCU_TM_Speed_percent; //加速踏板开度
unsigned char VCU_TM_Brake_percent; //制动踏板开度
unsigned char VCU_Kwh_100Km;


//VCU 使能控制 ID:0x18F105D0
DATA_BIT      VCU_Enable[4];

//高压柜状态信息 ID:0x18F106D0
DATA_BIT      VCU_KT_Control;
DATA_BIT      VCU_KT_Status;
DATA_BIT      BMS_KT_Status;

//电机控制器状态信息 1 ID:0x18F501F0
unsigned char MCU_Temp = 40; //电机温度
unsigned char MCU_Control_Temp = 40; //电机控制器温度
unsigned int  MCU_Voltage; //电机母线电压
unsigned char MCU_SelfStatus; //电机自检状态
unsigned char MCU_Status; //电机状态
DATA_BIT      MCU_Fault;
unsigned char MCU_Code;   //电机故障码

//电机控制器状态信息 2 ID:0x18F502F0
unsigned int  MCU_RPM;                 //电机转速
unsigned int  MCU_NM = 2000;                  //电机扭矩
unsigned int  MCU_POWER = 200;               //电机功率
unsigned int  MCU_Current = 32000;     //电机电流

//电机控制器状态信息 3 ID:0x18F503F0
unsigned int  MCU_Output_Voltage; //电机输出电压
unsigned int  MCU_Phase_Current;  //电机相电流

//助力油泵发送报文状态 ID 0x0CF601A0
unsigned int  OILDCAC_Voltage;   //DCAC输出电压
unsigned char OILDCAC_Current;   //DCAC输出电流
unsigned char OILDCAC_Temp = 40; //DCAC电机温度
DATA_BIT      OILDCAC_Status;    //DCAC工作状态
unsigned char OILDCAC_Life;      //DCAC Life
   
//DC/DC 发送报文状态 ID 0x0CF602A1
unsigned char DCDC_Status; //DCDC工作状态
unsigned char DCDC_Output_Current; //DCDC输出电流
unsigned char DCDC_Output_Voltage; //DCDC输出电压
unsigned char DCDC_Temp = 40;      //DCDC模块温度
DATA_BIT      DCDC_Fault_Warn;     //DCDC故障报警
unsigned int  DCDC_Input_Voltage;  //DCDC输入电压
unsigned char DCDC_Life;           //DCDC Life

//气泵发送报文状态 ID 0x0CF603A2
unsigned int  AIRDCAC_Voltage;   //DCAC输出电压
unsigned char AIRDCAC_Current;   //DCAC输出电流
DATA_BIT      AIRDCAC_Status;    //DCAC工作状态
unsigned char AIRDCAC_Temp = 40; //DCAC电机温度
unsigned char AIRDCAC_Life;      //DCAC Life

//空调控制报文状态 ID 0x0CF605A3
unsigned char AC_Status;   //
unsigned char AC_Indoor_Temp; 
unsigned char AC_Gear; 
unsigned char AC_WindMode; 
unsigned char AC_Work_Status; 
unsigned char AC_Outdoor_Temp; 
unsigned char AC_Fault_Code; 
unsigned char AC_Life; 

unsigned char AC_Set_Temp;

void DM(unsigned char x, DM1 id) {//解析出id的第x个故障码的spn和fmi
    SPN = id.bData[2 + 4 * (x - 1)]
            +((unsigned int) id.bData[3 + 4 * (x - 1)] << 8)
            +((unsigned long) (id.bData[4 + 4 * (x - 1)]&0xE0) << 11);
    FMI = (id.bData[4 + 4 * (x - 1)] & 0x1F);
}

void __attribute__((__interrupt__, auto_psv)) _C2Interrupt(void) {
    unsigned char i = 0,temp = 0;
    CAN_MESSAGE msg;
    //DATA_DOUBLE CAN_DOUBLE;
    //DATA_BIT CAN_BIT;
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
            case 0x18F201F3:
                BMS_SOC = msg.data[0];
                BMS_V = ((unsigned char) msg.data[1]
                        +((unsigned int) msg.data[2] << 8));
                BMS_A = ((unsigned char) msg.data[3]
                        +((unsigned int) msg.data[4] << 8));
                BMS_Number = ((unsigned char) msg.data[5]
                        +((unsigned int) msg.data[6] << 8));
                BMS_Life = msg.data[7];
                break;
                
            case 0x18F202F3:
                BMS_Current_Charge_Limit_Long = msg.data[0];
                BMS_Current_Charge_Limit_Short = msg.data[1];
                BMS_Current_Disharge_Limit_Long = msg.data[2];
                BMS_Current_Disharge_Limit_Short = msg.data[3];
                BMS_Cut = msg.data[7]&0x03;
                break;
                
            case 0x18F205F3:
                for (i = 0; i < 4; i++) {
                    BMS_Warn[i].byte = msg.data[i];
                }
                for (i = 5; i < 8; i++) {
                    BMS_Fault[i - 5].byte = msg.data[i];
                }
                BMS_Self_Check = (msg.data[6] >> 6)&0x03;
                break;
                
            case 0x18F206F3://BMS1_S_1
                //Bcan_count = 0;
                BAT_Max_Cell_Voltage[0] = ((unsigned char) msg.data[0]
                        +((unsigned int) msg.data[1] << 8));
                BAT_Max_Cell_Voltage_Cell_Case[0] = (unsigned char) msg.data[2];
                BAT_Max_Cell_Voltage_Cell_Number[0] = (unsigned char) msg.data[3];

                BAT_Max_Cell_Voltage[1] = ((unsigned char) msg.data[4]
                        +((unsigned int) msg.data[5] << 8));
                BAT_Max_Cell_Voltage_Cell_Case[1] = (unsigned char) msg.data[6];
                BAT_Max_Cell_Voltage_Cell_Number[1] = (unsigned char) msg.data[7];
                break;

            case 0x18F207F3://BMS1_S_2
                //Bcan_count = 0;
                BAT_Max_Cell_Voltage[2] = ((unsigned char) msg.data[0]
                        +((unsigned int) msg.data[1] << 8));
                BAT_Max_Cell_Voltage_Cell_Case[2] = (unsigned char) msg.data[2];
                BAT_Max_Cell_Voltage_Cell_Number[2] = (unsigned char) msg.data[3];

                BAT_Max_Cell_Voltage[3] = ((unsigned char) msg.data[4]
                        +((unsigned int) msg.data[5] << 8));
                BAT_Max_Cell_Voltage_Cell_Case[3] = (unsigned char) msg.data[6];
                BAT_Max_Cell_Voltage_Cell_Number[3] = (unsigned char) msg.data[7];
                break;

            case 0x18F208F3://BMS1_S_3
                //Bcan_count = 0;
                BAT_Min_Cell_Voltage[0] = ((unsigned char) msg.data[0]
                        +((unsigned int) msg.data[1] << 8));
                BAT_Min_Cell_Voltage_Cell_Case[0] = (unsigned char) msg.data[2];
                BAT_Min_Cell_Voltage_Cell_Number[0] = (unsigned char) msg.data[3];

                BAT_Min_Cell_Voltage[1] = ((unsigned char) msg.data[4]
                        +((unsigned int) msg.data[5] << 8));
                BAT_Min_Cell_Voltage_Cell_Case[1] = (unsigned char) msg.data[6];
                BAT_Min_Cell_Voltage_Cell_Number[1] = (unsigned char) msg.data[7];
                break;

            case 0x18F209F3://BMS1_S_4
                //Bcan_count = 0;
                BAT_Min_Cell_Voltage[2] = ((unsigned char) msg.data[0]
                        +((unsigned int) msg.data[1] << 8));
                BAT_Min_Cell_Voltage_Cell_Case[2] = (unsigned char) msg.data[2];
                BAT_Min_Cell_Voltage_Cell_Number[2] = (unsigned char) msg.data[3];

                BAT_Min_Cell_Voltage[3] = ((unsigned char) msg.data[4]
                        +((unsigned int) msg.data[5] << 8));
                BAT_Min_Cell_Voltage_Cell_Case[3] = (unsigned char) msg.data[6];
                BAT_Min_Cell_Voltage_Cell_Number[3] = (unsigned char) msg.data[7];
                break;

            case 0x18F20AF3://BMS1_T_1
                //Bcan_count = 0;
                BAT_Max_Cell_Temperature[0] = (unsigned char) msg.data[0];
                BAT_Max_Cell_Temp_Cell_Case[0] = (unsigned char) msg.data[1];
                BAT_Max_Cell_Temperature[1] = (unsigned char) msg.data[2];
                BAT_Max_Cell_Temp_Cell_Case[1] = (unsigned char) msg.data[3];
                BAT_Max_Cell_Temperature[2] = (unsigned char) msg.data[4];
                BAT_Max_Cell_Temp_Cell_Case[2] = (unsigned char) msg.data[5];
                BAT_Max_Cell_Temperature[3] = (unsigned char) msg.data[6];
                BAT_Max_Cell_Temp_Cell_Case[3] = (unsigned char) msg.data[7];
                break;

            case 0x18F20BF3://BMS1_T_2
                //Bcan_count = 0;
                BAT_Min_Cell_Temperature[0] = (unsigned char) msg.data[0];
                BAT_Min_Cell_Temp_Cell_Case[0] = (unsigned char) msg.data[1];
                BAT_Min_Cell_Temperature[1] = (unsigned char) msg.data[2];
                BAT_Min_Cell_Temp_Cell_Case[1] = (unsigned char) msg.data[3];
                BAT_Min_Cell_Temperature[2] = (unsigned char) msg.data[4];
                BAT_Min_Cell_Temp_Cell_Case[2] = (unsigned char) msg.data[5];
                BAT_Min_Cell_Temperature[3] = (unsigned char) msg.data[6];
                BAT_Min_Cell_Temp_Cell_Case[3] = (unsigned char) msg.data[7];
                break;

            case 0x18F210F3://BMS1_P_1
                //Bcan_count = 0;
                BAT_Pole_Temperature_P[0] = (unsigned char) msg.data[0];
                BAT_Pole_Temperature_N[0] = (unsigned char) msg.data[1];
                BAT_Pole_Temperature_P[1] = (unsigned char) msg.data[2];
                BAT_Pole_Temperature_N[1] = (unsigned char) msg.data[3];
                BAT_Pole_Temperature_P[2] = (unsigned char) msg.data[4];
                BAT_Pole_Temperature_N[2] = (unsigned char) msg.data[5];
                BAT_Pole_Temperature_P[3] = (unsigned char) msg.data[6];
                BAT_Pole_Temperature_N[3] = (unsigned char) msg.data[7];
                break;

            case 0x18F211F3://BMS1_P_2
                //Bcan_count = 0;
                BAT_Pole_Temperature_P[4] = (unsigned char) msg.data[0];
                BAT_Pole_Temperature_N[4] = (unsigned char) msg.data[1];
                BAT_Pole_Temperature_P[5] = (unsigned char) msg.data[2];
                BAT_Pole_Temperature_N[5] = (unsigned char) msg.data[3];
                BAT_Pole_Temperature_P[6] = (unsigned char) msg.data[4];
                BAT_Pole_Temperature_N[6] = (unsigned char) msg.data[5];
                BAT_Pole_Temperature_P[7] = (unsigned char) msg.data[6];
                BAT_Pole_Temperature_N[7] = (unsigned char) msg.data[7];
                break;

            case 0x18F212F3://BMS1_P_3
                //Bcan_count = 0;
                BAT_Pole_Temperature_P[8] = (unsigned char) msg.data[0];
                BAT_Pole_Temperature_N[8] = (unsigned char) msg.data[1];
                BAT_Pole_Temperature_P[9] = (unsigned char) msg.data[2];
                BAT_Pole_Temperature_N[9] = (unsigned char) msg.data[3];
                BAT_Pole_Temperature_P[10] = (unsigned char) msg.data[4];
                BAT_Pole_Temperature_N[10] = (unsigned char) msg.data[5];
                BAT_Pole_Temperature_P[11] = (unsigned char) msg.data[6];
                BAT_Pole_Temperature_N[11] = (unsigned char) msg.data[7];
                break;

            case 0x18F213F3://BMS1_P_4
                //Bcan_count = 0;
                BAT_Pole_Temperature_P[12] = (unsigned char) msg.data[0];
                BAT_Pole_Temperature_N[12] = (unsigned char) msg.data[1];
                BAT_Pole_Temperature_P[13] = (unsigned char) msg.data[2];
                BAT_Pole_Temperature_N[13] = (unsigned char) msg.data[3];
                BAT_Pole_Temperature_P[14] = (unsigned char) msg.data[4];
                BAT_Pole_Temperature_N[14] = (unsigned char) msg.data[5];
                BAT_Pole_Temperature_P[15] = (unsigned char) msg.data[6];
                BAT_Pole_Temperature_N[15] = (unsigned char) msg.data[7];
                break; 
                
            case 0x185017F3:
                //Bcan_count = 0;
                for(i = 0;i < 4;i++){
                    BMU_Comm_Status[i].byte = 0xFF;
                }
                BMS_Unit_Number = msg.data[4];
                for (i = 0; i < (BMS_Unit_Number / 8) + 1; i++) {
                    BMU_Comm_Status[i].byte = msg.data[i];
                }
                for (i = 0; i < (BMS_Unit_Number % 8); i++) {
                    temp = (temp << 1) + 1;
                }
                BMU_Comm_Status[BMS_Unit_Number / 8].byte = BMU_Comm_Status[BMS_Unit_Number / 8].byte | ~temp;                   
                break;
                
            case 0x18F20CF3:
                //Bcan_count = 0;
                BAT_Productor = msg.data[0];
                BAT_Ahr = msg.data[1];
                BAT_Voltage = msg.data[2];
                BAT_Charge_Times = ((unsigned char) msg.data[3]
                        +((unsigned int) msg.data[4] << 8));
                BAT_Material = (msg.data[5] >> 4)&0x0F;
                BAT_Time_Month = msg.data[5]&0x0F;
                BAT_Time_Year = msg.data[6];
                BAT_Verison = msg.data[7];
                break;
                
            case 0x18FF2B49:
                Bcan_count = 0;
                Oum_Status = msg.data[0]&0x0F;
                Oum_Warn = (msg.data[0]>>4)&0x03;
                Oum = ((unsigned char) msg.data[2]
                        +((unsigned int) msg.data[1] << 8));
                Oum_Voltage = ((unsigned char) msg.data[4]
                        +((unsigned int) msg.data[3] << 8));
                Oum_Life = msg.data[7];
                break;
                
            case 0x18F101D0:
                //Bcan_count = 0;
                VCU_Status.byte = msg.data[0];
                VCU_SPEED = ((unsigned char) msg.data[1]
                        +((unsigned int) msg.data[2] << 8));
                VCU_Gear = (unsigned char) msg.data[3]&0x07;
                VCU_Clutch = (msg.data[3] >> 3)&0x01;
                VCU_Fault.byte = msg.data[4];
                VCU_Code = msg.data[5];
                VCU_CarMode = msg.data[6];
                VCU_Life = msg.data[7];
                break;
                
            case 0x18F103D0:
                //Bcan_count = 0;
                VCU_Verison = msg.data[0];
                VCU_KM = ((unsigned char) msg.data[1]
                        +((unsigned int) msg.data[2] << 8));
                VCU_TM_Speed_percent = (unsigned char) msg.data[3];
                VCU_TM_Brake_percent = (unsigned char) msg.data[4];
                VCU_Kwh_100Km = msg.data[5];
                break;
                
            case 0x18F105D0:
                for (i = 0; i < 4; i++) {
                    VCU_Enable[i].byte = msg.data[i];
                }
                break;
                
            case 0x18F106D0:
                //Bcan_count = 0;
                VCU_KT_Control.byte = msg.data[0];
                VCU_KT_Status.byte = msg.data[1];
                BMS_KT_Status.byte = msg.data[2];
                break;
                
            case 0x18F501F0:
                MCU_Temp = msg.data[0]; //电机温度
                MCU_Control_Temp = msg.data[1]; //电机控制器温度
                MCU_Voltage = ((unsigned char) msg.data[2]
                        +((unsigned int) msg.data[3] << 8)); //电机母线电压
                MCU_SelfStatus = msg.data[5]&0x03; //电机自检状态
                MCU_Status = (msg.data[5] >> 2)&0x0F; //电机状态
                MCU_Fault.byte = msg.data[6];
                MCU_Code = msg.data[7];
                break;
                
            case 0x18F502F0:
                MCU_RPM = ((unsigned char) msg.data[0]
                        +((unsigned int) msg.data[1] << 8));//电机转速
                MCU_NM = ((unsigned char) msg.data[2]
                        +((unsigned int) msg.data[3] << 8));//电机扭矩
                MCU_POWER = ((unsigned char) msg.data[4]
                        +((unsigned int) msg.data[5] << 8));//电机功率
                MCU_Current = ((unsigned char) msg.data[6]
                        +((unsigned int) msg.data[7] << 8));//电机电流
                break;
                
            case 0x18F503F0:
                MCU_Output_Voltage = ((unsigned char) msg.data[0]
                        +((unsigned int) msg.data[1] << 8));
                MCU_Phase_Current = ((unsigned char) msg.data[2]
                        +((unsigned int) msg.data[3] << 8));
                break;
                
            case 0x0CF601A0:
                OILDCAC_Voltage = ((unsigned char) msg.data[0]
                        +((unsigned int) msg.data[1] << 8));
                OILDCAC_Current = msg.data[2];
                OILDCAC_Temp = msg.data[3];
                OILDCAC_Status.byte = msg.data[4];
                OILDCAC_Life = msg.data[7];
                break;

            case 0x0CF602A1:
                DCDC_Status = msg.data[0]&0x03;
                DCDC_Output_Current = msg.data[1];
                DCDC_Output_Voltage = msg.data[2];
                DCDC_Temp = msg.data[3];
                DCDC_Fault_Warn.byte = msg.data[4];
                DCDC_Input_Voltage = ((unsigned char) msg.data[5]
                        +((unsigned int) msg.data[6] << 8));
                DCDC_Life = msg.data[7];
                break;

            case 0x0CF603A2:
                AIRDCAC_Voltage = ((unsigned char) msg.data[0]
                        +((unsigned int) msg.data[1] << 8));
                AIRDCAC_Current = msg.data[2];
                AIRDCAC_Status.byte = msg.data[4];
                AIRDCAC_Temp = msg.data[5];
                AIRDCAC_Life = msg.data[7];
                break;

            case 0x0CF604A3:
                AC_Status = msg.data[0]; //
                AC_Indoor_Temp = msg.data[1];
                AC_Gear = msg.data[2];
                AC_WindMode = msg.data[3];
                AC_Work_Status = msg.data[4];
                AC_Outdoor_Temp = msg.data[5];
                AC_Fault_Code = msg.data[6];
                AC_Life = msg.data[7];
                break;
                
            case 0x0CF605A4:
                //AC_Status = msg.data[0]; //
                AC_Set_Temp = msg.data[1];
                //AC_Gear = msg.data[2];
                //AC_WindMode = msg.data[3];
                //AC_Work_Status = msg.data[4];
                //AC_Outdoor_Temp = msg.data[5];
                //AC_Fault_Code = msg.data[6];
                //AC_Life = msg.data[7];
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

                case 0x0C04A1A7://仪表报文MET_C_2
                    Vcan_count=0;
                    Accelerator = (unsigned char) msg.data[4];
                    Engine_Speed = ((unsigned char) msg.data[5]+((unsigned int) msg.data[6] << 8))*0.125;
                    break;

                case 0x0C05A1A7://仪表报文MET_C_3
                    Vcan_count=0;
                    Fule_rate = (unsigned char) msg.data[0]+((unsigned int) msg.data[1] << 8);
                    water_temp = msg.data[2];
                    Engine_Fuhe = msg.data[3];
                    Niaosu = msg.data[4];
                    Accelerator_Shiji = msg.data[5]; //油门踏板实际
                    Engine_oil_press = msg.data[6]; //机油压力
                    ambient_air_temperature = msg.data[7]; //周围空气温度
                    break;

                case 0x0C06A1A7://仪表报文MET_C_4  
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

                case 0x0C07A1A7://仪表报文MET_C_5  
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

                case 0x0C08A1A7://仪表报文MET_C_6  
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
#endif
        }                  
    }   
    C2INTF = 0; /* the individual flag register cleared */
    C2RX0CONbits.RXFUL = 0;
    IFS2bits.C2IF = 0;
}
