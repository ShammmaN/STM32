/*
 * L3GD20.c
 *
 *  Created on: Mar 24, 2022
 *      Author: elekt
 */

#include "L3GD20.h"
#include "spi.h"



void L3GD20_Read_Temp(SPI_HandleTypeDef *spi, float *Temp);

/*
Once the device is powered-up, it automatically downloads the calibration coefficients from
the embedded flash to the internal registers. When the boot procedure is completed, i.e.
after approximately 10 milliseconds, the device automatically enters power-down mode. To
turn on the device and gather angular rate data, it is necessary to select one of the
operating modes through CTRL_REG1 and to enable at least one of the axes.
The following general-purpose sequence can be used to configure the device:
  :
*/

void L3GD20_Init(SPI_HandleTypeDef *spi){


	SPI_Stop();
	HAL_Delay(20);

	SPI_Start();
	HAL_Delay(20);
	spiTxBuf[0]=0x20;
	spiTxBuf[1]=0xff;
	HAL_SPI_Transmit(spi,spiTxBuf,2,50);
	SPI_Stop();
	HAL_Delay(20);

	SPI_Start();
	HAL_Delay(20);
	spiTxBuf[0]=0x21;
	spiTxBuf[1]=0x00;
	HAL_SPI_Transmit(spi,spiTxBuf,2,50);
	SPI_Stop();
	HAL_Delay(20);

	SPI_Start();
	HAL_Delay(20);
	spiTxBuf[0]=0x22;
	spiTxBuf[1]=0x00;
	HAL_SPI_Transmit(spi,spiTxBuf,2,50);
	SPI_Stop();
	HAL_Delay(20);

	SPI_Start();
	HAL_Delay(20);
	spiTxBuf[0]=0x23;
	spiTxBuf[1]=0x20;
	HAL_SPI_Transmit(spi,spiTxBuf,2,50);
	SPI_Stop();
	HAL_Delay(20);

	SPI_Start();
	HAL_Delay(20);
	spiTxBuf[0]=0x24;
	spiTxBuf[1]=0x10;
	HAL_SPI_Transmit(spi,spiTxBuf,2,50);
	SPI_Stop();
	HAL_Delay(20);
}



/*
3.2 Using the status register
The device is provided with a STATUS_REG which should be polled to check when a new
set of data is available. The reads should be performed as follows
*/

