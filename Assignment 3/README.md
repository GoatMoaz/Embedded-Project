# Embedded C Assignment 3: Control 4 LEDs with External Interrupt

## Objective:

This project involves writing Embedded C code to control 4 LEDs using an ATmega32 microcontroller, triggered by an external interrupt INT1.

## Requirements:

- ATmega32 Microcontroller
- 4 LEDs (Light Emitting Diodes)
- Appropriate resistors for the LEDs
- Push-button switch or any external signal source to trigger the interrupt (for simulating INT1)

## Implementation Details:

1. **Hardware Setup**:

   - Connect the ATmega32 microcontroller to your development board.
   - Connect the 4 LEDs to the GPIO pins of the microcontroller, ensuring appropriate current limiting resistors are used.
   - Connect the external interrupt INT1 pin (usually PD3 on ATmega32) to the signal source (e.g., push-button switch).

2. **Software Implementation**:

   - Set up your development environment with AVR-GCC compiler and AVR programmer.
   - Ensure that the fuse bits of the microcontroller are configured correctly for the clock source and other settings as required for your project.

3. **Main Program Logic**:
   - Write the C code for the ATmega32 microcontroller to initialize the GPIO pins connected to the LEDs and configure the external interrupt INT1.
   - Implement the interrupt service routine (ISR) for INT1, which toggles the state of the LEDs or performs any desired action.
   - Compile the code using the AVR-GCC compiler.
   - Program the compiled code onto the ATmega32 microcontroller using the AVR programmer.

## Code Implementation:

```c
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
```

## Conclusion:
In this assignment, we successfully implemented Embedded C code to control 4 LEDs using an ATmega32 microcontroller, triggered by an external interrupt INT1. Through this project, we gained valuable experience in:

- Configuring GPIO pins and external interrupts on the ATmega32 microcontroller.
- Writing interrupt service routines (ISRs) to handle external events.
- Testing and debugging embedded systems code to ensure proper functionality.
- Understanding the interaction between hardware and software in embedded systems.