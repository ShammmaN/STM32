#include "LSM303.h"

////////////////////////////////////////////////////////////////////////////////////////////






#define AVERAGE_WINDOW_SIZE                  ((uint32_t) 10u)
#define CALIBRATION_BUFFER_LENGTH            ((uint32_t) 2000u)
#define L3GD20_SENSITIVITY    ((float)0.07)


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












////////////////////////////////////////////////////////////////////////////////////////////

//
//
//void LSM303_Init(I2C_HandleTypeDef *i2c) {
//
//     HAL_I2C_Mem_Write(i2c, ACC_ADDRESS, CTRL_REG1_A, 1,0x27, 1, 100);
//     HAL_I2C_Mem_Write(i2c, MF_ADDRESS, MR_REG_M, 1, 0x00, 1, 100);
//
//}
//
//void L3GD20_Init(SPI_HandleTypeDef *spi) {
//
//	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3 ,GPIO_PIN_SET);
//	HAL_Delay(20);
//
//	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3 ,GPIO_PIN_RESET);
//	HAL_Delay(20);
//	spiTxBuf[0] = 0x20;
//	spiTxBuf[1] = 0xff;
//	HAL_SPI_Transmit(spi, spiTxBuf, 2, 50);
//	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_SET);
//	HAL_Delay(20);
//
//
//	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3 ,GPIO_PIN_RESET);
//	HAL_Delay(20);
//	spiTxBuf[0] = 0x21;
//	spiTxBuf[1] = 0x00;
//	HAL_SPI_Transmit(spi, spiTxBuf, 2, 50);
//	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_SET);
//	HAL_Delay(20);
//
//
//
//	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3 ,GPIO_PIN_RESET);
//	HAL_Delay(20);
//	spiTxBuf[0] = 0x22;
//	spiTxBuf[1] = 0x00;
//	HAL_SPI_Transmit(spi, spiTxBuf, 2, 50);
//	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_SET);
//	HAL_Delay(20);
//
//
//	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3 ,GPIO_PIN_RESET);
//	HAL_Delay(20);
//	spiTxBuf[0] = 0x23;
//	spiTxBuf[1] = 0x20;
//	HAL_SPI_Transmit(spi, spiTxBuf, 2, 50);
//	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_SET);
//	HAL_Delay(20);
//
//
//	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3 ,GPIO_PIN_RESET);
//	HAL_Delay(20);
//	spiTxBuf[0] = 0x24;
//	spiTxBuf[1] = 0x10;
//	HAL_SPI_Transmit(spi, spiTxBuf, 2, 50);
//	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_SET);
//	HAL_Delay(20);
//
//}


