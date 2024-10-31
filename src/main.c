#include <string.h>
#include "collision.h"
#include "screen.h"
#include "keyboard.h"
#include "timer.h"
#include "wing.h"
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
    int YPos = 7, XPos = 20;
    int life;

    int enemyX[NUM_ENEMIES], enemyY[NUM_ENEMIES];
    int enemyTimers[NUM_ENEMIES];
    
    initializeGame(&life, enemyX, enemyY, enemyTimers);

    while (ch != 10) {
        if (keyhit()) {
            ch = readch();
            moveWing(&ch, &YPos, &XPos);
            moveWingBullet(&XPos, &YPos, &ch);
        }

        printWing(&XPos, &YPos);
        printLife(SCRSTARTY, SCRSTARTX, life);
        screenUpdate();

        if (timerTimeOver() == 1) {
            screenClear();
            screenSetColor(CYAN, DARKGRAY);
            screenDrawBorders();
            // updateAndPrintEnemies(XPos, YPos, &life, enemyX, enemyY, enemyTimers);
            moveBullets(); 
            
        }

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
