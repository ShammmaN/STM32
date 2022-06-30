/*
 * myUART.c
 *
 *  Created on: Jun 5, 2022
 *      Author: shammman
 */

#include "MyUART.h"



void uart2_TX_init()
{
	/*****************Configure uart gpio pin ******************/
	/*Enable clock access to gpioa*/
	//Enable GPIOA Port
	RCC->AHB1ENR |= GPIOAEN;
	/*Set PA2 mode to alternate function mode*/

	//Set alternate function for PA2
	GPIOA->MODER &=~(1U<<4);
	GPIOA->MODER |=(1U<<5);

	//Set alternate function for PA3
	GPIOA->MODER &=~(1U<<4);
	GPIOA->MODER |=(1U<<5);


	//Set alternate function register AF7 (0111) for PA2
	GPIOA->AFR[0] |= (1U<<8);
	GPIOA->AFR[0] |= (1U<<9);
	GPIOA->AFR[0] |= (1U<<10);
	GPIOA->AFR[0] &=~(1U<<11);

	//Set alternate function register AF7 (0111) for PA3
	GPIOA->AFR[0] |= (1U<<12);
	GPIOA->AFR[0] |= (1U<<13);
	GPIOA->AFR[0] |= (1U<<14);
	GPIOA->AFR[0] &=~(1U<<15);



	/*****************Configure uart module*********************/
	/*Enable clock access to uart2*/
	RCC->APB1ENR |= UART2EN;

	/*Configure baudrate*/
	uart_set_baudrate(USART2, APB1_CLK, UART_BAUDRATE);

	/*Configure the transfer direction*/
	USART2->CR1 = CR1_TE;	//Transmitter enable & clearing
	//USART2->CR1 |=CR1_RE;	//Receiver enable

	/*Enable uart module*/
	USART2->CR1 |=CR1_UE;

	/*Enabnle USART Word Length*/
	USART2->CR1 &= ~(1U<<12);


}

  int __io_putchar(int ch)
	{
		uart_write(ch);
		return ch;
	}


void uart_write(int ch)
{

	//Make sure transmit data register is empty
	while(!(USART2->SR & SR_TXE)){};
	//Write transmit data register
	USART2->DR = (ch & 0xFFU);

}


static void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClock, uint32_t Baudrate)
{
	USARTx->BRR = compute_uart_br(PeriphClock,Baudrate);
}

static uint16_t compute_uart_br(uint32_t PeriphClock, uint32_t Baudrate)
{
	return ((PeriphClock+ (Baudrate/2U))/Baudrate);
}

/*
example from https://cpp.hotexamples.com/examples/-/-/USART_BRR/cpp-usart_brr-function-examples.html

USART_BRR(base) = ((2 * cpuclock) + baudrate) / (2 * baudrate);
USART_CR1(base) &= ~USART_CR1_M; /* 8 data bits  //
USART_CR1(base) = (USART_CR1(base) & ~USART_PARITY_MASK) |
		   USART_PARITY_NONE;
USART_CR2(base) = (USART_CR2(base) & ~USART_CR2_STOPBITS_MASK) |
		   USART_STOPBITS_1;
USART_CR3(base) = (USART_CR3(base) & ~USART_FLOWCONTROL_MASK) |
		   USART_FLOWCONTROL_NONE;
*/
