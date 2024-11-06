#include "test.h"

START_TEST(truncate_0) {
  custom_decimal value_one = {{7, 7, 7, 0}}, result = {0};
  float result_f = 0, value_two_f = (float)129127208515966861312.0;
  ck_assert_int_eq(0, custom_truncate(value_one, &result));
  custom_from_decimal_to_float(result, &result_f);
  ck_assert_float_eq(value_two_f, result_f);
}
END_TEST

START_TEST(truncate_1) {
  custom_decimal value_one = {{2, 0, 0, ~(UINT_MAX / 2)}}, result = {0};
  float result_f = 0, value_two_f = (float)-2.0;
  ck_assert_int_eq(0, custom_truncate(value_one, &result));
  custom_from_decimal_to_float(result, &result_f);
  ck_assert_float_eq(value_two_f, result_f);
}
END_TEST

START_TEST(truncate_2) {
  custom_decimal value_one = {{2, 0, 0, ~(UINT_MAX / 2)}}, result = {0};
  float result_f = 0, value_two_f = (float)-2.0;
  ck_assert_int_eq(0, custom_truncate(value_one, &result));
  custom_from_decimal_to_float(result, &result_f);
  ck_assert_float_eq(value_two_f, result_f);
}
END_TEST

START_TEST(truncate_3) {
  custom_decimal value_one = {{2, 0, 0, ~(UINT_MAX / 2)}}, result = {0};
  float result_f = 0, value_two_f = (float)-0.0;
  custom_set_scale(&value_one, 5);
  ck_assert_int_eq(0, custom_truncate(value_one, &result));
  custom_from_decimal_to_float(result, &result_f);
  ck_assert_float_eq(value_two_f, result_f);
}
END_TEST

START_TEST(truncate_4) {
  custom_decimal value_one = {{128, 0, 0, 0}};
  custom_decimal result = {0};
  custom_set_scale(&value_one, 1);
  ck_assert_int_eq(0, custom_truncate(value_one, &result));
  float result_f = 0;
  custom_from_decimal_to_float(result, &result_f);
  float value_two_f = 12;
  ck_assert_float_eq(value_two_f, result_f);
}
END_TEST

START_TEST(truncate_5) {
  custom_decimal value_one = {{123456, 0, 0, 0}}, value_two = {{123, 0, 0, 0}},
              result;
  float result_f, value_two_f;
  custom_set_scale(&value_one, 3);
  ck_assert_int_eq(0, custom_truncate(value_one, &result));
  custom_from_decimal_to_float(result, &result_f);
  custom_from_decimal_to_float(value_two, &value_two_f);
  ck_assert_float_eq(result_f, value_two_f);
}
END_TEST

START_TEST(truncate_6) {
  custom_decimal value_one = {{34445667, 0, 0, 0}}, value_two = {{3, 0, 0, 0}},
              result;
  float result_f, value_two_f;
  custom_set_scale(&value_one, 7);
  ck_assert_int_eq(0, custom_truncate(value_one, &result));
  custom_from_decimal_to_float(result, &result_f);
  custom_from_decimal_to_float(value_two, &value_two_f);
  ck_assert_float_eq(result_f, value_two_f);
}
END_TEST

START_TEST(truncate_7) {
  custom_decimal value_one = {{UINT_MAX, 0, 0, 0}},
              value_two = {{4294967, 0, 0, 0}}, result;
  float result_f, value_two_f;
  custom_set_scale(&value_one, 3);
  ck_assert_int_eq(0, custom_truncate(value_one, &result));
  custom_from_decimal_to_float(result, &result_f);
  custom_from_decimal_to_float(value_two, &value_two_f);
  ck_assert_float_eq(result_f, value_two_f);
}
END_TEST

START_TEST(truncate_8) {
  custom_decimal value_one = {{UINT_MAX, 1, 0, 0}}, value_two = {{8, 0, 0, 0}},
              result;
  float result_f, value_two_f;
  custom_set_scale(&value_one, 9);
  ck_assert_int_eq(0, custom_truncate(value_one, &result));
  custom_from_decimal_to_float(result, &result_f);
  custom_from_decimal_to_float(value_two, &value_two_f);
  ck_assert_float_eq(result_f, value_two_f);
}
END_TEST

START_TEST(truncate_9) {
  custom_decimal value_one = {{UINT_MAX, 0, 0, 0}}, value_two = {{0, 0, 0, 0}},
              result;
  float result_f, value_two_f;
  custom_set_scale(&value_one, 10);
  ck_assert_int_eq(0, custom_truncate(value_one, &result));
  custom_from_decimal_to_float(result, &result_f);
  custom_from_decimal_to_float(value_two, &value_two_f);
  ck_assert_float_eq(result_f, value_two_f);
  custom_from_float_to_decimal(result_f, &result);
}
END_TEST

START_TEST(truncate_10) {
  custom_decimal value_one = {{UINT_MAX, 0, 0, 0}}, value_two = {{4, 0, 0, 0}},
              result;
  float result_f, value_two_f;
  custom_set_scale(&value_one, 9);
  ck_assert_int_eq(0, custom_truncate(value_one, &result));
  custom_from_decimal_to_float(result, &result_f);
  custom_from_decimal_to_float(value_two, &value_two_f);
  ck_assert_float_eq(result_f, value_two_f);
}
END_TEST

Suite *test_truncate(void) {
  Suite *s = suite_create("\033[45m-=CUS_TRUNCATE=-\033[0m");
  TCase *tc = tcase_create("truncate_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, truncate_0);
  tcase_add_test(tc, truncate_1);
  tcase_add_test(tc, truncate_2);
  tcase_add_test(tc, truncate_3);
  tcase_add_test(tc, truncate_4);
  tcase_add_test(tc, truncate_5);
  tcase_add_test(tc, truncate_6);
  tcase_add_test(tc, truncate_7);
  tcase_add_test(tc, truncate_8);
  tcase_add_test(tc, truncate_9);
  tcase_add_test(tc, truncate_10);

  suite_add_tcase(s, tc);
  return s;
}