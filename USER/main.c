#include "stm32f10x.h"
#include "sys.h"
#include "LCD.h"
#include "stdint.h"
#include "button.h"
#include "stdio.h"

#define ON 1
#define OFF 0
#define LED1 0
#define LED2 1
#define LED3 2



void atulatoraction (uint8_t devices, uint8_t status)
{
	switch (devices)
	{
		case LED1: if(status)  digitalWrite(PA5,0);
							 else 			digitalWrite(PA5,1);
				break;	
		case LED2: if(status)  digitalWrite(PA4,0);
							 else 			digitalWrite(PA4,1);
				break;
		case LED3: if(status)  digitalWrite(PA3,0);
							 else 			digitalWrite(PA3,1);
				break;
	}


}



typedef struct linker
{	
	uint8_t menuID;
	struct linker *pre;
	uint8_t title[20];
	uint8_t list1[20];
	struct linker *nextlist1; void (*ONled) (uint8_t,uint8_t);
	uint8_t list2[20];
	struct linker *nextlist2; void (*OFFled) (uint8_t,uint8_t);
	uint8_t list3[20];
	struct linker *nextlist3;

} Menu;

Menu mainmenu, led01,led02,led03;

Menu mainmenu = {
	NULL,
	NULL,
	"		Menu",
	"	led01",&led01,NULL,
	"	led02",&led02,NULL,
	"	led03",&led03,
};

Menu led01 = {
	LED1,
	&mainmenu,
	"		LED01",
	"	ON",NULL,&atulatoraction,
	"	OFF",NULL,&atulatoraction,
	"	none",NULL,
};

Menu led02 = {
	LED2,
	&mainmenu,
	"		LED02",
	"	ON",NULL,&atulatoraction,
	"	OFF",NULL,&atulatoraction,
	"	none",NULL,
};

Menu led03 = {
	LED3,
	&mainmenu,
	"		LED03",
	"	ON",NULL,&atulatoraction,
	"	OFF",NULL,&atulatoraction,
	"	none",NULL,
};

/*--------------------------------------------*/

void Menudisplay (Menu *menu, uint8_t select)
{
	  LCD_start();
	  
		LCD_displaystr(menu->title,l1);
	  LCD_displaystr(menu->list1,l2);
		LCD_displaystr(menu->list2,l3);
		LCD_displaystr(menu->list3,l4);
	  LCD_displaystr(">",select);
	  
}








int main(void)
 {
	
	 Menu *menu;
	 uint8_t select = 2; 
	 menu = &mainmenu;
	  button_init();
	 LCD_init();	 
	 pinMode(PA5,OUTPUT);
	pinMode(PA4,OUTPUT);
	pinMode(PA3,OUTPUT);
	Menudisplay (menu,select);
	 digitalWrite(PA5,1);
	 digitalWrite(PA4,1);
	 digitalWrite(PA3,1);
	
	 while (1)
	{ 
    
	  if(Readbutton ()==_down)
		{
				while (Readbutton()==_down) {};
			  select = (select==4)?2 : select+1;
		    Menudisplay (menu,select);
		}
		if(Readbutton ()==_up)
		{
				while (Readbutton ()==_up) {};
			  select = (select==2)?4 : select-1;
		    Menudisplay (menu,select);
		}
		if(Readbutton ()==_right)
		{
				while (Readbutton()==_right) {};
			  switch(select)
				{
					case 2: menu=(menu->nextlist1==NULL)?menu : menu->nextlist1; break;
					case 3: menu=(menu->nextlist2==NULL)?menu : menu->nextlist2; break;
					case 4: menu=(menu->nextlist3==NULL)?menu : menu->nextlist3; break;
				
				}
				Menudisplay (menu,select);
				
		}
		
		if(Readbutton ()==_left)
		{
				while (Readbutton()==_left) {};
			  switch(select)
				{
					case 2: menu=(menu->pre==NULL)?menu : menu->pre; break;
					case 3: menu=(menu->pre==NULL)?menu : menu->pre; break;
					case 4: menu=(menu->pre==NULL)?menu : menu->pre; break;
				
				}
				Menudisplay (menu,select);
				
		}
		if(Readbutton ()==_go)
		{
				while (Readbutton()==_go) {};
			  switch(select)
				{
					case 2: if(menu->ONled != NULL) menu->ONled(menu->menuID,ON);
						break;
					case 3: if(menu->OFFled != NULL) menu->OFFled(menu->menuID,OFF);
					  break;
				
				}
				
		}
		

	}
	 
	 

 }
