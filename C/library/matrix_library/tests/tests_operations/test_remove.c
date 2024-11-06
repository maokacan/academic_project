#include "../test.h"

START_TEST(remove_1) {
  matrix_t first_mtrx = INIT_MTRX;
  custom_create_matrix(2, 2, &first_mtrx);
  ck_assert_int_eq(first_mtrx.rows, 2);
  ck_assert_int_eq(first_mtrx.columns, 2);
  ck_assert_ptr_nonnull(first_mtrx.matrix);
  custom_remove_matrix(&first_mtrx);
  ck_assert_int_eq(first_mtrx.rows, 0);
  ck_assert_int_eq(first_mtrx.columns, 0);
  ck_assert_ptr_null(first_mtrx.matrix);
}
END_TEST

START_TEST(remove_2) {
  matrix_t first_mtrx = INIT_MTRX;
  ck_assert_int_eq(first_mtrx.rows, 0);
  ck_assert_int_eq(first_mtrx.columns, 0);
  ck_assert_ptr_null(first_mtrx.matrix);
  custom_remove_matrix(&first_mtrx);
  ck_assert_int_eq(first_mtrx.rows, 0);
  ck_assert_int_eq(first_mtrx.columns, 0);
  ck_assert_ptr_null(first_mtrx.matrix);
}
END_TEST

START_TEST(remove_3) {
  matrix_t first_mtrx = INIT_MTRX;
  custom_create_matrix(3, 3, &first_mtrx);
  fill_matrix(&first_mtrx, 9, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);
  ck_assert_int_eq(first_mtrx.rows, 3);
  ck_assert_int_eq(first_mtrx.columns, 3);
  ck_assert_ptr_nonnull(first_mtrx.matrix);
  custom_remove_matrix(&first_mtrx);
  ck_assert_int_eq(first_mtrx.rows, 0);
  ck_assert_int_eq(first_mtrx.columns, 0);
  ck_assert_ptr_null(first_mtrx.matrix);
}
END_TEST

Suite *test_remove() {
  Suite *s = suite_create(BLUE "-=MTRX_REMOVE=-" RESET);
  TCase *tc = tcase_create(RED "mtrx_remove_tc" RESET);

  tcase_add_test(tc, remove_1);
  tcase_add_test(tc, remove_2);
  tcase_add_test(tc, remove_3);

  suite_add_tcase(s, tc);
  return s;
}