#include "matrixlib.h"

void matrix_edit_swapColumns(matrix * a, unsigned int columnA, unsigned int columnB)
{
    double temp;

    for(int i = 0; i < a->n; i++)
    {
        temp = a->arr[i][columnA];
        a->arr[i][columnA] = a->arr[i][columnB];
        a->arr[i][columnB] = temp;
    }
}

void matrix_edit_swapRows(matrix * a, unsigned int rowA, unsigned int rowB)
{
    double temp;

    for(int i = 0; i < a->m; i++)
    {
        temp = a->arr[rowA][i];
        a->arr[rowA][i] = a->arr[rowB][i];
        a->arr[rowB][i] = temp;
    }
}

void matrix_edit_multiplyRow(matrix * a, unsigned int row, double k)
{
    for(int i = 0; i < a->m; i++)
    {
        a->arr[row][i] *= k;
    }
}

void matrix_edit_multiplyColumn(matrix * a, unsigned int column, double k)
{
    for(int i = 0; i < a->m; i++)
    {
        a->arr[i][column] *= k;
    }
}

void matrix_edit_addRows(matrix * a, unsigned int rowDestination, double k, unsigned int rowSource)
{
    for(int i = 0; i < a->m; i++)
    {
        a->arr[rowDestination][i] += ((a->arr[rowSource][i]) * k); 
    }
}

void matrix_edit_addColumns(matrix * a, unsigned int columnDestination, double k, unsigned int columnSource)
{
    for(int i = 0; i < a->n; i++)
    {
        a->arr[i][columnDestination] += ((a->arr[i][columnSource]) * k); 
    }
}
