#include "test.h"

START_TEST(negate_0) {
  custom_decimal value_one = {{2, 0, 0, 0}}, result = {0};
  custom_negate(value_one, &result);
  ck_assert_int_ne(get_sign(&value_one), get_sign(&result));
}

END_TEST

START_TEST(negate_1) {
  custom_decimal value_one = {{2, 0, 0, ~(UINT_MAX / 2)}}, result = {0};
  custom_negate(value_one, &result);
  ck_assert_int_ne(get_sign(&value_one), get_sign(&result));
}

END_TEST

START_TEST(negate_2) {
  custom_decimal value_one = {{0, 0, 0, ~(UINT_MAX / 2)}}, result = {0};
  custom_negate(value_one, &result);
  ck_assert_int_ne(get_sign(&value_one), get_sign(&result));
}

END_TEST

START_TEST(negate_3) {
  custom_decimal value_one = {0}, result = {0};
  custom_negate(value_one, &result);
  ck_assert_int_ne(get_sign(&value_one), get_sign(&result));
}

END_TEST

START_TEST(negate_4) {
  custom_decimal value_one = {{655678, 0, 0, 0}}, result = {0};
  custom_negate(value_one, &result);
  ck_assert_int_ne(get_sign(&result), get_sign(&value_one));
}

END_TEST

START_TEST(negate_5) {
  custom_decimal value_one = {{777, 346678, 455678, 0}}, result = {0};
  custom_negate(value_one, &result);
  ck_assert_int_ne(get_sign(&result), get_sign(&value_one));
}

END_TEST

START_TEST(negate_6) {
  custom_decimal value_one = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}}, result = {0};
  custom_negate(value_one, &result);
  ck_assert_int_ne(get_sign(&result), get_sign(&value_one));
}

END_TEST

START_TEST(negate_7) {
  custom_decimal value_one = {{67295, 7777666, 1234567, 0}}, result = {0};
  custom_set_bit(&value_one, 127, 1);
  custom_set_scale(&value_one, 10);
  custom_negate(value_one, &result);
  ck_assert_int_ne(get_sign(&result), get_sign(&value_one));
}

END_TEST

START_TEST(negate_8) {
  custom_decimal value_one = {{0, 346678, 0, 0}}, result = {0};
  custom_negate(value_one, &result);
  ck_assert_int_ne(get_sign(&result), get_sign(&value_one));
}

END_TEST

START_TEST(negate_9) {
  custom_decimal value_one = {{UINT_MAX, 346678, UINT_MAX, 0}}, result = {0};
  custom_negate(value_one, &result);
  ck_assert_int_ne(get_sign(&result), get_sign(&value_one));
}

END_TEST

START_TEST(negate_10) {
  custom_decimal value_one = {{UINT_MAX, UINT_MAX, 0, 0}}, result = {0};
  custom_set_bit(&value_one, 127, 1);
  custom_set_scale(&value_one, 5);
  custom_negate(value_one, &result);
  ck_assert_int_ne(get_sign(&result), get_sign(&value_one));
}

END_TEST

Suite *test_negate(void) {
  Suite *s = suite_create("\033[45m-=CUS_NEGATE=-\033[0m");
  TCase *tc = tcase_create("negate_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, negate_0);
  tcase_add_test(tc, negate_1);
  tcase_add_test(tc, negate_2);
  tcase_add_test(tc, negate_3);
  tcase_add_test(tc, negate_4);
  tcase_add_test(tc, negate_5);
  tcase_add_test(tc, negate_6);
  tcase_add_test(tc, negate_7);
  tcase_add_test(tc, negate_8);
  tcase_add_test(tc, negate_9);
  tcase_add_test(tc, negate_10);

  suite_add_tcase(s, tc);
  return s;
}
