#include "test.h"
START_TEST(from_decimal_to_float_0) {
  custom_decimal value_one = {{456123, 0, 0, 0}};
  float result = 0.456123, value_one_f;
  custom_set_scale(&value_one, 6);
  custom_from_decimal_to_float(value_one, &value_one_f);
  ck_assert_float_eq(result, value_one_f);
}

END_TEST

START_TEST(from_decimal_to_float_1) {
  custom_decimal value_one = {{77777, 0, 0, 0}};
  float result = -777.77, value_one_f;
  custom_set_bit(&value_one, 127, 1);
  custom_set_scale(&value_one, 2);
  custom_from_decimal_to_float(value_one, &value_one_f);
  ck_assert_float_eq(result, value_one_f);
}

END_TEST

START_TEST(from_decimal_to_float_2) {
  custom_decimal value_one = {{123456789, 0, 0, 0}};
  float result = -1234.56789, value_one_f;
  custom_set_bit(&value_one, 127, 1);
  custom_set_scale(&value_one, 5);
  custom_from_decimal_to_float(value_one, &value_one_f);
  ck_assert_float_eq(result, value_one_f);
}

END_TEST

START_TEST(from_decimal_to_float_3) {
  custom_decimal value_one = {{123456789, 1, 0, 0}};
  float result = 4.418424084, value_one_f;
  custom_set_scale(&value_one, 9);
  custom_from_decimal_to_float(value_one, &value_one_f);
  ck_assert_float_eq(result, value_one_f);
}

END_TEST

START_TEST(from_decimal_to_float_4) {
  custom_decimal value_one = {{UINT_MAX, 0, 0, 0}};
  float result = 42.94967295, value_one_f;
  custom_set_scale(&value_one, 8);
  custom_from_decimal_to_float(value_one, &value_one_f);
  ck_assert_float_eq(result, value_one_f);
}

END_TEST

START_TEST(from_decimal_to_float_5) {
  custom_decimal value_one = {{UINT_MAX, 1, 0, 0}};
  float result = 85.89934590, value_one_f;
  custom_set_scale(&value_one, 8);
  custom_from_decimal_to_float(value_one, &value_one_f);
  ck_assert_float_eq(result, value_one_f);
}

END_TEST

Suite *test_dec_to_float(void) {
  Suite *s = suite_create("\033[45m-=CUS_DEC_TO_FLOAT=-\033[0m");
  TCase *tc = tcase_create("convert_dec_to_float_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, from_decimal_to_float_0);
  tcase_add_test(tc, from_decimal_to_float_1);
  tcase_add_test(tc, from_decimal_to_float_2);
  tcase_add_test(tc, from_decimal_to_float_3);
  tcase_add_test(tc, from_decimal_to_float_4);
  tcase_add_test(tc, from_decimal_to_float_5);

  suite_add_tcase(s, tc);
  return s;
}
