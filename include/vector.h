#include <common.h>

typedef VEC_TYPE vtype;

// key structure and typedef
struct _vector
{
    int size;
    vtype * arr;
};
typedef struct _vector vector;

// basic operations on one vector
void vector_fill(vector * input_vector,vtype val);
void vector_normalize(vector * input_vector);
void vector_scalar_multiplication(vector * input_vector, vtype val);
void vectors_1_apply_operation(vector * input_vector, vtype(*operation)(vtype));

// memory
vector vector_create_empty(int size);
vector vector_cpy(const vector * input_vector);

// operations on two vectors
vector vector_addition(const vector A,const vector B, bool* failed);
vector vector_dot_product(const vector A,const vector B, bool* failed);
void vectors_2_apply_operation(vector * input_vector, vtype(*operation)(vtype,vtype), bool * failed);
