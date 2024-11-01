#include "enemy.h"
#include "timer.h"
#include <stdio.h>
#include "screen.h"
#include <stdlib.h> 
#include "collision.h"
#include <sys/time.h>

static struct timeval timer, now;

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

void updateEnemies(int XPos, int YPos, int *life, int enemyX[], int enemyY[], int enemyTimers[]) {
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

void clearEnemy(int enemyX, int enemyY) {
    screenGotoxy(enemyY, enemyX);
    printf("   ");
    screenUpdate();
}
// 
// void moveMinion(int *XPos, int *YPos) {
//     int newPos = (randomNumber() % 8);
// 
//     int timediff =;
// 
//     if (timediff > 75){
// 
//         screenGotoxy(*XPos + 1, *YPos);
//         printf("          \n");
//         screenGotoxy(*XPos, *YPos + 1);
//         printf("          \n");
// 
//         if (newPos == 0 && *YPos > MINY) {
//             *YPos -= 1;
//         } else if (newPos == 1 && *YPos > MINY && *XPos < MAXX) {
//             *XPos += 1;
//             *YPos -= 1;
//         } else if (newPos == 2 && *XPos < MAXX)  {
//             *XPos += 1;
//         } else if (newPos == 3 && *YPos < MAXY && *XPos < MAXX) {
//             *XPos += 1;
//             *YPos += 1;
//         } else if (newPos == 4 && *YPos < MAXY)  {
//             *YPos += 1;
//         } else if (newPos == 5 && *YPos < MAXY && *XPos > MINX) {
//             *XPos -= 1;
//             *YPos += 1;
//         } else if (newPos == 6 && *XPos > MINX) {
//             *XPos -= 1;
//         } else if (newPos == 7 && *YPos > MINY && *XPos > MINX) {
//             *XPos -= 1;
//             *YPos -= 1;
//         }
//         timediff = getTimeDiff();
//     }
// }

void printMinion(int x, int y) {


    screenSetColor(GREEN, DARKGRAY);

    screenGotoxy(x + 1, y);
    printf("_/@\\_\n");
    screenGotoxy(x, y + 1);
    printf("|\\WVW/|\n");
    
    screenUpdate();

}

int minionSpeed()
{
    gettimeofday(&now, NULL);
    long diff = (((now.tv_sec - timer.tv_sec) * 1000000) + now.tv_usec - timer.tv_usec)/1000;
    return (int) diff;
}

void moveMinion(int *minionX, int *minionY) {
    int timediff;

    if (*minionX >= 0) {
        printMinion(*minionX, *minionY);
    }

    *minionX -= 1;
    if (*minionX < 0) {
        clearMinion(*minionX + 3, *minionY);
        *minionX = MAXX; 
        *minionY = rand() % (MAXY - 4) + 1;
    }

    timediff = minionSpeed();

    if (timediff > 1000){
        if ((randomNumber() % 2) == 1){
            *minionY += 1;
        }else {
            *minionY -= 1;
        }

    }


}

void initializeMinions(int MinionX[], int MinionY[], int MinionTimers[]) {
    for (int i = 0; i < NUM_MINIONS; i++)
    {
        MinionX[i] = MAXX;
        MinionY[i] = (rand() % (MAXY - 4)) + 2;
        MinionTimers[i] = rand() % 50 + 20;
    }
}

void updateMinions(int XPos, int YPos, int *life, int MinionX[], int MinionY[], int MinionTimers[]) {
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
    }
    screenUpdate();
}

void clearMinion(int minionX, int minionY) {
    screenGotoxy(minionY - 1, minionX);
    printf("             ");
    screenGotoxy(minionY + 1, minionX);
    printf("              ");
    screenUpdate();
}



