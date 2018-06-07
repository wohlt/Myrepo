/*
 * moduleelectronic.c
 *
 * Created: 26.04.2018 18:56:57
 *  Author: wohlt
 */ 

#include <avr/io.h>
#include "moduleelectronic.h"
#include "can.h"
#include "header.h"
#include "DigIO.h"
#include "bmschip.h"
#include "BMS_Configuration.h"
#include "bms_data.h"
#include "user_tasks.h"

#define DEBOUNCELIMIT 5

static uint8_t temp_status = TEMP_OK;
static uint8_t voltage_status = VOLTAGE_OK;
static uint8_t communication_status = COMMUNICATION_OK;

static uint8_t tempcounter = 0;
static uint8_t voltagecounter = 0;
static uint8_t communicationcounter = 0;

static uint8_t enabled = 1;

void Enable_Moduleelectronic_Module()
{
	enabled = 1;
}

void Disable_Moduleelectronic_Module()
{
	temp_status = TEMP_OK;						//Module is disabled, pretend Temperature is ok
	voltage_status = VOLTAGE_OK;				//		"-"			, pretend Voltage is ok
	communication_status = COMMUNICATION_OK;	//		"-"			, pretend Communication is ok
	enabled = 0;
}

uint8_t Get_Temp_Status()
{
	return temp_status;	
}


uint8_t Get_Voltage_Status()
{
	return voltage_status;
}


void Moduleelectronic_Task()	//Call every 50ms
{
	if(enabled)
	{
		//-----------------------------Get Cell Voltages and check them-------------------------------------
		if(!bmschip_getVoltages(bms.volt.val))							//PEC OK?
		{
			communicationcounter = 0;									//PEC was right NO Communication Error
			communication_status = COMMUNICATION_OK;
			
			bmschip_evaluate(bms.volt.val, &bms.volt.max, &bms.volt.min, &bms.volt.avg, &bms.volt.NumOfCells);
			
			if(bms.volt.min<=UNDERVOLT || bms.volt.max>=OVERVOLT)
			{
				voltagecounter++;
				if(voltagecounter >= DEBOUNCELIMIT)
				{
					voltage_status = VOLTAGE_ERROR;
					voltagecounter = 0;
				}
			}
			else
			{
				voltage_status = VOLTAGE_OK;
				voltagecounter = 0;
			}
		}
		else															//PEC was wrong
		{
			communicationcounter++;
			if(communicationcounter >= DEBOUNCELIMIT)
			{
				communicationcounter = 0;
				communication_status = communication_status;
			}
		}
		CAN_SCHEDULE_MESSAGE2;
	
	
		//-----------------------------Get Cell Temperature and check them---------------------------------	
		if(!bmschip_getTemperature(0))
		{	
			if(bms.temp.temp_max>=OVERTEMP)
			{
				tempcounter++;
				if(tempcounter >= DEBOUNCELIMIT)
				{
					tempcounter = 0;
					temp_status = TEMP_ERROR;
				}
			}
			else
			{
				tempcounter = 0;
				temp_status = TEMP_OK;
			}
			CAN_SCHEDULE_MESSAGE4;
		}
		
	}
}