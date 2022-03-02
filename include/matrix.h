#include <stdlib.h>
#include <stdbool.h> 

// typedef of data type used in matrix
typedef float vtype;

// key structure and typedef
struct Matrix;
typedef struct Matrix matrix; 

// get number of elements
inline int matrix_size(const matrix * input_matrix);
inline bool matrix_size_match(const matrix * A, const matrix * B);

// access elements
inline vtype * matrix_at(matrix * input_matrix, int i, int j);
vtype ** matrix_column(matrix input_matrix, int column);
vtype ** matrix_row(matrix input_matrix, int row_number);

// check property
bool is_matrix_zero(const matrix * input_matrix);
bool is_matrix_identity(const matrix * input_matrix);
inline bool is_matrix_square(const matrix * input_matrix);
inline bool is_matrix_rect(const matrix * input_matrix);

// basic operations on one matrix
void matrix_transpose(matrix * input_matrix);
void matrix_fill(matrix * input_matrix, vtype val);
void matrix_scalar_mult(matrix * input_matrix, vtype val);
void matrix_normalize(matrix * input_matrix);

// memory
matrix matrix_create_empty(int M, int N);
matrix matrix_create_empty_from(const matrix * input_matrix);
matrix matrix_cpy(const matrix * input_matrix);

// operations on two matrices
matrix matrix_addition(matrix A, matrix B, bool* failed);
matrix matrix_multiplication(matrix A, matrix B, bool* failed);
matrix matrix_aply_operation(matrix A, matrix B, vtype(*operation)(vtype, vtype), bool* failed);

