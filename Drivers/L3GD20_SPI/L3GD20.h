/*
 * L3GD20.h
 *
 *  Created on: Mar 24, 2022
 *      Author: elekt
 */

#ifndef INC_L3GD20_H_
#define INC_L3GD20_H_

#include "stm32f4xx_hal.h"
#include "stm32f4xx.h"


#define WHO__AM		0x0F			// 1 1 0 1 0 0 2 2  D3

#define CTRL_REG1	0x20
  #define DR1	    (1 << 7)
  #define DR0	    (1 << 6)
  #define BW1	    (1 << 5)
  #define BW0	    (1 << 4)
  #define PD	    (1 << 3)
  #define Zen	    (1 << 2)
  #define Yen	    (1 << 1)
  #define Xen       (1 << 0)

#define CTRL_REG2	0x21
  #define HPM1	    (1 << 5)
  #define HPM0	    (1 << 4)
  #define HPCF3	    (1 << 3)
  #define HPCF2	    (1 << 2)
  #define HPCF1	    (1 << 1)
  #define HPCF0	    (1 << 0)


#define CTRL_REG3	0x22
  #define I1_Int1   (1 << 7)
  #define I1_Boot   (1 << 6)
  #define H_Lactive (1 << 5)
  #define PP_OD	    (1 << 4)
  #define I2_DRDY   (1 << 3)
  #define I2_WTM    (1 << 2)
  #define I2_ORun   (1 << 1)
  #define I2_Empty  (1 << 0)

#define CTRL_REG4	0x23
  #define BDU	    (1 << 7)
  #define BLE       (1 << 6)
  #define FS1       (1 << 5)
  #define FS0	    (1 << 4)
  #define SIM	    (1 << 0)

#define CTRL_REG5	0x24
  #define BOOT      (1 << 7)
  #define FIFO_EN   (1 << 6)
  #define HPen	    (1 << 4)
  #define INT1_Sel1 (1 << 3)
  #define INT1_Sel0 (1 << 2)
  #define OUT_Sel1  (1 << 1)
  #define OUT_Sel0  (1 << 0)

#define REFERENCE	0x25
  #define REF7      (1 << 7)
  #define REF6      (1 << 6)
  #define REF5      (1 << 5)
  #define REF4	    (1 << 4)
  #define REF3      (1 << 3)
  #define REF2      (1 << 2)
  #define REF1      (1 << 1)
  #define REF0      (1 << 0)

#define OUT_TEMP	0x26
  #define TEMP7     (1 << 7)
  #define TEMP6     (1 << 6)
  #define TEMP5     (1 << 5)
  #define TEMP4	    (1 << 4)
  #define TEMP3     (1 << 3)
  #define TEMP2     (1 << 2)
  #define TEMP1     (1 << 1)
  #define TEMP0     (1 << 0)

#define STATUS_REG	0x27
  #define ZYXOR     (1 << 7)
  #define ZOR       (1 << 6)
  #define YOR       (1 << 5)
  #define XOR	    (1 << 4)
  #define ZYXDA     (1 << 3)
  #define ZDA       (1 << 2)
  #define YDA       (1 << 1)
  #define XDA       (1 << 0)

#define OUT_X_L		0x28
  #define XD7       (1 << 7)
  #define XD6       (1 << 6)
  #define XD5       (1 << 5)
  #define XD4	    (1 << 4)
  #define XD3       (1 << 3)
  #define XD2       (1 << 2)
  #define XD1       (1 << 1)
  #define XD0       (1 << 0)

#define OUT_X_H		0x29
  #define XD15      (1 << 7)
  #define XD14      (1 << 6)
  #define XD13      (1 << 5)
  #define XD12	    (1 << 4)
  #define XD11      (1 << 3)
  #define XD10       (1 << 2)
  #define XD9       (1 << 1)
  #define XD8       (1 << 0)

