#include <stdlib.h>
#include <stdbool.h> 

typedef float vtype;

// key structure and typedef
struct _vector
{
    int size;
    vtype * arr;
};
typedef struct _vector vector;

// basic operations on one vector
void vec_fill(vector * input_vector,vtype val);
void vector_normalize(vector * input_vector);
void scalar_multiplication(vector * input_vector, vtype val);

// memory
vector vector_create_empty(int size);
vector vector_cpy(const vector * input_vector);

// operations on two vectors
vector vector_addition(const vector A,const vector B, bool* failed);
vector dot_product(const vector A,const vector B, bool* failed);
