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

/**
 * @brief initialize new matrix from console
 * @return matrix newly allocated matrix
 */
matrix matrix_io_read_console()
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
 * @brief initializes new matrix directly from file (format can be found at tests/data/readme.md)
 * @param path file pointer to file to read (NOTE: the pointer is closed and nullified after use)
 * @return matrix matrix initialized from file
 */
matrix matrix_io_read_file(FILE* path) {
    if(path == NULL) {
        fprintf(stderr, "Error: %s: file specified could not be opened or found\n", __func__);
        abort();
    }
    int n, m;
    if(fscanf(path, "%d, %d, ", &n, &m) != 2) {
        fprintf(stderr, "Error: %s: file header specified is not formatted correctly.\n", __func__);
        fprintf(stderr, "Error: %s: Format guides can be found in the source repository at tests/data/readme.md\n", __func__);
        abort();
    }
    matrix new_matrix = matrix_init_zero(n, m);
    for (int i = 0; i < new_matrix.n; i++){
        for (int j = 0; j < new_matrix.m; j++){
            if(fscanf(path, "%lf, ", &(new_matrix.arr[i][j])) != 1) {
                fprintf(stderr, "Error: %s: file specified is not formatted correctly.\n", __func__);
                fprintf(stderr, "Error: %s: Format guides can be found in the source repository at tests/data/readme.md\n", __func__);
                abort();
            }
        }
    }
    fclose(path);
    path = NULL;
    return new_matrix;
}