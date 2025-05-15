#include<iostream>
using namespace std;
class index{
 private:
  int value;
  public:
   index(){
    value=0;
    }
     void getindex()
     {
      cout<<"value: "<<value<<endl;
      }
      void operator ++()
      {
       ++value;
       }
       };
       int main()
       {
        index d;
        ++d;
        ++d;
        d.getindex();
        }