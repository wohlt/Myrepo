/*
 *	user_tasks.h
 *
 *	Version		|	Author			|	Date		|	Changes made
 *  -------------------------------------------------------------------
 *	1.0			|	F. Moertl		|	19.03.2015	|
 *	1.1			|	F. Moertl		|	19.03.2015	|	changed example code to use new can_tx_flags defines from can.h v1.1, changed can_send_task
 *
 *
 *	user_tasks.c is the only file to be edited by the user (except for SPI_CS_Conf.h in case of a new SPI-Slave)
 *	Further information in munichmotorsport or SE-Labor wiki
 */

#ifndef USER_TASKS_H_
#define USER_TASKS_H_

//#define SPI_INTERRUPT		//diese Zeile auskommentieren, um SPI-Polling statt Interrupts zu verwenden
#include "can.h"
#include "bms_data.h"

void main_init_task();		//uc init tasks
uint8_t freigabe_task();

extern uint8_t slave;




//void timer_1ms_task();		//1 kHz
//void timer_5ms_task();		//200 Hz
//void timer_10ms_task();		//100 Hz
//void timer_50ms_task();		//20 Hz
//void timer_100ms_task();	//10 Hz
//void timer_500ms_task();	//2 Hz
//void timer_1s_task();		//1 Hz
//
//void main_loop_task();		//call your background- and stateflow-tasks here, such as AD7794_task();



#endif /* USER_TASKS_H_ */