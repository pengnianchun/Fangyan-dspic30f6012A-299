#include "APP_System.h"

unsigned char delay_cnt;

DATA_BIT gKEY[5];

unsigned int single_miles = 0;
unsigned long total_miles = 0;

unsigned int SPEED; //外部CAN换算车速
unsigned int RPM; //外部CAN换算转速

unsigned char PRESS[2]; //气压值

unsigned char dm_hcu_display[32]; //故障类型
unsigned char dm_tcu_display[32];

//系统初始化函数

void System_Init(void) {
    ADPCFG = 0xffff; //关闭AD口     
    LED_Clear(); //消除开机瞬间LED和蜂鸣器闪烁
    LED_Out();
    /*按键控制接口 */
    KEY_UP_DR = 1; //   
    KEY_SET_DR = 1; // 
    KEY_AV_DR = 1;

    PWR_CTRL_DR = 1; //供电电压端口初始化
    PWR_CTRL = 0;

    LCD_Init();
    TIMER1_Init();
    delay_cnt = 10; //延时0.1s
    while (delay_cnt > 1) {
        ClrWdt();
        SW_Input(); //开关读取
    }
    LED_Clear();
    LED_Out();
    POUT_Clear();
    CAN1_Init();
    CAN2_Init();
    while (1) {
        ClrWdt();
        LCD_BackLight(0x00);

        if (F50ms) {
            F50ms = 0;
            SW_Input();
        }

        if (WAKE_Danger) {//如果危险报警唤醒
            PWR_CTRL_DR = 0;
            PWR_CTRL = 1;
            LED_Danger();
        } else {
            POUT_Clear();
            LED_Clear();
        }

        LED_Out();

        if (WAKE_ON || WAKE_ACC || WAKE_Charge || WAKE_Start) break; // 如果是ON唤醒则正常退出

        if (!WAKE_Danger) {
            BCAN_SendCtl(); //中断里的BCAN发送50ms发送一次，可能来不及发最后的状态，程序已经结束
            __delay_us(500);
            BCAN_SendCtl();
            __delay_us(500);
            BCAN_SendCtl();
            __delay_us(500);
            BCAN_SendCtl();
            __delay_us(500);
            PWR_CTRL_DR = 1; //关闭电源
            PWR_CTRL = 0; //关闭电源 
            PWR_CTRL_DR = 1; //关闭电源
            PWR_CTRL = 0; //关闭电源 
            PWR_CTRL_DR = 1; //关闭电源
            PWR_CTRL = 0; //关闭电源 
        }
    }

    delay_cnt = 100; //设置1s定时 
    SM_Init();
    SM_Reset();
    BL_Init(); //仪表小灯背光初始化
    INT1_Init();
    INT2_Init();
    TIMER3_Init();
    TIM5_Init(); //频率输出初始化
    EEROM_ReadSingleMiles();
    EEROM_ReadTotalMiles();
    EEROM_ReadHMPulse();
    EEROM_ReadBackLight();
    single_miles = e_single_miles;
    total_miles = e_total_miles;
    OC1RS = e_backlight; //更新背光值
    ADC_Init();
    LCD_Init();
    LED_Enable(); //蜂鸣器开启
    LED_Out();
    while (delay_cnt > 1); //延时1s
    OC1RS = 0;
    PWR_CTRL_DR = 0; //电源控制接口
    PWR_CTRL = 1; //开启MCU电源控制
    LED_Clear();
    LED_Out();
    SW_Input();
    LCD_BackLight(7);
    DS3231_ReadTime(&timer); //读取时间 
    Count_ADR(); //AD采集
    CAN_DATA_Init(); //CAN数据初始化
}

//电机转动逻辑

