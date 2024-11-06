#include "../test.h"

/*
 * |1.0 4.0|    |1.0 2.0 3.0|
 * |2.0 5.0| -> |4.0 5.0 6.0|
 * |3.0 6.0|
 */
START_TEST(transpose_1) {
  matrix_t first_mtrx = INIT_MTRX;
  matrix_t second_mtrx = INIT_MTRX;
  custom_create_matrix(3, 2, &first_mtrx);
  fill_matrix(&first_mtrx, mtrx_size(&first_mtrx), 1.0, 4.0,
                                                   2.0, 5.0,
                                                   3.0, 6.0);
  int res = custom_transpose(&first_mtrx, &second_mtrx);
  ck_assert_double_eq(second_mtrx.matrix[0][0], 1.0);
  ck_assert_double_eq(second_mtrx.matrix[0][1], 2.0);
  ck_assert_double_eq(second_mtrx.matrix[0][2], 3.0);
  ck_assert_double_eq(second_mtrx.matrix[1][0], 4.0);
  ck_assert_double_eq(second_mtrx.matrix[1][1], 5.0);
  ck_assert_double_eq(second_mtrx.matrix[1][2], 6.0);
  ck_assert_int_eq(res, OK);
  custom_remove_matrix(&first_mtrx);
  custom_remove_matrix(&second_mtrx);
} END_TEST

START_TEST(transpose_2) {
  matrix_t first_mtrx = INIT_MTRX;
  matrix_t second_mtrx = INIT_MTRX;
  custom_create_matrix(5, 5, &first_mtrx);
  fill_matrix_random(&first_mtrx);
  int res = custom_transpose(&first_mtrx, &second_mtrx);
  for (int i = 0; i < second_mtrx.rows; i++) {
    for (int j = 0; j < second_mtrx.columns; j++) {
      ck_assert_double_eq(second_mtrx.matrix[i][j], first_mtrx.matrix[j][i]);
    }
  }
  ck_assert_int_eq(res, OK);
  custom_remove_matrix(&first_mtrx);
  custom_remove_matrix(&second_mtrx);
} END_TEST

START_TEST(transpose_3) {
  matrix_t first_mtrx = INIT_MTRX;
  matrix_t second_mtrx = INIT_MTRX;
  custom_create_matrix(2, 8, &first_mtrx);
  fill_matrix_random(&first_mtrx);
  int res = custom_transpose(&first_mtrx, &second_mtrx);
  for (int i = 0; i < second_mtrx.rows; i++) {
    for (int j = 0; j < second_mtrx.columns; j++) {
      ck_assert_double_eq(second_mtrx.matrix[i][j], first_mtrx.matrix[j][i]);
    }
  }
  ck_assert_int_eq(res, OK);
  custom_remove_matrix(&first_mtrx);
  custom_remove_matrix(&second_mtrx);
} END_TEST

START_TEST(transpose_4) {
  matrix_t first_mtrx = INIT_MTRX, second_mtrx = INIT_MTRX;
  custom_create_matrix(-3, -2, &first_mtrx);
  int res = custom_transpose(&first_mtrx, &second_mtrx);
  ck_assert_int_eq(res, INVALID_MATRIX);
  custom_remove_matrix(&first_mtrx);
  custom_remove_matrix(&second_mtrx);
} END_TEST

Suite *test_transpose() {
  Suite *s = suite_create(BLUE"-=MTRX_TRANSPOSE=-"RESET);
  TCase *tc = tcase_create(RED"mtrx_transpose_tc"RESET);

  tcase_add_test(tc, transpose_1);
  tcase_add_test(tc, transpose_2);
  tcase_add_test(tc, transpose_3);
  tcase_add_test(tc, transpose_4);

  suite_add_tcase(s, tc);
  return s;
}