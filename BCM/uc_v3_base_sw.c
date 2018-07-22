/*
 *	uc_v3_base_sw.c
 *
 *	Version		|	Author			|	Date		|	Changes made
 *  -------------------------------------------------------------------
 *	1.0			|	F. Moertl		|	27.05.2015	|
 *	2.0			|	A. Weiss		|	18.08.2016	|	Freigabe-Routine implementiert
 *
 *
 *	C-file containing the main-function. calls all important tasks in main loop, specific task calls for main-loop have to be placed in main_loop_task in user_tasks.c
 *	Further information in munichmotorsport or SE-Labor wiki
 */

#include <avr/io.h>
#include <stdio.h>
#include "header.h"
#include "timer.h"
#include "SPI.h"
#include "can.h"
#include "usart.h"
#include "user_tasks.h"
#include "BMS_Configuration.h"
//#include "util/delay.h"


//***************************************************************************************************************************************************************************************
char uart_out[10];
bms_s bms;
uint8_t Rec = 0;
uint8_t curDirect = 0;
//***************************************************************************************************************************************************************************************

void Init()
{
	digital_output_init(SPI_CS_LTC6804_PIN);				//Init des SPI-CS-Outputs
	SPI_CS_LTC6804_HIGH;
	digital_output_init(BCM_Freigabe_PIN);					//Init des SBox-Pins
	Reset_BCM_Freigabe;
	usart_init(115200);										//Init UART für RS232-Schnittstelle mit Baudrate
	can_init(500);											//Init CAN Bus mit 500kbps (moeglich 1Mbps, 500kbps, 250kbps, 125kbps)
	spi_init_master(32);									//Prescaler 32 -> 0.5MHz spi clock @ 16MHz CPU clock
	bmschip_init(UNDERVOLT, OVERVOLT);

	//Nach Initialisierung -> Freigabe an ARM
	//Init_flag = 1;
	CAN_SCHEDULE_MESSAGE0;
	
	usart_transmit_string("\f");
	usart_transmit_string("AVR-Initialisierung erfolgreich!\r\n");
}

int main(void)
{
	timer_init();
	Init();
	while(1)
	{	
		Statemachine_Task();
		can_task();
		timer_task();
	}
	return 42;			//the answer to life, the universe and everything.
}



