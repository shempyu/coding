#include<iostream>
#include<fstream>
using namespace std;
class student{
     public:
  int roll;
  string name;
  student(){
    cout<<"enter roll and name\n";
    cin>>roll>>name;
  }
};
int main(){
    fstream f1;
    char str[45];
    f1.open("shem1.txt",ios::out);
    if(f1.fail()){
        cout<<"failed "<<endl;
    }
    else {

        student s[5];
       for(int i = 0;i<5;i++){
        f1<<s[i].roll<<" "<<s[i].name<<endl;
       }
        f1.close();
    }
    f1.open("shem1.txt",ios::in);
    f1.getline(str ,12);
    return 0;
}