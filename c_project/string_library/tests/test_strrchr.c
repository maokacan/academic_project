#include "test_me.h"

START_TEST(strrchr_1) {
  char str[] = "Hello, world!";
  int ch = 'h';
  ck_assert_pstr_eq(strrchr(str, ch), custom_strrchr(str, ch));
}
END_TEST

START_TEST(strrchr_2) {
  char str[] = "Hello, world!";
  int ch = '\0';
  ck_assert_pstr_eq(strrchr(str, ch), custom_strrchr(str, ch));
}
END_TEST

START_TEST(strrchr_3) {
  char str[] = "Hello, world!";
  int ch = ',';
  ck_assert_pstr_eq(strrchr(str, ch), custom_strrchr(str, ch));
}
END_TEST

START_TEST(strrchr_4) {
  char str[] = "Hello, world!";
  int ch = 33;
  ck_assert_pstr_eq(strrchr(str, ch), custom_strrchr(str, ch));
}
END_TEST

START_TEST(strrchr_5) {
  char str[] = "Hello, Polina!";
  int ch = 'P';
  ck_assert_pstr_eq(strrchr(str, ch), custom_strrchr(str, ch));
}
END_TEST

START_TEST(strrchr_6) {
  char str[] = "Hello, world!";
  int ch = 'w';
  ck_assert_pstr_eq(strrchr(str, ch), custom_strrchr(str, ch));
}
END_TEST

START_TEST(strrchr_7) {
  char str[] = "Hello, world!";
  int ch = '0';
  ck_assert_pstr_eq(strrchr(str, ch), custom_strrchr(str, ch));
}
END_TEST

START_TEST(strrchr_8) {
  char str[] = "Hello, world!";
  int ch = 'm';
  ck_assert_pstr_eq(strrchr(str, ch), custom_strrchr(str, ch));
}
END_TEST

START_TEST(strrchr_9) {
  char str1[] = "floppy";
  int ch1 = '\0';
  ck_assert_ptr_eq(custom_strrchr(str1, ch1), strrchr(str1, ch1));
  char str2[] = "";
  int ch2 = 'l';
  ck_assert_ptr_eq(custom_strrchr(str2, ch2), strrchr(str2, ch2));
  char str3[] = "poki doki";
  int ch3 = 'o';
  ck_assert_ptr_eq(custom_strrchr(str3, ch3), strrchr(str3, ch3));
  char str4[] = "Hello";
  int ch4 = 'o';
  ck_assert_ptr_eq(custom_strrchr(str4, ch4), strrchr(str4, ch4));
  char str5[] = "ppPpppppppppP";
  int ch5 = 'P';
  ck_assert_ptr_eq(custom_strrchr(str5, ch5), strrchr(str5, ch5));
  char str6[] = "Hello";
  int ch6 = 'p';
  ck_assert_ptr_eq(custom_strrchr(str6, ch6), strrchr(str6, ch6));
}
END_TEST

Suite *test_strrchr(void) {
  Suite *s = suite_create("\033[45m-=S21_STRRCHR=-\033[0m");
  TCase *tc = tcase_create("strrchr_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, strrchr_1);
  tcase_add_test(tc, strrchr_2);
  tcase_add_test(tc, strrchr_3);
  tcase_add_test(tc, strrchr_4);
  tcase_add_test(tc, strrchr_5);
  tcase_add_test(tc, strrchr_6);
  tcase_add_test(tc, strrchr_7);
  tcase_add_test(tc, strrchr_8);
  tcase_add_test(tc, strrchr_9);

  suite_add_tcase(s, tc);
  return s;
}