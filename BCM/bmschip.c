/*
 *	bmschip.c
 *
 *	Version		|	Author			|	Date		|	Changes made   	
 *  -------------------------------------------------------------------
 *	1.0			|	A. Welzmiller	|	27.05.2015	|	
 *	2.0			|	A. Weiss		|	01.06.2016	|	Temperatur-Bug behoben
 *	2.1			|	A. Weiss		|	15.06.2016	|	Funktion: Zellen_pro_Board
 *	2.2			|	A. Weiss		|	28.07.2016	|	ADC-Funkktionen: bmschip_read_IntADC, evaluate_Current
 *	2.3			|	A. Weiss		|	29.07.2016	|	Balancing-Funktion: bmschip_recommendBalancing, bmschip_checkBalancing
 *
 *
 */

// *** Includes ****************************************************************************
#include "bmschip.h"
#include "header.h"
#include "SPI.h"
#include "DigIO.h"
#include "BMS_Configuration.h"

#include <avr/io.h>

#include <stdlib.h>
#include "usart.h"
#include "timer.h"
#include "bms_data.h"
#include "user_tasks.h"


// *** Variables ***************************************************************************
volatile ltc6804_s ltc6804;
char uart_out[10];
uint16_t buff;
uint16_t wait_count;
// *****************************************************************************************

// *** Functions ***************************************************************************
/* PL_ltc6804_f_1.1
//Initialisierung
*/
// *****************************************************************************************

// *** Funktion zur Initialisierung der LTC6804 - Slaves ***********************************
void bmschip_init(uint16_t undervoltage, uint16_t overvoltage)
{
	uint8_t i, cmd=0x00;
	uint8_t *p_cmd = &cmd;
	
	
	// Befehlsregister fuer Zellspannungen lesen initialisieren
	//Group A
	ltc6804.adcv[0][0] = 0x00;	// 00000000	Konfigurations-Befehl
	ltc6804.adcv[0][1] = 0x04;	// 00000100	Konfigurations-Befehl
	ltc6804.adcv[0][2] = 0x07; 	// 00000111 PEC-High-Byte
	ltc6804.adcv[0][3] = 0xc2;	// 11000010 PEC-Low-Byte
	//Group B
	ltc6804.adcv[1][0] = 0x00;	// 00000000	Konfigurations-Befehl	
	ltc6804.adcv[1][1] = 0x06;	// 00000110	Konfigurations-Befehl
	ltc6804.adcv[1][2] = 0x9a;	// 10011010 PEC-High-Byte
	ltc6804.adcv[1][3] = 0x94;	// 10010100 PEC-Low-Byte
	//Group C
	ltc6804.adcv[2][0] = 0x00;	// 00000000	Konfigurations-Befehl
	ltc6804.adcv[2][1] = 0x08;	// 00001000	Konfigurations-Befehl
	ltc6804.adcv[2][2] = 0x5e;	// 01011110 PEC-High-Byte
	ltc6804.adcv[2][3] = 0x52;	// 01010010 PEC-Low-Byte
	//Group D
	ltc6804.adcv[3][0] = 0x00;	// 00000000	Konfigurations-Befehl		
	ltc6804.adcv[3][1] = 0x0A;	// 00001010	Konfigurations-Befehl
	ltc6804.adcv[3][2] = 0xc3;	// 11000011 PEC-High-Byte
	ltc6804.adcv[3][3] = 0x04;	// 00000100 PEC-Low-Byte
	
	for(i=0; i<SLAVE_BOARDS; i++)	//Keine Zelle darf zu Beginn gebalanced werden
	{
		bms.balancing.cells[i]= 0x0000;
	}
	bms.bms_flag = 0x00;	//Alle Flags erst einmal ausschalten
	
	bms.balancing.undervoltage = UNDERVOLT;	//erwuenschte Unterspannung übertragen
	bms.balancing.overvoltage = OVERVOLT;	//erwuenschte Ueberspannung übertragen
	bmschip_setOvUnVoltage(&bms.balancing.undervoltage, &bms.balancing.overvoltage);	//Tatsaechlich moegliche Grenzen für den LTC6804 bestimmen
	for (i=0; i<SLAVE_BOARDS; i++)
	{
		SPI_Transmit_Block(p_cmd, 1);	//Dummybyte, um den isoSPI aufzuwecken
		
		SPI_CS_LTC6804_HIGH;
		wait_count = TCNT1;
		while ((((wait_count + 800) >= TCNT1)&&(wait_count<TCNT1)) || ((wait_count>TCNT1) && ((TCNT1 + ICR1)<(wait_count + 800))));	//400us
	}
	bmschip_writeConfig();
}
// *****************************************************************************************

