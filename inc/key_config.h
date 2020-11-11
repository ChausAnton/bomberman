#pragma once 
#ifndef KEY_BINDINGS_H
#define KEY_BINDINGS_H

#include "../inc/game.h"
#include "../inc/texture_manager.h"

bool move_up;
bool move_down;
bool move_left;
bool move_right;

bool bomb_placed;
bool explosion_placed;

int bonus;

void playerMove(int, int [20][25]);
void Bomb();
void boom(int, int [20][25]);
void bombAnimation();
void explosionAnimation(int , int [20][25]);

int dorandom();

#endif
