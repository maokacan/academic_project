#include "test_me.h"

START_TEST(memcmp_1) {
  char str_1[] = "Hello, world!";
  char str_2[] = "Hello, world!";
  custom_size_t num = 7;
  int num_1 = memcmp(str_1, str_2, num);
  num_1 = num_1 > 0 ? 1 : num_1 == 0 ? 0 : -1;
  int num_2 = custom_memcmp(str_1, str_2, num);
  num_2 = num_2 > 0 ? 1 : num_2 == 0 ? 0 : -1;
  ck_assert_int_eq(num_1, num_2);
}
END_TEST

START_TEST(memcmp_2) {
  char str_1[] = "Hello, world!";
  char str_2[] = "Hello, world!";
  custom_size_t num = 13;
  int num_1 = memcmp(str_1, str_2, num);
  num_1 = num_1 > 0 ? 1 : num_1 == 0 ? 0 : -1;
  int num_2 = custom_memcmp(str_1, str_2, num);
  num_2 = num_2 > 0 ? 1 : num_2 == 0 ? 0 : -1;
  ck_assert_int_eq(num_1, num_2);
}
END_TEST

START_TEST(memcmp_3) {
  char str_1[] = "Hello, world!";
  char str_2[] = "Hello, world!";
  custom_size_t num = 0;
  int num_1 = memcmp(str_1, str_2, num);
  num_1 = num_1 > 0 ? 1 : num_1 == 0 ? 0 : -1;
  int num_2 = custom_memcmp(str_1, str_2, num);
  num_2 = num_2 > 0 ? 1 : num_2 == 0 ? 0 : -1;
  ck_assert_int_eq(num_1, num_2);
}
END_TEST

START_TEST(memcmp_4) {
  char str_1[] = "Hello, world!";
  char str_2[] = "Hello, world!";
  custom_size_t num = 14;
  int num_1 = memcmp(str_1, str_2, num);
  num_1 = num_1 > 0 ? 1 : num_1 == 0 ? 0 : -1;
  int num_2 = custom_memcmp(str_1, str_2, num);
  num_2 = num_2 > 0 ? 1 : num_2 == 0 ? 0 : -1;
  ck_assert_int_eq(num_1, num_2);
}
END_TEST

START_TEST(memcmp_5) {
  char str_1[] = "Hello, world!";
  char str_2[] = "Hello, world!";
  custom_size_t num = 14;
  int num_1 = memcmp(str_1, str_2, num);
  num_1 = num_1 > 0 ? 1 : num_1 == 0 ? 0 : -1;
  int num_2 = custom_memcmp(str_1, str_2, num);
  num_2 = num_2 > 0 ? 1 : num_2 == 0 ? 0 : -1;
  ck_assert_int_eq(num_1, num_2);
}
END_TEST

START_TEST(memcmp_6) {
  char str_1[] = "69917020";
  char str_2[] = "69917020";
  custom_size_t num = 0;
  int num_1 = memcmp(str_1, str_2, num);
  num_1 = num_1 > 0 ? 1 : num_1 == 0 ? 0 : -1;
  int num_2 = custom_memcmp(str_1, str_2, num);
  num_2 = num_2 > 0 ? 1 : num_2 == 0 ? 0 : -1;
  ck_assert_int_eq(num_1, num_2);
}
END_TEST

START_TEST(memcmp_7) {
  char str_1[] = "69917020";
  char str_2[] = "69917020";
  custom_size_t num = 2;
  int num_1 = memcmp(str_1, str_2, num);
  num_1 = num_1 > 0 ? 1 : num_1 == 0 ? 0 : -1;
  int num_2 = custom_memcmp(str_1, str_2, num);
  num_2 = num_2 > 0 ? 1 : num_2 == 0 ? 0 : -1;
  ck_assert_int_eq(num_1, num_2);
}
END_TEST

START_TEST(memcmp_8) {
  char str_1[] = "69917020";
  char str_2[] = "69917020";
  custom_size_t num = 8;
  int num_1 = memcmp(str_1, str_2, num);
  num_1 = num_1 > 0 ? 1 : num_1 == 0 ? 0 : -1;
  int num_2 = custom_memcmp(str_1, str_2, num);
  num_2 = num_2 > 0 ? 1 : num_2 == 0 ? 0 : -1;
  ck_assert_int_eq(num_1, num_2);
}
END_TEST

START_TEST(memcmp_9) {
  char str_1[] = "69917020";
  char str_2[] = "69917020";
  custom_size_t num = 9;
  int num_1 = memcmp(str_1, str_2, num);
  num_1 = num_1 > 0 ? 1 : num_1 == 0 ? 0 : -1;
  int num_2 = custom_memcmp(str_1, str_2, num);
  num_2 = num_2 > 0 ? 1 : num_2 == 0 ? 0 : -1;
  ck_assert_int_eq(num_1, num_2);
}
END_TEST

START_TEST(memcmp_10) {
  char str_1[] = "69917020";
  char str_2[] = "6991702H";
  custom_size_t num = 7;
  int num_1 = memcmp(str_1, str_2, num);
  num_1 = num_1 > 0 ? 1 : num_1 == 0 ? 0 : -1;
  int num_2 = custom_memcmp(str_1, str_2, num);
  num_2 = num_2 > 0 ? 1 : num_2 == 0 ? 0 : -1;
  ck_assert_int_eq(num_1, num_2);
}
END_TEST

