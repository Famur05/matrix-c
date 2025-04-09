#include "../s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int flag = 0;
  if (A->matrix != NULL) {
    if (A->rows == A->columns) {
      if (*result != 0) *result = 0;
      if (A->rows == 1) {
        *result = A->matrix[0][0];
      } else if (A->rows == 2) {
        *result = A->matrix[0][0] * A->matrix[1][1] -
                  A->matrix[0][1] * A->matrix[1][0];
      }
      // матрицы >= 3
      else {
        matrix_t new_matrix;
        double res_det = 0;
        flag = s21_create_matrix((A->rows) - 1, (A->columns) - 1, &new_matrix);

        for (int i = 0; i < A->columns && !flag; i++) {
          int m_for_new_matrix = 0, n_for_new_matrix = 0;
          for (int m = 0; m < A->rows; m++) {
            for (int n = 0; n < A->columns; n++) {
              if (m != 0 && n != i) {
                new_matrix.matrix[m_for_new_matrix][n_for_new_matrix] =
                    A->matrix[m][n];
                n_for_new_matrix++;
              }
            }
            if (m != 0) {
              m_for_new_matrix++;
              n_for_new_matrix = 0;
            }
          }
          flag = s21_determinant(&new_matrix, &res_det);
          *result += pow(-1, i) * A->matrix[0][i] * res_det;
        }
        s21_remove_matrix(&new_matrix);
      }
    } else {
      flag = 2;
    }
  } else {
    flag = 1;
  }
  return flag;
}