class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,1);
        for(int  i = 1;i<n;i++){
            ans[i] = ans[i-1] * nums[i-1];
              //pre[0]= 1,pre[1] = pre[0] * nums[0]
             //suf[3] = 1 ; suf[2] = suf[3] * num[3]
        }
        int suf = 1;
        for(int i = n-2;i>=0;i--){
            suf = suf * nums[i+1];
            ans[i] = ans[i] * suf;
        }
        return ans;
    }
};