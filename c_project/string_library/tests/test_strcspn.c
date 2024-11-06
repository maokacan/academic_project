#include "test_me.h"

START_TEST(strcspn_1) {
  char str_1[] =
      "Hello, world!Hello, world!Hello, world!Hello, world!Hello, world!";
  char str_2[] = "Hello, world!";
  ck_assert_int_eq(strcspn(str_1, str_2), custom_strcspn(str_1, str_2));
}
END_TEST

START_TEST(strcspn_2) {
  char str_1[] =
      "Hello, world!Hello, world!Hello, world!Hello, world!Hello, world!";
  char str_2[] =
      "Hello, world!Hello, world!Hello, world!Hello, world!Hello, world!";
  ck_assert_int_eq(strcspn(str_1, str_2), custom_strcspn(str_1, str_2));
}
END_TEST

START_TEST(strcspn_3) {
  char str_1[] = "v";
  char str_2[] = "vendetta";
  ck_assert_int_eq(strcspn(str_1, str_2), custom_strcspn(str_1, str_2));
}
END_TEST

START_TEST(strcspn_4) {
  char str_1[] = "";
  char str_2[] = "Hello, world!";
  ck_assert_int_eq(strcspn(str_1, str_2), custom_strcspn(str_1, str_2));
}
END_TEST

START_TEST(strcspn_5) {
  char str_1[] = "Hello, world!";
  char str_2[] = "";
  ck_assert_int_eq(strcspn(str_1, str_2), custom_strcspn(str_1, str_2));
}
END_TEST

START_TEST(strcspn_6) {
  char str_1[] = "6";
  char str_2[] = "67";
  ck_assert_int_eq(strcspn(str_1, str_2), custom_strcspn(str_1, str_2));
}
END_TEST

START_TEST(strcspn_7) {
  char str_1[] = "69917020";
  char str_2[] = "69917020";
  ck_assert_int_eq(strcspn(str_1, str_2), custom_strcspn(str_1, str_2));
}
END_TEST

START_TEST(strcspn_8) {
  char str_1[] = "69917020";
  char str_2[] = "69917020";
  ck_assert_int_eq(strcspn(str_1, str_2), custom_strcspn(str_1, str_2));
}
END_TEST

START_TEST(strcspn_9) {
  char str_1[] = "699";
  char str_2[] = "69917020";
  ck_assert_int_eq(strcspn(str_1, str_2), custom_strcspn(str_1, str_2));
}
END_TEST

START_TEST(strcspn_10) {
  char str_1[] = "69917020";
  char str_2[] = "699";
  ck_assert_int_eq(strcspn(str_1, str_2), custom_strcspn(str_1, str_2));
}
END_TEST

START_TEST(strcspn_11) {
  char str_1[] = "";
  char str_2[] = "";
  ck_assert_int_eq(strcspn(str_1, str_2), custom_strcspn(str_1, str_2));
}
END_TEST

START_TEST(strcspn_12) {
  char str_1[] = "69917020";
  char str_2[] = "6991702H";
  ck_assert_int_eq(strcspn(str_1, str_2), custom_strcspn(str_1, str_2));
}
END_TEST

START_TEST(strcspn_13) {
  const char *A = "rrr";
  const char *B = "r";
  const char *D = " ";

  ck_assert_int_eq(custom_strcspn(A, B), strcspn(A, B));
  ck_assert_int_eq(custom_strcspn(A, D), strcspn(A, D));
  ck_assert_int_eq(custom_strcspn("ABC", "A"), strcspn("ABC", "A"));
}
END_TEST

Suite *test_strcspn(void) {
  Suite *s = suite_create("\033[45m-=custom_STRCSPN=-\033[0m");
  TCase *tc = tcase_create("strcspn_tc");

  tcase_add_test(tc, strcspn_1);
  tcase_add_test(tc, strcspn_2);
  tcase_add_test(tc, strcspn_3);
  tcase_add_test(tc, strcspn_4);
  tcase_add_test(tc, strcspn_5);
  tcase_add_test(tc, strcspn_6);
  tcase_add_test(tc, strcspn_7);
  tcase_add_test(tc, strcspn_8);
  tcase_add_test(tc, strcspn_9);
  tcase_add_test(tc, strcspn_10);
  tcase_add_test(tc, strcspn_11);
  tcase_add_test(tc, strcspn_12);
  tcase_add_test(tc, strcspn_13);

  suite_add_tcase(s, tc);
  return s;
}