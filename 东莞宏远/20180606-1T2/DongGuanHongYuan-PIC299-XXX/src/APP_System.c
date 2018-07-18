#include "APP_System.h"

unsigned char delay_cnt;

DATA_BIT gKEY[5];

unsigned int single_miles = 0;
unsigned long total_miles = 0;

unsigned int SPEED; //�ⲿCAN���㳵��
unsigned int RPM; //�ⲿCAN����ת��

unsigned char PRESS[2]; //��ѹֵ

extern __prog__ const unsigned char __attribute__((space(prog))) BMP_LOGO[];

//ϵͳ��ʼ������

void System_Init(void) {
    ADPCFG = 0xffff; //�ر�AD��     
    LED_Clear(); //��������˲��LED�ͷ�������˸
    LED_Out();
    /*�������ƽӿ� */
    KEY_UP_DR = 1; //   
    KEY_SET_DR = 1; // 
    KEY_AV_DR = 1;

    PWR_CTRL_DR = 1; //�����ѹ�˿ڳ�ʼ��
    PWR_CTRL = 0;

    /*RCONbits.SWDTEN = 1;//���ʹ�ܿ��Ź�
    INT1_Init();
    INT2_Init();  
    BUZZ=0;
    LED_Out();
    __delay_ms(500);
    while(1){//Sleep();Idle();
        PWR_CTRL_DR = 0;
        PWR_CTRL = 1;
        ClrWdt();
        LED1=1;
        LED2=0;
        LED3=0;
        BUZZ=1;
        LED_Out();
        __delay_ms(1500);
        //RCONbits.SWDTEN = 0;//����رտ��Ź�
        Sleep();
        if(RCONbits.WDTO){   
            RCONbits.WDTO = 0;            
            LED1 = 0;
            LED2 = 0;
            LED3 = 1;
            BUZZ = 1;
            LED_Out();
            Sleep();
            RCONbits.SWDTEN = 0;//����رտ��Ź�
        }    
        LED1=0;
        LED2=1;
        LED3=0;
        BUZZ=0;
        LED_Out();
        __delay_ms(1500);
    }*/

    LCD_Init();
    TIMER1_Init();
    delay_cnt = 10; //��ʱ0.1s
    while (delay_cnt > 1) {
        ClrWdt();
        SW_Input(); //���ض�ȡ
    }
    LED_Clear();
    LED_Out();
    POUT_Clear();
    CAN1_Init();
    CAN2_Init();
    INT1_Init();
    INT2_Init();
    TIMER3_Init();
    TIM5_Init(); //Ƶ�������ʼ��
    EEROM_ReadSingleMiles();
    EEROM_ReadTotalMiles();
    EEROM_ReadHMPulse();
    EEROM_ReadBackLight();
    single_miles = e_single_miles;
    total_miles = e_total_miles;
    while (1) {
        ClrWdt();
        LCD_BackLight(0x00);

        if (F50ms) {
            F50ms = 0;
            SW_Input();
        }

        if (WAKE_VBAT) {
            PWR_CTRL_DR = 0;
            PWR_CTRL = 1;
            LED_Logic();
            SYSTME_Logic();
        } else if (WAKE_Danger) {//���Σ�ձ�������
            PWR_CTRL_DR = 0;
            PWR_CTRL = 1;
            LED_Danger();
        } else {
            POUT_Clear();
            LED_Clear();
        }

        LED_Out();

        if (WAKE_ON || WAKE_ACC || WAKE_Charge || WAKE_Start) break; // �����ON�����������˳�

        if (!WAKE_Danger && !WAKE_VBAT) {
            BCAN_SendCtl(); //�ж����BCAN����50ms����һ�Σ�����������������״̬�������Ѿ�����
            __delay_us(500);
            BCAN_SendCtl();
            __delay_us(500);
            BCAN_SendCtl();
            __delay_us(500);
            BCAN_SendCtl();
            __delay_us(500);
            PWR_CTRL_DR = 1; //�رյ�Դ
            PWR_CTRL = 0; //�رյ�Դ 
            PWR_CTRL_DR = 1; //�رյ�Դ
            PWR_CTRL = 0; //�رյ�Դ 
            PWR_CTRL_DR = 1; //�رյ�Դ
            PWR_CTRL = 0; //�رյ�Դ 
        }
    }

    delay_cnt = 100; //����1s��ʱ 
    SM_Init();
    SM_Reset();
    BL_Init(); //�Ǳ�С�Ʊ����ʼ��
    OC1RS = e_backlight; //���±���ֵ
    ADC_Init();
    LCD_Init();
    LED_Enable(); //����������
    LED_Out();
    LCD_DrawImage1BPPZOOM_4(241, 149, BMP_LOGO, WHITE, BLACK);
    LCD_BackLight(7);
    while (delay_cnt > 1); //��ʱ1s
    OC1RS = 0;
    PWR_CTRL_DR = 0; //��Դ���ƽӿ�
    PWR_CTRL = 1; //����MCU��Դ����
    LED_Clear();
    LED_Out();
    SW_Input();   
    DS3231_ReadTime(&timer); //��ȡʱ�� 
    Count_ADR(); //AD�ɼ�
    CAN_DATA_Init(); //CAN���ݳ�ʼ��
    delay_cnt = 100; //����1s��ʱ
    while (delay_cnt > 1);//��ʱ1s
}

