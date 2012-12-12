#include <plib.h>
#include "board.h"

extern int rand();

//roll random number from 2-12
//The extra code is an attempt to increase the pseudo randomness
int roll(){
    int i = 0;
    int temp = 0;
    for(i;i<30;i++)
        temp+=(rand()%6+1);
    temp = (temp%6)+1;
    return temp;
}

//determine if you landed on a shoot or ladder
//returning one is a shoot, two a ladder, zero is nothing
int SoL(int pos, int level){
    int SoL = (rand()%20+1);

    //if level is easy, only 10% chance of landing
    //if level is hard, 15% chance of landing
    if (level == 1){
        if(pos > 6 && SoL < 2){
            return 1;
        }
        else if (pos < 43 && SoL > 17){
            return 2;
        }else return 0;
    }else if (level == 2){
        if(pos > 6 && SoL < 4){
            return 1;
        }
        else if (pos < 43 && SoL > 17){
            return 2;
        }else return 0;
    }else return 0;
}

// determine if someone has won
// return 1 if win, 0 if no win, -# if hard level and passed 48
int checkWin(int pos, int level){
    if (pos == 48){
        return 1;
    }else if (pos < 48){
        return 0;
    }else if ((pos > 48) && (level == 1)){
        return 1;
    }else if ((pos > 48) && (level == 2)){
        return (48 - pos);
    }

    return 0;
}

