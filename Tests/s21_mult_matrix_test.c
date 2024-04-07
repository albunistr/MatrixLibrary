#include "s21_testing.h"

START_TEST(mult_matrix_1) {
  matrix_t A = {}, B = {}, result = {};
  s21_create_matrix(5, 5, &A);
  int output = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(output, Incorrect_Matrix);
  s21_remove_matrix(&A), s21_remove_matrix(&B), s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_matrix_2) {
  matrix_t A = {}, B = {}, result = {};
  s21_create_matrix(0, 5, &A), s21_create_matrix(0, 5, &B);
  int output = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(output, Incorrect_Matrix);
  s21_remove_matrix(&A), s21_remove_matrix(&B), s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_matrix_3) {
  matrix_t A = {}, B = {}, result = {};
  s21_create_matrix(4, 3, &A), s21_create_matrix(4, 4, &B);
  int output = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(output, Calculation_Error);
  s21_remove_matrix(&A), s21_remove_matrix(&B), s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_matrix_4) {
  matrix_t A = {}, B = {}, result = {}, template = {};
  s21_create_matrix(4, 3, &A), s21_create_matrix(3, 3, &B),
      s21_create_matrix(4, 3, &template);
  initialize(&A, 1.4), initialize(&B, 1.4);
  int output = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(output, OK);
  template.matrix[0][0] = 5.88, template.matrix[0][1] = 11.76,
  template.matrix[0][2] = 17.64;
  template.matrix[1][0] = 11.76, template.matrix[1][1] = 27.44,
  template.matrix[1][2] = 43.12;
  template.matrix[2][0] = 17.64, template.matrix[2][1] = 43.12,
  template.matrix[2][2] = 68.6;
  template.matrix[3][0] = 23.52, template.matrix[3][1] = 58.8,
  template.matrix[3][2] = 94.08;
  int status = s21_eq_matrix(&result, &template);
  ck_assert_int_eq(status, SUCCESS);
  s21_remove_matrix(&A), s21_remove_matrix(&B), s21_remove_matrix(&result),
      s21_remove_matrix(&template);
}
END_TEST

START_TEST(mult_matrix_5) {
  matrix_t A = {}, B = {}, result = {}, template = {};
  s21_create_matrix(4, 3, &A), s21_create_matrix(3, 3, &B),
      s21_create_matrix(4, 3, &template);
  initialize(&A, 0), initialize(&B, 0);
  int output = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(output, OK);
  for (int r = 0; r < 4; r++)
    for (int c = 0; c < 3; c++) template.matrix[r][c] = 0;
  int status = s21_eq_matrix(&result, &template);
  ck_assert_int_eq(status, SUCCESS);
  s21_remove_matrix(&A), s21_remove_matrix(&B), s21_remove_matrix(&result),
      s21_remove_matrix(&template);
}
END_TEST

Suite *check_mult_matrix() {
  Suite *s;
  TCase *tc_1;
  s = suite_create("mult_matrix_test");
  tc_1 = tcase_create("tc_1");
  tcase_add_test(tc_1, mult_matrix_1);
  tcase_add_test(tc_1, mult_matrix_2);
  tcase_add_test(tc_1, mult_matrix_3);
  tcase_add_test(tc_1, mult_matrix_4);
  tcase_add_test(tc_1, mult_matrix_5);
  suite_add_tcase(s, tc_1);
  return s;
}