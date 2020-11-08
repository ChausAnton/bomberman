#include "../inc/game.h"
#include "../inc/texture_manager.h"
#include "../inc/map.h"
#include "../inc/key_config.h"

void init(const char *title, int x_pos, int y_pos, int width, int height, bool fullscreen){
    int flags = 0;
    if(fullscreen) flags = SDL_WINDOW_FULLSCREEN;
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
        printf("\nTerminal Handler initialized.\n\n");
        printf("Subsystems initialized.\n");
        window = SDL_CreateWindow(title, x_pos, y_pos, width, height, flags);
        if(window) printf("Widnow created.\n");
        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer){
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            printf("Renderer created.\n");
        }
        isRunning = true;
    }
    player_R.x = 64;
    player_R.y = 64;
    player_velocity = 2;
    playerTex = LoadTexture("resource/ast/Bomberman/Bomberman_Front.png", renderer);

    init_slime();

    gScreenSurface = SDL_GetWindowSurface(window);    
}

void handleEvents(){
    SDL_Event event;
    while(SDL_PollEvent(&event) != 0){
        if(event.type == SDL_QUIT) isRunning = false;
        if(event.type == SDL_KEYDOWN){
            switch(event.key.keysym.sym) {
                case SDLK_UP: move_up = true; break;
                case SDLK_DOWN: move_down = true; break;
                case SDLK_LEFT: move_left = true; break;
                case SDLK_RIGHT: move_right = true; break;
                case SDLK_e: Bomb(); break;
            }
        }
        if(event.type == SDL_KEYUP) switch( event.key.keysym.sym ) {
            case SDLK_UP: move_up = false; break;
            case SDLK_DOWN: move_down = false; break;
            case SDLK_LEFT: move_left = false; break;
            case SDLK_RIGHT: move_right = false; break;
        }
    }
}

void update(){ 
    player_R.h = 64;
    player_R.w = 64;

    player_wall_hitbox_R.h = 40;
    player_wall_hitbox_R.w = 26;

    bomb_R.h = 64;
    bomb_R.w = 64;
    
    playerMove(player_velocity);
    slimeMovePro(slime_velocity);
} 

void render(){
    SDL_RenderClear(renderer);
    DrawMap();
    SDL_RenderCopy(renderer, playerTex, NULL, &player_R);
    SDL_RENDERS_SLIMES();
    SDL_RenderCopy(renderer, bombTex, NULL, &bomb_R);
    SDL_RenderPresent(renderer);
}

void clean(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    printf("Game cleaned.\n\n");
}
