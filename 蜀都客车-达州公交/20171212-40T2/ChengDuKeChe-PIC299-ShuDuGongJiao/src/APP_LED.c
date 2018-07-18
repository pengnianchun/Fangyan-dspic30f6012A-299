/*
 * File:   APP_LED.c
 * Author: pnc
 *
 * Created on 2017��7��28��, ����4:49
 */

#include "APP_System.h"

void LED_Logic(void) {     
    //ǰ�ſ�ָʾ //��������
    LED1 = 0;

    //���ſ�ָʾ �յ�ָʾ
    LED2 = 0;   
    
    //�����ƶ�ָʾ
    //LED3 = (VCU_Gear==0); 

    //Interval_Status(IN1 || IN5 || WAKE_Danger,Flash_400ms);//ע��400ms��˸��Ч״̬
    //��ת��
    if ((IN1) || WAKE_Danger)
        LED4 = FLASH;
        //LED4 = Flash[Flash_400ms].Status;
    else LED4 = 0;
  
    //LED5 = (VCU_Gear==1); //ǰ����ָʾ Ԥ��ָʾ

    //���ָʾ  ����ѹ������
    LED6 = ((Engine_oil_press < 110) && FLASH_1s && (CAN_0x18EF4BEF.Engine_wait == 0));   
    
    //����ͷ����  ˮ�¸߱���
    LED7 = ((water_temp > 135) && FLASH_1s);
    
    //��ת���
    if ((IN5) || WAKE_Danger)
        LED8 = FLASH;
        //LED8 = Flash[Flash_400ms].Status;
    else LED8 = 0;

    if (ADV[2] < 1875)//��ѹ1���ź� 0.55MP����
        LED9 = 1;
    else
        LED9 = 0;

    LED10 = 1; //�ܵ�Դָʾ   

    if (ADV[3] < 1875) //��ѹ2 0.55MP����
        LED11 = 1;
    else
        LED11 = 0;

    //SOC���� ���������ϱ���
    LED12 = 0;

    //������� ���л�ˮ����
    LED13 = 0;

    //�������ϵͳ���� OBDָʾ
    LED14 = 0;

    LED15 = 0; //С�� ��������ϱ���ָʾ

    LED16 = (BAT24V_count >= BAT24_TIME); //���ص�ѹ�� ���ָʾ

    LED17 = (WAKE_ON && IN24); //Զ��� Զ��Ʊ���

    LED18 = (rKL5); //��ɲ פ���ƶ�����

    LED19 = (WAKE_ON && IN29 && IN8); //ǰ��� ǰ��Ʊ���

    LED20 = (LED19 && IN9); //����� ����Ʊ���

    LED21 = (Current_Gear == 124);//������ ������

    LED22 = (WAKE_ON && IN6); //����� ����Ʊ���

    //LED23 = (IN14 && IN31 && M_ON);//������ ����������

    LED24 =  (WAKE_ON && rKL2); //ɲ��ָʾ ɲ��ָʾ


    //������ Ϊ0ʱ�죬Ϊ1ʱ����   
    if (0)
        BUZZ = 0;
    else if ((rKL10 && SPEED > 5)       //�����δ��
            || (fKL15  && SPEED > 5)     //ǰ��δ��
            || (fKH1   && SPEED > 5)     //����δ��
            || IN30                     //������ѹ��
            || ((Engine_oil_press < 110) && (CAN_0x18EF4BEF.Engine_wait == 0))//����ѹ������ < 110
            || (water_temp > 135) //ˮ�¸߱���>95
            || rKL9 //ˮλ��
            || CAN_18FECAEF.MalfunctionIndicatorLampStatus == 1
            )
        BUZZ = !FLASH_1s;
    else if (LED4                       //��ת��
            || LED8                     //��ת��
            || LED9                     //��ѹ1����
            || LED11                    //��ѹ2����
            || !rKL11                   //��ǰĦ��Ƭ
            || !rKL6                    //���Ħ��Ƭ
            || !rKL12                   //��ǰĦ��Ƭ
            || !rKL8                    //�Һ�Ħ��Ƭ
            //|| (mKL10 && SPEED > 5)     //��ȫ��
            //|| (BMS_ChargeGun_Link == 1)//���ڳ�磬��ֹ�г�
            || (SPEED > 69)             //���ٱ���
            )
        BUZZ = !FLASH;
    else BUZZ = 1;

    //���� С�ƿ��رպ� 
    if (IN29) {
        OC1RS = e_backlight;
    } else {
        OC1RS = 0;
    }

    //PO1 = !(SPEED > 5);
    //PO2 = !(M_ON && VCU_Gear == 1);
}

void LED_Danger(void){     //Σ�ձ���״̬
    F_PO7 = FLASH;
    F_PO8 = FLASH;
    //M_PO8 = FLASH;
    //M_PO15 = FLASH;
    R_PO7 = FLASH;
    R_PO8 = FLASH;
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