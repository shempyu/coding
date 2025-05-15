#include <iostream>
using namespace std;
class stack
{
 int top=-1;
 int a[3];
 public:
  void push();
  void pop();
  bool isFull();
  bool isEmpty();
  void peek();
  void display();
  };
  bool stack :: isFull()
  {
    if(top==2)
     return 1;
     else 
     return 0;
  }
  bool stack :: isEmpty()
  {
    if(top==-1)
     return 1;
     else
     return 0;
   }
   void stack :: push()
   {
      if(isFull())
      {
       cout<<"stack is overflow"<<endl;
      }
      else
      {  
        int x;
       cout<<"enter the data: ";
        cin>>x;
        top=top+1;
        a[top]=x;
      }
   }
     void stack :: pop()
     {
      if(isEmpty())
      {
        cout<<"stack is underflow"<<endl;
      }
      else
      {
        cout<<"poped element: "<<a[top]<<endl;
        top=top-1;
      }
    }
      void stack :: peek()
      {
        cout<<"peek element: "<<a[top]<<endl;
       }
       void stack :: display()
       {
         if(isFull())
         cout<<"stack is overflow"<<endl;
         else if(isEmpty())
          cout<<"stack is underflow"<<endl;
          else{
               cout<<"elements of stack: "; 
              for(int i=top; i>=0; i--)
               cout<<a[i]<<" ";
               }
               cout<<endl;
      }
       
      int main()
      {
       stack s1;
       int ch;
       while(ch!=5)
       {
         cout<<"stack operation"<<endl;
         cout<<"1.push"<<endl;
         cout<<"2.pop"<<endl;
         cout<<"3.peek"<<endl;
         cout<<"4.display"<<endl;
         cout<<"5.exit"<<endl;
         cout<<"enter the operation to be perform: ";
         cin>>ch;
         switch(ch)
         {
          case 1:s1.push();
                  break;
          case 2:s1.pop();
                  break;
          case 3:s1.peek();
                  break;
          case 4:s1.display();
                 break;            
          case 5:exit(1);
             default: cout<<"invalid operation"<<endl;
          }
        }
      }