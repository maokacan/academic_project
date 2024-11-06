#include "../test.h"

START_TEST(calc_complements_1) {
  matrix_t first_mtrx = INIT_MTRX, result = INIT_MTRX;
  custom_create_matrix(4, 4, &first_mtrx);
  fill_matrix(&first_mtrx, mtrx_size(&first_mtrx), 1.0, 3.0, 5.0, 8.0,
                                                   9.0, 9.0, 1.0, 2.0,
                                                   2.0, 2.0, 2.0, 2.0,
                                                   3.0, 6.0, 7.0, 2.0);
  int res = custom_calc_complements(&first_mtrx, &result);
  ck_assert_double_lt(custom_fabs(result.matrix[0][0] -  -78.0), ACCURACY);
  ck_assert_double_lt(custom_fabs(result.matrix[0][1] -   72.0), ACCURACY);
  ck_assert_double_lt(custom_fabs(result.matrix[0][2] -  -42.0), ACCURACY);
  ck_assert_double_lt(custom_fabs(result.matrix[0][3] -   48.0), ACCURACY);
  ck_assert_double_lt(custom_fabs(result.matrix[1][0] -  -26.0), ACCURACY);
  ck_assert_double_lt(custom_fabs(result.matrix[1][1] -   64.0), ACCURACY);
  ck_assert_double_lt(custom_fabs(result.matrix[1][2] -  -46.0), ACCURACY);
  ck_assert_double_lt(custom_fabs(result.matrix[1][3] -    8.0), ACCURACY);
  ck_assert_double_lt(custom_fabs(result.matrix[2][0] -  390.0), ACCURACY);
  ck_assert_double_lt(custom_fabs(result.matrix[2][1] - -408.0), ACCURACY);
  ck_assert_double_lt(custom_fabs(result.matrix[2][2] -  186.0), ACCURACY);
  ck_assert_double_lt(custom_fabs(result.matrix[2][3] -  -12.0), ACCURACY);
  ck_assert_double_lt(custom_fabs(result.matrix[3][0] -  -52.0), ACCURACY);
  ck_assert_double_lt(custom_fabs(result.matrix[3][1] -   56.0), ACCURACY);
  ck_assert_double_lt(custom_fabs(result.matrix[3][2] -     28), ACCURACY);
  ck_assert_double_lt(custom_fabs(result.matrix[3][3] -  -32.0), ACCURACY);
  ck_assert_int_eq(res, OK);
  custom_remove_matrix(&first_mtrx);
  custom_remove_matrix(&result);
} END_TEST

