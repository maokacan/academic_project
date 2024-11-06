#include "test.h"

START_TEST(custom_from_float_to_decimal_1) {
  custom_decimal val;
  float fl1 = 3;
  float fl2 = 127.1234;
  float fl1_res = 0;
  float fl2_res = 0;

  custom_from_float_to_decimal(fl1, &val);
  // print_2_32_int(fl2);
  // printf("\n");
  // print_2_32_uint(fl2);
  // printf("\n");
  // print_2(&val);
  // print_2_32_uint(val->bits);
  custom_from_decimal_to_float(val, &fl1_res);
  ck_assert_double_eq_tol(fl1, fl1_res, 1e-28);
  // ck_assert_int_eq(val.bits[0], 3);
  // ck_assert_int_eq(val.bits[1], 0);
  // ck_assert_int_eq(val.bits[2], 0);
  // ck_assert_int_eq(val.bits[3], 131072);

  custom_from_float_to_decimal(fl2, &val);
  custom_from_decimal_to_float(val, &fl2_res);
  ck_assert_double_eq_tol(fl2, fl2_res, 1e-28);
  // ck_assert_int_eq(val.bits[0], 1271234);
  // ck_assert_int_eq(val.bits[1], 0);
  // ck_assert_int_eq(val.bits[2], 0);
  // ck_assert_int_eq(val.bits[3], 262144);
}
END_TEST

START_TEST(custom_from_float_to_decimal_2) {
  custom_decimal val;
  float fl1 = -128.023;
  float fl2 = 12345.37643764;
  float fl1_res = 0;
  float fl2_res = 0;

  custom_from_float_to_decimal(fl1, &val);
  custom_from_decimal_to_float(val, &fl1_res);
  ck_assert_double_eq_tol(fl1, fl1_res, 1e-28);

  custom_from_float_to_decimal(fl2, &val);
  custom_from_decimal_to_float(val, &fl2_res);
  ck_assert_double_eq_tol(fl2, fl2_res, 1e-28);

  // custom_from_float_to_decimal(-128.023, &val);
  // ck_assert_int_eq(val.bits[0], 12802299);
  // ck_assert_int_eq(val.bits[1], 0);
  // ck_assert_int_eq(val.bits[2], 0);
  // ck_assert_int_eq(val.bits[3], -2147155968);
}
END_TEST
START_TEST(custom_from_float_to_decimal_3) {
  custom_decimal val;
  float num = -2.1474836E+09;
  custom_from_float_to_decimal(num, &val);
  ck_assert_int_eq(val.bits[0], 2147483648);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 2147483648);
}
END_TEST

START_TEST(custom_from_float_to_decimal_4) {
  custom_decimal val;
  float fl1 = 22.14836E+03;
  float fl2 = -2.1474836E+09;
  float fl1_res = 0;
  float fl2_res = 0;

  custom_from_float_to_decimal(fl1, &val);
  custom_from_decimal_to_float(val, &fl1_res);
  ck_assert_double_eq_tol(fl1, fl1_res, 1e-28);

  custom_from_float_to_decimal(fl2, &val);
  custom_from_decimal_to_float(val, &fl2_res);
  ck_assert_double_eq_tol(fl2, fl2_res, 1e-28);

  // custom_from_float_to_decimal(22.14836E+03, &val);
  // ck_assert_int_eq(val.bits[0], 2214836);
  // ck_assert_int_eq(val.bits[1], 0);
  // ck_assert_int_eq(val.bits[2], 0);
  // ck_assert_int_eq(val.bits[3], 131072);
}
END_TEST

START_TEST(custom_from_float_to_decimal_5) {
  custom_decimal val;
  custom_from_float_to_decimal(1.02E+09, &val);
  ck_assert_int_eq(val.bits[0], 1020000000);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);
}
END_TEST

START_TEST(custom_from_float_to_decimal_6) {
  custom_decimal val;
  float fl1 = -333.2222;
  float fl2 = -2.1474836E+20;
  float fl1_res = 0;
  float fl2_res = 0;

  custom_from_float_to_decimal(fl1, &val);
  custom_from_decimal_to_float(val, &fl1_res);
  ck_assert_double_eq_tol(fl1, fl1_res, 1e-28);

  custom_from_float_to_decimal(fl2, &val);
  custom_from_decimal_to_float(val, &fl2_res);
  ck_assert_double_eq_tol(fl2, fl2_res, 1e-28);

  // custom_from_float_to_decimal(-333.2222, &val);
  // ck_assert_int_eq(val.bits[0], 3332222);
  // ck_assert_int_eq(val.bits[1], 0);
  // ck_assert_int_eq(val.bits[2], 0);
  // ck_assert_int_eq(val.bits[3], -2147221504);
}
END_TEST

