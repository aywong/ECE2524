#ifndef BUTTON_H
#define	BUTTON_H

#define BTN1_PORT IOPORT_G
#define BTN1_BIT  0x40

//set the relevant PIC32 ports and pins as digital outputs and inputs
void     initButtons();

//read and write the relevant PIC32 ports and bits.
unsigned getButtonState(unsigned int button);

#endif	/* BUTTON_H */

