class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen; // To track unique characters in the current substring
        int n = s.size();
        int left = 0, ans = 0;

        for (int right = 0; right < n; right++) {
            // Remove characters from the left until the substring is valid
            //check for duplicates if found deleted it
            while (seen.find(s[right]) != seen.end()) {
                seen.erase(s[left]);
                left++;
            }
            // Add the current character to the set
            seen.insert(s[right]);

            // Update the maximum length of the substring
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
