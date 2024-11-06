#include "test_me.h"

START_TEST(test_to_lower_1) {
  char str_1[30] = "hello, world!";
  char str_3[] = "hELLO, WORLD!";
  char *str_2 = custom_to_lower(str_3);
  ck_assert_pstr_eq(str_1, str_2);
  if (str_2) free(str_2);
}
END_TEST

START_TEST(test_to_lower_2) {
  char str_1[30] = "\nh\t\\g123123";
  char str_3[] = "\nH\t\\G123123";
  char *str_2 = custom_to_lower(str_3);
  ck_assert_pstr_eq(str_1, str_2);
  if (str_2) free(str_2);
}
END_TEST

START_TEST(test_to_lower_3) {
  char str_1[30] = "already lower";
  char str_3[] = "already lower";
  char *str_2 = custom_to_lower(str_3);
  ck_assert_pstr_eq(str_1, str_2);
  if (str_2) free(str_2);
}
END_TEST

START_TEST(test_to_lower_4) {
  char str_1[30] = "";
  char str_3[] = "";
  char *str_2 = custom_to_lower(str_3);
  ck_assert_pstr_eq(str_1, str_2);
  if (str_2) free(str_2);
}
END_TEST

START_TEST(test_to_lower_5) {
  char str_1[30] = "abcdefghijklmnopqrstuvwxyz";
  char str_3[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char *str_2 = custom_to_lower(str_3);
  ck_assert_pstr_eq(str_1, str_2);
  if (str_2) free(str_2);
}
END_TEST

START_TEST(test_to_lower_6) {
  char str_1[30] = "_?};!234";
  char str_3[] = "_?};!234";
  char *str_2 = custom_to_lower(str_3);
  ck_assert_pstr_eq(str_1, str_2);
  if (str_2) free(str_2);
}
END_TEST

START_TEST(test_to_lower_7) {
  char *str_1 = NULL;
  char *str_3 = NULL;
  char *str_2 = custom_to_lower(str_3);
  ck_assert_pstr_eq(str_1, str_2);
  if (str_2) free(str_2);
}
END_TEST

Suite *test_to_lower(void) {
  Suite *s = suite_create("\033[45m-=S21_TO_LOWER=-\033[0m");
  TCase *tc = tcase_create("to_lower_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_to_lower_1);
  tcase_add_test(tc, test_to_lower_2);
  tcase_add_test(tc, test_to_lower_3);
  tcase_add_test(tc, test_to_lower_4);
  tcase_add_test(tc, test_to_lower_5);
  tcase_add_test(tc, test_to_lower_6);
  tcase_add_test(tc, test_to_lower_7);

  suite_add_tcase(s, tc);
  return s;
}