/*
 * File:   APP_LED.c
 * Author: pnc
 *
 * Created on 2017��7��28��, ����4:49
 */

#include "APP_System.h"

void LED_Logic(void) {     
    //ǰ�ſ�ָʾ //��������
    LED1 = fKL15;

    //���ſ�ָʾ �յ�ָʾ
    LED2 = mKH1;   
    
    //�����ƶ�ָʾ
    //LED3 = (VCU_Gear==0); 

    //Interval_Status(IN1 || IN5 || WAKE_Danger,Flash_400ms);//ע��400ms��˸��Ч״̬
    //��ת��
    if ((IN1 && WAKE_ACC) || WAKE_Danger)
        LED4 = FLASH;
        //LED4 = Flash[Flash_400ms].Status;
    else LED4 = 0;
  
    //LED5 = (VCU_Gear==1); //ǰ����ָʾ Ԥ��ָʾ

    //���ָʾ  ����ѹ������
    LED6 = (CAN_0x1818D0F3.BMSFlag3.bit7);   
    
    //����ͷ����  ˮ�¸߱���
    LED7 = (CAN_0x1818D0F3.BMSFlag3.bit6);
    
    //��ת���
    if ((IN5 && WAKE_ACC) || WAKE_Danger)
        LED8 = FLASH;
        //LED8 = Flash[Flash_400ms].Status;
    else LED8 = 0;

    if (rKL10)//��ѹ1���ź� 0.55MP����
        LED9 = 1;
    else
        LED9 = 0;

    LED10 = 1; //�ܵ�Դָʾ   

    if (rKL12) //��ѹ2 0.55MP����
        LED11 = 1;
    else
        LED11 = 0;

    //SOC���� ���������ϱ���
    LED12 = (CAN_0x181CD0F3.BMSFlag4.bit2 || CAN_0x1818D0F3.BMSFlag1.bit3 || CAN_0x1818D0F3.BMSFlag1.bit4);

    //������� ���л�ˮ����
    LED13 = (CAN_0x0C04A1A7.FaultLevel > 0);

    //�������ϵͳ���� OBDָʾ
    LED14 = (CAN_0x1819D0F3.Warn_level > 0);

    LED15 = (IN6 && WAKE_ACC); //С�� ��������ϱ���ָʾ

    LED16 = (BAT24V_count >= BAT24_TIME); //���ص�ѹ�� ���ָʾ

    LED17 = (WAKE_ACC && IN7); //Զ��� Զ��Ʊ���

    LED18 = (rKL5); //��ɲ פ���ƶ�����

    LED19 = (WAKE_ACC && IN9); //ǰ��� ǰ��Ʊ���

    LED20 = (LED19 && IN10); //����� ����Ʊ���

    LED21 = (CAN_0x0C06A1A7.VCUGearR && WAKE_ON);//������ ������

    LED22 = (WAKE_ACC && IN8); //����� ����Ʊ���

    //LED23 = (IN14 && IN31 && M_ON);//������ ����������

    LED24 =  (WAKE_ACC && (CAN_0x0C05A1A7.E_Brake || rKL3)); //ɲ��ָʾ ɲ��ָʾ


    //������ Ϊ0ʱ�죬Ϊ1ʱ����   
    if (mKL2)                               //�³�����
        BUZZ = 0;
    else if ((rKL11 && SPEED > 5)           //�����δ��
            || (LED1  && SPEED > 5)         //ǰ��δ��
            || (LED2   && SPEED > 5)        //����δ��
            )
        BUZZ = !FLASH_1s;
    else if (LED4                           //��ת��
            || LED8                         //��ת��
            || LED9                         //��ѹ1����
            || LED11                        //��ѹ2����
            || !rKL2                        //��ǰĦ��Ƭ
            || !rKL4                        //���Ħ��Ƭ
            || !rKL6                        //��ǰĦ��Ƭ
            || !rKL8                        //�Һ�Ħ��Ƭ
            //|| (mKL10 && SPEED > 5)       //��ȫ��
            //|| (BMS_ChargeGun_Link == 1)//���ڳ�磬��ֹ�г�         
            || (CAN_0x0C06A1A7.VCUOverSpeed)//���ٱ���
            )
        BUZZ = !FLASH;
    else 
        BUZZ = 1;

    //���� С�ƿ��رպ� 
    if (LED15) {
        OC1RS = e_backlight;
    } else {
        OC1RS = 0;
    }

    //Ӳ���������ƣ���ֵ0���������Ӳ���������ƣ���ֵ1�������
    PO1 = (SPEED < 5);
    PO2 = (SPEED < 5);
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