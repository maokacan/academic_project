#include "test_me.h"

START_TEST(test_insert_1) {
  char str_1[30] = "hello, world!";
  char str_3[] = "hELLO, WORLD!";
  char str_4[] = "hello, hELLO, WORLD!world!";
  custom_size_t num = 7;
  char *str_2 = custom_insert(str_1, str_3, num);
  ck_assert_pstr_eq(str_4, str_2);
  if (str_2) free(str_2);
}
END_TEST

START_TEST(test_insert_2) {
  char str_1[30] = "";
  char str_3[] = "";
  char *str_4 = NULL;
  custom_size_t num = 7;
  char *str_2 = custom_insert(str_1, str_3, num);
  ck_assert_pstr_eq(str_4, str_2);
  if (str_2) free(str_2);
}
END_TEST

START_TEST(test_insert_3) {
  char *str_1 = NULL;
  char str_3[] = "";
  char *str_4 = NULL;
  custom_size_t num = 0;
  char *str_2 = custom_insert(str_1, str_3, num);
  ck_assert_pstr_eq(str_4, str_2);
  if (str_2) free(str_2);
}
END_TEST

START_TEST(test_insert_4) {
  char str_1[30] = "abcdefghij";
  char str_3[] = "\'I WAS HERE\'";
  char str_4[] = "abc\'I WAS HERE\'defghij";
  custom_size_t num = 3;
  char *str_2 = custom_insert(str_1, str_3, num);
  ck_assert_pstr_eq(str_4, str_2);
  if (str_2) free(str_2);
}
END_TEST

START_TEST(test_insert_5) {
  char str_1[30] = "abc";
  char str_3[] = "333";
  char *str_4 = NULL;
  custom_size_t num = 10;
  char *str_2 = custom_insert(str_1, str_3, num);
  ck_assert_pstr_eq(str_4, str_2);
  if (str_2) free(str_2);
}
END_TEST

START_TEST(test_insert_6) {
  char str_1[30] = "hello, world!";
  char str_3[] = "hELLO, WORLD!";
  char *str_4 = NULL;
  custom_size_t num = -1;
  char *str_2 = custom_insert(str_1, str_3, num);
  ck_assert_pstr_eq(str_4, str_2);
  if (str_2) free(str_2);
}
END_TEST

START_TEST(test_insert_7) {
  char *str_1 = NULL;
  char *str_3 = NULL;
  char *str_4 = NULL;
  custom_size_t num = 0;
  char *str_2 = custom_insert(str_1, str_3, num);
  ck_assert_pstr_eq(str_4, str_2);
  if (str_2) free(str_2);
}
END_TEST

START_TEST(test_insert_8) {
  char str_1[30] = "";
  char str_3[] = "";
  char str_4[] = "";
  custom_size_t num = 0;
  char *str_2 = custom_insert(str_1, str_3, num);
  ck_assert_pstr_eq(str_4, str_2);
  if (str_2) free(str_2);
}
END_TEST

START_TEST(test_insert_9) {
  char str_1[] = "wtf";
  char *str_3 = NULL;
  char *str_4 = NULL;
  custom_size_t num = 0;
  char *str_2 = custom_insert(str_1, str_3, num);
  ck_assert_pstr_eq(str_4, str_2);
  if (str_2) free(str_2);
}
END_TEST

START_TEST(test_insert_10) {
  char str_1[] = "";
  char *str_3 = NULL;
  char *str_4 = NULL;
  custom_size_t num = 0;
  char *str_2 = custom_insert(str_1, str_3, num);
  ck_assert_pstr_eq(str_2, str_4);
  if (str_2) free(str_2);
}
END_TEST

Suite *test_insert(void) {
  Suite *s = suite_create("\033[45m-=S21_INSERT=-\033[0m");
  TCase *tc = tcase_create("insert_tc");

  tcase_add_test(tc, test_insert_1);
  tcase_add_test(tc, test_insert_2);
  tcase_add_test(tc, test_insert_3);
  tcase_add_test(tc, test_insert_4);
  tcase_add_test(tc, test_insert_5);
  tcase_add_test(tc, test_insert_6);
  tcase_add_test(tc, test_insert_7);
  tcase_add_test(tc, test_insert_8);
  tcase_add_test(tc, test_insert_9);
  tcase_add_test(tc, test_insert_10);

  suite_add_tcase(s, tc);
  return s;
}