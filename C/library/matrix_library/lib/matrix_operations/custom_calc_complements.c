#include "../../custom_matrix.h"

int custom_calc_complements(matrix_t *A, matrix_t *result) {
  int error = OK;
  if (!valid_matrix(A)) {
    error = INVALID_MATRIX;
  } else if (A->rows != A->columns) {
    error = CALCULATION_ERROR;
  } else {
    error = custom_create_matrix(A->rows, A->rows, result);
  }
  if (error == OK) {
    for (int i = 0; i < result->rows; i++) {
      for (int j = 0; j < result->rows; j++) {
        double minor = INIT_ZERO, minor_sign = INIT_ZERO;
        minor = get_minor(i, j, A);
        minor_sign = get_minor_sign(i, j);
        result->matrix[i][j] = minor * minor_sign;
      }
    }
  }

  return error;
}
