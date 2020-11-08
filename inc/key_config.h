#pragma once 
#ifndef KEY_BINDINGS_H
#define KEY_BINDINGS_H

#include "../inc/game.h"
#include "../inc/texture_manager.h"
#include "enemy.h"

bool move_up;
bool move_down;
bool move_left;
bool move_right;

void playerMove(int player_velocity);
void Bomb();

#endif
