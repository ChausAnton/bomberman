#include "../inc/game.h"
void init(const char *title, int x_pos, int y_pos, int width, int height, bool fullscreen){
    int flags = 0;
    if(fullscreen) flags = SDL_WINDOW_FULLSCREEN;
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
        printf("\nTerminal Handler initialized.\n\n");
        printf("Subsystems initialized.\n");
        // Music
        Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
        init_sound(1);
        // Window and Renderer
        //Load texture
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

    init_slime();

    playerTex = LoadTexture("resource/ast/Bomberman/Bomberman_Front.png", renderer);
    gScreenSurface = SDL_GetWindowSurface(window);    
}

void handleEvents(){
    SDL_Event event;
    while(SDL_PollEvent(&event) != 0){
        if(event.type == SDL_QUIT) isRunning = false;
        if(event.type == SDL_KEYDOWN){
            switch(event.key.keysym.sym) {
                move_start = SDL_GetTicks();///////////////Frames start
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

    bomb_R.h = 64;
    bomb_R.w = 64;
    
    playerMove(player_velocity);
    slimeMove(slime_velocity);
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
    //playerTex.free();////Free loaded images
    Mix_FreeMusic( backgroundSound );
    backgroundSound = NULL;
    Mix_FreeChunk( put_bomb_sound );
    put_bomb_sound = NULL;
     Mix_FreeChunk( step_sound );
    step_sound = NULL;
    /////////////////////////
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    window =  NULL;
    renderer = NULL;
    Mix_Quit();
    IMG_Quit();
    SDL_Quit();
    printf("Game cleaned.\n\n");
}
