#include<iostream>
#include<math.h>
using namespace std;
class calci
{
 int a,b;
 public:
  void operation()
  {
   int ch;
   while(ch!=8)
   {
     cout<<"PRESS operation FROM 1 TO 8"<<endl;
      cout<<"1.Addition"<<endl;
       cout<<"2.Subtraction"<<endl;
        cout<<"3.Multiplication"<<endl;
         cout<<"4.Divide"<<endl;
          cout<<"5.Square"<<endl;
           cout<<"6.Cube"<<endl;
            cout<<"7.Squareroot"<<endl;
             cout<<"8.exit"<<endl;
              cout<<"enter value for operation:"<<endl;
              cin>>ch;
              switch(ch)
              {
              case 1:add();
                     break;
              case 2:sub();
                     break;
              case 3:multi();
                     break;
              case 4:div();
                     break;
              case 5:square();
                     break;
              case 6:cube();
                     break;
              case 7:squareroot();
                     break;
              case 8:exit(1);
             }
         }
     }                                                   
   void add()
   {
    cout<<"a+b = "<<a+b<<endl;
   }
   void sub()
   {
    cout<<"a-b = "<<a-b<<endl;
   }
   void multi()
   {
    cout<<"a*b = "<<a*b<<endl;
   }
   void div()
   {
    cout<<"a/b = "<<a/b<<endl;
   }
   void square()
   {
    cout<<"a*a = "<<a*a<<endl;
    cout<<"b*b = "<<b*b<<endl;
   }
   void cube()
   {
    cout<<"a*a*a = "<<a*a*a<<endl;
    cout<<"b*b*b = "<<b*b*b<<endl;
   }  
   void squareroot()
   {
   cout<<"squareroot of a = "<<sqrt(a)<<endl;
   cout<<"squareroot of b = "<<sqrt(b)<<endl;
   }
   int get_a()
   {
    return a;
   }
   int get_b()
   {
    return b;
    }
    void set_value(int x,int y)
    {
      a=x;
      b=y;
    }
    };
    int main()
    { 
      int n1,n2;
      cout<<"enter 1st value: ";
       cin>>n1;
       cout<<"enter 2nd value: ";
        cin>>n2;
     calci c1;
     c1.set_value(n1,n2);
     cout<<"value of 1st no: "<<c1.get_a()<<endl;
      cout<<"value of 2nd no: "<<c1.get_b()<<endl;
       c1.operation();
     return 0;
   }