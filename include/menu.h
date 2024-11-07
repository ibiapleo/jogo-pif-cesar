#ifndef MENU_H
#define MENU_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

void showMainMenu(int selectedOption);
void handleMenuInput(int ch, int* selectedOption, int* isPlaying, int* life, int enemyX[], int enemyY[], int enemyTimers[], Mix_Music *gameTrack, int minionX[], int minionY[], int minionTimers[]););
#endif