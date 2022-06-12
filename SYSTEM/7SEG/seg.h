#ifndef __SEG_H
#define __SEG_H	
#include "delay.h"
#include "sys.h"
#include "stdint.h"
#define a  PB0
#define b  PB1
#define c  PB2
#define d  PB3
#define e  PB4
#define f  PB5
#define g  PB6
#define dp PB7


void seg_init ();
void seg_setnumberA (uint8_t number);
void seg_setnumberK (uint8_t number);
void seg_set (uint8_t Data);




#endif


