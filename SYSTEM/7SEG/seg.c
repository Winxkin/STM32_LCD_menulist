#include "seg.h"

void seg_init ()
{
  pinMode(a,OUTPUT);
	pinMode(b,OUTPUT);
	pinMode(c,OUTPUT);
	pinMode(d,OUTPUT);
	pinMode(e,OUTPUT);
	pinMode(f,OUTPUT);
	pinMode(g,OUTPUT);
	pinMode(dp,OUTPUT);
}

void seg_set (uint8_t Data)
{
	uint8_t buf[8];
	if(Data & 1)  buf[0]=1 ;
	else buf[0]=0;
	
	if(Data & 2)  buf[1]=1;
	else buf[1]=0;
	
	if(Data & 4)  buf[2]=1;
	else buf[2]=0;
	
	if(Data & 8)  buf[3]=1;
	else buf[3]=0;
	
	if(Data & 16)  buf[4]=1;
	else buf[4]=0;
	
	if(Data & 32)  buf[5]=1;
	else buf[5]=0;
	
	if(Data & 64)  buf[6]=1;
	else buf[6]=0;
	
	if(Data & 128) buf[7]=1;
	else buf[7]=0;
	
	digitalWrite( a, buf[0] );
	digitalWrite( b, buf[1] );
	digitalWrite( c, buf[2] );
	digitalWrite( d, buf[3] );
	digitalWrite( e, buf[4] );
	digitalWrite( f, buf[5] );
	digitalWrite( g, buf[6] );
	digitalWrite( dp, buf[7] );
	

}



void seg_setnumberA (uint8_t number)
{
  if(number == 0)  seg_set (0xC0);
	else if (number == 1 ) seg_set (0xF9);
	else if (number == 2 ) seg_set (0xA4);
	else if (number == 3 ) seg_set (0xB0);
	else if (number == 4 ) seg_set (0x99);
	else if (number == 5 ) seg_set (0x92);
	else if (number == 6 ) seg_set (0x82);
	else if (number == 7 ) seg_set (0x8F);
	else if (number == 8 ) seg_set (0x80);
	else if (number == 9 ) seg_set (0x90);
	else seg_set (0xFF);
	

}

void seg_setnumberK (uint8_t number)
{
  if(number == 0)  seg_set (0x3F);
	else if (number == 1 ) seg_set (0x06);
	else if (number == 2 ) seg_set (0x5B);
	else if (number == 3 ) seg_set (0x40);
	else if (number == 4 ) seg_set (0x66);
	else if (number == 5 ) seg_set (0x6D);
	else if (number == 6 ) seg_set (0x7D);
	else if (number == 7 ) seg_set (0x07);
	else if (number == 8 ) seg_set (0x7F);
	else if (number == 9 ) seg_set (0x6F);
	else seg_set (0x00);
	

}










