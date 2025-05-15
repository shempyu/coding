#include<stdio.h>
void input(int *arr,int n){
    printf("enetr the elements of array: ");
    for(int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }
}
void output(int *arr,int n){
    printf("elemet are: ");
    for(int i = 0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void ins(int *arr,int n){
    for(int i = 0;i<n;i++){
        int key = arr[i];
        int j;
        for(j = i;j>0 && key<arr[j-1];j--)
            arr[j] = arr[j-1];
        arr[j] = key;
        output(arr,n);
        
    }
}
  void sel(int *arr,int n){
    for(int i = 0;i<n;i++){
        int min = i;
        for(int j = i+1;j<n;j++){
        if(arr[j] < arr[min])
        min = j;
        }
        int temp = arr[min];
        arr[min]  = arr[i];
        arr[i] = temp;
        output(arr,n);
    }
  }
  void bub(int *arr,int n){
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            if(arr[j] < arr[i]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        output(arr,n);
    }
  }  

int main(){
    int n;
    printf("enert the size of array: ");
    scanf("%d",&n);
    int arr[n];
    input(arr,n);
    bub(arr,n);
    
    

    return 0;
}