#pragma once 
#ifndef ENEMY
#define ENEMY

#include <ncurses.h>
#include "game.h"
#include "texture_manager.h"
#include "map.h"
#include "key_config.h"
#include <stdbool.h>
#include <stdio.h>
#include <time.h>
enum { number_of_slimes = 1 };

SDL_Texture *slimeTex[number_of_slimes];
SDL_Rect slime_R[number_of_slimes];

SDL_Rect slime_wall_hitbox_R[number_of_slimes];

int slime_velocity;

typedef struct s_slime {
    SDL_Texture *slimeTex;
    SDL_Rect slime_R;
    SDL_Rect slime_wall_hitbox_R;
    struct s_slime *next;
    int up;
    int down;
    int left;
    int right;
}   t_slime;

t_slime *mx_create_slime(int);

void mx_push_back_slime(t_slime **, int );

t_slime *slimes;

void slimeMove(int slime_velocity);

void init_slime();

void slimeMovePro(int);

void SDL_RENDERS_SLIMES();

bool slime_up;
bool slime_down;
bool slime_right;
bool slime_left;

#endif
