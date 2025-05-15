#include <stdio.h>

// Function to find nth Fibonacci number
int fibonacci(int n) {
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Function to calculate the sum of Fibonacci series
int sumOfFibonacci(int n) {
    if (n == 0)
        return 0;
    return fibonacci(n) + sumOfFibonacci(n - 1);
}

int main() {
    int n;

    printf("Enter the number of terms in the Fibonacci series: ");
    scanf("%d", &n);

    int sum = sumOfFibonacci(n - 1);  // Subtracting 1 as Fibonacci is 0-indexed
    printf("Sum of the Fibonacci series up to %d terms is: %d\n", n, sum);

    return 0;
}
