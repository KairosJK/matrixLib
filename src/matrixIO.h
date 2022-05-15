/*

    Matrix Display Functions
        All functions display or print matrices

*/

#define PRINT_PRECISION 2

void matrix_io_printToConsole(const matrix matrixInput)
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