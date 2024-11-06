#include "../../custom_matrix.h"

int custom_create_matrix(int rows, int columns, matrix_t *result) {
  int error = OK;
  if (rows <= 0 || columns <= 0) {
    error = INVALID_MATRIX;
  } else {
    result->matrix = (double **)malloc(rows * sizeof(double *));
    //// error during memory allocation
    //    if (result->matrix == NULL) {
    //      error = INVALID_MATRIX;
    //    }
    //// end
  }
  if (error == OK) {
    result->rows = rows;
    result->columns = columns;
    for (int i = 0; i < rows; ++i) {
      result->matrix[i] = (double *)malloc(columns * sizeof(double));
      //// TODO: come up with a test case
      //            if (result->matrix[i] == NULL) {
      //              for (int j = 0; j < i; ++j) {
      //                free(result->matrix[j]);
      //              }
      //              free(result->matrix);
      //              i = rows;
      //              result->rows = 0;
      //              result->columns = 0;
      //              error = INVALID_MATRIX;
      //            }
      //// for this (error during memory allocation)
    }
  }
  return error;
}
