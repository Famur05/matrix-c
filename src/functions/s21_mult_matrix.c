#include "../s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int flag = 0;
  if ((A->matrix != NULL) && (B->matrix != NULL)) {
    if (A->columns == B->rows) {
      flag = s21_create_matrix(A->rows, B->columns, result);
      for (int i = 0; i < A->rows && !flag; i++) {
        for (int j = 0; j < B->columns && !flag; j++) {
          for (int l = 0; l < A->columns && !flag; l++) {
            result->matrix[i][j] += A->matrix[i][l] * B->matrix[l][j];
          }
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