#include "APP_System.h"

unsigned char delay_cnt;

DATA_BIT gKEY[5];

unsigned int single_miles = 0;
unsigned long total_miles = 0;

unsigned int SPEED; //�ⲿCAN���㳵��
unsigned int RPM;   //�ⲿCAN����ת��

unsigned char dm_hcu_display[32]; //��������
unsigned char dm_tcu_display[32];


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
    Count_ADR();//AD�ɼ�
    CAN_DATA_Init();
}

//���ת���߼�
void SM_Logic(void) {
    static unsigned char task = 0;
    static unsigned int  temp = 0;
    
    if (CAN_0x18EF4EEF.MCU_RPM > 20000)
        RPM = CAN_0x18EF4EEF.MCU_RPM - 20000;
    else RPM = 20000 - CAN_0x18EF4EEF.MCU_RPM;
    //RPM = MCU_RPM * 50;
    
    //SPEED = (unsigned int) (RPM * 0.446 * 2 * 60 * 3.14159 / 1000 / 5.571  * e_hm_pulse / 100); //��λ1Km/h
    SPEED = CAN_0x18EF4AEF.EV_Speed / 10 * e_hm_pulse / 100;
    
    sm_new_value[0] = (unsigned int) (SPEED * 132 / 7);
    SM_Update_0(); //

    sm_new_value[5] = (unsigned int) (RPM * 0.33);
    SM_Update_5(); //2640

    if (task == 0) {
        task = 1;
        temp = ADV[3];
        if (temp < 500)
            sm_new_value[4] = 0;
        else if (temp > 4500)
            sm_new_value[4] = 1152;
        else
            sm_new_value[4] = (unsigned int) ((temp - 500) * 0.288);
        SM_Update_4(); //��ѹ1
    } else if (task == 1) {
        task = 2;
        temp = CAN_0x18EF4CEF.BMS_SOC;
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
        temp = ADV[4];
        if (temp < 500)
            sm_new_value[2] = 0;
        else if (temp > 4500)
            sm_new_value[2] = 1152;
        else
            sm_new_value[2] = (unsigned int) ((temp - 500) * 0.288);
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
        /*if (temp < 180) { 
            sm_new_value[1] = 0;
        } else if ((temp >= 180)&&(temp < 240)) {
            sm_new_value[1] = (unsigned int) (6.667 * (temp - 180));
        } else if ((temp >= 240)&&(temp <= 320)) {
            sm_new_value[1] = (unsigned int) (10 * (temp - 240)) + 400;
        } else {
            sm_new_value[1] = 1200;
        }*/
        SM_Update_1();//���ص�ѹ
    } else {
        task = 0;
    }
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

//��ʱ��������
char Count_Time(unsigned char condition, //��������
        unsigned int  out_time,           //�������㣬����ʱ��
        CYCLE_EN cycle_en,                //�Ƿ�ѭ��ִ��
        unsigned int  stop_time           //ѭ��ִ��ʱ����Ъʱ��
        ) { 
    static unsigned int temp = 0;
    if (condition) {
        temp = temp > 60000 ? 60000 : temp + 1; //�������ޣ���ֹ���
    } else {
        temp = 0;
    }

    if (temp > 0 && temp < out_time * 100) {
        return 1;
    } else if (!cycle_en) {
        return 0;
    } else if (temp < (out_time + stop_time) * 100) {
        return 0;
    } else {
        temp = 0;
        return 0;     
    }
}

/**************************************************************************************
    * FunctionName   : KeyProcess()
    * Description    : ��ť����
    * EntryParameter : None
    * ReturnValue    : None
    **************************************************************************************/
void KeyProcess(void){
    static unsigned int lpcnt2 = 0, lpcnt1 = 0, lpcount = 0;
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
        key_up = 1; //���ϰ���
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
        if (lpcnt2 >= 300) {//����SET��ť
            lpcnt2 = 0;
            bkey_set = 1; //����ʱȡ������������
            key_long_set = 1;
        } else lpcnt2++;
    } else {
        lpcnt2 = 0;
    }

    if (KEY_AV && KEY_UP) {
        if (lpcnt1 >= 300) {//��ϰ�ť������AV��UP��ť
            lpcnt1 = 0;
            bkey_AV = 1; //����ʱȡ������������
            bkey_up = 1; //����ʱȡ������������
            key_duble = 1; //�������ܰ���
        } else lpcnt1++;
    } else {
        lpcnt1 = 0;
    }

    if (KEY_AV && (KEY_UP == 0)) { //���� 2S ���㵥��� ����AV
        if (lpcount >= 200) {
            single_miles = 0;
            save_flag = 1;
            bkey_AV = 1; //����ʱȡ������������
            lpcount = 100;
        } else lpcount++;
    } else if (lpcount > 0) lpcount--;
}

/**************************************************************************************
    * FunctionName   : TaskRemarks()
    * Description    : �����־����
    * EntryParameter : None
    * ReturnValue    : None
    **************************************************************************************/
void TaskRemarks(void) {
    unsigned char i;
    for (i = 0; TaskComps[i].TaskHook != NULL; i++) // �������ʱ�䴦��
    {
        if (TaskComps[i].Timer) // ʱ�䲻Ϊ0
        {
            TaskComps[i].Timer--; // ��ȥһ������
            if (TaskComps[i].Timer == 0) // ʱ�������
            {
                TaskComps[i].Timer = TaskComps[i].ItvTime; // �ָ���ʱ��ֵ��������һ��
                TaskComps[i].Run = 1; // �����������
            }
        }
    }
}

/**************************************************************************************
 * FunctionName   : TaskProcess()
 * Description    : ������
 * EntryParameter : None
 * ReturnValue    : None
 **************************************************************************************/
void TaskProcess(void) {
    unsigned char i = 0;   
    //������,����������ȡ����F_CANSend
    for (i = 0; TaskComps[i].TaskHook != NULL; i++) { // �������ʱ�䴦��
        if (TaskComps[i].Run && F_CANSend) // ʱ�䲻Ϊ0
        {
            TaskComps[i].TaskHook(); // ��������
            TaskComps[i].Run = 0; // ��־��0 
            F_CANSend = 0;
        }
    }

    //������ÿ��ѭ��ִֻ��һ������
    /*if (TaskComps[i].TaskHook != NULL) // �������ʱ�䴦��
    {
        if (TaskComps[i].Run) // ʱ�䲻Ϊ0
        {
            TaskComps[i].TaskHook(); // ��������
            TaskComps[i].Run = 0; // ��־��0 
        }
        i++;
    }
    if(TaskComps[i].TaskHook == NULL){
        i = 0;
    }*/
}

_FLASH Flash[] = {
    {0, 0, 40, CYCLE, 40, 3},         //400ms��˸���3��
    {0, 0, 50, CYCLE, 50, 0},         //500ms��˸���
    {0, 0, 100, CYCLE, 100, 0},       //1s��˸���
    {0, 0, 500, CYCLE, 60000, 0},     //���3�룬ͣ10����
    {}    
};
//ע����˸�����Ч����,��÷����ж���
void Interval_Status(unsigned int condition, Flash_Number x) {
    if (x < Flash_Null) {
        if (condition) {
            Flash[x].Condition = 1;
        } else {
            Flash[x].Condition = 0;
        }
    }
}