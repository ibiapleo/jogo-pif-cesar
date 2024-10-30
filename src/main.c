#include <string.h>
#include "screen.h"
#include "keyboard.h"
#include "timer.h"


int x = 0, y = 0;

void prtAndMoveHelicopter(int *command, int *YPos, int *XPos) 
{
    screenSetColor(CYAN, DARKGRAY);
    if (*command == 119 && *YPos > MINY + strlen("O")){
        *YPos -= 1;
    } else if (*command == 115 && *YPos < MAXY - strlen("O")){
        *YPos += 1;
    }
    
    if (*command == 97 && *XPos > MINX + strlen("O")){
        *XPos -= 1;
    } else if (*command == 100 && *XPos < MAXX - strlen("O") - 1){
        *XPos += 1;
    }

    screenDrawBorders();
    screenGotoxy(*XPos, *YPos);
    printf("0");
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

            prtAndMoveHelicopter(&ch, &YPos, &XPos);

            screenClear();
            screenInit(1);
            screenGotoxy(((randomNumber()*327)%44), (randomNumber()%30));
            printf("0");
            // Atualiza a tela
            screenUpdate();
        }

        // Atualiza o estado do jogo (mover elementos, verificarcolisões, etc)
        if (timerTimeOver() == 1) {
            // Atualiza a tela
            screenUpdate();
        }
    }
    
    // Desaloca os recursos utilizados pela cli-lib
    keyboardDestroy();
    screenDestroy();
    timerDestroy();
    return 0;
}
