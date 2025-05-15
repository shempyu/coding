#include <iostream>
using namespace std;
class queue{
 private:
  int qu[3],x;
  int front=-1;
  int rear=-1;
public:
 void enqueue(){
    if(rear==2)
     cout<<"queue is full"<<endl;
     else if(front==-1 && rear==-1){
        front=rear=0;
          cout<<"enter the data: ";
        cin>>x;
        qu[rear]=x;
     }
        else{
        rear=rear+1;
        cout<<"enter the data: ";
        cin>>x;
        qu[rear]=x;
        }
 }
 void dequeue(){
    if(front==-1 || rear==-1)
     cout<<"queue is empty"<<endl;
     else if(front==rear){
        cout<<"deueue element is: "<<qu[front]<<endl;
        front=rear=-1;
     }
     else{
        cout<<"dequeue element is: "<<qu[front]<<endl;
        front=front+1;
     }
 }
 void peekf(){
    cout<<"peek front element is: "<<qu[front]<<endl;
 }
 void peekr(){
     cout<<"peek rear element is: "<<qu[rear]<<endl;
 }
 void display(){
      if(front==-1 && rear==-1)
       cout<<"queue is empty"<<endl;
       else{
         cout<<"elements of queue are: ";
         for(int i=front; i<=rear; i++){
            cout<<qu[i]<<" ";
         }
       }
        cout<<endl;
 }
};
int main(){
    queue q;
     int ch;
     while(ch!=6){
        cout<<"queue operation"<<endl;
        cout<<"1.enqueue operation"<<endl;
        cout<<"2.dequeue operation"<<endl;
        cout<<"3.peek front operation"<<endl;
        cout<<"4.peek rear operation"<<endl;
        cout<<"5.display opeartion"<<endl;
        cout<<"enter your choice: ";
        cin>>ch;
        switch(ch){
            case 1: q.enqueue();
                     break;
            case 2: q.dequeue();
                     break;
            case 3: q.peekf();
                     break;
            case 4: q.peekr();
                     break;
            case 5: q.display();
                    break;
            case 6:exit(1);
             default :cout<<"enter valid input"<<endl;                           
        }
     }

}