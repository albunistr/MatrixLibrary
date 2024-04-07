#include "s21_testing.h"

START_TEST(remove_matrix_1) {
  matrix_t A = {};
  s21_create_matrix(4, 3, &A);
  s21_remove_matrix(&A);
  ck_assert_ptr_null(A.matrix);
}
END_TEST

START_TEST(remove_matrix_2) {
  matrix_t A = {};
  s21_create_matrix(4, 3, &A);
  ck_assert_ptr_nonnull(A.matrix);
  s21_remove_matrix(&A);
}
END_TEST

Suite *check_remove_matrix() {
  Suite *s;
  TCase *tc_1;
  s = suite_create("remove_matrix_test");
  tc_1 = tcase_create("tc_1");
  tcase_add_test(tc_1, remove_matrix_1);
  tcase_add_test(tc_1, remove_matrix_2);
  suite_add_tcase(s, tc_1);
  return s;
}