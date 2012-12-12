#include <plib.h>

#include "PmodOLED.h"
#include "OledChar.h"
#include "OledGrph.h"
#include "delay.h"
#include "Button.h"
#include "LED.h"
#include "Rotary.h"
#include "board.h"
#include "draw.h"

#pragma config FNOSC		= PRIPLL	// Oscillator selection
#pragma config POSCMOD		= XT		// Primary oscillator mode
#pragma config FPLLIDIV 	= DIV_2		// PLL input divider
#pragma config FPLLMUL		= MUL_20	// PLL multiplier
#pragma config FPLLODIV 	= DIV_1		// PLL output divider
#pragma config FPBDIV		= DIV_8		// Peripheral bus clock divider
#pragma config FSOSCEN		= OFF		// Secondary oscillator enable

#pragma config ICESEL       = ICS_PGx1  // ICE/ICD Comm Channel Select
#pragma config DEBUG        = OFF       // Debugger Disabled for Starter Kit

unsigned BTN1, button;
int  RotaryPos = 1, state = 0, step = 0, turn = 4, playNum, level, players[4], rollNum, SoLNum, win;
char pos[3];

void __ISR(_TIMER_2_VECTOR) Time2Handler( void) { //Int handler for rotary switch
    step = getRotaryPos();
    RotaryPos = step + RotaryPos;

    if (RotaryPos == 5) RotaryPos = 1;
    else if (RotaryPos == 0)  RotaryPos = 4;
    
    button = getRotaryState(BTN_BIT);
    BTN1 = getButtonState(BTN1_BIT);

   INTClearFlag(INT_T2);
}

void Timer2Init() { //Initialize the timer
  OpenTimer2(T2_ON          |
             T2_SOURCE_INT  |
             T2_PS_1_16,
             625);  // freq = 10M/16/625 = 1KHz

  ConfigIntTimer2(T2_INT_ON|T2_INT_PRIOR_1);
  INTConfigureSystem(INT_SYSTEM_CONFIG_MULT_VECTOR);
  INTEnableInterrupts();
}

