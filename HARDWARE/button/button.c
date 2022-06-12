#include "button.h"



void button_init ()
{
  pinMode (up,INPUT);
	pinMode (down,INPUT);
	pinMode (left,INPUT);
	pinMode (right,INPUT);
	pinMode (go,INPUT);
}

bt_state Readbutton ()
{ 
	bt_state buttonstate = _none;
  if(digitalRead(up) == 1)	buttonstate = _up;
	if(digitalRead(down) == 1)	buttonstate = _down;
	if(digitalRead(left) == 1)	buttonstate = _left;
	if(digitalRead(right) == 1)	buttonstate = _right;
	if(digitalRead(go) == 1)	buttonstate = _go;
  
	return buttonstate;
}