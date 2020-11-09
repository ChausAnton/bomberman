#include "../../inc/game.h"

void mx_push_back_slime(t_slime **list, int i) {
    t_slime *current = *list;
    if (current == NULL) {
        write(2, "!!!!!!!!!!!", 11);
        current = mx_create_slime(i);
        return;
    }
    while (current->next != NULL){
        current = current->next;
    }
    current->next = mx_create_slime(i);    
}
