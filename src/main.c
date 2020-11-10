#include "../inc/game.h"

int main() {
    mStartTicks = SDL_GetTicks();
    mPausedTicks = 0;
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;
    Uint32 frameStart;
    int frameTime;
    is_pause = false;

    init("Bomberman", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 2000, 1280, false);
    //Init Texture
    init_texture();
    while(isRunning){
        frameStart = SDL_GetTicks();
        timer_start = SDL_GetTicks();
        handleEvents();
        if (!is_pause) {
            update();
            render();
        }
        frameTime = SDL_GetTicks() - frameStart;
        if(frameDelay > frameTime) SDL_Delay(frameDelay - frameTime);
        init_timer();
    }
    clean();
}
