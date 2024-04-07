#include "../s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  if (A == NULL || A->matrix == NULL) {
    return Incorrect_Matrix;
  }
  if (A->rows < 1 || A->rows != A->columns) {
    return Calculation_Error;
  }
  *result = 0;
  determinant_help(A, result);
  return OK;
}
