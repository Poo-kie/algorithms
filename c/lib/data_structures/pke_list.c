//
// Created by pookie on 11/11/18.
//

#include <stdlib.h>
#include <string.h>

#include "pke_list.h"

void pke_list_init(pke_list_t *list, void (*destroy)(void *data)) {
    list->size = 0;
    list->destroy = destroy;
    list->head = NULL;
    list->tail = NULL;
}

void pke_list_destroy(pke_list_t *list) {

    void *data;

    while (pke_list_size(list) > 0) {
        if (pke_list_rem_next(list, NULL, &data) == 0 &&
            list->destroy != NULL) {

            list->destroy(data);
        }
    }

    memset(list, 0, sizeof(pke_list_t));
}

int pke_list_ins_next(pke_list_t *list, pke_list_el_t *element, const void *data) {

    pke_list_el_t *new_element;

    if ((new_element = (pke_list_el_t *)malloc(sizeof(pke_list_el_t))) == NULL) return -1;

    new_element->data = (void *)data;

    if (element == NULL) {
        if (pke_list_size(list) == 0) list->tail = new_element;

        new_element->next = list->head;
        list->head = new_element;
    }
    else {
        if (element->next == NULL) list->tail = new_element;

        new_element->next = element->next;
        element->next = new_element;
    }

    list->size++;

    return 0;
}

int pke_list_rem_next(pke_list_t *list, pke_list_el_t *element, void **data) {
    pke_list_el_t *old_element;

    if(pke_list_size(list) == 0) return -1;

    if(element == NULL) {
        *data = list->head->data;
        old_element = list->head;
        list->head = list->head->next;

        if (pke_list_size(list) == 1) list->tail = NULL;
    }
    else {
        if (element->next == NULL) return -1;

        *data = element->next->data;
        old_element = element->next;
        element->next = element->next->next;

        if (element->next == NULL) list->tail = element;
    }

    free(old_element);

    list->size--;

    return 0;
}