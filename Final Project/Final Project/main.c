#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h> 


#include "bit_math.h"
#include "atmga32.h"

#include "keypad.h"
#include "Seven_Segment.h"
#include "LCD.h"
#include "LEDs.h"

int main(void){
	
	keypad_init();
	LCD_init();
	int array[16] = {0};
	unsigned char targets[16] = {-1};
	int target = 0;
	unsigned char counter = 0 , counter2 = 0;
	bool flag = false;
    while (1) {
		
		unsigned char value = keypad_get_value();
		if(flag){
			
			// if any number is pressed then update the target value
			
			if ((value != 0xff) && (value != '=') && (value != '+')){
				
				LCD_write_char(value);
				_delay_ms(400);
				target+=value-'0';
				target*=10;
				
			}
			
			// if = is pressed then end the LCD process and start searching
			
			else if (value == '='){
				
				LCD_clear();
				_delay_ms(400);
				break;
				
			}
		
		}
		
		else{
			
			// if any number is pressed then add it to the array
			
			if ((value != 0xff) && (value != '=') && (value != '+')){
				
				LCD_write_char(value);
				_delay_ms(400);
				array[counter]+=value-'0';
				array[counter]*=10;
				
			}
			
			// if + is pressed then move to the next element to the array
			
			else if (value == '+'){
				
				LCD_command(0x14);
				counter++;
				_delay_ms(400);
				
			}
			
			// if = is pressed then stop entering numbers to the array
			
			else if (value == '=') {
				
				LCD_clear();
				_delay_ms(400);
				counter++;
				flag = true;
				
			}
		}		
    }
	
	// Search for the target and add the positions to targets
	
	for (int i=0 ; i<counter ; i++){
		if(target == array[i]){
			
			targets[counter2]=i;
			counter2++;

		}
	}
	
	// if the target is not found then print in the LCD not Found
	
	if(counter2==0){
		LCD_string("NOT FOUND");
	}
	
	//if  the target is found then display the positions in Seven segment and Leds 
	
	else{
		seven_segment_init();
		leds_init();
		unsigned char i = 0;
		while(1){
			display_on_seven_seg(targets[i%counter2]);
			display_on_leds(targets[i%counter2]);
			_delay_ms(1000);
			i++;
		}
			
	}
	
}

