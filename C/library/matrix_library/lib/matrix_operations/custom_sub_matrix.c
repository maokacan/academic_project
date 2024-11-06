#include "../../custom_matrix.h"

int custom_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = OK;
  if (!valid_matrix(A) || !valid_matrix(B)) {
    error = INVALID_MATRIX;
  } else if (A->rows != B->rows || A->columns != B->columns) {
    error = CALCULATION_ERROR;
  } else {
    error = custom_create_matrix(A->rows, A->columns, result);
  }
  if (error == OK) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
      }
    }
  }
  return error;
}