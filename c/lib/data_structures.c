//
// Created by pookie on 9/15/18.
//

#include <stdlib.h>
#include <string.h>

#include "data_structures.h"

void dlist_init(dlist_t *list, void (*destroy) (void *data)) {
    list->size = 0;
    list->destroy = destroy;
    list->head = NULL;
    list->tail = NULL;
}

/*
 * Frees the data elements of the list
 * using the 'destroy' fn passed in init.
 * Performance: O(n)
 */
void dlist_destroy(dlist_t *list) {

    void *data;

    while (dlist_size(list) > 0) {
        if (dlist_remove(list, dlist_tail(list), &data) == 0 &&
            list->destroy != NULL) {

            list->destroy(data);
        }
    }

    memset(list, 0, sizeof(dlist_t));
}

int dlist_remove(dlist_t *list, dlist_el_t *element, void **data) {
    if (element == NULL || dlist_size(list) == 0) return -1;

    *data = element->data;

    if (element == list->head) {
        list->head = element->next;

        if (list->head == NULL) list->tail = NULL;
        else element->next->prev = NULL;
    }
    else {
        element->prev->next = element->next;

        if (element->next == NULL) list->tail = element->prev;
        else element->next->prev = element->prev;
    }

    free(element);

    list->size--;

    return 0;
}
