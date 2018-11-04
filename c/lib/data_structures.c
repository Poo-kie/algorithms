//
// Created by pookie on 9/15/18.
//

#include <stdlib.h>
#include <string.h>

#include "data_structures.h"

/****************************************************************************
 *
 * ------------------------------ list --------------------------------------
 *
 ****************************************************************************/

/**
 * Initializes a list
 * @param list
 * @param destroy
 */
void list_init(list_t *list, void (*destroy)(void *data)) {
    list->size = 0;
    list->destroy = destroy;
    list->head = NULL;
    list->tail = NULL;
}

void list_destroy(list_t *list) {

    void *data;

    while (list_size(list) > 0) {
        if (list_rem_next(list, NULL, &data) == 0 &&
            list->destroy != NULL) {

            list->destroy(data);
        }
    }

    memset(list, 0, sizeof(list_t));
}

int list_ins_next(list_t *list, list_el_t *element, const void *data) {

    list_el_t *new_element;

    if ((new_element = (list_el_t *)malloc(sizeof(list_el_t))) == NULL) return -1;

    new_element->data = (void *)data;

    if (element == NULL) {
        if (list_size(list) == 0) list->tail = new_element;

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

int list_rem_next(list_t *list, list_el_t *element, void **data) {
    list_el_t *old_element;

    if(list_size(list) == 0) return -1;

    if(element == NULL) {
        *data = list->head->data;
        old_element = list->head;
        list->head = list->head->next;

        if (list_size(list) == 1) list->tail = NULL;
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
