#include "test_me.h"

START_TEST(test_to_upper_1) {
  char str_1[30] = "Hello, world!";
  char *str_2 = custom_to_upper(str_1);
  char str_3[] = "HELLO, WORLD!";
  ck_assert_pstr_eq(str_3, str_2);
  if (str_2) free(str_2);
}
END_TEST

START_TEST(test_to_upper_2) {
  char str_1[30] = "\nh\t\\g123123";
  char *str_2 = custom_to_upper(str_1);
  char str_3[] = "\nH\t\\G123123";
  ck_assert_pstr_eq(str_3, str_2);
  if (str_2) free(str_2);
}
END_TEST

START_TEST(test_to_upper_3) {
  char str_1[30] = "ALREADY UPPER";
  char *str_2 = custom_to_upper(str_1);
  char str_3[] = "ALREADY UPPER";
  ck_assert_pstr_eq(str_3, str_2);
  if (str_2) free(str_2);
}
END_TEST

START_TEST(test_to_upper_4) {
  char str_1[30] = "";
  char *str_2 = custom_to_upper(str_1);
  char str_3[] = "";
  ck_assert_pstr_eq(str_3, str_2);
  if (str_2) free(str_2);
}
END_TEST

START_TEST(test_to_upper_5) {
  char str_1[30] = "abcdefghijklmnopqrstuvwxyz";
  char *str_2 = custom_to_upper(str_1);
  char str_3[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  ck_assert_pstr_eq(str_3, str_2);
  if (str_2) free(str_2);
}
END_TEST

START_TEST(test_to_upper_6) {
  char str_1[30] = "_?};!234";
  char *str_2 = custom_to_upper(str_1);
  char str_3[] = "_?};!234";
  ck_assert_pstr_eq(str_3, str_2);
  if (str_2) free(str_2);
}
END_TEST

START_TEST(test_to_upper_7) {
  char *str_1 = NULL;
  char *str_2 = custom_to_upper(str_1);
  char *str_3 = NULL;
  ck_assert_pstr_eq(str_3, str_2);
  if (str_2) free(str_2);
}
END_TEST

Suite *test_to_upper(void) {
  Suite *s = suite_create("\033[45m-=S21_TO_UPPER=-\033[0m");
  TCase *tc = tcase_create("to_upper_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_to_upper_1);
  tcase_add_test(tc, test_to_upper_2);
  tcase_add_test(tc, test_to_upper_3);
  tcase_add_test(tc, test_to_upper_4);
  tcase_add_test(tc, test_to_upper_5);
  tcase_add_test(tc, test_to_upper_6);
  tcase_add_test(tc, test_to_upper_7);

  suite_add_tcase(s, tc);
  return s;
}