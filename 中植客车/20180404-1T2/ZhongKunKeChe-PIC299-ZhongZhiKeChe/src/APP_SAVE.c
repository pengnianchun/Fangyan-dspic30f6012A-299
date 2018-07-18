#include "APP_System.h"

//总里程定义
unsigned long e_total_miles = TOTAL_MILES;
unsigned int e_address = MT_ADDR; //EEPROM存储地址
unsigned int e_single_miles = SINGLE_MILES;
unsigned int e_backlight = BACKLIGHT;
unsigned int e_hm_pulse = HM_PLUSE;

//总里程计数
//总里程数低位EEROM
unsigned int _EEDATA(2) EE_TOTAL_MILES_LOW_1[16] = {
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 0) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 1) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 2) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 3) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 4) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 5) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 6) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 7) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 8) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 9) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 10) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 11) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 12) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 13) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 14) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 15) ? (1) : (0))),
};
unsigned int _EEDATA(2) EE_TOTAL_MILES_LOW_2[16] = {
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 0) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 1) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 2) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 3) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 4) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 5) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 6) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 7) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 8) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 9) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 10) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 11) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 12) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 13) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 14) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 15) ? (1) : (0))),
};
unsigned int _EEDATA(2) EE_TOTAL_MILES_LOW_3[16] = {
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 0) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 1) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 2) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 3) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 4) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 5) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 6) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 7) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 8) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 9) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 10) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 11) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 12) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 13) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 14) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 15) ? (1) : (0))),
};

//总里程数高位EEROM
unsigned int _EEDATA(2) EE_TOTAL_MILES_HIGH_1 = (TOTAL_MILES >> 16);
unsigned int _EEDATA(2) EE_TOTAL_MILES_HIGH_2 = (TOTAL_MILES >> 16);
unsigned int _EEDATA(2) EE_TOTAL_MILES_HIGH_3 = (TOTAL_MILES >> 16);

