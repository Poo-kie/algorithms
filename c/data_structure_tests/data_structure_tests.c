//
// Created by pookie on 9/23/18.
//

#include "../dependencies/munit/munit.h"
#include "data_structures/data_structures.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-parameter"

#define TESTCASE(func) { \
    #func,/* name */ \
    func, /* test */ \
    NULL, /* setup */ \
    NULL, /* tear_down */ \
    MUNIT_TEST_OPTION_NONE, /* options */ \
    NULL /* parameters */ \
}

// we don't need to malloc each element
// to unit test here.  we just make sure
// the elements are all set to NULL
void destroy(void *data) {
    data = NULL;
}

// this file is going to get big.. but it's better than having to search through n files to find anything
// and have those do includes to use macros and such.  just add new test cases from the top

/****************************************************************************
 *
 * ------------------------------ stack -------------------------------------
 *
 ****************************************************************************/

static MunitResult pke_stack_push_should_add_element_to_top_of_stack(
        const MunitParameter *params, void *fixture) {

    pke_stack_t *stack = (pke_stack_t *) malloc(sizeof(pke_stack_t));

    pke_stack_init(stack, destroy);

    char *test = "test";
    char *test2 = "test2";
    char *test3 = "test3";

    pke_stack_push(stack, test);
    pke_stack_push(stack, test2);
    pke_stack_push(stack, test3);

    munit_assert_string_equal(pke_stack_top(stack), test3);
    munit_assert_string_equal(pke_stack_next_to_top(stack), test2);

    return MUNIT_OK;
}

/****************************************************************************
 *
 * ------------------------------ list --------------------------------------
 *
 ****************************************************************************/

static MunitResult pke_list_rem_next_should_remove_element_after_head_when_next_element_is_head(
        const MunitParameter *params, void *fixture) {
    pke_list_t *list = (pke_list_t *) malloc(sizeof(pke_list_t));

    pke_list_init(list, destroy);

    char *test = "test";
    char *test2 = "test2";
    char *test3 = "test3";

    void *data;

    pke_list_ins_next(list, NULL, test);
    pke_list_ins_next(list, pke_list_tail(list), test2);
    pke_list_ins_next(list, pke_list_head(list), test3);

    pke_list_rem_next(list, pke_list_head(list), &data);

    munit_assert_int(pke_list_size(list), ==, 2);

    munit_assert_ptr(list->head->data, ==, test);
    munit_assert_ptr(list->head->next->data, ==, list->tail->data);
    munit_assert_string_equal(pke_list_head(list)->data, "test");
    munit_assert_string_equal(pke_list_tail(list)->data, "test2");

    return MUNIT_OK;
}

static MunitResult pke_list_rem_next_should_remove_head_when_next_element_is_NULL(const MunitParameter *params,
                                                                                  void *fixture) {
    pke_list_t *list = (pke_list_t *) malloc(sizeof(pke_list_t));

    pke_list_init(list, destroy);

    char *test = "test";
    void *data;

    pke_list_ins_next(list, NULL, test);
    pke_list_rem_next(list, NULL, &data);

    munit_assert_true(pke_list_head(list) == NULL);
    munit_assert_true(pke_list_tail(list) == NULL);
    munit_assert_int(list->size, ==, 0);

    free(list);

    return MUNIT_OK;
}

static MunitResult pke_list_ins_next_should_insert_new_element_between_head_and_tail_when_ins_after_current_head(
        const MunitParameter *params, void *fixture) {
    pke_list_t *list = (pke_list_t *) malloc(sizeof(pke_list_t));

    pke_list_init(list, destroy);

    char *test = "test";
    char *test2 = "test2";
    char *test3 = "test3";

    int retval1 = pke_list_ins_next(list, NULL, test);
    int retval2 = pke_list_ins_next(list, pke_list_tail(list), test2);
    int retval3 = pke_list_ins_next(list, pke_list_head(list), test3);

    munit_assert_int(retval1, ==, 0);
    munit_assert_int(retval2, ==, 0);
    munit_assert_int(retval3, ==, 0);

    munit_assert_ptr(list->head->data, ==, test);
    munit_assert_ptr(list->head->next->data, ==, test3);
    munit_assert_ptr(list->tail->data, ==, test2);
    munit_assert_string_equal(pke_list_head(list)->data, "test");
    munit_assert_string_equal(pke_list_head(list)->next->data, "test3");
    munit_assert_string_equal(pke_list_tail(list)->data, "test2");

    return MUNIT_OK;
}

