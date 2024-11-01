#include "bullet.h"
#include "screen.h"
#include <string.h>

#define MAX_BULLETS 12
typedef struct {
    int x;
    int y;
    int status;
} Bullet;

Bullet myBullets[MAX_BULLETS];

void printBullet(int XBullet, int YBullet) {
    screenGotoxy(XBullet, YBullet);
    printf(" ⁍ ");
    screenUpdate();
}  

void clearBullet(int XBullet, int YBullet) {
    screenGotoxy(XBullet, YBullet);
    printf("   ");
    screenUpdate();
}

void shootBullets(int *XPos, int *YPos) {
    for (int i = 0; i < MAX_BULLETS; i++) {
        if (myBullets[i].status != 1)  {
            myBullets[i].x = *XPos + 10;
            myBullets[i].y = *YPos + 2;
            myBullets[i].status = 1;
            printBullet(myBullets[i].x, myBullets[i].y);
            break;
        }
    }
}

void moveBullets() {
    for (int i = 0; i < MAX_BULLETS; i++) {
        if (myBullets[i].status == 1) {
            clearBullet(myBullets[i].x, myBullets[i].y);
            myBullets[i].x++;
            
            if (myBullets[i].x >= MAXX) {
                myBullets[i].status = 0;
            } else {
                printBullet(myBullets[i].x, myBullets[i].y);
            }
        }
    }
}

void moveWingBullet(int *XPos, int *YPos, int *command) {
     if (*command == 32) { // Espaço
        shootBullets(XPos, YPos);
    }
 }