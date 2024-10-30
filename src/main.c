#include <string.h>
#include "screen.h"
#include "keyboard.h"
#include "timer.h"
#include "helicopter.h"


int x = 0, y = 0;

// Inicialização da biblioteca na main
int main() {
    static int ch = 0;
    int YPos = 20;
    int XPos = 20;
    
    screenInit(1);
    keyboardInit();
    timerInit(50);

    // O loop do jogo segue até pressionar enter (10)
    while (ch != 10) {
        // Verifica se uma tecla foi pressionada
        if (keyhit()) {
            // Captura o caractere pressionado

            ch = readch();
            moveHelicopter(&ch, &YPos, &XPos);
            // Atualiza a tela
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
