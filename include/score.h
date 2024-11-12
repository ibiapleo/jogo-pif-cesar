#ifndef SCORE_H
#define SCORE_H

typedef struct {
    int points;
} Score;

Score* createScore();
void incrementScore();
void resetScore();
void freeScore();
void saveScoreToFile();
void printScore();

#endif
