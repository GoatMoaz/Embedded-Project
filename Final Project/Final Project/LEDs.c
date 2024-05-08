#include "LEDs.h"

void leds_init(){
	
	set_bit(DDRA , 4);
	set_bit(DDRA , 5);
	set_bit(DDRA , 6);
	set_bit(DDRB , 7);
	
}

void display_on_leds(unsigned char number){
	unsigned char counter = 0;
	while(counter < 4){
		
		if(number & 1){
			
			if(!counter)
				set_bit(PORTB , 7);
			else if (counter == 1)
				set_bit(PORTA , 6);
			else if (counter == 2)
				set_bit(PORTA , 5);
			else 
				set_bit(PORTA , 4);
				
		}
		
		else{
			
			if(!counter)
				clr_bit(PORTB , 7);
			else if (counter == 1)
				clr_bit(PORTA , 6);
			else if (counter == 2)
				clr_bit(PORTA , 5);
			else
				clr_bit(PORTA , 4);
				
		}
		counter++;
		number>>=1;
	}
}