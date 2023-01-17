// ~~~~~~~~~~~~~~~~~~ //
//  matrixlib header  //
// ~~~~~~~~~~~~~~~~~~ //

#ifndef MATRIXLIB_H
#define MATRIXLIB_H

// stdlib headers
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//  matrix struct and common defines  //
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

// Max dimensions for matrices
#define MAX_DIMENSIONS      1000
// Double comparison precision
#define DECIMAL_PRECISION   0.00001
// Double print precision (%.*lf)
#define PRINT_PRECISION 2

typedef struct matrix
{
    double ** arr;
    unsigned int n; // Array row count
    unsigned int m; // Array column count
}matrix;

// ~~~~~~~~~~~~~~ //
//  io functions  //
// ~~~~~~~~~~~~~~ //

void matrix_io_print(const matrix matrixInput);

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//  constructors & deconstructors  //
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

matrix matrix_init_zero(unsigned int n, unsigned int m);
matrix matrix_init_identity(unsigned int n);
matrix matrix_init_console();
matrix matrix_copy(matrix a);
int matrix_free(matrix * a);

// ~~~~~~~~~~~~~~~~~~~~~ //
//  matrix manipulation  //
// ~~~~~~~~~~~~~~~~~~~~~ //

void matrix_edit_swap_columns(matrix * a, unsigned int columnA, unsigned int columnB);
void matrix_edit_swap_rows(matrix * a, unsigned int rowA, unsigned int rowB);
void matrix_edit_multiply_row(matrix * a, unsigned int row, double k);
void matrix_edit_multiply_column(matrix * a, unsigned int column, double k);
void matrix_edit_add_rows(matrix * a, unsigned int rowDestination, double k, unsigned int rowSource);
void matrix_edit_add_columns(matrix * a, unsigned int columnDestination, double k, unsigned int columnSource);

// ~~~~~~~~~~~~~~~~~~~ //
//  matrix arithmetic  //
// ~~~~~~~~~~~~~~~~~~~ //

matrix matrix_scalar_multiply(matrix a, double k);
matrix matrix_add(const matrix a, const matrix b);
bool matrix_compare(const matrix a, const matrix b);
matrix matrix_transpose(const matrix a);
matrix matrix_multiply(const matrix a, const matrix b);

#endif


