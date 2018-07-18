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
    unsigned int  temp = 0;
    unsigned char menu=0;
    unsigned char count=10;
    System_Init();
    while (1) {
        ClrWdt();
        if(F50ms){
            F50ms=0;
            SW_Input();
        }
        
        if (M_ON) {// ON 闭合   
            M_ON_flag = 1;//ON当有效标记
            PWR_CTRL_DR = 0;
            PWR_CTRL = 1;
            if(menu==0){
               menu=1;LCD_Init();frmID=0;f_index=0;
            }
            
            Vspeed = (60.0 * DJ_speed) / e_hm_pulse; //车速单位0.1KM/H
            if(Vspeed<1400)sm_new_value[0] = (unsigned int) (Vspeed*1.885);
            else           sm_new_value[0] = 2640; 
            SM_Update_0(); //车速表   角度220° 2640
            
            if(DJ_speed<8000)sm_new_value[5]=(unsigned int) (DJ_speed*0.33);
            else             sm_new_value[5]=2640;
            SM_Update_5(); //转速表   角度220° 2640

            if (task == 0) {
                task = 1;
                LCD_Exec();
            } else if (task == 1) {
                task = 2; 
                /*
                temp = ADV[3]/10;
                      if(temp<50 )sm_new_value[4] = 0;
                else  if(temp<300)sm_new_value[4] = (unsigned int)( 4.608*(temp-50));
                else              sm_new_value[4] = 1152;
              */  
                temp = ADR[1];
                      if(temp<10 )sm_new_value[4] = 0;
                else  if(temp<185)sm_new_value[4] = (unsigned int)( 5.485*(temp-10));
                else              sm_new_value[4] = 960;
                
                SM_Update_4(); //气压1
            } else if (task == 2) {
                task = 3;
                temp = DC_SOC*0.4;
                if (temp <= 0) {//电机值为1152为满
                    sm_new_value[3] = 0;
                } else if (temp > 100) {
                    sm_new_value[3] = 1152;
                } else {
                    sm_new_value[3] = (unsigned int) (11.52 * temp);
                }
                SM_Update_3(); //SOC
            } else if (task == 3) {
                task = 4;
                /*
                temp = ADV[4]/10;
                      if(temp<50 )sm_new_value[2] = 0;
                else  if(temp<300)sm_new_value[2] = (unsigned int)( 4.608*(temp-50));
                else              sm_new_value[2] = 1152;
               */       
                temp = ADR[2];
                      if(temp<10 )sm_new_value[2] = 0;
                else  if(temp<185)sm_new_value[2] = (unsigned int)( 5.485*(temp-10));
                else              sm_new_value[2] = 960;
                SM_Update_2(); //气压2
            } else if (task == 4) {
                task = 5;
                temp = ADR[0];
                if (temp < 160) { //更新电压表程序ADR[5]
                    sm_new_value[1] = 0;
                } else if ((temp >= 160)&&(temp < 320)) {
                    sm_new_value[1] = (unsigned int) (7.2 * (temp - 160));
                } else {
                    sm_new_value[1] = 1152;
                }               
                //燃油车表盘
                /*if (temp < 180) { //更新电压表程序ADR[5]
                    sm_new_value[1] = 0;
                } else if ((temp >= 180)&&(temp < 240)) {
                    sm_new_value[1] = (unsigned int) (6.667 * (temp - 180));
                } else if ((temp >= 240)&&(temp <= 320)) {
                    sm_new_value[1] = (unsigned int) (10 * (temp - 240)) + 400;
                } else {
                    sm_new_value[1] = 1200;
                }*/
                SM_Update_1(); //电压表 
            } else if (task == 5) {
                task = 0;
                if (F500ms) { //
                    F500ms = 0;  
                    Count_ADR(); //换算模拟量的值  会严重影响主函数运行时间
                    
                    PCAN_Send_TCO1();                  
                    DS3231_ReadTime(&timer); //读取时间  
                  //PCAN_send_mile();//里程
                    PCAN_Send_TCO2();
                    
                    //以下数据5秒内收不到数据清零
                    if(Vcan_count >= CAN_TIME){
                       VCU_Status[0]=0;
                       VCU_Status[1]=0;        
                       VCU_Status[2]=0;
                       VCU_Status[3]=0;        
                    }
                    if(Bcan_count >= CAN_TIME){
                       DC_Status[0]=0;
                       DC_Status[1]=0;        
                       DC_SOC=0;
                       DC_current=32000;        
                       DC_voltage=0;        
                    }
                    if(Kcan_count >= CAN_TIME){
                       DJ_torque=32000;
                       DJcontroler_voltage=0;
                       DJcontroler_current=32000;
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
            M_ON_flag=0;//ON档有效标记
        } else { //ON 关闭            
            SM_Zero(); //步进电机复位
                if(menu==1){
                    menu=0;
                    if(M_ACC){LCD_Init();}//disp_LOGO();
                }
            
            if (F100ms) {
                F100ms = 0;
                if(M_ACC){
                 //LCD_BackLight(7);
                 //disp_Door();
                   LED10 = 1; //总电源指示    
                }else{
                   LCD_BackLight(0); 
                   LED10 = 0; //总电源指示 
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

                /*
                if (wake_up1) {//如果危险报警唤醒
                    PWR_CTRL_DR = 0;
                    PWR_CTRL = 1;
                    F_PO6 = FLASH;//左转向灯
                    F_PO7 = FLASH;//右转向灯
                } else {
                    F_PO6 = 0;
                    F_PO7 = 0;
                }
                    R_PO6 = F_PO6; //左转向灯
                    R_PO7 = F_PO7; //右转向灯
                    LED4  = F_PO6; //左转向报警
                    LED8  = F_PO7; //右转向报警   
                    BUZZ  = !(LED8 || LED4);//转向蜂鸣
                 */  
                
                SYSTME_Logic();
                LED4 = F_PO6; //左转向报警
                LED8 = F_PO7; //右转向报警  
                if (wake_up1 == 0) {LED4 = 0;LED8 = 0;}
              //BUZZ  = !(LED8 || LED4); //转向蜂鸣 
                if(wake_up1)BUZZ  = !FLASH;else BUZZ  = 1;
                
                LED10 = 1; //总电源指示
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
                
                if ( (task == 6) && (wake_up3 == 0) && (wake_up1 == 0) && (wake_up2 == 0)  ) {//步进电机回零，准备切断电源;
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
                    __delay_us(100);//中断里的BCAN发送50ms发送一次，可能来不及发最后的状态，程序已经结束
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
