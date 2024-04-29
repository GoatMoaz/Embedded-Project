#include <avr/io.h>
#include "bit_math.h"
#include <avr/interrupt.h>
#include <util/delay.h>



void initInterrupt1() {
	// Enable internal pull-up resistor on PD3
	PORTD |= (1 << INT1);

	// Set INT1 to trigger on falling edge
	MCUCR |= (1 << ISC11);
	MCUCR &= ~(1 << ISC10);

	// Enable external interrupt INT1
	GICR |= (1 << INT1);
}

void flashLEDs() {
	for (int i = 0; i < 5; i++) {
		PORTB = 0xFF; // Turn on all LEDs
		_delay_ms(500); // Delay for half a second
		PORTB = 0x00; // Turn off all LEDs
		_delay_ms(500); // Delay for half a second
	}
}

void rollLEDs() {
	for (int i = 0; i < 4; i++) {
		PORTB = (1 << i); // Turn on one LED at a time
		_delay_ms(500); // Delay for half a second
	}
}

ISR(INT1_vect) {
	flashLEDs();
}

int main(void) {
	// Set LED pins as output
	DDRB = 0xFF;

	// Set INT1 pin as input
	DDRD &= ~(1 << INT1);

	initInterrupt1();

	// Enable global interrupts
	sei();

	while (1) {
		rollLEDs();
	}

	return 0;
}