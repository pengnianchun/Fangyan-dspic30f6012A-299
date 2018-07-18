#include "SYSTEM.h"
//#include "LOGO.h"
unsigned int delay_cnt;
unsigned int delay_5s;
DATA_BIT gKEY[5];
DATA_BIT gCTL[8]; //仪表输出控制信息

unsigned int single_miles = 0;
unsigned long total_miles = 0;
unsigned int X_pSpeed=0;

unsigned int Fcan_count = 0; //前部模块CAN
unsigned int Rcan_count = 0; //顶部模块CAN
unsigned int Mcan_count = 0; //中部模块CAN
unsigned int Ecan_count = 0; //发动机ECU模块CAN
unsigned int Vcan_count = 0; //整车控制器VCU模块CAN
unsigned int Bcan_count = 0; //电池管理器BMS模块CAN
unsigned int Dcan_count = 0; //转向助力DC/AC模块CAN
unsigned int Acan_count = 0; //空调AC模块CAN

unsigned int Hcan_count = 0; //灭火器
unsigned int Jcan_count = 0; //绝缘检测
unsigned int Ccan_count = 0; //DCDC
unsigned int Qcan_count = 0; //气泵
unsigned int Ycan_count = 0; //油泵
unsigned int ECU_TIME;
unsigned int QY_count   = 0; //气压延时处理

unsigned int BAT24V_count = 0; //蓄电池低压报警计时

unsigned int M_PO11_count = 1000; //输出10秒计时

DBCM_KEY fKEY; //前模块功率开关状态
DBCM_KEY mKEY; //中（顶）模块功率开关状态
DBCM_KEY rKEY; //后模块功率开关状态

SW_DATA  fkey[3];
SW_DATA  rkey[3];
SW_DATA  tkey[3];

unsigned int fMK_Version=0; //前模块版本号
unsigned int mMK_Version=0; //顶模块版本号
unsigned int rMK_Version=0; //后模块版本号

unsigned int fFreq; //前模块频率
unsigned int mFreq; //中（顶）模块频率
unsigned int rFreq; //后模块频率

unsigned int fSpeed; //前模块折算车速
unsigned int mSpeed; //中（顶）模块折算车速
unsigned int rSpeed; //后模块折算车速
unsigned int pSpeed; //外部CAN这算车速

unsigned int fADR[2]; //前模块电阻值
unsigned int mADR[2]; //中（顶）模块电阻值
unsigned int rADR[2]; //后模块电阻值

unsigned int ADR[8]; //模拟量采集   10/15
unsigned int ADV[8]; //模拟量采集 

DBCM_POUT fPOUT; //前模块功率输出状态
DBCM_POUT mPOUT; //中（顶）模块功率输出状态
DBCM_POUT rPOUT; //后模块功率输出状态

unsigned char fPF[16]; //前模块功率输出故障
unsigned char mPF[16]; //中（顶）模块功率故障
unsigned char rPF[16]; //后模块功率输出故障

unsigned int fpcur[15]; //前模块功率输出电流
unsigned int mpcur[15]; //中模块功率输出电流
unsigned int rpcur[15]; //后模块功率输出电流

unsigned int fSingle_miles;
unsigned int mSingle_miles;
unsigned int rSingle_miles;

unsigned char ccvs_eng_req; //启动请求

unsigned char dm_hcu_display[32]; //故障类型
unsigned char dm_tcu_display[32];

unsigned int  BUZZ_COUNT;
unsigned int  Vspeed=0; //车速
//系统初始化函数

