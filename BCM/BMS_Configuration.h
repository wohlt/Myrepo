/*
 *	BMS_Configuration.h
 *
 *	Version		|	Author			|	Date		|	Changes made   	
 *  -------------------------------------------------------------------
 *	1.0			|	A. Welzmiller	|	14.07.2015	|	
 *	2.0			|	A. Weiss		|	15.06.2016	|	Zellbelegung via. 12Bit-Maske (alternativ: mehrdim. Array)
 *	2.1			|	A. Weiss		|	29.07.2016	|	Recommend-Balancing-Limit definiert
 *	2.2			|	A. Weiss		|	03.08.2016	|	Overcurrent definiert
 *	
 *
 */

#include "header.h"

#ifndef BMS_CONFIGURATION_H_
#define BMS_CONFIGURATION_H_

// *** Definition der BMS Slaves ***********************************************************

// Anzahl der Slave_Boards 
#define MODULE_COUNT 2
#define SLAVE_BOARDS  4


// Angeschlossene Zellen pro Slave-Board 
/* 5-12 Zellen koennen angeschlossen werden

	Zellbelegung:		Wert:
	0	Zellen			0x00	(000000000000)
	5	Zellen			0x01F	(000000011111)
	6	Zellen			0x03F	(000001111111)
	7	Zellen			0x07F	(000001111111)
	8	Zellen			0x0FF	(000011111111)
	9	Zellen			0x1FF	(000111111111)
	10	Zellen			0x3FF	(001111111111)
	11	Zellen			0x7FF	(011111111111)
	12	Zellen			0xFFF	(111111111111)

	Default-Belegung:
		Ungerade Board! Nummer	== 9 (6-3 auf Multiplexer gruppiert)
		Gerade Board! Nummer	== 8 (6-2 auf Multiplexer gruppiert)	
*/
static const uint16_t cells_per_board[16]={
	0x1FF,	//Zellen an Board 1
	0x0FF,	//Zellen an Board 2
	0x1FF,	//Zellen an Board 3
	0x0FF,	//Zellen an Board 4
	0x1FF,	//Zellen an Board 5
	0x0FF,	//Zellen an Board 6
	0x1FF,	//Zellen an Board 7
	0x0FF,	//Zellen an Board 8
	0x1FF,	//Zellen an Board 9
	0x0FF,	//Zellen an Board 10
	0x1FF,	//Zellen an Board 11
	0x0FF,	//Zellen an Board 12
	0x1FF,	//Zellen an Board 13
	0x0FF,	//Zellen an Board 14
	0x1FF,	//Zellen an Board 15
	0x0FF	//Zellen an Board 16
};

/*	Optionaler Array-Ansatz: Nicht Gewaehlt!
	Aufruf mit Funktion Zellen_pro_Board2();
	
		
	5-12 Zellen koennen angeschlossen werden
	Default-Belegung:
		Ungerade Board Zahl	== 9 (6-3 auf Multiplexer gruppiert)
		Gerade Board Zahl	== 8 (6-2 auf Multiplexer gruppiert)

static const uint8_t cells_per_board2[16][12]={
	{1,1,1,1,1,1,1,1,1,1,1,1},		//Zellen an Board 1
	{1,1,1,1,1,1,1,1,1,1,1,1},		//Zellen an Board 2
	{1,1,1,1,1,1,1,1,1,1,1,1},		//Zellen an Board 3
	{1,1,1,1,1,1,1,1,1,1,1,1},		//Zellen an Board 4
	{1,1,1,1,1,1,1,1,1,1,1,1},		//Zellen an Board 5
	{1,1,1,1,1,1,1,1,1,1,1,1},		//Zellen an Board 6
	{1,1,1,1,1,1,1,1,1,1,1,1},		//Zellen an Board 7
	{1,1,1,1,1,1,1,1,1,1,1,1},		//Zellen an Board 8
	{1,1,1,1,1,1,1,1,1,1,1,1},		//Zellen an Board 9
	{1,1,1,1,1,1,1,1,1,1,1,1},		//Zellen an Board 10
	{1,1,1,1,1,1,1,1,1,1,1,1},		//Zellen an Board 11
	{1,1,1,1,1,1,1,1,1,1,1,1},		//Zellen an Board 12
	{1,1,1,1,1,1,1,1,1,1,1,1},		//Zellen an Board 13
	{1,1,1,1,1,1,1,1,1,1,1,1},		//Zellen an Board 14
	{1,1,1,1,1,1,1,1,1,1,1,1},		//Zellen an Board 15
	{1,1,1,1,1,1,1,1,1,1,1,1}		//Zellen an Board 16
};
*/
// Temperatursensoren 
// Vorerst ein Sensor an GPIO 3 pro Board
// *****************************************************************************************

// *** Definition des Masters **************************************************************
// Ueber- und Unterspannungsgrenzen in 100uV-
#define OVERVOLT	42000			// == 4.2V
#define UNDERVOLT	25000			// == 2.5V

// Uebertemperatur
#define OVERTEMP	6000			// == 60.00°C

// Ueberstrom
#define OVERCURRENT 130000		// == 150000000 mA == 150A

// Entprellung der Grenzen
#define ENTPRELLUNG 4
#define ENTPRELLUNGCOM 10

// Limit S-Box-Timer
#define SBOXLIMIT 40

// Balancing in 100uV 
#define BAL_DIFFERENCE		100		// == 0.01V		Differenzspannung, ab welcher gebalanced wird
#define BAL_REC_DIFFERENCE	200		// == 0.02V		Differenzspannung, ab welcher Balancing empfohlen wird
#define BALANCING_LIMIT		30000	// == 3.00V		Minimalspannung, ab welcher gebalanced werden darf
// *****************************************************************************************
#endif /* BMS_CONFIGURATION_H_ */