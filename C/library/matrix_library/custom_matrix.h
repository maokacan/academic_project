//
// Created by maokacan on 06.11.2024.
// tg: @chrstfr
//

#ifndef CUS_MATRIX_H
#define CUS_MATRIX_H

#include "./lib/operations_helpers.h"

int custom_create_matrix(int rows, int columns, matrix_t *result);
void custom_remove_matrix(matrix_t *A);
int custom_eq_matrix(matrix_t *A, matrix_t *B);
int custom_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int custom_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int custom_mult_number(matrix_t *A, double number, matrix_t *result);
int custom_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int custom_transpose(matrix_t *A, matrix_t *result);
int custom_determinant(matrix_t *A, double *result);
int custom_calc_complements(matrix_t *A, matrix_t *result);
int custom_inverse_matrix(matrix_t *A, matrix_t *result);

// minor operations
int get_minor_matrix(int row, int column, matrix_t *A, matrix_t *B);
double get_minor(int row, int column, matrix_t *A);
double get_minor_sign(int i, int j);
// minor operations

#endif  // CUS_MATRIX_H
