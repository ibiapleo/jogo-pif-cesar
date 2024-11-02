#include "background.h"
#include "screen.h"
#include "timer.h"

#define MAX_STARS 20
#define STARS_SPEED 10
int contador = 0;

typedef struct
{
    char star;
    int XPos;
    int YPos;
    int distance;

}backgroundSparkle; 

backgroundSparkle stars[MAX_STARS];

void initializaStars(){
    
    int number;

    for (int i = 0; i < MAX_STARS; i++){

        number = randomNumber();

        while (number > MINX && number < MAXX)
        {
            number = randomNumber();
        }

        stars[i].XPos = randomNumber();

        while (number > MINY && number < MAXY)
        {
            number = randomNumber();
        }   

        stars[i].YPos = randomNumber();
        stars[i].distance = (i % 2);
        stars[i].star[0] = "*";

    }
}

void printStars(){
    for (int i = 0; i < MAX_STARS; i++){
        if (stars[i].distance == 0){
            screenSetColor(LIGHTGRAY, BLACK);
            screenGotoxy(randomNumber() % MAXX, randomNumber() % MAXY);
        }
        if (stars[i].distance == 1){
            screenSetColor(DARKGRAY, BLACK);
            screenGotoxy(randomNumber() % MAXX, randomNumber() % MAXY);
        }
    }
    screenUpdate();
}

void moveStars(){
    contador++;
    for(int i = 0; i < MAX_STARS; i++){
        clearStar(stars[i].XPos, stars[i].YPos);
        if (contador == (STARS_SPEED) && stars[i].distance == 1){
            stars[i].XPos--;
        }
        if (contador == (STARS_SPEED) && stars[i].distance){
            stars[i].XPos--;
        }
    }
}

void clearStar(int XPos, int YPos) {
    screenGotoxy(XPos, YPos);
    printf("  ");
}




