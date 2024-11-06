#include "../../custom_matrix.h"

int custom_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = OK;
  if (!valid_matrix(A) || !valid_matrix(B)) {
    error = INVALID_MATRIX;
  } else {
    error = custom_create_matrix(A->rows, B->columns, result);
  }
  if (error == OK) {
    int common_length = A->columns;
    for (int i = 0; i < result->rows; i++) {
      for (int j = 0; j < result->columns; j++) {
        result->matrix[i][j] = INIT_ZERO;
        for (int k = 0; k < common_length; k++) {
          result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
        }
      }
    }
  }
  return error;
}