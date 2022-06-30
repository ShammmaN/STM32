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
	TIM2->CR1 |= CEN;

}



