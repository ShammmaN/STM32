/*
 * hey.c
 *
 *  Created on: Jun 28, 2022
 *      Author: shammman
 */
#include "stm32f4xx.h"
#include "./key.h"
#include "main.h"


volatile uint16_t i=80;
char text[20];


void Key_Read(uint16_t GPIO_Pin)
{


	 sprintf(text, "var= %d",i);

	switch(GPIO_Pin)
		{



		case B1_Pin :
				lcd_clear();
				lcd_line_1("Lewo");
				break;

		case B2_Pin :

				lcd_clear();
				lcd_line_1("Gora");
				break;

		case B3_Pin :

				lcd_clear();
				lcd_line_1("Plus");
				lcd_line_2("Wartosc i : ");
				lcd_line_3(text);
				i++;
				break;

		case B4_Pin :

				lcd_clear();
				lcd_line_1("Dol");
				break;

		case B5_Pin :

				lcd_clear();
				lcd_line_1("Minus");
				lcd_line_2("Wartosc i : ");
				lcd_line_3(text);

				i--;
				break;

		case B6_Pin :

				lcd_clear();
				lcd_line_1("Prawo");
				break;

			}



}
