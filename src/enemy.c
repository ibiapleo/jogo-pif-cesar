#include "enemy.h"
#include "timer.h"
#include <stdio.h>
#include "screen.h"
#include <stdlib.h> 
#include "collision.h"
#include <sys/time.h>
#include "bullet.h"
#include "score.h"


static struct timeval timer, now;

void printEnemy(int x, int y) {
    screenSetColor(RED, DARKGRAY);
    if (x >= 0 && y >= 0 && x < MAXX && y < MAXY) {
        screenGotoxy(x, y);
        printf(" ‣ ");
    }
}

void moveEnemy(int *enemyX, int *enemyY) {

    if (*enemyX >= 0) {
        printEnemy(*enemyX, *enemyY);
    }

    *enemyX -= 1;
    
    if (*enemyX < 0) {
        clearEnemy(*enemyX + 3, *enemyY);
        *enemyX = MAXX; 
        int newPos = (randomNumber() % 8);

        *enemyY = rand() % (MAXY - 4) + 1;

    }
}

void initializeEnemies(int enemyX[], int enemyY[], int enemyTimers[]) {
    for (int i = 0; i < NUM_ENEMIES; i++)
    {
        enemyX[i] = MAXX;
        enemyY[i] = rand() % (MAXY - 4) + 1;
        enemyTimers[i] = rand() % 50 + 20;
    }
}

void updateEnemies(int XPos, int YPos, int *life, int enemyX[], int enemyY[], int enemyTimers[], Score* score) {
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
}

void clearEnemy(int enemyX, int enemyY) {
    screenGotoxy(enemyY, enemyX);
    printf("   ");
}

void printMinion(int x, int y) {
    screenSetColor(GREEN, DARKGRAY);

    screenGotoxy(x + 1, y);
    printf("_/@\\_\n");
    screenGotoxy(x, y + 1);
    printf("|\\WVW/|\n");
}

void initializeMinions(int MinionX[], int MinionY[], int MinionTimers[]) {
    for (int i = 0; i < NUM_MINIONS; i++)
    {
        MinionX[i] = MAXX;
        MinionY[i] = (rand() % (MAXY - 4)) + 2;
        if (MinionY[i] > MAXY - 3) {
            MinionY[i] = MAXY - 3;
        }
        MinionTimers[i] = rand() % 50 + 20;
    }
}

void moveMinion(int *minionX, int *minionY) {
    if (*minionX >= 0) {
        printMinion(*minionX, *minionY);
    }

    *minionX -= 1;
    if (*minionX < 0) {
        clearMinion(*minionX + 3, *minionY);
        *minionX = MAXX; 
        *minionY = rand() % (MAXY - 4) + 1;
        if (*minionY > MAXY - 3) {
            *minionY = MAXY - 3;
        }
    }

    if ((rand() % 2) == 1 && *minionY < (MAXY - 3)){
        *minionY += 1;
    } else if (*minionY > (MINY  + 1)) {
        *minionY -= 1;
    }
}

void updateMinions(int XPos, int YPos, int *life, int MinionX[], int MinionY[], int MinionTimers[], Score* score) {
    for (int i = 0; i < NUM_MINIONS; i++) {
        if (MinionTimers[i] > 0) {
            MinionTimers[i]--;
        } else {
            moveMinion(&MinionX[i], &MinionY[i]);
            if (checkCollision(XPos, YPos, MinionX[i], MinionY[i])) {
                clearMinion(MinionX[i], MinionY[i]);
                (*life)--;
                MinionX[i] = MAXX;
                MinionY[i] = rand() % (MAXY - 4) + 1;
                MinionTimers[i] = rand() % 50 + 20;
            } else {
                printMinion(MinionX[i], MinionY[i]);
            }

            if (MinionX[i] < 0) {
                MinionX[i] = MAXX;
                MinionY[i] = rand() % (MAXY - 4) + 1;
                MinionTimers[i] = rand() % 50 + 20;
            }
        }  

        for (int i = 0; i < MAX_BULLETS; i++) {
                for (int i = 0; i < MAX_BULLETS; i++) {
                    for (int j = 0; j < NUM_MINIONS; j++){
                        int bulletX = sendBulletsLocation(i)/1000, bulletY = sendBulletsLocation(i) % 1000;
                        if (checkCollision(MinionX[j], MinionY[j], bulletX, bulletY )&& bulletX < MAXX) {
                            incrementScore(score);
                            MinionX[j] = MAXX;
                            MinionY[j] = rand() % (MAXY - 4) + 1;
                            MinionTimers[j] = rand() % 50 + 20;
                        }
                    }
                }   
        }

    }
}

void clearMinion(int minionX, int minionY) {
    screenGotoxy(minionY - 1, minionX);
    printf("             ");
    screenGotoxy(minionY + 1, minionX);
    printf("              ");
}



