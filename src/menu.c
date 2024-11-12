#include "menu.h"
#include "screen.h"
#include "keyboard.h"
#include "game.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <string.h>

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
        }
    }
}



void printName(char namr[]) {
    screenGotoxy((MAXX / 2), (MAXY / 2));
    // Usar %s para imprimir a string, até o terminador nulo
    printf("%s", namr);
    
}



void nameInput(char* name){
    int ch = 0; // Inicializa ch
    int contador = 0; // Deve ser int, não char

    // Limpa a tela
    for (int i = 0; i < MAXX; i++){
        for (int j = 0; j < MAXY; j++){
            screenGotoxy(i, j);
            printf("  ");
        }
    }  

    screenGotoxy((MAXX/2), (MAXY/2)); 

    while (ch != 10){ 
        if (keyhit()){
            ch = readch();
            if (ch == 127 && contador > 0){ 
                contador--;
                name[contador] = '\0'; 
                printName(name);
                printf("                          ");
                screenUpdate();
                
            }else if(contador < 20){ 
                name[contador] = ch;
                contador++;
                printf("                         ");
                printName(name);
                screenUpdate();
            }
        }
    }
    
}