#include<iostream>
#include<fstream>
using namespace std;
int main(){
    fstream f1;
    char str[40];
    f1.open("shem.txt",ios::in);
    // ofstream f1("shem.txt"); //for write only
    //  ifstream f1("shem.txt"); // for read only
    // >> read from file
    // << write to file
    //f1.eof() --to go up to end of file
    //eof() return true when no more information is to raed
    //f1.getline(str,81,'$'); $ is delimiter char of my choice ,if it encounter the function will stop read before it read the maxm number of character
    //#include <ctype> // to convert into upeercase
    
    if(f1.fail()){
        cout<<"failed "<<endl;
    }
    else {
        // cout<<"write in file\n";
        // getline(cin,str);
        f1.getline(str,10);
        cout<<str;
        f1.close();
    }
    return 0;
}