#include<stdio.h>
//bubble sort
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void show(int *arr,int n){
    for(int i = 0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void bubblesort(int*arr,int n){
    for(int i = 0;i<n;i++){
        int swapped = 0; //to check any swap
        for(int j = i+1;j<n;j++){
            if(arr[i] > arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                swapped = 1;
            }
        }
        show(arr,n);
        if(swapped == 0)
         break;
    }
}

void input(int *arr,int n){
    printf("enetr the elemetso f array: ");
    for(int i = 0 ;i<n;i++){
        scanf("%d",&arr[i]);
    }
}

int main(){
   int n ;
   printf("eneter the size iof aray: ");
   scanf("%d",&n);
   int arr[n];
   input(arr,n);
   bubblesort(arr,n);
   show(arr,n);
    return 0;
}