#ifndef __BUTTON_H
#define __BUTTON_H	
#include "sys.h"
#include "delay.h"
#include "stdint.h"
#include "LCD.h"

#define up  	PA10
#define down 	PA11
#define left 	PA12
#define right PA13
#define go		PA14

typedef enum
{ _up,
	_down,
	_left,
	_right,
	_go,
	_none
} bt_state;


void button_init ();
bt_state Readbutton ();




#endif


