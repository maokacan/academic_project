#include "../../custom_matrix.h"

int custom_transpose(matrix_t *A, matrix_t *result) {
  int error = OK;
  if (!valid_matrix(A)) {
    error = INVALID_MATRIX;
  } else {
    error = custom_create_matrix(A->columns, A->rows, result);
  }
  if (error == OK) {
    for (int i = 0; i < result->rows; i++) {
      for (int j = 0; j < result->columns; j++) {
        result->matrix[i][j] = A->matrix[j][i];
      }
    }
  }
  return error;
}