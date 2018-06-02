/*
 *	timer.c
 *
 *	Version		|	Author			|	Date		|	Changes made
 *  -------------------------------------------------------------------
 *	1.0			|	F. Moertl		|	18.12.2014	|
 *
 *
 */

#include <avr/io.h>
#include <avr/interrupt.h>

#include "timer.h"
#include "header.h"
#include "user_tasks.h"
#include "moduleelectronic.h"
#include "isocontrol.h"
#include "ivtcontrol.h"


volatile uint32_t millisec_count = 0;
volatile uint8_t flag_1ms = 0;

void timer_init(void)
{
	TCCR1A |= (1<<WGM11);
	TCCR1B |= (1<<WGM13)|(1<<WGM12)|(1<<CS11);		//CS11 -> Prescaler = 8; Timer-Clk = ClkIO / 8 -> Timer-Clk = 16MHz / 8 = 2MHz
	ICR1 = 2000;
	TIMSK1 |= (1<<TOIE1);
	sei();
	
}


ISR(TIMER1_OVF_vect)
{
	millisec_count++;
	flag_1ms = 1;
}

uint32_t Get_Sys_Tick()
{
	return millisec_count;
}



void timer_task()
{
	if (flag_1ms == 1)		//triggered every ms - 1 kHz task
	{
		static uint16_t ms_count = 1;
		
		flag_1ms = 0;
		
		timer_1ms_task();	//1 kHz user task
		
		if (ms_count < 1000)
		{
			ms_count++;
		}
		else
		{
			//divide by 1000 - 1Hz task - offset by 1ms to all other tasks
			timer_1s_task();	//1 Hz
			ms_count = 1;
		}
        static uint8_t count1 = 1;
		if (count1 < 5)		//divide by 5 - 200Hz task
		{
            count1++;
        }
        else
        {
            count1 = 1;
            
			timer_5ms_task();	//200 Hz user task
		
			if (!(ms_count & 0x01))	//divide by 2 - 100 Hz task
			{
				timer_10ms_task();	//100 Hz user task

				static uint8_t count2 = 1;
                if (count2 < 5)		//divide by 5 - 20Hz task
                {
                    count2++;
                }
                else
                {
                    count2 = 1;
                
                    timer_50ms_task();	//20 Hz user task

					if (!(ms_count & 0x02))	//divide by 2 - 10Hz task
					{
						timer_100ms_task();	//10 Hz user task

                        static uint8_t count3 = 1;
                        if (count3 < 5)     //divide by 5 - 2Hz task
                        {
                            count3++;
                        }
                        else
                        {
                            count3 = 1;
						
							timer_500ms_task();	//2 Hz user task
						}
					}
				}
			}
		}		
	}
}

void timer_1ms_task()	//1 kHz
{

}

void timer_5ms_task()	//200 Hz
{

}

void timer_10ms_task()	//100 Hz
{

}

void timer_50ms_task()	//20 Hz
{
	ISO_Control_Task();
	IVT_Control_Task();
}

void timer_100ms_task()	//10 Hz
{
	
}

void timer_500ms_task()	//2 Hz
{
	Moduleelectronic_Task();
}


void timer_1s_task()		//1 Hz
{

}
