class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        // Helper function for backtracking
        function<bool(int, int, int)> dfs = [&](int i, int j, int index) {
            // If the current index matches the word's length, we have found the word
            if (index == word.length()) {
                return true;
            }

            // Check if out of bounds or the character does not match
            if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] != word[index]) {
                return false;
            }

            // Temporarily mark the cell as visited by replacing it with a unique character
            char temp = board[i][j];
            board[i][j] = '#';

            // Explore all 4 directions (up, down, left, right)
            bool found = dfs(i + 1, j, index + 1) || // Move down
                         dfs(i - 1, j, index + 1) || // Move up
                         dfs(i, j + 1, index + 1) || // Move right
                         dfs(i, j - 1, index + 1);   // Move left

            // Restore the original character
            board[i][j] = temp;

            return found;
        };

        // Try to find the word starting from every cell in the board
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0] && dfs(i, j, 0)) {
                    return true;
                }
            }
        }

        return false;
    }
};
