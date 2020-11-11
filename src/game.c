#include "../inc/game.h"
#include "../inc/enemy.h"

void init(const char *title, int x_pos, int y_pos, int width, int height, bool fullscreen){
    int flags = 0;
    score_num = 0;
    TTF_Init();
    loaded_bonus = NULL;
    is_win = false;
    if(fullscreen) flags = SDL_WINDOW_FULLSCREEN;
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
        // Music
        Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
        init_sound(1);
        // Window
        window = SDL_CreateWindow(title, x_pos, y_pos, width, height, flags);
        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer){
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        }
        isRunning = true;
    }
    level_num = 1;
    player_hp = 3;
    bonusTime = 0;
    a = 0;
    initGame();
    initMenu();
    initMap();
    menu_score();
    advertising();
    initIntro();
}

void init_timer() {
    char buffer[10];
    timer_start = SDL_GetTicks();
    timer_time = (400 + bonusTime) - (int)((timer_start - a)/1000);

    if(timer_time == 0){
        lose();
    } else if(timer_time < 10) {
        Time_rect.x = 1775;
        Time_rect.y = 705;
        Time_rect.w = 52;
        Time_rect.h = 95;
        Red.r = 220;
        Red.g = 20; 
        Red.b = 60;
    } else if(timer_time < 100) {
        Time_rect.x = 1755;
        Time_rect.y = 703;
        Time_rect.w = 90;
        Time_rect.h = 100;
        Red.r = 219;
        Red.g = 196; 
        Red.b = 46;
    } else if(timer_time > 99) {
        Time_rect.x = 1750;
        Time_rect.y = 700;
        Time_rect.w = 100;
        Time_rect.h = 110;
        Red.r = 50;
        Red.g = 168; 
        Red.b = 145;
    }

    TimeMessage = TTF_RenderText_Solid(arcade, SDL_itoa(timer_time, buffer, 10), Red);
    Time_Message = SDL_CreateTextureFromSurface(renderer, TimeMessage); 
}
void advertising() {
    adv_rect.x = 1610;
    adv_rect.y = 900;
    adv_rect.w = 380;
    adv_rect.h = 320;
}

void initIntro() {
    Mix_PlayMusic(backgroundSound, -1);
    is_intro = true;

    intro_R.w = 2000;
    intro_R.h = 1280;

    play_R.x = 800;
    play_R.y = 580;
    play_R.w = 400;
    play_R.h = 150;

    exit_R.x = 800;
    exit_R.y = 760;
    exit_R.w = 400;
    exit_R.h = 150;    
}

void receiveDamage(){
    playerTex =  loaded_dead_bomberman;
    render();
    SDL_Delay(500);
    player_hp--;
    reset();
}

void menu_score(){
    
    Red.r = 50;
    Red.g = 168; 
    Red.b = 145;

    if(score_num == 0){
        score_num_rect.x = 1775;
        score_num_rect.y = 500;
        score_num_rect.w = 46; 
        score_num_rect.h = 95;
    } else {
        score_num_rect.x = 1765;
        score_num_rect.y = 500;
        score_num_rect.w = 82;
        score_num_rect.h = 100;
    }

    char buffer[10];
    ScoreNumMessage = TTF_RenderText_Solid(arcade, SDL_itoa(score_num, buffer, 10), Red);
    Score_Num_Message = SDL_CreateTextureFromSurface(renderer, ScoreNumMessage); 
}

