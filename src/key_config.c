#include "../inc/key_config.h"
#include "../inc/map.h"
#include "../inc/enemy.h"

int bomb_index_animation = 0;
int loaded_explosion_index_animation = 0;
int index_animation = 0;
int anim_index_animation = 0;

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
	if(map[(player_R.y + 30)/64][(player_R.x + 8)/64] == 11 && map[(player_R.y + 30)/64][(player_R.x + 54)/64] == 11) {
		new_lvl();
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
	if(map[(player_R.y + 63)/64][(player_R.x + 8)/64] == 11 && map[(player_R.y + 63)/64][(player_R.x + 54)/64] == 11){
		new_lvl();
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
	if(map[(player_R.y + 32)/64][(player_R.x + 56)/64] == 11 && map[(player_R.y + 61)/64][(player_R.x + 56)/64] == 11){
		new_lvl();
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
	if(map[(player_R.y + 32)/64][(player_R.x + 6)/64] == 11 && map[(player_R.y + 61)/64][(player_R.x + 6)/64] == 11) {
		new_lvl();
	}

	if (move_right) {
		/////////////SoundMove////////////////
		move_time = SDL_GetTicks() - move_start;
		if(move_time > 200){
			Mix_PlayChannel( -1, step_sound, 0 );
			move_start = SDL_GetTicks();
		}
		///////////AnimationMove////////////////
		if(anim_index_animation < 10) playerTex = loaded_anim_right[0];	
		else if(anim_index_animation > 10 && anim_index_animation < 20) playerTex = loaded_anim_right[1];
		else if(anim_index_animation > 20 && anim_index_animation < 30)playerTex = loaded_anim_right[0];
		else if(anim_index_animation > 30 && anim_index_animation < 40)playerTex = loaded_anim_right[2];
		else playerTex = loaded_anim_right[0];
		if(anim_index_animation > 50) anim_index_animation = 0;	
		anim_index_animation++;	
	}
	else if (move_left){
		/////////////SoundMove////////////////
		move_time = SDL_GetTicks() - move_start;
		if(move_time > 200){
			Mix_PlayChannel( -1, step_sound, 0 );
			move_start = SDL_GetTicks();
		}
		///////////AnimationMove////////////////
		if(anim_index_animation < 10) playerTex = loaded_anim_left[0];	
		else if(anim_index_animation > 10 && anim_index_animation < 20) playerTex = loaded_anim_left[1];
		else if(anim_index_animation > 20 && anim_index_animation < 30)playerTex = loaded_anim_left[0];
		else if(anim_index_animation > 30 && anim_index_animation < 40)playerTex = loaded_anim_left[2];
		else playerTex = loaded_anim_left[0];
		if(anim_index_animation > 50) anim_index_animation = 0;	
		anim_index_animation++;	
	}
	else if (move_up) {
		/////////////SoundMove////////////////
		move_time = SDL_GetTicks() - move_start;
		if(move_time > 200){
			Mix_PlayChannel( -1, step_sound, 0 );
			move_start = SDL_GetTicks();
		}
		///////////AnimationMove////////////////
		if(anim_index_animation < 10) playerTex = loaded_anim_up[0];	
		else if(anim_index_animation > 10 && anim_index_animation < 20) playerTex = loaded_anim_up[1];
		else if(anim_index_animation > 20 && anim_index_animation < 30)playerTex = loaded_anim_up[0];
		else if(anim_index_animation > 30 && anim_index_animation < 40)playerTex = loaded_anim_up[2];
		else playerTex = loaded_anim_up[0];
		if(anim_index_animation > 50) anim_index_animation = 0;	
		anim_index_animation++;	
	}
	else if (move_down) {
		/////////////SoundMove////////////////
		move_time = SDL_GetTicks() - move_start;
		if(move_time > 200){
			Mix_PlayChannel( -1, step_sound, 0 );
			move_start = SDL_GetTicks();
		}
		///////////AnimationMove////////////////
		if(anim_index_animation < 10) playerTex = loaded_anim_down[0];	
		else if(anim_index_animation > 10 && anim_index_animation < 20) playerTex = loaded_anim_down[1];
		else if(anim_index_animation > 20 && anim_index_animation < 30)playerTex = loaded_anim_down[0];
		else if(anim_index_animation > 30 && anim_index_animation < 40)playerTex = loaded_anim_down[2];
		else playerTex = loaded_anim_down[0];
		if(anim_index_animation > 50) anim_index_animation = 0;	
		anim_index_animation++;		
		}
	else 
		playerTex = loaded_anim_down[0];
}

void Bomb(){
	mStartTicks = 0;
	bomb_placed = true;
	Mix_PlayChannel(-1, put_bomb_sound, 0);
	bombStart = SDL_GetTicks();
	bomb_R.x = (((player_R.x + 32) / 64) * 64);
	bomb_R.y = (((player_R.y + 32) / 64) * 64);	
}

void bombAnimation(){
	if(bomb_index_animation < 20) bombTex = loaded_bomb;	
	else bombTex = loaded_white_bomb;
	if(bomb_index_animation > 40) bomb_index_animation = 0;
	bomb_index_animation++;
}

void explosionAnimation(int bomb_power, int map[20][25]){
	if (bombTime > 2000 && bombTime < 2500){
		if (map[(bomb_R.y) / 64][bomb_R.x / 64] == 1 || map[(bomb_R.y) / 64][bomb_R.x / 64] == 0){
			explosion_R.x = bomb_R.x;
  			explosion_R.y = bomb_R.y;
			explosionTex = loaded_explosion;
			SDL_RenderCopy(renderer, explosionTex, NULL, &explosion_R);   
 		}//center
 		if (map[(bomb_R.y - bomb_power*64) / 64][bomb_R.x / 64] == 1 || map[(bomb_R.y - bomb_power*64) / 64][bomb_R.x / 64] == 0){
			explosion_R.x = bomb_R.x;
  			explosion_R.y = bomb_R.y - bomb_power*64;
			explosionTex = loaded_explosion_up;
			SDL_RenderCopy(renderer, explosionTex, NULL, &explosion_R); 
 		 }//up
 		if (map[(bomb_R.y + bomb_power*64) / 64][bomb_R.x / 64] == 1 || map[(bomb_R.y + bomb_power*64) / 64][bomb_R.x / 64] == 0){ 
			explosion_R.x = bomb_R.x;
  			explosion_R.y = bomb_R.y + bomb_power*64;
			explosionTex = loaded_explosion_down;
			SDL_RenderCopy(renderer, explosionTex, NULL, &explosion_R); 
  		}//down
 		if (map[bomb_R.y / 64][(bomb_R.x + bomb_power*64) / 64] == 1 || map[bomb_R.y / 64][(bomb_R.x + bomb_power*64) / 64] == 0){
			explosion_R.x = bomb_R.x + bomb_power*64;
  			explosion_R.y = bomb_R.y;
			explosionTex = loaded_explosion_right;
			SDL_RenderCopy(renderer, explosionTex, NULL, &explosion_R); 
  		} //right
 		if (map[bomb_R.y / 64][(bomb_R.x - bomb_power*64) / 64] == 1 || map[bomb_R.y / 64][(bomb_R.x - bomb_power*64) / 64] == 0){
			explosion_R.x = bomb_R.x - bomb_power*64;
  			explosion_R.y = bomb_R.y;
			explosionTex = loaded_explosion_left;
			SDL_RenderCopy(renderer, explosionTex, NULL, &explosion_R); 
  		} //left
		//SDL_RenderCopy(renderer, explosionTex, NULL, &explosion_R); 
	}
}

int dorandom() {
	int v = rand() % 100 + 1;
	if (v > 0 && v <= 6) return 1;
	else if (v > 6 && v <= 25) return 2;
	else if (v > 25 && v <= 40) return 3;
	else return 4;
}

void boom(int bomb_power, int map[20][25]){
	if (map[(bomb_R.y - bomb_power*64) / 64][bomb_R.x / 64] == 1) {//up
		bonus = dorandom();
		map[(bomb_R.y - bomb_power*64) / 64][bomb_R.x / 64] = 0;
		addBonus();
	}
	if (map[(bomb_R.y + bomb_power*64) / 64][bomb_R.x / 64] == 1) {//down
		bonus = dorandom();	
		map[(bomb_R.y + bomb_power*64) / 64][bomb_R.x / 64] = 0;
		addBonus();
	} 
	if (map[bomb_R.y / 64][(bomb_R.x + bomb_power*64) / 64] == 1) {//right
		bonus = dorandom();
		map[bomb_R.y / 64][(bomb_R.x + bomb_power*64) / 64] = 0;
		addBonus();
	} 
	if (map[bomb_R.y / 64][(bomb_R.x - bomb_power*64) / 64] == 1) {//left
		bonus = dorandom();	
		map[bomb_R.y / 64][(bomb_R.x - bomb_power*64) / 64] = 0;
		addBonus();
	}

	t_slime *cur_slime  = slimes;
	for(int i = 0; cur_slime != NULL; ++i) {
		if (bomb_R.y / 64 == (cur_slime->slime_R.y + 32)/64 && bomb_R.x / 64 == (cur_slime->slime_R.x + 32)/64) {
			Mix_PlayChannel( -1, die_slime_sound, 0 );
			mx_pop_index_slime(&slimes, i);
			}
		else if ((bomb_R.y - bomb_power*64)/ 64 == (cur_slime->slime_R.y + 32)/64 && bomb_R.x / 64 == (cur_slime->slime_R.x + 32)/64) {
			Mix_PlayChannel( -1, die_slime_sound, 0 );
			mx_pop_index_slime(&slimes, i);
			}
		else if ((bomb_R.y + bomb_power*64)/ 64 == (cur_slime->slime_R.y + 32)/64 && bomb_R.x / 64 == (cur_slime->slime_R.x + 32)/64) {
			Mix_PlayChannel( -1, die_slime_sound, 0 );
			mx_pop_index_slime(&slimes, i);
			}
		else if (bomb_R.y / 64 == (cur_slime->slime_R.y + 32)/64 && (bomb_R.x + bomb_power*64) / 64 == (cur_slime->slime_R.x + 32)/64) {
			Mix_PlayChannel( -1, die_slime_sound, 0 );
			mx_pop_index_slime(&slimes, i);
			}
		else if (bomb_R.y / 64 == (cur_slime->slime_R.y + 32)/64 && (bomb_R.x - bomb_power*64) / 64 == (cur_slime->slime_R.x + 32)/64) {
			Mix_PlayChannel( -1, die_slime_sound, 0 );
			mx_pop_index_slime(&slimes, i);
			}
		cur_slime = cur_slime->next;
	}
	Mix_PlayChannel(-1, explosion_sound, 0);
	bomb_placed = false;
	explosion_placed = true;
	bombTex = NULL;

	if (bomb_R.y / 64 == (player_R.y + 32)/64 && bomb_R.x / 64 == (player_R.x + 32)/64) receiveDamage();
	else if ((bomb_R.y - bomb_power*64)/ 64 == (player_R.y + 32)/64 && bomb_R.x / 64 == (player_R.x + 32)/64) receiveDamage();
	else if ((bomb_R.y + bomb_power*64)/ 64 == (player_R.y + 32)/64 && bomb_R.x / 64 == (player_R.x + 32)/64) receiveDamage();
	else if (bomb_R.y / 64 == (player_R.y + 32)/64 && (bomb_R.x + bomb_power*64) / 64 == (player_R.x + 32)/64) receiveDamage();
	else if (bomb_R.y / 64 == (player_R.y + 32)/64 && (bomb_R.x - bomb_power*64) / 64 == (player_R.x + 32)/64) receiveDamage();
}
