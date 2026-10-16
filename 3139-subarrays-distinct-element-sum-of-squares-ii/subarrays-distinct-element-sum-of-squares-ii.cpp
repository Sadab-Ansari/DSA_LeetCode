class Solution {
public:
    static const long long MOD = 1000000007LL;

    struct Node {
        long long sum = 0;       // sum of distinct counts
        long long square = 0;    // sum of squares
        long long lazy = 0;      // pending addition
    };

    vector<Node> tree;

    void apply(int node, int l, int r, long long val) {
        long long len = r - l + 1;

        // New square sum:
        // (x + val)^2 = x^2 + 2*x*val + val^2
        tree[node].square =
            (tree[node].square
            + 2LL * val % MOD * tree[node].sum % MOD
            + val * val % MOD * (len % MOD)) % MOD;

        // New sum
        tree[node].sum =
            (tree[node].sum + val * (len % MOD)) % MOD;

        // Store lazy update
        tree[node].lazy =
            (tree[node].lazy + val) % MOD;
    }

    void push(int node, int l, int r) {
        if (tree[node].lazy == 0 || l == r)
            return;

        int mid = (l + r) / 2;

        apply(node * 2, l, mid, tree[node].lazy);
        apply(node * 2 + 1, mid + 1, r, tree[node].lazy);

        tree[node].lazy = 0;
    }

    void update(int node, int l, int r,
                int ql, int qr, long long val) {

        if (qr < l || r < ql)
            return;

        if (ql <= l && r <= qr) {
            apply(node, l, r, val);
            return;
        }

        push(node, l, r);

        int mid = (l + r) / 2;

        update(node * 2, l, mid, ql, qr, val);
        update(node * 2 + 1, mid + 1, r, ql, qr, val);

        tree[node].sum =
            (tree[node * 2].sum + tree[node * 2 + 1].sum) % MOD;

        tree[node].square =
            (tree[node * 2].square + tree[node * 2 + 1].square) % MOD;
    }

    int sumCounts(vector<int>& nums) {
        int n = nums.size();

        tree.resize(4 * n);

        unordered_map<int, int> last;

        long long answer = 0;

        for (int r = 0; r < n; r++) {

            int prev = -1;

            if (last.count(nums[r])) {
                prev = last[nums[r]];
            }

            // nums[r] becomes a new distinct element
            // for all subarrays starting from prev + 1 to r.
            update(1, 0, n - 1, prev + 1, r, 1);

            // Root contains the sum of squares of
            // distinct counts of all subarrays ending at r.
            answer = (answer + tree[1].square) % MOD;

            last[nums[r]] = r;
        }

        return answer;
    }
};