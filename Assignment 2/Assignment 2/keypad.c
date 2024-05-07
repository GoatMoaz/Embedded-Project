#include "keypad.h"
#include <util/delay.h>
unsigned char arr[4][4]={
	{'7','8','9','/'},
	{'4','5','6','*'},
	{'1','2','3','-'},
	{'?','0','=','+'}
	};
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
void seven_segment_init(){
	DDRB |= 0b01111111;
}
void display_on_seven_seg(int num){
	int arr[10]={
		 0b00111111,//0
		 0b00000110,//1
		 0b01011011,//2
		 0b01001111,//3
		 0b01100110,//4
		 0b01101101,//5
		 0b01111101,//6
		 0b00000111,//7
		 0b01111111,//8
		 0b01101111 //9
		 };
	PORTB=arr[num%10];
}
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
	return ans;
}