void initMenu() {
    is_pause = false;

    back_menu_rect.x = 1600;
    back_menu_rect.w = 400; 
    back_menu_rect.h = 1280; 	

    Bonuse_rect.x = 1762;
    Bonuse_rect.y = 320;
    Bonuse_rect.w = 64; 
    Bonuse_rect.h = 64;


    menu_Heart1_R.x = 1670;  
    menu_Heart1_R.y = 115;
    menu_Heart1_R.w = 64; 
    menu_Heart1_R.h = 64;

    menu_Heart2_R.x = 1770;  
    menu_Heart2_R.y = 115;
    menu_Heart2_R.w = 64; 
    menu_Heart2_R.h = 64;

    menu_Heart3_R.x = 1860;  
    menu_Heart3_R.y = 115;
    menu_Heart3_R.w = 64; 
    menu_Heart3_R.h = 64;

    arcade = TTF_OpenFont("resource/ttf/ARCADECLASSIC.TTF", 24);
    
    White.r = 255;
    White.g = 255; 
    White.b = 255;

    healthMessage = TTF_RenderText_Solid(arcade, " H e a lth ", White);
    bombMessage = TTF_RenderText_Solid(arcade, " B o n u s", White);
    scoreMessage = TTF_RenderText_Solid(arcade, " S c o r e ", White); 
    timeMessage = TTF_RenderText_Solid(arcade, " Ti m e r ", White);

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
   is_lose = false;
    player_R.h = 64;
    player_R.w = 64;

    bomb_R.h = 64;
    bomb_R.w = 64;

    player_R.x = 64;
    player_R.y = 64;

    if(level_num == 1) {
        init_slime(3*64, 2*64);
        init_slime(1*64, 8*64);
        init_slime(12*64, 3*64);
        init_slime(4*64, 7*64);
        init_slime(7*64, 8*64);
        init_slime(13*64, 10*64);
        init_slime(10*64, 13*64);
        init_slime(14*64, 17*64);
        init_slime(19*64, 11*64);
        init_slime(17*64, 3*64);
        init_slime(23*64, 13*64);
        init_slime(20*64, 6*64);
    }
    if(level_num ==  2){
        init_slime(7*64, 2*64);
        init_slime(4*64, 7*64);
        init_slime(12*64, 3*64);
        init_slime(8*64, 7*64);
        init_slime(7*64, 8*64);
        init_slime(13*64, 10*64);
        init_slime(10*64, 13*64);
        init_slime(19*64, 11*64);
        init_slime(17*64, 3*64);
        init_slime(19*64, 18*64);
        init_slime(20*64, 6*64);
        init_slime(4*64, 15*64);
        init_slime(7*64, 17*64);
    }
    if(level_num == 3) {
        init_slime((24 - 3)*64, 3*64);
        init_slime((24 - 9)*64, 3*64);
        init_slime(7*64, 2*64);
        init_slime(7*64, 11*64);
        init_slime(12*64, 3*64);
        init_slime(9*64, 7*64);
        init_slime(11*64, 9*64);
        init_slime(13*64, 10*64);
        init_slime(10*64, 14*64);
        init_slime(3*64, 1*64);
        init_slime(17*64, 3*64);
        init_slime(19*64, 18*64);
        init_slime(20*64, 6*64);
        init_slime(1*64, 15*64);
        init_slime(7*64, 17*64);
        init_slime(15*64, (19 - 4)*64);
        init_slime(17*64, (19 - 4)*64);
        init_slime(1*64, 7*64);
        init_slime(24*64, 8*64);
        player_R.x = 5 * 64;
        player_R.y = 18 * 64;
    }

    explosion_R.h = 64;
    explosion_R.w = 64;

    
    player_velocity = 2;
    bomb_power = 1;
    bomb_placed = false;
    playerTex = loaded_front;
    gScreenSurface = SDL_GetWindowSurface(window);
}

