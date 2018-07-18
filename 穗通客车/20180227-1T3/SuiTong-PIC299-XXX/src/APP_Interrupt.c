/*
 * File:   APP_Interrupt.c
 * Author: pnc
 *
 * Created on 2017��7��28��, ����5:24
 */

#include "APP_System.h"

unsigned int Fcan_count = 0; //ǰ��ģ��CAN
unsigned int Rcan_count = 0; //����ģ��CAN
unsigned int Mcan_count = 0; //�в�ģ��CAN

unsigned int Ecan_count = 0; //������ECUģ��CAN
unsigned int Vcan_count = 0; //����������VCUģ��CAN
unsigned int Bcan_count = 0; //��ع�����BMSģ��CAN
unsigned int Dcan_count = 0; //ת������DC/ACģ��CAN
unsigned int Acan_count = 0; //�յ�ACģ��CAN

unsigned int BAT24V_count = 0; //���ص�ѹ������ʱ

unsigned int NodeCount[NODE_NUMBER] = {}; //�ڵ㳬ʱ����
/**************************************************************************************
 * FunctionName   : KeyProcess()
 * Description    : ��ť����
 * EntryParameter : None
 * ReturnValue    : None
 **************************************************************************************/
static void KeyProcess(void) {
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
static void TaskRemarks(void) {
    unsigned char i;
    for (i = 0; TaskComps[i].TaskHook != NULL; i++) // �������ʱ�䴦��
    {
        if (TaskComps[i].Timer) // ʱ�䲻Ϊ0
        {
            TaskComps[i].Timer--; // ��ȥһ������
        }
        if (TaskComps[i].Timer == 0) // ʱ�������
        {
            if (TaskComps[i].Run == 0) {
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
static void TaskProcess(void) {
    unsigned char i = 0;
    static unsigned char Flag = 0, poll_time = 0;
    //������,����������ȡ����poll_time * ����ʱ����
    for (i = 0; TaskComps[i].TaskHook != NULL; i++) { // �������ʱ�䴦��
        if (TaskComps[i].Run && Flag) // ʱ�䲻Ϊ0
        {
            TaskComps[i].TaskHook(); // ��������
            TaskComps[i].Run = 0; // ��־��0 
            Flag = 0;
        }
    }

    if (poll_time >= 0) {
        poll_time = 0;
        Flag = 1;
    } else if (!Flag) {
        poll_time++;
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

static void Interval_Run(void) {
    //static unsigned int temp = 0;
    //static unsigned char times = 0;
    unsigned char i = 0;
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
    for (i = 0; Flash[i].Out_time != 0; i++) {
        if (Flash[i].Condition && ((Flash[i].Run_frequency < Flash[i].Cycle_times) || (!Flash[i].Cycle_times))) {//���������㣬ָ��ѭ������������ֹͣ���У��������㣬����ָ���Ĵ�����һֱѭ������
            Flash[i].Run_time = Flash[i].Run_time > 60000 ? 60000 : Flash[i].Run_time + 1; //�������ޣ���ֹ���
        } else if (Flash[i].Run_time > 0 && Flash[i].Run_time < (Flash[i].Out_time + Flash[i].Stop_time)) {
            Flash[i].Run_time = Flash[i].Run_time > 60000 ? 60000 : Flash[i].Run_time + 1;
        } else if ((Flash[i].Run_frequency > 0) && (Flash[i].Run_frequency < Flash[i].Cycle_times)) {//�ı������ cycle_times ��������ֹͣ����ǰѭ������
            Flash[i].Run_time = Flash[i].Run_time > 60000 ? 60000 : Flash[i].Run_time + 1;
        } else {
            Flash[i].Run_time = 0;
            if (!Flash[i].Condition) {
                Flash[i].Run_frequency = 0;
            }
        }

        if (Flash[i].Run_time > 0 && Flash[i].Run_time < Flash[i].Out_time) {
            Flash[i].Status = 1;
        } else if (!Flash[i].Cycle_en) {
            Flash[i].Status = 0;
        } else if (Flash[i].Run_time < (Flash[i].Out_time + Flash[i].Stop_time)) {
            Flash[i].Status = 0;
        } else {
            Flash[i].Run_time = 0;
            Flash[i].Run_frequency++;
            Flash[i].Status = 0;
        }
    }
}

static void CAN_DATA_Lost(void) {
    if (NodeCount[0] == CAN_TIME) {
        CAN_0x0C03A1A7.MotoCurrent = 10000;
        CAN_0x0C03A1A7.MotoSpeed = 20000;
        CAN_0x0C03A1A7.MotoVoltage = 10000;
        CAN_0x0C03A1A7.MotorTemperature = 40;
        CAN_0x0C03A1A7.MotorTemperature_Controller = 40;

        CAN_0x0C08A1A7.MotoSpeed = 20000;
        CAN_0x0C08A1A7.MotoTorque = 20000;
    }
    if (NodeCount[1] == CAN_TIME) {
        CAN_0x1818D0F3.BMS_A = 10000;
        CAN_0x1818D0F3.BMS_V = 10000;

        CAN_0x1819D0F3.BMS_A_charge = 10000;
        CAN_0x1819D0F3.BMS_A_discharge = 10000;
        CAN_0x1819D0F3.BMS_T_H = 40;
        CAN_0x1819D0F3.BMS_V_average = 10000;

        CAN_0x181AD0F3.Battery_single_H = 10000;
        CAN_0x181AD0F3.Battery_single_L = 10000;
        CAN_0x181BD0F3.BAT_Min_Cell_Temperature = 40;

        CAN_0x181CD0F3.ChargeSocketTemp1 = 40;
        CAN_0x181CD0F3.ChargeSocketTemp2 = 40;
    }
    if (NodeCount[2] == CAN_TIME) {
        CAN_0x1801A79A.DCDC_Temp = 40;

        CAN_0x1801A79D.AIRDCAC_Temp = 40;

        CAN_0x1801A79B.OILDCAC_Temp = 40;
    }
}

void __attribute__((__interrupt__, auto_psv)) _T1Interrupt(void) {//10ms�ж�һ��
    static unsigned int cnt0 = 0;
    static unsigned int cnt1 = 3;
    static unsigned int cnt2 = 7;
    static unsigned int cnt3 = 9;
    static unsigned int cnt4 = 0;
    static unsigned int cnt6 = 0;    
    static unsigned int Fcount = 0, Kcount = 0;
    static unsigned int count6 = 0;
    static float mile = 0;
    unsigned char i;
    //static unsigned char task1 = 0;
    //������ʱ3s���
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
   //�����Ǵ���
    TaskRemarks();
    
    //��ť����
    KeyProcess();
    
    //��Ъ���״̬
    Interval_Run();

    if (delay_cnt > 0) delay_cnt--; //��ʱ������    

    if (cnt0 >= 4) {//50ms
        cnt0 = 0;
        BCAN_send_mile();
        BCAN_SendCtl();
        if (M_ON_flag && (WAKE_ON || WAKE_ACC || WAKE_Charge || WAKE_Start)) {//wake_up3��0ʱ��M_ON����������0����Ϊ����������ʱ
            LED_Logic();
            LED_Out();
            SYSTME_Logic();
        }
        F50ms = 1;
    } else cnt0++;

    if (cnt1 >= 9) {//100ms
        cnt1 = 0;
        F100ms = 1;          
        //�����ۼ����
        if (SPEED > 0) {//���ٴ���0ʱ���ۼ�
            mile = mile + (float) (SPEED / 3.6 * 0.1);
            if (mile >= 100.0) {
                mile = 0.0;
                save_flag = 1;
                if (single_miles >= 9999) single_miles = 0;
                else single_miles++;
                if (total_miles >= 9999999) total_miles = 0;
                else total_miles++;
            }
        }
        //CAN�ڵ���ϼ�ʱ3s
        if (Fcan_count >= CAN_TIME)Fcan_count = CAN_TIME;
        else Fcan_count++;
        if (Rcan_count >= CAN_TIME)Rcan_count = CAN_TIME;
        else Rcan_count++;
        if (Mcan_count >= CAN_TIME)Mcan_count = CAN_TIME;
        else Mcan_count++;
        BAT24V_count = BAT24V_count >= BAT24_TIME ? BAT24_TIME : BAT24V_count + 1;
        for (i = 0; i < NODE_NUMBER; i++) {
            NodeCount[i] = NodeCount[i] >= CAN_TIME ? CAN_TIME : NodeCount[i] + 1;
            if (NodeCount[i] == CAN_TIME) {
                //CAN_DATA_Lost();
            }
        }      

        if (cnt4 >= 9) {//1s
            cnt4 = 0;
            F1000ms = 1;
            FLASH_1s = !FLASH_1s;            
            if(cnt6 >= 4){//5��
                cnt6 = 0;
            }else cnt6++;
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

    if (wake_up3) { //ON�����ж�//����//M_ON�ڵ����һ˲���ʹ������Դ��Ч����M_ON�ڶϵ�ᱣ��300ms���Ӷ�Ӱ�쿪�����ɼ�
        if (cnt3 > 30) M_ON = 1;
        else cnt3++;
    } else {
        if (cnt3 < 1) M_ON = 0;
        else cnt3--;
    }
        
    _T1IF = 0;
}

void TIM5_Init(void) {
    FOUT_DR = 0;
    FOUT = 0;
    T5CON = 0; //1��1 ��Ƶ   16MHz
    TMR5 = 0;
    PR5 = 15999; //1ms�ж�һ��
    _T5IF = 0;
    _T5IE = 1;
    T5CONbits.TON = 1;
}

void __attribute__((__interrupt__, auto_psv)) _T5Interrupt(void) { //1ms ������Ƶ��500HZ
    static unsigned int cnt = 0, out_K = 0;
    out_K = 721; // ����ϵ��K = 1000 * 3600/����������P
    if (SPEED > 0) {
        //if (cnt < 2) FOUT = 1;//C3���
        if (cnt < (out_K / SPEED) / 2) FOUT = 1; //ռ�ձ�1:1���
        else FOUT = 0;
        cnt++;

        //C3����ź� V = 255 * 2 / T
        /*if (cnt >= (C3_K / SPEED)) {
            cnt = 0;
        }*/
        // ����T(��) = 3600/����������P(��)/�ٶȣ�KM/H��
        // ����ϵ��K = 1000 * 3600/����������P
        if (cnt >= (out_K / SPEED)) {
            cnt = 0;
        }

    } else {
        cnt = 0;
        FOUT = 0;
    }
    //CAN������
    TaskProcess();      
    
    _T5IF = 0;
}