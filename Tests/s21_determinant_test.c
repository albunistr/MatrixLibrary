#include "s21_testing.h"

START_TEST(determinant_1) {
  matrix_t A = {};
  double result = 0;
  int output = s21_determinant(&A, &result);
  ck_assert_int_eq(output, Incorrect_Matrix);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_2) {
  matrix_t A = {};
  double result = 0;
  s21_create_matrix(5, 0, &A);
  int output = s21_determinant(&A, &result);
  ck_assert_int_eq(output, Incorrect_Matrix);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_3) {
  matrix_t A = {};
  double result = 0;
  s21_create_matrix(4, 4, &A), initialize(&A, 1.4);

  int output = s21_determinant(&A, &result);
  ck_assert_int_eq(output, OK);
  s21_remove_matrix(&A), s21_create_matrix(1, 1, &A), A.matrix[0][0] = result;
  matrix_t a = {};
  s21_create_matrix(1, 1, &a), a.matrix[0][0] = 0;
  int status = s21_eq_matrix(&A, &a);
  ck_assert_int_eq(status, SUCCESS);
  s21_remove_matrix(&A), s21_remove_matrix(&a);
}
END_TEST

START_TEST(determinant_4) {
  matrix_t A = {};
  double result = 0;
  s21_create_matrix(4, 4, &A), initialize(&A, 1.4);
  A.matrix[1][1] = A.matrix[2][2] = A.matrix[3][2] = 0;
  int output = s21_determinant(&A, &result);

  ck_assert_int_eq(output, OK);
  s21_remove_matrix(&A), s21_create_matrix(1, 1, &A), A.matrix[0][0] = result;

  matrix_t a = {};
  s21_create_matrix(1, 1, &a), a.matrix[0][0] = 23.0496;

  int status = s21_eq_matrix(&A, &a);
  ck_assert_int_eq(status, SUCCESS);
  s21_remove_matrix(&A), s21_remove_matrix(&a);
}
END_TEST

START_TEST(determinant_5) {
  matrix_t A = {};
  double result = 0;
  s21_create_matrix(5, 4, &A);
  int output = s21_determinant(&A, &result);
  ck_assert_int_eq(output, Calculation_Error);
  s21_remove_matrix(&A);
}
END_TEST

Suite *check_determinant() {
  Suite *s;
  TCase *tc_1;
  s = suite_create("determinant_test");
  tc_1 = tcase_create("tc_1");
  tcase_add_test(tc_1, determinant_1);
  tcase_add_test(tc_1, determinant_2);
  tcase_add_test(tc_1, determinant_3);
  tcase_add_test(tc_1, determinant_4);
  tcase_add_test(tc_1, determinant_5);
  suite_add_tcase(s, tc_1);
  return s;
}