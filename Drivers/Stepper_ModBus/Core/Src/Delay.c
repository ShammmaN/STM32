/*
 * Delay.c
 *
 *  Created on: Apr 26, 2022
 *      Author: elekt
 */


#include "Delay.h"


void Delay_Init(uint32_t divider){
if (SysTick_Config(SystemCoreClock / divider))
	{
		while (1); //W przypadku błędu program zawiesi się w pętli nieskończonej
	}
}



void Delay(uint32_t nTime)
{
  TimingDelay = nTime;

  while(TimingDelay != 0);
}

void TimingDelay_Decrement(void)
{
  if (TimingDelay != 0x00)
  {
    TimingDelay--;
  }
}
