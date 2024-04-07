#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  if (result == NULL || rows < 1 || columns < 1) return Incorrect_Matrix;
  result->rows = rows;
  result->columns = columns;
  result->matrix = (double **)calloc(rows, sizeof(double *));
  for (int r = 0; r < rows && result->matrix; r++) {
    result->matrix[r] = (double *)calloc(columns, sizeof(double));
  }
  return OK;
}
