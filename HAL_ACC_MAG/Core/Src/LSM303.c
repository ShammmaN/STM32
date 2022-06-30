#include "LSM303.h"

////////////////////////////////////////////////////////////////////////////////////////////






#define AVERAGE_WINDOW_SIZE                  ((uint32_t) 10u)
#define CALIBRATION_BUFFER_LENGTH            ((uint32_t) 2000u)
//#define L3GD20_SENSITIVITY    ((float)0.07)

//
//typedef enum
//{
//	L3GD20_DATA_NOT_READY,
//	L3GD20_DATA_READY,
//}L3GD20_DataReadyFlagType;
//
//static L3GD20_DataReadyFlagType dataReadyFlag=L3GD20_DATA_READY;
//
//typedef enum
//{
//	L3GD20_collect_calibration_samples,
//	L3GD20_process_calibration_samples,
//	L3GD20_calibrated,
//}L3GD20_caliStateType;
//
//static L3GD20_caliStateType currentcalistate=L3GD20_collect_calibration_samples;
//
//
//
//typedef enum
//{
//	L3GD20_fisrt,
//	L3GD20_second,
//	L3GD20_finaly
//}L3GD20_StateType;
//static L3GD20_StateType currentState=L3GD20_fisrt;

//
//static float angleRate_x=0;
//static float angleRate_y=0;
//static float angleRate_z=0;
//
//static int32_t offset_x=0;
//static int32_t offset_y=0;
//static int32_t offset_z=0;
//
//static float Noise_X = 0;
//static float Noise_Y = 0;
//static float Noise_Z = 0;
//
//static float Angle_X = 0;
//static float Angle_Y = 0;
//static float Angle_Z = 0;
//
//static float LastAngleRate_X = 0;
//static float LastAngleRate_Y = 0;
//static float LastAngleRate_Z = 0;
//
//static int32_t TempNoise_X = 0;
//static int32_t TempNoise_Y = 0;
//static int32_t TempNoise_Z = 0;
//
//




volatile static uint32_t caliCounter = 0;


//static int16_t calibrationBuffer_X[CALIBRATION_BUFFER_LENGTH];
//static int16_t calibrationBuffer_Y[CALIBRATION_BUFFER_LENGTH];
//static int16_t calibrationBuffer_Z[CALIBRATION_BUFFER_LENGTH];
//
//static uint8_t spiTxBuf[2];
//static uint8_t spiRxBuf[7];












////////////////////////////////////////////////////////////////////////////////////////////



void LSM303_Init(I2C_HandleTypeDef *i2c) {

	// Config Accelero registers
	uint8_t Settings = Xen | Yen | Zen | ODR_100Hz;
	HAL_StatusTypeDef ret;

     ret = HAL_I2C_Mem_Write(i2c, ACC_ADDRESS, CTRL_REG1_A, 1,&Settings, 1, 10000);

 	// Config Magneto registers + temperature sensor
 	 Settings = TEMP_EN;
 	 ret =HAL_I2C_Mem_Write(i2c, MF_ADDRESS, CRA_REG_M, 1, &Settings, 1, 10000);

     Settings = 0X00;
     ret =HAL_I2C_Mem_Write(i2c, MF_ADDRESS, MR_REG_M, 1, &Settings, 1, 10000);

}


void lsm303dlhc_init_la(I2C_HandleTypeDef *i2c) {

    // wypelnienie zmiennej konfiguracyjnej odpowiednimi opcjami
    uint8_t Settings = Xen | Yen | Zen | ODR_100Hz;
    HAL_StatusTypeDef ret;
    // Wpisanie konfiguracji do rejestru akcelerometru
    ret = HAL_I2C_Mem_Write(i2c, ACC_ADDRESS, CTRL_REG1_A, 1, &Settings, 1, 100);
//    if (ret != HAL_OK) {
//          return;
//      }

}



void lsm303dlhc_read_la(I2C_HandleTypeDef *i2c, float *bufX, float *bufY, float *bufZ) {

    HAL_StatusTypeDef ret;
    uint8_t Data[2];
    int16_t buf;

    ret =HAL_I2C_Mem_Read(i2c, ACC_ADDRESS, OUT_X_L_A_MULTI_READ, 1, Data, 2, 100);
    //if (ret != HAL_OK) {   return;   }
    buf = ((Data[1] << 8)|Data[0]);
    *bufX=((float)buf*ACC_RESOLUTION)/(float)INT16_MAX;

    ret = HAL_I2C_Mem_Read(i2c, ACC_ADDRESS, OUT_Y_L_A_MULTI_READ, 1, Data, 2, 100);
   // if (ret != HAL_OK) {   return;   }
    buf = ((Data[1] << 8)|Data[0]);
    *bufY=((float)buf*ACC_RESOLUTION)/(float)INT16_MAX;

    ret = HAL_I2C_Mem_Read(i2c, ACC_ADDRESS, OUT_Z_L_A_MULTI_READ, 1, Data, 2, 100);
   // if (ret != HAL_OK) {   return;   }
    buf = ((Data[1] << 8)|Data[0]);
    *bufZ=((float)buf*ACC_RESOLUTION)/(float)INT16_MAX;

}




