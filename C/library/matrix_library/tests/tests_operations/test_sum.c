#include "../test.h"

START_TEST(sum_1) {
  matrix_t first_mtrx = INIT_MTRX;
  matrix_t second_mtrx = INIT_MTRX;
  matrix_t third_mtrx = INIT_MTRX;
  custom_create_matrix(3, 3, &first_mtrx);
  custom_create_matrix(3, 3, &second_mtrx);
  fill_matrix(&first_mtrx, mtrx_size(&first_mtrx), 1.0, 2.0, 3.0,
                                                   4.0, 5.0, 6.0,
                                                   7.0, 8.0, 9.0);
  fill_matrix(&second_mtrx, mtrx_size(&second_mtrx), 9.0, 8.0, 7.0,
                                                     6.0, 5.0, 4.0,
                                                     3.0, 2.0, 1.0);
  int res = custom_sum_matrix(&first_mtrx, &second_mtrx, &third_mtrx);
  ck_assert_double_lt(custom_fabs(third_mtrx.matrix[0][0] - 10.0), ACCURACY);
  ck_assert_double_lt(custom_fabs(third_mtrx.matrix[0][1] - 10.0), ACCURACY);
  ck_assert_double_lt(custom_fabs(third_mtrx.matrix[0][2] - 10.0), ACCURACY);
  ck_assert_double_lt(custom_fabs(third_mtrx.matrix[1][0] - 10.0), ACCURACY);
  ck_assert_double_lt(custom_fabs(third_mtrx.matrix[1][1] - 10.0), ACCURACY);
  ck_assert_double_lt(custom_fabs(third_mtrx.matrix[1][2] - 10.0), ACCURACY);
  ck_assert_double_lt(custom_fabs(third_mtrx.matrix[2][0] - 10.0), ACCURACY);
  ck_assert_double_lt(custom_fabs(third_mtrx.matrix[2][1] - 10.0), ACCURACY);
  ck_assert_double_lt(custom_fabs(third_mtrx.matrix[2][2] - 10.0), ACCURACY);
  ck_assert_int_eq(res, OK);
  custom_remove_matrix(&first_mtrx);
  custom_remove_matrix(&second_mtrx);
  custom_remove_matrix(&third_mtrx);
} END_TEST

START_TEST(sum_2) {
  matrix_t first_mtrx = INIT_MTRX;
  matrix_t second_mtrx = INIT_MTRX;
  matrix_t third_mtrx = INIT_MTRX;
  custom_create_matrix(3, 3, &first_mtrx);
  custom_create_matrix(3, 3, &second_mtrx);
  fill_matrix(&first_mtrx, mtrx_size(&first_mtrx), 1.9999999, 2.8888888, 3.7777777,
                                                   4.6666666, 5.5555555, 6.4444444,
                                                   7.3333333, 8.2222222, 9.1111111);
  fill_matrix(&second_mtrx, mtrx_size(&second_mtrx), 9.11111111, 8.1111111, 7.1111111,
                                                     6.11111110, 5.1111111, 4.1111111,
                                                     3.11111110, 2.1111111, 1.0000001);
  int res = custom_sum_matrix(&first_mtrx, &second_mtrx, &third_mtrx);
  ck_assert_double_lt(custom_fabs(third_mtrx.matrix[0][0] - 11.11111101), ACCURACY);
  ck_assert_double_lt(custom_fabs(third_mtrx.matrix[0][1] - 10.99999990), ACCURACY);
  ck_assert_double_lt(custom_fabs(third_mtrx.matrix[0][2] - 10.88888880), ACCURACY);
  ck_assert_double_lt(custom_fabs(third_mtrx.matrix[1][0] - 10.77777770), ACCURACY);
  ck_assert_double_lt(custom_fabs(third_mtrx.matrix[1][1] - 10.66666660), ACCURACY);
  ck_assert_double_lt(custom_fabs(third_mtrx.matrix[1][2] - 10.55555550), ACCURACY);
  ck_assert_double_lt(custom_fabs(third_mtrx.matrix[2][0] - 10.44444440), ACCURACY);
  ck_assert_double_lt(custom_fabs(third_mtrx.matrix[2][1] - 10.33333330), ACCURACY);
  ck_assert_double_lt(custom_fabs(third_mtrx.matrix[2][2] - 10.11111120), ACCURACY);
  ck_assert_int_eq(res, OK);
  custom_remove_matrix(&first_mtrx);
  custom_remove_matrix(&second_mtrx);
  custom_remove_matrix(&third_mtrx);
} END_TEST

