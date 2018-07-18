/*
 *Created on 2016年8月3日, 
 *     客车仪表
 *版本号 V1.0
 */
#include "SYSTEM.h"

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

/*
// FOSC
#pragma config FOSFPR = XT_PLL4        // Oscillator (XT w/PLL 4x)
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
 */

int main(void) {
    unsigned char task = 0;
    unsigned int temp = 0;
    System_Init();
    while (1) {
        ClrWdt();
        if (F50ms) {
            F50ms = 0;
            SW_Input();
        }
        if (wake_up2 && !M_ON) {
            M_ON_flag = 1; //唤醒当有效标记
            PWR_CTRL_DR = 0;
            PWR_CTRL = 1;
            if(!bLCD_RESET){
                LCD_BackLight(7);
            }
            bLCD_RESET = 1;
            LCD_Exec(); //直接执行会影响电机，原因未知
            SM_Zero(); //步进电机复位
                    
            if (F500ms) { //
                F500ms = 0;
                Count_ADR(); //换算模拟量的值  会严重影响主函数运行时间
                DS3231_ReadTime(&timer); //读取时间    
                LCD_BackLight(7); // 
            }

            M_ON_flag = 0; //唤醒档有效标记
        }
        
        if (M_ON) {// ON 闭合   
            M_ON_flag = 1; //ON当有效标记
            PWR_CTRL_DR = 0;
            PWR_CTRL = 1;
            if(!bLCD_RESET){
                LCD_BackLight(7);
            }
            bLCD_RESET = 1; 

            Vspeed = (30.0 * DJ_speed) / e_hm_pulse; //车速单位0.1KM/H
            if (Vspeed < 1400)sm_new_value[4] = (unsigned int) (1.97 * Vspeed);
            else              sm_new_value[4] = 2760;
            SM_Update_4(); //车速表           
            
            if (task == 0) {
                task = 1;
                
                LCD_Exec();
                
            } else if (task == 1) {
                task = 2;

                if (DJ_speed < 14000) sm_new_value[5] = (unsigned int) (0.19715 * DJ_speed);
                else                  sm_new_value[5] = 2760;
                SM_Update_5(); //转速表  

            } else if (task == 2) {
                task = 3;
                
                temp = ADV[4]/10;
                      if(temp < 50  )  sm_new_value[3] = 0;
                else  if(temp < 300 )  sm_new_value[3] = (unsigned int)( 4.32*(temp-50));
                else                   sm_new_value[3] = 1080;
                      
                //     if (ADR[1] < 10 ) sm_new_value[3] = 0;
                //else if (ADR[1] > 185) sm_new_value[3] = 1080;
                //else                   sm_new_value[3] = (unsigned int) (6.17 * (ADR[1] - 10));
                SM_Update_3(); //气压1                 

            } else if (task == 3) {
                task = 4;
                
                temp = ADV[5]/10;
                      if(temp < 50  )  sm_new_value[0] = 0;
                else  if(temp < 300 )  sm_new_value[0] = (unsigned int)( 4.32*(temp-50));
                else                   sm_new_value[0] = 1080;
                      
                //     if (ADR[2] < 10 ) sm_new_value[0] = 0;
                //else if (ADR[2] > 185) sm_new_value[0] = 1080;
                //else                   sm_new_value[0] = (unsigned int) (6.17 * (ADR[2] - 10));
                SM_Update_0(); //气压2 
                
            } else if (task == 4) {
                task = 0;
                if (F500ms) { //
                    F500ms = 0;        
                    Count_ADR(); //换算模拟量的值  会严重影响主函数运行时间
                    DS3231_ReadTime(&timer); //读取时间   
                    
                    PCAN_send_mile();//里程
                    
                    LCD_BackLight(7);//

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
            M_ON_flag = 0; //ON档有效标记
        } else if (M_ON == 0 && wake_up2 == 0) { //ON 关闭    
                SM_Zero(); //步进电机复位
            if (F100ms) {
                F100ms = 0;
                if (bLCD_RESET) {
                    bLCD_RESET = 0;
                    LCD_BackLight(0);
                }
                
                OC1RS = 0; //关闭小灯

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
                LED_Out();

                if (wake_up1) { //危险报警开关开启   
                    F_PO6=FLASH; //
                    F_PO7=FLASH; //
                }else{
                    F_PO7=0;
                    F_PO6=0; //
                     }
                    T_PO15=F_PO7; //左转向灯
                    T_PO2 =F_PO6; //右转向灯
                    LED16 =F_PO7; //左转向报警
                    LED21 =F_PO6; //右转向报警 
                    BUZZ = !(LED16 || LED21);
                LED_Out();   

                BCAN_SendCtl();
                
                task = 0;
                if (sm_old_value[0] == 0) task++;
                if (sm_old_value[1] == 0) task++;
                if (sm_old_value[2] == 0) task++;
                if (sm_old_value[3] == 0) task++;
                if (sm_old_value[4] == 0) task++;
                if (sm_old_value[5] == 0) task++;
                
                BCAN_SendCtl();
                
                if ((task == 6)&& (wake_up3 == 0) && (wake_up1 == 0) && (wake_up2 == 0)) {//步进电机回零，准备切断电源
                    __delay_us(100); //中断里的BCAN发送50ms发送一次，可能来不及发最后的状态，程序已经结束
                    BCAN_SendCtl();
                    __delay_us(100);
                    BCAN_SendCtl();
                    __delay_us(100);
                    BCAN_SendCtl();
                    __delay_us(100);
                    BCAN_SendCtl();
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
