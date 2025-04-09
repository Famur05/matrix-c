#include "../s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int flag = 0;
  if ((A->matrix != NULL) && (B->matrix != NULL)) {
    if ((A->rows == B->rows) && (A->columns == B->columns)) {
      flag = s21_create_matrix(A->rows, A->columns, result);
      for (int i = 0; i < A->rows && !flag; i++) {
        for (int j = 0; j < A->columns && !flag; j++) {
          result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
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