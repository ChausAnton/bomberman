#include "../inc/game.h"
#include "../inc/enemy.h"

void init(const char *title, int x_pos, int y_pos, int width, int height, bool fullscreen){
    int flags = 0;
    TTF_Init();
    if(fullscreen) flags = SDL_WINDOW_FULLSCREEN;
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
        printf("\nTerminal Handler initialized.\n\n");
        printf("Subsystems initialized.\n");
        // Music
        Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
        init_sound(1);
        // Window
        window = SDL_CreateWindow(title, x_pos, y_pos, width, height, flags);
        if(window) printf("Window created.\n");
        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer){
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
            printf("Renderer created.\n");
        }
        isRunning = true;
    }
    initGame();
}
void init_menu() {
    menubombTex = LoadTexture("resource/ast/Bomberman/Bomb.png", renderer);	
    menu_bomb_R.x = 1610;  
    menu_bomb_R.y = 310;
    menu_bomb_R.w = 70; 
    menu_bomb_R.h = 70; 

    arcade = TTF_OpenFont("resource/ttf/ARCADECLASSIC.TTF", 24);
    
    White.r = 255;
    White.g = 255; 
    White.b = 255;

    healthMessage = TTF_RenderText_Solid(arcade, " H e a l t h ", White);
    bombMessage = TTF_RenderText_Solid(arcade, " B o m b s ", White);
    scoreMessage = TTF_RenderText_Solid(arcade, " S c o r e ", White); 
    timeMessage = TTF_RenderText_Solid(arcade, " T i m e ", White);

    h_Message = SDL_CreateTextureFromSurface(renderer, healthMessage); 
    h_Message_rect.x = 1600;  
    h_Message_rect.y = 0;
    h_Message_rect.w = 400; 
    h_Message_rect.h = 100;  

    b_Message = SDL_CreateTextureFromSurface(renderer, bombMessage); 
    b_Message_rect.x = 1600;  
    b_Message_rect.y = 200;
    b_Message_rect.w = 400; 
    b_Message_rect.h = 100;   

    s_Message = SDL_CreateTextureFromSurface(renderer, scoreMessage); 
    s_Message_rect.x = 1600;  
    s_Message_rect.y = 400;
    s_Message_rect.w = 400; 
    s_Message_rect.h = 100;

    t_Message = SDL_CreateTextureFromSurface(renderer, timeMessage); 
    t_Message_rect.x = 1600;  
    t_Message_rect.y = 600;
    t_Message_rect.w = 400; 
    t_Message_rect.h = 100;     

    background_R.w = 1600;
    background_R.h = 1280;
}

