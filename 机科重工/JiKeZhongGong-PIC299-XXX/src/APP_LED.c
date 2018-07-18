/*
 * File:   APP_LED.c
 * Author: pnc
 *
 * Created on 2017��7��28��, ����4:49
 */

#include "APP_System.h"

void LED_Logic(void) {
    //LED1 = IN4;   //ǰ�ſ�ָʾ

    //LED2 = IN3;   //���ſ�ָʾ
    //LED3 = (VCU_Gear==0); //�յ�ָʾ

    //��ת��
    if ((IN23) || WAKE_Danger)
        LED4 = FLASH;
    else LED4 = 0;

    //LED5 = (VCU_Gear==1); //ǰ����ָʾ

    //���ָʾ
    LED6 = (Charging == 2);
    //����ͷ����
    LED7 = ChargeGun;
    //��ת���
    if ((IN24) || WAKE_Danger)
        LED8 = FLASH;
    else LED8 = 0;

    //��ѹ1���ź�
    LED9 = IN20;

    LED10 = 1; //�ܵ�Դָʾ   

    //if (ADV[4] < 2500) //��ѹ2
    //    LED11 = 1;
    //else
    //    LED11 = 0;

    LED12 = (BMS_SOC < 10);

    LED13 = (MCU_Control_High_Temp || MCU_Control_Fault); //�������

    LED14 = (BAT_High_Temp 
            || BAT_Low_Temp
            || BAT_Voltage_Diff 
            || BAT_OverCurrent
            || BMS_Fault
            ); //�������ϵͳ����

    LED15 = IN28; //С��

    LED16 = (BAT24V_count >= BAT24_TIME); //���ص�ѹ��

    LED17 = (IN19); //Զ���

    LED18 = (IN22); //��ɲ

    LED19 = (0); //ǰ���

    LED20 = (0); //�����

    LED21 = (IN13); //������

    LED22 = IN18; //�����

    //LED23 = (IN14 && IN31 && M_ON);//������

    LED24 = (IN21); //ɲ��ָʾ


    //������ Ϊ0ʱ�죬Ϊ1ʱ����   
    if ((SPEED > 69))
        BUZZ = 0;
    else if (0)
        BUZZ = !FLASH_1s;
    else if (0)
        BUZZ = !FLASH;
    else BUZZ = 1;

    //���� С�ƿ��رպ� 
    if (LED15) {
        OC1RS = e_backlight;
    } else {
        OC1RS = 0;
    }

    //PO1 = (SPEED > 5);
    //PO2 = !(M_ON && VCU_Gear == 1);
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