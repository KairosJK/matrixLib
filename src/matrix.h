/*

    Matrix Struct and Common Macros

*/

#define MAX_DIMENSIONS      1000
#define DECIMAL_PRECISION   0.00001

typedef double element;
typedef unsigned int uint;

typedef struct matrix
{
    element ** arr;
    uint n; // Array row count
    uint m; // Array column count
}matrix;