#include <string.h>
#include "collision.h"
#include "screen.h"
#include "keyboard.h"
#include "timer.h"
#include "helicopter.h"
#include "life.h"
#include "enemy.h"
#include "gameover.h"
#include <stdlib.h>
#include <stdio.h>

void initializeGame(int *life, int enemyX[], int enemyY[], int enemyTimers[]) {
    *life = LIFE;
    initializeEnemies(enemyX, enemyY, enemyTimers);
    screenInit(1);
    keyboardInit();
    timerInit(70);
}

void updateAndPrintEnemies(int XPos, int YPos, int *life, int enemyX[], int enemyY[], int enemyTimers[]) {
    for (int i = 0; i < NUM_ENEMIES; i++) {
        if (enemyTimers[i] > 0) {
            enemyTimers[i]--;
        } else {
            moveEnemy(&enemyX[i], &enemyY[i]);
            if (checkCollision(XPos, YPos, enemyX[i], enemyY[i])) {
                clearEnemy(enemyX[i], enemyY[i]);
                (*life)--;
                enemyX[i] = MAXX;
                enemyY[i] = rand() % (MAXY - 4) + 1;
                enemyTimers[i] = rand() % 50 + 20;
            } else {
                printEnemy(enemyX[i], enemyY[i]);
            }

            if (enemyX[i] < 0) {
                enemyX[i] = MAXX;
                enemyY[i] = rand() % (MAXY - 4) + 1;
                enemyTimers[i] = rand() % 50 + 20;
            }
        }
    }
    screenUpdate();
}

int main() {
    static int ch = 0;
    int YPos = 20, XPos = 20;
    int life, isPlaying = 0, selectedOption = 0;
    int enemyX[NUM_ENEMIES], enemyY[NUM_ENEMIES], enemyTimers[NUM_ENEMIES];
    int minionX[NUM_MINIONS], minionY[NUM_MINIONS], minionTimers[NUM_MINIONS];

    keyboardInit();
    screenInit(1);
    //Mix_PlayMusic(backgroundMusic, -1);
    
    while (1) {
        if (isPlaying == 0) {
            showMainMenu(selectedOption);
            ch = readch();
            handleMenuInput(ch, &selectedOption, &isPlaying, &life, enemyX, enemyY, enemyTimers, minionX, minionY, minionTimers);
        } else {
            if (keyhit()) {
                ch = readch();
                moveWing(&ch, &YPos, &XPos);
                moveWingBullet(&XPos, &YPos, &ch);
            }

            updateGame(&YPos, &XPos, &life, enemyX, enemyY, enemyTimers, minionX, minionY, minionTimers);

        if (life <= 0) {
            handleGameOver();
            break;
        }
    }

    keyboardDestroy();
    screenDestroy();
    timerDestroy();
    return 0;
}
