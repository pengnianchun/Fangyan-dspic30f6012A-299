/*
 * File:   LED_main.c
 * Author: mpszm
 *
 * Created on 2016年8月4日, 上午9:45
 */
// FOSC
#pragma config FOSFPR = XT_PLL4         // Oscillator (XT w/PLL 4x)
#pragma config FCKSMEN = CSW_FSCM_OFF   // Clock Switching and Monitor (Sw Disabled, Mon Disabled)

// FWDT
#pragma config FWPSB = WDTPSB_16        // WDT Prescaler B (1:16)
#pragma config FWPSA = WDTPSA_512       // WDT Prescaler A (1:512)
#pragma config WDT = WDT_OFF            // Watchdog Timer (Disabled)

// FBORPOR
#pragma config FPWRT = PWRT_64          // POR Timer Value (64ms)
#pragma config BODENV = NONE            // Brown Out Voltage (Reserved)
#pragma config BOREN = PBOR_ON          // PBOR Enable (Enabled)
#pragma config MCLRE = MCLR_EN          // Master Clear Enable (Enabled)

// FBS
#pragma config BWRP = WR_PROTECT_BOOT_OFF// Boot Segment Program Memory Write Protect (Boot Segment Program Memory may be written)
#pragma config BSS = NO_BOOT_CODE       // Boot Segment Program Flash Memory Code Protection (No Boot Segment)
#pragma config EBS = NO_BOOT_EEPROM     // Boot Segment Data EEPROM Protection (No Boot EEPROM)
#pragma config RBS = NO_BOOT_RAM        // Boot Segment Data RAM Protection (No Boot RAM)

// FSS
#pragma config SWRP = WR_PROT_SEC_OFF   // Secure Segment Program Write Protect (Disabled)
#pragma config SSS = NO_SEC_CODE        // Secure Segment Program Flash Memory Code Protection (No Secure Segment)
#pragma config ESS = NO_SEC_EEPROM      // Secure Segment Data EEPROM Protection (No Segment Data EEPROM)
#pragma config RSS = NO_SEC_RAM         // Secure Segment Data RAM Protection (No Secure RAM)

// FGS
#pragma config GWRP = GWRP_OFF          // General Code Segment Write Protect (Disabled)
#pragma config GCP = GSS_OFF            // General Segment Code Protection (Disabled)

// FICD
#pragma config ICS = ICS_PGD            // Comm Channel Select (Use PGC/EMUC and PGD/EMUD)

#include <xc.h>
#include "bsp.h"

#define SET_STEP_0  2500  //车速表
#define SET_STEP_1  1000  //电压表
#define SET_STEP_2  1000  //机油压力表
#define SET_STEP_3  1000  //油量表
#define SET_STEP_4  1000  //水温表
#define SET_STEP_5  2500  //转速表
int main(void) {
    alarm_led[0].byte = 0xff;//关闭蜂鸣器
    alarm_led[1].byte = 0x00;
    alarm_led[2].byte = 0x00;
    alarm_led[3].byte = 0x00;
    LED_Out();
    
    SM_Init();
    SM_Reset();
    
    while (1) {

        if(sm_old_value[0]==0){
          sm_new_value[0] = SET_STEP_0;
        }
        if(sm_old_value[0]==SET_STEP_0){
         sm_new_value[0] = 0;
        }
        if(sm_old_value[1]==0){
          sm_new_value[1] = SET_STEP_1;
        }
        if(sm_old_value[1]==SET_STEP_1){
         sm_new_value[1] = 0;
        }
        if(sm_old_value[2]==0){
          sm_new_value[2] = SET_STEP_2;
        }
        if(sm_old_value[2]==SET_STEP_2){
         sm_new_value[2] = 0;
        }
        if(sm_old_value[3]==0){
          sm_new_value[3] = SET_STEP_3;
        }
        if(sm_old_value[3]==SET_STEP_3){
         sm_new_value[3] = 0;
        }
                if(sm_old_value[4]==0){
          sm_new_value[4] = SET_STEP_4;
        }
        if(sm_old_value[4]==SET_STEP_4){
         sm_new_value[4] = 0;
        }
        if(sm_old_value[5]==0){
          sm_new_value[5] = SET_STEP_5;
        }
        if(sm_old_value[5]==SET_STEP_5){
         sm_new_value[5] = 0;
        }
        
        
        SM_Update_0();    
        SM_Update_1();     
        SM_Update_2();    
        SM_Update_3();   
        SM_Update_4();    
        SM_Update_5();   
        
        
    }
    return 0;
}
