#include "../inc/enemy.h"

void mx_pop_index_slime(t_slime **list, int index) {
    if(*list == NULL) return;
    score_num += 200;
    menu_score();
    if(index <= 0) {
        mx_pop_front_slime(list);
        return;
    }
    t_slime *node = *list;
    int size = 0;
    while (node != NULL) {
        node = node->next;
        size++;
    }
    if(size <= index) {
        mx_pop_back_slime(list);
        return;
    }
    
    t_slime *node_mv = (*list);
    for(int i = 0; node_mv != NULL && i < index - 1; i++) {
        node_mv = node_mv->next;
    }
    if(node_mv == NULL || node_mv->next == NULL) return;

    t_slime *temp = node_mv->next->next;
    free(node_mv->next);
    node_mv->next = temp;
}
