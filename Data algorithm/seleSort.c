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
void Selshort(int arr[], int n)
{
    int i, j;
    int min;
    for(i = 0;i<n-1;i++){
        min = i;
        for(j = i ;j<n;j++){
            if(arr[j+1]<arr[min])
            min = j+1;
            }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
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
        Selshort(arr, n);
         output_array(arr,n);
    }