// *** Funktion zum Festlegen kritischer Spannungsgrenzen **********************************
void bmschip_setOvUnVoltage(uint16_t * undervoltage, uint16_t * overvoltage)
{
	//Spannungen an LTC6804-Format anpassen
	//Aus der 16bit-Zahl wird eine 12Bit-Zahl
	if(*undervoltage > 0)
	{
		*undervoltage = (*undervoltage / 16) - 1;	// (Spannung in 100uV / (16 * 100uV)) - 1		
	}
	*overvoltage = *overvoltage / 16;	// Spannung in 100uV / (16 * 100uV)
		
	//Konfigurationsdaten aktualisieren
	ltc6804.config[0] = 0x24;																			// 00100100 (2) wenn GPIO3 als Input gesetzt werden soll
	ltc6804.config[1] = (uint8_t) *undervoltage;														//Ein Byte aus den niedrigeren 8 Bit des 12 Bit UV-Werts
	ltc6804.config[2] = (uint8_t) (((*overvoltage & 0x000F) << 4) | ((*undervoltage & 0x0F00) >> 8));	//Ein Byte aus den niedrigeren 4 Bit des 12 Bit OV-Werts und der höheren 4 Bit des 12 Bit UV-Werts
	ltc6804.config[3] = (uint8_t) ((*overvoltage & 0x0FF0) >> 4);										//Ein Byte aus den höheren 8 Bit des 12 Bit OV-Werts
	ltc6804.config[4] = 0x00;
	ltc6804.config[5] = 0x00;
	
	//Zur Fehlerkontrolle ausserhalb dieser Funktion Spannungen nach Runden zurueckrechnen
	*undervoltage = (*undervoltage + 1) * 16;
	*overvoltage = *overvoltage * 16;
}
// *****************************************************************************************


// *** Funktion um Konfiguration fuer das Balancing zu veraendern **************************
void bmschip_writeDischarge(uint16_t cells, uint8_t time)
{
	ltc6804.config[4] = (uint8_t) cells;	//zu balancende Zellen eintragen
	ltc6804.config[5] = (uint8_t) (((time & 0x0F) << 4) | ((cells & 0x0F00) >> 8));		//Balancing-time: Manuell
	/*
	Zu Balancende Zellen eintragen
	
	Byte	Bit7	Bit6	Bit5	Bit4	Bit3	Bit2	Bit1	Bit0
	[4]		cell8	cell7	cell6	cell5	cell4	cell3	cell2	cell1
	[5]		time3	time2	time1	time0	cell12	cell11	cell10	cell9

	Balancing-Time: Je nach Kombination der 4 time-Bits
	*/
}
// *****************************************************************************************

