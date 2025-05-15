#include <vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int st = 0, end = arr.size() - 1;

        // If there's only one element in the array, return it immediately
        if (st == end)
            return arr[st];

        // Binary search to find the single non-duplicate element
        while (st <= end) {
            // Calculate the middle index
            int mid = st + (end - st) / 2;

            // Case 1: Single element is at the beginning or end of the array
            if ((mid == 0 && arr[0] != arr[1]) || 
                (mid == end && arr[end] != arr[end - 1])) 
                return arr[mid];

            // Case 2: Single element is in the middle of the array
            // Check if the element at `mid` is different from its neighbors
            if (arr[mid - 1] != arr[mid] && arr[mid] != arr[mid + 1])
                return arr[mid];

            // Case 3: Determine which side of the array to search next
            // If the pair (arr[mid] == arr[mid - 1]) is aligned with the even index
            // OR (arr[mid] == arr[mid + 1]) is aligned with the odd index,
            // move to the left half
            if ((arr[mid - 1] == arr[mid] && mid % 2 == 0) || 
                (arr[mid] == arr[mid + 1] && mid % 2 != 0))
                end = mid - 1;
            else 
                // Otherwise, move to the right half
                st = mid + 1;
        }

        // After the loop, the `st` pointer will point to the single element
        return arr[st];
    }
};
