#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define SIZE 5

typedef struct
{
    uint16_t nRows;
    uint16_t ncols;
    uint16_t **values;
} Matrix;

Matrix *creer(uint16_t defVal, int rows, int cols)
{
    Matrix *mat = NULL;
    mat = (Matrix *)malloc(sizeof(mat));
    mat->nRows = rows;
    mat->ncols = cols;
    mat->values = (uint16_t **)malloc(rows * sizeof(uint16_t));
    for (int i = 0; i < rows; i++)
    {
        mat->values[i] = (uint16_t *)malloc(cols * sizeof(uint16_t));
        for (int j = 0; j < cols; j++)
        {
            mat->values[i][j] = defVal;
        }
    }
    return mat;
}

void initialiserLigne(int defVal, int row, Matrix *mat)
{
    for (int i = 0; i < mat->ncols; i++)
    {
        mat->values[row][i] = defVal;
    }
}

void matrix_mult(int64_t res[][SIZE], int64_t matrixA[][SIZE], int64_t matrixB[][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            res[i][j] = 0;
            for (int k = 0; k < SIZE; k++)
            {
                res[i][j] += (matrixA[i][k] * matrixB[k][j]);
            }
        }
    }
}

void squarre_matrix_print(int64_t matrix[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%lld ", matrix[i][j]);
        }
        printf("\n");
    }
}

void matrix_print(Matrix *mat)
{
    for (int i = 0; i < mat->nRows; i++)
    {
        for (int j = 0; j < mat->ncols; j++)
        {
            printf("%d ", mat->values[i][j]);
        }
        printf("\n");
    }
}

Matrix *multiplier(Matrix *A, Matrix *B){
    Matrix *C;
    C = creer(0, 0, 0);
    if (A->ncols == B->nRows){
        C = creer(0, A->nRows, B->ncols);
        for (int i = 0; i < A->nRows; i++){
            for (int j = 0; j < B->ncols; j++){
                for (int k = 0; k < A->ncols; k++){
                    C->values[i][j] += A->values[i][k] * B->values[k][j]; 
                }
            }
        }
    } else if (B->ncols == A->nRows){
        C = creer(0, B->nRows, A->ncols);
        for (int i = 0; i < B->nRows; i++){
            for (int j = 0; j < A->ncols; j++){
                for (int k = 0; k < B->ncols; k++){
                    C->values[i][j] += B->values[i][k] * A->values[k][j]; 
                }
            }
        }
    }
    return C;
}

int main(void)
{
    // matrices en ligne * colonne
    // int64_t matrice1[][SIZE] = {{1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}};
    // int64_t matrice2[][SIZE] = {{6, 7, 8, 9, 10}, {6, 7, 8, 9, 10}, {6, 7, 8, 9, 10}, {6, 7, 8, 9, 10}, {6, 7, 8, 9, 10}};
    // int64_t matriceResultat[SIZE][SIZE];
    // matrix_mult(matriceResultat, matrice1, matrice2);
    // squarre_matrix_print(matriceResultat);

    Matrix *A, *B, *C;
    A = creer(1, 2, 3);
    B = creer(1, 3, 4);

    matrix_print(A);
    printf("\n");
    matrix_print(B);
    printf("\n");

    // initialiserLigne(2, 1, A);
    initialiserLigne(1, 1, B);
    C = multiplier(A, B);

    
    matrix_print(C);

    return EXIT_SUCCESS;
}