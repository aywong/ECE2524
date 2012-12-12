#include <plib.h>
#include "draw.h"

// Clear the OLED area from pixel (0,0) to pixel (79,31)
// or from pixel (80,0) to pixel (127,31)
void ClearGraphArea(int area){
    if(area == 0){
        OledMoveTo(0, 0);
        OledFillRect(54, 31);
    }
    if(area == 1){
        OledMoveTo(55, 0);
        OledFillRect(127, 31);
    }

    OledUpdate();
}
void DrawOne(){
    OledMoveTo(16, 5);
    OledLineTo(22, 5);
    OledLineTo(22, 21);
    OledLineTo(26, 21);
    OledLineTo(26, 25);
    OledLineTo(14, 25);
    OledLineTo(14, 21);
    OledLineTo(18, 21);
    OledLineTo(18, 8);
    OledLineTo(16, 8);
    OledLineTo(16, 5);
}
void DrawTwo(){
    OledMoveTo(14, 5);
    OledLineTo(26, 5);
    OledLineTo(26, 17);
    OledLineTo(18, 17);
    OledLineTo(18, 21);
    OledLineTo(26, 21);
    OledLineTo(26, 25);
    OledLineTo(14, 25);
    OledLineTo(14, 13);
    OledLineTo(22, 13);
    OledLineTo(22, 9);
    OledLineTo(14, 9);
    OledLineTo(14, 5);
}
void DrawThree(){
    OledMoveTo(14, 5);
    OledLineTo(26, 5);
    OledLineTo(26, 25);
    OledLineTo(14, 25);
    OledLineTo(14, 21);
    OledLineTo(22, 21);
    OledLineTo(22, 17);
    OledLineTo(14, 17);
    OledLineTo(14, 13);
    OledLineTo(22, 13);
    OledLineTo(22, 9);
    OledLineTo(14, 9);
    OledLineTo(14, 5);
}
void DrawFour(){
    OledMoveTo(14, 5);
    OledLineTo(18, 5);
    OledLineTo(18, 15);
    OledLineTo(22, 15);
    OledLineTo(22, 5);
    OledLineTo(26, 5);
    OledLineTo(26, 25);
    OledLineTo(22, 25);
    OledLineTo(22, 19);
    OledLineTo(14, 19);
    OledLineTo(14, 5);
}
//Draws the labels X, Y and Z
void DrawState(int state){
    ClearGraphArea(1);

    if (state == 0){
        OledSetCursor(7, 0);
        OledPutString("Select  ");
        OledSetCursor(7, 1);
        OledPutString("number  ");
        OledSetCursor(7, 2);
        OledPutString("   of   ");
        OledSetCursor(7, 3);
        OledPutString("  users ");
        OledUpdate();
    }else if (state == 1){
        OledSetCursor(7, 0);
        OledPutString("Select   ");
        OledSetCursor(7, 1);
        OledPutString("level   ");
        OledSetCursor(7, 2);
        OledPutString(" 1:Easy  ");
        OledSetCursor(7, 3);
        OledPutString(" 2:Hard  ");
        OledUpdate();
    }
}

//Draws the labels X, Y and Z
void DrawPlayerPos(unsigned w, unsigned x, unsigned y, unsigned z){
    char buf[4];

    OledSetCursor(0, 0);
    OledPutString("P1:   ");
    OledSetCursor(0, 1);
    OledPutString("P2:   ");
    OledSetCursor(0, 2);
    OledPutString("P3:   ");
    OledSetCursor(0, 3);
    OledPutString("P4:   ");
    OledUpdate();

    sprintf(buf, "%d", w);
    OledSetCursor(3, 0);
    OledPutString(buf);

    sprintf(buf, "%d", x);
    OledSetCursor(3, 1);
    OledPutString(buf);

    sprintf(buf, "%d", y);
    OledSetCursor(3, 2);
    OledPutString(buf);

    sprintf(buf, "%d", z);
    OledSetCursor(3, 3);
    OledPutString(buf);
    OledUpdate();
}

// draw numbers (calls the other methods to draw)
void DrawNum(int num){
    ClearGraphArea(0);

    if(num == 1) DrawOne();
    else if(num == 2) DrawTwo();
    else if (num == 3) DrawThree();
    else if (num == 4) DrawFour();

    OledUpdate();
}

void DrawRoll(int num){ //Draws the roll
    ClearGraphArea(1);
    char buf[4];

    OledSetCursor(7, 0);
    OledPutString(" user   ");
    OledSetCursor(7, 1);
    OledPutString("  roll  ");
    OledSetCursor(7, 2);
    OledPutString("   the  ");
    OledSetCursor(7, 3);
    OledPutString("   die  ");
    OledUpdate();

    sprintf(buf, "%d", num);
    OledSetCursor(13, 0);
    OledPutString(buf);
}
void DrawMove(int roll, int pos){
    ClearGraphArea(1);
    char buf[4];

    OledSetCursor(7, 0);
    OledPutString("rolled: ");
    OledSetCursor(7, 1);
    OledPutString("        ");
    OledSetCursor(7, 2);
    OledPutString("Move to:");
    OledSetCursor(7, 3);
    OledPutString("        ");
    OledUpdate();

    sprintf(buf, "%d", roll);
    OledSetCursor(10, 1);
    OledPutString(buf);

    sprintf(buf, "%d", pos);
    OledSetCursor(10, 3);
    OledPutString(buf);
}

void DrawSoL(int SL, int roll, int pos){ //Draws message about a shoot or ladder
    ClearGraphArea(1);
    char buf[4];

    int old = pos - roll;

    if(SL == 1){
        OledSetCursor(7, 0);
        OledPutString(" CHUTE! ");
    }else if(SL == 2){
        OledSetCursor(7, 0);
        OledPutString("LADDER! ");
    }

    OledSetCursor(7, 1);
    OledPutString("Move:   ");
    OledSetCursor(7, 2);
    OledPutString("From:   ");
    OledSetCursor(7, 3);
    OledPutString("To:     ");
    OledUpdate();

    sprintf(buf, "%d", roll);
    OledSetCursor(13, 1);
    OledPutString(buf);

    sprintf(buf, "%d", old);
    OledSetCursor(13, 2);
    OledPutString(buf);

    sprintf(buf, "%d", pos);
    OledSetCursor(13, 3);
    OledPutString(buf);
}
void DrawOver(int over, int pos){
ClearGraphArea(1);
    char buf[4];

    OledSetCursor(7, 0);
    OledPutString("  spaces");
    OledSetCursor(7, 1);
    OledPutString("  over  ");
    OledSetCursor(7, 2);
    OledPutString("  Move  ");
    OledSetCursor(7, 3);
    OledPutString("to:     ");
    OledUpdate();

    sprintf(buf, "%d", (over*-1));
    OledSetCursor(7, 0);
    OledPutString(buf);   
    
    sprintf(buf, "%d", pos);
    OledSetCursor(12, 3);
    OledPutString(buf); 
}
void DrawWin(int num){ //Draws the winning message
    ClearGraphArea(1);
    char buf[4];

    OledSetCursor(7, 0);
    OledPutString(" user   ");
    OledSetCursor(7, 1);
    OledPutString("  WINS  ");
    OledSetCursor(7, 2);
    OledPutString("   the  ");
    OledSetCursor(7, 3);
    OledPutString("  game! ");
    OledUpdate();

    sprintf(buf, "%d", num);
    OledSetCursor(13, 0);
    OledPutString(buf);    
}




