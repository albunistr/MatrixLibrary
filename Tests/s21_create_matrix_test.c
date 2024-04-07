#include "s21_testing.h"

START_TEST(create_matrix_1) {
  matrix_t A = {};
  int output = s21_create_matrix(0, 0, &A);
  ck_assert_int_eq(output, Incorrect_Matrix);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(create_matrix_2) {
  matrix_t A = {};
  matrix_t *a = &A;
  a = NULL;
  int output = s21_create_matrix(5, 5, a);
  ck_assert_int_eq(output, Incorrect_Matrix);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(create_matrix_3) {
  matrix_t A = {};
  int output = s21_create_matrix(4, 3, &A);
  ck_assert_int_eq(output, OK);
  s21_remove_matrix(&A);
}
END_TEST

Suite *check_create_matrix() {
  Suite *s;
  TCase *tc_1;
  s = suite_create("create_matrix_test");
  tc_1 = tcase_create("tc_1");
  tcase_add_test(tc_1, create_matrix_1);
  tcase_add_test(tc_1, create_matrix_2);
  tcase_add_test(tc_1, create_matrix_3);
  suite_add_tcase(s, tc_1);
  return s;
}
