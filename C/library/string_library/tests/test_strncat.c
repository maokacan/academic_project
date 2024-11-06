#include "test_me.h"

START_TEST(strncat_1) {
  char str_1[30] = "Hello, world!";
  char str_2[30] = "Hello, world!";
  char str_3[] = "Hello, world!";
  custom_size_t num = 1;
  ck_assert_pstr_eq(strncat(str_1, str_3, num), custom_strncat(str_2, str_3, num));
}
END_TEST

START_TEST(strncat_2) {
  char str_1[30] = "Hello, world!";
  char str_2[30] = "Hello, world!";
  char str_3[] = "\0";
  custom_size_t num = 1;
  ck_assert_pstr_eq(strncat(str_1, str_3, num), custom_strncat(str_2, str_3, num));
}
END_TEST

START_TEST(strncat_3) {
  char str_1[30] = "Hello, world!";
  char str_2[30] = "Hello, world!";
  char str_3[] = "\n\0\\d\f\\g\7";
  custom_size_t num = 3;
  ck_assert_pstr_eq(strncat(str_1, str_3, num), custom_strncat(str_2, str_3, num));
}
END_TEST

START_TEST(strncat_4) {
  char str_1[30] = "Hello, world!";
  char str_2[30] = "Hello, world!";
  char str_3[] = "";
  custom_size_t num = 0;
  ck_assert_pstr_eq(strncat(str_1, str_3, num), custom_strncat(str_2, str_3, num));
}
END_TEST

START_TEST(strncat_5) {
  char str_1[30] = "";
  char str_2[30] = "";
  char str_3[] = "Hello, world!";
  custom_size_t num = 13;
  ck_assert_pstr_eq(strncat(str_1, str_3, num), custom_strncat(str_2, str_3, num));
}
END_TEST

START_TEST(strncat_6) {
  char str_1[100] = "Hello, world!";
  char str_2[100] = "Hello, world!";
  char str_3[] =
      "My name is Polina. I hate this, maybe I'm not supposed for this.";
  custom_size_t num = 6;
  ck_assert_pstr_eq(strncat(str_1, str_3, num), custom_strncat(str_2, str_3, num));
}
END_TEST

START_TEST(strncat_7) {
  char str_1[30] = "";
  char str_2[30] = "";
  char str_3[] = "Hello, world!";
  custom_size_t num = 3;
  ck_assert_pstr_eq(strncat(str_1, str_3, num), custom_strncat(str_2, str_3, num));
}
END_TEST

START_TEST(strncat_8) {
  char str_1[100] = "Hello, world!";
  char str_2[100] = "Hello, world!";
  char str_3[] = "My name is Polina.";
  custom_size_t num = 2;
  ck_assert_pstr_eq(strncat(str_1, str_3, num), custom_strncat(str_2, str_3, num));
}
END_TEST

START_TEST(strncat_9) {
  char str_1[100] = "";
  char str_2[100] = "";
  char str_3[] = "";
  custom_size_t num = 10;
  ck_assert_pstr_eq(strncat(str_1, str_3, num), custom_strncat(str_2, str_3, num));
}
END_TEST

START_TEST(strncat_10) {
  char str_1[100] = "Hello\0, world!";
  char str_2[100] = "Hello\0, world!";
  char str_3[] = "My name is\0 Polina.";
  custom_size_t num = 15;
  ck_assert_pstr_eq(strncat(str_1, str_3, num), custom_strncat(str_2, str_3, num));
}
END_TEST

START_TEST(strncat_11) {
  char str_1[100] = "Hello, world!";
  char str_2[100] = "Hello, world!";
  char str_3[] = "\0";
  custom_size_t num = 1;
  ck_assert_pstr_eq(strncat(str_1, str_3, num), custom_strncat(str_2, str_3, num));
}
END_TEST

START_TEST(strncat_12) {
  char str_1[100] = "Hello, world!";
  char str_2[100] = "Hello, world!";
  char str_3[] = "\0";
  custom_size_t num = 0;
  ck_assert_pstr_eq(strncat(str_1, str_3, num), custom_strncat(str_2, str_3, num));
}
END_TEST

START_TEST(strncat_13) {
  char str_1[100] = "Hello, world!";
  char str_2[100] = "Hello, world!";
  char str_3[] = "\0\0\0\0";
  custom_size_t num = 4;
  ck_assert_pstr_eq(strncat(str_1, str_3, num), custom_strncat(str_2, str_3, num));
}
END_TEST

START_TEST(strncat_14) {
  char str_1[100] = "Hello, world!";
  char str_2[100] = "Hello, world!";
  char str_3[] = "";
  custom_size_t num = 2;
  ck_assert_pstr_eq(strncat(str_1, str_3, num), custom_strncat(str_2, str_3, num));
}
END_TEST

START_TEST(strncat_15) {
  char str_1[100] = "Hello, world!\0\0\0";
  char str_2[100] = "Hello, world!\0\0\0";
  char str_3[] = "My name is Polina.";
  custom_size_t num = 0;
  ck_assert_pstr_eq(strncat(str_1, str_3, num), custom_strncat(str_2, str_3, num));
}
END_TEST

Suite *test_strncat(void) {
  Suite *s = suite_create("\033[45m-=S21_STRNCAT=-\033[0m");
  TCase *tc = tcase_create("strncat_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, strncat_1);
  tcase_add_test(tc, strncat_2);
  tcase_add_test(tc, strncat_3);
  tcase_add_test(tc, strncat_4);
  tcase_add_test(tc, strncat_5);
  tcase_add_test(tc, strncat_6);
  tcase_add_test(tc, strncat_7);
  tcase_add_test(tc, strncat_8);
  tcase_add_test(tc, strncat_9);
  tcase_add_test(tc, strncat_10);
  tcase_add_test(tc, strncat_11);
  tcase_add_test(tc, strncat_12);
  tcase_add_test(tc, strncat_13);
  tcase_add_test(tc, strncat_14);
  tcase_add_test(tc, strncat_15);

  suite_add_tcase(s, tc);
  return s;
}