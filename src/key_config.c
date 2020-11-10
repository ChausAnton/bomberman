#include "../inc/key_config.h"
#include "../inc/map.h"
#include "../inc/enemy.h"

int bomb_index_animation = 0;
int loaded_explosion_index_animation = 0;
int index_animation = 0;

void playerMove(int player_velocity, int map[20][25]){
	int move_time; // For sound_move
    if (move_up && map[(player_R.y + 30)/64][(player_R.x + 8)/64] == 0 && map[(player_R.y + 30)/64][(player_R.x + 54)/64] == 0) {
		t_slime *cur_slime = slimes;
	 	bool crossing = false;
		for (int i = 0; cur_slime != NULL; i++) {
			int x_slime = cur_slime->slime_R.x;
			int y_slime = cur_slime->slime_R.y;
			int temp = (x_slime - player_R.x);
			if (temp < 0 ) temp = temp * -1;
			if( temp < 42) {
				if ((y_slime + 40) != player_R.y);
				else crossing = true;
			}
			cur_slime = cur_slime->next;
		}
		if (crossing == false) {
			if(player_R.y < 32) player_R.y = 32;
			if(player_R.y > 1152) player_R.y = 1152;
			player_R.y -= player_velocity;
		}
	}
	if (move_down && map[(player_R.y + 63)/64][(player_R.x + 8)/64] == 0 && map[(player_R.y + 63)/64][(player_R.x + 54)/64] == 0) {
		t_slime *cur_slime = slimes;
	 	bool crossing = false;
		for (int i = 0; cur_slime != NULL; i++) {
			int x_slime = cur_slime->slime_R.x;
			int y_slime = cur_slime->slime_R.y;
			int temp = (x_slime - player_R.x);
			if (temp < 0 ) temp = temp * -1;
			if( temp < 42) {
				if ((y_slime) != player_R.y + 40);
				else crossing = true;
			}
			cur_slime = cur_slime->next;
		}
		if (crossing == false) {
			if(player_R.y < 32) player_R.y = 32;
			if(player_R.y > 1152) player_R.y = 1152;
			player_R.y += player_velocity;
		}
	}
	if (move_right && map[(player_R.y + 32)/64][(player_R.x + 56)/64] == 0 && map[(player_R.y + 61)/64][(player_R.x + 56)/64] == 0) {
		t_slime *cur_slime = slimes;
	 	bool crossing = false;
		for (int i = 0; cur_slime != NULL; i++) {
			int x_slime = cur_slime->slime_R.x;
			int y_slime = cur_slime->slime_R.y;
			int temp = (y_slime - player_R.y);
			if (temp < 0 ) temp = temp * -1;
			if( temp < 42) {
				if (x_slime != (player_R.x + 40));
				else crossing = true;
			}
			cur_slime = cur_slime->next;
		}
		if (crossing == false) {
			if(player_R.x < 56) player_R.x = 56;
			if(player_R.x > 1480) player_R.x = 1480;
			player_R.x += player_velocity;
		}
	}
	if (move_left && map[(player_R.y + 32)/64][(player_R.x + 6)/64] == 0 && map[(player_R.y + 61)/64][(player_R.x + 6)/64] == 0){
		t_slime *cur_slime = slimes;
	 	bool crossing = false;
		for (int i = 0; cur_slime != NULL; i++) {
			int x_slime = cur_slime->slime_R.x;
			int y_slime = cur_slime->slime_R.y;
			int temp = (y_slime - player_R.y);
			if (temp < 0 ) temp = temp * -1;
			if( temp < 42) {
				if ((x_slime + 40) != player_R.x);
				else crossing = true;
			}
			cur_slime = cur_slime->next;
		}
		if (crossing == false) {
			if(player_R.x < 56) player_R.x = 56;
			if(player_R.x > 1480) player_R.x = 1480;
			player_R.x -= player_velocity;
		}
	}

	if (move_right) {
		/////////////SoundMove////////////////
		move_time = SDL_GetTicks() - move_start;
		if(move_time > 200){
			Mix_PlayChannel( -1, step_sound, 0 );
			move_start = SDL_GetTicks();
		}
		///////////AnimationMove////////////////
		if (index_animation < 6)
			playerTex = loaded_anim_right[0];
		else
			playerTex = loaded_anim_right[1];
		index_animation++;
		if (index_animation > 12) index_animation = 0;
	}
	else if (move_left){
		/////////////SoundMove////////////////
		move_time = SDL_GetTicks() - move_start;
		if(move_time > 200){
			Mix_PlayChannel( -1, step_sound, 0 );
			move_start = SDL_GetTicks();
		}
		///////////AnimationMove////////////////
		if (index_animation < 6)
			playerTex = loaded_anim_left[0];
		else
			playerTex = loaded_anim_left[1];
		index_animation++;
		if (index_animation > 12) index_animation = 0;
	}
	else if (move_up) {
		/////////////SoundMove////////////////
		move_time = SDL_GetTicks() - move_start;
		if(move_time > 200){
			Mix_PlayChannel( -1, step_sound, 0 );
			move_start = SDL_GetTicks();
		}
		///////////AnimationMove////////////////
		if (index_animation < 6)
			playerTex = loaded_anim_up[0];
		else
			playerTex = loaded_anim_up[1];
		index_animation++;
		if (index_animation > 12) index_animation = 0;
	}
	else if (move_down) {
		/////////////SoundMove////////////////
		move_time = SDL_GetTicks() - move_start;
		if(move_time > 200){
			Mix_PlayChannel( -1, step_sound, 0 );
			move_start = SDL_GetTicks();
		}
		///////////AnimationMove////////////////
		if (index_animation < 6)
			playerTex = loaded_anim_down[0];
		else
			playerTex = loaded_anim_down[1];
		index_animation++;
		if (index_animation > 12) index_animation = 0;
	}
	else 
		playerTex = loaded_anim_down[0];	
}