unsigned int _EEDATA(2) EE_SINGLE_MILES_LOW_1[16] = {
    ((SINGLE_MILES / 16) + (((SINGLE_MILES % 16) > 0) ? (1) : (0))),
    ((SINGLE_MILES / 16) + (((SINGLE_MILES % 16) > 1) ? (1) : (0))),
    ((SINGLE_MILES / 16) + (((SINGLE_MILES % 16) > 2) ? (1) : (0))),
    ((SINGLE_MILES / 16) + (((SINGLE_MILES % 16) > 3) ? (1) : (0))),
    ((SINGLE_MILES / 16) + (((SINGLE_MILES % 16) > 4) ? (1) : (0))),
    ((SINGLE_MILES / 16) + (((SINGLE_MILES % 16) > 5) ? (1) : (0))),
    ((SINGLE_MILES / 16) + (((SINGLE_MILES % 16) > 6) ? (1) : (0))),
    ((SINGLE_MILES / 16) + (((SINGLE_MILES % 16) > 7) ? (1) : (0))),
    ((SINGLE_MILES / 16) + (((SINGLE_MILES % 16) > 8) ? (1) : (0))),
    ((SINGLE_MILES / 16) + (((SINGLE_MILES % 16) > 9) ? (1) : (0))),
    ((SINGLE_MILES / 16) + (((SINGLE_MILES % 16) > 10) ? (1) : (0))),
    ((SINGLE_MILES / 16) + (((SINGLE_MILES % 16) > 11) ? (1) : (0))),
    ((SINGLE_MILES / 16) + (((SINGLE_MILES % 16) > 12) ? (1) : (0))),
    ((SINGLE_MILES / 16) + (((SINGLE_MILES % 16) > 13) ? (1) : (0))),
    ((SINGLE_MILES / 16) + (((SINGLE_MILES % 16) > 14) ? (1) : (0))),
    ((SINGLE_MILES / 16) + (((SINGLE_MILES % 16) > 15) ? (1) : (0))),
};
unsigned int _EEDATA(2) EE_SINGLE_MILES_LOW_2[16] = {
    ((SINGLE_MILES / 16) + (((SINGLE_MILES % 16) > 0) ? (1) : (0))),
    ((SINGLE_MILES / 16) + (((SINGLE_MILES % 16) > 1) ? (1) : (0))),
    ((SINGLE_MILES / 16) + (((SINGLE_MILES % 16) > 2) ? (1) : (0))),
    ((SINGLE_MILES / 16) + (((SINGLE_MILES % 16) > 3) ? (1) : (0))),
    ((SINGLE_MILES / 16) + (((SINGLE_MILES % 16) > 4) ? (1) : (0))),
    ((SINGLE_MILES / 16) + (((SINGLE_MILES % 16) > 5) ? (1) : (0))),
    ((SINGLE_MILES / 16) + (((SINGLE_MILES % 16) > 6) ? (1) : (0))),
    ((SINGLE_MILES / 16) + (((SINGLE_MILES % 16) > 7) ? (1) : (0))),
    ((SINGLE_MILES / 16) + (((SINGLE_MILES % 16) > 8) ? (1) : (0))),
    ((SINGLE_MILES / 16) + (((SINGLE_MILES % 16) > 9) ? (1) : (0))),
    ((SINGLE_MILES / 16) + (((SINGLE_MILES % 16) > 10) ? (1) : (0))),
    ((SINGLE_MILES / 16) + (((SINGLE_MILES % 16) > 11) ? (1) : (0))),
    ((SINGLE_MILES / 16) + (((SINGLE_MILES % 16) > 12) ? (1) : (0))),
    ((SINGLE_MILES / 16) + (((SINGLE_MILES % 16) > 13) ? (1) : (0))),
    ((SINGLE_MILES / 16) + (((SINGLE_MILES % 16) > 14) ? (1) : (0))),
    ((SINGLE_MILES / 16) + (((SINGLE_MILES % 16) > 15) ? (1) : (0))),
};
unsigned int _EEDATA(2) EE_SINGLE_MILES_LOW_3[16] = {
    ((SINGLE_MILES / 16) + (((SINGLE_MILES % 16) > 0) ? (1) : (0))),
    ((SINGLE_MILES / 16) + (((SINGLE_MILES % 16) > 1) ? (1) : (0))),
    ((SINGLE_MILES / 16) + (((SINGLE_MILES % 16) > 2) ? (1) : (0))),
    ((SINGLE_MILES / 16) + (((SINGLE_MILES % 16) > 3) ? (1) : (0))),
    ((SINGLE_MILES / 16) + (((SINGLE_MILES % 16) > 4) ? (1) : (0))),
    ((SINGLE_MILES / 16) + (((SINGLE_MILES % 16) > 5) ? (1) : (0))),
    ((SINGLE_MILES / 16) + (((SINGLE_MILES % 16) > 6) ? (1) : (0))),
    ((SINGLE_MILES / 16) + (((SINGLE_MILES % 16) > 7) ? (1) : (0))),
    ((SINGLE_MILES / 16) + (((SINGLE_MILES % 16) > 8) ? (1) : (0))),
    ((SINGLE_MILES / 16) + (((SINGLE_MILES % 16) > 9) ? (1) : (0))),
    ((SINGLE_MILES / 16) + (((SINGLE_MILES % 16) > 10) ? (1) : (0))),
    ((SINGLE_MILES / 16) + (((SINGLE_MILES % 16) > 11) ? (1) : (0))),
    ((SINGLE_MILES / 16) + (((SINGLE_MILES % 16) > 12) ? (1) : (0))),
    ((SINGLE_MILES / 16) + (((SINGLE_MILES % 16) > 13) ? (1) : (0))),
    ((SINGLE_MILES / 16) + (((SINGLE_MILES % 16) > 14) ? (1) : (0))),
    ((SINGLE_MILES / 16) + (((SINGLE_MILES % 16) > 15) ? (1) : (0))),
};


//百米脉冲数EEROM备份
unsigned int _EEDATA(2) EE_HM_PLUSE_1 = HM_PLUSE;
unsigned int _EEDATA(2) EE_HM_PLUSE_2 = HM_PLUSE;
unsigned int _EEDATA(2) EE_HM_PLUSE_3 = HM_PLUSE;

