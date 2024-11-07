#ifndef __ENEMY_H__
#define __ENEMY_H__
#define NUM_ENEMIES 8
#define NUM_MINIONS 4

void printEnemy(int x, int y);
void moveMinion(int *XPos, int *YPos);
void moveEnemy(int *XPos, int *YPos);
void printMinion();
void initializeEnemies(int enemyX[], int enemyY[], int enemyTimers[]);
void clearEnemy(int enemyX, int enemyY);
void updateEnemies(int XPos, int YPos, int *life, int enemyX[], int enemyY[], int enemyTimers[]);
void printMinion(int x, int y);
void moveMinion(int *XPos, int *YPos);
void initializeMinions(int enemyX[], int enemyY[], int enemyTimers[]);
void clearMinion(int enemyX, int enemyY);
void updateMinions(int XPos, int YPos, int *life, int MinionX[], int MinionY[], int MinionTimers[]);


#endif /* __ENEMY_H__ */

