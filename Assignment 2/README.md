# Embedded C Assignment 2: 7-Segment Display Control with Keypad

## Objective:
The objective of this assignment is to control a 7-segment display using a keypad interfaced with an ATmega32 microcontroller.

## Requirements:
- Utilize an ATmega32 microcontroller.
- Connect a 7-segment display to PORTA.
- Connect a 4x4 keypad to PORTC and PORTD.
- Display digits 0-9 on the 7-segment display based on the keypad input.

## Implementation Details:
1. **Hardware Setup**:
   - Connect a 7-segment display to PORTA. Ensure proper connection of segments and common cathode/anode pins.
   - Connect a 4x4 keypad to PORTC and PORTD. Assign appropriate pins for row and column connections.

2. **Software Implementation**:
   - Initialize the ports:
     - Set keypad columns as input and enable pull-up resistors.
     - Set 7-segment display pins as output.

3. **Main Program Logic**:
   - Continuously scan the keypad for input.
   - Map the keypad input to the corresponding digit to be displayed on the 7-segment display.
   - Display the mapped digit on the 7-segment display.

## Code Implementation:
```c
#include "atmga32.h"
#include "keypad.h"
#include "bit_math.h"

int main(void)
{
    seven_segment_init();
	keypad_init();
	while (1) 
    {
		unsigned char value=keypad_get_value();
		if (value!=0xff)
		{
			display_on_seven_seg(value-'0');
		}
    }
}
```
## Conclusion:
This assignment demonstrates the implementation of a simple keypad interface to control a 7-segment display using an ATmega32 microcontroller and embedded C programming. Understanding and implementing this code provides students with essential skills in interfacing different input devices and output peripherals in embedded systems.
