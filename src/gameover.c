#include "gameover.h"
#include "screen.h"
#include <stdio.h>
#include "keyboard.h"

void displayGameOver()
{
    screenGotoxy(SCRSTARTX + 29, SCRSTARTY + 11);
    printf("   GAME OVER   \n");
    screenGotoxy(SCRSTARTX + 25, SCRSTARTY + 12);
    printf(" Press any key to exit...\n");
    screenUpdate();
}


void handleGameOver() {
    displayGameOver();
    while (!keyhit()) { }
}