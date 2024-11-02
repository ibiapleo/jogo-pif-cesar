#include <stdlib.h>
#include <stdio.h>
#include "menu.h"
#include "wing.h"
#include "game.h"
#include "screen.h"
#include "keyboard.h"
#include "timer.h"
#include "enemy.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

Mix_Music* initializeAudio() {
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        fprintf(stderr, "Não foi possível inicializar o SDL: %s\n", SDL_GetError());
        return NULL;
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        fprintf(stderr, "Erro ao inicializar SDL_mixer: %s\n", Mix_GetError());
        return NULL;
    }

    Mix_Music *backgroundMusic = Mix_LoadMUS("musicas/audio.mp3");
    if (!backgroundMusic) {
        fprintf(stderr, "Erro ao carregar música: %s\n", Mix_GetError());
        return NULL;
    }

    return backgroundMusic;
}

int main() {
    Mix_Music *backgroundMusic = initializeAudio();
    if (!backgroundMusic) return 1;

    int ch = 0;
    int YPos = 20, XPos = 20;
    int life, isPlaying = 0, selectedOption = 0;
    int enemyX[NUM_ENEMIES], enemyY[NUM_ENEMIES], enemyTimers[NUM_ENEMIES];
    int minionX[NUM_MINIONS], minionY[NUM_MINIONS], minionTimers[NUM_MINIONS];

    keyboardInit();
    screenInit(1);
    //Mix_PlayMusic(backgroundMusic, -1);
    

    while (1) {
        if (isPlaying == 0) {
            showMainMenu(selectedOption);
            ch = readch();
            handleMenuInput(ch, &selectedOption, &isPlaying, &life, enemyX, enemyY, enemyTimers, minionX, minionY, minionTimers);
        } else {
            if (keyhit()) {
                ch = readch();
                moveWing(&ch, &YPos, &XPos);
                moveWingBullet(&XPos, &YPos, &ch);
            }

            updateGame(&YPos, &XPos, &life, enemyX, enemyY, enemyTimers, minionX, minionY, minionTimers);

            if (life <= 0) {
                handleGameOver();
                isPlaying = 0;
            }
        }
    }

    cleanUp();
    //Mix_FreeMusic(backgroundMusic);
    //Mix_CloseAudio();
    //SDL_Quit();
    return 0;
}