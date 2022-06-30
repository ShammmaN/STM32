/*
 * LSM303DLHC.c
 *
 *  Created on: 19 cze 2022
 *      Author: shammman
 */


#include "LSM303DLHC.h"


void lsm303dlhc_init_la() {

    // wypelnienie zmiennej konfiguracyjnej odpowiednimi opcjami
	LSM303DLHC_TypeDef sensor ={0};

	sensor.CTRL_REG1 = CTRL_REG1_Xen|CTRL_REG1_Yen|CTRL_REG1_Zen|CTRL_REG1_100Hz;

//
//    uint8_t Settings = Xen | Yen | Zen | ODR_100Hz;
//    HAL_StatusTypeDef ret;
//    // Wpisanie konfiguracji do rejestru akcelerometru
//    ret = HAL_I2C_Mem_Write(i2c, LA_ADDRESS, CTRL_REG1_A, 1, &Settings, 1, 100);
//    if (ret != HAL_OK) {
//          return;
//      }









}
