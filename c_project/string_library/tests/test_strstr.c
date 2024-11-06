#include "test_me.h"

START_TEST(strstr_1) {
  char str_1[] = "Hello, world!";
  char str_2[] = "Hello, world!";
  ck_assert_pstr_eq(strstr(str_1, str_2), custom_strstr(str_1, str_2));
}
END_TEST

START_TEST(strstr_2) {
  char str_1[] = "Hello, world!";
  char str_2[] = "Hello, P!";
  ck_assert_pstr_eq(strstr(str_1, str_2), custom_strstr(str_1, str_2));
}
END_TEST

START_TEST(strstr_3) {
  char str_1[] = "Hello, world!";
  char str_2[] = "!";
  ck_assert_pstr_eq(strstr(str_1, str_2), custom_strstr(str_1, str_2));
}
END_TEST

START_TEST(strstr_4) {
  char str_1[] =
      "Hello, world!Hello, world!Hello, world!Hello, world!Hello, world!";
  char str_2[] = "world";
  ck_assert_pstr_eq(strstr(str_1, str_2), custom_strstr(str_1, str_2));
}
END_TEST

START_TEST(strstr_5) {
  char str_1[] = "";
  char str_2[] = "";
  ck_assert_pstr_eq(strstr(str_1, str_2), custom_strstr(str_1, str_2));
}
END_TEST

START_TEST(strstr_6) {
  char str_1[] = "Hello, world!";
  char str_2[] = "";
  ck_assert_pstr_eq(strstr(str_1, str_2), custom_strstr(str_1, str_2));
}
END_TEST

START_TEST(strstr_7) {
  char str_1[] = "";
  char str_2[] = "Hello, P!";
  ck_assert_pstr_eq(strstr(str_1, str_2), custom_strstr(str_1, str_2));
}
END_TEST

START_TEST(strstr_8) {
  char str_1[] = "69917020";
  char str_2[] = "0";
  ck_assert_pstr_eq(strstr(str_1, str_2), custom_strstr(str_1, str_2));
}
END_TEST

START_TEST(strstr_9) {
  char str_1[] = "69917020";
  char str_2[] = "\0";
  ck_assert_pstr_eq(strstr(str_1, str_2), custom_strstr(str_1, str_2));
}
END_TEST

START_TEST(strstr_10) {
  char str_1[] = "69917020";
  char str_2[] = "32859160 8v3489-74 tvc4y8719c n4[nqymu uv 4vm9cw";
  ck_assert_pstr_eq(strstr(str_1, str_2), custom_strstr(str_1, str_2));
}
END_TEST

START_TEST(strstr_11) {
  char str_1[] = "1   345 345 345 345 345";
  char str_2[] = "345";
  ck_assert_pstr_eq(strstr(str_1, str_2), custom_strstr(str_1, str_2));
}
END_TEST

START_TEST(strstr_12) {
  char str_1[] = "sususususpicioussusususpicious";
  char str_2[] = "susp";
  ck_assert_pstr_eq(strstr(str_1, str_2), custom_strstr(str_1, str_2));
}
END_TEST

START_TEST(strstr_13) {
  char str_1[] = "sus";
  char str_2[] = "suspi";
  ck_assert_pstr_eq(strstr(str_1, str_2), custom_strstr(str_1, str_2));
}
END_TEST

START_TEST(strstr_14) {
  const char *A = "rir";
  const char *B = "r";
  ck_assert_ptr_eq(custom_strstr(A, B), strstr(A, B));
}
END_TEST

Suite *test_strstr(void) {
  Suite *s = suite_create("\033[45m-=S21_STRSTR=-\033[0m");
  TCase *tc = tcase_create("strstr_tc");

  tcase_add_test(tc, strstr_1);
  tcase_add_test(tc, strstr_2);
  tcase_add_test(tc, strstr_3);
  tcase_add_test(tc, strstr_4);
  tcase_add_test(tc, strstr_5);
  tcase_add_test(tc, strstr_6);
  tcase_add_test(tc, strstr_7);
  tcase_add_test(tc, strstr_8);
  tcase_add_test(tc, strstr_9);
  tcase_add_test(tc, strstr_10);
  tcase_add_test(tc, strstr_11);
  tcase_add_test(tc, strstr_12);
  tcase_add_test(tc, strstr_13);
  tcase_add_test(tc, strstr_14);

  suite_add_tcase(s, tc);
  return s;
}