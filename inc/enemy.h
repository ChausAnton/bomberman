#pragma once 
#ifndef ENEMY
#define ENEMY

#include "game.h"
#include "texture_manager.h"
#include "map.h"
#include "key_config.h"

//const int number_of_slimes = 4;

SDL_Texture *slimeTex[4];
SDL_Rect slime_R[4];

SDL_Rect slime_wall_hitbox_R[4];

int slime_velocity;

void slimeMove(int);

void init_slime();

void SDL_RENDERS_SLIMES();

#endif
