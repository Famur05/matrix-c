#include "../s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int flag = 0;
  if (A->matrix != NULL) {
    if (!(isinf(number) || isnan(number))) {
      flag = s21_create_matrix(A->rows, A->columns, result);
      for (int i = 0; i < A->rows && !flag; i++) {
        for (int j = 0; j < A->columns && !flag; j++) {
          result->matrix[i][j] = A->matrix[i][j] * number;
        }
      }
    } else {
      flag = 2;
    }
  } else {
    flag = 1;
  }
  return flag;
}