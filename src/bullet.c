#include "bullet.h"
#include "screen.h"
#include <string.h>
#include "musics.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

#define MAX_BULLETS 12
typedef struct {
    int x;
    int y;
    int status;
} Bullet;

Bullet myBullets[MAX_BULLETS];

void printBullet(int XBullet, int YBullet) {
    screenGotoxy(XBullet, YBullet);
    printf(" ‣ ");
    screenUpdate();
}  

void clearBullet(int XBullet, int YBullet) {
    screenGotoxy(XBullet, YBullet);
    printf("   ");
    screenUpdate();
}

void shootBullets(int *XPos, int *YPos, Mix_Chunk *pewSound) {
    for (int i = 0; i < MAX_BULLETS; i++) {
        if (myBullets[i].status != 1)  {
            Mix_PlayChannel(-1, pewSound, 0);
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

void moveWingBullet(int *XPos, int *YPos, int *command, Mix_Chunk *pewSound) {
     if (*command == 32) { // Espaço
        shootBullets(XPos, YPos, pewSound);
    }
 }