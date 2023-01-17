#include "../src/matrixlib.h"
#include <stdio.h>

/**
 * @brief reads matrix from console input and prints
 */
int main(void) {
    matrix new_matrix = matrix_io_read_console();
    puts("");
    matrix_io_print(new_matrix);
    matrix_free(&new_matrix);
    return EXIT_SUCCESS;
}