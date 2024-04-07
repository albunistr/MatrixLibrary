#include "../s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (A == NULL || B == NULL || result == NULL || A->matrix == NULL ||
      B->matrix == NULL) {
    return Incorrect_Matrix;
  }
  if (A->rows < 1 || A->columns < 1 || B->columns < 1 || A->columns != B->rows)
    return Calculation_Error;

  s21_create_matrix(A->rows, B->columns, result);
  for (int i = 0, i1 = 0; i < A->rows; i++, i1++) {
    for (int j = 0, j1 = 0; j < B->columns; j++, j1++) {
      for (int k = 0, k1 = 0; k < A->columns; k++, k1++) {
        result->matrix[i][j] += A->matrix[i1][k1] * B->matrix[k][j];
      }
    }
  }

  return OK;
}