
#include <bits/stdc++.h>
using namespace std;
bool isPossible(vector<int> &arr, int N, int C,int minAllowedDist){ // O(N)
   // mid -> minm ALLOwed
   int cows = 1,lastStallPos = arr[0];
   
   for(int i = 1;i<N;i++)
   {
     if(arr[i] - lastStallPos >= minAllowedDist){
       cows++;
       lastStallPos = arr[i];
     }
     
     if(cows == C){
       return true;
     }
   }
   return false;
   
}
int getDistance(vector<int> &arr, int N, int C){
  sort(arr.begin(), arr.end()); // O(Nlog(N))
 int st = 1,end = arr[N-1] - arr[0], ans = 0;
 
 while(st <= end){ // O(log(Range) * N)
    int mid = st + (end - st) / 2;
    
    if(isPossible(arr ,N, C, mid)){
      ans  = mid;
      st = mid + 1;
    } else{
         end = mid -1;
    }
 
 }
 return ans;
}
int main(){
  int t;
  cin>>t;
  int N,C;
 
  while(t--){
  
  cin>>N>>C;
   vector<int> arr(N);
   
  for(int i = 0;i<N;i++){
    cin>>arr[i];
  }
  cout<<getDistance(arr,N,C)<<endl;
  
  }
  
return 0;
}