void System_Init(void) {
    unsigned char i, j;
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
        if (wake_up3) {
            PWR_CTRL_DR = 0;
            PWR_CTRL = 1;
            SYSTME_Logic();
            if (wake_up1) {
                LED4 = FLASH; //左转向报警
                LED8 = FLASH; //右转向报警   
                BUZZ = !(LED8 || LED4); //转向蜂鸣
            }else {
                LED4 = 0; //左转向报警
                LED8 = 0; //右转向报警   
                BUZZ = !(LED8 || LED4); //转向蜂鸣
            }
        } else if (wake_up1) {//如果危险报警唤醒
            PWR_CTRL_DR = 0;
            PWR_CTRL = 1;
            F_PO6 = FLASH;
            F_PO7 = FLASH;
            T_PO15 = F_PO7; //左转向灯
            T_PO2 = F_PO6; //右转向灯
            //R_PO5 = F_PO7; //左转向灯
            //R_PO7 = F_PO6; //右转向灯
            LED4 = F_PO7; //左转向报警
            LED8 = F_PO6; //右转向报警   
            BUZZ = !(LED8 || LED4); //转向蜂鸣
        } else {
            POUT_Clear();
            LED_Clear();
        }

        if (F50ms) {
            F50ms = 0;
            LED_Out();
            SW_Input();
            BCAN_SendCtl();
        }

        if (IN1 || wake_up2) break; // 如果是ON唤醒则正常退出

        if (!wake_up3 && !wake_up1) {
            POUT_Clear();
            LED_Clear();
            __delay_us(100);
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
    TIM5_Init();
    EEROM_ReadSingleMiles();
    EEROM_ReadTotalMiles();
    EEROM_ReadHMPulse();
    EEROM_ReadBackLight();
    single_miles = e_single_miles;
    total_miles = e_total_miles;
    OC1RS = e_backlight; //更新背光值
    EEROM_ReadXSpeed();
    X_pSpeed = e_limit_pSpeed;
    ADC_Init();
    LCD_Init();
    alarm_led[0].byte = 0xC0; //蜂鸣器开启
    alarm_led[1].byte = 0xff;
    alarm_led[2].byte = 0xff;
    alarm_led[3].byte = 0xff;
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

    /*
    //调试用
    for(j=0;j<10;j++){
        for(i=0;i<24;i++){
            Battery_Voltage[j][i]=1000;
        }
    }
    Battery_Voltage[0][0]=5000;
    Battery_Voltage[1][0]=4000;
    Battery_Voltage[9][0]=3000;
     */
}

void SM_Logic(void) {
    static unsigned char SM_task = 0;
    static unsigned int temp = 0;
    static unsigned int temp16 = 0;
    //Vspeed = (30.0 * DJ_speed) / e_hm_pulse; //车速单位0.1KM/H
    pSpeed = Vspeed / 10;
    if (Vspeed < 1400)sm_new_value[0] = (unsigned int) (Vspeed * 1.885);
    else sm_new_value[0] = 2640;
    SM_Update_0(); //车速表   角度220° 2640

    if (DJ_speed >= 65534)DJ_speed = 20000;
    if (DJ_speed >= 20000)temp16 = DJ_speed - 20000;
    else temp16 = 20000 - DJ_speed;
    if (temp16 < 8000)sm_new_value[5] = (unsigned int) (temp16 * 0.33);
    else sm_new_value[5] = 2640;
    SM_Update_5(); //转速表   角度220° 2640

    if (SM_task == 0) {
        SM_task = 1;
        LCD_Exec();
    } else if (SM_task == 1) {
        SM_task = 2;
        /*              
        temp = ADR[1]; //更新水温表程序 最大值1152  步进角度96°
        if (temp < 10)
            sm_new_value[4] = 0;
        else if (temp < 52)
            sm_new_value[4] = ((temp - 10) * 5.48);
        else if (temp < 88)
            sm_new_value[4] = ((1152 * 0.2)+((temp - 52) * 6.4));
        else if (temp < 124)
            sm_new_value[4] = ((1152 * 0.4)+((temp - 88) * 6.4));
        else if (temp < 155)
            sm_new_value[4] = ((1152 * 0.6)+((temp - 124) * 7.43));
        else if (temp < 180)
            sm_new_value[4] = ((1152 * 0.8)+((temp - 155) * 9.216));
        else sm_new_value[4] = 1152;
         */
        temp = ADV[3] / 10;
        if (temp < 50)sm_new_value[4] = 0;
        else if (temp < 300)sm_new_value[4] = (unsigned int) (4.608 * (temp - 50));
        else sm_new_value[4] = 1152;
        SM_Update_4(); //气压1
    } else if (SM_task == 2) {
        SM_task = 3;
        temp = DC_SOC;
        if (temp <= 0) {//电机值为1152为满
            sm_new_value[3] = 0;
        } else if (temp > 100) {
            sm_new_value[3] = 1152;
        } else {
            sm_new_value[3] = (unsigned int) (11.52 * temp);
        }
        SM_Update_3(); //SOC
    } else if (SM_task == 3) {
        SM_task = 4;
        /*
        temp = ADR[2];//更新水温表程序 最大值1152  步进角度96°
        if (temp < 10)
            sm_new_value[2] = 0;
        else if (temp < 52)
            sm_new_value[2] = ((temp - 10) * 5.48);
        else if (temp < 88)
            sm_new_value[2] = ((1152 * 0.2)+((temp - 52) * 6.4));
        else if (temp < 124)
            sm_new_value[2] = ((1152 * 0.4)+((temp - 88) * 6.4));
        else if (temp < 155)
            sm_new_value[2] = ((1152 * 0.6)+((temp - 124) * 7.43));
        else if (temp < 180)
            sm_new_value[2] = ((1152 * 0.8)+((temp - 155) * 9.216));
        else sm_new_value[2] = 1152;
         */
        temp = ADV[4] / 10;
        if (temp < 50)sm_new_value[2] = 0;
        else if (temp < 300)sm_new_value[2] = (unsigned int) (4.608 * (temp - 50));
        else sm_new_value[2] = 1152;
        SM_Update_2(); //气压2
    } else if (SM_task == 4) {
        SM_task = 5;
        temp = ADR[0];
        if (temp < 160) { //更新电压表程序ADR[5]
            sm_new_value[1] = 0;
        } else if ((temp >= 160)&&(temp < 320)) {
            sm_new_value[1] = (unsigned int) (7.2 * (temp - 160));
        } else {
            sm_new_value[1] = 1152;
        }
        //燃油车表盘
        /*if (temp < 180) { //更新电压表程序ADR[5]
            sm_new_value[1] = 0;
        } else if ((temp >= 180)&&(temp < 240)) {
            sm_new_value[1] = (unsigned int) (6.667 * (temp - 180));
        } else if ((temp >= 240)&&(temp <= 320)) {
            sm_new_value[1] = (unsigned int) (10 * (temp - 240)) + 400;
        } else {
            sm_new_value[1] = 1200;
        }*/
        SM_Update_1(); //电压表 
    } else if (SM_task == 5) {
        SM_task = 0;
        if (F500ms) { //
            F500ms = 0;
            Count_ADR(); //换算模拟量的值  会严重影响主函数运行时间
            DS3231_ReadTime(&timer); //读取时间  

            //PCAN_send_mile();//里程
            PCAN_send_yb1();
            PCAN_send_yb2();

            LCD_BackLight(7); //

            if (save_flag) {
                save_flag = 0;
                e_single_miles = single_miles;
                e_total_miles = total_miles;
                EEROM_WriteSingleMiles();
                EEROM_WriteTotalMiles();
            }
        }
    } else {
        SM_task = 0;
    }
}

void Count_ADR(void) {
    float ad = 4096;
    //电压型传感器采集  ADV[]是实际的电压*1000
    //ADV[1] = (unsigned int) (read_ADR(1) / ad * 5000);
    
    ADV[3] = (unsigned int) (read_ADR(3) / ad * 3500) + 0.3*ADV[3];
    ADV[4] = (unsigned int) (read_ADR(4) / ad * 3500) + 0.3*ADV[4];
    ADV[5] = (unsigned int) (read_ADR(5) / ad * 3500) + 0.3*ADV[5]; 
    ADV[6] = (unsigned int) (read_ADR(6) / ad * 3500) + 0.3*ADV[6];
    //蓄电池电压    
    ADR[0] = (unsigned int) (550.0 * read_VOL() / ad); //实际电压放大10倍   //(read_VOL() - 1300)*10 / 76 + 180;
    if (ADR[0] >= 225) BAT24V_count = 0;
    //电阻型传感器采集  ADR[]是实际的阻值
    //ADR[1] = (unsigned int) (100.0 * read_ADR(1) / (ad - read_ADR(1))); 
    
    ADR[1] = (unsigned int) (70.0 * read_ADR(1) / (ad - read_ADR(1))) + 0.3*ADR[1];
    ADR[2] = (unsigned int) (70.0 * read_ADR(2) / (ad - read_ADR(2))) + 0.3*ADR[2];
    ADR[3] = (unsigned int) (70.0 * read_ADR(3) / (ad - read_ADR(3))) + 0.3*ADR[3];
    ADR[4] = (unsigned int) (70.0 * read_ADR(4) / (ad - read_ADR(4))) + 0.3*ADR[4];
    ADR[5] = (unsigned int) (70.0 * read_ADR(5) / (ad - read_ADR(5))) + 0.3*ADR[5];
    ADR[6] = (unsigned int) (70.0 * read_ADR(6) / (ad - read_ADR(6))) + 0.3*ADR[6];   
    
    if (ADR[1] > 1000)ADR[1] = 0;      
    if (ADR[2] > 1000)ADR[2] = 0;       
    if (ADR[3] > 1000)ADR[3] = 0;      
    if (ADR[4] > 1000)ADR[4] = 0;  
    if (ADR[5] > 1000)ADR[5] = 0;
    if (ADR[6] > 1000)ADR[6] = 0;
  

}

    unsigned int  QY_TIME=0;  //气压计时变量
    unsigned int  KYJ_TIME=0; //空压机计时变量
    unsigned char QY_OUT_EN=1;//气压外部使能开关
void SYSTME_Logic(void) {
    static unsigned char KYJ_EN=1;
    static unsigned char QY_EN=1;
 // F_PO1  = (IN16 && M_ON);                    //雨刮快档
 // F_PO2  = (IN14 && M_ON);                    //雨刮慢档
 // F_PO3  = (IN21 && M_ON);                    //喷水电机
    F_PO4  = (M_ON && IN11 && IN22);                  //左前雾灯
    F_PO5  = (M_ON && IN11);                          //开关背光小灯  
    F_PO6  = (FLASH && ((M_ON && IN10) || wake_up1)); //右转向灯
    F_PO7  = (FLASH && ((M_ON && IN9)  || wake_up1)); //左转向灯
    F_PO8  = (M_ON && IN24);                          //喇叭
    F_PO9  = (M_ON && IN12 && !IN13);                 //远光灯      
    F_PO10 = (M_ON && IN11 && IN3);                   //前门踏步灯
    F_PO11 =  F_PO9;                                  //远光灯
    F_PO12 = (M_ON && IN11 && IN2);                   //中门踏步灯 
    F_PO13 = (M_ON && IN12 && IN13);                  //近光灯 
    F_PO14 = (M_ON && IN11);                          //位置灯
    F_PO15 =  0;                                      //
    F_PO16 =  0;                                      //励磁电流
    
    M_PO1  =  0;                                //
    M_PO2  = (F_PO6);                           //右后转向灯
    M_PO3  = (M_ON && IN23 && F_PO4);           //后雾灯
    M_PO4  = (M_ON && mKL3);                    //刹车灯
    M_PO5  =  0;                                //
    M_PO6  = (M_ON && mKL5);                    //后舱灯 
    M_PO7  =  0;                                //
    M_PO8  = (wake_up2);                        //充电信号输出
    M_PO9  =  0;                                //
    if(M_ON && (Tmax>80))M_PO10=1; //40度开     //电池仓风扇电源 
    if(M_ON && (Tmax<75))M_PO10=0; //35度关                             
    M_PO11 =  0;                                //
    M_PO12 =  0;                                //
    M_PO13 = (F_PO14);                          //小灯电源
    if(M_ON &&((VCU_Status[0]&0X38)==0X08))M_PO14=1;     //倒车灯
    else                                   M_PO14=0; 
    M_PO15 = (F_PO7);                           //左后转向灯
    M_PO16 =  0;                                //励磁电流


}

void LED_Logic(void) {
    LED3  = 0; //空挡指示    
    LED5  = 0; //前进挡指示    
    LED23 = 0; //缓速器
    LED13 = 0; //电机故障 
    
    LED10 = 1; //总电源指示     
    
    LED15 = F_PO14; //小灯   
    
    LED4  = F_PO7;  //左转向灯
    LED8  = F_PO6;  //右转向灯   
    
    LED22 = F_PO13; //近光灯    
    LED17 = F_PO9;  //远光灯     
    
    LED19 = F_PO4;  //前雾灯
    LED20 = M_PO3;  //后雾灯    
    
    LED1  = IN3;    //前门开指示
    LED2  = IN2;    //中门开指示   

    LED18 = mKL1;   //手刹
    LED24 = M_PO4;  //刹车指示      
    
    LED21 = M_PO14; //倒车灯
    if(BAT24V_count >= BAT24_TIME)LED16=1;else LED16=0;//蓄电池电压低     
    
//////////////////////////////////////////////////////
//压力   0    0.1    0.2   0.4    0.6    0.8    1   //
//电压  0.5   0.725   1    1.5     2     2.5    3   //
/////////////////////////////////////////////////////
    if( //IN11              
       ((ADV[3]/10)<200)     
        //rKL10
      )LED9=1; else LED9=0; //气压1低于0.6MPa 报警
    
    if( //IN12              
        ((ADV[4]/10)<200)  
        //rKL12  
      )LED11=1;else LED11=0;//气压2低于0.6MPa 报警   
      
    
    if(VCU_Status[4]==0x01)LED6=1;else LED6=0; //充电状态
    if(wake_up2)LED7=1;else LED7=0; //充电枪插入    
    
    if(DC_Status[1]&0XC0)LED12=1;else LED12=0; //SOC低报警
    if( (DC_fault_dj==1) ||
        (DC_fault_dj==2) ||   
        (DC_fault_dj==3)        
      )LED14=1;else LED14=0; //动力电池系统故障    
    
//蜂鸣器 为0时响，为1时不响
         if(    IN9              ||  //左转向灯报警 
                IN10             ||  //右转向灯报警
                wake_up1
           )    BUZZ = !(LED4 || LED8);//
    else if( M_ON &&
           (   !fKL4 ||   //左前摩擦片报警
               !fKL5 ||   //右前摩擦片报警
            
             //!fKL8 ||   //左后摩擦片报警
             //!fKL9 ||   //右后摩擦片报警
                fKL1 ||   //安全门开信号
                mKL4 ||   //前门应急阀开启报警开关
                mKL6 ||   //后门应急阀开启报警开关 
                mKL9 ||   //发动机舱温         
                LED9 ||   //气压1  
                LED11||   //气压2   
            
               (MCU_Status[1]&0x02)    ||  //驱动电机温度报警
               (MCU_Status[1]&0x01)    ||  //驱动电机控制器温度报警
              ((JY_Status[0]&0x03)>0)  ||  //正极绝缘报警
              ((JY_Status[0]&0x0C)>0)  ||  //负极绝缘报警 
               (VCU_Status[5]==2)      ||  //整车故障2等级
               (VCU_Status[5]==3)      ||  //整车故障3等级
             //(DC_fault_dj>0)         ||  //电池故障等级
            
              ((Vspeed >= 50) && IN3)  ||  //前门开报警
              ((Vspeed >= 50) && IN2)  ||  //后门开报警        
             //(Vspeed > 690)              //超速报警  
               (Vspeed > e_limit_pSpeed*10)//超速报警              
            )
       )     BUZZ = 0;//!FLASH;
    else     BUZZ = 1;
 
    
    //背光 小灯开关闭合 
    if (LED15) { //IN11
        OC1RS = e_backlight;
    } else {
        OC1RS = 0;
    }

    /*if (M_ON) {
        PO1 = 0;
        PO2 = 0;
    } else {
        PO1 = 1;
        PO2 = 1;
    }
    PO1 = (M_ON || wake_up1 || wake_up2);
    PO2 = (DMC_Gear == 2);*/


}

//模块
void BCAN_SendCtl(void) {
    CAN_MESSAGE message_POUT;
    SW_DATA     temp;
    
    message_POUT.id = 0x6a4;
    message_POUT.data[0] = gCTL[0].byte;
    message_POUT.data[1] = gCTL[1].byte;
    message_POUT.data[2] = gCTL[2].byte;
    message_POUT.data[3] = gCTL[3].byte;
    message_POUT.data[4] = gCTL[4].byte;
    message_POUT.data[5] = gCTL[5].byte;
    
    temp.byte = 0;
    temp.bit0 = ((M_ON && wake_up3) );//|| wake_up2
    temp.bit1 = IN14; //慢档      
    temp.bit2 = IN15; //间歇
    temp.bit3 = IN16; //快档
    temp.bit4 = IN21; //喷水        
    if (IN14 && IN16)temp.bit1 = 0;
    if (IN21) {
        temp.bit1 = 0;//慢档
        temp.bit2 = 0;//间歇
        temp.bit3 = 0;//快档
    }
    message_POUT.data[6]=temp.byte;
    
    message_POUT.data[7] = 0;
    message_POUT.len = 8;
    message_POUT.type = 1;
    CAN1_SendMessage(&message_POUT);
}

void BCAN_send_mile(void) {
    CAN_MESSAGE msg;
    msg.data[0] = (unsigned char) (e_total_miles); //低八位
    msg.data[1] = (unsigned char) (e_total_miles >> 8); //二级八位
    msg.data[2] = (unsigned char) (e_total_miles >> 16); //三级八位
    msg.data[3] = (unsigned char) (e_total_miles >> 24); //高八位
    msg.data[4] = 0;
    msg.data[5] = 0;
    msg.data[6] = 0;
    msg.data[7] = 0;
    msg.id      = 0x454;
    msg.len     = 0x08;
    msg.type    = 0x01;
    CAN1_SendMessage(&msg);

}


void PCAN_send_yb1(void) {
    CAN_MESSAGE msg;
    unsigned int  temp1;
    
    msg.data[0] = Vspeed/10;//车速
    
    if(DJ_speed>=65534)DJ_speed=20000;
    if(DJ_speed>=20000)temp1=DJ_speed-20000;
    else               temp1=20000-DJ_speed;
    if(temp1>=2500)temp1=2500;
    msg.data[1] = temp1/10;//转速  
    
    msg.data[2] = 0;//水温
    msg.data[3] = 0;//机油压力  
    
    temp1=ADV[3]/10;//前气压-电压式
    if(temp1>=50 && temp1<=300)temp1=(unsigned int)(0.4*(temp1-50));  
    else                       temp1=0;
    msg.data[4]=(unsigned char)(temp1);

    temp1=ADV[4]/10;//后气压-电压式
    if(temp1>=50 && temp1<=300)temp1=(unsigned int)(0.4*(temp1-50));  
    else                       temp1=0;
    msg.data[5]=(unsigned char)(temp1);
  
    msg.data[6] = 0;//油量
    msg.data[7] = ADR[0]/5;//整车电压 
    
    msg.id      = 0x18FB7017;   
    msg.len     = 8;
    msg.type    = 0;
    CAN2_SendMessage(&msg);
    
}

void PCAN_send_yb2(void) {
    CAN_MESSAGE msg;
    SW_DATA     temp;
    unsigned long  temp1;
    
    temp.bit0 = LED22; //近光灯
    temp.bit1 = LED17; //远光灯
    temp.bit2 = LED19; //前雾灯
    temp.bit3 = LED20; //后雾灯   
    temp.bit4 = LED21; //倒车灯  
    temp.bit5 = LED24; //刹车灯
    temp.bit6 = LED4;  //左转向
    temp.bit7 = LED8;  //右转向
    msg.data[0] =temp.byte;
    
    temp.bit0 = 0;     //厢灯 1
    temp.bit1 = 0;     //厢灯 2
    temp.bit2 = LED18; //手刹
    temp.bit3 = 0;     //备用   
  //temp.bit4 =((VCU_Status[0]&0x38)==0x00); //空档  
    if((VCU_Status[0]&0x38)==0x00)temp.bit4=1;else temp.bit4=0;//空档 
    temp.bit5 = 0;     //备用
    temp.bit6 = LED1;  //前门开信号
    temp.bit7 = LED2;  //后门开信号
    msg.data[1] =temp.byte;
    
    temp.bit0 = mKL4;  //前应急门开关
    temp.bit1 = mKL6;  //后应急门开关
    temp.bit2 = mKL5;  //后舱门开关
    temp.bit3 = 0;     //空滤堵塞报警   
    temp.bit4 = mKL7;  //水位过低信号  
    temp.bit5 = LED15; //小灯开关
    temp.bit6 = IN24;  //喇叭开关
    temp.bit7 = 0;     //路牌灯开关
    msg.data[2] =temp.byte;
        
    temp.bit0 = 0;     //司机扇开关
  //temp.bit1 =(IN14||IN15||IN16); //雨刮开关
  //temp.bit2 =(IN21);             //洗涤器开关 
    if(fPOUT.BYTES[0]&0x03)temp.bit1=1;else temp.bit1=0;//雨刮开关
    if(fPOUT.BYTES[0]&0x04)temp.bit2=1;else temp.bit2=0;//洗涤器开关
    temp.bit3 = fKL3;  //ABS 工作   
    temp.bit4 = 0;     //缓速器工作  
    temp.bit5 = !fKL4; //左蹄片磨损报警
    temp.bit6 = !fKL5; //右蹄片磨损报警
    temp.bit7 = mKL9;  //发动机舱温报警
    msg.data[3] =temp.byte;
    
    temp1=total_miles;
    msg.data[4] = (unsigned char) (temp1);       
    msg.data[5] = (unsigned char) (temp1 >> 8 );
    msg.data[6] = (unsigned char) (temp1 >> 16); 
    msg.data[7] = (unsigned char) (temp1 >> 24);   
    
    msg.id      = 0x18FB7117;   
    msg.len     = 8;
    msg.type    = 0;
    CAN2_SendMessage(&msg);
    
}

void POUT_Clear(void) {
    gCTL[0].byte = 0x00;
    gCTL[1].byte = 0x00;
    gCTL[2].byte = 0x00;
    gCTL[3].byte = 0x00;
    gCTL[4].byte = 0x00;
    gCTL[5].byte = 0x00;
    gCTL[6].byte = 0x00;
    gCTL[7].byte = 0x00;
}

void LED_Clear(void){
    alarm_led[0].byte = 0xff;
    alarm_led[1].byte = 0x00;
    alarm_led[2].byte = 0x00;
    alarm_led[3].byte = 0x00;
}

/*
void PCAN_send_yb(void) {
    CAN_MESSAGE msg;
    SW_DATA     temp;
    unsigned int  temp1;
    unsigned char xz=1;//0电阻  1电压

    temp.bit0 =(IN11||IN12); //气压低报警 (LED9 || LED11)
    temp.bit1 = IN13; //驻车信号 LED18
    temp.bit2 = mKL12;//后仓门
    temp.bit3 = mKL15;//前门开   LED1
    temp.bit4 = mKH1; //后门开   LED2
    temp.bit5 = M_ON; //二挡
    temp.bit6 = M_ON; //一档
    temp.bit7 = 0;
    msg.data[0] =temp.byte;
    
    temp.bit0 = M_PO3; //后雾灯   LED20
    temp.bit1 = F_PO13;//近光灯   LED22
    temp.bit2 = 0;     //发动机预热
    temp.bit3 = 0;     //油量报警
    temp.bit4 = F_PO6; //右转向灯 LED8
    temp.bit5 = F_PO4; //前雾灯   LED19
    temp.bit6 = F_PO9; //远光灯   LED17
    temp.bit7 = F_PO7; //左转向灯 LED4
    msg.data[1] =temp.byte; 
    
    msg.data[2] = 0;
    msg.data[3] = (unsigned char)(Vspeed/5); //车速
       
if(xz==0){
    temp1=ADR[1];//电阻式
    if(temp1>10 && temp1<185)temp1=(unsigned int)(57.143*(temp1-10));  
    else                     temp1=0;
    msg.data[4]=(unsigned char)(temp1);
    msg.data[5]=(unsigned char)(temp1>>8);

    temp1=ADR[2];//电阻式
    if(temp1>10 && temp1<185)temp1=(unsigned int)(57.143*(temp1-10));  
    else                     temp1=0;
    msg.data[6]=(unsigned char)(temp1);
    msg.data[7]=(unsigned char)(temp1>>8);
    
}else {
    
    temp1=ADV[3]/10;//电压式
    if(temp1>=50 && temp1<=300)temp1=(unsigned int)(40*(temp1-50));  
    else                       temp1=0;
    msg.data[4]=(unsigned char)(temp1);
    msg.data[5]=(unsigned char)(temp1>>8);

    temp1=ADV[4]/10;//电压式
    if(temp1>=50 && temp1<=300)temp1=(unsigned int)(40*(temp1-50));  
    else                       temp1=0;
    msg.data[6]=(unsigned char)(temp1);
    msg.data[7]=(unsigned char)(temp1>>8);
}
    msg.id      = 0x0C19A7A1;      
    msg.len     = 8;
    msg.type    = 0;
    CAN2_SendMessage(&msg);
    
}
 
void PCAN_send_time(void) {
    CAN_MESSAGE msg;
    static unsigned char bcd[6]={0,0,0,0,0,0,};
    unsigned char i;
    unsigned char sbcd=0;

//msg.data[0]=timer.second;
//msg.data[1]=timer.minute;
//msg.data[2]=timer.hour;
//msg.data[3]=timer.day;
//msg.data[4]=timer.month;
//msg.data[5]=timer.year;  
    
    for(i=0;i<7;i++){    
        sbcd=(unsigned char)(timer.byte[i]>>4);
        sbcd=sbcd*10;
        sbcd+=(unsigned char)(timer.byte[i]&0x0f);      
        bcd[i]=sbcd;     
    }
    msg.data[0] = bcd[6];   //年 
    msg.data[1] = bcd[5];   //月
    msg.data[2] = bcd[4];   //日
    msg.data[3] = bcd[2];   //时 
    msg.data[4] = bcd[1];   //分    
    msg.data[5] = bcd[0];   //秒
    msg.data[6] = 0x00;     
    msg.data[7] = 0x00;
    msg.id      = 0x18EFA5A1;   
    msg.len     = 8;
    msg.type    = 0;
    CAN2_SendMessage(&msg);
    
}

void PCAN_send_speed(void) {
    CAN_MESSAGE msg;
    
    msg.data[0] = 0xff;
    msg.data[1] = 0xff;
    msg.data[2] = 0xff;
    msg.data[3] = 0xff;
    msg.data[4] = 0xff;
    msg.data[5] = 0xff;
    msg.data[6] = 0xff;
    msg.data[7] = Vspeed/10;//pSpeed;
    msg.id      = 0X0CFE6CEE;
    msg.len     = 8;
    msg.type    = 0;
    CAN2_SendMessage(&msg);
      
}

void PCAN_send_mile(void) {
    CAN_MESSAGE   msg;    
    unsigned long temp;
 
    temp=total_miles;
    msg.data[0] = (unsigned char) (temp);       
    msg.data[1] = (unsigned char) (temp >> 8 );
    msg.data[2] = (unsigned char) (temp >> 16); 
    msg.data[3] = (unsigned char) (temp >> 24); 
    temp=single_miles;
    msg.data[4] = (unsigned char) (temp);       
    msg.data[5] = (unsigned char) (temp >> 8 );
    msg.data[6] = (unsigned char) (temp >> 16); 
    msg.data[7] = (unsigned char) (temp >> 24);     
    msg.id      = 0x0C1AA7A1;    
    msg.len     = 8;
    msg.type    = 0;
    CAN2_SendMessage(&msg);

}

void PCAN_send_test(void) {
    CAN_MESSAGE msg;
    
    msg.data[0] = (unsigned char)(QY_TIME);
    msg.data[1] = (unsigned char)(QY_TIME>>8);
    msg.data[2] = (unsigned char)(KYJ_TIME);
    msg.data[3] = (unsigned char)(KYJ_TIME>>8);
    msg.data[4] = (unsigned char)(ADV[6]/10);
    msg.data[5] = (unsigned char)(ADV[6]/10>>8);
    msg.data[6] = (unsigned char)(ADV[5]/10);
    msg.data[7] = (unsigned char)(ADV[5]/10>>8);
    msg.id      = 0X1800FF00;
    msg.len     = 8;
    msg.type    = 0;
    CAN2_SendMessage(&msg);
   
}
*/


/*
void DM_HCU(unsigned char x) {//解析出第x个故障码的spn和fmi
    hcu_spn = CAN_18FECAEF.bData[2 + 4 * (x - 1)]
            +((unsigned int) CAN_18FECAEF.bData[3 + 4 * (x - 1)] << 8)
            +((unsigned long) (CAN_18FECAEF.bData[4 + 4 * (x - 1)]&0xE0) << 11);
    hcu_fmi = (CAN_18FECAEF.bData[4 + 4 * (x - 1)] & 0x1F);
    //if(hcu_spn==103) hcu_spn=0;//随州那边103故障码无法消除
}

void DM_TCU(unsigned char x) {//解析出第x个故障码的spn和fmi
    tcu_spn = CAN_18FECA03.bData[2 + 4 * (x - 1)]
            +((unsigned int) CAN_18FECA03.bData[3 + 4 * (x - 1)] << 8)
            +((unsigned long) (CAN_18FECA03.bData[4 + 4 * (x - 1)]&0xE0) << 11);
    tcu_fmi = (CAN_18FECA03.bData[4 + 4 * (x - 1)] & 0x1F);
}

void DM_CCU(unsigned char x) {//解析出第x个故障码的spn和fmi
    ccu_spn = CAN_18FECAF5.bData[2 + 4 * (x - 1)]
            +((unsigned int) CAN_18FECAF5.bData[3 + 4 * (x - 1)] << 8)
            +((unsigned long) (CAN_18FECAF5.bData[4 + 4 * (x - 1)]&0xE0) << 11);
    ccu_fmi = (CAN_18FECAF5.bData[4 + 4 * (x - 1)] & 0x1F);
}

void DM_ECU(unsigned char x) {//解析出第x个故障码的spn和fmi
    ecu_spn = CAN_18FECA00.bData[2 + 4 * (x - 1)]
            +((unsigned int) CAN_18FECA00.bData[3 + 4 * (x - 1)] << 8)
            +((unsigned long) (CAN_18FECA00.bData[4 + 4 * (x - 1)]&0xE0) << 11);
    ecu_fmi = (CAN_18FECA00.bData[4 + 4 * (x - 1)] & 0x1F);
}
 */
void __attribute__((__interrupt__, auto_psv)) _C1Interrupt(void) {
    unsigned char i = 0, j = 0;
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
                fkey[0].byte  = fKEY.BYTES[0];                
                fkey[1].byte  = fKEY.BYTES[1];                  
                fkey[2].byte  = fKEY.BYTES[2];
                fkey[1].bit7  = fADD;
                fFreq = message.data[3]+((unsigned int) message.data[4] << 8);
                fSpeed = message.data[5]+((unsigned int) message.data[6] << 8);
                break;
            case 0x682:
                Mcan_count = 0;
                mKEY.BYTES[0] = message.data[0];
                mKEY.BYTES[1] = message.data[1];
                mKEY.BYTES[2] = message.data[2];
                tkey[0].byte  = mKEY.BYTES[0];                
                tkey[1].byte  = mKEY.BYTES[1];                  
                tkey[2].byte  = mKEY.BYTES[2];
                tkey[1].bit7  = mADD;
                mFreq = message.data[3]+((unsigned int) message.data[4] << 8);
                mSpeed = message.data[5]+((unsigned int) message.data[6] << 8);
                break;
            case 0x683:
                Rcan_count = 0;
                rKEY.BYTES[0] = message.data[0];
                rKEY.BYTES[1] = message.data[1];
                rKEY.BYTES[2] = message.data[2];
                rkey[0].byte  = rKEY.BYTES[0];                
                rkey[1].byte  = rKEY.BYTES[1];                  
                rkey[2].byte  = rKEY.BYTES[2];
                rkey[1].bit7  = rADD;
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
            case 0x621:
                Fcan_count = 0;
                fpcur[0] = message.data[0]+((unsigned int) message.data[1] << 8);
                fpcur[1] = message.data[2]+((unsigned int) message.data[3] << 8);
                fpcur[2] = message.data[4]+((unsigned int) message.data[5] << 8);
                fpcur[3] = message.data[6]+((unsigned int) message.data[7] << 8);
                break;
            case 0x631:
                Fcan_count = 0;
                fpcur[4] = message.data[0]+((unsigned int) message.data[1] << 8);
                fpcur[5] = message.data[2]+((unsigned int) message.data[3] << 8);
                fpcur[6] = message.data[4]+((unsigned int) message.data[5] << 8);
                fpcur[7] = message.data[6]+((unsigned int) message.data[7] << 8);
                break;
            case 0x641:
                Fcan_count = 0;
                fpcur[8] = message.data[0]+((unsigned int) message.data[1] << 8);
                fpcur[9] = message.data[2]+((unsigned int) message.data[3] << 8);
                fpcur[10] = message.data[4]+((unsigned int) message.data[5] << 8);
                fpcur[11] = message.data[6]+((unsigned int) message.data[7] << 8);
                break;
            case 0x651:
                Fcan_count = 0;
                fpcur[12] = message.data[0]+((unsigned int) message.data[1] << 8);
                fpcur[13] = message.data[2]+((unsigned int) message.data[3] << 8);
                fpcur[14] = message.data[4]+((unsigned int) message.data[5] << 8);
                break;
            case 0x622:
                Mcan_count = 0;
                mpcur[0] = message.data[0]+((unsigned int) message.data[1] << 8);
                mpcur[1] = message.data[2]+((unsigned int) message.data[3] << 8);
                mpcur[2] = message.data[4]+((unsigned int) message.data[5] << 8);
                mpcur[3] = message.data[6]+((unsigned int) message.data[7] << 8);
                break;
            case 0x632:
                Mcan_count = 0;
                mpcur[4] = message.data[0]+((unsigned int) message.data[1] << 8);
                mpcur[5] = message.data[2]+((unsigned int) message.data[3] << 8);
                mpcur[6] = message.data[4]+((unsigned int) message.data[5] << 8);
                mpcur[7] = message.data[6]+((unsigned int) message.data[7] << 8);
                break;
            case 0x642:
                Mcan_count = 0;
                mpcur[8] = message.data[0]+((unsigned int) message.data[1] << 8);
                mpcur[9] = message.data[2]+((unsigned int) message.data[3] << 8);
                mpcur[10] = message.data[4]+((unsigned int) message.data[5] << 8);
                mpcur[11] = message.data[6]+((unsigned int) message.data[7] << 8);
                break;
            case 0x652:
                Mcan_count = 0;
                mpcur[12] = message.data[0]+((unsigned int) message.data[1] << 8);
                mpcur[13] = message.data[2]+((unsigned int) message.data[3] << 8);
                mpcur[14] = message.data[4]+((unsigned int) message.data[5] << 8);
                break;
            case 0x623:
                Rcan_count = 0;
                rpcur[0] = message.data[0]+((unsigned int) message.data[1] << 8);
                rpcur[1] = message.data[2]+((unsigned int) message.data[3] << 8);
                rpcur[2] = message.data[4]+((unsigned int) message.data[5] << 8);
                rpcur[3] = message.data[6]+((unsigned int) message.data[7] << 8);
                break;
            case 0x633:
                Rcan_count = 0;
                rpcur[4] = message.data[0]+((unsigned int) message.data[1] << 8);
                rpcur[5] = message.data[2]+((unsigned int) message.data[3] << 8);
                rpcur[6] = message.data[4]+((unsigned int) message.data[5] << 8);
                rpcur[7] = message.data[6]+((unsigned int) message.data[7] << 8);
                break;
            case 0x643:
                Rcan_count = 0;
                rpcur[8] = message.data[0]+((unsigned int) message.data[1] << 8);
                rpcur[9] = message.data[2]+((unsigned int) message.data[3] << 8);
                rpcur[10] = message.data[4]+((unsigned int) message.data[5] << 8);
                rpcur[11] = message.data[6]+((unsigned int) message.data[7] << 8);
                break;
            case 0x653:
                Rcan_count = 0;
                rpcur[12] = message.data[0]+((unsigned int) message.data[1] << 8);
                rpcur[13] = message.data[2]+((unsigned int) message.data[3] << 8);
                rpcur[14] = message.data[4]+((unsigned int) message.data[5] << 8);
                break;
            case 0x561:
                Fcan_count = 0;
                fPOUT.BYTES[0] = message.data[0];
                fPOUT.BYTES[1] = message.data[1];
                for (j = 0; j < 4; j++) {//输出状态采集
                    for (i = 0; i < 4; i++) {
                        fPF[i + 4 * j] = (message.data[j + 2] >> (i * 2))&0x03;
                    }
                }
                fMK_Version=message.data[6];//模块版本号
                break;
            case 0x562:
                Mcan_count = 0;
                mPOUT.BYTES[0] = message.data[0];
                mPOUT.BYTES[1] = message.data[1];
                for (j = 0; j < 4; j++) {
                    for (i = 0; i < 4; i++) {
                        mPF[i + 4 * j] = (message.data[j + 2] >> (i * 2))&0x03;
                    }
                }
                mMK_Version=message.data[6];//模块版本号
                break;
            case 0x563:
                Rcan_count = 0;
                rPOUT.BYTES[0] = message.data[0];
                rPOUT.BYTES[1] = message.data[1];
                for (j = 0; j < 4; j++) {
                    for (i = 0; i < 4; i++) {
                        rPF[i + 4 * j] = (message.data[j + 2] >> (i * 2))&0x03;
                    }
                }
                rMK_Version=message.data[6];//模块版本号
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

/*******************分包处理*****************/

DM1 CAN_18FECAEF;
unsigned char CAN_18FECAEF_len;
DM1 CAN_18FECA03;
unsigned char CAN_18FECA03_len;
DM1 CAN_18FECAF5;
unsigned char CAN_18FECAF5_len;
DM1 CAN_18FECA00;
unsigned char CAN_18FECA00_len;
CAN_CACHE m_can;
CAN_CACHE n_can;
CAN_CACHE c_can;
CAN_CACHE e_can;

/**************************************************/

unsigned int CAN_BAT_COUNT=0;
unsigned int CAN_DRIVE_COUNT=0;

//整车控制器变量 
unsigned int   DJcontroler_voltage=0;//电机控制器输入电压
unsigned int   DJcontroler_current=10000; //电机控制器入电流高
unsigned int   DJ_torque=20000; //转矩Torque 
unsigned int   DJ_speed=20000;

unsigned char  DJ_temperature=40;             //驱动电机温度
unsigned char  DJcontroler_temperature=40;    //驱动电机控制器温度
unsigned char  FDJ_temperature=40;            //发电机温度
unsigned char  FDJcontroler_temperature=40;   //发电机控制器温度
unsigned char  DR_state=0x80;                 //司机操作状态
unsigned char  KEY_state=0;                   //开关量状态
unsigned char  system_state=0;                //系统工作状态
unsigned int   system_fault=0;                //系统故障码

unsigned  int  EngineSpeed=0;
unsigned char  WaterTem=40;
unsigned char  EngineLoad=0;     //发动机负荷率
unsigned char  urea_high=0;      //尿素液位
unsigned char  speed_st1=0;      //发动机目标油门踏板状态
unsigned char  speed_st2=0;      //发动机实际油门踏板
unsigned char  controler_LIFE=0; //整车控制器Life

unsigned char  traction_st=0;   //牵引踏板百分比
unsigned char  brake_st=0;      //制动踏板百分比
unsigned char  engine_oil_press=0;        //发动机机油压力
unsigned char  ambient_air_temperature=40;//发动机进气温度
unsigned long  total_fuel=0;     //发动机累计油（气）耗量

unsigned char  debug_num[8]; //调试参数1

unsigned int   DJ_torqueST=0; //驱动电机目标转矩
unsigned int   EngineSpeST=0; //发动机目标转速
unsigned char  instantaneous_fuel=0; //瞬态燃油经济性
unsigned int   single_BGLfuel=0;     //小计百公里油耗
unsigned int   total_BGLfuel=0;      //总计百公里油耗

unsigned char  KZQversion[7];
unsigned char  FDJversion[7];  //程序版本号高 3字节
unsigned char  DJversion[7];   //程序版本号高 3字节

unsigned int   anode_R;     //正端对地绝缘电阻
unsigned int   negative_R;  //负端对地绝缘电阻
unsigned char  eror_R;      //绝缘故障等级
unsigned char  R_life;      //
unsigned char  R_ID=0XAA;   //整车漏电报警

unsigned int   DCDC_SC_voltage=10000;
unsigned int   DCDC_SC_current=32000;
unsigned int   DCDC_SR_voltage=10000;
unsigned char  DCDC_temperature=40;
unsigned char  DCDC_fault=0;         //DCDC故障码

unsigned int   DCAC_W_current=10000;
unsigned int   DCAC_V_current=10000;
unsigned int   DCAC_U_current=10000;
unsigned char  DCAC_temperature=40;
unsigned char  DCAC_fault=0;   

unsigned char  KT_Status[3];
unsigned char  KT_temp[3]={40,40,40};
unsigned char  KT_ctrl=0;
unsigned char  KT_life=0;
unsigned int   KT_current=10000;
unsigned char  KT_MODE=0;//空调选择模式  0电动 1传统
unsigned char  KT_temp1[3]={60,60,60};//精度0.5 偏移量-30

unsigned int   DC_voltage=0; //电池电压 
unsigned int   DC_current=10000; //电池电流 
unsigned char  DC_SOC=0;
unsigned char  DC_Status[6]={0,0,0,0x00,0,0};

unsigned int   Vmax=10000;//最大单体电压
unsigned char  Vmax_num;  //最大单体电压组号
unsigned char  Tmax=40;   //最大单体电池温度
unsigned char  Tmax_num;  //最大单体电池温度组号
unsigned int   Vmin=10000;//最小单体电压
unsigned char  Vmin_num;  //最小单体电压组号 
 
unsigned int   CD_current=0; //当前最大允许充电电流
unsigned int   FD_current=10000; //当前最大允许放电电流
unsigned char  Tmin=40;          //最低单体电池温度
unsigned char  Twater=40;        //进水口温度
unsigned char  DC_JCQst[2]={0,0}; //电池接触器请求断开标识

unsigned char  KT_fuhe=0; //空调实际工作负荷
unsigned char  CAR_MODE=0;//整车模式-自检-快充-慢充
unsigned char  XHLC=0;    //续航里程
unsigned char  TYBJ_state[8]={0,0,0,0,0,0,0,0};//通用报警标志

unsigned int   Vpj=10000;//单体平均电压

unsigned char  Tmax1=40;//最大单体电池温度

unsigned int   anode_R1=0;//正端对地绝缘电阻
unsigned int   negative_R1=0;//负端对地绝缘电阻

unsigned char  VIN_Status=0;//VIN接收状态
unsigned char  CDZ_temp[4]={40,40,40,40};//充电座温度

unsigned int   DC_EDRL=0;  //电池额定容量
unsigned int   DC_EDDY=0;  //电池额定电压
unsigned int   DC_CL_SUM=0;//电池单体串联数量
unsigned char  DC_BL_SUM=0;//电池单体并联数量 
unsigned char  DC_WD_SUM=0;//电池系统温度探针

unsigned char  Tmax_box=0;//最大单体电池温度箱号
unsigned char  Tmin_box=0;//最小单体电池温度箱号
unsigned char  Vmax_box=0;//最大单体电池电压箱号
unsigned char  Vmin_box=0;//最小单体电池电压箱号
unsigned char  Tmin_num=0;//最小单体电池温度组号

unsigned char  DC_style=0;//电池类型
unsigned char  DC_LengQ=0;//电池冷却方式

unsigned int   BAT_vol[10]={10000,10000,10000,10000,10000,10000,10000,10000,10000,10000};//单体正反向电压
unsigned int   BAT_num[10]={0,0,0,0,0,0,0,0,0,0};//单体正反向电压编号

unsigned char  BAT_temp[10]={40,40,40,40,40,40,40,40,40,40};//单体正反向温度
unsigned char  BAT_num1[10]={0,0,0,0,0,0,0,0,0,0};//单体正反向温度编号

unsigned char  MHQ_DCBOX=0;//灭火器电池箱号
unsigned char  MHQ_YJJB=0; //灭火器系统预警级别
unsigned char  MHQ_fault=0;//灭火器故障码

unsigned char  MHQ_TIME=0;//请求校时
unsigned char  YW_Status[6]={0,0,0,0,0,0};//烟雾报警

unsigned char  VCU_Status[10]={0x00,0x02,0x00,0x00,0x03,0x00,0x00,0x00,0x00,0x00,};
unsigned long  VCU_fault;//系统故障码
unsigned char  VCU_Cmd[5]={0x55,0x55,0xAA,0x55,0x55};//控制指令
unsigned char  MCU_Num[5];//驱动电机序号
unsigned char  MCU_Status[10];//驱动电机状态
unsigned long  MCU_fault;//系统故障码

unsigned char  QB_Status[5];
unsigned int   QB_Power=200;//电机功率
unsigned char  QB_temperature=40;//电机温度
unsigned char  QB_controler_temperature=40;//电机控制器温度
unsigned int   QB_controler_voltage;//母线电压
unsigned int   QB_speed;//转速

unsigned char  YB_Status[5];
unsigned int   YB_Power=200;//电机功率
unsigned char  YB_temperature=40;//电机温度
unsigned char  YB_controler_temperature=40;//电机控制器温度
unsigned int   YB_controler_voltage;//母线电压
unsigned int   YB_speed;//转速

unsigned char  DCDC_Status[5];//工作状态
unsigned int   DCDC_MX_voltage;//母线电压

unsigned int   JY_R;//绝缘电阻
unsigned char  JY_Status[5]; //正极绝缘报警  负极绝缘报警
unsigned int   CD_voltage;   //电池组最大充电电压
unsigned char  Vmax_xt_num;  //最高电压电池子系统号
unsigned char  Vmin_xt_num;  //最低电压电池子系统号   
unsigned char  DC_fault_dj;  //BMS 故障等级

unsigned char  Tpj=40; //子系统平均温度
unsigned char  Tmax_xt_num;//最高温度子系统号
unsigned char  Tmin_xt_num;//最低温度子系统号               
unsigned char  Tmax_tz_num;//最高温度探针序号          
unsigned char  Tmin_tz_num;//最低温度探针序号  
unsigned char  DC_cd_sum;//可充电储能装置故障总数 N1
unsigned long  DC_fault;//系统故障码
unsigned int   MAX_cd_voltage; //最高充电电压
unsigned char  DC_control;//控制
unsigned char  BAT_sum;//单体数 
unsigned int   BAT_Vmax_bj; //单体电压报警上限
unsigned int   BAT_Vmax_qd; //单体电压切断上限
unsigned int   BAT_Vmin_bj; //单体电压报警下限
unsigned int   BAT_Vmin_qd; //单体电压切断下限
unsigned int   DC_Max_ed_cd_current; //额定最大充电电流
unsigned int   DC_Max_ed_fd_current; //额定最大放电电流           





void __attribute__((__interrupt__, auto_psv)) _C2Interrupt(void) {
    unsigned char i = 0;
    CAN_MESSAGE msg;
    
    IEC2bits.C2IE = 0; 
    
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
        ECU_TIME=0;
        switch (msg.id) {
            case 0x0CFFC9D0://整车控制器1
                VCU_Status[0]=msg.data[0];//整车控制器状态 换挡面板状态 高压互锁状态报警 制动系统报警
                VCU_Status[1]=msg.data[1];//车辆状态
                VCU_Status[2]=msg.data[2];//运行模式       
                Vspeed=((unsigned int)msg.data[4]<<8) + msg.data[3];//车速
                VCU_Status[3]=msg.data[5];//档位 制动力 驱动力状态
                VCU_Status[4]=msg.data[6];//充电状态             
                VCU_Status[5]=msg.data[7];//最高报警等级             
                break;
            case 0x0CFFC8D0://整车控制器2 
                traction_st=msg.data[0];   //牵引踏板百分比
                brake_st=msg.data[1];      //制动踏板百分比
                VCU_Status[6]=msg.data[2]; //其他故障总数 N 
                VCU_fault=(((unsigned long)msg.data[6]<<24)+
                           ((unsigned long)msg.data[5]<<16)+
                           ((unsigned long)msg.data[4]<<8) + 
                                           msg.data[3]);   //系统故障码-其他故障代码列表
                VCU_Status[7]=msg.data[7]; //驱动电机个数
                break;    
            case 0x0CFFCAD0://整车控制器3      
                VCU_Cmd[0]=msg.data[0];   //油泵控制器控制指令
                VCU_Cmd[1]=msg.data[1];   //气泵控制器控制指令            
                VCU_Cmd[2]=msg.data[2];   //空调变频器控制指令            
                VCU_Cmd[3]=msg.data[3];   //DC/DC 控制指令   
                VCU_Status[8]=msg.data[4];//DC/DC 状态           
                VCU_Status[9]=msg.data[5];//DCDC 温度报警   状态报警   
                break;
            case 0x18F501F0://电机控制器                
                MCU_Num[0]=msg.data[0];    //驱动电机序号
                MCU_Status[0]=msg.data[1]; //驱动电机状态
                DJ_temperature=msg.data[2];             //驱动电机温度
                DJcontroler_temperature=msg.data[3];    //驱动电机控制器温度
                DJcontroler_voltage=((unsigned int)msg.data[5]<<8) + msg.data[4];//电机控制器输入电压
                DJcontroler_current=((unsigned int)msg.data[7]<<8) + msg.data[6]; //电机控制器入电流高
                break;                
            case 0x18F502F0://主驱状态 2      
                MCU_Num[1]=msg.data[0];    //驱动电机序号
                DJ_speed =((unsigned int)msg.data[2]<<8) + msg.data[1];//电机转速
                DJ_torque=((unsigned int)msg.data[4]<<8) + msg.data[3];//电机转矩
                break;  
            case 0x18F503F0://主驱状态 2      
                MCU_Num[2]=msg.data[0];    //驱动电机序号
                MCU_Status[1]=msg.data[1]; //驱动电机控制器温度报警  电机温度报警
                MCU_Num[3]=msg.data[2];    //驱动电机故障总数 N2    
                MCU_fault=(((unsigned long)msg.data[6]<<24)+
                           ((unsigned long)msg.data[5]<<16)+
                           ((unsigned long)msg.data[4]<<8) + 
                                           msg.data[3]);   //系统故障码-其他故障代码列表
                break;        
            case 0x1801A79A://气泵控制器信息
                QB_Status[0]=msg.data[0]; //短路、过流故障 电机温度报警 电机控制器温度报警 通讯故障 转子传感器故障 电机运行状态
                QB_Power=msg.data[1];     //电机功率
                QB_temperature=msg.data[2];           //电机温度
                QB_controler_temperature=msg.data[3]; //电机控制器温度
                QB_controler_voltage=(((unsigned int)msg.data[5]<<8) + msg.data[4]);     //母线电压
                QB_speed=(((unsigned int)msg.data[7]<<8) + msg.data[6]);                 //转速
                break;        
            case 0x1801A79B://油泵控制器信息 
                YB_Status[0]=msg.data[0]; //短路、过流故障 电机温度报警 电机控制器温度报警 通讯故障 转子传感器故障 电机运行状态
                YB_Power=msg.data[1];     //电机功率
                YB_temperature=msg.data[2];           //电机温度
                YB_controler_temperature=msg.data[3]; //电机控制器温度
                YB_controler_voltage=(((unsigned int)msg.data[5]<<8) + msg.data[4]);     //母线电压
                YB_speed=(((unsigned int)msg.data[7]<<8) + msg.data[6]);                 //转速
                break;      
            case 0x1801A79C://DCDC 控制器信息
                DCDC_Status[0]=msg.data[0];   //工作状态  通讯故障报警
                DCDC_Status[1]=msg.data[1];   //温度故障  输出过流 输出过压 输出欠压 输入过压 输入欠压 输出短路 硬件故障       
                DCDC_temperature=msg.data[2]; //工作温度
                DCDC_SC_current=(((unsigned int)msg.data[4]<<8) + msg.data[3]);//输出电流
                DCDC_SC_voltage=msg.data[5]; //输出电压
                DCDC_MX_voltage=(((unsigned int)msg.data[7]<<8) + msg.data[6]);//母线电压
                break;         
            case 0x1801A79D://绝缘检测仪信息   
                JY_R=(((unsigned int)msg.data[1]<<8) + msg.data[0]);//绝缘电阻
                JY_Status[0]=msg.data[2]; //正极绝缘报警  负极绝缘报警
                anode_R=   (((unsigned int)msg.data[4]<<8) + msg.data[3]);  //正端对地绝缘电阻
                negative_R=(((unsigned int)msg.data[6]<<8) + msg.data[5]);  //负端对地绝缘电阻
                JY_Status[1]=msg.data[7]; //单元工作状态 0：未正常，1：已正常，2：错误，3：无操作
                break;   
            case 0x18FF217B://电池组总体数据信息     
                DC_Status[0] = msg.data[0];//BMS 系统工作状态 内部总线状态 充电状态反馈 加热状态
                DC_voltage = (((unsigned int) msg.data[2] << 8) + msg.data[1]); //电池电压 
                DC_current = (((unsigned int) msg.data[4] << 8) + msg.data[3]); //电池电流 
                DC_SOC = msg.data[5];
                CD_voltage = (((unsigned int) msg.data[7] << 8) + msg.data[6]); //电池组最大充电电压 
                break;  
            case 0x18FF227B:     
                DC_Status[1] = msg.data[0];//
                DC_Status[2] = msg.data[1];// 
                DC_Status[3] = msg.data[2];//        
                DC_Status[4] = msg.data[3];//  
                DC_style = msg.data[4];//车载储能装置类型
                Vmax_xt_num = msg.data[5];//最高电压电池子系统号
                Vmin_xt_num = msg.data[6];//最低电压电池子系统号   
                DC_fault_dj = msg.data[7];//BMS 故障等级
                break;         
            case 0x18FF247B://电池组电压 1     
                Vmax = (((unsigned int) msg.data[1] << 8) + msg.data[0]); //最大单体电压
                Vmin = (((unsigned int) msg.data[3] << 8) + msg.data[2]); //最小单体电压
                Vpj =  (((unsigned int) msg.data[5] << 8) + msg.data[4]); //单体平均电压
                Vmax_num = msg.data[6]; //最高电压电池单体代号
                Vmin_num = msg.data[7]; //最低电压电池单体代号
                break;        
            case 0x18FF257B://电池组温度 1         
                Tmax     = msg.data[0]; //最高温度值
                Tmin     = msg.data[1]; //最低温度值
                Tpj      = msg.data[2]; //子系统平均温度
                Tmax_xt_num = msg.data[3];//最高温度子系统号
                Tmin_xt_num = msg.data[4];//最低温度子系统号               
                Tmax_tz_num = msg.data[5];//最高温度探针序号          
                Tmin_tz_num = msg.data[6];//最低温度探针序号           
                break;      
            case 0x18FFA97B://充电控制信息        
                DC_Status[5] = msg.data[0];//电加热接触器控制 充电接触器控制
                DC_cd_sum = msg.data[1];//可充电储能装置故障总数 N1
                DC_fault=(((unsigned long)msg.data[5]<<24)+
                          ((unsigned long)msg.data[4]<<16)+
                          ((unsigned long)msg.data[3]<<8) + 
                                          msg.data[2]);   //可充电储能装置故障代码列表
                break;                
            case 0x13CC16B2://充电参数广播帧             
                MAX_cd_voltage = (((unsigned int) msg.data[1] << 8) + msg.data[0]); //最高充电电压
                CD_current = (((unsigned int) msg.data[3] << 8) + msg.data[2]); //实际要求充电电流 
                DC_control = msg.data[4];//控制
                BAT_sum = msg.data[5];//单体数 
                break;        
            case 0x104C1991://BMS 系统参数 1     
                BAT_Vmax_bj = (((unsigned int) msg.data[1] << 8) + msg.data[0]); //单体电压报警上限
                BAT_Vmax_qd = (((unsigned int) msg.data[3] << 8) + msg.data[2]); //单体电压切断上限
                BAT_Vmin_bj = (((unsigned int) msg.data[5] << 8) + msg.data[4]); //单体电压报警下限
                BAT_Vmin_qd = (((unsigned int) msg.data[7] << 8) + msg.data[6]); //单体电压切断下限
                break;        
            case 0x104C1992://BMS 系统参数 2           
                DC_Status[6] = (((unsigned int) msg.data[1] << 8) + msg.data[0]);//单体电压互差报警
                DC_Max_ed_cd_current = (((unsigned int) msg.data[3] << 8) + msg.data[2]); //额定最大充电电流
                DC_Max_ed_fd_current = (((unsigned int) msg.data[5] << 8) + msg.data[4]); //额定最大放电电流           
                DC_EDRL = (((unsigned int) msg.data[7] << 8) + msg.data[6]); //额定容量
                break;           
  
            default:
                break;
        }
    }
    C2INTF = 0; /* the individual flag register cleared */
    C2RX0CONbits.RXFUL = 0;
    IFS2bits.C2IF = 0;
    IEC2bits.C2IE = 1; 
}

void __attribute__((__interrupt__, auto_psv)) _T1Interrupt(void) {//10ms中断一次
    static unsigned int cnt0 = 0;
    static unsigned int cnt1 = 3;
    static unsigned int cnt2 = 7;
    static unsigned int cnt3 = 9;
    static unsigned int cnt4 = 0;
    static unsigned int cnt5 = 0;
    static unsigned int lpcnt2 = 0, lpcnt1 = 0, lpcount = 0;
    static unsigned int Fcount = 0, Kcount = 0;
    static unsigned int count6 = 0;
    static unsigned int count7 = 0;
    static unsigned int can1 = 0, can2 = 0;
    //static unsigned int count8 = 0;
    static float mile = 0;
    //报警延时3s标记
    F_DISP = 1;
    if (alarm_update_flag == 1) {
        if (count6 >= 300) {//
            count6 = 0;
            alarm_update_flag = 0;
        } else {
            count6++;
        }
    } else {
        count6 = 0;
    }

    if (delay_cnt > 0) delay_cnt--; //延时计数器 
    if (delay_5s > 0)  delay_5s--; //延时计数器  

    if (cnt0 >= 4) {//50ms
        cnt0 = 0;
        BCAN_send_mile();
        BCAN_SendCtl();
        if (M_ON_flag && (wake_up3 || wake_up2)) {//若放在main函数里，会导致闪烁频率异常wake_up3置0时，M_ON不会立马置0，因为存在消抖延时
            LED_Logic();
            LED_Out();
            SYSTME_Logic();
        }

        F50ms = 1;
    } else cnt0++;

    if (cnt1 >= 9) {//100ms
        cnt1 = 0;
        F100ms = 1;
        
              if(can2==0){
                 can2=1;
                 //if(MHQ_TIME==0xAA){MHQ_TIME=0;PCAN_send_time();}//时间        
        }else if(can2==1){
                 can2=2;
                 //PCAN_send_yb();//气压 
        }else if(can2==2){
                 can2=3;
                 //PCAN_send_speed();//车速
        }else if(can2==3){
                 can2=0;
               //PCAN_send_mile();//里程  
               //PCAN_send_test();//仪表调试用
        }
                
        //计算累计里程
        //if (pSpeed > 0) {//车速大于0时才累计
        //    mile = mile + (float) (pSpeed / 3.6 * 0.1);
        if (Vspeed/10 > 0) {//车速大于0时才累计
            mile = mile + (float) (Vspeed/10 / 3.6 * 0.1); 
            if (mile >= 100.0) {
                mile = 0.0;
                save_flag = 1;
                if (single_miles >= 9999) single_miles = 0;
                else single_miles++;
                if (total_miles >= 99999999) total_miles = 0;
                else total_miles++;
            }
        }
        //CAN节点故障计时3s
        if (Fcan_count >= CAN_TIME)Fcan_count = CAN_TIME;
        else Fcan_count++;
      //if (Rcan_count >= CAN_TIME)Rcan_count = CAN_TIME;
      //else Rcan_count++;
        if (Mcan_count >= CAN_TIME)Mcan_count = CAN_TIME;
        else Mcan_count++;
        if (Ecan_count >= CAN_TIME)Ecan_count = CAN_TIME;
        else Ecan_count++;
        if (Vcan_count >= CAN_TIME)Vcan_count = CAN_TIME;
        else Vcan_count++;
        if (Bcan_count >= CAN_TIME)Bcan_count = CAN_TIME;
        else Bcan_count++;
        if (Dcan_count >= CAN_TIME)Dcan_count = CAN_TIME;
        else Dcan_count++;
        if (Acan_count >= CAN_TIME)Acan_count = CAN_TIME;
        else Acan_count++;
        if(BAT24V_count>= BAT24_TIME)BAT24V_count= BAT24_TIME;
        else BAT24V_count++;
        if (ECU_TIME   >= CAN_TIME)ECU_TIME   = CAN_TIME;
        else ECU_TIME++;
        if(  QY_count  >= CAN_TIME)QY_count = CAN_TIME;
        else QY_count++;
        //if (Hcan_count >= CAN_TIME)Hcan_count = CAN_TIME;
        //else Hcan_count++;
        //if (Jcan_count >= CAN_TIME)Jcan_count = CAN_TIME;
        //else Jcan_count++;
        //if (Ccan_count >= CAN_TIME)Ccan_count = CAN_TIME;
        //else Ccan_count++;
        //if (Qcan_count >= CAN_TIME)Qcan_count = CAN_TIME;
        //else Qcan_count++;
        //if (Ycan_count >= CAN_TIME)Ycan_count = CAN_TIME;
        //else Ycan_count++;
      
        
        if (cnt4 >= 9) {//1s
            cnt4 = 0;
            F1000ms = 1;
            FLASH_1s = !FLASH_1s;
            //PCAN_send_mile();
            //输出5秒，10分钟循环
            //if (DMC_Rpm * 0.5 < 16300) count7 = 0;
            //else count7++;

            if ((count7 > 0) && (count7 < 6)) {
                F5s = 1;
            } else if (count7 < 605) {
                F5s = 0;
            } else count7 = 0;
            //蜂鸣6秒，10分钟循环报警
            /*if (1) count8 = 0;
            else count8++;
            
            if ((count8 > 0) && (count8 < 6)) {
                F_3 = 1;
            } else if (count8 < 605) {
                F_3 = 0;
            }else count8 = 0; 
             */
        } else cnt4++;
    } else cnt1++;

    if (Fcount >= 39) {//0.4s
        Fcount = 0;
        F400ms = 1;
        FLASH = !FLASH;
    } else Fcount++;

    if (Kcount >= 29) {//300ms
        Kcount = 0;
        F300ms = 1;
        kFLASH = !kFLASH;
    } else Kcount++;

    if (cnt2 >= 49) {//500ms 
        cnt2 = 0;
        F500ms = 1;
        F500ms_LCD = !F500ms_LCD;
    } else cnt2++;

    if (wake_up3) { //ON开关判断//消抖//M_ON在掉电的一瞬间会使上拉电源无效，而M_ON在断电会保持300ms，从而影响开关量采集
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
        key_up = 1; //向上按键
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
        if (lpcnt2 >= 300) {//长按SET按钮
            //lpcnt2 = 0;
            bkey_set = 1; //长按时取消单按键操作
            key_long_set = 1;
        } else lpcnt2++;
    } else {
        lpcnt2 = 0;
    }

    if (KEY_AV && KEY_UP) {
        if (lpcnt1 >= 300) {//组合按钮，长按AV和UP按钮
            lpcnt1 = 0;
            bkey_AV = 1; //长按时取消单按键操作
            bkey_up = 1; //长按时取消单按键操作
            key_duble = 1; //隐含功能按键
        } else lpcnt1++;
    } else {
        lpcnt1 = 0;
    }

    if (KEY_AV && (KEY_UP == 0)) { //长按 2S 清零单里程 长按AV
        if (lpcount >= 200) {
            lpcount = 0;
            single_miles = 0;
            save_flag = 1;
            bkey_AV = 1; //长按时取消单按键操作
            lpcount = 100;
        } else lpcount++;
    } else if (lpcount > 0) lpcount--;

    _T1IF = 0;
}

#define C3_K     512
#define FOUT_DR  TRISFbits.TRISF6
#define FOUT     LATFbits.LATF6
//unsigned char vspeed;    //单位km/h

void TIM5_Init(void) {
    FOUT_DR = 0;
    FOUT = 0;
    T5CON = 0; //1：1 分频   16MHz
    TMR5 = 0;
    PR5 = 15999; //1ms中断一次
    _T5IE = 1;
    T5CONbits.TON = 1;
}

void __attribute__((__interrupt__, auto_psv)) _T5Interrupt(void) { //1ms  
    static unsigned int cnt = 0;
    if (pSpeed > 0) {
        if (cnt < 2) FOUT = 1;
        else FOUT = 0;
        cnt++;

        if (cnt >= (C3_K / pSpeed)) {
            cnt = 0;
        }

    } else {
        cnt = 0;
        FOUT = 0;
    }
    _T5IF = 0;
}