void L3GD20_ReadXYZ(SPI_HandleTypeDef *spi, float *bufX, float *bufY, float *bufZ){



	volatile int16_t Raw_x=0;
	volatile int16_t Raw_y=0;
	volatile int16_t Raw_z=0;

	float difftime=0;

	int16_t averageWindow_X[AVERAGE_WINDOW_SIZE] = {0};
	int16_t averageWindow_Y[AVERAGE_WINDOW_SIZE] = {0};
	int16_t averageWindow_Z[AVERAGE_WINDOW_SIZE] = {0};

	uint32_t windowPosition = 0;
	int32_t tempSum_X = 0;
	int32_t tempSum_Y = 0;
	int32_t tempSum_Z = 0;

	switch(currentState)
	{
		//---------------------------------------------------------------------------
		//data
		case(L3GD20_fisrt):
			if(dataReadyFlag==L3GD20_DATA_READY)
			{
					SPI_Start();
					spiTxBuf[0]=0x28|0x80;
					HAL_SPI_Transmit(spi,spiTxBuf,1,50);
					HAL_SPI_Receive(spi,&spiRxBuf[1],1,50);
					SPI_Stop();

					SPI_Start();
					spiTxBuf[0]=0x29|0x80;
					HAL_SPI_Transmit(spi,spiTxBuf,1,50);
					HAL_SPI_Receive(spi,&spiRxBuf[2],1,50);
					SPI_Stop();

					SPI_Start();
					spiTxBuf[0]=0x2a|0x80;
					HAL_SPI_Transmit(spi,spiTxBuf,1,50);
					HAL_SPI_Receive(spi,&spiRxBuf[3],1,50);
					SPI_Stop();

					SPI_Start();
					spiTxBuf[0]=0x2b|0x80;
					HAL_SPI_Transmit(spi,spiTxBuf,1,50);
					HAL_SPI_Receive(spi,&spiRxBuf[4],1,50);
					SPI_Stop();

					SPI_Start();
					spiTxBuf[0]=0x2c|0x80;
					HAL_SPI_Transmit(spi,spiTxBuf,1,50);
					HAL_SPI_Receive(spi,&spiRxBuf[5],1,50);
					SPI_Stop();

					SPI_Start();
					spiTxBuf[0]=0x2d|0x80;
					HAL_SPI_Transmit(spi,spiTxBuf,1,50);
					HAL_SPI_Receive(spi,&spiRxBuf[6],1,50);
					SPI_Stop();

					currentState=L3GD20_second;
					dataReadyFlag=L3GD20_DATA_NOT_READY;
			}
			else
			{
			}

			break;
					//-----------------------------------------------------------------------------------
					//varibla
		case(L3GD20_second):
			Raw_x=(spiRxBuf[2]<<8)|spiRxBuf[1];
			Raw_y=(spiRxBuf[4]<<8)|spiRxBuf[3];
			Raw_z=(spiRxBuf[6]<<8)|spiRxBuf[5];

		if(currentcalistate==L3GD20_calibrated)
		{
			angleRate_x=(float) (Raw_x - (offset_x))*L3GD20_SENSITIVITY;
			angleRate_y=(float) (Raw_y - (offset_y))*L3GD20_SENSITIVITY;
			angleRate_z=(float) (Raw_z - (offset_z))*L3GD20_SENSITIVITY;
			difftime=0.003f;

			if((angleRate_x>Noise_X)||(angleRate_x<-Noise_X))
			{
				Angle_X+=((angleRate_x+LastAngleRate_X)*difftime)/(2.0f);
				LastAngleRate_X=angleRate_x;
			}
			else
			{
			}
			if((angleRate_y>Noise_Y)||(angleRate_y<-Noise_Y))
			{
				Angle_Y+=((angleRate_y+LastAngleRate_Y)*difftime)/(2.0f);
				LastAngleRate_Y=angleRate_y;
			}
			else
			{
			}
			if((angleRate_z>Noise_Z)||(angleRate_z<-Noise_Z))
			{
				Angle_Z+=((angleRate_z+LastAngleRate_Z)*difftime)/(2.0f);
				LastAngleRate_Z=angleRate_z;
			}
			else
			{
			}

		*bufX = Angle_X;
		*bufY = Angle_Y;
		*bufZ = Angle_Z;

		}
		else
		{
			switch(currentcalistate)
			{
				//---------------------------------------------------------------------------------------------------------
				case(L3GD20_collect_calibration_samples):
					calibrationBuffer_X[caliCounter]=Raw_x;
					calibrationBuffer_Y[caliCounter]=Raw_y;
					calibrationBuffer_Z[caliCounter]=Raw_z;
					caliCounter++;

					if(caliCounter>=CALIBRATION_BUFFER_LENGTH)
					{
						caliCounter=0;

						currentcalistate=L3GD20_process_calibration_samples;
					}
					else
					{
					}
					break;
				//----------------------------------------------------------------------------------------------------------
				case(L3GD20_process_calibration_samples):
					for(uint32_t idx=0; idx<CALIBRATION_BUFFER_LENGTH;idx++)
						{
							tempSum_X=tempSum_X-averageWindow_X[windowPosition]+calibrationBuffer_X[idx];
							tempSum_Y=tempSum_Y-averageWindow_Y[windowPosition]+calibrationBuffer_Y[idx];
							tempSum_Z=tempSum_Z-averageWindow_Z[windowPosition]+calibrationBuffer_Z[idx];

							averageWindow_X[windowPosition]=calibrationBuffer_X[idx];
							averageWindow_Y[windowPosition]=calibrationBuffer_Y[idx];
							averageWindow_Z[windowPosition]=calibrationBuffer_Z[idx];

							offset_x=tempSum_X/(int32_t)AVERAGE_WINDOW_SIZE;
							offset_y=tempSum_Y/(int32_t)AVERAGE_WINDOW_SIZE;
							offset_z=tempSum_Z/(int32_t)AVERAGE_WINDOW_SIZE;

							windowPosition++;

							if(windowPosition>=AVERAGE_WINDOW_SIZE)
							{
								windowPosition=0;
							}
							else
							{
							}

						}
						for(uint32_t idx=0;idx<CALIBRATION_BUFFER_LENGTH;idx++)
						{
							if(((int32_t)calibrationBuffer_X[idx]-offset_x)>TempNoise_X)
							{
								TempNoise_X=(int32_t)calibrationBuffer_X[idx]-offset_x;
							}
							else if(((int32_t)calibrationBuffer_X[idx]-offset_x)<-TempNoise_X)
							{
								TempNoise_X=-((int32_t)calibrationBuffer_X[idx]-offset_x);
							}

							if(((int32_t)calibrationBuffer_Y[idx]-offset_y)>TempNoise_Y)
							{
								TempNoise_Y=(int32_t)calibrationBuffer_Y[idx]-offset_y;
							}
							else if(((int32_t)calibrationBuffer_Y[idx]-offset_y)<-TempNoise_Y)
							{
								TempNoise_Y=-((int32_t)calibrationBuffer_Y[idx]-offset_y);
							}

							if(((int32_t)calibrationBuffer_Z[idx]-offset_z)>TempNoise_Z)
							{
								TempNoise_Z=(int32_t)calibrationBuffer_Z[idx]-offset_z;
							}
							else if(((int32_t)calibrationBuffer_Z[idx]-offset_z)<-TempNoise_Z)
							{
								TempNoise_Z=-((int32_t)calibrationBuffer_Z[idx]-offset_z);
							}
						}

						Noise_X=(float)TempNoise_X*L3GD20_SENSITIVITY;
						Noise_Y=(float)TempNoise_Y*L3GD20_SENSITIVITY;
						Noise_Z=(float)TempNoise_Z*L3GD20_SENSITIVITY;

						currentcalistate=L3GD20_calibrated;
						break;

				case(L3GD20_calibrated):
					break;

				default:
					break;
			}

		}
		currentState=L3GD20_fisrt;
		dataReadyFlag=L3GD20_DATA_READY;
		break;

				default:
					break;

	}




}
