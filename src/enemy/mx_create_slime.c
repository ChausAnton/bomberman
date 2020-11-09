#include "../../inc/game.h"

t_slime *mx_create_slime(int i) {
    t_slime *slime = (t_slime *) malloc(sizeof(t_slime));
    slime->slime_R.x = 192 + (i * 64);
    slime->slime_R.y = 192 + (i * 64);
    slime->slime_R.h = 64;
    slime->slime_R.w = 64;
    slime->slime_wall_hitbox_R.h = 64;
    slime->slime_wall_hitbox_R.w = 64;
    slime->slimeTex = LoadTexture("resource/ast/enemies/Slime.png", renderer);
    slime->up = rand() % 4 + 1;
    slime->down= rand() % 4 + 1;
    slime->left = rand() % 4 + 1;
    slime->rigth = rand() % 4 + 1;
    slime->next = NULL;
    return slime;
}
