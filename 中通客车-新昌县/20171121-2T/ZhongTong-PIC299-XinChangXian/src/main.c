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

int main(void) {
    unsigned char task = 0;
    unsigned char Task = 0;
    unsigned int temp = 0;
    unsigned char menu = 0;
    unsigned char count = 10;
    System_Init();
    while (1) {
        ClrWdt();
        if (F50ms) {
            F50ms = 0;
            SW_Input();
        }
        if (M_ON) {// ON �պ� || M_ON 
            M_ON_flag = 1; //ON����Ч���
            PWR_CTRL_DR = 0;
            PWR_CTRL = 1;
            if (menu == 0) {
                menu = 1;
                LCD_Init();
                frmID = 0;
                f_index = 0;
            }

            //Vspeed = (30.0 * DJ_speed) / e_hm_pulse; //���ٵ�λ0.1KM/H
            Vspeed = (unsigned int) ((unsigned long) 3600 * freq[0] / e_hm_pulse); //���ٵ�λ0.1KM/H
            pSpeed = Vspeed / 10;

            if (Vspeed < 1400)sm_new_value[0] = (unsigned int) (Vspeed * 1.885);
            else sm_new_value[0] = 2640;
            SM_Update_0(); //���ٱ�   �Ƕ�220�� 2640

            //if(DJ_speed<16000)sm_new_value[5]=(unsigned int) (DJ_speed*0.165);
            //else              sm_new_value[5]=2640;
            if (EngineSpeed >= 32000) EngineSpeed = 32010; //�����4000RPM
            sm_new_value[5] = (unsigned int) (0.0825 * EngineSpeed);
            SM_Update_5(); //ת�ٱ�   �Ƕ�220�� 2640

            if (task == 0) {
                task = 1;
                LCD_Exec();
            } else if (task == 1) {
                task = 2;
                //��ѹ1
                //temp = ADV[3]/10;
                //      if(temp<50 )sm_new_value[4] = 0;
                //else  if(temp<300)sm_new_value[4] = (unsigned int)( 4.608*(temp-50));
                //else              sm_new_value[4] = 1152;

                //����ˮ�±����
                if (WaterTem < 80) {
                    sm_new_value[4] = 0;
                } else if (WaterTem > 160) {
                    sm_new_value[4] = 1152; //96deg
                } else {
                    sm_new_value[4] = (unsigned int) (14.41 * ((unsigned int) (WaterTem) - 80));
                }
                if (ECU_TIME >= CAN_TIME)sm_new_value[4] = 0; //���ݶ�ʧ��0
                SM_Update_4();
            } else if (task == 2) {
                task = 3;
                //temp = DC_SOC*0.4;//SOC
                //if (temp <= 0) {//���ֵΪ1152Ϊ��
                //    sm_new_value[3] = 0;
                //} else if (temp > 100) {
                //    sm_new_value[3] = 1152;
                //} else {
                //    sm_new_value[3] = (unsigned int) (11.52 * temp);
                //}
                //SM_Update_3(); 
                temp = ADR[5]; //����
                if (temp >= 110) {
                    sm_new_value[3] = 0;
                } else if (temp > 70) {
                    sm_new_value[3] = (unsigned int) (288 - 7.2 * (temp - 70));
                } else if (temp > 33) {
                    sm_new_value[3] = (unsigned int) (576 - 7.8 * (temp - 33));
                } else if (temp > 3) {
                    sm_new_value[3] = (unsigned int) (1152 - 19.2 * (temp - 3));
                } else
                    sm_new_value[3] = 1152;
                SM_Update_3();
            } else if (task == 3) {
                task = 4;
                //temp = ADV[4]/10;//��ѹ2
                //      if(temp<50 )sm_new_value[2] = 0;
                //else  if(temp<300)sm_new_value[2] = (unsigned int)( 4.608*(temp-50));
                //else              sm_new_value[2] = 1152;

                sm_new_value[2] = (unsigned int) (4.6 * engine_oil_press); //����ѹ��ȡCAN
                SM_Update_2();
            } else if (task == 4) {
                task = 5;
                /*
                //����ʹ��
                temp = ADR[0];
                if (temp < 160) { //���µ�ѹ�����ADR[5]
                    sm_new_value[1] = 0;
                } else if ((temp >= 160)&&(temp < 320)) {
                    sm_new_value[1] = (unsigned int) (7.2 * (temp - 160));
                } else {
                    sm_new_value[1] = 1152;
                }    
                 */
                //ȼ�ͳ�����
                temp = ADR[0];
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

                    if (Task == 0) {
                        Task = 1;
                        //Pcan_send_yb5();//����������
                    } else if (Task == 1) {
                        Task = 2;
                        //Pcan_send_yb6();//����������
                    } else if (Task == 2) {
                        Task = 3;
                        //Pcan_send_yb7();//����������
                    } else if (Task == 3) {
                        Task = 0;
                        //PCAN_send_mile();//��� 
                        //PCAN_send_time();//ʱ��                        
                    }

                    LCD_BackLight(7); //

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
            M_ON_flag = 0; //ON����Ч���
        } else { //ON �ر�            
            SM_Zero(); //���������λ
            if (menu == 1) {               
                if (M_ACC) {
                    menu = 0;
                    LCD_Init();
                    disp_LOGO();
                }
            }

            if (F50ms1) {
                F50ms1 = 0;
                if (M_ACC) {
                    LCD_BackLight(7);
                    disp_Door();
                    LED10 = 1; //�ܵ�Դָʾ    
                } else {
                    LCD_BackLight(0);
                    LED10 = 0; //�ܵ�Դָʾ 
                }
                OC1RS = 0; //�ر�С��

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
                /*
                if (wake_up1) { //Σ�ձ������ؿ���   
                    F_PO14 = kFLASH; //FLASH;
                    F_PO15 = kFLASH; //FLASH;
                } else {
                    F_PO14 = 0;
                    F_PO15 = 0;
                }
                T_PO3 = F_PO14; //��ת���
                T_PO4 = F_PO15; //��ת���
                LED4 = F_PO14; //��ת�򱨾�
                LED8 = F_PO15; //��ת�򱨾�   
                BUZZ = !(LED8 || LED4); //ת�����
                 */
                SYSTME_Logic();
                //LED4 = F_PO14; //��ת�򱨾�
                //LED8 = F_PO15; //��ת�򱨾�  
                if (wake_up1 == 0) {
                    LED4 = 0;
                    LED8 = 0;
                }
                //BUZZ  = !(LED8 || LED4); //ת����� 
                //if (wake_up1)BUZZ = !FLASH;
                else BUZZ = 1;

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
                    while (count-- != 0) {
                        gCTL[0].byte = 0x00;
                        gCTL[1].byte = 0x00;
                        gCTL[2].byte = 0x00;
                        gCTL[3].byte = 0x00;
                        gCTL[4].byte = 0x00;
                        gCTL[5].byte = 0x00;
                        gCTL[6].byte = 0x00;
                        gCTL[7].byte = 0x00;
                        __delay_us(200);
                        BCAN_SendCtl();
                    }
                    gCTL[0].byte = 0x00;
                    gCTL[1].byte = 0x00;
                    gCTL[2].byte = 0x00;
                    gCTL[3].byte = 0x00;
                    gCTL[4].byte = 0x00;
                    gCTL[5].byte = 0x00;
                    gCTL[6].byte = 0x00;
                    gCTL[7].byte = 0x00;
                    __delay_us(100); //�ж����BCAN����50ms����һ�Σ�����������������״̬�������Ѿ�����
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
