#include "collision.h"

int checkCollision(int heliX, int heliY, int enemyX, int enemyY)
{
    int heliWidth = 13;
    int heliHeight = 4;

    return (enemyX >= heliX && enemyX < heliX + heliWidth &&
            enemyY >= heliY && enemyY < heliY + heliHeight);
}