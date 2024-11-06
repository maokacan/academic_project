#include "../test.h"

START_TEST(mult_number_1) {
  matrix_t first_mtrx = INIT_MTRX, result = INIT_MTRX;
  double value = 4.5;
  custom_create_matrix(3, 3, &first_mtrx);
  fill_matrix(&first_mtrx, mtrx_size(&first_mtrx), 1.9999999, 2.8888888, 3.7777777,
                                                   4.6666666, 5.5555555, 6.4444444,
                                                   7.3333333, 8.2222222, 9.1111111);
  int res = custom_mult_number(&first_mtrx, value, &result);
  ck_assert_double_lt(custom_fabs(result.matrix[0][0] - 8.999999550), ACCURACY);
  ck_assert_double_lt(custom_fabs(result.matrix[0][1] - 12.99999960), ACCURACY);
  ck_assert_double_lt(custom_fabs(result.matrix[0][2] - 16.99999965), ACCURACY);
  ck_assert_double_lt(custom_fabs(result.matrix[1][0] - 20.99999970), ACCURACY);
  ck_assert_double_lt(custom_fabs(result.matrix[1][1] - 24.99999975), ACCURACY);
  ck_assert_double_lt(custom_fabs(result.matrix[1][2] - 28.99999980), ACCURACY);
  ck_assert_double_lt(custom_fabs(result.matrix[2][0] - 32.99999985), ACCURACY);
  ck_assert_double_lt(custom_fabs(result.matrix[2][1] - 36.99999990), ACCURACY);
  ck_assert_double_lt(custom_fabs(result.matrix[2][2] - 40.99999995), ACCURACY);
  ck_assert_int_eq(res, OK);
  custom_remove_matrix(&first_mtrx);
  custom_remove_matrix(&result);
} END_TEST

START_TEST(mult_number_2) {
  matrix_t first_mtrx = INIT_MTRX,
           result = INIT_MTRX;
  custom_create_matrix(0, 0, &first_mtrx);
  double value = 4.5;
  int res = custom_mult_number(&first_mtrx, value, &result);
  ck_assert_int_eq(res, INVALID_MATRIX);
  custom_remove_matrix(&first_mtrx);
  custom_remove_matrix(&result);
} END_TEST

Suite *test_mult_number() {
  Suite *s = suite_create(BLUE"-=MTRX_MULT_NUMBER=-"RESET);
  TCase *tc = tcase_create(RED"mtrx_mult_number_tc"RESET);

  tcase_add_test(tc, mult_number_1);
  tcase_add_test(tc, mult_number_2);

  suite_add_tcase(s, tc);
  return s;
}