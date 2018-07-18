#include "BSP.h"

#define I2C_SCL_DR  _TRISF2
#define I2C_SDA_DR  _TRISF3

#define I2C_SCL     _LATF2
#define I2C_SDA     _LATF3
#define I2C_SDA_RD  _RF3 

void I2CStart(void) {

    I2C_SDA_DR = 1;
    I2C_SCL_DR = 1;
    __delay32(40); //5us
    I2C_SDA_DR = 0;
    I2C_SDA = 0;
    __delay32(40);
    I2C_SCL_DR = 0;
    I2C_SCL = 0;
}

void I2CStop(void) {
    
    I2C_SDA_DR = 0;
    I2C_SDA = 0;
    I2C_SCL_DR = 1;
    __delay32(40);
    I2C_SDA_DR = 1;
    __delay32(40);
}

void I2CSendAck(void) {
    
    I2C_SDA_DR = 0;
    I2C_SDA = 0;

    I2C_SCL_DR = 1;
    __delay32(40);
    I2C_SCL_DR = 0;
    I2C_SCL = 0;
    __delay32(40);
}

void I2CSendNAck(void) {

    I2C_SDA_DR = 1;

    I2C_SCL_DR = 1;
    __delay_us(5);
    I2C_SCL_DR = 0;
    I2C_SCL = 0;
    __delay_us(5);

}

unsigned char I2CRecACK(void) {
    unsigned char ret = 0;

    I2C_SCL_DR = 1;
   __delay_us(5);
    ret = I2C_SDA_RD;
    I2C_SCL_DR = 0;
    I2C_SCL = 0;
    __delay_us(5);

    return ret;
}

void I2CSendByte(unsigned char dat) {
    unsigned char i = 0;

    for (i = 0; i < 8; i++) {
        if ((dat & 0x80) == 0x80) {
            I2C_SDA_DR = 1;
        } else {
            I2C_SDA_DR = 0;
            I2C_SDA = 0;
        }
        I2C_SCL_DR = 1;
        __delay_us(5);
        I2C_SCL_DR = 0;
        I2C_SCL = 0;
        __delay_us(5);
        dat = (dat << 1);
    }
    I2CRecACK();

}

unsigned char I2CRevByte(void) {
    unsigned char i = 0;
    unsigned char ret = 0;

    I2C_SDA_DR = 1;
    for (i = 0; i < 8; i++) {
        I2C_SDA_DR = 1;
        ret <<= 1;
        I2C_SCL_DR = 1;
        __delay_us(5);
        ret |= I2C_SDA_RD;
        I2C_SCL_DR = 0;
        I2C_SCL = 0;
        __delay_us(5);
    }

    return ret;
}

void I2CWriteBytesToSlave(unsigned char sad, unsigned sub, unsigned char *pdata, unsigned char len) {
    unsigned char i;

    I2CStart();
    I2CSendByte(sad);
    I2CSendByte(sub);

    for (i = 0; i < len; i++) {
        I2CSendByte(*pdata++);
    }
    __delay_us(125);
    I2CStop();

}

unsigned char I2CReadBytesFromSlave(unsigned char sad, unsigned char sub, unsigned char *pdata, unsigned char len) {
 
    I2CStart();
    I2CSendByte(sad);
    I2CSendByte(sub);
    I2CStart();
    I2CSendByte(sad + 1);
    while (len) {
        *pdata = I2CRevByte();
        pdata++;
        len--;
        if (len == 0) {
            I2CSendNAck();
        } else {
            I2CSendAck();
        }
    }
    I2CStop();
    __delay_us(125);
    return 0;
}

