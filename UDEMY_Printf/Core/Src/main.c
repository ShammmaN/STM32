
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "Myconfig.h"
#include "MyUART.h"
//#include <stdio.h>



uint32_t sleep = 1000000;



int main(void)
{

  MyGPIOInit();
  uart2_TX_init();

  while (1)
  {

	 printf("Hello World\n");

	  GPIO_PIN_TOOGLE(GPIOD, LED_1);

 	  for(int j=0;j < sleep;j++){}

   }



}

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