void SM_Logic(void) {
    static unsigned char task = 0;
    static unsigned int temp = 0;

    if (CAN_0x0C03A1A7.MotoSpeed > 20000)
        RPM = CAN_0x0C03A1A7.MotoSpeed - 20000;
    else 
        RPM = 20000 - CAN_0x0C03A1A7.MotoSpeed;
    //RPM = 0 * 0.125;

    SPEED = (unsigned int) (RPM * 0.452 * 2 * 6 * 3.14159 / 100 / 6.17  * e_hm_pulse / 100); //单位1Km/h
    //SPEED = VCU_SPEED / 2 * 1.03;
    //if (SPEED >= 70) Speed_lim_mode = 0x01; //限速模式
    //else Speed_lim_mode = 0x03;
    sm_new_value[0] = SPEED * 132 / 7;
    SM_Update_0(); //车速表
    
    sm_new_value[5] = (unsigned int) (RPM * 0.66 / 2);
    SM_Update_5(); //转速表 

#if MODE_EV
    if (task == 0) {
        task = 1;
        temp = rADR[0];
        if (temp < 10)
            sm_new_value[4] = 0;
        else if (temp < 79)
            sm_new_value[4] = ((temp - 10)*5)*10/12;
        else if (temp < 116)
            sm_new_value[4] = (345 + (temp - 79)*9.3)*10/12;
        else if (temp < 149)
            sm_new_value[4] = (690 + (temp - 116)*7)*10/12;
        else if (temp < 184)
            sm_new_value[4] = (921 + (temp - 149)*6.6)*10/12;
        else
            sm_new_value[4] = 1152*10/12;
        SM_Update_4(); //气压1
    } else if (task == 1) {
        task = 2;
        temp = CAN_0x1818D0F3.BMS_SOC * 0.4;
        if (temp <= 0) {
            sm_new_value[3] = 0;
        } else if (temp > 100) {
            sm_new_value[3] = 1152;
        } else {
            sm_new_value[3] = (unsigned int) (11.52 * temp);
        }
        SM_Update_3(); //SOC
    } else if (task == 2) {
        task = 3;
        temp = rADR[1];
        if (temp < 10)
            sm_new_value[2] = 0;
        else if (temp < 79)
            sm_new_value[2] = ((temp - 10)*5)*10/12;
        else if (temp < 116)
            sm_new_value[2] = (345 + (temp - 79)*9.3)*10/12;
        else if (temp < 149)
            sm_new_value[2] = (690 + (temp - 116)*7)*10/12;
        else if (temp < 184)
            sm_new_value[2] = (921 + (temp - 149)*6.6)*10/12;
        else
            sm_new_value[2] = 1152*10/12;
        /*temp = ADV[4];//电压型传感器
        if (temp < 500)
            sm_new_value[2] = 0;
        else if (temp > 3000)
            sm_new_value[2] = 1152;
        else sm_new_value[2] = (unsigned int) ((temp - 500) * 0.4608);*/
        SM_Update_2(); //气压2
    } else if (task == 3) {
        task = 0;
        temp = ADV[0];
        if (temp < 160) {
            sm_new_value[1] = 0;
        } else if ((temp >= 160)&&(temp < 320)) {
            sm_new_value[1] = (unsigned int) (7.2 * (temp - 160));
        } else {
            sm_new_value[1] = 1152;
        }
        SM_Update_1(); //蓄电池电压
    } else {
        task = 0;
    }
#elif MODE_FV
    if (task == 0) {
        task = 1;
        temp = 0;
        if (temp > 160)
            sm_new_value[4] = 1152;
        else if (temp < 80)
            sm_new_value[4] = 0;
        else sm_new_value[4] = (unsigned int) ((temp - 80)*14.4);
        SM_Update_4(); //水温表
    } else if (task == 1) {
        task = 2;
        temp = ADR[5];
        if (temp < 10) {
            sm_new_value[3] = 0;
        } else if (temp > 180) {
            sm_new_value[3] = 1152;
        } else if (temp <= 90) {
            sm_new_value[3] = (unsigned int) (7.4 * (temp - 10));
        } else {
            sm_new_value[3] = (unsigned int) (6.5 * temp);
        }
        SM_Update_3(); //油量表
    } else if (task == 2) {
        task = 3;
        temp = 0;
        if (temp >= 1000) {
            sm_new_value[2] = 1152;
        }
        sm_new_value[2] = (unsigned int) (temp * 1.152);
        SM_Update_2(); //机油压力表
    } else if (task == 3) {
        task = 0;
        temp = ADV[0];
        if (temp < 180) {
            sm_new_value[1] = 0;
        } else if ((temp >= 180)&&(temp < 240)) {
            sm_new_value[1] = (unsigned int) (6.667 * (temp - 180));
        } else if ((temp >= 240)&&(temp <= 320)) {
            sm_new_value[1] = (unsigned int) (10 * (temp - 240)) + 400;
        } else {
            sm_new_value[1] = 1200;
        }
        SM_Update_1(); //蓄电池电压
    } else {
        task = 0;
    }
#endif    
}

//电机全部归位状态 函数为0时表示电机全部归位

