#include<iostream>
using namespace std;
class wife;
class husband{
     int sal;
     public:
     husband(){
    cout<<"enter hus salary:\n";
    cin>>sal;
     }
     friend void comparesal(husband h,wife w);
};
class wife{
     int sal;
     public:
     wife(){
    cout<<"enter wife salary:\n";
    cin>>sal;
     }
     friend void comparesal(husband h,wife w);
};

void comparesal(husband h,wife w){
  if(h.sal > w.sal){
   cout<<"husband sala is more than wife\n";
  }
  else{
    cout<<"wife sala is more than husbnad\n";
  }
  
}
int main()
{
   husband h;wife w;
  comparesal(h,w);
   return 0;
}