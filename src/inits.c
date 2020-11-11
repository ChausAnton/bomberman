#include "../inc/game.h"

void init_sound(int a){
    switch (a)
    {
    case 1:
        step_sound = Mix_LoadWAV( "resource/msc/minecraft_move_on_ground.wav" );
        put_bomb_sound = Mix_LoadWAV( "resource/msc/penetration.wav" );
        backgroundSound = Mix_LoadMUS( "resource/msc/menu_sound.wav");
        explosion_sound = Mix_LoadWAV( "resource/msc/torpedo_explosion.wav" );
        die_sound = Mix_LoadWAV( "resource/msc/autsch-oh-that-hurts.wav" );
        next_door_sound = Mix_LoadWAV( "resource/msc/boynextdoor.wav" );
        die_slime_sound = Mix_LoadWAV("resource/msc/spank-3.wav");
        win_sound = Mix_LoadWAV("resource/msc/win_sound.wav");
        if( backgroundSound== NULL ) printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError());
        break;
    case 2:
        Mix_PlayMusic(backgroundSound, -1);
        break;
    default:
        break;
    }
}

void init_texture(){
    loaded_anim_right[0] = LoadTexture("/resource/ast/Bomberman/Bomberman_MoveRight1.png", renderer);
    loaded_anim_right[1] = LoadTexture("/resource/ast/Bomberman/Bomberman_MoveRight2.png", renderer);
    loaded_anim_right[2] = LoadTexture("/resource/ast/Bomberman/Bomberman_MoveRight3.png", renderer);
    loaded_anim_left[0] = LoadTexture("/resource/ast/Bomberman/Bomberman_MoveLeft1.png", renderer);
    loaded_anim_left[1] = LoadTexture("/resource/ast/Bomberman/Bomberman_MoveLeft2.png", renderer);
    loaded_anim_left[2] = LoadTexture("/resource/ast/Bomberman/Bomberman_MoveLeft3.png", renderer);
    loaded_anim_up[0] = LoadTexture("/resource/ast/Bomberman/Bomberman_MoveUp1.png", renderer);
    loaded_anim_up[1] = LoadTexture("/resource/ast/Bomberman/Bomberman_MoveUp2.png", renderer);
    loaded_anim_up[2] = LoadTexture("/resource/ast/Bomberman/Bomberman_MoveUp3.png", renderer);
    loaded_anim_down[0] = LoadTexture("/resource/ast/Bomberman/Bomberman_MoveDown1.png", renderer);
    loaded_anim_down[1] = LoadTexture("/resource/ast/Bomberman/Bomberman_MoveDown2.png", renderer);
    loaded_anim_down[2] = LoadTexture("/resource/ast/Bomberman/Bomberman_MoveDown3.png", renderer);

    loaded_front = LoadTexture("resource/ast/Bomberman/Bomberman_Front.png", renderer);
    loaded_dead_bomberman = LoadTexture("resource/ast/Bomberman/Bomberman_Dead.png", renderer);
    loaded_bomb = LoadTexture("resource/ast/Bomberman/Bomb1.png", renderer);	
    loaded_menu_heart = LoadTexture("resource/ast/ui/Heart.png", renderer);
    loaded_menu_bomb = LoadTexture("resource/ast/Bomberman/Bomb1.png", renderer);
    loaded_white_bomb = LoadTexture("resource/ast/Bomberman/White_Bomb.png", renderer);
    loaded_explosion = LoadTexture("resource/ast/Bomberman/Explosion.png", renderer);
    loaded_explosion_up = LoadTexture("resource/ast/Bomberman/Explosion_Up.png", renderer);
    loaded_explosion_down = LoadTexture("resource/ast/Bomberman/Explosion_Down.png", renderer);
    loaded_explosion_right = LoadTexture("resource/ast/Bomberman/Explosion_Right.png", renderer);
    loaded_explosion_left = LoadTexture("resource/ast/Bomberman/Explosion_Left.png", renderer);
 
    // Advertising
    loaded_adv = LoadTexture("resource/ast/ui/1414348347_1735167655.png", renderer);

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

    pauseTex = LoadTexture("resource/ast/ui/Pause.png", renderer);

    loaded_playTex = LoadTexture("resource/ast/ui/Play_Button.png", renderer);
    loaded_playTexHover = LoadTexture("resource/ast/ui/Play_Button_MouseOn.png", renderer);
    loaded_playTexPressed = LoadTexture("resource/ast/ui/Play_Button_Click.png", renderer);

    loaded_exitTex = LoadTexture("resource/ast/ui/Exit_Button.png", renderer);
    loaded_exitTexHover = LoadTexture("resource/ast/ui/Exit_Button_MouseOn.png", renderer);
    loaded_exitTexPressed = LoadTexture("resource/ast/ui/Exit_Button_Click.png", renderer);

    introTex = LoadTexture("resource/ast/ui/sss1 (2).png", renderer);
    loaded_back_menu = LoadTexture("/resource/ast/ui/RMT0Kk (1).png", renderer); 

    //Bonuses
    loaded_bonus_hp = LoadTexture("resource/ast/PowerUps/PowerUp_Heart.png", renderer);
    loaded_bonus_time = LoadTexture("resource/ast/PowerUps/PowerUp_Time.png", renderer);
    loaded_bonus_score = LoadTexture("resource/ast/PowerUps/PowerUp_Score.png", renderer);
    //Win
    loaded_win = LoadTexture("resource/ast/ui/win.png", renderer);
    //Door 
    loaded_door = LoadTexture("resource/ast/terrain/Door.png", renderer);

}
