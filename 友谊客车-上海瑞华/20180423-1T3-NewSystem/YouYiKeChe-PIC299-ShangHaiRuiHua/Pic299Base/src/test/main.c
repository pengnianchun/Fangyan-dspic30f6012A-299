/*
 *Created on 2016年8月3日, 
 *     客车仪表
 *版本号 V1.0
 */
#include "system.h"

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

int main(void) {
    unsigned char task = 0;
    unsigned int temp = 0;
    System_Init();

    while (1) {
        ClrWdt();
        SW_Input();

        if (M_ON) {// ON 闭合
            PWR_CTRL_DR = 0;
            PWR_CTRL = 1;
            bLCD_RESET = 1;
            SM_Update_0(); //车速表
            SM_Update_5(); //转速表
            
            if (task == 0) {
                task = 1;
                LCD_Exec();
            } else if (task == 1) {
                task = 2;
                
                //更新水温表程序 最大值1152  步进角度96°
                //temp = ADR[3];
                if (temp >= 180) {
                    sm_new_value[4] = 0;
                } else if (temp > 90 && temp < 180) { //40--80 
                    sm_new_value[4] = 576 - (unsigned int) (6.4 * (temp - 90));
                } else if (temp <= 90 && temp > 28) { //80--100
                    sm_new_value[4] = 864 - (unsigned int) (4.65 * (temp - 28));
                } else if (temp <= 28 && temp > 8) { //100--120
                    sm_new_value[4] = 1152 - (unsigned int) (14.4 * (temp - 8));
                } else {
                    sm_new_value[4] = 1152;
                }
                SM_Update_4(); //水温表
            } else if (task == 2) {
                task = 3;
                //temp = ADR[1]; //更新油料表
                if (temp < 10) {
                    sm_new_value[3] = 0;
                } else if (temp > 180) {
                    sm_new_value[3] = 1152;
                } else {
                    sm_new_value[3] = (unsigned int) (6.775 * (temp - 10));
                }
                SM_Update_3(); //油量表
            } else if (task == 3) {
                task = 4;
                //temp = ADR[2];
                if (temp < 10) {
                    sm_new_value[2] = 0;
                } else if (temp > 185) {
                    sm_new_value[2] = 1152;
                } else {
                    sm_new_value[2] = (unsigned int) (6.583 * (temp - 10));
                }
                SM_Update_2(); //机油压力表
            } else if (task == 4) {
                task = 5;
                //temp = ADR[6];
                if (temp < 180) { //更新电压表程序ADR[5]
                    sm_new_value[1] = 0;
                } else if ((temp >= 180)&&(temp < 240)) {
                    sm_new_value[1] = (unsigned int) (6.667 * (temp - 180));
                } else if ((temp >= 240)&&(temp <= 320)) {
                    sm_new_value[1] = (unsigned int) (10 * (temp - 240)) + 400;
                } else {
                    sm_new_value[1] = 1200;
                }
                SM_Update_1(); //电压表 
            } else if (task == 5) {
                task = 0;
                if (F500ms) { //
                    F500ms = 0;
                    DS3231_ReadTime(&timer); //读取时间          
                    if (save_flag) {
                        save_flag = 0;
                        EEROM_WriteSingleMiles();
                        EEROM_WriteTotalMiles();
                    }
                }
            } else {
                task = 0;
            }
        } else { //ON 关闭
            if (F100ms) {
                F100ms = 0;
                if (bLCD_RESET) {
                    bLCD_RESET = 0;
                    LCD_Init();
                }
                LCD_BackLight(0);
                SM_Zero(); //步进电机复位
                OC1RS = 0; //关闭小灯
                task = 0;
                if (sm_old_value[0] == 0) task++;
                if (sm_old_value[1] == 0) task++;
                if (sm_old_value[2] == 0) task++;
                if (sm_old_value[3] == 0) task++;
                if (sm_old_value[4] == 0) task++;
                if (sm_old_value[5] == 0) task++;
                gCTL[0].byte = 0x00;
                gCTL[1].byte = 0x00;
                gCTL[2].byte = 0x00;
                gCTL[3].byte = 0x00;
                gCTL[4].byte = 0x00;
                gCTL[5].byte = 0x00;
                gCTL[6].byte = 0x00;
                gCTL[7].byte = 0x00;
                alarm_led[0].byte = 0xff;
                alarm_led[1].byte = 0x00;
                alarm_led[2].byte = 0x00;
                alarm_led[3].byte = 0x00;
                if (wake_up1) { //危险报警开关开启   
                    F_PO9 = FLASH;
                    F_PO10 = FLASH;
                    M_PO7 = FLASH;
                    M_PO8 = FLASH;
                    BUZZ = !FLASH;
                } else {
                    F_PO9 = 0;
                    F_PO10 = 0;
                    M_PO7 = 0;
                    M_PO8 = 0;
                }
                LED4 = M_PO7; //左转向灯
                LED8 = M_PO8; //右转向灯
                LED_Out();
//                if (F50ms) {
//                    F50ms = 0;
//                    BCAN_SendCtl();
//                }
                if ((task == 6)&& (wake_up3 == 0) && (wake_up1 == 0) && (wake_up2 == 0)) {//步进电机回零，准备切断电源
                    __delay_us(100);
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
