/*
 * isocontrol.h
 *
 * Created: 12.05.2018 21:20:44
 *  Author: wohlt
 */ 

#define ISO_OK 0
#define ISO_ERROR 1
#define INTERLOCK_OK 0
#define INTERLOCK_ERROR 1

void Enable_ISO_Control();
void Disable_ISO_Control();
uint8_t Get_ISO_Status();
void ISO_Control_Task();