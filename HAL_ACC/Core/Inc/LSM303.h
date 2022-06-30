#include "stm32f411xe.h"
#include "stm32f4xx_hal.h"


#ifndef __LSM303DLHC_H
#define __LSM303DLHC_H
// vim: ts=4 sw=4 expandtab

// Linear acceleration related register addesses
#define   CTRL_REG1_A 		 0x20
#define   CTRL_REG2_A     	 0x21
#define   CTRL_REG3_A     	 0x22
#define   CTRL_REG4_A     	 0x23
#define   CTRL_REG5_A     	 0x24
#define   CTRL_REG6_A     	 0x25
#define   REFERENCE_A     	 0x26
#define   STATUS_REG_A    	 0x27
#define   OUT_X_L_A       	 0x28
#define   OUT_X_H_A       	 0x29
#define   OUT_Y_L_A       	 0x2a
#define   OUT_Y_H_A       	 0x2b
#define   OUT_Z_L_A       	 0x2c
#define   OUT_Z_H_A        0x2d
#define   OUT_X_L_A_MULTI_READ (OUT_X_L_A | 0x80)
#define   OUT_Y_L_A_MULTI_READ (OUT_Y_L_A | 0x80)
#define   OUT_Z_L_A_MULTI_READ (OUT_Z_L_A | 0x80)

#define   FIFO_CTRL_REG_A  0x2e
#define   FIFO_SRC_REG_A   0x2f
#define   INT1_CFG_A       0x30
#define   INT1_SOURCE_A    0x31
#define   INT1_THS_A       0x32
#define   INT1_DURATION_A  0x33
#define   INT2_CFG_A       0x34
#define   INT2_SOURCE_A    0x35
#define   INT2_THS_A       0x36
#define   INT2_DURATION_A  0x37
#define   CLICK_CFG_A      0x38
#define   CLICK_SRC_A      0x39
#define   CLICK_THS_A      0x3a
#define   TIME_LIMIT_A     0x3b
#define   TIME_LATENCY_A   0x3c
#define   TIME_WINDOW_A    0x3d

// Options for CTRL_REG1_A
#define   ODR_DOWN   0b0000 << 4
#define   ODR_1Hz    0b0001 << 4
#define   ODR_10Hz   0b0010 << 4
#define   ODR_25Hz   0b0011 << 4
#define   ODR_50Hz   0b0100 << 4
#define   ODR_100Hz  0b0101 << 4
#define   ODR_200Hz  0b0110 << 4
#define   ODR_400Hz  0b0111 << 4
#define   LPen       0b0001 << 3
#define   Zen        0b0001 << 2
#define   Yen        0b0001 << 1
#define   Xen        0b0001 << 0
#define   TEMP_EN    0b0001 << 7

// Options for CTRL_REG4_A
#define   BDU        0b01 << 7
#define   BLE        0b01 << 6
#define   FS_2G      0b00 << 4
#define   FS_4G      0b01 << 4
#define   FS_8G      0b10 << 4
#define   FS_16G     0b11 << 4
#define   HR         0b00 << 3
#define   SIM        0b01 << 0
#define   ACC_RESOLUTION 2.0 // Maksymalna wartosc przyspieszenia [g]

// Magnetic field related register addesses
#define   CRA_REG_M        0x00
#define   CRB_REG_M        0x01
#define   MR_REG_M         0x02
#define   OUT_X_H_M        0x03
#define   OUT_X_L_M        0x04
#define   OUT_Z_H_M        0x05
#define   OUT_Z_L_M        0x06
#define   OUT_Y_H_M        0x07
#define   OUT_Y_L_M        0x08
#define   OUT_X_L_M_MULTI_READ (OUT_X_L_M | 0x80)
#define   OUT_Y_L_M_MULTI_READ (OUT_Y_L_M | 0x80)
#define   OUT_Z_L_M_MULTI_READ (OUT_Z_L_M | 0x80)
#define   SR_REG_M         0x09
#define   IRA_REG_M        0x0a
#define   IRB_REG_M        0x0b
#define   IRC_REG_M        0x0c
#define   TEMP_OUT_H_M     0x31
#define   TEMP_OUT_L_M     0x32
#define   TEMP_OUT_L_M_MULITREAD (TEMP_OUT_L_M | 0x80)
// I2C addresses (Datasheet << 1)
#define   ACC_ADDRESS      0x32
#define   MF_ADDRESS       0x3C

//#define AVERAGE_WINDOW_SIZE                  ((uint32_t) 10u)
//#define CALIBRATION_BUFFER_LENGTH            ((uint32_t) 2000u)
//#define L3GD20_SENSITIVITY   			     ((float)0.07)

//uint8_t buf[6];
//uint8_t spiTxBuf[2];
//uint8_t spiRxBuf[6];





void lsm303dlhc_init_la(I2C_HandleTypeDef *i2c);
void lsm303dlhc_init_mf(I2C_HandleTypeDef *i2c);

void lsm303dlhc_read_la(I2C_HandleTypeDef *i2c, float *bufX, float *bufY, float *bufZ);
void lsm303dlhc_read_mf(I2C_HandleTypeDef *i2c,float *bufX_g,float *bufY_g,float *bufZ_g);

void lsm303dlhc_read_mf_temp(I2C_HandleTypeDef *i2c, int16_t *bufX);
void lsm303dlhc_read_magneto(I2C_HandleTypeDef *i2c, float *bufX, float *bufY, float *bufZ);

void lsm303dlhc_read_la_b(I2C_HandleTypeDef *i2c, uint8_t *buf);
void lsm303dlhc_read_mf_b(I2C_HandleTypeDef *i2c, uint8_t *buf);


void LSM303_Init(I2C_HandleTypeDef *i2c);


//void L3GD20_Init(SPI_HandleTypeDef *spi);
//void L3GD20_ACC_READ(SPI_HandleTypeDef *spi , float *bufX_g, float *bufY_g, float *bufZ_g);
//

































#endif //__LSM303DLHC_H
