/*
 *	user_tasks.c
 *
 *	Version		|	Author			|	Date		|	Changes made   	
 *  -------------------------------------------------------------------
 *	1.0			|	F. Moertl		|	19.03.2015	|	
 *	2.0			|	A. Weiss		|	11.05.2016	|	Ausgabe der einzelnen Spannungswerte ergaenzt
 *	2.1			|	A. Weiss		|	16.06.2016	|	Ausgabe derStrommessung
 *	2.2			|	A. Weiss		|	23.06.2016	|	SBox Verzögerungszeit
 *	2.3			|	A. Weiss		|	04.08.2016	|	CAN Interface eingerichtet
 *	2.4			|	A. Weiss		|	12.08.2016	|	Balancing für Dauer der Spannungsmessung manuell deaktiviert
 *	2.5			|	A. Weiss		|	18.08.2016	|	Freigabe via. CAN hinzugefügt
 *	2.6			|	A. Weiss		|	19.01.2017	|	CAN-Nachricht Strom deaktiviert
 *		
 *
 *
 */


// *** Includes ****************************************************************************
#include <avr/io.h>
#include "header.h"
#include "user_tasks.h"
#include "moduleelectronic.h"
#include "can.h"
#include "SPI.h"
#include "DigIO.h"
#include "usart.h"
#include "BMS_Configuration.h"
#include "timer.h"
#include "bmschip.h"	//eigene Dateien
#include "bms_data.h"
#include <stdlib.h>
  
//#include "LM50.h"
// *****************************************************************************************

// *** Global Defines **********************************************************************


//Freigabe_flag des STM-boards für kontinuierlichen Betrieb
	uint8_t STM_flag = 0;
//Initialisierung abgechlossen
	uint8_t Init_flag = 0;
//Freigabe_flag: Test aller Funktionen erlaubt
	uint8_t Test_flag = 0;
//Freigabe_flag: Alle Funktionen erfolgreich getestet
	uint8_t Freigabe_flag = 0; 
//Übergabeparameter: Slave-Anzahl
	uint8_t slave = 0;
//Übergabeparameter: Stromrichtung
	uint8_t curDirect = 0;
//Timer für Überschreiten einer Sicherheitsgrenze
	uint8_t S_Box_Timer = 0; 
	uint8_t Overcur_Timer = 0;
	uint8_t Overvolt_Timer = 0;
	uint8_t Undervolt_Timer = 0;
	uint8_t Overtemp_Timer = 0;
	uint8_t Communication_Timer = 0; 		
	
//Flag für Abschluss des S-Box-Timers
	uint8_t S_Box_Timer_Done;

	
	
	
 


uint16_t wait_count;
sint16_t tempspeicher;
uint32_t curSpeicher;

char uart_out[10];
char eingabe;
static char mode=48;
// *****************************************************************************************

// *** Initialisierung der Schnittstellen **************************************************

// *****************************************************************************************

// *** Test des Systems ********************************************************************
//uint8_t freigabe_task()
//{
	//uint8_t i, i1, ret = 0;
	//uint32_t wait_milli;
//
	////Anzahl der Slave-Boards bestimmen
	//if(Init_flag == 1 && Test_flag == 1 && Freigabe_flag == 0)
	//{
		//SLAVE_BOARDS = slave;
		//i1 = 0;
	//
		//for(i=1; i<6;i++)
		//{
			//usart_transmit_string("\r\n Test ");
			//while(!(usart_transmit_char(48+i)));
			//if(bmschip_getVoltages(bms.volt.val) == 1)
			//{
				//
				//usart_transmit_string("\r\n Fehler: Kommunikation!");
				//usart_transmit_string("\r\n Test erneut starten!\r\n");	
				//SET_TRUE(flagCommunication);
				//CAN_SCHEDULE_MESSAGE0;		
				//SET_FALSE(flagCommunication);
				//Test_flag = 0;
				//break;
			//}
			//else
			//{
				//bmschip_evaluate(bms.volt.val, &bms.volt.max, &bms.volt.min,  &bms.volt.avg, &bms.volt.NumOfCells);
				//bmschip_getTemperature(3);
