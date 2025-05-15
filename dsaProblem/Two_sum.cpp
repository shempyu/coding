//2sum
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> m;
        vector<int> ans;

        for(int i = 0;i<n;i++){
            int first = nums[i];
            int sec = target - first;

            if(m.find(sec) != m.end()){ // check existance of sec in map m
                ans.push_back(i);
                ans.push_back(m[sec]);
                break;
            }
            m[first] = i;
        }
        return ans;
    }
};