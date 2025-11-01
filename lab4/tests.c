#include "minunit.h"
#include "lab4.h"

// Задание 1 (творческое). swap
// Напишите функцию swap(int *i, int *j), которая меняет значения двух ячеек местами.
// Напишите как можно больше тестов для этой функции (не меньше 10)
// На звёздочку: используйте фреймворк наподобие MinUnit https://github.com/siu/minunit
MU_TEST(test_swap_basic) {
    int a = 5, b = 10;
    swap(&a, &b);
    mu_assert_int_eq(10, a);
    mu_assert_int_eq(5, b);
}

MU_TEST(test_swap_same) {
    int a = 7;
    swap(&a, &a);
    mu_assert_int_eq(7, a);
}

MU_TEST(test_swap_negative) {
    int a = -1, b = 1;
    swap(&a, &b);
    mu_assert_int_eq(1, a);
    mu_assert_int_eq(-1, b);
}

MU_TEST(test_swap_zero) {
    int a = 0, b = 5;
    swap(&a, &b);
    mu_assert_int_eq(5, a);
    mu_assert_int_eq(0, b);
}

MU_TEST(test_swap_large) {
    int a = 1000000, b = 2000000;
    swap(&a, &b);
    mu_assert_int_eq(2000000, a);
    mu_assert_int_eq(1000000, b);
}

MU_TEST(test_swap_small) {
    int a = -1000000, b = -2000000;
    swap(&a, &b);
    mu_assert_int_eq(-2000000, a);
    mu_assert_int_eq(-1000000, b);
}

MU_TEST(test_swap_positive_negative) {
    int a = 100, b = -50;
    swap(&a, &b);
    mu_assert_int_eq(-50, a);
    mu_assert_int_eq(100, b);
}

MU_TEST(test_swap_max_int) {
    int a = INT_MAX, b = INT_MIN;
    swap(&a, &b);
    mu_assert_int_eq(INT_MIN, a);
    mu_assert_int_eq(INT_MAX, b);
}

MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(test_swap_basic);
    MU_RUN_TEST(test_swap_same);
    MU_RUN_TEST(test_swap_negative);
    MU_RUN_TEST(test_swap_zero);
    MU_RUN_TEST(test_swap_large);
    MU_RUN_TEST(test_swap_small);
    MU_RUN_TEST(test_swap_positive_negative);
    MU_RUN_TEST(test_swap_max_int);
}