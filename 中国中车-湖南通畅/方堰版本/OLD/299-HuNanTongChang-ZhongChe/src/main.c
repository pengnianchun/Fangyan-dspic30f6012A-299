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
    unsigned int temp = 0;
    System_Init();
    while (1) {
        ClrWdt();
        if(F50ms){
            F50ms=0;
            SW_Input();
        }
        if (wake_up2 && !M_ON) {
            M_ON_flag = 1;//���ѵ���Ч���
            PWR_CTRL_DR = 0;
            PWR_CTRL = 1;
            bLCD_RESET = 1;
            LCD_Exec(); //ֱ��ִ�л�Ӱ������ԭ��δ֪
            SM_Zero(); //���������λ
            /*
            if (F100ms) {
                F100ms = 0;
                LED_Logic();
                LED_Out();
            }*/
            if (F500ms) { //
                F500ms = 0;
                Count_ADR(); //����ģ������ֵ  ������Ӱ������������ʱ��
                DS3231_ReadTime(&timer);
            }
            M_ON_flag=0;//���ѵ���Ч���
        }         
        if (M_ON) {// ON �պ�   
            M_ON_flag = 1;//ON����Ч���
            PWR_CTRL_DR = 0;
            PWR_CTRL = 1;
            bLCD_RESET = 1;           
            pSpeed = (unsigned int) (Speed_rmp * 0.508 * 2 * 60 * 3.14159 / 1000 / 5.63 * 1.05); //�뾶*2*��*60/1000/���ٱ�
            sm_new_value[0] = pSpeed * 132 / 7;
            SM_Update_0(); //���ٱ�
            sm_new_value[5] = (unsigned int) (Engine_Speed * 0.66);
            SM_Update_5(); //ת�ٱ�   �Ƕ�220�� 2640

            if (task == 0) {
                task = 1;
                LCD_Exec();
            } else if (task == 1) {
                task = 2;                 
                temp = water_temp;//����ˮ�±���� ���ֵ1152  �����Ƕ�96��
                if (temp > 160)
                    sm_new_value[4] = 1152;
                else if (temp < 80)
                    sm_new_value[4] = 0;
                else sm_new_value[4] = (unsigned int) ((temp - 80)*14.4);
                SM_Update_4(); //ˮ�±�
            } else if (task == 2) {
                task = 3;               
                temp = ADR[5];
                if (temp <= 3) {//���ֵΪ1152Ϊ��
                    sm_new_value[3] = 0;
                } else if (temp > 180) {
                    sm_new_value[3] = 1152;
                } else if (temp <= 90) {
                    sm_new_value[3] = (unsigned int) (6.62 * (temp - 3));
                } else {
                    sm_new_value[3] = (unsigned int) (6.4 * temp);
                }
                SM_Update_3(); //������
            } else if (task == 3) {
                task = 4;
                temp = Engine_oil_press*4;
                if (temp >= 1000) {
                    sm_new_value[2] = 1152;
                }
                sm_new_value[2] = (unsigned int) (temp * 1.152);
                SM_Update_2(); //����ѹ����
            } else if (task == 4) {
                task = 5;
                temp = ADV[0];
                if (temp < 180) { //���µ�ѹ�����ADR[5]
                    sm_new_value[1] = 0;
                } else if ((temp >= 180)&&(temp < 240)) {
                    sm_new_value[1] = (unsigned int) (6.667 * (temp - 180));
                } else if ((temp >= 240)&&(temp <= 320)) {
                    sm_new_value[1] = (unsigned int) (10 * (temp - 240)) + 400;
                } else {
                    sm_new_value[1] = 1200;
                }
                SM_Update_1(); //��ѹ�� 
            } else if (task == 5) {
                task = 0;
                if (F500ms) { //
                    F500ms = 0;  
                    Count_ADR(); //����ģ������ֵ  ������Ӱ������������ʱ��
                    DS3231_ReadTime(&timer); //��ȡʱ��          
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
            M_ON_flag=0;//ON����Ч���
        } else if(M_ON==0 && wake_up2==0){ //ON �ر�            
            SM_Zero(); //���������λ
            if (F100ms) {
                F100ms = 0;
                if (bLCD_RESET) {
                    bLCD_RESET = 0;
                    LCD_Init();
                }               
                LCD_BackLight(0);               
                OC1RS = 0; //�ر�С��
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
                LED_Out();                    
                if((task == 6) && wake_up1) break;               
                /*
                if (wake_up1) { //Σ�ձ������ؿ���   
                    F_PO9 = FLASH;
                    F_PO10 = FLASH;
                    M_PO7 = FLASH;
                    M_PO8 = FLASH;
                    //BUZZ = !FLASH;
                } else {
                    F_PO9 = 0;
                    F_PO10 = 0;
                    M_PO7 = 0;
                    M_PO8 = 0;
                }
                 LED4 = M_PO7; //��ת���
                 LED8 = M_PO8; //��ת���                
                 LED_Out();   
                   */        
                if ((task == 6)&& (wake_up3 == 0) && (wake_up1 == 0) && (wake_up2 == 0)) {//����������㣬׼���жϵ�Դ
                    __delay_us(100);//�ж����BCAN����50ms����һ�Σ�����������������״̬�������Ѿ�����
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