void initMap(){
    int lvl1[20][25] = {
    {7,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,8},
    {5,0,1,0,1,1,2,0,1,0,2,0,0,1,0,1,0,0,1,0,0,0,0,0,6},
    {5,0,1,0,1,1,2,0,0,1,0,0,0,2,1,0,2,0,2,2,1,2,1,0,6},
    {5,0,1,0,0,0,0,2,2,1,0,1,0,2,0,0,2,0,1,0,0,0,2,0,6},
    {5,0,2,1,1,0,2,2,0,0,2,2,1,1,0,0,0,2,2,1,0,0,1,1,6},
    {5,1,1,0,0,0,0,0,1,0,0,0,1,2,2,0,0,0,1,0,2,1,2,2,6},
    {5,1,2,1,0,2,0,1,2,2,0,1,0,0,0,2,1,2,2,0,0,0,0,0,6},
    {5,0,1,0,0,2,0,1,0,0,1,1,0,0,1,0,0,0,0,1,2,2,2,1,6},
    {5,0,2,2,0,0,2,0,1,1,0,0,2,0,2,0,2,2,1,0,1,0,1,0,6},
    {5,0,1,1,0,1,1,0,1,1,2,0,1,0,2,0,1,0,0,2,0,0,2,0,6},
    {5,2,2,0,0,0,2,0,2,0,2,0,2,0,0,0,0,2,1,2,1,1,2,0,6},
    {5,0,2,0,1,0,1,0,0,0,0,0,2,2,0,2,0,1,0,0,1,0,1,0,6},
    {5,0,0,0,2,0,0,1,0,0,1,2,0,0,1,0,1,0,0,2,1,2,2,0,6},
    {5,0,2,1,0,2,1,0,0,1,0,1,0,1,0,0,2,0,2,2,0,0,1,0,6},
    {5,0,0,0,1,0,1,2,0,0,0,1,0,0,2,0,1,0,0,1,0,0,2,1,6},
    {5,0,1,0,2,2,0,2,2,1,0,0,0,2,2,0,2,0,2,1,0,2,0,0,6},
    {5,0,2,2,0,1,0,2,0,1,2,1,2,2,1,1,0,0,2,0,2,2,0,2,6},
    {5,0,2,2,0,1,0,1,0,0,0,0,0,1,0,2,1,1,2,2,0,1,1,2,6},
    {5,0,0,0,2,2,0,0,1,2,0,0,2,1,0,0,0,0,0,1,0,2,0,11,6},
    {9,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,10},
    };
    int lvl2[20][25] = {
    {7,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,8},
    {5,0,2,1,0,2,2,1,1,0,0,0,1,1,0,1,0,0,0,2,0,2,0,0,6},
    {5,0,0,1,1,1,0,0,0,1,0,0,0,2,1,0,2,0,2,2,1,2,1,0,6},
    {5,2,2,2,0,0,0,1,2,1,0,1,0,2,0,0,2,0,1,0,0,0,2,0,6},
    {5,1,2,1,2,0,1,2,0,0,2,2,1,1,0,0,0,2,2,1,0,0,1,1,6},
    {5,1,1,0,1,0,0,0,1,0,0,0,1,2,2,0,0,0,1,0,2,1,2,2,6},
    {5,0,2,1,0,2,0,1,0,1,2,2,0,0,0,1,0,1,2,2,0,0,2,0,6},
    {5,1,1,0,0,2,0,1,0,0,1,1,0,0,1,0,0,0,0,1,2,2,2,1,6},
    {5,0,2,2,1,0,1,0,1,1,0,0,2,0,2,0,2,2,1,0,1,0,1,0,6},
    {5,0,1,1,1,1,1,0,1,1,2,0,1,0,2,0,1,0,0,2,0,0,2,0,6},
    {5,2,2,0,0,0,2,0,2,0,0,0,2,0,0,0,2,2,1,0,2,1,2,0,6},
    {5,0,2,0,1,1,0,1,0,1,1,0,2,1,1,2,0,1,0,0,1,0,1,0,6},
    {5,0,1,0,2,0,2,1,0,2,1,2,0,0,1,0,1,0,0,2,1,2,2,0,6},
    {5,0,2,1,0,2,1,0,0,1,0,1,0,1,0,0,2,0,2,0,0,0,1,0,6},
    {5,1,0,2,1,0,1,2,2,0,0,1,0,0,2,0,1,0,0,1,0,0,2,1,6},
    {5,0,2,2,0,0,1,0,2,1,1,1,1,2,2,0,2,0,2,1,0,2,0,0,6},
    {5,0,2,0,0,1,0,2,1,2,2,1,2,2,1,1,0,0,2,0,2,2,0,2,6},
    {5,0,2,1,1,1,0,0,0,0,2,11,1,1,1,2,1,1,2,2,0,1,1,2,6},
    {5,1,0,1,2,2,1,0,2,1,1,1,1,2,0,1,1,0,0,1,0,2,0,0,6},
    {9,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,10},
    };
    int lvl3[20][25] = {
    {7,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,8},
    {5,0,2,0,2,1,2,0,2,0,2,0,2,1,2,1,2,1,2,1,2,1,11,1,6},
    {5,0,1,0,1,1,1,0,0,1,0,0,0,1,1,1,1,0,0,1,1,1,1,1,6},
    {5,1,2,0,2,0,2,1,2,1,2,1,2,1,2,0,2,0,2,0,2,0,2,0,6},
    {5,0,1,1,1,0,0,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,1,1,6},
    {5,1,2,0,2,1,2,0,2,0,2,0,2,1,2,0,2,0,2,0,2,1,2,1,6},
    {5,1,0,1,0,1,0,1,0,0,1,1,1,1,0,1,1,1,1,0,0,0,0,0,6},
    {5,0,2,0,2,1,2,1,2,0,2,1,2,0,2,0,2,0,2,1,2,1,2,1,6},
    {5,0,0,1,0,0,1,0,1,1,0,0,1,0,1,0,1,1,1,0,1,0,1,0,6},
    {5,0,2,1,2,1,2,0,2,1,2,0,2,0,2,0,2,0,2,1,2,0,2,0,6},
    {5,1,0,1,1,0,0,0,1,1,1,0,1,0,0,0,0,1,1,1,1,1,1,0,6},
    {5,1,2,0,2,0,2,0,2,0,2,0,2,1,2,1,2,1,2,0,2,0,2,0,6},
    {5,1,0,0,1,0,0,1,0,0,1,0,0,0,1,0,1,0,1,1,1,1,1,0,6},
    {5,0,2,1,2,0,2,0,2,1,2,1,2,1,2,0,2,0,2,1,2,0,2,0,6},
    {5,0,1,1,1,1,1,1,0,0,0,1,0,0,1,0,1,0,1,1,0,0,1,1,6},
    {5,0,2,0,2,0,2,1,2,1,2,1,2,1,2,0,2,0,2,1,2,1,2,0,6},
    {5,1,0,1,0,1,0,0,0,1,1,1,0,1,1,1,0,0,1,0,1,1,1,1,6},
    {5,1,2,0,2,1,2,1,2,1,2,0,2,1,2,1,2,1,2,1,2,1,2,1,6},
    {5,1,1,0,1,0,0,0,1,0,0,0,1,1,1,1,0,0,0,1,0,1,0,0,6},
    {9,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,10},
    };
    if(level_num == 1)
        LoadMap(lvl1);
    if(level_num == 2)
        LoadMap(lvl2);
    if(level_num == 3)
        LoadMap(lvl3);
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
        if(event.type == SDL_MOUSEMOTION && is_intro) {
            mouseX = event.motion.x;
            mouseY = event.motion.y;
            if (mouseX > 800 && mouseX < 1200 && mouseY > 590 && mouseY < 720) {
                play_Hover = true;          
            }
            else play_Hover = false;

            if (mouseX > 800 && mouseX < 1200 && mouseY > 770 && mouseY < 900) {
                exit_Hover = true;          
            }
            else exit_Hover = false;
        }
        if(event.type == SDL_KEYDOWN && !is_lose && !is_intro){
            switch(event.key.keysym.sym) {
                move_start = SDL_GetTicks();       //Frames start
                case SDLK_UP: move_up = true; break;
                case SDLK_DOWN: move_down = true; break;
                case SDLK_LEFT: move_left = true; break;
                case SDLK_RIGHT: move_right = true; break;
                case SDLK_e: if(!bomb_placed) Bomb(map); break;
                case SDLK_p: 
                    if (!is_pause) {
                        mPausedTicks = SDL_GetTicks();
                        is_pause = true;
                    }
                    else {
                        mStartTicks = SDL_GetTicks() - mPausedTicks;
                        a += mStartTicks;
                        is_pause = false; 
                    }
                    break;
                case SDLK_ESCAPE: 
                    initIntro();
                    break;
            }
        }
        if(event.type == SDL_KEYUP && !is_lose && !is_intro) switch( event.key.keysym.sym ) {
            case SDLK_UP: move_up = false; break;
            case SDLK_DOWN: move_down = false; break;
            case SDLK_LEFT: move_left = false; break;
            case SDLK_RIGHT: move_right = false; break;
        }
        if(event.type == SDL_KEYDOWN && is_lose && !is_intro) switch( event.key.keysym.sym ) {
            case SDLK_r: restart(); break;
        }
        if(is_intro) {
            int mouseX = event.motion.x;
            int mouseY = event.motion.y;
            if (mouseX > 800 && mouseX < 1200 && mouseY > 590 && mouseY < 720) {
                switch (event.button.button){
                    case SDL_BUTTON_LEFT: 
                        Mix_HaltMusic();
                        play_Pressed = true;
                        render();
                        SDL_Delay(200);
                        render();
                        SDL_Delay(200);
                        restart();
                        break;
                }             
            }
            if (mouseX > 800 && mouseX < 1200 && mouseY > 770 && mouseY < 900) {
                switch (event.button.button){
                    case SDL_BUTTON_LEFT: 
                        exit_Pressed = true;
                        render();
                        SDL_Delay(100);
                        render();
                        isRunning = false;
                        break;
                }             
            }
        }
    }
}

