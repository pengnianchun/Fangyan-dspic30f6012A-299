#ifndef APP_CHAR_H
#define	APP_CHAR_H

#include "APP_FONT.h"

/********************************菜单选项**************************************/
//仪表系统信息
__prog__ const unsigned char * IC_SYSTEM[] = {BMP_IC, BMP_STSTEM, BMP_Message, 0};
//电池信息
__prog__ const unsigned char * Battery_SYSTEM[] = {BMP_Battery, BMP_Message, 0};
//电机系统信息
__prog__ const unsigned char * MOTO_SYSTEM[] = {BMP_MOTO, BMP_STSTEM, BMP_Message, 0};
//电池管理系统信息
__prog__ const unsigned char * BMS_SYSTEM[] = {BMP_Battery, BMP_Manage, BMP_STSTEM, BMP_Message, 0};
//空调系统信息
__prog__ const unsigned char * AC_SYSTEM[] = {BMP_Air, BMP_STSTEM, BMP_Message, 0};
//DCDC系统信息
__prog__ const unsigned char * DCDC_SYSTEM[] = {BMP_DCDC, BMP_STSTEM, BMP_Message, 0};
//气泵系统信息
__prog__ const unsigned char * AIR_SYSTEM[] = {BMP_QIBENG, BMP_STSTEM, BMP_Message, 0};
//油泵系统信息
__prog__ const unsigned char * OIL_SYSTEM[] = {BMP_YOUBENG, BMP_STSTEM, BMP_Message, 0};
/******************************************************************************/
#endif	/* APP_CHAR_H */

