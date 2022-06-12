#ifndef __LCD_H
#define __LCD_H	
#include "sys.h"
#include "delay.h"
#include "stdint.h"
#define D0  PB0
#define D1	PB1
#define D2	PB2
#define D3	PB3
#define D4	PB4
#define D5	PB5
#define D6	PB6
#define D7	PB7
#define LCD_EN PA9
#define LCD_RS PA7

#define clear 		0x01
#define display 	0x0C
#define dis_2line 0x38


#define line1 		0x80
#define line2 		0xC0
#define line3			0x94
#define line4			0xD4
#define p_firstln 0x02

typedef enum
{ l1=1,
	l2=2,
	l3=3,
	l4=4
} _line;




void LCD_sentString (uint8_t *str);
void LCD_sentCHAR (uint8_t _char);
void LCD_sentCMD (uint8_t cmd);
void LCD_sentDATA (uint8_t Data);
void LCD_init ();

void LCD_start ();

void LCD_display (uint8_t *str,_line line);
void LCD_sentint (uint8_t _int);

void LCD_displaystr (uint8_t *str,_line line);

void LCD_setfull_str (uint8_t *str1, uint8_t *str2);

void LCD_sentint (uint8_t _int);

void LCD_displaynum (uint8_t _int,_line line);
void LCD_setfull_num (uint8_t _int1, uint8_t _int2);


#endif

