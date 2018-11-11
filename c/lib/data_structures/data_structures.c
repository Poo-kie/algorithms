//
// Created by pookie on 9/15/18.
//

#include <stdlib.h>
#include <string.h>

#include "data_structures.h"

/****************************************************************************
 *
 * ------------------------------ dlist -------------------------------------
 *
 ****************************************************************************/

/**
 * Initializes a double linked list
 * @param list
 * @param destroy
 */

void dlist_init(dlist_t *list, void (*destroy) (void *data)) {
    list->size = 0;
    list->destroy = destroy;
    list->head = NULL;
    list->tail = NULL;
}

/**
 * Removes all elements from the list and frees
 * any allocated memory
 * @param list
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

/**
 * Removes a single element from a given list
 * @param list
 * @param element
 * @param data
 * @return 0 if successful, -1 otherwise
 */
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

/**
 * Inserts a new element after a specified element
 * @param list
 * @param element
 * @param data
 * @return 0 if successful, -1 otherwise
 */
int dlist_ins_next(dlist_t *list, dlist_el_t *element, const void *data) {

    dlist_el_t *new_element;

    if (element == NULL && dlist_size(list) != 0) return -1;

    if ((new_element = (dlist_el_t *)malloc(sizeof(dlist_el_t))) == NULL) return -1;

    new_element->data = (void *)data;

    if (dlist_size(list) == 0) {
        list->head = new_element;
        list->head->next = NULL;
        list->head->prev = NULL;
        list->tail = new_element;
    }
    else if (element != NULL) {
        new_element->next = element->next;
        new_element->prev = element;

        if (element->next == NULL) list->tail = new_element;
        else element->next->prev = new_element;

        element->next = new_element;
    }
    else return -1;

    list->size++;

    return 0;
}

/**
 *
 * @param list
 * @param element
 * @param data
 * @return
 */
int dlist_ins_prev(dlist_t *list, dlist_el_t *element, const void *data) {
    dlist_el_t *new_element;

    if (element == NULL && dlist_size(list) != 0) return -1;

    if ((new_element = (dlist_el_t*)malloc(sizeof(dlist_el_t))) == NULL) return -1;

    new_element->data = (void*)data;

    if (dlist_size(list) == 0) {
        list->head = new_element;
        list->head->prev = NULL;
        list->head->next = NULL;
        list->tail = new_element;
    }
    else {
        new_element->next = element;
        new_element->prev = element->prev;

        if (element->prev == NULL) list->head = new_element;
        else element->prev->next = new_element;

        element->prev = new_element;
    }

    list->size++;

    return 0;
}

/****************************************************************************
 *
 * ------------------------------ stack -------------------------------------
 *
 ****************************************************************************/

void pke_stack_init(pke_stack_t *stack, void (*destroy)(void *data)) {
    stack->head = NULL;
    stack->tail = NULL;
    stack->destroy = destroy;
    stack->size = 0;
}

int pke_stack_push(pke_stack_t *stack, const void *data) {
    return pke_list_ins_next(stack, NULL, data);
}

int pke_stack_pop(pke_stack_t *stack, void **data) {
    return pke_list_rem_next(stack, NULL, data);
}
