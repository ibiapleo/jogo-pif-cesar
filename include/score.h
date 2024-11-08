#ifndef SCORE_H
#define SCORE_H

typedef struct {
    int points;
} Score;

Score* createScore();
void incrementScore(Score* score);
void resetScore(Score* score);
void freeScore(Score* score);
void saveScoreToFile(const Score* score);
void printScore();

#endif
