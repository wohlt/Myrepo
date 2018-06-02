/*
 * statemachine.c
 *
 * Created: 25.04.2018 15:51:20
 *  Author: wohlt
 */ 
#include <avr/io.h>
#include "statemachine.h"
#include "header.h"
#include "can.h"
#include "DigIO.h"
#include "usart.h"
#include "moduleelectronic.h"
#include "timer.h"
#include "ivtcontrol.h"
#include "isocontrol.h"

#define WAITING  0
#define TESTS 1
#define TESTTIME 250


	static State_t state = IDLE;						//Current statemachine state
	static uint8_t hv_ready = 0;
	
	void (*StateMachineFunctions[])();					//Function Pointer Array Declaration for State Machine
	
	State_t Get_Statemachine_State()
	{
		return state;	
	}
				
	void Idle()
	{
		static uint8_t substate = WAITING;
		
		switch (substate)
		{
			case WAITING:
			{
				if(Get_HV_Request_Status())
				{
					substate = TESTS;
				}
			}
			break;
			
			case TESTS:
			{
				static entry = 1;
				static uint32_t teststarttime;
				
				if(entry)
				{
					teststarttime = Get_Sys_Tick();
					entry = 0;
				}
				
				if(Get_Voltage_Status() == VOLTAGE_ERROR || Get_Current_Status() == CURRENT_ERROR || Get_ISO_Status() == ISO_ERROR || Get_Temp_Status() == TEMP_ERROR)
				{
					substate = WAITING;
					entry = 1;
				}
				else if(Get_Sys_Tick() - teststarttime >= TESTTIME)
				{
					hv_ready = 1;
					entry = 1;
					substate = WAITING;
				}
			}			
			break;
			
			default:
			{
				substate = WAITING;				
			}
			break;			
		}
		
		if(Get_HV_Request_Status() && hv_ready)
		{
			state = OPERATIONAL;
			Set_BCM_Freigabe;
		}
	}
	
	void Operational()
	{
		if(Get_Voltage_Status() == VOLTAGE_ERROR || Get_Current_Status() == CURRENT_ERROR || Get_ISO_Status() == ISO_ERROR || Get_Temp_Status() == TEMP_ERROR)
		{	
			Reset_BCM_Freigabe;
			state = ERROR;
		}
	}
	
	void Error()
	{
		if(Get_Error_Acknowledge_Status())
		{
			state = IDLE;
			Reset_HV_Request();
			Reset_Error_Acknowledge();
		}
	}	
	
	//Function Pointer Array for state machine
	void (*StateMachineFunctions[])() =
	{
		Idle,
		Operational,
		Error
	};
	

	void Statemachine_Task()
	{
		StateMachineFunctions[state]();		//Call Function of current State Machine State
	}