int SM_Zero_State(void) {
    unsigned char task = 6;

    if (sm_old_value[0] == 0) task--;
    if (sm_old_value[1] == 0) task--;
    if (sm_old_value[2] == 0) task--;
    if (sm_old_value[3] == 0) task--;
    if (sm_old_value[4] == 0) task--;
    if (sm_old_value[5] == 0) task--;

    return task;
}
#if 1
_FLASH Flash[] = {
    {0, 0, 40, CYCLE, 40, 3},         //400ms闪烁输出3次
    {0, 0, 50, CYCLE, 50, 0},         //500ms闪烁输出
    {0, 0, 100, CYCLE, 100, 0},       //1s闪烁输出
    //{0, 0, 100, CYCLE, 100, 3},       //1s闪烁输出3次
    {}    
};
//注册闪烁输出有效条件,最好放在中断里
void Interval_Status(unsigned int condition, Flash_Number x) {
    if (x < Flash_Null) {
        if (condition) {
            Flash[x].Condition = 1;
        } else {
            Flash[x].Condition = 0;
        }
    }
}
#endif
//定时启动条件

#if 0 
int Interval_Run(unsigned char condition,  //启动条件
        unsigned int out_time,              //条件满足，工作时间 T = out_time * 处理间隔时间
        CYCLE_EN cycle_en,                  //是否循环执行
        unsigned int stop_time,             //循环执行时，间歇时间 T = stop_time * 处理间隔时间
        unsigned char cycle_times           //循环次数，0为无限循环
        ) {
    static unsigned int temp = 0;
    static unsigned char times = 0;
#if 0    
    if (condition) {//条件不满足，立即停止运行
        temp = temp > 60000 ? 60000 : temp + 1; //计数上限，防止溢出
    } else {
        temp = 0;
    }
    
    if (condition) {//条件不满足，单次循环结束停止运行
        temp = temp > 60000 ? 60000 : temp + 1; //计数上限，防止溢出
    } else if(temp > 0 && temp < (out_time + stop_time) * 100){
        temp = temp > 60000 ? 60000 : temp + 1
    } else {
        temp = 0;
    }
    
    if (condition && ((times < cycle_times) || (!cycle_times))) {//条件不满足，单次循环结束后停止运行，条件满足，运行指定的次数或一直循环运行
        temp = temp > 60000 ? 60000 : temp + 1; //计数上限，防止溢出
    } else if (temp > 0 && temp < (out_time + stop_time) * 100) {        
        temp = temp > 60000 ? 60000 : temp + 1;
    } else {
        temp = 0;
        if (!condition) {
            times = 0;
        }
    }
#endif    
    if (condition && ((times < cycle_times) || (!cycle_times))) {//条件不满足，指定循环次数结束后停止运行，条件满足，运行指定的次数或一直循环运行
        temp = temp > 60000 ? 60000 : temp + 1; //计数上限，防止溢出
    } else if (temp > 0 && temp < (out_time + stop_time)) {        
        temp = temp > 60000 ? 60000 : temp + 1;
    } else if ((times > 0) && (times < cycle_times)){//改变这里的 cycle_times 可以设置停止运行前循环次数
        temp = temp > 60000 ? 60000 : temp + 1;
    } else {
        temp = 0;
        if (!condition) {
            times = 0;
        }
    }

    if (temp > 0 && temp < out_time) {
        return 1;
    } else if (!cycle_en) {
        return 0;
    } else if (temp < (out_time + stop_time)) {
        return 0;
    } else {
        temp = 0;
        times++;
        return 0;
    }
}
#endif

_Delay_Out delay_out[] = {
    {500},
    {1000},
    {2000},
    {5000},
    {}
};
//延迟输出处理，对.delay_condition赋值，即可用.delay_out的状态
void Delay_Out(void) {
    unsigned char i;
    for (i = 0; delay_out[i].delay_time != 0; i++) {
        if (delay_out[i].condition) {
            delay_out[i].delay_out = 1;
            delay_out[i].Timer = delay_out[i].delay_time;
        } else if (delay_out[i].Timer > 0) {
            delay_out[i].delay_out = 1;
            delay_out[i].Timer--;
        } else
            delay_out[i].delay_out = 0;
    }
}

//上升沿有效，触发一次
int Trigger_up(unsigned int x){
    static unsigned int old = 0;
    unsigned int status = 0;
    if(x && !old)
        status  = 1;
    else 
        status = 0;
    
    old = x;
    
    return status;
}

//下降沿有效，触发一次
int Trigger_down(unsigned int x){
    static unsigned int old = 1;
    unsigned int status = 0;
    if(!x && old)
        status  = 1;
    else 
        status = 0;
    
    old = x;
    
    return status;
}