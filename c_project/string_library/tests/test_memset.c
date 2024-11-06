#include "test_me.h"

START_TEST(memset_1) {
  char str_1[] = "Hello, world!";
  char str_2[] = "Hello, world!";
  int ch = ' ';
  custom_size_t num = strlen(str_1);
  ck_assert_str_eq(memset(str_1, ch, num), custom_memset(str_2, ch, num));
}
END_TEST

START_TEST(memset_2) {
  char str_1[] = "Hello, world!";
  char str_2[] = "Hello, world!";
  int ch = ' ';
  custom_size_t num = 5;
  ck_assert_str_eq(memset(str_1, ch, num), custom_memset(str_2, ch, num));
}
END_TEST

START_TEST(memset_3) {
  char str_1[] = "Hello, world!";
  char str_2[] = "Hello, world!";
  int ch = ' ';
  custom_size_t num = 0;
  ck_assert_str_eq(memset(str_1, ch, num), custom_memset(str_2, ch, num));
}
END_TEST

START_TEST(memset_4) {
  char str_1[] = "";
  char str_2[] = "";
  int ch = '\0';
  custom_size_t num = 0;
  ck_assert_str_eq(memset(str_1, ch, num), custom_memset(str_2, ch, num));
}
END_TEST

START_TEST(memset_5) {
  char str_1[] = "Hello";
  char str_2[] = "Hello";
  int ch = '\0';
  custom_size_t num = 4;
  ck_assert_str_eq(memset(str_1, ch, num), custom_memset(str_2, ch, num));
}
END_TEST

START_TEST(memset_6) {
  char str_1[] = "Hello, world!";
  char str_2[] = "Hello, world!";
  int ch = 80;
  custom_size_t num = 7;
  ck_assert_str_eq(memset(str_1, ch, num), custom_memset(str_2, ch, num));
}
END_TEST

Suite *test_memset(void) {
  Suite *s = suite_create("\033[45m-=S21_MEMSET=-\033[0m");
  TCase *tc = tcase_create("memset_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, memset_1);
  tcase_add_test(tc, memset_2);
  tcase_add_test(tc, memset_3);
  tcase_add_test(tc, memset_4);
  tcase_add_test(tc, memset_5);
  tcase_add_test(tc, memset_6);

  suite_add_tcase(s, tc);
  return s;
}