/*
 * Myconfig.c
 *
 *  Created on: Jun 5, 2022
 *      Author: shammman
 */


#include "Myconfig.h"

void MyGPIOInit()
{

	//Enable OTGUFEN PORT
	RCC->AHB2ENR |= (1U<<7);

	//Enable GPIOD Port
	RCC->AHB1ENR |= GPIODEN;



	//Enable pin PD12 output mode
	GPIOD->MODER |=(1U<<24);
	GPIOD->MODER &=~(1U<<25);

	//Enable pin PD13 output mode
	GPIOD->MODER |=(1U<<26);
	GPIOD->MODER &=~(1U<<27);

	//Enable pin PD14 output mode
	GPIOD->MODER |=(1U<<28);
	GPIOD->MODER &=~(1U<<29);

	//Enable pin PD15 output mode
	GPIOD->MODER |=(1U<<30);
	GPIOD->MODER &=~(1U<<31);

	//Enable PA0 Input mode
	GPIOA->MODER &=~(1U<<0);
	GPIOA->MODER &=~(1U<<1);

	//Enable PA11 Alternate function
    GPIOA->MODER |= (1U<<23);
	GPIOA->MODER &=~(1U<<22);

	//Enable PA12 Alternate function
	GPIOA->MODER |= (1U<<25);
	GPIOA->MODER &=~(1U<<24);

}



void GPIO_SET(GPIO_TypeDef *PORT,uint16_t GPIO_PIN)
{

	PORT->ODR |=GPIO_PIN;
}


void GPIO_RESET(GPIO_TypeDef *PORT,uint16_t GPIO_PIN)
{
	PORT->ODR &=GPIO_PIN;

}


void GPIO_PIN_TOOGLE(GPIO_TypeDef *PORT,uint16_t GPIO_PIN)
{

	PORT->ODR ^=GPIO_PIN;
}

uint8_t GPIO_READ(GPIO_TypeDef *PORT,uint16_t GPIO_PIN)
{
	return PORT->IDR & GPIO_PIN;
}

