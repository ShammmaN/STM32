

#include "stm32f4xx.h"
//#include "stm32f4xx_gpio.h"

#include "stm32f4xx_gpio.h"



GPIO_InitTypeDef* LED;


int main(){

	LED->GPIO_Mode = GPIO_Mode_OUT;
	LED->GPIO_Pin = GPIO_Pin_13;



	GPIO_Init(GPIOA,LED);

return 0;
}
