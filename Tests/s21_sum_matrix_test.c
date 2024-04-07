#include "s21_testing.h"

START_TEST(sum_matrix_1) {
  matrix_t A = {}, B = {}, result = {};
  s21_create_matrix(4, 3, &A), s21_create_matrix(5, 3, &B);
  int output = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(output, Calculation_Error);
  s21_remove_matrix(&A), s21_remove_matrix(&B), s21_remove_matrix(&result);
}
END_TEST

START_TEST(sum_matrix_2) {
  matrix_t A = {}, B = {}, result = {};
  s21_create_matrix(5, 5, &A);
  int output = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(output, Incorrect_Matrix);
  s21_remove_matrix(&A), s21_remove_matrix(&B), s21_remove_matrix(&result);
}
END_TEST

START_TEST(sum_matrix_3) {
  matrix_t A = {}, B = {}, result = {};
  s21_create_matrix(4, 4, &A), s21_create_matrix(4, 3, &B);
  int output = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(output, Calculation_Error);
  s21_remove_matrix(&A), s21_remove_matrix(&B), s21_remove_matrix(&result);
}
END_TEST

START_TEST(sum_matrix_4) {
  matrix_t A = {}, B = {}, result = {}, template = {};
  s21_create_matrix(4, 3, &A), s21_create_matrix(4, 3, &B),
      s21_create_matrix(4, 3, &template);
  initialize(&A, 1.4), initialize(&B, 2.05);
  int output = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(output, OK);
  template.matrix[0][0] = template.matrix[0][1] = template.matrix[0][2] =
      template.matrix[1][0] = template.matrix[2][0] = template.matrix[3][0] =
          3.45;
  template.matrix[1][1] = 6.9, template.matrix[1][2] = 10.35;
  template.matrix[2][1] = 10.35, template.matrix[2][2] = 17.25,
  template.matrix[3][1] = 13.8, template.matrix[3][2] = 24.15;
  int status = s21_eq_matrix(&result, &template);
  ck_assert_int_eq(status, SUCCESS);
  s21_remove_matrix(&A), s21_remove_matrix(&B), s21_remove_matrix(&result),
      s21_remove_matrix(&template);
}
END_TEST

START_TEST(sum_matrix_5) {
  matrix_t A = {}, B = {}, result = {}, template = {};
  s21_create_matrix(4, 3, &A), s21_create_matrix(4, 3, &B),
      s21_create_matrix(4, 3, &template);
  initialize(&A, 1.4), initialize(&B, 0);
  int output = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(output, OK);
  template.matrix[0][0] = template.matrix[0][1] = template.matrix[0][2] =
      template.matrix[1][0] = template.matrix[2][0] = template.matrix[3][0] =
          1.4;
  template.matrix[1][1] = 2.8, template.matrix[1][2] = 4.2;
  template.matrix[2][1] = 4.2, template.matrix[2][2] = 7,
  template.matrix[3][1] = 5.6, template.matrix[3][2] = 9.8;
  int status = s21_eq_matrix(&result, &template);
  ck_assert_int_eq(status, SUCCESS);
  s21_remove_matrix(&A), s21_remove_matrix(&B), s21_remove_matrix(&result),
      s21_remove_matrix(&template);
}
END_TEST

START_TEST(sum_matrix_6) {
  matrix_t A = {}, B = {}, result = {};
  s21_create_matrix(4, 0, &A), s21_create_matrix(4, 3, &B);
  int output = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(output, Incorrect_Matrix);
  s21_remove_matrix(&A), s21_remove_matrix(&B), s21_remove_matrix(&result);
}
END_TEST

Suite *check_sum_matrix() {
  Suite *s;
  TCase *tc_1;
  s = suite_create("sum_matrix_test");
  tc_1 = tcase_create("tc_1");
  tcase_add_test(tc_1, sum_matrix_1);
  tcase_add_test(tc_1, sum_matrix_2);
  tcase_add_test(tc_1, sum_matrix_3);
  tcase_add_test(tc_1, sum_matrix_4);
  tcase_add_test(tc_1, sum_matrix_5);
  tcase_add_test(tc_1, sum_matrix_6);
  suite_add_tcase(s, tc_1);
  return s;
}