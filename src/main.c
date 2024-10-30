#include <string.h>
#include "enemy.h"
#include "screen.h"
#include "keyboard.h"
#include "timer.h"
#include "helicopter.h"
#include "life.h"
#include "enemy.h"
#include <stdlib.h>

int checkCollision(int heliX, int heliY, int enemyX, int enemyY) {
    int heliWidth = 15;
    int heliHeight = 4;

    return (enemyX >= heliX && enemyX < heliX + heliWidth && 
            enemyY >= heliY && enemyY < heliY + heliHeight);
}

int main() {
    static int ch = 0;
    int YPos = 20;
    int XPos = 20;
    int enemyX = MAXX, enemyY = 10;
    int life = LIFE;
    int collisionDetected = 0;

    screenInit(1);
    keyboardInit();
    timerInit(50);

    while (ch != 10) {
    if (keyhit()) {
        ch = readch();
        moveHelicopter(&ch, &YPos, &XPos);
        screenUpdate();
    }

    printHelicopter(&XPos, &YPos);
    printLife(SCRSTARTY, SCRSTARTX, life);

    if (timerTimeOver() == 1) {
        moveEnemy(&enemyX, &enemyY);
        if (checkCollision(XPos, YPos, enemyX, enemyY) && !collisionDetected) { 
            life--;
            collisionDetected = 1;
        } else if (!checkCollision(XPos, YPos, enemyX, enemyY)) {
            collisionDetected = 0;
        }
        printEnemy(enemyX, enemyY);
        screenUpdate();
    }
}
    
    keyboardDestroy();
    screenDestroy();
    timerDestroy();
    return 0;
}