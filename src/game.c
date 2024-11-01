#include "game.h"
#include "screen.h"
#include "enemy.h"
#include "wing.h"
#include "life.h"
#include "timer.h"
#include "keyboard.h"
#include "timer.h"

void initializeGame(int *life, int enemyX[], int enemyY[], int enemyTimers[]) {
    *life = LIFE;
    initializeEnemies(enemyX, enemyY, enemyTimers);
    screenInit(1);
    keyboardInit();
    timerInit(45);
}

void updateGame(int *YPos, int *XPos, int *life, int enemyX[], int enemyY[], int enemyTimers[]) {
    printWing(XPos, YPos);
    printLife(SCRSTARTY, SCRSTARTX, *life);
    screenUpdate();

    if (timerTimeOver() == 1) {
        screenClear();
        screenSetColor(CYAN, DARKGRAY);
        screenDrawBorders();
        updateEnemies(*XPos, *YPos, life, enemyX, enemyY, enemyTimers);
        moveBullets();
    }
}

void displayGameOver() {
    screenGotoxy(SCRSTARTX + 6, SCRSTARTY + 8);
    printf("   _____          __  __ ______    ______      ________ _____  \n");
    screenGotoxy(SCRSTARTX + 6, SCRSTARTY + 9);
    printf("  / ____|   /\\   |  \\/  |  ____|  / __ \\ \\    / /  ____|  __ \\ \n");
    screenGotoxy(SCRSTARTX + 6, SCRSTARTY + 10);
    printf(" | |  __   /  \\  | \\  / | |__    | |  | \\ \\  / /| |__  | |__) |\n");
    screenGotoxy(SCRSTARTX + 6, SCRSTARTY + 11);
    printf(" | | |_ | / /\\ \\ | |\\/| |  __|   | |  | |\\ \\/ / |  __| |  _  / \n");
    screenGotoxy(SCRSTARTX + 6, SCRSTARTY + 12);
    printf(" | |__| |/ ____ \\| |  | | |____  | |__| | \\  /  | |____| | \\ \\ \n");
    screenGotoxy(SCRSTARTX + 6, SCRSTARTY + 13);
    printf("  \\_____/_/    \\_\\_|  |_|______|  \\____/   \\/   |______|_|  \\_\\\n");
    screenGotoxy(SCRSTARTX + 25, SCRSTARTY + 18);
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