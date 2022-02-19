#include <vector.h>

struct Vector
{
    int size;
    vtype * arr;
};

void vec_fill(vector input_vector,vtype val)
{
    for(int i = 0; i < input_vector.size; ++i)
        input_vector.arr[i] = val; 
}

void vector_normalize(vector input_vector)
{
    vtype MAX = input_vector.arr[0];
    vtype curr;
    for(int i = 0; i < input_vector.size; ++i){
        curr = input_vector.arr[i];
        if (MAX < curr)
        {
            MAX = curr;
        }
    }
    scalar_multiplication(input_vector, 1/MAX);
}

void scalar_multiplication(vector input_vector, vtype val)
{
    for(int i = 0; i < input_vector.size; ++i)
        input_vector.arr[i] *= val; 
}

vector vector_create_empty(int size)
{
    vector return_vector;
    return_vector.size = size;
    return_vector.arr = malloc(size * sizeof(vtype));
    return return_vector;
}

vector vector_cpy(vector input_vector)
{
    vector return_vector;
    return_vector.size = input_vector.size;
    for(int i = 0; i < input_vector.size; ++i)
        return_vector.arr[i] =  return_vector.arr[i];
}

vector vector_addition(const vector A,const vector B, bool * failed)
{
    vector return_vector;

    if (A.size != B.size)
        failed = 1; return return_vector;
    
    return_vector.arr = malloc(A.size * sizeof(vector));
    for(int i = 0; i < A.size; ++i)
    {
        return_vector.arr[i] = A.arr[i] + A.arr[i];
    }

    return return_vector;
}

vector dot_product(const vector A,const vector B, bool * failed)
{
    vector return_vector;

    if (A.size != B.size)
        failed = 1; return return_vector;

    return_vector.arr = malloc(A.size * sizeof(vector));
    for(int i = 0; i < A.size; ++i)
    {
        return_vector.arr[i] = A.arr[i] * A.arr[i];
    }

    return return_vector;
}

