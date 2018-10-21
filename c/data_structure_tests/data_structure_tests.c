//
// Created by pookie on 9/23/18.
//

//
// Created by pookie on 9/1/18.
//

#include "../dependencies/munit/munit.h"
#include "../lib/data_structures.h"

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

static MunitResult dlist_init_should_initialize_list_with_expected_default_values(const MunitParameter params[], void *fixture) {
    dlist_t *list = (dlist_t *) malloc(sizeof(dlist_t));

    dlist_init(list, destroy);

    munit_assert_int(dlist_size(list), ==, 0);
    munit_assert_ptr(list->destroy, ==, destroy);
    munit_assert_ptr(list->head, ==, NULL);
    munit_assert_ptr(list->tail, ==, NULL);

    free(list);

    return MUNIT_OK;
}

static MunitResult dlist_ins_next_should_insert_new_element_at_head_and_tail_for_empty_list(const MunitParameter params[], void *fixture) {
    dlist_t *list = (dlist_t *) malloc(sizeof(dlist_t));

    dlist_init(list, destroy);

    char *test = "test";

    dlist_ins_next(list, NULL, test);

    munit_assert_ptr(list->head->data, ==, test);
    munit_assert_ptr(list->tail->data, ==, test);
    munit_assert_string_equal(dlist_head(list)->data, "test");
    munit_assert_string_equal(dlist_tail(list)->data, "test");

    free(list);

    return MUNIT_OK;
}

static MunitResult dlist_ins_next_should_insert_new_element_at_tail_when_ins_after_current_tail(const MunitParameter params[], void *fixture) {
    dlist_t *list = (dlist_t *) malloc(sizeof(dlist_t));

    dlist_init(list, destroy);

    char *test = "test";
    char *test2 = "test2";

    dlist_ins_next(list, NULL, test);
    dlist_ins_next(list, dlist_tail(list), test2);

    munit_assert_ptr(list->head->data, ==, test);
    munit_assert_ptr(list->tail->data, ==, test2);
    munit_assert_string_equal(dlist_head(list)->data, "test");
    munit_assert_string_equal(dlist_tail(list)->data, "test2");

    free(list);

    return MUNIT_OK;
}

static MunitResult dlist_ins_prev_should_insert_new_element_at_head_when_inserted_before_head(const MunitParameter params[], void *fixture) {
    dlist_t *list = (dlist_t *) malloc(sizeof(dlist_t));

    dlist_init(list, destroy);

    char *test = "test";
    char *test2 = "test2";

    dlist_ins_prev(list, NULL, test);
    dlist_ins_prev(list, dlist_tail(list), test2);

    munit_assert_ptr(list->head->data, ==, test2);
    munit_assert_ptr(list->tail->data, ==, test);
    munit_assert_string_equal(dlist_head(list)->data, "test2");
    munit_assert_string_equal(dlist_tail(list)->data, "test");

    free(list);

    return MUNIT_OK;
}

static MunitResult dlist_ins_next_should_insert_new_element_between_head_and_tail_when_ins_after_current_head(const MunitParameter *params, void *fixture) {
    dlist_t *list = (dlist_t *) malloc(sizeof(dlist_t));

    dlist_init(list, destroy);

    char *test = "test";
    char *test2 = "test2";
    char *test3 = "test3";

    int retval1 = dlist_ins_next(list, NULL, test);
    int retval2 = dlist_ins_next(list, dlist_tail(list), test2);
    int retval3 = dlist_ins_next(list, dlist_head(list), test3);

    munit_assert_int(retval1, ==, 0);
    munit_assert_int(retval2, ==, 0);
    munit_assert_int(retval3, ==, 0);

    munit_assert_ptr(list->head->data, ==, test);
    munit_assert_ptr(list->head->next->data, ==, test3);
    munit_assert_ptr(list->tail->data, ==, test2);
    munit_assert_string_equal(dlist_head(list)->data, "test");
    munit_assert_string_equal(dlist_head(list)->next->data, "test3");
    munit_assert_string_equal(dlist_tail(list)->data, "test2");

    return MUNIT_OK;
}

static MunitResult dlist_destroy_should_free_list_and_zero_allocated_memory(
        const MunitParameter *params, void *fixture) {
    dlist_t *list = (dlist_t *) malloc(sizeof(dlist_t));

    dlist_init(list, destroy);

    char *test = "test";
    char *test2 = "test2";
    char *test3 = "test3";

    dlist_ins_next(list, NULL, test);
    dlist_ins_next(list, dlist_tail(list), test2);
    dlist_ins_next(list, dlist_head(list), test3);

    dlist_destroy(list);

    int *freedList = (int *)list;
    munit_assert_int(*freedList, ==, 0);

    return MUNIT_OK;
}


static MunitTest tests[] = {
        TESTCASE(dlist_init_should_initialize_list_with_expected_default_values),
        TESTCASE(dlist_ins_next_should_insert_new_element_at_head_and_tail_for_empty_list),
        TESTCASE(dlist_ins_next_should_insert_new_element_at_tail_when_ins_after_current_tail),
        TESTCASE(dlist_ins_next_should_insert_new_element_between_head_and_tail_when_ins_after_current_head),
        TESTCASE(dlist_destroy_should_free_list_and_zero_allocated_memory),
        TESTCASE(dlist_ins_prev_should_insert_new_element_at_head_when_inserted_before_head),
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