//void L3GD20_ACC_READ(SPI_HandleTypeDef *spi , float *bufX_g, float *bufY_g, float *bufZ_g){
//
//
//	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3 ,GPIO_PIN_RESET);
//	spiTxBuf[0] = 0x28|0x80;
//	HAL_SPI_Transmit(spi, spiTxBuf, 1, 50);
//	HAL_SPI_Receive(spi, &spiRxBuf[1], 1, 50);
//	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_SET);
//
//	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3 ,GPIO_PIN_RESET);
//	spiTxBuf[0] = 0x29|0x80;
//	HAL_SPI_Transmit(spi, spiTxBuf, 1, 50);
//	HAL_SPI_Receive(spi, &spiRxBuf[2], 1, 50);
//	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_SET);
//
//	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3 ,GPIO_PIN_RESET);
//	spiTxBuf[0] = 0x2a|0x80;
//	HAL_SPI_Transmit(spi, spiTxBuf, 1, 50);
//	HAL_SPI_Receive(spi, &spiRxBuf[3], 1, 50);
//	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_SET);
//
//	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3 ,GPIO_PIN_RESET);
//	spiTxBuf[0] = 0x2b|0x80;
//	HAL_SPI_Transmit(spi, spiTxBuf, 1, 50);
//	HAL_SPI_Receive(spi, &spiRxBuf[4], 4, 50);
//	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_SET);
//
//	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3 ,GPIO_PIN_RESET);
//	spiTxBuf[0] = 0x2c|0x80;
//	HAL_SPI_Transmit(spi, spiTxBuf, 1, 50);
//	HAL_SPI_Receive(spi, &spiRxBuf[5], 1, 50);
//	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_SET);
//
//	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3 ,GPIO_PIN_RESET);
//	spiTxBuf[0] = 0x2d|0x80;
//	HAL_SPI_Transmit(spi, spiTxBuf, 1, 50);
//	HAL_SPI_Receive(spi, &spiRxBuf[6], 1, 50);
//	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_SET);
//
//
//	*bufX_g = (spiRxBuf[2]<<8|spiRxBuf[1]);
//	*bufY_g = (spiRxBuf[4]<<8|spiRxBuf[3]);
//	*bufZ_g = (spiRxBuf[6]<<8|spiRxBuf[5]);
//
//}
//
//void L3GD20_ACC_READ(SPI_HandleTypeDef *spi , float *bufX_g, float *bufY_g, float *bufZ_g){
//
//
//	volatile int16_t Raw_x=0;
//	volatile int16_t Raw_y=0;
//	volatile int16_t Raw_z=0;
//
//	float difftime=0;
//
//	int16_t averageWindow_X[AVERAGE_WINDOW_SIZE] = {0};
//	int16_t averageWindow_Y[AVERAGE_WINDOW_SIZE] = {0};
//	int16_t averageWindow_Z[AVERAGE_WINDOW_SIZE] = {0};
//
//	uint32_t windowPosition = 0;
//	int32_t tempSum_X = 0;
//	int32_t tempSum_Y = 0;
//	int32_t tempSum_Z = 0;
//
//	switch(currentState)
//	{
//		//---------------------------------------------------------------------------
//		//data
//		case(L3GD20_fisrt):
//			if(dataReadyFlag==L3GD20_DATA_READY)
//			{
//			     	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_3,GPIO_PIN_RESET);
//					spiTxBuf[0]=0x28|0x80;
//					HAL_SPI_Transmit(spi,spiTxBuf,1,50);
//					HAL_SPI_Receive(spi,&spiRxBuf[1],1,50);
//					HAL_GPIO_WritePin(GPIOE,GPIO_PIN_3,GPIO_PIN_SET);
//
//					HAL_GPIO_WritePin(GPIOE,GPIO_PIN_3,GPIO_PIN_RESET);
//					spiTxBuf[0]=0x29|0x80;
//					HAL_SPI_Transmit(spi,spiTxBuf,1,50);
//					HAL_SPI_Receive(spi,&spiRxBuf[2],1,50);
//					HAL_GPIO_WritePin(GPIOE,GPIO_PIN_3,GPIO_PIN_SET);
//
//					HAL_GPIO_WritePin(GPIOE,GPIO_PIN_3,GPIO_PIN_RESET);
//					spiTxBuf[0]=0x2a|0x80;
//					HAL_SPI_Transmit(spi,spiTxBuf,1,50);
//					HAL_SPI_Receive(spi,&spiRxBuf[3],1,50);
//					HAL_GPIO_WritePin(GPIOE,GPIO_PIN_3,GPIO_PIN_SET);
//
//					HAL_GPIO_WritePin(GPIOE,GPIO_PIN_3,GPIO_PIN_RESET);
//					spiTxBuf[0]=0x2b|0x80;
//					HAL_SPI_Transmit(spi,spiTxBuf,1,50);
//					HAL_SPI_Receive(spi,&spiRxBuf[4],1,50);
//					HAL_GPIO_WritePin(GPIOE,GPIO_PIN_3,GPIO_PIN_SET);
//
//					HAL_GPIO_WritePin(GPIOE,GPIO_PIN_3,GPIO_PIN_RESET);
//					spiTxBuf[0]=0x2c|0x80;
//					HAL_SPI_Transmit(spi,spiTxBuf,1,50);
//					HAL_SPI_Receive(spi,&spiRxBuf[5],1,50);
//					HAL_GPIO_WritePin(GPIOE,GPIO_PIN_3,GPIO_PIN_SET);
//
//					HAL_GPIO_WritePin(GPIOE,GPIO_PIN_3,GPIO_PIN_RESET);
//					spiTxBuf[0]=0x2d|0x80;
//					HAL_SPI_Transmit(spi,spiTxBuf,1,50);
//					HAL_SPI_Receive(spi,&spiRxBuf[6],1,50);
//					HAL_GPIO_WritePin(GPIOE,GPIO_PIN_3,GPIO_PIN_SET);
//
//					currentState=L3GD20_second;
//					dataReadyFlag=L3GD20_DATA_NOT_READY;
//			}
//			else
//			{
//			}
//
//			break;
//					//-----------------------------------------------------------------------------------
//					//varibla
//		case(L3GD20_second):
//			Raw_x=(spiRxBuf[2]<<8)|spiRxBuf[1];
//			Raw_y=(spiRxBuf[4]<<8)|spiRxBuf[3];
//			Raw_z=(spiRxBuf[6]<<8)|spiRxBuf[5];
//
//		if(currentcalistate==L3GD20_calibrated)
//		{
//			angleRate_x=(float) (Raw_x - (offset_x))*L3GD20_SENSITIVITY;
//			angleRate_y=(float) (Raw_y - (offset_y))*L3GD20_SENSITIVITY;
//			angleRate_z=(float) (Raw_z - (offset_z))*L3GD20_SENSITIVITY;
//			difftime=0.003f;
//
//			if((angleRate_x>Noise_X)||(angleRate_x<-Noise_X))
//			{
//				Angle_X+=((angleRate_x+LastAngleRate_X)*difftime)/(2.0f);
//				LastAngleRate_X=angleRate_x;
//			}
//			else
//			{
//			}
//			if((angleRate_y>Noise_Y)||(angleRate_y<-Noise_Y))
//			{
//				Angle_Y+=((angleRate_y+LastAngleRate_Y)*difftime)/(2.0f);
//				LastAngleRate_Y=angleRate_y;
//			}
//			else
//			{
//			}
//			if((angleRate_z>Noise_Z)||(angleRate_z<-Noise_Z))
//			{
//				Angle_Z+=((angleRate_z+LastAngleRate_Z)*difftime)/(2.0f);
//				LastAngleRate_Z=angleRate_z;
//			}
//			else
//			{
//			}
//		}
//		else
//		{
//			switch(currentcalistate)
//			{
//				//---------------------------------------------------------------------------------------------------------
//				case(L3GD20_collect_calibration_samples):
//					calibrationBuffer_X[caliCounter]=Raw_x;
//					calibrationBuffer_Y[caliCounter]=Raw_y;
//					calibrationBuffer_Z[caliCounter]=Raw_z;
//					caliCounter++;
//
//					if(caliCounter>=CALIBRATION_BUFFER_LENGTH)
//					{
//						caliCounter=0;
//
//						currentcalistate=L3GD20_process_calibration_samples;
//					}
//					else
//					{
//					}
//					break;
//				//----------------------------------------------------------------------------------------------------------
//				case(L3GD20_process_calibration_samples):
//					for(uint32_t idx=0; idx<CALIBRATION_BUFFER_LENGTH;idx++)
//						{
//							tempSum_X=tempSum_X-averageWindow_X[windowPosition]+calibrationBuffer_X[idx];
//							tempSum_Y=tempSum_Y-averageWindow_Y[windowPosition]+calibrationBuffer_Y[idx];
//							tempSum_Z=tempSum_Z-averageWindow_Z[windowPosition]+calibrationBuffer_Z[idx];
//
//							averageWindow_X[windowPosition]=calibrationBuffer_X[idx];
//							averageWindow_Y[windowPosition]=calibrationBuffer_Y[idx];
//							averageWindow_Z[windowPosition]=calibrationBuffer_Z[idx];
//
//							offset_x=tempSum_X/(int32_t)AVERAGE_WINDOW_SIZE;
//							offset_y=tempSum_Y/(int32_t)AVERAGE_WINDOW_SIZE;
//							offset_z=tempSum_Z/(int32_t)AVERAGE_WINDOW_SIZE;
//
//							windowPosition++;
//
//							if(windowPosition>=AVERAGE_WINDOW_SIZE)
//							{
//								windowPosition=0;
//							}
//							else
//							{
//							}
//
//						}
//						for(uint32_t idx=0;idx<CALIBRATION_BUFFER_LENGTH;idx++)
//						{
//							if(((int32_t)calibrationBuffer_X[idx]-offset_x)>TempNoise_X)
//							{
//								TempNoise_X=(int32_t)calibrationBuffer_X[idx]-offset_x;
//							}
//							else if(((int32_t)calibrationBuffer_X[idx]-offset_x)<-TempNoise_X)
//							{
//								TempNoise_X=-((int32_t)calibrationBuffer_X[idx]-offset_x);
//							}
//
//							if(((int32_t)calibrationBuffer_Y[idx]-offset_y)>TempNoise_Y)
//							{
//								TempNoise_Y=(int32_t)calibrationBuffer_Y[idx]-offset_y;
//							}
//							else if(((int32_t)calibrationBuffer_Y[idx]-offset_y)<-TempNoise_Y)
//							{
//								TempNoise_Y=-((int32_t)calibrationBuffer_Y[idx]-offset_y);
//							}
//
//							if(((int32_t)calibrationBuffer_Z[idx]-offset_z)>TempNoise_Z)
//							{
//								TempNoise_Z=(int32_t)calibrationBuffer_Z[idx]-offset_z;
//							}
//							else if(((int32_t)calibrationBuffer_Z[idx]-offset_z)<-TempNoise_Z)
//							{
//								TempNoise_Z=-((int32_t)calibrationBuffer_Z[idx]-offset_z);
//							}
//						}
//
//						Noise_X=(float)TempNoise_X*L3GD20_SENSITIVITY;
//						Noise_Y=(float)TempNoise_Y*L3GD20_SENSITIVITY;
//						Noise_Z=(float)TempNoise_Z*L3GD20_SENSITIVITY;
//
//						currentcalistate=L3GD20_calibrated;
//						break;
//
//				case(L3GD20_calibrated):
//					break;
//
//				default:
//					break;
//			}
//
//		}
//		currentState=L3GD20_fisrt;
//		dataReadyFlag=L3GD20_DATA_READY;
//		break;
//
//				default:
//					break;
//
//	}
//
//
//
//
//}
//
//

