#include <string.h>
#include "screen.h"
#include "keyboard.h"
#include "timer.h"

// Inicialização da biblioteca na main
int main() {
    static int ch = 0;
    // Desenha as bordas da tela do jogo d
    screenInit(1);
    // Inicializa a captura de dados do teclado
    keyboardInit();
    // Define o atraso dos frames no jogo
    timerInit(50);
    // Inicializa atualizando a tela
    screenUpdate();
    // O loop do jogo segue até pressionar enter (10)
    while (ch != 10) {
    // Verifica se uma tecla foi pressionada
    if (keyhit()) {
    // Captura o caractere pressionado
    ch = readch();
    // Atualiza a tela
    screenUpdate();
    }
    // Atualiza o estado do jogo (mover elementos, verificar colisões, etc)
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
