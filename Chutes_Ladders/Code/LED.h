#ifndef LED_H
#define	LED_H

#define LD1 BIT_12    // LED 1
#define LD2 BIT_13    // LED 1
#define LD3 BIT_14    // LED 1
#define LD4 BIT_15    // LED 1

//set the relevant PIC32 ports and pins as digital outputs and inputs
void initLEDs();

//read and write the relevant PIC32 ports and bits.
void setLEDState(unsigned int led, unsigned int state);

//clear all LEDs
void clearAll();

#endif	/* LED_H */