// *** Funktion zum Beschreiben der Slaves *************************************************
uint8_t bmschip_writeConfig(void)
{
	uint8_t size = 12, i, j;
	uint8_t cmd[size], cmdAns[size];
	uint16_t pec;


	//Konfigurationsbefehl
	cmd[0] = 0x00; // WRCFG0
	cmd[1] = 0x01; // WRCFG1
	pec = Pec15(cmd, 2);
	
	cmd[2] = GET_HIGH_BYTE(pec);
	cmd[3] = GET_LOW_BYTE(pec);
	
	//Befehl und PEC schreiben
	for (i=0; i<SLAVE_BOARDS; i++)
	{
		SPI_Transmit_Block(cmd, 1);	//Dummybyte, um den IsoSPI aufzuwecken
		
		SPI_CS_LTC6804_HIGH;

		wait_count = TCNT1;
		while ((((wait_count + 25) >= TCNT1)&&(wait_count<TCNT1)) || ((wait_count>TCNT1) && ((TCNT1 + ICR1)<(wait_count + 25))));
	
	}	
	SPI_Transmit_Block(cmd, 4);	//Command schicken
	
	//CS nicht auf HIGH setzen! 
	//Jetzt Uebertragung der einzelnen Chip-Configs
	for (i=0;i<SLAVE_BOARDS;i++)
	{
		if(IS_TRUE(flagBalActiv))		//Abfrage, ob gebalanced werden darf?
		{
			bmschip_writeDischarge(bms.balancing.cells[SLAVE_BOARDS-i-1], 0x1);
		}
		else
		{
			ltc6804.config[4]=0x00;
			ltc6804.config[5]=0x00;
		}
		//Konfigurationsdaten der einzelnen Slaves 
		cmd[4] = ltc6804.config[0];
		cmd[5] = ltc6804.config[1];
		cmd[6] = ltc6804.config[2];
		cmd[7] = ltc6804.config[3];
		cmd[8] = ltc6804.config[4];
		cmd[9] = ltc6804.config[5];
		pec = Pec15(&(cmd[4]), 6);
		cmd[10] = GET_HIGH_BYTE(pec);
		cmd[11] = GET_LOW_BYTE(pec);
		
		SPI_Transmit_Block(&cmd[4], 8);
	}
	
	SPI_CS_LTC6804_HIGH;
	
	//Konfiguration zur Kontrolle lesen
	for (i=0; i<=SLAVE_BOARDS; i++)		//Der Reihe nach wird jetzt die Konfiguration der Boards eingeholt
	{
		if(bmschip_readConfig(cmdAns, size, i) != 0)		//Konfiguration der Zellen auslesen
		{
			SPI_CS_LTC6804_HIGH;
			return 1;
		}
		
		if(IS_FALSE(flagBalActiv))	//nicht beim Balancing, sondern bei Neukonfiguration
		{
			//Gelesene Config auswerten
			if (i != 0) //nicht beim Senden der Konfig
			{
				for(j=5;j<10;j++)	//Erstes Byte vorerst nicht, da beim Lesen an GPIOs NICHT die Konfiguration, sondern die anliegende Spannung ausgegeben wird
				{
					if(cmdAns[j] != ltc6804.config[j-4])
					{
						SPI_CS_LTC6804_HIGH;
						return 1;
					}
				}
			}
		}
	}
	SPI_CS_LTC6804_HIGH;

	return 0;
}
// *****************************************************************************************

// *** Funktion zum lesen der Konfiguration der Slaves *************************************
uint8_t bmschip_readConfig(uint8_t * cmd, uint8_t size, uint8_t msg)
{
	uint8_t i;
	uint16_t pec;
	
	
	//Befehl und PEC schreiben
	if (msg==0)	//für msg == 0 wird der Command gesendet. Das ist zuerst immer notwendig
	{	
		cmd[0] = 0x00; // RDCFG0
		cmd[1] = 0x02; // RDCFG1
		pec = Pec15(cmd, 2);
		cmd[2] = GET_HIGH_BYTE(pec);
		cmd[3] = GET_LOW_BYTE(pec);
		SPI_Transmit_Block(cmd, 4);	//Command
	}
	else	//Konfiguration empfangen
	{
		for(i=4; i<size; i++)
		{
			cmd[i] = 0x00;
		}
		SPI_Exchange_Block(&cmd[4], 8);		
		//Auswertung
		pec = Pec15(&cmd[4], 6);
		if(GET_HIGH_BYTE(pec) != cmd[10] ||	GET_LOW_BYTE(pec) != cmd[11])
		{
			return 1;	//Abbruch falls PEC nicht stimmt
		}
	}
	return 0;
}
// *****************************************************************************************

