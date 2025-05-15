/*
//Alternate way: using library function
 
       
        next_permutation(nums.begin(), nums.end());
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) { // tc : O(n) & sc : O(1)
        //find the pivot
        int pivot  = -1,n = nums.size();
       
        for(int i=n-2; i>=0; i--){  // n-2 cause last element has no i +1
            if(nums[i+1] > nums[i]){
                pivot = i;
                break;
            }
        }

        if(pivot == -1){
            reverse(nums.begin(), nums.end());
            return;
        }

        //2nd : next larger element
        for(int  i = n-1;i>pivot;i--){
            if(nums[i] > nums[pivot]){
                swap(nums[i] ,nums[pivot]);
                break;
            }
        }

        //3rd : revrse ()  from pivot + 1 to n-1
        reverse(nums.begin() + pivot + 1,nums.end());

        //  int i = pivot+1, j = n-1;
        //  while(i<=j){
        //     swap(nums[i++],nums[j--]);
        //  }
    }
};