/*
 *	uart.c
 *
 *	Version		|	Author			|	Date		|	Changes made
 *  -------------------------------------------------------------------
 *	1.0			|	F. Moertl		|	08.04.2014	|	File created!
 *  2.0			|	T. Wohl			|	17.04.2018	|	Added interrupt functionality for sending
 *
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include "header.h"
#include "usart.h"


#define TX_COMPLETE 1
#define TX_BUSY 0
#define USART_SEND_BUFFER_SIZE 64
#define USART_SEND_BUFFER_LAST_ELEMENT USART_SEND_BUFFER_SIZE-1
#define USART_RECEIVE_BUFFER_SIZE 16


static uint8_t usart_tx_buffer[USART_SEND_BUFFER_SIZE];
static uint8_t tx_head_idx = 0,
tx_tail_idx = 0;
static uint8_t usart_tx_complete = TX_COMPLETE;


//basic polling usart

void usart_init(uint32_t baudrate)
{
	LINCR |= (1<<LSWRES);
	LINBRR = (((F_CPU/baudrate)/32)-1);
	LINCR |= (1<<LENA)|(1<<LCMD2)|(1<<LCMD1)|(1<<LCMD0);
	DDRD  |=  (1<<PORTD3);      // output UART_TX Pin 2
	DDRD  &= ~(1<<PORTD4);       // input UART_RX Pin 12
}


uint8_t usart_transmit_char(uint8_t byte)
{
	if (!(LINSIR & (1 << LBUSY)))				//check: UART not busy?
	{
		LINDAT = byte;
		return 1;	
	}
	else
	{
		return 0;
	}
}

void usart_transmit_string(char *string) //waits for transmission, slow! faster version -> use usart_write_it
{
	while (*string)
	{
		while (!(usart_transmit_char(*string)));
		string++;
	}
}



uint8_t usart_receive(char *receive_buffer) //abgeaendert
{
	if (LINSIR & (1 << LRXOK))				//check: new data received?
	{          
		*receive_buffer = LINDAT;
		return 1;
	}
	else
	{
		return 0;
	}
}


uint8_t usart_write_it(uint8_t* data,uint8_t len)
{
	for(uint8_t i = 0; i < len; i++)		//Copy data to ring buffer
	{
		usart_tx_buffer[tx_head_idx] = data[i];
		tx_head_idx = tx_head_idx + 1 > USART_SEND_BUFFER_LAST_ELEMENT ? 0 : tx_head_idx + 1;		//Increment head idx
		
		if(tx_head_idx == tx_tail_idx)		//Head overtakes tail! we cant transmit the whole message because otherwise old data will be lost!
		{
			tx_head_idx = tx_head_idx - 1 < 0 ? USART_SEND_BUFFER_LAST_ELEMENT : tx_head_idx - 1;	//Set head pointer back were it was before the last iteration step
			return 1;
		}
	}
	
	if(usart_tx_complete)							//Uart currently sending?
	{
		usart_tx_complete = TX_BUSY;
		LINENIR |= (1<<LENRXOK);					//Enable Transmit interrupt
		LINDAT = usart_tx_buffer[tx_tail_idx];		//Start transmission of first char
		tx_tail_idx = tx_tail_idx + 1 > USART_SEND_BUFFER_LAST_ELEMENT ? 0 : tx_tail_idx + 1;		//Increment tail idx
	}
	
	return 0;
}



ISR(LIN_TC_vect)
{
	if((LINSIR & (1<<LTXOK))) //transmit interrupt?
	{
		if(tx_tail_idx != tx_head_idx)								//tail reached head?
		{
			LINDAT = usart_tx_buffer[tx_tail_idx];					//Start transmission of next char
			tx_tail_idx = tx_tail_idx + 1 > USART_SEND_BUFFER_LAST_ELEMENT ? 0 : tx_tail_idx + 1;		//Increment tail index
		}
		else														//transmission is complete! disable interrupt
		{
			usart_tx_complete = TX_COMPLETE;
			LINENIR &= ~(1<<LENTXOK);
			LINSIR |= (1<<LTXOK);				//Reset interrupt flag! (in other case writing LINDAT clears this flag)
		}
		
	}
}

