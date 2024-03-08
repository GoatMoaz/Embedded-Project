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

