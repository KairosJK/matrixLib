/*

    Matrix Initialization Functions
        All functions create new matrices

*/

matrix matrix_init_zero(uint n, uint m)
{
    matrix newMatrix;

    newMatrix.arr = calloc(n, sizeof(element*));

    for(int i = 0; i < n; i++)
    {
        newMatrix.arr[i] = calloc(m, sizeof(element));
    }

    newMatrix.n = n;
    newMatrix.m = m;

    return newMatrix;
}

matrix matrix_init_identityMatrix(uint n)
{
    matrix newMatrix = matrix_init_zero(n, n); // Get null matrix

    for(int i = 0; i < n; i++)
    {
        newMatrix.arr[i][i] = 1; // Sets diagonal of matrix to 1 
    }

    return newMatrix;
}

matrix matrix_init_FromConsole()
{
    int n, m;

    printf("Please enter column length: ");
    while(1)
    {
        scanf("%d", &n);
        if(n > 0 && n < MAX_DIMENSIONS)
        {
            break;
        }
        printf("Input cannot consist of negative integers, or above hardcoded limit, which is set to %d. Try again.\n", MAX_DIMENSIONS);
    }

    printf("Please enter row width: ");
    while(1)
    {
        scanf("%d", &m);
        if(m > 0 && m < MAX_DIMENSIONS)
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
            scanf("%lf", &newMatrix.arr[i][j]);
        }
    }

    return newMatrix;
}

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


int matrix_free(matrix * a)
{
    // Frees allocated memory from matrix
    //      > Returns number of frees
    
    int i;

    for(i = 0; i < a->n; i++)
    {
        free(a->arr[i]);
    }

    free(a->arr);

    a->n = 0;
    a->m = 0;

    return i;
}