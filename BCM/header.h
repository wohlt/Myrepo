/*
 *	header.h
 *
 *	Version		|	Author			|	Date		|	Changes made
 *  -------------------------------------------------------------------
 *	1.0			|	F. Moertl		|	13.12.2014	|
 *
 *
 */

#ifndef HEADER_H_
#define HEADER_H_

#define F_CPU 16000000UL

// ---------------------- Type definitions -------------------------------------
#define sint8_t  signed char
//#define uint8_t  unsigned char
#define sint16_t signed int
//#define uint16_t unsigned int
#define sint32_t signed long
//#define uint32_t unsigned long
#define sint64_t signed long long
//#define uint64_t unsigned long long

typedef unsigned char uint8_t;				//das mache ich, weil sich der Compiler bei den auskommentierten Defines 
typedef unsigned int uint16_t;				//manchmal dumm stellt
typedef unsigned long uint32_t;
typedef unsigned long long uint64_t;

typedef union { uint8_t b[2]; uint16_t s; } u16;
typedef union { uint8_t b[4]; uint16_t s[2]; uint32_t l; } u32;
typedef union { uint8_t b[8]; uint16_t s[4]; uint32_t l[2]; uint64_t ll; } u64;
typedef union { uint8_t b[16]; uint16_t s[8]; uint32_t l[4]; uint64_t ll[2]; } u128;

//folgende Typendefinitionen finden sich in den headerfiles der entsprechenden Funktionen.
//typedef struct { uint32_t id; uint8_t dlc; u64 data; } can_msg_t;
//typedef struct { u64 write_buffer; u64 read_buffer; uint8_t write_bytes; uint16_t write_address; } eeprom_t;
//typedef struct { u128 tx_buffer; u128 rx_buffer; uint8_t bytes; uint8_t current_byte; uint8_t locked; uint8_t flag; } spi_t;
	
// -----------------------------------------------------------------------------

// ---------------------- Global definitions -----------------------------------
#define set_bit(port, bit) (port) |= (1 << (bit))
#define clr_bit(port, bit) (port) &= ~(1 << (bit))

#define PIN_PWM1 105
#define PIN_PWM2 106
#define PIN_PWM3 107
#define PIN_PWM4 108
#define PIN_PWM5 101
#define PIN_PWM6 103
#define PIN_PWM7 109
#define PIN_PWM8 110
#define PIN_PWM9 111

#define PIN_AN10 102
#define PIN_AN11 111
#define PIN_AN1 211
#define PIN_AN2 210
#define PIN_AN3 209
#define PIN_AN4 208
#define PIN_AN5 207
#define PIN_AN6 206
#define PIN_AN7 205
#define PIN_AN8 204
#define PIN_AN9 101

#define PIN_DAC 202

#define PIN_RX 102
#define PIN_TX 103

#define PIN__MISO 109
#define PIN__MOSI 110
#define PIN__SCK 111

#define PIN_GPIO1 112
#define PIN_GPIO2 113
#define PIN_GPIO3 114
#define PIN_GPIO4 115

#endif /* HEADER_H_ */