#include "../test.h"

START_TEST(equal_1) {
  matrix_t first_mtrx = INIT_MTRX;
  matrix_t second_mtrx = INIT_MTRX;
  custom_create_matrix(3, 3, &first_mtrx);
  custom_create_matrix(3, 3, &second_mtrx);
  fill_matrix(&first_mtrx, mtrx_size(&first_mtrx), 1.0, 2.0, 3.0,
                                                   4.0, 5.0, 6.0,
                                                   7.0, 8.0, 9.0);
  fill_matrix(&second_mtrx, mtrx_size(&second_mtrx), 1.0, 2.0, 3.0,
                                                     4.0, 5.0, 6.0,
                                                     7.0, 8.0, 9.0);
  ck_assert_int_eq(custom_eq_matrix(&first_mtrx, &second_mtrx), SUCCESS);
  custom_remove_matrix(&first_mtrx);
  custom_remove_matrix(&second_mtrx);
}
END_TEST

START_TEST(equal_2) {
  matrix_t first_mtrx = INIT_MTRX;
  matrix_t second_mtrx = INIT_MTRX;
  custom_create_matrix(3, 3, &first_mtrx);
  custom_create_matrix(3, 3, &second_mtrx);
  fill_matrix(&first_mtrx, mtrx_size(&first_mtrx), 9.0, 8.0, 7.0,
                                                   6.0, 5.0, 4.0,
                                                   3.0, 2.0, 1.0);
  fill_matrix(&second_mtrx, mtrx_size(&second_mtrx), 1.0, 2.0, 3.0,
                                                     4.0, 5.0, 6.0,
                                                     7.0, 8.0, 9.0);
  ck_assert_int_eq(custom_eq_matrix(&first_mtrx, &second_mtrx), FAILURE);
  custom_remove_matrix(&first_mtrx);
  custom_remove_matrix(&second_mtrx);
}
END_TEST

START_TEST(equal_3) {
  matrix_t first_mtrx = INIT_MTRX;
  matrix_t second_mtrx = INIT_MTRX;
  custom_create_matrix(3, 3, &first_mtrx);
  custom_create_matrix(2, 2, &second_mtrx);
  fill_matrix(&first_mtrx, mtrx_size(&first_mtrx), 1.0, 2.0, 3.0,
                                                   4.0, 5.0, 6.0,
                                                   7.0, 8.0, 9.0);
  fill_matrix(&second_mtrx, mtrx_size(&second_mtrx), 1.0, 2.0,
                                                     3.0, 4.0);
  ck_assert_int_eq(custom_eq_matrix(&first_mtrx, &second_mtrx), FAILURE);
  custom_remove_matrix(&first_mtrx);
  custom_remove_matrix(&second_mtrx);
}
END_TEST

Suite *test_equal() {
  Suite *s = suite_create(BLUE "-=MTRX_EQUAL=-" RESET);
  TCase *tc = tcase_create(RED "mtrx_equal_tc" RESET);

  tcase_add_test(tc, equal_1);
  tcase_add_test(tc, equal_2);
  tcase_add_test(tc, equal_3);

  suite_add_tcase(s, tc);
  return s;
}