START_TEST(sum_3) {
  matrix_t first_mtrx = INIT_MTRX;
  matrix_t second_mtrx = INIT_MTRX;
  matrix_t third_mtrx = INIT_MTRX;
  custom_create_matrix(3, 3, &first_mtrx);
  custom_create_matrix(3, 3, &second_mtrx);
  fill_matrix(&first_mtrx, mtrx_size(&first_mtrx), 1.0, 2.0, 3.0,
                                                   4.0, 5.0, 6.0,
                                                   7.0, 8.0, 9.0);
  fill_matrix(&second_mtrx, mtrx_size(&second_mtrx), 9.0, 8.0, 7.0,
                                                     6.0, 5.0, 4.0,
                                                     3.0, 2.0, 1.0);
  int res = custom_sum_matrix(&first_mtrx, &second_mtrx, &third_mtrx);
  ck_assert_double_lt(custom_fabs(third_mtrx.matrix[0][0] - 10.0), ACCURACY);
  ck_assert_double_lt(custom_fabs(third_mtrx.matrix[0][1] - 10.0), ACCURACY);
  ck_assert_double_lt(custom_fabs(third_mtrx.matrix[0][2] - 10.0), ACCURACY);
  ck_assert_double_lt(custom_fabs(third_mtrx.matrix[1][0] - 10.0), ACCURACY);
  ck_assert_double_lt(custom_fabs(third_mtrx.matrix[1][1] - 10.0), ACCURACY);
  ck_assert_double_lt(custom_fabs(third_mtrx.matrix[1][2] - 10.0), ACCURACY);
  ck_assert_double_lt(custom_fabs(third_mtrx.matrix[2][0] - 10.0), ACCURACY);
  ck_assert_double_lt(custom_fabs(third_mtrx.matrix[2][1] - 10.0), ACCURACY);
  ck_assert_double_lt(custom_fabs(third_mtrx.matrix[2][2] - 10.0), ACCURACY);
  ck_assert_int_eq(res, OK);
  custom_remove_matrix(&first_mtrx);
  custom_remove_matrix(&second_mtrx);
  custom_remove_matrix(&third_mtrx);
} END_TEST

START_TEST(sum_4) {
  matrix_t first_mtrx = INIT_MTRX,
           second_mtrx = INIT_MTRX,
           third_mtrx = INIT_MTRX;
  custom_create_matrix(0, 0, &first_mtrx);
  custom_create_matrix(0, 0, &second_mtrx);
  int res = custom_sum_matrix(&first_mtrx, &second_mtrx, &third_mtrx);
  ck_assert_int_eq(res, INVALID_MATRIX);
  custom_remove_matrix(&first_mtrx);
  custom_remove_matrix(&second_mtrx);
  custom_remove_matrix(&third_mtrx);
} END_TEST

START_TEST(sum_5) {
  matrix_t first_mtrx = INIT_MTRX,
           second_mtrx = INIT_MTRX,
           third_mtrx = INIT_MTRX;
  custom_create_matrix(3, 2, &first_mtrx);
  custom_create_matrix(2, 3, &second_mtrx);
  fill_matrix(&first_mtrx, mtrx_size(&first_mtrx), 1.0, 4.0,
                                                   2.0, 5.0,
                                                   3.0, 6.0);
  fill_matrix(&second_mtrx, mtrx_size(&second_mtrx), 1.0,-1.0, 1.0,
                                                     2.0, 3.0, 4.0);
  int res = custom_sum_matrix(&first_mtrx, &second_mtrx, &third_mtrx);
  ck_assert_int_eq(res, CALCULATION_ERROR);
  custom_remove_matrix(&first_mtrx);
  custom_remove_matrix(&second_mtrx);
  custom_remove_matrix(&third_mtrx);
} END_TEST

Suite *test_sum() {
  Suite *s = suite_create(BLUE"-=MTRX_SUM=-"RESET);
  TCase *tc = tcase_create(RED"mtrx_sum_tc"RESET);

  tcase_add_test(tc, sum_1);
  tcase_add_test(tc, sum_2);
  tcase_add_test(tc, sum_3);
  tcase_add_test(tc, sum_4);
  tcase_add_test(tc, sum_5);

  suite_add_tcase(s, tc);
  return s;
}