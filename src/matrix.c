#include <matrix.h>

struct Matrix
{
    // M - column len
    // N - row len
    int M,N;
    vtype * arr;
};

inline vtype * matrix_at(matrix * input_matrix, int i, int j)
{
    return &(*input_matrix).arr[i* (*input_matrix).N + j];
}

vtype ** matrix_column(matrix input_matrix, int column)
{
    vtype ** return_arr = malloc(input_matrix.M * sizeof(vtype*));
    for (int i = 0; i < input_matrix.M; ++i) // for row
    {
        return_arr[i] = &input_matrix.arr[i*input_matrix.N + column];
    }
    return return_arr;
}

vtype ** matrix_row(matrix input_matrix, int row_number)
{
    vtype ** return_arr = malloc(input_matrix.N * sizeof(vtype*));
    for (int i = 0; i < input_matrix.N; ++i) //for column
    {
        return_arr[i] = &input_matrix.arr[i*input_matrix.M + row_number];
    }
    return return_arr;
}

void matrix_transpose(matrix * input_matrix)
{
    // i represents row number
    // j represents column number
    vtype temp;
    int M = (*input_matrix).M, N = (*input_matrix).N;
    for(int i = 0; i < M; ++i) //column iter
    {
        for(int j = 0; j < N; ++j) //row iter
        {
            temp = (*input_matrix).arr[ i*N + j ];
            (*input_matrix).arr[ i*N + j ] = (*input_matrix).arr[ j*M + i ];
            (*input_matrix).arr[ j*M + i ] = temp;
        }
    }
}

void matrix_fill(matrix *input_matrix, vtype val)
{
    for(int i; i < matrix_size(input_matrix); ++i)
        (*input_matrix).arr[i] = val;
}

void matrix_scalar_mult(matrix * input_matrix, vtype val)
{
    for(int i; i < matrix_size(input_matrix); ++i)
        (*input_matrix).arr[i] *= val;
}

void matrix_normalize(matrix * input_matrix)
{
    vtype MAX;
    for (int i = 0; i < matrix_size(input_matrix); i++)
    {
        if (MAX < (*input_matrix).arr[i])
            MAX = (*input_matrix).arr[i];
    }
    matrix_scalar_mult(input_matrix, 1/MAX);
}

matrix matrix_create_empty(int M, int N)
{
    matrix return_matrix;
    return_matrix.M = M;
    return_matrix.N = N;
    return_matrix.arr = malloc(M*N*sizeof(vtype));
    return return_matrix;
}

matrix matrix_create_empty_from(const matrix * input_matrix)
{
    return matrix_create_empty((*input_matrix).M, (*input_matrix).N);
}

matrix matrix_cpy(const matrix * input_matrix)
{
    matrix return_matrix = matrix_create_empty_from(input_matrix);
    for(int i; i < matrix_size(input_matrix); ++i)
    {
        return_matrix.arr[i] = (*input_matrix).arr[i]; 
    }
    return return_matrix;
}

matrix matrix_addition(matrix * A, matrix * B, bool* failed)
{
    matrix return_matrix;
    
    // check if sizes match
    if (!matrix_size_match(A, B))
        *failed = true; return return_matrix;

    // create empty matrix
    return_matrix = matrix_create_empty_from(A);

    // assign value to return_matrix
    for (int i = 0; i < matrix_size(A); i++)
    {
        return_matrix.arr[i] = (*A).arr[i] + (*B).arr[i];
    }
    
    return return_matrix;
}

matrix matrix_multiplication(matrix * A, matrix * B, bool* failed)
{
    matrix return_matrix;
    
    // size check
    if ((*A).N != (*B).M)
        *failed = true; return return_matrix;

    // create empty matrix
    return_matrix = matrix_create_empty((*A).M, (*B).N);
    
    vtype partial_sum;

    for (int i = 0; i < (*A).M; i++)
    {
        for (int j = 0; j < (*A).N; j++)
        {
            partial_sum = 0;
            for (int k = 0; k < (*A).N; k++)
            {
                partial_sum += *matrix_at(A, i, k) + *matrix_at(A, k, j);
            }
            *matrix_at(&return_matrix, i , j) = partial_sum;  
        }
        
    }
}

matrix matrix_aply_operation(matrix * A, matrix * B, vtype(*operation)(vtype, vtype), bool* failed)
{
    matrix return_matrix;

    // check if sizes match
    if(!matrix_size_match(A,B))
        *failed = true; return return_matrix;

    // create empty matrix
    return_matrix = matrix_create_empty_from(A);

    // assign value to return_matrix
    for (int i = 0; i < matrix_size(A); i++)
    {
        return_matrix.arr[i] = operation((*A).arr[i], (*A).arr[i]);
    }
    
    return return_matrix;
}

bool is_matrix_zero(matrix input_matrix)
{
    int size = input_matrix.M * input_matrix.N;
    int i = 0; 
    while ((i < size) && (input_matrix.arr[i] == 0))
        i++;

    return (i == size);
}

bool is_matrix_identity(const matrix * input_matrix)
{
    // is matrix square
    if(is_matrix_square(input_matrix))
        return 0;
    
    vtype element;
    for(int i = 0 ; i < (*input_matrix).M; ++i)
    {
        for(int j = 0 ; j < (*input_matrix).N; ++j)
        {
            element = *matrix_at(input_matrix,i,j);
            if (i == j && element != 1)
                return false;
            else if (i != j && element != 0)
                return false;
        }
    }
    return true;
}

inline bool is_matrix_square(const matrix * input_matrix)
{
    return ((*input_matrix).M == (*input_matrix).N);
}

inline bool is_matrix_rect(const matrix * input_matrix)
{
    return ((*input_matrix).M != (*input_matrix).N);
}

inline bool matrix_size_match(const matrix * A, const matrix * B)
{
    return ((*A).M == (*B).M) && ((*A).N == (*B).N);
}

inline int matrix_size(const matrix * input_matrix)
{
    return (*input_matrix).M*(*input_matrix).N;
}
