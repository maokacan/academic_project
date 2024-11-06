#include "../../custom_matrix.h"

int custom_eq_matrix(matrix_t *A, matrix_t *B) {
  int result = SUCCESS;
  if (A->rows != B->rows || A->columns != B->columns) {
    result = FAILURE;
  }
  if (result == SUCCESS) {
    for (int i = 0; i < A->rows; ++i) {
      for (int j = 0; j < A->columns; ++j) {
        //        if ((int)(A->matrix[i][j] * 1e7) != (int)(B->matrix[i][j] *
        //        1e7)) {
        if (custom_fabs(A->matrix[i][j] - B->matrix[i][j]) > 1e-7) {
          result = FAILURE;
        }
      }
    }
  }
  return result;
}