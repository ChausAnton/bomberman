#include "../inc/game.h"

void init_sound(int a){
    switch (a)
    {
    case 1:
        step_sound = Mix_LoadWAV( "resource/msc/minecraft_move_on_ground.wav" );
        put_bomb_sound = Mix_LoadWAV( "resource/msc/penetration.wav" );
        backgroundSound = Mix_LoadMUS( "/resource/msc/Green Day - Holiday.wavvgyb");
        if( backgroundSound== NULL ) printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError());
        break;
    case 2:
        step_sound = Mix_LoadWAV( "resource/msc/minecraft_move_on_ground.wav" );
        put_bomb_sound = Mix_LoadWAV( "resource/msc/sex.wav" );
        backgroundSound = Mix_LoadMUS( "/resource/msc/Green Day - Holiday.wavqwewq");
        if( backgroundSound== NULL ) printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError());
        Mix_PlayMusic(backgroundSound, -1);
        break;
    default:
        break;
    }
}

void init_texture(){
    loaded_anim_right[0] = LoadTexture("/resource/ast/Bomberman/Bomberman_MoveRight1.png", renderer);
    loaded_anim_right[1] = LoadTexture("/resource/ast/Bomberman/Bomberman_MoveRight2.png", renderer);
    loaded_anim_left[0] = LoadTexture("/resource/ast/Bomberman/Bomberman_MoveLeft1.png", renderer);
    loaded_anim_left[1] = LoadTexture("/resource/ast/Bomberman/Bomberman_MoveLeft1.png", renderer);
    loaded_anim_up[0] = LoadTexture("/resource/ast/Bomberman/Bomberman_MoveUp1.png", renderer);
    loaded_anim_up[1] = LoadTexture("/resource/ast/Bomberman/Bomberman_MoveUp1.png", renderer);
    loaded_anim_down[0] = LoadTexture("/resource/ast/Bomberman/Bomberman_MoveDown1.png", renderer);
    loaded_anim_down[1] = LoadTexture("/resource/ast/Bomberman/Bomberman_MoveDown1.png", renderer);
}
