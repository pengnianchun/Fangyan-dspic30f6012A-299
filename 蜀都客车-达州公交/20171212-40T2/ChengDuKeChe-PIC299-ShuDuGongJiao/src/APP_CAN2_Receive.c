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
_CAN_0x18EF4AEF CAN_0x18EF4AEF;
_CAN_0x18EF4BEF CAN_0x18EF4BEF;
_CAN_0x0CF00203 CAN_0x0CF00203;
unsigned int Speed_rmp; //输出轴转速
unsigned char Current_Gear; //档位-125 to +125(1=D1(1档)2=D2 3=D3 4=D4 5=D5 6=D6 0=N（空挡）-1=R（倒档）)
_CAN_0x18EF4CEF CAN_0x18EF4CEF;
_CAN_0x18EF4DEF CAN_0x18EF4DEF;
_CAN_0x18EF0AEF CAN_0x18EF0AEF;
unsigned char Accelerator; //油门踏板

unsigned char Speed_lim_mode;//限速模式

unsigned char water_temp; //水温

unsigned int Engine_oil_press; //机油压力
unsigned char water_level; //水位

unsigned char Wait_start; //等待启动
unsigned char Maintain_warn; //维护报警
unsigned char Stop_warn; //停机报警
unsigned char Engine_warn; //发动机故障

unsigned int EngineSpeed; //发动机转速

unsigned char barometric_pressure = 0; //增压压力 0.5Kpa
unsigned char ambient_air_temperature = 0; //周围空气温度
unsigned char air_pressure = 0; //进气压力 0.5Kpa

unsigned int fuel_rate = 0; //小时燃油消耗率
unsigned int instantaneous_fuel = 0; //瞬态燃油经济性

unsigned int  speed_st=0; //油门踏板

_CAN_0x18FE521E CAN_0x18FE521E;

_CAN_0x1CFF5281 CAN_0x1CFF5281;

