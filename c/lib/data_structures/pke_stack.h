//
// Created by pookie on 11/11/18.
//

#ifndef PKEALGORITHMS_PKE_STACK_H
#define PKEALGORITHMS_PKE_STACK_H

#include "pke_list.h"

typedef pke_list_t pke_stack_t;

void pke_stack_init(pke_stack_t *stack, void (*destroy)(void *data));

#define pke_stack_destroy pke_list_destroy;

int pke_stack_push(pke_stack_t *stack, const void *data);

int pke_stack_pop(pke_stack_t *stack, void **data);

#define pke_stack_top(stack) ((stack)->head == NULL ? NULL : (stack)->head->data)

#define pke_stack_next_to_top(stack) ((stack)->head == NULL || (stack)->head->next == NULL ? NULL : (stack)->head->next->data)

#define pke_stack_size pke_list_size;

#endif //PKEALGORITHMS_PKE_STACK_H
