#include "../inc/game.h"

int main() {
    mouseX = 0;
    mouseY = 0;
    mStartTicks = SDL_GetTicks();
    mPausedTicks = 0;
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;
    Uint32 frameStart;
    int frameTime;
    
    SDL_Delay(1000);
    init("Bomberman", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 2000, 1280, false);
    //Init Texture
    init_texture();
    while(isRunning){
        frameStart = SDL_GetTicks();
        handleEvents();
        if (!is_pause && !is_intro && !is_lose) {
            update();
            init_timer();
        }
        if (isRunning) render();
        frameTime = SDL_GetTicks() - frameStart;
        if(frameDelay > frameTime) SDL_Delay(frameDelay - frameTime);
    }
    clean();
}
