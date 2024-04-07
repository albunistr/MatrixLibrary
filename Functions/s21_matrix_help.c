#include "../s21_matrix.h"

void initialize(matrix_t *A, double start) {
  if (A && A->matrix)
    for (int r = 0; r < A->rows; r++)
      for (int c = 0; c < A->columns; c++)
        A->matrix[r][c] = start * r * c + start;
  start += 1.1;
}

void determinant_help(matrix_t *A, double *result) {
  if (A->rows == 1) {
    *result = A->matrix[0][0];
  } else if (A->rows == 2) {
    *result += ((A->matrix[0][0] * A->matrix[1][1] -
                 A->matrix[0][1] * A->matrix[1][0]));
  } else {
    matrix_t mtrx = {};
    for (int i = 0; i < A->columns; i++) {
      s21_remove_matrix(&mtrx);
      s21_minor(*A, 0, i, &mtrx);

      double t_d = 0;
      s21_determinant(&mtrx, &t_d);
      *result = *result + A->matrix[0][i] * (pow(-1, i) * t_d);
    }
    s21_remove_matrix(&mtrx);
  }
}

int s21_minor(matrix_t A, int row, int col, matrix_t *res) {
  int result = OK;

  s21_create_matrix(A.rows - 1, A.columns - 1, res);
  for (int i = 0, r = 0; i < A.rows; i++) {
    if (i == row) continue;
    for (int j = 0, c = 0; j < A.columns; j++) {
      if (j == col) continue;
      res->matrix[r][c] = A.matrix[i][j];
      c++;
    }
    r++;
  }
  return result;
}