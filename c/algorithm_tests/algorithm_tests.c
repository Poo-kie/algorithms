//
// Created by pookie on 9/1/18.
//

#include "../dependencies/munit/munit.h"
#include "algorithms/pke_algorithms.h"

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

// this file is going to get big.. but it's better than having to search through n files to find anything
// and have those do includes to use macros and such.  just add new test cases from the top

static MunitResult swap_head_with_lowest_leftmost_coordinate_should_return_expected_coordinates(const MunitParameter params[], void *fixture)
{
    coordinate_t **cs = (coordinate_t **) malloc(4 * sizeof(coordinate_t));

    coordinate_t *c1 = (coordinate_t *) malloc(sizeof(coordinate_t));
    coordinate_t *c2 = (coordinate_t *) malloc(sizeof(coordinate_t));
    coordinate_t *c3 = (coordinate_t *) malloc(sizeof(coordinate_t));
    coordinate_t *c4 = (coordinate_t *) malloc(sizeof(coordinate_t));

    c1->x = 4;
    c1->y = 7;

    c2->x = 2;
    c2->y = 9;

    c3->x = 1;
    c3->y = 0;

    c4->x = 2;
    c4->y = 0;

    cs[0] = c1;
    cs[1] = c2;
    cs[2] = c3;
    cs[3] = c4;

    swap_head_with_lowest_leftmost_coordinate(cs, 4);

    munit_assert_int(cs[0]->x, ==, 1);
    munit_assert_int(cs[0]->y, ==, 0);
    munit_assert_int(cs[1]->x, ==, 2);
    munit_assert_int(cs[1]->y, ==, 9);
    munit_assert_int(cs[2]->x, ==, 4);
    munit_assert_int(cs[2]->y, ==, 7);
    munit_assert_int(cs[3]->x, ==, 2);
    munit_assert_int(cs[3]->y, ==, 0);

    free(cs);
    free(c1);
    free(c2);
    free(c3);
    free(c4);

    return MUNIT_OK;
}

static MunitResult CROSS_PRODUCT_DIRECTION_should_return_LEFT_if_value_is_positive(const MunitParameter params[], void *fixture)
{
    coordinate_t c1 = { .x = 2, .y = 2};
    coordinate_t c2 = { .x = 5, .y = 6};
    coordinate_t c3 = { .x = 4, .y = 7};

    double crossProduct = 7.0;

    munit_assert_double_equal(crossProduct, CROSS_PRODUCT(c1, c2, c3), 6);          // value is positive
    munit_assert_int((int)LEFT, ==, (int)CROSS_PRODUCT_DIRECTION(crossProduct));    // returns left

    return MUNIT_OK;
}

static MunitResult CROSS_PRODUCT_DIRECTION_should_return_RIGHT_if_value_is_negative(const MunitParameter params[], void *fixture)
{
    coordinate_t c1 = { .x = 2, .y = 2};
    coordinate_t c2 = { .x = 5, .y = 6};
    coordinate_t c3 = { .x = 9, .y = 3};

    double crossProduct = -25.0;

    munit_assert_double_equal(crossProduct, CROSS_PRODUCT(c1, c2, c3), 6);          // value is negative
    munit_assert_int((int)RIGHT, ==, (int)CROSS_PRODUCT_DIRECTION(crossProduct));   // returns right

    return MUNIT_OK;
}

static MunitResult CROSS_PRODUCT_DIRECTION_should_return_STRAIGHT_if_value_is_zero(const MunitParameter params[], void *fixture)
{
    coordinate_t c1 = { .x = 2, .y = 2};
    coordinate_t c2 = { .x = 4, .y = 4};
    coordinate_t c3 = { .x = 6, .y = 6};

    double crossProduct = 0.0;

    munit_assert_double_equal(crossProduct, CROSS_PRODUCT(c1, c2, c3), 6);              // value is zero
    munit_assert_int((int)STRAIGHT, ==, (int)CROSS_PRODUCT_DIRECTION(crossProduct));    // returns straight

    return MUNIT_OK;
}

