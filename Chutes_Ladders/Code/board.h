#ifndef BOARD_H
#define	BOARD_H

#define BTN1_PORT IOPORT_G
#define BTN1_BIT  0x40

//roll random number from 1-6
int roll();

//determine if you landed on a shoot or ladder
int SoL(int pos, int level);

//determine if someone has won
int checkWin(int pos, int level);


#endif	/* BOARD_H */

