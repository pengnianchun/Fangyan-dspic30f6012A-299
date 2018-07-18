/* 
 * File:   newmain.c
 * Author: mpszm
 *
 * Created on 2016年8月1日, 上午9:59
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
/*
 * 
 */

const unsigned char  Bmp001[]=
{
/*------------------------------------------------------------------------------
;  若数据乱码，请检查字模格式设置，注意选择正确的取模方向和字节位顺序。
;  源文件 / 文字 : 字模
;  宽×高（像素）: 30×15
;  字模格式/大小 : 单色点阵液晶字模，横向取模，字节正序/60字节
;  数据转换日期  : 2016-8-1 9:24:31
------------------------------------------------------------------------------*/
0x1E,0x0F,0x04,//宽的像素数,高的像素数，宽的字节数，参数设置可选
0x02,0x00,0x22,0x20,0x01,0x00,0x22,0x20,0x7F,0xFC,0x27,0xF8,0x40,0x04,0xF2,0x20,
0x40,0x04,0x27,0xF0,0x1F,0xE0,0x24,0x10,0x00,0x40,0x77,0xF0,0x00,0x80,0x6C,0x10,
0x01,0x00,0xA7,0xF0,0x7F,0xFC,0x20,0x80,0x01,0x00,0x2F,0xF8,0x01,0x00,0x21,0x40,
0x01,0x00,0x22,0x20,0x07,0x00,0x2C,0x18,0x00,0x00,0x00,0x00,
};

int main(void) {
     ADPCFG=0xFF00;
    
     LCD_Init();
    while(1){
        LCD_DrawImage1BPP(10,10,Bmp001,BRIGHTRED,BLACK);
      
        LCD_DrawImage1BPPZOOM_1(60,60,Bmp001,BRIGHTRED,BLACK);
        
        LCD_DrawImage1BPPZOOM_4(100,100,Bmp001,BRIGHTRED,BLACK);
    }
}

