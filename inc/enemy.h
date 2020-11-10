#pragma once 
#ifndef ENEMY
#define ENEMY

#include "game.h"

enum { number_of_slimes = 1 };

SDL_Texture *slimeTex[number_of_slimes];
SDL_Rect slime_R[number_of_slimes];

SDL_Rect slime_wall_hitbox_R[number_of_slimes];

int slime_velocity;

typedef struct s_slime {
    SDL_Texture *slimeTex;
    SDL_Rect slime_R;
    SDL_Rect slime_wall_hitbox_R;
    bool gener;
    int random_slime;
    struct s_slime *next;
}   t_slime;

t_slime *mx_create_slime(int, int);

void mx_push_back_slime(t_slime **, int, int);

void mx_pop_back_slime(t_slime **);

void mx_pop_front_slime(t_slime **);

void mx_pop_index_slime(t_slime **, int);

t_slime *slimes;

void slimeMove(int slime_velocity);

void init_slime(int, int);

void slimeMovePro(int);

void SDL_RENDERS_SLIMES();

bool slime_up;
bool slime_down;
bool slime_right;
bool slime_left;

#endif