// *** Funktion zum Starten der Spannungsmessung *******************************************
void bmschip_startAdc(void)
{
	uint8_t i;
	uint8_t cmd[4];
	
	
	cmd[0]=0x00;
	for (i=0; i<SLAVE_BOARDS; i++)
	{
		SPI_Transmit_Block(cmd, 1);	//Dummybyte, um den IsoSPI aufzuwecken
		SPI_CS_LTC6804_HIGH;
		wait_count = TCNT1;
		while ((((wait_count + 25) >= TCNT1)&&(wait_count<TCNT1)) || ((wait_count>TCNT1) && ((TCNT1 + ICR1)<(wait_count + 25))));
	}
	
	//Messbefehl
	cmd[0] = 0x03;	// 00000011	ADCV0	Normal-Mode
	cmd[1] = 0x60;	// 01100000	ADCV1	Normal-Mode, Balancing wird unterbrochen während der Messung
	cmd[2] = 0xF4;	// PEC-High-Byte
	cmd[3] = 0x6C;	// PEC-Low-Byte
	
	/* 
	Byte	Bit7	Bit6	Bit5	Bit4	Bit3	Bit2	Bit1	Bit0
	[0]		0		0		0		0		0		0		1		MD[1]
	[1]		MD[0]	1		1		DCP		0		CH[2]	CH[1]	CH[0]	

	MD[1] + MD[0] 	== 10 	Messmodus Normal-Mode
	DCP				== 0	Balancing unterbrochen
					== 1	Balancing nicht unterbrochen
	CH[2] + CH[1] + CH[0]	== zu messende Zellen je nach Kombination
	*/
	
	//Befehl und PEC schreiben
	SPI_Transmit_Block(cmd, 4);
	
	SPI_CS_LTC6804_HIGH;
}
// *****************************************************************************************

// *** Funktion zum messen der Zellspannungen **********************************************
uint8_t bmschip_getVoltages(uint16_t *voltage)
{
	uint8_t i, group;
	uint8_t ret = 0;
	uint16_t pec;
	uint8_t cmd[12];
	uint8_t receive[8];
	uint16_t wait_count;		//Wartezeit für ADC-Messung vom LTC6804
	uint32_t wait_milli;		//Wartezeit in Millisekunden

	// LTC ADC starten
	bmschip_startAdc();
	
	//LTC ADC Wandlung abwarten (3000us) 

	wait_count = TCNT1;
	wait_milli = Get_Sys_Tick();
	while((wait_milli+2) > Get_Sys_Tick());	//2000us
	while(wait_count >= TCNT1);
	wait_count = TCNT1;
	while ((((wait_count + 1000) >= TCNT1)&&(wait_count<TCNT1)) || ((wait_count>TCNT1) && ((TCNT1 + ICR1)<(wait_count + 1000)))); //500us
		//
	//wait_milli = millisec_count;
	//while((wait_milli+3) > millisec_count);	//3000us
		
	//LTC Spannungen auslesen
	for(group = 0; group < 4; group++)		
	{
		for(i = 0; i < 4; i++)
		{
			cmd[i] = ltc6804.adcv[group][i];
		}
		for(i = 4; i < 12; i++)
		{
			cmd[i] = 0x00;
		}
		
		// Befehl und PEC schreiben
		SPI_Transmit_Block(cmd, 4); //Command schicken
		
		for (i=0; i<SLAVE_BOARDS; i++)
		{
			SPI_Transceive_Block(&cmd[4],receive, 8);			
			//Emfangene Daten durch PEC-Berechnung pruefen
			pec = Pec15(&(receive[0]), 6);
			if(pec == ((((uint16_t)receive[6]) << 8) | receive[7]))	//Stimmt der PEC?
			{
				//Jeweilige Zellspannung in die entsprechende Nummer im Array übertragen (Standardmäßig: bms.volt.val[])
				voltage[group * 3 + (i*12)] = (((uint16_t)receive[1]) << 8) | receive[0];		
				voltage[group * 3 + (i*12) + 1] = (((uint16_t)receive[3]) << 8) | receive[2];
				voltage[group * 3 + (i*12) + 2] = (((uint16_t)receive[5]) << 8) | receive[4];
			}
			else
			{
				ret = 1;	//PEC falsch!
				break;
			}
		}
		SPI_CS_LTC6804_HIGH;
	}
	return ret;
}
// *****************************************************************************************

