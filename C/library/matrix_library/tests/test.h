//
// Created by maokacan on 07.11.2024.
// tg: @chrstfr
//

#ifndef TEST_H
#define TEST_H

#define RESET "\033[0m"
#define RED "\033[0;91m"
#define GREEN "\033[32m"
#define BLUE "\033[0;94m"
#define PURPLE "\033[45m"

#define ACCURACY 1e-7

#include <check.h>

#include "../custom_matrix.h"
#include "tests_helpers.h"

void run_tests();

Suite *test_create();
Suite *test_remove();
Suite *test_equal();
Suite *test_sum();
Suite *test_sub();
Suite *test_transpose();
Suite *test_mult_number();
Suite *test_mult_matrix();
Suite *test_calc_complements();
Suite *test_determinant();
Suite *test_inverse_matrix();

#endif  // TEST_H
