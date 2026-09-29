class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if ((m + n - 1) % 2 || grid[0][0] == ')' || grid[m-1][n-1] == '(')
            return false;

        vector<vector<bitset<256>>> dp(m, vector<bitset<256>>(n));
        dp[0][0][1] = 1;  // after the first '(' the balance is 1

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;
                bitset<256> in;
                if (i > 0) in |= dp[i-1][j];
                if (j > 0) in |= dp[i][j-1];
                dp[i][j] = (grid[i][j] == '(') ? (in << 1) : (in >> 1);
            }
        }
        return dp[m-1][n-1][0];
    }
};