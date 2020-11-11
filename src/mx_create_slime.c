#include "../inc/enemy.h"

t_slime *mx_create_slime(int x, int y) {
    t_slime *slime = (t_slime *) malloc(sizeof(t_slime));
    slime->slime_R.x = x;
    slime->slime_R.y = y;
    slime->slime_R.h = 64;
    slime->slime_R.w = 64;
    slime->slime_wall_hitbox_R.h = 64;
    slime->slime_wall_hitbox_R.w = 64;
    slime->slimeTex = LoadTexture("resource/ast/enemies/Slime.png", renderer);
    slime->gener = true;
    slime->random_slime = 0;
    slime->next = NULL;
    return slime;
}
