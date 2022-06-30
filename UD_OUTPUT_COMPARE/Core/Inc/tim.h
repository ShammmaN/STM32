/*
 * tim.h
 *
 *  Created on: 13 cze 2022
 *      Author: shammman
 */

#ifndef INC_TIM_H_
#define INC_TIM_H_



#include "stm32f4xx.h"

#define GPIOAEN			(1U<<0)
#define GPIOA_AF		(1U<<11)| (~(1U<<10))


#define RCC_TIM2_EN		(1U<<0)
#define CR1_CEN			(1U<<0)
#define SR_UIF			(1U<<0)
#define CCR1_CC1E		(1U<<0)
#define OC_TOOGLE		((1U<<4)|(1U<<5))
#define AFR5_TIM		(1U<<20)
#define CCER_CC1E		(1U<<0)


void tim2_1hz_init(void);

void tim2_pa5_output_compare(void);

#endif /* INC_TIM_H_ */
