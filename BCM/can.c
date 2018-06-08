/*
 *	can.c
 *
 *	Version		|	Author			|	Date		|	Changes made   	
 *  -------------------------------------------------------------------
 *	1.0			|	F. Moertl		|	07.04.2014	|	
 *		
 *
 */

#include <avr/io.h>
#include "header.h"
#include "BMS_Configuration.h"
#include "user_tasks.h"
#include <avr/interrupt.h>
#include "can.h"
#include "statemachine.h"
#include "bms_data.h"

uint8_t can_tx_flags;
static uint8_t hv_request = 0;
static uint8_t error_acknowledge = 0;

uint8_t Get_HV_Request_Status()
{
	return hv_request;
}

void Reset_HV_Request()
{
	hv_request = 0;
}

uint8_t Get_Error_Acknowledge_Status()
{
	return error_acknowledge;
}

void Reset_Error_Acknowledge()
{
	error_acknowledge = 0;
}

void can_init(uint16_t kbaudrate)
{
	CANGCON = 0x00;		// disable CAN
	// set bit-timing registers
	// configure baudrate (SP=81.3%): single sample, SJW=2, PRS=6, PHS1=6, PHS2=3
	if(kbaudrate == 1000) 			// 1 MBit/s (87.5%)
	{
		CANBT1 = 0x00;
		CANBT2 = 0x0A;
		CANBT3 = 0x1C;
	} 
	else if(kbaudrate == 500)		// 500 kBit/s
	{
		CANBT1 = 0x02;
		CANBT2 = 0x2A;
		CANBT3 = 0x2A;
	} 
	else if(kbaudrate == 250)		// 250 kBit/s
	{
		CANBT1 = 0x06;
		CANBT2 = 0x2A;
		CANBT3 = 0x2A;
	} 
	else 							// 125 kBit/s
	{
		CANBT1 = 0x0E;
		CANBT2 = 0x2A;
		CANBT3 = 0x2A;
	}
	
	// init all MOb's, use MOb's #5 & #4 to send, MOb's #0..#3 to receive
	for(uint8_t i = 0; i < 6; i++) 
	{
		CANPAGE = (i << 4);		// select MOb
		CANSTMOB = 0;			// status: clear
		if(i < 4)
		{ 
			CANCDMOB = 0x80;	// ctrl: enable reception
			
			switch(i)
			{
				case 0:								//MOB0 Receive IDs 0x000-0x007
						//clear acceptance code
						CANIDT4 = 0;
						CANIDT3 = 0;
						CANIDT2 = 0;
						CANIDT1 = 0;
						
						//clear acceptance mask
						CANIDM4 = 0xFF;
						CANIDM3 = 0xFF;
						CANIDM2 = 0x1F;
						CANIDM1 = 0xFF;
				break;
				case 1:
						//clear acceptance code		//MOB1 Receive ID 0x521
						CANIDT4 = 0x00;
						CANIDT3 = 0x00;
						CANIDT2 = 0x00;
						CANIDT1 = 0x00;
							
						//clear acceptance mask
						CANIDM4 = 0xFF;
						CANIDM3 = 0xFF;
						CANIDM2 = 0xFF;
						CANIDM1 = 0xFF;
				break;
				case 2:
						//clear acceptance code
						CANIDT4 = 0;
						CANIDT3 = 0;
						CANIDT2 = 0;
						CANIDT1 = 0;
							
						//clear acceptance mask
						CANIDM4 = 0xFF;
						CANIDM3 = 0xFF;
						CANIDM2 = 0xFF;
						CANIDM1 = 0xFF;
				break;
				case 3:
						//clear acceptance code
						CANIDT4 = 0;
						CANIDT3 = 0;
						CANIDT2 = 0;
						CANIDT1 = 0;
							
						//clear acceptance mask
						CANIDM4 = 0xFF;
						CANIDM3 = 0xFF;
						CANIDM2 = 0xFF;
						CANIDM1 = 0xFF;
				break;
			}
		}
		else
		{ 
			CANCDMOB = 0;		// ctrl: disable MOb
			
			//clear acceptance code
			CANIDT4 = 0;
			CANIDT3 = 0;
			CANIDT2 = 0;
			CANIDT1 = 0;
					
			//clear acceptance mask
			CANIDM4 = 0;
			CANIDM3 = 0;
			CANIDM2 = 0;
			CANIDM1 = 0;
		}
		

	}
	//#ifdef CAN_LISTEN_ONLY
	//	CANGCON = 0x0A;		// set ListeningOnlyMode, no TX, no ACK
	//#else
	
	CANGCON = 0x02;		// enable CAN
	//#endif
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
uint8_t can_receive_message(uint32_t *id, uint8_t *len, uint64_t *can_data)
{
	uint8_t cs, return_value = 0;
	uint8_t *data_ptr = (uint8_t*) can_data;
	uint8_t mob;
	for(mob = 0; mob < 4; mob++)	// check receive buffers of the CAN
	{ 
		CANPAGE = (mob << 4);		// select MOb
		cs = CANEN2 >> mob;			// get status of MOb
		if ((cs & 0x01) == 0)		// MOb not busy? -> data received!
		{
			uint8_t inf = CANCDMOB;
			*len = inf & 0x0f;		//save DLC
			if(*len > 8) *len = 8;
			if((inf & 0x10) == 0)	//standard ID?
				*id = (((uint16_t)CANIDT1) << 3) + (CANIDT2 >> 5);
			else 					//extended ID!
			{	
				u32 id_buf;
				id_buf.b[3] = CANIDT1;
				id_buf.b[2] = CANIDT2;
				id_buf.b[1] = CANIDT3;
				id_buf.b[0] = CANIDT4;
				id_buf.l >>= 3;
				id_buf.b[3] |= 0x80;
				*id = id_buf.l;
			}
			for(uint8_t i = 0; i < *len; i++) 
				*(data_ptr++) = CANMSG;
			CANCDMOB = 0x80;		//re-activate MOb for reception
			return_value = ((~CANEN2) & 0x0f) | 1;
			break;
		}
	}
	return(return_value); //return_value = 0: no reception, 1: one msg received, >1: more than one msg in buffers (every set bit in return_value represents a full buffer at time of function-call)
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
	
uint8_t can_send_message(uint32_t id, uint8_t len, uint64_t can_data)
{
	uint8_t *data_ptr = (uint8_t *)&can_data;
	
	if((CANEN2 & 0x10) == 0)	// MOb #4 not busy? 
	{
		CANPAGE = (4 << 4);	// select MOb #4, data index = 0
	}
	else if((CANEN2 & 0x20) == 0)	// MOb #5 not busy? 
	{
		CANPAGE = (5 << 4);	// select MOb #5, data index = 0
	}
	else return(0);
	
	for(uint8_t i = 0; i < len; i++) 
		CANMSG = *(data_ptr++);
	if((id & 0x80000000) == 0) 	// set standard ID
	{
		CANIDT4 = 0;
		id = ((uint16_t) id << 5);
		CANIDT2 = (((uint16_t) id & 0x00ff) >>  0);
		CANIDT1 = (((uint16_t) id & 0xff00) >>  8);
	}
	else 						// set extended ID
	{	
		id = id << 3;
		CANIDT4 = ((id & 0x000000ff) >>  0);
		CANIDT3 = ((id & 0x0000ff00) >>  8);
		CANIDT2 = ((id & 0x00ff0000) >> 16);
		CANIDT1 = ((id & 0xff000000) >> 24);
		len += 0x10;
	
	}
	CANCDMOB = (0x40 | len);		// transmit
	return(1);
}

void can_receive_task(can_msg_t msg)
{
	switch(msg.id)
	{
		//Für Systemreset reserviert
		//case 0x000: if()
		
		//HV_Request
		case 0x001:	
			hv_request = msg.data.b[0] & 0x01;
			error_acknowledge = msg.data.b[0] & 0x02
			if((msg.data.b[1] == 1))
				SET_TRUE(flagBalActiv);
			else
				SET_FALSE(flagBalActiv);
			curDirect = msg.data.b[2];
		break;
		
		case 0x003: 
			bms.cur.raw[3] = msg.data.b[2];
			bms.cur.raw[2] = msg.data.b[3];
			bms.cur.raw[1] = msg.data.b[4];
			bms.cur.raw[0] = msg.data.b[5];
		break;
		
		////Initialisierung und Testlauf erlaubt!
		//case 0x100:	Test_flag = msg.data.b[0];
		//Update_Conditions_Received_Status(msg.data.b[0]);
		//SLAVE_BOARDS = msg.data.b[1];
		//curDirect = msg.data.b[2];
		//break;
		
		default: 	break;
	}
}

void can_send_task(uint8_t index)
{
	uint8_t i, i1;
	u32 transfer;
	can_msg_t msg;
	
	switch(index)			//index 0 - 7 equals bits set in can_tx_flags mask
	{
		//HV State
		case 0:			
						msg.data.b[0] = bms.bms_flag;
						msg.data.b[1] = Get_Statemachine_State();
						msg.id = 0x002;
						msg.dlc = 2;
						while(!(can_send_message(msg.id, msg.dlc, msg.data.ll)));	
						break;
								
		//Spannungsmesswerte & Status
		case 2: 		
						msg.id = 0x300;
						for(i=0; i<SLAVE_BOARDS; i++)
						{
							for(i1=0; i1<4; i1++)
							
							{
								msg.data.b[0] = (GET_LOW_BYTE(bms.volt.val[(i*12)+(i1*3)]));	
								msg.data.b[1] = (GET_HIGH_BYTE(bms.volt.val[(i*12)+(i1*3)]));	
								msg.data.b[2] = (GET_LOW_BYTE(bms.volt.val[(i*12)+(i1*3)+1]));	
								msg.data.b[3] = (GET_HIGH_BYTE(bms.volt.val[(i*12)+(i1*3)+1]));	
								msg.data.b[4] = (GET_LOW_BYTE(bms.volt.val[(i*12)+(i1*3)+2]));	
								msg.data.b[5] = (GET_HIGH_BYTE(bms.volt.val[(i*12)+(i1*3)+2]));	
								msg.data.b[6] = (i*12)+(i1*3)+3;		//Anzahl der bisher uebertragenen Werte (Die letzten 3 miteinbezogen)
								msg.data.b[7] = bms.bms_flag;
								
								
								msg.dlc = 8;
								while(!(can_send_message(msg.id, msg.dlc, msg.data.ll)));
								msg.id++;
							}						
						}
			 			break;
		
		//Bancing Status
		case 3:			for(i=0; i<SLAVE_BOARDS; i++)
						{
							msg.data.b[0] = (GET_LOW_BYTE(bms.balancing.cells[i]));	
							msg.data.b[1] = (GET_HIGH_BYTE(bms.balancing.cells[i]));
							msg.data.b[2] = Rec;	
							msg.data.b[3] = (i+1);
							msg.data.b[4] = bms.bms_flag;	
							msg.id = 0x005;
							msg.dlc = 5;
							while(!(can_send_message(msg.id, msg.dlc, msg.data.ll)));
						}
						break;
		
		//Temperatur & Status
		case 4:			for(i=0; i<SLAVE_BOARDS; i++)
						{	
							transfer.l = bms.temp.temp_transmit[i];						
							msg.data.b[0] = transfer.b[0];
							msg.data.b[1] = transfer.b[1];
							msg.data.b[2] = transfer.b[2];
							msg.data.b[3] = transfer.b[3];
							msg.data.b[4] = (i+1);	
							msg.data.b[5] = bms.bms_flag;							
							msg.id = 0x006;
							msg.dlc = 6;
							while(!(can_send_message(msg.id, msg.dlc, msg.data.ll)));
						}	
						transfer.l = 0;					
		  				break;
	
		default:		
		break;
	}
}


void can_task()
{
	static uint8_t index = 0;
	if (can_tx_flags)			//anything to send?
	{	
		if((CANEN2 & 0x30) != 0x30) // MOb #4 or #5 not busy?
		{
			do
			{
				if(index < 7) 
				{
					index++;		//select next message
				}
				else
				{
					index = 0;		//overrun, start over with first message
				}
			}
			while (!(can_tx_flags & (1 << index))); //message flagged for transmission? if not - check next message
			
			can_send_task(index);			//call can_send_task (prepares data and starts transmission)
			
			can_tx_flags &= ~(1 << index);  //reset send flag for sent message
		}
	}
	
	can_msg_t can_rx;
	
	//wenn alle nachrichten in einem Aufruf verarbeitet werden sollen -> while(can_receive.....
	while(can_receive_message(&can_rx.id, &can_rx.dlc, &can_rx.data.ll) >= 1) 
	{
		can_receive_task(can_rx);
	}
}

void Reactivate_IVT_MOB()
{
	CANPAGE = (1 << 4);		//select MOb
	CANCDMOB = 0x80;		//re-activate MOb for reception
}

