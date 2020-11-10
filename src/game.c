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
    a = 0;
    initGame();
}

void init_timer() {
    Red.r = 235;
    Red.g = 94; 
    Red.b = 52;

    Time_rect.x = 1670;
    Time_rect.y = 710;
    Time_rect.w = 40;
    Time_rect.h = 70;

    char buffer[10];

    timer_time = 200 - (timer_start - a)/1000;
    if(timer_time > 9){
        Time_rect.x = 1670;
        Time_rect.y = 705;
        Time_rect.w = 60;
        Time_rect.h = 75;
    }
    if(timer_time > 99){
        Time_rect.x = 1670;
        Time_rect.y = 700;
        Time_rect.w = 70;
        Time_rect.h = 80;
    }

    TimeMessage = TTF_RenderText_Solid(arcade, SDL_itoa(timer_time, buffer, 10), Red);
    Time_Message = SDL_CreateTextureFromSurface(renderer, TimeMessage); 
}

void initIntro() {
   // is_intro = false;

    ///intro_R.w = 2000;
    //intro_R.h = 1280;
}
void initMenu() {
    is_pause = false;
    	
    menu_Bomb_R.x = 1620;  
    menu_Bomb_R.y = 320;
    menu_Bomb_R.w = 64; 
    menu_Bomb_R.h = 64; 

    arcade = TTF_OpenFont("resource/ttf/ARCADECLASSIC.TTF", 24);
    
    White.r = 255;
    White.g = 255; 
    White.b = 255;

    healthMessage = TTF_RenderText_Solid(arcade, " H e a lth ", White);
    bombMessage = TTF_RenderText_Solid(arcade, " B o m b s ", White);
    scoreMessage = TTF_RenderText_Solid(arcade, " S c o r e ", White); 
    timeMessage = TTF_RenderText_Solid(arcade, " Ti m e ", White);

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

    pause_R.w = 1600;
    pause_R.h = 1280;
}

void initGame() {

    initMenu();
    init_timer();
    LoseGame = 0;
    player_R.h = 64;
    player_R.w = 64;

    bomb_R.h = 64;
    bomb_R.w = 64;

    init_slime(196, 128);
    init_slime(64, 8*64);

    explosion_R.h = 64;
    explosion_R.w = 64;

    player_R.x = 64;
    player_R.y = 64;
    player_velocity = 2;
    bomb_power = 1;
    bomb_placed = false;
    playerTex = loaded_front;
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
                    a = SDL_GetTicks();
                    is_pause = true;
                    SDL_RenderCopy(renderer, pauseTex, NULL, &pause_R);
                    SDL_RenderPresent(renderer); break;}
                                else {
                                    a = SDL_GetTicks() - mPausedTicks;
                                    mStartTicks = SDL_GetTicks() - mPausedTicks;
                                    is_pause = false; break;
                                    }
                case SDLK_1: init_sound(1); break;
                case SDLK_2: init_sound(2); break;
                case SDLK_r: restart(); break;
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
    LoseGame = 1;
    Mix_PlayChannel(-1, die_sound, 0);

    Red.r = 220;
    Red.g = 20; 
    Red.b = 60;

    GameOver = TTF_RenderText_Solid(arcade, "G a m e   O v e r", Red);
    GameOver_Message = SDL_CreateTextureFromSurface(renderer, GameOver); 

    GameOver_Message_rect.x = 500;  
    GameOver_Message_rect.y = 340;
    GameOver_Message_rect.w = 800; 
    GameOver_Message_rect.h = 300;
    is_pause = true;
    render();
}

void update(){   
    playerMove(player_velocity, map);
    slimeMove(slime_velocity);    
    if(bomb_placed){
        bombAnimation();
        bombTime = SDL_GetTicks() - (bombStart + mStartTicks);
        if(bombTime > 3000) boom(bomb_power, map);        
    }
    else if(bombTime > 3000) {
        bombTime = SDL_GetTicks() - (bombStart + mStartTicks);
        if(bombTime < 3500 && explosion_placed);
        else {
            bombTime = 0;
            bomb_R.x = 0;
		    bomb_R.y = 0;
        }
    }
} 

void render(){
    /*if(is_intro){

    }
    else  if(is_intro){
        
    }*/
    SDL_RenderClear(renderer);
    DrawMap();
    SDL_RENDERS_SLIMES();
    explosionAnimation(bomb_power, map);
    SDL_RenderCopy(renderer, playerTex, NULL, &player_R);
    SDL_RenderCopy(renderer, bombTex, NULL, &bomb_R);
    SDL_RenderCopy(renderer, loaded_menu_bomb, NULL, &menu_Bomb_R);
    SDL_RenderCopy(renderer, h_Message, NULL, &h_Message_rect);
    SDL_RenderCopy(renderer, b_Message, NULL, &b_Message_rect);
    SDL_RenderCopy(renderer, s_Message, NULL, &s_Message_rect);
    SDL_RenderCopy(renderer, t_Message, NULL, &t_Message_rect);
    SDL_RenderCopy(renderer, Time_Message, NULL, &Time_rect);
    if(LoseGame == 1)
        SDL_RenderCopy(renderer, GameOver_Message, NULL, &GameOver_Message_rect);
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
    
    // Free window
    SDL_DestroyWindow(window);
    window =  NULL;    
    SDL_DestroyRenderer(renderer);
    renderer = NULL;

    ///Free loaded text
    SDL_FreeSurface(GameOver);
    SDL_FreeSurface(healthMessage);
    SDL_FreeSurface(timeMessage);
    SDL_FreeSurface(scoreMessage);
    SDL_FreeSurface(bombMessage);

    //Free Loaded textures
    SDL_DestroyTexture(loaded_front);
    SDL_DestroyTexture(loaded_bomb);
    SDL_DestroyTexture(loaded_explosion);
    SDL_DestroyTexture(loaded_menu_bomb);
    SDL_DestroyTexture(loaded_white_bomb);
    SDL_DestroyTexture(h_Message);
    SDL_DestroyTexture(t_Message);
    SDL_DestroyTexture(b_Message);
    SDL_DestroyTexture(s_Message);
    SDL_DestroyTexture(GameOver_Message);
    SDL_DestroyTexture(playerTex);
    SDL_DestroyTexture(bombTex);

    Mix_Quit();
    IMG_Quit();
    SDL_Quit();
    TTF_Quit();
    printf("Game cleaned.\n\n");
}

void restart(){
    a =  SDL_GetTicks();
    //timer_start = SDL_GetTicks() - a;
    timer_time = 0;
    LoseGame = 0;
    is_pause = false;
	while(slimes != NULL) {
		mx_pop_index_slime(&slimes, 0);
    }
    SDL_DestroyTexture(bombTex);
    bombTex = NULL;
    SDL_RenderClear(renderer);
    initGame();
}
void pauseMenu(){
    //restart();
}
