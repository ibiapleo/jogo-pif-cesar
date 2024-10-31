#include "enemy.h"
#include "timer.h"
#include <stdio.h>
#include "screen.h"
#include <stdlib.h> 

void printEnemy(int x, int y) {
    if (x >= 0 && y >= 0 && x < MAXX && y < MAXY) {
        screenGotoxy(x, y);
        printf("  ☠  ");
    }
}

void moveEnemy(int *enemyX, int *enemyY) {
    if (*enemyX >= 0) {
        printEnemy(*enemyX, *enemyY);
    }

    *enemyX -= 1;
    if (*enemyX < 0) {
        *enemyX = MAXX; 
        *enemyY = rand() % (MAXY - 4) + 1; 
    }
}

void moveMinion(int *XPos, int *YPos) {

    int timediff = getTimeDiff();




    int newPos = (randomNumber() % 8);
    if (timediff > 50){

        screenGotoxy(*XPos + 1, *YPos);
        printf("          \n");
        screenGotoxy(*XPos, *YPos + 1);
        printf("          \n");

        if (newPos == 0 && *YPos > MINY) {
            *YPos -= 1;
        } else if (newPos == 1 && *YPos > MINY && *XPos < MAXX) {
            *XPos += 1;
            *YPos -= 1;
        } else if (newPos == 2 && *XPos < MAXX)  {
            *XPos += 1;
        } else if (newPos == 3 && *YPos < MAXY && *XPos < MAXX) {
            *XPos += 1;
            *YPos += 1;
        } else if (newPos == 4 && *YPos < MAXY)  {
            *YPos += 1;
        } else if (newPos == 5 && *YPos < MAXY && *XPos > MINX) {
            *XPos -= 1;
            *YPos += 1;
        } else if (newPos == 6 && *XPos > MINX) {
            *XPos -= 1;
        } else if (newPos == 7 && *YPos > MINY && *XPos > MINX) {
            *XPos -= 1;
            *YPos -= 1;
        }
        timediff = getTimeDiff();
    }
}

void printMinion(int *x, int *y) {
    screenSetColor(GREEN, DARKGRAY);

    
    screenGotoxy(*x + 1, *y);
    printf("_/@\\_\n");
    screenGotoxy(*x, *y + 1);
    printf("|\\WVW/|\n");
    
    screenUpdate();
}