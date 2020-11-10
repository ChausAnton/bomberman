#include "../inc/texture_manager.h"

SDL_Texture *LoadTexture(const char *texture, SDL_Renderer *ren){
    SDL_Surface *tmpSurface = IMG_Load(texture);
    SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, tmpSurface);
    SDL_FreeSurface(tmpSurface);
    return tex;
}

void drawMapCell(SDL_Texture *tex, SDL_Rect src, SDL_Rect dst){
    SDL_RenderCopy(renderer, tex, &src, &dst);
}
