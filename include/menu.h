#ifndef MENU_H
#define MENU_H

void showMainMenu(int selectedOption);
void handleMenuInput(int ch, int* selectedOption, int* isPlaying, int* life, int enemyX[], int enemyY[], int enemyTimers[]);

#endif