void lose() {
    is_lose = true;
    Mix_PlayChannel(-1, die_sound, 0);

    Red.r = 220;
    Red.g = 20; 
    Red.b = 60;

    GameOver = TTF_RenderText_Solid(arcade, "G a m e   O v e r", Red);
    RestartMessage = TTF_RenderText_Solid(arcade, "P r e s s     R     t o    r e s t a r t", Red);
    GameOver_Message = SDL_CreateTextureFromSurface(renderer, GameOver); 
    Restart_Message = SDL_CreateTextureFromSurface(renderer, RestartMessage); 

    Restart_Message_rect.x = 570;  
    Restart_Message_rect.y = 700;
    Restart_Message_rect.w = 900; 
    Restart_Message_rect.h = 140;

    GameOver_Message_rect.x = 600;  
    GameOver_Message_rect.y = 400;
    GameOver_Message_rect.w = 800; 
    GameOver_Message_rect.h = 300;
}

void win() {
    Mix_PlayChannel( -1, win_sound, 0 );
    is_win = true;
    Win_rect.w = 2000;
    Win_rect.h = 1280;
    render();
    SDL_Delay(5000);
    is_win = false;
    initIntro();
}

void addBonus() {
    if (bonus == 1) {
        bonus_start = timer_time;
        loaded_bonus = loaded_bonus_hp;
        if (player_hp < 3) {
            player_hp++;
        }
        else {  
            score_num += 100;
            menu_score();
        }
        render();
    }
	else if (bonus == 2) {
        bonus_start = timer_time;
        bonusTime += 20;
        loaded_bonus = loaded_bonus_time;
    }
	else if (bonus == 3) {
        bonus_start = timer_time;
        loaded_bonus = loaded_bonus_score;
        score_num += 100;
        menu_score();
    }
}

