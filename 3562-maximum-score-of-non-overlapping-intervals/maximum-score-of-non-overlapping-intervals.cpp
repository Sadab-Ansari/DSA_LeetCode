class Solution {
public:
    struct State {
        long long w = 0;
        int cnt = 0;
        array<int, 4> id{};
    };

    static bool better(const State& x, const State& y) {
        if (x.w != y.w) return x.w > y.w;
        for (int i = 0; i < min(x.cnt, y.cnt); i++)
            if (x.id[i] != y.id[i]) return x.id[i] < y.id[i];
        return x.cnt < y.cnt;          // shorter array is lexicographically smaller
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<array<int, 4>> a(n);    // {l, r, weight, original index}
        for (int i = 0; i < n; i++)
            a[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        sort(a.begin(), a.end());

        vector<int> ls(n);
        for (int i = 0; i < n; i++) ls[i] = a[i][0];

        vector<int> nxt(n);            // first interval that starts after r_i
        for (int i = 0; i < n; i++)
            nxt[i] = upper_bound(ls.begin(), ls.end(), a[i][1]) - ls.begin();

        vector<array<State, 5>> dp(n + 1);   // dp[n][*] = empty state
        for (int i = n - 1; i >= 0; i--) {
            dp[i][0] = State();
            for (int k = 1; k <= 4; k++) {
                State best = dp[i + 1][k];                 // skip interval i
                State cand = dp[nxt[i]][k - 1];            // take interval i
                cand.w += a[i][2];
                cand.id[cand.cnt++] = a[i][3];
                sort(cand.id.begin(), cand.id.begin() + cand.cnt);
                if (better(cand, best)) best = cand;
                dp[i][k] = best;
            }
        }

        State res = dp[0][4];
        return vector<int>(res.id.begin(), res.id.begin() + res.cnt);
    }
};