#include "menu.h"
#include "screen.h"
#include "keyboard.h"
#include "game.h"
#include "ranking.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <string.h>

void showMainMenu(int selectedOption) {
    screenClear();

    screenDrawBorders();
    screenSetColor(WHITE, BLACK);
    screenGotoxy(SCRSTARTX + 34, SCRSTARTY + 15);
    screenPrintCenter("=== MENU PRINCIPAL ===");

    const char* options[] = {"1. Iniciar Jogo", "2. Modo do Jogo - A REALIZAR", "3. Ver Rankings"};
    for (int i = 0; i < 3; i++) {
        screenSetColor(selectedOption == i ? CYAN : WHITE, BLACK);
        screenGotoxy(SCRSTARTX + 36, SCRSTARTY + 16 + i);
        screenPrintCenter(options[i]);
    }

    screenSetColor(WHITE, BLACK);
    screenGotoxy(SCRSTARTX + 24, SCRSTARTY + 13);

    screenPrintCenter("Use o WASD para mover e Enter para selecionar");
    screenUpdate();
}
void handleMenuInput(int ch, int* selectedOption, int* isPlaying, int* life, int enemyX[], int enemyY[], int enemyTimers[], Mix_Music *gameTrack, int minionX[], int minionY[], int minionTimers[], char* name) {
    
    
    if (ch == 119) *selectedOption = (*selectedOption - 1 + 3) % 3;
    else if (ch == 115) *selectedOption = (*selectedOption + 1) % 3;
    else if (ch == 10) {
        if (*selectedOption == 0) {
            nameInput(name);
            initializeGame(life, enemyX, enemyY, enemyTimers, gameTrack, minionX, minionY, minionTimers);
            *isPlaying = 1;
        } else if (*selectedOption == 2) {
            showRanking();
        }
    }
}

void printName(char name[]) {
    screenGotoxy(SCRSTARTX + 40, SCRSTARTY + 13);
    printf("Insira seu nome");

    screenGotoxy(SCRSTARTX + 33, SCRSTARTY + 14);
    printf("------------------------------");

    screenGotoxy(SCRSTARTX + 33, SCRSTARTY + 15);
    printf("|                            |"); 

    screenGotoxy(SCRSTARTX + 33, SCRSTARTY + 16);
    printf("------------------------------");

    screenGotoxy(SCRSTARTX + 33, SCRSTARTY + 18);
    printf("Pressione Enter para continuar");

    screenGotoxy(SCRSTARTX + 35, SCRSTARTY + 15);
    printf("%s", name);
}

void nameInput(char* name){
    int ch = 0;
    int contador = 0;
    
    screenDrawBorders();

    screenGotoxy((MAXX/2), (MAXY/2)); 

    printName(name);
    screenUpdate();
    while (ch != 10){ 
        if (keyhit()){
            ch = readch();
            if (ch == 127 && contador > 0){ 
                contador--;
                name[contador] = '\0';
                printName(name);
                screenUpdate();
            }else if(contador < 20){ 
                name[contador] = ch;
                contador++;
                printName(name);
                screenUpdate();
            }
        }
    }
}