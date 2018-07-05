/*
 * isocontrol.c
 *
 * Created: 12.05.2018 21:20:26
 *  Author: wohlt
 */ 

#include <avr/io.h>
#include "DigIO.h"
#include "isocontrol.h"

static uint8_t enabled = 1;
static uint8_t iso_status = ISO_OK;
static uint8_t interlock_status = INTERLOCK_OK;

void Enable_ISO_Control()
{
	enabled = 1;
}

void Disable_ISO_Control()
{
	iso_status = ISO_OK;
	interlock_status = INTERLOCK_OK;
	enabled = 0;
}

uint8_t Get_ISO_Status()
{
	return iso_status;
}

uint8_t Get_Interlock_Status()
{
	return interlock_status;
}

void ISO_Control_Task()
{
	if(enabled)
	{
		if(ISO_PIN_STATE)
		{
			iso_status = ISO_OK;
		}
		else
		{
			iso_status = ISO_ERROR;
		}
		
		if(INTERLOCK_PIN_STATE)
		{
			interlock_status = INTERLOCK_OK;
		}
		else
		{
			interlock_status = INTERLOCK_ERROR;
		}
	}
}