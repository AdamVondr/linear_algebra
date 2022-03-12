#include <vector.h>

void vector_print(const vector * input_vector)
{
    char char_buffer; 
    for (int i = 0; i < (*input_vector).size; i++)
    {
        type_print((*input_vector).arr[i]);
    }
    print_end;
}
