#include "game.h"
#include "screen.h"
#include "enemy.h"
#include "wing.h"
#include "life.h"
#include "timer.h"
#include "keyboard.h"
#include "timer.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

void initializeGame(int *life, int enemyX[], int enemyY[], int enemyTimers[], Mix_Music *gameTrack) {
    Mix_PlayMusic(gameTrack, -1);
    *life = LIFE;
    initializeEnemies(enemyX, enemyY, enemyTimers);
    screenInit(1);
    keyboardInit();
    timerInit(50);
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

void displayGameOver(Mix_Music *gameTrack, Mix_Music *deathSound) {
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
    Mix_FreeMusic(gameTrack);
    Mix_CloseAudio();
    Mix_PlayMusic(deathSound, 0);
    Mix_CloseAudio();
    screenUpdate();
}

void handleGameOver(Mix_Music *gameTrack, Mix_Music *deathSound) {
    displayGameOver(gameTrack, deathSound);
    while (!keyhit()) { }
}

void cleanUp() {
    keyboardDestroy();
    screenDestroy();
    timerDestroy();
}