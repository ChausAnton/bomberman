#pragma once 
#ifndef GAME_H
#define GAME_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include "enemy.h"

SDL_Texture *playerTex;
SDL_Texture *bombTex;

SDL_Surface *gScreenSurface;

SDL_Rect player_R;
SDL_Rect bomb_R;
SDL_Rect player_wall_hitbox_R;

SDL_Window *window;
SDL_Renderer *renderer;

bool isRunning;
int player_velocity;

void init(const char *title, int x_pos, int y_pos, int width, int height, bool fullscreen);
void handleEvents();
void update();
void render();
void clean();

#endif
