/*
 * menu.c
 *
 *  Created on: Jun 28, 2022
 *      Author: shammman
 */
#include "menu.h"


void menu(uint16_t Position)
{

	switch(Position)
	{
	case 1: menu1(); break;

	case 10: menu10(); break;
	case 11: menu11(); break;
	case 12: menu12(); break;
	case 13: menu13(); break;
	case 14: menu14(); break;
	case 15: menu15(); break;


	case 2: menu2(); break;

	case 20: menu20(); break;
	case 21: menu21(); break;
	case 22: menu22(); break;
	case 23: menu23(); break;
	case 24: menu24(); break;
	case 25: menu25(); break;

	case 3: menu3(); break;

	case 30: menu30(); break;
	case 31: menu31(); break;
	case 32: menu32(); break;
	case 33: menu33(); break;
	case 34: menu34(); break;
	case 35: menu35(); break;

	case 4: menu4(); break;

	case 40: menu40(); break;
	case 41: menu41(); break;
	case 42: menu42(); break;
	case 43: menu43(); break;
	case 44: menu44(); break;
	case 45: menu45(); break;

	case 5: menu5(); break;

	case 50: menu50(); break;
	case 51: menu51(); break;
	case 52: menu52(); break;
	case 53: menu53(); break;
	case 54: menu54(); break;
	case 55: menu55(); break;

	case 6: menu6(); break;

	case 60: menu60(); break;
	case 61: menu61(); break;
	case 62: menu62(); break;
	case 63: menu63(); break;
	case 64: menu64(); break;
	case 65: menu65(); break;

	}

}



void menu1()
{
	lcd_line_1("     MAIN MENU      ");
	lcd_line_2("                    ");
	lcd_line_3("->   ACCELERO     <-");
	lcd_line_4("     MAGNETO        ");

}

void menu2()
{
	lcd_line_1("     MAIN MENU      ");
	lcd_line_2("                    ");
	lcd_line_3("     ACCELERO       ");
	lcd_line_4("->   MAGNETO      <-");

}