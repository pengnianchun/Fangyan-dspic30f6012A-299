/*
 *Created on 2016��8��3��, 
 *     �ͳ��Ǳ�
 *�汾�� V1.0
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
    System_Init();
    while (1) {
        ClrWdt();
        if (F50ms) {
            F50ms = 0;
            SW_Input();
        }
        if (IN1 && M_ON) {// ON �պ�   
            M_ON_flag = 1; //ON����Ч���
            PWR_CTRL_DR = 0;
            PWR_CTRL = 1;
            if (!bLCD_RESET) {
                LCD_BackLight(7);
            }
            bLCD_RESET = 1;
            SM_Logic();
            M_ON_flag = 0; //ON����Ч���
        } else if (wake_up2) {//ֻ�ǻ��ѣ�ON����Чʱ��ִ�д˺���
            M_ON_flag = 1; //���ѵ���Ч���
            PWR_CTRL_DR = 0;
            PWR_CTRL = 1;
            if (!bLCD_RESET) {
                LCD_BackLight(7);
            }
            bLCD_RESET = 1;
            LCD_Exec(); //ֱ��ִ�л�Ӱ������ԭ��δ֪
            SM_Zero(); //���������λ
            if (F500ms) { //
                F500ms = 0;
                Count_ADR(); //����ģ������ֵ  ������Ӱ������������ʱ��
                DS3231_ReadTime(&timer);
                LCD_BackLight(7);
            }
            M_ON_flag = 0; //���ѵ���Ч���
        } else { //ON �ر�            
            SM_Zero(); //���������λ
            if (F100ms) {
                F100ms = 0;
                if (bLCD_RESET) {
                    bLCD_RESET = 0;
                    //LCD_Init();
                    LCD_BackLight(0);
                }
                OC1RS = 0; //�ر�С��

                POUT_Clear();
                LED_Clear();
                LED_Out();

                if (M_ON) {
                    SYSTME_Logic();
                    if (wake_up1) {
                        LED4 = FLASH; //��ת�򱨾�
                        LED8 = FLASH; //��ת�򱨾�   
                        BUZZ = !(LED8 || LED4); //ת�����
                    } else {
                        LED4 = 0; //��ת�򱨾�
                        LED8 = 0; //��ת�򱨾�   
                        BUZZ = !(LED8 || LED4); //ת�����
                    }
                } else if (wake_up1) {//���Σ�ձ�������
                    F_PO6 = FLASH;
                    F_PO7 = FLASH;
                    T_PO15 = F_PO7; //��ת���
                    T_PO2 = F_PO6; //��ת���
                    //R_PO5 = F_PO7; //��ת���
                    //R_PO7 = F_PO6; //��ת���
                    LED4 = F_PO7; //��ת�򱨾�
                    LED8 = F_PO6; //��ת�򱨾�   
                    BUZZ = !(LED8 || LED4); //ת�����
                } else {
                    POUT_Clear();
                    LED_Clear();
                }
                
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

                if ((task == 6) && (wake_up3 == 0) && (wake_up1 == 0) && (wake_up2 == 0)) {//����������㣬׼���жϵ�Դ;
                    POUT_Clear();
                    __delay_us(500); //�ж����BCAN����50ms����һ�Σ�����������������״̬�������Ѿ�����
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
