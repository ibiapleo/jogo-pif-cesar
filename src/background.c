#include "background.h"
#include "screen.h"
#include "timer.h"
#include "enemy.h"
#include <stdio.h>
#include <stdlib.h> 
#include "collision.h"
#include <sys/time.h>
#include "bullet.h"


#define MAX_STARS 20
#define STARS_SPEED 10000000000000
int contador = 0;

typedef struct
{
    int XPos;
    int YPos;
    int distance;

}backgroundSparkle; 

backgroundSparkle stars[MAX_STARS];

void initializaStars(){
    
    for (int i = 0; i < MAX_STARS; i++)

    {
        stars[i].YPos = (rand() % (MAXY - 2)) + 2;
        stars[i].XPos = (rand() % (MAXX - 4)) + 2;
        stars[i].distance = (i % 2);

    }

}

void printStars(){
    for (int i = 0; i < MAX_STARS; i++){
        if (stars[i].distance == 0){
            screenSetColor(WHITE, DARKGRAY);
            screenGotoxy(stars[i].XPos, stars[i].YPos);
            printf(".");
        }else {
            screenSetColor(LIGHTGRAY, DARKGRAY);
            screenGotoxy(stars[i].XPos, stars[i].YPos);
            printf(".");
        }
    }
    screenUpdate();
}

void moveStars(){
    contador++;
    for(int i = 0; i < MAX_STARS; i++){
        if ((contador % 2) == 0 && stars[i].distance == 1){
            clearStar(stars[i].XPos, stars[i].YPos);
            stars[i].XPos--;
            if (contador == 8)
            {
                contador = 0;
            }
                       
        }else if (contador == 3){
            clearStar(stars[i].XPos, stars[i].YPos);
            stars[i].XPos--;
        }

        if (stars[i].XPos < 0) {
            clearStar(stars[i].XPos, stars[i].YPos);
            stars[i].XPos = MAXX; 
            stars[i].YPos = rand() % (MAXY - 4) + 1;

        }
    }
}

void clearStar(int XPos, int YPos) {
    screenGotoxy(XPos, YPos);
    printf("  ");
}