///保存 背光亮度数据
unsigned int _EEDATA(2) EE_BACKLIGHT_1 = BACKLIGHT;
unsigned int _EEDATA(2) EE_BACKLIGHT_2 = BACKLIGHT;
unsigned int _EEDATA(2) EE_BACKLIGHT_3 = BACKLIGHT;

////模块地址EEROM备份 0x01 为前部模块 0x02 为后模块 0x03 为顶部模块 仪表为0x04
unsigned int _EEDATA(2) EE_ADDRESS_1 = MT_ADDR; //地址
unsigned int _EEDATA(2) EE_ADDRESS_2 = MT_ADDR;
unsigned int _EEDATA(2) EE_ADDRESS_3 = MT_ADDR;

unsigned int __attribute__((address(0x7FFFFE))) _EEDATA(2) EE_BT_ADDRESS = MT_ADDR; //BootLoader 地址

void EEROM_WriteBackLight(void) {
    EEROM_WriteWord(__builtin_tbladdress(&EE_BACKLIGHT_1), e_backlight);
    EEROM_WriteWord(__builtin_tbladdress(&EE_BACKLIGHT_2), e_backlight);
    EEROM_WriteWord(__builtin_tbladdress(&EE_BACKLIGHT_3), e_backlight);
}

void EEROM_ReadBackLight(void) {
    unsigned int dump[3] = {0, 0, 0};
    dump[0] = EEROM_ReadWord(__builtin_tbladdress(&EE_BACKLIGHT_1));
    dump[1] = EEROM_ReadWord(__builtin_tbladdress(&EE_BACKLIGHT_1));
    dump[2] = EEROM_ReadWord(__builtin_tbladdress(&EE_BACKLIGHT_1));

    if (dump[0] == dump[1]) e_backlight = dump[0];
    else if (dump[1] == dump[2]) e_backlight = dump[1];
    else if (dump[2] == dump[1]) e_backlight = dump[2];
    else e_backlight = BACKLIGHT;
}

void EEROM_WriteHMPulse(void) {
    EEROM_WriteWord(__builtin_tbladdress(&EE_HM_PLUSE_1), e_hm_pulse);
    EEROM_WriteWord(__builtin_tbladdress(&EE_HM_PLUSE_2), e_hm_pulse);
    EEROM_WriteWord(__builtin_tbladdress(&EE_HM_PLUSE_3), e_hm_pulse);
}

void EEROM_ReadHMPulse(void) {
    unsigned int dump[3] = {0, 0, 0};
    dump[0] = EEROM_ReadWord(__builtin_tbladdress(&EE_HM_PLUSE_1));
    dump[1] = EEROM_ReadWord(__builtin_tbladdress(&EE_HM_PLUSE_2));
    dump[2] = EEROM_ReadWord(__builtin_tbladdress(&EE_HM_PLUSE_3));

    if (dump[0] == dump[1]) e_hm_pulse = dump[0];
    else if (dump[1] == dump[2]) e_hm_pulse = dump[1];
    else if (dump[2] == dump[1]) e_hm_pulse = dump[2];
    else e_hm_pulse = HM_PLUSE;
}

void EEROM_WriteSingleMiles(void) {
    EEROM_WriteLowMiles(__builtin_tbladdress(&EE_SINGLE_MILES_LOW_1), e_single_miles);
    EEROM_WriteLowMiles(__builtin_tbladdress(&EE_SINGLE_MILES_LOW_2), e_single_miles);
    EEROM_WriteLowMiles(__builtin_tbladdress(&EE_SINGLE_MILES_LOW_3), e_single_miles);
}

void EEROM_ReadSingleMiles(void) {
    unsigned int dump[3];
    dump[0] = EEROM_ReadLowMiles(__builtin_tbladdress(&EE_SINGLE_MILES_LOW_1)); //原来是EE_TOTAL_MILES_HIGH
    dump[1] = EEROM_ReadLowMiles(__builtin_tbladdress(&EE_SINGLE_MILES_LOW_2)); //改为EE_SINGLE_MILES_LOW
    dump[2] = EEROM_ReadLowMiles(__builtin_tbladdress(&EE_SINGLE_MILES_LOW_3));

    if (dump[0] == dump[1]) e_single_miles = dump[0];
    else if (dump[1] == dump[2]) e_single_miles = dump[1];
    else if (dump[2] == dump[1]) e_single_miles = dump[2];
    else e_single_miles = 0;

}

