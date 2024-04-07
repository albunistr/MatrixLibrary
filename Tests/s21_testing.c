#include "s21_testing.h"

void run_test(Suite *s, int *fail) {
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  *fail = srunner_ntests_failed(runner);
  srunner_free(runner);
}

int main() {
  int fail = 0;
  run_test(check_create_matrix(), &fail);
  run_test(check_remove_matrix(), &fail);
  run_test(check_eq_matrix(), &fail);
  run_test(check_sum_matrix(), &fail);
  run_test(check_sub_matrix(), &fail);
  run_test(check_mult_number(), &fail);
  run_test(check_mult_matrix(), &fail);
  run_test(check_transpose(), &fail);
  run_test(check_determinant(), &fail);
  run_test(check_calc_complements(), &fail);
  run_test(check_inverse_matrix(), &fail);
  return fail;
}