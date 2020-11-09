#pragma once 
#ifndef GAME_H
#define GAME_H

// SDL 2.0
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"
#include "SDL2/SDL_ttf.h"

// Default
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ncurses.h>
#include <time.h>
// Inc
#include "../inc/texture_manager.h"
#include "../inc/map.h"
#include "../inc/key_config.h"
//#include "enemy.h"

// Textures
SDL_Texture *playerTex;
SDL_Texture *bombTex;
SDL_Texture *menubombTex;

// Surfaces
SDL_Surface *gScreenSurface;

// Player
SDL_Rect player_R;
int player_velocity;

// Bomb
SDL_Rect bomb_R;
SDL_Rect pause_bomb_R;
int bomb_power;

// Music
Mix_Music *backgroundSound;
Mix_Chunk *put_bomb_sound;
Mix_Chunk *step_sound;

// Bomb timer
Uint32 bombStart;
int bombTime;

// TXT Necessaries
TTF_Font *arcade;
SDL_Color White;

SDL_Surface* healthMessage;
SDL_Surface* bombMessage;
SDL_Surface* scoreMessage;
SDL_Surface* timeMessage;

SDL_Texture* h_Message;
SDL_Texture* b_Message;
SDL_Texture* s_Message;
SDL_Texture* t_Message;

SDL_Rect h_Message_rect;
SDL_Rect b_Message_rect;
SDL_Rect s_Message_rect;
SDL_Rect t_Message_rect;

// Window and renderer
SDL_Window *window;
SDL_Renderer *renderer;
bool isRunning;

//For move
Uint32 move_start;

// Map
int map[20][25];

//Loaded texture
SDL_Texture *LoadTexture(const char *, SDL_Renderer *);
SDL_Texture *loaded_anim_right[2];
SDL_Texture *loaded_anim_left[2];
SDL_Texture *loaded_anim_up[2];
SDL_Texture *loaded_anim_down[2];

void init(const char *title, int x_pos, int y_pos, int width, int height, bool fullscreen);
void initGame();
void handleEvents();
void update();
void render();
void clean();
void restart();
void pauseMenu();
void init_texture();
void init_sound(int);

#endif
