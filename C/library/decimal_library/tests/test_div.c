#include "test.h"

START_TEST(div_0) {
  custom_decimal value_one = {{123, 456, 0, ~(UINT_MAX / 2)}},
              value_two = {{987, 654, 0, 0}}, result;
  ck_assert_int_eq(0, custom_div(value_one, value_two, &result));
}

END_TEST

START_TEST(div_1) {
  custom_decimal value_one = {{123, 456, 789, 0}}, value_two = {{987, 0, 0, 0}},
              result;
  ck_assert_int_eq(0, custom_div(value_one, value_two, &result));
}

END_TEST

START_TEST(div_2) {
  custom_decimal value_one = {{12, 0, 0, 0}}, value_two = {{3, 0, 0, 0}}, result;
  custom_set_bit(&value_two, 127, 1);
  ck_assert_int_eq(0, custom_div(value_one, value_two, &result));
}

END_TEST

START_TEST(div_3) {
  custom_decimal value_one = {{12, 0, UINT_MAX, 0}},
              value_two = {{3, 345, 345, 0}}, result;
  custom_set_bit(&value_one, 127, 1);
  custom_set_bit(&value_two, 127, 1);
  custom_set_scale(&value_two, 15);
  ck_assert_int_eq(0, custom_div(value_one, value_two, &result));
}

END_TEST

START_TEST(div_4) {
  custom_decimal value_one = {{123, 456, 789, 0}},
              value_two = {{987, 654, 321, 0}}, result;
  ck_assert_int_eq(0, custom_div(value_one, value_two, &result));
}

END_TEST

START_TEST(div_5) {
  custom_decimal value_one = {{44444, 345, 0, 0}}, value_two = {{987, 0, 0, 0}},
              result;
  custom_set_bit(&value_two, 56, 1);
  ck_assert_int_eq(0, custom_div(value_one, value_two, &result));
}

END_TEST

START_TEST(div_6) {
  custom_decimal value_one = {{123, 345, 34, 0}}, value_two = {{987, 0, 5673, 0}},
              result;
  custom_set_bit(&value_two, 56, 1);
  custom_set_scale(&value_one, 7);
  custom_set_scale(&value_two, 9);
  ck_assert_int_eq(0, custom_div(value_one, value_two, &result));
}

END_TEST

START_TEST(div_7) {
  custom_decimal value_one = {{UINT_MAX, UINT_MAX, 0, 0}},
              value_two = {{UINT_MAX, UINT_MAX, 0, 0}}, result;
  custom_set_bit(&value_one, 127, 1);
  custom_set_bit(&value_two, 127, 1);
  ck_assert_int_eq(0, custom_div(value_one, value_two, &result));
}

END_TEST

START_TEST(div_8) {
  custom_decimal value_one = {{100, 0, 0, 0}}, value_two = {{25, 0, 0, 0}}, result;
  custom_set_bit(&value_one, 77, 1);
  ck_assert_int_eq(0, custom_div(value_one, value_two, &result));
}

END_TEST

START_TEST(div_9) {
  custom_decimal value_one = {{12, 0, UINT_MAX, 0}},
              value_two = {{3, 0, UINT_MAX, 0}}, result;
  custom_set_bit(&value_two, 127, 1);
  custom_set_scale(&value_one, 13);
  custom_set_scale(&value_two, 13);
  ck_assert_int_eq(0, custom_div(value_one, value_two, &result));
}

END_TEST

START_TEST(div_10) {
  custom_decimal value_one = {0}, value_two = {0}, result;
  custom_set_bit(&value_one, 88, 1);
  custom_set_bit(&value_two, 88, 1);
  custom_set_scale(&value_one, 4);
  custom_set_scale(&value_two, 4);
  ck_assert_int_eq(0, custom_div(value_one, value_two, &result));
}

END_TEST

START_TEST(div_11) {
  custom_decimal value_one = {{0, 0, 36, 0}}, value_two = {{0, 0, 6, 0}}, result;
  custom_set_bit(&value_two, 127, 1);
  custom_set_scale(&value_one, 6);
  custom_set_scale(&value_two, 6);
  ck_assert_int_eq(0, custom_div(value_one, value_two, &result));
}

END_TEST

START_TEST(div_12) {
  custom_decimal value_one = {{50, 0, 0, 0}},
              value_two = {{10, 0, 0, ~(UINT_MAX / 2)}}, result;
  ck_assert_int_eq(0, custom_div(value_one, value_two, &result));
}

END_TEST

START_TEST(div_13) {
  custom_decimal value_one = {{36, 0, 0, ~(UINT_MAX / 2)}},
              value_two = {{2, 0, 0, ~(UINT_MAX / 2)}}, result;
  custom_set_bit(&value_one, 127, 1);
  ck_assert_int_eq(0, custom_div(value_one, value_two, &result));
}

END_TEST

START_TEST(div_14) {
  custom_decimal value_one = {{12, 23, 123, ~(UINT_MAX / 2)}},
              value_two = {{0, 0, 0, 0}}, result;
  ck_assert_int_eq(3, custom_div(value_one, value_two, &result));
}

END_TEST

START_TEST(div_15) {
  custom_decimal value_one = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}},
              value_two = {{0, 0, 0, 0}}, result;
  ck_assert_int_eq(3, custom_div(value_one, value_two, &result));
}

END_TEST

Suite *test_div(void) {
  Suite *s = suite_create("\033[45m-=CUS_DIV=-\033[0m");
  TCase *tc = tcase_create("div_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, div_0);
  tcase_add_test(tc, div_1);
  tcase_add_test(tc, div_2);
  tcase_add_test(tc, div_3);
  tcase_add_test(tc, div_4);
  tcase_add_test(tc, div_5);
  tcase_add_test(tc, div_6);
  tcase_add_test(tc, div_7);
  tcase_add_test(tc, div_8);
  tcase_add_test(tc, div_9);
  tcase_add_test(tc, div_10);
  tcase_add_test(tc, div_11);
  tcase_add_test(tc, div_12);
  tcase_add_test(tc, div_13);
  tcase_add_test(tc, div_14);
  tcase_add_test(tc, div_15);

  suite_add_tcase(s, tc);
  return s;
}