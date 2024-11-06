#include "test.h"

START_TEST(from_decimal_to_int_0) {
  custom_decimal value_one = {{456789, 0, 0, 0}};
  int result = 456789, value_one_i = 0;
  custom_from_decimal_to_int(value_one, &value_one_i);
  ck_assert_int_eq(value_one_i, result);
}

END_TEST

START_TEST(from_decimal_to_int_1) {
  custom_decimal value_one = {{123456789, 0, 0, 0}};
  int result = 123456789, value_one_i = 0;
  custom_from_decimal_to_int(value_one, &value_one_i);
  ck_assert_int_eq(value_one_i, result);
}

END_TEST

START_TEST(from_decimal_to_int_2) {
  custom_decimal value_one = {{19121993, 0, 0, 0}};
  int result = -19121993, value_one_i = 0;
  custom_set_bit(&value_one, 127, 1);
  custom_from_decimal_to_int(value_one, &value_one_i);
  ck_assert_int_eq(value_one_i, result);
}

END_TEST

START_TEST(from_decimal_to_int_3) {
  custom_decimal value_one = {{7777777, 0, 0, 0}};
  int result = 7777777, value_one_i = 0;
  custom_from_decimal_to_int(value_one, &value_one_i);
  ck_assert_int_eq(value_one_i, result);
}

END_TEST

START_TEST(from_decimal_to_int_4) {
  custom_decimal value_one = {{UINT_MAX, 0, 0, 0}};
  int result = -UINT_MAX, value_one_i = 0;
  custom_set_bit(&value_one, 127, 1);
  custom_from_decimal_to_int(value_one, &value_one_i);
  ck_assert_int_eq(value_one_i, result);
}

END_TEST

START_TEST(from_decimal_to_int_5) {
  custom_decimal value_one = {{UINT_MAX, 0, 0, 0}};
  int result = UINT_MAX, value_one_i = 0;
  custom_from_decimal_to_int(value_one, &value_one_i);
  ck_assert_int_eq(value_one_i, result);
}

END_TEST

Suite *test_dec_to_int(void) {
  Suite *s = suite_create("\033[45m-=CUS_DEC_TO_INT=-\033[0m");
  TCase *tc = tcase_create("convert_dec_to_int_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, from_decimal_to_int_0);
  tcase_add_test(tc, from_decimal_to_int_1);
  tcase_add_test(tc, from_decimal_to_int_2);
  tcase_add_test(tc, from_decimal_to_int_3);
  tcase_add_test(tc, from_decimal_to_int_4);
  tcase_add_test(tc, from_decimal_to_int_5);

  suite_add_tcase(s, tc);
  return s;
}