START_TEST(calc_complements_2) {
  matrix_t first_mtrx = INIT_MTRX, result = INIT_MTRX, expected_mtrx = INIT_MTRX;
  custom_create_matrix(5, 5, &first_mtrx);
  custom_create_matrix(5, 5, &expected_mtrx);
  fill_matrix(&first_mtrx, mtrx_size(&first_mtrx), 1.0, 3.0, 5.0, 8.0, 3.0,
                                                   9.0, 9.0, 1.0, 2.0, 5.0,
                                                   2.0, 2.0, 2.0, 2.0, 4.0,
                                                   3.0, 6.0, 7.0, 2.0, 1.0,
                                                   8.0, 9.0, 2.0, 7.0, 6.0);
  fill_matrix(&expected_mtrx, mtrx_size(&expected_mtrx),   882.0,  -800.0,  298.0,  172.0, -276.0,
                                                          1174.0, -1000.0,  366.0,  124.0, -332.0,
                                                          -318.0,   200.0,  -42.0, -108.0,  264.0,
                                                          -380.0,   360.0,  -60.0,  -80.0,   80.0,
                                                         -1144.0,  1040.0, -416.0, -104.0,  312.0);

  int res = custom_calc_complements(&first_mtrx, &result);

  for (int i = 0; i < result.rows; ++i) {
    for (int j = 0; j < result.columns; ++j) {
      ck_assert_double_lt(custom_fabs(result.matrix[i][j] - expected_mtrx.matrix[i][j]), ACCURACY);
    }
  }
  ck_assert_int_eq(res, OK);
//  ck_assert_double_lt(custom_fabs(result.matrix[0][0] -   882.0), ACCURACY);
//  ck_assert_double_lt(custom_fabs(result.matrix[0][1] -  -800.0), ACCURACY);
//  ck_assert_double_lt(custom_fabs(result.matrix[0][2] -   298.0), ACCURACY);
//  ck_assert_double_lt(custom_fabs(result.matrix[0][3] -   172.0), ACCURACY);
//  ck_assert_double_lt(custom_fabs(result.matrix[0][4] -  -276.0), ACCURACY);
//  ck_assert_double_lt(custom_fabs(result.matrix[1][0] -  1174.0), ACCURACY);
//  ck_assert_double_lt(custom_fabs(result.matrix[1][1] - -1000.0), ACCURACY);
//  ck_assert_double_lt(custom_fabs(result.matrix[1][2] -   366.0), ACCURACY);
//  ck_assert_double_lt(custom_fabs(result.matrix[1][3] -   124.0), ACCURACY);
//  ck_assert_double_lt(custom_fabs(result.matrix[1][4] -  -332.0), ACCURACY);
//  ck_assert_double_lt(custom_fabs(result.matrix[2][0] -  -318.0), ACCURACY);
//  ck_assert_double_lt(custom_fabs(result.matrix[2][1] -   200.0), ACCURACY);
//  ck_assert_double_lt(custom_fabs(result.matrix[2][2] -   -42.0), ACCURACY);
//  ck_assert_double_lt(custom_fabs(result.matrix[2][3] -  -108.0), ACCURACY);
//  ck_assert_double_lt(custom_fabs(result.matrix[2][4] -   264.0), ACCURACY);
//  ck_assert_double_lt(custom_fabs(result.matrix[3][0] -  -380.0), ACCURACY);
//  ck_assert_double_lt(custom_fabs(result.matrix[3][1] -   360.0), ACCURACY);
//  ck_assert_double_lt(custom_fabs(result.matrix[3][2] -   -60.0), ACCURACY);
//  ck_assert_double_lt(custom_fabs(result.matrix[3][3] -   -80.0), ACCURACY);
//  ck_assert_double_lt(custom_fabs(result.matrix[3][4] -    80.0), ACCURACY);
//  ck_assert_double_lt(custom_fabs(result.matrix[4][0] - -1144.0), ACCURACY);
//  ck_assert_double_lt(custom_fabs(result.matrix[4][1] -  1040.0), ACCURACY);
//  ck_assert_double_lt(custom_fabs(result.matrix[4][2] -  -416.0), ACCURACY);
//  ck_assert_double_lt(custom_fabs(result.matrix[4][3] -  -104.0), ACCURACY);
//  ck_assert_double_lt(custom_fabs(result.matrix[4][4] -   312.0), ACCURACY);
  custom_remove_matrix(&first_mtrx);
  custom_remove_matrix(&expected_mtrx);
  custom_remove_matrix(&result);
} END_TEST

START_TEST(calc_complements_3) {
  matrix_t first_mtrx = INIT_MTRX, result = INIT_MTRX;
  custom_create_matrix(0, 0, &first_mtrx);
  int res = custom_calc_complements(&first_mtrx, &result);
  ck_assert_int_eq(res, INVALID_MATRIX);
  custom_remove_matrix(&first_mtrx);
  custom_remove_matrix(&result);
} END_TEST

START_TEST(calc_complements_4) {
  matrix_t first_mtrx = INIT_MTRX, result = INIT_MTRX;
  custom_create_matrix(5, 4, &first_mtrx);
  fill_matrix(&first_mtrx, mtrx_size(&first_mtrx), 1.0, 3.0, 5.0, 8.0,
                                                   9.0, 9.0, 1.0, 2.0,
                                                   2.0, 2.0, 2.0, 2.0,
                                                   3.0, 6.0, 7.0, 2.0,
                                                   8.0, 9.0, 2.0, 7.0);
  int res = custom_calc_complements(&first_mtrx, &result);
  ck_assert_int_eq(res, CALCULATION_ERROR);
  custom_remove_matrix(&first_mtrx);
  custom_remove_matrix(&result);
} END_TEST

Suite *test_calc_complements() {
  Suite *s = suite_create(BLUE"-=MTRX_CALC_COMPLEMENTS=-"RESET);
  TCase *tc = tcase_create(RED"mtrx_calc_complements_tc"RESET);

  tcase_add_test(tc, calc_complements_1);
  tcase_add_test(tc, calc_complements_2);
  tcase_add_test(tc, calc_complements_3);
  tcase_add_test(tc, calc_complements_4);

  suite_add_tcase(s, tc);
  return s;
}