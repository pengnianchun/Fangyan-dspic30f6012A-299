/*
 * File:   APP_Pout.c
 * Author: pnc
 *
 * Created on 2017��7��28��, ����4:53
 */


#include "APP_System.h"

void SYSTME_Logic(void) {
    F_PO1 = IN12;           //ǰ����
    F_PO2 = IN13;           //���˵�
    F_PO3 = IN15;//( IN15 &&  IN16 && IN17);//����1 
    F_PO4 = IN16;//(!IN15 &&  IN16 && IN17);//����2 
    F_PO5 = IN17;//(!IN15 && !IN16 && IN17);//����3 
    F_PO6 = LED18;          //פ����
    F_PO7 = LED22;          //�����
    F_PO8 = LED17;          //Զ���
    F_PO9 = LED4;           //��ת���
    F_PO10 = IN8;           //��ת���
    F_PO11 = LED21;         //������
    F_PO12 = LED24;         //�ƶ���
    F_PO13 = IN1;           //������
    F_PO14 = IN2;           //������
    F_PO15 = IN1;           //�����

    M_PO1 = (IN12); //������1
    M_PO2 = (FLASH && (IN5 || wake_up1)); //��ת���
    M_PO3 = (IN11); //˾����
    M_PO4 = (rKL6); //�ƶ���
    M_PO5 = (IN20); //ǰ�ſ���ŷ�
    M_PO6 = (IN19); //ǰ·��
    M_PO7 = (IN28); //ǰ�Źص�ŷ�
    M_PO8 = (M_ON); //������
    M_PO9 = (IN27); //���ſ���ŷ�
    M_PO10 = (IN19); //��·��
    M_PO11 = (IN26); //���Źص�ŷ�
    M_PO12 = (IN13); //������2
    M_PO13 = (M_ON); //Ӳ�̵�Դ
    M_PO14 = (IN6); //λ�õ�
    M_PO15 = (FLASH && (IN1 || wake_up1)); //��ת���

    R_PO1 = (rKL6); //�ƶ���
    R_PO2 = (IN19); //��·��
    R_PO3 = (LED20); //�����       
    R_PO4 = (M_ON); //������������Դ
    R_PO5 = (FLASH && (IN1 || wake_up1)); //��ת���
    R_PO6 = (M_ON); //��ѹ��������Դ
    R_PO7 = (FLASH && (IN5 || wake_up1)); //��ת��
    R_PO8 = IN22; //������
    R_PO9 = (0); //������1
    R_PO10 = IN22; //������
    R_PO11 = (mKH1 && IN6); //ǰ��̤����
    R_PO12 = (IN6); //λ�õ�ʾ�ߵ�
    R_PO13 = (mKL15 && IN6); //����̤����
    R_PO14 = (0); //����������
    R_PO15 = (0); //������2

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