//
//// ********************************************************************************************************************************************************************************************************************************				
				////Wenn Stromsensor angeschlossen:
				////bms.cur.cur_flag = 0x00;
				////bmschip_read_IntADC(&bms.cur.V_cur, &bms.cur.V_reference);
				////bms.cur.cur_transmit = evaluate_Current(bms.cur.V_cur, bms.cur.V_reference, &bms.cur.cur_flag, curDirect);
				////Wenn Stromsensor nicht angeschlossen:
				//bms.cur.cur_transmit = 0;
//// ********************************************************************************************************************************************************************************************************************************	
					//
				//if(bms.volt.min<=UNDERVOLT)
				//{
					//usart_transmit_string("\r\n Fehler: Undervoltage!");
					//usart_transmit_string("\r\n Test erneut starten!\r\n");		
					//SET_TRUE(flagUnderVol);
					//CAN_SCHEDULE_MESSAGE0;
					//SET_FALSE(flagUnderVol);				
					//Test_flag = 0;
					//break;		
				//}
				//else if(bms.volt.max>=OVERVOLT)
				//{
					//usart_transmit_string("\r\n Fehler: Overvoltage!");
					//usart_transmit_string("\r\n Test erneut starten!\r\n");										
					//SET_TRUE(flagOverVol);
					//CAN_SCHEDULE_MESSAGE0;
					//SET_FALSE(flagOverVol);
					//Test_flag = 0;
					//break;							
				//}
				//else if(bms.temp.temp_max>=OVERTEMP)
				//{
					//usart_transmit_string("\r\n Fehler: Overtemperature!");
					//usart_transmit_string("\r\n Test erneut starten!\r\n");					
					//SET_TRUE(flagOverTemp);
					//CAN_SCHEDULE_MESSAGE0;
					//SET_FALSE(flagOverTemp);
					//Test_flag = 0;
					//break;		
				//}
				//else if(bms.cur.cur_transmit>=OVERCURRENT)
				//{
					//usart_transmit_string("\r\n Fehler: Overcurrent!");
					//usart_transmit_string("\r\n Test erneut starten!\r\n");										
					//SET_TRUE(flagOverCur);
					//CAN_SCHEDULE_MESSAGE0;
					//SET_FALSE(flagOverCur);
					//Test_flag = 0;
					//break;		
				//}
				//else
				//{
					//i1++;
				//}
				//
				//if(i1 == 5)
				//{
					//Freigabe_flag = 1;
				//}
			//}
		//}
		//
		//if(Freigabe_flag == 1)
		//{
			//usart_transmit_string("\r\n\n Test-Durchlauf erfolgreich!");
			//usart_transmit_string("\r\n Warte auf endgueltige Freigabe!");
			//Test_flag = 0;
			//CAN_SCHEDULE_MESSAGE0;			
		//}
	//}
	//else if (STM_flag == 1 && Freigabe_flag == 1 && Test_flag == 0)
	//{
		//S_Box_active;
		//ret = 1;
	//}
	//return(ret);
//}
//// *****************************************************************************************

//void timer_1ms_task()	//1 kHz
//{
	////insert code here
	//
	//
	////----------------
//}
//
//void timer_5ms_task()	//200 Hz
//{
	////insert code here
//
	//
	////----------------
//}
//
//void timer_10ms_task()	//100 Hz
//{
	////insert code here
//
//
	////----------------
//}
//
//void timer_50ms_task()	//20 Hz
//{
//
//// *** Balancing ***************************************************************************
//if(usart_receive(&eingabe))
//{
	//switch (eingabe)
	//{
		//case 48:	SET_FALSE(flagBalActiv);
		//bmschip_writeConfig();
		//break;
		//case 49:	SET_TRUE(flagBalActiv);
		//break;
		//default:	break;
	//}
//}
//
//if(IS_FALSE(flagBalActiv)) mode = 48;		//Ausgabe: 0
//if(IS_TRUE(flagBalActiv)) mode = 49;		//Ausgabe: 1
//
////Balancing empfohlen?
//Rec = bmschip_recommendBalancing(bms.volt.val, bms.volt.min, bms.balancing.undervoltage, bms.balancing.RecCells);
//
////Balancing erlaubt?
//if(IS_TRUE(flagBalActiv))
//{
	//bmschip_checkBalancing(bms.volt.val, bms.volt.min, bms.balancing.undervoltage, bms.balancing.cells);
	//bmschip_writeConfig();
