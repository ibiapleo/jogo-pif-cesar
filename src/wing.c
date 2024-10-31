#include "wing.h"
#include "screen.h"
#include <string.h>

void printWing(int *x, int *y) {
    screenSetColor(CYAN, DARKGRAY);
    screenGotoxy(*x, *y);

    printf("   __");
    screenGotoxy(*x, *y + 1);
    printf("   \\ \\_____");
    screenGotoxy(*x, *y + 2);
    printf("   [==_____)");
    wingTrail(*x, *y);
    screenGotoxy(*x, *y + 3);
    printf("   /_/");
}

void moveWing(int *command, int *YPos, int *XPos)
{
    screenSetColor(CYAN, DARKGRAY);
    if (*command == 119 && *YPos > MINY + 1){
        *YPos -= 1;
    } else if (*command == 115 && *YPos < MAXY - 4){
        *YPos += 1;
    }

    if (*command == 97 && *XPos > MINX + 3){
        *XPos -= 1;
    } else if (*command == 100 && *XPos < MAXX - 13){
        *XPos += 1;
    }

    screenDrawBorders();
    screenGotoxy(*XPos, *YPos);
    printWing(XPos, YPos);
}

void wingTrail(int x, int y) {
    char trailArray[5] = {'@', '%', '#', '*', '-'};
    for (int i = 0; i < 5; i++) {
        screenGotoxy(x + 2 - i, y + 2);
        printf("%c ", trailArray[i]);
    }
}