#include "../src/matrixlib.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief reads matrix from file tests/data/3x3.csv and prints
 */
int main(void) {
    FILE* path = fopen("tests/data/test_3x3_1.csv", "r");
    matrix new_matrix = matrix_io_read_file(path);
    puts("");
    matrix_io_print(new_matrix);
    matrix_free(&new_matrix);
    return EXIT_SUCCESS;
}