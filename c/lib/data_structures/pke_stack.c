//
// Created by pookie on 11/11/18.
//

#include <stdlib.h>

#include "pke_stack.h"

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