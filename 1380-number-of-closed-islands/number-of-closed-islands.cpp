class Solution {
public:
    int rows, cols;

    // Returns true if this island is completely closed
    bool dfs(vector<vector<int>>& grid, int r, int c) {

        // If we go outside the grid,
        // this island touches the boundary.
        if (r < 0 || r >= rows || c < 0 || c >= cols) {
            return false;
        }

        // If this is water or already visited,
        // there is nothing to explore.
        if (grid[r][c] == 1) {
            return true;
        }

        // Mark this land as visited
        grid[r][c] = 1;

        // Explore all 4 directions
        bool up = dfs(grid, r - 1, c);
        bool down = dfs(grid, r + 1, c);
        bool left = dfs(grid, r, c - 1);
        bool right = dfs(grid, r, c + 1);

        // The island is closed only if
        // ALL four directions remain inside the grid.
        return up && down && left && right;
    }

    int closedIsland(vector<vector<int>>& grid) {

        rows = grid.size();
        cols = grid[0].size();

        int count = 0;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {

                // Found an unvisited island
                if (grid[r][c] == 0) {

                    // If DFS says it is closed,
                    // increase the answer.
                    if (dfs(grid, r, c)) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};