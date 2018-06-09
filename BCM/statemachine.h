/*
 * statemachine.h
 *
 * Created: 25.04.2018 15:51:33
 *  Author: wohlt
 */ 


typedef enum State_e
{
	INACTIVE = 0,
	OPERATIONAL = 1,
	ERROR = 2
}State_t;

void Statemachine_Task();
State_t Get_Statemachine_State();