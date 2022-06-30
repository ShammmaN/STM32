/*
 * adc.c
 *
 *  Created on: 11 cze 2022
 *      Author: shammman
 */
#include   "adc.h"


/* ADC configured with 3 channels
 * ch2,ch3,ch5
 *
 * first  = ch5
 * second = ch2
 * third  = ch3
 * */

void ADC_PA1_Init(void)
{

	/***Configure the ADC GPIO pin***/

	/*Enable clock access to GPIOA*/
	RCC->AHB1ENR |= GPIOAEN;

	/*Set the mode of PA1 to analog*/
	GPIOA->MODER |= (1U<<2);
	GPIOA->MODER |= (1U<<3);


	/**Configure the ADC module**/

	/*Conversion sequence start*/
	RCC->APB2ENR |= ADC1EN;
	/*Conversion the sequence start*/
	ADC1->SQR3 = ADC_CH1;
	/*Conversion the sequence length*/
	ADC1->SQR1 = ADC_SEQ_LEN_1;
	/*Enable ADC module*/
	ADC1->CR2 |= CR2_ADC_ENABLE;
}


void start_conversion(void)
{
	// Start ADC conversion
	ADC1->CR2 |= CR2_ADC_SWSTART;
}


uint32_t adc_read()
{
	// Wait for confersion to be complete
	while(!(ADC1->SR & SR_EOC))	{	}
	// Read converted result
	return ADC1->DR;
}
