#include "../src/matrixlib.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief reads 2 matrices from file and performs basic arithmetic on them
 */
int main(void) {
    matrix a = matrix_io_read_file(fopen("tests/data/test_3x3_1.csv", "r"));
    matrix b = matrix_io_read_file(fopen("tests/data/test_3x3_2.csv", "r"));
    puts("\na =");
    matrix_io_print(a);
    puts("\nb =");
    matrix_io_print(b);

    // addition
    puts("\naddition:\n\na+b =");
    matrix a_plus_b = matrix_add(a, b);
    matrix_io_print(a_plus_b);

    // transpose
    puts("\ntranspose:\n\na =");
    matrix transpose_a = matrix_transpose(a);
    matrix_io_print(transpose_a);
    puts("\nb =");
    matrix transpose_b = matrix_transpose(b);
    matrix_io_print(transpose_b);

    // multiply
    puts("\nmultiply:\n\na*b =");
    matrix a_times_b = matrix_multiply(a, b);
    matrix_io_print(a_times_b);

    matrix_free(&a_times_b);
    matrix_free(&transpose_a);
    matrix_free(&transpose_b);
    matrix_free(&a_plus_b);
    matrix_free(&a);
    matrix_free(&b);
    return EXIT_SUCCESS;
}