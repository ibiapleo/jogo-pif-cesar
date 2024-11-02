#include "background.h"
#include "screen.h"
#include "timer.h"

#define MAX_STARS 10
#define STARS_SPEED 10000000000000
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

        while (number < MINX + 1 && number > MAXX - 1)
        {
            number = randomNumber();
        }

        stars[i].XPos = number;

        while (number < MINY + 1 && number > MAXY - 1)
        {
            number = randomNumber();
        }   

        stars[i].YPos = number;
        stars[i].distance = (i % 2);
        stars[i].star = '+';

    }
}

void printStars(){
    for (int i = 0; i < MAX_STARS; i++){
        if (stars[i].distance == 0){
            screenSetColor(LIGHTGRAY, BLACK);
            screenGotoxy(stars[i].XPos, stars[i].YPos);
            printf("*");
        }
        if (stars[i].distance == 1){
            screenSetColor(DARKGRAY, BLACK);
            screenGotoxy(stars[i].XPos, stars[i].YPos);
            printf("*");
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




