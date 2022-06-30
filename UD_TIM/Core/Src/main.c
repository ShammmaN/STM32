/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "Myconfig.h"
#include "MyUART.h"
#include "tim.h"




void SystemClock_Config(void);


//int __io_putchar(int ch)
//	{
//		uart_write(ch);
//		return ch;
//	}


int main(void)
{
	int i=0;
//  HAL_Init();
//  SystemClock_Config();

  MyGPIOInit();
  uart2_TX_init();
  tim2_1hz_init();

  uint32_t sleep = 1000000;
  uint32_t result;
  while (1)
  {

	 printf("%ld\n",result);

	 while(!(TIM2->SR & SR_UIF)){}

	 //Clear UIF
	 TIM2->SR &=~SR_UIF;

	 GPIO_PIN_TOOGLE(GPIOD, LED_1);

 	//  for(int j=0;j < sleep;j++){}

//	  if(GPIO_READ(GPIOA,BTN))
//	  {
//	  GPIO_SET(GPIOD, LED_1);
//	  for(int i=0; i<sleep; i++){}
//
//	  GPIO_RESET(GPIOD, LED_1);
//	  for(int i=0; i<sleep; i++){}
//
//	  GPIO_SET(GPIOD, LED_2);
//	  for(int i=0; i<sleep; i++){}
//
//	  GPIO_RESET(GPIOD, LED_2);
//	  for(int i=0; i<sleep; i++){}
//
//	  GPIO_SET(GPIOD, LED_3);
//	  for(int i=0; i<sleep; i++){}
//
//	  GPIO_RESET(GPIOD, LED_3);
//	  for(int i=0; i<sleep; i++){}
//
//	  GPIO_SET(GPIOD, LED_4);
//	  for(int i=0; i<sleep; i++){}
//
//	  GPIO_RESET(GPIOD, LED_4);
//	  for(int i=0; i<sleep; i++){}
//	  }
//	  else{
//		  GPIO_RESET(GPIOD, LED_1);
//		  GPIO_RESET(GPIOD, LED_2);
//		  GPIO_RESET(GPIOD, LED_3);
//		  GPIO_RESET(GPIOD, LED_4);
//
//	  }

   }



}


void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 192;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
  RCC_OscInitStruct.PLL.PLLQ = 8;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_3) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
