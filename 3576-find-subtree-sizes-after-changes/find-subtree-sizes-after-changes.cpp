class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> ch(n);
        for (int i = 1; i < n; i++) ch[parent[i]].push_back(i);

        vector<int> last(26, -1), np(parent), order;
        order.reserve(n);

        function<void(int)> dfs = [&](int u) {
            order.push_back(u);
            int c = s[u] - 'a';
            if (u != 0 && last[c] != -1) np[u] = last[c];
            int saved = last[c];
            last[c] = u;
            for (int v : ch[u]) dfs(v);
            last[c] = saved;               // backtrack
        };
        dfs(0);

        vector<int> sz(n, 1);
        for (int i = n - 1; i > 0; i--) {  // reverse preorder
            int u = order[i];
            sz[np[u]] += sz[u];
        }
        return sz;
    }
};