
#ifndef UNTITLED1_ATMGA32_H
#define UNTITLED1_ATMGA32_H

#define DDRA *(volatile unsigned char*)(0x3A)
#define PORTA *(volatile unsigned char*)(0x3B)
#define PINA *(volatile unsigned char*)(0x39)


#define DDRB *(volatile unsigned char*)(0x37)
#define PINB *(volatile unsigned char*)(0x36)
#define PORTB *(volatile unsigned char*)(0x38)

#define DDRC *(volatile unsigned char*)(0x34)
#define PINC *(volatile unsigned char*)(0x33)
#define PORTC *(volatile unsigned char*)(0x35)

#define DDRD *(volatile unsigned char*)(0x31)
#define PIND *(volatile unsigned char*)(0x30)
#define PORTD *(volatile unsigned char*)(0x32)


#endif 
