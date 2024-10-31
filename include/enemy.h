#ifndef __ENEMY_H__
#define __ENEMY_H__
#define NUM_ENEMIES 8

void printEnemy(int x, int y);
void randomPosition(int *XPos, int *YPos);
void moveEnemy(int *XPos, int *YPos);
void initializeEnemies(int enemyX[], int enemyY[], int enemyTimers[]);
void clearEnemy(int enemyX, int enemyY);
void updateEnemies(int XPos, int YPos, int *life, int enemyX[], int enemyY[], int enemyTimers[]);

#endif /* __ENEMY_H__ */

