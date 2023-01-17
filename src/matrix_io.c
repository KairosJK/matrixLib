#include "matrixlib.h"

/**
 * @brief prints matrix to console, row by row
 * @param matrixInput matrix to print
 */
void matrix_io_print(const matrix matrixInput)
{
    for(int i = 0; i < matrixInput.n; i++)
    {
        for(int j = 0; j < matrixInput.m; j++)
        {
            printf(" %.*lf ", PRINT_PRECISION, matrixInput.arr[i][j]);
        }
        printf("\n");
    }
}