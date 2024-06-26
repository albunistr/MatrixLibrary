#ifndef C6_S21_MATRIX_1
#define C6_S21_MATRIX_1

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define SUCCESS 1
#define FAILURE 0

#define OK 0
#define Incorrect_Matrix 1
#define Calculation_Error 2

typedef struct matrix_struct {
    double** matrix;
    int rows;
    int columns;
} matrix_t;

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

//help functions
void initialize(matrix_t *A, double start);
void determinant_help(matrix_t *A, double *result);
int s21_minor (matrix_t A, int row, int col, matrix_t *res);

#endif