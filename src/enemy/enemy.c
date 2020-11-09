#include "../../inc/game.h"

int lvl2[20][25] = {
    {7,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,8},
    {5,0,1,0,1,1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
    {5,2,1,1,1,1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
    {5,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
    {5,0,2,1,1,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
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

void init_slime() {
    slimes = NULL;
    for (int i = 0; i < number_of_slimes - 1; i++) {
		mx_push_back_slime(slimes, i);
    }
	slime_up = true;
	slime_down = true;
	slime_left = true;
	slime_rigth = true;
}



void slimeMovePro(int slime_velocity) {
	for (int i = 0; i < number_of_slimes; i++) {
		if(lvl2[(slime_R[i].y - 1) / 64][(slime_R[i].x) / 64] == 0 && lvl2[(slime_R[i].y - 1) / 64][(slime_R[i].x + 63) / 64] == 0 && slime_up == true) {//move_up
			slimeTex[i] = LoadTexture("resource/ast/enemies/Slime.png", renderer);
		    if(slime_R[i].y < 0) slime_R[i].y = 0;
		    if(slime_R[i].y > 1280) slime_R[i].y = 1280;
		    slime_R[i].y -= slime_velocity;
			slime_down = false;
		}
		else if(lvl2[(slime_R[i].y) / 64][(slime_R[i].x + 63) / 64] == 0 && lvl2[(slime_R[i].y + 63) / 64][(slime_R[i].x + 63) / 64] == 0 && slime_rigth == true) {//move_right
			slimeTex[i] = LoadTexture("resource/ast/enemies/Slime.png", renderer);
		    if(slime_R[i].x < 0) slime_R[i].x = 0;
		    if(slime_R[i].x > 1600) slime_R[i].x = 1600;
		    slime_R[i].x += slime_velocity;
			slime_left = false;

		}
		else if (lvl2[(slime_R[i].y) / 64][(slime_R[i].x - 1) / 64] == 0 && lvl2[(slime_R[i].y + 63) / 64][(slime_R[i].x - 1) / 64] == 0 && slime_left == true) {//move_left
			slimeTex[i] = LoadTexture("resource/ast/enemies/Slime.png", renderer);
		    if(slime_R[i].x < 0) slime_R[i].x = 0;
		    if(slime_R[i].x > 1600) slime_R[i].x = 1600;
		    slime_R[i].x -= slime_velocity;
			slime_rigth = false;
		}
		else if(lvl2[(slime_R[i].y + 63) / 64][(slime_R[i].x) / 64] == 0 && lvl2[(slime_R[i].y + 63) / 64][(slime_R[i].x + 63) / 64] == 0 && slime_down == true) {//move_down
			slimeTex[i] = LoadTexture("resource/ast/enemies/Slime.png", renderer);
		    if(slime_R[i].y < 0) slime_R[i].y = 0;
		    if(slime_R[i].y > 1280) slime_R[i].y = 1280;
		    slime_R[i].y += slime_velocity;
			slime_up = false;
		}
		else {
			slimeTex[i] = LoadTexture("resource/ast/enemies/Slime.png", renderer);
			slime_up = true;
			slime_down = true;
			slime_left = true;
			slime_rigth = true;
		}
	}
}

void SDL_RENDERS_SLIMES() {
    for (int i = 0; i < number_of_slimes; i++)
        SDL_RenderCopy(renderer, slimeTex[i], NULL, &slime_R[i]);
}
