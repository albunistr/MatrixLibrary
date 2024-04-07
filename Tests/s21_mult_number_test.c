#include "s21_testing.h"

START_TEST(mult_number_1) {
  matrix_t A = {}, result = {};
  s21_create_matrix(5, 0, &A);
  int output = s21_mult_number(&A, 5, &result);
  ck_assert_int_eq(output, Incorrect_Matrix);
  s21_remove_matrix(&A), s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_number_2) {
  matrix_t A = {}, result = {};
  int output = s21_mult_number(&A, 5, &result);
  ck_assert_int_eq(output, Incorrect_Matrix);
  s21_remove_matrix(&A), s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_number_3) {
  matrix_t A = {}, result = {}, template = {};
  s21_create_matrix(4, 3, &A), s21_create_matrix(4, 3, &template);
  initialize(&A, 1.4);
  int output = s21_mult_number(&A, 5.2, &result);
  ck_assert_int_eq(output, OK);
  template.matrix[0][0] = template.matrix[0][1] = template.matrix[0][2] =
      template.matrix[1][0] = template.matrix[2][0] = template.matrix[3][0] =
          1.4 * 5.2;
  template.matrix[1][1] = 2.8 * 5.2, template.matrix[1][2] = 4.2 * 5.2;
  template.matrix[2][1] = 4.2 * 5.2, template.matrix[2][2] = 7 * 5.2,
  template.matrix[3][1] = 5.6 * 5.2, template.matrix[3][2] = 9.8 * 5.2;
  int status = s21_eq_matrix(&result, &template);
  ck_assert_int_eq(status, SUCCESS);
  s21_remove_matrix(&A), s21_remove_matrix(&result),
      s21_remove_matrix(&template);
}
END_TEST

START_TEST(mult_number_4) {
  matrix_t A = {}, result = {}, template = {};
  s21_create_matrix(5, 5, &A), s21_create_matrix(5, 5, &template);
  initialize(&A, 1.4);
  int output = s21_mult_number(&A, 0, &result);
  ck_assert_int_eq(output, OK);
  for (int r = 0; r < 4; r++)
    for (int c = 0; c < 3; c++) template.matrix[r][c] = 0;
  int status = s21_eq_matrix(&result, &template);
  ck_assert_int_eq(status, SUCCESS);
  s21_remove_matrix(&A), s21_remove_matrix(&result),
      s21_remove_matrix(&template);
}
END_TEST

START_TEST(mult_number_5) {
  matrix_t A = {}, result = {};
  s21_create_matrix(5, 5, &A);
  A.columns = 0;
  int output = s21_mult_number(&A, 5, &result);
  ck_assert_int_eq(output, Calculation_Error);
  A.columns = 5;
  s21_remove_matrix(&A), s21_remove_matrix(&result);
}
END_TEST

Suite *check_mult_number() {
  Suite *s;
  TCase *tc_1;
  s = suite_create("mult_number_test");
  tc_1 = tcase_create("tc_1");
  tcase_add_test(tc_1, mult_number_1);
  tcase_add_test(tc_1, mult_number_2);
  tcase_add_test(tc_1, mult_number_3);
  tcase_add_test(tc_1, mult_number_4);
  tcase_add_test(tc_1, mult_number_5);
  suite_add_tcase(s, tc_1);
  return s;
}
