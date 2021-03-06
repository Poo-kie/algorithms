//
// Created by pookie on 11/11/18.
//

#ifndef PKEALGORITHMS_PKE_LIST_H
#define PKEALGORITHMS_PKE_LIST_H

typedef struct pke_list_el {
    void            *data;
    struct pke_list_el  *next;
} pke_list_el_t;

typedef struct pke_list {
    int             size;
    int             (*match)(const void *key1, const void *key2);
    void            (*destroy)(void *data);
    pke_list_el_t       *head;
    pke_list_el_t       *tail;
} pke_list_t;

void pke_list_init(pke_list_t *list, void (*destroy)(void *data));

void pke_list_destroy(pke_list_t *list);

int pke_list_ins_next(pke_list_t *list, pke_list_el_t *element, const void *data);

int pke_list_rem_next(pke_list_t *list, pke_list_el_t *element, void **data);

#define pke_list_size(list) ((list)->size)

#define pke_list_head(list) ((list)->head)

#define pke_list_tail(list) ((list)->tail)

#define pke_list_is_head(element) ((element)->prev == NULL ? 1 : 0)

#define pke_list_is_tail(element) ((element)->next == NULL ? 1 : 0)

#define pke_list_data(element) ((element)->data)

#define pke_list_next(element) ((element)->next)

#endif //PKEALGORITHMS_PKE_LIST_H
