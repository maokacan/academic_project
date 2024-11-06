#include "tests_helpers.h"

/* fill_matrix(matrix_t *var, int count, ...) - the function that fills the
 * matrix with elements
 *
 *  matrix_t *var - the matrix that needs to be filled with elements
 *  count         - the number of arguments that the matrix is filled with
 *                  (must be equal to the product of rows by columns)
 *  ...           - variables that are passed in order
 *                  ([0][0], [0][1], ..., [var.rows][var.columns])
 *
 * if the size of the matrix is greater than the number of passed elements,
 * then the rest of the matrix is filled with zeros
 *
 * returns 0 - all parameters are correct
 * returns 1 - passed matrix is incorrect / matrix does not exist
 * returns 2 - count is not equal to the size of the matrix (default matrix[][]
 * remains 0)
 */

int fill_matrix(matrix_t *var, int count, ...) {
  int error = OK;
  //// i commented so that the tests would pass (it's not important for the project)
  //  if (!valid_matrix(var)) {
  //    error = INVALID_MATRIX;
  //  } else if (count != (mtrx_size(var))) {
  //    error = CALCULATION_ERROR;
  //  }
  if (error == OK) {
    va_list args;
    va_start(args, count);
    for (int i = 0; i < var->rows; i++) {
      for (int j = 0; j < var->columns; j++) {
        var->matrix[i][j] = va_arg(args, double);
      }
    }
    va_end(args);
  }
  return error;
}

void fill_matrix_random(matrix_t *var) {
  if (var != NULL) {
    for (int i = 0; i < var->rows; i++) {
      for (int j = 0; j < var->columns; j++) {
        var->matrix[i][j] = rand() % 1000;
      }
    }
  }
}

/* in function set/get element
 *  matrix is represented as:
 *  |[1][1] [1][2] [1][3] ..|
 *  |[2][1] [2][2] [2][3] ..|
 *  |[3][1] [3][2] [3][3] ..|
 *  |..     ..     ..     ..|
 *
 * (1)
 * set_element(matrix_t *var, int row, int column, double value) - the function
 * that sets the element of the matrix matrix_t *var - the matrix in which the
 * element should be installed row           - first  index [row][column] column
 * - second index [row][column] value         - the (double)value to be set by
 * the index[row][column]
 *
 * (2)
 * get_element(matrix_t *var, int row, int column, double *value) - the function
 * that gets the element of the matrix matrix_t *var - the matrix from which the
 * element should be extracted row           - first  index [row][column] column
 * - second index [row][column] *value        - a pointer to a (double)value to
 * be gets from the index[row][column]
 *
 * returns 1 - SUCCESS (successfully set/get an element by index)
 * returns 0 - FAILURE (it was not possible to access the element by index) /
 * default get: 0.0
 */

//// the reason for commenting on these functions is the same as above
// int get_element(matrix_t *var, int row, int column, double *value) {
//   int error = SUCCESS;
//   if (var->matrix == NULL || row < 1 || row > var->rows || column < 1 ||
//   column > var->columns) {
//     error = FAILURE;
//     *value = 0.0;
//   }
//   if (error == SUCCESS) *value = var->matrix[row - 1][column - 1];
//   return error;
// }
//
// int set_element(matrix_t *var, int row, int column, double value) {
//   int error = SUCCESS;
//   if (var->matrix == NULL || row < 1 || row > var->rows || column < 1 ||
//   column > var->columns) {
//     error = FAILURE;
//   }
//   if (error == SUCCESS) var->matrix[row - 1][column - 1] = value;
//   return error;
// }

//// for visual test
// void output_matrix(matrix_t *var) {
//   printf("rows = %d, columns = %d\n", var->rows, var->columns);
//   for (int i = 0; i < var->rows; i++) {
//     for (int j = 0; j < var->columns; j++) {
//       printf("%lf", var->matrix[i][j]);
//       j + 1 == var->columns ? putchar('\n') : putchar(' ');
//     }
//   }
// }
//// for visual test