// *** PEC-Berechnung **********************************************************************
// Code aus dem Datenblatt von LTC6804 übernommen 
// Funktioniert schneller als Berechnung, da Lookup-Table verwendet wird
uint16_t Pec15 (uint8_t *data, uint8_t len)
{
	uint16_t remainder = 16;	// PEC seed
	uint16_t adr;
	uint8_t i;
	
	
	for (i = 0; i < len; i++)
	{
		//Calculate PEC table address
		adr = ((remainder >> 7) ^ data[i]) & 0xFF;
		remainder = (remainder << 8 ) ^ crc15Table[adr];
	}
	//The CRC15 has a 0 in the LSB so the final value must be multiplied by 2
	return (remainder*2);
}
// *****************************************************************************************

// *** Auswertung der Zellspannungen *******************************************************
void bmschip_evaluate(uint16_t * pvolatages, uint16_t * pmaxVolt, uint16_t * pminVolt, uint16_t * pavgVolt, uint8_t * numofcells)
{
	uint16_t minVolt = 50000, maxVolt = 0;
	uint32_t avgVolt = 0;
	uint8_t i, i1, actNr = 0, Cells[SLAVE_BOARDS];
	
	
	//Bestimmung der Zellenanzahl pro Board
	Zellen_pro_Board(Cells);
		
	//Bestimmung Min, Max, Avg
	for(i=0; i<SLAVE_BOARDS;i++)
	{
		for(i1=0; i1<12; i1++)
		{
			//Average Voltage bestimmen
			if(cells_per_board[i] & (1<<i1))
			{
				avgVolt += pvolatages[(i*12)+i1];
			}
			
			//Min Voltage bestimmen
			if((pvolatages[(i*12)+i1] < minVolt) && (cells_per_board[i] & (1<<i1)))		//Minimalspannung
			{
				minVolt = pvolatages[(i*12)+i1];
			}
			
			//Max Voltage bestimmen
			else if((pvolatages[(i*12)+i1] > maxVolt) && (cells_per_board[i] & (1<<i1)))	//Maximalspannung
			{
				maxVolt = pvolatages[(i*12)+i1];
			}
		}
		actNr += Cells[i];	//Merken, wie viele Zellen man hat
	}
	avgVolt /= actNr;	//Mittelwertbildung
	
	//Rückgabe Min, Max, Avg
	*pmaxVolt = maxVolt;
	*pminVolt = minVolt;
	*pavgVolt = (uint16_t)avgVolt;
	*numofcells = actNr;
}
// *****************************************************************************************

// *** Balancing-Funktionen ****************************************************************
// pVoltages: Array beinhaltet Spannungswerte 
// minVolt:	Kleinste Spannung im System
// voltDiff: Different, ab welcher gebalanced werden darf
// undervoltage: Unterspannungsgrenze

void bmschip_checkBalancing(uint16_t *pvoltages, uint16_t minVolt, uint16_t undervoltage, uint16_t *pcells)
{
	uint16_t cells;
	uint8_t i, k, Cells[SLAVE_BOARDS];
	
	
	//Bestimmung der Zellenanzahl pro Board
	Zellen_pro_Board(Cells);

	for(k=0; k<SLAVE_BOARDS; k++)
	{
		cells = 0x0000;
		for(i=0; i<12; i++)
		{
			if((pvoltages[(k*12)+i] >= (minVolt + BAL_DIFFERENCE)) && (pvoltages[(k*12)+i] > (undervoltage + BAL_DIFFERENCE)) && (pvoltages[(k*12)+i] > BALANCING_LIMIT))
			{
				if(cells_per_board[k] & (1<<i))
				{
					cells |= (1 << i); 					
				}
			}
		}
		pcells[k] = cells;
	}
	
}

