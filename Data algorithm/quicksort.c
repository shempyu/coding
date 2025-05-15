#include<stdio.h>
void swap(int *x,int *y){
   int temp = *x;
   *x = *y;
   *y = temp;
}
void output_array(int A[], int n)
{
    int i;
    printf("Sorted Elements: ");
    for (i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}
int partition(int arr[],int lb,int ub){
      int pivot = arr[lb];
      int start = lb;
      int end  = ub;
      while(start<end){
        while(arr[start]<=pivot){
           start ++;
        }
        while(arr[end]>pivot){
            end--;
        }
        if(start<end){
            swap(arr + start,arr + end);
        }
      }
      swap(arr+lb,arr+end);
      return end;
      
}
void quicksort(int arr[],int lb,int ub){
    if(lb<ub){
   int  loc = partition(arr,lb,ub);
   quicksort(arr,lb,loc-1);
   quicksort(arr,loc+1,ub);
    }
}

void input_array(int A[], int n)
{
    int i;
    printf("Elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);
}


int main(){
   int n;
    printf("Size: ");
    scanf("%d", &n);
    
    int A[n];
    input_array(A, n);
    quicksort(A,0,n-1);
    output_array(A, n);
}