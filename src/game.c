#include "game.h"
#include "screen.h"
#include "enemy.h"
#include "wing.h"
#include "life.h"
#include "timer.h"
#include "keyboard.h"
#include "timer.h"
#include "background.h"

void initializeGame(int *life, int enemyX[], int enemyY[], int enemyTimers[], int minionX[], int minionY[], int minionTimers[]) {
    *life = LIFE;
    initializeEnemies(enemyX, enemyY, enemyTimers);
    initializeMinions(minionX, minionY, minionTimers);
    initializaStars();
    screenInit(1);
    keyboardInit();
    timerInit(70);
}

void updateGame(int *YPos, int *XPos, int *life, int enemyX[], int enemyY[], int enemyTimers[], int minionX[], int minionY[], int minionTimers[]) {
    printWing(XPos, YPos);


    printLife(SCRSTARTY, SCRSTARTX, *life);
    screenUpdate();


    if (timerTimeOver() == 1) {
        screenClear();
        screenSetColor(CYAN, DARKGRAY);
        screenDrawBorders();
        updateEnemies(*XPos, *YPos, life, enemyX, enemyY, enemyTimers);
        updateMinions(*XPos, *YPos, life, minionX, minionY, minionTimers);
        moveStars();
        printStars();

        moveBullets();
    }
}

void displayGameOver() {
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

void cleanUp() {
    keyboardDestroy();
    screenDestroy();
    timerDestroy();
}