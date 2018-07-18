/*
 * File:   APP_Pout.c
 * Author: pnc
 *
 * Created on 2017��7��28��, ����4:53
 */


#include "APP_System.h"

void SYSTME_Logic(void) {
    unsigned int temp = 0;
    //F_PO1 = (SPEED >= 5);                  //�ſص�Դ
    //F_PO2 = (WAKE_ACC || WAKE_ON);         //�ƶ�̤���Դ
    //F_PO3 = (WAKE_ON);                     //�¿������Դ
    F_PO4 = LED22;                         //������
    F_PO5 = LED17;                         //��Զ��ƣ�Զ�⸨����
    F_PO6 = LED19;                         //ǰ���
    F_PO7 = LED4;                          //��ǰת��ƣ�ǰ����ת��
    F_PO8 = LED8;                          //��ǰת��ƣ�ǰ����ת��
    F_PO9 = IN29;                          //ǰС��(���Ҳ���)
    //���ŵ�Դ
    if ((SPEED >= 5) && (fKL15 || fKH1)) {
        F_PO10 = 1;
    }else if((SPEED >= 5) && !fKL15 && !fKH1){
        F_PO10 = 0;
    }else if(SPEED < 5){
        F_PO10 = 1;
    }        
    F_PO11 = LED22;                        //�ҽ����
    F_PO12 = (IN29 && fKL15);              //ǰ��̤���ƣ�LED��
    //��������
    //ON - ǰ��ON �� �յ�ON �� ת��С��550 �� �����OFFʱ�����
    //ON - ����ON �� �յ�ON �� ת��С��550�Һ����ON����ɲ�ź�ONʱ�����
    F_PO13 = ((IN4 && (Current_Gear == 125)&&(EngineSpeed < 4400)&&(!rKL10))
            || (rKL15 && (Current_Gear == 125)&&(EngineSpeed < 4400) && rKL10 && LED18)
            );                           
    F_PO14 = WAKE_ON;                      //���ȵ�Դ
    F_PO15 = LED17;                        //��Զ��ƣ�Զ�⸨����
    F_PO16 = 0;

    /*M_PO1 = 1;                             //���ŵ�Դ��������
    M_PO2 = IN29;                          //ʾ�ߵƣ�LED��
    M_PO3 = ((mKH1 && IN29) || IN11);      //���ŵƣ�LED��
    M_PO4 = (IN17);                        //ǰ·��
    M_PO5 = (WAKE_ON && fKL2);             //���ƣ�LED��
    M_PO6 = (IN17);                        //�ࡢ��·��
    M_PO7 = (WAKE_ON && fKL10);            //TV1��Դ
    M_PO8 = (fKL3 || F_PO12);              //��ʻԱ���ƣ�LED)��ACCorON+��ʻԱ���ƿ��أ����ߣ�ACC/ON+ǰ�ſ���λ�źţ����ߣ���翪��+��ʻԱ���ƿ��أ�
    M_PO9 = (IN11);                        //���1�����LED)
    M_PO10 = (IN12);                       //���2�����LED)
    M_PO11 = (WAKE_ON && IN26 && (SPEED == 0)); //���ſ���ŷ�
    M_PO12 = (WAKE_ON && (IN32 || (SPEED > 5)));//���Źص�ŷ�
    M_PO13 = (WAKE_ON && IN19 && (SPEED == 0)); //ǰ�ſ���ŷ�
    M_PO14 = (WAKE_ON && (IN28 || (SPEED > 5)));//ǰ�Źص�ŷ�
    M_PO15 = (WAKE_ON && fKL10);           //TV2��Դ
    M_PO16 = 0;*/

    //�����̵��������������¶�������֮һ://ON - ǰ��ON�ҿյ�ON��ת��С��550�Һ����OFF��HCU������ֵֹΪ0��TCU����ʹ��ֵΪ1��
                                         //ON - ����ON�ҿյ�ON��ת��С��550�Һ����ON����ɲ�ź�ON��
                                         //ON - �������й�����HCU��0x18EF0AEF��������ֵΪ21415��ʱ�����
    if ((Current_Gear == 125)                            //�յ�
            && (EngineSpeed < 4400)                      //ת��С��550
            && (CAN_0x18EF0AEF.hcu_starter_forbid == 0)  //HCU������ֵֹΪ0
            && (CAN_0x0CF00203.tcu_start_allow == 1)     //TCU����ʹ��ֵΪ1
            && IN4                                       //ǰ����
            && !rKL10                                    //�����OFF
            ) {
        R_PO1 = 1;
    } else if((Current_Gear == 125)                      //�յ� 
            && (EngineSpeed < 4400)                      //ת��С��550
            && rKL15                                     //������
            && rKL10                                     //�����ON
            && rKL5                                      //��ɲON
            ){
        R_PO1 = 1;
    } else if (CAN_0x18EF0AEF.ENG_start_req == 21415) {
        R_PO1 = 1;
    } else {
        R_PO1 = 0;
    }
    //�ŷ���
    temp = rADR[1];
    if (M_ON) {
        if (IN17) {
            R_PO2 = 1;
        } else {
            if (temp <= 220)R_PO2 = 1; //35�ȿ���
            if (temp >= 232)R_PO2 = 0; //32�ȹر� 
        }
    } else {
        R_PO2 = 0;
    }
    R_PO3 = (WAKE_ON); //������  ON�����       
    R_PO4 = (WAKE_ON && (Current_Gear == 124)); //�����ƣ�LED)
    R_PO5 = (LED24); //��ɲ���ƣ�LED)
    R_PO6 = (LED20); //����ƣ�LED)
    R_PO7 = (LED4);  //���ת��ƣ��󲿲�ת����LED)
    R_PO8 = (LED8);  //�Һ�ת��ƣ��󲿲�ת����LED)
    R_PO9 = (WAKE_ON || WAKE_ACC); //�űõ�Դ
    R_PO10 = (IN29); //��С�ƣ�LED)
    R_PO11 = ((WAKE_ON && IN29 && fKH1) || IN11); //����̤��ƣ�LED��
    //��ʻԱ���ƣ�LED)��ACCorON+��ʻԱ���ƿ��أ����ߣ�ACC/ON+С��+ǰ�ſ���λ�źţ����ߣ���翪��+��ʻԱ���ƿ��أ�
    R_PO12 = ((WAKE_ON && (IN18 || (fKL15 && IN29))) || (WAKE_Charge && IN18));
    R_PO13 = (IN11);                       //���1�����LED)
    R_PO14 = (IN12);                       //���2�����LED)
    R_PO15 = (WAKE_ON && (fKH1 || fKL15)); //�ſ��ź�
    R_PO16 = 1;

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