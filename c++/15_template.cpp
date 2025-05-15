#include<iostream>
using namespace std;
template <class t>
t swap1(t &x,t &y){
   t temp;
   temp = x;
   x = y;
   y = temp;
}
int main(){
   int a,b;
   cin>>a>>b;
   cout<<a<<" "<<b<<endl;
   swap1(a,b);
  cout<<a<<" "<<b<<endl;
   return 0;
}