#include "../inc/enemy.h"

void mx_push_back_slime(t_slime **list, int x, int y) {
    t_slime *current = *list;
    if (current == NULL) {
        current = mx_create_slime(x, y);
        return;
    }
    while (current->next != NULL){
        current = current->next;
    }
    current->next = mx_create_slime(x, y);    
}
