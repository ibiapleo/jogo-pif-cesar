#include <stdlib.h>
#include <stdio.h>
#include "menu.h"
#include "wing.h"
#include "game.h"
#include "screen.h"
#include "keyboard.h"
#include "timer.h"
#include "enemy.h"
#include "musics.h"
#include "score.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

int main() {
    initializeAudioSystem();
    Mix_Music *menuMusic = initializeMenuAudio();
    Mix_Music *gameTrack = initializeGameTrack();
    Mix_Music *deathSound = initializeDeathSound();
    Mix_Chunk *pewSound = pew();

    if (!menuMusic || !gameTrack || !deathSound || !pewSound) {
        fprintf(stderr, "Erro ao carregar recursos de áudio.\n");
        return 1;
    }

    int ch = 0;
    int YPos = 20, XPos = 20;
    int life, isPlaying = 0, selectedOption = 0;
    int enemyX[NUM_ENEMIES], enemyY[NUM_ENEMIES], enemyTimers[NUM_ENEMIES];
    int minionX[NUM_MINIONS], minionY[NUM_MINIONS], minionTimers[NUM_MINIONS];
    Score* score = createScore();
    char name[21] = {0};

    keyboardInit();
    screenInit(1);
    Mix_HaltMusic();
    Mix_PlayMusic(menuMusic, -1);
    
    while (1) {
        if (isPlaying == 0) {
            showMainMenu(selectedOption);
            ch = readch();
            handleMenuInput(ch, &selectedOption, &isPlaying, &life, enemyX, enemyY, enemyTimers, gameTrack, minionX, minionY, minionTimers, &name);
            resetScore(score);
        } else {
            if (keyhit()) {
                ch = readch();
                moveWing(&ch, &YPos, &XPos);
                moveWingBullet(&XPos, &YPos, &ch, pewSound);
            }

            updateGame(&YPos, &XPos, &life, enemyX, enemyY, enemyTimers, minionX, minionY, minionTimers, score);

            if (life <= 0) {
                saveScoreToFile(score, &name);
                handleGameOver(gameTrack, deathSound, score);
                isPlaying = 0;
            }
        }
    }

    freeScore(score);
    cleanUp(&menuMusic, &gameTrack, &deathSound, &pewSound);
    SDL_Quit();
    return 0;
}
