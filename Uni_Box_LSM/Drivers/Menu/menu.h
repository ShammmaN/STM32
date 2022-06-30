/*
 * menu.h
 *
 *  Created on: Jun 28, 2022
 *      Author: shammman
 */
#include "stm32f4xx.h"


#define LCD_ROWS 4
#define LCD_COLS 20


void buf_locate(int, int);
void buf_char(char);
void buf_clear(void);
void lcd_refresh(void);
void buf_str(char *);
void buf_str_XY(int, int, char *);
void buf_int(int);
void buf_clear_menu(void);

char lcd_buf[LCD_ROWS][LCD_COLS];
char lcd_buf_old[LCD_ROWS][LCD_COLS];
int  lcd_buf_x, lcd_buf_y;

//typedef void (*menu_t)(void);


