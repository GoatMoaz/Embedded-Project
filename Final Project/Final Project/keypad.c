#include "keypad.h"

unsigned char arr[4][4]={
	{'7','8','9','/'},
	{'4','5','6','*'},
	{'1','2','3','-'},
	{'?','0','=','+'}
	};
	
// -------------- Initialize Keypad --------------

void keypad_init(void){
	
	// rows output
	set_bit(DDRC , 2); 
	set_bit(DDRC , 3);
	set_bit(DDRC , 4);
	set_bit(DDRC , 5);
	
	// column input
	clr_bit(DDRD , 7);
	clr_bit(DDRD , 6);
	clr_bit(DDRD , 5);
	clr_bit(DDRD , 3);
	
	// enable pull up
	set_bit(PORTD , 7);
	set_bit(PORTD , 6);
	set_bit(PORTD , 5);
	set_bit(PORTD , 3);
}

// -------------- Retrieve The input's Value --------------

unsigned char keypad_get_value(void){
	unsigned char ans=0xff;
	for (int row=5 ; row>=2 ; row--)
	{
		PORTC|=0b00111100;
		clr_bit(PORTC , row);
		for (int col=7 ; col>=3 ; col--)
		{
			if (col==4)
				col--;
			if (!get_bit(PIND , col))
			{
				_delay_ms(10);
				if (!get_bit(PIND , col))
				{
					if (col==3)
						ans=arr[5-row][7-col-1];
					else
						ans=arr[5-row][7-col];
				}
			}	
		}
	}
	// Make sure that the user can't enter any characters but numbers , = and +
	if((ans != '=') && (ans != '+') && ((ans>'9') || (ans<'0'))) 
		return 0xff;
	return ans;
}