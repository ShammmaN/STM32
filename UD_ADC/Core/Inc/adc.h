/*
 * adc.h
 *
 *  Created on: 11 cze 2022
 *      Author: shammman
 */

#ifndef INC_ADC_H_
#define INC_ADC_H_

#include <stm32f4xx.h>

#define ADC1EN		(1U<<8)
#define GPIOAEN		(1U<<0)

#define ADC_CH1		(1U<<0)

//#define ADC_CH5		(1U<<)

#define ADC_SEQ_LEN_1	0x00

#define CR2_ADC_SWSTART (1U<<30)
#define CR2_ADC_ENABLE	(1U<<0)

#define SR_EOC			(1U<<1)




void ADC_PA1_Init(void);
void start_conversion(void);
uint32_t adc_read();

#endif /* INC_ADC_H_ */

