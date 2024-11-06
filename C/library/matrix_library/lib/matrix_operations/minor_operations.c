#include "../../custom_matrix.h"

int get_minor_matrix(int row, int column, matrix_t *A, matrix_t *B) {
  int error = OK;
  int m_i = 0, m_j = 0;
  for (int i = 0; i < A->rows; i++) {
    m_j = 0;
    if (i != row) {
      for (int j = 0; j < A->columns; j++) {
        if (j != column) {
          B->matrix[m_i][m_j++] = A->matrix[i][j];
        }
      }
      m_i++;
    }
  }
  return error;
}

double get_minor(int row, int column, matrix_t *A) {
  matrix_t minor = INIT_MTRX;
  custom_create_matrix(A->rows - 1, A->columns - 1, &minor);
  get_minor_matrix(row, column, A, &minor);
  double determinant = INIT_ZERO;
  custom_determinant(&minor, &determinant);
  custom_remove_matrix(&minor);
  return determinant;
}

double get_minor_sign(int i, int j) { return (i + j) % 2 == 0 ? 1.0 : -1.0; }