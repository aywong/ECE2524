#ifndef ROTARY_H
#define	ROTARY_H

#define ROT_PORT  IOPORT_B
#define A_BIT     BIT_7
#define B_BIT     BIT_8
#define BTN_BIT   BIT_9

//set the relevant PIC32 ports and pins as digital outputs and inputs
void     initRotary();

//read and write the relevant PIC32 ports and bits.
unsigned getRotaryState(unsigned int rotary);

int getRotaryPos();

#endif	/* ROTARY_H */

