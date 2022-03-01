#include <stdlib.h>
#include <stdbool.h> 

#define MAX_VSIZE 100
typedef float vtype;

struct Vector;
typedef struct Vector vector;

void vec_fill(vector * input_vector,vtype val);
void vector_normalize(vector * input_vector);
void scalar_multiplication(vector * input_vector, vtype val);
vector vector_create_empty(int size);
vector vector_cpy(const vector * input_vector);
vector vector_addition(const vector A,const vector B, bool* failed);
vector dot_product(const vector A,const vector B, bool* failed);
