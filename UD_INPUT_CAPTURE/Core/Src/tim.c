/*
 * tim.c
 *
 *  Created on: 13 cze 2022
 *      Author: shammman
 */


#include "tim.h"



void tim2_1hz_init(void)
{

	//Enable clock access to tim2
	RCC->APB1ENR |= RCC_TIM2_EN;

	//Set prescaler value
	TIM2->PSC = 1600-1;		// 16 000 000 / 1 600  = 10 000

	//Set auto-reload value
	TIM2->ARR = 5000-1;	// 10 000 / 10 000 = 1;

	//Clear counter
	TIM2->CNT = 0;

	//Enable timer
//	TIM2->CR1 |= CEN;

}



void tim2_pa5_output_compare(void)
{

	//Configuration PA5 pin

	//Enable clock acces to GPIOA
	RCC->AHB1ENR |= GPIOAEN;
	//Set pa5 mode to alternate function
	GPIOA->MODER |=(1U<<11);
 	GPIOA->MODER &=~(1U<<10);
			//Set PA5 alternate function type to TIM2_CH1
	GPIOA->AFR[0] |= AFR5_TIM;

	//Configuration TIMER 2
	//Enable clock access to tim2
	RCC->APB1ENR |= RCC_TIM2_EN;

	//Set prescaler value
	TIM2->PSC = 1600-1;		// 16 000 000 / 1 600  = 10 000

	//Set auto-reload value
	TIM2->ARR = 10000-1;	// 10 000 / 10 000 = 1;

	//Set output compare toogle mode
	//Enable tim2 ch1 in compar mode 		001 -> toogle mode ch 1
	TIM2->CCMR1 |=  (1U<<4);
	TIM2->CCMR1 |=  (1U<<5);
	TIM2->CCMR1 &= ~(1U<<6);

	TIM2->CCER |= CCER_CC1E;
	//Clear counter
	TIM2->CNT = 0;

	//Enable timer
	TIM2->CR1 |= CR1_CEN;

}



void tim3_input_capture(void)
{

	//Configuration PA5 pin

	//Enable clock acces to GPIOA
	RCC->AHB1ENR |= GPIOAEN;
	//Set pa5 mode to alternate function
	GPIOA->MODER |=(1U<<11);
 	GPIOA->MODER &=~(1U<<10);
			//Set PA5 alternate function type to TIM2_CH1
	GPIOA->AFR[0] |= AFR5_TIM;

	//Configuration TIMER 3
	//Enable clock access to tim2
	RCC->APB1ENR |= RCC_TIM2_EN;

	//Set prescaler value
	TIM2->PSC = 1600-1;		// 16 000 000 / 1 600  = 10 000

	//Set auto-reload value
	TIM2->ARR = 10000-1;	// 10 000 / 10 000 = 1;

	//Set output compare toogle mode
	//Enable tim2 ch1 in compar mode 		001 -> toogle mode ch 1
	TIM2->CCMR1 |=  (1U<<4);
	TIM2->CCMR1 |=  (1U<<5);
	TIM2->CCMR1 &= ~(1U<<6);

	TIM2->CCER |= CCER_CC1E;
	//Clear counter
	TIM2->CNT = 0;

	//Enable timer
	TIM2->CR1 |= CR1_CEN;

}


