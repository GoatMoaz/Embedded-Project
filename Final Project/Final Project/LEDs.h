
#ifndef LEDS_H_
#define LEDS_H_

#include "bit_math.h"
#include "atmga32.h"

void leds_init(void);

void display_on_leds(unsigned char number); // Display the binary representation of the number


#endif 