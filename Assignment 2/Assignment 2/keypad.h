#ifndef KEY_PAD_H_
#define KEY_PAD_H_

#include "atmga32.h"
#include "bit_math.h"

void keypad_init(void);
unsigned char keypad_get_value(void);
void seven_segment_init(void);
void display_on_seven_seg(int num);

#endif /* KEY_PAD_H_ */