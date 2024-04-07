#include "../s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  if (A == NULL || result == NULL || A->matrix == NULL) {
    return Incorrect_Matrix;
  }
  if (A->rows < 1 || A->columns < 1 || A->rows != A->columns) {
    return Calculation_Error;
  }
  s21_create_matrix(A->rows, A->columns, result);
  matrix_t mtrx;
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      s21_minor(*A, i, j, &mtrx);
      double deter = 0;
      s21_determinant(&mtrx, &deter);
      result->matrix[i][j] = deter * pow(-1, i + j);
      s21_remove_matrix(&mtrx);
    }
  }

  return OK;
}