//���ת���߼�

void SM_Logic(void) {
    static unsigned char task = 0;
    static unsigned int temp = 0;

    if (CAN_0x18F120F0.MotorSpeed > 12000)
        RPM = CAN_0x18F120F0.MotorSpeed - 12000;
    else 
        RPM = 12000 - CAN_0x18F120F0.MotorSpeed;
    //RPM = 0 * 0.125;

    //SPEED = (unsigned int) (RPM * 0.452 * 2 * 6 * 3.14159 / 100 / 6.17  * e_hm_pulse / 100); //��λ1Km/h
    SPEED = CAN_0x0CF101A7.Speed / 256 * e_hm_pulse / 100;

    sm_new_value[0] = SPEED * 132 / 7;
    if(sm_new_value[0] > 2640)
        sm_new_value[0] = 2640;
    SM_Update_0(); //���ٱ�
    
    sm_new_value[5] = (unsigned int) (RPM * 0.3225);
    if(sm_new_value[5] > 2580){
        sm_new_value[5] = 2580;
    }
    SM_Update_5(); //ת�ٱ� 2580 215��

#if MODE_EV
    if (task == 0) {
        task = 1;
        temp = mADR[0]; //�����ʹ�����
        if (temp < 9)
            sm_new_value[4] = 0;
        else if (temp < 88)
            sm_new_value[4] = (temp - 9)*4.66;
        else if (temp < 124)
            sm_new_value[4] = 368 + (temp - 88)*5.1;
        else if (temp < 155)
            sm_new_value[4] = 552 + (temp - 124)*5.94;
        else if (temp < 184)
            sm_new_value[4] = 736 + (temp - 155)*6.35;
        else if (temp < 200)
            sm_new_value[4] = 920 + (temp - 184)*15.3;
        else
            sm_new_value[4] = 1104;
        /*temp = ADV[3];//��ѹ�ʹ�����
        if (temp < 500)
            sm_new_value[4] = 0;
        else if (temp > 4500)
            sm_new_value[4] = 1104;
        else sm_new_value[4] = (unsigned int) ((temp - 500) * 0.276);*/
        SM_Update_4(); //��ѹ1
    } else if (task == 1) {
        task = 2;
        temp = CAN_0x18F13DF3.SOC * 0.4;
        if (temp <= 0) {
            sm_new_value[3] = 0;
        } else if (temp > 100) {
            sm_new_value[3] = 1080;
        } else {
            sm_new_value[3] = (unsigned int) (10.8 * temp);
        }
        SM_Update_3(); //SOC
    } else if (task == 2) {
        task = 3;
        temp = mADR[1];//�����ʹ�����
        if (temp < 9)
            sm_new_value[2] = 0;
        else if (temp < 88)
            sm_new_value[2] = (temp - 9)*4.66;
        else if (temp < 124)
            sm_new_value[2] = 368 + (temp - 88)*5.1;
        else if (temp < 155)
            sm_new_value[2] = 552 + (temp - 124)*5.94;
        else if (temp < 184)
            sm_new_value[2] = 736 + (temp - 155)*6.35;
        else if (temp < 200)
            sm_new_value[2] = 920 + (temp - 184)*15.3;
        else
            sm_new_value[2] = 1104;
        /*temp = ADV[4];//��ѹ�ʹ�����
        if (temp < 500)
            sm_new_value[2] = 0;
        else if (temp > 4500)
            sm_new_value[2] = 1104;
        else sm_new_value[2] = (unsigned int) ((temp - 500) * 0.276);*/
        SM_Update_2(); //��ѹ2
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
        SM_Update_1(); //���ص�ѹ
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
        SM_Update_4(); //ˮ�±�
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
        SM_Update_3(); //������
    } else if (task == 2) {
        task = 3;
        temp = 0;
        if (temp >= 1000) {
            sm_new_value[2] = 1152;
        }
        sm_new_value[2] = (unsigned int) (temp * 1.152);
        SM_Update_2(); //����ѹ����
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
        SM_Update_1(); //���ص�ѹ
    } else {
        task = 0;
    }
#endif    
}

