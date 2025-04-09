#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int flag = 0;
  if (rows <= 0 || columns <= 0) {
    flag = 1;
  } else {
    result->matrix = calloc(rows, sizeof(double *));
    if (result->matrix != NULL) {
      for (int i = 0; i < rows && !flag; i++) {
        result->matrix[i] = calloc(columns, sizeof(double));
        if (result->matrix[i] == NULL) {
          flag = 1;
        }
      }
    } else {
      flag = 1;
    }
    if (!flag) {
      result->rows = rows;
      result->columns = columns;
    }
  }
  return flag;
}