#include "test.h"

START_TEST(not_equal_1) {
  float num1 = 1.375342323523;
  float num2 = 1.39;
  custom_decimal dec1, dec2;
  custom_from_float_to_decimal(num1, &dec1);
  custom_from_float_to_decimal(num2, &dec2);
  int res = custom_is_not_equal(dec1, dec2);
  ck_assert_int_eq(res, TRUE);
}
END_TEST

START_TEST(not_equal_2) {
  float num1 = 1.39;
  float num2 = 1.39;
  custom_decimal dec1, dec2;
  custom_from_float_to_decimal(num1, &dec1);
  custom_from_float_to_decimal(num2, &dec2);
  int res = custom_is_not_equal(dec1, dec2);
  ck_assert_int_eq(res, FALSE);
}
END_TEST

START_TEST(not_equal_3) {
  float num1 = 1.39;
  float num2 = -1.39;
  custom_decimal dec1, dec2;
  custom_from_float_to_decimal(num1, &dec1);
  custom_from_float_to_decimal(num2, &dec2);
  int res = custom_is_not_equal(dec1, dec2);
  ck_assert_int_eq(res, TRUE);
}
END_TEST

START_TEST(not_equal_4) {
  int num1 = 0;
  int num2 = 0;
  custom_decimal dec1, dec2;
  custom_from_int_to_decimal(num1, &dec1);
  custom_from_int_to_decimal(num2, &dec2);
  int res = custom_is_not_equal(dec1, dec2);
  ck_assert_int_eq(res, FALSE);
}
END_TEST

START_TEST(not_equal_5) {
  int num1 = 3;
  int num2 = 9;
  custom_decimal dec1, dec2;
  custom_from_int_to_decimal(num1, &dec1);
  custom_from_int_to_decimal(num2, &dec2);
  int res = custom_is_not_equal(dec1, dec2);
  ck_assert_int_eq(res, TRUE);
}
END_TEST

START_TEST(not_equal_6) {
  int num1 = -3;
  int num2 = -3;
  custom_decimal dec1, dec2;
  custom_from_int_to_decimal(num1, &dec1);
  custom_from_int_to_decimal(num2, &dec2);
  int res = custom_is_not_equal(dec1, dec2);
  ck_assert_int_eq(res, FALSE);
}
END_TEST

START_TEST(custom_not_equal_7) {
  custom_decimal dec1 = {
      {12345, 0, 0, 0b00000000000001000000000000000000}};  //  1.2345
  custom_decimal dec2 = {{12, 0, 0, 0b10000000000000010000000000000000}};  // -1.2;
  ck_assert_int_eq(custom_is_not_equal(dec1, dec2), 1);

  custom_decimal dec3 = {
      {120000, 0, 0, 0b00000000000001000000000000000000}};  //  12.0000
  custom_decimal dec4 = {{12, 0, 0, 0b00000000000000000000000000000000}};  //
  ck_assert_int_eq(custom_is_not_equal(dec3, dec4), 0);

  custom_decimal dec5 = {{0, 0, 0, 0b00000000000000000000000000000000}};   //  0
  custom_decimal dec6 = {{00, 0, 0, 0b00000000000000010000000000000000}};  //
  ck_assert_int_eq(custom_is_not_equal(dec5, dec6), 0);

  custom_decimal dec7 = {{0, 0, 0, 0b00000000000000000000000000000000}};  //   0
  custom_decimal dec8 = {{0, 0, 0, 0b10000000000000000000000000000000}};  //  -0;
  ck_assert_int_eq(custom_is_not_equal(dec7, dec8), 1);
}
END_TEST

Suite *suite_is_not_equal(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("custom_is_not_equal");
  tc = tcase_create("case_is_not_equal");

  tcase_add_test(tc, not_equal_1);
  tcase_add_test(tc, not_equal_2);
  tcase_add_test(tc, not_equal_3);
  tcase_add_test(tc, not_equal_4);
  tcase_add_test(tc, not_equal_5);
  tcase_add_test(tc, not_equal_6);
  tcase_add_test(tc, custom_not_equal_7);

  suite_add_tcase(s, tc);
  return s;
}