//}
//
//if(IS_FALSE(flagBalActiv))
//{
	//bmschip_writeConfig();
	//for(i=0;i<SLAVE_BOARDS;i++)
	//{
		//bms.balancing.cells[i] = 0x0000;
	//}
//}
//// *****************************************************************************************
//
//// *** Strommessung ************************************************************************
//bms.cur.cur_flag = 0x00;
//
//// ********************************************************************************************************************************************************************************************************************************
////Wenn Strommessung angeschlossen:
////bmschip_read_IntADC(&bms.cur.V_cur, &bms.cur.V_reference);
////bms.cur.cur_transmit = evaluate_Current(bms.cur.V_cur, bms.cur.V_reference, &bms.cur.cur_flag, curDirect);
////Wenn Stromsensor nicht Angeschlossen:
//bms.cur.cur_transmit = 0;
//// ********************************************************************************************************************************************************************************************************************************
//
//
//if(bms.cur.cur_transmit>=OVERCURRENT)
//{
	//SET_TRUE(flagOverCur);
//}
//// *****************************************************************************************
//
//// *** Temperaturmessung *******************************************************************
//bmschip_getTemperature(3);
//if(bms.temp.temp_max>=OVERTEMP)
//{
	//SET_TRUE(flagOverTemp);
//}
//// *****************************************************************************************
//
//// *** S-Box Freigabe überprüfen ***********************************************************
//if(STM_flag && !Test_flag)
//{
	////S-Box-Timer inaktiv
	//if(S_Box_Timer == 0)
	//{
		////Erstmaliges Überschreiten Strom
		//if((Overcur_Timer == 0) && (bms.bms_flag & flagOverCur))
		//{
			//Overcur_Timer = 1;
		//}
		//else if((Overcur_Timer > 0) && !(bms.bms_flag & flagOverCur))
		//{
			//Overcur_Timer--;
		//}
		//else if((Overcur_Timer > 0) && (bms.bms_flag & flagOverCur))
		//{
			//Overcur_Timer++;
			//if (Overcur_Timer >= ENTPRELLUNG)
			//{
				//Overcur_Timer = 0;
				//S_Box_Timer = 1;
				//SET_TRUE(flagCritical);
			//}
		//}
//
		////Erstmaliges Überschreiten Spannung
		//if((Overvolt_Timer == 0) && (bms.bms_flag & flagOverVol))
		//{
			//Overvolt_Timer = 1;
		//}
		//else if((Overvolt_Timer > 0) && !(bms.bms_flag & flagOverVol))
		//{
			//Overvolt_Timer--;
		//}
		//else if((Overvolt_Timer > 0) && (bms.bms_flag & flagOverVol))
		//{
			//Overvolt_Timer++;
			//if (Overvolt_Timer >= ENTPRELLUNG)
			//{
				//Overvolt_Timer = 0;
				//S_Box_Timer = 1;
				//SET_TRUE(flagCritical);
			//}
		//}
//
		////Erstmaliges Unterschreiten Spannung
		//if((Undervolt_Timer == 0) && (bms.bms_flag & flagUnderVol))
		//{
			//Undervolt_Timer = 1;
		//}
		//else if((Undervolt_Timer > 0) && !(bms.bms_flag & flagUnderVol))
		//{
			//Undervolt_Timer--;
		//}
		//else if((Undervolt_Timer > 0) && (bms.bms_flag & flagUnderVol))
		//{
			//Undervolt_Timer++;
			//if (Undervolt_Timer >= ENTPRELLUNG)
			//{
				//Undervolt_Timer = 0;
				//S_Box_Timer = 1;
				//SET_TRUE(flagCritical);
			//}
		//}
