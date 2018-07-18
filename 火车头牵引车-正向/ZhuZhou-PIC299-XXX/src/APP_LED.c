/*
 * File:   APP_LED.c
 * Author: pnc
 *
 * Created on 2017��7��28��, ����4:49
 */

#include "APP_System.h"

void LED_Logic(void) {
    //ǰ�ſ�ָʾ
    LED1 = IN8;   

    //���ſ�ָʾ
    LED2 = IN9;   
    
    //�յ�ָʾ
    //LED3 = (VCU_Gear==0); 

    //��ת��
    if ((IN4) || WAKE_Danger)
        LED4 = FLASH;
    else LED4 = 0;

    //ǰ����ָʾ
    //LED5 = (VCU_Gear==1); 

    //���ָʾ
    LED6 = (CAN_0x219.BMS_ChrgStsForTbox == 1);
    
    //����ͷ����
    LED7 = (CAN_0x219.BMS_ChrgConnIndLmp == 1);
    
    //��ת���
    if ((IN3) || WAKE_Danger)
        LED8 = FLASH;
    else LED8 = 0;

    //��ѹ1���ź� 0.55MP����
    if (IN22)
        LED9 = 1;
    else
        LED9 = 0;

    //�ܵ�Դָʾ
    LED10 = 0;    

    //��ѹ2 0.55MP����
    if (IN23) 
        LED11 = 1;
    else
        LED11 = 0;

    //SOC����
    LED12 = (CAN_0x213.BMS_SOCLwReqInd);

    //�������
    LED13 = (CAN_0x239.MCU_MtrSysFltSts > 0);

    //�������ϵͳ����
    LED14 = (CAN_0x207.BMS_SysFltLvl > 0);

    //С��
    LED15 = 0; 

    //���ص�ѹ��
    LED16 = (BAT24V_count >= BAT24_TIME); 

    //Զ���
    LED17 = IN7; 

    //��ɲ
    LED18 = IN17; 

    //ǰ���
    LED19 = IN18; 

    //�����
    LED20 = IN19; 

    //������
    //LED21 = (VCU_Gear==2 );

    //�����
    LED22 = IN2; 

    //������
    LED23 = IN16;

    //ɲ��ָʾ
    LED24 = IN24; 


    //������ Ϊ0ʱ�죬Ϊ1ʱ����   
    if (0)
        BUZZ = 0;
    else if (//VCU_OverSpeed              //���ٱ���
            //
            //|| mKL3                     //����Ӧ��������
            //|| mKL4                     //����Ӧ��������
            //|| IN13                     //�¿�����
            //|| (IM_FaultStatus == 0x55) //��Ե����
            //|| (VCU_FaultCode > 0)      //�������ϱ���
            //|| (!mKL12 && KT_SIGNAL)    //������Ӧ����
            //|| fKL8                     //������
             (IN10 && SPEED > 5)     //�����δ��
            ||  IN11                    //ǰ��Ӧ��������
            || (LED1  && SPEED > 5)     //ǰ��δ��
            || (LED2  && SPEED > 5)     //����δ��
            || (CAN_0x7E0.VCU_BusVoltage_Alarm == 2) //��ص�������
            )
        BUZZ = !FLASH_1s;
    else if (LED4                       //��ת��
            || LED8                     //��ת��
            || LED9                     //��ѹ1����
            || LED11                    //��ѹ2����
            //|| !mKL2                    //��ǰĦ��Ƭ
            //|| !mKL4                    //���Ħ��Ƭ
            //|| !mKL6                    //��ǰĦ��Ƭ
            //|| !mKL8                    //�Һ�Ħ��Ƭ
            //|| (mKL10 && SPEED > 5)     //��ȫ��
            //|| (BMS_ChargeGun_Link == 1)//���ڳ�磬��ֹ�г�
            || (SPEED > 69)             //���ٱ���
            )
        BUZZ = !FLASH;
    else BUZZ = 1;

    //���� С�ƿ��رպ� 
    if (1) {
        OC1RS = e_backlight;
    } else {
        OC1RS = 0;
    }

    PO1 = !(SPEED > 5);
    PO2 = !(M_ON);
}

void LED_Danger(void){     //Σ�ձ���״̬
    //F_PO6 = FLASH;
    F_PO7 = FLASH;
    M_PO8 = FLASH;
    M_PO15 = FLASH;
    R_PO5 = FLASH;
    R_PO7 = FLASH;
    LED4 = FLASH; //��ת���
    LED8 = FLASH; //��ת��� 
    BUZZ = !FLASH;
}

void LED_Clear(void){      //LEDȫ���ر�
    alarm_led[0].byte = 0xff;
    alarm_led[1].byte = 0x00;
    alarm_led[2].byte = 0x00;
    alarm_led[3].byte = 0x00;
}

void LED_Enable(void){
    alarm_led[0].byte = 0xC0; //����������
    alarm_led[1].byte = 0xff;
    alarm_led[2].byte = 0xff;
    alarm_led[3].byte = 0xff;
}