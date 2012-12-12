#include <plib.h>
#include "LED.h"

void initLEDs() {
    //LEDs are connected to bits 12-15 of I/O Port G
    PORTSetPinsDigitalOut (IOPORT_G, LD1);
    PORTSetPinsDigitalOut (IOPORT_G, LD2);
    PORTSetPinsDigitalOut (IOPORT_G, LD3);
    PORTSetPinsDigitalOut (IOPORT_G, LD4);
}

void setLEDstate(unsigned int led, unsigned int state) {
    //if the state should be on (1) Turn on the LED
    if (state){
        PORTSetBits(IOPORT_G, led);
    }
    // else clear the LEDs
    else
        PORTClearBits(IOPORT_G, led);
}
void clearAll(){
    PORTClearBits(IOPORT_G, LD1);
    PORTClearBits(IOPORT_G, LD2);
    PORTClearBits(IOPORT_G, LD3);
    PORTClearBits(IOPORT_G, LD4);
}