#include "s21_testing.h"

START_TEST(eq_matrix_1) {
  matrix_t A = {}, B = {};
  s21_create_matrix(4, 3, &A), s21_create_matrix(5, 3, &B);
  int status = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(status, FAILURE);
  s21_remove_matrix(&A), s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_2) {
  matrix_t A = {}, B = {};
  initialize(&A, 6.0);
  initialize(&B, 7.0);
  int status = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(status, FAILURE);
  s21_remove_matrix(&A), s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_3) {
  matrix_t A = {}, B = {};
  s21_create_matrix(4, 3, &A), s21_create_matrix(4, 3, &B);
  int status = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(status, SUCCESS);
  s21_remove_matrix(&A), s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_4) {
  matrix_t A = {}, B = {};
  s21_create_matrix(4, 3, &A), s21_create_matrix(4, 3, &B);
  initialize(&A, 1.4), initialize(&B, 1.4);
  int status = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(status, SUCCESS);
  s21_remove_matrix(&A), s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_5) {
  matrix_t A = {}, B = {};
  s21_create_matrix(4, 3, &A), s21_create_matrix(4, 3, &B);
  initialize(&A, 1.4), initialize(&B, 1.3);
  int status = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(status, FAILURE);
  s21_remove_matrix(&A), s21_remove_matrix(&B);
}
END_TEST

Suite *check_eq_matrix() {
  Suite *s;
  TCase *tc_1;
  s = suite_create("eq_matrix_test");
  tc_1 = tcase_create("tc_1");
  tcase_add_test(tc_1, eq_matrix_1);
  tcase_add_test(tc_1, eq_matrix_2);
  tcase_add_test(tc_1, eq_matrix_3);
  tcase_add_test(tc_1, eq_matrix_4);
  tcase_add_test(tc_1, eq_matrix_5);
  suite_add_tcase(s, tc_1);
  return s;
}