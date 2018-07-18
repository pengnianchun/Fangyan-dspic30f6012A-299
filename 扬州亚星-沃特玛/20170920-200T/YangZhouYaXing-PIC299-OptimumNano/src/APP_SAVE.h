/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef APP_SAVE_H
#define	APP_SAVE_H

extern unsigned long e_total_miles;
extern unsigned int e_address; //EEPROM¥Ê¥¢µÿ÷∑
extern unsigned int e_single_miles;
extern unsigned int e_backlight;
extern unsigned int e_hm_pulse;

void EEROM_WriteBackLight(void);

void EEROM_ReadBackLight(void);

void EEROM_WriteHMPulse(void);

void EEROM_ReadHMPulse(void);

void EEROM_WriteSingleMiles(void);

void EEROM_ReadSingleMiles(void);

void EEROM_WriteTotalMiles(void);

void EEROM_ReadTotalMiles(void);

void EEROM_WriteAddress(void);

void EEROM_ReadAddress(void);

#endif	/* APP_SAVE_H */

