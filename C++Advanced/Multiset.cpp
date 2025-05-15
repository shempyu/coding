// Multiset is implemented using balaced BST
//elements in Nultiset are sorted in ascending order by default
// Multiset has multi element
// random acces not possible
// can get ith element in 0(log n)
#include <iostream>
using namespace std;
#include <set>
int main()
{
    multiset<int> s; // declaration of set
    s.insert(9);
    s.insert(1);
    s.insert(5);
    s.insert(3);
    s.insert(3);
    s.insert(2);
    s.insert(5);
    s.insert(5);
    s.insert(5);
    s.insert(7);
    for (auto i : s) // accesing of set
        cout << i << " ";
    cout << endl;
    s.erase(3); // this will erase each occurance of 3
    s.erase(s.find(5)); // this will erase only first ocuurance of element and if element is not present it will remove all elements except first and last

    for (auto i : s) // accesing of set
        cout << i << " ";
    cout << endl;
    return 0;
}