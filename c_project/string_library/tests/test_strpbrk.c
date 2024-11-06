#include "test_me.h"

START_TEST(strpbrk_1) {
  char str_1[] = "Hello, world!";
  char str_2[] = "Hello, world!";
  ck_assert_pstr_eq(strpbrk(str_1, str_2), custom_strpbrk(str_1, str_2));
}
END_TEST

START_TEST(strpbrk_2) {
  char str_1[] = "Hello, world!";
  char str_2[] = "!";
  ck_assert_pstr_eq(strpbrk(str_1, str_2), custom_strpbrk(str_1, str_2));
}
END_TEST

START_TEST(strpbrk_3) {
  char str_1[] = "";
  char str_2[] = "He";
  ck_assert_pstr_eq(strpbrk(str_1, str_2), custom_strpbrk(str_1, str_2));
}
END_TEST

START_TEST(strpbrk_4) {
  char str_1[] = "\0";
  char str_2[] = "";
  ck_assert_pstr_eq(strpbrk(str_1, str_2), custom_strpbrk(str_1, str_2));
}
END_TEST

START_TEST(strpbrk_5) {
  char str_1[] = "";
  char str_2[] = "";
  ck_assert_pstr_eq(strpbrk(str_1, str_2), custom_strpbrk(str_1, str_2));
}
END_TEST

START_TEST(strpbrk_6) {
  char str_1[] = "1242434246364377659";
  char str_2[] = "364377659";
  ck_assert_pstr_eq(strpbrk(str_1, str_2), custom_strpbrk(str_1, str_2));
}
END_TEST

START_TEST(strpbrk_7) {
  ck_assert_ptr_eq((void *)custom_strpbrk("abcde", "ej"),
                   (void *)strpbrk("abcde", "ej"));
  ck_assert_ptr_eq((void *)custom_strpbrk("", "ej"), (void *)strpbrk("", "ej"));
  ck_assert_ptr_eq((void *)custom_strpbrk("abcde", "eea"),
                   (void *)strpbrk("abcde", "eea"));
  ck_assert_ptr_eq((void *)custom_strpbrk("abcde", ""),
                   (void *)strpbrk("abcde", ""));
  ck_assert_ptr_eq((void *)custom_strpbrk("", ""), (void *)strpbrk("", ""));
  ck_assert_ptr_eq((void *)custom_strpbrk("aaaaa", "aa"),
                   (void *)strpbrk("aaaaa", "aa"));
}
END_TEST

Suite *test_strpbrk(void) {
  Suite *s = suite_create("\033[45m-=S21_STRPBRK=-\033[0m");
  TCase *tc = tcase_create("strpbrk_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, strpbrk_1);
  tcase_add_test(tc, strpbrk_2);
  tcase_add_test(tc, strpbrk_3);
  tcase_add_test(tc, strpbrk_4);
  tcase_add_test(tc, strpbrk_5);
  tcase_add_test(tc, strpbrk_6);
  tcase_add_test(tc, strpbrk_7);

  suite_add_tcase(s, tc);
  return s;
}