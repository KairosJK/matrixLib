#include "../src/matrixlib.h"
#include <stdio.h>

/**
 * @brief initializes 3x3 identity matrix and prints
 */
int main(void) {
    matrix new_matrix = matrix_init_identity(3);
    puts("");
    matrix_io_print(new_matrix);
    matrix_free(&new_matrix);
    return EXIT_SUCCESS;
}