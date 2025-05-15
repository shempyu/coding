#include<iostream>
using namespace std;
class emp{
string id,name;
float salary;
public:
 emp(){
 cout<<"default constructor"<<endl;
  id="cse1234";
  name="shyam kumar";
  salary=100000;
  }
  emp(string a,string b,float c){
  cout<<"parameterized constructor"<<endl;
   id=a;
   name=b;
   salary=c;
   }
   emp(emp &obj){
   cout<<"copy constructor"<<endl;
   id=obj.id;
   name=obj.name;
   salary=obj.salary;
   }
   void display(){
    cout<<"employee id: "<<id<<endl;
    cout<<"employee name: "<<name<<endl;
    cout<<"employee salary: "<<salary<<endl;
    }
   };
   int main(){
    emp x;
    x.display();
   emp y("cse1098","ram kumar",180000);
    y.display();
    emp z(y);
    z.display();
    return 0;
    }