#include "SYSTEM.h"
unsigned char delay_cnt;
DATA_BIT gKEY[5];
DATA_BIT gCTL[8]; //仪表输出控制信息

unsigned int single_miles = 0;
unsigned long total_miles = 0;


unsigned int Fcan_count = 0; //前部模块
unsigned int Rcan_count = 0; //顶部模块
unsigned int Mcan_count = 0; //中部模块
unsigned int Ncan_count = 0; //发动机ECU模块




DBCM_KEY fKEY; //前模块功率开关状态
DBCM_KEY mKEY; //中（顶）模块功率开关状态
DBCM_KEY rKEY; //后模块功率开关状态

unsigned int fFreq; //前模块频率
unsigned int mFreq; //中（顶）模块频率
unsigned int rFreq; //后模块频率

unsigned int fSpeed; //前模块折算车速
unsigned int mSpeed; //中（顶）模块折算车速
unsigned int rSpeed; //后模块折算车速

unsigned int fADR[2]; //前模块电阻值
unsigned int mADR[2]; //中（顶）模块电阻值
unsigned int rADR[2]; //后模块电阻值

DBCM_POUT fPOUT; //前模块功率输出状态
DBCM_POUT mPOUT; //中（顶）模块功率输出状态
DBCM_POUT rPOUT; //后模块功率输出状态

unsigned char fPF[15]; //前模块功率输出故障
unsigned char mPF[15]; //中（顶）模块功率故障
unsigned char rPF[15]; //后模块功率输出故障

unsigned int fSingle_miles;
unsigned int mSingle_miles;
unsigned int rSingle_miles;
//系统初始化函数

void System_Init(void) {
    ADPCFG = 0xffff; //关闭AD口  

    /*按键控制接口 */
    KEY_UP_DR = 1; //   
    KEY_SET_DR = 1; // 
    KEY_AV_DR = 1;

    PWR_CTRL_DR = 1; //供电电压端口初始化
    PWR_CTRL = 0;

    TIMER1_Init();
    delay_cnt = 10; //初始值
    LCD_Init(); //液晶屏初始化

    delay_cnt = 10;
    while (delay_cnt > 1) {
        ClrWdt();
        SW_Input(); //开关读取
    }
    alarm_led[0].byte = 0xff;
    alarm_led[1].byte = 0x00;
    alarm_led[2].byte = 0x00;
    alarm_led[3].byte = 0x00;
    LED_Out();
    gCTL[0].byte = 0x00;
    gCTL[1].byte = 0x00;
    gCTL[2].byte = 0x00;
    gCTL[3].byte = 0x00;
    gCTL[4].byte = 0x00;
    gCTL[5].byte = 0x00;
    gCTL[6].byte = 0x00;
    gCTL[7].byte = 0x00;
     CAN1_Init();
     CAN2_Init();
    while (1) {
        ClrWdt();
        if (wake_up1) {//如果危险报警唤醒
            F_PO9 = FLASH;
            F_PO10 = FLASH;
            M_PO7 = FLASH;
            M_PO8 = FLASH;
            BUZZ = !FLASH;
        } else {
            F_PO9 = 0;
            F_PO10 = 0;
            M_PO7 = 0;
            M_PO8 = 0;
        }
        LED4 = M_PO7; //左转向灯
        LED8 = M_PO8; //右转向灯

        if (F50ms) {
            F50ms = 0;
            LED_Out();
            SW_Input();
            BCAN_SendCtl();
        }

        if (M_ON) break; // 如果是ON唤醒则正常退出
        if (wake_up1 == 0) {
            F_PO9 = 0;
            F_PO10 = 0;
            M_PO7 = 0;
            M_PO8 = 0;
            BCAN_SendCtl();
            __delay_us(100);
            BCAN_SendCtl();
          __delay_us(100);
            BCAN_SendCtl();
           __delay_us(100);
            BCAN_SendCtl();
          __delay_us(100);
            PWR_CTRL_DR = 1; //关闭电源
            PWR_CTRL = 0; //关闭电源 
        }
    }

    delay_cnt = 200; //设置2s定时 
    SM_Init();
    SM_Reset();
    BL_Init(); //仪表小灯背光初始化

    EEROM_ReadSingleMiles();
    EEROM_ReadTotalMiles();
    EEROM_ReadHMPulse();
    EEROM_ReadBackLight();

    OC1RS = e_backlight; //更新背光值
    //ConfigINT1();
    //ConfigINT2();

    ADC_Init();
    LCD_Init();
    alarm_led[0].byte = 0xC0; //蜂鸣器开启
    alarm_led[1].byte = 0xff;
    alarm_led[2].byte = 0xff;
    alarm_led[3].byte = 0xff;
    LED_Out();

    while (delay_cnt > 1); //延时0.1s
    OC1RS = 0;
    PWR_CTRL_DR = 0; //电源控制接口
    PWR_CTRL = 1; //开启MCU电源控制

    alarm_led[0].byte = 0xff;
    alarm_led[1].byte = 0x00;
    alarm_led[2].byte = 0x00;
    alarm_led[3].byte = 0x00;
    LED_Out();
    SW_Input();
    LCD_BackLight(7);
    DS3231_ReadTime(&timer); //读取时间 
}

