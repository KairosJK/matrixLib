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
 * @brief initialize new matrix from console
 * @return matrix newly allocated matrix
 */
matrix matrix_init_console()
{
    int n, m;

    printf("Please enter column length: ");
    while(1)
    {
        int num_scanned = scanf("%d", &n);
        if((n > 0 && n < MAX_DIMENSIONS) || num_scanned != 1)
        {
            break;
        }
        printf("Input cannot consist of negative integers, or above hardcoded limit, which is set to %d. Try again.\n", MAX_DIMENSIONS);
    }

    printf("Please enter row width: ");
    while(1)
    {
        int num_scanned = scanf("%d", &m);
        if((m > 0 && m < MAX_DIMENSIONS) || num_scanned != 1)
        {
            break;
        }
        printf("Input cannot consist of negative integers, or above hardcoded limit, which is set to %d. Try again.\n", MAX_DIMENSIONS);
    }

    matrix newMatrix = matrix_init_zero(n, m);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            printf("Enter element for cell [%d][%d]: ", i+1, j+1);
            if(scanf("%lf", &newMatrix.arr[i][j]) != 1) {
                printf("Something went wrong with the input, try again.\n");
                j--;
            };
        }
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
    // Frees allocated memory from matrix
    //      > Returns number of frees
    
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