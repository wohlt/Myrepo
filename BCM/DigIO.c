/*
 *	DigIO.c
 *
 *	Version		|	Author			|	Date		|	Changes made   	
 *  -------------------------------------------------------------------
 *	1.0			|	F. Moertl		|	01.03.2015	|	
 *		
 *
 */

#include <avr/io.h>
#include "header.h"
#include "DigIO.h"

void digital_output_init(uint8_t pin_define)
{
	switch (pin_define)									//not all PIN_... defines appear here - some of them refer to pins which are already taken care of
	{
	
		case PIN_PWM1:	//PORTD &= ~(1<<PORTD0);		//set pin State to low
						DDRD |= (1<<PORTD0);		//configure pin as output
						break;							
						
		case PIN_PWM2:	//PORTC &= ~(1<<PORTC0);		//set pin State to low
						DDRC |= (1<<PORTC0);		//configure pin as output
						break;
						
		case PIN_PWM3:	//PORTD &= ~(1<<PORTD2);		//set pin State to low
						DDRD |= (1<<PORTD2);		//configure pin as output
						break;
						
		case PIN_PWM4:	//PORTC &= ~(1<<PORTC1);		//set pin State to low
						DDRC |= (1<<PORTC1);		//configure pin as output
						break;
						
		case PIN_PWM5:	//PORTB &= ~(1<<PORTB6);		//set pin State to low
						DDRB |= (1<<PORTB6);		//configure pin as output
						break;
						
		case PIN_PWM6:	//PORTD &= ~(1<<PORTD3);		//set pin State to low
						DDRD |= (1<<PORTD3);		//configure pin as output
						break;
						
		case PIN_PWM7:	//PORTB &= ~(1<<PORTB0);		//set pin State to low
						DDRB |= (1<<PORTB0);		//configure pin as output
						break;
						
		case PIN_PWM8:	//PORTB &= ~(1<<PORTB1);		//set pin State to low
						DDRB |= (1<<PORTB1);		//configure pin as output
						break;
						
		case PIN_PWM9:	//PORTB &= ~(1<<PORTB7);		//set pin State to low
						DDRB |= (1<<PORTB7);		//configure pin as output
						break;

		case PIN_AN10:	//PORTD &= ~(1<<PORTD4);		//set pin State to low
						DDRD |= (1<<PORTD4);		//configure pin as output
						break;
						
		case PIN_AN1:	//PORTE &= ~(1<<PORTE2);		//set pin State to low
						DDRE |= (1<<PORTE2);		//configure pin as output
						break;
						
		case PIN_AN2:	//PORTD &= ~(1<<PORTD5);		//set pin State to low
						DDRD |= (1<<PORTD5);		//configure pin as output
						break;
						
		case PIN_AN3:	//PORTD &= ~(1<<PORTD6);		//set pin State to low
						DDRD |= (1<<PORTD6);		//configure pin as output
						break;
						
		case PIN_AN4:	//PORTB &= ~(1<<PORTB2);		//set pin State to low
						DDRB |= (1<<PORTB2);		//configure pin as output
						break;
						
		case PIN_AN5:	//PORTC &= ~(1<<PORTC4);		//set pin State to low
						DDRC |= (1<<PORTC4);		//configure pin as output
						break;
						
		case PIN_AN6:	//PORTC &= ~(1<<PORTC5);		//set pin State to low
						DDRC |= (1<<PORTC5);		//configure pin as output
						break;
						
		case PIN_AN7:	//PORTC &= ~(1<<PORTC6);		//set pin State to low
						DDRC |= (1<<PORTC6);		//configure pin as output
						break;
						
//#ifndef LM50_TEMP			//<-- wie geht das? muss noch gemacht werden!
		case PIN_AN8:	//PORTB &= ~(1<<PORTB5);		//set pin State to low
						DDRB |= (1<<PORTB5);		//configure pin as output
						break;
//#endif
						
						

		case PIN_DAC:	//PORTC &= ~(1<<PORTC7);		//set pin State to low
						DDRC |= (1<<PORTC7);		//configure pin as output
						break;

		case PIN_GPIO1:	//PORTB &= ~(1<<PORTB4);		//set pin State to low
						DDRB |= (1<<PORTB4);		//configure pin as output
						break;
							
		case PIN_GPIO2:	//PORTB &= ~(1<<PORTB3);		//set pin State to low
						DDRB |= (1<<PORTB3);		//configure pin as output
						break;
							
		case PIN_GPIO3:	//PORTD &= ~(1<<PORTD1);		//set pin State to low
						DDRD |= (1<<PORTD1);		//configure pin as output
						break;
							
		case PIN_GPIO4:	//PORTD &= ~(1<<PORTD7);		//set pin State to low
						DDRD |= (1<<PORTD7);		//configure pin as output
						break;
	
	}
}