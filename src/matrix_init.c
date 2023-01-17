#include "matrixlib.h"

/**
 * @brief initialize new zeroed matrix
 * @param n nth/vertical dimension of matrix
 * @param m mth/horizontal dimension of matrix
 * @return matrix newly allocated matrix
 */
matrix matrix_init_zero(unsigned int n, unsigned int m)
{
    matrix newMatrix;

    newMatrix.arr = calloc(n, sizeof(double*));

    for(int i = 0; i < n; i++)
    {
        newMatrix.arr[i] = calloc(m, sizeof(double));
    }

    newMatrix.n = n;
    newMatrix.m = m;

    return newMatrix;
}

/**
 * @brief initialize new identity matrix of given dimensions
 * @param n dimension of identity matrix (ie. n*n)
 * @return matrix newly allocated matrix
 */
matrix matrix_init_identity(unsigned int n)
{
    matrix newMatrix = matrix_init_zero(n, n); // Get null matrix

    for(int i = 0; i < n; i++)
    {
        newMatrix.arr[i][i] = 1; // Sets diagonal of matrix to 1 
    }

    return newMatrix;
}

/**
 * @brief Copies data from given matrix to new matrix
 * @param a matrix to be copied
 * @return matrix new copied matrix
 */
matrix matrix_copy(matrix a)
{
    matrix newMatrix = matrix_init_zero(a.n, a.m);

    for(int i = 0; i < newMatrix.n; i++)
    {
        for(int j = 0; j < newMatrix.m; j++)
        {
            newMatrix.arr[i][j] = a.arr[i][j];
        }
    }

    return newMatrix;
}

/**
 * @brief frees allocated memory from matrix
 * @param a matrix to be free'd
 * @return int number of allocations free'd
 */
int matrix_free(matrix * a)
{
    int i;
    for(i = 0; i < a->n; i++)
    {
        free(a->arr[i]);
        a->arr[i] = NULL;
    }

    free(a->arr);
    a->arr = NULL;

    a->n = 0;
    a->m = 0;

    return i;
}