_CAN_0x1CFF5381 CAN_0x1CFF5381;
void DM(unsigned char x, DM1 id) {//解析出id的第x个故障码的spn和fmi
    SPN = id.bData[2 + 4 * (x - 1)]
            +((unsigned int) id.bData[3 + 4 * (x - 1)] << 8)
            +((unsigned long) (id.bData[4 + 4 * (x - 1)]&0xE0) << 11);
    FMI = (id.bData[4 + 4 * (x - 1)] & 0x1F);
}

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
            case 0x18EF4AEF://Hybrid_Information_Message
                Vcan_count = 0;
                for (i = 0; i < 8; i++) {
                    CAN_0x18EF4AEF.byte[i] = msg.data[i];
                }
                
                break;

            case 0x18EF4BEF://Hybrid_DTC_Message
                Vcan_count = 0;
                for (i = 0; i < 8; i++) {
                    CAN_0x18EF4BEF.byte[i] = msg.data[i];
                }
                
                break;

            case 0x18FECAEF:// DM1 HCU
                Vcan_count = 0;
                for (i = 0; i < 6; i++) {
                    CAN_18FECAEF.bData[i] = msg.data[i];
                }
                CAN_18FECAEF_len = 0x06; //m_can.len;
                
                for (i = 0; i < 36; i++) {//清除多包故障缓存
                    CAN_18FECAEF.bData[i + 6] = 0;
                }
                break;

            case 0x1CECFFEF://TPCM HCU
                Vcan_count = 0;
                if (msg.data[0] == 0x20) {
                    if (msg.data[5] == 0xCA && msg.data[6] == 0xFE) {
                        m_can.len = msg.data[1]+((unsigned int) msg.data[2] << 8);
                        m_can.pack = msg.data[3];
                        m_can.flag = 1; //CAN接收开始标记
                    }
                }

                break;

            case 0x1CEBFFEF://TPDT HCU
                Vcan_count = 0;
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
                        for (i = m_can.len; i < 42; i++) {
                            CAN_18FECAEF.bData[i] = 0;
                        }
                        CAN_18FECAEF_len = m_can.len;
                        m_can.flag = 0; //已完成接收
                    }
                }

                break;
                
            /*case 0x18FECA00:// DM1 
                Vcan_count = 0;
                for (i = 0; i < 6; i++) {
                    CAN_18FECA00.bData[i] = msg.data[i];
                }
                CAN_18FECA00_len = 0x06; //m_can.len;
                
                break;

            case 0x1CECFF00://
                Vcan_count = 0;
                if (msg.data[0] == 0x20) {
                    if (msg.data[5] == 0xCA && msg.data[6] == 0xFE) {
                        e_can.len = msg.data[1]+((unsigned int) msg.data[2] << 8);
                        e_can.pack = msg.data[3];
                        e_can.flag = 1; //CAN接收开始标记
                    }
                }

                break;

            case 0x1CEBFF00://
                Vcan_count = 0;
                if (e_can.flag == 1) {
                    if (msg.data[0] <= e_can.pack) {
                        unsigned int slen;
                        slen = (msg.data[0] - 1)*7;
                        for (i = 0; i < 7; i++) {
                            e_can.buf[slen+i] = msg.data[i + 1];
                        }
                    }
                    if (msg.data[0] == e_can.pack) {
                        for (i = 0; i < e_can.len; i++) {
                            CAN_18FECA00.bData[i] = e_can.buf[i];
                        }
                        CAN_18FECA00_len = e_can.len;
                        e_can.flag = 0; //已完成接收
                    }
                }

                break;*/
                //////////////////////////////////////////////////////////////////////////////////            
            case 0x0CF00203://ETC1 TCU
                Vcan_count = 0;
                for (i = 0; i < 8; i++) {
                    CAN_0x0CF00203.byte[i] = msg.data[i];
                }
                Speed_rmp = msg.data[1] + ((unsigned int) msg.data[2] << 8);
                break;


            case 0x18F00503://ETC2 TCU
                Vcan_count = 0;
                Current_Gear = msg.data[3];
                
                break;

            case 0x18FECA03:// DM1 TCU
                Vcan_count = 0;
                for (i = 0; i < 6; i++) {
                    CAN_18FECA03.bData[i] = msg.data[i];
                }
                CAN_18FECA03_len = 0x06; //n_can.len;
                
                for (i = 0; i < 36; i++) {//清除多包故障缓存
                    CAN_18FECA03.bData[i + 6] = 0;
                }
                break;

            case 0x1CECFF03://TPCM TCU
                Vcan_count = 0;
                if (msg.data[0] == 0x20) {
                    if (msg.data[5] == 0xCA && msg.data[6] == 0xFE) {
                        n_can.len = msg.data[1]+((unsigned int) msg.data[2] << 8);
                        n_can.pack = msg.data[3];
                        n_can.flag = 1; //CAN接收开始标记
                    }
                }
                
                break;

            case 0x1CEBFF03://TPDT TCU
                Vcan_count = 0;
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
                        for (i = n_can.len; i < 42; i++) {//清缓存
                            CAN_18FECA03.bData[i] = 0;
                        }
                        CAN_18FECA03_len = n_can.len;
                        n_can.flag = 0; //已完成接收
                    }
                }
                
                break;                                            
                ////////////////////////////////////////////////////////////////////////////////          
            case 0x18EF4CEF://BMS Cell voltage Information Message
                Vcan_count = 0;
                for (i = 0; i < 8; i++) {
                    CAN_0x18EF4CEF.byte[i] = msg.data[i];
                }
                //CAN_0x18EF4CEF.Max_Cell_Voltage = msg.data[0] + (((unsigned int)msg.data[1] & 0x0F) << 8);
                break;

            case 0x18EF4DEF://Hybrid Temperature Information Message
                Vcan_count = 0;
                for (i = 0; i < 8; i++) {
                    CAN_0x18EF4DEF.byte[i] = msg.data[i];
                }
                
                break;

            case 0x18EF0AEF:// Hybrid_ENG_Control
                Vcan_count = 0;
                for (i = 0; i < 8; i++) {
                    CAN_0x18EF0AEF.byte[i] = msg.data[i];
                }
                
                break;
                
            case 0x1CFF5281:// 
                Vcan_count = 0;
                for (i = 0; i < 8; i++) {
                    CAN_0x1CFF5281.byte[i] = msg.data[i];
                }

                break;
                
            case 0x1CFF5381:// 
                Vcan_count = 0;
                for (i = 0; i < 8; i++) {
                    CAN_0x1CFF5381.byte[i] = msg.data[i];
                }

                break;
                
            case 0x18FE521E:// 
                Vcan_count = 0;
                for (i = 0; i < 8; i++) {
                    CAN_0x18FE521E.byte[i] = msg.data[i];
                }

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
                barometric_pressure = msg.data[1]; //增压压力 0.5Kpa
                ambient_air_temperature = msg.data[2]; //周围空气温度
                air_pressure = msg.data[3]; //进气压力 0.5Kpa
                break;

            case 0x0CF00400:
                EngineSpeed = msg.data[3]+((unsigned int) (msg.data[4]) << 8);
                if (EngineSpeed >= 32000) EngineSpeed = 32000; //最大是4000RPM
                break;

            case 0x18FEF200://燃料消费 
                fuel_rate = msg.data[0]+((unsigned int) (msg.data[1]) << 8); //0.05L/h
                instantaneous_fuel = (((unsigned int) msg.data[3]) << 8) + msg.data[2]; // 1/512 km/L	 
                break;

            case 0x0CF00300:
                speed_st = msg.data[1];
                break;
        }
    }
    C2INTF = 0; /* the individual flag register cleared */
    C2RX0CONbits.RXFUL = 0;
    IFS2bits.C2IF = 0;
}
