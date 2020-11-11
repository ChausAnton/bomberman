#include "../inc/enemy.h"

void mx_pop_back_slime(t_slime **list) {

    if (*list == NULL || list == NULL) {
        return;
    }

    t_slime *node = *list;
    if (node->next == NULL) {
        free(node);
        node = NULL;
        return;
    }

    while(node->next->next != NULL) {
        node = node->next;
    }

    free(node->next);
    node->next = NULL;
}
