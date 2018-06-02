/*
 *	bms_data.h
 *
 *	Version		|	Author			|	Date		|	Changes made   	
 *  -------------------------------------------------------------------
 *	1.0			|	A. Welzmiller	|	14.06.2015	|
 *	2.0			|	A. Weiss		|	16.06.2017	|	Hinzufuegen cur_s & bms.cur, Anpassen der volt_s	
 *	2.1			|	A. Weiss		|	29.07.2016	|	balancing.RecCells, Statusflag neu definiert
 *
 *
 */
#ifndef BMS_DATA_H_
#define BMS_DATA_H_

#include "bmschip.h"

/************************************************************************/
/* Structs                                                              */
/************************************************************************/


typedef struct
{
	uint8_t number;
	uint16_t val[MAX_NUM_OF_CELLS];		// in 100uV		Einzelzellspannungen
	uint16_t max;						// in 100uV		Maximalspannung im Akku
	uint16_t min;						// in 100uV		Minimalspannung im Akku
	uint16_t avg;						// in 100uV		Durchschnittsspannung im Akku
	uint8_t NumOfCells;					//				Gesamtanzahl an seriellen Zellen
} volt_s;

typedef union
{
	uint8_t raw[4];
	sint32_t s32;
} cur_t;



typedef struct
{
	uint16_t cells[16];				//Zellen, die gebalanced werden muessen
	uint16_t RecCells[16];			//Zellen, bei denen Balancing empfohlen wird	
	uint16_t min_Volt;				//min Spannung im gesamten Akku?
	uint16_t max_Volt;				//vollste Zelle
	uint16_t undervoltage;			//tatsaechliche Überspannungsgrenze
	uint16_t overvoltage;			//tatsaechliche Unterspannungsgrenze
} balancing_s;

typedef struct  
{
	uint16_t V_temp[5][SLAVE_BOARDS];			//Spannungswert an GPIO 1-5
	uint16_t V_reference[SLAVE_BOARDS];			//Spannungswert von V_REF2
	sint32_t temp_transmit[5][SLAVE_BOARDS];	//berechnete Temperatur Thermistor 1-5
	sint32_t temp_max;							//Maximaltemperatur
}temp_s;

typedef struct
{
	uint8_t bms_flag;		//Status-Flag vgl. Flag unten
	volt_s volt;
	cur_t cur;
	balancing_s balancing;
	temp_s temp;
} bms_s;

/************************************************************************/
/* Globale Variablen                                                    */
/************************************************************************/
extern uint8_t Rec;
extern bms_s bms;
extern uint8_t curDirect;

/************************************************************************/
/* Flag defines															*/
/************************************************************************/

#define flagOverCur			0x01		// 00000001		Overcurrent-Fehler
#define flagOverVol			0x02		// 00000010		OverVoltage-Fehler
#define flagUnderVol		0x04		// 00000100		UnderVoltage-Fehler
#define flagOverTemp		0x08		// 00001000		OverTemp-Fehler
#define	flagCommunication	0x10		// 00010000		Kommunikationsfehler
#define flagCritical		0x20		// 00100000		Warnung
#define flagBalActiv		0x40		// 01000000		Flag für das Balancing
#define flagBalRec			0x80		// 10000000


#define IS_TRUE(x)  (( bms.bms_flag & (x) ) == x )
#define IS_FALSE(x) (( bms.bms_flag & (x) ) == 0 )

#define SET_TRUE(x)  ( bms.bms_flag |= (x) )
#define SET_FALSE(x) ( bms.bms_flag &= ~(x) )




#endif /* BMS_DATA_H_ */