#include "enemy.h"
#include "timer.h"

void randomPosition(int *XPos, int *YPos){
    int newPos = (randomNumber()%8);

    // New position is based on a direction
    // 0 will be north
    // 1 will be northeast
    // 2 will bem east
    // ...



    if (newPos == 0){
        *YPos -= 1;
    }else if (newPos == 1){
        *XPos += 1;
        *YPos -= 1;
    }else if (newPos == 2){
        *XPos += 1;
    }else if (newPos == 3){
        *XPos += 1;
        *YPos += 1;
    }else if (newPos == 4){
        *YPos += 1;
    }else if (newPos == 5){
        *XPos -= 1;
        *YPos += 1;
    }else if (newPos == 6){
        *XPos -= 1;
    }else if (newPos == 7){
        *XPos -= 1;
        *YPos -= 1;
    }
}
