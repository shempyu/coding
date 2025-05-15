#include <stdio.h>
#include <limits.h> // For INT_MAX
//it is based on divide and conquer problem
void output_array(int A[], int n)
{
    int i;
    printf("Sorted Elements: ");
    for (i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}
void merge(int A[], int lb, int mid, int ub)
{
    int n1, n2, i, j, k;
    n1 = mid - lb + 1;
    n2 = ub - mid;

    int L[n1 + 1], R[n2 + 1]; // Temporary arrays with extra space for sentinel values

    for (i = 0; i < n1; i++)
        L[i] = A[lb + i];
    for (j = 0; j < n2; j++)
        R[j] = A[mid + 1 + j];

    L[n1] = INT_MAX; // Sentinel values
    R[n2] = INT_MAX;

    i = 0;
    j = 0;

    for (k = lb; k <= ub; k++)
    {
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
    }
}

void merge_sort(int A[], int lb, int ub)
{
    int mid;
    if (lb < ub)
    {
        mid = (lb + ub) / 2;         // Find the midpoint
        
        merge_sort(A, lb, mid);     // Sort the first half
        merge_sort(A, mid + 1, ub); // Sort the second half
        merge(A, lb, mid, ub);       // Merge the sorted halves
    }
}

void input_array(int A[], int n)
{
    int i;
    printf("Elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);
}



int main()
{
    int n;
    printf("Size: ");
    scanf("%d", &n);

    int A[n];

    input_array(A, n);
    merge_sort(A, 0, n - 1);
    output_array(A, n);

    return 0;
}