void SYSTME_Logic(void) {

}

void LED_Logic(void) {

    
    
  //背光 小灯开关闭合 
 if(IN2)          OC1RS=e_backlight;
 else             OC1RS=0; 
}

void BCAN_SendCtl(void) {

}

void __attribute__((__interrupt__, auto_psv)) _C1Interrupt(void) {
    CAN_MESSAGE message;
    if (C1INTFbits.ERRIF) { //接收错误
        C1INTFbits.ERRIF = 0; // 添加错误处理代码
        CAN1_Init();
        C1RX0CONbits.RXFUL = 0;
    }
    if (C1INTFbits.IVRIF) {
        C1INTFbits.IVRIF = 0; //数据无效
        C1RX0CONbits.RXFUL = 0;
    }
    if (C1INTFbits.WAKIF) {
        C1INTFbits.WAKIF = 0;
    }


    if (C1RX0CONbits.RXFUL) { //数据有效
        CAN1_ReceiveMessage(&message);

        switch (message.id) {
            case 0x681:
                Fcan_count = 0;
                fKEY.BYTES[0] = message.data[0];
                fKEY.BYTES[1] = message.data[1];
                fKEY.BYTES[2] = message.data[2];
                fFreq = message.data[3]+((unsigned int) message.data[4] << 8);
                fSpeed = message.data[5]+((unsigned int) message.data[6] << 8);
                break;
            case 0x682:
                Mcan_count = 0;
                mKEY.BYTES[0] = message.data[0];
                mKEY.BYTES[1] = message.data[1];
                mKEY.BYTES[2] = message.data[2];
                mFreq = message.data[3]+((unsigned int) message.data[4] << 8);
                mSpeed = message.data[5]+((unsigned int) message.data[6] << 8);
                break;
            case 0x683:
                Rcan_count = 0;
                rKEY.BYTES[0] = message.data[0];
                rKEY.BYTES[1] = message.data[1];
                rKEY.BYTES[2] = message.data[2];
                rFreq = message.data[3]+((unsigned int) message.data[4] << 8);
                rSpeed = message.data[5]+((unsigned int) message.data[6] << 8);
                break;
            case 0x671:
                Fcan_count = 0;
                fADR[0] = message.data[0]+((unsigned int) message.data[1] << 8);
                fADR[1] = message.data[2]+((unsigned int) message.data[3] << 8);
                break;
            case 0x672:
                Mcan_count = 0;
                mADR[0] = message.data[0]+((unsigned int) message.data[1] << 8);
                mADR[1] = message.data[2]+((unsigned int) message.data[3] << 8);
                break;
            case 0x673:
                Rcan_count = 0;
                rADR[0] = message.data[0]+((unsigned int) message.data[1] << 8);
                rADR[1] = message.data[2]+((unsigned int) message.data[3] << 8);
                break;
            case 0x561:
                Fcan_count = 0;
                fPOUT.BYTES[0] = message.data[0];
                fPOUT.BYTES[1] = message.data[1];

                break;
            case 0x562:
                Mcan_count = 0;
                mPOUT.BYTES[0] = message.data[0];
                mPOUT.BYTES[1] = message.data[1];

                break;

            case 0x563:
                Rcan_count = 0;
                rPOUT.BYTES[0] = message.data[0];
                rPOUT.BYTES[1] = message.data[1];

                break;
            case 0x451:
                Fcan_count = 0;
                fSingle_miles = message.data[4]+((unsigned int) message.data[5] << 8);
                break;
            case 0x452:
                Mcan_count = 0;
                mSingle_miles = message.data[4]+((unsigned int) message.data[5] << 8);
                break;
            case 0x453:
                Rcan_count = 0;
                rSingle_miles = message.data[4]+((unsigned int) message.data[5] << 8);
                break;

            default:
                if (message.id == e_address) {
                    if (message.data[0] == 0xC1) {
                        __asm__ volatile ("reset");
                    }
                }
                if (message.id == 0x610) {
                    if (message.data[0] == 0x55) {
                    } else if (message.data[0] == 0x56) {
                        if (message.data[1] == e_address) {
                            e_hm_pulse = message.data[2]+((unsigned int) message.data[3] << 8);
                            EEROM_WriteTotalMiles();
                        }
                    } else if (message.data[0] == 0x59) {
                        if (message.data[1] == e_address) {
                            e_total_miles = (unsigned char) message.data[2]
                                    +((unsigned int) message.data[3] << 8)
                                    +((unsigned long) message.data[4] << 16)
                                    +((unsigned long) message.data[5] << 24);
                            EEROM_WriteTotalMiles();
                        }
                    } else if (message.data[0] == 0x5A) {
                        if (message.data[1] == e_address) {
                            e_single_miles = (unsigned char) message.data[2]
                                    +((unsigned int) message.data[3] << 8);
                            EEROM_WriteSingleMiles();
                        }
                    }
                }
                break;
        }
    }
    C1INTF = 0; /* the individual flag register cleared */
    C1RX0CONbits.RXFUL = 0;
    _C1IF = 0;
}


