

#ifndef LCD_H_
#define LCD_H_

#define F_CPU 16000000

#include "atmga32.h"
#include "bit_math.h"
#include <util/delay.h>


void LCD_init(void); // Initialize LCD

void LCD_command(unsigned char cmd); // Write a command to the LCD

void LCD_write_char(unsigned char ch); // Write a character to the LCD

void RS_data(void); // Set Rs to receive data

void RS_command(void); // Set Rs to receive command

void latch(unsigned char digits); // Enable the latch and Save the digits to the PORT

void LCD_string(unsigned char* str); // Send a Full string to the LCD

void LCD_clear(void); // to Clear the LCD

#endif 