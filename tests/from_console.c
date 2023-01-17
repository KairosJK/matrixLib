#include "../src/matrixlib.h"
#include <stdio.h>

int main(void) {
    matrix new_matrix = matrix_init_console();
    puts("");
    matrix_io_print(new_matrix);
    matrix_free(&new_matrix);
    return EXIT_SUCCESS;
}