#include "../s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  if (A == NULL || B == NULL || A->matrix == NULL || B->matrix == NULL ||
      A->rows != B->rows || A->columns != B->columns) {
    return FAILURE;
  }

  int eq_res = SUCCESS;
  for (int i = 0; i < A->rows && eq_res == SUCCESS; i++) {
    for (int j = 0; j < A->columns && eq_res == SUCCESS; j++) {
      double a = fabs(A->matrix[i][j]);
      double b = fabs(B->matrix[i][j]);
      if (fabs(a - b) > 0.000001) {
        eq_res = FAILURE;
      }
    }
  }
  return eq_res;
}