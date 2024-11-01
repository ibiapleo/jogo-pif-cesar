#include "menu.h"
#include "screen.h"
#include "keyboard.h"
#include "game.h"

void showMainMenu(int selectedOption) {
    screenClear();
    screenSetColor(WHITE, BLACK);
    screenGotoxy(SCRSTARTX + 29, SCRSTARTY + 10);
    screenPrintCenter("=== MENU PRINCIPAL ===");

    const char* options[] = {"1. Iniciar Jogo", "2. Selecionar Modo", "3. Ver Rankings"};
    for (int i = 0; i < 3; i++) {
        screenSetColor(selectedOption == i ? CYAN : WHITE, BLACK);
        screenGotoxy(SCRSTARTX + 31, SCRSTARTY + 11 + i);
        screenPrintCenter(options[i]);
    }

    screenSetColor(WHITE, BLACK);
    screenGotoxy(SCRSTARTX + 22, SCRSTARTY + 8);
    screenPrintCenter("Use as setas para mover e Enter para selecionar");
    screenUpdate();
}

void handleMenuInput(int ch, int* selectedOption, int* isPlaying, int* life, int enemyX[], int enemyY[], int enemyTimers[], int minionX[], int minionY[], int minionTimers[]) {
    if (ch == 119) *selectedOption = (*selectedOption - 1 + 3) % 3;
    else if (ch == 115) *selectedOption = (*selectedOption + 1) % 3;
    else if (ch == 10) {
        if (*selectedOption == 0) {
            initializeGame(life, enemyX, enemyY, enemyTimers, minionX, minionY, minionTimers);
            *isPlaying = 1;
        }
    }
}