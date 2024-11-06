#include "test_me.h"

START_TEST(strncmp_1) {
  char str_1[] = "Hello, world!";
  char str_2[] = "Hello, world!";
  custom_size_t num = 14;
  int num_1 = strncmp(str_1, str_2, num);
  num_1 = num_1 > 0 ? 1 : num_1 == 0 ? 0 : -1;
  int num_2 = custom_strncmp(str_1, str_2, num);
  num_2 = num_2 > 0 ? 1 : num_2 == 0 ? 0 : -1;
  ck_assert_int_eq(num_1, num_2);
}
END_TEST

START_TEST(strncmp_2) {
  char str_1[] = "Hello, world!";
  char str_2[] = "Hello, worldj";
  custom_size_t num = 14;
  int num_1 = strncmp(str_1, str_2, num);
  num_1 = num_1 > 0 ? 1 : num_1 == 0 ? 0 : -1;
  int num_2 = custom_strncmp(str_1, str_2, num);
  num_2 = num_2 > 0 ? 1 : num_2 == 0 ? 0 : -1;
  ck_assert_int_eq(num_1, num_2);
}
END_TEST

START_TEST(strncmp_3) {
  char str_1[] = "";
  char str_2[] = "";
  custom_size_t num = 1;
  int num_1 = strncmp(str_1, str_2, num);
  num_1 = num_1 > 0 ? 1 : num_1 == 0 ? 0 : -1;
  int num_2 = custom_strncmp(str_1, str_2, num);
  num_2 = num_2 > 0 ? 1 : num_2 == 0 ? 0 : -1;
  ck_assert_int_eq(num_1, num_2);
}
END_TEST

START_TEST(strncmp_4) {
  char str_1[] = "f";
  char str_2[] = "";
  custom_size_t num = 1;
  int num_1 = strncmp(str_1, str_2, num);
  num_1 = num_1 > 0 ? 1 : num_1 == 0 ? 0 : -1;
  int num_2 = custom_strncmp(str_1, str_2, num);
  num_2 = num_2 > 0 ? 1 : num_2 == 0 ? 0 : -1;
  ck_assert_int_eq(num_1, num_2);
}
END_TEST

START_TEST(strncmp_5) {
  char str_1[] = "";
  char str_2[] = "j";
  custom_size_t num = 1;
  int num_1 = strncmp(str_1, str_2, num);
  num_1 = num_1 > 0 ? 1 : num_1 == 0 ? 0 : -1;
  int num_2 = custom_strncmp(str_1, str_2, num);
  num_2 = num_2 > 0 ? 1 : num_2 == 0 ? 0 : -1;
  ck_assert_int_eq(num_1, num_2);
}
END_TEST

START_TEST(strncmp_6) {
  char str_1[] = "1242434246364377659";
  char str_2[] = "1242434246364377659";
  custom_size_t num = 19;
  int num_1 = strncmp(str_1, str_2, num);
  num_1 = num_1 > 0 ? 1 : num_1 == 0 ? 0 : -1;
  int num_2 = custom_strncmp(str_1, str_2, num);
  num_2 = num_2 > 0 ? 1 : num_2 == 0 ? 0 : -1;
  ck_assert_int_eq(num_1, num_2);
}
END_TEST

START_TEST(strncmp_7) {
  char str_1[] = "1242434246364377659";
  char str_2[] = "1242434246364377659";
  custom_size_t num = 2;
  int num_1 = strncmp(str_1, str_2, num);
  num_1 = num_1 > 0 ? 1 : num_1 == 0 ? 0 : -1;
  int num_2 = custom_strncmp(str_1, str_2, num);
  num_2 = num_2 > 0 ? 1 : num_2 == 0 ? 0 : -1;
  ck_assert_int_eq(num_1, num_2);
}
END_TEST

START_TEST(strncmp_8) {
  char str_1[] = "g124243425";
  char str_2[] = "124243424";
  custom_size_t num = 0;
  int num_1 = strncmp(str_1, str_2, num);
  num_1 = num_1 > 0 ? 1 : num_1 == 0 ? 0 : -1;
  int num_2 = custom_strncmp(str_1, str_2, num);
  num_2 = num_2 > 0 ? 1 : num_2 == 0 ? 0 : -1;
  ck_assert_int_eq(num_1, num_2);
}
END_TEST

START_TEST(strncmp_9) {
  char str_1[] = "";
  char str_2[] = "";
  custom_size_t num = 1;
  int num_1 = strncmp(str_1, str_2, num);
  num_1 = num_1 > 0 ? 1 : num_1 == 0 ? 0 : -1;
  int num_2 = custom_strncmp(str_1, str_2, num);
  num_2 = num_2 > 0 ? 1 : num_2 == 0 ? 0 : -1;
  ck_assert_int_eq(num_1, num_2);
}
END_TEST

START_TEST(strncmp_10) {
  char str_1[10] = "abcde";
  char str_2[10] = "abcdo";
  char str_3[] = "abcdooe";
  char str_4[5] = "";
  char str_5[5] = "";

  ck_assert_int_eq(custom_strncmp(str_1, str_2, 5), strncmp(str_1, str_2, 5));
  ck_assert_int_eq(custom_strncmp(str_3, str_2, 5), strncmp(str_3, str_2, 5));
  ck_assert_int_eq(custom_strncmp(str_4, str_2, 5), strncmp(str_4, str_2, 5));
  ck_assert_int_eq(custom_strncmp(str_1, str_4, 5), strncmp(str_1, str_4, 5));
  ck_assert_int_eq(custom_strncmp(str_4, str_5, 5), strncmp(str_4, str_5, 5));
  ck_assert_int_eq(custom_strncmp(str_1, str_2, 10), strncmp(str_1, str_2, 10));
}
END_TEST

Suite *test_strncmp(void) {
  Suite *s = suite_create("\033[45m-=S21_STRNCMP=-\033[0m");
  TCase *tc = tcase_create("strncmp_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, strncmp_1);
  tcase_add_test(tc, strncmp_2);
  tcase_add_test(tc, strncmp_3);
  tcase_add_test(tc, strncmp_4);
  tcase_add_test(tc, strncmp_5);
  tcase_add_test(tc, strncmp_6);
  tcase_add_test(tc, strncmp_7);
  tcase_add_test(tc, strncmp_8);
  tcase_add_test(tc, strncmp_9);
  tcase_add_test(tc, strncmp_10);

  suite_add_tcase(s, tc);
  return s;
}