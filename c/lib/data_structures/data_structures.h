//
// Created by pookie on 9/11/18.
//

#ifndef PKEALGORITHMS_DATA_STRUCTURES_H
#define PKEALGORITHMS_DATA_STRUCTURES_H

#include "pke_list.h"

typedef struct {
    double x;
    double y;
} coordinate_t;

typedef enum { LEFT, RIGHT, STRAIGHT } direction_t;

typedef struct {
    coordinate_t a;
    coordinate_t b;
} vector_t;

/****************************************************************************
 *
 * ------------------------------ dlist -------------------------------------
 *
 ****************************************************************************/

typedef struct dlist_el {
    void            *data;
    struct dlist_el *next;
    struct dlist_el *prev;
} dlist_el_t;

typedef struct dlist {
    int                 size;
    int                 (*match)(const void *key1, const void *key2);
    void                (*destroy)(void *data);
    dlist_el_t          *head;
    dlist_el_t          *tail;
} dlist_t;

void dlist_init(dlist_t *list, void (*destroy)(void *data));

void dlist_destroy(dlist_t *list);

int dlist_ins_next(dlist_t *list, dlist_el_t *element, const void *data);

int dlist_ins_prev(dlist_t *list, dlist_el_t *element, const void *data);

int dlist_remove(dlist_t *list, dlist_el_t *element, void **data);

#define dlist_size(list) ((list)->size)

#define dlist_head(list) ((list)->head)

#define dlist_tail(list) ((list)->tail)

#define dlist_is_head(element) ((element)->prev == NULL ? 1 : 0)

#define dlist_is_tail(element) ((element)->next == NULL ? 1 : 0)

#define dlist_data(element) ((element)->data)

#define dlist_next(element) ((element)->next)

#define dlist_prev(element) ((element)->prev)


/****************************************************************************
 *
 * ------------------------------ stack -------------------------------------
 *
 ****************************************************************************/

typedef pke_list_t pke_stack_t;

void pke_stack_init(pke_stack_t *stack, void (*destroy)(void *data));

#define pke_stack_destroy pke_list_destroy;

int pke_stack_push(pke_stack_t *stack, const void *data);

int pke_stack_pop(pke_stack_t *stack, void **data);

#define pke_stack_top(stack) ((stack)->head == NULL ? NULL : (stack)->head->data)

#define pke_stack_next_to_top(stack) ((stack)->head == NULL || (stack)->head->next == NULL ? NULL : (stack)->head->next->data)

#define pke_stack_size pke_list_size;

#endif //PKEALGORITHMS_DATA_STRUCTURES_H
