class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int maxArea = 0;

        int directions[4][2] = {
            {-1, 0},
            {1, 0},
            {0, -1},
            {0, 1}
        };

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 1) {
                    int area = 0;

                    queue<pair<int, int>> q;
                    q.push({i, j});
                    grid[i][j] = 0; // mark visited

                    while (!q.empty()) {
                        auto [r, c] = q.front();
                        q.pop();

                        area++;

                        for (auto& dir : directions) {
                            int nr = r + dir[0];
                            int nc = c + dir[1];

                            if (nr >= 0 && nr < m &&
                                nc >= 0 && nc < n &&
                                grid[nr][nc] == 1) {

                                grid[nr][nc] = 0;
                                q.push({nr, nc});
                            }
                        }
                    }

                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};