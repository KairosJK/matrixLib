#include "matrixlib.h"

matrix matrix_scalar_multiply(matrix a, double k)
{
    for(int i = 0; i < a.n; i++)
    {
        for(int j = 0; j < a.m; j++)
        {
            a.arr[i][j] = a.arr[i][j] * k;
        }
    }
    return a;
}

matrix matrix_add(const matrix a, const matrix b)
{
    matrix summationMatrix = matrix_init_zero(a.n, a.m);

    if(a.n != b.n || a.m != b.m)
    {
        fprintf(stderr, "Error: %s: matrices must have same collumn and row length to add and subtract.\n", __func__);
        abort();
    }

    for(int i = 0; i < a.n; i++)
    {
        for(int j = 0; j < a.m; j++)
        {
            summationMatrix.arr[i][j] = a.arr[i][j] + b.arr[i][j];
        }
    }

    return summationMatrix;
}

bool matrix_compare(const matrix a, const matrix b)
{
    if(a.n != b.n || a.m != b.m)
    {
        return false; // Different dimensions, instant false
    }

    for(int i = 0; i < a.n; i++)
    {
        for(int j = 0; j < a.n; j++)
        {
            if(fabs((a.arr[i][j]) - (b.arr[i][j])) > DECIMAL_PRECISION) // Check two paired doubles for equality
            {
                return false; // If two doubles do not compare, return false
            }
        }
    }
    return true; // All doubles are the same, equal matrices
}

matrix matrix_transpose(const matrix a)
{
    matrix newMatrix = matrix_init_zero(a.m, a.n);

    for(int i = 0; i < a.n; i++)
    {
        for(int j = 0; j < a.m; j++)
        {
            newMatrix.arr[j][i] = a.arr[i][j];
        }
    }
    return newMatrix;
}

matrix matrix_multiply(const matrix a, const matrix b)
{
    matrix newMatrix = matrix_init_zero(a.n, b.m);

    if(a.m != b.n)
    {
        fprintf(stderr, "Error: %s: cannot multiply matricies who do not share the comformable dimensions.\n", __func__);
        abort();
    }

    for(int i = 0; i < newMatrix.n; i++)
    {
        for(int j = 0; j < newMatrix.m; j++)
        {
            double sum = 0;
            for(int k = 0; k < a.m; k++)
            {
                sum += a.arr[i][k] * b.arr[k][j];
            }
            newMatrix.arr[i][j] = sum;
        }
    }
    
    return newMatrix;
}