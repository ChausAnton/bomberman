#include "../inc/enemy.h"

void mx_pop_front_slime(t_slime **list) {
    if (list == NULL || *list == NULL) {
        return;
    }
    t_slime *node = *list;
    node = node->next;
    free(*list);
    (*list) = NULL;
    *list = node;
}
