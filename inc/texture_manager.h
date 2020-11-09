#pragma once
#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include "game.h"

SDL_Texture *LoadTexture(const char *texture, SDL_Renderer *ren);
void drawMapCell(SDL_Texture *tex, SDL_Rect src, SDL_Rect dst);

#endif
