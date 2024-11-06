#include "test_me.h"

START_TEST(strncpy_1) {
  char str_1[20] = "Hello, world!";
  char str_2[20] = "Hello, world!";
  char str_3[] = "Good";
  custom_size_t num = 5;
  ck_assert_pstr_eq(strncpy(str_1, str_3, num), custom_strncpy(str_2, str_3, num));
}
END_TEST

START_TEST(strncpy_2) {
  char str_1[20] = "Hello, world!";
  char str_2[20] = "Hello, world!";
  char str_3[] = "\0";
  custom_size_t num = 1;
  ck_assert_pstr_eq(strncpy(str_1, str_3, num), custom_strncpy(str_2, str_3, num));
}
END_TEST

START_TEST(strncpy_3) {
  char str_1[30] = "Hello, world!";
  char str_2[30] = "Hello, world!";
  char str_3[] = "fг-аг-аг";
  custom_size_t num = 1;
  ck_assert_pstr_eq(strncpy(str_1, str_3, num), custom_strncpy(str_2, str_3, num));
}
END_TEST

START_TEST(strncpy_4) {
  char str_1[5] = "";
  char str_2[5] = "";
  char str_3[] = "";
  custom_size_t num = 0;
  ck_assert_pstr_eq(strncpy(str_1, str_3, num), custom_strncpy(str_2, str_3, num));
}
END_TEST

START_TEST(strncpy_5) {
  char str_1[70] = "";
  char str_2[70] = "";
  char str_3[] =
      "I hate doing tests, it's not funny at all!!!!!!!!!!!!!!!!!!!!!!!!!";
  custom_size_t num = strlen(str_3);
  ck_assert_pstr_eq(strncpy(str_1, str_3, num), custom_strncpy(str_2, str_3, num));
}
END_TEST

START_TEST(strncpy_6) {
  char str_1[5] = "";
  char str_2[5] = "";
  char str_3[] = "\0";
  custom_size_t num = 1;
  ck_assert_pstr_eq(strncpy(str_1, str_3, num), custom_strncpy(str_2, str_3, num));
}
END_TEST

START_TEST(strncpy_7) {
  char dst1[60] = "String";
  char dst2[60] = "String";
  const char src1[] = "Hello world";
  const char src2[] = "1234567890\n\0";
  const char src3[] = "a\n\0";
  ck_assert_str_eq(strncpy(dst1, src1, 3), custom_strncpy(dst2, src1, 3));
  ck_assert_str_eq(strncpy(dst1, src2, 10), custom_strncpy(dst2, src2, 10));
  ck_assert_str_eq(strncpy(dst1, src3, 8), custom_strncpy(dst2, src3, 8));
}
END_TEST

Suite *test_strncpy(void) {
  Suite *s = suite_create("\033[45m-=S21_STRNCPY=-\033[0m");
  TCase *tc = tcase_create("strncpy_tc");

  tcase_add_test(tc, strncpy_1);
  tcase_add_test(tc, strncpy_2);
  tcase_add_test(tc, strncpy_3);
  tcase_add_test(tc, strncpy_4);
  tcase_add_test(tc, strncpy_5);
  tcase_add_test(tc, strncpy_6);
  tcase_add_test(tc, strncpy_7);

  suite_add_tcase(s, tc);
  return s;
}