void Bomb(){
	Mix_PlayChannel(-1, put_bomb_sound, 0);
	bombStart = SDL_GetTicks();
	bomb_R.x = (((player_R.x + 32) / 64) * 64);
	bomb_R.y = (((player_R.y + 32) / 64) * 64);
	//bombTex = loaded_bomb;
}

void bombAnimation(){
	if(bomb_index_animation < 20) bombTex = loaded_bomb;	
	else bombTex = loaded_white_bomb;
	if(bomb_index_animation > 40) bomb_index_animation = 0;
	bomb_index_animation++;
}

void explosionAnimation(int bomb_power, int map[20][25]){
	if (bombTime > 3000 && bombTime < 3500){
	if (map[(bomb_R.y) / 64][bomb_R.x / 64] == 1 || map[(bomb_R.y) / 64][bomb_R.x / 64] == 0){
		explosion_R.x = bomb_R.x;
  		explosion_R.y = bomb_R.y;
		SDL_RenderCopy(renderer, loaded_explosion, NULL, &explosion_R);   
 	 }//center
 	if (map[(bomb_R.y / 64) - bomb_power][bomb_R.x / 64] == 1 || map[(bomb_R.y / 64) - bomb_power][bomb_R.x / 64] == 0){
		explosion_R.x = bomb_R.x;
  		explosion_R.y = bomb_R.y - bomb_power*64;
		SDL_RenderCopy(renderer, loaded_explosion, NULL, &explosion_R); 
 	 }//up
 	if (map[(bomb_R.y / 64) + bomb_power][bomb_R.x / 64] == 1 || map[(bomb_R.y / 64) + bomb_power][bomb_R.x / 64] == 0 ){ 
		explosion_R.x = bomb_R.x;
  		explosion_R.y = bomb_R.y + bomb_power*64;
		SDL_RenderCopy(renderer, loaded_explosion, NULL, &explosion_R); 
  	}//down
 	if (map[bomb_R.y / 64][(bomb_R.x / 64) + bomb_power] == 1 || map[bomb_R.y / 64][(bomb_R.x / 64) + bomb_power] == 0 ){
		explosion_R.x = bomb_R.x + bomb_power*64;
  		explosion_R.y = bomb_R.y;
		SDL_RenderCopy(renderer, loaded_explosion, NULL, &explosion_R); 
  	} //right
 	if (map[bomb_R.y / 64][(bomb_R.x / 64) - bomb_power] == 1|| map[bomb_R.y / 64][(bomb_R.x / 64) - bomb_power] == 0){
		explosion_R.x = bomb_R.x - bomb_power*64;
  		explosion_R.y = bomb_R.y;
		SDL_RenderCopy(renderer, loaded_explosion, NULL, &explosion_R); 
  	} //left
	SDL_RenderCopy(renderer, loaded_explosion, NULL, &explosion_R); 
	}
}

void boom(int bomb_power, int map[20][25]){
	explosion_placed = true;
	
	if (map[(bomb_R.y - bomb_power*64) / 64][bomb_R.x / 64] == 1) map[(bomb_R.y - bomb_power*64) / 64][bomb_R.x / 64] = 0; //up
	if (map[(bomb_R.y + bomb_power*64) / 64][bomb_R.x / 64] == 1) map[(bomb_R.y + bomb_power*64) / 64][bomb_R.x / 64] = 0; //down
	if (map[bomb_R.y / 64][(bomb_R.x + bomb_power*64) / 64] == 1) map[bomb_R.y / 64][(bomb_R.x + bomb_power*64) / 64] = 0; //left
	if (map[bomb_R.y / 64][(bomb_R.x - bomb_power*64) / 64] == 1) map[bomb_R.y / 64][(bomb_R.x - bomb_power*64) / 64] = 0; //right
	
	if (bomb_R.y / 64 == (player_R.y + 32)/64 && bomb_R.x / 64 == (player_R.x + 32)/64){ 
		lose();
		}
	else if ((bomb_R.y - bomb_power*64)/ 64 == (player_R.y + 32)/64 && bomb_R.x / 64 == (player_R.x + 32)/64) {
		lose();
	}
	else if ((bomb_R.y + bomb_power*64)/ 64 == (player_R.y + 32)/64 && bomb_R.x / 64 == (player_R.x + 32)/64) {
		lose();
	}
	else if (bomb_R.y / 64 == (player_R.y + 32)/64 && (bomb_R.x + bomb_power*64) / 64 == (player_R.x + 32)/64) {
		lose();
	}
	else if (bomb_R.y / 64 == (player_R.y + 32)/64 && (bomb_R.x - bomb_power*64) / 64 == (player_R.x + 32)/64) {
		lose();
	}

	Mix_PlayChannel(-1, explosion_sound, 0);
	bomb_placed = false;
	//bomb_R.x = 0;
	//bomb_R.y = 0;
	bombTex = NULL;
}