uint8_t bmschip_recommendBalancing(uint16_t *pvoltages, uint16_t minVolt, uint16_t undervoltage, uint16_t *pcells)
{
	uint16_t cells;
	uint8_t i, k, Cells[SLAVE_BOARDS], Anzahl=0;


	//Bestimmung der Zellenanzahl pro Board
	Zellen_pro_Board(Cells);
		
	for(k=0; k<SLAVE_BOARDS; k++)
	{
		cells = 0x0000;
		for(i=0; i<12; i++)
		{
			if((pvoltages[(k*12)+i] >= (minVolt + BAL_REC_DIFFERENCE)) && (pvoltages[(k*12)+i] > (undervoltage + BAL_REC_DIFFERENCE)) && (pvoltages[(k*12)+i] > BALANCING_LIMIT))
			{
				if(cells_per_board[k] & (1<<i))
				{
					cells |= (1 << i);
					Anzahl++;
				}					
			}
		}
		pcells[k] = cells;
	}
	return(Anzahl);
}
// *****************************************************************************************

// *** Temperaturmessung *******************************************************************
void bmschip_startGPIO(uint8_t pin)
{
	uint8_t i;
	uint8_t cmd[4];
	uint16_t pec;
	
	
	cmd[0]=0x00;	
	for (i=0; i<SLAVE_BOARDS; i++)
	{
		SPI_Transmit_Block(cmd, 1);		//Dummybyte, um den IsoSPI aufzuwecken
		SPI_CS_LTC6804_HIGH;
		wait_count = TCNT1;
		while ((((wait_count + 25) >= TCNT1)&&(wait_count<TCNT1)) || ((wait_count>TCNT1) && ((TCNT1 + ICR1)<(wait_count + 25))));
	}
	
	//Messbefehl	
	cmd[0] = 0x05; // 00000101	ADAX0	Normal-Mode									
	cmd[1] = 0x60; // 01100000	ADAX1	Normal-Mode, Balancing wird unterbrochen	
	
	switch(pin)
	{
		case 0:									//Alles		cmd[1] =									= 01100000
				break;
		case 1: cmd[1] |= (1<<0);				//GPIO 1	cmd[1] = 01100000 | 00000001				= 01100001
				break;
		case 2: cmd[1] |= (1<<1);				//GPIO 2	cmd[1] = 01100000 | 00000010				= 01100010
				break;
		case 3: cmd[1] |= (1<<1) | (1<<0);		//GPIO 3	cmd[1] = 01100000 | 00000010 | 00000001		= 01100011
				break;
		case 4: cmd[1] |= (1<<2);				//GPIO 4	cmd[1] = 01100000 | 00000100				= 01100100
				break;
		case 5: cmd[1] |= (1<<2) | (1<<0);		//GPIO 5	cmd[1] = 01100000 | 00000100 | 00000001		= 01100101		
				break;
		case 6: cmd[1] |= (1<<2) | (1<<1);		//VRef		cmd[1] = 01100000 | 00000100 | 00000010		= 01100110
				break;
	}
	
	pec = Pec15(cmd, 2);
	cmd[2] = GET_HIGH_BYTE(pec);
	cmd[3] = GET_LOW_BYTE(pec);
		
	//Befehl und PEC schreiben
	SPI_Transmit_Block(cmd, 4);
	
	SPI_CS_LTC6804_HIGH;
}
// *****************************************************************************************

