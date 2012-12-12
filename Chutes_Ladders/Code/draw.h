#ifndef DRAW_H
#define	DRAW_H

void ClearGraphArea(int area); // Clear the OLED area from pixel (0,0) to pixel (79,31)
void DrawOne(); //Draws a 1
void DrawTwo(); //Draws a 2
void DrawThree(); //Draws a 3
void DrawFour(); //Draws a 4

//Draws the first two steps
void DrawState(int state);

//Draws the player positions
void DrawPlayerPos(unsigned w, unsigned x, unsigned y, unsigned z);

// draw numbers (calls the other methods to draw)
void DrawNum(int num);

void DrawRoll(int num);
void DrawMove(int roll, int pos);
void DrawSoL(int SL, int roll, int pos);
void DrawOver(int over, int pos);
void DrawWin(int num);

#endif	/* DRAW_H */

