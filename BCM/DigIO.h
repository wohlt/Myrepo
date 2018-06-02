/*
 *	DigIO.h
 *
 *	Version		|	Author			|	Date		|	Changes made   	
 *  -------------------------------------------------------------------
 *	1.0			|	F. Moertl		|	01.03.2015	|	
 *		
 *
 *	Functions to set I/O-Pins as output and change Pin state, or to read Pin states when Pin is an Input 
 *	Further information in munichmotorsport or SE-Labor wiki
 */

#ifndef DIGIO_H_
#define DIGIO_H_

#define SPI_CS_LTC6804_PIN PIN_PWM4					//CS define fuer LTC-Chip
#define SPI_CS_LTC6804_HIGH DIGOUT_SET_PWM4_HIGH
#define SPI_CS_LTC6804_LOW DIGOUT_SET_PWM4_LOW

#define BCM_Freigabe_PIN PIN_AN1
#define Set_BCM_Freigabe DIGOUT_SET_AN1_HIGH
#define Reset_BCM_Freigabe DIGOUT_SET_AN1_LOW

#define ISO_PIN PIN_GPIO1
#define ISO_PIN_STATE PIN_STATE_GPIO1

#define INTERLOCK_PIN PIN_GPIO2
#define INTERLOCK_PIN_STATE PIN_STATE_GPIO2


void digital_output_init(uint8_t pin_define);



// PIN_STATE defines -> if Digital Input is high, Expression is not zero,
//						if Digital Input is low, Expression is zero

#define PIN_STATE_PWM1		(PIND & (1<<PORTD0))	//read pin state
#define PIN_STATE_PWM2		(PINC & (1<<PORTC0))	//read pin state
#define PIN_STATE_PWM3  	(PIND & (1<<PORTD2))	//read pin state
#define PIN_STATE_PWM4		(PINC & (1<<PORTC1))	//read pin state
#define PIN_STATE_PWM5		(PINB & (1<<PORTB6))	//read pin state
#define PIN_STATE_PWM6		(PIND & (1<<PORTD3))	//read pin state
#define PIN_STATE_PWM7		(PINB & (1<<PORTB0))	//read pin state
#define PIN_STATE_PWM8		(PINB & (1<<PORTB1))	//read pin state
#define PIN_STATE_PWM9		(PINB & (1<<PORTB7))	//read pin state
#define PIN_STATE_AN10		(PIND & (1<<PORTD4))	//read pin state
#define PIN_STATE_AN1		(PINE & (1<<PORTE2))	//read pin state
#define PIN_STATE_AN2		(PIND & (1<<PORTD5))	//read pin state
#define PIN_STATE_AN3		(PIND & (1<<PORTD6))	//read pin state
#define PIN_STATE_AN4		(PINB & (1<<PORTB2))	//read pin state
#define PIN_STATE_AN5		(PINC & (1<<PORTC4))	//read pin state
#define PIN_STATE_AN6		(PINC & (1<<PORTC5))	//read pin state
#define PIN_STATE_AN7		(PINC & (1<<PORTC6))	//read pin state
#define PIN_STATE_AN8		(PINB & (1<<PORTB5))	//read pin state
#define PIN_STATE_DAC		(PINC & (1<<PORTC7))	//read pin state
#define PIN_STATE_GPIO1		(PINB & (1<<PORTB4))	//read pin state
#define PIN_STATE_GPIO2		(PINB & (1<<PORTB3))	//read pin state
#define PIN_STATE_GPIO3		(PIND & (1<<PORTD1))	//read pin state
#define PIN_STATE_GPIO4		(PIND & (1<<PORTD7))	//read pin state


