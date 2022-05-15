/*

    Matrix Edit Functions
        All functions pertain editing already initialized functions

*/

void matrix_edit_swapColumns(matrix * a, uint columnA, uint columnB)
{
    element temp;

    for(int i = 0; i < a->n; i++)
    {
        temp = a->arr[i][columnA];
        a->arr[i][columnA] = a->arr[i][columnB];
        a->arr[i][columnB] = temp;
    }
}

void matrix_edit_swapRows(matrix * a, uint rowA, uint rowB)
{
    element temp;

    for(int i = 0; i < a->m; i++)
    {
        temp = a->arr[rowA][i];
        a->arr[rowA][i] = a->arr[rowB][i];
        a->arr[rowB][i] = temp;
    }
}

void matrix_edit_multiplyRow(matrix * a, uint row, element k)
{
    for(int i = 0; i < a->m; i++)
    {
        a->arr[row][i] *= k;
    }
}

void matrix_edit_multiplyColumn(matrix * a, uint column, element k)
{
    for(int i = 0; i < a->m; i++)
    {
        a->arr[i][column] *= k;
    }
}

void matrix_edit_addRows(matrix * a, uint rowDestination, element k, uint rowSource)
{
    for(int i = 0; i < a->m; i++)
    {
        a->arr[rowDestination][i] += ((a->arr[rowSource][i]) * k); 
    }
}

void matrix_edit_addColumns(matrix * a, uint columnDestination, element k, uint columnSource)
{
    for(int i = 0; i < a->n; i++)
    {
        a->arr[i][columnDestination] += ((a->arr[i][columnSource]) * k); 
    }
}
