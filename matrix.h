#include <stdlib.h>
#include <stdbool.h> 
typedef float vtype;
typedef struct Matrix matrix; 

struct Matrix;
inline vtype * matrix_at(const matrix input_matrix, int i, int j);
vtype * matrix_column(matrix input_matrix, int column);
vtype * matrix_row(matrix input_matrix, int row_number);
void matrix_transpose(matrix input_matrix);
void matrix_fill(matrix input_matrix, vtype val);
void matrix_scalar_mult(matrix input_matrix, vtype val);
void matrix_normalize(matrix input_matrix);
matrix matrix_create_empty(int M, int N);
matrix matrix_addition(matrix A, matrix B, bool* failed);
matrix matrix_multiplication(matrix A, matrix B, bool* failed);