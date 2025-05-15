#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the array
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Initialize the array
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }

    // Print the elements of the array
    printf("Elements of the array are:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(arr);
    return 0;
}
