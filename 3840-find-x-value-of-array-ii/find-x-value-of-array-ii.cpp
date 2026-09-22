class Solution {
    struct Node {
        int prod;
        int cnt[5];
    };
    int K, n;
    vector<Node> tree;

    Node identity() {
        Node a;
        a.prod = 1 % K;
        memset(a.cnt, 0, sizeof(a.cnt));
        return a;
    }

    Node leaf(int v) {
        Node a;
        a.prod = v % K;
        memset(a.cnt, 0, sizeof(a.cnt));
        a.cnt[a.prod] = 1;
        return a;
    }

    Node merge(const Node& L, const Node& R) {
        Node res;
        res.prod = L.prod * R.prod % K;
        for (int r = 0; r < K; r++) res.cnt[r] = L.cnt[r];
        for (int r = K; r < 5; r++) res.cnt[r] = 0;
        for (int s = 0; s < K; s++)
            res.cnt[L.prod * s % K] += R.cnt[s];
        return res;
    }

    void build(int node, int l, int r, vector<int>& nums) {
        if (l == r) { tree[node] = leaf(nums[l]); return; }
        int m = (l + r) / 2;
        build(2 * node, l, m, nums);
        build(2 * node + 1, m + 1, r, nums);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) { tree[node] = leaf(val); return; }
        int m = (l + r) / 2;
        if (idx <= m) update(2 * node, l, m, idx, val);
        else update(2 * node + 1, m + 1, r, idx, val);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    Node query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return identity();
        if (ql <= l && r <= qr) return tree[node];
        int m = (l + r) / 2;
        return merge(query(2 * node, l, m, ql, qr),
                     query(2 * node + 1, m + 1, r, ql, qr));
    }

public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        K = k;
        n = nums.size();
        tree.assign(4 * n, identity());
        build(1, 0, n - 1, nums);

        vector<int> result;
        result.reserve(queries.size());
        for (auto& q : queries) {
            int idx = q[0], val = q[1], start = q[2], x = q[3];
            update(1, 0, n - 1, idx, val);
            result.push_back(query(1, 0, n - 1, start, n - 1).cnt[x]);
        }
        return result;
    }
};