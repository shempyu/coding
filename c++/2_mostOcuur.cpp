#include <iostream>
using namespace std;
int main(){
 int n;
 cout<<"enter the size of an array: ";
 cin>>n;
 int a[n];
 cout<<"enetr the elements of an array: ";
 for(int i=0; i<n; i++)
    cin>>a[i];
    int max_occur=0;
    int max_value=0;
    for(int i=0; i<n; i++){
            int occur=0;
            for(int j=0; j<n; j++){
              if(a[i]==a[j])
              occur++;
              }
              if(occur>max_occur)
              {
                max_occur=occur;
                max_value=a[i];
                }
             }
             cout<<"Most frequent element is: "<<max_value<<endl;
             cout<<"no of times repeated: "<<max_occur<<endl;
             return 0;
             }