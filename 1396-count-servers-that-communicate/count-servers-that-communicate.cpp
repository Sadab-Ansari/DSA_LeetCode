class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> row(m, 0), col(n, 0);

        // Pass 1: count servers in each row and column
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j]) { row[i]++; col[j]++; }

        // Pass 2: a server communicates if it isn't alone in its row or column
        int ans = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] && (row[i] > 1 || col[j] > 1))
                    ans++;

        return ans;
    }
};