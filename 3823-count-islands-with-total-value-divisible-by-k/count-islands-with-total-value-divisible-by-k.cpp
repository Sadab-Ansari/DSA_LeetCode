class Solution {
public:

    long long dfs(vector<vector<int>>& grid, int r, int c) {

        // Out of bounds
        if (r < 0 || r >= grid.size() ||
            c < 0 || c >= grid[0].size()) {
            return 0;
        }

        // Water or already visited
        if (grid[r][c] == 0) {
            return 0;
        }

        // Store current value
        long long sum = grid[r][c];

        // Mark as visited
        grid[r][c] = 0;

        // Up
        sum += dfs(grid, r - 1, c);

        // Down
        sum += dfs(grid, r + 1, c);

        // Left
        sum += dfs(grid, r, c - 1);

        // Right
        sum += dfs(grid, r, c + 1);

        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {

        int n = grid.size();
        int m = grid[0].size();

        int answer = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] != 0) {

                    long long sum = dfs(grid, i, j);

                    if (sum % k == 0) {
                        answer++;
                    }
                }
            }
        }

        return answer;
    }
};