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

