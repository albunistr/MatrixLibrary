#ifndef S21_MATRIX_TESTS_H
#define S21_MATRIX_TESTS_H

#include <check.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#include "../s21_matrix.h"

Suite *check_create_matrix();
Suite *check_remove_matrix();
Suite *check_eq_matrix();
Suite *check_sum_matrix();
Suite *check_sub_matrix();
Suite *check_mult_number();
Suite *check_mult_matrix();
Suite *check_transpose();
Suite *check_determinant();
Suite *check_calc_complements();
Suite *check_inverse_matrix();

#endif
