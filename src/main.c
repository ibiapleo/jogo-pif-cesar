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
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>


int main() {
    Mix_Music *menuMusic = initializeMenuAudio();
    Mix_Music *gameTrack = initializeGameTrack();
    Mix_Music *deathSound = initializeDeathSound();
    int ch = 0;
    int YPos = 20, XPos = 20;
    int life, isPlaying = 0, selectedOption = 0;
    int enemyX[NUM_ENEMIES], enemyY[NUM_ENEMIES], enemyTimers[NUM_ENEMIES];

    keyboardInit();
    screenInit(1);
    Mix_PlayMusic(menuMusic, -1);
    
    while (1) {
        if (isPlaying == 0) {
            showMainMenu(selectedOption);
            ch = readch();
            handleMenuInput(ch, &selectedOption, &isPlaying, &life, enemyX, enemyY, enemyTimers, menuMusic, gameTrack);
        } else {
            if (keyhit()) {
                ch = readch();
                moveWing(&ch, &YPos, &XPos);
                moveWingBullet(&XPos, &YPos, &ch);
            }

            updateGame(&YPos, &XPos, &life, enemyX, enemyY, enemyTimers);

            if (life <= 0) {
                handleGameOver(gameTrack, deathSound);
                isPlaying = 0;
            }
        }
    }

    cleanUp();
    SDL_Quit();
    return 0;
}