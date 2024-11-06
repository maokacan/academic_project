#include "test_me.h"

START_TEST(memcpy_1) {
  char str_1[] = "Hello, world!";
  char str_2[] = "Hello, world!";
  char str_3[] = "Good";
  custom_size_t num = 4;
  ck_assert_str_eq(memcpy(str_1, str_3, num), custom_memcpy(str_2, str_3, num));
}
END_TEST

START_TEST(memcpy_2) {
  char str_1[] = "Hello, world!";
  char str_2[] = "Hello, world!";
  char str_3[] = "\0";
  custom_size_t num = 1;
  ck_assert_str_eq(memcpy(str_1, str_3, num), custom_memcpy(str_2, str_3, num));
}
END_TEST

START_TEST(memcpy_3) {
  char str_1[] = "Hello, world!";
  char str_2[] = "Hello, world!";
  char str_3[] = "f";
  custom_size_t num = 0;
  ck_assert_str_eq(memcpy(str_1, str_3, num), custom_memcpy(str_2, str_3, num));
}
END_TEST

START_TEST(memcpy_4) {
  char str_1[] = "Hello, world!";
  char str_2[] = "Hello, world!";
  char str_3[] = "Hi";
  custom_size_t num = 3;
  ck_assert_str_eq(memcpy(str_1, str_3, num), custom_memcpy(str_2, str_3, num));
}
END_TEST

START_TEST(memcpy_5) {
  char str_1[] = "Hello, world!";
  char str_2[] = "Hello, world!";
  char str_3[] = "Hi";
  custom_size_t num = 2;
  ck_assert_str_eq(memcpy(str_1, str_3, num), custom_memcpy(str_2, str_3, num));
}
END_TEST

START_TEST(memcpy_6) {
  char str_1[] = "";
  char str_2[] = "";
  char str_3[] = "love";
  custom_size_t num = 0;
  ck_assert_str_eq(memcpy(str_1, str_3, num), custom_memcpy(str_2, str_3, num));
}
END_TEST

START_TEST(memcpy_7) {
  char str_1[] = "new_strnew_string";
  char str_2[] = "new_strnew_string";
  char str_3[] = "new_string";
  custom_size_t num = strlen(str_3);
  ck_assert_str_eq(memcpy(str_1, str_3, num), custom_memcpy(str_2, str_3, num));
}
END_TEST

START_TEST(memcpy_8) {
  char str_1[] = "699\017020";
  char str_2[] = "699\017020";
  char str_3[] = "com";
  custom_size_t num = 3;
  ck_assert_str_eq(memcpy(str_1, str_3, num), custom_memcpy(str_2, str_3, num));
}
END_TEST

START_TEST(memcpy_9) {
  char str_1[] = "69917020";
  char str_2[] = "69917020";
  char str_3[] = "c";
  custom_size_t num = 1;
  ck_assert_str_eq(memcpy(str_1, str_3, num), custom_memcpy(str_2, str_3, num));
}
END_TEST

START_TEST(memcpy_10) {
  char str_1[] = "69917020";
  char str_2[] = "69917020";
  char str_3[] = "com";
  custom_size_t num = 3;
  ck_assert_str_eq(memcpy(str_1, str_3, num), custom_memcpy(str_2, str_3, num));
}
END_TEST

START_TEST(memcpy_11) {
  char *src1 = "Hello";
  char *src2 = "str";
  char dest1[3] = {0, 0, 0};
  char dest2[5] = {0, 0, 0, 0, 0};

  ck_assert_str_eq(custom_memcpy(dest1, src2, 0), memcpy(dest1, src2, 0));
  ck_assert_str_eq(custom_memcpy(dest2, src2, sizeof(char) * 3),
                   memcpy(dest2, src2, sizeof(char) * 3));
  ck_assert_str_eq(custom_memcpy(dest2, src1, sizeof(char) * 4),
                   memcpy(dest2, src1, sizeof(char) * 4));
  ck_assert_str_eq(custom_memcpy(dest2, src1, sizeof(char) * 5),
                   memcpy(dest2, src1, sizeof(char) * 5));
}
END_TEST

Suite *test_memcpy(void) {
  Suite *s = suite_create("\033[45m-=S21_MEMCPY=-\033[0m");
  TCase *tc = tcase_create("memcpy_tc");

  tcase_add_test(tc, memcpy_1);
  tcase_add_test(tc, memcpy_2);
  tcase_add_test(tc, memcpy_3);
  tcase_add_test(tc, memcpy_4);
  tcase_add_test(tc, memcpy_5);
  tcase_add_test(tc, memcpy_6);
  tcase_add_test(tc, memcpy_7);
  tcase_add_test(tc, memcpy_8);
  tcase_add_test(tc, memcpy_9);
  tcase_add_test(tc, memcpy_10);
  tcase_add_test(tc, memcpy_11);

  suite_add_tcase(s, tc);
  return s;
}