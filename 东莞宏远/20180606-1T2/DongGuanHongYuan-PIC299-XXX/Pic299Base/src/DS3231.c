#include "BSP.h"

#define DS3231_SLAVE_ADDR              0xD0
#define DS3231_SLAVE_ADDR_RD           0xD1
#define DS3231_SLAVE_ADDR_WR           0xD0


//DS3231的寄存器（开始）地址
#define DS3231_REG_BEGIN_ADDR       0x00
#define DS3231_TIME_BEGIN_ADDR      0x00
#define DS3231_ALARM1_BEGIN_ADDR    0x07
#define DS3231_ALARM2_BEGIN_ADDR    0x0B
#define DS3231_CTRL_ADDR            0x0E
#define DS3231_CTRL_STATUS_ADDR     0x0F
#define DS3231_OFFSET_ADDR          0x10
#define DS3231_TEMP_BEGIN_ADDR      0x11


extern void I2CWriteBytesToSlave(unsigned char sad, unsigned sub, unsigned char *pdata, unsigned char len);
extern unsigned char I2CReadBytesFromSlave(unsigned char sad, unsigned char sub, unsigned char *pdata, unsigned char len);

DATE timer;

unsigned char bcd2bin(unsigned char bcd) {
    unsigned char dump;
    unsigned char dig;
    unsigned char dec;
    
    dig = bcd & 0x0f;
    dec = (bcd >> 4)*10;
    dump = dig + dec;
    return (dump);
}

unsigned char bin2bcd(unsigned char bin) {
    unsigned char dump;
    unsigned char dig;
    unsigned char dec;

    dig = bin % 10;
    dec = ((bin / 10) << 4);

    dump = dig + dec;
    return (dump);

}

/******************************************************************************
 *   功能：  从DS3231读取时间
 *   输出：  pTime 保存从DS3231读取到的时间的指针
    说明：  时间寄存器组7个字节定长
 ******************************************************************************/
void DS3231_ReadTime(DATE *pTime) {
    unsigned char buf[7];

    I2CReadBytesFromSlave(DS3231_SLAVE_ADDR,
            DS3231_TIME_BEGIN_ADDR,
            &buf[0], 7);
    
    pTime->byte[0] = buf[0];
    pTime->byte[1] = buf[1];
    pTime->byte[2] = buf[2];
    pTime->byte[3] = buf[3];
    pTime->byte[4] = buf[4];
    pTime->byte[5] = buf[5];
    pTime->byte[6] = buf[6];
}


//读取温度值

unsigned char DS3231_ReadTemp(void) {
    unsigned char buf;

    I2CReadBytesFromSlave(DS3231_SLAVE_ADDR,
            DS3231_TEMP_BEGIN_ADDR,
            &buf, 1);

    return buf;
}

/******************************************************************************
 *   功能：  设置DS3231的时间寄存器
 *   输入：  pTime 待设置的时间内容的指针
    说明：  时间寄存器组7个字节定长
 ******************************************************************************/
void DS3231_SetTime(DATE *pTime) {
    
    unsigned char buf[7];
    buf[0] = pTime->second;
    buf[1] = pTime->minute;
    buf[2] = pTime->hour;
    buf[3] = pTime->week;
    buf[4] = pTime->day;
    buf[5] = pTime->month;
    buf[6] = pTime->year;
    I2CWriteBytesToSlave(DS3231_SLAVE_ADDR,
            DS3231_TIME_BEGIN_ADDR,
            buf, 7);
}





