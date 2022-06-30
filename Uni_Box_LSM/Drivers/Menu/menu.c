/*
 * menu.c
 *
 *  Created on: Jun 28, 2022
 *      Author: shammman
 */
#include "menu.h"




typedef struct menu_t {
  const char * name;
  menu_t* next;
  menu_t* prev;
  menu_t* child;
  menu_t* parent;
  void (*menu_function)(void);
}menu_t;


menu1={ "CONFIGRATION", &menu2, &menu5, &sub_menu1_1, NULL, NULL };     // utworzenie struktury

menu_t menu1;
  menu_t sub_menu1_1;
  menu_t sub_menu1_2;
menu_t menu2;
  menu_t sub_menu2_1;
  menu_t sub_menu2_2;
menu_t menu3;
  menu_t sub_menu3_1;
menu_t menu4;
  menu_t sub_menu4_1;
    menu_t sub_menu4_1_1;
      menu_t sub_menu4_1_1_1;
      menu_t sub_menu4_1_1_2;
      menu_t sub_menu4_1_1_3;
      menu_t sub_menu4_1_1_4;
      menu_t sub_menu4_1_1_5;
      menu_t sub_menu4_1_1_6;
      menu_t sub_menu4_1_1_7;
      menu_t sub_menu4_1_1_8;
    menu_t sub_menu4_1_2;
      menu_t sub_menu4_1_2_1;
      menu_t sub_menu4_1_2_2;
      menu_t sub_menu4_1_2_3;
    menu_t sub_menu4_1_3;
    menu_t sub_menu4_1_4;
  menu_t sub_menu4_2;
menu_t menu5;
