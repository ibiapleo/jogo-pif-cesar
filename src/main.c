#include <string.h>
#include "screen.h"
#include "keyboard.h"
#include "timer.h"

// Inicialização da biblioteca na main
int main() {
    static int ch = 0;
    int YPos = 5;

    
    screenInit(1);
    keyboardInit();
    timerInit(50);


    screenGotoxy(5, YPos);
    screenInit(1);
    printf("0");
    screenUpdate();
    



    // O loop do jogo segue até pressionar enter (10)
    while (ch != 10) {
        // Verifica se uma tecla foi pressionada
        if (keyhit()) {
            // Captura o caractere pressionado

            ch = readch();

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
