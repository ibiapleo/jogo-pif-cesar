#include <stdio.h>
#include <stdlib.h>
#include "score.h"
#include "screen.h"

Score* createScore() {
    Score* score = (Score*)malloc(sizeof(Score));
    if (score) {
        score->points = 0;
    }
    return score;
}

void incrementScore(Score* score) {
    if (score != NULL) {
        score->points += 5;
    }
}

void resetScore(Score* score) {
    if (score) {
        score->points = 0;
    }
}

void freeScore(Score* score) {
    if (score) {
        free(score);
    }
}

void saveScoreToFile(const Score* score, char* name) {
    if (!score) return;
    
    FILE *file = fopen("scores.txt", "a");
    if (file) {
        fprintf(file, "%s | %d\n", name, score->points);
        fclose(file);
    } else {
        fprintf(stderr, "Erro ao abrir o arquivo de pontuação.\n");
    }
}

void printScore(int x, int y, Score* score) {
    screenSetColor(RED, DARKGRAY);
    screenGotoxy(x + 10, y);
    printf("  🏆  %d", score -> points);
}