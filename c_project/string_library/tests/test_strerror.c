#include "test_me.h"

START_TEST(strerror_1) {
  for (int ind = 0; ind < 150; ind++) {
    ck_assert_str_eq(strerror(ind), custom_strerror(ind));
  }
}
END_TEST

START_TEST(strerror_2) {
  int num = -1;
  ck_assert_str_eq(strerror(num), custom_strerror(num));
}
END_TEST

Suite *test_strerror(void) {
  Suite *s = suite_create("\033[45m-=S21_STRERROR=-\033[0m");
  TCase *tc = tcase_create("strerror_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, strerror_1);
  tcase_add_test(tc, strerror_2);

  suite_add_tcase(s, tc);
  return s;
}