#include <iostream>

using namespace std;

int findMaxLoc(int arr[], int n)
{
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > arr[max])
        {
            max = i;
        }
    }
    return max;
}

int main()
{

    int n;

    cout << "Enter the size of the array : ";
    cin >> n;
    int arr[n];

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int maxElementposi = findMaxLoc(arr, n);
    cout << "Maximum element position: " << maxElementposi << endl;

    return 0;
}