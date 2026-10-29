class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges,
                                string s, vector<string>& queries) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        vector<vector<int>> up(LOG, vector<int>(n, 0));
        vector<int> depth(n, 0), base(n, 0), tin(n), sz(n, 1), order;
        order.reserve(n);

        // Iterative DFS (preorder => subtrees are contiguous)
        vector<int> st = {0};
        vector<bool> vis(n, false);
        vis[0] = true;
        up[0][0] = 0;
        base[0] = 1 << (s[0] - 'a');
        while (!st.empty()) {
            int u = st.back(); st.pop_back();
            tin[u] = order.size();
            order.push_back(u);
            for (int v : adj[u]) {
                if (vis[v]) continue;
                vis[v] = true;
                up[0][v] = u;
                depth[v] = depth[u] + 1;
                base[v] = base[u] ^ (1 << (s[v] - 'a'));
                st.push_back(v);
            }
        }
        // Subtree sizes (process in reverse preorder)
        for (int i = n - 1; i > 0; i--) {
            int u = order[i];
            sz[up[0][u]] += sz[u];
        }
        // Binary lifting table
        for (int j = 1; j < LOG; j++)
            for (int v = 0; v < n; v++)
                up[j][v] = up[j - 1][up[j - 1][v]];

        auto lca = [&](int u, int v) {
            if (depth[u] < depth[v]) swap(u, v);
            int diff = depth[u] - depth[v];
            for (int j = 0; j < LOG; j++)
                if (diff & (1 << j)) u = up[j][u];
            if (u == v) return u;
            for (int j = LOG - 1; j >= 0; j--)
                if (up[j][u] != up[j][v]) { u = up[j][u]; v = up[j][v]; }
            return up[0][u];
        };

        // Fenwick tree: range XOR update, point query
        vector<int> bit(n + 2, 0);
        auto add = [&](int i, int x) {
            for (i++; i <= n + 1; i += i & -i) bit[i] ^= x;
        };
        auto pointQuery = [&](int i) {
            int r = 0;
            for (i++; i > 0; i -= i & -i) r ^= bit[i];
            return r;
        };
        auto getMask = [&](int v) { return base[v] ^ pointQuery(tin[v]); };

        vector<bool> ans;
        for (string& q : queries) {
            stringstream ss(q);
            string type;
            int u;
            ss >> type >> u;

            if (type == "update") {
                char c;
                ss >> c;
                if (s[u] == c) continue;
                int delta = (1 << (s[u] - 'a')) ^ (1 << (c - 'a'));  // remove old, add new
                s[u] = c;
                add(tin[u], delta);
                add(tin[u] + sz[u], delta);
            } else {
                int v;
                ss >> v;
                int w = lca(u, v);
                int pathMask = getMask(u) ^ getMask(v) ^ (1 << (s[w] - 'a'));
                ans.push_back((pathMask & (pathMask - 1)) == 0);
            }
        }
        return ans;
    }
};