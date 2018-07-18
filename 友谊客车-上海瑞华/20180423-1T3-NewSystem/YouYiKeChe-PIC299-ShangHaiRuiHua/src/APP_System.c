#include "APP_System.h"

unsigned char delay_cnt;

DATA_BIT gKEY[5];

unsigned int single_miles = 0;
unsigned long total_miles = 0;

unsigned int SPEED; //�ⲿCAN���㳵��
unsigned int RPM; //�ⲿCAN����ת��

unsigned char PRESS[2]; //��ѹֵ

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
    while (1) {
        ClrWdt();
        LCD_BackLight(0x00);

        if (F50ms) {
            F50ms = 0;
            SW_Input();
        }

        if (WAKE_Danger) {//���Σ�ձ�������
            PWR_CTRL_DR = 0;
            PWR_CTRL = 1;
            LED_Danger();
        } else {
            POUT_Clear();
            LED_Clear();
        }

        LED_Out();

        if (WAKE_ON || WAKE_ACC || WAKE_Charge || WAKE_Start) break; // �����ON�����������˳�

        if (!WAKE_Danger) {
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
    OC1RS = e_backlight; //���±���ֵ
    ADC_Init();
    LCD_Init();
    LED_Enable(); //����������
    LED_Out();
    while (delay_cnt > 1); //��ʱ1s
    OC1RS = 0;
    PWR_CTRL_DR = 0; //��Դ���ƽӿ�
    PWR_CTRL = 1; //����MCU��Դ����
    LED_Clear();
    LED_Out();
    SW_Input();
    LCD_BackLight(7);
    DS3231_ReadTime(&timer); //��ȡʱ�� 
    Count_ADR(); //AD�ɼ�
    CAN_DATA_Init(); //CAN���ݳ�ʼ��
}

//���ת���߼�

void SM_Logic(void) {
    static unsigned char task = 0;
    static unsigned int temp = 0;

    if (CAN_0x08019F80.VCU_MotorSpeed > 8000)
        RPM = CAN_0x08019F80.VCU_MotorSpeed - 8000;
    else 
        RPM = 8000 - CAN_0x08019F80.VCU_MotorSpeed;
    //RPM = 0 * 0.125;

    //SPEED = (unsigned int) (RPM * 0.452 * 2 * 6 * 3.14159 / 100 / 6.17  * e_hm_pulse / 100); //��λ1Km/h
    SPEED = CAN_0x08029F80.Speed * e_hm_pulse / 100;
    //if (SPEED >= 70) Speed_lim_mode = 0x01; //����ģʽ
    //else Speed_lim_mode = 0x03;
    sm_new_value[0] = SPEED * 132 / 7;
    SM_Update_0(); //���ٱ�
    
    sm_new_value[5] = (unsigned int) (RPM * 0.3225);
    SM_Update_5(); //ת�ٱ� 2580 215��

#if MODE_EV
    if (task == 0) {
        task = 1;
        /*temp = ADR[3];//�����ʹ�����
        if (temp < 10)
            sm_new_value[4] = 0;
        else if (temp < 79)
            sm_new_value[4] = (temp - 10)*5;
        else if (temp < 116)
            sm_new_value[4] = 345 + (temp - 79)*9.34;
        else if (temp < 149)
            sm_new_value[4] = 690 + (temp - 116)*7;
        else if (temp < 184)
            sm_new_value[4] = 921 + (temp - 149)*6.6;
        else
            sm_new_value[4] = 1152;*/
        temp = ADV[3];//��ѹ�ʹ�����
        if (temp < 500)
            sm_new_value[4] = 0;
        else if (temp > 4500)
            sm_new_value[4] = 1104;
        else sm_new_value[4] = (unsigned int) ((temp - 500) * 0.276);
        SM_Update_4(); //��ѹ1
    } else if (task == 1) {
        task = 2;
        temp = CAN_0x10F8159E.BMS_SOC;
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
        /*temp = ADR[4];//�����ʹ�����
        if (temp < 10)
            sm_new_value[2] = 0;
        else if (temp < 79)
            sm_new_value[2] = (temp - 10)*5;
        else if (temp < 116)
            sm_new_value[2] = 345 + (temp - 79)*9.34;
        else if (temp < 149)
            sm_new_value[2] = 690 + (temp - 116)*7;
        else if (temp < 184)
            sm_new_value[2] = 921 + (temp - 149)*6.6;
        else
            sm_new_value[2] = 1152;*/
        temp = ADV[4];//��ѹ�ʹ�����
        if (temp < 500)
            sm_new_value[2] = 0;
        else if (temp > 4500)
            sm_new_value[2] = 1104;
        else sm_new_value[2] = (unsigned int) ((temp - 500) * 0.276);
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
    {0, 0, 40, CYCLE, 40, 3},           //400ms��˸���3��
    {0, 0, 50, CYCLE, 50, 0},           //500ms��˸���
    {0, 0, 100, CYCLE, 100, 0},         //1s��˸���
    {0, 0, 300, NONCYCLE},              //3s��˸���1��
    {0, 0, 150, NONCYCLE},              //1.5s��˸���1��
    {0, 0, 10, CYCLE, 10, 5},           //100ms��˸���5��
    {0, 0, 20, CYCLE, 20, 7},           //200ms��˸���7��
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