// *** Temperaturwerte auslesen ************************************************************
uint8_t bmschip_getTemperature(uint8_t pin)		
{
	uint8_t i;
	uint8_t gpio = pin;
	uint16_t pec;
	uint8_t cmd[12];
	uint8_t receive[8];
	uint16_t wait_count;		//Wartezeit für ADC-Messung vom LTC6804
	sint32_t max = 0;			//Zwischenwert für Maximaltemperatur im System
	sint64_t x;					//Zwischenwert für Temperaturkennlinie
	
	
	bmschip_startGPIO(gpio);		//Spannung an jeweiligem GPIO
	
	for(i = 0;i<7;i++)
	{
		wait_count = TCNT1;
		while ((((wait_count + 810) >= TCNT1)&&(wait_count<TCNT1)) || ((wait_count>TCNT1) && ((TCNT1 + ICR1)<(wait_count + 900)))); //405us
	}
	//LTC-Temperatur auslesen	
	//Register A lesen
	cmd[0] = 0x00;		//00000000
	cmd[1] = 0x0C;		//00001100
	pec = Pec15(cmd, 2);
	cmd[2] = GET_HIGH_BYTE(pec);
	cmd[3] = GET_LOW_BYTE(pec);
	
	for(i = 4; i < 12; i++)
	{
		cmd[i] = 0x00;
	}
	
	SPI_Transmit_Block(cmd, 4); //Command schicken

	//Spannungswerte an GPIO3 in bms.temp.V_temp[] uebertragen
	for(i=0; i<SLAVE_BOARDS; i++)
	{
		SPI_Transceive_Block(&cmd[4],receive, 8);
		// Emfangene Daten durch Pec-Berechnung pruefen
		pec = Pec15(&(receive[0]), 6);
		if(pec == ((((uint16_t)receive[6]) << 8) | receive[7]))
		{
			bms.temp.V_temp[0][i] = (((uint16_t)receive[1]) << 8) | receive[0];	//GPIO1
			bms.temp.V_temp[1][i] = (((uint16_t)receive[3]) << 8) | receive[2];	//GPIO2
			bms.temp.V_temp[2][i] = (((uint16_t)receive[5]) << 8) | receive[4];	//GPIO3
		}
		else
		{
			SPI_CS_LTC6804_HIGH;
			return 1;
		} 
	}
	SPI_CS_LTC6804_HIGH;
		
	//Register B lesen
	cmd[0] = 0x00;		//00000000
	cmd[1] = 0x0E;		//00001110
	pec = Pec15(cmd, 2);
	cmd[2] = GET_HIGH_BYTE(pec);
	cmd[3] = GET_LOW_BYTE(pec);
	
	for(i = 4; i < 12; i++)
	{
		cmd[i] = 0x00;
	}
	
	SPI_Transmit_Block(cmd, 4); //Command schicken

	//Spannungswerte von V_REF2 in bms.temp.V_temp[] uebertragen
	for(i=0; i<SLAVE_BOARDS; i++)
	{
		SPI_Transceive_Block(&cmd[4],receive, 8);
		//Emfangene Daten durch Pec-Berechnung pruefen
		pec = Pec15(&(receive[0]), 6);
		if(pec == ((((uint16_t)receive[6]) << 8) | receive[7]))
		{
			bms.temp.V_temp[3][i] = (((uint16_t)receive[1]) << 8) | receive[0];		//GPIO4
			bms.temp.V_temp[4][i] = (((uint16_t)receive[3]) << 8) | receive[2];		//GPIO5
			bms.temp.V_reference[i] = (((uint16_t)receive[5]) << 8) | receive[4];	//V_REF2
		}
		else
		{
			usart_transmit_string("F2");
			SPI_CS_LTC6804_HIGH;
			return 1;
		}
	}
	SPI_CS_LTC6804_HIGH;
	
	//Nachbildung der Thermistorkennlinie und Berechnung der Temperatur
	
	//for(int k=0;k<5;k++) //Thermistor 1-5
	//{
		for(i=0; i<SLAVE_BOARDS; i++)
		{
			x = (((sint64_t)bms.temp.V_temp[2][i])*1000000)/(sint64_t)bms.temp.V_reference[2];
			
			if(x>=780000)
			{
				bms.temp.temp_transmit[2][i] = (sint32_t)((x-780000)/(-70));
			}
			else if(x>=340000)
			{
				bms.temp.temp_transmit[2][i] = (sint32_t)((x-780000)/(-110));
			}
			else if(x<183000)
			{
				bms.temp.temp_transmit[2][i] = (sint32_t)((x-490000)/(-51));
			}
			else
			{
				bms.temp.temp_transmit[2][i] = (sint32_t)((x-645000)/(-77));
			}
		}
	//}
	
	
	//Maximaltemperatur
	max = 0;
	//for(int k = 0; k<5; k++)	//Thermistor 1-5
	//{
		for(i=0;i<SLAVE_BOARDS; i++)
		{
			if(max < bms.temp.temp_transmit[2][i])
			{
				max = bms.temp.temp_transmit[2][i];
			}
		}		
	//}
	bms.temp.temp_max = max;
	return 0;
}
// *****************************************************************************************

