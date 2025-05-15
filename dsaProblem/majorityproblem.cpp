class Solution {
    public : 
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        for(int val : nums){
            int freq = 0;

            for(int el : nums){
                if(el == val){
                    freq++;
                }
            }
            if(freq > n/2){
                return val;
            }
        }
        return -1;
    }   
    
};



//second approach
class Solution {
    public : 
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int freq = 1;
        for(int i = 1;i<n;i++){
            if(nums[i-1] == nums[i]){
                freq++;
            }
            if(freq> n/2)
                return nums[i];

             if(nums[i-1] != nums[i])
                freq = 1;   
        }
       return nums[0];
    }   
    
};



//MOORES VOTING ALGORITHM
class Solution {
    public : 
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int freq = 0,ans = 0;
        for(int i = 0;i<n;i++){
            if(freq == 0){
                ans = nums[i];
            }
            if(ans == nums[i]){
                freq++;
            }
            else{
                freq--;
            } 
        }
       return ans;
    }   
    
};