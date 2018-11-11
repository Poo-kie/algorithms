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
