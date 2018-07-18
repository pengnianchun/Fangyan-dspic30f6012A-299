/*
 *Created on 2016å¹?8??3??, 
 *     å®¢è½¦ä»?è¡?
 *?????? V1.0
 */
#include "APP_System.h"

// FOSC
#pragma config FOSFPR = XT_PLL8        // Oscillator (XT w/PLL 4x)
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

int main(void) {
    unsigned char task = 0;
    System_Init();
    while (1) {
        ClrWdt();
        //SW_Input();
        if (F50ms) {
            F50ms = 0;
            SW_Input();           
        }
 
        if (WAKE_ON) {
            M_ON_flag = 1;
            PWR_CTRL_DR = 0;
            PWR_CTRL = 1;
            if (!bLCD_RESET) {
                LCD_BackLight(7);
            }
            bLCD_RESET = 1;

            if (task == 0) {
                task = 1;
                LCD_Exec();
            } else if (task == 1) {
                task = 2;
                if (TestMode) {
                    SM_Test();
                } else {
                    SM_Logic();
                }
            } else if (task == 2) {
                task = 0;
                if (F500ms) {
                    F500ms = 0;
                    Count_ADR(); 
                    DS3231_ReadTime(&timer); 
                    LCD_BackLight(7);
                    if (save_flag) {
                        save_flag = 0;
                        e_single_miles = single_miles;
                        e_total_miles = total_miles;
                        EEROM_WriteSingleMiles();
                        EEROM_WriteTotalMiles();
                    }
                }
            } else {
                task = 0;
            }
            M_ON_flag = 0;
        } else if (WAKE_ACC || WAKE_Charge || WAKE_Start) {
            M_ON_flag = 1;
            
            PWR_CTRL_DR = 0;
            PWR_CTRL = 1;
            if (!bLCD_RESET) {
                LCD_BackLight(7);
            }
            bLCD_RESET = 1;

            if (task == 0) {
                task = 1;
                LCD_Exec();
            } else if (task == 1) {
                task = 0;
                SM_Zero();
            } else {
                task = 0;
            }

            if (F500ms) {
                F500ms = 0;
                Count_ADR();
                DS3231_ReadTime(&timer);
                LCD_BackLight(7);
            }
            M_ON_flag = 0;
        } else {
            SM_Zero();
            if (F100ms) {
                F100ms = 0;
                if (bLCD_RESET) {
                    bLCD_RESET = 0;
                    LCD_BackLight(0);
                }
                OC1RS = 0;
                POUT_Clear();  
                LED_Clear();

                if (WAKE_Danger) {
                    LED_Danger();
                } else {     
                    POUT_Clear();
                    LED_Clear();
                }            
                
                LED_Out();

                if ((SM_Zero_State() == 0) && (wake_up3 == 0) && (wake_up1 == 0) && (wake_up2 == 0)) {
                    __delay_us(500);
                    BCAN_SendCtl();
                    __delay_us(500);
                    BCAN_SendCtl();
                    __delay_us(500);
                    BCAN_SendCtl();
                    __delay_us(500);
                    BCAN_SendCtl();
                    __delay_us(500);
                    PWR_CTRL_DR = 1;
                    PWR_CTRL = 0; // 
                    PWR_CTRL_DR = 1;
                    PWR_CTRL = 0; // 
                    PWR_CTRL_DR = 1;
                    PWR_CTRL = 0; //     
                }
            }
        }
    }
    return 0;
}
