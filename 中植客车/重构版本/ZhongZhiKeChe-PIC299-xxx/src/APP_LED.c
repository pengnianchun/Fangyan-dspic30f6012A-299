/*
 * File:   APP_LED.c
 * Author: pnc
 *
 * Created on 2017��7��28��, ����4:49
 */

#include "APP_System.h"

void LED_Logic(void) {
    LED1 = IN4; //ǰ�ſ�ָʾ

    LED2 = IN3; //���ſ�ָʾ
    
    //LED3 = (DMC_Gear==0 || DMC_Gear==3); //�յ�ָʾ

    //��ת��
    if (IN1 || wake_up1)
        LED4 = FLASH;
    else LED4 = 0;

    //LED5 = (DMC_Gear==1); //ǰ����ָʾ
    
    LED6 = BMS_Charge_Status.bit2; //���״̬

    LED7 = BMS_Charge_Status.bit1; //���ǹ����
    //��ת���
    if (IN5 || wake_up1)
        LED8 = FLASH;
    else LED8 = 0;

    LED9 = IN11; //��ѹ1���ź�

    LED10 = 1; //�ܵ�Դָʾ   

    LED11 = IN12; //��ѹ2���ź�

    LED12 = (BMS_Warn_Message[0].bit5 //SOC����
            || BMS_Warn_Message[0].bit8
            || BMS_Warn_Message[1].bit1); 

    LED13 = (MCU_Warn_Number > 0 && MCU_Warn_Number < 252); //�������

    LED14 = (BMS_Fault_Level == 1      //�������ϵͳ����
            || BMS_Fault_Level == 2
            || BMS_Fault_Level == 3);
           /*((((BMS_Status_Flag1 & 0x03) == 1) || ((BMS_Status_Flag1 & 0x03) == 2))
            || (((BMS_Status_Flag1 >> 2) & 0x03) == 1) || (((BMS_Status_Flag1 >> 2) & 0x03) == 2)
            || (((BMS_Status_Flag1 >> 4) & 0x03) == 1) || (((BMS_Status_Flag1 >> 4) & 0x03) == 2)
            || (((BMS_Status_Flag1 >> 6) & 0x03) == 1) || (((BMS_Status_Flag1 >> 6) & 0x03) == 2)
            || ((BMS_Status_Flag2 & 0x03) == 1) || ((BMS_Status_Flag2 & 0x03) == 2)
            || (((BMS_Status_Flag2 >> 2) & 0x03) == 1) || (((BMS_Status_Flag2 >> 2) & 0x03) == 2)
            || (((BMS_Status_Flag2 >> 4) & 0x03) == 1) || (((BMS_Status_Flag2 >> 4) & 0x03) == 2)
            || (((BMS_Status_Flag2 >> 6) & 0x03) == 1) || (((BMS_Status_Flag2 >> 6) & 0x03) == 2))
           */
    LED15 = IN6; //С��

    LED16 = (BAT24V_count == BAT24_TIME); //���ص�ѹ��

    LED17 = (IN7 && !IN8); //Զ���

    LED18 = (IN26); //��ɲ

    LED19 = (IN9 && IN6); //ǰ���

    LED20 = (IN9 && IN10 && IN6); //�����

    //LED21 = (DMC_Gear==2 /*&& M_ON*/);//������

    LED22 = (IN8 && IN6 && IN7); //�����

    //LED23 = (IN14 && IN31 && M_ON);//������

    LED24 = (fKL6); //ɲ��ָʾ


    //������ Ϊ0ʱ�죬Ϊ1ʱ����   
    if (SPEED > 69)
        BUZZ = 0;
    else if (LED13 || LED14)
        BUZZ = !FLASH_1s;
    else if (IN1 || IN5 || wake_up1)
        BUZZ = !FLASH;
    else BUZZ = 1;
    
    //���� С�ƿ��رպ� 
    if (IN6) {
        OC1RS = e_backlight;
    } else {
        OC1RS = 0;
    }
    
    PO1 = 0;
    PO2 = 0;
}

void LED_Danger(void){     //Σ�ձ���״̬
    F_PO6 = FLASH;
    F_PO7 = FLASH;
    M_PO2 = FLASH;
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