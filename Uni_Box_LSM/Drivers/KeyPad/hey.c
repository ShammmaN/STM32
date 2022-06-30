/*
 * hey.c
 *
 *  Created on: Jun 28, 2022
 *      Author: shammman
 */
#include "stm32f4xx.h"
#include "./key.h"
#include "main.h"

uint16_t Position =1;
volatile uint16_t i=80;
char text[20];
volatile static uint8_t cnt=0;
volatile static uint8_t st1=0,st2=0,st3=0;


uint8_t debouncer()
{
	//TODO: make a debouncer

return cnt;
}




void Key_Read(uint16_t GPIO_Pin)
{




	switch(GPIO_Pin)
		{



		case B1_Pin :
				lcd_clear();
				lcd_line_1("Lewo");
				Position = Position/10;
				sprintf(text, "Pozycja = %d",Position);
				lcd_line_4(text);

				break;


		case B2_Pin :


				lcd_clear();
				lcd_line_1("Gora");
				Position +=1;
				sprintf(text, "Pozycja = %d",Position);
				lcd_line_4(text);
				break;


		case B3_Pin :

				lcd_clear();
				lcd_line_1("Plus");
				lcd_line_2("Wartosc i : ");
				lcd_line_4(text);
				i++;
				break;

		case B4_Pin :

				lcd_clear();
				lcd_line_1("Dol");
				Position -=1;
				sprintf(text, "Pozycja = %d",Position);
				lcd_line_4(text);
				break;


		case B5_Pin :

				lcd_clear();
				lcd_line_1("Minus");
				lcd_line_2("Wartosc i : ");

				lcd_line_4(text);

				i--;
				break;

		case B6_Pin :

				lcd_clear();
				lcd_line_1("Prawo");
				Position =Position*10;
				sprintf(text, "Pozycja = %d",Position);
				lcd_line_4(text);
				break;

			}



}