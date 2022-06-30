#include "systick.h"
#include "stm32f4xx.h"

void systickDelayMs( int delay)
{
	/*Configure systick */
	SysTick->LOAD = SYSTICK_LOAD_VAL;

	/*Clear systick current value register*/
	SysTick->VAL =0;

	/*Enable systick amd select internal clk src*/
	SysTick->CTRL = CTRL_ENABLE | CTRL_CLKSRC;

	for(int i =0; i<delay;i++)
	{
		//Wait until COUNTFLAG is set
		while((SysTick->CTRL & CTRL_COUNTFLAG)==0)
		{

		}
		SysTick->CTRL = 0;
	}

}
