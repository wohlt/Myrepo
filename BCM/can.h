/*
 *	can.h
 *
 *	Version		|	Author			|	Date		|	Changes made   	
 *  -------------------------------------------------------------------
 *	1.0			|	F. Moertl		|	07.04.2014	|	
 *	1.1			|	F. Moertl		|	07.04.2014	|	Initial release to fix CAN-Bugs in 2013 and 2014 Season Code
 *				|					|				|	Initial release for uc_v3 Software. can_task() for polling added. Changed MOB Config to use 2 MOBs for sending and 4 for receiving. (Was 1/5 before)
 *				|					|				|	Defines for can_tx_flags in can.h added, new can_send_task
 *
 *
 *	Functions to initialize CAN, poll and send Messages 
 *	Further information in munichmotorsport or SE-Labor wiki
 */

#ifndef CAN_H_
#define CAN_H_
#include "header.h"

#define	 HV_NOREQUEST 0
#define  HV_REQUESTED 1
#define  NOERRORACKNOWLEDGE 0
#define  ERRORACKNOWLEDGED  1

#define CAN_SCHEDULE_MESSAGE0 can_tx_flags |= 0x01
#define CAN_SCHEDULE_MESSAGE1 can_tx_flags |= 0x02
#define CAN_SCHEDULE_MESSAGE2 can_tx_flags |= 0x04
#define CAN_SCHEDULE_MESSAGE3 can_tx_flags |= 0x08
#define CAN_SCHEDULE_MESSAGE4 can_tx_flags |= 0x10
#define CAN_SCHEDULE_MESSAGE5 can_tx_flags |= 0x20
#define CAN_SCHEDULE_MESSAGE6 can_tx_flags |= 0x40
#define CAN_SCHEDULE_MESSAGE7 can_tx_flags |= 0x80


typedef struct { uint32_t id; uint8_t dlc; u64 data; } can_msg_t;

extern uint8_t can_tx_flags;

void can_init(uint16_t);
uint8_t can_receive_message(uint32_t *id, uint8_t *dlc, uint64_t *data);
uint8_t can_send_message(uint32_t id, uint8_t dlc, uint64_t data);

void can_task();
uint8_t Get_HV_Request_Status();
void Reset_HV_Request();
uint8_t Get_Error_Acknowledge_Status();
void Reset_Error_Acknowledge();
void Reactivate_IVT_MOB();

#endif /* CAN_H_ */