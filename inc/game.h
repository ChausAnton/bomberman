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

// Mouse
int mouseX;
int mouseY;

// Textures
SDL_Texture *playerTex;
SDL_Texture *bombTex;
SDL_Texture *menuBombTex;
SDL_Texture *explosionTex;

// Surfaces
SDL_Surface *gScreenSurface;

// Player
SDL_Rect player_R;
SDL_Rect menu_Heart1_R;
SDL_Rect menu_Heart2_R;
SDL_Rect menu_Heart3_R;
int player_velocity;
int player_hp;

// Bomb
SDL_Rect bomb_R;
SDL_Rect menu_Bomb_R;
int bomb_power;

// Music
Mix_Music *backgroundSound;
Mix_Chunk *put_bomb_sound;
Mix_Chunk *step_sound;
Mix_Chunk *explosion_sound;
Mix_Chunk *die_sound;

// Bomb timer
Uint32 bombStart;
int bombTime;
Uint32 explosionStart;
int explosionTime;

// Time timer
Uint32  timer_start;
int timer_time;
Uint32 a;

// TXT Necessaries
TTF_Font *arcade;
SDL_Color White;

// Score
int score_num;
SDL_Rect score_num_rect;
SDL_Surface* ScoreNumMessage;
SDL_Texture* Score_Num_Message;
///////

Uint32  timer_do_pause;
SDL_Rect Time_rect;
SDL_Surface* TimeMessage;
SDL_Texture* Time_Message;

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

// Pause
SDL_Texture* pauseTex;
SDL_Rect pause_R;

// Intro
SDL_Texture* introTex;
SDL_Rect intro_R;
bool is_intro;

SDL_Texture* playTex;
SDL_Texture* loaded_playTex;
SDL_Texture* loaded_playTexHover;
SDL_Texture* loaded_playTexPressed;
SDL_Rect play_R;
bool play_Hover;
bool play_Pressed;

SDL_Texture* exitTex;
SDL_Texture* loaded_exitTex;
SDL_Texture* loaded_exitTexHover;
SDL_Texture* loaded_exitTexPressed;
SDL_Rect exit_R;
bool exit_Hover;
bool exit_Pressed;

// Pause
Uint32 mStartTicks;
Uint32 mPausedTicks;
bool is_pause;

// Game over
SDL_Color Red;
SDL_Surface* GameOver;
SDL_Texture* GameOver_Message;
SDL_Rect GameOver_Message_rect;
bool is_lose;

// Window and renderer
SDL_Window *window;
SDL_Renderer *renderer;
bool isRunning;

// For move
Uint32 move_start;

// Map
int map[20][25];

//Loaded texture
SDL_Texture *LoadTexture(const char *, SDL_Renderer *);
SDL_Texture *loaded_anim_right[2];
SDL_Texture *loaded_anim_left[2];
SDL_Texture *loaded_anim_up[2];
SDL_Texture *loaded_anim_down[2];
SDL_Texture *loaded_dead_bomberman;
SDL_Texture *loaded_front;
SDL_Texture *loaded_bomb;
SDL_Texture *loaded_white_bomb;
SDL_Texture *loaded_explosion;
SDL_Texture *loaded_menu_bomb;
SDL_Texture *loaded_menu_heart;
SDL_Texture *loaded_explosion_up;
SDL_Texture *loaded_explosion_left;
SDL_Texture *loaded_explosion_down;
SDL_Texture *loaded_explosion_right;

SDL_Rect explosion_R;

void init(const char *title, int x_pos, int y_pos, int width, int height, bool fullscreen);
void initGame();
void initMenu();
void initMap();
void receiveDamage();
void handleEvents();
void update();
void render();
void clean();
void restart();
void pauseMenu();
void init_texture();
void init_sound(int);
void lose();
void reset();
void init_timer();
void menu_score();
#endif
