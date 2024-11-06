//
// Created by maokacan on 06.11.2024.
// tg: @chrstfr
//

#ifndef TESTS_HELPERS_H
#define TESTS_HELPERS_H

#include <stdarg.h>

#include "../lib/operations_helpers.h"

int fill_matrix(matrix_t *var, int count, ...);
void fill_matrix_random(matrix_t *var);
int get_element(matrix_t *var, int row, int column, double *value);
int set_element(matrix_t *var, int row, int column, double value);

#endif  // TESTS_HELPERS_H
