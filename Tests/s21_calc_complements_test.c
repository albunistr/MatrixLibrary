#include "s21_testing.h"

START_TEST(calc_complements_1) {
  matrix_t A = {}, result = {};
  int output = s21_calc_complements(&A, &result);
  ck_assert_int_eq(output, Incorrect_Matrix);
  s21_remove_matrix(&A), s21_remove_matrix(&result);
}
END_TEST

START_TEST(calc_complements_2) {
  matrix_t A = {}, result = {};
  s21_create_matrix(0, 5, &A);
  int output = s21_calc_complements(&A, &result);
  ck_assert_int_eq(output, Incorrect_Matrix);
  s21_remove_matrix(&A), s21_remove_matrix(&result);
}
END_TEST

START_TEST(calc_complements_3) {
  matrix_t A = {}, result = {}, template = {};
  s21_create_matrix(4, 4, &A), s21_create_matrix(4, 4, &template);
  initialize(&A, 1.4);
  A.matrix[1][1] = A.matrix[2][2] = A.matrix[3][2] = 0;
  int output = s21_calc_complements(&A, &result);
  ck_assert_int_eq(output, OK);
  template.matrix[0][0] = -16.464, template.matrix[0][1] = 24.696,
  template.matrix[0][2] = 16.464, template.matrix[0][3] = -8.232;
  template.matrix[1][0] = 5.488, template.matrix[1][1] = -8.232,
  template.matrix[1][2] = 0, template.matrix[1][3] = 2.744;
  template.matrix[2][0] = 93.296, template.matrix[2][1] = -57.624,
  template.matrix[2][2] = -49.392, template.matrix[2][3] = 13.72;
  template.matrix[3][0] = -65.856, template.matrix[3][1] = 41.160,
  template.matrix[3][2] = 32.928, template.matrix[3][3] = -8.232;
  int status = s21_eq_matrix(&result, &template);
  ck_assert_int_eq(status, SUCCESS);
  s21_remove_matrix(&A), s21_remove_matrix(&result),
      s21_remove_matrix(&template);
}
END_TEST

START_TEST(calc_complements_4) {
  matrix_t A = {}, result = {}, template = {};
  s21_create_matrix(4, 4, &A), s21_create_matrix(4, 4, &template);
  initialize(&A, 0);
  int output = s21_calc_complements(&A, &result);
  ck_assert_int_eq(output, OK);
  for (int r = 0; r < 4; r++)
    for (int c = 0; c < 4; c++) template.matrix[r][c] = 0;
  int status = s21_eq_matrix(&result, &template);
  ck_assert_int_eq(status, SUCCESS);
  s21_remove_matrix(&A), s21_remove_matrix(&result),
      s21_remove_matrix(&template);
}
END_TEST

START_TEST(calc_complements_5) {
  matrix_t A = {}, result = {};
  s21_create_matrix(5, 4, &A);
  int output = s21_calc_complements(&A, &result);
  ck_assert_int_eq(output, Calculation_Error);
  s21_remove_matrix(&A), s21_remove_matrix(&result);
}
END_TEST

Suite *check_calc_complements() {
  Suite *s;
  TCase *tc_1;
  s = suite_create("calc_complements_test");
  tc_1 = tcase_create("tc_1");
  tcase_add_test(tc_1, calc_complements_1);
  tcase_add_test(tc_1, calc_complements_2);
  tcase_add_test(tc_1, calc_complements_3);
  tcase_add_test(tc_1, calc_complements_4);
  tcase_add_test(tc_1, calc_complements_5);
  suite_add_tcase(s, tc_1);
  return s;
}