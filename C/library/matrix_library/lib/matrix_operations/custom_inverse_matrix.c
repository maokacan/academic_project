#include "../../custom_matrix.h"

int custom_inverse_matrix(matrix_t *A, matrix_t *result) {
  int error = OK;
  if (!valid_matrix(A)) {
    error = INVALID_MATRIX;
  } else if (A->rows != A->columns) {
    error = CALCULATION_ERROR;
  } else {
    error = custom_create_matrix(A->rows, A->columns, result);
  }
  if (error == OK) {
    double determinant = INIT_ZERO;
    matrix_t complement_mtrx = INIT_MTRX, transpose_comp_mtrx = INIT_MTRX;
    custom_determinant(A, &determinant);
    custom_calc_complements(A, &complement_mtrx);
    custom_transpose(&complement_mtrx, &transpose_comp_mtrx);
    custom_mult_number(&transpose_comp_mtrx, (1.0 / determinant), result);
    //    for (int i = 0; i < A->rows; i++) {
    //      for (int j = 0; j < A->columns; j++) {
    //        result->matrix[i][j] = complement_mtrx.matrix[j][i] / determinant;
    //      }
    //    }
    custom_remove_matrix(&complement_mtrx);
    custom_remove_matrix(&transpose_comp_mtrx);
  }

  return error;
}