START_TEST(custom_from_float_to_decimal_7) {
  custom_decimal val;
  float a = 1.0 / 0.0;
  custom_from_float_to_decimal(a, &val);
  ck_assert_int_eq(val.bits[0], 0);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);
}
END_TEST

START_TEST(custom_from_float_to_decimal_8) {
  custom_decimal val;
  float a = -1.0 / 0.0;
  custom_from_float_to_decimal(a, &val);
  ck_assert_int_eq(val.bits[0], 0);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);
}
END_TEST

START_TEST(custom_from_float_to_decimal_10) {
  custom_decimal val;
  float a = 1e-30;
  custom_from_float_to_decimal(a, &val);
  ck_assert_int_eq(val.bits[0], 0);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);
}
END_TEST

START_TEST(custom_from_float_to_decimal_11) {
  custom_decimal dec;
  float tmp = 0;
  float tmp1 = 0.03;
  custom_from_float_to_decimal(tmp1, &dec);
  custom_from_decimal_to_float(dec, &tmp);
  ck_assert_float_eq_tol(tmp, tmp1, 1e-06);
}
END_TEST

START_TEST(custom_from_float_to_decimal_12) {
  custom_decimal dec;
  custom_from_float_to_decimal(-128.023, &dec);
  float tmp = 0;
  custom_from_decimal_to_float(dec, &tmp);
  ck_assert_float_eq_tol(tmp, -128.023, 1e-06);
}
END_TEST

START_TEST(custom_from_float_to_decimal_13) {
  custom_decimal dec;
  custom_from_float_to_decimal(-2.1474836E+09, &dec);
  float tmp = 0;
  custom_from_decimal_to_float(dec, &tmp);
  ck_assert_float_eq_tol(tmp, -2.1474836E+09, 1e-06);
}
END_TEST

START_TEST(custom_from_float_to_decimal_14) {
  custom_decimal dec;
  custom_from_float_to_decimal(22.14836E+03, &dec);
  float tmp = 0;
  custom_from_decimal_to_float(dec, &tmp);
  ck_assert_float_eq_tol(tmp, 22.14836E+03, 1e-06);
}
END_TEST

START_TEST(custom_from_float_to_decimal_15) {
  custom_decimal dec;
  custom_from_float_to_decimal(1.02E+08, &dec);
  float tmp = 0;
  custom_from_decimal_to_float(dec, &tmp);
  ck_assert_float_eq_tol(tmp, 1.02E+08, 1e-06);
}
END_TEST

START_TEST(custom_from_float_to_decimal_16) {
  custom_decimal dec;
  custom_from_float_to_decimal(-333.2222, &dec);
  float tmp = 0;
  custom_from_decimal_to_float(dec, &tmp);
  ck_assert_float_eq_tol(tmp, -333.2222, 1e-06);
}
END_TEST

START_TEST(custom_from_float_to_decimal_17) {
  custom_decimal dec;
  float a = 1.0 / 0.0;
  int ret = custom_from_float_to_decimal(a, &dec);
  ck_assert_int_eq(ret, 1);
}
END_TEST

START_TEST(custom_from_float_to_decimal_18) {
  custom_decimal dec;
  float a = -1.0 / 0.0;
  custom_from_float_to_decimal(a, &dec);
  ck_assert_int_eq(dec.bits[0], 0);
  ck_assert_int_eq(dec.bits[1], 0);
  ck_assert_int_eq(dec.bits[2], 0);
  ck_assert_int_eq(dec.bits[3], 0);
}
END_TEST

Suite *suite_from_float_to_decimal(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("custom_from_float_to_decimal");
  tc = tcase_create("case_from_float_to_decimal");

  tcase_add_test(tc, custom_from_float_to_decimal_1);
  tcase_add_test(tc, custom_from_float_to_decimal_2);
  tcase_add_test(tc, custom_from_float_to_decimal_3);
  tcase_add_test(tc, custom_from_float_to_decimal_4);
  tcase_add_test(tc, custom_from_float_to_decimal_5);
  tcase_add_test(tc, custom_from_float_to_decimal_6);
  tcase_add_test(tc, custom_from_float_to_decimal_7);
  tcase_add_test(tc, custom_from_float_to_decimal_8);
  tcase_add_test(tc, custom_from_float_to_decimal_10);
  tcase_add_test(tc, custom_from_float_to_decimal_11);
  tcase_add_test(tc, custom_from_float_to_decimal_12);
  tcase_add_test(tc, custom_from_float_to_decimal_13);
  tcase_add_test(tc, custom_from_float_to_decimal_14);
  tcase_add_test(tc, custom_from_float_to_decimal_15);
  tcase_add_test(tc, custom_from_float_to_decimal_16);
  tcase_add_test(tc, custom_from_float_to_decimal_17);
  tcase_add_test(tc, custom_from_float_to_decimal_18);

  suite_add_tcase(s, tc);
  return s;
}