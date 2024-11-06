#include "../test.h"

START_TEST(mult_matrix_1) {
  matrix_t first_mtrx = INIT_MTRX, second_mtrx = INIT_MTRX, third_mtrx = INIT_MTRX;
  custom_create_matrix(3, 2, &first_mtrx);
  custom_create_matrix(2, 3, &second_mtrx);
  fill_matrix(&first_mtrx, mtrx_size(&first_mtrx), 1.0, 4.0,
                                                   2.0, 5.0,
                                                   3.0, 6.0);
  fill_matrix(&second_mtrx, mtrx_size(&second_mtrx), 1.0,-1.0, 1.0,
                                                     2.0, 3.0, 4.0);
  int res = custom_mult_matrix(&first_mtrx, &second_mtrx, &third_mtrx);
  ck_assert_double_lt(custom_fabs(third_mtrx.matrix[0][0] -  9.0), ACCURACY);
  ck_assert_double_lt(custom_fabs(third_mtrx.matrix[0][1] - 11.0), ACCURACY);
  ck_assert_double_lt(custom_fabs(third_mtrx.matrix[0][2] - 17.0), ACCURACY);
  ck_assert_double_lt(custom_fabs(third_mtrx.matrix[1][0] - 12.0), ACCURACY);
  ck_assert_double_lt(custom_fabs(third_mtrx.matrix[1][1] - 13.0), ACCURACY);
  ck_assert_double_lt(custom_fabs(third_mtrx.matrix[1][2] - 22.0), ACCURACY);
  ck_assert_double_lt(custom_fabs(third_mtrx.matrix[2][0] - 15.0), ACCURACY);
  ck_assert_double_lt(custom_fabs(third_mtrx.matrix[2][1] - 15.0), ACCURACY);
  ck_assert_double_lt(custom_fabs(third_mtrx.matrix[2][2] - 27.0), ACCURACY);
  ck_assert_int_eq(res, OK);
  custom_remove_matrix(&first_mtrx);
  custom_remove_matrix(&second_mtrx);
  custom_remove_matrix(&third_mtrx);
} END_TEST

START_TEST(mult_matrix_2) {
  matrix_t first_mtrx = INIT_MTRX, second_mtrx = INIT_MTRX, third_mtrx = INIT_MTRX;
  custom_create_matrix(3, 2, &first_mtrx);
  custom_create_matrix(2, 3, &second_mtrx);
  fill_matrix(&first_mtrx, mtrx_size(&first_mtrx), 1.0, 4.0,
                                                   2.0, 5.0,
                                                   3.0, 6.0);
  fill_matrix(&second_mtrx, mtrx_size(&second_mtrx), 1.0,-1.0, 1.0,
                                                     2.0, 3.0, 4.0);
  int res = custom_mult_matrix(&second_mtrx, &first_mtrx, &third_mtrx);
  ck_assert_double_lt(custom_fabs(third_mtrx.matrix[0][0] -  2.0), ACCURACY);
  ck_assert_double_lt(custom_fabs(third_mtrx.matrix[0][1] -  5.0), ACCURACY);
  ck_assert_double_lt(custom_fabs(third_mtrx.matrix[1][0] - 20.0), ACCURACY);
  ck_assert_double_lt(custom_fabs(third_mtrx.matrix[1][1] - 47.0), ACCURACY);
  ck_assert_int_eq(res, OK);
  custom_remove_matrix(&first_mtrx);
  custom_remove_matrix(&second_mtrx);
  custom_remove_matrix(&third_mtrx);
} END_TEST

START_TEST(mult_matrix_3) {
  matrix_t first_mtrx = INIT_MTRX,
           second_mtrx = INIT_MTRX,
           third_mtrx = INIT_MTRX;
  custom_create_matrix(0, 0, &first_mtrx);
  custom_create_matrix(0, 0, &second_mtrx);
  int result = custom_mult_matrix(&first_mtrx, &second_mtrx, &third_mtrx);
  ck_assert_int_eq(result, INVALID_MATRIX);
  custom_remove_matrix(&first_mtrx);
  custom_remove_matrix(&second_mtrx);
  custom_remove_matrix(&third_mtrx);
} END_TEST

Suite *test_mult_matrix() {
  Suite *s = suite_create(BLUE"-=MTRX_MULT_MATRIX=-"RESET);
  TCase *tc = tcase_create(RED"mtrx_mult_matrix_tc"RESET);

  tcase_add_test(tc, mult_matrix_1);
  tcase_add_test(tc, mult_matrix_2);
  tcase_add_test(tc, mult_matrix_3);

  suite_add_tcase(s, tc);
  return s;
}