START_TEST(memcmp_11) {
  char str_1[] = "69917020";
  char str_2[] = "6991702H";
  custom_size_t num = 4;
  int num_1 = memcmp(str_1, str_2, num);
  num_1 = num_1 > 0 ? 1 : num_1 == 0 ? 0 : -1;
  int num_2 = custom_memcmp(str_1, str_2, num);
  num_2 = num_2 > 0 ? 1 : num_2 == 0 ? 0 : -1;
  ck_assert_int_eq(num_1, num_2);
}
END_TEST

START_TEST(memcmp_12) {
  char str_1[] = "69917020";
  char str_2[] = "6991702H";
  custom_size_t num = 8;
  int num_1 = memcmp(str_1, str_2, num);
  num_1 = num_1 > 0 ? 1 : num_1 == 0 ? 0 : -1;
  int num_2 = custom_memcmp(str_1, str_2, num);
  num_2 = num_2 > 0 ? 1 : num_2 == 0 ? 0 : -1;
  ck_assert_int_eq(num_1, num_2);
}
END_TEST

START_TEST(memcmp_13) {
  char str_1[] = "69917020";
  char str_2[] = "6991702H";
  custom_size_t num = 9;
  int num_1 = memcmp(str_1, str_2, num);
  num_1 = num_1 > 0 ? 1 : num_1 == 0 ? 0 : -1;
  int num_2 = custom_memcmp(str_1, str_2, num);
  num_2 = num_2 > 0 ? 1 : num_2 == 0 ? 0 : -1;
  ck_assert_int_eq(num_1, num_2);
}
END_TEST

START_TEST(memcmp_14) {
  char str_1[] =
      "The memcmp() function compares the first n bytes (each interpreted as "
      "unsigned char) of the memory areas str_1 and s2.";
  char str_2[] =
      "The memcmp() function compares the first n bytes (each interpreted as "
      "unsigned char) of the memory areas str_1 and s2.";
  custom_size_t num = 115;
  int num_1 = memcmp(str_1, str_2, num);
  num_1 = num_1 > 0 ? 1 : num_1 == 0 ? 0 : -1;
  int num_2 = custom_memcmp(str_1, str_2, num);
  num_2 = num_2 > 0 ? 1 : num_2 == 0 ? 0 : -1;
  ck_assert_int_eq(num_1, num_2);
}
END_TEST

START_TEST(memcmp_15) {
  char str_1[] =
      "The memcmp() function compares the first n bytes (each interpreted as "
      "unsigned char) of the memory areas str_1 and s2.";
  char str_2[] =
      "The memcmp() function compares the first n bytes (each interpreted as "
      "unsigned char) of the memory areas str_1 and s2";
  custom_size_t num = 115;
  int num_1 = memcmp(str_1, str_2, num);
  num_1 = num_1 > 0 ? 1 : num_1 == 0 ? 0 : -1;
  int num_2 = custom_memcmp(str_1, str_2, num);
  num_2 = num_2 > 0 ? 1 : num_2 == 0 ? 0 : -1;
  ck_assert_int_eq(num_1, num_2);
}
END_TEST

START_TEST(memcmp_16) {
  char str_1[] = "";
  char str_2[] = "";
  custom_size_t num = 0;
  int num_1 = memcmp(str_1, str_2, num);
  num_1 = num_1 > 0 ? 1 : num_1 == 0 ? 0 : -1;
  int num_2 = custom_memcmp(str_1, str_2, num);
  num_2 = num_2 > 0 ? 1 : num_2 == 0 ? 0 : -1;
  ck_assert_int_eq(num_1, num_2);
}
END_TEST

int is_matching_sign(int a, int b) {
  return ((a == 0 && b == 0) || (a < 0 && b < 0) || (a > 0 && b > 0));
}

START_TEST(memcmp_17) {
  char str_1[] = "abcde";
  char str_2[] = "abcdo";
  char str_3[5] = "";
  char str_4[] = "abcdo";
  char str_5[] = "abooo";
  int a = 1, b = 3;

  ck_assert(
      is_matching_sign(custom_memcmp(str_1, str_2, 5), memcmp(str_1, str_2, 5)));
  ck_assert(
      is_matching_sign(custom_memcmp(str_3, str_2, 5), memcmp(str_3, str_2, 5)));
  ck_assert(
      is_matching_sign(custom_memcmp(str_1, str_3, 5), memcmp(str_1, str_3, 5)));
  ck_assert(
      is_matching_sign(custom_memcmp(str_4, str_2, 5), memcmp(str_4, str_2, 5)));
  ck_assert(
      is_matching_sign(custom_memcmp(str_1, str_5, 3), memcmp(str_1, str_5, 3)));
  ck_assert(is_matching_sign(custom_memcmp(&a, &b, 3), memcmp(&a, &b, 3)));
}
END_TEST

Suite *test_memcmp(void) {
  Suite *s = suite_create("\033[45m-=S21_MEMCMP=-\033[0m");
  TCase *tc = tcase_create("memcmp_tc");

  tcase_add_test(tc, memcmp_1);
  tcase_add_test(tc, memcmp_2);
  tcase_add_test(tc, memcmp_3);
  tcase_add_test(tc, memcmp_4);
  tcase_add_test(tc, memcmp_5);
  tcase_add_test(tc, memcmp_6);
  tcase_add_test(tc, memcmp_7);
  tcase_add_test(tc, memcmp_8);
  tcase_add_test(tc, memcmp_9);
  tcase_add_test(tc, memcmp_10);
  tcase_add_test(tc, memcmp_11);
  tcase_add_test(tc, memcmp_12);
  tcase_add_test(tc, memcmp_13);
  tcase_add_test(tc, memcmp_14);
  tcase_add_test(tc, memcmp_15);
  tcase_add_test(tc, memcmp_16);
  tcase_add_test(tc, memcmp_17);

  suite_add_tcase(s, tc);
  return s;
}