static MunitResult pke_list_ins_next_should_insert_new_element_at_tail_when_ins_after_current_tail(
        const MunitParameter *params, void *fixture) {
    pke_list_t *list = (pke_list_t *) malloc(sizeof(pke_list_t));

    pke_list_init(list, destroy);

    char *test = "test";
    char *test2 = "test2";

    pke_list_ins_next(list, NULL, test);
    pke_list_ins_next(list, pke_list_tail(list), test2);

    munit_assert_ptr(list->head->data, ==, test);
    munit_assert_ptr(list->tail->data, ==, test2);
    munit_assert_string_equal(pke_list_head(list)->data, "test");
    munit_assert_string_equal(pke_list_tail(list)->data, "test2");

    free(list);

    return MUNIT_OK;
}

static MunitResult pke_list_ins_next_should_insert_new_element_at_head_and_tail_for_empty_list(
        const MunitParameter *params, void *fixture) {
    pke_list_t *list = (pke_list_t *) malloc(sizeof(pke_list_t));

    pke_list_init(list, destroy);

    char *test = "test";

    pke_list_ins_next(list, NULL, test);

    munit_assert_ptr(list->head->data, ==, test);
    munit_assert_ptr(list->tail->data, ==, test);
    munit_assert_string_equal(pke_list_head(list)->data, "test");
    munit_assert_string_equal(pke_list_tail(list)->data, "test");

    free(list);

    return MUNIT_OK;
}

static MunitResult pke_list_destroy_should_free_list_and_zero_allocated_memory(
        const MunitParameter *params, void *fixture) {
    pke_list_t *list = (pke_list_t *) malloc(sizeof(pke_list_t));

    pke_list_init(list, destroy);

    char *test = "test";
    char *test2 = "test2";
    char *test3 = "test3";

    pke_list_ins_next(list, NULL, test);
    pke_list_ins_next(list, pke_list_tail(list), test2);
    pke_list_ins_next(list, pke_list_head(list), test3);

    pke_list_destroy(list);

    int *freelist = (int *)list;
    munit_assert_int(*freelist, ==, 0);

    return MUNIT_OK;
}

static MunitResult pke_list_init_should_initialize_list_with_expected_default_values(const MunitParameter *params,
                                                                                     void *fixture) {
    pke_list_t *list = (pke_list_t *) malloc(sizeof(pke_list_t));

    pke_list_init(list, destroy);

    munit_assert_int(pke_list_size(list), ==, 0);
    munit_assert_ptr(list->destroy, ==, destroy);
    munit_assert_ptr(list->head, ==, NULL);
    munit_assert_ptr(list->tail, ==, NULL);

    free(list);

    return MUNIT_OK;
}


static MunitTest tests[] = {
        TESTCASE(pke_stack_push_should_add_element_to_top_of_stack),
        TESTCASE(pke_list_rem_next_should_remove_element_after_head_when_next_element_is_head),
        TESTCASE(pke_list_rem_next_should_remove_head_when_next_element_is_NULL),
        TESTCASE(pke_list_ins_next_should_insert_new_element_between_head_and_tail_when_ins_after_current_head),
        TESTCASE(pke_list_ins_next_should_insert_new_element_at_tail_when_ins_after_current_tail),
        TESTCASE(pke_list_ins_next_should_insert_new_element_at_head_and_tail_for_empty_list),
        TESTCASE(pke_list_destroy_should_free_list_and_zero_allocated_memory),
        TESTCASE(pke_list_init_should_initialize_list_with_expected_default_values),
        /* Mark the end of the array with an entry where the test
         * function is NULL */
        { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

static const MunitSuite suite = {
        "/data-structures-tests/", /* name */
        tests, /* tests */
        NULL, /* suites */
        1, /* iterations */
        MUNIT_SUITE_OPTION_NONE /* options */
};

int main(int argc, char **argv) {
    return munit_suite_main(&suite, NULL, argc, argv);
}

#pragma clang diagnostic pop