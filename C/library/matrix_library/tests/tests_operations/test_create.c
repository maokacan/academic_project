#include "../test.h"

START_TEST(create_1) {
  matrix_t first_mtrx = INIT_MTRX;
  int result = custom_create_matrix(0, 0, &first_mtrx);
  ck_assert_int_eq(result, INVALID_MATRIX);
  ck_assert_int_eq(first_mtrx.rows, 0);
  ck_assert_int_eq(first_mtrx.columns, 0);
  ck_assert_ptr_null(first_mtrx.matrix);
}
END_TEST

START_TEST(create_2) {
  matrix_t first_mtrx = INIT_MTRX;
  int result = custom_create_matrix(10, 0, &first_mtrx);
  ck_assert_int_eq(result, INVALID_MATRIX);
  ck_assert_int_eq(first_mtrx.rows, 0);
  ck_assert_int_eq(first_mtrx.columns, 0);
  ck_assert_ptr_null(first_mtrx.matrix);
  custom_remove_matrix(&first_mtrx);
}
END_TEST

START_TEST(create_3) {
  matrix_t first_mtrx = INIT_MTRX;
  int result = custom_create_matrix(0, 10, &first_mtrx);
  ck_assert_int_eq(result, INVALID_MATRIX);
  ck_assert_int_eq(first_mtrx.rows, 0);
  ck_assert_int_eq(first_mtrx.columns, 0);
  ck_assert_ptr_null(first_mtrx.matrix);
  custom_remove_matrix(&first_mtrx);
}
END_TEST

START_TEST(create_4) {
  matrix_t first_mtrx = INIT_MTRX;
  int result = custom_create_matrix(-1, -4, &first_mtrx);
  ck_assert_int_eq(result, INVALID_MATRIX);
  ck_assert_int_eq(first_mtrx.rows, 0);
  ck_assert_int_eq(first_mtrx.columns, 0);
  ck_assert_ptr_null(first_mtrx.matrix);
}
END_TEST

START_TEST(create_5) {
  matrix_t first_mtrx = INIT_MTRX;
  int result = custom_create_matrix(1, 1, &first_mtrx);
  ck_assert_int_eq(result, OK);
  ck_assert_int_eq(first_mtrx.rows, 1);
  ck_assert_int_eq(first_mtrx.columns, 1);
  ck_assert_ptr_nonnull(first_mtrx.matrix);
  custom_remove_matrix(&first_mtrx);
}
END_TEST

START_TEST(create_6) {
  matrix_t first_mtrx = INIT_MTRX;
  int result = custom_create_matrix(10, 5, &first_mtrx);
  ck_assert_int_eq(result, OK);
  ck_assert_int_eq(first_mtrx.rows, 10);
  ck_assert_int_eq(first_mtrx.columns, 5);
  ck_assert_ptr_nonnull(first_mtrx.matrix);
  custom_remove_matrix(&first_mtrx);
}
END_TEST

START_TEST(create_7) {
  matrix_t first_mtrx = INIT_MTRX;
  int result = custom_create_matrix(5, 10, &first_mtrx);
  ck_assert_int_eq(result, OK);
  ck_assert_int_eq(first_mtrx.rows, 5);
  ck_assert_int_eq(first_mtrx.columns, 10);
  ck_assert_ptr_nonnull(first_mtrx.matrix);
  custom_remove_matrix(&first_mtrx);
}
END_TEST

Suite *test_create() {
  Suite *s = suite_create(BLUE "-=MTRX_CREATE=-" RESET);
  TCase *tc = tcase_create(RED "-=mtrx_create_tc=-" RESET);

  tcase_add_test(tc, create_1);
  tcase_add_test(tc, create_2);
  tcase_add_test(tc, create_3);
  tcase_add_test(tc, create_4);
  tcase_add_test(tc, create_5);
  tcase_add_test(tc, create_6);
  tcase_add_test(tc, create_7);

  suite_add_tcase(s, tc);
  return s;
}
