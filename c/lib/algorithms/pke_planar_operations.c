//
// Created by pookie on 11/29/18.
//

#include "pke_algorithms.h"

void swap_head_with_lowest_leftmost_coordinate(coordinate_t **coordinates, int length) {
    coordinate_t *llm = (coordinates)[0];
    int llmIndex = 0;

    for (int i = 0; i < length; i++) {
        coordinate_t *c = (coordinates)[i];
        if (llm->y > c->y || (D_EQUAL(c->y, llm->y) && D_EQUAL(llm->x, c->x))) {
            llmIndex = i;
            llm = c;
        }
    }

    (coordinates)[llmIndex] = (coordinates)[0];
    (coordinates)[0] = llm;
}