// TO JEST PRAWIDLOWA WERSJA ODCZYTU MAGNETO
void lsm303dlhc_read_magneto(I2C_HandleTypeDef *i2c, float *bufX, float *bufY, float *bufZ) {

  HAL_StatusTypeDef ret;
  uint8_t Data[2];
  int16_t buffer;
  ret=HAL_I2C_Mem_Read(i2c, MF_ADDRESS, OUT_X_L_M, 1, &Data[0], 1, 100);
  	  if (ret != HAL_OK) { *bufX = 999;  return;   }
  ret=HAL_I2C_Mem_Read(i2c, MF_ADDRESS, OUT_X_H_M, 1, &Data[1], 1, 100);
  	  if (ret != HAL_OK) { *bufX = 999; return;   }
  buffer = ((Data[1] << 8)|Data[0]);
  *bufX=(float)buffer;
  ret=HAL_I2C_Mem_Read(i2c, MF_ADDRESS, OUT_Y_L_M, 1, &Data[0], 1, 100);
  	  if (ret != HAL_OK) { *bufY = 999;  return;   }
  ret=HAL_I2C_Mem_Read(i2c, MF_ADDRESS, OUT_Y_H_M, 1, &Data[1], 1, 100);
  	  if (ret != HAL_OK) { *bufY = 999; return;   }
  buffer = ((Data[1] << 8)|Data[0]);
  *bufY=(float)buffer;
  ret=HAL_I2C_Mem_Read(i2c, MF_ADDRESS, OUT_Z_L_M, 1, &Data[0], 1, 100);
  	  if (ret != HAL_OK) { *bufZ = 999;  return;   }
  ret=HAL_I2C_Mem_Read(i2c, MF_ADDRESS, OUT_Z_H_M, 1, &Data[1], 1, 100);
  	  if (ret != HAL_OK) { *bufZ = 999;  return;   }
  buffer = ((Data[1] << 8)|Data[0]);
  *bufZ=(float)buffer;

}

void lsm303dlhc_read_mf_temp(I2C_HandleTypeDef *i2c, int16_t *bufX) {

  HAL_StatusTypeDef ret;
  uint8_t Data[2];

  ret=HAL_I2C_Mem_Read(i2c, MF_ADDRESS, TEMP_OUT_L_M_MULITREAD, 1, Data, 2, 100);
  if (ret != HAL_OK) {   return;   }
  *bufX = ((Data[1] << 8)|Data[0]);

}

void lsm303dlhc_read_mf_b(I2C_HandleTypeDef *i2c, uint8_t *buf) {
    uint8_t reg = OUT_X_H_M;

   volatile HAL_StatusTypeDef ret;

    ret = HAL_I2C_Master_Transmit(i2c, MF_ADDRESS, &reg, 1, 1000);
    if (ret != HAL_OK) {
        return;
    }

    ret = HAL_I2C_Master_Receive(i2c, MF_ADDRESS, buf, 6, 1000);
    if (ret != HAL_OK) {
        return;
    }
}






//
//void lsm303dlhc_read_magneto(I2C_HandleTypeDef *i2c, float *bufX_g,float *bufY_g,float *bufZ_g){
//    uint8_t reg = OUT_X_H_M;
//    uint16_t bufX,bufY,bufZ;
//    HAL_StatusTypeDef ret;
//
//     ret = HAL_I2C_Master_Transmit(i2c, MF_ADDRESS, &reg, 1, 1000);
//     ret = HAL_I2C_Master_Receive(i2c, MF_ADDRESS, buf, 6, 1000);
//     bufX = ((buf[1] << 8)|buf[0]);
//     bufY = ((buf[3] << 8)|buf[2]);
//     bufZ = ((buf[5] << 8)|buf[4]);
////     *bufX_g = ((float)bufX*ACC_RESOLUTION)/(float)INT16_MAX;
////     *bufY_g = ((float)bufY*ACC_RESOLUTION)/(float)INT16_MAX;
////     *bufZ_g = ((float)bufZ*ACC_RESOLUTION)/(float)INT16_MAX;
//     *bufX_g = bufX;
//     *bufY_g = bufY;
//     *bufZ_g = bufZ;
//
//}



void lsm303dlhc_init_mf(I2C_HandleTypeDef *i2c) {
    uint8_t init[2][2] = {
        {CRB_REG_M, (uint8_t)0x20},
        {MR_REG_M, (uint8_t)0x00}
    };

    HAL_StatusTypeDef ret;

    ret = HAL_I2C_Master_Transmit(i2c, MF_ADDRESS, init[0], 2, 1000);
    HAL_Delay(5);
    ret = HAL_I2C_Master_Transmit(i2c, MF_ADDRESS, init[1], 2, 1000);


}



















