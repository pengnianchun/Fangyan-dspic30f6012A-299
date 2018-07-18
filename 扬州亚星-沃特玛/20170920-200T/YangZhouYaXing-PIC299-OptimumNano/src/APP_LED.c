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
    /*if ((IN1) || WAKE_Danger)
        LED4 = FLASH;
    else LED4 = 0;*/

    //LED5 = (VCU_Gear==1); //ǰ����ָʾ

    //���ָʾ
    LED6 = (BMS_Chargeing == 1);
    //����ͷ����
    LED7 = (wake_up2 || (BMS_ChargeGun_Link == 1));
    //��ת���
    /*if ((IN5) || WAKE_Danger)
        LED8 = FLASH;
    else LED8 = 0;*/

    if (ADV[3] < 1875)//��ѹ1���ź� 0.55MP����
        LED9 = 1;
    else
        LED9 = 0;

    LED10 = 1; //�ܵ�Դָʾ   

    if (ADV[4] < 1875) //��ѹ2 0.55MP����
        LED11 = 1;
    else
        LED11 = 0;

    //SOC����
    LED12 = (BMS_1LevelFault == 16
            || BMS_2LevelFault == 16
            || BMS_3LevelFault == 4
            || BMS_3LevelFault == 7
            );

    //�������
    LED13 = ((VCU_FaultCode >= 110 &&  VCU_FaultCode <= 139) 
            || (VCU_FaultCode >= 201 &&  VCU_FaultCode <= 209)
            );

    //�������ϵͳ����
    LED14 = (BMS_Warn_Type == 1 
            || BMS_Warn_Type ==2
            || BMS_Warn_Type ==3
            );

    LED15 = IN6; //С��

    LED16 = (BAT24V_count >= BAT24_TIME); //���ص�ѹ��

    LED17 = (IN7); //Զ���

    LED18 = (IN18); //��ɲ

    LED19 = (IN9); //ǰ���

    LED20 = (IN10); //�����

    //LED21 = (VCU_Gear==2 );//������

    LED22 = IN8; //�����

    //LED23 = (IN14 && IN31 && M_ON);//������

    LED24 = (IN11); //ɲ��ָʾ


    //������ Ϊ0ʱ�죬Ϊ1ʱ����   
    if (0)
        BUZZ = 0;
    else if (VCU_OverSpeed              //���ٱ���
            || IN26                     //Ӧ��������
            //|| IN19                     //�¿�����
            || IN20                     //������
            || (IM_FaultStatus == 0x55) //��Ե����
            || (VCU_FaultCode > 0)      //�������ϱ���
            )
        BUZZ = !FLASH_1s;
    else if (LED9                       //ǰ��ѹ����
            || LED11                    //����ѹ����
            || (LED1 && SPEED > 5)      //ǰ��δ��
            || (LED2 && SPEED > 5)      //ǰ��δ��
            || (SPEED > 100)            //���ٱ���
            )
        BUZZ = !FLASH;
    else BUZZ = 1;

    //���� С�ƿ��رպ� 
    if (LED15) {
        OC1RS = e_backlight;
    } else {
        OC1RS = 0;
    }

    PO1 = !(SPEED > 5);
    PO2 = !(M_ON && VCU_Gear == 1);
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