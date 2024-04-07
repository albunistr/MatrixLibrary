#include "../s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (A == NULL || B == NULL || result == NULL || A->matrix == NULL ||
      B->matrix == NULL) {
    return Incorrect_Matrix;
  }
  if (A->rows < 1 || A->columns < 1 || A->rows != B->rows ||
      A->columns != B->columns) {
    return Calculation_Error;
  }

  s21_create_matrix(A->rows, A->columns, result);

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
    }
  }

  return OK;
}
