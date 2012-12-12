#include <plib.h>
#include "Button.h"

void initButtons() {
  //BTN1 is connected to I/O Port G, bits
  PORTSetPinsDigitalIn(BTN1_PORT, BTN1_BIT);
}

unsigned getButtonState(unsigned int button) {
    unsigned int buttonState = 0;

    buttonState = PORTReadBits(IOPORT_G, button);
    return buttonState;
}

