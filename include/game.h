#ifndef GAME_H
#define GAME_H

void initializeGame(int *life, int enemyX[], int enemyY[], int enemyTimers[]);
void updateGame(int *YPos, int *XPos, int *life, int enemyX[], int enemyY[], int enemyTimers[]);
void handleGameOver();
void displayGameOver();
void handleGameOver();
void cleanUp();

#endif