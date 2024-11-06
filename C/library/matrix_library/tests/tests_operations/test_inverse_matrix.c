#include "../test.h"

START_TEST(inverse_matrix_1) {
  matrix_t first_mtrx = INIT_MTRX, result = INIT_MTRX;
  custom_create_matrix(4, 4, &first_mtrx);
  fill_matrix(&first_mtrx, mtrx_size(&first_mtrx), 1.0, 3.0, 5.0, 8.0,
                                                   9.0, 9.0, 1.0, 2.0,
                                                   2.0, 2.0, 2.0, 2.0,
                                                   3.0, 6.0, 7.0, 2.0);
  int res = custom_inverse_matrix(&first_mtrx, &result);
  ck_assert_double_lt(custom_fabs(result.matrix[0][0] - -0.25000000000), ACCURACY);
  ck_assert_double_lt(custom_fabs(result.matrix[0][1] - -0.08333330000), ACCURACY);
  ck_assert_double_lt(custom_fabs(result.matrix[0][2] -  1.25000000000), ACCURACY);
  ck_assert_double_lt(custom_fabs(result.matrix[0][3] - -0.16666666670), ACCURACY);
  ck_assert_double_lt(custom_fabs(result.matrix[1][0] -  0.23076923080), ACCURACY);
  ck_assert_double_lt(custom_fabs(result.matrix[1][1] -  0.20512820510), ACCURACY);
  ck_assert_double_lt(custom_fabs(result.matrix[1][2] - -1.30769230770), ACCURACY);
  ck_assert_double_lt(custom_fabs(result.matrix[1][3] -  0.17948717950), ACCURACY);
  ck_assert_double_lt(custom_fabs(result.matrix[2][0] - -0.13461538460), ACCURACY);
  ck_assert_double_lt(custom_fabs(result.matrix[2][1] - -0.14743589740), ACCURACY);
  ck_assert_double_lt(custom_fabs(result.matrix[2][2] -  0.59615384620), ACCURACY);
  ck_assert_double_lt(custom_fabs(result.matrix[2][3] -  0.08974358974), ACCURACY);
  ck_assert_double_lt(custom_fabs(result.matrix[3][0] -  0.15384615380), ACCURACY);
  ck_assert_double_lt(custom_fabs(result.matrix[3][1] -  0.02564102564), ACCURACY);
  ck_assert_double_lt(custom_fabs(result.matrix[3][2] - -0.03846153846), ACCURACY);
  ck_assert_double_lt(custom_fabs(result.matrix[3][3] - -0.10256410260), ACCURACY);
  ck_assert_int_eq(res, OK);
  custom_remove_matrix(&first_mtrx);
  custom_remove_matrix(&result);
} END_TEST

