/*
#include<iostream>
#include<vector>
#include<set>
using namespace std;
int main() {
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    int m = 3;
    int n = 3;
        multiset<int> s;
        int i = 0;
        while(m != 0){
           s.insert(nums1[i]);
           i++;
           m--;
        }
        int j = 0;
        while( n != 0 )
        {
            s.insert(nums2[j]);
            n--;
            j++;
        }
   // Clear nums1 and copy sorted elements back
    nums1.clear();
    for (auto val : s) {
        nums1.push_back(val);
    }

    // Print the updated nums1
    for (auto num : nums1) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
    
};

*/

// ############# two pointer approach ############
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums1 = {1, 2, 3, 0, 0, 0}; // nums1 has enough space for merging
    vector<int> nums2 = {2, 5, 6};
    int m = 3; // Number of valid elements in nums1
    int n = 3; // Number of elements in nums2

    // O(m+n) TC
    //O(1) SC(space complexity)
    // Pointers for the end of valid elements in nums1 and nums2
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1; // Pointer for the end of nums1

    // Merge nums1 and nums2 in reverse order
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];
            i--;
        } else {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }

    // Copy remaining elements from nums2 (if any)
    while (j >= 0) {
        nums1[k] = nums2[j];
        j--;
        k--;
    }

    // Print the merged nums1
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
