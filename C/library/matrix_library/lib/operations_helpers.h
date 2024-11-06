//
// Created by maokacan on 05.11.2024.
// tg: @chrstfr
//

#ifndef OPERATIONS_HELPERS_H
#define OPERATIONS_HELPERS_H

// #define CUS_EPS 1e-7
#include "macro_help.h"

int valid_matrix(matrix_t *A);
int mtrx_size(matrix_t *var);

// void copy_matrix(matrix_t *source, matrix_t *destination);

//// instead of the math.h library
long double custom_fabs(double x);
// double custom_floor(double x);
// double custom_ceil(double x);
// double custom_round(double x);
// double round_to_seven_decimals(double value);
////instead of the math.h library

#endif  // OPERATIONS_HELPERS_H
