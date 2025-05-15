#include <stdio.h>

void multiplyMatrices(int firstMatrix[][10], int secondMatrix[][10], int resultMatrix[][10], int row1, int col1, int row2, int col2) {
    // Initialize result matrix to 0
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            resultMatrix[i][j] = 0;
        }
    }

    // Multiply matrices
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            for (int k = 0; k < col1; k++) {
                resultMatrix[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
            }
        }
    }
}

void printMatrix(int matrix[][10], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int row1, col1, row2, col2;
    int firstMatrix[10][10], secondMatrix[10][10], resultMatrix[10][10];

    // Input dimensions of the first matrix
    printf("Enter rows and columns for the first matrix: ");
    scanf("%d %d", &row1, &col1);

    // Input dimensions of the second matrix
    printf("Enter rows and columns for the second matrix: ");
    scanf("%d %d", &row2, &col2);

    // Check if multiplication is possible
    if (col1 != row2) {
        printf("Matrix multiplication is not possible with the given dimensions.\n");
        return 0;
    }

    // Input first matrix
    printf("Enter elements of the first matrix:\n");
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col1; j++) {
            scanf("%d", &firstMatrix[i][j]);
        }
    }

    // Input second matrix
    printf("Enter elements of the second matrix:\n");
    for (int i = 0; i < row2; i++) {
        for (int j = 0; j < col2; j++) {
            scanf("%d", &secondMatrix[i][j]);
        }
    }

    // Call the function to multiply matrices
    multiplyMatrices(firstMatrix, secondMatrix, resultMatrix, row1, col1, row2, col2);

    // Print the result
    printf("Resultant Matrix:\n");
    printMatrix(resultMatrix, row1, col2);

    return 0;
}
