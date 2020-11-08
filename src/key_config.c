#include "../inc/key_config.h"


void playerMove(int player_velocity){
	
	player_wall_hitbox_R.h = player_R.h;
    player_wall_hitbox_R.w = player_R.w;

    if (move_up) {
		playerTex = LoadTexture("resource/ast/Bomberman/Bomberman_MoveUp1.png", renderer);
		if(player_R.y < 0) player_R.y = 0;
		if(player_R.y > 1280) player_R.y = 1280;
		player_R.y -= player_velocity;
	}
	else if (move_down) {
		playerTex = LoadTexture("resource/ast/Bomberman/Bomberman_MoveDown1.png", renderer);
		if(player_R.y < 0) player_R.y = 0;
		if(player_R.y > 1280) player_R.y = 1280;
		player_R.y += player_velocity;
	}
	else if (move_right) {
		playerTex = LoadTexture("resource/ast/Bomberman/Bomberman_MoveRight1.png", renderer);
		if(player_R.x < 0) player_R.x = 0;
		if(player_R.x > 1600) player_R.x = 1600;
		player_R.x += player_velocity;
	}
	else if (move_left) {
		playerTex = LoadTexture("resource/ast/Bomberman/Bomberman_MoveLeft1.png", renderer);
		if(player_R.x < 0) player_R.x = 0;
		if(player_R.x > 1600) player_R.x = 1600;
		player_R.x -= player_velocity;
	}
	else playerTex = LoadTexture("resource/ast/Bomberman/Bomberman_Front.png", renderer);
}

void Bomb(){
	bomb_R.x = player_R.x;
	bomb_R.y = player_R.y;
	bombTex = LoadTexture("resource/ast/Bomberman/Bomb.png", renderer);
}
