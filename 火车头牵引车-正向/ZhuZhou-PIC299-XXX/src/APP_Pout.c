/*
 * File:   APP_Pout.c
 * Author: pnc
 *
 * Created on 2017��7��28��, ����4:53
 */


#include "APP_System.h"

void SYSTME_Logic(void) {
    F_PO1 = (SPEED >= 5);                  //�ſص�Դ
    F_PO2 = (WAKE_ACC || WAKE_ON);         //�ƶ�̤���Դ
    F_PO3 = (WAKE_ON);                     //�¿������Դ
    //F_PO4 = LED4;                        //��ǰ���
    F_PO5 = (WAKE_ON);                     //���±�����Դ
    F_PO6 = LED20;                         //�����
    F_PO7 = LED4;                          //��ת���
    F_PO8 = (WAKE_ACC || WAKE_ON);         //���ӵ�Դ
    F_PO9 = LED17;                         //��Զ�ص�
    //F_PO10 = LED4; //��ǰ���
    F_PO11 = LED17;                        //��Զ�ص�
    F_PO12 =(WAKE_ON);                     //������
    F_PO13 = LED22;                        //������
    F_PO14 = 0;              //�����ź�
    F_PO15 = LED22;                        //������

    M_PO1 = ((LED1 || LED2) && IN11);      //����
    M_PO2 = (LED2 && LED15);               //����̤����
    M_PO3 = (IN19);                        //������
    M_PO4 = ((WAKE_ACC || WAKE_ON) && LED24); //�ƶ���
    M_PO5 = (fKH1);                        //�յ�����Դ
    M_PO6 = (WAKE_ON);                     //���ӷ��ȿ��Ƶ�Դ
    //M_PO7 = ((M_ON || wake_up2) && IN12); //������
    M_PO8 = LED8;                          //��ת���
    M_PO9 = (LED1 && LED15);              //ǰ��̤����
    M_PO10 = (WAKE_ON);                    //������
    M_PO11 = LED19;                        //ǰ���
    M_PO12 = (WAKE_ON);                    //��ѹ��������Դ
    M_PO13 = ((WAKE_ACC || WAKE_ON) && LED15); //С�Ƶ�Դ
    //M_PO14 = (VCU_Gear == 1); //�����ź�
    M_PO15 = LED4;                         //��ת���

    R_PO1 = (rKL6); //�ƶ���
    R_PO2 = (IN19); //��·��
    R_PO3 = (LED20); //�����       
    R_PO4 = (M_ON); //������������Դ
    R_PO5 = (FLASH && (IN1 || wake_up1)); //��ת���
    R_PO6 = (M_ON); //��ѹ��������Դ
    R_PO7 = (FLASH && (IN5 || wake_up1)); //��ת��
    R_PO8 = IN22; //������
    R_PO9 = 0; //������1
    R_PO10 = IN22; //������
    R_PO11 = (mKH1 && IN6); //ǰ��̤����
    R_PO12 = (IN6); //λ�õ�ʾ�ߵ�
    R_PO13 = (mKL15 && IN6); //����̤����
    R_PO14 = 0; //����������
    R_PO15 = 0; //������2

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