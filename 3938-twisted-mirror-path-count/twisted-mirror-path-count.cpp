class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1e9 + 7;
        int m = grid.size(), n = grid[0].size();
        vector<vector<long long>> R(m, vector<long long>(n, 0)), D = R;
        R[0][0] = 1;  // start

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;
                if (j > 0) {
                    R[i][j] = grid[i][j-1] == 0 ? (R[i][j-1] + D[i][j-1]) % MOD
                                                : D[i][j-1];
                }
                if (i > 0) {
                    D[i][j] = grid[i-1][j] == 0 ? (R[i-1][j] + D[i-1][j]) % MOD
                                                : R[i-1][j];
                }
            }
        }
        return (R[m-1][n-1] + D[m-1][n-1]) % MOD;
    }
};