/*
 * File:   APP_Pout.c
 * Author: pnc
 *
 * Created on 2017年7月28日, 下午4:53
 */


#include "APP_System.h"

void SYSTME_Logic(void) {
    F_PO1 = (WAKE_ACC);                    
    F_PO2 = (WAKE_ACC);         
    F_PO3 = (WAKE_ACC && IN11);
    F_PO4 = (WAKE_ON);
    F_PO5 = 0;
    F_PO6 = LED8;
    F_PO7 = LED4;
    F_PO8 = WAKE_ACC;
    F_PO9 = LED17;
    F_PO10 = 0;
    F_PO11 = LED17;
    F_PO12 = 0;
    F_PO13 = LED22;
    F_PO14 = LED15;
    F_PO15 = LED22;
    F_PO16 = 0;

    M_PO1 = (WAKE_ACC && mKL10);   
    M_PO2 = (LED8);                          
    M_PO3 = (WAKE_ACC && mKL12);    
    M_PO4 = (LED24);
    M_PO5 = ((mKL1 || fKL10 || mKL6)&&(SPEED < 5) && LED18);
    M_PO6 = (WAKE_ON && fKL1);
    M_PO7 = (mKL3);
    M_PO8 = (WAKE_ON && fKL1);
    M_PO9 = ((mKL5 || rKL9 || mKL8)&&(SPEED < 5) && LED18);                         
    M_PO10 = (LED19);                       
    M_PO11 = (mKL7);  
    M_PO12 = (WAKE_ACC && mKL9); 
    M_PO13 = (LED15);  
    M_PO14 = (WAKE_ACC && mKL11); 
    M_PO15 = (LED4);          
    M_PO16 = 0;
    
    R_PO1 = (LED24);
    R_PO2 = 0;
    R_PO3 = (LED20);     
    R_PO4 = 0; 
    R_PO5 = (LED4);
    R_PO6 = (WAKE_ACC);
    R_PO7 = (LED8);
    R_PO8 = (WAKE_ON && IN24);
    R_PO9 = (LED21); 
    R_PO10 = (IN4);
    R_PO11 = (WAKE_ON);
    R_PO12 = (LED15);
    R_PO13 = (WAKE_ACC);
    R_PO14 = (WAKE_ACC && rKL11);
    R_PO15 = (WAKE_ON);
    R_PO16 = 0;

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