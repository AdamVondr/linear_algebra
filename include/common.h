#define _DEFAULT_VALUE_TYPE float

#ifndef VALUE_TYPE
// set all types to _DEFAULT_VALUE_TYPE
#define VALUE_TYPE _DEFAULT_VALUE_TYPE
#define VEC_TYPE _DEFAULT_VALUE_TYPE
#define MAT_TYPE _DEFAULT_VALUE_TYPE

// define display methods
#define type_print(x) printf("%f",x)
#define print_end printf("/n");
#endif

#ifndef VEC_TYPE
#define VEC_TYPE _DEFAULT_VALUE_TYPE
#endif

#ifndef MAT_TYPE
#define MAT_TYPE _DEFAULT_VALUE_TYPE
#endif

#ifndef type_print(x)
#define type_print(x) 0
#endif

// commond includes
#include <stdlib.h>
#include <stdbool.h> 

// definition of basic 4 operations
#define addition(x,y) (x + y)
#define substraction(x,y) (x - y)
#define multiplication(x,y) (x*y)
#define division(x,y) (x/y)

// definition of basic 4 modular operations
#define modular_addition (x,y,m) (addition(x,y) % m)
#define modular_substraction (x,y,m) (substraction(x,y) % m)
#define modular_multiplication (x,y,m) (multiplication(x,y) % m)
#define modular_division (x,y,m) (division(x,y) % m)