# Embedded C Assignment 1: LED Control with Push Buttons

## Objective:
The objective of this assignment is to control an LED using two push buttons connected to an ATmega32 microcontroller.

## Requirements:
- Utilize an ATmega32 microcontroller.
- Connect two push buttons to pins 0 and 1 in PORTA.
- Connect an LED to pin 2 in PORTA.
- When switch 1 is pressed, turn on the LED.
- When switch 2 is pressed, turn off the LED.

## Implementation Details:
1. **Hardware Setup**:
   - Connect two push buttons to pins 0 and 1 in PORTA.
   - Connect an LED to pin 2 in PORTA.

2. **Software Implementation**:
   - Initialize the ports:
     - Set switch pins as input.
     - Set LED pin as output.

3. **Main Program Logic**:
   - Continuously monitor the status of the switches.
   - If switch 1 is pressed, turn on the LED.
   - If switch 2 is pressed, turn off the LED.
   
## Code Implementation:
```c
#include "bit_math.h" // for bit manipulation
#include "atmga32.h" // for all external memory
 
void initalize(){
	DDRA = 0xfc;
	PORTA = 0xf3;
}

void display(){
	if(!get_bit(PINA , 0))
	set_bit(PORTA , 2);
	if (!get_bit(PINA , 1))
	clr_bit(PORTA , 2);
}
int main(void)
{
	initalize();
	while(1){
		display();
	}
}
```

## Conclusion:
This assignment provides a practical example of interfacing push buttons and LEDs with an ATmega32 microcontroller using embedded C programming. By understanding and implementing this code, students can gain insights into basic embedded systems development and hardware-software interaction.