void SM_Test(void) {
    unsigned int temp5 = 0;
    if (F6s) {
        if (temp5 == 0) {
            temp5 = 2760; //2640;
        } else if (temp5 == 2760) {
            temp5 = 0;
        }
    }

    sm_new_value[0] = temp5;
    sm_new_value[5] = temp5;
    sm_new_value[4] = temp5 * 0.436;
    sm_new_value[2] = temp5 * 0.436;
    sm_new_value[1] = temp5 * 0.436;
    sm_new_value[3] = temp5 * 0.436;
    SM_Update_0(); //���ٱ�
    SM_Update_5(); //ת�ٱ�   �Ƕ�220�� 2640
    SM_Update_4(); //ˮ�±�    
    SM_Update_2(); //����ѹ����
    SM_Update_3(); //������            
    SM_Update_1(); //��ѹ�� 
}

//���ȫ����λ״̬ ����Ϊ0ʱ��ʾ���ȫ����λ

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
    {0, 0, 40, CYCLE, 40, 3}, //400ms��˸���3��
    {0, 0, 50, CYCLE, 50, 5}, //500ms��˸���
    {0, 0, 100, CYCLE, 100, 0}, //1s��˸���
    {0, 0, 300, NONCYCLE}, //�ӳ����3s
    {0, 0, 150, NONCYCLE}, //�ӳ����1.5s
    {0, 0, 10, CYCLE, 10, 5}, //100ms��˸���5��
    {0, 0, 20, CYCLE, 20, 7}, //200ms��˸���7��
    {0, 0, 9000, NONCYCLE}, //�ӳ����90s
    {}    
};
//ע����˸�����Ч����,��÷����ж���, .Status�ǻص�״̬�������״̬
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

//�ӳ���Ч���
_Delay_Out delay_out[] = {
    {500},
    {1000},
    {2000},
    {5000},
    {}
};

#if 0 
int Interval_Run(unsigned char condition,  //��������
        unsigned int out_time,              //�������㣬����ʱ�� T = out_time * ������ʱ��
        CYCLE_EN cycle_en,                  //�Ƿ�ѭ��ִ��
        unsigned int stop_time,             //ѭ��ִ��ʱ����Ъʱ�� T = stop_time * ������ʱ��
        unsigned char cycle_times           //ѭ��������0Ϊ����ѭ��
        ) {
    static unsigned int temp = 0;
    static unsigned char times = 0;
#if 0    
    if (condition) {//���������㣬����ֹͣ����
        temp = temp > 60000 ? 60000 : temp + 1; //�������ޣ���ֹ���
    } else {
        temp = 0;
    }
    
    if (condition) {//���������㣬����ѭ������ֹͣ����
        temp = temp > 60000 ? 60000 : temp + 1; //�������ޣ���ֹ���
    } else if(temp > 0 && temp < (out_time + stop_time) * 100){
        temp = temp > 60000 ? 60000 : temp + 1
    } else {
        temp = 0;
    }
    
    if (condition && ((times < cycle_times) || (!cycle_times))) {//���������㣬����ѭ��������ֹͣ���У��������㣬����ָ���Ĵ�����һֱѭ������
        temp = temp > 60000 ? 60000 : temp + 1; //�������ޣ���ֹ���
    } else if (temp > 0 && temp < (out_time + stop_time) * 100) {        
        temp = temp > 60000 ? 60000 : temp + 1;
    } else {
        temp = 0;
        if (!condition) {
            times = 0;
        }
    }
#endif    
    if (condition && ((times < cycle_times) || (!cycle_times))) {//���������㣬ָ��ѭ������������ֹͣ���У��������㣬����ָ���Ĵ�����һֱѭ������
        temp = temp > 60000 ? 60000 : temp + 1; //�������ޣ���ֹ���
    } else if (temp > 0 && temp < (out_time + stop_time)) {        
        temp = temp > 60000 ? 60000 : temp + 1;
    } else if ((times > 0) && (times < cycle_times)){//�ı������ cycle_times ��������ֹͣ����ǰѭ������
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

//��������Ч������һ��
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

//�½�����Ч������һ��
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