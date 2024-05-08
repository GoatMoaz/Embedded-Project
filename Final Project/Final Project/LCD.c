#include "LCD.h"

// -------------- Initialize LCD -------------- 

void LCD_init(void){
	set_bit(DDRA,3);
	set_bit(DDRA,2);
	
	set_bit(DDRB,0);
	set_bit(DDRB,1);
	set_bit(DDRB,2);
	set_bit(DDRB,4);
	
	_delay_ms(15); // You have to make this delay to make sure the LCD is on
	
	LCD_command(0x02); // to set the LCD
	LCD_command(0x28); // as a 4 bit mode
	
	LCD_command(0x0e); // Display on, Cursor blinking
	LCD_command(0x01); // Clear the display screen
	LCD_command(0x80); // Force the cursor to the beginning of the 1st line
}

// -------------- Write a command to the LCD --------------

void LCD_command(unsigned char cmd){
	RS_command(); // Rs is receiving a command not a data
	
	// Send the high bits of the cmd to LCD
	PORTB &= 0b11101000;
	
	unsigned char high = ((cmd&0xf0)>>4);
	
	latch(high);
	
	// Send the low bits of the cmd to LCD
	PORTB &= 0b11101000;
	
	unsigned char low = (cmd&0x0f);
	
	latch(low);
	
	_delay_ms(5);

}

// -------------- Write a character to the LCD --------------

void LCD_write_char(unsigned char ch){
	RS_data(); // Rs is receiving a data not a command
	
	// Send the high bits of the data to LCD
	
	PORTB &= 0b11101000;
	
	unsigned char high = ((ch&0xf0)>>4);
	latch(high);
	
	// Send the low bits of the data to LCD
	
	PORTB &= 0b11101000;
	
	unsigned char low = (ch&0x0f);
	latch(low);
	_delay_ms(5);
}

// -------------- Set Rs to receive data --------------

void RS_data(){
	set_bit(PORTA,3);
}

// -------------- Set Rs to receive a command --------------

void RS_command(){
	clr_bit(PORTA,3);
}

// -------------- Enable the latch and Save the digits to the PORT --------------

void latch(unsigned char digits){
	
	unsigned char temp = ((digits&0b00001000)<<1) | (digits&0b00000111);
	
	PORTB |= temp;
	
	// Enable the E register and latch
	
	set_bit(PORTA,2);
	_delay_ms(1);
	clr_bit(PORTA,2);
}

// -------------- Send a Full string to the LCD --------------

LCD_string(unsigned char* str){
	for (int i=0 ; str[i]!='\0' ; i++)
	{
		LCD_write_char(str[i]);
	}
}

// -------------- to Clear the LCD --------------

LCD_clear(){
	LCD_command(0x01);
}