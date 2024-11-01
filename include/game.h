#ifndef GAME_H
#define GAME_H


void initializeGame(int *life, int enemyX[], int enemyY[], int enemyTimers[], int minionX[], int minionY[], int minionTimers[]);
void updateGame(int *YPos, int *XPos, int *life, int enemyX[], int enemyY[], int enemyTimers[], int minionX[], int minionY[], int minionTimers[]);
void handleGameOver();
void displayGameOver();
void handleGameOver();
void cleanUp();

#endif