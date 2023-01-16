/*

    Matrix Library Binder
        All libraries binded for simpler include

*/

#ifndef MATRIXLIB_H
#define MATRIXLIB_H

// stdlib headers
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

/*

    Matrix Struct and Common Macros

*/

#define MAX_DIMENSIONS      1000
#define DECIMAL_PRECISION   0.00001
#define PRINT_PRECISION 2

typedef double element;

typedef struct matrix
{
    element ** arr;
    unsigned int n; // Array row count
    unsigned int m; // Array column count
}matrix;

// ~~~~~~~~~~~~~~ //
//  io functions  //
// ~~~~~~~~~~~~~~ //
void matrix_io_printToConsole(const matrix matrixInput);

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//  constructors & deconstructors  //
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
matrix matrix_init_zero(uint n, uint m);
matrix matrix_init_identityMatrix(uint n);
matrix matrix_init_FromConsole();
matrix matrix_copy(matrix a);
int matrix_free(matrix * a);

// ~~~~~~~~~~~~~~~~~~~~~ //
//  matrix manipulation  //
// ~~~~~~~~~~~~~~~~~~~~~ //
void matrix_edit_swapColumns(matrix * a, uint columnA, uint columnB);
void matrix_edit_swapRows(matrix * a, uint rowA, uint rowB);
void matrix_edit_multiplyRow(matrix * a, uint row, element k);
void matrix_edit_multiplyColumn(matrix * a, uint column, element k);
void matrix_edit_addRows(matrix * a, uint rowDestination, element k, uint rowSource);
void matrix_edit_addColumns(matrix * a, uint columnDestination, element k, uint columnSource);

// ~~~~~~~~~~~~~~~~~~~ //
//  matrix arithmetic  //
// ~~~~~~~~~~~~~~~~~~~ //
matrix matrix_scalar_multiply(matrix a, element k);
matrix matrix_add(const matrix a, const matrix b);
bool matrix_compare(const matrix a, const matrix b);
matrix matrix_transpose(const matrix a);
matrix matrix_multiply(const matrix a, const matrix b);

#endif