unsigned char engine_oil_press = 0;
unsigned char barometric_pressure = 0; //增压压力 0.5Kpa
unsigned char ambient_air_temperature = 0; //周围空气温度
unsigned char air_pressure = 0; //进气压力 0.5Kpa
unsigned int EngineSpeed = 0;
unsigned char WaterTem = 0;
unsigned int fuel_rate = 0; //小时燃油消耗率
unsigned int instantaneous_fuel = 0; //瞬态燃油经济性
unsigned int battery_voltage = 520;
unsigned char speed_st = 0; //油门踏板状态
unsigned char ECU_DM1 = 0; //ECU DM1 报警

void __attribute__((__interrupt__, auto_psv)) _C2Interrupt(void) {
    CAN_MESSAGE msg;
    if (C1INTFbits.ERRIF) { //接收错误
        C1INTFbits.ERRIF = 0; // 添加错误处理代码
        CAN1_Init();
        C1RX0CONbits.RXFUL = 0;
    }
    if (C1INTFbits.IVRIF) {
        C1INTFbits.IVRIF = 0; //数据无效
        C1RX0CONbits.RXFUL = 0;
    }
    if (C1RX0CONbits.RXFUL) { //数据有效
        Ncan_count = 0;
        CAN2_ReceiveMessage(&msg);
        switch (msg.id) {
            case 0x18FEEF00://发动机液体层/压力
                Ncan_count = 0; 
                engine_oil_press = msg.data[3];
                break;

            case 0xcf00400:
                Ncan_count = 0; 
                EngineSpeed = msg.data[3]+((unsigned int) (msg.data[4]) << 8);
                if (EngineSpeed >= 28000) EngineSpeed = 28000; //最大是3500RPM
                sm_new_value[4] = (unsigned int) (0.097 * EngineSpeed); //更新转速表
                break;
            case 0x18FEEE00:
                Ncan_count = 0; 
                WaterTem = msg.data[0];
                break;
            case 0x0CF00300:
                Ncan_count = 0; 
                speed_st = msg.data[1]; //踏板开度
                break;
            case 0x18FECA00: //DM1
                Ncan_count = 0; 
                ECU_DM1 = msg.data[0];
                break;
            case 0x18FEF200://燃料消费
                Ncan_count = 0; 
                fuel_rate = msg.data[0]+((unsigned int) (msg.data[1]) << 8); //0.05L/h
                instantaneous_fuel = msg.data[2]+((unsigned int) (msg.data[3]) << 8); // 1/512 km/L
                break;
            case 0x18FEF600: //周围环境条件 id==0x18FEF600
                Ncan_count = 0; 
                barometric_pressure = msg.data[1]; //增压压力 0.5Kpa
                ambient_air_temperature = msg.data[2]; //周围空气温度
                air_pressure = msg.data[3]; //进气压力 0.5Kpa
                break;
            case 0x18FEF700://电压
                Ncan_count = 0; 
                battery_voltage = msg.data[6]+((unsigned int) (msg.data[7]) << 8);
                break;
        }
    }
    C2INTF = 0; /* the individual flag register cleared */
    C2RX0CONbits.RXFUL = 0;
    IFS2bits.C2IF = 0;
}

