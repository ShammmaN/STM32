/*
 * tim.h
 *
 *  Created on: 13 cze 2022
 *      Author: shammman
 */

#ifndef INC_TIM_H_
#define INC_TIM_H_



#include "stm32f4xx.h"

#define RCC_TIM2_EN		(1U<<0)
#define CEN				(1U<<0)
#define SR_UIF			(1U<<0)



void tim2_1hz_init(void);

#endif /* INC_TIM_H_ */