//
		////Erstmaliges Überschreiten Temperatur
		//if((Overtemp_Timer == 0) && (bms.bms_flag & flagOverTemp))
		//{
			//Overtemp_Timer = 1;
		//}
		//else if((Overtemp_Timer > 0) && !(bms.bms_flag & flagOverTemp))
		//{
			//Overtemp_Timer--;
		//}
		//else if((Overtemp_Timer > 0) && (bms.bms_flag & flagOverTemp))
		//{
			//Overtemp_Timer++;
			//if (Overtemp_Timer >= ENTPRELLUNG)
			//{
				//Overtemp_Timer = 0;
				//S_Box_Timer = 1;
				//SET_TRUE(flagCritical);
			//}
		//}
		//
		////Erstmaliger Kommunikationsfehler
		//if((Communication_Timer == 0) && (bms.bms_flag & flagCommunication))
		//{
			//Communication_Timer = 1;
		//}
		//else if((Communication_Timer > 0) && !(bms.bms_flag & flagCommunication))
		//{
			//Communication_Timer--;
		//}
		//else if((Communication_Timer > 0) && (bms.bms_flag & flagCommunication))
		//{
			//Communication_Timer++;
			//if(Communication_Timer >= ENTPRELLUNGCOM)
			//{
				//Communication_Timer = 0;
				//S_Box_Timer = 1;
				//SET_TRUE(flagCritical);
			//}
		//}
//
	//} //Entprellung ueberschritten -> S-Box-Timer aktiv
	//else if((S_Box_Timer >= 1))
	//{
		//S_Box_Timer++;
		//if(S_Box_Timer >= SBOXLIMIT)
		//{
			//S_Box_NOT_active;
			//S_Box_Timer = 0;
			//S_Box_Timer_Done = 1;
			//SET_FALSE(flagCritical);
		//}
	//}
	//else if(!S_Box_Timer_Done)
	//{
		//S_Box_active;
	//}
//}
//else if(STM_flag == 0) //Sofortige Abschaltung durch USER
//{
	//S_Box_NOT_active;
	//S_Box_Timer=0;
//}
//
////CAN_SCHEDULE_MESSAGE1;
//CAN_SCHEDULE_MESSAGE2;
//CAN_SCHEDULE_MESSAGE3;
//CAN_SCHEDULE_MESSAGE4;
//
////BMS-Flag Reset fuer naechsten Durchgang
//SET_FALSE(flagCommunication);
//SET_FALSE(flagOverCur);
//SET_FALSE(flagOverTemp);
//SET_FALSE(flagOverVol);
//SET_FALSE(flagUnderVol);
//// *****************************************************************************************
//}
//
//void timer_100ms_task()	//10 Hz
//{
	//Moduleelectronic_Task();
//}
//
//void timer_500ms_task()	//2 Hz
//{
//// *** Spannungsmessung ********************************************************************
////Falls Balancing-flag gesetzt -> Balancing deaktivieren
//bal = 0x00;
//if(IS_TRUE(flagBalActiv))
//{
	//bal = 0x01;
	//SET_FALSE(flagBalActiv);
	//bmschip_writeConfig();
//}
//
////Messung
//if (bmschip_getVoltages(bms.volt.val) && !(bal))
//{
	//SET_TRUE(flagCommunication);
//}
//
////Falls Balancing-flag gesetzt -> Balancing aktivieren
//if(IS_FALSE(flagBalActiv) && bal == 0x01)
//{
	//SET_TRUE(flagBalActiv);
	//bmschip_writeConfig();
//}
//
//bmschip_evaluate(bms.volt.val, &bms.volt.max, &bms.volt.min, &bms.volt.avg, &bms.volt.NumOfCells);
//if(bms.volt.min<=UNDERVOLT)
//{
	//SET_TRUE(flagUnderVol);
//}
//if(bms.volt.max>=OVERVOLT)
//{
	//SET_TRUE(flagOverVol);
