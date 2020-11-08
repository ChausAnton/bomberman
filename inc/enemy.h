#pragma once 
#ifndef ENEMY
#define ENEMY

#include "game.h"
#include "texture_manager.h"
#include "map.h"
#include "key_config.h"
#include <stdbool.h>
#include <stdio.h>
enum { number_of_slimes = 1 };

SDL_Texture *slimeTex[number_of_slimes];
SDL_Rect slime_R[number_of_slimes];

SDL_Rect slime_wall_hitbox_R[number_of_slimes];

int slime_velocity;

//void slimeMove(int);

void init_slime();

void slimeMovePro(int);

void SDL_RENDERS_SLIMES();

bool slime_up;
bool slime_down;
bool slime_rigth;
bool slime_left;

#endif
