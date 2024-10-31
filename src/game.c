#include "game.h"
#include "screen.h"
#include "enemy.h"
#include "helicopter.h"
#include "life.h"
#include "timer.h"
#include "keyboard.h"
#include "timer.h"

void initializeGame(int *life, int enemyX[], int enemyY[], int enemyTimers[]) {
    *life = LIFE;
    initializeEnemies(enemyX, enemyY, enemyTimers);
    screenInit(1);
    keyboardInit();
    timerInit(70);
}

void updateGame(int *YPos, int *XPos, int *life, int enemyX[], int enemyY[], int enemyTimers[]) {
    printHelicopter(XPos, YPos);
    printLife(SCRSTARTY, SCRSTARTX, *life);
    screenUpdate();

    if (timerTimeOver() == 1) {
        screenClear();
        screenSetColor(CYAN, DARKGRAY);
        screenDrawBorders();
        updateEnemies(*XPos, *YPos, life, enemyX, enemyY, enemyTimers);
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