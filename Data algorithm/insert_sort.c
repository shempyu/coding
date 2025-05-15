#include <stdio.h>
//5 3  4 1 6 2
void output_array(int A[], int n)
{
    int i;
    printf("Sorted Elements: ");
    for (i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}
void ishort(int *arr, int n)
{
    int i, j;
    int key;
    for (i = 0; i < n; i++)
    {
    key = arr[i];
    for (j = i; j > 0 && key < arr[j - 1]; j--)
        arr[j] = arr[j - 1];
    arr[j] = key;
    output_array(arr,n);
    }
}

    int main()
    {
        int n;
        printf("enter the size of array\n");
        scanf("%d", &n);
        int arr[n];
        printf("enter the elements of array\n");
        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        ishort(arr, n);
       output_array(arr,n);
    }