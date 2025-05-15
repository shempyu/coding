class Solution {
public:
    void getAllCombinations(vector<int>& arr, int idx, int tar, set<vector<int>>& ans, vector<int>& combin) {
        if (idx == arr.size() || tar < 0)
            return;
        if (tar == 0) {
            ans.insert(combin); // Directly insert into the set
            return;
        }

        // Include current element (single and multiple inclusion cases)
        combin.push_back(arr[idx]);
        getAllCombinations(arr, idx + 1, tar - arr[idx], ans, combin); // Single inclusion
        getAllCombinations(arr, idx, tar - arr[idx], ans, combin);     // Multiple inclusion
        

        // Exclude current element
        combin.pop_back();
        getAllCombinations(arr, idx + 1, tar, ans, combin);
    }

    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        set<vector<int>> ansSet; // Use a set to store unique combinations
        vector<int> combin;

        getAllCombinations(arr, 0, target, ansSet, combin);

        // Convert the set to a vector of vectors
        return vector<vector<int>>(ansSet.begin(), ansSet.end());
    }
};
