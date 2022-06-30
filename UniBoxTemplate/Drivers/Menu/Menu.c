/*
 * Menu.c
 *
 *  Created on: Jun 30, 2022
 *      Author: shammman
 */


#include "Menu.h"
#include "Lcd_i2c.h"
#include "Keypad.h"


void menu_init(void)
{
	lcd_init();

	lcd_line_1("   EL-TECH SERWIS");
	lcd_line_2("--------------------");
	lcd_line_3("     LOADING");
	animation();

}


void menu_set(uint16_t GPIO_Pin)
{
	menu(Key_Read(GPIO_Pin));

}


void menu(uint16_t Position)
{

	switch(Position)
	{
	case 0: menu0(); break;

//	case 10: menu10(); break;
//	case 11: menu11(); break;
//	case 12: menu12(); break;
//	case 13: menu13(); break;
//	case 14: menu14(); break;
//	case 15: menu15(); break;


	case 1: menu1(); break;

//	case 20: menu20(); break;
//	case 21: menu21(); break;
//	case 22: menu22(); break;
//	case 23: menu23(); break;
//	case 24: menu24(); break;
//	case 25: menu25(); break;
//
//	case 3: menu3(); break;
//
//	case 30: menu30(); break;
//	case 31: menu31(); break;
//	case 32: menu32(); break;
//	case 33: menu33(); break;
//	case 34: menu34(); break;
//	case 35: menu35(); break;
//
//	case 4: menu4(); break;
//
//	case 40: menu40(); break;
//	case 41: menu41(); break;
//	case 42: menu42(); break;
//	case 43: menu43(); break;
//	case 44: menu44(); break;
//	case 45: menu45(); break;
//
//	case 5: menu5(); break;
//
//	case 50: menu50(); break;
//	case 51: menu51(); break;
//	case 52: menu52(); break;
//	case 53: menu53(); break;
//	case 54: menu54(); break;
//	case 55: menu55(); break;
//
//	case 6: menu6(); break;
//
//	case 60: menu60(); break;
//	case 61: menu61(); break;
//	case 62: menu62(); break;
//	case 63: menu63(); break;
//	case 64: menu64(); break;
//	case 65: menu65(); break;

	}

}



static void menu0()
{
	lcd_line_1("     MAIN MENU      ");
	lcd_line_2("                    ");
	lcd_line_3("->   ACCELERO     <-");
	lcd_line_4("     MAGNETO        ");

}

static void menu1()
{
	lcd_line_1("     MAIN MENU      ");
	lcd_line_2("                    ");
	lcd_line_3("     ACCELERO       ");
	lcd_line_4("->   MAGNETO      <-");

}


void animation(void)
{
	lcd_set_cursor(0, 3);
	for(uint8_t i =0; i<20; i++)
	{
	 lcd_send_string("|");
	 HAL_Delay(35);
	}
	HAL_Delay(250);
}

void menu10()
{

}
