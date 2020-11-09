#include "../inc/game.h"

int lvl[20][25] = {
    {7,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,8},
    {5,0,0,0,1,1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
    {5,0,1,2,1,1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
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
int index_animetion = 0;

void playerMove(int player_velocity)  {
	int move_time;//For sound_move
    if (move_up && lvl[(player_R.y + 30)/64][(player_R.x + 8)/64] == 0 && lvl[(player_R.y + 30)/64][(player_R.x + 54)/64] == 0) {
		if(player_R.y < 32) player_R.y = 32;
		if(player_R.y > 1152) player_R.y = 1152;
		player_R.y -= player_velocity;
	}
	if (move_down && lvl[(player_R.y + 63)/64][(player_R.x + 8)/64] == 0 && lvl[(player_R.y + 63)/64][(player_R.x + 54)/64] == 0) {
		if(player_R.y < 32) player_R.y = 32;
		if(player_R.y > 1152) player_R.y = 1152;
		player_R.y += player_velocity;
	}
	if (move_right && lvl[(player_R.y + 32)/64][(player_R.x + 56)/64] == 0 && lvl[(player_R.y + 61)/64][(player_R.x + 56)/64] == 0) {
		if(player_R.x < 56) player_R.x = 56;
		if(player_R.x > 1480) player_R.x = 1480;
		player_R.x += player_velocity;
	}
	if (move_left && lvl[(player_R.y + 32)/64][(player_R.x + 6)/64] == 0 && lvl[(player_R.y + 61)/64][(player_R.x + 6)/64] == 0){
		if(player_R.x < 56) player_R.x = 56;
		if(player_R.x > 1480) player_R.x = 1480;
		player_R.x -= player_velocity;
	}
	
	if (move_right) {
		/////////////SoundMove////////////////
		move_time = SDL_GetTicks() - move_start;
		if(move_time > 200){
			Mix_PlayChannel( -1, step_sound, 0 );
			move_start = SDL_GetTicks();
		}
		///////////AnimationMove////////////////
		if (index_animetion < 6)
			playerTex = loaded_anim_right[0];
		else
			playerTex = loaded_anim_right[1];
		index_animetion++;
		if (index_animetion > 12) index_animetion = 0;
	}
	else if (move_left){
		/////////////SoundMove////////////////
		move_time = SDL_GetTicks() - move_start;
		if(move_time > 200){
			Mix_PlayChannel( -1, step_sound, 0 );
			move_start = SDL_GetTicks();
		}
		///////////AnimationMove////////////////
		if (index_animetion < 6)
			playerTex = loaded_anim_left[0];
		else
			playerTex = loaded_anim_left[1];
		index_animetion++;
		if (index_animetion > 12) index_animetion = 0;
	}
	else if (move_up) {
		/////////////SoundMove////////////////
		move_time = SDL_GetTicks() - move_start;
		if(move_time > 200){
			Mix_PlayChannel( -1, step_sound, 0 );
			move_start = SDL_GetTicks();
		}
		///////////AnimationMove////////////////
		if (index_animetion < 6)
			playerTex = loaded_anim_up[0];
		else
			playerTex = loaded_anim_up[1];
		index_animetion++;
		if (index_animetion > 12) index_animetion = 0;
	}
	else if (move_down) {
		/////////////SoundMove////////////////
		move_time = SDL_GetTicks() - move_start;
		if(move_time > 200){
			Mix_PlayChannel( -1, step_sound, 0 );
			move_start = SDL_GetTicks();
		}
		///////////AnimationMove////////////////
		if (index_animetion < 6)
			playerTex = loaded_anim_down[0];
		else
			playerTex = loaded_anim_down[1];
		index_animetion++;
		if (index_animetion > 12) index_animetion = 0;
	}
	else 
		playerTex = LoadTexture("/resource/ast/Bomberman/Bomberman_Front.png", renderer);	
}

void Bomb(){
	//Mix_PauseMusic();
	Mix_PlayChannel( -1, put_bomb_sound, 0 );
	bomb_R.x = player_R.x;
	bomb_R.y = player_R.y;
	bombTex = LoadTexture("resource/ast/Bomberman/Bomb.png", renderer);
}
