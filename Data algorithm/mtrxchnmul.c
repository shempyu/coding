#include <stdio.h>
#include <limits.h>

// Function to print the optimal parenthesization of matrices
void parenth(int i, int j, int n, int s[n][n]) {
    if (i == j) {
        printf("A%d",i );
        return;
    }
    else {
    printf("(");
    parenth(i,         s[i][j], n,s);
    parenth(s[i][j]+ 1, j,     n, s);
    printf(")");
    }
}

// Function for Matrix Chain Multiplication
void matrixChainOrder(int arr[], int n) {
    
    int m[n][n];
    int brackets[n][n];

    // Initialize the cost of multiplying one matrix as 0
    for (int i = 1; i < n; i++)
        m[i][i] = 0;
    
    // l is the chain length
    for (int l = 2; l < n; l++) {
        for (int i = 1; i < n - l + 1; i++) {
            int j = i + l - 1;
            m[i][j] = INT_MAX; // Initialize m[i,j] to infinity

            // Find the optimal split point
            for (int k = i; k <= j - 1; k++) {
                // Cost of scalar multiplications
                int q = m[i][k] + m[k+1][j] + arr[i-1] * arr[k] * arr[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    brackets[i][j] = k;
                }
            }
        }
    }
    
    // Print the minimum number of multiplications needed
    printf("Minimum number of multiplications is: %d\n", m[1][n-1]);
    
    // Print the optimal parenthesization
    parenth(1, n-1, n, brackets);
   
}

int main() {
    int n;

    // Input number of matrices
    printf("Enter the number of dimensions: ");
    scanf("%d", &n);

    // Input the dimensions of the matrices
    int arr[n];
    printf("Enter the dimensions of the matrices: \n");
    for (int i = 0; i < n; i++) {
        printf("Dimension %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    // Call the function to calculate the matrix chain order
    matrixChainOrder(arr, n);
  

    return 0;
}