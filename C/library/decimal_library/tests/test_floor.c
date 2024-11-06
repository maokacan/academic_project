#include "test.h"

int custom_get_float_scale(float src) {
  int t = *(int *)&src;
  return ((t >> 23) & 255) - 127;
}

START_TEST(floor_0) {
  custom_decimal value_one = {{4, 0, 0, 0}}, result = {0};
  ck_assert_int_eq(0, custom_floor(value_one, &result));
}

END_TEST

START_TEST(floor_1) {
  custom_decimal value_one = {{2, 0, 0, ~(UINT_MAX / 2)}}, result = {0};
  float result_f = 0;
  custom_floor(value_one, &result);
  custom_from_decimal_to_float(result, &result_f);
  ck_assert_float_eq(-2, result_f);
}

END_TEST

START_TEST(floor_2) {
  custom_decimal value_one = {{2, 0, 0, ~(UINT_MAX / 2)}}, result = {0};
  float result_f = 0;
  custom_set_scale(&value_one, 5);
  custom_floor(value_one, &result);
  custom_from_decimal_to_float(result, &result_f);
  ck_assert_float_eq(-1, result_f);
}

END_TEST

START_TEST(floor_3) {
  custom_decimal value_one = {{2, 0, 0, 0}}, result = {0};
  float result_f = 0;
  custom_set_scale(&value_one, 5);
  custom_floor(value_one, &result);
  custom_from_decimal_to_float(result, &result_f);
  ck_assert_float_eq(0, result_f);
}

END_TEST

START_TEST(floor_4) {
  custom_decimal value_one = {{123456, 0, 0, 0}}, value_two = {{124, 0, 0, 0}},
              result = {0};
  float result_f, value_two_f;
  custom_set_bit(&value_one, 127, 1);
  custom_set_bit(&value_two, 127, 1);
  custom_set_scale(&value_one, 3);
  custom_floor(value_one, &result);
  custom_from_decimal_to_float(result, &result_f);
  custom_from_decimal_to_float(value_two, &value_two_f);
  ck_assert_float_eq(result_f, value_two_f);
}

END_TEST

START_TEST(floor_5) {
  custom_decimal value_one = {{87654, 0, 0, 0}}, value_two = {{9, 0, 0, 0}},
              result = {0};
  float result_f, value_two_f;
  custom_set_bit(&value_one, 127, 1);
  custom_set_bit(&value_two, 127, 1);
  custom_set_scale(&value_one, 4);
  custom_floor(value_one, &result);
  custom_from_decimal_to_float(result, &result_f);
  custom_from_decimal_to_float(value_two, &value_two_f);
  custom_get_float_scale(value_two_f);
  ck_assert_float_eq(result_f, value_two_f);
}

END_TEST

START_TEST(floor_6) {
  custom_decimal value_one = {{11, 0, 0, 0}}, value_two = {{2, 0, 0, 0}},
              result = {0};
  float result_f, value_two_f;
  custom_set_bit(&value_one, 127, 1);
  custom_set_bit(&value_two, 127, 1);
  custom_set_scale(&value_one, 1);
  custom_floor(value_one, &result);
  custom_from_decimal_to_float(result, &result_f);
  custom_from_decimal_to_float(value_two, &value_two_f);
  ck_assert_float_eq(result_f, value_two_f);
}

END_TEST

START_TEST(floor_7) {
  custom_decimal value_one = {{34, 0, 0, 0}}, value_two = {{1, 0, 0, 0}},
              result = {0};
  float result_f, value_two_f;
  custom_set_bit(&value_one, 127, 1);
  custom_set_bit(&value_two, 127, 1);
  custom_set_scale(&value_one, 3);
  custom_floor(value_one, &result);
  custom_from_decimal_to_float(result, &result_f);
  custom_from_decimal_to_float(value_two, &value_two_f);
  ck_assert_float_eq(result_f, value_two_f);
}

END_TEST

START_TEST(floor_8) {
  custom_decimal value_one = {{7777777, 0, 0, 0}}, value_two = {{78, 0, 0, 0}},
              result = {0};
  float result_f, value_two_f;
  custom_set_bit(&value_one, 127, 1);
  custom_set_bit(&value_two, 127, 1);
  custom_set_scale(&value_one, 5);
  custom_floor(value_one, &result);
  custom_from_decimal_to_float(result, &result_f);
  custom_from_decimal_to_float(value_two, &value_two_f);
  ck_assert_float_eq(result_f, value_two_f);
}

END_TEST

START_TEST(floor_9) {
  custom_decimal value_one = {{123456789, 0, 0, 0}}, value_two = {{1, 0, 0, 0}},
              result = {0};
  float result_f, value_two_f;
  custom_set_bit(&value_one, 127, 1);
  custom_set_bit(&value_two, 127, 1);
  custom_set_scale(&value_one, 9);
  custom_floor(value_one, &result);
  custom_from_decimal_to_float(result, &result_f);
  custom_from_decimal_to_float(value_two, &value_two_f);
  ck_assert_float_eq(result_f, value_two_f);
}

END_TEST

START_TEST(floor_10) {
  custom_decimal value_one = {{UINT_MAX, 0, 0, 0}}, value_two = {{43, 0, 0, 0}},
              result = {0};
  float result_f, value_two_f;
  custom_set_bit(&value_one, 127, 1);
  custom_set_bit(&value_two, 127, 1);
  custom_set_scale(&value_one, 8);
  custom_floor(value_one, &result);
  custom_from_decimal_to_float(result, &result_f);
  custom_from_decimal_to_float(value_two, &value_two_f);
  ck_assert_float_eq(result_f, value_two_f);
}

END_TEST

Suite *test_floor(void) {
  Suite *s = suite_create("\033[45m-=CUS_FLOOR=-\033[0m");
  TCase *tc = tcase_create("floor_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, floor_0);
  tcase_add_test(tc, floor_1);
  tcase_add_test(tc, floor_2);
  tcase_add_test(tc, floor_3);
  tcase_add_test(tc, floor_4);
  tcase_add_test(tc, floor_5);
  tcase_add_test(tc, floor_6);
  tcase_add_test(tc, floor_7);
  tcase_add_test(tc, floor_8);
  tcase_add_test(tc, floor_9);
  tcase_add_test(tc, floor_10);

  suite_add_tcase(s, tc);
  return s;
}