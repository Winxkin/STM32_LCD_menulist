#ifndef __DHT_H
#define __DHT_H	
#include "delay.h"
#include "sys.h"
#include "stdint.h"
#define pin_onewire PA0

void DHT_RST () ;
uint8_t Readbit ();
uint8_t Readbyte ();
//uint8_t Readdata(uint8_t* temp, uint8_t* humi);
uint8_t check_DHT11 ();
uint8_t Readtemp();
uint8_t Readhumi();

#endif

