/*
 *	SPI.h
 *
 *	Version		|	Author			|	Date		|	Changes made
 *  -------------------------------------------------------------------
 *	1.0			|	F. Moertl		|	20.12.2014	|
 *	1.1			|	F. Moertl		|	20.12.2014	|	SPI now supports Interrupts. #define SPI_INTERRUPT enables interrupts instead of polling.
 *
 *
 *	Functions for SPI-Interface. Includes Initialization as SPI-Master, 16 Bytes long receive and send buffers and a task for controlling SPI without waiting for completed byte-transceives.
 *	Further information in munichmotorsport or SE-Labor wiki
 */

#ifndef SPI_H_
#define SPI_H_

#include "DigIO.h"

#define SPI_BUSY 1
#define SPI_READY 0

void spi_init_master(uint8_t prescaler);
uint8_t Get_SPI_Status();
void SPI_Exchange_Block(uint8_t *data, uint8_t len);
void SPI_Transceive_Block(uint8_t *senddata,uint8_t * receivedata, uint8_t len);
void SPI_Transmit_Block(uint8_t *senddata,uint8_t len);


#endif /* SPI_H_ */