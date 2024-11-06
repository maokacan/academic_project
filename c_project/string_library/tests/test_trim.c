#include "test_me.h"

START_TEST(test_trim_1) {
  char str_1[30] = "-?hello, world!";
  char str_3[] = "!?-";
  char str_4[] = "hello, world";
  char *str_2 = custom_trim(str_1, str_3);
  ck_assert_pstr_eq(str_4, str_2);
  if (str_2) free(str_2);
}
END_TEST

START_TEST(test_trim_2) {
  char str_1[30] = "";
  char str_3[] = "";
  char *str_4 = "";
  char *str_2 = custom_trim(str_1, str_3);
  ck_assert_pstr_eq(str_4, str_2);
  if (str_2) free(str_2);
}
END_TEST

START_TEST(test_trim_3) {
  char *str_1 = NULL;
  char str_3[] = "";
  char *str_4 = NULL;
  char *str_2 = custom_trim(str_1, str_3);
  ck_assert_pstr_eq(str_4, str_2);
  if (str_2) free(str_2);
}
END_TEST

START_TEST(test_trim_4) {
  char str_1[30] = "!!!abcdefghij!?!";
  char str_3[] = "!?";
  char str_4[] = "abcdefghij";
  char *str_2 = custom_trim(str_1, str_3);
  ck_assert_pstr_eq(str_4, str_2);
  if (str_2) free(str_2);
}
END_TEST

START_TEST(test_trim_5) {
  char str_1[30] = "abc";
  char str_3[] = "333";
  char *str_4 = "abc";
  char *str_2 = custom_trim(str_1, str_3);
  ck_assert_pstr_eq(str_4, str_2);
  if (str_2) free(str_2);
}
END_TEST

START_TEST(test_trim_6) {
  char str_1[30] = "hello, world!";
  char str_3[] = "?!";
  char *str_4 = "hello, world";
  char *str_2 = custom_trim(str_1, str_3);
  ck_assert_pstr_eq(str_4, str_2);
  if (str_2) free(str_2);
}
END_TEST

START_TEST(test_trim_7) {
  char *str_1 = NULL;
  char *str_3 = NULL;
  char *str_4 = NULL;
  char *str_2 = custom_trim(str_1, str_3);
  ck_assert_pstr_eq(str_4, str_2);
  if (str_2) free(str_2);
}
END_TEST

START_TEST(test_trim_8) {
  char str_1[30] = "";
  char str_3[] = "";
  char str_4[] = "";
  char *str_2 = custom_trim(str_1, str_3);
  ck_assert_pstr_eq(str_4, str_2);
  if (str_2) free(str_2);
}
END_TEST

START_TEST(test_trim_9) {
  char str_1[] = " wtf ";
  char *str_3 = NULL;
  char *str_4 = NULL;
  char *str_2 = custom_trim(str_1, str_3);
  ck_assert_pstr_eq(str_4, str_2);
  if (str_2) free(str_2);
}
END_TEST

START_TEST(test_trim_10) {
  char str_1[] = " wtf ";
  char *str_3 = "";
  char *str_4 = " wtf ";
  char *str_2 = custom_trim(str_1, str_3);
  ck_assert_pstr_eq(str_4, str_2);
  if (str_2) free(str_2);
}
END_TEST

Suite *test_trim(void) {
  Suite *s = suite_create("\033[45m-=S21_TRIM=-\033[0m");
  TCase *tc = tcase_create("trim_tc");

  tcase_add_test(tc, test_trim_1);
  tcase_add_test(tc, test_trim_2);
  tcase_add_test(tc, test_trim_3);
  tcase_add_test(tc, test_trim_4);
  tcase_add_test(tc, test_trim_5);
  tcase_add_test(tc, test_trim_6);
  tcase_add_test(tc, test_trim_7);
  tcase_add_test(tc, test_trim_8);
  tcase_add_test(tc, test_trim_9);
  tcase_add_test(tc, test_trim_10);

  suite_add_tcase(s, tc);
  return s;
}