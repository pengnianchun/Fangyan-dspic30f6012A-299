/*
 * File:   APP_LED.c
 * Author: pnc
 *
 * Created on 2017��7��28��, ����4:49
 */

#include "APP_System.h"

void LED_Logic(void) {
    LED1 = IN4;   //ǰ�ſ�ָʾ

    LED2 = IN3;   //���ſ�ָʾ
    //LED3 = (VCU_Gear==0); //�յ�ָʾ

    //��ת��
    if ((IN1) || WAKE_Danger)
        LED4 = FLASH;
    else LED4 = 0;

    //LED5 = (VCU_Gear==1); //ǰ����ָʾ

    //���ָʾ
    LED6 = (ChargeStatus == 3);
    
    //����ͷ����
    LED7 = (No27 == 3);
    
    //��ת���
    if ((IN5) || WAKE_Danger)
        LED8 = FLASH;
    else LED8 = 0;

    if (ADV[4] < 2300)//��ѹ1���ź� 0.6MP����
        LED9 = 1;
    else
        LED9 = 0;

    LED10 = 1; //�ܵ�Դָʾ   

    if (ADV[3] < 2300) //��ѹ2 0.6MP����
        LED11 = 1;
    else
        LED11 = 0;

    //SOC����
    LED12 = (CAN_0x18EF5AEF.No23 || CAN_0x18EF5AEF.No26 || CAN_0x18EF5AEF.No27);

    //�������
    LED13 = (CAN_0x18EF5AEF.No2 || CAN_0x18EF5AEF.No3);

    //�������ϵͳ����
    LED14 = (CAN_0x18EF5AEF.No1 > 0);

    LED15 = (IN6); //С��

    LED16 = (BAT24V_count >= BAT24_TIME); //���ص�ѹ��

    LED17 = (M_ON && IN7); //Զ���

    LED18 = (IN26); //��ɲ

    LED19 = (M_ON && IN6 && IN9); //ǰ���

    LED20 = (M_ON && IN6 && IN9 && IN10); //�����

    LED21 = (CAN_0x18EF4AEF.EV_Gear == 13); //������

    LED22 = (M_ON && IN8); //�����

    //LED23 = (IN14 && IN31 && M_ON);//������

    LED24 =  (M_ON && fKL6); //ɲ��ָʾ


    //������ Ϊ0ʱ�죬Ϊ1ʱ����   
    if (mKL2 || fKL15)
        BUZZ = 0;
    else if ((mKH1 && SPEED > 5)       //�����δ��
            || (LED1  && SPEED > 5)       //ǰ��δ��
            || (LED2  && SPEED > 5)       //����δ��
            )
        BUZZ = !FLASH_1s;
    else if (LED4                       //��ת��
            || LED8                     //��ת��
            || LED9                     //��ѹ1����
            || LED11                    //��ѹ2����
            || !fKL4                    //��ǰĦ��Ƭ
            || !fKL1                    //���Ħ��Ƭ
            || !fKL5                    //��ǰĦ��Ƭ
            || !fKL3                    //�Һ�Ħ��Ƭ
            || (IN30 && SPEED > 5)      //��ȫ��
            //|| (BMS_ChargeGun_Link == 3)//���ڳ�磬��ֹ�г�
            || (SPEED > 69)             //���ٱ���
            )
        BUZZ = !FLASH;
    else BUZZ = 1;

    //���� С�ƿ��رպ� 
    if (LED15) {
        OC1RS = e_backlight;
    } else {
        OC1RS = 0;
    }

    //PO1 = !(SPEED > 5);
    //PO2 = !(M_ON && VCU_Gear == 1);
}

void LED_Danger(void){     //Σ�ձ���״̬
    F_PO6 = FLASH;
    F_PO7 = FLASH;
    M_PO6 = FLASH;
    M_PO7 = FLASH;
    R_PO6 = FLASH;
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