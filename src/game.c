#include "game.h"
#include "screen.h"
#include "enemy.h"
#include "wing.h"
#include "life.h"
#include "score.h"
#include "timer.h"
#include "keyboard.h"
#include "timer.h"
#include "background.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>



void initializeGame(int *life, int enemyX[], int enemyY[], int enemyTimers[], Mix_Music *gameTrack, int minionX[], int minionY[], int minionTimers[]) {
    Mix_PlayMusic(gameTrack, -1);
    *life = LIFE;
    initializeEnemies(enemyX, enemyY, enemyTimers);
    initializeMinions(minionX, minionY, minionTimers);
    initializaStars();
    screenInit(1);
    keyboardInit();
    timerInit(50);
}

void updateGame(int *YPos, int *XPos, int *life, int enemyX[], int enemyY[], int enemyTimers[], int minionX[], int minionY[], int minionTimers[], Score* score) {
    printWing(XPos, YPos);

    printLife(SCRSTARTY, SCRSTARTX, *life);
    printScore(SCRSTARTY, SCRSTARTX, score);
    
    screenUpdate();

    if (timerTimeOver() == 1) {
        screenClear();
        screenSetColor(CYAN, DARKGRAY);
        screenDrawBorders();
        updateEnemies(*XPos, *YPos, life, enemyX, enemyY, enemyTimers);
        updateMinions(*XPos, *YPos, life, minionX, minionY, minionTimers, score);
        moveStars();
        printStars();

        moveBullets();
    }
}

void displayGameOver(Mix_Music *gameTrack, Mix_Music *deathSound, Score* score) {
    screenGotoxy(SCRSTARTX + 15, SCRSTARTY + 11);
    printf("   _____          __  __ ______    ______      ________ _____  \n");
    screenGotoxy(SCRSTARTX + 15, SCRSTARTY + 12);
    printf("  / ____|   /\\   |  \\/  |  ____|  / __ \\ \\    / /  ____|  __ \\ \n");
    screenGotoxy(SCRSTARTX + 15, SCRSTARTY + 13);
    printf(" | |  __   /  \\  | \\  / | |__    | |  | \\ \\  / /| |__  | |__) |\n");
    screenGotoxy(SCRSTARTX + 15, SCRSTARTY + 14);
    printf(" | | |_ | / /\\ \\ | |\\/| |  __|   | |  | |\\ \\/ / |  __| |  _  / \n");
    screenGotoxy(SCRSTARTX + 15, SCRSTARTY + 15);
    printf(" | |__| |/ ____ \\| |  | | |____  | |__| | \\  /  | |____| | \\ \\ \n");
    screenGotoxy(SCRSTARTX + 15, SCRSTARTY + 16);
    printf("  \\_____/_/    \\_\\_|  |_|______|  \\____/   \\/   |______|_|  \\_\\\n");
    screenGotoxy(SCRSTARTX + 35, SCRSTARTY + 21);
    printf(" Press any key to exit...\n");

    screenGotoxy(SCRSTARTX + 38, SCRSTARTY + 26);
    screenSetColor(YELLOW, BLACK);
    printf("Sua pontuação foi: %d", score->points);
    screenUpdate();
}

void handleGameOver(Mix_Music *gameTrack, Mix_Music *deathSound, Score* score) {
    Mix_HaltMusic();
    Mix_PlayMusic(deathSound, 0);
    displayGameOver(gameTrack, deathSound, score);
    while (!keyhit()) { }
}

void cleanUp(Mix_Music **menuMusic, Mix_Music **gameTrack, Mix_Music **deathSound, Mix_Chunk **pewSound) {
    Mix_FreeMusic(*menuMusic);
    Mix_FreeMusic(*gameTrack);
    Mix_FreeMusic(*deathSound);
    Mix_FreeChunk(*pewSound);
    Mix_CloseAudio();
    keyboardDestroy();
    screenDestroy();
    timerDestroy();
}