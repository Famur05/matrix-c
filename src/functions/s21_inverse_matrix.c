#include "../s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int flag = 0;
  double res_det = 0;
  if (A->matrix != NULL) {
    if (A->rows == A->columns) {
      flag = s21_determinant(A, &res_det);
      if (!flag) {
        if (res_det) {
          matrix_t new_matrix;
          flag = s21_calc_complements(A, &new_matrix);
          if (!flag) {
            matrix_t new_matrix_tr;
            flag = s21_transpose(&new_matrix, &new_matrix_tr);
            if (!flag) {
              flag = s21_mult_number(&new_matrix_tr, (1 / res_det), result);
            }
            s21_remove_matrix(&new_matrix_tr);
          }
          s21_remove_matrix(&new_matrix);
        } else {
          flag = 2;
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
