//minimum maximum time for painters
#include <iostream>
#include <algorithm>
#include<limits.h>
using namespace std;

// Function to check if the current maximum time `mid` is valid
bool isValid(int arr[], int n, int m, int mid) {
    int painters = 1; // Start with one painter
    int time = 0;     // Time taken by the current painter
    
    for (int i = 0; i < n; i++) {
        if (arr[i] > mid) {
            // If a single board's length exceeds `mid`, it is not possible
            return false;
        }
        
        if (time + arr[i] <= mid) {
            time += arr[i];
			}

		else{
            painters++;
            time = arr[i]; //reset of time
		}
	}
	return painters <= m ; 

}

// Main function
int main() {
    int n, l, r;
    cin >> n >> l >> r; // Input number of boards, minimum and maximum painters
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; // Input the length of each board
    }
    
    int sum = 0, maxLength = INT_MIN;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        maxLength = max(maxLength, arr[i]);
    }
    
    int ans = -1;
    int st = maxLength, end = sum; // Start with the largest board length and sum of all lengths
    int m = 2;
    while (st <= end) {
        int mid = st + (end - st) / 2;
        
        if (isValid(arr, n, m, mid)) { //left
            ans = mid;
            end = mid - 1; // Try for a smaller maximum time
        } else { // right
            st = mid + 1; // Increase the maximum time
        }
    }
    
    cout <<ans<< endl; // Output the minimum time required
    return 0;
}
