#include "Seven_Segment.h"

// -------------- Initialize 7 Segment --------------

void seven_segment_init(){
	DDRB |= 0b00010111;
}

// -------------- Display on 7 Segment --------------

void display_on_seven_seg(unsigned char num){
	if(num<8)
		PORTB = num;
	else if (num==8)
		PORTB = 0b00010000;
	else
		PORTB = 0b00010001;
	
}