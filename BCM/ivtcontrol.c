/*
 * ivtcontrol.c
 *
 * Created: 12.05.2018 21:41:43
 *  Author: wohlt
 */ 

#include <avr/io.h>
#include "ivtcontrol.h"
#include "bms_data.h"
#include "BMS_Configuration.h"

static uint8_t enabled = 1;
static uint8_t current_status = CURRENT_OK;


void Enable_IVT_Control()
{
	enabled = 1;
}

void Disable_IVT_Control()
{
	current_status = CURRENT_OK;
	enabled = 0;
}

uint8_t Get_Current_Status()
{
	return current_status;
}

uint32_t abs32(sint32_t val)
{
	if(val > 0)
		return val;
	else
		return val*(-1);
}

void IVT_Control_Task()
{
	if(enabled)
	{
		if(abs32(bms.cur.s32) > OVERCURRENT)
		{
			current_status = CURRENT_ERROR;
		}
		else
		{
			current_status = CURRENT_OK;
		}
	}
}