void lsm303dlhc_init_la(I2C_HandleTypeDef *i2c) {

    // wypelnienie zmiennej konfiguracyjnej odpowiednimi opcjami
    uint8_t Settings = Xen | Yen | Zen | ODR_100Hz;
    HAL_StatusTypeDef ret;
    // Wpisanie konfiguracji do rejestru akcelerometru
    ret = HAL_I2C_Mem_Write(i2c, ACC_ADDRESS, CTRL_REG1_A, 1, &Settings, 1, 100);
  //  if (ret != HAL_OK) {
  //        return;
  //    }

}


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

//void lsm303dlhc_init_mf(I2C_HandleTypeDef *i2c) {
//  // wypelnienie zmiennej konfiguracyjnej odpowiednimi opcjami
//  uint8_t Settings = 0x90;
//  HAL_StatusTypeDef ret;
//  // Wpisanie konfiguracji do rejestru akcelerometru
//  ret = HAL_I2C_Mem_Write(i2c, MF_ADDRESS, CRA_REG_M, 1, &Settings, 1, 100);
//  HAL_Delay(10);
//
//  Settings = 0x80;
//  ret = HAL_I2C_Mem_Write(i2c, MF_ADDRESS, CRB_REG_M, 1, &Settings, 1, 100);
//  HAL_Delay(10);
//
//   Settings = 0x00;
//  ret = HAL_I2C_Mem_Write(i2c, MF_ADDRESS, MR_REG_M, 1, &Settings, 1, 100);
//  HAL_Delay(10);
//}

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
  	  if (ret != HAL_OK) { *bufX = 999; return;    }
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
 // int16_t buf;
  ret=HAL_I2C_Mem_Read(i2c, MF_ADDRESS, TEMP_OUT_L_M_MULITREAD, 1, Data, 2, 100);
  if (ret != HAL_OK) {   return;   }
  *bufX = ((Data[1] << 8)|Data[0]);
 // *bufX=((float)buf*ACC_RESOLUTION)/(float)INT16_MAX;
}

void lsm303dlhc_read_mf_b(I2C_HandleTypeDef *i2c, uint8_t *buf) {
    uint8_t reg = OUT_X_H_M;

    HAL_StatusTypeDef ret;

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























