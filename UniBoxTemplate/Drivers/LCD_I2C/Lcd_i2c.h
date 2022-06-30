/*
 * Lcd_i2c.h
 *
 *  Created on: Jun 30, 2022
 *      Author: shammman
 */

#ifndef LCD_I2C_LCD_I2C_H_
#define LCD_I2C_LCD_I2C_H_

#include "stm32f4xx_hal.h"



void lcd_init (void);   // initialize lcd


void lcd_send_cmd (char cmd);  // send command to the lcd
void lcd_send_data (char data);  // send data to the lcd
void lcd_send_string (char *str);  // send string to the lcd
void lcd_clear (void);

void lcd_line_1 (char *str);  // send string to the lcd
void lcd_line_2 (char *str);  // send string to the lcd
void lcd_line_3 (char *str);  // send string to the lcd
void lcd_line_4 (char *str);  // send string to the lcd


void lcd_set_cursor(uint8_t a, uint8_t b);




#endif /* LCD_I2C_LCD_I2C_H_ */
