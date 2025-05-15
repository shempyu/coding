/*
class Solution {
public:
    int singleNumber(vector<int>& nums) {
         int n = nums.size();
        multiset<int> s(nums.begin(),nums.end());
       
        int a;
        for(int i = 0;i<n;i++){
            s.erase(nums[i]);
            if(s.size() == n - 1){
                return nums[i];
            }
            else{
                int m = s.size();
                while( m != n){
                  s.insert(nums[i]); 
                  m++;
                }
                
            }

        }
        return 0;
    }
};
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
       int ans = 0;
        for (int num : nums) {
            ans = ans ^ num; // XOR all elements
        }
        return ans;
        return 0;
    }
};

