/*
 * ltc6804.h
 *
 * Created: 26.04.2018 18:57:10
 *  Author: wohlt
 */ 

#define TEMP_OK 0
#define TEMP_ERROR 1
#define VOLTAGE_OK 0
#define	VOLTAGE_ERROR 1
#define COMMUNICATION_OK 0
#define COMMUNICATION_ERROR 1

uint8_t Get_Temp_Status();
uint8_t Get_Voltage_Status();
void Moduleelectronic_Task();