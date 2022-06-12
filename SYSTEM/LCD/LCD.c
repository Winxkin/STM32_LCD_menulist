#include "LCD.h"

void LCD_init ()
{
	pinMode(D0,OUTPUT);
	pinMode(D1,OUTPUT);
	pinMode(D2,OUTPUT);
	pinMode(D3,OUTPUT);
	pinMode(D4,OUTPUT);
	pinMode(D5,OUTPUT);
	pinMode(D6,OUTPUT);
	pinMode(D7,OUTPUT);
	pinMode(LCD_EN,OUTPUT);
	pinMode(LCD_RS,OUTPUT);
}

void LCD_sentDATA (uint8_t Data)
{
  uint8_t b[8];
	if(Data & 1)  b[0]=1;
	else b[0] =0;
	
	if(Data & 2)  b[1]=1;
	else b[1] =0;
	
	if(Data & 4)  b[2]=1;
	else b[2] =0;
	
	if(Data & 8)  b[3]=1;
	else b[3] =0;
	
	if(Data & 16)  b[4]=1;
	else b[4] =0;
	
	if(Data & 32)  b[5]=1;
	else b[5] =0;
	
	if(Data & 64)  b[6]=1;
	else b[6] =0;
	
	if(Data & 128)  b[7]=1;
	else b[7] =0;
	
	
	digitalWrite( D0, b[0] );
	digitalWrite( D1, b[1] );
	digitalWrite( D2, b[2] );
	digitalWrite( D3, b[3] );
	digitalWrite( D4, b[4] );
	digitalWrite( D5, b[5] );
	digitalWrite( D6, b[6] );
	digitalWrite( D7, b[7] );
	
	
}

void LCD_sentCMD (uint8_t cmd)
{
	digitalWrite (LCD_RS,LOW);
	LCD_sentDATA (cmd);
	digitalWrite (LCD_EN,LOW);
	digitalWrite (LCD_EN,HIGH);
	delay_ms (1);
  
}

void LCD_sentCHAR (uint8_t _char)
{
	digitalWrite (LCD_RS,HIGH);
	LCD_sentDATA (_char);
	digitalWrite (LCD_EN,LOW);
	digitalWrite (LCD_EN,HIGH);
	delay_ms (1);
  
}


void LCD_sentString (uint8_t *str)
{
	int i;
	for(i=0; *(str) != '\0';i++)
	{
	   LCD_sentCHAR (*(str)++);
	}
	
}

void LCD_start ()
{
  LCD_sentCMD(clear);
	LCD_sentCMD(dis_2line);
	LCD_sentCMD(display);
 
}


void LCD_displaystr (uint8_t *str,_line line)
{
  if(line == l1)
	{
	  LCD_sentCMD(line1);
		LCD_sentString(str);
	}
	else if (line == l2)
	{
		LCD_sentCMD(line2);
		LCD_sentString(str);
	}
	else if (line == l3)
	{
		LCD_sentCMD(line3);
		LCD_sentString(str);
	}	
	else 
	{
		LCD_sentCMD(line4);
		LCD_sentString(str);
	}		
	

}


void LCD_setfull_str (uint8_t *str1, uint8_t *str2)
{
	 LCD_init();
	 LCD_start();
	 LCD_displaystr (str1,l1);
	 LCD_displaystr (str2,l2);
}


void LCD_sentint (uint8_t _int)
{ 
	 uint8_t hundred =0;
		 uint8_t dozen = 0;
		 uint8_t unit  =0;
	
	 if(_int<10)
	 {
			LCD_sentCHAR(_int+0x30);
	 }
	 else if (_int>=10 && _int<100)
	 {
	     dozen = _int/10;
		   unit = _int%10;
		  
		  LCD_sentCHAR (dozen + 0x30);
		  LCD_sentCHAR (unit + 0x30);
	 
	 }
	 else
	 { 
		 hundred = _int/100;
		 dozen = (_int/10)%10;
		 unit = _int%10;
	    
		 LCD_sentCHAR (hundred + 0x30);
		 LCD_sentCHAR (dozen + 0x30);
		 LCD_sentCHAR (unit + 0x30);
	 }
}

void LCD_displaynum (uint8_t _int,_line line)
{
  if(line == l1)
	{
	  LCD_sentCMD(line1);
		LCD_sentint ( _int);
	}
	else
	{
		LCD_sentCMD(line2);
		LCD_sentint ( _int);
	}

}

void LCD_setfull_num (uint8_t _int1, uint8_t _int2)
{
	 LCD_init();
	 LCD_start();
	 LCD_displaynum (_int1,l1);
	 LCD_displaynum (_int2,l2);
}

