#include "../../inc/game.h"

void init_slime() {
    slime_velocity = 2;
    for (int i = 0; i < 4; i++) {
        slime_R[i].x = 128 + (i * 64);
        slime_R[i].y = 128 + (i * 64);

        slimeTex[i] = LoadTexture("resource/ast/enemies/Slime.png", renderer);

        slime_R[i].h = 64;
        slime_R[i].w = 64;

        slime_wall_hitbox_R[i].h = 64; 
        slime_wall_hitbox_R[i].w = 64;
    }
}

void slimeMove(int slime_velocity) {
    for(int i = 0; i < 4; i++) {
        slime_wall_hitbox_R[i].h = player_R.h;
        slime_wall_hitbox_R[i].w = player_R.w;

        if (move_up) {
		    slimeTex[i] = LoadTexture("resource/ast/enemies/Slime.png", renderer);
		    if(slime_R[i].y < 0) slime_R[i].y = 0;
		    if(slime_R[i].y > 1280) slime_R[i].y = 1280;
		    slime_R[i].y -= slime_velocity;
	    }
	    else if (move_down) {
		    slimeTex[i] = LoadTexture("resource/ast/enemies/Slime.png", renderer);
		    if(slime_R[i].y < 0) slime_R[i].y = 0;
		    if(slime_R[i].y > 1280) slime_R[i].y = 1280;
		    slime_R[i].y += slime_velocity;
	    }
	    else if (move_right) {
		    slimeTex[i] = LoadTexture("resource/ast/enemies/Slime.png", renderer);
		    if(slime_R[i].x < 0) slime_R[i].x = 0;
		    if(slime_R[i].x > 1600) slime_R[i].x = 1600;
		    slime_R[i].x += slime_velocity;
	    }
	    else if (move_left) {
		    slimeTex[i] = LoadTexture("resource/ast/enemies/Slime.png", renderer);
		    if(slime_R[i].x < 0) slime_R[i].x = 0;
		    if(slime_R[i].x > 1600) slime_R[i].x = 1600;
		    slime_R[i].x -= slime_velocity;
	    }
	    else slimeTex[i] = LoadTexture("resource/ast/enemies/Slime.png", renderer);
    }
    
}

void SDL_RENDERS_SLIMES() {
    for (int i = 0; i < 4; i++)
        SDL_RenderCopy(renderer, slimeTex[i], NULL, &slime_R[i]);
}
