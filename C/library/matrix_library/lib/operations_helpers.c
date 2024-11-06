#include "operations_helpers.h"

int valid_matrix(matrix_t *A) {
  int validate = (A->matrix != NULL && A->rows > 0 && A->columns > 0);
  return validate;
}

/* returns the size of the matrix
 * or
 * returns -1 if the matrix is invalidation
 */
int mtrx_size(matrix_t *var) {
  int num = -1;
  if (valid_matrix(var)) {
    num = (var->rows * var->columns);
  }
  return num;
}

// void copy_matrix(matrix_t *source, matrix_t *destination) {
//   for (int i = 0; i < source->rows; i++) {
//     for (int j = 0; j < source->columns; j++) {
//       destination->matrix[i][j] = source->matrix[i+1][j+1];
//     }
//   }
// }

//// instead of the math.h library
long double custom_fabs(double x) {
  if (x < 0) x *= -1.0;
  return x;
}
// double custom_floor(double x) {
//   int intPart = (int)x;
//   return (x < 0 && x != intPart) ? intPart - 1 : intPart;
// }
// double custom_ceil(double x) {
//   int intPart = (int)x;
//   return (x > 0 && x != intPart) ? intPart + 1 : intPart;
// }
// double custom_round(double x) {
//   return (x >= 0.0) ? custom_floor(x + 0.5) : custom_ceil(x - 0.5);
// }
// double round_to_eight_decimals(double value) {
//   return custom_round(value * CUS_EPS) / CUS_EPS;
// }
//// instead of the math.h library
