#include "test.h"

int main() { run_tests(); }

void run_tests() {
  int failed = 0;
  Suite *custom_matrix_test[] = {test_create(),
                              test_remove(),
                              test_equal(),
                              test_sum(),
                              test_sub(),
                              test_transpose(),
                              test_mult_number(),
                              test_mult_matrix(),
                              test_calc_complements(),
                              test_determinant(),
                              test_inverse_matrix(),
                              NULL};
  for (int i = 0; custom_matrix_test[i]; i++) {
    SRunner *sr = srunner_create(custom_matrix_test[i]);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }
  if (failed > 0) {
    printf(RED "\n>>>>>>>>> FAILED: %d <<<<<<<<<\n" RESET, failed);
  } else {
    printf(GREEN "\n>>>>>>>>> SUCCESS <<<<<<<<<\n" RESET);
  }
}