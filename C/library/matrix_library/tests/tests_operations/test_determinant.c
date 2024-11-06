#include "../test.h"

START_TEST(determinant_1) {
  matrix_t first_mtrx = INIT_MTRX;
  double result;
  custom_create_matrix(4, 4, &first_mtrx);
  fill_matrix(&first_mtrx, mtrx_size(&first_mtrx), 1.0, 3.0, 5.0, 8.0,
                                                   9.0, 9.0, 1.0, 2.0,
                                                   2.0, 2.0, 2.0, 2.0,
                                                   3.0, 6.0, 7.0, 2.0);

  int res = custom_determinant(&first_mtrx, &result);
  ck_assert_double_lt(custom_fabs(result - 312.0), ACCURACY);
  ck_assert_int_eq(res, OK);
  custom_remove_matrix(&first_mtrx);
} END_TEST

START_TEST(determinant_2) {
  matrix_t first_mtrx = INIT_MTRX;
  double result;
  custom_create_matrix(5, 5, &first_mtrx);
  fill_matrix(&first_mtrx, mtrx_size(&first_mtrx), 1.0, 3.0, 5.0, 8.0, 3.0,
                                                   9.0, 9.0, 1.0, 2.0, 5.0,
                                                   2.0, 2.0, 2.0, 2.0, 4.0,
                                                   3.0, 6.0, 7.0, 2.0, 1.0,
                                                   8.0, 9.0, 2.0, 7.0, 6.0);

  int res = custom_determinant(&first_mtrx, &result);
  ck_assert_double_lt(custom_fabs(result - 520.0), ACCURACY);
  ck_assert_int_eq(res, OK);
  custom_remove_matrix(&first_mtrx);
} END_TEST

START_TEST(determinant_3) {
  matrix_t first_mtrx = INIT_MTRX;
  double result = INIT_ZERO;
  custom_create_matrix(0, 0, &first_mtrx);
  int res = custom_determinant(&first_mtrx, &result);
  ck_assert_int_eq(res, INVALID_MATRIX);
  custom_remove_matrix(&first_mtrx);
} END_TEST

START_TEST(determinant_4) {
  matrix_t first_mtrx = INIT_MTRX;
  double result = INIT_ZERO;
  custom_create_matrix(5, 4, &first_mtrx);
  fill_matrix(&first_mtrx, mtrx_size(&first_mtrx), 1.0, 3.0, 5.0, 8.0,
                                                   9.0, 9.0, 1.0, 2.0,
                                                   2.0, 2.0, 2.0, 2.0,
                                                   3.0, 6.0, 7.0, 2.0,
                                                   8.0, 9.0, 2.0, 7.0);
  int res = custom_determinant(&first_mtrx, &result);
  ck_assert_int_eq(res, CALCULATION_ERROR);
  custom_remove_matrix(&first_mtrx);
} END_TEST

Suite *test_determinant() {
  Suite *s = suite_create(BLUE"-=MTRX_DETERMINANT=-"RESET);
  TCase *tc = tcase_create(RED"mtrx_determinant_tc"RESET);

  tcase_add_test(tc, determinant_1);
  tcase_add_test(tc, determinant_2);
  tcase_add_test(tc, determinant_3);
  tcase_add_test(tc, determinant_4);

  suite_add_tcase(s, tc);
  return s;
}