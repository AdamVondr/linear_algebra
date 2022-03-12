#define VALUE_TYPE float
#include <vectorio.h>

int main()
{
    int t_size = 20;
    vector test_vector = vector_create_empty(t_size); // random bytes
    vec_fill(&test_vector, (vtype)1); // ones
    vector_print(&test_vector);
    scalar_multiplication(&test_vector, (vtype)2); // twos
    vector_print(&test_vector);
    vector test_vector2 = vector_cpy(&test_vector); // twos
    vector_print(&test_vector2);
    
    return 0;
}