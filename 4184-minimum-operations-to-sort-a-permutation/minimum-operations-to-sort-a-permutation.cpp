class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> base[2] = {nums, vector<int>(nums.rbegin(), nums.rend())};

        // ok[r]: base r is a cyclic shift of 0,1,...,n-1
        // pos0[r]: index of 0 in base r
        bool ok[2];
        int pos0[2];
        for (int r = 0; r < 2; r++) {
            ok[r] = true;
            for (int i = 0; i < n; i++) {
                if (base[r][(i + 1) % n] != (base[r][i] + 1) % n) ok[r] = false;
                if (base[r][i] == 0) pos0[r] = i;
            }
        }
        if (!ok[0] && !ok[1]) return -1;

        // BFS over states (r, k), stored as r * n + k
        vector<int> dist(2 * n, -1);
        queue<int> q;
        dist[0] = 0;
        q.push(0);
        while (!q.empty()) {
            int s = q.front(); q.pop();
            int r = s / n, k = s % n;
            if (ok[r] && k == pos0[r]) return dist[s];

            int nxt[2] = {r * n + (k + 1) % n,            // rotate left
                          (1 - r) * n + (n - k) % n};     // reverse
            for (int t : nxt) {
                if (dist[t] == -1) {
                    dist[t] = dist[s] + 1;
                    q.push(t);
                }
            }
        }
        return -1;
    }
};