#include "../../custom_matrix.h"

int custom_mult_number(matrix_t *A, double number, matrix_t *result) {
  int error = OK;
  if (!valid_matrix(A)) {
    error = INVALID_MATRIX;
  } else {
    error = custom_create_matrix(A->rows, A->columns, result);
  }
  if (error == OK) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
      }
    }
  }
  return error;
}