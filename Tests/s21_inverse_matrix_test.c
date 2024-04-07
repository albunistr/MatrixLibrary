#include "s21_testing.h"

START_TEST(inverse_matrix_1) {
  matrix_t A = {}, result = {};
  int output = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(output, Incorrect_Matrix);
  s21_remove_matrix(&A), s21_remove_matrix(&result);
}
END_TEST

START_TEST(inverse_matrix_2) {
  matrix_t A = {}, result = {};
  s21_create_matrix(0, 5, &A);
  int output = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(output, Incorrect_Matrix);
  s21_remove_matrix(&A), s21_remove_matrix(&result);
}
END_TEST

START_TEST(inverse_matrix_3) {
  matrix_t A = {}, result = {}, template = {};
  s21_create_matrix(4, 4, &A), s21_create_matrix(4, 4, &template);
  initialize(&A, 1.4);
  A.matrix[1][1] = A.matrix[2][2] = A.matrix[3][2] = 0;
  int output = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(output, OK);
  template.matrix[0][0] = -0.714286, template.matrix[0][1] = 0.238095,
  template.matrix[0][2] = 4.047619, template.matrix[0][3] = -2.857143;
  template.matrix[1][0] = 1.071429, template.matrix[1][1] = -0.357143,
  template.matrix[1][2] = -2.5, template.matrix[1][3] = 1.785714;
  template.matrix[2][0] = 0.714286, template.matrix[2][1] = 0,
  template.matrix[2][2] = -2.142857, template.matrix[2][3] = 1.428571;
  template.matrix[3][0] = -0.357143, template.matrix[3][1] = 0.119048,
  template.matrix[3][2] = 0.595238, template.matrix[3][3] = -0.357143;
  int status = s21_eq_matrix(&result, &template);
  ck_assert_int_eq(status, SUCCESS);
  s21_remove_matrix(&A), s21_remove_matrix(&result),
      s21_remove_matrix(&template);
}
END_TEST

START_TEST(inverse_matrix_4) {
  matrix_t A = {}, result = {}, template = {};
  s21_create_matrix(4, 4, &A), s21_create_matrix(4, 4, &template);
  initialize(&A, 0);
  int output = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(output, Calculation_Error);
  s21_remove_matrix(&A), s21_remove_matrix(&template),
      s21_remove_matrix(&result);
}
END_TEST

START_TEST(inverse_matrix_5) {
  matrix_t A = {}, result = {};
  s21_create_matrix(5, 5, &A);
  A.rows = 0;
  int output = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(output, Calculation_Error);
  A.rows = 5;
  s21_remove_matrix(&A), s21_remove_matrix(&result);
}
END_TEST

Suite *check_inverse_matrix() {
  Suite *s;
  TCase *tc_1;
  s = suite_create("inverse_matrix_test");
  tc_1 = tcase_create("tc_1");
  tcase_add_test(tc_1, inverse_matrix_1);
  tcase_add_test(tc_1, inverse_matrix_2);
  tcase_add_test(tc_1, inverse_matrix_3);
  tcase_add_test(tc_1, inverse_matrix_4);
  tcase_add_test(tc_1, inverse_matrix_5);
  suite_add_tcase(s, tc_1);
  return s;
}