void EEROM_WriteTotalMiles(void) {
    unsigned int high = 0;
    unsigned int low = 0;

    high = (e_total_miles >> 16);
    EEROM_WriteWord(__builtin_tbladdress(&EE_TOTAL_MILES_HIGH_1), high);
    EEROM_WriteWord(__builtin_tbladdress(&EE_TOTAL_MILES_HIGH_2), high);
    EEROM_WriteWord(__builtin_tbladdress(&EE_TOTAL_MILES_HIGH_3), high);

    low = (unsigned int) e_total_miles;
    EEROM_WriteLowMiles(__builtin_tbladdress(&EE_TOTAL_MILES_LOW_1), low);
    EEROM_WriteLowMiles(__builtin_tbladdress(&EE_TOTAL_MILES_LOW_2), low);
    EEROM_WriteLowMiles(__builtin_tbladdress(&EE_TOTAL_MILES_LOW_3), low);
}

void EEROM_ReadTotalMiles(void) {
    unsigned int low[3] = {0, 0, 0};
    unsigned int high[3] = {0, 0, 0};

    unsigned int dump_l = 0;
    unsigned int dump_h = 0;

    low[0] = EEROM_ReadLowMiles(__builtin_tbladdress(&EE_TOTAL_MILES_LOW_1));
    low[1] = EEROM_ReadLowMiles(__builtin_tbladdress(&EE_TOTAL_MILES_LOW_2));
    low[2] = EEROM_ReadLowMiles(__builtin_tbladdress(&EE_TOTAL_MILES_LOW_3));

    if (low[0] == low[1]) dump_l = low[0];
    else if (low[1] == low[2]) dump_l = low[1];
    else if (low[2] == low[0]) dump_l = low[2];
    else dump_l = low[2]; //读取最后一直值

    high[0] = EEROM_ReadWord(__builtin_tbladdress(&EE_TOTAL_MILES_HIGH_1));
    high[1] = EEROM_ReadWord(__builtin_tbladdress(&EE_TOTAL_MILES_HIGH_2));
    high[2] = EEROM_ReadWord(__builtin_tbladdress(&EE_TOTAL_MILES_HIGH_3));

    if (high[0] == high[1]) dump_h = high[0];
    else if (high[1] == high[2]) dump_h = high[1];
    else if (high[2] == high[0]) dump_h = high[2];
    else {
        if (high[0] != 0xFFFF) dump_h = high[0];
        else if (high[1] != 0xFFFF) dump_h = high[1];
        else if (high[2] != 0xFFFF) dump_h = high[2];
    }

    e_total_miles = ((unsigned long) dump_h << 16) + dump_l;
}

void EEROM_WriteAddress(void) {
    EEROM_WriteWord(__builtin_tbladdress(&EE_ADDRESS_1), e_address);
    EEROM_WriteWord(__builtin_tbladdress(&EE_ADDRESS_2), e_address);
    EEROM_WriteWord(__builtin_tbladdress(&EE_ADDRESS_3), e_address);
    EEROM_WriteWord(__builtin_tbladdress(&EE_BT_ADDRESS), e_address);
}

void EEROM_ReadAddress(void) {
    unsigned int dump[3] = {0, 0, 0};
    dump[0] = EEROM_ReadWord(__builtin_tbladdress(&EE_ADDRESS_1));
    dump[1] = EEROM_ReadWord(__builtin_tbladdress(&EE_ADDRESS_1));
    dump[2] = EEROM_ReadWord(__builtin_tbladdress(&EE_ADDRESS_1));

    if (dump[0] == dump[1]) e_address = dump[0];
    else if (dump[1] == dump[2]) e_address = dump[1];
    else if (dump[2] == dump[1]) e_address = dump[2];
    else e_address = 0;
}