/*
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1, i = 0;

        while (i <= r) {
            if (nums[i] == 0) {
                swap(nums[i], nums[l]);
                l++;
                i++; // Move forward after swapping with the left pointer
            } else if (nums[i] == 2) {
                swap(nums[i], nums[r]);
                r--; // Only move the right pointer; recheck the current `i`
            } else {
                i++; // Move forward for `1` as it is already in place
            }
        }
    }
};

*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int mid = 0, high = n - 1, low = 0;

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                mid++;
                low++;
            } else if (nums[mid] == 1) {
               mid++;
            } else { // if mid = 2
               swap(nums[high], nums[mid]);
               high--;
            }
        }
    }
};
