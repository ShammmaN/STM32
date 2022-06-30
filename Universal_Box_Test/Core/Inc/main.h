/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define B2_Pin GPIO_PIN_14
#define B2_GPIO_Port GPIOB
#define B2_EXTI_IRQn EXTI15_10_IRQn
#define B1_Pin GPIO_PIN_15
#define B1_GPIO_Port GPIOB
#define B1_EXTI_IRQn EXTI15_10_IRQn
#define B6_Pin GPIO_PIN_8
#define B6_GPIO_Port GPIOD
#define B6_EXTI_IRQn EXTI9_5_IRQn
#define B5_Pin GPIO_PIN_9
#define B5_GPIO_Port GPIOD
#define B5_EXTI_IRQn EXTI9_5_IRQn
#define B4_Pin GPIO_PIN_10
#define B4_GPIO_Port GPIOD
#define B4_EXTI_IRQn EXTI15_10_IRQn
#define B3_Pin GPIO_PIN_11
#define B3_GPIO_Port GPIOD
#define B3_EXTI_IRQn EXTI15_10_IRQn
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
