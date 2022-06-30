/*
 * myUART.h
 *
 *  Created on: Jun 5, 2022
 *      Author: shammman
 */

#ifndef INC_MYUART_H_
#define INC_MYUART_H_

#include "stm32f4xx.h"
#include <stdio.h>



/*USART 2 it's connected to PA2 & PA3 in GPIOA port*/
#define GPIOAEN 	(1U<<0)
//RCC enabling register 17
#define UART2EN 	(1U<<17)
// Default system frequency
#define SYS_FREQ 	16000000
#define APB1_CLK	SYS_FREQ
// Define uart baudrate
#define UART_BAUDRATE 115200

#define CR1_TE		(1U<<3)
#define CR1_RE		(1U<<2)
#define CR1_UE		(1U<<13)
#define SR_TXE		(1U<<7)

void uart2_TX_init();
static uint16_t compute_uart_br(uint32_t PeriphClock, uint32_t Baudrate);
static void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClock, uint32_t Baudrate);
  int __io_putchar(int ch);

void uart_write(int ch);



#endif /* INC_MYUART_H_ */
