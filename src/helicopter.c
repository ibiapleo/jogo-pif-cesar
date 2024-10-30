#include "helicopter.h"
#include "screen.h"
#include <string.h>

void printHelicopter(int *x, int *y) {
    screenSetColor(CYAN, DARKGRAY);
    screenGotoxy(*x, *y);
    printf(" __   ______\n");
    screenGotoxy(*x, *y + 1);
    printf(" |X\\_.-╨─｡_\n");
    screenGotoxy(*x, *y + 2);
    printf(" ─´‾‾‷\\  °★¯]─\n");
    screenGotoxy(*x, *y + 3);
    printf("         ‾‾‾‾\n");
}

void moveHelicopter(int *command, int *YPos, int *XPos) 
{
    screenSetColor(CYAN, DARKGRAY);
    if (*command == 119 && *YPos > MINY + 1){
        *YPos -= 1;
    } else if (*command == 115 && *YPos < MAXY - 4){
        *YPos += 1;
    }
    
    if (*command == 97 && *XPos > MINX + 1){
        *XPos -= 1;
    } else if (*command == 100 && *XPos < MAXX - 15){
        *XPos += 1;
    }

    screenDrawBorders();
    screenGotoxy(*XPos, *YPos);
    printHelicopter(XPos, YPos);
    screenUpdate();
}