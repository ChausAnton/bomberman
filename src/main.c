#include "../inc/game.h"

int main() {
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;
    Uint32 frameStart;
    int frameTime;

    init("Bomberman", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1600, 1280, false);

    while(isRunning){
        frameStart = SDL_GetTicks();
        handleEvents();
        update();
        render();
        frameTime = SDL_GetTicks() - frameStart;
        if(frameDelay > frameTime) SDL_Delay(frameDelay - frameTime);
    }
    clean();
}
