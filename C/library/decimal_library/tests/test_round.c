#include "test.h"

START_TEST(round_0) {
  custom_decimal value_one = {{7, 7, 7, 0}}, result = {0};
  float result_f = 0, value_two_f = (float)129127208515966861312.0;
  custom_round(value_one, &result);
  custom_from_decimal_to_float(result, &result_f);
  ck_assert_float_eq(value_two_f, result_f);
}

END_TEST

START_TEST(round_1) {
  custom_decimal value_one = {{3, 3, 3, ~(UINT_MAX / 2)}}, result = {0};
  ck_assert_int_eq(0, custom_round(value_one, &result));
}

END_TEST

START_TEST(round_2) {
  custom_decimal value_one = {{3, 3, 3, 0}}, result = {0};
  custom_set_scale(&value_one, 5);
  ck_assert_int_eq(0, custom_round(value_one, &result));
}

END_TEST

START_TEST(round_3) {
  custom_decimal value_one = {{7, 7, 7, ~(UINT_MAX / 2)}}, result = {0};
  custom_set_scale(&value_one, 5);
  ck_assert_int_eq(0, custom_round(value_one, &result));
}

END_TEST

START_TEST(round_4) {
  custom_decimal value_one = {{25, 0, 0, ~(UINT_MAX / 2)}}, result = {0};
  custom_set_scale(&value_one, 1);
  ck_assert_int_eq(0, custom_round(value_one, &result));
}

END_TEST

START_TEST(round_5) {
  custom_decimal value_one = {{26, 0, 0, 0}}, result = {0};
  custom_set_scale(&value_one, 1);
  ck_assert_int_eq(0, custom_round(value_one, &result));
}

END_TEST

START_TEST(round_6) {
  custom_decimal value_one = {{115, 0, 0, 0}}, result = {0};
  custom_set_scale(&value_one, 1);
  ck_assert_int_eq(0, custom_round(value_one, &result));
}

END_TEST

START_TEST(round_7) {
  custom_decimal value_one = {{118, 0, 0, 0}}, result = {0};
  custom_set_scale(&value_one, 1);
  ck_assert_int_eq(0, custom_round(value_one, &result));
}

END_TEST

START_TEST(round_8) {
  custom_decimal value_one = {{125, 0, 0, 0}}, result = {0};
  custom_set_scale(&value_one, 1);
  ck_assert_int_eq(0, custom_round(value_one, &result));
}

END_TEST

START_TEST(round_9) {
  custom_decimal value_one = {{345, 0, 0, 0}}, result = {0};
  custom_set_scale(&value_one, 1);
  ck_assert_int_eq(0, custom_round(value_one, &result));
}

END_TEST

START_TEST(round_10) {
  custom_decimal value_one = {{128, 0, 0, 0}}, result = {0};
  float result_f = 0, value_two_f = 13;
  custom_set_scale(&value_one, 1);
  custom_round(value_one, &result);
  custom_from_decimal_to_float(result, &result_f);
  ck_assert_float_eq(value_two_f, result_f);
}

END_TEST

Suite *test_round(void) {
  Suite *s = suite_create("\033[45m-=CUS_ROUND=-\033[0m");
  TCase *tc = tcase_create("round_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, round_0);
  tcase_add_test(tc, round_1);
  tcase_add_test(tc, round_2);
  tcase_add_test(tc, round_3);
  tcase_add_test(tc, round_4);
  tcase_add_test(tc, round_5);
  tcase_add_test(tc, round_6);
  tcase_add_test(tc, round_7);
  tcase_add_test(tc, round_8);
  tcase_add_test(tc, round_9);
  tcase_add_test(tc, round_10);

  suite_add_tcase(s, tc);
  return s;
}