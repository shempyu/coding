class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        
        // Step 1: Sort intervals by their start times
        sort(intervals.begin(), intervals.end());

        // Step 2: Initialize the first interval as the current interval
        vector<int> current = intervals[0];

        // Step 3: Iterate through the intervals
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= current[1]) {
                current[1] = max(current[1], intervals[i][1]);
            } else {
                // If they don't overlap, add the current interval to the answer
                ans.push_back(current);
                current = intervals[i];
            }
        }

        // Step 4: Add the last interval
        ans.push_back(current);

        return ans;
    }
};