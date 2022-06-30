/*
 * Myconfig.h
 *
 *  Created on: Jun 5, 2022
 *      Author: shammman
 */

#ifndef INC_MYCONFIG_H_
#define INC_MYCONFIG_H_

#include "stm32f4xx.h"

#define GPIOAEN (1U<<0)
#define GPIOBEN (1U<<1)
#define GPIOCEN (1U<<2)
#define GPIODEN (1U<<3)
#define GPIOEEN (1U<<4)

#define PIN0    (1U<<0)
#define PIN12	(1U<<12)
#define PIN13	(1U<<13)
#define PIN14	(1U<<14)
#define PIN15	(1U<<15)



#define LED_1	PIN12
#define LED_2	PIN13
#define LED_3	PIN14
#define LED_4	PIN15

#define BTN	PIN0


void MyGPIOInit();

void GPIO_SET(GPIO_TypeDef *PORT,uint16_t GPIO_PIN);
void GPIO_RESET(GPIO_TypeDef *PORT,uint16_t GPIO_PIN);
void GPIO_PIN_TOOGLE(GPIO_TypeDef *PORT,uint16_t GPIO_PIN);
uint8_t GPIO_READ(GPIO_TypeDef *PORT,uint16_t GPIO_PIN);



#endif /* INC_MYCONFIG_H_ */
