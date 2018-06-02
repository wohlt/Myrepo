/*
 *	uart.h
 *
 *	Version		|	Author			|	Date		|	Changes made
 *  -------------------------------------------------------------------
 *	1.0			|	F. Moertl		|	08.04.2014	|
 *
 *
 *	Functions for control of the usart/rs232 interface
 *	Further information in munichmotorsport or SE-Labor wiki
 */

#ifndef USART_H_
#define USART_H_



void usart_init(uint32_t baudrate);
uint8_t usart_transmit_char(uint8_t byte);
void usart_transmit_string(char *string);
uint8_t usart_receive(char *receive_buffer);
uint8_t usart_write_it(uint8_t* data,uint8_t len);

#endif /* USART_H_ */