void __attribute__((__interrupt__, auto_psv)) _T1Interrupt(void) {//10ms中断一次
    static unsigned int cnt0 = 0;
    static unsigned int cnt1 = 3;
    static unsigned int cnt2 = 7;
    static unsigned int cnt3 = 9;
    static unsigned int cnt4 = 0;
    static unsigned int lpcnt2 = 0, lpcnt1 = 0, lpcount = 0;
    static unsigned int Fcount = 0, Kcount = 0;


    if (delay_cnt > 0) delay_cnt--; //延时计数器 

    if (cnt0 >= 5) {//50ms
        cnt0 = 0;
        SYSTME_Logic();
        BCAN_SendCtl();
        F50ms = 1;
        
    } else cnt0++;

    if (cnt1 >= 10) {//100ms
        cnt1 = 0;
        LED_Logic();
        LED_Out();
        F100ms = 1;
        if (Fcan_count >= CAN_TIME)Fcan_count = CAN_TIME;
        else Fcan_count++;
        if (Rcan_count >= CAN_TIME)Rcan_count = CAN_TIME;
        else Rcan_count++;
        if (Mcan_count >= CAN_TIME)Mcan_count = CAN_TIME;
        else Mcan_count++;
        if (Ncan_count >= CAN_TIME)Ncan_count = CAN_TIME;
        else Ncan_count++;

        if (cnt4 > 10) {//1s
            cnt4 = 0;
            FLASH_1s = !FLASH_1s;
        } else cnt4++;
    } else cnt1++;

    if (Fcount >= 40) {//0.4s
        Fcount = 0;
        FLASH = !FLASH;
    } else Fcount++;

    if (Kcount >= 30) {//300ms
        Kcount = 0;
        kFLASH = !kFLASH;
    } else Kcount++;

    if (cnt2 >= 50) {//500ms 
        cnt2 = 0;
        F500ms = 1;
        F500ms_LCD = !F500ms_LCD;
    } else cnt2++;

    if (wake_up3) { //ON开关判断
        if (cnt3 > 30) M_ON = 1;
        else cnt3++;
    } else {
        if (cnt3 < 1) M_ON = 0;
        else cnt3--;
    }


    //bit  key_set;  
    if (!KEY_SET && pkey_set && !bkey_set) {
        key_set = 1;
        bkey_set = pkey_set;
    } else {
        if (!KEY_SET == pkey_set) bkey_set = pkey_set;
    }
    pkey_set = KEY_SET;

    //bit  key_up;
    if (!KEY_UP && pkey_up && !bkey_up) {
        key_up = 1;         //向上按键
        bkey_up = pkey_up;
    } else {
        if (!KEY_UP == pkey_up) bkey_up = pkey_up;
    }
    pkey_up = KEY_UP;

    //bit key_AV;
    if (!KEY_AV && pkey_AV && !bkey_AV) {
        key_AV = 1;
        bkey_AV = pkey_AV;
    } else {
        if (!KEY_AV == pkey_AV)bkey_AV = pkey_AV;
    }
    pkey_AV = KEY_AV;


    if (KEY_SET) {
        if (lpcnt2 >= 300) {
            lpcnt2 = 0;
            bkey_set = 1; //长按时取消单按键操作
            key_long_set = 1;
        } else lpcnt2++;
    } else {
        lpcnt2 = 0;
    }
    
    if (KEY_AV && KEY_UP) {
        if (lpcnt1 >= 300) {
            lpcnt1 = 0;
            bkey_AV = 1; //长按时取消单按键操作
            bkey_up = 1; //长按时取消单按键操作
            key_duble = 1; //隐含功能按键
        } else lpcnt1++;
    } else {
        lpcnt1 = 0;
    }
    
    if (KEY_AV &&  (KEY_UP == 0)) { //长按 2S 清零单里程
        if (lpcount >= 200) {
            single_miles = 0;
            save_flag = 1;
            bkey_AV = 1; //长按时取消单按键操作
            lpcount = 100;
        } else lpcount++;
    } else if (lpcount > 0) lpcount--;

    _T1IF = 0;
}



