#include<iostream>
using namespace std;
class complex
{
 int a,b;
 public:
 complex(){
  a=0;
  b=0;
  }
  complex(int x1,int x2)
  {
   a=x1;
   b=x2;
   }
   void show()
   {
    cout<<"complex no= "<<a<<"+ i"<<b<<endl;}
complex operator +(complex j){
    complex temp;
    //temp.a=a;
   // temp.b=b;
    temp.a=a+j.a;
    temp.b=b+j.b;
    return temp;
    
   }};
 int main()
 {
  complex f(5,6);
  complex s(7,8);
  complex t;
  t=f+s;
  t.show();
  }