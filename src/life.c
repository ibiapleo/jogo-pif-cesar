#include "life.h"
#include "screen.h"
#include <stdio.h>

void printLife(int x, int y, int life) {
    screenSetColor(RED, DARKGRAY);
    screenGotoxy(x + 1, y);
    printf("  ♥   %d", life);
}