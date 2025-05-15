#include <stdio.h>
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
// Function to heapify a subtree rooted at index i
void maxheapify(int arr[], int n, int i)
{
    int largest = i;
    int l = (2 * i) + 1;
    int r = (2 * i) + 2;
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
    // If right child is larger than the largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
    // If largest is not root
    if (largest != i)
    {
        swap(arr + largest, arr + i);
        // Recursively heapify the affected subtree
        maxheapify(arr, n, largest);
    }
}
void buildMaxHeap(int arr[], int n)
{
    // Step 1: Build a max heap (rearrange the array)
    for (int i = (n / 2) - 1; i >= 0; i--)
        maxheapify(arr, n, i);
}
void heapsort(int arr[], int n)
{
    // buildMaxHeap(arr, n);
    for (int i = (n / 2) - 1; i >= 0; i--)
        maxheapify(arr, n, i);

    // Step 2: One by one extract elements from the heap
    for (int i = n - 1; i >0; i--) //start from n cause we keep max data at last 
    {
        // Move current root (maximum element) to the end
        swap(arr, arr + i);
        // Heapify the root to restore the max heap property
        maxheapify(arr, i, 0); // we heapy fy from starting cause changing has done at starting(root)
    }
}

void input_array(int A[], int n)
{
    int i;
    printf("Elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);
}

void output_array(int A[], int n)
{
    int i;
    printf("Sorted Elements: ");
    for (i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main()
{
    int n;
    printf("Size: ");
    scanf("%d", &n);
    int A[n];

    input_array(A, n);
    heapsort(A, n);
    output_array(A, n);

    return 0;
}