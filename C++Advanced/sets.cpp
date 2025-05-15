#include<iostream>
using namespace std;
#include<set>
//set is implemented using balanced BST
//elements in set are sorted in ascending order by default
//set has unique element
//random acces not possible 
//can get ith element in 0(log n)
//insertion :O(log n)
//Deletion: O(log n)
//lower/Upper_bound:O(log n)
int main()
{  
    set <int> s;  // declaration of set
    s.insert(1);
    s.insert(2);
    s.insert(2);
    s.insert(3);
    for(auto i: s)  // accesing of set
       cout<<i<<" ";
    cout<<endl;

    for(auto i = s.begin(); i != s.end(); i++)
       cout<<*i<<" ";

    cout<<endl<<"printing in reverse: "<<endl;  //in reverse order accesing
    for(auto i = s.rbegin(); i != s.rend(); i++)
       cout<<*i<<" ";
       
    cout<<endl;   

    cout<<"size of set: "<<s.size()<<endl;  

    //insertig it ascending order
    set <int,greater<int>> ss;
    ss.insert(1);
    ss.insert(2);
    ss.insert(2);
    ss.insert(3);
    cout<<endl<<endl<<"sorting and printing in ascending order: "<<endl;
    for(auto i: ss)
       cout<<i<<" ";
    cout<<endl;   

     set <int> sss;
    sss.insert(1);
    sss.insert(3);
    sss.insert(5);
    for(auto i: sss)
       cout<<i<<" ";
    cout<<endl;
    // LOWER / UPPER BOUND()
    cout<< *sss.lower_bound(1)<<endl;
    cout<< *sss.lower_bound(2)<<endl;
    cout<< *sss.lower_bound(3)<<endl;
    cout<< *sss.upper_bound(3)<<endl;
    cout<<(sss.upper_bound(5) == sss.end()) <<endl<<endl; 
   

   cout<<"operation of erasing: "<<endl;
    //ERASING 
    set <int> s1; //declaring a set as s1
    s1.insert(1);
    s1.insert(3);
    s1.insert(2); 
    s1.insert(5);
    s1.insert(4);
    s1.insert(6);
    s1.insert(7);
   for (auto i: s1)
        cout<<i<<" ";
    s1.erase(2);
    s1.erase(s1.begin());
    s1.erase(s1.end());
    cout<<endl<<"after erasing "<<endl;
    for (auto i: s1)
        cout<<i<<" ";
    
    return 0;
}