//}
//// *****************************************************************************************	
	//
	//
	//// *** Ausgabe via UART ********************************************************************
	////SBox Timer aktiv
	//usart_transmit_string("\f");
	//if(IS_TRUE(flagCommunication) || IS_TRUE(flagOverCur) || IS_TRUE(flagOverVol) || IS_TRUE(flagOverTemp) || IS_TRUE(flagUnderVol))
	//{
		//utoa(S_Box_Timer, uart_out, 10);	//int in ASCII (uart_out ist ASCII-buffer)
		//usart_transmit_string(" S-Box Timer: ");
		//usart_transmit_string(&uart_out[0]);
		//usart_transmit_string("\r\n\n");	
	//}
	//
	////Fehlerausgabe
	//if(IS_TRUE(flagCommunication))
	//{
		//usart_transmit_string(" Fehler: Kommunikation!\r\n");
	//}                                           
	//if(bms.volt.min<=UNDERVOLT)
	//{
		//usart_transmit_string(" Fehler: Undervoltage!\r\n");
	//}
	//if(bms.volt.max>=OVERVOLT)
	//{
		//usart_transmit_string(" Fehler: Overvoltage!\r\n");
	//}
	//if(bms.temp.temp_max>=OVERTEMP)
	//{
		//usart_transmit_string(" Fehler: Overtemperature!\r\n");
	//}
	//if(bms.cur.cur_transmit>=OVERCURRENT)
	//{
		//usart_transmit_string(" Fehler: OverCurrent!\r\n");
	//}
	//
	////Formatierte Ausgabe der einzelnen Spannungswerte
	//usart_transmit_string("            \t");
	//for(i=0; i<SLAVE_BOARDS; i++)
	//{
		//usart_transmit_string("Slave ");
		//utoa(i+1, uart_out, 10);
		//while(!(usart_transmit_char(uart_out[0])));
		//usart_transmit_string(":\t");
	//}
	//
	//for(i=0; i<12; i++)
	//{
		//usart_transmit_string(" \r\n");
		//usart_transmit_string(" Zelle ");
		//utoa(i+1, uart_out, 10);
		//while(!(usart_transmit_char(uart_out[0])));
		//while(!(usart_transmit_char(uart_out[1])));
		//usart_transmit_string(": \t");
		//
		//for(i1=0; i1<SLAVE_BOARDS; i1++)
		//{
			//if(cells_per_board[i1] & (1<<i))
			//{
				//if(bms.volt.val[((i1*12)+i)] >= 10000)
				//{
					//utoa(bms.volt.val[((i1*12)+i)], uart_out, 10);
					//while(!(usart_transmit_char(uart_out[0])));
					//while(!(usart_transmit_char(',')));
					//usart_transmit_string(&uart_out[1]);
					//usart_transmit_string(" V\t");
				//}
				//else
				//{
					//usart_transmit_string("0,");
					//utoa(bms.volt.val[((i1*12)+i)], uart_out, 10);
					//usart_transmit_string(&uart_out[0]);
					//usart_transmit_string(" V\t");
				//}
			//}
			//else
			//{
				//usart_transmit_string("Keine Zelle\t");
			//}
		//}
	//}
	//usart_transmit_string(" \r\n\n");
//
	////Min. Voltage
	//utoa(bms.volt.min, uart_out, 10);	//int in ASCII (uart_out ist ASCII-buffer)
	//usart_transmit_string(" min. Voltage:\t ");
	//while(!(usart_transmit_char(uart_out[0])));
	//while(!(usart_transmit_char(',')));
	//usart_transmit_string(&uart_out[1]);
	//usart_transmit_string(" V");
	//
	////Avg. Voltage
	//utoa(bms.volt.avg, uart_out, 10);
	//usart_transmit_string("\r\n avg. Voltage:\t ");
	//while(!(usart_transmit_char(uart_out[0])));
	//while(!(usart_transmit_char(',')));
	//usart_transmit_string(&uart_out[1]);
	//usart_transmit_string(" V");
	//
	////Max. Voltage
	//utoa(bms.volt.max, uart_out, 10);
	//usart_transmit_string("\r\n max. Voltage:\t ");
	//while(!(usart_transmit_char(uart_out[0])));
	//while(!(usart_transmit_char(',')));
	//usart_transmit_string(&uart_out[1]);
	//usart_transmit_string(" V\r\n");
	//
	//
	////Ausgabe der Temperaturen des LTC6804
	//for(i=0; i<SLAVE_BOARDS; i++)
	//{
		//usart_transmit_string("\r\n Temperatur ");
		//utoa(i+1, uart_out, 10);
		//while(!(usart_transmit_char(uart_out[0])));
		//usart_transmit_string(":\t");
		//
		//tempspeicher = (sint16_t)(bms.temp.temp_transmit[i]/100);	//Temp vor dem Komma
		//itoa(tempspeicher, uart_out, 10);
		//usart_transmit_string(uart_out);
		//while(!(usart_transmit_char(',')));
		//tempspeicher = (sint16_t)(bms.temp.temp_transmit[i]%100);	//Temp hinter dem Komma
		//itoa(tempspeicher, uart_out, 10);
		//usart_transmit_string(uart_out);
		//usart_transmit_string(" C");
		//tempspeicher=0;
	//}
