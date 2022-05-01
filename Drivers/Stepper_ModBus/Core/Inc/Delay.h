/*
 * Delay.h
 *
 *  Created on: Apr 26, 2022
 *      Author: elekt
 */

#ifndef INC_DELAY_H_
#define INC_DELAY_H_

#include "stm32f4xx_hal.h"

uint32_t TimingDelay;



/*
 * 		SystemCoreClock / divider = time
 * 		9 MHz = 9 000 000 Hz = 9 000 000 tick per sec = 9000 taktów na 1 ms
 */

void Delay_Init(uint32_t divider);

void Delay(uint32_t nTime);

void TimingDelay_Decrement(void);


#endif /* INC_DELAY_H_ */
