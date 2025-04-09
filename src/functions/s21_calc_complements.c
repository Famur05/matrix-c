#include "../s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int flag = 0;
  if (A->matrix != NULL) {
    if (A->rows == A->columns) {
      matrix_t new_matrix;
      if (A->rows > 1) {
        flag = s21_create_matrix((A->rows) - 1, (A->columns) - 1, &new_matrix);
      } else {
        flag = s21_create_matrix((A->rows), (A->columns), &new_matrix);
      }
      if (!flag) {
        double res_det = 0;
        flag = s21_create_matrix((A->rows), (A->columns), result);
        for (int i = 0; i < A->rows && !flag; i++) {
          for (int j = 0; j < A->columns && !flag; j++) {
            if (A->rows == 1) {
              new_matrix.matrix[0][0] = A->matrix[0][0];
            } else {
              int m_for_new_matrix = 0, n_for_new_matrix = 0;
              for (int m = 0; m < A->rows; m++) {
                for (int n = 0; n < A->columns; n++) {
                  if (m != i && n != j) {
                    new_matrix.matrix[m_for_new_matrix][n_for_new_matrix] =
                        A->matrix[m][n];
                    n_for_new_matrix++;
                  }
                }
                if (m != i) {
                  m_for_new_matrix++;
                  n_for_new_matrix = 0;
                }
              }
            }
            flag = s21_determinant(&new_matrix, &res_det);
            result->matrix[i][j] = pow(-1, i + j) * res_det;
          }
        }
      }
      s21_remove_matrix(&new_matrix);
    } else {
      flag = 2;
    }
  } else {
    flag = 1;
  }
  return flag;
}
