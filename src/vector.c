#include <vector.h>

inline bool vector_size_match(const vector * A, const vector * B)
{
    return (*A).size == (*B).size;
}
//----------------------------------------------------------------------------------------------------

void vector_fill(vector * input_vector,vtype val)
{
    for(int i = 0; i < (*input_vector).size; ++i)
        (*input_vector).arr[i] = val; 
}

void vector_normalize(vector * input_vector)
{
    vtype MAX = (*input_vector).arr[0];
    vtype curr;
    for(int i = 0; i < (*input_vector).size; ++i){
        curr = (*input_vector).arr[i];
        if (MAX < curr)
        {
            MAX = curr;
        }
    }
    scalar_multiplication(input_vector, 1/MAX);
}

void scalar_multiplication(vector * input_vector, vtype val)
{
    for(int i = 0; i < (*input_vector).size; ++i)
        (*input_vector).arr[i] *= val; 
}

void vectors_1_apply_operation(vector * input_vector, vtype(*operation)(vtype))
{
    for(int i = 0; i < (*input_vector).size; ++i)
    {
        (*input_vector).arr[i] = operation((*input_vector).arr[i]);
    }
}

//----------------------------------------------------------------------------------------------------

vector vector_create_empty(int size)
{
    vector return_vector;
    return_vector.size = size;
    return_vector.arr = malloc(size * sizeof(vtype));
    return return_vector;
}

vector vector_cpy(const vector * input_vector)
{
    vector return_vector;
    return_vector.size = (*input_vector).size;
    for(int i = 0; i < (*input_vector).size; ++i)
        return_vector.arr[i] =  return_vector.arr[i];
}

//----------------------------------------------------------------------------------------------------

vector vector_addition(const vector * A, const vector * B, bool * failed)
{
    vector return_vector;

    if (vector_size_match(A,B))
        *failed = 1; return return_vector;
    
    return_vector.arr = malloc((*A).size * sizeof(vtype));
    for(int i = 0; i < (*A).size; ++i)
    {
        return_vector.arr[i] = (*A).arr[i] + (*B).arr[i];
    }

    return return_vector;
}

vector vector_dot_product(const vector * A,const vector * B, bool * failed)
{
    vector return_vector;

    if (vector_size_match(A,B))
        *failed = 1; return return_vector;

    return_vector.arr = malloc((*A).size * sizeof(vtype));
    for(int i = 0; i < (*A).size; ++i)
    {
        return_vector.arr[i] = (*A).arr[i] * (*B).arr[i];
    }

    return return_vector;
}

void vectors_2_apply_operation(vector * A, vector * B, vtype(*operation)(vtype,vtype), bool * failed)
{
    vector return_vector;

    if ((*A).size != (*B).size)
        *failed = 1; return return_vector;

    return_vector.arr = malloc((*A).size * sizeof(vtype));
    for(int i = 0; i < (*A).size; ++i)
    {
        return_vector.arr[i] = operation((*A).arr[i],(*B).arr[i]);
    }
}
//----------------------------------------------------------------------------------------------------