START_TEST(inverse_matrix_2) {
  matrix_t first_mtrx = INIT_MTRX, result = INIT_MTRX;
  custom_create_matrix(5, 5, &first_mtrx);
  fill_matrix(&first_mtrx, mtrx_size(&first_mtrx), 1.0, 3.0, 5.0, 8.0, 3.0,
                                                   9.0, 9.0, 1.0, 2.0, 5.0,
                                                   2.0, 2.0, 2.0, 2.0, 4.0,
                                                   3.0, 6.0, 7.0, 2.0, 1.0,
                                                   8.0, 9.0, 2.0, 7.0, 6.0);
  int res = custom_inverse_matrix(&first_mtrx, &result);
  ck_assert_double_lt(custom_fabs(result.matrix[0][0] -  1.69615384620), ACCURACY);
  ck_assert_double_lt(custom_fabs(result.matrix[0][1] -  2.25769230770), ACCURACY);
  ck_assert_double_lt(custom_fabs(result.matrix[0][2] - -0.61153846150), ACCURACY);
  ck_assert_double_lt(custom_fabs(result.matrix[0][3] - -0.73076923080), ACCURACY);
  ck_assert_double_lt(custom_fabs(result.matrix[0][4] - -2.20000000000), ACCURACY);
  ck_assert_double_lt(custom_fabs(result.matrix[1][0] - -1.53846153850), ACCURACY);
  ck_assert_double_lt(custom_fabs(result.matrix[1][1] - -1.92307692310), ACCURACY);
  ck_assert_double_lt(custom_fabs(result.matrix[1][2] -  0.38461538460), ACCURACY);
  ck_assert_double_lt(custom_fabs(result.matrix[1][3] -  0.69230769230), ACCURACY);
  ck_assert_double_lt(custom_fabs(result.matrix[1][4] -  2.00000000000), ACCURACY);
  ck_assert_double_lt(custom_fabs(result.matrix[2][0] -  0.57307692310), ACCURACY);
  ck_assert_double_lt(custom_fabs(result.matrix[2][1] -  0.70384615380), ACCURACY);
  ck_assert_double_lt(custom_fabs(result.matrix[2][2] - -0.08076923077), ACCURACY);
  ck_assert_double_lt(custom_fabs(result.matrix[2][3] - -0.11538461540), ACCURACY);
  ck_assert_double_lt(custom_fabs(result.matrix[2][4] - -0.80000000000), ACCURACY);
  ck_assert_double_lt(custom_fabs(result.matrix[3][0] -  0.33076923080), ACCURACY);
  ck_assert_double_lt(custom_fabs(result.matrix[3][1] -  0.23846153850), ACCURACY);
  ck_assert_double_lt(custom_fabs(result.matrix[3][2] - -0.20769230770), ACCURACY);
  ck_assert_double_lt(custom_fabs(result.matrix[3][3] - -0.15384615380), ACCURACY);
  ck_assert_double_lt(custom_fabs(result.matrix[3][4] - -0.20000000000), ACCURACY);
  ck_assert_double_lt(custom_fabs(result.matrix[4][0] - -0.53076923080), ACCURACY);
  ck_assert_double_lt(custom_fabs(result.matrix[4][1] - -0.63846153850), ACCURACY);
  ck_assert_double_lt(custom_fabs(result.matrix[4][2] -  0.50769230770), ACCURACY);
  ck_assert_double_lt(custom_fabs(result.matrix[4][3] -  0.15384615380), ACCURACY);
  ck_assert_double_lt(custom_fabs(result.matrix[4][4] -  0.60000000000), ACCURACY);
  ck_assert_int_eq(res, OK);
  custom_remove_matrix(&first_mtrx);
  custom_remove_matrix(&result);
} END_TEST

START_TEST(inverse_matrix_3) {
  matrix_t first_mtrx = INIT_MTRX, result = INIT_MTRX;
  custom_create_matrix(0, 0, &first_mtrx);
  int res = custom_inverse_matrix(&first_mtrx, &result);
  ck_assert_int_eq(res, INVALID_MATRIX);
  custom_remove_matrix(&first_mtrx);
  custom_remove_matrix(&result);
} END_TEST

START_TEST(inverse_matrix_4) {
  matrix_t first_mtrx = INIT_MTRX, result = INIT_MTRX;
  custom_create_matrix(5, 4, &first_mtrx);
  fill_matrix(&first_mtrx, mtrx_size(&first_mtrx), 1.0, 3.0, 5.0, 8.0,
                                                   9.0, 9.0, 1.0, 2.0,
                                                   2.0, 2.0, 2.0, 2.0,
                                                   3.0, 6.0, 7.0, 2.0,
                                                   8.0, 9.0, 2.0, 7.0);
  int res = custom_inverse_matrix(&first_mtrx, &result);
  ck_assert_int_eq(res, CALCULATION_ERROR);
  custom_remove_matrix(&first_mtrx);
  custom_remove_matrix(&result);
} END_TEST

Suite *test_inverse_matrix() {
  Suite *s = suite_create(BLUE"-=MTRX_INVERSE=-"RESET);
  TCase *tc = tcase_create(RED"mtrx_inverse_tc"RESET);

  tcase_add_test(tc, inverse_matrix_1);
  tcase_add_test(tc, inverse_matrix_2);
  tcase_add_test(tc, inverse_matrix_3);
  tcase_add_test(tc, inverse_matrix_4);

  suite_add_tcase(s, tc);
  return s;
}