//
	////Ausgabe des Stroms
	//if(curDirect == 1)		//Entladen
	//{
		//usart_transmit_string("\r\n\n Entlade-Strom: ");
	//}
	//else if(curDirect==0)	//Laden
	//{
		//usart_transmit_string("\r\n\n Lade-Strom: ");
	//}
	//
////	usart_transmit_string("\r\n\n S-Box-Signal: ");	
////	usart_transmit_char(S_Box_active);
		//
	//
	//if(bms.cur.cur_transmit >= 100000000) // >100A
	//{
		//curSpeicher = (bms.cur.cur_transmit) / 1000000;
		//utoa(curSpeicher, uart_out, 10);
		//usart_transmit_string(&uart_out[0]);
		//while(!(usart_transmit_char(',')));
		//curSpeicher = (bms.cur.cur_transmit) % 1000000;
		//ultoa(curSpeicher, uart_out, 10);
		//usart_transmit_string(&uart_out[0]);
		//usart_transmit_string(" A \r\n\n");
	//}
	//else if (bms.cur.cur_transmit >= 10000000) //>10A
	//{
		//curSpeicher = (bms.cur.cur_transmit) / 1000000;
		//utoa(curSpeicher, uart_out, 10);
		//usart_transmit_string(&uart_out[0]);
		//while(!(usart_transmit_char(',')));
		//curSpeicher = (bms.cur.cur_transmit) % 1000000;
		//ultoa(curSpeicher, uart_out, 10);
		//usart_transmit_string(&uart_out[0]);
		//usart_transmit_string(" A \r\n");
	//}
	//else if (bms.cur.cur_transmit >= 1000000) //>1A
	//{
		//curSpeicher = (bms.cur.cur_transmit) / 1000000;
		//utoa(curSpeicher, uart_out, 10);
		//usart_transmit_string(&uart_out[0]);
		//while(!(usart_transmit_char(',')));
		//curSpeicher = (bms.cur.cur_transmit) % 1000000;
		//ultoa(curSpeicher, uart_out, 10);
		//usart_transmit_string(&uart_out[0]);
		//usart_transmit_string(" A \r\n");
	//}
	//else if (bms.cur.cur_transmit >= 100000) //>0.1A
	//{
		//while(!(usart_transmit_char('0')));
		//while(!(usart_transmit_char(',')));
		//curSpeicher = (bms.cur.cur_transmit);
		//ultoa(curSpeicher, uart_out, 10);
		//usart_transmit_string(&uart_out[0]);
		//usart_transmit_string(" A \r\n");
	//}
	//else
	//{
		//while(!(usart_transmit_char('0')));
		//usart_transmit_string(" A \r\n");
	//}
//
	////Ausgabe Strom-Status
	//if(bms.cur.cur_flag & 0x01)
	//{
		//usart_transmit_string(" Strom befindet sich in kritischem Bereich: -2A ... 0A \r\n");
	//}
	//else if(bms.cur.cur_flag & 0x02)
	//{
		//usart_transmit_string(" Fehler: Strom fliesst in den Speicher! \r\n");
	//}
	//else if(bms.cur.cur_flag & 0x04)
	//{
		//usart_transmit_string(" Strom befindet sich in kritischem Bereich: 0A ... +2A \r\n");
	//}
	//else if(bms.cur.cur_flag & 0x08)
	//{
		//usart_transmit_string(" Fehler: Strom fliesst aus dem Speicher! \r\n");
	//}
	//else if(bms.cur.cur_flag & 0x10)
	//{
		//usart_transmit_string(" Fehler: Betriebsbereich ueberschritten! \r\n");
	//}
	//// *****************************************************************************************
//
	//// *** Balancing Eingabe via UART **********************************************************
	//usart_transmit_string("\r\n Balancing empfohlen an ");
	//utoa(Rec, uart_out, 10);
	//usart_transmit_string(&uart_out[0]);
	//usart_transmit_string(" Zellen.");
	//usart_transmit_string("\r\n Balancing-Mode:    ");
	//while(!(usart_transmit_char(mode)));
	//usart_transmit_string("\r\n <1> Charge ");
	//usart_transmit_string("\r\n <0> Drive ");
	//// *****************************************************************************************
//
//}
//
//
//void timer_1s_task()		//1 Hz
//{
	////insert code here
	//
	//
	////----------------
//}






















