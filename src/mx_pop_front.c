#include "libmx.h"

void mx_pop_front(t_list **list) {
    if (*list == NULL || list == NULL) {
        return;
    }

    t_list *curr = NULL;

    if((*list)->next == NULL) {
        free(*list);
        *list = NULL;
    }
    else {
        curr = (*list)->next;
        free(*list);
        *list = curr;
    }
}