static MunitResult CROSS_PRODUCT_should_return_cross_product_of_specified_coordinates(const MunitParameter params[], void *fixture)
{
    coordinate_t c1 = { .x = 2, .y = 2};
    coordinate_t c2 = { .x = 5, .y = 6};
    coordinate_t c3 = { .x = 4, .y = 7};

    double crossProduct = 7.0;

    munit_assert_double_equal(crossProduct, CROSS_PRODUCT(c1, c2, c3), 6);

    return MUNIT_OK;
}

static MunitResult VECTOR_X_should_return_x_value_as_difference_of_x_coordinates(const MunitParameter params[], void *fixture) {
    coordinate_t c1 = { .x = -2, .y = 31};
    coordinate_t c2 = { .x = 7, .y = 25};

    vector_t v = { .a = c1, .b = c2 };

    double vx = 9.0;

    munit_assert_double_equal(vx, VECTOR_X(v), 6);

    return MUNIT_OK;
}

static MunitResult VECTOR_Y_should_return_y_value_as_difference_of_y_coordinates(const MunitParameter params[], void *fixture) {
    coordinate_t c1 = { .x = -2, .y = 31};
    coordinate_t c2 = { .x = 7, .y = 25};

    vector_t v = { .a = c1, .b = c2 };

    double vy = -6.0;

    munit_assert_double_equal(vy, VECTOR_Y(v), 6);

    return MUNIT_OK;
}

static MunitResult VECTOR_MAGNITUDE_should_return_magnitude_of_x_and_y_values(const MunitParameter params[], void *fixture) {
    coordinate_t c1 = { .x = 2, .y = 2};
    coordinate_t c2 = { .x = 5, .y = 6};

    vector_t v = { .a = c1, .b = c2 };

    double magnitude = 5.0;

    munit_assert_double_equal(magnitude, VECTOR_MAGNITUDE(v), 6);

    return MUNIT_OK;
}

static MunitResult DOT_PRODUCT_should_return_dot_product_of_specified_vectors(const MunitParameter params[], void *fixture)
{
    coordinate_t c1 = { .x = 2, .y = 2};
    coordinate_t c2 = { .x = 5, .y = 6};
    coordinate_t c3 = { .x = 2, .y = 2};
    coordinate_t c4 = { .x = 5, .y = 6};

    vector_t v = { .a = c1, .b = c2 };
    vector_t v2 = { .a = c3, .b = c4 };

    double dotProduct = 25.0;

    munit_assert_double_equal(dotProduct, DOT_PRODUCT(v, v2), 6);

    return MUNIT_OK;
}

static MunitTest tests[] = {
        TESTCASE(swap_head_with_lowest_leftmost_coordinate_should_return_expected_coordinates),
        TESTCASE(VECTOR_X_should_return_x_value_as_difference_of_x_coordinates),
        TESTCASE(VECTOR_Y_should_return_y_value_as_difference_of_y_coordinates),
        TESTCASE(VECTOR_MAGNITUDE_should_return_magnitude_of_x_and_y_values),
        TESTCASE(DOT_PRODUCT_should_return_dot_product_of_specified_vectors),
        TESTCASE(CROSS_PRODUCT_should_return_cross_product_of_specified_coordinates),
        TESTCASE(CROSS_PRODUCT_DIRECTION_should_return_LEFT_if_value_is_positive),
        TESTCASE(CROSS_PRODUCT_DIRECTION_should_return_RIGHT_if_value_is_negative),
        TESTCASE(CROSS_PRODUCT_DIRECTION_should_return_STRAIGHT_if_value_is_zero),
        /* Mark the end of the array with an entry where the test
         * function is NULL */
        { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

static const MunitSuite suite = {
        "/algorithm-tests/", /* name */
        tests, /* tests */
        NULL, /* suites */
        1, /* iterations */
        MUNIT_SUITE_OPTION_NONE /* options */
};

int main(int argc, char **argv) {
    return munit_suite_main(&suite, NULL, argc, argv);
}

#pragma clang diagnostic pop