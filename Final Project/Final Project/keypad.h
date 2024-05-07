#ifndef KEY_PAD_H_
#define KEY_PAD_H_

#include "atmga32.h"
#include "bit_math.h"
#include <util/delay.h>

void keypad_init(void); // Initialize Keypad

unsigned char keypad_get_value(void); // Retrieve The input's Value

#endif 