// *** Zellbelegung bestimmen **************************************************************
void Zellen_pro_Board(uint8_t *Cells)
{
	uint8_t i, i1;


	for(i=0; i<SLAVE_BOARDS; i++)
	{
		Cells[i] = 0;
		for(i1=0; i1<12; i1++)
		{
			if(cells_per_board[i] & (1<<i1))
			{	
				Cells[i]++;
			}
		}
	}	
}

//Optionaler Array-Ansatz: Nicht gewaehlt
/* void Zellen_pro_Board2(uint8_t *Cells)
{
	uint8_t i, i1;
	
	
	for(i=0; i<SLAVE_BOARDS; i++)
	{
		Cells[i] = 0;
		for(i1=0; i1<12; i1++)
		{
			if(cells_per_board2[i][i1] == 1)
			{
				Cells[i]++;
			}
		}
	}
}
*/
// *****************************************************************************************


// *** Funktion zur Auswertung der Strommessung ********************************************
// Faktor zur Umrechnung Dual -> Spannung:							*1000000uV/V * 5V / 1024bit 
// Faktor zur Umrechnung Spannung -> Stroms aus 1.25 und 200A:		*200A / 1.25V = 160A/V (Keine floating point Rechnung nötig)
	
// Achtung!
// Je nach Stromrichtung (Direction):	
//		Entladen/Betrieb (Direction == 1) 
//		Laden (Direction == 0) 
//		Befestigungsrichtung des Stromsensors beachten!

//	Kritischer Bereich -2A ... 0 ... +2A 

uint32_t evaluate_Current(uint16_t V_Cur, uint16_t V_Ref, uint8_t *cFlag, uint8_t Direction)
{
	uint32_t x = 0;	 
	
	if ((V_Ref >= 500) && (V_Ref <= 524)) // Nur dann liegt Strommessung überhaupt möglich
	{
		if((Direction == 1) && (V_Cur > (V_Ref))) 	//In die im Datenblatt definierte Stromrichtung
		{	
			x = ((((((uint32_t) V_Cur) - V_Ref) * 1000000) * 5) / 1024) * 160;
		}
		else if((Direction == 1) && (V_Cur <= V_Ref) && (V_Cur >= (V_Ref-3)))	//Kritischer Bereich -2A bis 0A
		{
			x = 0;
			*cFlag |= (1<<0);	// 00000001
		}
		else if((Direction == 1) && (V_Cur < (V_Ref-3)))	//Strom fließt im Entlade-Modus in den Speicher
		{
			x = ((((((uint32_t) V_Ref - 3) - V_Cur) * 1000000) * 5) / 1024) * 160;
			*cFlag |= (1<<1);	// 00000010			
		}
		else if((Direction == 0) && (V_Cur < V_Ref))	//Gegen die im Datenblatt definierte Stromrichtung
		{
			x = ((((((uint32_t) V_Ref) - V_Cur) * 1000000) * 5) / 1024) * 160;
		}
		else if((Direction == 0) && (V_Cur >= V_Ref) &&  (V_Cur <= (V_Ref+3)))	//Kritischer Bereich 0A bis +2A
		{
			x = 0;
			*cFlag |= (1<<2);	// 00000100
		}	
		else if((Direction == 0) && (V_Cur > (V_Ref+3)))	//Strom fließt im Lade-Modus aus dem Speicher	
		{
			x = ((((((uint32_t) V_Cur) - ((uint64_t) V_Ref + 3)) * 1000000) * 5) / 1024) * 160;
			*cFlag |= (1<<3);	// 00001000
		}
	}
	else
	{
	//	x = 0;
		*cFlag |= (1<<7);	// 00010000
	}
	return(x);
}
// *****************************************************************************************