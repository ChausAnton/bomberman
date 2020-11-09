#include "../inc/game.h"

void init_sound(int a){
    switch (a)
    {
    case 1:
        step_sound = Mix_LoadWAV( "resource/msc/minecraft_move_on_ground.wav" );
        put_bomb_sound = Mix_LoadWAV( "resource/msc/penetration.wav" );
        //backgroundSound = Mix_LoadMUS( "/resource/msc/Green Day - Holiday.wav");
        //if( backgroundSound== NULL ) printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError());
        break;
    case 2:
        step_sound = Mix_LoadWAV( "resource/msc/minecraft_move_on_ground.wav" );
        put_bomb_sound = Mix_LoadWAV( "resource/msc/sex.wav" );
        //backgroundSound = Mix_LoadMUS( "/resource/msc/Green Day - Holiday.wav");
        //if( backgroundSound== NULL ) printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError());
        //Mix_PlayMusic(backgroundSound, -1);
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

    ground = LoadTexture("resource/ast/terrain/Ground.png", renderer);
    breakable_stone = LoadTexture("resource/ast/terrain/Breakable_Stone.png", renderer);
    stone = LoadTexture("resource/ast/terrain/Stone.png", renderer);
    // Stone Walls
    up_stone_wall = LoadTexture("resource/ast/terrain/UpStoneWall.png", renderer);
    down_stone_wall = LoadTexture("resource/ast/terrain/DownStoneWall.png", renderer);
    left_stone_wall = LoadTexture("resource/ast/terrain/LeftStoneWall.png", renderer);
    right_stone_wall = LoadTexture("resource/ast/terrain/RightStoneWall.png", renderer);
    // Stone Corners
    up_left_corner = LoadTexture("resource/ast/terrain/UpLeftCorner.png", renderer);
    up_right_corner = LoadTexture("resource/ast/terrain/UpRightCorner.png", renderer);
    down_left_corner = LoadTexture("resource/ast/terrain/DownLeftCorner.png", renderer);
    down_right_corner = LoadTexture("resource/ast/terrain/DownRightCorner.png", renderer);
}
