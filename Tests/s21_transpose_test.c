#include "s21_testing.h"

START_TEST(transpose_1) {
  matrix_t A = {}, result = {};
  s21_create_matrix(5, 0, &A);
  int output = s21_transpose(&A, &result);
  ck_assert_int_eq(output, Incorrect_Matrix);
  s21_remove_matrix(&A), s21_remove_matrix(&result);
}
END_TEST

START_TEST(transpose_2) {
  matrix_t A = {}, result = {};
  int output = s21_transpose(&A, &result);
  ck_assert_int_eq(output, Incorrect_Matrix);
  s21_remove_matrix(&A), s21_remove_matrix(&result);
}
END_TEST

START_TEST(transpose_3) {
  matrix_t A = {}, result = {}, template = {};
  s21_create_matrix(4, 3, &A), s21_create_matrix(3, 4, &template);
  initialize(&A, 1.4);
  int output = s21_transpose(&A, &result);
  ck_assert_int_eq(output, OK);
  template.matrix[0][0] = template.matrix[0][1] = template.matrix[0][2] =
      template.matrix[0][3] = template.matrix[1][0] = template.matrix[2][0] =
          1.4;
  template.matrix[1][1] = 2.8, template.matrix[1][2] = 4.2,
  template.matrix[1][3] = 5.6;
  template.matrix[2][1] = 4.2, template.matrix[2][2] = 7,
  template.matrix[2][3] = 9.8;
  int status = s21_eq_matrix(&result, &template);
  ck_assert_int_eq(status, SUCCESS);
  s21_remove_matrix(&A), s21_remove_matrix(&result),
      s21_remove_matrix(&template);
}
END_TEST

START_TEST(transpose_4) {
  matrix_t A = {}, result = {};
  s21_create_matrix(5, 5, &A);
  A.rows = 0;
  int output = s21_transpose(&A, &result);
  ck_assert_int_eq(output, Calculation_Error);
  A.rows = 5;
  s21_remove_matrix(&A), s21_remove_matrix(&result);
}

Suite *check_transpose() {
  Suite *s;
  TCase *tc_1;
  s = suite_create("transpose_test");
  tc_1 = tcase_create("tc_1");
  tcase_add_test(tc_1, transpose_1);
  tcase_add_test(tc_1, transpose_2);
  tcase_add_test(tc_1, transpose_3);
  tcase_add_test(tc_1, transpose_4);
  suite_add_tcase(s, tc_1);
  return s;
}