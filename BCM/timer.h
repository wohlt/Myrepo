/*
 *	timer.h
 *
 *	Version		|	Author			|	Date		|	Changes made
 *  -------------------------------------------------------------------
 *	1.0			|	F. Moertl		|	18.12.2014	|
 *
 *
 *	Functions to init timer-interrupt, and a timer-task to periodically call 1ms, 5ms, 10ms, 50ms, 100ms, 500ms and 1s tasks in user_tasks.c
 *	Further information in munichmotorsport or SE-Labor wiki
 */

#ifndef TIMER_H_
#define TIMER_H_

extern volatile uint32_t millisec_count;

void timer_init(void);
void timer_task();
uint32_t Get_Sys_Tick();

void timer_10ms_task();		//100 Hz
void timer_50ms_task();		//20 Hz
void timer_100ms_task();	//10 Hz
void timer_500ms_task();	//2 Hz
void timer_1s_task();		//1 Hz


#endif /* TIMER_H_ */