#define OUT_Y_L		0x2a
  #define YD7       (1 << 7)
  #define YD6       (1 << 6)
  #define YD5       (1 << 5)
  #define YD4	    (1 << 4)
  #define YD3       (1 << 3)
  #define YD2       (1 << 2)
  #define YD1       (1 << 1)
  #define YD0       (1 << 0)

#define OUT_Y_H		0x2b
  #define YD15      (1 << 7)
  #define YD14      (1 << 6)
  #define YD13      (1 << 5)
  #define YD12	    (1 << 4)
  #define YD11      (1 << 3)
  #define YD10      (1 << 2)
  #define YD9       (1 << 1)
  #define YD8       (1 << 0)

#define OUT_Z_L		0x2c
  #define ZD7       (1 << 7)
  #define ZD6       (1 << 6)
  #define ZD5       (1 << 5)
  #define ZD4	    (1 << 4)
  #define ZD3       (1 << 3)
  #define ZD2       (1 << 2)
  #define ZD1       (1 << 1)
  #define ZD0       (1 << 0)

#define OUT_Z_H		0x2d
  #define ZD15      (1 << 7)
  #define ZD14      (1 << 6)
  #define ZD13      (1 << 5)
  #define ZD12	    (1 << 4)
  #define ZD11      (1 << 3)
  #define ZD10      (1 << 2)
  #define ZD9       (1 << 1)
  #define ZD8       (1 << 0)

#define FIFO_CTRL_REG	0x2e
  #define FM2       (1 << 7)
  #define FM1       (1 << 6)
  #define FM0       (1 << 5)
  #define WTM4	    (1 << 4)
  #define WTM3      (1 << 3)
  #define WTM2      (1 << 2)
  #define WTM1      (1 << 1)
  #define WTM0      (1 << 0)

#define FIFO_SRC_REG 	0x2f
  #define WTM       (1 << 7)
  #define OVRN      (1 << 6)
  #define EMPTY     (1 << 5)
  #define FSS4	    (1 << 4)
  #define FSS3      (1 << 3)
  #define FSS2      (1 << 2)
  #define FSS1      (1 << 1)
  #define FSS0      (1 << 0)

#define INT1_CFG	0x30
  #define AND_OR    (1 << 7)
  #define LIR       (1 << 6)
  #define ZHIE      (1 << 5)
  #define ZLIE	    (1 << 4)
  #define YHIE      (1 << 3)
  #define YLIE      (1 << 2)
  #define XHIE      (1 << 1)
  #define XLIE      (1 << 0)

#define INT1_SRC	0x31
  #define IA        (1 << 6)
  #define ZH        (1 << 5)
  #define ZL	    (1 << 4)
  #define YH        (1 << 3)
  #define YL        (1 << 2)
  #define XH        (1 << 1)
  #define XL        (1 << 0)

#define INT1_THS_XH	0x32
  #define THSX14    (1 << 6)
  #define THSX13    (1 << 5)
  #define THSX12    (1 << 4)
  #define THSX11    (1 << 3)
  #define THSX10    (1 << 2)
  #define THSX9     (1 << 1)
  #define THSX8     (1 << 0)

#define INT1_THS_XL	0x33
  #define THSX7     (1 << 7)
  #define THSX6     (1 << 6)
  #define THSX5     (1 << 5)
  #define THSX4     (1 << 4)
  #define THSX3     (1 << 3)
  #define THSX2     (1 << 2)
  #define THSX1     (1 << 1)
  #define THSX0     (1 << 0)


#define INT1_THS_YH	0x34
  #define THSY14    (1 << 6)
  #define THSY13    (1 << 5)
  #define THSY12    (1 << 4)
  #define THSY11    (1 << 3)
  #define THSY10    (1 << 2)
  #define THSY9     (1 << 1)
  #define THSY8     (1 << 0)

#define INT1_THS_YL	0x35
  #define THSY7     (1 << 7)
  #define THSY6     (1 << 6)
  #define THSY5     (1 << 5)
  #define THSY4     (1 << 4)
  #define THSY3     (1 << 3)
  #define THSY2     (1 << 2)
  #define THSY1     (1 << 1)
  #define THSY0     (1 << 0)

