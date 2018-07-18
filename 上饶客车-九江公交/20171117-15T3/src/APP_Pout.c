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
    //F_PO14 = (VCU_Gear == 1);              //�����ź�
    F_PO15 = LED22;                        //������

    M_PO1 = LED15;      //С��
    M_PO2 = (IN20 && (SPEED < 5));               //����̤����
    M_PO3 = (IN28);                        //������
    M_PO4 = (IN27 && (SPEED < 5)); //�ƶ���
    M_PO5 = (IN26);                        //�յ�����Դ
    M_PO6 = LED4;                     //���ӷ��ȿ��Ƶ�Դ
    M_PO7 = LED8; //������
    M_PO8 = LED19;                          //��ת���
    M_PO9 = (WAKE_ON && IN11);              //ǰ��̤����
    M_PO10 = (WAKE_ON && IN12);                    //������
    M_PO11 = (WAKE_ON && IN12);                        //ǰ���
    M_PO12 = LED17;                    //��ѹ��������Դ
    M_PO13 = LED17; //С�Ƶ�Դ
    M_PO14 = LED22; //�����ź�
    M_PO15 = LED22;                         //��ת���

    R_PO1 = (EV_Gear == 2); //�ƶ���
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
    R_PO15 = WAKE_ON; //������2

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