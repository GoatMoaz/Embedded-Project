
#ifndef UNTITLED1_INC_H
#define UNTITLED1_INC_H

#define set_bit(reg,bit) (reg|=(1<<bit))
#define clr_bit(reg,bit) (reg&=~(1<<bit))
#define toggle_bit(reg,bit) (reg^=(1<<bit))
#define get_bit(reg,bit) ((reg>>bit)&(0x01))

#endif //UNTITLED1_INC_H
