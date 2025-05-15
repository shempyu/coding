#include <stdio.h>
#include <limits.h>

// Function for Matrix Chain Multiplication
int matrixChainOrder(int p[], int i,int j) {
   if(i==j)
      return 0;
   int min = INT_MAX;
   for(int k = i;k<=j-1;k++){
    int temp = matrixChainOrder(p,i,k) + matrixChainOrder(p,k+1,j)+(p[i-1]*p[k]*p[j]);
    if (temp<min)
        min = temp;
   }
   return min; 
         
}

int main() {
    int n;

    // Input number of matrices
    printf("Enter the number of matrices: ");
    scanf("%d", &n);

    // Input the dimensions of the matrices
    int arr[n+1];
    printf("Enter the dimensions of the matrices: \n");
    for (int i = 0; i < n; i++) {
        printf("Dimension %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    // Call the function to calculate the matrix chain order
    printf("cost: %d",matrixChainOrder(arr, 1,n-1));

    return 0;
}