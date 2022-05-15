#include "../src/matrixlib.h"

int main(void)
{
    printf("\n--\n");
    matrix nulltwo = matrix_init_zero(2 , 2);
    matrix identitytwo = matrix_init_identityMatrix(2);
    //matrix userIn = matrix_init_FromConsole();
    //matrix addition = matrix_add(matrix_init_identityMatrix(2), userIn);
    matrix multiply = matrix_scalar_multiply(matrix_init_identityMatrix(3), 0.5);
    //matrix transpose = matrix_transpose(userIn);
    matrix a = matrix_init_FromConsole();
    //matrix b = matrix_init_FromConsole();
    //matrix multiplyMatricies = matrix_multiply(a, b);
    
    matrix_io_printToConsole(nulltwo);
    printf("\n--\n");

    matrix_io_printToConsole(identitytwo);
    printf("\n--\n");

    //matrix_io_printToConsole(userIn);
    //printf("\n--\n");

    //matrix_io_printToConsole(addition);
    printf("\n--\n");
    matrix_io_printToConsole(multiply);


    matrix_free(&nulltwo);
    matrix_free(&identitytwo);
    matrix_free(&multiply);
    matrix_free(&a);
    //matrix_free(&b);
    //matrix_free(&multiplyMatricies);

    //matrix_io_printToConsole(transpose);
    //printf("\n--\n");

    //transpose = matrix_transpose(transpose);
    //matrix_io_printToConsole(transpose);
    //printf("\n--\n");

    /*
    if(matrix_compare(userIn, matrix_init_identityMatrix(3)))
    {
        puts("TRUE!");
    }
    else
    {
        puts("FALSE!");
    }
    */

    return EXIT_SUCCESS;
}