#define DIGOUT_SET_PWM1_HIGH	(PORTD |= (1<<PORTD0))		//set pin State to high
#define DIGOUT_SET_PWM1_LOW		(PORTD &= ~(1<<PORTD0))		//set pin State to low
#define DIGOUT_SET_PWM2_HIGH	(PORTC |= (1<<PORTC0))		//set pin State to high
#define DIGOUT_SET_PWM2_LOW		(PORTC &= ~(1<<PORTC0))		//set pin State to low
#define DIGOUT_SET_PWM3_HIGH	(PORTD |= (1<<PORTD2))		//set pin State to high
#define DIGOUT_SET_PWM3_LOW  	(PORTD &= ~(1<<PORTD2))		//set pin State to low
#define DIGOUT_SET_PWM4_HIGH	(PORTC |= (1<<PORTC1))		//set pin State to high
#define DIGOUT_SET_PWM4_LOW		(PORTC &= ~(1<<PORTC1))		//set pin State to low
#define DIGOUT_SET_PWM5_HIGH	(PORTB |= (1<<PORTB6))		//set pin State to high
#define DIGOUT_SET_PWM5_LOW		(PORTB &= ~(1<<PORTB6))		//set pin State to low
#define DIGOUT_SET_PWM6_HIGH	(PORTD |= (1<<PORTD3))		//set pin State to high
#define DIGOUT_SET_PWM6_LOW		(PORTD &= ~(1<<PORTD3))		//set pin State to low
#define DIGOUT_SET_PWM7_HIGH	(PORTB |= (1<<PORTB0))		//set pin State to high
#define DIGOUT_SET_PWM7_LOW		(PORTB &= ~(1<<PORTB0))		//set pin State to low
#define DIGOUT_SET_PWM8_HIGH	(PORTB |= (1<<PORTB1))		//set pin State to high
#define DIGOUT_SET_PWM8_LOW		(PORTB &= ~(1<<PORTB1))		//set pin State to low
#define DIGOUT_SET_PWM9_HIGH	(PORTB |= (1<<PORTB7))		//set pin State to high
#define DIGOUT_SET_PWM9_LOW		(PORTB &= ~(1<<PORTB7))		//set pin State to low
#define DIGOUT_SET_AN10_HIGH	(PORTD |= (1<<PORTD4))		//set pin State to high
#define DIGOUT_SET_AN10_LOW		(PORTD &= ~(1<<PORTD4))		//set pin State to low
#define DIGOUT_SET_AN1_HIGH		(PORTE |= (1<<PORTE2))		//set pin State to high
#define DIGOUT_SET_AN1_LOW		(PORTE &= ~(1<<PORTE2))		//set pin State to low		
#define DIGOUT_SET_AN2_HIGH		(PORTD |= (1<<PORTD5))		//set pin State to high
#define DIGOUT_SET_AN2_LOW		(PORTD &= ~(1<<PORTD5))		//set pin State to low		
#define DIGOUT_SET_AN3_HIGH		(PORTD |= (1<<PORTD6))		//set pin State to high
#define DIGOUT_SET_AN3_LOW		(PORTD &= ~(1<<PORTD6))		//set pin State to low
#define DIGOUT_SET_AN4_HIGH		(PORTB |= (1<<PORTB2))		//set pin State to high
#define DIGOUT_SET_AN4_LOW		(PORTB &= ~(1<<PORTB2))		//set pin State to low
#define DIGOUT_SET_AN5_HIGH		(PORTC |= (1<<PORTC4))		//set pin State to high
#define DIGOUT_SET_AN5_LOW		(PORTC &= ~(1<<PORTC4))		//set pin State to low
#define DIGOUT_SET_AN6_HIGH		(PORTC |= (1<<PORTC5))		//set pin State to high
#define DIGOUT_SET_AN6_LOW		(PORTC &= ~(1<<PORTC5))		//set pin State to low
#define DIGOUT_SET_AN7_HIGH		(PORTC |= (1<<PORTC6))		//set pin State to high
#define DIGOUT_SET_AN7_LOW		(PORTC &= ~(1<<PORTC6))		//set pin State to low
#define DIGOUT_SET_AN8_HIGH		(PORTB |= (1<<PORTB5))		//set pin State to high
#define DIGOUT_SET_AN8_LOW		(PORTB &= ~(1<<PORTB5))		//set pin State to low
#define DIGOUT_SET_DAC_HIGH		(PORTC |= (1<<PORTC7))		//set pin State to high
#define DIGOUT_SET_DAC_LOW		(PORTC &= ~(1<<PORTC7))		//set pin State to low
#define DIGOUT_SET_GPIO1_HIGH	(PORTB |= (1<<PORTB4))		//set pin State to high
#define DIGOUT_SET_GPIO1_LOW	(PORTB &= ~(1<<PORTB4))		//set pin State to low
#define DIGOUT_SET_GPIO2_HIGH	(PORTB |= (1<<PORTB3))		//set pin State to high
#define DIGOUT_SET_GPIO2_LOW	(PORTB &= ~(1<<PORTB3))		//set pin State to low
#define DIGOUT_SET_GPIO3_HIGH	(PORTD |= (1<<PORTD1))		//set pin State to high
#define DIGOUT_SET_GPIO3_LOW	(PORTD &= ~(1<<PORTD1))		//set pin State to low
#define DIGOUT_SET_GPIO4_HIGH	(PORTD |= (1<<PORTD7))		//set pin State to high
#define DIGOUT_SET_GPIO4_LOW	(PORTD &= ~(1<<PORTD7))		//set pin State to low


#endif /* DIGIO_H_ */