void new_lvl() {
    level_num++;
    loaded_bonus = NULL;
    is_lose = false;
    is_pause = false;
    is_intro = false;
    move_up = false;
    move_down = false;
    move_left = false;
    move_right = false;
    bombTime = 0;
    while(slimes != NULL) {
		mx_pop_index_slime(&slimes, 0);
        score_num -= 200;
        menu_score();
    }
    if(bomb_placed) bombTex = NULL;
    if(explosion_placed) explosionTex = NULL;
    if(level_num > 3) {
        win();
    }else {
    Mix_PlayChannel( -1, next_door_sound, 0 );
    initMenu();
    initMap();
    initGame();
    }

}

void update(){
    if((bonus_start - timer_time) >= 2)
        loaded_bonus = NULL;
    playerMove(player_velocity, map);
    slimeMove(slime_velocity);  
    if ((bomb_placed || explosion_placed) && bombTime < 2600) bombTime = SDL_GetTicks() - (bombStart + mStartTicks);
    if (bomb_placed && bombTime > 2000) boom(bomb_power, map);       
    if (bombTime > 2500) {
        explosion_placed = false;
        bombTime = 0;
        bomb_R.x = 0;
        bomb_R.y = 0;
    }
    if (player_hp < 1) {
        
        lose();
        return;
    }
} 