#define INT1_THS_ZH	0x36
  #define THSZ14    (1 << 6)
  #define THSZ13    (1 << 5)
  #define THSZ12    (1 << 4)
  #define THSZ11    (1 << 3)
  #define THSZ10    (1 << 2)
  #define THSZ9     (1 << 1)
  #define THSZ8     (1 << 0)

#define INT1_THS_ZL	0x37
  #define THSz7     (1 << 7)
  #define THSZ6     (1 << 6)
  #define THSZ5     (1 << 5)
  #define THSZ4     (1 << 4)
  #define THSZ3     (1 << 3)
  #define THSZ2     (1 << 2)
  #define THSZ1     (1 << 1)
  #define THSZ0     (1 << 0)

#define INT1_DURATION	0x38
  #define WAIT     (1 << 7)
  #define D6       (1 << 6)
  #define D5       (1 << 5)
  #define D4       (1 << 4)
  #define D3       (1 << 3)
  #define D2       (1 << 2)
  #define D1       (1 << 1)
  #define D0       (1 << 0)



#define AVERAGE_WINDOW_SIZE                  ((uint32_t) 10u)
#define CALIBRATION_BUFFER_LENGTH            ((uint32_t) 2000u)
#define L3GD20_SENSITIVITY    ((float)0.07)
#define SPI_Start()	HAL_GPIO_WritePin(CS_Port,CS_PIN,GPIO_PIN_RESET)
#define SPI_Stop()	HAL_GPIO_WritePin(CS_Port,CS_PIN,GPIO_PIN_SET)

// Here must define where is your CS pin
#define CS_Port		GPIOE
#define CS_PIN 		GPIO_PIN_3



typedef enum
{
	L3GD20_DATA_NOT_READY,
	L3GD20_DATA_READY,
}L3GD20_DataReadyFlagType;

static L3GD20_DataReadyFlagType dataReadyFlag=L3GD20_DATA_READY;

typedef enum
{
	L3GD20_collect_calibration_samples,
	L3GD20_process_calibration_samples,
	L3GD20_calibrated,
}L3GD20_caliStateType;

static L3GD20_caliStateType currentcalistate=L3GD20_collect_calibration_samples;



typedef enum
{
	L3GD20_fisrt,
	L3GD20_second,
	L3GD20_finaly
}L3GD20_StateType;
static L3GD20_StateType currentState=L3GD20_fisrt;


static float angleRate_x=0;
static float angleRate_y=0;
static float angleRate_z=0;

static int32_t offset_x=0;
static int32_t offset_y=0;
static int32_t offset_z=0;

static float Noise_X = 0;
static float Noise_Y = 0;
static float Noise_Z = 0;

static float Angle_X = 0;
static float Angle_Y = 0;
static float Angle_Z = 0;

static float LastAngleRate_X = 0;
static float LastAngleRate_Y = 0;
static float LastAngleRate_Z = 0;

static int32_t TempNoise_X = 0;
static int32_t TempNoise_Y = 0;
static int32_t TempNoise_Z = 0;






volatile static uint32_t caliCounter = 0;


static int16_t calibrationBuffer_X[CALIBRATION_BUFFER_LENGTH];
static int16_t calibrationBuffer_Y[CALIBRATION_BUFFER_LENGTH];
static int16_t calibrationBuffer_Z[CALIBRATION_BUFFER_LENGTH];

static uint8_t spiTxBuf[2];
static uint8_t spiRxBuf[7];




void L3GD20_Init(SPI_HandleTypeDef *spi);
void L3GD20_ReadXYZ(SPI_HandleTypeDef *spi, float *bufX, float *bufY, float *bufZ);
void L3GD20_Read_Temp(SPI_HandleTypeDef *spi, float *Temp);




#endif /* INC_L3GD20_H_ */
