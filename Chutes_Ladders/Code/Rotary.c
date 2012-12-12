#include <plib.h>
#include "Rotary.h"

void initRotary() {
  PORTSetPinsDigitalIn(ROT_PORT, A_BIT);
  PORTSetPinsDigitalIn(ROT_PORT, B_BIT);
  PORTSetPinsDigitalIn(ROT_PORT, BTN_BIT);
}

unsigned getRotaryState(unsigned int rotary) {
    unsigned int rotaryState = 0;

    rotaryState = PORTReadBits(ROT_PORT, rotary);
    return rotaryState;
}
int getRotaryPos(){
    unsigned int encoderSignals;
    unsigned int encoderMask = BIT_10| BIT_9|BIT_8|BIT_7;
    static unsigned int Q1, Q2;
    unsigned int chanA, chanB;
    unsigned previous_q1,previous_q2;

    previous_q1 = Q1;
    previous_q2 = Q2;

    encoderSignals = PORTRead(IOPORT_B) & encoderMask;
    chanA = (encoderSignals >> 7) &0x1 ;
    chanB = (encoderSignals >> 8) &0x1 ;

    if (chanB==1 && chanA==1)           //Accounts for debouncing
        Q1= 0;
    else if (chanB==1 && chanA==0)
        Q2 = 0;
    else if (chanB==0 && chanA==1)
        Q2 = 1;
    else if (chanB==0 && chanA == 0)
        Q1 = 1;

    if ((previous_q1==0) && (Q1==1))
    {
        if (Q2 == 1)
            return 1;                  // returns a -1 if turned counter clockwise
        if(Q2==0)
            return -1;                   // returns a 01 if turned clockwise
    }
    return 0;
}
