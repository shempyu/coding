//remove duplicacy without sorting
#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "enter n\n";
    cin >> n;
    int arr[n];
    int count;
    cout << "enter elemen of arrsy\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
           count = 0;
        for (int j = 0; j < i; j++)
        {
            if(arr[i] ==arr[j]){
                count++;
            }
        }
        if(count == 0)
        cout<<arr[i]<<" ";
    }
    return 0;
}