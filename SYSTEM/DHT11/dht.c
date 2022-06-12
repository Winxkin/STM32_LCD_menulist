#include "dht.h"


void MCUgetwire ()
{
 pinMode (pin_onewire,OUTPUT);
}

void MCUfreewire ()
{
	pinMode (pin_onewire,INPUT);
}

u8 onewire_state()
{
	return digitalRead( pin_onewire );
}

void DHT_RST () 
{ MCUgetwire ();  //MCU control can push or pull wire
	digitalWrite(pin_onewire , HIGH );
	digitalWrite(pin_onewire , LOW );
	delay_ms (20); // delay at least 18ms
	digitalWrite(pin_onewire , HIGH );
	delay_us (30);	// 20-40us
	MCUfreewire ();	
}

uint8_t check_DHT11 ()
{
uint32_t time =0;
  
  while((onewire_state()==1) && (time<100)) 
	{ time ++;
		delay_us(1);
	} // wait down
	if(time>=80) return 0; //error
		

	time =0;
	while((onewire_state()==0) && (time<100)) 
	{ time ++;
		delay_us(1);
	} // wait up
	if(time>=80) return 0; //error
	
	return 1;
	
}





uint8_t Readbit ()
{ uint32_t time =0;
	
	while((onewire_state()==1) && (time<100)) 
	{ time ++;
		delay_us(1);
	} // wait down
	
	
	time =0;
	while((onewire_state()==0) && (time<100)) 
	{ time ++;
		delay_us(1);
	} // wait up
	
	delay_us(40);
	if(onewire_state()==0) return 0;
	else return 1;
	

}

uint8_t Readbyte ()
{ u8 i;
	u8 byte = 0;
	
	for(i=0;i<5;i++)
	{
	  byte<<=1;
		byte|=Readbit();
	}
	
	return byte;
	
}


/*
uint8_t Readdata(uint8_t* temp, uint8_t* humi)
{ 
	uint32_t i=0;
	uint8_t buf[5]={0,0,0,0,0};
	
	void DHT_RST ();
	
	if(check_DHT11 ())
	{
		for(i=0;i<5;i++)
		{
			buf[i]=Readbyte ();
		
		}
	  // checksum
		if((buf[0] + buf[1] + buf[2] + buf[3])==buf[4])
		{
		 *temp = buf[2];
			*humi = buf[0];
		}
	 
	 return 1;
	}
	else	return 0; //error 
  
	
}

*/

uint8_t Readtemp()
{ 
	uint32_t i=0;
	uint8_t buf[5]={0,0,0,0,0};
	
	void DHT_RST ();
	
	if(check_DHT11 () ==1 )
	{
		for(i=0;i<5;i++)
		{
			buf[i]=Readbyte ();
		
		}
	  // checksum
		if((buf[0] + buf[1] + buf[2] + buf[3])==buf[4])
		{
		 return buf[2];
		}
	 
	
	}
	
}


uint8_t Readhumi()
{ 
	uint32_t i=0;
	uint8_t buf[5]={0,0,0,0,0};
	
	void DHT_RST ();
	
	if(check_DHT11 ()==1)
	{
		for(i=0;i<5;i++)
		{
			buf[i]=Readbyte ();
		
		}
	  // checksum
		if((buf[0] + buf[1] + buf[2] + buf[3])==buf[4])
		{
		 return buf[0];
		}
	 	
	}
	
}



