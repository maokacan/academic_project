#include "test.h"

START_TEST(mul_0) {
  custom_decimal value_one = {{123, 456, 789, ~(UINT_MAX / 2)}},
              value_two = {{987, 654, 321, 0}}, result = {{0}};
  custom_set_scale(&value_one, 3);
  ck_assert_int_eq(0, custom_mul(value_one, value_two, &result));
}

END_TEST

START_TEST(mul_1) {
  custom_decimal value_one = {{123, 456, 789, 0}},
              value_two = {{987, 654, 321, ~(UINT_MAX / 2)}}, result = {{0}};
  custom_set_bit(&value_two, 127, 1);
  ck_assert_int_eq(2, custom_mul(value_one, value_two, &result));
}

END_TEST

START_TEST(mul_2) {
  custom_decimal value_one = {{123, 456, 789, ~(UINT_MAX / 2)}},
              value_two = {{987, 654, 321, ~(UINT_MAX / 2)}}, result = {{0}};
  ck_assert_int_eq(1, custom_mul(value_one, value_two, &result));
}

END_TEST

START_TEST(mul_3) {
  custom_decimal value_one = {{123, 456, 789, 0}},
              value_two = {{987, 654, 321, 0}}, result = {{0}};
  custom_set_scale(&value_one, 8);
  custom_set_scale(&value_two, 8);
  ck_assert_int_eq(0, custom_mul(value_one, value_two, &result));
}

END_TEST

START_TEST(mul_4) {
  custom_decimal value_one = {{123, 456, UINT_MAX, 0}},
              value_two = {{987, UINT_MAX, 321, 0}}, result = {{0}};
  custom_set_bit(&value_one, 127, 1);
  custom_set_bit(&value_two, 127, 1);
  ck_assert_int_eq(1, custom_mul(value_one, value_two, &result));
}

END_TEST

START_TEST(mul_5) {
  custom_decimal value_one = {{123, 456, 789, 0}},
              value_two = {{987, 654, 321, 0}}, result = {{0}};
  custom_set_bit(&value_one, 127, 1);
  custom_set_bit(&value_two, 127, 1);
  custom_set_scale(&value_one, 12);
  custom_set_scale(&value_two, 14);
  ck_assert_int_eq(0, custom_mul(value_one, value_two, &result));
}

END_TEST

START_TEST(mul_6) {
  custom_decimal value_one = {{123, 456, 0, ~(UINT_MAX / 2)}},
              value_two = {{987, 654, 321, 0}}, result = {{0}};
  custom_set_bit(&value_one, 23, 1);
  ck_assert_int_eq(2, custom_mul(value_one, value_two, &result));
}

END_TEST

START_TEST(mul_7) {
  custom_decimal value_one = {{123, 456, 0, ~(UINT_MAX / 2)}},
              value_two = {{987, 654, 0, 0}}, result = {{0}};
  custom_set_bit(&value_one, 33, 1);
  custom_set_bit(&value_two, 22, 1);
  custom_set_scale(&value_one, 2);
  custom_set_scale(&value_two, 2);
  ck_assert_int_eq(0, custom_mul(value_one, value_two, &result));
}

END_TEST

START_TEST(mul_8) {
  custom_decimal value_one = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}},
              value_two = {{777, 0, 0, ~(UINT_MAX / 2)}}, result = {{0}};
  ck_assert_int_eq(1, custom_mul(value_one, value_two, &result));
}

END_TEST

START_TEST(mul_9) {
  custom_decimal value_one = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}},
              value_two = {{2, 0, 0, 0}}, result = {{0}};
  ck_assert_int_eq(2, custom_mul(value_one, value_two, &result));
}

END_TEST

START_TEST(mul_10) {
  custom_decimal value_one = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}},
              value_two = {{22, 0, 0, 0}}, result = {{0}};
  ck_assert_int_eq(1, custom_mul(value_one, value_two, &result));
}

END_TEST

START_TEST(mul_11) {
  custom_decimal value_one = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}},
              value_two = {{0, 0, 0, 0}}, result = {{0}};
  custom_set_bit(&value_two, 35, 1);
  ck_assert_int_eq(2, custom_mul(value_one, value_two, &result));
}

END_TEST

START_TEST(mul_12) {
  custom_decimal value_one = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}},
              value_two = {{2, 0, 0, 0}}, result = {{0}};
  custom_set_scale(&value_one, 1);
  ck_assert_int_eq(0, custom_mul(value_one, value_two, &result));
}

END_TEST

START_TEST(mul_13) {
  custom_decimal value_one = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}},
              value_two = {{200, 4444, 0, 0}}, result = {{0}};
  custom_set_bit(&value_two, 19, 1);
  custom_set_scale(&value_one, 1);
  custom_set_scale(&value_two, 2);
  ck_assert_int_eq(0, custom_mul(value_one, value_two, &result));
}

END_TEST

START_TEST(mul_14) {
  custom_decimal value_two = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}},
              value_one = {{20, 0, 0, 0}}, result = {{0}};
  custom_set_scale(&value_one, 1);
  custom_set_scale(&value_two, 2);
  ck_assert_int_eq(0, custom_mul(value_one, value_two, &result));
}

END_TEST

START_TEST(mul_15) {
  custom_decimal value_one = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}},
              value_two = {{0, 4444, UINT_MAX, 0}}, result = {{0}};
  custom_set_bit(&value_two, 19, 1);
  custom_set_scale(&value_one, 3);
  custom_set_scale(&value_two, 4);
  custom_set_bit(&value_one, 127, 1);
  custom_set_bit(&value_two, 127, 1);
  ck_assert_int_eq(1, custom_mul(value_one, value_two, &result));
}

END_TEST

Suite *test_mul(void) {
  Suite *s = suite_create("\033[45m-=CUS_MUL=-\033[0m");
  TCase *tc = tcase_create("mull_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, mul_0);
  tcase_add_test(tc, mul_1);
  tcase_add_test(tc, mul_2);
  tcase_add_test(tc, mul_3);
  tcase_add_test(tc, mul_4);
  tcase_add_test(tc, mul_5);
  tcase_add_test(tc, mul_6);
  tcase_add_test(tc, mul_7);
  tcase_add_test(tc, mul_8);
  tcase_add_test(tc, mul_9);
  tcase_add_test(tc, mul_10);
  tcase_add_test(tc, mul_11);
  tcase_add_test(tc, mul_12);
  tcase_add_test(tc, mul_13);
  tcase_add_test(tc, mul_14);
  tcase_add_test(tc, mul_15);

  suite_add_tcase(s, tc);
  return s;
}