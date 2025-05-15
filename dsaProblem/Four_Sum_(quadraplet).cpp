//### two poiter approach 
// TC : O(nlogn + n^3)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
       int n = nums.size();
       vector<vector<int>> ans;

       sort(nums.begin(),nums.end());

       for(int i = 0; i<n; i++){

        if(i > 0 && nums[i] == nums[i-1])
        continue;

        for(int j = i+1; j<n;j++){
             if(j > i+1 && nums[j] == nums[j-1])
                continue;
            int k = j+1,l = n-1;
            
            while(k<l){
                long long sum =(long long) nums[i] + (long long)nums[j] + (long long)nums[k] + (long long)nums[l];
                if(sum < target)
                  k++;
                else if(sum > target)  
                  l--;
                else{
                    ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                    k++;l--;
                    while(k<l && nums[k] == nums[k-1])
                          k++;
                    
                }  
            }
        }
        
       }
       return ans;
    }
};