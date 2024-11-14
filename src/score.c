#include <stdio.h>
#include <stdlib.h>
#include "score.h"
#include "screen.h"
#include <string.h>
#include <ctype.h>

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

void trimWhitespace(char* str) {
    size_t len = strlen(str);
    while (len > 0 && (isspace((unsigned char)str[len - 1]) || str[len - 1] == '\n')) {
        str[--len] = '\0';
    }
    char* start = str;
    while (*start && isspace((unsigned char)*start)) {
        start++;
    }
    memmove(str, start, strlen(start) + 1);
}

void saveScoreToFile(const Score* score, char* name) {
    if (!score || !name) return;
    
    trimWhitespace(name);

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