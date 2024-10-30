#include <string.h>
#include "enemy.h"
#include "screen.h"
#include "keyboard.h"
#include "timer.h"


int x = 0, y = 0;

void printHelicopter(int *x, int *y) {
    screenSetColor(CYAN, DARKGRAY);
    screenGotoxy(*x, *y);
    printf("     ______\n");
    screenGotoxy(*x, *y + 1);
    printf(" |X\\_.-╨─｡_\n");
    screenGotoxy(*x, *y + 2);
    printf(" ─´‾‾‷\\  °★¯]─\n");
    screenGotoxy(*x, *y + 3);
    printf("         ‾‾‾‾\n");
}

void moveHelicopter(int *command, int *YPos, int *XPos) 
{
    screenSetColor(CYAN, DARKGRAY);
    if (*command == 119 && *YPos > MINY + 5){
        *YPos -= 1;
    } else if (*command == 115 && *YPos < MAXY - 5){
        *YPos += 1;
    }
    
    if (*command == 97 && *XPos > MINX + strlen(" ─´‾‾‷\\  °★¯]─\n")){
        *XPos -= 1;
    } else if (*command == 100 && *XPos < MAXX - strlen(" ─´‾‾‷\\  °★¯]─\n") - 1){
        *XPos += 1;
    }

    screenDrawBorders();
    screenGotoxy(*XPos, *YPos);
    printHelicopter(XPos, YPos);
    // Atualiza a tela
    screenUpdate();
}

// Inicialização da biblioteca na main
int main() {
    static int ch = 0;
    int YPos = 10;
    int XPos = 10;
    
    screenInit(1);
    keyboardInit();
    timerInit(50);

    // O loop do jogo segue até pressionar enter (10)
    while (ch != 10) {
        // Verifica se uma tecla foi pressionada
        if (keyhit()) {
            // Captura o caractere pressionado

            ch = readch();



            screenClear();
            screenInit(1);
            screenUpdate();
        }

        // Atualiza o estado do jogo (mover elementos, verificarcolisões, etc)
        if (timerTimeOver() == 1) {
            // Atualiza a tela
            screenUpdate();
            printHelicopter(&XPos, &YPos);
        }
    }
    
    // Desaloca os recursos utilizados pela cli-lib
    keyboardDestroy();
    screenDestroy();
    timerDestroy();
    return 0;
}
