#include "../../custom_matrix.h"

int custom_determinant(matrix_t *A, double *result) {
  int error = OK;
  if (!valid_matrix(A)) {
    error = INVALID_MATRIX;
  } else if (A->rows != A->columns) {
    error = CALCULATION_ERROR;
  }
  if (A->rows == 1 && error == OK) {
    *result = A->matrix[0][0];
  } else if (error == OK) {
    double determinant = INIT_ZERO;
    for (int i = 0; i < A->rows; i++) {
      double minor = INIT_ZERO, minor_sign = INIT_ZERO;
      minor = get_minor(0, i, A);
      minor_sign = get_minor_sign(0, i);
      determinant += A->matrix[0][i] * minor * minor_sign;
    }

    *result = determinant;
  }

  return error;
}