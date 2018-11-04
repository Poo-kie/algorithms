//
// Created by pookie on 9/11/18.
//

#ifndef PKEALGORITHMS_DATA_STRUCTURES_H
#define PKEALGORITHMS_DATA_STRUCTURES_H

/****************************************************************************
 *
 * ------------------------------ list --------------------------------------
 *
 ****************************************************************************/

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

#endif //PKEALGORITHMS_DATA_STRUCTURES_H
