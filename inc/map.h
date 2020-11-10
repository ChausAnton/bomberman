#pragma once
#ifndef MAP_H
#define MAP_H

#include "game.h"
#include "texture_manager.h"

void constrMap();
void LoadMap();
void DrawMap();

SDL_Rect map_src, map_dst;

SDL_Texture *ground;
SDL_Texture *breakable_stone;
SDL_Texture *stone;
SDL_Texture *up_stone_wall;
SDL_Texture *down_stone_wall;
SDL_Texture *left_stone_wall;
SDL_Texture *right_stone_wall;
SDL_Texture *up_left_corner;
SDL_Texture *up_right_corner;
SDL_Texture *down_left_corner;
SDL_Texture *down_right_corner;
SDL_Texture *slime;

#endif
