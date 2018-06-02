/*
 * ivtcontrol.h
 *
 * Created: 12.05.2018 21:41:54
 *  Author: wohlt
 */ 

#define CURRENT_OK 0
#define CURRENT_ERROR 1

void Enable_IVT_Control();
void Disable_IVT_Control();
uint8_t Get_Current_Status();
void IVT_Control_Task();