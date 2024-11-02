#ifndef MUSICS_H
#define MUSICS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

Mix_Music* initializeMenuAudio();

Mix_Music* initializeGameTrack();

Mix_Music* initializeDeathSound();

#endif