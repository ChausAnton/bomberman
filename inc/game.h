#pragma once 
#ifndef GAME_H
#define GAME_H

// SDL 2.0
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"
// Deafult
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
// Inc
#include "../inc/texture_manager.h"
#include "../inc/map.h"
#include "../inc/key_config.h"
#include "enemy.h"

// Textures
SDL_Texture *playerTex;
SDL_Texture *bombTex;

// Surfaces
SDL_Surface *gScreenSurface;

// Music
Mix_Music *backgroundSound;
Mix_Chunk *put_bomb_sound;
Mix_Chunk *step_sound;
// Objects Info
SDL_Rect player_R;
SDL_Rect bomb_R;

// Window and renderer
SDL_Window *window;
SDL_Renderer *renderer;
//For move
Uint32 move_start;
//Loaded texture
SDL_Texture *LoadTexture(const char *, SDL_Renderer *);
SDL_Texture *loaded_anim_right[2];
SDL_Texture *loaded_anim_left[2];
SDL_Texture *loaded_anim_up[2];
SDL_Texture *loaded_anim_down[2];
void init_texture();
////////////////////
bool isRunning;
int player_velocity;

void init(const char *title, int x_pos, int y_pos, int width, int height, bool fullscreen);
void handleEvents();
void update();
void render();
void clean();
void init_sound(int );
#endif
