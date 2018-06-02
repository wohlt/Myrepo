/*
 *	SPI.c
 *
 *	Version		|	Author			|	Date		|	Changes made
 *  -------------------------------------------------------------------
 *	1.0			|	F. Moertl		|	20.12.2014	|
 *	2.0			|	T. Wohl			|	25.04.2018	| Implemented SPI interrupt transfer 
 *													
 *
 *	How to calculate value for prescaler:
 *
 *	prescaler = F_CPU / F_SPI
 *
 *	Pin Port D3 a.k.a TX/PWM6 is the slave select input during master operation
 *	-> SPI can be accidentally configured as slave when this pin is configured as an input
 *	-> the spi_init_master()-function will configure it as an output
 */

#include <avr/io.h>

#include "header.h"
#include "user_tasks.h"
#include <avr/interrupt.h>

#include "DigIO.h"		//debug with LA
#include "SPI.h"

#include <stdlib.h>
#include "usart.h"

static uint8_t idx = 0;
static uint8_t spi_busy = 0;
static uint8_t transmit_len = 0;
static uint8_t* spi_buffer;

void spi_init_master(uint8_t prescaler)
{
	/* Set MOSI and SCK as output, MISO will be set to input automatically when SPI-Interface is finally enabled */
	DDRB |= (1<<PORTB1)|(1<<PORTB7);
	/* Set _SS as output to protect SPI-Module from being switched to slave mode accidentally */
	DDRD  |=  (1<<PORTD3);
	/* Enable SPI, Master, set clock rate */
	switch (prescaler)
	{
	case 2:		SPSR |= (1<<SPI2X);
				SPCR = (1<<SPE)|(1<<MSTR);
				break;

	case 4:		SPSR &= ~(1<<SPI2X);
				SPCR = (1<<SPE)|(1<<MSTR);
				break;

	case 8:		SPSR |= (1<<SPI2X);
				SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
				break;

	case 16:	SPSR &= ~(1<<SPI2X);
				SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
				break;

	case 32:	SPSR |= (1<<SPI2X);
				SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR1);
				break;

	case 64:	SPSR &= ~(1<<SPI2X);
				SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR1);
				break;

	case 128:	SPSR &= ~(1<<SPI2X);
				SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR1)|(1<<SPR0);
				break;
	}
	SPCR |= (1 << CPOL) | (1 << CPHA);
}


void SPI_Exchange_Block(uint8_t *data, uint8_t len)			
{
	SPI_CS_LTC6804_LOW;
	for(int i = 0; i < len; i++)
	{
		/* Start transmission */
		SPDR = data[i];
	
		/* Wait for transmission complete */
		while(!(SPSR & (1<<SPIF)));
		
		// Read received data
		data[i] = SPDR;
	}
}
	
void SPI_Transceive_Block(uint8_t *senddata,uint8_t * receivedata, uint8_t len)
{
	SPI_CS_LTC6804_LOW;
	for(int i = 0; i < len; i++)
	{
		/* Start transmission */
		SPDR = senddata[i];
		
		/* Wait for transmission complete */
		while(!(SPSR & (1<<SPIF)));
		
		// Read received data
		receivedata[i] = SPDR;
	}
}

void SPI_Transmit_Block(uint8_t *senddata,uint8_t len)
{
	SPI_CS_LTC6804_LOW;
	for(int i = 0; i < len; i++)
	{
		/* Start transmission */
		SPDR = senddata[i];
			
		/* Wait for transmission complete */
		while(!(SPSR & (1<<SPIF)));
	}
}



uint8_t Get_SPI_Status()
{
	return spi_busy;
}


uint8_t SPI_Transceive_IT(uint8_t*data,uint8_t len)
{
	uint8_t ret = spi_busy;
	if(!spi_busy)
	{
		SPI_CS_LTC6804_LOW;
		spi_busy = SPI_BUSY;
		SPCR |= (1<<SPIE);											//Enable spi interrupt
		idx = 0;
		spi_buffer = data;
		transmit_len = len;
		SPDR = spi_buffer[idx];										//Start transmission with first byte
	}
	return ret;
}


void SPI_IT_Callback()
{
	SPI_CS_LTC6804_HIGH;
}


ISR(SPI_STC_vect)
{
	spi_buffer[idx++] = SPDR;			//Read received data
	if(idx >= transmit_len)				//Finished transmission?
	{
		spi_busy = SPI_READY;
		SPCR &= ~(1<<SPIE);				//Disable spi interrupt
		SPI_IT_Callback();				//Call Callback Function
	}
	else
	{
		SPDR = spi_buffer[idx];			//Start transmission for next byte
	}
}