void render(){
    if(is_intro){
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, introTex, NULL, &intro_R);

        if (play_Hover) playTex = loaded_playTexHover;
        else playTex = loaded_playTex;
        if (play_Pressed) { play_Pressed = false; playTex = loaded_playTexPressed; }
        SDL_RenderCopy(renderer, playTex, NULL, &play_R);

        if (exit_Hover) exitTex = loaded_exitTexHover;
        else exitTex = loaded_exitTex;
        if (exit_Pressed) { exit_Pressed = false; exitTex = loaded_exitTexPressed; }
        SDL_RenderCopy(renderer, exitTex, NULL, &exit_R);

        SDL_RenderPresent(renderer);
    }
    else if(is_pause){
        SDL_RenderClear(renderer);
        DrawMap();
        SDL_RENDERS_SLIMES();
        if(explosion_placed) explosionAnimation(bomb_power, map);
        SDL_RenderCopy(renderer, playerTex, NULL, &player_R);
        if(bomb_placed) SDL_RenderCopy(renderer, bombTex, NULL, &bomb_R);
        SDL_RenderCopy(renderer, pauseTex, NULL, &pause_R);
        SDL_RenderCopy(renderer, loaded_back_menu, NULL, &back_menu_rect);
        if (player_hp >= 1) SDL_RenderCopy(renderer, loaded_menu_heart, NULL, &menu_Heart1_R);
        if (player_hp >= 2) SDL_RenderCopy(renderer, loaded_menu_heart, NULL, &menu_Heart2_R);
        if (player_hp >= 3) SDL_RenderCopy(renderer, loaded_menu_heart, NULL, &menu_Heart3_R);
        SDL_RenderCopy(renderer, loaded_menu_bomb, NULL, &menu_Bomb_R);
        SDL_RenderCopy(renderer, h_Message, NULL, &h_Message_rect);
        SDL_RenderCopy(renderer, b_Message, NULL, &b_Message_rect);
        SDL_RenderCopy(renderer, s_Message, NULL, &s_Message_rect);
        SDL_RenderCopy(renderer, t_Message, NULL, &t_Message_rect);
        SDL_RenderCopy(renderer, Time_Message, NULL, &Time_rect);
        SDL_RenderCopy(renderer, Score_Num_Message, NULL, &score_num_rect);
        SDL_RenderCopy(renderer, loaded_adv, NULL, &adv_rect);
        if(loaded_bonus != NULL) SDL_RenderCopy(renderer, loaded_bonus, NULL, &Bonuse_rect);//////////////
        SDL_RenderPresent(renderer);
    }
    else if (is_lose) {
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, GameOver_Message, NULL, &GameOver_Message_rect);
        SDL_RenderCopy(renderer, Restart_Message, NULL, &Restart_Message_rect);
        SDL_RenderPresent(renderer);
    } else if(is_win){
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, loaded_win, NULL, &Win_rect);
        SDL_RenderPresent(renderer);
    } else {
        SDL_RenderClear(renderer);
        DrawMap();
        SDL_RENDERS_SLIMES();
        if(bomb_placed) bombAnimation();
        if(explosion_placed) explosionAnimation(bomb_power, map);
        SDL_RenderCopy(renderer, playerTex, NULL, &player_R);
        if(bomb_placed) SDL_RenderCopy(renderer, bombTex, NULL, &bomb_R);
        SDL_RenderCopy(renderer, loaded_back_menu, NULL, &back_menu_rect);
        if (player_hp >= 1) SDL_RenderCopy(renderer, loaded_menu_heart, NULL, &menu_Heart1_R);
        if (player_hp >= 2) SDL_RenderCopy(renderer, loaded_menu_heart, NULL, &menu_Heart2_R);
        if (player_hp >= 3) SDL_RenderCopy(renderer, loaded_menu_heart, NULL, &menu_Heart3_R);
        SDL_RenderCopy(renderer, loaded_menu_bomb, NULL, &menu_Bomb_R);
        SDL_RenderCopy(renderer, h_Message, NULL, &h_Message_rect);
        SDL_RenderCopy(renderer, b_Message, NULL, &b_Message_rect);
        SDL_RenderCopy(renderer, s_Message, NULL, &s_Message_rect);
        SDL_RenderCopy(renderer, t_Message, NULL, &t_Message_rect);
        SDL_RenderCopy(renderer, Time_Message, NULL, &Time_rect);
        SDL_RenderCopy(renderer, Score_Num_Message, NULL, &score_num_rect);
        SDL_RenderCopy(renderer, loaded_adv, NULL, &adv_rect);
        if(loaded_bonus != NULL) SDL_RenderCopy(renderer, loaded_bonus, NULL, &Bonuse_rect);
        SDL_RenderPresent(renderer);
    }
}

