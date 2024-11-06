#include "test.h"

int main(void) {
  run_tests2();
  run_tests();
  return 0;
}

void run_tests2() {
  int failed = 0;
  Suite *custom_decimal_test[] = {test_add(),
                               test_sub(),
                               test_mul(),
                               test_dec_to_int(),
                               test_dec_to_float(),
                               test_negate(),
                               test_truncate(),
                               test_div(),
                               test_round(),
                               test_floor(),
                               NULL};

  for (int i = 0; custom_decimal_test[i] != NULL; i++) {
    SRunner *sr = srunner_create(custom_decimal_test[i]);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }
  printf("========= FAILED: %d =========\n", failed);
}
void run_testcase(Suite *testcase) {
  static int counter_testcase = 1;
  if (counter_testcase > 1) counter_testcase++;
  SRunner *sr = srunner_create(testcase);
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);
  srunner_free(sr);
}

void run_tests(void) {
  Suite *list_cases[] = {suite_from_float_to_decimal(),
                         suite_from_int_to_decimal(),
                         suite_is_equal(),
                         suite_is_not_equal(),
                         suite_is_greater(),
                         suite_is_greater_or_equal(),
                         suite_is_less(),
                         suite_is_less_or_equal(),
                         NULL};

  for (Suite **current_testcase = list_cases; *current_testcase != NULL;
       current_testcase++) {
    run_testcase(*current_testcase);
  }
}
