#include "musics.h"

void initializeAudioSystem() {
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        fprintf(stderr, "Não foi possível inicializar o SDL: %s\n", SDL_GetError());
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4100) < 0) {
        fprintf(stderr, "Erro ao inicializar SDL_mixer: %s\n", Mix_GetError());
    }
}

Mix_Music* initializeMenuAudio() {

    Mix_Music *menuMusic = Mix_LoadMUS("../musicas/Menu_Track.mp3");
    if (!menuMusic) {
        fprintf(stderr, "Erro ao carregar música: %s\n", Mix_GetError());
        return NULL;
    }

    return menuMusic;
}

Mix_Music* initializeGameTrack() {

    Mix_Music *gameTrack = Mix_LoadMUS("../musicas/Game_Track.mp3");
    if (!gameTrack) {
        fprintf(stderr, "Erro ao carregar música: %s\n", Mix_GetError());
        return NULL;
    }

    return gameTrack;
}

Mix_Music* initializeDeathSound() {

    Mix_Music *deathSound = Mix_LoadMUS("../musicas/Death_Sound.mp3");
    if (!deathSound) {
        fprintf(stderr, "Erro ao carregar música: %s\n", Mix_GetError());
        return NULL;
    }

    return deathSound;
}

Mix_Chunk* pew() {

    Mix_Chunk *pewSound = Mix_LoadWAV("../musicas/Pew.wav");
    if (!pewSound) {
        fprintf(stderr, "Erro ao carregar áudio: %s\n", Mix_GetError());
        return NULL;
    }

    Mix_Volume(-1, MIX_MAX_VOLUME);

    return pewSound;
}
