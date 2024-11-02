#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

void initializeGame(int *life, int enemyX[], int enemyY[], int enemyTimers[], Mix_Music *gameTrack);
void updateGame(int *YPos, int *XPos, int *life, int enemyX[], int enemyY[], int enemyTimers[]);
void handleGameOver(Mix_Music *gameTrack, Mix_Music *deathSound);
void displayGameOver(Mix_Music *gameTrack, Mix_Music *deathSound);
void handleGameOver();
void cleanUp(Mix_Music **menuMusic, Mix_Music **gameTrack, Mix_Music **deathSound, Mix_Chunk **pewSound);

#endif