int main() {
    DelayInit();
    OledInit();
    Timer2Init();  //Enable interrupts
    initRotary();
    initLEDs();
    initButtons();

    // turn off all LEDs
    clearAll();
    
    while (1) { //Loop for Finite state machine (main game operation)
        if(state == 0){ //Choose number of players
            DrawState(state);
            while(state == 0){
                DrawNum(RotaryPos);

                if (BTN1){
                    state = 1;
                    playNum = RotaryPos;
                    DelayMs(500);
                }
            }
            state = 1;
            RotaryPos = 1;
            
            DrawState(state);
            while(state == 1){ //Difficulty select
                if (RotaryPos == 3) RotaryPos = 1;
                if (RotaryPos == 4) RotaryPos = 2;

                DrawNum(RotaryPos);

                if(BTN1){
                    state = 2;
                    level = RotaryPos;
                }
            }
        }
        
        state = 2;
        RotaryPos = 1;

        if(state == 2){ //
            int i;
            for(i = 0; i < 4; i++){
                if (i < playNum) players[i] = 0;
                else if (i >= playNum) players[i] = -1;
            }
            ClearGraphArea(1);
            DrawPlayerPos(players[0],players[1],players[2],players[3]);

            while(state == 2){ //Players turn state
                turn = 1 + turn;
                if (turn >= playNum) turn = 0;

                if (turn == 0){ //Player 1 turn
                    clearAll();
                    setLEDstate(LD1, 1);
                    DrawRoll(turn+1);

                    while(!BTN1);
                    DelayMs(500);

                    rollNum = roll();
                    players[turn] = players[turn] + rollNum;
                    DrawMove(rollNum, players[turn]);
                    DrawPlayerPos(players[0],players[1],players[2],players[3]);

                    while(!BTN1);
                    DelayMs(500);

                    win = checkWin(players[turn], level);
                    if(win == 1){
                        DrawWin(turn+1);
                        while(!BTN1);
                        state = 0;
                    }else if(win < 0){
                        players[turn] = 48 + win;
                        DrawOver(win, players[turn]);
                        DrawPlayerPos(players[0],players[1],players[2],players[3]);
                        while(!BTN1);
                    }

                    SoLNum = SoL(players[turn], level);
                    if(SoLNum == 1){
                        rollNum = -(roll());
                        players[turn] = players[turn] + rollNum;
                        DrawSoL(SoLNum, rollNum, players[turn]);
                        DrawPlayerPos(players[0],players[1],players[2],players[3]);

                        while(!BTN1);
                        DelayMs(500);
                    }else if(SoLNum == 2){
                        rollNum = (roll());
                        players[turn] = players[turn] + rollNum;
                        DrawSoL(SoLNum, rollNum, players[turn]);
                        DrawPlayerPos(players[0],players[1],players[2],players[3]);
                        while(!BTN1);
                        DelayMs(500);
                    }

                } else if (turn == 1){ //Player 2 turn
                    clearAll();
                    setLEDstate(LD2, 1);
                    DrawRoll(turn+1);

                    while(!BTN1);
                    DelayMs(500);

                    rollNum = roll();
                    players[turn] = players[turn] + rollNum;
                    DrawMove(rollNum, players[turn]);
                    DrawPlayerPos(players[0],players[1],players[2],players[3]);

                    while(!BTN1);
                    DelayMs(500);

                    win = checkWin(players[turn], level);
                    if(win == 1){
                        DrawWin(turn+1);
                        while(!BTN1);
                        state = 0;
                    }else if(win < 0){
                        players[turn] = 48 + win;
                        DrawOver(win, players[turn]);
                        DrawPlayerPos(players[0],players[1],players[2],players[3]);
                        while(!BTN1);
                    }

                    SoLNum = SoL(players[turn], level);
                    if(SoLNum == 1){
                        rollNum = -(roll());
                        players[turn] = players[turn] + rollNum;
                        DrawSoL(SoLNum, rollNum, players[turn]);
                        DrawPlayerPos(players[0],players[1],players[2],players[3]);

                        while(!BTN1);
                        DelayMs(500);
                    }else if(SoLNum == 2){
                        rollNum = (roll());
                        players[turn] = players[turn] + rollNum;
                        DrawSoL(SoLNum, rollNum, players[turn]);
                        DrawPlayerPos(players[0],players[1],players[2],players[3]);
                        while(!BTN1);
                        DelayMs(500);
                    }

                } else if (turn == 2){ //Player 3 turn
                    clearAll();
                    setLEDstate(LD3, 1);
                    DrawRoll(turn+1);

                    while(!BTN1);
                    DelayMs(500);

                    rollNum = roll();
                    players[turn] = players[turn] + rollNum;
                    DrawMove(rollNum, players[turn]);
                    DrawPlayerPos(players[0],players[1],players[2],players[3]);

                    while(!BTN1);
                    DelayMs(500);

                    win = checkWin(players[turn], level);
                    if(win == 1){
                        DrawWin(turn+1);
                        while(!BTN1);
                        state = 0;
                    }else if(win < 0){
                        players[turn] = 48 + win;
                        DrawOver(win, players[turn]);
                        DrawPlayerPos(players[0],players[1],players[2],players[3]);
                        while(!BTN1);
                    }

                    SoLNum = SoL(players[turn], level);
                    if(SoLNum == 1){
                        rollNum = -(roll());
                        players[turn] = players[turn] + rollNum;
                        DrawSoL(SoLNum, rollNum, players[turn]);
                        DrawPlayerPos(players[0],players[1],players[2],players[3]);

                        while(!BTN1);
                        DelayMs(500);
                    }else if(SoLNum == 2){
                        rollNum = (roll());
                        players[turn] = players[turn] + rollNum;
                        DrawSoL(SoLNum, rollNum, players[turn]);
                        DrawPlayerPos(players[0],players[1],players[2],players[3]);
                        while(!BTN1);
                        DelayMs(500);
                    }

                } else if (turn == 3){ //Player 4 turn
                    clearAll();
                    setLEDstate(LD4, 1);
                    DrawRoll(turn+1);

                    while(!BTN1);
                    DelayMs(500);

                    rollNum = roll();
                    players[turn] = players[turn] + rollNum;
                    DrawMove(rollNum, players[turn]);
                    DrawPlayerPos(players[0],players[1],players[2],players[3]);

                    while(!BTN1);
                    DelayMs(500);

                    win = checkWin(players[turn], level);
                    if(win == 1){
                        DrawWin(turn+1);
                        while(!BTN1);
                        state = 0;
                    }else if(win < 0){
                        players[turn] = 48 + win;
                        DrawOver(win, players[turn]);
                        DrawPlayerPos(players[0],players[1],players[2],players[3]);
                        while(!BTN1);
                    }

                    SoLNum = SoL(players[turn], level);
                    if(SoLNum == 1){
                        rollNum = -(roll());
                        players[turn] = players[turn] + rollNum;
                        DrawSoL(SoLNum, rollNum, players[turn]);
                        DrawPlayerPos(players[0],players[1],players[2],players[3]);

                        while(!BTN1);
                        DelayMs(500);
                    }else if(SoLNum == 2){
                        rollNum = (roll());
                        players[turn] = players[turn] + rollNum;
                        DrawSoL(SoLNum, rollNum, players[turn]);
                        DrawPlayerPos(players[0],players[1],players[2],players[3]);
                        while(!BTN1);
                        DelayMs(500);
                    }

                }

            }
        }


    }
    return 0;
}

