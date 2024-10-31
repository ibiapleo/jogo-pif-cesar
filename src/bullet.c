#include "bullet.h"
#include "screen.h"
#include <string.h>

#define MAX_BULLETS 12

typedef struct {
    int x;
    int y;
    int status; // ativa ou inativa
} Bullet;

Bullet myBullets[MAX_BULLETS];

void printBullet(int XBullet, int YBullet) {
    screenGotoxy(XBullet, YBullet);
    printf(" ⁍ ");
    screenUpdate();
}  

void clearBullet(int XBullet, int YBullet) {
    screenGotoxy(XBullet, YBullet);
    printf("   ");
    screenUpdate();
}

void shootBullets(int *XPos, int *YPos) {
    for (int i = 0; i < MAX_BULLETS; i++) {
        if (myBullets[i].status != 1)  { // Encontra uma bala inativa
            myBullets[i].x = *XPos + 6; // Ajusta a posição X da bala com a nave
            myBullets[i].y = *YPos + 2; // Ajusta a posição Y da bala com a nave
            myBullets[i].status = 1; // Marca a bala como ativa
            printBullet(myBullets[i].x, myBullets[i].y); // Desenha a nova bala
            break; // Sai do loop após adicionar a nova bala
        }
    }
}

void moveBullets() {
    for (int i = 0; i < MAX_BULLETS; i++) {
        if (myBullets[i].status == 1) { //Encontra uma bala ativa
            clearBullet(myBullets[i].x, myBullets[i].y); // Limpa a posicao antiga da bala
            myBullets[i].x++; // Movimenta a bala uma posição
            
            if (myBullets[i].x >= MAXX) {
                myBullets[i].status = 0; // Desativa a bala se sair da tela
            } else {
                printBullet(myBullets[i].x, myBullets[i].y); // Desenha a nova bala
            }
        }
    }
}

void moveWingBullet(int *XPos, int *YPos, int *command) {
     if (*command == 32) { // Espaço
        shootBullets(XPos, YPos);
    }
 }

