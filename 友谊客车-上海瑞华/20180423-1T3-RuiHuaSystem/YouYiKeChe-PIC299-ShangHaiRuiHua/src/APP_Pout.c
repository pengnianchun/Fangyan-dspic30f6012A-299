/*
 * File:   APP_Pout.c
 * Author: pnc
 *
 * Created on 2017��7��28��, ����4:53
 */


#include "APP_System.h"

void SYSTME_Logic(void) {
    // F_PO1 = (IN16 && M_ON); //��ο쵵
    // F_PO2 = (IN14 && M_ON); //�������
    // F_PO3 = (IN21 && M_ON); //��ˮ���
    F_PO4 = (LED15 && IN9);                     //��ǰ���
    F_PO5 = (IN28 && wake_up2);                 //������۷�
    F_PO6 = (FLASH && (IN5 || wake_up1));       //��ת���
    F_PO7 = (FLASH && (IN1 || wake_up1));       //��ת���
    Interval_Status(CAN_0x18EF4EEF.MCU_RPM > 20300,Flash_3s_10min);
    F_PO8 = Flash[Flash_3s_10min].Status; //������ 
    F_PO9 = LED17;                              //��Զ�ص�
    F_PO10 = (LED15 && IN9);                    //��ǰ���
    F_PO11 = LED17;                             //��Զ���
    F_PO12 = fKL8;                              //���е� 
    F_PO13 = LED22;                             //�����
    F_PO14 = LED15;                             //λ�õ�
    F_PO15 = LED22;                             //�ҽ���
    F_PO16 = 0;                                 //���ŵ���

    M_PO1 = (IN19);                             //ǰ·�Ƶ�Դ
    M_PO2 = (wake_up2 && IN24);                 //���2
    M_PO3 = (LED15 && IN4);                     //ǰ��̤����
    M_PO4 = (fKL6);                             //�ƶ���
    M_PO5 = (LED15 && IN3);                     //����̤���� 
    M_PO6 = (IN19);                             //��·��
    M_PO7 = (wake_up2 && fKL10);                //���Ӿ�����
    M_PO8 = (IN9 && IN10 && LED15);             //�����
    M_PO9 = (IN19);                             //��·�� //(wake_up2 && IN6 && fKL8); //���е�
    M_PO10 = (wake_up2 && IN18);                //˾������
    M_PO11 = (wake_up2);                        //��������Դ
    M_PO12 = (wake_up2 && IN25);                //˾����
    M_PO13 = (CAN_0x18EF4AEF.EV_Gear == 13);    //�����Ƶ�Դ
    M_PO14 = (SPEED < 3);                       //�űõ�Դ
    M_PO15 = (wake_up2 && IN23);                //���1
    M_PO16 = 0;                                 //���ŵ���

    /*R_PO1 = (0); //�ƶ���
    R_PO2 = LED15; //��·��
    R_PO3 = WAKE_ON; //�����       
    R_PO4 = (LED15 && mKH1); //������������Դ
    R_PO5 = (LED15 && mKL12); //��ת���
    R_PO6 = LED4; //��ѹ��������Դ
    R_PO7 = LED8; //��ת��
    R_PO8 = LED20; //������
    R_PO9 = 0; //������1
    R_PO10 = WAKE_ON; //������
    R_PO11 = LED24; //ǰ��̤����
    R_PO12 = (WAKE_ACC && IN22); //λ�õ�ʾ�ߵ�
    R_PO13 = (WAKE_ACC && IN23); //����̤����
    R_PO14 = (WAKE_ACC && IN24); //����������
    R_PO15 = WAKE_ON; //������2*/

}

void POUT_Clear(void){
    gCTL[0].byte = 0x00;
    gCTL[1].byte = 0x00;
    gCTL[2].byte = 0x00;
    gCTL[3].byte = 0x00;
    gCTL[4].byte = 0x00;
    gCTL[5].byte = 0x00;
    gCTL[6].byte = 0x00;
    gCTL[7].byte = 0x00;
}