void clean(){   
    // Free loaded sounds
    Mix_FreeMusic(backgroundSound);
    backgroundSound = NULL;
    Mix_FreeChunk(put_bomb_sound);
    put_bomb_sound = NULL;
    Mix_FreeChunk(step_sound);
    step_sound = NULL; 

    

    // Free loaded text
    SDL_FreeSurface(GameOver);
    SDL_FreeSurface(healthMessage);
    SDL_FreeSurface(timeMessage);
    SDL_FreeSurface(scoreMessage);
    SDL_FreeSurface(bombMessage);

    // Free Loaded textures
    SDL_DestroyTexture(loaded_front);
    SDL_DestroyTexture(loaded_bomb);
    SDL_DestroyTexture(loaded_explosion);
    SDL_DestroyTexture(loaded_menu_bomb);
    SDL_DestroyTexture(loaded_white_bomb);
    SDL_DestroyTexture(h_Message);
    SDL_DestroyTexture(t_Message);
    SDL_DestroyTexture(b_Message);
    SDL_DestroyTexture(s_Message);
    if(!is_intro) SDL_DestroyTexture(playerTex);

    SDL_DestroyRenderer(renderer);
    renderer = NULL;

    SDL_DestroyWindow(window);
    window =  NULL;    

    Mix_Quit();
    IMG_Quit();
    TTF_Quit();
    SDL_Quit();
}

void reset() {
    loaded_bonus = NULL;
    is_lose = false;
    is_pause = false;
    is_intro = false;
    move_up = false;
    move_down = false;
    move_left = false;
    move_right = false;
    bombTime = 0;
    while(slimes != NULL) {
		mx_pop_index_slime(&slimes, 0);
    }
    score_num = 0;
    menu_score();
    if(bomb_placed) bombTex = NULL;
    if(explosion_placed) explosionTex = NULL;

    initMenu();
    initMap();
    initGame();
}

void restart(){
    loaded_bonus = NULL;
    bonusTime = 0;
    level_num = 1;
    is_lose = false;
    is_pause = false;
    is_intro = false;
    move_up = false;
    move_down = false;
    move_left = false;
    move_right = false;
    bombTime = 0;
    while(slimes != NULL) {
		mx_pop_index_slime(&slimes, 0);
    }
    if(bomb_placed) bombTex = NULL;
    if(explosion_placed) explosionTex = NULL;
    player_hp = 3;

    a = SDL_GetTicks();
    Mix_FreeChunk(die_sound);
    die_sound = NULL;
    initMenu();
    initMap();
    initGame();
    init_sound(1);
    score_num = 0;
    menu_score();
}
