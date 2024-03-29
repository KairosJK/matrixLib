#include "../src/matrixlib.h"
#include <stdio.h>

/**
 * @brief initializes 3*6 zeroed matrix and prints
 */
int main(void) {
    matrix new_matrix = matrix_init_zero(3, 6);
    puts("");
    matrix_io_print(new_matrix);
    matrix_free(&new_matrix);
    return EXIT_SUCCESS;
}