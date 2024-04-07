#include "../s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (A == NULL || A->matrix == NULL || result == NULL) {
    return Incorrect_Matrix;
  }
  if (A->rows < 1 || A->rows != A->columns) {
    return Calculation_Error;
  }

  int inverse_res = OK;
  double deter = 0;
  s21_determinant(A, &deter);
  if (deter == 0)
    inverse_res = Calculation_Error;
  else {
    matrix_t tempor = {};
    matrix_t transp = {};
    s21_calc_complements(A, &tempor);
    s21_transpose(&tempor, &transp);
    s21_mult_number(&transp, 1 / deter, result);
    s21_remove_matrix(&tempor);
    s21_remove_matrix(&transp);
  }
  return inverse_res;
}