void initGame() {

    init_menu();

    init_slime(196, 128);
    init_slime(64, 8*64);
    
    exp_R.h = 64;
    exp_R.w = 64;

    player_R.x = 64;
    player_R.y = 64;
    player_velocity = 2;
    bomb_power = 1;
    bomb_placed = false;
    playerTex = loaded_font;
    gScreenSurface = SDL_GetWindowSurface(window);

    int lvl1[20][25] = {
    {7,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,8},
    {5,0,0,0,1,1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
    {5,0,1,0,1,1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
    {5,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
    {5,0,2,1,1,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
    {5,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
    {5,1,1,1,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
    {5,0,1,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
    {5,0,2,2,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
    {5,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
    {5,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
    {5,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
    {5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
    {5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
    {5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
    {5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
    {5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
    {5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
    {5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
    {9,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,10},
    };
    LoadMap(lvl1);
}

void LoadMap(int arr[20][25]){
    for(int row = 0; row < 20; ++row)
        for(int column = 0; column < 25; ++column)
            map[row][column] = arr[row][column];
}

void handleEvents(){
    SDL_Event event;
    while(SDL_PollEvent(&event) != 0){
        if(event.type == SDL_QUIT) isRunning = false;
        if(event.type == SDL_KEYDOWN){
            switch(event.key.keysym.sym) {
                move_start = SDL_GetTicks();       //Frames start
                case SDLK_UP: move_up = true; break;
                case SDLK_DOWN: move_down = true; break;
                case SDLK_LEFT: move_left = true; break;
                case SDLK_RIGHT: move_right = true; break;
                case SDLK_e: if(!bomb_placed) { Bomb(map); bomb_placed = true;} break;
                case SDLK_ESCAPE: if (!is_pause) {
                    mPausedTicks = SDL_GetTicks();
                    pauseMenu();
                    is_pause = true;
                    SDL_RenderCopy(renderer, b_Tex, NULL, &background_R);
                    SDL_RenderPresent(renderer); break;}
                                else {
                                    mStartTicks = SDL_GetTicks() - mPausedTicks;
                                    is_pause = false; break;
                                    }
                case SDLK_1: init_sound(1); break;
                case SDLK_2: init_sound(2); break;
                case SDLK_3: lose(); break;
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

void lose() {
    arcade = TTF_OpenFont("resource/ttf/ARCADECLASSIC.TTF", 24);
    printf("%s\n", "1111111");
    Red.r = 220;
    Red.g = 20; 
    Red.b = 60;

    GameOver = TTF_RenderText_Solid(arcade, "G a m e   O v e r", Red);
    GameOver_Message = SDL_CreateTextureFromSurface(renderer, GameOver); 

    printf("%s\n", "22222222");

    GameOver_Message_rect.x = 500;  
    GameOver_Message_rect.y = 340;
    GameOver_Message_rect.w = 800; 
    GameOver_Message_rect.h = 300;
    if (!is_pause) {
        printf("%s\n", "33333333");
        mPausedTicks = SDL_GetTicks();
        printf("%s\n", "444444444");
        pauseMenu();
        printf("%s\n", "555555555");
        //SDL_RenderCopy(renderer, GameOver_Message, NULL, &GameOver_Message_rect);
        //SDL_RenderPresent(renderer);
        printf("%s\n", "6666666666");
        is_pause = true;
    }
     else {
        printf("%s\n", "777777777");
        mStartTicks = SDL_GetTicks() - mPausedTicks;
        is_pause = false;
    }
    
    SDL_RenderCopy(renderer, GameOver_Message, NULL, &GameOver_Message_rect);
    SDL_RenderPresent(renderer);
}

void update(){   
    player_R.h = 64;
    player_R.w = 64;

    bomb_R.h = 64;
    bomb_R.w = 64;

    playerMove(player_velocity, map);
    slimeMove(slime_velocity);    
    if(bomb_placed){
        bombTime = SDL_GetTicks() - (bombStart + mStartTicks);
        if(bombTime > 3000) boom(bomb_power, map);        
    }
} 

void render(){
    SDL_RenderClear(renderer);
    DrawMap();
    SDL_RENDERS_SLIMES();
    SDL_RenderCopy(renderer, playerTex, NULL, &player_R);
    SDL_RenderCopy(renderer, bombTex, NULL, &bomb_R);
    SDL_RenderCopy(renderer, menubombTex, NULL, &menu_bomb_R);
    SDL_RenderCopy(renderer, h_Message, NULL, &h_Message_rect);
    SDL_RenderCopy(renderer, b_Message, NULL, &b_Message_rect);
    SDL_RenderCopy(renderer, s_Message, NULL, &s_Message_rect);
    SDL_RenderCopy(renderer, t_Message, NULL, &t_Message_rect);
    //SDL_RenderCopy(renderer, GameOver_Message, NULL, &GameOver_Message_rect);
    
    SDL_RenderPresent(renderer);
}

void clean(){   
    // Free loaded sounds
    Mix_FreeMusic(backgroundSound);
    backgroundSound = NULL;
    Mix_FreeChunk(put_bomb_sound);
    put_bomb_sound = NULL;
    Mix_FreeChunk(step_sound);
    step_sound = NULL; 

    SDL_DestroyWindow(window);
    window =  NULL;    
    SDL_DestroyRenderer(renderer);
    renderer = NULL;
    Mix_Quit();
    IMG_Quit();
    SDL_Quit();
    printf("Game cleaned.\n\n");
}

void restart(){
    mx_pop_index_slime(&slimes, 0);
    mx_pop_index_slime(&slimes, 0);
    SDL_DestroyTexture(bombTex);
    bombTex = NULL;
    SDL_RenderClear(renderer);
    initGame();
}
void pauseMenu(){
    //restart();
}
