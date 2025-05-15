#include<iostream>
using namespace std;
class text
{
 string msg;
 public:
 text(){
  msg=" ";
  }
  text(string given)
  {
   msg=given;
   }
   void show()
   {
    cout<<"msg: "<<msg<<endl;
    
}

 text operator +(text msg2){
   text temp;
   temp.msg=msg;
   temp.msg.append(msg2.msg);
   return temp;
   }
 };
 int main()
 {
  text f("new");
  text s(" delhi");
  text t;
  t=f+s;
  t.show();
  }